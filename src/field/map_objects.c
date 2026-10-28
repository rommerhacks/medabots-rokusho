// Field map objects: NPC idle animations, NPC / map event lookup at the cursor tile, tile and room-exit
// checks, on-screen entity sprites, area tiles, camera centring and BG scroll, field_warp_to_area, and the
// nibble-packed event flags in gEventFlags (event_flag_clear..event_counter_get). Used by field/player_walk,
// field/field_walk, field/field_update and the map script commands.
#include "global.h"

void set_sprite_anim_and_store(u8 idx, u8 state, struct MapObject *obj) {
    set_sprite_animation_state(idx, state);
    obj->unk5 = state;
}

void update_npc_random_animation(void) {
    struct MapObject *obj = gFieldWork.objects;

    if ((gFieldState.frame_counter & 3) == 0) {
        obj += field_random(64);
        if (obj->unk4_7 && (obj->unk2 >> 12) == 0)
            set_sprite_anim_and_store(obj->unk4_0 + 49, field_random(4), obj);
    }
}

void update_npc_sprite_animations(void) {
    struct MapObject *obj = gFieldWork.objects;
    s32 i;
    u32 active;

    for (i = 0; i < 64; obj++, i++) {
        if (gFieldWork.script_running) {
            active = gFieldWork.script_object != i;
            if (gFieldWork.cmd != 0x87)
                goto check;
            continue;
        } else {
            active = 1;
        }
    check:
        if (active && (obj->unk2 >> 12) == 6) {
            s32 idx = obj->unk4_0 + 49;
            if (gSpriteEntries[idx].unk24 != 0xFF)
                advance_sprite_animation_frame(idx);
        }
    }
}

u32 map_cursor_move_and_check_event(void) {
    struct MapObject *obj = gFieldWork.objects;
    s32 blocked = 0;
    s32 x = gFieldWork.player_tile_x;
    s32 y = gFieldWork.player_tile_y;
    u8 found;
    s32 i;

    switch (gSpriteEntries[47].unk20) {
    case 0:
        if ((u8)y == 0)
            blocked = 1;
        else
            y--;
        break;
    case 1:
        if (y == (gFieldWork.map_height >> 1) - 1)
            blocked = 1;
        else
            y++;
        break;
    case 2:
        if ((u8)x == 0)
            blocked = 1;
        else
            x--;
        break;
    case 3:
        if (x == (gFieldWork.map_width >> 1) - 1)
            blocked = 1;
        else
            x++;
        break;
    }
    if (blocked == 1)
        return 0;

    found = 0;
    for (i = 0; i < 64; i++) {
        if (obj->x == x && obj->y == y) {
            switch ((obj->unk2 & 0xF000) >> 12) {
            case 0:
            case 4:
            case 6:
                gFieldWork.script_running = 1;
                gFieldWork.last_script_id = gFieldWork.script_id = obj->unk2 & 0xFFF;
                gFieldWork.cmd_busy = 0;
                gFieldWork.script_pos = 0;
                gFieldWork.script_object = i;
                gSpriteEntries[47].unk25 = 1;
                found = 1;
                break;
            }
            if ((obj->unk2 & 0xF000) == 0) {
                u8 *d = &gUnk_03003810;
                u8 slot = obj->unk4_0 + 49;
                const u8 *t = gUnk_083D2903;
                set_sprite_anim_and_store(slot, t[*d], obj);
            }
        }
        obj++;
        if (found == 1)
            break;
    }
    return found;
}

u32 find_npc_event_match(void) {
    u8 found = 0;
    struct MapObject *obj = gFieldWork.objects;
    s32 i;

    for (i = 0; i < 64; i++) {
        if (obj->x == gFieldWork.player_tile_x) {
            if (obj->y == gFieldWork.player_tile_y && (obj->unk2 & 0xF000) >> 12 == 8) {
                gFieldWork.script_running = 1;
                gFieldWork.last_script_id = gFieldWork.script_id = obj->unk2 & 0xFFF;
                gFieldWork.cmd_busy = 0;
                gFieldWork.script_pos = 0;
                gFieldWork.script_object = i;
                gSpriteEntries[47].unk25 = 1;
                found = 1;
            }
        }
        obj++;
        if (found)
            break;
    }
    return gFieldWork.script_running;
}

u32 get_adjacent_tile_value(u8 dir) {
    u8 tile;
    switch (dir) {
    case 0:
        tile = gFieldWork
                   .tile_map[(gFieldWork.player_tile_y - 1) * (gFieldWork.map_width >> 1) + gFieldWork.player_tile_x];
        break;
    case 1:
        tile = gFieldWork
                   .tile_map[(gFieldWork.player_tile_y + 1) * (gFieldWork.map_width >> 1) + gFieldWork.player_tile_x];
        break;
    case 2:
        tile = gFieldWork
                   .tile_map[gFieldWork.player_tile_y * (gFieldWork.map_width >> 1) + (gFieldWork.player_tile_x - 1)];
        break;
    case 3:
        tile = gFieldWork
                   .tile_map[gFieldWork.player_tile_y * (gFieldWork.map_width >> 1) + (gFieldWork.player_tile_x + 1)];
        break;
    }
    return tile;
}

bool32 check_tile_and_trigger_battle_action(u8 dir) {
    u8 tile;
    u32 ret;

    if (gFieldWork.player_form == 2) {
        tile = get_adjacent_tile_value(dir);
        if (tile == 0 || tile == 2) {
            gFieldWork.player_form = gFieldWork.saved_player_form;
            load_battle_palette_via_dma(0);
        }
    }
    tile = get_adjacent_tile_value(dir);
    ret = gFieldWork.tile_actions[tile];
    if (ret)
        field_set_player_facing(dir);
    return ret;
}

s32 check_room_exit_at_position(void) {
    s32 ret = -1;
    const struct MapExit *p = gAreaExits[gFieldWork.area_id];
    s32 blocked = 0;
    s32 x = gFieldWork.player_tile_x;
    s32 y = gFieldWork.player_tile_y;
    u8 mask;
    s32 i;

    // step one tile in the facing direction (0 up, 1 down, 2 left, 3 right)
    switch (gSpriteEntries[47].unk20) {
    case 0:
        if ((u8)y == 0)
            blocked = -1;
        else
            y--;
        break;
    case 1:
        if (y == (gFieldWork.map_height >> 1) - 1)
            blocked = -1;
        else
            y++;
        break;
    case 2:
        if ((u8)x == 0)
            blocked = -1;
        else
            x--;
        break;
    case 3:
        if (x == (gFieldWork.map_width >> 1) - 1)
            blocked = -1;
        else
            x++;
        break;
    }
    if (blocked == -1)
        return blocked;

    for (i = 0; p[i].mask != 0; i++) {
        if (p[i].x == x && p[i].y == y && (ret = p[i].value) != 0) {
            mask = p[i].mask;
            switch (gSpriteEntries[47].unk20) {
            case 0:
                if (!(mask & 2))
                    ret = -1;
                break;
            case 1:
                if (!(mask & 1))
                    ret = -1;
                break;
            case 2:
                if (!(mask & 8))
                    ret = -1;
                break;
            case 3:
                if (!(mask & 4))
                    ret = -1;
                break;
            }
        }
        if (ret != -1)
            break;
    }
    return ret;
}

// Field pixel position to map tile, relative to the map origin (non-zero for maps smaller than the screen).
u8 field_pixel_x_to_tile(u16 x) {
    return (x - gFieldWork.map_origin_x) / 16;
}

u8 field_pixel_y_to_tile(u16 y) {
    return (y - gFieldWork.map_origin_y) / 16;
}

void update_entity_sprites_on_screen(void) {
    s32 i;
    u8 visible;

    for (i = 0; i < 36; i++) {
        if (gEntityStates[i + 49].active != 0) {
            visible = 0;
            if (gBg1Scroll.y < gSpriteEntries[i + 49].unk10_8 - gFieldWork.map_origin_y + 16 &&
                gSpriteEntries[i + 49].unk10_8 - gFieldWork.map_origin_y < gBg1Scroll.y + 0xA8 &&
                gBg1Scroll.x < gSpriteEntries[i + 49].unkC_8 - gFieldWork.map_origin_x + 16 &&
                gSpriteEntries[i + 49].unkC_8 - gFieldWork.map_origin_x < gBg1Scroll.x + 0xF0)
                visible = 1;
            if (visible) {
                if (gSpriteEntries[i + 49].unk2D != 1) {
                    gSpriteEntries[i + 49].unk0 = gSpriteEntries[i + 49].unk32;
                    gSpriteEntries[i + 49].unk2E = 1;
                    gSpriteEntries[i + 49].unk2 = gSpriteEntries[i + 49].unkC_8 - gBg1Scroll.x;
                    gSpriteEntries[i + 49].unk4 = gSpriteEntries[i + 49].unk10_8 - gBg1Scroll.y;
                    if (gSpriteSheetHasShadow[gSpriteEntries[i + 49].unk30]) {
                        gSpriteEntries[i + 91].unk0 = 0xCC0C;
                        gSpriteEntries[i + 91].unk2 = gSpriteEntries[i + 49].unk2;
                        gSpriteEntries[i + 91].unk4 =
                            gSpriteEntries[i + 49].unk4 + (s16)(gSpriteEntries[i + 49].unk2C - 5);
                    } else {
                        gSpriteEntries[i + 91].unk0 = 0;
                    }
                } else {
                    gSpriteEntries[i + 49].unk0 = 0;
                    gSpriteEntries[i + 49].unk2E = 0;
                    gSpriteEntries[i + 91].unk0 = 0;
                }
            } else {
                gSpriteEntries[i + 49].unk0 = 0;
                gSpriteEntries[i + 49].unk2E = 0;
                gSpriteEntries[i + 91].unk0 = 0;
            }
        }
    }
}

// Decompresses the area's tiles and centres maps smaller than the screen (15 x 10 tiles).
void field_load_area_tiles(u8 area) {
    LZ77UnCompVram(gAreaBgTilemaps[area].unk0, gFieldTilemapBuf);
    if (area_map_size(gFieldWork.area_id, 0) >> 1 <= 14)
        gFieldWork.map_origin_x = (15 - (area_map_size(area, 0) >> 1)) * 8;
    else
        gFieldWork.map_origin_x = 0;
    if (area_map_size(gFieldWork.area_id, 1) >> 1 <= 9)
        gFieldWork.map_origin_y = (10 - (area_map_size(area, 1) >> 1)) * 8;
    else
        gFieldWork.map_origin_y = 0;
}

// Map width (which 0) or height (1) of an area, in 8-pixel units.
u32 area_map_size(u8 area, u8 which) {
    u32 ret = 0;

    switch (which) {
    case 0:
        ret = gAreaMapSizes[area][which];
        break;
    case 1:
        ret = gAreaMapSizes[area][which];
        break;
    }
    return ret;
}

// The first two 32-bit header words of the last tilemap decompressed to gFieldTilemapBuf.
u32 field_tilemap_header_word(u32 unused, u8 which) {
    u32 ret = 0;

    switch (which) {
    case 0:
        ret = gFieldTilemapBuf[0] | (gFieldTilemapBuf[1] << 16);
        break;
    case 1:
        ret = gFieldTilemapBuf[2] | (gFieldTilemapBuf[3] << 16);
        break;
    }
    return ret;
}

// Sets (or below, moves) the scroll of all three field BG layers together.
void field_set_bg_scroll_x(u16 x) {
    gBg1Scroll.x = x;
    gBg2Scroll.x = x;
    gBg3Scroll.x = x;
}

void field_set_bg_scroll_y(u16 y) {
    gBg1Scroll.y = y;
    gBg2Scroll.y = y;
    gBg3Scroll.y = y;
}

u32 field_map_origin_x(void) {
    return gFieldWork.map_origin_x;
}

u32 field_map_origin_y(void) {
    return gFieldWork.map_origin_y;
}

void field_scroll_bg_x(s16 dx) {
    gBg1Scroll.x += dx;
    gBg2Scroll.x += dx;
    gBg3Scroll.x += dx;
}

void field_center_camera_on_player(void) {
    s32 x, y;

    x = gFieldWork.player_tile_x - 7;
    if (x < 0)
        x = 0;
    if (x + 15 > area_map_size(gFieldWork.area_id, 0) >> 1) {
        x = area_map_size(gFieldWork.area_id, 0) >> 1;
        x -= 15;
        if (field_map_origin_x())
            x = 0;
    }
    y = gFieldWork.player_tile_y - 4;
    if (y <= 0)
        y = 0;
    if (y + 10 > area_map_size(gFieldWork.area_id, 1) >> 1) {
        y = area_map_size(gFieldWork.area_id, 1) >> 1;
        y -= 10;
        if (field_map_origin_y())
            y = 0;
    }
    field_set_bg_scroll_x(x * 16);
    field_set_bg_scroll_y(y * 16);
}

void field_scroll_bg_y(s16 dy) {
    gBg1Scroll.y += dy;
    gBg2Scroll.y += dy;
    gBg3Scroll.y += dy;
}

void update_bg_scroll_offsets_a(void) {
    gSpriteEntries[47].unk2 = gFieldWork.player_x - gBg1Scroll.x;
    gSpriteEntries[47].unk4 = gFieldWork.player_y - gBg1Scroll.y;
    gSpriteEntries[89].unk2 = gSpriteEntries[47].unk2;
    gSpriteEntries[89].unk4 = gSpriteEntries[47].unk4 - 5;
}

static void field_hide_player_sprite(void) {
    gSpriteEntries[47].unk0 = 0;
    gSpriteEntries[89].unk0 = 0;
}

// Shows or hides the player sprite (entry 47) and its shadow (entry 89).
void field_set_player_sprite_visible(u8 on) {
    if (on) {
        gSpriteEntries[47].unk0 = 0xC804;
        gSpriteEntries[89].unk0 = 0xCC0C;
    } else {
        gSpriteEntries[47].unk0 = on;
        gSpriteEntries[89].unk0 = on;
    }
}

void check_and_update_battlefield_palette(void) {
    if (gFieldWork.player_form == 1 && area_allows_vehicle(0) == 0) {
        gFieldWork.player_form = gFieldWork.saved_player_form;
        load_battle_palette_via_dma(1);
    }
}

// Returns 1 if a warp of the current area sits at (x, y); stores its high dir nibble in gFieldSceneParams.warp_sound.
u32 find_map_event_by_coords(u32 x, u32 y) {
    u32 found = 0;
    const struct AreaWarp *w = gAreaWarps[gFieldWork.area_id];
    s32 dir;
    s32 i;

    for (i = 0; w[i].x != 0xFF; i++) {
        u8 wx = w[i].x;
        u8 wy = w[i].y;
        if (wx == x && wy == y) {
            found = 1;
            dir = w[i].dir;
            gFieldSceneParams.warp_sound = (dir & 0xF0) >> 4;
        }
    }
    return found;
}

// dir: 0 up, 1 down, 2 left, 3 right. At the edge the player only turns to face dir.
bool32 field_player_at_map_edge(u8 dir) {
    u8 ret = 0;

    switch (dir) {
    case 0:
        if (gFieldWork.player_y - gFieldWork.map_origin_y == 0)
            ret = 1;
        break;
    case 1:
        if (gFieldWork.player_y - gFieldWork.map_origin_y + 16 == gFieldWork.map_height * 8)
            ret = 1;
        break;
    case 2:
        if (gFieldWork.player_x - gFieldWork.map_origin_x == 0)
            ret = 1;
        break;
    case 3:
        if (gFieldWork.player_x - gFieldWork.map_origin_x + 16 == gFieldWork.map_width * 8)
            ret = 1;
        break;
    }
    if (ret)
        field_set_player_facing(dir);
    return ret;
}

void set_sprite_animation_state(u8 idx, u8 state) {
    gSpriteEntries[idx].unk20 = state;
    gSpriteEntries[idx].unk21 = state;
    switch (state) {
    case 0:
        gSpriteEntries[idx].unk6 = gSpriteEntries[idx].unk2B * 12;
        break;
    case 1:
        gSpriteEntries[idx].unk6 = gSpriteEntries[idx].unk2B * 12 + 3;
        break;
    case 2:
        gSpriteEntries[idx].unk6 = gSpriteEntries[idx].unk2B * 12 + 6;
        break;
    case 3:
        gSpriteEntries[idx].unk6 = gSpriteEntries[idx].unk2B * 12 + 9;
        break;
    }
}

// Player facing (0 up, 1 down, 2 left, 3 right); sprite 47 is the player.
void field_set_player_facing(u8 dir) {
    gFieldWork.player_facing = dir;
    set_sprite_animation_state(47, dir);
    follower_turn_toward_player(3);
}

void follower_set_facing(u8 dir) {
    gFieldWork.follower_facing = dir;
    set_sprite_animation_state(48, dir);
}

void set_tile_data(u8 x, u8 y, u8 val) {
    gFieldWork.tile_map[y * (gFieldWork.map_width >> 1) + x] = val;
}

// Runs at the end of a door transition: finds the warp under the player, switches area and places the player.
void field_warp_to_area(void) {
    u32 found = 0;
    u32 area = gFieldWork.area_id;
    const struct AreaWarp *w = gAreaWarps[area];
    s32 i;

    for (i = 0; w[i].x != 0xFF;) {
        u8 x = w[i].x;
        u8 y = w[i].y;
        if (x == gFieldWork.player_tile_x && y == gFieldWork.player_tile_y) {
            gFieldWork.area_id = w[i].area;
            field_load_area_tiles(gFieldWork.area_id);
            field_set_player_facing(w[i].dir & 7);
            gFieldWork.player_x = (w[i].destX << 4) + gFieldWork.map_origin_x;
            gFieldWork.player_y = (w[i].destY << 4) + gFieldWork.map_origin_y;
            gFieldWork.player_tile_x = field_pixel_x_to_tile(gFieldWork.player_x);
            gFieldWork.player_tile_y = field_pixel_y_to_tile(gFieldWork.player_y);
            field_center_camera_on_player();
            found = 1;
        }
        i++;
        if (found)
            break;
    }
    follower_snap_to_player();
}

// Recreates the follower sprite (48) and its shadow (90) after an area or screen reload.
void follower_respawn(void) {
    if (gFieldWork.follower_active) {
        sprite_entry_init(48, 0xC804, gFieldWork.follower_sprite_set * 12 + gFieldWork.follower_facing,
                          gFieldWork.follower_sprite_set, 1);
        gSpriteEntries[48].unkB = 0x40;
        gSpriteEntries[48].unk2B = gFieldWork.follower_sprite_set;
        follower_set_facing(gFieldWork.follower_facing);
        sprite_anim_start(48, sprite_walk_anim_id(48, gFieldWork.follower_facing));
        gFieldWork.follower_tile_x = field_pixel_x_to_tile(gFieldWork.follower_x);
        gFieldWork.follower_tile_y = field_pixel_y_to_tile(gFieldWork.follower_y);
        gSpriteEntries[48].unk30 = area_sprite_sheet_id(gSpriteEntries[48].unk2B);
        sprite_set_blend_from_kind(48);
        sprite_entry_init(90, 0xCC0C, 0x90, 14, 1);
        gSpriteEntries[90].unkC_8 = gFieldWork.follower_x;
        gSpriteEntries[90].unk10_8 = gFieldWork.follower_y - 5;
        gSpriteEntries[90].unk2 = gSpriteEntries[48].unk2;
        gSpriteEntries[90].unk4 = gSpriteEntries[48].unk4 - 5;
    }
}

void follower_snap_to_player(void) {
    if (gFieldWork.follower_active) {
        gFieldWork.follower_x = gFieldWork.player_x;
        gFieldWork.follower_y = gFieldWork.player_y;
        gFieldWork.follower_tile_x = field_pixel_x_to_tile(gFieldWork.follower_x);
        gFieldWork.follower_tile_y = field_pixel_y_to_tile(gFieldWork.follower_y);
        follower_set_facing(gSpriteEntries[47].unk20);
    }
}

void follower_update_screen_pos(void) {
    gSpriteEntries[48].unk2 = gFieldWork.follower_x - gBg1Scroll.x;
    gSpriteEntries[48].unk4 = gFieldWork.follower_y - gBg1Scroll.y;
    gSpriteEntries[90].unk2 = gSpriteEntries[48].unk2;
    gSpriteEntries[90].unk4 = gSpriteEntries[48].unk4 - 5;
}

void event_flag_clear(u16 id) {
    if (!(id & 1)) {
        u8 *flags = gEventFlags;
        flags[id >> 1] &= 0x7F;
    } else {
        u8 *flags = gEventFlags;
        flags[id >> 1] &= 0xF7;
    }
}

void event_flag_set(u16 id) {
    if (!(id & 1)) {
        u8 *flags = gEventFlags;
        flags[id >> 1] = (flags[id >> 1] & 0x7F) | 0x80;
    } else {
        u8 *flags = gEventFlags;
        flags[id >> 1] = (flags[id >> 1] & 0xF7) | 0x08;
    }
}

u32 event_flag_get(u16 id) {
    if (!(id & 1)) {
        u8 *flags = gEventFlags;
        return (u8)(flags[id >> 1] & 0x80) >> 7;
    } else {
        u8 *flags = gEventFlags;
        return (u8)(flags[id >> 1] & 0x08) >> 3;
    }
}

void event_flag_write(u16 id, u8 val) {
    if (val == 0)
        event_flag_clear(id);
    else
        event_flag_set(id);
}

void event_counter_set(u16 id, u8 val) {
    if (!(id & 1)) {
        u8 *flags = gEventFlags;
        flags[id >> 1] = (flags[id >> 1] & 0x8F) | (val << 4);
    } else {
        u8 *flags = gEventFlags;
        flags[id >> 1] = (flags[id >> 1] & 0xF8) | val;
    }
}

void event_counter_increment(u16 id) {
    u8 n;

    if (!(id & 1)) {
        u8 *flags = gEventFlags;
        n = (flags[id >> 1] & 0x70) >> 4;
        n++;
        flags[id >> 1] = (flags[id >> 1] & 0x8F) | (n << 4);
    } else {
        u8 *flags = gEventFlags;
        n = flags[id >> 1] & 7;
        n++;
        flags[id >> 1] = (flags[id >> 1] & 0xF8) | n;
    }
}

u32 event_counter_get(u16 id) {
    if (!(id & 1)) {
        u8 *flags = gEventFlags;
        return (flags[id >> 1] & 0x70) >> 4;
    } else {
        u8 *flags = gEventFlags;
        return flags[id >> 1] & 7;
    }
}

void load_battle_terrain_data(void) {
    memcpy_u8(gUnk_083D2918[gFieldWork.loaded_form], gFieldWork.tile_actions, 8);
    gSpriteEntries[47].unk2A = gPlayerFormSpeedIds[gFieldWork.player_form];
}
