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

How the systems call each other, the main loop and the game-mode state machine are described in
[docs/systems.md](docs/systems.md).

| System | Folder | What's in it |
|---|---|---|
| Engine | `src/engine/` | boot and main loop, interrupts, LZ decompression, BG / tilemap / palette / OAM helpers, palette blends, byte memory helpers, shared menu/battle helpers (`common.c`), the sprite slot table, random numbers, the game-mode-0 state dispatcher, blend fades, fixed-point 3-D matrices and sprite rings, the game-mode-3 dispatcher and its screen transitions |
| Link | `src/link/` | serial link cable transfer, link Robattle (game state 10), the link menu / connect prompt / trade scenes and Medal handshakes (mode-2 states 16, 17, 20, 21, 26, 27) |
| Text | `src/text/` | the message window: text printing, glyph rendering, message commands; the yes/no choice menu |
| Inventory | `src/inventory/` | Medals, Medaparts, items and the Tinpet team the player owns |
| Menus | `src/menu/` | field pause menu, Medawatch, Medabots screen (team / detail / team select), Medals screen, Medaparts screen, item screen and item lists, name entry, Town Map |
| Field | `src/field/` | the field game mode (mode 1): frame update, area graphics and effects, the map script interpreter and its per-frame command updates, script sprites, the player's walk / warp handler and scene changes, player movement, map objects / events, the 3-D scene sequences |
| Battle | `src/battle/` | Robattle intro and results (game state 6), the Robattle state machine (state 7), battle Medabots and AI, battle screen drawing, command ring, part select, Medaforce select, status screen, action scripts and skill effects (states 8 and 9), combat helpers, particles, battle sequences, the Medal level-up screen after a Robattle (guess) |
| Title | `src/title/` | the game-mode-2 state dispatcher, the title menu, the new-game prompt, the hidden TEST MODE, the screen after a lost Robattle, the boot logos, the opening intro and the title screen (mode 3 states 0-2) |
| Save | `src/save/` | the save screen, EEPROM save data load / write / checks, the "saved data has been lost" screen |
| Shop | `src/shop/` | the Medaparts shop: Buy / Sell menu, the buy / sell list and cart, the return from the Medaparts screen, the Medal shop (guess) |
| Debug | `src/debug/` | the developer debug menu and its entries |
| Minigames | `src/minigame/` | the race and bomb minigames (mode 3 states 4-5) |
| Cutscenes | `src/cutscene/` | the scrolling-text scene (mode-2 state 22), the event picture with a message (mode-3 state 3), Medabots Weekly (mode-3 state 6) |
| Audio | `src/audio/` | the game's own sound engine (sequencer and driver) |

## See also

* [rommer-gba](https://github.com/rommerhacks/rommer-gba): patches and research notes for this game.
* [pret](https://github.com/pret), whose decompilation layout and tooling this project follows.
