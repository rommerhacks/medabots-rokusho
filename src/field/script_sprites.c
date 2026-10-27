// Map script sprites: the sprite slots a script controls (spawn_script_sprite, init_script_sprite), their
// step-by-step movement and animation, the snapshot kept while the field menu is open
// (save_script_sprites / restore_script_sprites), and map_script_command_done. Talks to the engine
// sprite code and field/map_script.
#include "global.h"

static void init_script_sprite(u8 idx, u8 part, u8 x, u8 y);

// Starts a scripted walk: code low nibble = steps, high nibble = direction (also the walk animation).
void script_sprite_begin_walk(u8 slot, u8 a, u8 b) {
    struct SpriteEntry *base = gSpriteEntries;
    struct SpriteEntry *spr = &base[slot];

    spr->unk27 = a & 0xF;
    a = (a & 0xF0) >> 4;
    set_sprite_animation_state(slot, a);
    spr->unk2A = b;
    spr->unk28 = 16 / sprite_walk_speed(slot);
    sprite_anim_start(slot, sprite_walk_anim_id(slot, a));
}

// Same, but the facing / animation stay as they are (the sprite slides).
void script_sprite_begin_slide(u8 slot, u8 a, u8 b) {
    struct SpriteEntry *base = gSpriteEntries;
    struct SpriteEntry *spr = &base[slot];

    spr->unk27 = a & 0xF;
    spr->unk20 = (a & 0xF0) >> 4;
    spr->unk2A = b;
    spr->unk28 = 16 / sprite_walk_speed(slot);
}

void script_sprite_advance_anim_by_speed(u8 slot) {
    s32 i;

    for (i = 0; i < sprite_walk_speed(slot); i++)
        advance_sprite_animation_frame(slot);
}

// One frame of that walk; returns 1 after the last step. Some sheets (0x71, 0x78, 0x82-0x84) thud each step.
u32 script_sprite_update_walk(u8 slot, u8 mode) {
    u32 done = 0;
    struct SpriteEntry *base = gSpriteEntries;
    struct SpriteEntry *spr = &base[slot];

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
            script_sprite_advance_anim_by_speed(slot);
        if (--gSpriteEntries[slot].unk28 == 0) {
            switch (gSpriteEntries[slot].unk30) {
            case 0x71:
            case 0x78:
            case 0x82:
            case 0x83:
            case 0x84:
                field_play_sound_effect(0x57);
                break;
            }
            gSpriteEntries[slot].unk28 = 16 / sprite_walk_speed(slot);
            if (--gSpriteEntries[slot].unk27 == 0)
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

// Map script sprite codes: high nibble = graphics kind, low 2 bits = direction (4 directions x 3 frames).
u8 sprite_code_kind(u8 a) {
    return a >> 4;
}

static u8 sprite_code_direction(u8 a) {
    return a & 3;
}

u8 sprite_code_anim_index(u8 a) {
    return sprite_code_kind(a) * 12 + sprite_code_direction(a) * 3;
}

u8 sprite_walk_anim_id(u8 slot, u8 v) {
    return v + gSpriteEntries[slot].unk2B * 4;
}

static u8 script_object_anim_index(u8 id, u8 a) {
    return gSpriteEntries[script_object_slot(id) + 79].unk2B * 12 + a * 3;
}

// Map script opcodes: sprite slot flags & 0xF (+0x4F), graphics id, tile x / y; bit 0x40 = 5 px lower.
void spawn_script_sprite(u8 flags, u8 part, u8 x, u8 y) {
    u32 idx = flags & 0xF;

    if ((flags & 0xF0) && find_map_event_by_coords(x, y) && gUnk_03006D38.unk3)
        field_play_sound_effect(gUnk_083D29E6[gUnk_03006D38.unk3]);
    script_object_set_slot(idx, find_free_script_sprite_slot());
    init_script_sprite(script_object_slot(idx), part, x, y);
    if (flags & 0x40)
        gSpriteEntries[script_object_slot(idx) + 0x4F].unk10_8 += 5;
}

// Sets up script sprite idx + 0x4F at tile (x, y), plus an overlay sprite at idx + 0x79 on some tiles.
static void init_script_sprite(u8 idx, u8 part, u8 x, u8 y) {
    u32 slot = idx + 0x4F;
    struct SpriteEntry *spr;
    u32 tile;
    u8 anim;

    sprite_entry_clear(slot);
    sprite_entry_init(slot, 0xC804, sprite_code_anim_index(part), sprite_code_kind(part), 1);
    anim = sprite_code_kind(part);
    spr = &gSpriteEntries[slot];
    spr->unk2B = anim;
    spr->unk20 = sprite_code_direction(part);
    spr->unkC_8 = x * 16 + gUnk_030057E0.map_origin_x;
    spr->unk10_8 = y * 16 + gUnk_030057E0.map_origin_y;
    gUnk_030055A0[slot].unk0 = 0xFFFF;
    spr->unk2C = 0;
    tile = area_sprite_sheet_id(spr->unk2B);
    spr->unk30 = tile;
    sprite_set_blend_from_kind(slot);
    if (gUnk_083D2B8D[tile]) {
        sprite_entry_init(idx + 0x79, 0xCC0C, 0x90, 0xE, 1);
        gSpriteEntries[idx + 0x79].unkC_8 = spr->unkC_8;
        gSpriteEntries[idx + 0x79].unk10_8 = spr->unk10_8 - 5;
    }
}

// Removes script object (arg & 0xF) and its overlay; if arg & 0xF0, plays the area sound when it stands on an
// event tile (as spawn_script_sprite does).
void despawn_script_sprite(u8 arg) {
    u32 id = arg & 0xF;

    if (arg & 0xF0) {
        u8 x = field_pixel_x_to_tile(gSpriteEntries[script_object_slot(id) + 79].unkC_8);
        u8 y = field_pixel_y_to_tile(gSpriteEntries[script_object_slot(id) + 79].unk10_8);

        if (find_map_event_by_coords(x, y) && gUnk_03006D38.unk3)
            field_play_sound_effect(gUnk_083D29E6[gUnk_03006D38.unk3]);
    }
    sprite_entry_clear(script_object_slot(id) + 79);
    sprite_entry_clear(script_object_slot(id) + 121);
    script_object_free_slot(id);
}

// Snapshot of the 6 script sprites into gUnk_030057E0.unk7DC (runtime: opening the field menu).
void save_script_sprites(void) {
    s32 i;

    memzero_bytes((u8 *)gUnk_030057E0.unk7DC, sizeof(gUnk_030057E0.unk7DC));
    for (i = 0; i <= 5; i++) {
        if (gUnk_030055A0[i + 79].unk0) {
            gUnk_030057E0.unk7DC[i].x = field_pixel_x_to_tile(gSpriteEntries[i + 79].unkC_8);
            gUnk_030057E0.unk7DC[i].y = field_pixel_y_to_tile(gSpriteEntries[i + 79].unk10_8);
            gUnk_030057E0.unk7DC[i].anim =
                ((gSpriteEntries[i + 79].unk2B & 0xF) << 4) | (gSpriteEntries[i + 79].unk20 & 3);
            gUnk_030057E0.unk7DC[i].id = i;
            gUnk_030057E0.unk7DC[i].unk2_6 = gSpriteEntries[i + 79].unk2D;
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

// First of the 6 script sprite slots (79-84) that is neither active nor hidden; 5 when all are taken.
u32 find_free_script_sprite_slot(void) {
    s32 i;
    for (i = 0; i < 6; i++) {
        if (!(gSpriteEntries[i + 79].unk0 & 0x4000) && !gSpriteEntries[i + 79].unk2E)
            break;
    }
    if (i == 6)
        return 5;
    return i;
}

void script_object_set_direction(u8 id, u8 state) {
    gSpriteEntries[script_object_slot(id) + 79].unk20 = state;
    gSpriteEntries[script_object_slot(id) + 79].unk6 = script_object_anim_index(id, state);
}

void sprite_set_blend(u32 idx, u8 val) {
    gSpriteEntries[idx].unkB = val;
}

void script_object_set_blend(u8 i, u32 val) {
    gSpriteEntries[script_object_slot(i) + 79].unkB = val;
}

// OAM priority (bits 10-11) of a sprite entry.
void sprite_set_priority(u32 idx, u32 val) {
    u32 v = (gSpriteEntries[idx].unk32 & 0xF3FF) | (val << 10);
    gSpriteEntries[idx].unk0 = v;
    gSpriteEntries[idx].unk32 = v;
}

void script_object_set_priority(u8 i, u8 val) {
    sprite_set_priority(script_object_slot(i) + 79, val);
}

// Blinks the sprite for gUnk_03006D20.unk0 frames, toggling every unk3 frames; returns 1 when done.
u32 script_sprite_blink_step(u8 slot) {
    u32 ret = 0;

    if (gUnk_03006D20.unk0) {
        if (gUnk_03006D20.unk2)
            gUnk_03006D20.unk2--;
        else {
            gUnk_03006D20.unk1++;
            gUnk_03006D20.unk2 = gUnk_03006D20.unk3;
        }
        if (gUnk_03006D20.unk1 & 1) {
            gSpriteEntries[slot].unk2D = 1;
            gSpriteEntries[slot].unk0 = 0;
        } else {
            gSpriteEntries[slot].unk2D = 0;
            gSpriteEntries[slot].unk0 = gSpriteEntries[slot].unk32;
        }
        gUnk_03006D20.unk0--;
    } else {
        gSpriteEntries[slot].unk2D = 0;
        gSpriteEntries[slot].unk0 = gSpriteEntries[slot].unk32;
        ret = 1;
    }
    return ret;
}

// Plays the walk animation of sprite gUnk_03006D20.unkA in place for unk2 frames; returns 1 when done.
u32 script_sprite_anim_step(void) {
    u32 ret = 0;

    switch (gUnk_03006D20.unk0) {
    case 0:
        sprite_anim_start(gUnk_03006D20.unkA,
                          sprite_walk_anim_id(gUnk_03006D20.unkA, gSpriteEntries[gUnk_03006D20.unkA].unk20));
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

// Hops sprite gUnk_03006D20.unkA in place along gJumpArcTable (16 frames); returns 1 when landed.
u32 script_sprite_hop_step(void) {
    u32 ret = 0;

    if (gSpriteEntries[gUnk_03006D20.unkA].unk28 < 16) {
        gSpriteEntries[gUnk_03006D20.unkA].unk10_8 =
            gUnk_03006D20.unk8 - gJumpArcTable[gSpriteEntries[gUnk_03006D20.unkA].unk28][0] / 16;
        gSpriteEntries[gUnk_03006D20.unkA].unk2C = gJumpArcTable[gSpriteEntries[gUnk_03006D20.unkA].unk28][0] / 16;
        gSpriteEntries[gUnk_03006D20.unkA].unk28++;
        if (gSpriteEntries[gUnk_03006D20.unkA].unk10_8 / 4 <= (gUnk_03006D20.unk8 - 16) / 4)
            gSpriteEntries[gUnk_03006D20.unkA].unkB = 0xFF;
        else
            sprite_set_blend_from_kind(gUnk_03006D20.unkA);
    } else {
        sprite_set_blend_from_kind(gUnk_03006D20.unkA);
        gSpriteEntries[gUnk_03006D20.unkA].unk10_8 = gUnk_03006D20.unk8;
        gSpriteEntries[gUnk_03006D20.unkA].unk2C = 0;
        ret = 1;
    }
    return ret;
}

// Jumps sprite gUnk_03006D20.unkA two tiles in the script's direction (jump sound 0x70); returns 1 when landed.
u32 script_sprite_jump_step(void) {
    u32 ret = 0;
    u8 slot = gUnk_03006D20.unkA;
    struct SpriteEntry *base = gSpriteEntries;
    struct SpriteEntry *s = &base[slot];

    switch (s->unk26) {
    case 0:
        s->unk28 = 0;
        s->unk2A = 0;
        s->unk20 = gUnk_030057E0.unkC94[1];
        sprite_anim_start(slot, sprite_walk_anim_id(slot, gUnk_030057E0.unkC94[1]));
        s->unk34 = s->unk10_8;
        field_play_sound_effect(0x70);
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
            gSpriteEntries[slot].unk10_8 =
                gSpriteEntries[slot].unk34 -
                gJumpArcTable[0][gSpriteEntries[slot].unk28 * (sprite_walk_speed(slot) << 2)] / 16;
            gSpriteEntries[slot].unk2C =
                gJumpArcTable[0][gSpriteEntries[slot].unk28 * (sprite_walk_speed(slot) << 2)] / 16;
            gSpriteEntries[slot].unk28++;
            if (gSpriteEntries[slot].unkB != 0xFF) {
                if (gSpriteEntries[slot].unk10_8 / 4 <= (gSpriteEntries[slot].unk34 - 16) / 4)
                    gSpriteEntries[slot].unkB = 0xFE;
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
void clear_input_keys(void) {
    memzero_bytes((u8 *)&gNewKeys, 4);
    memzero_bytes((u8 *)&gRepeatKeys, 4);
    memzero_bytes((u8 *)&gHeldKeys, 4);
}
