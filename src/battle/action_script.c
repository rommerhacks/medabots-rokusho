// Battle state 9: battle_run_action_script reads the acting Medabot's action script one byte at a time
// and calls gActionScriptCommands[command] (script_op_end_action..script_op_medaforce_anti_protection, in ROM order;
// opcodes 0x1E-0x6A start the effect sequences of battle/action_steps and the *_skills / medaforce_effects modules).
// Ends with the script reader (battle_script_read_byte / load_operands / advance).

#include "global.h"

// Runs the acting Medabot's action script (gActionScripts[gBattleWork.actorSkill]): commands < 0x80 go to
// gActionScriptCommands, others are skipped; a command sets unk163 to run the next one in the same frame.
void battle_run_action_script(void) {
    if (link_error_check() == 0) {
        if (gVBlankOamMode == 2) {
            u32 fill = 0x200;

            CpuFastSet(&fill, gSpriteWork->oamBuf, 0x01000100);
        }
        if (gBattleWork.closeupWipeDone == 0)
            update_all_battle_status_sprites();
        do {
            gBattleWork.runNextStep = 0;
            gGameSubState = battle_script_read_byte();
            while ((s32)gGameSubState > 0x7F) {
                battle_script_advance();
                gGameSubState = battle_script_read_byte();
            }
            gActionScriptCommands[gGameSubState]();
        } while (gBattleWork.runNextStep);
    }
}

// Opcode 0x01: ends the action script (battle state 8, sub-state 0x40).
void script_op_end_action(void) {
    gGameState = 8;
    gGameSubState = 0x40;
}

// Opcode 0x02: skips forward to the next command byte equal to operand 0.
void script_op_skip_to_label(void) {
    vu8 found = 0;
    struct BattleWork *s;
    const u8 *const *tbl;
    const u8 *script;

    battle_script_load_operands();
    battle_script_advance();
    while (!found) {
        tbl = gActionScripts;
        s = &gBattleWork;
        script = tbl[s->actorSkill];
        if (s->scriptOperands[0] == script[s->scriptOffset]) {
            battle_script_advance();
            found = 1;
        } else
            battle_script_advance();
    }
    gBattleWork.runNextStep = 1;
}

// Opcode 0x03: skips forward to the command byte equal to operand [stepResult] (the last check's 0-2 result).
void script_op_branch_on_result(void) {
    vu8 found = 0;
    struct BattleWork *s;
    const u8 *const *tbl;
    const u8 *script;

    battle_script_load_operands();
    battle_script_advance();
    while (!found) {
        tbl = gActionScripts;
        s = &gBattleWork;
        script = tbl[s->actorSkill];
        if (s->scriptOperands[s->stepResult] == script[s->scriptOffset]) {
            battle_script_advance();
            found = 1;
        } else
            battle_script_advance();
    }
    gBattleWork.runNextStep = 1;
}

void script_op_trap_hit(void) {
    trap_hit_run();
    if (gBattleWork.stepDone)
        battle_script_advance();
}

void script_op_action_part_check(void) {
    action_part_check_run();
    if (gBattleWork.stepDone)
        battle_script_advance();
}

// Opcode 0x06: no target yet -> the nearest enemy; no target part -> a random intact one; then loads both.
void script_op_resolve_target(void) {
    if (gBattleBots[gBattleWork.actor].unkE0 == 0)
        battle_target_nearest_enemy(gBattleWork.actor);
    if (gBattleBots[gBattleWork.actor].unkE1 == 0)
        battle_pick_random_target_part(gBattleWork.actor);
    battle_load_action_target(gBattleWork.actor);
    battle_script_advance();
}

void script_op_target_part_check(void) {
    target_part_check_run();
    if (gBattleWork.stepDone)
        battle_script_advance();
}

void script_op_action_flash(void) {
    action_flash_run();
    if (gBattleWork.stepDone)
        battle_script_advance();
}

void script_op_guard(void) {
    guard_run();
    if (gBattleWork.stepDone)
        battle_script_advance();
}

void script_op_guard_restore(void) {
    if (gBattleWork.guardBot) {
        memcpy_bytes_0803F63C(gGuardSpriteEntryBytes,
                              gGuardSpriteEntryBytes + 0xE40 + ((gBattleWork.guardBot - 1) << 8), 0x40);
        memcpy_bytes_0803F63C(gGuardSpriteEntryBytes + 0x40,
                              gGuardSpriteEntryBytes + 0xE80 + ((gBattleWork.guardBot - 1) << 8), 0x40);
        memcpy_bytes_0803F63C(gGuardSpriteEntryBytes + 0x80,
                              gGuardSpriteEntryBytes + 0xEC0 + ((gBattleWork.guardBot - 1) << 8), 0x40);
        memcpy_bytes_0803F63C(gGuardSpriteEntryBytes + 0xC0,
                              gGuardSpriteEntryBytes + 0xF00 + ((gBattleWork.guardBot - 1) << 8), 0x40);
        clear_battle_sprite_slot(0x21, 4);
        enable_sprites(gBattleWork.guardBot * 4 + 0x56, 4);
        init_battle_sprite_entry_0801BC04(gBattleWork.guardBot - 1);
        gBattleWork.guardBot = 0;
        load_all_bot_part_sprites();
        iterate_bots_setup_battle_sprites();
    }
    battle_script_advance();
}

// Opcode 0x0B: sets the actor's unkBC bits 1 / 0 by skill type (data[2]: 0 Strike, 1 Berserk, 3 Aim Shot).
void script_op_set_attack_type_flags(void) {
    u32 type = gBattleBots[gBattleWork.actor].parts[gBattleWork.actorPart].data[2];

    if (type == 0)
        goto both;
    if (type == 1) {
    both:
        gBattleBots[gBattleWork.actor].hitFlags |= 2;
        if (gBattleBots[gBattleWork.actor].parts[gBattleWork.actorPart].data[2] == 1)
            gBattleBots[gBattleWork.actor].hitFlags |= 1;
    } else if (type == 3)
        gBattleBots[gBattleWork.actor].hitFlags |= 1;
    battle_script_advance();
}

// Opcode 0x0C: the attack's success value (unkE8).
void script_op_calc_success(void) {
    battle_calc_attack_success();
    battle_script_advance();
}

// Opcode 0x0D: a guarding teammate or a cover part takes the attack (stepResult = 1).
void script_op_guard_check(void) {
    battle_check_guard_or_cover();
    battle_script_advance();
}

// Opcode 0x0E: guess: sets the target's unkBC bits 2 / 3 (no dodge) from its status effect and attack type.
void script_op_set_target_no_dodge_flags(void) {
    u32 type;

    if (gBattleBots[gBattleWork.target].statusType == 0x2E)
        gBattleBots[gBattleWork.target].hitFlags |= 4;
    if (gBattleBots[gBattleWork.target].statusType == 0x2F)
        gBattleBots[gBattleWork.target].hitFlags |= 8;
    type = gBattleBots[gBattleWork.target].statusType;
    if (type == 0xF)
        goto both;
    if (type == 0x10) {
    both:
        gBattleBots[gBattleWork.target].hitFlags |= 0xC;
    }
    if (gBattleBots[gBattleWork.target].hitFlags & 1)
        gBattleBots[gBattleWork.target].hitFlags |= 4;
    if (gBattleBots[gBattleWork.target].hitFlags & 2)
        gBattleBots[gBattleWork.target].hitFlags |= 8;
    battle_script_advance();
}

// Opcode 0x0F: success against the target's evasion (evasion).
void script_op_evasion_check(void) {
    battle_begin_action_phase();
    battle_script_advance();
}

// Opcode 0x10: stepResult = 1, hitResult = 1 (missed) when the target dodged.
void script_op_dodge_check(void) {
    battle_check_dodged();
    battle_script_advance();
}

// Opcode 0x11: blockResult = 2 (nullified) when the target is immune (nullifyReason says why).
void script_op_nullify_check(void) {
    battle_check_nullified();
    battle_script_advance();
}

// Opcode 0x12: blockResult = 4 (absorbed) when the target absorbs the attack (absorbReason says why).
void script_op_absorb_check(void) {
    battle_check_absorbed();
    battle_script_advance();
}

// Opcode 0x13: successBonus = success / 4, added to the damage by script_op_calc_damage.
void script_op_success_bonus(void) {
    gBattleWork.successBonus = gBattleWork.success >> 2;
    battle_script_advance();
}

// Opcode 0x14: the damage (unkEC) from the part's power (data[6]) and the actor's and target's modifiers.
void script_op_calc_damage(void) {
    u32 type;

    gBattleWork.amount = 0;
    gBattleWork.amount = gBattleBots[gBattleWork.actor].parts[gBattleWork.actorPart].data[6] + gBattleWork.successBonus;
    gBattleWork.amount += gBattleBots[gBattleWork.actor].powerBonus;
    type = gBattleBots[gBattleWork.actor].parts[gBattleWork.actorPart].data[2];
    if (type == 0)
        goto melee;
    if (type == 1) {
    melee:
        gBattleWork.amount += gBattleBots[gBattleWork.actor].meleeBonus;
    }
    if (gBattleBots[gBattleWork.actor].parts[gBattleWork.actorPart].data[2] == 2)
        goto ranged;
    if (gBattleBots[gBattleWork.actor].parts[gBattleWork.actorPart].data[2] == 3) {
    ranged:
        gBattleWork.amount += gBattleBots[gBattleWork.actor].rangedBonus;
    }
    if (gBattleBots[gBattleWork.actor].parts[gBattleWork.actorPart].data[2] == 1)
        gBattleWork.amount += gBattleBots[gBattleWork.actor].parts[3].unk12 >> 1;
    type = gBattleBots[gBattleWork.actor].parts[gBattleWork.actorPart].data[1];
    if (type == 4)
        goto skill;
    if (type == 5) {
    skill:
        gBattleWork.amount += gBattleBots[gBattleWork.actor].parts[gBattleWork.actorPart].data[6];
    }
    if (gBattleBots[gBattleWork.actor].unkD6 & 1)
        gBattleWork.amount += gBattleBots[gBattleWork.actor].parts[gBattleWork.actorPart].data[6];
    if (gBattleBots[gBattleWork.actor].parts[gBattleWork.actorPart].data[1] == 0x34 &&
        gBattleWork.traps[gBattleWork.otherSide].skill == 0x33)
        gBattleWork.amount += gBattleWork.traps[gBattleWork.otherSide].power;
    damage_add_strengthen_parts(gBattleWork.actor);
    subtract_s16_floored(&gBattleWork.amount, gBattleBots[gBattleWork.target].ironWallBonus);
    if (gBattleWork.guardBot != 0 && gBattleWork.guardSkill == 0x1B)
        subtract_s16_floored(&gBattleWork.amount, (s16)gBattleBots[gBattleWork.target].defence);
    battle_script_advance();
}

// Opcode 0x15: Half Block guard: damage below the guard's threshold (unkD8) is nullified.
void script_op_half_block_check(void) {
    if (gBattleWork.guardBot != 0 && gBattleWork.guardSkill == 0x1D && gBattleWork.blockResult == 0 &&
        gBattleWork.amount < (s16)gBattleBots[gBattleWork.target].defence) {
        gBattleWork.blockResult = 2;
        gBattleWork.nullifyReason = 1;
    }
    battle_script_advance();
}

// Opcode 0x16: Full Block guard: the attack is nullified.
void script_op_full_block_check(void) {
    if (gBattleWork.guardBot != 0 && gBattleWork.guardSkill == 0x1C && gBattleWork.blockResult == 0) {
        gBattleWork.blockResult = 2;
        gBattleWork.nullifyReason = 5;
    }
    battle_script_advance();
}

// Opcode 0x17: guess: the target counters (unkB7 = 3) damage above its threshold (unkD8).
void script_op_counter_check(void) {
    if ((gBattleBots[gBattleWork.target].stateFlags & 0x10) &&
        gBattleBots[gBattleWork.target].parts[gBattleBots[gBattleWork.target].lastAction - 1].unk11 != 0 &&
        gBattleWork.hitResult == 0 && gBattleWork.amount > (s16)gBattleBots[gBattleWork.target].defence)
        gBattleWork.hitResult = 3;
    battle_script_advance();
}

// Opcode 0x18: small damage gets + rng & 3, then the damage is divided by the part's data[0xC].
void script_op_finish_damage(void) {
    damage_add_small_random();
    damage_divide_by_part_divisor(gBattleWork.actor, gBattleWork.actorPart);
    battle_script_advance();
}

void script_op_announce_action(void) {
    action_announce_run();
    if (gBattleWork.stepDone)
        battle_script_advance();
}

void script_op_closeup_enter(void) {
    gGameWork.inCloseup = 1;
    closeup_enter_run();
    if (gBattleWork.stepDone)
        battle_script_advance();
}

void script_op_skill_anim_start(void) {
    init_battle_scene_backgrounds();
    closeup_left_pose_step();
    closeup_right_pose_step();
    clear_battle_sprite_slot(0, 0x28);
    CpuFastSet(gEffectCommonPalette, (void *)0x05000380, 8);
    gBattleWork.seqOffset = 0;
    gBattleWork.unkFB = 0;
    gBattleWork.unkFC = 0;
    gBattleWork.seqCondition = 0;
    gBattleWork.unkFE = 0;
    if (gBattleBots[gBattleWork.actor].chosenAction <= 3)
        gBattleWork.animSkill = gBattleBots[gBattleWork.actor].parts[gBattleWork.actorPart].data[1];
    else
        gBattleWork.animSkill = gBattleBots[gBattleWork.actor].medaforce[0] + 0x50;
    gSpriteEntries[1].unk29 = 1;
    gSpriteEntries[2].unk29 = 1;
    battle_script_advance();
}

void script_op_skill_anim_run(void) {
    init_battle_scene_backgrounds();
    gBattleWork.closeupLeftPoseDone = closeup_left_pose_step();
    gBattleWork.closeupRightPoseDone = closeup_right_pose_step();
    gBattleWork.stepDone = 0;
    battle_sequence_update();
    if (gBattleWork.stepDone) {
        gGameWork.inCloseup = 0;
        battle_script_advance();
    }
}

void script_op_set_damage(void) {
    init_battle_scene_backgrounds();
    gBattleWork.closeupLeftPoseDone = closeup_left_pose_step();
    gBattleWork.closeupRightPoseDone = closeup_right_pose_step();
    gBattleWork.damagePart = gBattleWork.targetPart;
    battle_set_damage_vs_armor(gBattleWork.target, gBattleWork.damagePart, gBattleWork.amount);
    battle_script_advance();
}

void script_op_attack_hit(void) {
    init_battle_scene_backgrounds();
    gBattleWork.closeupLeftPoseDone = closeup_left_pose_step();
    gBattleWork.closeupRightPoseDone = closeup_right_pose_step();
    attack_hit_run();
    if (gBattleWork.stepDone)
        battle_script_advance();
}

void script_op_status_attack(void) {
    init_battle_scene_backgrounds();
    gBattleWork.closeupLeftPoseDone = closeup_left_pose_step();
    gBattleWork.closeupRightPoseDone = closeup_right_pose_step();
    status_attack_run();
    if (gBattleWork.stepDone)
        battle_script_advance();
}

void script_op_closeup_exit(void) {
    closeup_exit_run();
    if (gBattleWork.stepDone) {
        gGameWork.inCloseup = 0;
        battle_script_advance();
    }
}

void script_op_bot_defeat(void) {
    bot_defeat_run();
    if (gBattleWork.stepDone)
        battle_script_advance();
}

void script_op_reaction(void) {
    init_battle_scene_backgrounds();
    gBattleWork.closeupLeftPoseDone = closeup_left_pose_step();
    gBattleWork.closeupRightPoseDone = closeup_right_pose_step();
    reaction_run();
    if (gBattleWork.stepDone)
        battle_script_advance();
}

void script_op_sacrifice(void) {
    sacrifice_run();
    if (gBattleWork.stepDone)
        battle_script_advance();
}

void script_op_destroy_check(void) {
    destroy_check_run();
    if (gBattleWork.stepDone)
        battle_script_advance();
}

void script_op_recovery(void) {
    recovery_run();
    if (gBattleWork.stepDone)
        battle_script_advance();
}

void script_op_recovery_heal(void) {
    init_battle_scene_backgrounds();
    gBattleWork.closeupLeftPoseDone = closeup_left_pose_step();
    gBattleWork.closeupRightPoseDone = closeup_right_pose_step();
    recovery_heal_run();
    if (gBattleWork.stepDone)
        battle_script_advance();
}

void script_op_repair(void) {
    repair_run();
    if (gBattleWork.stepDone)
        battle_script_advance();
}

void script_op_repair_apply(void) {
    init_battle_scene_backgrounds();
    gBattleWork.closeupLeftPoseDone = closeup_left_pose_step();
    gBattleWork.closeupRightPoseDone = closeup_right_pose_step();
    repair_apply_run();
    if (gBattleWork.stepDone)
        battle_script_advance();
}

void script_op_trap(void) {
    trap_run();
    if (gBattleWork.stepDone)
        battle_script_advance();
}

void script_op_break_form(void) {
    break_form_run();
    if (gBattleWork.stepDone)
        battle_script_advance();
}

void script_op_stability(void) {
    stability_run();
    if (gBattleWork.stepDone)
        battle_script_advance();
}

void script_op_force_bind(void) {
    force_bind_run();
    if (gBattleWork.stepDone)
        battle_script_advance();
}

void script_op_defence(void) {
    defence_run();
    if (gBattleWork.stepDone)
        battle_script_advance();
}

void script_op_autorecover(void) {
    autorecover_run();
    if (gBattleWork.stepDone)
        battle_script_advance();
}

void script_op_reactivate(void) {
    reactivate_run();
    if (gBattleWork.stepDone)
        battle_script_advance();
}

void script_op_scout(void) {
    scout_run();
    if (gBattleWork.stepDone)
        battle_script_advance();
}

void script_op_conceal(void) {
    conceal_run();
    if (gBattleWork.stepDone)
        battle_script_advance();
}

void script_op_boost_charge(void) {
    boost_charge_run();
    if (gBattleWork.stepDone)
        battle_script_advance();
}

void script_op_rapid_charge(void) {
    rapid_charge_run();
    if (gBattleWork.stepDone)
        battle_script_advance();
}

void script_op_drain_charge(void) {
    drain_charge_run();
    if (gBattleWork.stepDone)
        battle_script_advance();
}

void script_op_pushover(void) {
    pushover_run();
    if (gBattleWork.stepDone)
        battle_script_advance();
}

void script_op_impair(void) {
    impair_run();
    if (gBattleWork.stepDone)
        battle_script_advance();
}

void script_op_confusion(void) {
    confusion_run();
    if (gBattleWork.stepDone)
        battle_script_advance();
}

void script_op_use_drain(void) {
    use_drain_run();
    if (gBattleWork.stepDone)
        battle_script_advance();
}

void script_op_no_escape_defense(void) {
    no_escape_defense_run();
    if (gBattleWork.stepDone)
        battle_script_advance();
}

void script_op_forcedrain(void) {
    forcedrain_run();
    if (gBattleWork.stepDone)
        battle_script_advance();
}

void script_op_team_attack_check(void) {
    team_attack_check_run();
    if (gBattleWork.stepDone)
        battle_script_advance();
}

void script_op_team_attack_turrets(void) {
    team_attack_turrets_run();
    if (gBattleWork.stepDone)
        battle_script_advance();
}

void script_op_clear_queued_action(void) {
    gBattleWork.traps[gBattleWork.otherSide].active = 0;
    gBattleWork.traps[gBattleWork.otherSide].skill = 0;
    gBattleWork.traps[gBattleWork.otherSide].durability = 0;
    gBattleWork.traps[gBattleWork.otherSide].power = 0;
    battle_script_advance();
}

void script_op_counter_attack(void) {
    counter_attack_run();
    if (gBattleWork.stepDone)
        battle_script_advance();
}

void script_op_change(void) {
    change_run();
    if (gBattleWork.stepDone) {
        if (gBattleWork.stepResult == 1)
            battle_script_advance();
        else {
            gGameState = 8;
            gGameSubState = 0;
        }
    }
}

// Opcode 0x40: Spiral Bolt (Medaforce 0), damage to all four parts of the target.
void script_op_medaforce_spiral_bolt(void) {
    init_battle_scene_backgrounds();
    gBattleWork.closeupLeftPoseDone = closeup_left_pose_step();
    gBattleWork.closeupRightPoseDone = closeup_right_pose_step();
    medaforce_spiral_bolt_run();
    if (gBattleWork.stepDone)
        battle_script_advance();
}

// Opcode 0x41: targets a random enemy and a random intact part of it.
void script_op_target_random_enemy(void) {
    gBattleWork.targetSideFirst = battle_enemy_side_first_record(gBattleWork.actor);
    gBattleBots[gBattleWork.actor].unkE0 = select_random_battle_target(gBattleWork.targetSideFirst) + 1;
    battle_pick_random_target_part(gBattleWork.actor);
    battle_load_action_target(gBattleWork.actor);
    battle_script_advance();
}

// Opcode 0x42: Medaforce success and damage (unkA8 = the Medaforce record).
void script_op_medaforce_damage(void) {
    medaforce_calc_success(gBattleWork.actor);
    medaforce_calc_damage(gBattleWork.actor);
    battle_script_advance();
}

// Opcode 0x43: adds the power of the actor's intact Shoot / Aim Shot parts to the damage.
void script_op_damage_add_shoot_parts(void) {
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gBattleBots[gBattleWork.actor].parts[i].unk11 != 0) {
            u32 type = gBattleBots[gBattleWork.actor].parts[i].data[2];

            if (type == 2)
                goto add;
            if (type == 3) {
            add:
                gBattleWork.amount += gBattleBots[gBattleWork.actor].parts[i].data[6];
            }
        }
    }
    battle_script_advance();
}

// Opcode 0x44: the shared Medaforce hit on one part (Ultra Shot, Damage Ball, Life Drain, Shrapnel Attack,
// Unbreakable Will, Structureless, Dice Attack, Type Crash).
void script_op_medaforce_hit(void) {
    init_battle_scene_backgrounds();
    gBattleWork.closeupLeftPoseDone = closeup_left_pose_step();
    gBattleWork.closeupRightPoseDone = closeup_right_pose_step();
    medaforce_hit_run();
    if (gBattleWork.stepDone)
        battle_script_advance();
}

// Opcode 0x45.
void script_op_add_action_point(void) {
    side_add_action_point();
    battle_script_advance();
}

// Opcode 0x46: adds the armor the actor has lost to the damage.
void script_op_damage_from_armor_lost(void) {
    u32 i;

    for (i = 0; i <= 3; i++)
        gBattleWork.amount +=
            gBattleBots[gBattleWork.actor].parts[i].data[4] - gBattleBots[gBattleWork.actor].parts[i].unk11;
    battle_script_advance();
}

// Opcode 0x47: guess: the actor targets itself (old target in swapBot) and the close-up sides swap.
void script_op_target_self(void) {
    init_battle_scene_backgrounds();
    gBattleWork.closeupLeftPoseDone = closeup_left_pose_step();
    gBattleWork.closeupRightPoseDone = closeup_right_pose_step();
    gBattleWork.reactionFlags = 3;
    gBattleBots[gBattleWork.actor].unkE0 = gBattleWork.actor + 1;
    gBattleWork.swapBot = gBattleWork.target;
    battle_load_action_target(gBattleWork.actor);
    gBattleWork.actorSideFlags ^= 2;
    if (!(gBattleWork.actorSideFlags & 2))
        gBattleWork.closeupPoseBase[0] = 0;
    else {
        gBattleWork.closeupPoseBase[0] = 0x28;
        gBattleWork.closeupRedraw |= 1;
    }
    if (!(gBattleWork.actorSideFlags & 2)) {
        gBattleWork.closeupPoseBase[1] = 0x28;
        gBattleWork.closeupRedraw |= 2;
    } else
        gBattleWork.closeupPoseBase[1] = 0;
    battle_script_advance();
}

// Opcode 0x48: Life Drain (Medaforce 0x14) heals the actor's most damaged part.
void script_op_medaforce_life_drain_heal(void) {
    init_battle_scene_backgrounds();
    gBattleWork.closeupLeftPoseDone = closeup_left_pose_step();
    gBattleWork.closeupRightPoseDone = closeup_right_pose_step();
    medaforce_life_drain_heal_run();
    if (gBattleWork.stepDone)
        battle_script_advance();
}

// Opcode 0x49: half of each of the actor's part armors (kept in partDamage[]) is added to the damage.
void script_op_damage_from_half_armor(void) {
    u32 i;

    for (i = 0; i <= 3; i++) {
        gBattleWork.partDamage[i] = gBattleBots[gBattleWork.actor].parts[i].unk11 >> 1;
        gBattleWork.amount += gBattleBots[gBattleWork.actor].parts[i].unk11 >> 1;
    }
    battle_script_advance();
}

// Opcode 0x4A: + 10 damage per broken part on the actor's team.
void script_op_damage_from_broken_parts(void) {
    u32 i, j;

    gBattleWork.targetSideFirst = battle_side_first_record(gBattleWork.actor);
    for (i = 0; i <= 2; i++) {
        if (gBattleBots[gBattleWork.targetSideFirst + i].present != 0) {
            for (j = 0; j <= 3; j++) {
                if (gBattleBots[gBattleWork.targetSideFirst + i].parts[j].unk11 == 0)
                    gBattleWork.amount += 10;
            }
        }
    }
    battle_script_advance();
}

// Opcode 0x4B: targets a guarding enemy's guard part; none: a random enemy, nullified (unkB8 = 2).
void script_op_target_guarding_enemy(void) {
    u32 t;

    gBattleWork.targetSideFirst = battle_enemy_side_first_record(gBattleWork.actor);
    t = battle_find_guarding_enemy(gBattleWork.targetSideFirst);
    if (t != 0xFF) {
        gBattleBots[gBattleWork.actor].unkE0 = t + 1;
        gBattleBots[gBattleWork.actor].unkE1 = gBattleBots[t].lastAction;
    } else {
        gBattleWork.targetSideFirst = battle_enemy_side_first_record(gBattleWork.actor);
        gBattleBots[gBattleWork.actor].unkE0 = select_random_battle_target(gBattleWork.targetSideFirst) + 1;
        battle_pick_random_target_part(gBattleWork.actor);
        gBattleWork.blockResult = 2;
    }
    battle_load_action_target(gBattleWork.actor);
    battle_script_advance();
}

// Opcode 0x4C: the damage is the target part's armor.
void script_op_damage_equals_target_armor(void) {
    gBattleWork.amount = gBattleBots[gBattleWork.target].parts[gBattleWork.targetPart].unk11;
    battle_script_advance();
}

// Opcode 0x4D: two random digits (unk188, unk189); damage = their sum * 10.
void script_op_roll_dice_damage(void) {
    gBattleWork.dice1 = gDiceRollValues[rng_next_byte() & 0xF];
    gBattleWork.dice2 = gDiceRollValues[rng_next_byte() & 0xF];
    gBattleWork.amount = (gBattleWork.dice1 + gBattleWork.dice2) * 10;
    battle_script_advance();
}

// Opcode 0x4E: targets a random enemy with the actor's leg type, else any random enemy.
void script_op_target_same_legs_enemy(void) {
    u32 t;

    gBattleWork.targetSideFirst = battle_enemy_side_first_record(gBattleWork.actor);
    t = battle_find_enemy_same_legs(gBattleWork.targetSideFirst, gBattleWork.actor);
    if (t != 0xFF)
        gBattleBots[gBattleWork.actor].unkE0 = t + 1;
    else {
        gBattleWork.targetSideFirst = battle_enemy_side_first_record(gBattleWork.actor);
        gBattleBots[gBattleWork.actor].unkE0 = select_random_battle_target(gBattleWork.targetSideFirst) + 1;
    }
    battle_pick_random_target_part(gBattleWork.actor);
    battle_load_action_target(gBattleWork.actor);
    battle_script_advance();
}

// Opcode 0x4F: damage = 10 when no enemy has the actor's leg type.
void script_op_damage_if_no_same_legs(void) {
    gBattleWork.targetSideFirst = battle_enemy_side_first_record(gBattleWork.actor);
    if (battle_find_enemy_same_legs(gBattleWork.targetSideFirst, gBattleWork.actor) == 0xFF)
        gBattleWork.amount = 10;
    battle_script_advance();
}

// Opcode 0x50: Side Bolt (Medaforce 1), damage to all three opponents.
void script_op_medaforce_side_bolt(void) {
    medaforce_side_bolt_run();
    if (gBattleWork.stepDone)
        battle_script_advance();
}

// Opcode 0x51: Optic / Bomb / Gravity Form and Absorb Optic / Bomb / Gravity (Medaforces 4-9).
void script_op_medaforce_form(void) {
    medaforce_form_run();
    if (gBattleWork.stepDone)
        battle_script_advance();
}

// Opcode 0x52: Anti Attk Trap (Medaforce 0xA).
void script_op_medaforce_anti_attack_trap(void) {
    medaforce_anti_attack_trap_run();
    if (gBattleWork.stepDone)
        battle_script_advance();
}

// Opcode 0x53: Cancel Formation (Medaforce 0xB).
void script_op_medaforce_cancel_formation(void) {
    medaforce_cancel_formation_run();
    if (gBattleWork.stepDone)
        battle_script_advance();
}

// Opcode 0x54: Movement / Stop / Bind / Flow (Medaforces 0xC, 0xE, 0x10, 0x12) and Chaos (0x28).
void script_op_medaforce_inflict_status(void) {
    medaforce_inflict_status_run();
    if (gBattleWork.stepDone)
        battle_script_advance();
}

// Opcode 0x55: Cancel Movement / Stop / Bind / Flow (Medaforces 0xD, 0xF, 0x11, 0x13).
void script_op_medaforce_cancel_status(void) {
    medaforce_cancel_status_run();
    if (gBattleWork.stepDone)
        battle_script_advance();
}

// Opcode 0x56: Status Restore (Medaforce 0x15).
void script_op_medaforce_status_restore(void) {
    medaforce_status_restore_run();
    if (gBattleWork.stepDone)
        battle_script_advance();
}

// Opcode 0x57: Total Recovery (Medaforce 0x1A).
void script_op_medaforce_total_recovery(void) {
    medaforce_total_recovery_run();
    if (gBattleWork.stepDone)
        battle_script_advance();
}

// Opcode 0x58: Full Body Repair (Medaforce 0x1C).
void script_op_medaforce_full_body_repair(void) {
    medaforce_full_body_repair_run();
    if (gBattleWork.stepDone)
        battle_script_advance();
}

// Opcode 0x59: Full Body Up (Medaforce 0x16).
void script_op_medaforce_full_body_up(void) {
    medaforce_full_body_up_run();
    if (gBattleWork.stepDone)
        battle_script_advance();
}

// Opcode 0x5A: Full Body RAD (Medaforce 0x17).
void script_op_medaforce_full_body_rad(void) {
    medaforce_full_body_rad_run();
    if (gBattleWork.stepDone)
        battle_script_advance();
}

// Opcode 0x5B: Iron Wall (Medaforce 0x18).
void script_op_medaforce_iron_wall(void) {
    medaforce_iron_wall_run();
    if (gBattleWork.stepDone)
        battle_script_advance();
}

// Opcode 0x5C: Power Up (Medaforce 0x19).
void script_op_medaforce_power_up(void) {
    medaforce_power_up_run();
    if (gBattleWork.stepDone)
        battle_script_advance();
}

// Opcode 0x5D: Anti Air / Anti Sea (Medaforces 0x1E, 0x20).
void script_op_medaforce_anti_terrain(void) {
    medaforce_anti_terrain_run();
    if (gBattleWork.stepDone)
        battle_script_advance();
}

// Opcode 0x5E: Propulsion / Mobility / PROX / Remoteness Up (Medaforces 0x1F, 0x21, 0x23, 0x25).
void script_op_medaforce_legs_stat_up(void) {
    medaforce_legs_stat_up_run();
    if (gBattleWork.stepDone)
        battle_script_advance();
}

// Opcode 0x5F: Spy Game (Medaforce 0x22).
void script_op_medaforce_spy_game(void) {
    medaforce_spy_game_run();
    if (gBattleWork.stepDone)
        battle_script_advance();
}

// Opcode 0x60: Hide n Seek (Medaforce 0x24).
void script_op_medaforce_hide_n_seek(void) {
    medaforce_hide_n_seek_run();
    if (gBattleWork.stepDone)
        battle_script_advance();
}

// Opcode 0x61: Charge (Medaforce 0x26).
void script_op_medaforce_charge(void) {
    medaforce_charge_run();
    if (gBattleWork.stepDone)
        battle_script_advance();
}

// Opcode 0x62: Pushover Attk (Medaforce 0x27).
void script_op_medaforce_pushover_attack(void) {
    medaforce_pushover_attack_run();
    if (gBattleWork.stepDone)
        battle_script_advance();
}

// Opcode 0x63: Useless (Medaforce 0x29).
void script_op_medaforce_useless(void) {
    medaforce_useless_run();
    if (gBattleWork.stepDone)
        battle_script_advance();
}

// Opcode 0x64: Destroyer (Medaforce 0x2A).
void script_op_medaforce_destroyer(void) {
    medaforce_destroyer_run();
    if (gBattleWork.stepDone)
        battle_script_advance();
}

// Opcode 0x65: Crazy Medaforce (Medaforce 0x2C).
void script_op_medaforce_crazy(void) {
    medaforce_crazy_run();
    if (gBattleWork.stepDone)
        battle_script_advance();
}

// Opcode 0x66: Medaforce Up (Medaforce 0x2D).
void script_op_medaforce_up(void) {
    medaforce_up_run();
    if (gBattleWork.stepDone)
        battle_script_advance();
}

// Opcode 0x67: Formation Orders (Medaforce 0x2E).
void script_op_medaforce_formation_orders(void) {
    medaforce_formation_orders_run();
    if (gBattleWork.stepDone)
        battle_script_advance();
}

// Opcode 0x68: Leg Crash (Medaforce 0x2F).
void script_op_medaforce_leg_crash(void) {
    medaforce_leg_crash_run();
    if (gBattleWork.stepDone)
        battle_script_advance();
}

// Opcode 0x69: Protector (Medaforce 0x30).
void script_op_medaforce_protector(void) {
    medaforce_protector_run();
    if (gBattleWork.stepDone)
        battle_script_advance();
}

// Opcode 0x6A: Anti-Protection (Medaforce 0x31).
void script_op_medaforce_anti_protection(void) {
    medaforce_anti_protection_run();
    if (gBattleWork.stepDone)
        battle_script_advance();
}

s32 battle_script_read_byte(void) {
    const u8 *script = gActionScripts[gBattleWork.actorSkill];
    return script[gBattleWork.scriptOffset];
}

void battle_script_load_operands(void) {
    const u8 *script = gActionScripts[gBattleWork.actorSkill];
    u32 n = gActionScriptOperandCounts[script[gBattleWork.scriptOffset]];
    u32 i;
    for (i = 0; i < n; i++)
        gBattleWork.scriptOperands[i] = script[gBattleWork.scriptOffset + i + 1];
}

void battle_script_advance(void) {
    struct BattleWork *b = &gBattleWork;
    const u8 *script;
    const u8 *len;
    u16 *pc;
    s32 n;

    b->step = 0;
    script = gActionScripts[b->actorSkill];
    len = gActionScriptOperandCounts;
    pc = &b->scriptOffset;
    n = *pc;
    *pc = n + 1 + len[script[n]];
}
