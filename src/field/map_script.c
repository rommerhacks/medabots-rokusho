// The map script interpreter: map_script_run_command reads one opcode and calls its handler from
// gMapScriptCommands (0x083D20AC, 137 entries, all in this file, ROM order = opcode order), then the
// script byte readers read_map_script_byte / read_map_script_bytes and the map object / script variable
// helpers (script_object_slots) the commands use. Commands drive the field (warps,
// NPCs, flags, messages, sounds, battles) through field/script_helpers, text/message and the engine.

#include "global.h"
#include "constants/sprites.h"

static s32 map_object_index_by_id(u16 id);
static void map_object_remove(struct MapObject *obj);
static void follower_attach(u8 slot);
static void follower_detach(void);

static void map_script_read_message_args(void);
static void map_script_read_warp(void);

void map_script_run_command(void) {
    gFieldWork.cmd = read_map_script_byte();
    gFieldWork.cmd_busy = 0;
    gFieldWork.cmd_step = 0;
    gMapScriptCommands[gFieldWork.cmd]();
}

u32 map_script_always_zero(void) {
    return 0;
}

void map_script_cmd_nop(void) {}

void map_script_cmd_message(void) {
    map_script_read_message_args();
}

void map_script_cmd_skip_message(void) {
    map_script_read_message_args();
}

static void map_script_read_message_args(void) {
    read_map_script_bytes(3);
    gFieldWork.cmd_busy = 1;
}

// Not called directly (hidden in the tail of map_script_read_message_args).
void map_script_cmd_wait_window_close(void) {
    gFieldWork.cmd_busy = 1;
}

void map_script_cmd_wait(void) {
    gFieldWork.cmd_args[0] = read_map_script_byte();
    gFieldWork.cmd_busy = 1;
}

// Not called directly (hidden in the tail of map_script_cmd_wait).
void map_script_cmd_wait_button(void) {
    gFieldWork.cmd_busy = 1;
}

// Map script command 6: ends the running script (clears the script id and read offset, frees the
// script sprite slots) and gives control back to the player.
void map_script_cmd_end(void) {
    gFieldWork.script_running = 0;
    gFieldWork.cmd_busy = 0;
    gFieldWork.cmd_step = 0;
    gFieldWork.script_pos = 0;
    gFieldWork.script_id = 0;
    gFieldWork.script_field_update = 0;
    gFieldWork.unkC60 = 0;
    gFieldSceneParams.bot_gender = 0;
    gFieldState.unk38 = 0;
    memzero_bytes(gFieldWork.script_object_slots, 16);
    memzero_bytes((u8 *)&gScriptCmdWork, 16);
    gSpriteEntries[47].unk25 = 1;
    set_battle_state_cancel_flag();
}

// Opcodes 7-0xA: fade to / back from black or white over n frames (n = script byte, 1..16).
void map_script_cmd_fade_out_black(void) {
    s32 n;
    gFieldWork.cmd_args[0] = read_map_script_byte();
    n = gFieldWork.cmd_args[0];
    if (n < 2)
        n = 1;
    if (n > 15)
        n = 16;
    setup_palette_fade_to_color_with_obj(0, 0.0f, 32.0f, n);
    gFieldWork.cmd_busy = 1;
}

void map_script_cmd_fade_in_black(void) {
    s32 n;
    gFieldWork.cmd_args[0] = read_map_script_byte();
    n = gFieldWork.cmd_args[0];
    if (n < 2)
        n = 1;
    if (n > 15)
        n = 16;
    setup_palette_fade_to_color(0, 32.0f, 0.0f, n);
    gFieldWork.cmd_busy = 1;
}

void map_script_cmd_fade_out_white(void) {
    s32 n;
    gFieldWork.cmd_args[0] = read_map_script_byte();
    n = gFieldWork.cmd_args[0];
    if (n < 2)
        n = 1;
    if (n > 15)
        n = 16;
    setup_palette_fade_to_color_with_obj(0x7FFF, 0.0f, 32.0f, n);
    gFieldWork.cmd_busy = 1;
}

void map_script_cmd_fade_in_white(void) {
    s32 n;
    gFieldWork.cmd_args[0] = read_map_script_byte();
    n = gFieldWork.cmd_args[0];
    if (n < 2)
        n = 1;
    if (n > 15)
        n = 16;
    setup_palette_fade_to_color(0x7FFF, 32.0f, 0.0f, n);
    gFieldWork.cmd_busy = 1;
}

// Opcodes 0xB / 0xC: warp to another area with the player shown / hidden.
void map_script_cmd_warp(void) {
    gFieldWork.player_visible = 1;
    map_script_read_warp();
}

void map_script_cmd_warp_hidden(void) {
    gFieldWork.player_visible = 0;
    map_script_read_warp();
}

// Reads a warp target from the script: area, unk7FC, unk7FD, player tile x/y. The player keeps
// facing the same way; field_warp_to_area then loads the area.
static void map_script_read_warp(void) {
    gFieldWork.area_id = read_map_script_byte();
    gFieldWork.unk7FC = read_map_script_byte();
    gFieldWork.unk7FD = read_map_script_byte();
    gFieldWork.player_tile_x = read_map_script_byte();
    gFieldWork.player_tile_y = read_map_script_byte();
    gFieldWork.player_facing = gSpriteEntries[47].unk20;
    gFieldWork.cmd_busy = 1;
}

void map_script_cmd_set_player_facing(void) {
    gFieldWork.cmd_args[0] = read_map_script_byte();
    gSpriteEntries[47].unk21 = gFieldWork.cmd_args[0];
    sprite_anim_start(47, gSpriteEntries[47].unk21);
    gSpriteEntries[47].unk20 = gSpriteEntries[47].unk21;
    field_set_player_facing(gFieldWork.cmd_args[0]);
}

void map_script_cmd_player_hop(void) {
    gFieldWork.cmd_args[0] = gSpriteEntries[47].y;
    gSpriteEntries[47].unk26 = 0;
    gSpriteEntries[47].unk28 = 0;
    field_play_sound_effect(0x70);
    gFieldWork.cmd_busy = 1;
}

void map_script_cmd_player_jump(void) {
    gFieldWork.cmd_args[0] = read_map_script_byte();
    gFieldWork.cmd_busy = 1;
}

void map_script_cmd_player_walk(void) {
    read_map_script_bytes(4);
    *(u8 *)&gHeldKeys = 0; // drops the held buttons (A, B, D-pad...)
    memcpy_u8(gFieldWork.tile_actions, gFieldWork.script_tile_actions, 8);
    memzero_bytes(gFieldWork.tile_actions, 8);
    gSpriteEntries[47].unk28 = 0;
    gSpriteEntries[47].unk26 = 0;
    gSpriteEntries[47].unk27 = 0;
    gFieldWork.script_field_update = 1;
    script_sprite_begin_walk(47, gFieldWork.cmd_args[gSpriteEntries[47].unk26],
                             gPlayerFormScriptSpeedIds[gFieldWork.player_form]);
    field_set_player_facing(gSpriteEntries[47].unk20);
    gFieldWork.cmd_busy = 1;
}

void map_script_cmd_set_player_form(void) {
    gFieldWork.cmd_args[0] = read_map_script_byte();
    gFieldWork.cmd_busy = 1;
}

void map_script_cmd_clear_event_flag(void) {
    read_map_script_bytes(2);
    event_flag_clear((gFieldWork.cmd_args[0] << 8) | gFieldWork.cmd_args[1]);
}

void map_script_cmd_set_event_flag(void) {
    read_map_script_bytes(2);
    event_flag_set((gFieldWork.cmd_args[0] << 8) | gFieldWork.cmd_args[1]);
}

void map_script_cmd_remove_self(void) {
    if ((gFieldWork.objects[gFieldWork.script_object].unk2 & 0xFFF) - gFieldWork.script_id == 0)
        map_object_remove(&gFieldWork.objects[gFieldWork.script_object]);
}

void map_script_cmd_hide_self(void) {
    gFieldWork.objects[gFieldWork.script_object].unk4_7 = 0;
    if (gFieldWork.objects[gFieldWork.script_object].unk4_6) {
        sprite_entry_clear(gFieldWork.objects[gFieldWork.script_object].unk4_0 + 49);
        sprite_entry_clear(gFieldWork.objects[gFieldWork.script_object].unk4_0 + 91);
    }
}

void map_script_cmd_remove_object(void) {
    struct MapObject *obj;
    read_map_script_bytes(2);
    obj = map_object_find_by_id((gFieldWork.cmd_args[0] << 8) | gFieldWork.cmd_args[1]);
    if (obj != NULL)
        map_object_remove(obj);
}

void map_script_cmd_set_event_counter(void) {
    read_map_script_bytes(3);
    event_counter_set((gFieldWork.cmd_args[0] << 8) | gFieldWork.cmd_args[1], gFieldWork.cmd_args[2] & 7);
}

void map_script_cmd_increment_event_counter(void) {
    read_map_script_bytes(2);
    event_counter_increment((gFieldWork.cmd_args[0] << 8) | gFieldWork.cmd_args[1]);
}

// Opcode 0x19: makes map object id (arg0 << 8 | arg1) the script's "self" object (script_id / script_object).
void map_script_cmd_select_object(void) {
    read_map_script_bytes(2);
    gFieldWork.script_id = (gFieldWork.cmd_args[0] << 8) | gFieldWork.cmd_args[1];
    gFieldWork.script_pos = 0;
    if (map_object_find_by_id((gFieldWork.cmd_args[0] << 8) | gFieldWork.cmd_args[1]) != NULL)
        gFieldWork.script_object =
            map_object_index_by_id((u16)((gFieldWork.cmd_args[0] << 8) | gFieldWork.cmd_args[1]));
}

void map_script_cmd_self_anim(void) {
    read_map_script_bytes(2);
    gScriptCmdWork.sprite_slot = gFieldWork.objects[gFieldWork.script_object].unk4_0 + 49;
    set_sprite_anim_and_store(gScriptCmdWork.sprite_slot, gFieldWork.cmd_args[0] & 0xF,
                              &gFieldWork.objects[gFieldWork.script_object]);
    gScriptCmdWork.counter = 0;
    gScriptCmdWork.timer = gFieldWork.cmd_args[1];
    gFieldWork.cmd_busy = 1;
}

void map_script_cmd_self_face_player(void) {
    if ((gFieldWork.objects[gFieldWork.script_object].unk2 & 0xFFF) == gFieldWork.script_id)
        set_sprite_anim_and_store(gFieldWork.objects[gFieldWork.script_object].unk4_0 + 49,
                                  gOppositeDirection[gSpriteEntries[47].unk21],
                                  &gFieldWork.objects[gFieldWork.script_object]);
}

void map_script_cmd_self_set_anim(void) {
    gFieldWork.cmd_args[0] = read_map_script_byte();
    if ((gFieldWork.objects[gFieldWork.script_object].unk2 & 0xFFF) == gFieldWork.script_id)
        set_sprite_anim_and_store(gFieldWork.objects[gFieldWork.script_object].unk4_0 + 49, gFieldWork.cmd_args[0],
                                  &gFieldWork.objects[gFieldWork.script_object]);
}

void map_script_cmd_self_hop(void) {
    if ((gFieldWork.objects[gFieldWork.script_object].unk2 & 0xFFF) == gFieldWork.script_id) {
        gScriptCmdWork.sprite_slot = gFieldWork.objects[gFieldWork.script_object].unk4_0 + 49;
        gScriptCmdWork.hop_base_y = gSpriteEntries[gScriptCmdWork.sprite_slot].pos_y;
        gSpriteEntries[gScriptCmdWork.sprite_slot].unk28 = 0;
        field_play_sound_effect(0x70);
        gFieldWork.cmd_busy = 1;
    }
}

void map_script_cmd_self_blink(void) {
    gFieldWork.cmd_args[0] = read_map_script_byte();
    if ((gFieldWork.objects[gFieldWork.script_object].unk2 & 0xFFF) == gFieldWork.script_id) {
        gScriptCmdWork.sprite_slot = gFieldWork.objects[gFieldWork.script_object].unk4_0 + 49;
        gScriptCmdWork.counter = gFieldWork.cmd_args[0];
        gScriptCmdWork.blink_phase = 0;
        gScriptCmdWork.timer = 8;
        gScriptCmdWork.timer_reload = 8;
        gFieldWork.cmd_busy = 1;
    }
}

void map_script_cmd_actor_spawn_walk(void) {
    u8 id;
    read_map_script_bytes(5);
    id = gFieldWork.cmd_args[0];
    script_object_set_slot(id, find_free_script_sprite_slot());
    gScriptCmdWork.sprite_slot = script_object_slot(gFieldWork.cmd_args[0]) + 79;
    gFieldWork.cmd_busy = 1;
}

void map_script_cmd_actor_spawn_walk_2(void) {
    u8 id;
    read_map_script_bytes(5);
    id = gFieldWork.cmd_args[0];
    script_object_set_slot(id, find_free_script_sprite_slot());
    gScriptCmdWork.sprite_slot = script_object_slot(gFieldWork.cmd_args[0]) + 79;
    gFieldWork.cmd_busy = 1;
}

void map_script_cmd_actor_spawn(void) {
    read_map_script_bytes(4);
    spawn_script_sprite(gFieldWork.cmd_args[0], gFieldWork.cmd_args[1], gFieldWork.cmd_args[2], gFieldWork.cmd_args[3]);
}

void map_script_cmd_actor_set_facing(void) {
    read_map_script_bytes(2);
    script_object_set_direction(gFieldWork.cmd_args[0] & 0xF, gFieldWork.cmd_args[1]);
}

void map_script_cmd_actor_walk(void) {
    read_map_script_bytes(2);
    gScriptCmdWork.sprite_slot = script_object_slot(gFieldWork.cmd_args[0]) + 79;
    gFieldWork.cmd_busy = 1;
}

void map_script_cmd_actor_walk_2(void) {
    read_map_script_bytes(2);
    gScriptCmdWork.sprite_slot = script_object_slot(gFieldWork.cmd_args[0]) + 79;
    gFieldWork.cmd_busy = 1;
}

void map_script_cmd_actor_despawn(void) {
    gFieldWork.cmd_args[0] = read_map_script_byte();
    despawn_script_sprite(gFieldWork.cmd_args[0]);
}

void map_script_cmd_actor_blink(void) {
    read_map_script_bytes(2);
    gScriptCmdWork.sprite_slot = script_object_slot(gFieldWork.cmd_args[0]) + 79;
    gScriptCmdWork.counter = gFieldWork.cmd_args[1];
    gScriptCmdWork.blink_phase = 0;
    gScriptCmdWork.timer = 8;
    gScriptCmdWork.timer_reload = 8;
    gFieldWork.cmd_busy = 1;
}

void map_script_cmd_actor_anim(void) {
    read_map_script_bytes(3);
    gScriptCmdWork.sprite_slot = script_object_slot(gFieldWork.cmd_args[0]) + 79;
    set_sprite_animation_state(gScriptCmdWork.sprite_slot, gFieldWork.cmd_args[1] & 0xF);
    gScriptCmdWork.counter = 0;
    gScriptCmdWork.timer = gFieldWork.cmd_args[2];
    gFieldWork.cmd_busy = 1;
}

void map_script_cmd_actor_hop(void) {
    gFieldWork.cmd_args[0] = read_map_script_byte();
    gScriptCmdWork.sprite_slot = script_object_slot(gFieldWork.cmd_args[0]) + 79;
    gScriptCmdWork.hop_base_y = gSpriteEntries[gScriptCmdWork.sprite_slot].pos_y;
    gSpriteEntries[gScriptCmdWork.sprite_slot].unk28 = 0;
    field_play_sound_effect(0x70);
    gFieldWork.cmd_busy = 1;
}

void map_script_cmd_all_actors_walk(void) {
    gFieldWork.cmd_args[0] = read_map_script_byte();
    gFieldWork.cmd_busy = 1;
}

void map_script_cmd_all_actors_walk_fast(void) {
    gFieldWork.cmd_args[0] = read_map_script_byte();
    gFieldWork.cmd_busy = 1;
}

void map_script_cmd_actor_spawn_glide(void) {
    u8 id;
    read_map_script_bytes(5);
    id = gFieldWork.cmd_args[0];
    script_object_set_slot(id, find_free_script_sprite_slot());
    gScriptCmdWork.sprite_slot = script_object_slot(gFieldWork.cmd_args[0]) + 79;
    gFieldWork.cmd_busy = 1;
}

void map_script_cmd_set_locket_block(void) {
    if ((gFieldWork.cmd_args[0] = read_map_script_byte()) == 1)
        gFieldWork.useBlockFlags = (gFieldWork.useBlockFlags & ~0x10) | 0x10;
    else
        gFieldWork.useBlockFlags &= ~0x10;
}

void map_script_cmd_actor_glide(void) {
    read_map_script_bytes(2);
    gScriptCmdWork.sprite_slot = script_object_slot(gFieldWork.cmd_args[0]) + 79;
    gFieldWork.cmd_busy = 1;
}

// guess: opcode 0x2E, skip ahead by arg2 if every owned copy of Medapart (arg0, arg1) is in use (owned count, high
// byte of field_medapart_counts, minus the low byte).
void map_script_cmd_jump_if_no_spare_medapart(void) {
    u16 r;
    s16 d;
    gFieldWork.branch_base = gFieldWork.script_pos;
    read_map_script_bytes(3);
    r = field_medapart_counts(gFieldWork.cmd_args[0], gFieldWork.cmd_args[1]);
    d = ((r & 0xFF00) >> 8) - (r & 0xFF);
    if (d == 0)
        gFieldWork.script_pos = gFieldWork.branch_base + gFieldWork.cmd_args[2];
}

// Opcode 0x2F: jump table; the event counter of the running script picks one of the byte offsets after it.
void map_script_cmd_switch_event_counter(void) {
    u16 start = gFieldWork.script_pos;
    gFieldWork.script_pos += event_counter_get(gFieldWork.script_id);
    gFieldWork.script_pos = start + read_map_script_byte();
}

// Opcode 0x30: relative jump (read offset += 16-bit big-endian argument, from the opcode's offset).
void map_script_cmd_jump(void) {
    u16 start = gFieldWork.script_pos;
    read_map_script_bytes(2);
    gFieldWork.script_pos = start + ((gFieldWork.cmd_args[0] << 8) | gFieldWork.cmd_args[1]);
}

void map_script_cmd_yes_no(void) {
    gFieldWork.branch_base = gFieldWork.script_pos;
    gFieldWork.cmd_args[0] = read_map_script_byte();
    gFieldWork.unkCB5 = 0;
    gFieldWork.cmd_busy = 1;
}

void map_script_cmd_yes_no_keep_window(void) {
    gFieldWork.branch_base = gFieldWork.script_pos;
    gFieldWork.cmd_args[0] = read_map_script_byte();
    gFieldWork.unkCB5 = 1;
    gFieldWork.cmd_busy = 1;
}

void map_script_cmd_robattle(void) {
    gFieldWork.battle_id = read_map_script_byte();
    gFieldWork.story_battle = read_map_script_byte();
    gFieldWork.battle_flags = read_map_script_byte();
    if (map_script_always_zero() == 0)
        gFieldWork.cmd_busy = 1;
}

void map_script_cmd_object_set_anim(void) {
    struct MapObject *obj;
    read_map_script_bytes(3);
    obj = map_object_find_by_id((gFieldWork.cmd_args[0] << 8) | gFieldWork.cmd_args[1]);
    if (obj != NULL && obj->unk4_6)
        set_sprite_anim_and_store(obj->unk4_0 + 49, gFieldWork.cmd_args[2], obj);
}

void map_script_cmd_all_actors_set_facing(void) {
    s32 i;
    gFieldWork.cmd_args[0] = read_map_script_byte();
    for (i = 0; i <= 3; i++) {
        if (script_object_slot(i) != -1 && gEntityStates[script_object_slot(i) + 79].active != 0)
            set_sprite_animation_state(script_object_slot(i) + 79, gFieldWork.cmd_args[0]);
    }
}

void map_script_cmd_give_item(void) {
    read_map_script_bytes(2);
    if (gFieldWork.cmd_args[1] == 0)
        gFieldWork.cmd_args[1] = 1;
    gFieldWork.cmd_busy = 1;
}

void map_script_cmd_take_item(void) {
    read_map_script_bytes(2);
    if (gFieldWork.cmd_args[1] == 0)
        gFieldWork.cmd_args[1] = 1;
    gFieldWork.cmd_busy = 1;
}

void map_script_cmd_give_medapart(void) {
    read_map_script_bytes(3);
    gFieldWork.cmd_busy = 1;
}

void map_script_cmd_take_medapart(void) {
    read_map_script_bytes(3);
    gFieldWork.cmd_busy = 1;
}

void map_script_cmd_give_money(void) {
    read_map_script_bytes(2);
    gFieldWork.cmd_busy = 1;
}

void map_script_cmd_take_money(void) {
    read_map_script_bytes(2);
    gFieldWork.cmd_busy = 1;
}

void map_script_cmd_give_medal(void) {
    gFieldWork.cmd_args[0] = read_map_script_byte();
    gFieldWork.cmd_busy = 1;
}

void map_script_cmd_give_tinpet(void) {
    gFieldWork.cmd_args[0] = read_map_script_byte();
    gFieldWork.cmd_busy = 1;
}

// Opcodes 0x3E / 0x3F: raise / lower affinity_ar (arg0 0) or affinity_ka by arg1, kept in 0..32. The raise
// caps affinity_ka in both branches (original bug).
void map_script_cmd_raise_affinity(void) {
    read_map_script_bytes(2);
    if (gFieldWork.cmd_args[0] == 0) {
        gFieldWork.affinity_ar += gFieldWork.cmd_args[1];
        if (gFieldWork.affinity_ka > 32)
            gFieldWork.affinity_ka = 32;
    } else {
        gFieldWork.affinity_ka += gFieldWork.cmd_args[1];
        if (gFieldWork.affinity_ka > 32)
            gFieldWork.affinity_ka = 32;
    }
}

void map_script_cmd_lower_affinity(void) {
    read_map_script_bytes(2);
    if (gFieldWork.cmd_args[0] == 0) {
        gFieldWork.affinity_ar -= gFieldWork.cmd_args[1];
        if (gFieldWork.affinity_ar < 0)
            gFieldWork.affinity_ar = 0;
    } else {
        gFieldWork.affinity_ka -= gFieldWork.cmd_args[1];
        if (gFieldWork.affinity_ka < 0)
            gFieldWork.affinity_ka = 0;
    }
}

void map_script_cmd_flash_white(void) {
    gFieldWork.cmd_args[0] = read_map_script_byte();
    gFieldWork.cmd_busy = 1;
}

void map_script_cmd_all_actors_blink(void) {
    s32 i;
    gFieldWork.cmd_args[0] = read_map_script_byte();
    for (i = 0; i <= 3; i++) {
        if (script_object_slot(i) != -1 && gEntityStates[script_object_slot(i) + 79].active != 0) {
            gSpriteEntries[script_object_slot(i) + 79].unk26 = gFieldWork.cmd_args[0];
            gSpriteEntries[script_object_slot(i) + 79].unk27 = 0;
            gSpriteEntries[script_object_slot(i) + 79].unk28 = 8;
            gSpriteEntries[script_object_slot(i) + 79].unk29 = 8;
        }
    }
    gFieldWork.cmd_busy = 1;
}

void map_script_cmd_player_slide(void) {}

void map_script_cmd_shake_screen(void) {
    read_map_script_bytes(2);
    gFieldWork.cmd_busy = 1;
}

void map_script_cmd_play_sound(void) {
    field_play_sound_effect(read_map_script_byte());
}

void map_script_cmd_play_song(void) {
    gFieldWork.cmd_args[0] = read_map_script_byte();
    field_update_music(1, gFieldWork.cmd_args[0]);
}

void map_script_cmd_stop_song(void) {
    field_update_music(2, 0);
}

void map_script_cmd_fade_out_songs(void) {
    field_stop_songs(0x78);
}

void map_script_cmd_play_event_song(void) {
    gFieldWork.cmd_args[0] = read_map_script_byte();
    field_update_music(3, gFieldWork.cmd_args[0]);
}

void map_script_cmd_restore_area_song(void) {
    field_update_music(4, 0);
}

void map_script_cmd_jump_unless_player_facing(void) {
    gFieldWork.branch_base = gFieldWork.script_pos;
    read_map_script_bytes(2);
    if (gFieldWork.cmd_args[0] != gSpriteEntries[47].unk21)
        gFieldWork.script_pos = gFieldWork.branch_base + gFieldWork.cmd_args[1];
}

// Opcode 0x4B: skip ahead by arg2 unless the player has at least arg1 of item arg0
void map_script_cmd_jump_unless_has_items(void) {
    s32 n;
    gFieldWork.branch_base = gFieldWork.script_pos;
    read_map_script_bytes(3);
    n = field_item_quantity(gFieldWork.cmd_args[0]);
    if (n == 0 || n < gFieldWork.cmd_args[1])
        gFieldWork.script_pos = gFieldWork.branch_base + gFieldWork.cmd_args[2];
}

void map_script_cmd_jump_unless_part_equipped(void) {
    u32 r;
    gFieldWork.branch_base = gFieldWork.script_pos;
    read_map_script_bytes(3);
    r = team_equipped_part_legs_value(gFieldWork.cmd_args[0], gFieldWork.cmd_args[1]);
    if (r != -1)
        gFieldWork.unkC60 = r;
    else
        gFieldWork.script_pos = gFieldWork.branch_base + gFieldWork.cmd_args[2];
}

// Opcode 0x4D: skip ahead by arg1 unless medal arg0 is owned (find_medal_slot_by_id)
void map_script_cmd_jump_unless_has_medal(void) {
    gFieldWork.branch_base = gFieldWork.script_pos;
    read_map_script_bytes(2);
    if (field_find_medal_slot(gFieldWork.cmd_args[0]) == 0)
        gFieldWork.script_pos = gFieldWork.branch_base + gFieldWork.cmd_args[1];
}

// Opcode 0x4E: skip ahead by arg2 if money (gMoney) < 16-bit arg * 10
void map_script_cmd_jump_if_money_below(void) {
    gFieldWork.branch_base = gFieldWork.script_pos;
    read_map_script_bytes(3);
    if ((s32)get_money() < ((gFieldWork.cmd_args[0] << 8) | gFieldWork.cmd_args[1]) * 10)
        gFieldWork.script_pos = gFieldWork.branch_base + gFieldWork.cmd_args[2];
}

void map_script_cmd_jump_if_lost(void) {
    gFieldWork.branch_base = gFieldWork.script_pos;
    read_map_script_bytes(1);
    if (gFieldState.sceneResult == 2)
        gFieldWork.script_pos = gFieldWork.branch_base + gFieldWork.cmd_args[0];
}

void map_script_cmd_jump_if_affinity_below(void) {
    struct FieldWork *s = &gFieldWork;
    s->branch_base = s->script_pos;
    read_map_script_bytes(3);
    if (s->cmd_args[0] == 0) {
        if (s->affinity_ar >= s->cmd_args[1])
            return;
    } else if (s->affinity_ka >= s->cmd_args[1])
        return;
    gFieldWork.script_pos = gFieldWork.branch_base + gFieldWork.cmd_args[2];
}

void map_script_cmd_jump_unless_part_value(void) {
    gFieldWork.branch_base = gFieldWork.script_pos;
    read_map_script_bytes(2);
    if (gFieldWork.cmd_args[0] - 70 != gFieldWork.unkC60)
        gFieldWork.script_pos = gFieldWork.branch_base + gFieldWork.cmd_args[1];
}

void map_script_cmd_jump_random(void) {
    gFieldWork.branch_base = gFieldWork.script_pos;
    read_map_script_bytes(2);
    if (field_random(0xFF) & 0xF)
        gFieldWork.script_pos = gFieldWork.branch_base + gFieldWork.cmd_args[2];
}

void map_script_cmd_set_area_sprite_sheet(void) {
    read_map_script_bytes(2);
    if (gFieldWork.cmd_args[0] != 0)
        gFieldWork.cmd_args[0]--;
    gFieldWork.sheet_variants[gFieldWork.cmd_args[0]] = gFieldWork.cmd_args[1];
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

// Not called directly (hidden in the tail of map_script_cmd_set_area_sprite_sheet).
void map_script_cmd_unused_54(void) {}

// Not called directly (hidden in the tail of map_script_cmd_set_area_sprite_sheet).
void map_script_cmd_unused_55(void) {}

// Not called directly (hidden in the tail of map_script_cmd_set_area_sprite_sheet).
void map_script_cmd_reload_map(void) {
    gFieldWork.cmd_busy = 1;
}

// Not called directly (hidden in the tail of map_script_cmd_set_area_sprite_sheet).
void map_script_cmd_unused_57(void) {}

// Not called directly (hidden in the tail of map_script_cmd_set_area_sprite_sheet).
void map_script_cmd_unused_58(void) {}

void map_script_cmd_open_shop(void) {
    read_map_script_bytes(1);
    gFieldWork.cmd_busy = 1;
}

void map_script_cmd_set_follower_facing(void) {
    gFieldWork.cmd_args[0] = read_map_script_byte();
    gSpriteEntries[48].unk21 = gFieldWork.cmd_args[0];
    gSpriteEntries[48].unk20 = gFieldWork.cmd_args[0];
    sprite_anim_start(48, sprite_walk_anim_id(48, gFieldWork.cmd_args[0] + gSpriteEntries[48].unk2B * 4));
    follower_set_facing(gFieldWork.cmd_args[0]);
}

void map_script_cmd_jump_if_team_under_3(void) {
    gFieldWork.branch_base = gFieldWork.script_pos;
    read_map_script_bytes(1);
    if (team_count_complete_bots() <= 2)
        gFieldWork.script_pos = gFieldWork.branch_base + gFieldWork.cmd_args[1];
}

// Opcode 0x5C: skip ahead by arg1 unless an assembled Medabot (0x030017A0) is all model arg0
void map_script_cmd_jump_unless_full_part_set(void) {
    gFieldWork.branch_base = gFieldWork.script_pos;
    read_map_script_bytes(2);
    if (team_has_full_part_set(gFieldWork.cmd_args[0]) == 0)
        gFieldWork.script_pos = gFieldWork.branch_base + gFieldWork.cmd_args[1];
}

// Opcode 0x5D. Bit 7 set: arg 1 sets / else clears useBlockFlags bit 5; else medawatch_enabled (Medawatch
// menu flag) = arg & 0xF. Runtime: sets 0x03006413 to 1 when Dad gives Ikki the Medawatch.
void map_script_cmd_set_medawatch_flag(void) {
    read_map_script_bytes(1);
    if (gFieldWork.cmd_args[0] & 0x80) {
        if ((gFieldWork.cmd_args[0] & 0xF) == 1)
            gFieldWork.useBlockFlags = (gFieldWork.useBlockFlags & ~0x20) | 0x20;
        else
            gFieldWork.useBlockFlags &= ~0x20;
    } else {
        gFieldWork.medawatch_enabled = gFieldWork.cmd_args[0] & 0xF;
    }
}

void map_script_cmd_set_disguise_block(void) {
    if ((gFieldWork.cmd_args[0] = read_map_script_byte()) == 1)
        gFieldWork.useBlockFlags = (gFieldWork.useBlockFlags & ~0x01) | 0x01;
    else
        gFieldWork.useBlockFlags &= ~0x01;
}

void map_script_cmd_set_encounters_off(void) {
    gFieldWork.encounters_off = read_map_script_byte();
}

void map_script_cmd_follower_attach(void) {
    u16 id;
    struct MapObject *obj;
    read_map_script_bytes(3);
    switch (gFieldWork.cmd_args[0]) {
    case 0:
        if (script_object_slot(gFieldWork.cmd_args[2]) != -1)
            follower_attach(script_object_slot(gFieldWork.cmd_args[2]) + 79);
        break;
    case 1:
        id = (gFieldWork.cmd_args[1] << 8) | gFieldWork.cmd_args[2];
        if (id != 0) {
            obj = map_object_find_by_id(id);
            if (obj != NULL)
                follower_attach(obj->unk4_0 + 49);
        } else {
            follower_attach(gFieldWork.objects[gFieldWork.script_object].unk4_0 + 49);
        }
        break;
    }
}

void map_script_cmd_follower_detach(void) {
    follower_detach();
}

void map_script_cmd_give_starter_medabot(void) {
    give_starter_medabot();
}

void map_script_cmd_start_field_effect(void) {
    read_map_script_bytes(3);
    field_effect_start(gFieldWork.cmd_args[0], (gFieldWork.cmd_args[1] & 0x7F) * 16 + gFieldWork.map_origin_x,
                       (gFieldWork.cmd_args[2] & 0x7F) * 16 + gFieldWork.map_origin_y, 0);
    gFieldWork.cmd_busy = 1;
}

void map_script_cmd_clear_sprites(void) {
    init_battle_sprites();
}

void map_script_cmd_unused_65(void) {}

void map_script_cmd_actor_jump(void) {
    read_map_script_bytes(2);
    gScriptCmdWork.sprite_slot = script_object_slot(gFieldWork.cmd_args[0]) + 79;
    gSpriteEntries[gScriptCmdWork.sprite_slot].unk26 = 0;
    gFieldWork.cmd_busy = 1;
}

void map_script_cmd_skip_2(void) {
    read_map_script_bytes(2);
    gFieldWork.cmd_busy = 1;
}

void map_script_cmd_clear_self_tile(void) {
    struct MapObject *obj;
    read_map_script_bytes(2);
    obj = &gFieldWork.objects[gFieldWork.script_object];
    if ((obj->unk2 & 0xFFF) == ((gFieldWork.cmd_args[0] << 8) | gFieldWork.cmd_args[1]))
        set_tile_data(obj->x, obj->y, 0);
}

void map_script_cmd_toggle_player_visible(void) {
    read_map_script_bytes(2);
    if (gFieldWork.cmd_args[0] == gFieldWork.player_visible) {
        gFieldWork.player_visible = gFieldWork.cmd_args[0] ^ 1;
        field_set_player_sprite_visible(gFieldWork.player_visible);
        if (gFieldWork.cmd_args[1] == 0) {
            if (gFieldWork.player_visible) {
                memcpy_u8(gFieldWork.saved_tile_actions, gFieldWork.tile_actions, 8);
            } else {
                memcpy_u8(gFieldWork.tile_actions, gFieldWork.saved_tile_actions, 8);
                gFieldWork.tile_actions[0] = 0;
                gFieldWork.tile_actions[1] = 0;
                gFieldWork.tile_actions[2] = 0;
                gFieldWork.tile_actions[3] = 0;
                gFieldWork.tile_actions[4] = 0;
                gFieldWork.tile_actions[5] = 0;
                gFieldWork.tile_actions[6] = 0;
                gFieldWork.tile_actions[7] = 0;
            }
        }
    }
}

void map_script_cmd_unused_6a(void) {}

void map_script_cmd_set_story_phase(void) {
    gFieldWork.story_phase = read_map_script_byte();
}

void map_script_cmd_actor_spawn_walk_fast(void) {
    read_map_script_bytes(5);
    script_object_set_slot(gFieldWork.cmd_args[0], find_free_script_sprite_slot());
    gScriptCmdWork.sprite_slot = script_object_slot(gFieldWork.cmd_args[0]) + 79;
    gFieldWork.cmd_busy = 1;
}

void map_script_cmd_actor_walk_fast(void) {
    read_map_script_bytes(2);
    gScriptCmdWork.sprite_slot = script_object_slot(gFieldWork.cmd_args[0]) + 79;
    gFieldWork.cmd_busy = 1;
}

void map_script_cmd_actor_spawn_glide_fast(void) {
    read_map_script_bytes(5);
    script_object_set_slot(gFieldWork.cmd_args[0], find_free_script_sprite_slot());
    gScriptCmdWork.sprite_slot = script_object_slot(gFieldWork.cmd_args[0]) + 79;
    gFieldWork.cmd_busy = 1;
}

void map_script_cmd_actor_glide_fast(void) {
    read_map_script_bytes(2);
    gScriptCmdWork.sprite_slot = script_object_slot(gFieldWork.cmd_args[0]) + 79;
    gFieldWork.cmd_busy = 1;
}

// Not called directly (hidden in the tail of map_script_cmd_actor_glide_fast).
void map_script_cmd_medabots_weekly(void) {
    gFieldWork.cmd_busy = 1;
}

// Not called directly (hidden in the tail of map_script_cmd_actor_glide_fast).
void map_script_cmd_enter_player_name(void) {
    gFieldWork.cmd_busy = 1;
}

// Not called directly (hidden in the tail of map_script_cmd_actor_glide_fast).
void map_script_cmd_rename_medal(void) {
    gFieldWork.cmd_busy = 1;
}

// Not called directly (hidden in the tail of map_script_cmd_actor_glide_fast).
void map_script_cmd_text_scroll(void) {
    gFieldWork.cmd_busy = 1;
}

// Not called directly (hidden in the tail of map_script_cmd_actor_glide_fast).
void map_script_cmd_unused_74(void) {}

// Not called directly (hidden in the tail of map_script_cmd_actor_glide_fast).
void map_script_cmd_unused_75(void) {}

// Not called directly (hidden in the tail of map_script_cmd_actor_glide_fast).
// guess: opcode 0x76, the link cable screen (switch_game_mode 4), then the link menu if it asked for it.
void map_script_cmd_link_start(void) {
    gFieldWork.cmd_busy = 1;
}

// Not called directly (hidden in the tail of map_script_cmd_actor_glide_fast).
void map_script_cmd_unused_77(void) {}

void map_script_cmd_race(void) {
    gFieldWork.branch_base = gFieldWork.script_pos;
    read_map_script_bytes(2);
    gFieldSceneParams.race_id = gFieldWork.cmd_args[0];
    if (team_count_complete_bots() > 2)
        gFieldWork.cmd_busy = 1;
    else
        gFieldWork.script_pos = gFieldWork.branch_base + gFieldWork.cmd_args[1];
}

void map_script_cmd_event_picture(void) {
    gFieldSceneParams.event_picture_id = read_map_script_byte();
    gFieldWork.cmd_busy = 1;
}

// Not called directly (hidden in the tail of map_script_cmd_event_picture).
void map_script_cmd_bomb_game(void) {
    gFieldWork.cmd_busy = 1;
}

void map_script_cmd_jump_unless_has_medapart(void) {
    gFieldWork.branch_base = gFieldWork.script_pos;
    read_map_script_bytes(3);
    if ((u8)((u16)field_medapart_counts(gFieldWork.cmd_args[0], gFieldWork.cmd_args[1]) >> 8) == 0)
        gFieldWork.script_pos = gFieldWork.branch_base + gFieldWork.cmd_args[2];
}

void map_script_cmd_unused_7c(void) {}

// guess: opcode 0x7D, which Town Map variant to draw (unkC32, read by town_map.c).
void map_script_cmd_set_town_map_phase(void) {
    gFieldWork.unkC32 = read_map_script_byte();
}

void map_script_cmd_all_actors_slide(void) {
    gFieldWork.cmd_args[0] = read_map_script_byte();
    gFieldWork.cmd_busy = 1;
}

void map_script_cmd_follower_to_actor(void) {
    gFieldWork.cmd_args[0] = read_map_script_byte();
    gFieldWork.cmd_busy = 1;
}

// Opcodes 0x80-0x82: queue 8-byte move lists for several actors, then run them together.
void map_script_cmd_move_queue_begin(void) {
    gFieldScriptWork.queue_len = 0;
    memzero_bytes(gFieldScriptWork.queue_timer, 8);
    memzero_bytes(gFieldScriptWork.queue_pos, 8);
    memzero_bytes(gFieldScriptWork.queue[0], 64);
    memzero_bytes(&gFieldScriptWork.queue_len, 1);
    memzero_bytes(&gFieldScriptWork.unk53, 1);
    memzero_bytes(gFieldScriptWork.queue_sprite, 8);
    gFieldWork.cmd = read_map_script_byte();
    gFieldWork.cmd_busy = 0;
    gFieldWork.cmd_step = 0;
    gMapScriptCommands[gFieldWork.cmd]();
}

void map_script_cmd_move_queue_add(void) {
    read_map_script_bytes(8);
    memcpy_u8(gFieldWork.cmd_args, gFieldScriptWork.queue[gFieldScriptWork.queue_len++], 8);
    gFieldWork.cmd = read_map_script_byte();
    gFieldWork.cmd_busy = 0;
    gFieldWork.cmd_step = 0;
    gMapScriptCommands[gFieldWork.cmd]();
}

// Not called directly (hidden in the tail of map_script_cmd_move_queue_add).
void map_script_cmd_move_queue_run(void) {
    gFieldWork.cmd_busy = 1;
}

void map_script_cmd_set_sprite_blend_priority(void) {
    u8 slot;

    read_map_script_bytes(2);
    if (gFieldWork.cmd_args[0] & 0x10) {
        if (gFieldWork.cmd_args[0] & 0x40) {
            if (gFieldWork.cmd_args[1] == 0)
                sprite_set_blend_from_kind(47);
            else
                sprite_set_blend(47, gFieldWork.cmd_args[1]);
        } else if (gFieldWork.cmd_args[0] & 0x20) {
            if ((gFieldWork.objects[gFieldWork.script_object].unk2 & 0xFFF) == gFieldWork.script_id) {
                slot = gFieldWork.objects[gFieldWork.script_object].unk4_0 + 49;
                if (gFieldWork.cmd_args[1] == 0)
                    sprite_set_blend_from_kind(slot);
                else
                    sprite_set_blend(slot, gFieldWork.cmd_args[1]);
            }
        } else {
            if (gFieldWork.cmd_args[1] == 0)
                sprite_set_blend_from_kind(script_object_slot(gFieldWork.cmd_args[0] & 0xF) + 79);
            else
                script_object_set_blend(gFieldWork.cmd_args[0] & 0xF, gFieldWork.cmd_args[1]);
        }
    } else {
        if (gFieldWork.cmd_args[0] & 0x40) {
            sprite_set_priority(47, gFieldWork.cmd_args[1]);
        } else if (gFieldWork.cmd_args[0] & 0x20) {
            if ((gFieldWork.objects[gFieldWork.script_object].unk2 & 0xFFF) == gFieldWork.script_id) {
                slot = gFieldWork.objects[gFieldWork.script_object].unk4_0 + 49;
                sprite_set_priority(slot, gFieldWork.cmd_args[1]);
            }
        } else {
            script_object_set_priority(gFieldWork.cmd_args[0] & 0xF, gFieldWork.cmd_args[1]);
        }
    }
}

void map_script_cmd_set_bg_tile_anim(void) {
    read_map_script_bytes(1);
    gFieldWork.cmd_busy = 1;
}

// Opcodes 0x85-0x87: queue map object 4-frame open (1) / close (2) animations (guess: doors), then run them.
void map_script_cmd_anim_queue_begin(void) {
    struct FieldScriptWork *v = &gFieldScriptWork;
    v->queue_len = 0;
    memzero_bytes(v->queue_timer, 8);
    memzero_bytes(v->queue_pos, 8);
    memzero_bytes(v->queue[0], 64);
}

void map_script_cmd_anim_queue_add(void) {
    read_map_script_bytes(8);
    memcpy_u8(gFieldWork.cmd_args, gFieldScriptWork.queue[gFieldScriptWork.queue_len++], 8);
}

// Not called directly (hidden in the tail of map_script_cmd_anim_queue_add).
void map_script_cmd_anim_queue_run(void) {
    gFieldWork.cmd_busy = 1;
}

void map_script_cmd_jump_unless_follower(void) {
    u16 start = gFieldWork.script_pos;
    read_map_script_bytes(2);
    if (gFieldWork.follower_active == 0)
        gFieldWork.script_pos = start + ((gFieldWork.cmd_args[0] << 8) | gFieldWork.cmd_args[1]);
}

u8 read_map_script_byte(void) {
    u8 *data = gMapScriptData;
    u32 offsets = (u16)((data[0] | (data[1] << 8)) - 0x4000);
    u16 banks = (data[2] | (data[3] << 8)) - 0x4000;
    u16 script = gFieldWork.script_id;
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
    pos = start + gFieldWork.script_pos;
    ret = data[pos + (bank << 14)];
    gFieldWork.script_pos++;
    return ret;
}

void read_map_script_bytes(u8 n) {
    s32 i;
    for (i = 0; i < n; i++)
        gFieldWork.cmd_args[i] = read_map_script_byte();
}

static s32 map_object_index_by_id(u16 id) {
    s32 i;
    for (i = 0; i < 64; i++)
        if ((gFieldWork.objects[i].unk2 & 0xFFF) == id)
            return i;
    if (i == 64)
        return -1;
}

struct MapObject *map_object_find_by_id(u16 id) {
    s32 i;
    for (i = 0; i < 64; i++)
        if ((gFieldWork.objects[i].unk2 & 0xFFF) == id)
            return &gFieldWork.objects[i];
    if (i == 64)
        return NULL;
}

static void map_object_remove(struct MapObject *obj) {
    u8 *raw = (u8 *)obj;
    const u8 *tiles = gAreaCollisionMaps[gFieldWork.area_id];
    set_tile_data(obj->x, obj->y, tiles[obj->y * (gFieldWork.map_width >> 1) + obj->x]);
    if (obj->unk4_6) {
        sprite_entry_clear(obj->unk4_0 + 49);
        sprite_entry_clear(obj->unk4_0 + 91);
    }
    memzero_bytes(raw, 8);
}

// Turns sprite i into the follower (sprite 48 + shadow 90) that walks behind the player; scripts
// block item use meanwhile.
static void follower_attach(u8 i) {
    sprite_entry_clear(48);
    sprite_entry_clear(90);
    memcpy_u8(&gSpriteEntries[i], &gSpriteEntries[48], 0x40);
    memcpy_u8(&gEntityStates[i], &gEntityStates[48], 4);
    gFieldWork.follower_active = 1;
    gFieldWork.follower_x = gSpriteEntries[48].x + gBg1Scroll.x;
    gFieldWork.follower_y = gSpriteEntries[48].y + gBg1Scroll.y;
    gFieldWork.follower_tile_x = field_pixel_x_to_tile(gFieldWork.follower_x);
    gFieldWork.follower_tile_y = field_pixel_y_to_tile(gFieldWork.follower_y);
    gFieldWork.follower_sprite_set = gSpriteEntries[48].unk2B;
    follower_clear_scroll_dir();
    sprite_anim_start(48, sprite_walk_anim_id(48, gSpriteEntries[48].unk2B * 4 + gSpriteEntries[48].unk21));
    sprite_entry_init(90,
                      SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(3) | SPRITE_OBJ_MODE(1) |
                          SPRITE_FLAG_PART_PALETTE,
                      0x90, 0xE, 1);
    gSpriteEntries[90].x = gSpriteEntries[48].x;
    gSpriteEntries[90].y = gSpriteEntries[48].y - 5;
    gSpriteEntries[90].pos_x = gSpriteEntries[48].pos_x;
    gSpriteEntries[90].pos_y = gSpriteEntries[48].pos_y - 5;
    follower_turn_toward_player(1);
    gFieldWork.savedUseBlockFlags = gFieldWork.useBlockFlags;
    gFieldWork.useBlockFlags = 0xDF;
}

static void follower_detach(void) {
    sprite_entry_clear(48);
    sprite_entry_clear(90);
    gFieldWork.follower_active = 0;
    gFieldWork.useBlockFlags = gFieldWork.savedUseBlockFlags;
}

void script_object_free_slot(u8 i) {
    gFieldWork.script_object_slots[i] = 0;
}

void script_object_set_slot(u8 i, u8 v) {
    gFieldWork.script_object_slots[i] = v + 1;
}

u32 script_object_slot(u8 i) {
    return gFieldWork.script_object_slots[i] - 1;
}
