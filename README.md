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

Every function has been disassembled into `asm/nonmatching/`. The C files in `src/` include them
with `INCLUDE_ASM(...)`; decompiling a function replaces its `INCLUDE_ASM` line with C that old_agbcc
compiles to the original bytes. Run `make progress` to see the current numbers.

| | |
|---|---|
| Compiler | old_agbcc (`gcc 2.9-arm-000512`, the Nintendo AGB SDK compiler, without pret's agbcc changes), `-O2 -mthumb-interwork` |
| Code | `0x0800025C`-`0x080750D7` game code (Thumb), `0x0807C740`-`0x0807E6EF` SDK libraries |
| Libraries | EEPROM_V122, libgcc, BIOS syscall stubs (kept as asm in `asm/lib/`) |
| Sound | custom driver (`src/sound_driver.c`), not m4a |
| Data | still `.incbin` from `baserom.gba` (`data/`, `sound/`, `graphics/`) |

## Layout

| Path | Contents |
|---|---|
| `src/*.c` | C modules (one per code region for now; they get renamed as their purpose is understood) |
| `asm/nonmatching/<module>/` | one `.s` file per function not decompiled yet |
| `asm/crt0.s`, `asm/lib/` | startup code and SDK libraries |
| `include/` | headers: `functions.h` (prototypes), `variables.h` (RAM/ROM data), `gba/` |
| `symbols.ld` | absolute addresses of RAM variables and ROM data used from C |
| `config/functions.tsv` | every function: address, original size, name, module |
| `tools/scripts/` | `match.py`, `install_func.py`, `candidates.py`, `progress.py`, `romdiff.py` (see [CONTRIBUTING.md](CONTRIBUTING.md)) |

## See also

* [rommer-gba](https://github.com/rommerhacks/rommer-gba): patches and research notes for this game.
* [pret](https://github.com/pret), whose decompilation layout and tooling this project follows.
