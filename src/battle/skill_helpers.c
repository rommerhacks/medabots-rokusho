// Helpers for the skill effect sequences (battle/*_skills, medaforce_effects): damage split, action
// counters, Medal exp progress, action parameters, bot state reset, the cursor sprite, skill timers and
// stat ratios, and random target selection.

#include "global.h"
#include "constants/sprites.h"

void battle_calc_damage_split(u32 rec, u32 part, s32 amount) {
    s32 room = gBattleBots[rec].parts[part].data[4] - gBattleBots[rec].parts[part].armor;
    if (room > amount) {
        gBattleWork.appliedAmount = amount;
        gBattleWork.cappedAmount = amount;
        gBattleWork.overflowAmount = 0;
    } else {
        gBattleWork.appliedAmount = room;
        gBattleWork.cappedAmount = room;
        gBattleWork.overflowAmount = amount - room;
    }
}

u32 armor_heal_step(u16 *amount, u32 rec, u32 part) {
    u8 *n = (u8 *)amount;
    if (gBattleBots[rec].parts[part].armor != gBattleBots[rec].parts[part].data[4]) {
        gBattleBots[rec].parts[part].armor++;
        if (--*n != 0)
            return 0;
    }
    return 1;
}

u32 bot_has_status_guard(u32 rec, u32 skill) {
    if (skill - 0xd <= 1) {
        if (gBattleBots[rec].statusGuardFlags & 1)
            return 1;
        return 0;
    } else if (skill - 0xf <= 1) {
        if (gBattleBots[rec].statusGuardFlags & 8)
            return 1;
        return 0;
    } else if (skill - 0x11 <= 1) {
        if (gBattleBots[rec].statusGuardFlags & 2)
            return 1;
        return 0;
    } else if (skill - 0x13 <= 1) {
        if (gBattleBots[rec].statusGuardFlags & 4)
            return 1;
        return 0;
    }
    return 0;
}

u32 sprite_slide_x_step(u32 slot, u32 n) {
    if (!(gSpriteEntries[slot].flags & SPRITE_FLAG_ENABLED) || gSpriteEntries[slot].unk23 == 0x10)
        return 1;
    if (n == 0)
        gSpriteEntries[slot].x = gSpriteEntries[slot].x + gSpriteSlideXSteps[gSpriteEntries[slot].unk23];
    else
        gSpriteEntries[slot].x = gSpriteEntries[slot].x - gSpriteSlideXSteps[gSpriteEntries[slot].unk23];
    gSpriteEntries[slot].unk23++;
    return 0;
}

u32 clamp_1_99(u32 value) {
    if (value > 99)
        value = 99;
    else if (value == 0)
        value = 1;
    return value;
}

void battle_inflict_status(u32 rec, u32 skill, s32 duration, u32 power) {
    if (skill - 0xD <= 1) {
        gBattleBots[rec].statusType = skill;
        gBattleBots[rec].statusPart = gBattleWork.targetPart + 1;
        gBattleBots[rec].statusTimer = clamp_1_99(duration);
        gBattleBots[rec].statusAmount = clamp_1_99(power * 2);
    } else if (skill - 0xF <= 1) {
        gBattleBots[rec].statusType = skill;
        gBattleBots[rec].statusPart = gBattleWork.targetPart + 1;
        gBattleBots[rec].statusTimer = clamp_1_99(power >> 3);
        gBattleBots[rec].statusAmount = 0;
    } else if (skill - 0x11 <= 1) {
        gBattleBots[rec].statusType = skill;
        gBattleBots[rec].statusPart = gBattleWork.targetPart + 1;
        gBattleBots[rec].statusTimer = clamp_1_99(duration);
        gBattleBots[rec].statusAmount = clamp_1_99(power >> 2);
    } else if (skill - 0x13 <= 1) {
        gBattleBots[rec].statusType = skill;
        gBattleBots[rec].statusPart = gBattleWork.targetPart + 1;
        gBattleBots[rec].statusTimer = clamp_1_99(duration);
        gBattleBots[rec].statusAmount = clamp_1_99(power >> 1);
    } else {
        gBattleBots[rec].statusType = skill;
        gBattleBots[rec].statusPart = gBattleWork.targetPart;
        gBattleBots[rec].statusTimer = clamp_1_99(duration);
        gBattleBots[rec].statusAmount = clamp_1_99(power);
    }
}

void reset_battle_bot_state(u32 rec) {
    gBattleBots[rec].teamState = 0;
    gBattleBots[rec].parts[0].armor = 0;
    gBattleBots[rec].evasionBonus = 0;
    gBattleBots[rec].present = 2;
    gBattleBots[rec].hitFlags = 0;
    gBattleBots[rec].stateFlags &= 0xE4;
    gBattleBots[rec].hitFlags = 0;
    mem_fill8(&gBattleBots[rec].buffType, 0xC, 0);
    mem_fill8(&gBattleBots[rec].unkDC, 8, 0);
}

void staggered_sprites_spawn(u32 slot, s16 x, s16 y, u32 n) {
    u32 i;
    s32 pos_x;
    s32 pos_y;
    clear_battle_sprite_slot(slot, n);
    for (i = 0; i < n; i++) {
        gSpriteEntries[slot + i].flags = SPRITE_FLAG_VISIBLE | SPRITE_FLAG_PART_PALETTE;
        gSpriteEntries[slot + i].frame_table = 0;
        gSpriteEntries[slot + i].palette = 7;
        gSpriteEntries[slot + i].order = 0xF0;
        gSpriteEntries[slot + i].unk2C = i * 8;
        pos_x = gStaggeredSpriteOffsets[i * 2] + x;
        gSpriteEntries[slot + i].x = pos_x & 0x1FF;
        pos_y = gStaggeredSpriteOffsets[i * 2 + 1] + y;
        gSpriteEntries[slot + i].y = pos_y & 0xFF;
        battle_sprite_anim_init(gBattleSpriteAnimScripts[36], slot + i);
    }
}

u32 staggered_sprites_update(u32 slot, u32 n) {
    u32 done = 1;
    u32 i;
    u8 sprite_slot;
    const void **anim;

    for (i = 0; i < n; i++) {
        anim = gStaggeredSpriteAnimScripts;
        if (gSpriteEntries[slot + i].flags != 0) {
            if (gSpriteEntries[slot + i].unk2C != 0) {
                gSpriteEntries[slot + i].unk2C--;
                done = 0;
            } else {
                gSpriteEntries[slot + i].flags |= SPRITE_FLAG_ENABLED;
                process_sprite_anim_commands(*anim, sprite_slot = slot + i);
                if (gSpriteEntries[slot + i].unk22 == 0xFF)
                    clear_battle_sprite_slot(sprite_slot, 1);
                else
                    done = 0;
            }
        }
    }
    return done;
}

void reaction_counter_begin(void) {
    gBattleBots[gBattleWork.actor].targetBot = gBattleWork.actor + 1;
    gBattleBots[gBattleWork.actor].targetPart = gBattleWork.actorPart + 1;
    if ((gBattleWork.swapPart = gBattleWork.targetPart) == 3)
        gBattleWork.swapPart = 0;
    gBattleWork.swapBot = gBattleWork.target;
    battle_load_action_target(gBattleWork.actor);
    gBattleWork.actorSideFlags ^= 2;
    gBattleWork.hitResult = 0;
    gBattleWork.reactionFlags = 2;
    if (!(gBattleWork.actorSideFlags & 2))
        gBattleWork.closeupPoseBase[0] = 0;
    else {
        gBattleWork.closeupPoseBase[0] = 0x28;
        gBattleWork.closeupRedraw |= 1;
    }
    if (!(gBattleWork.actorSideFlags & 2)) {
        gBattleWork.closeupPoseBase[1] = 0x28;
        gBattleWork.closeupRedraw |= 2;
    } else
        gBattleWork.closeupPoseBase[1] = 0;
    gBattleWork.blockResult = 0;
    select_ai_action_type();
    determine_battle_target_mode();
}

// 1 if the part is broken or at full armor (nothing for a heal to restore).
u32 part_broken_or_undamaged(u32 rec, u32 part) {
    if (gBattleBots[rec].parts[part].armor != 0 &&
        gBattleBots[rec].parts[part].armor != gBattleBots[rec].parts[part].data[4])
        return 0;
    return 1;
}

u32 decrement_battle_timer_and_check_zero(void) {
    subtract_s16_floored(&gBattleWork.success, 0x20);
    if (gBattleWork.success != 0)
        return 0;
    return 1;
}

void calc_battle_stat_ratio(u32 rec, u32 part) {
    struct BattleWork *work = &gBattleWork;
    work->amount = work->success >> 2;
    work->amount += gBattleBots[rec].parts[part].data[6];
    work->amount = work->amount / gBattleBots[rec].parts[part].data[0xC];
    if (work->amount == 0)
        work->amount = 1;
}

void battle_set_damage_display(u32 rec, u32 part, s32 amount) {
    if (gBattleBots[rec].parts[part].data[4] >= amount) {
        gBattleWork.appliedAmount = amount;
        gBattleWork.cappedAmount = amount;
        gBattleWork.overflowAmount = 0;
    } else {
        gBattleWork.appliedAmount = gBattleBots[rec].parts[part].data[4];
        gBattleWork.cappedAmount = gBattleBots[rec].parts[part].data[4];
        gBattleWork.overflowAmount = amount - gBattleBots[rec].parts[part].data[4];
    }
}

void battle_bot_sprites_blink(u32 rec, u32 frame, u32 mask) {
    if (frame & mask) {
        gSpriteEntries[rec * 4 + 0x5A].flags |= SPRITE_FLAG_ENABLED;
        gSpriteEntries[rec * 4 + 0x5B].flags |= SPRITE_FLAG_ENABLED;
        gSpriteEntries[rec * 4 + 0x5C].flags |= SPRITE_FLAG_ENABLED;
        gSpriteEntries[rec * 4 + 0x5D].flags |= SPRITE_FLAG_ENABLED;
    } else {
        gSpriteEntries[rec * 4 + 0x5A].flags &= (u16)~SPRITE_FLAG_ENABLED;
        gSpriteEntries[rec * 4 + 0x5B].flags &= (u16)~SPRITE_FLAG_ENABLED;
        gSpriteEntries[rec * 4 + 0x5C].flags &= (u16)~SPRITE_FLAG_ENABLED;
        gSpriteEntries[rec * 4 + 0x5D].flags &= (u16)~SPRITE_FLAG_ENABLED;
    }
}

void battle_bot_sprites_show(u32 rec) {
    gSpriteEntries[rec * 4 + 0x5A].flags |= SPRITE_FLAG_ENABLED;
    gSpriteEntries[rec * 4 + 0x5B].flags |= SPRITE_FLAG_ENABLED;
    gSpriteEntries[rec * 4 + 0x5C].flags |= SPRITE_FLAG_ENABLED;
    gSpriteEntries[rec * 4 + 0x5D].flags |= SPRITE_FLAG_ENABLED;
}

void sprite_bob_step(u32 slot) {
    gSpriteEntries[slot].y = (gSpriteEntries[slot].y + gSpriteBobYSteps[gSpriteEntries[slot].unk23]) & 0xFF;
    gSpriteEntries[slot].unk23 = (gSpriteEntries[slot].unk23 + 1) & 31;
}

void calc_head_uses_taken(u32 rec, s32 amount) {
    s32 head = gBattleBots[rec].parts[0].headUses;
    if (head > amount) {
        gBattleWork.appliedAmount = amount;
        gBattleWork.cappedAmount = amount;
        gBattleWork.overflowAmount = 0;
    } else {
        gBattleWork.appliedAmount = head;
        gBattleWork.cappedAmount = head;
        gBattleWork.overflowAmount = amount - head;
    }
}

void calc_head_uses_given(u32 rec, s32 amount) {
    s32 room = gBattleBots[rec].parts[0].data[8] - gBattleBots[rec].parts[0].headUses;
    if (room > amount) {
        gBattleWork.appliedAmount = amount;
        gBattleWork.cappedAmount = amount;
        gBattleWork.overflowAmount = 0;
    } else {
        gBattleWork.appliedAmount = room;
        gBattleWork.cappedAmount = room;
        gBattleWork.overflowAmount = amount - room;
    }
}

void calc_drain_amount(u32 current, u32 amount) {
    if (current > amount) {
        gBattleWork.appliedAmount = amount;
        gBattleWork.cappedAmount = amount;
        gBattleWork.overflowAmount = 0;
        gBattleWork.partBroken = 0;
    } else {
        gBattleWork.appliedAmount = current;
        gBattleWork.cappedAmount = current;
        gBattleWork.overflowAmount = amount - current;
        gBattleWork.partBroken = 1;
    }
}

void calc_fill_amount(u32 current, u32 max, u32 amount) {
    u32 room = max - current;
    if (room > amount) {
        gBattleWork.appliedAmount = amount;
        gBattleWork.cappedAmount = amount;
        gBattleWork.overflowAmount = 0;
        gBattleWork.partBroken = 0;
    } else {
        gBattleWork.appliedAmount = room;
        gBattleWork.cappedAmount = room;
        gBattleWork.overflowAmount = amount - room;
        gBattleWork.partBroken = 1;
    }
}

u8 pick_random_change_part(u32 change_skill, u32 kind) {
    u8 ret = 0;

    rng_next_byte();
    switch (change_skill) {
    case 0:
        switch (kind) {
        case 0:
            ret = gChangeHeadPartIds[gGameWork.rngLast & 0x7F];
            break;
        case 1:
            ret = gChangeRightArmPartIds[gGameWork.rngLast & 0x7F];
            break;
        case 2:
            ret = gChangeLeftArmPartIds[gGameWork.rngLast & 0x7F];
            break;
        }
        break;
    case 1:
        switch (kind) {
        case 0:
            ret = gItrpChangeHeadPartIds[gGameWork.rngLast & 0x3F];
            break;
        case 1:
            ret = gItrpChangeRightArmPartIds[gGameWork.rngLast & 0x3F];
            break;
        case 2:
            ret = gItrpChangeLeftArmPartIds[gGameWork.rngLast & 0x3F];
            break;
        }
        break;
    case 2:
        switch (kind) {
        case 0:
            ret = gAttackChangeHeadPartIds[gGameWork.rngLast & 0x3F];
            break;
        case 1:
            ret = gAttackChangeRightArmPartIds[gGameWork.rngLast & 0x3F];
            break;
        case 2:
            ret = gAttackChangeLeftArmPartIds[gGameWork.rngLast & 0x3F];
            break;
        }
        break;
    case 3:
        switch (kind) {
        case 0:
            ret = gDefenseChangeHeadPartIds[gGameWork.rngLast & 0x3F];
            break;
        case 1:
            ret = gDefenseChangeRightArmPartIds[gGameWork.rngLast & 0x3F];
            break;
        case 2:
            ret = gDefenseChangeLeftArmPartIds[gGameWork.rngLast & 0x3F];
            break;
        }
        break;
    default:
        switch (kind) {
        case 0:
            ret = gHealChangeHeadPartIds[gGameWork.rngLast & 0x3F];
            break;
        case 1:
            ret = gHealChangeRightArmPartIds[gGameWork.rngLast & 0x3F];
            break;
        case 2:
            ret = gHealChangeLeftArmPartIds[gGameWork.rngLast & 0x3F];
            break;
        }
        break;
    }
    return ret;
}

void medaforce_calc_success(u32 rec) {
    gBattleWork.success = 0;
    gBattleWork.success = gBattleBots[rec].medaforce[3];
    gBattleWork.success += calc_bot_matching_part_power(rec);
    gBattleWork.success += rng_next_byte() & 7;
    gBattleWork.success += gBattleBots[rec].medal.skillLevel[gBattleBots[rec].medaforce[1]];
}

void medaforce_calc_damage(u32 rec) {
    gBattleWork.amount = gBattleWork.success >> 3;
    gBattleWork.amount += gBattleBots[rec].medaforce[4];
    if (gBattleWork.amount == 0)
        gBattleWork.amount = 1;
}

// Medaforce hit list entry for one part: partDamage = damage it takes (capped at its armor), partBreaks = 1 if that
// breaks it. No return statement: the original never sets r0 but is not void (`pop {r1}` epilogue).
u32 hit_list_set_part_damage(u32 rec, u32 part, u32 amount) {
    if (gBattleBots[rec].parts[part].armor == 0) {
        gBattleWork.partDamage[part] = 0;
        gBattleWork.partBreaks[part] = 0;
    } else if (gBattleBots[rec].parts[part].armor > amount) {
        gBattleWork.partDamage[part] = amount;
        gBattleWork.partBreaks[part] = 0;
    } else {
        gBattleWork.partDamage[part] = gBattleBots[rec].parts[part].armor;
        gBattleWork.partBreaks[part] = 1;
    }
}

// guess: a random living bot from base..base+2 that is guarding (unkBD bit 3 or 4) with its guard part intact.
u32 battle_find_guarding_enemy(u32 base) {
    u32 i, j, dir;

    i = rng_random_slot();
    dir = rng_next_byte() & 1;
    for (j = 0; j <= 2; j++) {
        if (gBattleBots[base + i].teamState &&
            ((gBattleBots[base + i].stateFlags & 8) || (gBattleBots[base + i].stateFlags & 0x10)) &&
            gBattleBots[base + i].parts[gBattleBots[base + i].lastAction - 1].armor)
            return base + i;
        if (dir) {
            if (++i > 2)
                i = 0;
        } else if (i == 0)
            i = 2;
        else
            i--;
    }
    return 0xFF;
}

// A random living bot from base..base+2 with the same leg type (parts[3].data[1]) as rec, else 0xFF.
u32 battle_find_enemy_same_legs(u32 base, u32 rec) {
    u32 i, j, dir;

    i = rng_random_slot();
    dir = rng_next_byte() & 1;
    for (j = 0; j <= 2; j++) {
        if (gBattleBots[base + i].teamState &&
            gBattleBots[base + i].parts[3].data[1] == gBattleBots[rec].parts[3].data[1])
            return base + i;
        if (dir) {
            if (++i > 2)
                i = 0;
        } else if (i == 0)
            i = 2;
        else
            i--;
    }
    return 0xFF;
}
