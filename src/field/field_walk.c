// Field walking and scene changes: scene_state_dispatch fades out, switches to another game mode and
// back (shops, menus, battles), field_effect_run_and_restore runs a field effect (field/scene_3d), and
// field_walk_update is the frame handler that walks the player, triggers NPC / map events and warps.
// Talks to field/field_mode, field/field_update, field/script_sprites and the engine.
#include "global.h"

u32 field_effect_run_and_restore(void) {
    if ((gFieldEffect.flags & 0x3F) == 0xD || (gFieldEffect.flags & 0x3F) == 0x16) {
        gFieldWork.player_visible = 0;
        field_set_player_sprite_visible(0);
        update_bg_scroll_offsets_a();
    }
    if (field_effect_run() == 4) {
        switch (gFieldEffect.flags & 0x3F) {
        case 0:
        case 13:
        case 15:
        case 16:
        case 19:
        case 22:
            break;
        default:
            init_battle_sprites();
            break;
        }
        return 1;
    }
    return 0;
}

void init_battle_sprites(void) {
    s32 i;

    memzero_bytes((u8 *)gSpriteEntries, 0xA00);
    affine_params_reset();
    for (i = 0; i < 32; i++)
        calculate_oam_affine_matrix(i);
}

void scene_state_reset(void) {
    gScriptCmdWork.transition_step = 0;
}

u32 scene_state_dispatch(u32 mode, u32 mode_param) {
    u32 zero;
    u32 ret = 0;

    switch (gScriptCmdWork.transition_step) {
    case 0:
        if (mode != 0x20) {
            s32 n;
            if (mode == 0x12)
                field_update_music(0x17, 0);
            n = 8;
            if (mode == 8)
                n = 0xFF;
            setup_palette_fade_to_color_with_obj(0, 0.0f, 32.0f, n);
        }
        gScriptCmdWork.transition_step++;
        break;
    case 1:
        if (mode == 0x20) {
            save_script_sprites();
            switch_game_mode(0x20, mode_param);
            gScriptCmdWork.transition_step++;
        } else if (run_blend_fade_transition(0)) {
            if (mode == 0x12)
                field_update_music(0x18, 0);
            save_script_sprites();
            switch_game_mode(mode, mode_param);
            gScriptCmdWork.transition_step++;
        }
        break;
    case 2:
        memzero_bytes((u8 *)gSpriteEntries, 0x2000);
        memzero_bytes((u8 *)gEntityStates, 0x200);
        zero = 0;
        DmaSet(3, &zero, OAM, 0x85000100);
        zero = 0;
        DmaSet(3, &zero, PLTT, 0x85000100);
        REG_BLDCNT = 0;
        REG_BLDY = 0;
        clear_vram_tiles_1000();
        restore_script_sprites();
        REG_DISPCNT = 0x1E40;
        if (mode == 0x10 || mode == 0x20)
            gFieldWork.npc_load_mode = 2;
        else
            gFieldWork.npc_load_mode = 1;
        area_load_graphics();
        field_center_camera_on_player();
        blend_set_alpha_12_10();
        if (mode == 0x13) {
            field_effect_start(0x93, gFieldEffect.pos_x, gFieldEffect.pos_y, 0);
            while (!field_effect_run_and_restore())
                ;
        }
        if (mode != 8)
            setup_palette_fade_to_color(0, 32.0f, 0.0f, 8.0f);
        switch (mode) {
        case 0x20:
            field_update_music(0xD, 0);
            break;
        case 1:
            field_update_music(0x11, 0);
            break;
        case 3:
            field_update_music(0x14, 0);
            break;
        case 0x13:
            field_update_music(0x13, 0);
            break;
        case 0:
            field_update_music(0x10, 0);
            break;
        case 2:
            field_update_music(0x12, 0);
            break;
        case 8:
            field_update_music(0x1B, 0);
            break;
        case 5:
            field_update_music(0x1A, 0);
            break;
        case 0x10:
            field_update_music(0x15, 0);
            break;
        case 0x12:
            field_update_music(0x19, 0);
            break;
        case 0x11:
            field_update_music(0x16, 0);
            break;
        case 0x14:
            field_update_music(0xF, 0);
            break;
        }
        gScriptCmdWork.transition_step++;
        break;
    case 3:
        gScriptCmdWork.transition_step++;
        break;
    case 4:
        if (mode == 8 || run_blend_fade_transition(0))
            ret = 1;
        break;
    }
    return ret;
}

void field_walk_update(void) {
    u32 done;
    u32 npc;
    u32 warp;

    switch (gFieldState.step) {
    case 0:
        set_battle_state_cancel_flag();
        if (find_map_event_by_coords(gFieldWork.player_tile_x, gFieldWork.player_tile_y)) {
            gFieldWork.player_step_frames = 16 / sprite_walk_speed(47);
            field_set_player_facing(gSpriteEntries[47].unk20);
            sprite_anim_start(47, gSpriteEntries[47].unk20);
            if (gFieldWork.follower_active) {
                gFieldWork.follower_x = gFieldWork.player_x;
                gFieldWork.follower_y = gFieldWork.player_y;
                follower_set_facing(gSpriteEntries[47].unk20);
                sprite_anim_start(48, gSpriteEntries[48].unk2B * 4 + gSpriteEntries[48].unk20);
            }
            follower_turn_toward_player(3);
            gFieldState.step = 1;
        } else {
            if (gFieldSceneParams.warp_sound == 4)
                field_play_sound_effect(0);
            gFieldState.step = 2;
        }
        break;
    case 1:
        field_player_step(gSpriteEntries[47].unk20);
        if (gFieldWork.player_step_frames == 0) {
            if (gFieldSceneParams.warp_sound == 4)
                field_play_sound_effect(0);
            gFieldState.step++;
        }
        break;
    case 2:
        done = 0;
        npc = 0;
        warp = 0;
        if (gFieldWork.player_step_frames == 0 && gFieldWork.script_running == 0) {
            update_npc_random_animation();
            if (find_npc_event_match()) {
                npc = 1;
            } else {
                if (find_map_event_by_coords(gFieldWork.player_tile_x, gFieldWork.player_tile_y)) {
                    gFieldState.step = 3;
                    if (gFieldSceneParams.warp_sound)
                        field_play_sound_effect(gWarpSoundEffects[gFieldSceneParams.warp_sound]);
                    setup_palette_fade_to_color_with_obj(0x7FFF, 0.0f, 32.0f, 8.0f);
                    warp = 1;
                }
                if (!npc && !warp) {
                    if (KEYS_LO(gHeldKeys) & 1) {
                        gSpriteEntries[47].unk2A = 1;
                        gSpriteEntries[48].unk2A = 1;
                    } else {
                        gSpriteEntries[48].unk2A = gSpriteEntries[47].unk2A =
                            gPlayerFormSpeedIds[gFieldWork.player_form];
                    }
                    if (KEYS_LO(gNewKeys) & 1) {
                        if (map_cursor_move_and_check_event())
                            done = 1;
                        else if (check_room_exit_at_position() != -1) {
                            gGameSubState = 8;
                            done = 1;
                        }
                    } else if (KEYS_LO(gNewKeys) & 2) {
                        if (gFieldWork.medawatch_enabled) {
                            message_reset_hook();
                            gGameMode = 0;
                            gGameState = 1;
                            gGameSubState = 0;
                            gFieldState.saved_bg0_x = gBg0Scroll.x;
                            gFieldState.saved_bg0_y = gBg0Scroll.y;
                            gFieldState.saved_bg1_x = gBg1Scroll.x;
                            gFieldState.saved_bg1_y = gBg1Scroll.y;
                            gFieldState.saved_bg2_x = gBg2Scroll.x;
                            gFieldState.saved_bg2_y = gBg2Scroll.y;
                            gFieldState.saved_bg3_x = gBg3Scroll.x;
                            gFieldState.saved_bg3_y = gBg3Scroll.y;
                            gBg0Scroll.x = 0;
                            gBg0Scroll.y = 0;
                            gFieldWork.player_facing = gSpriteEntries[47].unk20;
                            gFieldWork.follower_facing = gSpriteEntries[48].unk20;
                            gFieldWork.follower_sprite_set = gSpriteEntries[48].unk2B;
                            save_script_sprites();
                            gFieldWork.npc_load_mode = 2;
                            done = 1;
                        }
                    } else if (KEYS_HI(gNewKeys) & 1 && gFieldWork.player_form == 1) {
                        field_play_sound_effect(0x74);
                    }
                }
            }
        }
        if (!done && !npc && !warp) {
            if (KEYS_HI(gNewKeys) & 1 && gFieldWork.player_form == 1)
                field_play_sound_effect(0x74);
            field_player_walk_input();
        } else {
            field_set_player_facing(gSpriteEntries[47].unk20);
            follower_set_facing(gSpriteEntries[48].unk20);
        }
        break;
    case 3:
        if (run_blend_fade_transition(0x7FFF))
            gFieldState.step = 4;
        break;
    case 4:
        field_warp_to_area();
        gFieldState.step = 0;
        gGameMode = 1;
        gGameState = 1;
        gGameSubState = 1;
        gFieldWork.npc_load_mode = 1;
        break;
    }
    update_bg_scroll_offsets_a();
    follower_update_screen_pos();
    update_entity_sprites_on_screen();
}

// guess: resets the field frame handler (field_walk_update runs a state machine on gFieldState.step)
static void field_walk_reset(void) {
    gFieldState.unk0 = 1;
    gFieldState.step = 0;
}
