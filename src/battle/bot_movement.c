// Medabot movement on the battle field: every frame each Medabot's movement delay is rebuilt from its action,
// legs, the battlefield terrain, statuses and Medal level (bot_calc_move_delay), then battle_bot_move steps it
// (0x20 - delay) / 16 px between its home line and the front line. Called from battle/robattle.

#include "global.h"

static void bot_calc_move_delay(u32 rec);
static void bot_move_delay_add_action(u32 rec);
static void bot_move_delay_add(u32 rec, u32 amount);
static void bot_move_delay_add_broken_legs(u32 rec);
static void bot_move_delay_add_slow_status(u32 rec);
static void bot_move_delay_sub_medal_level(u32 rec);
static void bot_move_delay_sub_time_status(u32 rec);
static void bot_move_delay_sub_speed_parts(u32 rec);
static void bot_move_delay_clamp(u32 rec);

// Moves every Medabot in play that isn't stopped by Thunder / Freeze (effect B 0xF / 0x10).
void battle_bots_move_all(void) {
    u32 i;

    for (i = 0; i <= 5; i++) {
        if (gBattleBots[i].teamState && (u8)(gBattleBots[i].statusType - 0xF) > 1) {
            bot_calc_move_delay(i);
            battle_bot_move(i);
            bot_update_walk_anim(i);
        }
    }
}

// Picks the walk animation of every Medabot in play that isn't stopped by Thunder / Freeze.
void battle_bots_update_walk_anims(void) {
    u32 i;

    for (i = 0; i <= 5; i++) {
        if (gBattleBots[i].teamState && (u8)(gBattleBots[i].statusType - 0xF) > 1) {
            bot_update_walk_anim(i);
        }
    }
}

// Rebuilds moveDelay: the additions first, then the reductions, capped at 0x1F.
static void bot_calc_move_delay(u32 rec) {
    gBattleBots[rec].moveDelay = 0;
    bot_move_delay_add_action(rec);
    bot_move_delay_add_broken_legs(rec);
    bot_move_delay_add_terrain(rec);
    bot_move_delay_add_slow_status(rec);
    bot_move_delay_sub_medal_level(rec);
    bot_move_delay_sub_propulsion(rec);
    bot_move_delay_sub_time_status(rec);
    bot_move_delay_sub_speed_parts(rec);
    bot_move_delay_clamp(rec);
}

// The chosen action's delay: Medaforce 12, head 6, an arm its part data[8] on the way out and data[9] on the way
// back (unkBD bit 2); nothing for a broken part.
static void bot_move_delay_add_action(u32 rec) {
    if (gBattleBots[rec].chosenAction == 0)
        return;
    if (gBattleBots[rec].chosenAction > 3) {
        bot_move_delay_add(rec, 12);
        return;
    }
    if (gBattleBots[rec].parts[gBattleBots[rec].chosenAction - 1].unk11 == 0)
        return;
    if (gBattleBots[rec].chosenAction == 1)
        bot_move_delay_add(rec, 6);
    else if (!(gBattleBots[rec].stateFlags & 4))
        bot_move_delay_add(rec, gBattleBots[rec].parts[gBattleBots[rec].chosenAction - 1].data[8]);
    else
        bot_move_delay_add(rec, gBattleBots[rec].parts[gBattleBots[rec].chosenAction - 1].data[9]);
}

static void bot_move_delay_add(u32 rec, u32 amount) {
    amount += gBattleBots[rec].moveDelay;
    if (amount > 0xFF)
        amount = 0xFF;
    gBattleBots[rec].moveDelay = amount;
}

static void bot_move_delay_sub(u32 rec, u32 amount) {
    s32 delay = gBattleBots[rec].moveDelay - amount;

    if (delay < 0)
        delay = 0;
    gBattleBots[rec].moveDelay = delay;
}

// +6 while the legs are broken.
static void bot_move_delay_add_broken_legs(u32 rec) {
    if (gBattleBots[rec].parts[3].unk11 == 0)
        bot_move_delay_add(rec, 6);
}

// + the battlefield's delay for the leg type (gTerrainMoveDelays).
void bot_move_delay_add_terrain(u32 rec) {
    memcpy_bytes_08041D04(&gTerrainMoveDelays[gBattleWork.battlefield + (gBattleBots[rec].parts[3].data[1] - 100) * 11],
                          &gGameWork.partAbility, 1);
    bot_move_delay_add(rec, gGameWork.partAbility);
}

// + the status amount while slowed by Wave / Hold (effect B 0x11 / 0x12) or Bind (0x29).
static void bot_move_delay_add_slow_status(u32 rec) {
    if (gBattleBots[rec].statusType != 0 &&
        ((u8)(gBattleBots[rec].statusType - 0x11) <= 1 || gBattleBots[rec].statusType == 0x29))
        bot_move_delay_add(rec, gBattleBots[rec].statusAmount);
}

// - Medal level / 10.
static void bot_move_delay_sub_medal_level(u32 rec) {
    bot_move_delay_sub(rec, (u8)(gBattleBots[rec].medal.level / 10));
}

// - legs Propulsion / 20.
void bot_move_delay_sub_propulsion(u32 rec) {
    bot_move_delay_sub(rec, (u8)(gBattleBots[rec].parts[3].unk12 / 20));
}

// - the status amount while sped up by Time (effect A 0x26 / 0x29).
static void bot_move_delay_sub_time_status(u32 rec) {
    if (gBattleBots[rec].buffType != 0 && (gBattleBots[rec].buffType == 0x26 || gBattleBots[rec].buffType == 0x29))
        bot_move_delay_sub(rec, gBattleBots[rec].buffAmount);
}

// - data[6] of each unbroken head / arm with the passive skill 0x28 (guess: a speed-up skill).
static void bot_move_delay_sub_speed_parts(u32 rec) {
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gBattleBots[rec].parts[i].data[1] == 0x28 && gBattleBots[rec].parts[i].unk11 != 0)
            bot_move_delay_sub(rec, gBattleBots[rec].parts[i].data[6]);
    }
}

static void bot_move_delay_clamp(u32 rec) {
    if (gBattleBots[rec].moveDelay > 0x1F)
        gBattleBots[rec].moveDelay = 0x1F;
}

void battle_bot_move(u32 rec) {

    gBattleBots[rec].moveSubpixel += 0x20 - gBattleBots[rec].moveDelay;
    gBattleBots[rec].moveStep = gBattleBots[rec].moveSubpixel / 16;
    gBattleBots[rec].moveSubpixel %= 16;
    if (rec <= 2) {
        if (!(gBattleBots[rec].stateFlags & 4)) {
            if (gSpriteEntries[rec * 4 + 0x5D].unk2 + gBattleBots[rec].moveStep > 0x68)
                gSpriteEntries[rec * 4 + 0x5D].unk2 = 0x68;
            else
                gSpriteEntries[rec * 4 + 0x5D].unk2 += gBattleBots[rec].moveStep;
        } else {
            if (gSpriteEntries[rec * 4 + 0x5D].unk2 - gBattleBots[rec].moveStep < 0x28)
                gSpriteEntries[rec * 4 + 0x5D].unk2 = 0x28;
            else
                gSpriteEntries[rec * 4 + 0x5D].unk2 -= gBattleBots[rec].moveStep;
        }
    } else {
        if (!(gBattleBots[rec].stateFlags & 4)) {
            if (gSpriteEntries[rec * 4 + 0x5D].unk2 - gBattleBots[rec].moveStep < 0x88)
                gSpriteEntries[rec * 4 + 0x5D].unk2 = 0x88;
            else
                gSpriteEntries[rec * 4 + 0x5D].unk2 -= gBattleBots[rec].moveStep;
        } else {
            if (gSpriteEntries[rec * 4 + 0x5D].unk2 + gBattleBots[rec].moveStep > 0xC8)
                gSpriteEntries[rec * 4 + 0x5D].unk2 = 0xC8;
            else
                gSpriteEntries[rec * 4 + 0x5D].unk2 += gBattleBots[rec].moveStep;
        }
    }
}

// battle_bot_move with the directions swapped (used by a Medaforce effect on the target side); 1 when the line is
// reached.
u32 battle_bot_move_reverse(u32 rec) {
    u32 done = 0;

    gBattleBots[rec].moveSubpixel += 0x20 - gBattleBots[rec].moveDelay;
    gBattleBots[rec].moveStep = gBattleBots[rec].moveSubpixel / 16;
    gBattleBots[rec].moveSubpixel %= 16;
    if (rec <= 2) {
        if (gBattleBots[rec].stateFlags & 4) {
            if (gSpriteEntries[rec * 4 + 0x5D].unk2 + gBattleBots[rec].moveStep > 0x68) {
                gSpriteEntries[rec * 4 + 0x5D].unk2 = 0x68;
                done = 1;
            } else
                gSpriteEntries[rec * 4 + 0x5D].unk2 += gBattleBots[rec].moveStep;
        } else {
            if (gSpriteEntries[rec * 4 + 0x5D].unk2 - gBattleBots[rec].moveStep < 0x28) {
                gSpriteEntries[rec * 4 + 0x5D].unk2 = 0x28;
                done = 1;
            } else
                gSpriteEntries[rec * 4 + 0x5D].unk2 -= gBattleBots[rec].moveStep;
        }
    } else {
        if (gBattleBots[rec].stateFlags & 4) {
            if (gSpriteEntries[rec * 4 + 0x5D].unk2 - gBattleBots[rec].moveStep < 0x88) {
                gSpriteEntries[rec * 4 + 0x5D].unk2 = 0x88;
                done = 1;
            } else
                gSpriteEntries[rec * 4 + 0x5D].unk2 -= gBattleBots[rec].moveStep;
        } else {
            if (gSpriteEntries[rec * 4 + 0x5D].unk2 + gBattleBots[rec].moveStep > 0xC8) {
                gSpriteEntries[rec * 4 + 0x5D].unk2 = 0xC8;
                done = 1;
            } else
                gSpriteEntries[rec * 4 + 0x5D].unk2 += gBattleBots[rec].moveStep;
        }
    }
    return done;
}

// Sets the Medabot's walk animation from its speed: anim script (0x20 - moveDelay) / 2 + 1.
void bot_update_walk_anim(u32 rec) {
    if (gSpriteEntries[rec * 4 + 0x5B].unk0 & 0x200) {
        gSpriteEntries[rec * 4 + 0x5D].unk24 = ((s32)(0x20 - gBattleBots[rec].moveDelay) >> 1) + 1;
        update_battle_sprite_orbiting_positions(rec * 4 + 0x5A, rec, bot_sprite_is_flipped(rec));
    } else {
        battle_sprite_group_set_anim(rec * 4 + 0x5A, ((s32)(0x20 - gBattleBots[rec].moveDelay) >> 1) + 1);
    }
}
