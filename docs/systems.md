# How the game is put together

This page gives an overview of the game's systems: the main loop, the state machine that picks which screen
runs, and which systems call which. The [README](../README.md) has the folder layout. Names marked "guess" in
the source are still unconfirmed.

## The main loop and the state machine

`AgbMain` (`src/engine/main.c`) sets up the hardware, interrupts, the sound engine and the serial link, then
runs one iteration per VBlank: `read_keys`, the play-time counter, the link status, then the handler of the
current **game mode**, `gGameModeHandlers[gGameMode]`, then the OAM copy and the outgoing link packet.

The current screen is picked by three bytes:

* `gGameMode`: which top-level dispatcher runs (0-3, below);
* `gGameState`: the screen inside that mode (each mode has a table of `*_update` functions);
* `gGameSubState`: the step inside that screen (each screen has its own table of sub-state handlers).

So every screen module has the same shape: an `*_update` dispatcher that calls
`table[gGameSubState]()`, the sub-state handlers, and the drawing helpers they share. Screens change mode by
writing the three bytes directly, through `switch_game_mode` (`src/field/field_mode.c`, used by field scripts
to start Robattles, shops, minigames and cutscenes), or through the mode-3 scene transitions, which store the
next mode / state / sub-state and switch once the fade is done.

| mode | dispatcher | screens |
|---|---|---|
| 0 | `src/engine/game_state.c` | menus and Robattles: test screen (0), field menu (1), Medawatch (2), Medabots (3), Medals (4), Medaparts (5), Robattle intro / results (6), the Robattle (7-9), link Robattle (10), debug menu (63) |
| 1 | `src/field/field_mode.c` | the field: walking, map scripts, the vehicle menu (guess), the field debug pages |
| 2 | `src/title/title_menu.c` | title menu, item screen, save, name entry, TEST MODE, game over, save lost, Town Map, shops, link menu and trades, text scroll, Medal level-up |
| 3 | `src/engine/scene_transition.c` | boot logos (0), intro (1), title screen (2), event picture (3), race (4), bomb game (5), Medabots Weekly (6) |

The game boots into mode 3 state 0 (boot logos), which runs into the intro and the title screen; START on the
title screen goes to the mode-2 title menu, and starting or loading a game enters the field (mode 1).

## Systems

**Engine** (`src/engine/`). Everything the screens share: the main loop and interrupts, LZ decompression,
BG / tilemap / palette / OAM helpers, palette blends and fades, the sprite slot table and sprite trees, random
numbers, fixed-point 3-D matrices and the mode-0 and mode-3 dispatchers. It calls nothing above it except
through the handler tables.

**Field** (`src/field/`). Mode 1. `field_update` runs the field sub-states; the map script interpreter
(`map_script.c`) runs one command per step and `map_script_update.c` runs the per-frame part of commands that
take several frames. Script commands move script sprites, change areas, give items and money
(`script_helpers.c`), and start other screens through `switch_game_mode`: Robattles (battle), shops, cutscenes
and minigames. The player's walk, warps and map objects live in `player_walk.c`, `field_walk.c` and
`map_objects.c`.

Random encounters: at the end of each step `player_walk.c` calls `check_random_encounter`
(`src/engine/common.c`). An area with a non-zero `gAreaBattleSettings` rate counts steps in
`gFieldWork.encounter_steps`; from step 17 each step has a 1-in-32 chance, and step 32 always starts a battle. The
counter is reset on area load and by a random battle, not by a scripted one. The step that triggers a map event
is not counted. `setup_random_encounter_enemies` (`src/battle/prebattle.c`) then picks the team from
`gAreaRandomEncounters`.

**Battle** (`src/battle/`). Mode 0 states 6-9. `prebattle.c` runs the intro before and the results after a
Robattle; `robattle.c` is the turn loop (command ring, part select, Medaforce select, status screen); state 8
(`action_phase.c`) picks actions, with the AI in `battle_ai.c`; state 9 (`action_script.c`) runs the action
scripts, whose opcodes are split by ability type across `action_steps.c`, `defend_heal_skills.c`,
`support_skills.c`, `interrupt_skills.c` and `medaforce_effects.c`. Damage and stat helpers, sprites, particles
and the close-up scenes are the rest. Battle uses the engine, text and inventory systems.

**Link** (`src/link/`). The serial transfer (`serial.c`, also used by the main loop every frame), link
Robattles (mode 0 state 10) and the mode-2 link menu, trade and Medal handshake screens.

**Menus** (`src/menu/`). The field pause menu and the screens it opens: Medawatch, Medabots, Medals,
Medaparts, items, Town Map, plus name entry. They read and change the inventory.

**Inventory** (`src/inventory/`). The Medals, Medaparts, items and team the player owns, with the list sorts.
Used by menus, shops, battle and field scripts.

**Text** (`src/text/`). The message window (`message.c`): text printing, glyphs and message commands; the
yes/no choice menu. Used by nearly every screen.

**Title** (`src/title/`). The mode-2 dispatcher and title menu, the new-game prompt, TEST MODE, the screen
after a lost Robattle, and the mode-3 boot logos, intro and title screen.

**Save** (`src/save/`). The save screen, EEPROM load / write / checks and the "saved data has been lost"
screen.

**Shop** (`src/shop/`). The Medaparts shop (Buy / Sell, lists and cart) and the Medal shop (guess), entered
from field scripts.

**Cutscenes** (`src/cutscene/`). The scrolling-text scene, the event picture with a message and Medabots
Weekly, the in-game TV show: curtains open on a studio, four characters walk on and talk, the "Medabots
Lecture" corner assembles a Medabot part by part, and the curtains close again. Its sub-states are a linear
script; sprite moves are small effect functions (`gWeeklySpriteEffects`) and the lecture's build steps are
`gWeeklyLectureSteps`.

**Minigames** (`src/minigame/`). The race and the bomb game, both mode-3 states.

**Debug** (`src/debug/`). The developer debug menu (mode 0 state 63) and its entries.

**Audio** (`src/audio/`). The game's own sound engine (not m4a): the sequencer (`sound_seq.c`) reads the song
byte streams and runs envelopes and vibrato; the driver (`sound_driver.c`) ticks once a frame from the VBlank
handler and writes the PSG and Direct Sound channels. Screens call `play_song` and `play_sound_effect`.
The work area (`struct SoundWork`, `gSoundWork`) holds 13 tracks (`struct SoundTrack`): 0-3 music on PSG
channels 1-4, 4-7 sound effects on the same channels, 8/9 music and 10/11 sound effects on Direct Sound FIFO A/B,
12 music drums on the noise channel. A sound effect track takes its channel over and hands it back when it ends
(`sound_on_*_end`). Each track has a sequence pointer (`seqPos`), a command stream of notes, rests, volumes and
0xE0-0xFF commands (`sound_cmd_*`: loops, jump/call, envelope, vibrato, pan, echo, note mode), and a per-frame
`tick`. The two Direct Sound channels (`struct SoundMixChannel`) are refilled from the DMA1/DMA2 interrupts
(`sound_mix_refill_fifo_a/b`); songs and effects come from `gSongTable` / `gSoundEffectTable`.
