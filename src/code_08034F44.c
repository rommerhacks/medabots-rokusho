#include "global.h"

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

void battle_sprite_blink_update(u32 slot, u8 *counter, u8 *n) {
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
    return gUnk_083AF330[sub_08035590(n - 1) * 8 + (rng_next_080424B8() & 7)];
}

void calc_bot_evasion_modifier(u32 rec) {
    struct Unk_03000590 *base = gUnk_03000590;
    struct Unk_03000590 *b = &base[rec];

    if (b->unkE0 != 0)
        b->unkE1 = pick_evasion_weight(b->unkE0) + 1;
}

u32 get_random_battle_weight_entry(u32 rec) {
    return gUnk_083AF330[sub_08035590(rec) * 8 + (rng_next_080424B8() & 7)];
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

u32 check_sprite_in_range(u32 slot) {
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
    b->unkE8 += rng_next_080424B8() & 7;
    b->unkE8 += gUnk_03000590[rec].medal.unk20[gUnk_03000590[rec].parts[part].data[2]];
    if (sub_08042B80(gUnk_03000590[rec].parts[part].data[2]))
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
    b->unkEE += rng_next_080424B8() & 7;
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

u32 sub_08035960(u32 rec, u32 skill) {
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
        b->unkEC += rng_next_080424B8() & 3;
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

void init_battle_closeup_scene(void) {
    init_scene_buffers_080445F4();
    if (!(gUnk_03001800.unkF8 & 1)) {
        gUnk_03001800.unk154 = 0x3C;
        gUnk_03001800.unk114[0] = 0;
    } else {
        gUnk_03001800.unk154 = 0x12C;
        gUnk_03001800.unk114[0] = 0x28;
        gUnk_03001800.unkFF |= 1;
    }
    get_active_bot_part_index_and_load_values(0);
    gUnk_03001800.unk156 = 0x50;
    init_scene_with_bg_and_palette(0, gUnk_03001800.unk64[0], gUnk_03001800.unk64[1], gUnk_03001800.unk64[2],
                                   gUnk_03001800.unk64[3], (s16)gUnk_03001800.unk154, (s16)gUnk_03001800.unk156,
                                   gUnk_03001800.unk39[3] + 2, 4, 0, 0, 0, gUnk_03001800.unk114[0]);
    if (!(gUnk_03001800.unkF8 & 1)) {
        gUnk_03001800.unk158 = 0x1C4;
        gUnk_03001800.unk114[1] = 0x28;
        gUnk_03001800.unkFF |= 2;
    } else {
        gUnk_03001800.unk158 = 0xB4;
        gUnk_03001800.unk114[1] = 0;
    }
    get_active_bot_part_index_and_load_values(1);
    gUnk_03001800.unk15A = 0x50;
    init_scene_with_bg_and_palette(1, gUnk_03001800.unk64[0], gUnk_03001800.unk64[1], gUnk_03001800.unk64[2],
                                   gUnk_03001800.unk64[3], (s16)gUnk_03001800.unk158, (s16)gUnk_03001800.unk15A,
                                   gUnk_03001800.unk39[3] + 2, 8, 1, 0, 1, gUnk_03001800.unk114[1]);
}

u32 sub_08035DD4(u32 a) {
    if (a - 0x128 <= 0xA8)
        return 0;
    return 1;
}

void init_battle_scene_backgrounds(void) {
    if (gUnk_03001800.unkFF & 1)
        gUnk_03000440.unk96 = 1;
    else
        gUnk_03000440.unk96 = 0;
    if (sub_08035DD4((s16)gUnk_03001800.unk154)) {
        get_active_bot_part_index_and_load_values(0);
        init_scene_with_bg_and_palette(0, gUnk_03001800.unk64[0], gUnk_03001800.unk64[1], gUnk_03001800.unk64[2],
                                       gUnk_03001800.unk64[3], (s16)gUnk_03001800.unk154, (s16)gUnk_03001800.unk156,
                                       gUnk_03001800.unk39[3] + 2, 4, 0, 1, 0, gUnk_03001800.unk114[0]);
    }
    if (gUnk_03001800.unkFF & 2)
        gUnk_03000440.unk96 = 1;
    else
        gUnk_03000440.unk96 = 0;
    if (sub_08035DD4((s16)gUnk_03001800.unk158)) {
        get_active_bot_part_index_and_load_values(1);
        init_scene_with_bg_and_palette(1, gUnk_03001800.unk64[0], gUnk_03001800.unk64[1], gUnk_03001800.unk64[2],
                                       gUnk_03001800.unk64[3], (s16)gUnk_03001800.unk158, (s16)gUnk_03001800.unk15A,
                                       gUnk_03001800.unk39[3] + 2, 8, 1, 1, 1, gUnk_03001800.unk114[1]);
    }
    gUnk_03000440.unk96 = 0;
}

void setup_battle_medapart_scenes(void) {
    if (gUnk_03001800.unkFF & 1)
        gUnk_03000440.unk96 = 1;
    else
        gUnk_03000440.unk96 = 0;
    if (sub_08035DD4((s16)gUnk_03001800.unk154)) {
        get_active_bot_part_index_and_load_values(0);
        init_scene_with_bg_and_palette(0, gUnk_03001800.unk64[0], gUnk_03001800.unk64[1], gUnk_03001800.unk64[2],
                                       gUnk_03001800.unk64[3], (s16)gUnk_03001800.unk154, (s16)gUnk_03001800.unk156,
                                       gUnk_03001800.unk39[3] + 2, 4, 0, 2, 0, gUnk_03001800.unk114[0]);
        init_scene_with_bg_and_palette(0, gUnk_03001800.unk64[0], gUnk_03001800.unk64[1], gUnk_03001800.unk64[2],
                                       gUnk_03001800.unk64[3], (s16)gUnk_03001800.unk154, (s16)gUnk_03001800.unk156,
                                       gUnk_03001800.unk39[3] + 2, 4, 0, 1, 0, gUnk_03001800.unk114[0]);
    }
    if (gUnk_03001800.unkFF & 2)
        gUnk_03000440.unk96 = 1;
    else
        gUnk_03000440.unk96 = 0;
    if (sub_08035DD4((s16)gUnk_03001800.unk158)) {
        get_active_bot_part_index_and_load_values(1);
        init_scene_with_bg_and_palette(1, gUnk_03001800.unk64[0], gUnk_03001800.unk64[1], gUnk_03001800.unk64[2],
                                       gUnk_03001800.unk64[3], (s16)gUnk_03001800.unk158, (s16)gUnk_03001800.unk15A,
                                       gUnk_03001800.unk39[3] + 2, 8, 1, 2, 1, gUnk_03001800.unk114[1]);
        init_scene_with_bg_and_palette(1, gUnk_03001800.unk64[0], gUnk_03001800.unk64[1], gUnk_03001800.unk64[2],
                                       gUnk_03001800.unk64[3], (s16)gUnk_03001800.unk158, (s16)gUnk_03001800.unk15A,
                                       gUnk_03001800.unk39[3] + 2, 8, 1, 1, 1, gUnk_03001800.unk114[1]);
    }
    gUnk_03000440.unk96 = 0;
}

void get_active_bot_part_index_and_load_values(u32 side) {
    if (side == 0) {
        if (!(gUnk_03001800.unkF8 & 1))
            get_bot_part_effective_values(gUnk_03001800.unk87, gUnk_03001800.unk64);
        else if (gUnk_03001800.unkF6 & 2)
            get_bot_part_effective_values(gUnk_03001800.unk161, gUnk_03001800.unk64);
        else
            get_bot_part_effective_values(gUnk_03001800.unk88, gUnk_03001800.unk64);
    } else {
        if (!(gUnk_03001800.unkF8 & 1)) {
            if (gUnk_03001800.unkF6 & 2)
                get_bot_part_effective_values(gUnk_03001800.unk161, gUnk_03001800.unk64);
            else
                get_bot_part_effective_values(gUnk_03001800.unk88, gUnk_03001800.unk64);
        } else {
            get_bot_part_effective_values(gUnk_03001800.unk87, gUnk_03001800.unk64);
        }
    }
}

// r0 stays live through the function: it passes its (unused) argument through.
u32 sub_080361A8(a)
u32 a;
{
    struct Unk_03001800 *b = &gUnk_03001800;
    b->unk112 = 0x29;
    b->unk113 = 0x29;
    return a;
}

u32 battle_advance_dialogue_text(void) {
    struct Unk_03001800 *b = &gUnk_03001800;
    u8 *state = &b->unk112;
    u32 done;
    if (!(*state & 0x80) && !(b->unkFF & 1)) {
        get_active_bot_part_index_and_load_values(0);
        done = advance_text_display(0, *state, b->unk64[3]);
        if (done)
            b->unk112 |= 0x80;
        return done;
    }
    return 1;
}

u32 battle_advance_action_text(void) {
    struct Unk_03001800 *b = &gUnk_03001800;
    u8 *state = &b->unk113;
    u32 done;
    if (!(*state & 0x80) && !(b->unkFF & 2)) {
        get_active_bot_part_index_and_load_values(1);
        done = advance_text_display(1, *state, b->unk64[3]);
        if (done)
            b->unk113 |= 0x80;
        return done;
    }
    return 1;
}

void sub_08036270(void) {
    gUnk_03001800.unk28[gUnk_03001800.unk89].unk1++;
}

void sub_0803628C(void) {
    u32 add;
    u32 v;
    if (gUnk_03000590[gUnk_03001800.unk88].unkC0 & 8)
        add = 0x28;
    else
        add = 0x14;
    v = gUnk_03000590[gUnk_03001800.unk88].unkC1 + add;
    if (v > 0x4F)
        v = 0x50;
    gUnk_03000590[gUnk_03001800.unk88].unkC1 = v;
}

void sub_080362C4(u32 side) {
    u32 x = 2;
    if (side == 0)
        x = 0x10;
    fill_tilemap_rect_08042698(2, 2, x, 1, REG_BG1CNT, 0xB340);
    fill_tilemap_rect_08042698(2, 2, x, 4, REG_BG1CNT, 0xB344);
    fill_tilemap_rect_08042698(2, 2, x, 7, REG_BG1CNT, 0xB348);
    fill_tilemap_rect_08042698(2, 2, x, 10, REG_BG1CNT, 0xB34C);
}

void sub_08036340(u32 side) {
    u32 x = 4;
    if (side == 0)
        x = 0x12;
    set_tilemap_and_decompress_bg(x, 0, gUnk_084889B4, REG_BG1CNT, 0x329);
}

void sub_08036370(u32 side, u32 rec) {
    u32 x = 5;
    if (side == 0)
        x = 0x13;
    sub_080363E8(x, 1, 0x40, gUnk_03000590[rec].parts[0].data[4], gUnk_03000590[rec].parts[0].unk11);
    sub_080363E8(x, 4, 0x40, gUnk_03000590[rec].parts[1].data[4], gUnk_03000590[rec].parts[1].unk11);
    sub_080363E8(x, 7, 0x40, gUnk_03000590[rec].parts[2].data[4], gUnk_03000590[rec].parts[2].unk11);
    sub_080363E8(x, 10, 0x40, gUnk_03000590[rec].parts[3].data[4], gUnk_03000590[rec].parts[3].unk11);
}

void sub_080363E8(u32 x, u32 y, u32 w, u32 max, u32 cur) {
    u32 full, rem, col, i;

    full = scale_to_bar_fill(w, max, cur);
    rem = full & 0xFFFF;
    full >>= 16;

    if (cur != 0 && full == 0 && rem == 0)
        rem = 1;
    col = 0;
    for (i = 0; i < full; i++) {
        fill_tilemap_rect_08042698(1, 1, x + col, y, REG_BG1CNT, 0xA328);
        col++;
    }
    if (rem) {
        fill_tilemap_rect_08042698(1, 1, x + col, y, REG_BG1CNT, 0xA320 + rem);
        col++;
    }
    for (i = col; i <= 7; i++) {
        fill_tilemap_rect_08042698(1, 1, x + col, y, REG_BG1CNT, 0xA320);
        col++;
    }
}

void sub_080364A8(u32 side, u32 rec) {
    u32 x;
    u32 y;

    x = 6;
    if (side == 0)
        x = 0x14;
    y = 2;
    if (gUnk_03000590[rec].parts[0].unk11 != 0) {
        divide_by_100000_08042838(gUnk_03000590[rec].parts[0].unk11, x, y, 3, REG_BG1CNT, 0xA330);
        divide_by_100000_08042838(gUnk_03000590[rec].parts[0].data[4], x + 4, y, 3, REG_BG1CNT, 0xA330);
    } else {
        divide_by_100000_08042838(gUnk_03000590[rec].parts[0].unk11, x, y, 3, REG_BG1CNT, 0x8330);
        divide_by_100000_08042838(gUnk_03000590[rec].parts[0].data[4], x + 4, y, 3, REG_BG1CNT, 0x8330);
    }
    if (gUnk_03000590[rec].parts[1].unk11 != 0) {
        divide_by_100000_08042838(gUnk_03000590[rec].parts[1].unk11, x, y + 3, 3, REG_BG1CNT, 0xA330);
        divide_by_100000_08042838(gUnk_03000590[rec].parts[1].data[4], x + 4, y + 3, 3, REG_BG1CNT, 0xA330);
    } else {
        divide_by_100000_08042838(gUnk_03000590[rec].parts[1].unk11, x, y + 3, 3, REG_BG1CNT, 0x8330);
        divide_by_100000_08042838(gUnk_03000590[rec].parts[1].data[4], x + 4, y + 3, 3, REG_BG1CNT, 0x8330);
    }
    if (gUnk_03000590[rec].parts[2].unk11 != 0) {
        divide_by_100000_08042838(gUnk_03000590[rec].parts[2].unk11, x, y + 6, 3, REG_BG1CNT, 0xA330);
        divide_by_100000_08042838(gUnk_03000590[rec].parts[2].data[4], x + 4, y + 6, 3, REG_BG1CNT, 0xA330);
    } else {
        divide_by_100000_08042838(gUnk_03000590[rec].parts[2].unk11, x, y + 6, 3, REG_BG1CNT, 0x8330);
        divide_by_100000_08042838(gUnk_03000590[rec].parts[2].data[4], x + 4, y + 6, 3, REG_BG1CNT, 0x8330);
    }
    if (gUnk_03000590[rec].parts[3].unk11 != 0) {
        divide_by_100000_08042838(gUnk_03000590[rec].parts[3].unk11, x, y + 9, 3, REG_BG1CNT, 0xA330);
        divide_by_100000_08042838(gUnk_03000590[rec].parts[3].data[4], x + 4, y + 9, 3, REG_BG1CNT, 0xA330);
    } else {
        divide_by_100000_08042838(gUnk_03000590[rec].parts[3].unk11, x, y + 9, 3, REG_BG1CNT, 0x8330);
        divide_by_100000_08042838(gUnk_03000590[rec].parts[3].data[4], x + 4, y + 9, 3, REG_BG1CNT, 0x8330);
    }
}

u32 sub_080366DC(u32 slot, u32 part) {
    s16 dx, dy;
    struct Unk_03002C30 *base = gUnk_03002C30;
    struct Unk_03002C30 *s = &base[slot];
    u8 *frame;

    if (!(s->unk0 & 0x8000) || *(frame = &s->unk23) == 0x10)
        return 1;
    switch (part) {
    case 0:
        dx = gUnk_083AF380[*frame << 1];
        dy = gUnk_083AF380[*frame * 2 + 1];
        break;
    case 1:
        dx = gUnk_083AF3C0[*frame << 1];
        dy = gUnk_083AF3C0[*frame * 2 + 1];
        break;
    case 2:
        dx = gUnk_083AF400[*frame << 1];
        dy = gUnk_083AF400[*frame * 2 + 1];
        break;
    case 3:
        dx = gUnk_083AF440[*frame << 1];
        dy = gUnk_083AF440[*frame * 2 + 1];
        break;
    }
    gUnk_03002C30[slot].unk2 = (dx + gUnk_03002C30[slot].unk2) & 0x1FF;
    gUnk_03002C30[slot].unk4 = (dy + gUnk_03002C30[slot].unk4) & 0xFF;
    gUnk_03002C30[slot].unk23++;
    return 0;
}

void sub_08036784(u32 slot, u32 part, s16 x, s16 y) {
    u32 i;
    s32 t, u;

    clear_battle_sprite_slot(slot, 4);
    for (i = 0; i <= 3; i++) {
        gUnk_03002C30[slot + i].unk0 = 0x4404;
        gUnk_03002C30[slot + i].unk1C = 0;
        gUnk_03002C30[slot + i].unkA = 0xE;
        gUnk_03002C30[slot + i].unkB = 0x80;
        gUnk_03002C30[slot + i].unk2C = i * 8;
        u = gUnk_083AF480[part << 1] + x;
        t = gUnk_083AF490[i * 2];
        t += u;
        gUnk_03002C30[slot + i].unk2 = t & 0x1FF;
        u = gUnk_083AF480[part * 2 + 1] + y;
        t = gUnk_083AF490[i * 2 + 1];
        t += u;
        gUnk_03002C30[slot + i].unk4 = t & 0xFF;
        init_battle_sprite_entry_08040B90(gUnk_083B5F80[29], slot + i);
    }
}

u32 sub_0803684C(u32 slot) {
    u32 done = 1;
    u32 i;
    u8 n;

    for (i = 0; i <= 3; i++) {
        if (gUnk_03002C30[slot + i].unk0 != 0) {
            if (gUnk_03002C30[slot + i].unk2C == 0) {
                gUnk_03002C30[slot + i].unk0 |= 0x8004;
                gUnk_03002C30[slot + i].unkA = 0xE;
                process_sprite_anim_commands(gUnk_083B5F80[29], n = slot + i);
                if (gUnk_03002C30[slot + i].unk22 == 0xFF)
                    clear_battle_sprite_slot(n, 1);
                else
                    done = 0;
            } else {
                gUnk_03002C30[slot + i].unk2C--;
                done = 0;
            }
        }
    }
    return done;
}

void sub_080368C4(u8 *digits, u32 slot, u32 part, s16 x, s16 y) {
    u32 i = 0;
    s32 t;
    s32 u;
    for (; i <= 4; i++) {
        if (digits[i] == 0xFE)
            return;
        gUnk_03002C30[slot + i].unk0 = 0xC624;
        gUnk_03002C30[slot + i].unk1C = 0;
        t = x;
        t += gUnk_083AF480[part << 1];
        gUnk_03002C30[slot + i].unk2 = t & 0x1FF;
        u = y;
        u += gUnk_083AF480[part * 2 + 1];
        gUnk_03002C30[slot + i].unk4 = u & 0xFF;
        gUnk_03002C30[slot + i].unkB = 0x80;
        gUnk_03002C30[slot + i].unk6 = digits[i] + 0x2D00;
        gUnk_03002C30[slot + i].unk23 = 0;
        gUnk_03002C30[slot + i].unk9 = 0x40;
        gUnk_03002C30[slot + i].unk8 = 0x40;
        gUnk_03002C30[slot + i].unkA = 0xE;
        switch (digits[6]) {
        case 2:
            gUnk_03002C30[slot + i].unk2 = 0xFFFC + gUnk_03002C30[slot + i].unk2 + i * 8;
            break;
        case 3:
            gUnk_03002C30[slot + i].unk2 = 0xFFF8 + gUnk_03002C30[slot + i].unk2 + i * 8;
            break;
        case 4:
            gUnk_03002C30[slot + i].unk2 = 0xFFF4 + gUnk_03002C30[slot + i].unk2 + i * 8;
            break;
        }
    }
}

void setup_battle_sprite_oam_entries(u8 *buf, u32 slot, u32 part, s16 x, s16 y) {
    u32 i = 0;
    s32 t;
    s32 u;
    for (; i <= 4; i++) {
        if (buf[i] == 0xFE)
            return;
        gUnk_03002C30[slot + i].unk0 = 0xC404;
        gUnk_03002C30[slot + i].unk1C = 0;
        t = x;
        t += gUnk_083AF480[part << 1];
        gUnk_03002C30[slot + i].unk2 = t & 0x1FF;
        u = y;
        u += gUnk_083AF480[part * 2 + 1];
        gUnk_03002C30[slot + i].unk4 = u & 0xFF;
        gUnk_03002C30[slot + i].unkB = 0x80;
        gUnk_03002C30[slot + i].unk6 = buf[i] + 0x2D00;
        gUnk_03002C30[slot + i].unk23 = 0;
        gUnk_03002C30[slot + i].unkA = 0xE;
        switch (buf[6]) {
        case 2:
            gUnk_03002C30[slot + i].unk2 = 0xFFFC + gUnk_03002C30[slot + i].unk2 + i * 8;
            break;
        case 3:
            gUnk_03002C30[slot + i].unk2 = 0xFFF8 + gUnk_03002C30[slot + i].unk2 + i * 8;
            break;
        case 4:
            gUnk_03002C30[slot + i].unk2 = 0xFFF4 + gUnk_03002C30[slot + i].unk2 + i * 8;
            break;
        }
    }
}

u32 advance_sprite_anim_frame(u32 sprite, u32 b) {
    s32 f;
    if (!(gUnk_03002C30[sprite].unk0 & 0x8000) || gUnk_03002C30[sprite].unk23 == 0x10)
        return 1;
    gUnk_03002C30[sprite].unk4 = (gUnk_03002C30[sprite].unk4 + gUnk_083AF4A0[gUnk_03002C30[sprite].unk23]) & 0xFF;
    f = gUnk_03002C30[sprite].unk23 + 1;
    gUnk_03002C30[sprite].unk23 = f;
    if (b)
        gUnk_03002C30[sprite].unk9 = f * 4 + 0x40;
    return 0;
}

u32 advance_sprite_group_anims(u8 *digits, u32 slot) {
    u32 busy = 0;
    u32 i = 0;

    goto test;
    for (;;) {
        i++;
    test:
        if (i > 4 || digits[i] == 0xFE)
            goto done;
        if (advance_sprite_anim_frame(slot + i, 1))
            busy = 1;
    }
done:
    return busy;
}

u32 sub_08036B50(u8 *buf, u32 slot) {
    u32 busy = 0;
    u32 i = 0;

    goto test;
    for (;;) {
        i++;
    test:
        if (i > 4 || buf[i] == 0xFE)
            goto done;
        if (advance_sprite_anim_frame(slot + i, 0))
            busy = 1;
    }
done:
    return busy;
}

void sub_08036B84(u32 rec, u32 part) {
    gUnk_03001800.unkC8 = gUnk_03000590[rec].parts[part].unk11;
    gUnk_03001800.unkCC = gUnk_03000590[rec].parts[part].unk11;
    gUnk_03001800.unkD1 = 1;
}

u32 sub_08036BB8(u16 *amount, u32 rec, u32 part) {
    u8 *n = (u8 *)amount;
    if (gUnk_03000590[rec].parts[part].unk11 != 0 && *n != 0) {
        (*n)--;
        gUnk_03000590[rec].parts[part].unk11--;
        return 0;
    }
    return 1;
}

void sub_08036BF4(u32 side) {
    u32 y = 2;
    if (side == 0)
        y = 0x10;
    vram_fill_tilemap_rect(0xC, 0xD, y, 0, REG_BG1CNT, 0);
}

void sub_08036C20(u32 slot, u32 part, s16 x, s16 y, u32 n) {
    struct Unk_03002C30 *s;
    struct Unk_03002C30 *base;
    s32 t1, t2;

    clear_battle_sprite_slot(slot, 1);
    base = gUnk_03002C30;
    s = &base[slot];
    s->unk0 = 0xC404;
    s->unk1C = 0;
    s->unkA = 0xE;
    s->unkB = 0x80;
    t1 = gUnk_083AF480[part << 1] + x;
    s->unk2 = t1 & 0x1FF;
    t2 = gUnk_083AF480[part * 2 + 1] + y;
    s->unk4 = t2 & 0xFF;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[n], slot);
}

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

u32 battle_check_action_counter(u16 *amount, u32 rec, u32 part) {
    u8 *n = (u8 *)amount;
    if (gUnk_03000590[rec].parts[part].unk11 != gUnk_03000590[rec].parts[part].data[4]) {
        gUnk_03000590[rec].parts[part].unk11++;
        if (--*n != 0)
            return 0;
    }
    return 1;
}

u32 sub_08036D64(u32 rec, u32 skill) {
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

u32 medal_update_exp_progress(u32 slot, u32 n) {
    if (!(gUnk_03002C30[slot].unk0 & 0x8000) || gUnk_03002C30[slot].unk23 == 0x10)
        return 1;
    if (n == 0)
        gUnk_03002C30[slot].unk2 = gUnk_03002C30[slot].unk2 + gUnk_083AF4B0[gUnk_03002C30[slot].unk23];
    else
        gUnk_03002C30[slot].unk2 = gUnk_03002C30[slot].unk2 - gUnk_083AF4B0[gUnk_03002C30[slot].unk23];
    gUnk_03002C30[slot].unk23++;
    return 0;
}

u32 sub_08036E54(u32 a) {
    if (a > 99)
        a = 99;
    else if (a == 0)
        a = 1;
    return a;
}

void battle_set_action_params(u32 rec, u32 skill, s32 a, u32 b) {
    if (skill - 0xD <= 1) {
        gUnk_03000590[rec].unkC9 = skill;
        gUnk_03000590[rec].unkCA = gUnk_03001800.unk8B + 1;
        gUnk_03000590[rec].unkCB = sub_08036E54(a);
        gUnk_03000590[rec].unkCC = sub_08036E54(b * 2);
    } else if (skill - 0xF <= 1) {
        gUnk_03000590[rec].unkC9 = skill;
        gUnk_03000590[rec].unkCA = gUnk_03001800.unk8B + 1;
        gUnk_03000590[rec].unkCB = sub_08036E54(b >> 3);
        gUnk_03000590[rec].unkCC = 0;
    } else if (skill - 0x11 <= 1) {
        gUnk_03000590[rec].unkC9 = skill;
        gUnk_03000590[rec].unkCA = gUnk_03001800.unk8B + 1;
        gUnk_03000590[rec].unkCB = sub_08036E54(a);
        gUnk_03000590[rec].unkCC = sub_08036E54(b >> 2);
    } else if (skill - 0x13 <= 1) {
        gUnk_03000590[rec].unkC9 = skill;
        gUnk_03000590[rec].unkCA = gUnk_03001800.unk8B + 1;
        gUnk_03000590[rec].unkCB = sub_08036E54(a);
        gUnk_03000590[rec].unkCC = sub_08036E54(b >> 1);
    } else {
        gUnk_03000590[rec].unkC9 = skill;
        gUnk_03000590[rec].unkCA = gUnk_03001800.unk8B;
        gUnk_03000590[rec].unkCB = sub_08036E54(a);
        gUnk_03000590[rec].unkCC = sub_08036E54(b);
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
    sub_0803F624(&gUnk_03000590[rec].unkC4, 0xC, 0);
    sub_0803F624(&gUnk_03000590[rec].unkDC, 8, 0);
}

void setup_battle_cursor_sprite_08036FF8(u32 slot, s16 x, s16 y, u32 n) {
    u32 i;
    s32 t1;
    s32 t2;
    clear_battle_sprite_slot(slot, n);
    for (i = 0; i < n; i++) {
        gUnk_03002C30[slot + i].unk0 = 0x4004;
        gUnk_03002C30[slot + i].unk1C = 0;
        gUnk_03002C30[slot + i].unkA = 7;
        gUnk_03002C30[slot + i].unkB = 0xF0;
        gUnk_03002C30[slot + i].unk2C = i * 8;
        t1 = gUnk_083AF4C0[i * 2] + x;
        gUnk_03002C30[slot + i].unk2 = t1 & 0x1FF;
        t2 = gUnk_083AF4C0[i * 2 + 1] + y;
        gUnk_03002C30[slot + i].unk4 = t2 & 0xFF;
        init_battle_sprite_entry_08040B90(gUnk_083B5F80[36], slot + i);
    }
}

u32 update_sprite_animations_tick_080370AC(u32 slot, u32 n) {
    u32 done = 1;
    u32 i;
    u8 s;
    const void **anim;

    for (i = 0; i < n; i++) {
        anim = gUnk_083B6010;
        if (gUnk_03002C30[slot + i].unk0 != 0) {
            if (gUnk_03002C30[slot + i].unk2C != 0) {
                gUnk_03002C30[slot + i].unk2C--;
                done = 0;
            } else {
                gUnk_03002C30[slot + i].unk0 |= 0x8000;
                process_sprite_anim_commands(*anim, s = slot + i);
                if (gUnk_03002C30[slot + i].unk22 == 0xFF)
                    clear_battle_sprite_slot(s, 1);
                else
                    done = 0;
            }
        }
    }
    return done;
}

void sub_0803713C(void) {
    gUnk_03000590[gUnk_03001800.unk87].unkE0 = gUnk_03001800.unk87 + 1;
    gUnk_03000590[gUnk_03001800.unk87].unkE1 = gUnk_03001800.unkA7 + 1;
    if ((gUnk_03001800.unk162 = gUnk_03001800.unk8B) == 3)
        gUnk_03001800.unk162 = 0;
    gUnk_03001800.unk161 = gUnk_03001800.unk88;
    sub_080355C4(gUnk_03001800.unk87);
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

u32 sub_08037230(u32 rec, u32 part) {
    if (gUnk_03000590[rec].parts[part].unk11 != 0 &&
        gUnk_03000590[rec].parts[part].unk11 != gUnk_03000590[rec].parts[part].data[4])
        return 0;
    return 1;
}

u32 decrement_battle_timer_and_check_zero(void) {
    sub_08035754(&gUnk_03001800.unkE8, 0x20);
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

void sub_08037330(u32 rec, u32 frame, u32 mask) {
    if (frame & mask) {
        gUnk_03002C30[rec * 4 + 0x5A].unk0 |= 0x8000;
        gUnk_03002C30[rec * 4 + 0x5B].unk0 |= 0x8000;
        gUnk_03002C30[rec * 4 + 0x5C].unk0 |= 0x8000;
        gUnk_03002C30[rec * 4 + 0x5D].unk0 |= 0x8000;
    } else {
        gUnk_03002C30[rec * 4 + 0x5A].unk0 &= 0x7FFF;
        gUnk_03002C30[rec * 4 + 0x5B].unk0 &= 0x7FFF;
        gUnk_03002C30[rec * 4 + 0x5C].unk0 &= 0x7FFF;
        gUnk_03002C30[rec * 4 + 0x5D].unk0 &= 0x7FFF;
    }
}

void sub_080373D4(u32 rec) {
    gUnk_03002C30[rec * 4 + 0x5A].unk0 |= 0x8000;
    gUnk_03002C30[rec * 4 + 0x5B].unk0 |= 0x8000;
    gUnk_03002C30[rec * 4 + 0x5C].unk0 |= 0x8000;
    gUnk_03002C30[rec * 4 + 0x5D].unk0 |= 0x8000;
}

void sub_08037424(u32 slot) {
    gUnk_03002C30[slot].unk4 = (gUnk_03002C30[slot].unk4 + gUnk_083AF4E0[gUnk_03002C30[slot].unk23]) & 0xFF;
    gUnk_03002C30[slot].unk23 = (gUnk_03002C30[slot].unk23 + 1) & 31;
}

void sub_08037458(u32 rec, s32 amount) {
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

void sub_08037498(u32 rec, s32 amount) {
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

void sub_080374E0(u32 a, u32 b) {
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

void sub_0803752C(u32 a, u32 max, u32 b) {
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

u8 sub_08037578(u32 a, u32 kind) {
    u8 ret = 0;

    rng_next_080424B8();
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

void sub_0803769C(u32 rec) {
    gUnk_03001800.unkE8 = 0;
    gUnk_03001800.unkE8 = gUnk_03000590[rec].unkA8[3];
    gUnk_03001800.unkE8 += calc_bot_matching_part_power(rec);
    gUnk_03001800.unkE8 += rng_next_080424B8() & 7;
    gUnk_03001800.unkE8 += gUnk_03000590[rec].medal.unk20[gUnk_03000590[rec].unkA8[1]];
}

void sub_080376F4(u32 rec) {
    gUnk_03001800.unkEC = gUnk_03001800.unkE8 >> 3;
    gUnk_03001800.unkEC += gUnk_03000590[rec].unkA8[4];
    if (gUnk_03001800.unkEC == 0)
        gUnk_03001800.unkEC = 1;
}

// No return statement: the original never sets r0 but is not void (`pop {r1}` epilogue).
u32 sub_08037728(u32 rec, u32 part, u32 amount) {
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

u32 sub_08037798(u32 base) {
    u32 i, j, dir;

    i = rng_lookup_table_value();
    dir = rng_next_080424B8() & 1;
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

u32 battle_select_random_target(u32 base, u32 rec) {
    u32 i, j, dir;

    i = rng_lookup_table_value();
    dir = rng_next_080424B8() & 1;
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

void sub_080378A8(void) {
    if (!(gUnk_03001800.unkF8 & 2))
        gUnk_03002C30[0x21].unk2 = (gUnk_03002C30[0x21].unk2 + 4) & 0x1FF;
    else
        gUnk_03002C30[0x21].unk2 = (gUnk_03002C30[0x21].unk2 - 4) & 0x1FF;
}

void sub_080378F0(u32 src) {
    u32 mask;
    u32 n;
    struct Unk_03002C30 *p, *s;
    struct Unk_03002C30 *base;

    switch (gUnk_03001800.unk51) {
    case 0:
        mask = 0xF;
        break;
    case 1:
        mask = 7;
        break;
    case 2:
        mask = 7;
        break;
    case 3:
        mask = 7;
        break;
    case 4:
        mask = 7;
        break;
    case 5:
        mask = 7;
        break;
    }
    base = gUnk_03002C30;
    p = &base[src];
    if (!(p->unk2D & mask)) {
        n = find_next_free_sprite_slot(src + 1, 0x14);
        clear_battle_sprite_slot(n, 1);
        s = &base[n];
        s->unk0 = 0xC604;
        s->unk1C = 0;
        s->unk2 = (p->unk2 + gUnk_083AF520[(rng_next_080424B8() & 3) * 2]) & 0x1FF;
        s->unk4 = (p->unk4 + gUnk_083AF520[(rng_next_080424B8() & 3) * 2 + 1]) & 0xFF;
        s->unk8 = 0x40;
        s->unk9 = 0x40;
        s->unkA = 6;
        s->unkB = 0xE0;
        switch (gUnk_03001800.unk51) {
        case 0:
            gUnk_03002C30[n].unk6 = (rng_next_080424B8() & 3) + 0x6B01;
            gUnk_03002C30[n].unk29 = 0x10;
            break;
        case 1:
            gUnk_03002C30[n].unk6 = 0x6C01;
            gUnk_03002C30[n].unk29 = 0x14;
            break;
        case 2:
            gUnk_03002C30[n].unk6 = 0x6D01;
            gUnk_03002C30[n].unk29 = 0x18;
            break;
        case 3:
            init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x5E], n);
            gUnk_03002C30[n].unk29 = 0x1C;
            break;
        case 4:
            gUnk_03002C30[n].unk6 = 0x7001;
            gUnk_03002C30[n].unk29 = 0x20;
            break;
        case 5:
            break;
        }
    }
}

void spawn_battle_particle_effect(u32 src) {
    u32 mask;
    u32 n;
    struct Unk_03002C30 *p, *s;
    struct Unk_03002C30 *base;

    switch (gUnk_03001800.unk51) {
    case 0:
        mask = 7;
        break;
    case 1:
        mask = 7;
        break;
    case 2:
        mask = 7;
        break;
    }
    base = gUnk_03002C30;
    p = &base[src];
    if (!(p->unk2D & mask)) {
        n = find_next_free_sprite_slot(src + 1, 0x14);
        clear_battle_sprite_slot(n, 1);
        s = &base[n];
        s->unk0 = 0xC604;
        s->unk1C = 0;
        s->unk2 = (p->unk2 + gUnk_083AF520[(rng_next_080424B8() & 3) * 2]) & 0x1FF;
        s->unk4 = (p->unk4 + gUnk_083AF520[(rng_next_080424B8() & 3) * 2 + 1]) & 0xFF;
        s->unk8 = 0x40;
        s->unk9 = 0x40;
        s->unkA = 6;
        s->unkB = 0xE0;
        switch (gUnk_03001800.unk51) {
        case 0:
            s->unk6 = 0x7201;
            s->unk29 = 0x30;
            break;
        case 1:
            s->unk6 = 0x7302;
            s->unk29 = 0x34;
            break;
        case 2:
            s->unk6 = 0x7402;
            s->unk29 = 0x34;
            break;
        }
    }
}

u32 sub_08037B9C(void) {
    u32 done = 1;
    u32 i;
    u32 k;

    for (i = 0; i <= 0x1A; i++) {
        gUnk_0300056F = i + 0x21;
        if (gUnk_03002C30[i + 0x21].unk29)
            done = 0;
        k = gUnk_03002C30[i + 0x21].unk29;
        gUnk_083AF530[k]();
    }
    return done;
}

void sub_08037BF4(void) {
    process_sprite_anim_commands(gUnk_083B5F80[gUnk_03002C30[gUnk_03000440.unk12F].unk2E], gUnk_03000440.unk12F);
    if (gUnk_03002C30[gUnk_03000440.unk12F].unk4 == 0x14)
        gUnk_03002C30[gUnk_03000440.unk12F].unk29++;
    else
        gUnk_03002C30[gUnk_03000440.unk12F].unk4 = (gUnk_03002C30[gUnk_03000440.unk12F].unk4 + 1) & 0xFF;
}

void sub_08037C50(void) {
    struct Coords16 v;

    process_sprite_anim_commands(gUnk_083B5F80[gUnk_03002C30[gUnk_03000440.unk12F].unk2E], gUnk_03000440.unk12F);
    if (gUnk_03002C30[gUnk_03000440.unk12F].unk2D == 0xFF) {
        gUnk_03002C30[gUnk_03000440.unk12F].unk29++;
        return;
    }
    if (!(gUnk_03002C30[gUnk_03000440.unk12F].unk2D & 0x3F)) {
        switch (gUnk_03001800.unk51) {
        case 0:
            play_sound_effect(0x36);
            break;
        case 1:
            play_sound_effect(0x28);
            break;
        case 2:
            play_sound_effect(0x31);
            break;
        case 3:
            play_sound_effect(0x71);
            break;
        case 4:
            play_sound_effect(0x4F);
            break;
        case 5:
            break;
        }
    }
    gUnk_03002C30[gUnk_03000440.unk12F].unk2B += gUnk_083AF630[(gUnk_03002C30[gUnk_03000440.unk12F].unk2D & 0x1F) * 2];
    if (!(gUnk_03001800.unkF8 & 1)) {
        if (gUnk_03001800.unk51 != 3)
            gUnk_03002C30[gUnk_03000440.unk12F].unk18 = (gUnk_03002C30[gUnk_03000440.unk12F].unk18 - 0x10) & 0x3FF;
        gUnk_03002C30[gUnk_03000440.unk12F].unk2C--;
        v = calc_polar_to_screen_coords(gUnk_03002C30[gUnk_03000440.unk12F].unk2C,
                                        gUnk_03002C30[gUnk_03000440.unk12F].unk2B, 0xB8, 0x34);
    } else {
        if (gUnk_03001800.unk51 != 3)
            gUnk_03002C30[gUnk_03000440.unk12F].unk18 = (gUnk_03002C30[gUnk_03000440.unk12F].unk18 + 0x10) & 0x3FF;
        gUnk_03002C30[gUnk_03000440.unk12F].unk2C++;
        v = calc_polar_to_screen_coords(gUnk_03002C30[gUnk_03000440.unk12F].unk2C,
                                        gUnk_03002C30[gUnk_03000440.unk12F].unk2B, 0x38, 0x34);
    }
    gUnk_03002C30[gUnk_03000440.unk12F].unk2 = v.x;
    gUnk_03002C30[gUnk_03000440.unk12F].unk4 = v.y;
    sub_080378F0(gUnk_03000440.unk12F);
    gUnk_03002C30[gUnk_03000440.unk12F].unk2D++;
}

void sub_08037E2C(void) {
    struct Coords16 v;

    process_sprite_anim_commands(gUnk_083B5F80[gUnk_03002C30[gUnk_03000440.unk12F].unk2E], gUnk_03000440.unk12F);
    if (gUnk_03002C30[gUnk_03000440.unk12F].unk2D == 0xFF) {
        gUnk_03002C30[gUnk_03000440.unk12F].unk29++;
        return;
    }
    if (!(gUnk_03002C30[gUnk_03000440.unk12F].unk2D & 0x3F)) {
        switch (gUnk_03001800.unk51) {
        case 0:
            play_sound_effect(0x5D);
            break;
        case 1:
            play_sound_effect(0x2E);
            break;
        case 2:
            play_sound_effect(0x4B);
            break;
        }
    }
    gUnk_03002C30[gUnk_03000440.unk12F].unk2B += gUnk_083AF630[(gUnk_03002C30[gUnk_03000440.unk12F].unk2D & 0x1F) * 2];
    if (gUnk_03001800.unkF8 & 1) {
        if (gUnk_03001800.unk51 == 0)
            gUnk_03002C30[gUnk_03000440.unk12F].unk18 = (gUnk_03002C30[gUnk_03000440.unk12F].unk18 - 0x10) & 0x3FF;
        gUnk_03002C30[gUnk_03000440.unk12F].unk2C--;
        v = calc_polar_to_screen_coords(gUnk_03002C30[gUnk_03000440.unk12F].unk2C,
                                        gUnk_03002C30[gUnk_03000440.unk12F].unk2B, 0xB8, 0x34);
    } else {
        if (gUnk_03001800.unk51 == 0)
            gUnk_03002C30[gUnk_03000440.unk12F].unk18 = (gUnk_03002C30[gUnk_03000440.unk12F].unk18 + 0x10) & 0x3FF;
        gUnk_03002C30[gUnk_03000440.unk12F].unk2C++;
        v = calc_polar_to_screen_coords(gUnk_03002C30[gUnk_03000440.unk12F].unk2C,
                                        gUnk_03002C30[gUnk_03000440.unk12F].unk2B, 0x38, 0x34);
    }
    gUnk_03002C30[gUnk_03000440.unk12F].unk2 = v.x;
    gUnk_03002C30[gUnk_03000440.unk12F].unk4 = v.y;
    spawn_battle_particle_effect(gUnk_03000440.unk12F);
    gUnk_03002C30[gUnk_03000440.unk12F].unk2D++;
}

void sub_08037FE4(void) {
    if (gUnk_03002C30[gUnk_03000440.unk12F].unk8 == 4) {
        gUnk_03002C30[gUnk_03000440.unk12F].unk29++;
    } else {
        gUnk_03002C30[gUnk_03000440.unk12F].unk8 -= 4;
        gUnk_03002C30[gUnk_03000440.unk12F].unk9 -= 4;
    }
}

void sub_08038024(void) {
    if (gUnk_03002C30[gUnk_03000440.unk12F].unk2D == 0x5A)
        gUnk_03002C30[gUnk_03000440.unk12F].unk29++;
    else
        gUnk_03002C30[gUnk_03000440.unk12F].unk2D++;
}

void sub_0803805C(void) {
    if (gUnk_03002C30[gUnk_03000440.unk12F].unk8 == 8) {
        gUnk_03002C30[gUnk_03000440.unk12F].unk29++;
    } else {
        gUnk_03002C30[gUnk_03000440.unk12F].unk8 -= 8;
        gUnk_03002C30[gUnk_03000440.unk12F].unk9 -= 8;
    }
}

void sub_0803809C(void) {
    clear_battle_sprite_slot(gUnk_03000440.unk12F, 1);
}

void sub_080380B8(void) {
    if (gUnk_03002C30[gUnk_03000440.unk12F].unk2D == 0x23)
        gUnk_03002C30[gUnk_03000440.unk12F].unk29++;
    else
        gUnk_03002C30[gUnk_03000440.unk12F].unk2D++;
}

void sub_080380F0(void) {
    if (gUnk_03002C30[gUnk_03000440.unk12F].unk2D == 0x46) {
        gUnk_03002C30[gUnk_03000440.unk12F].unk29++;
    } else {
        gUnk_03002C30[gUnk_03000440.unk12F].unk2 = (gUnk_03002C30[gUnk_03000440.unk12F].unk2 +
                                                    gUnk_083AF670[gUnk_03002C30[gUnk_03000440.unk12F].unk2D & 0xF]) &
                                                   0x1FF;
        if (gUnk_03002C30[gUnk_03000440.unk12F].unk2D & 1)
            gUnk_03002C30[gUnk_03000440.unk12F].unk4++;
        gUnk_03002C30[gUnk_03000440.unk12F].unk2D++;
    }
}

void sub_08038178(void) {
    process_sprite_anim_commands(gUnk_083B5F80[0x5E], gUnk_03000440.unk12F);
    if (gUnk_03002C30[gUnk_03000440.unk12F].unk2D == 0x5A)
        gUnk_03002C30[gUnk_03000440.unk12F].unk29++;
    else {
        if (!(gUnk_03002C30[gUnk_03000440.unk12F].unk2D & 7))
            gUnk_03002C30[gUnk_03000440.unk12F].unk4--;
        gUnk_03002C30[gUnk_03000440.unk12F].unk2D++;
    }
}

void sub_080381E0(void) {
    if (gUnk_03002C30[gUnk_03000440.unk12F].unk2D == 0x23) {
        gUnk_03002C30[gUnk_03000440.unk12F].unk29++;
    } else {
        if (!(gUnk_03001800.unkF8 & 1))
            gUnk_03002C30[gUnk_03000440.unk12F].unk18 = (gUnk_03002C30[gUnk_03000440.unk12F].unk18 - 0x10) & 0x3FF;
        else
            gUnk_03002C30[gUnk_03000440.unk12F].unk18 = (gUnk_03002C30[gUnk_03000440.unk12F].unk18 + 0x10) & 0x3FF;
        gUnk_03002C30[gUnk_03000440.unk12F].unk2D++;
    }
}

void sub_08038258(void) {
    if (gUnk_03002C30[gUnk_03000440.unk12F].unk2D == 0x46) {
        gUnk_03002C30[gUnk_03000440.unk12F].unk29++;
    } else {
        if (gUnk_03002C30[gUnk_03000440.unk12F].unk2D & 1)
            gUnk_03002C30[gUnk_03000440.unk12F].unk4++;
        if (!(gUnk_03001800.unkF8 & 1))
            gUnk_03002C30[gUnk_03000440.unk12F].unk18 = (gUnk_03002C30[gUnk_03000440.unk12F].unk18 - 0x10) & 0x3FF;
        else
            gUnk_03002C30[gUnk_03000440.unk12F].unk18 = (gUnk_03002C30[gUnk_03000440.unk12F].unk18 + 0x10) & 0x3FF;
        gUnk_03002C30[gUnk_03000440.unk12F].unk2D++;
    }
}

void sub_080382F4(void) {
    if (gUnk_03002C30[gUnk_03000440.unk12F].unk2D == 0x5A) {
        gUnk_03002C30[gUnk_03000440.unk12F].unk29++;
    } else {
        if (gUnk_03001800.unkF8 & 1)
            gUnk_03002C30[gUnk_03000440.unk12F].unk18 = (gUnk_03002C30[gUnk_03000440.unk12F].unk18 - 0x10) & 0x3FF;
        else
            gUnk_03002C30[gUnk_03000440.unk12F].unk18 = (gUnk_03002C30[gUnk_03000440.unk12F].unk18 + 0x10) & 0x3FF;
        gUnk_03002C30[gUnk_03000440.unk12F].unk2D++;
    }
}

void sub_0803836C(void) {
    u32 i;
    for (i = 0; i <= 2; i++) {
        gUnk_03001800.unkD2[i] = 0;
        gUnk_03001800.unkD6[i] = 0;
    }
}

void sub_08038394(u32 rec, u32 flags) {
    if (flags & 1) {
        gUnk_03000590[rec].unkC9 = 0;
        gUnk_03000590[rec].unkCA = 0;
        gUnk_03000590[rec].unkCB = 0;
        gUnk_03000590[rec].unkCC = 0;
    }
    if (flags & 2) {
        gUnk_03000590[rec].unkC4 = 0;
        gUnk_03000590[rec].unkC5 = 0;
        gUnk_03000590[rec].unkC6 = 0;
        gUnk_03000590[rec].unkC7 = 0;
    }
}

void sub_080383E8(void) {
    u32 i;
    for (i = 10; i <= 0x1A; i++) {
        gUnk_0300056F = i + 0x21;
        gUnk_083AF690[gUnk_03002C30[i + 0x21].unk29]();
    }
}

void sub_08038428(void) {
    u32 r, slot;
    struct Unk_03002C30 *s;
    struct Unk_03002C30 *base;

    if ((r = gUnk_03000440.unk86 & 7) == 0) {
        slot = find_next_free_sprite_slot(gUnk_03000440.unk12F + 1, 10);
        clear_battle_sprite_slot(slot, 1);
        base = gUnk_03002C30;
        s = &base[slot];
        s->unk0 = 0xC604;
        s->unk1C = 0;
        s->unk2 = 0x78;
        s->unk4 = 0x78;
        s->unk8 = 0x40;
        s->unk9 = 0x40;
        s->unk18 = r;
        s->unkA = 6;
        s->unkB = 0xF0;
        s->unk6 = 0x7706;
        s->unk29 = 2;
        s->unk24 = 3;
        s->unk23 = 0;
        r = rng_next_080424B8() & 3;
        if (!(gUnk_03001800.unkF8 & 1)) {
            s->unk2 = (base[gUnk_03000440.unk12F].unk2 + gUnk_083AF6D0[r << 1]) & 0x1FF;
            s->unk4 = (base[gUnk_03000440.unk12F].unk4 + gUnk_083AF6D0[r * 2 + 1]) & 0xFF;
            s->unk30 = base[gUnk_03000440.unk12F].unk2 + 0x10;
            s->unk32 = base[gUnk_03000440.unk12F].unk4 + 4;
        } else {
            s->unk2 = (0xF0 - (base[gUnk_03000440.unk12F].unk2 + gUnk_083AF6D0[r << 1])) & 0x1FF;
            s->unk4 = (base[gUnk_03000440.unk12F].unk4 + gUnk_083AF6D0[r * 2 + 1]) & 0xFF;
            s->unk30 = base[gUnk_03000440.unk12F].unk2 - 0x10;
            s->unk32 = base[gUnk_03000440.unk12F].unk4 + 6;
        }
    }
}

void sub_0803858C(void) {
    gUnk_03002C30[gUnk_03000440.unk12F].unk18 = (gUnk_03002C30[gUnk_03000440.unk12F].unk18 + 0x10) & 0x3FF;
    if (move_sprite_toward_target(gUnk_03000440.unk12F))
        clear_battle_sprite_slot(gUnk_03000440.unk12F, 1);
}

void sub_080385D0(u32 rec) {
    u32 i;
    struct Unk_03001800 *b;
    for (i = 0, b = &gUnk_03001800; i <= 5; i++) {
        if (b->unk45[i][0] == rec + 1) {
            b->unk45[i][0] = 0;
            b->unk45[i][1] = 0;
        }
    }
}

u32 sub_080385F8(void) {
    u32 done = 1;
    u32 i;
    u32 k;

    for (i = 0; i <= 0x1A; i++) {
        gUnk_0300056F = i + 0x21;
        if (gUnk_03002C30[i + 0x21].unk29)
            done = 0;
        k = gUnk_03002C30[i + 0x21].unk29;
        gUnk_083AF6E0[k]();
    }
    return done;
}

void sub_08038650(void) {
    if (move_sprite_toward_target(gUnk_03000440.unk12F)) {
        init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x6B], gUnk_03000440.unk12F);
        gUnk_03002C30[gUnk_03000440.unk12F].unkA = 6;
        gUnk_03002C30[gUnk_03000440.unk12F].unk28 = 0;
        gUnk_03002C30[gUnk_03000440.unk12F].unk29++;
        memcpy_bytes_0803F63C(&gUnk_03002C30[gUnk_03000440.unk12F], &gUnk_03002C30[gUnk_03000440.unk12F + 3], 0x40);
        init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x6C], gUnk_03000440.unk12F + 3);
        gUnk_03002C30[gUnk_03000440.unk12F + 3].unkB = (gUnk_03000440.unk12F + (gUnk_03001800.unk60 + 0xDF)) * 4 + 0x59;
        gUnk_03002C30[gUnk_03000440.unk12F + 3].unk29 = 3;
    }
}

void sub_08038700(void) {
    gUnk_03002C30[gUnk_03000440.unk12F].unk28++;
    if (gUnk_03002C30[gUnk_03000440.unk12F].unk28 & 2)
        gUnk_03002C30[((gUnk_03001800.unk60 + (gUnk_03000440.unk12F - 0x21))) * 4 + 0x5D].unk4 =
            gUnk_03001800.unk13C[(gUnk_03001800.unk60 + (gUnk_03000440.unk12F - 0x21))].y + 2;
    else
        gUnk_03002C30[((gUnk_03001800.unk60 + (gUnk_03000440.unk12F - 0x21))) * 4 + 0x5D].unk4 =
            gUnk_03001800.unk13C[(gUnk_03001800.unk60 + (gUnk_03000440.unk12F - 0x21))].y + 4;
    sub_080350E0((gUnk_03001800.unk60 + (gUnk_03000440.unk12F - 0x21)));
    process_sprite_anim_commands(gUnk_083B5F80[0x6B], gUnk_03000440.unk12F);
    if (gUnk_03002C30[gUnk_03000440.unk12F].unk22 == 0xFF) {
        gUnk_03002C30[((gUnk_03001800.unk60 + (gUnk_03000440.unk12F - 0x21))) * 4 + 0x5D].unk4 =
            gUnk_03001800.unk13C[(gUnk_03001800.unk60 + (gUnk_03000440.unk12F - 0x21))].y + 4;
        sub_080350E0((gUnk_03001800.unk60 + (gUnk_03000440.unk12F - 0x21)));
        clear_battle_sprite_slot(gUnk_03000440.unk12F, 1);
    }
}

void sub_08038804(void) {
    process_sprite_anim_commands(gUnk_083B5F80[0x6C], gUnk_03000440.unk12F);
    if (gUnk_03002C30[gUnk_03000440.unk12F].unk22 == 0xFF)
        clear_battle_sprite_slot(gUnk_03000440.unk12F, 1);
}

u32 sub_0803884C(void) {
    u32 done = 1;
    u32 i;
    u32 k;

    for (i = 0; i <= 0x1A; i++) {
        gUnk_0300056F = i + 0x21;
        if (gUnk_03002C30[i + 0x21].unk29)
            done = 0;
        k = gUnk_03002C30[i + 0x21].unk29;
        gUnk_083AF720[k]();
    }
    return done;
}

void sub_080388A4(void) {
    process_sprite_anim_commands(gUnk_083B5F80[0x6D], gUnk_03000440.unk12F);
    if (!(gUnk_03001800.unkF8 & 1)) {
        gUnk_03002C30[gUnk_03000440.unk12F].unk2 = (gUnk_03002C30[gUnk_03000440.unk12F].unk2 + 4) & 0x1FF;
        if (gUnk_03002C30[gUnk_03000440.unk12F].unk2 >
                gUnk_03002C30[(gUnk_03001800.unk60 + (gUnk_03000440.unk12F - 0x21)) * 4 + 0x5D].unk2 &&
            gUnk_03001800.unkD6[gUnk_03000440.unk12F - 0x21] != 0 && gUnk_03002C30[gUnk_03000440.unk12F].unk28 == 0) {
            play_sound_effect(0x54);
            gUnk_03002C30[gUnk_03000440.unk12F + 3].unk0 = 0xC404;
            gUnk_03002C30[gUnk_03000440.unk12F + 3].unk1C = 0;
            gUnk_03002C30[gUnk_03000440.unk12F + 3].unk2 =
                gUnk_03002C30[(gUnk_03001800.unk60 + (gUnk_03000440.unk12F - 0x21)) * 4 + 0x5D].unk2;
            gUnk_03002C30[gUnk_03000440.unk12F + 3].unk4 =
                gUnk_03002C30[(gUnk_03001800.unk60 + (gUnk_03000440.unk12F - 0x21)) * 4 + 0x5D].unk4 - 4;
            gUnk_03002C30[gUnk_03000440.unk12F + 3].unkA = 6;
            gUnk_03002C30[gUnk_03000440.unk12F + 3].unkB = 0xF1;
            gUnk_03002C30[gUnk_03000440.unk12F + 3].unk29 = 2;
            gUnk_03002C30[gUnk_03000440.unk12F + 3].unk28 = 0;
            init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x6E], gUnk_03000440.unk12F + 3);
            gUnk_03002C30[gUnk_03000440.unk12F].unk28 = 1;
        }
    } else {
        gUnk_03002C30[gUnk_03000440.unk12F].unk2 = (gUnk_03002C30[gUnk_03000440.unk12F].unk2 - 4) & 0x1FF;
        if (gUnk_03002C30[gUnk_03000440.unk12F].unk2 <
                gUnk_03002C30[(gUnk_03001800.unk60 + (gUnk_03000440.unk12F - 0x21)) * 4 + 0x5D].unk2 &&
            gUnk_03001800.unkD6[gUnk_03000440.unk12F - 0x21] != 0 && gUnk_03002C30[gUnk_03000440.unk12F].unk28 == 0) {
            play_sound_effect(0x54);
            gUnk_03002C30[gUnk_03000440.unk12F + 3].unk0 = 0xD404;
            gUnk_03002C30[gUnk_03000440.unk12F + 3].unk1C = 0;
            gUnk_03002C30[gUnk_03000440.unk12F + 3].unk2 =
                gUnk_03002C30[(gUnk_03001800.unk60 + (gUnk_03000440.unk12F - 0x21)) * 4 + 0x5D].unk2;
            gUnk_03002C30[gUnk_03000440.unk12F + 3].unk4 =
                gUnk_03002C30[(gUnk_03001800.unk60 + (gUnk_03000440.unk12F - 0x21)) * 4 + 0x5D].unk4 - 4;
            gUnk_03002C30[gUnk_03000440.unk12F + 3].unkA = 6;
            gUnk_03002C30[gUnk_03000440.unk12F + 3].unkB = 0xF1;
            gUnk_03002C30[gUnk_03000440.unk12F + 3].unk29 = 2;
            gUnk_03002C30[gUnk_03000440.unk12F + 3].unk28 = 0;
            init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x6E], gUnk_03000440.unk12F + 3);
            gUnk_03002C30[gUnk_03000440.unk12F].unk28 = 1;
        }
    }
    if (gUnk_03002C30[gUnk_03000440.unk12F].unk27 > 0x28)
        clear_battle_sprite_slot(gUnk_03000440.unk12F, 1);
    else
        gUnk_03002C30[gUnk_03000440.unk12F].unk27++;
}

void sub_08038AC0(void) {
    gUnk_03002C30[gUnk_03000440.unk12F].unk28++;
    if (gUnk_03002C30[gUnk_03000440.unk12F].unk28 & 2)
        gUnk_03002C30[((gUnk_03001800.unk60 + (gUnk_03000440.unk12F - 0x24))) * 4 + 0x5D].unk2 =
            gUnk_03001800.unk13C[(gUnk_03001800.unk60 + (gUnk_03000440.unk12F - 0x24))].x + 2;
    else
        gUnk_03002C30[((gUnk_03001800.unk60 + (gUnk_03000440.unk12F - 0x24))) * 4 + 0x5D].unk2 =
            gUnk_03001800.unk13C[(gUnk_03001800.unk60 + (gUnk_03000440.unk12F - 0x24))].x - 2;
    sub_080350E0((gUnk_03001800.unk60 + (gUnk_03000440.unk12F - 0x24)));
    process_sprite_anim_commands(gUnk_083B5F80[0x6E], gUnk_03000440.unk12F);
    if (gUnk_03002C30[gUnk_03000440.unk12F].unk22 == 0xFF) {
        gUnk_03002C30[((gUnk_03001800.unk60 + (gUnk_03000440.unk12F - 0x24))) * 4 + 0x5D].unk2 =
            gUnk_03001800.unk13C[(gUnk_03001800.unk60 + (gUnk_03000440.unk12F - 0x24))].x;
        sub_080350E0((gUnk_03001800.unk60 + (gUnk_03000440.unk12F - 0x24)));
        clear_battle_sprite_slot(gUnk_03000440.unk12F, 1);
    }
}

void sub_08038BC0(void) {
    gUnk_03001800.unkE8 = 0;
    calc_battle_action_speed(gUnk_03001800.unk87, gUnk_03001800.unkA7);
    if (check_bot_ability_type_strike(gUnk_03001800.unk87, gUnk_03001800.unkA7, gUnk_03001800.unk88))
        gUnk_03001800.unkE8 += gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03001800.unkA7].data[5] << 4;
    if (check_bot_ability_type_shoot(gUnk_03001800.unk87, gUnk_03001800.unkA7, gUnk_03001800.unk88))
        gUnk_03001800.unkE8 += gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03001800.unkA7].data[5] << 4;
    if (gUnk_03000590[gUnk_03001800.unk87].unkD6 & 4)
        gUnk_03001800.unkE8 += gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03001800.unkA7].data[5];
    gUnk_03001800.unkE8 += gUnk_03001800.unk28[gUnk_03001800.unk89].unk0;
    sub_080358F0(gUnk_03001800.unk87);
    if (gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03001800.unkA7].data[1] == 8)
        goto add;
    if (gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03001800.unkA7].data[1] == 9) {
    add:
        gUnk_03001800.unkE8 += gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03001800.unkA7].data[5];
    }
    if (gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03001800.unkA7].data[1] == 0x34 &&
        gUnk_03001800.unk28[gUnk_03001800.unk8A].unk3 == 0x33)
        gUnk_03001800.unkE8 += gUnk_03001800.unk28[gUnk_03001800.unk8A].unk4;
    apply_battle_bot_damage_reduction(gUnk_03001800.unk87);
    sub_08035754(&gUnk_03001800.unkE8, gUnk_03000590[gUnk_03001800.unk88].unkB9);
}
