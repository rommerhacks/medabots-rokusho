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
    gBattleWork.unkE8 = 0;
    calc_battle_action_speed(gBattleWork.unk87, gBattleWork.unkA7);
    if (check_bot_ability_type_strike(gBattleWork.unk87, gBattleWork.unkA7, gBattleWork.unk88))
        gBattleWork.unkE8 += gBattleBots[gBattleWork.unk87].parts[gBattleWork.unkA7].data[5] << 4;
    if (check_bot_ability_type_shoot(gBattleWork.unk87, gBattleWork.unkA7, gBattleWork.unk88))
        gBattleWork.unkE8 += gBattleBots[gBattleWork.unk87].parts[gBattleWork.unkA7].data[5] << 4;
    if (gBattleBots[gBattleWork.unk87].unkD6 & 4)
        gBattleWork.unkE8 += gBattleBots[gBattleWork.unk87].parts[gBattleWork.unkA7].data[5];
    gBattleWork.unkE8 += gBattleWork.unk28[gBattleWork.unk89].unk0;
    success_add_strengthen_parts(gBattleWork.unk87);
    if (gBattleBots[gBattleWork.unk87].parts[gBattleWork.unkA7].data[1] == 8)
        goto add;
    if (gBattleBots[gBattleWork.unk87].parts[gBattleWork.unkA7].data[1] == 9) {
    add:
        gBattleWork.unkE8 += gBattleBots[gBattleWork.unk87].parts[gBattleWork.unkA7].data[5];
    }
    if (gBattleBots[gBattleWork.unk87].parts[gBattleWork.unkA7].data[1] == 0x34 &&
        gBattleWork.unk28[gBattleWork.unk8A].skill == 0x33)
        gBattleWork.unkE8 += gBattleWork.unk28[gBattleWork.unk8A].durability;
    apply_battle_bot_damage_reduction(gBattleWork.unk87);
    subtract_s16_floored(&gBattleWork.unkE8, gBattleBots[gBattleWork.unk88].evasionBonus);
}

// guess: a guarding teammate (unkDE) or the target's cover part (unkBD bit 4) takes the hit: unkAB = 1.
void battle_check_guard_or_cover(void) {
    gBattleBots[gBattleWork.unk88].hitFlags &= 3;
    gBattleBots[gBattleWork.unk88].stateFlags |= 2;
    if (gBattleWork.unkDE) {
        gBattleBots[gBattleWork.unk88].hitFlags |= 0xC;
        gBattleWork.unkF2 = gBattleWork.unkE8;
        gBattleWork.unkAB = 1;
        if ((gBattleBots[gBattleWork.unk88].guardFlags & 1) && (rng_next_byte() & 1)) {
            gBattleWork.unkF6 = 1;
            gBattleWork.unkB7 = 3;
        }
    } else if (!(gBattleBots[gBattleWork.unk87].guardFlags & 4) && (gBattleBots[gBattleWork.unk88].stateFlags & 0x10) &&
               gBattleBots[gBattleWork.unk88].parts[gBattleBots[gBattleWork.unk88].lastAction - 1].unk11) {
        gBattleBots[gBattleWork.unk88].hitFlags |= 0xC;
        gBattleWork.unkF2 = gBattleWork.unkE8;
        battle_set_action_target_part(gBattleWork.unk87, gBattleBots[gBattleWork.unk88].lastAction);
        gBattleWork.unkF6 = 1;
        gBattleWork.unkAB = 1;
    } else {
        gBattleWork.unkAB = 0;
    }
}

void battle_begin_action_phase(void) {
    gBattleWork.unkEE = 0;
    if ((gBattleBots[gBattleWork.unk88].hitFlags & 4) && (gBattleBots[gBattleWork.unk88].hitFlags & 8))
        battle_calculate_damage_modifier();
    else if (!battle_calculate_turn_speed())
        battle_process_speed_and_action();
}

static u32 battle_calculate_damage_modifier(void) {
    u8 type;

    if (check_bot_ability_type_strike(gBattleWork.unk87, gBattleWork.unkA7, gBattleWork.unk88)) {
        if (battle_check_damage_threshold(gBattleWork.unkEE))
            return 1;
        return 0;
    }
    if (check_bot_ability_type_shoot(gBattleWork.unk87, gBattleWork.unkA7, gBattleWork.unk88)) {
        if (battle_check_damage_threshold(gBattleWork.unkEE))
            return 1;
        return 0;
    }
    type = gBattleBots[gBattleWork.unk87].parts[gBattleWork.unkA7].data[2];
    if (type == 3) {
        if (battle_check_damage_threshold(gBattleWork.unkEE * 2))
            return 1;
        return 0;
    }
    if (type == 0) {
        if (battle_check_damage_threshold(gBattleWork.unkEE * 4))
            return 1;
        return 0;
    }
    if (battle_check_damage_threshold(gBattleWork.unkEE * 8))
        return 1;
    return 0;
}

u32 battle_check_damage_threshold(s16 v) {
    if (gBattleWork.unkE8 > v) {
        gBattleWork.unkEE = 0;
        gBattleBots[gBattleWork.unk88].hitFlags |= 0x4C;
        gBattleWork.unkF2 = gBattleWork.unkE8;
        return 1;
    }
    return 0;
}

static u32 battle_calculate_turn_speed(void) {
    gBattleWork.unkEE = 0;
    if (!(gBattleBots[gBattleWork.unk88].hitFlags & 4)) {
        accumulate_battle_speed_value(gBattleWork.unk88);
        gBattleWork.unkEE += gBattleBots[gBattleWork.unk88].parts[3].unk13;
        if (!(gBattleBots[gBattleWork.unk88].hitFlags & 8))
            subtract_s16_floored((s16 *)&gBattleWork.unkEE, 8);
        if (battle_calculate_damage_modifier())
            return 1;
        subtract_s16_floored(&gBattleWork.unkE8, (s16)gBattleWork.unkEE);
        if ((gBattleWork.unkF2 = gBattleWork.unkE8) == 0) {
            u8 type = gBattleBots[gBattleWork.unk87].parts[gBattleWork.unkA7].data[1];
            if (type == 6)
                return 0;
            if (type == 7)
                return 0;
            if (!(gBattleBots[gBattleWork.unk87].unkD6 & 2)) {
                gBattleBots[gBattleWork.unk88].hitFlags |= 0x10;
                return 1;
            }
        }
    }
    return 0;
}

static void battle_process_speed_and_action(void) {
    u32 part;

    gBattleWork.unkEE = 0;
    gBattleWork.unkF2 = gBattleWork.unkE8;
    if (!(gBattleBots[gBattleWork.unk88].hitFlags & 8)) {
        accumulate_battle_speed_value(gBattleWork.unk88);
        gBattleWork.unkEE += gBattleBots[gBattleWork.unk88].parts[3].unk14;
        if (!(gBattleBots[gBattleWork.unk88].hitFlags & 4))
            subtract_s16_floored((s16 *)&gBattleWork.unkEE, 8);
        if (!battle_calculate_damage_modifier() && (s16)gBattleWork.unkEE > 0x1F) {
            subtract_s16_floored(&gBattleWork.unkE8, (s16)gBattleWork.unkEE);
            gBattleWork.unkF2 = gBattleWork.unkE8;
            gBattleBots[gBattleWork.unk88].hitFlags |= 0x20;
            if (count_intact_parts(gBattleWork.unk88) == 1)
                part = 1;
            else
                part = battle_find_strongest_part(gBattleWork.unk88);
            battle_set_action_target_part(gBattleWork.unk87, part);
        }
    }
}

static u32 count_intact_parts(u32 rec) {
    u32 n = 0;
    u32 i;

    for (i = 0; i <= 3; i++)
        if (gBattleBots[rec].parts[i].unk11)
            n++;
    return n;
}

static u32 battle_find_strongest_part(u32 rec) {
    u32 best = 0;
    u32 i;
    u32 idx;

    for (i = 3; i != 0; i--) {
        u8 a = gBattleBots[rec].parts[i].unk11;
        if (a && a > best) {
            idx = i;
            best = a;
        }
    }
    return idx + 1;
}

void battle_check_dodged(void) {
    u8 f = gBattleBots[gBattleWork.unk88].hitFlags & 0x10;
    if (f) {
        gBattleWork.unkAB = 1;
        gBattleWork.unkB7 = 1;
    } else {
        gBattleWork.unkAB = f;
    }
}

void battle_check_nullified(void) {
    if (check_bot_can_shoot(gBattleWork.unk87, gBattleWork.unkA7, gBattleWork.unk88)) {
        gBattleWork.unkB8 = 2;
        gBattleWork.unkBE = 2;
    } else if (check_bot_can_support(gBattleWork.unk87, gBattleWork.unkA7, gBattleWork.unk88)) {
        gBattleWork.unkB8 = 2;
        gBattleWork.unkBE = 3;
    } else if (check_bot_can_use_shoot_part(gBattleWork.unk87, gBattleWork.unkA7, gBattleWork.unk88)) {
        gBattleWork.unkB8 = 2;
        gBattleWork.unkBE = 4;
    } else if (check_bot_status_effect_4(gBattleWork.unk87, gBattleWork.unkA7, gBattleWork.unk88)) {
        gBattleWork.unkB8 = 2;
        gBattleWork.unkBE = 6;
    }
}

void select_ai_action_type(void) {
    if (check_bot_can_shoot(gBattleWork.unk87, gBattleWork.unkA7, gBattleWork.unk87)) {
        gBattleWork.unkB8 = 2;
        gBattleWork.unkBE = 2;
    } else if (check_bot_can_support(gBattleWork.unk87, gBattleWork.unkA7, gBattleWork.unk87)) {
        gBattleWork.unkB8 = 2;
        gBattleWork.unkBE = 3;
    } else if (check_bot_can_use_shoot_part(gBattleWork.unk87, gBattleWork.unkA7, gBattleWork.unk87)) {
        gBattleWork.unkB8 = 2;
        gBattleWork.unkBE = 4;
    } else if (check_bot_status_effect_4(gBattleWork.unk87, gBattleWork.unkA7, gBattleWork.unk87)) {
        gBattleWork.unkB8 = 2;
        gBattleWork.unkBE = 6;
    }
}

void battle_check_absorbed(void) {
    if (check_can_target_bot(gBattleWork.unk87, gBattleWork.unkA7, gBattleWork.unk88)) {
        gBattleWork.unkB8 = 4;
        gBattleWork.unkBF = 2;
    } else if (check_battle_can_support_target(gBattleWork.unk87, gBattleWork.unkA7, gBattleWork.unk88)) {
        gBattleWork.unkB8 = 4;
        gBattleWork.unkBF = 3;
    } else if (check_battle_can_special_target(gBattleWork.unk87, gBattleWork.unkA7, gBattleWork.unk88)) {
        gBattleWork.unkB8 = 4;
        gBattleWork.unkBF = 4;
    }
}

void determine_battle_target_mode(void) {
    if (check_can_target_bot(gBattleWork.unk87, gBattleWork.unkA7, gBattleWork.unk87)) {
        gBattleWork.unkB8 = 4;
        gBattleWork.unkBF = 2;
    } else if (check_battle_can_support_target(gBattleWork.unk87, gBattleWork.unkA7, gBattleWork.unk87)) {
        gBattleWork.unkB8 = 4;
        gBattleWork.unkBF = 3;
    } else if (check_battle_can_special_target(gBattleWork.unk87, gBattleWork.unkA7, gBattleWork.unk87)) {
        gBattleWork.unkB8 = 4;
        gBattleWork.unkBF = 4;
    }
}
