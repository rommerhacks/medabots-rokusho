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
    struct MapObject *obj = gUnk_030057E0.unk5DC;

    if ((gUnk_03005310.unk4 & 3) == 0) {
        obj += field_random(64);
        if (obj->unk4_7 && (obj->unk2 >> 12) == 0)
            set_sprite_anim_and_store(obj->unk4_0 + 49, field_random(4), obj);
    }
}

void update_npc_sprite_animations(void) {
    struct MapObject *obj = gUnk_030057E0.unk5DC;
    s32 i;
    u32 active;

    for (i = 0; i < 64; obj++, i++) {
        if (gUnk_030057E0.unkC88) {
            active = gUnk_030057E0.unkCB4 != i;
            if (gUnk_030057E0.unkC92 != 0x87)
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
    struct MapObject *obj = gUnk_030057E0.unk5DC;
    s32 blocked = 0;
    s32 x = gUnk_030057E0.player_tile_x;
    s32 y = gUnk_030057E0.player_tile_y;
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
        if (y == (gUnk_030057E0.unk802 >> 1) - 1)
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
        if (x == (gUnk_030057E0.unk800 >> 1) - 1)
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
                gUnk_030057E0.unkC88 = 1;
                gUnk_030057E0.unkC90 = gUnk_030057E0.unkC8E = obj->unk2 & 0xFFF;
                gUnk_030057E0.unkC89 = 0;
                gUnk_030057E0.unkC8A = 0;
                gUnk_030057E0.unkCB4 = i;
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
    struct MapObject *obj = gUnk_030057E0.unk5DC;
    s32 i;

    for (i = 0; i < 64; i++) {
        if (obj->x == gUnk_030057E0.player_tile_x) {
            if (obj->y == gUnk_030057E0.player_tile_y && (obj->unk2 & 0xF000) >> 12 == 8) {
                gUnk_030057E0.unkC88 = 1;
                gUnk_030057E0.unkC90 = gUnk_030057E0.unkC8E = obj->unk2 & 0xFFF;
                gUnk_030057E0.unkC89 = 0;
                gUnk_030057E0.unkC8A = 0;
                gUnk_030057E0.unkCB4 = i;
                gSpriteEntries[47].unk25 = 1;
                found = 1;
            }
        }
        obj++;
        if (found)
            break;
    }
    return gUnk_030057E0.unkC88;
}

u32 get_adjacent_tile_value(u8 dir) {
    u8 tile;
    switch (dir) {
    case 0:
        tile =
            gUnk_030057E0
                .unk810[(gUnk_030057E0.player_tile_y - 1) * (gUnk_030057E0.unk800 >> 1) + gUnk_030057E0.player_tile_x];
        break;
    case 1:
        tile =
            gUnk_030057E0
                .unk810[(gUnk_030057E0.player_tile_y + 1) * (gUnk_030057E0.unk800 >> 1) + gUnk_030057E0.player_tile_x];
        break;
    case 2:
        tile =
            gUnk_030057E0
                .unk810[gUnk_030057E0.player_tile_y * (gUnk_030057E0.unk800 >> 1) + (gUnk_030057E0.player_tile_x - 1)];
        break;
    case 3:
        tile =
            gUnk_030057E0
                .unk810[gUnk_030057E0.player_tile_y * (gUnk_030057E0.unk800 >> 1) + (gUnk_030057E0.player_tile_x + 1)];
        break;
    }
    return tile;
}

bool32 check_tile_and_trigger_battle_action(u8 dir) {
    u8 tile;
    u32 ret;

    if (gUnk_030057E0.player_form == 2) {
        tile = get_adjacent_tile_value(dir);
        if (tile == 0 || tile == 2) {
            gUnk_030057E0.player_form = gUnk_030057E0.saved_player_form;
            load_battle_palette_via_dma(0);
        }
    }
    tile = get_adjacent_tile_value(dir);
    ret = gUnk_030057E0.unkC10[tile];
    if (ret)
        field_set_player_facing(dir);
    return ret;
}

s32 check_room_exit_at_position(void) {
    s32 ret = -1;
    const struct MapExit *p = gUnk_0840FAF4[gUnk_030057E0.unk7FE];
    s32 blocked = 0;
    s32 x = gUnk_030057E0.player_tile_x;
    s32 y = gUnk_030057E0.player_tile_y;
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
        if (y == (gUnk_030057E0.unk802 >> 1) - 1)
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
        if (x == (gUnk_030057E0.unk800 >> 1) - 1)
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

u8 sub_080526F0(u16 x) {
    return (x - gUnk_030057E0.unkC48) / 16;
}

u8 sub_08052714(u16 y) {
    return (y - gUnk_030057E0.unkC4A) / 16;
}

void update_entity_sprites_on_screen(void) {
    s32 i;
    u8 visible;

    for (i = 0; i < 36; i++) {
        if (gUnk_030055A0[i + 49].unk0 != 0) {
            visible = 0;
            if (gBg1Scroll.y < gSpriteEntries[i + 49].unk10_8 - gUnk_030057E0.unkC4A + 16 &&
                gSpriteEntries[i + 49].unk10_8 - gUnk_030057E0.unkC4A < gBg1Scroll.y + 0xA8 &&
                gBg1Scroll.x < gSpriteEntries[i + 49].unkC_8 - gUnk_030057E0.unkC48 + 16 &&
                gSpriteEntries[i + 49].unkC_8 - gUnk_030057E0.unkC48 < gBg1Scroll.x + 0xF0)
                visible = 1;
            if (visible) {
                if (gSpriteEntries[i + 49].unk2D != 1) {
                    gSpriteEntries[i + 49].unk0 = gSpriteEntries[i + 49].unk32;
                    gSpriteEntries[i + 49].unk2E = 1;
                    gSpriteEntries[i + 49].unk2 = gSpriteEntries[i + 49].unkC_8 - gBg1Scroll.x;
                    gSpriteEntries[i + 49].unk4 = gSpriteEntries[i + 49].unk10_8 - gBg1Scroll.y;
                    if (gUnk_083D2B8D[gSpriteEntries[i + 49].unk30]) {
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
    LZ77UnCompVram(gUnk_083F92F4[area].unk0, gUnk_03006D14);
    if (sub_08052960(gUnk_030057E0.unk7FE, 0) >> 1 <= 14)
        gUnk_030057E0.unkC48 = (15 - (sub_08052960(area, 0) >> 1)) * 8;
    else
        gUnk_030057E0.unkC48 = 0;
    if (sub_08052960(gUnk_030057E0.unk7FE, 1) >> 1 <= 9)
        gUnk_030057E0.unkC4A = (10 - (sub_08052960(area, 1) >> 1)) * 8;
    else
        gUnk_030057E0.unkC4A = 0;
}

u32 sub_08052960(u8 area, u8 which) {
    u32 ret = 0;

    switch (which) {
    case 0:
        ret = gUnk_083F8B74[area][which];
        break;
    case 1:
        ret = gUnk_083F8B74[area][which];
        break;
    }
    return ret;
}

u32 sub_08052990(u32 unused, u8 which) {
    u32 ret = 0;

    switch (which) {
    case 0:
        ret = gUnk_03006D14[0] | (gUnk_03006D14[1] << 16);
        break;
    case 1:
        ret = gUnk_03006D14[2] | (gUnk_03006D14[3] << 16);
        break;
    }
    return ret;
}

void sub_080529C4(u16 x) {
    gBg1Scroll.x = x;
    gBg2Scroll.x = x;
    gBg3Scroll.x = x;
}

void sub_080529E4(u16 y) {
    gBg1Scroll.y = y;
    gBg2Scroll.y = y;
    gBg3Scroll.y = y;
}

u32 sub_08052A04(void) {
    return gUnk_030057E0.unkC48;
}

u32 sub_08052A18(void) {
    return gUnk_030057E0.unkC4A;
}

void sub_08052A2C(s16 dx) {
    gBg1Scroll.x += dx;
    gBg2Scroll.x += dx;
    gBg3Scroll.x += dx;
}

void field_center_camera_on_player(void) {
    s32 x, y;

    x = gUnk_030057E0.player_tile_x - 7;
    if (x < 0)
        x = 0;
    if (x + 15 > sub_08052960(gUnk_030057E0.unk7FE, 0) >> 1) {
        x = sub_08052960(gUnk_030057E0.unk7FE, 0) >> 1;
        x -= 15;
        if (sub_08052A04())
            x = 0;
    }
    y = gUnk_030057E0.player_tile_y - 4;
    if (y <= 0)
        y = 0;
    if (y + 10 > sub_08052960(gUnk_030057E0.unk7FE, 1) >> 1) {
        y = sub_08052960(gUnk_030057E0.unk7FE, 1) >> 1;
        y -= 10;
        if (sub_08052A18())
            y = 0;
    }
    sub_080529C4(x * 16);
    sub_080529E4(y * 16);
}

void sub_08052AF8(s16 dy) {
    gBg1Scroll.y += dy;
    gBg2Scroll.y += dy;
    gBg3Scroll.y += dy;
}

void update_bg_scroll_offsets_a(void) {
    gSpriteEntries[47].unk2 = gUnk_030057E0.player_x - gBg1Scroll.x;
    gSpriteEntries[47].unk4 = gUnk_030057E0.player_y - gBg1Scroll.y;
    gSpriteEntries[89].unk2 = gSpriteEntries[47].unk2;
    gSpriteEntries[89].unk4 = gSpriteEntries[47].unk4 - 5;
}

static void sub_08052B84(void) {
    gSpriteEntries[47].unk0 = 0;
    gSpriteEntries[89].unk0 = 0;
}

void sub_08052BA0(u8 on) {
    if (on) {
        gSpriteEntries[47].unk0 = 0xC804;
        gSpriteEntries[89].unk0 = 0xCC0C;
    } else {
        gSpriteEntries[47].unk0 = on;
        gSpriteEntries[89].unk0 = on;
    }
}

void check_and_update_battlefield_palette(void) {
    if (gUnk_030057E0.player_form == 1 && current_area_flag(0) == 0) {
        gUnk_030057E0.player_form = gUnk_030057E0.saved_player_form;
        load_battle_palette_via_dma(1);
    }
}

// Returns 1 if a warp of the current area sits at (x, y); stores its high dir nibble in gUnk_03006D38.unk3.
u32 find_map_event_by_coords(u32 x, u32 y) {
    u32 found = 0;
    const struct AreaWarp *w = gAreaWarps[gUnk_030057E0.unk7FE];
    s32 dir;
    s32 i;

    for (i = 0; w[i].x != 0xFF; i++) {
        u8 wx = w[i].x;
        u8 wy = w[i].y;
        if (wx == x && wy == y) {
            found = 1;
            dir = w[i].dir;
            gUnk_03006D38.unk3 = (dir & 0xF0) >> 4;
        }
    }
    return found;
}

// dir: 0 up, 1 down, 2 left, 3 right. At the edge the player only turns to face dir.
bool32 field_player_at_map_edge(u8 dir) {
    u8 ret = 0;

    switch (dir) {
    case 0:
        if (gUnk_030057E0.player_y - gUnk_030057E0.unkC4A == 0)
            ret = 1;
        break;
    case 1:
        if (gUnk_030057E0.player_y - gUnk_030057E0.unkC4A + 16 == gUnk_030057E0.unk802 * 8)
            ret = 1;
        break;
    case 2:
        if (gUnk_030057E0.player_x - gUnk_030057E0.unkC48 == 0)
            ret = 1;
        break;
    case 3:
        if (gUnk_030057E0.player_x - gUnk_030057E0.unkC48 + 16 == gUnk_030057E0.unk800 * 8)
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
    gUnk_030057E0.player_facing = dir;
    set_sprite_animation_state(47, dir);
    update_battle_direction_indicator(3);
}

void set_battle_state_byte_c83(u8 dir) {
    gUnk_030057E0.unkC83 = dir;
    set_sprite_animation_state(48, dir);
}

void set_tile_data(u8 x, u8 y, u8 val) {
    gUnk_030057E0.unk810[y * (gUnk_030057E0.unk800 >> 1) + x] = val;
}

// Runs at the end of a door transition: finds the warp under the player, switches area and places the player.
void field_warp_to_area(void) {
    u32 found = 0;
    u32 area = gUnk_030057E0.unk7FE;
    const struct AreaWarp *w = gAreaWarps[area];
    s32 i;

    for (i = 0; w[i].x != 0xFF;) {
        u8 x = w[i].x;
        u8 y = w[i].y;
        if (x == gUnk_030057E0.player_tile_x && y == gUnk_030057E0.player_tile_y) {
            gUnk_030057E0.unk7FE = w[i].area;
            field_load_area_tiles(gUnk_030057E0.unk7FE);
            field_set_player_facing(w[i].dir & 7);
            gUnk_030057E0.player_x = (w[i].destX << 4) + gUnk_030057E0.unkC48;
            gUnk_030057E0.player_y = (w[i].destY << 4) + gUnk_030057E0.unkC4A;
            gUnk_030057E0.player_tile_x = sub_080526F0(gUnk_030057E0.player_x);
            gUnk_030057E0.player_tile_y = sub_08052714(gUnk_030057E0.player_y);
            field_center_camera_on_player();
            found = 1;
        }
        i++;
        if (found)
            break;
    }
    update_cursor_tile_position();
}

// guess: sets up sprite 48 and its shadow (90), see update_battle_direction_indicator
void init_battle_medaforce_sprite(void) {
    if (gUnk_030057E0.unkC76) {
        sprite_entry_init(48, 0xC804, gUnk_030057E0.unkC84 * 12 + gUnk_030057E0.unkC83, gUnk_030057E0.unkC84, 1);
        gSpriteEntries[48].unkB = 0x40;
        gSpriteEntries[48].unk2B = gUnk_030057E0.unkC84;
        set_battle_state_byte_c83(gUnk_030057E0.unkC83);
        sprite_anim_start(48, sub_080502B4(48, gUnk_030057E0.unkC83));
        gUnk_030057E0.unkC72 = sub_080526F0(gUnk_030057E0.unkC6E);
        gUnk_030057E0.unkC73 = sub_08052714(gUnk_030057E0.unkC70);
        gSpriteEntries[48].unk30 = area_sprite_sheet_id(gSpriteEntries[48].unk2B);
        sprite_set_blend_from_kind(48);
        sprite_entry_init(90, 0xCC0C, 0x90, 14, 1);
        gSpriteEntries[90].unkC_8 = gUnk_030057E0.unkC6E;
        gSpriteEntries[90].unk10_8 = gUnk_030057E0.unkC70 - 5;
        gSpriteEntries[90].unk2 = gSpriteEntries[48].unk2;
        gSpriteEntries[90].unk4 = gSpriteEntries[48].unk4 - 5;
    }
}

void update_cursor_tile_position(void) {
    if (gUnk_030057E0.unkC76) {
        gUnk_030057E0.unkC6E = gUnk_030057E0.player_x;
        gUnk_030057E0.unkC70 = gUnk_030057E0.player_y;
        gUnk_030057E0.unkC72 = sub_080526F0(gUnk_030057E0.unkC6E);
        gUnk_030057E0.unkC73 = sub_08052714(gUnk_030057E0.unkC70);
        set_battle_state_byte_c83(gSpriteEntries[47].unk20);
    }
}

void update_bg_scroll_offsets_b(void) {
    gSpriteEntries[48].unk2 = gUnk_030057E0.unkC6E - gBg1Scroll.x;
    gSpriteEntries[48].unk4 = gUnk_030057E0.unkC70 - gBg1Scroll.y;
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
    memcpy_u8(gUnk_083D2918[gUnk_030057E0.unkC28], gUnk_030057E0.unkC10, 8);
    gSpriteEntries[47].unk2A = gUnk_083D2908[gUnk_030057E0.player_form];
}
