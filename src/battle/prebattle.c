// Game state 6: the screens around a Robattle. Before it: the mosaic flash and stripe wipe over the field,
// loading the encounter (random encounter enemies, battlefield), the opponent's line, the Rubberobo option
// and team select. After it: the battle count, the part won (with its detail page), experience and Medal
// level-up, the loss path (part taken, no Medabots left), and the exit back to the field.
// Entry point prebattle_screen_update (sub-states in gPrebattleScreenHandlers). Hands over to state 7
// (battle/robattle) and back to the field (game mode 1).

#include "global.h"

static void load_encounter_into_battle_setup(void);
static void prebattle_draw_opponent_name(void);
static void prebattle_draw_battlefield_name(void);
static void load_opponent_medabot_sprites(void);
static void update_all_battle_sprite_orbits(void);
static void prebattle_init_rubberobo_sprite(void);
static void sub_080121CC(void);
static s32 sub_080121F0(void);
static void setup_battle_result_sprite(void);
static void sub_08012468(void);
static void setup_battle_result_sprite_animation(void);
static void calc_average_bot_stat_080125B4(void);
static void accumulate_alive_bot_score(void);
static void calc_average_bot_stat_0801264C(void);
static void calc_medaforce_gauge_from_damage(void);
static void sub_0801275C(void);
static void battle_check_medal_level_up(void);

// Game state 6, "Get ready to Robattle" (runtime-checked from the debug Battle entry): sub-states 0-5
// flash a mosaic over the field three times, 6-7 wipe the screen in stripes, 8 loads the encounter,
// 9 loads the pre-battle screen graphics.
void prebattle_screen_update(void) {
    u32 fill;

    if (gUnk_03000430 == 2) {
        fill = 0x200;
        DmaSet(3, &fill, gUnk_03002414->unkB84, 0x85000100);
    }
    gPrebattleScreenHandlers[gGameSubState]();
}

void prebattle_mosaic_start(void) {
    REG_BG0CNT |= 0x40;
    REG_BG1CNT |= 0x40;
    REG_BG2CNT |= 0x40;
    REG_BG3CNT |= 0x40;
    play_song(8);
    gUnk_03000440.unk85 = 0;
    gGameSubState++;
}

void prebattle_mosaic_grow_init(void) {
    gUnk_03000440.unk84 = 0;
    gGameSubState++;
}

void prebattle_mosaic_grow(void) {
    REG_MOSAIC = gUnk_03000440.unk84 + (gUnk_03000440.unk84 << 4);
    gUnk_03000440.unk84 += 2;
    if (gUnk_03000440.unk84 == 16)
        gGameSubState = 5;
}

void prebattle_mosaic_shrink_init(void) {
    gUnk_03000440.unk84 = 16;
    gGameSubState++;
}

void prebattle_mosaic_shrink(void) {
    u32 v = gUnk_03000440.unk84 - 2;

    gUnk_03000440.unk84 = v;
    REG_MOSAIC = gUnk_03000440.unk84 + (gUnk_03000440.unk84 << 4);
    if ((u8)v == 0)
        gGameSubState = 5;
}

void prebattle_mosaic_repeat(void) {
    if (gUnk_03000440.unk85 <= 2) {
        if (gUnk_03000440.unk85 & 1)
            gGameSubState = 1;
        else
            gGameSubState = 3;
        gUnk_03000440.unk85++;
    } else
        gGameSubState++;
}

void prebattle_wipe_init(void) {
    REG_DISPCNT |= 0x100;
    REG_BG0CNT = 0x500;
    gBg0Scroll.x = 0;
    gBg0Scroll.y = 0;
    lz_decompress_dispatch(gUnk_084C696C, (void *)0x06002600);
    DmaSet(3, gUnk_084C6A78, 0x050001A0, 0x84000008);
    gUnk_03000440.unk3F = 0;
    gUnk_03000440.unk48 = 0;
    gUnk_03000440.unk84 = 0;
    gGameSubState++;
}

void prebattle_wipe(void) {
    s32 start, i;

    if (gUnk_03000440.unk48 <= 4)
        start = 0;
    else
        start = gUnk_03000440.unk48 - 4;
    for (i = start; i <= gUnk_03000440.unk48; i++) {
        if (i <= 14)
            vram_fill_tilemap_rect(1, 20, i, 0, REG_BG0CNT, gUnk_03000440.unk48 - i - 0x2ED0);
    }
    for (i = start; i <= gUnk_03000440.unk48; i++) {
        if (i <= 14)
            vram_fill_tilemap_rect(1, 20, 29 - i, 0, REG_BG0CNT, gUnk_03000440.unk48 - i - 0x2ED0);
    }
    if (++gUnk_03000440.unk48 > 19)
        gGameSubState++;
}

void prebattle_load_encounter(void) {
    u32 zero0, zero1;

    load_encounter_into_battle_setup();
    gUnk_03000440.unk132 = 0;
    zero0 = 0;
    CpuFastSet(&zero0, (void *)0x05000200, 0x01000080);
    zero1 = 0;
    CpuFastSet(&zero1, (void *)0x05000000, 0x01000080);
    gGameSubState++;
}

void prebattle_load_gfx(void) {
    u32 zero;

    sub_08043CA8();
    REG_DISPCNT &= 0xE0FF;
    REG_BG0CNT = 0x500;
    REG_BG1CNT = 0x1801;
    REG_BG2CNT = 0x590A;
    REG_BG3CNT = 0x5B0B;
    lz_decompress_dispatch(gUnk_084E6C9C, (void *)0x06004000);
    lz_decompress_dispatch(gUnk_084C48B4, (void *)0x06006000);
    lz_decompress_dispatch(gUnk_084C4A34, (void *)0x06006200);
    lz_decompress_dispatch(gUnk_084C7D10, (void *)0x06012800);
    lz_decompress_dispatch(gUnk_084C6A98, (void *)0x06017400);
    vram_fill_tilemap_rect(32, 32, 0, 0, REG_BG0CNT, 0);
    vram_fill_tilemap_rect(32, 32, 0, 0, REG_BG1CNT, 0);
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
    zero = 0;
    DmaSet(3, &zero, gUnk_03002C30, 0x85000800);
    REG_DISPCNT |= 0x1F60;
    prebattle_draw_opponent_name();
    prebattle_draw_battlefield_name();
    load_opponent_medabot_sprites();
    init_opponent_medabot_sprites();
    draw_opponent_leg_type_icons();
    prebattle_init_rubberobo_sprite();
    sub_080121A8();
    apply_battle_blend_effect_a();
    gUnk_03000440.unk84 = 0;
    gGameSubState++;
}

// guess: fades the sprites in from white (state 6 sub 10)
void sub_08010794(void) {
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    if (gUnk_03000440.unk84 <= 8) {
        blend_obj_palettes_to_color_0803F684(0, 32 - gUnk_03000440.unk84 * 4, 0xFFFF);
        blend_obj_palettes_to_color_0803F998(0, 32 - gUnk_03000440.unk84 * 4, 0xFFFF);
        gUnk_03000440.unk84++;
    } else
        gGameSubState++;
}

void prebattle_open_text_window(void) {
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    text_window_init(1, 0, 0);
    gGameSubState++;
}

void prebattle_show_opponent_line(void) {
    update_scroll_movement_a();
    if (run_message(gUnk_083C2BBC[gUnk_03001800.unk0])) {
        update_all_battle_sprite_orbits();
        gUnk_03000440.unk84 = 8;
        gUnk_03000440.unk85 = 8;
        gGameSubState++;
    }
    update_all_battle_sprite_orbits();
}

// START (with a Rubberobo Medal, item 50, outside debug battles) asks to use it; A starts the battle
void prebattle_wait_for_start_input(void) {
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    if ((KEYS_LO(gNewKeys) & 8) && get_item_quantity_by_id(50) && gUnk_030057E0.unkC2D == 0) {
        play_sound_effect(4);
        gGameSubState++;
    } else if (KEYS_LO(gNewKeys) & 1) {
        play_sound_effect(4);
        gGameSubState = 32;
    }
}

void sub_080108D0(void) {
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    if (game_state_execute_handler_a()) {
        text_window_init(1, 2, 0);
        gGameSubState++;
    }
}

void prebattle_rubberobo_ask(void) {
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    if (run_message(gUnk_083B53F8[20])) {
        open_choice_menu(1, 22, 7);
        gGameSubState++;
    }
}

void prebattle_rubberobo_choice(void) {
    u32 r;

    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    r = poll_choice_menu();
    if (r) {
        if ((r >> 4) == 0) {
            sub_0803FB0C();
            gGameSubState++;
        } else
            gGameSubState = 32;
    }
}

void prebattle_rubberobo_use(void) {
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    if (run_message(gUnk_083B53F8[21])) {
        sound_stop_all_with_fade_guard(8);
        sub_08042318(50, 1);
        gGameSubState++;
    }
}

void sub_080109A0(void) {
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    copy_obj_palette_to_buffer();
    gUnk_03000440.unk84 = 0;
    gGameSubState++;
}

void sub_080109CC(void) {
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    if (gUnk_03000440.unk84 <= 8) {
        blend_obj_palettes_to_color_0803F684(0, gUnk_03000440.unk84 * 4, 0xFFFF);
        blend_obj_palettes_to_color_0803F998(0, gUnk_03000440.unk84 * 4, 0xFFFF);
        gUnk_03000440.unk84++;
    } else
        gGameSubState++;
}

void sub_08010A20(void) {
    set_blend_effect_mode(0, 0, 0);
    vram_fill_tilemap_rect(32, 32, 0, 0, REG_BG0CNT, 0);
    vram_fill_tilemap_rect(32, 32, 0, 0, REG_BG1CNT, 0);
    clear_battle_sprite_slot(0, 0x80);
    gGameSubState++;
}

void sub_08010A7C(void) {
    update_battle_field_frame();
    sub_080487E4();
    setup_blend_effect(0x40, 0x2F00, 5, 16, 16, 16, 12, 10, 0);
    gUnk_03000440.unk84 = 0;
    gGameSubState++;
}

// guess: Rubberobo Medal used: fade to white, then skip the battle
void sub_08010AC8(void) {
    if (gUnk_03000440.unk84 <= 16) {
        blend_effect_update();
        blend_obj_palettes_to_color_0803F684(0, 32 - gUnk_03000440.unk84 * 2, 0xFFFF);
        blend_obj_palettes_to_color_0803F998(0, 32 - gUnk_03000440.unk84 * 2, 0xFFFF);
        gUnk_03000440.unk84++;
    } else {
        gVBlankCallback = nullsub_08000840;
        sub_08044094();
    }
}

// A on the pre-battle screen: Medabots screen in team select mode (game state 3, unk50 = 2)
void prebattle_open_team_select(void) {
    sub_0803F624(&gUnk_03000440.unk50, 0x14, 0);
    gUnk_03000440.unk50 = 2;
    gGameState = 3;
    gGameSubState = 0;
}

// Game state 6 sub-states 48+ = after the Robattle (runtime-checked from a debug battle,
// re/scratch/afterbattle_probe.txt): 53 opponent line, 55-61 Medapart won (START = details),
// 64-65 experience, 66+ Medal level-ups and Medaforces per team member (unk186)
void afterbattle_count_battle(void) {
    sub_0801BF64(&gUnk_03002B84[0], 9999);
    if (gUnk_03000440.unk9C == 1) {
        sub_0801BF64(&gUnk_03002B84[1], 9999);
        play_song(14);
    } else
        play_song(15);
    gGameSubState++;
}

void afterbattle_check_won(void) {
    update_scroll_movement_a();
    if (gUnk_03000440.unk9C == 1)
        gGameSubState++;
    else
        gGameSubState = 0x70;
}

void afterbattle_show_opponent_line(void) {
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    if (run_message(gUnk_083C3984[gUnk_03001800.unk0]) && (KEYS_LO(gNewKeys) & 3)) {
        gUnk_03000440.unk1B = 0;
        play_sound_effect(13);
        gGameSubState++;
    }
}

void sub_08010C28(void) {
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    if (game_state_execute_handler_b()) {
        sub_0803FB0C();
        gGameSubState++;
    }
}

void afterbattle_give_part(void) {
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    if (gUnk_030057E0.unkC2E & 0xF) {
        gUnk_030057E0.unkC2E = 0;
        gGameSubState = 62;
    } else {
        sub_080121CC();
        if (sub_08042114(gUnk_03001800.unk169, gUnk_03001800.unk168))
            gUnk_03001800.unk16A = 0;
        else
            gUnk_03001800.unk16A = 1;
        medapart_add_quantity(gUnk_03001800.unk169, gUnk_03001800.unk168, 1);
        gGameSubState++;
    }
}

void afterbattle_load_part_name(void) {
    const u32 *tbl;

    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    setup_battle_result_sprite_animation();
    memcpy_bytes_0803F63C(gUnk_083C6DE8[gUnk_03001800.unk168], gUnk_03000440.unk9E, 14);
    tbl = gUnk_083BB9CC[0];
    memcpy_bytes_0803F63C((const void *)tbl[gUnk_03001800.unk169 * 4 + gUnk_03001800.unk168], gUnk_03000440.unk9E + 20,
                          15);
    gGameSubState++;
}

void afterbattle_show_part_acquired(void) {
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    setup_battle_result_sprite();
    if (run_message(gUnk_083C65C4[107])) {
        if (gUnk_03001800.unk16A)
            gGameSubState++;
        else
            gGameSubState = 60;
    }
}

// guess: new Medapart: "NEW" sprite (sprite 1, sound 0x2A)
void sub_08010DAC(void) {
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

void sub_08010E50(void) {
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    setup_battle_result_sprite();
    if (advance_sprite_anim_frame(1, 0))
        gGameSubState++;
}

void sub_08010E7C(void) {
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

void afterbattle_part_details_input(void) {
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    setup_battle_result_sprite();
    sub_08012468();
    if (KEYS_LO(gNewKeys) & 3) {
        clear_battle_sprite_slot(1, 2);
        gUnk_03000430 = 0;
        play_sound_effect(13);
        gGameSubState++;
    } else if (KEYS_LO(gNewKeys) & 8) {
        play_sound_effect(4);
        gGameSubState = 0x60;
    }
}

void sub_08010F6C(void) {
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    if (gUnk_03001800.unk1) {
        sub_0803FB0C();
        gGameSubState++;
    } else
        gGameSubState = 0x40;
}

void sub_08010FA4(void) {
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    if (run_message(gUnk_083C65C4[118])) {
        item_add_quantity(50, 1);
        gGameSubState++;
    }
}

void afterbattle_load_experience(void) {
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    calculate_battle_score_summary();
    divide_by_100000_b(gUnk_03000440.unk9E, gUnk_03001800.unk16C, 0x35);
    sub_0803FB0C();
    gGameSubState++;
}

void afterbattle_show_experience(void) {
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    if (run_message(gUnk_083C65C4[109]))
        gGameSubState++;
}

void afterbattle_start_medal_level_up(void) {
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    battle_check_medal_level_up();
    gUnk_03001800.unk186 = 0;
    gGameSubState++;
}

void sub_08011078(void) {
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    if (gUnk_03001800.unk186 == 3) {
        gUnk_03001800.unk186 = 0;
        gGameSubState = 0x47;
    } else if (gUnk_03001800.unk16E[gUnk_03001800.unk186][0]) {
        sub_0803FB0C();
        memcpy_bytes_0803F63C((const void *)gUnk_083B6410[gUnk_03001800.unk16E[gUnk_03001800.unk186][0] - 1],
                              gUnk_03000440.unk9E, 11);
        play_song(16);
        gGameSubState++;
    } else
        gUnk_03001800.unk186++;
}

void sub_080110FC(void) {
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    if (run_message(gUnk_083C65C4[119]))
        gGameSubState++;
}

void sub_0801112C(void) {
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    gUnk_03001800.unk186++;
    gGameSubState = 0x43;
}

void sub_08011158(void) {
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    if (gUnk_03001800.unk186 == 3) {
        gUnk_03001800.unk186 = 0;
        gGameSubState = 0x4B;
    } else if (gUnk_03001800.unk16E[gUnk_03001800.unk186][6]) {
        sub_0803FB0C();
        memcpy_bytes_0803F63C((const void *)gUnk_083B6410[gUnk_03001800.unk16E[gUnk_03001800.unk186][0] - 1],
                              gUnk_03000440.unk9E, 11);
        memcpy_bytes_0803F63C((const void *)gUnk_083B7338[gUnk_03001800.unk16E[gUnk_03001800.unk186][7]],
                              gUnk_03000440.unk9E + 20, 17);
        play_song(16);
        gGameSubState++;
    } else
        gUnk_03001800.unk186++;
}

void sub_0801120C(void) {
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    if (run_message(gUnk_083C65C4[120]))
        gGameSubState++;
}

void sub_0801123C(void) {
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    gUnk_03001800.unk186++;
    gGameSubState = 0x47;
}

void sub_08011268(void) {
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    if (gUnk_03001800.unk186 == 3) {
        gUnk_03001800.unk186 = 0;
        gGameSubState = 0x58;
    } else if (gUnk_03001800.unk16E[gUnk_03001800.unk186][1])
        gGameSubState++;
    else
        gUnk_03001800.unk186++;
}

void sub_080112C4(void) {
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    copy_obj_palette_to_buffer();
    gUnk_03000440.unk84 = 0;
    gGameSubState++;
}

void sub_080112F0(void) {
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    if (gUnk_03000440.unk84 <= 8) {
        blend_obj_palettes_to_color_0803F684(0, gUnk_03000440.unk84 * 4, 0xFFFF);
        blend_obj_palettes_to_color_0803F998(0, gUnk_03000440.unk84 * 4, 0xFFFF);
        gUnk_03000440.unk84++;
    } else
        gGameSubState++;
}

void sub_08011344(void) {
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

void sub_08011490(void) {
    if (gUnk_03001800.unk186 == 3) {
        gUnk_03001800.unk186 = 0;
        gGameSubState = 0x5B;
    } else if (gUnk_03001800.unk16E[gUnk_03001800.unk186][1])
        gGameSubState = 0x4E;
    else
        gUnk_03001800.unk186++;
}

void sub_080114E0(void) {
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    sound_stop_all_with_fade_guard(8);
    gGameSubState++;
}

void sub_08011500(void) {
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
void afterbattle_part_detail_init_fade(void) {
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    setup_battle_result_sprite();
    sub_08012468();
    copy_obj_palette_to_buffer();
    gUnk_03000440.unk84 = 0;
    gGameSubState++;
}

void afterbattle_part_detail_fade_out(void) {
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    setup_battle_result_sprite();
    sub_08012468();
    if (gUnk_03000440.unk84 <= 8) {
        blend_obj_palettes_to_color_0803F684(0, gUnk_03000440.unk84 * 4, 0xFFFF);
        blend_obj_palettes_to_color_0803F998(0, gUnk_03000440.unk84 * 4, 0xFFFF);
        gUnk_03000440.unk84++;
    } else
        gGameSubState++;
}

void afterbattle_part_detail_save_screen(void) {
    DmaSet(3, 0x06002800, gUnk_02020800, 0x84000200);
    DmaSet(3, 0x06000280, 0x02021000, 0x84000380);
    DmaSet(3, gUnk_03002C30, 0x02028000, 0x84000800);
    set_blend_effect_mode(5, 0x3F, 0x20);
    gVBlankCallback = nullsub_08000840;
    gGameSubState++;
}

// Guess: START on "Medapart was acquired": open the Medaparts detail page (game state 5 sub 0x10) of the
// won part (gUnk_03001800.unk168 = part kind, unk169 = part id).
void sub_080116C4(void) {
    struct Unk_03000440 *g;
    struct Unk_03001800 *b;
    u8 kind;

    sub_08043CA8();
    clear_battle_sprite_slot(0, 0x80);
    g = &gUnk_03000440;
    g->unk96 = 0;
    gUnk_03000430 = 0;
    b = &gUnk_03001800;
    kind = b->unk168;
    switch (kind) {
    case 0:
        sub_0803F624(&g->unk3C, 0x14, 0);
        g->unk3C = 2;
        g->unk3D = b->unk169;
        g->unk3E = kind;
        gGameState = 5;
        gGameSubState = 0x10;
        break;
    case 1:
        sub_0803F624(&g->unk3C, 0x14, 0);
        g->unk3C = 2;
        g->unk3D = b->unk169;
        g->unk3E = kind;
        gGameState = 5;
        gGameSubState = 0x10;
        break;
    case 2:
        sub_0803F624(&g->unk3C, 0x14, 0);
        g->unk3C = 2;
        g->unk3D = b->unk169;
        g->unk3E = kind;
        gGameState = 5;
        gGameSubState = 0x10;
        break;
    case 3:
        sub_0803F624(&g->unk3C, 0x14, 0);
        g->unk3C = 2;
        g->unk3D = b->unk169;
        g->unk3E = kind;
        gGameState = 5;
        gGameSubState = 0x10;
        break;
    }
}

void afterbattle_part_detail_restore_screen(void) {
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
    memcpy_bytes_0803F63C((const void *)tbl[gUnk_03001800.unk169 * 4 + gUnk_03001800.unk168], gUnk_03000440.unk9E + 20,
                          15);
    gUnk_03000440.unk84 = 0;
    gGameSubState++;
}

void afterbattle_part_detail_fade_in(void) {
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    setup_battle_result_sprite();
    sub_08012468();
    if (gUnk_03000440.unk84 <= 8) {
        blend_obj_palettes_to_color_0803F684(0, 32 - gUnk_03000440.unk84 * 4, 0xFFFF);
        blend_obj_palettes_to_color_0803F998(0, 32 - gUnk_03000440.unk84 * 4, 0xFFFF);
        gUnk_03000440.unk84++;
    } else
        gGameSubState++;
}

void afterbattle_part_detail_return(void) {
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    setup_battle_result_sprite();
    sub_08012468();
    gGameSubState = 0x3D;
}

// Sub-states 0x70+: lost Robattle ("You lost the Robattle").
void afterbattle_show_lost_message(void) {
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    if (run_message(gUnk_083C65C4[110])) {
        gUnk_03000440.unk1B = 0;
        gGameSubState++;
    }
}

// guess: 0x71, waits for a handler, then 0x72 (fade out) if unkC2F else 0x77 (a Medapart is taken)
void sub_08011B18(void) {
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    if (game_state_execute_handler_b()) {
        if (gUnk_030057E0.unkC2F)
            gGameSubState++;
        else
            gGameSubState = 0x77;
    }
}

void afterbattle_fade_to_white(void) {
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    if (gUnk_03000440.unk84 <= 8) {
        blend_obj_palettes_to_color_0803F684(0x7FFF, gUnk_03000440.unk84 * 4, 0xFFFF);
        blend_obj_palettes_to_color_0803F998(0x7FFF, gUnk_03000440.unk84 * 4, 0xFFFF);
        gUnk_03000440.unk84++;
    } else
        gGameSubState++;
}

void afterbattle_exit_to_field(void) {
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
void battle_loss_take_part(void) {
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    if (gUnk_030057E0.unkC2E & 0xF) {
        gUnk_030057E0.unkC2E = 0;
        gGameSubState = 0x40;
    } else {
        sub_080122F4(0);
        sub_080421B4(gUnk_03000590[gUnk_03001800.unk187].unk47, gUnk_03001800.unk168);
        sub_0803FB0C();
        gGameSubState++;
    }
}

void battle_loss_show_part_taken(void) {
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    setup_battle_result_sprite();
    if (run_message(gUnk_083C65C4[108]) && (KEYS_LO(gNewKeys) & 3)) {
        gUnk_03000430 = 0;
        play_sound_effect(13);
        gGameSubState++;
    }
}

// guess: sub_080440B4() nonzero = a Medabot is still assembled
void battle_loss_check_team(void) {
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    if (sub_080440B4())
        gGameSubState = 0x40;
    else {
        sub_0803FB0C();
        gGameSubState++;
    }
}

void battle_loss_show_no_medabots(void) {
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    if (run_message(gUnk_083C65C4[111]))
        gGameSubState = 0x72;
}

static void load_encounter_into_battle_setup(void) {
    u32 zero = 0;

    DmaSet(3, &zero, &gUnk_03001800, 0x85000100);
    load_area_battlefield();
    setup_random_encounter_enemies();
}

void load_area_battlefield(void) {
    memcpy_bytes_08041D04(gUnk_083BEA90[gUnk_030057E0.unk7FE], &gUnk_03000440.unkEE, 2);
    gUnk_03001800.unk38 = (&gUnk_03000440.unkEE)[1];
}

// Picks the encounter (area table unless a debug battle set unkC2A), copies its setup and re-rolls
// each opponent part with random_pick_weighted4 unless the setup has fixed parts (unk3).
void setup_random_encounter_enemies(void) {
    struct Unk_030057E0 *st;
    u8 flag;
    u32 r;
    u8 id;
    u32 i;
    u8 a, b, c, d;

    flag = gUnk_030057E0.unkC2D;
    st = &gUnk_030057E0;
    if (!flag) {
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
    if (!gUnk_03001800.unk3) {
        for (i = 0; i < 3; i++) {
            a = random_pick_weighted4(gUnk_03001800.unk4[i].parts[0], gUnk_03001800.unk4[i].parts[1],
                                      gUnk_03001800.unk4[i].parts[2], gUnk_03001800.unk4[i].parts[3]);
            b = random_pick_weighted4(gUnk_03001800.unk4[i].parts[0], gUnk_03001800.unk4[i].parts[1],
                                      gUnk_03001800.unk4[i].parts[2], gUnk_03001800.unk4[i].parts[3]);
            c = random_pick_weighted4(gUnk_03001800.unk4[i].parts[0], gUnk_03001800.unk4[i].parts[1],
                                      gUnk_03001800.unk4[i].parts[2], gUnk_03001800.unk4[i].parts[3]);
            d = random_pick_weighted4(gUnk_03001800.unk4[i].parts[0], gUnk_03001800.unk4[i].parts[1],
                                      gUnk_03001800.unk4[i].parts[2], gUnk_03001800.unk4[i].parts[3]);
            gUnk_03001800.unk4[i].parts[0] = a;
            gUnk_03001800.unk4[i].parts[1] = b;
            gUnk_03001800.unk4[i].parts[2] = c;
            gUnk_03001800.unk4[i].parts[3] = d;
        }
    }
}

// Returns a, b, c or d with 40/30/20/10% probability.
u32 random_pick_weighted4(u32 a, u32 b, u32 c, u32 d) {
    u32 r = sub_08043C94();

    if (r < 40)
        return a;
    if (r < 70)
        return b;
    if (r < 90)
        return c;
    return d;
}

static void prebattle_draw_opponent_name(void) {
    memcpy_bytes_0803F63C(gUnk_083C3F38[gUnk_03001800.unk0], gUnk_03000440.unk9E, 18);
    render_text_sprites_08040EE4(gUnk_03000440.unk9E, 10, 18, 3, 10, 13, 0, 1, 0, -4);
}

static void prebattle_draw_battlefield_name(void) {
    memcpy_bytes_0803F63C(gUnk_083BE9E8[gUnk_03001800.unk38], gUnk_03000440.unk9E, 11);
    render_text_sprites_08040DB8(gUnk_03000440.unk9E, 30, 1, 3, 8, 12, 0, 1);
}

static void load_opponent_medabot_sprites(void) {
    u32 i;

    for (i = 0; i < gUnk_03001800.unk2; i++)
        decompress_sprite_to_vram_08042D94(gUnk_03001800.unk4[i].parts[0], gUnk_03001800.unk4[i].parts[1],
                                           gUnk_03001800.unk4[i].parts[2], gUnk_03001800.unk4[i].parts[3], i);
}

void init_opponent_medabot_sprites(void) {
    u32 i;

    for (i = 0; i < gUnk_03001800.unk2; i++) {
        init_battle_medabot_sprites(gUnk_03001800.unk4[i].parts[0], gUnk_03001800.unk4[i].parts[1],
                                    gUnk_03001800.unk4[i].parts[2], gUnk_03001800.unk4[i].parts[3], i, 40 + i * 4,
                                    gUnk_083ACEE4[i][0], gUnk_083ACEE4[i][1], 1, 1, 0);
        battle_sprite_set_palette_index(40 + i * 4, 8);
    }
}

static void update_all_battle_sprite_orbits(void) {
    u32 i;

    for (i = 0; i < gUnk_03001800.unk2; i++)
        update_battle_sprite_orbiting_positions(40 + i * 4, i, 1);
}

void draw_opponent_leg_type_icons(void) {
    u32 i;

    for (i = 0; i < 3; i++) {
        if (gUnk_03001800.unk2 > i) {
            load_part_data(gUnk_03001800.unk4[i].parts[3], 3, &gUnk_03000440.unkEE);
            draw_tilemap_with_offset((&gUnk_03000440.unkEE)[1] - 100, gUnk_083ACEEA[i][0], gUnk_083ACEEA[i][1],
                                     REG_BG0CNT, 0x8300);
        } else
            draw_tilemap_with_offset(0xFF, gUnk_083ACEEA[i][0], gUnk_083ACEEA[i][1], REG_BG0CNT, 0x8300);
    }
}

// Shows sprite 0 when the player owns a Rubberobo Medal (item 50) outside debug battles.
static void prebattle_init_rubberobo_sprite(void) {
    if (!gUnk_03000440.unk132 && get_item_quantity_by_id(50) && !gUnk_030057E0.unkC2D) {
        gUnk_03002C30[0].unk0 = 0xC404;
        gUnk_03002C30[0].unk2 = 8;
        gUnk_03002C30[0].unk4 = 0x50;
        gUnk_03002C30[0].unkA = 11;
        gUnk_03002C30[0].unkB = 0xC0;
        gUnk_03002C30[0].unk6 = 0x700;
    }
}

// guess: battlefield parameters
void sub_080121A8(void) {
    memcpy_bytes_0803F63C(gUnk_083C3B04[gUnk_03001800.unk38], gUnk_03001800.unk39, 8);
}

// guess: chooses the won Medapart: sub_080121F0 (10 per destroyed opponent part) against a 0-100 roll,
// then sub_08012234 (a part the player doesn't own yet), else any opponent part (sub_080122F4(3)).
static void sub_080121CC(void) {
    s32 n = sub_080121F0();

    if (n < sub_08043C94() || !sub_08012234())
        sub_080122F4(3);
}

// Guess: 10 points per broken (armor 0) arm / legs part of the present opponents (records 3-5).
static s32 sub_080121F0(void) {
    s32 sum = 0;
    u32 i = 0, j, k;
    struct Unk_03000590 *base = gUnk_03000590;
    u8 *armor = &base->parts[0].unk11;
    u8 *p;

loop:
    k = (i + 3) << 8;
    if (!*((u8 *)base + 0xBA + k))
        goto end;
    j = 1;
    i++;
    p = (u8 *)(k + (u32)armor) + 0x18;
inner:
    if (!*p)
        sum += 10;
    p += 0x18;
    j++;
    if (j <= 3)
        goto inner;
    if (i <= 2)
        goto loop;
end:
    return sum;
}

u32 sub_08012234(void) {
    u32 slot, n, j, part, k;
    u8 *p;
    struct Unk_03000590 *bb;

    slot = gUnk_083ACEF0[rng_next_080424B8() & 0xF];
    for (n = 0; n < 3; n++) {
        register struct Unk_03000590 *base asm("r5") = gUnk_03000590;
        if (base[k = slot + 3].unkBA) {
            part = rng_next_080424B8() & 3;
            for (j = 0, bb = base; j < 4; j++) {
                p = (u8 *)(part * 24 + ((slot + 3) << 8) + (u32)bb) + 0x5F;
                if (!sub_08042114(*p, part)) {
                    gUnk_03001800.unk168 = part;
                    gUnk_03001800.unk169 = *p;
                    return 1;
                }
                part = (part + 1) & 3;
            }
        }
        if (slot == 2)
            slot = 0;
        else
            slot++;
    }
    return 0;
}

void sub_080122F4(u32 a) {
    u32 slot, dir, i, k;

    slot = gUnk_083ACEF0[rng_next_080424B8() & 0xF];
    dir = rng_next_080424B8() & 1;
    for (i = 0; i < 3; i++) {
        k = a + slot;
        if (gUnk_03000590[k].unkBA) {
            gUnk_03001800.unk168 = rng_next_080424B8() & 3;
            gUnk_03001800.unk169 = gUnk_03000590[k].parts[gUnk_03001800.unk168].unk17;
            gUnk_03001800.unk187 = k;
            return;
        }
        if (dir) {
            if (++slot > 2)
                slot = 0;
        } else {
            if (slot == 0)
                slot = 2;
            else
                slot--;
        }
    }
}

static void setup_battle_result_sprite(void) {
    switch (gUnk_03001800.unk168) {
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

static void sub_08012468(void) {
    if (gUnk_03001800.unk16A) {
        if (!gUnk_03002C30[1].unk28) {
            if ((u8)(gUnk_03002C30[1].unk9 += 2) == 0x80)
                gUnk_03002C30[1].unk28 = 1;
        } else {
            if ((u8)(gUnk_03002C30[1].unk9 -= 2) == 0x40)
                gUnk_03002C30[1].unk28 = 0;
        }
    }
}

static void setup_battle_result_sprite_animation(void) {
    init_scene_buffers_080445F4();
    switch (gUnk_03001800.unk168) {
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
void calculate_battle_score_summary(void) {
    gUnk_03001800.unk16C = 0;
    calc_average_bot_stat_080125B4();
    accumulate_alive_bot_score();
    calc_average_bot_stat_0801264C();
    calc_medaforce_gauge_from_damage();
    sub_0801275C();
    accumulate_team_armor_stats();
}

static void calc_average_bot_stat_080125B4(void) {
    u32 sum = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03000590[i + 3].unkBA)
            sum += gUnk_03000590[i + 3].medal.unk5;
    }
    gUnk_03001800.unk16C += sum / 3;
}

static void accumulate_alive_bot_score(void) {
    u32 n = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03000590[i + 3].unkBA)
            n++;
    }
    gUnk_03001800.unk16C += n * 8;
}

static void calc_average_bot_stat_0801264C(void) {
    u32 opp = 0;
    u32 team = 0;
    u32 i;
    u32 nopp;
    u32 nteam;

    for (i = 0, nopp = 0; i <= 2; i++) {
        if (gUnk_03000590[i + 3].unkBA) {
            opp += gUnk_03000590[i + 3].medal.unk5;
            nopp++;
        }
    }
    opp = opp / nopp;
    for (i = 0, nteam = 0; i <= 2; i++) {
        if (gUnk_03000590[i].unkBA) {
            team += gUnk_03000590[i].medal.unk5;
            nteam++;
        }
    }
    team = team / nteam;
    if (team < opp)
        gUnk_03001800.unk16C += (opp - team) * (nopp << 4);
}

static void calc_medaforce_gauge_from_damage(void) {
    u32 i;
    u32 score;

    for (i = 0, score = 0; i <= 2; i++) {
        if (gUnk_03000590[i + 3].unkBA) {
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

static void sub_0801275C(void) {
    gUnk_03001800.unk16C += gUnk_03001800.unk16B * 5;
}

void accumulate_team_armor_stats(void) {
    u32 i;
    u32 sum;

    for (i = 0, sum = 0; i <= 2; i++) {
        if (gUnk_03000590[i + 3].unkBA) {
            sum += gUnk_03000590[i + 3].parts[0].data[0xA];
            sum += gUnk_03000590[i + 3].parts[1].data[0xA];
            sum += gUnk_03000590[i + 3].parts[2].data[0xA];
            sum += gUnk_03000590[i + 3].parts[3].data[0xA];
        }
    }
    gUnk_03001800.unk16C += sum;
}

static void battle_check_medal_level_up(void) {
    u32 i;
    struct Unk_03000BE0 *medal;
    u32 variant;
    u32 slot;

    sub_0803F624(&gUnk_03001800.unk16E[0][0], 0x18, 0);
    for (i = 0; i <= 2; i++) {
        if (!gUnk_03000590[i].unkBA)
            continue;
        slot = find_medal_slot_by_id(gUnk_03000590[i].medal.unk1) - 1;
        {
            struct Unk_03000BE0 *medals = gUnk_03000BE0;
            medal = &medals[slot];
        }
        if (medal->unk5 == 100)
            continue;
        if (medal->unk2 > gUnk_03001800.unk16C) {
            medal->unk2 -= gUnk_03001800.unk16C;
            continue;
        }
        medal->unk5++;
        medal->unk2 = (medal->unk5 + 1) * 100;
        gUnk_03001800.unk16E[i][0] = medal->unk1 + 1;
        memcpy_bytes_08041D04(gUnk_083B6158[medal->unk1], &gUnk_03000440.unkEE, 16);
        variant = sub_080420C4(medal->unk5, (&gUnk_03000440.unkEE)[3], (&gUnk_03000440.unkEE)[4],
                               (&gUnk_03000440.unkEE)[5], (&gUnk_03000440.unkEE)[6]);
        if (variant != medal->unk8) {
            gUnk_03001800.unk16E[i][1] = 1;
            gUnk_03001800.unk16E[i][2] = medal->unk1;
            gUnk_03001800.unk16E[i][3] = medal->unk8;
            gUnk_03001800.unk16E[i][4] = medal->unk1;
            gUnk_03001800.unk16E[i][5] = variant;
            medal->unk8 = variant;
        }
        memcpy_bytes_08041D04(&gUnk_083B7E0C[medal->unk1 * 3], &gUnk_03000440.unkEE, 3);
        if (medal->unk5 == 10) {
            gUnk_03001800.unk16E[i][6] = 1;
            gUnk_03001800.unk16E[i][7] = (&gUnk_03000440.unkEE)[0];
        }
        if (medal->unk5 == 30) {
            gUnk_03001800.unk16E[i][6] = 1;
            gUnk_03001800.unk16E[i][7] = (&gUnk_03000440.unkEE)[1];
        }
        if (medal->unk5 == 60) {
            gUnk_03001800.unk16E[i][6] = 1;
            gUnk_03001800.unk16E[i][7] = (&gUnk_03000440.unkEE)[2];
        }
    }
}
