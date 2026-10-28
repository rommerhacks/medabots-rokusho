// Effect sequences of the Defend and Heal skills (names from the ROM's skill list at 0x083BE4D4):
// action script opcodes 0x25/0x26 Recovery (30), 0x27/0x28 Repair (32), 0x29 Grap Trap / Shot Trap /
// Attack Clr / Team Form (10-12, 51), 0x2A Break Form (21), 0x2B Stability (22), 0x2C Force Bind (23),
// 0x2D Defence / Full Block / Half Block (27-29), 0x2E AutoRecover (31), 0x2F Reactivate (33).
// Each *_run clears unkB5 and calls entry [unkAA] of its *Steps table; it is one action script command
// (gActionScriptCommands -> script_op_*). Step 0 (*_begin) checks the time-out and whether the skill can work,
// the last step sets unkA6 (the result message) and unkB5. The skill id is part data[1].

#include "global.h"
#include "constants/sprites.h"

void recovery_run(void) {
    gBattleWork.stepDone = 0;
    gRecoverySteps[gBattleWork.step]();
}

void recovery_begin(void) {
    u32 timed_out;

    if (!part_broken_or_undamaged(gBattleWork.target, gBattleWork.targetPart)) {
        calc_battle_action_speed(gBattleWork.actor, gBattleWork.actorPart);
        apply_battle_bot_damage_reduction(gBattleWork.actor);
        timed_out = decrement_battle_timer_and_check_zero();
        if (timed_out) {
            gBattleWork.messageId = 0x1A;
            gBattleWork.step = 2;
            gBattleWork.stepResult = 1;
        } else {
            calc_battle_stat_ratio(gBattleWork.actor, gBattleWork.actorPart);
            side_add_action_point();
            gBattleWork.step++;
            gBattleWork.stepResult = timed_out;
        }
    } else {
        gBattleWork.messageId = 0x26;
        gBattleWork.step = 2;
        gBattleWork.stepResult = 1;
    }
}

void recovery_heal_run(void) {
    gBattleWork.stepDone = 0;
    gRecoveryHealSteps[gBattleWork.step]();
}

void recovery_heal_apply(void) {
    clear_battle_sprite_slot(0, 0x80);
    gBattleWork.damagePart = gBattleWork.targetPart;
    battle_calc_damage_split(gBattleWork.target, gBattleWork.damagePart, gBattleWork.amount);
    gBattleWork.step++;
}

void recovery_heal_spread(void) {
    u32 part;
    struct BattleWork *battle;

    if (gBattleBots[gBattleWork.actor].parts[(battle = &gBattleWork)->actorPart].data[7] && battle->overflowAmount &&
        (part = find_most_damaged_part(battle->target))) {
        part--;
        battle->damagePart = part;
        battle->targetPart = part;
        battle_calc_damage_split(battle->target, battle->damagePart, battle->overflowAmount);
        battle->step = 0xE;
    } else {
        battle->step++;
    }
}

void recovery_heal_repeat(void) {
    gBattleWork.step = 2;
}

void repair_run(void) {
    gBattleWork.stepDone = 0;
    gRepairSteps[gBattleWork.step]();
}

void repair_begin(void) {
    u32 timed_out;

    if (!gBattleBots[gBattleWork.target].parts[gBattleWork.targetPart].armor) {
        calc_battle_action_speed(gBattleWork.actor, gBattleWork.actorPart);
        apply_battle_bot_damage_reduction(gBattleWork.actor);
        timed_out = decrement_battle_timer_and_check_zero();
        if (timed_out) {
            gBattleWork.messageId = 0x1A;
            gBattleWork.step = 2;
            gBattleWork.stepResult = 1;
        } else {
            calc_battle_stat_ratio(gBattleWork.actor, gBattleWork.actorPart);
            side_add_action_point();
            gBattleWork.step++;
            gBattleWork.stepResult = timed_out;
        }
    } else {
        gBattleWork.messageId = 0x27;
        gBattleWork.step = 2;
        gBattleWork.stepResult = 1;
    }
}

void repair_apply_run(void) {
    gBattleWork.stepDone = 0;
    gRepairApplySteps[gBattleWork.step]();
}

void repair_apply(void) {
    clear_battle_sprite_slot(0, 0x80);
    gBattleWork.damagePart = gBattleWork.targetPart;
    battle_set_damage_display(gBattleWork.target, gBattleWork.damagePart, gBattleWork.amount);
    gBattleWork.step++;
}

void repair_spread(void) {
    u32 part;
    struct BattleWork *battle = &gBattleWork;

    bot_restore_leg_stats(battle->target);
    if (gBattleBots[battle->actor].parts[battle->actorPart].data[7] && battle->overflowAmount &&
        (part = find_random_broken_part(battle->target))) {
        part--;
        battle->damagePart = part;
        battle->targetPart = part;
        battle_set_damage_display(battle->target, battle->damagePart, battle->overflowAmount);
        battle->step = 0xF;
    } else {
        battle->step++;
    }
}

void repair_redraw_bot(void) {
    armor_heal_step(&gBattleWork.appliedAmount, gBattleWork.target, gBattleWork.targetPart);
    if (gBattleWork.actorSideFlags & 2) {
        get_active_bot_part_index_and_load_values(0);
        draw_medabot_sprite(0, gBattleWork.partIds[0], gBattleWork.partIds[1], gBattleWork.partIds[2],
                            gBattleWork.partIds[3], (s16)gBattleWork.closeupLeftX, (s16)gBattleWork.closeupLeftY,
                            gBattleWork.battlefieldParams[3] + 2, 4, 0, 2, 0, gBattleWork.closeupPoseBase[0]);
        draw_medabot_sprite(0, gBattleWork.partIds[0], gBattleWork.partIds[1], gBattleWork.partIds[2],
                            gBattleWork.partIds[3], (s16)gBattleWork.closeupLeftX, (s16)gBattleWork.closeupLeftY,
                            gBattleWork.battlefieldParams[3] + 2, 4, 0, 1, 0, gBattleWork.closeupPoseBase[0]);
    } else {
        get_active_bot_part_index_and_load_values(1);
        draw_medabot_sprite(1, gBattleWork.partIds[0], gBattleWork.partIds[1], gBattleWork.partIds[2],
                            gBattleWork.partIds[3], (s16)gBattleWork.closeupRightX, (s16)gBattleWork.closeupRightY,
                            gBattleWork.battlefieldParams[3] + 2, 8, 1, 2, 1, gBattleWork.closeupPoseBase[1]);
        draw_medabot_sprite(1, gBattleWork.partIds[0], gBattleWork.partIds[1], gBattleWork.partIds[2],
                            gBattleWork.partIds[3], (s16)gBattleWork.closeupRightX, (s16)gBattleWork.closeupRightY,
                            gBattleWork.battlefieldParams[3] + 2, 8, 1, 1, 1, gBattleWork.closeupPoseBase[1]);
    }
    gBattleWork.step++;
}

void repair_repeat(void) {
    gBattleWork.step = 2;
}

void trap_run(void) {
    gBattleWork.stepDone = 0;
    gTrapSteps[gBattleWork.step]();
}

void trap_begin(void) {
    u32 timed_out;

    calc_battle_action_speed(gBattleWork.actor, gBattleWork.actorPart);
    apply_battle_bot_damage_reduction(gBattleWork.actor);
    timed_out = decrement_battle_timer_and_check_zero();
    if (timed_out) {
        gBattleWork.messageId = 0x1A;
        gBattleWork.step++;
        return;
    }
    calc_battle_stat_ratio(gBattleWork.actor, gBattleWork.actorPart);
    side_add_action_point();
    switch (gBattleBots[gBattleWork.actor].parts[gBattleWork.actorPart].data[1]) {
    case 0xA:
        gBattleWork.unk51 = timed_out;
        break;
    case 0xB:
        gBattleWork.unk51 = 1;
        break;
    case 0xC:
        gBattleWork.unk51 = 2;
        break;
    default:
        gBattleWork.unk51 = 3;
        break;
    }
    gBattleWork.unk52 = gBattleBots[gBattleWork.actor].parts[gBattleWork.actorPart].data[1];
    gBattleWork.step = 4;
}

// Steps 4-7 of most skill sequences (also the Interrupt skills): a sprite hops over the user, then a
// burst animation plays. guess: the "skill cast" effect.
void skill_cast_hop_spawn(void) {
    lz_decompress_dispatch(gSkillCastHopTiles, (void *)0x06015800);
    CpuFastSet(gSkillCastHopPalette, (void *)0x050002E0, 8);
    gSpriteEntries[0x21].flags =
        SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_AFFINE | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[0x21].frame_table = 0;
    gSpriteEntries[0x21].x = gSpriteEntries[0x5D + gBattleWork.actor * 4].x;
    gSpriteEntries[0x21].y = gSpriteEntries[0x5D + gBattleWork.actor * 4].y - 4;
    gSpriteEntries[0x21].palette = 7;
    gSpriteEntries[0x21].order = 0xF0;
    gSpriteEntries[0x21].scale_x = 0x40;
    gSpriteEntries[0x21].scale_y = 0x40;
    gSpriteEntries[0x21].angle = 0;
    gSpriteEntries[0x21].frame = 0x4100;
    gSpriteEntries[0x21].unk23 = 0;
    gSpriteEntries[0x21].unk27 = 0;
    play_sound_effect(0x29);
    gBattleWork.step++;
}

void skill_cast_hop(void) {
    sprite_hop_step(0x21);
    if (gSpriteEntries[0x21].unk27 == 0x20) {
        gSpriteEntries[0x21].flags &= ~SPRITE_FLAG_AFFINE;
        gSpriteEntries[0x21].angle = 0;
        gBattleWork.step++;
        return;
    }
    if (!(gBattleWork.actorSideFlags & 1))
        gSpriteEntries[0x21].angle = (gSpriteEntries[0x21].angle + 0x20) & 0x3FF;
    else
        gSpriteEntries[0x21].angle = (gSpriteEntries[0x21].angle - 0x20) & 0x3FF;
    if (!(gSpriteEntries[0x21].unk27 & 1)) {
        if (!(gBattleWork.actorSideFlags & 1))
            gSpriteEntries[0x21].x++;
        else
            gSpriteEntries[0x21].x--;
    }
    gSpriteEntries[0x21].unk27++;
}

void skill_cast_flash_init(void) {
    lz_decompress_dispatch(gPartBreakBurstTiles, (void *)0x06014800);
    CpuFastSet(gPartBreakBurstPalette, (void *)0x050002E0, 8);
    battle_sprite_anim_init(gBattleSpriteAnimScripts[0x23], 0x21);
    gBattleWork.step++;
}

void skill_cast_flash_wait(void) {
    process_sprite_anim_commands(gBattleSpriteAnimScripts[0x23], 0x21);
    if (gSpriteEntries[0x21].unk22 == 0xFF)
        gBattleWork.step++;
}

void trap_sprite_spawn(void) {
    switch (gBattleWork.unk51) {
    case 0:
        lz_decompress_dispatch(gGrapTrapTiles, (void *)0x06014800);
        CpuFastSet(gGrapTrapPalette, (void *)0x050002E0, 8);
        gSpriteEntries[0x21].y = 0x3C;
        battle_sprite_anim_init(gBattleSpriteAnimScripts[0x19], 0x21);
        break;
    case 1:
        lz_decompress_dispatch(gShotTrapTiles, (void *)0x06014800);
        CpuFastSet(gShotTrapPalette, (void *)0x050002E0, 8);
        gSpriteEntries[0x21].y = 0x3C;
        battle_sprite_anim_init(gBattleSpriteAnimScripts[0x1A], 0x21);
        break;
    case 2:
        lz_decompress_dispatch(gAttackClrTrapTiles, (void *)0x06014800);
        CpuFastSet(gAttackClrTrapPalette, (void *)0x050002E0, 8);
        gSpriteEntries[0x21].y = 0x3C;
        gSpriteEntries[0x21].frame = 0xD00;
        break;
    case 3:
        lz_decompress_dispatch(gTeamAttackTurretTilesLz, (void *)0x06014800);
        CpuFastSet(gTeamAttackTurretPalette, (void *)0x050002E0, 8);
        battle_sprite_anim_init(gBattleSpriteAnimScripts[0x38], 0x21);
        break;
    }
    gSpriteEntries[0x21].flags |= SPRITE_FLAG_AFFINE | SPRITE_FLAG_DOUBLE_SIZE;
    gSpriteEntries[0x21].scale_y = 0x40;
    gSpriteEntries[0x21].scale_x = 8;
    if (gBattleWork.actorSideFlags & 1) {
        gSpriteEntries[0x21].flags |= SPRITE_FLAG_HFLIP;
        gSpriteEntries[0x21].x--;
    }
    gBattleWork.step++;
}

void trap_sprite_grow(void) {
    if ((gSpriteEntries[0x21].scale_x += 8) == 0x40) {
        if (gBattleWork.unk51 == 3)
            gGameWork.stepTimer = 1;
        else
            gGameWork.stepTimer = 0x3C;
        gBattleWork.step++;
    }
}

void trap_sprite_hold(void) {
    gGameWork.stepTimer--;
    if (gGameWork.skipBotSetup == 0 && (*(u8 *)&gRepeatKeys & 1))
        gGameWork.stepTimer = 0;
    if (gGameWork.stepTimer == 0) {
        switch (gBattleWork.unk51) {
        case 0:
        case 1:
        case 2:
            gSpriteEntries[0x21].unk27 = 0;
            gBattleWork.step++;
            break;
        case 3:
            play_sound_effect(0x52);
            gBattleWork.step = 0x20;
            break;
        }
    }
}

void trap_sprite_slide(void) {
    if (gSpriteEntries[0x21].unk27 == 0x10) {
        gBattleWork.step++;
        return;
    }
    if (!(gBattleWork.actorSideFlags & 1))
        gSpriteEntries[0x21].x++;
    else
        gSpriteEntries[0x21].x--;
    gSpriteEntries[0x21].unk27++;
}

// The side already holds this trap: pulse the sprite and add to it; Attack Clr skips the pulse.
void trap_check_existing(void) {
    if (gBattleWork.traps[gBattleWork.otherSide].active &&
        gBattleWork.traps[gBattleWork.otherSide].skill == gBattleWork.unk52) {
        gSpriteEntries[0x21].unk27 = 0;
        gBattleWork.step++;
    } else if (gBattleWork.unk51 == 2) {
        gBattleWork.step = 0x14;
    } else {
        play_sound_effect(0x3E);
        gBattleWork.step = 0xE;
    }
}

void trap_sprite_pulse(void) {
    if (gSpriteEntries[0x21].unk27 == 0x10) {
        if (gBattleWork.unk51 == 2) {
            gBattleWork.step = 0x14;
        } else {
            play_sound_effect(0x3E);
            gBattleWork.step = 0xE;
        }
        return;
    }
    if (gSpriteEntries[0x21].unk27 < 8)
        gSpriteEntries[0x21].scale_x += 8;
    else
        gSpriteEntries[0x21].scale_x -= 8;
    gSpriteEntries[0x21].unk27++;
}

void trap_sprite_shrink(void) {
    if (gSpriteEntries[0x21].scale_x == 8) {
        clear_battle_sprite_slot(0x21, 1);
        gBattleWork.step++;
    } else {
        gSpriteEntries[0x21].scale_x -= 8;
    }
}

// unk28[side]: the side's trap / Team Form record (active, skill kind, power); a repeat stacks half.
void trap_apply(void) {
    if (gBattleWork.traps[gBattleWork.otherSide].active &&
        gBattleWork.traps[gBattleWork.otherSide].skill == gBattleWork.unk52) {
        gBattleWork.unk53 = 1;
        if (gBattleWork.unk51 != 2) {
            add_u8_capped(&gBattleWork.traps[gBattleWork.otherSide].durability, gBattleWork.success >> 1, 0xFF);
            add_u8_capped(&gBattleWork.traps[gBattleWork.otherSide].power,
                          (gBattleWork.amount + gBattleBots[gBattleWork.actor].trapBonus) >> 1, 0xFF);
            gBattleWork.step++;
        } else {
            gBattleWork.traps[gBattleWork.otherSide].durability++;
            gBattleWork.step++;
        }
    } else {
        gBattleWork.unk53 = 0;
        gBattleWork.traps[gBattleWork.otherSide].active = 1;
        gBattleWork.traps[gBattleWork.otherSide].skill = gBattleWork.unk52;
        gBattleWork.traps[gBattleWork.otherSide].durability = 0;
        gBattleWork.traps[gBattleWork.otherSide].power = 0;
        if (gBattleWork.unk51 != 2) {
            add_u8_capped(&gBattleWork.traps[gBattleWork.otherSide].durability, gBattleWork.success, 0xFF);
            add_u8_capped(&gBattleWork.traps[gBattleWork.otherSide].power,
                          gBattleWork.amount + gBattleBots[gBattleWork.actor].trapBonus, 0xFF);
        } else {
            gBattleWork.traps[gBattleWork.otherSide].durability++;
        }
        gBattleWork.step++;
    }
}

void trap_finish(void) {
    switch (gBattleWork.unk51) {
    case 0:
        gBattleWork.messageId = 0x1E;
        break;
    case 1:
        gBattleWork.messageId = 0x1F;
        break;
    case 2:
        gBattleWork.messageId = 0x20;
        break;
    case 3:
        gBattleWork.messageId = 0x21;
        break;
    }
    if (gBattleWork.unk53)
        gBattleWork.messageId = 0x71;
    gBattleWork.step++;
}

void trap_sprite_fly_init(void) {
    gSpriteEntries[0x21].unk24 = 4;
    gSpriteEntries[0x21].unk25 = 0;
    gSpriteEntries[0x21].unk30 = 0;
    play_sound_effect(0x40);
    gBattleWork.step++;
}

void trap_sprite_fly(void) {
    if (update_sprite_deceleration(0x21, -0x40, -0x30)) {
        clear_battle_sprite_slot(0x21, 1);
        gBattleWork.step++;
    }
}

void team_form_anim_wait(void) {
    process_sprite_anim_commands(gBattleSpriteAnimScripts[0x38], 0x21);
    if (gSpriteEntries[0x21].unk22 == 0xFF) {
        gGameWork.stepTimer = 0x3C;
        gBattleWork.step++;
    }
}

void team_form_split(void) {
    struct SpriteEntry *spr;

    gGameWork.stepTimer--;
    if (gGameWork.skipBotSetup == 0 && (*(u8 *)&gRepeatKeys & 1))
        gGameWork.stepTimer = 0;
    if (gGameWork.stepTimer == 0) {
        spr = &gSpriteEntries[0x21];
        memcpy_bytes_0803F63C(spr, spr + 1, 0x40);
        memcpy_bytes_0803F63C(spr, spr + 2, 0x40);
        spr[0].unk32 = 0x58;
        spr[0].unk24 = 6;
        spr[1].unk32 = 0x40;
        spr[1].unk24 = 6;
        spr[2].unk32 = 0x28;
        spr[2].unk24 = 6;
        if (!(gBattleWork.actorSideFlags & 1))
            spr[2].unk30 = spr[1].unk30 = spr[0].unk30 = 0x88;
        else
            spr[2].unk30 = spr[1].unk30 = spr[0].unk30 = 0x68;
        gBattleWork.step++;
    }
}

void team_form_move(void) {
    u32 first_arrived = move_sprite_toward_target(0x21);
    u32 n = (first_arrived | -first_arrived) >> 31;
    if (move_sprite_toward_target(0x22))
        n++;
    if (move_sprite_toward_target(0x23))
        n++;
    if (n == 3)
        gBattleWork.step++;
}

void team_form_check_existing(void) {
    if (gBattleWork.traps[gBattleWork.otherSide].active &&
        gBattleWork.traps[gBattleWork.otherSide].skill == gBattleWork.unk52) {
        gSpriteEntries[0x21].unk27 = 0;
        gBattleWork.step++;
    } else {
        play_sound_effect(0x3E);
        gBattleWork.step = 0x25;
    }
}

void team_form_pulse(void) {
    if (gSpriteEntries[0x21].unk27 == 0x10) {
        play_sound_effect(0x3E);
        gBattleWork.step++;
        return;
    }
    if (gSpriteEntries[0x21].unk27 < 8) {
        gSpriteEntries[0x21].scale_x += 8;
        gSpriteEntries[0x22].scale_x += 8;
        gSpriteEntries[0x23].scale_x += 8;
    } else {
        gSpriteEntries[0x21].scale_x -= 8;
        gSpriteEntries[0x22].scale_x -= 8;
        gSpriteEntries[0x23].scale_x -= 8;
    }
    gSpriteEntries[0x21].unk27++;
}

void team_form_shrink(void) {
    if (gSpriteEntries[0x21].scale_x == 8) {
        clear_battle_sprite_slot(0x21, 3);
        gBattleWork.step++;
    } else {
        gSpriteEntries[0x21].scale_x -= 8;
        gSpriteEntries[0x22].scale_x -= 8;
        gSpriteEntries[0x23].scale_x -= 8;
    }
}

void break_form_run(void) {
    gBattleWork.stepDone = 0;
    gBreakFormSteps[gBattleWork.step]();
}

void break_form_begin(void) {
    calc_battle_action_speed(gBattleWork.actor, gBattleWork.actorPart);
    apply_battle_bot_damage_reduction(gBattleWork.actor);
    if (decrement_battle_timer_and_check_zero()) {
        gBattleWork.messageId = 0x1A;
        gBattleWork.step++;
    } else if (!gBattleWork.traps[gBattleWork.actorSide].active) {
        gBattleWork.messageId = 0x24;
        gBattleWork.step++;
    } else {
        side_add_action_point();
        gBattleWork.step = 4;
    }
}

void break_form_sprite_spawn(void) {
    lz_decompress_dispatch(gBreakFormTilesLz, (void *)0x06014800);
    CpuFastSet(gBreakFormPalette, (void *)0x050002E0, 8);
    battle_sprite_anim_init(gBattleSpriteAnimScripts[0x39], 0x21);
    if (gBattleWork.actorSideFlags & 1)
        gSpriteEntries[0x21].flags |= SPRITE_FLAG_HFLIP;
    gBattleWork.step++;
}

void break_form_anim_wait(void) {
    process_sprite_anim_commands(gBattleSpriteAnimScripts[0x39], 0x21);
    if (gSpriteEntries[0x21].unk22 == 0xFF) {
        battle_sprite_anim_init(gBattleSpriteAnimScripts[0x3B], 0x21);
        gGameWork.stepTimer = 0x3C;
        gBattleWork.step++;
    }
}

void break_form_hold(void) {
    process_sprite_anim_commands(gBattleSpriteAnimScripts[0x3B], 0x21);
    gGameWork.stepTimer--;
    if (gGameWork.skipBotSetup == 0 && (*(u8 *)&gRepeatKeys & 1))
        gGameWork.stepTimer = 0;
    if (gGameWork.stepTimer == 0)
        gBattleWork.step++;
}

void break_form_split(void) {
    struct SpriteEntry *spr;

    process_sprite_anim_commands(gBattleSpriteAnimScripts[0x3B], 0x21);
    spr = &gSpriteEntries[0x21];
    memcpy_bytes_0803F63C(spr, spr + 1, 0x40);
    memcpy_bytes_0803F63C(spr, spr + 2, 0x40);
    spr[0].unk32 = 0x58;
    spr[0].unk24 = 6;
    spr[1].unk32 = 0x40;
    spr[1].unk24 = 6;
    spr[2].unk32 = 0x28;
    spr[2].unk24 = 6;
    if (gBattleWork.actorSideFlags & 1)
        spr[2].unk30 = spr[1].unk30 = spr[0].unk30 = 0x88;
    else
        spr[2].unk30 = spr[1].unk30 = spr[0].unk30 = 0x68;
    gBattleWork.step++;
}

void break_form_move(void) {
    u32 first_arrived, n;

    process_sprite_anim_commands(gBattleSpriteAnimScripts[0x3B], 0x21);
    process_sprite_anim_commands(gBattleSpriteAnimScripts[0x3B], 0x22);
    process_sprite_anim_commands(gBattleSpriteAnimScripts[0x3B], 0x23);
    first_arrived = move_sprite_toward_target(0x21);
    n = (first_arrived | -first_arrived) >> 31;
    if (move_sprite_toward_target(0x22))
        n++;
    if (move_sprite_toward_target(0x23))
        n++;
    if (n == 3) {
        battle_sprite_anim_init(gBattleSpriteAnimScripts[0x3A], 0x21);
        battle_sprite_anim_init(gBattleSpriteAnimScripts[0x3A], 0x22);
        battle_sprite_anim_init(gBattleSpriteAnimScripts[0x3A], 0x23);
        gBattleWork.step++;
    }
}

void break_form_hit_wait(void) {
    process_sprite_anim_commands(gBattleSpriteAnimScripts[0x3A], 0x21);
    process_sprite_anim_commands(gBattleSpriteAnimScripts[0x3A], 0x22);
    process_sprite_anim_commands(gBattleSpriteAnimScripts[0x3A], 0x23);
    if (gSpriteEntries[0x21].unk22 == 0xFF) {
        disable_sprites(0x21, 3);
        gGameWork.stepTimer = 0x3C;
        gBattleWork.step++;
    }
}

void break_form_shatter_init(void) {
    u32 i;

    lz_decompress_dispatch(gPartBreakBurstTiles, (void *)0x06014800);
    CpuFastSet(gPartBreakBurstPalette, (void *)0x050002E0, 8);
    battle_sprite_anim_init(gBattleSpriteAnimScripts[0x23], 0x21);
    battle_sprite_anim_init(gBattleSpriteAnimScripts[0x23], 0x22);
    battle_sprite_anim_init(gBattleSpriteAnimScripts[0x23], 0x23);
    enable_sprites(0x21, 3);
    for (i = 0; i < 6; i++) {
        if (gBattleBots[i].teamState) {
            gSpriteEntries[0x5A + i * 4].unk23 = 0;
            gSpriteEntries[0x5B + i * 4].unk23 = 0;
            gSpriteEntries[0x5C + i * 4].unk23 = 0;
            gSpriteEntries[0x5D + i * 4].unk23 = 0;
        }
    }
    gGameWork.stepTimer = 0;
    gBattleWork.step++;
}

void break_form_shatter(void) {
    u32 i;

    gGameWork.stepTimer++;
    bg3_shake_step(gGameWork.stepTimer);
    for (i = 0; i < 6; i++) {
        if (gBattleBots[i].teamState) {
            advance_sprite_anim_frame(0x5A + i * 4, 0);
            advance_sprite_anim_frame(0x5B + i * 4, 0);
            advance_sprite_anim_frame(0x5C + i * 4, 0);
            advance_sprite_anim_frame(0x5D + i * 4, 0);
        }
    }
    process_sprite_anim_commands(gBattleSpriteAnimScripts[0x23], 0x21);
    process_sprite_anim_commands(gBattleSpriteAnimScripts[0x23], 0x22);
    process_sprite_anim_commands(gBattleSpriteAnimScripts[0x23], 0x23);
    if (gSpriteEntries[0x21].unk22 == 0xFF) {
        for (i = 0; i < 6; i++) {
            if (gBattleBots[i].teamState) {
                gSpriteEntries[0x5A + i * 4].unk23 = 0;
                gSpriteEntries[0x5B + i * 4].unk23 = 0;
                gSpriteEntries[0x5C + i * 4].unk23 = 0;
                gSpriteEntries[0x5D + i * 4].unk23 = 0;
            }
        }
        gBg3Scroll.y = 0;
        clear_battle_sprite_slot(0x21, 3);
        gBattleWork.step++;
    }
}

void break_form_apply(void) {
    gBattleWork.traps[gBattleWork.actorSide].active = 0;
    gBattleWork.traps[gBattleWork.actorSide].skill = 0;
    gBattleWork.traps[gBattleWork.actorSide].durability = 0;
    gBattleWork.traps[gBattleWork.actorSide].power = 0;
    gBattleWork.step++;
}

void break_form_finish(void) {
    gBattleWork.messageId = 0x25;
    gBattleWork.step++;
}

void stability_run(void) {
    gBattleWork.stepDone = 0;
    gStabilitySteps[gBattleWork.step]();
}

void stability_begin(void) {
    calc_battle_action_speed(gBattleWork.actor, gBattleWork.actorPart);
    apply_battle_bot_damage_reduction(gBattleWork.actor);
    if (decrement_battle_timer_and_check_zero()) {
        gBattleWork.messageId = 0x1A;
        gBattleWork.step++;
    } else if (!gBattleBots[gBattleWork.target].statusType) {
        gBattleWork.messageId = 0x70;
        gBattleWork.step++;
    } else {
        side_add_action_point();
        gBattleWork.step = 4;
    }
}

void stability_sprite_spawn(void) {
    lz_decompress_dispatch(gStabilitySparkleTiles, (void *)0x06014800);
    CpuFastSet(gStabilitySparklePalette, (void *)0x050002E0, 8);
    if (gBattleWork.actorSideFlags & 1)
        gSpriteEntries[0x21].flags |= SPRITE_FLAG_HFLIP;
    gSpriteEntries[0x21].flags |= SPRITE_FLAG_AFFINE;
    gSpriteEntries[0x21].scale_x = 0x40;
    gSpriteEntries[0x21].scale_y = 0x40;
    gSpriteEntries[0x21].angle = 0;
    gSpriteEntries[0x21].unk30 = gSpriteEntries[gBattleWork.target * 4 + 0x5D].x;
    gSpriteEntries[0x21].unk32 = gSpriteEntries[gBattleWork.target * 4 + 0x5D].y - 4;
    gSpriteEntries[0x21].unk24 = 6;
    battle_sprite_anim_init(gBattleSpriteAnimScripts[0x3C], 0x21);
    gGameWork.stepTimer = 0x3C;
    gBattleWork.step++;
}

void stability_sprite_fly(void) {
    if (!(gBattleWork.actorSideFlags & 1))
        gSpriteEntries[0x21].angle = (gSpriteEntries[0x21].angle - 0x40) & 0x3FF;
    else
        gSpriteEntries[0x21].angle = (gSpriteEntries[0x21].angle + 0x40) & 0x3FF;
    if (move_sprite_toward_target(0x21)) {
        gSpriteEntries[0x21].flags &= ~SPRITE_FLAG_AFFINE;
        gSpriteEntries[0x21].angle = 0;
        gBattleWork.step++;
    }
}

// Stability cures the target's negative status (unkC9-unkCC, set by Impair, Confusion...).
void stability_apply(void) {
    gBattleBots[gBattleWork.target].statusType = 0;
    gBattleBots[gBattleWork.target].statusPart = 0;
    gBattleBots[gBattleWork.target].statusTimer = 0;
    gBattleBots[gBattleWork.target].statusAmount = 0;
    gSpriteEntries[gBattleWork.target * 3 + 0x47].flags |=
        SPRITE_FLAG_ENABLED | SPRITE_FLAG_AFFINE | SPRITE_FLAG_DOUBLE_SIZE;
    gSpriteEntries[gBattleWork.target * 3 + 0x47].scale_y = 0x40;
    gSpriteEntries[gBattleWork.target * 3 + 0x47].scale_x = 0x40;
    play_sound_effect(0x37);
    gBattleWork.step++;
}

void stability_status_icon_fade(void) {
    if (gSpriteEntries[gBattleWork.target * 3 + 0x47].scale_x != 4) {
        gSpriteEntries[gBattleWork.target * 3 + 0x47].flags |= SPRITE_FLAG_ENABLED;
        gSpriteEntries[gBattleWork.target * 3 + 0x47].scale_y += 4;
        gSpriteEntries[gBattleWork.target * 3 + 0x47].scale_x -= 4;
    }
    process_sprite_anim_commands(gBattleSpriteAnimScripts[0x3C], 0x21);
    if (gSpriteEntries[0x21].unk22 == 0xFF) {
        clear_battle_sprite_slot(0x21, 1);
        clear_battle_sprite_slot(gBattleWork.target * 3 + 0x47, 1);
        gBattleWork.step++;
    }
}

void stability_finish(void) {
    gBattleWork.messageId = 0x23;
    gBattleWork.step++;
}

void force_bind_run(void) {
    gBattleWork.stepDone = 0;
    gForceBindSteps[gBattleWork.step]();
}

void force_bind_begin(void) {
    calc_battle_action_speed(gBattleWork.actor, gBattleWork.actorPart);
    apply_battle_bot_damage_reduction(gBattleWork.actor);
    if (decrement_battle_timer_and_check_zero()) {
        gBattleWork.messageId = 0x1A;
        gBattleWork.step++;
    } else {
        side_add_action_point();
        gBattleWork.step = 4;
    }
}

void force_bind_orbs_spawn(void) {
    u32 i;

    lz_decompress_dispatch(gForceBindOrbTilesLz, (void *)0x06014800);
    CpuFastSet(gForceBindOrbPalette, (void *)0x050002E0, 8);
    for (i = 0; i < 4; i++) {
        gSpriteEntries[0x21 + i].flags = SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) |
                                         SPRITE_FLAG_AFFINE | SPRITE_FLAG_PART_PALETTE;
        gSpriteEntries[0x21 + i].frame_table = 0;
        gSpriteEntries[0x21 + i].x = gSpriteEntries[gBattleWork.actor * 4 + 0x5D].x;
        gSpriteEntries[0x21 + i].y = gSpriteEntries[gBattleWork.actor * 4 + 0x5D].y - 4;
        gSpriteEntries[0x21 + i].palette = 7;
        gSpriteEntries[0x21 + i].order = 0xF0;
        gSpriteEntries[0x21 + i].scale_x = 0x40;
        gSpriteEntries[0x21 + i].scale_y = 0x40;
        gSpriteEntries[0x21 + i].unk2B = 0;
        gSpriteEntries[0x21 + i].unk2C = i << 6;
        gSpriteEntries[0x21 + i].unk2D = 0;
        battle_sprite_anim_init(gBattleSpriteAnimScripts[0x3D], 0x21 + i);
    }
    play_sound_effect(0x5C);
    gBattleWork.step++;
}

void force_bind_orbs_spin(void) {
    u32 i;
    struct Coords16 pos;

    for (i = 0; i < 4; i++) {
        process_sprite_anim_commands(gBattleSpriteAnimScripts[0x3D], 0x21 + i);
        pos = calc_polar_to_screen_coords(gSpriteEntries[0x21 + i].unk2C, gSpriteEntries[0x21 + i].unk2B,
                                          gSpriteEntries[gBattleWork.actor * 4 + 0x5D].x,
                                          gSpriteEntries[gBattleWork.actor * 4 + 0x5D].y - 4);
        gSpriteEntries[0x21 + i].x = pos.x;
        gSpriteEntries[0x21 + i].y = pos.y;
        gSpriteEntries[0x21 + i].unk2C += 4;
        gSpriteEntries[0x21 + i].unk2D++;
        if (!(gSpriteEntries[0x21 + i].unk2D & 3))
            gSpriteEntries[0x21 + i].unk2B++;
        if (gSpriteEntries[0x21 + i].unk2D > 0xB4) {
            gSpriteEntries[0x21 + i].scale_x -= 4;
            gSpriteEntries[0x21 + i].scale_y -= 4;
        }
    }
    if (gSpriteEntries[0x21].scale_y == 4) {
        clear_battle_sprite_slot(0x21, 4);
        gBattleWork.step++;
    }
}

// Each use toggles Force Bind on (message 0x72) or off (0x73).
void force_bind_toggle(void) {
    if (!gBattleWork.medaforceBlocked) {
        gBattleWork.messageId = 0x72;
        gBattleWork.medaforceBlocked = 1;
    } else {
        gBattleWork.messageId = 0x73;
        gBattleWork.medaforceBlocked = 0;
    }
    gBattleWork.step++;
}

void defence_run(void) {
    gBattleWork.stepDone = 0;
    gDefenceSteps[gBattleWork.step]();
}

void defence_begin(void) {
    u32 timed_out;

    calc_battle_action_speed(gBattleWork.actor, gBattleWork.actorPart);
    apply_battle_bot_damage_reduction(gBattleWork.actor);
    timed_out = decrement_battle_timer_and_check_zero();
    if (timed_out) {
        gBattleWork.messageId = 0x1A;
        gBattleWork.step++;
    } else {
        side_add_action_point();
        switch (gBattleBots[gBattleWork.actor].parts[gBattleWork.actorPart].data[1]) {
        case 0x1B:
            gBattleWork.unk51 = timed_out;
            break;
        case 0x1C:
            gBattleWork.unk51 = 1;
            break;
        default:
            gBattleWork.unk51 = 2;
            break;
        }
        calc_battle_stat_ratio(gBattleWork.actor, gBattleWork.actorPart);
        gBattleWork.step = 4;
    }
}

void defence_shields_spawn(void) {
    switch (gBattleWork.unk51) {
    case 0:
        lz_decompress_dispatch(gDefenceShieldTiles, (void *)0x06014800);
        CpuFastSet(gDefenceShieldPalette, (void *)0x050002E0, 8);
        break;
    case 1:
        lz_decompress_dispatch(gFullBlockShieldTiles, (void *)0x06014800);
        CpuFastSet(gFullBlockShieldPalette, (void *)0x050002E0, 8);
        break;
    default:
        lz_decompress_dispatch(gHalfBlockShieldTiles, (void *)0x06014800);
        CpuFastSet(gHalfBlockShieldPalette, (void *)0x050002E0, 8);
        break;
    }
    gSpriteEntries[0x21].flags = SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_AFFINE |
                                 SPRITE_FLAG_DOUBLE_SIZE | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[0x21].frame_table = 0;
    gSpriteEntries[0x21].x = gSpriteEntries[gBattleWork.actor * 4 + 0x5D].x - 0x20;
    gSpriteEntries[0x21].y = gSpriteEntries[gBattleWork.actor * 4 + 0x5D].y - 4;
    gSpriteEntries[0x21].palette = 7;
    gSpriteEntries[0x21].order = 0xF0;
    gSpriteEntries[0x21].scale_x = 0x80;
    gSpriteEntries[0x21].scale_y = 0x80;
    gSpriteEntries[0x21].unk2B = 0x1C;
    gSpriteEntries[0x21].unk2C = 0;
    gSpriteEntries[0x21].unk2D = 0;
    battle_sprite_anim_init(gBattleSpriteAnimScripts[0x1C], 0x21);
    gSpriteEntries[0x22].flags = SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_AFFINE |
                                 SPRITE_FLAG_DOUBLE_SIZE | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[0x22].frame_table = 0;
    gSpriteEntries[0x22].x = gSpriteEntries[gBattleWork.actor * 4 + 0x5D].x + 0x20;
    gSpriteEntries[0x22].y = gSpriteEntries[gBattleWork.actor * 4 + 0x5D].y - 4;
    gSpriteEntries[0x22].palette = 7;
    gSpriteEntries[0x22].order = 0xF0;
    gSpriteEntries[0x22].scale_x = 0x80;
    gSpriteEntries[0x22].scale_y = 0x80;
    gSpriteEntries[0x22].unk2B = 0x1C;
    gSpriteEntries[0x22].unk2C = 0x80;
    gSpriteEntries[0x22].unk2D = 0;
    battle_sprite_anim_init(gBattleSpriteAnimScripts[0x1C], 0x22);
    play_sound_effect(0x33);
    gBattleWork.step++;
}

void defence_shields_spin(void) {
    u32 i;
    struct Coords16 pos;

    for (i = 0; i < 2; i++) {
        pos = calc_polar_to_screen_coords(gSpriteEntries[0x21 + i].unk2C, gSpriteEntries[0x21 + i].unk2B,
                                          gSpriteEntries[gBattleWork.actor * 4 + 0x5D].x,
                                          gSpriteEntries[gBattleWork.actor * 4 + 0x5D].y - 4);
        gSpriteEntries[0x21 + i].x = pos.x;
        gSpriteEntries[0x21 + i].y = pos.y;
        gSpriteEntries[0x21 + i].unk2C += 8;
        gSpriteEntries[0x21 + i].unk2D++;
        if (!(gSpriteEntries[0x21 + i].unk2D & 3))
            gSpriteEntries[0x21 + i].unk2B--;
        if (gSpriteEntries[0x21 + i].scale_x != 0x40) {
            gSpriteEntries[0x21 + i].scale_x--;
            gSpriteEntries[0x21 + i].scale_y--;
        }
    }
    if (gSpriteEntries[0x21].unk2B == 0) {
        play_sound_effect(0x30);
        clear_battle_sprite_slot(0x22, 1);
        gBattleWork.step++;
    }
}

void defence_shield_anim_wait(void) {
    process_sprite_anim_commands(gBattleSpriteAnimScripts[0x1C], 0x21);
    if (gSpriteEntries[0x21].unk22 == 0xFF) {
        clear_battle_sprite_slot(0x21, 1);
        gBattleWork.step++;
    }
}

// Marks the user as guarding (unkBD bit 3) with this skill (Defence, Full Block or Half Block).
void defence_apply(void) {
    gBattleBots[gBattleWork.actor].stateFlags |= 8;
    gBattleBots[gBattleWork.actor].lastActionSkill =
        gBattleBots[gBattleWork.actor].parts[gBattleWork.actorPart].data[1];
    gBattleBots[gBattleWork.actor].defence = 0;
    add_u8_capped(&gBattleBots[gBattleWork.actor].moveSubpixel + 1, gBattleWork.amount, 0xFF);
    gBattleWork.step++;
}

void defence_finish(void) {
    gBattleWork.messageId = 0x1B;
    gBattleWork.step++;
}

void autorecover_run(void) {
    gBattleWork.stepDone = 0;
    gAutoRecoverSteps[gBattleWork.step]();
}

void autorecover_begin(void) {
    calc_battle_action_speed(gBattleWork.actor, gBattleWork.actorPart);
    apply_battle_bot_damage_reduction(gBattleWork.actor);
    if (decrement_battle_timer_and_check_zero()) {
        gBattleWork.messageId = 0x1A;
        gBattleWork.step++;
    } else if (!battle_bot_lacks_stability(gBattleWork.target)) {
        gBattleWork.messageId = 0x39;
        gBattleWork.step++;
    } else {
        side_add_action_point();
        calc_battle_stat_ratio(gBattleWork.actor, gBattleWork.actorPart);
        gBattleWork.step = 4;
    }
}

void autorecover_orb_spawn(void) {
    lz_decompress_dispatch(gAutorecoverOrbTilesLz, (void *)0x06014800);
    CpuFastSet(gAutorecoverOrbPalettes, (void *)0x050002C0, 0x10);
    gSpriteEntries[0x21].flags |= SPRITE_FLAG_AFFINE;
    gSpriteEntries[0x21].scale_x = 0x40;
    gSpriteEntries[0x21].scale_y = 0x40;
    gSpriteEntries[0x21].palette = 6;
    gSpriteEntries[0x21].unk30 = gSpriteEntries[gBattleWork.target * 4 + 0x5D].x;
    gSpriteEntries[0x21].unk32 = gSpriteEntries[gBattleWork.target * 4 + 0x5D].y - 4;
    gSpriteEntries[0x21].unk24 = 6;
    battle_sprite_anim_init(gBattleSpriteAnimScripts[0x3E], 0x21);
    gGameWork.stepTimer = 0x3C;
    gBattleWork.step++;
}

void heal_orb_hold(void) {
    process_sprite_anim_commands(gBattleSpriteAnimScripts[0x3E], 0x21);
    if (gGameWork.skipBotSetup == 0 && (*(u8 *)&gRepeatKeys & 1))
        gBattleWork.step++;
    else if (gGameWork.stepTimer)
        gGameWork.stepTimer--;
    else
        gBattleWork.step++;
}

void heal_orb_fly(void) {
    process_sprite_anim_commands(gBattleSpriteAnimScripts[0x3E], 0x21);
    if (move_sprite_toward_target(0x21))
        gBattleWork.step++;
}

void heal_orb_shrink(void) {
    process_sprite_anim_commands(gBattleSpriteAnimScripts[0x3E], 0x21);
    if (gSpriteEntries[0x21].scale_x == 8) {
        clear_battle_sprite_slot(0x21, 1);
        gBattleWork.step++;
    } else
        gSpriteEntries[0x21].scale_x -= 8;
}

void autorecover_ring_spawn(void) {
    u32 i;
    struct Coords16 pos;

    gSpriteEntries[0x25].flags =
        SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_AFFINE | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[0x25].frame_table = 0;
    gSpriteEntries[0x25].x = gSpriteEntries[gBattleWork.target * 4 + 0x5D].x;
    gSpriteEntries[0x25].y = gSpriteEntries[gBattleWork.target * 4 + 0x5D].y - 4;
    gSpriteEntries[0x25].palette = 7;
    gSpriteEntries[0x25].scale_x = 0x40;
    gSpriteEntries[0x25].scale_y = 0x40;
    gSpriteEntries[0x25].order = 0xF0;
    battle_sprite_anim_init(gBattleSpriteAnimScripts[0x3F], 0x25);
    for (i = 0; i < 4; i++) {
        gSpriteEntries[0x21 + i].flags = SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) |
                                         SPRITE_FLAG_AFFINE | SPRITE_FLAG_PART_PALETTE;
        pos = calc_polar_to_screen_coords(i << 6, 0x10, gSpriteEntries[gBattleWork.target * 4 + 0x5D].x,
                                          gSpriteEntries[gBattleWork.target * 4 + 0x5D].y - 4);
        gSpriteEntries[0x21 + i].x = pos.x;
        gSpriteEntries[0x21 + i].y = pos.y;
        gSpriteEntries[0x21 + i].frame_table = 0;
        gSpriteEntries[0x21 + i].palette = 7;
        gSpriteEntries[0x21 + i].order = 0xF0;
        gSpriteEntries[0x21 + i].frame = 0x4604;
        gSpriteEntries[0x21 + i].scale_x = 0x40;
        gSpriteEntries[0x21 + i].scale_y = 0x40;
        gSpriteEntries[0x21 + i].unk2B = 0x10;
        gSpriteEntries[0x21 + i].unk2C = i << 6;
        gSpriteEntries[0x21 + i].unk2D = 0;
    }
    play_sound_effect(0x4A);
    gBattleWork.step++;
}

void heal_ring_spin(void) {
    u32 i;
    struct Coords16 pos;
    u32 n;

    process_sprite_anim_commands(gBattleSpriteAnimScripts[0x3F], 0x25);
    for (i = 0; i < 5; i++) {
        if (i < 4) {
            pos = calc_polar_to_screen_coords(gSpriteEntries[0x21 + i].unk2C, gSpriteEntries[0x21 + i].unk2B,
                                              gSpriteEntries[gBattleWork.target * 4 + 0x5D].x,
                                              gSpriteEntries[gBattleWork.target * 4 + 0x5D].y - 4);
            gSpriteEntries[0x21 + i].x = pos.x;
            gSpriteEntries[0x21 + i].y = pos.y;
            gSpriteEntries[0x21 + i].unk2C += 4;
        }
        n = gSpriteEntries[0x21 + i].unk2D + 1;
        gSpriteEntries[0x21 + i].unk2D = n;
        if (gSpriteEntries[0x21 + i].unk2D > 0x5A) {
            if (n & 1)
                gSpriteEntries[0x21 + i].unk2B++;
            gSpriteEntries[0x21 + i].scale_x -= 2;
            gSpriteEntries[0x21 + i].scale_y -= 2;
        }
    }
    if (gSpriteEntries[0x21].scale_y == 4) {
        clear_battle_sprite_slot(0x21, 5);
        gBattleWork.step++;
    }
}

// Gives the target the AutoRecover status (unkC4 = skill 31) with this action's power.
void autorecover_apply(void) {
    gBattleBots[gBattleWork.target].buffType = 0x1F;
    gBattleBots[gBattleWork.target].buffPart = 0;
    gBattleBots[gBattleWork.target].buffTimer = clamp_1_99(gBattleWork.success);
    gBattleBots[gBattleWork.target].buffAmount = clamp_1_99(gBattleWork.amount);
    gBattleWork.step++;
}

void autorecover_finish(void) {
    gBattleWork.messageId = 0x29;
    gBattleWork.step++;
}

void reactivate_run(void) {
    gBattleWork.stepDone = 0;
    gReactivateSteps[gBattleWork.step]();
}

void reactivate_begin(void) {
    calc_battle_action_speed(gBattleWork.actor, gBattleWork.actorPart);
    apply_battle_bot_damage_reduction(gBattleWork.actor);
    if (decrement_battle_timer_and_check_zero()) {
        gBattleWork.messageId = 0x1A;
        gBattleWork.step++;
    } else if (gBattleBots[gBattleWork.target].parts[0].armor) {
        gBattleWork.messageId = 9;
        gBattleWork.step++;
    } else {
        side_add_action_point();
        calc_battle_stat_ratio(gBattleWork.actor, gBattleWork.actorPart);
        gBattleWork.step = 4;
    }
}

void reactivate_orb_spawn(void) {
    lz_decompress_dispatch(gReactivateOrbTilesLz, (void *)0x06014800);
    CpuFastSet(gReactivateOrbPalettes, (void *)0x050002C0, 0x10);
    gSpriteEntries[0x21].flags |= SPRITE_FLAG_AFFINE;
    gSpriteEntries[0x21].scale_x = 0x40;
    gSpriteEntries[0x21].scale_y = 0x40;
    gSpriteEntries[0x21].palette = 6;
    gSpriteEntries[0x21].unk30 = gSpriteEntries[gBattleWork.target * 4 + 0x5D].x;
    gSpriteEntries[0x21].unk32 = gSpriteEntries[gBattleWork.target * 4 + 0x5D].y - 4;
    gSpriteEntries[0x21].unk24 = 6;
    battle_sprite_anim_init(gBattleSpriteAnimScripts[0x3E], 0x21);
    gGameWork.stepTimer = 0x3C;
    gBattleWork.step++;
}

void reactivate_ring_spawn(void) {
    u32 i;
    struct Coords16 pos;

    gSpriteEntries[0x25].flags =
        SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_AFFINE | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[0x25].frame_table = 0;
    gSpriteEntries[0x25].x = gSpriteEntries[gBattleWork.target * 4 + 0x5D].x;
    gSpriteEntries[0x25].y = gSpriteEntries[gBattleWork.target * 4 + 0x5D].y - 4;
    gSpriteEntries[0x25].palette = 7;
    gSpriteEntries[0x25].scale_x = 0x40;
    gSpriteEntries[0x25].scale_y = 0x40;
    gSpriteEntries[0x25].order = 0xF0;
    battle_sprite_anim_init(gBattleSpriteAnimScripts[0x3F], 0x25);
    for (i = 0; i < 4; i++) {
        gSpriteEntries[0x21 + i].flags = SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) |
                                         SPRITE_FLAG_AFFINE | SPRITE_FLAG_PART_PALETTE;
        pos = calc_polar_to_screen_coords(i << 6, 0x10, gSpriteEntries[gBattleWork.target * 4 + 0x5D].x,
                                          gSpriteEntries[gBattleWork.target * 4 + 0x5D].y - 4);
        gSpriteEntries[0x21 + i].x = pos.x;
        gSpriteEntries[0x21 + i].y = pos.y;
        gSpriteEntries[0x21 + i].frame_table = 0;
        gSpriteEntries[0x21 + i].palette = 7;
        gSpriteEntries[0x21 + i].order = 0xF0;
        gSpriteEntries[0x21 + i].frame = 0x4604;
        gSpriteEntries[0x21 + i].scale_x = 0x40;
        gSpriteEntries[0x21 + i].scale_y = 0x40;
        gSpriteEntries[0x21 + i].unk2B = 0x10;
        gSpriteEntries[0x21 + i].unk2C = i << 6;
        gSpriteEntries[0x21 + i].unk2D = 0;
    }
    play_sound_effect(0x4B);
    gBattleWork.step++;
}

// Revives a target whose head is broken: refills the head and redraws its parts.
void reactivate_apply(void) {
    gBattleBots[gBattleWork.target].teamState = 3;
    battle_calc_damage_split(gBattleWork.target, 0, gBattleWork.amount);
    gBattleBots[gBattleWork.target].parts[0].armor = gBattleWork.appliedAmount;
    gBattleBots[gBattleWork.target].present = 1;
    load_all_bot_part_sprites();
    iterate_bots_setup_battle_sprites();
    gBattleWork.step++;
}

void reactivate_finish(void) {
    memcpy_bytes_0803F63C(gBattleBots[gBattleWork.target].medal.name, gGameWork.textBuf, 0xE);
    gBattleWork.messageId = 0x28;
    gBattleWork.step++;
}
