# Decompiling a function

1. Build once (`make compare`) so `medabots_rokusho.elf` exists. `match.py` links against it.
2. Pick a function from `src/<module>.c` that is still `INCLUDE_ASM`'d and read its asm in
   `asm/nonmatching/<module>/<name>.s`. `python3 tools/scripts/candidates.py --leaf` lists the
   remaining functions, leaf functions (no calls) first, then by size; `--module` narrows it down.
3. Write it in a scratch file that starts with `#include "global.h"`, then check it:

   ```sh
   python3 tools/scripts/match.py <name> scratch.c
   ```

   This compiles the way the Makefile does (agbcc `-fprologue-bugfix`), links at the function's original address and compares the bytes
   (code and literal pool). On a mismatch it prints both disassemblies side by side.
4. Declare what it uses in `include/`: prototypes in `functions.h`, RAM variables and ROM data in
   `variables.h`, with their addresses in `symbols.ld`.
5. Install it:

   ```sh
   python3 tools/scripts/install_func.py <name> scratch.c
   ```

   This replaces the `INCLUDE_ASM` line with your C, deletes the asm file and runs `make compare`.
   If the ROM stops matching, it puts everything back.

## Notes on agbcc

* Calls through function pointers go through `_call_via_rN` (libgcc). A `bl _call_via_r0` in the asm
  is a call like `table[i]()`.
* `push {lr}` ... `pop {r0}; bx r0` is the normal epilogue with `-mthumb-interwork`.
* Literal pools come after the last `b`/`bx`. A different pool order usually means a different order
  of first use in the C.
* Register allocation and instruction order are sensitive to statement order, temporaries and
  combined assignments (`a = b = c;`). Small rewrites often fix "almost" matches.
* The game matches pret's `agbcc` with `-fprologue-bugfix`: without the flag, leaf functions that
  branch get an extra `push {lr}` the original doesn't have. pret's `old_agbcc` builds most
  functions the same way, but not all (agbcc's address CSE, e.g. `subs r2, #0x16` to reach a
  neighbouring field, and its operand order in some multiplies). `match.py --old` / `--new` try
  `old_agbcc` / plain `agbcc`.
* A `ldr rX, =0x414` + `ldr r0, [rX, #0x14]` where you expect a single folded offset
  (`ldr r0, [rX]` with `rX = base + 0x428`) means the original took the address of a struct first,
  typically through a small `static inline` helper that takes the struct pointer.
* A value that must stay in a callee-saved register across calls (e.g. a zero stored at the end)
  is often a separate variable assigned in the middle of the code, not a constant.
* `mov sb, sp` before a `bl`, and a callee that saves `sb` (r9) and reads `[sb]`: that is a GCC
  **nested function** (r9 is the static chain, pointing at the outer function's frame, where it
  spilled the variables the nested function uses). gcc emits the nested function just before the
  outer one; decompile the pair together as one C function containing the nested one (see
  `sound_fade_out_music` in `sound_driver.c`). The nested function becomes a local symbol
  (`name.N`), so it can't be called from other files.
* A `.byte` tail after a function's `.align` can hide whole functions that nothing calls (dead code
  kept by the linker). Disassemble it (`objdump -b binary -M force-thumb`) and look for `push`.
  Pointer tables (e.g. `gMapScriptCommands`) whose entries point inside a function's range show
  them too. `tools/scripts/carve.py PARENT ADDR:NAME:SIZE ...` cuts the tail off the parent's `.s`
  and adds the new entries to `config/functions.tsv`; then write them in C after the parent.
* A `u8` return value copied to a local gets re-truncated (`lsls/lsrs #24`). When the original
  passes the raw `r0` on, store it into its destination field and read the field back
  (`a.x = f(); b.y = a.x;`): gcc reuses the register instead of reloading.
* A callee result added without any truncation (`adds r1, r1, r0` right after the `bl`) means
  the callee returns `u32`/`int`, even if its value fits a `u16`.
* A param spilled to the stack and read back with `ldrb` hints at a `u8` param; if the callers
  pass it untruncated, they were compiled against a different prototype.
* The base address loaded **before** the scaled index (`ldr r1, =gArr; lsrs r0, r0, #18`) comes
  from indexing the global directly in every statement (`gArr[i].a = x; gArr[i].b = x;`); a
  `struct X *p = &gArr[i]` local makes gcc compute the index first.
* A pointer that walks a table while a separate counter runs (`adds r2, #8` + `adds r4, #1`), and a
  copy of the table pointer made only after the first loop test, are `for (i = 0; p[i].f; i++)`
  with indexing: gcc strength-reduces the index into the pointer itself.
* Two adjacent byte compares merged into one `ldrh` compare in your build but not the original:
  split the `&&` into nested `if`s.
* `cmp` of `a - b + 16` in some cases and a plain `a == b` that crossjumps oddly in the others:
  write the plain ones as `a - b == 0` too (the original source was symmetric).
* A bitfield shows as `lsls #27; lsrs #27` (low 5 bits) or `lsls #27; lsrs #3; adds 0x31000000;
  lsrs #24` (a 5-bit field plus a constant, as a `u8`): use a bitfield in the struct, not masks.
* Two halves of one buffer loaded as two separate literals (`=0x0202F800` and `=0x0202FA00`) with
  no base register reused: the original names each half (separate symbols), not `buf + 0x100`.
* `*d++ = ...` row loops: `dst + (i << 5)` and `dst + i * 32` can give different register orders
  (write_tilemap_to_vram_08000E94 only matched with the shift).
* Registers read back after a store through a `u16 *` pointer: gcc must reload the globals if the
  pointer may alias them; registers written through a plain (non-volatile) pointer still reload
  `u16` globals. Copy the values to locals or a struct pointer to keep them in registers.
* Choosing a table with `if/else` before one call: gcc hoists one of the two loads above the
  compare. Writing the whole call in both branches lets gcc crossjump the tails and keeps the
  original `ldr r4, =A; b common` shape (medapart_detail_show_hint).
* The same goes for a constant picked by a condition: `v = c ? 0x50 : 0x40` (or if/else into a
  temp) is if-converted to `movs #0x40; cmp; beq; movs #0x50`; writing the stores in both arms
  gives the original's branch (command_ring_pulse_selected).
* Float math links against the ROM's soft-float routines (`__addsf3`, `__mulsf3`, `__divsf3`,
  `__floatsisf`, `__fixunssfsi` are aliased in `asm/lib/libgcc.s`); `(float)u32` gives the
  `blt; x >> 1 | x & 1; add` sequence (scale_to_bar_fill).
* A function returning 0/1 whose original tests the "nothing to do" case first: write
  `if (!cond) ret = 0; else { ...; ret = 1; } return ret;` (early `return`s put the body first).
* Hardware I/O addresses (`OAM`, `VRAM`, `INTR_CHECK`, ...) are in `include/gba/io_reg.h`;
  `CpuCopy16(src, dst, size)` gives the `lsls #10; lsrs #11` count of a 16-bit CpuSet.

## Naming

* Functions keep their `sub_XXXXXXXX` names until their purpose is known. Names that came from
  research (`read_keys`, `main`, ...) are snake_case.
* Globals are `gCamelCase`. ROM data that isn't understood yet is named `gUnk_XXXXXXXX` or by what
  it holds plus its address (`gGameStateHandlers_083AC148`).
* A `switch` whose code starts with a range check (`cmp r0, #2; bhi default`) before the case
  tests was wrapped in an `if (x <= 2)` in the original.
* `a == 0 || a > 3` is folded into one `(a - 1) <= 2` compare; when the original tests both,
  write the two arms separately (`if (a == 0) v = 0; else if (a > 3) v = 0; else ...`).
* Two pointer increments where you expect one (`base + i*4` and a separate `base + i*4 + 0x13E`): the
  fields are members of a struct array element (`a[i].x`, `a[i].y`), not a 2-D array (`a[i][0]`,
  `a[i][1]`, which gcc folds into one pointer).
* A loop ending in `movs r0, #1; cmp r0, #0; bne top` comes from a flag that never changes:
  `u32 run = 1; while (run) { ... }`. `while (1)` / `do ... while (1)` give a plain `b` and a
  different register allocation.
* `x == 0 || x == 1` (and `case 0: case 1:`) become one `x <= 1` compare. For the original's
  two compares write `if (x == 0) goto ok; if (x != 1) goto fail; ok:`.
* An index computed as `(a << 2) + (b + 0x5A)` comes from `arr[0x5A + a * 4 + b]` (constant
  first). `a * 4 + b + 0x5A` and `a * 4 + (b + 0x5A)` get reassociated into `(a * 4 + 0x5A) + b`.
* A caller passing `ldrsh` / `ldrh` / `lsls; asrs` arguments tells you the prototype's parameter type
  (s16, u16, s16 after arithmetic). The callee may truncate differently; follow the caller.
* A table entry read as `ldr rX, =sym; adds rX, #off` and reloaded after every call is a struct
  field, not an array element: `arr[0x69]` gives `ldr =sym+0x1A4`. Declare a struct view of the
  table (see `struct Unk_083B4AE0` / `gUnk_083B4AE0_s`) and read the field.
* `side = 0; if (!(f & 2)) side = 1;` loads the zero before the test; the original's
  `ands; movs r1, #0; cmp; bne; movs r1, #1` order comes from `if (!(f & 2)) side = 1; else side = 0;`.
* A u16 value stored with `lsls; lsrs` and sign-extended (`lsls; asrs`) only where it is used, once,
  for several sums: copy it into an `s16` local first (`sx = x; a = sx - 16; b = sx + 16;`).
  Casting at each use (`(s16)x - 16`) lets gcc drop the extension.
* Two branches that store the same fields from different sources (`a = p->x; b = p->y - 16; c = p->y`)
  match when written out in each branch; a shared local after the if gives a different tail.
* `if (a && b && (r = f())) {...} else x++;` where the original's else path reuses the
  `gUnk_03001800` base kept in a callee-saved register (no new literal): write the function with a
  struct pointer local (`struct Unk_03001800 *s = &gUnk_03001800;`). With the global, gcc reloads the
  base at the join (sub_08020AD0).
* `n = (r | -r) >> 31;` gives the original's `rsbs; orrs; lsrs #31` for "count 1 if nonzero";
  `n = f() != 0` gets a branch (sub_08021734).
* A table whose entries the original reloads after every call (`ldr r0, [r4]` before each `bl`) must
  not be declared with `const` elements (`const void *gUnk_083B5F80[]`, not `const void *const`):
  gcc keeps a const element in a register across calls.
* Two stores of the same value after a select (`if (c) x = 0x88; else x = 0x68; a = b = c = x;`) come
  out as one join when written as chained stores in each arm: `if (c) p[2].f = p[1].f = p[0].f = 0x88;
  else ... = 0x68;` (sub_0802167C).
* A caller passing an un-truncated register (`ldrh` value, a loop counter + 0x5A) to an asm callee that
  doesn't truncate its parameter either means the parameter is u32, not u8.
* An out-parameter read back as one word and split (`ldr r0, [sp, #4]; strh r0, [..]; asrs r0, r0, #16;
  strh r0, [..]`) is an `s32` written by the callee as x | y << 16: copy it to a local first
  (`v = pos; a = v; b = v >> 16;`); a `struct { s16 x, y; }` gives two `ldrh` (calc_polar_to_screen_coords).
* The global base loaded again for the second test of `if (a == 0 && b) next; else if (c) c--; else next;`
  comes from writing the two `next` arms out separately; `if ((a || !b) && c) c--; else next;` CSEs the
  base into one register (sub_08022938).
