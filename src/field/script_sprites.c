// Map script sprites: the sprite slots a script controls (spawn_script_sprite, init_script_sprite), their
// step-by-step movement and animation, the snapshot kept while the field menu is open
// (save_script_sprites / restore_script_sprites), and map_script_command_done. Talks to the engine
// sprite code and field/map_script.
#include "global.h"

static void init_script_sprite(u8 idx, u8 part, u8 x, u8 y);

void setup_battle_sprite_terrain(u8 slot, u8 a, u8 b) {
    struct Unk_03002C30 *base = gUnk_03002C30;
    struct Unk_03002C30 *spr = &base[slot];

    spr->unk27 = a & 0xF;
    a = (a & 0xF0) >> 4;
    set_sprite_animation_state(slot, a);
    spr->unk2A = b;
    spr->unk28 = 16 / sprite_walk_speed(slot);
    sub_080493D4(slot, sub_080502B4(slot, a));
}

void sub_080500D8(u8 slot, u8 a, u8 b) {
    struct Unk_03002C30 *base = gUnk_03002C30;
    struct Unk_03002C30 *spr = &base[slot];

    spr->unk27 = a & 0xF;
    spr->unk20 = (a & 0xF0) >> 4;
    spr->unk2A = b;
    spr->unk28 = 16 / sprite_walk_speed(slot);
}

void advance_sprite_by_terrain_modifier(u8 slot) {
    s32 i;

    for (i = 0; i < sprite_walk_speed(slot); i++)
        advance_sprite_animation_frame(slot);
}

u32 update_battle_sprite_movement(u8 slot, u8 mode) {
    u32 done = 0;
    struct Unk_03002C30 *base = gUnk_03002C30;
    struct Unk_03002C30 *spr = &base[slot];

    if (spr->unk28 != 0) {
        switch (spr->unk20) {
        case 0:
            spr->unk10_8 -= sprite_walk_speed(slot);
            break;
        case 1:
            spr->unk10_8 += sprite_walk_speed(slot);
            break;
        case 2:
            spr->unkC_8 -= sprite_walk_speed(slot);
            break;
        case 3:
            spr->unkC_8 += sprite_walk_speed(slot);
            break;
        }
        if (mode)
            advance_sprite_by_terrain_modifier(slot);
        if (--gUnk_03002C30[slot].unk28 == 0) {
            switch (gUnk_03002C30[slot].unk30) {
            case 0x71:
            case 0x78:
            case 0x82:
            case 0x83:
            case 0x84:
                sub_08047BA8(0x57);
                break;
            }
            gUnk_03002C30[slot].unk28 = 16 / sprite_walk_speed(slot);
            if (--gUnk_03002C30[slot].unk27 == 0)
                done = 1;
        }
    }
    return done;
}

// Ends the current command: the next frame runs the next one (map_script_run_command).
void map_script_command_done(void) {
    gUnk_030057E0.unkC93 = 0;
    gUnk_030057E0.unkC89 = 0;
}

u8 sub_08050264(u8 a) {
    return a >> 4;
}

static u8 sub_0805026C(u8 a) {
    return a & 3;
}

u8 calc_medapart_table_index(u8 a) {
    return sub_08050264(a) * 12 + sub_0805026C(a) * 3;
}

u8 sub_080502B4(u8 slot, u8 v) {
    return v + gUnk_03002C30[slot].unk2B * 4;
}

static u8 compute_battle_sprite_anim_offset(u8 id, u8 a) {
    return gUnk_03002C30[sub_0804DBA4(id) + 79].unk2B * 12 + a * 3;
}

// Map script opcodes: sprite slot flags & 0xF (+0x4F), graphics id, tile x / y; bit 0x40 = 5 px lower.
void spawn_script_sprite(u8 flags, u8 part, u8 x, u8 y) {
    u32 idx = flags & 0xF;

    if ((flags & 0xF0) && find_map_event_by_coords(x, y) && gUnk_03006D38.unk3)
        sub_08047BA8(gUnk_083D29E6[gUnk_03006D38.unk3]);
    sub_0804DB84(idx, find_next_available_battle_sprite_slot());
    init_script_sprite(sub_0804DBA4(idx), part, x, y);
    if (flags & 0x40)
        gUnk_03002C30[sub_0804DBA4(idx) + 0x4F].unk10_8 += 5;
}

// Sets up script sprite idx + 0x4F at tile (x, y), plus an overlay sprite at idx + 0x79 on some tiles.
static void init_script_sprite(u8 idx, u8 part, u8 x, u8 y) {
    u32 slot = idx + 0x4F;
    struct Unk_03002C30 *spr;
    u32 tile;
    u8 anim;

    sprite_entry_clear(slot);
    sprite_entry_init(slot, 0xC804, calc_medapart_table_index(part), sub_08050264(part), 1);
    anim = sub_08050264(part);
    spr = &gUnk_03002C30[slot];
    spr->unk2B = anim;
    spr->unk20 = sub_0805026C(part);
    spr->unkC_8 = x * 16 + gUnk_030057E0.unkC48;
    spr->unk10_8 = y * 16 + gUnk_030057E0.unkC4A;
    gUnk_030055A0[slot].unk0 = 0xFFFF;
    spr->unk2C = 0;
    tile = area_sprite_sheet_id(spr->unk2B);
    spr->unk30 = tile;
    sprite_set_blend_from_kind(slot);
    if (gUnk_083D2B8D[tile]) {
        sprite_entry_init(idx + 0x79, 0xCC0C, 0x90, 0xE, 1);
        gUnk_03002C30[idx + 0x79].unkC_8 = spr->unkC_8;
        gUnk_03002C30[idx + 0x79].unk10_8 = spr->unk10_8 - 5;
    }
}

// guess: remove the sprite of map object (arg & 0xF); if arg & 0xF0, play the exit sound when it stands on an exit.
void sub_08050508(u8 arg) {
    u32 id = arg & 0xF;

    if (arg & 0xF0) {
        u8 x = sub_080526F0(gUnk_03002C30[sub_0804DBA4(id) + 79].unkC_8);
        u8 y = sub_08052714(gUnk_03002C30[sub_0804DBA4(id) + 79].unk10_8);

        if (find_map_event_by_coords(x, y) && gUnk_03006D38.unk3)
            sub_08047BA8(gUnk_083D29E6[gUnk_03006D38.unk3]);
    }
    sprite_entry_clear(sub_0804DBA4(id) + 79);
    sprite_entry_clear(sub_0804DBA4(id) + 121);
    sub_0804DB68(id);
}

// Snapshot of the 6 script sprites into gUnk_030057E0.unk7DC (runtime: opening the field menu).
void save_script_sprites(void) {
    s32 i;

    memzero_bytes((u8 *)gUnk_030057E0.unk7DC, sizeof(gUnk_030057E0.unk7DC));
    for (i = 0; i <= 5; i++) {
        if (gUnk_030055A0[i + 79].unk0) {
            gUnk_030057E0.unk7DC[i].x = sub_080526F0(gUnk_03002C30[i + 79].unkC_8);
            gUnk_030057E0.unk7DC[i].y = sub_08052714(gUnk_03002C30[i + 79].unk10_8);
            gUnk_030057E0.unk7DC[i].anim =
                ((gUnk_03002C30[i + 79].unk2B & 0xF) << 4) | (gUnk_03002C30[i + 79].unk20 & 3);
            gUnk_030057E0.unk7DC[i].id = i;
            gUnk_030057E0.unk7DC[i].unk2_6 = gUnk_03002C30[i + 79].unk2D;
            gUnk_030057E0.unk7DC[i].active = 1;
        }
    }
}

// Re-creates the script sprites from that snapshot (runtime: returning from the field menu).
void restore_script_sprites(void) {
    s32 i;

    for (i = 0; i <= 5; i++) {
        if (gUnk_030057E0.unk7DC[i].active && !gUnk_030057E0.unk7DC[i].unk2_6)
            init_script_sprite(i, gUnk_030057E0.unk7DC[i].anim, gUnk_030057E0.unk7DC[i].x, gUnk_030057E0.unk7DC[i].y);
    }
}

u32 find_next_available_battle_sprite_slot(void) {
    s32 i;
    for (i = 0; i < 6; i++) {
        if (!(gUnk_03002C30[i + 79].unk0 & 0x4000) && !gUnk_03002C30[i + 79].unk2E)
            break;
    }
    if (i == 6)
        return 5;
    return i;
}

void set_battle_sprite_animation(u8 id, u8 state) {
    gUnk_03002C30[sub_0804DBA4(id) + 79].unk20 = state;
    gUnk_03002C30[sub_0804DBA4(id) + 79].unk6 = compute_battle_sprite_anim_offset(id, state);
}

void sub_08050770(u32 idx, u8 val) {
    gUnk_03002C30[idx].unkB = val;
}

void sub_08050780(u8 i, u32 val) {
    gUnk_03002C30[sub_0804DBA4(i) + 79].unkB = val;
}

void sub_080507A0(u32 idx, u32 val) {
    u32 v = (gUnk_03002C30[idx].unk32 & 0xF3FF) | (val << 10);
    gUnk_03002C30[idx].unk0 = v;
    gUnk_03002C30[idx].unk32 = v;
}

void sub_080507C0(u8 i, u8 val) {
    sub_080507A0(sub_0804DBA4(i) + 79, val);
}

u32 sub_080507E0(u8 slot) {
    u32 ret = 0;

    if (gUnk_03006D20.unk0) {
        if (gUnk_03006D20.unk2)
            gUnk_03006D20.unk2--;
        else {
            gUnk_03006D20.unk1++;
            gUnk_03006D20.unk2 = gUnk_03006D20.unk3;
        }
        if (gUnk_03006D20.unk1 & 1) {
            gUnk_03002C30[slot].unk2D = 1;
            gUnk_03002C30[slot].unk0 = 0;
        } else {
            gUnk_03002C30[slot].unk2D = 0;
            gUnk_03002C30[slot].unk0 = gUnk_03002C30[slot].unk32;
        }
        gUnk_03006D20.unk0--;
    } else {
        gUnk_03002C30[slot].unk2D = 0;
        gUnk_03002C30[slot].unk0 = gUnk_03002C30[slot].unk32;
        ret = 1;
    }
    return ret;
}

u32 sub_08050868(void) {
    u32 ret = 0;

    switch (gUnk_03006D20.unk0) {
    case 0:
        sub_080493D4(gUnk_03006D20.unkA, sub_080502B4(gUnk_03006D20.unkA, gUnk_03002C30[gUnk_03006D20.unkA].unk20));
        gUnk_03006D20.unk0++;
        break;
    case 1:
        if (gUnk_03006D20.unk2) {
            advance_sprite_animation_frame(gUnk_03006D20.unkA);
            gUnk_03006D20.unk2--;
        } else
            ret = 1;
        break;
    }
    return ret;
}

u32 sub_080508CC(void) {
    u32 ret = 0;

    if (gUnk_03002C30[gUnk_03006D20.unkA].unk28 < 16) {
        gUnk_03002C30[gUnk_03006D20.unkA].unk10_8 =
            gUnk_03006D20.unk8 - gUnk_083D69A0[gUnk_03002C30[gUnk_03006D20.unkA].unk28][0] / 16;
        gUnk_03002C30[gUnk_03006D20.unkA].unk2C = gUnk_083D69A0[gUnk_03002C30[gUnk_03006D20.unkA].unk28][0] / 16;
        gUnk_03002C30[gUnk_03006D20.unkA].unk28++;
        if (gUnk_03002C30[gUnk_03006D20.unkA].unk10_8 / 4 <= (gUnk_03006D20.unk8 - 16) / 4)
            gUnk_03002C30[gUnk_03006D20.unkA].unkB = 0xFF;
        else
            sprite_set_blend_from_kind(gUnk_03006D20.unkA);
    } else {
        sprite_set_blend_from_kind(gUnk_03006D20.unkA);
        gUnk_03002C30[gUnk_03006D20.unkA].unk10_8 = gUnk_03006D20.unk8;
        gUnk_03002C30[gUnk_03006D20.unkA].unk2C = 0;
        ret = 1;
    }
    return ret;
}

u32 sub_080509A0(void) {
    u32 ret = 0;
    u8 slot = gUnk_03006D20.unkA;
    struct Unk_03002C30 *base = gUnk_03002C30;
    struct Unk_03002C30 *s = &base[slot];

    switch (s->unk26) {
    case 0:
        s->unk28 = 0;
        s->unk2A = 0;
        s->unk20 = gUnk_030057E0.unkC94[1];
        sub_080493D4(slot, sub_080502B4(slot, gUnk_030057E0.unkC94[1]));
        s->unk34 = s->unk10_8;
        sub_08047BA8(0x70);
        s->unk26++;
        break;
    case 1:
        if (s->unk28 < 16 / sprite_walk_speed(slot) * 2) {
            switch (s->unk20) {
            case 0:
                s->unk34 -= sprite_walk_speed(slot);
                break;
            case 1:
                s->unk34 += sprite_walk_speed(slot);
                break;
            case 2:
                s->unkC_8 -= sprite_walk_speed(slot);
                break;
            case 3:
                s->unkC_8 += sprite_walk_speed(slot);
                break;
            }
            gUnk_03002C30[slot].unk10_8 =
                gUnk_03002C30[slot].unk34 -
                gUnk_083D69A0[0][gUnk_03002C30[slot].unk28 * (sprite_walk_speed(slot) << 2)] / 16;
            gUnk_03002C30[slot].unk2C =
                gUnk_083D69A0[0][gUnk_03002C30[slot].unk28 * (sprite_walk_speed(slot) << 2)] / 16;
            gUnk_03002C30[slot].unk28++;
            if (gUnk_03002C30[slot].unkB != 0xFF) {
                if (gUnk_03002C30[slot].unk10_8 / 4 <= (gUnk_03002C30[slot].unk34 - 16) / 4)
                    gUnk_03002C30[slot].unkB = 0xFE;
                else
                    sprite_set_blend_from_kind(slot);
            }
        } else {
            sprite_set_blend_from_kind(slot);
            s->unk10_8 = s->unk34;
            s->unk2C = 0;
            ret = 1;
        }
        break;
    }
    return ret;
}

// Clears gNewKeys, gRepeatKeys and gHeldKeys (called every frame by sub_0804E0E8 during scripted scenes).
void sub_08050B50(void) {
    memzero_bytes((u8 *)&gNewKeys, 4);
    memzero_bytes((u8 *)&gRepeatKeys, 4);
    memzero_bytes((u8 *)&gHeldKeys, 4);
}
