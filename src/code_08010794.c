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

// guess: Rubberobo Medal used: fade to white, then skip the battle
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

// A on the pre-battle screen: Medabots screen in team select mode (game state 3, unk50 = 2)
void prebattle_open_team_select(void)
{
    sub_0803F624(&gUnk_03000440.unk50, 0x14, 0);
    gUnk_03000440.unk50 = 2;
    gGameState = 3;
    gGameSubState = 0;
}

// Game state 6 sub-states 48+ = after the Robattle (runtime-checked from a debug battle,
// re/scratch/afterbattle_probe.txt): 53 opponent line, 55-61 Medapart won (START = details),
// 64-65 experience, 66+ Medal level-ups and Medaforces per team member (unk186)
void afterbattle_count_battle(void)
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

void afterbattle_check_won(void)
{
    update_scroll_movement_a();
    if (gUnk_03000440.unk9C == 1)
        gGameSubState++;
    else
        gGameSubState = 0x70;
}

void afterbattle_show_opponent_line(void)
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

void afterbattle_give_part(void)
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

void afterbattle_load_part_name(void)
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

void afterbattle_show_part_acquired(void)
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

// guess: new Medapart: "NEW" sprite (sprite 1, sound 0x2A)
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

void afterbattle_part_details_input(void)
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

void afterbattle_load_experience(void)
{
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    calculate_battle_score_summary();
    divide_by_100000_b(gUnk_03000440.unk9E, gUnk_03001800.unk16C, 0x35);
    sub_0803FB0C();
    gGameSubState++;
}

void afterbattle_show_experience(void)
{
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    if (run_message(gUnk_083C65C4[109]))
        gGameSubState++;
}

void afterbattle_start_medal_level_up(void)
{
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    battle_check_medal_level_up();
    gUnk_03001800.unk186 = 0;
    gGameSubState++;
}

void sub_08011078(void)
{
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    if (gUnk_03001800.unk186 == 3)
    {
        gUnk_03001800.unk186 = 0;
        gGameSubState = 0x47;
    }
    else if (gUnk_03001800.unk16E[gUnk_03001800.unk186][0])
    {
        sub_0803FB0C();
        memcpy_bytes_0803F63C((const void *)gUnk_083B6410[gUnk_03001800.unk16E[gUnk_03001800.unk186][0] - 1], gUnk_03000440.unk9E, 11);
        play_song(16);
        gGameSubState++;
    }
    else
        gUnk_03001800.unk186++;
}

void sub_080110FC(void)
{
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    if (run_message(gUnk_083C65C4[119]))
        gGameSubState++;
}

void sub_0801112C(void)
{
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    gUnk_03001800.unk186++;
    gGameSubState = 0x43;
}

void sub_08011158(void)
{
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    if (gUnk_03001800.unk186 == 3)
    {
        gUnk_03001800.unk186 = 0;
        gGameSubState = 0x4B;
    }
    else if (gUnk_03001800.unk16E[gUnk_03001800.unk186][6])
    {
        sub_0803FB0C();
        memcpy_bytes_0803F63C((const void *)gUnk_083B6410[gUnk_03001800.unk16E[gUnk_03001800.unk186][0] - 1], gUnk_03000440.unk9E, 11);
        memcpy_bytes_0803F63C((const void *)gUnk_083B7338[gUnk_03001800.unk16E[gUnk_03001800.unk186][7]], gUnk_03000440.unk9E + 20, 17);
        play_song(16);
        gGameSubState++;
    }
    else
        gUnk_03001800.unk186++;
}

void sub_0801120C(void)
{
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    if (run_message(gUnk_083C65C4[120]))
        gGameSubState++;
}

void sub_0801123C(void)
{
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    gUnk_03001800.unk186++;
    gGameSubState = 0x47;
}

void sub_08011268(void)
{
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    if (gUnk_03001800.unk186 == 3)
    {
        gUnk_03001800.unk186 = 0;
        gGameSubState = 0x58;
    }
    else if (gUnk_03001800.unk16E[gUnk_03001800.unk186][1])
        gGameSubState++;
    else
        gUnk_03001800.unk186++;
}

void sub_080112C4(void)
{
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    copy_obj_palette_to_buffer();
    gUnk_03000440.unk84 = 0;
    gGameSubState++;
}

void sub_080112F0(void)
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

void sub_08011344(void)
{
    vu32 zero;

    clear_battle_sprite_slot(0, 0x80);
    sub_08043CA8();
    vram_fill_tilemap_rect(32, 32, 0, 0, REG_BG0CNT, 0);
    vram_fill_tilemap_rect(32, 32, 0, 0, REG_BG1CNT, 0);
    vram_fill_tilemap_rect(32, 32, 0, 0, REG_BG2CNT, 0);
    vram_fill_tilemap_rect(32, 32, 0, 0, REG_BG3CNT, 0);
    set_blend_effect_mode(5, 0x3F, 0x20);
    gVBlankCallback = nullsub_08000840;
    zero = 0;
    DmaSet(3, &zero, 0x05000200, 0x85000080);
    zero = 0;
    DmaSet(3, &zero, 0x05000000, 0x85000080);
    gUnk_03000440.unk133 = find_medal_slot_by_id(gUnk_03001800.unk16E[gUnk_03001800.unk186][0] - 1) - 1;
    gUnk_03000440.unk134 = gUnk_03001800.unk16E[gUnk_03001800.unk186][2];
    gUnk_03000440.unk135 = gUnk_03001800.unk16E[gUnk_03001800.unk186][3];
    gUnk_03000440.unk136 = gUnk_03001800.unk16E[gUnk_03001800.unk186][4];
    gUnk_03000440.unk137 = gUnk_03001800.unk16E[gUnk_03001800.unk186][5];
    sub_08067A48(gUnk_03000440.unk133);
    gUnk_03001800.unk186++;
}

void sub_08011490(void)
{
    if (gUnk_03001800.unk186 == 3)
    {
        gUnk_03001800.unk186 = 0;
        gGameSubState = 0x5B;
    }
    else if (gUnk_03001800.unk16E[gUnk_03001800.unk186][1])
        gGameSubState = 0x4E;
    else
        gUnk_03001800.unk186++;
}

void sub_080114E0(void)
{
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    sound_stop_all_with_fade_guard(8);
    gGameSubState++;
}

void sub_08011500(void)
{
    play_song(1);
    clear_battle_sprite_slot(0, 0x80);
    sub_08043CA8();
    vram_fill_tilemap_rect(32, 32, 0, 0, REG_BG0CNT, 0);
    vram_fill_tilemap_rect(32, 32, 0, 0, REG_BG1CNT, 0);
    vram_fill_tilemap_rect(32, 32, 0, 0, REG_BG2CNT, 0);
    vram_fill_tilemap_rect(32, 32, 0, 0, REG_BG3CNT, 0);
    gUnk_030057E0.unkC2D = 0;
    gUnk_030057E0.unkC2E = 0;
    gUnk_030057E0.unkC2F = 0;
    gVBlankCallback = nullsub_08000840;
    sub_0804765C(0);
}

// Sub-states 0x60-0x67: START on "Medapart was acquired" opens the won part's Medaparts detail page
// (0x62 saves BG tiles and sprites, 0x63 enters game state 5, 0x65 restores the screen on return).
void afterbattle_part_detail_init_fade(void)
{
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    setup_battle_result_sprite();
    sub_08012468();
    copy_obj_palette_to_buffer();
    gUnk_03000440.unk84 = 0;
    gGameSubState++;
}

void afterbattle_part_detail_fade_out(void)
{
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    setup_battle_result_sprite();
    sub_08012468();
    if (gUnk_03000440.unk84 <= 8)
    {
        blend_obj_palettes_to_color_0803F684(0, gUnk_03000440.unk84 * 4, 0xFFFF);
        blend_obj_palettes_to_color_0803F998(0, gUnk_03000440.unk84 * 4, 0xFFFF);
        gUnk_03000440.unk84++;
    }
    else
        gGameSubState++;
}

void afterbattle_part_detail_save_screen(void)
{
    DmaSet(3, 0x06002800, gUnk_02020800, 0x84000200);
    DmaSet(3, 0x06000280, 0x02021000, 0x84000380);
    DmaSet(3, gUnk_03002C30, 0x02028000, 0x84000800);
    set_blend_effect_mode(5, 0x3F, 0x20);
    gVBlankCallback = nullsub_08000840;
    gGameSubState++;
}

INCLUDE_ASM("asm/nonmatching/code_08010794", sub_080116C4);

void afterbattle_part_detail_restore_screen(void)
{
    const u32 *tbl;
    u32 zero;

    sub_08043CA8();
    REG_DISPCNT &= 0xE0FF;
    REG_BG0CNT = 0x500;
    REG_BG1CNT = 0x1801;
    REG_BG2CNT = 0x590A;
    REG_BG3CNT = 0x5B0B;
    vram_fill_tilemap_rect(32, 32, 0, 0, REG_BG0CNT, 0);
    vram_fill_tilemap_rect(32, 32, 0, 0, REG_BG1CNT, 0);
    lz_decompress_dispatch(gUnk_084E6C9C, (void *)0x06004000);
    lz_decompress_dispatch(gUnk_084C48B4, (void *)0x06006000);
    lz_decompress_dispatch(gUnk_084C4A34, (void *)0x06006200);
    lz_decompress_dispatch(gUnk_084C7D10, (void *)0x06012800);
    lz_decompress_dispatch(gUnk_084C6A98, (void *)0x06017400);
    set_tilemap_and_decompress_bg(0, 0, gUnk_084EFA34, REG_BG1CNT, 0x200);
    DmaSet(3, gUnk_084F29E0, 0x0202FA00, 0x84000070);
    DmaSet(3, gUnk_084C69D8, 0x0202FB00, 0x84000008);
    DmaSet(3, gUnk_084C69F8, 0x0202FB20, 0x84000008);
    DmaSet(3, gUnk_0850DEF8, 0x0202F800, 0x84000040);
    DmaSet(3, gUnk_0850DCF8 + 0xB0, 0x0202F980, 0x84000008);
    DmaSet(3, gUnk_0850DCF8, 0x0202F9A0, 0x84000008);
    DmaSet(3, gUnk_084E2FB8, 0x0202F940, 0x84000008);
    DmaSet(3, gUnk_084E2F98, 0x0202F960, 0x84000008);
    decompress_tileset_to_vram(gUnk_03001800.unk38, 1);
    lz_decompress_dispatch(gUnk_084D7C9C, (void *)0x06012400);
    DmaSet(3, gUnk_0850E9D8, 0x0202F940, 0x84000008);
    lz_decompress_dispatch(gUnk_084D7DB0, (void *)0x06016C00);
    DmaSet(3, gUnk_084E2F98, 0x0202F960, 0x84000008);
    zero = 0;
    DmaSet(3, &zero, gUnk_03002C30, 0x85000800);
    DmaSet(3, gUnk_02020800, 0x06002800, 0x84000200);
    DmaSet(3, 0x02021000, 0x06000280, 0x84000380);
    DmaSet(3, 0x02028000, gUnk_03002C30, 0x84000800);
    REG_DISPCNT |= 0x1F60;
    prebattle_draw_opponent_name();
    prebattle_draw_battlefield_name();
    load_opponent_medabot_sprites();
    init_opponent_medabot_sprites();
    draw_opponent_leg_type_icons();
    prebattle_init_rubberobo_sprite();
    sub_080121A8();
    apply_battle_blend_effect_a();
    setup_battle_result_sprite_animation();
    memcpy_bytes_0803F63C(gUnk_083C6DE8[gUnk_03001800.unk168], gUnk_03000440.unk9E, 14);
    tbl = gUnk_083BB9CC[0];
    memcpy_bytes_0803F63C((const void *)tbl[gUnk_03001800.unk169 * 4 + gUnk_03001800.unk168], gUnk_03000440.unk9E + 20, 15);
    gUnk_03000440.unk84 = 0;
    gGameSubState++;
}

void afterbattle_part_detail_fade_in(void)
{
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    setup_battle_result_sprite();
    sub_08012468();
    if (gUnk_03000440.unk84 <= 8)
    {
        blend_obj_palettes_to_color_0803F684(0, 32 - gUnk_03000440.unk84 * 4, 0xFFFF);
        blend_obj_palettes_to_color_0803F998(0, 32 - gUnk_03000440.unk84 * 4, 0xFFFF);
        gUnk_03000440.unk84++;
    }
    else
        gGameSubState++;
}

void afterbattle_part_detail_return(void)
{
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    setup_battle_result_sprite();
    sub_08012468();
    gGameSubState = 0x3D;
}

// Sub-states 0x70+: lost Robattle ("You lost the Robattle").
void afterbattle_show_lost_message(void)
{
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    if (run_message(gUnk_083C65C4[110]))
    {
        gUnk_03000440.unk1B = 0;
        gGameSubState++;
    }
}

// guess: 0x71, waits for a handler, then 0x72 (fade out) if unkC2F else 0x77 (a Medapart is taken)
void sub_08011B18(void)
{
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    if (game_state_execute_handler_b())
    {
        if (gUnk_030057E0.unkC2F)
            gGameSubState++;
        else
            gGameSubState = 0x77;
    }
}

void afterbattle_fade_to_white(void)
{
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    if (gUnk_03000440.unk84 <= 8)
    {
        blend_obj_palettes_to_color_0803F684(0x7FFF, gUnk_03000440.unk84 * 4, 0xFFFF);
        blend_obj_palettes_to_color_0803F998(0x7FFF, gUnk_03000440.unk84 * 4, 0xFFFF);
        gUnk_03000440.unk84++;
    }
    else
        gGameSubState++;
}

void afterbattle_exit_to_field(void)
{
    clear_battle_sprite_slot(0, 0x80);
    sub_08043CA8();
    vram_fill_tilemap_rect(32, 32, 0, 0, REG_BG0CNT, 0);
    vram_fill_tilemap_rect(32, 32, 0, 0, REG_BG1CNT, 0);
    vram_fill_tilemap_rect(32, 32, 0, 0, REG_BG2CNT, 0);
    vram_fill_tilemap_rect(32, 32, 0, 0, REG_BG3CNT, 0);
    gUnk_030057E0.unkC2D = 0;
    gUnk_030057E0.unkC2E = 0;
    gUnk_030057E0.unkC2F = 0;
    gVBlankCallback = nullsub_08000840;
    set_blend_effect_mode(3, 0x3F, 0x20);
    gGameMode = 2;
    gGameState = 8;
    gGameSubState = 0;
}

// 0x77: picks one of the player's parts (sub_080122F4(0): slots 0-2) and removes it (sub_080421B4).
void battle_loss_take_part(void)
{
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    if (gUnk_030057E0.unkC2E & 0xF)
    {
        gUnk_030057E0.unkC2E = 0;
        gGameSubState = 0x40;
    }
    else
    {
        sub_080122F4(0);
        sub_080421B4(gUnk_03000590[gUnk_03001800.unk187].unk47, gUnk_03001800.unk168);
        sub_0803FB0C();
        gGameSubState++;
    }
}

void battle_loss_show_part_taken(void)
{
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    setup_battle_result_sprite();
    if (run_message(gUnk_083C65C4[108]) && (KEYS_LO(gNewKeys) & 3))
    {
        gUnk_03000430 = 0;
        play_sound_effect(13);
        gGameSubState++;
    }
}

// guess: sub_080440B4() nonzero = a Medabot is still assembled
void battle_loss_check_team(void)
{
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    if (sub_080440B4())
        gGameSubState = 0x40;
    else
    {
        sub_0803FB0C();
        gGameSubState++;
    }
}

void battle_loss_show_no_medabots(void)
{
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    if (run_message(gUnk_083C65C4[111]))
        gGameSubState = 0x72;
}

void load_encounter_into_battle_setup(void)
{
    u32 zero = 0;

    DmaSet(3, &zero, &gUnk_03001800, 0x85000100);
    load_area_battlefield();
    setup_random_encounter_enemies();
}

void load_area_battlefield(void)
{
    memcpy_bytes_08041D04(gUnk_083BEA90[gUnk_030057E0.unk7FE], &gUnk_03000440.unkEE, 2);
    gUnk_03001800.unk38 = (&gUnk_03000440.unkEE)[1];
}

// Picks the encounter (area table unless a debug battle set unkC2A), copies its setup and re-rolls
// each opponent part with random_pick_weighted4 unless the setup has fixed parts (unk3).
void setup_random_encounter_enemies(void)
{
    struct Unk_030057E0 *st;
    u8 flag;
    u32 r;
    u8 id;
    u32 i;
    u8 a, b, c, d;

    flag = gUnk_030057E0.unkC2D;
    st = &gUnk_030057E0;
    if (!flag)
    {
        memcpy_bytes_08041D04(gUnk_083BF090[st->unk7FE], &gUnk_03000440.unkEE, 4);
        r = sub_08043C94();
        if (r < 40)
            id = (&gUnk_03000440.unkEE)[0];
        else if (r < 70)
            id = (&gUnk_03000440.unkEE)[1];
        else if (r < 90)
            id = (&gUnk_03000440.unkEE)[2];
        else
            id = (&gUnk_03000440.unkEE)[3];
        st->unkC2A = id;
    }
    memcpy_bytes_08041D04(gUnk_083C1A00[st->unkC2A], &gUnk_03001800, 0x28);
    if (!gUnk_03001800.unk3)
    {
        for (i = 0; i < 3; i++)
        {
            a = random_pick_weighted4(gUnk_03001800.unk4[i].parts[0], gUnk_03001800.unk4[i].parts[1], gUnk_03001800.unk4[i].parts[2], gUnk_03001800.unk4[i].parts[3]);
            b = random_pick_weighted4(gUnk_03001800.unk4[i].parts[0], gUnk_03001800.unk4[i].parts[1], gUnk_03001800.unk4[i].parts[2], gUnk_03001800.unk4[i].parts[3]);
            c = random_pick_weighted4(gUnk_03001800.unk4[i].parts[0], gUnk_03001800.unk4[i].parts[1], gUnk_03001800.unk4[i].parts[2], gUnk_03001800.unk4[i].parts[3]);
            d = random_pick_weighted4(gUnk_03001800.unk4[i].parts[0], gUnk_03001800.unk4[i].parts[1], gUnk_03001800.unk4[i].parts[2], gUnk_03001800.unk4[i].parts[3]);
            gUnk_03001800.unk4[i].parts[0] = a;
            gUnk_03001800.unk4[i].parts[1] = b;
            gUnk_03001800.unk4[i].parts[2] = c;
            gUnk_03001800.unk4[i].parts[3] = d;
        }
    }
}

// Returns a, b, c or d with 40/30/20/10% probability.
u32 random_pick_weighted4(u32 a, u32 b, u32 c, u32 d)
{
    u32 r = sub_08043C94();

    if (r < 40)
        return a;
    if (r < 70)
        return b;
    if (r < 90)
        return c;
    return d;
}

void prebattle_draw_opponent_name(void)
{
    memcpy_bytes_0803F63C(gUnk_083C3F38[gUnk_03001800.unk0], gUnk_03000440.unk9E, 18);
    render_text_sprites_08040EE4(gUnk_03000440.unk9E, 10, 18, 3, 10, 13, 0, 1, 0, -4);
}

void prebattle_draw_battlefield_name(void)
{
    memcpy_bytes_0803F63C(gUnk_083BE9E8[gUnk_03001800.unk38], gUnk_03000440.unk9E, 11);
    render_text_sprites_08040DB8(gUnk_03000440.unk9E, 30, 1, 3, 8, 12, 0, 1);
}

void load_opponent_medabot_sprites(void)
{
    u32 i;

    for (i = 0; i < gUnk_03001800.unk2; i++)
        decompress_sprite_to_vram_08042D94(gUnk_03001800.unk4[i].parts[0], gUnk_03001800.unk4[i].parts[1], gUnk_03001800.unk4[i].parts[2], gUnk_03001800.unk4[i].parts[3], i);
}

void init_opponent_medabot_sprites(void)
{
    u32 i;

    for (i = 0; i < gUnk_03001800.unk2; i++)
    {
        init_battle_medabot_sprites(gUnk_03001800.unk4[i].parts[0], gUnk_03001800.unk4[i].parts[1], gUnk_03001800.unk4[i].parts[2], gUnk_03001800.unk4[i].parts[3],
            i, 40 + i * 4, gUnk_083ACEE4[i][0], gUnk_083ACEE4[i][1], 1, 1, 0);
        battle_sprite_set_palette_index(40 + i * 4, 8);
    }
}

void update_all_battle_sprite_orbits(void)
{
    u32 i;

    for (i = 0; i < gUnk_03001800.unk2; i++)
        update_battle_sprite_orbiting_positions(40 + i * 4, i, 1);
}

void draw_opponent_leg_type_icons(void)
{
    u32 i;

    for (i = 0; i < 3; i++)
    {
        if (gUnk_03001800.unk2 > i)
        {
            load_part_data(gUnk_03001800.unk4[i].parts[3], 3, &gUnk_03000440.unkEE);
            draw_tilemap_with_offset((&gUnk_03000440.unkEE)[1] - 100, gUnk_083ACEEA[i][0], gUnk_083ACEEA[i][1], REG_BG0CNT, 0x8300);
        }
        else
            draw_tilemap_with_offset(0xFF, gUnk_083ACEEA[i][0], gUnk_083ACEEA[i][1], REG_BG0CNT, 0x8300);
    }
}

// Shows sprite 0 when the player owns a Rubberobo Medal (item 50) outside debug battles.
void prebattle_init_rubberobo_sprite(void)
{
    if (!gUnk_03000440.unk132 && get_item_quantity_by_id(50) && !gUnk_030057E0.unkC2D)
    {
        gUnk_03002C30[0].unk0 = 0xC404;
        gUnk_03002C30[0].unk2 = 8;
        gUnk_03002C30[0].unk4 = 0x50;
        gUnk_03002C30[0].unkA = 11;
        gUnk_03002C30[0].unkB = 0xC0;
        gUnk_03002C30[0].unk6 = 0x700;
    }
}

// guess: battlefield parameters
void sub_080121A8(void)
{
    memcpy_bytes_0803F63C(gUnk_083C3B04[gUnk_03001800.unk38], gUnk_03001800.unk39, 8);
}

// guess: chooses the won Medapart: sub_080121F0 (10 per destroyed opponent part) against a 0-100 roll,
// then sub_08012234 (a part the player doesn't own yet), else any opponent part (sub_080122F4(3)).
void sub_080121CC(void)
{
    s32 n = sub_080121F0();

    if (n < sub_08043C94() || !sub_08012234())
        sub_080122F4(3);
}

INCLUDE_ASM("asm/nonmatching/code_08010794", sub_080121F0);
INCLUDE_ASM("asm/nonmatching/code_08010794", sub_08012234);
INCLUDE_ASM("asm/nonmatching/code_08010794", sub_080122F4);

void setup_battle_result_sprite(void)
{
    switch (gUnk_03001800.unk168)
    {
    case 0:
        setup_sprite_animation_entry(0, gUnk_03001800.unk169, 0, 0xC2, 0x50, 1, 8, 0, 1);
        break;
    case 1:
        setup_sprite_animation_entry(0, gUnk_03001800.unk169, 1, 0xCC, 0x38, 1, 7, 0, 1);
        break;
    case 2:
        setup_sprite_animation_entry(0, gUnk_03001800.unk169, 2, 0xB8, 0x38, 1, 6, 1, 1);
        break;
    case 3:
        setup_sprite_animation_entry(0, gUnk_03001800.unk169, 3, 0xC2, 0x2E, 1, 5, 0, 1);
        break;
    }
}

void sub_08012468(void)
{
    if (gUnk_03001800.unk16A)
    {
        if (!gUnk_03002C30[1].unk28)
        {
            if ((u8)(gUnk_03002C30[1].unk9 += 2) == 0x80)
                gUnk_03002C30[1].unk28 = 1;
        }
        else
        {
            if ((u8)(gUnk_03002C30[1].unk9 -= 2) == 0x40)
                gUnk_03002C30[1].unk28 = 0;
        }
    }
}

void setup_battle_result_sprite_animation(void)
{
    init_scene_buffers_080445F4();
    switch (gUnk_03001800.unk168)
    {
    case 0:
        setup_sprite_animation_entry(0, gUnk_03001800.unk169, 0, 0xC2, 0x3C, 1, 8, 0, 0);
        break;
    case 1:
        setup_sprite_animation_entry(0, gUnk_03001800.unk169, 1, 0xCC, 0x28, 1, 7, 0, 0);
        break;
    case 2:
        setup_sprite_animation_entry(0, gUnk_03001800.unk169, 2, 0xB8, 0x28, 1, 6, 1, 0);
        break;
    case 3:
        setup_sprite_animation_entry(0, gUnk_03001800.unk169, 3, 0xC2, 0x1E, 1, 5, 0, 0);
        break;
    }
}

// Experience points for the won Robattle (gUnk_03001800.unk16C), from the opponents' Medal levels,
// their count, the level gap to the team, their parts (guess: broken ones), unk16B and armor.
void calculate_battle_score_summary(void)
{
    gUnk_03001800.unk16C = 0;
    calc_average_bot_stat_080125B4();
    accumulate_alive_bot_score();
    calc_average_bot_stat_0801264C();
    calc_medaforce_gauge_from_damage();
    sub_0801275C();
    accumulate_team_armor_stats();
}

void calc_average_bot_stat_080125B4(void)
{
    u32 sum = 0;
    u32 i;

    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03000590[i + 3].unkBA)
            sum += gUnk_03000590[i + 3].medal.unk5;
    }
    gUnk_03001800.unk16C += sum / 3;
}

void accumulate_alive_bot_score(void)
{
    u32 n = 0;
    u32 i;

    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03000590[i + 3].unkBA)
            n++;
    }
    gUnk_03001800.unk16C += n * 8;
}

void calc_average_bot_stat_0801264C(void)
{
    u32 opp = 0;
    u32 team = 0;
    u32 i;
    u32 nopp;
    u32 nteam;

    for (i = 0, nopp = 0; i <= 2; i++)
    {
        if (gUnk_03000590[i + 3].unkBA)
        {
            opp += gUnk_03000590[i + 3].medal.unk5;
            nopp++;
        }
    }
    opp = opp / nopp;
    for (i = 0, nteam = 0; i <= 2; i++)
    {
        if (gUnk_03000590[i].unkBA)
        {
            team += gUnk_03000590[i].medal.unk5;
            nteam++;
        }
    }
    team = team / nteam;
    if (team < opp)
        gUnk_03001800.unk16C += (opp - team) * (nopp << 4);
}

void calc_medaforce_gauge_from_damage(void)
{
    u32 i;
    u32 score;

    for (i = 0, score = 0; i <= 2; i++)
    {
        if (gUnk_03000590[i + 3].unkBA)
        {
            if (!gUnk_03000590[i + 3].parts[0].unk11)
                score += 8;
            if (!gUnk_03000590[i + 3].parts[1].unk11)
                score += 16;
            if (!gUnk_03000590[i + 3].parts[2].unk11)
                score += 16;
            if (!gUnk_03000590[i + 3].parts[3].unk11)
                score += 16;
        }
    }
    gUnk_03001800.unk16C += score * 2;
}

void sub_0801275C(void)
{
    gUnk_03001800.unk16C += gUnk_03001800.unk16B * 5;
}

void accumulate_team_armor_stats(void)
{
    u32 i;
    u32 sum;

    for (i = 0, sum = 0; i <= 2; i++)
    {
        if (gUnk_03000590[i + 3].unkBA)
        {
            sum += gUnk_03000590[i + 3].parts[0].data[0xA];
            sum += gUnk_03000590[i + 3].parts[1].data[0xA];
            sum += gUnk_03000590[i + 3].parts[2].data[0xA];
            sum += gUnk_03000590[i + 3].parts[3].data[0xA];
        }
    }
    gUnk_03001800.unk16C += sum;
}

void battle_check_medal_level_up(void)
{
    u32 i;
    struct Unk_03000BE0 *medal;
    u32 variant;
    u32 slot;

    sub_0803F624(&gUnk_03001800.unk16E[0][0], 0x18, 0);
    for (i = 0; i <= 2; i++)
    {
        if (!gUnk_03000590[i].unkBA)
            continue;
        slot = find_medal_slot_by_id(gUnk_03000590[i].medal.unk1) - 1;
        {
            struct Unk_03000BE0 *medals = gUnk_03000BE0;
            medal = &medals[slot];
        }
        if (medal->unk5 == 100)
            continue;
        if (medal->unk2 > gUnk_03001800.unk16C)
        {
            medal->unk2 -= gUnk_03001800.unk16C;
            continue;
        }
        medal->unk5++;
        medal->unk2 = (medal->unk5 + 1) * 100;
        gUnk_03001800.unk16E[i][0] = medal->unk1 + 1;
        memcpy_bytes_08041D04(gUnk_083B6158[medal->unk1], &gUnk_03000440.unkEE, 16);
        variant = sub_080420C4(medal->unk5, (&gUnk_03000440.unkEE)[3], (&gUnk_03000440.unkEE)[4],
                               (&gUnk_03000440.unkEE)[5], (&gUnk_03000440.unkEE)[6]);
        if (variant != medal->unk8)
        {
            gUnk_03001800.unk16E[i][1] = 1;
            gUnk_03001800.unk16E[i][2] = medal->unk1;
            gUnk_03001800.unk16E[i][3] = medal->unk8;
            gUnk_03001800.unk16E[i][4] = medal->unk1;
            gUnk_03001800.unk16E[i][5] = variant;
            medal->unk8 = variant;
        }
        memcpy_bytes_08041D04(&gUnk_083B7E0C[medal->unk1 * 3], &gUnk_03000440.unkEE, 3);
        if (medal->unk5 == 10)
        {
            gUnk_03001800.unk16E[i][6] = 1;
            gUnk_03001800.unk16E[i][7] = (&gUnk_03000440.unkEE)[0];
        }
        if (medal->unk5 == 30)
        {
            gUnk_03001800.unk16E[i][6] = 1;
            gUnk_03001800.unk16E[i][7] = (&gUnk_03000440.unkEE)[1];
        }
        if (medal->unk5 == 60)
        {
            gUnk_03001800.unk16E[i][6] = 1;
            gUnk_03001800.unk16E[i][7] = (&gUnk_03000440.unkEE)[2];
        }
    }
}

// Game state 7 = Robattle (gGameStateHandlers_083AC148[7]); sub-states in gRobattleHandlers.
void robattle_update(void)
{
    u32 fill;

    if (sub_0803EED8())
        return;
    if (gUnk_03000430 == 2)
    {
        fill = 0x200;
        CpuFastSet(&fill, gUnk_03002414->unkB84, 0x01000100);
    }
    gRobattleHandlers[gGameSubState]();
}

void battle_init_phase(void)
{
    gUnk_03000440.unk139 = 0;
    gUnk_03000440.unk13A = 0;
    if (gUnk_03000440.unk89 != 1)
    {
        clear_battle_bot_array();
        count_active_battle_bots();
        battle_setup_team_bots();
        init_opponent_bots();
    }
    battle_process_all_bots_actions();
    if (gUnk_03000440.unk89 != 1)
        sub_08018A18();
    gGameSubState++;
}

void battle_scene_init_state_machine(void)
{
    u32 fill;

    switch (gUnk_03000440.unk139)
    {
        case 0:
            sub_08043CA8();
            load_battle_script_entry_b();
            REG_DISPCNT &= 0xF0FF;
            REG_BG0CNT = 0x500;
            REG_BG1CNT = 0x1901;
            REG_BG2CNT = 0x1A0A;
            REG_BG3CNT = 0x1B0B;
            if (battle_phase_dispatch_0801A788(0))
                gUnk_03000440.unk139++;
            break;
        case 1:
            gUnk_03000440.unk84 = 0;
            fill = 0;
            CpuFastSet(&fill, gUnk_03002C30, 0x01000800);
            REG_DISPCNT |= 0x1F40;
            REG_DISPCNT &= 0xFFDF;
            gUnk_03000440.unk139++;
            break;
        case 2:
            load_bg3_tilemap_08488764();
            draw_battle_bot_portraits();
            load_all_bot_part_sprites();
            setup_all_battle_bot_sprite_positions();
            init_battle_bot_sprites();
            apply_battle_blend_effect_b();
            decompress_to_ewram_27000((const u8 *)gUnk_083B24A8[gUnk_03001800.unk38 * 5 + 1]);
            gVBlankCallback = sub_08044100;
            gGameSubState++;
            gUnk_03000440.unk139 = 0;
            break;
    }
}

void robattle_fade_in_from_white(void)
{
    if (gUnk_03000440.unk84 <= 8)
    {
        blend_obj_palettes_to_color_0803F684(0, 0x20 - gUnk_03000440.unk84 * 4, 0xFFFF);
        blend_obj_palettes_to_color_0803F998(0, 0x20 - gUnk_03000440.unk84 * 4, 0xFFFF);
        gUnk_03000440.unk84++;
    }
    else
        gGameSubState++;
}

void sub_08012B94(void)
{
    update_all_battle_status_sprites();
    if (gUnk_03000440.unk89 != 1)
        battle_process_bot_actions_for_side(3);
    gGameSubState++;
}

void sub_08012BC0(void)
{
    update_all_battle_status_sprites();
    sub_08016370(gUnk_03001800.unk80);
    gGameSubState++;
}

void sub_08012BE4(void)
{
    update_all_battle_status_sprites();
    if (sub_08016438(gUnk_03001800.unk80))
        gGameSubState++;
}

void sub_08012C0C(void)
{
    update_all_battle_status_sprites();
    animate_battle_sprites(gUnk_03001800.unk80);
    load_battle_bg_layers();
    render_bot_name_sprites(gUnk_03001800.unk80);
    draw_battle_panel_left_a(gUnk_03001800.unk80);
    draw_medaforce_gauge_bar(gUnk_03001800.unk80);
    draw_medaforce_gauge_value(gUnk_03001800.unk80);
    command_ring_draw_name();
    command_ring_init_icons();
    battle_sprite_set_palette_index(gUnk_03001800.unk80 * 4 + 0x5A, 8);
    gGameSubState++;
}

// Sub-state 7: command ring of team Medabot gUnk_03001800.unk80 (runtime-checked). A -> sub-state 8,
// B -> back to the previous Medabot (sub-state 4).
void robattle_command_input(void)
{
    update_all_battle_status_sprites();
    animate_battle_sprites(gUnk_03001800.unk80);
    update_battle_sprite_orbiting_positions(gUnk_03001800.unk80 * 4 + 0x5A, gUnk_03001800.unk80, 0);
    command_ring_input();
    sub_080178CC();
    if (gUnk_03001800.unk83)
        return;
    command_ring_pulse_selected();
    if (KEYS_LO(gNewKeys) & 1)
    {
        if (gUnk_03000440.unk89 == 1 && gUnk_03001800.unk81 == 5)
        {
            play_sound_effect(6);
            return;
        }
        play_sound_effect(4);
        sub_08017914();
        gUnk_03000440.unk84 = 0;
        gGameSubState++;
    }
    else if (KEYS_LO(gNewKeys) & 2)
    {
        if (gUnk_03001800.unk84 == 0 && gUnk_03001800.unk80 != 0)
        {
            play_sound_effect(5);
            setup_bot_battle_sprites_08015A00(gUnk_03001800.unk80, 0x28, (u8)(gUnk_03001800.unk80 % 3) * 24 + 0x24);
            gUnk_03001800.unk80--;
            draw_battle_panel_left_a(0);
            sub_0801A744(gUnk_03001800.unk80);
            gUnk_03001800.unk81 = 0;
            gUnk_03001800.unk82 = 0;
            clear_battle_sprite_slot(0, 0x46);
            vram_fill_tilemap_rect(0x1E, 8, 0, 0xC, REG_BG0CNT, 0);
            vram_fill_tilemap_rect(0x1E, 8, 0, 0xC, REG_BG1CNT, 0);
            gGameSubState = 4;
        }
    }
}

void sub_08012D98(void)
{
    update_all_battle_status_sprites();
    animate_battle_sprites(gUnk_03001800.unk80);
    update_battle_sprite_orbiting_positions(gUnk_03001800.unk80 * 4 + 0x5A, gUnk_03001800.unk80, 0);
    sub_08016554();
    if (++gUnk_03000440.unk84 == 20)
    {
        clear_battle_sprite_slot(0x1E, 0xB);
        gUnk_03000440.unk84 = 0;
        gGameSubState++;
    }
}

void sub_08012DF4(void)
{
    update_all_battle_status_sprites();
    animate_battle_sprites(gUnk_03001800.unk80);
    update_battle_sprite_orbiting_positions(gUnk_03001800.unk80 * 4 + 0x5A, gUnk_03001800.unk80, 0);
    sub_080165D0();
    sub_08016614();
    sub_08016660();
    if (++gUnk_03000440.unk84 == 16)
        command_ring_goto_selected();
}

void sub_08012E40(void)
{
    update_all_battle_status_sprites();
    animate_battle_sprites(gUnk_03001800.unk80);
    update_battle_sprite_orbiting_positions(gUnk_03001800.unk80 * 4 + 0x5A, gUnk_03001800.unk80, 0);
    decompress_two_bg1_layers();
    command_ring_init_icons_hidden();
    read_vram_tilemap_rect(6, 5, 0xC, 0x15, REG_BG1CNT, gUnk_02020800);
    gUnk_03000440.unk84 = 0;
    gGameSubState++;
}

void sub_08012EA8(void)
{
    update_all_battle_status_sprites();
    animate_battle_sprites(gUnk_03001800.unk80);
    update_battle_sprite_orbiting_positions(gUnk_03001800.unk80 * 4 + 0x5A, gUnk_03001800.unk80, 0);
    draw_partial_bg1_column();
    scroll_tilemap_window();
    sub_08016FB4();
    if (++gUnk_03000440.unk84 == 10)
    {
        command_ring_draw_name();
        gGameSubState = 7;
    }
}

// Stores the chosen command of Medabot unk80 and moves on to the next one (sub-state 4), or to
// sub-state 0x40 (0x90 when unk89 is 1) after the last one.
void robattle_command_commit(void)
{
    update_all_battle_status_sprites();
    animate_battle_sprites(gUnk_03001800.unk80);
    update_battle_sprite_orbiting_positions(gUnk_03001800.unk80 * 4 + 0x5A, gUnk_03001800.unk80, 0);
    switch (gUnk_03001800.unk81)
    {
        case 0:
            battle_bot_select_part(gUnk_03001800.unk80, gUnk_03001800.unk82);
            break;
        case 1:
            if (gUnk_03001800.unk82)
                battle_bot_select_medaforce(gUnk_03001800.unk80, gUnk_03001800.unk82 - 1);
            else
                battle_bot_select_part(gUnk_03001800.unk80, 0);
            break;
        default:
            process_bot_battle_turn(gUnk_03001800.unk80);
            break;
    }
    setup_bot_battle_sprites_08015A00(gUnk_03001800.unk80, 0x28, (u8)(gUnk_03001800.unk80 % 3) * 24 + 0x24);
    gUnk_03001800.unk81 = 0;
    gUnk_03001800.unk82 = 0;
    gUnk_03001800.unk80++;
    if (gUnk_03001800.unk84 == 0)
    {
        if (gUnk_03001800.unk80 != 3 && gUnk_03001800.unk80 < gUnk_03001800.unk5A)
            gGameSubState = 4;
        else if (gUnk_03000440.unk89 != 1)
            gGameSubState = 0x40;
        else
            gGameSubState = 0x90;
    }
    else
        gGameSubState++;
}

void sub_08012FF8(void)
{
    update_all_battle_status_sprites();
    sub_08018900(gUnk_03001800.unk87);
    init_battle_action_select_ui(0);
    if (gUnk_03000440.unk89 != 1)
        gGameSubState = 0x45;
    else
        gGameSubState = 0xA0;
}

void sub_0801303C(void)
{
    update_all_battle_status_sprites();
    animate_battle_sprites(gUnk_03001800.unk80);
    update_battle_sprite_orbiting_positions(gUnk_03001800.unk80 * 4 + 0x5A, gUnk_03001800.unk80, 0);
    CpuFastSet(gUnk_084E2F58, (void *)0x05000340, 8);
    CpuFastSet(gUnk_084E3038, (void *)0x050002C0, 8);
    clear_battle_sprite_slot(0, 6);
    clear_battle_sprite_slot(0x1E, 0xB);
    sub_080166AC();
    determine_battle_part_action_priority();
    read_vram_tilemap_rect(0xC, 4, 9, 0x15, REG_BG0CNT, gUnk_02020800);
    gUnk_03000440.unk84 = 0;
    gGameSubState++;
}

void sub_080130D8(void)
{
    update_all_battle_status_sprites();
    animate_battle_sprites(gUnk_03001800.unk80);
    update_battle_sprite_orbiting_positions(gUnk_03001800.unk80 * 4 + 0x5A, gUnk_03001800.unk80, 0);
    sub_080166F0();
    sub_0801672C();
    if (++gUnk_03000440.unk84 == 16)
    {
        part_select_init_cursor();
        part_select_init_center_icon();
        part_select_init_head_icon(1);
        part_select_init_right_arm_icon(1);
        part_select_init_left_arm_icon(1);
        part_select_init_bottom_icon(1);
        part_select_draw_part_name();
        part_select_draw_skill_type();
        part_select_draw_skill_name();
        part_select_draw_head_uses();
        sub_0801B894();
        gUnk_03000440.unk84 = 0;
        gGameSubState++;
    }
}

// guess: Medaforce panel input (shows "Charge MF"; sub-state 18, B -> 19, A -> 21)
void sub_08013164(void)
{
    u8 b;

    update_all_battle_status_sprites();
    animate_battle_sprites(gUnk_03001800.unk80);
    update_battle_sprite_orbiting_positions(gUnk_03001800.unk80 * 4 + 0x5A, gUnk_03001800.unk80, 0);
    sub_0801B9C4();
    gUnk_03000440.unk84++;
    part_select_blink_selected_icon();
    part_select_input();
    part_select_blink_status();
    if ((b = KEYS_LO(gNewKeys) & 2))
    {
        play_sound_effect(5);
        clear_battle_sprite_slot(0, 6);
        sub_0801BACC();
        clear_battle_sprite_slot(0x14, 0x26);
        vram_fill_tilemap_rect(7, 1, 0xE, 0xC, REG_BG0CNT, 0);
        gUnk_03000440.unk84 = 0;
        gGameSubState++;
    }
    else if (KEYS_LO(gNewKeys) & 1)
    {
        play_sound_effect(4);
        sub_0801BACC();
        gUnk_03000440.unk86 = 0;
        gGameSubState = 0x15;
    }
}

void sub_08013228(void)
{
    update_all_battle_status_sprites();
    animate_battle_sprites(gUnk_03001800.unk80);
    update_battle_sprite_orbiting_positions(gUnk_03001800.unk80 * 4 + 0x5A, gUnk_03001800.unk80, 0);
    save_restore_bg0_tilemap_region();
    save_restore_bg1_tilemap_region();
    if (++gUnk_03000440.unk84 == 16)
    {
        CpuFastSet(gUnk_084E2F38, (void *)0x05000340, 8);
        gGameSubState = 0xB;
    }
}

void sub_08013288(void)
{
    update_all_battle_status_sprites();
    animate_battle_sprites(gUnk_03001800.unk80);
    update_battle_sprite_orbiting_positions(gUnk_03001800.unk80 * 4 + 0x5A, gUnk_03001800.unk80, 0);
    gUnk_03000440.unk84++;
    gUnk_03000440.unk84++;
    part_select_blink_selected_icon();
    part_select_blink_status();
    if (++gUnk_03000440.unk86 == 16)
    {
        clear_battle_sprite_slot(0, 0x46);
        vram_fill_tilemap_rect(0x1E, 8, 0, 0xC, REG_BG0CNT, 0);
        vram_fill_tilemap_rect(0x1E, 8, 0, 0xC, REG_BG1CNT, 0);
        CpuFastSet(gUnk_084E2F38, (void *)0x05000340, 8);
        gGameSubState = 0xD;
    }
}

void sub_08013330(void)
{
    update_all_battle_status_sprites();
    animate_battle_sprites(gUnk_03001800.unk80);
    update_battle_sprite_orbiting_positions(gUnk_03001800.unk80 * 4 + 0x5A, gUnk_03001800.unk80, 0);
    CpuFastSet(gUnk_084E2F78, (void *)0x05000340, 8);
    clear_battle_sprite_slot(0, 6);
    clear_battle_sprite_slot(0x1E, 0xB);
    sub_08017004();
    read_vram_tilemap_rect(0xC, 4, 9, 0x15, REG_BG0CNT, gUnk_02020800);
    gUnk_03000440.unk84 = 0;
    gGameSubState++;
}

void sub_080133B8(void)
{
    update_all_battle_status_sprites();
    animate_battle_sprites(gUnk_03001800.unk80);
    update_battle_sprite_orbiting_positions(gUnk_03001800.unk80 * 4 + 0x5A, gUnk_03001800.unk80, 0);
    sub_08017048();
    sub_08017084();
    if (++gUnk_03000440.unk84 == 16)
    {
        sub_080170D4();
        sub_08017104();
        sub_08017178(1);
        sub_080171C0(1);
        sub_08017208(1);
        sub_08017130(1);
        sub_08017268();
        sub_080173B4(0);
        gUnk_03000440.unk84 = 0;
        gGameSubState++;
    }
}

void sub_08013438(void)
{
    u8 b;

    update_all_battle_status_sprites();
    animate_battle_sprites(gUnk_03001800.unk80);
    update_battle_sprite_orbiting_positions(gUnk_03001800.unk80 * 4 + 0x5A, gUnk_03001800.unk80, 0);
    gUnk_03000440.unk84++;
    sub_0801767C();
    sub_080175FC();
    sub_080173B4(1);
    if ((b = KEYS_LO(gNewKeys) & 2))
    {
        play_sound_effect(5);
        vram_fill_tilemap_rect(8, 1, 1, 0x11, REG_BG0CNT, 0);
        draw_medaforce_gauge_value(gUnk_03001800.unk80);
        clear_battle_sprite_slot(0, 5);
        clear_battle_sprite_slot(0x14, 0x24);
        gUnk_03000440.unk84 = 0;
        gGameSubState++;
    }
    else if (KEYS_LO(gNewKeys) & 1)
    {
        play_sound_effect(4);
        gUnk_03000440.unk86 = 0;
        gGameSubState = 0x1D;
    }
}

void sub_08013508(void)
{
    update_all_battle_status_sprites();
    animate_battle_sprites(gUnk_03001800.unk80);
    update_battle_sprite_orbiting_positions(gUnk_03001800.unk80 * 4 + 0x5A, gUnk_03001800.unk80, 0);
    save_restore_bg0_tilemap_region();
    sub_08017948();
    if (++gUnk_03000440.unk84 == 16)
    {
        CpuFastSet(gUnk_084E2F38, (void *)0x05000340, 8);
        gGameSubState = 0xB;
    }
}

void sub_08013568(void)
{
    update_all_battle_status_sprites();
    animate_battle_sprites(gUnk_03001800.unk80);
    update_battle_sprite_orbiting_positions(gUnk_03001800.unk80 * 4 + 0x5A, gUnk_03001800.unk80, 0);
    gUnk_03000440.unk84++;
    gUnk_03000440.unk84++;
    sub_0801767C();
    sub_080173B4(1);
    if (++gUnk_03000440.unk86 == 16)
    {
        clear_battle_sprite_slot(0, 0x46);
        vram_fill_tilemap_rect(0x1E, 8, 0, 0xC, REG_BG0CNT, 0);
        vram_fill_tilemap_rect(0x1E, 8, 0, 0xC, REG_BG1CNT, 0);
        CpuFastSet(gUnk_084E2F38, (void *)0x05000340, 8);
        gGameSubState = 0xD;
    }
}

void sub_08013614(void)
{
    update_all_battle_status_sprites();
    animate_battle_sprites(gUnk_03001800.unk80);
    update_battle_sprite_orbiting_positions(gUnk_03001800.unk80 * 4 + 0x5A, gUnk_03001800.unk80, 0);
    text_window_init(1, 2, 0);
    gGameSubState++;
}

void sub_08013650(void)
{
    update_all_battle_status_sprites();
    animate_battle_sprites(gUnk_03001800.unk80);
    update_battle_sprite_orbiting_positions(gUnk_03001800.unk80 * 4 + 0x5A, gUnk_03001800.unk80, 0);
    if (run_message(gUnk_083B70AC[gUnk_03000590[gUnk_03001800.unk80].medal.unk6]))
    {
        gUnk_03000440.unk1B = 0;
        gGameSubState++;
    }
}

void sub_080136B0(void)
{
    update_all_battle_status_sprites();
    animate_battle_sprites(gUnk_03001800.unk80);
    update_battle_sprite_orbiting_positions(gUnk_03001800.unk80 * 4 + 0x5A, gUnk_03001800.unk80, 0);
    if (game_state_execute_handler_a())
        gGameSubState = 0xB;
}

void sub_080136E8(void)
{
    update_all_battle_status_sprites();
    animate_battle_sprites(gUnk_03001800.unk80);
    update_battle_sprite_orbiting_positions(gUnk_03001800.unk80 * 4 + 0x5A, gUnk_03001800.unk80, 0);
    copy_obj_palette_to_buffer();
    gUnk_03000440.unk84 = 0;
    gGameSubState++;
}

void sub_0801372C(void)
{
    update_all_battle_status_sprites();
    animate_battle_sprites(gUnk_03001800.unk80);
    update_battle_sprite_orbiting_positions(gUnk_03001800.unk80 * 4 + 0x5A, gUnk_03001800.unk80, 0);
    if (gUnk_03000440.unk84 <= 8)
    {
        blend_obj_palettes_to_color_0803F684(0, gUnk_03000440.unk84 * 4, 0xFFFF);
        blend_obj_palettes_to_color_0803F998(0, gUnk_03000440.unk84 * 4, 0xFFFF);
        gUnk_03000440.unk84++;
    }
    else
    {
        gGameSubState++;
    }
}

void sub_08013798(void)
{
    CpuFastSet((void *)0x06002800, (void *)0x02020800, 0x200);
    CpuFastSet((void *)0x0600C800, (void *)0x02021000, 0x200);
    CpuFastSet((void *)0x0600D000, (void *)0x02021800, 0x200);
    CpuFastSet((void *)0x0600D800, (void *)0x02022000, 0x200);
    CpuFastSet(gUnk_03002C30, (void *)0x02028000, 0x800);
    set_blend_effect_mode(5, 0x3F, 0x20);
    gVBlankCallback = nullsub_08000840;
    gGameSubState++;
}

// guess: Robattle sub-state 0x33 opens the Medals screen (game state 4, sub 0x28) on the Rotation page of
// the current Medabot's Medal; sub_08013798 (0x32) saves VRAM/OAM, battle_phase_dispatch_0801387C (0x3C) restores it.
void sub_08013824(void)
{
    sub_0803F624(&gUnk_03000440.unk3C, 0x14, 0);
    gUnk_03000440.unk3C = 2;
    gUnk_03000440.unk3D = find_medal_slot_by_id(gUnk_03000590[gUnk_03001800.unk80].medal.unk1) - 1;
    gUnk_03000440.unk41 = 1;
    gUnk_03000440.unk42 = 2;
    sub_08043CA8();
    gGameState = 4;
    gGameSubState = 0x28;
}

void battle_phase_dispatch_0801387C(void)
{
    u32 fill;

    switch (gUnk_03000440.unk139)
    {
        case 0:
            gUnk_03000440.unk96 = 0;
            gUnk_03000430 = 0;
            sub_08043CA8();
            load_battle_script_entry_b();
            REG_DISPCNT &= 0xF0FF;
            REG_BG0CNT = 0x500;
            REG_BG1CNT = 0x1901;
            REG_BG2CNT = 0x1A0A;
            REG_BG3CNT = 0x1B0B;
            if (battle_phase_dispatch_0801A788(0))
            {
                gUnk_03000440.unk84 = 0;
                gUnk_03000440.unk139++;
            }
            break;
        case 1:
            fill = 0;
            CpuFastSet(&fill, gUnk_03002C30, 0x01000800);
            gUnk_03000440.unk139++;
            break;
        case 2:
            REG_DISPCNT |= 0x1F40;
            load_all_bot_part_sprites();
            apply_battle_blend_effect_b();
            decompress_to_ewram_27000((const u8 *)gUnk_083B24A8[gUnk_03001800.unk38 * 5 + 1]);
            gUnk_03000440.unk139++;
            break;
        case 3:
            CpuFastSet((void *)0x02020800, (void *)0x06002800, 0x200);
            CpuFastSet((void *)0x02021000, (void *)0x0600C800, 0x200);
            gUnk_03000440.unk139++;
            break;
        case 4:
            CpuFastSet((void *)0x02021800, (void *)0x0600D000, 0x200);
            CpuFastSet((void *)0x02022000, (void *)0x0600D800, 0x200);
            gUnk_03000440.unk139++;
            break;
        case 5:
            CpuFastSet((void *)0x02028000, gUnk_03002C30, 0x800);
            gVBlankCallback = sub_08044100;
            gGameSubState++;
            gUnk_03000440.unk139 = 0;
            break;
    }
}

void sub_08013A74(void)
{
    update_all_battle_status_sprites();
    animate_battle_sprites(gUnk_03001800.unk80);
    update_battle_sprite_orbiting_positions(gUnk_03001800.unk80 * 4 + 0x5A, gUnk_03001800.unk80, 0);
    if (gUnk_03000440.unk84 <= 8)
    {
        blend_obj_palettes_to_color_0803F684(0, 0x20 - gUnk_03000440.unk84 * 4, 0xFFFF);
        blend_obj_palettes_to_color_0803F998(0, 0x20 - gUnk_03000440.unk84 * 4, 0xFFFF);
        gUnk_03000440.unk84++;
    }
    else
    {
        gGameSubState = 0xB;
    }
}

void sub_08013AE4(void)
{
    update_all_battle_status_sprites();
    animate_battle_sprites(gUnk_03001800.unk80);
    update_battle_sprite_orbiting_positions(gUnk_03001800.unk80 * 4 + 0x5A, gUnk_03001800.unk80, 0);
    switch (gUnk_03001800.unk80)
    {
    case 0:
        gUnk_03001800.unk44 |= 1;
        break;
    case 1:
        gUnk_03001800.unk44 |= 2;
        break;
    case 2:
        gUnk_03001800.unk44 |= 4;
        break;
    }
    clear_battle_sprite_slot(0, 0x46);
    vram_fill_tilemap_rect(0x1E, 8, 0, 0xC, REG_BG0CNT, 0);
    vram_fill_tilemap_rect(0x1E, 8, 0, 0xC, REG_BG1CNT, 0);
    gGameSubState = 0xD;
}

void sub_08013B8C(void)
{
    u32 fill;

    sub_08043CA8();
    REG_DISPCNT &= 0xF0FF;
    REG_BG0CNT = 0x500;
    REG_BG1CNT = 0x1901;
    REG_BG2CNT = 0x1A02;
    REG_BG3CNT = 0x1B03;
    lz_decompress_dispatch(gUnk_084ED4C4, (void *)0x06004000);
    lz_decompress_dispatch(gUnk_084C50D8, (void *)0x06006000);
    lz_decompress_dispatch(gUnk_084C33DC, (void *)0x06006800);
    lz_decompress_dispatch(gUnk_084C4DB0, (void *)0x06006E00);
    lz_decompress_dispatch(gUnk_084C36F0, (void *)0x06007200);
    lz_decompress_dispatch(gUnk_084C50BC, (void *)0x06007480);
    lz_decompress_dispatch(gUnk_084C7318, (void *)0x06017E00);
    set_tilemap_and_decompress_bg(0, 0, gUnk_084EF5DC, REG_BG0CNT, 0x200);
    set_tilemap_and_decompress_bg(0, 0, gUnk_084F0128, REG_BG1CNT, 0x200);
    set_tilemap_and_decompress_bg(0, 0, gUnk_084F0D24, REG_BG2CNT, 0x200);
    set_tilemap_and_decompress_bg(0, 0, gUnk_084F205C, REG_BG3CNT, 0x200);
    CpuFastSet(gUnk_084F37E0, (void *)0x05000000, 0x70);
    CpuFastSet(gUnk_0850DEF8, (void *)0x05000200, 0x40);
    CpuFastSet(gUnk_0850DD58, (void *)0x05000380, 8);
    CpuFastSet(&gUnk_0850DD58[0x20], (void *)0x050003A0, 8);
    CpuFastSet(&gUnk_0850DD58[-0x20], (void *)0x050003E0, 8);
    CpuFastSet(gUnk_084E2E58, (void *)0x050003C0, 8);
    fill = 0;
    CpuFastSet(&fill, gUnk_03002C30, 0x01000800);
    REG_DISPCNT |= 0x1F40;
    sub_0803F624(&gUnk_03000440.unk3C, 0x14, 0);
    gUnk_03000440.unk46 = 1;
    position_battle_team_cursors(0, 0);
    status_init_cursor();
    status_draw_bot_name();
    sub_08017D14();
    status_load_medal_icon();
    status_draw_medal_name();
    status_draw_part_names();
    status_draw_part_ability_icons();
    status_draw_part_armor();
    get_bot_part_effective_values(gUnk_03000440.unk3C * 3 + gUnk_03000440.unk3D, gUnk_03001800.unk64);
    set_portrait_parts(gUnk_03001800.unk64[0], gUnk_03001800.unk64[1], gUnk_03001800.unk64[2], gUnk_03001800.unk64[3]);
    status_init_portrait();
    status_draw_team_sprites();
    battle_sprite_set_palette_index(0, 8);
    fill_tilemap_rect_08042698(2, 2, 0xB, 2, REG_BG1CNT, 0x63C0);
    set_blend_effect_mode(5, 0x3F, 0x20);
    gGameSubState++;
}

void sub_08013DE4(void)
{
    sub_080182D0();
    status_blink_lr_button();
    status_update_portrait();
    status_draw_team_sprites();
    sub_08041C14(8, gFrameCounter, status_cursor_x());
    scroll_bg3_diagonal();
    if (update_blend_effect())
        gGameSubState++;
}

void sub_08013E30(void)
{
    sub_080182D0();
    status_update_portrait();
    scroll_bg3_diagonal();
    switch (gUnk_03000440.unk3F)
    {
    case 0:
        status_blink_lr_button();
        status_draw_team_sprites();
        sub_08041C14(8, gFrameCounter, status_cursor_x());
        status_select_input();
        if ((KEYS_HI(gNewKeys) & 1) && gUnk_03000440.unk3C == 0)
        {
            play_sound_effect(2);
            status_begin_side_change();
            gUnk_03000440.unk40 = 0;
            gUnk_03000440.unk3F++;
        }
        else if ((KEYS_HI(gNewKeys) & 2) && gUnk_03000440.unk3C == 1)
        {
            play_sound_effect(2);
            status_begin_side_change();
            gUnk_03000440.unk40 = 0;
            gUnk_03000440.unk3F++;
        }
        else if (KEYS_LO(gNewKeys) & 2)
        {
            play_sound_effect(5);
            set_blend_effect_mode(6, 0x3F, 0x20);
            gGameSubState++;
        }
        break;
    case 1:
        if (status_side_change_scroll_out())
        {
            gUnk_03000440.unk40 = 0;
            gUnk_03000440.unk3F++;
        }
        break;
    case 2:
        if (status_side_change_scroll_in())
            gUnk_03000440.unk3F++;
        break;
    case 3:
        get_bot_part_effective_values(gUnk_03000440.unk3D + gUnk_03000440.unk3C * 3, gUnk_03001800.unk64);
        set_portrait_parts(gUnk_03001800.unk64[0], gUnk_03001800.unk64[1], gUnk_03001800.unk64[2], gUnk_03001800.unk64[3]);
        status_init_portrait();
        battle_sprite_set_palette_index(0, 8);
        fill_tilemap_rect_08042698(2, 2, 0xB, 2, REG_BG1CNT, 0x63C0);
        status_reset_portrait();
        gUnk_03000440.unk3F = 0;
        break;
    }
}

void sub_08013FA8(void)
{
    u32 fill1, fill2, fill3;

    sub_080182D0();
    status_blink_lr_button();
    status_update_portrait();
    status_draw_team_sprites();
    sub_08041C14(8, gFrameCounter, status_cursor_x());
    scroll_bg3_diagonal();
    if (update_blend_effect())
    {
        gUnk_03000440.unk96 = 0;
        gUnk_03000430 = 0;
        fill1 = 0x200;
        CpuFastSet(&fill1, gUnk_03002414->unkB84, 0x01000100);
        fill2 = 0;
        CpuFastSet(&fill2, (void *)0x05000200, 0x01000080);
        fill3 = 0;
        CpuFastSet(&fill3, (void *)0x05000000, 0x01000080);
        gGameSubState = 0x3C;
    }
}

// Robattle sub-state 0x40: loads the "MEDABOTS ROBATTLE" logo sprites, plays sound 0x6E.
void robattle_start_banner_init(void)
{
    sub_080189EC();
    gUnk_03001800.unk84 = 1;
    lz_decompress_dispatch(gUnk_084C84E4, (void *)0x06014800);
    CpuFastSet(gUnk_084E2FD8, (void *)0x050003E0, 8);
    sound_stop_all_with_fade_guard(8);
    play_sound_effect(0x6E);
    gUnk_03000440.unk84 = 0;
    gGameSubState++;
}

// Robattle sub-state 0x41: "MEDABOTS" (sprite 3) mosaics in, then "ROBATTLE" (sprite 4) stretches in;
// after 60 frames -> 0x42 (runtime-checked from battle_start.ss0).
void robattle_start_banner(void)
{
    switch (gUnk_03000440.unk84)
    {
    case 0:
        gUnk_03002C30[3].unk0 = 0xC005;
        gUnk_03002C30[3].unk1C = 0;
        gUnk_03002C30[3].unk2 = 0x78;
        gUnk_03002C30[3].unk4 = 0x38;
        gUnk_03002C30[3].unkA = 0xF;
        gUnk_03002C30[3].unkB = 0xC0;
        gUnk_03002C30[3].unk6 = 0x900;
        gUnk_03002C30[3].unk20 = 8;
        REG_MOSAIC = (gUnk_03002C30[3].unk20 << 12) + (gUnk_03002C30[3].unk20 << 8);
        gUnk_03000440.unk84++;
        break;
    case 1:
        if (gFrameCounter & 1)
            break;
        gUnk_03002C30[3].unk20--;
        REG_MOSAIC = (gUnk_03002C30[3].unk20 << 12) + (gUnk_03002C30[3].unk20 << 8);
        if (gUnk_03002C30[3].unk20 == 0)
        {
            gUnk_03002C30[4].unk0 = 0xC224;
            gUnk_03002C30[4].unk1C = 0;
            gUnk_03002C30[4].unk2 = 0x78;
            gUnk_03002C30[4].unk4 = 0x48;
            gUnk_03002C30[4].unkA = 0xF;
            gUnk_03002C30[4].unkB = 0xC0;
            gUnk_03002C30[4].unk6 = 0x901;
            gUnk_03002C30[4].unk9 = 8;
            gUnk_03002C30[4].unk8 = 0x40;
            gUnk_03000440.unk84++;
        }
        break;
    case 2:
        if ((gUnk_03002C30[4].unk9 += 8) == 0x60)
            gUnk_03000440.unk84++;
        break;
    case 3:
        if ((gUnk_03002C30[4].unk9 -= 8) == 0x40)
        {
            gUnk_03000440.unk84++;
            gUnk_03000440.unk86 = 0;
        }
        break;
    default:
        if (++gUnk_03000440.unk86 == 0x3C)
        {
            clear_battle_sprite_slot(3, 2);
            CpuFastSet(gUnk_0850DDF8, (void *)0x050003E0, 8);
            gGameSubState++;
        }
        break;
    }
}

void sub_0801425C(void)
{
    select_battle_music();
    init_battle_action_select_ui(0);
    sub_08018BD4();
    gGameSubState = 0x44;
}

// Robattle sub-state 0x44: turn loop (TIME counter on screen); unk55 flags 2/4/8/0x10 -> 0x60/0x68/0x70/0x78.
void sub_0801427C(void)
{
    if (gUnk_03001800.unk55 == 0)
    {
        sub_08018C38();
        sub_08018C78();
    }
    if (gUnk_03001800.unk55 & 2)
        gGameSubState = 0x60;
    else if (gUnk_03001800.unk55 & 4)
        gGameSubState = 0x68;
    else if (gUnk_03001800.unk55 & 8)
        gGameSubState = 0x70;
    else if (gUnk_03001800.unk55 & 0x10)
        gGameSubState = 0x78;
    else
    {
        sub_0801902C();
        update_all_battle_status_sprites();
        init_battle_bot_sprites();
        if (sub_08019EF0())
        {
            sub_08019078();
            gGameSubState++;
        }
    }
}

void sub_08014314(void)
{
    struct Unk_03000590 *rec;
    u8 flag;

    update_all_battle_status_sprites();
    sub_08019078();
    sort_active_medal_slots();
    if (gUnk_03001800.unk45 == 0)
    {
        gGameSubState = 0x44;
        return;
    }
    battle_calc_bot_count_minus_one_mod3();
    rec = gUnk_03000590;
    rec += gUnk_03001800.unk87;
    if (rec->unk40 == 0)
    {
        sub_0801A678();
    }
    else if ((flag = rec->unkBD & 4))
    {
        gGameSubState = 0x47;
    }
    else
    {
        iterate_bots_setup_battle_sprites();
        gGameState = 8;
        gGameSubState = flag;
    }
}

void sub_080143A0(void)
{
    update_all_battle_status_sprites();
    gUnk_03000590[gUnk_03001800.unk87].unkBD ^= 4;
    iterate_bots_setup_battle_sprites();
    sub_0801A678();
    battle_bot_advance_rotation(gUnk_03001800.unk87);
    if (sub_0801A6B0())
    {
        sub_0803F624(&gUnk_03001800.unk45, 0xC, 0);
        gGameSubState = 0x4C;
    }
    else
    {
        gGameSubState = 0x45;
    }
}

void sub_08014404(void)
{
    update_all_battle_status_sprites();
    sub_08019078();
    gUnk_03000590[gUnk_03001800.unk87].unkBD ^= 4;
    setup_bot_battle_sprites_08015A00(gUnk_03001800.unk87,
        gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk2,
        gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 4);
    sub_0801A678();
    battle_process_all_bot_actions(gUnk_03001800.unk87);
    if (gUnk_03001800.unk87 > 2)
    {
        if (gUnk_03000440.unk89 != 1)
        {
            process_bot_battle_turn(gUnk_03001800.unk87);
            gGameSubState = 0x45;
        }
        else
        {
            if (gUnk_03000590[gUnk_03001800.unk87].unkC9 == 0x2C)
                process_bot_battle_turn(gUnk_03001800.unk87);
            gGameSubState = 0xA0;
        }
    }
    else if (gUnk_03000590[gUnk_03001800.unk87].unkC9 == 0x2C)
    {
        process_bot_battle_turn(gUnk_03001800.unk87);
        sub_08018900(gUnk_03001800.unk87);
        if (gUnk_03000440.unk89 != 1)
            gGameSubState = 0x45;
        else
            gGameSubState = 0xA0;
    }
    else
    {
        if (sub_0801A6EC(gUnk_03001800.unk87))
        {
            if (!(KEYS_LO(gHeldKeys) & 2))
            {
                process_bot_battle_turn(gUnk_03001800.unk87);
                sub_08018900(gUnk_03001800.unk87);
                gGameSubState = 0x45;
                return;
            }
            sub_0801A744(gUnk_03001800.unk87);
        }
        gUnk_03001800.unk80 = gUnk_03001800.unk87;
        gUnk_03001800.unk81 = 0;
        gUnk_03001800.unk82 = 0;
        gUnk_03001800.unk83 = 0;
        gUnk_03001800.unk85 = 0;
        iterate_bots_setup_battle_sprites();
        gGameSubState = 4;
    }
}

void sub_08014548(void)
{
    u32 i;

    update_all_battle_status_sprites();
    init_battle_bot_sprites();
    for (i = 0; i <= 5; i++)
    {
        struct Unk_03000590 *rec = gUnk_03000590;

        rec += i;
        if (rec->unk40 && rec->unkBF)
        {
            u32 a, b;

            rec->unkBB = 8;
            sub_08019348(i);
            sub_08019544(i);
            a = sub_08019FBC(i, 1);
            b = sub_0801A030(i, 1);
            if (a || b)
            {
                rec->unkBF = 0;
                gGameSubState = 0x45;
                return;
            }
        }
    }
}

void sub_080145BC(void)
{
    u32 i;

    update_all_battle_status_sprites();
    iterate_bots_setup_battle_sprites();
    for (i = 0; i <= 5; i++)
    {
        if (gUnk_03000590[i].unk40 && (gUnk_03000590[i].unkCE & 1))
        {
            gUnk_03002C30[0x46 + i * 3].unk0 |= 0x8220;
            gUnk_03002C30[0x46 + i * 3].unk9 = 0x40;
            gUnk_03002C30[0x46 + i * 3].unk8 = 0x40;
        }
    }
    play_sound_effect(0x37);
    gGameSubState++;
}

void sub_08014634(void)
{
    u32 i;

    update_all_battle_status_sprites();
    for (i = 0; i <= 5; i++)
    {
        if (gUnk_03000590[i].unk40 && (gUnk_03000590[i].unkCE & 1))
        {
            gUnk_03002C30[0x46 + i * 3].unk0 |= 0x8000;
            gUnk_03002C30[0x46 + i * 3].unk9 += 4;
            if ((gUnk_03002C30[0x46 + i * 3].unk8 -= 4) == 4)
            {
                gUnk_03001800.unk55 &= ~2;
                gUnk_03000590[i].unkCE &= ~1;
                clear_battle_sprite_slot(0x46 + i * 3, 1);
            }
        }
    }
    if (!(gUnk_03001800.unk55 & 2))
        gGameSubState = 0x44;
}

void sub_080146DC(void)
{
    u32 i;

    update_all_battle_status_sprites();
    iterate_bots_setup_battle_sprites();
    for (i = 0; i <= 5; i++)
    {
        if (gUnk_03000590[i].unk40 && (gUnk_03000590[i].unkCE & 2))
        {
            gUnk_03002C30[0x47 + i * 3].unk0 |= 0x8220;
            gUnk_03002C30[0x47 + i * 3].unk9 = 0x40;
            gUnk_03002C30[0x47 + i * 3].unk8 = 0x40;
        }
    }
    play_sound_effect(0x37);
    gGameSubState++;
}

void sub_08014754(void)
{
    u32 i;

    update_all_battle_status_sprites();
    for (i = 0; i <= 5; i++)
    {
        if (gUnk_03000590[i].unk40 && (gUnk_03000590[i].unkCE & 2))
        {
            gUnk_03002C30[0x47 + i * 3].unk0 |= 0x8000;
            gUnk_03002C30[0x47 + i * 3].unk9 += 4;
            if ((gUnk_03002C30[0x47 + i * 3].unk8 -= 4) == 4)
            {
                gUnk_03001800.unk55 &= ~4;
                gUnk_03000590[i].unkCE &= ~2;
                clear_battle_sprite_slot(0x47 + i * 3, 1);
            }
        }
    }
    if (!(gUnk_03001800.unk55 & 4))
        gGameSubState = 0x44;
}

