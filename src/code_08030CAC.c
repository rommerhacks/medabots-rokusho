#include "global.h"

void sub_08030CAC(void)
{
    CpuFastSet(gUnk_084E2EF8, (void *)0x05000300, 8);
    CpuFastSet(gUnk_084E2F18, (void *)0x05000320, 8);
    CpuFastSet(gUnk_084E2F38, (void *)0x05000340, 8);
    gGameState = 7;
    gGameSubState = 0x46;
}

void sub_08030CFC(void)
{
    if (gUnk_03000590[gUnk_03001800.unk87].unkC1 == 0x50)
        gGameSubState++;
    else
    {
        sub_0801AEB4();
        gGameSubState = 0x14;
    }
}

void sub_08030D3C(void)
{
    if (sub_0801C154())
        gGameSubState++;
}

void sub_08030D58(void)
{
    if (sub_0801C0BC(0))
        gGameSubState++;
}

void sub_08030D74(void)
{
    if (dispatch_battle_action_substate(0))
        gGameSubState++;
}

void sub_08030D90(void)
{
    dispatch_battle_action_substate(0);
    if (sub_0801C0BC(1))
        gGameSubState++;
}

void sub_08030DB4(void)
{
    dispatch_battle_action_substate(0);
    play_sound_effect(0x51);
    if (gUnk_03000590[gUnk_03001800.unk87].unkC0 & 8)
        gUnk_03001800.unk51 = 0x50;
    else
        gUnk_03001800.unk51 = 0x28;
    sub_0801B004(gUnk_03001800.unk87);
    gGameSubState++;
}

void sub_08030E14(void)
{
    u32 done;

    dispatch_battle_action_substate(0);
    done = medaforce_gauge_fill_step(gUnk_03001800.unk87);
    done += sub_0801B0E8(gUnk_03001800.unk87);
    if (done == 2)
    {
        clear_battle_ui_tilemaps();
        sub_0801AEB4();
        gGameSubState++;
    }
}

void sub_08030E54(void)
{
    if (sub_0801C0BC(gUnk_03001800.unkA6))
        gGameSubState++;
}

void sub_08030E78(void)
{
    lz_decompress_dispatch(gUnk_084C6A98, (void *)0x06017400);
    increment_medal_skill_level(gUnk_03001800.unk87);
    sub_0801B274(gUnk_03001800.unk87);
    gUnk_03000440.unk9C = 0;
    if (gUnk_03000590[0].unk40 == 0)
    {
        gUnk_03000440.unk9C = 2;
        sound_stop_all_with_fade_guard(4);
        play_sound_effect(0x6F);
        gGameSubState++;
    }
    else if (gUnk_03000590[3].unk40 == 0)
    {
        gUnk_03000440.unk9C = 1;
        sound_stop_all_with_fade_guard(4);
        play_sound_effect(0x6F);
        gGameSubState++;
    }
    else
        gGameSubState = 0x48;
}

void sub_08030F10(void)
{
    lz_decompress_dispatch(gUnk_084C84E4, (void *)0x06014800);
    CpuFastSet(gUnk_084E2FD8, (void *)0x050003E0, 8);
    gUnk_03002C30[0x21].unk0 = 0xC624;
    gUnk_03002C30[0x21].unk1C = 0;
    gUnk_03002C30[0x21].unk2 = 0x78;
    gUnk_03002C30[0x21].unk4 = 0x40;
    gUnk_03002C30[0x21].unkA = 0xF;
    gUnk_03002C30[0x21].unkB = 0xC0;
    gUnk_03002C30[0x21].unk6 = 0x902;
    gUnk_03002C30[0x21].unk9 = 0x80;
    gUnk_03002C30[0x21].unk8 = 0x40;
    gGameSubState++;
}

void sub_08030FB4(void)
{
    if (gUnk_03002C30[0x21].unk9 == 0x40)
    {
        gUnk_03000440.unk86 = 0;
        gGameSubState++;
    }
    else
        gUnk_03002C30[0x21].unk9 -= 8;
}

void sub_08030FEC(void)
{
    if (gUnk_03000440.unk86 == 0x5A)
    {
        if (gUnk_03002C30[0x21].unk9 == 8)
        {
            play_song(0x1C);
            clear_battle_sprite_slot(0x21, 1);
            text_window_init(1, 2, 0);
            gGameSubState++;
        }
        else
            gUnk_03002C30[0x21].unk9 -= 8;
    }
    else
        gUnk_03000440.unk86++;
}

void sub_08031048(void)
{
    if (gUnk_03000440.unk86 == 0x5A)
    {
        if (gUnk_03002C30[0x21].unk9 == 8)
        {
            clear_battle_sprite_slot(0x21, 1);
            text_window_init(1, 2, 0);
            gGameSubState++;
        }
        else
            gUnk_03002C30[0x21].unk9 -= 8;
    }
    else
        gUnk_03000440.unk86++;
}

void sub_080310A0(void)
{
    if (gUnk_03000440.unk9C == 1)
        memcpy_bytes_0803F63C(gUnk_03002B74, gUnk_03000440.unk9E, 0xE);
    else if (gUnk_03000440.unk89 != 1)
        memcpy_bytes_0803F63C(gUnk_083C3F38[gUnk_03001800.unk0], gUnk_03000440.unk9E, 0x12);
    else
        memcpy_bytes_0803F63C(gUnk_0300198A, gUnk_03000440.unk9E, 0x12);
    if (run_message(gUnk_083C65C4[2]))
        gGameSubState++;
}

void sub_08031120(void)
{
    if (gUnk_03001800.unk57)
    {
        if (gUnk_03001800.unk165)
            gGameSubState = 0x60;
        else
            gGameSubState = 0x4F;
    }
    else
    {
        robattle_judge_time_up();
        play_song(0x11);
        gGameSubState++;
    }
}

void sub_08031174(void)
{
    lz_decompress_dispatch(gUnk_084C84E4, (void *)0x06014800);
    CpuFastSet(gUnk_084E2FD8, (void *)0x050003E0, 8);
    gUnk_03002C30[0x21].unk0 = 0xC624;
    gUnk_03002C30[0x21].unk1C = 0;
    gUnk_03002C30[0x21].unk2 = 0x78;
    gUnk_03002C30[0x21].unk4 = 0x40;
    gUnk_03002C30[0x21].unkA = 0xF;
    gUnk_03002C30[0x21].unkB = 0xC0;
    gUnk_03002C30[0x21].unk6 = 0x903;
    gUnk_03002C30[0x21].unk9 = 0x80;
    gUnk_03002C30[0x21].unk8 = 0x40;
    gGameSubState++;
}

void sub_08031218(void)
{
    if (gUnk_03000440.unk9C == 1)
        memcpy_bytes_0803F63C(gUnk_03002B74, gUnk_03000440.unk9E, 0xE);
    else if (gUnk_03000440.unk89 != 1)
        memcpy_bytes_0803F63C(gUnk_083C3F38[gUnk_03001800.unk0], gUnk_03000440.unk9E, 0x12);
    else
        memcpy_bytes_0803F63C(gUnk_0300198A, gUnk_03000440.unk9E, 0x12);
    if (run_message(gUnk_083C65C4[3]))
        gGameSubState++;
}

void sub_08031298(void)
{
    if (gUnk_03000440.unk89 != 1)
    {
        sound_stop_all_with_fade_guard(8);
        gGameSubState++;
    }
    else
        gGameSubState = 0x58;
}

void sub_080312CC(void)
{
    copy_obj_palette_to_buffer();
    gUnk_03000440.unk84 = 0;
    gGameSubState++;
}

void sub_080312F0(void)
{
    if (gUnk_03000440.unk84 <= 8)
    {
        blend_obj_palettes_to_color_0803F684(0, gUnk_03000440.unk84 * 4, 0xFFFF);
        blend_obj_palettes_to_color_0803F998(0, gUnk_03000440.unk84 * 4, 0xFFFF);
        gUnk_03000440.unk84++;
    }
    else
        gGameSubState++;
}

void sub_0803133C(void)
{
    gVBlankCallback = nullsub_08000840;
    gUnk_03000440.unk132 = 1;
    if (gUnk_03000440.unk89 != 1)
    {
        gGameState = 6;
        gGameSubState = 0x30;
    }
    else
    {
        gGameState = 10;
        gGameSubState = 0x20;
    }
}

void sub_08031390(void)
{
    lz_decompress_dispatch(gUnk_084D796C, (void *)0x06014800);
    gUnk_03002C30[0x21].unk0 = 0xC404;
    gUnk_03002C30[0x21].unk1C = 0;
    gUnk_03002C30[0x21].unk2 = gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk2;
    gUnk_03002C30[0x21].unk4 = gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 4;
    gUnk_03002C30[0x21].unkA = 0xC;
    gUnk_03002C30[0x21].unkB = 0x80;
    gUnk_03002C30[0x21].unk6 = 0x5800;
    gUnk_03002C30[0x21].unk23 = 0;
    play_sound_effect(0x2A);
    gGameSubState++;
}

void sub_08031438(void)
{
    if (advance_sprite_anim_frame(0x21, 0))
        gGameSubState++;
}

void sub_08031458(void)
{
    gUnk_03002C30[0x22].unk0 = 0xC404;
    gUnk_03002C30[0x22].unk1C = 0;
    gUnk_03002C30[0x22].unk2 = gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk2 - 0x10;
    gUnk_03002C30[0x22].unk4 = gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk4 + 4;
    gUnk_03002C30[0x22].unkA = gUnk_083AED18[gUnk_03001800.unk166];
    gUnk_03002C30[0x22].unkB = 0x80;
    gUnk_03002C30[0x22].unk6 = 0x5801 + gUnk_03001800.unk166;
    gUnk_03002C30[0x22].unk23 = 0;
    play_sound_effect(0x2A);
    gGameSubState++;
}

void sub_08031518(void)
{
    if (medal_update_exp_progress(0x22, 0))
        gGameSubState++;
}

void sub_08031538(void)
{
    lz_decompress_dispatch(gUnk_084D6BFC, (void *)0x06017E00);
    set_display_digit_type(&gUnk_03000440.unkEE, gUnk_03001800.unk167, 2);
    battle_setup_text_sprites_0801A4F4(&gUnk_03000440.unkEE, gUnk_03001800.unk87, 0x23,
        gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk2 + 0x18,
        gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk4 + 4);
    gUnk_03000440.unk84 = 0;
    gGameSubState++;
}

void sub_080315B0(void)
{
    update_battle_sprite_animations(&gUnk_03000440.unkEE, gUnk_03001800.unk87, 0x23);
    if (++gUnk_03000440.unk84 == 0x78)
    {
        clear_battle_sprite_slot(0x21, 2);
        clear_battle_sprite_slot(gUnk_03001800.unk87 * 4 + 0x23, 4);
        gGameSubState++;
    }
}

void sub_08031608(void)
{
    gGameSubState = 0x4F;
}

void sub_08031614(void)
{
    sub_0801AEB4();
    if (gUnk_03001800.unk58)
    {
        gUnk_03001800.unkA6 = 0x79;
        gGameSubState++;
    }
    else if (gUnk_03001800.unkA7 == 0 && gUnk_03000590[gUnk_03001800.unk87].medal.unk5 <= 9)
    {
        gUnk_03001800.unkA6 = 0x36;
        gGameSubState++;
    }
    else if (gUnk_03001800.unkA7 == 1 && gUnk_03000590[gUnk_03001800.unk87].medal.unk5 <= 0x1D)
    {
        gUnk_03001800.unkA6 = 0x36;
        gGameSubState++;
    }
    else if (gUnk_03001800.unkA7 == 2 && gUnk_03000590[gUnk_03001800.unk87].medal.unk5 <= 0x3B)
    {
        gUnk_03001800.unkA6 = 0x36;
        gGameSubState++;
    }
    else if (gUnk_03000590[gUnk_03001800.unk87].unkC1 != 0x50)
    {
        gUnk_03001800.unkA6 = 0x37;
        gGameSubState++;
    }
    else
        gGameSubState = 0x34;
}

void sub_08031704(void)
{
    dispatch_battle_action_substate(0);
    CpuFastSet(gUnk_084E3018, (void *)0x050002E0, 8);
    gUnk_03002C30[0x21].unk0 = ((gUnk_03001800.unk39[3] + 2) << 10) | 0xC004;
    gUnk_03002C30[0x21].unk1C = 0;
    gUnk_03002C30[0x21].unk2 = gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk2;
    gUnk_03002C30[0x21].unk4 = gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 4;
    gUnk_03002C30[0x21].unkA = 7;
    gUnk_03002C30[0x21].unkB = 0x81;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x4D], 0x21);
    gUnk_03002C30[0x22].unk0 = ((gUnk_03001800.unk39[3] + 2) << 10) | 0xC004;
    gUnk_03002C30[0x22].unk1C = 0;
    gUnk_03002C30[0x22].unk2 = gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk2;
    gUnk_03002C30[0x22].unk4 = gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 4;
    gUnk_03002C30[0x22].unkA = 7;
    gUnk_03002C30[0x22].unkB = gUnk_03001800.unk87 * 4 + 0x59;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x4E], 0x22);
    gUnk_03001800.unk51 = gUnk_03000590[gUnk_03001800.unk87].unkA8[2];
    gGameSubState++;
}

void sub_0803185C(void)
{
    dispatch_battle_action_substate(0);
    medaforce_gauge_drain_step(gUnk_03001800.unk87);
    process_sprite_anim_commands(gUnk_083B5F80[0x4D], 0x21);
    process_sprite_anim_commands(gUnk_083B5F80[0x4E], 0x22);
    if (gUnk_03002C30[0x21].unk22 == 0xFF)
    {
        clear_battle_ui_tilemaps();
        sub_0801AEB4();
        clear_battle_sprite_slot(0x21, 2);
        gGameSubState++;
    }
}

void sub_080318CC(void)
{
    memcpy_bytes_0803F63C((void *)gUnk_083B7338[gUnk_03000590[gUnk_03001800.unk87].unkA8[0]], gUnk_03000440.unk9E, 0x11);
    gUnk_03001800.unkA6 = 0x38;
    gGameSubState++;
}

void battle_start_transition_to_action(void)
{
    gUnk_03001800.unk164 = 1;
    gUnk_03001800.unkA8 = gUnk_03000590[gUnk_03001800.unk87].unkA8[0] + 0x50;
    gUnk_03000590[gUnk_03001800.unk87].unkE0 = 0;
    gUnk_03000590[gUnk_03001800.unk87].unkE1 = 0;
    gGameState = 9;
    gGameSubState = 0;
}

void sub_08031978(void)
{
    text_window_init(1, 0, 0);
    gGameSubState++;
}

void sub_08031994(void)
{
    if (run_message(gUnk_083CF3B0[1]))
        gGameSubState++;
}

void sub_080319B8(void)
{
    if (sub_0803E79C())
    {
        gUnk_03000440.unk86 = 0;
        gGameSubState++;
    }
}

void sub_080319E0(void)
{
    if (gUnk_03000440.unk86 == 8)
        gGameSubState++;
    else
        gUnk_03000440.unk86++;
}

void sub_08031A08(void)
{
    if (game_state_execute_handler_a())
        gGameSubState++;
}

void sub_08031A24(void)
{
    sound_stop_all_with_fade_guard(8);
    gGameSubState = 0x51;
}

INCLUDE_ASM("asm/nonmatching/code_08030CAC", battle_process_all_bot_actions);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", battle_execute_action_selection);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", call_bot_action_handler);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", select_battle_targets_and_actions);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", battle_ai_select_target_defend);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", battle_ai_select_target_jump);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", ai_select_target_enemy_side_ability22_status);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", ai_select_target_enemy_side_ewram_check);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", battle_ai_select_target_ability22_enemy);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", ai_select_target_enemy_side_available_part);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", select_enemy_battle_target);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", select_battle_target_for_bot);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", battle_ai_select_target_ability22_ally);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", battle_ai_select_target_status58);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", select_player_battle_target);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", ai_select_target_player_side_ability22);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", clear_battle_action_selection);

u32 sub_08032FB8(u32 a)
{
    switch (a)
    {
    case 0:
    case 1:
    case 2:
        return 3;
    default:
        return 0;
    }
}

u32 sub_08032FC4(u32 a)
{
    switch (a)
    {
    case 0:
    case 1:
    case 2:
        return 0;
    default:
        return 3;
    }
}

INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08032FD0);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08032FFC);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", select_battle_pending_action);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", rng_lookup_table_value);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", select_random_battle_target);

u32 sub_080330E8(u32 idx)
{
    return get_random_battle_weight_entry(idx);
}

INCLUDE_ASM("asm/nonmatching/code_08030CAC", battle_find_next_active_bot);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08033154);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", clear_ewram_buffer_02023000_b);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_080331F8);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08033224);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08033240);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", find_random_available_part_slot);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_080332B4);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_080332D0);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", begin_battle_action_lookup);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", check_battle_bot_defeated_set_flag);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_080333E4);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08033490);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_080334E0);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08033698);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_080336DC);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08033754);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_080337CC);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08033840);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_080338F4);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08033974);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_080339F4);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08033A10);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08033A2C);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08033A78);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08033A94);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08033AB0);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08033ACC);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08033B7C);

void sub_08033C00(void)
{
    sub_08038BC0();
    sub_08034F08();
}

void sub_08033C10(void)
{
    sub_08038D30();
    sub_08034F08();
}

INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08033C20);

void sub_08033CD0(void)
{
    battle_begin_action_phase();
    sub_08034F08();
}

void sub_08033CE0(void)
{
    sub_08039188();
    sub_08034F08();
}

void sub_08033CF0(void)
{
    sub_080391C4();
    sub_08034F08();
}

void sub_08033D00(void)
{
    sub_080392D8();
    sub_08034F08();
}

INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08033D10);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08033D30);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08033F04);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08033F64);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08033F9C);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08034008);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_0803402C);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08034048);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08034074);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08034120);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08034170);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_080341C0);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08034200);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08034240);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_0803426C);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08034288);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_080342C8);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_080342E4);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08034300);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_0803431C);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_0803435C);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08034378);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_080343B8);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_080343D4);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_080343F0);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_0803440C);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08034428);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08034444);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08034460);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_0803447C);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08034498);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_080344B4);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_080344D0);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_080344EC);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08034508);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08034524);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08034540);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_0803455C);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08034578);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08034594);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_080345B0);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_080345CC);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_080345E8);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08034628);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08034644);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08034684);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_080346C4);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08034708);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08034728);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_0803476C);

void sub_080347AC(void)
{
    sub_08036270();
    sub_08034F08();
}

INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_080347BC);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_080347F8);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_080348D0);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08034910);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_0803496C);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_080349D8);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08034A68);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08034AA0);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08034AF4);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08034B68);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08034BA0);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08034BBC);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08034BD8);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08034BF4);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08034C10);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08034C2C);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08034C48);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08034C64);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08034C80);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08034C9C);
