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
  The same works for a constant stored and then used as an index (`movs r1, #0x47`, `strb`, then
  `lsls r1, r1, #2`): write `x.f = 0x47; g(tbl[x.f]);`, not `tbl[0x47]` or a local.
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
* A global array base hoisted into a high register (`ldr r0, =gArr; mov r9, r0`) and loaded
  before the loop counter's other setup: a pointer local assigned after the counter,
  `i = 0; bots = gArr; for (; i <= 2; i++)` (sub_08026FF8). When the original instead re-adds the
  base after the scaled index, index the global directly with the full expression in every use
  and no `rec` local (sub_08027494).
* A slot counter `adds r5, #4` set up after the other loop invariants: write the call argument as
  `i * 4 + 0x21` and let gcc strength-reduce it; an explicit `slot += 4` variable is set up first.
* A `u8` local computed right before a call (`lsls/lsrs #24` after the first argument's load):
  assign it inside the call, `f(tbl[k], slot = i + 0x21)`; a declaration initializer moves the
  computation above the load.
* Hardware I/O addresses (`OAM`, `VRAM`, `INTR_CHECK`, ...) are in `include/gba/io_reg.h`;
  `CpuCopy16(src, dst, size)` gives the `lsls #10; lsrs #11` count of a 16-bit CpuSet.
* `ldr rB, =gArr` **before** `lsls rI, slot, #6` (and `rB` reused later for other indexes, often
  copied to `ip`): take a base pointer local, `base = gArr; s = &base[slot];` (sub_080366DC,
  sub_08038428, spawn_battle_particle_effect).
* A pair `tbl[n * 2]`, `tbl[n * 2 + 1]` that the original loads as `n << 1` first, then `n << 2`
  for the first element and `(n * 2 + 1) * 2` unfolded for the second: write the first index as
  `tbl[n << 1]` and keep `tbl[n * 2 + 1]`. Several tables picked by a switch whose loads share
  one tail: write the loads in every case with the table named directly (sub_080366DC).
* A variable set only in some switch cases (`case 0: case 1: case 2: mask = 7;`) gets folded to a
  constant; separate identical case bodies keep the original's branch tree
  (spawn_battle_particle_effect).
* `adds #0xDF` (a byte constant for `- 0x21`) or an unfolded `subs` in an index sum: try the
  grouping `a + (b + 0xDF)` / `b + (a - 0x21)`; the first operand gcc sees decides the order
  (sub_08038650, sub_08038700).
* A loop-invariant table address hoisted after the loop guard (`cmp; bhs; ldr rT, =tbl`): assign a
  pointer local inside the loop body, `tbl = gTable;` (update_sprite_animations_tick_080370AC).
* `subs r1, #8; subs r0, r0, r1` where C's `a * 9 - (b - 8)` always folds to `(a * 9 + 8) - b`:
  tree folding happens before inlining, so `static inline` helpers keep the terms apart:
  `mul9(a) - sub8(b)` (message_portrait_anim_step). One helper alone is evaluated first, like a call.
* Two `u8` stores to a stack array as `add r0, sp, #N; strb; adds r0, #1; strb` (not
  `strb [r0, #1]`): `u8 *p = buf; *p++ = a; *p = b;`.
* A string loop whose pointer copy and table address are set up *after* the first `*p != 0xFE`
  test: index it, `for (i = 0; str[i] != 0xFE; i++)`, also for the slot (`gArr[slot + i]`)
  (render_text_sprites_08040DB8).
* `struct` field addresses above 0xFF on a global that the original materializes as
  `ldr rA, =gX; ldr rB, =0x12F; adds`: access the field directly every time
  (`gArr[gUnk_03000440.unk12F]`), not through a `u8 *slot` local.
* Fields of `gUnk_03001800` past 0x100 (literal `0x030019A4`, the next one as `-10` from it): the
  struct field, not a separate symbol like `gUnk_0300198A[0x1A]`.
* Tilemap rect copies whose address is `x * 2 + VRAM` then `+ bg_base`, `+ y * 64`: write
  `(u16 *)(VRAM + bg_base) + x + y * 32`; `bg_base + (VRAM + x * 2)` gets reassociated
  (read_vram_tilemap_rect, fill_tilemap_rect_08042698). Row loops that keep a row pointer and a
  write pointer (`adds r4, #0x40; adds r2, r4, #0`) are `d = base; row = d; ... row += 32; d = row;`,
  with the source rows the same way (`srow = s; ... srow += 32; s = srow;`; declare `srow` before
  `row`): copy_transition_tiles_to_bg2, clear_and_copy_tilemap_rows.
* A leaf that loads the array base first into a callee-saved register (`push {r4}; ldr r4, =gArr`)
  before computing the index: `u8 *inv = gArr; p = &inv[i];` (reduce_medapart_stat; the same for
  one branch of modify_medapart_quantity).
* `(&s->unk3)[k]` for a run of byte fields: take `u8 *p = &gArr[i].unk3;` then `p[k]`
  (sub_080421B4). A 4-D table index `(a - 1) * 256 + b * 8 + c * 2` is a flat 1-D index in the
  original (gUnk_083C6DF8), and a 3-D `[part][kind][i]` table was `[part * 64 + kind * 16 + i]`
  with a `u8 *d = dst` copy (load_part_data).
* Block order: when the original's fall-through is the second arm of your `if`, swap the arms
  (`if (x == 0) {...} else {...}`, `if (n != 0x1E)`), also for `return a > b ? 1 : 0` written as
  `if (a > 0xFF) return 1; return 0;` (update_blend_effect, update_sprite_hflip_by_animation_phase).
* `(id & 1)` written at each use instead of a `b = id & 1` local lets gcc share the constant 1 with
  a `= 1` store (team_add_tinpet).
* Params read and written through `[sp]` in a leaf (`sub sp, #8; str r0, [sp]`): `vu32` params
  (sub_0804361C, not matched yet).
* **File context**: register choices (and sometimes block order) change with the C functions
  compiled before it in the same file, so a function can match in a scratch file and not in its
  module. `python3 tools/scripts/tryin.py <name> variants.c [N]` tries each `----`-separated
  variant in place of the module's `INCLUDE_ASM` line and restores the module afterwards
  (sub_0805B7A0, sub_0805BDC8, sub_0805C190 only matched this way).
* A non-constant array initializer `u8 cur[3] = {gA, gB, gC};` builds a temporary on the stack and
  copies it with a `bl memcpy` (sub_0805BCC0). `memcpy` is a second label on `memcpy_optimized` in
  `asm/lib/libgcc.s`.
* A constant that the original builds at run time (`movs r0, #0x1f; lsls r4, r0, #10; lsls r1,
  r0, #5; orrs ...`) comes from a local variable: `s32 w = 31; c = (w << 10) | (w << 5) | w;`
  (sub_0805C6AC).
* Repeated key tests that `ands` into a fresh register each time: write `*(u8 *)&gNewKeys & 0x20`
  at every test instead of a `keys` local (sub_0805B7A0).
* A `u16` loaded once and split into fields in two places: `u16 c = buf[i];` locals (not `u32`, not
  re-reading the array) (sub_0805BDC8).
* Unsolved: callees that zero-extend `u16` x/y params at entry, then sign-extend them at each use
  (`lsls #16; asrs #16` before `& 0x1FF`), while their callers pass sign-extended values (an `s16`
  prototype). `(s16)x` on a `u16` param gets dropped under the mask; see the near misses in NOTES
  (sub_08036784, sub_08036C20, setup_battle_cursor_sprite_08036FF8).
* A pointer table copied to the stack with `ldm` / `stm` before an indexed call: copy a struct that
  wraps the array, `struct FuncTable7 t = gUnk_080AFA20; t.f[i]();` (dispatch_substate_handler). The
  ROM table stays in the data blob; only a symbol is needed.
* A switch whose `case 0` and `case 1` jump to the same code but whose compare tree is `1 / >1 / 0`
  (not a `0..1` range): write the two case bodies out in full; gcc's cross-jumping merges them later.
  The same change made the original's zero constants appear early in callee-saved registers
  (sub_080611D0).
* `a = b = v;` stores `b` first. Swap the chain if two byte stores come out in the wrong order
  (sub_0805FE90).
* Loop pointer start order (`dst` literal before `src = base + v * 0x200`): explicit pointer locals
  assigned in the original's order, then `v <<= 9; src = base + v;` (fade_update_tilemap_copy).
* `CpuCopy16(buf, (void *)0x06004000, size); lz_decompress_dispatch(src, (void *)(0x06004000 + size));`
  keeps 0x06004000 in a callee-saved register; the original loads the literal twice. Solved by a helper
  `static inline void *vram_at(u32 off) { return (void *)(0x06004000 + off); }` used for both destinations
  (sub_0805D628, item_menu_load_graphics; retry sub_0805FBA8, load_battle_background_graphics this way).
* `id * 6` where the original computes `(id << 2) + (id << 1)`: write the shifts out
  (load_battle_sprite_tiles; retry decompress_sprite_to_vram_08042D94).
* Variable-length arrays (`s32 n = 5; u8 ids[n];`) reproduced a stack frame where the constant only
  appears through reload (update_battle_medapart_icons, render_battle_medapart_list).
* A function that matches standalone can break when an unrelated function earlier in the file becomes C
  (session 91: sub_0805C190 rotates r8 / sl / ip). Bisect by reverting single functions to INCLUDE_ASM
  and keep the cheapest one as asm until the next neighbour is installed.
* **Last resort for a few-line register swap:** a GNU local register variable,
  `register u8 *p asm("r0") = (u8 *)&gX;`. Keep it in the smallest block that needs it; a function-wide
  pin often reshuffles everything else. It solved: load_save_with_retries (call result kept in r1),
  save_dispatch (bit-set address in r0), status_side_change_scroll_out (`rec * 2` in r0),
  update_sound_channel_frequency_080733AC (pin the two pointer params, `cnt` declared first),
  town_map_load_graphics, and sub_0805E5B0 (table pointer pinned to r4 *and* assigned inside the loop
  body, so it is loaded after the loop guard). It does not help when the swapped register only holds a
  constant (no variable to pin) or a spill slot.

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
* A field address built as `base + rec*0x100` + an offset, then `adds r0, #1` (literal `base + off`, not
  `base + off + 1`): take the address of the field *before* it and add one, `&gUnk_03000590[r].unkB8 + 1`
  (sub_080236E0) or `&...unkD7 + 1` for a u16 at 0xD8 (sub_08022748). `&...unkB9` folds the 1 into the literal.
* `x.unk84 = 0x45; f(tbl[0x45]);` loads 0x114 as a fresh constant; the original's `movs r1, #0x45; strb;
  lsls r1, #2` comes from indexing with the field just stored: `f(tbl[x.unk84])` (sub_08023B44).
* `x = K; if (c) x |= M;` (on a struct field) makes gcc keep K in a register and `orrs` it for the second
  store; `x = K | M` folds the constant and a `u16 v = K` local moves the load (sub_08026184).
* Loops over sprite slots `gUnk_03002C30[i + 0x21]` that compute `(i + 0x21) << 6` each time come from
  writing the index out in every statement; a `spr` pointer or `slot` local lets gcc fold `base + 0x840`
  (sub_08025FC8).
* A 2D table read as `(a * 4 + b) * 4` is indexed flat, `tbl[0][a * 4 + b]` (gUnk_083BB9CC, sub_08026810).
* `v = 0; if (x) v = 1;` and `v = !x` order the zero differently: `if (!(f & 2)) v = 1; else v = 0;` gives
  `ands; movs v, #0; cmp; bne; movs v, #1` (sub_08026A74).
* Nested loops where the original reloads loop invariants inside the outer loop (and keeps `i + 1` in a
  saved register): leave the inner loop with `goto next;` (label just before the outer loop's closing
  brace) instead of `break`. With `break`, gcc hoists everything to the top of the function
  (sub_08029B84, sub_08029FE0).
* `x == A || x == B` per switch case can come out as `x - A <= 1`; the original's `cmp A; beq; cmp B; bne`
  needs `if (x == A) goto call; if (x != B) break; call: f();` (sub_08029354).
* `strh` of a `0xFFFFxxxx` literal / `movs; rsbs` for a byte: the source wrote a negative constant
  (`unk0 = -0x39DC`, `unkB = -0x10`) (sub_0802AAF8).
* Switch cases that share a tail in the original (`movs r2, #0` hoisted into each case, then a branch to
  a shared `strb r1, [r0]`): write every case out in full. gcc tail-merges identical case tails itself;
  a hand-written `goto common` gives different code (sub_0802B5AC).
* `x = (a + b) & 0x3FF` stored to a u16, where the original loads the mask into a spare register and
  copies it (`ldr r4, =0x3FF; adds r0, r4, #0; ands`): cast the sum, `(u16)(a + b) & 0x3FF`
  (sub_0802BE44, sub_0802C960).
* A loop over `i` with a sprite slot `i + 0x21` where the original recomputes `slot << 6` each time
  (no pointer strength reduction) and truncates the slot at calls: write `i + 0x21` at every use, not a
  separate `slot` counter (sub_0802C960).
* Operand order of a sum decides how gcc splits it. For a sprite index the original computes as
  `base + (i << 8) + 0xC00 + j * 0x40`, write `gUnk_03002C30[0x30 + j + i * 4]` (sub_0802D198,
  sub_0802D270); `i * 4 + 0x30 + j` and friends regroup it. For an argument computed as `(i + 0x72)`
  then `+ unk60`, write `unk60 + 0x72 + i` (sub_0802CE4C).
* An `i * 4` computed once (`lsls r4, r6, #2`) right after the first call's source address and reused
  by later index expressions and a u8 argument: assign it inside the first use,
  `&gUnk_03002C30[(j = i * 4) + 0x24]`, then use `j` (sub_0802CE4C).
* `subs r0, #0x80` before a `strb` (`adds r0, #0x80` is what `- 0x80` gives): cast the call result
  to `s8` first, `(s8)f(x) - 0x80` (sub_0802D758).
* A chain of early-out failures that each store a different message and then share
  `gGameSubState = 0x20`: write each one in full (`unkA6 = N; gGameSubState = 0x20; return;`) so gcc
  cross-jumps the tails like the original; a `goto fail` with the store before it adds a branch per
  case (resolve_battle_action_phase).
* Callee prototypes: if the asm callee uses an argument without truncating it, declare it `u32`, or the
  caller emits `lsls/lsrs` the original doesn't have (reduce_bot_part_stat, medal_update_exp_progress).
* A fixed EWRAM buffer whose literal is reloaded inside the loop (`ldr r1, =0x02023000` per iteration,
  index not strength-reduced): index a cast constant (`SORT_BUFFER[i]`, `((struct X *)0x02023000)`),
  not a linker symbol; with a symbol gcc keeps the pointer in a register (find_most_damaged_part).
* `if (x) return A; else return B;` puts the `then` value at the branch target: if the original's
  fall-through is `movs r0, #1` after a `bne`, write `if (x != 0) return 0; else return 1;`
  (sub_08033224).
* `cmp #0; beq; cmp #1; beq` (no `cmp #1; bls`): two separate `if (x == 0) return; if (x == 1) return;`
  (sub_080336DC). For `x == 0 || x == 1` in an if/else chain use `if (x == 0) goto both; if (x == 1)
  { both: ... }` (sub_08033B7C).
* An index computed before the record (`part * 0x18` first, then `rec << 8`) with the field offset
  added separately (`adds #0x59`): index the global in full at each use, no `struct *` local
  (sub_08033434, sub_08033550).
* Toggle then test a flag: `f ^= 2; if (!(f & 2))` reloads the constant like the original;
  `if (!((f ^= 2) & 2))` reuses the register (sub_080347F8).
* Several `x == A || x == B` checks in a row: if one uses the `goto` pair through a `type` local and
  the registers come out swapped, write that check with the field read at both compares instead
  (sub_08033D30).
* Array element base: `gUnk_03002C30[slot].x` at every use gives `ldr base; lsls; adds` (literal first);
  a `struct X *s = &gUnk_03002C30[slot]` local gives `lsls; ldr; adds`. Pick the form by the order of
  the first two instructions (check_sprite_in_range, sub_080353CC).
* `ldr r4, =gUnk_03001800; adds r4, #0xEC` (field address not folded into one literal): access the
  field through `struct Unk_03001800 *b = &gUnk_03001800;` (sub_08035BD4, calc_battle_action_speed);
  plain `gUnk_03001800.unkEC` gives `ldr r4, =0x030018EC`.
* `movs r2, #0` before `ldr r1, =base` in a loop prologue: put the pointer init in the `for`,
  `for (i = 0, b = &gUnk_03001800; ...)` (sub_080385D0).
* `x |= 0x80` with the constant's register as the result (`movs r0, #0x80; orrs r0, r1`): write it on the
  struct field (`b->unk112 |= 0x80`), not through a `u8 *` alias (battle_advance_dialogue_text).
* An `else if` chain where the later cases jump back into the first case's `ands/cmp/bne` tail:
  `if (A) { if (f & 1) return 1; } else if (B) { if (f & 8) return 1; } ... return 0;` (sub_08036D64).
* A table index `tbl[f(x) * 8 + (g() & 7)]` with the shift before the `ands`: write it as one
  expression on the global; with a `tbl` or `row` local gcc does the `ands` first
  (get_random_battle_weight_entry).
* Callers can depend on a narrow prototype: sub_08036C20's callers only match with `s16 x, s16 y`, even
  though the callee zero-extends them; check `make compare` after every prototype change.
* `s16` parameters are zero-extended at entry (`lsls/lsrs`) and sign-extended at each use: that is just
  how agbcc promotes `s16` params. If the original keeps the `lsls/asrs` before an `& 0x1FF` / `& 0xFF`,
  the sum went through an `s32` temp (`t = x + tbl[i]; s->unk2 = t & 0x1FF;`); written in one
  expression on the `s16` field, gcc narrows it and drops the extension.
* A callee called with `add r0, sp, #N` as the *last* argument set up (after the stack arguments) returns
  a struct in memory: declare it as returning the struct (`struct Coords16
  calc_polar_to_screen_coords(...)`), not as taking an out pointer; `v = f(...)` then `v.x` / `v.y`.
* A switch whose cases each write two fields, with one shared tail in the original: write both stores in
  every case and let gcc cross-jump them (set_target_sprite_position).
* A constant not folded (`movs r6, #2; adds r6, #3`): it came from a local (`y = 2; ... y + 3`)
  (sub_080364A8).
* `tools/scripts/split_scratch.py FILE.c OUTDIR` splits a scratch file with several functions into one
  file per function (with prototypes of the others), so each can be checked with `match.py` at its own
  address; calls between functions in one file otherwise link locally and the `bl` offsets differ.
* Two identical branches that each end in `b` to one shared call (`v = x; b call` twice), where gcc
  merges yours into one: write the call in every branch (`if (A) { if (f(x)) return 1; return 0; }`)
  and let gcc cross-jump the call tails instead (battle_calculate_damage_modifier).
* `x != 6 && x != 7` comes out as a range check (`subs #6; cmp #1; bls`); the original's two
  `cmp/beq` need `if (x == 6) return 0; if (x == 7) return 0;` (battle_calculate_turn_speed).
* A loop on a store-and-test of a call result (`strb r0, [r1]; lsls r0, #24; cmp; bge` before the loop,
  the same inside): `if ((s8)(f.x = g()) < 0) { p = &f.x; do { ...; *p = g(); } while (*p < 0); }`
  (battle_sequence_run_command).
* `a + 1 + tbl[...]` where the original does `adds r1, #1` between the table address and the `ldrb`:
  read the u16 field into an `s32` local first (battle_advance_sequence_counter).
* A `switch` with two cases and a default comes out as `cmp #0; beq; cmp #1; beq; <default inline>`; an
  `if / else if / else` chain puts the first case inline instead (battle_seq_cmd_wait_text).
* `(0x1E - t - (x + t)) - 1` stored to an s16 field: gcc reassociates the `- 1` into the subtraction
  unless the inner part is cast, `(s16)(0x1E - t - (x + t)) - 1` (sub_0803A474).
* A loop whose table pointer is loaded *after* the hoisted struct base and `&field` (`movs r7, #0; ldr r5,
  =base; adds r0, r5, #0xF8; mov r8, r0; ldr r6, =tbl`): write the base and field pointers as locals
  before the table pointer (`i = 0; b = &gUnk_03001800; f = &b->unkF8; tbl = gUnk_...; do {...}`)
  (sub_0803B0C0).
* `x - s->unk30` where the original loads `unk30` first: `x + (s->unk30 * -1)` (sub_0803CC8C); for `+`,
  swap the operands (`x + s->unk30` loads `unk30` first).
* A slot byte loaded into a scratch register and copied to a callee-saved one only at `cmp #1`: don't
  keep it in a local, test `if (gUnk_0300056F == 1)` again and let cse reuse the load (sub_0803B9A4).
* `if (A) { X; Y++; Y++; } else Y++;` where both `else if` arms of the caller do the same: write the
  body in full in each arm; the original's tail-merged copies only come out that way (sub_0803B900).
* A sprite slot found by a search loop and then used for many stores: index `gUnk_03002C30[slot].f`
  every time instead of a `struct *s = &...[slot]` (the pointer swaps the `lsls/ldr` order).
* An unrotated loop (`top: test; bls out; i += 3; b top`) where gcc rotates your `while`/`for`: write it
  with a label and `goto` (init_battle_sprite_entry_08040B90).
* `VRAM + ((bgcnt >> 8) & 0x1F) << 11` screen-base addressing: `(u16 *)(VRAM + (screen << 11)) + x + y * 32`
  matches; byte sums in other orders put `VRAM` in the wrong add (vram_fill_tilemap_rect, tilemap_fill_rect).
* A value loaded once (`ldrh r2`) and used non-destructively three times where your `u16 c` local gets
  copied before each `ands`: read it through a pointer, `u16 *src = &tbl[k]; ... *src & 0x1F ... *src &
  0x3E0` (the palette blends at 0x0803F684..0x0803F998).
* `ldrb; adds #1; strb; ands #3` with no `& 0xFF`: write `x++; if (!(x & 3))`, not `++x & 3`
  (sub_0803EC98).
* A struct word read across byte fields (`ldr r0, [base, #0x1C]` over `unk19[3]`..`unk1E`): cast to a
  local anonymous struct with the word at that offset; a `(u32 *)` cast folds into `=sym+0x1C`
  (sub_0803EED8).
* A loop that keeps a global array's address in a callee-saved register (`ldr r6, =sym` before the
  loop, `adds r0, r4, r6` inside): declare the pointer inside the loop body
  (`for (...) { u8 *p = gSym; f(p[i]); }`); a pointer declared outside swaps the `adds` operands.
* Two adjacent constant addresses where the second is built from the first (`ldr r4, =A; adds r4, #-0x160`)
  come from one symbol with two offsets (`gSym + 0xB0`, then `gSym`). Destination literals that are each
  loaded fresh (`0x0202F980`, `0x0202F9A0`) are plain integer casts, not `gPaletteBackup + n`.
* One branch that compares the new value of `++x` and another that tests a call first, sharing the
  compare (`b` to a `cmp r0, #0x3C`): use a local (`n = ++x;` / `n = x;`) and compare it after the if.
* A shared tail where both branches end with the same stores (`movs r1, #0` hoisted into each branch):
  write the tail in both branches.
* A callee that narrows its parameters (`lsls/lsrs` at entry) while its matched callers pass plain
  ints: the callers were compiled without a prototype. Declare it `void f();` in the header and write
  the definition K&R-style (`void f(a, b) u32 a; u8 b; { ... }`); a prototype with `u8` params changes
  the callers (setup_scene_with_bg_and_sprites, init_scene_with_bg_and_palette).
* `x | f` where the original materializes the constant first (`movs r0, #0x80; lsls; orrs r0, r4`) and
  your build ORs into the variable: check whether the value is really `size / 2` of a wider value.
  `dma3_copy_or_decompress` matched only as CpuCopy16 of the first half + a DMA3 copy of the second
  half (`size = hdr >> 8`, `size / 2 / 2` for the count).
* Same pattern with a byte flag: `u32 f = x & 0x1F; ... = (y & 0x80) | f` (a `u8 f` swaps the `orrs`)
  (export_medals_to_buffer).
* A struct-returning function whose epilogue is `pop {r1}; bx r1` with `mov r0, <hidden ptr>` before the
  final `str`: that is the normal struct return. A table declared `[][8]` read as a flat `s16` array
  needs `tbl[0][i]`; a `(const s16 *)` cast reorders the base load (calc_polar_to_screen_coords).
* A u8 key byte read with `ldrb` from `gNewKeys` (u16): `KEYS_LO(gNewKeys) & mask`.
* A constant stored to an I/O register that goes **straight into `r0`** after the address
  (`ldr r1, =REG; ldr r0, =0xA0C; strh r0, [r1]`), while plain `REG = 0xA0C;` gives
  `ldr r2, =0xA0C; adds r0, r2, #0`: take the register's address and the value into locals,
  `vu16 *r = &REG_BLDALPHA; u16 v = 0xA0C; *r = v;` (sub_080487E4, sub_080487AC). Worth trying on
  the older `REG_X = const` near misses.
* `adds r0, r0, #imm` folded into one constant where the original kept `(t - 0xC0) * 2` and
  `(x + 0x28)` apart: combine reassociates even through a `static inline` helper (sub_080481C4,
  unsolved).
* A loop whose index is only used in an address (`0x05000200 + i * 0x20`) keeps its up-counter
  and the strength-reduced address is set up *after* the hoisted invariants; an explicit
  `dst += 0x20` pointer is set up first (dma_load_obj_palettes_08048664).
* A loop condition that calls a function and a body that calls it again with the same argument
  (`for (i = 0; (t = f(i)) != 0xFF; i++) { t = f(i); ... }`): the original really calls it twice.
* A bitfield tested with `ldrb; movs #0xF; ands` but read elsewhere with `lsls/lsrs`: the test was
  written on the raw byte (`(*(u8 *)desc & 0xF) == 0`), gcc narrows the mask test to a byte load.
* A function table entry whose first instructions sit in the previous function's `.byte` tail
  (render_sprite_if_visible started 8 bytes before its listed address): move the start in
  `config/functions.tsv` and prepend the instructions to its `.s`.
* **The file context changes the high-register choice.** Which of `ip` / `sl` / `r8` holds a value
  (and so which `mov` encodings appear) depends on the functions compiled *before* it in the same
  `.c` file; `INCLUDE_ASM` functions don't count, C functions do. A function can match in
  `match.py` (compiled alone) and still fail in `install_func.py` (sub_0805C190: same code, the three
  hi registers rotated). Nothing about the function's own source fixes it; it should match once the
  `INCLUDE_ASM` functions before it in the file are C. Keep such functions in `scratch/` and retry
  later. A mismatch that is only an `ip`/`r8` swap in scratch may be the same effect.
* `p = (u16 *)(bgbase + x * 2) + y * 32`-style tilemap addresses: gcc reassociates
  `bg * 0x800 + (x * 2 + VRAM)` so the constant ends up last. Writing
  `(u16 *)(VRAM + (bg << 11)) + col + row * 32` gives the original's `row * 64 + 0x060000xx` then
  `+ bg` order (sub_0805BC6C, sub_0805C190).
* Inner loops `for (j = 0; j <= 15; j++)` and `for (j = 15; j >= 0; j--)` both become count-down
  loops, but only the up-counting source gives the original's `i + 1` kept in another register
  (sub_0805BC6C).
* One local reused for two unrelated values (an "empty name" flag, then a stored checksum) shows as
  both living in the same callee-saved register (validate_save_data).
* A u8 parameter tested as `lsls r1, r1, #24; cmp r1, #0` with the truncation *after* other setup:
  the parameter is `u32`/`int` and the test is `if ((u8)force)` (write_save_to_eeprom).
* `bool32` sprite / state handlers whose original falls through to `movs r0, #1` and branches to
  `movs r0, #0`: write the FALSE case first (`if (a < b) return FALSE; return TRUE;`, or
  `if (x > 0x8F) { ...; return FALSE; } return TRUE;`). The mirrored `if (a >= b) return TRUE;`
  flips the branch (race sprite handlers sub_0806B014 .. sub_0806B124).
* `ldr rB, =gUnk_03002C30` **before** `lsls rI, sprite, #6`: index the global in every statement
  (`gUnk_03002C30[sprite].unk2 += 2;`); a `struct Unk_03002C30 *s = &gUnk_03002C30[sprite]` local
  computes the shift first (sub_0806AFA0, update_sprite_animations_tick_0806AF40).
* `x = c ? 1 : 2;` into a struct field reached through a pointer local loads the pointer before the
  test; an `if` with a temporary loads it after (sub_08069158).
* A local array initializer that the original clears with `bl memset` (`custom_memset`) and then
  fills element by element: write **every** element, zeros included
  (`u16 pal[16] = {0, 0x6FFF, ..., 0, 0, 0}`). agbcc only takes the clear-then-store path when 3/4
  of the *written* elements are zero; with the zeros left implicit it copies the whole array from
  .rodata with memcpy instead. `memset` is a second label on `custom_memset` in `asm/lib/libgcc.s`
  (init_scene_with_palette_and_song_25).
* `ldrh; ands rX, #0x1f` done in place (no second register for the masked value) and a later
  `strb rX` of the known-zero result: `(u16)s->unk3A % 32 == 0` instead of `(s->unk3A & 0x1F) == 0`
  (sub_080677E0).
* A ROM table that the original reloads after unrelated stores (outgoing stack arguments, struct
  fields) is declared without `const`: agbcc keeps loads from `const` arrays live across stores and
  CSEs them (gUnk_08485CC4, divide_by_3 / update_battle_bot_damage_animations).
* A `u16`/`u32` zero on the stack whose address is taken *before* the zero is materialized
  (`add r1, sp, #4; movs r0, #0; strh r0, [r1]`): declare it `vu16` / `vu32`
  (init_battle_bg_layer1, load_bg_tilemaps_and_palette).
* `s->unk84++` through a struct pointer vs `(*n)++` through a `u8 *` local change where a following
  zero constant is materialized (sub_080676DC).
* Two values read from the same struct in one function where the original loads the struct base
  first, then the index (`ldr r2, =base; ldr r0, =&idx; ldrb r1, [r0]`): `struct T *b = gBase;
  struct T *m = &b[gIdx];` (sub_08068104).
* Unsolved: `x - (y - k)` computed as `subs r1, #k; subs r1, rX, r1` in the original; agbcc folds
  every spelling tried into `(x + k) - y` (`-((y - k) - x)`, casts to `u32`, `+ -k`)
  (divide_by_3, sub_08069A68, update_battle_bot_damage_animations).
  Possible fix (session 69): update_battle_bot_death_animations gets `i * 3 - (stage - 1)` right with a
  `static inline int sub1(int x) { return x - 1; }` helper (`i * 3 - sub1(stage)`), or an assignment
  inside the argument (`i * 3 - (t = stage - 1)`). Try it on the three above.
* A `static inline` helper also stops gcc hoisting a loop-invariant address out of a loop
  (`base += col * 2; return row * 64 + base;`, write_tilemap_tiles_dma).
* An argument passed without truncation (`i + 20` with no `lsls/lsrs #24`) to a function whose
  prototype takes `u8`: the original saw an `int` / unprototyped declaration; call through a
  `((void (*)())f)(...)` cast (update_battle_bot_entry_animations).
* `for (i = 0; i < 5u; i++)` / `i < sizeof(arr)` (unsigned bound) gives `bls` instead of `ble`
  (init_scene_with_palette_and_song_5).
* **agbcc pads every union (and struct) to a multiple of 4 bytes.** A `union { u16 h; u8 b; }` at
  0xC takes 0xC..0xF, so a field declared after it lands at 0x10, not 0xE. Put such neighbours inside
  the union (`s8 s[4]`, struct Unk_03001800_s.unkC).
* Two copies of one stack-array base (`movs r7, #0` before `mov ip, r5` in the original, the other
  order in yours) in a "widen a 30x20 tilemap to 32x20" loop: read the source as `*(map[i] + j)`
  instead of `map[i][j]` (boot_logos_load_licensed_by and its two siblings).
* An I/O register read once for a compare and the value reused for the first use, then re-read
  after each store (`ldrb r0, [r3]; cmp r0, #0x9E; ... adds r0, #1` with no second load): the original
  read it through a non-volatile pointer (`*(u8 *)REG_ADDR_VCOUNT`, sub_0806D420).
* A callee result compared with `bgt` for `> 1` (signed) where yours gives `bcc`: the function-table
  type returns `s32`, not `bool32` (update_sprite_special_effects).
* A loop that waits until `timer == n * 2` with `n` kept in a register: a local `s32 n = 0xC4;`, and
  the test written `n * 2 <= timer` to keep the original `cmp` operand order (sub_0806F0B4).
* `ands` with the constant loaded first (`movs r1, #3; ands r1, r0`) where `& 3` gives `ands r0, r1`
  the other way round: the original wrote `x % 4` on an unsigned value (sub_0806C7C4, bomb_game_drop_bombs).
* A switch whose compare tree pivots on 1 instead of the middle case: add an empty `case 0: break;`
  (sub_0806BEF0, sub_0806C20C). Case body order in the source also changes the block order.
* `x = cond ? a : b - 1;` stored with a single `strb` after both paths: write the store as one ternary;
  an if/else gives two stores (sub_0806B9D0).
* A table copied to the stack with `ldm`/`stm` is a struct copy (`struct S32Array3 t = gUnk_080AFF34;`);
  a byte-wise `memcpy` call is `memcpy(buf, table, n)` (sub_0806C500, sub_0806C994). Both tables live
  in the data blob, so they need symbols, not local initializers.
* A VRAM store followed by a read-back of the same halfword (`strh r0, [r1]; ldrh r0, [r1]`) is a
  `vu16 *p` with a bare `*p++;` statement after the store (the number drawers `draw_number*`).
* `(s32)some_float` needs `__fixsfsi`; libgcc.s exports it as an alias of `float_to_int`.
* Float and double code: write plain C (`a * b`, `(s32)f`, `(double)i`, `-f`). `asm/lib/libgcc.s` gives the
  ROM's soft-float routines their standard names (`__addsf3`, `__fixsfsi`, `__floatsidf`, `__truncdfsf2`,
  `__negsf2`, ...). Calling the routines by their own names changes register use. Libcalls don't make gcc
  reload memory, so read struct fields inline at each use instead of copying them into temporaries.
* Accessors into a byte table (`u8 *p = gTable; p[i >> 1] ...`) may need the pointer local declared inside
  each branch, so the base is loaded before the index shift.
* A switch whose compare tree doesn't match and whose inner switch gets merged into the outer one: add a
  case value outside -1..127 (e.g. `case 0xFF:` sharing the default's body). That turns off agbcc's switch
  cost table and gave the original order in sub_0804FCC4.
* `(a & 0xF0) >> 4` and `a >> 4` compile differently for a u8 `a`; use the masked form when the original
  has `movs rX, #0xF0; ands`.
* A `[][8]` s16 table indexed with a flat computed index: write `tbl[0][idx]`, not a pointer cast
  (`((const s16 *)tbl)[idx]` swapped two registers in sub_0804F3AC).
* Text tile flush (`if (unk14 & 7) CpuSet(buf, VRAM + 0x280 + unk17 * 0x680 + col * 0x40, n)`): test the low
  bits through a bitfield view (`((struct TextColBits *)&gUnk_03000440)->col`, which makes gcc reload unk14),
  compute the column into a `u8` local with `/ 8` (not `>> 3`) and write the address as
  `col * 0x40 + VRAM + 0x280 + unk17 * 0x680` (reset_text_tile_state, sub_0804070C ... in code_0803CDCC).
* Where the original reads a field twice in a row or re-reads a byte just stored, only a volatile read
  reproduces it: `*(vu16 *)&gUnk_03000440.unkC`.
* A constant like 0xFFFF8000 built from `x + 0x8000` with an `s16` intermediate: put the sum in an
  assignment inside the expression, `a + (flag = (b & 0x100) + 0x8000)` with `s16 flag` (sub_08014B34).
* An address strength-reduced across a loop that the original recomputes: assign the row inside the index,
  `[((a = i + 4) - step) * 32]` (bg_tilemap_scroll_up_row).
* A `cond ? tblA[c] : tblB[c]` that computes `c * 2` too early: write if / else with the whole statement in
  both arms.
* Do not run `tools/scripts/tryin.py` for two functions of the same module at the same time (or while
  installing into it): it rewrites `src/<module>.c` and restores its saved copy afterwards.
* Several early exits that share one failure store: make the store the final `else { fail: ... }` arm of the
  if / else-if chain and `goto fail` from the checks above it (sub_0801C524).
* A function that leaves its incoming r0 untouched and returns it (no `movs r0`, but callers ignore the
  value): an old-style definition `u32 f(a) u32 a; { ...; return a; }` with an unprototyped `u32 f();` in
  functions.h, so callers may still pass nothing (sub_080361A8).
* A non-void function with no return statement (`pop {r1}` epilogue, r0 never set) is written as `u32 f(...)`
  without `return`; agbcc accepts it (sub_08037728).
