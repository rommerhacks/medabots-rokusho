// Combat helpers shared by the action steps and the skill modules: damage against a part's armor, the
// target cursor and sprite positions, stat reductions, the defeated list, sprite movement toward a target,
// evasion weights, and the part / ability checks the AI (battle/action_calc) uses (check_bot_can_*).

#include "global.h"

static u32 check_sprite_in_range(u32 slot);

u32 sub_08034F44(u32 rec) {
    u32 i;
    for (i = 0; i <= 2; i++)
        if (gUnk_03000590[rec].parts[i].data[1] == 0x15)
            return 1;
    return 0;
}

void battle_set_damage_vs_armor(u32 rec, u32 part, s32 amount) {
    s32 armor = gUnk_03000590[rec].parts[part].unk11;
    if (armor > amount) {
        gUnk_03001800.unkC8 = amount;
        gUnk_03001800.unkCC = amount;
        gUnk_03001800.unkCA = 0;
        gUnk_03001800.unkD1 = 0;
    } else {
        gUnk_03001800.unkC8 = armor;
        gUnk_03001800.unkCC = armor;
        gUnk_03001800.unkCA = amount - armor;
        gUnk_03001800.unkD1 = 1;
    }
}

void set_target_sprite_position(u32 rec, u32 dir, u32 axis) {
    if (axis == 0) {
        switch ((dir & 6) >> 1) {
        case 1:
            gUnk_03002C30[rec * 4 + 0x5D].unk2 = gUnk_03001800.unk13C[rec].x + 1;
            gUnk_03002C30[rec * 4 + 0x5D].unk4 = gUnk_03001800.unk13C[rec].y;
            break;
        case 3:
            gUnk_03002C30[rec * 4 + 0x5D].unk2 = gUnk_03001800.unk13C[rec].x - 1;
            gUnk_03002C30[rec * 4 + 0x5D].unk4 = gUnk_03001800.unk13C[rec].y;
            break;
        default:
            gUnk_03002C30[rec * 4 + 0x5D].unk2 = gUnk_03001800.unk13C[rec].x;
            gUnk_03002C30[rec * 4 + 0x5D].unk4 = gUnk_03001800.unk13C[rec].y;
            break;
        }
    } else {
        switch ((dir & 6) >> 1) {
        case 1:
            gUnk_03002C30[rec * 4 + 0x5D].unk4 = gUnk_03001800.unk13C[rec].y - 2;
            break;
        case 3:
            gUnk_03002C30[rec * 4 + 0x5D].unk4 = gUnk_03001800.unk13C[rec].y;
            break;
        default:
            gUnk_03002C30[rec * 4 + 0x5D].unk4 = gUnk_03001800.unk13C[rec].y - 1;
            break;
        }
    }
    sub_080350E0(rec);
}

void sub_080350E0(u32 rec) {
    gUnk_03002C30[rec * 4 + 0x5A].unk2 = gUnk_03002C30[rec * 4 + 0x5D].unk2;
    gUnk_03002C30[rec * 4 + 0x5A].unk4 = gUnk_03002C30[rec * 4 + 0x5D].unk4 - 8;
    gUnk_03002C30[rec * 4 + 0x5B].unk2 = gUnk_03002C30[rec * 4 + 0x5D].unk2 - 8;
    gUnk_03002C30[rec * 4 + 0x5B].unk4 = gUnk_03002C30[rec * 4 + 0x5D].unk4;
    gUnk_03002C30[rec * 4 + 0x5C].unk2 = gUnk_03002C30[rec * 4 + 0x5D].unk2 + 8;
    gUnk_03002C30[rec * 4 + 0x5C].unk4 = gUnk_03002C30[rec * 4 + 0x5D].unk4;
}

void update_target_cursor_position(u32 rec) {
    gUnk_03002C30[rec * 4 + 0x5D].unk2 = gUnk_03001800.unk13C[rec].x;
    gUnk_03002C30[rec * 4 + 0x5D].unk4 = gUnk_03001800.unk13C[rec].y + 4;
    sub_080350E0(rec);
}

void reduce_bot_part_stat(u32 rec, u32 part, s32 amount) {
    if (gUnk_03000590[rec].parts[part].unk11 < amount)
        gUnk_03000590[rec].parts[part].unk11 = 0;
    else
        gUnk_03000590[rec].parts[part].unk11 -= amount;
}

void sub_08035194(u32 rec) {
    if (gUnk_03000590[rec].parts[3].unk11 == 0) {
        gUnk_03000590[rec].parts[3].unk12 = gUnk_03000590[rec].parts[3].data[5] >> 1;
        gUnk_03000590[rec].parts[3].unk13 = gUnk_03000590[rec].parts[3].data[6] >> 1;
        gUnk_03000590[rec].parts[3].unk14 = gUnk_03000590[rec].parts[3].data[7] >> 1;
        gUnk_03000590[rec].parts[3].unk15 = gUnk_03000590[rec].parts[3].data[8] >> 1;
        gUnk_03000590[rec].parts[3].unk16 = gUnk_03000590[rec].parts[3].data[9] >> 1;
    }
}

void sub_080351E8(u32 rec) {
    if (gUnk_03000590[rec].parts[3].unk11 != 0) {
        gUnk_03000590[rec].parts[3].unk12 = gUnk_03000590[rec].parts[3].data[5];
        gUnk_03000590[rec].parts[3].unk13 = gUnk_03000590[rec].parts[3].data[6];
        gUnk_03000590[rec].parts[3].unk14 = gUnk_03000590[rec].parts[3].data[7];
        gUnk_03000590[rec].parts[3].unk15 = gUnk_03000590[rec].parts[3].data[8];
        gUnk_03000590[rec].parts[3].unk16 = gUnk_03000590[rec].parts[3].data[9];
    }
}

void add_bot_to_defeated_list(u32 rec) {
    u32 i;
    if (gUnk_03000590[rec].parts[0].unk11 == 0) {
        for (i = 0; i <= 2; i++) {
            if (gUnk_03001800.unkE0[i] == 0) {
                gUnk_03001800.unkE0[i] = rec + 1;
                return;
            }
        }
    }
}

u32 sprite_move_toward_target(u32 slot, s16 x, s16 y) {
    struct Unk_03002C30 *base = gUnk_03002C30;
    struct Unk_03002C30 *s = &base[slot];
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
    gUnk_03002C30[slot].unk30 += gUnk_03002C30[slot].unk24;
    if (gUnk_03002C30[slot].unk30 > 0xFF)
        gUnk_03002C30[slot].unk30 = 0xFF;
    return 0;
}

u32 update_sprite_deceleration(u32 slot, s16 a, s16 b) {
    struct Unk_03002C30 *base = gUnk_03002C30;
    struct Unk_03002C30 *s = &base[slot];
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
    gUnk_03002C30[slot].unk30 += gUnk_03002C30[slot].unk24;
    if (gUnk_03002C30[slot].unk30 > 0xFF)
        gUnk_03002C30[slot].unk30 = 0xFF;
    return 0;
}

void sub_0803536C(u32 slot, u32 frame, u32 y) {
    switch ((frame & 6) >> 1) {
    case 1:
        gUnk_03002C30[slot].unk2 = y + 1;
        break;
    case 3:
        gUnk_03002C30[slot].unk2 = y - 1;
        break;
    default:
        gUnk_03002C30[slot].unk2 = y;
        break;
    }
}

void sub_080353AC(u32 a) {
    if (a & 2)
        gBg3Scroll.y = 2;
    else
        gBg3Scroll.y = 0;
}

u32 sub_080353CC(u32 slot) {
    if ((gUnk_03002C30[slot].unk0 & 0x8000) && gUnk_03002C30[slot].unk23 != 0x20) {
        gUnk_03002C30[slot].unk4 = (gUnk_03002C30[slot].unk4 + gUnk_083AF310[gUnk_03002C30[slot].unk23]) & 0xFF;
        gUnk_03002C30[slot].unk23++;
        return 0;
    }
    return 1;
}

static void battle_sprite_blink_update(u32 slot, u8 *counter, u8 *n) {
    gUnk_03002C30[slot].unk0 |= 0x8000;
    if (*n == 0) {
        if (++*counter & 1)
            gUnk_03002C30[slot].unk0 &= 0x7FFF;
    } else if (*counter == *n) {
        *counter = 0;
        gUnk_03002C30[slot].unk0 &= 0x7FFF;
        (*n)--;
    } else {
        (*counter)++;
    }
}

void sub_08035478(u32 rec) {
    u32 best_x;
    s32 i;
    s32 best;
    if (rec <= 2) {
        best_x = 0xFF;
        for (i = 5, best = 5; i > 2; i--) {
            if (gUnk_03000590[i].unk40 != 0 && gUnk_03002C30[i * 4 + 0x5D].unk2 < best_x) {
                best_x = gUnk_03002C30[i * 4 + 0x5D].unk2;
                best = i;
            }
        }
    } else {
        best_x = 0;
        for (i = 2, best = 2; i >= 0; i--) {
            if (gUnk_03000590[i].unk40 != 0 && gUnk_03002C30[i * 4 + 0x5D].unk2 > best_x) {
                best_x = gUnk_03002C30[i * 4 + 0x5D].unk2;
                best = i;
            }
        }
    }
    gUnk_03000590[rec].unkE0 = best + 1;
}

// get_random_battle_weight_entry inlined, with the "- 1" inside
static inline u32 pick_evasion_weight(u32 n) {
    return gUnk_083AF330[sub_08035590(n - 1) * 8 + (rng_next_byte() & 7)];
}

void calc_bot_evasion_modifier(u32 rec) {
    struct Unk_03000590 *base = gUnk_03000590;
    struct Unk_03000590 *b = &base[rec];

    if (b->unkE0 != 0)
        b->unkE1 = pick_evasion_weight(b->unkE0) + 1;
}

u32 get_random_battle_weight_entry(u32 rec) {
    return gUnk_083AF330[sub_08035590(rec) * 8 + (rng_next_byte() & 7)];
}

u32 sub_08035590(u32 rec) {
    u32 n = gUnk_03000590[rec].parts[1].unk11 != 0;
    if (gUnk_03000590[rec].parts[2].unk11 != 0)
        n += 3;
    if (gUnk_03000590[rec].parts[3].unk11 != 0)
        n += 5;
    return n;
}

void sub_080355C4(u32 rec) {
    gUnk_03001800.unk88 = gUnk_03000590[rec].unkE0 - 1;
    gUnk_03001800.unk8B = gUnk_03000590[rec].unkE1 - 1;
}

u32 move_sprite_toward_target(u32 slot) {
    u32 ret;

    if (gUnk_03002C30[slot].unk2 == gUnk_03002C30[slot].unk30 && gUnk_03002C30[slot].unk4 == gUnk_03002C30[slot].unk32)
        ret = 1;
    else {
        gUnk_03002C30[slot].unk25 = calculate_direction_index(gUnk_03002C30[slot].unk2, gUnk_03002C30[slot].unk4,
                                                              gUnk_03002C30[slot].unk30, gUnk_03002C30[slot].unk32);
        update_sprite_animation_position(slot);
        if (check_sprite_in_range(slot)) {
            gUnk_03002C30[slot].unk2 = gUnk_03002C30[slot].unk30;
            gUnk_03002C30[slot].unk4 = gUnk_03002C30[slot].unk32;
            ret = 1;
        } else
            ret = 0;
    }
    return ret;
}

static u32 check_sprite_in_range(u32 slot) {
    s32 y = gUnk_03002C30[slot].unk2;
    s32 x = gUnk_03002C30[slot].unk4;
    u16 tx = gUnk_03002C30[slot].unk30;
    u16 ty = gUnk_03002C30[slot].unk32;
    if (ty - 2 <= x && ty + 2 >= x && tx - 2 <= y && tx + 2 >= y)
        return 1;
    return 0;
}

void sub_08035694(u32 slot) {
    gUnk_03002C30[slot].unk0 |= 0x200;
    gUnk_03002C30[slot].unk8 = 0x40;
    gUnk_03002C30[slot].unk9 = 0x40;
}

void sub_080356B4(u32 slot) {
    gUnk_03002C30[slot].unk0 &= ~0x200;
}

void check_sprite_overlap_and_adjust(u32 a, u32 b) {
    struct Unk_03002C30 *base = gUnk_03002C30;
    struct Unk_03002C30 *sa = &base[a];
    struct Unk_03002C30 *sb;
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

void sub_0803572C(u8 *val, s32 amount) {
    if (*val < amount)
        *val = 0;
    else
        *val -= amount;
}

void sub_08035740(u8 *val, u32 amount, u32 max) {
    u32 sum = *val + amount;
    if (sum > max)
        *val = max;
    else
        *val = sum;
}

void sub_08035754(s16 *val, s32 amount) {
    if (*val < amount)
        *val = 0;
    else
        *val -= amount;
}

u32 calc_bot_matching_part_power(u32 rec) {
    u32 sum = 0;
    u32 i;
    for (i = 0; i <= 3; i++)
        if (gUnk_03000590[rec].medal.unk4 == gUnk_03000590[rec].parts[i].data[0])
            sum += gUnk_03000590[rec].medal.unk7;
    return sum;
}

void calc_battle_action_speed(u32 rec, u32 part) {
    struct Unk_03001800 *b = &gUnk_03001800;
    b->unkE8 += gUnk_03000590[rec].parts[part].data[5];
    b->unkE8 += calc_bot_matching_part_power(rec);
    b->unkE8 += rng_next_byte() & 7;
    b->unkE8 += gUnk_03000590[rec].medal.unk20[gUnk_03000590[rec].parts[part].data[2]];
    if (skill_type_is_remote(gUnk_03000590[rec].parts[part].data[2]))
        b->unkE8 += gUnk_03000590[rec].parts[3].unk16;
    else
        b->unkE8 += gUnk_03000590[rec].parts[3].unk15;
}

void apply_battle_bot_damage_reduction(u32 rec) {
    if ((u8)(gUnk_03000590[rec].unkC9 - 0xD) <= 1)
        sub_08035754(&gUnk_03001800.unkE8, gUnk_03000590[rec].unkCC);
}

void accumulate_battle_speed_value(u32 rec) {
    struct Unk_03001800 *b = &gUnk_03001800;
    b->unkEE += gUnk_03000590[rec].medal.unk5;
    b->unkEE += calc_bot_matching_part_power(rec);
    b->unkEE += rng_next_byte() & 7;
}

u32 check_bot_ability_type_strike(u32 rec, u32 part, u32 target) {
    if (gUnk_03000590[rec].parts[part].data[1] == 0x22 && gUnk_03000590[target].parts[3].data[1] == 0x64)
        return 1;
    return 0;
}

u32 check_bot_ability_type_shoot(u32 rec, u32 part, u32 target) {
    if (gUnk_03000590[rec].parts[part].data[1] == 0x23 && gUnk_03000590[target].parts[3].data[1] == 0x6A)
        return 1;
    return 0;
}

void sub_080358F0(u32 rec) {
    u32 i;
    for (i = 0; i <= 2; i++)
        if (gUnk_03000590[rec].parts[i].unk11 != 0 && gUnk_03000590[rec].parts[i].data[1] == 0x35)
            gUnk_03001800.unkE8 += gUnk_03000590[rec].parts[i].data[5];
}

void sub_08035928(u32 rec, u32 target) {
    gUnk_03000590[rec].unkE0 = target;
    gUnk_03001800.unk88 = target - 1;
}

void sub_08035944(u32 rec, u32 part) {
    gUnk_03000590[rec].unkE1 = part;
    gUnk_03001800.unk8B = part - 1;
}

static u32 sub_08035960(u32 rec, u32 skill) {
    u32 i;
    for (i = 0; i <= 3; i++)
        if (gUnk_03000590[rec].parts[i].unk11 != 0 && gUnk_03000590[rec].parts[i].data[1] == skill)
            return 1;
    return 0;
}

u32 check_bot_can_shoot(u32 rec, u32 part, u32 target) {
    if (((u8)(gUnk_03000590[rec].parts[part].data[1] - 4) <= 1 || (gUnk_03000590[rec].unkD6 & 1)) &&
        sub_08035960(target, 0x18))
        return 1;
    return 0;
}

u32 check_bot_can_support(u32 rec, u32 part, u32 target) {
    if (((u8)(gUnk_03000590[rec].parts[part].data[1] - 6) <= 1 || (gUnk_03000590[rec].unkD6 & 2)) &&
        sub_08035960(target, 0x19))
        return 1;
    return 0;
}

u32 check_bot_can_use_shoot_part(u32 rec, u32 part, u32 target) {
    if (((u8)(gUnk_03000590[rec].parts[part].data[1] - 8) <= 1 || (gUnk_03000590[rec].unkD6 & 4)) &&
        sub_08035960(target, 0x1A))
        return 1;
    return 0;
}

u32 check_bot_status_effect_4(u32 rec, u32 part, u32 target) {
    if ((gUnk_03000590[target].unkC0 & 2) && gUnk_03000590[rec].parts[part].data[1] == 0x34)
        return 1;
    return 0;
}

u32 check_can_target_bot(u32 rec, u32 part, u32 target) {
    if (((u8)(gUnk_03000590[rec].parts[part].data[1] - 4) <= 1 || (gUnk_03000590[rec].unkD6 & 1)) &&
        (gUnk_03000590[target].unkD6 & 8))
        return 1;
    return 0;
}

u32 check_battle_can_support_target(u32 rec, u32 part, u32 target) {
    if (((u8)(gUnk_03000590[rec].parts[part].data[1] - 6) <= 1 || (gUnk_03000590[rec].unkD6 & 2)) &&
        (gUnk_03000590[target].unkD6 & 0x10))
        return 1;
    return 0;
}

u32 check_battle_can_special_target(u32 rec, u32 part, u32 target) {
    if (((u8)(gUnk_03000590[rec].parts[part].data[1] - 8) <= 1 || (gUnk_03000590[rec].unkD6 & 4)) &&
        (gUnk_03000590[target].unkD6 & 0x20))
        return 1;
    return 0;
}

void sub_08035B9C(u32 rec) {
    u32 i;
    for (i = 0; i <= 2; i++)
        if (gUnk_03000590[rec].parts[i].unk11 != 0 && gUnk_03000590[rec].parts[i].data[1] == 0x35)
            gUnk_03001800.unkEC += gUnk_03000590[rec].parts[i].data[6];
}

void sub_08035BD4(void) {
    struct Unk_03001800 *b = &gUnk_03001800;
    if (b->unkEC <= 2)
        b->unkEC += rng_next_byte() & 3;
}

void sub_08035BFC(u32 rec, u32 part) {
    struct Unk_03001800 *b = &gUnk_03001800;
    b->unkEC = b->unkEC / gUnk_03000590[rec].parts[part].data[0xC];
    if (b->unkEC == 0)
        b->unkEC = 1;
}

void sub_08035C3C(void) {
    u32 t = gUnk_03001800.unkF8 & 1;
    if (t) {
        gBg2Scroll.x = 0x110;
        gBg3Scroll.x = 0x110;
    } else {
        gBg2Scroll.x = t;
        gBg3Scroll.x = t;
    }
}
