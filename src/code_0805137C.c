#include "global.h"

INCLUDE_ASM("asm/nonmatching/code_0805137C", load_map_npc_sprites);

// guess: sets up the player sprite (47) and its shadow (89) on entering the field
void init_battle_field_setup(void)
{
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
    if (gUnk_030057E0.unkC5B)
    {
        gUnk_03002C30[47].unk0 = 0xC804;
    }
    else
    {
        gUnk_03002C30[47].unk0 = 0;
        gUnk_03002C30[89].unk0 = 0;
    }
}

s32 sub_080518F4(u8 idx)
{
    return gUnk_083D28C0[gUnk_03002C30[idx].unk2A] * gUnk_083D28C0[gUnk_03006D38.unk2];
}

void set_battle_state_cancel_flag(void)
{
    gUnk_030057E0.unkC59 = 0xFF;
    sub_08051E8C();
}

// One frame of a tile step (dir 0 up, 1 down, 2 left, 3 right): moves the player, scrolls the camera,
// and when the step ends (unkC58 counts down) checks NPC events, map events and random encounters.
void field_player_step(u8 dir)
{
    switch (dir)
    {
    case 0:
        if (gUnk_030057E0.unkC54 - gUnk_030057E0.unkC4A != 0)
        {
            gUnk_030057E0.unkC54 -= sub_080518F4(47);
            advance_sprite_by_terrain_modifier(47);
            if (!sub_08052A18()
             && gUnk_030057E0.unkC54 - gUnk_030057E0.unkC4A < gUnk_030057E0.unk802 * 8 - 0x60
             && gBg1Scroll.y != 0)
                sub_08052AF8(-sub_080518F4(47));
        }
        break;
    case 1:
        if (gUnk_030057E0.unkC54 - gUnk_030057E0.unkC4A + 16 < gUnk_030057E0.unk802 * 8)
        {
            gUnk_030057E0.unkC54 += sub_080518F4(47);
            advance_sprite_by_terrain_modifier(47);
            if (!sub_08052A18()
             && gUnk_030057E0.unkC54 - gUnk_030057E0.unkC4A + 16 > 0x50
             && gBg1Scroll.y + 0xA0 < gUnk_030057E0.unk802 * 8)
                sub_08052AF8(sub_080518F4(47));
        }
        break;
    case 2:
        if (gUnk_030057E0.unkC52 - gUnk_030057E0.unkC48 != 0)
        {
            gUnk_030057E0.unkC52 -= sub_080518F4(47);
            advance_sprite_by_terrain_modifier(47);
            if (!sub_08052A04()
             && gUnk_030057E0.unkC52 - gUnk_030057E0.unkC48 < gUnk_030057E0.unk800 * 8 - 0x80
             && gBg1Scroll.x != 0)
                sub_08052A2C(-sub_080518F4(47));
        }
        break;
    case 3:
        if (gUnk_030057E0.unkC52 - gUnk_030057E0.unkC48 + 16 < gUnk_030057E0.unk800 * 8)
        {
            gUnk_030057E0.unkC52 += sub_080518F4(47);
            advance_sprite_by_terrain_modifier(47);
            if (!sub_08052A04()
             && gUnk_030057E0.unkC52 - gUnk_030057E0.unkC48 + 16 > 0x80
             && gBg1Scroll.x + 0xF0 < gUnk_030057E0.unk800 * 8)
                sub_08052A2C(sub_080518F4(47));
        }
        break;
    }
    if (--gUnk_030057E0.unkC58 == 0)
    {
        gUnk_03002C30[47].unk2A = gUnk_083D2908[gUnk_030057E0.unkC5C];
        gUnk_030057E0.unkC56 = sub_080526F0(gUnk_030057E0.unkC52);
        gUnk_030057E0.unkC57 = sub_08052714(gUnk_030057E0.unkC54);
        if (gUnk_030057E0.unkC88 == 0 && !find_npc_event_match())
        {
            if (find_map_event_by_coords(gUnk_030057E0.unkC56, gUnk_030057E0.unkC57))
            {
                gUnk_03005310.unk1 = 3;
                if (gUnk_03006D38.unk3)
                    sub_08047BA8(gUnk_083D29E6[gUnk_03006D38.unk3]);
                setup_palette_fade_to_color_with_obj(0x7FFF, 0.0f, 32.0f, 8.0f);
            }
            else if (gUnk_030057E0.unkC5C != 1 && check_random_encounter())
            {
                populate_battle_entity_tile_positions();
                sub_08047878(0x21, 0);
            }
        }
    }
}

u8 handle_battle_movement_input(u8 dir)
{
    u32 tile = gUnk_0847E948[gUnk_030057E0.unkC57 * (gUnk_030057E0.unk800 >> 1) + gUnk_030057E0.unkC56] - 1;

    if (tile <= 3)
        dir = gUnk_083D28C3[tile][dir];
    return dir;
}

INCLUDE_ASM("asm/nonmatching/code_0805137C", field_player_walk_input);

void load_battle_palette_via_dma(u32 toBuffer)
{
    decompress_battle_tile_graphics();
    if (toBuffer == 0)
        DmaCopy32(3, gUnk_083F8634[gUnk_083D29A6[gUnk_030057E0.unkC5C]], OBJ_PLTT, 32)
    else
        DmaCopy32(3, gUnk_083F8634[gUnk_083D29A6[gUnk_030057E0.unkC5C]], 0x0202F800, 32)
    gUnk_030057E0.unkC28 = gUnk_030057E0.unkC5C;
    load_battle_terrain_data();
}

void sub_08051E8C(void)
{
    if (gUnk_030057E0.unkC76)
        gUnk_030057E0.unkC75 = 0xFF;
}

// guess: sprite 48 (shadow 90) follows the player while unkC76 is set; turns it toward the player's tile.
// unkC76 stayed 0 through walkthrough segment 01.
void update_battle_direction_indicator(u8 flags)
{
    u8 prev = gUnk_030057E0.unkC75;

    if (gUnk_030057E0.unkC73 == gUnk_030057E0.unkC57)
    {
        if (gUnk_030057E0.unkC72 == gUnk_030057E0.unkC56)
        {
            gUnk_030057E0.unkC74 = 0;
        }
        else
        {
            if (flags & 2)
                gUnk_030057E0.unkC74 = 16 / sub_080518F4(48);
            if (gUnk_030057E0.unkC72 < gUnk_030057E0.unkC56)
                gUnk_030057E0.unkC75 = 3;
            else
                gUnk_030057E0.unkC75 = 2;
            if (gUnk_030057E0.unkC75 != prev)
            {
                set_battle_state_byte_c83(gUnk_030057E0.unkC75);
                sub_080493D4(48, sub_080502B4(48, gUnk_030057E0.unkC75));
            }
        }
    }
    else
    {
        if (flags & 2)
            gUnk_030057E0.unkC74 = 16 / sub_080518F4(48);
        if (gUnk_030057E0.unkC73 < gUnk_030057E0.unkC57)
            gUnk_030057E0.unkC75 = 1;
        else
            gUnk_030057E0.unkC75 = 0;
        if (gUnk_030057E0.unkC75 != prev)
        {
            set_battle_state_byte_c83(gUnk_030057E0.unkC75);
            sub_080493D4(48, sub_080502B4(48, gUnk_030057E0.unkC75));
        }
    }
    gUnk_03002C30[48].unk2A = gUnk_03002C30[47].unk2A;
}

// guess: one frame of sprite 48's step toward the player (see update_battle_direction_indicator)
void battle_camera_scroll_update(u8 dir)
{
    if (gUnk_030057E0.unkC76 && gUnk_030057E0.unkC74)
    {
        switch (dir)
        {
        case 0:
            if (gUnk_030057E0.unkC70 - gUnk_030057E0.unkC4A != 0)
            {
                gUnk_030057E0.unkC70 -= sub_080518F4(48);
                advance_sprite_by_terrain_modifier(48);
            }
            break;
        case 1:
            if (gUnk_030057E0.unkC70 - gUnk_030057E0.unkC4A + 16 < gUnk_030057E0.unk802 * 8)
            {
                gUnk_030057E0.unkC70 += sub_080518F4(48);
                advance_sprite_by_terrain_modifier(48);
            }
            break;
        case 2:
            if (gUnk_030057E0.unkC6E - gUnk_030057E0.unkC48 != 0)
            {
                gUnk_030057E0.unkC6E -= sub_080518F4(48);
                advance_sprite_by_terrain_modifier(48);
            }
            break;
        case 3:
            if (gUnk_030057E0.unkC6E - gUnk_030057E0.unkC48 + 16 < gUnk_030057E0.unk800 * 8)
            {
                gUnk_030057E0.unkC6E += sub_080518F4(48);
                advance_sprite_by_terrain_modifier(48);
            }
            break;
        }
        if (--gUnk_030057E0.unkC74 == 0)
        {
            gUnk_03002C30[48].unk2A = gUnk_03002C30[47].unk2A;
            gUnk_030057E0.unkC72 = sub_080526F0(gUnk_030057E0.unkC6E);
            gUnk_030057E0.unkC73 = sub_08052714(gUnk_030057E0.unkC70);
        }
    }
}

void set_sprite_anim_and_store(u8 idx, u8 state, struct MapObject *obj)
{
    set_sprite_animation_state(idx, state);
    obj->unk5 = state;
}

void update_npc_random_animation(void)
{
    struct MapObject *obj = gUnk_030057E0.unk5DC;

    if ((gUnk_03005310.unk4 & 3) == 0)
    {
        obj += field_random(64);
        if (obj->unk4_7 && (obj->unk2 >> 12) == 0)
            set_sprite_anim_and_store(obj->unk4_0 + 49, field_random(4), obj);
    }
}

void update_npc_sprite_animations(void)
{
    struct MapObject *obj = gUnk_030057E0.unk5DC;
    s32 i;
    u32 active;

    for (i = 0; i < 64; obj++, i++)
    {
        if (gUnk_030057E0.unkC88)
        {
            active = gUnk_030057E0.unkCB4 != i;
            if (gUnk_030057E0.unkC92 != 0x87)
                goto check;
            continue;
        }
        else
        {
            active = 1;
        }
    check:
        if (active && (obj->unk2 >> 12) == 6)
        {
            s32 idx = obj->unk4_0 + 49;
            if (gUnk_03002C30[idx].unk24 != 0xFF)
                advance_sprite_animation_frame(idx);
        }
    }
}

INCLUDE_ASM("asm/nonmatching/code_0805137C", map_cursor_move_and_check_event);

u32 find_npc_event_match(void)
{
    u8 found = 0;
    struct MapObject *obj = gUnk_030057E0.unk5DC;
    s32 i;

    for (i = 0; i < 64; i++)
    {
        if (obj->x == gUnk_030057E0.unkC56)
        {
            if (obj->y == gUnk_030057E0.unkC57 && (obj->unk2 & 0xF000) >> 12 == 8)
            {
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

INCLUDE_ASM("asm/nonmatching/code_0805137C", get_adjacent_tile_value);

u8 check_tile_and_trigger_battle_action(u8 dir)
{
    u8 tile;
    u32 ret;

    if (gUnk_030057E0.unkC5C == 2)
    {
        tile = get_adjacent_tile_value(dir);
        if (tile == 0 || tile == 2)
        {
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

s32 check_room_exit_at_position(void)
{
    s32 ret = -1;
    const struct MapExit *p = gUnk_0840FAF4[gUnk_030057E0.unk7FE];
    s32 blocked = 0;
    s32 x = gUnk_030057E0.unkC56;
    s32 y = gUnk_030057E0.unkC57;
    u8 mask;
    s32 i;

    // step one tile in the facing direction (0 up, 1 down, 2 left, 3 right)
    switch (gUnk_03002C30[47].unk20)
    {
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

    for (i = 0; p[i].mask != 0; i++)
    {
        if (p[i].x == x && p[i].y == y && (ret = p[i].value) != 0)
        {
            mask = p[i].mask;
            switch (gUnk_03002C30[47].unk20)
            {
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

u8 sub_080526F0(u16 x)
{
    return (x - gUnk_030057E0.unkC48) / 16;
}

u8 sub_08052714(u16 y)
{
    return (y - gUnk_030057E0.unkC4A) / 16;
}

INCLUDE_ASM("asm/nonmatching/code_0805137C", update_entity_sprites_on_screen);

// Decompresses the area's tiles and centres maps smaller than the screen (15 x 10 tiles).
void field_load_area_tiles(u8 area)
{
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

u32 sub_08052960(u8 area, u8 which)
{
    u32 ret = 0;

    switch (which)
    {
    case 0:
        ret = gUnk_083F8B74[area][which];
        break;
    case 1:
        ret = gUnk_083F8B74[area][which];
        break;
    }
    return ret;
}

u32 sub_08052990(u32 unused, u8 which)
{
    u32 ret = 0;

    switch (which)
    {
    case 0:
        ret = gUnk_03006D14[0] | (gUnk_03006D14[1] << 16);
        break;
    case 1:
        ret = gUnk_03006D14[2] | (gUnk_03006D14[3] << 16);
        break;
    }
    return ret;
}

void sub_080529C4(u16 x)
{
    gBg1Scroll.x = x;
    gBg2Scroll.x = x;
    gBg3Scroll.x = x;
}

void sub_080529E4(u16 y)
{
    gBg1Scroll.y = y;
    gBg2Scroll.y = y;
    gBg3Scroll.y = y;
}

u32 sub_08052A04(void)
{
    return gUnk_030057E0.unkC48;
}

u32 sub_08052A18(void)
{
    return gUnk_030057E0.unkC4A;
}

void sub_08052A2C(s16 dx)
{
    gBg1Scroll.x += dx;
    gBg2Scroll.x += dx;
    gBg3Scroll.x += dx;
}

void field_center_camera_on_player(void)
{
    s32 x, y;

    x = gUnk_030057E0.unkC56 - 7;
    if (x < 0)
        x = 0;
    if (x + 15 > sub_08052960(gUnk_030057E0.unk7FE, 0) >> 1)
    {
        x = sub_08052960(gUnk_030057E0.unk7FE, 0) >> 1;
        x -= 15;
        if (sub_08052A04())
            x = 0;
    }
    y = gUnk_030057E0.unkC57 - 4;
    if (y <= 0)
        y = 0;
    if (y + 10 > sub_08052960(gUnk_030057E0.unk7FE, 1) >> 1)
    {
        y = sub_08052960(gUnk_030057E0.unk7FE, 1) >> 1;
        y -= 10;
        if (sub_08052A18())
            y = 0;
    }
    sub_080529C4(x * 16);
    sub_080529E4(y * 16);
}

void sub_08052AF8(s16 dy)
{
    gBg1Scroll.y += dy;
    gBg2Scroll.y += dy;
    gBg3Scroll.y += dy;
}

void update_bg_scroll_offsets_a(void)
{
    gUnk_03002C30[47].unk2 = gUnk_030057E0.unkC52 - gBg1Scroll.x;
    gUnk_03002C30[47].unk4 = gUnk_030057E0.unkC54 - gBg1Scroll.y;
    gUnk_03002C30[89].unk2 = gUnk_03002C30[47].unk2;
    gUnk_03002C30[89].unk4 = gUnk_03002C30[47].unk4 - 5;
}

void sub_08052B84(void)
{
    gUnk_03002C30[47].unk0 = 0;
    gUnk_03002C30[89].unk0 = 0;
}

void sub_08052BA0(u8 on)
{
    if (on)
    {
        gUnk_03002C30[47].unk0 = 0xC804;
        gUnk_03002C30[89].unk0 = 0xCC0C;
    }
    else
    {
        gUnk_03002C30[47].unk0 = on;
        gUnk_03002C30[89].unk0 = on;
    }
}

void check_and_update_battlefield_palette(void)
{
    if (gUnk_030057E0.unkC5C == 1 && sub_0804803C(0) == 0)
    {
        gUnk_030057E0.unkC5C = gUnk_030057E0.unkC69;
        load_battle_palette_via_dma(1);
    }
}

// Returns 1 if a warp of the current area sits at (x, y); stores its high dir nibble in gUnk_03006D38.unk3.
u32 find_map_event_by_coords(u32 x, u32 y)
{
    u32 found = 0;
    const struct AreaWarp *w = gUnk_08413114[gUnk_030057E0.unk7FE];
    s32 dir;
    s32 i;

    for (i = 0; w[i].x != 0xFF; i++)
    {
        u8 wx = w[i].x;
        u8 wy = w[i].y;
        if (wx == x && wy == y)
        {
            found = 1;
            dir = w[i].dir;
            gUnk_03006D38.unk3 = (dir & 0xF0) >> 4;
        }
    }
    return found;
}

// dir: 0 up, 1 down, 2 left, 3 right. At the edge the player only turns to face dir.
u8 field_player_at_map_edge(u8 dir)
{
    u8 ret = 0;

    switch (dir)
    {
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

void set_sprite_animation_state(u8 idx, u8 state)
{
    gUnk_03002C30[idx].unk20 = state;
    gUnk_03002C30[idx].unk21 = state;
    switch (state)
    {
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
void field_set_player_facing(u8 dir)
{
    gUnk_030057E0.unkC67 = dir;
    set_sprite_animation_state(47, dir);
    update_battle_direction_indicator(3);
}

void set_battle_state_byte_c83(u8 dir)
{
    gUnk_030057E0.unkC83 = dir;
    set_sprite_animation_state(48, dir);
}

void set_tile_data(u8 x, u8 y, u8 val)
{
    gUnk_030057E0.unk810[y * (gUnk_030057E0.unk800 >> 1) + x] = val;
}

// Runs at the end of a door transition: finds the warp under the player, switches area and places the player.
void field_warp_to_area(void)
{
    u32 found = 0;
    u32 area = gUnk_030057E0.unk7FE;
    const struct AreaWarp *w = gUnk_08413114[area];
    s32 i;

    for (i = 0; w[i].x != 0xFF; )
    {
        u8 x = w[i].x;
        u8 y = w[i].y;
        if (x == gUnk_030057E0.unkC56 && y == gUnk_030057E0.unkC57)
        {
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
void init_battle_medaforce_sprite(void)
{
    if (gUnk_030057E0.unkC76)
    {
        init_battle_sprite_entry_08048818(48, 0xC804, gUnk_030057E0.unkC84 * 12 + gUnk_030057E0.unkC83, gUnk_030057E0.unkC84, 1);
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

void update_cursor_tile_position(void)
{
    if (gUnk_030057E0.unkC76)
    {
        gUnk_030057E0.unkC6E = gUnk_030057E0.unkC52;
        gUnk_030057E0.unkC70 = gUnk_030057E0.unkC54;
        gUnk_030057E0.unkC72 = sub_080526F0(gUnk_030057E0.unkC6E);
        gUnk_030057E0.unkC73 = sub_08052714(gUnk_030057E0.unkC70);
        set_battle_state_byte_c83(gUnk_03002C30[47].unk20);
    }
}

void update_bg_scroll_offsets_b(void)
{
    gUnk_03002C30[48].unk2 = gUnk_030057E0.unkC6E - gBg1Scroll.x;
    gUnk_03002C30[48].unk4 = gUnk_030057E0.unkC70 - gBg1Scroll.y;
    gUnk_03002C30[90].unk2 = gUnk_03002C30[48].unk2;
    gUnk_03002C30[90].unk4 = gUnk_03002C30[48].unk4 - 5;
}

void sub_0805311C(u16 id)
{
    if (!(id & 1))
    {
        u8 *flags = gUnk_030057D8;
        flags[id >> 1] &= 0x7F;
    }
    else
    {
        u8 *flags = gUnk_030057D8;
        flags[id >> 1] &= 0xF7;
    }
}

void sub_08053154(u16 id)
{
    if (!(id & 1))
    {
        u8 *flags = gUnk_030057D8;
        flags[id >> 1] = (flags[id >> 1] & 0x7F) | 0x80;
    }
    else
    {
        u8 *flags = gUnk_030057D8;
        flags[id >> 1] = (flags[id >> 1] & 0xF7) | 0x08;
    }
}

u32 sub_08053194(u16 id)
{
    if (!(id & 1))
    {
        u8 *flags = gUnk_030057D8;
        return (u8)(flags[id >> 1] & 0x80) >> 7;
    }
    else
    {
        u8 *flags = gUnk_030057D8;
        return (u8)(flags[id >> 1] & 0x08) >> 3;
    }
}

void sub_080531D0(u16 id, u8 val)
{
    if (val == 0)
        sub_0805311C(id);
    else
        sub_08053154(id);
}

void sub_080531EC(u16 id, u8 val)
{
    if (!(id & 1))
    {
        u8 *flags = gUnk_030057D8;
        flags[id >> 1] = (flags[id >> 1] & 0x8F) | (val << 4);
    }
    else
    {
        u8 *flags = gUnk_030057D8;
        flags[id >> 1] = (flags[id >> 1] & 0xF8) | val;
    }
}

void sub_08053234(u16 id)
{
    u8 n;

    if (!(id & 1))
    {
        u8 *flags = gUnk_030057D8;
        n = (flags[id >> 1] & 0x70) >> 4;
        n++;
        flags[id >> 1] = (flags[id >> 1] & 0x8F) | (n << 4);
    }
    else
    {
        u8 *flags = gUnk_030057D8;
        n = flags[id >> 1] & 7;
        n++;
        flags[id >> 1] = (flags[id >> 1] & 0xF8) | n;
    }
}

u32 sub_08053288(u16 id)
{
    if (!(id & 1))
    {
        u8 *flags = gUnk_030057D8;
        return (flags[id >> 1] & 0x70) >> 4;
    }
    else
    {
        u8 *flags = gUnk_030057D8;
        return flags[id >> 1] & 7;
    }
}

void load_battle_terrain_data(void)
{
    memcpy_u8(gUnk_083D2918[gUnk_030057E0.unkC28], gUnk_030057E0.unkC10, 8);
    gUnk_03002C30[47].unk2A = gUnk_083D2908[gUnk_030057E0.unkC5C];
}

float float_default_to_one_if_zero(float x)
{
    if (x == 0.0f)
        x = 1.0f;
    return x;
}

float float_sign(float x)
{
    if (x < 0.0f)
        return -1.0f;
    return 1.0f;
}

float float_abs_if_negative(float x)
{
    if (x < 0.0f)
        x *= -1.0f;
    return x;
}

double compute_sqrt_scaled(double x)
{
    return (u16)Sqrt((s32)x << 3) >> 3;
}

void init_sprite_affine_matrices_and_state(u32 flags, u32 x, u32 y, u32 d)
{
    s32 i;

    sub_080492CC();
    for (i = 0; i < 32; i++)
        calculate_oam_affine_matrix(i);
    sub_080496C8((u8 *)&gUnk_03005350, 0x240);
    gUnk_03005350.unk1D4 = flags;
    if (flags & 0x40)
    {
        x = gUnk_030057E0.unkC52;
        y = gUnk_030057E0.unkC54;
    }
    gUnk_03005350.unk1D8 = x;
    gUnk_03005350.unk1DC = y;
    gUnk_03005350.unk1E0 = d;
}

void sub_08053418(void)
{
    sub_0805378C();
    gUnk_03005350.unkA4[0] = gUnk_03005350.unk1D8 - gBg1Scroll.x - 0x70;
    gUnk_03005350.unkA4[1] = gUnk_03005350.unk1DC - gBg1Scroll.y - 0x50;
    sub_080496C8((u8 *)gUnk_03006D30, 0x3000);
}

void compute_distance_to_state_position(float *xs, float *ys, float *zs)
{
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
void compute_plane_from_points(float *x, float *y, float *z, float *a, float *b, float *c, float *d)
{
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

void get_state_position_xyz(float *x, float *y, float *z)
{
    *x = gUnk_03005350.unk40;
    *y = gUnk_03005350.unk44;
    *z = gUnk_03005350.unk48;
}

void sub_0805378C(void)
{
    sub_08053798();
}

void sub_08053798(void)
{
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

void affine_set_destination_and_compute_transform(float x0, float x1, float y0, float y1)
{
    gUnk_03005350.unk10 = x0;
    gUnk_03005350.unk14 = x1;
    gUnk_03005350.unk18 = y0;
    gUnk_03005350.unk1C = y1;
    gUnk_03005350.unk30 = (gUnk_03005350.unk24 - gUnk_03005350.unk20) / (x1 - x0);
    gUnk_03005350.unk34 = (gUnk_03005350.unk2C - gUnk_03005350.unk28) / (y1 - y0);
    gUnk_03005350.unk38 = (x1 * gUnk_03005350.unk20 - x0 * gUnk_03005350.unk24) / (x1 - x0);
    gUnk_03005350.unk3C = (y1 * gUnk_03005350.unk28 - y0 * gUnk_03005350.unk2C) / (y1 - y0);
}

void affine_set_source_and_compute_transform(float x0, float x1, float y0, float y1)
{
    gUnk_03005350.unk20 = x0;
    gUnk_03005350.unk24 = x1;
    gUnk_03005350.unk28 = y0;
    gUnk_03005350.unk2C = y1;
    gUnk_03005350.unk30 = (x1 - x0) / (gUnk_03005350.unk14 - gUnk_03005350.unk10);
    gUnk_03005350.unk34 = (y1 - y0) / (gUnk_03005350.unk1C - gUnk_03005350.unk18);
    gUnk_03005350.unk38 = (gUnk_03005350.unk14 * x0 - gUnk_03005350.unk10 * x1) / (gUnk_03005350.unk14 - gUnk_03005350.unk10);
    gUnk_03005350.unk3C = (gUnk_03005350.unk1C * y0 - gUnk_03005350.unk18 * y1) / (gUnk_03005350.unk1C - gUnk_03005350.unk18);
}

void set_state_float_field(float a, float b, float c, float d)
{
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

void sub_08053AB8(float *x, float *y, float *z)
{
    float a, b, c;
    s32 i;

    a = x[0];
    b = y[0];
    c = z[0];
    sub_08053B94(a, b, c);
    for (i = 1; i < gUnk_03005350.unk1D0; i++)
    {
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

void sub_08053B94(float a, float b, float c)
{
    float x, y, z;

    compute_3d_transform_vectors(a, b, c, &x, &y, &z);
    sub_08053BB4(x, y);
}

void sub_08053BB4(float a, float b)
{
    get_state_float_as_int(a, b, &gUnk_03005350.unkB4, &gUnk_03005350.unkB8);
}

void update_battle_entity_screen_position(float x, float y, float z)
{
    float sx, sy, depth;
    struct Unk_03002C30 *sprites;

    compute_3d_transform_vectors(x, y, z, &sx, &sy, &depth);
    update_entity_position_and_triggers(sx, sy);
    sprites = gUnk_03002C30;
    sprites[gUnk_03006D30[gUnk_03005350.unk1CC].unk2DC[gUnk_03006D30[gUnk_03005350.unk1CC].unk20C]].unk14_8 = depth;
}

void compute_3d_transform_vectors(float x, float y, float z, float *outX, float *outY, float *outZ)
{
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

void get_state_float_as_int(float a, float b, s32 *x, s32 *y)
{
    *x = (s32)gUnk_03005350.unk30 * (s32)a + (s32)gUnk_03005350.unk38 + gUnk_03005350.unk8;
    *y = gUnk_03005350.unkC - ((s32)gUnk_03005350.unk34 * (s32)b + (s32)gUnk_03005350.unk3C);
}

#define CUR_ENTITY gUnk_03006D30[gUnk_03005350.unk1CC]

void update_entity_position_and_triggers(float a, float b)
{
    get_state_float_as_int(a, b, &gUnk_03005350.unkB4, &gUnk_03005350.unkB8);
    gUnk_03002C30[CUR_ENTITY.unk2DC[CUR_ENTITY.unk20C]].unk2 = gUnk_03005350.unkB4 + CUR_ENTITY.unk2E0[CUR_ENTITY.unk20C];
    gUnk_03002C30[CUR_ENTITY.unk2DC[CUR_ENTITY.unk20C]].unk4 = gUnk_03005350.unkB8 + CUR_ENTITY.unk2E8[CUR_ENTITY.unk20C];
    if (CUR_ENTITY.unk1EC && (u8)gUnk_03005350.unkB8 >= CUR_ENTITY.unk1F0 && (u8)gUnk_03005350.unkB8 <= CUR_ENTITY.unk1F4)
    {
        CUR_ENTITY.unk0 = 2;
        CUR_ENTITY.unkAC = 0;
    }
    if (CUR_ENTITY.unk1E0 && (s32)(gUnk_03005350.unkB4 & 0x1FF) >= CUR_ENTITY.unk1E4 && (s32)(gUnk_03005350.unkB4 & 0x1FF) <= CUR_ENTITY.unk1E8)
    {
        CUR_ENTITY.unk0 = 2;
        CUR_ENTITY.unk64 = 0;
        CUR_ENTITY.unk1C = 0;
    }
    if (CUR_ENTITY.unk1F8)
    {
        if (CUR_ENTITY.unkA0 <= CUR_ENTITY.unk1FC)
        {
            CUR_ENTITY.unk0 = 2;
            CUR_ENTITY.unkAC = 0;
        }
        if (CUR_ENTITY.unkA0 >= CUR_ENTITY.unk200)
        {
            CUR_ENTITY.unk0 = 2;
            CUR_ENTITY.unkAC = 0;
        }
    }
}

void init_affine_transform_viewport(s32 x, s32 y)
{
    gUnk_03005350.unk0 = 240;
    gUnk_03005350.unk4 = 160;
    gUnk_03005350.unk8 = x + 120;
    gUnk_03005350.unkC = y + 80;
    affine_set_destination_and_compute_transform(-120.5f, 120.5f, -80.5f, 80.5f);
    affine_set_source_and_compute_transform(-120.5f, 120.5f, -80.5f, 80.5f);
}

INCLUDE_ASM("asm/nonmatching/code_0805137C", update_3d_entity_projections);
INCLUDE_ASM("asm/nonmatching/code_0805137C", battle_sequence_dispatch);
INCLUDE_ASM("asm/nonmatching/code_0805137C", sub_08054234);
