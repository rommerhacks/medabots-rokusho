// Action calculations for the action script (battle/action_script): action speed, damage modifiers and
// thresholds, turn speed, the strongest part, and the AI's action type and target mode
// (select_ai_action_type, determine_battle_target_mode). Uses the checks in battle/combat_helpers.

#include "global.h"

static u32 battle_calculate_damage_modifier(void);
static u32 battle_calculate_turn_speed(void);
static void battle_process_speed_and_action(void);
static u32 count_intact_parts(u32 rec);
static u32 battle_find_strongest_part(u32 rec);

void battle_calc_attack_success(void) {
    gBattleWork.success = 0;
    calc_battle_action_speed(gBattleWork.actor, gBattleWork.actorPart);
    if (check_bot_ability_type_strike(gBattleWork.actor, gBattleWork.actorPart, gBattleWork.target))
        gBattleWork.success += gBattleBots[gBattleWork.actor].parts[gBattleWork.actorPart].data[5] << 4;
    if (check_bot_ability_type_shoot(gBattleWork.actor, gBattleWork.actorPart, gBattleWork.target))
        gBattleWork.success += gBattleBots[gBattleWork.actor].parts[gBattleWork.actorPart].data[5] << 4;
    if (gBattleBots[gBattleWork.actor].formFlags & 4)
        gBattleWork.success += gBattleBots[gBattleWork.actor].parts[gBattleWork.actorPart].data[5];
    gBattleWork.success += gBattleWork.traps[gBattleWork.actorSide].unk0;
    success_add_strengthen_parts(gBattleWork.actor);
    if (gBattleBots[gBattleWork.actor].parts[gBattleWork.actorPart].data[1] == 8)
        goto add;
    if (gBattleBots[gBattleWork.actor].parts[gBattleWork.actorPart].data[1] == 9) {
    add:
        gBattleWork.success += gBattleBots[gBattleWork.actor].parts[gBattleWork.actorPart].data[5];
    }
    if (gBattleBots[gBattleWork.actor].parts[gBattleWork.actorPart].data[1] == 0x34 &&
        gBattleWork.traps[gBattleWork.otherSide].skill == 0x33)
        gBattleWork.success += gBattleWork.traps[gBattleWork.otherSide].durability;
    apply_battle_bot_damage_reduction(gBattleWork.actor);
    subtract_s16_floored(&gBattleWork.success, gBattleBots[gBattleWork.target].evasionBonus);
}

// guess: a guarding teammate (unkDE) or the target's cover part (unkBD bit 4) takes the hit: stepResult = 1.
void battle_check_guard_or_cover(void) {
    gBattleBots[gBattleWork.target].hitFlags &= 3;
    gBattleBots[gBattleWork.target].stateFlags |= 2;
    if (gBattleWork.guardBot) {
        gBattleBots[gBattleWork.target].hitFlags |= 0xC;
        gBattleWork.finalSuccess = gBattleWork.success;
        gBattleWork.stepResult = 1;
        if ((gBattleBots[gBattleWork.target].guardFlags & 1) && (rng_next_byte() & 1)) {
            gBattleWork.reactionFlags = 1;
            gBattleWork.hitResult = 3;
        }
    } else if (!(gBattleBots[gBattleWork.actor].guardFlags & 4) &&
               (gBattleBots[gBattleWork.target].stateFlags & 0x10) &&
               gBattleBots[gBattleWork.target].parts[gBattleBots[gBattleWork.target].lastAction - 1].armor) {
        gBattleBots[gBattleWork.target].hitFlags |= 0xC;
        gBattleWork.finalSuccess = gBattleWork.success;
        battle_set_action_target_part(gBattleWork.actor, gBattleBots[gBattleWork.target].lastAction);
        gBattleWork.reactionFlags = 1;
        gBattleWork.stepResult = 1;
    } else {
        gBattleWork.stepResult = 0;
    }
}

void battle_begin_action_phase(void) {
    gBattleWork.evasion = 0;
    if ((gBattleBots[gBattleWork.target].hitFlags & 4) && (gBattleBots[gBattleWork.target].hitFlags & 8))
        battle_calculate_damage_modifier();
    else if (!battle_calculate_turn_speed())
        battle_process_speed_and_action();
}

static u32 battle_calculate_damage_modifier(void) {
    u8 type;

    if (check_bot_ability_type_strike(gBattleWork.actor, gBattleWork.actorPart, gBattleWork.target)) {
        if (battle_check_damage_threshold(gBattleWork.evasion))
            return 1;
        return 0;
    }
    if (check_bot_ability_type_shoot(gBattleWork.actor, gBattleWork.actorPart, gBattleWork.target)) {
        if (battle_check_damage_threshold(gBattleWork.evasion))
            return 1;
        return 0;
    }
    type = gBattleBots[gBattleWork.actor].parts[gBattleWork.actorPart].data[2];
    if (type == 3) {
        if (battle_check_damage_threshold(gBattleWork.evasion * 2))
            return 1;
        return 0;
    }
    if (type == 0) {
        if (battle_check_damage_threshold(gBattleWork.evasion * 4))
            return 1;
        return 0;
    }
    if (battle_check_damage_threshold(gBattleWork.evasion * 8))
        return 1;
    return 0;
}

u32 battle_check_damage_threshold(s16 threshold) {
    if (gBattleWork.success > threshold) {
        gBattleWork.evasion = 0;
        gBattleBots[gBattleWork.target].hitFlags |= 0x4C;
        gBattleWork.finalSuccess = gBattleWork.success;
        return 1;
    }
    return 0;
}

static u32 battle_calculate_turn_speed(void) {
    gBattleWork.evasion = 0;
    if (!(gBattleBots[gBattleWork.target].hitFlags & 4)) {
        accumulate_battle_speed_value(gBattleWork.target);
        gBattleWork.evasion += gBattleBots[gBattleWork.target].parts[3].evasion;
        if (!(gBattleBots[gBattleWork.target].hitFlags & 8))
            subtract_s16_floored((s16 *)&gBattleWork.evasion, 8);
        if (battle_calculate_damage_modifier())
            return 1;
        subtract_s16_floored(&gBattleWork.success, (s16)gBattleWork.evasion);
        if ((gBattleWork.finalSuccess = gBattleWork.success) == 0) {
            u8 type = gBattleBots[gBattleWork.actor].parts[gBattleWork.actorPart].data[1];
            if (type == 6)
                return 0;
            if (type == 7)
                return 0;
            if (!(gBattleBots[gBattleWork.actor].formFlags & 2)) {
                gBattleBots[gBattleWork.target].hitFlags |= 0x10;
                return 1;
            }
        }
    }
    return 0;
}

static void battle_process_speed_and_action(void) {
    u32 part;

    gBattleWork.evasion = 0;
    gBattleWork.finalSuccess = gBattleWork.success;
    if (!(gBattleBots[gBattleWork.target].hitFlags & 8)) {
        accumulate_battle_speed_value(gBattleWork.target);
        gBattleWork.evasion += gBattleBots[gBattleWork.target].parts[3].defence;
        if (!(gBattleBots[gBattleWork.target].hitFlags & 4))
            subtract_s16_floored((s16 *)&gBattleWork.evasion, 8);
        if (!battle_calculate_damage_modifier() && (s16)gBattleWork.evasion > 0x1F) {
            subtract_s16_floored(&gBattleWork.success, (s16)gBattleWork.evasion);
            gBattleWork.finalSuccess = gBattleWork.success;
            gBattleBots[gBattleWork.target].hitFlags |= 0x20;
            if (count_intact_parts(gBattleWork.target) == 1)
                part = 1;
            else
                part = battle_find_strongest_part(gBattleWork.target);
            battle_set_action_target_part(gBattleWork.actor, part);
        }
    }
}

static u32 count_intact_parts(u32 rec) {
    u32 n = 0;
    u32 i;

    for (i = 0; i <= 3; i++)
        if (gBattleBots[rec].parts[i].armor)
            n++;
    return n;
}

static u32 battle_find_strongest_part(u32 rec) {
    u32 best = 0;
    u32 i;
    u32 idx;

    for (i = 3; i != 0; i--) {
        u8 armor = gBattleBots[rec].parts[i].armor;
        if (armor && armor > best) {
            idx = i;
            best = armor;
        }
    }
    return idx + 1;
}

void battle_check_dodged(void) {
    u8 dodged = gBattleBots[gBattleWork.target].hitFlags & 0x10;
    if (dodged) {
        gBattleWork.stepResult = 1;
        gBattleWork.hitResult = 1;
    } else {
        gBattleWork.stepResult = dodged;
    }
}

void battle_check_nullified(void) {
    if (check_bot_can_shoot(gBattleWork.actor, gBattleWork.actorPart, gBattleWork.target)) {
        gBattleWork.blockResult = 2;
        gBattleWork.nullifyReason = 2;
    } else if (check_bot_can_support(gBattleWork.actor, gBattleWork.actorPart, gBattleWork.target)) {
        gBattleWork.blockResult = 2;
        gBattleWork.nullifyReason = 3;
    } else if (check_bot_can_use_shoot_part(gBattleWork.actor, gBattleWork.actorPart, gBattleWork.target)) {
        gBattleWork.blockResult = 2;
        gBattleWork.nullifyReason = 4;
    } else if (check_bot_status_effect_4(gBattleWork.actor, gBattleWork.actorPart, gBattleWork.target)) {
        gBattleWork.blockResult = 2;
        gBattleWork.nullifyReason = 6;
    }
}

void select_ai_action_type(void) {
    if (check_bot_can_shoot(gBattleWork.actor, gBattleWork.actorPart, gBattleWork.actor)) {
        gBattleWork.blockResult = 2;
        gBattleWork.nullifyReason = 2;
    } else if (check_bot_can_support(gBattleWork.actor, gBattleWork.actorPart, gBattleWork.actor)) {
        gBattleWork.blockResult = 2;
        gBattleWork.nullifyReason = 3;
    } else if (check_bot_can_use_shoot_part(gBattleWork.actor, gBattleWork.actorPart, gBattleWork.actor)) {
        gBattleWork.blockResult = 2;
        gBattleWork.nullifyReason = 4;
    } else if (check_bot_status_effect_4(gBattleWork.actor, gBattleWork.actorPart, gBattleWork.actor)) {
        gBattleWork.blockResult = 2;
        gBattleWork.nullifyReason = 6;
    }
}

void battle_check_absorbed(void) {
    if (check_can_target_bot(gBattleWork.actor, gBattleWork.actorPart, gBattleWork.target)) {
        gBattleWork.blockResult = 4;
        gBattleWork.absorbReason = 2;
    } else if (check_battle_can_support_target(gBattleWork.actor, gBattleWork.actorPart, gBattleWork.target)) {
        gBattleWork.blockResult = 4;
        gBattleWork.absorbReason = 3;
    } else if (check_battle_can_special_target(gBattleWork.actor, gBattleWork.actorPart, gBattleWork.target)) {
        gBattleWork.blockResult = 4;
        gBattleWork.absorbReason = 4;
    }
}

void determine_battle_target_mode(void) {
    if (check_can_target_bot(gBattleWork.actor, gBattleWork.actorPart, gBattleWork.actor)) {
        gBattleWork.blockResult = 4;
        gBattleWork.absorbReason = 2;
    } else if (check_battle_can_support_target(gBattleWork.actor, gBattleWork.actorPart, gBattleWork.actor)) {
        gBattleWork.blockResult = 4;
        gBattleWork.absorbReason = 3;
    } else if (check_battle_can_special_target(gBattleWork.actor, gBattleWork.actorPart, gBattleWork.actor)) {
        gBattleWork.blockResult = 4;
        gBattleWork.absorbReason = 4;
    }
}
