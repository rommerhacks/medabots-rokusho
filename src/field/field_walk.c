// Field walking and scene changes: scene_state_dispatch fades out, switches to another game mode and
// back (shops, menus, battles), battle_scene_state_dispatch runs a battle sequence inside the field, and
// field_walk_update is the frame handler that walks the player, triggers NPC / map events and warps.
// Talks to field/field_mode, field/field_update, field/script_sprites and the engine.
#include "global.h"

u32 battle_scene_state_dispatch(void) {
    if ((gUnk_03005350.unk1D4 & 0x3F) == 0xD || (gUnk_03005350.unk1D4 & 0x3F) == 0x16) {
        gUnk_030057E0.unkC5B = 0;
        sub_08052BA0(0);
        update_bg_scroll_offsets_a();
    }
    if (battle_sequence_dispatch() == 4) {
        switch (gUnk_03005350.unk1D4 & 0x3F) {
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

    sub_080496C8((u8 *)gUnk_03002C30, 0xA00);
    sub_080492CC();
    for (i = 0; i < 32; i++)
        calculate_oam_affine_matrix(i);
}

void scene_state_reset(void) {
    gUnk_03006D20.unkB = 0;
}

u32 scene_state_dispatch(u32 a, u32 b) {
    u32 zero;
    u32 ret = 0;

    switch (gUnk_03006D20.unkB) {
    case 0:
        if (a != 0x20) {
            s32 n;
            if (a == 0x12)
                dispatch_jump_table_29(0x17, 0);
            n = 8;
            if (a == 8)
                n = 0xFF;
            setup_palette_fade_to_color_with_obj(0, 0.0f, 32.0f, n);
        }
        gUnk_03006D20.unkB++;
        break;
    case 1:
        if (a == 0x20) {
            save_script_sprites();
            switch_game_mode(0x20, b);
            gUnk_03006D20.unkB++;
        } else if (run_blend_fade_transition(0)) {
            if (a == 0x12)
                dispatch_jump_table_29(0x18, 0);
            save_script_sprites();
            switch_game_mode(a, b);
            gUnk_03006D20.unkB++;
        }
        break;
    case 2:
        sub_080496C8((u8 *)gUnk_03002C30, 0x2000);
        sub_080496C8((u8 *)gUnk_030055A0, 0x200);
        zero = 0;
        DmaSet(3, &zero, OAM, 0x85000100);
        zero = 0;
        DmaSet(3, &zero, PLTT, 0x85000100);
        REG_BLDCNT = 0;
        REG_BLDY = 0;
        sub_0804B1FC();
        restore_script_sprites();
        REG_DISPCNT = 0x1E40;
        if (a == 0x10 || a == 0x20)
            gUnk_030057E0.unkCBA = 2;
        else
            gUnk_030057E0.unkCBA = 1;
        update_battle_field_frame();
        field_center_camera_on_player();
        sub_080487E4();
        if (a == 0x13) {
            init_sprite_affine_matrices_and_state(0x93, gUnk_03005350.unk1D8, gUnk_03005350.unk1DC, 0);
            while (!battle_scene_state_dispatch())
                ;
        }
        if (a != 8)
            setup_palette_fade_to_color(0, 32.0f, 0.0f, 8.0f);
        switch (a) {
        case 0x20:
            dispatch_jump_table_29(0xD, 0);
            break;
        case 1:
            dispatch_jump_table_29(0x11, 0);
            break;
        case 3:
            dispatch_jump_table_29(0x14, 0);
            break;
        case 0x13:
            dispatch_jump_table_29(0x13, 0);
            break;
        case 0:
            dispatch_jump_table_29(0x10, 0);
            break;
        case 2:
            dispatch_jump_table_29(0x12, 0);
            break;
        case 8:
            dispatch_jump_table_29(0x1B, 0);
            break;
        case 5:
            dispatch_jump_table_29(0x1A, 0);
            break;
        case 0x10:
            dispatch_jump_table_29(0x15, 0);
            break;
        case 0x12:
            dispatch_jump_table_29(0x19, 0);
            break;
        case 0x11:
            dispatch_jump_table_29(0x16, 0);
            break;
        case 0x14:
            dispatch_jump_table_29(0xF, 0);
            break;
        }
        gUnk_03006D20.unkB++;
        break;
    case 3:
        gUnk_03006D20.unkB++;
        break;
    case 4:
        if (a == 8 || run_blend_fade_transition(0))
            ret = 1;
        break;
    }
    return ret;
}

void field_walk_update(void) {
    u32 done;
    u32 npc;
    u32 warp;

    switch (gUnk_03005310.unk1) {
    case 0:
        set_battle_state_cancel_flag();
        if (find_map_event_by_coords(gUnk_030057E0.unkC56, gUnk_030057E0.unkC57)) {
            gUnk_030057E0.unkC58 = 16 / sprite_walk_speed(47);
            field_set_player_facing(gUnk_03002C30[47].unk20);
            sub_080493D4(47, gUnk_03002C30[47].unk20);
            if (gUnk_030057E0.unkC76) {
                gUnk_030057E0.unkC6E = gUnk_030057E0.unkC52;
                gUnk_030057E0.unkC70 = gUnk_030057E0.unkC54;
                set_battle_state_byte_c83(gUnk_03002C30[47].unk20);
                sub_080493D4(48, gUnk_03002C30[48].unk2B * 4 + gUnk_03002C30[48].unk20);
            }
            update_battle_direction_indicator(3);
            gUnk_03005310.unk1 = 1;
        } else {
            if (gUnk_03006D38.unk3 == 4)
                sub_08047BA8(0);
            gUnk_03005310.unk1 = 2;
        }
        break;
    case 1:
        field_player_step(gUnk_03002C30[47].unk20);
        if (gUnk_030057E0.unkC58 == 0) {
            if (gUnk_03006D38.unk3 == 4)
                sub_08047BA8(0);
            gUnk_03005310.unk1++;
        }
        break;
    case 2:
        done = 0;
        npc = 0;
        warp = 0;
        if (gUnk_030057E0.unkC58 == 0 && gUnk_030057E0.unkC88 == 0) {
            update_npc_random_animation();
            if (find_npc_event_match()) {
                npc = 1;
            } else {
                if (find_map_event_by_coords(gUnk_030057E0.unkC56, gUnk_030057E0.unkC57)) {
                    gUnk_03005310.unk1 = 3;
                    if (gUnk_03006D38.unk3)
                        sub_08047BA8(gUnk_083D29E6[gUnk_03006D38.unk3]);
                    setup_palette_fade_to_color_with_obj(0x7FFF, 0.0f, 32.0f, 8.0f);
                    warp = 1;
                }
                if (!npc && !warp) {
                    if (KEYS_LO(gHeldKeys) & 1) {
                        gUnk_03002C30[47].unk2A = 1;
                        gUnk_03002C30[48].unk2A = 1;
                    } else {
                        gUnk_03002C30[48].unk2A = gUnk_03002C30[47].unk2A = gUnk_083D2908[gUnk_030057E0.unkC5C];
                    }
                    if (KEYS_LO(gNewKeys) & 1) {
                        if (map_cursor_move_and_check_event())
                            done = 1;
                        else if (check_room_exit_at_position() != -1) {
                            gGameSubState = 8;
                            done = 1;
                        }
                    } else if (KEYS_LO(gNewKeys) & 2) {
                        if (gUnk_030057E0.unkC33) {
                            sub_08047E4C();
                            gGameMode = 0;
                            gGameState = 1;
                            gGameSubState = 0;
                            gUnk_03005310.unk1C = gBg0Scroll.x;
                            gUnk_03005310.unk24 = gBg0Scroll.y;
                            gUnk_03005310.unk1E = gBg1Scroll.x;
                            gUnk_03005310.unk26 = gBg1Scroll.y;
                            gUnk_03005310.unk20 = gBg2Scroll.x;
                            gUnk_03005310.unk28 = gBg2Scroll.y;
                            gUnk_03005310.unk22 = gBg3Scroll.x;
                            gUnk_03005310.unk2A = gBg3Scroll.y;
                            gBg0Scroll.x = 0;
                            gBg0Scroll.y = 0;
                            gUnk_030057E0.unkC67 = gUnk_03002C30[47].unk20;
                            gUnk_030057E0.unkC83 = gUnk_03002C30[48].unk20;
                            gUnk_030057E0.unkC84 = gUnk_03002C30[48].unk2B;
                            save_script_sprites();
                            gUnk_030057E0.unkCBA = 2;
                            done = 1;
                        }
                    } else if (KEYS_HI(gNewKeys) & 1 && gUnk_030057E0.unkC5C == 1) {
                        sub_08047BA8(0x74);
                    }
                }
            }
        }
        if (!done && !npc && !warp) {
            if (KEYS_HI(gNewKeys) & 1 && gUnk_030057E0.unkC5C == 1)
                sub_08047BA8(0x74);
            field_player_walk_input();
        } else {
            field_set_player_facing(gUnk_03002C30[47].unk20);
            set_battle_state_byte_c83(gUnk_03002C30[48].unk20);
        }
        break;
    case 3:
        if (run_blend_fade_transition(0x7FFF))
            gUnk_03005310.unk1 = 4;
        break;
    case 4:
        field_warp_to_area();
        gUnk_03005310.unk1 = 0;
        gGameMode = 1;
        gGameState = 1;
        gGameSubState = 1;
        gUnk_030057E0.unkCBA = 1;
        break;
    }
    update_bg_scroll_offsets_a();
    update_bg_scroll_offsets_b();
    update_entity_sprites_on_screen();
}

// guess: resets the field frame handler (field_walk_update runs a state machine on unk1)
static void field_walk_reset(void) {
    gUnk_03005310.unk0 = 1;
    gUnk_03005310.unk1 = 0;
}
