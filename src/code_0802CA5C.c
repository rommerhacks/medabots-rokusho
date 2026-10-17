#include "global.h"

void sub_0802CA5C(void)
{
    u32 done = 0;
    u32 i;

    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03001800.unkD2[i])
        {
            process_sprite_anim_commands(gUnk_083B5F80[0x43], 0x21 + i);
            if (gUnk_03002C30[0x21 + i].unk22 == 0xFF)
                done = 1;
        }
    }
    if (done)
        gUnk_03001800.unkAA++;
}

void sub_0802CAD4(void)
{
    u32 done = 0;
    u32 i;

    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03001800.unkD2[i])
        {
            gUnk_03002C30[0x21 + i].unk8 -= 4;
            gUnk_03002C30[0x21 + i].unk9 -= 4;
            if (gUnk_03002C30[0x21 + i].unk8 == 4)
                done = 1;
        }
    }
    if (done)
    {
        clear_battle_sprite_slot(0x21, 3);
        gUnk_03001800.unkAA++;
    }
}

void sub_0802CB34(void)
{
    u32 i;

    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03001800.unkD2[i])
        {
            gUnk_03000590[gUnk_03001800.unk60 + i].unkC4 = 0x26;
            gUnk_03000590[gUnk_03001800.unk60 + i].unkC5 = 0;
            gUnk_03000590[gUnk_03001800.unk60 + i].unkC6 = sub_08036E54(gUnk_03001800.unkE8);
            gUnk_03000590[gUnk_03001800.unk60 + i].unkC7 = sub_08036E54(gUnk_03001800.unkEC);
        }
    }
    gUnk_03001800.unkAA++;
}

void sub_0802CBD0(void)
{
    gUnk_03001800.unkA6 = 0x59;
    gUnk_03001800.unkAA++;
}

void sub_0802CBE8(void)
{
    gUnk_03001800.unkB5 = 0;
    gUnk_083AE854[gUnk_03001800.unkAA]();
}

void sub_0802CC10(void)
{
    u32 i;

    sub_0803836C();
    gUnk_03001800.unk60 = sub_08032FB8(gUnk_03001800.unk87);
    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03000590[gUnk_03001800.unk60 + i].unk40 && gUnk_03000590[gUnk_03001800.unk60 + i].parts[0].unk11)
            gUnk_03001800.unkD2[i] = 1;
    }
    gUnk_03001800.unkAA++;
}

void sub_0802CC74(void)
{
    u32 i;

    lz_decompress_dispatch(gUnk_084D6464, (void *)0x06014800);
    CpuFastSet(gUnk_0850E838, (void *)0x050002E0, 8);
    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        gUnk_03002C30[0x21 + i].unk0 = 0xC624;
        gUnk_03002C30[0x21 + i].unk1C = 0;
        gUnk_03002C30[0x21 + i].unk2 = 0x78;
        gUnk_03002C30[0x21 + i].unk4 = 0xF0;
        gUnk_03002C30[0x21 + i].unk8 = 0x40;
        gUnk_03002C30[0x21 + i].unk9 = 0x40;
        gUnk_03002C30[0x21 + i].unkA = 7;
        gUnk_03002C30[0x21 + i].unkB = 0xF0;
        gUnk_03002C30[0x21 + i].unk6 = 0x4D00;
        gUnk_03002C30[0x21 + i].unk24 = 4;
        gUnk_03002C30[0x21 + i].unk25 = 0;
        gUnk_03002C30[0x21 + i].unk30 = 0;
        if (gUnk_03001800.unkF8 & 1)
            gUnk_03002C30[0x21 + i].unk0 |= 0x1000;
    }
    play_sound_effect(0x61);
    gUnk_03001800.unkAA++;
}

void sub_0802CD48(void)
{
    u32 done = 0;
    u32 count = 0;
    u32 i;

    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03001800.unkD2[i])
        {
            count++;
            if (sprite_move_toward_target(0x21 + i, gUnk_03002C30[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk4 - 4,
                                          gUnk_03002C30[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk4 + 0x10))
            {
                gUnk_03002C30[0x21 + i].unk30 = gUnk_03002C30[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk2;
                gUnk_03002C30[0x21 + i].unk32 = gUnk_03002C30[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk4 - 4;
                gUnk_03002C30[0x21 + i].unk24 = 6;
                done++;
            }
        }
    }
    if (done == count)
    {
        gUnk_03000440.unk86 = 0x3C;
        gUnk_03001800.unkAA++;
    }
}

void sub_0802CE08(void)
{
    u32 done = 0;
    u32 count = 0;
    u32 i;

    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03001800.unkD2[i])
        {
            count++;
            if (move_sprite_toward_target(0x21 + i))
                done++;
        }
    }
    if (done == count)
        gUnk_03001800.unkAA++;
}

void sub_0802CE4C(void)
{
    u32 i;
    u32 j;

    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        gUnk_03002C30[0x21 + i].unk23 = 0;
        memcpy_bytes_0803F63C(&gUnk_03002C30[(gUnk_03001800.unk60 + i) * 4 + 0x5A], &gUnk_03002C30[(j = i * 4) + 0x24], 0x40);
        memcpy_bytes_0803F63C(&gUnk_03002C30[(gUnk_03001800.unk60 + i) * 4 + 0x5B], &gUnk_03002C30[j + 0x25], 0x40);
        memcpy_bytes_0803F63C(&gUnk_03002C30[(gUnk_03001800.unk60 + i) * 4 + 0x5C], &gUnk_03002C30[j + 0x26], 0x40);
        memcpy_bytes_0803F63C(&gUnk_03002C30[(gUnk_03001800.unk60 + i) * 4 + 0x5D], &gUnk_03002C30[j + 0x27], 0x40);
        clear_sprite_table_mask(j + 0x24, 4);
        gUnk_03002C30[(gUnk_03001800.unk60 + i) * 4 + 0x5A].unk23 = 0;
        gUnk_03002C30[(gUnk_03001800.unk60 + i) * 4 + 0x5B].unk23 = 0;
        gUnk_03002C30[(gUnk_03001800.unk60 + i) * 4 + 0x5C].unk23 = 0;
        gUnk_03002C30[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk23 = 0;
        sub_08035694(gUnk_03001800.unk60 + 0x72 + i);
    }
    play_sound_effect(0x34);
    gUnk_03001800.unkAA++;
}

void sub_0802CFAC(void)
{
    u32 done = 0;
    u32 count = 0;
    u32 i, j;

    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        count++;
        if (gUnk_03002C30[0x21 + i].unk0 & 0x8000)
        {
            if (advance_sprite_anim_frame(0x21 + i, 0))
                clear_battle_sprite_slot(0x21 + i, 1);
            else if (!(gUnk_03001800.unkF8 & 1))
            {
                gUnk_03002C30[0x21 + i].unk2--;
                gUnk_03002C30[0x21 + i].unk18 = (gUnk_03002C30[0x21 + i].unk18 - 0x10) & 0x3FF;
            }
            else
            {
                gUnk_03002C30[0x21 + i].unk2++;
                gUnk_03002C30[0x21 + i].unk18 = (gUnk_03002C30[0x21 + i].unk18 + 0x10) & 0x3FF;
            }
        }
        sub_080353CC((gUnk_03001800.unk60 + i) * 4 + 0x5A);
        sub_080353CC((gUnk_03001800.unk60 + i) * 4 + 0x5B);
        sub_080353CC((gUnk_03001800.unk60 + i) * 4 + 0x5C);
        done += sub_080353CC((gUnk_03001800.unk60 + i) * 4 + 0x5D);
        if (gUnk_03002C30[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk23 == 0x10)
        {
            gUnk_03002C30[(gUnk_03001800.unk60 + i) * 4 + 0x5A].unk4 += 8;
            gUnk_03002C30[(gUnk_03001800.unk60 + i) * 4 + 0x5B].unk4 -= 8;
            gUnk_03002C30[(gUnk_03001800.unk60 + i) * 4 + 0x5C].unk4 -= 8;
            gUnk_03002C30[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk4 -= 8;
            gUnk_03002C30[(gUnk_03001800.unk60 + i) * 4 + 0x5A].unk0 |= 0x2000;
            gUnk_03002C30[(gUnk_03001800.unk60 + i) * 4 + 0x5B].unk0 |= 0x2000;
            gUnk_03002C30[(gUnk_03001800.unk60 + i) * 4 + 0x5C].unk0 |= 0x2000;
            gUnk_03002C30[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk0 |= 0x2000;
        }
        check_sprite_overlap_and_adjust((gUnk_03001800.unk60 + i) * 4 + 0x5D, gUnk_03001800.unk60 + (j = i + 0x72));
    }
    if (done == count)
    {
        for (i = 0; i <= 2; i++)
        {
            if (gUnk_03001800.unkD2[i])
                sub_080356B4((j = i + 0x72) + gUnk_03001800.unk60);
        }
        play_sound_effect(0x41);
        gUnk_03001800.unkAA++;
    }
}

void sub_0802D198(void)
{
    u32 i, j;

    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        for (j = 0; j < 4; j++)
        {
            gUnk_03002C30[0x30 + j + i * 4].unk0 = 0xC404;
            gUnk_03002C30[0x30 + j + i * 4].unk1C = 0;
            gUnk_03002C30[0x30 + j + i * 4].unk2 = gUnk_03002C30[(gUnk_03001800.unk60 + i) * 4 + 0x5A].unk2;
            gUnk_03002C30[0x30 + j + i * 4].unk4 = gUnk_03002C30[(gUnk_03001800.unk60 + i) * 4 + 0x5A].unk4 + 4;
            gUnk_03002C30[0x30 + j + i * 4].unkA = 7;
            gUnk_03002C30[0x30 + j + i * 4].unkB = 0xF0;
            gUnk_03002C30[0x30 + j + i * 4].unk24 = 6;
            gUnk_03002C30[0x30 + j + i * 4].unk25 = gUnk_083ADEE0[j];
            gUnk_03002C30[0x30 + j + i * 4].unk6 = 0x4D01;
        }
    }
    gUnk_03000440.unk84 = 0;
    gUnk_03001800.unkAA++;
}

void sub_0802D270(void)
{
    u32 i, j;

    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        for (j = 0; j < 4; j++)
            update_sprite_animation_position(0x30 + j + i * 4);
    }
    if (gUnk_03000440.unk84 == 0x10)
    {
        for (i = 0; i <= 2; i++)
        {
            if (gUnk_03001800.unkD2[i] == 0)
                continue;
            memcpy_bytes_0803F63C(&gUnk_03002C30[0x24 + i * 4], &gUnk_03002C30[(gUnk_03001800.unk60 + i) * 4 + 0x5A], 0x40);
            memcpy_bytes_0803F63C(&gUnk_03002C30[0x25 + i * 4], &gUnk_03002C30[(gUnk_03001800.unk60 + i) * 4 + 0x5B], 0x40);
            memcpy_bytes_0803F63C(&gUnk_03002C30[0x26 + i * 4], &gUnk_03002C30[(gUnk_03001800.unk60 + i) * 4 + 0x5C], 0x40);
            memcpy_bytes_0803F63C(&gUnk_03002C30[0x27 + i * 4], &gUnk_03002C30[(gUnk_03001800.unk60 + i) * 4 + 0x5D], 0x40);
            gUnk_03002C30[(gUnk_03001800.unk60 + i) * 4 + 0x5A].unk0 |= 0x8000;
            gUnk_03002C30[(gUnk_03001800.unk60 + i) * 4 + 0x5B].unk0 |= 0x8000;
            gUnk_03002C30[(gUnk_03001800.unk60 + i) * 4 + 0x5C].unk0 |= 0x8000;
            gUnk_03002C30[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk0 |= 0x8000;
        }
        clear_battle_sprite_slot(0x21, 0x1B);
        gUnk_03001800.unkAA++;
    }
    else
        gUnk_03000440.unk84++;
}

void apply_battle_damage_and_render(void)
{
    u32 i;

    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        if (gUnk_03000590[gUnk_03001800.unk60 + i].unkBD & 4)
            battle_set_damage_vs_armor(gUnk_03001800.unk60 + i, 0, 1);
        else
            battle_set_damage_vs_armor(gUnk_03001800.unk60 + i, 0, gUnk_03001800.unkEC);
        gUnk_03001800.unkD6[i] = gUnk_03001800.unkC8;
        switch (i)
        {
        case 0:
            set_display_digit_type(gUnk_03000440.unk9E, gUnk_03001800.unkC8, 1);
            render_battle_text_sprites(gUnk_03000440.unk9E, gUnk_03001800.unk60 + i, 0x21);
            break;
        case 1:
            set_display_digit_type(gUnk_03000440.unk9E + 0x14, gUnk_03001800.unkC8, 1);
            render_battle_text_sprites(gUnk_03000440.unk9E + 0x14, gUnk_03001800.unk60 + 1, 0x21);
            break;
        case 2:
            set_display_digit_type(gUnk_03000440.unk9E + 0x28, gUnk_03001800.unkC8, 1);
            render_battle_text_sprites(gUnk_03000440.unk9E + 0x28, gUnk_03001800.unk60 + 2, 0x21);
            break;
        }
    }
    play_sound_effect(0x5B);
    gUnk_03000440.unk84 = 0;
    gUnk_03001800.unkAA++;
}

void sub_0802D4D8(void)
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
        for (i = 0; i <= 2; i++)
        {
            if (gUnk_03001800.unkD2[i])
                clear_battle_sprite_slot((gUnk_03001800.unk60 + i) * 4 + 0x21, 4);
        }
        gUnk_03001800.unkAA++;
    }
}

void apply_battle_damage_to_team(void)
{
    u32 defeated = 0;
    u32 i;

    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        reduce_bot_part_stat(gUnk_03001800.unk60 + i, 0, gUnk_03001800.unkD6[i]);
        if (gUnk_03000590[gUnk_03001800.unk60 + i].parts[0].unk11 == 0)
        {
            add_bot_to_defeated_list(gUnk_03001800.unk60 + i);
            gUnk_03001800.unkD2[i] = 0x80;
            defeated = 1;
        }
        else if (!(gUnk_03000590[gUnk_03001800.unk60 + i].unkBD & 4))
            gUnk_03000590[gUnk_03001800.unk60 + i].unkBD |= 1;
    }
    if (defeated)
        gUnk_03001800.unkAA = 0x10;
    else
        gUnk_03001800.unkAA++;
}

void sub_0802D670(void)
{
    gUnk_03001800.unkA6 = 0x42;
    gUnk_03001800.unkAA++;
}

void sub_0802D688(void)
{
    gUnk_03001800.unkB5 = 0;
    gUnk_083AE8B0[gUnk_03001800.unkAA]();
}

INCLUDE_ASM("asm/nonmatching/code_0802CA5C", sub_0802D6B0);
INCLUDE_ASM("asm/nonmatching/code_0802CA5C", sub_0802D758);
INCLUDE_ASM("asm/nonmatching/code_0802CA5C", sub_0802D7EC);
INCLUDE_ASM("asm/nonmatching/code_0802CA5C", sub_0802D8D0);
INCLUDE_ASM("asm/nonmatching/code_0802CA5C", sub_0802DA0C);
INCLUDE_ASM("asm/nonmatching/code_0802CA5C", sub_0802DA60);
INCLUDE_ASM("asm/nonmatching/code_0802CA5C", sub_0802DAD0);
INCLUDE_ASM("asm/nonmatching/code_0802CA5C", sub_0802DB3C);
INCLUDE_ASM("asm/nonmatching/code_0802CA5C", sub_0802DBD8);
INCLUDE_ASM("asm/nonmatching/code_0802CA5C", sub_0802DCB4);
INCLUDE_ASM("asm/nonmatching/code_0802CA5C", sub_0802DCDC);
INCLUDE_ASM("asm/nonmatching/code_0802CA5C", sub_0802DD98);
INCLUDE_ASM("asm/nonmatching/code_0802CA5C", sub_0802DE1C);
INCLUDE_ASM("asm/nonmatching/code_0802CA5C", sub_0802DF18);
INCLUDE_ASM("asm/nonmatching/code_0802CA5C", sub_0802DF48);
INCLUDE_ASM("asm/nonmatching/code_0802CA5C", sub_0802DF98);
INCLUDE_ASM("asm/nonmatching/code_0802CA5C", sub_0802DFE8);
INCLUDE_ASM("asm/nonmatching/code_0802CA5C", sub_0802E010);
INCLUDE_ASM("asm/nonmatching/code_0802CA5C", sub_0802E098);
INCLUDE_ASM("asm/nonmatching/code_0802CA5C", sub_0802E140);
INCLUDE_ASM("asm/nonmatching/code_0802CA5C", sub_0802E1A4);
INCLUDE_ASM("asm/nonmatching/code_0802CA5C", sub_0802E1C8);
INCLUDE_ASM("asm/nonmatching/code_0802CA5C", sub_0802E294);
INCLUDE_ASM("asm/nonmatching/code_0802CA5C", sub_0802E358);
INCLUDE_ASM("asm/nonmatching/code_0802CA5C", battle_dispatch_phase_handler_0802E424);
INCLUDE_ASM("asm/nonmatching/code_0802CA5C", sub_0802E44C);
INCLUDE_ASM("asm/nonmatching/code_0802CA5C", sub_0802E4C8);
INCLUDE_ASM("asm/nonmatching/code_0802CA5C", sub_0802E5D4);
INCLUDE_ASM("asm/nonmatching/code_0802CA5C", sub_0802E638);
INCLUDE_ASM("asm/nonmatching/code_0802CA5C", sub_0802E70C);
INCLUDE_ASM("asm/nonmatching/code_0802CA5C", sub_0802E7A0);
INCLUDE_ASM("asm/nonmatching/code_0802CA5C", sub_0802E820);
INCLUDE_ASM("asm/nonmatching/code_0802CA5C", sub_0802E8D4);
INCLUDE_ASM("asm/nonmatching/code_0802CA5C", sub_0802E948);
INCLUDE_ASM("asm/nonmatching/code_0802CA5C", sub_0802EAA4);
INCLUDE_ASM("asm/nonmatching/code_0802CA5C", sub_0802EAD8);
INCLUDE_ASM("asm/nonmatching/code_0802CA5C", sub_0802EBC0);
INCLUDE_ASM("asm/nonmatching/code_0802CA5C", sub_0802EBE8);
INCLUDE_ASM("asm/nonmatching/code_0802CA5C", sub_0802EC4C);
INCLUDE_ASM("asm/nonmatching/code_0802CA5C", sub_0802ED34);
INCLUDE_ASM("asm/nonmatching/code_0802CA5C", sub_0802ED90);
INCLUDE_ASM("asm/nonmatching/code_0802CA5C", decrement_timer_and_decompress_sprite);
INCLUDE_ASM("asm/nonmatching/code_0802CA5C", sub_0802EF0C);
INCLUDE_ASM("asm/nonmatching/code_0802CA5C", sub_0802EF5C);
INCLUDE_ASM("asm/nonmatching/code_0802CA5C", sub_0802EFD0);
INCLUDE_ASM("asm/nonmatching/code_0802CA5C", sub_0802F030);
INCLUDE_ASM("asm/nonmatching/code_0802CA5C", sub_0802F058);
INCLUDE_ASM("asm/nonmatching/code_0802CA5C", sub_0802F13C);
INCLUDE_ASM("asm/nonmatching/code_0802CA5C", sub_0802F214);
INCLUDE_ASM("asm/nonmatching/code_0802CA5C", sub_0802F2F4);
INCLUDE_ASM("asm/nonmatching/code_0802CA5C", sub_0802F3FC);
INCLUDE_ASM("asm/nonmatching/code_0802CA5C", sub_0802F468);
INCLUDE_ASM("asm/nonmatching/code_0802CA5C", sub_0802F48C);
INCLUDE_ASM("asm/nonmatching/code_0802CA5C", sub_0802F4D0);
INCLUDE_ASM("asm/nonmatching/code_0802CA5C", sub_0802F594);
INCLUDE_ASM("asm/nonmatching/code_0802CA5C", sub_0802F5D8);
INCLUDE_ASM("asm/nonmatching/code_0802CA5C", sub_0802F628);
INCLUDE_ASM("asm/nonmatching/code_0802CA5C", sub_0802F650);
INCLUDE_ASM("asm/nonmatching/code_0802CA5C", sub_0802F6CC);
INCLUDE_ASM("asm/nonmatching/code_0802CA5C", sub_0802F7B8);
INCLUDE_ASM("asm/nonmatching/code_0802CA5C", sub_0802F864);
INCLUDE_ASM("asm/nonmatching/code_0802CA5C", sub_0802F880);
INCLUDE_ASM("asm/nonmatching/code_0802CA5C", sub_0802F89C);
INCLUDE_ASM("asm/nonmatching/code_0802CA5C", sub_0802F8E4);
INCLUDE_ASM("asm/nonmatching/code_0802CA5C", sub_0802F990);
INCLUDE_ASM("asm/nonmatching/code_0802CA5C", sub_0802F9B8);
INCLUDE_ASM("asm/nonmatching/code_0802CA5C", sub_0802FC3C);
INCLUDE_ASM("asm/nonmatching/code_0802CA5C", sub_0802FD08);
INCLUDE_ASM("asm/nonmatching/code_0802CA5C", sub_0802FDC8);
INCLUDE_ASM("asm/nonmatching/code_0802CA5C", sub_0802FE50);
INCLUDE_ASM("asm/nonmatching/code_0802CA5C", sub_0802FE78);
INCLUDE_ASM("asm/nonmatching/code_0802CA5C", sub_0803029C);
INCLUDE_ASM("asm/nonmatching/code_0802CA5C", sub_08030354);
INCLUDE_ASM("asm/nonmatching/code_0802CA5C", sub_080303A4);
INCLUDE_ASM("asm/nonmatching/code_0802CA5C", sub_08030494);
INCLUDE_ASM("asm/nonmatching/code_0802CA5C", sub_080305E0);
INCLUDE_ASM("asm/nonmatching/code_0802CA5C", sub_08030608);
INCLUDE_ASM("asm/nonmatching/code_0802CA5C", sub_08030624);
INCLUDE_ASM("asm/nonmatching/code_0802CA5C", sub_080306B8);
INCLUDE_ASM("asm/nonmatching/code_0802CA5C", sub_08030780);
INCLUDE_ASM("asm/nonmatching/code_0802CA5C", sub_0803081C);
INCLUDE_ASM("asm/nonmatching/code_0802CA5C", sub_08030860);
INCLUDE_ASM("asm/nonmatching/code_0802CA5C", sub_08030890);
INCLUDE_ASM("asm/nonmatching/code_0802CA5C", sub_08030910);
INCLUDE_ASM("asm/nonmatching/code_0802CA5C", sub_08030990);
INCLUDE_ASM("asm/nonmatching/code_0802CA5C", resolve_battle_action_phase);
