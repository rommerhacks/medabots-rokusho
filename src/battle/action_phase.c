#include "global.h"

// Battle state 8, the action phase, every frame: unless waiting on the serial link, runs the gActionPhaseSteps
// step for gGameSubState. Sub-states (runtime-checked in the battle scenario):
//   0x00-0x04 turn cursor over the acting Medabot, then the command check
//   0x10-0x18 no part chosen: charge the Medaforce gauge (or say it is full)
//   0x20-0x22 the command fails: popup + message gBattleWork.messageId
//   0x30-0x39 Medaforce chosen: level / gauge checks, activation animation, then battle state 9
//   0x40-0x45 after an action: a side's leader is down -> win / lose banner and message
//   0x48-0x4D TIME check: time up -> banner and judgement message; 0x4F back to the turn order (state 7)
//   0x50-0x53 leave the battle (fade out to state 6, or 10 for a link battle); 0x58-0x5D link battle sync
//   0x60-0x66 a Medal skill levelled up: popup, skill type and new level
void battle_action_state_update(void) {
    if (link_error_check() == 0) {
        link_clear_send_word();
        update_all_battle_status_sprites();
        gActionPhaseSteps[gGameSubState]();
    }
}

// Resets the actor's status sprites and loads the turn cursor graphics, one step per frame.
void action_phase_load_gfx(void) {
    switch (gGameWork.setupStep) {
    case 0:
        reset_bot_status_and_init_palette_transfers(gBattleWork.actor);
        copy_battle_entity_positions();
        gGameWork.setupStep++;
        break;
    case 1:
        lz_decompress_dispatch(gMissPopupTiles, (void *)0x06014E00);
        gGameWork.setupStep++;
        break;
    case 2:
        CpuFastSet(gUnk_084E2FF8, (void *)0x050002C0, 8);
        gGameSubState++;
        gGameWork.setupStep = 0;
        break;
    }
}

// Turn cursor (sprite 3) above the acting Medabot.
void action_phase_cursor_init(void) {
    gSpriteEntries[3].unk0 = 0xC004;
    gSpriteEntries[3].unk1C = 0;
    gSpriteEntries[3].unk2 = gSpriteEntries[gBattleWork.actor * 4 + 0x5D].unk2;
    gSpriteEntries[3].unk4 = gSpriteEntries[gBattleWork.actor * 4 + 0x5D].unk4 - 4;
    gSpriteEntries[3].unkA = 6;
    gSpriteEntries[3].unkB = 0x81;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x15], 3);
    play_sound_effect(7);
    gGameSubState++;
}

void action_phase_cursor_anim(void) {
    process_sprite_anim_commands(gUnk_083B5F80[0x15], 3);
    if (gSpriteEntries[3].unk22 == 0xFF) {
        clear_battle_sprite_slot(3, 1);
        gGameSubState++;
    }
}

// Fails with message 4 when the acting Medabot has unkBD bit 0 set; no part chosen (action == 0) goes to
// sub-state 0x10, otherwise on to action_phase_resolve_command.
void action_phase_check_command(void) {
    if (gBattleBots[gBattleWork.actor].stateFlags & 1) {
        gBattleWork.messageId = 4;
        gGameSubState = 0x20;
    } else if (gBattleBots[gBattleWork.actor].chosenAction == 0)
        gGameSubState = 0x10;
    else
        gGameSubState++;
}

void action_phase_resolve_command(void) {
    battle_set_actor_side(gBattleWork.actor);
    if (gBattleBots[gBattleWork.actor].stateFlags & 1) {
        gBattleWork.messageId = 4;
        gGameSubState = 0x20;
        return;
    }
    if (gBattleBots[gBattleWork.actor].chosenAction <= 3 &&
        gBattleBots[gBattleWork.actor].parts[gBattleBots[gBattleWork.actor].chosenAction - 1].unk11 == 0) {
        gBattleWork.messageId = 5;
        gGameSubState = 0x20;
        return;
    }
    if (gBattleBots[gBattleWork.actor].statusType == 0x2B &&
        gBattleBots[gBattleWork.actor].statusPart == gBattleBots[gBattleWork.actor].chosenAction) {
        gBattleWork.messageId = 6;
        gGameSubState = 0x20;
        return;
    }
    if (gBattleBots[gBattleWork.actor].chosenAction > 3) {
        gBattleWork.actorPart = gBattleBots[gBattleWork.actor].chosenAction - 4;
        gGameSubState = 0x30;
        return;
    }
    gBattleWork.skillGrowthOn = 1;
    select_next_bot_and_action(gBattleWork.actor);
    if (part_skill_is_passive(gBattleWork.actor, gBattleBots[gBattleWork.actor].chosenAction - 1)) {
        gBattleWork.messageId = 7;
        gGameSubState = 0x20;
        return;
    }
    if (gBattleBots[gBattleWork.actor].chosenAction == 1 && gBattleWork.unk118 != 1) {
        if (gBattleBots[gBattleWork.actor].parts[0].unk10 == 0) {
            gBattleWork.messageId = 8;
            gGameSubState = 0x20;
            return;
        }
        gBattleBots[gBattleWork.actor].parts[0].unk10--;
    }
    if (gBattleBots[gBattleWork.actor].unkE0) {
        if (gBattleBots[gBattleWork.actor].parts[gBattleBots[gBattleWork.actor].chosenAction - 1].data[1] == 0x21) {
            if (gBattleBots[gBattleBots[gBattleWork.actor].unkE0 - 1].teamState) {
                gBattleWork.messageId = 9;
                gGameSubState = 0x20;
                return;
            }
        } else if (gBattleBots[gBattleBots[gBattleWork.actor].unkE0 - 1].teamState == 0) {
            gBattleWork.messageId = 0xA;
            gGameSubState = 0x20;
            return;
        }
    }
    if (gBattleBots[gBattleWork.actor].unkE1) {
        if (gBattleBots[gBattleWork.actor].parts[gBattleBots[gBattleWork.actor].chosenAction - 1].data[1] == 0x20) {
            if (gBattleBots[gBattleBots[gBattleWork.actor].unkE0 - 1]
                    .parts[gBattleBots[gBattleWork.actor].unkE1 - 1]
                    .unk11) {
                gBattleWork.messageId = 0xB;
                gGameSubState = 0x20;
                return;
            }
        } else if (gBattleBots[gBattleBots[gBattleWork.actor].unkE0 - 1]
                       .parts[gBattleBots[gBattleWork.actor].unkE1 - 1]
                       .unk11 == 0) {
            gBattleWork.messageId = 0xC;
            gGameSubState = 0x20;
            return;
        }
    }
    gBattleWork.actorSkill =
        gBattleBots[gBattleWork.actor].parts[gBattleBots[gBattleWork.actor].chosenAction - 1].data[1];
    gBattleWork.actorPart = gBattleBots[gBattleWork.actor].chosenAction - 1;
    gGameState = 9;
    gGameSubState = 0;
}

void action_phase_goto_end_check(void) {
    gGameSubState = 0x40;
}

void action_phase_goto_exit(void) {
    gGameSubState = 0x50;
}

void action_phase_next_turn(void) {
    CpuFastSet(gTargetLinePalette, (void *)0x05000300, 8);
    CpuFastSet(gTargetArrowsPalette, (void *)0x05000320, 8);
    CpuFastSet(gUnk_084E2F38, (void *)0x05000340, 8);
    gGameState = 7;
    gGameSubState = 0x46;
}

// No part chosen: a full gauge (80) shows message 0 instead of charging.
void action_phase_charge_check(void) {
    if (gBattleBots[gBattleWork.actor].medaforceGauge == 0x50)
        gGameSubState++;
    else {
        battle_substeps_reset();
        gGameSubState = 0x14;
    }
}

void action_phase_fail_popup(void) {
    if (miss_popup_run())
        gGameSubState++;
}

// guess: message 0 says the Medaforce gauge is already full.
void action_phase_show_gauge_full_message(void) {
    if (battle_message_show(0))
        gGameSubState++;
}

void action_phase_show_target_panels(void) {
    if (target_panels_show(0))
        gGameSubState++;
}

void action_phase_show_charge_message(void) {
    target_panels_show(0);
    if (battle_message_show(1))
        gGameSubState++;
}

// Charge sparkles; unk51 = gauge fill amount, 80 with unkC0 bit 3 set, else 40.
void action_phase_charge_init(void) {
    target_panels_show(0);
    play_sound_effect(0x51);
    if (gBattleBots[gBattleWork.actor].guardFlags & 8)
        gBattleWork.unk51 = 0x50;
    else
        gBattleWork.unk51 = 0x28;
    mf_charge_sparkles_init(gBattleWork.actor);
    gGameSubState++;
}

void action_phase_charge_fill(void) {
    u32 done;

    target_panels_show(0);
    done = medaforce_gauge_fill_step(gBattleWork.actor);
    done += mf_charge_sparkles_update(gBattleWork.actor);
    if (done == 2) {
        clear_battle_ui_tilemaps();
        battle_substeps_reset();
        gGameSubState++;
    }
}

void action_phase_show_message(void) {
    if (battle_message_show(gBattleWork.messageId))
        gGameSubState++;
}

// After an action: Medal skill levels, then record 0 (our leader) down = lost (unk9C 2), record 3 (their
// leader) down = won (unk9C 1); otherwise on to the TIME check.
void action_phase_end_check(void) {
    lz_decompress_dispatch(gUnk_084C6A98, (void *)0x06017400);
    increment_medal_skill_level(gBattleWork.actor);
    battle_action_cleanup(gBattleWork.actor);
    gGameWork.unk9C = 0;
    if (gBattleBots[0].teamState == 0) {
        gGameWork.unk9C = 2;
        fade_out_music(4);
        play_sound_effect(0x6F);
        gGameSubState++;
    } else if (gBattleBots[3].teamState == 0) {
        gGameWork.unk9C = 1;
        fade_out_music(4);
        play_sound_effect(0x6F);
        gGameSubState++;
    } else
        gGameSubState = 0x48;
}

// End banner (sprite 0x21, tile 0x902) zooming in at the screen centre.
void action_phase_win_banner_init(void) {
    lz_decompress_dispatch(gUnk_084C84E4, (void *)0x06014800);
    CpuFastSet(gUnk_084E2FD8, (void *)0x050003E0, 8);
    gSpriteEntries[0x21].unk0 = 0xC624;
    gSpriteEntries[0x21].unk1C = 0;
    gSpriteEntries[0x21].unk2 = 0x78;
    gSpriteEntries[0x21].unk4 = 0x40;
    gSpriteEntries[0x21].unkA = 0xF;
    gSpriteEntries[0x21].unkB = 0xC0;
    gSpriteEntries[0x21].unk6 = 0x902;
    gSpriteEntries[0x21].unk9 = 0x80;
    gSpriteEntries[0x21].unk8 = 0x40;
    gGameSubState++;
}

void action_phase_banner_zoom_in(void) {
    if (gSpriteEntries[0x21].unk9 == 0x40) {
        gGameWork.unk86 = 0;
        gGameSubState++;
    } else
        gSpriteEntries[0x21].unk9 -= 8;
}

void action_phase_win_banner_hold(void) {
    if (gGameWork.unk86 == 0x5A) {
        if (gSpriteEntries[0x21].unk9 == 8) {
            play_song(0x1C);
            clear_battle_sprite_slot(0x21, 1);
            text_window_init(1, 2, 0);
            gGameSubState++;
        } else
            gSpriteEntries[0x21].unk9 -= 8;
    } else
        gGameWork.unk86++;
}

void action_phase_time_up_banner_hold(void) {
    if (gGameWork.unk86 == 0x5A) {
        if (gSpriteEntries[0x21].unk9 == 8) {
            clear_battle_sprite_slot(0x21, 1);
            text_window_init(1, 2, 0);
            gGameSubState++;
        } else
            gSpriteEntries[0x21].unk9 -= 8;
    } else
        gGameWork.unk86++;
}

// Puts the winner's name (player, opponent or link partner) in the message buffer.
void action_phase_show_winner_message(void) {
    if (gGameWork.unk9C == 1)
        memcpy_bytes_0803F63C(gPlayerName, gGameWork.textBuf, 0xE);
    else if (gGameWork.skipBotSetup != 1)
        memcpy_bytes_0803F63C(gUnk_083C3F38[gBattleWork.encounterMessage], gGameWork.textBuf, 0x12);
    else
        memcpy_bytes_0803F63C(gLinkPartnerName, gGameWork.textBuf, 0x12);
    if (run_message(gUnk_083C65C4[2]))
        gGameSubState++;
}

// TIME left: a levelled-up Medal skill (unk165) shows the level-up popup, else next turn. Time up: judge it.
void action_phase_time_check(void) {
    if (gBattleWork.timeLeft) {
        if (gBattleWork.skillLevelledUp)
            gGameSubState = 0x60;
        else
            gGameSubState = 0x4F;
    } else {
        robattle_judge_time_up();
        play_song(0x11);
        gGameSubState++;
    }
}

void action_phase_time_up_banner_init(void) {
    lz_decompress_dispatch(gUnk_084C84E4, (void *)0x06014800);
    CpuFastSet(gUnk_084E2FD8, (void *)0x050003E0, 8);
    gSpriteEntries[0x21].unk0 = 0xC624;
    gSpriteEntries[0x21].unk1C = 0;
    gSpriteEntries[0x21].unk2 = 0x78;
    gSpriteEntries[0x21].unk4 = 0x40;
    gSpriteEntries[0x21].unkA = 0xF;
    gSpriteEntries[0x21].unkB = 0xC0;
    gSpriteEntries[0x21].unk6 = 0x903;
    gSpriteEntries[0x21].unk9 = 0x80;
    gSpriteEntries[0x21].unk8 = 0x40;
    gGameSubState++;
}

void action_phase_show_time_up_message(void) {
    if (gGameWork.unk9C == 1)
        memcpy_bytes_0803F63C(gPlayerName, gGameWork.textBuf, 0xE);
    else if (gGameWork.skipBotSetup != 1)
        memcpy_bytes_0803F63C(gUnk_083C3F38[gBattleWork.encounterMessage], gGameWork.textBuf, 0x12);
    else
        memcpy_bytes_0803F63C(gLinkPartnerName, gGameWork.textBuf, 0x12);
    if (run_message(gUnk_083C65C4[3]))
        gGameSubState++;
}

void action_phase_exit_begin(void) {
    if (gGameWork.skipBotSetup != 1) {
        fade_out_music(8);
        gGameSubState++;
    } else
        gGameSubState = 0x58;
}

void action_phase_exit_fade_init(void) {
    palette_backup_from_hardware();
    gGameWork.unk84 = 0;
    gGameSubState++;
}

void action_phase_exit_fade_step(void) {
    if (gGameWork.unk84 <= 8) {
        bg_palettes_blend_masked_now(0, gGameWork.unk84 * 4, 0xFFFF);
        obj_palettes_blend_masked_now(0, gGameWork.unk84 * 4, 0xFFFF);
        gGameWork.unk84++;
    } else
        gGameSubState++;
}

// Leaves the battle: after-battle state 6, or link state 10 for a link battle (unk89 == 1).
void action_phase_exit(void) {
    gVBlankCallback = empty_callback;
    gGameWork.unk132 = 1;
    if (gGameWork.skipBotSetup != 1) {
        gGameState = 6;
        gGameSubState = 0x30;
    } else {
        gGameState = 10;
        gGameSubState = 0x20;
    }
}

// Medal skill level-up popup above the acting Medabot (sprite 0x21), then the skill type (0x22) and level.
void action_phase_level_up_init(void) {
    lz_decompress_dispatch(gUnk_084D796C, (void *)0x06014800);
    gSpriteEntries[0x21].unk0 = 0xC404;
    gSpriteEntries[0x21].unk1C = 0;
    gSpriteEntries[0x21].unk2 = gSpriteEntries[gBattleWork.actor * 4 + 0x5D].unk2;
    gSpriteEntries[0x21].unk4 = gSpriteEntries[gBattleWork.actor * 4 + 0x5D].unk4 - 4;
    gSpriteEntries[0x21].unkA = 0xC;
    gSpriteEntries[0x21].unkB = 0x80;
    gSpriteEntries[0x21].unk6 = 0x5800;
    gSpriteEntries[0x21].unk23 = 0;
    play_sound_effect(0x2A);
    gGameSubState++;
}

void action_phase_level_up_anim(void) {
    if (advance_sprite_anim_frame(0x21, 0))
        gGameSubState++;
}

void action_phase_level_up_skill_init(void) {
    gSpriteEntries[0x22].unk0 = 0xC404;
    gSpriteEntries[0x22].unk1C = 0;
    gSpriteEntries[0x22].unk2 = gSpriteEntries[gBattleWork.actor * 4 + 0x5D].unk2 - 0x10;
    gSpriteEntries[0x22].unk4 = gSpriteEntries[gBattleWork.actor * 4 + 0x5D].unk4 + 4;
    gSpriteEntries[0x22].unkA = gLevelUpSkillPalettes[gBattleWork.levelUpSkill];
    gSpriteEntries[0x22].unkB = 0x80;
    gSpriteEntries[0x22].unk6 = 0x5801 + gBattleWork.levelUpSkill;
    gSpriteEntries[0x22].unk23 = 0;
    play_sound_effect(0x2A);
    gGameSubState++;
}

void action_phase_level_up_skill_slide(void) {
    if (sprite_slide_x_step(0x22, 0))
        gGameSubState++;
}

void action_phase_level_up_digits_init(void) {
    lz_decompress_dispatch(gUnk_084D6BFC, (void *)0x06017E00);
    set_display_digit_type(&gGameWork.partAbility, gBattleWork.levelUpLevel, 2);
    battle_text_popup_init_at(&gGameWork.partAbility, gBattleWork.actor, 0x23,
                              gSpriteEntries[gBattleWork.actor * 4 + 0x5D].unk2 + 0x18,
                              gSpriteEntries[gBattleWork.actor * 4 + 0x5D].unk4 + 4);
    gGameWork.unk84 = 0;
    gGameSubState++;
}

void action_phase_level_up_wait(void) {
    battle_popup_update_slot(&gGameWork.partAbility, gBattleWork.actor, 0x23);
    if (++gGameWork.unk84 == 0x78) {
        clear_battle_sprite_slot(0x21, 2);
        clear_battle_sprite_slot(gBattleWork.actor * 4 + 0x23, 4);
        gGameSubState++;
    }
}

void action_phase_level_up_done(void) {
    gGameSubState = 0x4F;
}

// Medaforce chosen (unkA7 = slot 0-2): blocked (unk58, message 0x79), Medal level too low for the slot
// (below 10 / 30 / 60, message 0x36) or gauge not full (message 0x37) fail; otherwise activate it.
void action_phase_medaforce_check(void) {
    battle_substeps_reset();
    if (gBattleWork.medaforceBlocked) {
        gBattleWork.messageId = 0x79;
        gGameSubState++;
    } else if (gBattleWork.actorPart == 0 && gBattleBots[gBattleWork.actor].medal.level <= 9) {
        gBattleWork.messageId = 0x36;
        gGameSubState++;
    } else if (gBattleWork.actorPart == 1 && gBattleBots[gBattleWork.actor].medal.level <= 0x1D) {
        gBattleWork.messageId = 0x36;
        gGameSubState++;
    } else if (gBattleWork.actorPart == 2 && gBattleBots[gBattleWork.actor].medal.level <= 0x3B) {
        gBattleWork.messageId = 0x36;
        gGameSubState++;
    } else if (gBattleBots[gBattleWork.actor].medaforceGauge != 0x50) {
        gBattleWork.messageId = 0x37;
        gGameSubState++;
    } else
        gGameSubState = 0x34;
}

void action_phase_medaforce_anim_init(void) {
    target_panels_show(0);
    CpuFastSet(gUnk_084E3018, (void *)0x050002E0, 8);
    gSpriteEntries[0x21].unk0 = ((gBattleWork.battlefieldParams[3] + 2) << 10) | 0xC004;
    gSpriteEntries[0x21].unk1C = 0;
    gSpriteEntries[0x21].unk2 = gSpriteEntries[gBattleWork.actor * 4 + 0x5D].unk2;
    gSpriteEntries[0x21].unk4 = gSpriteEntries[gBattleWork.actor * 4 + 0x5D].unk4 - 4;
    gSpriteEntries[0x21].unkA = 7;
    gSpriteEntries[0x21].unkB = 0x81;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x4D], 0x21);
    gSpriteEntries[0x22].unk0 = ((gBattleWork.battlefieldParams[3] + 2) << 10) | 0xC004;
    gSpriteEntries[0x22].unk1C = 0;
    gSpriteEntries[0x22].unk2 = gSpriteEntries[gBattleWork.actor * 4 + 0x5D].unk2;
    gSpriteEntries[0x22].unk4 = gSpriteEntries[gBattleWork.actor * 4 + 0x5D].unk4 - 4;
    gSpriteEntries[0x22].unkA = 7;
    gSpriteEntries[0x22].unkB = gBattleWork.actor * 4 + 0x59;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x4E], 0x22);
    gBattleWork.unk51 = gBattleBots[gBattleWork.actor].medaforce[2];
    gGameSubState++;
}

void action_phase_medaforce_anim(void) {
    target_panels_show(0);
    medaforce_gauge_drain_step(gBattleWork.actor);
    process_sprite_anim_commands(gUnk_083B5F80[0x4D], 0x21);
    process_sprite_anim_commands(gUnk_083B5F80[0x4E], 0x22);
    if (gSpriteEntries[0x21].unk22 == 0xFF) {
        clear_battle_ui_tilemaps();
        battle_substeps_reset();
        clear_battle_sprite_slot(0x21, 2);
        gGameSubState++;
    }
}

void action_phase_medaforce_name(void) {
    memcpy_bytes_0803F63C((void *)gMedaforceNames[gBattleBots[gBattleWork.actor].medaforce[0]], gGameWork.textBuf,
                          0x11);
    gBattleWork.messageId = 0x38;
    gGameSubState++;
}

// Runs the Medaforce as action unkA8[0] + 0x50 in battle state 9.
void action_phase_start_medaforce(void) {
    gBattleWork.skillGrowthOn = 1;
    gBattleWork.actorSkill = gBattleBots[gBattleWork.actor].medaforce[0] + 0x50;
    gBattleBots[gBattleWork.actor].unkE0 = 0;
    gBattleBots[gBattleWork.actor].unkE1 = 0;
    gGameState = 9;
    gGameSubState = 0;
}

void action_phase_link_text_init(void) {
    text_window_init(1, 0, 0);
    gGameSubState++;
}

void action_phase_link_message(void) {
    if (run_message(gLinkMessages[1]))
        gGameSubState++;
}

void action_phase_link_sync(void) {
    if (link_sync_both_ready()) {
        gGameWork.unk86 = 0;
        gGameSubState++;
    }
}

void action_phase_link_wait(void) {
    if (gGameWork.unk86 == 8)
        gGameSubState++;
    else
        gGameWork.unk86++;
}

void action_phase_link_finish(void) {
    if (game_state_execute_handler_a())
        gGameSubState++;
}

void action_phase_link_exit(void) {
    fade_out_music(8);
    gGameSubState = 0x51;
}
