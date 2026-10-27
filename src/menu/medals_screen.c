// Game state 4: the Medals screen (Medawatch > Medals): the Medal list, a Medal's pages (Ability, Medaforce,
// Rotation, Skill), the START help, and the drawing helpers for Medal sprites, names, levels and skill bars.

#include "global.h"

static void medals_scroll_bg(void);
static void medals_list_set_cursor_from_medal(void);
static void count_owned_medals(void);
static void render_medal_sprite_tile(void);
static void render_medal_list_entries(void);
static void render_medal_slots_in_menu(void);
static void render_medal_name_display(void);
static void medals_list_init_tab_arrows(void);
static void medals_list_init_cursor(void);
static void medals_list_blink_tab_arrows(void);
static void medals_list_row_input(void);
static void medals_list_tab_input(void);
static void update_battle_sprite_visibility(void);
static void medals_list_swap_input(void);
static void decompress_active_medal_sprite(void);
static void init_active_medal_battle_sprites(void);
static void draw_medal_position_tile(void);
static void medal_page_draw_icon(void);
static void medal_skill_draw_icon(void);
static void medal_page_draw_kind_name(void);
static void medal_page_draw_name(void);
static void medal_page_draw_level(void);
static void medal_skill_draw_level(void);
static void medal_ability_draw_attribute(void);
static void medal_ability_draw_aim(void);
static void medal_ability_draw_compatibility(void);
static void medal_page_init_medal_arrows(void);
static void medal_page_blink_medal_arrows(void);
static void medal_page_cycle_medal_input(void);
static void medal_ability_redraw(void);
static void medal_medaforce_draw_list(void);
static void medal_medaforce_draw_selected(void);
static void medal_medaforce_init_cursor(void);
static u32 medal_medaforce_cursor_input(void);
static u32 medal_medaforce_redraw(void);
// guess: moves the Medals help cursor sprite to entry unk44
static void sub_0800AAC0(void);
// guess: Rotation page frame tilemap for unk9 entries
static void sub_0800ABA4(void);
static void medal_rotation_redraw(void);
// guess: Rotation edit arrows above/below slot unk46
static void sub_0800AC2C(void);
// guess: Rotation page end marker sprite at entry unk9
static void sub_0800ACA8(void);
// guess: blinks the Rotation edit arrows
static void sub_0800AD00(void);
// guess: UP/DOWN cycles Rotation entry unk46 (0-7), returns 1 on change
static u32 sub_0800AD58(void);
// guess: LEFT/RIGHT moves the Rotation slot cursor unk46 (0-7)
static u32 sub_0800ADE8(void);
// guess: LEFT/RIGHT changes the Rotation entry count (Medal unk9, 0-7)
static u32 sub_0800AE54(void);
// guess: loads the parts graphics of the Medabot holding the Medal
static void sub_0800AED0(void);
// guess: shows the Medabot holding the Medal (sprites 0x64..)
static void sub_0800AF0C(void);
// guess: draws the legs type of the Medabot holding the Medal
static void sub_0800AF64(void);
// guess: animates that strip, a frame every 2 ticks after 180 ticks
static void sub_0800B130(void);
static void medal_skill_redraw(void);
static void init_battle_cursor_sprite_0800B668(void);
static void handle_menu_cursor_updown(void);

// Game state 4: the Medals screen (runtime-checked from Medawatch > Medals). Sub-states 0-5 = Medal
// list (unk3F tab, unk40 row); A opens a Medal's pages, L/R cycle unk42: 8.. Ability, 24.. Medaforce,
// 40.. Rotation, 56.. Skill. START = help (0x48..).
void medals_screen_update(void) {
    if (link_error_check() == 0)
        gMedalsScreenHandlers[gGameSubState]();
}

void medals_list_load_gfx(void) {
    u32 zero;

    REG_DISPCNT &= 0xF0FF;
    REG_BG0CNT = 0x500;
    REG_BG1CNT = 0x1801;
    REG_BG2CNT = 0x1902;
    REG_BG3CNT = 0x1A03;
    lz_decompress_dispatch(gUnk_084E7264, (void *)0x06004000);
    lz_decompress_dispatch(gUnk_084C32DC, (void *)0x06006000);
    lz_decompress_dispatch(gUnk_084C3208, (void *)0x06006280);
    lz_decompress_dispatch(gUnk_084C48B4, (void *)0x06007400);
    lz_decompress_dispatch(gUnk_084C4A34, (void *)0x06007600);
    lz_decompress_dispatch(gUnk_084C6A98, (void *)0x06017400);
    lz_decompress_dispatch(gUnk_084C7318, (void *)0x06017E00);
    lz_decompress_dispatch(gUnk_0848833C, (void *)0x06006A00);
    set_tilemap_and_decompress_bg(0, 0, gUnk_084EF348, REG_BG0CNT, 0x200);
    set_tilemap_and_decompress_bg(0, 0, gUnk_084EFB5C, REG_BG1CNT, 0x200);
    set_tilemap_and_decompress_bg(0, 0, gUnk_084F04F0, REG_BG2CNT, 0x200);
    set_tilemap_and_decompress_bg(0, 0, gUnk_084F1554, REG_BG3CNT, 0x200);
    CpuFastSet(gUnk_084F2BA0, (void *)0x05000000, 0x70);
    CpuFastSet(gUnk_08488B44, (void *)0x05000160, 8);
    CpuFastSet(gUnk_0850DEF8, (void *)0x05000200, 0x40);
    CpuFastSet(gUnk_0850DD58, (void *)0x05000300, 8);
    CpuFastSet(gUnk_0850DD58 - 0x20, (void *)0x05000320, 8);
    CpuFastSet(gUnk_084E2E98, (void *)0x050003A0, 8);
    CpuFastSet(gUnk_0850DD58 + 0x60, (void *)0x05000340, 8);
    CpuFastSet(gUnk_084E2E58, (void *)0x050003C0, 8);
    zero = 0;
    CpuFastSet(&zero, gSpriteEntries, 0x01000800);
    REG_DISPCNT |= 0x1F60;
    medals_list_set_cursor_from_medal();
    write_tilemap_rect(10, 2, 5, 2, gUnk_083B4AE0[gUnk_03000440.unk3F + 0x4B], REG_BG1CNT, 0x200);
    render_medal_sprite_tile();
    render_medal_list_entries();
    render_medal_slots_in_menu();
    render_medal_name_display();
    load_medal_sprite();
    render_medal_level_display();
    medals_list_init_tab_arrows();
    medals_list_init_cursor();
    count_owned_medals();
    decompress_active_medal_sprite();
    init_active_medal_battle_sprites();
    draw_medal_position_tile();
    set_blend_effect_mode(5, 0x3F, 0x20);
    if (gUnk_03000440.unk3C == 4 && gUnk_03000440.unk4B == 0) {
        gUnk_03000440.unk4B = 1;
        play_song(7);
    }
    gUnk_03000440.unk84 = 0;
    gGameSubState++;
}

void medals_list_fade_in(void) {
    medals_scroll_bg();
    medals_list_blink_tab_arrows();
    sprite_bob_y(3, gFrameCounter, 0x18);
    if (update_blend_effect())
        gGameSubState++;
}

void medals_list_handle_input(void) {
    u8 b;

    medals_scroll_bg();
    medals_list_blink_tab_arrows();
    sprite_bob_y(3, gFrameCounter, 0x18);
    update_battle_sprite_visibility();
    medals_list_row_input();
    medals_list_tab_input();
    medals_list_swap_input();
    if ((b = KEYS_LO(gNewKeys) & 2)) {
        if (gUnk_03000440.unk3E & 0x80) {
            play_sound_effect(2);
            gUnk_03000440.unk3E = 0;
            update_battle_sprite_visibility();
        } else {
            play_sound_effect(5);
            gGameSubState++;
        }
    } else if (KEYS_LO(gNewKeys) & 1) {
        gUnk_03000440.unk3D = gUnk_03000440.unk3F * 6 + gUnk_03000440.unk40;
        if (gUnk_03000BE0[gUnk_03000440.unk3D].unk0 & 0x80) {
            play_sound_effect(4);
            if (gUnk_03000440.unk3C == 4)
                gGameSubState = 0x60;
            else {
                gUnk_03000440.unk42 = b;
                set_blend_effect_mode(6, 0x3F, 0x20);
                gGameSubState = 7;
            }
        } else {
            play_sound_effect(6);
        }
    }
}

void medals_list_start_fade_out(void) {
    set_blend_effect_mode(6, 0x3F, 0x20);
    medals_scroll_bg();
    medals_list_blink_tab_arrows();
    sprite_bob_y(3, gFrameCounter, 0x18);
    gGameSubState++;
}

void medals_list_wait_fade(void) {
    medals_scroll_bg();
    medals_list_blink_tab_arrows();
    sprite_bob_y(3, gFrameCounter, 0x18);
    if (update_blend_effect())
        gGameSubState++;
}

void medals_list_exit(void) {
    clear_battle_sprite_slot(0, 0x80);
    if (gUnk_03000440.unk3C == 4)
        goto_link_scene(0);
    else {
        gGameState = 2;
        gGameSubState = 0x10;
    }
}

void medal_ability_load_gfx(void) {
    u32 zero;

    REG_DISPCNT &= 0xF0FF;
    REG_BG0CNT = 0x500;
    REG_BG1CNT = 0x1801;
    REG_BG2CNT = 0x1902;
    REG_BG3CNT = 0x1A03;
    lz_decompress_dispatch(gUnk_084E80B0, (void *)0x06004000);
    lz_decompress_dispatch(gUnk_084C3208, (void *)0x06006280);
    lz_decompress_dispatch(gUnk_084C33DC, (void *)0x06006800);
    lz_decompress_dispatch(gUnk_084C7318, (void *)0x06017E00);
    set_tilemap_and_decompress_bg(0, 0, gUnk_084EF380, REG_BG0CNT, 0x200);
    set_tilemap_and_decompress_bg(0, 0, gUnk_084EFBE0, REG_BG1CNT, 0x200);
    set_tilemap_and_decompress_bg(0, 0, gUnk_084F0688, REG_BG2CNT, 0x200);
    set_tilemap_and_decompress_bg(0, 0, gUnk_084F16E8, REG_BG3CNT, 0x200);
    CpuFastSet(gUnk_084F2D60, (void *)0x05000000, 0x70);
    CpuFastSet(gUnk_0850DD58 + 0x70, (void *)0x05000340, 8);
    CpuFastSet(gUnk_0850DD58 + 0x40, (void *)0x05000360, 8);
    CpuFastSet(gUnk_0850DD58 - 0x20, (void *)0x05000380, 8);
    CpuFastSet(gUnk_0850DD58 - 0x10, (void *)0x050003A0, 8);
    CpuFastSet(gUnk_084E2E58, (void *)0x050003C0, 8);
    zero = 0;
    CpuFastSet(&zero, gSpriteEntries, 0x01000800);
    REG_DISPCNT |= 0x1F60;
    gUnk_03000440.unk44 = 0;
    medal_page_draw_icon();
    medal_page_draw_kind_name();
    medal_page_draw_name();
    medal_page_draw_level();
    medal_ability_draw_attribute();
    medal_ability_draw_aim();
    medal_ability_draw_compatibility();
    medal_page_init_medal_arrows();
    set_blend_effect_mode(5, 0x3F, 0x20);
    gUnk_03000440.unk84 = 0;
    gGameSubState++;
}

void medal_page_wait_fade(void) {
    medals_scroll_bg();
    medal_page_blink_medal_arrows();
    if (update_blend_effect())
        gGameSubState++;
}

void medal_page_open_text_window(void) {
    medals_scroll_bg();
    medal_page_blink_medal_arrows();
    text_window_init(1, 2, 0);
    gGameSubState++;
}

void medal_ability_show_hint(void) {
    medals_scroll_bg();
    medal_page_blink_medal_arrows();
    if (run_message(gUnk_083B53F8[4]))
        gGameSubState++;
}

void medal_ability_handle_input(void) {
    medals_scroll_bg();
    medal_page_blink_medal_arrows();
    medal_page_cycle_medal_input();
    medal_ability_redraw();
    if (KEYS_LO(gNewKeys) & 2) {
        play_sound_effect(5);
        gGameSubState++;
    } else if (*((u8 *)&gNewKeys + 1) & 2) {
        play_sound_effect(2);
        gUnk_03000440.unk42 = (gUnk_03000440.unk42 - 1) & 3;
        gGameSubState = 0x14;
    } else if (*((u8 *)&gNewKeys + 1) & 1) {
        play_sound_effect(2);
        gUnk_03000440.unk42 = (gUnk_03000440.unk42 + 1) & 3;
        gGameSubState = 0x14;
    } else if (KEYS_LO(gNewKeys) & 8) {
        play_sound_effect(4);
        gUnk_03000440.unk43 = 0;
        gGameSubState = 0x48;
    }
}

void medal_page_start_fade_out(void) {
    set_blend_effect_mode(6, 0x3F, 0x20);
    medals_scroll_bg();
    medal_page_blink_medal_arrows();
    gGameSubState++;
}

void medal_page_exit(void) {
    u32 zero;
    u32 zero2;

    clear_battle_sprite_slot(0, 0x80);
    switch (gUnk_03000440.unk3C) {
    case 1:
        gUnk_03000440.unk97 = gUnk_03000440.unk3D;
        gGameState = 3;
        gGameSubState = 0x10;
        break;
    case 2:
        sub_0800B498();
        zero = 0;
        CpuFastSet(&zero, (void *)0x05000200, 0x01000080);
        zero2 = 0;
        CpuFastSet(&zero2, (void *)0x05000000, 0x01000080);
        gGameState = 7;
        gGameSubState = 0x3C;
        break;
    case 0:
    case 3:
    case 4:
        gGameSubState = 0;
        break;
    }
}

void medal_page_switch(void) {
    clear_battle_sprite_slot(0, 0x80);
    switch (gUnk_03000440.unk42) {
    case 0:
        gGameSubState = 8;
        break;
    case 1:
        gGameSubState = 0x18;
        break;
    case 2:
        gGameSubState = 0x28;
        break;
    default:
        gGameSubState = 0x38;
        break;
    }
}

void medal_medaforce_load_gfx(void) {
    u32 zero;

    REG_DISPCNT &= 0xF0FF;
    REG_BG0CNT = 0x500;
    REG_BG1CNT = 0x1801;
    REG_BG2CNT = 0x1902;
    REG_BG3CNT = 0x1A03;
    lz_decompress_dispatch(gUnk_084E9020, (void *)0x06004000);
    lz_decompress_dispatch(gUnk_084C3208, (void *)0x06006280);
    lz_decompress_dispatch(gUnk_084C3524, (void *)0x06006000);
    lz_decompress_dispatch(gUnk_084C3648, (void *)0x06006680);
    lz_decompress_dispatch(gUnk_084C7318, (void *)0x06017E00);
    set_tilemap_and_decompress_bg(0, 0, gUnk_084EF3F4, REG_BG0CNT, 0x200);
    set_tilemap_and_decompress_bg(0, 0, gUnk_084EFCDC, REG_BG1CNT, 0x200);
    set_tilemap_and_decompress_bg(0, 0, gUnk_084F07B8, REG_BG2CNT, 0x200);
    set_tilemap_and_decompress_bg(0, 0, gUnk_084F187C, REG_BG3CNT, 0x200);
    CpuFastSet(gUnk_084F2F20, (void *)0x05000000, 0x70);
    CpuFastSet(gUnk_0850DD58 + 0x30, (void *)0x05000340, 8);
    CpuFastSet(gUnk_0850DD58 + 0x40, (void *)0x05000360, 8);
    CpuFastSet(gUnk_0850DD58 - 0x20, (void *)0x05000380, 8);
    CpuFastSet(gUnk_0850DD58 - 0x10, (void *)0x050003A0, 8);
    CpuFastSet(gUnk_084E2E58, (void *)0x050003C0, 8);
    zero = 0;
    CpuFastSet(&zero, gSpriteEntries, 0x01000800);
    REG_DISPCNT |= 0x1F60;
    gUnk_03000440.unk44 = 0;
    gUnk_03000440.unk46 = 0;
    medal_page_draw_icon();
    medal_page_draw_kind_name();
    medal_page_draw_name();
    medal_page_draw_level();
    medal_page_init_medal_arrows();
    medal_medaforce_draw_list();
    medal_medaforce_draw_selected();
    medal_medaforce_init_cursor();
    set_blend_effect_mode(5, 0x3F, 0x20);
    gUnk_03000440.unk84 = 0;
    gGameSubState++;
}

void medal_medaforce_wait_fade(void) {
    medals_scroll_bg();
    medal_page_blink_medal_arrows();
    sprite_bob_y(3, gFrameCounter, 8);
    if (update_blend_effect())
        gGameSubState++;
}

void medal_medaforce_open_text_window(void) {
    medals_scroll_bg();
    medal_page_blink_medal_arrows();
    sprite_bob_y(3, gFrameCounter, 8);
    text_window_init(1, 2, 0);
    gGameSubState++;
}

void medal_medaforce_show_message(void) {
    medals_scroll_bg();
    medal_page_blink_medal_arrows();
    sprite_bob_y(3, gFrameCounter, 8);
    if (run_message(gUnk_083B7C00[medal_medaforce_get_selected()]))
        gGameSubState++;
}

void medal_medaforce_handle_input(void) {
    medals_scroll_bg();
    medal_page_blink_medal_arrows();
    sprite_bob_y(3, gFrameCounter, 8);
    if (medal_medaforce_cursor_input()) {
        sub_0803FB0C();
        gGameSubState++;
        return;
    }
    medal_page_cycle_medal_input();
    if (medal_medaforce_redraw()) {
        sub_0803FB0C();
        gGameSubState++;
    } else if (KEYS_LO(gNewKeys) & 2) {
        play_sound_effect(5);
        gGameSubState = 0x1E;
    } else if (*((u8 *)&gNewKeys + 1) & 2) {
        play_sound_effect(2);
        gUnk_03000440.unk42 = (gUnk_03000440.unk42 - 1) & 3;
        gGameSubState = 0x24;
    } else if (*((u8 *)&gNewKeys + 1) & 1) {
        play_sound_effect(2);
        gUnk_03000440.unk42 = (gUnk_03000440.unk42 + 1) & 3;
        gGameSubState = 0x24;
    } else if (KEYS_LO(gNewKeys) & 8) {
        play_sound_effect(4);
        gUnk_03000440.unk43 = 1;
        gGameSubState = 0x48;
    }
}

void medal_medaforce_show_message_back(void) {
    medals_scroll_bg();
    medal_page_blink_medal_arrows();
    sprite_bob_y(3, gFrameCounter, 8);
    if (run_message(gUnk_083B7C00[medal_medaforce_get_selected()]))
        gGameSubState--;
}

void medal_medaforce_start_fade_out(void) {
    set_blend_effect_mode(6, 0x3F, 0x20);
    medals_scroll_bg();
    medal_page_blink_medal_arrows();
    sprite_bob_y(3, gFrameCounter, 8);
    gGameSubState++;
}

void medal_rotation_load_gfx(void) {
    u32 zero;

    REG_DISPCNT &= 0xF0FF;
    REG_BG0CNT = 0x500;
    REG_BG1CNT = 0x1801;
    REG_BG2CNT = 0x1902;
    REG_BG3CNT = 0x1A03;
    lz_decompress_dispatch(gUnk_084E9E68, (void *)0x06004000);
    lz_decompress_dispatch(gUnk_084C3208, (void *)0x06006280);
    lz_decompress_dispatch(gUnk_084C37A4, (void *)0x06006800);
    lz_decompress_dispatch(gUnk_084C3990, (void *)0x06006C00);
    lz_decompress_dispatch(gUnk_084C48B4, (void *)0x06007400);
    lz_decompress_dispatch(gUnk_084C4A34, (void *)0x06007600);
    lz_decompress_dispatch(gUnk_084C7318, (void *)0x06017E00);
    set_tilemap_and_decompress_bg(0, 0, gUnk_084EF46C, REG_BG0CNT, 0x200);
    set_tilemap_and_decompress_bg(0, 0, gUnk_084EFD74, REG_BG1CNT, 0x200);
    set_tilemap_and_decompress_bg(0, 0, gUnk_084F08F0, REG_BG2CNT, 0x200);
    set_tilemap_and_decompress_bg(0, 0, gUnk_084F1A10, REG_BG3CNT, 0x200);
    CpuFastSet(gUnk_084F30E0, (void *)0x05000000, 0x70);
    CpuFastSet(gUnk_0850DEF8, (void *)0x05000200, 0x40);
    CpuFastSet(gUnk_0850DD18, (void *)0x05000380, 8);
    CpuFastSet(gUnk_0850DD18 + 0x10, (void *)0x050003A0, 8);
    CpuFastSet(gUnk_084E2E58, (void *)0x050003C0, 8);
    zero = 0;
    CpuFastSet(&zero, gSpriteEntries, 0x01000800);
    REG_DISPCNT |= 0x1F60;
    gUnk_03000440.unk44 = 0;
    gUnk_03000440.unk46 = 0;
    medal_page_draw_icon();
    medal_page_draw_kind_name();
    medal_page_draw_name();
    medal_page_draw_level();
    medal_page_init_medal_arrows();
    sub_0800AB0C();
    sub_0800ABA4();
    sub_0800AED0();
    sub_0800AF0C();
    sub_0800AF64();
    set_blend_effect_mode(5, 0x3F, 0x20);
    gUnk_03000440.unk84 = 0;
    gGameSubState++;
}

void medal_rotation_wait_fade(void) {
    medals_scroll_bg();
    medal_page_blink_medal_arrows();
    if (update_blend_effect())
        gGameSubState++;
}

void medal_rotation_open_text_window(void) {
    medals_scroll_bg();
    medal_page_blink_medal_arrows();
    text_window_init(1, 2, 0);
    gGameSubState++;
}

void medal_rotation_show_hint(void) {
    medals_scroll_bg();
    medal_page_blink_medal_arrows();
    if (run_message(gUnk_083B53F8[12]))
        gGameSubState++;
}

void medal_rotation_handle_input(void) {
    medals_scroll_bg();
    medal_page_blink_medal_arrows();
    medal_page_cycle_medal_input();
    medal_rotation_redraw();
    if (KEYS_LO(gNewKeys) & 1) {
        play_sound_effect(4);
        clear_sprite_table_mask(1, 2);
        gUnk_03000440.unk46 = 0;
        gUnk_03000440.unk3F = 0;
        gGameSubState = 0x30;
    } else if (KEYS_LO(gNewKeys) & 2) {
        play_sound_effect(5);
        gGameSubState++;
    } else if (*((u8 *)&gNewKeys + 1) & 2) {
        play_sound_effect(2);
        gUnk_03000440.unk42 = (gUnk_03000440.unk42 - 1) & 3;
        gGameSubState = 0x34;
    } else if (*((u8 *)&gNewKeys + 1) & 1) {
        play_sound_effect(2);
        gUnk_03000440.unk42 = (gUnk_03000440.unk42 + 1) & 3;
        gGameSubState = 0x34;
    } else if (KEYS_LO(gNewKeys) & 8) {
        play_sound_effect(4);
        gUnk_03000440.unk43 = 2;
        gGameSubState = 0x48;
    }
}

void medal_rotation_start_fade_out(void) {
    set_blend_effect_mode(6, 0x3F, 0x20);
    medals_scroll_bg();
    medal_page_blink_medal_arrows();
    gGameSubState++;
}

void medal_rotation_edit_init(void) {
    medals_scroll_bg();
    if (gUnk_03000440.unk3F == 0)
        sub_0800AC2C();
    else
        sub_0800ACA8();
    sub_0803FB0C();
    gGameSubState++;
}

void medal_rotation_edit_show_message(void) {
    const void *msg;

    medals_scroll_bg();
    if (gUnk_03000440.unk3F == 0) {
        sub_0800AD00();
        msg = gUnk_083B825C[gUnk_03000BE0[gUnk_03000440.unk3D].unk18[gUnk_03000440.unk46]];
    } else {
        msg = gUnk_083B53F8[15];
    }
    if (run_message(msg))
        gGameSubState++;
}

void medal_rotation_edit_input(void) {
    medals_scroll_bg();
    if (gUnk_03000440.unk3F == 0) {
        sub_0800AD00();
        if (sub_0800AD58()) {
            sub_0800AB0C();
            sub_0803FB0C();
            gGameSubState--;
            return;
        }
        if (sub_0800ADE8()) {
            sub_0803FB0C();
            gGameSubState--;
            return;
        }
        if (KEYS_LO(gNewKeys) & 1) {
            play_sound_effect(4);
            clear_sprite_table_mask(1, 2);
            sub_0800ACA8();
            sub_0803FB0C();
            gUnk_03000440.unk3F = 1;
            gGameSubState--;
            return;
        }
        if (KEYS_LO(gNewKeys) & 2) {
            play_sound_effect(5);
            clear_sprite_table_mask(1, 2);
            gUnk_03000440.unk46 = 0;
            medal_page_init_medal_arrows();
            sub_0803FB0C();
            gGameSubState = 0x2B;
            return;
        }
    } else {
        sprite_bob_x(3, gFrameCounter, 0x30);
        if (sub_0800AE54()) {
            sub_0800AB0C();
            sub_0800ABA4();
            sub_0800ACA8();
            return;
        }
        if (KEYS_LO(gNewKeys) & 1) {
            play_sound_effect(4);
            clear_sprite_table_mask(3, 1);
            gUnk_03000440.unk46 = 0;
            medal_page_init_medal_arrows();
            sub_0803FB0C();
            gGameSubState = 0x2B;
            return;
        }
        if (KEYS_LO(gNewKeys) & 2) {
            play_sound_effect(5);
            clear_sprite_table_mask(3, 1);
            sub_0800AC2C();
            sub_0803FB0C();
            gUnk_03000440.unk3F = 0;
            gGameSubState--;
            return;
        }
    }
    if (KEYS_LO(gNewKeys) & 8) {
        play_sound_effect(4);
        gUnk_03000440.unk46 |= 0x80;
        gUnk_03000440.unk43 = 2;
        gGameSubState = 0x48;
    }
}

void medal_skill_load_gfx(void) {
    u32 zero;

    REG_DISPCNT &= 0xF0FF;
    REG_BG0CNT = 0x500;
    REG_BG1CNT = 0x1801;
    REG_BG2CNT = 0x1902;
    REG_BG3CNT = 0x1A03;
    lz_decompress_dispatch(gUnk_084EAC58, (void *)0x06004000);
    lz_decompress_dispatch(gUnk_084C3208, (void *)0x06007480);
    lz_decompress_dispatch(gUnk_084C3648, (void *)0x06007880);
    lz_decompress_dispatch(gUnk_084C7318, (void *)0x06017E00);
    set_tilemap_and_decompress_bg(0, 0, gUnk_084EF4E0, REG_BG0CNT, 0x200);
    set_tilemap_and_decompress_bg(0, 0, gUnk_084EFE28, REG_BG1CNT, 0x200);
    set_tilemap_and_decompress_bg(0, 0, gUnk_084F0A00, REG_BG2CNT, 0x200);
    set_tilemap_and_decompress_bg(0, 0, gUnk_084F1BA0, REG_BG3CNT, 0x200);
    CpuFastSet(gUnk_084F32A0, (void *)0x05000000, 0x70);
    CpuFastSet(gUnk_0850DD18, (void *)0x05000380, 8);
    CpuFastSet(gUnk_0850DD18 + 0x10, (void *)0x050003A0, 8);
    CpuFastSet(gUnk_084E2E58, (void *)0x050003C0, 8);
    zero = 0;
    CpuFastSet(&zero, gSpriteEntries, 0x01000800);
    REG_DISPCNT |= 0x1F60;
    gUnk_03000440.unk48 = 0;
    gUnk_03000440.unk3F = 0;
    medal_skill_draw_icon();
    medal_page_draw_kind_name();
    medal_page_draw_name();
    medal_skill_draw_level();
    medal_page_init_medal_arrows();
    render_medal_skill_stats();
    sub_0800B0F8();
    draw_medal_skill_bars();
    set_blend_effect_mode(5, 0x3F, 0x20);
    gUnk_03000440.unk84 = 0;
    gGameSubState++;
}

void medal_skill_wait_fade(void) {
    medals_scroll_bg();
    medal_page_blink_medal_arrows();
    sub_0800B130();
    if (update_blend_effect())
        gGameSubState++;
}

void medal_skill_handle_input(void) {
    medals_scroll_bg();
    medal_page_blink_medal_arrows();
    sub_0800B130();
    medal_page_cycle_medal_input();
    medal_skill_redraw();
    if (KEYS_LO(gNewKeys) & 2) {
        play_sound_effect(5);
        gGameSubState++;
    } else if (*((u8 *)&gNewKeys + 1) & 2) {
        play_sound_effect(2);
        gUnk_03000440.unk42 = (gUnk_03000440.unk42 - 1) & 3;
        gGameSubState = 0x44;
    } else if (*((u8 *)&gNewKeys + 1) & 1) {
        play_sound_effect(2);
        gUnk_03000440.unk42 = (gUnk_03000440.unk42 + 1) & 3;
        gGameSubState = 0x44;
    }
}

void medal_skill_start_fade_out(void) {
    set_blend_effect_mode(6, 0x3F, 0x20);
    medals_scroll_bg();
    medal_page_blink_medal_arrows();
    sub_0800B130();
    gGameSubState++;
}

// guess: debug skill level editor (sub-state 64; UP/DOWN pick a skill, RIGHT/LEFT change its level, SELECT, B -> 58)
void sub_08008A5C(void) {
    u8 b;

    setup_battle_cursor_sprite_0800B5E8();
    if ((b = KEYS_LO(gRepeatKeys) & 0x40)) {
        if (gUnk_03000440.unk48 == 0)
            gUnk_03000440.unk48 = 7;
        else
            gUnk_03000440.unk48--;
    } else if (KEYS_LO(gRepeatKeys) & 0x80) {
        if (gUnk_03000440.unk48 == 7)
            gUnk_03000440.unk48 = b;
        else
            gUnk_03000440.unk48++;
    } else if (KEYS_LO(gRepeatKeys) & 0x10 && gUnk_03000BE0[gUnk_03000440.unk3D].unk20[gUnk_03000440.unk48] != 100) {
        gUnk_03000BE0[gUnk_03000440.unk3D].unk20[gUnk_03000440.unk48]++;
        render_medal_skill_stats();
    } else if (KEYS_LO(gRepeatKeys) & 0x20 && gUnk_03000BE0[gUnk_03000440.unk3D].unk20[gUnk_03000440.unk48] != 0) {
        gUnk_03000BE0[gUnk_03000440.unk3D].unk20[gUnk_03000440.unk48]--;
        render_medal_skill_stats();
    } else if (KEYS_LO(gNewKeys) & 4) {
        gUnk_03000BE0[gUnk_03000440.unk3D].unk28[gUnk_03000440.unk48] = 7;
        draw_medal_skill_bars();
    } else if (KEYS_LO(gNewKeys) & 2) {
        clear_battle_sprite_slot(0x7F, 1);
        gGameSubState = 0x3A;
    }
}

void medals_help_load(void) {
    medals_scroll_bg();
    clear_sprite_table_mask(1, 5);
    CpuFastSet(gUnk_084E2E78, (void *)0x050003C0, 8);
    sub_0800AA1C();
    sub_0803FB0C();
    gGameSubState++;
}

void medals_help_show_intro(void) {
    medals_scroll_bg();
    if (run_message(gUnk_083B53F8[5]))
        gGameSubState++;
}

void medals_help_cursor_input(void) {
    u8 b;

    medals_scroll_bg();
    process_sprite_anim_commands(gUnk_083B5F80[3], 6);
    if ((b = KEYS_LO(gRepeatKeys) & 0x40)) {
        if (gUnk_03000440.unk44 == 0)
            gUnk_03000440.unk44 = gUnk_03000440.unk45 - 1;
        else
            gUnk_03000440.unk44--;
        goto moved;
    } else if (KEYS_LO(gRepeatKeys) & 0x80) {
        if (gUnk_03000440.unk44 == gUnk_03000440.unk45 - 1)
            gUnk_03000440.unk44 = b;
        else
            gUnk_03000440.unk44++;
    moved:
        play_sound_effect(2);
        sub_0800AAC0();
    } else if (KEYS_LO(gNewKeys) & 1) {
        play_sound_effect(4);
        sub_0800AA1C();
        sub_0803FB0C();
        gGameSubState++;
    } else if (KEYS_LO(gNewKeys) & 0xA) {
        play_sound_effect(5);
        gGameSubState = 0x4E;
    }
}

void medals_help_show_text(void) {
    u8 done;

    medals_scroll_bg();
    switch (gUnk_03000440.unk42) {
    case 0:
        switch (gUnk_03000440.unk44) {
        case 0:
            done = run_message(gUnk_083B53F8[6]);
            break;
        case 1:
            done = run_message(gUnk_083B53F8[7]);
            break;
        case 2:
            done = run_message(gUnk_083B69C8[gUnk_03000BE0[gUnk_03000440.unk3D].unk4]);
            break;
        case 3:
            done = run_message(gUnk_083B70AC[gUnk_03000BE0[gUnk_03000440.unk3D].unk6]);
            break;
        case 4:
            done = run_message(gUnk_083B53F8[8]);
            break;
        }
        break;
    case 1:
        switch (gUnk_03000440.unk44) {
        case 0:
            if (gUnk_03000BE0[gUnk_03000440.unk3D].unk5 > 9) {
                memcpy_bytes_08041D04(gUnk_083B7E0C + gUnk_03000BE0[gUnk_03000440.unk3D].unk1 * 3, &gUnk_03000440.unkEE,
                                      3);
                memcpy_bytes_08041D04(gUnk_083B7CD4 + gUnk_03000440.unkEE * 6, gUnk_03000440.unk10E, 6);
                done = run_message(gUnk_083B7F40[gUnk_03000440.unk10E[5]]);
            } else {
                done = run_message(gUnk_083B7F40[4]);
            }
            break;
        case 1:
            if (gUnk_03000BE0[gUnk_03000440.unk3D].unk5 > 29) {
                memcpy_bytes_08041D04(gUnk_083B7E0C + gUnk_03000BE0[gUnk_03000440.unk3D].unk1 * 3, &gUnk_03000440.unkEE,
                                      3);
                memcpy_bytes_08041D04(gUnk_083B7CD4 + gUnk_03000440.unkEF * 6, gUnk_03000440.unk10E, 6);
                done = run_message(gUnk_083B7F40[gUnk_03000440.unk10E[5]]);
            } else {
                done = run_message(gUnk_083B7F40[4]);
            }
            break;
        case 2:
            if (gUnk_03000BE0[gUnk_03000440.unk3D].unk5 > 59) {
                memcpy_bytes_08041D04(gUnk_083B7E0C + gUnk_03000BE0[gUnk_03000440.unk3D].unk1 * 3, &gUnk_03000440.unkEE,
                                      3);
                memcpy_bytes_08041D04(gUnk_083B7CD4 + gUnk_03000440.unkF0 * 6, gUnk_03000440.unk10E, 6);
                done = run_message(gUnk_083B7F40[gUnk_03000440.unk10E[5]]);
            } else {
                done = run_message(gUnk_083B7F40[4]);
            }
            break;
        case 3:
            done = run_message(gUnk_083B53F8[9]);
            break;
        case 4:
            done = run_message(gUnk_083B53F8[10]);
            break;
        case 5:
            switch (gUnk_03000440.unk46) {
            case 0:
                if (gUnk_03000BE0[gUnk_03000440.unk3D].unk5 > 9) {
                    memcpy_bytes_08041D04(gUnk_083B7E0C + gUnk_03000BE0[gUnk_03000440.unk3D].unk1 * 3,
                                          &gUnk_03000440.unkEE, 3);
                    memcpy_bytes_08041D04(gUnk_083B7CD4 + (&gUnk_03000440.unkEE)[gUnk_03000440.unk46] * 6,
                                          gUnk_03000440.unk10E, 6);
                    done = run_message(gUnk_083B8170[gUnk_03000440.unk10E[1]]);
                } else {
                    done = run_message(gUnk_083B53F8[11]);
                }
                break;
            case 1:
                if (gUnk_03000BE0[gUnk_03000440.unk3D].unk5 > 29) {
                    memcpy_bytes_08041D04(gUnk_083B7E0C + gUnk_03000BE0[gUnk_03000440.unk3D].unk1 * 3,
                                          &gUnk_03000440.unkEE, 3);
                    memcpy_bytes_08041D04(gUnk_083B7CD4 + (&gUnk_03000440.unkEE)[gUnk_03000440.unk46] * 6,
                                          gUnk_03000440.unk10E, 6);
                    done = run_message(gUnk_083B8170[gUnk_03000440.unk10E[1]]);
                } else {
                    done = run_message(gUnk_083B53F8[11]);
                }
                break;
            case 2:
                if (gUnk_03000BE0[gUnk_03000440.unk3D].unk5 > 59) {
                    memcpy_bytes_08041D04(gUnk_083B7E0C + gUnk_03000BE0[gUnk_03000440.unk3D].unk1 * 3,
                                          &gUnk_03000440.unkEE, 3);
                    memcpy_bytes_08041D04(gUnk_083B7CD4 + (&gUnk_03000440.unkEE)[gUnk_03000440.unk46] * 6,
                                          gUnk_03000440.unk10E, 6);
                    done = run_message(gUnk_083B8170[gUnk_03000440.unk10E[1]]);
                } else {
                    done = run_message(gUnk_083B53F8[11]);
                }
                break;
            }
            break;
        }
        break;
    case 2:
        switch (gUnk_03000440.unk44) {
        case 0:
            done = run_message(gUnk_083B53F8[13]);
            break;
        case 1:
            done = run_message(gUnk_083B53F8[14]);
            break;
        }
        break;
    }
    if (done) {
        sub_0803FB0C();
        gGameSubState = 0x49;
    }
}

void medals_help_exit(void) {
    medals_scroll_bg();
    clear_sprite_table_mask(6, 1);
    CpuFastSet(gUnk_084E2E58, (void *)0x050003C0, 8);
    switch (gUnk_03000440.unk42) {
    case 0:
        sub_0803FB0C();
        medal_page_init_medal_arrows();
        gGameSubState = 0xB;
        break;
    case 1:
        sub_0803FB0C();
        medal_page_init_medal_arrows();
        medal_medaforce_init_cursor();
        gGameSubState = 0x1B;
        break;
    case 2:
        if (gUnk_03000440.unk46 & 0x80) {
            gUnk_03000440.unk46 &= 0x7F;
            gGameSubState = 0x30;
        } else {
            sub_0803FB0C();
            medal_page_init_medal_arrows();
            gGameSubState = 0x2B;
        }
        break;
    }
}

// Medals screen sub-states 96-107 (not reached at runtime yet; guess: Medal confirm / transfer dialog)
void sub_08009174(void) {
    medals_scroll_bg();
    update_battle_sprite_visibility();
    gSpriteEntries[1].unk0 &= 0xBFFF;
    gSpriteEntries[2].unk0 &= 0xBFFF;
    set_tilemap_and_decompress_bg(0x12, 0xC, gUnk_084889F8, REG_BG0CNT, 0x350);
    gUnk_03000440.unk4A = 0;
    init_battle_cursor_sprite_0800B668();
    gGameSubState++;
}

void sub_080091E0(void) {
    medals_scroll_bg();
    update_battle_sprite_visibility();
    sprite_bob_y(7, gFrameCounter, 0xA8);
    handle_menu_cursor_updown();
    if (KEYS_LO(gNewKeys) & 1) {
        play_sound_effect(4);
    } else if (KEYS_LO(gNewKeys) & 2) {
        play_sound_effect(5);
        gUnk_03000440.unk4A = 2;
    } else {
        return;
    }
    init_battle_cursor_sprite_0800B668();
    gGameSubState++;
}

void sub_08009248(void) {
    medals_scroll_bg();
    update_battle_sprite_visibility();
    if (update_battle_sprite_and_check_done()) {
        clear_sprite_table_mask(7, 1);
        gGameSubState++;
    }
}

void sub_08009274(void) {
    medals_scroll_bg();
    update_battle_sprite_visibility();
    switch (gUnk_03000440.unk4A) {
    case 0:
        gUnk_03000440.unk42 = gUnk_03000440.unk4A;
        set_blend_effect_mode(6, 0x3F, 0x20);
        gGameSubState = 7;
        break;
    case 1:
        gGameSubState++;
        break;
    case 2:
        gGameSubState = gUnk_03000440.unk4A;
        break;
    }
}

void sub_080092D4(void) {
    u32 bit;

    medals_scroll_bg();
    update_battle_sprite_visibility();
    if (gUnk_03000BE0[gUnk_03000440.unk3D].unk0 & 0x40) {
        text_window_init(1, 2, 0);
        gUnk_03000440.unk84 = 9;
        gGameSubState++;
    } else if ((bit = (1 << gUnk_03000BE0[gUnk_03000440.unk3D].unk1) & gUnk_03002B68)) {
        text_window_init(1, 2, 0);
        gUnk_03000440.unk84 = 8;
        gGameSubState++;
    } else {
        clear_battle_sprite_slot(5, 1);
        sound_stop_all_with_fade_guard(8);
        gUnk_03000440.unk3E = bit;
        gGameSubState = 0x68;
    }
}

void sub_08009374(void) {
    medals_scroll_bg();
    update_battle_sprite_visibility();
    if (run_message(gLinkMessages[gUnk_03000440.unk84]))
        gGameSubState = 2;
}

void sub_080093AC(void) {
    memcpy_bytes_0803F63C(&gUnk_03000BE0[gUnk_03000440.unk3D], (void *)0x02023000, 0x40);
    gGameSubState++;
}

void sub_080093E0(void) {
    clear_battle_sprite_slot(0, 0x80);
    clear_bg_scroll();
    goto_link_scene(1);
}

static void medals_scroll_bg(void) {
    if (gFrameCounter & 1) {
        gBg3Scroll.x++;
        gBg3Scroll.y++;
    }
}

static void medals_list_set_cursor_from_medal(void) {
    gUnk_03000440.unk3F = gUnk_03000440.unk3D / 6;
    gUnk_03000440.unk40 = gUnk_03000440.unk3D % 6;
}

static void count_owned_medals(void) {
    u32 i;

    gUnk_03000440.unk41 = 0;
    for (i = 0; i < 30; i++) {
        if (gUnk_03000BE0[i].unk0 & 0x80)
            gUnk_03000440.unk41++;
    }
}

static void render_medal_sprite_tile(void) {
    u8 n = 0;
    u8 i;

    for (i = gUnk_03000440.unk3F * 6; i < gUnk_03000440.unk3F * 6 + 6; n++, i++) {
        if (gUnk_03000BE0[i].unk0 & 0x80)
            CpuFastSet(gUnk_084C21BC + gUnk_03000BE0[i].unk1 * 0x80, (void *)0x06006600 + n * 0x80, 0x20);
        else
            CpuFastSet(gUnk_084C30BC, (void *)0x06006600 + n * 0x80, 0x20);
    }
    write_tilemap_rect(2, 12, 4, 4, gUnk_083B4AE0[0x50], REG_BG1CNT, 0x200);
}

static void render_medal_list_entries(void) {
    u8 n = 0;
    u8 i;

    clear_sprite_table_mask(10, 0x3C);
    for (i = gUnk_03000440.unk3F * 6; i < gUnk_03000440.unk3F * 6 + 6; n++, i++) {
        if (gUnk_03000BE0[i].unk0 & 0x80) {
            memcpy_bytes_0803F63C((void *)gUnk_083B6410[gUnk_03000BE0[i].unk1], gUnk_03000440.unk9E, 11);
            render_text_sprites_08040DB8(gUnk_03000440.unk9E, n * 10 + 10, 6, n * 2 + 4, 7, 8, 1, 2);
        } else {
            fill_text_blank(gUnk_03000440.unk9E, 9);
            render_text_sprites_08040DB8(gUnk_03000440.unk9E, n * 10 + 10, 6, n * 2 + 4, 7, 8, 1, 2);
        }
    }
}

static void render_medal_slots_in_menu(void) {
    u32 i;
    u32 n;

    for (n = 0, i = gUnk_03000440.unk3F * 6; i < gUnk_03000440.unk3F * 6 + 6; n++, i++) {
        if (gUnk_03000BE0[i].unk0 & 0x80) {
            fill_tilemap_pair_or_divide(gUnk_03000BE0[i].unk5, 14, (u8)(n * 2 + 4), REG_BG1CNT, 0xD314);
        } else {
            draw_tile_block(1, 2, 14, n * 2 + 4, REG_BG1CNT, 0xD32C);
            draw_tile_block(1, 2, 15, n * 2 + 4, REG_BG1CNT, 0xD32C);
        }
    }
}

static void render_medal_name_display(void) {
    u8 has;

    gUnk_03000440.unk3D = gUnk_03000440.unk3F * 6 + gUnk_03000440.unk40;
    clear_sprite_table_mask(0x46, 10);
    if ((has = gUnk_03000BE0[gUnk_03000440.unk3D].unk0 & 0x80)) {
        render_text_sprites_08040DB8(gUnk_03000BE0[gUnk_03000440.unk3D].unkA, 0x46, 0x13, 3, 10, 9, 0, 2);
    } else {
        fill_text_blank(gUnk_03000440.unk9E, 10);
        render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x46, 0x13, 3, 10, 9, has, 2);
    }
}

void load_medal_sprite(void) {
    gUnk_03000440.unk3D = gUnk_03000440.unk3F * 6 + gUnk_03000440.unk40;
    if (gUnk_03000BE0[gUnk_03000440.unk3D].unk0 & 0x80) {
        lz_decompress_dispatch(
            gUnk_083AC494[gUnk_03000BE0[gUnk_03000440.unk3D].unk1][gUnk_03000BE0[gUnk_03000440.unk3D].unk8],
            (void *)0x06010000);
        gSpriteEntries[0].unk0 = 0xC804;
        gSpriteEntries[0].unk2 = 0xC0;
        gSpriteEntries[0].unk4 = 0x50;
        gSpriteEntries[0].unk6 = 0x200;
        gSpriteEntries[0].unkA = 13;
        gSpriteEntries[0].unk1C = 0;
        gSpriteEntries[0].unkB = 0x40;
    } else {
        clear_sprite_table_mask(0, 1);
    }
}

void render_medal_level_display(void) {
    u8 *buf;

    gUnk_03000440.unk3D = gUnk_03000440.unk3F * 6 + gUnk_03000440.unk40;
    clear_sprite_table_mask(0x50, 6);
    if (gUnk_03000BE0[gUnk_03000440.unk3D].unk0 & 0x80) {
        if (gUnk_03000BE0[gUnk_03000440.unk3D].unk5 != 100) {
            buf = gUnk_03000440.unk9E;
            divide_by_100000_08041370(buf, gUnk_03000BE0[gUnk_03000440.unk3D].unk2);
        } else {
            buf = gUnk_03000440.unk9E;
            fill_text_blank(buf, 5);
        }
        render_text_sprites_08040DB8(buf, 0x50, 0x13, 0x11, 6, 10, 2, 2);
    } else {
        buf = gUnk_03000440.unk9E;
        fill_text_blank(buf, 5);
        render_text_sprites_08040DB8(buf, 0x50, 0x13, 0x11, 6, 10, 2, 2);
    }
}

static void medals_list_init_tab_arrows(void) {
    gSpriteEntries[1].unk0 = 0xC804;
    gSpriteEntries[1].unk2 = 0x24;
    gSpriteEntries[1].unk4 = 0x18;
    gSpriteEntries[1].unk6 = 0x302;
    gSpriteEntries[1].unkA = 14;
    gSpriteEntries[1].unk1C = 0;
    gSpriteEntries[1].unkB = 0x40;
    gSpriteEntries[2].unk0 = 0xC804;
    gSpriteEntries[2].unk2 = 0x7C;
    gSpriteEntries[2].unk4 = 0x18;
    gSpriteEntries[2].unk6 = 0x303;
    gSpriteEntries[2].unkA = 14;
    gSpriteEntries[2].unk1C = 0;
    gSpriteEntries[2].unkB = 0x40;
}

static void medals_list_init_cursor(void) {
    gSpriteEntries[3].unk0 = 0xC804;
    gSpriteEntries[3].unk2 = 0x18;
    gSpriteEntries[3].unk4 = gUnk_03000440.unk40 * 16 + 0x28;
    gSpriteEntries[3].unk6 = 0x307;
    gSpriteEntries[3].unkA = 14;
    gSpriteEntries[3].unk1C = 0;
    gSpriteEntries[3].unkB = 0x41;
}

static void medals_list_blink_tab_arrows(void) {
    if (gFrameCounter & 8) {
        gSpriteEntries[1].unk0 &= 0xBFFF;
        gSpriteEntries[2].unk0 &= 0xBFFF;
    } else {
        gSpriteEntries[1].unk0 |= 0x4000;
        gSpriteEntries[2].unk0 |= 0x4000;
    }
}

static void medals_list_row_input(void) {
    if (KEYS_LO(gRepeatKeys) & 0x40) {
        if (gUnk_03000440.unk40 == 0)
            gUnk_03000440.unk40 = 5;
        else
            gUnk_03000440.unk40--;
    }
    if (KEYS_LO(gRepeatKeys) & 0x80) {
        if (gUnk_03000440.unk40 == 5)
            gUnk_03000440.unk40 = 0;
        else
            gUnk_03000440.unk40++;
    }
    if (KEYS_LO(gRepeatKeys) & 0xC0) {
        play_sound_effect(2);
        gSpriteEntries[3].unk4 = gUnk_03000440.unk40 * 16 + 0x28;
        render_medal_name_display();
        load_medal_sprite();
        render_medal_level_display();
        decompress_active_medal_sprite();
        init_active_medal_battle_sprites();
        draw_medal_position_tile();
    }
}

static void medals_list_tab_input(void) {
    if (KEYS_LO(gRepeatKeys) & 0x20) {
        if (gUnk_03000440.unk3F == 0)
            gUnk_03000440.unk3F = 4;
        else
            gUnk_03000440.unk3F--;
    }
    if (KEYS_LO(gRepeatKeys) & 0x10) {
        if (gUnk_03000440.unk3F == 4)
            gUnk_03000440.unk3F = 0;
        else
            gUnk_03000440.unk3F++;
    }
    if (KEYS_LO(gRepeatKeys) & 0x30) {
        play_sound_effect(2);
        write_tilemap_rect(10, 2, 5, 2, gUnk_083B4AE0[gUnk_03000440.unk3F + 0x4B], REG_BG1CNT, 0x200);
        render_medal_sprite_tile();
        render_medal_list_entries();
        render_medal_slots_in_menu();
        render_medal_name_display();
        load_medal_sprite();
        render_medal_level_display();
        decompress_active_medal_sprite();
        init_active_medal_battle_sprites();
        draw_medal_position_tile();
    }
}

static void update_battle_sprite_visibility(void) {
    u8 medal;

    if (gUnk_03000440.unk3E & 0x80) {
        medal = gUnk_03000440.unk3E & 0x7F;
        if ((u8)(medal / 6) == gUnk_03000440.unk3F) {
            if (gFrameCounter & 1) {
                gSpriteEntries[5].unk0 = 0xC804;
                gSpriteEntries[5].unk2 = 0x19;
                gSpriteEntries[5].unk4 = (u8)(medal % 6) * 16 + 0x2A;
                gSpriteEntries[5].unk6 = 0x307;
                gSpriteEntries[5].unkA = 0xE;
                gSpriteEntries[5].unk1C = 0;
                gSpriteEntries[5].unkB = 0x40;
            } else
                gSpriteEntries[5].unk0 &= 0xBFFF;
        } else
            gSpriteEntries[5].unk0 &= 0xBFFF;
    } else
        gSpriteEntries[5].unk0 &= 0xBFFF;
}

static void medals_list_swap_input(void) {
    u32 cur;

    if (KEYS_LO(gNewKeys) & 4) {
        play_sound_effect(2);
        if (gUnk_03000440.unk3E & 0x80) {
            gUnk_03000440.unk3E &= 0x7F;
            if (gUnk_03000440.unk3E != (cur = gUnk_03000440.unk3F * 6 + gUnk_03000440.unk40)) {
                memswap(&gUnk_03000BE0[gUnk_03000440.unk3E], &gUnk_03000BE0[cur], 0x40);
                write_tilemap_rect(10, 2, 5, 2, gUnk_083B4AE0[gUnk_03000440.unk3F + 0x4B], REG_BG1CNT, 0x200);
                render_medal_sprite_tile();
                render_medal_list_entries();
                render_medal_slots_in_menu();
                render_medal_name_display();
                load_medal_sprite();
                render_medal_level_display();
                decompress_active_medal_sprite();
                init_active_medal_battle_sprites();
                draw_medal_position_tile();
            }
            gUnk_03000440.unk3E = 0;
            update_battle_sprite_visibility();
        } else {
            gUnk_03000440.unk3E = gUnk_03000440.unk3F * 6 + gUnk_03000440.unk40 + 0x80;
            update_battle_sprite_visibility();
        }
    }
}

static u32 get_medal_active_slot(u8 medal) {
    if (gUnk_03000BE0[medal].unk0 & 0x80 && gUnk_03000BE0[medal].unk0 & 0x40)
        return find_medabot_slot_by_medal(gUnk_03000BE0[medal].unk1);
    return 0xFF;
}

static void decompress_active_medal_sprite(void) {
    u32 slot;

    gUnk_03000440.unk3D = gUnk_03000440.unk3F * 6 + gUnk_03000440.unk40;
    slot = get_medal_active_slot(gUnk_03000440.unk3D);
    if (slot != 0xFF)
        decompress_sprite_to_vram_08042D94(gUnk_030017A0[slot].unk3, gUnk_030017A0[slot].unk4, gUnk_030017A0[slot].unk5,
                                           gUnk_030017A0[slot].unk6, 2);
}

static void init_active_medal_battle_sprites(void) {
    u32 slot;

    gUnk_03000440.unk3D = gUnk_03000440.unk3F * 6 + gUnk_03000440.unk40;
    slot = get_medal_active_slot(gUnk_03000440.unk3D);
    if (slot != 0xFF)
        init_battle_medabot_sprites(gUnk_030017A0[slot].unk3, gUnk_030017A0[slot].unk4, gUnk_030017A0[slot].unk5,
                                    gUnk_030017A0[slot].unk6, 2, 0x64, 0xE0, 0x78, 0, 2, 0);
    else
        clear_sprite_table_mask(0x64, 4);
}

static void draw_medal_position_tile(void) {
    u32 slot;

    gUnk_03000440.unk3D = gUnk_03000440.unk3F * 6 + gUnk_03000440.unk40;
    slot = get_medal_active_slot(gUnk_03000440.unk3D);
    if (slot != 0xFF) {
        if (gUnk_030017A0[slot].unk6 < 0x78) {
            load_part_data(gUnk_030017A0[slot].unk6, 3, gUnk_03000440.unk10E);
            draw_tilemap_with_offset(gUnk_03000440.unk10E[1] - 0x64, 0x1B, 0x11, REG_BG1CNT, 0x83A0);
        } else
            draw_tilemap_with_offset(0xFF, 0x1B, 0x11, REG_BG1CNT, 0x83A0);
    } else
        draw_tilemap_with_offset(0xFF, 0x1B, 0x11, REG_BG1CNT, 0x83A0);
}

static void medal_page_draw_icon(void) {
    CpuFastSet(gUnk_084C21BC + gUnk_03000BE0[gUnk_03000440.unk3D].unk1 * 0x80, (void *)0x06006600, 0x20);
    draw_tile_block(2, 2, 2, 3, REG_BG1CNT, 0x6330);
}

static void medal_skill_draw_icon(void) {
    CpuFastSet(gUnk_084C21BC + gUnk_03000BE0[gUnk_03000440.unk3D].unk1 * 0x80, (void *)0x06007800, 0x20);
    draw_tile_block(2, 2, 2, 3, REG_BG1CNT, 0x63C0);
}

static void medal_page_draw_kind_name(void) {
    clear_sprite_table_mask(10, 10);
    memcpy_bytes_0803F63C((void *)gUnk_083B6410[gUnk_03000BE0[gUnk_03000440.unk3D].unk1], gUnk_03000440.unk9E, 11);
    render_text_sprites_08040DB8(gUnk_03000440.unk9E, 10, 4, 3, 7, 13, 1, 1);
}

static void medal_page_draw_name(void) {
    clear_sprite_table_mask(0x14, 10);
    render_text_sprites_08040DB8(gUnk_03000BE0[gUnk_03000440.unk3D].unkA, 0x14, 0x12, 3, 10, 12, 0, 1);
}

static void medal_page_draw_level(void) {
    fill_tilemap_pair_or_divide(gUnk_03000BE0[gUnk_03000440.unk3D].unk5, 12, 3, REG_BG1CNT, 0xC314);
}

static void medal_skill_draw_level(void) {
    fill_tilemap_pair_or_divide(gUnk_03000BE0[gUnk_03000440.unk3D].unk5, 12, 3, REG_BG1CNT, 0xC3A4);
}

static void medal_ability_draw_attribute(void) {
    clear_sprite_table_mask(0x1E, 15);
    memcpy_bytes_0803F63C((void *)gUnk_083B656C[gUnk_03000BE0[gUnk_03000440.unk3D].unk4], gUnk_03000440.unk9E, 14);
    render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x1E, 10, 7, 8, 11, 1, 1);
}

static void medal_ability_draw_aim(void) {
    clear_sprite_table_mask(0x2D, 13);
    memcpy_bytes_0803F63C((void *)gUnk_083B6EC8[gUnk_03000BE0[gUnk_03000440.unk3D].unk6], gUnk_03000440.unk9E, 14);
    render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x2D, 10, 10, 10, 10, 1, 1);
}

static void medal_ability_draw_compatibility(void) {
    draw_tile_block(2, 2, 0x1B, 7, REG_BG1CNT, gUnk_03000BE0[gUnk_03000440.unk3D].unk7 * 4 + 0xD340);
}

static void medal_page_init_medal_arrows(void) {
    if (gUnk_03000440.unk41 > 1) {
        gSpriteEntries[1].unk0 = 0xC804;
        gSpriteEntries[1].unk2 = 4;
        gSpriteEntries[1].unk4 = 0x20;
        gSpriteEntries[1].unk6 = 0x302;
        gSpriteEntries[1].unkA = 14;
        gSpriteEntries[1].unk1C = 0;
        gSpriteEntries[1].unkB = 0x40;
        gSpriteEntries[2].unk0 = 0xC804;
        gSpriteEntries[2].unk2 = 0x7C;
        gSpriteEntries[2].unk4 = 0x20;
        gSpriteEntries[2].unk6 = 0x303;
        gSpriteEntries[2].unkA = 14;
        gSpriteEntries[2].unk1C = 0;
        gSpriteEntries[2].unkB = 0x40;
    }
}

static void medal_page_blink_medal_arrows(void) {
    if (gUnk_03000440.unk41 > 1) {
        if (gFrameCounter & 8) {
            gSpriteEntries[1].unk0 &= 0xBFFF;
            gSpriteEntries[2].unk0 &= 0xBFFF;
        } else {
            gSpriteEntries[1].unk0 |= 0x4000;
            gSpriteEntries[2].unk0 |= 0x4000;
        }
    }
}

static void medal_page_cycle_medal_input(void) {
    u32 found;

    if (gUnk_03000440.unk41 > 1) {
        if (KEYS_LO(gRepeatKeys) & 0x20) {
            play_sound_effect(2);
            found = 0;
            do {
                if (gUnk_03000440.unk3D == 0)
                    gUnk_03000440.unk3D = 29;
                else
                    gUnk_03000440.unk3D--;
                if (gUnk_03000BE0[gUnk_03000440.unk3D].unk0 & 0x80) {
                    if (gUnk_03000440.unk3C != 1)
                        found = 1;
                    else if (!(gUnk_03000BE0[gUnk_03000440.unk3D].unk0 & 0x40))
                        found = 1;
                }
            } while (!found);
        }
        if (KEYS_LO(gRepeatKeys) & 0x10) {
            play_sound_effect(2);
            found = 0;
            do {
                if (gUnk_03000440.unk3D == 29)
                    gUnk_03000440.unk3D = 0;
                else
                    gUnk_03000440.unk3D++;
                if (gUnk_03000BE0[gUnk_03000440.unk3D].unk0 & 0x80) {
                    if (gUnk_03000440.unk3C != 1)
                        found = 1;
                    else if (!(gUnk_03000BE0[gUnk_03000440.unk3D].unk0 & 0x40))
                        found = 1;
                }
            } while (!found);
        }
    }
}

static void medal_ability_redraw(void) {
    if (KEYS_LO(gRepeatKeys) & 0x30) {
        medal_page_draw_icon();
        medal_page_draw_kind_name();
        medal_page_draw_name();
        medal_page_draw_level();
        medal_ability_draw_attribute();
        medal_ability_draw_aim();
        medal_ability_draw_compatibility();
    }
}

static void medal_medaforce_draw_list(void) {
    clear_sprite_table_mask(0x1E, 0x3C);
    if (gUnk_03000BE0[gUnk_03000440.unk3D].unk5 >= 10) {
        memcpy_bytes_08041D04(gUnk_083B7E0C + gUnk_03000BE0[gUnk_03000440.unk3D].unk1 * 3, &gUnk_03000440.unkEE, 3);
        memcpy_bytes_08041D04(gUnk_083B7CD4 + gUnk_03000440.unkEE * 6, gUnk_03000440.unk10E, 6);
        memcpy_bytes_0803F63C((void *)gUnk_083B7338[gUnk_03000440.unkEE], gUnk_03000440.unk9E, 17);
        render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x1E, 2, 6, 10, 10, 1, 1);
        draw_tile_block(2, 2, 12, 6, REG_BG1CNT, gUnk_03000440.unk10E[5] * 4 + 0x5300);
    } else {
        fill_text_blank(gUnk_03000440.unk9E, 13);
        render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x1E, 2, 6, 10, 10, 1, 1);
        vram_fill_tilemap_rect(2, 2, 12, 6, REG_BG1CNT, 0);
    }
    if (gUnk_03000BE0[gUnk_03000440.unk3D].unk5 >= 30) {
        memcpy_bytes_08041D04(gUnk_083B7CD4 + gUnk_03000440.unkEF * 6, gUnk_03000440.unk10E, 6);
        memcpy_bytes_0803F63C((void *)gUnk_083B7338[gUnk_03000440.unkEF], gUnk_03000440.unk9E, 17);
        render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x32, 2, 8, 10, 10, 1, 1);
        draw_tile_block(2, 2, 12, 8, REG_BG1CNT, gUnk_03000440.unk10E[5] * 4 + 0x5300);
    } else {
        fill_text_blank(gUnk_03000440.unk9E, 13);
        render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x32, 2, 8, 10, 10, 1, 1);
        vram_fill_tilemap_rect(2, 2, 12, 8, REG_BG1CNT, 0);
    }
    if (gUnk_03000BE0[gUnk_03000440.unk3D].unk5 >= 60) {
        memcpy_bytes_08041D04(gUnk_083B7CD4 + gUnk_03000440.unkF0 * 6, gUnk_03000440.unk10E, 6);
        memcpy_bytes_0803F63C((void *)gUnk_083B7338[gUnk_03000440.unkF0], gUnk_03000440.unk9E, 17);
        render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x46, 2, 10, 10, 10, 1, 1);
        draw_tile_block(2, 2, 12, 10, REG_BG1CNT, gUnk_03000440.unk10E[5] * 4 + 0x5300);
    } else {
        fill_text_blank(gUnk_03000440.unk9E, 13);
        render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x46, 2, 10, 10, 10, 1, 1);
        vram_fill_tilemap_rect(2, 2, 12, 10, REG_BG1CNT, 0);
    }
}

static void medal_medaforce_draw_selected(void) {
    clear_sprite_table_mask(0x5A, 15);
    switch (gUnk_03000440.unk46) {
    case 0:
        if (gUnk_03000BE0[gUnk_03000440.unk3D].unk5 >= 10) {
            memcpy_bytes_08041D04(gUnk_083B7E0C + gUnk_03000BE0[gUnk_03000440.unk3D].unk1 * 3, &gUnk_03000440.unkEE, 3);
            memcpy_bytes_08041D04(gUnk_083B7CD4 + gUnk_03000440.unkEE * 6, gUnk_03000440.unk10E, 6);
            memcpy_bytes_0803F63C((void *)gUnk_083B6EC8[gUnk_03000440.unk10E[1]], gUnk_03000440.unk9E, 14);
            render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x5A, 0x13, 7, 10, 11, 1, 1);
            draw_number_bgcnt(gUnk_03000440.unk10E[2], 0x19, 10, 2, REG_BG1CNT, 0xD334);
        } else {
            fill_text_blank(gUnk_03000440.unk9E, 13);
            render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x5A, 0x13, 7, 10, 11, 1, 1);
            draw_number_bgcnt(0, 0x19, 10, 2, REG_BG1CNT, 0xD334);
        }
        break;
    case 1:
        if (gUnk_03000BE0[gUnk_03000440.unk3D].unk5 >= 30) {
            memcpy_bytes_08041D04(gUnk_083B7E0C + gUnk_03000BE0[gUnk_03000440.unk3D].unk1 * 3, &gUnk_03000440.unkEE, 3);
            memcpy_bytes_08041D04(gUnk_083B7CD4 + gUnk_03000440.unkEF * 6, gUnk_03000440.unk10E, 6);
            memcpy_bytes_0803F63C((void *)gUnk_083B6EC8[gUnk_03000440.unk10E[1]], gUnk_03000440.unk9E, 14);
            render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x5A, 0x13, 7, 10, 11, 1, 1);
            draw_number_bgcnt(gUnk_03000440.unk10E[2], 0x19, 10, 2, REG_BG1CNT, 0xD334);
        } else {
            fill_text_blank(gUnk_03000440.unk9E, 13);
            render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x5A, 0x13, 7, 10, 11, 1, 1);
            draw_number_bgcnt(0, 0x19, 10, 2, REG_BG1CNT, 0xD334);
        }
        break;
    default:
        if (gUnk_03000BE0[gUnk_03000440.unk3D].unk5 >= 60) {
            memcpy_bytes_08041D04(gUnk_083B7E0C + gUnk_03000BE0[gUnk_03000440.unk3D].unk1 * 3, &gUnk_03000440.unkEE, 3);
            memcpy_bytes_08041D04(gUnk_083B7CD4 + gUnk_03000440.unkF0 * 6, gUnk_03000440.unk10E, 6);
            memcpy_bytes_0803F63C((void *)gUnk_083B6EC8[gUnk_03000440.unk10E[1]], gUnk_03000440.unk9E, 14);
            render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x5A, 0x13, 7, 10, 11, 1, 1);
            draw_number_bgcnt(gUnk_03000440.unk10E[2], 0x19, 10, 2, REG_BG1CNT, 0xD334);
        } else {
            fill_text_blank(gUnk_03000440.unk9E, 13);
            render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x5A, 0x13, 7, 10, 11, 1, 1);
            draw_number_bgcnt(0, 0x19, 10, 2, REG_BG1CNT, 0xD334);
        }
        break;
    }
}

static void medal_medaforce_init_cursor(void) {
    gSpriteEntries[3].unk0 = 0xC804;
    gSpriteEntries[3].unk2 = 8;
    gSpriteEntries[3].unk4 = gUnk_03000440.unk46 * 16 + 0x38;
    gSpriteEntries[3].unk6 = 0x307;
    gSpriteEntries[3].unkA = 14;
    gSpriteEntries[3].unk1C = 0;
    gSpriteEntries[3].unkB = 0x41;
}

static u32 medal_medaforce_cursor_input(void) {
    if (KEYS_LO(gRepeatKeys) & 0x40) {
        if (gUnk_03000440.unk46 == 0)
            gUnk_03000440.unk46 = 2;
        else
            gUnk_03000440.unk46--;
    }
    if (KEYS_LO(gRepeatKeys) & 0x80) {
        if (gUnk_03000440.unk46 == 2)
            gUnk_03000440.unk46 = 0;
        else
            gUnk_03000440.unk46++;
    }
    if (KEYS_LO(gRepeatKeys) & 0xC0) {
        play_sound_effect(2);
        gSpriteEntries[3].unk4 = gUnk_03000440.unk46 * 16 + 0x38;
        medal_medaforce_draw_selected();
        return 1;
    }
    return 0;
}

static u32 medal_medaforce_redraw(void) {
    if (KEYS_LO(gRepeatKeys) & 0x30) {
        medal_page_draw_icon();
        medal_page_draw_kind_name();
        medal_page_draw_name();
        medal_page_draw_level();
        medal_medaforce_draw_list();
        medal_medaforce_draw_selected();
        return 1;
    }
    return 0;
}

u32 medal_medaforce_get_selected(void) {
    switch (gUnk_03000440.unk46) {
    default:
        if (gUnk_03000BE0[gUnk_03000440.unk3D].unk5 >= 60)
            goto slot2;
    none:
        return 0x34;
    case 0:
        if (gUnk_03000BE0[gUnk_03000440.unk3D].unk5 < 10)
            goto none;
        memcpy_bytes_08041D04(gUnk_083B7E0C + gUnk_03000BE0[gUnk_03000440.unk3D].unk1 * 3, &gUnk_03000440.unkEE, 3);
        return gUnk_03000440.unkEE;
    case 1:
        if (gUnk_03000BE0[gUnk_03000440.unk3D].unk5 < 30)
            goto none;
        memcpy_bytes_08041D04(gUnk_083B7E0C + gUnk_03000BE0[gUnk_03000440.unk3D].unk1 * 3, &gUnk_03000440.unkEE, 3);
        return gUnk_03000440.unkEF;
    }
slot2:
    memcpy_bytes_08041D04(gUnk_083B7E0C + gUnk_03000BE0[gUnk_03000440.unk3D].unk1 * 3, &gUnk_03000440.unkEE, 3);
    return gUnk_03000440.unkF0;
}

void sub_0800AA1C(void) {
    const u8 *rec = gUnk_083B7EBC[gUnk_03000440.unk43];

    gUnk_03000440.unk45 = rec[0];
    gSpriteEntries[6].unk0 = 0xC004;
    gSpriteEntries[6].unk2 = rec[(gUnk_03000440.unk44 + 1) << 1] * 8;
    gSpriteEntries[6].unk4 = rec[((gUnk_03000440.unk44 + 1) << 1) + 1] * 8;
    gSpriteEntries[6].unk6 = 0x308;
    gSpriteEntries[6].unkA = 14;
    gSpriteEntries[6].unk1C = 0;
    gSpriteEntries[6].unkB = 0xC1;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[3], 6);
}

static void sub_0800AAC0(void) {
    const u8 *rec = gUnk_083B7EBC[gUnk_03000440.unk43];

    gSpriteEntries[6].unk2 = rec[(gUnk_03000440.unk44 + 1) << 1] * 8;
    gSpriteEntries[6].unk4 = rec[((gUnk_03000440.unk44 + 1) << 1) + 1] * 8;
}

void sub_0800AB0C(void) {
    u32 i;

    for (i = 0; i < 8; i++) {
        if (i < gUnk_03000BE0[gUnk_03000440.unk3D].unk9)
            draw_tile_block(2, 2, i * 2 + 6, 7, REG_BG1CNT, gUnk_03000BE0[gUnk_03000440.unk3D].unk18[i] * 4 + 0xB340);
        else
            draw_tile_block(2, 2, i * 2 + 6, 7, REG_BG1CNT, gUnk_03000BE0[gUnk_03000440.unk3D].unk18[i] * 4 + 0xA340);
    }
}

static void sub_0800ABA4(void) {
    write_tilemap_rect(16, 2, 6, 10, gUnk_083B4AE0[gUnk_03000BE0[gUnk_03000440.unk3D].unk9 + 0x51], REG_BG1CNT, 0x200);
}

static void medal_rotation_redraw(void) {
    if (KEYS_LO(gRepeatKeys) & 0x30) {
        medal_page_draw_icon();
        medal_page_draw_kind_name();
        medal_page_draw_name();
        medal_page_draw_level();
        sub_0800AB0C();
        sub_0800ABA4();
        sub_0800AED0();
        sub_0800AF0C();
        sub_0800AF64();
    }
}

static void sub_0800AC2C(void) {
    gSpriteEntries[1].unk0 = 0xC804;
    gSpriteEntries[1].unk2 = gUnk_03000440.unk46 * 16 + 0x38;
    gSpriteEntries[1].unk4 = 0x34;
    gSpriteEntries[1].unk6 = 0x300;
    gSpriteEntries[1].unkA = 14;
    gSpriteEntries[1].unk1C = 0;
    gSpriteEntries[1].unkB = 0x40;
    gSpriteEntries[2].unk0 = 0xC804;
    gSpriteEntries[2].unk2 = gUnk_03000440.unk46 * 16 + 0x38;
    gSpriteEntries[2].unk4 = 0x4C;
    gSpriteEntries[2].unk6 = 0x301;
    gSpriteEntries[2].unkA = 14;
    gSpriteEntries[2].unk1C = 0;
    gSpriteEntries[2].unkB = 0x40;
}

static void sub_0800ACA8(void) {
    gSpriteEntries[3].unk0 = 0xC804;
    gSpriteEntries[3].unk2 = gUnk_03000BE0[gUnk_03000440.unk3D].unk9 * 16 + 0x30;
    gSpriteEntries[3].unk4 = 0x30;
    gSpriteEntries[3].unk6 = 0x305;
    gSpriteEntries[3].unkA = 14;
    gSpriteEntries[3].unk1C = 0;
    gSpriteEntries[3].unkB = 0x40;
}

static void sub_0800AD00(void) {
    if (gFrameCounter & 8) {
        gSpriteEntries[1].unk0 &= 0xBFFF;
        gSpriteEntries[2].unk0 &= 0xBFFF;
    } else {
        gSpriteEntries[1].unk0 |= 0x4000;
        gSpriteEntries[2].unk0 |= 0x4000;
    }
}

static u32 sub_0800AD58(void) {
    u8 up;

    if ((up = KEYS_LO(gRepeatKeys) & 0x40)) {
        play_sound_effect(2);
        if (gUnk_03000BE0[gUnk_03000440.unk3D].unk18[gUnk_03000440.unk46] == 0)
            gUnk_03000BE0[gUnk_03000440.unk3D].unk18[gUnk_03000440.unk46] = 7;
        else
            gUnk_03000BE0[gUnk_03000440.unk3D].unk18[gUnk_03000440.unk46]--;
        return 1;
    }
    if (KEYS_LO(gRepeatKeys) & 0x80) {
        play_sound_effect(2);
        if (gUnk_03000BE0[gUnk_03000440.unk3D].unk18[gUnk_03000440.unk46] == 7)
            gUnk_03000BE0[gUnk_03000440.unk3D].unk18[gUnk_03000440.unk46] = up;
        else
            gUnk_03000BE0[gUnk_03000440.unk3D].unk18[gUnk_03000440.unk46]++;
        return 1;
    }
    return 0;
}

static u32 sub_0800ADE8(void) {
    u8 left;

    if ((left = KEYS_LO(gRepeatKeys) & 0x20)) {
        play_sound_effect(2);
        if (gUnk_03000440.unk46 == 0)
            gUnk_03000440.unk46 = 7;
        else
            gUnk_03000440.unk46--;
        sub_0800AC2C();
        return 1;
    }
    if (KEYS_LO(gRepeatKeys) & 0x10) {
        play_sound_effect(2);
        if (gUnk_03000440.unk46 == 7)
            gUnk_03000440.unk46 = left;
        else
            gUnk_03000440.unk46++;
        sub_0800AC2C();
        return 1;
    }
    return 0;
}

static u32 sub_0800AE54(void) {
    u8 left;

    if ((left = KEYS_LO(gRepeatKeys) & 0x20)) {
        play_sound_effect(2);
        if (gUnk_03000BE0[gUnk_03000440.unk3D].unk9 == 0)
            gUnk_03000BE0[gUnk_03000440.unk3D].unk9 = 7;
        else
            gUnk_03000BE0[gUnk_03000440.unk3D].unk9--;
        return 1;
    }
    if (KEYS_LO(gRepeatKeys) & 0x10) {
        play_sound_effect(2);
        if (gUnk_03000BE0[gUnk_03000440.unk3D].unk9 == 7)
            gUnk_03000BE0[gUnk_03000440.unk3D].unk9 = left;
        else
            gUnk_03000BE0[gUnk_03000440.unk3D].unk9++;
        return 1;
    }
    return 0;
}

static void sub_0800AED0(void) {
    u32 slot = get_medal_active_slot(gUnk_03000440.unk3D);

    if (slot != 0xFF)
        decompress_sprite_to_vram_08042D94(gUnk_030017A0[slot].unk3, gUnk_030017A0[slot].unk4, gUnk_030017A0[slot].unk5,
                                           gUnk_030017A0[slot].unk6, 2);
}

static void sub_0800AF0C(void) {
    u32 slot = get_medal_active_slot(gUnk_03000440.unk3D);

    if (slot != 0xFF)
        init_battle_medabot_sprites(gUnk_030017A0[slot].unk3, gUnk_030017A0[slot].unk4, gUnk_030017A0[slot].unk5,
                                    gUnk_030017A0[slot].unk6, 2, 0x64, 0x18, 0x40, 0, 2, 0);
    else
        clear_sprite_table_mask(0x64, 4);
}

static void sub_0800AF64(void) {
    u32 slot = get_medal_active_slot(gUnk_03000440.unk3D);

    if (slot != 0xFF) {
        if (gUnk_030017A0[slot].unk6 < 0x78) {
            load_part_data(gUnk_030017A0[slot].unk6, 3, gUnk_03000440.unk10E);
            draw_tilemap_with_offset(gUnk_03000440.unk10E[1] - 100, 2, 10, REG_BG1CNT, 0x83A0);
        } else {
            draw_tilemap_with_offset(0xFF, 2, 10, REG_BG1CNT, 0x83A0);
        }
    } else {
        draw_tilemap_with_offset(0xFF, 2, 10, REG_BG1CNT, 0x83A0);
    }
}

void render_medal_skill_stats(void) {
    draw_number_bgcnt(gUnk_03000BE0[gUnk_03000440.unk3D].unk20[0], 11, 9, 3, REG_BG1CNT, 0xC3C4);
    draw_number_bgcnt(gUnk_03000BE0[gUnk_03000440.unk3D].unk20[1], 11, 12, 3, REG_BG1CNT, 0xC3C4);
    draw_number_bgcnt(gUnk_03000BE0[gUnk_03000440.unk3D].unk20[2], 25, 9, 3, REG_BG1CNT, 0xC3C4);
    draw_number_bgcnt(gUnk_03000BE0[gUnk_03000440.unk3D].unk20[3], 25, 12, 3, REG_BG1CNT, 0xC3C4);
    draw_number_bgcnt(gUnk_03000BE0[gUnk_03000440.unk3D].unk20[4], 11, 15, 3, REG_BG1CNT, 0xC3C4);
    draw_number_bgcnt(gUnk_03000BE0[gUnk_03000440.unk3D].unk20[5], 11, 18, 3, REG_BG1CNT, 0xC3C4);
    draw_number_bgcnt(gUnk_03000BE0[gUnk_03000440.unk3D].unk20[6], 25, 15, 3, REG_BG1CNT, 0xC3C4);
    draw_number_bgcnt(gUnk_03000BE0[gUnk_03000440.unk3D].unk20[7], 25, 18, 3, REG_BG1CNT, 0xC3C4);
}

void sub_0800B0F8(void) {
    u32 i;

    for (i = 0; i < 5; i++)
        CpuFastSet(gUnk_084C3B14 + (i * 0x100 + gUnk_03000440.unk3F * 0x20), (void *)0x06007A00 + i * 0x20, 8);
}

static void sub_0800B130(void) {
    if (++gUnk_03000440.unk48 > 180 && gUnk_03000440.unk48 & 1) {
        sub_0800B0F8();
        if (++gUnk_03000440.unk3F == 8) {
            gUnk_03000440.unk48 = 0;
            gUnk_03000440.unk3F = 0;
        }
    }
}

void draw_medal_skill_bars(void) {
    u32 i;

    for (i = 0; i < 8; i++) {
        if (gUnk_03000BE0[gUnk_03000440.unk3D].unk28[0] > i)
            draw_tile_block(1, 1, i + 2, 9, REG_BG1CNT, 0xD3D0);
        else
            vram_fill_tilemap_rect(1, 1, i + 2, 9, REG_BG1CNT, 0);
    }

    for (i = 0; i < 8; i++) {
        if (gUnk_03000BE0[gUnk_03000440.unk3D].unk28[1] > i)
            draw_tile_block(1, 1, i + 2, 12, REG_BG1CNT, 0xD3D0);
        else
            vram_fill_tilemap_rect(1, 1, i + 2, 12, REG_BG1CNT, 0);
    }

    for (i = 0; i < 8; i++) {
        if (gUnk_03000BE0[gUnk_03000440.unk3D].unk28[2] > i)
            draw_tile_block(1, 1, i + 16, 9, REG_BG1CNT, 0xD3D3);
        else
            vram_fill_tilemap_rect(1, 1, i + 16, 9, REG_BG1CNT, 0);
    }

    for (i = 0; i < 8; i++) {
        if (gUnk_03000BE0[gUnk_03000440.unk3D].unk28[3] > i)
            draw_tile_block(1, 1, i + 16, 12, REG_BG1CNT, 0xD3D3);
        else
            vram_fill_tilemap_rect(1, 1, i + 16, 12, REG_BG1CNT, 0);
    }

    for (i = 0; i < 8; i++) {
        if (gUnk_03000BE0[gUnk_03000440.unk3D].unk28[4] > i)
            draw_tile_block(1, 1, i + 2, 15, REG_BG1CNT, 0xD3D1);
        else
            vram_fill_tilemap_rect(1, 1, i + 2, 15, REG_BG1CNT, 0);
    }

    for (i = 0; i < 8; i++) {
        if (gUnk_03000BE0[gUnk_03000440.unk3D].unk28[5] > i)
            draw_tile_block(1, 1, i + 2, 18, REG_BG1CNT, 0xD3D2);
        else
            vram_fill_tilemap_rect(1, 1, i + 2, 18, REG_BG1CNT, 0);
    }

    for (i = 0; i < 8; i++) {
        if (gUnk_03000BE0[gUnk_03000440.unk3D].unk28[6] > i)
            draw_tile_block(1, 1, i + 16, 15, REG_BG1CNT, 0xD3D4);
        else
            vram_fill_tilemap_rect(1, 1, i + 16, 15, REG_BG1CNT, 0);
    }

    for (i = 0; i < 8; i++) {
        if (gUnk_03000BE0[gUnk_03000440.unk3D].unk28[7] > i)
            draw_tile_block(1, 1, i + 16, 18, REG_BG1CNT, 0xD3D0);
        else
            vram_fill_tilemap_rect(1, 1, i + 16, 18, REG_BG1CNT, 0);
    }
}

static void medal_skill_redraw(void) {
    if (KEYS_LO(gRepeatKeys) & 0x30) {
        medal_skill_draw_icon();
        medal_page_draw_kind_name();
        medal_page_draw_name();
        medal_skill_draw_level();
        render_medal_skill_stats();
        draw_medal_skill_bars();
    }
}

void sub_0800B498(void) {
    u32 i;

    gUnk_03000590[gUnk_03001800.unk80].medal.unk9 = gUnk_03000BE0[gUnk_03000440.unk3D].unk9;
    for (i = 0; i < 8; i++)
        gUnk_03000590[gUnk_03001800.unk80].medal.unk18[i] = gUnk_03000BE0[gUnk_03000440.unk3D].unk18[i];
}

static void increment_medal_level_on_input(void) {
    if (gUnk_03000BE0[gUnk_03000440.unk3D].unk0 & 0x80 && KEYS_LO(gHeldKeys) & 8 && KEYS_HI(gRepeatKeys) & 2 &&
        gUnk_03000BE0[gUnk_03000440.unk3D].unk5 != 100) {
        gUnk_03000BE0[gUnk_03000440.unk3D].unk5++;
        memcpy_bytes_08041D04(gUnk_083B6158[gUnk_03000BE0[gUnk_03000440.unk3D].unk1], &gUnk_03000440.unkEE, 16);
        gUnk_03000BE0[gUnk_03000440.unk3D].unk8 =
            medal_tier_for_level(gUnk_03000BE0[gUnk_03000440.unk3D].unk5, gUnk_03000440.unkF1, gUnk_03000440.unkF2,
                                 gUnk_03000440.unkF3, gUnk_03000440.unkF4);
        load_medal_sprite();
        render_medal_slots_in_menu();
    }
}

static void handle_medal_level_down_input(void) {
    if (gUnk_03000BE0[gUnk_03000440.unk3D].unk0 & 0x80 && KEYS_LO(gHeldKeys) & 8 && KEYS_HI(gRepeatKeys) & 1 &&
        gUnk_03000BE0[gUnk_03000440.unk3D].unk2 > 99) {
        gUnk_03000BE0[gUnk_03000440.unk3D].unk2 -= 100;
        render_medal_level_display();
    }
}

void setup_battle_cursor_sprite_0800B5E8(void) {
    gSpriteEntries[127].unk0 = 0xC804;
    gSpriteEntries[127].unk2 = gUnk_083AC8AC[gUnk_03000440.unk48 * 2];
    gSpriteEntries[127].unk4 = gUnk_083AC8AC[gUnk_03000440.unk48 * 2 + 1];
    gSpriteEntries[127].unk6 = 0x303;
    gSpriteEntries[127].unkA = 0xE;
    gSpriteEntries[127].unk1C = 0;
    gSpriteEntries[127].unkB = 0x40;
}

static void init_battle_cursor_sprite_0800B668(void) {
    gSpriteEntries[7].unk0 = 0xD204;
    gSpriteEntries[7].unk2 = 0xA8;
    gSpriteEntries[7].unk4 = gUnk_03000440.unk4A * 16 + 0x70;
    gSpriteEntries[7].unk6 = 0x307;
    gSpriteEntries[7].unkA = 0xE;
    gSpriteEntries[7].unk8 = 0x40;
    gSpriteEntries[7].unk9 = 0x40;
    gSpriteEntries[7].unk1C = 0;
    gSpriteEntries[7].unk29 = 0;
    gSpriteEntries[7].unk27 = 0;
    gSpriteEntries[7].unkB = 0xC1;
}

static void handle_menu_cursor_updown(void) {
    if (KEYS_LO(gRepeatKeys) & 0x40) {
        if (gUnk_03000440.unk4A == 0)
            gUnk_03000440.unk4A = 2;
        else
            gUnk_03000440.unk4A--;
    }
    if (KEYS_LO(gRepeatKeys) & 0x80) {
        if (gUnk_03000440.unk4A == 2)
            gUnk_03000440.unk4A = 0;
        else
            gUnk_03000440.unk4A++;
    }
    if (KEYS_LO(gRepeatKeys) & 0xC0) {
        play_sound_effect(2);
        gSpriteEntries[7].unk4 = gUnk_03000440.unk4A * 16 + 0x70;
    }
}

u32 update_battle_sprite_and_check_done(void) {
    gUnk_083AC8CC[gSpriteEntries[7].unk29]();
    if (gSpriteEntries[7].unk29 == 3)
        return 1;
    return 0;
}

void update_sprite_blink_animation(void) {
    if (gSpriteEntries[7].unk27 != 30) {
        if (gSpriteEntries[7].unk27 & 4)
            gSpriteEntries[7].unk0 &= 0xBFFF;
        else
            gSpriteEntries[7].unk0 |= 0x4000;
        gSpriteEntries[7].unk27++;
    } else {
        gSpriteEntries[7].unk0 |= 0x4000;
        gSpriteEntries[7].unk29++;
    }
}

void update_battle_sprite_scroll(void) {
    gSpriteEntries[7].unk8 -= 8;
    gSpriteEntries[7].unk9 -= 8;
    if (gSpriteEntries[7].unk8 == 0) {
        clear_sprite_table_mask(7, 1);
        gSpriteEntries[7].unk29++;
    }
}

void fill_bg0_rect_and_advance_sprite_state(void) {
    vram_fill_tilemap_rect(12, 8, 18, 12, REG_BG0CNT, 0);
    gSpriteEntries[7].unk29++;
}
