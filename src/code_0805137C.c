#include "global.h"

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
    const struct MapNpcRecord *e;

    obj = gUnk_030057E0.unk5DC;
    sub_080496C8((u8 *)saved, sizeof(saved));
    memcpy_u8(obj, saved, sizeof(saved));
    sub_080496C8((u8 *)obj, sizeof(saved));
    count = 0;
    n = 0;
    j = 0;
    for (k = 0; k < 32; k++) {
        for (e = gUnk_084837A0[gUnk_030057E0.unk7FE]; e->x != 0xFF; e++) {
            if (!((e->unk6 >> gUnk_030057E0.unk7FF) & 1))
                continue;
            if (e->unk5 != k)
                continue;
            if (sub_08053194(e->unk2 & 0xFFF))
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
                        if ((e->unk2 & 0xFFF) == (saved[j].unk2 & 0xFFF))
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
                            if (saved[j].unk4_7 == 1)
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
            anim = e->unk4 >> 4;
            gUnk_030057E0.unk5DC[n].x = e->x;
            gUnk_030057E0.unk5DC[n].y = e->y;
            gUnk_030057E0.unk5DC[n].unk2 = e->unk2;
            switch (e->unk2 >> 12) {
            case 0:
            case 4:
            case 6:
                gUnk_030057E0.unk810[e->y * (gUnk_030057E0.unk800 >> 1) + e->x] = 7;
                break;
            }
            gUnk_030057E0.unk5DC[n].unk4_7 = 1;
            if (e->unk4 == 0xFF)
                goto next;
            if (count < 30) {
                switch (e->unk2 >> 12) {
                case 0:
                case 2:
                case 4:
                case 6: {
                    u8 slot = count + 49;
                    u32 f = anim * 12;
                    u8 a = anim;
                    init_battle_sprite_entry_08048818(slot, 0xC804, f, a, 1);
                    gUnk_030057E0.unk5DC[n].unk4_6 = 1;
                    gUnk_03002C30[count + 49].unk30 = resolve_tile_from_battle_state(a);
                    sub_0804877C(count + 49);
                    if (gUnk_083D2B8D[gUnk_03002C30[count + 49].unk30])
                        init_battle_sprite_entry_08048818(count + 91, 0xCC0C, 0x90, 14, 1);
                } break;
                }
                gUnk_030057E0.unk5DC[n].unk4_0 = count;
                anim = e->unk4 >> 4;
                gUnk_030055A0[count + 49].unk0 = e->unk2 & 0xFFF;
                gUnk_03002C30[count + 49].unk2B = anim;
                gUnk_03002C30[count + 49].unkC_8 = e->x * 16 + gUnk_030057E0.unkC48;
                gUnk_03002C30[count + 49].unk10_8 = e->y * 16 + gUnk_030057E0.unkC4A;
                set_sprite_anim_and_store(count + 49, e->unk4 & 0xF, &gUnk_030057E0.unk5DC[n]);
                sub_080493D4(count + 49, anim * 4 + (e->unk4 & 0xF));
                if (mode != 0 && found) {
                    set_sprite_anim_and_store(count + 49, saved[j].unk5, &gUnk_030057E0.unk5DC[n]);
                    sub_080493D4(count + 49, saved[j].unk5 + anim * 4);
                }
                gUnk_03002C30[count + 49].unk2C = 0;
                gUnk_03002C30[count + 91].unkC_8 = gUnk_03002C30[count + 49].unkC_8;
                gUnk_03002C30[count + 91].unk10_8 = gUnk_03002C30[count + 49].unk10_8 - 5;
                gUnk_03002C30[count + 91].unk2 = gUnk_03002C30[count + 49].unk2;
                gUnk_03002C30[count + 91].unk4 = gUnk_03002C30[count + 49].unk4 - 5;
            }
            count++;
        next:
            n++;
        }
    }
    if (gUnk_030057E0.unkC8E != 0) {
        for (i = 0; i < 64; obj++, i++) {
            if ((obj->unk2 & 0xFFF) == gUnk_030057E0.unkC8E) {
                gUnk_030057E0.unkCB4 = i;
                break;
            }
        }
    }
    gUnk_030057E0.unkCBA = 2;
}

// guess: sets up the player sprite (47) and its shadow (89) on entering the field
void init_battle_field_setup(void) {
    gUnk_030057E0.unkC58 = 0;
    gUnk_030057E0.unkC28 = gUnk_030057E0.unkC5C;
    load_battle_terrain_data();
    gUnk_030057E0.unkC56 = sub_080526F0(gUnk_030057E0.unkC52);
    gUnk_030057E0.unkC57 = sub_08052714(gUnk_030057E0.unkC54);
    init_battle_sprite_entry_08048818(47, 0xC804, 3, 0, 1);
    field_set_player_facing(gUnk_030057E0.unkC67);
    update_battle_direction_indicator(3);
    gUnk_03002C30[47].unkB = 0x40;
    LZ77UnCompVram(gUnk_085FA104, (void *)0x06017FC0);
    init_battle_sprite_entry_08048818(89, 0xCC0C, 0x90, 14, 1);
    gUnk_03002C30[89].unkC_8 = gUnk_030057E0.unkC52;
    gUnk_03002C30[89].unk10_8 = gUnk_030057E0.unkC54 - 5;
    gUnk_03002C30[89].unk2 = gUnk_03002C30[47].unk2;
    gUnk_03002C30[89].unk4 = gUnk_03002C30[47].unk4 - 5;
    if (gUnk_030057E0.unkC5B) {
        gUnk_03002C30[47].unk0 = 0xC804;
    } else {
        gUnk_03002C30[47].unk0 = 0;
        gUnk_03002C30[89].unk0 = 0;
    }
}

s32 sub_080518F4(u8 idx) {
    return gUnk_083D28C0[gUnk_03002C30[idx].unk2A] * gUnk_083D28C0[gUnk_03006D38.unk2];
}

void set_battle_state_cancel_flag(void) {
    gUnk_030057E0.unkC59 = 0xFF;
    sub_08051E8C();
}

// One frame of a tile step (dir 0 up, 1 down, 2 left, 3 right): moves the player, scrolls the camera,
// and when the step ends (unkC58 counts down) checks NPC events, map events and random encounters.
void field_player_step(u8 dir) {
    switch (dir) {
    case 0:
        if (gUnk_030057E0.unkC54 - gUnk_030057E0.unkC4A != 0) {
            gUnk_030057E0.unkC54 -= sub_080518F4(47);
            advance_sprite_by_terrain_modifier(47);
            if (!sub_08052A18() && gUnk_030057E0.unkC54 - gUnk_030057E0.unkC4A < gUnk_030057E0.unk802 * 8 - 0x60 &&
                gBg1Scroll.y != 0)
                sub_08052AF8(-sub_080518F4(47));
        }
        break;
    case 1:
        if (gUnk_030057E0.unkC54 - gUnk_030057E0.unkC4A + 16 < gUnk_030057E0.unk802 * 8) {
            gUnk_030057E0.unkC54 += sub_080518F4(47);
            advance_sprite_by_terrain_modifier(47);
            if (!sub_08052A18() && gUnk_030057E0.unkC54 - gUnk_030057E0.unkC4A + 16 > 0x50 &&
                gBg1Scroll.y + 0xA0 < gUnk_030057E0.unk802 * 8)
                sub_08052AF8(sub_080518F4(47));
        }
        break;
    case 2:
        if (gUnk_030057E0.unkC52 - gUnk_030057E0.unkC48 != 0) {
            gUnk_030057E0.unkC52 -= sub_080518F4(47);
            advance_sprite_by_terrain_modifier(47);
            if (!sub_08052A04() && gUnk_030057E0.unkC52 - gUnk_030057E0.unkC48 < gUnk_030057E0.unk800 * 8 - 0x80 &&
                gBg1Scroll.x != 0)
                sub_08052A2C(-sub_080518F4(47));
        }
        break;
    case 3:
        if (gUnk_030057E0.unkC52 - gUnk_030057E0.unkC48 + 16 < gUnk_030057E0.unk800 * 8) {
            gUnk_030057E0.unkC52 += sub_080518F4(47);
            advance_sprite_by_terrain_modifier(47);
            if (!sub_08052A04() && gUnk_030057E0.unkC52 - gUnk_030057E0.unkC48 + 16 > 0x80 &&
                gBg1Scroll.x + 0xF0 < gUnk_030057E0.unk800 * 8)
                sub_08052A2C(sub_080518F4(47));
        }
        break;
    }
    if (--gUnk_030057E0.unkC58 == 0) {
        gUnk_03002C30[47].unk2A = gUnk_083D2908[gUnk_030057E0.unkC5C];
        gUnk_030057E0.unkC56 = sub_080526F0(gUnk_030057E0.unkC52);
        gUnk_030057E0.unkC57 = sub_08052714(gUnk_030057E0.unkC54);
        if (gUnk_030057E0.unkC88 == 0 && !find_npc_event_match()) {
            if (find_map_event_by_coords(gUnk_030057E0.unkC56, gUnk_030057E0.unkC57)) {
                gUnk_03005310.unk1 = 3;
                if (gUnk_03006D38.unk3)
                    sub_08047BA8(gUnk_083D29E6[gUnk_03006D38.unk3]);
                setup_palette_fade_to_color_with_obj(0x7FFF, 0.0f, 32.0f, 8.0f);
            } else if (gUnk_030057E0.unkC5C != 1 && check_random_encounter()) {
                save_script_sprites();
                switch_game_mode(0x21, 0);
            }
        }
    }
}

u8 handle_battle_movement_input(u8 dir) {
    u32 tile = gUnk_0847E948[gUnk_030057E0.unkC57 * (gUnk_030057E0.unk800 >> 1) + gUnk_030057E0.unkC56] - 1;

    if (tile <= 3)
        dir = gUnk_083D28C3[tile][dir];
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

    if (gUnk_030057E0.unkC58 == 0) {
        any = gHeldKeyBits.down | gHeldKeyBits.up | gHeldKeyBits.left | gHeldKeyBits.right;
        if (any) {
            input = (gHeldKeyBits.down << 3) | (gHeldKeyBits.up << 2) | (gHeldKeyBits.left << 1) | gHeldKeyBits.right;
            if (gUnk_030057E0.unkC88 == 0 && gUnk_030057E0.unk7FE == 0x53)
                input = handle_battle_movement_input(input);
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
            if (gUnk_030057E0.unkC59 != dir) {
                gUnk_030057E0.unkC59 = dir;
                field_set_player_facing(dir);
                sub_080493D4(0x2F, dir);
                update_battle_direction_indicator(3);
            }
            if (!field_player_at_map_edge(dir) && !check_tile_and_trigger_battle_action(dir)) {
                gUnk_030057E0.unkC58 = 16 / sub_080518F4(0x2F);
                field_player_step(gUnk_030057E0.unkC59);
                update_battle_direction_indicator(3);
                if (gUnk_030057E0.unkC5C == 2 || gUnk_030057E0.unkC5C == 9)
                    sub_08047BA8(0x57);
                battle_camera_scroll_update(gUnk_030057E0.unkC75);
            }
        }
    } else {
        field_player_step(gUnk_030057E0.unkC59);
        battle_camera_scroll_update(gUnk_030057E0.unkC75);
    }
}

void load_battle_palette_via_dma(u32 toBuffer) {
    decompress_battle_tile_graphics();
    if (toBuffer == 0)
        DmaCopy32(3, gUnk_083F8634[gUnk_083D29A6[gUnk_030057E0.unkC5C]], OBJ_PLTT,
                  32) else DmaCopy32(3, gUnk_083F8634[gUnk_083D29A6[gUnk_030057E0.unkC5C]], 0x0202F800, 32)
            gUnk_030057E0.unkC28 = gUnk_030057E0.unkC5C;
    load_battle_terrain_data();
}

void sub_08051E8C(void) {
    if (gUnk_030057E0.unkC76)
        gUnk_030057E0.unkC75 = 0xFF;
}

// guess: sprite 48 (shadow 90) follows the player while unkC76 is set; turns it toward the player's tile.
// unkC76 stayed 0 through walkthrough segment 01.
void update_battle_direction_indicator(u8 flags) {
    u8 prev = gUnk_030057E0.unkC75;

    if (gUnk_030057E0.unkC73 == gUnk_030057E0.unkC57) {
        if (gUnk_030057E0.unkC72 == gUnk_030057E0.unkC56) {
            gUnk_030057E0.unkC74 = 0;
        } else {
            if (flags & 2)
                gUnk_030057E0.unkC74 = 16 / sub_080518F4(48);
            if (gUnk_030057E0.unkC72 < gUnk_030057E0.unkC56)
                gUnk_030057E0.unkC75 = 3;
            else
                gUnk_030057E0.unkC75 = 2;
            if (gUnk_030057E0.unkC75 != prev) {
                set_battle_state_byte_c83(gUnk_030057E0.unkC75);
                sub_080493D4(48, sub_080502B4(48, gUnk_030057E0.unkC75));
            }
        }
    } else {
        if (flags & 2)
            gUnk_030057E0.unkC74 = 16 / sub_080518F4(48);
        if (gUnk_030057E0.unkC73 < gUnk_030057E0.unkC57)
            gUnk_030057E0.unkC75 = 1;
        else
            gUnk_030057E0.unkC75 = 0;
        if (gUnk_030057E0.unkC75 != prev) {
            set_battle_state_byte_c83(gUnk_030057E0.unkC75);
            sub_080493D4(48, sub_080502B4(48, gUnk_030057E0.unkC75));
        }
    }
    gUnk_03002C30[48].unk2A = gUnk_03002C30[47].unk2A;
}

// guess: one frame of sprite 48's step toward the player (see update_battle_direction_indicator)
void battle_camera_scroll_update(u8 dir) {
    if (gUnk_030057E0.unkC76 && gUnk_030057E0.unkC74) {
        switch (dir) {
        case 0:
            if (gUnk_030057E0.unkC70 - gUnk_030057E0.unkC4A != 0) {
                gUnk_030057E0.unkC70 -= sub_080518F4(48);
                advance_sprite_by_terrain_modifier(48);
            }
            break;
        case 1:
            if (gUnk_030057E0.unkC70 - gUnk_030057E0.unkC4A + 16 < gUnk_030057E0.unk802 * 8) {
                gUnk_030057E0.unkC70 += sub_080518F4(48);
                advance_sprite_by_terrain_modifier(48);
            }
            break;
        case 2:
            if (gUnk_030057E0.unkC6E - gUnk_030057E0.unkC48 != 0) {
                gUnk_030057E0.unkC6E -= sub_080518F4(48);
                advance_sprite_by_terrain_modifier(48);
            }
            break;
        case 3:
            if (gUnk_030057E0.unkC6E - gUnk_030057E0.unkC48 + 16 < gUnk_030057E0.unk800 * 8) {
                gUnk_030057E0.unkC6E += sub_080518F4(48);
                advance_sprite_by_terrain_modifier(48);
            }
            break;
        }
        if (--gUnk_030057E0.unkC74 == 0) {
            gUnk_03002C30[48].unk2A = gUnk_03002C30[47].unk2A;
            gUnk_030057E0.unkC72 = sub_080526F0(gUnk_030057E0.unkC6E);
            gUnk_030057E0.unkC73 = sub_08052714(gUnk_030057E0.unkC70);
        }
    }
}

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
            if (gUnk_03002C30[idx].unk24 != 0xFF)
                advance_sprite_animation_frame(idx);
        }
    }
}

u32 map_cursor_move_and_check_event(void) {
    struct MapObject *obj = gUnk_030057E0.unk5DC;
    s32 blocked = 0;
    s32 x = gUnk_030057E0.unkC56;
    s32 y = gUnk_030057E0.unkC57;
    u8 found;
    s32 i;

    switch (gUnk_03002C30[47].unk20) {
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
                gUnk_03002C30[47].unk25 = 1;
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
        if (obj->x == gUnk_030057E0.unkC56) {
            if (obj->y == gUnk_030057E0.unkC57 && (obj->unk2 & 0xF000) >> 12 == 8) {
                gUnk_030057E0.unkC88 = 1;
                gUnk_030057E0.unkC90 = gUnk_030057E0.unkC8E = obj->unk2 & 0xFFF;
                gUnk_030057E0.unkC89 = 0;
                gUnk_030057E0.unkC8A = 0;
                gUnk_030057E0.unkCB4 = i;
                gUnk_03002C30[47].unk25 = 1;
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
        tile = gUnk_030057E0.unk810[(gUnk_030057E0.unkC57 - 1) * (gUnk_030057E0.unk800 >> 1) + gUnk_030057E0.unkC56];
        break;
    case 1:
        tile = gUnk_030057E0.unk810[(gUnk_030057E0.unkC57 + 1) * (gUnk_030057E0.unk800 >> 1) + gUnk_030057E0.unkC56];
        break;
    case 2:
        tile = gUnk_030057E0.unk810[gUnk_030057E0.unkC57 * (gUnk_030057E0.unk800 >> 1) + (gUnk_030057E0.unkC56 - 1)];
        break;
    case 3:
        tile = gUnk_030057E0.unk810[gUnk_030057E0.unkC57 * (gUnk_030057E0.unk800 >> 1) + (gUnk_030057E0.unkC56 + 1)];
        break;
    }
    return tile;
}

bool32 check_tile_and_trigger_battle_action(u8 dir) {
    u8 tile;
    u32 ret;

    if (gUnk_030057E0.unkC5C == 2) {
        tile = get_adjacent_tile_value(dir);
        if (tile == 0 || tile == 2) {
            gUnk_030057E0.unkC5C = gUnk_030057E0.unkC69;
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
    s32 x = gUnk_030057E0.unkC56;
    s32 y = gUnk_030057E0.unkC57;
    u8 mask;
    s32 i;

    // step one tile in the facing direction (0 up, 1 down, 2 left, 3 right)
    switch (gUnk_03002C30[47].unk20) {
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
            switch (gUnk_03002C30[47].unk20) {
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
            if (gBg1Scroll.y < gUnk_03002C30[i + 49].unk10_8 - gUnk_030057E0.unkC4A + 16 &&
                gUnk_03002C30[i + 49].unk10_8 - gUnk_030057E0.unkC4A < gBg1Scroll.y + 0xA8 &&
                gBg1Scroll.x < gUnk_03002C30[i + 49].unkC_8 - gUnk_030057E0.unkC48 + 16 &&
                gUnk_03002C30[i + 49].unkC_8 - gUnk_030057E0.unkC48 < gBg1Scroll.x + 0xF0)
                visible = 1;
            if (visible) {
                if (gUnk_03002C30[i + 49].unk2D != 1) {
                    gUnk_03002C30[i + 49].unk0 = gUnk_03002C30[i + 49].unk32;
                    gUnk_03002C30[i + 49].unk2E = 1;
                    gUnk_03002C30[i + 49].unk2 = gUnk_03002C30[i + 49].unkC_8 - gBg1Scroll.x;
                    gUnk_03002C30[i + 49].unk4 = gUnk_03002C30[i + 49].unk10_8 - gBg1Scroll.y;
                    if (gUnk_083D2B8D[gUnk_03002C30[i + 49].unk30]) {
                        gUnk_03002C30[i + 91].unk0 = 0xCC0C;
                        gUnk_03002C30[i + 91].unk2 = gUnk_03002C30[i + 49].unk2;
                        gUnk_03002C30[i + 91].unk4 =
                            gUnk_03002C30[i + 49].unk4 + (s16)(gUnk_03002C30[i + 49].unk2C - 5);
                    } else {
                        gUnk_03002C30[i + 91].unk0 = 0;
                    }
                } else {
                    gUnk_03002C30[i + 49].unk0 = 0;
                    gUnk_03002C30[i + 49].unk2E = 0;
                    gUnk_03002C30[i + 91].unk0 = 0;
                }
            } else {
                gUnk_03002C30[i + 49].unk0 = 0;
                gUnk_03002C30[i + 49].unk2E = 0;
                gUnk_03002C30[i + 91].unk0 = 0;
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

    x = gUnk_030057E0.unkC56 - 7;
    if (x < 0)
        x = 0;
    if (x + 15 > sub_08052960(gUnk_030057E0.unk7FE, 0) >> 1) {
        x = sub_08052960(gUnk_030057E0.unk7FE, 0) >> 1;
        x -= 15;
        if (sub_08052A04())
            x = 0;
    }
    y = gUnk_030057E0.unkC57 - 4;
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
    gUnk_03002C30[47].unk2 = gUnk_030057E0.unkC52 - gBg1Scroll.x;
    gUnk_03002C30[47].unk4 = gUnk_030057E0.unkC54 - gBg1Scroll.y;
    gUnk_03002C30[89].unk2 = gUnk_03002C30[47].unk2;
    gUnk_03002C30[89].unk4 = gUnk_03002C30[47].unk4 - 5;
}

void sub_08052B84(void) {
    gUnk_03002C30[47].unk0 = 0;
    gUnk_03002C30[89].unk0 = 0;
}

void sub_08052BA0(u8 on) {
    if (on) {
        gUnk_03002C30[47].unk0 = 0xC804;
        gUnk_03002C30[89].unk0 = 0xCC0C;
    } else {
        gUnk_03002C30[47].unk0 = on;
        gUnk_03002C30[89].unk0 = on;
    }
}

void check_and_update_battlefield_palette(void) {
    if (gUnk_030057E0.unkC5C == 1 && sub_0804803C(0) == 0) {
        gUnk_030057E0.unkC5C = gUnk_030057E0.unkC69;
        load_battle_palette_via_dma(1);
    }
}

// Returns 1 if a warp of the current area sits at (x, y); stores its high dir nibble in gUnk_03006D38.unk3.
u32 find_map_event_by_coords(u32 x, u32 y) {
    u32 found = 0;
    const struct AreaWarp *w = gUnk_08413114[gUnk_030057E0.unk7FE];
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
        if (gUnk_030057E0.unkC54 - gUnk_030057E0.unkC4A == 0)
            ret = 1;
        break;
    case 1:
        if (gUnk_030057E0.unkC54 - gUnk_030057E0.unkC4A + 16 == gUnk_030057E0.unk802 * 8)
            ret = 1;
        break;
    case 2:
        if (gUnk_030057E0.unkC52 - gUnk_030057E0.unkC48 == 0)
            ret = 1;
        break;
    case 3:
        if (gUnk_030057E0.unkC52 - gUnk_030057E0.unkC48 + 16 == gUnk_030057E0.unk800 * 8)
            ret = 1;
        break;
    }
    if (ret)
        field_set_player_facing(dir);
    return ret;
}

void set_sprite_animation_state(u8 idx, u8 state) {
    gUnk_03002C30[idx].unk20 = state;
    gUnk_03002C30[idx].unk21 = state;
    switch (state) {
    case 0:
        gUnk_03002C30[idx].unk6 = gUnk_03002C30[idx].unk2B * 12;
        break;
    case 1:
        gUnk_03002C30[idx].unk6 = gUnk_03002C30[idx].unk2B * 12 + 3;
        break;
    case 2:
        gUnk_03002C30[idx].unk6 = gUnk_03002C30[idx].unk2B * 12 + 6;
        break;
    case 3:
        gUnk_03002C30[idx].unk6 = gUnk_03002C30[idx].unk2B * 12 + 9;
        break;
    }
}

// Player facing (0 up, 1 down, 2 left, 3 right); sprite 47 is the player.
void field_set_player_facing(u8 dir) {
    gUnk_030057E0.unkC67 = dir;
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
    const struct AreaWarp *w = gUnk_08413114[area];
    s32 i;

    for (i = 0; w[i].x != 0xFF;) {
        u8 x = w[i].x;
        u8 y = w[i].y;
        if (x == gUnk_030057E0.unkC56 && y == gUnk_030057E0.unkC57) {
            gUnk_030057E0.unk7FE = w[i].area;
            field_load_area_tiles(gUnk_030057E0.unk7FE);
            field_set_player_facing(w[i].dir & 7);
            gUnk_030057E0.unkC52 = (w[i].destX << 4) + gUnk_030057E0.unkC48;
            gUnk_030057E0.unkC54 = (w[i].destY << 4) + gUnk_030057E0.unkC4A;
            gUnk_030057E0.unkC56 = sub_080526F0(gUnk_030057E0.unkC52);
            gUnk_030057E0.unkC57 = sub_08052714(gUnk_030057E0.unkC54);
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
        init_battle_sprite_entry_08048818(48, 0xC804, gUnk_030057E0.unkC84 * 12 + gUnk_030057E0.unkC83,
                                          gUnk_030057E0.unkC84, 1);
        gUnk_03002C30[48].unkB = 0x40;
        gUnk_03002C30[48].unk2B = gUnk_030057E0.unkC84;
        set_battle_state_byte_c83(gUnk_030057E0.unkC83);
        sub_080493D4(48, sub_080502B4(48, gUnk_030057E0.unkC83));
        gUnk_030057E0.unkC72 = sub_080526F0(gUnk_030057E0.unkC6E);
        gUnk_030057E0.unkC73 = sub_08052714(gUnk_030057E0.unkC70);
        gUnk_03002C30[48].unk30 = resolve_tile_from_battle_state(gUnk_03002C30[48].unk2B);
        sub_0804877C(48);
        init_battle_sprite_entry_08048818(90, 0xCC0C, 0x90, 14, 1);
        gUnk_03002C30[90].unkC_8 = gUnk_030057E0.unkC6E;
        gUnk_03002C30[90].unk10_8 = gUnk_030057E0.unkC70 - 5;
        gUnk_03002C30[90].unk2 = gUnk_03002C30[48].unk2;
        gUnk_03002C30[90].unk4 = gUnk_03002C30[48].unk4 - 5;
    }
}

void update_cursor_tile_position(void) {
    if (gUnk_030057E0.unkC76) {
        gUnk_030057E0.unkC6E = gUnk_030057E0.unkC52;
        gUnk_030057E0.unkC70 = gUnk_030057E0.unkC54;
        gUnk_030057E0.unkC72 = sub_080526F0(gUnk_030057E0.unkC6E);
        gUnk_030057E0.unkC73 = sub_08052714(gUnk_030057E0.unkC70);
        set_battle_state_byte_c83(gUnk_03002C30[47].unk20);
    }
}

void update_bg_scroll_offsets_b(void) {
    gUnk_03002C30[48].unk2 = gUnk_030057E0.unkC6E - gBg1Scroll.x;
    gUnk_03002C30[48].unk4 = gUnk_030057E0.unkC70 - gBg1Scroll.y;
    gUnk_03002C30[90].unk2 = gUnk_03002C30[48].unk2;
    gUnk_03002C30[90].unk4 = gUnk_03002C30[48].unk4 - 5;
}

void sub_0805311C(u16 id) {
    if (!(id & 1)) {
        u8 *flags = gUnk_030057D8;
        flags[id >> 1] &= 0x7F;
    } else {
        u8 *flags = gUnk_030057D8;
        flags[id >> 1] &= 0xF7;
    }
}

void sub_08053154(u16 id) {
    if (!(id & 1)) {
        u8 *flags = gUnk_030057D8;
        flags[id >> 1] = (flags[id >> 1] & 0x7F) | 0x80;
    } else {
        u8 *flags = gUnk_030057D8;
        flags[id >> 1] = (flags[id >> 1] & 0xF7) | 0x08;
    }
}

u32 sub_08053194(u16 id) {
    if (!(id & 1)) {
        u8 *flags = gUnk_030057D8;
        return (u8)(flags[id >> 1] & 0x80) >> 7;
    } else {
        u8 *flags = gUnk_030057D8;
        return (u8)(flags[id >> 1] & 0x08) >> 3;
    }
}

void sub_080531D0(u16 id, u8 val) {
    if (val == 0)
        sub_0805311C(id);
    else
        sub_08053154(id);
}

void sub_080531EC(u16 id, u8 val) {
    if (!(id & 1)) {
        u8 *flags = gUnk_030057D8;
        flags[id >> 1] = (flags[id >> 1] & 0x8F) | (val << 4);
    } else {
        u8 *flags = gUnk_030057D8;
        flags[id >> 1] = (flags[id >> 1] & 0xF8) | val;
    }
}

void sub_08053234(u16 id) {
    u8 n;

    if (!(id & 1)) {
        u8 *flags = gUnk_030057D8;
        n = (flags[id >> 1] & 0x70) >> 4;
        n++;
        flags[id >> 1] = (flags[id >> 1] & 0x8F) | (n << 4);
    } else {
        u8 *flags = gUnk_030057D8;
        n = flags[id >> 1] & 7;
        n++;
        flags[id >> 1] = (flags[id >> 1] & 0xF8) | n;
    }
}

u32 sub_08053288(u16 id) {
    if (!(id & 1)) {
        u8 *flags = gUnk_030057D8;
        return (flags[id >> 1] & 0x70) >> 4;
    } else {
        u8 *flags = gUnk_030057D8;
        return flags[id >> 1] & 7;
    }
}

void load_battle_terrain_data(void) {
    memcpy_u8(gUnk_083D2918[gUnk_030057E0.unkC28], gUnk_030057E0.unkC10, 8);
    gUnk_03002C30[47].unk2A = gUnk_083D2908[gUnk_030057E0.unkC5C];
}

float float_default_to_one_if_zero(float x) {
    if (x == 0.0f)
        x = 1.0f;
    return x;
}

float float_sign(float x) {
    if (x < 0.0f)
        return -1.0f;
    return 1.0f;
}

float float_abs_if_negative(float x) {
    if (x < 0.0f)
        x *= -1.0f;
    return x;
}

double compute_sqrt_scaled(double x) {
    return (u16)Sqrt((s32)x << 3) >> 3;
}

void init_sprite_affine_matrices_and_state(u32 flags, u32 x, u32 y, u32 d) {
    s32 i;

    sub_080492CC();
    for (i = 0; i < 32; i++)
        calculate_oam_affine_matrix(i);
    sub_080496C8((u8 *)&gUnk_03005350, 0x240);
    gUnk_03005350.unk1D4 = flags;
    if (flags & 0x40) {
        x = gUnk_030057E0.unkC52;
        y = gUnk_030057E0.unkC54;
    }
    gUnk_03005350.unk1D8 = x;
    gUnk_03005350.unk1DC = y;
    gUnk_03005350.unk1E0 = d;
}

void sub_08053418(void) {
    sub_0805378C();
    gUnk_03005350.unkA4[0] = gUnk_03005350.unk1D8 - gBg1Scroll.x - 0x70;
    gUnk_03005350.unkA4[1] = gUnk_03005350.unk1DC - gBg1Scroll.y - 0x50;
    sub_080496C8((u8 *)gUnk_03006D30, 0x3000);
}

void compute_distance_to_state_position(float *xs, float *ys, float *zs) {
    float a, b, c, d;
    float px, py, pz;
    float x, y, z;
    float dx, dy, dz;
    float dist;

    compute_plane_from_points(xs, ys, zs, &a, &b, &c, &d);
    x = *xs;
    y = *ys;
    z = *zs;
    get_state_position_xyz(&px, &py, &pz);
    dx = x - px;
    dy = y - py;
    dz = z - pz;
    dist = dx * dx + dy * dy + dz * dz;
    dist = compute_sqrt_scaled(dist);
    if (dist == 0.0f)
        dist = 1.0f;
    Div((s32)dx, (s32)dist);
    Div((s32)dy, (s32)dist);
    Div((s32)dz, (s32)dist);
    if (dist < 10000.0f)
        sub_08053AB8(xs, ys, zs);
}

// x, y, z: the three points' coordinates (x[i], y[i], z[i] = point i).
// Outputs the plane through them: normal (a, b, c) scaled to integers, and d.
void compute_plane_from_points(float *x, float *y, float *z, float *a, float *b, float *c, float *d) {
    float nx, ny, nz, len;

    nx = y[0] * (z[1] - z[2]) + y[1] * (z[2] - z[0]) + y[2] * (z[0] - z[1]);
    ny = z[0] * (x[1] - x[2]) + z[1] * (x[2] - x[0]) + z[2] * (x[0] - x[1]);
    nz = x[0] * (y[1] - y[2]) + x[1] * (y[2] - y[0]) + x[2] * (y[0] - y[1]);
    len = nx * nx + ny * ny + nz * nz;
    len = compute_sqrt_scaled(len);
    if (len == 0.0f)
        len = 1.0f;
    nx = Div(nx, len);
    ny = Div(ny, len);
    nz = Div(nz, len);
    *a = nx;
    *b = ny;
    *c = nz;
    *d = -(nx * x[0] + ny * y[0] + nz * z[0]);
}

void get_state_position_xyz(float *x, float *y, float *z) {
    *x = gUnk_03005350.unk40;
    *y = gUnk_03005350.unk44;
    *z = gUnk_03005350.unk48;
}

void sub_0805378C(void) {
    sub_08053798();
}

void sub_08053798(void) {
    s32 zero;

    gUnk_03005350.unk0 = 240;
    gUnk_03005350.unk4 = 160;
    zero = 0;
    gUnk_03005350.unk8 = 120;
    gUnk_03005350.unkC = 80;
    affine_set_destination_and_compute_transform(-120.5f, 120.5f, -80.5f, 80.5f);
    affine_set_source_and_compute_transform(-120.5f, 120.5f, -80.5f, 80.5f);
    gUnk_03005350.unkB4 = zero;
    gUnk_03005350.unkB8 = zero;
}

void affine_set_destination_and_compute_transform(float x0, float x1, float y0, float y1) {
    gUnk_03005350.unk10 = x0;
    gUnk_03005350.unk14 = x1;
    gUnk_03005350.unk18 = y0;
    gUnk_03005350.unk1C = y1;
    gUnk_03005350.unk30 = (gUnk_03005350.unk24 - gUnk_03005350.unk20) / (x1 - x0);
    gUnk_03005350.unk34 = (gUnk_03005350.unk2C - gUnk_03005350.unk28) / (y1 - y0);
    gUnk_03005350.unk38 = (x1 * gUnk_03005350.unk20 - x0 * gUnk_03005350.unk24) / (x1 - x0);
    gUnk_03005350.unk3C = (y1 * gUnk_03005350.unk28 - y0 * gUnk_03005350.unk2C) / (y1 - y0);
}

void affine_set_source_and_compute_transform(float x0, float x1, float y0, float y1) {
    gUnk_03005350.unk20 = x0;
    gUnk_03005350.unk24 = x1;
    gUnk_03005350.unk28 = y0;
    gUnk_03005350.unk2C = y1;
    gUnk_03005350.unk30 = (x1 - x0) / (gUnk_03005350.unk14 - gUnk_03005350.unk10);
    gUnk_03005350.unk34 = (y1 - y0) / (gUnk_03005350.unk1C - gUnk_03005350.unk18);
    gUnk_03005350.unk38 =
        (gUnk_03005350.unk14 * x0 - gUnk_03005350.unk10 * x1) / (gUnk_03005350.unk14 - gUnk_03005350.unk10);
    gUnk_03005350.unk3C =
        (gUnk_03005350.unk1C * y0 - gUnk_03005350.unk18 * y1) / (gUnk_03005350.unk1C - gUnk_03005350.unk18);
}

void set_state_float_field(float a, float b, float c, float d) {
    float x, y, z, len;

    gUnk_03005350.unk4C = c;
    gUnk_03005350.unkA0 = d;
    gUnk_03005350.unk50 = gUnk_083D6EA0[(s32)a & 0xFF];
    gUnk_03005350.unk54 = gUnk_083D72A0[(s32)a & 0xFF];
    gUnk_03005350.unk58 = gUnk_083D6EA0[(s32)b & 0xFF];
    gUnk_03005350.unk5C = gUnk_083D72A0[(s32)b & 0xFF];
    x = gUnk_03005350.unk58 * gUnk_03005350.unk50;
    y = gUnk_03005350.unk58 * gUnk_03005350.unk54;
    z = gUnk_03005350.unk5C;
    len = compute_sqrt_scaled(x * x + y * y + z * z);
    if (len == 0.0f)
        len = 1.0f;
    x = Div(x, len);
    y = Div(y, len);
    z = Div(z, len);
    gUnk_03005350.unk40 = c * x;
    gUnk_03005350.unk44 = c * y;
    gUnk_03005350.unk48 = c * z;
}

void sub_08053AB8(float *x, float *y, float *z) {
    float a, b, c;
    s32 i;

    a = x[0];
    b = y[0];
    c = z[0];
    sub_08053B94(a, b, c);
    for (i = 1; i < gUnk_03005350.unk1D0; i++) {
        a = x[i];
        b = y[i];
        c = z[i];
        gUnk_03006D30[gUnk_03005350.unk1CC].unk20C = i;
        update_battle_entity_screen_position(a, b, c);
    }
    a = x[0];
    b = y[0];
    c = z[0];
    gUnk_03006D30[gUnk_03005350.unk1CC].unk20C = 0;
    update_battle_entity_screen_position(a, b, c);
}

void sub_08053B94(float a, float b, float c) {
    float x, y, z;

    compute_3d_transform_vectors(a, b, c, &x, &y, &z);
    sub_08053BB4(x, y);
}

void sub_08053BB4(float a, float b) {
    get_state_float_as_int(a, b, &gUnk_03005350.unkB4, &gUnk_03005350.unkB8);
}

void update_battle_entity_screen_position(float x, float y, float z) {
    float sx, sy, depth;
    struct Unk_03002C30 *sprites;

    compute_3d_transform_vectors(x, y, z, &sx, &sy, &depth);
    update_entity_position_and_triggers(sx, sy);
    sprites = gUnk_03002C30;
    sprites[gUnk_03006D30[gUnk_03005350.unk1CC].unk2DC[gUnk_03006D30[gUnk_03005350.unk1CC].unk20C]].unk14_8 = depth;
}

void compute_3d_transform_vectors(float x, float y, float z, float *outX, float *outY, float *outZ) {
    float rx, ry, rz, d;

    rx = x * gUnk_03005350.unk50 + y * gUnk_03005350.unk54;
    ry = -x * gUnk_03005350.unk54 + y * gUnk_03005350.unk50;
    rz = z * gUnk_03005350.unk58 - rx * gUnk_03005350.unk5C;
    d = gUnk_03005350.unk4C - (rx * gUnk_03005350.unk58 + z * gUnk_03005350.unk5C);
    if (d == 0.0f)
        d = 1.0f;
    rx = gUnk_03005350.unkA0 / d;
    *outX = ry * rx;
    *outY = rz * rx;
    *outZ = d;
}

void get_state_float_as_int(float a, float b, s32 *x, s32 *y) {
    *x = (s32)gUnk_03005350.unk30 * (s32)a + (s32)gUnk_03005350.unk38 + gUnk_03005350.unk8;
    *y = gUnk_03005350.unkC - ((s32)gUnk_03005350.unk34 * (s32)b + (s32)gUnk_03005350.unk3C);
}

#define CUR_ENTITY gUnk_03006D30[gUnk_03005350.unk1CC]

void update_entity_position_and_triggers(float a, float b) {
    get_state_float_as_int(a, b, &gUnk_03005350.unkB4, &gUnk_03005350.unkB8);
    gUnk_03002C30[CUR_ENTITY.unk2DC[CUR_ENTITY.unk20C]].unk2 =
        gUnk_03005350.unkB4 + CUR_ENTITY.unk2E0[CUR_ENTITY.unk20C];
    gUnk_03002C30[CUR_ENTITY.unk2DC[CUR_ENTITY.unk20C]].unk4 =
        gUnk_03005350.unkB8 + CUR_ENTITY.unk2E8[CUR_ENTITY.unk20C];
    if (CUR_ENTITY.unk1EC && (u8)gUnk_03005350.unkB8 >= CUR_ENTITY.unk1F0 &&
        (u8)gUnk_03005350.unkB8 <= CUR_ENTITY.unk1F4) {
        CUR_ENTITY.unk0 = 2;
        CUR_ENTITY.unkAC = 0;
    }
    if (CUR_ENTITY.unk1E0 && (s32)(gUnk_03005350.unkB4 & 0x1FF) >= CUR_ENTITY.unk1E4 &&
        (s32)(gUnk_03005350.unkB4 & 0x1FF) <= CUR_ENTITY.unk1E8) {
        CUR_ENTITY.unk0 = 2;
        CUR_ENTITY.unk64 = 0;
        CUR_ENTITY.unk1C = 0;
    }
    if (CUR_ENTITY.unk1F8) {
        if (CUR_ENTITY.unkA0 <= CUR_ENTITY.unk1FC) {
            CUR_ENTITY.unk0 = 2;
            CUR_ENTITY.unkAC = 0;
        }
        if (CUR_ENTITY.unkA0 >= CUR_ENTITY.unk200) {
            CUR_ENTITY.unk0 = 2;
            CUR_ENTITY.unkAC = 0;
        }
    }
}

void init_affine_transform_viewport(s32 x, s32 y) {
    gUnk_03005350.unk0 = 240;
    gUnk_03005350.unk4 = 160;
    gUnk_03005350.unk8 = x + 120;
    gUnk_03005350.unkC = y + 80;
    affine_set_destination_and_compute_transform(-120.5f, 120.5f, -80.5f, 80.5f);
    affine_set_source_and_compute_transform(-120.5f, 120.5f, -80.5f, 80.5f);
}

void update_3d_entity_projections(void) {
    s32 i, j;
    const s32 *p;
    const s32 *q;

    gUnk_03005350.unk0 = 240;
    gUnk_03005350.unk4 = 160;
    affine_set_destination_and_compute_transform(-120.5f, 120.5f, -80.5f, 80.5f);
    affine_set_source_and_compute_transform(-120.5f, 120.5f, -80.5f, 80.5f);
    init_affine_transform_viewport(gUnk_03005350.unkA4[0], gUnk_03005350.unkA4[1]);
    for (i = 0; i < 16; i++) {
        if (gUnk_03006D30[i].unk0 == 0)
            continue;
        if (gUnk_03006D30[i].unk4 < gUnk_03006D30[i].unk8)
            continue;
        if (gUnk_03006D30[i].unk1C0 == 0)
            continue;
        if (gUnk_03006D30[i].unk1C4 < gUnk_03006D30[i].unk1C8)
            continue;
        p = gUnk_083D2DB0[gUnk_03005350.unkF8][i];
        q = p;
        gUnk_03005350.unk1D0 = *q++;
        for (j = 0; j < 4; j++) {
            gUnk_03005350.unkC0[j] = q[0];
            gUnk_03005350.unkD0[j] = q[4];
            gUnk_03005350.unkE0[j] = q[8];
            q++;
        }
        set_state_float_field(gUnk_03005350.unk90 + gUnk_03006D30[i].unkF8,
                              gUnk_03005350.unk94 + gUnk_03006D30[i].unk110, gUnk_03005350.unk9C, gUnk_03005350.unkA0);
        for (j = 0; j < 4; j++) {
            gUnk_03005350.unk60[j] = gUnk_03005350.unkC0[j] * gUnk_03006D30[i].unk164 + gUnk_03006D30[i].unk10;
            gUnk_03005350.unk70[j] = gUnk_03005350.unkD0[j] * gUnk_03006D30[i].unk17C + gUnk_03006D30[i].unk58;
            gUnk_03005350.unk80[j] = gUnk_03005350.unkE0[j] * gUnk_03006D30[i].unk194 + gUnk_03006D30[i].unkA0;
        }
        gUnk_03005350.unk98 = p[1];
        gUnk_03005350.unk1CC = i;
        compute_distance_to_state_position(gUnk_03005350.unk60, gUnk_03005350.unk70, gUnk_03005350.unk80);
    }
}

#define S (*(struct SeqState *)&gUnk_03005350)
#define E ((struct SeqEntity *)gUnk_03006D30)

// Battle 3-D sequence script interpreter (guess). Runs the script picked by unk1D4 & 0x3F until an opcode
// returns control: 0 (script end), 1, 2 (wait a frame) or 4 (finished).
u32 battle_sequence_dispatch(void) {
    s32 *script;
    s32 buf[16];
    u32 zero;
    s32 x, y, attr;
    s32 i;
    s32 done;
    s32 cnt;
    s32 tmp;
    struct AnimInterp *anim;
    struct SeqTrack *trk;
    struct SeqOsc *osc;
    struct SeqRamp *ramp;
    s32 j, k;
    s32 n;
    s32 flag;
    s32 part;
    s32 v, a, b;
    s32 d;
    const s32 *model;
    u16 color;
    s32 r, g, bl;

    S.unkF0 = 1;
    S.unkF8 = S.unk1D4 & 0x3F;
    script = gUnk_083D5D84[S.unkF8];
    while (1) {
        switch (S.unkF4 = script[S.unkFC]) {
        case 0: // guess: end of script (return 0); 4 = finish (reset, rebuild the field), 37 = nop
        case 4:
        case 37:
            break;
        case 1: // guess: init: camera distance/scale, yaw/pitch, reset entity scales
            S.unkFC++;
            S.unk9C = script[S.unkFC++];
            S.unkA0 = script[S.unkFC++];
            S.unk90 = script[S.unkFC++];
            S.unk94 = script[S.unkFC++];
            S.unk214 = 0x80;
            S.unk218 = 0;
            S.unk21C = 0x400;
            S.unk220 = 0x800;
            sub_08053418();
            for (i = 0; i < 16; i++) {
                E[i].unk160.value = 1.0f;
                E[i].unk178.value = 1.0f;
                E[i].unk190.value = 1.0f;
            }
            break;
        case 2: // guess: run one frame: fire entity triggers, step all tracks, fade; advance when an entity finished
            done = 0;
            flag = 0;
            cnt = 0;
            for (i = 0; i < 16; i++) {
                if (E[i].unk0 != 0 && E[i].unk218 != 0) {
                    for (k = 0; k < 16; k++) {
                        if (E[i].unk29C[k] != 0) {
                            cnt++;
                            if (E[i].unk4 >= E[i].unk21C[k]) {
                                S.unk184 = E[i].unk25C[k];
                                E[S.unk184].unk10.unk0 = E[i].unk10.unk0;
                                E[S.unk184].unk58.unk0 = E[i].unk58.unk0;
                                E[S.unk184].unkA0.unk0 = E[i].unkA0.unk0;
                                S.unk144[S.unk140] = script;
                                script = E[i].unk29C[k];
                                S.unk100[S.unk140] = S.unkFC;
                                S.unk140++;
                                S.unkFC = 0;
                                S.unkF4 = script[0];
                                E[i].unk29C[k] = 0;
                                flag = 1;
                            }
                            if (flag)
                                break;
                        }
                        if (flag)
                            break;
                    }
                    if (cnt == 0)
                        E[i].unk218 = 0;
                }
            }
            if (flag)
                break;
            for (i = 0; i < 16; i++) {
                if (E[i].unk0 == 0)
                    continue;
                if (E[i].unk8 <= E[i].unk4) {
                    for (k = 0; k < 3; k++) {
                        if (k == 0)
                            anim = &E[i].unk10;
                        else if (k == 1)
                            anim = &E[i].unk58;
                        else if (k == 2)
                            anim = &E[i].unkA0;
                        animation_interpolation_step(anim);
                    }
                    for (k = 0; k < 2; k++) {
                        if (k == 0)
                            trk = &E[i].unkE8;
                        else if (k == 1)
                            trk = &E[i].unk100;
                        if (trk->active) {
                            if (trk->start <= trk->timer) {
                                trk->value = trk->value + trk->step;
                                trk->timer++;
                                if (trk->end != 0xFFFF && trk->timer >= trk->end)
                                    trk->active = 0;
                            } else
                                trk->timer++;
                        }
                    }
                    for (j = 0; j < 2; j++) {
                        if (j == 0)
                            osc = &E[i].unk118;
                        else if (j == 1)
                            osc = &E[i].unk13C;
                        if (osc->type != 0) {
                            if (osc->start <= osc->timer) {
                                if (osc->type == 1) {
                                    osc->value = osc->value + osc->amp;
                                    for (k = 0; k < 4; k++) {
                                        if (j == 0)
                                            gUnk_03006D40[i * 4 + k].scaleX = osc->value;
                                        else if (j == 1)
                                            gUnk_03006D40[i * 4 + k].scaleY = osc->value;
                                    }
                                } else if (osc->type == 2) {
                                    osc->value = osc->amp * gSineTable[(s32)osc->angle & 0xFF];
                                    for (k = 0; k < 4; k++) {
                                        if (j == 0)
                                            gUnk_03006D40[i * 4 + k].scaleX = osc->value;
                                        else if (j == 1)
                                            gUnk_03006D40[i * 4 + k].scaleY = osc->value;
                                    }
                                    osc->angle = osc->angle + osc->angleStep;
                                } else if (osc->type == 3) {
                                    osc->value = osc->amp * gSineTable[((s32)osc->angle & 0xFF) + 0x40];
                                    for (k = 0; k < 4; k++) {
                                        if (j == 0)
                                            gUnk_03006D40[i * 4 + k].scaleX = osc->value;
                                        else if (j == 1)
                                            gUnk_03006D40[i * 4 + k].scaleY = osc->value;
                                    }
                                    osc->angle = osc->angle + osc->angleStep;
                                }
                                osc->timer++;
                                if (osc->end != 0xFFFF && osc->timer >= osc->end)
                                    osc->type = 4;
                            } else
                                osc->timer++;
                        }
                    }
                    for (k = 0; k < 3; k++) {
                        if (k == 0)
                            ramp = &E[i].unk160;
                        else if (k == 1)
                            ramp = &E[i].unk178;
                        else if (k == 2)
                            ramp = &E[i].unk190;
                        if (ramp->active) {
                            if (ramp->start <= ramp->timer) {
                                ramp->value = ramp->value + ramp->step;
                                ramp->timer++;
                                if (ramp->end != 0xFFFF && ramp->timer >= ramp->end)
                                    ramp->active = 0;
                            } else
                                ramp->timer++;
                        }
                    }
                    if (E[i].unk1A8.active) {
                        if (E[i].unk1A8.start <= E[i].unk1A8.timer) {
                            E[i].unk1A8.value = E[i].unk1A8.value + E[i].unk1A8.step;
                            for (k = 0; k < 4; k++)
                                gUnk_03006D40[i * 4 + k].angle = (s32)E[i].unk1A8.value & 0xFF;
                            E[i].unk1A8.timer++;
                            if (E[i].unk1A8.end != 0xFFFF && E[i].unk1A8.timer >= E[i].unk1A8.end)
                                E[i].unk1A8.active = 0;
                        } else
                            E[i].unk1A8.timer++;
                    }
                    if (E[i].unk208) {
                        for (k = 0; k < E[i].unk210; k++)
                            advance_sprite_animation_frame(E[i].unk2DC[k]);
                    }
                    if (E[i].unk1C0.active) {
                        if (E[i].unk1C0.start <= E[i].unk1C0.timer) {
                            for (k = 0; k < E[i].unk210; k++)
                                gUnk_03002C30[E[i].unk2DC[k]].unk0 |= 0x4000;
                            E[i].unk1C0.timer++;
                            if (E[i].unk1C0.end != 0xFFFF && E[i].unk1C0.timer >= E[i].unk1C0.end) {
                                for (k = 0; k < E[i].unk210; k++)
                                    clear_battle_sprite_entry(E[i].unk2DC[k]);
                                E[i].unk1C0.active = 0;
                                E[i].unk208 = 0;
                            }
                        } else
                            E[i].unk1C0.timer++;
                    }
                    if (E[i].unk1D0.active) {
                        if (E[i].unk1D0.start <= E[i].unk1D0.timer) {
                            if (!(E[i].unk1D0.timer & 1)) {
                                for (k = 0; k < E[i].unk210; k++)
                                    gUnk_03002C30[E[i].unk2DC[k]].unk0 &= ~0x4000;
                            } else {
                                for (k = 0; k < E[i].unk210; k++)
                                    gUnk_03002C30[E[i].unk2DC[k]].unk0 |= 0x4000;
                            }
                            E[i].unk1D0.timer++;
                            if (E[i].unk1D0.end != 0xFFFF && E[i].unk1D0.timer >= E[i].unk1D0.end)
                                E[i].unk1D0.active = 0;
                        } else
                            E[i].unk1D0.timer++;
                    }
                    if (E[i].unk2EC.active) {
                        if (E[i].unk2EC.start <= E[i].unk2EC.timer) {
                            sub_08047BA8(E[i].unk2FC);
                            E[i].unk2EC.timer++;
                            if (E[i].unk2EC.end != 0xFFFF && E[i].unk2EC.timer >= E[i].unk2EC.end)
                                E[i].unk2EC.active = 0;
                        } else
                            E[i].unk2EC.timer++;
                    }
                    E[i].unk4++;
                    if (E[i].unkC != 0xFFFF && E[i].unk4 >= E[i].unkC)
                        done++;
                } else
                    E[i].unk4++;
            }
            update_3d_entity_projections();
            for (i = 0; i < 16; i++) {
                if (E[i].unk0 == 2)
                    done++;
            }
            for (i = 0; i < 16; i++) {
                if (E[i].unk0 != 0 && (E[i].unk118.type | E[i].unk13C.type) == 0) {
                    for (k = 0; k < 4; k++) {
                        d = gUnk_03002C30[E[i].unk2DC[k]].unk14_8;
                        if (d > S.unk9C) {
                            gUnk_03006D40[i * 4 + k].scaleX = 0x101 - d / S.unk9C;
                            gUnk_03006D40[i * 4 + k].scaleY = 0x101 - gUnk_03002C30[E[i].unk2DC[k]].unk14_8 / S.unk9C;
                        } else {
                            gUnk_03006D40[i * 4 + k].scaleX = S.unk9C / d + 0xFF;
                            gUnk_03006D40[i * 4 + k].scaleY = S.unk9C / gUnk_03002C30[E[i].unk2DC[k]].unk14_8 + 0xFF;
                        }
                    }
                }
            }
            update_battle_sprite_status_effects();
            if (S.unk1F4 != 0) {
                if (S.unk200 <= S.unk1FC) {
                    S.unk1FC++;
                    switch (S.unk1F4) {
                    case 1:
                        if (run_blend_fade_transition(0x7FFF)) {
                            S.unk1F4 = 0;
                            done++;
                        }
                        break;
                    case 2:
                        if (run_blend_fade_transition(0x7FFF)) {
                            S.unk1F4 = 0;
                            done++;
                        }
                        break;
                    case 3:
                        blend_effect_update();
                        sub_08049E74(S.unk210 << 10 | S.unk20F << 5 | S.unk20E, S.unk208 * S.unk1F8, S.unk20A);
                        sub_08049E88(S.unk210 << 10 | S.unk20F << 5 | S.unk20E, S.unk208 * S.unk1F8, S.unk20C);
                        if (S.unk208 < 0x20 / S.unk1F8)
                            S.unk208++;
                        else {
                            gVBlankCallback = nullsub_08000840;
                            S.unk1F4 = 0;
                            done++;
                        }
                        break;
                    case 4:
                        blend_effect_update();
                        r = S.unk208 * S.unk1F8 - 1;
                        g = r;
                        bl = r;
                        if (r < S.unk20E)
                            r = S.unk20E;
                        if (g < S.unk20F)
                            g = S.unk20F;
                        if (bl < S.unk210)
                            bl = S.unk210;
                        color = bl << 10 | g << 5 | r;
                        sub_08049E74(color, S.unk208 * S.unk1F8, S.unk20A);
                        sub_08049E88(color, S.unk208 * S.unk1F8, S.unk20C);
                        if (S.unk208 != 0)
                            S.unk208--;
                        else {
                            gVBlankCallback = nullsub_08000840;
                            S.unk1F4 = 0;
                            done++;
                        }
                        break;
                    }
                    if (S.unk204 != 0xFFFF && S.unk1FC >= S.unk204) {
                        gVBlankCallback = nullsub_08000840;
                        S.unk1F4 = 0;
                        done++;
                    }
                } else
                    S.unk1FC++;
            }
            if (done == 0)
                break;
            if (S.unk1F4 != 0)
                break;
            S.unkFC++;
            S.unkF4 = script[S.unkFC];
            break;
        case 3: // guess: set current entity state/timer/start/end
            S.unkFC++;
            S.unkFC++;
            n = S.unk184;
            E[n].unk0 = script[S.unkFC++];
            E[n].unk4 = script[S.unkFC++];
            E[n].unk8 = script[S.unkFC++];
            E[n].unkC = script[S.unkFC++];
            break;
        case 5: // guess: skip one argument
            S.unkFC++;
            S.unkFC++;
            break;
        case 6: // guess: set x (absolute or relative to the parent entity)
            S.unkFC++;
            S.unkFC++;
            n = S.unk184;
            if (script[S.unkFC++] == 0)
                E[n].unk10.unk0 = script[S.unkFC++];
            else
                E[n].unk10.unk0 = script[S.unkFC++] + E[E[n].unk214].unk10.unk0;
            break;
        case 7: // guess: set y (absolute or relative to the parent entity)
            S.unkFC++;
            S.unkFC++;
            n = S.unk184;
            if (script[S.unkFC++] == 0)
                E[n].unk58.unk0 = script[S.unkFC++];
            else
                E[n].unk58.unk0 = script[S.unkFC++] + E[E[n].unk214].unk58.unk0;
            break;
        case 8: // guess: set z (absolute or relative to the parent entity)
            S.unkFC++;
            S.unkFC++;
            n = S.unk184;
            if (script[S.unkFC++] == 0)
                E[n].unkA0.unk0 = script[S.unkFC++];
            else
                E[n].unkA0.unk0 = script[S.unkFC++] + E[E[n].unk214].unkA0.unk0;
            break;
        case 9: // guess: set yaw
            S.unkFC++;
            S.unkFC++;
            n = S.unk184;
            E[n].unkE8.value = script[S.unkFC++];
            break;
        case 10: // guess: set pitch
            S.unkFC++;
            S.unkFC++;
            n = S.unk184;
            E[n].unk100.value = script[S.unkFC++];
            break;
        case 11: // guess: set affine x-scale oscillator type/value
            S.unkFC++;
            S.unkFC++;
            n = S.unk184;
            E[n].unk118.type = script[S.unkFC++];
            E[n].unk118.value = script[S.unkFC++];
            if (E[n].unk118.type == 0)
                break;
            for (k = 0; k < 4; k++)
                gUnk_03006D40[n * 4 + k].scaleX = E[n].unk118.value;
            break;
        case 12: // guess: set affine y-scale oscillator type/value
            S.unkFC++;
            S.unkFC++;
            n = S.unk184;
            E[n].unk13C.type = script[S.unkFC++];
            E[n].unk13C.value = script[S.unkFC++];
            if (E[n].unk13C.type == 0)
                break;
            for (k = 0; k < 4; k++)
                gUnk_03006D40[n * 4 + k].scaleY = E[n].unk13C.value;
            break;
        case 13: // guess: set 3-D scale x
            S.unkFC++;
            S.unkFC++;
            n = S.unk184;
            E[n].unk160.value = script[S.unkFC++];
            break;
        case 14: // guess: set 3-D scale y
            S.unkFC++;
            S.unkFC++;
            n = S.unk184;
            E[n].unk178.value = script[S.unkFC++];
            break;
        case 15: // guess: set 3-D scale z
            S.unkFC++;
            S.unkFC++;
            n = S.unk184;
            E[n].unk190.value = script[S.unkFC++];
            break;
        case 16: // guess: set up x/y/z interpolation (16 words)
        case 17:
        case 18:
            S.unkFC++;
            S.unkFC++;
            n = S.unk184;
            if (S.unkF4 == 0x10)
                anim = &E[n].unk10;
            else if (S.unkF4 == 0x11)
                anim = &E[n].unk58;
            else if (S.unkF4 == 0x12)
                anim = &E[n].unkA0;
            memcpy_u8(&script[S.unkFC], buf, 0x40);
            S.unkFC += 0x10;
            sub_0805689C(anim, buf);
            break;
        case 23: // guess: 3-D scale x ramp
            S.unkFC++;
            S.unkFC++;
            n = S.unk184;
            E[n].unk160.active = script[S.unkFC++];
            E[n].unk160.step = script[S.unkFC++] / 10.0f;
            E[n].unk160.timer = script[S.unkFC++];
            E[n].unk160.start = script[S.unkFC++];
            E[n].unk160.end = script[S.unkFC++];
            break;
        case 24: // guess: 3-D scale y ramp
            S.unkFC++;
            S.unkFC++;
            n = S.unk184;
            E[n].unk178.active = script[S.unkFC++];
            E[n].unk178.step = script[S.unkFC++] / 10.0f;
            E[n].unk178.timer = script[S.unkFC++];
            E[n].unk178.start = script[S.unkFC++];
            E[n].unk178.end = script[S.unkFC++];
            break;
        case 25: // guess: 3-D scale z ramp
            S.unkFC++;
            S.unkFC++;
            n = S.unk184;
            E[n].unk190.active = script[S.unkFC++];
            E[n].unk190.step = script[S.unkFC++] / 10.0f;
            E[n].unk190.timer = script[S.unkFC++];
            E[n].unk190.start = script[S.unkFC++];
            E[n].unk190.end = script[S.unkFC++];
            break;
        case 19: // guess: yaw track
            S.unkFC++;
            S.unkFC++;
            n = S.unk184;
            E[n].unkE8.active = script[S.unkFC++];
            E[n].unkE8.step = script[S.unkFC++] * 0.125f;
            E[n].unkE8.timer = script[S.unkFC++];
            E[n].unkE8.start = script[S.unkFC++];
            E[n].unkE8.end = script[S.unkFC++];
            break;
        case 20: // guess: pitch track
            S.unkFC++;
            S.unkFC++;
            n = S.unk184;
            E[n].unk100.active = script[S.unkFC++];
            E[n].unk100.step = script[S.unkFC++] * 0.125f;
            E[n].unk100.timer = script[S.unkFC++];
            E[n].unk100.start = script[S.unkFC++];
            E[n].unk100.end = script[S.unkFC++];
            break;
        case 21: // guess: affine x-scale oscillator
            S.unkFC++;
            S.unkFC++;
            n = S.unk184;
            E[n].unk118.type = script[S.unkFC++];
            E[n].unk118.amp = script[S.unkFC++] * 0.125f;
            E[n].unk118.angle = script[S.unkFC++];
            E[n].unk118.angleStep = script[S.unkFC++];
            E[n].unk118.timer = script[S.unkFC++];
            E[n].unk118.start = script[S.unkFC++];
            E[n].unk118.end = script[S.unkFC++];
            break;
        case 22: // guess: affine y-scale oscillator
            S.unkFC++;
            S.unkFC++;
            n = S.unk184;
            E[n].unk13C.type = script[S.unkFC++];
            E[n].unk13C.amp = script[S.unkFC++] * 0.125f;
            E[n].unk13C.angle = script[S.unkFC++];
            E[n].unk13C.angleStep = script[S.unkFC++];
            E[n].unk13C.timer = script[S.unkFC++];
            E[n].unk13C.start = script[S.unkFC++];
            E[n].unk13C.end = script[S.unkFC++];
            break;
        case 26: // guess: affine angle ramp
            S.unkFC++;
            S.unkFC++;
            n = S.unk184;
            E[n].unk1A8.active = script[S.unkFC++];
            E[n].unk1A8.step = script[S.unkFC++] * 0.125f;
            E[n].unk1A8.timer = script[S.unkFC++];
            E[n].unk1A8.start = script[S.unkFC++];
            E[n].unk1A8.end = script[S.unkFC++];
            break;
        case 27: // guess: create a sprite part (gfx + palette from the script set)
            S.unkFC++;
            S.unkFC++;
            n = S.unk184;
            part = script[S.unkFC++];
            x = script[S.unkFC++];
            y = script[S.unkFC++];
            attr = script[S.unkFC++];
            model = gUnk_083D2DB0[S.unkF8][n];
            E[n].unk210 = *model;
            if (part >= *model)
                break;
            E[n].unk2DC[part] = n * 4 + part;
            E[n].unk2E0[part] = 0;
            E[n].unk2E8[part] = 0;
            LZ77UnCompVram(gUnk_0847ECC0[S.unkF8], (void *)0x06016C00);
            if (!(S.unk1D4 & 0x80))
                DmaSet(3, gUnk_0847EC40[S.unkF8], 0x050003A0, 0x84000008) else DmaSet(3, gUnk_0847EC40[S.unkF8],
                                                                                      0x0202F9A0, 0x84000008)
                    init_battle_sprite_entry_08048818(E[n].unk2DC[part], x, (u16)y, 0xD, 1);
            gUnk_03002C30[E[n].unk2DC[part]].unk0 |= attr;
            gUnk_03002C30[E[n].unk2DC[part]].filler1D[0] = n * 4 + part;
            break;
        case 134: // guess: set a sprite part (slot, offsets, attributes)
            S.unkFC++;
            S.unkFC++;
            n = S.unk184;
            part = script[S.unkFC++];
            E[n].unk2DC[part] = script[S.unkFC++];
            E[n].unk2E0[part] = script[S.unkFC++];
            E[n].unk2E8[part] = script[S.unkFC++];
            gUnk_03002C30[E[n].unk2DC[part]].unk0 = script[S.unkFC++];
            gUnk_03002C30[E[n].unk2DC[part]].filler1D[0] = n * 4 + part;
            break;
        case 28: // guess: hide timer, then free the sprites
            S.unkFC++;
            S.unkFC++;
            n = S.unk184;
            E[n].unk1C0.active = script[S.unkFC++];
            E[n].unk1C0.timer = script[S.unkFC++];
            E[n].unk1C0.start = script[S.unkFC++];
            E[n].unk1C0.end = script[S.unkFC++];
            break;
        case 29: // guess: animate sprites flag + palette
            S.unkFC++;
            S.unkFC++;
            n = S.unk184;
            E[n].unk208 = script[S.unkFC++];
            E[n].unk204 = script[S.unkFC++];
            for (k = 0; k < 4; k++)
                sub_080493D4(E[n].unk2DC[k], E[n].unk204);
            break;
        case 30: // guess: blink timer
            S.unkFC++;
            S.unkFC++;
            n = S.unk184;
            E[n].unk1D0.active = script[S.unkFC++];
            E[n].unk1D0.timer = script[S.unkFC++];
            E[n].unk1D0.start = script[S.unkFC++];
            E[n].unk1D0.end = script[S.unkFC++];
            break;
        case 31: // guess: x range check
            S.unkFC++;
            S.unkFC++;
            n = S.unk184;
            E[n].unk1E0 = script[S.unkFC++];
            E[n].unk1E4 = script[S.unkFC++];
            E[n].unk1E8 = script[S.unkFC++];
            break;
        case 32: // guess: y range check
            S.unkFC++;
            S.unkFC++;
            n = S.unk184;
            E[n].unk1EC = script[S.unkFC++];
            E[n].unk1F0 = script[S.unkFC++];
            E[n].unk1F4 = script[S.unkFC++];
            break;
        case 33: // guess: depth range check
            S.unkFC++;
            S.unkFC++;
            n = S.unk184;
            E[n].unk1F8 = script[S.unkFC++];
            E[n].unk1FC = script[S.unkFC++];
            E[n].unk200 = script[S.unkFC++];
            break;
        case 34: // guess: call: select entity, run a sub-script
            S.unkFC++;
            S.unk188[S.unk140] = script[S.unkFC++];
            S.unk184 = S.unk188[S.unk140];
            S.unk144[S.unk140] = script;
            script = (s32 *)script[S.unkFC++];
            S.unk100[S.unk140] = S.unkFC;
            S.unk140++;
            S.unkFC = 0;
            break;
        case 35: // guess: return from a sub-script
            S.unkFC++;
            S.unk140--;
            S.unkFC = S.unk100[S.unk140];
            script = S.unk144[S.unk140];
            S.unk184 = S.unk188[S.unk140];
            break;
        case 36: // guess: add a trigger: run a sub-script on another entity at a given time
        {
            s32 old;

            S.unkFC++;
            S.unk188[S.unk140] = script[S.unkFC++];
            k = S.unk188[S.unk140];
            E[S.unk184].unk25C[k] = k;
            v = script[S.unkFC++];
            E[S.unk184].unk218 = v & 0xFF;
            E[S.unk184].unk21C[k] = script[S.unkFC++];
            E[S.unk184].unk29C[k] = (s32 *)script[S.unkFC++];
            E[k].unk214 = S.unk184;
            if ((v & 0xFF00) != 0x100)
                break;
            a = script[S.unkFC++];
            b = script[S.unkFC++];
            if (a != 1)
                break;
            old = E[S.unk184].unk21C[k];
            if (b == 0)
                tmp = E[S.unk184].unkA0.unk24;
            E[S.unk184].unk21C[k] = tmp - old;
            break;
        }
        case 128: // guess: fade from white (with OBJ)
            S.unkFC++;
            S.unk1FC = script[S.unkFC++];
            S.unk200 = script[S.unkFC++];
            S.unk204 = script[S.unkFC++];
            setup_palette_fade_to_color_with_obj(0x7FFF, 0.0f, 32.0f, 8.0f);
            S.unk1F4 = 1;
            break;
        case 129: // guess: fade to white
            S.unkFC++;
            S.unk1FC = script[S.unkFC++];
            S.unk200 = script[S.unkFC++];
            S.unk204 = script[S.unkFC++];
            setup_palette_fade_to_color(0x7FFF, 32.0f, 0.0f, 8.0f);
            S.unk1F4 = 2;
            break;
        case 130: // guess: palette blend in
            S.unkFC++;
            S.unk208 = script[S.unkFC++];
            S.unk20A = script[S.unkFC++];
            S.unk20C = script[S.unkFC++];
            S.unk20E = script[S.unkFC++];
            S.unk20F = script[S.unkFC++];
            S.unk210 = script[S.unkFC++];
            S.unk1F8 = script[S.unkFC++];
            S.unk1FC = script[S.unkFC++];
            S.unk200 = script[S.unkFC++];
            S.unk204 = script[S.unkFC++];
            S.unk1F4 = 3;
            sub_08049CC0();
            setup_blend_effect(0x40, 0x2F00, 6, 8, 8, 8, 0xD, 0xB, 0);
            break;
        case 131: // guess: palette blend out
            S.unkFC++;
            S.unk208 = script[S.unkFC++];
            S.unk20A = script[S.unkFC++];
            S.unk20C = script[S.unkFC++];
            S.unk20E = script[S.unkFC++];
            S.unk20F = script[S.unkFC++];
            S.unk210 = script[S.unkFC++];
            S.unk1F8 = script[S.unkFC++];
            S.unk1FC = script[S.unkFC++];
            S.unk200 = script[S.unkFC++];
            S.unk204 = script[S.unkFC++];
            S.unk1F4 = 4;
            if (S.unk208 != 0) {
                if (S.unk208 == 0x10) {
                    sub_08049CB0(0x7FFF, 0x20);
                    gUnk_03006F40.unk24 = 32.0f;
                    gUnk_03006F40.unk2C = 0.0f;
                    setup_blend_effect(0x40, 0x2F00, 5, 8, 8, 8, 0xE, 0xC, 0);
                } else if (S.unk208 == 8)
                    setup_blend_effect(0x40, 0x2F00, 6, 8, 8, 8, 0xC, 0xA, 0);
            } else
                setup_blend_effect(0x40, 0x2F00, 4, 8, 8, 8, 0x10, 0x10, 0);
            break;
        case 132: // guess: clear the sprites and reload the field
            S.unkFC++;
            save_script_sprites();
            sub_080496C8((u8 *)gUnk_03002C30, 0x2000);
            sub_080496C8((u8 *)gUnk_030055A0, 0x200);
            zero = 0;
            DmaSet(3, &zero, OAM, 0x85000100);
            restore_script_sprites();
            if (S.unkF8 == 0x12) {
                if (gUnk_03006D38.unk5 <= 8)
                    S.unk1E0 = gUnk_083D2AAB[gUnk_03006D38.unk5];
                else
                    S.unk1E0 = 0;
                S.unk1D8 = gUnk_083D2AB4[gUnk_03006D38.unk5 * 4 + 2] << 4;
                S.unk1DC = gUnk_083D2AB4[gUnk_03006D38.unk5 * 4 + 3] << 4;
                gUnk_030057E0.unkC52 = S.unk1D8;
                gUnk_030057E0.unkC54 = S.unk1DC;
                gUnk_030057E0.unkC56 = sub_080526F0(gUnk_030057E0.unkC52);
                gUnk_030057E0.unkC57 = sub_08052714(gUnk_030057E0.unkC54);
                gUnk_030057E0.unk7FE = S.unk1E0;
                field_center_camera_on_player();
                dispatch_jump_table_29(0xC, 0);
            } else if (S.unkF8 == 0xE) {
                S.unk1E0 = gUnk_083D2AD8;
                S.unk1D8 = gUnk_083D2AD9[2] << 4;
                S.unk1DC = gUnk_083D2AD9[3] << 4;
                gUnk_030057E0.unkC52 = S.unk1D8;
                gUnk_030057E0.unkC54 = S.unk1DC;
                gUnk_030057E0.unkC56 = sub_080526F0(gUnk_030057E0.unkC52);
                gUnk_030057E0.unkC57 = sub_08052714(gUnk_030057E0.unkC54);
                gUnk_030057E0.unk7FE = S.unk1E0;
                field_center_camera_on_player();
                dispatch_jump_table_29(0xA, 0);
            }
            gUnk_030057E0.unkCBA = 1;
            update_battle_field_frame();
            load_battlefield_data_to_buffer();
            gUnk_03002C30[89].unk0 &= ~0x4000;
            break;
        case 133: // guess: set unk214..unk220
            S.unkFC++;
            S.unk214 = script[S.unkFC++];
            S.unk218 = script[S.unkFC++];
            S.unk21C = script[S.unkFC++];
            S.unk220 = script[S.unkFC++];
            break;
        case 135: // guess: set unk224..unk23C
            S.unkFC++;
            S.unk224 = script[S.unkFC++];
            S.unk228 = script[S.unkFC++];
            S.unk22C = script[S.unkFC++];
            S.unk230 = script[S.unkFC++];
            S.unk234 = script[S.unkFC++];
            S.unk238 = script[S.unkFC++];
            S.unk23C = script[S.unkFC++];
            break;
        case 137: // guess: copy z / end frames between entities
        {
            s32 src, dst;

            S.unkFC++;
            src = script[S.unkFC++];
            dst = script[S.unkFC++];
            switch (script[S.unkFC++]) {
            case 0:
                E[dst].unkA0.unk0 = E[src].unkA0.unk0;
                break;
            case 1:
                E[dst].unkC = E[src].unkA0.unk24;
                break;
            case 2:
                E[dst].unkC = E[src].unk58.unk24;
                break;
            case 3:
                E[dst].unkC = E[src].unk10.unk24;
                break;
            }
            break;
        }
        case 138: // guess: callback timer (sub_08047BA8)
            S.unkFC++;
            S.unkFC++;
            n = S.unk184;
            E[n].unk2EC.active = script[S.unkFC++];
            E[n].unk2EC.timer = script[S.unkFC++];
            E[n].unk2EC.start = script[S.unkFC++];
            E[n].unk2EC.end = script[S.unkFC++];
            E[n].unk2FC = script[S.unkFC++];
            break;
        case 136: // guess: set gUnk_030057E0.unkC4C and refresh the status chars
            S.unkFC++;
            gUnk_030057E0.unkC4C = script[S.unkFC++];
            update_battle_entity_status_chars();
            break;
        default:
            S.unkF4 = 0;
            S.unkFC = 0;
            break;
        }
        if (S.unkF4 == 0)
            break;
        if (S.unkF4 == 1)
            break;
        if (S.unkF4 == 2)
            break;
        if (S.unkF4 == 4) {
            S.unkFC = 0;
            S.unkF0 = 0;
            if ((S.unk1D4 & 0x3F) != 0xD && (S.unk1D4 & 0x3F) != 0x16) {
                s32 q;

                sub_080492CC();
                for (q = 0; q < 32; q++)
                    calculate_oam_affine_matrix(q);
            }
            if (S.unkF8 == 0xE || S.unkF8 == 0x12) {
                gUnk_030057E0.unkC67 = 1;
                set_battle_state_cancel_flag();
                init_battle_field_setup();
                update_bg_scroll_offsets_a();
                field_set_player_facing(gUnk_030057E0.unkC67);
                if (gUnk_030057E0.unkC76) {
                    set_battle_state_byte_c83(gUnk_03002C30[47].unk20);
                    sub_080493D4(0x30, gUnk_03002C30[48].unk2B * 4 + gUnk_03002C30[48].unk20);
                }
                update_battle_entity_status_chars();
            }
            if (S.unkF4 == 4)
                break;
        }
    }
    return S.unkF4;
}
