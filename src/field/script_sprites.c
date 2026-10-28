// Map script sprites: the sprite slots a script controls (spawn_script_sprite, init_script_sprite), their
// step-by-step movement and animation, the snapshot kept while the field menu is open
// (save_script_sprites / restore_script_sprites), and map_script_command_done. Talks to the engine
// sprite code and field/map_script.
#include "global.h"
#include "constants/sprites.h"

static void init_script_sprite(u8 idx, u8 part, u8 x, u8 y);

// Starts a scripted walk: code low nibble = steps, high nibble = direction (also the walk animation).
void script_sprite_begin_walk(u8 slot, u8 code, u8 speed_id) {
    struct SpriteEntry *base = gSpriteEntries;
    struct SpriteEntry *spr = &base[slot];

    spr->unk27 = code & 0xF;
    code = (code & 0xF0) >> 4;
    set_sprite_animation_state(slot, code);
    spr->unk2A = speed_id;
    spr->unk28 = 16 / sprite_walk_speed(slot);
    sprite_anim_start(slot, sprite_walk_anim_id(slot, code));
}

// Same, but the facing / animation stay as they are (the sprite slides).
void script_sprite_begin_slide(u8 slot, u8 code, u8 speed_id) {
    struct SpriteEntry *base = gSpriteEntries;
    struct SpriteEntry *spr = &base[slot];

    spr->unk27 = code & 0xF;
    spr->unk20 = (code & 0xF0) >> 4;
    spr->unk2A = speed_id;
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
            spr->pos_y -= sprite_walk_speed(slot);
            break;
        case 1:
            spr->pos_y += sprite_walk_speed(slot);
            break;
        case 2:
            spr->pos_x -= sprite_walk_speed(slot);
            break;
        case 3:
            spr->pos_x += sprite_walk_speed(slot);
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
    gFieldWork.cmd_step = 0;
    gFieldWork.cmd_busy = 0;
}

// Map script sprite codes: high nibble = graphics kind, low 2 bits = direction (4 directions x 3 frames).
u8 sprite_code_kind(u8 code) {
    return code >> 4;
}

static u8 sprite_code_direction(u8 code) {
    return code & 3;
}

u8 sprite_code_anim_index(u8 code) {
    return sprite_code_kind(code) * 12 + sprite_code_direction(code) * 3;
}

u8 sprite_walk_anim_id(u8 slot, u8 direction) {
    return direction + gSpriteEntries[slot].unk2B * 4;
}

static u8 script_object_anim_index(u8 id, u8 direction) {
    return gSpriteEntries[script_object_slot(id) + 79].unk2B * 12 + direction * 3;
}

// Map script opcodes: sprite slot flags & 0xF (+0x4F), graphics id, tile x / y; bit 0x40 = 5 px lower.
void spawn_script_sprite(u8 flags, u8 part, u8 x, u8 y) {
    u32 idx = flags & 0xF;

    if ((flags & 0xF0) && find_map_event_by_coords(x, y) && gFieldSceneParams.warp_sound)
        field_play_sound_effect(gWarpSoundEffects[gFieldSceneParams.warp_sound]);
    script_object_set_slot(idx, find_free_script_sprite_slot());
    init_script_sprite(script_object_slot(idx), part, x, y);
    if (flags & 0x40)
        gSpriteEntries[script_object_slot(idx) + 0x4F].pos_y += 5;
}

// Sets up script sprite idx + 0x4F at tile (x, y), plus an overlay sprite at idx + 0x79 on some tiles.
static void init_script_sprite(u8 idx, u8 part, u8 x, u8 y) {
    u32 slot = idx + 0x4F;
    struct SpriteEntry *spr;
    u32 tile;
    u8 anim;

    sprite_entry_clear(slot);
    sprite_entry_init(slot, SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(2) | SPRITE_FLAG_PART_PALETTE,
                      sprite_code_anim_index(part), sprite_code_kind(part), 1);
    anim = sprite_code_kind(part);
    spr = &gSpriteEntries[slot];
    spr->unk2B = anim;
    spr->unk20 = sprite_code_direction(part);
    spr->pos_x = x * 16 + gFieldWork.map_origin_x;
    spr->pos_y = y * 16 + gFieldWork.map_origin_y;
    gEntityStates[slot].active = 0xFFFF;
    spr->unk2C = 0;
    tile = area_sprite_sheet_id(spr->unk2B);
    spr->unk30 = tile;
    sprite_set_blend_from_kind(slot);
    if (gSpriteSheetHasShadow[tile]) {
        sprite_entry_init(idx + 0x79,
                          SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(3) | SPRITE_OBJ_MODE(1) |
                              SPRITE_FLAG_PART_PALETTE,
                          0x90, 0xE, 1);
        gSpriteEntries[idx + 0x79].pos_x = spr->pos_x;
        gSpriteEntries[idx + 0x79].pos_y = spr->pos_y - 5;
    }
}

// Removes script object (code & 0xF) and its overlay; if code & 0xF0, plays the area sound when it stands on an
// event tile (as spawn_script_sprite does).
void despawn_script_sprite(u8 code) {
    u32 id = code & 0xF;

    if (code & 0xF0) {
        u8 x = field_pixel_x_to_tile(gSpriteEntries[script_object_slot(id) + 79].pos_x);
        u8 y = field_pixel_y_to_tile(gSpriteEntries[script_object_slot(id) + 79].pos_y);

        if (find_map_event_by_coords(x, y) && gFieldSceneParams.warp_sound)
            field_play_sound_effect(gWarpSoundEffects[gFieldSceneParams.warp_sound]);
    }
    sprite_entry_clear(script_object_slot(id) + 79);
    sprite_entry_clear(script_object_slot(id) + 121);
    script_object_free_slot(id);
}

// Snapshot of the 6 script sprites into gFieldWork.sprite_snapshot (runtime: opening the field menu).
void save_script_sprites(void) {
    s32 i;

    memzero_bytes((u8 *)gFieldWork.sprite_snapshot, sizeof(gFieldWork.sprite_snapshot));
    for (i = 0; i <= 5; i++) {
        if (gEntityStates[i + 79].active) {
            gFieldWork.sprite_snapshot[i].x = field_pixel_x_to_tile(gSpriteEntries[i + 79].pos_x);
            gFieldWork.sprite_snapshot[i].y = field_pixel_y_to_tile(gSpriteEntries[i + 79].pos_y);
            gFieldWork.sprite_snapshot[i].anim =
                ((gSpriteEntries[i + 79].unk2B & 0xF) << 4) | (gSpriteEntries[i + 79].unk20 & 3);
            gFieldWork.sprite_snapshot[i].id = i;
            gFieldWork.sprite_snapshot[i].blink_hidden = gSpriteEntries[i + 79].unk2D;
            gFieldWork.sprite_snapshot[i].active = 1;
        }
    }
}

// Re-creates the script sprites from that snapshot (runtime: returning from the field menu).
void restore_script_sprites(void) {
    s32 i;

    for (i = 0; i <= 5; i++) {
        if (gFieldWork.sprite_snapshot[i].active && !gFieldWork.sprite_snapshot[i].blink_hidden)
            init_script_sprite(i, gFieldWork.sprite_snapshot[i].anim, gFieldWork.sprite_snapshot[i].x,
                               gFieldWork.sprite_snapshot[i].y);
    }
}

// First of the 6 script sprite slots (79-84) that is neither active nor hidden; 5 when all are taken.
u32 find_free_script_sprite_slot(void) {
    s32 i;
    for (i = 0; i < 6; i++) {
        if (!(gSpriteEntries[i + 79].flags & SPRITE_FLAG_VISIBLE) && !gSpriteEntries[i + 79].unk2E)
            break;
    }
    if (i == 6)
        return 5;
    return i;
}

void script_object_set_direction(u8 id, u8 state) {
    gSpriteEntries[script_object_slot(id) + 79].unk20 = state;
    gSpriteEntries[script_object_slot(id) + 79].frame = script_object_anim_index(id, state);
}

void sprite_set_blend(u32 idx, u8 val) {
    gSpriteEntries[idx].order = val;
}

void script_object_set_blend(u8 i, u32 val) {
    gSpriteEntries[script_object_slot(i) + 79].order = val;
}

// OAM priority (bits 10-11) of a sprite entry.
void sprite_set_priority(u32 idx, u32 val) {
    u32 flags = (gSpriteEntries[idx].unk32 & 0xF3FF) | (val << 10);
    gSpriteEntries[idx].flags = flags;
    gSpriteEntries[idx].unk32 = flags;
}

void script_object_set_priority(u8 i, u8 val) {
    sprite_set_priority(script_object_slot(i) + 79, val);
}

// Blinks the sprite for gScriptCmdWork.counter frames, toggling every timer_reload frames; returns 1 when done.
u32 script_sprite_blink_step(u8 slot) {
    u32 ret = 0;

    if (gScriptCmdWork.counter) {
        if (gScriptCmdWork.timer)
            gScriptCmdWork.timer--;
        else {
            gScriptCmdWork.blink_phase++;
            gScriptCmdWork.timer = gScriptCmdWork.timer_reload;
        }
        if (gScriptCmdWork.blink_phase & 1) {
            gSpriteEntries[slot].unk2D = 1;
            gSpriteEntries[slot].flags = 0;
        } else {
            gSpriteEntries[slot].unk2D = 0;
            gSpriteEntries[slot].flags = gSpriteEntries[slot].unk32;
        }
        gScriptCmdWork.counter--;
    } else {
        gSpriteEntries[slot].unk2D = 0;
        gSpriteEntries[slot].flags = gSpriteEntries[slot].unk32;
        ret = 1;
    }
    return ret;
}

// Plays the walk animation of sprite gScriptCmdWork.sprite_slot in place for timer frames; returns 1 when done.
u32 script_sprite_anim_step(void) {
    u32 ret = 0;

    switch (gScriptCmdWork.counter) {
    case 0:
        sprite_anim_start(
            gScriptCmdWork.sprite_slot,
            sprite_walk_anim_id(gScriptCmdWork.sprite_slot, gSpriteEntries[gScriptCmdWork.sprite_slot].unk20));
        gScriptCmdWork.counter++;
        break;
    case 1:
        if (gScriptCmdWork.timer) {
            advance_sprite_animation_frame(gScriptCmdWork.sprite_slot);
            gScriptCmdWork.timer--;
        } else
            ret = 1;
        break;
    }
    return ret;
}

// Hops sprite gScriptCmdWork.sprite_slot in place along gJumpArcTable (16 frames); returns 1 when landed.
u32 script_sprite_hop_step(void) {
    u32 ret = 0;

    if (gSpriteEntries[gScriptCmdWork.sprite_slot].unk28 < 16) {
        gSpriteEntries[gScriptCmdWork.sprite_slot].pos_y =
            gScriptCmdWork.hop_base_y - gJumpArcTable[gSpriteEntries[gScriptCmdWork.sprite_slot].unk28][0] / 16;
        gSpriteEntries[gScriptCmdWork.sprite_slot].unk2C =
            gJumpArcTable[gSpriteEntries[gScriptCmdWork.sprite_slot].unk28][0] / 16;
        gSpriteEntries[gScriptCmdWork.sprite_slot].unk28++;
        if (gSpriteEntries[gScriptCmdWork.sprite_slot].pos_y / 4 <= (gScriptCmdWork.hop_base_y - 16) / 4)
            gSpriteEntries[gScriptCmdWork.sprite_slot].order = 0xFF;
        else
            sprite_set_blend_from_kind(gScriptCmdWork.sprite_slot);
    } else {
        sprite_set_blend_from_kind(gScriptCmdWork.sprite_slot);
        gSpriteEntries[gScriptCmdWork.sprite_slot].pos_y = gScriptCmdWork.hop_base_y;
        gSpriteEntries[gScriptCmdWork.sprite_slot].unk2C = 0;
        ret = 1;
    }
    return ret;
}

// Jumps sprite gScriptCmdWork.sprite_slot two tiles in the script's direction (jump sound 0x70); returns 1 when landed.
u32 script_sprite_jump_step(void) {
    u32 ret = 0;
    u8 slot = gScriptCmdWork.sprite_slot;
    struct SpriteEntry *base = gSpriteEntries;
    struct SpriteEntry *spr = &base[slot];

    switch (spr->unk26) {
    case 0:
        spr->unk28 = 0;
        spr->unk2A = 0;
        spr->unk20 = gFieldWork.cmd_args[1];
        sprite_anim_start(slot, sprite_walk_anim_id(slot, gFieldWork.cmd_args[1]));
        spr->unk34 = spr->pos_y;
        field_play_sound_effect(0x70);
        spr->unk26++;
        break;
    case 1:
        if (spr->unk28 < 16 / sprite_walk_speed(slot) * 2) {
            switch (spr->unk20) {
            case 0:
                spr->unk34 -= sprite_walk_speed(slot);
                break;
            case 1:
                spr->unk34 += sprite_walk_speed(slot);
                break;
            case 2:
                spr->pos_x -= sprite_walk_speed(slot);
                break;
            case 3:
                spr->pos_x += sprite_walk_speed(slot);
                break;
            }
            gSpriteEntries[slot].pos_y =
                gSpriteEntries[slot].unk34 -
                gJumpArcTable[0][gSpriteEntries[slot].unk28 * (sprite_walk_speed(slot) << 2)] / 16;
            gSpriteEntries[slot].unk2C =
                gJumpArcTable[0][gSpriteEntries[slot].unk28 * (sprite_walk_speed(slot) << 2)] / 16;
            gSpriteEntries[slot].unk28++;
            if (gSpriteEntries[slot].order != 0xFF) {
                if (gSpriteEntries[slot].pos_y / 4 <= (gSpriteEntries[slot].unk34 - 16) / 4)
                    gSpriteEntries[slot].order = 0xFE;
                else
                    sprite_set_blend_from_kind(slot);
            }
        } else {
            sprite_set_blend_from_kind(slot);
            spr->pos_y = spr->unk34;
            spr->unk2C = 0;
            ret = 1;
        }
        break;
    }
    return ret;
}

// Clears gNewKeys, gRepeatKeys and gHeldKeys (called every frame by map_script_update_player_walk during scripted
// scenes).
void clear_input_keys(void) {
    memzero_bytes((u8 *)&gNewKeys, 4);
    memzero_bytes((u8 *)&gRepeatKeys, 4);
    memzero_bytes((u8 *)&gHeldKeys, 4);
}
