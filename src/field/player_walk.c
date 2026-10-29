// Field player: load_map_npc_sprites puts the area's NPC sprites up, field_player_walk_input and
// field_player_step move the player tile by tile, plus the follower sprite that walks one tile
// behind the player. Called from the field frame handler (field/field_walk) and the field sub-states
// (field/field_update); uses field/map_objects for collision, events and exits.
#include "global.h"
#include "constants/field_sprites.h"
#include "constants/sprites.h"

static void follower_step(u8 dir);

void load_map_npc_sprites(s32 mode) {
    struct MapObject saved[64];
    s32 n;
    s32 j;
    s32 k;
    s32 count;
    s32 found;
    struct MapObject *obj;
    u32 anim;
    s32 skip;
    s32 i;
    const struct MapNpcRecord *rec;

    obj = gFieldWork.objects;
    memzero_bytes((u8 *)saved, sizeof(saved));
    memcpy_u8(obj, saved, sizeof(saved));
    memzero_bytes((u8 *)obj, sizeof(saved));
    count = 0;
    n = 0;
    j = 0;
    for (k = 0; k < 32; k++) {
        for (rec = gAreaNpcRecords[gFieldWork.area_id]; rec->x != 0xFF; rec++) {
            if (!((rec->phase_mask >> gFieldWork.story_phase) & 1))
                continue;
            if (rec->load_order != k)
                continue;
            if (event_flag_get(rec->event & 0xFFF))
                continue;
            skip = 0;
            found = 0;
            if (mode == 0) {
                skip = 0;
                goto place;
            }
            if (mode >= 0)
                if (mode <= 2) {
                    for (j = 0; j < 64; j++) {
                        if ((rec->event & 0xFFF) == (saved[j].event & 0xFFF))
                            found = 1;
                        if (found)
                            break;
                    }
                    if (j != 64) {
                        if (mode == 1) {
                            skip = 0;
                            goto place;
                        }
                        if (mode == 2) {
                            if (saved[j].present == 1)
                                goto chk;
                            goto next;
                        }
                    } else if (mode == 2)
                        skip = 1;
                }
        chk:
            if (skip)
                goto next;
        place:
            anim = rec->anim >> 4;
            gFieldWork.objects[n].x = rec->x;
            gFieldWork.objects[n].y = rec->y;
            gFieldWork.objects[n].event = rec->event;
            switch (rec->event >> 12) {
            case 0:
            case 4:
            case 6:
                gFieldWork.tile_map[rec->y * (gFieldWork.map_width >> 1) + rec->x] = 7;
                break;
            }
            gFieldWork.objects[n].present = 1;
            if (rec->anim == 0xFF)
                goto next;
            if (count < 30) {
                switch (rec->event >> 12) {
                case 0:
                case 2:
                case 4:
                case 6: {
                    u8 slot = count + 49;
                    u32 frame_base = anim * 12;
                    u8 sheet_anim = anim;
                    sprite_entry_init(
                        slot, SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(2) | SPRITE_FLAG_PART_PALETTE,
                        frame_base, sheet_anim, 1);
                    gFieldWork.objects[n].has_sprite = 1;
                    gSpriteEntries[count + 49].work16[FIELD_SPR_SHEET] = area_sprite_sheet_id(sheet_anim);
                    sprite_set_blend_from_kind(count + 49);
                    if (gSpriteSheetHasShadow[gSpriteEntries[count + 49].work16[FIELD_SPR_SHEET]])
                        sprite_entry_init(count + 91,
                                          SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(3) |
                                              SPRITE_OBJ_MODE(1) | SPRITE_FLAG_PART_PALETTE,
                                          0x90, 14, 1);
                } break;
                }
                gFieldWork.objects[n].sprite_slot = count;
                anim = rec->anim >> 4;
                gEntityStates[count + 49].active = rec->event & 0xFFF;
                gSpriteEntries[count + 49].work[FIELD_SPR_ANIM_SET] = anim;
                gSpriteEntries[count + 49].pos_x = rec->x * 16 + gFieldWork.map_origin_x;
                gSpriteEntries[count + 49].pos_y = rec->y * 16 + gFieldWork.map_origin_y;
                set_sprite_anim_and_store(count + 49, rec->anim & 0xF, &gFieldWork.objects[n]);
                sprite_anim_start(count + 49, anim * 4 + (rec->anim & 0xF));
                if (mode != 0 && found) {
                    set_sprite_anim_and_store(count + 49, saved[j].anim_state, &gFieldWork.objects[n]);
                    sprite_anim_start(count + 49, saved[j].anim_state + anim * 4);
                }
                gSpriteEntries[count + 49].work[FIELD_SPR_HEIGHT] = 0;
                gSpriteEntries[count + 91].pos_x = gSpriteEntries[count + 49].pos_x;
                gSpriteEntries[count + 91].pos_y = gSpriteEntries[count + 49].pos_y - 5;
                gSpriteEntries[count + 91].x = gSpriteEntries[count + 49].x;
                gSpriteEntries[count + 91].y = gSpriteEntries[count + 49].y - 5;
            }
            count++;
        next:
            n++;
        }
    }
    if (gFieldWork.script_id != 0) {
        for (i = 0; i < 64; obj++, i++) {
            if ((obj->event & 0xFFF) == gFieldWork.script_id) {
                gFieldWork.script_object = i;
                break;
            }
        }
    }
    gFieldWork.npc_load_mode = 2;
}

// guess: sets up the player sprite (47) and its shadow (89) on entering the field
void init_battle_field_setup(void) {
    gFieldWork.player_step_frames = 0;
    gFieldWork.loaded_form = gFieldWork.player_form;
    load_battle_terrain_data();
    gFieldWork.player_tile_x = field_pixel_x_to_tile(gFieldWork.player_x);
    gFieldWork.player_tile_y = field_pixel_y_to_tile(gFieldWork.player_y);
    sprite_entry_init(47, SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(2) | SPRITE_FLAG_PART_PALETTE, 3,
                      0, 1);
    field_set_player_facing(gFieldWork.player_facing);
    follower_turn_toward_player(3);
    gSpriteEntries[47].order = 0x40;
    LZ77UnCompVram(gShadowTilesLz, (void *)(OBJ_VRAM0 + 0x7FC0));
    sprite_entry_init(89,
                      SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(3) | SPRITE_OBJ_MODE(1) |
                          SPRITE_FLAG_PART_PALETTE,
                      0x90, 14, 1);
    gSpriteEntries[89].pos_x = gFieldWork.player_x;
    gSpriteEntries[89].pos_y = gFieldWork.player_y - 5;
    gSpriteEntries[89].x = gSpriteEntries[47].x;
    gSpriteEntries[89].y = gSpriteEntries[47].y - 5;
    if (gFieldWork.player_visible) {
        gSpriteEntries[47].flags =
            SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(2) | SPRITE_FLAG_PART_PALETTE;
    } else {
        gSpriteEntries[47].flags = 0;
        gSpriteEntries[89].flags = 0;
    }
}

// Pixels per frame for a walking sprite: its own speed factor times the area's (16 / speed = frames per tile).
s32 sprite_walk_speed(u8 idx) {
    return gWalkSpeedFactors[gSpriteEntries[idx].work[FIELD_SPR_SPEED]] *
           gWalkSpeedFactors[gFieldSceneParams.area_speed_id];
}

void set_battle_state_cancel_flag(void) {
    gFieldWork.player_move_dir = 0xFF;
    follower_clear_scroll_dir();
}

// One frame of a tile step (dir 0 up, 1 down, 2 left, 3 right): moves the player, scrolls the camera,
// and when the step ends (player_step_frames counts down) checks NPC events, map events and random encounters.
void field_player_step(u8 dir) {
    switch (dir) {
    case 0:
        if (gFieldWork.player_y - gFieldWork.map_origin_y != 0) {
            gFieldWork.player_y -= sprite_walk_speed(47);
            script_sprite_advance_anim_by_speed(47);
            if (!field_map_origin_y() &&
                gFieldWork.player_y - gFieldWork.map_origin_y < gFieldWork.map_height * 8 - 0x60 && gBg1Scroll.y != 0)
                field_scroll_bg_y(-sprite_walk_speed(47));
        }
        break;
    case 1:
        if (gFieldWork.player_y - gFieldWork.map_origin_y + 16 < gFieldWork.map_height * 8) {
            gFieldWork.player_y += sprite_walk_speed(47);
            script_sprite_advance_anim_by_speed(47);
            if (!field_map_origin_y() && gFieldWork.player_y - gFieldWork.map_origin_y + 16 > 0x50 &&
                gBg1Scroll.y + 0xA0 < gFieldWork.map_height * 8)
                field_scroll_bg_y(sprite_walk_speed(47));
        }
        break;
    case 2:
        if (gFieldWork.player_x - gFieldWork.map_origin_x != 0) {
            gFieldWork.player_x -= sprite_walk_speed(47);
            script_sprite_advance_anim_by_speed(47);
            if (!field_map_origin_x() &&
                gFieldWork.player_x - gFieldWork.map_origin_x < gFieldWork.map_width * 8 - 0x80 && gBg1Scroll.x != 0)
                field_scroll_bg_x(-sprite_walk_speed(47));
        }
        break;
    case 3:
        if (gFieldWork.player_x - gFieldWork.map_origin_x + 16 < gFieldWork.map_width * 8) {
            gFieldWork.player_x += sprite_walk_speed(47);
            script_sprite_advance_anim_by_speed(47);
            if (!field_map_origin_x() && gFieldWork.player_x - gFieldWork.map_origin_x + 16 > 0x80 &&
                gBg1Scroll.x + 0xF0 < gFieldWork.map_width * 8)
                field_scroll_bg_x(sprite_walk_speed(47));
        }
        break;
    }
    if (--gFieldWork.player_step_frames == 0) {
        gSpriteEntries[47].work[FIELD_SPR_SPEED] = gPlayerFormSpeedIds[gFieldWork.player_form];
        gFieldWork.player_tile_x = field_pixel_x_to_tile(gFieldWork.player_x);
        gFieldWork.player_tile_y = field_pixel_y_to_tile(gFieldWork.player_y);
        if (gFieldWork.script_running == 0 && !find_npc_event_match()) {
            if (find_map_event_by_coords(gFieldWork.player_tile_x, gFieldWork.player_tile_y)) {
                gFieldState.step = 3;
                if (gFieldSceneParams.warp_sound)
                    field_play_sound_effect(gWarpSoundEffects[gFieldSceneParams.warp_sound]);
                setup_palette_fade_to_color_with_obj(0x7FFF, 0.0f, 32.0f, 8.0f);
            } else if (gFieldWork.player_form != 1 && check_random_encounter()) {
                save_script_sprites();
                switch_game_mode(0x21, 0);
            }
        }
    }
}

// Area 0x53 only: tiles that reverse or rotate the D-pad.
static u8 area53_remap_dpad(u8 dir) {
    u32 tile = gArea53DpadTiles[gFieldWork.player_tile_y * (gFieldWork.map_width >> 1) + gFieldWork.player_tile_x] - 1;

    if (tile <= 3)
        dir = gDpadRemaps[tile][dir];
    return dir;
}

struct HeldKeyBits {
    u32 a : 1;
    u32 b : 1;
    u32 select : 1;
    u32 start : 1;
    u32 right : 1;
    u32 left : 1;
    u32 up : 1;
    u32 down : 1;
    u32 rest : 24;
};

#define gHeldKeyBits (*(struct HeldKeyBits *)&gHeldKeys)

void field_player_walk_input(void) {
    u8 dir = 0;
    u8 input;
    int zero = 0;
    u16 any;

    if (gFieldWork.player_step_frames == 0) {
        any = gHeldKeyBits.down | gHeldKeyBits.up | gHeldKeyBits.left | gHeldKeyBits.right;
        if (any) {
            input = (gHeldKeyBits.down << 3) | (gHeldKeyBits.up << 2) | (gHeldKeyBits.left << 1) | gHeldKeyBits.right;
            if (gFieldWork.script_running == 0 && gFieldWork.area_id == 0x53)
                input = area53_remap_dpad(input);
            switch (input) {
            case 4:
                dir = zero;
                break;
            case 8:
                dir = 1;
                break;
            case 1:
            case 5:
            case 9:
                dir = 3;
                break;
            case 2:
            case 6:
            case 10:
                dir = 2;
                break;
            }
            if (gFieldWork.player_move_dir != dir) {
                gFieldWork.player_move_dir = dir;
                field_set_player_facing(dir);
                sprite_anim_start(0x2F, dir);
                follower_turn_toward_player(3);
            }
            if (!field_player_at_map_edge(dir) && !check_tile_and_trigger_battle_action(dir)) {
                gFieldWork.player_step_frames = 16 / sprite_walk_speed(0x2F);
                field_player_step(gFieldWork.player_move_dir);
                follower_turn_toward_player(3);
                if (gFieldWork.player_form == 2 || gFieldWork.player_form == 9)
                    field_play_sound_effect(0x57);
                follower_step(gFieldWork.follower_move_dir);
            }
        }
    } else {
        field_player_step(gFieldWork.player_move_dir);
        follower_step(gFieldWork.follower_move_dir);
    }
}

void load_battle_palette_via_dma(u32 toBuffer) {
    area_load_sprite_sheets();
    if (toBuffer == 0)
        DmaCopy32(3, gFieldSpritePalettes[gPlayerFormSpriteSheets[gFieldWork.player_form]], OBJ_PLTT,
                  32) else DmaCopy32(3, gFieldSpritePalettes[gPlayerFormSpriteSheets[gFieldWork.player_form]],
                                     OBJ_PAL_BACKUP_ADDR(0), 32) gFieldWork.loaded_form = gFieldWork.player_form;
    load_battle_terrain_data();
}

// Clears the follower's pending step direction.
void follower_clear_scroll_dir(void) {
    if (gFieldWork.follower_active)
        gFieldWork.follower_move_dir = 0xFF;
}

// Turns the follower (sprite 48, shadow 90) toward the player's tile and, with flags bit 1, starts its next step
// there.
void follower_turn_toward_player(u8 flags) {
    u8 prev = gFieldWork.follower_move_dir;

    if (gFieldWork.follower_tile_y == gFieldWork.player_tile_y) {
        if (gFieldWork.follower_tile_x == gFieldWork.player_tile_x) {
            gFieldWork.follower_step_frames = 0;
        } else {
            if (flags & 2)
                gFieldWork.follower_step_frames = 16 / sprite_walk_speed(48);
            if (gFieldWork.follower_tile_x < gFieldWork.player_tile_x)
                gFieldWork.follower_move_dir = 3;
            else
                gFieldWork.follower_move_dir = 2;
            if (gFieldWork.follower_move_dir != prev) {
                follower_set_facing(gFieldWork.follower_move_dir);
                sprite_anim_start(48, sprite_walk_anim_id(48, gFieldWork.follower_move_dir));
            }
        }
    } else {
        if (flags & 2)
            gFieldWork.follower_step_frames = 16 / sprite_walk_speed(48);
        if (gFieldWork.follower_tile_y < gFieldWork.player_tile_y)
            gFieldWork.follower_move_dir = 1;
        else
            gFieldWork.follower_move_dir = 0;
        if (gFieldWork.follower_move_dir != prev) {
            follower_set_facing(gFieldWork.follower_move_dir);
            sprite_anim_start(48, sprite_walk_anim_id(48, gFieldWork.follower_move_dir));
        }
    }
    gSpriteEntries[48].work[FIELD_SPR_SPEED] = gSpriteEntries[47].work[FIELD_SPR_SPEED];
}

// One frame of the follower's step in dir (see follower_turn_toward_player).
static void follower_step(u8 dir) {
    if (gFieldWork.follower_active && gFieldWork.follower_step_frames) {
        switch (dir) {
        case 0:
            if (gFieldWork.follower_y - gFieldWork.map_origin_y != 0) {
                gFieldWork.follower_y -= sprite_walk_speed(48);
                script_sprite_advance_anim_by_speed(48);
            }
            break;
        case 1:
            if (gFieldWork.follower_y - gFieldWork.map_origin_y + 16 < gFieldWork.map_height * 8) {
                gFieldWork.follower_y += sprite_walk_speed(48);
                script_sprite_advance_anim_by_speed(48);
            }
            break;
        case 2:
            if (gFieldWork.follower_x - gFieldWork.map_origin_x != 0) {
                gFieldWork.follower_x -= sprite_walk_speed(48);
                script_sprite_advance_anim_by_speed(48);
            }
            break;
        case 3:
            if (gFieldWork.follower_x - gFieldWork.map_origin_x + 16 < gFieldWork.map_width * 8) {
                gFieldWork.follower_x += sprite_walk_speed(48);
                script_sprite_advance_anim_by_speed(48);
            }
            break;
        }
        if (--gFieldWork.follower_step_frames == 0) {
            gSpriteEntries[48].work[FIELD_SPR_SPEED] = gSpriteEntries[47].work[FIELD_SPR_SPEED];
            gFieldWork.follower_tile_x = field_pixel_x_to_tile(gFieldWork.follower_x);
            gFieldWork.follower_tile_y = field_pixel_y_to_tile(gFieldWork.follower_y);
        }
    }
}
