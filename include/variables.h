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
extern u32 gMoney; // money, capped at 99999 (add_money)
extern u32 gGameState;
extern u32 gGameSubState;
extern struct Unk_03002C30 gUnk_03002C30[];
extern struct Unk_03005170 gUnk_03005170;
extern struct Unk_03005350 gUnk_03005350;
extern struct Unk_030057A0 gUnk_030057A0;
extern u8 *gMapScriptData; // current map script data (banked, see read_map_script_byte)
extern struct Unk_030057E0 gUnk_030057E0;
extern struct Unk_030064A0 gUnk_030064A0;
extern struct Unk_03006D20 gUnk_03006D20;
extern struct Unk_03007014 *gUnk_03007014;
extern struct Vec16 gBg1Scroll;     // BG1 scroll (field: map camera)
extern struct Unk_03005310 gUnk_03005310;
extern u8 gUnk_03006F40[];
extern struct Unk_030055A0 gUnk_030055A0[];
extern struct Vec16 gBg2Scroll;     // BG2 scroll
extern struct Vec16 gBg3Scroll;     // BG3 scroll
extern u8 *gUnk_030057D8; // two 4-bit entries per byte (bit 3 / bit 7: flag, bits 0-2 / 4-6: count)
extern u16 *gUnk_03006D14;
extern struct Unk_03006D38 gUnk_03006D38;
extern u8 gUnk_03003810;
extern struct Unk_03005010 gUnk_03005010;
extern s8 gUnk_03005030;  // multiplayer link active (soft_reset)
extern vu16 gUnk_03002B90; // bit 0: vblank handler running
extern s8 gUnk_03002410;  // frames since the main loop last ran (vblank_irq)
extern Func gIntrTable[14];           // RAM copy of gIntrTableTemplate, used by irq_dispatch_arm
extern u32 gIntrMain[0x200];          // RAM copy of irq_dispatch_arm (the IRQ vector)
extern Func gVBlankCallback;          // called every vblank
extern Func gVBlankOnceCallback;      // called at the next vblank, then reset to nullsub_08000840
extern Func gHBlankCallback;          // called by hblank_irq
extern struct OamData gOamBuffer[128]; // copied to OAM in vblank_body
extern struct Unk_03002414 *gUnk_03002414;
extern u8 *gUnk_03005308;
extern u32 gUnk_03000430;              // vblank_body OAM mode (0, 2)
extern u8 gUnk_03000434;               // bit 0: vblank_body skips the BG scroll registers
extern struct Vec16 gUnk_03002C2C;     // scroll added to every BG layer
extern struct Vec16 gBg0Scroll;     // BG0 scroll
extern u16 gTilemapBaseEntry;          // added to every tilemap entry by write_tilemap_to_vram_08000E94
extern u8 gDecompressBuffer[];         // EWRAM buffer the tilemap loaders decompress into
extern u16 gPaletteBackup[0x200];      // OBJ then BG palette (copy_obj_palette_to_buffer)
extern u16 gPaletteBackupBg[0x100];    // = gPaletteBackup + 0x100
extern u16 gPaletteBuffer[0x200];      // OBJ then BG palette (dma_obj_palette_to_hardware)
extern u16 gPaletteBufferBg[0x100];    // = gPaletteBuffer + 0x100
extern u32 gRngCounter;
extern u32 gRngValue;
extern u32 gRngState;
extern u8 gUnk_03000588;

// ROM data
extern const Func gIntrTableTemplate[14];
extern const u32 gRngTable[16];
extern struct SoundSongHeader *gUnk_080AFFB8[]; // song table (sound_init)
extern struct SoundSongHeader *gUnk_080B06EC[]; // sound effect table (sound_init)
extern struct SoundNoteTable gUnk_080B1788;
extern const u8 gUnk_080B1570[];
extern const u8 gUnk_080B1718[];
extern const u8 gUnk_083D28C0[];
extern const u8 gUnk_083D2908[];
extern const u8 gUnk_083D29A6[];
extern const u16 *const gUnk_083F8634[]; // 16-colour palettes
extern const u8 gUnk_083D2918[][8];
extern const u8 gUnk_083D2B8D[];
extern const u8 gUnk_083D28C3[][16];
extern const u8 gUnk_083F8B74[][2];
extern const u8 gUnk_0847E948[];
extern const struct AreaWarp *const gUnk_08413114[];
extern void (*const gMapScriptCommands[])(void); // map script command handlers
extern void (*const gMapScriptUpdates[])(void); // per-command update handlers, run each frame while unkC89 is set
extern const u8 gUnk_083D24AC[]; // indexed by the player's facing (gUnk_03002C30[47].unk21)
extern const u8 gUnk_083D28B0[]; // indexed by gUnk_030057E0.unkC5C, passed to setup_battle_sprite_terrain
extern const u8 *const gUnk_084045A8[]; // per area: tile map
extern const struct AreaGfx gUnk_083F92F4[];
extern const u8 gUnk_083D2903[];
extern const u8 gUnk_083D29E6[];
extern const u8 gUnk_085FA104[]; // LZ77 sprite tiles
extern const struct MapExit *const gUnk_0840FAF4[]; // per area: 8-byte map exit records, 0xFF-terminated
extern const u16 gUnk_083AB9D0[];
extern const u16 gUnk_083ABA88[];
extern const u8 gUnk_083ABA8C[][16];
extern const u16 gUnk_083ABAB2[][4];
extern const u16 gUnk_083ABAC2[];
extern const u8 gSoundWavePatterns[][16]; // 4-bit samples for the wave channel (sound 3)
extern const u8 gUnk_083ABA62[16]; // envelope volume -> SOUND3CNT_H volume bits (>> 8)
extern const u16 gSoundSemitoneRatios[12]; // 2^(i/12) * 0x1000
extern const u16 gSoundFinetuneRatios[128]; // 2^(i/(12*128)) * 0x1000
extern const u32 gSoundEffectTracks[6]; // track indices of the sound effect tracks (4-7, 10, 11)
extern const Func gGameStateHandlers_083AC148[];
extern const u32 gUnk_083B6410[];
extern const u8 gUnk_083B6158[][16]; // 16-byte records per Medal graphic index (byte 1 compared with a Medapart's skill, byte 7 icon)
extern const u8 gUnk_083D1BF8[];
extern const u32 gUnk_083BA4D8[];
extern const u32 gUnk_083BB9CC[][4]; // Medapart name pointers: [part id][kind: head, right arm, left arm, legs]
extern const u32 gUnk_08484444[];
extern vu32 *const gSoundFifoAddrs[]; // REG_FIFO_A, REG_FIFO_B
extern vu32 *const gSoundTimerRegs[]; // REG_TM0CNT, REG_TM1CNT (sample rate timers of FIFO A / B)
extern const u8 gSoundFifoResetBits[]; // SOUNDCNT_H high byte: FIFO A / B reset
extern const u16 gSoundFifoEnableBits[]; // SOUNDCNT_H: FIFO A / B left+right enable
extern vu16 *const gSoundFifoDmaCnt[];
extern const struct SoundTrackConfig gSoundTrackConfigs[13];
extern const u8 gSoundOutputMasks[4]; // SOUNDCNT_L high byte: clears the left/right enables of PSG channel i
extern const u8 gSoundOutputBits[4][4]; // [channel][output: 0 off, 1, 2, 3 both] SOUNDCNT_L high byte bits // REG_DMA1CNT_H, REG_DMA2CNT_H
extern u8 gUnk_030017EC;
extern u8 gUnk_03003870[];
extern u8 gUnk_03005664[];
extern const void *const gUnk_0847E8C4[]; // text pointers (guess)
extern const u32 *const gTextTable[]; // text pointers, banks 0-1 (guess)
extern const u32 *const *const gTextBankTables[]; // text pointer tables, bank 2+ (guess)
extern const s16 gUnk_083D69A0[][8]; // 16 steps; [n][0] / 16 = player sprite y offset (sub_0804DE28, guess: jump arc)
extern const u8 gUnk_083D2998[]; // map script terrain/palette id -> unkC5C/unkC69/unkC28 (sub_0804E324)
extern struct Unk_03002B70 gUnk_03002B70; // = gMoney, with the bytes after it
extern const Func gUnk_083AC248[]; // game state 0 sub-state handlers (guess: debug map viewer)
extern const Func gFieldMenuHandlers[]; // game state 1 (field pause menu) sub-state handlers
extern const void *const gUnk_083B53F8[]; // messages used by game state 0 (guess: debug menu)
extern const void *const gUnk_083CF3B0[]; // message table (run_message)
extern const u8 gUnk_083AC420[]; // orbit centre x, y per gUnk_03000440.unk51
extern const u8 gUnk_083AC432[]; // per slot sprite priority base
extern const u8 gUnk_083AC43B[]; // x, y per team select slot (9)
extern const u8 gUnk_083AC468[]; // team select: cursor slot to move to after a pick, per slot
extern const u8 gUnk_083AC44D[]; // tile x, y per team select slot (9)
extern const u8 *const gMedabotSlotDpadMoves[]; // up, down, left, right: next slot (gUnk_03000440.unk51) per slot
extern const void *const gUnk_083B4AE0[]; // tilemaps (field menu rows: open/close animation frames)
extern const void *const gUnk_083B5F80[]; // sprite animation commands (field menu cursor)
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
extern const u8 gUnk_083B7E0C[]; // 3 Medaforce ids per Medal graphic index (slots open at level 10/30/60)
extern const u8 gUnk_083B7CD4[]; // 6-byte Medaforce records: +1 skill type, +2 MF consumption, +5 icon
extern const void *const gUnk_083B7F40[]; // messages (run_message), Medals help Medaforce page
extern const void *const gUnk_083B8170[]; // messages (run_message), Medals help page 5
extern u32 gUnk_03002B68; // bit per Medal graphic index (sub_080092D4)
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
extern u8 gUnk_02020800[]; // BG tile backup (0x800 bytes of VRAM 0x06002800 while a Medawatch submenu runs)
extern const Func gMedabotsScreenHandlers[]; // game state 3 sub-state handlers
extern const Func gMedalsScreenHandlers[]; // game state 4 (Medals screen) sub-state handlers
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
extern const void *const gUnk_083B825C[]; // messages (run_message), indexed by a Medal record byte at +0x18 (guess: rotation entries)
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

#endif // GUARD_VARIABLES_H
extern const u8 gUnk_084C21BC[]; // Medal icon tiles, 0x80 bytes per graphic index
extern const u8 gUnk_084C30BC[]; // blank Medal icon tile
extern const u8 *const gUnk_083AC494[][5]; // compressed Medal sprites (load_medal_sprite)
extern const u32 gUnk_083B656C[]; // Medal Attribute names, indexed by Medal record unk4 (Ability page)
extern const u32 gUnk_083B6EC8[]; // skill type names (Shoot, Strike, ...): Medal Aim, Medaforce skill
extern const u8 *const gUnk_083B7EBC[]; // Medals help cursor layouts: count, then (x, y) tile pairs (sub_0800AA1C)
extern const u16 gUnk_083AC8AC[]; // (y, x) pairs per Medal skill row 0-7 (setup_battle_cursor_sprite_0800B5E8)
extern const Func gUnk_083AC8CC[]; // sprite 7 sub-state handlers, by gUnk_03002C30[7].unk29 (update_battle_sprite_and_check_done)
extern const Func gUnk_083AC8DC[]; // sub-state handlers run by dispatch_menu_substate_handler
extern const u8 gUnk_084C3B14[]; // tiles, 5 rows of 0x100 bytes, 0x20 per Medals tab (sub_0800B0F8)
extern const u32 gUnk_083B7338[]; // Medaforce names, indexed by Medaforce id
