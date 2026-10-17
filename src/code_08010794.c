#include "global.h"

// guess: fades the sprites in from white (state 6 sub 10)
void sub_08010794(void)
{
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    if (gUnk_03000440.unk84 <= 8)
    {
        blend_obj_palettes_to_color_0803F684(0, 32 - gUnk_03000440.unk84 * 4, 0xFFFF);
        blend_obj_palettes_to_color_0803F998(0, 32 - gUnk_03000440.unk84 * 4, 0xFFFF);
        gUnk_03000440.unk84++;
    }
    else
        gGameSubState++;
}

void prebattle_open_text_window(void)
{
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    text_window_init(1, 0, 0);
    gGameSubState++;
}

void prebattle_show_opponent_line(void)
{
    update_scroll_movement_a();
    if (run_message(gUnk_083C2BBC[gUnk_03001800.unk0]))
    {
        update_all_battle_sprite_orbits();
        gUnk_03000440.unk84 = 8;
        gUnk_03000440.unk85 = 8;
        gGameSubState++;
    }
    update_all_battle_sprite_orbits();
}

// START (with a Rubberobo Medal, item 50, outside debug battles) asks to use it; A starts the battle
void prebattle_wait_for_start_input(void)
{
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    if ((KEYS_LO(gNewKeys) & 8) && get_item_quantity_by_id(50) && gUnk_030057E0.unkC2D == 0)
    {
        play_sound_effect(4);
        gGameSubState++;
    }
    else if (KEYS_LO(gNewKeys) & 1)
    {
        play_sound_effect(4);
        gGameSubState = 32;
    }
}

void sub_080108D0(void)
{
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    if (game_state_execute_handler_a())
    {
        text_window_init(1, 2, 0);
        gGameSubState++;
    }
}

void prebattle_rubberobo_ask(void)
{
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    if (run_message(gUnk_083B53F8[20]))
    {
        open_choice_menu(1, 22, 7);
        gGameSubState++;
    }
}

void prebattle_rubberobo_choice(void)
{
    u32 r;

    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    r = poll_choice_menu();
    if (r)
    {
        if ((r >> 4) == 0)
        {
            sub_0803FB0C();
            gGameSubState++;
        }
        else
            gGameSubState = 32;
    }
}

void prebattle_rubberobo_use(void)
{
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    if (run_message(gUnk_083B53F8[21]))
    {
        sound_stop_all_with_fade_guard(8);
        sub_08042318(50, 1);
        gGameSubState++;
    }
}

void sub_080109A0(void)
{
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    copy_obj_palette_to_buffer();
    gUnk_03000440.unk84 = 0;
    gGameSubState++;
}

void sub_080109CC(void)
{
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    if (gUnk_03000440.unk84 <= 8)
    {
        blend_obj_palettes_to_color_0803F684(0, gUnk_03000440.unk84 * 4, 0xFFFF);
        blend_obj_palettes_to_color_0803F998(0, gUnk_03000440.unk84 * 4, 0xFFFF);
        gUnk_03000440.unk84++;
    }
    else
        gGameSubState++;
}

void sub_08010A20(void)
{
    set_blend_effect_mode(0, 0, 0);
    vram_fill_tilemap_rect(32, 32, 0, 0, REG_BG0CNT, 0);
    vram_fill_tilemap_rect(32, 32, 0, 0, REG_BG1CNT, 0);
    clear_battle_sprite_slot(0, 0x80);
    gGameSubState++;
}

void sub_08010A7C(void)
{
    update_battle_field_frame();
    sub_080487E4();
    setup_blend_effect(0x40, 0x2F00, 5, 16, 16, 16, 12, 10, 0);
    gUnk_03000440.unk84 = 0;
    gGameSubState++;
}

void sub_08010AC8(void)
{
    if (gUnk_03000440.unk84 <= 16)
    {
        blend_effect_update();
        blend_obj_palettes_to_color_0803F684(0, 32 - gUnk_03000440.unk84 * 2, 0xFFFF);
        blend_obj_palettes_to_color_0803F998(0, 32 - gUnk_03000440.unk84 * 2, 0xFFFF);
        gUnk_03000440.unk84++;
    }
    else
    {
        gVBlankCallback = nullsub_08000840;
        sub_08044094();
    }
}

void sub_08010B24(void)
{
    sub_0803F624(&gUnk_03000440.unk50, 0x14, 0);
    gUnk_03000440.unk50 = 2;
    gGameState = 3;
    gGameSubState = 0;
}

void sub_08010B54(void)
{
    sub_0801BF64(&gUnk_03002B84[0], 9999);
    if (gUnk_03000440.unk9C == 1)
    {
        sub_0801BF64(&gUnk_03002B84[1], 9999);
        play_song(14);
    }
    else
        play_song(15);
    gGameSubState++;
}

void sub_08010BA0(void)
{
    update_scroll_movement_a();
    if (gUnk_03000440.unk9C == 1)
        gGameSubState++;
    else
        gGameSubState = 0x70;
}

void sub_08010BD0(void)
{
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    if (run_message(gUnk_083C3984[gUnk_03001800.unk0]) && (KEYS_LO(gNewKeys) & 3))
    {
        gUnk_03000440.unk1B = 0;
        play_sound_effect(13);
        gGameSubState++;
    }
}

void sub_08010C28(void)
{
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    if (game_state_execute_handler_b())
    {
        sub_0803FB0C();
        gGameSubState++;
    }
}

void sub_08010C50(void)
{
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    if (gUnk_030057E0.unkC2E & 0xF)
    {
        gUnk_030057E0.unkC2E = 0;
        gGameSubState = 62;
    }
    else
    {
        sub_080121CC();
        if (sub_08042114(gUnk_03001800.unk169, gUnk_03001800.unk168))
            gUnk_03001800.unk16A = 0;
        else
            gUnk_03001800.unk16A = 1;
        medapart_add_quantity(gUnk_03001800.unk169, gUnk_03001800.unk168, 1);
        gGameSubState++;
    }
}

void sub_08010CE8(void)
{
    const u32 *tbl;

    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    setup_battle_result_sprite_animation();
    memcpy_bytes_0803F63C(gUnk_083C6DE8[gUnk_03001800.unk168], gUnk_03000440.unk9E, 14);
    tbl = gUnk_083BB9CC[0];
    memcpy_bytes_0803F63C((const void *)tbl[gUnk_03001800.unk169 * 4 + gUnk_03001800.unk168], gUnk_03000440.unk9E + 20, 15);
    gGameSubState++;
}

void sub_08010D58(void)
{
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    setup_battle_result_sprite();
    if (run_message(gUnk_083C65C4[107]))
    {
        if (gUnk_03001800.unk16A)
            gGameSubState++;
        else
            gGameSubState = 60;
    }
}

void sub_08010DAC(void)
{
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    setup_battle_result_sprite();
    lz_decompress_dispatch(gUnk_084D7C9C, (void *)0x06012400);
    DmaSet(3, gUnk_0850E9D8, 0x05000340, 0x84000008);
    gUnk_03002C30[1].unk0 = 0xC624;
    gUnk_03002C30[1].unk1C = 0;
    gUnk_03002C30[1].unk2 = 0xC0;
    gUnk_03002C30[1].unk4 = 0x60;
    gUnk_03002C30[1].unkA = 10;
    gUnk_03002C30[1].unkB = 0xC0;
    gUnk_03002C30[1].unk6 = 0x5900;
    gUnk_03002C30[1].unk9 = 0x40;
    gUnk_03002C30[1].unk8 = 0x40;
    gUnk_03002C30[1].unk23 = 0;
    gUnk_03002C30[1].unk28 = 0;
    play_sound_effect(0x2A);
    gGameSubState++;
}

void sub_08010E50(void)
{
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    setup_battle_result_sprite();
    if (advance_sprite_anim_frame(1, 0))
        gGameSubState++;
}

void sub_08010E7C(void)
{
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    setup_battle_result_sprite();
    sub_08012468();
    lz_decompress_dispatch(gUnk_084D7DB0, (void *)0x06016C00);
    DmaSet(3, gUnk_084E2F98, 0x05000360, 0x84000008);
    gUnk_03002C30[2].unk0 = 0xC404;
    gUnk_03002C30[2].unk1C = 0;
    gUnk_03002C30[2].unk2 = 8;
    gUnk_03002C30[2].unk4 = 0x50;
    gUnk_03002C30[2].unkA = 11;
    gUnk_03002C30[2].unkB = 0xC0;
    gUnk_03002C30[2].unk6 = 0x5A00;
    gGameSubState++;
}

void sub_08010F08(void)
{
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    setup_battle_result_sprite();
    sub_08012468();
    if (KEYS_LO(gNewKeys) & 3)
    {
        clear_battle_sprite_slot(1, 2);
        gUnk_03000430 = 0;
        play_sound_effect(13);
        gGameSubState++;
    }
    else if (KEYS_LO(gNewKeys) & 8)
    {
        play_sound_effect(4);
        gGameSubState = 0x60;
    }
}

void sub_08010F6C(void)
{
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    if (gUnk_03001800.unk1)
    {
        sub_0803FB0C();
        gGameSubState++;
    }
    else
        gGameSubState = 0x40;
}

void sub_08010FA4(void)
{
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    if (run_message(gUnk_083C65C4[118]))
    {
        sub_080422B8(50, 1);
        gGameSubState++;
    }
}

void sub_08010FDC(void)
{
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    calculate_battle_score_summary();
    divide_by_100000_b(gUnk_03000440.unk9E, gUnk_03001800.unk16C, 0x35);
    sub_0803FB0C();
    gGameSubState++;
}

void sub_08011018(void)
{
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    if (run_message(gUnk_083C65C4[109]))
        gGameSubState++;
}

void sub_08011048(void)
{
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    battle_check_medal_level_up();
    gUnk_03001800.unk186 = 0;
    gGameSubState++;
}

INCLUDE_ASM("asm/nonmatching/code_08010794", sub_08011078);
INCLUDE_ASM("asm/nonmatching/code_08010794", sub_080110FC);
INCLUDE_ASM("asm/nonmatching/code_08010794", sub_0801112C);
INCLUDE_ASM("asm/nonmatching/code_08010794", sub_08011158);
INCLUDE_ASM("asm/nonmatching/code_08010794", sub_0801120C);
INCLUDE_ASM("asm/nonmatching/code_08010794", sub_0801123C);
INCLUDE_ASM("asm/nonmatching/code_08010794", sub_08011268);
INCLUDE_ASM("asm/nonmatching/code_08010794", sub_080112C4);
INCLUDE_ASM("asm/nonmatching/code_08010794", sub_080112F0);
INCLUDE_ASM("asm/nonmatching/code_08010794", sub_08011344);
INCLUDE_ASM("asm/nonmatching/code_08010794", sub_08011490);
INCLUDE_ASM("asm/nonmatching/code_08010794", sub_080114E0);
INCLUDE_ASM("asm/nonmatching/code_08010794", sub_08011500);
INCLUDE_ASM("asm/nonmatching/code_08010794", sub_080115B4);
INCLUDE_ASM("asm/nonmatching/code_08010794", sub_080115E8);
INCLUDE_ASM("asm/nonmatching/code_08010794", sub_08011644);
INCLUDE_ASM("asm/nonmatching/code_08010794", sub_080116C4);
INCLUDE_ASM("asm/nonmatching/code_08010794", sub_08011764);
INCLUDE_ASM("asm/nonmatching/code_08010794", sub_08011A58);
INCLUDE_ASM("asm/nonmatching/code_08010794", sub_08011ABC);
INCLUDE_ASM("asm/nonmatching/code_08010794", sub_08011ADC);
INCLUDE_ASM("asm/nonmatching/code_08010794", sub_08011B18);
INCLUDE_ASM("asm/nonmatching/code_08010794", sub_08011B5C);
INCLUDE_ASM("asm/nonmatching/code_08010794", sub_08011BB8);
INCLUDE_ASM("asm/nonmatching/code_08010794", battle_loss_take_part);
INCLUDE_ASM("asm/nonmatching/code_08010794", sub_08011CFC);
INCLUDE_ASM("asm/nonmatching/code_08010794", sub_08011D50);
INCLUDE_ASM("asm/nonmatching/code_08010794", sub_08011D80);
INCLUDE_ASM("asm/nonmatching/code_08010794", load_encounter_into_battle_setup);
INCLUDE_ASM("asm/nonmatching/code_08010794", sub_08011DE4);
INCLUDE_ASM("asm/nonmatching/code_08010794", setup_random_encounter_enemies);
INCLUDE_ASM("asm/nonmatching/code_08010794", sub_08011F20);
INCLUDE_ASM("asm/nonmatching/code_08010794", sub_08011F50);
INCLUDE_ASM("asm/nonmatching/code_08010794", sub_08011FA0);
INCLUDE_ASM("asm/nonmatching/code_08010794", sub_08011FEC);
INCLUDE_ASM("asm/nonmatching/code_08010794", sub_08012024);
INCLUDE_ASM("asm/nonmatching/code_08010794", update_all_battle_sprite_orbits);
INCLUDE_ASM("asm/nonmatching/code_08010794", sub_080120C8);
INCLUDE_ASM("asm/nonmatching/code_08010794", sub_0801214C);
INCLUDE_ASM("asm/nonmatching/code_08010794", sub_080121A8);
INCLUDE_ASM("asm/nonmatching/code_08010794", sub_080121CC);
INCLUDE_ASM("asm/nonmatching/code_08010794", sub_080121F0);
INCLUDE_ASM("asm/nonmatching/code_08010794", sub_08012234);
INCLUDE_ASM("asm/nonmatching/code_08010794", sub_080122F4);
INCLUDE_ASM("asm/nonmatching/code_08010794", setup_battle_result_sprite);
INCLUDE_ASM("asm/nonmatching/code_08010794", sub_08012468);
INCLUDE_ASM("asm/nonmatching/code_08010794", setup_battle_result_sprite_animation);
INCLUDE_ASM("asm/nonmatching/code_08010794", calculate_battle_score_summary);
INCLUDE_ASM("asm/nonmatching/code_08010794", calc_average_bot_stat_080125B4);
INCLUDE_ASM("asm/nonmatching/code_08010794", accumulate_alive_bot_score);
INCLUDE_ASM("asm/nonmatching/code_08010794", calc_average_bot_stat_0801264C);
INCLUDE_ASM("asm/nonmatching/code_08010794", calc_medaforce_gauge_from_damage);
INCLUDE_ASM("asm/nonmatching/code_08010794", sub_0801275C);
INCLUDE_ASM("asm/nonmatching/code_08010794", accumulate_team_armor_stats);
INCLUDE_ASM("asm/nonmatching/code_08010794", battle_check_medal_level_up);
INCLUDE_ASM("asm/nonmatching/code_08010794", dispatch_battle_phase_with_fade_check);
INCLUDE_ASM("asm/nonmatching/code_08010794", battle_init_phase);
INCLUDE_ASM("asm/nonmatching/code_08010794", battle_scene_init_state_machine);
INCLUDE_ASM("asm/nonmatching/code_08010794", fade_obj_palettes_to_white_step);
INCLUDE_ASM("asm/nonmatching/code_08010794", sub_08012B94);
INCLUDE_ASM("asm/nonmatching/code_08010794", sub_08012BC0);
INCLUDE_ASM("asm/nonmatching/code_08010794", sub_08012BE4);
INCLUDE_ASM("asm/nonmatching/code_08010794", sub_08012C0C);
INCLUDE_ASM("asm/nonmatching/code_08010794", sub_08012C64);
INCLUDE_ASM("asm/nonmatching/code_08010794", sub_08012D98);
INCLUDE_ASM("asm/nonmatching/code_08010794", sub_08012DF4);
INCLUDE_ASM("asm/nonmatching/code_08010794", sub_08012E40);
INCLUDE_ASM("asm/nonmatching/code_08010794", sub_08012EA8);
INCLUDE_ASM("asm/nonmatching/code_08010794", sub_08012F00);
INCLUDE_ASM("asm/nonmatching/code_08010794", sub_08012FF8);
INCLUDE_ASM("asm/nonmatching/code_08010794", sub_0801303C);
INCLUDE_ASM("asm/nonmatching/code_08010794", sub_080130D8);
INCLUDE_ASM("asm/nonmatching/code_08010794", sub_08013164);
INCLUDE_ASM("asm/nonmatching/code_08010794", sub_08013228);
INCLUDE_ASM("asm/nonmatching/code_08010794", sub_08013288);
INCLUDE_ASM("asm/nonmatching/code_08010794", sub_08013330);
INCLUDE_ASM("asm/nonmatching/code_08010794", sub_080133B8);
INCLUDE_ASM("asm/nonmatching/code_08010794", sub_08013438);
INCLUDE_ASM("asm/nonmatching/code_08010794", sub_08013508);
INCLUDE_ASM("asm/nonmatching/code_08010794", sub_08013568);
INCLUDE_ASM("asm/nonmatching/code_08010794", sub_08013614);
INCLUDE_ASM("asm/nonmatching/code_08010794", sub_08013650);
INCLUDE_ASM("asm/nonmatching/code_08010794", sub_080136B0);
INCLUDE_ASM("asm/nonmatching/code_08010794", sub_080136E8);
INCLUDE_ASM("asm/nonmatching/code_08010794", sub_0801372C);
INCLUDE_ASM("asm/nonmatching/code_08010794", sub_08013798);
INCLUDE_ASM("asm/nonmatching/code_08010794", sub_08013824);
INCLUDE_ASM("asm/nonmatching/code_08010794", battle_phase_dispatch_0801387C);
INCLUDE_ASM("asm/nonmatching/code_08010794", sub_08013A74);
INCLUDE_ASM("asm/nonmatching/code_08010794", sub_08013AE4);
INCLUDE_ASM("asm/nonmatching/code_08010794", sub_08013B8C);
INCLUDE_ASM("asm/nonmatching/code_08010794", sub_08013DE4);
INCLUDE_ASM("asm/nonmatching/code_08010794", sub_08013E30);
INCLUDE_ASM("asm/nonmatching/code_08010794", sub_08013FA8);
INCLUDE_ASM("asm/nonmatching/code_08010794", sub_08014050);
INCLUDE_ASM("asm/nonmatching/code_08010794", sub_080140B0);
INCLUDE_ASM("asm/nonmatching/code_08010794", sub_0801425C);
INCLUDE_ASM("asm/nonmatching/code_08010794", sub_0801427C);
INCLUDE_ASM("asm/nonmatching/code_08010794", sub_08014314);
INCLUDE_ASM("asm/nonmatching/code_08010794", sub_080143A0);
INCLUDE_ASM("asm/nonmatching/code_08010794", sub_08014404);
INCLUDE_ASM("asm/nonmatching/code_08010794", sub_08014548);
INCLUDE_ASM("asm/nonmatching/code_08010794", sub_080145BC);
INCLUDE_ASM("asm/nonmatching/code_08010794", sub_08014634);
INCLUDE_ASM("asm/nonmatching/code_08010794", sub_080146DC);
INCLUDE_ASM("asm/nonmatching/code_08010794", sub_08014754);
