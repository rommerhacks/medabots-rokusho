# Medabots: Rokusho Version (USA)

This is a work-in-progress decompilation of **Medabots: Rokusho Version** for the Game Boy Advance
(Natsume, 2002).

It builds the following ROM:

* [**medabots_rokusho.gba**](https://datomatic.no-intro.org/) `sha1: c4572428ea97b302f699a3b4eba2a1f0e87c1c9c`
  (`MEDABOTSRKSV`, game code `A9BE`, revision 0)

To set up the repository, see [INSTALL.md](INSTALL.md).

**This repository does not contain the game.** You need your own copy of the ROM; its graphics,
sound and data are copied out of it at build time.

## Status

Every function is decompiled: the C in `src/` compiles back to the original ROM byte for byte
(`make compare`), and `make shifted` builds a copy with all code and data moved, which still plays.
The code is now being reorganised into the game's original modules, grouped by system (see Layout).
Run `make progress` to see the numbers.

| | |
|---|---|
| Compiler | pret's agbcc (gcc 2.95-based), `-O2 -mthumb-interwork -fprologue-bugfix` for every C file |
| Code | `0x0800025C`-`0x080750D7` game code (Thumb), `0x0807C740`-`0x0807E6EF` SDK libraries |
| Libraries | EEPROM_V122, libgcc, BIOS syscall stubs (kept as asm in `asm/lib/`) |
| Sound | custom sequencer and driver (`src/audio/sound_seq.c`, `src/audio/sound_driver.c`), not m4a |
| Data | still `.incbin` from `baserom.gba` (`data/`, `sound/`, `graphics/`) |

## Layout

| Path | Contents |
|---|---|
| `src/<system>/<module>.c` | C modules in ROM (link) order, each a contiguous run of functions; see the systems below |
| `src/code_XXXXXXXX.c` | regions not split into modules yet (named after their start address) |
| `asm/nonmatching/<module>/` | `.s` files of functions not decompiled yet (none left) |
| `asm/crt0.s`, `asm/lib/` | startup code and SDK libraries |
| `include/` | `include/<system>/<module>.h` (one per module), `functions.h` (prototypes of the regions not split yet; includes the module headers), `variables.h` (RAM/ROM data), `structs.h`, `gba/` |
| `config/clang-format.yml` | the code style (`make format`, `make format-check`) |
| `symbols.ld` | absolute addresses of RAM variables and ROM data used from C |
| `config/functions.tsv` | every function: address, original size, name, module |
| `tools/scripts/` | `match.py`, `install_func.py`, `candidates.py`, `progress.py`, `romdiff.py` (see [CONTRIBUTING.md](CONTRIBUTING.md)) |

### Systems

| System | Folder | What's in it |
|---|---|---|
| Engine | `src/engine/` | boot and main loop, interrupts, LZ decompression, BG / palette / OAM helpers, random numbers, the game-mode-0 state dispatcher |
| Link | `src/link/` | serial link cable transfer |
| Menus | `src/menu/` | field pause menu, Medawatch, Medabots screen (team / detail / team select), Medals screen, Medaparts screen |
| Battle | `src/battle/` | Robattle intro and results (game state 6), the Robattle state machine (state 7), battle Medabots and AI, battle screen drawing, command ring, part select, Medaforce select, status screen, action scripts and skill effects (states 8 and 9), combat helpers, particles, battle sequences |
| Debug | `src/debug/` | the developer debug menu and its entries |
| Audio | `src/audio/` | the game's own sound engine (sequencer and driver) |

Folders for the field, Robattle, title and minigame code follow as the remaining `code_*` regions are
split.

## See also

* [rommer-gba](https://github.com/rommerhacks/rommer-gba): patches and research notes for this game.
* [pret](https://github.com/pret), whose decompilation layout and tooling this project follows.
