#ifndef GUARD_VARIABLES_H
#define GUARD_VARIABLES_H

// RAM variables and ROM data. Addresses are in symbols.ld.

typedef void (*Func)(void);

// RAM
extern struct GameWork gGameWork;
extern struct BattleBot gBattleBots[];
extern u8 gUnk_03000890[];
extern u8 gUnk_03000B90; // guess: link player id (0/1)
extern struct MedalData gMedals[];
extern u32 gFrameCounter;
extern u32 gGameMode;
extern struct TeamSlot gTeamSlots[];
extern struct BattleWork gBattleWork;
extern struct SceneWork gSceneWork;       // same address as gBattleWork (game mode 3 scenes)
extern struct BombGameWork gBombGameWork; // same address as gBattleWork (game mode 3 state 5)
// A view through gBattleWork itself: the scene init also clears that block, and the literal pool shares one address.
#define gMedabotsWeekly (*(struct MedabotsWeeklyWork *)&gBattleWork)
extern u32 gMoney; // money, capped at 99999 (add_money)
extern u32 gGameState;
extern u32 gGameSubState;
extern struct SpriteEntry gSpriteEntries[];
extern struct SioLink gSioLink;
extern s32 gUnk_03005048;       // OAM affine zoom override (-1 = off)
extern s16 gUnk_080750E0[];     // Q14 sine table, 1024 steps per turn (cos at +0x100); not const: callers reload it
extern u8 gUnk_02030A00[];      // second half of the BG2 per-scanline affine double buffer (first: gDecompressBuffer)
extern u32 gUnk_03005250[0x10]; // IWRAM copy of link_buffer_swap_arm
extern u32 gUnk_03005050[0x48]; // IWRAM copy of serial_multiplayer_transfer_handler
extern const Func gUnk_083ABE18[]; // game mode handlers (AgbMain)
extern struct Unk_03005350 gUnk_03005350;
extern struct FieldDebugWork gFieldDebug;
extern u8 *gMapScriptData; // current map script data (banked, see read_map_script_byte)
extern struct FieldWork gFieldWork;
extern struct Unk_030064A0 gUnk_030064A0;
extern struct Unk_03006D20 gUnk_03006D20;
extern struct SoundWork *gSoundWork;
extern struct SoundWork gSoundWorkArea; // sound work area (soft_reset_to_title passes it to sound_init)
extern struct Vec16 gBg1Scroll;         // BG1 scroll (field: map camera)
extern struct Unk_03005310 gUnk_03005310;
extern struct BlendEffectState gBlendEffect;
extern struct MenuWork *gMenuWork;
extern struct Unk_030055A0 gUnk_030055A0[];
extern struct Vec16 gBg2Scroll; // BG2 scroll
extern struct Vec16 gBg3Scroll; // BG3 scroll
extern u8 *gEventFlags;         // two 4-bit entries per byte (bit 3 / bit 7: flag, bits 0-2 / 4-6: count)
extern u16 *gFieldTilemapBuf;
extern struct Unk_03006D38 gUnk_03006D38;
extern u8 gUnk_03003810;
extern struct Unk_03005010 gUnk_03005010;
extern s8 gUnk_03005030;               // multiplayer link active (soft_reset)
extern vu16 gUnk_03002B90;             // bit 0: vblank handler running
extern s8 gUnk_03002410;               // frames since the main loop last ran (vblank_irq)
extern Func gIntrTable[14];            // RAM copy of gIntrTableTemplate, used by irq_dispatch_arm
extern u32 gIntrMain[0x200];           // RAM copy of irq_dispatch_arm (the IRQ vector)
extern Func gVBlankCallback;           // called every vblank
extern Func gVBlankOnceCallback;       // called at the next vblank, then reset to empty_callback
extern Func gHBlankCallback;           // called by hblank_irq
extern struct OamData gOamBuffer[128]; // copied to OAM in vblank_body
extern struct SpriteWork *gSpriteWork;
extern struct SceneSlot *gUnk_03005308;
extern u32 gVBlankOamMode;          // vblank_body OAM mode (0, 2)
extern u8 gUnk_03000434;            // bit 0: vblank_body skips the BG scroll registers
extern struct Vec16 gUnk_03002C2C;  // scroll added to every BG layer
extern struct Vec16 gBg0Scroll;     // BG0 scroll
extern u16 gTilemapBaseEntry;       // added to every tilemap entry by write_tilemap_to_vram_08000E94
extern u8 gDecompressBuffer[];      // EWRAM buffer the tilemap loaders decompress into
extern u16 gPaletteBackup[0x200];   // OBJ then BG palette (palette_backup_from_hardware)
extern u16 gPaletteBackupBg[0x100]; // = gPaletteBackup + 0x100
extern u16 gPaletteBuffer[0x200];   // OBJ then BG palette (palette_buffer_upload)
extern u16 gPaletteBufferBg[0x100]; // = gPaletteBuffer + 0x100
extern u32 gRngCounter;
extern u32 gRngValue;
extern u32 gRngState;
extern u8 gUnk_03000588;

// ROM data
extern const Func gIntrTableTemplate[14];
extern const u32 gRngTable[16];
extern const struct Unk_03005290 gUnk_0807ECA0; // part layer templates: head, left arm, right arm, legs
extern const struct Unk_03005290 gUnk_0807ECB8; // (setup_medabot_part_sprites)
extern const struct Unk_03005290 gUnk_0807ECD0;
extern const struct Unk_03005290 gUnk_0807ECE8;
// Sprite tree node lists by part id: head, right arm, left arm, legs (non-const: needed to match)
extern struct SpriteTileRef gUnk_0807ED00[][4];
extern struct SpriteTileRef gUnk_0807F4A0[][4];
extern struct SpriteTileRef gUnk_0807FC40[][4];
extern struct SpriteTileRef gUnk_080803E0[][8];
extern struct SoundSongHeader *gSongTable[];        // song table (sound_init)
extern struct SoundSongHeader *gSoundEffectTable[]; // sound effect table (sound_init)
extern struct SoundDrumKit gDrumKit;
extern const u8 gInstrumentSamples[]; // sample pointers by SoundTrack.instrument
extern const u8 gDrumSamples[];       // sample pointers by drum index
extern const u8 gUnk_083D28C0[];
extern const u8 gUnk_083D2908[];
extern const u8 gPlayerFormSpriteSheets[]; // player form -> map sprite sheet id (its palette in gFieldSpritePalettes)
extern const u8 gUnk_083D29B6[];
extern const u16 *const gFieldSpritePalettes[]; // 16-colour OBJ palette per map sprite sheet id (NULL: none)
extern const u8 gUnk_083D2918[][8];
extern const u8 gSpriteSheetHasShadow[]; // per map sprite sheet id: give the sprite a shadow (sprite 0x90)
extern const u8 gUnk_083D28C3[][16];
extern const u8 gAreaMapSizes[][2];
extern const u8 gUnk_0847E948[];
extern const struct AreaWarp *const gAreaWarps[];
extern void (*const gMapScriptCommands[])(void); // map script command handlers
extern void (*const gMapScriptUpdates[])(void);  // per-command update handlers, run each frame while cmd_busy is set
extern const u8 gOppositeDirection[];            // indexed by the player's facing (gSpriteEntries[47].unk21)
extern const u8 gUnk_083D28B0[];        // indexed by gFieldWork.player_form, passed to script_sprite_begin_walk
extern const u8 *const gUnk_084045A8[]; // per area: tile map
extern const struct AreaGfx gUnk_083F92F4[];
extern const u8 gUnk_083D2903[];
extern const u8 gUnk_083D29E6[];
extern const u8 gUnk_085FA104[];                    // LZ77 sprite tiles
extern const struct MapExit *const gUnk_0840FAF4[]; // per area: 8-byte map exit records, 0xFF-terminated
extern const u16 gSoundPsgNoteFreqs[];
extern const u16 gSoundFifoVolumeMasks[];
extern const u8 gSoundFifoVolumeBits[][16];
extern const u16 gSoundFifoOutputBits[][4];
extern const u16 gSoundFifoOutputMasks[];
extern const u8 gSoundWavePatterns[][16];   // 4-bit samples for the wave channel (sound 3)
extern const u8 gSoundWaveVolumes[16];      // envelope volume -> SOUND3CNT_H volume bits (>> 8)
extern const u16 gSoundSemitoneRatios[12];  // 2^(i/12) * 0x1000
extern const u16 gSoundFinetuneRatios[128]; // 2^(i/(12*128)) * 0x1000
extern const u32 gSoundEffectTracks[6];     // track indices of the sound effect tracks (4-7, 10, 11)
extern const Func gGameStateHandlers_083AC148[];
extern const u32 gMedalNames[];      // Medal names by Medal id (0 KUWAGATA, 6 SNAKE...); +0x20: "Rokusho" / "Metabee"
extern const u8 gUnk_083B6158[][16]; // 16-byte records per Medal graphic index (byte 1 compared with a Medapart's
                                     // skill, byte 7 icon)
extern const u8 gUnk_083D1BF8[];
extern const u32 gUnk_083BA4D8[];
extern const u8 gUnk_083AD200[];         // 8 bytes per Medal attribute: base skill levels (init_enemy_bot_medal)
extern const u8 gUnk_083AD2F0[][4];      // 32 part orders (0xFF = end) tried by select_bot_battle_action
extern const u32 gUnk_083BB9CC[][4];     // Medapart name pointers: [part id][kind: head, right arm, left arm, legs]
extern const u32 gItemNames[];           // item name strings by item id (17 bytes, item lists)
extern vu32 *const gSoundFifoAddrs[];    // REG_FIFO_A, REG_FIFO_B
extern vu32 *const gSoundTimerRegs[];    // REG_TM0CNT, REG_TM1CNT (sample rate timers of FIFO A / B)
extern const u8 gSoundFifoResetBits[];   // SOUNDCNT_H high byte: FIFO A / B reset
extern const u16 gSoundFifoEnableBits[]; // SOUNDCNT_H: FIFO A / B left+right enable
extern vu16 *const gSoundFifoDmaCnt[];
extern const struct SoundTrackConfig gSoundTrackConfigs[13];
extern const u8 gSoundOutputMasks[4];   // SOUNDCNT_L high byte: clears the left/right enables of PSG channel i
extern const u8 gSoundOutputBits[4][4]; // [channel][output: 0 off, 1, 2, 3 both] SOUNDCNT_L high byte bits //
                                        // REG_DMA1CNT_H, REG_DMA2CNT_H
extern u8 gCurrentMedalSlot;            // gMedals slot the Medal level-up / naming screens work on
extern s32 gRaceStep;                   // step counter of the current race sub-state
extern u8 gRaceRunner[];                // per team: runner on the track (0-2), 3 = team finished
extern s32 gRaceNextSubState;           // sub-state to resume after a transition (code_08067160)
extern u8 gRaceField;                   // battlefield the race runs on (race_pick_field)
extern u8 gRaceStaticBg;                // 0: race_dispatch_substate scrolls BG3 diagonally
extern u8 gRaceFinishOrder[3];          // team + 1 that finished 1st, 2nd, 3rd (0 = not yet)
extern u8 gRaceRunnerParts[3][4][3];    // [team][head/right/left/legs][runner]: part ids for the runner sprites
extern const Func gRaceSubStates[];     // race sub-states, by gGameSubState (race_dispatch_substate)
extern u8 gRaceLegTypes[3][3];          // per team and runner: leg type - SKILL_LEGS_AIR (gRaceLegDelays column)
extern s32 gRaceStepTimers[3];          // per team: frames since the runner last moved (race_advance_runners)
extern const u8 gUnk_087B2CCC[];        // race BG tiles (LZ77, race_load_frame_bgs)
extern const u8 gUnk_087B3710[];        // race BG2 tilemap (LZ77)
extern const u8 gUnk_087B384C[];        // race BG3 tilemap (LZ77)
extern const u16 gUnk_087B3AF0[];       // race BG palette
extern const u8 gUnk_087A44F8[];        // Medal scene OBJ palettes (medal_transform_init)
extern const u32 gUnk_087A46F8[];       // Medal scene BG tiles (dma3_copy_or_decompress)
extern const u8 gUnk_087A7F98[];        // Medal scene BG1 tilemap (decompress_and_write_tilemap)
extern const u8 gUnk_087A80E8[];        // BG2 tilemap
extern const u8 gUnk_087A8324[];        // BG3 tilemap
extern const u8 gUnk_087AD4E4[];        // race OBJ tiles (LZ77, race_load_character_sprites)
extern const u8 gUnk_087C4EBC[];        // race field BG tiles (LZ77, race_load_track_screen)
extern const u8 gUnk_087C4F48[];
extern const u8 gUnk_087C4FDC[];
extern const u8 gUnk_087C51C0[];
extern const u16 gUnk_087C5248[]; // race field BG palettes
extern const u16 gUnk_087C5268[];
extern const u16 gUnk_087C5288[];
extern const u16 gUnk_087C52A8[];
extern const u8 gUnk_087C52C8[];  // race BG1 tiles (LZ77, race_load_track_status_bar)
extern const u8 gUnk_087C5518[];  // race BG1 tiles, second part (LZ77)
extern const u16 gUnk_087C55D0[]; // race BG1 palettes
extern const u16 gUnk_087C55F0[];
extern const u8 gUnk_0848417C[];   // scene text line counts by gMenuWork->cursor (text_scroll_lines)
extern u8 gRaceAnimDelay[3];       // per team: run animation frame delay (0x20 slowest, A presses lower it)
extern u8 gRaceAnimTimers[3];      // per team: frames since the run animation last stepped
extern s32 gRaceRivalTapTimers[2]; // rival teams: frames since their last simulated A press
extern s32 gRaceRivalTaps[2];      // rival teams: simulated A presses (phase into gRaceRivalPace)
extern const Func gUnk_08485C48[]; // by gGameState (dispatch_game_mode_handler)
extern const u8 gRaceRivalPace[];  // [rival * 11 + field]: phase of the rivals' tapping rhythm (race_update_speeds)
extern const struct ByteTable3
    gUnk_080AFF30;                   // 3 bytes copied to the stack, indexed by racer (race_refresh_runner_sprite)
extern u8 gRaceRunnerSlots[3][3];    // [team][runner]: sprite slot of the runner (ROM; not const, the code reloads it
                                     // after stores)
extern const u8 gRaceLegDelays[][7]; // [field][leg type]: frames per step of a runner
extern bool32 (*const gRaceSpriteMotions[])(
    u8);                  // race sprite animations, by gSpriteEntries[].unk20 - 1 (race_run_sprite_motions)
extern u8 gRaceId;        // race (gRaces index), copied from gUnk_03006D38.unk0 by race_init
extern s32 gUnk_03000000; // scene step frame counter, reset when a step finishes (execute_scene_step)
extern u8 gUnk_03000004;  // scene step, gUnk_08485C7C index
extern bool32 (*const gUnk_08485C7C[])(void); // scene steps (execute_scene_step)
extern bool32 (*const gUnk_08485C68[])(void); // transition steps (scene_transition_step_080686F4)
extern const u16 gUnk_0807C320[];    // title OBJ palettes (0x60 colours), then 0x1C bytes copied to gSceneWork + 0xC
                                     // (title_screen_load_graphics)
extern const Func gBombGameStates[]; // game mode 3 state 5 sub-states, by gGameSubState (bomb_game_dispatch)
extern const struct SpriteAnimFrame gRaceSpriteAnims[]; // sprite animation steps (race_step_sprite_anims)
extern const u8 gUnk_087B3B30[];  // game mode 3 state 5 (bomb_game_load_graphics): compressed BG tiles
extern const u8 gUnk_087B50AC[];  // compressed BG map (VRAM + 0x800)
extern const u8 gUnk_087B5214[];  // compressed BG map (VRAM + 0x1000)
extern const u8 gUnk_087B52E4[];  // compressed BG map (VRAM + 0x1800)
extern const u16 gUnk_087B551C[]; // BG palettes (0x50 colours)
extern const u8 gUnk_087AA19C[];  // compressed OBJ tiles
extern const u16 gUnk_0807C0A0[]; // OBJ palettes (0xF0 colours)
extern const s8 gHalfSineArc[];   // 64 steps of a half sine, 0..47..2: bounce / hop heights (bomb game, race)
extern const Func
    gTitleScreenStates[]; // game mode 3 state 2 (title screen) sub-states, by gGameSubState (title_screen_update)
extern s32 (*const gTitleSpriteEffects[])(u8); // title sprite effects, by gSpriteEntries[].unk20 - 1: 0 = done, 0xFF =
                                               // hide (title_screen_update_sprite_effects)
extern const u8 gTitleSpriteEffectPeriods[];   // title sprite effects: frame period, by unk20 - 1
extern const Func gUnk_08485F1C[];             // game mode 3 state 3 (story intro) sub-states, by gGameSubState
                                               // (dispatch_game_substate_handler_0806DFA4)
extern const Func
    gBootLogosSubStates[]; // game mode 3 state 0 (boot logos) sub-states, by gGameSubState (boot_logos_update)
extern const Func gIntroSubStates[];      // game mode 3 state 1 (the animated intro after the logos) sub-states, by
                                          // gGameSubState (intro_update)
extern const void *const gUnk_08486EEC[]; // story intro texts, by page gSceneWork.unkC.h (dispatch_battle_event_script)
extern const void *const gUnk_08487328[]; // story intro compressed tiles (to 0x06008000), by page
extern const void *const gUnk_08487358[]; // story intro compressed tilemaps (30x20), by page
extern const void *const gUnk_08487388[]; // story intro palettes (0xE0 halfwords), by page
extern const u8 gUnk_087F1B4C[];          // boot logo 1: compressed BG tiles (boot_logos_load_licensed_by)
extern const u8 gUnk_087F1E4C[];          // boot logo 1: compressed 30x20 tilemap
extern const u16 gUnk_087F1F38[];         // boot logo 1: palette (16 colours)
extern const u8 gUnk_087F1F58[];          // boot logo 2: compressed BG tiles (boot_logos_load_natsume)
extern const u8 gUnk_087F2658[];          // boot logo 2: compressed 30x20 tilemap
extern const u16 gUnk_087F27D8[];         // boot logo 2: palette
extern const u8 gUnk_087F27F8[];          // boot overlay: compressed BG tiles (boot_logos_load_overlay)
extern const u8 gUnk_087F3070[];          // boot overlay: compressed 30x20 tilemap (palette 1)
extern const u16 gUnk_087F3250[];         // boot overlay: palette 1
extern const u8 gUnk_087ADDDC[];          // title (title_screen_load_graphics): compressed OBJ tiles
extern const u8 gUnk_087B55BC[];          // title: compressed BG tiles
extern const u8 gUnk_087B9B6C[];          // title: BG2 tiles (0x240 bytes, uncompressed)
extern const u16 gUnk_087B9DAC[];         // title: BG palettes (0x60 colours)
extern const u8 gUnk_087B9E6C[];          // title: compressed tilemap (to 0x06006800)
extern const u8 gUnk_087BA0AC[];          // title: compressed tilemap (to 0x06007000)
extern const u8 gUnk_087BA5EC[];          // title: BG2 affine tilemap (0x280 bytes)
extern const u8 gUnk_087BA86C[];          // state 1 scene (intro_load_silhouette_scene): compressed BG tiles
extern const u16 gUnk_087BDC10[];         // 256-colour BG palette
extern const u8 gUnk_087BDE10[];          // compressed tilemap (to 0x06007000)
extern const u8 gUnk_087BE18C[];          // compressed tilemap (to 0x06007800)
extern const u8 gUnk_087BE494[];          // state 1 scene (intro_load_scan_screen): compressed BG tiles
extern const u16 gUnk_087C09C0[];         // 256-colour BG palette
extern const u8 gUnk_087C0BC0[];          // compressed tilemap (to 0x06007000)
extern const u8 gUnk_087C0E0C[];          // compressed tilemap (to 0x06007800)
extern const u8 gUnk_087C8368[];          // compressed tiles (to 0x06008020)
extern const u16 gUnk_087C8818[];         // 16-colour palette
extern const u8 gUnk_087C8838[];          // compressed 10x12 tilemap
extern const u8 gUnk_087C88F4[];          // compressed tiles (intro_load_scan_screen)
extern const u8 gUnk_087C8BD8[];
extern const u8 gUnk_087C8C94[];
extern const u8 gUnk_087C8CE4[];
extern const u16 gUnk_087C8CF4[]; // 16-colour palettes (intro_load_scan_screen)
extern const u16 gUnk_087C8D14[];
extern const u16 gUnk_087C8D34[];
extern const u8 gUnk_087C8D54[]; // compressed, decompressed to gSceneWork.unk30 (intro_load_scan_sprites)
extern const void *const gIntroSilhouetteTiles[2]; // compressed tiles ([1] to 0x06008C80, intro_load_silhouette_scene)
extern const void *const gIntroSilhouetteMaps[2];  // compressed 20x20 tilemaps ([1] in intro_load_silhouette_scene)
extern const void *const gIntroSilhouettePals[2];  // 16-colour palettes ([1] in intro_load_silhouette_scene)
extern const void *const gIntroScanObjTiles[2];    // compressed OBJ tiles (intro_load_scan_sprites)
extern const void *const gIntroObjPals[2];         // OBJ palettes (0x50 halfwords; [1] in intro_load_rokusho_sprite)
extern u8 gUnk_03000005;                           // scene step speed: frames per fade level
extern u16 gUnk_03000008[];                        // BG0 tilemap offsets of the rows the wipe steps clear / fill
extern u16 gUnk_03000028;                          // palette fade target color
extern u16 *gUnk_0300002C;                         // palette fade source palette (0x200 colors)
extern u16 gUnk_03000030[160];                     // title BG2 per-scanline values: BG2PA (title_screen_hblank, HBlank)
extern u16 gUnk_03000170[160];                     // BG2X_L per scanline
extern u16 gUnk_030002B0[160];                     // BG2X_H per scanline
extern u16 gUnk_030003F0; // title BG2 scroll counter, += 0x80 per frame (title_screen_build_wave_tables)
extern u8 gUnk_030004DE[];
extern const u8 gRandomBytes[];           // random bytes, indexed by the low byte of gFrameCounter
extern const void *const gRaceMessages[]; // referee lines of the race
extern const struct RaceInfo gRaces[];    // by gRaceId
extern const u16 gUnk_0807C260[];         // OBJ palettes (inside the 0x080750D8 data blob)
extern const u16 gUnk_0807C280[];
extern const u16 gUnk_0807C2A0[];
extern const u16 gUnk_0807C2C0[];
extern const u16 gUnk_0807C300[];
extern u8 gNameEntryMode; // 0 player name, 1 new Medal (default name), 2 rename a Medal gMedals[gCurrentMedalSlot]
extern u8 gUnk_03003870[];
extern u8 gUnk_03005664[];
extern const void *const gUnk_0847E8C4[];         // text pointers (guess)
extern const u32 *const gTextTable[];             // text pointers, banks 0-1 (guess)
extern const u32 *const *const gTextBankTables[]; // text pointer tables, bank 2+ (guess)
extern const s16 gJumpArcTable[][8];              // jump arc: [n][0] / 16 = sprite y offset at frame n (hops / jumps)
extern const u8 gUnk_083D2998[];          // map script terrain/palette id -> player_form/saved_player_form/unkC28
                                          // (map_script_update_set_player_form)
extern struct PlayerRecord gPlayerRecord; // gMoney is its first field
extern const Func gUnk_083AC248[];        // game state 0 sub-state handlers (guess: debug map viewer)
extern const Func gFieldMenuHandlers[];   // game state 1 (field pause menu) sub-state handlers
extern const void
    *const gMenuMessages[]; // menu messages: debug menu (0-3), Medals screen hints / help (4-15), pre-battle (20-21)
extern const void *const gLinkMessages[];       // message table (run_message)
extern const u8 gUnk_083AC420[];                // orbit centre x, y per gGameWork.medabotsCursor
extern const u8 gUnk_083AC432[];                // per slot sprite priority base
extern const u8 gUnk_083AC43B[];                // x, y per team select slot (9)
extern const u8 gUnk_083AC468[];                // team select: cursor slot to move to after a pick, per slot
extern const u8 gUnk_083AC44D[];                // tile x, y per team select slot (9)
extern const u8 *const gMedabotSlotDpadMoves[]; // up, down, left, right: next slot (gGameWork.medabotsCursor) per slot
extern const void *const gUnk_083B4AE0[];       // tilemaps (field menu rows: open/close animation frames)
extern const void *gBattleSpriteAnimScripts[];  // battle sprite animation command lists (battle_sprite_anim_init /
                                                // process_sprite_anim_commands)
extern const u8 gUnk_084C1608[];
extern const u8 gUnk_084C17F0[];
extern const u8 gUnk_084C1934[];
extern const u8 gUnk_084C1ACC[];
extern const u8 gUnk_084C1C14[];
extern const u8 gUnk_08487708[];
extern const u8 gUnk_08487814[];
extern const u16 gUnk_08488A84[];
extern const u8 gUnk_08488690[];
extern const u8 gUnk_08488644[];
extern const u8 gUnk_084C6A98[];
extern const u16 gUnk_084E2E38[];
extern const u8 gUnk_084C7174[];
extern const u16 gCursorArrowPalette[]; // OBJ palette 14 of the arrow cursor (gCursorArrowTiles)
extern const u16 gUnk_084E2E78[];
extern const u8 gUnk_084889F8[];
extern const void
    *const gAttributeHelpMessages[]; // messages (run_message), indexed by Medal record byte 4 (Medals help)
extern const void
    *const gSkillTypeHelpMessages[];  // messages (run_message), indexed by Medal record byte 6 (Medals help)
extern const u8 gMedalMedaforceIds[]; // 3 Medaforce ids per Medal graphic index (slots open at level 10/30/60)
extern const u8 gMedaforceRecords[];  // 6-byte Medaforce records: +1 skill type, +2 MF consumption, +5 icon
extern const void *const gMedaforceTypeHelpMessages[];  // messages (run_message), Medals help Medaforce page
extern const void *const gMedaforceSkillHelpMessages[]; // messages (run_message), Medals help page 5
extern u32 gUnk_03002B68; // bit per Medal graphic index (medal_trade_check_medal); also (part kind << 16) + part id
                          // (medapart_trade_store_part)
extern const u8 gMedalSkillBgTiles[];
extern const u8 gMedalSkillBg0Tilemap[];
extern const u8 gMedalSkillBg1Tilemap[];
extern const u8 gMedalSkillBg2Tilemap[];
extern const u8 gMedalSkillBg3Tilemap[];
extern const u16 gMedalSkillBgPalette[];
extern const Func gMedawatchMenuHandlers[]; // game state 2 (Medawatch menu) sub-state handlers
extern const u8 gUnk_084E30D8[];
extern const u8 gUnk_084EF6A0[];
extern const u8 gUnk_084F023C[];
extern const u8 gUnk_084F0F2C[];
extern const u16 gUnk_084F24E0[];
extern const u8 gUnk_084C1C24[];
extern const u8 gUnk_084C1E04[];
extern const u8 gUnk_084C1FD4[];
extern u8 gTextGlyphTile[];   // message text: the next glyph, shifted then ORed into gTextComposeTile
                              // (text_render_glyph_step)
extern u8 gTextComposeTile[]; // message text: the 8x16 tile being composed, flushed to the window tiles when full
extern u8 gUnk_02020800[];    // BG tile backup (0x800 bytes of VRAM 0x06002800 while a Medawatch submenu runs)
extern const Func gMedabotsScreenHandlers[];        // game state 3 sub-state handlers
extern const Func gMedalsScreenHandlers[];          // game state 4 (Medals screen) sub-state handlers
extern const Func gMedapartsScreenHandlers[];       // game state 5 (Medaparts screen) sub-state handlers
extern const Func gMedapartTradeChoiceCloseSteps[]; // sprite 4 sub-state handlers, by gSpriteEntries[4].unk29
                                                    // (medapart_trade_choice_close_step)
extern const Func gPrebattleScreenHandlers[];       // game state 6 ("Get ready to Robattle") sub-state handlers
extern const u8 gUnk_084C696C[];
extern const void *const gUnk_083C2BBC[]; // pre-battle opponent lines, by gBattleWork.encounterMessage
extern const u16 gUnk_084C6A78[];
extern const u8 gUnk_084E6C9C[];
extern const u8 gUnk_084C7D10[];
extern const u8 gUnk_084EFA34[];
extern const u16 gUnk_084F29E0[];
extern const u16 gUnk_084C69D8[];
extern const u16 gUnk_084C69F8[];
extern const u16 gUnk_0850DCF8[];
extern const u16 gUnk_084E2FB8[];
extern const u16 gUnk_084E2F98[];
extern u8
    gMedapartInventory[4 * 120 * 2]; // 2 bytes per Medapart, 120 per kind (head, right arm, left arm, legs): [0] count
                                     // owned (runtime-checked), [1] count equipped (team_lose_equipped_part)
// The Medaparts list shows 4 parts per page (part id = page * 4 + row); the game indexes it flat like this.
#define MEDAPART_INV(kind, page, row, byte) gMedapartInventory[(kind) * 240 + (page) * 8 + (row) * 2 + (byte)]
extern u8
    gItemInventory[64][2]; // item inventory (runtime-checked): [0] 0x80 | item id, [1] count (get_item_quantity_by_id)
extern const u8 gUnk_083B296C[]; // 4 per-phase y bob flags (update_battle_sprite_orbiting_positions)
extern const u8 gUnk_083B2970[]; // indexed by gFieldWork.player_form (resolve_area_sprite_set)
extern const u8 gUnk_083B827C[]; // 16 bytes per Medapart (part id * 64 + kind * 16), copied by load_part_data
extern const u8 gUnk_083B286C[]; // random bytes, indexed by gGameWork.rngIndex when unk89 is set (rng_next_byte)
extern const u8 gUnk_084EBF50[];
extern const u8 gUnk_084C4014[];
extern const u8 gUnk_084C4330[];
extern const u8 gUnk_084C36F0[];
extern const u8 gUnk_084EF550[];
extern const u8 gUnk_084EFF74[];
extern const u8 gUnk_084F0BF0[];
extern const u8 gUnk_084F1D34[];
extern const u8 gUnk_084ECB3C[];
extern const u8 gUnk_084C43C0[];
extern const u8 gUnk_084C47A0[];
extern const u8 gUnk_084C47E0[];
extern const u8 gUnk_084C4BAC[];
extern const u8 gUnk_084EF5A4[];
extern const u8 gUnk_084F0068[];
extern const u8 gUnk_084F0CA4[];
extern const u8 gUnk_084F1EC8[];
extern const u16 gUnk_084F3460[];
extern const u16 gUnk_084F3620[];
extern const void *const gUnk_083BE3E4[]; // messages (run_message), Medaparts detail help for head / arms, indexed by
                                          // medapart_detail_skill_help_index()
extern const void *const gUnk_083BE92C[]; // messages (run_message), Medaparts detail help for legs, indexed by
                                          // medapart_detail_skill_help_index()
extern const void *const gUnk_083B6E24[]; // messages (run_message), indexed by the part record byte unkEE
extern const void *const gUnk_083BD884[]; // messages (run_message), Medaparts help pages
extern const u8 gMedalsListBgTiles[];
extern const u8 gMedalsTabNumberTiles[]; // Medals list tab numbers 1-5 (runtime: blanking 0x06006000)
extern const u8 gUnk_0848833C[];
extern const u8 gMedalsListBg0Tilemap[];
extern const u8 gMedalsListBg1Tilemap[];
extern const u8 gMedalsListBg2Tilemap[];
extern const u8 gMedalsListBg3Tilemap[];
extern const u16 gMedalsListBgPalette[];
extern const u16 gUnk_08488B44[];
extern const u16 gUnk_084E2E98[];
extern const u8 gMedalAbilityBgTiles[];
extern const u8 gMedalAbilityBg0Tilemap[];
extern const u8 gMedalAbilityBg1Tilemap[];
extern const u8 gMedalAbilityBg2Tilemap[];
extern const u8 gMedalAbilityBg3Tilemap[];
extern const u16 gMedalAbilityBgPalette[];
extern const u8 gMedalMedaforceBgTiles[];
extern const u8 gMedaforceTypeIconTiles[]; // Medaforce page type icons next to each Medaforce (runtime)
extern const u8 gMedaforceGaugeTiles[];    // Medaforce gauge pips (MF consumption; runtime on the Medaforce page)
extern const u8 gMedalMedaforceBg0Tilemap[];
extern const u8 gMedalMedaforceBg1Tilemap[];
extern const u8 gMedalMedaforceBg2Tilemap[];
extern const u8 gMedalMedaforceBg3Tilemap[];
extern const u16 gMedalMedaforceBgPalette[];
extern const u8 gMedalRotationBgTiles[];
extern const u8 gRotationActionIconTiles[]; // Rotation page action slot icons (runtime)
extern const u8 gRotationPathTiles[];       // Rotation page arrow path under the slots (runtime)
extern const u8 gMedalRotationBg0Tilemap[];
extern const u8 gMedalRotationBg1Tilemap[];
extern const u8 gMedalRotationBg2Tilemap[];
extern const u8 gMedalRotationBg3Tilemap[];
extern const u16 gMedalRotationBgPalette[];
extern const void *const gMedaforceDescMessages[];  // messages (run_message), indexed by medal_medaforce_get_selected()
extern const void *const gRotationActionMessages[]; // messages (run_message), indexed by a Medal record byte at +0x18
                                                    // (guess: rotation entries)
extern const u8 gUnk_084E5650[];
extern const u8 gUnk_084C48B4[];
extern const u8 gUnk_084C4A34[];
extern const u8 gUnk_084C7428[];
extern const u8 gUnk_084EF2D8[];
extern const u8 gUnk_084EF95C[];
extern const u8 gUnk_084F02B8[];
extern const u8 gUnk_084F122C[];
extern const u16 gUnk_084F2680[];
extern const u16 gUnk_0850DEF8[];
extern const u16 gUnk_0850DD18[];
extern const u16 gUnk_084E2EB8[];
extern const u16 gUnk_084E2ED8[];
extern const u8 gUnk_084E61CC[];
extern const u8 gSmallDigitTiles[]; // small digits (Medal levels; runtime: blanking 0x06006280 on the Medals list)
extern const u8 gCompatibilityIconTiles[]; // Ability page compatibility icon (runtime)
extern const u8 gUnk_084C4DB0[];
extern const u8 gCursorArrowTiles[]; // arrow cursor OBJ tiles at 0x06017E00 (runtime: Medals list cursor)
extern const u8 gUnk_084EF310[];
extern const u8 gUnk_084EF9C8[];
extern const u8 gUnk_084F03EC[];
extern const u8 gUnk_084F13C0[];
extern const u16 gUnk_084F2820[];
extern const u16 gUnk_0850DD58[];

extern const u8 gMedalIconTiles[];            // Medal icon tiles, 0x80 bytes per graphic index
extern const u8 gMedalIconBlankTiles[];       // blank Medal icon tile
extern const u8 *const gMedalSpriteGfx[][5];  // compressed Medal sprites (load_medal_sprite)
extern const u32 gAttributeNames[];           // Medal Attribute names, indexed by Medal record unk4 (Ability page)
extern const u32 gSkillTypeNames[];           // skill type names (Shoot, Strike, ...): Medal Aim, Medaforce skill
extern const u8 *const gHelpCursorLayouts[];  // Medals / Medaparts help cursor layouts: count, then (x, y) tile pairs
                                              // (medals_help_init_cursor)
extern const u16 gMedalSkillDebugCursorPos[]; // (y, x) pairs per Medal skill row 0-7 (medal_skill_debug_init_cursor)
extern const Func gMedalTradeChoiceCloseSteps[]; // sprite 7 sub-state handlers, by gSpriteEntries[7].unk29
                                                 // (medal_trade_choice_close_step)
extern const Func gDebugMenuHandlers[];          // game state 63 sub-state handlers (debug_menu_update)
extern const Func gDebugMenuEntryHandlers[];     // game state 63: one handler per menu entry (debug_menu_run_entry)
extern const Func gDebugProcessHandlers[];       // game state 63 entry 0 sub-state handlers (debug_process_update)
extern const Func gDebugMedalHandlers[];         // entry 1 (debug_medal_update)
extern const Func gDebugPartsHandlers[];         // entry 2 (debug_parts_update)
extern const u8 *const gDebugMenuLabels[];    // game state 63 menu labels, 11 x 8 bytes: Process, Medal, Parts, Tinpet,
                                              // Item, Face, Mdlpic, Rnd.tk, Battle, Sound, Motion
extern const u8 *const gDebugProcessLabels[]; // game state 63 "Process" field labels "User", "Func.no", "S.func"
                                              // (gGameMode / gGameState / gGameSubState; debug_process_input)
extern const u8 *const gDebugMedalLabels[];   // game state 63 "Medal" field labels (3 x 8 bytes; debug_medal_input)
extern const u8 *const gDebugPartsLabels[];   // game state 63 "Parts" field labels (3 x 8 bytes; debug_parts_input)
extern const Func gDebugTinpetHandlers[];     // game state 63 entry 3 sub-state handlers (debug_tinpet_update)
extern const Func gDebugItemHandlers[];       // entry 4 (debug_item_update)
extern const Func gDebugFaceHandlers[];       // entry 5 (debug_face_update)
extern const Func gDebugMdlpicHandlers[];     // entry 6 (debug_mdlpic_update)
extern const Func gDebugRndTkHandlers[];      // entry 7 (debug_rndtk_update)
extern const Func gDebugBattleHandlers[];     // entry 8 (debug_battle_update)
extern const Func gDebugSoundHandlers[];      // entry 9 (debug_sound_update)
extern const Func gDebugMotionHandlers[];     // entry 10 (debug_motion_update; 4 sub-states)
extern const u8 *const gDebugTinpetLabels[];  // "Get"
extern const u8 *const gDebugItemLabels[];    // "Get", "Lost", "All"
extern const u8 *const gDebugFaceLabels[];    // "No", "Look" (also used by the Mdlpic entry)
extern const u8 *const gDebugMdlpicLabels[];  // "No", "Lv" (unused: debug_mdlpic_input reads gDebugFaceLabels)
extern const u8 *const gDebugRndTkLabels[];   // "Switch"
extern const u8 *const gDebugBattleLabels[];  // "No"
extern const u8 *const gDebugSoundLabels[];   // "Se", "Bgm"
extern const u8 *const gDebugMotionLabels[];  // "No"
extern const u8
    gMedalSkillShineTiles[];        // tiles, 5 rows of 0x100 bytes, 0x20 per Medals tab (medal_skill_load_shine_frame)
extern const u32 gMedaforceNames[]; // Medaforce names, indexed by Medaforce id
extern const u32 gUnk_083BE97C[];   // Medapart skill names for ids >= 100 (medapart_detail_draw_skill)
extern u16 gRobattleCounts[2]; // gPlayerRecord.robattleCounts: [0] fought, [1] won (gGameWork.unk9C == 1); capped at
                               // 9999 (runtime-checked; guess: Robattles fought / won)
extern const void *const gUnk_083C3984[]; // after-battle opponent lines, by gBattleWork.encounterMessage
extern const void *const gUnk_083C65C4[]; // messages (after-battle screen uses 107, 109, 118)
extern const u8 *const gPartKindNames[];  // Medapart kind names, by kind
extern const u8 gUnk_084D7C9C[];          // LZ tiles (after-battle screen sprite 1)
extern const u8 gUnk_084D7DB0[];          // LZ tiles (after-battle screen sprite 2)
extern const u16 gUnk_0850E9D8[];         // OBJ palette (sprite 1)
extern const u16 gUnk_084E2F98[];         // OBJ palette (sprite 2)

extern const u8 *const gUnk_083C3F38[]; // opponent names, by gBattleWork.encounterMessage
extern const u8 *const gUnk_083BE9E8[]; // battlefield names, by gBattleWork.battlefield
extern const u8 gUnk_083BEA90[][8];     // per area: [1] = battlefield (load_area_battlefield)
extern const u8
    gUnk_083BF090[][4]; // per area: random encounter ids, picked 40/30/20/10% (setup_random_encounter_enemies)
extern const u8 *const gUnk_083C1A00[]; // encounter setups (0x28 bytes copied to gBattleWork), by gFieldWork.battle_id
extern const u8 gUnk_083ACEE4[][2];     // per opponent Medabot: sprite position (init_opponent_medabot_sprites)
extern const u8 gUnk_083ACEEA[][2];     // per opponent Medabot: leg type icon position (draw_opponent_leg_type_icons)
extern const u8 gRandomBotSlotStarts[16]; // random starting opponent slot 0-2 (afterbattle_pick_unowned_part,
                                          // battle_pick_random_bot_part)
extern const u8 gBattlefieldParams[][8];  // per battlefield (battlefield_load_params)
extern const Func gRobattleHandlers[];    // game state 7 (Robattle) sub-state handlers
extern const void
    *const gBattlefieldGraphics[];      // 5 compressed graphics pointers per battlefield (gBattleWork.battlefield)
extern const u16 gUnk_084E2F58[];       // Robattle palette (OBJ palette 10, robattle_parts_menu_open)
extern const u16 gActionFlashPalette[]; // Robattle palette (OBJ palette 6, robattle_parts_menu_open)
extern const u16 gUnk_084E2F38[];       // Robattle palette (OBJ palette 10)
extern const u16 gUnk_084E2F78[];       // Robattle palette (OBJ palette 10)

extern const u8 gUnk_084ED4C4[];
extern const u8 gUnk_084C50D8[];
extern const u8 gUnk_084C50BC[];
extern const u8 gUnk_084EF5DC[];
extern const u8 gUnk_084F0128[];
extern const u8 gUnk_084F0D24[];
extern const u8 gUnk_084F205C[];
extern const u16 gUnk_084F37E0[];

extern const u8 gUnk_084C84E4[];
extern const u16 gUnk_084E2FD8[];

extern const u16 gUnk_0850DDF8[];

extern const u8 gUnk_08488764[]; // Robattle screen tilemaps (compressed)
extern const u8 gUnk_08488830[];
extern const u8 gUnk_08488744[];
extern const u8 gUnk_084887A4[];
extern const u8 gUnk_084887F4[];
extern const u8 *const gUnk_083C466C[]; // 12-byte name text, by gBattleWork.ringSlot (command_ring_draw_name)
extern const u8 gUnk_083AD370[]; // angles for compute_polar_to_screen_position, by sprite slot - gBattleWork.ringSlot
                                 // (command_ring_init_icon)
extern const u8
    gUnk_083AD376[]; // next slot after a right turn of the ring, by gBattleWork.ringSlot (command_ring_input)
extern const u8 gUnk_083AD37C[]; // next slot after a left turn
extern const u8 gUnk_083AD382[]; // 4-byte records: sprite count, start value, x, y (bot_pointer_line_init,
                                 // bot_pointer_line_animate)
extern const u8 gUnk_083AD3A0[]; // part select: centre sprite frame by gBattleWork.unk82 (part_select_init_center_icon)
// Part / MF menu messages: Damaged, Unusable, Used Up, Charge MF, MF low, Unmastered
extern const u8 *const gBattleMenuTexts[];
// names by part skill id (part data[1]; part_select_draw_skill_name)
extern const u32 gSkillNames[]; // skill name text pointers, by skill id (SKILL_*)
extern const u8 gUnk_084888A8[];
extern const u8 gUnk_0848895C[];
extern const u8 gUnk_084888E4[];
extern const u8 gUnk_08488920[];
extern u8 gUnk_02021000[];       // BG tile backup, second half (see gUnk_02020800)
extern const u8 gUnk_083AD39A[]; // Robattle sub-state per command ring slot (command_ring_goto_selected)
extern const u8 gUnk_083AD3A4[]; // battle bot screen positions (x, y) per record 0-5 (position_battle_team_cursors)

extern const u32 gTitleMenuBlendAlphas[];   // BLDALPHA values by fade step / 8 (title_menu_blend_step)
extern const u16 gSaveScreenSpriteFrames[]; // sprite 0 tile by (frame >> 3) & 3 (save_screen_animate_sprite)
extern const u16 gNameEntrySpriteFrames[];  // sprite 20 tile by (frame >> 3) & 3 (name_entry_animate_sprite)

extern u8 gUnk_02023078;                   // first visible list entry (update_battle_sprite_priority_flags)
extern struct Vec16 gUnk_02023200[160][4]; // per-scanline BG0-3 scroll, even frames (start_scanline_wave_scroll)
extern struct Vec16 gUnk_02023C00[160][4]; // per-scanline BG0-3 scroll, odd frames (start_scanline_wave_scroll)

extern struct Unk_03001784 gUnk_03001784;
extern const u8 gSaveMagic[17]; // save file signature (serialize_save_data, validate_save_data)
extern const u8
    gSaveMagicErased[17]; // written by save_dispatch(2) instead of gSaveMagic, so validate_save_data rejects the save

extern const void *const gUnk_08485788[]; // save screen messages
extern const void *const gUnk_08485BD8[]; // messages (save_screen_ask_overwrite uses 18)
extern const Func gSaveScreenStates[15];  // save screen states, by gGameSubState (save_screen_update): 6 stops the
                                          // music, 7 writes the save, 8 / 12 show the result

extern const u8 gUnk_0878DE10[];     // save screen BG1 tilemap (LZ77, decompress_and_write_tilemap)
extern const u8 gUnk_0878DFE0[];     // save screen BG2 tilemap
extern const u8 gUnk_0878E104[];     // save screen BG3 tilemap
extern const u32 gUnk_0878CC64[];    // save screen BG tiles (dma3_copy_or_decompress)
extern const u8 gUnk_0878A844[];     // town map graphics (town_map_load_graphics)
extern const u8 gUnk_0878A918[];     // town map graphics (town_map_load_graphics)
extern const u8 gUnk_0878AA0C[];     // town map graphics (town_map_load_graphics)
extern const u32 gUnk_087877C4[];    // town map graphics (town_map_load_graphics)
extern const u8 gUnk_087871E4[];     // town map graphics (town_map_load_graphics)
extern const u8 gUnk_080AF9A8[];     // town map graphics (town_map_load_graphics)
extern const u8 gAreaTownMapPlace[]; // town map place by area id (gFieldWork.area_id, town_map_load_graphics)
extern const u32 gUnk_087873A4[];    // town map graphics (town_map_load_graphics)
extern const u8 *gDefaultPlayerName; // -> "Ikki" (stored in the tail of gNameEntryStates), name entry mode 0
extern const u16 gUnk_080AF810[];    // name entry OBJ palette (name_entry_load_name)
extern const u16 gUnk_08793428[];    // name entry BG palettes (name_entry_load_name)
extern const u8 gUnk_08784CB0[];     // save screen BG tiles, after gUnk_0878CC64 (LZ77)
extern const u8 gUnk_08784DA4[];     // save screen OBJ tiles (LZ77)

extern const Func gTitleMenuStates[]; // state handlers by gGameSubState (title_menu_update)

extern const u8 gUnk_0878FBB4[];           // title menu BG0 tilemap (LZ77, decompress_and_write_tilemap)
extern const u8 gUnk_0878FD84[];           // title menu BG1 tilemap
extern const u8 gUnk_0878FFC8[];           // title menu BG2 tilemap
extern const u8 gUnk_08790128[];           // title menu BG3 tilemap
extern const u32 gUnk_0878E5F4[];          // title menu BG tiles (dma3_copy_or_decompress)
extern const u8 gSaveLostBg0Tilemap[];     // BG0 tilemap (LZ77, save_lost_load_graphics)
extern const u8 gSaveLostBg1Tilemap[];     // BG1 tilemap (LZ77, save_lost_load_graphics)
extern const u8 gSaveLostBg3Tilemap[];     // BG3 tilemap (LZ77, save_lost_load_graphics)
extern const u32 gSaveLostBgTiles[];       // BG tiles (dma3_copy_or_decompress, save_lost_load_graphics)
extern const u16 gSaveLostBgPalette[];     // BG palette (save_lost_load_graphics)
extern const u16 gSaveLostSpritePalette[]; // OBJ palette 0 (save_lost_load_graphics)
extern const u8 gUnk_08785F34[];           // OBJ tiles (LZ77, save_lost_load_graphics)
extern const u8 gUnk_08799838[];           // BG1 tilemap (LZ77, shop_menu_load_graphics)
extern const u8 gUnk_087999EC[];           // BG2 tilemap (LZ77, shop_menu_load_graphics)
extern const u8 gUnk_08798608[];           // BG1 tilemap (LZ77, shop_menu_load_graphics)
extern const u8 gUnk_08798824[];           // BG2 tilemap (LZ77, shop_menu_load_graphics)
extern const u8 gUnk_08798A34[];           // BG3 tilemap (LZ77, shop_menu_load_graphics)
extern const u32 gUnk_0879691C[];          // BG tiles (dma3_copy_or_decompress, shop_menu_load_graphics)
extern const u32 gUnk_08798F2C[];          // BG tiles (dma3_copy_or_decompress, shop_menu_load_graphics)
extern const u8 gUnk_087962E8[];           // BG0 tilemap (LZ77, game_over_load_graphics)
extern const u8 gUnk_08796474[];           // BG2 tilemap (LZ77, game_over_load_graphics)
extern const u8 gUnk_08796598[];           // BG3 tilemap (LZ77, game_over_load_graphics)
extern const u32 gUnk_0879579C[];          // BG tiles (dma3_copy_or_decompress, game_over_load_graphics)
extern const u16 gUnk_0879559C[];          // BG palette (game_over_load_graphics)
extern const u16 gUnk_080AF900[];          // OBJ palettes 0-1 (game_over_load_graphics)
extern const u16 gGameOverIkkiFrames[];    // sprite 1 animation frames, by unk1A / 6 (game_over_logo_drop)
extern const s8 gGameOverLogoBounce[];     // sprite 0 y offsets, 13 steps (game_over_logo_drop)
extern const u16 gUnk_0878E3F4[];          // title menu BG palette (0x100 colors)
extern u8 gOptionTimeLimit;                // picks the Robattle TIME limit: 0 = 40, 1 = 30, 2 = 20 (robattle_time_init)
extern u8 gOptionBattleMusic;              // index into gUnk_083AD3B0 (battle music)
extern const u8 gUnk_083AD3B0[];           // battle song ids (select_battle_music)
// Per leg type (skill id - 100), 11 bytes: one per battlefield (gBattleWork.battlefield); added to moveDelay
// (bot_move_delay_add_terrain).
extern const u8 gTerrainMoveDelays[];
extern const s8 gUnk_083AD3B3[]; // 32 y steps of the number pop-up over a Medabot (battle_number_popup_update)
extern const u8 gUnk_083AD3D3[]; // 32 random record orders (find_next_active_bot)
extern const u8 gUnk_083AD3F3[]; // record remap when gUnk_03000B90 is set in a link Robattle (find_next_active_bot)
extern const u8 gTargetSwapSideTable[]; // record + 1 -> same slot on the other side (bot_target_swap_side)
extern const struct GfxListEntry *const gUnk_083CE480[]; // graphics lists (decompress_indexed_graphics_to_ewram)
extern const void *const gUnk_083B2584[];                // pairs: compressed tiles [i * 2], palette [i * 2 + 1]
extern const Func gBattleMessageSteps[];                 // message steps by gBattleWork.unkA1[0] (battle_message_show)
extern const Func gMissPopupSteps[];                     // steps by gBattleWork.unk9C[0] (miss_popup_run)
extern const Func gTargetPanelSteps[];                   // steps by gBattleWork.unk9C[0] (target_panels_show)
extern const Func gTrapHitSteps[];                       // by gBattleWork.step (trap_hit_run)
extern const Func gActionPartCheckSteps[];               // by gBattleWork.step (action_part_check_run)
extern const Func gTargetPartCheckSteps[];               // by gBattleWork.step (target_part_check_run)
extern const Func gActionFlashSteps[];                   // by gBattleWork.step (action_flash_run)
extern const Func gGuardSteps[];                         // by gBattleWork.step (guard_run)
extern const Func gActionAnnounceSteps[];                // by gBattleWork.step (action_announce_run)
extern const Func gCloseupEnterSteps[];                  // by gBattleWork.step (closeup_enter_run)
extern const Func gAttackHitSteps[];                     // by gBattleWork.step (attack_hit_run)
extern const u8 gMissPopupTiles[];                       // compressed OBJ tiles (miss_popup_load)
extern const u16 gMissPopupPalette[];                    // OBJ palette (miss_popup_load)
extern const u16 gTargetLinePalette[];                   // OBJ palette 8 (target_panels_line_init)
extern const u16 gTargetArrowsPalette[];                 // OBJ palette 9 (target_panels_arrows_init)
extern const u8 gGrapTrapTiles[];                        // compressed OBJ tiles, trap_hit_load_graphics case 0
extern const u8 gShotTrapTiles[];                        // case 1
extern const u8 gAttackClrTrapTiles[];                   // case 2
extern const u8 gMedaforceTrapTiles[];                   // case 3
extern const u16 gGrapTrapPalette[];                     // OBJ palettes for the same cases
extern const u16 gShotTrapPalette[];
extern const u16 gAttackClrTrapPalette[];
extern const u16 gMedaforceTrapPalette[];
extern const u8 gBreakRingTiles[];        // compressed OBJ tiles (trap_hit_break_cursor_init)
extern const u16 gBreakRingPalette[];     // its OBJ palette (palette 7)
extern const u8 gHitSparksTiles[];        // compressed OBJ tiles (trap_hit_break_burst_init)
extern const u16 gHitSparksPalette[];     // its OBJ palette (palette 7)
extern const u8 gUnk_084C6A98[];          // compressed OBJ tiles at 0x06017400 (closeup_enter_setup_bgs)
extern const u16 gActionFlashPalette[];   // OBJ palette 6 (action_flash_load_palette)
extern const u8 gDefenceShieldTiles[];    // compressed OBJ tiles, guard_load_graphics for unkDF 0x1B
extern const u8 gFullBlockShieldTiles[];  // 0x1C
extern const u8 gHalfBlockShieldTiles[];  // 0x1D
extern const u16 gDefenceShieldPalette[]; // their OBJ palettes
extern const u16 gFullBlockShieldPalette[];
extern const u16 gHalfBlockShieldPalette[];
extern const u8
    gUnk_0848886C[]; // Robattle screen tilemap (compressed), opponent side of gUnk_08488830 (draw_bot_panel_frame)
extern u8 gOptionSkipMessages;         // Robattle: nonzero skips the message windows unless gGameWork.skipBotSetup == 1
                                       // (battle_message_open..battle_message_finish)
extern const u8 gUnk_084E3058[];       // 32-byte OBJ palette, copied to OBJ palette 6 (mf_charge_sparkles_init)
extern u32 gUnk_030018A8[16];          // cleared in two 32-byte halves by battle_action_cleanup
extern const u8 gUnk_084C4F00[];       // compressed tiles (code_0801C988)
extern const u8 gUnk_084882F4[];       // compressed tiles (code_0801C988)
extern const u8 gUnk_084C65C8[];       // compressed tiles (code_0801C988)
extern const u8 gUnk_08488B24[];       // 32-byte OBJ palette (code_0801C988)
extern const u8 gUnk_084E3098[];       // 32-byte OBJ palette (code_0801C988)
extern const u8 gUnk_084C6A58[];       // 32-byte OBJ palette (code_0801C988)
extern const u8 gCriticalHitTiles[];   // compressed OBJ tiles (battle/action_steps)
extern const u8 gCriticalHitPalette[]; // OBJ palette (battle/action_steps)
extern const u8 gDestroyMarkerTiles[]; // compressed OBJ tiles (battle/action_steps)
extern const u8 gDestroyMarkerPalette[];            // OBJ palette (battle/action_steps)
extern const u8 gHeadMarkerTiles[];                 // compressed OBJ tiles (battle/action_steps)
extern const u8 gHeadMarkerPalette[];               // OBJ palette (battle/action_steps)
extern const u8 gRightArmMarkerTiles[];             // compressed OBJ tiles (battle/action_steps)
extern const u8 gRightArmMarkerPalette[];           // OBJ palette (battle/action_steps)
extern const u8 gLeftArmMarkerTiles[];              // compressed OBJ tiles (battle/action_steps)
extern const u8 gLeftArmMarkerPalette[];            // OBJ palette (battle/action_steps)
extern const u8 gLegsMarkerTiles[];                 // compressed OBJ tiles (battle/action_steps)
extern const u8 gLegsMarkerPalette[];               // OBJ palette (battle/action_steps)
extern const u8 gDamageNumberTiles[];               // compressed OBJ tiles (battle/action_steps)
extern const u8 gDamageNumberPalette[];             // OBJ palette (battle/action_steps)
extern const u8 gPartBreakBurstTiles[];             // compressed OBJ tiles (battle/action_steps)
extern const u8 gPartBreakBurstPalette[];           // OBJ palette (battle/action_steps)
extern const u8 gCarryOverMarkerTiles[];            // compressed OBJ tiles (battle/action_steps)
extern const u8 gCarryOverMarkerPalette[];          // OBJ palette (battle/action_steps)
extern const u8 gAttackMissTiles[];                 // compressed OBJ tiles (battle/action_steps)
extern const u8 gAttackMissPalette[];               // OBJ palette (battle/action_steps)
extern const u8 gAttackNullifiedTiles[];            // compressed OBJ tiles (battle/action_steps)
extern const u8 gAttackNullifiedPalette[];          // OBJ palette (battle/action_steps)
extern const u8 gAttackAbsorbedTiles[];             // compressed OBJ tiles (battle/action_steps)
extern const u8 gAttackAbsorbedPalette[];           // OBJ palette (battle/action_steps)
extern const u8 gAbsorbSparkleTiles[];              // compressed OBJ tiles (battle/action_steps)
extern const u8 gAbsorbSparklePalette[];            // OBJ palette (battle/action_steps)
extern const u8 gHealNumberPalette[];               // OBJ palette (battle/action_steps)
extern const Func gStatusAttackSteps[];             // by gBattleWork.step (status_attack_run)
extern const u8 gStatusFlashTiles[];                // compressed OBJ tiles (battle/action_steps)
extern const u8 gStatusFlashPalette[];              // OBJ palette (battle/action_steps)
extern const u8 gBugEffectTiles[];                  // compressed OBJ tiles (battle/action_steps)
extern const u8 gBugEffectPalette[];                // OBJ palette (battle/action_steps)
extern const u8 gThunderEffectTiles[];              // compressed OBJ tiles (battle/action_steps)
extern const u8 gThunderEffectPalette[];            // OBJ palette (battle/action_steps)
extern const u8 gWaveEffectTiles[];                 // compressed OBJ tiles (battle/action_steps)
extern const u8 gWaveEffectPalette[];               // OBJ palette (battle/action_steps)
extern const u8 gFireEffectTiles[];                 // compressed OBJ tiles (battle/action_steps)
extern const u8 gFireEffectPalette[];               // OBJ palette (battle/action_steps)
extern const u8 gBugIconTiles[];                    // compressed OBJ tiles (battle/action_steps)
extern const u8 gBugIconPalette[];                  // OBJ palette (battle/action_steps)
extern const u8 gThunderIconTiles[];                // compressed OBJ tiles (battle/action_steps)
extern const u8 gThunderIconPalette[];              // OBJ palette (battle/action_steps)
extern const u8 gWaveIconTiles[];                   // compressed OBJ tiles (battle/action_steps)
extern const u8 gWaveIconPalette[];                 // OBJ palette (battle/action_steps)
extern const u8 gFireIconTiles[];                   // compressed OBJ tiles (battle/action_steps)
extern const u8 gFireIconPalette[];                 // OBJ palette (battle/action_steps)
extern const Func gCloseupExitSteps[];              // by gBattleWork.step (closeup_exit_run)
extern struct Unk_083B4AE0 gUnk_083B4AE0_s;         // same address as gUnk_083B4AE0
extern const Func gBotDefeatSteps[];                // by gBattleWork.step (bot_defeat_run)
extern const u8 gReactionRiseTiles[];               // compressed OBJ tiles (battle/action_steps)
extern const u8 gReactionRiseFxTiles[];             // compressed OBJ tiles (battle/action_steps)
extern const u8 gReactionNullifyTiles[];            // compressed OBJ tiles (battle/action_steps)
extern const u8 gReactionAbsorbTiles[];             // compressed OBJ tiles (battle/action_steps)
extern const u8 gReactionRisePalette[];             // OBJ palette (battle/action_steps)
extern const u8 gReactionRiseFxPalette[];           // OBJ palette (battle/action_steps)
extern const u8 gReactionNullifyPalette[];          // OBJ palette (battle/action_steps)
extern const u8 gReactionAbsorbPalette[];           // OBJ palette (battle/action_steps)
extern const Func gReactionSteps[];                 // by gBattleWork.step (reaction_run)
extern const Func gSacrificeSteps[];                // by gBattleWork.step (sacrifice_run)
extern const Func gDestroyCheckSteps[];             // by gBattleWork.step (destroy_check_run)
extern const Func gRecoverySteps[];                 // by gBattleWork.step (recovery_run)
extern const Func gRecoveryHealSteps[];             // by gBattleWork.step (recovery_heal_run)
extern const Func gRepairSteps[];                   // by gBattleWork.step (repair_run)
extern const Func gRepairApplySteps[];              // by gBattleWork.step (repair_apply_run)
extern const Func gTrapSteps[];                     // by gBattleWork.step (trap_run)
extern const Func gBreakFormSteps[];                // by gBattleWork.step (break_form_run)
extern const u8 gSkillCastHopTiles[];               // compressed tiles (battle skill effects)
extern const u8 gSkillCastHopPalette[];             // 32-byte OBJ palette (battle skill effects)
extern const u8 gUnk_084D513C[];                    // compressed tiles (code_080209B0)
extern const u8 gUnk_0850E678[];                    // 32-byte OBJ palette (code_080209B0)
extern const u8 gUnk_084D54BC[];                    // compressed tiles (code_080209B0)
extern const u8 gUnk_0850E698[];                    // 32-byte OBJ palette (code_080209B0)
extern const Func gStabilitySteps[];                // by gBattleWork.step (stability_run)
extern const Func gForceBindSteps[];                // by gBattleWork.step (force_bind_run)
extern const Func gDefenceSteps[];                  // by gBattleWork.step (defence_run)
extern const u8 gStabilitySparkleTiles[];           // compressed tiles (battle skill effects)
extern const u8 gStabilitySparklePalette[];         // 32-byte OBJ palette (battle skill effects)
extern const u8 gUnk_084D5788[];                    // compressed tiles (code_080209B0)
extern const u8 gUnk_0850E6D8[];                    // 32-byte OBJ palette (code_080209B0)
extern const Func gAutoRecoverSteps[];              // by gBattleWork.step (autorecover_run)
extern const u8 gUnk_084D5860[];                    // compressed tiles (code_080209B0)
extern const u8 gUnk_0850E6F8[];                    // 2 OBJ palettes (code_080209B0)
extern const Func gReactivateSteps[];               // by gBattleWork.step (reactivate_run)
extern const u8 gUnk_084D5B08[];                    // compressed tiles (code_080209B0)
extern const u8 gUnk_0850E738[];                    // 2 OBJ palettes (code_080209B0)
extern const Func gScoutSteps[];                    // by gBattleWork.step (scout_run)
extern const u8 gUnk_084D5D78[];                    // compressed tiles (code_080209B0)
extern const u8 gUnk_0850E778[];                    // 2 OBJ palettes (code_080209B0)
extern const Func gConcealSteps[];                  // by gBattleWork.step (conceal_run)
extern const u8 gConcealDomeTiles[];                // compressed tiles (battle skill effects)
extern const u8 gConcealDomePalette[];              // 32-byte OBJ palette (battle skill effects)
extern const Func gBoostChargeSteps[];              // by gBattleWork.step (boost_charge_run)
extern const u8 gChargeHourglassTiles[];            // compressed tiles (battle skill effects)
extern const u8 gChargeHourglassPalette[];          // 32-byte OBJ palette (battle skill effects)
extern const Func gRapidChargeSteps[];              // by gBattleWork.step (rapid_charge_run)
extern const u8 gUnk_084D61DC[];                    // compressed tiles (code_080209B0)
extern const u8 gUnk_0850E7F8[];                    // 32-byte OBJ palette (code_080209B0)
extern const Func gDrainChargeSteps[];              // by gBattleWork.step (drain_charge_run)
extern const u8 gUnk_084D6320[];                    // compressed tiles (code_080209B0)
extern const u8 gUnk_0850E818[];                    // 32-byte OBJ palette (code_080209B0)
extern const Func gPushoverSteps[];                 // by gBattleWork.step (pushover_run)
extern const u8 gPushoverBananaTiles[];             // compressed tiles (battle skill effects)
extern const u8 gPushoverBananaPalette[];           // 32-byte OBJ palette (battle skill effects)
extern const u8 gBurstSpriteDirections[];           // 4 bytes, sprite unk25 for slots 0x26-0x29 (pushover_burst_spawn)
extern const Func gImpairSteps[];                   // by gBattleWork.step (impair_run)
extern const u8 gImpairPortraitTiles[];             // compressed tiles (battle skill effects)
extern const u8 gImpairPortraitPalette[];           // 32-byte OBJ palette (battle skill effects)
extern const u8 gUnk_084D6780[];                    // compressed tiles (code_080249C0)
extern const u8 gUnk_0850E878[];                    // 64-byte OBJ palettes (code_080249C0)
extern const Func gConfusionSteps[];                // by gBattleWork.step (confusion_run)
extern const Func gUseDrainSteps[];                 // by gBattleWork.step (use_drain_run)
extern const u8 gUnk_084D6AAC[];                    // compressed tiles (code_080249C0)
extern const u8 gUnk_0850E8B8[];                    // 64-byte OBJ palettes (code_080249C0)
extern const u8 gBattlePopupDigitTiles[];           // compressed tiles (battle skill effects)
extern const Func gNoEscapeDefenseSteps[];          // by gBattleWork.step (no_escape_defense_run)
extern const u8 gUnk_084D6CC4[];                    // compressed tiles (code_080249C0)
extern const u8 gUnk_0850E8F8[];                    // 32-byte OBJ palette (code_080249C0)
extern const u8 gUnk_084D6E20[];                    // compressed tiles (code_080249C0)
extern const u8 gUnk_0850E918[];                    // 32-byte OBJ palette (code_080249C0)
extern const Func gForcedrainSteps[];               // by gBattleWork.step (forcedrain_run)
extern const u8 gForcedrainGlassTiles[];            // compressed tiles (battle skill effects)
extern const u8 gForcedrainGlassPalettes[];         // 32-byte OBJ palette (battle skill effects)
extern const Func gTeamAttackCheckSteps[];          // by gBattleWork.step (team_attack_check_run)
extern const Func gTeamAttackTurretSteps[];         // by gBattleWork.step (team_attack_turrets_run)
extern const Func gCounterAttackSteps[];            // by gBattleWork.step (counter_attack_run)
extern const u8 gUnk_084D71D8[];                    // compressed tiles (code_080249C0)
extern const u8 gUnk_0850E978[];                    // 32-byte OBJ palette (code_080249C0)
extern const Func gChangeSteps[];                   // by gBattleWork.step (change_run)
extern const u8 gUnk_084D7528[];                    // compressed tiles (code_080249C0)
extern const u8 gUnk_0850E998[];                    // 64-byte OBJ palettes (code_080249C0)
extern const Func gMedaforceSpiralBoltSteps[];      // by gBattleWork.step (medaforce_spiral_bolt_run)
extern const Func gMedaforceHitSteps[];             // by gBattleWork.step (medaforce_hit_run)
extern const Func gMedaforceLifeDrainHealSteps[];   // by gBattleWork.step (medaforce_life_drain_heal_run)
extern const Func gMedaforceSideBoltSteps[];        // by gBattleWork.step (medaforce_side_bolt_run)
extern const u8 gMedaforceSideBoltTiles[];          // compressed tiles (battle/medaforce_effects)
extern const u8 gMedaforceSideBoltPalette[];        // 64-byte OBJ palettes (battle/medaforce_effects)
extern const Func gMedaforceFormSteps[];            // by gBattleWork.step (medaforce_form_run)
extern const Func gMedaforceAntiAttackTrapSteps[];  // by gBattleWork.step (medaforce_anti_attack_trap_run)
extern const u8 gMedaforceFormEmblemTiles[];        // compressed tiles (battle/medaforce_effects)
extern const u8 gEffectCommonPalette[];             // 64-byte OBJ palettes shared by many skill and Medaforce effects
extern const u8 gMedaforceOpticFormTiles[];         // compressed tiles (battle/medaforce_effects)
extern const u8 gMedaforceOpticFormPalette[];       // 64-byte OBJ palettes (battle/medaforce_effects)
extern const u8 gMedaforceBombFormTiles[];          // compressed tiles (battle/medaforce_effects)
extern const u8 gMedaforceBombFormPalette[];        // 64-byte OBJ palettes (battle/medaforce_effects)
extern const u8 gMedaforceGravityFormTiles[];       // compressed tiles (battle/medaforce_effects)
extern const u8 gMedaforceGravityFormPalette[];     // 64-byte OBJ palettes (battle/medaforce_effects)
extern const Func gMedaforceCancelFormationSteps[]; // by gBattleWork.step (medaforce_cancel_formation_run)
extern const u8 gMedaforceCancelFormationTiles[];   // compressed tiles (battle/medaforce_effects)
extern const u8 gMedaforceCancelFormationPalette[]; // 64-byte OBJ palettes (battle/medaforce_effects)
extern const Func gMedaforceInflictStatusSteps[];   // by gBattleWork.step (medaforce_inflict_status_run)
extern const u8 gMedaforceMovementEmblemTiles[];    // compressed tiles (battle/medaforce_effects)
extern const u8 gMedaforceMovementEmblemPalette[];  // 64-byte OBJ palettes (battle/medaforce_effects)
extern const u8 gMedaforceStopEmblemTiles[];        // compressed tiles (battle/medaforce_effects)
extern const u8 gMedaforceStopEmblemPalette[];      // 64-byte OBJ palettes (battle/medaforce_effects)
extern const u8 gMedaforceBindEmblemTiles[];        // compressed tiles (battle/medaforce_effects)
extern const u8 gMedaforceBindEmblemPalette[];      // 64-byte OBJ palettes (battle/medaforce_effects)
extern const u8 gMedaforceFlowEmblemTiles[];        // compressed tiles (battle/medaforce_effects)
extern const u8 gMedaforceFlowEmblemPalette[];      // 64-byte OBJ palettes (battle/medaforce_effects)
extern const u8 gMedaforceChaosEmblemTiles[];       // compressed tiles (battle/medaforce_effects)
extern const u8 gMedaforceChaosEmblemPalette[];     // 64-byte OBJ palettes (battle/medaforce_effects)
extern const u16 gUnk_0850E0D8[];                   // battle graphics (battle_load_graphics_step)
extern const u8 gUnk_0850DDB8[];                    // battle graphics (battle_load_graphics_step)
extern const u16 gUnk_084C6A38[];                   // battle graphics (battle_load_graphics_step)
extern const u16 gUnk_08488AE4[];                   // battle graphics (battle_load_graphics_step)
extern const u16 gUnk_08488B04[];                   // battle graphics (battle_load_graphics_step)
extern const u16 gUnk_08488AC4[];                   // battle graphics (battle_load_graphics_step)
extern const u16 gUnk_084C6A18[];                   // battle graphics (battle_load_graphics_step)
extern const u8 gUnk_084E2C18[];                    // battle graphics (battle_load_graphics_step)
extern const u8 gUnk_084E2950[];                    // battle graphics (battle_load_graphics_step)
extern const u8 gUnk_084C7FC0[];                    // battle graphics (battle_load_graphics_step)
extern const u8 gUnk_08487D6C[];                    // battle graphics (battle_load_graphics_step)
extern const u8 gUnk_08487C94[];                    // battle graphics (battle_load_graphics_step)
extern const u8 gUnk_08487B80[];                    // battle graphics (battle_load_graphics_step)
extern const u8 gUnk_084C984C[];                    // battle graphics (battle_load_graphics_step)
extern const u8 gUnk_084C7634[];                    // battle graphics (battle_load_graphics_step)
extern const u8 gUnk_084881EC[];                    // battle graphics (battle_load_graphics_step)
extern const u8 gUnk_08488114[];                    // battle graphics (battle_load_graphics_step)
extern const u8 gUnk_0848803C[];                    // battle graphics (battle_load_graphics_step)
extern const u8 gUnk_08487F64[];                    // battle graphics (battle_load_graphics_step)
extern const u8 gUnk_08487E68[];                    // battle graphics (battle_load_graphics_step)
extern const u8 gUnk_084C5008[];                    // battle graphics (battle_load_graphics_step)
extern const u8 gUnk_08487A24[];                    // battle graphics (battle_load_graphics_step)
extern const u8 gUnk_084C5080[];                    // battle graphics (battle_load_graphics_step)
extern const u8 gUnk_084879F0[];                    // battle graphics (battle_load_graphics_step)
extern const u8 gUnk_084C4F8C[];                    // battle graphics (battle_load_graphics_step)
extern const u8 gUnk_083C4C88[][4];        // bot status sprite OAM attribute sets (battle_bot_status_sprite_update)
extern const u8 gUnk_083C4C60[][4];        // status sprite OAM attribute sets, 4 bytes each (code_08018900)
extern const u16 gUnk_083AF4C0[];          // battle cursor sprite data (staggered_sprites_spawn)
extern const u8 *const gUnk_083AFD08[][9]; // LZ assets by set and index (decompress_indexed_asset)
extern const u16 *const gUnk_083B15C8[];   // palettes by asset set (decompress_indexed_asset)
extern const u16 gTextWindowObjPalette[];  // text window OBJ palette (text_window_init)
extern const u8 gUnk_08488540[];           // LZ text window graphics (text/message)
extern const u8 gUnk_084C31BC[];           // LZ text window graphics (text/message)
extern const u8 gUnk_084873D0[];           // LZ text window graphics (text/message)
extern const u16 gUnk_0850EF58[];          // OBJ palettes (link Robattle screen, prize_game_load)
extern const u16 gUnk_084F39A0[];          // BG palettes (link Robattle screen, prize_game_load)
extern const u8 gUnk_084F21E8[];           // LZ graphics (link Robattle screen, prize_game_load)
extern const u8 gUnk_084F0D9C[];           // LZ graphics (link Robattle screen, prize_game_load)
extern const u8 gUnk_084F0194[];           // LZ graphics (link Robattle screen, prize_game_load)
extern const u8 gUnk_084EF668[];           // LZ graphics (link Robattle screen, prize_game_load)
extern const u8 gUnk_084E20F8[];           // LZ graphics (link Robattle screen, prize_game_load)
extern const u8 gUnk_084C68E0[];           // LZ graphics (link Robattle screen, prize_game_load)
extern const u8 gUnk_084C66B8[];           // LZ graphics (link Robattle screen, prize_game_load)
extern const u8 gUnk_084EDEF0[];           // LZ graphics (link Robattle screen, prize_game_load)
extern const s16 gBattleSeqWaveOffsets[];  // y offsets by sprite unk23 (0-31; battle_seq_spr_effect_wave)
extern const u8
    gBattleBg3ParallaxShift[]; // BG3 parallax shift by battlefield gBattleWork.battlefield (battle_seq_spr_actor_dash)
extern const Func gBattleSeqSpriteHandlers[]; // sprite handlers by unk29, slots 1-0x27 (battle_sequence_update_sprites)
extern const u8 *const gBattleSeqEwramGfx[];  // pairs: compressed OBJ tiles (lz_decompress to 0x02000000), OBJ palette
                                              // 14 (battle_seq_cmd_load_effect_gfx_ewram)
extern const struct Unk_083AF94C gBattleSeqEffectSetPos[]; // 4 sprite positions (battle_seq_cmd_spawn_effect_set)
extern const Func gParticleSweepHandlers[]; // sweep particle states by sprite unk29 (particle_run_sweep_handlers)
extern const u16 gParticleTrailOffsets[];   // 4 (x, y) trail offsets, x and y picked by separate rng & 3 rolls
extern const u16 gParticleSparkOffsets[];   // 4 (x, y) spark offsets from the emitter, picked by rng & 3
extern const u8 gUnk_083CED08[];            // random part ids (pick_random_change_part)
extern const u8 gUnk_083CED88[];            // random part ids (pick_random_change_part)
extern const u8 gUnk_083CEE08[];            // random part ids (pick_random_change_part)
extern const u8 gUnk_083CEE88[];            // random part ids (pick_random_change_part)
extern const u8 gUnk_083CEEC8[];            // random part ids (pick_random_change_part)
extern const u8 gUnk_083CEF08[];            // random part ids (pick_random_change_part)
extern const u8 gUnk_083CEF48[];            // random part ids (pick_random_change_part)
extern const u8 gUnk_083CEF88[];            // random part ids (pick_random_change_part)
extern const u8 gUnk_083CEFC8[];            // random part ids (pick_random_change_part)
extern const u8 gUnk_083CF008[];            // random part ids (pick_random_change_part)
extern const u8 gUnk_083CF048[];            // random part ids (pick_random_change_part)
extern const u8 gUnk_083CF088[];            // random part ids (pick_random_change_part)
extern const u8 gUnk_083CF0C8[];            // random part ids (pick_random_change_part)
extern const u8 gUnk_083CF108[];            // random part ids (pick_random_change_part)
extern const u8 gUnk_083CF148[];            // random part ids (pick_random_change_part)
extern const void *gUnk_083B6010[];         // sprite animation commands (staggered_sprites_update)
extern const u16 gUnk_083AF490[];           // x, y offset pairs per sprite of a 4-sprite group (hit_sparks_spawn)
extern const u16
    gUnk_083AF440[]; // (dx, dy) s16 pairs by sprite unk23, added to the sprite position (effect_sprite_fly_to_part)
extern const u16
    gUnk_083AF400[]; // (dx, dy) s16 pairs by sprite unk23, added to the sprite position (effect_sprite_fly_to_part)
extern const u16
    gUnk_083AF3C0[]; // (dx, dy) s16 pairs by sprite unk23, added to the sprite position (effect_sprite_fly_to_part)
extern const u16
    gUnk_083AF380[]; // (dx, dy) s16 pairs by sprite unk23, added to the sprite position (effect_sprite_fly_to_part)
extern const u16 gUnk_083AF4E0[]; // 32 y offsets added to a sprite's unk4 by sprite_bob_step
extern const u8 gUnk_083AF4A0[];  // 16 y offsets added to a sprite's unk4 by advance_sprite_anim_frame
extern const u8 gUnk_083AF4B0[];  // 16 x offsets added to / subtracted from a sprite's unk2 by sprite_slide_x_step
extern const u8 gUnk_083AF210[];  // 256 speed steps (quarter pixels) by a sprite's unk30 (sprite_move_toward_target,
                                  // update_sprite_deceleration)
extern const u16 gParticleSwayOffsets[];     // 16 x steps by a sprite's unk2D & 15 (particle_sway_down)
extern const u8 gParticleOrbitRadiusSteps[]; // orbit radius steps (+1 / -1, byte pairs) by a sprite's unk2D & 31
extern const u8 gUnk_083AF330[];             // 8 entries per bot_intact_parts_class result, one picked at random
                                             // (get_random_battle_weight_entry)
extern const u8 gUnk_084889B4[];             // compressed tilemap (armor_panel_draw_frame)
extern u8 gEffectSpriteSlot;                 // sprite slot whose handler is running (= gGameWork.runningSpriteSlot)
extern const Func
    gParticleSparkHandlers[]; // spark states by sprite unk29 (particle_run_spark_handlers, slots 0x2B-0x3B)
extern const Func gParticleOrbitHandlers[]; // orbit / trail states by sprite unk29 (particle_run_orbit_handlers)
extern const s16
    *const gBattleSeqScripts[]; // battle sequence scripts, by gBattleWork.animSkill (battle_seq_load_operands)
extern const u8 gBattleSeqOperandCounts[]; // operand count per battle sequence command (battle_seq_advance)
extern const u16
    *const gBattleSeqTileAnims[]; // x, y passed to tile_anim_init, by sprite 4 unk2B (battle_seq_cmd_bg_effect)
extern const u8 *const gBattleSeqLegSoundSets[]; // by sequence operand: 4 animation sets, by legs data[1] - 0x64 (3
                                                 // when gBattleWork.unk64[3] > 0x77; battle_seq_cmd_leg_sound)
extern const u8
    *const gBattleSeqEffectGfx[];       // pairs: compressed OBJ tiles, OBJ palette 14 (battle_seq_cmd_load_effect_gfx)
extern const Func gBattleSeqCommands[]; // battle sequence commands, by battle_seq_peek() (battle_sequence_run_command)
extern const Func gParticleShotHandlers[]; // shot states by sprite unk29 (particle_run_shot_handlers)
extern u16 gUnk_083AF480[];      // x, y offset pairs by part (effect_sprite_spawn_at_part); not const: hit_sparks_spawn
                                 // reloads it per iteration
extern const u8 gUnk_083AF200[]; // 16 values, two random picks summed into gBattleWork.dice1 / unk189
                                 // (script_op_roll_dice_damage)
extern u8 gUnk_03003470[]; // IWRAM buffer; script_op_guard_restore copies 4 x 0x40 bytes from +0xE40 + (rec * 0x100) to
                           // its start
extern const u8
    gActionScriptOperandCounts[];    // Robattle action script: operand count per command byte (battle_script_advance)
extern const u8 gSpriteHopOffsets[]; // 32 y offsets added to a sprite's unk4 by sprite_hop_step
extern const u8
    *const gActionScripts[]; // Robattle action scripts by skill id gBattleWork.actorSkill (battle_script_read_byte)
extern const Func
    gActionScriptCommands[]; // Robattle action script commands by script byte < 0x80 (battle_run_action_script; script
                             // from gActionScripts[gBattleWork.actorSkill] at offset unkBC, battle_script_read_byte)
extern const Func gAiActionChecks[];     // Robattle AI: action validity checks by part skill id data[1]; set
                                         // gBattleWork.unk51 = 1 to reject (ai_action_unusable)
extern const u8 gRandomSlots[];          // 16 slot numbers 0-2 picked by rng & 15 (rng_random_slot)
extern const Func gAiAfterPick[];        // Robattle AI: action handlers by part skill id data[1] (ai_run_after_pick)
extern const Func gAiTargetPickers[];    // Robattle AI: action selection handlers by part skill id data[1]
                                         // (ai_pick_part_target)
extern const u8 gLevelUpSkillPalettes[]; // sprite 0x22 palette bits (unkA) by the levelled-up skill type
                                         // gBattleWork.levelUpSkill (action_phase_level_up_skill_init)
extern const u8 gUnk_084D796C[];         // compressed OBJ tiles at 0x06014800 (action_phase_level_up_init)
extern u8 gLinkPartnerName[];    // = gBattleWork.partnerName: link partner's player name (link_robattle_exchange_names)
extern u8 gPlayerName[];         // gPlayerRecord.name; copied for message 2 when gGameWork.unk9C == 1
                                 // (action_phase_show_winner_message; guess: player name)
extern const u8 gUnk_084E2FF8[]; // 32-byte OBJ palette (code_0802CA5C)
extern const Func gActionPhaseSteps[];              // by gGameSubState (battle_action_state_update)
extern const u8 gMedaforceAntiProtectionTiles[];    // compressed tiles (battle/medaforce_effects)
extern const Func gMedaforceAntiProtectionSteps[];  // by gBattleWork.step (medaforce_anti_protection_run)
extern const u8 gMedaforceProtectorPalettes[];      // 32-byte OBJ palette (battle/medaforce_effects)
extern const u8 gMedaforceProtectorTiles[];         // compressed tiles (battle/medaforce_effects)
extern const Func gMedaforceProtectorSteps[];       // by gBattleWork.step (medaforce_protector_run)
extern const u8 gMedaforceLegCrashPalette[];        // 32-byte OBJ palette (battle/medaforce_effects)
extern const u8 gMedaforceLegCrashTiles[];          // compressed tiles (battle/medaforce_effects)
extern const Func gMedaforceLegCrashSteps[];        // by gBattleWork.step (medaforce_leg_crash_run)
extern const Func gMedaforceFormationOrdersSteps[]; // by gBattleWork.step (medaforce_formation_orders_run)
extern const u8 gMedaforceUpTiles[];                // compressed tiles (battle/medaforce_effects)
extern const Func gMedaforceUpSteps[];              // by gBattleWork.step (medaforce_up_run)
extern const u8 gMedaforceActivatePalette[];        // 32-byte OBJ palette (battle/medaforce_effects)
extern const u8 gMedaforceCrazyShotPalette[];       // 32-byte OBJ palette (battle/medaforce_effects)
extern const u8 gMedaforceCrazyShotTiles[];         // compressed tiles (battle/medaforce_effects)
extern const Func gMedaforceCrazySteps[];           // by gBattleWork.step (medaforce_crazy_run)
extern const u8 gDestroyerSwingFrames[];      // pairs (sprite unk25 frame or 0xFF end, wait frames) by sprite unk23
                                              // (medaforce_destroyer_swing)
extern const u8 gMedaforceDestroyerPalette[]; // 32-byte OBJ palette (battle/medaforce_effects)
extern const u8 gMedaforceDestroyerTiles[];   // compressed tiles (battle/medaforce_effects)
extern const Func gMedaforceDestroyerSteps[]; // by gBattleWork.step (medaforce_destroyer_run)
extern const u8 gMedaforceUselessPalette[];   // 32-byte OBJ palette (battle/medaforce_effects)
extern const u8 gMedaforceUselessTiles[];     // compressed tiles (battle/medaforce_effects)
extern const Func gMedaforceUselessSteps[];   // by gBattleWork.step (medaforce_useless_run)
extern const Func gMedaforcePushoverAttackSteps[];       // by gBattleWork.step (medaforce_pushover_attack_run)
extern const u8 gMedaforceChargeTiles[];                 // compressed tiles (battle/medaforce_effects)
extern const u8 gMedaforceChargePalette[];               // 32-byte OBJ palette (battle/medaforce_effects)
extern const Func gMedaforceChargeSteps[];               // by gBattleWork.step (medaforce_charge_run)
extern const Func gMedaforceHideNSeekSteps[];            // by gBattleWork.step (medaforce_hide_n_seek_run)
extern const u8 gSpyGameBeamSpinFrames[];                // frame counts (medaforce_spy_game_beam_spin)
extern const Func gMedaforceSpyGameSteps[];              // by gBattleWork.step (medaforce_spy_game_run)
extern const u8 gMedaforceUpArrowTiles[];                // compressed tiles (battle/medaforce_effects)
extern const u8 gMedaforceUpArrowPalettes[];             // 64-byte OBJ palettes (battle/medaforce_effects)
extern const Func gMedaforceLegsStatUpSteps[];           // by gBattleWork.step (medaforce_legs_stat_up_run)
extern const u8 gMedaforceAntiTerrainBoltTiles[];        // compressed tiles (battle/medaforce_effects)
extern const u8 gMedaforceAntiTerrainBoltPalettes[];     // 64-byte OBJ palettes (battle/medaforce_effects)
extern const Func gMedaforceAntiTerrainSteps[];          // by gBattleWork.step (medaforce_anti_terrain_run)
extern const u8 gMedaforceAntiTerrainBeamTiles[];        // compressed tiles (battle/medaforce_effects)
extern const u8 gMedaforceAntiTerrainBeamPalettes[];     // 64-byte OBJ palettes (battle/medaforce_effects)
extern const u8 gMedaforcePowerUpPalette[];              // 64-byte OBJ palettes (battle/medaforce_effects)
extern const u8 gMedaforcePowerUpTiles[];                // compressed tiles (battle/medaforce_effects)
extern const Func gMedaforcePowerUpSteps[];              // by gBattleWork.step (medaforce_power_up_run)
extern const u8 gMedaforceIronWallPalette[];             // 64-byte OBJ palettes (battle/medaforce_effects)
extern const u8 gMedaforceIronWallTiles[];               // compressed tiles (battle/medaforce_effects)
extern const Func gMedaforceIronWallSteps[];             // by gBattleWork.step (medaforce_iron_wall_run)
extern const u8 gMedaforceFullBodyRadPalette[];          // 64-byte OBJ palettes (battle/medaforce_effects)
extern const u8 gMedaforceFullBodyRadTiles[];            // compressed tiles (battle/medaforce_effects)
extern const Func gMedaforceFullBodyRadSteps[];          // by gBattleWork.step (medaforce_full_body_rad_run)
extern const u8 gMedaforceFullBodyUpPalette[];           // 64-byte OBJ palettes (battle/medaforce_effects)
extern const u8 gMedaforceFullBodyUpTiles[];             // compressed tiles (battle/medaforce_effects)
extern const Func gMedaforceFullBodyUpSteps[];           // by gBattleWork.step (medaforce_full_body_up_run)
extern const u8 gMedaforceFullBodyRepairPalette[];       // 64-byte OBJ palettes (battle/medaforce_effects)
extern const u8 gMedaforceFullBodyRepairTiles[];         // compressed tiles (battle/medaforce_effects)
extern const Func gMedaforceFullBodyRepairSteps[];       // by gBattleWork.step (medaforce_full_body_repair_run)
extern const u8 gMedaforceTotalRecoverySparklePalette[]; // 64-byte OBJ palettes (battle/medaforce_effects)
extern const u8 gMedaforceTotalRecoverySparkleTiles[];   // compressed tiles (battle/medaforce_effects)
extern const u8 gMedaforceTotalRecoveryPalette[];        // 64-byte OBJ palettes (battle/medaforce_effects)
extern const u8 gMedaforceTotalRecoveryTiles[];          // compressed tiles (battle/medaforce_effects)
extern const Func gMedaforceTotalRecoverySteps[];        // by gBattleWork.step (medaforce_total_recovery_run)
extern const u8 gMedaforceStatusRestorePalette[];        // 64-byte OBJ palettes (battle/medaforce_effects)
extern const u8 gMedaforceStatusRestoreTiles[];          // compressed tiles (battle/medaforce_effects)
extern const Func gMedaforceCancelStatusSteps[];         // by gBattleWork.step (medaforce_cancel_status_run)
extern const Func gMedaforceStatusRestoreSteps[];        // by gBattleWork.step (medaforce_status_restore_run)
extern const u8 gMedaforceCancelStatusSparkleTiles[];    // compressed tiles (battle/medaforce_effects)
extern const u8 gMedaforceCancelStatusSparklePalette[];  // 64-byte OBJ palettes (battle/medaforce_effects)
extern const u8 gMedaforceTargetBurstTiles[];            // compressed tiles (battle/medaforce_effects)
extern const u8 gMedaforceTargetBurstPalette[];          // 64-byte OBJ palettes (battle/medaforce_effects)
extern const Func
    gMessageEndWaitCloseSteps[]; // end mode 0 steps by gGameWork.endModeStep: portrait, window, frame, palettes, done
extern const Func gMessageEndCloseSteps[];     // end mode 1 steps (same as mode 0, no wait for A / B)
extern const Func gMessageEndWaitKeepSteps[];  // end mode 2 steps: message_close only (window stays open)
extern const Func gMessageEndWaitClearSteps[]; // end mode 3 steps: clear the text tiles, then message_close
extern const Func gMessageEndKeepSteps[];      // end mode 4 steps: message_close only, no wait
extern const u8 gLinkBattlefields[32];         // battlefields, picked at random into gBattleWork.battlefield
                                               // (link_robattle_pick_battlefield)
extern const Func
    gMessageStates[]; // run_message states by gGameWork.msgState: message_open, message_dim_palettes_step,
                      // message_show_window, ..., message_run_command (runtime-checked in 03_new_game_intro)
extern const Func gMessageEndModes[];      // end modes 0-4, by the byte after the 0xFF end code (message_run_command)
extern const u8 gPrizeGameSlotSets[16][6]; // prize rows per set, one set picked at random into gPrizeGameSlots
                                           // (prize_game_pick_slots)
extern const u8 gFontGlyphs[]; // message font, 64 bytes (two 4bpp tiles, 8x16) per character; character 0 is blank
extern u8 gPrizeGameSlots[6];  // 6 bytes from gPrizeGameSlotSets (prize_game_pick_slots); = gBattleWork.prizeSlots
extern const u8 gPrizeGameBotPicks[16]; // record index 0-2 picked at random (prize_game_pick_prize_part)
extern const u8 gAltFontWidths[][2];    // alternate font widths, used after a 0xF8 code (gGameWork.altFont)
extern const u8 gAltFontGlyphs[];       // alternate font glyphs, 64 bytes per character
extern const u8 gFontWidths[][2];       // message font: per character code, [0] width in pixels
extern const Func
    gLinkRobattleHandlers[];     // link Robattle game state: sub-state handlers by gGameSubState (link_robattle_update)
extern const u8 gUnk_08487524[]; // compressed tiles, message window frame style 3 (message_close_window_frame)
extern const u8 gUnk_084885A8[]; // compressed tilemap, message window frame style 3 (message_close_window_frame)
extern const u8 gUnk_08487630[]; // compressed tiles, message window frame style 2 (message_close_window_frame)
extern const u8 gUnk_08488600[]; // compressed tilemap, message window frame style 2 (message_close_window_frame)
extern const u8 gUnk_083C3B5C[][8];     // per battlefield, copied to gBattleWork.unk74 (load_battle_script_entry_b)
extern const Func gUnk_083B2814[];      // choice menu states by gGameWork.choiceState (poll_choice_menu)
extern const Func gUnk_083B284C[];      // by gGameWork.endModeStep (game_state_execute_handler_a)
extern const Func gUnk_083B2864[];      // by gGameWork.endModeStep (game_state_execute_handler_b)
extern const u8 *const gUnk_083B23F8[]; // 4 compressed graphics pointers per entry: tiles, BG palette, BG2 / BG3
                                        // tilemaps (decompress_tileset_to_vram)
extern const u8 gUnk_084878EC[];        // compressed tiles (decompress_bg_tilemap_to_vram)
extern const u8 gUnk_0848796C[];        // compressed tiles
extern const u8 gUnk_084886D0[];        // compressed tilemap
extern const u8 gUnk_08488718[];        // compressed tilemap
extern const u8 gUnk_083C40B8[];        // per battlefield: animation tile count / 8 (advance_battle_animation_frame)
extern const u8 gUnk_083C40C3[];        // [battlefield][0x80]: animation tile block per frame, 0xFF = loop
extern const u8
    *const gUnk_083B1888[];       // 6 compressed sprite tile pointers per Medabot (decompress_sprite_to_vram_08042D94)
extern const s16 gUnk_083D6BA0[]; // per angle 0-0xFF: cosine-like factor x256 (calc_polar_to_screen_coords x;
                                  // gJumpArcTable is the y factor)
extern const u8 gUnk_0847EB80[];  // per area id (gFieldWork.area_id), used unless song == 0xFF (area_song_id)
extern struct Unk_03005290 gUnk_03005290;
extern struct Unk_03005290 gUnk_030052B0;
extern struct Unk_03005290 gUnk_030052D0;
extern struct Unk_03005290 gUnk_030052F0;
extern const u8 gUnk_083D2ADD[]; // per animation id (gSpriteEntries[].unk30): 2 -> unkB = 0xFF, 1 -> 0, else 0x40
                                 // (sprite_set_blend_from_kind)
extern const u8 *const
    gUnk_08414394[];      // tile tables by id - 0xD0, indexed by gFieldWork.unkC38[id - 0xD0] (resolve_sprite_sheet_id)
extern u8 *gUnk_030057DC; // animated tile source for the area (animate_area_bg_tiles)
extern const u8 *const gUnk_084096F4[];  // per area id: tile animation [0] tiles per frame, [2] enabled, [3..] frame
                                         // list ending 0xFF (animate_area_bg_tiles)
extern const u16 *const gUnk_083F9BF4[]; // per area id: 0xD0-color palette for 0x0202FA00, NULL = default set from
                                         // gUnk_080AC5B4 (area_load_bg_palettes)
extern const u16 gUnk_080AC5B4[];        // default palette (area_load_bg_palettes)
extern const u16 gUnk_080AC654[];        // default palette (area_load_bg_palettes)
extern const u16 gUnk_080AC6F4[];        // default palette (area_load_bg_palettes)
extern const u16 gUnk_080AC794[];        // default palette (area_load_bg_palettes)
extern const u16 gUnk_080AC834[];        // default palette (area_load_bg_palettes)
extern const u16 gUnk_080AC8D4[];        // default palette (area_load_bg_palettes)
extern const Func gUnk_083D1F84[];       // by gGameState (field_mode_dispatch)
extern const u8
    *const gUnk_08413514[]; // per area id: tile ids, resolved through resolve_sprite_sheet_id (area_sprite_sheet_id)
extern const u8
    *const gUnk_083F80F4[];       // compressed OBJ tile sets, NULL entries fall back to 1 (area_load_sprite_sheets)
extern const u16 gUnk_085FA0E4[]; // palette copied to 0x0202F9C0 (area_load_sprite_palettes)
extern u32 gUnk_0300534C;
extern struct AffineParam gAffineParams[32];
extern struct BattleEntity3D *gUnk_03006D30;
extern const s32 *const
    *const gUnk_083D2DB0[]; // per model set, per entity: s32 count, x[4], y[4], z[4] (field_effect_project_objects)
extern const float gUnk_083D6EA0[256]; // guess: sine, angle 0-255 (set_state_float_field)
extern const float gUnk_083D72A0[256]; // guess: cosine
extern const Func gItemMenuStates[];   // field menu Item screen states, by gGameSubState (item_menu_update)
extern const Func gNameEntryStates[];  // 7 name entry sub-states, by gGameSubState (name_entry_screen_update)
extern const u8
    *const gItemDescriptions[];  // item description messages by item id (runtime: item 1 Skirt -> "Transform Goods No.1
                                 // / A frilly mini-skirt."); 0x3F with an empty list (item_menu_show_description)
extern const u8 gUnk_080AF755[]; // 0x53-byte message copied to the stack (load_rotation_grid_and_advance)
extern const Func gMenuModeStates[]; // by gGameState (menu_mode_update)
extern const u8 gUnk_080AF6EC[];     // 4 bytes copied to an unused local (init_multiplayer_id)
extern const u8 gUnk_080AF5FC[];     // per gFieldWork.unkC32: 10 x 4 next-entry bytes (right, left, up, down) by
                                     // gMenuWork->town_map_place (town_map_move_cursor)
extern const u8 gUnk_080AF674[];     // same, used when gMenuWork->cursor_style is set (town_map_move_cursor)
extern const u8 gUnk_083BEA14[];     // per Medabot (gUnk_083B1888 index): sprite palette - 4 (load_battle_sprite_tiles)
extern const u16 gTitleOptionValueMasks[3][3]; // 3 x 3 tile masks (bit 15 first) of the title option rows
                                               // (title_options_draw_values)
extern const u8 gUnk_0878C484[];               // field menu item list BG1 tilemap (LZ77, item_menu_load_graphics)
extern const u8 gUnk_0878C5B4[];               // field menu item list BG2 tilemap (LZ77, item_menu_load_graphics)
extern const u8 gUnk_0878C750[];               // field menu item list BG3 tilemap (LZ77, item_menu_load_graphics)
extern const u32 gUnk_0878B078[];   // field menu item list BG tiles (dma3_copy_or_decompress, item_menu_load_graphics)
extern const u16 gUnk_080AF7C0[16]; // OBJ palette 14 of the field menu item list (item_menu_init)
extern const u16 gUnk_0878AE78[0x100]; // BG palettes of the field menu item list (item_menu_init)
// code_0805EE6C
extern const u8 gSaveLostSpriteFrames[8];      // sprite 0 frame offsets (save_lost_animate_sprite)
extern const u8 gShopkeeperPortraitSets[];     // 0xFB portrait set by gShopId (shop_copy_text_with_portrait)
extern u8 gShopId;                             // Medaparts shop id: stock row in gShopStock, shopkeeper portrait
extern const Func gTownMapStates[];            // sub-state handlers (town_map_dispatch)
extern const Func gGameOverStates[];           // sub-state handlers (game_over_update)
extern const Func gSaveLostStates[];           // sub-state handlers (save_lost_dispatch)
extern const Func gTestModeStates[];           // sub-state handlers (test_mode_dispatch)
extern const Func gUnk_08483E8C[];             // sub-state handlers (shop_list_dispatch)
extern const void *const gTownMapPlaceNames[]; // messages by gMenuWork->town_map_place (town_map_show_place_name)
extern const u8 gShopSellPartTypeText[];       // message text (shop_menu_part_type_prompt, gMenuWork->cursor set)
extern const u8 gShopBuyPartTypeText[];        // message text (shop_menu_part_type_prompt, gMenuWork->cursor clear)
extern const u8 gTownMapPlacePositions[][2];   // x, y in tiles by gMenuWork->town_map_place (town_map_update_cursor)
extern const u16 gUnk_08483DD4[][4];           // x offsets [unk18][frame]
extern const u16 gUnk_08483DE4[][4];           // y offsets [unk18][frame]
extern const u16 gUnk_08483DF4[][4];           // animation frames [unk18][frame]
extern const u8 gUnk_08483E04[];               // frame index by gMenuWork->frame / 10 (town_map_animate_tiles)
extern const u8 gShopGreetingText[];           // message text (shop_menu_greeting)
extern const Func gShopMenuStates[];           // sub-state handlers (shop_menu_dispatch)
extern const u16 gGameOverIkkiFramesExit[];    // sprite 1 animation frames by unk1A / 6 (game_over_wipe_out)
extern u8 gTitleSkipIntro;
extern const u8 gUnk_080AFA3C[][4][2];      // x, y by [which][kind] (load_medapart_sprite_animation)
extern const u16 gUnk_08488AA4[];           // OBJ palette 1 (shop_menu_show_layers)
extern const u16 gUnk_0879671C[];           // BG palettes (shop_menu_show_layers)
extern const u8 gShopPartTypeIconPos[4][2]; // icon x, y in BG2 tiles (shop_highlight_part_type_icon)
// A function table that the code copies to the stack before indexing it (agbcc emits ldm / stm for
// the struct copy), like a local initialized array whose initializer lives in ROM.
struct FuncTable7 {
    Func f[7];
};
extern const struct FuncTable7 gUnk_080AFA20; // sub-state handlers by gGameSubState (dispatch_substate_handler)
extern const struct FuncTable7 gUnk_080AFEA8; // sub-state handlers by gGameSubState (text_scroll_update)
struct TextBufTable4 {
    u8 *p[4];
};
extern const struct ObjAffineDstData gUnk_080ABBEC; // identity affine matrix (render_sprite_if_visible_rotated)
extern const struct ObjAffineDstData gUnk_080ABBF4; // affine matrix template (render_sprite_node_recursive)
extern const u8 gUnk_08081320[]; // mirrored sprite node index per node (render_sprite_node_recursive)
extern const struct TextBufTable4
    gUnk_080ABBFC;               // the 4 text buffers 0x030004DE + 0x14 * n (copy_string_to_text_buffer)
extern const u8 gUnk_080AFE96[]; // first tilemap column by gMenuWork->cursor (text_scroll_shift_row)
struct U16PtrArray8 {
    const u16 *v[8];
};
extern const u8 gUnk_080AFEE0[8];               // guess: tile block widths by type (race_draw_tile_block)
extern const u8 gUnk_080AFEE8[8];               // guess: tile block heights by type (race_draw_tile_block)
extern const u16 gUnk_080AFEF0[8];              // first tile by type (race_draw_tile_block)
extern const struct U16PtrArray8 gUnk_080AFF00; // tile index lists by type (race_draw_tile_block)
extern const u16 gUnk_080AFF20[8];              // palette bits by type (race_draw_tile_block)
extern const u8 gUnk_087A3CFC[];                // race scene BG0 tilemap (decompress_and_write_tilemap)
extern const u8 gUnk_087A3E64[];                // race scene BG2 tilemap (decompress_and_write_tilemap)
extern const u8 gUnk_087A40A0[];                // race scene BG3 tilemap (decompress_and_write_tilemap)
extern const u32 gUnk_087A1410[];               // race scene BG tiles (dma3_copy_or_decompress)
extern const u8 gUnk_087A13B0[];                // race scene BG palettes (0x60 bytes to 0x0202FA00)
extern const u8 gUnk_0850DEB8[];                // OBJ palette (0x20 bytes to 0x05000200)
struct PtrTable3 {
    const u8 *const *p[3];
};
extern const struct PtrTable3 gUnk_080AFE9C; // scene texts by gMenuWork->cursor (text_scroll_page_start)
extern const u16 gUnk_080AFA4C[16];          // OBJ palette for the link Medapart trade scene (medapart_trade_fade_in)
struct FuncTable13 {
    Func f[13];
};
extern const struct FuncTable13
    gUnk_080AFA6C;                  // link Medapart trade sub-states by gGameSubState (medapart_trade_update)
extern const s16 gSineTable[0x140]; // sin(i * 2pi / 256) * 0x100, 256 + 64 entries (cos(x) = [x + 0x40])
extern const s8 gUnk_080AFB45[];    // game mode by gMenuWork->cursor (link_menu_fade_out_exit)
extern const struct FuncTable13
    gUnk_080AFB48;                // link menu sub-states by gGameSubState (dispatch_battle_menu_and_update_counters)
extern const u8 gUnk_0848564F[];  // 0xFF-terminated message (setup_dialogue_script_from_rom)
extern const u8 gUnk_0879C06C[];  // graphics (clear_vram_bg)
extern const u8 gUnk_0879A634[];  // Medal list BG1 tilemap (medal_rename_load_graphics)
extern const u8 gUnk_0879A78C[];  // Medal list BG2 tilemap (medal_rename_load_graphics)
extern const u8 gUnk_0879A8BC[];  // Medal list BG3 tilemap (medal_rename_load_graphics)
extern const u32 gUnk_08799D98[]; // Medal list BG tiles, compressed (medal_rename_load_graphics)
extern const u8 gUnk_0879FDC0[];  // BG1 tilemap (medal_trade_init_screen)
extern const u8 gUnk_0879FB10[];  // BG2 tilemap (medal_trade_init_screen)
extern const u8 gUnk_087A0050[];  // BG3 tilemap (medal_trade_init_screen)
extern const u8 gUnk_0879FEFC[];  // BG2 tilemap, second (medal_trade_init_screen)
extern const u32 gUnk_0879E618[]; // BG tiles, compressed (medal_trade_init_screen)
extern const u16 gUnk_0879E4D8[]; // BG palettes (medal_trade_init_screen)
extern const u8 gUnk_0879C260[];
extern const u8 gUnk_0879C3A0[];
extern const u32 gUnk_0879AC40[];
extern const u16 gUnk_0879AA40[];
extern const u16 gUnk_08483AA0[]; // medal_rename_load_palettes
extern const u16 gUnk_08799B98[];
extern const u16 gUnk_080AFAE8[];
extern const u8 gUnk_080AFB08[]; // message indices (battle_cutscene_dispatch)
extern const u8 gUnk_080AFB0B[];
extern const u8 gUnk_080AFB30[];  // message (handle_battle_menu_selection)
extern const u8 gUnk_080AFB3F[];  // message index per cursor position (handle_battle_menu_selection)
extern const u32 gUnk_087A88CC[]; // graphics (scroll_banner_init)
extern const u8 gUnk_087A1084[];
extern const u32 gUnk_087A92D4[];
extern const u32 gUnk_087A046C[];
extern const u16 gUnk_087A034C[];
struct FuncTable2 {
    Func f[2];
};
struct FuncTable4 {
    Func f[4];
};
struct FuncTable6 {
    Func f[6];
};
struct FuncTable12 {
    Func f[12];
};
extern const struct FuncTable12 gUnk_080AFAA0; // link Medal exchange sub-states by gGameSubState (medal_trade_update)
extern const struct FuncTable4 gUnk_080AFAD0;  // sub-states by gGameSubState (scene_dispatch_and_tick)
extern const struct FuncTable2 gUnk_080AFAE0;  // sub-states by gGameSubState (link_medal_sync_update)
struct FuncTable8 {
    Func f[8];
};
extern const struct FuncTable8 gUnk_080AFB10; // sub-state handlers by gGameSubState (dispatch_battle_cutscene_substate)
extern const Func gMedalRenameStates[];       // Medal list screen sub-states (medal_rename_main)
extern const struct FuncTable7 gUnk_080AFEC4; // sub-state handlers by gGameSubState (medal_transform_update)
struct S32Array3 {
    s32 v[3];
};
extern const struct S32Array3
    gBombGameDebrisTimes;              // {0x50, 0x40, 0x20}: bomb minigame debris intervals (bomb_game_player_blown_up)
extern const u8 gBombGameBannerEva[8]; // bomb minigame BLDALPHA EVA steps (bomb_game_animate_round_banner)
extern const u8 gBombGameBannerEvb[8]; // bomb minigame BLDALPHA EVB steps (bomb_game_animate_round_banner)
extern const u8 gUnk_087C11C4[];
extern const u8 gUnk_087C2598[];
extern const u8 gUnk_087C3928[];
extern const u8 gUnk_087C3AF4[];
extern const u8 gUnk_087C3D40[];
extern const u8 gUnk_087C40B0[];
extern const u8 gUnk_087C4210[];
extern const u8 gUnk_087C4498[];
extern const u8 gUnk_087B1CEC[];
extern const u8 gUnk_087C481C[];
extern const u8 gUnk_087C4C5C[];
extern const u8 gUnk_085E3AC8[];
extern const u8 gUnk_085E32C0[];
extern const u8 gUnk_085E1A0C[];
extern const u8 gUnk_085E0A58[];
extern const u16 gUnk_085E3AA8[];
extern const u16 gUnk_085E32A0[];
extern const u16 gUnk_085E19EC[];
extern const u16 gUnk_085E0A38[];
extern const u16 gUnk_0807C540[]; // 16-colour palettes (same table as weekly_show_lecture)
extern const u16 gUnk_087C4DFC[];
extern const u8 gUnk_087C8E00[];  // LZ77 BG tiles (intro_load_art_unused)
extern const u8 gUnk_087CC7BC[];  // LZ77 30x20 tilemap (intro_load_art_unused)
extern const u16 gUnk_087CCAEC[]; // BG palette, 256 colours (intro_load_art_unused)
extern const u8 gUnk_087CCCEC[];  // LZ77 BG tiles (intro_load_versus_art)
extern const u8 gUnk_087D0954[];  // LZ77 30x20 tilemap (intro_load_versus_art)
extern const u16 gUnk_087D0C80[]; // BG palette, 256 colours (intro_load_versus_art)
extern const u8 gUnk_087D0E80[];  // LZ77 BG tiles (intro_load_closeup_art)
extern const u8 gUnk_087D424C[];  // LZ77 30x20 tilemap (intro_load_closeup_art)
extern const u16 gUnk_087D4564[]; // BG palette, 256 colours (intro_load_closeup_art)
extern s32 (*const gIntroSpriteActions[])(
    u8); // sprite actions, by gSpriteEntries[].unk20 - 1: 0 = done, 0xFF = clear (intro_update_sprite_actions)
extern const u8 gIntroSpriteActionPeriods[]; // sprite actions: frame period, by unk20 - 1
extern const s8 gIntroBobOffsets[]; // 64-entry wave offsets, by gSpriteEntries[].unk21 & 0x3F (intro_action_bob)
extern u8 gWeeklyAnimTiles[];       // animated BG tiles: 6 frames of 0x280 bytes, 0x100 copied (weekly_update_studio)
extern u8 gWeeklyAnimTiles2[];      // animated BG tiles: 6 frames of 0x280 bytes, 0x180 copied (weekly_update_studio)
extern u8 gWeeklyCycleAnimMask;
extern const Func
    gMedabotsWeeklySubStates[]; // sub-states by gGameSubState (medabots_weekly_update); [0] = medabots_weekly_init
extern s32 (*const gWeeklySpriteEffects[])(u8);
extern const s8 gWeeklyCurtainOpenTimes[8];
extern const void *const gWeeklyMessages[];
extern const u8 gUnk_08486114[];
extern const u8 gIntroPointerLines[]; // 12 bytes per scan part, from +0x30: 3 lines (lineIdx) of x, y, end x, end row
extern const u8 *const
    gIntroScanStrings[]; // intro scan screen strings; [part + 4] are the part names typed by intro_type_part_name
extern const s8 gWeeklyCurtainCloseTimes[12]; // 12 frame counts (unk1A values) at which weekly_fx_right_curtain_close /
                                              // weekly_fx_left_curtain_close step
extern const u8 gCycleAnimFrameOffsets[];     // sprite_cycle_anim_update table
extern u16
    *gWeeklyFlashPalette; // palette the fade in weekly_lecture_flash reads from (set to gPaletteBackupBg = 0x0202FA00)
extern const u8 gWeeklyLectureSfxScript[13]; // weekly_lecture_run_pose script: pairs (0, n) = wait n frames, (1, id) =
                                             // play_sound_effect(id)
extern u32 (*const gWeeklyLectureSteps[])(
    void); // Medabots Lecture steps by gSceneWork.unk10.lecture.state (weekly_lecture_run_step); 1 = done
extern const struct SpriteAnimCmd *const gSpriteAnimScripts[];
extern const struct SpriteAnimGfx gSpriteAnimGfx[];
extern const u8 gUnk_08764CB0[];
extern const Func gFieldSubStates[];
extern const void *const gRoomExitMessages[];
extern const u8 *gUnk_03005590;
extern const void *const gUnk_083F8CF4[];
extern const void *const gUnk_083F8FF4[];
extern const u8 gUnk_080AC5D4[];
extern const u8 gUnk_080AC674[];
extern const u8 gUnk_080AC714[];
extern const u8 gUnk_080AC7B4[];
extern const u8 gUnk_080AC854[];
extern const u8 gUnk_080AC8F4[];
extern const u8 gUnk_083D29EB[];
extern const u8 gVehicleMenuCursorRows[];
extern const u8 gUnk_085FA144[];
extern const u8 gUnk_085FA5D8[];
extern const u16 gUnk_085FA4D8[];
extern const u16 gUnk_085FA620[];
extern const u16 gVehicleMenuWindowTilemap[];
extern const u8 gUnk_085FA660[];
extern const u8 gUnk_085FA87C[];
extern const u8 gUnk_085FAA98[];
extern const u8 gUnk_085FA6E8[];
extern const u8 gUnk_085FA904[];
extern const u8 gUnk_085FA774[];
extern const u8 gUnk_085FA990[];
extern const u8 gUnk_085FA7FC[];
extern const u8 gUnk_085FAA18[];
extern const u16 gUnk_085FA640[];
extern const u16 gUnk_085FA85C[];
extern u16 *gFieldDebugEventValues[];
extern u16 *gFieldDebugMessageValues[];
extern u8 **gFieldDebugPageValues[];
extern const u8 gUnk_083D2C3D[];
// Field debug screen labels: NUL-terminated ASCII, drawn glyph by glyph from gFieldDebugFont
extern const u8 gFieldDebugLabelMd[];
extern const u8 gFieldDebugLabelMp[];
extern const u8 gFieldDebugLabelMn[];
extern const u8 gFieldDebugLabelPt[];
extern const u8 gFieldDebugLabelNor[];
extern const u8 gFieldDebugLabelCar[];
extern const u8 gFieldDebugLabelSen[];
extern const u8 gFieldDebugLabelSka[];
extern const u8 gFieldDebugLabelKim[];
extern const u8 gFieldDebugLabelYus[];
extern const u8 gFieldDebugLabelRob[];
extern const u8 gFieldDebugLabelBan[];
extern const u8 gFieldDebugLabelDor[];
extern const u8 gFieldDebugLabelObo[];
extern const u8 gFieldDebugLabelMef[];
extern const u8 gFieldDebugLabelKaz[];
extern const u8 gFieldDebugLabelGin[];
extern const u8 gFieldDebugLabelDog[];
extern const u8 gFieldDebugLabelKok[];
extern const u8 gFieldDebugLabelJet[];
extern const u8 gFieldDebugLabelMf[];
extern const u8 gFieldDebugLabelEf[];
extern const u8 gFieldDebugLabelEe[];
extern const u8 gFieldDebugLabelTe[];
extern const u8 gFieldDebugLabelEx[];
extern const u8 gFieldDebugLabelSt[];
extern const u8 gFieldDebugLabelCm[];
extern const u8 gFieldDebugLabelEvent[];
extern const u8 gFieldDebugLabelEno[];
extern const u8 gFieldDebugLabelFlg[];
extern const u8 gFieldDebugLabelX[];
extern const u8 gFieldDebugLabelLv[];
extern const u8 gFieldDebugLabelPlayer[];
extern const u8 gFieldDebugLabelPlx[];
extern const u8 gFieldDebugLabelPly[];
extern const u8 gFieldDebugLabelMapEffect[];
extern const u8 gFieldDebugLabelMen[];
extern const u8 gFieldDebugLabelKwg[];
extern const u8 gFieldDebugLabelDc[];
extern const u8 gFieldDebugLabelMl[];
extern const u8 gFieldDebugLabelBt[];
extern const u8 gFieldDebugLabelR[];
extern const u8 gFieldDebugLabelBlank[];
extern const u8 gFieldDebugLabelE[];
extern const u8 gFieldDebugLabelSk[];
extern const u8 gFieldDebugLabelSp[];
extern const u8 gFieldDebugLabelWl[];
extern const u8 gFieldDebugLabelN[];
extern const u8 gFieldDebugLabelW[];
extern const u8 gFieldDebugLabelL[];
extern const u8 gFieldDebugLabelKoma[];
extern const u8 gFieldDebugLabelKno[];
extern const u8 gFieldDebugLabelMess[];
extern const u8 gFieldDebugLabelMsb[];
extern const u8 gFieldDebugLabelMsn[];
extern const u8 gFieldDebugLabelMsf[];
extern const u8 gFieldDebugLabelMax[];
extern const u8 gFieldDebugLabelAr[];
extern const u8 gFieldDebugLabelKa[];
extern const u8 gFieldDebugLabelBgm[];
extern const u8 gFieldDebugLabelSe[];
extern const u8 gFieldDebugLabelPnt[];
extern u8 *gFieldDebugSoundValues[];
extern const Func gVehicleMenuStates[];
extern const u8 gFieldDebugFont[];
extern const u8 gFieldDebugHexDigits[];

// code_0805AB40 (session 91)
extern const struct FuncTable6
    gUnk_080AF7A8; // sub-states by gGameSubState (dispatch_rotation_menu_substate; guess: title options screen)
extern const u8 gItemUsable[];             // per item id: 1 if usable from the item menu (town map 0 and the disguises)
extern const u8 gBattleMusicOptionSongs[]; // song per battle music option (title_options_input preview)
extern const u16 gUnk_0878CA64[];
extern const u16 gUnk_080AF7E8[];

// code_0805EE6C (session 94)
extern const u8 gSoundTestSongs[];
extern const u8 gSoundTestEffects[];
extern const u16 gUnk_084C69B8[];
extern const u16 gUnk_08798D2C[];
extern const u8 gUnk_08791694[];
extern const u8 gUnk_087917F4[];
extern const u8 gUnk_087919C4[];
extern const u32 gUnk_08790600[];
extern const u16 gUnk_08790400[];
extern const u16 gUnk_083C6DF8[]; // per-step (x, y) offsets for update_sprite_animation_position
extern const u8 gUnk_0879DDCC[];
extern const u8 gUnk_0879DF44[];
extern const u8 gUnk_0879E1DC[];
extern const u32 gUnk_0879C89C[];
extern const u8 gUnk_0879C69C[];
extern const u8 gUnk_0850DD78[];

extern s32 *gUnk_083D5D84[];        // field effect scripts, picked by gUnk_03005350.unk1D4 & 0x3F (field_effect_run)
extern const void *gUnk_0847ECC0[]; // battle sequence sprite graphics (opcode 27)
extern const void *gUnk_0847EC40[]; // battle sequence sprite palettes (opcode 27)
extern const u8 gUnk_083D2AAB[];
extern const u8 gUnk_083D2AB4[];
extern const u8 gUnk_083D2AD8;
extern const u8 gUnk_083D2AD9[];
extern u32 gUnk_0807E77C[][7];
extern u8 gUnk_083CABF8[];
extern u8 *gUnk_083D1E98[];
extern s16 *gUnk_083D1CC0[];
extern s8 *gUnk_083D1DAC[];
extern const u8 gUnk_08794E6C[]; // name entry screen tilemaps (name_entry_init_graphics)
extern const u8 gUnk_0879514C[];
extern const u8 gUnk_08795418[];
extern const u32 gUnk_08793628[]; // name entry screen tiles
extern const u8 gUnk_080AF850[];  // name entry: bottom-row button column -> letter-row column

extern u8 gUnk_03000438; // bit 0: skip one OAM rebuild, bit 1: don't sort sprites
extern s32 gUnk_03005040;
extern s32 gUnk_03005044;
extern s32 gUnk_0300504C;
extern struct Vec16 gUnk_03002C24; // sprite camera position
extern struct Vec16 gUnk_03001794;
extern struct SpriteFrame *const *const gUnk_083ABE30[];
extern struct SpriteFrame *const *const gUnk_083AC088[];
extern struct SpriteFrame *const *const gUnk_083AC0C8[];
extern struct SpriteFrame *const *const gUnk_083AC108[];
extern const struct MapNpcRecord *const gUnk_084837A0[];
extern u8 gUnk_02023000[];    // shop cart: quantity per sell-list entry; [0x78] = first visible entry
extern const u8 gShopStock[]; // 4 Medapart ids per shop (gShopId * 4 + i); 0xFF ends
extern u16 gUnk_03006432;     // guess: battle field grid origin x (field_debug_draw_sprite_preview)
extern u16 gUnk_03006434;     // guess: battle field grid origin y

#endif // GUARD_VARIABLES_H
