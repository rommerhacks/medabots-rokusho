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
    u32 unk3C;
    u16 unk40;
    u16 unk42;
    s16 unk44;
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
    u8 filler68[0x1];
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
    u8 filler41[0x7];
};

struct Unk_03006D20
{
    u8 filler0[0xB];
    u8 unkB;
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
    u8 filler0[0xB];
    u8 unkB;
    u8 fillerC[0x34];
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

struct Unk_030057E0
{
    u8 filler0[0xC48];
    u16 unkC48;
    u16 unkC4A;
};

struct Unk_03005350
{
    u8 filler0[0xB4];
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

// Sound driver work area (0x734 bytes, cleared by sound_engine_init).
struct Unk_03007014
{
    struct SoundTrack tracks[13];
    struct SoundTrack *unk5E4;
    u8 filler5E8[0xA0];
    u32 unk688;
    u32 unk68C;
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

struct Unk_08047414
{
    u8 *unk0;
    u32 unk4;
    u32 unk8;
};

#endif // GUARD_STRUCTS_H
