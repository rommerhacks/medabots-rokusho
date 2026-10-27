// Combat helpers shared by the action steps and the skill modules: damage against a part's armor, the
// target cursor and sprite positions, stat reductions, the defeated list, sprite movement toward a target,
// evasion weights, and the part / ability checks the AI (battle/action_calc) uses (check_bot_can_*).

#include "global.h"

static u32 check_sprite_in_range(u32 slot);

// Whether the head or an arm has skill 0x15 Break Form (ROM skill list); trap_hit_check lets it break traps.
u32 bot_has_break_form_part(u32 rec) {
    u32 i;
    for (i = 0; i <= 2; i++)
        if (gBattleBots[rec].parts[i].data[1] == 0x15)
            return 1;
    return 0;
}

void battle_set_damage_vs_armor(u32 rec, u32 part, s32 amount) {
    s32 armor = gBattleBots[rec].parts[part].unk11;
    if (armor > amount) {
        gBattleWork.unkC8 = amount;
        gBattleWork.unkCC = amount;
        gBattleWork.unkCA = 0;
        gBattleWork.unkD1 = 0;
    } else {
        gBattleWork.unkC8 = armor;
        gBattleWork.unkCC = armor;
        gBattleWork.unkCA = amount - armor;
        gBattleWork.unkD1 = 1;
    }
}

void set_target_sprite_position(u32 rec, u32 dir, u32 axis) {
    if (axis == 0) {
        switch ((dir & 6) >> 1) {
        case 1:
            gSpriteEntries[rec * 4 + 0x5D].unk2 = gBattleWork.unk13C[rec].x + 1;
            gSpriteEntries[rec * 4 + 0x5D].unk4 = gBattleWork.unk13C[rec].y;
            break;
        case 3:
            gSpriteEntries[rec * 4 + 0x5D].unk2 = gBattleWork.unk13C[rec].x - 1;
            gSpriteEntries[rec * 4 + 0x5D].unk4 = gBattleWork.unk13C[rec].y;
            break;
        default:
            gSpriteEntries[rec * 4 + 0x5D].unk2 = gBattleWork.unk13C[rec].x;
            gSpriteEntries[rec * 4 + 0x5D].unk4 = gBattleWork.unk13C[rec].y;
            break;
        }
    } else {
        switch ((dir & 6) >> 1) {
        case 1:
            gSpriteEntries[rec * 4 + 0x5D].unk4 = gBattleWork.unk13C[rec].y - 2;
            break;
        case 3:
            gSpriteEntries[rec * 4 + 0x5D].unk4 = gBattleWork.unk13C[rec].y;
            break;
        default:
            gSpriteEntries[rec * 4 + 0x5D].unk4 = gBattleWork.unk13C[rec].y - 1;
            break;
        }
    }
    target_cursor_place_markers(rec);
}

// Places the three marker sprites above, left of and right of the target cursor sprite (rec * 4 + 0x5D).
void target_cursor_place_markers(u32 rec) {
    gSpriteEntries[rec * 4 + 0x5A].unk2 = gSpriteEntries[rec * 4 + 0x5D].unk2;
    gSpriteEntries[rec * 4 + 0x5A].unk4 = gSpriteEntries[rec * 4 + 0x5D].unk4 - 8;
    gSpriteEntries[rec * 4 + 0x5B].unk2 = gSpriteEntries[rec * 4 + 0x5D].unk2 - 8;
    gSpriteEntries[rec * 4 + 0x5B].unk4 = gSpriteEntries[rec * 4 + 0x5D].unk4;
    gSpriteEntries[rec * 4 + 0x5C].unk2 = gSpriteEntries[rec * 4 + 0x5D].unk2 + 8;
    gSpriteEntries[rec * 4 + 0x5C].unk4 = gSpriteEntries[rec * 4 + 0x5D].unk4;
}

void update_target_cursor_position(u32 rec) {
    gSpriteEntries[rec * 4 + 0x5D].unk2 = gBattleWork.unk13C[rec].x;
    gSpriteEntries[rec * 4 + 0x5D].unk4 = gBattleWork.unk13C[rec].y + 4;
    target_cursor_place_markers(rec);
}

void reduce_bot_part_stat(u32 rec, u32 part, s32 amount) {
    if (gBattleBots[rec].parts[part].unk11 < amount)
        gBattleBots[rec].parts[part].unk11 = 0;
    else
        gBattleBots[rec].parts[part].unk11 -= amount;
}

void bot_halve_broken_leg_stats(u32 rec) {
    if (gBattleBots[rec].parts[3].unk11 == 0) {
        gBattleBots[rec].parts[3].unk12 = gBattleBots[rec].parts[3].data[5] >> 1;
        gBattleBots[rec].parts[3].unk13 = gBattleBots[rec].parts[3].data[6] >> 1;
        gBattleBots[rec].parts[3].unk14 = gBattleBots[rec].parts[3].data[7] >> 1;
        gBattleBots[rec].parts[3].unk15 = gBattleBots[rec].parts[3].data[8] >> 1;
        gBattleBots[rec].parts[3].unk16 = gBattleBots[rec].parts[3].data[9] >> 1;
    }
}

// Undoes bot_halve_broken_leg_stats: reloads the leg stats from the part data while the legs have armor.
void bot_restore_leg_stats(u32 rec) {
    if (gBattleBots[rec].parts[3].unk11 != 0) {
        gBattleBots[rec].parts[3].unk12 = gBattleBots[rec].parts[3].data[5];
        gBattleBots[rec].parts[3].unk13 = gBattleBots[rec].parts[3].data[6];
        gBattleBots[rec].parts[3].unk14 = gBattleBots[rec].parts[3].data[7];
        gBattleBots[rec].parts[3].unk15 = gBattleBots[rec].parts[3].data[8];
        gBattleBots[rec].parts[3].unk16 = gBattleBots[rec].parts[3].data[9];
    }
}

void add_bot_to_defeated_list(u32 rec) {
    u32 i;
    if (gBattleBots[rec].parts[0].unk11 == 0) {
        for (i = 0; i <= 2; i++) {
            if (gBattleWork.unkE0[i] == 0) {
                gBattleWork.unkE0[i] = rec + 1;
                return;
            }
        }
    }
}

u32 sprite_move_toward_target(u32 slot, s16 x, s16 y) {
    struct SpriteEntry *base = gSpriteEntries;
    struct SpriteEntry *s = &base[slot];
    u32 step;
    u32 pos;

    s->unk25 += gUnk_083AF210[s->unk30];
    step = s->unk25;
    s->unk25 = step % 4;
    pos = ((step >> 2) + (u16)s->unk4) & 0xFF;
    s->unk4 = pos;
    if ((s32)pos >= x && (s32)pos <= y) {
        s->unk4 = x;
        return 1;
    }
    gSpriteEntries[slot].unk30 += gSpriteEntries[slot].unk24;
    if (gSpriteEntries[slot].unk30 > 0xFF)
        gSpriteEntries[slot].unk30 = 0xFF;
    return 0;
}

u32 update_sprite_deceleration(u32 slot, s16 a, s16 b) {
    struct SpriteEntry *base = gSpriteEntries;
    struct SpriteEntry *s = &base[slot];
    u8 *frac = &s->unk25;
    u32 step;
    u32 pos;
    *frac = *frac + gUnk_083AF210[0xFF - s->unk30];
    step = *frac;
    *frac &= 3;
    pos = (u16)s->unk4 - (step >> 2);
    s->unk4 = pos;
    if (s->unk4 >= a && s->unk4 <= b) {
        s->unk4 = b;
        return 1;
    }
    gSpriteEntries[slot].unk30 += gSpriteEntries[slot].unk24;
    if (gSpriteEntries[slot].unk30 > 0xFF)
        gSpriteEntries[slot].unk30 = 0xFF;
    return 0;
}

void sprite_shake_x_step(u32 slot, u32 frame, u32 y) {
    switch ((frame & 6) >> 1) {
    case 1:
        gSpriteEntries[slot].unk2 = y + 1;
        break;
    case 3:
        gSpriteEntries[slot].unk2 = y - 1;
        break;
    default:
        gSpriteEntries[slot].unk2 = y;
        break;
    }
}

void bg3_shake_step(u32 a) {
    if (a & 2)
        gBg3Scroll.y = 2;
    else
        gBg3Scroll.y = 0;
}

u32 sprite_hop_step(u32 slot) {
    if ((gSpriteEntries[slot].unk0 & 0x8000) && gSpriteEntries[slot].unk23 != 0x20) {
        gSpriteEntries[slot].unk4 = (gSpriteEntries[slot].unk4 + gSpriteHopOffsets[gSpriteEntries[slot].unk23]) & 0xFF;
        gSpriteEntries[slot].unk23++;
        return 0;
    }
    return 1;
}

static void battle_sprite_blink_update(u32 slot, u8 *counter, u8 *n) {
    gSpriteEntries[slot].unk0 |= 0x8000;
    if (*n == 0) {
        if (++*counter & 1)
            gSpriteEntries[slot].unk0 &= 0x7FFF;
    } else if (*counter == *n) {
        *counter = 0;
        gSpriteEntries[slot].unk0 &= 0x7FFF;
        (*n)--;
    } else {
        (*counter)++;
    }
}

// guess: targets the living enemy whose sprite is closest in x (smallest x for the team, largest for opponents).
void battle_target_nearest_enemy(u32 rec) {
    u32 best_x;
    s32 i;
    s32 best;
    if (rec <= 2) {
        best_x = 0xFF;
        for (i = 5, best = 5; i > 2; i--) {
            if (gBattleBots[i].unk40 != 0 && gSpriteEntries[i * 4 + 0x5D].unk2 < best_x) {
                best_x = gSpriteEntries[i * 4 + 0x5D].unk2;
                best = i;
            }
        }
    } else {
        best_x = 0;
        for (i = 2, best = 2; i >= 0; i--) {
            if (gBattleBots[i].unk40 != 0 && gSpriteEntries[i * 4 + 0x5D].unk2 > best_x) {
                best_x = gSpriteEntries[i * 4 + 0x5D].unk2;
                best = i;
            }
        }
    }
    gBattleBots[rec].unkE0 = best + 1;
}

// get_random_battle_weight_entry inlined, with the "- 1" inside
static inline u32 pick_evasion_weight(u32 n) {
    return gUnk_083AF330[bot_intact_parts_class(n - 1) * 8 + (rng_next_byte() & 7)];
}

// Picks a random intact part of the target (unkE1), weighted by gUnk_083AF330 per intact-part class.
void battle_pick_random_target_part(u32 rec) {
    struct BattleBot *base = gBattleBots;
    struct BattleBot *b = &base[rec];

    if (b->unkE0 != 0)
        b->unkE1 = pick_evasion_weight(b->unkE0) + 1;
}

u32 get_random_battle_weight_entry(u32 rec) {
    return gUnk_083AF330[bot_intact_parts_class(rec) * 8 + (rng_next_byte() & 7)];
}

// Which of the arms and legs are intact, as 0-8 (right arm 1, left arm 3, legs 5): row of gUnk_083AF330.
u32 bot_intact_parts_class(u32 rec) {
    u32 n = gBattleBots[rec].parts[1].unk11 != 0;
    if (gBattleBots[rec].parts[2].unk11 != 0)
        n += 3;
    if (gBattleBots[rec].parts[3].unk11 != 0)
        n += 5;
    return n;
}

void battle_load_action_target(u32 rec) {
    gBattleWork.unk88 = gBattleBots[rec].unkE0 - 1;
    gBattleWork.unk8B = gBattleBots[rec].unkE1 - 1;
}

u32 move_sprite_toward_target(u32 slot) {
    u32 ret;

    if (gSpriteEntries[slot].unk2 == gSpriteEntries[slot].unk30 &&
        gSpriteEntries[slot].unk4 == gSpriteEntries[slot].unk32)
        ret = 1;
    else {
        gSpriteEntries[slot].unk25 = calculate_direction_index(gSpriteEntries[slot].unk2, gSpriteEntries[slot].unk4,
                                                               gSpriteEntries[slot].unk30, gSpriteEntries[slot].unk32);
        update_sprite_animation_position(slot);
        if (check_sprite_in_range(slot)) {
            gSpriteEntries[slot].unk2 = gSpriteEntries[slot].unk30;
            gSpriteEntries[slot].unk4 = gSpriteEntries[slot].unk32;
            ret = 1;
        } else
            ret = 0;
    }
    return ret;
}

static u32 check_sprite_in_range(u32 slot) {
    s32 y = gSpriteEntries[slot].unk2;
    s32 x = gSpriteEntries[slot].unk4;
    u16 tx = gSpriteEntries[slot].unk30;
    u16 ty = gSpriteEntries[slot].unk32;
    if (ty - 2 <= x && ty + 2 >= x && tx - 2 <= y && tx + 2 >= y)
        return 1;
    return 0;
}

// Turns on the affine flag (0x200, see build_oam) at scale 0x40 (1.0) on both axes.
void sprite_enable_affine_unit_scale(u32 slot) {
    gSpriteEntries[slot].unk0 |= 0x200;
    gSpriteEntries[slot].unk8 = 0x40;
    gSpriteEntries[slot].unk9 = 0x40;
}

void sprite_disable_affine(u32 slot) {
    gSpriteEntries[slot].unk0 &= ~0x200;
}

void check_sprite_overlap_and_adjust(u32 a, u32 b) {
    struct SpriteEntry *base = gSpriteEntries;
    struct SpriteEntry *sa = &base[a];
    struct SpriteEntry *sb;
    s32 y = sa->unk4;

    if ((u32)y > 0x9F || y + 8 <= (sb = &base[b])->unk4 - 0x20)
        clear_sprite_table_mask(b, 1);
    else {
        s32 d;
        set_sprite_hidden_flags(b, 1);
        d = (u8)sb->unk4 - 8;
        sb->unk8 = 0x40 - (d - (u8)sa->unk4) * 2;
        sb->unk9 = 0x40 - (d - (u8)sa->unk4) * 2;
    }
}

void subtract_u8_floored(u8 *val, s32 amount) {
    if (*val < amount)
        *val = 0;
    else
        *val -= amount;
}

void add_u8_capped(u8 *val, u32 amount, u32 max) {
    u32 sum = *val + amount;
    if (sum > max)
        *val = max;
    else
        *val = sum;
}

void subtract_s16_floored(s16 *val, s32 amount) {
    if (*val < amount)
        *val = 0;
    else
        *val -= amount;
}

u32 calc_bot_matching_part_power(u32 rec) {
    u32 sum = 0;
    u32 i;
    for (i = 0; i <= 3; i++)
        if (gBattleBots[rec].medal.unk4 == gBattleBots[rec].parts[i].data[0])
            sum += gBattleBots[rec].medal.unk7;
    return sum;
}

void calc_battle_action_speed(u32 rec, u32 part) {
    struct BattleWork *b = &gBattleWork;
    b->unkE8 += gBattleBots[rec].parts[part].data[5];
    b->unkE8 += calc_bot_matching_part_power(rec);
    b->unkE8 += rng_next_byte() & 7;
    b->unkE8 += gBattleBots[rec].medal.unk20[gBattleBots[rec].parts[part].data[2]];
    if (skill_type_is_remote(gBattleBots[rec].parts[part].data[2]))
        b->unkE8 += gBattleBots[rec].parts[3].unk16;
    else
        b->unkE8 += gBattleBots[rec].parts[3].unk15;
}

void apply_battle_bot_damage_reduction(u32 rec) {
    if ((u8)(gBattleBots[rec].unkC9 - 0xD) <= 1)
        subtract_s16_floored(&gBattleWork.unkE8, gBattleBots[rec].unkCC);
}

void accumulate_battle_speed_value(u32 rec) {
    struct BattleWork *b = &gBattleWork;
    b->unkEE += gBattleBots[rec].medal.unk5;
    b->unkEE += calc_bot_matching_part_power(rec);
    b->unkEE += rng_next_byte() & 7;
}

u32 check_bot_ability_type_strike(u32 rec, u32 part, u32 target) {
    if (gBattleBots[rec].parts[part].data[1] == 0x22 && gBattleBots[target].parts[3].data[1] == 0x64)
        return 1;
    return 0;
}

u32 check_bot_ability_type_shoot(u32 rec, u32 part, u32 target) {
    if (gBattleBots[rec].parts[part].data[1] == 0x23 && gBattleBots[target].parts[3].data[1] == 0x6A)
        return 1;
    return 0;
}

void success_add_strengthen_parts(u32 rec) {
    u32 i;
    for (i = 0; i <= 2; i++)
        if (gBattleBots[rec].parts[i].unk11 != 0 && gBattleBots[rec].parts[i].data[1] == 0x35)
            gBattleWork.unkE8 += gBattleBots[rec].parts[i].data[5];
}

void battle_set_action_target(u32 rec, u32 target) {
    gBattleBots[rec].unkE0 = target;
    gBattleWork.unk88 = target - 1;
}

void battle_set_action_target_part(u32 rec, u32 part) {
    gBattleBots[rec].unkE1 = part;
    gBattleWork.unk8B = part - 1;
}

// Whether any part with armor left has the given skill id (0x18 CancelOptic for check_bot_can_shoot).
static u32 bot_has_intact_part_with_skill(u32 rec, u32 skill) {
    u32 i;
    for (i = 0; i <= 3; i++)
        if (gBattleBots[rec].parts[i].unk11 != 0 && gBattleBots[rec].parts[i].data[1] == skill)
            return 1;
    return 0;
}

u32 check_bot_can_shoot(u32 rec, u32 part, u32 target) {
    if (((u8)(gBattleBots[rec].parts[part].data[1] - 4) <= 1 || (gBattleBots[rec].unkD6 & 1)) &&
        bot_has_intact_part_with_skill(target, 0x18))
        return 1;
    return 0;
}

u32 check_bot_can_support(u32 rec, u32 part, u32 target) {
    if (((u8)(gBattleBots[rec].parts[part].data[1] - 6) <= 1 || (gBattleBots[rec].unkD6 & 2)) &&
        bot_has_intact_part_with_skill(target, 0x19))
        return 1;
    return 0;
}

u32 check_bot_can_use_shoot_part(u32 rec, u32 part, u32 target) {
    if (((u8)(gBattleBots[rec].parts[part].data[1] - 8) <= 1 || (gBattleBots[rec].unkD6 & 4)) &&
        bot_has_intact_part_with_skill(target, 0x1A))
        return 1;
    return 0;
}

u32 check_bot_status_effect_4(u32 rec, u32 part, u32 target) {
    if ((gBattleBots[target].unkC0 & 2) && gBattleBots[rec].parts[part].data[1] == 0x34)
        return 1;
    return 0;
}

u32 check_can_target_bot(u32 rec, u32 part, u32 target) {
    if (((u8)(gBattleBots[rec].parts[part].data[1] - 4) <= 1 || (gBattleBots[rec].unkD6 & 1)) &&
        (gBattleBots[target].unkD6 & 8))
        return 1;
    return 0;
}

u32 check_battle_can_support_target(u32 rec, u32 part, u32 target) {
    if (((u8)(gBattleBots[rec].parts[part].data[1] - 6) <= 1 || (gBattleBots[rec].unkD6 & 2)) &&
        (gBattleBots[target].unkD6 & 0x10))
        return 1;
    return 0;
}

u32 check_battle_can_special_target(u32 rec, u32 part, u32 target) {
    if (((u8)(gBattleBots[rec].parts[part].data[1] - 8) <= 1 || (gBattleBots[rec].unkD6 & 4)) &&
        (gBattleBots[target].unkD6 & 0x20))
        return 1;
    return 0;
}

void damage_add_strengthen_parts(u32 rec) {
    u32 i;
    for (i = 0; i <= 2; i++)
        if (gBattleBots[rec].parts[i].unk11 != 0 && gBattleBots[rec].parts[i].data[1] == 0x35)
            gBattleWork.unkEC += gBattleBots[rec].parts[i].data[6];
}

void damage_add_small_random(void) {
    struct BattleWork *b = &gBattleWork;
    if (b->unkEC <= 2)
        b->unkEC += rng_next_byte() & 3;
}

// guess: data[0xC] is a per-part damage divisor (multi-hit parts?); the result is at least 1.
void damage_divide_by_part_divisor(u32 rec, u32 part) {
    struct BattleWork *b = &gBattleWork;
    b->unkEC = b->unkEC / gBattleBots[rec].parts[part].data[0xC];
    if (b->unkEC == 0)
        b->unkEC = 1;
}

// Scrolls BG2/BG3 to x 0x110 when the actor is an opponent (unkF8 bit 0), else to 0: the action close-up
// background faces the acting side.
void action_bg_set_side_scroll(void) {
    u32 t = gBattleWork.unkF8 & 1;
    if (t) {
        gBg2Scroll.x = 0x110;
        gBg3Scroll.x = 0x110;
    } else {
        gBg2Scroll.x = t;
        gBg3Scroll.x = t;
    }
}
