// Robattle turn order: robattle_judge_time_up (winner when TIME runs out), select_next_bot_and_action,
// find_next_active_bot, determine_battle_part_action_priority. Called from the battle action state code.

#include "global.h"
#include "constants/skill_sprites.h"
#include "constants/sprites.h"

// present == 2: set by reset_battle_bot_state when a Medabot stops functioning.
static u32 count_knocked_out_bots(u32 first) {
    u32 n = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gBattleBots[first + i].present == 2)
            n++;
    }
    return n;
}

static u32 battle_count_broken_parts(u32 first) {
    u32 n = 0;
    u32 i, j;

    for (i = 0; i <= 2; i++) {
        if (gBattleBots[first + i].present) {
            for (j = 0; j <= 3; j++) {
                if (gBattleBots[first + i].parts[j].armor == 0)
                    n++;
            }
        }
    }
    return n;
}

// Decides the Robattle winner from the team / opponent records: fewer Medabots with present == 2, then fewer
// broken parts, then the larger gBattleWork.traps[side].actionPoints, then a coin flip (mirrored on link player 1).
// gGameWork.battleResult = 1 team wins, 2 opponents win. Called by action_phase_time_check when TIME (timeLeft) is 0.
void robattle_judge_time_up(void) {
    u32 team = count_knocked_out_bots(0);
    u32 opp = count_knocked_out_bots(3);

    if (team < opp)
        gGameWork.battleResult = 1;
    else if (opp < team)
        gGameWork.battleResult = 2;
    else {
        team = battle_count_broken_parts(0);
        opp = battle_count_broken_parts(3);
        if (team < opp)
            gGameWork.battleResult = 1;
        else if (opp < team)
            gGameWork.battleResult = 2;
        else if (gBattleWork.traps[0].actionPoints > gBattleWork.traps[1].actionPoints)
            gGameWork.battleResult = 1;
        else if (gBattleWork.traps[0].actionPoints < gBattleWork.traps[1].actionPoints)
            gGameWork.battleResult = 2;
        else if (gGameWork.skipBotSetup != 1) {
            if (rng_next_byte() & 1)
                gGameWork.battleResult = 1;
            else
                gGameWork.battleResult = 2;
        } else if (gLinkPlayerId == 0) {
            if (rng_next_byte() & 1)
                gGameWork.battleResult = 1;
            else
                gGameWork.battleResult = 2;
        } else {
            if (rng_next_byte() & 1)
                gGameWork.battleResult = 2;
            else
                gGameWork.battleResult = 1;
        }
    }
}

void reset_bot_status_and_init_palette_transfers(u32 rec) {
    u32 z0, z1, z2, z3, z4;

    gBattleBots[rec].hitFlags = 0;
    gBattleBots[rec].stateFlags &= 0xE5;
    z0 = 0;
    CpuSet(&z0, gBattleWorkActionVars, CPU_SET_SRC_FIXED | CPU_SET_32BIT | 0x8);
    z1 = 0;
    CpuSet(&z1, gBattleWorkActionVars + 8, CPU_SET_SRC_FIXED | CPU_SET_32BIT | 0x8);
    z2 = 0;
    CpuSet(&z2, gBattleWorkActionVars + 16, CPU_SET_SRC_FIXED | CPU_SET_32BIT | 0x4);
    z3 = 0;
    CpuSet(&z3, gBattleWorkActionVars + 20, CPU_SET_SRC_FIXED | CPU_SET_32BIT | 0x8);
    z4 = 0;
    CpuSet(&z4, gBattleWorkActionVars + 47, CPU_SET_SRC_FIXED | CPU_SET_32BIT | 0x1);
}

// actorSideFlags = first record of the acting Medabot's side (0 team, 3 opponents).
void battle_set_actor_side(u32 rec) {
    if (rec <= 2)
        gBattleWork.actorSideFlags = 0;
    else
        gBattleWork.actorSideFlags = 3;
}

void select_next_bot_and_action(u32 rec) {
    if (gBattleBots[rec].statusType == 0x2C) {
        if (gBattleBots[rec].parts[gBattleBots[rec].chosenAction - 1].data[2] <= 3 ||
            gBattleBots[rec].parts[gBattleBots[rec].chosenAction - 1].data[1] == 0x34) {
            gBattleBots[rec].targetBot = find_next_active_bot(rec) + 1;
            gBattleBots[rec].targetPart = ai_random_target_part(gBattleBots[rec].targetBot - 1) + 1;
        }
    }
}

u32 find_next_active_bot(u32 rec) {
    u32 k = rng_next_byte() & 0x1F;
    u32 i;
    u32 bot;

    for (i = 0; i <= 5; i++) {
        bot = gRandomBotOrder[k];
        if (gGameWork.skipBotSetup == 1 && gLinkPlayerId)
            bot = gLinkBotRecordSwap[bot];
        if (gBattleBots[bot].teamState && rec != bot)
            return bot;
        k = (k + 1) & 0x1F;
    }
    return 0;
}

void determine_battle_part_action_priority(void) {
    gBattleWork.partBlockReason[0] = 0;
    gBattleWork.partBlockReason[1] = 0;
    gBattleWork.partBlockReason[2] = 0;

    if (gBattleBots[gBattleWork.commandBot].parts[0].headUses == 0)
        gBattleWork.partBlockReason[0] = 4;
    if (part_skill_is_passive(gBattleWork.commandBot, 0))
        gBattleWork.partBlockReason[0] = 3;
    if (gBattleBots[gBattleWork.commandBot].statusType == 0x2B && gBattleBots[gBattleWork.commandBot].statusPart == 1)
        gBattleWork.partBlockReason[0] = 2;

    if (part_skill_is_passive(gBattleWork.commandBot, 1))
        gBattleWork.partBlockReason[1] = 3;
    if (gBattleBots[gBattleWork.commandBot].statusType == 0x2B && gBattleBots[gBattleWork.commandBot].statusPart == 2)
        gBattleWork.partBlockReason[1] = 2;
    if (gBattleBots[gBattleWork.commandBot].parts[1].armor == 0)
        gBattleWork.partBlockReason[1] = 1;

    if (part_skill_is_passive(gBattleWork.commandBot, 2))
        gBattleWork.partBlockReason[2] = 3;
    if (gBattleBots[gBattleWork.commandBot].statusType == 0x2B && gBattleBots[gBattleWork.commandBot].statusPart == 3)
        gBattleWork.partBlockReason[2] = 2;
    if (gBattleBots[gBattleWork.commandBot].parts[2].armor == 0)
        gBattleWork.partBlockReason[2] = 1;
}

// Sprite 9 marks the target of the selected part (parts[].aiTargetBot = target record + 1, aiTargetPart = target part +
// 1); target_marker_update pulses that part sprite's scale, target_marker_hide restores it.
void target_marker_show(void) {
    clear_battle_sprite_slot(9, 1);
    if (gBattleWork.partCursor != 0 && gBattleWork.partBlockReason[gBattleWork.partCursor - 1] == 0 &&
        gBattleBots[gBattleWork.commandBot].parts[gBattleWork.partCursor - 1].aiTargetBot) {
        gSpriteEntries[9].flags =
            SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_PART_PALETTE;
        gSpriteEntries[9].frame_table = 0;
        gSpriteEntries[9].y =
            gSpriteEntries[gBattleBots[gBattleWork.commandBot].parts[gBattleWork.partCursor - 1].aiTargetBot * 4 + 0x59]
                .y -
            4;
        gSpriteEntries[9].x =
            gSpriteEntries[gBattleBots[gBattleWork.commandBot].parts[gBattleWork.partCursor - 1].aiTargetBot * 4 + 0x59]
                .x;
        gSpriteEntries[9].palette = 6;
        gSpriteEntries[9].order = 0xF0;
        gSpriteEntries[9].work[MARKER_SPR_PART] =
            gBattleBots[gBattleWork.commandBot].parts[gBattleWork.partCursor - 1].aiTargetPart;
        gSpriteEntries[9].work[MARKER_SPR_BOT] =
            gBattleBots[gBattleWork.commandBot].parts[gBattleWork.partCursor - 1].aiTargetBot;
        gSpriteEntries[9].work[MARKER_SPR_SHRINK] = 0;
        gSpriteEntries[9].work[MARKER_SPR_FRAMES] = 0;
        battle_sprite_anim_init(gBattleSpriteAnimScripts[24], 9);
    }
}

void target_marker_update(void) {
    if (gSpriteEntries[9].flags & SPRITE_FLAG_ENABLED) {
        process_sprite_anim_commands(gBattleSpriteAnimScripts[24], 9);
        if (gSpriteEntries[9].work[MARKER_SPR_PART]) {
            gSpriteEntries[9].work[MARKER_SPR_FRAMES]++;
            gSpriteEntries[(gSpriteEntries[9].work[MARKER_SPR_BOT] - 1) * 4 + gSpriteEntries[9].work[MARKER_SPR_PART] +
                           0x59]
                .flags |= SPRITE_FLAG_AFFINE | SPRITE_FLAG_DOUBLE_SIZE;
            if (gSpriteEntries[9].work[MARKER_SPR_SHRINK] == 0) {
                gSpriteEntries[(gSpriteEntries[9].work[MARKER_SPR_BOT] - 1) * 4 +
                               gSpriteEntries[9].work[MARKER_SPR_PART] + 0x59]
                    .scale_x = gSpriteEntries[9].work[MARKER_SPR_FRAMES] * 2 + 0x40;
                gSpriteEntries[(gSpriteEntries[9].work[MARKER_SPR_BOT] - 1) * 4 +
                               gSpriteEntries[9].work[MARKER_SPR_PART] + 0x59]
                    .scale_y = gSpriteEntries[9].work[MARKER_SPR_FRAMES] * 2 + 0x40;
            } else {
                gSpriteEntries[(gSpriteEntries[9].work[MARKER_SPR_BOT] - 1) * 4 +
                               gSpriteEntries[9].work[MARKER_SPR_PART] + 0x59]
                    .scale_x = 0x60 - gSpriteEntries[9].work[MARKER_SPR_FRAMES] * 2;
                gSpriteEntries[(gSpriteEntries[9].work[MARKER_SPR_BOT] - 1) * 4 +
                               gSpriteEntries[9].work[MARKER_SPR_PART] + 0x59]
                    .scale_y = 0x60 - gSpriteEntries[9].work[MARKER_SPR_FRAMES] * 2;
            }
            if (gSpriteEntries[9].work[MARKER_SPR_FRAMES] > 0x10) {
                gSpriteEntries[9].work[MARKER_SPR_SHRINK] ^= 1;
                gSpriteEntries[9].work[MARKER_SPR_FRAMES] = 0;
            }
        }
    }
}

void target_marker_hide(void) {
    if (gSpriteEntries[9].flags & SPRITE_FLAG_ENABLED) {
        if (gSpriteEntries[9].work[MARKER_SPR_PART]) {
            gSpriteEntries[(gSpriteEntries[9].work[MARKER_SPR_BOT] - 1) * 4 + gSpriteEntries[9].work[MARKER_SPR_PART] +
                           0x59]
                .scale_x = 0x40;
            gSpriteEntries[(gSpriteEntries[9].work[MARKER_SPR_BOT] - 1) * 4 + gSpriteEntries[9].work[MARKER_SPR_PART] +
                           0x59]
                .scale_y = 0x40;
            if (gBattleWork.commandBot == gSpriteEntries[9].work[MARKER_SPR_BOT] - 1) {
                if ((u8)(gSpriteEntries[9].work[MARKER_SPR_PART] - 2) <= 1)
                    gSpriteEntries[gBattleWork.commandBot * 4 + gSpriteEntries[9].work[MARKER_SPR_PART] + 0x59].flags &=
                        (u16)~SPRITE_FLAG_DOUBLE_SIZE;
                else
                    gSpriteEntries[gBattleWork.commandBot * 4 + gSpriteEntries[9].work[MARKER_SPR_PART] + 0x59].flags &=
                        (u16) ~(SPRITE_FLAG_AFFINE | SPRITE_FLAG_DOUBLE_SIZE);
            }
        }
        clear_battle_sprite_slot(9, 1);
    }
}
