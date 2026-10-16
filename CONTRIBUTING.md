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

## Naming

* Functions keep their `sub_XXXXXXXX` names until their purpose is known. Names that came from
  research (`read_keys`, `main`, ...) are snake_case.
* Globals are `gCamelCase`. ROM data that isn't understood yet is named `gUnk_XXXXXXXX` or by what
  it holds plus its address (`gGameStateHandlers_083AC148`).
