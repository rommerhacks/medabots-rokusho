# Releases

## 1.0 (2026-11-06)

- **Matching:** 3,475/3,475 functions, 478,844/478,844 bytes (100.0%); 0 documented NONMATCHING. `make compare` rebuilds the original ROM (SHA-1 `c4572428ea97b302f699a3b4eba2a1f0e87c1c9c`) byte for byte.
- **Shiftable:** the code can move (`make shifted`) and the game still plays.
- **Names:** 3,475/3,475 functions and 1,329/1,329 globals named; 4,946/4,967 locals and parameters descriptive.
- **Playthrough:** 94 walkthrough segments play from power-on to the ending on the shifted build, through 3.7f The Great Escape.
- **Systems documented** (`docs/systems.md`): The main loop and the state machine, Systems.

Build it with your own copy of the game as `baserom.gba` (see the README); nothing from the game is in this repository.
