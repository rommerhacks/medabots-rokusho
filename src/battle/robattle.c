// Game state 7: the Robattle itself. robattle_update runs the sub-state machine in gRobattleHandlers:
// 0x00-0x02 setup and fade-in, 0x03-0x0E command ring (the six ring commands, decoded from their name
// text gCommandRingNames, jump to gCommandRingSubStates: Medaparts 0x10, MF 0x18, Status 0x20, Aim 0x28, Rotation 0x30,
// Auto 0x38), 0x3C-0x3D screen restore after a full-screen menu, 0x40-0x42 start banner, 0x44-0x4C the turn
// loop, 0x60-0x79 timed effect ends / numbers, 0x90-0xAF link Robattle command exchange. Calls into battle_bots (turn
// logic), battle_hud, command_ring, part_select and status_screen; the action scripts run in game states 8-9.

#include "global.h"
#include "constants/sprites.h"

// Game state 7 = Robattle (gGameStateHandlers_083AC148[7]); sub-states in gRobattleHandlers.
void robattle_update(void) {
    u32 fill;

    if (link_error_check())
        return;
    if (gVBlankOamMode == 2) {
        fill = 0x200;
        CpuFastSet(&fill, gSpriteWork->oamBuf, 0x01000100);
    }
    gRobattleHandlers[gGameSubState]();
}

void robattle_setup_bots(void) {
    gGameWork.setupStep = 0;
    gGameWork.gfxLoadStep = 0;
    if (gGameWork.skipBotSetup != 1) {
        clear_battle_bot_array();
        count_active_battle_bots();
        battle_setup_team_bots();
        init_opponent_bots();
    }
    battle_pick_all_ai_targets();
    if (gGameWork.skipBotSetup != 1)
        fill_opponent_medaforce_for_battle_type();
    gGameSubState++;
}

void robattle_load_scene(void) {
    u32 fill;

    switch (gGameWork.setupStep) {
    case 0:
        clear_bg_scroll();
        load_battle_script_entry_b();
        REG_DISPCNT &= 0xF0FF;
        REG_BG0CNT = 0x500;
        REG_BG1CNT = 0x1901;
        REG_BG2CNT = 0x1A0A;
        REG_BG3CNT = 0x1B0B;
        if (battle_load_graphics_step(0))
            gGameWork.setupStep++;
        break;
    case 1:
        gGameWork.stepCounter = 0;
        fill = 0;
        CpuFastSet(&fill, gSpriteEntries, 0x01000800);
        REG_DISPCNT |= 0x1F40;
        REG_DISPCNT &= 0xFFDF;
        gGameWork.setupStep++;
        break;
    case 2:
        load_bg3_tilemap_08488764();
        draw_battle_bot_portraits();
        load_all_bot_part_sprites();
        setup_all_battle_bot_sprite_positions();
        init_battle_bot_sprites();
        apply_battle_blend_effect_b();
        decompress_to_ewram_27000((const u8 *)gBattlefieldGraphics[gBattleWork.battlefield * 5 + 1]);
        gVBlankCallback = battle_vblank_update_bg;
        gGameSubState++;
        gGameWork.setupStep = 0;
        break;
    }
}

void robattle_fade_in_from_white(void) {
    if (gGameWork.stepCounter <= 8) {
        bg_palettes_blend_masked_now(0, 0x20 - gGameWork.stepCounter * 4, 0xFFFF);
        obj_palettes_blend_masked_now(0, 0x20 - gGameWork.stepCounter * 4, 0xFFFF);
        gGameWork.stepCounter++;
    } else
        gGameSubState++;
}

// Sub-state 3: the AI picks the opponents' (records 3-5) first commands.
void robattle_opponents_choose_commands(void) {
    update_all_battle_status_sprites();
    if (gGameWork.skipBotSetup != 1)
        battle_process_bot_actions_for_side(3);
    gGameSubState++;
}

// Sub-state 4: starts the pointer line towards team Medabot unk80 (bot_pointer_line_init).
void robattle_command_begin(void) {
    update_all_battle_status_sprites();
    bot_pointer_line_init(gBattleWork.unk80);
    gGameSubState++;
}

void robattle_command_pointer_wait(void) {
    update_all_battle_status_sprites();
    if (bot_pointer_line_extend(gBattleWork.unk80))
        gGameSubState++;
}

// Sub-state 6: draws the Medabot's panel, MF gauge and the command ring.
void robattle_command_ring_open(void) {
    update_all_battle_status_sprites();
    bot_pointer_line_animate(gBattleWork.unk80);
    load_battle_bg_layers();
    render_bot_name_sprites(gBattleWork.unk80);
    draw_battle_panel_left_a(gBattleWork.unk80);
    draw_medaforce_gauge_bar(gBattleWork.unk80);
    draw_medaforce_gauge_value(gBattleWork.unk80);
    command_ring_draw_name();
    command_ring_init_icons();
    battle_sprite_group_set_anim(gBattleWork.unk80 * 4 + 0x5A, 8);
    gGameSubState++;
}

// Sub-state 7: command ring of team Medabot gBattleWork.unk80 (runtime-checked). A -> sub-state 8,
// B -> back to the previous Medabot (sub-state 4).
void robattle_command_input(void) {
    update_all_battle_status_sprites();
    bot_pointer_line_animate(gBattleWork.unk80);
    update_battle_sprite_orbiting_positions(gBattleWork.unk80 * 4 + 0x5A, gBattleWork.unk80, 0);
    command_ring_input();
    mf_gauge_full_blink_panel();
    if (gBattleWork.ringTurning)
        return;
    command_ring_pulse_selected();
    if (KEYS_LO(gNewKeys) & 1) {
        if (gGameWork.skipBotSetup == 1 && gBattleWork.ringSlot == 5) {
            play_sound_effect(6);
            return;
        }
        play_sound_effect(4);
        mf_gauge_draw_panel();
        gGameWork.stepCounter = 0;
        gGameSubState++;
    } else if (KEYS_LO(gNewKeys) & 2) {
        if (gBattleWork.unk84 == 0 && gBattleWork.unk80 != 0) {
            play_sound_effect(5);
            setup_battle_bot_sprite_group(gBattleWork.unk80, 0x28, (u8)(gBattleWork.unk80 % 3) * 24 + 0x24);
            gBattleWork.unk80--;
            draw_battle_panel_left_a(0);
            team_bot_clear_command_kept(gBattleWork.unk80);
            gBattleWork.ringSlot = 0;
            gBattleWork.unk82 = 0;
            clear_battle_sprite_slot(0, 0x46);
            vram_fill_tilemap_rect(0x1E, 8, 0, 0xC, REG_BG0CNT, 0);
            vram_fill_tilemap_rect(0x1E, 8, 0, 0xC, REG_BG1CNT, 0);
            gGameSubState = 4;
        }
    }
}

void robattle_command_chosen_flash(void) {
    update_all_battle_status_sprites();
    bot_pointer_line_animate(gBattleWork.unk80);
    update_battle_sprite_orbiting_positions(gBattleWork.unk80 * 4 + 0x5A, gBattleWork.unk80, 0);
    command_ring_flash_selected();
    if (++gGameWork.stepCounter == 20) {
        clear_battle_sprite_slot(0x1E, 0xB);
        gGameWork.stepCounter = 0;
        gGameSubState++;
    }
}

// Sub-state 9: shrinks the ring icons, then jumps to the selected command's sub-state.
void robattle_command_ring_close(void) {
    update_all_battle_status_sprites();
    bot_pointer_line_animate(gBattleWork.unk80);
    update_battle_sprite_orbiting_positions(gBattleWork.unk80 * 4 + 0x5A, gBattleWork.unk80, 0);
    command_ring_shrink_icons();
    command_ring_close_scroll_right();
    command_ring_close_scroll_down();
    if (++gGameWork.stepCounter == 16)
        command_ring_goto_selected();
}

// Sub-states 0x0B-0x0C: the ring comes back after a command menu was cancelled -> sub-state 7.
void robattle_command_ring_reopen(void) {
    update_all_battle_status_sprites();
    bot_pointer_line_animate(gBattleWork.unk80);
    update_battle_sprite_orbiting_positions(gBattleWork.unk80 * 4 + 0x5A, gBattleWork.unk80, 0);
    decompress_two_bg1_layers();
    command_ring_init_icons_hidden();
    read_vram_tilemap_rect(6, 5, 0xC, 0x15, REG_BG1CNT, gBgTileBackup);
    gGameWork.stepCounter = 0;
    gGameSubState++;
}

void robattle_command_ring_reopen_anim(void) {
    update_all_battle_status_sprites();
    bot_pointer_line_animate(gBattleWork.unk80);
    update_battle_sprite_orbiting_positions(gBattleWork.unk80 * 4 + 0x5A, gBattleWork.unk80, 0);
    draw_partial_bg1_column();
    scroll_tilemap_window();
    command_ring_grow_icons();
    if (++gGameWork.stepCounter == 10) {
        command_ring_draw_name();
        gGameSubState = 7;
    }
}

// Stores the chosen command of Medabot unk80 and moves on to the next one (sub-state 4), or to
// sub-state 0x40 (0x90 when unk89 is 1) after the last one.
void robattle_command_commit(void) {
    update_all_battle_status_sprites();
    bot_pointer_line_animate(gBattleWork.unk80);
    update_battle_sprite_orbiting_positions(gBattleWork.unk80 * 4 + 0x5A, gBattleWork.unk80, 0);
    switch (gBattleWork.ringSlot) {
    case 0:
        battle_bot_select_part(gBattleWork.unk80, gBattleWork.unk82);
        break;
    case 1:
        if (gBattleWork.unk82)
            battle_bot_select_medaforce(gBattleWork.unk80, gBattleWork.unk82 - 1);
        else
            battle_bot_select_part(gBattleWork.unk80, 0);
        break;
    default:
        process_bot_battle_turn(gBattleWork.unk80);
        break;
    }
    setup_battle_bot_sprite_group(gBattleWork.unk80, 0x28, (u8)(gBattleWork.unk80 % 3) * 24 + 0x24);
    gBattleWork.ringSlot = 0;
    gBattleWork.unk82 = 0;
    gBattleWork.unk80++;
    if (gBattleWork.unk84 == 0) {
        if (gBattleWork.unk80 != 3 && gBattleWork.unk80 < gBattleWork.teamCount)
            gGameSubState = 4;
        else if (gGameWork.skipBotSetup != 1)
            gGameSubState = 0x40;
        else
            gGameSubState = 0x90;
    } else
        gGameSubState++;
}

// Sub-state 0x0E: a command chosen during the turn loop (unk84 set) -> back to 0x45 (0xA0 when linked).
void robattle_command_resume_turn(void) {
    update_all_battle_status_sprites();
    count_bot_skill_use(gBattleWork.actor);
    init_battle_action_select_ui(0);
    if (gGameWork.skipBotSetup != 1)
        gGameSubState = 0x45;
    else
        gGameSubState = 0xA0;
}

// Sub-states 0x10-0x15: the Medaparts command (part_select).
void robattle_parts_menu_open(void) {
    update_all_battle_status_sprites();
    bot_pointer_line_animate(gBattleWork.unk80);
    update_battle_sprite_orbiting_positions(gBattleWork.unk80 * 4 + 0x5A, gBattleWork.unk80, 0);
    CpuFastSet(gPartsMenuObjPalette, (void *)0x05000340, 8);
    CpuFastSet(gActionFlashPalette, (void *)0x050002C0, 8);
    clear_battle_sprite_slot(0, 6);
    clear_battle_sprite_slot(0x1E, 0xB);
    parts_menu_load_frame();
    determine_battle_part_action_priority();
    read_vram_tilemap_rect(0xC, 4, 9, 0x15, REG_BG0CNT, gBgTileBackup);
    gGameWork.stepCounter = 0;
    gGameSubState++;
}

void robattle_parts_menu_slide_in(void) {
    update_all_battle_status_sprites();
    bot_pointer_line_animate(gBattleWork.unk80);
    update_battle_sprite_orbiting_positions(gBattleWork.unk80 * 4 + 0x5A, gBattleWork.unk80, 0);
    parts_menu_slide_bg0();
    parts_menu_slide_bg1();
    if (++gGameWork.stepCounter == 16) {
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
        gGameWork.stepCounter = 0;
        gGameSubState++;
    }
}

// Sub-state 0x12: Medapart select input (part_select). B -> 0x13 (back to the ring), A -> 0x15.
void robattle_parts_menu_input(void) {
    u8 b;

    update_all_battle_status_sprites();
    bot_pointer_line_animate(gBattleWork.unk80);
    update_battle_sprite_orbiting_positions(gBattleWork.unk80 * 4 + 0x5A, gBattleWork.unk80, 0);
    target_marker_update();
    gGameWork.stepCounter++;
    part_select_blink_selected_icon();
    part_select_input();
    part_select_blink_status();
    if ((b = KEYS_LO(gNewKeys) & 2)) {
        play_sound_effect(5);
        clear_battle_sprite_slot(0, 6);
        target_marker_hide();
        clear_battle_sprite_slot(0x14, 0x26);
        vram_fill_tilemap_rect(7, 1, 0xE, 0xC, REG_BG0CNT, 0);
        gGameWork.stepCounter = 0;
        gGameSubState++;
    } else if (KEYS_LO(gNewKeys) & 1) {
        play_sound_effect(4);
        target_marker_hide();
        gGameWork.stepTimer = 0;
        gGameSubState = 0x15;
    }
}

void robattle_parts_menu_cancel(void) {
    update_all_battle_status_sprites();
    bot_pointer_line_animate(gBattleWork.unk80);
    update_battle_sprite_orbiting_positions(gBattleWork.unk80 * 4 + 0x5A, gBattleWork.unk80, 0);
    save_restore_bg0_tilemap_region();
    save_restore_bg1_tilemap_region();
    if (++gGameWork.stepCounter == 16) {
        CpuFastSet(gBattleObjPalette10, (void *)0x05000340, 8);
        gGameSubState = 0xB;
    }
}

void robattle_parts_menu_confirm(void) {
    update_all_battle_status_sprites();
    bot_pointer_line_animate(gBattleWork.unk80);
    update_battle_sprite_orbiting_positions(gBattleWork.unk80 * 4 + 0x5A, gBattleWork.unk80, 0);
    gGameWork.stepCounter++;
    gGameWork.stepCounter++;
    part_select_blink_selected_icon();
    part_select_blink_status();
    if (++gGameWork.stepTimer == 16) {
        clear_battle_sprite_slot(0, 0x46);
        vram_fill_tilemap_rect(0x1E, 8, 0, 0xC, REG_BG0CNT, 0);
        vram_fill_tilemap_rect(0x1E, 8, 0, 0xC, REG_BG1CNT, 0);
        CpuFastSet(gBattleObjPalette10, (void *)0x05000340, 8);
        gGameSubState = 0xD;
    }
}

// Sub-states 0x18-0x1D: the MF (Medaforce) command (battle/medaforce_select).
void robattle_mf_menu_open(void) {
    update_all_battle_status_sprites();
    bot_pointer_line_animate(gBattleWork.unk80);
    update_battle_sprite_orbiting_positions(gBattleWork.unk80 * 4 + 0x5A, gBattleWork.unk80, 0);
    CpuFastSet(gMfMenuObjPalette, (void *)0x05000340, 8);
    clear_battle_sprite_slot(0, 6);
    clear_battle_sprite_slot(0x1E, 0xB);
    mf_menu_load_frame();
    read_vram_tilemap_rect(0xC, 4, 9, 0x15, REG_BG0CNT, gBgTileBackup);
    gGameWork.stepCounter = 0;
    gGameSubState++;
}

void robattle_mf_menu_slide_in(void) {
    update_all_battle_status_sprites();
    bot_pointer_line_animate(gBattleWork.unk80);
    update_battle_sprite_orbiting_positions(gBattleWork.unk80 * 4 + 0x5A, gBattleWork.unk80, 0);
    mf_menu_slide_bg0();
    mf_menu_slide_bg1();
    if (++gGameWork.stepCounter == 16) {
        mf_menu_init_cursor();
        mf_menu_init_center_icon();
        mf_menu_init_top_icon(1);
        mf_menu_init_left_icon(1);
        mf_menu_init_right_icon(1);
        mf_menu_init_charge_icon(1);
        mf_menu_draw_medaforce_name();
        mf_menu_draw_status(0);
        gGameWork.stepCounter = 0;
        gGameSubState++;
    }
}

void robattle_mf_menu_input(void) {
    u8 b;

    update_all_battle_status_sprites();
    bot_pointer_line_animate(gBattleWork.unk80);
    update_battle_sprite_orbiting_positions(gBattleWork.unk80 * 4 + 0x5A, gBattleWork.unk80, 0);
    gGameWork.stepCounter++;
    mf_menu_blink_selected_icon();
    mf_menu_input();
    mf_menu_draw_status(1);
    if ((b = KEYS_LO(gNewKeys) & 2)) {
        play_sound_effect(5);
        vram_fill_tilemap_rect(8, 1, 1, 0x11, REG_BG0CNT, 0);
        draw_medaforce_gauge_value(gBattleWork.unk80);
        clear_battle_sprite_slot(0, 5);
        clear_battle_sprite_slot(0x14, 0x24);
        gGameWork.stepCounter = 0;
        gGameSubState++;
    } else if (KEYS_LO(gNewKeys) & 1) {
        play_sound_effect(4);
        gGameWork.stepTimer = 0;
        gGameSubState = 0x1D;
    }
}

void robattle_mf_menu_cancel(void) {
    update_all_battle_status_sprites();
    bot_pointer_line_animate(gBattleWork.unk80);
    update_battle_sprite_orbiting_positions(gBattleWork.unk80 * 4 + 0x5A, gBattleWork.unk80, 0);
    save_restore_bg0_tilemap_region();
    mf_menu_slide_out_bg1();
    if (++gGameWork.stepCounter == 16) {
        CpuFastSet(gBattleObjPalette10, (void *)0x05000340, 8);
        gGameSubState = 0xB;
    }
}

void robattle_mf_menu_confirm(void) {
    update_all_battle_status_sprites();
    bot_pointer_line_animate(gBattleWork.unk80);
    update_battle_sprite_orbiting_positions(gBattleWork.unk80 * 4 + 0x5A, gBattleWork.unk80, 0);
    gGameWork.stepCounter++;
    gGameWork.stepCounter++;
    mf_menu_blink_selected_icon();
    mf_menu_draw_status(1);
    if (++gGameWork.stepTimer == 16) {
        clear_battle_sprite_slot(0, 0x46);
        vram_fill_tilemap_rect(0x1E, 8, 0, 0xC, REG_BG0CNT, 0);
        vram_fill_tilemap_rect(0x1E, 8, 0, 0xC, REG_BG1CNT, 0);
        CpuFastSet(gBattleObjPalette10, (void *)0x05000340, 8);
        gGameSubState = 0xD;
    }
}

// Sub-states 0x28-0x2A: the Aim command shows the Medal's message (gSkillTypeHelpMessages by Medal byte 6).
void robattle_aim_message_open(void) {
    update_all_battle_status_sprites();
    bot_pointer_line_animate(gBattleWork.unk80);
    update_battle_sprite_orbiting_positions(gBattleWork.unk80 * 4 + 0x5A, gBattleWork.unk80, 0);
    text_window_init(1, 2, 0);
    gGameSubState++;
}

void robattle_aim_message_show(void) {
    update_all_battle_status_sprites();
    bot_pointer_line_animate(gBattleWork.unk80);
    update_battle_sprite_orbiting_positions(gBattleWork.unk80 * 4 + 0x5A, gBattleWork.unk80, 0);
    if (run_message(gSkillTypeHelpMessages[gBattleBots[gBattleWork.unk80].medal.aimSkillType])) {
        gGameWork.endModeStep = 0;
        gGameSubState++;
    }
}

void robattle_aim_message_close(void) {
    update_all_battle_status_sprites();
    bot_pointer_line_animate(gBattleWork.unk80);
    update_battle_sprite_orbiting_positions(gBattleWork.unk80 * 4 + 0x5A, gBattleWork.unk80, 0);
    if (game_state_execute_handler_a())
        gGameSubState = 0xB;
}

// Sub-states 0x20-0x22 (Status) and 0x30-0x32 (Rotation): fade to white and back up VRAM / OAM.
void robattle_fade_to_white_init(void) {
    update_all_battle_status_sprites();
    bot_pointer_line_animate(gBattleWork.unk80);
    update_battle_sprite_orbiting_positions(gBattleWork.unk80 * 4 + 0x5A, gBattleWork.unk80, 0);
    palette_backup_from_hardware();
    gGameWork.stepCounter = 0;
    gGameSubState++;
}

void robattle_fade_to_white(void) {
    update_all_battle_status_sprites();
    bot_pointer_line_animate(gBattleWork.unk80);
    update_battle_sprite_orbiting_positions(gBattleWork.unk80 * 4 + 0x5A, gBattleWork.unk80, 0);
    if (gGameWork.stepCounter <= 8) {
        bg_palettes_blend_masked_now(0, gGameWork.stepCounter * 4, 0xFFFF);
        obj_palettes_blend_masked_now(0, gGameWork.stepCounter * 4, 0xFFFF);
        gGameWork.stepCounter++;
    } else {
        gGameSubState++;
    }
}

void robattle_backup_screen(void) {
    CpuFastSet((void *)0x06002800, (void *)0x02020800, 0x200);
    CpuFastSet((void *)0x0600C800, (void *)0x02021000, 0x200);
    CpuFastSet((void *)0x0600D000, (void *)0x02021800, 0x200);
    CpuFastSet((void *)0x0600D800, (void *)0x02022000, 0x200);
    CpuFastSet(gSpriteEntries, (void *)0x02028000, 0x800);
    set_blend_effect_mode(5, 0x3F, 0x20);
    gVBlankCallback = empty_callback;
    gGameSubState++;
}

// guess: Robattle sub-state 0x33 opens the Medals screen (game state 4, sub 0x28) on the Rotation page of
// the current Medabot's Medal; robattle_backup_screen (0x32) saves VRAM/OAM, robattle_restore_screen (0x3C) restores
// it.
void robattle_rotation_open_medals_screen(void) {
    mem_fill8(&gGameWork.openedFrom, 0x14, 0);
    gGameWork.openedFrom = 2;
    gGameWork.shownId = find_medal_slot_by_id(gBattleBots[gBattleWork.unk80].medal.graphicId) - 1;
    gGameWork.freeMedalCount = 1;
    gGameWork.medalPage = 2;
    clear_bg_scroll();
    gGameState = 4;
    gGameSubState = 0x28;
}

void robattle_restore_screen(void) {
    u32 fill;

    switch (gGameWork.setupStep) {
    case 0:
        gGameWork.noAffineSprites = 0;
        gVBlankOamMode = 0;
        clear_bg_scroll();
        load_battle_script_entry_b();
        REG_DISPCNT &= 0xF0FF;
        REG_BG0CNT = 0x500;
        REG_BG1CNT = 0x1901;
        REG_BG2CNT = 0x1A0A;
        REG_BG3CNT = 0x1B0B;
        if (battle_load_graphics_step(0)) {
            gGameWork.stepCounter = 0;
            gGameWork.setupStep++;
        }
        break;
    case 1:
        fill = 0;
        CpuFastSet(&fill, gSpriteEntries, 0x01000800);
        gGameWork.setupStep++;
        break;
    case 2:
        REG_DISPCNT |= 0x1F40;
        load_all_bot_part_sprites();
        apply_battle_blend_effect_b();
        decompress_to_ewram_27000((const u8 *)gBattlefieldGraphics[gBattleWork.battlefield * 5 + 1]);
        gGameWork.setupStep++;
        break;
    case 3:
        CpuFastSet((void *)0x02020800, (void *)0x06002800, 0x200);
        CpuFastSet((void *)0x02021000, (void *)0x0600C800, 0x200);
        gGameWork.setupStep++;
        break;
    case 4:
        CpuFastSet((void *)0x02021800, (void *)0x0600D000, 0x200);
        CpuFastSet((void *)0x02022000, (void *)0x0600D800, 0x200);
        gGameWork.setupStep++;
        break;
    case 5:
        CpuFastSet((void *)0x02028000, gSpriteEntries, 0x800);
        gVBlankCallback = battle_vblank_update_bg;
        gGameSubState++;
        gGameWork.setupStep = 0;
        break;
    }
}

// Sub-state 0x3D: fade back in after robattle_restore_screen -> the ring (0x0B).
void robattle_return_fade_in(void) {
    update_all_battle_status_sprites();
    bot_pointer_line_animate(gBattleWork.unk80);
    update_battle_sprite_orbiting_positions(gBattleWork.unk80 * 4 + 0x5A, gBattleWork.unk80, 0);
    if (gGameWork.stepCounter <= 8) {
        bg_palettes_blend_masked_now(0, 0x20 - gGameWork.stepCounter * 4, 0xFFFF);
        obj_palettes_blend_masked_now(0, 0x20 - gGameWork.stepCounter * 4, 0xFFFF);
        gGameWork.stepCounter++;
    } else {
        gGameSubState = 0xB;
    }
}

// Sub-state 0x38: the Auto command sets the Medabot's bit in unk44 and lets the AI choose (commit, 0x0D).
void robattle_command_auto(void) {
    update_all_battle_status_sprites();
    bot_pointer_line_animate(gBattleWork.unk80);
    update_battle_sprite_orbiting_positions(gBattleWork.unk80 * 4 + 0x5A, gBattleWork.unk80, 0);
    switch (gBattleWork.unk80) {
    case 0:
        gBattleWork.autoCommandBits |= 1;
        break;
    case 1:
        gBattleWork.autoCommandBits |= 2;
        break;
    case 2:
        gBattleWork.autoCommandBits |= 4;
        break;
    }
    clear_battle_sprite_slot(0, 0x46);
    vram_fill_tilemap_rect(0x1E, 8, 0, 0xC, REG_BG0CNT, 0);
    vram_fill_tilemap_rect(0x1E, 8, 0, 0xC, REG_BG1CNT, 0);
    gGameSubState = 0xD;
}

// Sub-states 0x23-0x26: the Status command's team status screen (status_screen); B -> 0x3C.
void robattle_status_screen_init(void) {
    u32 fill;

    clear_bg_scroll();
    REG_DISPCNT &= 0xF0FF;
    REG_BG0CNT = 0x500;
    REG_BG1CNT = 0x1901;
    REG_BG2CNT = 0x1A02;
    REG_BG3CNT = 0x1B03;
    lz_decompress_dispatch(gStatusScreenBgTilesLz, (void *)0x06004000);
    lz_decompress_dispatch(gStatusScreenCornerTiles, (void *)0x06006000);
    lz_decompress_dispatch(gCompatibilityIconTiles, (void *)0x06006800);
    lz_decompress_dispatch(gPartSlotIconTiles, (void *)0x06006E00);
    lz_decompress_dispatch(gTallDigitTiles, (void *)0x06007200);
    lz_decompress_dispatch(gSlashTiles, (void *)0x06007480);
    lz_decompress_dispatch(gCursorArrowTiles, (void *)0x06017E00);
    set_tilemap_and_decompress_bg(0, 0, gStatusScreenBg0Tilemap, REG_BG0CNT, 0x200);
    set_tilemap_and_decompress_bg(0, 0, gStatusScreenBg1Tilemap, REG_BG1CNT, 0x200);
    set_tilemap_and_decompress_bg(0, 0, gStatusScreenBg2Tilemap, REG_BG2CNT, 0x200);
    set_tilemap_and_decompress_bg(0, 0, gStatusScreenBg3Tilemap, REG_BG3CNT, 0x200);
    CpuFastSet(gStatusScreenBgPalettes, (void *)0x05000000, 0x70);
    CpuFastSet(gMenuObjPalettes, (void *)0x05000200, 0x40);
    CpuFastSet(gGradientPaletteOlive, (void *)0x05000380, 8);
    CpuFastSet(&gGradientPaletteOlive[0x20], (void *)0x050003A0, 8);
    CpuFastSet(&gGradientPaletteOlive[-0x20], (void *)0x050003E0, 8);
    CpuFastSet(gCursorArrowPalette, (void *)0x050003C0, 8);
    fill = 0;
    CpuFastSet(&fill, gSpriteEntries, 0x01000800);
    REG_DISPCNT |= 0x1F40;
    mem_fill8(&gGameWork.openedFrom, 0x14, 0);
    gGameWork.pageCursor = 1;
    position_battle_team_cursors(0, 0);
    status_init_cursor();
    status_draw_bot_name();
    status_draw_row_icons();
    status_load_medal_icon();
    status_draw_medal_name();
    status_draw_part_names();
    status_draw_part_ability_icons();
    status_draw_part_armor();
    get_bot_part_effective_values(gGameWork.openedFrom * 3 + gGameWork.shownId, gBattleWork.unk64);
    set_portrait_parts(gBattleWork.unk64[0], gBattleWork.unk64[1], gBattleWork.unk64[2], gBattleWork.unk64[3]);
    status_init_portrait();
    status_draw_team_sprites();
    battle_sprite_group_set_anim(0, 8);
    draw_tile_block(2, 2, 0xB, 2, REG_BG1CNT, 0x63C0);
    set_blend_effect_mode(5, 0x3F, 0x20);
    gGameSubState++;
}

void robattle_status_screen_fade_in(void) {
    status_next_other_slot();
    status_blink_lr_button();
    status_update_portrait();
    status_draw_team_sprites();
    sprite_bob_x(8, gFrameCounter, status_cursor_x());
    scroll_bg3_diagonal();
    if (update_blend_effect())
        gGameSubState++;
}

void robattle_status_screen_input(void) {
    status_next_other_slot();
    status_update_portrait();
    scroll_bg3_diagonal();
    switch (gGameWork.listTab) {
    case 0:
        status_blink_lr_button();
        status_draw_team_sprites();
        sprite_bob_x(8, gFrameCounter, status_cursor_x());
        status_select_input();
        if ((KEYS_HI(gNewKeys) & 1) && gGameWork.openedFrom == 0) {
            play_sound_effect(2);
            status_begin_side_change();
            gGameWork.medalRow = 0;
            gGameWork.listTab++;
        } else if ((KEYS_HI(gNewKeys) & 2) && gGameWork.openedFrom == 1) {
            play_sound_effect(2);
            status_begin_side_change();
            gGameWork.medalRow = 0;
            gGameWork.listTab++;
        } else if (KEYS_LO(gNewKeys) & 2) {
            play_sound_effect(5);
            set_blend_effect_mode(6, 0x3F, 0x20);
            gGameSubState++;
        }
        break;
    case 1:
        if (status_side_change_scroll_out()) {
            gGameWork.medalRow = 0;
            gGameWork.listTab++;
        }
        break;
    case 2:
        if (status_side_change_scroll_in())
            gGameWork.listTab++;
        break;
    case 3:
        get_bot_part_effective_values(gGameWork.shownId + gGameWork.openedFrom * 3, gBattleWork.unk64);
        set_portrait_parts(gBattleWork.unk64[0], gBattleWork.unk64[1], gBattleWork.unk64[2], gBattleWork.unk64[3]);
        status_init_portrait();
        battle_sprite_group_set_anim(0, 8);
        draw_tile_block(2, 2, 0xB, 2, REG_BG1CNT, 0x63C0);
        status_reset_portrait();
        gGameWork.listTab = 0;
        break;
    }
}

void robattle_status_screen_fade_out(void) {
    u32 fill1, fill2, fill3;

    status_next_other_slot();
    status_blink_lr_button();
    status_update_portrait();
    status_draw_team_sprites();
    sprite_bob_x(8, gFrameCounter, status_cursor_x());
    scroll_bg3_diagonal();
    if (update_blend_effect()) {
        gGameWork.noAffineSprites = 0;
        gVBlankOamMode = 0;
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
    gBattleWork.unk84 = 1;
    lz_decompress_dispatch(gBattleBannerTilesLz, (void *)0x06014800);
    CpuFastSet(gBattleBannerPalette, (void *)0x050003E0, 8);
    fade_out_music(8);
    play_sound_effect(0x6E);
    gGameWork.stepCounter = 0;
    gGameSubState++;
}

// Robattle sub-state 0x41: "MEDABOTS" (sprite 3) mosaics in, then "ROBATTLE" (sprite 4) stretches in;
// after 60 frames -> 0x42 (runtime-checked from battle_start.ss0).
void robattle_start_banner(void) {
    switch (gGameWork.stepCounter) {
    case 0:
        gSpriteEntries[3].flags =
            SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_FLAG_PART_PALETTE | SPRITE_FLAG_MOSAIC;
        gSpriteEntries[3].frame_table = 0;
        gSpriteEntries[3].x = 0x78;
        gSpriteEntries[3].y = 0x38;
        gSpriteEntries[3].palette = 0xF;
        gSpriteEntries[3].order = 0xC0;
        gSpriteEntries[3].frame = 0x900;
        gSpriteEntries[3].unk20 = 8;
        REG_MOSAIC = (gSpriteEntries[3].unk20 << 12) + (gSpriteEntries[3].unk20 << 8);
        gGameWork.stepCounter++;
        break;
    case 1:
        if (gFrameCounter & 1)
            break;
        gSpriteEntries[3].unk20--;
        REG_MOSAIC = (gSpriteEntries[3].unk20 << 12) + (gSpriteEntries[3].unk20 << 8);
        if (gSpriteEntries[3].unk20 == 0) {
            gSpriteEntries[4].flags = SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_FLAG_AFFINE |
                                      SPRITE_FLAG_DOUBLE_SIZE | SPRITE_FLAG_PART_PALETTE;
            gSpriteEntries[4].frame_table = 0;
            gSpriteEntries[4].x = 0x78;
            gSpriteEntries[4].y = 0x48;
            gSpriteEntries[4].palette = 0xF;
            gSpriteEntries[4].order = 0xC0;
            gSpriteEntries[4].frame = 0x901;
            gSpriteEntries[4].scale_y = 8;
            gSpriteEntries[4].scale_x = 0x40;
            gGameWork.stepCounter++;
        }
        break;
    case 2:
        if ((gSpriteEntries[4].scale_y += 8) == 0x60)
            gGameWork.stepCounter++;
        break;
    case 3:
        if ((gSpriteEntries[4].scale_y -= 8) == 0x40) {
            gGameWork.stepCounter++;
            gGameWork.stepTimer = 0;
        }
        break;
    default:
        if (++gGameWork.stepTimer == 0x3C) {
            clear_battle_sprite_slot(3, 2);
            CpuFastSet(gGradientPaletteOrange, (void *)0x050003E0, 8);
            gGameSubState++;
        }
        break;
    }
}

// Sub-state 0x42: battle music, TIME counter -> the turn loop (0x44).
void robattle_turn_loop_init(void) {
    select_battle_music();
    init_battle_action_select_ui(0);
    robattle_time_init();
    gGameSubState = 0x44;
}

// Robattle sub-state 0x44: turn loop (TIME counter on screen); unk55 flags 2/4/8/0x10 -> 0x60/0x68/0x70/0x78.
void robattle_turn_loop(void) {
    if (gBattleWork.resultFlags == 0) {
        robattle_time_tick();
        robattle_time_draw();
    }
    if (gBattleWork.resultFlags & 2)
        gGameSubState = 0x60;
    else if (gBattleWork.resultFlags & 4)
        gGameSubState = 0x68;
    else if (gBattleWork.resultFlags & 8)
        gGameSubState = 0x70;
    else if (gBattleWork.resultFlags & 0x10)
        gGameSubState = 0x78;
    else {
        battle_bots_move_all();
        update_all_battle_status_sprites();
        init_battle_bot_sprites();
        if (battle_queue_bots_at_lines()) {
            battle_bots_update_walk_anims();
            gGameSubState++;
        }
    }
}

// Sub-state 0x45: takes the head of the action queue; a Medabot back home (unkBD bit 2) chooses a
// command (0x47), one at the front line acts (game state 8).
void robattle_turn_next_action(void) {
    struct BattleBot *rec;
    u8 flag;

    update_all_battle_status_sprites();
    battle_bots_update_walk_anims();
    battle_queue_sort();
    if (gBattleWork.actionQueue[0][0] == 0) {
        gGameSubState = 0x44;
        return;
    }
    battle_queue_take_head();
    rec = gBattleBots;
    rec += gBattleWork.actor;
    if (rec->teamState == 0) {
        battle_queue_pop();
    } else if ((flag = rec->stateFlags & 4)) {
        gGameSubState = 0x47;
    } else {
        iterate_bots_setup_battle_sprites();
        gGameState = 8;
        gGameSubState = flag;
    }
}

// Sub-state 0x46 (guess: entered when game state 8 finishes an action): next rotation entry, back to 0x45.
void robattle_action_finished(void) {
    update_all_battle_status_sprites();
    gBattleBots[gBattleWork.actor].stateFlags ^= 4;
    iterate_bots_setup_battle_sprites();
    battle_queue_pop();
    battle_bot_advance_rotation(gBattleWork.actor);
    if (any_bot_extra_move_pending()) {
        mem_fill8(gBattleWork.actionQueue[0], 0xC, 0);
        gGameSubState = 0x4C;
    } else {
        gGameSubState = 0x45;
    }
}

// Sub-state 0x47: a Medabot is back home; the AI (opponents, effect 0x2C) or the player (ring, sub-state
// 4) chooses its next command. Holding B cancels a kept command.
void robattle_bot_ready_for_command(void) {
    update_all_battle_status_sprites();
    battle_bots_update_walk_anims();
    gBattleBots[gBattleWork.actor].stateFlags ^= 4;
    setup_battle_bot_sprite_group(gBattleWork.actor, gSpriteEntries[gBattleWork.actor * 4 + 0x5D].x,
                                  gSpriteEntries[gBattleWork.actor * 4 + 0x5D].y - 4);
    battle_queue_pop();
    ai_pick_bot_targets(gBattleWork.actor);
    if (gBattleWork.actor > 2) {
        if (gGameWork.skipBotSetup != 1) {
            process_bot_battle_turn(gBattleWork.actor);
            gGameSubState = 0x45;
        } else {
            if (gBattleBots[gBattleWork.actor].statusType == 0x2C)
                process_bot_battle_turn(gBattleWork.actor);
            gGameSubState = 0xA0;
        }
    } else if (gBattleBots[gBattleWork.actor].statusType == 0x2C) {
        process_bot_battle_turn(gBattleWork.actor);
        count_bot_skill_use(gBattleWork.actor);
        if (gGameWork.skipBotSetup != 1)
            gGameSubState = 0x45;
        else
            gGameSubState = 0xA0;
    } else {
        if (team_bot_command_kept(gBattleWork.actor)) {
            if (!(KEYS_LO(gHeldKeys) & 2)) {
                process_bot_battle_turn(gBattleWork.actor);
                count_bot_skill_use(gBattleWork.actor);
                gGameSubState = 0x45;
                return;
            }
            team_bot_clear_command_kept(gBattleWork.actor);
        }
        gBattleWork.unk80 = gBattleWork.actor;
        gBattleWork.ringSlot = 0;
        gBattleWork.unk82 = 0;
        gBattleWork.ringTurning = 0;
        gBattleWork.unk85 = 0;
        iterate_bots_setup_battle_sprites();
        gGameSubState = 4;
    }
}

// Sub-state 0x4C (guess): Medabots with unkBF set keep moving until one reaches a line.
void robattle_bots_extra_move(void) {
    u32 i;

    update_all_battle_status_sprites();
    init_battle_bot_sprites();
    for (i = 0; i <= 5; i++) {
        struct BattleBot *rec = gBattleBots;

        rec += i;
        if (rec->teamState && rec->unkBF) {
            u32 a, b;

            rec->moveDelay = 8;
            battle_bot_move(i);
            bot_update_walk_anim(i);
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

// Sub-states 0x60-0x61 / 0x68-0x69: timed effect A / B ended (unkCE bit 0 / 1): its icon over the
// Medabot shrinks away.
void robattle_effect_a_end_init(void) {
    u32 i;

    update_all_battle_status_sprites();
    iterate_bots_setup_battle_sprites();
    for (i = 0; i <= 5; i++) {
        if (gBattleBots[i].teamState && (gBattleBots[i].effectShownFlags & 1)) {
            gSpriteEntries[0x46 + i * 3].flags |= SPRITE_FLAG_ENABLED | SPRITE_FLAG_AFFINE | SPRITE_FLAG_DOUBLE_SIZE;
            gSpriteEntries[0x46 + i * 3].scale_y = 0x40;
            gSpriteEntries[0x46 + i * 3].scale_x = 0x40;
        }
    }
    play_sound_effect(0x37);
    gGameSubState++;
}

void robattle_effect_a_end_anim(void) {
    u32 i;

    update_all_battle_status_sprites();
    for (i = 0; i <= 5; i++) {
        if (gBattleBots[i].teamState && (gBattleBots[i].effectShownFlags & 1)) {
            gSpriteEntries[0x46 + i * 3].flags |= SPRITE_FLAG_ENABLED;
            gSpriteEntries[0x46 + i * 3].scale_y += 4;
            if ((gSpriteEntries[0x46 + i * 3].scale_x -= 4) == 4) {
                gBattleWork.resultFlags &= ~2;
                gBattleBots[i].effectShownFlags &= ~1;
                clear_battle_sprite_slot(0x46 + i * 3, 1);
            }
        }
    }
    if (!(gBattleWork.resultFlags & 2))
        gGameSubState = 0x44;
}

void robattle_effect_b_end_init(void) {
    u32 i;

    update_all_battle_status_sprites();
    iterate_bots_setup_battle_sprites();
    for (i = 0; i <= 5; i++) {
        if (gBattleBots[i].teamState && (gBattleBots[i].effectShownFlags & 2)) {
            gSpriteEntries[0x47 + i * 3].flags |= SPRITE_FLAG_ENABLED | SPRITE_FLAG_AFFINE | SPRITE_FLAG_DOUBLE_SIZE;
            gSpriteEntries[0x47 + i * 3].scale_y = 0x40;
            gSpriteEntries[0x47 + i * 3].scale_x = 0x40;
        }
    }
    play_sound_effect(0x37);
    gGameSubState++;
}

void robattle_effect_b_end_anim(void) {
    u32 i;

    update_all_battle_status_sprites();
    for (i = 0; i <= 5; i++) {
        if (gBattleBots[i].teamState && (gBattleBots[i].effectShownFlags & 2)) {
            gSpriteEntries[0x47 + i * 3].flags |= SPRITE_FLAG_ENABLED;
            gSpriteEntries[0x47 + i * 3].scale_y += 4;
            if ((gSpriteEntries[0x47 + i * 3].scale_x -= 4) == 4) {
                gBattleWork.resultFlags &= ~4;
                gBattleBots[i].effectShownFlags &= ~2;
                clear_battle_sprite_slot(0x47 + i * 3, 1);
            }
        }
    }
    if (!(gBattleWork.resultFlags & 4))
        gGameSubState = 0x44;
}

// Robattle (game state 7) handlers 0x70/0x71 and 0x78/0x79: show a number over each Medabot with
// unkCE bit 2 (unkC8) / bit 3 (unkCD) for 90 frames (guess: damage / repair numbers).
void robattle_effect_a_number_init(void) {
    u32 i;

    update_all_battle_status_sprites();
    iterate_bots_setup_battle_sprites();
    for (i = 0; i <= 5; i++) {
        if (gBattleBots[i].teamState && (gBattleBots[i].effectShownFlags & 4)) {
            set_display_digit_type(&gGameWork.partAbility, gBattleBots[i].buffNumber, 0);
            battle_number_popup_init(&gGameWork.partAbility, i);
        }
    }
    play_sound_effect(0x5B);
    gGameWork.stepCounter = 0;
    gGameSubState++;
}

void robattle_effect_a_number_update(void) {
    u32 i;

    update_all_battle_status_sprites();
    for (i = 0; i <= 5; i++) {
        if (gBattleBots[i].teamState && (gBattleBots[i].effectShownFlags & 4))
            battle_number_popup_update(i);
    }
    if (++gGameWork.stepCounter == 90) {
        for (i = 0; i <= 5; i++) {
            if (gBattleBots[i].teamState && (gBattleBots[i].effectShownFlags & 4)) {
                gBattleBots[i].effectShownFlags &= ~4;
                clear_battle_sprite_slot(10 + i * 4, 3);
            }
        }
        gBattleWork.resultFlags &= ~8;
        gGameSubState = 0x44;
    }
}

void robattle_effect_b_number_init(void) {
    u32 i;

    update_all_battle_status_sprites();
    iterate_bots_setup_battle_sprites();
    for (i = 0; i <= 5; i++) {
        if (gBattleBots[i].teamState && (gBattleBots[i].effectShownFlags & 8)) {
            set_display_digit_type(&gGameWork.partAbility, gBattleBots[i].statusNumber, 1);
            battle_number_popup_init(&gGameWork.partAbility, i);
        }
    }
    play_sound_effect(0x5B);
    gGameWork.stepCounter = 0;
    gGameSubState++;
}

void robattle_effect_b_number_update(void) {
    u32 i;

    update_all_battle_status_sprites();
    for (i = 0; i <= 5; i++) {
        if (gBattleBots[i].teamState && (gBattleBots[i].effectShownFlags & 8))
            battle_number_popup_update(i);
    }
    if (++gGameWork.stepCounter == 90) {
        for (i = 0; i <= 5; i++) {
            if (gBattleBots[i].teamState && (gBattleBots[i].effectShownFlags & 8)) {
                gBattleBots[i].effectShownFlags &= ~8;
                clear_battle_sprite_slot(10 + i * 4, 3);
            }
        }
        gBattleWork.resultFlags &= ~0x10;
        gGameSubState = 0x44;
    }
}

// Robattle handlers 0x90-0x99 and 0xA0-0xAF: exchange each side's chosen parts (action) over the
// serial link (gLinkPackets), guess: link Robattle (only when gGameWork.skipBotSetup = 1).
void robattle_link_message_open(void) {
    text_window_init(1, 0, 0);
    gGameSubState++;
}

void robattle_link_message_show(void) {
    if (run_message(gLinkMessages[1]))
        gGameSubState++;
}

void robattle_link_sync(void) {
    if (link_sync_both_ready()) {
        gLinkPackets.sendData = 0;
        gGameWork.stepTimer = 0;
        gGameSubState++;
    }
}

void robattle_link_delay(void) {
    if (gGameWork.stepTimer == 16)
        gGameSubState++;
    else
        gGameWork.stepTimer++;
}

void robattle_link_exchange_init(void) {
    gBattleWork.unk51 = 0;
    gBattleWork.unk52 = 0;
    gBattleWork.unk53 = 0;
    gBattleWork.unk54 = 0;
    gBattleWork.unk1A6 = 0;
    gBattleWork.unk1AF = 0;
    gBattleWork.unk1B0 = 1;
    gGameWork.stepTimer = 0;
    gGameSubState++;
}

void robattle_link_exchange_commands(void) {
    u16 r;
    s16 flag;

    if (gBattleWork.unk51 != 3) {
        gLinkPackets.sendData =
            gBattleBots[gBattleWork.unk51].chosenAction + (flag = ((gBattleWork.unk1AF << 8) & 0x100) + 0x8000);
        gGameWork.stepTimer++;
        if (!(gGameWork.stepTimer & 1)) {
            gBattleWork.unk1AF ^= 1;
            gBattleWork.unk51++;
        }
    }
    if (gBattleWork.unk53 != 3) {
        r = gLinkPackets.recv[gLinkPlayerId ^ 1][1];
        if ((r & 0x8000) && ((u16)(r & 0x100) >> 8) != gBattleWork.unk1B0) {
            gBattleWork.unk1B0 ^= 1;
            gBattleBots[gBattleWork.unk53 + 3].chosenAction = r;
            gBattleWork.unk53++;
        }
    }
    if (gBattleWork.unk51 == 3) {
        if (gBattleWork.unk53 == 3) {
            gGameSubState++;
            gGameWork.stepTimer = 0;
        }
    }
}

void robattle_link_apply_opponent_parts(void) {
    gLinkPackets.sendData = 0;
    battle_bot_select_part(3, gBattleBots[3].chosenAction);
    battle_bot_select_part(4, gBattleBots[4].chosenAction);
    battle_bot_select_part(5, gBattleBots[5].chosenAction);
    gGameSubState++;
}

void robattle_link_apply_opponent_medaforces(void) {
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gBattleBots[i + 3].chosenAction > 3)
            battle_bot_select_medaforce(i + 3, gBattleBots[i + 3].chosenAction - 4);
    }
    gGameSubState++;
}

void robattle_link_message_close(void) {
    if (game_state_execute_handler_a())
        gGameSubState++;
}

void robattle_link_start_banner(void) {
    gGameSubState = 0x40;
}

void robattle_link_exchange_bot_command(void) {
    u16 r;

    if (gBattleWork.actor <= 2) {
        gLinkPackets.sendData = gBattleBots[gBattleWork.actor].chosenAction + 0x8000;
        if (gBattleWork.unk1AF)
            goto next;
        gBattleWork.unk1AF = 1;
    } else {
        r = gLinkPackets.recv[gLinkPlayerId ^ 1][1];
        if (r & 0x8000) {
            gBattleBots[gBattleWork.actor].chosenAction = r;
        next:
            gGameSubState++;
        }
    }
}

void robattle_link_skip_step(void) {
    gGameSubState++;
}

void robattle_link_apply_bot_part(void) {
    if (gBattleWork.actor > 2)
        battle_bot_select_part(gBattleWork.actor, gBattleBots[gBattleWork.actor].chosenAction);
    gGameSubState++;
}

void robattle_link_apply_bot_medaforce(void) {
    if (gBattleWork.actor > 2 && gBattleBots[gBattleWork.actor].chosenAction > 3)
        battle_bot_select_medaforce(gBattleWork.actor, gBattleBots[gBattleWork.actor].chosenAction - 4);
    gGameSubState++;
}

void robattle_link_resume_turn(void) {
    gLinkPackets.sendData = 0;
    gGameSubState = 0x45;
}

void robattle_link_sync_counted(void) {
    gGameWork.stepTimer++;
    if (link_sync_both_ready()) {
        gLinkPackets.sendData = 0;
        gGameSubState++;
    }
}

void robattle_link_sync_delay(void) {
    if (gGameWork.stepTimer)
        gGameWork.stepTimer--;
    else
        gGameSubState++;
}
