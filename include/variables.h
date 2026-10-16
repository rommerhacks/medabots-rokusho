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
extern u32 gUnk_03002B70;
extern u32 gGameState;
extern u32 gGameSubState;
extern struct Unk_03002C30 gUnk_03002C30[];
extern struct Unk_03005170 gUnk_03005170;
extern struct Unk_03005350 gUnk_03005350;
extern struct Unk_030057A0 gUnk_030057A0;
extern struct Unk_030057E0 gUnk_030057E0;
extern struct Unk_03006D20 gUnk_03006D20;
extern struct Unk_03007014 *gUnk_03007014;
extern struct Vec16 gUnk_03004C30;
extern struct Unk_03005310 gUnk_03005310;
extern struct Unk_030055A0 gUnk_030055A0[];
extern struct Vec16 gUnk_0300057C;
extern struct Vec16 gUnk_03001C04;
extern u8 *gUnk_030057D8; // two 4-bit entries per byte (bit 3 / bit 7: flag, bits 0-2 / 4-6: count)
extern u16 *gUnk_03006D14;
extern struct Unk_03006D38 gUnk_03006D38;

// ROM data
extern const u8 gUnk_083D28C0[];
extern const u8 gUnk_083D2908[];
extern const u8 gUnk_083D2918[][8];
extern const u8 gUnk_083D2B8D[];
extern const u8 gUnk_083D28C3[][16];
extern const u8 gUnk_083F8B74[][2];
extern const u8 gUnk_0847E948[];
extern const u8 *const gUnk_08413114[];
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

#endif // GUARD_VARIABLES_H
