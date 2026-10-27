// Robattle turn order: robattle_judge_time_up (winner when TIME runs out), select_next_bot_and_action,
// find_next_active_bot, determine_battle_part_action_priority. Called from the battle action state code.

#include "global.h"

// unkBA == 2: set by reset_battle_bot_state when a Medabot stops functioning.
static u32 count_knocked_out_bots(u32 first) {
    u32 n = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gBattleBots[first + i].unkBA == 2)
            n++;
    }
    return n;
}

static u32 battle_count_broken_parts(u32 first) {
    u32 n = 0;
    u32 i, j;

    for (i = 0; i <= 2; i++) {
        if (gBattleBots[first + i].unkBA) {
            for (j = 0; j <= 3; j++) {
                if (gBattleBots[first + i].parts[j].unk11 == 0)
                    n++;
            }
        }
    }
    return n;
}

// Decides the Robattle winner from the team / opponent records: fewer Medabots with unkBA == 2, then fewer
// broken parts, then the larger gBattleWork.unk28[side].unk1, then a coin flip (mirrored on link player 1).
// gGameWork.unk9C = 1 team wins, 2 opponents win. Called by action_phase_time_check when TIME (unk57) is 0.
void robattle_judge_time_up(void) {
    u32 team = count_knocked_out_bots(0);
    u32 opp = count_knocked_out_bots(3);

    if (team < opp)
        gGameWork.unk9C = 1;
    else if (opp < team)
        gGameWork.unk9C = 2;
    else {
        team = battle_count_broken_parts(0);
        opp = battle_count_broken_parts(3);
        if (team < opp)
            gGameWork.unk9C = 1;
        else if (opp < team)
            gGameWork.unk9C = 2;
        else if (gBattleWork.unk28[0].unk1 > gBattleWork.unk28[1].unk1)
            gGameWork.unk9C = 1;
        else if (gBattleWork.unk28[0].unk1 < gBattleWork.unk28[1].unk1)
            gGameWork.unk9C = 2;
        else if (gGameWork.unk89 != 1) {
            if (rng_next_byte() & 1)
                gGameWork.unk9C = 1;
            else
                gGameWork.unk9C = 2;
        } else if (gUnk_03000B90 == 0) {
            if (rng_next_byte() & 1)
                gGameWork.unk9C = 1;
            else
                gGameWork.unk9C = 2;
        } else {
            if (rng_next_byte() & 1)
                gGameWork.unk9C = 2;
            else
                gGameWork.unk9C = 1;
        }
    }
}

void reset_bot_status_and_init_palette_transfers(u32 rec) {
    u32 z0, z1, z2, z3, z4;

    gBattleBots[rec].unkBC = 0;
    gBattleBots[rec].unkBD &= 0xE5;
    z0 = 0;
    CpuSet(&z0, gUnk_030018A8, 0x05000008);
    z1 = 0;
    CpuSet(&z1, gUnk_030018A8 + 8, 0x05000008);
    z2 = 0;
    CpuSet(&z2, gUnk_030018A8 + 16, 0x05000004);
    z3 = 0;
    CpuSet(&z3, gUnk_030018A8 + 20, 0x05000008);
    z4 = 0;
    CpuSet(&z4, gUnk_030018A8 + 47, 0x05000001);
}

// unkF8 = first record of the acting Medabot's side (0 team, 3 opponents).
void battle_set_actor_side(u32 rec) {
    if (rec <= 2)
        gBattleWork.unkF8 = 0;
    else
        gBattleWork.unkF8 = 3;
}

void select_next_bot_and_action(u32 rec) {
    if (gBattleBots[rec].unkC9 == 0x2C) {
        if (gBattleBots[rec].parts[gBattleBots[rec].chosenAction - 1].data[2] <= 3 ||
            gBattleBots[rec].parts[gBattleBots[rec].chosenAction - 1].data[1] == 0x34) {
            gBattleBots[rec].unkE0 = find_next_active_bot(rec) + 1;
            gBattleBots[rec].unkE1 = ai_random_target_part(gBattleBots[rec].unkE0 - 1) + 1;
        }
    }
}

u32 find_next_active_bot(u32 rec) {
    u32 k = rng_next_byte() & 0x1F;
    u32 i;
    u32 r;

    for (i = 0; i <= 5; i++) {
        r = gUnk_083AD3D3[k];
        if (gGameWork.unk89 == 1 && gUnk_03000B90)
            r = gUnk_083AD3F3[r];
        if (gBattleBots[r].unk40 && rec != r)
            return r;
        k = (k + 1) & 0x1F;
    }
    return 0;
}

void determine_battle_part_action_priority(void) {
    gBattleWork.unk15C[0] = 0;
    gBattleWork.unk15C[1] = 0;
    gBattleWork.unk15C[2] = 0;

    if (gBattleBots[gBattleWork.unk80].parts[0].unk10 == 0)
        gBattleWork.unk15C[0] = 4;
    if (part_skill_is_passive(gBattleWork.unk80, 0))
        gBattleWork.unk15C[0] = 3;
    if (gBattleBots[gBattleWork.unk80].unkC9 == 0x2B && gBattleBots[gBattleWork.unk80].unkCA == 1)
        gBattleWork.unk15C[0] = 2;

    if (part_skill_is_passive(gBattleWork.unk80, 1))
        gBattleWork.unk15C[1] = 3;
    if (gBattleBots[gBattleWork.unk80].unkC9 == 0x2B && gBattleBots[gBattleWork.unk80].unkCA == 2)
        gBattleWork.unk15C[1] = 2;
    if (gBattleBots[gBattleWork.unk80].parts[1].unk11 == 0)
        gBattleWork.unk15C[1] = 1;

    if (part_skill_is_passive(gBattleWork.unk80, 2))
        gBattleWork.unk15C[2] = 3;
    if (gBattleBots[gBattleWork.unk80].unkC9 == 0x2B && gBattleBots[gBattleWork.unk80].unkCA == 3)
        gBattleWork.unk15C[2] = 2;
    if (gBattleBots[gBattleWork.unk80].parts[2].unk11 == 0)
        gBattleWork.unk15C[2] = 1;
}

// Sprite 9 marks the target of the selected part (parts[].unkE = target record + 1, unkF = target part);
// target_marker_update pulses that part sprite's scale, target_marker_hide restores it.
void target_marker_show(void) {
    clear_battle_sprite_slot(9, 1);
    if (gBattleWork.unk82 != 0 && gBattleWork.unk15C[gBattleWork.unk82 - 1] == 0 &&
        gBattleBots[gBattleWork.unk80].parts[gBattleWork.unk82 - 1].unkE) {
        gSpriteEntries[9].unk0 = 0xC404;
        gSpriteEntries[9].unk1C = 0;
        gSpriteEntries[9].unk4 =
            gSpriteEntries[gBattleBots[gBattleWork.unk80].parts[gBattleWork.unk82 - 1].unkE * 4 + 0x59].unk4 - 4;
        gSpriteEntries[9].unk2 =
            gSpriteEntries[gBattleBots[gBattleWork.unk80].parts[gBattleWork.unk82 - 1].unkE * 4 + 0x59].unk2;
        gSpriteEntries[9].unkA = 6;
        gSpriteEntries[9].unkB = 0xF0;
        gSpriteEntries[9].unk24 = gBattleBots[gBattleWork.unk80].parts[gBattleWork.unk82 - 1].unkF;
        gSpriteEntries[9].unk25 = gBattleBots[gBattleWork.unk80].parts[gBattleWork.unk82 - 1].unkE;
        gSpriteEntries[9].unk26 = 0;
        gSpriteEntries[9].unk27 = 0;
        init_battle_sprite_entry_08040B90(gUnk_083B5F80[24], 9);
    }
}

void target_marker_update(void) {
    if (gSpriteEntries[9].unk0 & 0x8000) {
        process_sprite_anim_commands(gUnk_083B5F80[24], 9);
        if (gSpriteEntries[9].unk24) {
            gSpriteEntries[9].unk27++;
            gSpriteEntries[(gSpriteEntries[9].unk25 - 1) * 4 + gSpriteEntries[9].unk24 + 0x59].unk0 |= 0x220;
            if (gSpriteEntries[9].unk26 == 0) {
                gSpriteEntries[(gSpriteEntries[9].unk25 - 1) * 4 + gSpriteEntries[9].unk24 + 0x59].unk8 =
                    gSpriteEntries[9].unk27 * 2 + 0x40;
                gSpriteEntries[(gSpriteEntries[9].unk25 - 1) * 4 + gSpriteEntries[9].unk24 + 0x59].unk9 =
                    gSpriteEntries[9].unk27 * 2 + 0x40;
            } else {
                gSpriteEntries[(gSpriteEntries[9].unk25 - 1) * 4 + gSpriteEntries[9].unk24 + 0x59].unk8 =
                    0x60 - gSpriteEntries[9].unk27 * 2;
                gSpriteEntries[(gSpriteEntries[9].unk25 - 1) * 4 + gSpriteEntries[9].unk24 + 0x59].unk9 =
                    0x60 - gSpriteEntries[9].unk27 * 2;
            }
            if (gSpriteEntries[9].unk27 > 0x10) {
                gSpriteEntries[9].unk26 ^= 1;
                gSpriteEntries[9].unk27 = 0;
            }
        }
    }
}

void target_marker_hide(void) {
    if (gSpriteEntries[9].unk0 & 0x8000) {
        if (gSpriteEntries[9].unk24) {
            gSpriteEntries[(gSpriteEntries[9].unk25 - 1) * 4 + gSpriteEntries[9].unk24 + 0x59].unk8 = 0x40;
            gSpriteEntries[(gSpriteEntries[9].unk25 - 1) * 4 + gSpriteEntries[9].unk24 + 0x59].unk9 = 0x40;
            if (gBattleWork.unk80 == gSpriteEntries[9].unk25 - 1) {
                if ((u8)(gSpriteEntries[9].unk24 - 2) <= 1)
                    gSpriteEntries[gBattleWork.unk80 * 4 + gSpriteEntries[9].unk24 + 0x59].unk0 &= 0xFFDF;
                else
                    gSpriteEntries[gBattleWork.unk80 * 4 + gSpriteEntries[9].unk24 + 0x59].unk0 &= 0xFDDF;
            }
        }
        clear_battle_sprite_slot(9, 1);
    }
}
