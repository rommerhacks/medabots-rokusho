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

void sub_08028E84(void)
{
    process_sprite_anim_commands(gUnk_083B5F80[gUnk_03002C30[0x21].unk2E], 0x21);
    if (gUnk_03002C30[0x21].unk4 == 0x40)
    {
        gUnk_03000440.unk86 = 0x3C;
        gUnk_03001800.unkAA++;
        return;
    }
    gUnk_03002C30[0x21].unk4 = (gUnk_03002C30[0x21].unk4 + 2) & 0xFF;
    if (gUnk_03001800.unkF8 & 1)
    {
        if (gUnk_03001800.unk51 != 3)
            gUnk_03002C30[gUnk_03000440.unk12F].unk18 = (gUnk_03002C30[gUnk_03000440.unk12F].unk18 - 0x10) & 0x3FF;
    }
    else
    {
        if (gUnk_03001800.unk51 != 3)
            gUnk_03002C30[gUnk_03000440.unk12F].unk18 = (gUnk_03002C30[gUnk_03000440.unk12F].unk18 + 0x10) & 0x3FF;
    }
}

void sub_08028F4C(void)
{
    process_sprite_anim_commands(gUnk_083B5F80[gUnk_03002C30[0x21].unk2E], 0x21);
    if (gUnk_03001800.unkF8 & 1)
    {
        if (gUnk_03001800.unk51 != 3)
            gUnk_03002C30[0x21].unk18 = (gUnk_03002C30[0x21].unk18 - 0x10) & 0x3FF;
    }
    else
    {
        if (gUnk_03001800.unk51 != 3)
            gUnk_03002C30[0x21].unk18 = (gUnk_03002C30[0x21].unk18 + 0x10) & 0x3FF;
    }
    if (gUnk_03000440.unk89 == 0 && (*(u8 *)&gRepeatKeys & 1))
        gUnk_03001800.unkAA++;
    else if (gUnk_03000440.unk86)
        gUnk_03000440.unk86--;
    else
        gUnk_03001800.unkAA++;
}

void sub_08029004(void)
{
    lz_decompress_dispatch(gUnk_084CCE48, (void *)0x06014800);
    CpuFastSet(gUnk_0850E358, (void *)0x050002E0, 8);
    gUnk_03002C30[0x21].unk8 = 0x40;
    gUnk_03002C30[0x21].unk9 = 0x40;
    gUnk_03002C30[0x21].unk18 = 0;
    gUnk_03002C30[0x21].unkB = 0xF0;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x23], 0x21);
    CpuSet(&gUnk_03002C30[0x21], &gUnk_03002C30[0x22], 0x20);
    CpuSet(&gUnk_03002C30[0x21], &gUnk_03002C30[0x23], 0x20);
    CpuSet(&gUnk_03002C30[0x21], &gUnk_03002C30[0x24], 0x20);
    CpuSet(&gUnk_03002C30[0x21], &gUnk_03002C30[0x25], 0x20);
    gUnk_03002C30[0x21].unk24 = 0;
    gUnk_03002C30[0x22].unk24 = 2;
    gUnk_03002C30[0x22].unk25 = 0x1C;
    gUnk_03002C30[0x22].unk2 -= 0x10;
    gUnk_03002C30[0x22].unk4 -= 0x10;
    gUnk_03002C30[0x23].unk24 = 2;
    gUnk_03002C30[0x23].unk25 = 4;
    gUnk_03002C30[0x23].unk2 += 0x10;
    gUnk_03002C30[0x23].unk4 -= 0x10;
    gUnk_03002C30[0x24].unk24 = 2;
    gUnk_03002C30[0x24].unk25 = 0x14;
    gUnk_03002C30[0x24].unk2 -= 0x10;
    gUnk_03002C30[0x24].unk4 += 0x10;
    gUnk_03002C30[0x25].unk24 = 2;
    gUnk_03002C30[0x25].unk25 = 0xC;
    gUnk_03002C30[0x25].unk2 += 0x10;
    gUnk_03002C30[0x25].unk4 += 0x10;
    gUnk_03001800.unkAA++;
}

void sub_08029178(void)
{
    u32 i;

    for (i = 0; i <= 4; i++)
    {
        process_sprite_anim_commands(gUnk_083B5F80[0x23], 0x21 + i);
        update_sprite_animation_position(0x21 + i);
    }
    if (gUnk_03002C30[0x21].unk22 == 0xFF)
    {
        clear_battle_sprite_slot(0x21, 5);
        gUnk_03000440.unk86 = 0x3C;
        gUnk_03001800.unkAA++;
    }
}

void sub_080291E0(void)
{
    u32 i;

    lz_decompress_dispatch(gUnk_084DD45C, (void *)0x06014800);
    CpuFastSet(gUnk_0850EC98, (void *)0x050002E0, 8);
    sub_0803836C();
    gUnk_03001800.unk60 = sub_08032FC4(gUnk_03001800.unk87);
    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03000590[gUnk_03001800.unk60 + i].unk40 == 0)
            continue;
        if (gUnk_03000590[gUnk_03001800.unk60 + i].parts[0].unk11 == 0)
            continue;
        gUnk_03001800.unkD2[i] = 1;
        gUnk_03002C30[0x21 + i].unk0 = 0xC404;
        gUnk_03002C30[0x21 + i].unk1C = 0;
        gUnk_03002C30[0x21 + i].unk2 = gUnk_03002C30[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk2;
        gUnk_03002C30[0x21 + i].unk4 = gUnk_03002C30[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk4 - 4;
        gUnk_03002C30[0x21 + i].unkA = 7;
        gUnk_03002C30[0x21 + i].unkB = 0xF0;
        init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x5F], 0x21 + i);
    }
    gUnk_03001800.unkAA++;
}

void sub_080292D4(void)
{
    u32 done = 0;
    u32 i;

    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03001800.unkD2[i])
        {
            process_sprite_anim_commands(gUnk_083B5F80[0x5F], 0x21 + i);
            if (gUnk_03002C30[0x21 + i].unk22 == 0xFF)
                done = 1;
        }
    }
    if (done)
    {
        clear_battle_sprite_slot(0x21, 3);
        gUnk_03001800.unkAA++;
    }
}

void sub_08029354(void)
{
    u32 i;

    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        switch (gUnk_03001800.unk51)
        {
        case 0:
            gUnk_03000590[gUnk_03001800.unk60 + i].unkCF |= 1;
            if (gUnk_03000590[gUnk_03001800.unk60 + i].unkC9 == 0xD)
                goto call_0xD;
            if (gUnk_03000590[gUnk_03001800.unk60 + i].unkC9 != 0xE)
                break;
        call_0xD:
            sub_08038394(gUnk_03001800.unk60 + i, 1);
            break;
        case 1:
            gUnk_03000590[gUnk_03001800.unk60 + i].unkCF |= 8;
            if (gUnk_03000590[gUnk_03001800.unk60 + i].unkC9 == 0xF)
                goto call_0xF;
            if (gUnk_03000590[gUnk_03001800.unk60 + i].unkC9 != 0x10)
                break;
        call_0xF:
            sub_08038394(gUnk_03001800.unk60 + i, 1);
            break;
        case 2:
            gUnk_03000590[gUnk_03001800.unk60 + i].unkCF |= 2;
            if (gUnk_03000590[gUnk_03001800.unk60 + i].unkC9 == 0x11)
                goto call_0x11;
            if (gUnk_03000590[gUnk_03001800.unk60 + i].unkC9 != 0x12)
                break;
        call_0x11:
            sub_08038394(gUnk_03001800.unk60 + i, 1);
            break;
        case 3:
            gUnk_03000590[gUnk_03001800.unk60 + i].unkCF |= 4;
            if (gUnk_03000590[gUnk_03001800.unk60 + i].unkC9 == 0x13)
                goto call_0x13;
            if (gUnk_03000590[gUnk_03001800.unk60 + i].unkC9 != 0x14)
                break;
        call_0x13:
            sub_08038394(gUnk_03001800.unk60 + i, 1);
            break;
        }
    }
    gUnk_03001800.unkAA++;
}

void sub_08029464(void)
{
    switch (gUnk_03001800.unk51)
    {
    case 0:
        gUnk_03001800.unkA6 = 0x55;
        break;
    case 1:
        gUnk_03001800.unkA6 = 0x58;
        break;
    case 2:
        gUnk_03001800.unkA6 = 0x56;
        break;
    case 3:
        gUnk_03001800.unkA6 = 0x57;
        break;
    }
    gUnk_03001800.unkAA++;
}

void sub_080294B4(void)
{
    gUnk_03001800.unkB5 = 0;
    gUnk_083AE540[gUnk_03001800.unkAA]();
}

void sub_080294DC(void)
{
    lz_decompress_dispatch(gUnk_084DD648, (void *)0x06014800);
    CpuFastSet(gUnk_0850ECB8, (void *)0x050002E0, 8);
    CpuFastSet(gUnk_084E30B8, (void *)0x050002C0, 8);
    gUnk_03002C30[0x21].unk0 = 0xC604;
    gUnk_03002C30[0x21].unk1C = 0;
    gUnk_03002C30[0x21].unk4 = 0xE0;
    gUnk_03002C30[0x21].unkA = 7;
    gUnk_03002C30[0x21].unk8 = 0x40;
    gUnk_03002C30[0x21].unk9 = 0x40;
    gUnk_03002C30[0x21].unk18 = 0;
    gUnk_03002C30[0x21].unkB = 0xF0;
    gUnk_03002C30[0x21].unk28 = 0;
    gUnk_03002C30[0x21].unk2E = 0x5B;
    gUnk_03002C30[0x21].unk29 = 6;
    gUnk_03002C30[0x21].unk2B = 0x20;
    gUnk_03002C30[0x21].unk2C = 0xC0;
    gUnk_03002C30[0x21].unk2D = 0;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[gUnk_03002C30[0x21].unk2E], 0x21);
    if (gUnk_03001800.unkF8 & 1)
        gUnk_03002C30[0x21].unk2 = 0xB8;
    else
        gUnk_03002C30[0x21].unk2 = 0x38;
    gUnk_03001800.unk51 = 0;
    gUnk_03001800.unkAA++;
}

void sub_08029600(void)
{
    u32 found = 0;
    u32 i;

    sub_0803836C();
    gUnk_03001800.unk60 = sub_08032FC4(gUnk_03001800.unk87);
    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03000590[gUnk_03001800.unk60 + i].unk40 == 0)
            continue;
        if (gUnk_03000590[gUnk_03001800.unk60 + i].parts[0].unk11 == 0)
            continue;
        if (gUnk_03000590[gUnk_03001800.unk60 + i].unkC9 == 0)
            continue;
        found = 1;
        gUnk_03001800.unkD2[i] = found;
    }
    if (!found)
        gUnk_03001800.unkAA++;
    else
        gUnk_03001800.unkAA += 2;
}

void sub_08029680(void)
{
    u32 i;

    lz_decompress_dispatch(gUnk_084D55D0, (void *)0x06014800);
    CpuFastSet(gUnk_0850E6B8, (void *)0x050002E0, 8);
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
        init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x3C], 0x21 + i);
        if (gUnk_03001800.unkF8 & 1)
            gUnk_03002C30[0x21 + i].unk0 |= 0x1000;
    }
    play_sound_effect(0x37);
    gUnk_03001800.unkAA++;
}

void sub_0802976C(void)
{
    u32 done = 0;
    u32 i;

    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03001800.unkD2[i])
        {
            process_sprite_anim_commands(gUnk_083B5F80[0x3C], 0x21 + i);
            if (gUnk_03002C30[0x21 + i].unk22 == 0xFF)
                done = 1;
        }
    }
    if (done)
    {
        clear_battle_sprite_slot(0x21, 3);
        gUnk_03001800.unkAA++;
    }
}

void sub_080297EC(void)
{
    u32 i;

    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03001800.unkD2[i])
            sub_08038394(gUnk_03001800.unk60 + i, 1);
    }
    gUnk_03001800.unkAA++;
}

void sub_08029828(void)
{
    gUnk_03001800.unkA6 = 0x53;
    gUnk_03001800.unkAA++;
}

void sub_08029840(void)
{
    gUnk_03001800.unkB5 = 0;
    gUnk_083AE580[gUnk_03001800.unkAA]();
}

void sub_08029868(void)
{
    lz_decompress_dispatch(gUnk_084DD894, (void *)0x06014800);
    CpuFastSet(gUnk_0850ECD8, (void *)0x050002E0, 8);
    CpuFastSet(gUnk_084E30B8, (void *)0x050002C0, 8);
    gUnk_03002C30[0x21].unk0 = 0xC604;
    gUnk_03002C30[0x21].unk1C = 0;
    gUnk_03002C30[0x21].unk4 = 0xE0;
    gUnk_03002C30[0x21].unkA = 7;
    gUnk_03002C30[0x21].unkB = 0xF0;
    gUnk_03002C30[0x21].unk8 = 0x40;
    gUnk_03002C30[0x21].unk9 = 0x40;
    gUnk_03002C30[0x21].unk18 = 0;
    gUnk_03002C30[0x21].unk28 = 0;
    gUnk_03002C30[0x21].unk2E = 0x5C;
    gUnk_03002C30[0x21].unk29 = 6;
    gUnk_03002C30[0x21].unk2B = 0x20;
    gUnk_03002C30[0x21].unk2C = 0xC0;
    gUnk_03002C30[0x21].unk2D = 0;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[gUnk_03002C30[0x21].unk2E], 0x21);
    if (gUnk_03001800.unkF8 & 1)
        gUnk_03002C30[0x21].unk2 = 0xB8;
    else
        gUnk_03002C30[0x21].unk2 = 0x38;
    gUnk_03001800.unk51 = 1;
    gUnk_03001800.unkAA++;
}

void sub_08029984(void)
{
    u32 found = 0;
    u32 i;

    sub_0803836C();
    gUnk_03001800.unk60 = sub_08032FC4(gUnk_03001800.unk87);
    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03000590[gUnk_03001800.unk60 + i].unk40 == 0)
            continue;
        if (gUnk_03000590[gUnk_03001800.unk60 + i].parts[0].unk11 == 0)
            continue;
        if (clear_ewram_buffer_02023000_b(gUnk_03001800.unk60 + i) == 0)
            continue;
        found = 1;
        gUnk_03001800.unkD2[i] = found;
    }
    if (!found)
        gUnk_03001800.unkAA++;
    else
        gUnk_03001800.unkAA += 2;
}

void sub_08029A14(void)
{
    u32 i;

    lz_decompress_dispatch(gUnk_084DE4BC, (void *)0x06014800);
    CpuFastSet(gUnk_0850ED18, (void *)0x050002E0, 8);
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
        init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x60], 0x21 + i);
        if (gUnk_03001800.unkF8 & 1)
            gUnk_03002C30[0x21 + i].unk0 |= 0x1000;
    }
    play_sound_effect(0x2A);
    gUnk_03001800.unkAA++;
}

void sub_08029B04(void)
{
    u32 done = 0;
    u32 i;

    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03001800.unkD2[i])
        {
            process_sprite_anim_commands(gUnk_083B5F80[0x60], 0x21 + i);
            if (gUnk_03002C30[0x21 + i].unk22 == 0xFF)
                done = 1;
        }
    }
    if (done)
    {
        clear_battle_sprite_slot(0x21, 3);
        gUnk_03001800.unkAA++;
    }
}

void sub_08029B84(void)
{
    u32 i, j;
    u32 r;

    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        for (j = 0; j <= 3; j++)
        {
            r = clear_ewram_buffer_02023000_b(gUnk_03001800.unk60 + i);
            if (r == 0)
                goto next;
            gUnk_03001800.unkD0 = r - 1;
            battle_calc_damage_split(gUnk_03001800.unk60 + i, gUnk_03001800.unkD0, gUnk_03001800.unkEC);
            gUnk_03000590[gUnk_03001800.unk60 + i].parts[gUnk_03001800.unkD0].unk11 += gUnk_03001800.unkC8;
            gUnk_03001800.unkD6[i] += gUnk_03001800.unkC8;
            if (gUnk_03001800.unkCA == 0)
                goto next;
            gUnk_03001800.unkEC = gUnk_03001800.unkCA;
        }
    next:;
    }
    gUnk_03001800.unkAA++;
}

void init_battle_bot_display_digits(void)
{
    u32 i;

    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        switch (i)
        {
        case 0:
            set_display_digit_type(gUnk_03000440.unk9E, gUnk_03001800.unkD6[i], 0);
            render_battle_text_sprites(gUnk_03000440.unk9E, gUnk_03001800.unk60 + i, 0x21);
            break;
        case 1:
            set_display_digit_type(gUnk_03000440.unk9E + 0x14, gUnk_03001800.unkD6[1], 0);
            render_battle_text_sprites(gUnk_03000440.unk9E + 0x14, gUnk_03001800.unk60 + 1, 0x21);
            break;
        case 2:
            set_display_digit_type(gUnk_03000440.unk9E + 0x28, gUnk_03001800.unkD6[2], 0);
            render_battle_text_sprites(gUnk_03000440.unk9E + 0x28, gUnk_03001800.unk60 + 2, 0x21);
            break;
        }
    }
    play_sound_effect(0x5B);
    gUnk_03000440.unk84 = 0;
    gUnk_03001800.unkAA++;
}

void sub_08029D28(void)
{
    u32 i;
    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03001800.unkD2[i])
        {
            switch (i)
            {
            case 0:
                update_battle_sprite_animations(gUnk_03000440.unk9E, gUnk_03001800.unk60 + i, 0x21);
                break;
            case 1:
                update_battle_sprite_animations(gUnk_03000440.unk9E + 0x14, gUnk_03001800.unk60 + 1, 0x21);
                break;
            case 2:
                update_battle_sprite_animations(gUnk_03000440.unk9E + 0x28, gUnk_03001800.unk60 + 2, 0x21);
                break;
            }
        }
    }
    gUnk_03000440.unk84++;
    if (gUnk_03000440.unk89 == 0 && (*(u8 *)&gRepeatKeys & 1) && gUnk_03000440.unk84 > 0x32)
        gUnk_03000440.unk84 = 0x78;
    if (gUnk_03000440.unk84 == 0x78)
    {
        clear_battle_sprite_slot(gUnk_03001800.unk60 * 4 + 0x21, 0xC);
        gUnk_03001800.unkAA++;
    }
}

void sub_08029DF4(void)
{
    gUnk_03001800.unkA6 = 0x3B;
    gUnk_03001800.unkAA++;
}

void sub_08029E0C(void)
{
    gUnk_03001800.unkB5 = 0;
    gUnk_083AE5C0[gUnk_03001800.unkAA]();
}

void sub_08029E34(void)
{
    lz_decompress_dispatch(gUnk_084DDEA4, (void *)0x06014800);
    CpuFastSet(gUnk_0850ECF8, (void *)0x050002E0, 8);
    CpuFastSet(gUnk_084E30B8, (void *)0x050002C0, 8);
    gUnk_03002C30[0x21].unk0 = 0xC604;
    gUnk_03002C30[0x21].unk1C = 0;
    gUnk_03002C30[0x21].unk4 = 0xE0;
    gUnk_03002C30[0x21].unkA = 7;
    gUnk_03002C30[0x21].unkB = 0xF0;
    gUnk_03002C30[0x21].unk8 = 0x40;
    gUnk_03002C30[0x21].unk9 = 0x40;
    gUnk_03002C30[0x21].unk18 = 0;
    gUnk_03002C30[0x21].unk28 = 0;
    gUnk_03002C30[0x21].unk2E = 0x5C;
    gUnk_03002C30[0x21].unk29 = 6;
    gUnk_03002C30[0x21].unk2B = 0x20;
    gUnk_03002C30[0x21].unk2C = 0xC0;
    gUnk_03002C30[0x21].unk2D = 0;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[gUnk_03002C30[0x21].unk2E], 0x21);
    if (gUnk_03001800.unkF8 & 1)
        gUnk_03002C30[0x21].unk2 = 0xB8;
    else
        gUnk_03002C30[0x21].unk2 = 0x38;
    gUnk_03001800.unk51 = 2;
    gUnk_03001800.unkAA++;
}

void sub_08029F50(void)
{
    u32 found = 0;
    u32 i;

    sub_0803836C();
    gUnk_03001800.unk60 = sub_08032FC4(gUnk_03001800.unk87);
    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03000590[gUnk_03001800.unk60 + i].unk40 == 0)
            continue;
        if (gUnk_03000590[gUnk_03001800.unk60 + i].parts[0].unk11 == 0)
            continue;
        if (find_random_available_part_slot(gUnk_03001800.unk60 + i) == 0)
            continue;
        found = 1;
        gUnk_03001800.unkD2[i] = found;
    }
    if (!found)
        gUnk_03001800.unkAA++;
    else
        gUnk_03001800.unkAA += 2;
}

void sub_08029FE0(void)
{
    u32 i, j;
    u32 r;

    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        for (j = 0; j <= 3; j++)
        {
            r = find_random_available_part_slot(gUnk_03001800.unk60 + i);
            if (r == 0)
                goto next;
            gUnk_03001800.unkD0 = r - 1;
            battle_set_damage_display(gUnk_03001800.unk60 + i, gUnk_03001800.unkD0, gUnk_03001800.unkEC);
            gUnk_03000590[gUnk_03001800.unk60 + i].parts[gUnk_03001800.unkD0].unk11 += gUnk_03001800.unkC8;
            gUnk_03001800.unkD6[i] += gUnk_03001800.unkC8;
            sub_080351E8(gUnk_03001800.unk60 + i);
            if (gUnk_03001800.unkCA == 0)
                goto next;
            gUnk_03001800.unkEC = gUnk_03001800.unkCA;
        }
    next:;
    }
    load_all_bot_part_sprites();
    iterate_bots_setup_battle_sprites();
    gUnk_03001800.unkAA++;
}

void sub_0802A0D0(void)
{
    gUnk_03001800.unkA6 = 0x3C;
    gUnk_03001800.unkAA++;
}

void sub_0802A0E8(void)
{
    gUnk_03001800.unkB5 = 0;
    gUnk_083AE600[gUnk_03001800.unkAA]();
}

void sub_0802A110(void)
{
    lz_decompress_dispatch(gUnk_084DE628, (void *)0x06014800);
    CpuFastSet(gUnk_0850ED38, (void *)0x050002E0, 8);
    CpuFastSet(gUnk_084E30B8, (void *)0x050002C0, 8);
    gUnk_03002C30[0x21].unk0 = 0xC604;
    gUnk_03002C30[0x21].unk1C = 0;
    gUnk_03002C30[0x21].unk2 = 0x78;
    gUnk_03002C30[0x21].unk4 = gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 4;
    gUnk_03002C30[0x21].unkA = 7;
    gUnk_03002C30[0x21].unkB = 0xF0;
    gUnk_03002C30[0x21].unk8 = 4;
    gUnk_03002C30[0x21].unk9 = 4;
    gUnk_03002C30[0x21].unk18 = 0;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x61], 0x21);
    gUnk_03002C30[0x22].unk0 = 0xC604;
    gUnk_03002C30[0x22].unk1C = 0;
    gUnk_03002C30[0x22].unk2 = 0x78;
    gUnk_03002C30[0x22].unk4 = gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 4;
    gUnk_03002C30[0x22].unkA = 6;
    gUnk_03002C30[0x22].unkB = 0xE0;
    gUnk_03002C30[0x22].unk8 = 4;
    gUnk_03002C30[0x22].unk9 = 4;
    gUnk_03002C30[0x22].unk18 = 0;
    gUnk_03002C30[0x22].unk6 = 0x7604;
    play_sound_effect(0x67);
    gUnk_03001800.unkAA++;
}

void sub_0802A274(void)
{
    if (gUnk_03002C30[0x21].unk8 == 0x40)
    {
        gUnk_03000440.unk86 = 0x3C;
        gUnk_03001800.unkAA++;
    }
    else
    {
        gUnk_03002C30[0x21].unk8 += 4;
        gUnk_03002C30[0x21].unk9 += 4;
        gUnk_03002C30[0x22].unk8 += 4;
        gUnk_03002C30[0x22].unk9 += 4;
    }
}

void sub_0802A2D4(void)
{
    if (gUnk_03002C30[0x21].unk4 == 0x20)
    {
        play_sound_effect(0x42);
        gUnk_03001800.unkAA++;
    }
    else
    {
        gUnk_03002C30[0x21].unk4--;
        gUnk_03002C30[0x22].unk4--;
    }
}

void sub_0802A31C(void)
{
    process_sprite_anim_commands(gUnk_083B5F80[0x61], 0x21);
    if (gUnk_03002C30[0x21].unk22 == 0xFF)
    {
        clear_battle_sprite_slot(0x21, 1);
        gUnk_03001800.unkAA++;
    }
}

void sub_0802A360(void)
{
    u32 i;

    sub_0803836C();
    gUnk_03001800.unk60 = sub_08032FC4(gUnk_03001800.unk87);
    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03000590[gUnk_03001800.unk60 + i].unk40 == 0)
            continue;
        if (gUnk_03000590[gUnk_03001800.unk60 + i].parts[0].unk11 == 0)
            continue;
        memcpy_bytes_0803F63C(&gUnk_03002C30[0x22], &gUnk_03002C30[0x23 + i], 0x40);
        gUnk_03002C30[0x23 + i].unk30 = gUnk_03002C30[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk2;
        gUnk_03002C30[0x23 + i].unk32 = gUnk_03002C30[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk4 - 4;
        gUnk_03002C30[0x23 + i].unk24 = 3;
        gUnk_03002C30[0x23 + i].unk23 = 0;
        gUnk_03001800.unkD2[i] = 1;
    }
    clear_battle_sprite_slot(0x22, 1);
    gUnk_03001800.unkAA++;
}

void sub_0802A440(void)
{
    u32 done = 0;
    u32 count = 0;
    u32 i;

    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03001800.unkD2[i])
        {
            count++;
            gUnk_03002C30[0x23 + i].unk18 = (gUnk_03002C30[0x23 + i].unk18 + 0x20) & 0x3FF;
            if (move_sprite_toward_target(0x23 + i))
                done++;
        }
    }
    if (count == done)
    {
        play_sound_effect(0x2B);
        gUnk_03001800.unkAA++;
    }
}

void sub_0802A4C4(void)
{
    u32 done = 0;
    u32 i;

    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03001800.unkD2[i])
        {
            gUnk_03002C30[0x23 + i].unk18 = (gUnk_03002C30[0x23 + i].unk18 + 0x20) & 0x3FF;
            gUnk_03002C30[0x23 + i].unk8 -= 4;
            gUnk_03002C30[0x23 + i].unk9 -= 4;
            if (gUnk_03002C30[0x23 + i].unk9 == 4)
                done = 1;
        }
    }
    if (done)
    {
        clear_battle_sprite_slot(0x24, 3);
        gUnk_03001800.unkAA++;
    }
}

void sub_0802A534(void)
{
    u32 i;

    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03001800.unkD2[i])
        {
            sub_08037498(gUnk_03001800.unk60 + i, gUnk_03001800.unkEC);
            gUnk_03001800.unkD6[i] = gUnk_03001800.unkC8;
            sub_08035740(&gUnk_03000590[gUnk_03001800.unk60 + i].parts[0].unk10, gUnk_03001800.unkD6[i],
                gUnk_03000590[gUnk_03001800.unk60 + i].parts[0].data[8]);
        }
    }
    gUnk_03001800.unkAA++;
}

void sub_0802A5C0(void)
{
    u32 i;

    lz_decompress_dispatch(gUnk_084D6BFC, (void *)0x06017E00);
    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        switch (i)
        {
        case 0:
            set_display_digit_type(gUnk_03000440.unk9E, gUnk_03001800.unkD6[i], 0);
            battle_setup_text_sprites_0801A418(gUnk_03000440.unk9E, gUnk_03001800.unk60 + i, 0x21);
            break;
        case 1:
            set_display_digit_type(gUnk_03000440.unk9E + 0x14, gUnk_03001800.unkD6[1], 0);
            battle_setup_text_sprites_0801A418(gUnk_03000440.unk9E + 0x14, gUnk_03001800.unk60 + 1, 0x21);
            break;
        case 2:
            set_display_digit_type(gUnk_03000440.unk9E + 0x28, gUnk_03001800.unkD6[2], 0);
            battle_setup_text_sprites_0801A418(gUnk_03000440.unk9E + 0x28, gUnk_03001800.unk60 + 2, 0x21);
            break;
        }
    }
    play_sound_effect(0x5B);
    gUnk_03000440.unk84 = 0;
    gUnk_03001800.unkAA++;
}

void sub_0802A694(void)
{
    gUnk_03001800.unkA6 = 0x54;
    gUnk_03001800.unkAA++;
}

void sub_0802A6AC(void)
{
    gUnk_03001800.unkB5 = 0;
    gUnk_083AE640[gUnk_03001800.unkAA]();
}

void sub_0802A6D4(void)
{
    lz_decompress_dispatch(gUnk_084DED1C, (void *)0x06014800);
    CpuFastSet(gUnk_0850ED58, (void *)0x050002E0, 8);
    CpuFastSet(gUnk_084E30B8, (void *)0x050002C0, 8);
    gUnk_03002C30[0x21].unk0 = 0xC604;
    gUnk_03002C30[0x21].unk1C = 0;
    gUnk_03002C30[0x21].unk4 = gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 4;
    gUnk_03002C30[0x21].unkA = 7;
    gUnk_03002C30[0x21].unkB = 0xF0;
    gUnk_03002C30[0x21].unk8 = 4;
    gUnk_03002C30[0x21].unk9 = 4;
    gUnk_03002C30[0x21].unk18 = 0;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x62], 0x21);
    if (!(gUnk_03001800.unkF8 & 1))
    {
        gUnk_03002C30[0x21].unk2 = 0x70;
    }
    else
    {
        gUnk_03002C30[0x21].unk0 |= 0x1000;
        gUnk_03002C30[0x21].unk2 = 0x80;
    }
    play_sound_effect(0x6A);
    gUnk_03001800.unkAA++;
}

void sub_0802A7E0(void)
{
    if (gUnk_03002C30[0x21].unk8 == 0x40)
    {
        gUnk_03000440.unk86 = 0x3C;
        gUnk_03001800.unkAA++;
    }
    else
    {
        gUnk_03002C30[0x21].unk8 += 4;
        gUnk_03002C30[0x21].unk9 += 4;
    }
}

void sub_0802A824(void)
{
    u32 i;

    sub_0803836C();
    gUnk_03001800.unk60 = sub_08032FB8(gUnk_03001800.unk87);
    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03000590[gUnk_03001800.unk60 + i].unk40 == 0)
            continue;
        if (gUnk_03000590[gUnk_03001800.unk60 + i].parts[0].unk11 == 0)
            continue;
        gUnk_03000590[gUnk_03001800.unk60 + i].unkBD |= 4;
        gUnk_03001800.unkD2[i] = 1;
        sub_080385D0(gUnk_03001800.unk60 + i);
        gUnk_03000590[gUnk_03001800.unk60 + i].unkD7 = 0;
        gUnk_03000590[gUnk_03001800.unk60 + i].unkBB = 0x14;
        gUnk_03000590[gUnk_03001800.unk60 + i].unkDA = 0;
        gUnk_03002C30[0x22 + i].unk0 = 0xC404;
        gUnk_03002C30[0x22 + i].unk1C = 0;
        gUnk_03002C30[0x22 + i].unk2 = gUnk_03002C30[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk2;
        gUnk_03002C30[0x22 + i].unk4 = gUnk_03002C30[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk4 - 0x10;
        gUnk_03002C30[0x22 + i].unkA = 7;
        gUnk_03002C30[0x22 + i].unkB = 0xE0;
        init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x63], 0x22 + i);
        if (gUnk_03001800.unkF8 & 1)
            gUnk_03002C30[0x22 + i].unk0 |= 0x1000;
    }
    iterate_bots_setup_battle_sprites();
    gUnk_03000440.unk86 = 0;
    gUnk_03002C30[0x21].unk0 &= 0xFDFF;
    gUnk_03002C30[0x2B].unk29 = 1;
    gUnk_03002C30[0x2B].unk2 = gUnk_03002C30[0x21].unk2;
    gUnk_03002C30[0x2B].unk4 = gUnk_03002C30[0x21].unk4;
    battle_queue_sort();
    gUnk_03001800.unkAA++;
}

void sub_0802A9B8(void)
{
    u32 done = 0;
    u32 count = 0;
    u32 i;

    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        count++;
        sub_08019544(gUnk_03001800.unk60 + i);
        if (sub_08019440(gUnk_03001800.unk60 + i))
            done++;
        process_sprite_anim_commands(gUnk_083B5F80[0x63], 0x22 + i);
        gUnk_03002C30[0x22 + i].unk2 = gUnk_03002C30[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk2;
        gUnk_03002C30[0x22 + i].unk4 = gUnk_03002C30[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk4 - 0x10;
        init_battle_sprite_entry_0801BC04(gUnk_03001800.unk60 + i);
    }
    process_sprite_anim_commands(gUnk_083B5F80[0x62], 0x21);
    if (!(gUnk_03000440.unk86 & 0x3F))
        play_sound_effect(0x33);
    gUnk_03000440.unk86++;
    sub_080383E8();
    if (done == count && gUnk_03000440.unk86 > 0x3C)
    {
        clear_battle_sprite_slot(0x21, 0x1B);
        iterate_bots_setup_battle_sprites();
        gUnk_03001800.unkAA++;
    }
}

void sub_0802AAB8(void)
{
    gUnk_03001800.unkA6 = 0x65;
    gUnk_03001800.unkAA++;
}

void sub_0802AAD0(void)
{
    gUnk_03001800.unkB5 = 0;
    gUnk_083AE680[gUnk_03001800.unkAA]();
}

void sub_0802AAF8(void)
{
    lz_decompress_dispatch(gUnk_084DF024, (void *)0x06014800);
    CpuFastSet(gUnk_0850ED78, (void *)0x050002E0, 8);
    gUnk_03002C30[0x21].unk0 = -0x39DC;
    gUnk_03002C30[0x21].unk1C = 0;
    gUnk_03002C30[0x21].unk2 = gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk2 - 0x20;
    gUnk_03002C30[0x21].unk4 = gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 4;
    gUnk_03002C30[0x21].unkA = 7;
    gUnk_03002C30[0x21].unkB = -0x10;
    gUnk_03002C30[0x21].unk8 = 0x80;
    gUnk_03002C30[0x21].unk9 = 0x80;
    gUnk_03002C30[0x21].unk2B = 0x1C;
    gUnk_03002C30[0x21].unk2C = 0;
    gUnk_03002C30[0x21].unk2D = 0;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x1C], 0x21);
    gUnk_03002C30[0x22].unk0 = -0x39DC;
    gUnk_03002C30[0x22].unk1C = 0;
    gUnk_03002C30[0x22].unk2 = gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk2 + 0x20;
    gUnk_03002C30[0x22].unk4 = gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 4;
    gUnk_03002C30[0x22].unkA = 7;
    gUnk_03002C30[0x22].unkB = -0x10;
    gUnk_03002C30[0x22].unk8 = 0x80;
    gUnk_03002C30[0x22].unk9 = 0x80;
    gUnk_03002C30[0x22].unk2B = 0x1C;
    gUnk_03002C30[0x22].unk2C = 0x80;
    gUnk_03002C30[0x22].unk2D = 0;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x1C], 0x22);
    play_sound_effect(0x33);
    gUnk_03001800.unkAA++;
}

void sub_0802AC7C(void)
{
    sub_08035740(&gUnk_03000590[gUnk_03001800.unk87].unkD0 + 1, gUnk_03001800.unkEC, 0xFF);
    gUnk_03001800.unkAA++;
}

void sub_0802ACB4(void)
{
    gUnk_03001800.unkA6 = 0x45;
    gUnk_03001800.unkAA++;
}

void sub_0802ACCC(void)
{
    gUnk_03001800.unkB5 = 0;
    gUnk_083AE6C0[gUnk_03001800.unkAA]();
}

void sub_0802ACF4(void)
{
    lz_decompress_dispatch(gUnk_084DF400, (void *)0x06014800);
    CpuFastSet(gUnk_0850ED98, (void *)0x050002E0, 8);
    gUnk_03002C30[0x21].unk0 = -0x39DC;
    gUnk_03002C30[0x21].unk1C = 0;
    gUnk_03002C30[0x21].unk2 = gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk2 - 0x20;
    gUnk_03002C30[0x21].unk4 = gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 4;
    gUnk_03002C30[0x21].unkA = 7;
    gUnk_03002C30[0x21].unkB = 0xF0;
    gUnk_03002C30[0x21].unk8 = 0x80;
    gUnk_03002C30[0x21].unk9 = 0x80;
    gUnk_03002C30[0x21].unk2B = 0x1C;
    gUnk_03002C30[0x21].unk2C = 0;
    gUnk_03002C30[0x21].unk2D = 0;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x64], 0x21);
    gUnk_03002C30[0x22].unk0 = -0x39DC;
    gUnk_03002C30[0x22].unk1C = 0;
    gUnk_03002C30[0x22].unk2 = gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk2 + 0x20;
    gUnk_03002C30[0x22].unk4 = gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 4;
    gUnk_03002C30[0x22].unkA = 7;
    gUnk_03002C30[0x22].unkB = 0xF0;
    gUnk_03002C30[0x22].unk8 = 0x80;
    gUnk_03002C30[0x22].unk9 = 0x80;
    gUnk_03002C30[0x22].unk6 = 0x7901;
    gUnk_03002C30[0x22].unk2B = 0x1C;
    gUnk_03002C30[0x22].unk2C = 0x80;
    gUnk_03002C30[0x22].unk2D = 0;
    play_sound_effect(0x33);
    gUnk_03001800.unkAA++;
}

void sub_0802AE88(void)
{
    process_sprite_anim_commands(gUnk_083B5F80[0x64], 0x21);
    if (gUnk_03002C30[0x21].unk22 == 0xFF)
    {
        clear_battle_sprite_slot(0x21, 1);
        gUnk_03001800.unkAA++;
    }
}

void sub_0802AECC(void)
{
    gUnk_03002C30[0x21].unk0 = 0xCC04;
    gUnk_03002C30[0x21].unk1C = 0;
    gUnk_03002C30[0x21].unk2 = gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk2;
    gUnk_03002C30[0x21].unk4 = gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 4;
    gUnk_03002C30[0x21].unkA = 7;
    gUnk_03002C30[0x21].unkB = 0;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x65], 0x21);
    play_sound_effect(0x71);
    gUnk_03001800.unkAA++;
}

void sub_0802AF6C(void)
{
    process_sprite_anim_commands(gUnk_083B5F80[0x65], 0x21);
    if (gUnk_03002C30[0x21].unk22 == 0xFF)
    {
        clear_battle_sprite_slot(0x21, 1);
        gUnk_03001800.unkAA++;
    }
}

void sub_0802AFB0(void)
{
    sub_08035740(&gUnk_03000590[gUnk_03001800.unk87].unkD0, gUnk_03001800.unkEC, 0xFF);
    gUnk_03001800.unkAA++;
}

void sub_0802AFE8(void)
{
    gUnk_03001800.unkA6 = 0x44;
    gUnk_03001800.unkAA++;
}

void sub_0802B000(void)
{
    gUnk_03001800.unkB5 = 0;
    gUnk_083AE700[gUnk_03001800.unkAA]();
}

void sub_0802B028(void)
{
    lz_decompress_dispatch(gUnk_084DFA88, (void *)0x06014800);
    CpuFastSet(gUnk_0850EDB8, (void *)0x050002C0, 0x10);
    gUnk_03002C30[0x21].unk0 = 0xC604;
    gUnk_03002C30[0x21].unk1C = 0;
    gUnk_03002C30[0x21].unk2 = gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk2;
    gUnk_03002C30[0x21].unk4 = gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 4;
    gUnk_03002C30[0x21].unkA = 6;
    gUnk_03002C30[0x21].unkB = 0xF0;
    gUnk_03002C30[0x21].unk8 = 0x40;
    gUnk_03002C30[0x21].unk9 = 0x40;
    gUnk_03002C30[0x21].unk6 = 0x7A00;
    gUnk_03002C30[0x22].unk0 = 0xC404;
    gUnk_03002C30[0x22].unk1C = 0;
    gUnk_03002C30[0x22].unk2 = gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk2;
    gUnk_03002C30[0x22].unk4 = gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 4;
    gUnk_03002C30[0x22].unkA = 7;
    gUnk_03002C30[0x22].unkB = 0xE0;
    gUnk_03002C30[0x22].unk2D = 0;
    if (gUnk_03000590[gUnk_03001800.unk87].unkA8[0] == 0x1E)
        gUnk_03002C30[0x22].unk6 = 0x7A01;
    else
        gUnk_03002C30[0x22].unk6 = 0x7A02;
    play_sound_effect(0x4C);
    gUnk_03001800.unkAA++;
}

void sub_0802B184(void)
{
    u32 i;
    u32 found = 0;

    sub_0803836C();
    gUnk_03001800.unk60 = sub_08032FB8(gUnk_03001800.unk87);
    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03000590[gUnk_03001800.unk60 + i].unk40 == 0
            || gUnk_03000590[gUnk_03001800.unk60 + i].parts[0].unk11 == 0
            || sub_080331F8(gUnk_03001800.unk60 + i) == 0)
            continue;
        if (gUnk_03000590[gUnk_03001800.unk87].unkA8[0] == 0x1E)
        {
            if (gUnk_03000590[gUnk_03001800.unk60 + i].parts[3].data[1] == 0x64)
            {
                gUnk_03001800.unkD2[i] = 1;
                found = 1;
            }
        }
        else if (gUnk_03000590[gUnk_03001800.unk60 + i].parts[3].data[1] == 0x6A)
        {
            gUnk_03001800.unkD2[i] = 2;
            found = 1;
        }
    }
    if (!found)
        gUnk_03001800.unkAA++;
    else
        gUnk_03001800.unkAA += 2;
}

void sub_0802B258(void)
{
    u32 i;

    lz_decompress_dispatch(gUnk_084DFBD4, (void *)0x06014800);
    CpuFastSet(gUnk_0850EDF8, (void *)0x050002C0, 0x10);
    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        gUnk_03002C30[i + 0x21].unk0 = 0xC404;
        gUnk_03002C30[i + 0x21].unk1C = 0;
        gUnk_03002C30[i + 0x21].unk2 = gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk2;
        gUnk_03002C30[i + 0x21].unk4 = gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 4;
        gUnk_03002C30[i + 0x21].unk30 = gUnk_03002C30[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk2;
        gUnk_03002C30[i + 0x21].unk32 = gUnk_03002C30[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk4 - 4;
        gUnk_03002C30[i + 0x21].unk24 = 6;
        gUnk_03002C30[i + 0x21].unk23 = 0;
        gUnk_03002C30[i + 0x21].unkB = 0xF0;
        if (gUnk_03001800.unkF8 & 1)
            gUnk_03002C30[i + 0x21].unk0 |= 0x1000;
        if (gUnk_03001800.unkD2[i] == 1)
        {
            gUnk_03002C30[i + 0x21].unkA = 6;
            gUnk_03002C30[i + 0x21].unk6 = 0x7B00;
        }
        else
        {
            gUnk_03002C30[i + 0x21].unkA = 7;
            gUnk_03002C30[i + 0x21].unk6 = 0x7B01;
        }
    }
    play_sound_effect(0x24);
    gUnk_03001800.unkAA++;
}

void sub_0802B388(void)
{
    u32 done = 0;
    u32 count = 0;
    u32 i;

    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        count++;
        if (move_sprite_toward_target(i + 0x21))
            done++;
    }
    if (done == count)
        gUnk_03001800.unkAA++;
}

void sub_0802B3CC(void)
{
    u32 i;

    lz_decompress_dispatch(gUnk_084DCF54, (void *)0x06016000);
    CpuFastSet(gUnk_0850EC58, (void *)0x050002E0, 8);
    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        gUnk_03002C30[i + 0x21].unkA = 7;
        gUnk_03002C30[i + 0x21].unk0 &= 0xEFFF;
        init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x66], i + 0x21);
    }
    gUnk_03001800.unkAA++;
}

void sub_0802B460(void)
{
    u32 done = 0;
    u32 i;

    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        process_sprite_anim_commands(gUnk_083B5F80[0x66], i + 0x21);
        if (gUnk_03002C30[i + 0x21].unk22 == 0xFF)
            done = 1;
    }
    if (done)
        gUnk_03001800.unkAA++;
}

void sub_0802B4D8(void)
{
    u32 i;

    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        gUnk_03001800.unkD6[i] = rng_next_080424B8() & 7;
        switch (gUnk_03001800.unkD6[i])
        {
        case 0:
            if (sub_08036D64(gUnk_03001800.unk60 + i, 0xD))
                gUnk_03001800.unkD6[i] = 5;
            break;
        case 1:
            if (sub_08036D64(gUnk_03001800.unk60 + i, 0x11))
                gUnk_03001800.unkD6[i] = 5;
            break;
        case 2:
            if (sub_08036D64(gUnk_03001800.unk60 + i, 0x13))
                gUnk_03001800.unkD6[i] = 5;
            break;
        case 3:
            if (sub_08036D64(gUnk_03001800.unk60 + i, 0x10))
                gUnk_03001800.unkD6[i] = 5;
            break;
        }
        gUnk_03002C30[i + 0x21].unk6 = 0x6F00 + gUnk_03001800.unkD6[i];
        gUnk_03002C30[i + 0x21].unk23 = 0;
    }
    play_sound_effect(0x5B);
    gUnk_03001800.unkAA++;
}

void sub_0802B5AC(void)
{
    u32 i;

    clear_battle_sprite_slot(0x21, 3);
    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        switch (gUnk_03001800.unkD6[i])
        {
        case 0:
            battle_set_action_params(gUnk_03001800.unk60 + i, 0xD, gUnk_03001800.unkE8, gUnk_03001800.unkEC);
            break;
        case 1:
            battle_set_action_params(gUnk_03001800.unk60 + i, 0x11, gUnk_03001800.unkE8, gUnk_03001800.unkEC);
            break;
        case 2:
            battle_set_action_params(gUnk_03001800.unk60 + i, 0x13, gUnk_03001800.unkE8, gUnk_03001800.unkEC);
            break;
        case 3:
            battle_set_action_params(gUnk_03001800.unk60 + i, 0x10, gUnk_03001800.unkE8, gUnk_03001800.unkEC);
            break;
        case 4:
            gUnk_03000590[gUnk_03001800.unk60 + i].unkC9 = 0x2B;
            gUnk_03000590[gUnk_03001800.unk60 + i].unkCB = sub_08036E54(gUnk_03001800.unkE8);
            gUnk_03000590[gUnk_03001800.unk60 + i].unkCC = sub_08036E54(gUnk_03001800.unkEC);
            gUnk_03000590[gUnk_03001800.unk60 + i].unkCA = 1;
            break;
        case 5:
            gUnk_03000590[gUnk_03001800.unk60 + i].unkC9 = 0x2C;
            gUnk_03000590[gUnk_03001800.unk60 + i].unkCA = 0;
            gUnk_03000590[gUnk_03001800.unk60 + i].unkCB = sub_08036E54(gUnk_03001800.unkE8);
            gUnk_03000590[gUnk_03001800.unk60 + i].unkCC = sub_08036E54(gUnk_03001800.unkEC);
            break;
        case 6:
            gUnk_03000590[gUnk_03001800.unk60 + i].unkC9 = 0x2E;
            gUnk_03000590[gUnk_03001800.unk60 + i].unkCA = 0;
            gUnk_03000590[gUnk_03001800.unk60 + i].unkCB = sub_08036E54(gUnk_03001800.unkE8);
            gUnk_03000590[gUnk_03001800.unk60 + i].unkCC = sub_08036E54(gUnk_03001800.unkEC);
            break;
        case 7:
            gUnk_03000590[gUnk_03001800.unk60 + i].unkC9 = 0x2F;
            gUnk_03000590[gUnk_03001800.unk60 + i].unkCA = 0;
            gUnk_03000590[gUnk_03001800.unk60 + i].unkCB = sub_08036E54(gUnk_03001800.unkE8);
            gUnk_03000590[gUnk_03001800.unk60 + i].unkCC = sub_08036E54(gUnk_03001800.unkEC);
            break;
        }
    }
    gUnk_03001800.unkAA++;
}

void sub_0802B7AC(void)
{
    if (gUnk_03000590[gUnk_03001800.unk87].unkA8[0] == 0x1E)
        gUnk_03001800.unkA6 = 0x4D;
    else
        gUnk_03001800.unkA6 = 0x4E;
    gUnk_03001800.unkAA++;
}

void sub_0802B7E8(void)
{
    gUnk_03001800.unkB5 = 0;
    gUnk_083AE750[gUnk_03001800.unkAA]();
}

void sub_0802B810(void)
{
    u32 i;

    sub_0803836C();
    gUnk_03001800.unk60 = sub_08032FC4(gUnk_03001800.unk87);
    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03000590[gUnk_03001800.unk60 + i].unk40 != 0
            && gUnk_03000590[gUnk_03001800.unk60 + i].parts[0].unk11 != 0)
            gUnk_03001800.unkD2[i] = 1;
    }
    switch (gUnk_03000590[gUnk_03001800.unk87].unkA8[0])
    {
    case 0x1F:
        gUnk_03001800.unk51 = 0;
        break;
    case 0x21:
        gUnk_03001800.unk51 = 1;
        break;
    case 0x23:
        gUnk_03001800.unk51 = 2;
        break;
    case 0x25:
        gUnk_03001800.unk51 = 3;
        break;
    }
    gUnk_03001800.unkAA++;
}

void sub_0802B8BC(void)
{
    u32 i;

    lz_decompress_dispatch(gUnk_084DFC18, (void *)0x06014800);
    CpuFastSet(gUnk_0850EE38, (void *)0x050002C0, 0x10);
    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        gUnk_03002C30[i + 0x21].unk0 = 0xC404;
        gUnk_03002C30[i + 0x21].unk1C = 0;
        gUnk_03002C30[i + 0x21].unk2 = gUnk_03002C30[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk2;
        gUnk_03002C30[i + 0x21].unk4 = 0xF0;
        gUnk_03002C30[i + 0x21].unkA = 6;
        gUnk_03002C30[i + 0x21].unkB = 0xF0;
        init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x67], i + 0x21);
    }
    play_sound_effect(0x2C);
    gUnk_03001800.unkAA++;
}

void sub_0802B980(void)
{
    u32 done = 0;
    u32 count = 0;
    u32 i;

    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        count++;
        process_sprite_anim_commands(gUnk_083B5F80[0x67], i + 0x21);
        if (gUnk_03002C30[i + 0x21].unk4 == gUnk_03002C30[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk4 - 4)
            done++;
        else
            gUnk_03002C30[i + 0x21].unk4 = (gUnk_03002C30[i + 0x21].unk4 + 1) & 0xFF;
    }
    if (done == count)
        gUnk_03001800.unkAA++;
}

void sub_0802BA2C(void)
{
    u32 i;

    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        gUnk_03002C30[i + 0x21].unk0 = 0xCC04;
        gUnk_03002C30[i + 0x21].unkB = 0;
        init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x68], i + 0x21);
    }
    play_sound_effect(0x30);
    gUnk_03001800.unkAA++;
}

void sub_0802BAAC(void)
{
    u32 done = 0;
    u32 i;

    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        process_sprite_anim_commands(gUnk_083B5F80[0x68], i + 0x21);
        if (gUnk_03002C30[i + 0x21].unk22 == 0xFF)
            done = 1;
    }
    if (done)
        gUnk_03001800.unkAA++;
}

void sub_0802BB24(void)
{
    u32 i;

    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        gUnk_03002C30[i + 0x21].unk0 = 0xC404;
        gUnk_03002C30[i + 0x21].unkB = 0xE0;
        gUnk_03002C30[i + 0x21].unk4 += 8;
        gUnk_03002C30[i + 0x21].unkA = 7;
        gUnk_03002C30[i + 0x21].unk6 = 0x7C04 + gUnk_03001800.unk51;
    }
    gUnk_03000440.unk86 = 0;
    play_sound_effect(0x2E);
    gUnk_03001800.unkAA++;
}

void sub_0802BBA8(void)
{
    u32 i;

    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03001800.unkD2[i] != 0 && !(gUnk_03000440.unk86 & 1))
            gUnk_03002C30[i + 0x21].unk4--;
    }
    if (++gUnk_03000440.unk86 == 0x20)
    {
        gUnk_03000440.unk86 = 0x3C;
        gUnk_03001800.unkAA++;
    }
}

void sub_0802BC1C(void)
{
    u32 i;

    clear_battle_sprite_slot(0x21, 3);
    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03001800.unkD2[i] != 0)
            gUnk_03001800.unkD6[i] = gUnk_03001800.unkEC;
    }
    gUnk_03001800.unkAA++;
}

void sub_0802BC60(void)
{
    u32 i;

    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        switch (gUnk_03001800.unk51)
        {
        case 0:
            sub_08035740(&gUnk_03000590[gUnk_03001800.unk60 + i].parts[3].data[5], gUnk_03001800.unkEC, 0xFF);
            break;
        case 1:
            sub_08035740(&gUnk_03000590[gUnk_03001800.unk60 + i].parts[3].data[6], gUnk_03001800.unkEC, 0xFF);
            break;
        case 2:
            sub_08035740(&gUnk_03000590[gUnk_03001800.unk60 + i].parts[3].data[8], gUnk_03001800.unkEC, 0xFF);
            break;
        case 3:
            sub_08035740(&gUnk_03000590[gUnk_03001800.unk60 + i].parts[3].data[9], gUnk_03001800.unkEC, 0xFF);
            break;
        }
        sub_08035194(gUnk_03001800.unk60 + i);
        sub_080351E8(gUnk_03001800.unk60 + i);
    }
    gUnk_03001800.unkAA++;
}

void sub_0802BD1C(void)
{
    switch (gUnk_03001800.unk51)
    {
    case 0:
        gUnk_03001800.unkA6 = 0x3D;
        break;
    case 1:
        gUnk_03001800.unkA6 = 0x3E;
        break;
    case 2:
        gUnk_03001800.unkA6 = 0x40;
        break;
    case 3:
        gUnk_03001800.unkA6 = 0x41;
        break;
    }
    gUnk_03001800.unkAA++;
}

void sub_0802BD6C(void)
{
    gUnk_03001800.unkB5 = 0;
    gUnk_083AE790[gUnk_03001800.unkAA]();
}

void sub_0802BD94(void)
{
    gUnk_03002C30[0x21].unk0 = 0xC604;
    gUnk_03002C30[0x21].unk1C = 0;
    gUnk_03002C30[0x21].unk2 = 0x78;
    gUnk_03002C30[0x21].unk4 = 0x40;
    gUnk_03002C30[0x21].unkA = 6;
    gUnk_03002C30[0x21].unkB = 0xF0;
    gUnk_03002C30[0x21].unk6 = 0x4800;
    gUnk_03002C30[0x21].unk8 = 0x40;
    gUnk_03002C30[0x21].unk9 = 0x40;
    gUnk_03002C30[0x21].unk18 = 0;
    gUnk_03002C30[0x21].unk2D = 0;
    gUnk_03002C30[0x21].unk2E = 1;
    gUnk_03000440.unk86 = 0;
    gUnk_03000440.unk84 = 0;
    gUnk_03001800.unkAA++;
}

void sub_0802BE44(void)
{
    u32 v;

    if (gUnk_03000440.unk84 <= 2)
    {
        if (gUnk_03000440.unk86 == 0)
        {
            gUnk_03000440.unk84++;
            play_sound_effect(0x4C);
        }
        if (++gUnk_03000440.unk86 == gUnk_083AE7D0[gUnk_03000440.unk84 - 1])
            gUnk_03000440.unk86 = 0;
    }
    if (gUnk_03002C30[0x21].unk18 == 0)
        gUnk_03002C30[0x21].unk2E++;
    v = (u16)(gUnk_03002C30[0x21].unk2E * 16 + gUnk_03002C30[0x21].unk18) & 0x3FF;
    gUnk_03002C30[0x21].unk18 = v;
    if (gUnk_03002C30[0x21].unk2E == 5 && v == 0)
    {
        clear_battle_sprite_slot(0x21, 1);
        gUnk_03001800.unkAA++;
    }
}

void sub_0802BEEC(void)
{
    u32 i;

    sub_0803836C();
    gUnk_03001800.unk60 = sub_08032FC4(gUnk_03001800.unk87);
    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03000590[gUnk_03001800.unk60 + i].unk40 != 0
            && gUnk_03000590[gUnk_03001800.unk60 + i].parts[0].unk11 != 0)
            gUnk_03001800.unkD2[i] = 1;
    }
    gUnk_03001800.unk60 = sub_08032FB8(gUnk_03001800.unk87);
    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03000590[gUnk_03001800.unk60 + i].unk40 != 0
            && gUnk_03000590[gUnk_03001800.unk60 + i].parts[0].unk11 != 0)
            gUnk_03001800.unkD6[i] = 1;
    }
    gUnk_03001800.unkAA++;
}

void sub_0802BF9C(void)
{
    u32 i;

    gUnk_03001800.unk60 = sub_08032FC4(gUnk_03001800.unk87);
    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        gUnk_03002C30[i + 0x21].unk0 = 0xC624;
        gUnk_03002C30[i + 0x21].unk1C = 0;
        gUnk_03002C30[i + 0x21].unk2 = gUnk_03002C30[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk2;
        gUnk_03002C30[i + 0x21].unk4 = gUnk_03002C30[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk4;
        gUnk_03002C30[i + 0x21].unkA = 7;
        gUnk_03002C30[i + 0x21].unkB = 0xF0;
        gUnk_03002C30[i + 0x21].unk8 = 0x40;
        gUnk_03002C30[i + 0x21].unk9 = 0x40;
        gUnk_03002C30[i + 0x21].unk6 = 0x4801;
    }
    gUnk_03001800.unk60 = sub_08032FB8(gUnk_03001800.unk87);
    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03001800.unkD6[i] == 0)
            continue;
        gUnk_03002C30[i + 0x24].unk0 = 0xC624;
        gUnk_03002C30[i + 0x24].unk1C = 0;
        gUnk_03002C30[i + 0x24].unk2 = gUnk_03002C30[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk2;
        gUnk_03002C30[i + 0x24].unk4 = gUnk_03002C30[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk4 - 0x10;
        gUnk_03002C30[i + 0x24].unkA = 7;
        gUnk_03002C30[i + 0x24].unkB = 0xF0;
        gUnk_03002C30[i + 0x24].unk8 = 0x40;
        gUnk_03002C30[i + 0x24].unk9 = 0x40;
        gUnk_03002C30[i + 0x24].unk6 = 0x4802;
    }
    gUnk_03000440.unk84 = 0;
    play_sound_effect(0x2E);
    gUnk_03001800.unkAA++;
}

void sub_0802C0DC(void)
{
    u32 i;

    gUnk_03001800.unk60 = sub_08032FC4(gUnk_03001800.unk87);
    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03001800.unkD2[i] != 0 && !(gUnk_03000440.unk84 & 1))
            gUnk_03002C30[i + 0x21].unk4--;
    }
    gUnk_03001800.unk60 = sub_08032FB8(gUnk_03001800.unk87);
    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03001800.unkD6[i] != 0 && !(gUnk_03000440.unk84 & 1))
            gUnk_03002C30[i + 0x24].unk4++;
    }
    if (gUnk_03000440.unk84 == 0x20)
    {
        gUnk_03000440.unk86 = 0x3C;
        gUnk_03001800.unkAA++;
    }
    else
        gUnk_03000440.unk84++;
}

void sub_0802C1A4(void)
{
    u32 i;

    gUnk_03001800.unk60 = sub_08032FC4(gUnk_03001800.unk87);
    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03001800.unkD2[i] != 0)
        {
            gUnk_03002C30[i + 0x21].unk8 -= 8;
            gUnk_03002C30[i + 0x21].unk9 += 8;
        }
    }
    gUnk_03001800.unk60 = sub_08032FB8(gUnk_03001800.unk87);
    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03001800.unkD6[i] != 0)
        {
            gUnk_03002C30[i + 0x24].unk8 -= 8;
            gUnk_03002C30[i + 0x24].unk9 += 8;
        }
    }
    if (gUnk_03002C30[0x21].unk8 == 8)
    {
        clear_battle_sprite_slot(0x21, 6);
        gUnk_03001800.unkAA++;
    }
}

void sub_0802C24C(void)
{
    sub_08035740(&gUnk_03001800.unk28[gUnk_03001800.unk89].unk0, gUnk_03001800.unkEC, 0xA0);
    sub_0803572C(&gUnk_03001800.unk28[gUnk_03001800.unk8A].unk0, gUnk_03001800.unkEC);
    gUnk_03001800.unkAA++;
}

void sub_0802C294(void)
{
    gUnk_03001800.unkA6 = 0x5B;
    gUnk_03001800.unkAA++;
}

void sub_0802C2AC(void)
{
    gUnk_03001800.unkB5 = 0;
    gUnk_083AE7D4[gUnk_03001800.unkAA]();
}

void sub_0802C2D4(void)
{
    u32 i;

    lz_decompress_dispatch(gUnk_084D5EBC, (void *)0x06014800);
    CpuFastSet(gUnk_0850E7B8, (void *)0x050002E0, 8);
    gUnk_03001800.unk60 = sub_08032FC4(gUnk_03001800.unk87);
    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        gUnk_03002C30[i + 0x21].unk0 = 0xC404;
        gUnk_03002C30[i + 0x21].unk1C = 0;
        gUnk_03002C30[i + 0x21].unk2 = gUnk_03002C30[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk2;
        gUnk_03002C30[i + 0x21].unk4 = gUnk_03002C30[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk4 - 4;
        gUnk_03002C30[i + 0x21].unkA = 7;
        gUnk_03002C30[i + 0x21].unkB = 0xF0;
        init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x40], i + 0x21);
    }
    gUnk_03001800.unk60 = sub_08032FB8(gUnk_03001800.unk87);
    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03001800.unkD6[i] == 0)
            continue;
        gUnk_03002C30[i + 0x24].unk0 = 0xC404;
        gUnk_03002C30[i + 0x24].unk1C = 0;
        gUnk_03002C30[i + 0x24].unk2 = gUnk_03002C30[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk2;
        gUnk_03002C30[i + 0x24].unk4 = gUnk_03002C30[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk4 - 4;
        gUnk_03002C30[i + 0x24].unkA = 7;
        gUnk_03002C30[i + 0x24].unkB = 0xF0;
        init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x41], i + 0x24);
    }
    play_sound_effect(0x4D);
    gUnk_03001800.unkAA++;
}

void sub_0802C440(void)
{
    u32 i;

    gUnk_03001800.unk60 = sub_08032FC4(gUnk_03001800.unk87);
    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03001800.unkD2[i] != 0)
            process_sprite_anim_commands(gUnk_083B5F80[0x40], i + 0x21);
    }
    gUnk_03001800.unk60 = sub_08032FB8(gUnk_03001800.unk87);
    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03001800.unkD6[i] != 0)
            process_sprite_anim_commands(gUnk_083B5F80[0x41], i + 0x24);
    }
    if (gUnk_03002C30[0x21].unk22 == 0xFF)
    {
        clear_battle_sprite_slot(0x21, 6);
        gUnk_03000440.unk84 = 0;
        gUnk_03001800.unkAA++;
    }
}

void sub_0802C4F8(void)
{
    u32 i;

    gUnk_03000440.unk84++;
    gUnk_03001800.unk60 = sub_08032FC4(gUnk_03001800.unk87);
    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03001800.unkD2[i] != 0)
            sub_08037330(gUnk_03001800.unk60 + i, gUnk_03000440.unk84, 2);
    }
    if (gUnk_03000440.unk84 == 0x3C)
    {
        for (i = 0; i <= 2; i++)
        {
            if (gUnk_03001800.unkD2[i] != 0)
                sub_080373D4(gUnk_03001800.unk60 + i);
        }
        gUnk_03001800.unkAA++;
    }
}

void sub_0802C588(void)
{
    u32 i;

    gUnk_03001800.unk60 = sub_08032FC4(gUnk_03001800.unk87);
    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03001800.unkD2[i] != 0)
            sub_08035740(&gUnk_03000590[gUnk_03001800.unk60 + i].unkB8 + 1, gUnk_03001800.unkEC, 0x78);
    }
    gUnk_03001800.unk60 = sub_08032FB8(gUnk_03001800.unk87);
    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03001800.unkD6[i] != 0)
            sub_0803572C(&gUnk_03000590[gUnk_03001800.unk60 + i].unkB8 + 1, gUnk_03001800.unkEC);
    }
    gUnk_03001800.unkAA++;
}

void sub_0802C62C(void)
{
    gUnk_03001800.unkA6 = 0x5C;
    gUnk_03001800.unkAA++;
}

void sub_0802C644(void)
{
    gUnk_03001800.unkB5 = 0;
    gUnk_083AE814[gUnk_03001800.unkAA]();
}

void sub_0802C66C(void)
{
    lz_decompress_dispatch(gUnk_084DFFE4, (void *)0x06014800);
    CpuFastSet(gUnk_0850EE78, (void *)0x050002E0, 8);
    gUnk_03002C30[0x21].unk0 = 0xC604;
    gUnk_03002C30[0x21].unk1C = 0;
    gUnk_03002C30[0x21].unk2 = 0x78;
    gUnk_03002C30[0x21].unk4 = 0x40;
    gUnk_03002C30[0x21].unk8 = 4;
    gUnk_03002C30[0x21].unk9 = 4;
    gUnk_03002C30[0x21].unkA = 7;
    gUnk_03002C30[0x21].unkB = 0xF0;
    gUnk_03002C30[0x21].unk6 = 0x7D00;
    play_sound_effect(0x6E);
    gUnk_03001800.unkAA++;
}

void sub_0802C714(void)
{
    if (gUnk_03002C30[0x21].unk8 == 0x40)
    {
        gUnk_03000440.unk86 = 0x3C;
        gUnk_03001800.unkAA++;
    }
    else
    {
        gUnk_03002C30[0x21].unk8 += 4;
        gUnk_03002C30[0x21].unk9 += 4;
    }
}

void sub_0802C758(void)
{
    if (gUnk_03002C30[0x21].unk8 == 0x20)
    {
        gUnk_03001800.unkAA++;
    }
    else
    {
        gUnk_03002C30[0x21].unk8 -= 4;
        gUnk_03002C30[0x21].unk9 -= 4;
    }
}

void sub_0802C790(void)
{
    u32 i;
    u32 found = 0;

    sub_0803836C();
    gUnk_03001800.unk60 = sub_08032FC4(gUnk_03001800.unk87);
    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03000590[gUnk_03001800.unk60 + i].unk40 != 0
            && gUnk_03000590[gUnk_03001800.unk60 + i].parts[0].unk11 != 0
            && sub_080331F8(gUnk_03001800.unk60 + i) != 0)
        {
            gUnk_03001800.unkD2[i] = 1;
            found = 1;
        }
    }
    if (!found)
        gUnk_03001800.unkAA++;
    else
        gUnk_03001800.unkAA += 3;
}

void sub_0802C820(void)
{
    if (gUnk_03002C30[0x21].unk8 == 4)
    {
        clear_battle_sprite_slot(0x21, 1);
        gUnk_03001800.unkAA++;
    }
    else
    {
        gUnk_03002C30[0x21].unk8 -= 4;
        gUnk_03002C30[0x21].unk9 -= 4;
    }
}

INCLUDE_ASM("asm/nonmatching/code_08028A00", sub_0802C864);
INCLUDE_ASM("asm/nonmatching/code_08028A00", sub_0802C960);
