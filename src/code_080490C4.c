#include "global.h"

INCLUDE_ASM("asm/nonmatching/code_080490C4", build_bg_tile_entry);
INCLUDE_ASM("asm/nonmatching/code_080490C4", fill_tilemap_rect_0804916C);
INCLUDE_ASM("asm/nonmatching/code_080490C4", copy_tilemap_region);
INCLUDE_ASM("asm/nonmatching/code_080490C4", copy_tilemap_rect_with_offset);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_080492CC);
INCLUDE_ASM("asm/nonmatching/code_080490C4", clear_entity_state);
INCLUDE_ASM("asm/nonmatching/code_080490C4", calculate_oam_affine_matrix);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_080493D4);
INCLUDE_ASM("asm/nonmatching/code_080490C4", advance_sprite_animation_frame);

void sub_080496C8(u8 *dst, u32 size)
{
    u32 i;
    for (i = 0; i < size; i++)
        *dst++ = 0;
}

INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_080496DC);
INCLUDE_ASM("asm/nonmatching/code_080490C4", count_byte_differences);
INCLUDE_ASM("asm/nonmatching/code_080490C4", field_random);
INCLUDE_ASM("asm/nonmatching/code_080490C4", memcpy_u8);
INCLUDE_ASM("asm/nonmatching/code_080490C4", setup_blend_effect);
INCLUDE_ASM("asm/nonmatching/code_080490C4", blend_effect_update);
INCLUDE_ASM("asm/nonmatching/code_080490C4", apply_blend_coefficients);

void sub_08049CB0(u16 color, u32 amount)
{
    palette_blend_to_color_080013A8(color, amount);
}

void sub_08049CC0(void)
{
    copy_obj_palette_to_buffer();
}

INCLUDE_ASM("asm/nonmatching/code_080490C4", setup_palette_fade_to_color);
INCLUDE_ASM("asm/nonmatching/code_080490C4", setup_palette_fade_to_color_with_obj);
INCLUDE_ASM("asm/nonmatching/code_080490C4", run_blend_fade_transition);

void sub_08049E74(u16 a, u32 b, u16 c)
{
    blend_obj_palettes_to_color_0803F684(a, b, c);
}

void sub_08049E88(u16 a, u32 b, u16 c)
{
    blend_obj_palettes_to_color_0803F998(a, b, c);
}

INCLUDE_ASM("asm/nonmatching/code_080490C4", quicksort_u8_array);

void sub_0804A1C4(void)
{
    gGameSubState++;
}

INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804A1D4);
INCLUDE_ASM("asm/nonmatching/code_080490C4", new_game_init);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804A5C0);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804A654);

void sub_0804A670(void)
{
    sub_0804A1C4();
}

INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804A67C);

void sub_0804A694(void)
{
    sub_08050F10();
}

void sub_0804A6A0(void)
{
    sub_0804A1C4();
}

INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804A6AC);

void sub_0804A6D8(void)
{
    init_cursor_state();
    sub_0804A1C4();
}

INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804A6E8);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804A718);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804A8B4);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804A8F8);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804A9B8);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804A9F8);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804AA28);

void sub_0804AAB8(void)
{
    if (run_blend_fade_transition(0))
        sub_0804A1C4();
}

INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804AACC);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804AAF0);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804AB14);

void sub_0804AB74(void)
{
    sub_0804A1C4();
}

INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804AB80);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804ABC8);

void sub_0804AC7C(void)
{
    sub_0804A1C4();
}

INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804AC88);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804AD1C);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804AD68);

void nullsub_0804AE2C(void)
{
}

void nullsub_0804AE30(void)
{
}

INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804AE34);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804AE7C);

void nullsub_0804AF40(void)
{
}

void nullsub_0804AF44(void)
{
}

void nullsub_0804AF48(void)
{
}

INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804AF4C);

void sub_0804AF6C(void)
{
    sub_08058214(gUnk_030057A0.unk14);
}

void sub_0804AF80(void)
{
    if (sub_0805937C())
        handle_battle_end_state_transition();
}

INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804AF94);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804AFBC);
INCLUDE_ASM("asm/nonmatching/code_080490C4", update_battle_entity_status_chars);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804B1FC);
INCLUDE_ASM("asm/nonmatching/code_080490C4", clear_vram_bg2_tiles);
INCLUDE_ASM("asm/nonmatching/code_080490C4", load_room_graphics);
INCLUDE_ASM("asm/nonmatching/code_080490C4", update_blend_effect_from_input);

u32 sub_0804B694(void)
{
    if (battle_sequence_dispatch() == 4)
        return 1;
    return 0;
}

void map_script_run_command(void)
{
    gUnk_030057E0.unkC92 = read_map_script_byte();
    gUnk_030057E0.unkC89 = 0;
    gUnk_030057E0.unkC93 = 0;
    gMapScriptCommands[gUnk_030057E0.unkC92]();
}

u32 sub_0804B6EC(void)
{
    return 0;
}

void nullsub_0804B6F0(void)
{
}

void sub_0804B6F4(void)
{
    sub_0804B70C();
}

void sub_0804B700(void)
{
    sub_0804B70C();
}

void sub_0804B70C(void)
{
    read_map_script_bytes(3);
    gUnk_030057E0.unkC89 = 1;
}

// Not called directly (hidden in the tail of sub_0804B70C).
void sub_0804B72C(void)
{
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804B740(void)
{
    gUnk_030057E0.unkC94[0] = read_map_script_byte();
    gUnk_030057E0.unkC89 = 1;
}

// Not called directly (hidden in the tail of sub_0804B740).
void sub_0804B768(void)
{
    gUnk_030057E0.unkC89 = 1;
}

// Map script command 6: ends the running script (clears the script id and read offset, frees the
// script sprite slots) and gives control back to the player.
void map_script_cmd_end(void)
{
    gUnk_030057E0.unkC88 = 0;
    gUnk_030057E0.unkC89 = 0;
    gUnk_030057E0.unkC93 = 0;
    gUnk_030057E0.unkC8A = 0;
    gUnk_030057E0.unkC8E = 0;
    gUnk_030057E0.unkC5F = 0;
    gUnk_030057E0.unkC60 = 0;
    gUnk_03006D38.unk6 = 0;
    gUnk_03005310.unk38 = 0;
    sub_080496C8(gUnk_030057E0.unkCA4, 16);
    sub_080496C8((u8 *)&gUnk_03006D20, 16);
    gUnk_03002C30[47].unk25 = 1;
    set_battle_state_cancel_flag();
}

// guess: fade to black over n frames (n = script byte, 1..16)
void sub_0804B80C(void)
{
    s32 n;
    gUnk_030057E0.unkC94[0] = read_map_script_byte();
    n = gUnk_030057E0.unkC94[0];
    if (n < 2)
        n = 1;
    if (n > 15)
        n = 16;
    setup_palette_fade_to_color_with_obj(0, 0.0f, 32.0f, n);
    gUnk_030057E0.unkC89 = 1;
}

// guess: fade back in from black over n frames
void sub_0804B860(void)
{
    s32 n;
    gUnk_030057E0.unkC94[0] = read_map_script_byte();
    n = gUnk_030057E0.unkC94[0];
    if (n < 2)
        n = 1;
    if (n > 15)
        n = 16;
    setup_palette_fade_to_color(0, 32.0f, 0.0f, n);
    gUnk_030057E0.unkC89 = 1;
}

// guess: fade to white over n frames
void sub_0804B8B4(void)
{
    s32 n;
    gUnk_030057E0.unkC94[0] = read_map_script_byte();
    n = gUnk_030057E0.unkC94[0];
    if (n < 2)
        n = 1;
    if (n > 15)
        n = 16;
    setup_palette_fade_to_color_with_obj(0x7FFF, 0.0f, 32.0f, n);
    gUnk_030057E0.unkC89 = 1;
}

INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804B90C);

// guess: warp command (sets unkC5B first)
void sub_0804B964(void)
{
    gUnk_030057E0.unkC5B = 1;
    map_script_read_warp();
}

// guess: warp command (clears unkC5B first)
void sub_0804B980(void)
{
    gUnk_030057E0.unkC5B = 0;
    map_script_read_warp();
}

// Reads a warp target from the script: area, unk7FC, unk7FD, player tile x/y. The player keeps
// facing the same way; field_warp_to_area then loads the area.
void map_script_read_warp(void)
{
    gUnk_030057E0.unk7FE = read_map_script_byte();
    gUnk_030057E0.unk7FC = read_map_script_byte();
    gUnk_030057E0.unk7FD = read_map_script_byte();
    gUnk_030057E0.unkC56 = read_map_script_byte();
    gUnk_030057E0.unkC57 = read_map_script_byte();
    gUnk_030057E0.unkC67 = gUnk_03002C30[47].unk20;
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804BA10(void)
{
    gUnk_030057E0.unkC94[0] = read_map_script_byte();
    gUnk_03002C30[47].unk21 = gUnk_030057E0.unkC94[0];
    sub_080493D4(47, gUnk_03002C30[47].unk21);
    gUnk_03002C30[47].unk20 = gUnk_03002C30[47].unk21;
    field_set_player_facing(gUnk_030057E0.unkC94[0]);
}

void sub_0804BA50(void)
{
    gUnk_030057E0.unkC94[0] = gUnk_03002C30[47].unk4;
    gUnk_03002C30[47].unk26 = 0;
    gUnk_03002C30[47].unk28 = 0;
    sub_08047BA8(0x70);
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804BAA0(void)
{
    gUnk_030057E0.unkC94[0] = read_map_script_byte();
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804BAC8(void)
{
    read_map_script_bytes(4);
    *(u8 *)&gHeldKeys = 0; // drops the held buttons (A, B, D-pad...)
    memcpy_u8(gUnk_030057E0.unkC10, gUnk_030057E0.unkC20, 8);
    sub_080496C8(gUnk_030057E0.unkC10, 8);
    gUnk_03002C30[47].unk28 = 0;
    gUnk_03002C30[47].unk26 = 0;
    gUnk_03002C30[47].unk27 = 0;
    gUnk_030057E0.unkC5F = 1;
    setup_battle_sprite_terrain(47, gUnk_030057E0.unkC94[gUnk_03002C30[47].unk26], gUnk_083D28B0[gUnk_030057E0.unkC5C]);
    field_set_player_facing(gUnk_03002C30[47].unk20);
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804BB54(void)
{
    gUnk_030057E0.unkC94[0] = read_map_script_byte();
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804BB7C(void)
{
    read_map_script_bytes(2);
    sub_0805311C((gUnk_030057E0.unkC94[0] << 8) | gUnk_030057E0.unkC94[1]);
}

void sub_0804BBA8(void)
{
    read_map_script_bytes(2);
    sub_08053154((gUnk_030057E0.unkC94[0] << 8) | gUnk_030057E0.unkC94[1]);
}

void sub_0804BBD4(void)
{
    if ((gUnk_030057E0.unk5DC[gUnk_030057E0.unkCB4].unk2 & 0xFFF) - gUnk_030057E0.unkC8E == 0)
        sub_0804D934(&gUnk_030057E0.unk5DC[gUnk_030057E0.unkCB4]);
}

void sub_0804BC20(void)
{
    gUnk_030057E0.unk5DC[gUnk_030057E0.unkCB4].unk4_7 = 0;
    if (gUnk_030057E0.unk5DC[gUnk_030057E0.unkCB4].unk4_6)
    {
        clear_battle_sprite_entry(gUnk_030057E0.unk5DC[gUnk_030057E0.unkCB4].unk4_0 + 49);
        clear_battle_sprite_entry(gUnk_030057E0.unk5DC[gUnk_030057E0.unkCB4].unk4_0 + 91);
    }
}

void sub_0804BC88(void)
{
    struct MapObject *obj;
    read_map_script_bytes(2);
    obj = battle_find_entity_by_id((gUnk_030057E0.unkC94[0] << 8) | gUnk_030057E0.unkC94[1]);
    if (obj != NULL)
        sub_0804D934(obj);
}

void sub_0804BCBC(void)
{
    read_map_script_bytes(3);
    sub_080531EC((gUnk_030057E0.unkC94[0] << 8) | gUnk_030057E0.unkC94[1], gUnk_030057E0.unkC94[2] & 7);
}

void sub_0804BCF8(void)
{
    read_map_script_bytes(2);
    sub_08053234((gUnk_030057E0.unkC94[0] << 8) | gUnk_030057E0.unkC94[1]);
}

void sub_0804BD24(void)
{
    read_map_script_bytes(2);
    gUnk_030057E0.unkC8E = (gUnk_030057E0.unkC94[0] << 8) | gUnk_030057E0.unkC94[1];
    gUnk_030057E0.unkC8A = 0;
    if (battle_find_entity_by_id((gUnk_030057E0.unkC94[0] << 8) | gUnk_030057E0.unkC94[1]) != NULL)
        gUnk_030057E0.unkCB4 = sub_0804D8A8((u16)((gUnk_030057E0.unkC94[0] << 8) | gUnk_030057E0.unkC94[1]));
}

void sub_0804BD8C(void)
{
    read_map_script_bytes(2);
    gUnk_03006D20.unkA = gUnk_030057E0.unk5DC[gUnk_030057E0.unkCB4].unk4_0 + 49;
    set_sprite_anim_and_store(gUnk_03006D20.unkA, gUnk_030057E0.unkC94[0] & 0xF, &gUnk_030057E0.unk5DC[gUnk_030057E0.unkCB4]);
    gUnk_03006D20.unk0 = 0;
    gUnk_03006D20.unk2 = gUnk_030057E0.unkC94[1];
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804BE04(void)
{
    if ((gUnk_030057E0.unk5DC[gUnk_030057E0.unkCB4].unk2 & 0xFFF) == gUnk_030057E0.unkC8E)
        set_sprite_anim_and_store(gUnk_030057E0.unk5DC[gUnk_030057E0.unkCB4].unk4_0 + 49,
                                  gUnk_083D24AC[gUnk_03002C30[47].unk21],
                                  &gUnk_030057E0.unk5DC[gUnk_030057E0.unkCB4]);
}

void sub_0804BE78(void)
{
    gUnk_030057E0.unkC94[0] = read_map_script_byte();
    if ((gUnk_030057E0.unk5DC[gUnk_030057E0.unkCB4].unk2 & 0xFFF) == gUnk_030057E0.unkC8E)
        set_sprite_anim_and_store(gUnk_030057E0.unk5DC[gUnk_030057E0.unkCB4].unk4_0 + 49,
                                  gUnk_030057E0.unkC94[0],
                                  &gUnk_030057E0.unk5DC[gUnk_030057E0.unkCB4]);
}

void sub_0804BEE8(void)
{
    if ((gUnk_030057E0.unk5DC[gUnk_030057E0.unkCB4].unk2 & 0xFFF) == gUnk_030057E0.unkC8E)
    {
        gUnk_03006D20.unkA = gUnk_030057E0.unk5DC[gUnk_030057E0.unkCB4].unk4_0 + 49;
        gUnk_03006D20.unk8 = gUnk_03002C30[gUnk_03006D20.unkA].unk10_8;
        gUnk_03002C30[gUnk_03006D20.unkA].unk28 = 0;
        sub_08047BA8(0x70);
        gUnk_030057E0.unkC89 = 1;
    }
}

void sub_0804BF68(void)
{
    gUnk_030057E0.unkC94[0] = read_map_script_byte();
    if ((gUnk_030057E0.unk5DC[gUnk_030057E0.unkCB4].unk2 & 0xFFF) == gUnk_030057E0.unkC8E)
    {
        gUnk_03006D20.unkA = gUnk_030057E0.unk5DC[gUnk_030057E0.unkCB4].unk4_0 + 49;
        gUnk_03006D20.unk0 = gUnk_030057E0.unkC94[0];
        gUnk_03006D20.unk1 = 0;
        gUnk_03006D20.unk2 = 8;
        gUnk_03006D20.unk3 = 8;
        gUnk_030057E0.unkC89 = 1;
    }
}

void sub_0804BFE0(void)
{
    u8 id;
    read_map_script_bytes(5);
    id = gUnk_030057E0.unkC94[0];
    sub_0804DB84(id, find_next_available_battle_sprite_slot());
    gUnk_03006D20.unkA = sub_0804DBA4(gUnk_030057E0.unkC94[0]) + 79;
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804C02C(void)
{
    u8 id;
    read_map_script_bytes(5);
    id = gUnk_030057E0.unkC94[0];
    sub_0804DB84(id, find_next_available_battle_sprite_slot());
    gUnk_03006D20.unkA = sub_0804DBA4(gUnk_030057E0.unkC94[0]) + 79;
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804C078(void)
{
    read_map_script_bytes(4);
    spawn_battle_medapart_sprite(gUnk_030057E0.unkC94[0], gUnk_030057E0.unkC94[1], gUnk_030057E0.unkC94[2], gUnk_030057E0.unkC94[3]);
}

void sub_0804C0B4(void)
{
    read_map_script_bytes(2);
    set_battle_sprite_animation(gUnk_030057E0.unkC94[0] & 0xF, gUnk_030057E0.unkC94[1]);
}

void sub_0804C0E4(void)
{
    read_map_script_bytes(2);
    gUnk_03006D20.unkA = sub_0804DBA4(gUnk_030057E0.unkC94[0]) + 79;
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804C11C(void)
{
    read_map_script_bytes(2);
    gUnk_03006D20.unkA = sub_0804DBA4(gUnk_030057E0.unkC94[0]) + 79;
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804C154(void)
{
    gUnk_030057E0.unkC94[0] = read_map_script_byte();
    sub_08050508(gUnk_030057E0.unkC94[0]);
}

void sub_0804C174(void)
{
    read_map_script_bytes(2);
    gUnk_03006D20.unkA = sub_0804DBA4(gUnk_030057E0.unkC94[0]) + 79;
    gUnk_03006D20.unk0 = gUnk_030057E0.unkC94[1];
    gUnk_03006D20.unk1 = 0;
    gUnk_03006D20.unk2 = 8;
    gUnk_03006D20.unk3 = 8;
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804C1C4(void)
{
    read_map_script_bytes(3);
    gUnk_03006D20.unkA = sub_0804DBA4(gUnk_030057E0.unkC94[0]) + 79;
    set_sprite_animation_state(gUnk_03006D20.unkA, gUnk_030057E0.unkC94[1] & 0xF);
    gUnk_03006D20.unk0 = 0;
    gUnk_03006D20.unk2 = gUnk_030057E0.unkC94[2];
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804C220(void)
{
    gUnk_030057E0.unkC94[0] = read_map_script_byte();
    gUnk_03006D20.unkA = sub_0804DBA4(gUnk_030057E0.unkC94[0]) + 79;
    gUnk_03006D20.unk8 = gUnk_03002C30[gUnk_03006D20.unkA].unk10_8;
    gUnk_03002C30[gUnk_03006D20.unkA].unk28 = 0;
    sub_08047BA8(0x70);
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804C27C(void)
{
    gUnk_030057E0.unkC94[0] = read_map_script_byte();
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804C2A4(void)
{
    gUnk_030057E0.unkC94[0] = read_map_script_byte();
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804C2CC(void)
{
    u8 id;
    read_map_script_bytes(5);
    id = gUnk_030057E0.unkC94[0];
    sub_0804DB84(id, find_next_available_battle_sprite_slot());
    gUnk_03006D20.unkA = sub_0804DBA4(gUnk_030057E0.unkC94[0]) + 79;
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804C318(void)
{
    if ((gUnk_030057E0.unkC94[0] = read_map_script_byte()) == 1)
        gUnk_030057E0.unkC5D = (gUnk_030057E0.unkC5D & ~0x10) | 0x10;
    else
        gUnk_030057E0.unkC5D &= ~0x10;
}

void sub_0804C360(void)
{
    read_map_script_bytes(2);
    gUnk_03006D20.unkA = sub_0804DBA4(gUnk_030057E0.unkC94[0]) + 79;
    gUnk_030057E0.unkC89 = 1;
}

INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804C398);

// guess: jump by a byte offset, selected by the flag nibble sub_08053288(script id)
void sub_0804C3F8(void)
{
    u16 start = gUnk_030057E0.unkC8A;
    gUnk_030057E0.unkC8A += sub_08053288(gUnk_030057E0.unkC8E);
    gUnk_030057E0.unkC8A = start + read_map_script_byte();
}

// guess: relative jump (read offset += 16-bit big-endian argument, from the opcode's offset)
void sub_0804C42C(void)
{
    u16 start = gUnk_030057E0.unkC8A;
    read_map_script_bytes(2);
    gUnk_030057E0.unkC8A = start + ((gUnk_030057E0.unkC94[0] << 8) | gUnk_030057E0.unkC94[1]);
}

void sub_0804C468(void)
{
    gUnk_030057E0.unkC8C = gUnk_030057E0.unkC8A;
    gUnk_030057E0.unkC94[0] = read_map_script_byte();
    gUnk_030057E0.unkCB5 = 0;
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804C4AC(void)
{
    gUnk_030057E0.unkC8C = gUnk_030057E0.unkC8A;
    gUnk_030057E0.unkC94[0] = read_map_script_byte();
    gUnk_030057E0.unkCB5 = 1;
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804C4F0(void)
{
    gUnk_030057E0.unkC2A = read_map_script_byte();
    gUnk_030057E0.unkC2F = read_map_script_byte();
    gUnk_030057E0.unkC2E = read_map_script_byte();
    if (sub_0804B6EC() == 0)
        gUnk_030057E0.unkC89 = 1;
}

void sub_0804C53C(void)
{
    struct MapObject *obj;
    read_map_script_bytes(3);
    obj = battle_find_entity_by_id((gUnk_030057E0.unkC94[0] << 8) | gUnk_030057E0.unkC94[1]);
    if (obj != NULL && obj->unk4_6)
        set_sprite_anim_and_store(obj->unk4_0 + 49, gUnk_030057E0.unkC94[2], obj);
}

void sub_0804C598(void)
{
    s32 i;
    gUnk_030057E0.unkC94[0] = read_map_script_byte();
    for (i = 0; i <= 3; i++)
    {
        if (sub_0804DBA4(i) != -1 && gUnk_030055A0[sub_0804DBA4(i) + 79].unk0 != 0)
            set_sprite_animation_state(sub_0804DBA4(i) + 79, gUnk_030057E0.unkC94[0]);
    }
}

void sub_0804C5FC(void)
{
    read_map_script_bytes(2);
    if (gUnk_030057E0.unkC94[1] == 0)
        gUnk_030057E0.unkC94[1] = 1;
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804C62C(void)
{
    read_map_script_bytes(2);
    if (gUnk_030057E0.unkC94[1] == 0)
        gUnk_030057E0.unkC94[1] = 1;
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804C65C(void)
{
    read_map_script_bytes(3);
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804C67C(void)
{
    read_map_script_bytes(3);
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804C69C(void)
{
    read_map_script_bytes(2);
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804C6BC(void)
{
    read_map_script_bytes(2);
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804C6DC(void)
{
    gUnk_030057E0.unkC94[0] = read_map_script_byte();
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804C704(void)
{
    gUnk_030057E0.unkC94[0] = read_map_script_byte();
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804C72C(void)
{
    read_map_script_bytes(2);
    if (gUnk_030057E0.unkC94[0] == 0)
    {
        gUnk_030057E0.unkCBC += gUnk_030057E0.unkC94[1];
        if (gUnk_030057E0.unkCBD > 32)
            gUnk_030057E0.unkCBD = 32;
    }
    else
    {
        gUnk_030057E0.unkCBD += gUnk_030057E0.unkC94[1];
        if (gUnk_030057E0.unkCBD > 32)
            gUnk_030057E0.unkCBD = 32;
    }
}

void sub_0804C790(void)
{
    read_map_script_bytes(2);
    if (gUnk_030057E0.unkC94[0] == 0)
    {
        gUnk_030057E0.unkCBC -= gUnk_030057E0.unkC94[1];
        if (gUnk_030057E0.unkCBC < 0)
            gUnk_030057E0.unkCBC = 0;
    }
    else
    {
        gUnk_030057E0.unkCBD -= gUnk_030057E0.unkC94[1];
        if (gUnk_030057E0.unkCBD < 0)
            gUnk_030057E0.unkCBD = 0;
    }
}

void sub_0804C7F4(void)
{
    gUnk_030057E0.unkC94[0] = read_map_script_byte();
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804C81C(void)
{
    s32 i;
    gUnk_030057E0.unkC94[0] = read_map_script_byte();
    for (i = 0; i <= 3; i++)
    {
        if (sub_0804DBA4(i) != -1 && gUnk_030055A0[sub_0804DBA4(i) + 79].unk0 != 0)
        {
            gUnk_03002C30[sub_0804DBA4(i) + 79].unk26 = gUnk_030057E0.unkC94[0];
            gUnk_03002C30[sub_0804DBA4(i) + 79].unk27 = 0;
            gUnk_03002C30[sub_0804DBA4(i) + 79].unk28 = 8;
            gUnk_03002C30[sub_0804DBA4(i) + 79].unk29 = 8;
        }
    }
    gUnk_030057E0.unkC89 = 1;
}

void nullsub_0804C8DC(void)
{
}

void sub_0804C8E0(void)
{
    read_map_script_bytes(2);
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804C900(void)
{
    sub_08047BA8(read_map_script_byte());
}

void sub_0804C914(void)
{
    gUnk_030057E0.unkC94[0] = read_map_script_byte();
    dispatch_jump_table_29(1, gUnk_030057E0.unkC94[0]);
}

void sub_0804C938(void)
{
    dispatch_jump_table_29(2, 0);
}

void sub_0804C948(void)
{
    sub_08047BC0(0x78);
}

void sub_0804C954(void)
{
    gUnk_030057E0.unkC94[0] = read_map_script_byte();
    dispatch_jump_table_29(3, gUnk_030057E0.unkC94[0]);
}

void sub_0804C978(void)
{
    dispatch_jump_table_29(4, 0);
}

void sub_0804C988(void)
{
    gUnk_030057E0.unkC8C = gUnk_030057E0.unkC8A;
    read_map_script_bytes(2);
    if (gUnk_030057E0.unkC94[0] != gUnk_03002C30[47].unk21)
        gUnk_030057E0.unkC8A = gUnk_030057E0.unkC8C + gUnk_030057E0.unkC94[1];
}

// guess: opcode 0x4B, skip ahead by arg2 unless the player has at least arg1 of item arg0
void sub_0804C9DC(void)
{
    s32 n;
    gUnk_030057E0.unkC8C = gUnk_030057E0.unkC8A;
    read_map_script_bytes(3);
    n = sub_08047D8C(gUnk_030057E0.unkC94[0]);
    if (n == 0 || n < gUnk_030057E0.unkC94[1])
        gUnk_030057E0.unkC8A = gUnk_030057E0.unkC8C + gUnk_030057E0.unkC94[2];
}

void sub_0804CA38(void)
{
    u32 r;
    gUnk_030057E0.unkC8C = gUnk_030057E0.unkC8A;
    read_map_script_bytes(3);
    r = lookup_position_table_value(gUnk_030057E0.unkC94[0], gUnk_030057E0.unkC94[1]);
    if (r != -1)
        gUnk_030057E0.unkC60 = r;
    else
        gUnk_030057E0.unkC8A = gUnk_030057E0.unkC8C + gUnk_030057E0.unkC94[2];
}

// guess: opcode 0x4D, skip ahead by arg1 unless medal arg0 is owned (find_medal_slot_by_id)
void sub_0804CA9C(void)
{
    gUnk_030057E0.unkC8C = gUnk_030057E0.unkC8A;
    read_map_script_bytes(2);
    if (sub_08047DB0(gUnk_030057E0.unkC94[0]) == 0)
        gUnk_030057E0.unkC8A = gUnk_030057E0.unkC8C + gUnk_030057E0.unkC94[1];
}

// guess: opcode 0x4E, skip ahead by arg2 if money (gMoney) < 16-bit arg * 10
void sub_0804CAE8(void)
{
    gUnk_030057E0.unkC8C = gUnk_030057E0.unkC8A;
    read_map_script_bytes(3);
    if ((s32)get_money() < ((gUnk_030057E0.unkC94[0] << 8) | gUnk_030057E0.unkC94[1]) * 10)
        gUnk_030057E0.unkC8A = gUnk_030057E0.unkC8C + gUnk_030057E0.unkC94[2];
}

void sub_0804CB48(void)
{
    gUnk_030057E0.unkC8C = gUnk_030057E0.unkC8A;
    read_map_script_bytes(1);
    if (gUnk_03005310.unk39 == 2)
        gUnk_030057E0.unkC8A = gUnk_030057E0.unkC8C + gUnk_030057E0.unkC94[0];
}

INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804CB90);

void sub_0804CC10(void)
{
    gUnk_030057E0.unkC8C = gUnk_030057E0.unkC8A;
    read_map_script_bytes(2);
    if (gUnk_030057E0.unkC94[0] - 70 != gUnk_030057E0.unkC60)
        gUnk_030057E0.unkC8A = gUnk_030057E0.unkC8C + gUnk_030057E0.unkC94[1];
}

void sub_0804CC60(void)
{
    gUnk_030057E0.unkC8C = gUnk_030057E0.unkC8A;
    read_map_script_bytes(2);
    if (field_random(0xFF) & 0xF)
        gUnk_030057E0.unkC8A = gUnk_030057E0.unkC8C + gUnk_030057E0.unkC94[2];
}

void sub_0804CCA8(void)
{
    read_map_script_bytes(2);
    if (gUnk_030057E0.unkC94[0] != 0)
        gUnk_030057E0.unkC94[0]--;
    gUnk_030057E0.unkC38[gUnk_030057E0.unkC94[0]] = gUnk_030057E0.unkC94[1];
    decompress_battle_tile_graphics();
    switch (gUnk_03006F40[1])
    {
    case 1:
    case 3:
    case 5:
    case 6:
        dma_load_obj_palettes_08048664();
        break;
    default:
        dma_load_battle_palettes();
        break;
    }
}

// Not called directly (hidden in the tail of sub_0804CCA8).
void nullsub_0804CD14(void)
{
}

// Not called directly (hidden in the tail of sub_0804CCA8).
void nullsub_0804CD18(void)
{
}

// Not called directly (hidden in the tail of sub_0804CCA8).
void sub_0804CD1C(void)
{
    gUnk_030057E0.unkC89 = 1;
}

// Not called directly (hidden in the tail of sub_0804CCA8).
void nullsub_0804CD30(void)
{
}

// Not called directly (hidden in the tail of sub_0804CCA8).
void nullsub_0804CD34(void)
{
}

void sub_0804CD38(void)
{
    read_map_script_bytes(1);
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804CD58(void)
{
    gUnk_030057E0.unkC94[0] = read_map_script_byte();
    gUnk_03002C30[48].unk21 = gUnk_030057E0.unkC94[0];
    gUnk_03002C30[48].unk20 = gUnk_030057E0.unkC94[0];
    sub_080493D4(48, sub_080502B4(48, gUnk_030057E0.unkC94[0] + gUnk_03002C30[48].unk2B * 4));
    set_battle_state_byte_c83(gUnk_030057E0.unkC94[0]);
}

void sub_0804CDB8(void)
{
    gUnk_030057E0.unkC8C = gUnk_030057E0.unkC8A;
    read_map_script_bytes(1);
    if (sub_08047F50() <= 2)
        gUnk_030057E0.unkC8A = gUnk_030057E0.unkC8C + gUnk_030057E0.unkC94[1];
}

// guess: opcode 0x5C, skip ahead by arg1 unless an assembled Medabot (0x030017A0) is all model arg0
void sub_0804CDF8(void)
{
    gUnk_030057E0.unkC8C = gUnk_030057E0.unkC8A;
    read_map_script_bytes(2);
    if (sub_08047F70(gUnk_030057E0.unkC94[0]) == 0)
        gUnk_030057E0.unkC8A = gUnk_030057E0.unkC8C + gUnk_030057E0.unkC94[1];
}

// Opcode 0x5D. Bit 7 set: arg 1 sets / else clears unkC5D bit 5; else unkC33 (Medawatch
// menu flag) = arg & 0xF. Runtime: sets 0x03006413 to 1 when Dad gives Ikki the Medawatch.
void map_script_cmd_set_medawatch_flag(void)
{
    read_map_script_bytes(1);
    if (gUnk_030057E0.unkC94[0] & 0x80)
    {
        if ((gUnk_030057E0.unkC94[0] & 0xF) == 1)
            gUnk_030057E0.unkC5D = (gUnk_030057E0.unkC5D & ~0x20) | 0x20;
        else
            gUnk_030057E0.unkC5D &= ~0x20;
    }
    else
    {
        gUnk_030057E0.unkC33 = gUnk_030057E0.unkC94[0] & 0xF;
    }
}

void sub_0804CEAC(void)
{
    if ((gUnk_030057E0.unkC94[0] = read_map_script_byte()) == 1)
        gUnk_030057E0.unkC5D = (gUnk_030057E0.unkC5D & ~0x01) | 0x01;
    else
        gUnk_030057E0.unkC5D &= ~0x01;
}

void sub_0804CEF4(void)
{
    gUnk_030057E0.unkC2C = read_map_script_byte();
}

void sub_0804CF10(void)
{
    u16 id;
    struct MapObject *obj;
    read_map_script_bytes(3);
    switch (gUnk_030057E0.unkC94[0])
    {
    case 0:
        if (sub_0804DBA4(gUnk_030057E0.unkC94[2]) != -1)
            sub_0804D9AC(sub_0804DBA4(gUnk_030057E0.unkC94[2]) + 79);
        break;
    case 1:
        id = (gUnk_030057E0.unkC94[1] << 8) | gUnk_030057E0.unkC94[2];
        if (id != 0)
        {
            obj = battle_find_entity_by_id(id);
            if (obj != NULL)
                sub_0804D9AC(obj->unk4_0 + 49);
        }
        else
        {
            sub_0804D9AC(gUnk_030057E0.unk5DC[gUnk_030057E0.unkCB4].unk4_0 + 49);
        }
        break;
    }
}

void sub_0804CFC0(void)
{
    sub_0804DB34();
}

void sub_0804CFCC(void)
{
    sub_08044B58();
}

void sub_0804CFD8(void)
{
    read_map_script_bytes(3);
    init_sprite_affine_matrices_and_state(gUnk_030057E0.unkC94[0],
        (gUnk_030057E0.unkC94[1] & 0x7F) * 16 + gUnk_030057E0.unkC48,
        (gUnk_030057E0.unkC94[2] & 0x7F) * 16 + gUnk_030057E0.unkC4A, 0);
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804D038(void)
{
    init_battle_sprites();
}

void nullsub_0804D044(void)
{
}

void sub_0804D048(void)
{
    read_map_script_bytes(2);
    gUnk_03006D20.unkA = sub_0804DBA4(gUnk_030057E0.unkC94[0]) + 79;
    gUnk_03002C30[gUnk_03006D20.unkA].unk26 = 0;
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804D094(void)
{
    read_map_script_bytes(2);
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804D0B4(void)
{
    struct MapObject *obj;
    read_map_script_bytes(2);
    obj = &gUnk_030057E0.unk5DC[gUnk_030057E0.unkCB4];
    if ((obj->unk2 & 0xFFF) == ((gUnk_030057E0.unkC94[0] << 8) | gUnk_030057E0.unkC94[1]))
        set_tile_data(obj->x, obj->y, 0);
}

