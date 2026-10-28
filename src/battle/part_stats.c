// Timed battle effects on the battle records gBattleBots, ticked every 32 frames by robattle_time_tick:
// effect A (buffType..buffNumber) is AutoRecover (skill 0x1F), which restores armor to damaged parts; effect B
// (statusType..statusNumber) is a status, of which Fire / Melt (skills 0x13 / 0x14) burn armor down to 1 each tick.
// Each tick takes 4 from the frames left; at 0 the effect ends. Skill names from the ROM's skill list.

#include "global.h"

static u32 find_damaged_part(u32 rec);
static u32 add_part_stat_clamped(u32 rec, u32 part, s32 amount);
static u32 subtract_part_armor_keep_one(u32 rec, u32 part, s32 amount);

// Ticks both timed effects of every present Medabot; gBattleWork.resultFlags collects what happened.
void battle_tick_timed_effects(void) {
    u32 i;

    gBattleWork.resultFlags = 0;
    for (i = 0; i <= 5; i++) {
        if (gBattleBots[i].teamState) {
            if (gBattleBots[i].buffType)
                battle_tick_buff_effect(i);
            if (gBattleBots[i].statusType)
                battle_tick_status_effect(i);
        }
    }
}

// AutoRecover: spreads buffAmount armor over up to 4 damaged parts; buffNumber = the total, shown as a number.
void battle_tick_buff_effect(u32 rec) {
    s32 frames;
    u32 i, part, result, done;

    frames = gBattleBots[rec].buffTimer - 4;
    if (frames <= 0) {
        gBattleBots[rec].buffType = 0;
        gBattleBots[rec].buffPart = 0;
        gBattleBots[rec].buffTimer = 0;
        gBattleBots[rec].buffAmount = 0;
        gBattleBots[rec].effectShownFlags |= 1;
        gBattleWork.resultFlags |= 2;
        return;
    }
    gBattleBots[rec].buffTimer = frames;
    if (gBattleBots[rec].buffType != 0x1F)
        return;
    gBattleWork.effectAmountLeft = gBattleBots[rec].buffAmount;
    gBattleWork.effectAmountTotal = 0;
    done = 0;
    for (i = 0; i <= 3; i++) {
        part = find_damaged_part(rec);
        if (part != 0) {
            result = add_part_stat_clamped(rec, part - 1, gBattleWork.effectAmountLeft);
            gBattleWork.effectAmountTotal += result;
            gBattleWork.effectAmountLeft = (result & 0xFF00) >> 8;
            done = 1;
            if (gBattleWork.effectAmountLeft == 0)
                break;
        } else
            break;
    }
    if (done) {
        gBattleBots[rec].buffNumber = gBattleWork.effectAmountTotal;
        gBattleBots[rec].effectShownFlags |= 4;
        gBattleWork.resultFlags |= 8;
    }
}

// Fire / Melt: burns statusAmount armor off up to 4 parts (never below 1); statusNumber = the total, shown as a number.
void battle_tick_status_effect(u32 rec) {
    s32 frames;
    u32 i, part, result, done;

    frames = gBattleBots[rec].statusTimer - 4;
    if (frames <= 0) {
        gBattleBots[rec].statusType = 0;
        gBattleBots[rec].statusPart = 0;
        gBattleBots[rec].statusTimer = 0;
        gBattleBots[rec].statusAmount = 0;
        gBattleBots[rec].effectShownFlags |= 2;
        gBattleWork.resultFlags |= 4;
        return;
    }
    gBattleBots[rec].statusTimer = frames;
    if ((u8)(gBattleBots[rec].statusType - 0x13) > 1)
        return;
    gBattleWork.effectAmountLeft = gBattleBots[rec].statusAmount;
    gBattleWork.effectAmountTotal = 0;
    done = 0;
    for (i = 0; i <= 3; i++) {
        part = find_burnable_part(rec);
        if (part != 0) {
            result = subtract_part_armor_keep_one(rec, part - 1, gBattleWork.effectAmountLeft);
            gBattleWork.effectAmountTotal += result;
            gBattleWork.effectAmountLeft = (result & 0xFF00) >> 8;
            done = 1;
            if (gBattleWork.effectAmountLeft == 0)
                break;
        } else
            break;
    }
    if (done) {
        gBattleBots[rec].statusNumber = gBattleWork.effectAmountTotal;
        gBattleBots[rec].effectShownFlags |= 8;
        gBattleWork.resultFlags |= 0x10;
    }
}

static inline u32 part_armor(u32 rec, u32 i) {
    return gBattleBots[rec].parts[i].armor;
}

// First part (1-4) that still works but is below its maximum armor (data[4]), 0 = none.
static u32 find_damaged_part(u32 rec) {
    u32 i;
    for (i = 0; i <= 3; i++) {
        if (gBattleBots[rec].parts[i].armor != 0)
            if (gBattleBots[rec].parts[i].data[4] != part_armor(rec, i))
                return i + 1;
    }
    return 0;
}

// Adds armor up to the part's maximum. Returns the amount applied, with the leftover in bits 8-15.
static u32 add_part_stat_clamped(u32 rec, u32 part, s32 amount) {
    u32 armor = gBattleBots[rec].parts[part].armor;

    armor += amount;
    if (armor > gBattleBots[rec].parts[part].data[4]) {
        armor -= gBattleBots[rec].parts[part].data[4];
        gBattleBots[rec].parts[part].armor = gBattleBots[rec].parts[part].data[4];
        return (armor << 8) + (amount - armor);
    }
    gBattleBots[rec].parts[part].armor = armor;
    return amount;
}

// Unused: counts down from part 4 to the first one with armor left (returns 1 for part 4), 0 = none.
static u32 find_last_part_with_armor(u32 rec) {
    u32 i;

    for (i = 0; i <= 3; i++) {
        if (gBattleBots[rec].parts[3 - i].armor)
            return i + 1;
    }
    return 0;
}

// Part (1-4) with more than 1 armor, starting at the status's part (statusPart, 0 = part 4) and going down.
u32 find_burnable_part(u32 rec) {
    u32 part, i;

    if (gBattleBots[rec].statusPart == 0)
        part = 4;
    else
        part = gBattleBots[rec].statusPart;
    for (i = 0; i <= 3; i++) {
        if (gBattleBots[rec].parts[part - 1].armor > 1)
            return part;
        part--;
        if (part == 0)
            part = 4;
    }
    return 0;
}

// Unused: takes armor down to 0. Returns the amount taken, with the leftover in bits 8-15.
static u32 subtract_part_armor_clamped(u32 rec, u32 part, s32 amount) {
    u32 cur = gBattleBots[rec].parts[part].armor;
    s32 left = cur - amount;
    u32 ret;

    if (left >= 0) {
        gBattleBots[rec].parts[part].armor = left;
        ret = amount;
    } else {
        gBattleBots[rec].parts[part].armor = 0;
        ret = ((amount - cur) << 8) + cur;
    }
    return ret;
}

// Takes armor down to 1 (a burn never breaks the part). Returns the amount taken, leftover in bits 8-15.
static u32 subtract_part_armor_keep_one(u32 rec, u32 part, s32 amount) {
    u32 cur = gBattleBots[rec].parts[part].armor;
    u32 spare = cur - 1;
    u32 ret;

    if ((s32)(spare - amount) >= 0) {
        gBattleBots[rec].parts[part].armor = cur - amount;
        ret = amount;
    } else {
        gBattleBots[rec].parts[part].armor = 1;
        ret = ((amount - spare) << 8) + spare;
    }
    return ret;
}
