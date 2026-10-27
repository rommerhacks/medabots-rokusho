// Map script command updates: map_script_update_command calls the gMapScriptUpdates (0x083D24B0) handler of
// the current opcode every frame until it calls map_script_command_done (messages, waits, fades, items,
// Medaparts, Medals, money, sprite walks, battles and scene changes). All 137 entries are in this file, in
// opcode order. Talks to field/map_script, field/script_sprites, field/field_walk, text/message and
// field/script_helpers.
#include "global.h"

static void map_script_load_warp_area(void);
static void map_script_actor_spawn_walk_step(void);
static void map_script_actor_walk_step(void);
static void map_script_all_actors_move_step(u8 speed, u8 mode);
static u32 map_script_player_slide_step(u8 a);

void map_script_update_command(void) {
    gMapScriptUpdates[gFieldWork.cmd]();
}

void map_script_update_none(void) {}

// Opcode 1 update: shows message (C94[1] << 8 | C94[2]) of text bank C94[0] (runtime: bank 2, id 1
// is the lab intro "Good afternoon!"), finishes once the text window closes.
void map_script_update_message(void) {
    struct FieldWork *s = &gFieldWork;
    const u32 *const *tbl;

    switch (s->cmd_step) {
    case 0:
        message_steps_reset();
        gFieldDebug.text_bank = s->cmd_args[0] - 2;
        gFieldDebug.text_id = (s->cmd_args[1] << 8) | s->cmd_args[2];
        if (map_script_always_zero())
            map_script_command_done();
        s->cmd_step++;
        break;
    case 1:
        if (s->cmd_args[0] < 2)
            tbl = (const u32 *const *)gTextTable;
        else
            tbl = gTextBankTables[s->cmd_args[0] - 2];
        if (message_step_run(0, 0, 0, tbl[(s->cmd_args[1] << 8) | s->cmd_args[2]]))
            map_script_command_done();
        break;
    }
}

void map_script_update_skip_message(void) {
    map_script_command_done();
}

void map_script_update_wait_window_close(void) {
    if (game_state_execute_handler_a())
        map_script_command_done();
}

void map_script_update_wait(void) {
    if (gFieldWork.cmd_args[0] != 0)
        gFieldWork.cmd_args[0]--;
    else
        map_script_command_done();
}

void map_script_update_wait_button(void) {
    if (KEY_BITS(gNewKeys).a | KEY_BITS(gNewKeys).start)
        map_script_command_done();
}

void map_script_update_fade_out_black(void) {
    if (run_blend_fade_transition(0))
        map_script_command_done();
}

void map_script_update_fade_in_black(void) {
    if (run_blend_fade_transition(0))
        map_script_command_done();
}

void map_script_update_fade_out_white(void) {
    if (run_blend_fade_transition(0x7FFF))
        map_script_command_done();
}

void map_script_update_fade_in_white(void) {
    if (run_blend_fade_transition(0x7FFF))
        map_script_command_done();
}

void map_script_update_warp(void) {
    map_script_load_warp_area();
}

void map_script_update_warp_hidden(void) {
    map_script_load_warp_area();
}

static void map_script_load_warp_area(void) {
    area_load_bg_palettes();
    area_load_sprite_palettes();
    load_room_graphics();
    area_load_encounter_rate();
    gFieldWork.bg_anim_frame = 0;
    gFieldWork.bg_anim_timer = 0;
    animate_area_bg_tiles();
    load_battle_terrain_data();
    gFieldWork.player_x = gFieldWork.player_tile_x * 16 + gFieldWork.map_origin_x;
    gFieldWork.player_y = gFieldWork.player_tile_y * 16 + gFieldWork.map_origin_y;
    init_battle_field_setup();
    update_bg_scroll_offsets_a();
    gSpriteEntries[47].unk25 = 1;
    field_set_player_facing(gFieldWork.player_facing);
    follower_snap_to_player();
    area_load_sprite_sheets();
    map_script_command_done();
}

void map_script_update_player_hop(void) {
    switch (gSpriteEntries[47].unk26) {
    case 0:
        if (gSpriteEntries[47].unk28 < 16) {
            gSpriteEntries[47].unk4 = gFieldWork.cmd_args[0] - gJumpArcTable[gSpriteEntries[47].unk28][0] / 16;
            gSpriteEntries[47].unk28++;
            if (gSpriteEntries[47].unk4 / 4 <= (gFieldWork.cmd_args[0] - 16) / 4)
                gSpriteEntries[47].unkB = 0xFF;
            else
                sprite_set_blend_from_kind(47);
        } else {
            gSpriteEntries[47].unk26 = 1;
            gSpriteEntries[47].unk28 = 0;
        }
        break;
    case 1:
        sprite_set_blend_from_kind(47);
        gSpriteEntries[47].unk4 = gFieldWork.cmd_args[0];
        map_script_command_done();
        break;
    }
}

void map_script_update_player_jump(void) {
    switch (gFieldWork.cmd_step) {
    case 0:
        memcpy_u8(gFieldWork.tile_actions, gFieldWork.saved_tile_actions, 8);
        gFieldWork.tile_actions[0] = 0;
        gFieldWork.tile_actions[3] = 0;
        gFieldWork.tile_actions[7] = 0;
        field_set_player_facing(gFieldWork.cmd_args[0]);
        memcpy_u8(&gSpriteEntries[47], &gSpriteEntries[46], 0x40);
        gFieldWork.player_visible = 0;
        field_set_player_sprite_visible(0);
        gSpriteEntries[89].unk0 = 0xCC0C;
        gSpriteEntries[48].unk0 = 0;
        gSpriteEntries[47].unk28 = 0;
        gFieldWork.script_field_update = 1;
        clear_input_keys();
        field_play_sound_effect(0x70);
        gFieldWork.cmd_step++;
        break;
    case 1:
        clear_input_keys();
        switch (gFieldWork.cmd_args[0]) {
        case 0:
            KEYS_LO(gHeldKeys) |= 0x40;
            break;
        case 1:
            KEYS_LO(gHeldKeys) |= 0x80;
            break;
        case 2:
            KEYS_LO(gHeldKeys) |= 0x20;
            break;
        case 3:
            KEYS_LO(gHeldKeys) |= 0x10;
            break;
        }
        gSpriteEntries[46].unk2 = gSpriteEntries[47].unk2;
        if (gSpriteEntries[47].unk28 < 16 / sprite_walk_speed(47) * 2) {
            gSpriteEntries[46].unk4 = gSpriteEntries[47].unk4 -
                                      gJumpArcTable[0][gSpriteEntries[47].unk28 * (sprite_walk_speed(47) << 2)] / 16;
            gSpriteEntries[47].unk28++;
            if (gSpriteEntries[46].unk4 / 4 <= (gSpriteEntries[47].unk4 - 16) / 4)
                gSpriteEntries[46].unkB = 0xFF;
            else
                sprite_set_blend_from_kind(46);
        } else {
            gSpriteEntries[47].unk26++;
            gSpriteEntries[47].unk28 = 0;
            memcpy_u8(gFieldWork.saved_tile_actions, gFieldWork.tile_actions, 8);
            sprite_entry_clear(46);
            gFieldWork.player_visible = 1;
            field_set_player_sprite_visible(1);
            gFieldWork.script_field_update = 0;
            map_script_command_done();
        }
        break;
    }
}

void map_script_update_player_walk(void) {
    switch (gFieldWork.cmd_step) {
    case 0:
        clear_input_keys();
        if (gFieldWork.cmd_args[gSpriteEntries[47].unk26] == 0xFF) {
            gFieldWork.cmd_step++;
            break;
        }
        if (gSpriteEntries[47].unk28 == 0)
            break;
        switch ((gFieldWork.cmd_args[gSpriteEntries[47].unk26] & 0xF0) >> 4) {
        case 0:
            KEYS_LO(gHeldKeys) |= 0x40;
            break;
        case 1:
            KEYS_LO(gHeldKeys) |= 0x80;
            break;
        case 2:
            KEYS_LO(gHeldKeys) |= 0x20;
            break;
        case 3:
            KEYS_LO(gHeldKeys) |= 0x10;
            break;
        }
        gSpriteEntries[47].unk28--;
        if (gSpriteEntries[47].unk28 != 0)
            break;
        gSpriteEntries[47].unk28 = 16 / sprite_walk_speed(47);
        gSpriteEntries[47].unk27--;
        if (gSpriteEntries[47].unk27 != 0)
            break;
        gFieldWork.player_tile_x = field_pixel_x_to_tile(gFieldWork.player_x);
        gFieldWork.player_tile_y = field_pixel_y_to_tile(gFieldWork.player_y);
        if (gFieldWork.follower_active != 0) {
            gFieldWork.follower_tile_x = field_pixel_x_to_tile(gFieldWork.follower_x);
            gFieldWork.follower_tile_y = field_pixel_y_to_tile(gFieldWork.follower_y);
        }
        gSpriteEntries[47].unk26++;
        if (gSpriteEntries[47].unk26 > 3) {
            gFieldWork.cmd_step++;
            break;
        }
        if (gFieldWork.cmd_args[gSpriteEntries[47].unk26] == 0xFF) {
            gFieldWork.cmd_step++;
            break;
        }
        script_sprite_begin_walk(47, gFieldWork.cmd_args[gSpriteEntries[47].unk26], gSpriteEntries[47].unk2A);
        switch (gFieldWork.cmd_args[gSpriteEntries[47].unk26] >> 4) {
        case 0:
            KEYS_LO(gHeldKeys) |= 0x40;
            break;
        case 1:
            KEYS_LO(gHeldKeys) |= 0x80;
            break;
        case 2:
            KEYS_LO(gHeldKeys) |= 0x20;
            break;
        case 3:
            KEYS_LO(gHeldKeys) |= 0x10;
            break;
        }
        break;
    case 1:
        memcpy_u8(gFieldWork.script_tile_actions, gFieldWork.tile_actions, 8);
        gFieldWork.script_field_update = 0;
        map_script_command_done();
        break;
    }
}

void map_script_update_set_player_form(void) {
    u8 obj;
    u32 i;

    gFieldWork.saved_player_form = gFieldWork.player_form = gUnk_083D2998[gFieldWork.cmd_args[0]];
    gFieldWork.loaded_form = gUnk_083D2998[gFieldWork.cmd_args[0]];
    load_battle_terrain_data();
    area_load_sprite_sheets();
    switch (gBlendEffect.type) {
    case 1:
    case 3:
    case 5:
    case 6:
        obj = 1;
        break;
    default:
        obj = 0;
        break;
    }
    i = area_sprite_sheet_id(0);
    if (gUnk_083F8634[i] == NULL)
        i = 1;
    if (obj)
        DmaCopy32(3, gUnk_083F8634[i], OBJ_PLTT, 32) else DmaCopy32(3, gUnk_083F8634[i], 0x0202F800, 32)
            map_script_command_done();
}

void map_script_update_self_anim(void) {
    if (script_sprite_anim_step())
        map_script_command_done();
}

void map_script_update_self_hop(void) {
    if (script_sprite_hop_step())
        map_script_command_done();
}

void map_script_update_self_blink(void) {
    if (script_sprite_blink_step(gUnk_03006D20.unkA))
        map_script_command_done();
}

void map_script_update_actor_spawn_walk(void) {
    map_script_actor_spawn_walk_step();
}

void map_script_update_actor_spawn_walk_2(void) {
    map_script_actor_spawn_walk_step();
}

static void map_script_actor_spawn_walk_step(void) {
    struct FieldWork *s = &gFieldWork;

    switch (s->cmd_step) {
    case 0:
        spawn_script_sprite(s->cmd_args[0], s->cmd_args[1], s->cmd_args[2], s->cmd_args[3]);
        script_sprite_begin_walk(gUnk_03006D20.unkA, s->cmd_args[4], 0);
        s->cmd_step++;
        break;
    case 1:
        if (script_sprite_update_walk(gUnk_03006D20.unkA, 1))
            map_script_command_done();
        break;
    }
}

void map_script_update_actor_walk(void) {
    map_script_actor_walk_step();
}

void map_script_update_actor_walk_2(void) {
    map_script_actor_walk_step();
}

static void map_script_actor_walk_step(void) {
    struct FieldWork *s = &gFieldWork;

    switch (s->cmd_step) {
    case 0:
        script_sprite_begin_walk(gUnk_03006D20.unkA, s->cmd_args[1], 0);
        s->cmd_step++;
        break;
    case 1:
        if (script_sprite_update_walk(gUnk_03006D20.unkA, 1))
            map_script_command_done();
        break;
    }
}

void map_script_update_actor_blink(void) {
    if (script_sprite_blink_step(gUnk_03006D20.unkA))
        map_script_command_done();
}

void map_script_update_actor_anim(void) {
    if (script_sprite_anim_step())
        map_script_command_done();
}

void map_script_update_actor_hop(void) {
    if (script_sprite_hop_step())
        map_script_command_done();
}

void map_script_update_all_actors_walk(void) {
    map_script_all_actors_move_step(0, 1);
}

void map_script_update_all_actors_walk_fast(void) {
    map_script_all_actors_move_step(1, 1);
}

// Moves every spawned actor in direction arg0: mode 1 walks (animated), mode 0 slides (speed 1 = double).
static void map_script_all_actors_move_step(u8 speed, u8 mode) {
    s32 empty = 0;
    s32 done = 0;
    s32 i;
    s32 slot;

    switch (gFieldWork.cmd_step) {
    case 0:
        for (i = 0; i <= 3; i++) {
            if (script_object_slot(i) != -1 && gUnk_030055A0[script_object_slot(i) + 79].unk0 != 0) {
                if (mode == 1)
                    script_sprite_begin_walk(script_object_slot(i) + 79, gFieldWork.cmd_args[0], speed);
                else
                    script_sprite_begin_slide(script_object_slot(i) + 79, gFieldWork.cmd_args[0], speed);
            }
        }
        gFieldWork.cmd_step++;
        break;
    case 1:
        for (i = 0; i <= 3; i++) {
            slot = script_object_slot(i);
            if (slot != -1) {
                if (gUnk_030055A0[slot + 79].unk0 != 0)
                    done += script_sprite_update_walk(slot + 79, mode);
                else
                    done++;
            } else
                empty++;
        }
        if (empty == 4)
            map_script_command_done();
        if (done)
            map_script_command_done();
        break;
    }
}

void map_script_update_actor_spawn_glide(void) {
    struct FieldWork *s = &gFieldWork;

    switch (s->cmd_step) {
    case 0:
        spawn_script_sprite(s->cmd_args[0], s->cmd_args[1], s->cmd_args[2], s->cmd_args[3]);
        script_sprite_begin_walk(gUnk_03006D20.unkA, s->cmd_args[4], 0);
        s->cmd_step++;
        break;
    case 1:
        if (script_sprite_update_walk(gUnk_03006D20.unkA, 0))
            map_script_command_done();
        break;
    }
}

void map_script_update_actor_glide(void) {
    struct FieldWork *s = &gFieldWork;

    switch (s->cmd_step) {
    case 0:
        script_sprite_begin_walk(gUnk_03006D20.unkA, s->cmd_args[1], 0);
        s->cmd_step++;
        break;
    case 1:
        if (script_sprite_update_walk(gUnk_03006D20.unkA, 0))
            map_script_command_done();
        break;
    }
}

void map_script_update_jump_if_no_spare_medapart(void) {}

void map_script_update_switch_event_counter(void) {}

void map_script_update_jump(void) {}

void map_script_update_yes_no(void) {
    struct FieldWork *s = &gFieldWork;
    u32 r;

    switch (s->cmd_step) {
    case 0:
        yes_no_menu_open(0);
        s->cmd_step++;
        break;
    case 1:
        r = yes_no_menu_poll();
        if (r) {
            if (r & 0xF0)
                s->script_pos = s->branch_base + s->cmd_args[0];
            s->cmd_step++;
        }
        break;
    case 2:
        if (game_state_execute_handler_a())
            map_script_command_done();
        break;
    }
}

void map_script_update_yes_no_keep_window(void) {
    struct FieldWork *s = &gFieldWork;
    u32 r;

    switch (s->cmd_step) {
    case 0:
        yes_no_menu_open(1);
        s->cmd_step++;
        break;
    case 1:
        r = yes_no_menu_poll();
        if (r) {
            if (r & 0xF0)
                s->script_pos = s->branch_base + s->cmd_args[0];
            map_script_command_done();
        }
        break;
    }
}

// Opcode 0x33: start Robattle (battle id unkC2A) and keep its result (1 won, 2 lost) in sceneResult.
void map_script_update_robattle(void) {
    struct FieldWork *s = &gFieldWork;

    switch (s->cmd_step) {
    case 0:
        scene_state_reset();
        s->cmd_step++;
        break;
    case 1:
        if (scene_state_dispatch(0x20, 0)) {
            u32 v = s->unkC4F;
            if (v == 1)
                gUnk_03005310.sceneResult = v;
            else if (v == 2)
                gUnk_03005310.sceneResult = v;
            map_script_command_done();
        }
        break;
    }
}

// Empty and never referenced (dead code kept in the ROM).
static void map_script_update_unused_stub_1(void) {}

static void map_script_update_unused_stub_2(void) {}

// Opcode 0x36: give arg1 of item arg0 (capped at 99) and show the text.
void map_script_update_give_item(void) {
    struct FieldWork *s = &gFieldWork;
    s32 have;
    s32 n;

    switch (s->cmd_step) {
    case 0:
        message_steps_reset();
        have = field_item_quantity(s->cmd_args[0]);
        if (have == 99) {
            field_play_sound_effect(6);
            copy_string_to_text_buffer(0, item_name(s->cmd_args[0]));
            s->cmd_step = 1;
            break;
        }
        field_play_sound_effect(14);
        if (s->cmd_args[1] + have > 99)
            n = 99 - have;
        else
            n = s->cmd_args[1];
        field_give_item(gFieldWork.cmd_args[0], n);
        copy_string_to_text_buffer(0, item_name(gFieldWork.cmd_args[0]));
        format_number_to_text_buffer(1, n);
        gFieldWork.cmd_step = 2;
        break;
    case 1:
        if (message_step_run(0, 0, 0, gUnk_0847E8C4[0]))
            map_script_command_done();
        break;
    case 2:
        if (message_step_run(0, 0, 0, gUnk_0847E8C4[1]))
            map_script_command_done();
        break;
    }
}

// Opcode 0x37: take arg1 of item arg0 and show the text.
void map_script_update_take_item(void) {
    struct FieldWork *s = &gFieldWork;
    s32 have;
    s32 n;

    switch (s->cmd_step) {
    case 0:
        message_steps_reset();
        have = field_item_quantity(s->cmd_args[0]);
        if (have == 0) {
            field_play_sound_effect(6);
            copy_string_to_text_buffer(0, item_name(s->cmd_args[0]));
            s->cmd_step = 1;
            break;
        }
        field_play_sound_effect(5);
        if (have - s->cmd_args[1] < 0)
            n = have;
        else
            n = s->cmd_args[1];
        field_take_item(s->cmd_args[0], n);
        copy_string_to_text_buffer(0, item_name(s->cmd_args[0]));
        format_number_to_text_buffer(1, n);
        have = field_item_quantity(s->cmd_args[0]);
        if (have == 0)
            s->cmd_step = 3;
        else
            s->cmd_step = 2;
        break;
    case 1:
        if (message_step_run(0, 0, 0, gUnk_0847E8C4[2]))
            map_script_command_done();
        break;
    case 2:
        if (message_step_run(0, 0, 0, gUnk_0847E8C4[3]))
            map_script_command_done();
        break;
    case 3:
        if (message_step_run(0, 0, 0, gUnk_0847E8C4[4]))
            map_script_command_done();
        break;
    }
}

// Opcode 0x38: give arg2 of Medapart (arg0, arg1), capped at 99 (medapart_add_quantity), then show the text.
void map_script_update_give_medapart(void) {
    struct FieldWork *s = &gFieldWork;
    s32 have;
    s32 n;

    switch (s->cmd_step) {
    case 0:
        message_steps_reset();
        have = (s32)(field_medapart_counts(s->cmd_args[0], s->cmd_args[1]) & 0xFF00) >> 8;
        if (have == 99) {
            field_play_sound_effect(6);
            copy_string_to_text_buffer(0, medapart_name(s->cmd_args[1], s->cmd_args[0]));
            s->cmd_step = 1;
            break;
        }
        field_play_sound_effect(14);
        if (s->cmd_args[2] + have > 99)
            n = 99 - have;
        else
            n = s->cmd_args[2];
        field_give_medapart(gFieldWork.cmd_args[0], gFieldWork.cmd_args[1], n);
        copy_string_to_text_buffer(0, medapart_name(gFieldWork.cmd_args[1], gFieldWork.cmd_args[0]));
        format_number_to_text_buffer(1, n);
        gFieldWork.cmd_step = 2;
        break;
    case 1:
        if (message_step_run(0, 0, 0, gUnk_0847E8C4[5]))
            map_script_command_done();
        break;
    case 2:
        if (message_step_run(0, 0, 0, gUnk_0847E8C4[s->cmd_args[1] + 6]))
            map_script_command_done();
        break;
    }
}

// Opcode 0x39: take arg2 of Medapart (arg0, arg1) and show the text.
void map_script_update_take_medapart(void) {
    struct FieldWork *s = &gFieldWork;
    s32 have;
    s32 n;

    switch (s->cmd_step) {
    case 0:
        message_steps_reset();
        have = (s32)(field_medapart_counts(s->cmd_args[0], s->cmd_args[1]) & 0xFF00) >> 8;
        if (have == 0) {
            field_play_sound_effect(6);
            copy_string_to_text_buffer(0, medapart_name(s->cmd_args[1], s->cmd_args[0]));
            s->cmd_step = 1;
            break;
        }
        field_play_sound_effect(5);
        if (have - s->cmd_args[2] < 0)
            n = have;
        else
            n = s->cmd_args[2];
        field_take_medapart(s->cmd_args[0], s->cmd_args[1], n);
        copy_string_to_text_buffer(0, medapart_name(s->cmd_args[1], s->cmd_args[0]));
        format_number_to_text_buffer(1, n);
        have = field_medapart_counts(s->cmd_args[0], s->cmd_args[1]) & 0xFF00;
        if (have == 0)
            s->cmd_step = 3;
        else
            s->cmd_step = 2;
        break;
    case 1:
        if (message_step_run(0, 0, 0, gUnk_0847E8C4[s->cmd_args[1] + 14]))
            map_script_command_done();
        break;
    case 2:
        if (message_step_run(0, 0, 0, gUnk_0847E8C4[s->cmd_args[1] + 18]))
            map_script_command_done();
        break;
    case 3:
        if (message_step_run(0, 0, 0, gUnk_0847E8C4[s->cmd_args[1] + 18]))
            map_script_command_done();
        break;
    }
}

// Opcode 0x3A: add the 16-bit argument * 10 to gMoney and show the "got money" text (runtime: +5000 in the intro).
void map_script_update_give_money(void) {
    struct FieldWork *s = &gFieldWork;
    u32 n;

    switch (s->cmd_step) {
    case 0:
        message_steps_reset();
        n = ((s->cmd_args[0] << 8) | s->cmd_args[1]) * 10;
        field_play_sound_effect(7);
        add_money(n);
        format_money_to_text_buffer(0, n);
        s->cmd_step = 1;
        break;
    case 1:
        if (message_step_run(0, 0, 0, gUnk_0847E8C4[26]))
            map_script_command_done();
        break;
    }
}

// Opcode 0x3B: subtract the 16-bit argument * 10 from gMoney, at most what is left (runtime: -4980 buying Rokusho).
void map_script_update_take_money(void) {
    struct FieldWork *s = &gFieldWork;
    s32 n;
    s32 money;

    switch (s->cmd_step) {
    case 0:
        message_steps_reset();
        n = ((s->cmd_args[0] << 8) | s->cmd_args[1]) * 10;
        field_play_sound_effect(5);
        money = get_money();
        if (money - n <= 0)
            n = money;
        field_play_sound_effect(5);
        subtract_money(n);
        format_money_to_text_buffer(0, n);
        s->cmd_step = 1;
        break;
    case 1:
        if (message_step_run(0, 0, 0, gUnk_0847E8C4[27]))
            map_script_command_done();
        break;
    }
}

// Opcode 0x3C: give medal arg0 unless already owned (find_medal_slot_by_id), then run scene 1.
void map_script_update_give_medal(void) {
    struct FieldWork *s = &gFieldWork;

    switch (s->cmd_step) {
    case 0:
        message_steps_reset();
        field_play_sound_effect(14);
        copy_string_to_text_buffer(0, medal_name(s->cmd_args[0]));
        if (field_find_medal_slot(s->cmd_args[0])) {
            s->cmd_step = 1;
            break;
        }
        gUnk_030017EC = field_give_medal(s->cmd_args[0]);
        s->cmd_step = 2;
        break;
    case 1:
        if (message_step_run(0, 0, 0, gUnk_0847E8C4[28]))
            map_script_command_done();
        break;
    case 2:
        if (message_step_run(0, 0, 0, gUnk_0847E8C4[29])) {
            scene_state_reset();
            s->cmd_step++;
        }
        break;
    case 3:
        if (scene_state_dispatch(1, s->cmd_args[0]))
            map_script_command_done();
        break;
    }
}

// Opcode 0x3D: add Tinpet arg0 to the team unless it is full, then show its text (runs in walkthrough 01).
void map_script_update_give_tinpet(void) {
    struct FieldWork *s = &gFieldWork;

    switch (s->cmd_step) {
    case 0:
        message_steps_reset();
        field_play_sound_effect(14);
        if (field_team_is_full()) {
            s->cmd_step = 1;
            break;
        }
        field_team_add_tinpet(s->cmd_args[0]);
        s->cmd_step = 2;
        break;
    case 1:
        if (message_step_run(0, 0, 0, gUnk_0847E8C4[30]))
            map_script_command_done();
        break;
    case 2:
        if (message_step_run(0, 0, 0, gUnk_0847E8C4[s->cmd_args[0] + 31]))
            map_script_command_done();
        break;
    }
}

// Opcode 0x40: flash the screen white arg0 times.
void map_script_update_flash_white(void) {
    struct FieldWork *s = &gFieldWork;

    switch (s->cmd_step) {
    case 0:
        setup_palette_fade_to_color_with_obj(0x7FFF, 0.0f, 32.0f, 8.0f);
        s->cmd_step++;
        break;
    case 1:
        if (run_blend_fade_transition(0x7FFF)) {
            setup_palette_fade_to_color(0x7FFF, 32.0f, 0.0f, 8.0f);
            s->cmd_step++;
        }
        break;
    case 2:
        if (run_blend_fade_transition(0x7FFF)) {
            if (--s->cmd_args[0] != 0)
                s->cmd_step = 0;
            else
                map_script_command_done();
        }
        break;
    }
}

void map_script_update_all_actors_blink(void) {
    s32 empty = 0;
    s32 done = 0;
    s32 i;

    for (i = 0; i <= 3; i++) {
        if (script_object_slot(i) != -1) {
            if (gUnk_030055A0[script_object_slot(i) + 79].unk0 != 0)
                done += script_sprite_blink_step(script_object_slot(i) + 79);
            else
                empty++;
        }
    }
    if (empty == 4)
        done = 1;
    if (done)
        map_script_command_done();
}

// Opcode 0x42 (its command is a nullsub, so this never runs).
void map_script_update_player_slide(void) {
    struct FieldWork *s = &gFieldWork;

    switch (s->cmd_step) {
    case 0:
        s->script_pos = 16 / sprite_walk_speed(47);
        script_sprite_begin_slide(47, (s->cmd_args[0] << 4) | s->cmd_args[1], 0);
        s->cmd_step++;
        break;
    case 1:
        if (map_script_player_slide_step(s->cmd_args[0]))
            map_script_command_done();
        break;
    }
}

// guess: scripted player step in dir (field_player_step without the input checks); returns 1 when the step ends.
static u32 map_script_player_slide_step(u8 dir) {
    u32 ret;

    switch (dir) {
    case 0:
        if (gFieldWork.player_y - gFieldWork.map_origin_y != 0) {
            gFieldWork.player_y -= sprite_walk_speed(47);
            if (!field_map_origin_y() &&
                gFieldWork.player_y - gFieldWork.map_origin_y < gFieldWork.map_height * 8 - 0x60 && gBg1Scroll.y != 0) {
                field_scroll_bg_y(-sprite_walk_speed(47));
                gSpriteEntries[0].unk4 += sprite_walk_speed(47);
            }
        }
        break;
    case 1:
        if (gFieldWork.player_y - gFieldWork.map_origin_y + 16 < gFieldWork.map_height * 8) {
            gFieldWork.player_y += sprite_walk_speed(47);
            if (!field_map_origin_y() && gFieldWork.player_y - gFieldWork.map_origin_y + 16 > 0x50 &&
                gBg1Scroll.y + 0xA0 < gFieldWork.map_height * 8) {
                field_scroll_bg_y(sprite_walk_speed(47));
                gSpriteEntries[0].unk4 -= sprite_walk_speed(47);
            }
        }
        break;
    case 2:
        if (gFieldWork.player_x - gFieldWork.map_origin_x != 0) {
            gFieldWork.player_x -= sprite_walk_speed(47);
            if (!field_map_origin_x() &&
                gFieldWork.player_x - gFieldWork.map_origin_x < gFieldWork.map_width * 8 - 0x80 && gBg1Scroll.x != 0) {
                field_scroll_bg_x(-sprite_walk_speed(47));
                gSpriteEntries[0].unk2 += sprite_walk_speed(47);
            }
        }
        break;
    case 3:
        if (gFieldWork.player_x - gFieldWork.map_origin_x + 16 < gFieldWork.map_width * 8) {
            gFieldWork.player_x += sprite_walk_speed(47);
            if (!field_map_origin_x() && gFieldWork.player_x - gFieldWork.map_origin_x + 16 > 0x80 &&
                gBg1Scroll.x + 0xF0 < gFieldWork.map_width * 8) {
                field_scroll_bg_x(sprite_walk_speed(47));
                gSpriteEntries[0].unk2 -= sprite_walk_speed(47);
            }
        }
        break;
    }
    gUnk_03006D20.unk0--;
    ret = 0;
    if (gUnk_03006D20.unk0 == 0) {
        gFieldWork.player_tile_x = field_pixel_x_to_tile(gFieldWork.player_x);
        gFieldWork.player_tile_y = field_pixel_y_to_tile(gFieldWork.player_y);
        ret = 1;
    }
    return ret;
}

// Opcode 0x43: shake BG1 horizontally (arg0 0) or vertically for arg1 frames.
void map_script_update_shake_screen(void) {
    s32 idx;
    u8 phase;
    u16 off;
    u8 div;
    u8 n;

    switch (gFieldWork.cmd_step) {
    case 0:
        if (gFieldWork.cmd_args[0] == 0)
            gUnk_03005310.unk1E = gBg1Scroll.x;
        else
            gUnk_03005310.unk26 = gBg1Scroll.y;
        gFieldWork.cmd_args[2] = 0;
        gFieldWork.cmd_args[4] = gFieldWork.cmd_args[1];
        gFieldWork.cmd_step++;
        break;
    case 1:
        if (gFieldWork.cmd_args[1] != 0) {
            gFieldWork.cmd_args[1]--;
            div = gFieldWork.cmd_args[4];
            n = gFieldWork.cmd_args[2];
            idx = 256 / div * n / 2;
            if (gFieldWork.cmd_args[0] == 0) {
                off = gJumpArcTable[0][idx] / (128 - ((phase = n & 3) + 1) * 16);
                if (phase <= 1)
                    field_set_bg_scroll_x(gUnk_03005310.unk1E - off);
                else
                    field_set_bg_scroll_x(off + gUnk_03005310.unk1E);
            } else {
                off = gJumpArcTable[0][idx] / (128 - ((phase = n & 3) + 1) * 16);
                if (phase <= 1)
                    field_set_bg_scroll_y(gUnk_03005310.unk26 - off);
                else
                    field_set_bg_scroll_y(off + gUnk_03005310.unk26);
            }
            update_bg_scroll_offsets_a();
            if (gFieldWork.follower_active)
                follower_update_screen_pos();
            gFieldWork.cmd_args[2]++;
        } else {
            if (gFieldWork.cmd_args[0] == 0)
                field_set_bg_scroll_x(gUnk_03005310.unk1E);
            else
                field_set_bg_scroll_y(gUnk_03005310.unk26);
            update_bg_scroll_offsets_a();
            if (gFieldWork.follower_active)
                follower_update_screen_pos();
            map_script_command_done();
        }
        break;
    }
}

void map_script_update_jump_unless_part_value(void) {}

void map_script_update_jump_random(void) {}

void map_script_update_set_area_sprite_sheet(void) {}

void map_script_update_unused_54(void) {}

void map_script_update_unused_55(void) {}

// Opcode 0x56: reload the map (clears tile buffers, recopies the collision map, reloads NPC sprites).
void map_script_update_reload_map(void) {
    save_script_sprites();
    memzero_bytes(gUnk_03003870, 0x900);
    memzero_bytes(gUnk_03003870 + 0xA80, 0x900);
    memzero_bytes(gUnk_03005664, 0x90);
    memzero_bytes(gUnk_03005664 + 0xA8, 0x90);
    restore_script_sprites();
    memzero_bytes(gFieldWork.tile_map, 0x400);
    memcpy_u8(gUnk_084045A8[gFieldWork.area_id], gFieldWork.tile_map,
              (gFieldWork.map_height >> 1) * (gFieldWork.map_width >> 1));
    gFieldWork.npc_load_mode = 1;
    load_map_npc_sprites();
    update_entity_sprites_on_screen();
    map_script_command_done();
}

void map_script_update_unused_57(void) {}

void map_script_update_unused_58(void) {}

void map_script_update_open_shop(void) {
    struct FieldWork *s = &gFieldWork;

    switch (s->cmd_step) {
    case 0:
        scene_state_reset();
        s->cmd_step++;
        break;
    case 1:
        if (scene_state_dispatch(3, s->cmd_args[0]))
            map_script_command_done();
        break;
    }
}

void map_script_update_set_follower_facing(void) {}

void map_script_update_jump_if_team_under_3(void) {}

void map_script_update_jump_unless_full_part_set(void) {}

void map_script_update_set_medawatch_flag(void) {}

void map_script_update_set_disguise_block(void) {}

void map_script_update_set_encounters_off(void) {}

void map_script_update_give_starter_medabot(void) {}

void map_script_update_field_effect(void) {
    u32 kind;

    switch (gFieldWork.cmd_step) {
    case 0:
        kind = gUnk_03005350.unk1D4 & 0x3F;
        if (kind == 0xD || kind == 0x16) {
            if (field_effect_run_and_restore())
                gFieldWork.cmd_step++;
        } else if (field_effect_run_and_restore())
            map_script_command_done();
        break;
    case 1:
        gUnk_03006D20.unk0 = 16 / sprite_walk_speed(47);
        script_sprite_begin_slide(47, (gFieldWork.cmd_args[0] << 4) | gFieldWork.cmd_args[1], 0);
        gFieldWork.cmd_step++;
        break;
    case 2:
        if ((gUnk_03005350.unk1D4 & 0x3F) == 0xD)
            gFieldWork.player_facing = 2;
        else
            gFieldWork.player_facing = 3;
        if (map_script_player_slide_step(gFieldWork.player_facing)) {
            gFieldWork.player_visible = 1;
            gSpriteEntries[47].unk2A = gUnk_083D2908[gFieldWork.player_form];
            gFieldWork.player_tile_x = field_pixel_x_to_tile(gFieldWork.player_x);
            gFieldWork.player_tile_y = field_pixel_y_to_tile(gFieldWork.player_y);
            field_center_camera_on_player();
            field_set_player_sprite_visible(gFieldWork.player_visible);
            field_set_player_facing(gFieldWork.player_facing);
            update_bg_scroll_offsets_a();
            init_battle_sprites();
            map_script_command_done();
        }
        break;
    }
}

void map_script_update_actor_jump(void) {
    if (script_sprite_jump_step())
        map_script_command_done();
}

void map_script_update_skip_2(void) {
    map_script_command_done();
}

// Empty and never referenced (dead code kept in the ROM).
static void map_script_update_unused_stub_3(void) {}

void map_script_update_unused_6a(void) {}

void map_script_update_actor_spawn_walk_fast(void) {
    struct FieldWork *s = &gFieldWork;

    switch (s->cmd_step) {
    case 0:
        spawn_script_sprite(s->cmd_args[0], s->cmd_args[1], s->cmd_args[2], s->cmd_args[3]);
        script_sprite_begin_walk(gUnk_03006D20.unkA, s->cmd_args[4], 1);
        s->cmd_step++;
        break;
    case 1:
        if (script_sprite_update_walk(gUnk_03006D20.unkA, 1))
            map_script_command_done();
        break;
    }
}

void map_script_update_actor_walk_fast(void) {
    struct FieldWork *s = &gFieldWork;

    switch (s->cmd_step) {
    case 0:
        script_sprite_begin_walk(gUnk_03006D20.unkA, s->cmd_args[1], 1);
        s->cmd_step++;
        break;
    case 1:
        if (script_sprite_update_walk(gUnk_03006D20.unkA, 1))
            map_script_command_done();
        break;
    }
}

void map_script_update_actor_spawn_glide_fast(void) {
    struct FieldWork *s = &gFieldWork;

    switch (s->cmd_step) {
    case 0:
        spawn_script_sprite(s->cmd_args[0], s->cmd_args[1], s->cmd_args[2], s->cmd_args[3]);
        script_sprite_begin_walk(gUnk_03006D20.unkA, s->cmd_args[4], 1);
        s->cmd_step++;
        break;
    case 1:
        if (script_sprite_update_walk(gUnk_03006D20.unkA, 0))
            map_script_command_done();
        break;
    }
}

void map_script_update_actor_glide_fast(void) {
    struct FieldWork *s = &gFieldWork;

    switch (s->cmd_step) {
    case 0:
        script_sprite_begin_walk(gUnk_03006D20.unkA, s->cmd_args[1], 1);
        s->cmd_step++;
        break;
    case 1:
        if (script_sprite_update_walk(gUnk_03006D20.unkA, 0))
            map_script_command_done();
        break;
    }
}

void map_script_update_medabots_weekly(void) {
    struct FieldWork *s = &gFieldWork;

    switch (s->cmd_step) {
    case 0:
        scene_state_reset();
        s->cmd_step++;
        break;
    case 1:
        if (scene_state_dispatch(0x13, 0))
            map_script_command_done();
        break;
    }
}

void map_script_update_enter_player_name(void) {
    struct FieldWork *s = &gFieldWork;

    switch (s->cmd_step) {
    case 0:
        scene_state_reset();
        s->cmd_step++;
        break;
    case 1:
        if (scene_state_dispatch(0, 0))
            map_script_command_done();
        break;
    }
}

void map_script_update_rename_medal(void) {
    struct FieldWork *s = &gFieldWork;

    switch (s->cmd_step) {
    case 0:
        scene_state_reset();
        s->cmd_step++;
        break;
    case 1:
        if (scene_state_dispatch(2, 0))
            map_script_command_done();
        break;
    }
}

// Opcode 0x73: the scrolling text screen (switch_game_mode 8, mode 2 state 22).
void map_script_update_text_scroll(void) {
    struct FieldWork *s = &gFieldWork;

    switch (s->cmd_step) {
    case 0:
        scene_state_reset();
        s->cmd_step++;
        break;
    case 1:
        if (scene_state_dispatch(8, 0))
            map_script_command_done();
        break;
    }
}

void map_script_update_link_start(void) {
    struct FieldWork *s = &gFieldWork;

    switch (s->cmd_step) {
    case 0:
        switch_game_mode(4, 0);
        s->cmd_step++;
        break;
    case 1:
        if (gUnk_03006D20.unkC == 7)
            s->cmd_step = 2;
        else
            map_script_command_done();
        break;
    case 2:
        scene_state_reset();
        s->cmd_step++;
        break;
    case 3:
        if (scene_state_dispatch(5, 0))
            map_script_command_done();
        break;
    }
}

void map_script_update_race(void) {
    struct FieldWork *s = &gFieldWork;

    switch (s->cmd_step) {
    case 0:
        scene_state_reset();
        s->cmd_step++;
        break;
    case 1:
        if (scene_state_dispatch(0x10, 0)) {
            if (map_script_always_zero())
                gUnk_03005310.sceneResult = 1;
            map_script_command_done();
        }
        break;
    }
}

void map_script_update_event_picture(void) {
    struct FieldWork *s = &gFieldWork;

    switch (s->cmd_step) {
    case 0:
        scene_state_reset();
        s->cmd_step++;
        break;
    case 1:
        if (scene_state_dispatch(0x12, 0))
            map_script_command_done();
        break;
    }
}

void map_script_update_bomb_game(void) {
    struct FieldWork *s = &gFieldWork;

    switch (s->cmd_step) {
    case 0:
        scene_state_reset();
        s->cmd_step++;
        break;
    case 1:
        if (scene_state_dispatch(0x11, 0)) {
            if (map_script_always_zero())
                gUnk_03005310.sceneResult = 1;
            map_script_command_done();
        }
        break;
    }
}

void map_script_update_all_actors_slide(void) {
    map_script_all_actors_move_step(0, 0);
}

// Opcode 0x7F: end the follower: copy sprite 48 and its shadow back to map object arg0.
void map_script_update_follower_to_actor(void) {
    gSpriteEntries[48].unkC_8 = gFieldWork.follower_x;
    gSpriteEntries[48].unk10_8 = gFieldWork.follower_y;
    memcpy_u8(&gSpriteEntries[48], &gSpriteEntries[gFieldWork.cmd_args[0] + 79], 0x40);
    gUnk_030055A0[gFieldWork.cmd_args[0] + 79].unk0 = 0xFFFF;
    memcpy_u8(&gSpriteEntries[90], &gSpriteEntries[gFieldWork.cmd_args[0] + 121], 0x40);
    map_script_command_done();
}

void map_script_update_move_queue_run(void) {
    s32 done = 0;
    s32 i;
    u8 b;

    for (i = 0; i < gUnk_030064A0.unk52; i++) {
        if (gUnk_030064A0.unkA[i] > 1)
            done++;
        else {
            switch (gUnk_030064A0.unk12[i][gUnk_030064A0.unkA[i] * 4]) {
            case 1:
                script_object_set_direction(gUnk_030064A0.unk12[i][gUnk_030064A0.unkA[i] * 4 + 1],
                                            gUnk_030064A0.unk12[i][gUnk_030064A0.unkA[i] * 4 + 2]);
                gUnk_030064A0.unkA[i]++;
                break;
            case 2:
                gUnk_030064A0.unk54[i] = gUnk_030064A0.unk12[i][gUnk_030064A0.unkA[i] * 4 + 1];
                despawn_script_sprite(gUnk_030064A0.unk54[i]);
                gUnk_030064A0.unkA[i]++;
                break;
            case 3:
            case 4:
                switch (gUnk_030064A0.unk12[i][gUnk_030064A0.unkA[i] * 4]) {
                case 3:
                default:
                    b = 0;
                    break;
                case 4:
                    b = 1;
                    break;
                }
                switch (gUnk_030064A0.unk5C[i]) {
                case 0:
                    gUnk_030064A0.unk54[i] =
                        script_object_slot(gUnk_030064A0.unk12[i][gUnk_030064A0.unkA[i] * 4 + 1]) + 79;
                    script_sprite_begin_walk(gUnk_030064A0.unk54[i],
                                             gUnk_030064A0.unk12[i][gUnk_030064A0.unkA[i] * 4 + 2], b);
                    gUnk_030064A0.unk5C[i]++;
                    break;
                case 1:
                    if (script_sprite_update_walk(gUnk_030064A0.unk54[i], 1))
                        gUnk_030064A0.unk5C[i]++;
                    break;
                case 2:
                    gUnk_030064A0.unk5C[i] = 0;
                    gUnk_030064A0.unkA[i]++;
                    break;
                }
                break;
            case 0xFF:
                done++;
                break;
            default:
                done++;
                break;
            }
            if (gUnk_030064A0.unkA[i] > 1)
                done++;
        }
    }
    if (done == gUnk_030064A0.unk52) {
        gUnk_030064A0.unk52 = 0;
        memzero_bytes(gUnk_030064A0.unk12[0], 64);
        map_script_command_done();
    }
}

void map_script_update_set_bg_tile_anim(void) {
    if (gFieldWork.bg_anim_timer == 0) {
        gFieldWork.bg_anim_enabled = gFieldWork.cmd_args[0];
        map_script_command_done();
    }
}

void map_script_update_anim_queue_run(void) {
    s32 done = 0;
    s32 i;
    struct MapObject *obj;
    u32 id;

    for (i = 0; i < gUnk_030064A0.unk52; i++) {
        switch (gUnk_030064A0.unk12[i][0]) {
        case 0:
            done = 1;
            break;
        case 1:
            if (++gUnk_030064A0.unk2[i] > 5) {
                id = (gUnk_030064A0.unk12[i][1] << 8) | gUnk_030064A0.unk12[i][2];
                obj = map_object_find_by_id(id);
                if (obj != NULL && obj->unk4_6) {
                    set_sprite_anim_and_store(obj->unk4_0 + 49, gUnk_030064A0.unkA[i], obj);
                    if (gUnk_030064A0.unkA[i] == 0 && gUnk_030064A0.unk12[i][3] == 1 &&
                        find_map_event_by_coords(obj->x, obj->y) && gUnk_03006D38.unk3)
                        field_play_sound_effect(gUnk_083D29E6[gUnk_03006D38.unk3]);
                }
                gUnk_030064A0.unkA[i]++;
                gUnk_030064A0.unk2[i] = 0;
                if (gUnk_030064A0.unkA[i] > 3) {
                    gSpriteEntries[obj->unk4_0 + 49].unk24 = 0xFF;
                    done = 1;
                }
            }
            break;
        case 2:
            if (++gUnk_030064A0.unk2[i] > 5) {
                id = (gUnk_030064A0.unk12[i][1] << 8) | gUnk_030064A0.unk12[i][2];
                obj = map_object_find_by_id(id);
                if (obj != NULL && obj->unk4_6)
                    set_sprite_anim_and_store(obj->unk4_0 + 49, 3 - gUnk_030064A0.unkA[i], obj);
                gUnk_030064A0.unkA[i]++;
                gUnk_030064A0.unk2[i] = 0;
                if (gUnk_030064A0.unkA[i] > 3) {
                    gSpriteEntries[obj->unk4_0 + 49].unk24 = 0xFF;
                    gSpriteEntries[obj->unk4_0 + 49].unk20 = 0;
                    sprite_anim_start(obj->unk4_0 + 49,
                                      sprite_walk_anim_id(obj->unk4_0 + 49, gSpriteEntries[obj->unk4_0 + 49].unk20));
                    done = 1;
                }
            }
            break;
        default:
            done = 1;
            break;
        }
    }
    if (done) {
        gUnk_030064A0.unk52 = 0;
        memzero_bytes(gUnk_030064A0.unk12[0], 64);
        map_script_command_done();
    }
}
