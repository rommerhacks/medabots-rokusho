#include "global.h"

void sub_080209B0(void)
{
    gUnk_03001800.unkB5 = 0;
    gUnk_083AD93C[gUnk_03001800.unkAA]();
}

void sub_080209D8(void)
{
    u32 r;

    if (!gUnk_03000590[gUnk_03001800.unk88].parts[gUnk_03001800.unk8B].unk11)
    {
        calc_battle_action_speed(gUnk_03001800.unk87, gUnk_03001800.unkA7);
        apply_battle_bot_damage_reduction(gUnk_03001800.unk87);
        r = decrement_battle_timer_and_check_zero();
        if (r)
        {
            gUnk_03001800.unkA6 = 0x1A;
            gUnk_03001800.unkAA = 2;
            gUnk_03001800.unkAB = 1;
        }
        else
        {
            calc_battle_stat_ratio(gUnk_03001800.unk87, gUnk_03001800.unkA7);
            sub_08036270();
            gUnk_03001800.unkAA++;
            gUnk_03001800.unkAB = r;
        }
    }
    else
    {
        gUnk_03001800.unkA6 = 0x27;
        gUnk_03001800.unkAA = 2;
        gUnk_03001800.unkAB = 1;
    }
}

void sub_08020A68(void)
{
    gUnk_03001800.unkB5 = 0;
    gUnk_083AD95C[gUnk_03001800.unkAA]();
}

void sub_08020A90(void)
{
    clear_battle_sprite_slot(0, 0x80);
    gUnk_03001800.unkD0 = gUnk_03001800.unk8B;
    battle_set_damage_display(gUnk_03001800.unk88, gUnk_03001800.unkD0, gUnk_03001800.unkEC);
    gUnk_03001800.unkAA++;
}

void sub_08020AD0(void)
{
    u32 part;
    struct Unk_03001800 *s = &gUnk_03001800;

    sub_080351E8(s->unk88);
    if (gUnk_03000590[s->unk87].parts[s->unkA7].data[7] && s->unkCA
        && (part = find_random_available_part_slot(s->unk88)))
    {
        part--;
        s->unkD0 = part;
        s->unk8B = part;
        battle_set_damage_display(s->unk88, s->unkD0, s->unkCA);
        s->unkAA = 0xF;
    }
    else
    {
        s->unkAA++;
    }
}

void sub_08020B4C(void)
{
    battle_check_action_counter(&gUnk_03001800.unkC8, gUnk_03001800.unk88, gUnk_03001800.unk8B);
    if (gUnk_03001800.unkF8 & 2)
    {
        get_active_bot_part_index_and_load_values(0);
        init_scene_with_bg_and_palette(0, gUnk_03001800.unk64[0], gUnk_03001800.unk64[1], gUnk_03001800.unk64[2], gUnk_03001800.unk64[3],
            (s16)gUnk_03001800.unk154, (s16)gUnk_03001800.unk156, gUnk_03001800.unk39[3] + 2, 4, 0, 2, 0, gUnk_03001800.unk114[0]);
        init_scene_with_bg_and_palette(0, gUnk_03001800.unk64[0], gUnk_03001800.unk64[1], gUnk_03001800.unk64[2], gUnk_03001800.unk64[3],
            (s16)gUnk_03001800.unk154, (s16)gUnk_03001800.unk156, gUnk_03001800.unk39[3] + 2, 4, 0, 1, 0, gUnk_03001800.unk114[0]);
    }
    else
    {
        get_active_bot_part_index_and_load_values(1);
        init_scene_with_bg_and_palette(1, gUnk_03001800.unk64[0], gUnk_03001800.unk64[1], gUnk_03001800.unk64[2], gUnk_03001800.unk64[3],
            (s16)gUnk_03001800.unk158, (s16)gUnk_03001800.unk15A, gUnk_03001800.unk39[3] + 2, 8, 1, 2, 1, gUnk_03001800.unk114[1]);
        init_scene_with_bg_and_palette(1, gUnk_03001800.unk64[0], gUnk_03001800.unk64[1], gUnk_03001800.unk64[2], gUnk_03001800.unk64[3],
            (s16)gUnk_03001800.unk158, (s16)gUnk_03001800.unk15A, gUnk_03001800.unk39[3] + 2, 8, 1, 1, 1, gUnk_03001800.unk114[1]);
    }
    gUnk_03001800.unkAA++;
}

void sub_08020CEC(void)
{
    gUnk_03001800.unkAA = 2;
}

void sub_08020CFC(void)
{
    gUnk_03001800.unkB5 = 0;
    gUnk_083AD9C0[gUnk_03001800.unkAA]();
}

void sub_08020D24(void)
{
    u32 r;

    calc_battle_action_speed(gUnk_03001800.unk87, gUnk_03001800.unkA7);
    apply_battle_bot_damage_reduction(gUnk_03001800.unk87);
    r = decrement_battle_timer_and_check_zero();
    if (r)
    {
        gUnk_03001800.unkA6 = 0x1A;
        gUnk_03001800.unkAA++;
        return;
    }
    calc_battle_stat_ratio(gUnk_03001800.unk87, gUnk_03001800.unkA7);
    sub_08036270();
    switch (gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03001800.unkA7].data[1])
    {
    case 0xA:
        gUnk_03001800.unk51 = r;
        break;
    case 0xB:
        gUnk_03001800.unk51 = 1;
        break;
    case 0xC:
        gUnk_03001800.unk51 = 2;
        break;
    default:
        gUnk_03001800.unk51 = 3;
        break;
    }
    gUnk_03001800.unk52 = gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03001800.unkA7].data[1];
    gUnk_03001800.unkAA = 4;
}

void sub_08020DF8(void)
{
    lz_decompress_dispatch(gUnk_084D50DC, (void *)0x06015800);
    CpuFastSet(gUnk_0850E658, (void *)0x050002E0, 8);
    gUnk_03002C30[0x21].unk0 = 0xC604;
    gUnk_03002C30[0x21].unk1C = 0;
    gUnk_03002C30[0x21].unk2 = gUnk_03002C30[0x5D + gUnk_03001800.unk87 * 4].unk2;
    gUnk_03002C30[0x21].unk4 = gUnk_03002C30[0x5D + gUnk_03001800.unk87 * 4].unk4 - 4;
    gUnk_03002C30[0x21].unkA = 7;
    gUnk_03002C30[0x21].unkB = 0xF0;
    gUnk_03002C30[0x21].unk8 = 0x40;
    gUnk_03002C30[0x21].unk9 = 0x40;
    gUnk_03002C30[0x21].unk18 = 0;
    gUnk_03002C30[0x21].unk6 = 0x4100;
    gUnk_03002C30[0x21].unk23 = 0;
    gUnk_03002C30[0x21].unk27 = 0;
    play_sound_effect(0x29);
    gUnk_03001800.unkAA++;
}

void sub_08020EDC(void)
{
    sub_080353CC(0x21);
    if (gUnk_03002C30[0x21].unk27 == 0x20)
    {
        gUnk_03002C30[0x21].unk0 &= ~0x200;
        gUnk_03002C30[0x21].unk18 = 0;
        gUnk_03001800.unkAA++;
        return;
    }
    if (!(gUnk_03001800.unkF8 & 1))
        gUnk_03002C30[0x21].unk18 = (gUnk_03002C30[0x21].unk18 + 0x20) & 0x3FF;
    else
        gUnk_03002C30[0x21].unk18 = (gUnk_03002C30[0x21].unk18 - 0x20) & 0x3FF;
    if (!(gUnk_03002C30[0x21].unk27 & 1))
    {
        if (!(gUnk_03001800.unkF8 & 1))
            gUnk_03002C30[0x21].unk2++;
        else
            gUnk_03002C30[0x21].unk2--;
    }
    gUnk_03002C30[0x21].unk27++;
}

void sub_08020FB8(void)
{
    lz_decompress_dispatch(gUnk_084CCE48, (void *)0x06014800);
    CpuFastSet(gUnk_0850E358, (void *)0x050002E0, 8);
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x23], 0x21);
    gUnk_03001800.unkAA++;
}

void sub_08021000(void)
{
    process_sprite_anim_commands(gUnk_083B5F80[0x23], 0x21);
    if (gUnk_03002C30[0x21].unk22 == 0xFF)
        gUnk_03001800.unkAA++;
}

void sub_08021038(void)
{
    switch (gUnk_03001800.unk51)
    {
    case 0:
        lz_decompress_dispatch(gUnk_084C907C, (void *)0x06014800);
        CpuFastSet(gUnk_0850E058, (void *)0x050002E0, 8);
        gUnk_03002C30[0x21].unk4 = 0x3C;
        init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x19], 0x21);
        break;
    case 1:
        lz_decompress_dispatch(gUnk_084C9288, (void *)0x06014800);
        CpuFastSet(gUnk_0850E078, (void *)0x050002E0, 8);
        gUnk_03002C30[0x21].unk4 = 0x3C;
        init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x1A], 0x21);
        break;
    case 2:
        lz_decompress_dispatch(gUnk_084C9624, (void *)0x06014800);
        CpuFastSet(gUnk_0850E098, (void *)0x050002E0, 8);
        gUnk_03002C30[0x21].unk4 = 0x3C;
        gUnk_03002C30[0x21].unk6 = 0xD00;
        break;
    case 3:
        lz_decompress_dispatch(gUnk_084D513C, (void *)0x06014800);
        CpuFastSet(gUnk_0850E678, (void *)0x050002E0, 8);
        init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x38], 0x21);
        break;
    }
    gUnk_03002C30[0x21].unk0 |= 0x220;
    gUnk_03002C30[0x21].unk9 = 0x40;
    gUnk_03002C30[0x21].unk8 = 8;
    if (gUnk_03001800.unkF8 & 1)
    {
        gUnk_03002C30[0x21].unk0 |= 0x1000;
        gUnk_03002C30[0x21].unk2--;
    }
    gUnk_03001800.unkAA++;
}

void sub_080211C8(void)
{
    if ((gUnk_03002C30[0x21].unk8 += 8) == 0x40)
    {
        if (gUnk_03001800.unk51 == 3)
            gUnk_03000440.unk86 = 1;
        else
            gUnk_03000440.unk86 = 0x3C;
        gUnk_03001800.unkAA++;
    }
}

void sub_0802121C(void)
{
    gUnk_03000440.unk86--;
    if (gUnk_03000440.unk89 == 0 && (*(u8 *)&gRepeatKeys & 1))
        gUnk_03000440.unk86 = 0;
    if (gUnk_03000440.unk86 == 0)
    {
        switch (gUnk_03001800.unk51)
        {
        case 0:
        case 1:
        case 2:
            gUnk_03002C30[0x21].unk27 = 0;
            gUnk_03001800.unkAA++;
            break;
        case 3:
            play_sound_effect(0x52);
            gUnk_03001800.unkAA = 0x20;
            break;
        }
    }
}

void sub_080212A0(void)
{
    if (gUnk_03002C30[0x21].unk27 == 0x10)
    {
        gUnk_03001800.unkAA++;
        return;
    }
    if (!(gUnk_03001800.unkF8 & 1))
        gUnk_03002C30[0x21].unk2++;
    else
        gUnk_03002C30[0x21].unk2--;
    gUnk_03002C30[0x21].unk27++;
}

void sub_08021300(void)
{
    if (gUnk_03001800.unk28[gUnk_03001800.unk8A].unk2 && gUnk_03001800.unk28[gUnk_03001800.unk8A].unk3 == gUnk_03001800.unk52)
    {
        gUnk_03002C30[0x21].unk27 = 0;
        gUnk_03001800.unkAA++;
    }
    else if (gUnk_03001800.unk51 == 2)
    {
        gUnk_03001800.unkAA = 0x14;
    }
    else
    {
        play_sound_effect(0x3E);
        gUnk_03001800.unkAA = 0xE;
    }
}

void sub_08021370(void)
{
    if (gUnk_03002C30[0x21].unk27 == 0x10)
    {
        if (gUnk_03001800.unk51 == 2)
        {
            gUnk_03001800.unkAA = 0x14;
        }
        else
        {
            play_sound_effect(0x3E);
            gUnk_03001800.unkAA = 0xE;
        }
        return;
    }
    if (gUnk_03002C30[0x21].unk27 < 8)
        gUnk_03002C30[0x21].unk8 += 8;
    else
        gUnk_03002C30[0x21].unk8 -= 8;
    gUnk_03002C30[0x21].unk27++;
}

void sub_080213E4(void)
{
    if (gUnk_03002C30[0x21].unk8 == 8)
    {
        clear_battle_sprite_slot(0x21, 1);
        gUnk_03001800.unkAA++;
    }
    else
    {
        gUnk_03002C30[0x21].unk8 -= 8;
    }
}

INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08021418);

void sub_08021564(void)
{
    switch (gUnk_03001800.unk51)
    {
    case 0:
        gUnk_03001800.unkA6 = 0x1E;
        break;
    case 1:
        gUnk_03001800.unkA6 = 0x1F;
        break;
    case 2:
        gUnk_03001800.unkA6 = 0x20;
        break;
    case 3:
        gUnk_03001800.unkA6 = 0x21;
        break;
    }
    if (gUnk_03001800.unk53)
        gUnk_03001800.unkA6 = 0x71;
    gUnk_03001800.unkAA++;
}

void sub_080215C8(void)
{
    gUnk_03002C30[0x21].unk24 = 4;
    gUnk_03002C30[0x21].unk25 = 0;
    gUnk_03002C30[0x21].unk30 = 0;
    play_sound_effect(0x40);
    gUnk_03001800.unkAA++;
}

void sub_08021608(void)
{
    if (update_sprite_deceleration(0x21, -0x40, -0x30))
    {
        clear_battle_sprite_slot(0x21, 1);
        gUnk_03001800.unkAA++;
    }
}

void sub_08021638(void)
{
    process_sprite_anim_commands(gUnk_083B5F80[0x38], 0x21);
    if (gUnk_03002C30[0x21].unk22 == 0xFF)
    {
        gUnk_03000440.unk86 = 0x3C;
        gUnk_03001800.unkAA++;
    }
}

void sub_0802167C(void)
{
    struct Unk_03002C30 *spr;

    gUnk_03000440.unk86--;
    if (gUnk_03000440.unk89 == 0 && (*(u8 *)&gRepeatKeys & 1))
        gUnk_03000440.unk86 = 0;
    if (gUnk_03000440.unk86 == 0)
    {
        spr = &gUnk_03002C30[0x21];
        memcpy_bytes_0803F63C(spr, spr + 1, 0x40);
        memcpy_bytes_0803F63C(spr, spr + 2, 0x40);
        spr[0].unk32 = 0x58;
        spr[0].unk24 = 6;
        spr[1].unk32 = 0x40;
        spr[1].unk24 = 6;
        spr[2].unk32 = 0x28;
        spr[2].unk24 = 6;
        if (!(gUnk_03001800.unkF8 & 1))
            spr[2].unk30 = spr[1].unk30 = spr[0].unk30 = 0x88;
        else
            spr[2].unk30 = spr[1].unk30 = spr[0].unk30 = 0x68;
        gUnk_03001800.unkAA++;
    }
}

void sub_08021734(void)
{
    u32 r = move_sprite_toward_target(0x21);
    u32 n = (r | -r) >> 31;
    if (move_sprite_toward_target(0x22))
        n++;
    if (move_sprite_toward_target(0x23))
        n++;
    if (n == 3)
        gUnk_03001800.unkAA++;
}

void sub_08021774(void)
{
    if (gUnk_03001800.unk28[gUnk_03001800.unk8A].unk2 && gUnk_03001800.unk28[gUnk_03001800.unk8A].unk3 == gUnk_03001800.unk52)
    {
        gUnk_03002C30[0x21].unk27 = 0;
        gUnk_03001800.unkAA++;
    }
    else
    {
        play_sound_effect(0x3E);
        gUnk_03001800.unkAA = 0x25;
    }
}

void sub_080217D8(void)
{
    if (gUnk_03002C30[0x21].unk27 == 0x10)
    {
        play_sound_effect(0x3E);
        gUnk_03001800.unkAA++;
        return;
    }
    if (gUnk_03002C30[0x21].unk27 < 8)
    {
        gUnk_03002C30[0x21].unk8 += 8;
        gUnk_03002C30[0x22].unk8 += 8;
        gUnk_03002C30[0x23].unk8 += 8;
    }
    else
    {
        gUnk_03002C30[0x21].unk8 -= 8;
        gUnk_03002C30[0x22].unk8 -= 8;
        gUnk_03002C30[0x23].unk8 -= 8;
    }
    gUnk_03002C30[0x21].unk27++;
}

void sub_0802186C(void)
{
    if (gUnk_03002C30[0x21].unk8 == 8)
    {
        clear_battle_sprite_slot(0x21, 3);
        gUnk_03001800.unkAA++;
    }
    else
    {
        gUnk_03002C30[0x21].unk8 -= 8;
        gUnk_03002C30[0x22].unk8 -= 8;
        gUnk_03002C30[0x23].unk8 -= 8;
    }
}

void sub_080218BC(void)
{
    gUnk_03001800.unkB5 = 0;
    gUnk_083ADA6C[gUnk_03001800.unkAA]();
}

void sub_080218E4(void)
{
    calc_battle_action_speed(gUnk_03001800.unk87, gUnk_03001800.unkA7);
    apply_battle_bot_damage_reduction(gUnk_03001800.unk87);
    if (decrement_battle_timer_and_check_zero())
    {
        gUnk_03001800.unkA6 = 0x1A;
        gUnk_03001800.unkAA++;
    }
    else if (!gUnk_03001800.unk28[gUnk_03001800.unk89].unk2)
    {
        gUnk_03001800.unkA6 = 0x24;
        gUnk_03001800.unkAA++;
    }
    else
    {
        sub_08036270();
        gUnk_03001800.unkAA = 4;
    }
}

void sub_08021950(void)
{
    lz_decompress_dispatch(gUnk_084D54BC, (void *)0x06014800);
    CpuFastSet(gUnk_0850E698, (void *)0x050002E0, 8);
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x39], 0x21);
    if (gUnk_03001800.unkF8 & 1)
        gUnk_03002C30[0x21].unk0 |= 0x1000;
    gUnk_03001800.unkAA++;
}

void sub_080219C0(void)
{
    process_sprite_anim_commands(gUnk_083B5F80[0x39], 0x21);
    if (gUnk_03002C30[0x21].unk22 == 0xFF)
    {
        init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x3B], 0x21);
        gUnk_03000440.unk86 = 0x3C;
        gUnk_03001800.unkAA++;
    }
}

void sub_08021A14(void)
{
    process_sprite_anim_commands(gUnk_083B5F80[0x3B], 0x21);
    gUnk_03000440.unk86--;
    if (gUnk_03000440.unk89 == 0 && (*(u8 *)&gRepeatKeys & 1))
        gUnk_03000440.unk86 = 0;
    if (gUnk_03000440.unk86 == 0)
        gUnk_03001800.unkAA++;
}

void sub_08021A6C(void)
{
    struct Unk_03002C30 *spr;

    process_sprite_anim_commands(gUnk_083B5F80[0x3B], 0x21);
    spr = &gUnk_03002C30[0x21];
    memcpy_bytes_0803F63C(spr, spr + 1, 0x40);
    memcpy_bytes_0803F63C(spr, spr + 2, 0x40);
    spr[0].unk32 = 0x58;
    spr[0].unk24 = 6;
    spr[1].unk32 = 0x40;
    spr[1].unk24 = 6;
    spr[2].unk32 = 0x28;
    spr[2].unk24 = 6;
    if (gUnk_03001800.unkF8 & 1)
        spr[2].unk30 = spr[1].unk30 = spr[0].unk30 = 0x88;
    else
        spr[2].unk30 = spr[1].unk30 = spr[0].unk30 = 0x68;
    gUnk_03001800.unkAA++;
}

void sub_08021AFC(void)
{
    u32 r, n;

    process_sprite_anim_commands(gUnk_083B5F80[0x3B], 0x21);
    process_sprite_anim_commands(gUnk_083B5F80[0x3B], 0x22);
    process_sprite_anim_commands(gUnk_083B5F80[0x3B], 0x23);
    r = move_sprite_toward_target(0x21);
    n = (r | -r) >> 31;
    if (move_sprite_toward_target(0x22))
        n++;
    if (move_sprite_toward_target(0x23))
        n++;
    if (n == 3)
    {
        init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x3A], 0x21);
        init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x3A], 0x22);
        init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x3A], 0x23);
        gUnk_03001800.unkAA++;
    }
}

void sub_08021B78(void)
{
    process_sprite_anim_commands(gUnk_083B5F80[0x3A], 0x21);
    process_sprite_anim_commands(gUnk_083B5F80[0x3A], 0x22);
    process_sprite_anim_commands(gUnk_083B5F80[0x3A], 0x23);
    if (gUnk_03002C30[0x21].unk22 == 0xFF)
    {
        clear_sprite_table_mask(0x21, 3);
        gUnk_03000440.unk86 = 0x3C;
        gUnk_03001800.unkAA++;
    }
}

void sub_08021BD8(void)
{
    u32 i;

    lz_decompress_dispatch(gUnk_084CCE48, (void *)0x06014800);
    CpuFastSet(gUnk_0850E358, (void *)0x050002E0, 8);
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x23], 0x21);
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x23], 0x22);
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x23], 0x23);
    set_sprite_hidden_flags(0x21, 3);
    for (i = 0; i < 6; i++)
    {
        if (gUnk_03000590[i].unk40)
        {
            gUnk_03002C30[0x5A + i * 4].unk23 = 0;
            gUnk_03002C30[0x5B + i * 4].unk23 = 0;
            gUnk_03002C30[0x5C + i * 4].unk23 = 0;
            gUnk_03002C30[0x5D + i * 4].unk23 = 0;
        }
    }
    gUnk_03000440.unk86 = 0;
    gUnk_03001800.unkAA++;
}

void sub_08021C94(void)
{
    u32 i;

    gUnk_03000440.unk86++;
    sub_080353AC(gUnk_03000440.unk86);
    for (i = 0; i < 6; i++)
    {
        if (gUnk_03000590[i].unk40)
        {
            advance_sprite_anim_frame(0x5A + i * 4, 0);
            advance_sprite_anim_frame(0x5B + i * 4, 0);
            advance_sprite_anim_frame(0x5C + i * 4, 0);
            advance_sprite_anim_frame(0x5D + i * 4, 0);
        }
    }
    process_sprite_anim_commands(gUnk_083B5F80[0x23], 0x21);
    process_sprite_anim_commands(gUnk_083B5F80[0x23], 0x22);
    process_sprite_anim_commands(gUnk_083B5F80[0x23], 0x23);
    if (gUnk_03002C30[0x21].unk22 == 0xFF)
    {
        for (i = 0; i < 6; i++)
        {
            if (gUnk_03000590[i].unk40)
            {
                gUnk_03002C30[0x5A + i * 4].unk23 = 0;
                gUnk_03002C30[0x5B + i * 4].unk23 = 0;
                gUnk_03002C30[0x5C + i * 4].unk23 = 0;
                gUnk_03002C30[0x5D + i * 4].unk23 = 0;
            }
        }
        gBg3Scroll.y = 0;
        clear_battle_sprite_slot(0x21, 3);
        gUnk_03001800.unkAA++;
    }
}

void sub_08021DAC(void)
{
    gUnk_03001800.unk28[gUnk_03001800.unk89].unk2 = 0;
    gUnk_03001800.unk28[gUnk_03001800.unk89].unk3 = 0;
    gUnk_03001800.unk28[gUnk_03001800.unk89].unk4 = 0;
    gUnk_03001800.unk28[gUnk_03001800.unk89].unk5 = 0;
    gUnk_03001800.unkAA++;
}

void sub_08021DEC(void)
{
    gUnk_03001800.unkA6 = 0x25;
    gUnk_03001800.unkAA++;
}

void sub_08021E04(void)
{
    gUnk_03001800.unkB5 = 0;
    gUnk_083ADAEC[gUnk_03001800.unkAA]();
}

void sub_08021E2C(void)
{
    calc_battle_action_speed(gUnk_03001800.unk87, gUnk_03001800.unkA7);
    apply_battle_bot_damage_reduction(gUnk_03001800.unk87);
    if (decrement_battle_timer_and_check_zero())
    {
        gUnk_03001800.unkA6 = 0x1A;
        gUnk_03001800.unkAA++;
    }
    else if (!gUnk_03000590[gUnk_03001800.unk88].unkC9)
    {
        gUnk_03001800.unkA6 = 0x70;
        gUnk_03001800.unkAA++;
    }
    else
    {
        sub_08036270();
        gUnk_03001800.unkAA = 4;
    }
}

void sub_08021EA0(void)
{
    lz_decompress_dispatch(gUnk_084D55D0, (void *)0x06014800);
    CpuFastSet(gUnk_0850E6B8, (void *)0x050002E0, 8);
    if (gUnk_03001800.unkF8 & 1)
        gUnk_03002C30[0x21].unk0 |= 0x1000;
    gUnk_03002C30[0x21].unk0 |= 0x200;
    gUnk_03002C30[0x21].unk8 = 0x40;
    gUnk_03002C30[0x21].unk9 = 0x40;
    gUnk_03002C30[0x21].unk18 = 0;
    gUnk_03002C30[0x21].unk30 = gUnk_03002C30[gUnk_03001800.unk88 * 4 + 0x5D].unk2;
    gUnk_03002C30[0x21].unk32 = gUnk_03002C30[gUnk_03001800.unk88 * 4 + 0x5D].unk4 - 4;
    gUnk_03002C30[0x21].unk24 = 6;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x3C], 0x21);
    gUnk_03000440.unk86 = 0x3C;
    gUnk_03001800.unkAA++;
}

void sub_08021F90(void)
{
    if (!(gUnk_03001800.unkF8 & 1))
        gUnk_03002C30[0x21].unk18 = (gUnk_03002C30[0x21].unk18 - 0x40) & 0x3FF;
    else
        gUnk_03002C30[0x21].unk18 = (gUnk_03002C30[0x21].unk18 + 0x40) & 0x3FF;
    if (move_sprite_toward_target(0x21))
    {
        gUnk_03002C30[0x21].unk0 &= ~0x200;
        gUnk_03002C30[0x21].unk18 = 0;
        gUnk_03001800.unkAA++;
    }
}

void sub_08022010(void)
{
    gUnk_03000590[gUnk_03001800.unk88].unkC9 = 0;
    gUnk_03000590[gUnk_03001800.unk88].unkCA = 0;
    gUnk_03000590[gUnk_03001800.unk88].unkCB = 0;
    gUnk_03000590[gUnk_03001800.unk88].unkCC = 0;
    gUnk_03002C30[gUnk_03001800.unk88 * 3 + 0x47].unk0 |= 0x8220;
    gUnk_03002C30[gUnk_03001800.unk88 * 3 + 0x47].unk9 = 0x40;
    gUnk_03002C30[gUnk_03001800.unk88 * 3 + 0x47].unk8 = 0x40;
    play_sound_effect(0x37);
    gUnk_03001800.unkAA++;
}

void sub_080220A0(void)
{
    if (gUnk_03002C30[gUnk_03001800.unk88 * 3 + 0x47].unk8 != 4)
    {
        gUnk_03002C30[gUnk_03001800.unk88 * 3 + 0x47].unk0 |= 0x8000;
        gUnk_03002C30[gUnk_03001800.unk88 * 3 + 0x47].unk9 += 4;
        gUnk_03002C30[gUnk_03001800.unk88 * 3 + 0x47].unk8 -= 4;
    }
    process_sprite_anim_commands(gUnk_083B5F80[0x3C], 0x21);
    if (gUnk_03002C30[0x21].unk22 == 0xFF)
    {
        clear_battle_sprite_slot(0x21, 1);
        clear_battle_sprite_slot(gUnk_03001800.unk88 * 3 + 0x47, 1);
        gUnk_03001800.unkAA++;
    }
}

void sub_0802213C(void)
{
    gUnk_03001800.unkA6 = 0x23;
    gUnk_03001800.unkAA++;
}

void sub_08022154(void)
{
    gUnk_03001800.unkB5 = 0;
    gUnk_083ADB2C[gUnk_03001800.unkAA]();
}

void sub_0802217C(void)
{
    calc_battle_action_speed(gUnk_03001800.unk87, gUnk_03001800.unkA7);
    apply_battle_bot_damage_reduction(gUnk_03001800.unk87);
    if (decrement_battle_timer_and_check_zero())
    {
        gUnk_03001800.unkA6 = 0x1A;
        gUnk_03001800.unkAA++;
    }
    else
    {
        sub_08036270();
        gUnk_03001800.unkAA = 4;
    }
}

void sub_080221C8(void)
{
    u32 i;

    lz_decompress_dispatch(gUnk_084D5788, (void *)0x06014800);
    CpuFastSet(gUnk_0850E6D8, (void *)0x050002E0, 8);
    for (i = 0; i < 4; i++)
    {
        gUnk_03002C30[0x21 + i].unk0 = 0xC604;
        gUnk_03002C30[0x21 + i].unk1C = 0;
        gUnk_03002C30[0x21 + i].unk2 = gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk2;
        gUnk_03002C30[0x21 + i].unk4 = gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 4;
        gUnk_03002C30[0x21 + i].unkA = 7;
        gUnk_03002C30[0x21 + i].unkB = 0xF0;
        gUnk_03002C30[0x21 + i].unk8 = 0x40;
        gUnk_03002C30[0x21 + i].unk9 = 0x40;
        gUnk_03002C30[0x21 + i].unk2B = 0;
        gUnk_03002C30[0x21 + i].unk2C = i << 6;
        gUnk_03002C30[0x21 + i].unk2D = 0;
        init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x3D], 0x21 + i);
    }
    play_sound_effect(0x5C);
    gUnk_03001800.unkAA++;
}

void sub_080222A8(void)
{
    u32 i;
    s32 pos, v;

    for (i = 0; i < 4; i++)
    {
        process_sprite_anim_commands(gUnk_083B5F80[0x3D], 0x21 + i);
        calc_polar_to_screen_coords(&pos, gUnk_03002C30[0x21 + i].unk2C, gUnk_03002C30[0x21 + i].unk2B,
                                    gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk2,
                                    gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 4);
        v = pos;
        gUnk_03002C30[0x21 + i].unk2 = v;
        gUnk_03002C30[0x21 + i].unk4 = v >> 16;
        gUnk_03002C30[0x21 + i].unk2C += 4;
        gUnk_03002C30[0x21 + i].unk2D++;
        if (!(gUnk_03002C30[0x21 + i].unk2D & 3))
            gUnk_03002C30[0x21 + i].unk2B++;
        if (gUnk_03002C30[0x21 + i].unk2D > 0xB4)
        {
            gUnk_03002C30[0x21 + i].unk8 -= 4;
            gUnk_03002C30[0x21 + i].unk9 -= 4;
        }
    }
    if (gUnk_03002C30[0x21].unk9 == 4)
    {
        clear_battle_sprite_slot(0x21, 4);
        gUnk_03001800.unkAA++;
    }
}

void sub_08022380(void)
{
    if (!gUnk_03001800.unk58)
    {
        gUnk_03001800.unkA6 = 0x72;
        gUnk_03001800.unk58 = 1;
    }
    else
    {
        gUnk_03001800.unkA6 = 0x73;
        gUnk_03001800.unk58 = 0;
    }
    gUnk_03001800.unkAA++;
}

void sub_080223BC(void)
{
    gUnk_03001800.unkB5 = 0;
    gUnk_083ADB6C[gUnk_03001800.unkAA]();
}

void sub_080223E4(void)
{
    u32 r;

    calc_battle_action_speed(gUnk_03001800.unk87, gUnk_03001800.unkA7);
    apply_battle_bot_damage_reduction(gUnk_03001800.unk87);
    r = decrement_battle_timer_and_check_zero();
    if (r)
    {
        gUnk_03001800.unkA6 = 0x1A;
        gUnk_03001800.unkAA++;
    }
    else
    {
        sub_08036270();
        switch (gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03001800.unkA7].data[1])
        {
        case 0x1B:
            gUnk_03001800.unk51 = r;
            break;
        case 0x1C:
            gUnk_03001800.unk51 = 1;
            break;
        default:
            gUnk_03001800.unk51 = 2;
            break;
        }
        calc_battle_stat_ratio(gUnk_03001800.unk87, gUnk_03001800.unkA7);
        gUnk_03001800.unkAA = 4;
    }
}

void sub_08022480(void)
{
    switch (gUnk_03001800.unk51)
    {
    case 0:
        lz_decompress_dispatch(gUnk_084C9880, (void *)0x06014800);
        CpuFastSet(gUnk_0850E0F8, (void *)0x050002E0, 8);
        break;
    case 1:
        lz_decompress_dispatch(gUnk_084C9B88, (void *)0x06014800);
        CpuFastSet(gUnk_0850E118, (void *)0x050002E0, 8);
        break;
    default:
        lz_decompress_dispatch(gUnk_084C9E9C, (void *)0x06014800);
        CpuFastSet(gUnk_0850E138, (void *)0x050002E0, 8);
        break;
    }
    gUnk_03002C30[0x21].unk0 = 0xC624;
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
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x1C], 0x21);
    gUnk_03002C30[0x22].unk0 = 0xC624;
    gUnk_03002C30[0x22].unk1C = 0;
    gUnk_03002C30[0x22].unk2 = gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk2 + 0x20;
    gUnk_03002C30[0x22].unk4 = gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 4;
    gUnk_03002C30[0x22].unkA = 7;
    gUnk_03002C30[0x22].unkB = 0xF0;
    gUnk_03002C30[0x22].unk8 = 0x80;
    gUnk_03002C30[0x22].unk9 = 0x80;
    gUnk_03002C30[0x22].unk2B = 0x1C;
    gUnk_03002C30[0x22].unk2C = 0x80;
    gUnk_03002C30[0x22].unk2D = 0;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x1C], 0x22);
    play_sound_effect(0x33);
    gUnk_03001800.unkAA++;
}

void sub_08022648(void)
{
    u32 i;
    s32 pos, v;

    for (i = 0; i < 2; i++)
    {
        calc_polar_to_screen_coords(&pos, gUnk_03002C30[0x21 + i].unk2C, gUnk_03002C30[0x21 + i].unk2B,
                                    gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk2,
                                    gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 4);
        v = pos;
        gUnk_03002C30[0x21 + i].unk2 = v;
        gUnk_03002C30[0x21 + i].unk4 = v >> 16;
        gUnk_03002C30[0x21 + i].unk2C += 8;
        gUnk_03002C30[0x21 + i].unk2D++;
        if (!(gUnk_03002C30[0x21 + i].unk2D & 3))
            gUnk_03002C30[0x21 + i].unk2B--;
        if (gUnk_03002C30[0x21 + i].unk8 != 0x40)
        {
            gUnk_03002C30[0x21 + i].unk8--;
            gUnk_03002C30[0x21 + i].unk9--;
        }
    }
    if (gUnk_03002C30[0x21].unk2B == 0)
    {
        play_sound_effect(0x30);
        clear_battle_sprite_slot(0x22, 1);
        gUnk_03001800.unkAA++;
    }
}

void sub_08022708(void)
{
    process_sprite_anim_commands(gUnk_083B5F80[0x1C], 0x21);
    if (gUnk_03002C30[0x21].unk22 == 0xFF)
    {
        clear_battle_sprite_slot(0x21, 1);
        gUnk_03001800.unkAA++;
    }
}

INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08022748);

void sub_080227C0(void)
{
    gUnk_03001800.unkA6 = 0x1B;
    gUnk_03001800.unkAA++;
}

void sub_080227D8(void)
{
    gUnk_03001800.unkB5 = 0;
    gUnk_083ADBAC[gUnk_03001800.unkAA]();
}

void sub_08022800(void)
{
    calc_battle_action_speed(gUnk_03001800.unk87, gUnk_03001800.unkA7);
    apply_battle_bot_damage_reduction(gUnk_03001800.unk87);
    if (decrement_battle_timer_and_check_zero())
    {
        gUnk_03001800.unkA6 = 0x1A;
        gUnk_03001800.unkAA++;
    }
    else if (!sub_080331F8(gUnk_03001800.unk88))
    {
        gUnk_03001800.unkA6 = 0x39;
        gUnk_03001800.unkAA++;
    }
    else
    {
        sub_08036270();
        calc_battle_stat_ratio(gUnk_03001800.unk87, gUnk_03001800.unkA7);
        gUnk_03001800.unkAA = 4;
    }
}

void sub_08022870(void)
{
    lz_decompress_dispatch(gUnk_084D5860, (void *)0x06014800);
    CpuFastSet(gUnk_0850E6F8, (void *)0x050002C0, 0x10);
    gUnk_03002C30[0x21].unk0 |= 0x200;
    gUnk_03002C30[0x21].unk8 = 0x40;
    gUnk_03002C30[0x21].unk9 = 0x40;
    gUnk_03002C30[0x21].unkA = 6;
    gUnk_03002C30[0x21].unk30 = gUnk_03002C30[gUnk_03001800.unk88 * 4 + 0x5D].unk2;
    gUnk_03002C30[0x21].unk32 = gUnk_03002C30[gUnk_03001800.unk88 * 4 + 0x5D].unk4 - 4;
    gUnk_03002C30[0x21].unk24 = 6;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x3E], 0x21);
    gUnk_03000440.unk86 = 0x3C;
    gUnk_03001800.unkAA++;
}

void sub_08022938(void)
{
    process_sprite_anim_commands(gUnk_083B5F80[0x3E], 0x21);
    if (gUnk_03000440.unk89 == 0 && (*(u8 *)&gRepeatKeys & 1))
        gUnk_03001800.unkAA++;
    else if (gUnk_03000440.unk86)
        gUnk_03000440.unk86--;
    else
        gUnk_03001800.unkAA++;
}

void sub_08022990(void)
{
    process_sprite_anim_commands(gUnk_083B5F80[0x3E], 0x21);
    if (move_sprite_toward_target(0x21))
        gUnk_03001800.unkAA++;
}

void sub_080229C0(void)
{
    process_sprite_anim_commands(gUnk_083B5F80[0x3E], 0x21);
    if (gUnk_03002C30[0x21].unk8 == 8)
    {
        clear_battle_sprite_slot(0x21, 1);
        gUnk_03001800.unkAA++;
    }
    else
        gUnk_03002C30[0x21].unk8 -= 8;
}

void sub_08022A04(void)
{
    u32 i;
    s32 pos, v;

    gUnk_03002C30[0x25].unk0 = 0xC604;
    gUnk_03002C30[0x25].unk1C = 0;
    gUnk_03002C30[0x25].unk2 = gUnk_03002C30[gUnk_03001800.unk88 * 4 + 0x5D].unk2;
    gUnk_03002C30[0x25].unk4 = gUnk_03002C30[gUnk_03001800.unk88 * 4 + 0x5D].unk4 - 4;
    gUnk_03002C30[0x25].unkA = 7;
    gUnk_03002C30[0x25].unk8 = 0x40;
    gUnk_03002C30[0x25].unk9 = 0x40;
    gUnk_03002C30[0x25].unkB = 0xF0;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x3F], 0x25);
    for (i = 0; i < 4; i++)
    {
        gUnk_03002C30[0x21 + i].unk0 = 0xC604;
        calc_polar_to_screen_coords(&pos, i << 6, 0x10,
                                    gUnk_03002C30[gUnk_03001800.unk88 * 4 + 0x5D].unk2,
                                    gUnk_03002C30[gUnk_03001800.unk88 * 4 + 0x5D].unk4 - 4);
        v = pos;
        gUnk_03002C30[0x21 + i].unk2 = v;
        gUnk_03002C30[0x21 + i].unk4 = v >> 16;
        gUnk_03002C30[0x21 + i].unk1C = 0;
        gUnk_03002C30[0x21 + i].unkA = 7;
        gUnk_03002C30[0x21 + i].unkB = 0xF0;
        gUnk_03002C30[0x21 + i].unk6 = 0x4604;
        gUnk_03002C30[0x21 + i].unk8 = 0x40;
        gUnk_03002C30[0x21 + i].unk9 = 0x40;
        gUnk_03002C30[0x21 + i].unk2B = 0x10;
        gUnk_03002C30[0x21 + i].unk2C = i << 6;
        gUnk_03002C30[0x21 + i].unk2D = 0;
    }
    play_sound_effect(0x4A);
    gUnk_03001800.unkAA++;
}

void sub_08022B40(void)
{
    u32 i;
    s32 pos, v;
    u32 n;

    process_sprite_anim_commands(gUnk_083B5F80[0x3F], 0x25);
    for (i = 0; i < 5; i++)
    {
        if (i < 4)
        {
            calc_polar_to_screen_coords(&pos, gUnk_03002C30[0x21 + i].unk2C, gUnk_03002C30[0x21 + i].unk2B,
                                        gUnk_03002C30[gUnk_03001800.unk88 * 4 + 0x5D].unk2,
                                        gUnk_03002C30[gUnk_03001800.unk88 * 4 + 0x5D].unk4 - 4);
            v = pos;
            gUnk_03002C30[0x21 + i].unk2 = v;
            gUnk_03002C30[0x21 + i].unk4 = v >> 16;
            gUnk_03002C30[0x21 + i].unk2C += 4;
        }
        n = gUnk_03002C30[0x21 + i].unk2D + 1;
        gUnk_03002C30[0x21 + i].unk2D = n;
        if (gUnk_03002C30[0x21 + i].unk2D > 0x5A)
        {
            if (n & 1)
                gUnk_03002C30[0x21 + i].unk2B++;
            gUnk_03002C30[0x21 + i].unk8 -= 2;
            gUnk_03002C30[0x21 + i].unk9 -= 2;
        }
    }
    if (gUnk_03002C30[0x21].unk9 == 4)
    {
        clear_battle_sprite_slot(0x21, 5);
        gUnk_03001800.unkAA++;
    }
}

void sub_08022C28(void)
{
    gUnk_03000590[gUnk_03001800.unk88].unkC4 = 0x1F;
    gUnk_03000590[gUnk_03001800.unk88].unkC5 = 0;
    gUnk_03000590[gUnk_03001800.unk88].unkC6 = sub_08036E54(gUnk_03001800.unkE8);
    gUnk_03000590[gUnk_03001800.unk88].unkC7 = sub_08036E54(gUnk_03001800.unkEC);
    gUnk_03001800.unkAA++;
}

void sub_08022C90(void)
{
    gUnk_03001800.unkA6 = 0x29;
    gUnk_03001800.unkAA++;
}

void sub_08022CA8(void)
{
    gUnk_03001800.unkB5 = 0;
    gUnk_083ADC0C[gUnk_03001800.unkAA]();
}

void sub_08022CD0(void)
{
    calc_battle_action_speed(gUnk_03001800.unk87, gUnk_03001800.unkA7);
    apply_battle_bot_damage_reduction(gUnk_03001800.unk87);
    if (decrement_battle_timer_and_check_zero())
    {
        gUnk_03001800.unkA6 = 0x1A;
        gUnk_03001800.unkAA++;
    }
    else if (gUnk_03000590[gUnk_03001800.unk88].parts[0].unk11)
    {
        gUnk_03001800.unkA6 = 9;
        gUnk_03001800.unkAA++;
    }
    else
    {
        sub_08036270();
        calc_battle_stat_ratio(gUnk_03001800.unk87, gUnk_03001800.unkA7);
        gUnk_03001800.unkAA = 4;
    }
}

void sub_08022D4C(void)
{
    lz_decompress_dispatch(gUnk_084D5B08, (void *)0x06014800);
    CpuFastSet(gUnk_0850E738, (void *)0x050002C0, 0x10);
    gUnk_03002C30[0x21].unk0 |= 0x200;
    gUnk_03002C30[0x21].unk8 = 0x40;
    gUnk_03002C30[0x21].unk9 = 0x40;
    gUnk_03002C30[0x21].unkA = 6;
    gUnk_03002C30[0x21].unk30 = gUnk_03002C30[gUnk_03001800.unk88 * 4 + 0x5D].unk2;
    gUnk_03002C30[0x21].unk32 = gUnk_03002C30[gUnk_03001800.unk88 * 4 + 0x5D].unk4 - 4;
    gUnk_03002C30[0x21].unk24 = 6;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x3E], 0x21);
    gUnk_03000440.unk86 = 0x3C;
    gUnk_03001800.unkAA++;
}

void sub_08022E14(void)
{
    u32 i;
    s32 pos, v;

    gUnk_03002C30[0x25].unk0 = 0xC604;
    gUnk_03002C30[0x25].unk1C = 0;
    gUnk_03002C30[0x25].unk2 = gUnk_03002C30[gUnk_03001800.unk88 * 4 + 0x5D].unk2;
    gUnk_03002C30[0x25].unk4 = gUnk_03002C30[gUnk_03001800.unk88 * 4 + 0x5D].unk4 - 4;
    gUnk_03002C30[0x25].unkA = 7;
    gUnk_03002C30[0x25].unk8 = 0x40;
    gUnk_03002C30[0x25].unk9 = 0x40;
    gUnk_03002C30[0x25].unkB = 0xF0;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x3F], 0x25);
    for (i = 0; i < 4; i++)
    {
        gUnk_03002C30[0x21 + i].unk0 = 0xC604;
        calc_polar_to_screen_coords(&pos, i << 6, 0x10,
                                    gUnk_03002C30[gUnk_03001800.unk88 * 4 + 0x5D].unk2,
                                    gUnk_03002C30[gUnk_03001800.unk88 * 4 + 0x5D].unk4 - 4);
        v = pos;
        gUnk_03002C30[0x21 + i].unk2 = v;
        gUnk_03002C30[0x21 + i].unk4 = v >> 16;
        gUnk_03002C30[0x21 + i].unk1C = 0;
        gUnk_03002C30[0x21 + i].unkA = 7;
        gUnk_03002C30[0x21 + i].unkB = 0xF0;
        gUnk_03002C30[0x21 + i].unk6 = 0x4604;
        gUnk_03002C30[0x21 + i].unk8 = 0x40;
        gUnk_03002C30[0x21 + i].unk9 = 0x40;
        gUnk_03002C30[0x21 + i].unk2B = 0x10;
        gUnk_03002C30[0x21 + i].unk2C = i << 6;
        gUnk_03002C30[0x21 + i].unk2D = 0;
    }
    play_sound_effect(0x4B);
    gUnk_03001800.unkAA++;
}

void sub_08022F50(void)
{
    gUnk_03000590[gUnk_03001800.unk88].unk40 = 3;
    battle_calc_damage_split(gUnk_03001800.unk88, 0, gUnk_03001800.unkEC);
    gUnk_03000590[gUnk_03001800.unk88].parts[0].unk11 = gUnk_03001800.unkC8;
    gUnk_03000590[gUnk_03001800.unk88].unkBA = 1;
    load_all_bot_part_sprites();
    iterate_bots_setup_battle_sprites();
    gUnk_03001800.unkAA++;
}

void sub_08022FB4(void)
{
    memcpy_bytes_0803F63C(gUnk_03000590[gUnk_03001800.unk88].medal.unkA, gUnk_03000440.unk9E, 0xE);
    gUnk_03001800.unkA6 = 0x28;
    gUnk_03001800.unkAA++;
}

void sub_08022FF0(void)
{
    gUnk_03001800.unkB5 = 0;
    gUnk_083ADC6C[gUnk_03001800.unkAA]();
}

void sub_08023018(void)
{
    calc_battle_action_speed(gUnk_03001800.unk87, gUnk_03001800.unkA7);
    apply_battle_bot_damage_reduction(gUnk_03001800.unk87);
    if (decrement_battle_timer_and_check_zero())
    {
        gUnk_03001800.unkA6 = 0x1A;
        gUnk_03001800.unkAA++;
    }
    else
    {
        sub_08036270();
        calc_battle_stat_ratio(gUnk_03001800.unk87, gUnk_03001800.unkA7);
        gUnk_03001800.unkAA = 4;
    }
}

void sub_0802306C(void)
{
    lz_decompress_dispatch(gUnk_084D5D78, (void *)0x06014800);
    CpuFastSet(gUnk_0850E778, (void *)0x050002C0, 0x10);
    gUnk_03001800.unkAA++;
}

void sub_080230A4(void)
{
    copy_obj_palette_to_buffer();
    gUnk_03000440.unk84 = 0;
    gUnk_03001800.unkAA++;
}

void sub_080230C8(void)
{
    blend_obj_palettes_to_color_0803F684(0x1084, gUnk_03000440.unk84, 0xFFFF);
    blend_obj_palettes_to_color_0803F998(0x1084, gUnk_03000440.unk84, 0xFF00);
    if (gUnk_03000440.unk84 == 0x10)
        gUnk_03001800.unkAA++;
    else
        gUnk_03000440.unk84++;
}

void sub_08023118(void)
{
    gUnk_03002C30[0x21].unk0 = 0xC604;
    gUnk_03002C30[0x21].unk1C = 0;
    gUnk_03002C30[0x21].unk2 = gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk2;
    gUnk_03002C30[0x21].unk4 = gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 4;
    gUnk_03002C30[0x21].unkA = 6;
    gUnk_03002C30[0x21].unkB = 0xF0;
    gUnk_03002C30[0x21].unk6 = 0x4800;
    gUnk_03002C30[0x21].unk8 = 0x40;
    gUnk_03002C30[0x21].unk9 = 0x40;
    gUnk_03002C30[0x21].unk18 = 0;
    gUnk_03002C30[0x21].unk2D = 0;
    play_sound_effect(0x4C);
    gUnk_03001800.unkAA++;
}

void sub_080231D4(void)
{
    if (gUnk_03002C30[0x21].unk2D == 0x40)
    {
        clear_battle_sprite_slot(0x21, 2);
        gUnk_03001800.unkAA++;
    }
    else
    {
        gUnk_03002C30[0x21].unk2D++;
        gUnk_03002C30[0x21].unk18 = (gUnk_03002C30[0x21].unk18 + 0x10) & 0x3FF;
    }
}

void sub_08023224(void)
{
    blend_obj_palettes_to_color_0803F684(0x1084, gUnk_03000440.unk84, 0xFFFF);
    blend_obj_palettes_to_color_0803F998(0x1084, gUnk_03000440.unk84, 0xFF00);
    if (gUnk_03000440.unk84 == 0)
        gUnk_03001800.unkAA++;
    else
        gUnk_03000440.unk84--;
}

void sub_08023274(void)
{
    u32 i;
    u32 first = sub_08032FC4(gUnk_03001800.unk87);

    for (i = 0; i < 3; i++)
    {
        if (gUnk_03000590[first + i].unk40)
        {
            gUnk_03002C30[0x21 + i].unk0 = 0xC624;
            gUnk_03002C30[0x21 + i].unk1C = 0;
            gUnk_03002C30[0x21 + i].unk2 = gUnk_03002C30[(first + i) * 4 + 0x5D].unk2;
            gUnk_03002C30[0x21 + i].unk4 = gUnk_03002C30[(first + i) * 4 + 0x5D].unk4;
            gUnk_03002C30[0x21 + i].unkA = 7;
            gUnk_03002C30[0x21 + i].unkB = 0xF0;
            gUnk_03002C30[0x21 + i].unk8 = 0x40;
            gUnk_03002C30[0x21 + i].unk9 = 0x40;
            gUnk_03002C30[0x21 + i].unk6 = 0x4801;
        }
    }
    gUnk_03000440.unk86 = 0;
    play_sound_effect(0x2E);
    gUnk_03001800.unkAA++;
}

void sub_08023328(void)
{
    u32 i;

    if (gUnk_03000440.unk86 == 0x14)
    {
        gUnk_03000440.unk86 = 0x3C;
        gUnk_03001800.unkAA++;
    }
    else
    {
        gUnk_03000440.unk86++;
        for (i = 0; i < 3; i++)
        {
            if (gUnk_03002C30[0x21 + i].unk0 & 0x8000)
                gUnk_03002C30[0x21 + i].unk4--;
        }
    }
}

void sub_08023384(void)
{
    u32 i;

    for (i = 0; i < 3; i++)
    {
        if (gUnk_03002C30[0x21 + i].unk0 & 0x8000)
        {
            gUnk_03002C30[0x21 + i].unk8 -= 8;
            gUnk_03002C30[0x21 + i].unk9 += 8;
        }
    }
    if (gUnk_03002C30[0x21].unk8 == 8)
    {
        clear_battle_sprite_slot(0x21, 3);
        gUnk_03001800.unkAA++;
    }
}

void sub_080233E0(void)
{
    sub_08035740(&gUnk_03001800.unk28[gUnk_03001800.unk89].unk0, gUnk_03001800.unkEC, 0xA0);
    gUnk_03001800.unkAA++;
}

void sub_08023414(void)
{
    gUnk_03001800.unkA6 = 0x1C;
    gUnk_03001800.unkAA++;
}

void sub_0802342C(void)
{
    gUnk_03001800.unkB5 = 0;
    gUnk_083ADCC0[gUnk_03001800.unkAA]();
}

void sub_08023454(void)
{
    calc_battle_action_speed(gUnk_03001800.unk87, gUnk_03001800.unkA7);
    apply_battle_bot_damage_reduction(gUnk_03001800.unk87);
    if (decrement_battle_timer_and_check_zero())
    {
        gUnk_03001800.unkA6 = 0x1A;
        gUnk_03001800.unkAA++;
    }
    else
    {
        sub_08036270();
        calc_battle_stat_ratio(gUnk_03001800.unk87, gUnk_03001800.unkA7);
        gUnk_03001800.unkAA = 4;
    }
}

void sub_080234A8(void)
{
    lz_decompress_dispatch(gUnk_084D5EBC, (void *)0x06014800);
    CpuFastSet(gUnk_0850E7B8, (void *)0x050002E0, 8);
    gUnk_03002C30[0x21].unk0 = 0xC404;
    gUnk_03002C30[0x21].unk1C = 0;
    gUnk_03002C30[0x21].unk2 = gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk2;
    gUnk_03002C30[0x21].unk4 = gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 4;
    gUnk_03002C30[0x21].unkA = 7;
    gUnk_03002C30[0x21].unkB = 0xF0;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x40], 0x21);
    play_sound_effect(0x4D);
    gUnk_03001800.unkAA++;
}

void sub_08023564(void)
{
    process_sprite_anim_commands(gUnk_083B5F80[0x40], 0x21);
    if (gUnk_03002C30[0x21].unk22 == 0xFF)
    {
        gUnk_03000440.unk86 = 0x3C;
        gUnk_03001800.unkAA++;
    }
}

void sub_080235AC(void)
{
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x41], 0x21);
    play_sound_effect(0x4D);
    gUnk_03000440.unk84 = 0;
    gUnk_03001800.unkAA++;
}

void sub_080235E8(void)
{
    gUnk_03000440.unk84++;
    sub_08037330(gUnk_03001800.unk87, gUnk_03000440.unk84, 2);
    process_sprite_anim_commands(gUnk_083B5F80[0x41], 0x21);
    if (gUnk_03002C30[0x21].unk22 == 0xFF)
    {
        clear_battle_sprite_slot(0x21, 1);
        gUnk_03000440.unk86 = 0x3C;
        gUnk_03001800.unkAA++;
    }
}

void sub_08023658(void)
{
    gUnk_03000440.unk84++;
    sub_08037330(gUnk_03001800.unk87, gUnk_03000440.unk84, 2);
    if (gUnk_03000440.unk89 == 0 && (*(u8 *)&gRepeatKeys & 1))
    {
        sub_080373D4(gUnk_03001800.unk87);
        gUnk_03001800.unkAA++;
    }
    else if (gUnk_03000440.unk86)
        gUnk_03000440.unk86--;
    else
    {
        sub_080373D4(gUnk_03001800.unk87);
        gUnk_03001800.unkAA++;
    }
}

INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_080236E0);

void sub_08023718(void)
{
    gUnk_03001800.unkA6 = 0x1D;
    gUnk_03001800.unkAA++;
}

INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08023730);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08023758);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_080237C8);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_080238A0);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08023900);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08023988);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_080239C0);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08023A04);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08023A48);

void sub_08023AB0(void)
{
    gUnk_03001800.unkA6 = 0x2C;
    gUnk_03001800.unkAA++;
}

INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08023AC8);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08023AF0);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08023B44);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08023C18);

void sub_08023C50(void)
{
    gUnk_03000590[gUnk_03001800.unk88].unkBF = 1;
    gUnk_03001800.unkAA++;
}


void sub_08023C78(void)
{
    gUnk_03001800.unkA6 = 0x2B;
    gUnk_03001800.unkAA++;
}

INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08023C90);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08023CB8);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08023D44);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08023E18);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08023E50);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08023E94);

void sub_08023F48(void)
{
    if (gUnk_03002C30[0x21].unk8 == 0x40)
        gUnk_03001800.unkAA++;
    else
    {
        gUnk_03002C30[0x21].unk8 += 8;
        gUnk_03002C30[0x21].unk9 += 8;
    }
}

INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08023F80);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08023FB8);

void sub_08024078(void)
{
    gUnk_03001800.unkA6 = 0x2D;
    gUnk_03001800.unkAA++;
}

INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08024090);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_080240B8);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_0802410C);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_080241F0);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08024210);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_080242F8);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08024488);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08024538);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_0802463C);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_080246C0);
INCLUDE_ASM("asm/nonmatching/code_080209B0", battle_process_bot_defeat);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_0802480C);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08024870);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08024890);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_0802494C);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08024998);
