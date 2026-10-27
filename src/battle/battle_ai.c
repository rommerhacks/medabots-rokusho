// Robattle AI. For each part of a Medabot, ai_pick_bot_targets runs the target picker gAiTargetPickers[skill]
// (indexed by the part's skill id; attacks, Anti-Air / Anti-Sea, Stability, Recovery, Repair, Reactivate, charge and
// status skills) and the after-pick hook gAiAfterPick[skill] (ai_clear_target_part for skills that target a whole
// Medabot). The chosen target record + 1 and part + 1 go to the part's unkE / unkF.
// Each picker narrows the candidates in passes: first the bots that suit the skill and have a part of the user's
// Medal Aim skill type, then just the ones that suit the skill, then (usually) the Aim match alone, and last any
// present bot. ai_action_unusable runs gAiActionChecks[skill], which set gBattleWork.unk51 when the skill
// can't be used on the chosen target (battle_part_unusable). Reads the bot records gBattleBots.

#include "global.h"

static void ai_clear_target(void);
// 1 if rec has an unbroken part (of the first three) of skill type type.
static u32 bot_has_part_of_skill_type(u32 rec, u32 type);
static u32 ai_has_candidates(void);
// A random gBattleWork.unk61 candidate, as a record index.
static u32 ai_pick_random_candidate(void);
static void ai_store_target(u32 rec, u32 part);
static u32 bot_has_no_buff(u32 rec);
static u32 bot_has_no_status(u32 rec);
static u32 bot_head_has_uses(u32 rec);
static u32 bot_has_medaforce_charge(u32 rec);

// Picks a target for each of the three action parts of record rec.
void ai_pick_bot_targets(u32 rec) {
    u32 i;

    gBattleWork.unk5C = rec;
    gBattleWork.unk5D = 0;
    for (i = 0; i <= 2; i++) {
        ai_pick_part_target();
        ai_run_after_pick();
        gBattleWork.unk5D++;
    }
}

void ai_pick_part_target(void) {
    ai_clear_target();
    mem_fill8(gBattleWork.unk61, 3, 0);
    gAiTargetPickers[gBattleBots[gBattleWork.unk5C].parts[gBattleWork.unk5D].data[1]]();
}

void ai_run_after_pick(void) {
    gAiAfterPick[gBattleBots[gBattleWork.unk5C].parts[gBattleWork.unk5D].data[1]]();
}

// Attacks (Rifle..Press, Pushover, Sacrifice, TeamAttack): an opponent with a part of the Medal's Aim type.
void ai_target_attack(void) {
    u32 i;

    gBattleWork.unk60 = battle_enemy_side_first_record(gBattleWork.unk5C);
    for (i = 0; i <= 2; i++) {
        if (gBattleBots[gBattleWork.unk60].unk40 &&
            bot_has_part_of_skill_type(gBattleWork.unk60, gBattleBots[gBattleWork.unk5C].medal.unk6))
            gBattleWork.unk61[i] = gBattleWork.unk60 + 1;
        gBattleWork.unk60++;
    }
    if (ai_has_candidates())
        gBattleWork.unk5E = ai_pick_random_candidate() + 1;
    else {
        gBattleWork.unk60 = battle_enemy_side_first_record(gBattleWork.unk5C);
        gBattleWork.unk5E = select_random_battle_target(gBattleWork.unk60) + 1;
    }
    gBattleWork.unk5F = ai_random_target_part(gBattleWork.unk5E - 1) + 1;
    ai_store_target(gBattleWork.unk5C, gBattleWork.unk5D);
}

// Anti-Air: prefers opponents on Air legs.
void ai_target_anti_air(void) {
    u32 i;

    gBattleWork.unk60 = battle_enemy_side_first_record(gBattleWork.unk5C);
    for (i = 0; i <= 2; i++) {
        if (gBattleBots[gBattleWork.unk60].unk40 && gBattleBots[gBattleWork.unk60].parts[3].data[1] == SKILL_LEGS_AIR &&
            bot_has_part_of_skill_type(gBattleWork.unk60, gBattleBots[gBattleWork.unk5C].medal.unk6))
            gBattleWork.unk61[i] = gBattleWork.unk60 + 1;
        gBattleWork.unk60++;
    }
    if (ai_has_candidates())
        gBattleWork.unk5E = ai_pick_random_candidate() + 1;
    else {
        gBattleWork.unk60 = battle_enemy_side_first_record(gBattleWork.unk5C);
        for (i = 0; i <= 2; i++) {
            if (gBattleBots[gBattleWork.unk60].unk40 &&
                gBattleBots[gBattleWork.unk60].parts[3].data[1] == SKILL_LEGS_AIR)
                gBattleWork.unk61[i] = gBattleWork.unk60 + 1;
            gBattleWork.unk60++;
        }
        if (ai_has_candidates())
            gBattleWork.unk5E = ai_pick_random_candidate() + 1;
        else {
            gBattleWork.unk60 = battle_enemy_side_first_record(gBattleWork.unk5C);
            for (i = 0; i <= 2; i++) {
                if (gBattleBots[gBattleWork.unk60].unk40 &&
                    bot_has_part_of_skill_type(gBattleWork.unk60, gBattleBots[gBattleWork.unk5C].medal.unk6))
                    gBattleWork.unk61[i] = gBattleWork.unk60 + 1;
                gBattleWork.unk60++;
            }
            if (ai_has_candidates())
                gBattleWork.unk5E = ai_pick_random_candidate() + 1;
            else {
                gBattleWork.unk60 = battle_enemy_side_first_record(gBattleWork.unk5C);
                gBattleWork.unk5E = select_random_battle_target(gBattleWork.unk60) + 1;
            }
        }
    }
    gBattleWork.unk5F = ai_random_target_part(gBattleWork.unk5E - 1) + 1;
    ai_store_target(gBattleWork.unk5C, gBattleWork.unk5D);
}

// Anti-Sea: prefers opponents on Sea legs.
void ai_target_anti_sea(void) {
    u32 i;

    gBattleWork.unk60 = battle_enemy_side_first_record(gBattleWork.unk5C);
    for (i = 0; i <= 2; i++) {
        if (gBattleBots[gBattleWork.unk60].unk40 && gBattleBots[gBattleWork.unk60].parts[3].data[1] == SKILL_LEGS_SEA &&
            bot_has_part_of_skill_type(gBattleWork.unk60, gBattleBots[gBattleWork.unk5C].medal.unk6))
            gBattleWork.unk61[i] = gBattleWork.unk60 + 1;
        gBattleWork.unk60++;
    }
    if (ai_has_candidates())
        gBattleWork.unk5E = ai_pick_random_candidate() + 1;
    else {
        gBattleWork.unk60 = battle_enemy_side_first_record(gBattleWork.unk5C);
        for (i = 0; i <= 2; i++) {
            if (gBattleBots[gBattleWork.unk60].unk40 &&
                gBattleBots[gBattleWork.unk60].parts[3].data[1] == SKILL_LEGS_SEA)
                gBattleWork.unk61[i] = gBattleWork.unk60 + 1;
            gBattleWork.unk60++;
        }
        if (ai_has_candidates())
            gBattleWork.unk5E = ai_pick_random_candidate() + 1;
        else {
            gBattleWork.unk60 = battle_enemy_side_first_record(gBattleWork.unk5C);
            for (i = 0; i <= 2; i++) {
                if (gBattleBots[gBattleWork.unk60].unk40 &&
                    bot_has_part_of_skill_type(gBattleWork.unk60, gBattleBots[gBattleWork.unk5C].medal.unk6))
                    gBattleWork.unk61[i] = gBattleWork.unk60 + 1;
                gBattleWork.unk60++;
            }
            if (ai_has_candidates())
                gBattleWork.unk5E = ai_pick_random_candidate() + 1;
            else {
                gBattleWork.unk60 = battle_enemy_side_first_record(gBattleWork.unk5C);
                gBattleWork.unk5E = select_random_battle_target(gBattleWork.unk60) + 1;
            }
        }
    }
    gBattleWork.unk5F = ai_random_target_part(gBattleWork.unk5E - 1) + 1;
    ai_store_target(gBattleWork.unk5C, gBattleWork.unk5D);
}

// Stability: a teammate without Stability that has a negative status (unkC9) to clear.
void ai_target_stability(void) {
    u32 i;

    gBattleWork.unk60 = battle_side_first_record(gBattleWork.unk5C);
    for (i = 0; i <= 2; i++) {
        if (gBattleBots[gBattleWork.unk60].unk40 && battle_bot_lacks_stability(gBattleWork.unk60) &&
            gBattleBots[gBattleWork.unk60].unkC9 &&
            bot_has_part_of_skill_type(gBattleWork.unk60, gBattleBots[gBattleWork.unk5C].medal.unk6))
            gBattleWork.unk61[i] = gBattleWork.unk60 + 1;
        gBattleWork.unk60++;
    }
    if (ai_has_candidates())
        gBattleWork.unk5E = ai_pick_random_candidate() + 1;
    else {
        gBattleWork.unk60 = battle_side_first_record(gBattleWork.unk5C);
        for (i = 0; i <= 2; i++) {
            if (gBattleBots[gBattleWork.unk60].unk40 && battle_bot_lacks_stability(gBattleWork.unk60) &&
                gBattleBots[gBattleWork.unk60].unkC9)
                gBattleWork.unk61[i] = gBattleWork.unk60 + 1;
            gBattleWork.unk60++;
        }
        if (ai_has_candidates())
            gBattleWork.unk5E = ai_pick_random_candidate() + 1;
        else {
            gBattleWork.unk60 = battle_side_first_record(gBattleWork.unk5C);
            for (i = 0; i <= 2; i++) {
                if (gBattleBots[gBattleWork.unk60].unk40 && battle_bot_lacks_stability(gBattleWork.unk60) &&
                    bot_has_part_of_skill_type(gBattleWork.unk60, gBattleBots[gBattleWork.unk5C].medal.unk6))
                    gBattleWork.unk61[i] = gBattleWork.unk60 + 1;
                gBattleWork.unk60++;
            }
            if (ai_has_candidates())
                gBattleWork.unk5E = ai_pick_random_candidate() + 1;
            else {
                gBattleWork.unk60 = battle_side_first_record(gBattleWork.unk5C);
                gBattleWork.unk5E = select_random_battle_target(gBattleWork.unk60) + 1;
            }
        }
    }
    gBattleWork.unk5F = ai_random_target_part(gBattleWork.unk5E - 1) + 1;
    ai_store_target(gBattleWork.unk5C, gBattleWork.unk5D);
}

// Recovery: the teammate part that lost the most armor.
void ai_target_recovery(void) {
    u32 i;
    u32 part;

    gBattleWork.unk60 = battle_side_first_record(gBattleWork.unk5C);
    for (i = 0; i <= 2; i++) {
        if (gBattleBots[gBattleWork.unk60].unk40 && find_most_damaged_part(gBattleWork.unk60) &&
            bot_has_part_of_skill_type(gBattleWork.unk60, gBattleBots[gBattleWork.unk5C].medal.unk6))
            gBattleWork.unk61[i] = gBattleWork.unk60 + 1;
        gBattleWork.unk60++;
    }
    if (ai_has_candidates())
        gBattleWork.unk5E = ai_pick_random_candidate() + 1;
    else {
        gBattleWork.unk60 = battle_side_first_record(gBattleWork.unk5C);
        for (i = 0; i <= 2; i++) {
            if (gBattleBots[gBattleWork.unk60].unk40 && find_most_damaged_part(gBattleWork.unk60))
                gBattleWork.unk61[i] = gBattleWork.unk60 + 1;
            gBattleWork.unk60++;
        }
        if (ai_has_candidates())
            gBattleWork.unk5E = ai_pick_random_candidate() + 1;
        else {
            gBattleWork.unk60 = battle_side_first_record(gBattleWork.unk5C);
            for (i = 0; i <= 2; i++) {
                if (gBattleBots[gBattleWork.unk60].unk40 &&
                    bot_has_part_of_skill_type(gBattleWork.unk60, gBattleBots[gBattleWork.unk5C].medal.unk6))
                    gBattleWork.unk61[i] = gBattleWork.unk60 + 1;
                gBattleWork.unk60++;
            }
            if (ai_has_candidates())
                gBattleWork.unk5E = ai_pick_random_candidate() + 1;
            else {
                gBattleWork.unk60 = battle_side_first_record(gBattleWork.unk5C);
                gBattleWork.unk5E = select_random_battle_target(gBattleWork.unk60) + 1;
            }
        }
    }
    part = find_most_damaged_part(gBattleWork.unk5E - 1);
    if (part)
        gBattleWork.unk5F = part;
    else
        gBattleWork.unk5F = ai_random_target_part(gBattleWork.unk5E - 1) + 1;
    ai_store_target(gBattleWork.unk5C, gBattleWork.unk5D);
}

// AutoRecover, Boost Chrg: a teammate without Stability or a positive status (unkC4).
void ai_target_buff(void) {
    u32 i;

    gBattleWork.unk60 = battle_side_first_record(gBattleWork.unk5C);
    for (i = 0; i <= 2; i++) {
        if (gBattleBots[gBattleWork.unk60].unk40 && battle_bot_lacks_stability(gBattleWork.unk60) &&
            bot_has_no_buff(gBattleWork.unk60) &&
            bot_has_part_of_skill_type(gBattleWork.unk60, gBattleBots[gBattleWork.unk5C].medal.unk6))
            gBattleWork.unk61[i] = gBattleWork.unk60 + 1;
        gBattleWork.unk60++;
    }
    if (ai_has_candidates())
        gBattleWork.unk5E = ai_pick_random_candidate() + 1;
    else {
        gBattleWork.unk60 = battle_side_first_record(gBattleWork.unk5C);
        for (i = 0; i <= 2; i++) {
            if (gBattleBots[gBattleWork.unk60].unk40 && battle_bot_lacks_stability(gBattleWork.unk60) &&
                bot_has_no_buff(gBattleWork.unk60))
                gBattleWork.unk61[i] = gBattleWork.unk60 + 1;
            gBattleWork.unk60++;
        }
        if (ai_has_candidates())
            gBattleWork.unk5E = ai_pick_random_candidate() + 1;
        else {
            gBattleWork.unk60 = battle_side_first_record(gBattleWork.unk5C);
            for (i = 0; i <= 2; i++) {
                if (gBattleBots[gBattleWork.unk60].unk40 &&
                    bot_has_part_of_skill_type(gBattleWork.unk60, gBattleBots[gBattleWork.unk5C].medal.unk6))
                    gBattleWork.unk61[i] = gBattleWork.unk60 + 1;
                gBattleWork.unk60++;
            }
            if (ai_has_candidates())
                gBattleWork.unk5E = ai_pick_random_candidate() + 1;
            else {
                gBattleWork.unk60 = battle_side_first_record(gBattleWork.unk5C);
                gBattleWork.unk5E = select_random_battle_target(gBattleWork.unk60) + 1;
            }
        }
    }
    ai_store_target(gBattleWork.unk5C, gBattleWork.unk5D);
}

// Repair: a random broken part of a teammate.
void ai_target_repair(void) {
    u32 i;
    u32 part;

    gBattleWork.unk60 = battle_side_first_record(gBattleWork.unk5C);
    for (i = 0; i <= 2; i++) {
        if (gBattleBots[gBattleWork.unk60].unk40 && find_random_broken_part(gBattleWork.unk60) &&
            bot_has_part_of_skill_type(gBattleWork.unk60, gBattleBots[gBattleWork.unk5C].medal.unk6))
            gBattleWork.unk61[i] = gBattleWork.unk60 + 1;
        gBattleWork.unk60++;
    }
    if (ai_has_candidates())
        gBattleWork.unk5E = ai_pick_random_candidate() + 1;
    else {
        gBattleWork.unk60 = battle_side_first_record(gBattleWork.unk5C);
        for (i = 0; i <= 2; i++) {
            if (gBattleBots[gBattleWork.unk60].unk40 && find_random_broken_part(gBattleWork.unk60))
                gBattleWork.unk61[i] = gBattleWork.unk60 + 1;
            gBattleWork.unk60++;
        }
        if (ai_has_candidates())
            gBattleWork.unk5E = ai_pick_random_candidate() + 1;
        else {
            gBattleWork.unk60 = battle_side_first_record(gBattleWork.unk5C);
            for (i = 0; i <= 2; i++) {
                if (gBattleBots[gBattleWork.unk60].unk40 &&
                    bot_has_part_of_skill_type(gBattleWork.unk60, gBattleBots[gBattleWork.unk5C].medal.unk6))
                    gBattleWork.unk61[i] = gBattleWork.unk60 + 1;
                gBattleWork.unk60++;
            }
            if (ai_has_candidates())
                gBattleWork.unk5E = ai_pick_random_candidate() + 1;
            else {
                gBattleWork.unk60 = battle_side_first_record(gBattleWork.unk5C);
                gBattleWork.unk5E = select_random_battle_target(gBattleWork.unk60) + 1;
            }
        }
    }
    part = find_random_broken_part(gBattleWork.unk5E - 1);
    if (part)
        gBattleWork.unk5F = part;
    else
        gBattleWork.unk5F = ai_random_target_part(gBattleWork.unk5E - 1) + 1;
    ai_store_target(gBattleWork.unk5C, gBattleWork.unk5D);
}

// Reactivate: a teammate that is out of action (unkBA == 2).
void ai_target_reactivate(void) {
    u32 i;

    gBattleWork.unk60 = battle_side_first_record(gBattleWork.unk5C);
    for (i = 0; i <= 2; i++) {
        if (gBattleBots[gBattleWork.unk60].unkBA == 2 &&
            bot_has_part_of_skill_type(gBattleWork.unk60, gBattleBots[gBattleWork.unk5C].medal.unk6))
            gBattleWork.unk61[i] = gBattleWork.unk60 + 1;
        gBattleWork.unk60++;
    }
    if (ai_has_candidates())
        gBattleWork.unk5E = ai_pick_random_candidate() + 1;
    else {
        gBattleWork.unk60 = battle_side_first_record(gBattleWork.unk5C);
        for (i = 0; i <= 2; i++) {
            if (gBattleBots[gBattleWork.unk60].unkBA == 2)
                gBattleWork.unk61[i] = gBattleWork.unk60 + 1;
            gBattleWork.unk60++;
        }
        if (ai_has_candidates())
            gBattleWork.unk5E = ai_pick_random_candidate() + 1;
        else {
            gBattleWork.unk60 = battle_side_first_record(gBattleWork.unk5C);
            for (i = 0; i <= 2; i++) {
                if (bot_has_part_of_skill_type(gBattleWork.unk60, gBattleBots[gBattleWork.unk5C].medal.unk6))
                    gBattleWork.unk61[i] = gBattleWork.unk60 + 1;
                gBattleWork.unk60++;
            }
            if (ai_has_candidates())
                gBattleWork.unk5E = ai_pick_random_candidate() + 1;
            else {
                gBattleWork.unk60 = battle_side_first_record(gBattleWork.unk5C);
                gBattleWork.unk5E = select_random_battle_target(gBattleWork.unk60) + 1;
            }
        }
    }
    ai_store_target(gBattleWork.unk5C, gBattleWork.unk5D);
}

// Rapid Chrg: any teammate but the user.
void ai_target_rapid_chrg(void) {
    u32 i;

    gBattleWork.unk60 = battle_side_first_record(gBattleWork.unk5C);
    for (i = 0; i <= 2; i++) {
        if (gBattleBots[gBattleWork.unk60].unk40 && gBattleWork.unk60 != gBattleWork.unk5C &&
            bot_has_part_of_skill_type(gBattleWork.unk60, gBattleBots[gBattleWork.unk5C].medal.unk6))
            gBattleWork.unk61[i] = gBattleWork.unk60 + 1;
        gBattleWork.unk60++;
    }
    if (ai_has_candidates())
        gBattleWork.unk5E = ai_pick_random_candidate() + 1;
    else {
        gBattleWork.unk60 = battle_side_first_record(gBattleWork.unk5C);
        for (i = 0; i <= 2; i++) {
            if (gBattleBots[gBattleWork.unk60].unk40 && gBattleWork.unk60 != gBattleWork.unk5C)
                gBattleWork.unk61[i] = gBattleWork.unk60 + 1;
            gBattleWork.unk60++;
        }
        if (ai_has_candidates())
            gBattleWork.unk5E = ai_pick_random_candidate() + 1;
        else {
            gBattleWork.unk60 = battle_side_first_record(gBattleWork.unk5C);
            gBattleWork.unk5E = select_random_battle_target(gBattleWork.unk60) + 1;
        }
    }
    ai_store_target(gBattleWork.unk5C, gBattleWork.unk5D);
}

// Drain Chrg, Confusion, No Escape, No Defense: an opponent without Stability or a negative status.
void ai_target_status(void) {
    u32 i;

    gBattleWork.unk60 = battle_enemy_side_first_record(gBattleWork.unk5C);
    for (i = 0; i <= 2; i++) {
        if (gBattleBots[gBattleWork.unk60].unk40 && battle_bot_lacks_stability(gBattleWork.unk60) &&
            bot_has_no_status(gBattleWork.unk60) &&
            bot_has_part_of_skill_type(gBattleWork.unk60, gBattleBots[gBattleWork.unk5C].medal.unk6))
            gBattleWork.unk61[i] = gBattleWork.unk60 + 1;
        gBattleWork.unk60++;
    }
    if (ai_has_candidates())
        gBattleWork.unk5E = ai_pick_random_candidate() + 1;
    else {
        gBattleWork.unk60 = battle_enemy_side_first_record(gBattleWork.unk5C);
        for (i = 0; i <= 2; i++) {
            if (gBattleBots[gBattleWork.unk60].unk40 && battle_bot_lacks_stability(gBattleWork.unk60) &&
                bot_has_no_status(gBattleWork.unk60))
                gBattleWork.unk61[i] = gBattleWork.unk60 + 1;
            gBattleWork.unk60++;
        }
        if (ai_has_candidates())
            gBattleWork.unk5E = ai_pick_random_candidate() + 1;
        else {
            gBattleWork.unk60 = battle_enemy_side_first_record(gBattleWork.unk5C);
            for (i = 0; i <= 2; i++) {
                if (gBattleBots[gBattleWork.unk60].unk40 &&
                    bot_has_part_of_skill_type(gBattleWork.unk60, gBattleBots[gBattleWork.unk5C].medal.unk6))
                    gBattleWork.unk61[i] = gBattleWork.unk60 + 1;
                gBattleWork.unk60++;
            }
            if (ai_has_candidates())
                gBattleWork.unk5E = ai_pick_random_candidate() + 1;
            else {
                gBattleWork.unk60 = battle_enemy_side_first_record(gBattleWork.unk5C);
                gBattleWork.unk5E = select_random_battle_target(gBattleWork.unk60) + 1;
            }
        }
    }
    ai_store_target(gBattleWork.unk5C, gBattleWork.unk5D);
}

// Use Drain: an opponent whose head has uses left; aims at the head.
void ai_target_use_drain(void) {
    u32 i;

    gBattleWork.unk60 = battle_enemy_side_first_record(gBattleWork.unk5C);
    for (i = 0; i <= 2; i++) {
        if (gBattleBots[gBattleWork.unk60].unk40 && bot_head_has_uses(gBattleWork.unk60) &&
            bot_has_part_of_skill_type(gBattleWork.unk60, gBattleBots[gBattleWork.unk5C].medal.unk6))
            gBattleWork.unk61[i] = gBattleWork.unk60 + 1;
        gBattleWork.unk60++;
    }
    if (ai_has_candidates())
        gBattleWork.unk5E = ai_pick_random_candidate() + 1;
    else {
        gBattleWork.unk60 = battle_enemy_side_first_record(gBattleWork.unk5C);
        for (i = 0; i <= 2; i++) {
            if (gBattleBots[gBattleWork.unk60].unk40 && bot_head_has_uses(gBattleWork.unk60))
                gBattleWork.unk61[i] = gBattleWork.unk60 + 1;
            gBattleWork.unk60++;
        }
        if (ai_has_candidates())
            gBattleWork.unk5E = ai_pick_random_candidate() + 1;
        else {
            gBattleWork.unk60 = battle_enemy_side_first_record(gBattleWork.unk5C);
            for (i = 0; i <= 2; i++) {
                if (gBattleBots[gBattleWork.unk60].unk40 &&
                    bot_has_part_of_skill_type(gBattleWork.unk60, gBattleBots[gBattleWork.unk5C].medal.unk6))
                    gBattleWork.unk61[i] = gBattleWork.unk60 + 1;
                gBattleWork.unk60++;
            }
            if (ai_has_candidates())
                gBattleWork.unk5E = ai_pick_random_candidate() + 1;
            else {
                gBattleWork.unk60 = battle_enemy_side_first_record(gBattleWork.unk5C);
                gBattleWork.unk5E = select_random_battle_target(gBattleWork.unk60) + 1;
            }
        }
    }
    gBattleWork.unk5F = 1;
    ai_store_target(gBattleWork.unk5C, gBattleWork.unk5D);
}

// Forcedrain: an opponent with Medaforce charge.
void ai_target_forcedrain(void) {
    u32 i;

    gBattleWork.unk60 = battle_enemy_side_first_record(gBattleWork.unk5C);
    for (i = 0; i <= 2; i++) {
        if (gBattleBots[gBattleWork.unk60].unk40 && bot_has_medaforce_charge(gBattleWork.unk60) &&
            bot_has_part_of_skill_type(gBattleWork.unk60, gBattleBots[gBattleWork.unk5C].medal.unk6))
            gBattleWork.unk61[i] = gBattleWork.unk60 + 1;
        gBattleWork.unk60++;
    }
    if (ai_has_candidates())
        gBattleWork.unk5E = ai_pick_random_candidate() + 1;
    else {
        gBattleWork.unk60 = battle_enemy_side_first_record(gBattleWork.unk5C);
        for (i = 0; i <= 2; i++) {
            if (gBattleBots[gBattleWork.unk60].unk40 && bot_has_medaforce_charge(gBattleWork.unk60))
                gBattleWork.unk61[i] = gBattleWork.unk60 + 1;
            gBattleWork.unk60++;
        }
        if (ai_has_candidates())
            gBattleWork.unk5E = ai_pick_random_candidate() + 1;
        else {
            gBattleWork.unk60 = battle_enemy_side_first_record(gBattleWork.unk5C);
            for (i = 0; i <= 2; i++) {
                if (gBattleBots[gBattleWork.unk60].unk40 &&
                    bot_has_part_of_skill_type(gBattleWork.unk60, gBattleBots[gBattleWork.unk5C].medal.unk6))
                    gBattleWork.unk61[i] = gBattleWork.unk60 + 1;
                gBattleWork.unk60++;
            }
            if (ai_has_candidates())
                gBattleWork.unk5E = ai_pick_random_candidate() + 1;
            else {
                gBattleWork.unk60 = battle_enemy_side_first_record(gBattleWork.unk5C);
                gBattleWork.unk5E = select_random_battle_target(gBattleWork.unk60) + 1;
            }
        }
    }
    ai_store_target(gBattleWork.unk5C, gBattleWork.unk5D);
}

// Impair: like ai_target_status, aimed at a random intact part.
void ai_target_impair(void) {
    u32 i;

    gBattleWork.unk60 = battle_enemy_side_first_record(gBattleWork.unk5C);
    for (i = 0; i <= 2; i++) {
        if (gBattleBots[gBattleWork.unk60].unk40 && battle_bot_lacks_stability(gBattleWork.unk60) &&
            bot_has_no_status(gBattleWork.unk60) &&
            bot_has_part_of_skill_type(gBattleWork.unk60, gBattleBots[gBattleWork.unk5C].medal.unk6))
            gBattleWork.unk61[i] = gBattleWork.unk60 + 1;
        gBattleWork.unk60++;
    }
    if (ai_has_candidates())
        gBattleWork.unk5E = ai_pick_random_candidate() + 1;
    else {
        gBattleWork.unk60 = battle_enemy_side_first_record(gBattleWork.unk5C);
        for (i = 0; i <= 2; i++) {
            if (gBattleBots[gBattleWork.unk60].unk40 && battle_bot_lacks_stability(gBattleWork.unk60) &&
                bot_has_no_status(gBattleWork.unk60))
                gBattleWork.unk61[i] = gBattleWork.unk60 + 1;
            gBattleWork.unk60++;
        }
        if (ai_has_candidates())
            gBattleWork.unk5E = ai_pick_random_candidate() + 1;
        else {
            gBattleWork.unk60 = battle_enemy_side_first_record(gBattleWork.unk5C);
            for (i = 0; i <= 2; i++) {
                if (gBattleBots[gBattleWork.unk60].unk40 &&
                    bot_has_part_of_skill_type(gBattleWork.unk60, gBattleBots[gBattleWork.unk5C].medal.unk6))
                    gBattleWork.unk61[i] = gBattleWork.unk60 + 1;
                gBattleWork.unk60++;
            }
            if (ai_has_candidates())
                gBattleWork.unk5E = ai_pick_random_candidate() + 1;
            else {
                gBattleWork.unk60 = battle_enemy_side_first_record(gBattleWork.unk5C);
                gBattleWork.unk5E = select_random_battle_target(gBattleWork.unk60) + 1;
            }
        }
    }
    gBattleWork.unk5F = bot_random_intact_part(gBattleWork.unk5E - 1) + 1;
    ai_store_target(gBattleWork.unk5C, gBattleWork.unk5D);
}

static void ai_clear_target(void) {
    gBattleWork.unk5E = 0;
    gBattleWork.unk5F = 0;
    gBattleBots[gBattleWork.unk5C].parts[gBattleWork.unk5D].unkE = 0;
    gBattleBots[gBattleWork.unk5C].parts[gBattleWork.unk5D].unkF = 0;
}

u32 battle_enemy_side_first_record(u32 rec) {
    switch (rec) {
    case 0:
    case 1:
    case 2:
        return 3;
    default:
        return 0;
    }
}

u32 battle_side_first_record(u32 rec) {
    switch (rec) {
    case 0:
    case 1:
    case 2:
        return 0;
    default:
        return 3;
    }
}

static u32 bot_has_part_of_skill_type(u32 rec, u32 type) {
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gBattleBots[rec].parts[i].unk11 && gBattleBots[rec].parts[i].data[2] == type)
            return 1;
    }
    return 0;
}

static u32 ai_has_candidates(void) {
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gBattleWork.unk61[i])
            return 1;
    }
    return 0;
}

static u32 ai_pick_random_candidate(void) {
    u32 i, j, dir;

    i = rng_random_slot();
    dir = rng_next_byte() & 1;
    for (j = 0; j <= 2; j++) {
        if (gBattleWork.unk61[i])
            return gBattleWork.unk61[i] - 1;
        if (dir) {
            if (++i > 2)
                i = 0;
        } else if (i == 0)
            i = 2;
        else
            i--;
    }
    return gBattleWork.unk61[i];
}

// Random 0-2 (from gRandomSlots).
u32 rng_random_slot(void) {
    return gRandomSlots[rng_next_byte() & 0xF];
}

u32 select_random_battle_target(u32 base) {
    u32 i, j, dir;

    i = rng_random_slot();
    dir = rng_next_byte() & 1;
    for (j = 0; j <= 2; j++) {
        if (gBattleBots[base + i].unk40)
            return base + i;
        if (dir) {
            if (++i > 2)
                i = 0;
        } else if (i == 0)
            i = 2;
        else
            i--;
    }
    return base + i;
}

// Random part to aim at, weighted by which parts are intact (get_random_battle_weight_entry).
u32 ai_random_target_part(u32 idx) {
    return get_random_battle_weight_entry(idx);
}

u32 bot_random_intact_part(u32 rec) {
    u32 i, j, dir;

    i = rng_random_slot();
    dir = rng_next_byte() & 1;
    for (j = 0; j <= 2; j++) {
        if (gBattleBots[rec].parts[i].unk11)
            return i;
        if (dir) {
            if (++i > 2)
                i = 0;
        } else if (i == 0)
            i = 2;
        else
            i--;
    }
    return i;
}

static void ai_store_target(u32 rec, u32 part) {
    gBattleBots[rec].parts[part].unkE = gBattleWork.unk5E;
    gBattleBots[rec].parts[part].unkF = gBattleWork.unk5F;
}

u32 find_most_damaged_part(u32 rec) {
    u32 zero = 0;
    u32 i;

    CpuFastSet(&zero, (void *)0x02023000, 0x01000080);
    for (i = 0; i <= 3; i++) {
        SORT_BUFFER[i].value = i;
        if (gBattleBots[rec].parts[i].unk11 != 0 &&
            gBattleBots[rec].parts[i].unk11 != gBattleBots[rec].parts[i].data[4])
            SORT_BUFFER[i].key = gBattleBots[rec].parts[i].data[4] - gBattleBots[rec].parts[i].unk11;
    }
    sort_buffer_descending(4);
    if (SORT_BUFFER[0].key != 0)
        return SORT_BUFFER[0].value + 1;
    else
        return 0;
}

u32 battle_bot_lacks_stability(u32 rec) {
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gBattleBots[rec].parts[i].unk11 && gBattleBots[rec].parts[i].data[1] == SKILL_STABILITY)
            return 0;
    }
    return 1;
}

static u32 bot_has_no_buff(u32 rec) {
    if (gBattleBots[rec].unkC4 != 0)
        return 0;
    else
        return 1;
}

static u32 bot_has_no_status(u32 rec) {
    if (gBattleBots[rec].unkC9 != 0)
        return 0;
    else
        return 1;
}

u32 find_random_broken_part(u32 rec) {
    u32 i, slot, dir;

    slot = rng_next_byte() & 3;
    dir = rng_next_byte() & 1;
    for (i = 0; i <= 3; i++) {
        if (gBattleBots[rec].parts[slot].unk11 == 0)
            return slot + 1;
        if (dir)
            slot = (slot + 1) & 3;
        else
            slot = (slot - 1) & 3;
    }
    return 0;
}

static u32 bot_head_has_uses(u32 rec) {
    if (gBattleBots[rec].parts[0].unk10 != 0)
        return 1;
    else
        return 0;
}

static u32 bot_has_medaforce_charge(u32 rec) {
    if (gBattleBots[rec].unkC1 != 0)
        return 1;
    else
        return 0;
}

// gAiAfterPick: the skill targets the whole Medabot, not one part.
void ai_clear_target_part(void) {
    gBattleBots[gBattleWork.unk5C].parts[gBattleWork.unk5D].unkF = 0;
}

// 1 if the skill of rec's part (1-3) can't be used on its chosen target (gAiActionChecks).
u32 ai_action_unusable(u32 rec, u32 part) {
    gBattleWork.unk51 = 0;
    gBattleWork.unk5C = rec;
    gBattleWork.unk5D = --part;
    gAiActionChecks[gBattleBots[rec].parts[part].data[1]]();
    return gBattleWork.unk51;
}

// Break Form: needs a trap or Team Form laid by the other side.
void ai_check_break_form(void) {
    if (gBattleWork.unk28[bot_side_index(gBattleWork.unk5C, 0)].active == 0)
        gBattleWork.unk51 = 1;
}

// Stability: needs a target with a negative status.
void ai_check_stability(void) {
    if (gBattleBots[gBattleBots[gBattleWork.unk5C].parts[gBattleWork.unk5D].unkE - 1].unkC9 == 0)
        gBattleWork.unk51 = 1;
}

// Cancel*, Accel Chrg, Strengthen: never chosen as an action.
void ai_check_never(void) {
    gBattleWork.unk51 = 1;
}

// Defence, Full Block, Half Block: need a teammate to guard.
void ai_check_guard(void) {
    u32 i, n;

    gBattleWork.unk60 = battle_side_first_record(gBattleWork.unk5C);
    for (i = 0, n = 0; i <= 2; i++) {
        if (gBattleBots[gBattleWork.unk60 + i].unk40)
            n++;
    }
    if (n <= 1)
        gBattleWork.unk51 = 1;
}

// Recovery: the target part must be damaged but not broken.
void ai_check_recovery(void) {
    if (gBattleBots[gBattleBots[gBattleWork.unk5C].parts[gBattleWork.unk5D].unkE - 1]
                .parts[gBattleBots[gBattleWork.unk5C].parts[gBattleWork.unk5D].unkF - 1]
                .unk11 == 0 ||
        gBattleBots[gBattleBots[gBattleWork.unk5C].parts[gBattleWork.unk5D].unkE - 1]
                .parts[gBattleBots[gBattleWork.unk5C].parts[gBattleWork.unk5D].unkF - 1]
                .unk11 == gBattleBots[gBattleBots[gBattleWork.unk5C].parts[gBattleWork.unk5D].unkE - 1]
                              .parts[gBattleBots[gBattleWork.unk5C].parts[gBattleWork.unk5D].unkF - 1]
                              .data[4])
        gBattleWork.unk51 = 1;
}

// AutoRecover, Boost Chrg: target without a positive status or Stability.
void ai_check_buff(void) {
    u32 rec = gBattleBots[gBattleWork.unk5C].parts[gBattleWork.unk5D].unkE - 1;

    if (gBattleBots[rec].unkC4 != 0 || battle_bot_lacks_stability(rec) == 0)
        gBattleWork.unk51 = 1;
}

// Drain Chrg, Impair, Confusion, No Escape, No Defense: target without a negative status or Stability.
void ai_check_status(void) {
    if (gBattleBots[gBattleBots[gBattleWork.unk5C].parts[gBattleWork.unk5D].unkE - 1].unkC9 != 0)
        gBattleWork.unk51 = 1;
    if (battle_bot_lacks_stability(gBattleBots[gBattleWork.unk5C].parts[gBattleWork.unk5D].unkE - 1) == 0)
        gBattleWork.unk51 = 1;
}

// Repair: the target part must be broken.
void ai_check_repair(void) {
    if (gBattleBots[gBattleBots[gBattleWork.unk5C].parts[gBattleWork.unk5D].unkE - 1]
            .parts[gBattleBots[gBattleWork.unk5C].parts[gBattleWork.unk5D].unkF - 1]
            .unk11 != 0)
        gBattleWork.unk51 = 1;
}

// Reactivate: the target must be out of action.
void ai_check_reactivate(void) {
    if (gBattleBots[gBattleBots[gBattleWork.unk5C].parts[gBattleWork.unk5D].unkE - 1].unkBA != 2)
        gBattleWork.unk51 = 1;
}

// Rapid Chrg: not on the user itself.
void ai_check_rapid_chrg(void) {
    if (gBattleBots[gBattleWork.unk5C].parts[gBattleWork.unk5D].unkE - 1 == gBattleWork.unk5C)
        gBattleWork.unk51 = 1;
}

// Use Drain: the target's head must have uses left.
void ai_check_use_drain(void) {
    if (gBattleBots[gBattleBots[gBattleWork.unk5C].parts[gBattleWork.unk5D].unkE - 1].parts[0].unk10 == 0)
        gBattleWork.unk51 = 1;
}

// Forcedrain: the target must have Medaforce charge.
void ai_check_forcedrain(void) {
    if (gBattleBots[gBattleBots[gBattleWork.unk5C].parts[gBattleWork.unk5D].unkE - 1].unkC1 == 0)
        gBattleWork.unk51 = 1;
}

// TeamAttack: needs the side's Team Form.
void ai_check_team_attack(void) {
    if (gBattleWork.unk28[bot_side_index(gBattleWork.unk5C, 1)].active == 0 ||
        gBattleWork.unk28[bot_side_index(gBattleWork.unk5C, 1)].skill != SKILL_TEAM_FORM)
        gBattleWork.unk51 = 1;
}

// Grap Trap: an opponent must have a Strike or Berserk part.
void ai_check_grap_trap(void) {
    u32 i, j;

    gBattleWork.unk60 = battle_enemy_side_first_record(gBattleWork.unk5C);
    for (i = 0; i <= 2; i++) {
        if (gBattleBots[gBattleWork.unk60 + i].unk40) {
            for (j = 0; j <= 2; j++) {
                if (gBattleBots[gBattleWork.unk60 + i].parts[j].unk11) {
                    if (gBattleBots[gBattleWork.unk60 + i].parts[j].data[2] == SKILL_TYPE_STRIKE)
                        return;
                    if (gBattleBots[gBattleWork.unk60 + i].parts[j].data[2] == SKILL_TYPE_BERSERK)
                        return;
                }
            }
        }
    }
    gBattleWork.unk51 = 1;
}

// Shot Trap: an opponent must have a Shoot or Aim Shot part.
void ai_check_shot_trap(void) {
    u32 i, j;

    gBattleWork.unk60 = battle_enemy_side_first_record(gBattleWork.unk5C);
    for (i = 0; i <= 2; i++) {
        if (gBattleBots[gBattleWork.unk60 + i].unk40) {
            for (j = 0; j <= 2; j++) {
                if (gBattleBots[gBattleWork.unk60 + i].parts[j].unk11) {
                    if (gBattleBots[gBattleWork.unk60 + i].parts[j].data[2] == SKILL_TYPE_SHOOT)
                        return;
                    if (gBattleBots[gBattleWork.unk60 + i].parts[j].data[2] == SKILL_TYPE_AIM_SHOT)
                        return;
                }
            }
        }
    }
    gBattleWork.unk51 = 1;
}

// Team Form: a teammate must have a TeamAttack part.
void ai_check_team_form(void) {
    u32 i, j;

    gBattleWork.unk60 = battle_side_first_record(gBattleWork.unk5C);
    for (i = 0; i <= 2; i++) {
        if (gBattleBots[gBattleWork.unk60 + i].unk40) {
            for (j = 0; j <= 2; j++) {
                if (gBattleBots[gBattleWork.unk60 + i].parts[j].unk11 &&
                    gBattleBots[gBattleWork.unk60 + i].parts[j].data[1] == SKILL_TEAM_ATTACK)
                    return;
            }
        }
    }
    gBattleWork.unk51 = 1;
}
