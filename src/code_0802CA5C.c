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

void sub_0802D6B0(void)
{
    lz_decompress_dispatch(gUnk_084E0360, (void *)0x06014800);
    CpuFastSet(gUnk_0850EE98, (void *)0x050002E0, 8);
    gUnk_03002C30[0x21].unk0 = 0xC604;
    gUnk_03002C30[0x21].unk1C = 0;
    gUnk_03002C30[0x21].unk2 = 0x78;
    gUnk_03002C30[0x21].unk4 = 0x40;
    gUnk_03002C30[0x21].unk8 = 4;
    gUnk_03002C30[0x21].unk9 = 4;
    gUnk_03002C30[0x21].unkA = 7;
    gUnk_03002C30[0x21].unkB = 0xF0;
    gUnk_03002C30[0x21].unk6 = 0x7E00;
    play_sound_effect(0x6E);
    gUnk_03001800.unkAA++;
}

void sub_0802D758(void)
{
    u32 found = 0;
    u32 i;

    sub_0803836C();
    gUnk_03001800.unk60 = sub_08032FB8(gUnk_03001800.unk87);
    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03000590[gUnk_03001800.unk60 + i].unk40 && gUnk_03000590[gUnk_03001800.unk60 + i].parts[0].unk11
            && sub_080331F8(gUnk_03001800.unk60 + i))
        {
            gUnk_03001800.unkD2[i] = (s8)battle_find_next_active_bot(gUnk_03001800.unk60 + i) - 0x80;
            found = 1;
        }
    }
    if (!found)
        gUnk_03001800.unkAA++;
    else
        gUnk_03001800.unkAA += 3;
}

void sub_0802D7EC(void)
{
    u32 i;

    clear_battle_sprite_slot(0x21, 1);
    lz_decompress_dispatch(gUnk_084D651C, (void *)0x06014800);
    CpuFastSet(gUnk_0850E858, (void *)0x050002E0, 8);
    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        gUnk_03002C30[0x21 + i].unk0 = 0xC624;
        gUnk_03002C30[0x21 + i].unk1C = 0;
        gUnk_03002C30[0x21 + i].unk2 = 0x78;
        gUnk_03002C30[0x21 + i].unk4 = 0x40;
        gUnk_03002C30[0x21 + i].unkA = 7;
        gUnk_03002C30[0x21 + i].unkB = 0xF0;
        gUnk_03002C30[0x21 + i].unk8 = 0x40;
        gUnk_03002C30[0x21 + i].unk9 = 0x40;
        gUnk_03002C30[0x21 + i].unk18 = 0;
        gUnk_03002C30[0x21 + i].unk30 = gUnk_03002C30[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk2;
        gUnk_03002C30[0x21 + i].unk32 = gUnk_03002C30[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk4 - 4;
        gUnk_03002C30[0x21 + i].unk24 = 6;
        gUnk_03002C30[0x21 + i].unk6 = 0x4E00;
    }
    gUnk_03001800.unkAA++;
}

INCLUDE_ASM("asm/nonmatching/code_0802CA5C", sub_0802D8D0);

void sub_0802DA0C(void)
{
    u32 done = 0;
    u32 count = 0;
    u32 i;

    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03001800.unkD2[i])
        {
            count++;
            if (advance_sprite_anim_frame(0x24 + i, 0))
                done++;
        }
    }
    if (done == count)
    {
        gUnk_03000440.unk86 = 0x3C;
        gUnk_03001800.unkAA++;
    }
}

void sub_0802DA60(void)
{
    u32 i;

    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03001800.unkD2[i])
        {
            set_sprite_hidden_flags(0x21 + i, 1);
            gUnk_03002C30[0x21 + i].unk0 |= 0x220;
            gUnk_03002C30[0x21 + i].unk8 = 0x80;
            gUnk_03002C30[0x21 + i].unk9 = 0x80;
            gUnk_03002C30[0x21 + i].unk18 = 0;
        }
    }
    gUnk_03001800.unkAA++;
}

void sub_0802DAD0(void)
{
    u32 done = 0;
    u32 count = 0;
    u32 i;

    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03001800.unkD2[i])
        {
            count++;
            if (gUnk_03002C30[0x21 + i].unk8 == 0x40)
                done++;
            else
            {
                gUnk_03002C30[0x21 + i].unk8 -= 8;
                gUnk_03002C30[0x21 + i].unk9 -= 8;
            }
        }
    }
    if (done == count)
    {
        play_sound_effect(0x3C);
        gUnk_03000440.unk86 = 0;
        gUnk_03001800.unkAA++;
    }
}

void sub_0802DB3C(void)
{
    u32 i;

    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03001800.unkD2[i])
        {
            if (gUnk_03000440.unk86 & 4)
                gUnk_03002C30[0x21 + i].unk2 = gUnk_03002C30[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk2 - 2;
            else
                gUnk_03002C30[0x21 + i].unk2 = gUnk_03002C30[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk2 + 2;
        }
    }
    if (gUnk_03000440.unk86 == 0x3C)
    {
        clear_battle_sprite_slot(0x21, 6);
        gUnk_03001800.unkAA++;
    }
    else
        gUnk_03000440.unk86++;
}

void sub_0802DBD8(void)
{
    u32 i;

    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        gUnk_03000590[gUnk_03001800.unk60 + i].unkC9 = 0x2B;
        gUnk_03000590[gUnk_03001800.unk60 + i].unkCB = sub_08036E54(gUnk_03001800.unkE8);
        gUnk_03000590[gUnk_03001800.unk60 + i].unkCC = sub_08036E54(gUnk_03001800.unkEC);
        switch (gUnk_03001800.unkD2[i] & 0x7F)
        {
        case 1:
            gUnk_03000590[gUnk_03001800.unk60 + i].unkCA = 2;
            break;
        case 2:
            gUnk_03000590[gUnk_03001800.unk60 + i].unkCA = 3;
            break;
        default:
            gUnk_03000590[gUnk_03001800.unk60 + i].unkCA = 1;
            break;
        }
    }
    gUnk_03001800.unkAA++;
}

void sub_0802DC9C(void)
{
    gUnk_03001800.unkA6 = 0x5E;
    gUnk_03001800.unkAA++;
}

void sub_0802DCB4(void)
{
    gUnk_03001800.unkB5 = 0;
    gUnk_083AE908[gUnk_03001800.unkAA]();
}

void sub_0802DCDC(void)
{
    lz_decompress_dispatch(gUnk_084E046C, (void *)0x06014800);
    CpuFastSet(gUnk_0850EEB8, (void *)0x050002E0, 8);
    gUnk_03002C30[0x21].unk0 = 0xC404;
    gUnk_03002C30[0x21].unk1C = 0;
    gUnk_03002C30[0x21].unk4 = 0xE0;
    gUnk_03002C30[0x21].unkA = 7;
    gUnk_03002C30[0x21].unkB = 0xF0;
    if (!(gUnk_03001800.unkF8 & 1))
        gUnk_03002C30[0x21].unk2 = 0xB8;
    else
        gUnk_03002C30[0x21].unk2 = 0x40;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x69], 0x21);
    gUnk_03001800.unkAA++;
}

void sub_0802DD98(void)
{
    process_sprite_anim_commands(gUnk_083B5F80[0x69], 0x21);
    if (gUnk_03002C30[0x21].unk4 == 0x40)
    {
        gUnk_03000440.unk86 = 0;
        gUnk_03002C30[0x21].unk25 = 0x14;
        gUnk_03002C30[0x21].unk24 = 0;
        gUnk_03002C30[0x21].unk28 = 0;
        gUnk_03002C30[0x21].unk23 = 0;
        gUnk_03001800.unkAA++;
    }
    else
        gUnk_03002C30[0x21].unk4 = (gUnk_03002C30[0x21].unk4 + 1) & 0xFF;
}

INCLUDE_ASM("asm/nonmatching/code_0802CA5C", sub_0802DE1C);

void sub_0802DF18(void)
{
    gUnk_03002C30[0x21].unk6 = 0x7F02;
    play_sound_effect(0x38);
    gUnk_03001800.unkAA++;
}

void sub_0802DF48(void)
{
    blend_obj_palettes_to_color_0803F684(0x7FFF, gUnk_03000440.unk84, 0xFFFF);
    blend_obj_palettes_to_color_0803F998(0x7FFF, gUnk_03000440.unk84, 0xFF00);
    if (gUnk_03000440.unk84 == 0x20)
        gUnk_03001800.unkAA++;
    else
        gUnk_03000440.unk84 += 2;
}

void sub_0802DF98(void)
{
    blend_obj_palettes_to_color_0803F684(0x1084, gUnk_03000440.unk84, 0xFFFF);
    blend_obj_palettes_to_color_0803F998(0x1084, gUnk_03000440.unk84, 0xFF00);
    if (gUnk_03000440.unk84 == 0x10)
        gUnk_03001800.unkAA++;
    else
        gUnk_03000440.unk84 -= 2;
}

void sub_0802DFE8(void)
{
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x69], 0x21);
    gUnk_03001800.unkAA = 4;
}

void sub_0802E010(void)
{
    u32 found = 0;
    u32 i;

    sub_0803836C();
    gUnk_03001800.unk60 = sub_08032FB8(gUnk_03001800.unk87);
    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03000590[gUnk_03001800.unk60 + i].unk40 && gUnk_03000590[gUnk_03001800.unk60 + i].parts[0].unk11
            && (gUnk_03000590[gUnk_03001800.unk60 + i].unkBD & 4))
        {
            gUnk_03001800.unkD2[i] = 1;
            found = 1;
        }
    }
    if (!found)
        gUnk_03001800.unkAA++;
    else
        gUnk_03001800.unkAA += 2;
}

void sub_0802E098(void)
{
    u32 i;

    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        gUnk_03002C30[0x21 + i].unk0 = 0xC624;
        gUnk_03002C30[0x21 + i].unk1C = 0;
        gUnk_03002C30[0x21 + i].unk2 = gUnk_03002C30[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk2;
        gUnk_03002C30[0x21 + i].unk4 = gUnk_03002C30[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk4 - 4;
        gUnk_03002C30[0x21 + i].unk8 = 0x80;
        gUnk_03002C30[0x21 + i].unk9 = 0x80;
        gUnk_03002C30[0x21 + i].unkA = 7;
        gUnk_03002C30[0x21 + i].unkB = 0xF0;
        gUnk_03002C30[0x21 + i].unk6 = 0x7F03;
    }
    play_sound_effect(0x54);
    gUnk_03001800.unkAA++;
}

void sub_0802E140(void)
{
    u32 done = 0;
    u32 i;

    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03001800.unkD2[i])
        {
            if (gUnk_03002C30[0x21 + i].unk8 == 0x40)
                done = 1;
            else
            {
                gUnk_03002C30[0x21 + i].unk8 -= 8;
                gUnk_03002C30[0x21 + i].unk9 -= 8;
            }
        }
    }
    if (done)
    {
        gUnk_03000440.unk86 = 0x3C;
        gUnk_03001800.unkAA++;
    }
}

void sub_0802E1A4(void)
{
    clear_battle_sprite_slot(0x21, 3);
    gUnk_03001800.unkA6 = 0x43;
    gUnk_03001800.unkAA++;
}

void sub_0802E1C8(void)
{
    u32 i;

    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        gUnk_03001800.unkD2[i] = get_random_battle_weight_entry(gUnk_03001800.unk60 + i);
        battle_set_damage_vs_armor(gUnk_03001800.unk60 + i, gUnk_03001800.unkD2[i], 0xC8);
        gUnk_03001800.unkD2[i] |= gUnk_03001800.unkD1 << 7;
        gUnk_03001800.unkD6[i] = gUnk_03001800.unkC8;
        gUnk_03000590[gUnk_03001800.unk60 + i].parts[gUnk_03001800.unkD2[i] & 0x7F].unk11 -= gUnk_03001800.unkD6[i];
        sub_08035194(gUnk_03001800.unk60 + i);
        if ((gUnk_03001800.unkD2[i] & 0x7F) == 0 && gUnk_03000590[gUnk_03001800.unk60 + i].parts[0].unk11 == 0)
            add_bot_to_defeated_list(gUnk_03001800.unk60 + i);
    }
    gUnk_03001800.unkAA++;
}

void sub_0802E294(void)
{
    u32 i;

    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03001800.unkD2[i])
        {
            switch (i)
            {
            case 0:
                set_display_digit_type(gUnk_03000440.unk9E, gUnk_03001800.unkD6[i], 1);
                render_battle_text_sprites(gUnk_03000440.unk9E, gUnk_03001800.unk60 + i, 0x21);
                break;
            case 1:
                set_display_digit_type(gUnk_03000440.unk9E + 0x14, gUnk_03001800.unkD6[1], 1);
                render_battle_text_sprites(gUnk_03000440.unk9E + 0x14, gUnk_03001800.unk60 + 1, 0x21);
                break;
            case 2:
                set_display_digit_type(gUnk_03000440.unk9E + 0x28, gUnk_03001800.unkD6[2], 1);
                render_battle_text_sprites(gUnk_03000440.unk9E + 0x28, gUnk_03001800.unk60 + 2, 0x21);
                break;
            }
        }
    }
    play_sound_effect(0x5B);
    gUnk_03000440.unk84 = 0;
    gUnk_03001800.unkAA++;
}

void sub_0802E358(void)
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

void battle_dispatch_phase_handler_0802E424(void)
{
    gUnk_03001800.unkB5 = 0;
    gUnk_083AE99C[gUnk_03001800.unkAA]();
}

void sub_0802E44C(void)
{
    u32 i;

    sub_0803836C();
    gUnk_03001800.unk60 = sub_08032FB8(gUnk_03001800.unk87);
    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03000590[gUnk_03001800.unk60 + i].unk40 && gUnk_03000590[gUnk_03001800.unk60 + i].parts[0].unk11)
        {
            gUnk_03001800.unkD2[i] = 1;
            gUnk_03001800.unkD6[i] = gUnk_03000590[gUnk_03001800.unk60 + i].unkC1;
        }
    }
    gUnk_03001800.unkAA++;
}

void sub_0802E4C8(void)
{
    u32 i;

    lz_decompress_dispatch(gUnk_084D6F88, (void *)0x06014800);
    CpuFastSet(gUnk_0850E938, (void *)0x050002E0, 0x10);
    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        gUnk_03002C30[0xA + i].unk0 = 0xC624;
        gUnk_03002C30[0xA + i].unk1C = 0;
        gUnk_03002C30[0xA + i].unk2 = 0x78;
        gUnk_03002C30[0xA + i].unk4 = 0x40;
        gUnk_03002C30[0xA + i].unk8 = 4;
        gUnk_03002C30[0xA + i].unk9 = 4;
        gUnk_03002C30[0xA + i].unk18 = 0;
        gUnk_03002C30[0xA + i].unk30 = gUnk_03002C30[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk2;
        gUnk_03002C30[0xA + i].unk32 = gUnk_03002C30[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk4 - 4;
        gUnk_03002C30[0xA + i].unk24 = 6;
        gUnk_03002C30[0xA + i].unk23 = 0;
        gUnk_03002C30[0xA + i].unkA = 7;
        gUnk_03002C30[0xA + i].unkB = 0xE0;
        gUnk_03000440.unk84 = 0x48;
        init_battle_sprite_entry_08040B90(gUnk_083B5F80[gUnk_03000440.unk84], i + 0xA);
    }
    play_sound_effect(0x6A);
    gUnk_03001800.unkAA++;
}

void sub_0802E5D4(void)
{
    u32 done = 0;
    u32 i;

    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03001800.unkD2[i])
        {
            if (gUnk_03002C30[0xA + i].unk8 == 0x40)
                done = 1;
            else
            {
                gUnk_03002C30[0xA + i].unk8 += 4;
                gUnk_03002C30[0xA + i].unk9 += 4;
            }
        }
    }
    if (done)
    {
        gUnk_03000440.unk86 = 0x3C;
        gUnk_03001800.unkAA++;
    }
}

void sub_0802E638(void)
{
    u32 done = 0;
    u32 count = 0;
    u32 i;

    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03001800.unkD2[i])
        {
            count++;
            if (!(gUnk_03001800.unkF8 & 1))
                gUnk_03002C30[0xA + i].unk18 = (gUnk_03002C30[0xA + i].unk18 - 0x40) & 0x3FF;
            else
                gUnk_03002C30[0xA + i].unk18 = (gUnk_03002C30[0xA + i].unk18 + 0x40) & 0x3FF;
            if (move_sprite_toward_target(0xA + i))
            {
                gUnk_03002C30[0xA + i].unk18 = 0;
                done++;
            }
        }
    }
    if (done == count)
    {
        for (i = 0; i <= 2; i++)
        {
            if (gUnk_03001800.unkD2[i] && gUnk_03001800.unkD6[i])
                play_sound_effect(0x51);
        }
        gUnk_03001800.unkAA++;
    }
}

void sub_0802E70C(void)
{
    u32 done = 0;
    u32 count = 0;
    u32 i;

    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03001800.unkD2[i])
        {
            count++;
            if (gUnk_03001800.unkD6[i] == 0)
                done++;
            else
            {
                process_sprite_anim_commands(gUnk_083B5F80[gUnk_03000440.unk84], 0xA + i);
                if (gUnk_03002C30[0xA + i].unk22 == 0xFF)
                    done++;
            }
        }
    }
    if (done == count)
        gUnk_03001800.unkAA++;
}

void sub_0802E7A0(void)
{
    u32 i;

    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03001800.unkD2[i])
        {
            gUnk_03002C30[0xA + i].unk30 = gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk2;
            gUnk_03002C30[0xA + i].unk32 = gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 4;
            gUnk_03002C30[0xA + i].unk23 = 0;
        }
    }
    gUnk_03001800.unkAA++;
}

void sub_0802E820(void)
{
    u32 done = 0;
    u32 count = 0;
    u32 i;

    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03001800.unkD2[i])
        {
            count++;
            if (gUnk_03001800.unkF8 & 1)
                gUnk_03002C30[0xA + i].unk18 = (gUnk_03002C30[0xA + i].unk18 - 0x40) & 0x3FF;
            else
                gUnk_03002C30[0xA + i].unk18 = (gUnk_03002C30[0xA + i].unk18 + 0x40) & 0x3FF;
            if (move_sprite_toward_target(0xA + i))
            {
                gUnk_03002C30[0xA + i].unk18 = 0;
                done++;
            }
        }
    }
    if (done == count)
    {
        play_sound_effect(0x2B);
        gUnk_03001800.unkAA++;
    }
}

void sub_0802E8D4(void)
{
    u32 done = 0;
    u32 i;

    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03001800.unkD2[i])
        {
            if (gUnk_03002C30[0xA + i].unk8 == 2)
            {
                done = 1;
                clear_battle_sprite_slot(0xA + i, 1);
            }
            else
            {
                gUnk_03002C30[0xA + i].unk8 -= 2;
                gUnk_03002C30[0xA + i].unk9 -= 2;
            }
        }
    }
    if (done)
        gUnk_03001800.unkAA++;
}

void sub_0802E948(void)
{
    u32 i;

    lz_decompress_dispatch(gUnk_084E1518, (void *)0x06017000);
    CpuFastSet(gUnk_0850EED8, (void *)0x050002E0, 8);
    lz_decompress_dispatch(gUnk_084C8AC4, (void *)0x06014E00);
    CpuFastSet(gUnk_084E3018, (void *)0x050002C0, 8);
    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        gUnk_03002C30[0x21 + i].unk0 = ((gUnk_03001800.unk39[3] + 2) << 10) | 0xC004;
        gUnk_03002C30[0x21 + i].unk1C = 0;
        gUnk_03002C30[0x21 + i].unk2 = gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk2;
        gUnk_03002C30[0x21 + i].unk4 = gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 4;
        gUnk_03002C30[0x21 + i].unkA = 7;
        gUnk_03002C30[0x21 + i].unkB = 0x81;
        gUnk_03002C30[0x21 + i].unk30 = gUnk_03002C30[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk2;
        gUnk_03002C30[0x21 + i].unk32 = gUnk_03002C30[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk4 - 4;
        gUnk_03002C30[0x21 + i].unk24 = 6;
        gUnk_03002C30[0x21 + i].unk23 = 0;
        gUnk_03002C30[0x21 + i].unk29 = 1;
        if (gUnk_03001800.unkF8 & 1)
            gUnk_03002C30[0x21 + i].unk0 |= 0x1000;
        init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x6A], 0x21 + i);
    }
    gUnk_03001800.unkAA++;
}

void sub_0802EAA4(void)
{
    if (sub_080385F8())
        gUnk_03001800.unkAA++;
}

void sub_0802EAC0(void)
{
    gUnk_03001800.unkA6 = 0x67;
    gUnk_03001800.unkAA++;
}

void sub_0802EAD8(void)
{
    u32 i;

    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        gUnk_03000590[gUnk_03001800.unk60 + i].unkC1 = 0;
        gUnk_03001800.unkD2[i] = get_random_battle_weight_entry(gUnk_03001800.unk60 + i);
        battle_set_damage_vs_armor(gUnk_03001800.unk60 + i, gUnk_03001800.unkD2[i], gUnk_03001800.unkD6[i]);
        gUnk_03001800.unkD2[i] |= gUnk_03001800.unkD1 << 7;
        gUnk_03001800.unkD6[i] = gUnk_03001800.unkC8;
        gUnk_03000590[gUnk_03001800.unk60 + i].parts[gUnk_03001800.unkD2[i] & 0x7F].unk11 -= gUnk_03001800.unkD6[i];
        sub_08035194(gUnk_03001800.unk60 + i);
        if ((gUnk_03001800.unkD2[i] & 0x7F) == 0 && gUnk_03000590[gUnk_03001800.unk60 + i].parts[0].unk11 == 0)
            add_bot_to_defeated_list(gUnk_03001800.unk60 + i);
    }
    gUnk_03001800.unkAA++;
}

void sub_0802EBC0(void)
{
    gUnk_03001800.unkB5 = 0;
    gUnk_083AEA08[gUnk_03001800.unkAA]();
}

void sub_0802EBE8(void)
{
    u32 i;

    sub_0803836C();
    gUnk_03001800.unk60 = sub_08032FC4(gUnk_03001800.unk87);
    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03000590[gUnk_03001800.unk60 + i].unk40 && gUnk_03000590[gUnk_03001800.unk60 + i].parts[0].unk11)
            gUnk_03001800.unkD2[i] = 1;
    }
    gUnk_03001800.unkAA++;
}

void sub_0802EC4C(void)
{
    u32 i;

    lz_decompress_dispatch(gUnk_084D6F88, (void *)0x06014800);
    CpuFastSet(gUnk_0850E938, (void *)0x050002E0, 0x10);
    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        gUnk_03002C30[0x21 + i].unk0 = 0xC624;
        gUnk_03002C30[0x21 + i].unk1C = 0;
        gUnk_03002C30[0x21 + i].unk2 = gUnk_03002C30[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk2;
        gUnk_03002C30[0x21 + i].unk4 = gUnk_03002C30[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk4 - 4;
        gUnk_03002C30[0x21 + i].unk8 = 0x80;
        gUnk_03002C30[0x21 + i].unk9 = 0x80;
        gUnk_03002C30[0x21 + i].unk18 = 0;
        gUnk_03002C30[0x21 + i].unkA = 7;
        gUnk_03002C30[0x21 + i].unkB = 0xE0;
        gUnk_03000440.unk84 = 0x48;
        init_battle_sprite_entry_08040B90(gUnk_083B5F80[gUnk_03000440.unk84], i + 0x21);
    }
    play_sound_effect(0x6A);
    gUnk_03001800.unkAA++;
}

void sub_0802ED34(void)
{
    u32 done = 0;
    u32 i;

    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03001800.unkD2[i])
        {
            if (gUnk_03002C30[0x21 + i].unk8 == 0x40)
                done = 1;
            else
            {
                gUnk_03002C30[0x21 + i].unk8 -= 4;
                gUnk_03002C30[0x21 + i].unk9 -= 4;
            }
        }
    }
    if (done)
    {
        play_sound_effect(0x51);
        gUnk_03001800.unkAA++;
    }
}

void sub_0802ED90(void)
{
    u32 done = 0;
    u32 i;

    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03001800.unkD2[i])
        {
            process_sprite_anim_commands(gUnk_083B5F80[gUnk_03000440.unk84], 0x21 + i);
            if (gUnk_03002C30[0x21 + i].unk22 == 0xFF)
                done = 1;
        }
    }
    if (done)
    {
        gUnk_03000440.unk86 = 0x20;
        gUnk_03001800.unkAA++;
    }
}

void decrement_timer_and_decompress_sprite(void)
{
    u32 i;

    if (gUnk_03000440.unk86)
    {
        gUnk_03000440.unk86--;
        return;
    }
    lz_decompress_dispatch(gUnk_084E17E0, (void *)0x06015400);
    CpuFastSet(gUnk_084E30B8, (void *)0x050002C0, 8);
    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        gUnk_03002C30[0x24 + i].unk0 = 0xC624;
        gUnk_03002C30[0x24 + i].unk1C = 0;
        gUnk_03002C30[0x24 + i].unk2 = gUnk_03002C30[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk2;
        gUnk_03002C30[0x24 + i].unk4 = gUnk_03002C30[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk4 - 4;
        gUnk_03002C30[0x24 + i].unk8 = 0x40;
        gUnk_03002C30[0x24 + i].unk9 = 0x40;
        gUnk_03002C30[0x24 + i].unk18 = 0;
        gUnk_03002C30[0x24 + i].unkA = 6;
        gUnk_03002C30[0x24 + i].unkB = 0xF0;
        gUnk_03002C30[0x24 + i].unk23 = 0;
        gUnk_03002C30[0x24 + i].unk6 = 0x8100;
    }
    play_sound_effect(0x2A);
    gUnk_03001800.unkAA++;
}

void sub_0802EF0C(void)
{
    u32 done = 0;
    u32 i;

    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03001800.unkD2[i] && medal_update_exp_progress(0x24 + i, 0))
            done = 1;
    }
    if (done)
    {
        gUnk_03000440.unk86 = 0x3C;
        gUnk_03001800.unkAA++;
    }
}

void sub_0802EF5C(void)
{
    u32 done = 0;
    u32 i;

    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03001800.unkD2[i])
        {
            if (gUnk_03002C30[0x21 + i].unk8 == 4)
                done = 1;
            else
            {
                gUnk_03002C30[0x21 + i].unk8 -= 4;
                gUnk_03002C30[0x21 + i].unk9 -= 4;
                gUnk_03002C30[0x24 + i].unk8 -= 4;
                gUnk_03002C30[0x24 + i].unk9 -= 4;
            }
        }
    }
    if (done)
    {
        clear_battle_sprite_slot(0x21, 6);
        gUnk_03001800.unkAA++;
    }
}

void sub_0802EFD0(void)
{
    u32 i;

    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03001800.unkD2[i])
            gUnk_03000590[gUnk_03001800.unk60 + i].unkC0 |= 8;
    }
    gUnk_03001800.unkAA++;
}

void sub_0802F018(void)
{
    gUnk_03001800.unkA6 = 0x68;
    gUnk_03001800.unkAA++;
}

void sub_0802F030(void)
{
    gUnk_03001800.unkB5 = 0;
    gUnk_083AEA44[gUnk_03001800.unkAA]();
}

void sub_0802F058(void)
{
    lz_decompress_dispatch(gUnk_084D50DC, (void *)0x06015800);
    CpuFastSet(gUnk_0850E658, (void *)0x050002E0, 8);
    gUnk_03002C30[0x21].unk0 = 0xC624;
    gUnk_03002C30[0x21].unk1C = 0;
    gUnk_03002C30[0x21].unk2 = gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk2;
    gUnk_03002C30[0x21].unk4 = gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 4;
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

void sub_0802F13C(void)
{
    sub_080353CC(0x21);
    if (gUnk_03002C30[0x21].unk27 == 0x20)
    {
        gUnk_03002C30[0x21].unk18 = 0;
        gUnk_03000440.unk84 = 1;
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

void sub_0802F214(void)
{
    gUnk_03002C30[gUnk_03000440.unk84 + 0x21].unk0 = 0xC604;
    gUnk_03002C30[gUnk_03000440.unk84 + 0x21].unk1C = 0;
    gUnk_03002C30[gUnk_03000440.unk84 + 0x21].unk2 = gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk2;
    gUnk_03002C30[gUnk_03000440.unk84 + 0x21].unk4 = gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 4;
    gUnk_03002C30[gUnk_03000440.unk84 + 0x21].unkA = 7;
    gUnk_03002C30[gUnk_03000440.unk84 + 0x21].unkB = 0xF0;
    gUnk_03002C30[gUnk_03000440.unk84 + 0x21].unk8 = 0x40;
    gUnk_03002C30[gUnk_03000440.unk84 + 0x21].unk9 = 0x40;
    gUnk_03002C30[gUnk_03000440.unk84 + 0x21].unk18 = 0;
    gUnk_03002C30[gUnk_03000440.unk84 + 0x21].unk6 = 0x4100;
    gUnk_03002C30[gUnk_03000440.unk84 + 0x21].unk23 = 0;
    gUnk_03002C30[gUnk_03000440.unk84 + 0x21].unk27 = 0;
    play_sound_effect(0x29);
    gUnk_03001800.unkAA++;
}

void sub_0802F2F4(void)
{
    sub_080353CC(gUnk_03000440.unk84 + 0x21);
    if (gUnk_03002C30[gUnk_03000440.unk84 + 0x21].unk27 == 0x20)
    {
        clear_battle_sprite_slot(gUnk_03000440.unk84 + 0x21, 1);
        gUnk_03002C30[0x21].unk8 += gUnk_03000440.unk84 << 4;
        gUnk_03002C30[0x21].unk9 += gUnk_03000440.unk84 << 4;
        if (++gUnk_03000440.unk84 == 4)
            gUnk_03001800.unkAA++;
        else
            gUnk_03001800.unkAA = 2;
        return;
    }
    if (!(gUnk_03001800.unkF8 & 1))
        gUnk_03002C30[gUnk_03000440.unk84 + 0x21].unk18 = (gUnk_03002C30[gUnk_03000440.unk84 + 0x21].unk18 + 0x20) & 0x3FF;
    else
        gUnk_03002C30[gUnk_03000440.unk84 + 0x21].unk18 = (gUnk_03002C30[gUnk_03000440.unk84 + 0x21].unk18 - 0x20) & 0x3FF;
    if (!(gUnk_03002C30[gUnk_03000440.unk84 + 0x21].unk27 & 1))
    {
        if (!(gUnk_03001800.unkF8 & 1))
            gUnk_03002C30[gUnk_03000440.unk84 + 0x21].unk2++;
        else
            gUnk_03002C30[gUnk_03000440.unk84 + 0x21].unk2--;
    }
    gUnk_03002C30[gUnk_03000440.unk84 + 0x21].unk27++;
}

void sub_0802F3FC(void)
{
    gUnk_03002C30[0x21].unk30 = gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk2;
    gUnk_03002C30[0x21].unk32 = gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 4;
    gUnk_03002C30[0x21].unk24 = 4;
    gUnk_03002C30[0x21].unk23 = 0;
    gUnk_03001800.unkAA++;
}

void sub_0802F468(void)
{
    if (move_sprite_toward_target(0x21))
    {
        play_sound_effect(0x2B);
        gUnk_03001800.unkAA++;
    }
}

void sub_0802F48C(void)
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

void sub_0802F4D0(void)
{
    lz_decompress_dispatch(gUnk_084DFC18, (void *)0x06014800);
    CpuFastSet(gUnk_0850EE38, (void *)0x050002E0, 0x10);
    gUnk_03002C30[0x21].unk0 = 0xCC04;
    gUnk_03002C30[0x21].unk1C = 0;
    gUnk_03002C30[0x21].unk2 = gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk2;
    gUnk_03002C30[0x21].unk4 = gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 4;
    gUnk_03002C30[0x21].unkA = 7;
    gUnk_03002C30[0x21].unkB = 0;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x68], 0x21);
    play_sound_effect(0x2C);
    gUnk_03001800.unkAA++;
}

void sub_0802F594(void)
{
    process_sprite_anim_commands(gUnk_083B5F80[0x68], 0x21);
    if (gUnk_03002C30[0x21].unk22 == 0xFF)
    {
        clear_battle_sprite_slot(0x21, 1);
        gUnk_03001800.unkAA++;
    }
}

void sub_0802F5D8(void)
{
    sub_08035740(&gUnk_03000590[gUnk_03001800.unk87].unkD0 + 5, gUnk_03001800.unkEC, 0xFF);
    gUnk_03001800.unkAA++;
}

void sub_0802F610(void)
{
    gUnk_03001800.unkA6 = 0x51;
    gUnk_03001800.unkAA++;
}

void sub_0802F628(void)
{
    gUnk_03001800.unkB5 = 0;
    gUnk_083AEA84[gUnk_03001800.unkAA]();
}

void sub_0802F650(void)
{
    u32 i;

    sub_0803836C();
    gUnk_03001800.unk60 = sub_08032FB8(gUnk_03001800.unk87);
    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03000590[gUnk_03001800.unk60 + i].unk40 && gUnk_03000590[gUnk_03001800.unk60 + i].parts[0].unk11)
        {
            gUnk_03001800.unkD2[i] = 1;
            gUnk_03001800.unkD6[i] = gUnk_03000590[gUnk_03001800.unk60 + i].parts[3].unk11;
        }
    }
    gUnk_03001800.unkAA++;
}

void sub_0802F6CC(void)
{
    u32 i;

    lz_decompress_dispatch(gUnk_084E1884, (void *)0x06014800);
    CpuFastSet(gUnk_0850EEF8, (void *)0x050002E0, 8);
    CpuFastSet(gUnk_084E30B8, (void *)0x050002C0, 8);
    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        gUnk_03002C30[0x21 + i].unk0 = 0xC404;
        gUnk_03002C30[0x21 + i].unk1C = 0;
        gUnk_03002C30[0x21 + i].unk2 = 0x78;
        gUnk_03002C30[0x21 + i].unk4 = 0xF0;
        gUnk_03002C30[0x21 + i].unkA = 7;
        gUnk_03002C30[0x21 + i].unkB = 0xF0;
        gUnk_03002C30[0x21 + i].unk24 = 4;
        gUnk_03002C30[0x21 + i].unk25 = 0;
        gUnk_03002C30[0x21 + i].unk30 = 0;
        init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x6D], 0x21 + i);
        if (gUnk_03001800.unkF8 & 1)
            gUnk_03002C30[0x21 + i].unk0 |= 0x1000;
    }
    play_sound_effect(0x61);
    gUnk_03001800.unkAA++;
}

void sub_0802F7B8(void)
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
                gUnk_03002C30[0x21 + i].unk27 = 0;
                gUnk_03002C30[0x21 + i].unk28 = 0;
                gUnk_03002C30[0x21 + i].unk29 = 1;
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

void sub_0802F864(void)
{
    play_sound_effect(0x22);
    gUnk_03001800.unkAA++;
}

void sub_0802F880(void)
{
    if (sub_0803884C())
        gUnk_03001800.unkAA++;
}

void sub_0802F89C(void)
{
    u32 found = 0;
    u32 i;

    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03001800.unkD2[i] && gUnk_03001800.unkD6[i])
            found = 1;
    }
    if (!found)
        gUnk_03001800.unkAA++;
    else
        gUnk_03001800.unkAA += 2;
}

void sub_0802F8E4(void)
{
    u32 i;

    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03001800.unkD2[i] && gUnk_03001800.unkD6[i])
        {
            gUnk_03001800.unkD2[i] = 3;
            battle_set_damage_vs_armor(gUnk_03001800.unk60 + i, 3, gUnk_03001800.unkD6[i]);
            gUnk_03001800.unkD2[i] |= gUnk_03001800.unkD1 << 7;
            gUnk_03001800.unkD6[i] = gUnk_03001800.unkC8;
            gUnk_03000590[gUnk_03001800.unk60 + i].parts[gUnk_03001800.unkD2[i] & 0x7F].unk11 -= gUnk_03001800.unkD6[i];
            sub_08035194(gUnk_03001800.unk60 + i);
        }
    }
    gUnk_03001800.unkAA++;
}

void sub_0802F990(void)
{
    gUnk_03001800.unkB5 = 0;
    gUnk_083AEAD8[gUnk_03001800.unkAA]();
}

void sub_0802F9B8(void)
{
    lz_decompress_dispatch(gUnk_084E1B98, (void *)0x06014800);
    CpuFastSet(gUnk_0850EF18, (void *)0x050002C0, 8);
    CpuFastSet(gUnk_084E30B8, (void *)0x050002E0, 8);
    gUnk_03002C30[0x21].unk0 = 0xC404;
    gUnk_03002C30[0x21].unk1C = 0;
    gUnk_03002C30[0x21].unk4 = gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 0x1C;
    gUnk_03002C30[0x21].unkA = 6;
    gUnk_03002C30[0x21].unkB = 0xF0;
    gUnk_03002C30[0x21].unk6 = 0x8300;
    if (!(gUnk_03001800.unkF8 & 1))
        gUnk_03002C30[0x21].unk2 = gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk2 - 0x18;
    else
        gUnk_03002C30[0x21].unk2 = gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk2 + 0x18;
    gUnk_03002C30[0x22].unk0 = 0xC404;
    gUnk_03002C30[0x22].unk1C = 0;
    gUnk_03002C30[0x22].unk4 = gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 0x1C;
    gUnk_03002C30[0x22].unkA = 7;
    gUnk_03002C30[0x22].unkB = 0xF1;
    gUnk_03002C30[0x22].unk6 = 0x8301;
    if (!(gUnk_03001800.unkF8 & 1))
        gUnk_03002C30[0x22].unk2 = gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk2 + 0x18;
    else
    {
        gUnk_03002C30[0x22].unk2 = gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk2 - 0x18;
        gUnk_03002C30[0x22].unk0 |= 0x1000;
    }
    gUnk_03000440.unk86 = 0;
    play_sound_effect(0x2B);
    gUnk_03001800.unkAA++;
}

void sub_0802FB74(void)
{
    if (gUnk_03000440.unk86 == 0x18)
    {
        gUnk_03000440.unk86 = 0;
        gUnk_03001800.unkAA++;
        return;
    }
    gUnk_03000440.unk86++;
    if (!(gUnk_03001800.unkF8 & 1))
    {
        gUnk_03002C30[0x21].unk2++;
        gUnk_03002C30[0x22].unk2--;
    }
    else
    {
        gUnk_03002C30[0x21].unk2--;
        gUnk_03002C30[0x22].unk2++;
    }
}

void sub_0802FBF4(void)
{
    if (gUnk_03000440.unk86 == 0xC)
    {
        gUnk_03001800.unkAA++;
        return;
    }
    gUnk_03000440.unk86++;
    gUnk_03002C30[0x21].unk4 += 2;
    gUnk_03002C30[0x22].unk4 += 2;
}

void sub_0802FC3C(void)
{
    clear_battle_sprite_slot(0x21, 2);
    CpuFastSet(gUnk_0850EF18, (void *)0x050002C0, 0x10);
    gUnk_03002C30[0x21].unk0 = 0xC624;
    gUnk_03002C30[0x21].unk1C = 0;
    gUnk_03002C30[0x21].unk2 = gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk2;
    gUnk_03002C30[0x21].unk4 = gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 4;
    gUnk_03002C30[0x21].unkA = 7;
    gUnk_03002C30[0x21].unk8 = 0x80;
    gUnk_03002C30[0x21].unk9 = 0x80;
    gUnk_03002C30[0x21].unk18 = 0;
    gUnk_03002C30[0x21].unkB = 0xF0;
    gUnk_03002C30[0x21].unk6 = 0x8302;
    gUnk_03001800.unkAA++;
}

void sub_0802FD08(void)
{
    if (gUnk_03002C30[0x21].unk8 == 0x40)
    {
        play_sound_effect(0x54);
        gUnk_03001800.unkAA++;
    }
    else
    {
        gUnk_03002C30[0x21].unk8 -= 8;
        gUnk_03002C30[0x21].unk9 -= 8;
    }
}

void sub_0802FD4C(void)
{
    if (gUnk_03002C30[0x21].unk8 == 0x60)
        gUnk_03001800.unkAA++;
    else
    {
        gUnk_03002C30[0x21].unk8 += 4;
        gUnk_03002C30[0x21].unk9 += 4;
    }
}

void sub_0802FD84(void)
{
    if (gUnk_03002C30[0x21].unk8 == 0x40)
    {
        gUnk_03000440.unk86 = 0x3C;
        gUnk_03001800.unkAA++;
    }
    else
    {
        gUnk_03002C30[0x21].unk8 -= 4;
        gUnk_03002C30[0x21].unk9 -= 4;
    }
}

void sub_0802FDC8(void)
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

void sub_0802FE0C(void)
{
    gUnk_03000590[gUnk_03001800.unk87].unkC0 |= 1;
    gUnk_03001800.unkAA++;
}

void sub_0802FE38(void)
{
    gUnk_03001800.unkA6 = 0x4F;
    gUnk_03001800.unkAA++;
}

void sub_0802FE50(void)
{
    gUnk_03001800.unkB5 = 0;
    gUnk_083AEB18[gUnk_03001800.unkAA]();
}

void sub_0802FE78(void)
{
    lz_decompress_dispatch(gUnk_084E1EA4, (void *)0x06014800);
    CpuFastSet(gUnk_0850EF18, (void *)0x050002C0, 8);
    CpuFastSet(gUnk_084E30B8, (void *)0x050002E0, 8);
    gUnk_03002C30[0x21].unk0 = 0xC404;
    gUnk_03002C30[0x21].unk1C = 0;
    gUnk_03002C30[0x21].unk4 = gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 0x1C;
    gUnk_03002C30[0x21].unkA = 6;
    gUnk_03002C30[0x21].unkB = 0xF0;
    gUnk_03002C30[0x21].unk6 = 0x8400;
    if (!(gUnk_03001800.unkF8 & 1))
        gUnk_03002C30[0x21].unk2 = gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk2 - 0x18;
    else
        gUnk_03002C30[0x21].unk2 = gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk2 + 0x18;
    gUnk_03002C30[0x22].unk0 = 0xC404;
    gUnk_03002C30[0x22].unk1C = 0;
    gUnk_03002C30[0x22].unk4 = gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 0x1C;
    gUnk_03002C30[0x22].unkA = 6;
    gUnk_03002C30[0x22].unkB = 0xF0;
    gUnk_03002C30[0x22].unk6 = 0x8401;
    if (!(gUnk_03001800.unkF8 & 1))
        gUnk_03002C30[0x22].unk2 = gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk2 - 0x18;
    else
        gUnk_03002C30[0x22].unk2 = gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk2 + 0x18;
    gUnk_03002C30[0x23].unk0 = 0xC404;
    gUnk_03002C30[0x23].unk1C = 0;
    gUnk_03002C30[0x23].unk4 = gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 0x1C;
    gUnk_03002C30[0x23].unkA = 7;
    gUnk_03002C30[0x23].unkB = 0xF1;
    gUnk_03002C30[0x23].unk6 = 0x8402;
    if (!(gUnk_03001800.unkF8 & 1))
        gUnk_03002C30[0x23].unk2 = gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk2 + 0x18;
    else
    {
        gUnk_03002C30[0x23].unk2 = gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk2 - 0x18;
        gUnk_03002C30[0x23].unk0 |= 0x1000;
    }
    gUnk_03002C30[0x24].unk0 = 0xC404;
    gUnk_03002C30[0x24].unk1C = 0;
    gUnk_03002C30[0x24].unk4 = gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 0x1C;
    gUnk_03002C30[0x24].unkA = 7;
    gUnk_03002C30[0x24].unkB = 0xF1;
    gUnk_03002C30[0x24].unk6 = 0x8403;
    if (!(gUnk_03001800.unkF8 & 1))
        gUnk_03002C30[0x24].unk2 = gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk2 + 0x18;
    else
    {
        gUnk_03002C30[0x24].unk2 = gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk2 - 0x18;
        gUnk_03002C30[0x24].unk0 |= 0x1000;
    }
    gUnk_03000440.unk86 = 0;
    play_sound_effect(0x2B);
    gUnk_03001800.unkAA++;
}

void sub_08030180(void)
{
    if (gUnk_03000440.unk86 == 0x18)
    {
        gUnk_03000440.unk86 = 0;
        gUnk_03001800.unkAA++;
        return;
    }
    gUnk_03000440.unk86++;
    if (!(gUnk_03001800.unkF8 & 1))
    {
        gUnk_03002C30[0x21].unk2++;
        gUnk_03002C30[0x22].unk2++;
        gUnk_03002C30[0x23].unk2--;
        gUnk_03002C30[0x24].unk2--;
    }
    else
    {
        gUnk_03002C30[0x21].unk2--;
        gUnk_03002C30[0x22].unk2--;
        gUnk_03002C30[0x23].unk2++;
        gUnk_03002C30[0x24].unk2++;
    }
}

void sub_08030238(void)
{
    if (gUnk_03000440.unk86 == 0xC)
    {
        gUnk_03001800.unkAA++;
        return;
    }
    gUnk_03000440.unk86++;
    gUnk_03002C30[0x21].unk4 += 2;
    gUnk_03002C30[0x22].unk4 += 2;
    gUnk_03002C30[0x23].unk4 += 2;
    gUnk_03002C30[0x24].unk4 += 2;
}

void sub_0803029C(void)
{
    gUnk_03002C30[0x25].unk0 = 0xC404;
    gUnk_03002C30[0x25].unk1C = 0;
    gUnk_03002C30[0x25].unk2 = gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk2;
    gUnk_03002C30[0x25].unk4 = gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 4;
    gUnk_03002C30[0x25].unkA = 7;
    gUnk_03002C30[0x25].unkB = 0xF2;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x6F], 0x25);
    if (gUnk_03001800.unkF8 & 1)
        gUnk_03002C30[0x25].unk0 |= 0x1000;
    play_sound_effect(0x30);
    gUnk_03001800.unkAA++;
}

void sub_08030354(void)
{
    process_sprite_anim_commands(gUnk_083B5F80[0x6F], 0x25);
    if (gUnk_03002C30[0x25].unk22 == 0xFF)
    {
        gUnk_03000440.unk86 = 0;
        clear_battle_sprite_slot(0x25, 1);
        gUnk_03001800.unkAA++;
    }
}

void sub_080303A4(void)
{
    if (gUnk_03000440.unk86 == 0x20)
    {
        gUnk_03000440.unk86 = 0;
        gUnk_03001800.unkAA++;
        return;
    }
    if (gUnk_03000440.unk86 & 1)
    {
        if (!(gUnk_03001800.unkF8 & 1))
        {
            gUnk_03002C30[0x21].unk2 = (gUnk_03002C30[0x21].unk2 - 1) & 0x1FF;
            gUnk_03002C30[0x22].unk2 = (gUnk_03002C30[0x22].unk2 + 1) & 0x1FF;
            gUnk_03002C30[0x23].unk2 = (gUnk_03002C30[0x23].unk2 - 1) & 0x1FF;
            gUnk_03002C30[0x24].unk2 = (gUnk_03002C30[0x24].unk2 + 1) & 0x1FF;
        }
        else
        {
            gUnk_03002C30[0x21].unk2 = (gUnk_03002C30[0x21].unk2 + 1) & 0x1FF;
            gUnk_03002C30[0x22].unk2 = (gUnk_03002C30[0x22].unk2 - 1) & 0x1FF;
            gUnk_03002C30[0x23].unk2 = (gUnk_03002C30[0x23].unk2 + 1) & 0x1FF;
            gUnk_03002C30[0x24].unk2 = (gUnk_03002C30[0x24].unk2 - 1) & 0x1FF;
        }
    }
    gUnk_03000440.unk86++;
}

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
