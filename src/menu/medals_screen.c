// Game state 4: the Medals screen (Medawatch > Medals): the Medal list, a Medal's pages (Ability, Medaforce,
// Rotation, Skill), the START help, and the drawing helpers for Medal sprites, names, levels and skill bars.

#include "global.h"
#include "constants/sprites.h"

// gSpriteEntries work[] indices
#define MEDALS_SPR_BLINK_TIMER 0x7 // trade choice cursor (sprite 7): blink frames, 0-30
#define MEDALS_SPR_CLOSE_STEP 0x9  // trade choice cursor: gMedalTradeChoiceCloseSteps index

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
static void medals_list_update_swap_marker(void);
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
// Moves the help cursor sprite to entry helpPage.
static void medals_help_move_cursor(void);
// Arrow path under the slots for the Repetition count (MedalData.rotationLen).
static void medal_rotation_draw_repeat_path(void);
static void medal_rotation_redraw(void);
// Up/down arrow sprites 1-2 above and below action slot pageCursor.
static void medal_rotation_init_slot_arrows(void);
// Repetition cursor sprite 3 at slot rotationLen.
static void medal_rotation_init_repeat_cursor(void);
static void medal_rotation_blink_slot_arrows(void);
// UP/DOWN cycles the action (0-7) in slot pageCursor; returns 1 on change.
static u32 medal_rotation_action_input(void);
// LEFT/RIGHT moves the slot cursor pageCursor (0-7); returns 1 on change.
static u32 medal_rotation_slot_input(void);
// LEFT/RIGHT changes the Repetition count (MedalData.rotationLen, 0-7); returns 1 on change.
static u32 medal_rotation_repeat_input(void);
// The next three show the Medabot the Medal is set in (nothing if it's in none).
static void medal_page_load_bot_gfx(void);
static void medal_page_draw_bot_sprite(void);
// guess: legs type icon (load_part_data kind 3 of the legs part)
static void medal_page_draw_bot_legs_type(void);
// guess: a shine sweep over the Skill page, a frame every 2 ticks after 180 ticks
static void medal_skill_animate_shine(void);
static void medal_skill_redraw(void);
static void medal_trade_init_choice_cursor(void);
static void medal_trade_choice_cursor_input(void);

// Game state 4: the Medals screen (runtime-checked from Medawatch > Medals). Sub-states 0-5 = Medal
// list (listTab tab, medalRow row); A opens a Medal's pages, L/R cycle medalPage: 8.. Ability, 24.. Medaforce,
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
    lz_decompress_dispatch(gMedalsListBgTiles, (void *)0x06004000);
    lz_decompress_dispatch(gMedalsTabNumberTiles, (void *)0x06006000);
    lz_decompress_dispatch(gSmallDigitTiles, (void *)0x06006280);
    lz_decompress_dispatch(gLegTypePedestalTiles, (void *)0x06007400);
    lz_decompress_dispatch(gLegTypePedestalTiles2, (void *)0x06007600);
    lz_decompress_dispatch(gSpriteFontTiles, (void *)0x06017400);
    lz_decompress_dispatch(gCursorArrowTiles, (void *)0x06017E00);
    lz_decompress_dispatch(gTradeChoiceWindowTiles, (void *)0x06006A00);
    set_tilemap_and_decompress_bg(0, 0, gMedalsListBg0Tilemap, REG_BG0CNT, 0x200);
    set_tilemap_and_decompress_bg(0, 0, gMedalsListBg1Tilemap, REG_BG1CNT, 0x200);
    set_tilemap_and_decompress_bg(0, 0, gMedalsListBg2Tilemap, REG_BG2CNT, 0x200);
    set_tilemap_and_decompress_bg(0, 0, gMedalsListBg3Tilemap, REG_BG3CNT, 0x200);
    CpuFastSet(gMedalsListBgPalette, (void *)0x05000000, 0x70);
    CpuFastSet(gTradeChoiceWindowPalette, (void *)0x05000160, 8);
    CpuFastSet(gMenuObjPalettes, (void *)0x05000200, 0x40);
    CpuFastSet(gGradientPaletteOlive, (void *)0x05000300, 8);
    CpuFastSet(gGradientPaletteOlive - 0x20, (void *)0x05000320, 8);
    CpuFastSet(gCommonObjPalette, (void *)0x050003A0, 8);
    CpuFastSet(gGradientPaletteOlive + 0x60, (void *)0x05000340, 8);
    CpuFastSet(gCursorArrowPalette, (void *)0x050003C0, 8);
    zero = 0;
    CpuFastSet(&zero, gSpriteEntries, 0x01000800);
    REG_DISPCNT |= 0x1F60;
    medals_list_set_cursor_from_medal();
    write_tilemap_rect(10, 2, 5, 2, gUiTilemaps[gGameWork.listTab + 0x4B], REG_BG1CNT, 0x200);
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
    if (gGameWork.openedFrom == 4 && gGameWork.medalsSongStarted == 0) {
        gGameWork.medalsSongStarted = 1;
        play_song(7);
    }
    gGameWork.stepCounter = 0;
    gGameSubState++;
}

void medals_list_fade_in(void) {
    medals_scroll_bg();
    medals_list_blink_tab_arrows();
    sprite_bob_x(3, gFrameCounter, 0x18);
    if (update_blend_effect())
        gGameSubState++;
}

void medals_list_handle_input(void) {
    u8 cancel_pressed;

    medals_scroll_bg();
    medals_list_blink_tab_arrows();
    sprite_bob_x(3, gFrameCounter, 0x18);
    medals_list_update_swap_marker();
    medals_list_row_input();
    medals_list_tab_input();
    medals_list_swap_input();
    if ((cancel_pressed = KEYS_LO(gNewKeys) & 2)) {
        if (gGameWork.partSlot & 0x80) {
            play_sound_effect(2);
            gGameWork.partSlot = 0;
            medals_list_update_swap_marker();
        } else {
            play_sound_effect(5);
            gGameSubState++;
        }
    } else if (KEYS_LO(gNewKeys) & 1) {
        gGameWork.shownId = gGameWork.listTab * 6 + gGameWork.medalRow;
        if (gMedals[gGameWork.shownId].flags & 0x80) {
            play_sound_effect(4);
            if (gGameWork.openedFrom == 4)
                gGameSubState = 0x60;
            else {
                gGameWork.medalPage = cancel_pressed;
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
    sprite_bob_x(3, gFrameCounter, 0x18);
    gGameSubState++;
}

void medals_list_wait_fade(void) {
    medals_scroll_bg();
    medals_list_blink_tab_arrows();
    sprite_bob_x(3, gFrameCounter, 0x18);
    if (update_blend_effect())
        gGameSubState++;
}

void medals_list_exit(void) {
    clear_battle_sprite_slot(0, 0x80);
    if (gGameWork.openedFrom == 4)
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
    lz_decompress_dispatch(gMedalAbilityBgTiles, (void *)0x06004000);
    lz_decompress_dispatch(gSmallDigitTiles, (void *)0x06006280);
    lz_decompress_dispatch(gCompatibilityIconTiles, (void *)0x06006800);
    lz_decompress_dispatch(gCursorArrowTiles, (void *)0x06017E00);
    set_tilemap_and_decompress_bg(0, 0, gMedalAbilityBg0Tilemap, REG_BG0CNT, 0x200);
    set_tilemap_and_decompress_bg(0, 0, gMedalAbilityBg1Tilemap, REG_BG1CNT, 0x200);
    set_tilemap_and_decompress_bg(0, 0, gMedalAbilityBg2Tilemap, REG_BG2CNT, 0x200);
    set_tilemap_and_decompress_bg(0, 0, gMedalAbilityBg3Tilemap, REG_BG3CNT, 0x200);
    CpuFastSet(gMedalAbilityBgPalette, (void *)0x05000000, 0x70);
    CpuFastSet(gGradientPaletteOlive + 0x70, (void *)0x05000340, 8);
    CpuFastSet(gGradientPaletteOlive + 0x40, (void *)0x05000360, 8);
    CpuFastSet(gGradientPaletteOlive - 0x20, (void *)0x05000380, 8);
    CpuFastSet(gGradientPaletteOlive - 0x10, (void *)0x050003A0, 8);
    CpuFastSet(gCursorArrowPalette, (void *)0x050003C0, 8);
    zero = 0;
    CpuFastSet(&zero, gSpriteEntries, 0x01000800);
    REG_DISPCNT |= 0x1F60;
    gGameWork.helpPage = 0;
    medal_page_draw_icon();
    medal_page_draw_kind_name();
    medal_page_draw_name();
    medal_page_draw_level();
    medal_ability_draw_attribute();
    medal_ability_draw_aim();
    medal_ability_draw_compatibility();
    medal_page_init_medal_arrows();
    set_blend_effect_mode(5, 0x3F, 0x20);
    gGameWork.stepCounter = 0;
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
    if (run_message(gMenuMessages[4]))
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
        gGameWork.medalPage = (gGameWork.medalPage - 1) & 3;
        gGameSubState = 0x14;
    } else if (*((u8 *)&gNewKeys + 1) & 1) {
        play_sound_effect(2);
        gGameWork.medalPage = (gGameWork.medalPage + 1) & 3;
        gGameSubState = 0x14;
    } else if (KEYS_LO(gNewKeys) & 8) {
        play_sound_effect(4);
        gGameWork.helpFromPage = 0;
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
    switch (gGameWork.openedFrom) {
    case 1:
        gGameWork.shownMedal = gGameWork.shownId;
        gGameState = 3;
        gGameSubState = 0x10;
        break;
    case 2:
        medal_rotation_store_to_battle_bot();
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
    switch (gGameWork.medalPage) {
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
    lz_decompress_dispatch(gMedalMedaforceBgTiles, (void *)0x06004000);
    lz_decompress_dispatch(gSmallDigitTiles, (void *)0x06006280);
    lz_decompress_dispatch(gMedaforceTypeIconTiles, (void *)0x06006000);
    lz_decompress_dispatch(gMedaforceGaugeTiles, (void *)0x06006680);
    lz_decompress_dispatch(gCursorArrowTiles, (void *)0x06017E00);
    set_tilemap_and_decompress_bg(0, 0, gMedalMedaforceBg0Tilemap, REG_BG0CNT, 0x200);
    set_tilemap_and_decompress_bg(0, 0, gMedalMedaforceBg1Tilemap, REG_BG1CNT, 0x200);
    set_tilemap_and_decompress_bg(0, 0, gMedalMedaforceBg2Tilemap, REG_BG2CNT, 0x200);
    set_tilemap_and_decompress_bg(0, 0, gMedalMedaforceBg3Tilemap, REG_BG3CNT, 0x200);
    CpuFastSet(gMedalMedaforceBgPalette, (void *)0x05000000, 0x70);
    CpuFastSet(gGradientPaletteOlive + 0x30, (void *)0x05000340, 8);
    CpuFastSet(gGradientPaletteOlive + 0x40, (void *)0x05000360, 8);
    CpuFastSet(gGradientPaletteOlive - 0x20, (void *)0x05000380, 8);
    CpuFastSet(gGradientPaletteOlive - 0x10, (void *)0x050003A0, 8);
    CpuFastSet(gCursorArrowPalette, (void *)0x050003C0, 8);
    zero = 0;
    CpuFastSet(&zero, gSpriteEntries, 0x01000800);
    REG_DISPCNT |= 0x1F60;
    gGameWork.helpPage = 0;
    gGameWork.pageCursor = 0;
    medal_page_draw_icon();
    medal_page_draw_kind_name();
    medal_page_draw_name();
    medal_page_draw_level();
    medal_page_init_medal_arrows();
    medal_medaforce_draw_list();
    medal_medaforce_draw_selected();
    medal_medaforce_init_cursor();
    set_blend_effect_mode(5, 0x3F, 0x20);
    gGameWork.stepCounter = 0;
    gGameSubState++;
}

void medal_medaforce_wait_fade(void) {
    medals_scroll_bg();
    medal_page_blink_medal_arrows();
    sprite_bob_x(3, gFrameCounter, 8);
    if (update_blend_effect())
        gGameSubState++;
}

void medal_medaforce_open_text_window(void) {
    medals_scroll_bg();
    medal_page_blink_medal_arrows();
    sprite_bob_x(3, gFrameCounter, 8);
    text_window_init(1, 2, 0);
    gGameSubState++;
}

void medal_medaforce_show_message(void) {
    medals_scroll_bg();
    medal_page_blink_medal_arrows();
    sprite_bob_x(3, gFrameCounter, 8);
    if (run_message(gMedaforceDescMessages[medal_medaforce_get_selected()]))
        gGameSubState++;
}

void medal_medaforce_handle_input(void) {
    medals_scroll_bg();
    medal_page_blink_medal_arrows();
    sprite_bob_x(3, gFrameCounter, 8);
    if (medal_medaforce_cursor_input()) {
        message_next();
        gGameSubState++;
        return;
    }
    medal_page_cycle_medal_input();
    if (medal_medaforce_redraw()) {
        message_next();
        gGameSubState++;
    } else if (KEYS_LO(gNewKeys) & 2) {
        play_sound_effect(5);
        gGameSubState = 0x1E;
    } else if (*((u8 *)&gNewKeys + 1) & 2) {
        play_sound_effect(2);
        gGameWork.medalPage = (gGameWork.medalPage - 1) & 3;
        gGameSubState = 0x24;
    } else if (*((u8 *)&gNewKeys + 1) & 1) {
        play_sound_effect(2);
        gGameWork.medalPage = (gGameWork.medalPage + 1) & 3;
        gGameSubState = 0x24;
    } else if (KEYS_LO(gNewKeys) & 8) {
        play_sound_effect(4);
        gGameWork.helpFromPage = 1;
        gGameSubState = 0x48;
    }
}

void medal_medaforce_show_message_back(void) {
    medals_scroll_bg();
    medal_page_blink_medal_arrows();
    sprite_bob_x(3, gFrameCounter, 8);
    if (run_message(gMedaforceDescMessages[medal_medaforce_get_selected()]))
        gGameSubState--;
}

void medal_medaforce_start_fade_out(void) {
    set_blend_effect_mode(6, 0x3F, 0x20);
    medals_scroll_bg();
    medal_page_blink_medal_arrows();
    sprite_bob_x(3, gFrameCounter, 8);
    gGameSubState++;
}

void medal_rotation_load_gfx(void) {
    u32 zero;

    REG_DISPCNT &= 0xF0FF;
    REG_BG0CNT = 0x500;
    REG_BG1CNT = 0x1801;
    REG_BG2CNT = 0x1902;
    REG_BG3CNT = 0x1A03;
    lz_decompress_dispatch(gMedalRotationBgTiles, (void *)0x06004000);
    lz_decompress_dispatch(gSmallDigitTiles, (void *)0x06006280);
    lz_decompress_dispatch(gRotationActionIconTiles, (void *)0x06006800);
    lz_decompress_dispatch(gRotationPathTiles, (void *)0x06006C00);
    lz_decompress_dispatch(gLegTypePedestalTiles, (void *)0x06007400);
    lz_decompress_dispatch(gLegTypePedestalTiles2, (void *)0x06007600);
    lz_decompress_dispatch(gCursorArrowTiles, (void *)0x06017E00);
    set_tilemap_and_decompress_bg(0, 0, gMedalRotationBg0Tilemap, REG_BG0CNT, 0x200);
    set_tilemap_and_decompress_bg(0, 0, gMedalRotationBg1Tilemap, REG_BG1CNT, 0x200);
    set_tilemap_and_decompress_bg(0, 0, gMedalRotationBg2Tilemap, REG_BG2CNT, 0x200);
    set_tilemap_and_decompress_bg(0, 0, gMedalRotationBg3Tilemap, REG_BG3CNT, 0x200);
    CpuFastSet(gMedalRotationBgPalette, (void *)0x05000000, 0x70);
    CpuFastSet(gMenuObjPalettes, (void *)0x05000200, 0x40);
    CpuFastSet(gGradientPaletteGold, (void *)0x05000380, 8);
    CpuFastSet(gGradientPaletteGold + 0x10, (void *)0x050003A0, 8);
    CpuFastSet(gCursorArrowPalette, (void *)0x050003C0, 8);
    zero = 0;
    CpuFastSet(&zero, gSpriteEntries, 0x01000800);
    REG_DISPCNT |= 0x1F60;
    gGameWork.helpPage = 0;
    gGameWork.pageCursor = 0;
    medal_page_draw_icon();
    medal_page_draw_kind_name();
    medal_page_draw_name();
    medal_page_draw_level();
    medal_page_init_medal_arrows();
    medal_rotation_draw_actions();
    medal_rotation_draw_repeat_path();
    medal_page_load_bot_gfx();
    medal_page_draw_bot_sprite();
    medal_page_draw_bot_legs_type();
    set_blend_effect_mode(5, 0x3F, 0x20);
    gGameWork.stepCounter = 0;
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
    if (run_message(gMenuMessages[12]))
        gGameSubState++;
}

void medal_rotation_handle_input(void) {
    medals_scroll_bg();
    medal_page_blink_medal_arrows();
    medal_page_cycle_medal_input();
    medal_rotation_redraw();
    if (KEYS_LO(gNewKeys) & 1) {
        play_sound_effect(4);
        disable_sprites(1, 2);
        gGameWork.pageCursor = 0;
        gGameWork.listTab = 0;
        gGameSubState = 0x30;
    } else if (KEYS_LO(gNewKeys) & 2) {
        play_sound_effect(5);
        gGameSubState++;
    } else if (*((u8 *)&gNewKeys + 1) & 2) {
        play_sound_effect(2);
        gGameWork.medalPage = (gGameWork.medalPage - 1) & 3;
        gGameSubState = 0x34;
    } else if (*((u8 *)&gNewKeys + 1) & 1) {
        play_sound_effect(2);
        gGameWork.medalPage = (gGameWork.medalPage + 1) & 3;
        gGameSubState = 0x34;
    } else if (KEYS_LO(gNewKeys) & 8) {
        play_sound_effect(4);
        gGameWork.helpFromPage = 2;
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
    if (gGameWork.listTab == 0)
        medal_rotation_init_slot_arrows();
    else
        medal_rotation_init_repeat_cursor();
    message_next();
    gGameSubState++;
}

void medal_rotation_edit_show_message(void) {
    const void *msg;

    medals_scroll_bg();
    if (gGameWork.listTab == 0) {
        medal_rotation_blink_slot_arrows();
        msg = gRotationActionMessages[gMedals[gGameWork.shownId].rotation[gGameWork.pageCursor]];
    } else {
        msg = gMenuMessages[15];
    }
    if (run_message(msg))
        gGameSubState++;
}

void medal_rotation_edit_input(void) {
    medals_scroll_bg();
    if (gGameWork.listTab == 0) {
        medal_rotation_blink_slot_arrows();
        if (medal_rotation_action_input()) {
            medal_rotation_draw_actions();
            message_next();
            gGameSubState--;
            return;
        }
        if (medal_rotation_slot_input()) {
            message_next();
            gGameSubState--;
            return;
        }
        if (KEYS_LO(gNewKeys) & 1) {
            play_sound_effect(4);
            disable_sprites(1, 2);
            medal_rotation_init_repeat_cursor();
            message_next();
            gGameWork.listTab = 1;
            gGameSubState--;
            return;
        }
        if (KEYS_LO(gNewKeys) & 2) {
            play_sound_effect(5);
            disable_sprites(1, 2);
            gGameWork.pageCursor = 0;
            medal_page_init_medal_arrows();
            message_next();
            gGameSubState = 0x2B;
            return;
        }
    } else {
        sprite_bob_y(3, gFrameCounter, 0x30);
        if (medal_rotation_repeat_input()) {
            medal_rotation_draw_actions();
            medal_rotation_draw_repeat_path();
            medal_rotation_init_repeat_cursor();
            return;
        }
        if (KEYS_LO(gNewKeys) & 1) {
            play_sound_effect(4);
            disable_sprites(3, 1);
            gGameWork.pageCursor = 0;
            medal_page_init_medal_arrows();
            message_next();
            gGameSubState = 0x2B;
            return;
        }
        if (KEYS_LO(gNewKeys) & 2) {
            play_sound_effect(5);
            disable_sprites(3, 1);
            medal_rotation_init_slot_arrows();
            message_next();
            gGameWork.listTab = 0;
            gGameSubState--;
            return;
        }
    }
    if (KEYS_LO(gNewKeys) & 8) {
        play_sound_effect(4);
        gGameWork.pageCursor |= 0x80;
        gGameWork.helpFromPage = 2;
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
    lz_decompress_dispatch(gMedalSkillBgTiles, (void *)0x06004000);
    lz_decompress_dispatch(gSmallDigitTiles, (void *)0x06007480);
    lz_decompress_dispatch(gMedaforceGaugeTiles, (void *)0x06007880);
    lz_decompress_dispatch(gCursorArrowTiles, (void *)0x06017E00);
    set_tilemap_and_decompress_bg(0, 0, gMedalSkillBg0Tilemap, REG_BG0CNT, 0x200);
    set_tilemap_and_decompress_bg(0, 0, gMedalSkillBg1Tilemap, REG_BG1CNT, 0x200);
    set_tilemap_and_decompress_bg(0, 0, gMedalSkillBg2Tilemap, REG_BG2CNT, 0x200);
    set_tilemap_and_decompress_bg(0, 0, gMedalSkillBg3Tilemap, REG_BG3CNT, 0x200);
    CpuFastSet(gMedalSkillBgPalette, (void *)0x05000000, 0x70);
    CpuFastSet(gGradientPaletteGold, (void *)0x05000380, 8);
    CpuFastSet(gGradientPaletteGold + 0x10, (void *)0x050003A0, 8);
    CpuFastSet(gCursorArrowPalette, (void *)0x050003C0, 8);
    zero = 0;
    CpuFastSet(&zero, gSpriteEntries, 0x01000800);
    REG_DISPCNT |= 0x1F60;
    gGameWork.subCounter = 0;
    gGameWork.listTab = 0;
    medal_skill_draw_icon();
    medal_page_draw_kind_name();
    medal_page_draw_name();
    medal_skill_draw_level();
    medal_page_init_medal_arrows();
    render_medal_skill_stats();
    medal_skill_load_shine_frame();
    draw_medal_skill_bars();
    set_blend_effect_mode(5, 0x3F, 0x20);
    gGameWork.stepCounter = 0;
    gGameSubState++;
}

void medal_skill_wait_fade(void) {
    medals_scroll_bg();
    medal_page_blink_medal_arrows();
    medal_skill_animate_shine();
    if (update_blend_effect())
        gGameSubState++;
}

void medal_skill_handle_input(void) {
    medals_scroll_bg();
    medal_page_blink_medal_arrows();
    medal_skill_animate_shine();
    medal_page_cycle_medal_input();
    medal_skill_redraw();
    if (KEYS_LO(gNewKeys) & 2) {
        play_sound_effect(5);
        gGameSubState++;
    } else if (*((u8 *)&gNewKeys + 1) & 2) {
        play_sound_effect(2);
        gGameWork.medalPage = (gGameWork.medalPage - 1) & 3;
        gGameSubState = 0x44;
    } else if (*((u8 *)&gNewKeys + 1) & 1) {
        play_sound_effect(2);
        gGameWork.medalPage = (gGameWork.medalPage + 1) & 3;
        gGameSubState = 0x44;
    }
}

void medal_skill_start_fade_out(void) {
    set_blend_effect_mode(6, 0x3F, 0x20);
    medals_scroll_bg();
    medal_page_blink_medal_arrows();
    medal_skill_animate_shine();
    gGameSubState++;
}

// Debug Skill level editor (sub-state 64, no handler jumps there; UP/DOWN pick a skill, RIGHT/LEFT change its level,
// SELECT, B -> 58)
void medal_skill_debug_edit_input(void) {
    u8 up_pressed;

    medal_skill_debug_init_cursor();
    if ((up_pressed = KEYS_LO(gRepeatKeys) & 0x40)) {
        if (gGameWork.subCounter == 0)
            gGameWork.subCounter = 7;
        else
            gGameWork.subCounter--;
    } else if (KEYS_LO(gRepeatKeys) & 0x80) {
        if (gGameWork.subCounter == 7)
            gGameWork.subCounter = up_pressed;
        else
            gGameWork.subCounter++;
    } else if (KEYS_LO(gRepeatKeys) & 0x10 && gMedals[gGameWork.shownId].skillLevel[gGameWork.subCounter] != 100) {
        gMedals[gGameWork.shownId].skillLevel[gGameWork.subCounter]++;
        render_medal_skill_stats();
    } else if (KEYS_LO(gRepeatKeys) & 0x20 && gMedals[gGameWork.shownId].skillLevel[gGameWork.subCounter] != 0) {
        gMedals[gGameWork.shownId].skillLevel[gGameWork.subCounter]--;
        render_medal_skill_stats();
    } else if (KEYS_LO(gNewKeys) & 4) {
        gMedals[gGameWork.shownId].skillExp[gGameWork.subCounter] = 7;
        draw_medal_skill_bars();
    } else if (KEYS_LO(gNewKeys) & 2) {
        clear_battle_sprite_slot(0x7F, 1);
        gGameSubState = 0x3A;
    }
}

void medals_help_load(void) {
    medals_scroll_bg();
    disable_sprites(1, 5);
    CpuFastSet(gHelpCursorPalette, (void *)0x050003C0, 8);
    medals_help_init_cursor();
    message_next();
    gGameSubState++;
}

void medals_help_show_intro(void) {
    medals_scroll_bg();
    if (run_message(gMenuMessages[5]))
        gGameSubState++;
}

void medals_help_cursor_input(void) {
    u8 up_pressed;

    medals_scroll_bg();
    process_sprite_anim_commands(gBattleSpriteAnimScripts[3], 6);
    if ((up_pressed = KEYS_LO(gRepeatKeys) & 0x40)) {
        if (gGameWork.helpPage == 0)
            gGameWork.helpPage = gGameWork.helpPageCount - 1;
        else
            gGameWork.helpPage--;
        goto moved;
    } else if (KEYS_LO(gRepeatKeys) & 0x80) {
        if (gGameWork.helpPage == gGameWork.helpPageCount - 1)
            gGameWork.helpPage = up_pressed;
        else
            gGameWork.helpPage++;
    moved:
        play_sound_effect(2);
        medals_help_move_cursor();
    } else if (KEYS_LO(gNewKeys) & 1) {
        play_sound_effect(4);
        medals_help_init_cursor();
        message_next();
        gGameSubState++;
    } else if (KEYS_LO(gNewKeys) & 0xA) {
        play_sound_effect(5);
        gGameSubState = 0x4E;
    }
}

void medals_help_show_text(void) {
    u8 done;

    medals_scroll_bg();
    switch (gGameWork.medalPage) {
    case 0:
        switch (gGameWork.helpPage) {
        case 0:
            done = run_message(gMenuMessages[6]);
            break;
        case 1:
            done = run_message(gMenuMessages[7]);
            break;
        case 2:
            done = run_message(gAttributeHelpMessages[gMedals[gGameWork.shownId].attribute]);
            break;
        case 3:
            done = run_message(gSkillTypeHelpMessages[gMedals[gGameWork.shownId].aimSkillType]);
            break;
        case 4:
            done = run_message(gMenuMessages[8]);
            break;
        }
        break;
    case 1:
        switch (gGameWork.helpPage) {
        case 0:
            if (gMedals[gGameWork.shownId].level > 9) {
                memcpy_bytes_08041D04(gMedalMedaforceIds + gMedals[gGameWork.shownId].graphicId * 3,
                                      &gGameWork.partAbility, 3);
                memcpy_bytes_08041D04(gMedaforceRecords + gGameWork.partAbility * 6, gGameWork.medalGfxRecord, 6);
                done = run_message(gMedaforceTypeHelpMessages[gGameWork.medalGfxRecord[5]]);
            } else {
                done = run_message(gMedaforceTypeHelpMessages[4]);
            }
            break;
        case 1:
            if (gMedals[gGameWork.shownId].level > 29) {
                memcpy_bytes_08041D04(gMedalMedaforceIds + gMedals[gGameWork.shownId].graphicId * 3,
                                      &gGameWork.partAbility, 3);
                memcpy_bytes_08041D04(gMedaforceRecords + gGameWork.partSkill * 6, gGameWork.medalGfxRecord, 6);
                done = run_message(gMedaforceTypeHelpMessages[gGameWork.medalGfxRecord[5]]);
            } else {
                done = run_message(gMedaforceTypeHelpMessages[4]);
            }
            break;
        case 2:
            if (gMedals[gGameWork.shownId].level > 59) {
                memcpy_bytes_08041D04(gMedalMedaforceIds + gMedals[gGameWork.shownId].graphicId * 3,
                                      &gGameWork.partAbility, 3);
                memcpy_bytes_08041D04(gMedaforceRecords + gGameWork.partSkillType * 6, gGameWork.medalGfxRecord, 6);
                done = run_message(gMedaforceTypeHelpMessages[gGameWork.medalGfxRecord[5]]);
            } else {
                done = run_message(gMedaforceTypeHelpMessages[4]);
            }
            break;
        case 3:
            done = run_message(gMenuMessages[9]);
            break;
        case 4:
            done = run_message(gMenuMessages[10]);
            break;
        case 5:
            switch (gGameWork.pageCursor) {
            case 0:
                if (gMedals[gGameWork.shownId].level > 9) {
                    memcpy_bytes_08041D04(gMedalMedaforceIds + gMedals[gGameWork.shownId].graphicId * 3,
                                          &gGameWork.partAbility, 3);
                    memcpy_bytes_08041D04(gMedaforceRecords + (&gGameWork.partAbility)[gGameWork.pageCursor] * 6,
                                          gGameWork.medalGfxRecord, 6);
                    done = run_message(gMedaforceSkillHelpMessages[gGameWork.medalGfxRecord[1]]);
                } else {
                    done = run_message(gMenuMessages[11]);
                }
                break;
            case 1:
                if (gMedals[gGameWork.shownId].level > 29) {
                    memcpy_bytes_08041D04(gMedalMedaforceIds + gMedals[gGameWork.shownId].graphicId * 3,
                                          &gGameWork.partAbility, 3);
                    memcpy_bytes_08041D04(gMedaforceRecords + (&gGameWork.partAbility)[gGameWork.pageCursor] * 6,
                                          gGameWork.medalGfxRecord, 6);
                    done = run_message(gMedaforceSkillHelpMessages[gGameWork.medalGfxRecord[1]]);
                } else {
                    done = run_message(gMenuMessages[11]);
                }
                break;
            case 2:
                if (gMedals[gGameWork.shownId].level > 59) {
                    memcpy_bytes_08041D04(gMedalMedaforceIds + gMedals[gGameWork.shownId].graphicId * 3,
                                          &gGameWork.partAbility, 3);
                    memcpy_bytes_08041D04(gMedaforceRecords + (&gGameWork.partAbility)[gGameWork.pageCursor] * 6,
                                          gGameWork.medalGfxRecord, 6);
                    done = run_message(gMedaforceSkillHelpMessages[gGameWork.medalGfxRecord[1]]);
                } else {
                    done = run_message(gMenuMessages[11]);
                }
                break;
            }
            break;
        }
        break;
    case 2:
        switch (gGameWork.helpPage) {
        case 0:
            done = run_message(gMenuMessages[13]);
            break;
        case 1:
            done = run_message(gMenuMessages[14]);
            break;
        }
        break;
    }
    if (done) {
        message_next();
        gGameSubState = 0x49;
    }
}

void medals_help_exit(void) {
    medals_scroll_bg();
    disable_sprites(6, 1);
    CpuFastSet(gCursorArrowPalette, (void *)0x050003C0, 8);
    switch (gGameWork.medalPage) {
    case 0:
        message_next();
        medal_page_init_medal_arrows();
        gGameSubState = 0xB;
        break;
    case 1:
        message_next();
        medal_page_init_medal_arrows();
        medal_medaforce_init_cursor();
        gGameSubState = 0x1B;
        break;
    case 2:
        if (gGameWork.pageCursor & 0x80) {
            gGameWork.pageCursor &= 0x7F;
            gGameSubState = 0x30;
        } else {
            message_next();
            medal_page_init_medal_arrows();
            gGameSubState = 0x2B;
        }
        break;
    }
}

// Medals screen sub-states 96-104: A on a Medal in link trade mode (openedFrom == 4) opens a 3-entry choice (cursor
// tradeChoice): 0 opens the Medal's pages, 1 offers it for trade, 2 goes back to the list. Code-read only (needs a link
// partner). guess: the refusal messages are gLinkMessages[9] for Medal flag 0x40 and [8] for a Medal kind the
// partner already has (gLinkTradeData is synced from the partner in link_medal_sync).
void medal_trade_choice_open(void) {
    medals_scroll_bg();
    medals_list_update_swap_marker();
    gSpriteEntries[1].flags &= (u16)~SPRITE_FLAG_VISIBLE;
    gSpriteEntries[2].flags &= (u16)~SPRITE_FLAG_VISIBLE;
    set_tilemap_and_decompress_bg(0x12, 0xC, gTradeChoiceWindowTilemap, REG_BG0CNT, 0x350);
    gGameWork.tradeChoice = 0;
    medal_trade_init_choice_cursor();
    gGameSubState++;
}

void medal_trade_choice_input(void) {
    medals_scroll_bg();
    medals_list_update_swap_marker();
    sprite_bob_x(7, gFrameCounter, 0xA8);
    medal_trade_choice_cursor_input();
    if (KEYS_LO(gNewKeys) & 1) {
        play_sound_effect(4);
    } else if (KEYS_LO(gNewKeys) & 2) {
        play_sound_effect(5);
        gGameWork.tradeChoice = 2;
    } else {
        return;
    }
    medal_trade_init_choice_cursor();
    gGameSubState++;
}

void medal_trade_choice_close(void) {
    medals_scroll_bg();
    medals_list_update_swap_marker();
    if (medal_trade_choice_close_step()) {
        disable_sprites(7, 1);
        gGameSubState++;
    }
}

void medal_trade_choice_dispatch(void) {
    medals_scroll_bg();
    medals_list_update_swap_marker();
    switch (gGameWork.tradeChoice) {
    case 0:
        gGameWork.medalPage = gGameWork.tradeChoice;
        set_blend_effect_mode(6, 0x3F, 0x20);
        gGameSubState = 7;
        break;
    case 1:
        gGameSubState++;
        break;
    case 2:
        gGameSubState = gGameWork.tradeChoice;
        break;
    }
}

void medal_trade_check_medal(void) {
    u32 bit;

    medals_scroll_bg();
    medals_list_update_swap_marker();
    if (gMedals[gGameWork.shownId].flags & 0x40) {
        text_window_init(1, 2, 0);
        gGameWork.stepCounter = 9;
        gGameSubState++;
    } else if ((bit = (1 << gMedals[gGameWork.shownId].graphicId) & gLinkTradeData)) {
        text_window_init(1, 2, 0);
        gGameWork.stepCounter = 8;
        gGameSubState++;
    } else {
        clear_battle_sprite_slot(5, 1);
        fade_out_music(8);
        gGameWork.partSlot = bit;
        gGameSubState = 0x68;
    }
}

void medal_trade_refused_message(void) {
    medals_scroll_bg();
    medals_list_update_swap_marker();
    if (run_message(gLinkMessages[gGameWork.stepCounter]))
        gGameSubState = 2;
}

void medal_trade_copy_medal(void) {
    memcpy_bytes_0803F63C(&gMedals[gGameWork.shownId], (void *)0x02023000, 0x40);
    gGameSubState++;
}

void medal_trade_enter_link(void) {
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
    gGameWork.listTab = gGameWork.shownId / 6;
    gGameWork.medalRow = gGameWork.shownId % 6;
}

static void count_owned_medals(void) {
    u32 i;

    gGameWork.freeMedalCount = 0;
    for (i = 0; i < 30; i++) {
        if (gMedals[i].flags & 0x80)
            gGameWork.freeMedalCount++;
    }
}

static void render_medal_sprite_tile(void) {
    u8 n = 0;
    u8 i;

    for (i = gGameWork.listTab * 6; i < gGameWork.listTab * 6 + 6; n++, i++) {
        if (gMedals[i].flags & 0x80)
            CpuFastSet(gMedalIconTiles + gMedals[i].graphicId * 0x80, (void *)0x06006600 + n * 0x80, 0x20);
        else
            CpuFastSet(gMedalIconBlankTiles, (void *)0x06006600 + n * 0x80, 0x20);
    }
    write_tilemap_rect(2, 12, 4, 4, gUiTilemaps[0x50], REG_BG1CNT, 0x200);
}

static void render_medal_list_entries(void) {
    u8 n = 0;
    u8 i;

    disable_sprites(10, 0x3C);
    for (i = gGameWork.listTab * 6; i < gGameWork.listTab * 6 + 6; n++, i++) {
        if (gMedals[i].flags & 0x80) {
            memcpy_bytes_0803F63C((void *)gMedalNames[gMedals[i].graphicId], gGameWork.textBuf, 11);
            render_text_sprites_08040DB8(gGameWork.textBuf, n * 10 + 10, 6, n * 2 + 4, 7, 8, 1, 2);
        } else {
            fill_text_blank(gGameWork.textBuf, 9);
            render_text_sprites_08040DB8(gGameWork.textBuf, n * 10 + 10, 6, n * 2 + 4, 7, 8, 1, 2);
        }
    }
}

static void render_medal_slots_in_menu(void) {
    u32 i;
    u32 n;

    for (n = 0, i = gGameWork.listTab * 6; i < gGameWork.listTab * 6 + 6; n++, i++) {
        if (gMedals[i].flags & 0x80) {
            fill_tilemap_pair_or_divide(gMedals[i].level, 14, (u8)(n * 2 + 4), REG_BG1CNT, 0xD314);
        } else {
            draw_tile_block(1, 2, 14, n * 2 + 4, REG_BG1CNT, 0xD32C);
            draw_tile_block(1, 2, 15, n * 2 + 4, REG_BG1CNT, 0xD32C);
        }
    }
}

static void render_medal_name_display(void) {
    u8 has;

    gGameWork.shownId = gGameWork.listTab * 6 + gGameWork.medalRow;
    disable_sprites(0x46, 10);
    if ((has = gMedals[gGameWork.shownId].flags & 0x80)) {
        render_text_sprites_08040DB8(gMedals[gGameWork.shownId].name, 0x46, 0x13, 3, 10, 9, 0, 2);
    } else {
        fill_text_blank(gGameWork.textBuf, 10);
        render_text_sprites_08040DB8(gGameWork.textBuf, 0x46, 0x13, 3, 10, 9, has, 2);
    }
}

void load_medal_sprite(void) {
    gGameWork.shownId = gGameWork.listTab * 6 + gGameWork.medalRow;
    if (gMedals[gGameWork.shownId].flags & 0x80) {
        lz_decompress_dispatch(
            gMedalSpriteGfx[gMedals[gGameWork.shownId].graphicId][gMedals[gGameWork.shownId].spriteVariant],
            (void *)0x06010000);
        gSpriteEntries[0].flags =
            SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(2) | SPRITE_FLAG_PART_PALETTE;
        gSpriteEntries[0].x = 0xC0;
        gSpriteEntries[0].y = 0x50;
        gSpriteEntries[0].frame = 0x200;
        gSpriteEntries[0].palette = 13;
        gSpriteEntries[0].frame_table = 0;
        gSpriteEntries[0].order = 0x40;
    } else {
        disable_sprites(0, 1);
    }
}

void render_medal_level_display(void) {
    u8 *buf;

    gGameWork.shownId = gGameWork.listTab * 6 + gGameWork.medalRow;
    disable_sprites(0x50, 6);
    if (gMedals[gGameWork.shownId].flags & 0x80) {
        if (gMedals[gGameWork.shownId].level != 100) {
            buf = gGameWork.textBuf;
            divide_by_100000_08041370(buf, gMedals[gGameWork.shownId].nextLevelExp);
        } else {
            buf = gGameWork.textBuf;
            fill_text_blank(buf, 5);
        }
        render_text_sprites_08040DB8(buf, 0x50, 0x13, 0x11, 6, 10, 2, 2);
    } else {
        buf = gGameWork.textBuf;
        fill_text_blank(buf, 5);
        render_text_sprites_08040DB8(buf, 0x50, 0x13, 0x11, 6, 10, 2, 2);
    }
}

static void medals_list_init_tab_arrows(void) {
    gSpriteEntries[1].flags = SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(2) | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[1].x = 0x24;
    gSpriteEntries[1].y = 0x18;
    gSpriteEntries[1].frame = 0x302;
    gSpriteEntries[1].palette = 14;
    gSpriteEntries[1].frame_table = 0;
    gSpriteEntries[1].order = 0x40;
    gSpriteEntries[2].flags = SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(2) | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[2].x = 0x7C;
    gSpriteEntries[2].y = 0x18;
    gSpriteEntries[2].frame = 0x303;
    gSpriteEntries[2].palette = 14;
    gSpriteEntries[2].frame_table = 0;
    gSpriteEntries[2].order = 0x40;
}

static void medals_list_init_cursor(void) {
    gSpriteEntries[3].flags = SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(2) | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[3].x = 0x18;
    gSpriteEntries[3].y = gGameWork.medalRow * 16 + 0x28;
    gSpriteEntries[3].frame = 0x307;
    gSpriteEntries[3].palette = 14;
    gSpriteEntries[3].frame_table = 0;
    gSpriteEntries[3].order = 0x41;
}

static void medals_list_blink_tab_arrows(void) {
    if (gFrameCounter & 8) {
        gSpriteEntries[1].flags &= (u16)~SPRITE_FLAG_VISIBLE;
        gSpriteEntries[2].flags &= (u16)~SPRITE_FLAG_VISIBLE;
    } else {
        gSpriteEntries[1].flags |= SPRITE_FLAG_VISIBLE;
        gSpriteEntries[2].flags |= SPRITE_FLAG_VISIBLE;
    }
}

static void medals_list_row_input(void) {
    if (KEYS_LO(gRepeatKeys) & 0x40) {
        if (gGameWork.medalRow == 0)
            gGameWork.medalRow = 5;
        else
            gGameWork.medalRow--;
    }
    if (KEYS_LO(gRepeatKeys) & 0x80) {
        if (gGameWork.medalRow == 5)
            gGameWork.medalRow = 0;
        else
            gGameWork.medalRow++;
    }
    if (KEYS_LO(gRepeatKeys) & 0xC0) {
        play_sound_effect(2);
        gSpriteEntries[3].y = gGameWork.medalRow * 16 + 0x28;
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
        if (gGameWork.listTab == 0)
            gGameWork.listTab = 4;
        else
            gGameWork.listTab--;
    }
    if (KEYS_LO(gRepeatKeys) & 0x10) {
        if (gGameWork.listTab == 4)
            gGameWork.listTab = 0;
        else
            gGameWork.listTab++;
    }
    if (KEYS_LO(gRepeatKeys) & 0x30) {
        play_sound_effect(2);
        write_tilemap_rect(10, 2, 5, 2, gUiTilemaps[gGameWork.listTab + 0x4B], REG_BG1CNT, 0x200);
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

static void medals_list_update_swap_marker(void) {
    u8 medal;

    if (gGameWork.partSlot & 0x80) {
        medal = gGameWork.partSlot & 0x7F;
        if ((u8)(medal / 6) == gGameWork.listTab) {
            if (gFrameCounter & 1) {
                gSpriteEntries[5].flags =
                    SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(2) | SPRITE_FLAG_PART_PALETTE;
                gSpriteEntries[5].x = 0x19;
                gSpriteEntries[5].y = (u8)(medal % 6) * 16 + 0x2A;
                gSpriteEntries[5].frame = 0x307;
                gSpriteEntries[5].palette = 0xE;
                gSpriteEntries[5].frame_table = 0;
                gSpriteEntries[5].order = 0x40;
            } else
                gSpriteEntries[5].flags &= (u16)~SPRITE_FLAG_VISIBLE;
        } else
            gSpriteEntries[5].flags &= (u16)~SPRITE_FLAG_VISIBLE;
    } else
        gSpriteEntries[5].flags &= (u16)~SPRITE_FLAG_VISIBLE;
}

static void medals_list_swap_input(void) {
    u32 cur;

    if (KEYS_LO(gNewKeys) & 4) {
        play_sound_effect(2);
        if (gGameWork.partSlot & 0x80) {
            gGameWork.partSlot &= 0x7F;
            if (gGameWork.partSlot != (cur = gGameWork.listTab * 6 + gGameWork.medalRow)) {
                memswap(&gMedals[gGameWork.partSlot], &gMedals[cur], 0x40);
                write_tilemap_rect(10, 2, 5, 2, gUiTilemaps[gGameWork.listTab + 0x4B], REG_BG1CNT, 0x200);
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
            gGameWork.partSlot = 0;
            medals_list_update_swap_marker();
        } else {
            gGameWork.partSlot = gGameWork.listTab * 6 + gGameWork.medalRow + 0x80;
            medals_list_update_swap_marker();
        }
    }
}

static u32 get_medal_active_slot(u8 medal) {
    if (gMedals[medal].flags & 0x80 && gMedals[medal].flags & 0x40)
        return find_medabot_slot_by_medal(gMedals[medal].graphicId);
    return 0xFF;
}

static void decompress_active_medal_sprite(void) {
    u32 slot;

    gGameWork.shownId = gGameWork.listTab * 6 + gGameWork.medalRow;
    slot = get_medal_active_slot(gGameWork.shownId);
    if (slot != 0xFF)
        decompress_sprite_to_vram_08042D94(gTeamSlots[slot].head, gTeamSlots[slot].rightArm, gTeamSlots[slot].leftArm,
                                           gTeamSlots[slot].legs, 2);
}

static void init_active_medal_battle_sprites(void) {
    u32 slot;

    gGameWork.shownId = gGameWork.listTab * 6 + gGameWork.medalRow;
    slot = get_medal_active_slot(gGameWork.shownId);
    if (slot != 0xFF)
        init_battle_medabot_sprites(gTeamSlots[slot].head, gTeamSlots[slot].rightArm, gTeamSlots[slot].leftArm,
                                    gTeamSlots[slot].legs, 2, 0x64, 0xE0, 0x78, 0, 2, 0);
    else
        disable_sprites(0x64, 4);
}

static void draw_medal_position_tile(void) {
    u32 slot;

    gGameWork.shownId = gGameWork.listTab * 6 + gGameWork.medalRow;
    slot = get_medal_active_slot(gGameWork.shownId);
    if (slot != 0xFF) {
        if (gTeamSlots[slot].legs < 0x78) {
            load_part_data(gTeamSlots[slot].legs, 3, gGameWork.medalGfxRecord);
            draw_tilemap_with_offset(gGameWork.medalGfxRecord[1] - 0x64, 0x1B, 0x11, REG_BG1CNT, 0x83A0);
        } else
            draw_tilemap_with_offset(0xFF, 0x1B, 0x11, REG_BG1CNT, 0x83A0);
    } else
        draw_tilemap_with_offset(0xFF, 0x1B, 0x11, REG_BG1CNT, 0x83A0);
}

static void medal_page_draw_icon(void) {
    CpuFastSet(gMedalIconTiles + gMedals[gGameWork.shownId].graphicId * 0x80, (void *)0x06006600, 0x20);
    draw_tile_block(2, 2, 2, 3, REG_BG1CNT, 0x6330);
}

static void medal_skill_draw_icon(void) {
    CpuFastSet(gMedalIconTiles + gMedals[gGameWork.shownId].graphicId * 0x80, (void *)0x06007800, 0x20);
    draw_tile_block(2, 2, 2, 3, REG_BG1CNT, 0x63C0);
}

static void medal_page_draw_kind_name(void) {
    disable_sprites(10, 10);
    memcpy_bytes_0803F63C((void *)gMedalNames[gMedals[gGameWork.shownId].graphicId], gGameWork.textBuf, 11);
    render_text_sprites_08040DB8(gGameWork.textBuf, 10, 4, 3, 7, 13, 1, 1);
}

static void medal_page_draw_name(void) {
    disable_sprites(0x14, 10);
    render_text_sprites_08040DB8(gMedals[gGameWork.shownId].name, 0x14, 0x12, 3, 10, 12, 0, 1);
}

static void medal_page_draw_level(void) {
    fill_tilemap_pair_or_divide(gMedals[gGameWork.shownId].level, 12, 3, REG_BG1CNT, 0xC314);
}

static void medal_skill_draw_level(void) {
    fill_tilemap_pair_or_divide(gMedals[gGameWork.shownId].level, 12, 3, REG_BG1CNT, 0xC3A4);
}

static void medal_ability_draw_attribute(void) {
    disable_sprites(0x1E, 15);
    memcpy_bytes_0803F63C((void *)gAttributeNames[gMedals[gGameWork.shownId].attribute], gGameWork.textBuf, 14);
    render_text_sprites_08040DB8(gGameWork.textBuf, 0x1E, 10, 7, 8, 11, 1, 1);
}

static void medal_ability_draw_aim(void) {
    disable_sprites(0x2D, 13);
    memcpy_bytes_0803F63C((void *)gSkillTypeNames[gMedals[gGameWork.shownId].aimSkillType], gGameWork.textBuf, 14);
    render_text_sprites_08040DB8(gGameWork.textBuf, 0x2D, 10, 10, 10, 10, 1, 1);
}

static void medal_ability_draw_compatibility(void) {
    draw_tile_block(2, 2, 0x1B, 7, REG_BG1CNT, gMedals[gGameWork.shownId].compatibility * 4 + 0xD340);
}

static void medal_page_init_medal_arrows(void) {
    if (gGameWork.freeMedalCount > 1) {
        gSpriteEntries[1].flags =
            SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(2) | SPRITE_FLAG_PART_PALETTE;
        gSpriteEntries[1].x = 4;
        gSpriteEntries[1].y = 0x20;
        gSpriteEntries[1].frame = 0x302;
        gSpriteEntries[1].palette = 14;
        gSpriteEntries[1].frame_table = 0;
        gSpriteEntries[1].order = 0x40;
        gSpriteEntries[2].flags =
            SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(2) | SPRITE_FLAG_PART_PALETTE;
        gSpriteEntries[2].x = 0x7C;
        gSpriteEntries[2].y = 0x20;
        gSpriteEntries[2].frame = 0x303;
        gSpriteEntries[2].palette = 14;
        gSpriteEntries[2].frame_table = 0;
        gSpriteEntries[2].order = 0x40;
    }
}

static void medal_page_blink_medal_arrows(void) {
    if (gGameWork.freeMedalCount > 1) {
        if (gFrameCounter & 8) {
            gSpriteEntries[1].flags &= (u16)~SPRITE_FLAG_VISIBLE;
            gSpriteEntries[2].flags &= (u16)~SPRITE_FLAG_VISIBLE;
        } else {
            gSpriteEntries[1].flags |= SPRITE_FLAG_VISIBLE;
            gSpriteEntries[2].flags |= SPRITE_FLAG_VISIBLE;
        }
    }
}

static void medal_page_cycle_medal_input(void) {
    u32 found;

    if (gGameWork.freeMedalCount > 1) {
        if (KEYS_LO(gRepeatKeys) & 0x20) {
            play_sound_effect(2);
            found = 0;
            do {
                if (gGameWork.shownId == 0)
                    gGameWork.shownId = 29;
                else
                    gGameWork.shownId--;
                if (gMedals[gGameWork.shownId].flags & 0x80) {
                    if (gGameWork.openedFrom != 1)
                        found = 1;
                    else if (!(gMedals[gGameWork.shownId].flags & 0x40))
                        found = 1;
                }
            } while (!found);
        }
        if (KEYS_LO(gRepeatKeys) & 0x10) {
            play_sound_effect(2);
            found = 0;
            do {
                if (gGameWork.shownId == 29)
                    gGameWork.shownId = 0;
                else
                    gGameWork.shownId++;
                if (gMedals[gGameWork.shownId].flags & 0x80) {
                    if (gGameWork.openedFrom != 1)
                        found = 1;
                    else if (!(gMedals[gGameWork.shownId].flags & 0x40))
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
    disable_sprites(0x1E, 0x3C);
    if (gMedals[gGameWork.shownId].level >= 10) {
        memcpy_bytes_08041D04(gMedalMedaforceIds + gMedals[gGameWork.shownId].graphicId * 3, &gGameWork.partAbility, 3);
        memcpy_bytes_08041D04(gMedaforceRecords + gGameWork.partAbility * 6, gGameWork.medalGfxRecord, 6);
        memcpy_bytes_0803F63C((void *)gMedaforceNames[gGameWork.partAbility], gGameWork.textBuf, 17);
        render_text_sprites_08040DB8(gGameWork.textBuf, 0x1E, 2, 6, 10, 10, 1, 1);
        draw_tile_block(2, 2, 12, 6, REG_BG1CNT, gGameWork.medalGfxRecord[5] * 4 + 0x5300);
    } else {
        fill_text_blank(gGameWork.textBuf, 13);
        render_text_sprites_08040DB8(gGameWork.textBuf, 0x1E, 2, 6, 10, 10, 1, 1);
        vram_fill_tilemap_rect(2, 2, 12, 6, REG_BG1CNT, 0);
    }
    if (gMedals[gGameWork.shownId].level >= 30) {
        memcpy_bytes_08041D04(gMedaforceRecords + gGameWork.partSkill * 6, gGameWork.medalGfxRecord, 6);
        memcpy_bytes_0803F63C((void *)gMedaforceNames[gGameWork.partSkill], gGameWork.textBuf, 17);
        render_text_sprites_08040DB8(gGameWork.textBuf, 0x32, 2, 8, 10, 10, 1, 1);
        draw_tile_block(2, 2, 12, 8, REG_BG1CNT, gGameWork.medalGfxRecord[5] * 4 + 0x5300);
    } else {
        fill_text_blank(gGameWork.textBuf, 13);
        render_text_sprites_08040DB8(gGameWork.textBuf, 0x32, 2, 8, 10, 10, 1, 1);
        vram_fill_tilemap_rect(2, 2, 12, 8, REG_BG1CNT, 0);
    }
    if (gMedals[gGameWork.shownId].level >= 60) {
        memcpy_bytes_08041D04(gMedaforceRecords + gGameWork.partSkillType * 6, gGameWork.medalGfxRecord, 6);
        memcpy_bytes_0803F63C((void *)gMedaforceNames[gGameWork.partSkillType], gGameWork.textBuf, 17);
        render_text_sprites_08040DB8(gGameWork.textBuf, 0x46, 2, 10, 10, 10, 1, 1);
        draw_tile_block(2, 2, 12, 10, REG_BG1CNT, gGameWork.medalGfxRecord[5] * 4 + 0x5300);
    } else {
        fill_text_blank(gGameWork.textBuf, 13);
        render_text_sprites_08040DB8(gGameWork.textBuf, 0x46, 2, 10, 10, 10, 1, 1);
        vram_fill_tilemap_rect(2, 2, 12, 10, REG_BG1CNT, 0);
    }
}

static void medal_medaforce_draw_selected(void) {
    disable_sprites(0x5A, 15);
    switch (gGameWork.pageCursor) {
    case 0:
        if (gMedals[gGameWork.shownId].level >= 10) {
            memcpy_bytes_08041D04(gMedalMedaforceIds + gMedals[gGameWork.shownId].graphicId * 3, &gGameWork.partAbility,
                                  3);
            memcpy_bytes_08041D04(gMedaforceRecords + gGameWork.partAbility * 6, gGameWork.medalGfxRecord, 6);
            memcpy_bytes_0803F63C((void *)gSkillTypeNames[gGameWork.medalGfxRecord[1]], gGameWork.textBuf, 14);
            render_text_sprites_08040DB8(gGameWork.textBuf, 0x5A, 0x13, 7, 10, 11, 1, 1);
            draw_number_bgcnt(gGameWork.medalGfxRecord[2], 0x19, 10, 2, REG_BG1CNT, 0xD334);
        } else {
            fill_text_blank(gGameWork.textBuf, 13);
            render_text_sprites_08040DB8(gGameWork.textBuf, 0x5A, 0x13, 7, 10, 11, 1, 1);
            draw_number_bgcnt(0, 0x19, 10, 2, REG_BG1CNT, 0xD334);
        }
        break;
    case 1:
        if (gMedals[gGameWork.shownId].level >= 30) {
            memcpy_bytes_08041D04(gMedalMedaforceIds + gMedals[gGameWork.shownId].graphicId * 3, &gGameWork.partAbility,
                                  3);
            memcpy_bytes_08041D04(gMedaforceRecords + gGameWork.partSkill * 6, gGameWork.medalGfxRecord, 6);
            memcpy_bytes_0803F63C((void *)gSkillTypeNames[gGameWork.medalGfxRecord[1]], gGameWork.textBuf, 14);
            render_text_sprites_08040DB8(gGameWork.textBuf, 0x5A, 0x13, 7, 10, 11, 1, 1);
            draw_number_bgcnt(gGameWork.medalGfxRecord[2], 0x19, 10, 2, REG_BG1CNT, 0xD334);
        } else {
            fill_text_blank(gGameWork.textBuf, 13);
            render_text_sprites_08040DB8(gGameWork.textBuf, 0x5A, 0x13, 7, 10, 11, 1, 1);
            draw_number_bgcnt(0, 0x19, 10, 2, REG_BG1CNT, 0xD334);
        }
        break;
    default:
        if (gMedals[gGameWork.shownId].level >= 60) {
            memcpy_bytes_08041D04(gMedalMedaforceIds + gMedals[gGameWork.shownId].graphicId * 3, &gGameWork.partAbility,
                                  3);
            memcpy_bytes_08041D04(gMedaforceRecords + gGameWork.partSkillType * 6, gGameWork.medalGfxRecord, 6);
            memcpy_bytes_0803F63C((void *)gSkillTypeNames[gGameWork.medalGfxRecord[1]], gGameWork.textBuf, 14);
            render_text_sprites_08040DB8(gGameWork.textBuf, 0x5A, 0x13, 7, 10, 11, 1, 1);
            draw_number_bgcnt(gGameWork.medalGfxRecord[2], 0x19, 10, 2, REG_BG1CNT, 0xD334);
        } else {
            fill_text_blank(gGameWork.textBuf, 13);
            render_text_sprites_08040DB8(gGameWork.textBuf, 0x5A, 0x13, 7, 10, 11, 1, 1);
            draw_number_bgcnt(0, 0x19, 10, 2, REG_BG1CNT, 0xD334);
        }
        break;
    }
}

static void medal_medaforce_init_cursor(void) {
    gSpriteEntries[3].flags = SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(2) | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[3].x = 8;
    gSpriteEntries[3].y = gGameWork.pageCursor * 16 + 0x38;
    gSpriteEntries[3].frame = 0x307;
    gSpriteEntries[3].palette = 14;
    gSpriteEntries[3].frame_table = 0;
    gSpriteEntries[3].order = 0x41;
}

static u32 medal_medaforce_cursor_input(void) {
    if (KEYS_LO(gRepeatKeys) & 0x40) {
        if (gGameWork.pageCursor == 0)
            gGameWork.pageCursor = 2;
        else
            gGameWork.pageCursor--;
    }
    if (KEYS_LO(gRepeatKeys) & 0x80) {
        if (gGameWork.pageCursor == 2)
            gGameWork.pageCursor = 0;
        else
            gGameWork.pageCursor++;
    }
    if (KEYS_LO(gRepeatKeys) & 0xC0) {
        play_sound_effect(2);
        gSpriteEntries[3].y = gGameWork.pageCursor * 16 + 0x38;
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
    switch (gGameWork.pageCursor) {
    default:
        if (gMedals[gGameWork.shownId].level >= 60)
            goto slot2;
    none:
        return 0x34;
    case 0:
        if (gMedals[gGameWork.shownId].level < 10)
            goto none;
        memcpy_bytes_08041D04(gMedalMedaforceIds + gMedals[gGameWork.shownId].graphicId * 3, &gGameWork.partAbility, 3);
        return gGameWork.partAbility;
    case 1:
        if (gMedals[gGameWork.shownId].level < 30)
            goto none;
        memcpy_bytes_08041D04(gMedalMedaforceIds + gMedals[gGameWork.shownId].graphicId * 3, &gGameWork.partAbility, 3);
        return gGameWork.partSkill;
    }
slot2:
    memcpy_bytes_08041D04(gMedalMedaforceIds + gMedals[gGameWork.shownId].graphicId * 3, &gGameWork.partAbility, 3);
    return gGameWork.partSkillType;
}

void medals_help_init_cursor(void) {
    const u8 *rec = gHelpCursorLayouts[gGameWork.helpFromPage];

    gGameWork.helpPageCount = rec[0];
    gSpriteEntries[6].flags = SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[6].x = rec[(gGameWork.helpPage + 1) << 1] * 8;
    gSpriteEntries[6].y = rec[((gGameWork.helpPage + 1) << 1) + 1] * 8;
    gSpriteEntries[6].frame = 0x308;
    gSpriteEntries[6].palette = 14;
    gSpriteEntries[6].frame_table = 0;
    gSpriteEntries[6].order = 0xC1;
    battle_sprite_anim_init(gBattleSpriteAnimScripts[3], 6);
}

static void medals_help_move_cursor(void) {
    const u8 *rec = gHelpCursorLayouts[gGameWork.helpFromPage];

    gSpriteEntries[6].x = rec[(gGameWork.helpPage + 1) << 1] * 8;
    gSpriteEntries[6].y = rec[((gGameWork.helpPage + 1) << 1) + 1] * 8;
}

void medal_rotation_draw_actions(void) {
    u32 i;

    for (i = 0; i < 8; i++) {
        if (i < gMedals[gGameWork.shownId].rotationLen)
            draw_tile_block(2, 2, i * 2 + 6, 7, REG_BG1CNT, gMedals[gGameWork.shownId].rotation[i] * 4 + 0xB340);
        else
            draw_tile_block(2, 2, i * 2 + 6, 7, REG_BG1CNT, gMedals[gGameWork.shownId].rotation[i] * 4 + 0xA340);
    }
}

static void medal_rotation_draw_repeat_path(void) {
    write_tilemap_rect(16, 2, 6, 10, gUiTilemaps[gMedals[gGameWork.shownId].rotationLen + 0x51], REG_BG1CNT, 0x200);
}

static void medal_rotation_redraw(void) {
    if (KEYS_LO(gRepeatKeys) & 0x30) {
        medal_page_draw_icon();
        medal_page_draw_kind_name();
        medal_page_draw_name();
        medal_page_draw_level();
        medal_rotation_draw_actions();
        medal_rotation_draw_repeat_path();
        medal_page_load_bot_gfx();
        medal_page_draw_bot_sprite();
        medal_page_draw_bot_legs_type();
    }
}

static void medal_rotation_init_slot_arrows(void) {
    gSpriteEntries[1].flags = SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(2) | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[1].x = gGameWork.pageCursor * 16 + 0x38;
    gSpriteEntries[1].y = 0x34;
    gSpriteEntries[1].frame = 0x300;
    gSpriteEntries[1].palette = 14;
    gSpriteEntries[1].frame_table = 0;
    gSpriteEntries[1].order = 0x40;
    gSpriteEntries[2].flags = SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(2) | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[2].x = gGameWork.pageCursor * 16 + 0x38;
    gSpriteEntries[2].y = 0x4C;
    gSpriteEntries[2].frame = 0x301;
    gSpriteEntries[2].palette = 14;
    gSpriteEntries[2].frame_table = 0;
    gSpriteEntries[2].order = 0x40;
}

static void medal_rotation_init_repeat_cursor(void) {
    gSpriteEntries[3].flags = SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(2) | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[3].x = gMedals[gGameWork.shownId].rotationLen * 16 + 0x30;
    gSpriteEntries[3].y = 0x30;
    gSpriteEntries[3].frame = 0x305;
    gSpriteEntries[3].palette = 14;
    gSpriteEntries[3].frame_table = 0;
    gSpriteEntries[3].order = 0x40;
}

static void medal_rotation_blink_slot_arrows(void) {
    if (gFrameCounter & 8) {
        gSpriteEntries[1].flags &= (u16)~SPRITE_FLAG_VISIBLE;
        gSpriteEntries[2].flags &= (u16)~SPRITE_FLAG_VISIBLE;
    } else {
        gSpriteEntries[1].flags |= SPRITE_FLAG_VISIBLE;
        gSpriteEntries[2].flags |= SPRITE_FLAG_VISIBLE;
    }
}

static u32 medal_rotation_action_input(void) {
    u8 up;

    if ((up = KEYS_LO(gRepeatKeys) & 0x40)) {
        play_sound_effect(2);
        if (gMedals[gGameWork.shownId].rotation[gGameWork.pageCursor] == 0)
            gMedals[gGameWork.shownId].rotation[gGameWork.pageCursor] = 7;
        else
            gMedals[gGameWork.shownId].rotation[gGameWork.pageCursor]--;
        return 1;
    }
    if (KEYS_LO(gRepeatKeys) & 0x80) {
        play_sound_effect(2);
        if (gMedals[gGameWork.shownId].rotation[gGameWork.pageCursor] == 7)
            gMedals[gGameWork.shownId].rotation[gGameWork.pageCursor] = up;
        else
            gMedals[gGameWork.shownId].rotation[gGameWork.pageCursor]++;
        return 1;
    }
    return 0;
}

static u32 medal_rotation_slot_input(void) {
    u8 left;

    if ((left = KEYS_LO(gRepeatKeys) & 0x20)) {
        play_sound_effect(2);
        if (gGameWork.pageCursor == 0)
            gGameWork.pageCursor = 7;
        else
            gGameWork.pageCursor--;
        medal_rotation_init_slot_arrows();
        return 1;
    }
    if (KEYS_LO(gRepeatKeys) & 0x10) {
        play_sound_effect(2);
        if (gGameWork.pageCursor == 7)
            gGameWork.pageCursor = left;
        else
            gGameWork.pageCursor++;
        medal_rotation_init_slot_arrows();
        return 1;
    }
    return 0;
}

static u32 medal_rotation_repeat_input(void) {
    u8 left;

    if ((left = KEYS_LO(gRepeatKeys) & 0x20)) {
        play_sound_effect(2);
        if (gMedals[gGameWork.shownId].rotationLen == 0)
            gMedals[gGameWork.shownId].rotationLen = 7;
        else
            gMedals[gGameWork.shownId].rotationLen--;
        return 1;
    }
    if (KEYS_LO(gRepeatKeys) & 0x10) {
        play_sound_effect(2);
        if (gMedals[gGameWork.shownId].rotationLen == 7)
            gMedals[gGameWork.shownId].rotationLen = left;
        else
            gMedals[gGameWork.shownId].rotationLen++;
        return 1;
    }
    return 0;
}

static void medal_page_load_bot_gfx(void) {
    u32 slot = get_medal_active_slot(gGameWork.shownId);

    if (slot != 0xFF)
        decompress_sprite_to_vram_08042D94(gTeamSlots[slot].head, gTeamSlots[slot].rightArm, gTeamSlots[slot].leftArm,
                                           gTeamSlots[slot].legs, 2);
}

static void medal_page_draw_bot_sprite(void) {
    u32 slot = get_medal_active_slot(gGameWork.shownId);

    if (slot != 0xFF)
        init_battle_medabot_sprites(gTeamSlots[slot].head, gTeamSlots[slot].rightArm, gTeamSlots[slot].leftArm,
                                    gTeamSlots[slot].legs, 2, 0x64, 0x18, 0x40, 0, 2, 0);
    else
        disable_sprites(0x64, 4);
}

static void medal_page_draw_bot_legs_type(void) {
    u32 slot = get_medal_active_slot(gGameWork.shownId);

    if (slot != 0xFF) {
        if (gTeamSlots[slot].legs < 0x78) {
            load_part_data(gTeamSlots[slot].legs, 3, gGameWork.medalGfxRecord);
            draw_tilemap_with_offset(gGameWork.medalGfxRecord[1] - 100, 2, 10, REG_BG1CNT, 0x83A0);
        } else {
            draw_tilemap_with_offset(0xFF, 2, 10, REG_BG1CNT, 0x83A0);
        }
    } else {
        draw_tilemap_with_offset(0xFF, 2, 10, REG_BG1CNT, 0x83A0);
    }
}

void render_medal_skill_stats(void) {
    draw_number_bgcnt(gMedals[gGameWork.shownId].skillLevel[0], 11, 9, 3, REG_BG1CNT, 0xC3C4);
    draw_number_bgcnt(gMedals[gGameWork.shownId].skillLevel[1], 11, 12, 3, REG_BG1CNT, 0xC3C4);
    draw_number_bgcnt(gMedals[gGameWork.shownId].skillLevel[2], 25, 9, 3, REG_BG1CNT, 0xC3C4);
    draw_number_bgcnt(gMedals[gGameWork.shownId].skillLevel[3], 25, 12, 3, REG_BG1CNT, 0xC3C4);
    draw_number_bgcnt(gMedals[gGameWork.shownId].skillLevel[4], 11, 15, 3, REG_BG1CNT, 0xC3C4);
    draw_number_bgcnt(gMedals[gGameWork.shownId].skillLevel[5], 11, 18, 3, REG_BG1CNT, 0xC3C4);
    draw_number_bgcnt(gMedals[gGameWork.shownId].skillLevel[6], 25, 15, 3, REG_BG1CNT, 0xC3C4);
    draw_number_bgcnt(gMedals[gGameWork.shownId].skillLevel[7], 25, 18, 3, REG_BG1CNT, 0xC3C4);
}

void medal_skill_load_shine_frame(void) {
    u32 i;

    for (i = 0; i < 5; i++)
        CpuFastSet(gMedalSkillShineTiles + (i * 0x100 + gGameWork.listTab * 0x20), (void *)0x06007A00 + i * 0x20, 8);
}

static void medal_skill_animate_shine(void) {
    if (++gGameWork.subCounter > 180 && gGameWork.subCounter & 1) {
        medal_skill_load_shine_frame();
        if (++gGameWork.listTab == 8) {
            gGameWork.subCounter = 0;
            gGameWork.listTab = 0;
        }
    }
}

void draw_medal_skill_bars(void) {
    u32 i;

    for (i = 0; i < 8; i++) {
        if (gMedals[gGameWork.shownId].skillExp[0] > i)
            draw_tile_block(1, 1, i + 2, 9, REG_BG1CNT, 0xD3D0);
        else
            vram_fill_tilemap_rect(1, 1, i + 2, 9, REG_BG1CNT, 0);
    }

    for (i = 0; i < 8; i++) {
        if (gMedals[gGameWork.shownId].skillExp[1] > i)
            draw_tile_block(1, 1, i + 2, 12, REG_BG1CNT, 0xD3D0);
        else
            vram_fill_tilemap_rect(1, 1, i + 2, 12, REG_BG1CNT, 0);
    }

    for (i = 0; i < 8; i++) {
        if (gMedals[gGameWork.shownId].skillExp[2] > i)
            draw_tile_block(1, 1, i + 16, 9, REG_BG1CNT, 0xD3D3);
        else
            vram_fill_tilemap_rect(1, 1, i + 16, 9, REG_BG1CNT, 0);
    }

    for (i = 0; i < 8; i++) {
        if (gMedals[gGameWork.shownId].skillExp[3] > i)
            draw_tile_block(1, 1, i + 16, 12, REG_BG1CNT, 0xD3D3);
        else
            vram_fill_tilemap_rect(1, 1, i + 16, 12, REG_BG1CNT, 0);
    }

    for (i = 0; i < 8; i++) {
        if (gMedals[gGameWork.shownId].skillExp[4] > i)
            draw_tile_block(1, 1, i + 2, 15, REG_BG1CNT, 0xD3D1);
        else
            vram_fill_tilemap_rect(1, 1, i + 2, 15, REG_BG1CNT, 0);
    }

    for (i = 0; i < 8; i++) {
        if (gMedals[gGameWork.shownId].skillExp[5] > i)
            draw_tile_block(1, 1, i + 2, 18, REG_BG1CNT, 0xD3D2);
        else
            vram_fill_tilemap_rect(1, 1, i + 2, 18, REG_BG1CNT, 0);
    }

    for (i = 0; i < 8; i++) {
        if (gMedals[gGameWork.shownId].skillExp[6] > i)
            draw_tile_block(1, 1, i + 16, 15, REG_BG1CNT, 0xD3D4);
        else
            vram_fill_tilemap_rect(1, 1, i + 16, 15, REG_BG1CNT, 0);
    }

    for (i = 0; i < 8; i++) {
        if (gMedals[gGameWork.shownId].skillExp[7] > i)
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

void medal_rotation_store_to_battle_bot(void) {
    u32 i;

    gBattleBots[gBattleWork.commandBot].medal.rotationLen = gMedals[gGameWork.shownId].rotationLen;
    for (i = 0; i < 8; i++)
        gBattleBots[gBattleWork.commandBot].medal.rotation[i] = gMedals[gGameWork.shownId].rotation[i];
}

static void increment_medal_level_on_input(void) {
    if (gMedals[gGameWork.shownId].flags & 0x80 && KEYS_LO(gHeldKeys) & 8 && KEYS_HI(gRepeatKeys) & 2 &&
        gMedals[gGameWork.shownId].level != 100) {
        gMedals[gGameWork.shownId].level++;
        memcpy_bytes_08041D04(gMedalRecords[gMedals[gGameWork.shownId].graphicId], &gGameWork.partAbility, 16);
        gMedals[gGameWork.shownId].spriteVariant =
            medal_tier_for_level(gMedals[gGameWork.shownId].level, gGameWork.partGender, gGameWork.partStat0,
                                 gGameWork.partStat1, gGameWork.partStat2);
        load_medal_sprite();
        render_medal_slots_in_menu();
    }
}

static void handle_medal_level_down_input(void) {
    if (gMedals[gGameWork.shownId].flags & 0x80 && KEYS_LO(gHeldKeys) & 8 && KEYS_HI(gRepeatKeys) & 1 &&
        gMedals[gGameWork.shownId].nextLevelExp > 99) {
        gMedals[gGameWork.shownId].nextLevelExp -= 100;
        render_medal_level_display();
    }
}

void medal_skill_debug_init_cursor(void) {
    gSpriteEntries[127].flags =
        SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(2) | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[127].x = gMedalSkillDebugCursorPos[gGameWork.subCounter * 2];
    gSpriteEntries[127].y = gMedalSkillDebugCursorPos[gGameWork.subCounter * 2 + 1];
    gSpriteEntries[127].frame = 0x303;
    gSpriteEntries[127].palette = 0xE;
    gSpriteEntries[127].frame_table = 0;
    gSpriteEntries[127].order = 0x40;
}

static void medal_trade_init_choice_cursor(void) {
    gSpriteEntries[7].flags =
        SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_FLAG_HFLIP | SPRITE_FLAG_AFFINE | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[7].x = 0xA8;
    gSpriteEntries[7].y = gGameWork.tradeChoice * 16 + 0x70;
    gSpriteEntries[7].frame = 0x307;
    gSpriteEntries[7].palette = 0xE;
    gSpriteEntries[7].scale_x = 0x40;
    gSpriteEntries[7].scale_y = 0x40;
    gSpriteEntries[7].frame_table = 0;
    gSpriteEntries[7].work[MEDALS_SPR_CLOSE_STEP] = 0;
    gSpriteEntries[7].work[MEDALS_SPR_BLINK_TIMER] = 0;
    gSpriteEntries[7].order = 0xC1;
}

static void medal_trade_choice_cursor_input(void) {
    if (KEYS_LO(gRepeatKeys) & 0x40) {
        if (gGameWork.tradeChoice == 0)
            gGameWork.tradeChoice = 2;
        else
            gGameWork.tradeChoice--;
    }
    if (KEYS_LO(gRepeatKeys) & 0x80) {
        if (gGameWork.tradeChoice == 2)
            gGameWork.tradeChoice = 0;
        else
            gGameWork.tradeChoice++;
    }
    if (KEYS_LO(gRepeatKeys) & 0xC0) {
        play_sound_effect(2);
        gSpriteEntries[7].y = gGameWork.tradeChoice * 16 + 0x70;
    }
}

u32 medal_trade_choice_close_step(void) {
    gMedalTradeChoiceCloseSteps[gSpriteEntries[7].work[MEDALS_SPR_CLOSE_STEP]]();
    if (gSpriteEntries[7].work[MEDALS_SPR_CLOSE_STEP] == 3)
        return 1;
    return 0;
}

void medal_trade_choice_blink_step(void) {
    if (gSpriteEntries[7].work[MEDALS_SPR_BLINK_TIMER] != 30) {
        if (gSpriteEntries[7].work[MEDALS_SPR_BLINK_TIMER] & 4)
            gSpriteEntries[7].flags &= (u16)~SPRITE_FLAG_VISIBLE;
        else
            gSpriteEntries[7].flags |= SPRITE_FLAG_VISIBLE;
        gSpriteEntries[7].work[MEDALS_SPR_BLINK_TIMER]++;
    } else {
        gSpriteEntries[7].flags |= SPRITE_FLAG_VISIBLE;
        gSpriteEntries[7].work[MEDALS_SPR_CLOSE_STEP]++;
    }
}

void medal_trade_choice_shrink_step(void) {
    gSpriteEntries[7].scale_x -= 8;
    gSpriteEntries[7].scale_y -= 8;
    if (gSpriteEntries[7].scale_x == 0) {
        disable_sprites(7, 1);
        gSpriteEntries[7].work[MEDALS_SPR_CLOSE_STEP]++;
    }
}

void medal_trade_choice_clear_step(void) {
    vram_fill_tilemap_rect(12, 8, 18, 12, REG_BG0CNT, 0);
    gSpriteEntries[7].work[MEDALS_SPR_CLOSE_STEP]++;
}
