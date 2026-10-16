# Decompiling a function

1. Build once (`make compare`) so `medabots_rokusho.elf` exists. `match.py` links against it.
2. Pick a function from `src/<module>.c` that is still `INCLUDE_ASM`'d and read its asm in
   `asm/nonmatching/<module>/<name>.s`. `python3 tools/scripts/candidates.py --leaf` lists the
   remaining functions, leaf functions (no calls) first, then by size; `--module` narrows it down.
3. Write it in a scratch file that starts with `#include "global.h"`, then check it:

   ```sh
   python3 tools/scripts/match.py <name> scratch.c
   ```

   This compiles with old_agbcc (the compiler the Makefile uses), links at the function's original address and compares the bytes
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

## Naming

* Functions keep their `sub_XXXXXXXX` names until their purpose is known. Names that came from
  research (`read_keys`, `main`, ...) are snake_case.
* Globals are `gCamelCase`. ROM data that isn't understood yet is named `gUnk_XXXXXXXX` or by what
  it holds plus its address (`gGameStateHandlers_083AC148`).
