// Game state 7: the Robattle itself. robattle_update runs the sub-state machine in gRobattleHandlers:
// battle init, command input on the ring, action commit and execution, the start banner, damage / repair
// number pop-ups. Calls into battle_bots (turn logic), battle_hud, command_ring, part_select and
// status_screen; the action scripts run in game states 8-9.

#include "global.h"

// Game state 7 = Robattle (gGameStateHandlers_083AC148[7]); sub-states in gRobattleHandlers.
void robattle_update(void) {
    u32 fill;

    if (sub_0803EED8())
        return;
    if (gUnk_03000430 == 2) {
        fill = 0x200;
        CpuFastSet(&fill, gSpriteWork->oamBuf, 0x01000100);
    }
    gRobattleHandlers[gGameSubState]();
}

void battle_init_phase(void) {
    gUnk_03000440.unk139 = 0;
    gUnk_03000440.unk13A = 0;
    if (gUnk_03000440.unk89 != 1) {
        clear_battle_bot_array();
        count_active_battle_bots();
        battle_setup_team_bots();
        init_opponent_bots();
    }
    battle_process_all_bots_actions();
    if (gUnk_03000440.unk89 != 1)
        fill_opponent_medaforce_for_battle_type();
    gGameSubState++;
}

void battle_scene_init_state_machine(void) {
    u32 fill;

    switch (gUnk_03000440.unk139) {
    case 0:
        clear_bg_scroll();
        load_battle_script_entry_b();
        REG_DISPCNT &= 0xF0FF;
        REG_BG0CNT = 0x500;
        REG_BG1CNT = 0x1901;
        REG_BG2CNT = 0x1A0A;
        REG_BG3CNT = 0x1B0B;
        if (battle_load_graphics_step(0))
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
        gVBlankCallback = battle_vblank_update_bg;
        gGameSubState++;
        gUnk_03000440.unk139 = 0;
        break;
    }
}

void robattle_fade_in_from_white(void) {
    if (gUnk_03000440.unk84 <= 8) {
        blend_obj_palettes_to_color_0803F684(0, 0x20 - gUnk_03000440.unk84 * 4, 0xFFFF);
        blend_obj_palettes_to_color_0803F998(0, 0x20 - gUnk_03000440.unk84 * 4, 0xFFFF);
        gUnk_03000440.unk84++;
    } else
        gGameSubState++;
}

void sub_08012B94(void) {
    update_all_battle_status_sprites();
    if (gUnk_03000440.unk89 != 1)
        battle_process_bot_actions_for_side(3);
    gGameSubState++;
}

void sub_08012BC0(void) {
    update_all_battle_status_sprites();
    sub_08016370(gUnk_03001800.unk80);
    gGameSubState++;
}

void sub_08012BE4(void) {
    update_all_battle_status_sprites();
    if (sub_08016438(gUnk_03001800.unk80))
        gGameSubState++;
}

void sub_08012C0C(void) {
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
void robattle_command_input(void) {
    update_all_battle_status_sprites();
    animate_battle_sprites(gUnk_03001800.unk80);
    update_battle_sprite_orbiting_positions(gUnk_03001800.unk80 * 4 + 0x5A, gUnk_03001800.unk80, 0);
    command_ring_input();
    sub_080178CC();
    if (gUnk_03001800.unk83)
        return;
    command_ring_pulse_selected();
    if (KEYS_LO(gNewKeys) & 1) {
        if (gUnk_03000440.unk89 == 1 && gUnk_03001800.unk81 == 5) {
            play_sound_effect(6);
            return;
        }
        play_sound_effect(4);
        sub_08017914();
        gUnk_03000440.unk84 = 0;
        gGameSubState++;
    } else if (KEYS_LO(gNewKeys) & 2) {
        if (gUnk_03001800.unk84 == 0 && gUnk_03001800.unk80 != 0) {
            play_sound_effect(5);
            setup_battle_bot_sprite_group(gUnk_03001800.unk80, 0x28, (u8)(gUnk_03001800.unk80 % 3) * 24 + 0x24);
            gUnk_03001800.unk80--;
            draw_battle_panel_left_a(0);
            team_bot_clear_command_kept(gUnk_03001800.unk80);
            gUnk_03001800.unk81 = 0;
            gUnk_03001800.unk82 = 0;
            clear_battle_sprite_slot(0, 0x46);
            vram_fill_tilemap_rect(0x1E, 8, 0, 0xC, REG_BG0CNT, 0);
            vram_fill_tilemap_rect(0x1E, 8, 0, 0xC, REG_BG1CNT, 0);
            gGameSubState = 4;
        }
    }
}

void sub_08012D98(void) {
    update_all_battle_status_sprites();
    animate_battle_sprites(gUnk_03001800.unk80);
    update_battle_sprite_orbiting_positions(gUnk_03001800.unk80 * 4 + 0x5A, gUnk_03001800.unk80, 0);
    sub_08016554();
    if (++gUnk_03000440.unk84 == 20) {
        clear_battle_sprite_slot(0x1E, 0xB);
        gUnk_03000440.unk84 = 0;
        gGameSubState++;
    }
}

void sub_08012DF4(void) {
    update_all_battle_status_sprites();
    animate_battle_sprites(gUnk_03001800.unk80);
    update_battle_sprite_orbiting_positions(gUnk_03001800.unk80 * 4 + 0x5A, gUnk_03001800.unk80, 0);
    sub_080165D0();
    sub_08016614();
    sub_08016660();
    if (++gUnk_03000440.unk84 == 16)
        command_ring_goto_selected();
}

void sub_08012E40(void) {
    update_all_battle_status_sprites();
    animate_battle_sprites(gUnk_03001800.unk80);
    update_battle_sprite_orbiting_positions(gUnk_03001800.unk80 * 4 + 0x5A, gUnk_03001800.unk80, 0);
    decompress_two_bg1_layers();
    command_ring_init_icons_hidden();
    read_vram_tilemap_rect(6, 5, 0xC, 0x15, REG_BG1CNT, gUnk_02020800);
    gUnk_03000440.unk84 = 0;
    gGameSubState++;
}

void sub_08012EA8(void) {
    update_all_battle_status_sprites();
    animate_battle_sprites(gUnk_03001800.unk80);
    update_battle_sprite_orbiting_positions(gUnk_03001800.unk80 * 4 + 0x5A, gUnk_03001800.unk80, 0);
    draw_partial_bg1_column();
    scroll_tilemap_window();
    sub_08016FB4();
    if (++gUnk_03000440.unk84 == 10) {
        command_ring_draw_name();
        gGameSubState = 7;
    }
}

// Stores the chosen command of Medabot unk80 and moves on to the next one (sub-state 4), or to
// sub-state 0x40 (0x90 when unk89 is 1) after the last one.
void robattle_command_commit(void) {
    update_all_battle_status_sprites();
    animate_battle_sprites(gUnk_03001800.unk80);
    update_battle_sprite_orbiting_positions(gUnk_03001800.unk80 * 4 + 0x5A, gUnk_03001800.unk80, 0);
    switch (gUnk_03001800.unk81) {
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
    setup_battle_bot_sprite_group(gUnk_03001800.unk80, 0x28, (u8)(gUnk_03001800.unk80 % 3) * 24 + 0x24);
    gUnk_03001800.unk81 = 0;
    gUnk_03001800.unk82 = 0;
    gUnk_03001800.unk80++;
    if (gUnk_03001800.unk84 == 0) {
        if (gUnk_03001800.unk80 != 3 && gUnk_03001800.unk80 < gUnk_03001800.unk5A)
            gGameSubState = 4;
        else if (gUnk_03000440.unk89 != 1)
            gGameSubState = 0x40;
        else
            gGameSubState = 0x90;
    } else
        gGameSubState++;
}

void sub_08012FF8(void) {
    update_all_battle_status_sprites();
    count_bot_skill_use(gUnk_03001800.unk87);
    init_battle_action_select_ui(0);
    if (gUnk_03000440.unk89 != 1)
        gGameSubState = 0x45;
    else
        gGameSubState = 0xA0;
}

void sub_0801303C(void) {
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

void sub_080130D8(void) {
    update_all_battle_status_sprites();
    animate_battle_sprites(gUnk_03001800.unk80);
    update_battle_sprite_orbiting_positions(gUnk_03001800.unk80 * 4 + 0x5A, gUnk_03001800.unk80, 0);
    sub_080166F0();
    sub_0801672C();
    if (++gUnk_03000440.unk84 == 16) {
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
        target_marker_show();
        gUnk_03000440.unk84 = 0;
        gGameSubState++;
    }
}

// guess: Medaforce panel input (shows "Charge MF"; sub-state 18, B -> 19, A -> 21)
void sub_08013164(void) {
    u8 b;

    update_all_battle_status_sprites();
    animate_battle_sprites(gUnk_03001800.unk80);
    update_battle_sprite_orbiting_positions(gUnk_03001800.unk80 * 4 + 0x5A, gUnk_03001800.unk80, 0);
    target_marker_update();
    gUnk_03000440.unk84++;
    part_select_blink_selected_icon();
    part_select_input();
    part_select_blink_status();
    if ((b = KEYS_LO(gNewKeys) & 2)) {
        play_sound_effect(5);
        clear_battle_sprite_slot(0, 6);
        target_marker_hide();
        clear_battle_sprite_slot(0x14, 0x26);
        vram_fill_tilemap_rect(7, 1, 0xE, 0xC, REG_BG0CNT, 0);
        gUnk_03000440.unk84 = 0;
        gGameSubState++;
    } else if (KEYS_LO(gNewKeys) & 1) {
        play_sound_effect(4);
        target_marker_hide();
        gUnk_03000440.unk86 = 0;
        gGameSubState = 0x15;
    }
}

void sub_08013228(void) {
    update_all_battle_status_sprites();
    animate_battle_sprites(gUnk_03001800.unk80);
    update_battle_sprite_orbiting_positions(gUnk_03001800.unk80 * 4 + 0x5A, gUnk_03001800.unk80, 0);
    save_restore_bg0_tilemap_region();
    save_restore_bg1_tilemap_region();
    if (++gUnk_03000440.unk84 == 16) {
        CpuFastSet(gUnk_084E2F38, (void *)0x05000340, 8);
        gGameSubState = 0xB;
    }
}

void sub_08013288(void) {
    update_all_battle_status_sprites();
    animate_battle_sprites(gUnk_03001800.unk80);
    update_battle_sprite_orbiting_positions(gUnk_03001800.unk80 * 4 + 0x5A, gUnk_03001800.unk80, 0);
    gUnk_03000440.unk84++;
    gUnk_03000440.unk84++;
    part_select_blink_selected_icon();
    part_select_blink_status();
    if (++gUnk_03000440.unk86 == 16) {
        clear_battle_sprite_slot(0, 0x46);
        vram_fill_tilemap_rect(0x1E, 8, 0, 0xC, REG_BG0CNT, 0);
        vram_fill_tilemap_rect(0x1E, 8, 0, 0xC, REG_BG1CNT, 0);
        CpuFastSet(gUnk_084E2F38, (void *)0x05000340, 8);
        gGameSubState = 0xD;
    }
}

void sub_08013330(void) {
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

void sub_080133B8(void) {
    update_all_battle_status_sprites();
    animate_battle_sprites(gUnk_03001800.unk80);
    update_battle_sprite_orbiting_positions(gUnk_03001800.unk80 * 4 + 0x5A, gUnk_03001800.unk80, 0);
    sub_08017048();
    sub_08017084();
    if (++gUnk_03000440.unk84 == 16) {
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

void sub_08013438(void) {
    u8 b;

    update_all_battle_status_sprites();
    animate_battle_sprites(gUnk_03001800.unk80);
    update_battle_sprite_orbiting_positions(gUnk_03001800.unk80 * 4 + 0x5A, gUnk_03001800.unk80, 0);
    gUnk_03000440.unk84++;
    sub_0801767C();
    sub_080175FC();
    sub_080173B4(1);
    if ((b = KEYS_LO(gNewKeys) & 2)) {
        play_sound_effect(5);
        vram_fill_tilemap_rect(8, 1, 1, 0x11, REG_BG0CNT, 0);
        draw_medaforce_gauge_value(gUnk_03001800.unk80);
        clear_battle_sprite_slot(0, 5);
        clear_battle_sprite_slot(0x14, 0x24);
        gUnk_03000440.unk84 = 0;
        gGameSubState++;
    } else if (KEYS_LO(gNewKeys) & 1) {
        play_sound_effect(4);
        gUnk_03000440.unk86 = 0;
        gGameSubState = 0x1D;
    }
}

void sub_08013508(void) {
    update_all_battle_status_sprites();
    animate_battle_sprites(gUnk_03001800.unk80);
    update_battle_sprite_orbiting_positions(gUnk_03001800.unk80 * 4 + 0x5A, gUnk_03001800.unk80, 0);
    save_restore_bg0_tilemap_region();
    sub_08017948();
    if (++gUnk_03000440.unk84 == 16) {
        CpuFastSet(gUnk_084E2F38, (void *)0x05000340, 8);
        gGameSubState = 0xB;
    }
}

void sub_08013568(void) {
    update_all_battle_status_sprites();
    animate_battle_sprites(gUnk_03001800.unk80);
    update_battle_sprite_orbiting_positions(gUnk_03001800.unk80 * 4 + 0x5A, gUnk_03001800.unk80, 0);
    gUnk_03000440.unk84++;
    gUnk_03000440.unk84++;
    sub_0801767C();
    sub_080173B4(1);
    if (++gUnk_03000440.unk86 == 16) {
        clear_battle_sprite_slot(0, 0x46);
        vram_fill_tilemap_rect(0x1E, 8, 0, 0xC, REG_BG0CNT, 0);
        vram_fill_tilemap_rect(0x1E, 8, 0, 0xC, REG_BG1CNT, 0);
        CpuFastSet(gUnk_084E2F38, (void *)0x05000340, 8);
        gGameSubState = 0xD;
    }
}

void sub_08013614(void) {
    update_all_battle_status_sprites();
    animate_battle_sprites(gUnk_03001800.unk80);
    update_battle_sprite_orbiting_positions(gUnk_03001800.unk80 * 4 + 0x5A, gUnk_03001800.unk80, 0);
    text_window_init(1, 2, 0);
    gGameSubState++;
}

void sub_08013650(void) {
    update_all_battle_status_sprites();
    animate_battle_sprites(gUnk_03001800.unk80);
    update_battle_sprite_orbiting_positions(gUnk_03001800.unk80 * 4 + 0x5A, gUnk_03001800.unk80, 0);
    if (run_message(gUnk_083B70AC[gUnk_03000590[gUnk_03001800.unk80].medal.unk6])) {
        gUnk_03000440.unk1B = 0;
        gGameSubState++;
    }
}

void sub_080136B0(void) {
    update_all_battle_status_sprites();
    animate_battle_sprites(gUnk_03001800.unk80);
    update_battle_sprite_orbiting_positions(gUnk_03001800.unk80 * 4 + 0x5A, gUnk_03001800.unk80, 0);
    if (game_state_execute_handler_a())
        gGameSubState = 0xB;
}

void sub_080136E8(void) {
    update_all_battle_status_sprites();
    animate_battle_sprites(gUnk_03001800.unk80);
    update_battle_sprite_orbiting_positions(gUnk_03001800.unk80 * 4 + 0x5A, gUnk_03001800.unk80, 0);
    copy_obj_palette_to_buffer();
    gUnk_03000440.unk84 = 0;
    gGameSubState++;
}

void sub_0801372C(void) {
    update_all_battle_status_sprites();
    animate_battle_sprites(gUnk_03001800.unk80);
    update_battle_sprite_orbiting_positions(gUnk_03001800.unk80 * 4 + 0x5A, gUnk_03001800.unk80, 0);
    if (gUnk_03000440.unk84 <= 8) {
        blend_obj_palettes_to_color_0803F684(0, gUnk_03000440.unk84 * 4, 0xFFFF);
        blend_obj_palettes_to_color_0803F998(0, gUnk_03000440.unk84 * 4, 0xFFFF);
        gUnk_03000440.unk84++;
    } else {
        gGameSubState++;
    }
}

void sub_08013798(void) {
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
void sub_08013824(void) {
    mem_fill8(&gUnk_03000440.unk3C, 0x14, 0);
    gUnk_03000440.unk3C = 2;
    gUnk_03000440.unk3D = find_medal_slot_by_id(gUnk_03000590[gUnk_03001800.unk80].medal.unk1) - 1;
    gUnk_03000440.unk41 = 1;
    gUnk_03000440.unk42 = 2;
    clear_bg_scroll();
    gGameState = 4;
    gGameSubState = 0x28;
}

void battle_phase_dispatch_0801387C(void) {
    u32 fill;

    switch (gUnk_03000440.unk139) {
    case 0:
        gUnk_03000440.unk96 = 0;
        gUnk_03000430 = 0;
        clear_bg_scroll();
        load_battle_script_entry_b();
        REG_DISPCNT &= 0xF0FF;
        REG_BG0CNT = 0x500;
        REG_BG1CNT = 0x1901;
        REG_BG2CNT = 0x1A0A;
        REG_BG3CNT = 0x1B0B;
        if (battle_load_graphics_step(0)) {
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
        gVBlankCallback = battle_vblank_update_bg;
        gGameSubState++;
        gUnk_03000440.unk139 = 0;
        break;
    }
}

void sub_08013A74(void) {
    update_all_battle_status_sprites();
    animate_battle_sprites(gUnk_03001800.unk80);
    update_battle_sprite_orbiting_positions(gUnk_03001800.unk80 * 4 + 0x5A, gUnk_03001800.unk80, 0);
    if (gUnk_03000440.unk84 <= 8) {
        blend_obj_palettes_to_color_0803F684(0, 0x20 - gUnk_03000440.unk84 * 4, 0xFFFF);
        blend_obj_palettes_to_color_0803F998(0, 0x20 - gUnk_03000440.unk84 * 4, 0xFFFF);
        gUnk_03000440.unk84++;
    } else {
        gGameSubState = 0xB;
    }
}

void sub_08013AE4(void) {
    update_all_battle_status_sprites();
    animate_battle_sprites(gUnk_03001800.unk80);
    update_battle_sprite_orbiting_positions(gUnk_03001800.unk80 * 4 + 0x5A, gUnk_03001800.unk80, 0);
    switch (gUnk_03001800.unk80) {
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

void sub_08013B8C(void) {
    u32 fill;

    clear_bg_scroll();
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
    mem_fill8(&gUnk_03000440.unk3C, 0x14, 0);
    gUnk_03000440.unk46 = 1;
    position_battle_team_cursors(0, 0);
    status_init_cursor();
    status_draw_bot_name();
    status_draw_row_icons();
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
    draw_tile_block(2, 2, 0xB, 2, REG_BG1CNT, 0x63C0);
    set_blend_effect_mode(5, 0x3F, 0x20);
    gGameSubState++;
}

void sub_08013DE4(void) {
    status_next_other_slot();
    status_blink_lr_button();
    status_update_portrait();
    status_draw_team_sprites();
    sprite_bob_y(8, gFrameCounter, status_cursor_x());
    scroll_bg3_diagonal();
    if (update_blend_effect())
        gGameSubState++;
}

void sub_08013E30(void) {
    status_next_other_slot();
    status_update_portrait();
    scroll_bg3_diagonal();
    switch (gUnk_03000440.unk3F) {
    case 0:
        status_blink_lr_button();
        status_draw_team_sprites();
        sprite_bob_y(8, gFrameCounter, status_cursor_x());
        status_select_input();
        if ((KEYS_HI(gNewKeys) & 1) && gUnk_03000440.unk3C == 0) {
            play_sound_effect(2);
            status_begin_side_change();
            gUnk_03000440.unk40 = 0;
            gUnk_03000440.unk3F++;
        } else if ((KEYS_HI(gNewKeys) & 2) && gUnk_03000440.unk3C == 1) {
            play_sound_effect(2);
            status_begin_side_change();
            gUnk_03000440.unk40 = 0;
            gUnk_03000440.unk3F++;
        } else if (KEYS_LO(gNewKeys) & 2) {
            play_sound_effect(5);
            set_blend_effect_mode(6, 0x3F, 0x20);
            gGameSubState++;
        }
        break;
    case 1:
        if (status_side_change_scroll_out()) {
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
        set_portrait_parts(gUnk_03001800.unk64[0], gUnk_03001800.unk64[1], gUnk_03001800.unk64[2],
                           gUnk_03001800.unk64[3]);
        status_init_portrait();
        battle_sprite_set_palette_index(0, 8);
        draw_tile_block(2, 2, 0xB, 2, REG_BG1CNT, 0x63C0);
        status_reset_portrait();
        gUnk_03000440.unk3F = 0;
        break;
    }
}

void sub_08013FA8(void) {
    u32 fill1, fill2, fill3;

    status_next_other_slot();
    status_blink_lr_button();
    status_update_portrait();
    status_draw_team_sprites();
    sprite_bob_y(8, gFrameCounter, status_cursor_x());
    scroll_bg3_diagonal();
    if (update_blend_effect()) {
        gUnk_03000440.unk96 = 0;
        gUnk_03000430 = 0;
        fill1 = 0x200;
        CpuFastSet(&fill1, gSpriteWork->oamBuf, 0x01000100);
        fill2 = 0;
        CpuFastSet(&fill2, (void *)0x05000200, 0x01000080);
        fill3 = 0;
        CpuFastSet(&fill3, (void *)0x05000000, 0x01000080);
        gGameSubState = 0x3C;
    }
}

// Robattle sub-state 0x40: loads the "MEDABOTS ROBATTLE" logo sprites, plays sound 0x6E.
void robattle_start_banner_init(void) {
    count_team_skill_uses();
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
void robattle_start_banner(void) {
    switch (gUnk_03000440.unk84) {
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
        if (gUnk_03002C30[3].unk20 == 0) {
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
        if ((gUnk_03002C30[4].unk9 -= 8) == 0x40) {
            gUnk_03000440.unk84++;
            gUnk_03000440.unk86 = 0;
        }
        break;
    default:
        if (++gUnk_03000440.unk86 == 0x3C) {
            clear_battle_sprite_slot(3, 2);
            CpuFastSet(gUnk_0850DDF8, (void *)0x050003E0, 8);
            gGameSubState++;
        }
        break;
    }
}

void sub_0801425C(void) {
    select_battle_music();
    init_battle_action_select_ui(0);
    robattle_time_init();
    gGameSubState = 0x44;
}

// Robattle sub-state 0x44: turn loop (TIME counter on screen); unk55 flags 2/4/8/0x10 -> 0x60/0x68/0x70/0x78.
void sub_0801427C(void) {
    if (gUnk_03001800.unk55 == 0) {
        robattle_time_tick();
        robattle_time_draw();
    }
    if (gUnk_03001800.unk55 & 2)
        gGameSubState = 0x60;
    else if (gUnk_03001800.unk55 & 4)
        gGameSubState = 0x68;
    else if (gUnk_03001800.unk55 & 8)
        gGameSubState = 0x70;
    else if (gUnk_03001800.unk55 & 0x10)
        gGameSubState = 0x78;
    else {
        sub_0801902C();
        update_all_battle_status_sprites();
        init_battle_bot_sprites();
        if (battle_queue_bots_at_lines()) {
            sub_08019078();
            gGameSubState++;
        }
    }
}

void sub_08014314(void) {
    struct Unk_03000590 *rec;
    u8 flag;

    update_all_battle_status_sprites();
    sub_08019078();
    battle_queue_sort();
    if (gUnk_03001800.unk45[0][0] == 0) {
        gGameSubState = 0x44;
        return;
    }
    battle_queue_take_head();
    rec = gUnk_03000590;
    rec += gUnk_03001800.unk87;
    if (rec->unk40 == 0) {
        battle_queue_pop();
    } else if ((flag = rec->unkBD & 4)) {
        gGameSubState = 0x47;
    } else {
        iterate_bots_setup_battle_sprites();
        gGameState = 8;
        gGameSubState = flag;
    }
}

void sub_080143A0(void) {
    update_all_battle_status_sprites();
    gUnk_03000590[gUnk_03001800.unk87].unkBD ^= 4;
    iterate_bots_setup_battle_sprites();
    battle_queue_pop();
    battle_bot_advance_rotation(gUnk_03001800.unk87);
    if (any_bot_extra_move_pending()) {
        mem_fill8(gUnk_03001800.unk45[0], 0xC, 0);
        gGameSubState = 0x4C;
    } else {
        gGameSubState = 0x45;
    }
}

void sub_08014404(void) {
    update_all_battle_status_sprites();
    sub_08019078();
    gUnk_03000590[gUnk_03001800.unk87].unkBD ^= 4;
    setup_battle_bot_sprite_group(gUnk_03001800.unk87, gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk2,
                                  gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 4);
    battle_queue_pop();
    battle_process_all_bot_actions(gUnk_03001800.unk87);
    if (gUnk_03001800.unk87 > 2) {
        if (gUnk_03000440.unk89 != 1) {
            process_bot_battle_turn(gUnk_03001800.unk87);
            gGameSubState = 0x45;
        } else {
            if (gUnk_03000590[gUnk_03001800.unk87].unkC9 == 0x2C)
                process_bot_battle_turn(gUnk_03001800.unk87);
            gGameSubState = 0xA0;
        }
    } else if (gUnk_03000590[gUnk_03001800.unk87].unkC9 == 0x2C) {
        process_bot_battle_turn(gUnk_03001800.unk87);
        count_bot_skill_use(gUnk_03001800.unk87);
        if (gUnk_03000440.unk89 != 1)
            gGameSubState = 0x45;
        else
            gGameSubState = 0xA0;
    } else {
        if (team_bot_command_kept(gUnk_03001800.unk87)) {
            if (!(KEYS_LO(gHeldKeys) & 2)) {
                process_bot_battle_turn(gUnk_03001800.unk87);
                count_bot_skill_use(gUnk_03001800.unk87);
                gGameSubState = 0x45;
                return;
            }
            team_bot_clear_command_kept(gUnk_03001800.unk87);
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

void sub_08014548(void) {
    u32 i;

    update_all_battle_status_sprites();
    init_battle_bot_sprites();
    for (i = 0; i <= 5; i++) {
        struct Unk_03000590 *rec = gUnk_03000590;

        rec += i;
        if (rec->unk40 && rec->unkBF) {
            u32 a, b;

            rec->unkBB = 8;
            battle_bot_move(i);
            sub_08019544(i);
            a = battle_bot_at_front_line(i, 1);
            b = battle_bot_at_home_line(i, 1);
            if (a || b) {
                rec->unkBF = 0;
                gGameSubState = 0x45;
                return;
            }
        }
    }
}

void sub_080145BC(void) {
    u32 i;

    update_all_battle_status_sprites();
    iterate_bots_setup_battle_sprites();
    for (i = 0; i <= 5; i++) {
        if (gUnk_03000590[i].unk40 && (gUnk_03000590[i].unkCE & 1)) {
            gUnk_03002C30[0x46 + i * 3].unk0 |= 0x8220;
            gUnk_03002C30[0x46 + i * 3].unk9 = 0x40;
            gUnk_03002C30[0x46 + i * 3].unk8 = 0x40;
        }
    }
    play_sound_effect(0x37);
    gGameSubState++;
}

void sub_08014634(void) {
    u32 i;

    update_all_battle_status_sprites();
    for (i = 0; i <= 5; i++) {
        if (gUnk_03000590[i].unk40 && (gUnk_03000590[i].unkCE & 1)) {
            gUnk_03002C30[0x46 + i * 3].unk0 |= 0x8000;
            gUnk_03002C30[0x46 + i * 3].unk9 += 4;
            if ((gUnk_03002C30[0x46 + i * 3].unk8 -= 4) == 4) {
                gUnk_03001800.unk55 &= ~2;
                gUnk_03000590[i].unkCE &= ~1;
                clear_battle_sprite_slot(0x46 + i * 3, 1);
            }
        }
    }
    if (!(gUnk_03001800.unk55 & 2))
        gGameSubState = 0x44;
}

void sub_080146DC(void) {
    u32 i;

    update_all_battle_status_sprites();
    iterate_bots_setup_battle_sprites();
    for (i = 0; i <= 5; i++) {
        if (gUnk_03000590[i].unk40 && (gUnk_03000590[i].unkCE & 2)) {
            gUnk_03002C30[0x47 + i * 3].unk0 |= 0x8220;
            gUnk_03002C30[0x47 + i * 3].unk9 = 0x40;
            gUnk_03002C30[0x47 + i * 3].unk8 = 0x40;
        }
    }
    play_sound_effect(0x37);
    gGameSubState++;
}

void sub_08014754(void) {
    u32 i;

    update_all_battle_status_sprites();
    for (i = 0; i <= 5; i++) {
        if (gUnk_03000590[i].unk40 && (gUnk_03000590[i].unkCE & 2)) {
            gUnk_03002C30[0x47 + i * 3].unk0 |= 0x8000;
            gUnk_03002C30[0x47 + i * 3].unk9 += 4;
            if ((gUnk_03002C30[0x47 + i * 3].unk8 -= 4) == 4) {
                gUnk_03001800.unk55 &= ~4;
                gUnk_03000590[i].unkCE &= ~2;
                clear_battle_sprite_slot(0x47 + i * 3, 1);
            }
        }
    }
    if (!(gUnk_03001800.unk55 & 4))
        gGameSubState = 0x44;
}

// Robattle (game state 7) handlers 0x70/0x71 and 0x78/0x79: show a number over each Medabot with
// unkCE bit 2 (unkC8) / bit 3 (unkCD) for 90 frames (guess: damage / repair numbers).
void sub_080147FC(void) {
    u32 i;

    update_all_battle_status_sprites();
    iterate_bots_setup_battle_sprites();
    for (i = 0; i <= 5; i++) {
        if (gUnk_03000590[i].unk40 && (gUnk_03000590[i].unkCE & 4)) {
            set_display_digit_type(&gUnk_03000440.unkEE, gUnk_03000590[i].unkC8, 0);
            battle_number_popup_init(&gUnk_03000440.unkEE, i);
        }
    }
    play_sound_effect(0x5B);
    gUnk_03000440.unk84 = 0;
    gGameSubState++;
}

void sub_08014870(void) {
    u32 i;

    update_all_battle_status_sprites();
    for (i = 0; i <= 5; i++) {
        if (gUnk_03000590[i].unk40 && (gUnk_03000590[i].unkCE & 4))
            battle_number_popup_update(i);
    }
    if (++gUnk_03000440.unk84 == 90) {
        for (i = 0; i <= 5; i++) {
            if (gUnk_03000590[i].unk40 && (gUnk_03000590[i].unkCE & 4)) {
                gUnk_03000590[i].unkCE &= ~4;
                clear_battle_sprite_slot(10 + i * 4, 3);
            }
        }
        gUnk_03001800.unk55 &= ~8;
        gGameSubState = 0x44;
    }
}

void sub_08014920(void) {
    u32 i;

    update_all_battle_status_sprites();
    iterate_bots_setup_battle_sprites();
    for (i = 0; i <= 5; i++) {
        if (gUnk_03000590[i].unk40 && (gUnk_03000590[i].unkCE & 8)) {
            set_display_digit_type(&gUnk_03000440.unkEE, gUnk_03000590[i].unkCD, 1);
            battle_number_popup_init(&gUnk_03000440.unkEE, i);
        }
    }
    play_sound_effect(0x5B);
    gUnk_03000440.unk84 = 0;
    gGameSubState++;
}

void sub_08014994(void) {
    u32 i;

    update_all_battle_status_sprites();
    for (i = 0; i <= 5; i++) {
        if (gUnk_03000590[i].unk40 && (gUnk_03000590[i].unkCE & 8))
            battle_number_popup_update(i);
    }
    if (++gUnk_03000440.unk84 == 90) {
        for (i = 0; i <= 5; i++) {
            if (gUnk_03000590[i].unk40 && (gUnk_03000590[i].unkCE & 8)) {
                gUnk_03000590[i].unkCE &= ~8;
                clear_battle_sprite_slot(10 + i * 4, 3);
            }
        }
        gUnk_03001800.unk55 &= ~0x10;
        gGameSubState = 0x44;
    }
}

// Robattle handlers 0x90-0x99 and 0xA0-0xAF: exchange each side's chosen parts (unkDD) over the
// serial link (gUnk_03005010), guess: link Robattle (only when gUnk_03000440.unk89 = 1).
void sub_08014A44(void) {
    text_window_init(1, 0, 0);
    gGameSubState++;
}

void sub_08014A60(void) {
    if (run_message(gUnk_083CF3B0[1]))
        gGameSubState++;
}

void sub_08014A84(void) {
    if (sub_0803E79C()) {
        gUnk_03005010.unk6 = 0;
        gUnk_03000440.unk86 = 0;
        gGameSubState++;
    }
}

void sub_08014AB4(void) {
    if (gUnk_03000440.unk86 == 16)
        gGameSubState++;
    else
        gUnk_03000440.unk86++;
}

void sub_08014ADC(void) {
    gUnk_03001800.unk51 = 0;
    gUnk_03001800.unk52 = 0;
    gUnk_03001800.unk53 = 0;
    gUnk_03001800.unk54 = 0;
    gUnk_03001800.unk1A6 = 0;
    gUnk_03001800.unk1AF = 0;
    gUnk_03001800.unk1B0 = 1;
    gUnk_03000440.unk86 = 0;
    gGameSubState++;
}

void sub_08014B34(void) {
    u16 r;
    s16 flag;

    if (gUnk_03001800.unk51 != 3) {
        gUnk_03005010.unk6 =
            gUnk_03000590[gUnk_03001800.unk51].unkDD + (flag = ((gUnk_03001800.unk1AF << 8) & 0x100) + 0x8000);
        gUnk_03000440.unk86++;
        if (!(gUnk_03000440.unk86 & 1)) {
            gUnk_03001800.unk1AF ^= 1;
            gUnk_03001800.unk51++;
        }
    }
    if (gUnk_03001800.unk53 != 3) {
        r = gUnk_03005010.unk8[gUnk_03000B90 ^ 1][1];
        if ((r & 0x8000) && ((u16)(r & 0x100) >> 8) != gUnk_03001800.unk1B0) {
            gUnk_03001800.unk1B0 ^= 1;
            gUnk_03000590[gUnk_03001800.unk53 + 3].unkDD = r;
            gUnk_03001800.unk53++;
        }
    }
    if (gUnk_03001800.unk51 == 3) {
        if (gUnk_03001800.unk53 == 3) {
            gGameSubState++;
            gUnk_03000440.unk86 = 0;
        }
    }
}

void sub_08014C30(void) {
    gUnk_03005010.unk6 = 0;
    battle_bot_select_part(3, gUnk_03000590[3].unkDD);
    battle_bot_select_part(4, gUnk_03000590[4].unkDD);
    battle_bot_select_part(5, gUnk_03000590[5].unkDD);
    gGameSubState++;
}

void sub_08014C84(void) {
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03000590[i + 3].unkDD > 3)
            battle_bot_select_medaforce(i + 3, gUnk_03000590[i + 3].unkDD - 4);
    }
    gGameSubState++;
}

void sub_08014CC8(void) {
    if (game_state_execute_handler_a())
        gGameSubState++;
}

void sub_08014CE4(void) {
    gGameSubState = 0x40;
}

void sub_08014CF0(void) {
    u16 r;

    if (gUnk_03001800.unk87 <= 2) {
        gUnk_03005010.unk6 = gUnk_03000590[gUnk_03001800.unk87].unkDD + 0x8000;
        if (gUnk_03001800.unk1AF)
            goto next;
        gUnk_03001800.unk1AF = 1;
    } else {
        r = gUnk_03005010.unk8[gUnk_03000B90 ^ 1][1];
        if (r & 0x8000) {
            gUnk_03000590[gUnk_03001800.unk87].unkDD = r;
        next:
            gGameSubState++;
        }
    }
}

void sub_08014D84(void) {
    gGameSubState++;
}

void sub_08014D94(void) {
    if (gUnk_03001800.unk87 > 2)
        battle_bot_select_part(gUnk_03001800.unk87, gUnk_03000590[gUnk_03001800.unk87].unkDD);
    gGameSubState++;
}

void sub_08014DC8(void) {
    if (gUnk_03001800.unk87 > 2 && gUnk_03000590[gUnk_03001800.unk87].unkDD > 3)
        battle_bot_select_medaforce(gUnk_03001800.unk87, gUnk_03000590[gUnk_03001800.unk87].unkDD - 4);
    gGameSubState++;
}

void sub_08014E08(void) {
    gUnk_03005010.unk6 = 0;
    gGameSubState = 0x45;
}

void sub_08014E20(void) {
    gUnk_03000440.unk86++;
    if (sub_0803E79C()) {
        gUnk_03005010.unk6 = 0;
        gGameSubState++;
    }
}

void sub_08014E54(void) {
    if (gUnk_03000440.unk86)
        gUnk_03000440.unk86--;
    else
        gGameSubState++;
}
