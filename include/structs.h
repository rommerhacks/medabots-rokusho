#ifndef GUARD_STRUCTS_H
#define GUARD_STRUCTS_H

// Structures that are not understood yet. Fields are named by offset.

// Sound sequence track (sound_seq.c), 0x74 bytes; unk14 is the read pointer into the sequence data.
struct SoundTrack
{
    struct SoundTrack *unk0; // previous in the circular list at gUnk_03007014->unk5E4
    struct SoundTrack *unk4; // next in the circular list at gUnk_03007014->unk5E4
    u8 *unk8; // ring buffer of 0x30 bytes, write index at unk8[0x30]
    u32 unkC;
    void (*unk10)(struct SoundTrack *track);
    u8 *unk14;
    u8 *unk18;
    u8 *unk1C;
    u8 *unk20;
    u8 *unk24;
    u32 unk28;
    u32 unk2C;
    u32 unk30;
    s32 unk34;
    s32 unk38;
    u32 unk3C; // fade: frames left
    u16 unk40; // fade: current volume scale (0x1000 = full)
    u16 unk42; // fade: target volume scale
    s16 unk44; // fade: step per frame
    u16 unk46;
    u16 unk48;
    u16 unk4A;
    u16 unk4C;
    u16 unk4E;
    u8 unk50; // dirty flags
    u8 unk51;
    u8 unk52;
    u8 unk53;
    u8 unk54;
    u8 unk55;
    u8 unk56;
    u8 unk57;
    u8 unk58;
    u8 unk59;
    u8 unk5A;
    u8 envAttack; // high nibble: frames per step, low nibble: volume step
    u8 envDecay; // same layout as envAttack
    u8 envReleaseAt; // release starts when this many frames of the note remain
    u8 envRelease; // high nibble: frames per step, low nibble: steps
    u8 envCounter; // frames until the next envelope step
    s8 envStep; // volume change per step / steps left in release
    u8 envPhase; // 0 off, 1 key-on delay, 2 attack, 3 decay, 4 sustain, 5 release
    u8 envEnabled;
    u8 unk63;
    u8 unk64;
    u8 volume;
    u8 envVolume; // current envelope volume (0..15)
    u8 unk67;
    u8 unk68;
    u8 unk69;
    u8 unk6A;
    u8 unk6B;
    u8 unk6C;
    u8 unk6D;
    u8 unk6E;
    u8 unk6F;
    u8 unk70;
    u8 filler71[0x3];
};

// Header of a Direct Sound sample (pointed to by SoundMixChannel.unk0).
struct SoundSampleHeader
{
    u32 unk0;
    u16 rate; // playback rate at baseNote
    u8 fineTune; // 1/128 semitones
    u8 baseNote;
    u32 unk8;
    u32 unkC;
    s8 data[1]; // 8-bit PCM
};

// Direct Sound channel (FIFO A / B) state, 0x48 bytes, two of them in the sound work area.
struct SoundMixChannel
{
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u32 unkC;
    u32 unk10;
    u32 unk14;
    u32 unk18;
    u32 unk1C;
    u32 unk20;
    u32 unk24;
    u32 unk28;
    u32 unk2C;
    u8 unk30;
    u8 unk31;
    u8 filler32[0x2];
    u16 unk34;
    u16 unk36;
    u16 unk38;
    u8 unk3A; // 1 = FIFO A, 2 = FIFO B
    u8 unk3B;
    u8 unk3C;
    u8 filler3D[0x1];
    u8 unk3E; // state
    u8 unk3F;
    u8 unk40;
    u8 filler41[0x3];
    u32 unk44; // counts frames while no sample is set
};

struct Unk_03006D20
{
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    u8 filler4[0x4];
    s16 unk8;
    u8 unkA; // sprite slot (gUnk_03002C30 index)
    u8 unkB;
    u8 fillerC[0x4];
};

struct Unk_03000440
{
    u8 filler0[0xC];
    u16 unkC;
    u8 fillerE[0xE1];
    u8 unkEF;
};

struct Unk_03002C30
{
    u16 unk0;
    s16 unk2;
    s16 unk4;
    u16 unk6; // animation frame
    u8 filler8[0x2];
    u8 unkA;
    u8 unkB;
    u32 unkC_0:8; // x, 24.8 fixed point: fraction
    s32 unkC_8:24; // integer part
    u32 unk10_0:8; // y, 24.8 fixed point
    s32 unk10_8:24;
    u8 filler14[0x8];
    u8 unk1C;
    u8 filler1D[0x3];
    u8 unk20; // animation state (0-3)
    u8 unk21;
    u8 filler22[0x2];
    u8 unk24;
    u8 unk25;
    u8 unk26;
    u8 unk27;
    u8 unk28;
    u8 unk29;
    u8 unk2A;
    u8 unk2B; // animation set
    u8 unk2C;
    u8 unk2D;
    u8 unk2E; // on screen
    u8 filler2F[0x1];
    u16 unk30;
    u16 unk32;
    u8 filler34[0xC];
};

struct Unk_030055A0
{
    u16 unk0;
    u16 unk2;
};

struct Unk_03005170
{
    u8 unk0;
    u8 filler1[0x5];
    u8 unk6;
};

struct Unk_03001800
{
    u8 filler0[0x87];
    u8 unk87;
    u8 filler88[0x19];
    u8 unkA1;
};

struct Unk_03000BE0
{
    u8 unk0;
    u8 filler1[0x3F];
};

struct Unk_030017A0
{
    u8 filler0[0x7];
    u8 unk7;
};

struct Unk_030057A0
{
    u8 filler0[0x14];
    u8 unk14;
};

// Per-area record list (gUnk_0840FAF4), ends at mask 0. A record applies when the player steps
// from a neighbouring tile onto (x, y) in a direction whose bit is set in mask.
struct MapExit
{
    u8 x;
    u8 y;
    u8 mask; // direction 0: 2, 1: 1, 2: 8, 3: 4
    u8 value; // returned by check_room_exit_at_position (0 = none)
};

// Map object record (64 at gUnk_030057E0.unk5DC).
struct MapObject
{
    u8 x;
    u8 y;
    u16 unk2; // bits 12-15: type (8 = event), bits 0-11: event id
    u8 unk4_0:5; // sprite slot (gUnk_03002C30 index - 49)
    u8 unk4_5:1;
    u8 unk4_6:1; // has a sprite (slot + 49, shadow slot + 91)
    u8 unk4_7:1; // animates at random
    u8 unk5; // animation state
    u8 filler6[0x2];
};

struct Unk_030064A0
{
    u8 filler0[0x2];
    u8 unk2[8];
    u8 unkA[8];
    u8 unk12[8][8];
    u8 unk52;
    u8 unk53;
    u8 unk54[8];
};

struct Unk_030057E0
{
    u8 filler0[0x5DC];
    struct MapObject unk5DC[64];
    u8 filler7DC[0x20];
    u8 unk7FC;
    u8 unk7FD;
    u8 unk7FE; // area id
    u8 unk7FF;
    u16 unk800; // map width * 2 (tiles are bytes, unk810 rows are unk800 / 2 long)
    u16 unk802; // map height * 2
    u8 filler804[0xC];
    u8 unk810[0x400]; // tile map
    u8 unkC10[0x8]; // tile value -> result of check_tile_and_trigger_battle_action
    u8 fillerC18[0x8];
    u8 unkC20[0x8];
    u8 unkC28;
    u8 fillerC29[0x1];
    u8 unkC2A;
    u8 fillerC2B[0x3];
    u8 unkC2E;
    u8 unkC2F;
    u8 fillerC30[0x2];
    u8 unkC32;
    u8 fillerC33[0x4];
    u8 unkC37; // random seed
    u8 unkC38[0x10];
    u16 unkC48;
    u16 unkC4A;
    u8 fillerC4C[0x6];
    u16 unkC52;
    u16 unkC54;
    u8 unkC56; // player tile x
    u8 unkC57; // player tile y
    u8 unkC58;
    u8 unkC59;
    u8 fillerC5A[0x1];
    u8 unkC5B;
    u8 unkC5C;
    u8 unkC5D;
    u8 unkC5E;
    u8 unkC5F;
    u8 unkC60;
    u8 fillerC61[0x6];
    u8 unkC67;
    u8 fillerC68[0x1];
    u8 unkC69;
    u8 fillerC6A[0x4];
    u16 unkC6E;
    u16 unkC70;
    u8 unkC72;
    u8 unkC73;
    u8 unkC74;
    u8 unkC75;
    u8 unkC76;
    u8 fillerC77[0xC];
    u8 unkC83;
    u8 unkC84;
    u8 fillerC85[0x3];
    u8 unkC88;
    u8 unkC89;
    u16 unkC8A; // map script read offset
    u16 unkC8C;
    u16 unkC8E; // current map script id
    u16 unkC90;
    u8 unkC92; // current map script command (gMapScriptCommands index)
    u8 unkC93;
    u8 unkC94[0x10]; // map script command arguments (read_map_script_bytes)
    u8 unkCA4[0x10];
    u8 unkCB4; // index of the map object running the script (unk5DC)
    u8 unkCB5;
    u8 fillerCB6[0x6];
    s8 unkCBC;
    s8 unkCBD;
};

struct Unk_03005310
{
    u8 filler0[0x1];
    u8 unk1;
    u8 filler2[0x2];
    u32 unk4; // frame counter
    u8 filler8[0x30];
    u8 unk38;
};

struct Unk_03006D38
{
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    u8 filler4[0x2];
    u8 unk6;
};

// Three copies at gUnk_03004C30, gUnk_0300057C, gUnk_03001C04 (camera / scroll position).
struct Vec16
{
    s16 x;
    s16 y;
};

struct Unk_03005350
{
    u8 filler0[0x40];
    s32 unk40; // position x, y, z
    s32 unk44;
    s32 unk48;
    u8 filler4C[0x68];
    s32 unkB4;
    s32 unkB8;
};

// Table pointed to by the sound work area at 0x728: note -> sample/frequency entry.
struct SoundNoteTable
{
    u16 count;
    u16 base;
    u32 unk4;
    u8 *entries[1]; // count entries
};

// Per-track configuration (gSoundTrackConfigs, one per SoundTrack).
struct SoundTrackConfig
{
    u32 unk0; // -> SoundTrack.unkC
    void (*unk4)(struct SoundTrack *track); // -> SoundTrack.unk10
    u8 unk8; // -> SoundTrack.unk64
    u8 unk9; // ring buffer index (work+0x5EC), 0xFF = none
    u8 fillerA[2];
};

// Song / sound effect header (tables at gUnk_03007014->unk688 / unk68C).
struct SoundSongHeader
{
    u16 trackMask; // bit 11 - i set: track i is used (0x800 = track 0)
    u8 priority; // copied to SoundTrack.unk6D
    u8 unk3;
    u8 *tracks[1]; // one sequence pointer per set bit, in track order
};

// Sound driver work area (0x734 bytes, cleared by sound_engine_init).
struct Unk_03007014
{
    struct SoundTrack tracks[13];
    struct SoundTrack *unk5E4;
    u32 unk5E8;
    u8 unk5EC[3][0x34]; // SoundTrack.unk8 ring buffers (0x30 bytes + write index)
    struct SoundSongHeader **unk688; // songs
    struct SoundSongHeader **unk68C; // sound effects
    struct SoundMixChannel unk690;
    struct SoundMixChannel unk6D8;
    u32 unk720;
    u32 unk724;
    struct SoundNoteTable *unk728;
    u8 unk72C; // flags
    u8 unk72D;
    u8 unk72E;
    u8 unk72F;
    u16 unk730;
    u8 filler732[0x2];
};

// Area warp record (gUnk_08413114, one 0xFF-terminated list per area): stepping onto (x, y)
// moves the player to (destX, destY) of area.
struct AreaWarp
{
    u8 x;
    u8 y;
    u8 area;
    u8 dir; // low 3 bits: facing after the warp
    u8 unk4;
    u8 unk5;
    u8 destX;
    u8 destY;
};

// Per-area graphics record (gUnk_083F92F4, indexed by area id).
struct AreaGfx
{
    const void *unk0; // LZ77 data, decompressed to gUnk_03006D14
    u32 unk4;
    u32 unk8;
};

struct Unk_08047414
{
    u8 *unk0;
    u32 unk4;
    u32 unk8;
};

#endif // GUARD_STRUCTS_H
