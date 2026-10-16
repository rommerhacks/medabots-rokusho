#ifndef GUARD_STRUCTS_H
#define GUARD_STRUCTS_H

// Structures that are not understood yet. Fields are named by offset.

// Sound sequence track (code_0806F3F0); unk14 is the read pointer into the sequence data.
struct SoundTrack
{
    u8 filler0[0x14];
    u8 *unk14;
    u8 filler18[0x8];
    u8 *unk20;
    u8 filler24[0x8];
    u32 unk2C;
    u8 filler30[0x1C];
    u16 unk4C;
    u8 filler4E[0x7];
    u8 unk55;
    u8 filler56[0xD];
    u8 unk63;
    u8 filler64[0x6];
    u8 unk6A;
    u8 filler6B[0x3];
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
};

struct Unk_03002C30
{
    u8 filler0[0xB];
    u8 unkB;
    u8 fillerC[0x34];
};

#endif // GUARD_STRUCTS_H
