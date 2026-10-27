#ifndef GUARD_VARIABLES_H
#define GUARD_VARIABLES_H

// RAM variables and ROM data. Addresses are in symbols.ld.

typedef void (*Func)(void);

// RAM
extern struct Unk_03000440 gUnk_03000440;
extern struct Unk_03000590 gUnk_03000590[];
extern u8 gUnk_03000890[];
extern u8 gUnk_03000B90; // guess: link player id (0/1)
extern struct Unk_03000BE0 gUnk_03000BE0[];
extern u32 gFrameCounter;
extern u32 gGameMode;
extern struct Unk_030017A0 gUnk_030017A0[];
extern struct Unk_03001800 gUnk_03001800;
extern struct Unk_03001800_s gUnk_03001800_s;       // same address as gUnk_03001800 (game mode 3 scenes)
extern struct Unk_03001800_bomb gUnk_03001800_bomb; // same address as gUnk_03001800 (game mode 3 state 5)
// A view through gUnk_03001800 itself: the scene init also clears that block, and the literal pool shares one address.
#define gMedabotsWeekly (*(struct MedabotsWeeklyWork *)&gUnk_03001800)
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
extern struct Unk_030057A0 gUnk_030057A0;
extern u8 *gMapScriptData; // current map script data (banked, see read_map_script_byte)
extern struct Unk_030057E0 gUnk_030057E0;
extern struct Unk_030064A0 gUnk_030064A0;
extern struct Unk_03006D20 gUnk_03006D20;
extern struct Unk_03007014 *gUnk_03007014;
extern struct Unk_03007014 gUnk_03002430; // sound work area (soft_reset_to_title passes it to sound_init)
extern struct Vec16 gBg1Scroll;           // BG1 scroll (field: map camera)
extern struct Unk_03005310 gUnk_03005310;
extern struct BlendEffectState gBlendEffect;
extern struct Unk_03006F74 *gUnk_03006F74;
extern struct Unk_030055A0 gUnk_030055A0[];
extern struct Vec16 gBg2Scroll; // BG2 scroll
extern struct Vec16 gBg3Scroll; // BG3 scroll
extern u8 *gUnk_030057D8;       // two 4-bit entries per byte (bit 3 / bit 7: flag, bits 0-2 / 4-6: count)
extern u16 *gUnk_03006D14;
extern struct Unk_03006D38 gUnk_03006D38;
extern u8 gUnk_03003810;
extern struct Unk_03005010 gUnk_03005010;
extern s8 gUnk_03005030;               // multiplayer link active (soft_reset)
extern vu16 gUnk_03002B90;             // bit 0: vblank handler running
extern s8 gUnk_03002410;               // frames since the main loop last ran (vblank_irq)
extern Func gIntrTable[14];            // RAM copy of gIntrTableTemplate, used by irq_dispatch_arm
extern u32 gIntrMain[0x200];           // RAM copy of irq_dispatch_arm (the IRQ vector)
extern Func gVBlankCallback;           // called every vblank
extern Func gVBlankOnceCallback;       // called at the next vblank, then reset to nullsub_08000840
extern Func gHBlankCallback;           // called by hblank_irq
extern struct OamData gOamBuffer[128]; // copied to OAM in vblank_body
extern struct SpriteWork *gSpriteWork;
extern struct SceneSlot *gUnk_03005308;
extern u32 gUnk_03000430;           // vblank_body OAM mode (0, 2)
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
extern const struct Unk_03005290 gUnk_0807ECB8; // (setup_scene_bg_layers_and_sprites)
extern const struct Unk_03005290 gUnk_0807ECD0;
extern const struct Unk_03005290 gUnk_0807ECE8;
// Sprite tree node lists by part id: head, right arm, left arm, legs (non-const: needed to match)
extern struct SpriteTileRef gUnk_0807ED00[][4];
extern struct SpriteTileRef gUnk_0807F4A0[][4];
extern struct SpriteTileRef gUnk_0807FC40[][4];
extern struct SpriteTileRef gUnk_080803E0[][8];
extern struct SoundSongHeader *gUnk_080AFFB8[]; // song table (sound_init)
extern struct SoundSongHeader *gUnk_080B06EC[]; // sound effect table (sound_init)
extern struct SoundNoteTable gUnk_080B1788;
extern const u8 gUnk_080B1570[];
extern const u8 gUnk_080B1718[];
extern const u8 gUnk_083D28C0[];
extern const u8 gUnk_083D2908[];
extern const u8 gUnk_083D29A6[];
extern const u8 gUnk_083D29B6[];
extern const u16 *const gUnk_083F8634[]; // 16-colour palettes
extern const u8 gUnk_083D2918[][8];
extern const u8 gUnk_083D2B8D[];
extern const u8 gUnk_083D28C3[][16];
extern const u8 gUnk_083F8B74[][2];
extern const u8 gUnk_0847E948[];
extern const struct AreaWarp *const gUnk_08413114[];
extern void (*const gMapScriptCommands[])(void); // map script command handlers
extern void (*const gMapScriptUpdates[])(void);  // per-command update handlers, run each frame while unkC89 is set
extern const u8 gUnk_083D24AC[];                 // indexed by the player's facing (gSpriteEntries[47].unk21)
extern const u8 gUnk_083D28B0[];        // indexed by gUnk_030057E0.unkC5C, passed to setup_battle_sprite_terrain
extern const u8 *const gUnk_084045A8[]; // per area: tile map
extern const struct AreaGfx gUnk_083F92F4[];
extern const u8 gUnk_083D2903[];
extern const u8 gUnk_083D29E6[];
extern const u8 gUnk_085FA104[];                    // LZ77 sprite tiles
extern const struct MapExit *const gUnk_0840FAF4[]; // per area: 8-byte map exit records, 0xFF-terminated
extern const u16 gUnk_083AB9D0[];
extern const u16 gUnk_083ABA88[];
extern const u8 gUnk_083ABA8C[][16];
extern const u16 gUnk_083ABAB2[][4];
extern const u16 gUnk_083ABAC2[];
extern const u8 gSoundWavePatterns[][16];   // 4-bit samples for the wave channel (sound 3)
extern const u8 gUnk_083ABA62[16];          // envelope volume -> SOUND3CNT_H volume bits (>> 8)
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
extern u8 gUnk_030017EC;
extern s32 gUnk_03006F88;
extern u8 gUnk_03006F8C[];
extern s32 gUnk_03006F80; // sub-state to resume after a transition (code_08067160)
extern u8 gUnk_03006F84;
extern u8 gUnk_03006F90;
extern u8 gUnk_03006F94[3];
extern u8 gUnk_03006FA0[3][4][3];   // per racer: 4 bytes per stage, passed to init_battle_medabot_sprites
extern const Func gRaceSubStates[]; // race sub-states, by gGameSubState (race_dispatch_substate)
extern u8 gUnk_03006FD0[3][3];
extern s32 gUnk_03006FE0[3];      // per entry frame counters (race_update_racer_anim_counters)
extern const u8 gUnk_087B2CCC[];  // race BG tiles (LZ77, load_bg_tilemaps_and_palette)
extern const u8 gUnk_087B3710[];  // race BG2 tilemap (LZ77)
extern const u8 gUnk_087B384C[];  // race BG3 tilemap (LZ77)
extern const u16 gUnk_087B3AF0[]; // race BG palette
extern const u8 gUnk_087A44F8[];  // Medal scene OBJ palettes (medal_transform_init)
extern const u32 gUnk_087A46F8[]; // Medal scene BG tiles (dma3_copy_or_decompress)
extern const u8 gUnk_087A7F98[];  // Medal scene BG1 tilemap (decompress_and_write_tilemap)
extern const u8 gUnk_087A80E8[];  // BG2 tilemap
extern const u8 gUnk_087A8324[];  // BG3 tilemap
extern const u8 gUnk_087AD4E4[];  // race OBJ tiles (LZ77, load_battle_sprite_graphics)
extern const u8 gUnk_087C4EBC[];  // race field BG tiles (LZ77, init_battle_field_screen)
extern const u8 gUnk_087C4F48[];
extern const u8 gUnk_087C4FDC[];
extern const u8 gUnk_087C51C0[];
extern const u16 gUnk_087C5248[]; // race field BG palettes
extern const u16 gUnk_087C5268[];
extern const u16 gUnk_087C5288[];
extern const u16 gUnk_087C52A8[];
extern const u8 gUnk_087C52C8[];  // race BG1 tiles (LZ77, init_battle_bg_layer1)
extern const u8 gUnk_087C5518[];  // race BG1 tiles, second part (LZ77)
extern const u16 gUnk_087C55D0[]; // race BG1 palettes
extern const u16 gUnk_087C55F0[];
extern const u8 gUnk_0848417C[]; // scene text line counts by gUnk_03006F74->unk5 (text_scroll_lines)
extern u8 gUnk_03006FEC[3];      // per racer (set to 0x20 at the start, sub_0806A4C0)
extern u8 gUnk_03006FF0[3];      // per racer (cleared at the start, sub_0806A4C0)
extern s32 gUnk_03006FF8[2];
extern s32 gUnk_03007000[2];
extern const Func gUnk_08485C48[]; // by gGameState (dispatch_game_mode_handler)
extern const u8 gUnk_08485CCD[];   // racer table read by update_battle_icon_rotation (just after gUnk_08485CC4)
extern const struct ByteTable3 gUnk_080AFF30; // 3 bytes copied to the stack, indexed by racer (divide_by_3)
extern u8 gUnk_08485CC4[3][3];      // sprite slots (ROM; declared without const, the code reloads it after stores)
extern const u8 gUnk_08485CE3[][7]; // frame delays
extern bool32 (*const gUnk_08485D30[])(
    u8); // race sprite animations, by gSpriteEntries[].unk20 - 1 (update_sprite_animations_tick_0806AF40)
extern const s8 gUnk_08485E84[];
extern u8 gUnk_03006FDC;  // race course (copied from gUnk_03006D38.unk0, sub_08068C6C)
extern s32 gUnk_03000000; // scene step frame counter, reset when a step finishes (execute_scene_step)
extern u8 gUnk_03000004;  // scene step, gUnk_08485C7C index
extern bool32 (*const gUnk_08485C7C[])(void); // scene steps (execute_scene_step)
extern bool32 (*const gUnk_08485C68[])(void); // transition steps (scene_transition_step_080686F4)
extern const u16 gUnk_0807C320[];  // title OBJ palettes (0x60 colours), then 0x1C bytes copied to gUnk_03001800_s + 0xC
                                   // (title_screen_load_graphics)
extern const Func gUnk_08485E5C[]; // game mode 3 state 5 sub-states, by gGameSubState (bomb_game_dispatch)
extern const struct SpriteAnimFrame gUnk_08485D5C[]; // sprite animation steps (update_sprite_animations_0806B334)
extern const u8 gUnk_087B3B30[];  // game mode 3 state 5 (bomb_game_load_graphics): compressed BG tiles
extern const u8 gUnk_087B50AC[];  // compressed BG map (VRAM + 0x800)
extern const u8 gUnk_087B5214[];  // compressed BG map (VRAM + 0x1000)
extern const u8 gUnk_087B52E4[];  // compressed BG map (VRAM + 0x1800)
extern const u16 gUnk_087B551C[]; // BG palettes (0x50 colours)
extern const u8 gUnk_087AA19C[];  // compressed OBJ tiles
extern const u16 gUnk_0807C0A0[]; // OBJ palettes (0xF0 colours)
extern const s8 gUnk_08485E84[];  // per-frame y steps, by unk1A & 0x3F (sub_0806CDE8)
extern const Func
    gTitleScreenStates[]; // game mode 3 state 2 (title screen) sub-states, by gGameSubState (title_screen_update)
extern s32 (*const gTitleSpriteEffects[])(u8); // title sprite effects, by gSpriteEntries[].unk20 - 1: 0 = done, 0xFF =
                                               // hide (title_screen_update_sprite_effects)
extern const u8 gTitleSpriteEffectPeriods[];   // title sprite effects: frame period, by unk20 - 1
extern const Func gUnk_08485F1C[];             // game mode 3 state 3 (story intro) sub-states, by gGameSubState
                                               // (dispatch_game_substate_handler_0806DFA4)
extern const Func
    gBootLogosSubStates[]; // game mode 3 state 0 (boot logos) sub-states, by gGameSubState (boot_logos_update)
extern const Func gIntroSubStates[]; // game mode 3 state 1 (the animated intro after the logos) sub-states, by
                                     // gGameSubState (intro_update)
extern const void
    *const gUnk_08486EEC[]; // story intro texts, by page gUnk_03001800_s.unkC.h (dispatch_battle_event_script)
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
extern const u8 gUnk_087BA86C[];          // state 1 scene (load_battle_scene_graphics): compressed BG tiles
extern const u16 gUnk_087BDC10[];         // 256-colour BG palette
extern const u8 gUnk_087BDE10[];          // compressed tilemap (to 0x06007000)
extern const u8 gUnk_087BE18C[];          // compressed tilemap (to 0x06007800)
extern const u8 gUnk_087BE494[];          // state 1 scene (init_scene_graphics): compressed BG tiles
extern const u16 gUnk_087C09C0[];         // 256-colour BG palette
extern const u8 gUnk_087C0BC0[];          // compressed tilemap (to 0x06007000)
extern const u8 gUnk_087C0E0C[];          // compressed tilemap (to 0x06007800)
extern const u8 gUnk_087C8368[];          // compressed tiles (to 0x06008020)
extern const u16 gUnk_087C8818[];         // 16-colour palette
extern const u8 gUnk_087C8838[];          // compressed 10x12 tilemap
extern const u8 gUnk_087C88F4[];          // compressed tiles (init_scene_graphics)
extern const u8 gUnk_087C8BD8[];
extern const u8 gUnk_087C8C94[];
extern const u8 gUnk_087C8CE4[];
extern const u16 gUnk_087C8CF4[]; // 16-colour palettes (init_scene_graphics)
extern const u16 gUnk_087C8D14[];
extern const u16 gUnk_087C8D34[];
extern const u8 gUnk_087C8D54[];           // compressed, decompressed to gUnk_03001800_s.unk30 (load_battle_ui_assets)
extern const void *const gUnk_08485FB8[2]; // compressed tiles ([1] to 0x06008C80, load_battle_scene_graphics)
extern const void *const gUnk_08485FC0[2]; // compressed 20x20 tilemaps ([1] in load_battle_scene_graphics)
extern const void *const gUnk_08485FC8[2]; // 16-colour palettes ([1] in load_battle_scene_graphics)
extern const void *const gUnk_08485FD0[2]; // compressed OBJ tiles (load_battle_ui_assets)
extern const void *const gUnk_08485FD8[2]; // OBJ palettes (0x50 halfwords; [1] in init_battle_result_screen)
extern u8 gUnk_03000005;                   // scene step speed: frames per fade level
extern u16 gUnk_03000008[];                // BG0 tilemap offsets of the rows the wipe steps clear / fill
extern u16 gUnk_03000028;                  // palette fade target color
extern u16 *gUnk_0300002C;                 // palette fade source palette (0x200 colors)
extern u16 gUnk_03000030[160];             // title BG2 per-scanline values: BG2PA (title_screen_hblank, HBlank)
extern u16 gUnk_03000170[160];             // BG2X_L per scanline
extern u16 gUnk_030002B0[160];             // BG2X_H per scanline
extern u16 gUnk_030003F0; // title BG2 scroll counter, += 0x80 per frame (title_screen_build_wave_tables)
extern u8 gUnk_030004DE[];
extern const u8 gRandomBytes[]; // random bytes, indexed by the low byte of gFrameCounter
extern const void *const gUnk_084864E8[];
extern const struct Unk_08486160 gUnk_08486160[]; // by gUnk_03006FDC (init_battle_background_layers)
extern const u16 gUnk_0807C260[];                 // OBJ palettes (inside the 0x080750D8 data blob)
extern const u16 gUnk_0807C280[];
extern const u16 gUnk_0807C2A0[];
extern const u16 gUnk_0807C2C0[];
extern const u16 gUnk_0807C300[];
extern u8 gNameEntryMode; // 0 player name, 1 new Medal (default name), 2 rename a Medal gUnk_03000BE0[gUnk_030017EC]
extern u8 gUnk_03003870[];
extern u8 gUnk_03005664[];
extern const void *const gUnk_0847E8C4[];         // text pointers (guess)
extern const u32 *const gTextTable[];             // text pointers, banks 0-1 (guess)
extern const u32 *const *const gTextBankTables[]; // text pointer tables, bank 2+ (guess)
extern const s16 gUnk_083D69A0[][8]; // 16 steps; [n][0] / 16 = player sprite y offset (sub_0804DE28, guess: jump arc)
extern const u8 gUnk_083D2998[];     // map script terrain/palette id -> unkC5C/unkC69/unkC28 (sub_0804E324)
extern struct Unk_03002B70 gUnk_03002B70;       // = gMoney, with the bytes after it
extern const Func gUnk_083AC248[];              // game state 0 sub-state handlers (guess: debug map viewer)
extern const Func gFieldMenuHandlers[];         // game state 1 (field pause menu) sub-state handlers
extern const void *const gUnk_083B53F8[];       // messages used by game state 0 (guess: debug menu)
extern const void *const gLinkMessages[];       // message table (run_message)
extern const u8 gUnk_083AC420[];                // orbit centre x, y per gUnk_03000440.unk51
extern const u8 gUnk_083AC432[];                // per slot sprite priority base
extern const u8 gUnk_083AC43B[];                // x, y per team select slot (9)
extern const u8 gUnk_083AC468[];                // team select: cursor slot to move to after a pick, per slot
extern const u8 gUnk_083AC44D[];                // tile x, y per team select slot (9)
extern const u8 *const gMedabotSlotDpadMoves[]; // up, down, left, right: next slot (gUnk_03000440.unk51) per slot
extern const void *const gUnk_083B4AE0[];       // tilemaps (field menu rows: open/close animation frames)
extern const void *gUnk_083B5F80[];             // sprite animation commands (field menu cursor)
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
extern const u16 gUnk_084E2E58[];
extern const u16 gUnk_084E2E78[];
extern const u8 gUnk_084889F8[];
extern const void *const gUnk_083B69C8[]; // messages (run_message), indexed by Medal record byte 4 (Medals help)
extern const void *const gUnk_083B70AC[]; // messages (run_message), indexed by Medal record byte 6 (Medals help)
extern const u8 gUnk_083B7E0C[];          // 3 Medaforce ids per Medal graphic index (slots open at level 10/30/60)
extern const u8 gUnk_083B7CD4[];          // 6-byte Medaforce records: +1 skill type, +2 MF consumption, +5 icon
extern const void *const gUnk_083B7F40[]; // messages (run_message), Medals help Medaforce page
extern const void *const gUnk_083B8170[]; // messages (run_message), Medals help page 5
extern u32 gUnk_03002B68; // bit per Medal graphic index (sub_080092D4); also (part kind << 16) + part id (sub_0800EBB8)
extern const u8 gUnk_084EAC58[];
extern const u8 gUnk_084EF4E0[];
extern const u8 gUnk_084EFE28[];
extern const u8 gUnk_084F0A00[];
extern const u8 gUnk_084F1BA0[];
extern const u16 gUnk_084F32A0[];
extern const Func gMedawatchMenuHandlers[]; // game state 2 (Medawatch menu) sub-state handlers
extern const u8 gUnk_084E30D8[];
extern const u8 gUnk_084EF6A0[];
extern const u8 gUnk_084F023C[];
extern const u8 gUnk_084F0F2C[];
extern const u16 gUnk_084F24E0[];
extern const u8 gUnk_084C1C24[];
extern const u8 gUnk_084C1E04[];
extern const u8 gUnk_084C1FD4[];
extern u8 gUnk_02020040[]; // second 64-byte text tile buffer: glyph shifted then ORed into gUnk_02020000
                           // (text_render_glyph_step)
extern u8 gUnk_02020000[]; // tilemap rect buffer for the Robattle team-side scroll (status_side_change_scroll_out)
extern u8 gUnk_02020800[]; // BG tile backup (0x800 bytes of VRAM 0x06002800 while a Medawatch submenu runs)
extern const Func gMedabotsScreenHandlers[];  // game state 3 sub-state handlers
extern const Func gMedalsScreenHandlers[];    // game state 4 (Medals screen) sub-state handlers
extern const Func gMedapartsScreenHandlers[]; // game state 5 (Medaparts screen) sub-state handlers
extern const Func gUnk_083ACC94[];            // sprite 4 sub-state handlers, by gSpriteEntries[4].unk29 (sub_0801013C)
extern const Func gPrebattleScreenHandlers[]; // game state 6 ("Get ready to Robattle") sub-state handlers
extern const u8 gUnk_084C696C[];
extern const void *const gUnk_083C2BBC[]; // pre-battle opponent lines, by gUnk_03001800.unk0
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
                                     // owned (runtime-checked), [1] second count shown on the Medaparts list
// The Medaparts list shows 4 parts per page (part id = page * 4 + row); the game indexes it flat like this.
#define MEDAPART_INV(kind, page, row, byte) gMedapartInventory[(kind) * 240 + (page) * 8 + (row) * 2 + (byte)]
extern u8
    gItemInventory[64][2]; // item inventory (runtime-checked): [0] 0x80 | item id, [1] count (get_item_quantity_by_id)
extern const u8 gUnk_083B296C[]; // 4 per-phase y bob flags (update_battle_sprite_orbiting_positions)
extern const u8 gUnk_083B2970[]; // indexed by gUnk_030057E0.unkC5C (resolve_area_sprite_set)
extern const u8 gUnk_083B827C[]; // 16 bytes per Medapart (part id * 64 + kind * 16), copied by load_part_data
extern const u8 gUnk_083B286C[]; // random bytes, indexed by gUnk_03000440.unk8D when unk89 is set (rng_next_byte)
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
extern const void
    *const gUnk_083BE3E4[]; // messages (run_message), Medaparts detail help for head / arms, indexed by sub_0800F6CC()
extern const void
    *const gUnk_083BE92C[]; // messages (run_message), Medaparts detail help for legs, indexed by sub_0800F6CC()
extern const void *const gUnk_083B6E24[]; // messages (run_message), indexed by the part record byte unkEE
extern const void *const gUnk_083BD884[]; // messages (run_message), Medaparts help pages
extern const u8 gUnk_084E7264[];
extern const u8 gUnk_084C32DC[];
extern const u8 gUnk_0848833C[];
extern const u8 gUnk_084EF348[];
extern const u8 gUnk_084EFB5C[];
extern const u8 gUnk_084F04F0[];
extern const u8 gUnk_084F1554[];
extern const u16 gUnk_084F2BA0[];
extern const u16 gUnk_08488B44[];
extern const u16 gUnk_084E2E98[];
extern const u8 gUnk_084E80B0[];
extern const u8 gUnk_084EF380[];
extern const u8 gUnk_084EFBE0[];
extern const u8 gUnk_084F0688[];
extern const u8 gUnk_084F16E8[];
extern const u16 gUnk_084F2D60[];
extern const u8 gUnk_084E9020[];
extern const u8 gUnk_084C3524[];
extern const u8 gUnk_084C3648[];
extern const u8 gUnk_084EF3F4[];
extern const u8 gUnk_084EFCDC[];
extern const u8 gUnk_084F07B8[];
extern const u8 gUnk_084F187C[];
extern const u16 gUnk_084F2F20[];
extern const u8 gUnk_084E9E68[];
extern const u8 gUnk_084C37A4[];
extern const u8 gUnk_084C3990[];
extern const u8 gUnk_084EF46C[];
extern const u8 gUnk_084EFD74[];
extern const u8 gUnk_084F08F0[];
extern const u8 gUnk_084F1A10[];
extern const u16 gUnk_084F30E0[];
extern const void *const gUnk_083B7C00[]; // messages (run_message), indexed by medal_medaforce_get_selected()
extern const void
    *const gUnk_083B825C[]; // messages (run_message), indexed by a Medal record byte at +0x18 (guess: rotation entries)
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
extern const u8 gUnk_084C3208[];
extern const u8 gUnk_084C33DC[];
extern const u8 gUnk_084C4DB0[];
extern const u8 gUnk_084C7318[];
extern const u8 gUnk_084EF310[];
extern const u8 gUnk_084EF9C8[];
extern const u8 gUnk_084F03EC[];
extern const u8 gUnk_084F13C0[];
extern const u16 gUnk_084F2820[];
extern const u16 gUnk_0850DD58[];

extern const u8 gUnk_084C21BC[];           // Medal icon tiles, 0x80 bytes per graphic index
extern const u8 gUnk_084C30BC[];           // blank Medal icon tile
extern const u8 *const gUnk_083AC494[][5]; // compressed Medal sprites (load_medal_sprite)
extern const u32 gUnk_083B656C[];          // Medal Attribute names, indexed by Medal record unk4 (Ability page)
extern const u32 gUnk_083B6EC8[];          // skill type names (Shoot, Strike, ...): Medal Aim, Medaforce skill
extern const u8 *const gUnk_083B7EBC[];    // Medals help cursor layouts: count, then (x, y) tile pairs (sub_0800AA1C)
extern const u16 gUnk_083AC8AC[];          // (y, x) pairs per Medal skill row 0-7 (setup_battle_cursor_sprite_0800B5E8)
extern const Func
    gUnk_083AC8CC[]; // sprite 7 sub-state handlers, by gSpriteEntries[7].unk29 (update_battle_sprite_and_check_done)
extern const Func gDebugMenuHandlers[];       // game state 63 sub-state handlers (debug_menu_update)
extern const Func gDebugMenuEntryHandlers[];  // game state 63: one handler per menu entry (debug_menu_run_entry)
extern const Func gDebugProcessHandlers[];    // game state 63 entry 0 sub-state handlers (debug_process_update)
extern const Func gDebugMedalHandlers[];      // entry 1 (debug_medal_update)
extern const Func gDebugPartsHandlers[];      // entry 2 (debug_parts_update)
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
extern const u8 gUnk_084C3B14[];              // tiles, 5 rows of 0x100 bytes, 0x20 per Medals tab (sub_0800B0F8)
extern const u32 gUnk_083B7338[];             // Medaforce names, indexed by Medaforce id
extern const u32 gUnk_083BE97C[];             // Medapart skill names for ids >= 100 (medapart_detail_draw_skill)
extern u16 gUnk_03002B84[2]; // capped at 9999: [0] every game state 6 battle, [1] when gUnk_03000440.unk9C == 1
                             // (runtime-checked; guess: Robattles fought / won)
extern const void *const gUnk_083C3984[]; // after-battle opponent lines, by gUnk_03001800.unk0
extern const void *const gUnk_083C65C4[]; // messages (after-battle screen uses 107, 109, 118)
extern const u8 *const gPartKindNames[];  // Medapart kind names, by kind
extern const u8 gUnk_084D7C9C[];          // LZ tiles (after-battle screen sprite 1)
extern const u8 gUnk_084D7DB0[];          // LZ tiles (after-battle screen sprite 2)
extern const u16 gUnk_0850E9D8[];         // OBJ palette (sprite 1)
extern const u16 gUnk_084E2F98[];         // OBJ palette (sprite 2)

extern const u8 *const gUnk_083C3F38[]; // opponent names, by gUnk_03001800.unk0
extern const u8 *const gUnk_083BE9E8[]; // battlefield names, by gUnk_03001800.unk38
extern const u8 gUnk_083BEA90[][8];     // per area: [1] = battlefield (load_area_battlefield)
extern const u8
    gUnk_083BF090[][4]; // per area: random encounter ids, picked 40/30/20/10% (setup_random_encounter_enemies)
extern const u8
    *const gUnk_083C1A00[];            // encounter setups (0x28 bytes copied to gUnk_03001800), by gUnk_030057E0.unkC2A
extern const u8 gUnk_083ACEE4[][2];    // per opponent Medabot: sprite position (init_opponent_medabot_sprites)
extern const u8 gUnk_083ACEEA[][2];    // per opponent Medabot: leg type icon position (draw_opponent_leg_type_icons)
extern const u8 gUnk_083ACEF0[16];     // random starting opponent slot 0-2 (sub_08012234, sub_080122F4)
extern const u8 gUnk_083C3B04[][8];    // per battlefield (sub_080121A8)
extern const Func gRobattleHandlers[]; // game state 7 (Robattle) sub-state handlers
extern const void *const gUnk_083B24A8[]; // 5 compressed graphics pointers per battlefield (gUnk_03001800.unk38)
extern const u16 gUnk_084E2F58[];         // Robattle palette (OBJ palette 10, robattle_parts_menu_open)
extern const u16 gUnk_084E3038[];         // Robattle palette (OBJ palette 6, robattle_parts_menu_open)
extern const u16 gUnk_084E2F38[];         // Robattle palette (OBJ palette 10)
extern const u16 gUnk_084E2F78[];         // Robattle palette (OBJ palette 10)

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
extern const u8 *const gUnk_083C466C[]; // 12-byte name text, by gUnk_03001800.unk81 (command_ring_draw_name)
extern const u8 gUnk_083AD370[]; // angles for compute_polar_to_screen_position, by sprite slot - gUnk_03001800.unk81
                                 // (command_ring_init_icon)
extern const u8
    gUnk_083AD376[]; // next slot after a right turn of the ring, by gUnk_03001800.unk81 (command_ring_input)
extern const u8 gUnk_083AD37C[]; // next slot after a left turn
extern const u8 gUnk_083AD382[]; // 4-byte records: sprite count, start value, x, y (bot_pointer_line_init,
                                 // bot_pointer_line_animate)
extern const u8
    gUnk_083AD3A0[]; // part select: centre sprite frame by gUnk_03001800.unk82 (part_select_init_center_icon)
// Part / MF menu messages: Damaged, Unusable, Used Up, Charge MF, MF low, Unmastered
extern const u8 *const gBattleMenuTexts[];
// names by part skill id (part data[1]; part_select_draw_skill_name)
extern const u32 gUnk_083BE6E8[];
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
extern const u8 gAreaTownMapPlace[]; // town map place by area id (gUnk_030057E0.unk7FE, town_map_load_graphics)
extern const u32 gUnk_087873A4[];    // town map graphics (town_map_load_graphics)
extern const u8 *gDefaultPlayerName; // -> "Ikki" (stored in the tail of gNameEntryStates), name entry mode 0
extern const u16 gUnk_080AF810[];    // name entry OBJ palette (name_entry_load_name)
extern const u16 gUnk_08793428[];    // name entry BG palettes (name_entry_load_name)
extern const u8 gUnk_08784CB0[];     // save screen BG tiles, after gUnk_0878CC64 (LZ77)
extern const u8 gUnk_08784DA4[];     // save screen OBJ tiles (LZ77)

extern const Func gTitleMenuStates[]; // state handlers by gGameSubState (title_menu_update)

extern const u8 gUnk_0878FBB4[];        // title menu BG0 tilemap (LZ77, decompress_and_write_tilemap)
extern const u8 gUnk_0878FD84[];        // title menu BG1 tilemap
extern const u8 gUnk_0878FFC8[];        // title menu BG2 tilemap
extern const u8 gUnk_08790128[];        // title menu BG3 tilemap
extern const u32 gUnk_0878E5F4[];       // title menu BG tiles (dma3_copy_or_decompress)
extern const u8 gUnk_08792CD0[];        // BG0 tilemap (LZ77, sub_080601A4)
extern const u8 gUnk_08792E6C[];        // BG1 tilemap (LZ77, sub_080601A4)
extern const u8 gUnk_08792FC4[];        // BG3 tilemap (LZ77, sub_080601A4)
extern const u32 gUnk_08791D88[];       // BG tiles (dma3_copy_or_decompress, sub_080601A4)
extern const u16 gUnk_08791CA8[];       // BG palette (sub_080601A4)
extern const u16 gUnk_080AF988[];       // OBJ palette 0 (sub_080601A4)
extern const u8 gUnk_08785F34[];        // OBJ tiles (LZ77, sub_080601A4)
extern const u8 gUnk_08799838[];        // BG1 tilemap (LZ77, sub_08060C6C)
extern const u8 gUnk_087999EC[];        // BG2 tilemap (LZ77, sub_08060C6C)
extern const u8 gUnk_08798608[];        // BG1 tilemap (LZ77, sub_08060C6C)
extern const u8 gUnk_08798824[];        // BG2 tilemap (LZ77, sub_08060C6C)
extern const u8 gUnk_08798A34[];        // BG3 tilemap (LZ77, sub_08060C6C)
extern const u32 gUnk_0879691C[];       // BG tiles (dma3_copy_or_decompress, sub_08060C6C)
extern const u32 gUnk_08798F2C[];       // BG tiles (dma3_copy_or_decompress, sub_08060C6C)
extern const u8 gUnk_087962E8[];        // BG0 tilemap (LZ77, game_over_load_graphics)
extern const u8 gUnk_08796474[];        // BG2 tilemap (LZ77, game_over_load_graphics)
extern const u8 gUnk_08796598[];        // BG3 tilemap (LZ77, game_over_load_graphics)
extern const u32 gUnk_0879579C[];       // BG tiles (dma3_copy_or_decompress, game_over_load_graphics)
extern const u16 gUnk_0879559C[];       // BG palette (game_over_load_graphics)
extern const u16 gUnk_080AF900[];       // OBJ palettes 0-1 (game_over_load_graphics)
extern const u16 gGameOverIkkiFrames[]; // sprite 1 animation frames, by unk1A / 6 (game_over_logo_drop)
extern const s8 gGameOverLogoBounce[];  // sprite 0 y offsets, 13 steps (game_over_logo_drop)
extern const u16 gUnk_0878E3F4[];       // title menu BG palette (0x100 colors)
extern u8 gOptionTimeLimit;             // picks the Robattle TIME limit: 0 = 40, 1 = 30, 2 = 20 (robattle_time_init)
extern u8 gOptionBattleMusic;           // index into gUnk_083AD3B0 (battle music)
extern const u8 gUnk_083AD3B0[];        // battle song ids (select_battle_music)
extern const u8 gUnk_083C4C10[]; // per leg type (skill id - 100), 11 bytes: one per battlefield (gUnk_03001800.unk38);
                                 // added to unkBB (sub_080191E4)
extern const s8 gUnk_083AD3B3[]; // 32 y steps of the number pop-up over a Medabot (battle_number_popup_update)
extern const u8 gUnk_083AD3D3[]; // 32 random record orders (find_next_active_bot)
extern const u8 gUnk_083AD3F3[]; // record remap when gUnk_03000B90 is set in a link Robattle (find_next_active_bot)
extern const u8 gUnk_083AD3F9[]; // record remap for unkE0 (sub_0801C0A0)
extern const struct GfxListEntry *const gUnk_083CE480[]; // graphics lists (decompress_indexed_graphics_to_ewram)
extern const void *const gUnk_083B2584[];                // pairs: compressed tiles [i * 2], palette [i * 2 + 1]
extern const Func gBattleMessageSteps[]; // message steps by gUnk_03001800.unkA1[0] (battle_message_show)
extern const Func gMissPopupSteps[];     // steps by gUnk_03001800.unk9C[0] (miss_popup_run)
extern const Func gTargetPanelSteps[];   // steps by gUnk_03001800.unk9C[0] (target_panels_show)
extern const Func gUnk_083AD44C[];       // by gUnk_03001800.unkAA (sub_0801C4FC)
extern const Func gUnk_083AD50C[];       // by gUnk_03001800.unkAA (battle_dispatch_phase_handler_0801D2F0)
extern const Func gUnk_083AD530[];       // by gUnk_03001800.unkAA (sub_0801D380)
extern const Func gUnk_083AD550[];       // by gUnk_03001800.unkAA (sub_0801D40C)
extern const Func gUnk_083AD570[];       // by gUnk_03001800.unkAA (sub_0801D580)
extern const Func gUnk_083AD5B0[];       // by gUnk_03001800.unkAA (sub_0801DE1C)
extern const Func gUnk_083AD5D0[];       // by gUnk_03001800.unkAA (sub_0801DEE4)
extern const Func gUnk_083AD610[];       // by gUnk_03001800.unkAA (sub_0801E2D8)
extern const u8 gUnk_084C8AC4[];         // compressed OBJ tiles (miss_popup_load)
extern const u16 gUnk_084E3078[];        // OBJ palette (miss_popup_load)
extern const u16 gUnk_084E2EF8[];        // OBJ palette 8 (target_panels_line_init)
extern const u16 gUnk_084E2F18[];        // OBJ palette 9 (target_panels_arrows_init)
extern const u8 gUnk_084C907C[];         // compressed OBJ tiles, sub_0801C6C4 case 0
extern const u8 gUnk_084C9288[];         // case 1
extern const u8 gUnk_084C9624[];         // case 2
extern const u8 gUnk_084C978C[];         // case 3
extern const u16 gUnk_0850E058[];        // OBJ palettes for the same cases
extern const u16 gUnk_0850E078[];
extern const u16 gUnk_0850E098[];
extern const u16 gUnk_0850E0B8[];
extern const u8 gUnk_084CDBD8[];  // compressed OBJ tiles (sub_0801CD50)
extern const u16 gUnk_0850E378[]; // its OBJ palette (palette 7)
extern const u8 gUnk_084CC9A8[];  // compressed OBJ tiles (sub_0801CDD4)
extern const u16 gUnk_0850E338[]; // its OBJ palette (palette 7)
extern const u8 gUnk_084C6A98[];  // compressed OBJ tiles at 0x06017400 (sub_0801E09C)
extern const u16 gUnk_084E3038[]; // OBJ palette 6 (sub_0801D434)
extern const u8 gUnk_084C9880[];  // compressed OBJ tiles, sub_0801D6A4 for unkDF 0x1B
extern const u8 gUnk_084C9B88[];  // 0x1C
extern const u8 gUnk_084C9E9C[];  // 0x1D
extern const u16 gUnk_0850E0F8[]; // their OBJ palettes
extern const u16 gUnk_0850E118[];
extern const u16 gUnk_0850E138[];
extern const u8
    gUnk_0848886C[]; // Robattle screen tilemap (compressed), opponent side of gUnk_08488830 (draw_bot_panel_frame)
extern u8 gOptionSkipMessages;     // Robattle: nonzero skips the message windows unless gUnk_03000440.unk89 == 1
                                   // (battle_message_open..battle_message_finish)
extern const u8 gUnk_084E3058[];   // 32-byte OBJ palette, copied to OBJ palette 6 (mf_charge_sparkles_init)
extern u32 gUnk_030018A8[16];      // cleared in two 32-byte halves by battle_action_cleanup
extern const u8 gUnk_084C4F00[];   // compressed tiles (code_0801C988)
extern const u8 gUnk_084882F4[];   // compressed tiles (code_0801C988)
extern const u8 gUnk_084C65C8[];   // compressed tiles (code_0801C988)
extern const u8 gUnk_08488B24[];   // 32-byte OBJ palette (code_0801C988)
extern const u8 gUnk_084E3098[];   // 32-byte OBJ palette (code_0801C988)
extern const u8 gUnk_084C6A58[];   // 32-byte OBJ palette (code_0801C988)
extern const u8 gUnk_084CC430[];   // compressed tiles (code_0801C988)
extern const u8 gUnk_0850E2D8[];   // 32-byte OBJ palette (code_0801C988)
extern const u8 gUnk_084CC7C8[];   // compressed tiles (code_0801C988)
extern const u8 gUnk_0850E318[];   // 32-byte OBJ palette (code_0801C988)
extern const u8 gUnk_084CB950[];   // compressed tiles (code_0801C988)
extern const u8 gUnk_0850E258[];   // 32-byte OBJ palette (code_0801C988)
extern const u8 gUnk_084CBC10[];   // compressed tiles (code_0801C988)
extern const u8 gUnk_0850E278[];   // 32-byte OBJ palette (code_0801C988)
extern const u8 gUnk_084CBF04[];   // compressed tiles (code_0801C988)
extern const u8 gUnk_0850E298[];   // 32-byte OBJ palette (code_0801C988)
extern const u8 gUnk_084CC19C[];   // compressed tiles (code_0801C988)
extern const u8 gUnk_0850E2B8[];   // 32-byte OBJ palette (code_0801C988)
extern const u8 gUnk_084D1824[];   // compressed tiles (code_0801C988)
extern const u8 gUnk_0850E018[];   // 32-byte OBJ palette (code_0801C988)
extern const u8 gUnk_084CCE48[];   // compressed tiles (code_0801C988)
extern const u8 gUnk_0850E358[];   // 32-byte OBJ palette (code_0801C988)
extern const u8 gUnk_084CA61C[];   // compressed tiles (code_0801C988)
extern const u8 gUnk_0850E198[];   // 32-byte OBJ palette (code_0801C988)
extern const u8 gUnk_084CA428[];   // compressed tiles (code_0801C988)
extern const u8 gUnk_0850E178[];   // 32-byte OBJ palette (code_0801C988)
extern const u8 gUnk_084CC5F8[];   // compressed tiles (code_0801C988)
extern const u8 gUnk_0850E2F8[];   // 32-byte OBJ palette (code_0801C988)
extern const u8 gUnk_084D18EC[];   // compressed tiles (code_0801C988)
extern const u8 gUnk_0850E498[];   // 32-byte OBJ palette (code_0801C988)
extern const u8 gUnk_084CDCD4[];   // compressed tiles (code_0801C988)
extern const u8 gUnk_0850E398[];   // 32-byte OBJ palette (code_0801C988)
extern const u8 gUnk_0850DFF8[];   // 32-byte OBJ palette (code_0801C988)
extern const Func gUnk_083AD750[]; // by gUnk_03001800.unkAA (sub_0801F484)
extern const u8 gUnk_084CA89C[];   // compressed tiles (code_0801C988)
extern const u8 gUnk_0850E1B8[];   // 32-byte OBJ palette (code_0801C988)
extern const u8 gUnk_084CE154[];   // compressed tiles (code_0801C988)
extern const u8 gUnk_0850E3B8[];   // 32-byte OBJ palette (code_0801C988)
extern const u8 gUnk_084CE644[];   // compressed tiles (code_0801C988)
extern const u8 gUnk_0850E3D8[];   // 32-byte OBJ palette (code_0801C988)
extern const u8 gUnk_084CEF14[];   // compressed tiles (code_0801C988)
extern const u8 gUnk_0850E3F8[];   // 32-byte OBJ palette (code_0801C988)
extern const u8 gUnk_084CF340[];   // compressed tiles (code_0801C988)
extern const u8 gUnk_0850E418[];   // 32-byte OBJ palette (code_0801C988)
extern const u8 gUnk_084CAB58[];   // compressed tiles (code_0801C988)
extern const u8 gUnk_0850E1D8[];   // 32-byte OBJ palette (code_0801C988)
extern const u8 gUnk_084CAFD8[];   // compressed tiles (code_0801C988)
extern const u8 gUnk_0850E1F8[];   // 32-byte OBJ palette (code_0801C988)
extern const u8 gUnk_084CB36C[];   // compressed tiles (code_0801C988)
extern const u8 gUnk_0850E218[];   // 32-byte OBJ palette (code_0801C988)
extern const u8 gUnk_084CB684[];   // compressed tiles (code_0801C988)
extern const u8 gUnk_0850E238[];   // 32-byte OBJ palette (code_0801C988)
extern const Func gUnk_083AD794[]; // by gUnk_03001800.unkAA (sub_0801FA40)
extern struct Unk_083B4AE0 gUnk_083B4AE0_s; // same address as gUnk_083B4AE0
extern const Func gUnk_083AD7D4[];          // by gUnk_03001800.unkAA (sub_0801FDEC)
extern const u8 gUnk_084CA1A4[];            // compressed tiles (code_0801C988)
extern const u8 gUnk_084D1074[];            // compressed tiles (code_0801C988)
extern const u8 gUnk_084D01EC[];            // compressed tiles (code_0801C988)
extern const u8 gUnk_084D073C[];            // compressed tiles (code_0801C988)
extern const u8 gUnk_0850E158[];            // 32-byte OBJ palette (code_0801C988)
extern const u8 gUnk_0850E478[];            // 32-byte OBJ palette (code_0801C988)
extern const u8 gUnk_0850E438[];            // 32-byte OBJ palette (code_0801C988)
extern const u8 gUnk_0850E458[];            // 32-byte OBJ palette (code_0801C988)
extern const Func gUnk_083AD814[];          // by gUnk_03001800.unkAA (sub_08020050)
extern const Func gUnk_083AD878[];          // by gUnk_03001800.unkAA (sub_0802057C)
extern const Func gUnk_083AD898[];          // by gUnk_03001800.unkAA (sub_080207A4)
extern const Func gRecoverySteps[];         // by gUnk_03001800.unkAA (recovery_run)
extern const Func gRecoveryHealSteps[];     // by gUnk_03001800.unkAA (recovery_heal_run)
extern const Func gRepairSteps[];           // by gUnk_03001800.unkAA (repair_run)
extern const Func gRepairApplySteps[];      // by gUnk_03001800.unkAA (repair_apply_run)
extern const Func gTrapSteps[];             // by gUnk_03001800.unkAA (trap_run)
extern const Func gBreakFormSteps[];        // by gUnk_03001800.unkAA (break_form_run)
extern const u8 gUnk_084D50DC[];            // compressed tiles (code_080209B0)
extern const u8 gUnk_0850E658[];            // 32-byte OBJ palette (code_080209B0)
extern const u8 gUnk_084D513C[];            // compressed tiles (code_080209B0)
extern const u8 gUnk_0850E678[];            // 32-byte OBJ palette (code_080209B0)
extern const u8 gUnk_084D54BC[];            // compressed tiles (code_080209B0)
extern const u8 gUnk_0850E698[];            // 32-byte OBJ palette (code_080209B0)
extern const Func gStabilitySteps[];        // by gUnk_03001800.unkAA (stability_run)
extern const Func gForceBindSteps[];        // by gUnk_03001800.unkAA (force_bind_run)
extern const Func gDefenceSteps[];          // by gUnk_03001800.unkAA (defence_run)
extern const u8 gUnk_084D55D0[];            // compressed tiles (code_080209B0)
extern const u8 gUnk_0850E6B8[];            // 32-byte OBJ palette (code_080209B0)
extern const u8 gUnk_084D5788[];            // compressed tiles (code_080209B0)
extern const u8 gUnk_0850E6D8[];            // 32-byte OBJ palette (code_080209B0)
extern const Func gAutoRecoverSteps[];      // by gUnk_03001800.unkAA (autorecover_run)
extern const u8 gUnk_084D5860[];            // compressed tiles (code_080209B0)
extern const u8 gUnk_0850E6F8[];            // 2 OBJ palettes (code_080209B0)
extern const Func gReactivateSteps[];       // by gUnk_03001800.unkAA (reactivate_run)
extern const u8 gUnk_084D5B08[];            // compressed tiles (code_080209B0)
extern const u8 gUnk_0850E738[];            // 2 OBJ palettes (code_080209B0)
extern const Func gScoutSteps[];            // by gUnk_03001800.unkAA (scout_run)
extern const u8 gUnk_084D5D78[];            // compressed tiles (code_080209B0)
extern const u8 gUnk_0850E778[];            // 2 OBJ palettes (code_080209B0)
extern const Func gConcealSteps[];          // by gUnk_03001800.unkAA (conceal_run)
extern const u8 gUnk_084D5EBC[];            // compressed tiles (code_080209B0)
extern const u8 gUnk_0850E7B8[];            // 32-byte OBJ palette (code_080209B0)
extern const Func gBoostChargeSteps[];      // by gUnk_03001800.unkAA (boost_charge_run)
extern const u8 gUnk_084D6098[];            // compressed tiles (code_080209B0)
extern const u8 gUnk_0850E7D8[];            // 32-byte OBJ palette (code_080209B0)
extern const Func gRapidChargeSteps[];      // by gUnk_03001800.unkAA (rapid_charge_run)
extern const u8 gUnk_084D61DC[];            // compressed tiles (code_080209B0)
extern const u8 gUnk_0850E7F8[];            // 32-byte OBJ palette (code_080209B0)
extern const Func gDrainChargeSteps[];      // by gUnk_03001800.unkAA (drain_charge_run)
extern const u8 gUnk_084D6320[];            // compressed tiles (code_080209B0)
extern const u8 gUnk_0850E818[];            // 32-byte OBJ palette (code_080209B0)
extern const Func gPushoverSteps[];         // by gUnk_03001800.unkAA (pushover_run)
extern const u8 gUnk_084D6464[];            // compressed tiles (code_080209B0)
extern const u8 gUnk_0850E838[];            // 32-byte OBJ palette (code_080209B0)
extern const u8 gBurstSpriteDirections[];   // 4 bytes, sprite unk25 for slots 0x26-0x29 (pushover_burst_spawn)
extern const Func gImpairSteps[];           // by gUnk_03001800.unkAA (impair_run)
extern const u8 gUnk_084D651C[];            // compressed tiles (code_080249C0)
extern const u8 gUnk_0850E858[];            // 32-byte OBJ palette (code_080249C0)
extern const u8 gUnk_084D6780[];            // compressed tiles (code_080249C0)
extern const u8 gUnk_0850E878[];            // 64-byte OBJ palettes (code_080249C0)
extern const Func gConfusionSteps[];        // by gUnk_03001800.unkAA (confusion_run)
extern const Func gUseDrainSteps[];         // by gUnk_03001800.unkAA (use_drain_run)
extern const u8 gUnk_084D6AAC[];            // compressed tiles (code_080249C0)
extern const u8 gUnk_0850E8B8[];            // 64-byte OBJ palettes (code_080249C0)
extern const u8 gUnk_084D6BFC[];            // compressed tiles (code_080249C0)
extern const Func gNoEscapeDefenseSteps[];  // by gUnk_03001800.unkAA (no_escape_defense_run)
extern const u8 gUnk_084D6CC4[];            // compressed tiles (code_080249C0)
extern const u8 gUnk_0850E8F8[];            // 32-byte OBJ palette (code_080249C0)
extern const u8 gUnk_084D6E20[];            // compressed tiles (code_080249C0)
extern const u8 gUnk_0850E918[];            // 32-byte OBJ palette (code_080249C0)
extern const Func gForcedrainSteps[];       // by gUnk_03001800.unkAA (forcedrain_run)
extern const u8 gUnk_084D6F88[];            // compressed tiles (code_080249C0)
extern const u8 gUnk_0850E938[];            // 32-byte OBJ palette (code_080249C0)
extern const Func gTeamAttackCheckSteps[];  // by gUnk_03001800.unkAA (team_attack_check_run)
extern const Func gTeamAttackTurretSteps[]; // by gUnk_03001800.unkAA (team_attack_turrets_run)
extern const Func gCounterAttackSteps[];    // by gUnk_03001800.unkAA (counter_attack_run)
extern const u8 gUnk_084D71D8[];            // compressed tiles (code_080249C0)
extern const u8 gUnk_0850E978[];            // 32-byte OBJ palette (code_080249C0)
extern const Func gChangeSteps[];           // by gUnk_03001800.unkAA (change_run)
extern const u8 gUnk_084D7528[];            // compressed tiles (code_080249C0)
extern const u8 gUnk_0850E998[];            // 64-byte OBJ palettes (code_080249C0)
extern const Func gUnk_083AE1C0[];          // by gUnk_03001800.unkAA (sub_08026884)
extern const Func gUnk_083AE240[];          // by gUnk_03001800.unkAA (sub_08026CF4)
extern const Func gUnk_083AE300[];          // by gUnk_03001800.unkAA (sub_08026ED0)
extern const Func gUnk_083AE380[];          // by gUnk_03001800.unkAA (sub_08026FD0)
extern const u8 gUnk_084DB788[];            // compressed tiles (code_080249C0)
extern const u8 gUnk_0850EB38[];            // 64-byte OBJ palettes (code_080249C0)
extern const Func gUnk_083AE400[];          // by gUnk_03001800.unkAA (sub_0802793C)
extern const Func gUnk_083AE440[];          // by gUnk_03001800.unkAA (sub_08027F5C)
extern const u8 gUnk_084DBB28[];            // compressed tiles (code_080249C0)
extern const u8 gUnk_084E30B8[];            // 64-byte OBJ palettes (code_080249C0)
extern const u8 gUnk_084DBCAC[];            // compressed tiles (code_080249C0)
extern const u8 gUnk_0850EB58[];            // 64-byte OBJ palettes (code_080249C0)
extern const u8 gUnk_084DBD0C[];            // compressed tiles (code_080249C0)
extern const u8 gUnk_0850EB78[];            // 64-byte OBJ palettes (code_080249C0)
extern const u8 gUnk_084DBD60[];            // compressed tiles (code_080249C0)
extern const u8 gUnk_0850EB98[];            // 64-byte OBJ palettes (code_080249C0)
extern const Func gUnk_083AE480[];          // by gUnk_03001800.unkAA (sub_08028248)
extern const u8 gUnk_084DBDC8[];            // compressed tiles (code_080249C0)
extern const u8 gUnk_0850EBB8[];            // 64-byte OBJ palettes (code_080249C0)
extern const Func gUnk_083AE4C0[];          // by gUnk_03001800.unkAA (sub_08028404)
extern const u8 gUnk_084DBEE4[];            // compressed tiles (code_080249C0)
extern const u8 gUnk_0850EBD8[];            // 64-byte OBJ palettes (code_080249C0)
extern const u8 gUnk_084DC100[];            // compressed tiles (code_080249C0)
extern const u8 gUnk_0850EBF8[];            // 64-byte OBJ palettes (code_080249C0)
extern const u8 gUnk_084DC544[];            // compressed tiles (code_080249C0)
extern const u8 gUnk_0850EC18[];            // 64-byte OBJ palettes (code_080249C0)
extern const u8 gUnk_084DC7D0[];            // compressed tiles (code_080249C0)
extern const u8 gUnk_0850EC38[];            // 64-byte OBJ palettes (code_080249C0)
extern const u8 gUnk_084DD188[];            // compressed tiles (code_080249C0)
extern const u8 gUnk_0850EC78[];            // 64-byte OBJ palettes (code_080249C0)
extern const u16 gUnk_0850E0D8[];           // battle graphics (battle_load_graphics_step)
extern const u8 gUnk_0850DDB8[];            // battle graphics (battle_load_graphics_step)
extern const u16 gUnk_084C6A38[];           // battle graphics (battle_load_graphics_step)
extern const u16 gUnk_08488AE4[];           // battle graphics (battle_load_graphics_step)
extern const u16 gUnk_08488B04[];           // battle graphics (battle_load_graphics_step)
extern const u16 gUnk_08488AC4[];           // battle graphics (battle_load_graphics_step)
extern const u16 gUnk_084C6A18[];           // battle graphics (battle_load_graphics_step)
extern const u8 gUnk_084E2C18[];            // battle graphics (battle_load_graphics_step)
extern const u8 gUnk_084E2950[];            // battle graphics (battle_load_graphics_step)
extern const u8 gUnk_084C7FC0[];            // battle graphics (battle_load_graphics_step)
extern const u8 gUnk_08487D6C[];            // battle graphics (battle_load_graphics_step)
extern const u8 gUnk_08487C94[];            // battle graphics (battle_load_graphics_step)
extern const u8 gUnk_08487B80[];            // battle graphics (battle_load_graphics_step)
extern const u8 gUnk_084C984C[];            // battle graphics (battle_load_graphics_step)
extern const u8 gUnk_084C7634[];            // battle graphics (battle_load_graphics_step)
extern const u8 gUnk_084881EC[];            // battle graphics (battle_load_graphics_step)
extern const u8 gUnk_08488114[];            // battle graphics (battle_load_graphics_step)
extern const u8 gUnk_0848803C[];            // battle graphics (battle_load_graphics_step)
extern const u8 gUnk_08487F64[];            // battle graphics (battle_load_graphics_step)
extern const u8 gUnk_08487E68[];            // battle graphics (battle_load_graphics_step)
extern const u8 gUnk_084C5008[];            // battle graphics (battle_load_graphics_step)
extern const u8 gUnk_08487A24[];            // battle graphics (battle_load_graphics_step)
extern const u8 gUnk_084C5080[];            // battle graphics (battle_load_graphics_step)
extern const u8 gUnk_084879F0[];            // battle graphics (battle_load_graphics_step)
extern const u8 gUnk_084C4F8C[];            // battle graphics (battle_load_graphics_step)
extern const u8 gUnk_083C4C88[][4];         // bot status sprite OAM attribute sets (battle_bot_status_sprite_update)
extern const u8 gUnk_083C4C60[][4];         // status sprite OAM attribute sets, 4 bytes each (code_08018900)
extern const u16 gUnk_083AF4C0[];           // battle cursor sprite data (setup_battle_cursor_sprite_08036FF8)
extern const u8 *const gUnk_083AFD08[][9];  // LZ assets by set and index (decompress_indexed_asset)
extern const u16 *const gUnk_083B15C8[];    // palettes by asset set (decompress_indexed_asset)
extern const u16 gUnk_084C6998[];           // text window OBJ palette (text_window_init)
extern const u8 gUnk_08488540[];            // LZ text window graphics (text/message)
extern const u8 gUnk_084C31BC[];            // LZ text window graphics (text/message)
extern const u8 gUnk_084873D0[];            // LZ text window graphics (text/message)
extern const u16 gUnk_0850EF58[];           // OBJ palettes (link Robattle screen, prize_game_load)
extern const u16 gUnk_084F39A0[];           // BG palettes (link Robattle screen, prize_game_load)
extern const u8 gUnk_084F21E8[];            // LZ graphics (link Robattle screen, prize_game_load)
extern const u8 gUnk_084F0D9C[];            // LZ graphics (link Robattle screen, prize_game_load)
extern const u8 gUnk_084F0194[];            // LZ graphics (link Robattle screen, prize_game_load)
extern const u8 gUnk_084EF668[];            // LZ graphics (link Robattle screen, prize_game_load)
extern const u8 gUnk_084E20F8[];            // LZ graphics (link Robattle screen, prize_game_load)
extern const u8 gUnk_084C68E0[];            // LZ graphics (link Robattle screen, prize_game_load)
extern const u8 gUnk_084C66B8[];            // LZ graphics (link Robattle screen, prize_game_load)
extern const u8 gUnk_084EDEF0[];            // LZ graphics (link Robattle screen, prize_game_load)
extern const s16 gUnk_083AFAB8[];           // y offsets by sprite unk23 (0-31; sub_0803C680)
extern const u8 gUnk_083AFAAC[];            // BG3 parallax shift by battlefield gUnk_03001800.unk38 (sub_0803BE44)
extern const Func gUnk_083AF96C[];          // sprite handlers by unk29, slots 1-0x27 (battle_sequence_update_sprites)
extern const u8
    *const gUnk_083AF95C[]; // pairs: compressed OBJ tiles (lz_decompress to 0x02000000), OBJ palette 14 (sub_0803B19C)
extern const struct Unk_083AF94C gUnk_083AF94C[]; // 4 sprite positions (sub_0803B0C0)
extern const Func gUnk_083AF720[];                // sprite handlers by unk29 for slots 0x21-0x3B (sub_0803884C)
extern const u16 gUnk_083AF520[];                 // 4 (x, y) particle offsets, x and y picked by separate rng & 3 rolls
                                                  // (spawn_battle_particle_effect)
extern const u16 gUnk_083AF6D0[];   // 4 (x, y) offsets from the source sprite, picked by rng & 3 (sub_08038428)
extern const u8 gUnk_083CED08[];    // random part ids (pick_random_change_part)
extern const u8 gUnk_083CED88[];    // random part ids (pick_random_change_part)
extern const u8 gUnk_083CEE08[];    // random part ids (pick_random_change_part)
extern const u8 gUnk_083CEE88[];    // random part ids (pick_random_change_part)
extern const u8 gUnk_083CEEC8[];    // random part ids (pick_random_change_part)
extern const u8 gUnk_083CEF08[];    // random part ids (pick_random_change_part)
extern const u8 gUnk_083CEF48[];    // random part ids (pick_random_change_part)
extern const u8 gUnk_083CEF88[];    // random part ids (pick_random_change_part)
extern const u8 gUnk_083CEFC8[];    // random part ids (pick_random_change_part)
extern const u8 gUnk_083CF008[];    // random part ids (pick_random_change_part)
extern const u8 gUnk_083CF048[];    // random part ids (pick_random_change_part)
extern const u8 gUnk_083CF088[];    // random part ids (pick_random_change_part)
extern const u8 gUnk_083CF0C8[];    // random part ids (pick_random_change_part)
extern const u8 gUnk_083CF108[];    // random part ids (pick_random_change_part)
extern const u8 gUnk_083CF148[];    // random part ids (pick_random_change_part)
extern const void *gUnk_083B6010[]; // sprite animation commands (update_sprite_animations_tick_080370AC)
extern const u16 gUnk_083AF490[];   // x, y offset pairs per sprite of a 4-sprite group (sub_08036784)
extern const u16 gUnk_083AF440[];   // (dx, dy) s16 pairs by sprite unk23, added to the sprite position (sub_080366DC)
extern const u16 gUnk_083AF400[];   // (dx, dy) s16 pairs by sprite unk23, added to the sprite position (sub_080366DC)
extern const u16 gUnk_083AF3C0[];   // (dx, dy) s16 pairs by sprite unk23, added to the sprite position (sub_080366DC)
extern const u16 gUnk_083AF380[];   // (dx, dy) s16 pairs by sprite unk23, added to the sprite position (sub_080366DC)
extern const u16 gUnk_083AF4E0[];   // 32 y offsets added to a sprite's unk4 by sprite_bob_step
extern const u8 gUnk_083AF4A0[];    // 16 y offsets added to a sprite's unk4 by advance_sprite_anim_frame
extern const u8 gUnk_083AF4B0[]; // 16 x offsets added to / subtracted from a sprite's unk2 by medal_update_exp_progress
extern const u8 gUnk_083AF210[]; // 256 speed steps (quarter pixels) by a sprite's unk30 (sprite_move_toward_target,
                                 // update_sprite_deceleration)
extern const u16 gUnk_083AF670[]; // 16 x offsets by a sprite's unk2D & 15 (sub_080380F0)
extern const u8 gUnk_083AF630[];  // radius steps (byte pairs) by a sprite's unk2D & 31 (sub_08037C50)
extern const u8
    gUnk_083AF330[]; // 8 entries per sub_08035590 result, one picked at random (get_random_battle_weight_entry)
extern const u8 gUnk_084889B4[];   // compressed tilemap (sub_08036340)
extern u8 gUnk_0300056F;           // sprite slot whose handler is running (sub_080383E8)
extern const Func gUnk_083AF690[]; // battle effect sprite handlers by sprite unk29 (sub_080383E8, sprites 0x2B-0x3B)
extern const Func gUnk_083AF530[]; // sprite handlers by sprite unk29 (sub_08037B9C, sprites 0x21-0x3B)
extern const s16
    *const gUnk_083CDFE4[];      // battle sequence scripts, by gUnk_03001800.unkF9 (load_battle_sequence_commands)
extern const u8 gUnk_083CE1F4[]; // operand count per battle sequence command (battle_advance_sequence_counter)
extern const u16 *const gUnk_083CEC74[]; // x, y passed to tile_anim_init, by sprite 4 unk2B (sub_080398AC)
extern const u8 *const gUnk_083AF888[];  // by sequence operand: 4 animation sets, by legs data[1] - 0x64 (3 when
                                         // gUnk_03001800.unk64[3] > 0x77; sub_08039AC8)
extern const u8 *const gUnk_083AF88C[];  // pairs: compressed OBJ tiles, OBJ palette 14 (sub_0803A0E0)
extern const Func gUnk_083AF740[];       // battle sequence commands, by sub_0803D424() (battle_sequence_run_command)
extern const Func gUnk_083AF6E0[];       // sprite handlers by sprite unk29 (sub_080385F8, sprites 0x21-0x3B)
extern u16
    gUnk_083AF480[]; // x, y offset pairs by part (sub_08036C20); not const: sub_08036784 reloads it per iteration
extern const u8 gUnk_083AF200[]; // 16 values, two random picks summed into gUnk_03001800.unk188 / unk189 (sub_08034AA0)
extern u8 gUnk_03003470[]; // IWRAM buffer; sub_08033ACC copies 4 x 0x40 bytes from +0xE40 + (rec * 0x100) to its start
extern const u8 gUnk_083C6D38[];     // Robattle action script: operand count per command byte (battle_script_advance)
extern const u8 gSpriteHopOffsets[]; // 32 y offsets added to a sprite's unk4 by sprite_hop_step
extern const u8
    *const gUnk_083C6B28[]; // Robattle action scripts by skill id gUnk_03001800.unkA8 (battle_script_read_byte)
extern const Func
    gUnk_083AF000[]; // Robattle action script commands by script byte < 0x80 (battle_run_action_script; script from
                     // gUnk_083C6B28[gUnk_03001800.unkA8] at offset unkBC, battle_script_read_byte)
extern const Func gUnk_083AEF10[]; // Robattle AI: action validity checks by part skill id data[1]; set
                                   // gUnk_03001800.unk51 = 1 to reject (begin_battle_action_lookup)
extern const u8 gUnk_083AEF00[];   // 16 slot numbers 0-2 picked by rng & 15 (rng_lookup_table_value)
extern const Func gUnk_083AEE10[]; // Robattle AI: action handlers by part skill id data[1] (call_bot_action_handler)
extern const Func gUnk_083AED20[]; // Robattle AI: action selection handlers by part skill id data[1]
                                   // (battle_execute_action_selection)
extern const u8 gUnk_083AED18[];   // sprite 0x22 palette bits (unkA) by the levelled-up skill type gUnk_03001800.unk166
                                   // (sub_08031458)
extern const u8 gUnk_084D796C[];   // compressed OBJ tiles at 0x06014800 (sub_08031390)
extern u8 gLinkPartnerName[]; // = gUnk_03001800.partnerName: link partner's player name (link_robattle_exchange_names)
extern u8 gUnk_03002B74[];    // 14-byte name copied for message 2 when gUnk_03000440.unk9C == 1 (sub_080310A0; guess:
                              // player name)
extern const u8 gUnk_084E2FF8[];   // 32-byte OBJ palette (code_0802CA5C)
extern const Func gUnk_083AEB58[]; // by gGameSubState (battle_action_state_update)
extern const u8 gUnk_084E1EA4[];   // compressed tiles (code_0802CA5C)
extern const Func gUnk_083AEB18[]; // by gUnk_03001800.unkAA (sub_0802FE50)
extern const u8 gUnk_0850EF18[];   // 32-byte OBJ palette (code_0802CA5C)
extern const u8 gUnk_084E1B98[];   // compressed tiles (code_0802CA5C)
extern const Func gUnk_083AEAD8[]; // by gUnk_03001800.unkAA (sub_0802F990)
extern const u8 gUnk_0850EEF8[];   // 32-byte OBJ palette (code_0802CA5C)
extern const u8 gUnk_084E1884[];   // compressed tiles (code_0802CA5C)
extern const Func gUnk_083AEA84[]; // by gUnk_03001800.unkAA (sub_0802F628)
extern const Func gUnk_083AEA44[]; // by gUnk_03001800.unkAA (sub_0802F030)
extern const u8 gUnk_084E17E0[];   // compressed tiles (code_0802CA5C)
extern const Func gUnk_083AEA08[]; // by gUnk_03001800.unkAA (sub_0802EBC0)
extern const u8 gUnk_084E3018[];   // 32-byte OBJ palette (code_0802CA5C)
extern const u8 gUnk_0850EED8[];   // 32-byte OBJ palette (code_0802CA5C)
extern const u8 gUnk_084E1518[];   // compressed tiles (code_0802CA5C)
extern const Func gUnk_083AE99C[]; // by gUnk_03001800.unkAA (battle_dispatch_phase_handler_0802E424)
extern const u8 gUnk_083AE988[];   // pairs (sprite unk25 frame or 0xFF end, wait frames) by sprite unk23 (sub_0802DE1C)
extern const u8 gUnk_0850EEB8[];   // 32-byte OBJ palette (code_0802CA5C)
extern const u8 gUnk_084E046C[];   // compressed tiles (code_0802CA5C)
extern const Func gUnk_083AE908[]; // by gUnk_03001800.unkAA (sub_0802DCB4)
extern const u8 gUnk_0850EE98[];   // 32-byte OBJ palette (code_0802CA5C)
extern const u8 gUnk_084E0360[];   // compressed tiles (code_0802CA5C)
extern const Func gUnk_083AE8B0[]; // by gUnk_03001800.unkAA (sub_0802D688)
extern const Func gUnk_083AE854[]; // by gUnk_03001800.unkAA (sub_0802CBE8)
extern const u8 gUnk_084DFFE4[];   // compressed tiles (code_08028A00)
extern const u8 gUnk_0850EE78[];   // 32-byte OBJ palette (code_08028A00)
extern const Func gUnk_083AE814[]; // by gUnk_03001800.unkAA (sub_0802C644)
extern const Func gUnk_083AE7D4[]; // by gUnk_03001800.unkAA (sub_0802C2AC)
extern const u8 gUnk_083AE7D0[];   // frame counts (sub_0802BE44)
extern const Func gUnk_083AE790[]; // by gUnk_03001800.unkAA (sub_0802BD6C)
extern const u8 gUnk_084DFC18[];   // compressed tiles (code_08028A00)
extern const u8 gUnk_0850EE38[];   // 64-byte OBJ palettes (code_08028A00)
extern const Func gUnk_083AE750[]; // by gUnk_03001800.unkAA (sub_0802B7E8)
extern const u8 gUnk_084DFBD4[];   // compressed tiles (code_08028A00)
extern const u8 gUnk_0850EDF8[];   // 64-byte OBJ palettes (code_08028A00)
extern const Func gUnk_083AE700[]; // by gUnk_03001800.unkAA (sub_0802B000)
extern const u8 gUnk_084DFA88[];   // compressed tiles (code_08028A00)
extern const u8 gUnk_0850EDB8[];   // 64-byte OBJ palettes (code_08028A00)
extern const u8 gUnk_0850ED98[];   // 64-byte OBJ palettes (code_08028A00)
extern const u8 gUnk_084DF400[];   // compressed tiles (code_08028A00)
extern const Func gUnk_083AE6C0[]; // by gUnk_03001800.unkAA (sub_0802ACCC)
extern const u8 gUnk_0850ED78[];   // 64-byte OBJ palettes (code_08028A00)
extern const u8 gUnk_084DF024[];   // compressed tiles (code_08028A00)
extern const Func gUnk_083AE680[]; // by gUnk_03001800.unkAA (sub_0802AAD0)
extern const u8 gUnk_0850ED58[];   // 64-byte OBJ palettes (code_08028A00)
extern const u8 gUnk_084DED1C[];   // compressed tiles (code_08028A00)
extern const Func gUnk_083AE640[]; // by gUnk_03001800.unkAA (sub_0802A6AC)
extern const u8 gUnk_0850ED38[];   // 64-byte OBJ palettes (code_08028A00)
extern const u8 gUnk_084DE628[];   // compressed tiles (code_08028A00)
extern const Func gUnk_083AE600[]; // by gUnk_03001800.unkAA (sub_0802A0E8)
extern const u8 gUnk_0850ECF8[];   // 64-byte OBJ palettes (code_08028A00)
extern const u8 gUnk_084DDEA4[];   // compressed tiles (code_08028A00)
extern const Func gUnk_083AE5C0[]; // by gUnk_03001800.unkAA (sub_08029E0C)
extern const u8 gUnk_0850ED18[];   // 64-byte OBJ palettes (code_08028A00)
extern const u8 gUnk_084DE4BC[];   // compressed tiles (code_08028A00)
extern const u8 gUnk_0850ECD8[];   // 64-byte OBJ palettes (code_08028A00)
extern const u8 gUnk_084DD894[];   // compressed tiles (code_08028A00)
extern const Func gUnk_083AE580[]; // by gUnk_03001800.unkAA (sub_08029840)
extern const u8 gUnk_0850ECB8[];   // 64-byte OBJ palettes (code_08028A00)
extern const u8 gUnk_084DD648[];   // compressed tiles (code_08028A00)
extern const Func gUnk_083AE500[]; // by gUnk_03001800.unkAA (sub_08028C40)
extern const Func gUnk_083AE540[]; // by gUnk_03001800.unkAA (sub_080294B4)
extern const u8 gUnk_084DD45C[];   // compressed tiles (code_08028A00)
extern const u8 gUnk_0850EC98[];   // 64-byte OBJ palettes (code_08028A00)
extern const u8 gUnk_084DCF54[];   // compressed tiles (code_08028A00)
extern const u8 gUnk_0850EC58[];   // 64-byte OBJ palettes (code_08028A00)
extern const Func gUnk_083B27D4[]; // by gUnk_03000440.unk1B (sub_080408F4)
extern const Func gUnk_083B27EC[]; // by gUnk_03000440.unk1B (sub_08040914)
extern const Func gUnk_083B2804[]; // by gUnk_03000440.unk1B (sub_08040934)
extern const Func gUnk_083B2808[]; // by gUnk_03000440.unk1B (sub_08040954)
extern const Func gUnk_083B2810[]; // by gUnk_03000440.unk1B (sub_08040974)
extern const u8
    gLinkBattlefields[32]; // battlefields, picked at random into gUnk_03001800.unk38 (link_robattle_pick_battlefield)
extern const Func
    gUnk_083B279C[]; // run_message states by gUnk_03000440.unk4: message_open, message_dim_palettes_step,
                     // message_show_window, ..., message_run_command (runtime-checked in 03_new_game_intro)
extern const Func gUnk_083B27C0[]; // message commands, by the byte after gUnk_03000440.unk8[unkC] (message_run_command)
extern const u8 gPrizeGameSlotSets[16][6]; // prize rows per set, one set picked at random into gPrizeGameSlots
                                           // (prize_game_pick_slots)
extern const u8 gUnk_084C01C8[]; // 64 bytes of tiles copied 52 times to VRAM 0x280 (message_fill_window_tiles)
extern u8 gPrizeGameSlots[6];    // 6 bytes from gPrizeGameSlotSets (prize_game_pick_slots); = gUnk_03001800.prizeSlots
extern const u8 gPrizeGameBotPicks[16]; // record index 0-2 picked at random (prize_game_pick_prize_part)
extern const u8
    gUnk_083B4E88[][2];          // alternate font widths, used when gUnk_03000440.unk27 is set (text_render_glyph_step)
extern const u8 gUnk_084C5188[]; // alternate font glyphs, 64 bytes per character
extern const u8 gUnk_083B4C88[][2]; // per character code: [0] width in pixels (render_text_sprites_08040DB8)
extern const Func
    gLinkRobattleHandlers[];     // link Robattle game state: sub-state handlers by gGameSubState (link_robattle_update)
extern const u8 gUnk_08487524[]; // compressed tiles, message window frame style 3 (sub_08040A40)
extern const u8 gUnk_084885A8[]; // compressed tilemap, message window frame style 3 (sub_08040A40)
extern const u8 gUnk_08487630[]; // compressed tiles, message window frame style 2 (sub_08040A40)
extern const u8 gUnk_08488600[]; // compressed tilemap, message window frame style 2 (sub_08040A40)
extern const u8 gUnk_083C3B5C[][8];     // per battlefield, copied to gUnk_03001800.unk74 (load_battle_script_entry_b)
extern const Func gUnk_083B2814[];      // choice menu states by gUnk_03000440.unk29 (poll_choice_menu)
extern const Func gUnk_083B284C[];      // by gUnk_03000440.unk1B (game_state_execute_handler_a)
extern const Func gUnk_083B2864[];      // by gUnk_03000440.unk1B (game_state_execute_handler_b)
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
                                  // gUnk_083D69A0 is the y factor)
extern const u8 gUnk_0847EB80[];  // per area id (gUnk_030057E0.unk7FE), used unless unkC30 == 0xFF (area_song_id)
extern struct Unk_03005290 gUnk_03005290;
extern struct Unk_03005290 gUnk_030052B0;
extern struct Unk_03005290 gUnk_030052D0;
extern struct Unk_03005290 gUnk_030052F0;
extern const u8 gUnk_083D2ADD[]; // per animation id (gSpriteEntries[].unk30): 2 -> unkB = 0xFF, 1 -> 0, else 0x40
                                 // (sprite_set_blend_from_kind)
extern const u8 *const
    gUnk_08414394[]; // tile tables by id - 0xD0, indexed by gUnk_030057E0.unkC38[id - 0xD0] (resolve_sprite_sheet_id)
extern u8 *gUnk_030057DC;                // animated tile source for the area (animate_area_bg_tiles)
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
    *const gUnk_083D2DB0[]; // per model set, per entity: s32 count, x[4], y[4], z[4] (update_3d_entity_projections)
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
extern const u8 gUnk_080AF5FC[];     // per gUnk_030057E0.unkC32: 10 x 4 next-entry bytes (right, left, up, down) by
                                     // gUnk_03006F74->unk17 (town_map_move_cursor)
extern const u8 gUnk_080AF674[];     // same, used when gUnk_03006F74->unk18 is set (town_map_move_cursor)
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
extern const u8 gUnk_080AF980[8]; // sprite 0 frame offsets (sub_080600E0)
extern const u8 gUnk_080AFA10[];  // indexed by gUnk_03002420 (copy_text_with_lookup)
extern u8 gUnk_03002420;
extern const Func gTownMapStates[];            // sub-state handlers (town_map_dispatch)
extern const Func gGameOverStates[];           // sub-state handlers (game_over_update)
extern const Func gUnk_08483CC4[];             // sub-state handlers (save_lost_dispatch)
extern const Func gTestModeStates[];           // sub-state handlers (test_mode_dispatch)
extern const Func gUnk_08483E8C[];             // sub-state handlers (shop_list_dispatch)
extern const void *const gTownMapPlaceNames[]; // messages by gUnk_03006F74->unk17 (town_map_show_place_name)
extern const u8 gUnk_08485580[];               // message text (sub_0806142C, gUnk_03006F74->unk5 set)
extern const u8 gUnk_08485551[];               // message text (sub_0806142C, gUnk_03006F74->unk5 clear)
extern const u8 gTownMapPlacePositions[][2];   // x, y in tiles by gUnk_03006F74->unk17 (town_map_update_cursor)
extern const u16 gUnk_08483DD4[][4];           // x offsets [unk18][frame]
extern const u16 gUnk_08483DE4[][4];           // y offsets [unk18][frame]
extern const u16 gUnk_08483DF4[][4];           // animation frames [unk18][frame]
extern const u8 gUnk_08483E04[];               // frame index by gUnk_03006F74->unk3A / 10 (town_map_animate_tiles)
extern const u8 gUnk_0848552C[];               // message text (sub_08061180)
extern const Func gUnk_08483E10[];             // sub-state handlers (shop_menu_dispatch)
extern const u16 gGameOverIkkiFramesExit[];    // sprite 1 animation frames by unk1A / 6 (game_over_wipe_out)
extern u8 gTitleSkipIntro;
extern const u8 gUnk_080AFA3C[][4][2]; // x, y by [which][kind] (load_medapart_sprite_animation)
extern const u16 gUnk_08488AA4[];      // OBJ palette 1 (sub_08060FD4)
extern const u16 gUnk_0879671C[];      // BG palettes (sub_08060FD4)
extern const u8 gUnk_080AFA08[4][2];   // icon x, y in BG2 tiles (battle_menu_highlight_icons)
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
extern const u8 gUnk_080AFE96[]; // first tilemap column by gUnk_03006F74->unk5 (text_scroll_shift_row)
struct U16PtrArray8 {
    const u16 *v[8];
};
extern const u8 gUnk_080AFEE0[8];               // guess: tile block widths by type (write_tilemap_tiles_dma)
extern const u8 gUnk_080AFEE8[8];               // guess: tile block heights by type (write_tilemap_tiles_dma)
extern const u16 gUnk_080AFEF0[8];              // first tile by type (write_tilemap_tiles_dma)
extern const struct U16PtrArray8 gUnk_080AFF00; // tile index lists by type (write_tilemap_tiles_dma)
extern const u16 gUnk_080AFF20[8];              // palette bits by type (write_tilemap_tiles_dma)
extern const u8 gUnk_087A3CFC[];                // race scene BG0 tilemap (decompress_and_write_tilemap)
extern const u8 gUnk_087A3E64[];                // race scene BG2 tilemap (decompress_and_write_tilemap)
extern const u8 gUnk_087A40A0[];                // race scene BG3 tilemap (decompress_and_write_tilemap)
extern const u32 gUnk_087A1410[];               // race scene BG tiles (dma3_copy_or_decompress)
extern const u8 gUnk_087A13B0[];                // race scene BG palettes (0x60 bytes to 0x0202FA00)
extern const u8 gUnk_0850DEB8[];                // OBJ palette (0x20 bytes to 0x05000200)
struct PtrTable3 {
    const u8 *const *p[3];
};
extern const struct PtrTable3 gUnk_080AFE9C; // scene texts by gUnk_03006F74->unk5 (text_scroll_page_start)
extern const u16 gUnk_080AFA4C[16];          // OBJ palette for the link Medapart trade scene (medapart_trade_fade_in)
struct FuncTable13 {
    Func f[13];
};
extern const struct FuncTable13
    gUnk_080AFA6C;                  // link Medapart trade sub-states by gGameSubState (medapart_trade_update)
extern const s16 gSineTable[0x140]; // sin(i * 2pi / 256) * 0x100, 256 + 64 entries (cos(x) = [x + 0x40])
extern const s8 gUnk_080AFB45[];    // game mode by gUnk_03006F74->unk5 (link_menu_fade_out_exit)
extern const struct FuncTable13
    gUnk_080AFB48;                // link menu sub-states by gGameSubState (dispatch_battle_menu_and_update_counters)
extern const u8 gUnk_0848564F[];  // 0xFF-terminated message (setup_dialogue_script_from_rom)
extern const u8 gUnk_0879C06C[];  // graphics (clear_vram_bg)
extern const u8 gUnk_0879A634[];  // Medal list BG1 tilemap (sub_08064D3C)
extern const u8 gUnk_0879A78C[];  // Medal list BG2 tilemap (sub_08064D3C)
extern const u8 gUnk_0879A8BC[];  // Medal list BG3 tilemap (sub_08064D3C)
extern const u32 gUnk_08799D98[]; // Medal list BG tiles, compressed (sub_08064D3C)
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
extern const u16 gUnk_08483AA0[]; // sub_08064EFC
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
extern const Func gUnk_08483EB4[];            // Medal list screen sub-states (sub_08064C3C)
extern const struct FuncTable7 gUnk_080AFEC4; // sub-state handlers by gGameSubState (medal_transform_update)
struct S32Array3 {
    s32 v[3];
};
extern const struct S32Array3 gUnk_080AFF34; // {0x50, 0x40, 0x20}: bomb minigame debris intervals (sub_0806C500)
extern const u8 gUnk_080AFF40[8];            // bomb minigame BLDALPHA EVA steps (sub_0806C994)
extern const u8 gUnk_080AFF48[8];            // bomb minigame BLDALPHA EVB steps (sub_0806C994)
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
extern const u8 gUnk_087C8E00[];  // LZ77 BG tiles (load_bg_screen_a)
extern const u8 gUnk_087CC7BC[];  // LZ77 30x20 tilemap (load_bg_screen_a)
extern const u16 gUnk_087CCAEC[]; // BG palette, 256 colours (load_bg_screen_a)
extern const u8 gUnk_087CCCEC[];  // LZ77 BG tiles (load_bg_screen_b)
extern const u8 gUnk_087D0954[];  // LZ77 30x20 tilemap (load_bg_screen_b)
extern const u16 gUnk_087D0C80[]; // BG palette, 256 colours (load_bg_screen_b)
extern const u8 gUnk_087D0E80[];  // LZ77 BG tiles (load_bg_screen_c)
extern const u8 gUnk_087D424C[];  // LZ77 30x20 tilemap (load_bg_screen_c)
extern const u16 gUnk_087D4564[]; // BG palette, 256 colours (load_bg_screen_c)
extern s32 (*const gUnk_084860AC[])(
    u8); // sprite actions, by gSpriteEntries[].unk20 - 1: 0 = done, 0xFF = clear (update_sprite_animations_080703D8)
extern const u8 gUnk_084860C0[]; // sprite actions: frame period, by unk20 - 1
extern const s8 gUnk_080AFF50[]; // 64-entry wave offsets, by gSpriteEntries[].unk21 & 0x3F (sub_0807052C)
extern u8 gWeeklyAnimTiles[];    // animated BG tiles: 6 frames of 0x280 bytes, 0x100 copied (weekly_update_studio)
extern u8 gWeeklyAnimTiles2[];   // animated BG tiles: 6 frames of 0x280 bytes, 0x180 copied (weekly_update_studio)
extern u8 gWeeklyCycleAnimMask;
extern const Func
    gMedabotsWeeklySubStates[]; // sub-states by gGameSubState (medabots_weekly_update); [0] = medabots_weekly_init
extern s32 (*const gWeeklySpriteEffects[])(u8);
extern const s8 gWeeklyCurtainOpenTimes[8];
extern const void *const gWeeklyMessages[];
extern const u8 gUnk_08486114[];
extern const u8 gUnk_0848604C[]; // 12 bytes per a, from +0x30: 3 rows (gUnk_03001800.unkED) of x, y, end x, end row
extern const u8
    *const gUnk_0848602C[]; // text strings for the battle intro; [a + 4] read by process_text_tile_and_dma_transfer
extern const s8 gWeeklyCurtainCloseTimes[12]; // 12 frame counts (unk1A values) at which weekly_fx_right_curtain_close /
                                              // weekly_fx_left_curtain_close step
extern const u8 gCycleAnimFrameOffsets[];     // sprite_cycle_anim_update table
extern u16
    *gWeeklyFlashPalette; // palette the fade in weekly_lecture_flash reads from (set to gPaletteBackupBg = 0x0202FA00)
extern const u8 gWeeklyLectureSfxScript[13]; // weekly_lecture_run_pose script: pairs (0, n) = wait n frames, (1, id) =
                                             // play_sound_effect(id)
extern u32 (*const gWeeklyLectureSteps[])(
    void); // Medabots Lecture steps by gUnk_03001800_s.unk10.lecture.state (weekly_lecture_run_step); 1 = done
extern const struct SpriteAnimCmd *const gSpriteAnimScripts[];
extern const struct SpriteAnimGfx gSpriteAnimGfx[];
extern const u8 gUnk_08764CB0[];
extern const Func gFieldSubStates[];
extern const void *const gUnk_08411D54[];
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
extern const u8 gUnk_083D5F2C[];
extern const u8 gUnk_085FA144[];
extern const u8 gUnk_085FA5D8[];
extern const u16 gUnk_085FA4D8[];
extern const u16 gUnk_085FA620[];
extern const u16 gUnk_083D5F30[];
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
extern u16 *gUnk_083D6070[];
extern u16 *gUnk_083D607C[];
extern u8 **gUnk_083D60DC[];
extern const u8 gUnk_083D2C3D[];
extern const u8 gUnk_080AC494[];
extern const u8 gUnk_080AC498[];
extern const u8 gUnk_080AC49C[];
extern const u8 gUnk_080AC4A0[];
extern const u8 gUnk_080AC4A4[];
extern const u8 gUnk_080AC4A8[];
extern const u8 gUnk_080AC4AC[];
extern const u8 gUnk_080AC4B0[];
extern const u8 gUnk_080AC4B4[];
extern const u8 gUnk_080AC4B8[];
extern const u8 gUnk_080AC4BC[];
extern const u8 gUnk_080AC4C0[];
extern const u8 gUnk_080AC4C4[];
extern const u8 gUnk_080AC4C8[];
extern const u8 gUnk_080AC4CC[];
extern const u8 gUnk_080AC4D0[];
extern const u8 gUnk_080AC4D4[];
extern const u8 gUnk_080AC4D8[];
extern const u8 gUnk_080AC4DC[];
extern const u8 gUnk_080AC4E0[];
extern const u8 gUnk_080AC4E4[];
extern const u8 gUnk_080AC4E8[];
extern const u8 gUnk_080AC4EC[];
extern const u8 gUnk_080AC4F0[];
extern const u8 gUnk_080AC4F4[];
extern const u8 gUnk_080AC4F8[];
extern const u8 gUnk_080AC4FC[];
extern const u8 gUnk_080AC500[];
extern const u8 gUnk_080AC508[];
extern const u8 gUnk_080AC50C[];
extern const u8 gUnk_080AC510[];
extern const u8 gUnk_080AC514[];
extern const u8 gUnk_080AC518[];
extern const u8 gUnk_080AC520[];
extern const u8 gUnk_080AC524[];
extern const u8 gUnk_080AC528[];
extern const u8 gUnk_080AC534[];
extern const u8 gUnk_080AC538[];
extern const u8 gUnk_080AC53C[];
extern const u8 gUnk_080AC540[];
extern const u8 gUnk_080AC544[];
extern const u8 gUnk_080AC548[];
extern const u8 gUnk_080AC54C[];
extern const u8 gUnk_080AC550[];
extern const u8 gUnk_080AC554[];
extern const u8 gUnk_080AC558[];
extern const u8 gUnk_080AC55C[];
extern const u8 gUnk_080AC560[];
extern const u8 gUnk_080AC564[];
extern const u8 gUnk_080AC568[];
extern const u8 gUnk_080AC56C[];
extern const u8 gUnk_080AC574[];
extern const u8 gUnk_080AC578[];
extern const u8 gUnk_080AC580[];
extern const u8 gUnk_080AC584[];
extern const u8 gUnk_080AC588[];
extern const u8 gUnk_080AC58C[];
extern const u8 gUnk_080AC590[];
extern const u8 gUnk_080AC594[];
extern const u8 gUnk_080AC598[];
extern const u8 gUnk_080AC59C[];
extern const u8 gUnk_080AC5A0[];
extern u8 *gUnk_083D6088[];
extern const Func gUnk_083D5E08[];
extern const u8 gUnk_080ACB7C[];
extern const u8 gUnk_080AC5A4[];

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

extern s32
    *gUnk_083D5D84[]; // battle sequence scripts, picked by gUnk_03005350.unk1D4 & 0x3F (battle_sequence_dispatch)
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
extern u8 gUnk_02023000[];       // shop cart: quantity per sell-list entry; [0x78] = first visible entry
extern const u8 gUnk_08483E50[]; // 4 Medapart ids per shop (gUnk_03002420 * 4 + i); 0xFF ends
extern u16 gUnk_03006432;        // guess: battle field grid origin x (init_battle_field_sprites)
extern u16 gUnk_03006434;        // guess: battle field grid origin y

#endif // GUARD_VARIABLES_H
