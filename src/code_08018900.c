#include "global.h"

INCLUDE_ASM("asm/nonmatching/code_08018900", sub_08018900);

void sub_080189EC(void)
{
    u32 i;

    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03000590[i].unk40)
            sub_08018900(i);
    }
}

void sub_08018A18(void)
{
    u32 i;

    if ((gUnk_030057E0.unkC2E & 0xF0) == 0x20)
    {
        for (i = 0; i <= 2; i++)
            gUnk_03000590[i + 3].unkC1 = 0x50;
    }
}

void select_battle_music(void)
{
    if (gUnk_03000440.unk89 == 1)
        play_song(9);
    else if ((gUnk_030057E0.unkC2E & 0xF0) != 0)
    {
        if ((gUnk_030057E0.unkC2E & 0xF0) == 0x10)
            play_song(0xC);
        else
            play_song(0xD);
    }
    else
        play_song(gUnk_083AD3B0[gUnk_03000B94]);
}

INCLUDE_ASM("asm/nonmatching/code_08018900", init_battle_action_select_ui);

void sub_08018BD4(void)
{
    if (gUnk_03000440.unk89 == 1)
    {
        gUnk_03001800.unk57 = 40;
        return;
    }
    switch (gUnk_03001788)
    {
    case 0:
        gUnk_03001800.unk57 = 40;
        break;
    case 1:
        gUnk_03001800.unk57 = 30;
        break;
    case 2:
        gUnk_03001800.unk57 = 20;
        break;
    }
}

void sub_08018C38(void)
{
    if ((gUnk_03001800.unk56 = (gUnk_03001800.unk56 + 1) & 0x1F) == 0 && gUnk_03001800.unk57 != 0)
    {
        gUnk_03001800.unk57--;
        gUnk_03001800.unk16B++;
        sub_08018CBC();
    }
}

void sub_08018C78(void)
{
    gUnk_03002C30[1].unk6 = (u8)(gUnk_03001800.unk57 / 10) + 0x624;
    gUnk_03002C30[2].unk6 = (u8)(gUnk_03001800.unk57 % 10) + 0x624;
}

void sub_08018CBC(void)
{
    u32 i;

    gUnk_03001800.unk55 = 0;
    for (i = 0; i <= 5; i++)
    {
        if (gUnk_03000590[i].unk40)
        {
            if (gUnk_03000590[i].unkC4)
                sub_08018D0C(i);
            if (gUnk_03000590[i].unkC9)
                sub_08018DF4(i);
        }
    }
}

void sub_08018D0C(u32 rec)
{
    s32 t;
    u32 i, k, v, done;

    t = gUnk_03000590[rec].unkC6 - 4;
    if (t <= 0)
    {
        gUnk_03000590[rec].unkC4 = 0;
        gUnk_03000590[rec].unkC5 = 0;
        gUnk_03000590[rec].unkC6 = 0;
        gUnk_03000590[rec].unkC7 = 0;
        gUnk_03000590[rec].unkCE |= 1;
        gUnk_03001800.unk55 |= 2;
        return;
    }
    gUnk_03000590[rec].unkC6 = t;
    if (gUnk_03000590[rec].unkC4 != 0x1F)
        return;
    gUnk_03001800.unk59 = gUnk_03000590[rec].unkC7;
    gUnk_03001800.unk86 = 0;
    done = 0;
    for (i = 0; i <= 3; i++)
    {
        k = sub_08018EE0(rec);
        if (k != 0)
        {
            v = add_part_stat_clamped(rec, k - 1, gUnk_03001800.unk59);
            gUnk_03001800.unk86 += v;
            gUnk_03001800.unk59 = (v & 0xFF00) >> 8;
            done = 1;
            if (gUnk_03001800.unk59 == 0)
                break;
        }
        else
            break;
    }
    if (done)
    {
        gUnk_03000590[rec].unkC8 = gUnk_03001800.unk86;
        gUnk_03000590[rec].unkCE |= 4;
        gUnk_03001800.unk55 |= 8;
    }
}

void sub_08018DF4(u32 rec)
{
    s32 t;
    u32 i, k, v, done;

    t = gUnk_03000590[rec].unkCB - 4;
    if (t <= 0)
    {
        gUnk_03000590[rec].unkC9 = 0;
        gUnk_03000590[rec].unkCA = 0;
        gUnk_03000590[rec].unkCB = 0;
        gUnk_03000590[rec].unkCC = 0;
        gUnk_03000590[rec].unkCE |= 2;
        gUnk_03001800.unk55 |= 4;
        return;
    }
    gUnk_03000590[rec].unkCB = t;
    if ((u8)(gUnk_03000590[rec].unkC9 - 0x13) > 1)
        return;
    gUnk_03001800.unk59 = gUnk_03000590[rec].unkCC;
    gUnk_03001800.unk86 = 0;
    done = 0;
    for (i = 0; i <= 3; i++)
    {
        k = sub_08018F6C(rec);
        if (k != 0)
        {
            v = sub_08018FF0(rec, k - 1, gUnk_03001800.unk59);
            gUnk_03001800.unk86 += v;
            gUnk_03001800.unk59 = (v & 0xFF00) >> 8;
            done = 1;
            if (gUnk_03001800.unk59 == 0)
                break;
        }
        else
            break;
    }
    if (done)
    {
        gUnk_03000590[rec].unkCD = gUnk_03001800.unk86;
        gUnk_03000590[rec].unkCE |= 8;
        gUnk_03001800.unk55 |= 0x10;
    }
}

INCLUDE_ASM("asm/nonmatching/code_08018900", sub_08018EE0);
INCLUDE_ASM("asm/nonmatching/code_08018900", add_part_stat_clamped);

u32 sub_08018F48(u32 rec)
{
    u32 i;

    for (i = 0; i <= 3; i++)
    {
        if (gUnk_03000590[rec].parts[3 - i].unk11)
            return i + 1;
    }
    return 0;
}

u32 sub_08018F6C(u32 rec)
{
    u32 k, i;

    if (gUnk_03000590[rec].unkCA == 0)
        k = 4;
    else
        k = gUnk_03000590[rec].unkCA;
    for (i = 0; i <= 3; i++)
    {
        if (gUnk_03000590[rec].parts[k - 1].unk11 > 1)
            return k;
        k--;
        if (k == 0)
            k = 4;
    }
    return 0;
}

u32 sub_08018FB8(u32 rec, u32 part, s32 amount)
{
    u32 cur = gUnk_03000590[rec].parts[part].unk11;
    s32 v = cur - amount;
    u32 ret;

    if (v >= 0)
    {
        gUnk_03000590[rec].parts[part].unk11 = v;
        ret = amount;
    }
    else
    {
        gUnk_03000590[rec].parts[part].unk11 = 0;
        ret = ((amount - cur) << 8) + cur;
    }
    return ret;
}

u32 sub_08018FF0(u32 rec, u32 part, s32 amount)
{
    u32 cur = gUnk_03000590[rec].parts[part].unk11;
    u32 m = cur - 1;
    u32 ret;

    if ((s32)(m - amount) >= 0)
    {
        gUnk_03000590[rec].parts[part].unk11 = cur - amount;
        ret = amount;
    }
    else
    {
        gUnk_03000590[rec].parts[part].unk11 = 1;
        ret = ((amount - m) << 8) + m;
    }
    return ret;
}

void sub_0801902C(void)
{
    u32 i;

    for (i = 0; i <= 5; i++)
    {
        if (gUnk_03000590[i].unk40 && (u8)(gUnk_03000590[i].unkC9 - 0xF) > 1)
        {
            sub_080190B8(i);
            sub_08019348(i);
            sub_08019544(i);
        }
    }
}

void sub_08019078(void)
{
    u32 i;

    for (i = 0; i <= 5; i++)
    {
        if (gUnk_03000590[i].unk40 && (u8)(gUnk_03000590[i].unkC9 - 0xF) > 1)
        {
            sub_08019544(i);
        }
    }
}

void sub_080190B8(u32 rec)
{
    gUnk_03000590[rec].unkBB = 0;
    sub_08019108(rec);
    sub_080191C0(rec);
    sub_080191E4(rec);
    sub_0801922C(rec);
    sub_08019264(rec);
    sub_0801928C(rec);
    sub_080192B8(rec);
    sub_080192E8(rec);
    sub_0801932C(rec);
}

INCLUDE_ASM("asm/nonmatching/code_08018900", sub_08019108);
INCLUDE_ASM("asm/nonmatching/code_08018900", sub_08019184);
INCLUDE_ASM("asm/nonmatching/code_08018900", sub_080191A4);
INCLUDE_ASM("asm/nonmatching/code_08018900", sub_080191C0);
INCLUDE_ASM("asm/nonmatching/code_08018900", sub_080191E4);
INCLUDE_ASM("asm/nonmatching/code_08018900", sub_0801922C);
INCLUDE_ASM("asm/nonmatching/code_08018900", sub_08019264);
INCLUDE_ASM("asm/nonmatching/code_08018900", sub_0801928C);
INCLUDE_ASM("asm/nonmatching/code_08018900", sub_080192B8);
INCLUDE_ASM("asm/nonmatching/code_08018900", sub_080192E8);
INCLUDE_ASM("asm/nonmatching/code_08018900", sub_0801932C);
INCLUDE_ASM("asm/nonmatching/code_08018900", sub_08019348);
INCLUDE_ASM("asm/nonmatching/code_08018900", sub_08019440);
INCLUDE_ASM("asm/nonmatching/code_08018900", sub_08019544);
INCLUDE_ASM("asm/nonmatching/code_08018900", update_all_battle_status_sprites);
INCLUDE_ASM("asm/nonmatching/code_08018900", battle_bot_status_sprite_update);
INCLUDE_ASM("asm/nonmatching/code_08018900", battle_update_status_effect_sprite);
INCLUDE_ASM("asm/nonmatching/code_08018900", update_battle_status_effect_sprite);
INCLUDE_ASM("asm/nonmatching/code_08018900", battle_setup_part_sprite);
INCLUDE_ASM("asm/nonmatching/code_08018900", sub_08019EF0);
INCLUDE_ASM("asm/nonmatching/code_08018900", sub_08019FBC);
INCLUDE_ASM("asm/nonmatching/code_08018900", sub_0801A030);
INCLUDE_ASM("asm/nonmatching/code_08018900", battle_add_active_medal_slot);
INCLUDE_ASM("asm/nonmatching/code_08018900", iterate_bots_setup_battle_sprites);
INCLUDE_ASM("asm/nonmatching/code_08018900", sub_0801A144);
INCLUDE_ASM("asm/nonmatching/code_08018900", sub_0801A228);
INCLUDE_ASM("asm/nonmatching/code_08018900", set_display_digit_type);
INCLUDE_ASM("asm/nonmatching/code_08018900", render_battle_text_sprites);
INCLUDE_ASM("asm/nonmatching/code_08018900", battle_setup_text_sprites_0801A418);
INCLUDE_ASM("asm/nonmatching/code_08018900", battle_setup_text_sprites_0801A4F4);
INCLUDE_ASM("asm/nonmatching/code_08018900", update_battle_sprite_animations);
INCLUDE_ASM("asm/nonmatching/code_08018900", sort_active_medal_slots);
INCLUDE_ASM("asm/nonmatching/code_08018900", battle_calc_bot_count_minus_one_mod3);
INCLUDE_ASM("asm/nonmatching/code_08018900", sub_0801A678);
INCLUDE_ASM("asm/nonmatching/code_08018900", sub_0801A6B0);
INCLUDE_ASM("asm/nonmatching/code_08018900", sub_0801A6EC);
INCLUDE_ASM("asm/nonmatching/code_08018900", sub_0801A744);
INCLUDE_ASM("asm/nonmatching/code_08018900", battle_phase_dispatch_0801A788);
INCLUDE_ASM("asm/nonmatching/code_08018900", sub_0801ABF8);
INCLUDE_ASM("asm/nonmatching/code_08018900", sub_0801AC24);
INCLUDE_ASM("asm/nonmatching/code_08018900", sub_0801AC6C);
INCLUDE_ASM("asm/nonmatching/code_08018900", sub_0801AC98);
INCLUDE_ASM("asm/nonmatching/code_08018900", sub_0801AD10);
INCLUDE_ASM("asm/nonmatching/code_08018900", sub_0801AD48);
INCLUDE_ASM("asm/nonmatching/code_08018900", sub_0801ADE8);
INCLUDE_ASM("asm/nonmatching/code_08018900", sub_0801AE70);
INCLUDE_ASM("asm/nonmatching/code_08018900", sub_0801AEB4);
INCLUDE_ASM("asm/nonmatching/code_08018900", clear_battle_ui_tilemaps);
INCLUDE_ASM("asm/nonmatching/code_08018900", battle_increment_bot_level);
INCLUDE_ASM("asm/nonmatching/code_08018900", sub_0801AFB8);
INCLUDE_ASM("asm/nonmatching/code_08018900", sub_0801B004);
INCLUDE_ASM("asm/nonmatching/code_08018900", sub_0801B0E8);
INCLUDE_ASM("asm/nonmatching/code_08018900", sub_0801B274);
INCLUDE_ASM("asm/nonmatching/code_08018900", sub_0801B3AC);
INCLUDE_ASM("asm/nonmatching/code_08018900", sub_0801B4C8);
INCLUDE_ASM("asm/nonmatching/code_08018900", sub_0801B4F8);
INCLUDE_ASM("asm/nonmatching/code_08018900", sub_0801B53C);
INCLUDE_ASM("asm/nonmatching/code_08018900", reset_bot_status_and_init_palette_transfers);
INCLUDE_ASM("asm/nonmatching/code_08018900", sub_0801B67C);
INCLUDE_ASM("asm/nonmatching/code_08018900", select_next_bot_and_action);
INCLUDE_ASM("asm/nonmatching/code_08018900", find_next_active_bot);
INCLUDE_ASM("asm/nonmatching/code_08018900", determine_battle_part_action_priority);
INCLUDE_ASM("asm/nonmatching/code_08018900", sub_0801B894);
INCLUDE_ASM("asm/nonmatching/code_08018900", sub_0801B9C4);
INCLUDE_ASM("asm/nonmatching/code_08018900", sub_0801BACC);
INCLUDE_ASM("asm/nonmatching/code_08018900", copy_battle_entity_positions);
INCLUDE_ASM("asm/nonmatching/code_08018900", init_battle_bot_sprites);
INCLUDE_ASM("asm/nonmatching/code_08018900", init_battle_sprite_entry_0801BC04);
INCLUDE_ASM("asm/nonmatching/code_08018900", decompress_indexed_graphics_to_ewram);
INCLUDE_ASM("asm/nonmatching/code_08018900", decompress_fixed_graphics_to_ewram);
INCLUDE_ASM("asm/nonmatching/code_08018900", load_battle_entity_palette);
INCLUDE_ASM("asm/nonmatching/code_08018900", init_game_state_entry);
INCLUDE_ASM("asm/nonmatching/code_08018900", process_animation_script);
INCLUDE_ASM("asm/nonmatching/code_08018900", increment_medal_skill_level);
INCLUDE_ASM("asm/nonmatching/code_08018900", sync_medal_stats_from_battle_bot);

void sub_0801BF64(u16 *counter, u16 max)
{
    if (*counter != max)
        (*counter)++;
}

INCLUDE_ASM("asm/nonmatching/code_08018900", sub_0801BF78);
INCLUDE_ASM("asm/nonmatching/code_08018900", sub_0801BFB4);
INCLUDE_ASM("asm/nonmatching/code_08018900", sub_0801C0BC);
INCLUDE_ASM("asm/nonmatching/code_08018900", sub_0801C0F8);
INCLUDE_ASM("asm/nonmatching/code_08018900", sub_0801C110);
INCLUDE_ASM("asm/nonmatching/code_08018900", sub_0801C138);
INCLUDE_ASM("asm/nonmatching/code_08018900", sub_0801C154);
INCLUDE_ASM("asm/nonmatching/code_08018900", sub_0801C188);
INCLUDE_ASM("asm/nonmatching/code_08018900", sub_0801C1C0);
INCLUDE_ASM("asm/nonmatching/code_08018900", sub_0801C23C);
INCLUDE_ASM("asm/nonmatching/code_08018900", sub_0801C298);
INCLUDE_ASM("asm/nonmatching/code_08018900", dispatch_battle_action_substate);
INCLUDE_ASM("asm/nonmatching/code_08018900", sub_0801C32C);
INCLUDE_ASM("asm/nonmatching/code_08018900", sub_0801C360);
INCLUDE_ASM("asm/nonmatching/code_08018900", sub_0801C388);
INCLUDE_ASM("asm/nonmatching/code_08018900", sub_0801C3B0);

void sub_0801C3F8(void)
{
    animate_battle_sprites(gUnk_03001800.unk87);
}

INCLUDE_ASM("asm/nonmatching/code_08018900", sub_0801C40C);
INCLUDE_ASM("asm/nonmatching/code_08018900", sub_0801C444);
INCLUDE_ASM("asm/nonmatching/code_08018900", sub_0801C470);
INCLUDE_ASM("asm/nonmatching/code_08018900", sub_0801C4A4);
INCLUDE_ASM("asm/nonmatching/code_08018900", sub_0801C4E0);
INCLUDE_ASM("asm/nonmatching/code_08018900", sub_0801C4FC);
INCLUDE_ASM("asm/nonmatching/code_08018900", sub_0801C524);
INCLUDE_ASM("asm/nonmatching/code_08018900", sub_0801C660);
INCLUDE_ASM("asm/nonmatching/code_08018900", sub_0801C6C4);
INCLUDE_ASM("asm/nonmatching/code_08018900", sub_0801C774);
