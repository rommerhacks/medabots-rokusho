#include "global.h"

void sub_08028A00(void)
{
    u32 i;

    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03001800.unkD2[i])
        {
            gUnk_03001800.unkAA += 2;
            return;
        }
    }
    gUnk_03001800.unkAA++;
}

void sub_08028A38(void)
{
    u32 i;

    lz_decompress_dispatch(gUnk_084DCF54, (void *)0x06016000);
    CpuFastSet(gUnk_0850EC58, (void *)0x050002E0, 8);
    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        gUnk_03002C30[0x21 + i].unk0 = 0xC404;
        gUnk_03002C30[0x21 + i].unk1C = 0;
        gUnk_03002C30[0x21 + i].unk2 = gUnk_03002C30[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk2;
        gUnk_03002C30[0x21 + i].unk4 = gUnk_03002C30[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk4 - 4;
        gUnk_03002C30[0x21 + i].unkA = 7;
        gUnk_03002C30[0x21 + i].unkB = 0xF0;
        gUnk_03002C30[0x21 + i].unk23 = 0;
        switch (gUnk_03001800.unk51)
        {
        case 0:
            gUnk_03002C30[0x21 + i].unk6 = 0x6F00;
            break;
        case 1:
            gUnk_03002C30[0x21 + i].unk6 = 0x6F03;
            break;
        case 2:
            gUnk_03002C30[0x21 + i].unk6 = 0x6F01;
            break;
        case 3:
            gUnk_03002C30[0x21 + i].unk6 = 0x6F02;
            break;
        case 4:
            gUnk_03002C30[0x21 + i].unk6 = 0x6F05;
            break;
        case 5:
            gUnk_03002C30[0x21 + i].unk6 = 0x6F04;
            break;
        }
    }
    play_sound_effect(0x5B);
    gUnk_03001800.unkAA++;
}

void sub_08028B58(void)
{
    u32 done = 0;
    u32 i;

    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03001800.unkD2[i] && advance_sprite_anim_frame(0x21 + i, 0))
            done = 1;
    }
    if (done)
    {
        gUnk_03000440.unk86 = 0x3C;
        gUnk_03001800.unkAA++;
    }
}

void sub_08028BA8(void)
{
    clear_battle_sprite_slot(0x21, 3);
    switch (gUnk_03001800.unk51)
    {
    case 0:
        gUnk_03001800.unkA6 = 0x46;
        break;
    case 1:
        gUnk_03001800.unkA6 = 0x49;
        break;
    case 2:
        gUnk_03001800.unkA6 = 0x47;
        break;
    case 3:
        gUnk_03001800.unkA6 = 0x48;
        break;
    case 4:
        gUnk_03001800.unkA6 = 0x5D;
        break;
    case 5:
        gUnk_03001800.unkA6 = 0x5E;
        break;
    }
    gUnk_03001800.unkAA++;
}

void sub_08028C40(void)
{
    gUnk_03001800.unkB5 = 0;
    gUnk_083AE500[gUnk_03001800.unkAA]();
}

void sub_08028C68(void)
{
    switch (gUnk_03000590[gUnk_03001800.unk87].unkA8[0])
    {
    case 0xD:
        gUnk_03001800.unk51 = 0;
        break;
    case 0xF:
        gUnk_03001800.unk51 = 1;
        break;
    case 0x11:
        gUnk_03001800.unk51 = 2;
        break;
    case 0x13:
        gUnk_03001800.unk51 = 3;
        break;
    }
    gUnk_03001800.unkAA++;
}

void sub_08028CC8(void)
{
    switch (gUnk_03001800.unk51)
    {
    case 0:
        lz_decompress_dispatch(gUnk_084DBEE4, (void *)0x06014800);
        CpuFastSet(gUnk_0850EBD8, (void *)0x050002E0, 8);
        gUnk_03002C30[0x21].unk2E = 0x5B;
        break;
    case 1:
        lz_decompress_dispatch(gUnk_084DC100, (void *)0x06014800);
        CpuFastSet(gUnk_0850EBF8, (void *)0x050002E0, 8);
        gUnk_03002C30[0x21].unk2E = 0x5B;
        break;
    case 2:
        lz_decompress_dispatch(gUnk_084DC544, (void *)0x06014800);
        CpuFastSet(gUnk_0850EC18, (void *)0x050002E0, 8);
        gUnk_03002C30[0x21].unk2E = 0x5B;
        break;
    case 3:
        lz_decompress_dispatch(gUnk_084DC7D0, (void *)0x06014800);
        CpuFastSet(gUnk_0850EC38, (void *)0x050002E0, 8);
        gUnk_03002C30[0x21].unk2E = 0x5C;
        break;
    }
    gUnk_03002C30[0x21].unk0 = 0xC604;
    gUnk_03002C30[0x21].unk1C = 0;
    gUnk_03002C30[0x21].unk4 = 0xE0;
    gUnk_03002C30[0x21].unkA = 7;
    gUnk_03002C30[0x21].unk8 = 0x40;
    gUnk_03002C30[0x21].unk9 = 0x40;
    gUnk_03002C30[0x21].unk18 = 0;
    gUnk_03002C30[0x21].unkB = 0xF0;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[gUnk_03002C30[0x21].unk2E], 0x21);
    if (gUnk_03001800.unkF8 & 1)
    {
        gUnk_03002C30[0x21].unk2 = 0xB8;
    }
    else
    {
        gUnk_03002C30[0x21].unk0 |= 0x1000;
        gUnk_03002C30[0x21].unk2 = 0x38;
    }
    play_sound_effect(0x61);
    gUnk_03001800.unkAA++;
}

INCLUDE_ASM("asm/nonmatching/code_08028A00", sub_08028E84);
INCLUDE_ASM("asm/nonmatching/code_08028A00", sub_08028F4C);
INCLUDE_ASM("asm/nonmatching/code_08028A00", sub_08029004);
INCLUDE_ASM("asm/nonmatching/code_08028A00", sub_08029178);
INCLUDE_ASM("asm/nonmatching/code_08028A00", sub_080291E0);
INCLUDE_ASM("asm/nonmatching/code_08028A00", sub_080292D4);
INCLUDE_ASM("asm/nonmatching/code_08028A00", sub_08029354);
INCLUDE_ASM("asm/nonmatching/code_08028A00", sub_080294B4);
INCLUDE_ASM("asm/nonmatching/code_08028A00", sub_080294DC);
INCLUDE_ASM("asm/nonmatching/code_08028A00", sub_08029600);
INCLUDE_ASM("asm/nonmatching/code_08028A00", sub_08029680);
INCLUDE_ASM("asm/nonmatching/code_08028A00", sub_0802976C);
INCLUDE_ASM("asm/nonmatching/code_08028A00", sub_080297EC);
INCLUDE_ASM("asm/nonmatching/code_08028A00", sub_08029840);
INCLUDE_ASM("asm/nonmatching/code_08028A00", sub_08029868);
INCLUDE_ASM("asm/nonmatching/code_08028A00", sub_08029984);
INCLUDE_ASM("asm/nonmatching/code_08028A00", sub_08029A14);
INCLUDE_ASM("asm/nonmatching/code_08028A00", sub_08029B04);
INCLUDE_ASM("asm/nonmatching/code_08028A00", sub_08029B84);
INCLUDE_ASM("asm/nonmatching/code_08028A00", init_battle_bot_display_digits);
INCLUDE_ASM("asm/nonmatching/code_08028A00", sub_08029D28);
INCLUDE_ASM("asm/nonmatching/code_08028A00", sub_08029E0C);
INCLUDE_ASM("asm/nonmatching/code_08028A00", sub_08029E34);
INCLUDE_ASM("asm/nonmatching/code_08028A00", sub_08029F50);
INCLUDE_ASM("asm/nonmatching/code_08028A00", sub_08029FE0);
INCLUDE_ASM("asm/nonmatching/code_08028A00", sub_0802A0E8);
INCLUDE_ASM("asm/nonmatching/code_08028A00", sub_0802A110);
INCLUDE_ASM("asm/nonmatching/code_08028A00", sub_0802A2D4);
INCLUDE_ASM("asm/nonmatching/code_08028A00", sub_0802A31C);
INCLUDE_ASM("asm/nonmatching/code_08028A00", sub_0802A360);
INCLUDE_ASM("asm/nonmatching/code_08028A00", sub_0802A440);
INCLUDE_ASM("asm/nonmatching/code_08028A00", sub_0802A4C4);
INCLUDE_ASM("asm/nonmatching/code_08028A00", sub_0802A534);
INCLUDE_ASM("asm/nonmatching/code_08028A00", sub_0802A5C0);
INCLUDE_ASM("asm/nonmatching/code_08028A00", sub_0802A6AC);
INCLUDE_ASM("asm/nonmatching/code_08028A00", sub_0802A6D4);
INCLUDE_ASM("asm/nonmatching/code_08028A00", sub_0802A824);
INCLUDE_ASM("asm/nonmatching/code_08028A00", sub_0802A9B8);
INCLUDE_ASM("asm/nonmatching/code_08028A00", sub_0802AAD0);
INCLUDE_ASM("asm/nonmatching/code_08028A00", sub_0802AAF8);
INCLUDE_ASM("asm/nonmatching/code_08028A00", sub_0802AC7C);
INCLUDE_ASM("asm/nonmatching/code_08028A00", sub_0802ACCC);
INCLUDE_ASM("asm/nonmatching/code_08028A00", sub_0802ACF4);
INCLUDE_ASM("asm/nonmatching/code_08028A00", sub_0802AE88);
INCLUDE_ASM("asm/nonmatching/code_08028A00", sub_0802AECC);
INCLUDE_ASM("asm/nonmatching/code_08028A00", sub_0802AF6C);
INCLUDE_ASM("asm/nonmatching/code_08028A00", sub_0802AFB0);
INCLUDE_ASM("asm/nonmatching/code_08028A00", sub_0802B000);
INCLUDE_ASM("asm/nonmatching/code_08028A00", sub_0802B028);
INCLUDE_ASM("asm/nonmatching/code_08028A00", sub_0802B184);
INCLUDE_ASM("asm/nonmatching/code_08028A00", sub_0802B258);
INCLUDE_ASM("asm/nonmatching/code_08028A00", sub_0802B388);
INCLUDE_ASM("asm/nonmatching/code_08028A00", sub_0802B3CC);
INCLUDE_ASM("asm/nonmatching/code_08028A00", sub_0802B460);
INCLUDE_ASM("asm/nonmatching/code_08028A00", sub_0802B4D8);
INCLUDE_ASM("asm/nonmatching/code_08028A00", sub_0802B5AC);
INCLUDE_ASM("asm/nonmatching/code_08028A00", sub_0802B7E8);
INCLUDE_ASM("asm/nonmatching/code_08028A00", sub_0802B810);
INCLUDE_ASM("asm/nonmatching/code_08028A00", sub_0802B8BC);
INCLUDE_ASM("asm/nonmatching/code_08028A00", sub_0802B980);
INCLUDE_ASM("asm/nonmatching/code_08028A00", sub_0802BA2C);
INCLUDE_ASM("asm/nonmatching/code_08028A00", sub_0802BAAC);
INCLUDE_ASM("asm/nonmatching/code_08028A00", sub_0802BB24);
INCLUDE_ASM("asm/nonmatching/code_08028A00", sub_0802BBA8);
INCLUDE_ASM("asm/nonmatching/code_08028A00", sub_0802BC1C);
INCLUDE_ASM("asm/nonmatching/code_08028A00", sub_0802BC60);
INCLUDE_ASM("asm/nonmatching/code_08028A00", sub_0802BD6C);
INCLUDE_ASM("asm/nonmatching/code_08028A00", sub_0802BD94);
INCLUDE_ASM("asm/nonmatching/code_08028A00", sub_0802BE44);
INCLUDE_ASM("asm/nonmatching/code_08028A00", sub_0802BEEC);
INCLUDE_ASM("asm/nonmatching/code_08028A00", sub_0802BF9C);
INCLUDE_ASM("asm/nonmatching/code_08028A00", sub_0802C0DC);
INCLUDE_ASM("asm/nonmatching/code_08028A00", sub_0802C1A4);
INCLUDE_ASM("asm/nonmatching/code_08028A00", sub_0802C24C);
INCLUDE_ASM("asm/nonmatching/code_08028A00", sub_0802C2AC);
INCLUDE_ASM("asm/nonmatching/code_08028A00", sub_0802C2D4);
INCLUDE_ASM("asm/nonmatching/code_08028A00", sub_0802C440);
INCLUDE_ASM("asm/nonmatching/code_08028A00", sub_0802C4F8);
INCLUDE_ASM("asm/nonmatching/code_08028A00", sub_0802C588);
INCLUDE_ASM("asm/nonmatching/code_08028A00", sub_0802C644);
INCLUDE_ASM("asm/nonmatching/code_08028A00", sub_0802C66C);
INCLUDE_ASM("asm/nonmatching/code_08028A00", sub_0802C790);
INCLUDE_ASM("asm/nonmatching/code_08028A00", sub_0802C820);
INCLUDE_ASM("asm/nonmatching/code_08028A00", sub_0802C864);
INCLUDE_ASM("asm/nonmatching/code_08028A00", sub_0802C960);
