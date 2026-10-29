// The field game mode (game mode 1): field_update runs every frame (map script, the gGameSubState
// handler from gFieldSubStates 0x083D1FAC, sprites, BG tile animation, OAM affine), followed by the
// sub-state handlers and the helpers they use: status characters, room graphics loading
// (load_room_graphics) and the input-driven blend effect. Sub-state 5 (field_state_walk) is the normal
// one; the others are short chains that each end back in it:
//   0       new game, 1-4 entering a room (field_walk warps, then fade in from white),
//   6-7     back from a menu (return_to_field), 8-9 the message of a room exit the player can't take,
//   10-11   continue from the title menu, 13-14 back from a battle (field_resume),
//   16-20   back from the item menu / save screen (applies or clears a disguise),
//   24-26 / 28-30  vehicle menu forms 1 and 2 (toggled on and off), 32-35 town map warp effect,
//   40-41   vehicle menu entry 1 effect, 48-52 the debug battle-field screen (field/field_debug).
// Unused slots point at field_state_unused. Talks to field/map_script, field/field_effects,
// field/area_graphics and the engine.

#include "global.h"
#include "constants/field_sprites.h"
#include "constants/sprites.h"

static u32 field_effect_sequence_done(void);

// Copies the 32 affine matrices (pa..pd at +6 of each 16-byte gAffineParams entry) into the
// affineParam slots of gOamBuffer.
static inline void copy_affine(u8 *base) {
    u16 *src = (u16 *)(base + 6);
    struct OamData *oam = gOamBuffer;
    s32 i;

    for (i = 31; i >= 0; i--) {
        oam[0].affineParam = src[0];
        oam[1].affineParam = src[1];
        oam[2].affineParam = src[2];
        oam[3].affineParam = src[3];
        src += 8;
        oam += 4;
    }
}

// Per-frame update of the field game mode (game mode table 0x083D1F84 entry 1): frame counter,
// map script, the gGameSubState handler from gFieldSubStates, sprites, BG tile animation, OAM affine matrices
void field_update(void) {
    s32 i;

    gFieldState.frame_counter++;
    if (gFieldWork.script_running) {
        if (gFieldWork.cmd_busy)
            map_script_update_command();
        else
            map_script_run_command();
        if (gFieldWork.script_field_update)
            gFieldSubStates[gGameSubState]();
    } else {
        gFieldSubStates[gGameSubState]();
    }
    update_entity_sprites_on_screen();
    update_npc_sprite_animations();
    animate_area_bg_tiles();
    for (i = 0; i < 32; i++)
        calculate_oam_affine_matrix(i);
    field_sort_sprites_by_depth();
    copy_affine((u8 *)gAffineParams);
}

void new_game_init(void) {
    u32 zero;

    memzero_bytes((u8 *)&gPlayerRecord, 0x1C);
    memzero_bytes((u8 *)gMedals, 0x780);
    memzero_bytes(gMedapartInventory, 0x3C0);
    memzero_bytes((u8 *)gTeamSlots, 0x48);
    memzero_bytes((u8 *)gItemInventory, 0x80);
    memzero_bytes((u8 *)&gFieldWork, 0xCC0);
    memzero_bytes((u8 *)&gGameWork, 0x13C);
    memzero_bytes((u8 *)gBattleBots, 0x600);
    clear_oam();
    memzero_bytes((u8 *)gSpriteEntries, 0x2000);
    memzero_bytes((u8 *)gEntityStates, 0x200);
    zero = 0;
    DmaSet(3, &zero, OAM, 0x85000100);
    medal_list_init_order();
    team_init_order();
    gFieldWork.affinity_ar = 16;
    gFieldWork.affinity_ka = 16;
    REG_BG1CNT = 0xC609;
    REG_BG2CNT = 0xEA0A;
    REG_BG3CNT = 0xEE0B;
    REG_DISPCNT = 0x1E40;
    gMapScriptData = (u8 *)gMapScripts;
    gEventFlags = (u8 *)&gFieldWork;
    gFieldEffectEntities = (struct FieldEffectEntity *)0x02039000;
    gFieldTilemapBuf = (u16 *)0x02030000;
    gAreaAnimTileSrc = (u8 *)0x02038000;
    memzero_bytes((u8 *)gSpriteEntries, 0x2000);
    memzero_bytes((u8 *)gEntityStates, 0x200);
    zero = 0;
    DmaSet(3, &zero, OAM, 0x85000100);
    affine_params_reset();
    bg2_affine_reset();
    gFieldState.saved_bg0_x = 0;
    gFieldState.saved_bg0_y = 0;
    gFieldState.saved_bg1_x = 0;
    gFieldState.saved_bg1_y = 0;
    gFieldState.saved_bg2_x = 0;
    gFieldState.saved_bg2_y = 0;
    gFieldState.saved_bg3_x = 0;
    gFieldState.saved_bg3_y = 0;
    gBg0Scroll.x = 0;
    gBg0Scroll.y = 0;
    gBg1Scroll.x = 0;
    gBg1Scroll.y = 0;
    gBg2Scroll.x = 0;
    gBg2Scroll.y = 0;
    gBg3Scroll.x = 0;
    gBg3Scroll.y = 0;
    memzero_bytes(&gFieldWork.warp_unused0, 0x454);
    gFieldWork.npc_load_mode = 0;
    gFieldWork.area_id = 0x17;
    gFieldWork.warp_unused0 = 0xE;
    gFieldWork.warp_unused1 = 7;
    gFieldWork.player_x = gFieldWork.map_origin_x + 0x120;
    gFieldWork.player_y = gFieldWork.map_origin_y + 0xD0;
    gFieldWork.player_facing = 0;
    gFieldWork.bg_anim_enabled = 1;
    gFieldWork.player_tile_x = field_pixel_x_to_tile(gFieldWork.player_x);
    gFieldWork.player_tile_y = field_pixel_y_to_tile(gFieldWork.player_y);
    gFieldWork.player_form = 0;
    gFieldWork.player_visible = 1;
    sprite_entry_init(0x2F, SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(2) | SPRITE_FLAG_PART_PALETTE,
                      3, 0, 1);
    update_bg_scroll_offsets_a();
    if (gFieldWork.follower_active) {
        sprite_entry_init(
            0x30, SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(2) | SPRITE_FLAG_PART_PALETTE,
            gFieldWork.follower_sprite_set * 12 + gFieldWork.follower_facing, gFieldWork.follower_sprite_set, 1);
        gFieldWork.follower_x = 0x50 - gFieldWork.map_origin_x;
        gFieldWork.follower_y = 0x60 - gFieldWork.map_origin_y;
    }
    gFieldState.step = 0;
    REG_BLDCNT = 0;
    REG_BLDY = 0;
    blend_set_alpha_12_10();
    setup_palette_fade_to_color(0x7FFF, 32.0f, 0.0f, 8.0f);
    game_substate_advance();
}

// Sub-state 1: entering a room (after field_walk_update warps): clear the sprites and stop the
// map script, fade in from white next.
void field_room_enter_reset(void) {
    u32 zero;
    memzero_bytes((u8 *)gSpriteEntries, 0x2000);
    memzero_bytes((u8 *)gEntityStates, 0x200);
    zero = 0;
    DmaSet(3, &zero, OAM, 0x85000100);
    affine_params_reset();
    bg2_affine_reset();
    gFieldWork.script_pos = 0;
    gFieldWork.script_running = 0;
    gFieldWork.cmd_busy = 0;
    setup_palette_fade_to_color(0x7FFF, 32.0f, 0.0f, 8.0f);
    game_substate_advance();
}

void field_room_enter_load(void) {
    area_load_graphics();
    area_load_encounter_rate();
    field_update_music(0, 0);
    game_substate_advance();
}

void field_room_enter_wait(void) {
    game_substate_advance();
}

void field_room_enter_fade_in(void) {
    if (run_blend_fade_transition(0x7FFF))
        game_substate_advance();
}

void field_state_walk(void) {
    field_walk_update();
}

void field_resume_wait(void) {
    game_substate_advance();
}

// Sub-state 7 (return_to_field): back from a menu; the script sprites saved on the way out come back.
void field_resume_after_menu(void) {
    clear_vram_tiles_1000();
    restore_script_sprites();
    field_update_music(5, 0);
    gFieldState.step = 0;
    gGameSubState = 5;
}

// Sub-states 8-9: A at a room exit field_walk_update didn't take shows gRoomExitMessages[exit].
void field_exit_message_init(void) {
    message_steps_reset();
    game_substate_advance();
}

void field_exit_message_show(void) {
    s32 exit = check_room_exit_at_position();
    if (message_step_run(0, 0, 0, gRoomExitMessages[exit]))
        gGameSubState = 5;
}

// Sub-states 10-11 (title menu Continue): reset the field RAM the save doesn't hold and load the room.
void field_continue_load(void) {
    u32 zero;
    clear_oam();
    memzero_bytes((u8 *)gSpriteEntries, 0x2000);
    memzero_bytes((u8 *)gEntityStates, 0x200);
    zero = 0;
    DmaSet(3, &zero, OAM, 0x85000100);
    memzero_bytes((u8 *)&gGameWork, 0x13C);
    memzero_bytes((u8 *)gBattleBots, 0x600);
    gFieldWork.script_running = 0;
    gFieldWork.cmd_busy = 0;
    gFieldWork.cmd_step = 0;
    gFieldWork.script_pos = 0;
    gFieldWork.script_id = 0;
    gFieldWork.script_field_update = 0;
    gFieldWork.equipped_legs_value = 0;
    gFieldState.unused38 = 0;
    memzero_bytes((u8 *)&gScriptCmdWork, 16);
    clear_vram_tiles_1000();
    gFieldState.step = 0;
    restore_script_sprites();
    gMapScriptData = (u8 *)gMapScripts;
    gEventFlags = (u8 *)&gFieldWork;
    gFieldEffectEntities = (struct FieldEffectEntity *)0x02039000;
    gFieldTilemapBuf = (u16 *)0x02030000;
    gAreaAnimTileSrc = (u8 *)0x02038000;
    memzero_bytes((u8 *)gSpriteEntries, 0x2000);
    memzero_bytes((u8 *)gEntityStates, 0x200);
    zero = 0;
    DmaSet(3, &zero, OAM, 0x85000100);
    REG_BLDCNT = 0;
    REG_BLDY = 0;
    REG_DISPCNT = 0x1E40;
    gFieldWork.npc_load_mode = 2;
    area_load_graphics();
    area_load_encounter_rate();
    field_update_music(0x1C, 0);
    field_center_camera_on_player();
    blend_set_alpha_12_10();
    setup_palette_fade_to_color(0x7FFF, 32.0f, 0.0f, 8.0f);
    game_substate_advance();
}

void field_continue_fade_in(void) {
    if (run_blend_fade_transition(0x7FFF)) {
        gFieldState.step = 0;
        init_battle_field_setup();
        update_bg_scroll_offsets_a();
        field_set_player_facing(gFieldWork.player_facing);
        gGameSubState = 5;
    }
}

// Sub-states 13-14 (field_resume after a battle): reload the room and fade in from black.
void field_battle_return_load(void) {
    u32 zero;
    memzero_bytes((u8 *)gSpriteEntries, 0x2000);
    memzero_bytes((u8 *)gEntityStates, 0x200);
    zero = 0;
    DmaSet(3, &zero, OAM, 0x85000100);
    zero = 0;
    DmaSet(3, &zero, PLTT, 0x85000100);
    REG_BLDCNT = 0;
    REG_BLDY = 0;
    gFieldState.step = 0;
    restore_script_sprites();
    REG_DISPCNT = 0x1E40;
    gFieldWork.npc_load_mode = 2;
    area_load_graphics();
    area_load_encounter_rate();
    field_update_music(0xE, 0);
    field_center_camera_on_player();
    blend_set_alpha_12_10();
    setup_palette_fade_to_color(0, 32.0f, 0.0f, 8.0f);
    game_substate_advance();
}

void field_battle_return_fade_in(void) {
    if (run_blend_fade_transition(0)) {
        gFieldState.step = 0;
        init_battle_field_setup();
        update_bg_scroll_offsets_a();
        field_set_player_facing(gFieldWork.player_facing);
        gGameSubState = 5;
    }
}

// Sub-state 16 (back from the item menu or the save screen): a new form from the item menu becomes the saved
// one; using the current one again turns it off. guess: from the item menu code, not watched at runtime.
void field_disguise_update(void) {
    if (gFieldWork.player_form == gFieldWork.saved_player_form) {
        gFieldWork.player_form = 0;
        gFieldWork.saved_player_form = 0;
    } else
        gFieldWork.saved_player_form = gFieldWork.player_form;
    game_substate_advance();
}

void field_disguise_reload(void) {
    u32 zero;
    memzero_bytes((u8 *)gSpriteEntries, 0x2000);
    memzero_bytes((u8 *)gEntityStates, 0x200);
    zero = 0;
    DmaSet(3, &zero, OAM, 0x85000100);
    clear_vram_tiles_1000();
    REG_DISPCNT = 0x1E40;
    gFieldWork.npc_load_mode = 2;
    area_load_graphics();
    field_update_music(6, 0);
    setup_palette_fade_to_color(0, 32.0f, 0.0f, 8.0f);
    game_substate_advance();
}

void field_disguise_fade_in(void) {
    if (run_blend_fade_transition(0))
        game_substate_advance();
}

void field_disguise_wait(void) {
    game_substate_advance();
}

// Not called directly (hidden in the tail of field_disguise_wait).
void field_disguise_done(void) {
    gFieldState.step = 0;
    gGameSubState = 5;
}

void field_form1_wait(void) {
    game_substate_advance();
}

// Not called directly (hidden in the tail of field_form1_wait).
static void field_unused_advance_a(void) {
    game_substate_advance();
}

// Not called directly (hidden in the tail of field_form1_wait).
static void field_unused_advance_b(void) {
    game_substate_advance();
}

// Vehicle menu entry 0 (switch_game_mode 0x41): toggle player form 1.
void field_form1_toggle(void) {
    if (gFieldWork.player_form != 1) {
        gFieldWork.saved_player_form = gFieldWork.player_form;
        gFieldWork.player_form = 1;
    } else
        gFieldWork.player_form = gFieldWork.saved_player_form;
    load_battle_palette_via_dma(0);
    field_update_music(7, 0);
    game_substate_advance();
}

// Not called directly (hidden in the tail of field_form1_toggle).
void field_form1_done(void) {
    gFieldState.step = 0;
    gGameSubState = 5;
}

void field_form2_wait(void) {
    game_substate_advance();
}

// Vehicle menu entry 3 (switch_game_mode 0x42): toggle player form 2.
void field_form2_toggle(void) {
    if (gFieldWork.player_form != 2) {
        gFieldWork.saved_player_form = gFieldWork.player_form;
        gFieldWork.player_form = 2;
    } else
        gFieldWork.player_form = gFieldWork.saved_player_form;
    load_battle_palette_via_dma(0);
    field_update_music(8, 0);
    game_substate_advance();
}

// After a form change: walk speed and facing for the new form, then back to walking.
void field_form_resume_walk(void) {
    s32 speed;
    struct FieldWork *field;
    speed = sprite_walk_speed(47);
    field = &gFieldWork;
    field->player_step_frames = 0x10 / speed;
    field_set_player_facing(gSpriteEntries[47].work[FIELD_SPR_FACING]);
    sprite_anim_start(47, gSpriteEntries[47].work[FIELD_SPR_FACING]);
    if (field->follower_active) {
        field->follower_x = field->player_x;
        field->follower_y = field->player_y;
        follower_set_facing(gSpriteEntries[47].work[FIELD_SPR_FACING]);
        sprite_anim_start(48,
                          gSpriteEntries[48].work[FIELD_SPR_ANIM_SET] * 4 + gSpriteEntries[48].work[FIELD_SPR_FACING]);
    }
    follower_turn_toward_player(1);
    field_play_sound_effect(0x57);
    gFieldState.step = 1;
    gGameSubState = 5;
}

void field_map_warp_wait(void) {
    game_substate_advance();
}

// Sub-states 32-35 (town map warp): reload the room, then play effect sequence 0x12 (form 0xB) on the
// player until it ends.
void field_map_warp_load(void) {
    vu32 zero;

    memzero_bytes((u8 *)gSpriteEntries, 0x2000);
    memzero_bytes((u8 *)gEntityStates, 0x200);
    zero = 0;
    DmaSet(3, &zero, OAM, 0x85000100);
    clear_vram_tiles_1000();
    REG_DISPCNT = 0x1E40;
    gFieldWork.npc_load_mode = 2;
    area_load_graphics();
    area_load_encounter_rate();
    field_update_music(0xB, 0);
    setup_palette_fade_to_color(0, 32.0f, 0.0f, 8.0f);
    game_substate_advance();
}

void field_map_warp_start_effect(void) {
    if (run_blend_fade_transition(0)) {
        gFieldWork.player_form = 0xB;
        load_battle_palette_via_dma(0);
        field_effect_start(0x12, gFieldWork.player_x, gFieldWork.player_y, 0);
        game_substate_advance();
    }
}

void field_map_warp_run_effect(void) {
    if (field_effect_sequence_done()) {
        gFieldWork.player_form = gFieldWork.saved_player_form;
        load_battle_palette_via_dma(0);
        gFieldWork.player_facing = 1;
        gFieldState.step = 0;
        init_battle_field_setup();
        update_bg_scroll_offsets_a();
        field_set_player_facing(gFieldWork.player_facing);
        if (gFieldWork.follower_active) {
            gFieldWork.follower_x = gFieldWork.player_x;
            gFieldWork.follower_y = gFieldWork.player_y;
            follower_set_facing(gSpriteEntries[47].work[FIELD_SPR_FACING]);
            sprite_anim_start(0x30, gSpriteEntries[48].work[FIELD_SPR_ANIM_SET] * 4 +
                                        gSpriteEntries[48].work[FIELD_SPR_FACING]);
        }
        field_sort_sprites_by_depth();
        gGameSubState = 5;
    }
}

// Empty and never referenced (dead code kept in the ROM).
static void field_update_unused_stub_1(void) {}

static void field_update_unused_stub_2(void) {}

// Sub-states 40-41 (vehicle menu entry 1, switch_game_mode 0x43): effect sequence 0xE (form 0xC).
// guess: a teleport, from the effect only.
void field_teleport_start_effect(void) {
    gFieldWork.player_form = 0xC;
    load_battle_palette_via_dma(0);
    field_update_music(9, 0);
    field_effect_start(0xE, gFieldWork.player_x, gFieldWork.player_y, 0);
    game_substate_advance();
}

void field_teleport_run_effect(void) {
    if (field_effect_sequence_done()) {
        gFieldWork.player_form = gFieldWork.saved_player_form;
        load_battle_palette_via_dma(0);
        gFieldWork.player_facing = 1;
        gFieldState.step = 0;
        init_battle_field_setup();
        update_bg_scroll_offsets_a();
        field_set_player_facing(gFieldWork.player_facing);
        if (gFieldWork.follower_active) {
            gFieldWork.follower_x = gFieldWork.player_x;
            gFieldWork.follower_y = gFieldWork.player_y;
            follower_set_facing(gSpriteEntries[47].work[FIELD_SPR_FACING]);
            sprite_anim_start(0x30, gSpriteEntries[48].work[FIELD_SPR_ANIM_SET] * 4 +
                                        gSpriteEntries[48].work[FIELD_SPR_FACING]);
        }
        field_sort_sprites_by_depth();
        gGameSubState = 5;
    }
}

// Empty and never referenced (dead code kept in the ROM).
static void field_update_unused_stub_3(void) {}

static void field_update_unused_stub_4(void) {}

static void field_update_unused_stub_5(void) {}

// Sub-states 48-52: the field debug screen (pages in field/field_debug); the map page warps.
void field_debug_open(void) {
    struct FieldDebugWork *debug = &gFieldDebug;

    if (debug->debug_dc == 0) {
        debug->labels_drawn = 1;
        field_debug_init_page(0);
    }
    game_substate_advance();
}

void field_debug_run_page(void) {
    field_debug_update_page(gFieldDebug.page);
}

void field_debug_wait_effect(void) {
    if (field_debug_page_done())
        field_debug_close();
}

void field_debug_fade_out(void) {
    setup_palette_fade_to_color_with_obj(0x7FFF, 0.0f, 32.0f, 8.0f);
    game_substate_advance();
}

void field_debug_reload_area(void) {
    s32 x, y;

    if (run_blend_fade_transition(0x7FFF)) {
        gMapScriptData = (u8 *)gMapScripts;
        if (gFieldDebug.page == 0)
            gFieldWork.area_id = gFieldDebug.area_id;
        field_load_area_tiles(gFieldWork.area_id);
        x = field_pixel_x_to_tile(gFieldWork.player_x);
        y = field_pixel_y_to_tile(gFieldWork.player_y);
        if (gFieldWork.player_tile_x >= area_map_size(gFieldWork.area_id, 0) / 2)
            x = area_map_size(gFieldWork.area_id, 0) / 2 - 1;
        if (gFieldWork.player_tile_y >= area_map_size(gFieldWork.area_id, 1) / 2)
            y = area_map_size(gFieldWork.area_id, 1) / 2 - 1;
        gFieldWork.player_x = (x << 4) + gFieldWork.map_origin_x;
        gFieldWork.player_y = (y << 4) + gFieldWork.map_origin_y;
        gFieldWork.player_tile_x = field_pixel_x_to_tile(gFieldWork.player_x);
        gFieldWork.player_tile_y = field_pixel_y_to_tile(gFieldWork.player_y);
        field_center_camera_on_player();
        gFieldWork.loaded_form = gFieldWork.player_form;
        load_battle_terrain_data();
        REG_DISPCNT = 0x1E40;
        clear_vram_tiles_1000();
        gFieldWork.npc_load_mode = 0;
        gGameSubState = 1;
    }
}

void field_state_unused(void) {}

// Marks each of the area's gAreaWarps cells as 2 in the collision map (tile_map).
static void field_mark_warp_tiles(void) {
    const struct AreaWarp *warps = gAreaWarps[gFieldWork.area_id];
    s32 i;

    for (i = 0; warps[i].x != 0xFF; i++)
        gFieldWork.tile_map[warps[i].y * (gFieldWork.map_width >> 1) + warps[i].x] = 2;
}

void field_sort_sprites_by_depth(void) {
    s32 i;

    if (gFieldWork.depth_sort_enabled) {
        for (i = 0x2E; i <= 0x7F; i++) {
            if (gSpriteEntries[i].order == 0xFF)
                gSpriteEntries[i].order = 0xFF;
            else if (gSpriteEntries[i].order != 0)
                gSpriteEntries[i].order = (gSpriteEntries[i].y + 0x10) / 4 + 0x40;
            else
                gSpriteEntries[i].order = 0;
            if (i == 0x30 && gFieldWork.follower_y == gFieldWork.player_y)
                gSpriteEntries[48].order = gSpriteEntries[47].order - 1;
            if (i == 0x59 && gFieldWork.follower_y == gFieldWork.player_y)
                gSpriteEntries[0x59].order = gSpriteEntries[48].order - 1;
        }
    }
}

void clear_vram_tiles_1000(void) {
    vu32 zero;

    zero = 0;
    DmaSet(3, &zero, VRAM + 0x1000, 0x85000800);
}

static void clear_vram_tiles_2800(void) {
    vu32 zero;

    zero = 0;
    DmaSet(3, &zero, VRAM + 0x2800, 0x85001A00);
}

static void clear_vram_bg2_tiles(void) {
    memset_bytes((u8 *)(VRAM + 0x3000), 0x6000, 0x80);
}

// gAreaBgTilemaps indexed as a flat pointer array (three LZ77 tilemaps per area);
// the index has to reach the load unfolded ((area * 3 + 1) << 2), hence the helper.
static inline const void *area_gfx(const void *const *table, u32 i) {
    return table[i];
}

// Sets BG1-3 control, loads the area's tile map and its three BG layers (or blank tiles and a fill
// when the area has no layer graphics), then centres the camera.
void load_room_graphics(void) {
    const void *const *tbl;
    REG_BG1CNT = 0xC609;
    REG_BG2CNT = 0xEA0A;
    REG_BG3CNT = 0xEE0B;
    field_load_area_tiles(gFieldWork.area_id);
    gFieldWork.map_width = area_map_size(gFieldWork.area_id, 0);
    gFieldWork.map_height = area_map_size(gFieldWork.area_id, 1);
    gFieldWork.bg_map_width = field_tilemap_header_word(gFieldWork.area_id, 0);
    gFieldWork.bg_map_height = field_tilemap_header_word(gFieldWork.area_id, 1);
    clear_vram_bg2_tiles();
    memzero_bytes(gFieldWork.tile_map, 0x400);
    memcpy_u8(gAreaCollisionMaps[gFieldWork.area_id], gFieldWork.tile_map,
              (gFieldWork.map_height >> 1) * (gFieldWork.map_width >> 1));
    tbl = (const void *const *)gAreaBgTilemaps;
    if (area_gfx(tbl, gFieldWork.area_id * 3) != NULL && gAreaBgTiles[gFieldWork.area_id] != NULL) {
        LZ77UnCompVram(gAreaBgTiles[gFieldWork.area_id], (void *)0x06009000);
        LZ77UnCompVram(area_gfx(tbl, gFieldWork.area_id * 3), gFieldTilemapBuf);
        copy_tilemap_with_offset_08048CA4(gFieldTilemapBuf + 8, (void *)0x06003000, gFieldWork.bg_map_height,
                                          gFieldWork.bg_map_width, 0x40, 0x40, 0x80);
        LZ77UnCompVram(area_gfx(tbl, gFieldWork.area_id * 3 + 1), gFieldTilemapBuf);
        copy_tilemap_with_offset_08048CA4(gFieldTilemapBuf + 8, (void *)0x06005000, gFieldWork.bg_map_height,
                                          gFieldWork.bg_map_width, 0x40, 0x40, 0x80);
        LZ77UnCompVram(area_gfx(tbl, gFieldWork.area_id * 3 + 2), gFieldTilemapBuf);
        copy_tilemap_with_offset_08048CA4(gFieldTilemapBuf + 8, (void *)0x06007000, gFieldWork.bg_map_height,
                                          gFieldWork.bg_map_width, 0x40, 0x40, 0x80);
        if (gAreaAnimBgTiles[gFieldWork.area_id] != NULL)
            LZ77UnCompVram(gAreaAnimBgTiles[gFieldWork.area_id], gAreaAnimTileSrc);
    } else {
        memzero_bytes((u8 *)0x06009000, 0x80);
        DmaSet(3, gFallbackAreaTiles0, 0x06009080, 0x80000040);
        DmaSet(3, gFallbackAreaTiles1, 0x06009100, 0x80000040);
        DmaSet(3, gFallbackAreaTiles2, 0x06009180, 0x80000040);
        DmaSet(3, gFallbackAreaTiles3, 0x06009200, 0x80000040);
        DmaSet(3, gFallbackAreaTiles0, 0x06009280, 0x80000040);
        DmaSet(3, gFallbackAreaTiles0, 0x06009300, 0x80000040);
        DmaSet(3, gFallbackAreaTiles0, 0x06009380, 0x80000040);
        DmaSet(3, gFallbackAreaTiles4, 0x06009400, 0x80000040);
        DmaSet(3, gFallbackAreaTiles5, 0x06009480, 0x80000040);
        memset_bytes((u8 *)gFieldTilemapBuf, gFieldWork.map_height * gFieldWork.map_width, 8);
        copy_tiles_to_bg_tilemap(gFieldTilemapBuf, (void *)0x06003000, gFieldWork.map_height, gFieldWork.map_width,
                                 0x40, 0x40, gFieldWork.map_origin_y / 8, gFieldWork.map_origin_x / 8, 0x80);
        copy_tiles_to_bg_tilemap(gFieldTilemapBuf, (void *)0x06005000, gFieldWork.map_height, gFieldWork.map_width,
                                 0x40, 0x40, gFieldWork.map_origin_y / 8, gFieldWork.map_origin_x / 8, 0x80);
        copy_tiles_to_bg_tilemap(gFieldWork.tile_map, (void *)0x06007000, gFieldWork.map_height, gFieldWork.map_width,
                                 0x40, 0x40, gFieldWork.map_origin_y / 8, gFieldWork.map_origin_x / 8, 0x80);
    }
    field_center_camera_on_player();
    check_and_update_battlefield_palette();
}

static void update_blend_effect_from_input(void) {
    if (KEYS_LO(gNewKeys) & 0x40) {
        gBlendEffect.evy_level += 1.0f;
        gBlendEffect.evy_level = (s32)((u32)gBlendEffect.evy_level & 0xF);
        REG_BLDY = (u32)gBlendEffect.evy_level % 64;
    }
    if (KEYS_HI(gNewKeys) & 1) {
        gBlendEffect.eva_level += 1.0f;
        gBlendEffect.eva_level = (s32)((u32)gBlendEffect.eva_level & 0xF);
        REG_BLDALPHA = (((u32)gBlendEffect.evb_level & 0x3F) << 8) | ((u32)gBlendEffect.eva_level & 0x3F);
    }
    if (KEYS_HI(gNewKeys) & 2) {
        gBlendEffect.evb_level += 1.0f;
        gBlendEffect.evb_level = (s32)((u32)gBlendEffect.evb_level & 0xF);
        REG_BLDALPHA = (((u32)gBlendEffect.evb_level & 0x3F) << 8) | ((u32)gBlendEffect.eva_level & 0x3F);
    }
}

// Whether the field effect (field_effect_run) has finished.
static u32 field_effect_sequence_done(void) {
    if (field_effect_run() == 4)
        return 1;
    return 0;
}
