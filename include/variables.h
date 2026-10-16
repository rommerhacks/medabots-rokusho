#ifndef GUARD_VARIABLES_H
#define GUARD_VARIABLES_H

// RAM variables and ROM data. Addresses are in symbols.ld.

typedef void (*Func)(void);

// RAM
extern struct Unk_03000440 gUnk_03000440;
extern u8 gUnk_03000590[];
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
extern struct Vec16 gUnk_03004C30;
extern struct Unk_03005310 gUnk_03005310;
extern u8 gUnk_03006F40[];
extern struct Unk_030055A0 gUnk_030055A0[];
extern struct Vec16 gUnk_0300057C;
extern struct Vec16 gUnk_03001C04;
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
extern u16 gTilemapBaseEntry;          // added to every tilemap entry by write_tilemap_to_vram_08000E94
extern u8 gDecompressBuffer[];         // EWRAM buffer the tilemap loaders decompress into
extern u16 gPaletteBackup[0x200];      // OBJ then BG palette (copy_obj_palette_to_buffer)
extern u16 gPaletteBackupBg[0x100];    // = gPaletteBackup + 0x100
extern u16 gPaletteBuffer[0x200];      // OBJ then BG palette (dma_obj_palette_to_hardware)
extern u16 gPaletteBufferBg[0x100];    // = gPaletteBuffer + 0x100
extern u32 gRngCounter;
extern u32 gRngValue;
extern u32 gRngState;

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
extern const u32 gUnk_083BA4D8[];
extern const u32 gUnk_083BB9CC[][4];
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

#endif // GUARD_VARIABLES_H
