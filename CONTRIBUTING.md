# Decompiling a function

1. Build once (`make compare`) so `medabots_rokusho.elf` exists. `match.py` links against it.
2. Pick a function from `src/<module>.c` that is still `INCLUDE_ASM`'d and read its asm in
   `asm/nonmatching/<module>/<name>.s`. `python3 tools/scripts/candidates.py --leaf` lists the
   remaining functions, leaf functions (no calls) first, then by size; `--module` narrows it down.
3. Write it in a scratch file that starts with `#include "global.h"`, then check it:

   ```sh
   python3 tools/scripts/match.py <name> scratch.c
   ```

   This compiles the way the Makefile does for that function's module (old_agbcc, or agbcc
   `-fprologue-bugfix` for the sound modules listed in `SOUND_OBJS`), links at the function's original address and compares the bytes
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
* The game was built with what pret ships as `old_agbcc`: with `agbcc`, leaf functions that branch
  get an extra `push {lr}` that the original doesn't have. `match.py --new` tries `agbcc`.
* The sound code from `0x08072234` on (`sound_seq.c`, `sound_driver.c`) was built differently: it
  matches pret's `agbcc` with `-fprologue-bugfix` (no `push {lr}` in branching leaf functions, but
  agbcc's better address CSE, e.g. `subs r2, #0x16` to reach a neighbouring field). The Makefile sets
  this per object (`SOUND_OBJS`) and `match.py` picks it from the module (`BUGFIX_MODULES`).
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

## Naming

* Functions keep their `sub_XXXXXXXX` names until their purpose is known. Names that came from
  research (`read_keys`, `main`, ...) are snake_case.
* Globals are `gCamelCase`. ROM data that isn't understood yet is named `gUnk_XXXXXXXX` or by what
  it holds plus its address (`gGameStateHandlers_083AC148`).
