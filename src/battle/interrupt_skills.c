// Effect sequences of the Interrupt abilities (and two Defend ones): action script opcodes 0x36-0x3F.
// Each runner (*_run: clears stepDone and calls entry [step] of its step table) is one action script command
// (gActionScriptCommands, opcode order = ROM order); its step handlers follow it and the last step sets messageId.
// Abilities are part data[1], and the script of ability n is gActionScripts[n]:
//   0x36 Impair (43), 0x37 Confusion (44), 0x38 Use Drain (45), 0x39 No Escape (46) / No Defense (47),
//   0x3A Forcedrain (50), 0x3B / 0x3C TeamAttack (52: a Shoot script with the Team Form check and the turret
//   animation inserted), 0x3D clears the queued action (script_op_clear_queued_action, in action_script.c),
//   0x3E CntrAttk (54), 0x3F Change, ItrpChange, AttkChange, DEF Change, HealChange (55-59).
// Skill names from the in-game skill list and help texts (text at 0x083BE4D4); effects match a
// public FAQ's skill table. Steps 1-3 of each table are the shared time-out steps and 4-7 the shared
// "small Medabot tosses something" steps of battle/action_steps.
// Statuses set on the target: statusType = skill id (0x2B Impair, 0x2C Confusion, 0x2E / 0x2F No Escape /
// No Defense), statusPart = Impair's part kind + 1, statusTimer / statusAmount = durations (clamp_1_99).

#include "global.h"
#include "constants/skill_sprites.h"
#include "constants/sprites.h"

void impair_run(void) {
    gBattleWork.stepDone = 0;
    gImpairSteps[gBattleWork.step]();
}

void impair_begin(void) {
    calc_battle_action_speed(gBattleWork.actor, gBattleWork.actorPart);
    apply_battle_bot_damage_reduction(gBattleWork.actor);
    if (decrement_battle_timer_and_check_zero()) {
        gBattleWork.messageId = 0x1A;
        gBattleWork.step++;
    } else if (battle_bot_lacks_stability(gBattleWork.target) == 0) {
        gBattleWork.messageId = 0x39;
        gBattleWork.step++;
    } else {
        side_add_action_point();
        calc_battle_stat_ratio(gBattleWork.actor, gBattleWork.actorPart);
        gBattleWork.step = 4;
    }
}

void impair_portrait_spawn(void) {
    lz_decompress_dispatch(gImpairPortraitTiles, (void *)(OBJ_VRAM0 + 0x4800));
    CpuFastSet(gImpairPortraitPalette, (void *)0x050002E0, 8);
    gSpriteEntries[0x21].flags |= SPRITE_FLAG_AFFINE | SPRITE_FLAG_DOUBLE_SIZE;
    gSpriteEntries[0x21].scale_x = 0x40;
    gSpriteEntries[0x21].scale_y = 0x40;
    gSpriteEntries[0x21].angle = 0;
    gSpriteEntries[0x21].frame = 0x4E00;
    gSpriteEntries[0x21].work16[FX_SPR_TARGET_X] = gSpriteEntries[0x5D + gBattleWork.target * 4].x;
    gSpriteEntries[0x21].work16[FX_SPR_TARGET_Y] = gSpriteEntries[0x5D + gBattleWork.target * 4].y - 4;
    gSpriteEntries[0x21].work[SPR_MOTION_TABLE] = 6;
    gGameWork.stepTimer = 0x3C;
    gBattleWork.step++;
}

// Shows the portrait icon with the targeted part (targetPart: 0 head, 1 right arm, 2 left arm) highlighted.
void impair_part_icon_spawn(void) {
    disable_sprites(0x21, 1);
    gSpriteEntries[0x22].flags =
        SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[0x22].frame_table = 0;
    gSpriteEntries[0x22].x = gSpriteEntries[0x5D + gBattleWork.target * 4].x;
    gSpriteEntries[0x22].y = gSpriteEntries[0x5D + gBattleWork.target * 4].y - 4;
    gSpriteEntries[0x22].palette = 7;
    gSpriteEntries[0x22].order = 0xE0;
    gSpriteEntries[0x22].work[FX_SPR_STEP] = 0;
    switch (gBattleWork.targetPart) {
    case 1:
        gSpriteEntries[0x22].frame = 0x4E02;
        break;
    case 2:
        gSpriteEntries[0x22].frame = 0x4E03;
        break;
    default:
        gSpriteEntries[0x22].frame = 0x4E01;
        break;
    }
    play_sound_effect(0x6A);
    gBattleWork.step++;
}

void interrupt_icon_anim_wait(void) {
    if (advance_sprite_anim_frame(0x22, 0)) {
        gGameWork.stepTimer = 0x3C;
        gBattleWork.step++;
    }
}

// Steps shared with No Escape / No Defense: the X drawn over the icon, shrinking in, then shaking.
void interrupt_cross_spawn(void) {
    enable_sprites(0x21, 1);
    gSpriteEntries[0x21].flags |= SPRITE_FLAG_AFFINE | SPRITE_FLAG_DOUBLE_SIZE;
    gSpriteEntries[0x21].scale_x = 0x80;
    gSpriteEntries[0x21].scale_y = 0x80;
    gBattleWork.step++;
}

void interrupt_cross_shrink(void) {
    if (gSpriteEntries[0x21].scale_x == 0x40) {
        play_sound_effect(0x3C);
        gGameWork.stepTimer = 0;
        gBattleWork.step++;
    } else {
        gSpriteEntries[0x21].scale_x -= 8;
        gSpriteEntries[0x21].scale_y -= 8;
    }
}

void interrupt_cross_shake(void) {
    if (gGameWork.stepTimer == 0x3C) {
        clear_battle_sprite_slot(0x21, 2);
        gBattleWork.step++;
    } else {
        gGameWork.stepTimer++;
        if (gGameWork.stepTimer & 4)
            gSpriteEntries[0x21].x = gSpriteEntries[0x5D + gBattleWork.target * 4].x - 2;
        else
            gSpriteEntries[0x21].x = gSpriteEntries[0x5D + gBattleWork.target * 4].x + 2;
    }
}

void impair_apply(void) {
    gBattleBots[gBattleWork.target].statusType = 0x2B;
    gBattleBots[gBattleWork.target].statusTimer = clamp_1_99(gBattleWork.success);
    gBattleBots[gBattleWork.target].statusAmount = clamp_1_99(gBattleWork.amount);
    switch (gBattleWork.targetPart) {
    case 1:
        gBattleBots[gBattleWork.target].statusPart = 2;
        break;
    case 2:
        gBattleBots[gBattleWork.target].statusPart = 3;
        break;
    default:
        gBattleBots[gBattleWork.target].statusPart = 1;
        break;
    }
    gBattleWork.step++;
}

void impair_finish(void) {
    const u8 *kind_name;

    switch (gBattleWork.targetPart) {
    case 1:
        kind_name = gPartKindNames[1];
        break;
    case 2:
        kind_name = gPartKindNames[2];
        break;
    default:
        kind_name = gPartKindNames[0];
        break;
    }
    copy_bytes(kind_name, gGameWork.textBuf, 0xE);
    gBattleWork.messageId = 0x30;
    gBattleWork.step++;
}

void confusion_run(void) {
    gBattleWork.stepDone = 0;
    gConfusionSteps[gBattleWork.step]();
}

void confusion_begin(void) {
    calc_battle_action_speed(gBattleWork.actor, gBattleWork.actorPart);
    apply_battle_bot_damage_reduction(gBattleWork.actor);
    if (decrement_battle_timer_and_check_zero()) {
        gBattleWork.messageId = 0x1A;
        gBattleWork.step++;
    } else if (battle_bot_lacks_stability(gBattleWork.target) == 0) {
        gBattleWork.messageId = 0x39;
        gBattleWork.step++;
    } else {
        side_add_action_point();
        calc_battle_stat_ratio(gBattleWork.actor, gBattleWork.actorPart);
        gBattleWork.step = 4;
    }
}

void confusion_ball_spawn(void) {
    lz_decompress_dispatch(gConfusionBallTilesLz, (void *)(OBJ_VRAM0 + 0x4800));
    CpuFastSet(gConfusionBallPalettes, (void *)0x050002C0, 0x10);
    if (gBattleWork.actorSideFlags & 1)
        gSpriteEntries[0x21].flags |= SPRITE_FLAG_HFLIP;
    gSpriteEntries[0x21].flags |= SPRITE_FLAG_AFFINE | SPRITE_FLAG_DOUBLE_SIZE;
    gSpriteEntries[0x21].scale_x = 0x40;
    gSpriteEntries[0x21].scale_y = 0x40;
    gSpriteEntries[0x21].angle = 0;
    gSpriteEntries[0x21].palette = 6;
    gSpriteEntries[0x21].frame = 0x4F00;
    gSpriteEntries[0x21].work16[FX_SPR_TARGET_X] = gSpriteEntries[0x5D + gBattleWork.target * 4].x;
    gSpriteEntries[0x21].work16[FX_SPR_TARGET_Y] = gSpriteEntries[0x5D + gBattleWork.target * 4].y - 4;
    gSpriteEntries[0x21].work[SPR_MOTION_TABLE] = 6;
    gGameWork.stepTimer = 0x3C;
    gBattleWork.step++;
}

void confusion_wave_init(void) {
    play_sound_effect(0x33);
    gSpriteEntries[0x21].flags |= SPRITE_FLAG_AFFINE | SPRITE_FLAG_DOUBLE_SIZE;
    gBattleWork.step++;
}

void confusion_wave_spin(void) {
    if (!(gBattleWork.actorSideFlags & 1))
        gSpriteEntries[0x21].angle = (gSpriteEntries[0x21].angle - 0x80) & 0x3FF;
    else
        gSpriteEntries[0x21].angle = (gSpriteEntries[0x21].angle + 0x80) & 0x3FF;
    if (gSpriteEntries[0x21].scale_x == 0x80)
        gBattleWork.step++;
    else {
        gSpriteEntries[0x21].scale_x++;
        gSpriteEntries[0x21].scale_y++;
    }
}

void confusion_marks_spawn(void) {
    if (gBattleWork.actorSideFlags & 1)
        gSpriteEntries[0x21].flags &= ~SPRITE_FLAG_HFLIP;
    gSpriteEntries[0x21].scale_x = 0x40;
    gSpriteEntries[0x21].scale_y = 0x40;
    gSpriteEntries[0x21].angle = 0;
    gSpriteEntries[0x21].palette = 7;
    gSpriteEntries[0x21].x = gSpriteEntries[0x5D + gBattleWork.target * 4].x;
    gSpriteEntries[0x21].y = gSpriteEntries[0x5D + gBattleWork.target * 4].y - 0xC;
    gGameWork.stepCounter = 0x47;
    battle_sprite_anim_init(gBattleSpriteAnimScripts[gGameWork.stepCounter], 0x21);
    play_sound_effect(0x4F);
    gBattleWork.step++;
}

void confusion_apply(void) {
    clear_battle_sprite_slot(0x21, 1);
    gBattleBots[gBattleWork.target].statusType = 0x2C;
    gBattleBots[gBattleWork.target].statusPart = 0;
    gBattleBots[gBattleWork.target].statusTimer = clamp_1_99(gBattleWork.success);
    gBattleBots[gBattleWork.target].statusAmount = clamp_1_99(gBattleWork.amount);
    gBattleWork.step++;
}

void confusion_finish(void) {
    gBattleWork.messageId = 0x33;
    gBattleWork.step++;
}

void use_drain_run(void) {
    gBattleWork.stepDone = 0;
    gUseDrainSteps[gBattleWork.step]();
}

// Fails (messageId 0x34) when the target's head has no uses left.
void use_drain_begin(void) {
    calc_battle_action_speed(gBattleWork.actor, gBattleWork.actorPart);
    apply_battle_bot_damage_reduction(gBattleWork.actor);
    if (decrement_battle_timer_and_check_zero()) {
        gBattleWork.messageId = 0x1A;
        gBattleWork.step++;
    } else if (gBattleBots[gBattleWork.target].parts[0].headUses == 0) {
        gBattleWork.messageId = 0x34;
        gBattleWork.step++;
    } else {
        side_add_action_point();
        calc_battle_stat_ratio(gBattleWork.actor, gBattleWork.actorPart);
        gBattleWork.step = 4;
    }
}

void use_drain_bubble_spawn(void) {
    lz_decompress_dispatch(gDrainBubbleTilesLz, (void *)(OBJ_VRAM0 + 0x4800));
    CpuFastSet(gDrainBubblePalettes, (void *)0x050002C0, 0x10);
    gSpriteEntries[0x21].flags |= SPRITE_FLAG_AFFINE | SPRITE_FLAG_DOUBLE_SIZE;
    gSpriteEntries[0x21].scale_x = 0x40;
    gSpriteEntries[0x21].scale_y = 0x40;
    gSpriteEntries[0x21].angle = 0;
    gSpriteEntries[0x21].palette = 6;
    gSpriteEntries[0x21].frame = 0x5000;
    gSpriteEntries[0x21].work16[FX_SPR_TARGET_X] = gSpriteEntries[0x5D + gBattleWork.target * 4].x;
    gSpriteEntries[0x21].work16[FX_SPR_TARGET_Y] = gSpriteEntries[0x5D + gBattleWork.target * 4].y - 4;
    gSpriteEntries[0x21].work[SPR_MOTION_TABLE] = 3;
    gSpriteEntries[0x21].work[FX_SPR_STEP] = 0;
    gGameWork.stepTimer = 0x3C;
    gBattleWork.step++;
}

void use_drain_bubble_hold(void) {
    sprite_bob_step(0x21);
    if (gGameWork.skipBotSetup == 0 && (KEYS_LO(gRepeatKeys) & A_BUTTON))
        gBattleWork.step++;
    else if (gGameWork.stepTimer)
        gGameWork.stepTimer--;
    else
        gBattleWork.step++;
}

void use_drain_bubble_fly(void) {
    if (move_sprite_toward_target(0x21))
        gBattleWork.step++;
    sprite_bob_step(0x21);
}

void use_drain_drop_spawn(void) {
    sprite_bob_step(0x21);
    gSpriteEntries[0x22].flags =
        SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_AFFINE | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[0x22].frame_table = 0;
    gSpriteEntries[0x22].x = gSpriteEntries[0x5D + gBattleWork.target * 4].x;
    gSpriteEntries[0x22].y = gSpriteEntries[0x5D + gBattleWork.target * 4].y - 4;
    gSpriteEntries[0x22].scale_x = 1;
    gSpriteEntries[0x22].scale_y = 1;
    gSpriteEntries[0x22].palette = 7;
    gSpriteEntries[0x22].order = 0xE0;
    gSpriteEntries[0x22].frame = 0x5001;
    gSpriteEntries[0x22].work16[FX_SPR_TARGET_X] = gSpriteEntries[0x5D + gBattleWork.actor * 4].x;
    gSpriteEntries[0x22].work16[FX_SPR_TARGET_Y] = gSpriteEntries[0x5D + gBattleWork.actor * 4].y - 4;
    gSpriteEntries[0x22].work[SPR_MOTION_TABLE] = 3;
    gSpriteEntries[0x21].work16[FX_SPR_TARGET_X] = gSpriteEntries[0x5D + gBattleWork.actor * 4].x;
    gSpriteEntries[0x21].work16[FX_SPR_TARGET_Y] = gSpriteEntries[0x5D + gBattleWork.actor * 4].y - 4;
    gSpriteEntries[0x21].work[SPR_MOTION_TABLE] = 3;
    play_sound_effect(0x6F);
    gBattleWork.step++;
}

void use_drain_drop_grow(void) {
    sprite_bob_step(0x21);
    if (gSpriteEntries[0x22].scale_x == 0x40) {
        gSpriteEntries[0x22].x = gSpriteEntries[0x21].x;
        gSpriteEntries[0x22].y = gSpriteEntries[0x21].y;
        gBattleWork.step++;
    } else {
        gSpriteEntries[0x22].scale_x++;
        gSpriteEntries[0x22].scale_y++;
    }
}

void use_drain_bubble_return(void) {
    if (move_sprite_toward_target(0x21)) {
        gSpriteEntries[0x22].x = gSpriteEntries[0x21].x;
        gSpriteEntries[0x22].y = gSpriteEntries[0x21].y;
        play_sound_effect(0x2B);
        gBattleWork.step++;
    }
    sprite_bob_step(0x21);
    gSpriteEntries[0x22].x = gSpriteEntries[0x21].x;
    gSpriteEntries[0x22].y = gSpriteEntries[0x21].y;
}

void use_drain_bubble_shrink(void) {
    sprite_bob_step(0x21);
    gSpriteEntries[0x22].x = gSpriteEntries[0x21].x;
    gSpriteEntries[0x22].y = gSpriteEntries[0x21].y;
    if (gSpriteEntries[0x21].scale_x == 1) {
        clear_battle_sprite_slot(0x21, 2);
        gBattleWork.step++;
    } else {
        gSpriteEntries[0x21].scale_x--;
        gSpriteEntries[0x21].scale_y--;
        gSpriteEntries[0x22].scale_x--;
        gSpriteEntries[0x22].scale_y--;
    }
}

// Moves head uses (parts[0].headUses) from the target to the user, capped by the user's maximum (data[8]).
void use_drain_apply(void) {
    calc_head_uses_taken(gBattleWork.target, gBattleWork.amount);
    gBattleWork.scratch = gBattleWork.appliedAmount;
    subtract_u8_floored(&gBattleBots[gBattleWork.target].parts[0].headUses, gBattleWork.scratch);
    calc_head_uses_given(gBattleWork.actor, gBattleWork.scratch);
    gBattleWork.scratchValue = gBattleWork.appliedAmount;
    add_u8_capped(&gBattleBots[gBattleWork.actor].parts[0].headUses, gBattleWork.scratchValue,
                  gBattleBots[gBattleWork.actor].parts[0].data[8]);
    gBattleWork.step++;
}

void use_drain_popup_init(void) {
    lz_decompress_dispatch(gBattlePopupDigitTiles, (void *)(OBJ_VRAM0 + 0x7E00));
    set_display_digit_type(&gGameWork.partAbility, gBattleWork.scratch, 1);
    battle_text_popup_init_slot(&gGameWork.partAbility, gBattleWork.target, 0x21);
    set_display_digit_type(&gGameWork.partAbility + 0x20, gBattleWork.scratchValue, 0);
    battle_text_popup_init_slot(&gGameWork.partAbility + 0x20, gBattleWork.actor, 0x21);
    play_sound_effect(0x5B);
    gGameWork.stepCounter = 0;
    gBattleWork.step++;
}

void use_drain_popup_wait(void) {
    battle_popup_update_slot(&gGameWork.partAbility, gBattleWork.target, 0x21);
    battle_popup_update_slot(&gGameWork.partAbility + 0x20, gBattleWork.actor, 0x21);
    if (++gGameWork.stepCounter,
        gGameWork.skipBotSetup == 0 && (KEYS_LO(gRepeatKeys) & A_BUTTON) && gGameWork.stepCounter > 0x32)
        gGameWork.stepCounter = 0x78;
    if (gGameWork.stepCounter == 0x78) {
        clear_battle_sprite_slot(gBattleWork.target * 4 + 0x21, 4);
        clear_battle_sprite_slot(gBattleWork.actor * 4 + 0x21, 4);
        gBattleWork.step++;
    }
}

void use_drain_finish(void) {
    divide_by_100000_b(gGameWork.textBuf, gBattleWork.scratch, 0x35);
    gBattleWork.messageId = 0x35;
    gBattleWork.step++;
}

void no_escape_defense_run(void) {
    gBattleWork.stepDone = 0;
    gNoEscapeDefenseSteps[gBattleWork.step]();
}

void no_escape_defense_begin(void) {
    calc_battle_action_speed(gBattleWork.actor, gBattleWork.actorPart);
    apply_battle_bot_damage_reduction(gBattleWork.actor);
    if (decrement_battle_timer_and_check_zero()) {
        gBattleWork.messageId = 0x1A;
        gBattleWork.step++;
    } else if (battle_bot_lacks_stability(gBattleWork.target) == 0) {
        gBattleWork.messageId = 0x39;
        gBattleWork.step++;
    } else {
        side_add_action_point();
        calc_battle_stat_ratio(gBattleWork.actor, gBattleWork.actorPart);
        gBattleWork.step = 4;
    }
}

// Ability 46 (0x2E) shows the running-person icon, 47 the shield icon.
void no_escape_defense_icon_load(void) {
    if (gBattleBots[gBattleWork.actor].parts[gBattleWork.actorPart].data[1] == 0x2E) {
        lz_decompress_dispatch(gNoEscapeIconTilesLz, (void *)(OBJ_VRAM0 + 0x4800));
        CpuFastSet(gNoEscapeIconPalette, (void *)0x050002E0, 0x10);
    } else {
        lz_decompress_dispatch(gDefenseIconTilesLz, (void *)(OBJ_VRAM0 + 0x4800));
        CpuFastSet(gDefenseIconPalette, (void *)0x050002E0, 0x10);
    }
    gSpriteEntries[0x21].flags |= SPRITE_FLAG_AFFINE | SPRITE_FLAG_DOUBLE_SIZE;
    gSpriteEntries[0x21].scale_x = 0x40;
    gSpriteEntries[0x21].scale_y = 0x40;
    gSpriteEntries[0x21].angle = 0;
    gSpriteEntries[0x21].palette = 7;
    gSpriteEntries[0x21].frame = 0x5200;
    gSpriteEntries[0x21].work16[FX_SPR_TARGET_X] = gSpriteEntries[0x5D + gBattleWork.target * 4].x;
    gSpriteEntries[0x21].work16[FX_SPR_TARGET_Y] = gSpriteEntries[0x5D + gBattleWork.target * 4].y - 4;
    gSpriteEntries[0x21].work[SPR_MOTION_TABLE] = 6;
    gGameWork.stepTimer = 0x3C;
    gBattleWork.step++;
}

void no_escape_defense_icon_spawn(void) {
    disable_sprites(0x21, 1);
    gSpriteEntries[0x22].flags =
        SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[0x22].frame_table = 0;
    gSpriteEntries[0x22].x = gSpriteEntries[0x5D + gBattleWork.target * 4].x;
    gSpriteEntries[0x22].y = gSpriteEntries[0x5D + gBattleWork.target * 4].y - 4;
    gSpriteEntries[0x22].palette = 7;
    gSpriteEntries[0x22].order = 0xE0;
    gSpriteEntries[0x22].work[FX_SPR_STEP] = 0;
    gSpriteEntries[0x22].frame = 0x5201;
    play_sound_effect(0x6A);
    gBattleWork.step++;
}

void no_escape_defense_apply(void) {
    gBattleBots[gBattleWork.target].statusPart = 0;
    gBattleBots[gBattleWork.target].statusTimer = clamp_1_99(gBattleWork.success);
    gBattleBots[gBattleWork.target].statusAmount = clamp_1_99(gBattleWork.amount);
    if (gBattleBots[gBattleWork.actor].parts[gBattleWork.actorPart].data[1] == 0x2E)
        gBattleBots[gBattleWork.target].statusType = 0x2E;
    else
        gBattleBots[gBattleWork.target].statusType = 0x2F;
    gBattleWork.step++;
}

void no_escape_defense_finish(void) {
    if (gBattleBots[gBattleWork.actor].parts[gBattleWork.actorPart].data[1] == 0x2E)
        gBattleWork.messageId = 0x31;
    else
        gBattleWork.messageId = 0x32;
    gBattleWork.step++;
}

void forcedrain_run(void) {
    gBattleWork.stepDone = 0;
    gForcedrainSteps[gBattleWork.step]();
}

// Fails (messageId 0x74) when the target has no Medaforce (medaforceGauge).
void forcedrain_begin(void) {
    calc_battle_action_speed(gBattleWork.actor, gBattleWork.actorPart);
    apply_battle_bot_damage_reduction(gBattleWork.actor);
    if (decrement_battle_timer_and_check_zero()) {
        gBattleWork.messageId = 0x1A;
        gBattleWork.step++;
    } else if (gBattleBots[gBattleWork.target].medaforceGauge == 0) {
        gBattleWork.messageId = 0x74;
        gBattleWork.step++;
    } else {
        side_add_action_point();
        calc_battle_stat_ratio(gBattleWork.actor, gBattleWork.actorPart);
        gBattleWork.step = 4;
    }
}

void forcedrain_glass_spawn(void) {
    lz_decompress_dispatch(gForcedrainGlassTiles, (void *)(OBJ_VRAM0 + 0x4800));
    CpuFastSet(gForcedrainGlassPalettes, (void *)0x050002E0, 0x10);
    gSpriteEntries[0x21].flags |= SPRITE_FLAG_AFFINE | SPRITE_FLAG_DOUBLE_SIZE;
    gSpriteEntries[0x21].scale_x = 0x40;
    gSpriteEntries[0x21].scale_y = 0x40;
    gSpriteEntries[0x21].angle = 0;
    gSpriteEntries[0x21].palette = 7;
    gSpriteEntries[0x21].work16[FX_SPR_TARGET_X] = gSpriteEntries[0x5D + gBattleWork.target * 4].x;
    gSpriteEntries[0x21].work16[FX_SPR_TARGET_Y] = gSpriteEntries[0x5D + gBattleWork.target * 4].y - 4;
    gSpriteEntries[0x21].work[SPR_MOTION_TABLE] = 6;
    gSpriteEntries[0x21].work[FX_SPR_STEP] = 0;
    gGameWork.stepCounter = 0x48;
    battle_sprite_anim_init(gBattleSpriteAnimScripts[gGameWork.stepCounter], 0x21);
    gGameWork.stepTimer = 0x3C;
    gBattleWork.step++;
}

// Drains up to amount Medaforce from the target and gives it to the user (doubled when guardFlags bit 3 is set);
// the gauge steps run on the target first (actor swapped, restored by forcedrain_glass_return).
void forcedrain_calc(void) {
    calc_drain_amount(gBattleBots[gBattleWork.target].medaforceGauge, gBattleWork.amount);
    gBattleWork.scratch = gBattleWork.appliedAmount;
    if (gBattleBots[gBattleWork.actor].guardFlags & 8)
        calc_fill_amount(gBattleBots[gBattleWork.actor].medaforceGauge, 0x50, gBattleWork.scratch * 2);
    else
        calc_fill_amount(gBattleBots[gBattleWork.actor].medaforceGauge, 0x50, gBattleWork.scratch);
    gBattleWork.scratchValue = gBattleWork.appliedAmount;
    gBattleWork.partIds[0] = gBattleWork.actor;
    gBattleWork.actor = gBattleWork.target;
    battle_substeps_reset();
    gBattleWork.step++;
}

void forcedrain_substate_wait(void) {
    if (target_panels_show(0))
        gBattleWork.step++;
}

void forcedrain_gauge_sound(void) {
    target_panels_show(0);
    play_sound_effect(0x51);
    gBattleWork.step++;
}

void forcedrain_gauge_drain(void) {
    s32 done;

    target_panels_show(0);
    done = medaforce_gauge_drain_step(gBattleWork.actor);
    process_sprite_anim_commands(gBattleSpriteAnimScripts[gGameWork.stepCounter], 0x21);
    if (gSpriteEntries[0x21].work[SPR_CMD_STATE] == SPR_CMD_ENDED)
        done++;
    if (done == 2) {
        clear_battle_ui_tilemaps();
        battle_substeps_reset();
        gBattleWork.step++;
    }
}

void forcedrain_glass_return(void) {
    gBattleWork.actor = gBattleWork.partIds[0];
    gBattleWork.scratch = gBattleWork.scratchValue;
    gSpriteEntries[0x21].flags |= SPRITE_FLAG_AFFINE | SPRITE_FLAG_DOUBLE_SIZE;
    gSpriteEntries[0x21].scale_x = 0x40;
    gSpriteEntries[0x21].scale_y = 0x40;
    gSpriteEntries[0x21].angle = 0;
    gSpriteEntries[0x21].palette = 7;
    gSpriteEntries[0x21].work16[FX_SPR_TARGET_X] = gSpriteEntries[0x5D + gBattleWork.actor * 4].x;
    gSpriteEntries[0x21].work16[FX_SPR_TARGET_Y] = gSpriteEntries[0x5D + gBattleWork.actor * 4].y - 4;
    gSpriteEntries[0x21].work[SPR_MOTION_TABLE] = 6;
    gSpriteEntries[0x21].work[FX_SPR_STEP] = 0;
    gBattleWork.step++;
}

void forcedrain_gauge_fill(void) {
    s32 done;

    target_panels_show(0);
    done = medaforce_gauge_fill_step(gBattleWork.actor);
    if (gSpriteEntries[0x21].flags & SPRITE_FLAG_ENABLED) {
        gSpriteEntries[0x21].flags |= SPRITE_FLAG_AFFINE | SPRITE_FLAG_DOUBLE_SIZE;
        if (gSpriteEntries[0x21].scale_x == 1) {
            clear_battle_sprite_slot(0x21, 1);
        } else {
            gSpriteEntries[0x21].scale_x--;
            gSpriteEntries[0x21].scale_y--;
        }
    } else {
        done++;
    }
    if (done == 2) {
        clear_battle_ui_tilemaps();
        battle_substeps_reset();
        gBattleWork.step++;
    }
}

void forcedrain_finish(void) {
    gBattleWork.messageId = 0x75;
    gBattleWork.step++;
}

void team_attack_check_run(void) {
    gBattleWork.stepDone = 0;
    gTeamAttackCheckSteps[gBattleWork.step]();
}

// guess: TeamAttack needs the queued action of slot otherSide to be Team Form (skill 0x33); else it fails
// with messageId 0x22.
void team_attack_check_form(void) {
    if (gBattleWork.traps[gBattleWork.otherSide].active && gBattleWork.traps[gBattleWork.otherSide].skill == 0x33) {
        gBattleWork.stepResult = 0;
        gBattleWork.step++;
    } else {
        gBattleWork.messageId = 0x22;
        gBattleWork.stepResult = 1;
        gBattleWork.step = 2;
    }
}

void team_attack_turrets_run(void) {
    gBattleWork.stepDone = 0;
    gTeamAttackTurretSteps[gBattleWork.step]();
}

void team_attack_turrets_spawn(void) {
    u32 i;

    lz_decompress_dispatch(gTeamAttackTurretTilesLz, (void *)(OBJ_VRAM0 + 0x4800));
    CpuFastSet(gTeamAttackTurretPalette, (void *)0x050002E0, 8);
    for (i = 0; i <= 2; i++) {
        gSpriteEntries[i + 0x21].flags =
            SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_PART_PALETTE;
        gSpriteEntries[i + 0x21].frame_table = 0;
        gSpriteEntries[i + 0x21].y = 0x58 - i * 0x18;
        gSpriteEntries[i + 0x21].palette = 7;
        gSpriteEntries[i + 0x21].order = 0xF0;
        battle_sprite_anim_init(gBattleSpriteAnimScripts[0x38], i + 0x21);
        if (!(gBattleWork.actorSideFlags & 1)) {
            gSpriteEntries[i + 0x21].x = 0x88;
        } else {
            gSpriteEntries[i + 0x21].flags |= SPRITE_FLAG_HFLIP;
            gSpriteEntries[i + 0x21].x = 0x68;
        }
    }
    play_sound_effect(0x52);
    gBattleWork.step++;
}

void team_attack_turrets_anim(void) {
    u32 i;
    s32 done = 0;

    for (i = 0; i <= 2; i++) {
        process_sprite_anim_commands(gBattleSpriteAnimScripts[0x38], i + 0x21);
        if (gSpriteEntries[i + 0x21].work[SPR_CMD_STATE] == SPR_CMD_ENDED)
            done = 1;
    }
    if (done) {
        gGameWork.stepTimer = 0x3C;
        gBattleWork.step++;
    }
}

void team_attack_turrets_clear(void) {
    clear_battle_sprite_slot(0x21, 3);
    gBattleWork.step++;
}

void counter_attack_run(void) {
    gBattleWork.stepDone = 0;
    gCounterAttackSteps[gBattleWork.step]();
}

void counter_attack_begin(void) {
    calc_battle_action_speed(gBattleWork.actor, gBattleWork.actorPart);
    apply_battle_bot_damage_reduction(gBattleWork.actor);
    if (decrement_battle_timer_and_check_zero()) {
        gBattleWork.messageId = 0x1A;
        gBattleWork.step++;
    } else {
        side_add_action_point();
        calc_battle_stat_ratio(gBattleWork.actor, gBattleWork.actorPart);
        gBattleWork.step = 4;
    }
}

void counter_attack_ball_spawn(void) {
    lz_decompress_dispatch(gCounterAttackBallTilesLz, (void *)(OBJ_VRAM0 + 0x4800));
    CpuFastSet(gCounterAttackBallPalette, (void *)0x050002E0, 8);
    gSpriteEntries[0x21].flags = SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_AFFINE |
                                 SPRITE_FLAG_DOUBLE_SIZE | SPRITE_FLAG_PART_PALETTE;
    if (gBattleWork.actorSideFlags & 1)
        gSpriteEntries[0x21].flags |= SPRITE_FLAG_HFLIP;
    gSpriteEntries[0x21].frame_table = 0;
    gSpriteEntries[0x21].x = gSpriteEntries[0x5D + gBattleWork.actor * 4].x;
    gSpriteEntries[0x21].y = gSpriteEntries[0x5D + gBattleWork.actor * 4].y - 6;
    gSpriteEntries[0x21].angle = 0;
    gSpriteEntries[0x21].scale_x = 0x40;
    gSpriteEntries[0x21].scale_y = 0x40;
    gSpriteEntries[0x21].palette = 7;
    gSpriteEntries[0x21].order = 0xF0;
    gSpriteEntries[0x21].frame = 0x616;
    gSpriteEntries[0x21].work[FX_SPR_STEP] = 0;
    battle_sprite_anim_init(gBattleSpriteAnimScripts[0x4A], 0x21);
    gBattleWork.step++;
}

void counter_attack_glove_show(void) {
    process_sprite_anim_commands(gBattleSpriteAnimScripts[0x4A], 0x21);
    if (gSpriteEntries[0x21].work[SPR_CMD_STATE] == SPR_CMD_ENDED) {
        gSpriteEntries[0x21].scale_x = 0x80;
        gSpriteEntries[0x21].scale_y = 0x80;
        gSpriteEntries[0x21].frame = 0x5604;
        gSpriteEntries[0x21].y = gSpriteEntries[0x5D + gBattleWork.actor * 4].y - 4;
        gBattleWork.step++;
    }
}

void counter_attack_glove_shrink(void) {
    if (gSpriteEntries[0x21].scale_x == 0x40) {
        play_sound_effect(0x53);
        gBattleWork.step++;
    } else {
        gSpriteEntries[0x21].scale_x -= 8;
        gSpriteEntries[0x21].scale_y -= 8;
    }
}

void counter_attack_glove_pulse_grow(void) {
    if (gSpriteEntries[0x21].scale_x == 0x50) {
        gBattleWork.step++;
    } else {
        gSpriteEntries[0x21].scale_x += 4;
        gSpriteEntries[0x21].scale_y += 4;
    }
}

void counter_attack_glove_pulse_shrink(void) {
    if (gSpriteEntries[0x21].scale_x == 0x40) {
        gGameWork.stepTimer = 0x3C;
        gBattleWork.step++;
    } else {
        gSpriteEntries[0x21].scale_x -= 4;
        gSpriteEntries[0x21].scale_y -= 4;
    }
}

// Arms the counter on the user: stateFlags bit 4, lastActionSkill = the skill id, defence = the part's data[6].
void counter_attack_apply(void) {
    clear_battle_sprite_slot(0x21, 1);
    gBattleBots[gBattleWork.actor].stateFlags |= 0x10;
    gBattleBots[gBattleWork.actor].lastActionSkill =
        gBattleBots[gBattleWork.actor].parts[gBattleWork.actorPart].data[1];
    gBattleBots[gBattleWork.actor].defence = 0;
    add_u8_capped(&gBattleBots[gBattleWork.actor].moveSubpixel + 1,
                  gBattleBots[gBattleWork.actor].parts[gBattleWork.actorPart].data[6], 0xFF);
    gBattleWork.step++;
}

void counter_attack_finish(void) {
    gBattleWork.messageId = 0x2A;
    gBattleWork.step++;
}

void change_run(void) {
    gBattleWork.stepDone = 0;
    gChangeSteps[gBattleWork.step]();
}

// stepResult = 0 lets script_op_change restart the action (battle state 8) with the part swapped in.
void change_begin(void) {
    u32 timed_out;

    calc_battle_action_speed(gBattleWork.actor, gBattleWork.actorPart);
    apply_battle_bot_damage_reduction(gBattleWork.actor);
    timed_out = decrement_battle_timer_and_check_zero();
    if (timed_out) {
        gBattleWork.stepResult = 1;
        gBattleWork.messageId = 0x1A;
        gBattleWork.step++;
    } else {
        side_add_action_point();
        calc_battle_stat_ratio(gBattleWork.actor, gBattleWork.actorPart);
        gBattleWork.stepResult = timed_out;
        gBattleWork.step = 4;
    }
}

void change_effect_spawn(void) {
    lz_decompress_dispatch(gChangeEffectTilesLz, (void *)(OBJ_VRAM0 + 0x4800));
    CpuFastSet(gChangeEffectPalettes, (void *)0x050002C0, 0x10);
    gSpriteEntries[0x21].flags =
        SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[0x21].frame_table = 0;
    gSpriteEntries[0x21].x = gSpriteEntries[0x5D + gBattleWork.actor * 4].x;
    gSpriteEntries[0x21].y = gSpriteEntries[0x5D + gBattleWork.actor * 4].y - 4;
    gSpriteEntries[0x21].palette = 6;
    gSpriteEntries[0x21].order = 0xE0;
    battle_sprite_anim_init(gBattleSpriteAnimScripts[0x4B], 0x21);
    gSpriteEntries[0x22].flags =
        SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[0x22].frame_table = 0;
    gSpriteEntries[0x22].x = gSpriteEntries[0x5D + gBattleWork.actor * 4].x;
    gSpriteEntries[0x22].y = gSpriteEntries[0x5D + gBattleWork.actor * 4].y - 6;
    gSpriteEntries[0x22].palette = 7;
    gSpriteEntries[0x22].order = 0xF0;
    battle_sprite_anim_init(gBattleSpriteAnimScripts[0x4C], 0x22);
    play_sound_effect(0x5E);
    gGameWork.stepTimer = 0;
    gBattleWork.step++;
}

void change_effect_anim(void) {
    if (gGameWork.stepTimer == 0x5A) {
        gBattleWork.step++;
    } else {
        gGameWork.stepTimer++;
        process_sprite_anim_commands(gBattleSpriteAnimScripts[0x4B], 0x21);
        process_sprite_anim_commands(gBattleSpriteAnimScripts[0x4C], 0x22);
    }
}

// Swaps the acting part for a random one of the ability's family (changeSkill: 0 Change, 1 ItrpChange,
// 2 AttkChange, 3 DEF Change, 4 HealChange); the original part is kept in savedPart (partChanged = 1) and restored
// after the action.
void change_transform_part(void) {
    process_sprite_anim_commands(gBattleSpriteAnimScripts[0x4B], 0x21);
    process_sprite_anim_commands(gBattleSpriteAnimScripts[0x4C], 0x22);
    gBattleWork.partChanged = 1;
    gBattleWork.changeSkill = gBattleBots[gBattleWork.actor].parts[gBattleWork.actorPart].data[1] - 0x37;
    gBattleWork.changePartId = pick_random_change_part(gBattleWork.changeSkill, gBattleWork.actorPart);
    copy_bytes(&gBattleBots[gBattleWork.actor].parts[gBattleWork.actorPart], &gBattleWork.savedPart, 0x18);
    load_part_data(gBattleWork.changePartId, gBattleWork.actorPart, &gGameWork.partAbility);
    gBattleBots[gBattleWork.actor].parts[gBattleWork.actorPart].data[0] = (&gGameWork.partAbility)[0];
    gBattleBots[gBattleWork.actor].parts[gBattleWork.actorPart].data[1] = (&gGameWork.partAbility)[1];
    gBattleBots[gBattleWork.actor].parts[gBattleWork.actorPart].data[5] = (&gGameWork.partAbility)[5];
    gBattleBots[gBattleWork.actor].parts[gBattleWork.actorPart].data[6] = (&gGameWork.partAbility)[6];
    gBattleBots[gBattleWork.actor].parts[gBattleWork.actorPart].data[7] = (&gGameWork.partAbility)[7];
    gBattleBots[gBattleWork.actor].parts[gBattleWork.actorPart].data[0xC] = (&gGameWork.partAbility)[0xC];
    gBattleBots[gBattleWork.actor].parts[gBattleWork.actorPart].data[2] = 7;
    gBattleBots[gBattleWork.actor].parts[gBattleWork.actorPart].partId = gBattleWork.changePartId;
    ai_pick_bot_targets(gBattleWork.actor);
    battle_bot_select_part(gBattleWork.actor, gBattleWork.actorPart + 1);
    load_all_bot_part_sprites();
    iterate_bots_setup_battle_sprites();
    gBattleWork.step++;
}

// Copies the old and the new part names into the message buffer for the change message (messageId 0x2F).
void change_finish(void) {
    clear_battle_sprite_slot(0x21, 2);
    copy_bytes_short((const void *)gMedapartNames[0][gBattleWork.savedPart.partId * 4 + gBattleWork.actorPart],
                     gGameWork.textBuf, 0xF);
    copy_bytes_short((const void *)gMedapartNames[0][gBattleWork.changePartId * 4 + gBattleWork.actorPart],
                     gGameWork.textBuf + 0x14, 0xF);
    gBattleWork.messageId = 0x2F;
    gBattleWork.step++;
}
