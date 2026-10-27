// Field player: load_map_npc_sprites puts the area's NPC sprites up, field_player_walk_input and
// field_player_step move the player tile by tile, plus the facing indicator and the camera scroll that
// follows a step. Called from the field frame handler (field/field_walk) and the field sub-states
// (field/field_update); uses field/map_objects for collision, events and exits.
#include "global.h"

static void battle_camera_scroll_update(u8 dir);

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
    memzero_bytes((u8 *)saved, sizeof(saved));
    memcpy_u8(obj, saved, sizeof(saved));
    memzero_bytes((u8 *)obj, sizeof(saved));
    count = 0;
    n = 0;
    j = 0;
    for (k = 0; k < 32; k++) {
        for (e = gUnk_084837A0[gUnk_030057E0.unk7FE]; e->x != 0xFF; e++) {
            if (!((e->unk6 >> gUnk_030057E0.unk7FF) & 1))
                continue;
            if (e->unk5 != k)
                continue;
            if (event_flag_get(e->unk2 & 0xFFF))
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
                    sprite_entry_init(slot, 0xC804, f, a, 1);
                    gUnk_030057E0.unk5DC[n].unk4_6 = 1;
                    gSpriteEntries[count + 49].unk30 = area_sprite_sheet_id(a);
                    sprite_set_blend_from_kind(count + 49);
                    if (gUnk_083D2B8D[gSpriteEntries[count + 49].unk30])
                        sprite_entry_init(count + 91, 0xCC0C, 0x90, 14, 1);
                } break;
                }
                gUnk_030057E0.unk5DC[n].unk4_0 = count;
                anim = e->unk4 >> 4;
                gUnk_030055A0[count + 49].unk0 = e->unk2 & 0xFFF;
                gSpriteEntries[count + 49].unk2B = anim;
                gSpriteEntries[count + 49].unkC_8 = e->x * 16 + gUnk_030057E0.unkC48;
                gSpriteEntries[count + 49].unk10_8 = e->y * 16 + gUnk_030057E0.unkC4A;
                set_sprite_anim_and_store(count + 49, e->unk4 & 0xF, &gUnk_030057E0.unk5DC[n]);
                sprite_anim_start(count + 49, anim * 4 + (e->unk4 & 0xF));
                if (mode != 0 && found) {
                    set_sprite_anim_and_store(count + 49, saved[j].unk5, &gUnk_030057E0.unk5DC[n]);
                    sprite_anim_start(count + 49, saved[j].unk5 + anim * 4);
                }
                gSpriteEntries[count + 49].unk2C = 0;
                gSpriteEntries[count + 91].unkC_8 = gSpriteEntries[count + 49].unkC_8;
                gSpriteEntries[count + 91].unk10_8 = gSpriteEntries[count + 49].unk10_8 - 5;
                gSpriteEntries[count + 91].unk2 = gSpriteEntries[count + 49].unk2;
                gSpriteEntries[count + 91].unk4 = gSpriteEntries[count + 49].unk4 - 5;
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
    gUnk_030057E0.unkC28 = gUnk_030057E0.player_form;
    load_battle_terrain_data();
    gUnk_030057E0.player_tile_x = sub_080526F0(gUnk_030057E0.player_x);
    gUnk_030057E0.player_tile_y = sub_08052714(gUnk_030057E0.player_y);
    sprite_entry_init(47, 0xC804, 3, 0, 1);
    field_set_player_facing(gUnk_030057E0.player_facing);
    update_battle_direction_indicator(3);
    gSpriteEntries[47].unkB = 0x40;
    LZ77UnCompVram(gUnk_085FA104, (void *)0x06017FC0);
    sprite_entry_init(89, 0xCC0C, 0x90, 14, 1);
    gSpriteEntries[89].unkC_8 = gUnk_030057E0.player_x;
    gSpriteEntries[89].unk10_8 = gUnk_030057E0.player_y - 5;
    gSpriteEntries[89].unk2 = gSpriteEntries[47].unk2;
    gSpriteEntries[89].unk4 = gSpriteEntries[47].unk4 - 5;
    if (gUnk_030057E0.unkC5B) {
        gSpriteEntries[47].unk0 = 0xC804;
    } else {
        gSpriteEntries[47].unk0 = 0;
        gSpriteEntries[89].unk0 = 0;
    }
}

// Pixels per frame for a walking sprite: its own speed factor times the area's (16 / speed = frames per tile).
s32 sprite_walk_speed(u8 idx) {
    return gUnk_083D28C0[gSpriteEntries[idx].unk2A] * gUnk_083D28C0[gUnk_03006D38.unk2];
}

void set_battle_state_cancel_flag(void) {
    gUnk_030057E0.unkC59 = 0xFF;
    follower_clear_scroll_dir();
}

// One frame of a tile step (dir 0 up, 1 down, 2 left, 3 right): moves the player, scrolls the camera,
// and when the step ends (unkC58 counts down) checks NPC events, map events and random encounters.
void field_player_step(u8 dir) {
    switch (dir) {
    case 0:
        if (gUnk_030057E0.player_y - gUnk_030057E0.unkC4A != 0) {
            gUnk_030057E0.player_y -= sprite_walk_speed(47);
            advance_sprite_by_terrain_modifier(47);
            if (!sub_08052A18() && gUnk_030057E0.player_y - gUnk_030057E0.unkC4A < gUnk_030057E0.unk802 * 8 - 0x60 &&
                gBg1Scroll.y != 0)
                sub_08052AF8(-sprite_walk_speed(47));
        }
        break;
    case 1:
        if (gUnk_030057E0.player_y - gUnk_030057E0.unkC4A + 16 < gUnk_030057E0.unk802 * 8) {
            gUnk_030057E0.player_y += sprite_walk_speed(47);
            advance_sprite_by_terrain_modifier(47);
            if (!sub_08052A18() && gUnk_030057E0.player_y - gUnk_030057E0.unkC4A + 16 > 0x50 &&
                gBg1Scroll.y + 0xA0 < gUnk_030057E0.unk802 * 8)
                sub_08052AF8(sprite_walk_speed(47));
        }
        break;
    case 2:
        if (gUnk_030057E0.player_x - gUnk_030057E0.unkC48 != 0) {
            gUnk_030057E0.player_x -= sprite_walk_speed(47);
            advance_sprite_by_terrain_modifier(47);
            if (!sub_08052A04() && gUnk_030057E0.player_x - gUnk_030057E0.unkC48 < gUnk_030057E0.unk800 * 8 - 0x80 &&
                gBg1Scroll.x != 0)
                sub_08052A2C(-sprite_walk_speed(47));
        }
        break;
    case 3:
        if (gUnk_030057E0.player_x - gUnk_030057E0.unkC48 + 16 < gUnk_030057E0.unk800 * 8) {
            gUnk_030057E0.player_x += sprite_walk_speed(47);
            advance_sprite_by_terrain_modifier(47);
            if (!sub_08052A04() && gUnk_030057E0.player_x - gUnk_030057E0.unkC48 + 16 > 0x80 &&
                gBg1Scroll.x + 0xF0 < gUnk_030057E0.unk800 * 8)
                sub_08052A2C(sprite_walk_speed(47));
        }
        break;
    }
    if (--gUnk_030057E0.unkC58 == 0) {
        gSpriteEntries[47].unk2A = gUnk_083D2908[gUnk_030057E0.player_form];
        gUnk_030057E0.player_tile_x = sub_080526F0(gUnk_030057E0.player_x);
        gUnk_030057E0.player_tile_y = sub_08052714(gUnk_030057E0.player_y);
        if (gUnk_030057E0.unkC88 == 0 && !find_npc_event_match()) {
            if (find_map_event_by_coords(gUnk_030057E0.player_tile_x, gUnk_030057E0.player_tile_y)) {
                gUnk_03005310.unk1 = 3;
                if (gUnk_03006D38.unk3)
                    field_play_sound_effect(gUnk_083D29E6[gUnk_03006D38.unk3]);
                setup_palette_fade_to_color_with_obj(0x7FFF, 0.0f, 32.0f, 8.0f);
            } else if (gUnk_030057E0.player_form != 1 && check_random_encounter()) {
                save_script_sprites();
                switch_game_mode(0x21, 0);
            }
        }
    }
}

static u8 handle_battle_movement_input(u8 dir) {
    u32 tile =
        gUnk_0847E948[gUnk_030057E0.player_tile_y * (gUnk_030057E0.unk800 >> 1) + gUnk_030057E0.player_tile_x] - 1;

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
                sprite_anim_start(0x2F, dir);
                update_battle_direction_indicator(3);
            }
            if (!field_player_at_map_edge(dir) && !check_tile_and_trigger_battle_action(dir)) {
                gUnk_030057E0.unkC58 = 16 / sprite_walk_speed(0x2F);
                field_player_step(gUnk_030057E0.unkC59);
                update_battle_direction_indicator(3);
                if (gUnk_030057E0.player_form == 2 || gUnk_030057E0.player_form == 9)
                    field_play_sound_effect(0x57);
                battle_camera_scroll_update(gUnk_030057E0.unkC75);
            }
        }
    } else {
        field_player_step(gUnk_030057E0.unkC59);
        battle_camera_scroll_update(gUnk_030057E0.unkC75);
    }
}

void load_battle_palette_via_dma(u32 toBuffer) {
    area_load_sprite_sheets();
    if (toBuffer == 0)
        DmaCopy32(3, gUnk_083F8634[gUnk_083D29A6[gUnk_030057E0.player_form]], OBJ_PLTT,
                  32) else DmaCopy32(3, gUnk_083F8634[gUnk_083D29A6[gUnk_030057E0.player_form]], 0x0202F800, 32)
            gUnk_030057E0.unkC28 = gUnk_030057E0.player_form;
    load_battle_terrain_data();
}

// guess: unkC76 = a follower sprite is active; unkC75 = its pending camera scroll direction (0xFF none).
void follower_clear_scroll_dir(void) {
    if (gUnk_030057E0.unkC76)
        gUnk_030057E0.unkC75 = 0xFF;
}

// guess: sprite 48 (shadow 90) follows the player while unkC76 is set; turns it toward the player's tile.
// unkC76 stayed 0 through walkthrough segment 01.
void update_battle_direction_indicator(u8 flags) {
    u8 prev = gUnk_030057E0.unkC75;

    if (gUnk_030057E0.unkC73 == gUnk_030057E0.player_tile_y) {
        if (gUnk_030057E0.unkC72 == gUnk_030057E0.player_tile_x) {
            gUnk_030057E0.unkC74 = 0;
        } else {
            if (flags & 2)
                gUnk_030057E0.unkC74 = 16 / sprite_walk_speed(48);
            if (gUnk_030057E0.unkC72 < gUnk_030057E0.player_tile_x)
                gUnk_030057E0.unkC75 = 3;
            else
                gUnk_030057E0.unkC75 = 2;
            if (gUnk_030057E0.unkC75 != prev) {
                set_battle_state_byte_c83(gUnk_030057E0.unkC75);
                sprite_anim_start(48, sub_080502B4(48, gUnk_030057E0.unkC75));
            }
        }
    } else {
        if (flags & 2)
            gUnk_030057E0.unkC74 = 16 / sprite_walk_speed(48);
        if (gUnk_030057E0.unkC73 < gUnk_030057E0.player_tile_y)
            gUnk_030057E0.unkC75 = 1;
        else
            gUnk_030057E0.unkC75 = 0;
        if (gUnk_030057E0.unkC75 != prev) {
            set_battle_state_byte_c83(gUnk_030057E0.unkC75);
            sprite_anim_start(48, sub_080502B4(48, gUnk_030057E0.unkC75));
        }
    }
    gSpriteEntries[48].unk2A = gSpriteEntries[47].unk2A;
}

// guess: one frame of sprite 48's step toward the player (see update_battle_direction_indicator)
static void battle_camera_scroll_update(u8 dir) {
    if (gUnk_030057E0.unkC76 && gUnk_030057E0.unkC74) {
        switch (dir) {
        case 0:
            if (gUnk_030057E0.unkC70 - gUnk_030057E0.unkC4A != 0) {
                gUnk_030057E0.unkC70 -= sprite_walk_speed(48);
                advance_sprite_by_terrain_modifier(48);
            }
            break;
        case 1:
            if (gUnk_030057E0.unkC70 - gUnk_030057E0.unkC4A + 16 < gUnk_030057E0.unk802 * 8) {
                gUnk_030057E0.unkC70 += sprite_walk_speed(48);
                advance_sprite_by_terrain_modifier(48);
            }
            break;
        case 2:
            if (gUnk_030057E0.unkC6E - gUnk_030057E0.unkC48 != 0) {
                gUnk_030057E0.unkC6E -= sprite_walk_speed(48);
                advance_sprite_by_terrain_modifier(48);
            }
            break;
        case 3:
            if (gUnk_030057E0.unkC6E - gUnk_030057E0.unkC48 + 16 < gUnk_030057E0.unk800 * 8) {
                gUnk_030057E0.unkC6E += sprite_walk_speed(48);
                advance_sprite_by_terrain_modifier(48);
            }
            break;
        }
        if (--gUnk_030057E0.unkC74 == 0) {
            gSpriteEntries[48].unk2A = gSpriteEntries[47].unk2A;
            gUnk_030057E0.unkC72 = sub_080526F0(gUnk_030057E0.unkC6E);
            gUnk_030057E0.unkC73 = sub_08052714(gUnk_030057E0.unkC70);
        }
    }
}
