#include "global.h"

INCLUDE_ASM("asm/nonmatching/code_0805137C", load_map_npc_sprites);
INCLUDE_ASM("asm/nonmatching/code_0805137C", init_battle_field_setup);

u32 sub_080518F4(u8 idx)
{
    return gUnk_083D28C0[gUnk_03002C30[idx].unk2A] * gUnk_083D28C0[gUnk_03006D38.unk2];
}

void set_battle_state_cancel_flag(void)
{
    gUnk_030057E0.unkC59 = 0xFF;
    sub_08051E8C();
}

INCLUDE_ASM("asm/nonmatching/code_0805137C", update_camera_scroll_and_check_events);

u8 handle_battle_movement_input(u8 dir)
{
    u32 tile = gUnk_0847E948[gUnk_030057E0.unkC57 * (gUnk_030057E0.unk800 >> 1) + gUnk_030057E0.unkC56] - 1;

    if (tile <= 3)
        dir = gUnk_083D28C3[tile][dir];
    return dir;
}

INCLUDE_ASM("asm/nonmatching/code_0805137C", battle_field_movement_dispatch);
INCLUDE_ASM("asm/nonmatching/code_0805137C", load_battle_palette_via_dma);

void sub_08051E8C(void)
{
    if (gUnk_030057E0.unkC76)
        gUnk_030057E0.unkC75 = 0xFF;
}

INCLUDE_ASM("asm/nonmatching/code_0805137C", update_battle_direction_indicator);
INCLUDE_ASM("asm/nonmatching/code_0805137C", battle_camera_scroll_update);

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
        obj += get_entity_speed_fraction(64);
        if (obj->unk4_7 && (obj->unk2 >> 12) == 0)
            set_sprite_anim_and_store(obj->unk4_0 + 49, get_entity_speed_fraction(4), obj);
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

u8 find_npc_event_match(void)
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
        set_battle_entity_animation_attack(dir);
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
INCLUDE_ASM("asm/nonmatching/code_0805137C", load_npc_sprite_and_calc_camera_offset);
INCLUDE_ASM("asm/nonmatching/code_0805137C", sub_08052960);

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
    gUnk_03004C30.x = x;
    gUnk_0300057C.x = x;
    gUnk_03001C04.x = x;
}

void sub_080529E4(u16 y)
{
    gUnk_03004C30.y = y;
    gUnk_0300057C.y = y;
    gUnk_03001C04.y = y;
}

u16 sub_08052A04(void)
{
    return gUnk_030057E0.unkC48;
}

u16 sub_08052A18(void)
{
    return gUnk_030057E0.unkC4A;
}

INCLUDE_ASM("asm/nonmatching/code_0805137C", sub_08052A2C);
INCLUDE_ASM("asm/nonmatching/code_0805137C", calculate_camera_scroll_from_npc);
INCLUDE_ASM("asm/nonmatching/code_0805137C", sub_08052AF8);

void update_bg_scroll_offsets_a(void)
{
    gUnk_03002C30[47].unk2 = gUnk_030057E0.unkC52 - gUnk_03004C30.x;
    gUnk_03002C30[47].unk4 = gUnk_030057E0.unkC54 - gUnk_03004C30.y;
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

INCLUDE_ASM("asm/nonmatching/code_0805137C", find_map_event_by_coords);
INCLUDE_ASM("asm/nonmatching/code_0805137C", check_battle_animation_complete);

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

void set_battle_entity_animation_attack(u8 dir)
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

INCLUDE_ASM("asm/nonmatching/code_0805137C", sub_08052E3C);
INCLUDE_ASM("asm/nonmatching/code_0805137C", init_battle_medaforce_sprite);

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
    gUnk_03002C30[48].unk2 = gUnk_030057E0.unkC6E - gUnk_03004C30.x;
    gUnk_03002C30[48].unk4 = gUnk_030057E0.unkC70 - gUnk_03004C30.y;
    gUnk_03002C30[90].unk2 = gUnk_03002C30[48].unk2;
    gUnk_03002C30[90].unk4 = gUnk_03002C30[48].unk4 - 5;
}

INCLUDE_ASM("asm/nonmatching/code_0805137C", sub_0805311C);
INCLUDE_ASM("asm/nonmatching/code_0805137C", sub_08053154);
INCLUDE_ASM("asm/nonmatching/code_0805137C", sub_08053194);
INCLUDE_ASM("asm/nonmatching/code_0805137C", sub_080531D0);
INCLUDE_ASM("asm/nonmatching/code_0805137C", sub_080531EC);
INCLUDE_ASM("asm/nonmatching/code_0805137C", sub_08053234);
INCLUDE_ASM("asm/nonmatching/code_0805137C", sub_08053288);

void load_battle_terrain_data(void)
{
    memcpy_u8(gUnk_083D2918[gUnk_030057E0.unkC28], gUnk_030057E0.unkC10, 8);
    gUnk_03002C30[47].unk2A = gUnk_083D2908[gUnk_030057E0.unkC5C];
}

INCLUDE_ASM("asm/nonmatching/code_0805137C", float_default_to_one_if_zero);
INCLUDE_ASM("asm/nonmatching/code_0805137C", float_sign);
INCLUDE_ASM("asm/nonmatching/code_0805137C", float_abs_if_negative);
INCLUDE_ASM("asm/nonmatching/code_0805137C", compute_sqrt_scaled);
INCLUDE_ASM("asm/nonmatching/code_0805137C", init_sprite_affine_matrices_and_state);
INCLUDE_ASM("asm/nonmatching/code_0805137C", sub_08053418);
INCLUDE_ASM("asm/nonmatching/code_0805137C", compute_distance_to_state_position);
INCLUDE_ASM("asm/nonmatching/code_0805137C", compute_triangle_area_3d);

void get_state_position_xyz(s32 *x, s32 *y, s32 *z)
{
    *x = gUnk_03005350.unk40;
    *y = gUnk_03005350.unk44;
    *z = gUnk_03005350.unk48;
}

void sub_0805378C(void)
{
    sub_08053798();
}

INCLUDE_ASM("asm/nonmatching/code_0805137C", sub_08053798);
INCLUDE_ASM("asm/nonmatching/code_0805137C", affine_set_destination_and_compute_transform);
INCLUDE_ASM("asm/nonmatching/code_0805137C", affine_set_source_and_compute_transform);
INCLUDE_ASM("asm/nonmatching/code_0805137C", set_state_float_field);
INCLUDE_ASM("asm/nonmatching/code_0805137C", sub_08053AB8);
INCLUDE_ASM("asm/nonmatching/code_0805137C", sub_08053B94);

void sub_08053BB4(u32 a, u32 b)
{
    get_state_float_as_int(a, b, &gUnk_03005350.unkB4, &gUnk_03005350.unkB8);
}

INCLUDE_ASM("asm/nonmatching/code_0805137C", update_battle_entity_screen_position);
INCLUDE_ASM("asm/nonmatching/code_0805137C", compute_3d_transform_vectors);
INCLUDE_ASM("asm/nonmatching/code_0805137C", get_state_float_as_int);
INCLUDE_ASM("asm/nonmatching/code_0805137C", update_entity_position_and_triggers);
INCLUDE_ASM("asm/nonmatching/code_0805137C", init_affine_transform_viewport);
INCLUDE_ASM("asm/nonmatching/code_0805137C", update_3d_entity_projections);
INCLUDE_ASM("asm/nonmatching/code_0805137C", battle_sequence_dispatch);
INCLUDE_ASM("asm/nonmatching/code_0805137C", sub_08054234);
