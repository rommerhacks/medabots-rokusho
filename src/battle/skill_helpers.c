// Helpers for the skill effect sequences (battle/*_skills, medaforce_effects): damage split, action
// counters, Medal exp progress, action parameters, bot state reset, the cursor sprite, skill timers and
// stat ratios, and random target selection.

#include "global.h"

void battle_calc_damage_split(u32 rec, u32 part, s32 amount) {
    s32 room = gBattleBots[rec].parts[part].data[4] - gBattleBots[rec].parts[part].unk11;
    if (room > amount) {
        gBattleWork.appliedAmount = amount;
        gBattleWork.unkCC = amount;
        gBattleWork.overflowAmount = 0;
    } else {
        gBattleWork.appliedAmount = room;
        gBattleWork.unkCC = room;
        gBattleWork.overflowAmount = amount - room;
    }
}

u32 armor_heal_step(u16 *amount, u32 rec, u32 part) {
    u8 *n = (u8 *)amount;
    if (gBattleBots[rec].parts[part].unk11 != gBattleBots[rec].parts[part].data[4]) {
        gBattleBots[rec].parts[part].unk11++;
        if (--*n != 0)
            return 0;
    }
    return 1;
}

u32 bot_has_status_guard(u32 rec, u32 skill) {
    if (skill - 0xd <= 1) {
        if (gBattleBots[rec].unkCF & 1)
            return 1;
        return 0;
    } else if (skill - 0xf <= 1) {
        if (gBattleBots[rec].unkCF & 8)
            return 1;
        return 0;
    } else if (skill - 0x11 <= 1) {
        if (gBattleBots[rec].unkCF & 2)
            return 1;
        return 0;
    } else if (skill - 0x13 <= 1) {
        if (gBattleBots[rec].unkCF & 4)
            return 1;
        return 0;
    }
    return 0;
}

u32 sprite_slide_x_step(u32 slot, u32 n) {
    if (!(gSpriteEntries[slot].unk0 & 0x8000) || gSpriteEntries[slot].unk23 == 0x10)
        return 1;
    if (n == 0)
        gSpriteEntries[slot].unk2 = gSpriteEntries[slot].unk2 + gUnk_083AF4B0[gSpriteEntries[slot].unk23];
    else
        gSpriteEntries[slot].unk2 = gSpriteEntries[slot].unk2 - gUnk_083AF4B0[gSpriteEntries[slot].unk23];
    gSpriteEntries[slot].unk23++;
    return 0;
}

u32 clamp_1_99(u32 a) {
    if (a > 99)
        a = 99;
    else if (a == 0)
        a = 1;
    return a;
}

void battle_inflict_status(u32 rec, u32 skill, s32 a, u32 b) {
    if (skill - 0xD <= 1) {
        gBattleBots[rec].statusType = skill;
        gBattleBots[rec].statusPart = gBattleWork.targetPart + 1;
        gBattleBots[rec].statusTimer = clamp_1_99(a);
        gBattleBots[rec].statusAmount = clamp_1_99(b * 2);
    } else if (skill - 0xF <= 1) {
        gBattleBots[rec].statusType = skill;
        gBattleBots[rec].statusPart = gBattleWork.targetPart + 1;
        gBattleBots[rec].statusTimer = clamp_1_99(b >> 3);
        gBattleBots[rec].statusAmount = 0;
    } else if (skill - 0x11 <= 1) {
        gBattleBots[rec].statusType = skill;
        gBattleBots[rec].statusPart = gBattleWork.targetPart + 1;
        gBattleBots[rec].statusTimer = clamp_1_99(a);
        gBattleBots[rec].statusAmount = clamp_1_99(b >> 2);
    } else if (skill - 0x13 <= 1) {
        gBattleBots[rec].statusType = skill;
        gBattleBots[rec].statusPart = gBattleWork.targetPart + 1;
        gBattleBots[rec].statusTimer = clamp_1_99(a);
        gBattleBots[rec].statusAmount = clamp_1_99(b >> 1);
    } else {
        gBattleBots[rec].statusType = skill;
        gBattleBots[rec].statusPart = gBattleWork.targetPart;
        gBattleBots[rec].statusTimer = clamp_1_99(a);
        gBattleBots[rec].statusAmount = clamp_1_99(b);
    }
}

void reset_battle_bot_state(u32 rec) {
    gBattleBots[rec].teamState = 0;
    gBattleBots[rec].parts[0].unk11 = 0;
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
    s32 t1;
    s32 t2;
    clear_battle_sprite_slot(slot, n);
    for (i = 0; i < n; i++) {
        gSpriteEntries[slot + i].unk0 = 0x4004;
        gSpriteEntries[slot + i].unk1C = 0;
        gSpriteEntries[slot + i].unkA = 7;
        gSpriteEntries[slot + i].unkB = 0xF0;
        gSpriteEntries[slot + i].unk2C = i * 8;
        t1 = gUnk_083AF4C0[i * 2] + x;
        gSpriteEntries[slot + i].unk2 = t1 & 0x1FF;
        t2 = gUnk_083AF4C0[i * 2 + 1] + y;
        gSpriteEntries[slot + i].unk4 = t2 & 0xFF;
        init_battle_sprite_entry_08040B90(gUnk_083B5F80[36], slot + i);
    }
}

u32 staggered_sprites_update(u32 slot, u32 n) {
    u32 done = 1;
    u32 i;
    u8 s;
    const void **anim;

    for (i = 0; i < n; i++) {
        anim = gUnk_083B6010;
        if (gSpriteEntries[slot + i].unk0 != 0) {
            if (gSpriteEntries[slot + i].unk2C != 0) {
                gSpriteEntries[slot + i].unk2C--;
                done = 0;
            } else {
                gSpriteEntries[slot + i].unk0 |= 0x8000;
                process_sprite_anim_commands(*anim, s = slot + i);
                if (gSpriteEntries[slot + i].unk22 == 0xFF)
                    clear_battle_sprite_slot(s, 1);
                else
                    done = 0;
            }
        }
    }
    return done;
}

void reaction_counter_begin(void) {
    gBattleBots[gBattleWork.actor].unkE0 = gBattleWork.actor + 1;
    gBattleBots[gBattleWork.actor].unkE1 = gBattleWork.actorPart + 1;
    if ((gBattleWork.unk162 = gBattleWork.targetPart) == 3)
        gBattleWork.unk162 = 0;
    gBattleWork.unk161 = gBattleWork.target;
    battle_load_action_target(gBattleWork.actor);
    gBattleWork.actorSideFlags ^= 2;
    gBattleWork.hitResult = 0;
    gBattleWork.unkF6 = 2;
    if (!(gBattleWork.actorSideFlags & 2))
        gBattleWork.unk114[0] = 0;
    else {
        gBattleWork.unk114[0] = 0x28;
        gBattleWork.unkFF |= 1;
    }
    if (!(gBattleWork.actorSideFlags & 2)) {
        gBattleWork.unk114[1] = 0x28;
        gBattleWork.unkFF |= 2;
    } else
        gBattleWork.unk114[1] = 0;
    gBattleWork.blockResult = 0;
    select_ai_action_type();
    determine_battle_target_mode();
}

// 1 if the part is broken or at full armor (nothing for a heal to restore).
u32 part_broken_or_undamaged(u32 rec, u32 part) {
    if (gBattleBots[rec].parts[part].unk11 != 0 &&
        gBattleBots[rec].parts[part].unk11 != gBattleBots[rec].parts[part].data[4])
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
    struct BattleWork *b = &gBattleWork;
    b->amount = b->success >> 2;
    b->amount += gBattleBots[rec].parts[part].data[6];
    b->amount = b->amount / gBattleBots[rec].parts[part].data[0xC];
    if (b->amount == 0)
        b->amount = 1;
}

void battle_set_damage_display(u32 rec, u32 part, s32 amount) {
    if (gBattleBots[rec].parts[part].data[4] >= amount) {
        gBattleWork.appliedAmount = amount;
        gBattleWork.unkCC = amount;
        gBattleWork.overflowAmount = 0;
    } else {
        gBattleWork.appliedAmount = gBattleBots[rec].parts[part].data[4];
        gBattleWork.unkCC = gBattleBots[rec].parts[part].data[4];
        gBattleWork.overflowAmount = amount - gBattleBots[rec].parts[part].data[4];
    }
}

void battle_bot_sprites_blink(u32 rec, u32 frame, u32 mask) {
    if (frame & mask) {
        gSpriteEntries[rec * 4 + 0x5A].unk0 |= 0x8000;
        gSpriteEntries[rec * 4 + 0x5B].unk0 |= 0x8000;
        gSpriteEntries[rec * 4 + 0x5C].unk0 |= 0x8000;
        gSpriteEntries[rec * 4 + 0x5D].unk0 |= 0x8000;
    } else {
        gSpriteEntries[rec * 4 + 0x5A].unk0 &= 0x7FFF;
        gSpriteEntries[rec * 4 + 0x5B].unk0 &= 0x7FFF;
        gSpriteEntries[rec * 4 + 0x5C].unk0 &= 0x7FFF;
        gSpriteEntries[rec * 4 + 0x5D].unk0 &= 0x7FFF;
    }
}

void battle_bot_sprites_show(u32 rec) {
    gSpriteEntries[rec * 4 + 0x5A].unk0 |= 0x8000;
    gSpriteEntries[rec * 4 + 0x5B].unk0 |= 0x8000;
    gSpriteEntries[rec * 4 + 0x5C].unk0 |= 0x8000;
    gSpriteEntries[rec * 4 + 0x5D].unk0 |= 0x8000;
}

void sprite_bob_step(u32 slot) {
    gSpriteEntries[slot].unk4 = (gSpriteEntries[slot].unk4 + gUnk_083AF4E0[gSpriteEntries[slot].unk23]) & 0xFF;
    gSpriteEntries[slot].unk23 = (gSpriteEntries[slot].unk23 + 1) & 31;
}

void calc_head_uses_taken(u32 rec, s32 amount) {
    s32 head = gBattleBots[rec].parts[0].unk10;
    if (head > amount) {
        gBattleWork.appliedAmount = amount;
        gBattleWork.unkCC = amount;
        gBattleWork.overflowAmount = 0;
    } else {
        gBattleWork.appliedAmount = head;
        gBattleWork.unkCC = head;
        gBattleWork.overflowAmount = amount - head;
    }
}

void calc_head_uses_given(u32 rec, s32 amount) {
    s32 room = gBattleBots[rec].parts[0].data[8] - gBattleBots[rec].parts[0].unk10;
    if (room > amount) {
        gBattleWork.appliedAmount = amount;
        gBattleWork.unkCC = amount;
        gBattleWork.overflowAmount = 0;
    } else {
        gBattleWork.appliedAmount = room;
        gBattleWork.unkCC = room;
        gBattleWork.overflowAmount = amount - room;
    }
}

void calc_drain_amount(u32 a, u32 b) {
    if (a > b) {
        gBattleWork.appliedAmount = b;
        gBattleWork.unkCC = b;
        gBattleWork.overflowAmount = 0;
        gBattleWork.partBroken = 0;
    } else {
        gBattleWork.appliedAmount = a;
        gBattleWork.unkCC = a;
        gBattleWork.overflowAmount = b - a;
        gBattleWork.partBroken = 1;
    }
}

void calc_fill_amount(u32 a, u32 max, u32 b) {
    u32 room = max - a;
    if (room > b) {
        gBattleWork.appliedAmount = b;
        gBattleWork.unkCC = b;
        gBattleWork.overflowAmount = 0;
        gBattleWork.partBroken = 0;
    } else {
        gBattleWork.appliedAmount = room;
        gBattleWork.unkCC = room;
        gBattleWork.overflowAmount = b - room;
        gBattleWork.partBroken = 1;
    }
}

u8 pick_random_change_part(u32 a, u32 kind) {
    u8 ret = 0;

    rng_next_byte();
    switch (a) {
    case 0:
        switch (kind) {
        case 0:
            ret = gUnk_083CED08[gGameWork.rngLast & 0x7F];
            break;
        case 1:
            ret = gUnk_083CED88[gGameWork.rngLast & 0x7F];
            break;
        case 2:
            ret = gUnk_083CEE08[gGameWork.rngLast & 0x7F];
            break;
        }
        break;
    case 1:
        switch (kind) {
        case 0:
            ret = gUnk_083CEE88[gGameWork.rngLast & 0x3F];
            break;
        case 1:
            ret = gUnk_083CEEC8[gGameWork.rngLast & 0x3F];
            break;
        case 2:
            ret = gUnk_083CEF08[gGameWork.rngLast & 0x3F];
            break;
        }
        break;
    case 2:
        switch (kind) {
        case 0:
            ret = gUnk_083CEF48[gGameWork.rngLast & 0x3F];
            break;
        case 1:
            ret = gUnk_083CEF88[gGameWork.rngLast & 0x3F];
            break;
        case 2:
            ret = gUnk_083CEFC8[gGameWork.rngLast & 0x3F];
            break;
        }
        break;
    case 3:
        switch (kind) {
        case 0:
            ret = gUnk_083CF008[gGameWork.rngLast & 0x3F];
            break;
        case 1:
            ret = gUnk_083CF048[gGameWork.rngLast & 0x3F];
            break;
        case 2:
            ret = gUnk_083CF088[gGameWork.rngLast & 0x3F];
            break;
        }
        break;
    default:
        switch (kind) {
        case 0:
            ret = gUnk_083CF0C8[gGameWork.rngLast & 0x3F];
            break;
        case 1:
            ret = gUnk_083CF108[gGameWork.rngLast & 0x3F];
            break;
        case 2:
            ret = gUnk_083CF148[gGameWork.rngLast & 0x3F];
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

// Medaforce hit list entry for one part: unkD6 = damage it takes (capped at its armor), unkD2 = 1 if that breaks it.
// No return statement: the original never sets r0 but is not void (`pop {r1}` epilogue).
u32 hit_list_set_part_damage(u32 rec, u32 part, u32 amount) {
    if (gBattleBots[rec].parts[part].unk11 == 0) {
        gBattleWork.unkD6[part] = 0;
        gBattleWork.unkD2[part] = 0;
    } else if (gBattleBots[rec].parts[part].unk11 > amount) {
        gBattleWork.unkD6[part] = amount;
        gBattleWork.unkD2[part] = 0;
    } else {
        gBattleWork.unkD6[part] = gBattleBots[rec].parts[part].unk11;
        gBattleWork.unkD2[part] = 1;
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
            gBattleBots[base + i].parts[gBattleBots[base + i].lastAction - 1].unk11)
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
