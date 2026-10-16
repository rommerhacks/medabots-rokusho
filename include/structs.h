#ifndef GUARD_STRUCTS_H
#define GUARD_STRUCTS_H

// Structures that are not understood yet. Fields are named by offset.

// Sound sequence track (code_0806F3F0); unk14 is the read pointer into the sequence data.
struct SoundTrack
{
    u8 filler0[0x14];
    u8 *unk14;
    u8 *unk18;
    u8 *unk1C;
    u8 *unk20;
    u32 unk24;
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
    u8 filler4E[0x2];
    u8 unk50; // dirty flags
    u8 filler51[0x1];
    u8 unk52;
    u8 unk53;
    u8 filler54[0x1];
    u8 unk55;
    u8 unk56;
    u8 unk57;
    u8 unk58;
    u8 unk59;
    u8 unk5A;
    u8 unk5B;
    u8 unk5C;
    u8 unk5D;
    u8 unk5E;
    u8 unk5F; // envelope step counter
    s8 unk60; // envelope step delta
    u8 unk61; // envelope phase (1..5)
    u8 unk62;
    u8 unk63;
    u8 unk64;
    u8 unk65;
    u8 unk66; // envelope volume (0..15)
    u8 unk67;
    u8 filler68[0x1];
    u8 unk69;
    u8 unk6A;
    u8 filler6B[0x1];
    u8 unk6C;
    u8 filler6D[0x1];
    u8 unk6E;
};

struct UnkSound_08073CA4
{
    u8 filler0[0x3E];
    u8 unk3E;
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
    u32 entries[1]; // count entries
};

// Sound driver work area (0x734 bytes, cleared by sound_engine_init).
struct Unk_03007014
{
    u8 filler0[0x688];
    u32 unk688;
    u32 unk68C;
    u8 unk690[0x3A]; // channel at 0x690
    u8 unk6CA;
    u8 filler6CB[0xD];
    u8 unk6D8[0x3A]; // channel at 0x6D8
    u8 unk712;
    u8 filler713[0xD];
    u32 unk720;
    u32 unk724;
    struct SoundNoteTable *unk728;
    u8 filler72C[0x8];
};

struct Unk_08047414
{
    u8 *unk0;
    u32 unk4;
    u32 unk8;
};

#endif // GUARD_STRUCTS_H
