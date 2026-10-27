// Timed battle effects on the battle records gBattleBots, ticked every 32 frames by robattle_time_tick:
// effect A (unkC4-unkC8) is AutoRecover (skill 0x1F), which restores armor to damaged parts; effect B
// (unkC9-unkCD) is a status, of which Fire / Melt (skills 0x13 / 0x14) burn armor down to 1 each tick.
// Each tick takes 4 from the frames left; at 0 the effect ends. Skill names from the ROM's skill list.

#include "global.h"

static u32 find_damaged_part(u32 rec);
static u32 add_part_stat_clamped(u32 rec, u32 part, s32 amount);
static u32 subtract_part_armor_keep_one(u32 rec, u32 part, s32 amount);

// Ticks both timed effects of every present Medabot; gBattleWork.unk55 collects what happened.
void battle_tick_timed_effects(void) {
    u32 i;

    gBattleWork.unk55 = 0;
    for (i = 0; i <= 5; i++) {
        if (gBattleBots[i].unk40) {
            if (gBattleBots[i].unkC4)
                battle_tick_buff_effect(i);
            if (gBattleBots[i].unkC9)
                battle_tick_status_effect(i);
        }
    }
}

// AutoRecover: spreads unkC7 armor over up to 4 damaged parts; unkC8 = the total, shown as a number.
void battle_tick_buff_effect(u32 rec) {
    s32 frames;
    u32 i, part, result, done;

    frames = gBattleBots[rec].unkC6 - 4;
    if (frames <= 0) {
        gBattleBots[rec].unkC4 = 0;
        gBattleBots[rec].unkC5 = 0;
        gBattleBots[rec].unkC6 = 0;
        gBattleBots[rec].unkC7 = 0;
        gBattleBots[rec].unkCE |= 1;
        gBattleWork.unk55 |= 2;
        return;
    }
    gBattleBots[rec].unkC6 = frames;
    if (gBattleBots[rec].unkC4 != 0x1F)
        return;
    gBattleWork.unk59 = gBattleBots[rec].unkC7;
    gBattleWork.unk86 = 0;
    done = 0;
    for (i = 0; i <= 3; i++) {
        part = find_damaged_part(rec);
        if (part != 0) {
            result = add_part_stat_clamped(rec, part - 1, gBattleWork.unk59);
            gBattleWork.unk86 += result;
            gBattleWork.unk59 = (result & 0xFF00) >> 8;
            done = 1;
            if (gBattleWork.unk59 == 0)
                break;
        } else
            break;
    }
    if (done) {
        gBattleBots[rec].unkC8 = gBattleWork.unk86;
        gBattleBots[rec].unkCE |= 4;
        gBattleWork.unk55 |= 8;
    }
}

// Fire / Melt: burns unkCC armor off up to 4 parts (never below 1); unkCD = the total, shown as a number.
void battle_tick_status_effect(u32 rec) {
    s32 frames;
    u32 i, part, result, done;

    frames = gBattleBots[rec].unkCB - 4;
    if (frames <= 0) {
        gBattleBots[rec].unkC9 = 0;
        gBattleBots[rec].unkCA = 0;
        gBattleBots[rec].unkCB = 0;
        gBattleBots[rec].unkCC = 0;
        gBattleBots[rec].unkCE |= 2;
        gBattleWork.unk55 |= 4;
        return;
    }
    gBattleBots[rec].unkCB = frames;
    if ((u8)(gBattleBots[rec].unkC9 - 0x13) > 1)
        return;
    gBattleWork.unk59 = gBattleBots[rec].unkCC;
    gBattleWork.unk86 = 0;
    done = 0;
    for (i = 0; i <= 3; i++) {
        part = find_burnable_part(rec);
        if (part != 0) {
            result = subtract_part_armor_keep_one(rec, part - 1, gBattleWork.unk59);
            gBattleWork.unk86 += result;
            gBattleWork.unk59 = (result & 0xFF00) >> 8;
            done = 1;
            if (gBattleWork.unk59 == 0)
                break;
        } else
            break;
    }
    if (done) {
        gBattleBots[rec].unkCD = gBattleWork.unk86;
        gBattleBots[rec].unkCE |= 8;
        gBattleWork.unk55 |= 0x10;
    }
}

static inline u32 part_armor(u32 rec, u32 i) {
    return gBattleBots[rec].parts[i].unk11;
}

// First part (1-4) that still works but is below its maximum armor (data[4]), 0 = none.
static u32 find_damaged_part(u32 rec) {
    u32 i;
    for (i = 0; i <= 3; i++) {
        if (gBattleBots[rec].parts[i].unk11 != 0)
            if (gBattleBots[rec].parts[i].data[4] != part_armor(rec, i))
                return i + 1;
    }
    return 0;
}

// Adds armor up to the part's maximum. Returns the amount applied, with the leftover in bits 8-15.
static u32 add_part_stat_clamped(u32 rec, u32 part, s32 amount) {
    u32 armor = gBattleBots[rec].parts[part].unk11;

    armor += amount;
    if (armor > gBattleBots[rec].parts[part].data[4]) {
        armor -= gBattleBots[rec].parts[part].data[4];
        gBattleBots[rec].parts[part].unk11 = gBattleBots[rec].parts[part].data[4];
        return (armor << 8) + (amount - armor);
    }
    gBattleBots[rec].parts[part].unk11 = armor;
    return amount;
}

// Unused: counts down from part 4 to the first one with armor left (returns 1 for part 4), 0 = none.
static u32 find_last_part_with_armor(u32 rec) {
    u32 i;

    for (i = 0; i <= 3; i++) {
        if (gBattleBots[rec].parts[3 - i].unk11)
            return i + 1;
    }
    return 0;
}

// Part (1-4) with more than 1 armor, starting at the status's part (unkCA, 0 = part 4) and going down.
u32 find_burnable_part(u32 rec) {
    u32 part, i;

    if (gBattleBots[rec].unkCA == 0)
        part = 4;
    else
        part = gBattleBots[rec].unkCA;
    for (i = 0; i <= 3; i++) {
        if (gBattleBots[rec].parts[part - 1].unk11 > 1)
            return part;
        part--;
        if (part == 0)
            part = 4;
    }
    return 0;
}

// Unused: takes armor down to 0. Returns the amount taken, with the leftover in bits 8-15.
static u32 subtract_part_armor_clamped(u32 rec, u32 part, s32 amount) {
    u32 cur = gBattleBots[rec].parts[part].unk11;
    s32 left = cur - amount;
    u32 ret;

    if (left >= 0) {
        gBattleBots[rec].parts[part].unk11 = left;
        ret = amount;
    } else {
        gBattleBots[rec].parts[part].unk11 = 0;
        ret = ((amount - cur) << 8) + cur;
    }
    return ret;
}

// Takes armor down to 1 (a burn never breaks the part). Returns the amount taken, leftover in bits 8-15.
static u32 subtract_part_armor_keep_one(u32 rec, u32 part, s32 amount) {
    u32 cur = gBattleBots[rec].parts[part].unk11;
    u32 spare = cur - 1;
    u32 ret;

    if ((s32)(spare - amount) >= 0) {
        gBattleBots[rec].parts[part].unk11 = cur - amount;
        ret = amount;
    } else {
        gBattleBots[rec].parts[part].unk11 = 1;
        ret = ((amount - spare) << 8) + spare;
    }
    return ret;
}
