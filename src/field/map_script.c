// The map script interpreter: map_script_run_command reads one opcode and calls its handler from
// gMapScriptCommands (0x083D20AC, 137 entries, all in this file, ROM order = opcode order), then the
// script byte readers read_map_script_byte / read_map_script_bytes and the map object / script variable
// helpers (unkCA4) the commands use. Commands drive the field (warps,
// NPCs, flags, messages, sounds, battles) through field/script_helpers, text/message and the engine.

#include "global.h"

static s32 sub_0804D8A8(u16 id);
static void sub_0804D934(struct MapObject *obj);
static void sub_0804D9AC(u8 slot);
static void sub_0804DB34(void);

static void sub_0804B70C(void);
static void map_script_read_warp(void);

void map_script_run_command(void) {
    gUnk_030057E0.unkC92 = read_map_script_byte();
    gUnk_030057E0.unkC89 = 0;
    gUnk_030057E0.unkC93 = 0;
    gMapScriptCommands[gUnk_030057E0.unkC92]();
}

u32 sub_0804B6EC(void) {
    return 0;
}

void nullsub_0804B6F0(void) {}

void sub_0804B6F4(void) {
    sub_0804B70C();
}

void sub_0804B700(void) {
    sub_0804B70C();
}

static void sub_0804B70C(void) {
    read_map_script_bytes(3);
    gUnk_030057E0.unkC89 = 1;
}

// Not called directly (hidden in the tail of sub_0804B70C).
void sub_0804B72C(void) {
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804B740(void) {
    gUnk_030057E0.unkC94[0] = read_map_script_byte();
    gUnk_030057E0.unkC89 = 1;
}

// Not called directly (hidden in the tail of sub_0804B740).
void sub_0804B768(void) {
    gUnk_030057E0.unkC89 = 1;
}

// Map script command 6: ends the running script (clears the script id and read offset, frees the
// script sprite slots) and gives control back to the player.
void map_script_cmd_end(void) {
    gUnk_030057E0.unkC88 = 0;
    gUnk_030057E0.unkC89 = 0;
    gUnk_030057E0.unkC93 = 0;
    gUnk_030057E0.unkC8A = 0;
    gUnk_030057E0.unkC8E = 0;
    gUnk_030057E0.unkC5F = 0;
    gUnk_030057E0.unkC60 = 0;
    gUnk_03006D38.unk6 = 0;
    gUnk_03005310.unk38 = 0;
    memzero_bytes(gUnk_030057E0.unkCA4, 16);
    memzero_bytes((u8 *)&gUnk_03006D20, 16);
    gSpriteEntries[47].unk25 = 1;
    set_battle_state_cancel_flag();
}

// guess: fade to black over n frames (n = script byte, 1..16)
void sub_0804B80C(void) {
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
void sub_0804B860(void) {
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
void sub_0804B8B4(void) {
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

void sub_0804B90C(void) {
    s32 n;
    gUnk_030057E0.unkC94[0] = read_map_script_byte();
    n = gUnk_030057E0.unkC94[0];
    if (n < 2)
        n = 1;
    if (n > 15)
        n = 16;
    setup_palette_fade_to_color(0x7FFF, 32.0f, 0.0f, n);
    gUnk_030057E0.unkC89 = 1;
}

// guess: warp command (sets unkC5B first)
void sub_0804B964(void) {
    gUnk_030057E0.unkC5B = 1;
    map_script_read_warp();
}

// guess: warp command (clears unkC5B first)
void sub_0804B980(void) {
    gUnk_030057E0.unkC5B = 0;
    map_script_read_warp();
}

// Reads a warp target from the script: area, unk7FC, unk7FD, player tile x/y. The player keeps
// facing the same way; field_warp_to_area then loads the area.
static void map_script_read_warp(void) {
    gUnk_030057E0.unk7FE = read_map_script_byte();
    gUnk_030057E0.unk7FC = read_map_script_byte();
    gUnk_030057E0.unk7FD = read_map_script_byte();
    gUnk_030057E0.player_tile_x = read_map_script_byte();
    gUnk_030057E0.player_tile_y = read_map_script_byte();
    gUnk_030057E0.player_facing = gSpriteEntries[47].unk20;
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804BA10(void) {
    gUnk_030057E0.unkC94[0] = read_map_script_byte();
    gSpriteEntries[47].unk21 = gUnk_030057E0.unkC94[0];
    sprite_anim_start(47, gSpriteEntries[47].unk21);
    gSpriteEntries[47].unk20 = gSpriteEntries[47].unk21;
    field_set_player_facing(gUnk_030057E0.unkC94[0]);
}

void sub_0804BA50(void) {
    gUnk_030057E0.unkC94[0] = gSpriteEntries[47].unk4;
    gSpriteEntries[47].unk26 = 0;
    gSpriteEntries[47].unk28 = 0;
    field_play_sound_effect(0x70);
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804BAA0(void) {
    gUnk_030057E0.unkC94[0] = read_map_script_byte();
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804BAC8(void) {
    read_map_script_bytes(4);
    *(u8 *)&gHeldKeys = 0; // drops the held buttons (A, B, D-pad...)
    memcpy_u8(gUnk_030057E0.unkC10, gUnk_030057E0.unkC20, 8);
    memzero_bytes(gUnk_030057E0.unkC10, 8);
    gSpriteEntries[47].unk28 = 0;
    gSpriteEntries[47].unk26 = 0;
    gSpriteEntries[47].unk27 = 0;
    gUnk_030057E0.unkC5F = 1;
    script_sprite_begin_walk(47, gUnk_030057E0.unkC94[gSpriteEntries[47].unk26],
                             gUnk_083D28B0[gUnk_030057E0.player_form]);
    field_set_player_facing(gSpriteEntries[47].unk20);
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804BB54(void) {
    gUnk_030057E0.unkC94[0] = read_map_script_byte();
    gUnk_030057E0.unkC89 = 1;
}

void map_script_cmd_clear_event_flag(void) {
    read_map_script_bytes(2);
    event_flag_clear((gUnk_030057E0.unkC94[0] << 8) | gUnk_030057E0.unkC94[1]);
}

void map_script_cmd_set_event_flag(void) {
    read_map_script_bytes(2);
    event_flag_set((gUnk_030057E0.unkC94[0] << 8) | gUnk_030057E0.unkC94[1]);
}

void sub_0804BBD4(void) {
    if ((gUnk_030057E0.unk5DC[gUnk_030057E0.unkCB4].unk2 & 0xFFF) - gUnk_030057E0.unkC8E == 0)
        sub_0804D934(&gUnk_030057E0.unk5DC[gUnk_030057E0.unkCB4]);
}

void sub_0804BC20(void) {
    gUnk_030057E0.unk5DC[gUnk_030057E0.unkCB4].unk4_7 = 0;
    if (gUnk_030057E0.unk5DC[gUnk_030057E0.unkCB4].unk4_6) {
        sprite_entry_clear(gUnk_030057E0.unk5DC[gUnk_030057E0.unkCB4].unk4_0 + 49);
        sprite_entry_clear(gUnk_030057E0.unk5DC[gUnk_030057E0.unkCB4].unk4_0 + 91);
    }
}

void sub_0804BC88(void) {
    struct MapObject *obj;
    read_map_script_bytes(2);
    obj = battle_find_entity_by_id((gUnk_030057E0.unkC94[0] << 8) | gUnk_030057E0.unkC94[1]);
    if (obj != NULL)
        sub_0804D934(obj);
}

void map_script_cmd_set_event_counter(void) {
    read_map_script_bytes(3);
    event_counter_set((gUnk_030057E0.unkC94[0] << 8) | gUnk_030057E0.unkC94[1], gUnk_030057E0.unkC94[2] & 7);
}

void map_script_cmd_increment_event_counter(void) {
    read_map_script_bytes(2);
    event_counter_increment((gUnk_030057E0.unkC94[0] << 8) | gUnk_030057E0.unkC94[1]);
}

void sub_0804BD24(void) {
    read_map_script_bytes(2);
    gUnk_030057E0.unkC8E = (gUnk_030057E0.unkC94[0] << 8) | gUnk_030057E0.unkC94[1];
    gUnk_030057E0.unkC8A = 0;
    if (battle_find_entity_by_id((gUnk_030057E0.unkC94[0] << 8) | gUnk_030057E0.unkC94[1]) != NULL)
        gUnk_030057E0.unkCB4 = sub_0804D8A8((u16)((gUnk_030057E0.unkC94[0] << 8) | gUnk_030057E0.unkC94[1]));
}

void sub_0804BD8C(void) {
    read_map_script_bytes(2);
    gUnk_03006D20.unkA = gUnk_030057E0.unk5DC[gUnk_030057E0.unkCB4].unk4_0 + 49;
    set_sprite_anim_and_store(gUnk_03006D20.unkA, gUnk_030057E0.unkC94[0] & 0xF,
                              &gUnk_030057E0.unk5DC[gUnk_030057E0.unkCB4]);
    gUnk_03006D20.unk0 = 0;
    gUnk_03006D20.unk2 = gUnk_030057E0.unkC94[1];
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804BE04(void) {
    if ((gUnk_030057E0.unk5DC[gUnk_030057E0.unkCB4].unk2 & 0xFFF) == gUnk_030057E0.unkC8E)
        set_sprite_anim_and_store(gUnk_030057E0.unk5DC[gUnk_030057E0.unkCB4].unk4_0 + 49,
                                  gUnk_083D24AC[gSpriteEntries[47].unk21], &gUnk_030057E0.unk5DC[gUnk_030057E0.unkCB4]);
}

void sub_0804BE78(void) {
    gUnk_030057E0.unkC94[0] = read_map_script_byte();
    if ((gUnk_030057E0.unk5DC[gUnk_030057E0.unkCB4].unk2 & 0xFFF) == gUnk_030057E0.unkC8E)
        set_sprite_anim_and_store(gUnk_030057E0.unk5DC[gUnk_030057E0.unkCB4].unk4_0 + 49, gUnk_030057E0.unkC94[0],
                                  &gUnk_030057E0.unk5DC[gUnk_030057E0.unkCB4]);
}

void sub_0804BEE8(void) {
    if ((gUnk_030057E0.unk5DC[gUnk_030057E0.unkCB4].unk2 & 0xFFF) == gUnk_030057E0.unkC8E) {
        gUnk_03006D20.unkA = gUnk_030057E0.unk5DC[gUnk_030057E0.unkCB4].unk4_0 + 49;
        gUnk_03006D20.unk8 = gSpriteEntries[gUnk_03006D20.unkA].unk10_8;
        gSpriteEntries[gUnk_03006D20.unkA].unk28 = 0;
        field_play_sound_effect(0x70);
        gUnk_030057E0.unkC89 = 1;
    }
}

void sub_0804BF68(void) {
    gUnk_030057E0.unkC94[0] = read_map_script_byte();
    if ((gUnk_030057E0.unk5DC[gUnk_030057E0.unkCB4].unk2 & 0xFFF) == gUnk_030057E0.unkC8E) {
        gUnk_03006D20.unkA = gUnk_030057E0.unk5DC[gUnk_030057E0.unkCB4].unk4_0 + 49;
        gUnk_03006D20.unk0 = gUnk_030057E0.unkC94[0];
        gUnk_03006D20.unk1 = 0;
        gUnk_03006D20.unk2 = 8;
        gUnk_03006D20.unk3 = 8;
        gUnk_030057E0.unkC89 = 1;
    }
}

void sub_0804BFE0(void) {
    u8 id;
    read_map_script_bytes(5);
    id = gUnk_030057E0.unkC94[0];
    script_object_set_slot(id, find_free_script_sprite_slot());
    gUnk_03006D20.unkA = script_object_slot(gUnk_030057E0.unkC94[0]) + 79;
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804C02C(void) {
    u8 id;
    read_map_script_bytes(5);
    id = gUnk_030057E0.unkC94[0];
    script_object_set_slot(id, find_free_script_sprite_slot());
    gUnk_03006D20.unkA = script_object_slot(gUnk_030057E0.unkC94[0]) + 79;
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804C078(void) {
    read_map_script_bytes(4);
    spawn_script_sprite(gUnk_030057E0.unkC94[0], gUnk_030057E0.unkC94[1], gUnk_030057E0.unkC94[2],
                        gUnk_030057E0.unkC94[3]);
}

void sub_0804C0B4(void) {
    read_map_script_bytes(2);
    script_object_set_direction(gUnk_030057E0.unkC94[0] & 0xF, gUnk_030057E0.unkC94[1]);
}

void sub_0804C0E4(void) {
    read_map_script_bytes(2);
    gUnk_03006D20.unkA = script_object_slot(gUnk_030057E0.unkC94[0]) + 79;
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804C11C(void) {
    read_map_script_bytes(2);
    gUnk_03006D20.unkA = script_object_slot(gUnk_030057E0.unkC94[0]) + 79;
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804C154(void) {
    gUnk_030057E0.unkC94[0] = read_map_script_byte();
    despawn_script_sprite(gUnk_030057E0.unkC94[0]);
}

void sub_0804C174(void) {
    read_map_script_bytes(2);
    gUnk_03006D20.unkA = script_object_slot(gUnk_030057E0.unkC94[0]) + 79;
    gUnk_03006D20.unk0 = gUnk_030057E0.unkC94[1];
    gUnk_03006D20.unk1 = 0;
    gUnk_03006D20.unk2 = 8;
    gUnk_03006D20.unk3 = 8;
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804C1C4(void) {
    read_map_script_bytes(3);
    gUnk_03006D20.unkA = script_object_slot(gUnk_030057E0.unkC94[0]) + 79;
    set_sprite_animation_state(gUnk_03006D20.unkA, gUnk_030057E0.unkC94[1] & 0xF);
    gUnk_03006D20.unk0 = 0;
    gUnk_03006D20.unk2 = gUnk_030057E0.unkC94[2];
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804C220(void) {
    gUnk_030057E0.unkC94[0] = read_map_script_byte();
    gUnk_03006D20.unkA = script_object_slot(gUnk_030057E0.unkC94[0]) + 79;
    gUnk_03006D20.unk8 = gSpriteEntries[gUnk_03006D20.unkA].unk10_8;
    gSpriteEntries[gUnk_03006D20.unkA].unk28 = 0;
    field_play_sound_effect(0x70);
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804C27C(void) {
    gUnk_030057E0.unkC94[0] = read_map_script_byte();
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804C2A4(void) {
    gUnk_030057E0.unkC94[0] = read_map_script_byte();
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804C2CC(void) {
    u8 id;
    read_map_script_bytes(5);
    id = gUnk_030057E0.unkC94[0];
    script_object_set_slot(id, find_free_script_sprite_slot());
    gUnk_03006D20.unkA = script_object_slot(gUnk_030057E0.unkC94[0]) + 79;
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804C318(void) {
    if ((gUnk_030057E0.unkC94[0] = read_map_script_byte()) == 1)
        gUnk_030057E0.unkC5D = (gUnk_030057E0.unkC5D & ~0x10) | 0x10;
    else
        gUnk_030057E0.unkC5D &= ~0x10;
}

void sub_0804C360(void) {
    read_map_script_bytes(2);
    gUnk_03006D20.unkA = script_object_slot(gUnk_030057E0.unkC94[0]) + 79;
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804C398(void) {
    u16 r;
    s16 d;
    gUnk_030057E0.unkC8C = gUnk_030057E0.unkC8A;
    read_map_script_bytes(3);
    r = field_medapart_counts(gUnk_030057E0.unkC94[0], gUnk_030057E0.unkC94[1]);
    d = ((r & 0xFF00) >> 8) - (r & 0xFF);
    if (d == 0)
        gUnk_030057E0.unkC8A = gUnk_030057E0.unkC8C + gUnk_030057E0.unkC94[2];
}

// guess: jump by a byte offset, selected by the flag nibble event_counter_get(script id)
void sub_0804C3F8(void) {
    u16 start = gUnk_030057E0.unkC8A;
    gUnk_030057E0.unkC8A += event_counter_get(gUnk_030057E0.unkC8E);
    gUnk_030057E0.unkC8A = start + read_map_script_byte();
}

// guess: relative jump (read offset += 16-bit big-endian argument, from the opcode's offset)
void sub_0804C42C(void) {
    u16 start = gUnk_030057E0.unkC8A;
    read_map_script_bytes(2);
    gUnk_030057E0.unkC8A = start + ((gUnk_030057E0.unkC94[0] << 8) | gUnk_030057E0.unkC94[1]);
}

void sub_0804C468(void) {
    gUnk_030057E0.unkC8C = gUnk_030057E0.unkC8A;
    gUnk_030057E0.unkC94[0] = read_map_script_byte();
    gUnk_030057E0.unkCB5 = 0;
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804C4AC(void) {
    gUnk_030057E0.unkC8C = gUnk_030057E0.unkC8A;
    gUnk_030057E0.unkC94[0] = read_map_script_byte();
    gUnk_030057E0.unkCB5 = 1;
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804C4F0(void) {
    gUnk_030057E0.unkC2A = read_map_script_byte();
    gUnk_030057E0.unkC2F = read_map_script_byte();
    gUnk_030057E0.unkC2E = read_map_script_byte();
    if (sub_0804B6EC() == 0)
        gUnk_030057E0.unkC89 = 1;
}

void sub_0804C53C(void) {
    struct MapObject *obj;
    read_map_script_bytes(3);
    obj = battle_find_entity_by_id((gUnk_030057E0.unkC94[0] << 8) | gUnk_030057E0.unkC94[1]);
    if (obj != NULL && obj->unk4_6)
        set_sprite_anim_and_store(obj->unk4_0 + 49, gUnk_030057E0.unkC94[2], obj);
}

void sub_0804C598(void) {
    s32 i;
    gUnk_030057E0.unkC94[0] = read_map_script_byte();
    for (i = 0; i <= 3; i++) {
        if (script_object_slot(i) != -1 && gUnk_030055A0[script_object_slot(i) + 79].unk0 != 0)
            set_sprite_animation_state(script_object_slot(i) + 79, gUnk_030057E0.unkC94[0]);
    }
}

void sub_0804C5FC(void) {
    read_map_script_bytes(2);
    if (gUnk_030057E0.unkC94[1] == 0)
        gUnk_030057E0.unkC94[1] = 1;
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804C62C(void) {
    read_map_script_bytes(2);
    if (gUnk_030057E0.unkC94[1] == 0)
        gUnk_030057E0.unkC94[1] = 1;
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804C65C(void) {
    read_map_script_bytes(3);
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804C67C(void) {
    read_map_script_bytes(3);
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804C69C(void) {
    read_map_script_bytes(2);
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804C6BC(void) {
    read_map_script_bytes(2);
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804C6DC(void) {
    gUnk_030057E0.unkC94[0] = read_map_script_byte();
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804C704(void) {
    gUnk_030057E0.unkC94[0] = read_map_script_byte();
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804C72C(void) {
    read_map_script_bytes(2);
    if (gUnk_030057E0.unkC94[0] == 0) {
        gUnk_030057E0.unkCBC += gUnk_030057E0.unkC94[1];
        if (gUnk_030057E0.unkCBD > 32)
            gUnk_030057E0.unkCBD = 32;
    } else {
        gUnk_030057E0.unkCBD += gUnk_030057E0.unkC94[1];
        if (gUnk_030057E0.unkCBD > 32)
            gUnk_030057E0.unkCBD = 32;
    }
}

void sub_0804C790(void) {
    read_map_script_bytes(2);
    if (gUnk_030057E0.unkC94[0] == 0) {
        gUnk_030057E0.unkCBC -= gUnk_030057E0.unkC94[1];
        if (gUnk_030057E0.unkCBC < 0)
            gUnk_030057E0.unkCBC = 0;
    } else {
        gUnk_030057E0.unkCBD -= gUnk_030057E0.unkC94[1];
        if (gUnk_030057E0.unkCBD < 0)
            gUnk_030057E0.unkCBD = 0;
    }
}

void sub_0804C7F4(void) {
    gUnk_030057E0.unkC94[0] = read_map_script_byte();
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804C81C(void) {
    s32 i;
    gUnk_030057E0.unkC94[0] = read_map_script_byte();
    for (i = 0; i <= 3; i++) {
        if (script_object_slot(i) != -1 && gUnk_030055A0[script_object_slot(i) + 79].unk0 != 0) {
            gSpriteEntries[script_object_slot(i) + 79].unk26 = gUnk_030057E0.unkC94[0];
            gSpriteEntries[script_object_slot(i) + 79].unk27 = 0;
            gSpriteEntries[script_object_slot(i) + 79].unk28 = 8;
            gSpriteEntries[script_object_slot(i) + 79].unk29 = 8;
        }
    }
    gUnk_030057E0.unkC89 = 1;
}

void nullsub_0804C8DC(void) {}

void sub_0804C8E0(void) {
    read_map_script_bytes(2);
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804C900(void) {
    field_play_sound_effect(read_map_script_byte());
}

void sub_0804C914(void) {
    gUnk_030057E0.unkC94[0] = read_map_script_byte();
    field_update_music(1, gUnk_030057E0.unkC94[0]);
}

void sub_0804C938(void) {
    field_update_music(2, 0);
}

void sub_0804C948(void) {
    field_stop_songs(0x78);
}

void sub_0804C954(void) {
    gUnk_030057E0.unkC94[0] = read_map_script_byte();
    field_update_music(3, gUnk_030057E0.unkC94[0]);
}

void sub_0804C978(void) {
    field_update_music(4, 0);
}

void sub_0804C988(void) {
    gUnk_030057E0.unkC8C = gUnk_030057E0.unkC8A;
    read_map_script_bytes(2);
    if (gUnk_030057E0.unkC94[0] != gSpriteEntries[47].unk21)
        gUnk_030057E0.unkC8A = gUnk_030057E0.unkC8C + gUnk_030057E0.unkC94[1];
}

// guess: opcode 0x4B, skip ahead by arg2 unless the player has at least arg1 of item arg0
void sub_0804C9DC(void) {
    s32 n;
    gUnk_030057E0.unkC8C = gUnk_030057E0.unkC8A;
    read_map_script_bytes(3);
    n = field_item_quantity(gUnk_030057E0.unkC94[0]);
    if (n == 0 || n < gUnk_030057E0.unkC94[1])
        gUnk_030057E0.unkC8A = gUnk_030057E0.unkC8C + gUnk_030057E0.unkC94[2];
}

void sub_0804CA38(void) {
    u32 r;
    gUnk_030057E0.unkC8C = gUnk_030057E0.unkC8A;
    read_map_script_bytes(3);
    r = team_equipped_part_legs_value(gUnk_030057E0.unkC94[0], gUnk_030057E0.unkC94[1]);
    if (r != -1)
        gUnk_030057E0.unkC60 = r;
    else
        gUnk_030057E0.unkC8A = gUnk_030057E0.unkC8C + gUnk_030057E0.unkC94[2];
}

// guess: opcode 0x4D, skip ahead by arg1 unless medal arg0 is owned (find_medal_slot_by_id)
void sub_0804CA9C(void) {
    gUnk_030057E0.unkC8C = gUnk_030057E0.unkC8A;
    read_map_script_bytes(2);
    if (field_find_medal_slot(gUnk_030057E0.unkC94[0]) == 0)
        gUnk_030057E0.unkC8A = gUnk_030057E0.unkC8C + gUnk_030057E0.unkC94[1];
}

// guess: opcode 0x4E, skip ahead by arg2 if money (gMoney) < 16-bit arg * 10
void sub_0804CAE8(void) {
    gUnk_030057E0.unkC8C = gUnk_030057E0.unkC8A;
    read_map_script_bytes(3);
    if ((s32)get_money() < ((gUnk_030057E0.unkC94[0] << 8) | gUnk_030057E0.unkC94[1]) * 10)
        gUnk_030057E0.unkC8A = gUnk_030057E0.unkC8C + gUnk_030057E0.unkC94[2];
}

void sub_0804CB48(void) {
    gUnk_030057E0.unkC8C = gUnk_030057E0.unkC8A;
    read_map_script_bytes(1);
    if (gUnk_03005310.unk39 == 2)
        gUnk_030057E0.unkC8A = gUnk_030057E0.unkC8C + gUnk_030057E0.unkC94[0];
}

void sub_0804CB90(void) {
    struct Unk_030057E0 *s = &gUnk_030057E0;
    s->unkC8C = s->unkC8A;
    read_map_script_bytes(3);
    if (s->unkC94[0] == 0) {
        if (s->unkCBC >= s->unkC94[1])
            return;
    } else if (s->unkCBD >= s->unkC94[1])
        return;
    gUnk_030057E0.unkC8A = gUnk_030057E0.unkC8C + gUnk_030057E0.unkC94[2];
}

void sub_0804CC10(void) {
    gUnk_030057E0.unkC8C = gUnk_030057E0.unkC8A;
    read_map_script_bytes(2);
    if (gUnk_030057E0.unkC94[0] - 70 != gUnk_030057E0.unkC60)
        gUnk_030057E0.unkC8A = gUnk_030057E0.unkC8C + gUnk_030057E0.unkC94[1];
}

void sub_0804CC60(void) {
    gUnk_030057E0.unkC8C = gUnk_030057E0.unkC8A;
    read_map_script_bytes(2);
    if (field_random(0xFF) & 0xF)
        gUnk_030057E0.unkC8A = gUnk_030057E0.unkC8C + gUnk_030057E0.unkC94[2];
}

void sub_0804CCA8(void) {
    read_map_script_bytes(2);
    if (gUnk_030057E0.unkC94[0] != 0)
        gUnk_030057E0.unkC94[0]--;
    gUnk_030057E0.unkC38[gUnk_030057E0.unkC94[0]] = gUnk_030057E0.unkC94[1];
    area_load_sprite_sheets();
    switch (gBlendEffect.type) {
    case 1:
    case 3:
    case 5:
    case 6:
        area_load_sprite_palettes_now();
        break;
    default:
        area_load_sprite_palettes();
        break;
    }
}

// Not called directly (hidden in the tail of sub_0804CCA8).
void nullsub_0804CD14(void) {}

// Not called directly (hidden in the tail of sub_0804CCA8).
void nullsub_0804CD18(void) {}

// Not called directly (hidden in the tail of sub_0804CCA8).
void sub_0804CD1C(void) {
    gUnk_030057E0.unkC89 = 1;
}

// Not called directly (hidden in the tail of sub_0804CCA8).
void nullsub_0804CD30(void) {}

// Not called directly (hidden in the tail of sub_0804CCA8).
void nullsub_0804CD34(void) {}

void sub_0804CD38(void) {
    read_map_script_bytes(1);
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804CD58(void) {
    gUnk_030057E0.unkC94[0] = read_map_script_byte();
    gSpriteEntries[48].unk21 = gUnk_030057E0.unkC94[0];
    gSpriteEntries[48].unk20 = gUnk_030057E0.unkC94[0];
    sprite_anim_start(48, sprite_walk_anim_id(48, gUnk_030057E0.unkC94[0] + gSpriteEntries[48].unk2B * 4));
    set_battle_state_byte_c83(gUnk_030057E0.unkC94[0]);
}

void sub_0804CDB8(void) {
    gUnk_030057E0.unkC8C = gUnk_030057E0.unkC8A;
    read_map_script_bytes(1);
    if (team_count_complete_bots() <= 2)
        gUnk_030057E0.unkC8A = gUnk_030057E0.unkC8C + gUnk_030057E0.unkC94[1];
}

// guess: opcode 0x5C, skip ahead by arg1 unless an assembled Medabot (0x030017A0) is all model arg0
void sub_0804CDF8(void) {
    gUnk_030057E0.unkC8C = gUnk_030057E0.unkC8A;
    read_map_script_bytes(2);
    if (team_has_full_part_set(gUnk_030057E0.unkC94[0]) == 0)
        gUnk_030057E0.unkC8A = gUnk_030057E0.unkC8C + gUnk_030057E0.unkC94[1];
}

// Opcode 0x5D. Bit 7 set: arg 1 sets / else clears unkC5D bit 5; else unkC33 (Medawatch
// menu flag) = arg & 0xF. Runtime: sets 0x03006413 to 1 when Dad gives Ikki the Medawatch.
void map_script_cmd_set_medawatch_flag(void) {
    read_map_script_bytes(1);
    if (gUnk_030057E0.unkC94[0] & 0x80) {
        if ((gUnk_030057E0.unkC94[0] & 0xF) == 1)
            gUnk_030057E0.unkC5D = (gUnk_030057E0.unkC5D & ~0x20) | 0x20;
        else
            gUnk_030057E0.unkC5D &= ~0x20;
    } else {
        gUnk_030057E0.unkC33 = gUnk_030057E0.unkC94[0] & 0xF;
    }
}

void sub_0804CEAC(void) {
    if ((gUnk_030057E0.unkC94[0] = read_map_script_byte()) == 1)
        gUnk_030057E0.unkC5D = (gUnk_030057E0.unkC5D & ~0x01) | 0x01;
    else
        gUnk_030057E0.unkC5D &= ~0x01;
}

void sub_0804CEF4(void) {
    gUnk_030057E0.unkC2C = read_map_script_byte();
}

void sub_0804CF10(void) {
    u16 id;
    struct MapObject *obj;
    read_map_script_bytes(3);
    switch (gUnk_030057E0.unkC94[0]) {
    case 0:
        if (script_object_slot(gUnk_030057E0.unkC94[2]) != -1)
            sub_0804D9AC(script_object_slot(gUnk_030057E0.unkC94[2]) + 79);
        break;
    case 1:
        id = (gUnk_030057E0.unkC94[1] << 8) | gUnk_030057E0.unkC94[2];
        if (id != 0) {
            obj = battle_find_entity_by_id(id);
            if (obj != NULL)
                sub_0804D9AC(obj->unk4_0 + 49);
        } else {
            sub_0804D9AC(gUnk_030057E0.unk5DC[gUnk_030057E0.unkCB4].unk4_0 + 49);
        }
        break;
    }
}

void sub_0804CFC0(void) {
    sub_0804DB34();
}

void sub_0804CFCC(void) {
    give_starter_medabot();
}

void map_script_cmd_start_field_effect(void) {
    read_map_script_bytes(3);
    field_effect_start(gUnk_030057E0.unkC94[0], (gUnk_030057E0.unkC94[1] & 0x7F) * 16 + gUnk_030057E0.map_origin_x,
                       (gUnk_030057E0.unkC94[2] & 0x7F) * 16 + gUnk_030057E0.map_origin_y, 0);
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804D038(void) {
    init_battle_sprites();
}

void nullsub_0804D044(void) {}

void sub_0804D048(void) {
    read_map_script_bytes(2);
    gUnk_03006D20.unkA = script_object_slot(gUnk_030057E0.unkC94[0]) + 79;
    gSpriteEntries[gUnk_03006D20.unkA].unk26 = 0;
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804D094(void) {
    read_map_script_bytes(2);
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804D0B4(void) {
    struct MapObject *obj;
    read_map_script_bytes(2);
    obj = &gUnk_030057E0.unk5DC[gUnk_030057E0.unkCB4];
    if ((obj->unk2 & 0xFFF) == ((gUnk_030057E0.unkC94[0] << 8) | gUnk_030057E0.unkC94[1]))
        set_tile_data(obj->x, obj->y, 0);
}

void sub_0804D10C(void) {
    read_map_script_bytes(2);
    if (gUnk_030057E0.unkC94[0] == gUnk_030057E0.unkC5B) {
        gUnk_030057E0.unkC5B = gUnk_030057E0.unkC94[0] ^ 1;
        field_set_player_sprite_visible(gUnk_030057E0.unkC5B);
        if (gUnk_030057E0.unkC94[1] == 0) {
            if (gUnk_030057E0.unkC5B) {
                memcpy_u8(gUnk_030057E0.unkC18, gUnk_030057E0.unkC10, 8);
            } else {
                memcpy_u8(gUnk_030057E0.unkC10, gUnk_030057E0.unkC18, 8);
                gUnk_030057E0.unkC10[0] = 0;
                gUnk_030057E0.unkC10[1] = 0;
                gUnk_030057E0.unkC10[2] = 0;
                gUnk_030057E0.unkC10[3] = 0;
                gUnk_030057E0.unkC10[4] = 0;
                gUnk_030057E0.unkC10[5] = 0;
                gUnk_030057E0.unkC10[6] = 0;
                gUnk_030057E0.unkC10[7] = 0;
            }
        }
    }
}

void nullsub_0804D1B8(void) {}

void sub_0804D1BC(void) {
    gUnk_030057E0.unk7FF = read_map_script_byte();
}

void sub_0804D1D8(void) {
    read_map_script_bytes(5);
    script_object_set_slot(gUnk_030057E0.unkC94[0], find_free_script_sprite_slot());
    gUnk_03006D20.unkA = script_object_slot(gUnk_030057E0.unkC94[0]) + 79;
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804D224(void) {
    read_map_script_bytes(2);
    gUnk_03006D20.unkA = script_object_slot(gUnk_030057E0.unkC94[0]) + 79;
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804D25C(void) {
    read_map_script_bytes(5);
    script_object_set_slot(gUnk_030057E0.unkC94[0], find_free_script_sprite_slot());
    gUnk_03006D20.unkA = script_object_slot(gUnk_030057E0.unkC94[0]) + 79;
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804D2A8(void) {
    read_map_script_bytes(2);
    gUnk_03006D20.unkA = script_object_slot(gUnk_030057E0.unkC94[0]) + 79;
    gUnk_030057E0.unkC89 = 1;
}

// Not called directly (hidden in the tail of sub_0804D2A8).
void sub_0804D2E0(void) {
    gUnk_030057E0.unkC89 = 1;
}

// Not called directly (hidden in the tail of sub_0804D2A8).
void sub_0804D2F4(void) {
    gUnk_030057E0.unkC89 = 1;
}

// Not called directly (hidden in the tail of sub_0804D2A8).
void sub_0804D308(void) {
    gUnk_030057E0.unkC89 = 1;
}

// Not called directly (hidden in the tail of sub_0804D2A8).
void sub_0804D31C(void) {
    gUnk_030057E0.unkC89 = 1;
}

// Not called directly (hidden in the tail of sub_0804D2A8).
void nullsub_0804D330(void) {}

// Not called directly (hidden in the tail of sub_0804D2A8).
void nullsub_0804D334(void) {}

// Not called directly (hidden in the tail of sub_0804D2A8).
void sub_0804D338(void) {
    gUnk_030057E0.unkC89 = 1;
}

// Not called directly (hidden in the tail of sub_0804D2A8).
void nullsub_0804D34C(void) {}

void sub_0804D350(void) {
    gUnk_030057E0.unkC8C = gUnk_030057E0.unkC8A;
    read_map_script_bytes(2);
    gUnk_03006D38.unk0 = gUnk_030057E0.unkC94[0];
    if (team_count_complete_bots() > 2)
        gUnk_030057E0.unkC89 = 1;
    else
        gUnk_030057E0.unkC8A = gUnk_030057E0.unkC8C + gUnk_030057E0.unkC94[1];
}

void sub_0804D3B4(void) {
    gUnk_03006D38.unk1 = read_map_script_byte();
    gUnk_030057E0.unkC89 = 1;
}

// Not called directly (hidden in the tail of sub_0804D3B4).
void sub_0804D3D8(void) {
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804D3EC(void) {
    gUnk_030057E0.unkC8C = gUnk_030057E0.unkC8A;
    read_map_script_bytes(3);
    if ((u8)((u16)field_medapart_counts(gUnk_030057E0.unkC94[0], gUnk_030057E0.unkC94[1]) >> 8) == 0)
        gUnk_030057E0.unkC8A = gUnk_030057E0.unkC8C + gUnk_030057E0.unkC94[2];
}

void nullsub_0804D440(void) {}

void sub_0804D444(void) {
    gUnk_030057E0.unkC32 = read_map_script_byte();
}

void sub_0804D460(void) {
    gUnk_030057E0.unkC94[0] = read_map_script_byte();
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804D488(void) {
    gUnk_030057E0.unkC94[0] = read_map_script_byte();
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804D4B0(void) {
    gUnk_030064A0.unk52 = 0;
    memzero_bytes(gUnk_030064A0.unk2, 8);
    memzero_bytes(gUnk_030064A0.unkA, 8);
    memzero_bytes(gUnk_030064A0.unk12[0], 64);
    memzero_bytes(&gUnk_030064A0.unk52, 1);
    memzero_bytes(&gUnk_030064A0.unk53, 1);
    memzero_bytes(gUnk_030064A0.unk54, 8);
    gUnk_030057E0.unkC92 = read_map_script_byte();
    gUnk_030057E0.unkC89 = 0;
    gUnk_030057E0.unkC93 = 0;
    gMapScriptCommands[gUnk_030057E0.unkC92]();
}

void sub_0804D534(void) {
    read_map_script_bytes(8);
    memcpy_u8(gUnk_030057E0.unkC94, gUnk_030064A0.unk12[gUnk_030064A0.unk52++], 8);
    gUnk_030057E0.unkC92 = read_map_script_byte();
    gUnk_030057E0.unkC89 = 0;
    gUnk_030057E0.unkC93 = 0;
    gMapScriptCommands[gUnk_030057E0.unkC92]();
}

// Not called directly (hidden in the tail of sub_0804D534).
void sub_0804D590(void) {
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804D5A4(void) {
    u8 slot;

    read_map_script_bytes(2);
    if (gUnk_030057E0.unkC94[0] & 0x10) {
        if (gUnk_030057E0.unkC94[0] & 0x40) {
            if (gUnk_030057E0.unkC94[1] == 0)
                sprite_set_blend_from_kind(47);
            else
                sprite_set_blend(47, gUnk_030057E0.unkC94[1]);
        } else if (gUnk_030057E0.unkC94[0] & 0x20) {
            if ((gUnk_030057E0.unk5DC[gUnk_030057E0.unkCB4].unk2 & 0xFFF) == gUnk_030057E0.unkC8E) {
                slot = gUnk_030057E0.unk5DC[gUnk_030057E0.unkCB4].unk4_0 + 49;
                if (gUnk_030057E0.unkC94[1] == 0)
                    sprite_set_blend_from_kind(slot);
                else
                    sprite_set_blend(slot, gUnk_030057E0.unkC94[1]);
            }
        } else {
            if (gUnk_030057E0.unkC94[1] == 0)
                sprite_set_blend_from_kind(script_object_slot(gUnk_030057E0.unkC94[0] & 0xF) + 79);
            else
                script_object_set_blend(gUnk_030057E0.unkC94[0] & 0xF, gUnk_030057E0.unkC94[1]);
        }
    } else {
        if (gUnk_030057E0.unkC94[0] & 0x40) {
            sprite_set_priority(47, gUnk_030057E0.unkC94[1]);
        } else if (gUnk_030057E0.unkC94[0] & 0x20) {
            if ((gUnk_030057E0.unk5DC[gUnk_030057E0.unkCB4].unk2 & 0xFFF) == gUnk_030057E0.unkC8E) {
                slot = gUnk_030057E0.unk5DC[gUnk_030057E0.unkCB4].unk4_0 + 49;
                sprite_set_priority(slot, gUnk_030057E0.unkC94[1]);
            }
        } else {
            script_object_set_priority(gUnk_030057E0.unkC94[0] & 0xF, gUnk_030057E0.unkC94[1]);
        }
    }
}

void sub_0804D70C(void) {
    read_map_script_bytes(1);
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804D72C(void) {
    struct Unk_030064A0 *v = &gUnk_030064A0;
    v->unk52 = 0;
    memzero_bytes(v->unk2, 8);
    memzero_bytes(v->unkA, 8);
    memzero_bytes(v->unk12[0], 64);
}

void sub_0804D760(void) {
    read_map_script_bytes(8);
    memcpy_u8(gUnk_030057E0.unkC94, gUnk_030064A0.unk12[gUnk_030064A0.unk52++], 8);
}

// Not called directly (hidden in the tail of sub_0804D760).
void sub_0804D798(void) {
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804D7AC(void) {
    u16 start = gUnk_030057E0.unkC8A;
    read_map_script_bytes(2);
    if (gUnk_030057E0.unkC76 == 0)
        gUnk_030057E0.unkC8A = start + ((gUnk_030057E0.unkC94[0] << 8) | gUnk_030057E0.unkC94[1]);
}

u8 read_map_script_byte(void) {
    u8 *data = gMapScriptData;
    u32 offsets = (u16)((data[0] | (data[1] << 8)) - 0x4000);
    u16 banks = (data[2] | (data[3] << 8)) - 0x4000;
    u16 script = gUnk_030057E0.unkC8E;
    u8 *header;
    u16 start;
    u8 bank;
    u32 pos;
    u8 ret;

    offsets += script * 2;
    header = data + 0x4000;
    start = header[offsets];
    offsets++;
    start = (start | (header[offsets] << 8)) - 0x4000;
    bank = header[banks + script];
    pos = start + gUnk_030057E0.unkC8A;
    ret = data[pos + (bank << 14)];
    gUnk_030057E0.unkC8A++;
    return ret;
}

void read_map_script_bytes(u8 n) {
    s32 i;
    for (i = 0; i < n; i++)
        gUnk_030057E0.unkC94[i] = read_map_script_byte();
}

static s32 sub_0804D8A8(u16 id) {
    s32 i;
    for (i = 0; i < 64; i++)
        if ((gUnk_030057E0.unk5DC[i].unk2 & 0xFFF) == id)
            return i;
    if (i == 64)
        return -1;
}

struct MapObject *battle_find_entity_by_id(u16 id) {
    s32 i;
    for (i = 0; i < 64; i++)
        if ((gUnk_030057E0.unk5DC[i].unk2 & 0xFFF) == id)
            return &gUnk_030057E0.unk5DC[i];
    if (i == 64)
        return NULL;
}

static void sub_0804D934(struct MapObject *obj) {
    u8 *raw = (u8 *)obj;
    const u8 *tiles = gUnk_084045A8[gUnk_030057E0.unk7FE];
    set_tile_data(obj->x, obj->y, tiles[obj->y * (gUnk_030057E0.unk800 >> 1) + obj->x]);
    if (obj->unk4_6) {
        sprite_entry_clear(obj->unk4_0 + 49);
        sprite_entry_clear(obj->unk4_0 + 91);
    }
    memzero_bytes(raw, 8);
}

static void sub_0804D9AC(u8 i) {
    sprite_entry_clear(48);
    sprite_entry_clear(90);
    memcpy_u8(&gSpriteEntries[i], &gSpriteEntries[48], 0x40);
    memcpy_u8(&gUnk_030055A0[i], &gUnk_030055A0[48], 4);
    gUnk_030057E0.unkC76 = 1;
    gUnk_030057E0.unkC6E = gSpriteEntries[48].unk2 + gBg1Scroll.x;
    gUnk_030057E0.unkC70 = gSpriteEntries[48].unk4 + gBg1Scroll.y;
    gUnk_030057E0.unkC72 = field_pixel_x_to_tile(gUnk_030057E0.unkC6E);
    gUnk_030057E0.unkC73 = field_pixel_y_to_tile(gUnk_030057E0.unkC70);
    gUnk_030057E0.unkC84 = gSpriteEntries[48].unk2B;
    follower_clear_scroll_dir();
    sprite_anim_start(48, sprite_walk_anim_id(48, gSpriteEntries[48].unk2B * 4 + gSpriteEntries[48].unk21));
    sprite_entry_init(90, 0xCC0C, 0x90, 0xE, 1);
    gSpriteEntries[90].unk2 = gSpriteEntries[48].unk2;
    gSpriteEntries[90].unk4 = gSpriteEntries[48].unk4 - 5;
    gSpriteEntries[90].unkC_8 = gSpriteEntries[48].unkC_8;
    gSpriteEntries[90].unk10_8 = gSpriteEntries[48].unk10_8 - 5;
    update_battle_direction_indicator(1);
    gUnk_030057E0.unkC5E = gUnk_030057E0.unkC5D;
    gUnk_030057E0.unkC5D = 0xDF;
}

static void sub_0804DB34(void) {
    sprite_entry_clear(48);
    sprite_entry_clear(90);
    gUnk_030057E0.unkC76 = 0;
    gUnk_030057E0.unkC5D = gUnk_030057E0.unkC5E;
}

void script_object_free_slot(u8 i) {
    gUnk_030057E0.unkCA4[i] = 0;
}

void script_object_set_slot(u8 i, u8 v) {
    gUnk_030057E0.unkCA4[i] = v + 1;
}

u32 script_object_slot(u8 i) {
    return gUnk_030057E0.unkCA4[i] - 1;
}
