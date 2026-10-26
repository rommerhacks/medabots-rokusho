// The field game mode (game mode 1): field_update runs every frame (map script, the gGameSubState
// handler from gFieldSubStates 0x083D1FAC, sprites, BG tile animation, OAM affine), followed by the
// sub-state handlers (new_game_init first) and the helpers they use: status characters, room graphics
// loading (load_room_graphics) and the input-driven blend effect.
// Talks to field/map_script, field/field_effects, field/area_graphics and the engine.

#include "global.h"

static u32 sub_0804B694(void);

// Copies the 32 affine matrices (pa..pd at +6 of each 16-byte gUnk_03006D40 entry) into the
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

    gUnk_03005310.unk4++;
    if (gUnk_030057E0.unkC88) {
        if (gUnk_030057E0.unkC89)
            map_script_update_command();
        else
            map_script_run_command();
        if (gUnk_030057E0.unkC5F)
            gFieldSubStates[gGameSubState]();
    } else {
        gFieldSubStates[gGameSubState]();
    }
    update_entity_sprites_on_screen();
    update_npc_sprite_animations();
    animate_area_bg_tiles();
    for (i = 0; i < 32; i++)
        calculate_oam_affine_matrix(i);
    update_battle_entity_status_chars();
    copy_affine((u8 *)gUnk_03006D40);
}

void new_game_init(void) {
    u32 zero;

    sub_080496C8((u8 *)&gUnk_03002B70, 0x1C);
    sub_080496C8((u8 *)gUnk_03000BE0, 0x780);
    sub_080496C8(gMedapartInventory, 0x3C0);
    sub_080496C8((u8 *)gUnk_030017A0, 0x48);
    sub_080496C8((u8 *)gItemInventory, 0x80);
    sub_080496C8((u8 *)&gUnk_030057E0, 0xCC0);
    sub_080496C8((u8 *)&gUnk_03000440, 0x13C);
    sub_080496C8((u8 *)gUnk_03000590, 0x600);
    clear_oam();
    sub_080496C8((u8 *)gUnk_03002C30, 0x2000);
    sub_080496C8((u8 *)gUnk_030055A0, 0x200);
    zero = 0;
    DmaSet(3, &zero, OAM, 0x85000100);
    sub_08041D28();
    sub_080421A0();
    gUnk_030057E0.unkCBC = 16;
    gUnk_030057E0.unkCBD = 16;
    REG_BG1CNT = 0xC609;
    REG_BG2CNT = 0xEA0A;
    REG_BG3CNT = 0xEE0B;
    REG_DISPCNT = 0x1E40;
    gMapScriptData = (u8 *)gUnk_08764CB0;
    gUnk_030057D8 = (u8 *)&gUnk_030057E0;
    gUnk_03006D30 = (struct BattleEntity3D *)0x02039000;
    gUnk_03006D14 = (u16 *)0x02030000;
    gUnk_030057DC = (u8 *)0x02038000;
    sub_080496C8((u8 *)gUnk_03002C30, 0x2000);
    sub_080496C8((u8 *)gUnk_030055A0, 0x200);
    zero = 0;
    DmaSet(3, &zero, OAM, 0x85000100);
    sub_080492CC();
    sub_08048B6C();
    gUnk_03005310.unk1C = 0;
    gUnk_03005310.unk24 = 0;
    gUnk_03005310.unk1E = 0;
    gUnk_03005310.unk26 = 0;
    gUnk_03005310.unk20 = 0;
    gUnk_03005310.unk28 = 0;
    gUnk_03005310.unk22 = 0;
    gUnk_03005310.unk2A = 0;
    gBg0Scroll.x = 0;
    gBg0Scroll.y = 0;
    gBg1Scroll.x = 0;
    gBg1Scroll.y = 0;
    gBg2Scroll.x = 0;
    gBg2Scroll.y = 0;
    gBg3Scroll.x = 0;
    gBg3Scroll.y = 0;
    sub_080496C8(&gUnk_030057E0.unk7FC, 0x454);
    gUnk_030057E0.unkCBA = 0;
    gUnk_030057E0.unk7FE = 0x17;
    gUnk_030057E0.unk7FC = 0xE;
    gUnk_030057E0.unk7FD = 7;
    gUnk_030057E0.unkC52 = gUnk_030057E0.unkC48 + 0x120;
    gUnk_030057E0.unkC54 = gUnk_030057E0.unkC4A + 0xD0;
    gUnk_030057E0.unkC67 = 0;
    gUnk_030057E0.unkC34 = 1;
    gUnk_030057E0.unkC56 = sub_080526F0(gUnk_030057E0.unkC52);
    gUnk_030057E0.unkC57 = sub_08052714(gUnk_030057E0.unkC54);
    gUnk_030057E0.unkC5C = 0;
    gUnk_030057E0.unkC5B = 1;
    init_battle_sprite_entry_08048818(0x2F, 0xC804, 3, 0, 1);
    update_bg_scroll_offsets_a();
    if (gUnk_030057E0.unkC76) {
        init_battle_sprite_entry_08048818(0x30, 0xC804, gUnk_030057E0.unkC84 * 12 + gUnk_030057E0.unkC83,
                                          gUnk_030057E0.unkC84, 1);
        gUnk_030057E0.unkC6E = 0x50 - gUnk_030057E0.unkC48;
        gUnk_030057E0.unkC70 = 0x60 - gUnk_030057E0.unkC4A;
    }
    gUnk_03005310.unk1 = 0;
    REG_BLDCNT = 0;
    REG_BLDY = 0;
    sub_080487E4();
    setup_palette_fade_to_color(0x7FFF, 32.0f, 0.0f, 8.0f);
    sub_0804A1C4();
}

void sub_0804A5C0(void) {
    u32 zero;
    sub_080496C8((u8 *)gUnk_03002C30, 0x2000);
    sub_080496C8((u8 *)gUnk_030055A0, 0x200);
    zero = 0;
    DmaSet(3, &zero, OAM, 0x85000100);
    sub_080492CC();
    sub_08048B6C();
    gUnk_030057E0.unkC8A = 0;
    gUnk_030057E0.unkC88 = 0;
    gUnk_030057E0.unkC89 = 0;
    setup_palette_fade_to_color(0x7FFF, 32.0f, 0.0f, 8.0f);
    sub_0804A1C4();
}

void sub_0804A654(void) {
    update_battle_field_frame();
    load_battlefield_data_to_buffer();
    dispatch_jump_table_29(0, 0);
    sub_0804A1C4();
}

void sub_0804A670(void) {
    sub_0804A1C4();
}

void sub_0804A67C(void) {
    if (run_blend_fade_transition(0x7FFF))
        sub_0804A1C4();
}

void sub_0804A694(void) {
    sub_08050F10();
}

void sub_0804A6A0(void) {
    sub_0804A1C4();
}

void sub_0804A6AC(void) {
    sub_0804B1FC();
    restore_script_sprites();
    dispatch_jump_table_29(5, 0);
    gUnk_03005310.unk1 = 0;
    gGameSubState = 5;
}

void sub_0804A6D8(void) {
    init_cursor_state();
    sub_0804A1C4();
}

void sub_0804A6E8(void) {
    s32 exit = check_room_exit_at_position();
    if (scene_transition_step_08047C24(0, 0, 0, gUnk_08411D54[exit]))
        gGameSubState = 5;
}

void sub_0804A718(void) {
    u32 zero;
    clear_oam();
    sub_080496C8((u8 *)gUnk_03002C30, 0x2000);
    sub_080496C8((u8 *)gUnk_030055A0, 0x200);
    zero = 0;
    DmaSet(3, &zero, OAM, 0x85000100);
    sub_080496C8((u8 *)&gUnk_03000440, 0x13C);
    sub_080496C8((u8 *)gUnk_03000590, 0x600);
    gUnk_030057E0.unkC88 = 0;
    gUnk_030057E0.unkC89 = 0;
    gUnk_030057E0.unkC93 = 0;
    gUnk_030057E0.unkC8A = 0;
    gUnk_030057E0.unkC8E = 0;
    gUnk_030057E0.unkC5F = 0;
    gUnk_030057E0.unkC60 = 0;
    gUnk_03005310.unk38 = 0;
    sub_080496C8((u8 *)&gUnk_03006D20, 16);
    sub_0804B1FC();
    gUnk_03005310.unk1 = 0;
    restore_script_sprites();
    gUnk_03005590 = gUnk_08764CB0;
    gUnk_030057D8 = (u8 *)&gUnk_030057E0;
    gUnk_03006D30 = (struct BattleEntity3D *)0x02039000;
    gUnk_03006D14 = (u16 *)0x02030000;
    gUnk_030057DC = (u8 *)0x02038000;
    sub_080496C8((u8 *)gUnk_03002C30, 0x2000);
    sub_080496C8((u8 *)gUnk_030055A0, 0x200);
    zero = 0;
    DmaSet(3, &zero, OAM, 0x85000100);
    REG_BLDCNT = 0;
    REG_BLDY = 0;
    REG_DISPCNT = 0x1E40;
    gUnk_030057E0.unkCBA = 2;
    update_battle_field_frame();
    load_battlefield_data_to_buffer();
    dispatch_jump_table_29(0x1C, 0);
    field_center_camera_on_player();
    sub_080487E4();
    setup_palette_fade_to_color(0x7FFF, 32.0f, 0.0f, 8.0f);
    sub_0804A1C4();
}

void sub_0804A8B4(void) {
    if (run_blend_fade_transition(0x7FFF)) {
        gUnk_03005310.unk1 = 0;
        init_battle_field_setup();
        update_bg_scroll_offsets_a();
        field_set_player_facing(gUnk_030057E0.unkC67);
        gGameSubState = 5;
    }
}

void sub_0804A8F8(void) {
    u32 zero;
    sub_080496C8((u8 *)gUnk_03002C30, 0x2000);
    sub_080496C8((u8 *)gUnk_030055A0, 0x200);
    zero = 0;
    DmaSet(3, &zero, OAM, 0x85000100);
    zero = 0;
    DmaSet(3, &zero, PLTT, 0x85000100);
    REG_BLDCNT = 0;
    REG_BLDY = 0;
    gUnk_03005310.unk1 = 0;
    restore_script_sprites();
    REG_DISPCNT = 0x1E40;
    gUnk_030057E0.unkCBA = 2;
    update_battle_field_frame();
    load_battlefield_data_to_buffer();
    dispatch_jump_table_29(0xE, 0);
    field_center_camera_on_player();
    sub_080487E4();
    setup_palette_fade_to_color(0, 32.0f, 0.0f, 8.0f);
    sub_0804A1C4();
}

void sub_0804A9B8(void) {
    if (run_blend_fade_transition(0)) {
        gUnk_03005310.unk1 = 0;
        init_battle_field_setup();
        update_bg_scroll_offsets_a();
        field_set_player_facing(gUnk_030057E0.unkC67);
        gGameSubState = 5;
    }
}

void sub_0804A9F8(void) {
    if (gUnk_030057E0.unkC5C == gUnk_030057E0.unkC69) {
        gUnk_030057E0.unkC5C = 0;
        gUnk_030057E0.unkC69 = 0;
    } else
        gUnk_030057E0.unkC69 = gUnk_030057E0.unkC5C;
    sub_0804A1C4();
}

void sub_0804AA28(void) {
    u32 zero;
    sub_080496C8((u8 *)gUnk_03002C30, 0x2000);
    sub_080496C8((u8 *)gUnk_030055A0, 0x200);
    zero = 0;
    DmaSet(3, &zero, OAM, 0x85000100);
    sub_0804B1FC();
    REG_DISPCNT = 0x1E40;
    gUnk_030057E0.unkCBA = 2;
    update_battle_field_frame();
    dispatch_jump_table_29(6, 0);
    setup_palette_fade_to_color(0, 32.0f, 0.0f, 8.0f);
    sub_0804A1C4();
}

void sub_0804AAB8(void) {
    if (run_blend_fade_transition(0))
        sub_0804A1C4();
}

void sub_0804AACC(void) {
    sub_0804A1C4();
}

// Not called directly (hidden in the tail of sub_0804AACC).
void sub_0804AAD8(void) {
    gUnk_03005310.unk1 = 0;
    gGameSubState = 5;
}

void sub_0804AAF0(void) {
    sub_0804A1C4();
}

// Not called directly (hidden in the tail of sub_0804AAF0).
static void sub_0804AAFC(void) {
    sub_0804A1C4();
}

// Not called directly (hidden in the tail of sub_0804AAF0).
static void sub_0804AB08(void) {
    sub_0804A1C4();
}

void sub_0804AB14(void) {
    if (gUnk_030057E0.unkC5C != 1) {
        gUnk_030057E0.unkC69 = gUnk_030057E0.unkC5C;
        gUnk_030057E0.unkC5C = 1;
    } else
        gUnk_030057E0.unkC5C = gUnk_030057E0.unkC69;
    load_battle_palette_via_dma(0);
    dispatch_jump_table_29(7, 0);
    sub_0804A1C4();
}

// Not called directly (hidden in the tail of sub_0804AB14).
void sub_0804AB5C(void) {
    gUnk_03005310.unk1 = 0;
    gGameSubState = 5;
}

void sub_0804AB74(void) {
    sub_0804A1C4();
}

void sub_0804AB80(void) {
    if (gUnk_030057E0.unkC5C != 2) {
        gUnk_030057E0.unkC69 = gUnk_030057E0.unkC5C;
        gUnk_030057E0.unkC5C = 2;
    } else
        gUnk_030057E0.unkC5C = gUnk_030057E0.unkC69;
    load_battle_palette_via_dma(0);
    dispatch_jump_table_29(8, 0);
    sub_0804A1C4();
}

void sub_0804ABC8(void) {
    s32 r;
    struct Unk_030057E0 *s;
    r = sub_080518F4(47);
    s = &gUnk_030057E0;
    s->unkC58 = 0x10 / r;
    field_set_player_facing(gUnk_03002C30[47].unk20);
    sub_080493D4(47, gUnk_03002C30[47].unk20);
    if (s->unkC76) {
        s->unkC6E = s->unkC52;
        s->unkC70 = s->unkC54;
        set_battle_state_byte_c83(gUnk_03002C30[47].unk20);
        sub_080493D4(48, gUnk_03002C30[48].unk2B * 4 + gUnk_03002C30[48].unk20);
    }
    update_battle_direction_indicator(1);
    sub_08047BA8(0x57);
    gUnk_03005310.unk1 = 1;
    gGameSubState = 5;
}

void sub_0804AC7C(void) {
    sub_0804A1C4();
}

void sub_0804AC88(void) {
    vu32 zero;

    sub_080496C8((u8 *)gUnk_03002C30, 0x2000);
    sub_080496C8((u8 *)gUnk_030055A0, 0x200);
    zero = 0;
    DmaSet(3, &zero, OAM, 0x85000100);
    sub_0804B1FC();
    REG_DISPCNT = 0x1E40;
    gUnk_030057E0.unkCBA = 2;
    update_battle_field_frame();
    load_battlefield_data_to_buffer();
    dispatch_jump_table_29(0xB, 0);
    setup_palette_fade_to_color(0, 32.0f, 0.0f, 8.0f);
    sub_0804A1C4();
}

void sub_0804AD1C(void) {
    if (run_blend_fade_transition(0)) {
        gUnk_030057E0.unkC5C = 0xB;
        load_battle_palette_via_dma(0);
        init_sprite_affine_matrices_and_state(0x12, gUnk_030057E0.unkC52, gUnk_030057E0.unkC54, 0);
        sub_0804A1C4();
    }
}

void sub_0804AD68(void) {
    if (sub_0804B694()) {
        gUnk_030057E0.unkC5C = gUnk_030057E0.unkC69;
        load_battle_palette_via_dma(0);
        gUnk_030057E0.unkC67 = 1;
        gUnk_03005310.unk1 = 0;
        init_battle_field_setup();
        update_bg_scroll_offsets_a();
        field_set_player_facing(gUnk_030057E0.unkC67);
        if (gUnk_030057E0.unkC76) {
            gUnk_030057E0.unkC6E = gUnk_030057E0.unkC52;
            gUnk_030057E0.unkC70 = gUnk_030057E0.unkC54;
            set_battle_state_byte_c83(gUnk_03002C30[47].unk20);
            sub_080493D4(0x30, gUnk_03002C30[48].unk2B * 4 + gUnk_03002C30[48].unk20);
        }
        update_battle_entity_status_chars();
        gGameSubState = 5;
    }
}

static void nullsub_0804AE2C(void) {}

static void nullsub_0804AE30(void) {}

void sub_0804AE34(void) {
    gUnk_030057E0.unkC5C = 0xC;
    load_battle_palette_via_dma(0);
    dispatch_jump_table_29(9, 0);
    init_sprite_affine_matrices_and_state(0xE, gUnk_030057E0.unkC52, gUnk_030057E0.unkC54, 0);
    sub_0804A1C4();
}

void sub_0804AE7C(void) {
    if (sub_0804B694()) {
        gUnk_030057E0.unkC5C = gUnk_030057E0.unkC69;
        load_battle_palette_via_dma(0);
        gUnk_030057E0.unkC67 = 1;
        gUnk_03005310.unk1 = 0;
        init_battle_field_setup();
        update_bg_scroll_offsets_a();
        field_set_player_facing(gUnk_030057E0.unkC67);
        if (gUnk_030057E0.unkC76) {
            gUnk_030057E0.unkC6E = gUnk_030057E0.unkC52;
            gUnk_030057E0.unkC70 = gUnk_030057E0.unkC54;
            set_battle_state_byte_c83(gUnk_03002C30[47].unk20);
            sub_080493D4(0x30, gUnk_03002C30[48].unk2B * 4 + gUnk_03002C30[48].unk20);
        }
        update_battle_entity_status_chars();
        gGameSubState = 5;
    }
}

static void nullsub_0804AF40(void) {}

static void nullsub_0804AF44(void) {}

static void nullsub_0804AF48(void) {}

void sub_0804AF4C(void) {
    struct Unk_030057A0 *s = &gUnk_030057A0;

    if (s->unk11 == 0) {
        s->unk10 = 1;
        sub_08058110(0);
    }
    sub_0804A1C4();
}

void sub_0804AF6C(void) {
    sub_08058214(gUnk_030057A0.unk14);
}

void sub_0804AF80(void) {
    if (sub_0805937C())
        handle_battle_end_state_transition();
}

void sub_0804AF94(void) {
    setup_palette_fade_to_color_with_obj(0x7FFF, 0.0f, 32.0f, 8.0f);
    sub_0804A1C4();
}

void sub_0804AFBC(void) {
    s32 x, y;

    if (run_blend_fade_transition(0x7FFF)) {
        gMapScriptData = (u8 *)gUnk_08764CB0;
        if (gUnk_030057A0.unk14 == 0)
            gUnk_030057E0.unk7FE = gUnk_030057A0.unk26;
        field_load_area_tiles(gUnk_030057E0.unk7FE);
        x = sub_080526F0(gUnk_030057E0.unkC52);
        y = sub_08052714(gUnk_030057E0.unkC54);
        if (gUnk_030057E0.unkC56 >= sub_08052960(gUnk_030057E0.unk7FE, 0) / 2)
            x = sub_08052960(gUnk_030057E0.unk7FE, 0) / 2 - 1;
        if (gUnk_030057E0.unkC57 >= sub_08052960(gUnk_030057E0.unk7FE, 1) / 2)
            y = sub_08052960(gUnk_030057E0.unk7FE, 1) / 2 - 1;
        gUnk_030057E0.unkC52 = (x << 4) + gUnk_030057E0.unkC48;
        gUnk_030057E0.unkC54 = (y << 4) + gUnk_030057E0.unkC4A;
        gUnk_030057E0.unkC56 = sub_080526F0(gUnk_030057E0.unkC52);
        gUnk_030057E0.unkC57 = sub_08052714(gUnk_030057E0.unkC54);
        field_center_camera_on_player();
        gUnk_030057E0.unkC28 = gUnk_030057E0.unkC5C;
        load_battle_terrain_data();
        REG_DISPCNT = 0x1E40;
        sub_0804B1FC();
        gUnk_030057E0.unkCBA = 0;
        gGameSubState = 1;
    }
}

void nullsub_0804B110(void) {}

static void sub_0804B114(void) {
    const struct AreaWarp *w = gUnk_08413114[gUnk_030057E0.unk7FE];
    s32 i;

    for (i = 0; w[i].x != 0xFF; i++)
        gUnk_030057E0.unk810[w[i].y * (gUnk_030057E0.unk800 >> 1) + w[i].x] = 2;
}

void update_battle_entity_status_chars(void) {
    s32 i;

    if (gUnk_030057E0.unkC4C) {
        for (i = 0x2E; i <= 0x7F; i++) {
            if (gUnk_03002C30[i].unkB == 0xFF)
                gUnk_03002C30[i].unkB = 0xFF;
            else if (gUnk_03002C30[i].unkB != 0)
                gUnk_03002C30[i].unkB = (gUnk_03002C30[i].unk4 + 0x10) / 4 + 0x40;
            else
                gUnk_03002C30[i].unkB = 0;
            if (i == 0x30 && gUnk_030057E0.unkC70 == gUnk_030057E0.unkC54)
                gUnk_03002C30[48].unkB = gUnk_03002C30[47].unkB - 1;
            if (i == 0x59 && gUnk_030057E0.unkC70 == gUnk_030057E0.unkC54)
                gUnk_03002C30[0x59].unkB = gUnk_03002C30[48].unkB - 1;
        }
    }
}

void sub_0804B1FC(void) {
    vu32 zero;

    zero = 0;
    DmaSet(3, &zero, VRAM + 0x1000, 0x85000800);
}

static void sub_0804B224(void) {
    vu32 zero;

    zero = 0;
    DmaSet(3, &zero, VRAM + 0x2800, 0x85001A00);
}

static void clear_vram_bg2_tiles(void) {
    sub_080496DC((u8 *)(VRAM + 0x3000), 0x6000, 0x80);
}

// gUnk_083F92F4 indexed as a flat pointer array (three LZ77 tilemaps per area: unk0, unk4, unk8);
// the index has to reach the load unfolded ((area * 3 + 1) << 2), hence the helper.
static inline const void *area_gfx(const void *const *t, u32 i) {
    return t[i];
}

// Sets BG1-3 control, loads the area's tile map and its three BG layers (or blank tiles and a fill
// when the area has no layer graphics), then centres the camera.
void load_room_graphics(void) {
    const void *const *tbl;
    REG_BG1CNT = 0xC609;
    REG_BG2CNT = 0xEA0A;
    REG_BG3CNT = 0xEE0B;
    field_load_area_tiles(gUnk_030057E0.unk7FE);
    gUnk_030057E0.unk800 = sub_08052960(gUnk_030057E0.unk7FE, 0);
    gUnk_030057E0.unk802 = sub_08052960(gUnk_030057E0.unk7FE, 1);
    gUnk_030057E0.unk804 = sub_08052990(gUnk_030057E0.unk7FE, 0);
    gUnk_030057E0.unk806 = sub_08052990(gUnk_030057E0.unk7FE, 1);
    clear_vram_bg2_tiles();
    sub_080496C8(gUnk_030057E0.unk810, 0x400);
    memcpy_u8(gUnk_084045A8[gUnk_030057E0.unk7FE], gUnk_030057E0.unk810,
              (gUnk_030057E0.unk802 >> 1) * (gUnk_030057E0.unk800 >> 1));
    tbl = (const void *const *)gUnk_083F92F4;
    if (area_gfx(tbl, gUnk_030057E0.unk7FE * 3) != NULL && gUnk_083F8CF4[gUnk_030057E0.unk7FE] != NULL) {
        LZ77UnCompVram(gUnk_083F8CF4[gUnk_030057E0.unk7FE], (void *)0x06009000);
        LZ77UnCompVram(area_gfx(tbl, gUnk_030057E0.unk7FE * 3), gUnk_03006D14);
        copy_tilemap_with_offset_08048CA4(gUnk_03006D14 + 8, (void *)0x06003000, gUnk_030057E0.unk806,
                                          gUnk_030057E0.unk804, 0x40, 0x40, 0x80);
        LZ77UnCompVram(area_gfx(tbl, gUnk_030057E0.unk7FE * 3 + 1), gUnk_03006D14);
        copy_tilemap_with_offset_08048CA4(gUnk_03006D14 + 8, (void *)0x06005000, gUnk_030057E0.unk806,
                                          gUnk_030057E0.unk804, 0x40, 0x40, 0x80);
        LZ77UnCompVram(area_gfx(tbl, gUnk_030057E0.unk7FE * 3 + 2), gUnk_03006D14);
        copy_tilemap_with_offset_08048CA4(gUnk_03006D14 + 8, (void *)0x06007000, gUnk_030057E0.unk806,
                                          gUnk_030057E0.unk804, 0x40, 0x40, 0x80);
        if (gUnk_083F8FF4[gUnk_030057E0.unk7FE] != NULL)
            LZ77UnCompVram(gUnk_083F8FF4[gUnk_030057E0.unk7FE], gUnk_030057DC);
    } else {
        sub_080496C8((u8 *)0x06009000, 0x80);
        DmaSet(3, gUnk_080AC5D4, 0x06009080, 0x80000040);
        DmaSet(3, gUnk_080AC674, 0x06009100, 0x80000040);
        DmaSet(3, gUnk_080AC714, 0x06009180, 0x80000040);
        DmaSet(3, gUnk_080AC7B4, 0x06009200, 0x80000040);
        DmaSet(3, gUnk_080AC5D4, 0x06009280, 0x80000040);
        DmaSet(3, gUnk_080AC5D4, 0x06009300, 0x80000040);
        DmaSet(3, gUnk_080AC5D4, 0x06009380, 0x80000040);
        DmaSet(3, gUnk_080AC854, 0x06009400, 0x80000040);
        DmaSet(3, gUnk_080AC8F4, 0x06009480, 0x80000040);
        sub_080496DC((u8 *)gUnk_03006D14, gUnk_030057E0.unk802 * gUnk_030057E0.unk800, 8);
        copy_tiles_to_bg_tilemap(gUnk_03006D14, (void *)0x06003000, gUnk_030057E0.unk802, gUnk_030057E0.unk800, 0x40,
                                 0x40, gUnk_030057E0.unkC4A / 8, gUnk_030057E0.unkC48 / 8, 0x80);
        copy_tiles_to_bg_tilemap(gUnk_03006D14, (void *)0x06005000, gUnk_030057E0.unk802, gUnk_030057E0.unk800, 0x40,
                                 0x40, gUnk_030057E0.unkC4A / 8, gUnk_030057E0.unkC48 / 8, 0x80);
        copy_tiles_to_bg_tilemap(gUnk_030057E0.unk810, (void *)0x06007000, gUnk_030057E0.unk802, gUnk_030057E0.unk800,
                                 0x40, 0x40, gUnk_030057E0.unkC4A / 8, gUnk_030057E0.unkC48 / 8, 0x80);
    }
    field_center_camera_on_player();
    check_and_update_battlefield_palette();
}

static void update_blend_effect_from_input(void) {
    if (KEYS_LO(gNewKeys) & 0x40) {
        gUnk_03006F40.unk14 += 1.0f;
        gUnk_03006F40.unk14 = (s32)((u32)gUnk_03006F40.unk14 & 0xF);
        REG_BLDY = (u32)gUnk_03006F40.unk14 % 64;
    }
    if (KEYS_HI(gNewKeys) & 1) {
        gUnk_03006F40.unkC += 1.0f;
        gUnk_03006F40.unkC = (s32)((u32)gUnk_03006F40.unkC & 0xF);
        REG_BLDALPHA = (((u32)gUnk_03006F40.unk10 & 0x3F) << 8) | ((u32)gUnk_03006F40.unkC & 0x3F);
    }
    if (KEYS_HI(gNewKeys) & 2) {
        gUnk_03006F40.unk10 += 1.0f;
        gUnk_03006F40.unk10 = (s32)((u32)gUnk_03006F40.unk10 & 0xF);
        REG_BLDALPHA = (((u32)gUnk_03006F40.unk10 & 0x3F) << 8) | ((u32)gUnk_03006F40.unkC & 0x3F);
    }
}

static u32 sub_0804B694(void) {
    if (battle_sequence_dispatch() == 4)
        return 1;
    return 0;
}
