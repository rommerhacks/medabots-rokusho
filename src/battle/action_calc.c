// Action calculations for the action script (battle/action_script): action speed, damage modifiers and
// thresholds, turn speed, the strongest part, and the AI's action type and target mode
// (select_ai_action_type, determine_battle_target_mode). Uses the checks in battle/combat_helpers.

#include "global.h"

static u32 battle_calculate_damage_modifier(void);
static u32 battle_calculate_turn_speed(void);
static void battle_process_speed_and_action(void);
static u32 sub_08039134(u32 rec);
static u32 battle_find_strongest_part(u32 rec);

void sub_08038BC0(void) {
    gUnk_03001800.unkE8 = 0;
    calc_battle_action_speed(gUnk_03001800.unk87, gUnk_03001800.unkA7);
    if (check_bot_ability_type_strike(gUnk_03001800.unk87, gUnk_03001800.unkA7, gUnk_03001800.unk88))
        gUnk_03001800.unkE8 += gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03001800.unkA7].data[5] << 4;
    if (check_bot_ability_type_shoot(gUnk_03001800.unk87, gUnk_03001800.unkA7, gUnk_03001800.unk88))
        gUnk_03001800.unkE8 += gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03001800.unkA7].data[5] << 4;
    if (gUnk_03000590[gUnk_03001800.unk87].unkD6 & 4)
        gUnk_03001800.unkE8 += gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03001800.unkA7].data[5];
    gUnk_03001800.unkE8 += gUnk_03001800.unk28[gUnk_03001800.unk89].unk0;
    sub_080358F0(gUnk_03001800.unk87);
    if (gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03001800.unkA7].data[1] == 8)
        goto add;
    if (gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03001800.unkA7].data[1] == 9) {
    add:
        gUnk_03001800.unkE8 += gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03001800.unkA7].data[5];
    }
    if (gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03001800.unkA7].data[1] == 0x34 &&
        gUnk_03001800.unk28[gUnk_03001800.unk8A].unk3 == 0x33)
        gUnk_03001800.unkE8 += gUnk_03001800.unk28[gUnk_03001800.unk8A].unk4;
    apply_battle_bot_damage_reduction(gUnk_03001800.unk87);
    sub_08035754(&gUnk_03001800.unkE8, gUnk_03000590[gUnk_03001800.unk88].unkB9);
}

void sub_08038D30(void) {
    gUnk_03000590[gUnk_03001800.unk88].unkBC &= 3;
    gUnk_03000590[gUnk_03001800.unk88].unkBD |= 2;
    if (gUnk_03001800.unkDE) {
        gUnk_03000590[gUnk_03001800.unk88].unkBC |= 0xC;
        gUnk_03001800.unkF2 = gUnk_03001800.unkE8;
        gUnk_03001800.unkAB = 1;
        if ((gUnk_03000590[gUnk_03001800.unk88].unkC0 & 1) && (rng_next_080424B8() & 1)) {
            gUnk_03001800.unkF6 = 1;
            gUnk_03001800.unkB7 = 3;
        }
    } else if (!(gUnk_03000590[gUnk_03001800.unk87].unkC0 & 4) && (gUnk_03000590[gUnk_03001800.unk88].unkBD & 0x10) &&
               gUnk_03000590[gUnk_03001800.unk88].parts[gUnk_03000590[gUnk_03001800.unk88].unkDE - 1].unk11) {
        gUnk_03000590[gUnk_03001800.unk88].unkBC |= 0xC;
        gUnk_03001800.unkF2 = gUnk_03001800.unkE8;
        sub_08035944(gUnk_03001800.unk87, gUnk_03000590[gUnk_03001800.unk88].unkDE);
        gUnk_03001800.unkF6 = 1;
        gUnk_03001800.unkAB = 1;
    } else {
        gUnk_03001800.unkAB = 0;
    }
}

void battle_begin_action_phase(void) {
    gUnk_03001800.unkEE = 0;
    if ((gUnk_03000590[gUnk_03001800.unk88].unkBC & 4) && (gUnk_03000590[gUnk_03001800.unk88].unkBC & 8))
        battle_calculate_damage_modifier();
    else if (!battle_calculate_turn_speed())
        battle_process_speed_and_action();
}

static u32 battle_calculate_damage_modifier(void) {
    u8 type;

    if (check_bot_ability_type_strike(gUnk_03001800.unk87, gUnk_03001800.unkA7, gUnk_03001800.unk88)) {
        if (battle_check_damage_threshold(gUnk_03001800.unkEE))
            return 1;
        return 0;
    }
    if (check_bot_ability_type_shoot(gUnk_03001800.unk87, gUnk_03001800.unkA7, gUnk_03001800.unk88)) {
        if (battle_check_damage_threshold(gUnk_03001800.unkEE))
            return 1;
        return 0;
    }
    type = gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03001800.unkA7].data[2];
    if (type == 3) {
        if (battle_check_damage_threshold(gUnk_03001800.unkEE * 2))
            return 1;
        return 0;
    }
    if (type == 0) {
        if (battle_check_damage_threshold(gUnk_03001800.unkEE * 4))
            return 1;
        return 0;
    }
    if (battle_check_damage_threshold(gUnk_03001800.unkEE * 8))
        return 1;
    return 0;
}

u32 battle_check_damage_threshold(s16 v) {
    if (gUnk_03001800.unkE8 > v) {
        gUnk_03001800.unkEE = 0;
        gUnk_03000590[gUnk_03001800.unk88].unkBC |= 0x4C;
        gUnk_03001800.unkF2 = gUnk_03001800.unkE8;
        return 1;
    }
    return 0;
}

static u32 battle_calculate_turn_speed(void) {
    gUnk_03001800.unkEE = 0;
    if (!(gUnk_03000590[gUnk_03001800.unk88].unkBC & 4)) {
        accumulate_battle_speed_value(gUnk_03001800.unk88);
        gUnk_03001800.unkEE += gUnk_03000590[gUnk_03001800.unk88].parts[3].unk13;
        if (!(gUnk_03000590[gUnk_03001800.unk88].unkBC & 8))
            sub_08035754((s16 *)&gUnk_03001800.unkEE, 8);
        if (battle_calculate_damage_modifier())
            return 1;
        sub_08035754(&gUnk_03001800.unkE8, (s16)gUnk_03001800.unkEE);
        if ((gUnk_03001800.unkF2 = gUnk_03001800.unkE8) == 0) {
            u8 type = gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03001800.unkA7].data[1];
            if (type == 6)
                return 0;
            if (type == 7)
                return 0;
            if (!(gUnk_03000590[gUnk_03001800.unk87].unkD6 & 2)) {
                gUnk_03000590[gUnk_03001800.unk88].unkBC |= 0x10;
                return 1;
            }
        }
    }
    return 0;
}

static void battle_process_speed_and_action(void) {
    u32 part;

    gUnk_03001800.unkEE = 0;
    gUnk_03001800.unkF2 = gUnk_03001800.unkE8;
    if (!(gUnk_03000590[gUnk_03001800.unk88].unkBC & 8)) {
        accumulate_battle_speed_value(gUnk_03001800.unk88);
        gUnk_03001800.unkEE += gUnk_03000590[gUnk_03001800.unk88].parts[3].unk14;
        if (!(gUnk_03000590[gUnk_03001800.unk88].unkBC & 4))
            sub_08035754((s16 *)&gUnk_03001800.unkEE, 8);
        if (!battle_calculate_damage_modifier() && (s16)gUnk_03001800.unkEE > 0x1F) {
            sub_08035754(&gUnk_03001800.unkE8, (s16)gUnk_03001800.unkEE);
            gUnk_03001800.unkF2 = gUnk_03001800.unkE8;
            gUnk_03000590[gUnk_03001800.unk88].unkBC |= 0x20;
            if (sub_08039134(gUnk_03001800.unk88) == 1)
                part = 1;
            else
                part = battle_find_strongest_part(gUnk_03001800.unk88);
            sub_08035944(gUnk_03001800.unk87, part);
        }
    }
}

static u32 sub_08039134(u32 rec) {
    u32 n = 0;
    u32 i;

    for (i = 0; i <= 3; i++)
        if (gUnk_03000590[rec].parts[i].unk11)
            n++;
    return n;
}

static u32 battle_find_strongest_part(u32 rec) {
    u32 best = 0;
    u32 i;
    u32 idx;

    for (i = 3; i != 0; i--) {
        u8 a = gUnk_03000590[rec].parts[i].unk11;
        if (a && a > best) {
            idx = i;
            best = a;
        }
    }
    return idx + 1;
}

void sub_08039188(void) {
    u8 f = gUnk_03000590[gUnk_03001800.unk88].unkBC & 0x10;
    if (f) {
        gUnk_03001800.unkAB = 1;
        gUnk_03001800.unkB7 = 1;
    } else {
        gUnk_03001800.unkAB = f;
    }
}

void sub_080391C4(void) {
    if (check_bot_can_shoot(gUnk_03001800.unk87, gUnk_03001800.unkA7, gUnk_03001800.unk88)) {
        gUnk_03001800.unkB8 = 2;
        gUnk_03001800.unkBE = 2;
    } else if (check_bot_can_support(gUnk_03001800.unk87, gUnk_03001800.unkA7, gUnk_03001800.unk88)) {
        gUnk_03001800.unkB8 = 2;
        gUnk_03001800.unkBE = 3;
    } else if (check_bot_can_use_shoot_part(gUnk_03001800.unk87, gUnk_03001800.unkA7, gUnk_03001800.unk88)) {
        gUnk_03001800.unkB8 = 2;
        gUnk_03001800.unkBE = 4;
    } else if (check_bot_status_effect_4(gUnk_03001800.unk87, gUnk_03001800.unkA7, gUnk_03001800.unk88)) {
        gUnk_03001800.unkB8 = 2;
        gUnk_03001800.unkBE = 6;
    }
}

void select_ai_action_type(void) {
    if (check_bot_can_shoot(gUnk_03001800.unk87, gUnk_03001800.unkA7, gUnk_03001800.unk87)) {
        gUnk_03001800.unkB8 = 2;
        gUnk_03001800.unkBE = 2;
    } else if (check_bot_can_support(gUnk_03001800.unk87, gUnk_03001800.unkA7, gUnk_03001800.unk87)) {
        gUnk_03001800.unkB8 = 2;
        gUnk_03001800.unkBE = 3;
    } else if (check_bot_can_use_shoot_part(gUnk_03001800.unk87, gUnk_03001800.unkA7, gUnk_03001800.unk87)) {
        gUnk_03001800.unkB8 = 2;
        gUnk_03001800.unkBE = 4;
    } else if (check_bot_status_effect_4(gUnk_03001800.unk87, gUnk_03001800.unkA7, gUnk_03001800.unk87)) {
        gUnk_03001800.unkB8 = 2;
        gUnk_03001800.unkBE = 6;
    }
}

void sub_080392D8(void) {
    if (check_can_target_bot(gUnk_03001800.unk87, gUnk_03001800.unkA7, gUnk_03001800.unk88)) {
        gUnk_03001800.unkB8 = 4;
        gUnk_03001800.unkBF = 2;
    } else if (check_battle_can_support_target(gUnk_03001800.unk87, gUnk_03001800.unkA7, gUnk_03001800.unk88)) {
        gUnk_03001800.unkB8 = 4;
        gUnk_03001800.unkBF = 3;
    } else if (check_battle_can_special_target(gUnk_03001800.unk87, gUnk_03001800.unkA7, gUnk_03001800.unk88)) {
        gUnk_03001800.unkB8 = 4;
        gUnk_03001800.unkBF = 4;
    }
}

void determine_battle_target_mode(void) {
    if (check_can_target_bot(gUnk_03001800.unk87, gUnk_03001800.unkA7, gUnk_03001800.unk87)) {
        gUnk_03001800.unkB8 = 4;
        gUnk_03001800.unkBF = 2;
    } else if (check_battle_can_support_target(gUnk_03001800.unk87, gUnk_03001800.unkA7, gUnk_03001800.unk87)) {
        gUnk_03001800.unkB8 = 4;
        gUnk_03001800.unkBF = 3;
    } else if (check_battle_can_special_target(gUnk_03001800.unk87, gUnk_03001800.unkA7, gUnk_03001800.unk87)) {
        gUnk_03001800.unkB8 = 4;
        gUnk_03001800.unkBF = 4;
    }
}
