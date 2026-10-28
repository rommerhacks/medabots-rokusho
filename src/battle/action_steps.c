// Battle action step handlers. gBattleMessageSteps is one long table of step lists; each runner (battle_message_show
// for messages, target_panels_show, miss_popup_run ...) calls entry [step] of its own sub-table and the handlers
// advance the step counter. Then come the runners of script opcodes 0x04-0x09 and 0x19-0x1A (trap_hit_run ...
// closeup_enter_run; their order in an attack was seen at runtime) and of opcodes 0x1E-0x24 (gActionScriptCommands):
// attack_hit_run (0x1E: the hit itself, with its miss / nullified / absorbed branches), status_attack_run (0x1F:
// Bug, Thunder, Wave, Fire... status skills), closeup_exit_run (0x20), bot_defeat_run (0x21: "A's function ceased"),
// reaction_run (0x22), sacrifice_run (0x23: Sacrifice breaks the attacker's part) and destroy_check_run (0x24:
// Destroy needs a target facing away). The list continues in defend_heal_skills.c.
// Called from the battle action state code (state 8) and the action script commands (state 9).

#include "global.h"
#include "constants/sprites.h"

// Hidden function (no callers): moves the record's target (unkE0, record + 1) to the same slot on the other side
// (gTargetSwapSideTable: 1-3 <-> 4-6, 0 stays 0).
void bot_target_swap_side(u32 rec) {
    gBattleBots[rec].unkE0 = gTargetSwapSideTable[gBattleBots[rec].unkE0];
}

// The battle message runner: open the window, print message msg, finish; 1 when done.
u32 battle_message_show(u32 msg) {
    gBattleWork.unkA1[1] = msg;
    gBattleMessageSteps[gBattleWork.unkA1[0]]();
    if (gBattleWork.unkA1[0] == 3) {
        gBattleWork.unkA1[0] = 0;
        return 1;
    }
    return 0;
}

void battle_message_step_open(void) {
    battle_message_open();
    gBattleWork.unkA1[0]++;
}

void battle_message_step_print(void) {
    if (battle_message_print(gBattleWork.unkA1[1]))
        gBattleWork.unkA1[0]++;
}

void battle_message_step_finish(void) {
    if (battle_message_finish())
        gBattleWork.unkA1[0]++;
}

// The "MISS!!" popup (seen at runtime in the battle scenario): load its graphics, spawn it above the acting
// Medabot, let it drop 4 px, hold it 60 frames (A skips); 1 when done.
u32 miss_popup_run(void) {
    gMissPopupSteps[gBattleWork.unk9C[0]]();
    if (gBattleWork.unk9C[0] == 4) {
        gBattleWork.unk9C[0] = 0;
        return 1;
    }
    return 0;
}

void miss_popup_load(void) {
    lz_decompress_dispatch(gMissPopupTiles, (void *)0x06014E00);
    CpuFastSet(gMissPopupPalette, (void *)0x050002C0, 8);
    gBattleWork.unk9C[0]++;
}

void miss_popup_spawn(void) {
    gSpriteEntries[3].flags = SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[3].frame_table = 0;
    gSpriteEntries[3].x = gSpriteEntries[gBattleWork.actor * 4 + 0x5D].x;
    gSpriteEntries[3].y = gSpriteEntries[gBattleWork.actor * 4 + 0x5D].y - 12;
    gSpriteEntries[3].palette = 6;
    gSpriteEntries[3].frame = 0xA11;
    gSpriteEntries[3].order = 0x81;
    play_sound_effect(0x2F);
    gBattleWork.unk9C[0]++;
}

void miss_popup_drop(void) {
    if (gFrameCounter & 1) {
        gSpriteEntries[3].y++;
        if (gSpriteEntries[3].y == gSpriteEntries[gBattleWork.actor * 4 + 0x5D].y + 4) {
            gBattleWork.unk9C[1] = 0;
            gBattleWork.unk9C[0]++;
        }
    }
}

void miss_popup_wait(void) {
    gBattleWork.unk9C[1]++;
    if (gGameWork.skipBotSetup == 0 && (KEYS_LO(gRepeatKeys) & 1))
        gBattleWork.unk9C[1] = 60;
    if (gBattleWork.unk9C[1] == 60) {
        clear_battle_sprite_slot(3, 1);
        gBattleWork.unk9C[0]++;
    }
}

// Shows who acts on whom: a pointer line from the acting Medabot (unk87) and its panel; with show_target != 0
// the arrows then run to the target's (unk88) panel. 1 once the panels are up (the last step idles).
u32 target_panels_show(u32 show_target) {
    gBattleWork.unk9C[1] = show_target;
    gTargetPanelSteps[gBattleWork.unk9C[0]]();
    if (gBattleWork.unk9C[2] != 0)
        return 1;
    return 0;
}

void target_panels_line_init(void) {
    CpuFastSet(gTargetLinePalette, (void *)0x05000300, 8);
    bot_pointer_line_init(gBattleWork.actor);
    gBattleWork.unk9C[0]++;
}

void target_panels_line_extend(void) {
    if (bot_pointer_line_extend(gBattleWork.actor))
        gBattleWork.unk9C[0]++;
}

void target_panels_actor_frame(void) {
    bot_pointer_line_animate(gBattleWork.actor);
    draw_bot_panel_frame(gBattleWork.actor);
    gBattleWork.unk9C[0]++;
}

void target_panels_actor_panel(void) {
    bot_pointer_line_animate(gBattleWork.actor);
    render_bot_name_sprites(gBattleWork.actor);
    draw_bot_status_panel(gBattleWork.actor);
    if (gBattleWork.unk9C[1] == 0) {
        gBattleWork.unk9C[2] = 1;
        gBattleWork.unk9C[0]++;
    } else
        gBattleWork.unk9C[0] = 5;
}

void target_panels_idle(void) {
    bot_pointer_line_animate(gBattleWork.actor);
}

void target_panels_arrows_init(void) {
    CpuFastSet(gTargetArrowsPalette, (void *)0x05000320, 8);
    bot_pointer_line_animate(gBattleWork.actor);
    target_arrows_init(gBattleWork.actor);
    gBattleWork.unk9C[0]++;
}

void target_panels_arrows_slide(void) {
    bot_pointer_line_animate(gBattleWork.actor);
    if (target_arrows_slide(gBattleWork.actor))
        gBattleWork.unk9C[0]++;
}

void target_panels_target_frame(void) {
    bot_pointer_line_animate(gBattleWork.actor);
    target_arrows_animate(gBattleWork.actor);
    draw_bot_panel_frame(gBattleWork.target);
    gBattleWork.unk9C[0]++;
}

void target_panels_target_panel(void) {
    bot_pointer_line_animate(gBattleWork.actor);
    target_arrows_animate(gBattleWork.actor);
    render_bot_name_sprites(gBattleWork.target);
    draw_bot_status_panel(gBattleWork.target);
    gBattleWork.unk9C[2] = 1;
    gBattleWork.unk9C[0]++;
}

void target_panels_arrows_idle(void) {
    bot_pointer_line_animate(gBattleWork.actor);
    target_arrows_animate(gBattleWork.actor);
}

// Script opcode 0x04: a trap (Grap Trap / Shot Trap / Attack Clr) laid on the acting Medabot's side by the other side
// (trap_apply, unk28[side]) springs on it. unkAB = 0 the action goes on, 1 it was stopped (Attack Clr), 2 the
// actor's head broke.
void trap_hit_run(void) {
    gBattleWork.stepDone = 0;
    gTrapHitSteps[gBattleWork.step]();
}

// Does the trap catch this action? Grap Trap (0xA) catches part kinds 0-1, Shot Trap (0xB) kinds 2-3, Attack Clr
// (0xC) any attack; type 0x5A (unk51 3) is the trap a Medaforce lays
// (medaforce_effects). unkA6 = the "Caught in a ..."
// message. Bit 1 of the actor's unkC0, or a part with skill 0x15 (combat_helpers), keeps it out.
void trap_hit_check(void) {
    struct BattleWork *b;
    u32 r;
    u32 type;
    u32 k;

    if (gBattleBots[(b = &gBattleWork)->actor].guardFlags & 2)
        goto fail;
    r = bot_has_break_form_part(b->actor);
    if (r != 0)
        goto fail;
    type = b->traps[b->actorSide].skill;
    if (type == 0xA) {
        k = gBattleBots[b->actor].parts[gBattleBots[b->actor].chosenAction - 1].data[2];
        if (k == 0)
            goto okA;
        if (k != 1)
            goto fail;
    okA:
        b->messageId = 0xE;
        b->unk51 = r;
        b->step++;
    } else if (type == 0xB) {
        k = gBattleBots[b->actor].parts[gBattleBots[b->actor].chosenAction - 1].data[2];
        if (k == 2)
            goto okB;
        if (k != 3)
            goto fail;
    okB:
        b->messageId = 0xF;
        b->unk51 = 1;
        b->step++;
    } else if (type == 0xC) {
        if (gBattleBots[b->actor].parts[gBattleBots[b->actor].chosenAction - 1].data[2] > 3)
            goto fail;
        b->messageId = 0x10;
        b->unk51 = 2;
        b->step++;
    } else if (type == 0x5A) {
        if (gBattleBots[b->actor].parts[gBattleBots[b->actor].chosenAction - 1].data[2] > 3)
            goto fail;
        b->messageId = 0x11;
        b->unk51 = 3;
        b->step++;
    } else {
    fail:
        b->step = 0x2D;
    }
}

// The trap hits the actor's last part with armor left (legs first) for the trap's stored power.
void trap_hit_calc_damage(void) {
    s32 i;

    for (i = 3; i >= 0; i--) {
        if (gBattleBots[gBattleWork.actor].parts[i].unk11) {
            gBattleWork.damagePart = i;
            break;
        }
    }
    battle_set_damage_vs_armor(gBattleWork.actor, gBattleWork.damagePart,
                               gBattleWork.traps[gBattleWork.actorSide].power);
    gBattleWork.step++;
}

void trap_hit_load_graphics(void) {
    switch (gBattleWork.unk51) {
    case 0:
        lz_decompress_dispatch(gGrapTrapTiles, (void *)0x06014800);
        CpuFastSet(gGrapTrapPalette, (void *)0x050002C0, 8);
        break;
    case 1:
        lz_decompress_dispatch(gShotTrapTiles, (void *)0x06014800);
        CpuFastSet(gShotTrapPalette, (void *)0x050002C0, 8);
        break;
    case 2:
        lz_decompress_dispatch(gAttackClrTrapTiles, (void *)0x06014800);
        CpuFastSet(gAttackClrTrapPalette, (void *)0x050002C0, 8);
        break;
    case 3:
        lz_decompress_dispatch(gMedaforceTrapTiles, (void *)0x06014800);
        CpuFastSet(gMedaforceTrapPalette, (void *)0x050002C0, 8);
        break;
    }
    gBattleWork.step++;
}

void trap_hit_sprite_spawn(void) {
    gSpriteEntries[0x21].flags =
        SPRITE_PRIORITY(gBattleWork.battlefieldParams[3] + 2) |
        // FAKEMATCH: the constant is a negative s16 in the original (literal pool value)
        (s16)(SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_FLAG_AFFINE | SPRITE_FLAG_PART_PALETTE);
    gSpriteEntries[0x21].frame_table = 0;
    gSpriteEntries[0x21].palette = 6;
    gSpriteEntries[0x21].scale_y = 0x40;
    if (gBattleWork.actorSide == 0) {
        gSpriteEntries[0x21].flags |= SPRITE_FLAG_HFLIP;
        gSpriteEntries[0x21].x = 0x68;
    } else
        gSpriteEntries[0x21].x = 0x88;
    switch (gBattleWork.unk51) {
    case 0:
        gSpriteEntries[0x21].order = 5;
        gSpriteEntries[0x21].scale_x = 8;
        gSpriteEntries[0x21].y = 0x3C;
        gBattleWork.unk52 = 0x19;
        battle_sprite_anim_init(gBattleSpriteAnimScripts[0x19], 0x21);
        play_sound_effect(0x3E);
        gBattleWork.step++;
        break;
    case 1:
        gSpriteEntries[0x21].order = 5;
        gSpriteEntries[0x21].scale_x = 8;
        gSpriteEntries[0x21].y = 0x3C;
        gBattleWork.unk52 = 0x1A;
        battle_sprite_anim_init(gBattleSpriteAnimScripts[0x1A], 0x21);
        play_sound_effect(0x3E);
        gBattleWork.step++;
        break;
    case 2:
        gSpriteEntries[0x21].order = 0xF0;
        gSpriteEntries[0x21].scale_x = 0x40;
        gSpriteEntries[0x21].y = -0x2C;
        gSpriteEntries[0x21].frame = 0xD00;
        gSpriteEntries[0x21].unk24 = 8;
        gSpriteEntries[0x21].unk25 = 0;
        gSpriteEntries[0x21].unk30 = 0;
        play_sound_effect(0x61);
        gBattleWork.step = 0x10;
        break;
    case 3:
        gSpriteEntries[0x21].order = 0xF0;
        gSpriteEntries[0x21].scale_x = 0x40;
        gSpriteEntries[0x21].y = -0x2C;
        gSpriteEntries[0x21].frame = 0xE00;
        gSpriteEntries[0x21].unk20 = 0;
        gSpriteEntries[0x21].unk24 = 8;
        gSpriteEntries[0x21].unk25 = 0;
        gSpriteEntries[0x21].unk30 = 0;
        play_sound_effect(0x61);
        gBattleWork.step = 0x10;
        break;
    }
}

void trap_hit_sprite_grow(void) {
    if ((gSpriteEntries[0x21].scale_x += 8) == 0x40) {
        if (gBattleWork.step < 0x20)
            play_sound_effect(0x3F);
        gBattleWork.step++;
    }
}

void trap_hit_sprite_animate(void) {
    set_target_sprite_position(gBattleWork.actor, gFrameCounter, gBattleWork.unk51);
    process_sprite_anim_commands(gBattleSpriteAnimScripts[gBattleWork.unk52], 0x21);
    if (gSpriteEntries[0x21].unk22 == 0xFF) {
        update_target_cursor_position(gBattleWork.actor);
        gBattleWork.step++;
    }
}

void trap_hit_sprite_shrink(void) {
    if (gSpriteEntries[0x21].scale_x == 8) {
        clear_battle_sprite_slot(0x21, 1);
        gBattleWork.step++;
    } else {
        gSpriteEntries[0x21].scale_x -= 8;
    }
}

void trap_hit_damage_popup_init(void) {
    set_display_digit_type(&gGameWork.partAbility, gBattleWork.appliedAmount, 1);
    battle_number_popup_init_slot(&gGameWork.partAbility, gBattleWork.actor, 0x21);
    play_sound_effect(0x5B);
    gGameWork.stepCounter = 0;
    gBattleWork.step++;
}

void trap_hit_damage_popup_wait(void) {
    battle_popup_update_slot(&gGameWork.partAbility, gBattleWork.actor, 0x21);
    if (++gGameWork.stepCounter,
        gGameWork.skipBotSetup == 0 && (KEYS_LO(gRepeatKeys) & 1) && gGameWork.stepCounter > 0x32)
        gGameWork.stepCounter = 0x78;
    if (gGameWork.stepCounter == 0x78) {
        clear_battle_sprite_slot(gBattleWork.actor * 4 + 0x21, 4);
        gBattleWork.step++;
    }
}

// Message 0x12: "Medapart <kind> received <n> damage".
void trap_hit_damage_message(void) {
    memcpy_bytes_0803F63C(gPartKindNames[gBattleWork.damagePart], gGameWork.textBuf, 0xE);
    divide_by_100000_b(gGameWork.textBuf + 0x14, gBattleWork.appliedAmount, 0x35);
    gBattleWork.messageId = 0x12;
    gBattleWork.step++;
}

void trap_hit_apply_damage(void) {
    reduce_bot_part_stat(gBattleWork.actor, gBattleWork.damagePart, gBattleWork.appliedAmount);
    gBattleWork.step++;
}

// Message 0x13 "<kind> Medapart broke" and the break effect if the part broke.
void trap_hit_check_part_broken(void) {
    if (gBattleWork.partBroken) {
        play_sound_effect(0x3B);
        bot_halve_broken_leg_stats(gBattleWork.actor);
        gBattleWork.messageId = 0x13;
        gBattleWork.step = 0x1A;
    } else {
        gBattleWork.step = 0x20;
    }
}

void trap_hit_check_head_broken(void) {
    if (gBattleBots[gBattleWork.actor].parts[0].unk11 == 0) {
        add_bot_to_defeated_list(gBattleWork.actor);
        gBattleWork.step = 0x2F;
    } else {
        gBattleWork.step = 0x20;
    }
}

// Attack Clr (and type 0x5A): the trap drops on the actor and shakes the screen.
void trap_hit_erase_drop(void) {
    if (sprite_move_toward_target(0x21, 0x3C, 0x84)) {
        play_sound_effect(0x41);
        gGameWork.stepCounter = 0;
        gBattleWork.step++;
    }
}

void trap_hit_erase_shake_bg(void) {
    bg3_shake_step(gGameWork.stepCounter);
    if (++gGameWork.stepCounter > 0x1D) {
        play_sound_effect(0x3F);
        gBg3Scroll.y = 0;
        gGameWork.stepCounter = 0;
        gGameWork.stepTimer = gSpriteEntries[0x21].x;
        gBattleWork.step++;
    }
}

void trap_hit_erase_shake_sprite(void) {
    sprite_shake_x_step(0x21, gGameWork.stepCounter, gGameWork.stepTimer);
    if (++gGameWork.stepCounter == 0x5A) {
        gSpriteEntries[0x21].x = gGameWork.stepTimer;
        gBattleWork.step++;
    }
}

void trap_hit_erase_branch(void) {
    if (gBattleWork.unk51 == 2)
        gBattleWork.step++;
    else
        gBattleWork.step = 8;
}

// Message 0x15: "Your attack has been stopped by the Erase Attack Trap".
void trap_hit_erase_message(void) {
    gBattleWork.messageId = 0x15;
    gBattleWork.step++;
}

void trap_hit_goto_wear(void) {
    gBattleWork.step = 0x20;
}

void trap_hit_break_cursor_init(void) {
    lz_decompress_dispatch(gBreakRingTiles, (void *)0x06014800);
    CpuFastSet(gBreakRingPalette, (void *)0x050002E0, 8);
    staggered_sprites_spawn(0x21, gSpriteEntries[0x5A + gBattleWork.actor * 4 + gBattleWork.damagePart].x,
                            gSpriteEntries[0x5A + gBattleWork.actor * 4 + gBattleWork.damagePart].y, 4);
    gBattleWork.step++;
}

void trap_hit_break_cursor_wait(void) {
    if (staggered_sprites_update(0x21, 4))
        gBattleWork.step++;
}

void trap_hit_break_burst_init(void) {
    lz_decompress_dispatch(gHitSparksTiles, (void *)0x06014800);
    CpuFastSet(gHitSparksPalette, (void *)0x050002E0, 8);
    gSpriteEntries[0x21].flags = SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[0x21].frame_table = 0;
    gSpriteEntries[0x21].x = gSpriteEntries[0x5A + gBattleWork.actor * 4 + gBattleWork.damagePart].x;
    gSpriteEntries[0x21].y = gSpriteEntries[0x5A + gBattleWork.actor * 4 + gBattleWork.damagePart].y;
    gSpriteEntries[0x21].palette = 7;
    gSpriteEntries[0x21].order = 0xF0;
    battle_sprite_anim_init(gBattleSpriteAnimScripts[0x22], 0x21);
    gBattleWork.step++;
}

void trap_hit_break_burst_wait(void) {
    process_sprite_anim_commands(gBattleSpriteAnimScripts[0x22], 0x21);
    if (gSpriteEntries[0x21].unk22 == 0xFF) {
        clear_battle_sprite_slot(0x21, 1);
        load_all_bot_part_sprites();
        iterate_bots_setup_battle_sprites();
        switch (gBattleWork.unk51) {
        case 0:
            lz_decompress_dispatch(gGrapTrapTiles, (void *)0x06014800);
            CpuFastSet(gGrapTrapPalette, (void *)0x050002C0, 8);
            break;
        case 1:
            lz_decompress_dispatch(gShotTrapTiles, (void *)0x06014800);
            CpuFastSet(gShotTrapPalette, (void *)0x050002C0, 8);
            break;
        case 2:
            lz_decompress_dispatch(gAttackClrTrapTiles, (void *)0x06014800);
            CpuFastSet(gAttackClrTrapPalette, (void *)0x050002C0, 8);
            break;
        case 3:
            lz_decompress_dispatch(gMedaforceTrapTiles, (void *)0x06014800);
            CpuFastSet(gMedaforceTrapPalette, (void *)0x050002C0, 8);
            break;
        }
        gBattleWork.step = 0xE;
    }
}

// Wear the trap down: Grap / Shot Trap lose half the actor's leg stat (unk12) of durability, Attack Clr one use;
// used up -> the disarm animation.
void trap_hit_wear(void) {
    u8 v;

    if (gBattleWork.unk51 != 2) {
        v = gBattleBots[gBattleWork.actor].parts[3].unk12 >> 1;
        if (v >= gBattleWork.traps[gBattleWork.actorSide].durability) {
            gBattleWork.step++;
        } else {
            gBattleWork.traps[gBattleWork.actorSide].durability -= v;
            gBattleWork.step = 0x2D;
        }
    } else {
        gBattleWork.traps[gBattleWork.actorSide].durability--;
        if (gBattleWork.traps[gBattleWork.actorSide].durability == 0)
            gBattleWork.step++;
        else
            gBattleWork.step = 0x2E;
    }
}

void trap_disarm_load_graphics(void) {
    switch (gBattleWork.unk51) {
    case 0:
        lz_decompress_dispatch(gGrapTrapTiles, (void *)0x06015400);
        break;
    case 1:
        lz_decompress_dispatch(gShotTrapTiles, (void *)0x06015400);
        break;
    case 2:
        lz_decompress_dispatch(gAttackClrTrapTiles, (void *)0x06015400);
        break;
    case 3:
        lz_decompress_dispatch(gMedaforceTrapTiles, (void *)0x06015400);
        break;
    }
    gBattleWork.step++;
}

void trap_disarm_sprite_spawn(void) {
    gSpriteEntries[0x21].flags =
        SPRITE_PRIORITY(gBattleWork.battlefieldParams[3] + 2) |
        // FAKEMATCH: the constant is a negative s16 in the original (literal pool value)
        (s16)(SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_FLAG_AFFINE | SPRITE_FLAG_PART_PALETTE);
    gSpriteEntries[0x21].frame_table = 0;
    gSpriteEntries[0x21].palette = 6;
    gSpriteEntries[0x21].scale_y = 0x40;
    gSpriteEntries[0x21].scale_x = 8;
    gSpriteEntries[0x21].order = 0xF0;
    gSpriteEntries[0x21].y = 0x3C;
    if (gBattleWork.actorSide == 0) {
        gSpriteEntries[0x21].flags |= SPRITE_FLAG_HFLIP;
        gSpriteEntries[0x21].x = 0x68;
    } else
        gSpriteEntries[0x21].x = 0x88;
    switch (gBattleWork.unk51) {
    case 0:
        gSpriteEntries[0x21].frame = 0xB00;
        break;
    case 1:
        gSpriteEntries[0x21].frame = 0xC00;
        break;
    case 2:
        gSpriteEntries[0x21].frame = 0xD00;
        break;
    case 3:
        gSpriteEntries[0x21].frame = 0xE00;
        break;
    }
    gBattleWork.step++;
}

void trap_disarm_hop_init(void) {
    gSpriteEntries[0x21].unk23 = 0;
    gGameWork.stepCounter = 0;
    play_sound_effect(0x34);
    gBattleWork.step++;
}

void trap_disarm_hop(void) {
    if (sprite_hop_step(0x21) == 0) {
        if (!(gGameWork.stepCounter & 1)) {
            if (gBattleWork.actorSide == 0)
                gSpriteEntries[0x21].x++;
            else
                gSpriteEntries[0x21].x--;
        }
        gGameWork.stepCounter++;
    } else if (gSpriteEntries[0x21].scale_x == 8) {
        clear_battle_sprite_slot(0x21, 1);
        gBattleWork.step++;
    } else {
        gSpriteEntries[0x21].scale_x -= 8;
    }
}

void trap_disarm_end(void) {
    if (gBattleWork.unk51 == 2)
        gBattleWork.step = 0x2E;
    else
        gBattleWork.step = 0x2D;
}

// Clear the side's trap record, message 0x25 "Trap was disarmed".
void trap_disarm_clear(void) {
    gBattleWork.traps[gBattleWork.actorSide].active = 0;
    gBattleWork.traps[gBattleWork.actorSide].skill = 0;
    gBattleWork.traps[gBattleWork.actorSide].durability = 0;
    gBattleWork.traps[gBattleWork.actorSide].power = 0;
    gBattleWork.messageId = 0x25;
    gBattleWork.step++;
}

void trap_hit_end_continue(void) {
    gBattleWork.stepDone = 1;
    gBattleWork.unkAB = 0;
}

void trap_hit_end_stopped(void) {
    gBattleWork.stepDone = 1;
    gBattleWork.unkAB = 1;
}

void trap_hit_end_defeated(void) {
    gBattleWork.stepDone = 1;
    gBattleWork.unkAB = 2;
}

// Script opcode 0x05: is the acting Medabot's chosen part still intact? If not, message 5 "The Medapart for that
// action is broken" and unkAB = 1.
void action_part_check_run(void) {
    gBattleWork.stepDone = 0;
    gActionPartCheckSteps[gBattleWork.step]();
}

void action_part_check(void) {
    if (gBattleBots[gBattleWork.actor].parts[gBattleBots[gBattleWork.actor].chosenAction - 1].unk11) {
        gBattleWork.stepDone = 1;
        gBattleWork.unkAB = 0;
    } else {
        gBattleWork.messageId = 5;
        gBattleWork.step++;
    }
}

void action_part_check_end_broken(void) {
    gBattleWork.stepDone = 1;
    gBattleWork.unkAB = 1;
}

// Script opcode 0x07: is the targeted part still intact? If not, message 0xC "The target Medapart is broken" and
// unkAB = 1.
void target_part_check_run(void) {
    gBattleWork.stepDone = 0;
    gTargetPartCheckSteps[gBattleWork.step]();
}

void target_part_check(void) {
    if (gBattleBots[gBattleWork.target].parts[gBattleWork.targetPart].unk11) {
        gBattleWork.stepDone = 1;
        gBattleWork.unkAB = 0;
    } else {
        gBattleWork.messageId = 0xC;
        gBattleWork.step++;
    }
}

void target_part_check_end_broken(void) {
    gBattleWork.stepDone = 1;
    gBattleWork.unkAB = 1;
}

// guess: script opcode 0x08, a small effect (animation 0x1B) that flies from the actor to the target.
void action_flash_run(void) {
    gBattleWork.stepDone = 0;
    gActionFlashSteps[gBattleWork.step]();
}

void action_flash_load_palette(void) {
    CpuFastSet(gActionFlashPalette, (void *)0x050002C0, 8);
    gBattleWork.step++;
}

void action_flash_spawn(void) {
    clear_battle_sprite_slot(9, 1);
    gSpriteEntries[9].flags = SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[9].frame_table = 0;
    gSpriteEntries[9].y = gSpriteEntries[gBattleWork.actor * 4 + 0x5D].y - 4;
    gSpriteEntries[9].x = gSpriteEntries[gBattleWork.actor * 4 + 0x5D].x;
    gSpriteEntries[9].palette = 6;
    gSpriteEntries[9].order = 0xF0;
    gSpriteEntries[9].unk30 = gSpriteEntries[gBattleWork.target * 4 + 0x5D].x;
    gSpriteEntries[9].unk32 = gSpriteEntries[gBattleWork.target * 4 + 0x5D].y - 4;
    gSpriteEntries[9].unk24 = 6;
    battle_sprite_anim_init(gBattleSpriteAnimScripts[0x1B], 9);
    gBattleWork.step++;
}

void action_flash_move(void) {
    if (move_sprite_toward_target(9))
        gBattleWork.step++;
}

void action_flash_finish(void) {
    process_sprite_anim_commands(gBattleSpriteAnimScripts[0x1B], 9);
    if (gSpriteEntries[9].unk22 == 0xFF) {
        clear_battle_sprite_slot(9, 1);
        gBattleWork.stepDone = 1;
    }
}

// Script opcode 0x09: a teammate of the target with Defence / Full Block / Half Block ready (unkBD bit 3, skill in
// unkDF 0x1B-0x1D) jumps in front of it, shows its shield, message 0x16 "<name> protected!!" and becomes the new
// target. script_op_guard_restore (opcode 0x0A) puts its sprites back.
void guard_run(void) {
    gBattleWork.stepDone = 0;
    gGuardSteps[gBattleWork.step]();
}

void guard_find(void) {
    u32 base;
    u32 i;

    if (gBattleBots[gBattleWork.actor].guardFlags & 4) {
        gBattleWork.stepDone = 1;
        return;
    }
    base = battle_side_first_record(gBattleWork.target);
    for (i = 0; i <= 2; i++) {
        if (gBattleBots[base + i].teamState == 0)
            continue;
        if (!(gBattleBots[base + i].stateFlags & 8))
            continue;
        if (gBattleWork.target == base + i)
            continue;
        if (gBattleBots[base + i].statusType == 0x2F)
            continue;
        if (gBattleBots[base + i].parts[gBattleBots[base + i].lastAction - 1].unk11 == 0)
            continue;
        gBattleWork.guardBot = base + i + 1;
        gBattleWork.guardSkill = gBattleBots[base + i].lastActionSkill;
    }
    if (gBattleWork.guardBot)
        gBattleWork.step++;
    else
        gBattleWork.stepDone = 1;
}

void guard_load_graphics(void) {
    switch (gBattleWork.guardSkill) {
    case SKILL_DEFENCE:
        lz_decompress_dispatch(gDefenceShieldTiles, (void *)0x06014800);
        CpuFastSet(gDefenceShieldPalette, (void *)0x050002C0, 8);
        break;
    case SKILL_FULL_BLOCK:
        lz_decompress_dispatch(gFullBlockShieldTiles, (void *)0x06014800);
        CpuFastSet(gFullBlockShieldPalette, (void *)0x050002C0, 8);
        break;
    case SKILL_HALF_BLOCK:
        lz_decompress_dispatch(gHalfBlockShieldTiles, (void *)0x06014800);
        CpuFastSet(gHalfBlockShieldPalette, (void *)0x050002C0, 8);
        break;
    }
    gBattleWork.step++;
}

void guard_sprite_copy(void) {
    memcpy_bytes_0803F63C(&gSpriteEntries[(gBattleWork.guardBot - 1) * 4 + 0x5A], &gSpriteEntries[0x21], 0x40);
    memcpy_bytes_0803F63C(&gSpriteEntries[(gBattleWork.guardBot - 1) * 4 + 0x5B], &gSpriteEntries[0x22], 0x40);
    memcpy_bytes_0803F63C(&gSpriteEntries[(gBattleWork.guardBot - 1) * 4 + 0x5C], &gSpriteEntries[0x23], 0x40);
    memcpy_bytes_0803F63C(&gSpriteEntries[(gBattleWork.guardBot - 1) * 4 + 0x5D], &gSpriteEntries[0x24], 0x40);
    disable_sprites(0x21, 4);
    get_bot_part_effective_values(gBattleWork.guardBot - 1, gBattleWork.unk64);
    setup_battle_sprite_group(
        gBattleWork.unk64[0], gBattleWork.unk64[1], gBattleWork.unk64[2], gBattleWork.unk64[3],
        gBattleWork.guardBot - 1, gBattleWork.guardBot * 4 + 0x56, gSpriteEntries[gBattleWork.guardBot * 4 + 0x59].x,
        gSpriteEntries[gBattleWork.guardBot * 4 + 0x59].y - 4, (gBattleWork.actorSideFlags & 1) ^ 1,
        gBattleWork.battlefieldParams[3] + 2, gBattleWork.guardBot * 4 + 0x56);
    battle_sprite_group_set_anim(gBattleWork.guardBot * 4 + 0x56, 8);
    gGameWork.stepCounter = 0;
    gBattleWork.step++;
}

void guard_blink(void) {
    update_battle_sprite_orbiting_positions((gBattleWork.guardBot - 1) * 4 + 0x5A, gBattleWork.guardBot - 1,
                                            (gBattleWork.actorSideFlags & 1) ^ 1);
    if (gGameWork.stepCounter & 4)
        disable_sprites(gBattleWork.guardBot * 4 + 0x56, 4);
    else
        enable_sprites(gBattleWork.guardBot * 4 + 0x56, 4);
    if (++gGameWork.stepCounter == 0x3C) {
        enable_sprites(gBattleWork.guardBot * 4 + 0x56, 4);
        play_sound_effect(0x40);
        gSpriteEntries[gBattleWork.guardBot * 4 + 0x59].unk24 = 4;
        gSpriteEntries[gBattleWork.guardBot * 4 + 0x59].unk25 = 0;
        gSpriteEntries[gBattleWork.guardBot * 4 + 0x59].unk30 = 0;
        sprite_enable_affine_unit_scale(gBattleWork.guardBot + 0x71);
        gBattleWork.step++;
    }
}

void guard_jump(void) {
    if (update_sprite_deceleration(gBattleWork.guardBot * 4 + 0x59, -0x20, -0x10)) {
        check_sprite_overlap_and_adjust(gBattleWork.guardBot * 4 + 0x59, gBattleWork.guardBot + 0x71);
        update_battle_sprite_orbiting_positions((gBattleWork.guardBot - 1) * 4 + 0x5A, gBattleWork.guardBot - 1,
                                                (gBattleWork.actorSideFlags & 1) ^ 1);
        gBattleWork.step++;
    } else {
        update_battle_sprite_orbiting_positions((gBattleWork.guardBot - 1) * 4 + 0x5A, gBattleWork.guardBot - 1,
                                                (gBattleWork.actorSideFlags & 1) ^ 1);
        check_sprite_overlap_and_adjust(gBattleWork.guardBot * 4 + 0x59, gBattleWork.guardBot + 0x71);
    }
}

void guard_slide_center(void) {
    u32 done = 0;

    if (!(gBattleWork.actorSideFlags & 1)) {
        gSpriteEntries[gBattleWork.guardBot * 4 + 0x59].x -= 2;
        if (gSpriteEntries[gBattleWork.guardBot * 4 + 0x59].x <= 0x78)
            done = 1;
    } else {
        gSpriteEntries[gBattleWork.guardBot * 4 + 0x59].x += 2;
        if (gSpriteEntries[gBattleWork.guardBot * 4 + 0x59].x > 0x77)
            done = 1;
    }
    update_battle_sprite_orbiting_positions((gBattleWork.guardBot - 1) * 4 + 0x5A, gBattleWork.guardBot - 1,
                                            (gBattleWork.actorSideFlags & 1) ^ 1);
    if (done) {
        gSpriteEntries[gBattleWork.guardBot * 4 + 0x59].unk24 = 8;
        gSpriteEntries[gBattleWork.guardBot * 4 + 0x59].unk25 = 0;
        gSpriteEntries[gBattleWork.guardBot * 4 + 0x59].unk30 = 0;
        gSpriteEntries[gBattleWork.guardBot * 4 + 0x59].x = 0x78;
        gSpriteEntries[gBattleWork.guardBot + 0x71].x = 0x78;
        gSpriteEntries[gBattleWork.guardBot + 0x71].y = gSpriteEntries[gBattleWork.actor + 0x72].y;
        gBattleWork.step++;
    }
}

void guard_move_in(void) {
    if (sprite_move_toward_target(gBattleWork.guardBot * 4 + 0x59, gSpriteEntries[gBattleWork.actor * 4 + 0x5D].y,
                                  gSpriteEntries[gBattleWork.actor * 4 + 0x5D].y + 0x10)) {
        check_sprite_overlap_and_adjust(gBattleWork.guardBot * 4 + 0x59, gBattleWork.guardBot + 0x71);
        update_battle_sprite_orbiting_positions((gBattleWork.guardBot - 1) * 4 + 0x5A, gBattleWork.guardBot - 1,
                                                (gBattleWork.actorSideFlags & 1) ^ 1);
        play_sound_effect(0x41);
        get_bot_part_effective_values(gBattleWork.guardBot - 1, gBattleWork.unk64);
        setup_battle_sprite_group(gBattleWork.unk64[0], gBattleWork.unk64[1], gBattleWork.unk64[2],
                                  gBattleWork.unk64[3], gBattleWork.guardBot - 1, gBattleWork.guardBot * 4 + 0x56,
                                  gSpriteEntries[gBattleWork.guardBot * 4 + 0x59].x,
                                  gSpriteEntries[gBattleWork.guardBot * 4 + 0x59].y - 4,
                                  (gBattleWork.actorSideFlags & 1) ^ 1, gBattleWork.battlefieldParams[3] + 2,
                                  gBattleWork.guardBot * 4 + 0x56);
        gSpriteEntries[gBattleWork.guardBot * 4 + 0x57].angle = 0;
        gSpriteEntries[gBattleWork.guardBot * 4 + 0x58].angle = 0;
        sprite_disable_affine(gBattleWork.guardBot + 0x71);
        gGameWork.stepCounter = 0;
        gBattleWork.step++;
    } else {
        update_battle_sprite_orbiting_positions((gBattleWork.guardBot - 1) * 4 + 0x5A, gBattleWork.guardBot - 1,
                                                (gBattleWork.actorSideFlags & 1) ^ 1);
        check_sprite_overlap_and_adjust(gBattleWork.guardBot * 4 + 0x59, gBattleWork.guardBot + 0x71);
    }
}

void guard_shield_spawn(void) {
    if (gGameWork.stepCounter != 0x1E) {
        gGameWork.stepCounter++;
        return;
    }
    clear_battle_sprite_slot(0x21, 1);
    gSpriteEntries[0x21].flags = SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_AFFINE |
                                 SPRITE_FLAG_DOUBLE_SIZE | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[0x21].frame_table = 0;
    gSpriteEntries[0x21].x = gSpriteEntries[gBattleWork.guardBot * 4 + 0x59].x;
    gSpriteEntries[0x21].y = gSpriteEntries[gBattleWork.guardBot * 4 + 0x59].y - 4;
    gSpriteEntries[0x21].palette = 6;
    gSpriteEntries[0x21].scale_x = 0x80;
    gSpriteEntries[0x21].scale_y = 0x80;
    gSpriteEntries[0x21].order = 0xF0;
    battle_sprite_anim_init(gBattleSpriteAnimScripts[0x1C], 0x21);
    gBattleWork.step++;
}

void guard_shield_shrink(void) {
    if (gSpriteEntries[0x21].scale_x == 0x40) {
        play_sound_effect(0x30);
        gBattleWork.step++;
    } else {
        gSpriteEntries[0x21].scale_x -= 4;
        gSpriteEntries[0x21].scale_y -= 4;
    }
}

void guard_shield_animate(void) {
    process_sprite_anim_commands(gBattleSpriteAnimScripts[0x1C], 0x21);
    if (gSpriteEntries[0x21].unk22 == 0xFF) {
        memcpy_bytes_0803F63C(gBattleBots[gBattleWork.guardBot - 1].medal.name, gGameWork.textBuf, 0xE);
        gBattleWork.messageId = 0x16;
        clear_battle_sprite_slot(0x21, 1);
        gBattleWork.step++;
    }
}

void guard_retarget(void) {
    battle_set_action_target(gBattleWork.actor, gBattleWork.guardBot);
    battle_set_action_target_part(gBattleWork.actor, gBattleBots[gBattleWork.guardBot - 1].lastAction);
    gBattleWork.stepDone = 1;
}

// Script opcode 0x19: message 0x17 "<part kind> action <skill>" for the acting Medabot's part.
void action_announce_run(void) {
    gBattleWork.stepDone = 0;
    gActionAnnounceSteps[gBattleWork.step]();
}

void action_announce_prepare(void) {
    memcpy_bytes_0803F63C((void *)gSkillTypeNames[gBattleBots[gBattleWork.actor].parts[gBattleWork.actorPart].data[2]],
                          gGameWork.textBuf, 0xE);
    memcpy_bytes_0803F63C((void *)gSkillNames[gBattleBots[gBattleWork.actor].parts[gBattleWork.actorPart].data[1]],
                          gGameWork.textBuf + 0x14, 0xE);
    gBattleWork.messageId = 0x17;
    gBattleWork.step++;
}

void action_announce_end(void) {
    gBattleWork.stepDone = 1;
}

// Script opcode 0x1A: wipe out the battlefield, save its VRAM and sprites to EWRAM and set up the action close-up
// scene (closeup_scene.c).
void closeup_enter_run(void) {
    gBattleWork.stepDone = 0;
    gCloseupEnterSteps[gBattleWork.step]();
}

void closeup_enter_init(void) {
    u32 zero;
    u32 fill;

    gGameWork.stepCounter = 0;
    zero = 0;
    CpuFastSet(&zero, (void *)0x05000120, 0x01000008);
    fill = 0x11111111;
    CpuFastSet(&fill, (void *)0x06004120, 0x01000008);
    gBattleWork.step++;
}

void closeup_enter_wipe(void) {
    write_tilemap_rect(0x1E, 1, 0, gGameWork.stepCounter, gUiTilemapsNamed.blank_row, REG_BG0CNT, 0);
    write_tilemap_rect(0x1E, 1, 0, 0x13 - gGameWork.stepCounter, gUiTilemapsNamed.blank_row, REG_BG0CNT, 0);
    if (gGameWork.stepCounter == 9) {
        gBattleWork.unk1AE = 1;
        gBattleWork.step++;
    } else {
        gGameWork.stepCounter++;
    }
}

void closeup_enter_save_vram(void) {
    switch (gGameWork.setupStep) {
    case 0:
        CpuFastSet((void *)0x06002800, (void *)0x02020800, 0x200);
        CpuFastSet((void *)0x0600C800, (void *)0x02021000, 0x200);
        CpuFastSet((void *)0x0600D000, (void *)0x02021800, 0x200);
        CpuFastSet((void *)0x0600D800, (void *)0x02022000, 0x200);
        gGameWork.setupStep++;
        break;
    case 1:
        CpuFastSet(gSpriteEntries, (void *)0x02028000, 0x800);
        gGameWork.setupStep++;
        break;
    case 2:
        gVBlankCallback = empty_callback;
        clear_battle_sprite_slot(0, 0x80);
        gGameWork.setupStep = 0;
        gBattleWork.step++;
        break;
    }
}

void closeup_enter_setup_bgs(void) {
    u32 zero;

    switch (gGameWork.setupStep) {
    case 0:
        clear_bg_scroll();
        REG_DISPCNT &= 0xE0FF;
        REG_BG0CNT = 0x500;
        REG_BG1CNT = 0x1801;
        REG_BG2CNT = 0x590A;
        REG_BG3CNT = 0x5B0B;
        lz_decompress_dispatch(gSpriteFontTiles, (void *)0x06017400);
        vram_fill_tilemap_rect(0x20, 0x20, 0, 0, REG_BG1CNT, 0);
        decompress_tileset_to_vram(gBattleWork.battlefield, 0);
        zero = 0;
        CpuFastSet(&zero, gSpriteEntries, 0x01000800);
        gGameWork.setupStep++;
        break;
    case 1:
        REG_DISPCNT |= 0x1F40;
        REG_DISPCNT &= 0xFFDF;
        apply_battle_blend_effect_a();
        if (gBattleBots[gBattleWork.actor].chosenAction <= 3)
            decompress_indexed_graphics_to_ewram(gBattleBots[gBattleWork.actor].parts[gBattleWork.actorPart].data[1]);
        else
            decompress_indexed_graphics_to_ewram(gBattleBots[gBattleWork.actor].medaforce[0] + 0x50);
        decompress_fixed_graphics_to_ewram();
        action_bg_set_side_scroll();
        gVBlankCallback = battle_bg_scroll_vblank;
        gGameWork.stepCounter = 0;
        gGameWork.setupStep = 0;
        gBattleWork.step++;
        break;
    }
}

void closeup_enter_init_scene(void) {
    u32 zero = 0;

    CpuFastSet(&zero, gSpriteEntries, 0x01000800);
    init_battle_closeup_scene();
    init_battle_scene_backgrounds();
    closeup_reset_text_states();
    gGameWork.stepCounter = 0;
    gBattleWork.step++;
}

void closeup_enter_unwipe(void) {
    init_battle_scene_backgrounds();
    closeup_left_pose_step();
    closeup_right_pose_step();
    vram_fill_tilemap_rect(0x1E, 1, 0, 9 - gGameWork.stepCounter, REG_BG0CNT, 0);
    vram_fill_tilemap_rect(0x1E, 1, 0, gGameWork.stepCounter + 10, REG_BG0CNT, 0);
    if (gGameWork.stepCounter == 9)
        gBattleWork.step++;
    else
        gGameWork.stepCounter++;
}

void closeup_enter_end(void) {
    init_battle_scene_backgrounds();
    closeup_left_pose_step();
    closeup_right_pose_step();
    gBattleWork.stepDone = 1;
}

// Opcode 0x1E, the hit (gAttackHitSteps). Runtime: runs after every attack, after reaction_run. Step 1 branches on
// the result flags: unkB7 bit 0 = missed (step 40), unkB8 2 = nullified (48), unkB8 4 = absorbed as healing (56).
// A hit shows the target's armor panel, sparks and the damage number, drains the armor, breaks the part (burst,
// defeat check) and carries leftover damage to the next part (Destroy repeats unkEC times).
void attack_hit_run(void) {
    gBattleWork.stepDone = 0;
    gAttackHitSteps[gBattleWork.step]();
}

void attack_hit_load_graphics(void) {
    u32 side;

    lz_decompress_dispatch(gGaugeFillTiles, (void *)0x06006400);
    lz_decompress_dispatch(gArmorPanelDecorTilesLz, (void *)0x06006520);
    lz_decompress_dispatch(gMedaforceGaugeTiles, (void *)0x06006600);
    lz_decompress_dispatch(gArmorPanelPartIconTilesLz, (void *)0x06006800);
    CpuFastSet(gArmorPanelDecorPalette, (void *)0x05000140, 8);
    CpuFastSet(gArmorPanelGaugePalette, (void *)0x05000100, 8);
    CpuFastSet(gArmorPanelPartIconPalette, (void *)0x05000160, 8);
    if (!(gBattleWork.actorSideFlags & 2))
        side = 1;
    else
        side = 0;
    armor_panel_draw_icons(side);
    armor_panel_draw_frame(side);
    armor_panel_draw_bars(side, gBattleWork.target);
    armor_panel_draw_numbers(side, gBattleWork.target);
    gBattleWork.step++;
}

void attack_hit_branch(void) {
    gBattleWork.unkB9 = 0;
    if (gBattleWork.hitResult & 1)
        gBattleWork.step = 0x28;
    else if (gBattleWork.hitResult & 3) {
        charge_target_medaforce();
        gBattleWork.step = 10;
    } else if (gBattleWork.blockResult & 2)
        gBattleWork.step = 0x30;
    else if (gBattleWork.blockResult & 4)
        gBattleWork.step = 0x38;
    else {
        side_add_action_point();
        charge_target_medaforce();
        gBattleWork.step++;
    }
}

// guess: unkBC bit 6 is set with bits 2-3 by battle_check_damage_threshold (a clean / critical hit).
void attack_hit_check_critical(void) {
    if (gBattleBots[gBattleWork.target].hitFlags & 0x40)
        gBattleWork.step++;
    else
        gBattleWork.step = 6;
}

void attack_hit_critical_spawn(void) {
    lz_decompress_dispatch(gCriticalHitTiles, (void *)0x06010000);
    CpuFastSet(gCriticalHitPalette, (void *)0x050003C0, 8);
    gSpriteEntries[10].flags =
        SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[10].frame_table = 0;
    gSpriteEntries[10].palette = 0xE;
    gSpriteEntries[10].order = 0x80;
    gSpriteEntries[10].frame = 0x1F00;
    gSpriteEntries[10].unk23 = 0;
    if (!(gBattleWork.actorSideFlags & 2)) {
        gSpriteEntries[10].x = gBattleWork.unk158;
        gSpriteEntries[10].y = gBattleWork.unk15A;
    } else {
        gSpriteEntries[10].x = gBattleWork.unk154;
        gSpriteEntries[10].y = gBattleWork.unk156;
    }
    play_sound_effect(0x72);
    gBattleWork.step++;
}

void attack_effect_hop(void) {
    if (sprite_hop_step(10)) {
        gGameWork.stepTimer = 0x3C;
        gBattleWork.step++;
    }
}

// Destroy, or a hit moved to the strongest part by evasion (unkBC bit 5): show which part is hit first.
void attack_hit_check_part_marker(void) {
    if (gBattleBots[gBattleWork.actor].parts[gBattleWork.actorPart].data[1] == SKILL_DESTROY)
        gBattleWork.step++;
    else if (gBattleBots[gBattleWork.target].hitFlags & 0x20)
        gBattleWork.step++;
    else
        gBattleWork.step = 10;
}

void attack_hit_part_marker_spawn(void) {
    if (gBattleBots[gBattleWork.actor].parts[gBattleWork.actorPart].data[1] == SKILL_DESTROY) {
        battle_set_damage_break_part(gBattleWork.target, gBattleWork.targetPart);
        lz_decompress_dispatch(gDestroyMarkerTiles, (void *)0x06010000);
        CpuFastSet(gDestroyMarkerPalette, (void *)0x050003C0, 8);
        gSpriteEntries[10].frame = 0x2100;
        play_sound_effect(0x54);
    } else {
        switch (gBattleWork.targetPart) {
        case 0:
            lz_decompress_dispatch(gHeadMarkerTiles, (void *)0x06010000);
            CpuFastSet(gHeadMarkerPalette, (void *)0x050003C0, 8);
            gSpriteEntries[10].frame = 0x1B00;
            break;
        case 1:
            lz_decompress_dispatch(gRightArmMarkerTiles, (void *)0x06010000);
            CpuFastSet(gRightArmMarkerPalette, (void *)0x050003C0, 8);
            gSpriteEntries[10].frame = 0x1C00;
            break;
        case 2:
            lz_decompress_dispatch(gLeftArmMarkerTiles, (void *)0x06010000);
            CpuFastSet(gLeftArmMarkerPalette, (void *)0x050003C0, 8);
            gSpriteEntries[10].frame = 0x1D00;
            break;
        case 3:
            lz_decompress_dispatch(gLegsMarkerTiles, (void *)0x06010000);
            CpuFastSet(gLegsMarkerPalette, (void *)0x050003C0, 8);
            gSpriteEntries[10].frame = 0x1E00;
            break;
        }
        play_sound_effect(6);
    }
    gSpriteEntries[10].flags =
        SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[10].frame_table = 0;
    gSpriteEntries[10].palette = 0xE;
    gSpriteEntries[10].order = 0x80;
    gSpriteEntries[10].unk23 = 0;
    if (!(gBattleWork.actorSideFlags & 2)) {
        if (gBattleWork.targetPart == 2)
            gSpriteEntries[10].x = gBattleWork.unk158 - 0x10;
        else
            gSpriteEntries[10].x = gBattleWork.unk158;
        gSpriteEntries[10].y = gBattleWork.unk15A;
    } else {
        if (gBattleWork.targetPart == 1)
            gSpriteEntries[10].x = gBattleWork.unk154 + 0x10;
        else
            gSpriteEntries[10].x = gBattleWork.unk154;
        gSpriteEntries[10].y = gBattleWork.unk156;
    }
    gBattleWork.step++;
}

void attack_hit_part_marker_move(void) {
    if (effect_sprite_fly_to_part(10, gBattleWork.targetPart)) {
        gGameWork.stepTimer = 0x3C;
        gBattleWork.step++;
    }
}

void attack_hit_sparks_spawn(void) {
    u16 x, y;

    lz_decompress_dispatch(gHitSparksTiles, (void *)0x06010800);
    CpuFastSet(gHitSparksPalette, (void *)0x050003C0, 8);
    if (!(gBattleWork.actorSideFlags & 2)) {
        x = gBattleWork.unk158;
        y = gBattleWork.unk15A;
    } else {
        x = gBattleWork.unk154;
        y = gBattleWork.unk156;
    }
    hit_sparks_spawn(10, gBattleWork.targetPart, x, y);
    gBattleWork.step++;
}

void attack_hit_sparks_wait(void) {
    CpuFastSet(gHitSparksPalette, (void *)0x050003C0, 8);
    if (hit_sparks_update(10)) {
        gGameWork.stepTimer = 10;
        gBattleWork.step++;
    }
}

void attack_hit_damage_popup_init(void) {
    u16 x, y;

    lz_decompress_dispatch(gDamageNumberTiles, (void *)0x06010000);
    CpuFastSet(gDamageNumberPalette, (void *)0x050003C0, 8);
    if (!(gBattleWork.actorSideFlags & 2)) {
        x = gBattleWork.unk158;
        y = gBattleWork.unk15A;
    } else {
        x = gBattleWork.unk154;
        y = gBattleWork.unk156;
    }
    set_display_digit_type(&gGameWork.partAbility, gBattleWork.appliedAmount, 1);
    damage_digits_spawn(&gGameWork.partAbility, 10, gBattleWork.targetPart, x, y);
    play_sound_effect(0x5B);
    gBattleWork.step++;
}

void attack_damage_popup_wait(void) {
    if (advance_sprite_group_anims(&gGameWork.partAbility, 10)) {
        gGameWork.stepTimer = 0x3C;
        gBattleWork.step++;
    }
}

void attack_hit_drain_sound(void) {
    play_sound_effect(0x2F);
    gBattleWork.step++;
}

void attack_hit_drain_armor(void) {
    u32 done;
    u32 side;

    done = armor_drain_step(&gBattleWork.appliedAmount, gBattleWork.target, gBattleWork.targetPart);
    if (!(gBattleWork.actorSideFlags & 2))
        side = 1;
    else
        side = 0;
    armor_panel_draw_bars(side, gBattleWork.target);
    armor_panel_draw_numbers(side, gBattleWork.target);
    if (done) {
        gGameWork.stepTimer = 0x3C;
        gBattleWork.step++;
    }
}

void attack_hit_check_part_broken(void) {
    if (gBattleWork.partBroken) {
        bot_halve_broken_leg_stats(gBattleWork.target);
        gBattleWork.step += 3;
    } else
        gBattleWork.step++;
}

void attack_hide_armor_panel(void) {
    u32 side;

    if (!(gBattleWork.actorSideFlags & 2))
        side = 1;
    else
        side = 0;
    armor_panel_clear(side);
    gBattleWork.step++;
}

void attack_hit_end(void) {
    gBattleWork.stepDone = 1;
}

void attack_hit_break_burst_init(void) {
    u16 x, y;

    lz_decompress_dispatch(gPartBreakBurstTiles, (void *)0x06010800);
    CpuFastSet(gPartBreakBurstPalette, (void *)0x050003C0, 8);
    if (!(gBattleWork.actorSideFlags & 2)) {
        x = gBattleWork.unk158;
        y = gBattleWork.unk15A;
    } else {
        x = gBattleWork.unk154;
        y = gBattleWork.unk156;
    }
    gGameWork.stepTimer = 0;
    effect_sprite_spawn_at_part(10, gBattleWork.targetPart, x, y, 0x1E);
    gBattleWork.step++;
}

void attack_hit_break_burst_wait(void) {
    process_sprite_anim_commands(gBattleSpriteAnimScripts[0x1E], 10);
    if (gSpriteEntries[10].unk22 == 0xFF) {
        clear_battle_sprite_slot(10, 1);
        gBattleWork.step++;
    }
    if (gGameWork.stepTimer == 0x12)
        setup_battle_medapart_scenes();
    gGameWork.stepTimer++;
}

void attack_hit_break_pause(void) {
    gGameWork.stepTimer = 0x3C;
    gBattleWork.step++;
}

// Hidden function (no callers): attack_hit_break_pause plus the broken-part redraw.
void attack_hit_break_redraw(void) {
    setup_battle_medapart_scenes();
    gGameWork.stepTimer = 0x3C;
    gBattleWork.step++;
}

void attack_hit_check_defeated(void) {
    if (gBattleBots[gBattleWork.target].parts[0].unk11)
        gBattleWork.step += 3;
    else {
        add_bot_to_defeated_list(gBattleWork.target);
        gBattleWork.step++;
    }
}

// Leftover damage (unkCA) goes on to another part with actor unkD6 bit 1 or a piercing part (data[7]).
void attack_hit_check_carry_over(void) {
    if (gBattleBots[gBattleWork.actor].parts[gBattleWork.actorPart].data[1] == SKILL_DESTROY) {
        if (--gBattleWork.amount != 0) {
            gBattleWork.step = 0x20;
            return;
        }
    } else if ((gBattleBots[gBattleWork.actor].unkD6 & 2 ||
                gBattleBots[gBattleWork.actor].parts[gBattleWork.actorPart].data[7]) &&
               gBattleWork.overflowAmount != 0) {
        gBattleWork.step = 0x20;
        return;
    }
    gBattleWork.step++;
}

void attack_hit_carry_over_retarget(void) {
    battle_pick_random_target_part(gBattleWork.actor);
    battle_load_action_target(gBattleWork.actor);
    gBattleWork.damagePart = gBattleWork.targetPart;
    if (gBattleBots[gBattleWork.actor].parts[gBattleWork.actorPart].data[1] == SKILL_DESTROY)
        battle_set_damage_break_part(gBattleWork.target, gBattleWork.targetPart);
    else {
        if (gBattleBots[gBattleWork.actor].unkD6 & 2)
            gBattleWork.overflowAmount += 10;
        battle_set_damage_vs_armor(gBattleWork.target, gBattleWork.targetPart, gBattleWork.overflowAmount);
    }
    gBattleWork.step++;
}

void attack_carry_marker_spawn(void) {
    if (gBattleBots[gBattleWork.actor].parts[gBattleWork.actorPart].data[1] == SKILL_DESTROY) {
        lz_decompress_dispatch(gDestroyMarkerTiles, (void *)0x06010000);
        CpuFastSet(gDestroyMarkerPalette, (void *)0x050003C0, 8);
        gSpriteEntries[10].frame = 0x2100;
        play_sound_effect(0x54);
    } else {
        lz_decompress_dispatch(gCarryOverMarkerTiles, (void *)0x06010000);
        CpuFastSet(gCarryOverMarkerPalette, (void *)0x050003C0, 8);
        gSpriteEntries[10].frame = 0x1500;
        play_sound_effect(0x2A);
    }
    gSpriteEntries[10].flags =
        SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[10].frame_table = 0;
    gSpriteEntries[10].palette = 0xE;
    gSpriteEntries[10].order = 0x80;
    gSpriteEntries[10].unk23 = 0;
    if (!(gBattleWork.actorSideFlags & 2)) {
        if (gBattleWork.targetPart == 2)
            gSpriteEntries[10].x = gBattleWork.unk158 - 0x10;
        else
            gSpriteEntries[10].x = gBattleWork.unk158;
        gSpriteEntries[10].y = gBattleWork.unk15A;
    } else {
        if (gBattleWork.targetPart == 1)
            gSpriteEntries[10].x = gBattleWork.unk154 + 0x10;
        else
            gSpriteEntries[10].x = gBattleWork.unk154;
        gSpriteEntries[10].y = gBattleWork.unk156;
    }
    gBattleWork.step++;
}

void attack_hit_goto_sparks(void) {
    gBattleWork.step = 10;
}

// The miss branch (unkB7 bit 0: the target dodged, unkBC bit 4).
void attack_miss_sprite_spawn(void) {
    lz_decompress_dispatch(gAttackMissTiles, (void *)0x06010000);
    CpuFastSet(gAttackMissPalette, (void *)0x050003C0, 8);
    gSpriteEntries[10].flags =
        SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[10].frame_table = 0;
    gSpriteEntries[10].palette = 0xE;
    gSpriteEntries[10].order = 0x80;
    gSpriteEntries[10].frame = 0x1400;
    gSpriteEntries[10].unk23 = 0;
    if (!(gBattleWork.actorSideFlags & 2)) {
        gSpriteEntries[10].x = gBattleWork.unk158;
        gSpriteEntries[10].y = gBattleWork.unk15A - 0x10;
        gSpriteEntries[10].unk30 = gBattleWork.unk15A;
    } else {
        gSpriteEntries[10].x = gBattleWork.unk154;
        gSpriteEntries[10].y = gBattleWork.unk156 - 0x10;
        gSpriteEntries[10].unk30 = gBattleWork.unk156;
    }
    play_sound_effect(0x2F);
    gBattleWork.step++;
}

void attack_miss_sprite_drop(void) {
    if (gFrameCounter & 1) {
        gSpriteEntries[10].y++;
        if (gSpriteEntries[10].y == gSpriteEntries[10].unk30) {
            gGameWork.stepTimer = 0x3C;
            gBattleWork.step++;
        }
    }
}

// The nullified branch (unkB8 == 2: Full / Half Block and the immunity checks of action_calc.c).
void attack_nullified_sprite_spawn(void) {
    lz_decompress_dispatch(gAttackNullifiedTiles, (void *)0x06010000);
    CpuFastSet(gAttackNullifiedPalette, (void *)0x050003C0, 8);
    gSpriteEntries[10].flags =
        SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[10].frame_table = 0;
    gSpriteEntries[10].palette = 0xE;
    gSpriteEntries[10].order = 0x80;
    gSpriteEntries[10].frame = 0x2000;
    gSpriteEntries[10].unk23 = 0;
    if (!(gBattleWork.actorSideFlags & 2)) {
        gSpriteEntries[10].x = gBattleWork.unk158;
        gSpriteEntries[10].y = gBattleWork.unk15A;
    } else {
        gSpriteEntries[10].x = gBattleWork.unk154;
        gSpriteEntries[10].y = gBattleWork.unk156;
    }
    play_sound_effect(0x2A);
    gBattleWork.step++;
}

// The absorbed branch (unkB8 == 4): the damage heals the target's most damaged parts instead.
void attack_absorbed_sprite_spawn(void) {
    lz_decompress_dispatch(gAttackAbsorbedTiles, (void *)0x06010000);
    CpuFastSet(gAttackAbsorbedPalette, (void *)0x050003C0, 8);
    gSpriteEntries[10].flags =
        SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[10].frame_table = 0;
    gSpriteEntries[10].palette = 0xE;
    gSpriteEntries[10].order = 0x80;
    gSpriteEntries[10].frame = 0x2E00;
    gSpriteEntries[10].unk23 = 0;
    if (!(gBattleWork.actorSideFlags & 2)) {
        gSpriteEntries[10].x = gBattleWork.unk158;
        gSpriteEntries[10].y = gBattleWork.unk15A;
    } else {
        gSpriteEntries[10].x = gBattleWork.unk154;
        gSpriteEntries[10].y = gBattleWork.unk156;
    }
    play_sound_effect(0x2A);
    gBattleWork.step++;
}

void attack_absorbed_find_part(void) {
    u32 part = find_most_damaged_part(gBattleWork.target);

    if (part) {
        gBattleWork.targetPart = gBattleWork.damagePart = part - 1;
        battle_calc_damage_split(gBattleWork.target, gBattleWork.damagePart, gBattleWork.amount);
        gBattleWork.step = 0x3E;
    } else
        gBattleWork.step++;
}

void attack_absorbed_sparkle_init(void) {
    u16 x, y;

    lz_decompress_dispatch(gAbsorbSparkleTiles, (void *)0x06010800);
    CpuFastSet(gAbsorbSparklePalette, (void *)0x050003C0, 8);
    if (!(gBattleWork.actorSideFlags & 2)) {
        x = gBattleWork.unk158;
        y = gBattleWork.unk15A;
    } else {
        x = gBattleWork.unk154;
        y = gBattleWork.unk156;
    }
    effect_sprite_spawn_at_part(10, gBattleWork.targetPart, x, y, 0x20);
    gBattleWork.step++;
}

void attack_absorbed_sparkle_wait(void) {
    process_sprite_anim_commands(gBattleSpriteAnimScripts[0x20], 10);
    if (gSpriteEntries[10].unk22 == 0xFF) {
        clear_battle_sprite_slot(10, 1);
        gGameWork.stepTimer = 0x3C;
        gBattleWork.step++;
    }
}

void attack_absorbed_heal_popup_init(void) {
    u16 x, y;

    lz_decompress_dispatch(gDamageNumberTiles, (void *)0x06010000);
    CpuFastSet(gHealNumberPalette, (void *)0x050003C0, 8);
    if (!(gBattleWork.actorSideFlags & 2)) {
        x = gBattleWork.unk158;
        y = gBattleWork.unk15A;
    } else {
        x = gBattleWork.unk154;
        y = gBattleWork.unk156;
    }
    set_display_digit_type(&gGameWork.partAbility, gBattleWork.appliedAmount, 0);
    damage_digits_spawn(&gGameWork.partAbility, 10, gBattleWork.targetPart, x, y);
    play_sound_effect(0x5B);
    gBattleWork.step++;
}

void attack_absorbed_heal_sound(void) {
    play_sound_effect(0x2E);
    gBattleWork.step++;
}

void attack_absorbed_heal_armor(void) {
    u32 done;
    u32 side;

    done = armor_heal_step(&gBattleWork.appliedAmount, gBattleWork.target, gBattleWork.targetPart);
    if (!(gBattleWork.actorSideFlags & 2))
        side = 1;
    else
        side = 0;
    armor_panel_draw_bars(side, gBattleWork.target);
    armor_panel_draw_numbers(side, gBattleWork.target);
    if (done) {
        gGameWork.stepTimer = 0x3C;
        gBattleWork.step++;
    }
}

void attack_absorbed_check_carry_over(void) {
    u32 part;
    struct BattleWork *s;

    if ((gBattleBots[(s = &gBattleWork)->actor].unkD6 & 2 || gBattleBots[s->actor].parts[s->actorPart].data[7]) &&
        s->overflowAmount && (part = find_most_damaged_part(s->target))) {
        part--;
        s->damagePart = part;
        s->targetPart = part;
        battle_calc_damage_split(s->target, s->damagePart, s->overflowAmount);
        s->step = 0x4A;
    } else {
        s->step++;
    }
}

void attack_absorbed_goto_sparkle(void) {
    gBattleWork.step = 0x3E;
}

// Opcode 0x1F (gStatusAttackSteps): after a hit, skills 0xD-0x14 inflict their status unless the target missed /
// nullified / absorbed, is defeated, has Stability or a status guard. unk51 = kind: 0 Bug / Virus, 1 Thunder /
// Freeze, 2 Wave / Hold, 3 Fire / Melt (skill names from the ROM list).
void status_attack_run(void) {
    gBattleWork.stepDone = 0;
    gStatusAttackSteps[gBattleWork.step]();
}

void status_attack_check(void) {
    struct BattleWork *s = &gBattleWork;
    u8 skill;

    if (s->hitResult & 1)
        s->step++;
    else if (s->blockResult & 2)
        s->step++;
    else if (s->blockResult & 4)
        s->step++;
    else if (!gBattleBots[s->target].parts[0].unk11)
        s->step++;
    else if (!battle_bot_lacks_stability(s->target))
        s->step++;
    else if (bot_has_status_guard(s->target, gBattleBots[s->actor].parts[s->actorPart].data[1]))
        s->step++;
    else {
        skill = gBattleBots[s->actor].parts[s->actorPart].data[1];
        if (skill == 0xD)
            goto s0;
        if (skill != 0xE)
            goto c1;
    s0:
        s->unk51 = 0;
        s->step = 2;
        return;
    c1:
        if (skill == 0xF)
            goto s1;
        if (skill != 0x10)
            goto c2;
    s1:
        s->unk51 = 1;
        s->step = 2;
        return;
    c2:
        if (skill == 0x11)
            goto s2;
        if (skill != 0x12)
            goto c3;
    s2:
        s->unk51 = 2;
        s->step = 2;
        return;
    c3:
        if (skill == 0x13)
            goto s3;
        if (skill != 0x14)
            goto nx;
    s3:
        s->unk51 = 3;
        s->step = 2;
        return;
    nx:
        s->step++;
    }
}

void status_attack_end(void) {
    gBattleWork.stepDone = 1;
}

void status_attack_flash_spawn(void) {
    u16 x, y;

    lz_decompress_dispatch(gStatusFlashTiles, (void *)0x06010000);
    CpuFastSet(gStatusFlashPalette, (void *)0x050003C0, 8);
    if (!(gBattleWork.actorSideFlags & 2)) {
        x = gBattleWork.unk158;
        y = gBattleWork.unk15A;
    } else {
        x = gBattleWork.unk154;
        y = gBattleWork.unk156;
    }
    gSpriteEntries[10].flags = SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_AFFINE |
                               SPRITE_FLAG_DOUBLE_SIZE | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[10].frame_table = 0;
    gSpriteEntries[10].x = x;
    gSpriteEntries[10].y = y;
    gSpriteEntries[10].scale_x = 0x40;
    gSpriteEntries[10].scale_y = 4;
    gSpriteEntries[10].palette = 0xE;
    gSpriteEntries[10].order = 0xF0;
    gSpriteEntries[10].frame = 0x1600;
    gSpriteEntries[10].unk20 = 0;
    switch (gBattleWork.unk51) {
    case 0:
        lz_decompress_dispatch(gBugEffectTiles, (void *)0x06010800);
        CpuFastSet(gBugEffectPalette, (void *)0x050003A0, 8);
        break;
    case 1:
        lz_decompress_dispatch(gThunderEffectTiles, (void *)0x06010800);
        CpuFastSet(gThunderEffectPalette, (void *)0x050003A0, 8);
        break;
    case 2:
        lz_decompress_dispatch(gWaveEffectTiles, (void *)0x06010800);
        CpuFastSet(gWaveEffectPalette, (void *)0x050003A0, 8);
        break;
    case 3:
        lz_decompress_dispatch(gFireEffectTiles, (void *)0x06010800);
        CpuFastSet(gFireEffectPalette, (void *)0x050003A0, 8);
        break;
    }
    gSpriteEntries[11].flags =
        SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[11].frame_table = 0;
    gSpriteEntries[11].x = x;
    gSpriteEntries[11].y = y;
    gSpriteEntries[11].palette = 0xD;
    gSpriteEntries[11].order = 0x80;
    battle_sprite_anim_init(gBattleSpriteAnimScripts[0x21], 11);
    play_sound_effect(0x2F);
    gBattleWork.step++;
}

void status_attack_flash_animate(void) {
    if (gSpriteEntries[10].unk20 == 0) {
        if ((gSpriteEntries[10].scale_y += 4) == 0x80)
            gSpriteEntries[10].unk20 = 1;
    } else if (gSpriteEntries[10].scale_y != 0x40)
        gSpriteEntries[10].scale_y -= 4;
    process_sprite_anim_commands(gBattleSpriteAnimScripts[0x21], 11);
    if (gSpriteEntries[11].unk22 == 0xFF) {
        clear_battle_sprite_slot(10, 2);
        gBattleWork.step++;
    }
}

void status_attack_icons_spawn(void) {
    u16 x, y;
    s16 sx, sy;

    if (!(gBattleWork.actorSideFlags & 2)) {
        x = gBattleWork.unk158 - 4;
        y = gBattleWork.unk15A;
    } else {
        x = gBattleWork.unk154 + 4;
        y = gBattleWork.unk156;
    }
    switch (gBattleWork.unk51) {
    case 0:
        lz_decompress_dispatch(gBugIconTiles, (void *)0x06010000);
        CpuFastSet(gBugIconPalette, (void *)0x050003C0, 8);
        break;
    case 1:
        lz_decompress_dispatch(gThunderIconTiles, (void *)0x06010000);
        CpuFastSet(gThunderIconPalette, (void *)0x050003C0, 8);
        break;
    case 2:
        lz_decompress_dispatch(gWaveIconTiles, (void *)0x06010000);
        CpuFastSet(gWaveIconPalette, (void *)0x050003C0, 8);
        break;
    case 3:
        lz_decompress_dispatch(gFireIconTiles, (void *)0x06010000);
        CpuFastSet(gFireIconPalette, (void *)0x050003C0, 8);
        break;
    }
    sx = x;
    sy = y;
    gSpriteEntries[10].flags =
        SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[10].frame_table = 0;
    gSpriteEntries[10].x = sx - 0x10;
    gSpriteEntries[10].y = sy - 8;
    gSpriteEntries[10].palette = 0xE;
    gSpriteEntries[10].order = 0x80;
    gSpriteEntries[10].frame = 0x1700;
    gSpriteEntries[11].flags =
        SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[11].frame_table = 0;
    gSpriteEntries[11].x = sx + 0x10;
    gSpriteEntries[11].y = sy + 8;
    gSpriteEntries[11].palette = 0xE;
    gSpriteEntries[11].order = 0x80;
    gSpriteEntries[11].frame = 0x1701;
    gBattleWork.step++;
}

void status_attack_icons_slide(void) {
    sprite_slide_x_step(10, 0);
    if (sprite_slide_x_step(11, 1)) {
        play_sound_effect(0x2A);
        gGameWork.stepTimer = 0x5A;
        gBattleWork.step++;
    }
}

void status_attack_apply(void) {
    battle_inflict_status(gBattleWork.target, gBattleBots[gBattleWork.actor].parts[gBattleWork.actorPart].data[1],
                          gBattleWork.success, gBattleWork.amount);
    gBattleWork.step++;
}

// Opcode 0x20 (gCloseupExitSteps), seen at runtime after each attack: wipe the close-up away and restore the battle
// field graphics that closeup_enter_save_vram put in EWRAM.
void closeup_exit_run(void) {
    gBattleWork.stepDone = 0;
    gCloseupExitSteps[gBattleWork.step]();
}

void closeup_exit_init(void) {
    u32 zero;
    u32 fill;

    init_battle_scene_backgrounds();
    gBattleWork.unk15F = closeup_left_pose_step();
    gBattleWork.unk160 = closeup_right_pose_step();
    gGameWork.stepCounter = 0;
    zero = 0;
    CpuFastSet(&zero, (void *)0x05000120, 0x01000008);
    fill = 0x11111111;
    CpuFastSet(&fill, (void *)0x06004120, 0x01000008);
    gBattleWork.step++;
}

void closeup_exit_wipe(void) {
    u32 v;

    init_battle_scene_backgrounds();
    gBattleWork.unk15F = closeup_left_pose_step();
    gBattleWork.unk160 = closeup_right_pose_step();
    write_tilemap_rect(0x1E, 1, 0, gGameWork.stepCounter, gUiTilemapsNamed.blank_row, REG_BG0CNT, 0);
    write_tilemap_rect(0x1E, 1, 0, 0x13 - gGameWork.stepCounter, gUiTilemapsNamed.blank_row, REG_BG0CNT, 0);
    if (gGameWork.stepCounter == 9) {
        v = 0x200;
        CpuFastSet(&v, gSpriteWork->oamBuf, 0x01000100);
        gSpriteWork->oamCount = 0;
        gSpriteWork->affineIdx = 0;
        gVBlankCallback = empty_callback;
        gBattleWork.step++;
    } else {
        gGameWork.stepCounter++;
    }
}

void closeup_exit_reload(void) {
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
        if (battle_load_graphics_step(1)) {
            gGameWork.stepCounter = 0;
            gGameWork.setupStep++;
        }
        break;
    case 1:
        REG_DISPCNT |= 0x1F40;
        load_all_bot_part_sprites();
        iterate_bots_setup_battle_sprites();
        apply_battle_blend_effect_b();
        decompress_to_ewram_27000(gBattlefieldGraphics[gBattleWork.battlefield * 5 + 1]);
        gGameWork.setupStep++;
        break;
    case 2:
        CpuFastSet((void *)0x02021000, (void *)0x0600C800, 0x200);
        CpuFastSet((void *)0x02021800, (void *)0x0600D000, 0x200);
        CpuFastSet((void *)0x02022000, (void *)0x0600D800, 0x200);
        gGameWork.setupStep++;
        break;
    case 3:
        CpuFastSet((void *)0x02028000, gSpriteEntries, 0x800);
        gGameWork.setupStep++;
        break;
    case 4:
        load_all_bot_part_sprites();
        iterate_bots_setup_battle_sprites();
        gVBlankCallback = battle_vblank_update_bg;
        gGameWork.stepCounter = 0;
        gBattleWork.unk1AE = 0;
        gBattleWork.step++;
        gGameWork.setupStep = 0;
        break;
    }
}

void closeup_exit_unwipe(void) {
    vram_fill_tilemap_rect(0x1E, 1, 0, 9 - gGameWork.stepCounter, REG_BG0CNT, 0);
    vram_fill_tilemap_rect(0x1E, 1, 0, gGameWork.stepCounter + 10, REG_BG0CNT, 0);
    if (gGameWork.stepCounter == 9)
        gBattleWork.step++;
    else
        gGameWork.stepCounter++;
}

// Opcode 0x21 (gBotDefeatSteps): for each Medabot waiting in unkE0 (add_bot_to_defeated_list), a ring and a burst
// over it, remove its sprites and show message 0x14 "<Medal>'s function ceased".
void bot_defeat_run(void) {
    gBattleWork.stepDone = 0;
    gBotDefeatSteps[gBattleWork.step]();
}

void bot_defeat_find(void) {
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gBattleWork.unkE0[i]) {
            gBattleWork.unk51 = gBattleWork.unkE0[i] - 1;
            gBattleWork.unkE0[i] = 0;
            load_all_bot_part_sprites();
            iterate_bots_setup_battle_sprites();
            reset_battle_bot_state(gBattleWork.unk51);
            gBattleWork.step = 2;
            return;
        }
    }
    gBattleWork.step++;
}

void bot_defeat_ring_init(void) {
    lz_decompress_dispatch(gBreakRingTiles, (void *)0x06014800);
    CpuFastSet(gBreakRingPalette, (void *)0x050002E0, 8);
    staggered_sprites_spawn(0x21, gSpriteEntries[gBattleWork.unk51 * 4 + 0x5D].x,
                            gSpriteEntries[gBattleWork.unk51 * 4 + 0x5D].y - 4, 8);
    gBattleWork.step++;
}

void bot_defeat_ring_wait(void) {
    if (staggered_sprites_update(0x21, 8))
        gBattleWork.step++;
}

void bot_defeat_burst_init(void) {
    lz_decompress_dispatch(gHitSparksTiles, (void *)0x06014800);
    CpuFastSet(gHitSparksPalette, (void *)0x050002E0, 8);
    gSpriteEntries[0x21].flags = SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[0x21].frame_table = 0;
    gSpriteEntries[0x21].x = gSpriteEntries[gBattleWork.unk51 * 4 + 0x5D].x;
    gSpriteEntries[0x21].y = gSpriteEntries[gBattleWork.unk51 * 4 + 0x5D].y - 4;
    gSpriteEntries[0x21].palette = 7;
    gSpriteEntries[0x21].order = 0xF0;
    battle_sprite_anim_init(gBattleSpriteAnimScripts[0x22], 0x21);
    gBattleWork.step++;
}

void bot_defeat_burst_wait(void) {
    process_sprite_anim_commands(gBattleSpriteAnimScripts[0x22], 0x21);
    if (gSpriteEntries[0x21].unk22 == 0xFF) {
        clear_battle_sprite_slot(0x21, 1);
        disable_sprites(0x5A + gBattleWork.unk51 * 4, 4);
        disable_sprites(gBattleWork.unk51 + 0x72, 1);
        gBattleWork.step++;
    }
}

void bot_defeat_message(void) {
    memcpy_bytes_0803F63C(gBattleBots[gBattleWork.unk51].medal.name, gGameWork.textBuf, 0xE);
    gBattleWork.messageId = 0x14;
    gBattleWork.step++;
}

void bot_defeat_next(void) {
    gBattleWork.step = 0;
}

// Opcode 0x22 (gReactionSteps). guess: the target's prepared reaction (unkF6 bit 0, set by battle_check_guard_or_cover
// for a guard or a readied part): a sprite rises; with unkB7 == 3 it turns into a counter (reaction_counter_begin swaps
// the sides), else it drops back with a nullify or absorb effect. Runtime: runs first in each attack, skipped there.
void reaction_run(void) {
    gBattleWork.stepDone = 0;
    gReactionSteps[gBattleWork.step]();
}

void reaction_check(void) {
    if (gBattleWork.unkF6 & 1) {
        gBattleWork.step = 2;
    } else {
        gBattleWork.unkAB = 0;
        gBattleWork.step++;
    }
}

void reaction_rise_spawn(void) {
    u16 x, y;

    lz_decompress_dispatch(gReactionRiseTiles, (void *)0x06010000);
    CpuFastSet(gReactionRisePalette, (void *)0x050003C0, 8);
    lz_decompress_dispatch(gReactionRiseFxTiles, (void *)0x06010800);
    CpuFastSet(gReactionRiseFxPalette, (void *)0x050003A0, 8);
    if (!(gBattleWork.actorSideFlags & 2)) {
        x = gBattleWork.unk158;
        y = gBattleWork.unk15A;
    } else {
        x = gBattleWork.unk154;
        y = gBattleWork.unk156;
    }
    gSpriteEntries[10].flags =
        SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[10].frame_table = 0;
    gSpriteEntries[10].x = x;
    gSpriteEntries[10].y = y;
    gSpriteEntries[10].palette = 0xE;
    gSpriteEntries[10].order = 0x80;
    gSpriteEntries[10].frame = 0x1300;
    gSpriteEntries[10].unk2B = 0;
    gSpriteEntries[10].unk2C = 0;
    gSpriteEntries[11].flags =
        SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[11].frame_table = 0;
    gSpriteEntries[11].x = x;
    gSpriteEntries[11].y = y;
    gSpriteEntries[11].palette = 0xD;
    gSpriteEntries[11].order = 0x80;
    gSpriteEntries[11].frame = 0x2C00;
    battle_sprite_anim_init(gBattleSpriteAnimScripts[0x37], 11);
    play_sound_effect(0x53);
    gBattleWork.step++;
}

void reaction_rise(void) {
    process_sprite_anim_commands(gBattleSpriteAnimScripts[0x37], 11);
    if (gSpriteEntries[10].unk2B == 0x28) {
        clear_battle_sprite_slot(11, 1);
        gBattleWork.step++;
    } else {
        gSpriteEntries[10].unk2C++;
        if (gSpriteEntries[10].unk2C & 1) {
            gSpriteEntries[10].y--;
            gSpriteEntries[10].unk2B++;
        }
    }
}

void reaction_check_counter(void) {
    if (gBattleWork.hitResult == 3) {
        reaction_counter_begin();
        clear_battle_sprite_slot(10, 1);
        gBattleWork.unkAB = 1;
        gBattleWork.step++;
    } else {
        gBattleWork.step = 6;
    }
}

void reaction_drop_init(void) {
    lz_decompress_dispatch(gAttackMissTiles, (void *)0x06010000);
    CpuFastSet(gAttackMissPalette, (void *)0x050003C0, 8);
    gSpriteEntries[10].unk2B = 0;
    gSpriteEntries[10].unk2C = 0;
    play_sound_effect(0x2F);
    gBattleWork.step++;
}

void reaction_drop(void) {
    if (gSpriteEntries[10].unk2B == 0x28) {
        gGameWork.stepTimer = 0x3C;
        gBattleWork.unkAB = 0;
        gBattleWork.step++;
    } else {
        gSpriteEntries[10].unk2C++;
        gSpriteEntries[10].y++;
        gSpriteEntries[10].unk2B++;
    }
}

void reaction_branch(void) {
    if (gBattleWork.blockResult == 2)
        gBattleWork.step = 0xB;
    else if (gBattleWork.blockResult == 4)
        gBattleWork.step = 0xF;
    else
        gBattleWork.step++;
}

void reaction_nullify_init(void) {
    u16 x, y;

    lz_decompress_dispatch(gReactionNullifyTiles, (void *)0x06010800);
    CpuFastSet(gReactionNullifyPalette, (void *)0x050003C0, 8);
    if (!(gBattleWork.actorSideFlags & 2)) {
        x = gBattleWork.unk158;
        y = gBattleWork.unk15A;
    } else {
        x = gBattleWork.unk154;
        y = gBattleWork.unk156;
    }
    gSpriteEntries[10].flags =
        SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[10].frame_table = 0;
    gSpriteEntries[10].x = x;
    gSpriteEntries[10].y = y;
    gSpriteEntries[10].palette = 0xE;
    gSpriteEntries[10].order = 0x80;
    battle_sprite_anim_init(gBattleSpriteAnimScripts[0x25], 10);
    play_sound_effect(0x37);
    gBattleWork.step++;
}

void reaction_nullify_wait(void) {
    process_sprite_anim_commands(gBattleSpriteAnimScripts[0x25], 10);
    if (gSpriteEntries[10].unk22 == 0xFF) {
        gGameWork.stepTimer = 0x3C;
        clear_battle_sprite_slot(10, 1);
        gBattleWork.step++;
    }
}

void reaction_absorb_init(void) {
    u16 x, y;

    lz_decompress_dispatch(gReactionAbsorbTiles, (void *)0x06010800);
    CpuFastSet(gReactionAbsorbPalette, (void *)0x050003C0, 8);
    if (!(gBattleWork.actorSideFlags & 2)) {
        x = gBattleWork.unk158;
        y = gBattleWork.unk15A;
    } else {
        x = gBattleWork.unk154;
        y = gBattleWork.unk156;
    }
    gSpriteEntries[10].flags =
        SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[10].frame_table = 0;
    gSpriteEntries[10].x = x;
    gSpriteEntries[10].y = y;
    gSpriteEntries[10].palette = 0xE;
    gSpriteEntries[10].order = 0x80;
    battle_sprite_anim_init(gBattleSpriteAnimScripts[0x26], 10);
    play_sound_effect(0x2B);
    gBattleWork.step++;
}

void reaction_absorb_wait(void) {
    process_sprite_anim_commands(gBattleSpriteAnimScripts[0x26], 10);
    if (gSpriteEntries[10].unk22 == 0xFF) {
        gGameWork.stepTimer = 0x3C;
        clear_battle_sprite_slot(10, 1);
        gBattleWork.step++;
    }
}

// Opcode 0x23 (gSacrificeSteps): the attacker's own part breaks (message 0x18 "...due to the Sacrifice technique").
void sacrifice_run(void) {
    gBattleWork.stepDone = 0;
    gSacrificeSteps[gBattleWork.step]();
}

void sacrifice_ring_init(void) {
    lz_decompress_dispatch(gBreakRingTiles, (void *)0x06014800);
    CpuFastSet(gBreakRingPalette, (void *)0x050002E0, 8);
    staggered_sprites_spawn(0x21, gSpriteEntries[0x5A + gBattleWork.actor * 4 + gBattleWork.actorPart].x,
                            gSpriteEntries[0x5A + gBattleWork.actor * 4 + gBattleWork.actorPart].y, 4);
    gBattleWork.step++;
}

void sacrifice_ring_wait(void) {
    if (staggered_sprites_update(0x21, 4))
        gBattleWork.step++;
}

void sacrifice_burst_init(void) {
    lz_decompress_dispatch(gHitSparksTiles, (void *)0x06014800);
    CpuFastSet(gHitSparksPalette, (void *)0x050002E0, 8);
    gSpriteEntries[0x21].flags = SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[0x21].frame_table = 0;
    gSpriteEntries[0x21].x = gSpriteEntries[0x5A + gBattleWork.actor * 4 + gBattleWork.actorPart].x;
    gSpriteEntries[0x21].y = gSpriteEntries[0x5A + gBattleWork.actor * 4 + gBattleWork.actorPart].y;
    gSpriteEntries[0x21].palette = 7;
    gSpriteEntries[0x21].order = 0xF0;
    battle_sprite_anim_init(gBattleSpriteAnimScripts[0x22], 0x21);
    gBattleWork.step++;
}

void sacrifice_burst_wait(void) {
    process_sprite_anim_commands(gBattleSpriteAnimScripts[0x22], 0x21);
    if (gSpriteEntries[0x21].unk22 == 0xFF) {
        clear_battle_sprite_slot(0x21, 1);
        gBattleWork.step++;
    }
}

void sacrifice_break_part(void) {
    reduce_bot_part_stat(gBattleWork.actor, gBattleWork.actorPart, 0xFF);
    load_all_bot_part_sprites();
    iterate_bots_setup_battle_sprites();
    if (gBattleWork.actorPart == 0)
        add_bot_to_defeated_list(gBattleWork.actor);
    gBattleWork.step++;
}

void sacrifice_message(void) {
    memcpy_bytes_0803F63C(gPartKindNames[gBattleWork.actorPart], gGameWork.textBuf, 0xE);
    gBattleWork.messageId = 0x18;
    gBattleWork.step++;
}

// Opcode 0x24 (gDestroyCheckSteps): Destroy fails with message 0x19 "Destroy only works against Medabots facing away"
// and the MISS!! popup unless the target has unkBD bit 2.
void destroy_check_run(void) {
    gBattleWork.stepDone = 0;
    gDestroyCheckSteps[gBattleWork.step]();
}

void destroy_check(void) {
    if (gBattleBots[gBattleWork.target].stateFlags & 4) {
        gBattleWork.step++;
        gBattleWork.unkAB = 0;
    } else {
        gBattleWork.messageId = 0x19;
        gBattleWork.step = 2;
        gBattleWork.unkAB = 1;
    }
}
