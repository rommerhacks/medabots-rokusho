// The Medabots in a battle (gBattleBots, 6 records: 0-2 player, 3-5 opponent): team setup from the
// player's Medals and parts, opponent setup, then each turn's action processing, part and Medaforce
// selection and the AI's part order. Called from battle/robattle and battle/prebattle.

#include "global.h"

static void copy_player_medals_to_battle_bots(void);
static u32 battle_dispatch_action_by_type(u32 rec);
static u32 opponent_medaforce_locked(u32 rec);
static u32 battle_part_unusable(u32 rec, u32 part);

void clear_battle_bot_array(void) {
    mem_fill8((u8 *)gBattleBots, 0x600, 0);
}

void count_active_battle_bots(void) {
    u32 i;
    u32 n;

    for (i = 0, n = 0; i <= 2; i++) {
        if (gBattleWork.teamPicks[i])
            n++;
    }
    gBattleWork.teamCount = n;
    gBattleWork.unk5B = gBattleWork.opponentCount;
}

void battle_setup_team_bots(void) {
    copy_player_medals_to_battle_bots();
    copy_team_slots_to_battle_bots();
    battle_bots_load_parts(0, gBattleWork.teamCount);
}

static void copy_player_medals_to_battle_bots(void) {
    u32 i;

    for (i = 0; i < gBattleWork.teamCount; i++)
        memcpy_bytes_0803F63C(&gMedals[find_medal_slot_by_id(gTeamSlots[gBattleWork.teamPicks[i] & 0xF].medal) - 1],
                              &gBattleBots[i], 0x40);
}

void copy_team_slots_to_battle_bots(void) {
    u32 i;

    for (i = 0; i < gBattleWork.teamCount; i++)
        memcpy_bytes_0803F63C(&gTeamSlots[gBattleWork.teamPicks[i] & 0xF], &gBattleBots[i].teamState, 8);
}

void battle_bots_load_parts(u32 rec, u32 n) {
    u32 i;

    for (i = 0; i < n; rec++, i++) {
        gBattleBots[rec].index = rec;
        gBattleBots[rec].present = 1;
        load_part_data(gBattleBots[rec].head, 0, &gGameWork.partAbility);
        memcpy_bytes_0803F63C(&gGameWork.partAbility, gBattleBots[rec].parts[0].data, 0xD);
        gBattleBots[rec].parts[0].unk10 = gBattleBots[rec].parts[0].data[8];
        gBattleBots[rec].parts[0].unk11 = gBattleBots[rec].parts[0].data[4];
        gBattleBots[rec].parts[0].unk17 = gBattleBots[rec].head;
        load_part_data(gBattleBots[rec].rightArm, 1, &gGameWork.partAbility);
        memcpy_bytes_0803F63C(&gGameWork.partAbility, gBattleBots[rec].parts[1].data, 0xD);
        gBattleBots[rec].parts[1].unk11 = gBattleBots[rec].parts[1].data[4];
        gBattleBots[rec].parts[1].unk17 = gBattleBots[rec].rightArm;
        load_part_data(gBattleBots[rec].leftArm, 2, &gGameWork.partAbility);
        memcpy_bytes_0803F63C(&gGameWork.partAbility, gBattleBots[rec].parts[2].data, 0xD);
        gBattleBots[rec].parts[2].unk11 = gBattleBots[rec].parts[2].data[4];
        gBattleBots[rec].parts[2].unk17 = gBattleBots[rec].leftArm;
        load_part_data(gBattleBots[rec].legs, 3, &gGameWork.partAbility);
        memcpy_bytes_0803F63C(&gGameWork.partAbility, gBattleBots[rec].parts[3].data, 0xD);
        memcpy_bytes_0803F63C(&gBattleBots[rec].parts[3].data[4], &gBattleBots[rec].parts[3].unk11, 6);
        gBattleBots[rec].parts[3].unk17 = gBattleBots[rec].legs;
    }
}

void init_opponent_bots(void) {
    u32 i;

    for (i = 0; i < gBattleWork.unk5B; i++)
        init_enemy_bot_medal(i);
    init_opponent_bot_slots();
    battle_bots_load_parts(3, gBattleWork.unk5B);
}

void init_enemy_bot_medal(u8 i) {
    u32 k;
    u32 v;
    u32 lvl;

    memcpy_bytes_08041D04(gUnk_083B6158[gBattleWork.encounterBots[i].unk4], &gGameWork.partAbility, 16);
    gBattleBots[i + 3].medal.flags = 0x80;
    gBattleBots[i + 3].medal.graphicId = (&gGameWork.partAbility)[0];
    gBattleBots[i + 3].medal.attribute = (&gGameWork.partAbility)[1];
    gBattleBots[i + 3].medal.level = gBattleWork.encounterBots[i].unk5;
    gBattleBots[i + 3].medal.aimSkillType = (&gGameWork.partAbility)[2];
    gBattleBots[i + 3].medal.compatibility = (&gGameWork.partAbility)[7];
    gBattleBots[i + 3].medal.rotationLen = gBattleWork.encounterBots[i].unkA;
    memcpy_bytes_08041D04((const void *)gUnk_083BA4D8[gBattleWork.encounterBots[i].parts[0]],
                          gBattleBots[i + 3].medal.name, 0xE);
    for (k = 0; k <= 3; k++) {
        gBattleBots[i + 3].medal.rotation[k * 2] = gBattleWork.encounterBots[i].unk6[k] >> 4;
        gBattleBots[i + 3].medal.rotation[k * 2 + 1] = gBattleWork.encounterBots[i].unk6[k] & 0xF;
    }
    for (k = 0; k <= 7; k++) {
        v = gMedalAttributeBaseSkills[gBattleBots[i + 3].medal.attribute * 8 + k];
        lvl = gBattleBots[i + 3].medal.level >> 1;
        if (lvl)
            v *= lvl;
        if (v == 0)
            v = 1;
        else if (v > 100)
            v = 100;
        gBattleBots[i + 3].medal.skillLevel[k] = v;
    }
}

void init_opponent_bot_slots(void) {
    u32 i;

    for (i = 0; i < gBattleWork.unk5B; i++) {
        gBattleBots[i + 3].teamState = 3;
        load_part_data(gBattleWork.encounterBots[i].parts[0], 0, &gGameWork.partAbility);
        gBattleBots[i + 3].gender = (&gGameWork.partAbility)[3];
        gBattleBots[i + 3].medalId = gBattleBots[i + 3].medal.graphicId;
        gBattleBots[i + 3].head = gBattleWork.encounterBots[i].parts[0];
        gBattleBots[i + 3].rightArm = gBattleWork.encounterBots[i].parts[1];
        gBattleBots[i + 3].leftArm = gBattleWork.encounterBots[i].parts[2];
        gBattleBots[i + 3].legs = gBattleWork.encounterBots[i].parts[3];
    }
}

void battle_pick_all_ai_targets(void) {
    u32 i;

    if (gGameWork.skipBotSetup != 1 || gLinkPlayerId == 0) {
        for (i = 0; i <= 5; i++) {
            if (gBattleBots[i].teamState)
                ai_pick_bot_targets(i);
        }
    } else {
        for (i = 3; i <= 5; i++) {
            if (gBattleBots[i].teamState)
                ai_pick_bot_targets(i);
        }
        for (i = 0; i <= 2; i++) {
            if (gBattleBots[i].teamState)
                ai_pick_bot_targets(i);
        }
    }
}

void battle_process_bot_actions_for_side(u32 side) {
    u32 i;
    u32 rec;

    for (i = 0; i <= 2; i++) {
        rec = side + i;
        if (gBattleBots[side + i].teamState && battle_dispatch_action_by_type(rec))
            select_bot_battle_action(rec);
    }
}

void process_bot_battle_turn(u32 rec) {
    if (gBattleBots[rec].statusType == 0x2C)
        select_bot_battle_action(rec);
    else if (battle_dispatch_action_by_type(rec))
        select_bot_battle_action(rec);
}

static u32 battle_dispatch_action_by_type(u32 rec) {
    u32 type = gBattleBots[rec].medal.rotation[gBattleBots[rec].medal.rotationPos];

    switch (type) {
    case 0:
        return 1;
    case 1:
    case 2:
    case 3:
        if (battle_part_unusable(rec, type))
            return 1;
        battle_bot_select_part(rec, type);
        return 0;
    case 4:
        battle_bot_select_part(rec, 0);
        return 0;
    case 5:
    case 6:
    case 7:
        if (check_medaforce_availability(rec, type - 5, 0))
            return 1;
        return 0;
    }
}

void battle_bot_advance_rotation(u32 rec) {
    if (++gBattleBots[rec].medal.rotationPos == 8)
        gBattleBots[rec].medal.rotationPos = gBattleBots[rec].medal.rotationLen;
}

static void battle_advance_all_rotations(void) {
    u32 i;

    for (i = 0; i <= 5; i++) {
        if (gBattleBots[i].teamState)
            battle_bot_advance_rotation(i);
    }
}

void select_bot_battle_action(u32 rec) {
    u32 i;

    if (gBattleBots[rec].medaforceGauge == 0x50 && (rng_next_byte() & 1) && !check_medaforce_availability(rec, 0, 1))
        return;
    battle_ai_roll_part_order();
    for (i = 0; i <= 3; i++) {
        if (gBattleWork.unk64[i] == 0xFF) {
            battle_bot_select_part(rec, 0);
            return;
        }
        if (!battle_part_unusable(rec, gBattleWork.unk64[i])) {
            battle_bot_select_part(rec, gBattleWork.unk64[i]);
            return;
        }
    }
    battle_bot_select_part(rec, 0);
}

// Effect B type 0x2B disables the part in unkCA.
u32 part_blocked_by_effect(u32 rec, u32 part) {
    if (gBattleBots[rec].statusType == 0x2B && gBattleBots[rec].statusPart == part)
        return 1;
    return 0;
}

static u32 head_out_of_uses(u32 rec, u32 part) {
    if (part == 1 && gBattleBots[rec].parts[0].unk10 == 0)
        return 1;
    return 0;
}

static u32 part_is_broken(u32 rec, u32 part) {
    if (gBattleBots[rec].parts[part - 1].unk11 == 0)
        return 1;
    return 0;
}

// Side index (0 team, 1 opponents) of record a, or of the opposite side when b is nonzero.
u32 bot_side_index(u32 a, u32 b) {
    if (b == 0) {
        if (a <= 2)
            return 0;
        return 1;
    }
    if (a <= 2)
        return 1;
    return 0;
}

void battle_bot_select_part(u32 rec, u32 part) {
    gBattleBots[rec].chosenAction = part;
    if (part == 0)
        return;
    if (part <= 3) {
        gBattleBots[rec].unkE0 = gBattleBots[rec].parts[part - 1].unkE;
        gBattleBots[rec].unkE1 = gBattleBots[rec].parts[part - 1].unkF;
    }
}

u32 check_medaforce_availability(u32 rec, u32 slot, u32 random) {
    u32 i;

    if (opponent_medaforce_locked(rec) || gBattleWork.medaforceBlocked || gBattleBots[rec].medaforceGauge != 0x50)
        return 1;
    if (random)
        slot = rng_random_slot();
    for (i = 0; i <= 2; i++) {
        if (slot == 0) {
            if (gBattleBots[rec].medal.level > 9) {
                battle_bot_select_medaforce(rec, 0);
                return 0;
            }
            if (!random)
                return 1;
        }
        if (slot == 1) {
            if (gBattleBots[rec].medal.level > 29) {
                battle_bot_select_medaforce(rec, 1);
                return 0;
            }
            if (!random)
                return 1;
        }
        if (slot == 2) {
            if (gBattleBots[rec].medal.level > 59) {
                battle_bot_select_medaforce(rec, 2);
                return 0;
            }
            if (!random)
                return 1;
        }
        if (slot == 0)
            return 1;
        slot--;
    }
}

// Opponents can't use Medaforce until the story phase (gFieldWork.story_phase) is past 2.
static u32 opponent_medaforce_locked(u32 rec) {
    if (rec <= 2 || gFieldWork.story_phase > 2)
        return 0;
    return 1;
}

void battle_bot_select_medaforce(u32 rec, u32 part) {
    memcpy_bytes_08041D04(&gMedalMedaforceIds[gBattleBots[rec].medal.graphicId * 3], &gGameWork.partAbility, 3);
    memcpy_bytes_08041D04(&gMedaforceRecords[(&gGameWork.partAbility)[part] * 6], gBattleBots[rec].medaforce, 6);
    battle_bot_select_part(rec, part + 4);
}

void battle_ai_roll_part_order(void) {
    memcpy_bytes_08041D04(gAiPartOrders[rng_next_byte() & 0x1F], gBattleWork.unk64, 4);
}

static u32 battle_part_unusable(u32 rec, u32 part) {
    if (!part_blocked_by_effect(rec, part) && !head_out_of_uses(rec, part) && !part_is_broken(rec, part) &&
        !ai_action_unusable(rec, part))
        return 0;
    return 1;
}
