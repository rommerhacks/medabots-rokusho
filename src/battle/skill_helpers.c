// Helpers for the skill effect sequences (battle/*_skills, medaforce_effects): damage split, action
// counters, Medal exp progress, action parameters, bot state reset, the cursor sprite, skill timers and
// stat ratios, and random target selection.

#include "global.h"

void battle_calc_damage_split(u32 rec, u32 part, s32 amount) {
    s32 room = gUnk_03000590[rec].parts[part].data[4] - gUnk_03000590[rec].parts[part].unk11;
    if (room > amount) {
        gUnk_03001800.unkC8 = amount;
        gUnk_03001800.unkCC = amount;
        gUnk_03001800.unkCA = 0;
    } else {
        gUnk_03001800.unkC8 = room;
        gUnk_03001800.unkCC = room;
        gUnk_03001800.unkCA = amount - room;
    }
}

u32 armor_heal_step(u16 *amount, u32 rec, u32 part) {
    u8 *n = (u8 *)amount;
    if (gUnk_03000590[rec].parts[part].unk11 != gUnk_03000590[rec].parts[part].data[4]) {
        gUnk_03000590[rec].parts[part].unk11++;
        if (--*n != 0)
            return 0;
    }
    return 1;
}

u32 bot_has_status_guard(u32 rec, u32 skill) {
    if (skill - 0xd <= 1) {
        if (gUnk_03000590[rec].unkCF & 1)
            return 1;
        return 0;
    } else if (skill - 0xf <= 1) {
        if (gUnk_03000590[rec].unkCF & 8)
            return 1;
        return 0;
    } else if (skill - 0x11 <= 1) {
        if (gUnk_03000590[rec].unkCF & 2)
            return 1;
        return 0;
    } else if (skill - 0x13 <= 1) {
        if (gUnk_03000590[rec].unkCF & 4)
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
        gUnk_03000590[rec].unkC9 = skill;
        gUnk_03000590[rec].unkCA = gUnk_03001800.unk8B + 1;
        gUnk_03000590[rec].unkCB = clamp_1_99(a);
        gUnk_03000590[rec].unkCC = clamp_1_99(b * 2);
    } else if (skill - 0xF <= 1) {
        gUnk_03000590[rec].unkC9 = skill;
        gUnk_03000590[rec].unkCA = gUnk_03001800.unk8B + 1;
        gUnk_03000590[rec].unkCB = clamp_1_99(b >> 3);
        gUnk_03000590[rec].unkCC = 0;
    } else if (skill - 0x11 <= 1) {
        gUnk_03000590[rec].unkC9 = skill;
        gUnk_03000590[rec].unkCA = gUnk_03001800.unk8B + 1;
        gUnk_03000590[rec].unkCB = clamp_1_99(a);
        gUnk_03000590[rec].unkCC = clamp_1_99(b >> 2);
    } else if (skill - 0x13 <= 1) {
        gUnk_03000590[rec].unkC9 = skill;
        gUnk_03000590[rec].unkCA = gUnk_03001800.unk8B + 1;
        gUnk_03000590[rec].unkCB = clamp_1_99(a);
        gUnk_03000590[rec].unkCC = clamp_1_99(b >> 1);
    } else {
        gUnk_03000590[rec].unkC9 = skill;
        gUnk_03000590[rec].unkCA = gUnk_03001800.unk8B;
        gUnk_03000590[rec].unkCB = clamp_1_99(a);
        gUnk_03000590[rec].unkCC = clamp_1_99(b);
    }
}

void reset_battle_bot_state(u32 rec) {
    gUnk_03000590[rec].unk40 = 0;
    gUnk_03000590[rec].parts[0].unk11 = 0;
    gUnk_03000590[rec].unkB9 = 0;
    gUnk_03000590[rec].unkBA = 2;
    gUnk_03000590[rec].unkBC = 0;
    gUnk_03000590[rec].unkBD &= 0xE4;
    gUnk_03000590[rec].unkBC = 0;
    mem_fill8(&gUnk_03000590[rec].unkC4, 0xC, 0);
    mem_fill8(&gUnk_03000590[rec].unkDC, 8, 0);
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
    gUnk_03000590[gUnk_03001800.unk87].unkE0 = gUnk_03001800.unk87 + 1;
    gUnk_03000590[gUnk_03001800.unk87].unkE1 = gUnk_03001800.unkA7 + 1;
    if ((gUnk_03001800.unk162 = gUnk_03001800.unk8B) == 3)
        gUnk_03001800.unk162 = 0;
    gUnk_03001800.unk161 = gUnk_03001800.unk88;
    battle_load_action_target(gUnk_03001800.unk87);
    gUnk_03001800.unkF8 ^= 2;
    gUnk_03001800.unkB7 = 0;
    gUnk_03001800.unkF6 = 2;
    if (!(gUnk_03001800.unkF8 & 2))
        gUnk_03001800.unk114[0] = 0;
    else {
        gUnk_03001800.unk114[0] = 0x28;
        gUnk_03001800.unkFF |= 1;
    }
    if (!(gUnk_03001800.unkF8 & 2)) {
        gUnk_03001800.unk114[1] = 0x28;
        gUnk_03001800.unkFF |= 2;
    } else
        gUnk_03001800.unk114[1] = 0;
    gUnk_03001800.unkB8 = 0;
    select_ai_action_type();
    determine_battle_target_mode();
}

// 1 if the part is broken or at full armor (nothing for a heal to restore).
u32 part_broken_or_undamaged(u32 rec, u32 part) {
    if (gUnk_03000590[rec].parts[part].unk11 != 0 &&
        gUnk_03000590[rec].parts[part].unk11 != gUnk_03000590[rec].parts[part].data[4])
        return 0;
    return 1;
}

u32 decrement_battle_timer_and_check_zero(void) {
    subtract_s16_floored(&gUnk_03001800.unkE8, 0x20);
    if (gUnk_03001800.unkE8 != 0)
        return 0;
    return 1;
}

void calc_battle_stat_ratio(u32 rec, u32 part) {
    struct Unk_03001800 *b = &gUnk_03001800;
    b->unkEC = b->unkE8 >> 2;
    b->unkEC += gUnk_03000590[rec].parts[part].data[6];
    b->unkEC = b->unkEC / gUnk_03000590[rec].parts[part].data[0xC];
    if (b->unkEC == 0)
        b->unkEC = 1;
}

void battle_set_damage_display(u32 rec, u32 part, s32 amount) {
    if (gUnk_03000590[rec].parts[part].data[4] >= amount) {
        gUnk_03001800.unkC8 = amount;
        gUnk_03001800.unkCC = amount;
        gUnk_03001800.unkCA = 0;
    } else {
        gUnk_03001800.unkC8 = gUnk_03000590[rec].parts[part].data[4];
        gUnk_03001800.unkCC = gUnk_03000590[rec].parts[part].data[4];
        gUnk_03001800.unkCA = amount - gUnk_03000590[rec].parts[part].data[4];
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
    s32 head = gUnk_03000590[rec].parts[0].unk10;
    if (head > amount) {
        gUnk_03001800.unkC8 = amount;
        gUnk_03001800.unkCC = amount;
        gUnk_03001800.unkCA = 0;
    } else {
        gUnk_03001800.unkC8 = head;
        gUnk_03001800.unkCC = head;
        gUnk_03001800.unkCA = amount - head;
    }
}

void calc_head_uses_given(u32 rec, s32 amount) {
    s32 room = gUnk_03000590[rec].parts[0].data[8] - gUnk_03000590[rec].parts[0].unk10;
    if (room > amount) {
        gUnk_03001800.unkC8 = amount;
        gUnk_03001800.unkCC = amount;
        gUnk_03001800.unkCA = 0;
    } else {
        gUnk_03001800.unkC8 = room;
        gUnk_03001800.unkCC = room;
        gUnk_03001800.unkCA = amount - room;
    }
}

void calc_drain_amount(u32 a, u32 b) {
    if (a > b) {
        gUnk_03001800.unkC8 = b;
        gUnk_03001800.unkCC = b;
        gUnk_03001800.unkCA = 0;
        gUnk_03001800.unkD1 = 0;
    } else {
        gUnk_03001800.unkC8 = a;
        gUnk_03001800.unkCC = a;
        gUnk_03001800.unkCA = b - a;
        gUnk_03001800.unkD1 = 1;
    }
}

void calc_fill_amount(u32 a, u32 max, u32 b) {
    u32 room = max - a;
    if (room > b) {
        gUnk_03001800.unkC8 = b;
        gUnk_03001800.unkCC = b;
        gUnk_03001800.unkCA = 0;
        gUnk_03001800.unkD1 = 0;
    } else {
        gUnk_03001800.unkC8 = room;
        gUnk_03001800.unkCC = room;
        gUnk_03001800.unkCA = b - room;
        gUnk_03001800.unkD1 = 1;
    }
}

u8 pick_random_change_part(u32 a, u32 kind) {
    u8 ret = 0;

    rng_next_byte();
    switch (a) {
    case 0:
        switch (kind) {
        case 0:
            ret = gUnk_083CED08[gUnk_03000440.unk8C & 0x7F];
            break;
        case 1:
            ret = gUnk_083CED88[gUnk_03000440.unk8C & 0x7F];
            break;
        case 2:
            ret = gUnk_083CEE08[gUnk_03000440.unk8C & 0x7F];
            break;
        }
        break;
    case 1:
        switch (kind) {
        case 0:
            ret = gUnk_083CEE88[gUnk_03000440.unk8C & 0x3F];
            break;
        case 1:
            ret = gUnk_083CEEC8[gUnk_03000440.unk8C & 0x3F];
            break;
        case 2:
            ret = gUnk_083CEF08[gUnk_03000440.unk8C & 0x3F];
            break;
        }
        break;
    case 2:
        switch (kind) {
        case 0:
            ret = gUnk_083CEF48[gUnk_03000440.unk8C & 0x3F];
            break;
        case 1:
            ret = gUnk_083CEF88[gUnk_03000440.unk8C & 0x3F];
            break;
        case 2:
            ret = gUnk_083CEFC8[gUnk_03000440.unk8C & 0x3F];
            break;
        }
        break;
    case 3:
        switch (kind) {
        case 0:
            ret = gUnk_083CF008[gUnk_03000440.unk8C & 0x3F];
            break;
        case 1:
            ret = gUnk_083CF048[gUnk_03000440.unk8C & 0x3F];
            break;
        case 2:
            ret = gUnk_083CF088[gUnk_03000440.unk8C & 0x3F];
            break;
        }
        break;
    default:
        switch (kind) {
        case 0:
            ret = gUnk_083CF0C8[gUnk_03000440.unk8C & 0x3F];
            break;
        case 1:
            ret = gUnk_083CF108[gUnk_03000440.unk8C & 0x3F];
            break;
        case 2:
            ret = gUnk_083CF148[gUnk_03000440.unk8C & 0x3F];
            break;
        }
        break;
    }
    return ret;
}

void medaforce_calc_success(u32 rec) {
    gUnk_03001800.unkE8 = 0;
    gUnk_03001800.unkE8 = gUnk_03000590[rec].unkA8[3];
    gUnk_03001800.unkE8 += calc_bot_matching_part_power(rec);
    gUnk_03001800.unkE8 += rng_next_byte() & 7;
    gUnk_03001800.unkE8 += gUnk_03000590[rec].medal.unk20[gUnk_03000590[rec].unkA8[1]];
}

void medaforce_calc_damage(u32 rec) {
    gUnk_03001800.unkEC = gUnk_03001800.unkE8 >> 3;
    gUnk_03001800.unkEC += gUnk_03000590[rec].unkA8[4];
    if (gUnk_03001800.unkEC == 0)
        gUnk_03001800.unkEC = 1;
}

// Medaforce hit list entry for one part: unkD6 = damage it takes (capped at its armor), unkD2 = 1 if that breaks it.
// No return statement: the original never sets r0 but is not void (`pop {r1}` epilogue).
u32 hit_list_set_part_damage(u32 rec, u32 part, u32 amount) {
    if (gUnk_03000590[rec].parts[part].unk11 == 0) {
        gUnk_03001800.unkD6[part] = 0;
        gUnk_03001800.unkD2[part] = 0;
    } else if (gUnk_03000590[rec].parts[part].unk11 > amount) {
        gUnk_03001800.unkD6[part] = amount;
        gUnk_03001800.unkD2[part] = 0;
    } else {
        gUnk_03001800.unkD6[part] = gUnk_03000590[rec].parts[part].unk11;
        gUnk_03001800.unkD2[part] = 1;
    }
}

// guess: a random living bot from base..base+2 that is guarding (unkBD bit 3 or 4) with its guard part intact.
u32 battle_find_guarding_enemy(u32 base) {
    u32 i, j, dir;

    i = rng_random_slot();
    dir = rng_next_byte() & 1;
    for (j = 0; j <= 2; j++) {
        if (gUnk_03000590[base + i].unk40 &&
            ((gUnk_03000590[base + i].unkBD & 8) || (gUnk_03000590[base + i].unkBD & 0x10)) &&
            gUnk_03000590[base + i].parts[gUnk_03000590[base + i].unkDE - 1].unk11)
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
        if (gUnk_03000590[base + i].unk40 &&
            gUnk_03000590[base + i].parts[3].data[1] == gUnk_03000590[rec].parts[3].data[1])
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
