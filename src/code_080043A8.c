#include "global.h"

void sub_080043A8(void)
{
    struct Unk_03000440 *st;
    u8 *done;
    u8 *frame;

    sub_08004E74();
    sub_08006764();
    toggle_sprite_pair_visibility();
    dispatch_game_substate_handler_08006824();
    battle_update_medabot_display();
    sub_08006F14();
    st = &gUnk_03000440;
    done = &st->unk56;
    if (*done == 0)
    {
        frame = &st->unk84;
        if (*frame > 8)
            goto finish;
        blend_obj_palettes_to_color_0803F684(0, 32 - *frame * 4, 0xFFFF);
        blend_obj_palettes_to_color_0803F998(0, 32 - *frame * 4, 0xF0FF);
        (*frame)++;
    }
    else if (update_blend_effect())
    {
    finish:
        *done = 1;
        gGameSubState++;
    }
}

void sub_0800442C(void)
{
    u8 r;

    sub_08004E74();
    sub_08006764();
    toggle_sprite_pair_visibility();
    dispatch_game_substate_handler_08006824();
    battle_update_medabot_display();
    sub_08006F14();
    if (sub_080068EC() || sub_08006980() || sub_08006A00() || sub_08006A98() || sub_08006B30() || sub_08006BC8()
        || sub_08006C64())
        return;
    if (KEYS_LO(gNewKeys) & 2)
    {
        play_sound_effect(5);
        gGameSubState++;
    }
    else if (*((u8 *)&gNewKeys + 1) & 3)
    {
        play_sound_effect(2);
        gUnk_03000440.unk5E ^= 1;
        setup_scene_with_link_check();
        setup_battle_sprite_from_game_state();
    }
    else
    {
        r = sub_08006F34();
        if (r == 2)
            play_sound_effect(6);
        else if (r == 1)
        {
            play_sound_effect(4);
            gGameSubState = 24;
        }
    }
}

void sub_080044F8(void)
{
    struct Unk_03000440 *st;
    u8 v;

    sub_08004E74();
    sub_08006764();
    toggle_sprite_pair_visibility();
    dispatch_game_substate_handler_08006824();
    battle_update_medabot_display();
    sub_08006F14();
    st = &gUnk_03000440;
    v = st->unk50;
    if (v == 0)
    {
        copy_obj_palette_to_buffer();
        st->unk84 = v;
    }
    else
        set_blend_effect_mode(6, 0x3F, 0x20);
    gGameSubState++;
}

void sub_0800454C(void)
{
    u8 *frame;

    sub_08004E74();
    sub_08006764();
    toggle_sprite_pair_visibility();
    dispatch_game_substate_handler_08006824();
    battle_update_medabot_display();
    sub_08006F14();
    if (gUnk_03000440.unk50 == 0)
    {
        frame = &gUnk_03000440.unk84;
        if (*frame > 8)
            goto finish;
        blend_obj_palettes_to_color_0803F684(0, *frame * 4, 0xFFFF);
        blend_obj_palettes_to_color_0803F998(0, *frame * 4, 0xF0FF);
        (*frame)++;
    }
    else if (update_blend_effect())
    {
    finish:
        gGameSubState++;
    }
}

void sub_080045C4(void)
{
    sub_08006764();
    assign_medal_to_team_slot();
    gGameSubState = 0;
}

void sub_080045DC(void)
{
    sub_08004E74();
    sub_08006764();
    toggle_sprite_pair_visibility();
    dispatch_game_substate_handler_08006824();
    battle_update_medabot_display();
    sub_08006F14();
    set_blend_effect_mode(6, 0x3F, 0x20);
    gGameSubState++;
}

void sub_08004610(void)
{
    sub_08004E74();
    sub_08006764();
    toggle_sprite_pair_visibility();
    dispatch_game_substate_handler_08006824();
    battle_update_medabot_display();
    sub_08006F14();
    if (update_blend_effect())
        gGameSubState++;
}

void sub_08004644(void)
{
    clear_battle_sprite_slot(0, 0x80);
    gUnk_03000440.unk96 = 0;
    gUnk_03000430 = 0;
    switch (gUnk_03000440.unk5A)
    {
    case 0:
        sub_0803F624(&gUnk_03000440.unk3C, 0x14, 0);
        gUnk_03000440.unk3C = 1;
        gUnk_03000440.unk3D = gUnk_03000440.unk97;
        sub_080070F0();
        gGameState = 4;
        gGameSubState = 8;
        break;
    case 1:
        sub_0803F624(&gUnk_03000440.unk3C, 0x14, 0);
        gUnk_03000440.unk3C = 1;
        gUnk_03000440.unk3D = gUnk_03000440.unk98;
        gUnk_03000440.unk3E = 0;
        gGameState = 5;
        gGameSubState = 16;
        break;
    case 2:
        sub_0803F624(&gUnk_03000440.unk3C, 0x14, 0);
        gUnk_03000440.unk3C = 1;
        gUnk_03000440.unk3D = gUnk_03000440.unk99;
        gUnk_03000440.unk3E = 1;
        gGameState = 5;
        gGameSubState = 16;
        break;
    case 3:
        sub_0803F624(&gUnk_03000440.unk3C, 0x14, 0);
        gUnk_03000440.unk3C = 1;
        gUnk_03000440.unk3D = gUnk_03000440.unk9A;
        gUnk_03000440.unk3E = 2;
        gGameState = 5;
        gGameSubState = 16;
        break;
    case 4:
        sub_0803F624(&gUnk_03000440.unk3C, 0x14, 0);
        gUnk_03000440.unk3C = 1;
        gUnk_03000440.unk3D = gUnk_03000440.unk9B;
        gUnk_03000440.unk3E = 3;
        gGameState = 5;
        gGameSubState = 16;
        break;
    }
}

void sub_08004764(void)
{
    sub_08004E74();
    sub_08005000();
    setup_overworld_scene_from_position();
    clear_sprite_table_mask(0, 4);
    gUnk_03000440.unk5C = 0;
    gGameSubState++;
}

void sub_08004798(void)
{
    sub_08004E74();
    setup_overworld_scene_from_position();
    sub_08007480();
    if (gUnk_03000440.unk5C > 60)
    {
        if (gUnk_03000440.unk50 == 1)
            gGameSubState = 48;
        else
        {
            copy_obj_palette_to_buffer();
            gUnk_03000440.unk84 = 0;
            gGameSubState++;
        }
    }
}

void sub_080047EC(void)
{
    struct Unk_03000440 *st;
    u8 *frame;

    sub_08004E74();
    setup_overworld_scene_from_position();
    sub_08007480();
    st = &gUnk_03000440;
    frame = &st->unk84;
    if (*frame <= 32)
    {
        blend_obj_palettes_to_color_0803F684(0, *frame, 0xFFFF);
        blend_obj_palettes_to_color_0803F998(0, *frame, 0xFFFF);
        (*frame)++;
    }
    else
        gGameSubState++;
}

void team_select_exit_battle(void)
{
    clear_battle_sprite_slot(0, 0x80);
    gUnk_03000440.unk96 = 0;
    gUnk_03000430 = 0;
    gGameState = 7;
    gGameSubState = 0;
}

void sub_08004874(void)
{
    sub_08004E74();
    setup_overworld_scene_from_position();
    sub_08007480();
    if (gUnk_03000440.unk5C > 60)
    {
        sound_stop_all_with_fade_guard(8);
        set_blend_effect_mode(6, 0x3F, 8);
        gGameSubState++;
    }
}

void sub_080048B0(void)
{
    sub_08004E74();
    setup_overworld_scene_from_position();
    sub_08007480();
    if (update_blend_effect())
        gGameSubState++;
}

INCLUDE_ASM("asm/nonmatching/code_080043A8", team_select_exit_race);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_080049C8);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_080049EC);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_08004A18);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_08004A40);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_08004A78);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_08004AF8);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_08004C58);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_08004CA4);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_08004DB4);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_08004DF0);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_08004E40);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_08004E74);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_08004E98);
INCLUDE_ASM("asm/nonmatching/code_080043A8", update_battle_sprite_orbit_clockwise);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_08004FD0);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_08005000);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_0800508C);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_08005118);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_0800519C);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_0800522C);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_0800529C);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_080053C8);
INCLUDE_ASM("asm/nonmatching/code_080043A8", setup_overworld_scene_from_position);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_08005588);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_08005628);
INCLUDE_ASM("asm/nonmatching/code_080043A8", update_battle_sprite_orbit_counterclockwise);
INCLUDE_ASM("asm/nonmatching/code_080043A8", update_battle_icon_blink_and_orbit);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_080058A4);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_08005948);
INCLUDE_ASM("asm/nonmatching/code_080043A8", check_and_update_battle_sprite_orbit);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_080059D0);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_08005AD0);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_08005B44);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_08005BB4);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_08005C10);
INCLUDE_ASM("asm/nonmatching/code_080043A8", render_script_text_window);
INCLUDE_ASM("asm/nonmatching/code_080043A8", render_medal_skill_row_0);
INCLUDE_ASM("asm/nonmatching/code_080043A8", render_medal_name_text);
INCLUDE_ASM("asm/nonmatching/code_080043A8", render_medal_skill_row_1);
INCLUDE_ASM("asm/nonmatching/code_080043A8", render_medal_desc_text);
INCLUDE_ASM("asm/nonmatching/code_080043A8", render_medal_skill_row_2);
INCLUDE_ASM("asm/nonmatching/code_080043A8", render_script_text_line);
INCLUDE_ASM("asm/nonmatching/code_080043A8", render_medal_skill_row_3);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_08006238);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_08006284);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_080062D0);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_0800631C);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_08006368);
INCLUDE_ASM("asm/nonmatching/code_080043A8", draw_battle_stat_value);
INCLUDE_ASM("asm/nonmatching/code_080043A8", decompress_sprite_from_game_state);
INCLUDE_ASM("asm/nonmatching/code_080043A8", setup_battle_sprite_from_game_state);
INCLUDE_ASM("asm/nonmatching/code_080043A8", setup_battle_cursor_sprites);
INCLUDE_ASM("asm/nonmatching/code_080043A8", toggle_sprite_pair_visibility);
INCLUDE_ASM("asm/nonmatching/code_080043A8", init_scene_state);
INCLUDE_ASM("asm/nonmatching/code_080043A8", setup_scene_with_link_check);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_08006764);
INCLUDE_ASM("asm/nonmatching/code_080043A8", dispatch_game_substate_handler_08006824);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_080068EC);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_08006980);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_08006A00);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_08006A98);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_08006B30);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_08006BC8);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_08006C64);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_08006E08);
INCLUDE_ASM("asm/nonmatching/code_080043A8", battle_update_medabot_display);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_08006F14);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_08006F34);
INCLUDE_ASM("asm/nonmatching/code_080043A8", assign_medal_to_team_slot);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_080070F0);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_0800712C);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_0800725C);
INCLUDE_ASM("asm/nonmatching/code_080043A8", team_select_confirm_pick);
INCLUDE_ASM("asm/nonmatching/code_080043A8", battle_play_alert_sound);
INCLUDE_ASM("asm/nonmatching/code_080043A8", check_target_not_in_battle_list);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_08007480);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_0800750C);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_08007540);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_08007584);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_080075AC);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_08007834);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_08007868);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_08007964);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_08007998);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_080079CC);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_08007A04);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_08007BD8);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_08007BFC);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_08007C20);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_08007C4C);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_08007D04);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_08007D28);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_08007DDC);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_08007E38);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_0800801C);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_08008050);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_08008084);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_080080C8);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_080081BC);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_08008200);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_08008234);
