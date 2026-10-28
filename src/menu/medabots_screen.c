// Game state 3: the Medabots screen (Medawatch > Medabots): the team list with its orbiting part sprites, the
// Medabot detail ("Build") screen that equips Medals and Medaparts, and the team select before a battle or a
// race (also over the link). Opens the Medals (game state 4) and Medaparts (5) info screens.

#include "global.h"
#include "constants/sprites.h"

static void medabots_scroll_bg3(void);
static void medabots_screen_init_cursor_icons(void);
static void medabots_screen_orbit_cursor_icon(u32 i);
static void medabots_screen_load_team_icon_gfx(void);
static void medabots_screen_place_team_icons(void);
static void medabots_screen_draw_legs_type_icons(void);
static void medabots_screen_draw_medal_nickname(void);
static void medabots_screen_draw_medal_kind_name(void);
static void medabots_screen_draw_medal_icon(void);
static void medabots_screen_init_bot_sprite(void);
static void medabots_screen_draw_bot_sprite(void);
static u32 medabots_screen_cursor_input(void);
static void medabots_screen_start_reorder_orbit(void);
static void medabots_screen_orbit_reorder_icon(u32 i);
static void medabots_screen_update_reorder_icons(void);
static u32 medabots_screen_reorder_input(void);
static void medabots_screen_flag_invalid_bot(void);
static void medabots_screen_animate_invalid_bot(void);
static void medabot_detail_take_apart(void);
static void medabot_detail_draw_medal_nickname(void);
static void medabot_detail_draw_medal_icon(void);
static void medabot_detail_draw_medal_level(void);
static void medabot_detail_draw_medal_kind_name(void);
static void medabot_detail_draw_head_name(void);
static void medabot_detail_draw_head_skill_icon(void);
static void medabot_detail_draw_rarm_name(void);
static void medabot_detail_draw_rarm_skill_icon(void);
static void medabot_detail_draw_larm_name(void);
static void medabot_detail_draw_larm_skill_icon(void);
static void medabot_detail_draw_legs_name(void);
static void medabot_detail_draw_legs_skill_icon(void);
static void medabot_detail_draw_row_icon_0(u32 a);
static void medabot_detail_draw_row_icon_1(u32 a);
static void medabot_detail_draw_row_icon_2(u32 a);
static void medabot_detail_draw_row_icon_3(u32 a);
static void medabot_detail_draw_row_icon_4(u32 a);
static void medabot_detail_draw_legs_type_icon(void);
static void medabot_detail_load_icon_gfx(void);
static void medabot_detail_place_icon(void);
static void medabot_detail_place_row_arrows(void);
static void medabot_detail_blink_row_arrows(void);
static void medabot_detail_init_bot_sprite(void);
static void medabot_detail_redraw_bot_sprite(void);
static void medabot_detail_draw_bot_sprite(void);
static void medabot_detail_blink_row_icon(void);
static u32 medabot_detail_row_cursor_input(void);
static u32 medabot_detail_cycle_medal_input(void);
static u32 medabot_detail_cycle_head_input(void);
static u32 medabot_detail_cycle_rarm_input(void);
static u32 medabot_detail_cycle_larm_input(void);
static u32 medabot_detail_cycle_legs_input(void);
static u32 medabot_detail_equip_full_set_input(void);
// previous Medapart id: 0 wraps to 120 + slot unk1, >= 120 clamps to 119
static u32 medabot_detail_prev_part_id(u32 part);
static void medabot_detail_update_invalid_bot(void);
static void medabot_detail_animate_invalid_bot(void);
static u8 medabot_detail_check_row_select(void);
static void assign_medal_to_team_slot(void);
static void team_select_draw_pick_markers(void);
static void medabots_screen_cancel_input(void);
static void team_select_confirm_pick(void);
static void team_select_finish_input(void);
static u32 team_select_slot_not_picked(u32 n);
static void team_select_blink_pick_markers(void);
static void team_select_clear_hint_panel(void);
static void team_select_link_load_opponents(void);

// Game state 3: the Medabots screen (Medawatch > Medabots). Paused while the serial link is busy.
void medabots_screen_update(void) {
    if (link_error_check() == 0) {
        if (gVBlankOamMode == 2) {
            u32 fill = 0x200;
            CpuFastSet(&fill, gSpriteWork->oamBuf, 0x01000100);
        }
        gMedabotsScreenHandlers[gGameSubState]();
    }
}

void medabots_screen_load_gfx(void) {
    u32 zero;

    switch (gGameWork.setupStep) {
    case 0:
        clear_bg_scroll();
        if (gGameWork.enteredFromSubmenu == 1)
            medabots_screen_draw_bot_sprite();
        REG_DISPCNT &= 0xF0FF;
        REG_BG0CNT = 0x500;
        REG_BG1CNT = 0x1801;
        REG_BG2CNT = 0x1902;
        REG_BG3CNT = 0x1A03;
        lz_decompress_dispatch(gMedabotsBgTiles, (void *)0x06004000);
        lz_decompress_dispatch(gLegTypePedestalTiles, (void *)0x06006000);
        lz_decompress_dispatch(gLegTypePedestalTiles2, (void *)0x06006200);
        lz_decompress_dispatch(gTeamRoleLabelTiles, (void *)0x06016C00);
        lz_decompress_dispatch(gSpriteFontTiles, (void *)0x06017400);
        gGameWork.setupStep++;
        break;
    case 1:
        if (gGameWork.enteredFromSubmenu == 1)
            medabots_screen_draw_bot_sprite();
        set_tilemap_and_decompress_bg(0, 0, gMedabotsBg0Tilemap, REG_BG0CNT, 0x200);
        set_tilemap_and_decompress_bg(0, 0, gMedabotsBg1Tilemap, REG_BG1CNT, 0x200);
        set_tilemap_and_decompress_bg(0, 0, gMedabotsBg2Tilemap, REG_BG2CNT, 0x200);
        set_tilemap_and_decompress_bg(0, 0, gMedabotsBg3Tilemap, REG_BG3CNT, 0x200);
        if (gGameWork.enteredFromSubmenu == 1) {
            CpuFastSet(gMedabotsBgPalette, gPaletteBackupBg, 0x60);
            CpuFastSet(gMenuObjPalettes, gPaletteBackup, 0x40);
            CpuFastSet(gGradientPaletteGold, (void *)0x0202F9A0, 8);
            CpuFastSet(gGradientPaletteGold + 0x10, (void *)0x0202F9C0, 8);
            CpuFastSet(gMedabotsCursorObjPalette, (void *)0x0202F980, 8);
            CpuFastSet(gTeamRoleLabelObjPalette, (void *)0x0202F9E0, 8);
            gGameWork.stepCounter = 0;
        } else {
            CpuFastSet(gMedabotsBgPalette, (void *)0x05000000, 0x60);
            CpuFastSet(gMenuObjPalettes, (void *)0x05000200, 0x40);
            CpuFastSet(gGradientPaletteGold, (void *)0x050003A0, 8);
            CpuFastSet(gGradientPaletteGold + 0x10, (void *)0x050003C0, 8);
            CpuFastSet(gMedabotsCursorObjPalette, (void *)0x05000380, 8);
            CpuFastSet(gTeamRoleLabelObjPalette, (void *)0x050003E0, 8);
            set_blend_effect_mode(5, 0x3F, 0x20);
        }
        zero = 0;
        CpuFastSet(&zero, gSpriteEntries, 0x01000800);
        REG_DISPCNT |= 0x1F40;
        REG_DISPCNT &= 0xFFDF;
        gGameWork.setupStep++;
        break;
    case 2:
        if (gGameWork.enteredFromSubmenu == 1)
            medabots_screen_draw_bot_sprite();
        gGameWork.noAffineSprites = 1;
        medabots_screen_load_team_icon_gfx();
        medabots_screen_place_team_icons();
        medabots_screen_init_cursor_icons();
        medabots_screen_draw_legs_type_icons();
        medabots_screen_draw_medal_nickname();
        medabots_screen_draw_medal_kind_name();
        medabots_screen_draw_medal_icon();
        medabots_screen_flag_invalid_bot();
        team_select_clear_hint_panel();
        if (gGameWork.enteredFromSubmenu == 0) {
            medabots_screen_init_bot_sprite();
            if (gGameWork.medabotsMode == 3)
                play_song(7);
        } else if (gGameWork.reorderPick & 0x80) {
            medabots_screen_start_reorder_orbit();
        }
        gGameSubState++;
        gGameWork.setupStep = 0;
        break;
    }
}

void medabots_screen_fade_in(void) {
    struct GameWork *s;
    u8 *flag;

    medabots_scroll_bg3();
    medabots_screen_orbit_cursor_icon(0);
    medabots_screen_orbit_cursor_icon(1);
    medabots_screen_orbit_cursor_icon(2);
    medabots_screen_orbit_cursor_icon(3);
    medabots_screen_draw_bot_sprite();
    medabots_screen_update_reorder_icons();
    medabots_screen_animate_invalid_bot();
    s = &gGameWork;
    flag = &s->enteredFromSubmenu;
    if (*flag == 1) {
        if (s->stepCounter > 8)
            goto done;
        bg_palettes_blend_masked_now(0, 32 - s->stepCounter * 4, 0xFFFF);
        obj_palettes_blend_masked_now(0, 32 - s->stepCounter * 4, 0xF0FF);
        s->stepCounter++;
    } else if (update_blend_effect()) {
    done:
        *flag = 0;
        gGameSubState++;
    }
}

void medabots_screen_handle_input(void) {
    medabots_scroll_bg3();
    medabots_screen_orbit_cursor_icon(0);
    medabots_screen_orbit_cursor_icon(1);
    medabots_screen_orbit_cursor_icon(2);
    medabots_screen_orbit_cursor_icon(3);
    medabots_screen_draw_bot_sprite();
    medabots_screen_update_reorder_icons();
    medabots_screen_animate_invalid_bot();
    team_select_draw_pick_markers();
    if (medabots_screen_reorder_input() == 0 && medabots_screen_cursor_input() == 0) {
        if (KEYS_LO(gNewKeys) & 2)
            medabots_screen_cancel_input();
        else if (KEYS_LO(gNewKeys) & 1)
            team_select_confirm_pick();
        else if (KEYS_LO(gNewKeys) & 8)
            team_select_finish_input();
    }
}

void medabots_screen_exit_start(void) {
    medabots_scroll_bg3();
    medabots_screen_orbit_cursor_icon(0);
    medabots_screen_orbit_cursor_icon(1);
    medabots_screen_orbit_cursor_icon(2);
    medabots_screen_orbit_cursor_icon(3);
    medabots_screen_draw_bot_sprite();
    medabots_screen_animate_invalid_bot();
    set_blend_effect_mode(6, 0x3F, 0x20);
    gGameWork.stepCounter = 0;
    gGameSubState++;
}

void medabots_screen_exit_fade(void) {
    medabots_scroll_bg3();
    medabots_screen_orbit_cursor_icon(0);
    medabots_screen_orbit_cursor_icon(1);
    medabots_screen_orbit_cursor_icon(2);
    medabots_screen_orbit_cursor_icon(3);
    medabots_screen_draw_bot_sprite();
    medabots_screen_animate_invalid_bot();
    if (update_blend_effect())
        gGameSubState++;
}

void medabots_screen_return_to_medawatch(void) {
    CpuFastSet(gSpriteFontPalette, (void *)0x050003E0, 8);
    clear_battle_sprite_slot(0, 0x80);
    gGameWork.noAffineSprites = 0;
    gVBlankOamMode = 0;
    gGameState = 2;
    gGameSubState = 16;
}

// Sub-states 8/9: A on a Medabot in the list fades out, then 16 (medabot_detail_load_gfx) opens its
// detail ("Build") screen (runtime-checked: A -> sub-state 9 -> 18).
void medabots_screen_open_detail_start(void) {
    medabots_scroll_bg3();
    medabots_screen_orbit_cursor_icon(0);
    medabots_screen_orbit_cursor_icon(1);
    medabots_screen_orbit_cursor_icon(2);
    medabots_screen_orbit_cursor_icon(3);
    medabots_screen_draw_bot_sprite();
    medabots_screen_update_reorder_icons();
    medabots_screen_animate_invalid_bot();
    palette_backup_from_hardware();
    gGameWork.stepCounter = 0;
    gGameSubState++;
}

void medabots_screen_open_detail_fade(void) {
    medabots_scroll_bg3();
    medabots_screen_orbit_cursor_icon(0);
    medabots_screen_orbit_cursor_icon(1);
    medabots_screen_orbit_cursor_icon(2);
    medabots_screen_orbit_cursor_icon(3);
    medabots_screen_draw_bot_sprite();
    medabots_screen_update_reorder_icons();
    medabots_screen_animate_invalid_bot();
    if (gGameWork.stepCounter <= 8) {
        bg_palettes_blend_masked_now(0, gGameWork.stepCounter * 4, 0xFFFF);
        obj_palettes_blend_masked_now(0, gGameWork.stepCounter * 4, 0xF0FF);
        gGameWork.stepCounter++;
    } else {
        gGameSubState = 16;
    }
}

// Sub-states 11/12: B on the list with no assembled Medabot (count_assembled_medabots) shows message 22 instead
// of leaving, then returns to input (sub-state 2).
void medabots_screen_no_bot_message_start(void) {
    medabots_scroll_bg3();
    medabots_screen_orbit_cursor_icon(0);
    medabots_screen_orbit_cursor_icon(1);
    medabots_screen_orbit_cursor_icon(2);
    medabots_screen_orbit_cursor_icon(3);
    medabots_screen_draw_bot_sprite();
    medabots_screen_animate_invalid_bot();
    text_window_init(1, 2, 0);
    gGameSubState++;
}

void medabots_screen_no_bot_message_run(void) {
    medabots_scroll_bg3();
    medabots_screen_orbit_cursor_icon(0);
    medabots_screen_orbit_cursor_icon(1);
    medabots_screen_orbit_cursor_icon(2);
    medabots_screen_orbit_cursor_icon(3);
    medabots_screen_draw_bot_sprite();
    medabots_screen_animate_invalid_bot();
    if (run_message(gMenuMessages[22]))
        gGameSubState = 2;
}

void medabot_detail_load_gfx(void) {
    u32 zero;

    if (gGameWork.enteredFromSubmenu == 0)
        medabots_screen_draw_bot_sprite();
    REG_DISPCNT &= 0xF0FF;
    REG_BG0CNT = 0x500;
    REG_BG1CNT = 0x1801;
    REG_BG2CNT = 0x1902;
    REG_BG3CNT = 0x1A03;
    lz_decompress_dispatch(gMedabotBuildBgTiles, (void *)0x06004000);
    lz_decompress_dispatch(gLegTypePedestalTiles, (void *)0x06006000);
    lz_decompress_dispatch(gLegTypePedestalTiles2, (void *)0x06006200);
    lz_decompress_dispatch(gSmallDigitTiles, (void *)0x06007480);
    lz_decompress_dispatch(gCompatibilityIconTiles, (void *)0x06006800);
    lz_decompress_dispatch(gPartSlotIconTiles, (void *)0x06006E00);
    lz_decompress_dispatch(gCursorArrowTiles, (void *)0x06017E00);
    lz_decompress_dispatch(gSpriteFontTiles, (void *)0x06017400);
    set_tilemap_and_decompress_bg(0, 0, gMedabotBuildBg0Tilemap, REG_BG0CNT, 0x200);
    set_tilemap_and_decompress_bg(0, 0, gMedabotBuildBg1Tilemap, REG_BG1CNT, 0x200);
    set_tilemap_and_decompress_bg(0, 0, gMedabotBuildBg2Tilemap, REG_BG2CNT, 0x200);
    set_tilemap_and_decompress_bg(0, 0, gMedabotBuildBg3Tilemap, REG_BG3CNT, 0x200);
    if (gGameWork.enteredFromSubmenu == 0) {
        CpuFastSet(gMedabotBuildBgPalette, gPaletteBackupBg, 0x70);
        CpuFastSet(gMenuObjPalettes, gPaletteBackup, 0x40);
        CpuFastSet(gGradientPaletteOlive, (void *)0x0202F980, 8);
        CpuFastSet(gGradientPaletteOlive + 0x20, (void *)0x0202F9A0, 8);
        CpuFastSet(gGradientPaletteOlive - 0x20, (void *)0x0202F9E0, 8);
        CpuFastSet(gCursorArrowPalette, (void *)0x0202F9C0, 8);
        gGameWork.detailRow = 0;
        medabot_detail_take_apart();
        gGameWork.stepCounter = 0;
    } else {
        CpuFastSet(gMedabotBuildBgPalette, (void *)0x05000000, 0x70);
        CpuFastSet(gMenuObjPalettes, (void *)0x05000200, 0x40);
        CpuFastSet(gGradientPaletteOlive, (void *)0x05000380, 8);
        CpuFastSet(gGradientPaletteOlive + 0x20, (void *)0x050003A0, 8);
        CpuFastSet(gGradientPaletteOlive - 0x20, (void *)0x050003E0, 8);
        CpuFastSet(gCursorArrowPalette, (void *)0x050003C0, 8);
        set_blend_effect_mode(5, 0x3F, 0x20);
    }
    zero = 0;
    CpuFastSet(&zero, gSpriteEntries, 0x01000800);
    REG_DISPCNT |= 0x1F40;
    REG_DISPCNT &= 0xFFDF;
    gGameWork.detailInvalid = 0;
    gGameWork.noAffineSprites = 1;
    medabot_detail_draw_row_icon_0(0);
    medabot_detail_draw_row_icon_1(0);
    medabot_detail_draw_row_icon_2(0);
    medabot_detail_draw_row_icon_3(0);
    medabot_detail_draw_row_icon_4(0);
    medabot_detail_draw_medal_nickname();
    medabot_detail_draw_medal_icon();
    medabot_detail_draw_medal_kind_name();
    medabot_detail_draw_medal_level();
    medabot_detail_draw_head_name();
    medabot_detail_draw_head_skill_icon();
    medabot_detail_draw_rarm_name();
    medabot_detail_draw_rarm_skill_icon();
    medabot_detail_draw_larm_name();
    medabot_detail_draw_larm_skill_icon();
    medabot_detail_draw_legs_name();
    medabot_detail_draw_legs_skill_icon();
    medabot_detail_draw_legs_type_icon();
    medabot_detail_load_icon_gfx();
    init_battle_medabot_sprites(gGameWork.shownHead, gGameWork.shownRightArm, gGameWork.shownLeftArm,
                                gGameWork.shownLegs, 0, 6, 0xA8, 0x20, gGameWork.detailBot, 1, 5);
    medabot_detail_place_row_arrows();
    if (gGameWork.enteredFromSubmenu)
        medabot_detail_init_bot_sprite();
    gGameWork.stepCounter = 0;
    gGameSubState++;
}

// Game state 3, sub-states 16-26: the Medabot detail ("Build") screen, runtime-checked from the
// Medabots list (A). 18 = input: B back to the list (19-21), L/R switch Medabot, A on a row opens
// its Medal (game state 4) or Medapart (game state 5) info screen (24-26).
// 32-35 / 40-43 leave for a battle / race, 48-60 exchange the team over the link (not checked).
void medabot_detail_fade_in(void) {
    struct GameWork *st;
    u8 *done;
    u8 *frame;

    medabots_scroll_bg3();
    medabot_detail_draw_bot_sprite();
    medabot_detail_blink_row_arrows();
    medabot_detail_blink_row_icon();
    medabot_detail_update_invalid_bot();
    medabot_detail_animate_invalid_bot();
    st = &gGameWork;
    done = &st->enteredFromSubmenu;
    if (*done == 0) {
        frame = &st->stepCounter;
        if (*frame > 8)
            goto finish;
        bg_palettes_blend_masked_now(0, 32 - *frame * 4, 0xFFFF);
        obj_palettes_blend_masked_now(0, 32 - *frame * 4, 0xF0FF);
        (*frame)++;
    } else if (update_blend_effect()) {
    finish:
        *done = 1;
        gGameSubState++;
    }
}

void medabot_detail_handle_input(void) {
    u8 r;

    medabots_scroll_bg3();
    medabot_detail_draw_bot_sprite();
    medabot_detail_blink_row_arrows();
    medabot_detail_blink_row_icon();
    medabot_detail_update_invalid_bot();
    medabot_detail_animate_invalid_bot();
    if (medabot_detail_row_cursor_input() || medabot_detail_cycle_medal_input() || medabot_detail_cycle_head_input() ||
        medabot_detail_cycle_rarm_input() || medabot_detail_cycle_larm_input() || medabot_detail_cycle_legs_input() ||
        medabot_detail_equip_full_set_input())
        return;
    if (KEYS_LO(gNewKeys) & 2) {
        play_sound_effect(5);
        gGameSubState++;
    } else if (*((u8 *)&gNewKeys + 1) & 3) {
        play_sound_effect(2);
        gGameWork.detailBot ^= 1;
        medabot_detail_redraw_bot_sprite();
        medabot_detail_place_icon();
    } else {
        r = medabot_detail_check_row_select();
        if (r == 2)
            play_sound_effect(6);
        else if (r == 1) {
            play_sound_effect(4);
            gGameSubState = 24;
        }
    }
}

void medabot_detail_exit_start(void) {
    struct GameWork *st;
    u8 v;

    medabots_scroll_bg3();
    medabot_detail_draw_bot_sprite();
    medabot_detail_blink_row_arrows();
    medabot_detail_blink_row_icon();
    medabot_detail_update_invalid_bot();
    medabot_detail_animate_invalid_bot();
    st = &gGameWork;
    v = st->medabotsMode;
    if (v == 0) {
        palette_backup_from_hardware();
        st->stepCounter = v;
    } else
        set_blend_effect_mode(6, 0x3F, 0x20);
    gGameSubState++;
}

void medabot_detail_exit_fade(void) {
    u8 *frame;

    medabots_scroll_bg3();
    medabot_detail_draw_bot_sprite();
    medabot_detail_blink_row_arrows();
    medabot_detail_blink_row_icon();
    medabot_detail_update_invalid_bot();
    medabot_detail_animate_invalid_bot();
    if (gGameWork.medabotsMode == 0) {
        frame = &gGameWork.stepCounter;
        if (*frame > 8)
            goto finish;
        bg_palettes_blend_masked_now(0, *frame * 4, 0xFFFF);
        obj_palettes_blend_masked_now(0, *frame * 4, 0xF0FF);
        (*frame)++;
    } else if (update_blend_effect()) {
    finish:
        gGameSubState++;
    }
}

void medabot_detail_return_to_list(void) {
    medabot_detail_draw_bot_sprite();
    assign_medal_to_team_slot();
    gGameSubState = 0;
}

void medabot_detail_open_info_start(void) {
    medabots_scroll_bg3();
    medabot_detail_draw_bot_sprite();
    medabot_detail_blink_row_arrows();
    medabot_detail_blink_row_icon();
    medabot_detail_update_invalid_bot();
    medabot_detail_animate_invalid_bot();
    set_blend_effect_mode(6, 0x3F, 0x20);
    gGameSubState++;
}

void medabot_detail_open_info_fade(void) {
    medabots_scroll_bg3();
    medabot_detail_draw_bot_sprite();
    medabot_detail_blink_row_arrows();
    medabot_detail_blink_row_icon();
    medabot_detail_update_invalid_bot();
    medabot_detail_animate_invalid_bot();
    if (update_blend_effect())
        gGameSubState++;
}

void medabot_detail_open_info(void) {
    clear_battle_sprite_slot(0, 0x80);
    gGameWork.noAffineSprites = 0;
    gVBlankOamMode = 0;
    switch (gGameWork.detailRow) {
    case 0:
        mem_fill8(&gGameWork.openedFrom, 0x14, 0);
        gGameWork.openedFrom = 1;
        gGameWork.shownId = gGameWork.shownMedal;
        count_unequipped_medals();
        gGameState = 4;
        gGameSubState = 8;
        break;
    case 1:
        mem_fill8(&gGameWork.openedFrom, 0x14, 0);
        gGameWork.openedFrom = 1;
        gGameWork.shownId = gGameWork.shownHead;
        gGameWork.partSlot = 0;
        gGameState = 5;
        gGameSubState = 16;
        break;
    case 2:
        mem_fill8(&gGameWork.openedFrom, 0x14, 0);
        gGameWork.openedFrom = 1;
        gGameWork.shownId = gGameWork.shownRightArm;
        gGameWork.partSlot = 1;
        gGameState = 5;
        gGameSubState = 16;
        break;
    case 3:
        mem_fill8(&gGameWork.openedFrom, 0x14, 0);
        gGameWork.openedFrom = 1;
        gGameWork.shownId = gGameWork.shownLeftArm;
        gGameWork.partSlot = 2;
        gGameState = 5;
        gGameSubState = 16;
        break;
    case 4:
        mem_fill8(&gGameWork.openedFrom, 0x14, 0);
        gGameWork.openedFrom = 1;
        gGameWork.shownId = gGameWork.shownLegs;
        gGameWork.partSlot = 3;
        gGameState = 5;
        gGameSubState = 16;
        break;
    }
}

// Sub-states 32-35 (battle) and 40-43 (race): the team is picked; the pick markers blink for 60 frames, then
// the screen fades out. A link battle (unk50 == 1) goes to 48 instead.
void team_select_done_start(void) {
    medabots_scroll_bg3();
    medabots_screen_place_team_icons();
    medabots_screen_draw_bot_sprite();
    disable_sprites(0, 4);
    gGameWork.timer = 0;
    gGameSubState++;
}

void team_select_battle_wait(void) {
    medabots_scroll_bg3();
    medabots_screen_draw_bot_sprite();
    team_select_blink_pick_markers();
    if (gGameWork.timer > 60) {
        if (gGameWork.medabotsMode == 1)
            gGameSubState = 48;
        else {
            palette_backup_from_hardware();
            gGameWork.stepCounter = 0;
            gGameSubState++;
        }
    }
}

void team_select_battle_fade_out(void) {
    struct GameWork *st;
    u8 *frame;

    medabots_scroll_bg3();
    medabots_screen_draw_bot_sprite();
    team_select_blink_pick_markers();
    st = &gGameWork;
    frame = &st->stepCounter;
    if (*frame <= 32) {
        bg_palettes_blend_masked_now(0, *frame, 0xFFFF);
        obj_palettes_blend_masked_now(0, *frame, 0xFFFF);
        (*frame)++;
    } else
        gGameSubState++;
}

void team_select_exit_battle(void) {
    clear_battle_sprite_slot(0, 0x80);
    gGameWork.noAffineSprites = 0;
    gVBlankOamMode = 0;
    gGameState = 7;
    gGameSubState = 0;
}

void team_select_race_wait(void) {
    medabots_scroll_bg3();
    medabots_screen_draw_bot_sprite();
    team_select_blink_pick_markers();
    if (gGameWork.timer > 60) {
        fade_out_music(8);
        set_blend_effect_mode(6, 0x3F, 8);
        gGameSubState++;
    }
}

void team_select_race_fade_out(void) {
    medabots_scroll_bg3();
    medabots_screen_draw_bot_sprite();
    team_select_blink_pick_markers();
    if (update_blend_effect())
        gGameSubState++;
}

void team_select_exit_race(void) {
    s32 i;

    clear_battle_sprite_slot(0, 0x80);
    gGameWork.noAffineSprites = 0;
    gVBlankOamMode = 0;
    for (i = 0; i <= 2; i++) {
        load_part_data(gTeamSlots[gBattleWork.teamPicks[i] & 0xF].legs, 3, &gGameWork.partAbility);
        gBattleWork.raceLegTypes[i] = gGameWork.partSkill - 100;
        gBattleWork.raceParts[i][0] = gTeamSlots[gBattleWork.teamPicks[i] & 0xF].head;
        gBattleWork.raceParts[i][1] = gTeamSlots[gBattleWork.teamPicks[i] & 0xF].rightArm;
        gBattleWork.raceParts[i][2] = gTeamSlots[gBattleWork.teamPicks[i] & 0xF].leftArm;
        gBattleWork.raceParts[i][3] = gTeamSlots[gBattleWork.teamPicks[i] & 0xF].legs;
    }
    gGameMode = 3;
    gGameState = 4;
    gGameSubState = 5;
}

// Sub-states 48-60: link battle. Show gLinkMessages[11], set up the team, wait for the partner, swap the
// gBattleBots bot records (53), then compare checksums (57; a mismatch retries from 50).
// guess: 53 jumps straight to 58, so 54-57 look unused (code-read only, no link scenario).
void team_select_link_message_start(void) {
    medabots_scroll_bg3();
    medabots_screen_draw_bot_sprite();
    text_window_init(1, 0, 0);
    gGameSubState++;
}

void team_select_link_message_run(void) {
    medabots_scroll_bg3();
    medabots_screen_draw_bot_sprite();
    if (run_message(gLinkMessages[11]))
        gGameSubState++;
}

void team_select_link_setup_bots(void) {
    medabots_scroll_bg3();
    medabots_screen_draw_bot_sprite();
    clear_battle_bot_array();
    count_active_battle_bots();
    battle_setup_team_bots();
    gGameSubState++;
}

void team_select_link_wait_ready(void) {
    medabots_scroll_bg3();
    medabots_screen_draw_bot_sprite();
    if (link_sync_both_ready()) {
        gLinkPackets.sendData = 0;
        gGameWork.stepTimer = 0;
        gGameSubState++;
    }
}

void team_select_link_exchange_init(void) {
    struct GameWork *st;
    u16 *timer;

    medabots_scroll_bg3();
    medabots_screen_draw_bot_sprite();
    st = &gGameWork;
    timer = &st->stepTimer;
    if (*timer == 24) {
        gBattleWork.unk51 = 0;
        gBattleWork.unk52 = 0;
        gBattleWork.unk53 = 0;
        gBattleWork.linkRecvPos = 0;
        gBattleWork.linkSentSum = 0;
        gBattleWork.linkRecvSum = 0;
        gBattleWork.linkPartnerSentSum = 0;
        gBattleWork.linkPartnerRecvSum = 0;
        gBattleWork.linkSendToggle = 0;
        gBattleWork.linkRecvToggle = 1;
        *timer = 0;
        gGameSubState++;
    } else
        (*timer)++;
}

// guess: sends 3 x 0x48 bytes from gBattleBots and receives into gLinkPartnerBotData over the link, one
// byte per packet (bit 15 = valid, bit 8 = toggle), summing the received bytes in linkRecvSum. Near miss:
// scratch/sub_08004AF8_nearmiss.c (one literal load order and an orrs/adds for the 0x8000 header).

void team_select_link_exchange_bots(void) {
    struct BattleWork *s;
    s16 flag;
    u8 *src;

    medabots_scroll_bg3();
    medabots_screen_draw_bot_sprite();
    s = &gBattleWork;
    if (s->unk51 != 3) {
        src = (u8 *)&gBattleBots[s->unk51];
        gLinkPackets.sendData = src[s->unk52] + (flag = ((s->linkSendToggle << 8) & 0x100) + 0x8000);
        if (++gGameWork.stepTimer == 4) {
            gGameWork.stepTimer = 0;
            s->linkSendToggle ^= 1;
            if (++s->unk52 == 0x48) {
                s->unk51++;
                s->unk52 = 0;
            }
        }
    }
    if (gBattleWork.unk53 != 3) {
        u16 v = gLinkPackets.recv[gLinkPlayerId ^ 1][1];

        if ((v & 0x8000) && (u16)(v & 0x100) >> 8 != gBattleWork.linkRecvToggle) {
            gBattleWork.linkRecvToggle ^= 1;
            ((struct LinkRow256 *)gLinkPartnerBotData)[gBattleWork.unk53].b[gBattleWork.linkRecvPos] = v;
            gBattleWork.linkRecvSum = (gBattleWork.linkRecvSum + (v & 0xFF)) & 0x7FFF;
            if (++gBattleWork.linkRecvPos == 0x48) {
                gBattleWork.unk53++;
                gBattleWork.linkRecvPos = 0;
            }
        }
    }
    if (gBattleWork.unk51 == 3)
        if (gBattleWork.unk53 == 3) {
            gGameSubState = 58;
            gGameWork.stepTimer = 0;
        }
}

void team_select_link_checksum_init(void) {
    struct GameWork *st;
    u16 *timer;

    medabots_scroll_bg3();
    medabots_screen_draw_bot_sprite();
    st = &gGameWork;
    timer = &st->stepTimer;
    if (*timer == 16) {
        gBattleWork.unk51 = 0;
        gBattleWork.unk52 = 0;
        gBattleWork.unk53 = 0;
        gBattleWork.linkRecvPos = 0;
        *timer = 0;
        gGameSubState++;
    } else
        (*timer)++;
}

void team_select_link_compare_checksums(void) {
    u16 v;

    medabots_scroll_bg3();
    medabots_screen_draw_bot_sprite();
    if (gBattleWork.unk51 < 2) {
        switch (gBattleWork.unk51) {
        case 0:
            gLinkPackets.sendData = 0x8000 + gBattleWork.linkSentSum;
            break;
        case 1:
            gLinkPackets.sendData = 0x8000 + gBattleWork.linkRecvSum;
            break;
        }
        gBattleWork.unk51++;
    }
    v = gLinkPackets.recv[gLinkPlayerId ^ 1][1];
    if (v & 0x8000) {
        switch (gBattleWork.unk52) {
        case 0:
            gBattleWork.linkPartnerSentSum = v & 0x7FFF;
            break;
        case 1:
            gBattleWork.linkPartnerRecvSum = v & 0x7FFF;
            break;
        }
        if (++gBattleWork.unk52 == 2) {
            if (gBattleWork.linkSentSum == gBattleWork.linkPartnerRecvSum &&
                gBattleWork.linkRecvSum == gBattleWork.linkPartnerSentSum)
                gGameSubState++;
            else
                gGameSubState = 50;
        }
    }
}

void team_select_link_done_start(void) {
    gLinkPackets.sendData = 0;
    medabots_scroll_bg3();
    medabots_screen_draw_bot_sprite();
    team_select_link_load_opponents();
    palette_backup_from_hardware();
    gGameWork.stepCounter = 0;
    gGameSubState++;
}

void team_select_link_fade_out(void) {
    struct GameWork *st;
    u8 *frame;

    medabots_scroll_bg3();
    medabots_screen_draw_bot_sprite();
    st = &gGameWork;
    frame = &st->stepCounter;
    if (*frame <= 32) {
        bg_palettes_blend_masked_now(0, *frame, 0xFFFF);
        obj_palettes_blend_masked_now(0, *frame, 0xFFFF);
        (*frame)++;
    } else
        gGameSubState++;
}

void team_select_link_exit_battle(void) {
    clear_battle_sprite_slot(0, 0x80);
    gGameWork.noAffineSprites = 0;
    gVBlankOamMode = 0;
    gGameState = 7;
    gGameSubState = 0;
}

static void medabots_scroll_bg3(void) {
    if (gFrameCounter & 1) {
        gBg3Scroll.x++;
        gBg3Scroll.y++;
    }
}

static void medabots_screen_init_cursor_icons(void) {
    gSpriteEntries[0].flags =
        SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_AFFINE | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[0].unk23 = 0;
    medabots_screen_orbit_cursor_icon(0);
    gSpriteEntries[1].flags =
        SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_AFFINE | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[1].unk23 = 0x10;
    medabots_screen_orbit_cursor_icon(1);
    gSpriteEntries[2].flags =
        SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_AFFINE | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[2].unk23 = 0x20;
    medabots_screen_orbit_cursor_icon(2);
    gSpriteEntries[3].flags =
        SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_AFFINE | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[3].unk23 = 0x30;
    medabots_screen_orbit_cursor_icon(3);
}

static void medabots_screen_orbit_cursor_icon(u32 i) {
    u32 cx = gMedabotsCursorOrbitCenters[gGameWork.medabotsCursor * 2];
    u32 cy = gMedabotsCursorOrbitCenters[gGameWork.medabotsCursor * 2 + 1];
    struct Vec16 p = compute_polar_to_screen_position(((gSpriteEntries[i].unk23 + 16) & 0x3F) * 4, 16, cx, cy, 8, 0);

    gSpriteEntries[i].x = p.x;
    gSpriteEntries[i].y = p.y;
    gSpriteEntries[i].frame = 0x400;
    gSpriteEntries[i].palette = 12;
    gSpriteEntries[i].frame_table = 0;
    gSpriteEntries[i].scale_y = 0x40 - (cy + 8 - gSpriteEntries[i].y) * 3;
    gSpriteEntries[i].scale_x = 0x60 - (cy + 8 - gSpriteEntries[i].y) * 3;
    if (cy > gSpriteEntries[i].y)
        gSpriteEntries[i].order = gMedabotsSlotSpritePriorities[gGameWork.medabotsCursor] - 1;
    else
        gSpriteEntries[i].order = gMedabotsSlotSpritePriorities[gGameWork.medabotsCursor] + 4;
    gSpriteEntries[i].angle = gSpriteEntries[i].unk23 << 4;
    gSpriteEntries[i].unk23 = (gSpriteEntries[i].unk23 + 1) & 0x3F;
}

static void medabots_screen_load_team_icon_gfx(void) {
    u32 i;
    struct TeamSlot *bot;

    i = 0;
    bot = gTeamSlots;
    do {
        if (bot->state)
            decompress_sprite_to_vram_08042D94(bot->head, bot->rightArm, bot->leftArm, bot->legs, i);
        bot++;
        i++;
    } while (i <= 8);
}

static void medabots_screen_place_team_icons(void) {
    u32 i;

    for (i = 0; i <= 8; i++) {
        if (gTeamSlots[i].state)
            init_battle_medabot_sprites(gTeamSlots[i].head, gTeamSlots[i].rightArm, gTeamSlots[i].leftArm,
                                        gTeamSlots[i].legs, i, 10 + i * 4, gMedabotsSlotPositions[i * 2],
                                        gMedabotsSlotPositions[i * 2 + 1], gGameWork.detailBot, 1,
                                        gMedabotsSlotSpritePriorities[i]);
        else
            disable_sprites(10 + i * 4, 4);
    }
}

static void medabots_screen_draw_legs_type_icons(void) {
    u32 i;

    for (i = 0; i <= 8; i++) {
        if (gTeamSlots[i].state) {
            if (gTeamSlots[i].legs <= 0x77) {
                load_part_data(gTeamSlots[i].legs, 3, &gGameWork.partAbility);
                draw_tilemap_with_offset(gGameWork.partSkill - 100, gMedabotsSlotPedestalTilePositions[i * 2],
                                         gMedabotsSlotPedestalTilePositions[i * 2 + 1], REG_BG1CNT, 0x8300);
            } else
                draw_tilemap_with_offset(0xFF, gMedabotsSlotPedestalTilePositions[i * 2],
                                         gMedabotsSlotPedestalTilePositions[i * 2 + 1], REG_BG1CNT, 0x8300);
        } else
            draw_tilemap_with_offset(0xFF, gMedabotsSlotPedestalTilePositions[i * 2],
                                     gMedabotsSlotPedestalTilePositions[i * 2 + 1], REG_BG1CNT, 0x8300);
    }
}

// The selected Medabot's Medal nickname (Medal record unkA) as text sprites, or blanks.
static void medabots_screen_draw_medal_nickname(void) {
    disable_sprites(0x32, 10);
    if (gTeamSlots[gGameWork.medabotsCursor].state > 1)
        render_text_sprites_08040DB8((u8 *)0x03000BAA +
                                         find_medal_slot_by_id(gTeamSlots[gGameWork.medabotsCursor].medal) * 64,
                                     0x32, 1, 13, 10, 13, 0, 2);
    else {
        fill_text_blank(gGameWork.textBuf, 10);
        render_text_sprites_08040DB8(gGameWork.textBuf, 0x32, 1, 13, 10, 13, 0, 2);
    }
}

// The selected Medabot's Medal kind name (gMedalNames), or blanks.
static void medabots_screen_draw_medal_kind_name(void) {
    disable_sprites(0x3C, 10);
    if (gTeamSlots[gGameWork.medabotsCursor].state > 1) {
        memcpy_bytes_0803F63C((const void *)gMedalNames[gTeamSlots[gGameWork.medabotsCursor].medal], gGameWork.textBuf,
                              11);
        render_text_sprites_08040DB8(gGameWork.textBuf, 0x3C, 4, 16, 7, 14, 1, 2);
    } else {
        fill_text_blank(gGameWork.textBuf, 9);
        render_text_sprites_08040DB8(gGameWork.textBuf, 0x3C, 4, 16, 7, 14, 1, 2);
    }
}

static void medabots_screen_draw_medal_icon(void) {
    if (gTeamSlots[gGameWork.medabotsCursor].state > 1)
        CpuFastSet(gMedalIconTiles + gTeamSlots[gGameWork.medabotsCursor].medal * 0x80, (void *)0x06006600, 0x20);
    else
        CpuFastSet(gMedalIconBlankTiles, (void *)0x06006600, 0x20);
    draw_tile_block(2, 2, 1, 16, REG_BG1CNT, 0x6330);
}

static void medabots_screen_init_bot_sprite(void) {
    struct SpriteTree *obj = (struct SpriteTree *)0x02026000;
    u8 *b;
    u8 *c;
    u32 fill;

    mem_fill8((u8 *)obj, 0xD0, 0);
    b = (u8 *)0x020260D0;
    mem_fill8(b, 0x800, 0);
    c = (u8 *)0x020268D0;
    mem_fill8(c, 0x60, 0);
    gVBlankOamMode = 2;
    gSpriteWork = (struct SpriteWork *)0x02024000;
    fill = 0;
    CpuFastSet(&fill, (void *)0x02024000, 0x01000426);
    gMedabotSpriteSlots = (struct MedabotSpriteSlot *)c;
    init_sprite_tree(obj, (u8 *)gSpriteWork, (struct SpriteNodeDesc **)gMedabotSpriteNodeDescs,
                     (struct SpriteNodeOam *)b);
    obj->oams = (struct SpriteNodeOam *)b;
    if (gGameWork.detailBot)
        setup_medabot_part_sprites(gSpriteWork->oamBuf, obj, gTeamSlots[gGameWork.medabotsCursor].head,
                                   gTeamSlots[gGameWork.medabotsCursor].rightArm,
                                   gTeamSlots[gGameWork.medabotsCursor].leftArm,
                                   gTeamSlots[gGameWork.medabotsCursor].legs, 0x28, 0x28, 0x1C2, 8, 1, 1);
    else
        setup_medabot_part_sprites(gSpriteWork->oamBuf, obj, gTeamSlots[gGameWork.medabotsCursor].head,
                                   gTeamSlots[gGameWork.medabotsCursor].rightArm,
                                   gTeamSlots[gGameWork.medabotsCursor].leftArm,
                                   gTeamSlots[gGameWork.medabotsCursor].legs, 0x28, 0x28, 0x1C2, 8, 1, 0);
}

static void medabots_screen_redraw_bot_sprite(void) {
    struct SpriteTree *obj = (struct SpriteTree *)0x02026000;
    u32 fill;

    obj->oams = (struct SpriteNodeOam *)0x020260D0;
    if (gGameWork.detailBot)
        setup_medabot_part_sprites(gSpriteWork->oamBuf, obj, gTeamSlots[gGameWork.medabotsCursor].head,
                                   gTeamSlots[gGameWork.medabotsCursor].rightArm,
                                   gTeamSlots[gGameWork.medabotsCursor].leftArm,
                                   gTeamSlots[gGameWork.medabotsCursor].legs, 0x28, 0x28, 0x1C2, 8, 1, 1);
    else
        setup_medabot_part_sprites(gSpriteWork->oamBuf, obj, gTeamSlots[gGameWork.medabotsCursor].head,
                                   gTeamSlots[gGameWork.medabotsCursor].rightArm,
                                   gTeamSlots[gGameWork.medabotsCursor].leftArm,
                                   gTeamSlots[gGameWork.medabotsCursor].legs, 0x28, 0x28, 0x1C2, 8, 1, 0);
    fill = 0x200;
    CpuFastSet(&fill, gSpriteWork->oamBuf, 0x01000100);
    gSpriteWork->oamCount = 0;
    gSpriteWork->affineIdx = 0;
}

static void medabots_screen_draw_bot_sprite(void) {
    if (gTeamSlots[gGameWork.medabotsCursor].state) {
        if (gGameWork.detailBot)
            setup_medabot_part_sprites(
                gSpriteWork->oamBuf, (struct SpriteTree *)0x02026000, gTeamSlots[gGameWork.medabotsCursor].head,
                gTeamSlots[gGameWork.medabotsCursor].rightArm, gTeamSlots[gGameWork.medabotsCursor].leftArm,
                gTeamSlots[gGameWork.medabotsCursor].legs, 0x3C, 0x32, 0x1C2, 8, 5, 1);
        else
            setup_medabot_part_sprites(
                gSpriteWork->oamBuf, (struct SpriteTree *)0x02026000, gTeamSlots[gGameWork.medabotsCursor].head,
                gTeamSlots[gGameWork.medabotsCursor].rightArm, gTeamSlots[gGameWork.medabotsCursor].leftArm,
                gTeamSlots[gGameWork.medabotsCursor].legs, 0x3C, 0x32, 0x1C2, 8, 5, 0);
    }
}

// D-pad moves the slot cursor (gGameWork.medabotsCursor) through gMedabotSlotDpadMoves and redraws the
// selected Medabot's info. Runtime: RIGHT from slot 0 -> 3. Returns 1 if the cursor moved.
static u32 medabots_screen_cursor_input(void) {
    u32 moved = 0;
    const u8 *next;

    if (KEYS_LO(gRepeatKeys) & 0x40) {
        next = gMedabotSlotDpadMoves[0];
        moved = 1;
    }
    if (KEYS_LO(gRepeatKeys) & 0x80) {
        next = gMedabotSlotDpadMoves[1];
        moved = 1;
    }
    if (KEYS_LO(gRepeatKeys) & 0x20) {
        next = gMedabotSlotDpadMoves[2];
        moved = 1;
    }
    if (KEYS_LO(gRepeatKeys) & 0x10) {
        next = gMedabotSlotDpadMoves[3];
        moved = 1;
    }
    if (moved) {
        play_sound_effect(2);
        gGameWork.medabotsCursor = next[gGameWork.medabotsCursor];
        medabots_screen_orbit_cursor_icon(0);
        medabots_screen_orbit_cursor_icon(1);
        medabots_screen_orbit_cursor_icon(2);
        medabots_screen_orbit_cursor_icon(3);
        medabots_screen_draw_medal_nickname();
        medabots_screen_draw_medal_kind_name();
        medabots_screen_draw_medal_icon();
        medabots_screen_redraw_bot_sprite();
        medabots_screen_place_team_icons();
        medabots_screen_flag_invalid_bot();
        return 1;
    }
    return 0;
}

static void medabots_screen_start_reorder_orbit(void) {
    gSpriteEntries[4].flags =
        SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_AFFINE | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[4].unk23 = 0;
    medabots_screen_orbit_reorder_icon(4);
    gSpriteEntries[5].flags =
        SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_AFFINE | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[5].unk23 = 0x10;
    medabots_screen_orbit_reorder_icon(5);
    gSpriteEntries[6].flags =
        SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_AFFINE | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[6].unk23 = 0x20;
    medabots_screen_orbit_reorder_icon(6);
    gSpriteEntries[7].flags =
        SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_AFFINE | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[7].unk23 = 0x30;
    medabots_screen_orbit_reorder_icon(7);
}

static void medabots_screen_orbit_reorder_icon(u32 i) {
    u32 cx = gMedabotsCursorOrbitCenters[(gGameWork.reorderPick & 0x7F) * 2];
    u32 cy = gMedabotsCursorOrbitCenters[(gGameWork.reorderPick & 0x7F) * 2 + 1] - 4;
    struct Vec16 p = compute_polar_to_screen_position(((gSpriteEntries[i].unk23 + 16) & 0x3F) * 4, 16, cx, cy, 8, 0);

    gSpriteEntries[i].x = p.x;
    gSpriteEntries[i].y = p.y;
    gSpriteEntries[i].frame = 0x400;
    gSpriteEntries[i].palette = 12;
    gSpriteEntries[i].frame_table = 0;
    gSpriteEntries[i].scale_y = 0x40 - (cy + 8 - gSpriteEntries[i].y) * 3;
    gSpriteEntries[i].scale_x = 0x60 - (cy + 8 - gSpriteEntries[i].y) * 3;
    if (cy > gSpriteEntries[i].y)
        gSpriteEntries[i].order = gMedabotsSlotSpritePriorities[gGameWork.reorderPick & 0x7F] - 1;
    else
        gSpriteEntries[i].order = gMedabotsSlotSpritePriorities[gGameWork.reorderPick & 0x7F] + 4;
    gSpriteEntries[i].angle = gSpriteEntries[i].unk23 << 4;
    gSpriteEntries[i].unk23 = (gSpriteEntries[i].unk23 - 1) & 0x3F;
}

static void medabots_screen_update_reorder_icons(void) {
    if (gGameWork.reorderPick & 0x80) {
        if (gFrameCounter & 1) {
            gSpriteEntries[4].flags |= SPRITE_FLAG_VISIBLE;
            gSpriteEntries[5].flags |= SPRITE_FLAG_VISIBLE;
            gSpriteEntries[6].flags |= SPRITE_FLAG_VISIBLE;
            gSpriteEntries[7].flags |= SPRITE_FLAG_VISIBLE;
        } else {
            gSpriteEntries[4].flags &= (u16)~SPRITE_FLAG_VISIBLE;
            gSpriteEntries[5].flags &= (u16)~SPRITE_FLAG_VISIBLE;
            gSpriteEntries[6].flags &= (u16)~SPRITE_FLAG_VISIBLE;
            gSpriteEntries[7].flags &= (u16)~SPRITE_FLAG_VISIBLE;
        }
        medabots_screen_orbit_reorder_icon(4);
        medabots_screen_orbit_reorder_icon(5);
        medabots_screen_orbit_reorder_icon(6);
        medabots_screen_orbit_reorder_icon(7);
    } else {
        gSpriteEntries[4].flags &= (u16)~SPRITE_FLAG_VISIBLE;
        gSpriteEntries[5].flags &= (u16)~SPRITE_FLAG_VISIBLE;
        gSpriteEntries[6].flags &= (u16)~SPRITE_FLAG_VISIBLE;
        gSpriteEntries[7].flags &= (u16)~SPRITE_FLAG_VISIBLE;
    }
}

// SELECT ("REORDER"): first press picks the slot (unk52 = slot | 0x80, icons orbit it), second press
// swaps the two gTeamSlots entries. Runtime-checked: slot 3 picked (unk52 0x83), then swapped with 0.
static u32 medabots_screen_reorder_input(void) {
    if (gGameWork.medabotsMode == 0 && (KEYS_LO(gNewKeys) & 4)) {
        play_sound_effect(2);
        if (gGameWork.reorderPick & 0x80) {
            gGameWork.reorderPick &= 0x7F;
            if (gGameWork.reorderPick != gGameWork.medabotsCursor) {
                memswap(&gTeamSlots[gGameWork.reorderPick], &gTeamSlots[gGameWork.medabotsCursor], 8);
                medabots_screen_load_team_icon_gfx();
                medabots_screen_place_team_icons();
                medabots_screen_draw_legs_type_icons();
                medabots_screen_draw_medal_nickname();
                medabots_screen_draw_medal_kind_name();
                medabots_screen_draw_medal_icon();
                medabots_screen_redraw_bot_sprite();
                medabots_screen_flag_invalid_bot();
            }
            gGameWork.reorderPick = 0;
        } else {
            gGameWork.reorderPick = gGameWork.medabotsCursor + 0x80;
            medabots_screen_start_reorder_orbit();
        }
        medabots_screen_update_reorder_icons();
        return 1;
    }
    return 0;
}

static void medabots_screen_flag_invalid_bot(void) {
    if (validate_medapart_stats(gTeamSlots[gGameWork.medabotsCursor].medal, gTeamSlots[gGameWork.medabotsCursor].head,
                                gTeamSlots[gGameWork.medabotsCursor].rightArm,
                                gTeamSlots[gGameWork.medabotsCursor].leftArm,
                                gTeamSlots[gGameWork.medabotsCursor].legs))
        battle_sprite_group_set_anim(gGameWork.medabotsCursor * 4 + 10, 8);
}

static void medabots_screen_animate_invalid_bot(void) {
    if (validate_medapart_stats(gTeamSlots[gGameWork.medabotsCursor].medal, gTeamSlots[gGameWork.medabotsCursor].head,
                                gTeamSlots[gGameWork.medabotsCursor].rightArm,
                                gTeamSlots[gGameWork.medabotsCursor].leftArm,
                                gTeamSlots[gGameWork.medabotsCursor].legs))
        update_battle_sprite_orbiting_positions(gGameWork.medabotsCursor * 4 + 10, gGameWork.medabotsCursor, 0);
}

// Detail screen entry: takes the selected Medabot apart into the edit copy: Medal slot (unk97, 0x1E = none) and
// parts to unk98-9B, the parts back into the inventory, slot marked empty (assign_medal_to_team_slot puts it back).
// guess: matches the Build screen (parts can be swapped freely), not runtime-checked.
// back into the inventory (modify_medapart_quantity), slot marked empty.
static void medabot_detail_take_apart(void) {
    if (gTeamSlots[gGameWork.medabotsCursor].medal == 0x1E)
        gGameWork.shownMedal = 0x1E;
    else
        gGameWork.shownMedal = find_medal_slot_by_id(gTeamSlots[gGameWork.medabotsCursor].medal) - 1;
    gGameWork.shownHead = gTeamSlots[gGameWork.medabotsCursor].head;
    gGameWork.shownRightArm = gTeamSlots[gGameWork.medabotsCursor].rightArm;
    gGameWork.shownLeftArm = gTeamSlots[gGameWork.medabotsCursor].leftArm;
    gGameWork.shownLegs = gTeamSlots[gGameWork.medabotsCursor].legs;
    if (gGameWork.shownMedal != 0x1E)
        gMedals[gGameWork.shownMedal].flags &= 0xBF;
    gTeamSlots[gGameWork.medabotsCursor].state = 1;
    if (gGameWork.shownHead <= 0x77)
        modify_medapart_quantity(gGameWork.shownHead, 0, 1, 1, 1);
    if (gGameWork.shownRightArm <= 0x77)
        modify_medapart_quantity(gGameWork.shownRightArm, 1, 1, 1, 1);
    if (gGameWork.shownLeftArm <= 0x77)
        modify_medapart_quantity(gGameWork.shownLeftArm, 2, 1, 1, 1);
    if (gGameWork.shownLegs <= 0x77)
        modify_medapart_quantity(gGameWork.shownLegs, 3, 1, 1, 1);
}

static void medabot_detail_draw_medal_nickname(void) {
    disable_sprites(10, 10);
    if (gGameWork.shownMedal < 30)
        render_text_sprites_08040DB8(gMedals[gGameWork.shownMedal].name, 10, 1, 13, 10, 15, 0, 2);
    else {
        fill_text_blank(gGameWork.textBuf, 10);
        render_text_sprites_08040DB8(gGameWork.textBuf, 10, 1, 13, 10, 15, 0, 2);
    }
}

static void medabot_detail_draw_medal_icon(void) {
    if (gGameWork.shownMedal < 30)
        CpuFastSet(gMedalIconTiles + gMedals[gGameWork.shownMedal].graphicId * 0x80, (void *)0x06007800, 0x20);
    else
        CpuFastSet(gMedalIconBlankTiles, (void *)0x06007800, 0x20);
    draw_tile_block(2, 2, 16, 9, REG_BG1CNT, 0x63C0);
}

static void medabot_detail_draw_medal_level(void) {
    if (gGameWork.shownMedal < 30)
        fill_tilemap_pair_or_divide(gMedals[gGameWork.shownMedal].level, 0x1A, 9, REG_BG1CNT, 0xD3A4);
    else
        fill_tilemap_pair_or_divide(0xFF, 0x1A, 9, REG_BG1CNT, 0xD3A4);
}

static void medabot_detail_draw_medal_kind_name(void) {
    disable_sprites(0x14, 10);
    if (gGameWork.shownMedal < 30) {
        memcpy_bytes_0803F63C((const void *)gMedalNames[gMedals[gGameWork.shownMedal].graphicId], gGameWork.textBuf,
                              11);
        render_text_sprites_08040DB8(gGameWork.textBuf, 0x14, 0x12, 9, 7, 12, 1, 2);
    } else {
        fill_text_blank(gGameWork.textBuf, 9);
        render_text_sprites_08040DB8(gGameWork.textBuf, 0x14, 0x12, 9, 7, 12, 1, 2);
    }
}

// Medapart names (gMedapartNames[part][kind]: head, right arm, left arm, legs) at rows 11-17 (runtime-checked).
static void medabot_detail_draw_head_name(void) {
    disable_sprites(0x1E, 14);
    if (gGameWork.shownHead < 120) {
        memcpy_bytes_08041D04((const void *)gMedapartNames[0][gGameWork.shownHead * 4 + 0], gGameWork.textBuf, 15);
        render_text_sprites_08040DB8(gGameWork.textBuf, 0x1E, 0x12, 11, 10, 13, 1, 2);
    } else {
        fill_text_blank(gGameWork.textBuf, 13);
        render_text_sprites_08040DB8(gGameWork.textBuf, 0x1E, 0x12, 11, 10, 13, 1, 2);
    }
}

// Icon after the part name when the Medal's skill (gMedalRecords[...][1]) matches the part's (load_part_data byte 0).
static void medabot_detail_draw_head_skill_icon(void) {
    if (gGameWork.shownHead < 120) {
        if (gGameWork.shownMedal < 30) {
            load_part_data(gGameWork.shownHead, 0, &gGameWork.partAbility);
            memcpy_bytes_08041D04(gMedalRecords[gMedals[gGameWork.shownMedal].graphicId], gGameWork.medalGfxRecord, 16);
            if (gGameWork.partAbility == gGameWork.medalGfxRecord[1])
                draw_tile_block(2, 2, 16, 11, REG_BG1CNT, 0xD340 + gGameWork.medalGfxRecord[7] * 4);
            else
                draw_tile_block(2, 2, 16, 11, REG_BG1CNT, 0xD340);
        } else {
            vram_fill_tilemap_rect(2, 2, 16, 11, REG_BG1CNT, 0);
        }
    } else {
        vram_fill_tilemap_rect(2, 2, 16, 11, REG_BG1CNT, 0);
    }
}

static void medabot_detail_draw_rarm_name(void) {
    disable_sprites(0x2C, 14);
    if (gGameWork.shownRightArm < 120) {
        memcpy_bytes_08041D04((const void *)gMedapartNames[0][gGameWork.shownRightArm * 4 + 1], gGameWork.textBuf, 15);
        render_text_sprites_08040DB8(gGameWork.textBuf, 0x2C, 0x12, 13, 10, 13, 1, 2);
    } else {
        fill_text_blank(gGameWork.textBuf, 13);
        render_text_sprites_08040DB8(gGameWork.textBuf, 0x2C, 0x12, 13, 10, 13, 1, 2);
    }
}

static void medabot_detail_draw_rarm_skill_icon(void) {
    if (gGameWork.shownRightArm < 120) {
        if (gGameWork.shownMedal < 30) {
            load_part_data(gGameWork.shownRightArm, 1, &gGameWork.partAbility);
            memcpy_bytes_08041D04(gMedalRecords[gMedals[gGameWork.shownMedal].graphicId], gGameWork.medalGfxRecord, 16);
            if (gGameWork.partAbility == gGameWork.medalGfxRecord[1])
                draw_tile_block(2, 2, 16, 13, REG_BG1CNT, 0xD340 + gGameWork.medalGfxRecord[7] * 4);
            else
                draw_tile_block(2, 2, 16, 13, REG_BG1CNT, 0xD340);
        } else {
            vram_fill_tilemap_rect(2, 2, 16, 13, REG_BG1CNT, 0);
        }
    } else {
        vram_fill_tilemap_rect(2, 2, 16, 13, REG_BG1CNT, 0);
    }
}

static void medabot_detail_draw_larm_name(void) {
    disable_sprites(0x3A, 14);
    if (gGameWork.shownLeftArm < 120) {
        memcpy_bytes_08041D04((const void *)gMedapartNames[0][gGameWork.shownLeftArm * 4 + 2], gGameWork.textBuf, 15);
        render_text_sprites_08040DB8(gGameWork.textBuf, 0x3A, 0x12, 15, 10, 13, 1, 2);
    } else {
        fill_text_blank(gGameWork.textBuf, 13);
        render_text_sprites_08040DB8(gGameWork.textBuf, 0x3A, 0x12, 15, 10, 13, 1, 2);
    }
}

static void medabot_detail_draw_larm_skill_icon(void) {
    if (gGameWork.shownLeftArm < 120) {
        if (gGameWork.shownMedal < 30) {
            load_part_data(gGameWork.shownLeftArm, 2, &gGameWork.partAbility);
            memcpy_bytes_08041D04(gMedalRecords[gMedals[gGameWork.shownMedal].graphicId], gGameWork.medalGfxRecord, 16);
            if (gGameWork.partAbility == gGameWork.medalGfxRecord[1])
                draw_tile_block(2, 2, 16, 15, REG_BG1CNT, 0xD340 + gGameWork.medalGfxRecord[7] * 4);
            else
                draw_tile_block(2, 2, 16, 15, REG_BG1CNT, 0xD340);
        } else {
            vram_fill_tilemap_rect(2, 2, 16, 15, REG_BG1CNT, 0);
        }
    } else {
        vram_fill_tilemap_rect(2, 2, 16, 15, REG_BG1CNT, 0);
    }
}

static void medabot_detail_draw_legs_name(void) {
    disable_sprites(0x48, 14);
    if (gGameWork.shownLegs < 120) {
        memcpy_bytes_08041D04((const void *)gMedapartNames[0][gGameWork.shownLegs * 4 + 3], gGameWork.textBuf, 15);
        render_text_sprites_08040DB8(gGameWork.textBuf, 0x48, 0x12, 17, 10, 13, 1, 2);
    } else {
        fill_text_blank(gGameWork.textBuf, 13);
        render_text_sprites_08040DB8(gGameWork.textBuf, 0x48, 0x12, 17, 10, 13, 1, 2);
    }
}

static void medabot_detail_draw_legs_skill_icon(void) {
    if (gGameWork.shownLegs < 120) {
        if (gGameWork.shownMedal < 30) {
            load_part_data(gGameWork.shownLegs, 3, &gGameWork.partAbility);
            memcpy_bytes_08041D04(gMedalRecords[gMedals[gGameWork.shownMedal].graphicId], gGameWork.medalGfxRecord, 16);
            if (gGameWork.partAbility == gGameWork.medalGfxRecord[1])
                draw_tile_block(2, 2, 16, 17, REG_BG1CNT, 0xD340 + gGameWork.medalGfxRecord[7] * 4);
            else
                draw_tile_block(2, 2, 16, 17, REG_BG1CNT, 0xD340);
        } else {
            vram_fill_tilemap_rect(2, 2, 16, 17, REG_BG1CNT, 0);
        }
    } else {
        vram_fill_tilemap_rect(2, 2, 16, 17, REG_BG1CNT, 0);
    }
}

// Icon left of detail row 0-4 (Medal, head, right arm, left arm, legs); medabot_detail_blink_row_icon
// alternates a = 0 / 1 on the selected row every 8 frames.
static void medabot_detail_draw_row_icon_0(u32 a) {
    if (a == 0)
        draw_tile_block(2, 2, 14, 9, REG_BG1CNT, 0xC370);
    else
        draw_tile_block(2, 2, 14, 9, REG_BG1CNT, 0xC384);
}

static void medabot_detail_draw_row_icon_1(u32 a) {
    if (a == 0)
        draw_tile_block(2, 2, 14, 11, REG_BG1CNT, 0xC374);
    else
        draw_tile_block(2, 2, 14, 11, REG_BG1CNT, 0xC388);
}

static void medabot_detail_draw_row_icon_2(u32 a) {
    if (a == 0)
        draw_tile_block(2, 2, 14, 13, REG_BG1CNT, 0xC378);
    else
        draw_tile_block(2, 2, 14, 13, REG_BG1CNT, 0xC388);
}

static void medabot_detail_draw_row_icon_3(u32 a) {
    if (a == 0)
        draw_tile_block(2, 2, 14, 15, REG_BG1CNT, 0xC37C);
    else
        draw_tile_block(2, 2, 14, 15, REG_BG1CNT, 0xC388);
}

static void medabot_detail_draw_row_icon_4(u32 a) {
    if (a == 0)
        draw_tile_block(2, 2, 14, 17, REG_BG1CNT, 0xC380);
    else
        draw_tile_block(2, 2, 14, 17, REG_BG1CNT, 0xC388);
}

// Legs type icon above the Medal row (part data byte 1 - 100, 0xFF = none).
static void medabot_detail_draw_legs_type_icon(void) {
    if (gGameWork.shownLegs < 120) {
        load_part_data(gGameWork.shownLegs, 3, &gGameWork.partAbility);
        draw_tilemap_with_offset(gGameWork.partSkill - 100, 20, 6, REG_BG1CNT, 0x8300);
    } else {
        draw_tilemap_with_offset(0xFF, 20, 6, REG_BG1CNT, 0x8300);
    }
}

static void medabot_detail_load_icon_gfx(void) {
    decompress_sprite_to_vram_08042D94(gGameWork.shownHead, gGameWork.shownRightArm, gGameWork.shownLeftArm,
                                       gGameWork.shownLegs, 0);
}

static void medabot_detail_place_icon(void) {
    setup_battle_sprite_group(gGameWork.shownHead, gGameWork.shownRightArm, gGameWork.shownLeftArm, gGameWork.shownLegs,
                              0, 6, 0xA8, 0x20, gGameWork.detailBot, 1, 5);
}

static void medabot_detail_place_row_arrows(void) {
    gSpriteEntries[1].flags = SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(2) | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[1].x = 0x6C;
    gSpriteEntries[1].y = gGameWork.detailRow * 16 + 0x50;
    gSpriteEntries[1].frame = 0x302;
    gSpriteEntries[1].palette = 14;
    gSpriteEntries[1].frame_table = 0;
    gSpriteEntries[1].order = 0x40;
    gSpriteEntries[2].flags = SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(2) | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[2].x = 0xE4;
    gSpriteEntries[2].y = gGameWork.detailRow * 16 + 0x50;
    gSpriteEntries[2].frame = 0x303;
    gSpriteEntries[2].palette = 14;
    gSpriteEntries[2].frame_table = 0;
    gSpriteEntries[2].order = 0x40;
}

static void medabot_detail_blink_row_arrows(void) {
    if (gFrameCounter & 8) {
        gSpriteEntries[1].flags &= (u16)~SPRITE_FLAG_VISIBLE;
        gSpriteEntries[2].flags &= (u16)~SPRITE_FLAG_VISIBLE;
    } else {
        gSpriteEntries[1].flags |= SPRITE_FLAG_VISIBLE;
        gSpriteEntries[2].flags |= SPRITE_FLAG_VISIBLE;
    }
}

static void medabot_detail_init_bot_sprite(void) {
    struct SpriteTree *obj = (struct SpriteTree *)0x02026000;
    u8 *b;
    u8 *c;
    u32 fill;

    mem_fill8((u8 *)obj, 0xD0, 0);
    b = (u8 *)0x020260D0;
    mem_fill8(b, 0x800, 0);
    c = (u8 *)0x020268D0;
    mem_fill8(c, 0x60, 0);
    gVBlankOamMode = 2;
    gSpriteWork = (struct SpriteWork *)0x02024000;
    fill = 0;
    CpuFastSet(&fill, (void *)0x02024000, 0x01000426);
    gMedabotSpriteSlots = (struct MedabotSpriteSlot *)c;
    init_sprite_tree(obj, (u8 *)gSpriteWork, (struct SpriteNodeDesc **)gMedabotSpriteNodeDescs,
                     (struct SpriteNodeOam *)b);
    obj->oams = (struct SpriteNodeOam *)b;
    if (gGameWork.detailBot)
        setup_medabot_part_sprites(gSpriteWork->oamBuf, obj, gGameWork.shownHead, gGameWork.shownRightArm,
                                   gGameWork.shownLeftArm, gGameWork.shownLegs, 0x28, 0x28, 0x1C2, 8, 1, 1);
    else
        setup_medabot_part_sprites(gSpriteWork->oamBuf, obj, gGameWork.shownHead, gGameWork.shownRightArm,
                                   gGameWork.shownLeftArm, gGameWork.shownLegs, 0x28, 0x28, 0x1C2, 8, 1, 0);
}

static void medabot_detail_redraw_bot_sprite(void) {
    struct SpriteTree *obj = (struct SpriteTree *)0x02026000;
    u32 fill;

    obj->oams = (struct SpriteNodeOam *)0x020260D0;
    if (gGameWork.detailBot)
        setup_medabot_part_sprites(gSpriteWork->oamBuf, obj, gGameWork.shownHead, gGameWork.shownRightArm,
                                   gGameWork.shownLeftArm, gGameWork.shownLegs, 0x28, 0x28, 0x1C2, 8, 1, 1);
    else
        setup_medabot_part_sprites(gSpriteWork->oamBuf, obj, gGameWork.shownHead, gGameWork.shownRightArm,
                                   gGameWork.shownLeftArm, gGameWork.shownLegs, 0x28, 0x28, 0x1C2, 8, 1, 0);
    fill = 0x200;
    CpuFastSet(&fill, gSpriteWork->oamBuf, 0x01000100);
    gSpriteWork->oamCount = 0;
    gSpriteWork->affineIdx = 0;
}

static void medabot_detail_draw_bot_sprite(void) {
    if (gGameWork.detailBot)
        setup_medabot_part_sprites(gSpriteWork->oamBuf, (struct SpriteTree *)0x02026000, gGameWork.shownHead,
                                   gGameWork.shownRightArm, gGameWork.shownLeftArm, gGameWork.shownLegs, 0x3C, 0x32,
                                   0x1C2, 8, 5, 1);
    else
        setup_medabot_part_sprites(gSpriteWork->oamBuf, (struct SpriteTree *)0x02026000, gGameWork.shownHead,
                                   gGameWork.shownRightArm, gGameWork.shownLeftArm, gGameWork.shownLegs, 0x3C, 0x32,
                                   0x1C2, 8, 5, 0);
}

static void medabot_detail_blink_row_icon(void) {
    if (gFrameCounter & 8) {
        switch (gGameWork.detailRow) {
        case 0:
            medabot_detail_draw_row_icon_0(0);
            break;
        case 1:
            medabot_detail_draw_row_icon_1(0);
            break;
        case 2:
            medabot_detail_draw_row_icon_2(0);
            break;
        case 3:
            medabot_detail_draw_row_icon_3(0);
            break;
        case 4:
            medabot_detail_draw_row_icon_4(0);
            break;
        }
    } else {
        switch (gGameWork.detailRow) {
        case 0:
            medabot_detail_draw_row_icon_0(1);
            break;
        case 1:
            medabot_detail_draw_row_icon_1(1);
            break;
        case 2:
            medabot_detail_draw_row_icon_2(1);
            break;
        case 3:
            medabot_detail_draw_row_icon_3(1);
            break;
        case 4:
            medabot_detail_draw_row_icon_4(1);
            break;
        }
    }
}

static u32 medabot_detail_row_cursor_input(void) {
    if (KEYS_LO(gRepeatKeys) & 0x40) {
        if (gGameWork.detailRow == 0)
            gGameWork.detailRow = 4;
        else
            gGameWork.detailRow--;
    }
    if (KEYS_LO(gRepeatKeys) & 0x80) {
        if (gGameWork.detailRow == 4)
            gGameWork.detailRow = 0;
        else
            gGameWork.detailRow++;
    }
    if (KEY_BITS(gRepeatKeys).up | KEY_BITS(gRepeatKeys).down) {
        play_sound_effect(2);
        medabot_detail_draw_row_icon_0(0);
        medabot_detail_draw_row_icon_1(0);
        medabot_detail_draw_row_icon_2(0);
        medabot_detail_draw_row_icon_3(0);
        medabot_detail_draw_row_icon_4(0);
        medabot_detail_place_row_arrows();
        return 1;
    } else
        return 0;
}

static u32 medabot_detail_cycle_medal_input(void) {
    u32 old;

    if (gGameWork.detailRow != 0)
        goto none;
    old = gGameWork.shownMedal;
    if (KEYS_LO(gRepeatKeys) & 0x20)
        gGameWork.shownMedal = find_next_free_medal(old, 1);
    if (KEYS_LO(gRepeatKeys) & 0x10)
        gGameWork.shownMedal = find_next_free_medal(gGameWork.shownMedal, 0);
    if (old == gGameWork.shownMedal) {
    none:
        return 0;
    }
    play_sound_effect(2);
    medabot_detail_draw_medal_nickname();
    medabot_detail_draw_medal_icon();
    medabot_detail_draw_medal_kind_name();
    medabot_detail_draw_medal_level();
    medabot_detail_draw_head_skill_icon();
    medabot_detail_draw_rarm_skill_icon();
    medabot_detail_draw_larm_skill_icon();
    medabot_detail_draw_legs_skill_icon();
    return 1;
}

static u32 medabot_detail_cycle_head_input(void) {
    u32 old;

    if (gGameWork.detailRow != 1)
        goto none;
    old = gGameWork.shownHead;
    if (KEYS_LO(gRepeatKeys) & 0x20)
        gGameWork.shownHead = find_next_available_medapart_slot(old, 0, 1, gTeamSlots[gGameWork.medabotsCursor].gender);
    if (KEYS_LO(gRepeatKeys) & 0x10)
        gGameWork.shownHead =
            find_next_available_medapart_slot(gGameWork.shownHead, 0, 0, gTeamSlots[gGameWork.medabotsCursor].gender);
    if (old == gGameWork.shownHead) {
    none:
        return 0;
    }
    play_sound_effect(2);
    medabot_detail_draw_head_name();
    medabot_detail_draw_head_skill_icon();
    medabot_detail_load_icon_gfx();
    medabot_detail_place_icon();
    medabot_detail_redraw_bot_sprite();
    return 1;
}

static u32 medabot_detail_cycle_rarm_input(void) {
    u32 old;

    if (gGameWork.detailRow != 2)
        goto none;
    old = gGameWork.shownRightArm;
    if (KEYS_LO(gRepeatKeys) & 0x20)
        gGameWork.shownRightArm =
            find_next_available_medapart_slot(old, 1, 1, gTeamSlots[gGameWork.medabotsCursor].gender);
    if (KEYS_LO(gRepeatKeys) & 0x10)
        gGameWork.shownRightArm = find_next_available_medapart_slot(gGameWork.shownRightArm, 1, 0,
                                                                    gTeamSlots[gGameWork.medabotsCursor].gender);
    if (old == gGameWork.shownRightArm) {
    none:
        return 0;
    }
    play_sound_effect(2);
    medabot_detail_draw_rarm_name();
    medabot_detail_draw_rarm_skill_icon();
    medabot_detail_load_icon_gfx();
    medabot_detail_place_icon();
    medabot_detail_redraw_bot_sprite();
    return 1;
}

static u32 medabot_detail_cycle_larm_input(void) {
    u32 old;

    if (gGameWork.detailRow != 3)
        goto none;
    old = gGameWork.shownLeftArm;
    if (KEYS_LO(gRepeatKeys) & 0x20)
        gGameWork.shownLeftArm =
            find_next_available_medapart_slot(old, 2, 1, gTeamSlots[gGameWork.medabotsCursor].gender);
    if (KEYS_LO(gRepeatKeys) & 0x10)
        gGameWork.shownLeftArm = find_next_available_medapart_slot(gGameWork.shownLeftArm, 2, 0,
                                                                   gTeamSlots[gGameWork.medabotsCursor].gender);
    if (old == gGameWork.shownLeftArm) {
    none:
        return 0;
    }
    play_sound_effect(2);
    medabot_detail_draw_larm_name();
    medabot_detail_draw_larm_skill_icon();
    medabot_detail_load_icon_gfx();
    medabot_detail_place_icon();
    medabot_detail_redraw_bot_sprite();
    return 1;
}

static u32 medabot_detail_cycle_legs_input(void) {
    u32 old;

    if (gGameWork.detailRow != 4)
        goto none;
    old = gGameWork.shownLegs;
    if (KEYS_LO(gRepeatKeys) & 0x20)
        gGameWork.shownLegs = find_next_available_medapart_slot(old, 3, 1, gTeamSlots[gGameWork.medabotsCursor].gender);
    if (KEYS_LO(gRepeatKeys) & 0x10)
        gGameWork.shownLegs =
            find_next_available_medapart_slot(gGameWork.shownLegs, 3, 0, gTeamSlots[gGameWork.medabotsCursor].gender);
    if (old == gGameWork.shownLegs) {
    none:
        return 0;
    }
    play_sound_effect(2);
    medabot_detail_draw_legs_name();
    medabot_detail_draw_legs_skill_icon();
    medabot_detail_draw_legs_type_icon();
    medabot_detail_load_icon_gfx();
    medabot_detail_place_icon();
    medabot_detail_redraw_bot_sprite();
    return 1;
}

static u32 medabot_detail_equip_full_set_input(void) {
    volatile u32 kind;
    volatile u32 part;

    if (KEYS_LO(gNewKeys) & 8) {
        play_sound_effect(4);
        kind = 0;
        if (gGameWork.detailRow)
            kind = gGameWork.detailRow - 1;
        switch (kind) {
        case 0:
            part = gGameWork.shownHead;
            break;
        case 1:
            part = gGameWork.shownRightArm;
            break;
        case 2:
            part = gGameWork.shownLeftArm;
            break;
        case 3:
            part = gGameWork.shownLegs;
            break;
        }
        if (medabot_detail_is_full_set())
            part = find_next_available_medapart_slot(part, kind, 0, gTeamSlots[gGameWork.medabotsCursor].gender);
        goto next;
    done:
        medabot_detail_draw_head_name();
        medabot_detail_draw_head_skill_icon();
        medabot_detail_draw_rarm_name();
        medabot_detail_draw_rarm_skill_icon();
        medabot_detail_draw_larm_name();
        medabot_detail_draw_larm_skill_icon();
        medabot_detail_draw_legs_name();
        medabot_detail_draw_legs_skill_icon();
        medabot_detail_draw_legs_type_icon();
        medabot_detail_load_icon_gfx();
        medabot_detail_place_icon();
        medabot_detail_redraw_bot_sprite();
        return 1;
    next:
        part = medabot_detail_prev_part_id(part);
        while (1) {
            gGameWork.shownHead =
                find_next_available_medapart_slot(part, 0, 0, gTeamSlots[gGameWork.medabotsCursor].gender);
            gGameWork.shownRightArm =
                find_next_available_medapart_slot(part, 1, 0, gTeamSlots[gGameWork.medabotsCursor].gender);
            gGameWork.shownLeftArm =
                find_next_available_medapart_slot(part, 2, 0, gTeamSlots[gGameWork.medabotsCursor].gender);
            gGameWork.shownLegs =
                find_next_available_medapart_slot(part, 3, 0, gTeamSlots[gGameWork.medabotsCursor].gender);
            if (medabot_detail_is_full_set())
                goto done;
            switch (kind) {
            case 0:
                part = gGameWork.shownHead;
                break;
            case 1:
                part = gGameWork.shownRightArm;
                break;
            case 2:
                part = gGameWork.shownLeftArm;
                break;
            case 3:
                part = gGameWork.shownLegs;
                break;
            }
            part = find_next_available_medapart_slot(part, kind, 0, gTeamSlots[gGameWork.medabotsCursor].gender);
            part = medabot_detail_prev_part_id(part);
        }
    }
    return 0;
}

static u32 medabot_detail_prev_part_id(volatile u32 part) {
    if (part == 0)
        part = gTeamSlots[gGameWork.medabotsCursor].gender + 120;
    else if (part > 119)
        part = 119;
    else
        part = part - 1;
    return part;
}

// unk53 set while validate_medapart_stats rejects the shown Medal + Medaparts: the Medabot sprite
// switches to palette 8 (and medabot_detail_animate_invalid_bot animates it); cleared and redrawn once valid again.
static void medabot_detail_update_invalid_bot(void) {
    u32 r;

    if (gGameWork.detailInvalid) {
        r = validate_medapart_stats(gGameWork.shownMedal, gGameWork.shownHead, gGameWork.shownRightArm,
                                    gGameWork.shownLeftArm, gGameWork.shownLegs);
        if (r == 0) {
            init_battle_medabot_sprites(gGameWork.shownHead, gGameWork.shownRightArm, gGameWork.shownLeftArm,
                                        gGameWork.shownLegs, r, 6, 0xA8, 0x20, gGameWork.detailBot, 1, 5);
            gGameWork.detailInvalid = r;
        }
    } else {
        if (validate_medapart_stats(gGameWork.shownMedal, gGameWork.shownHead, gGameWork.shownRightArm,
                                    gGameWork.shownLeftArm, gGameWork.shownLegs)) {
            battle_sprite_group_set_anim(6, 8);
            gGameWork.detailInvalid = 1;
        }
    }
}

static void medabot_detail_animate_invalid_bot(void) {
    if (gGameWork.detailInvalid)
        update_battle_sprite_orbiting_positions(6, 0, 0);
}

// A on the detail screen: 1 if the selected row holds a Medal / Medapart, 2 if it is empty.
// No A press falls off the end (no return value, r0 is left as is; the caller tests 1 / 2).
static u8 medabot_detail_check_row_select(void) {
    if (KEYS_LO(gNewKeys) & 1) {
        switch (gGameWork.detailRow) {
        case 0:
            if (gGameWork.shownMedal == 30)
                return 2;
            return 1;
        case 1:
            if (gGameWork.shownHead > 119)
                return 2;
            return 1;
        case 2:
            if (gGameWork.shownRightArm > 119)
                return 2;
            return 1;
        case 3:
            if (gGameWork.shownLeftArm > 119)
                return 2;
            return 1;
        case 4:
            if (gGameWork.shownLegs > 119)
                return 2;
            return 1;
        }
    }
}

static void assign_medal_to_team_slot(void) {
    u8 n = 0;

    if (gGameWork.shownMedal == 30) {
        gTeamSlots[gGameWork.medabotsCursor].state = 1;
        gTeamSlots[gGameWork.medabotsCursor].medal = 30;
    } else {
        gTeamSlots[gGameWork.medabotsCursor].state = 2;
        gTeamSlots[gGameWork.medabotsCursor].medal = gMedals[gGameWork.shownMedal].graphicId;
        gMedals[gGameWork.shownMedal].flags |= 0x40;
        n = 1;
    }
    gTeamSlots[gGameWork.medabotsCursor].head = gGameWork.shownHead;
    if (gGameWork.shownHead < 120) {
        modify_medapart_quantity(gGameWork.shownHead, 0, 1, 0, 1);
        n++;
    }
    gTeamSlots[gGameWork.medabotsCursor].rightArm = gGameWork.shownRightArm;
    if (gGameWork.shownRightArm < 120) {
        modify_medapart_quantity(gGameWork.shownRightArm, 1, 1, 0, 1);
        n++;
    }
    gTeamSlots[gGameWork.medabotsCursor].leftArm = gGameWork.shownLeftArm;
    if (gGameWork.shownLeftArm < 120) {
        modify_medapart_quantity(gGameWork.shownLeftArm, 2, 1, 0, 1);
        n++;
    }
    gTeamSlots[gGameWork.medabotsCursor].legs = gGameWork.shownLegs;
    if (gGameWork.shownLegs < 120) {
        modify_medapart_quantity(gGameWork.shownLegs, 3, 1, 0, 1);
        n++;
    }
    if (n == 5)
        gTeamSlots[gGameWork.medabotsCursor].state = 3;
}

void count_unequipped_medals(void) {
    u32 i;

    for (i = 0; i < 30; i++) {
        if (gMedals[i].flags & 0x80) {
            if (!(gMedals[i].flags & 0x40))
                gGameWork.freeMedalCount++;
        }
    }
}

static void team_select_draw_pick_markers(void) {
    u32 i;

    switch (gGameWork.medabotsMode) {
    case 1:
    case 2:
        for (i = 0; i < 3; i++) {
            if (gBattleWork.teamPicks[i]) {
                gSpriteEntries[i + 4].flags = SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_FLAG_PART_PALETTE;
                gSpriteEntries[i + 4].x = gMedabotsSlotPositions[(gBattleWork.teamPicks[i] & 0xF) * 2];
                gSpriteEntries[i + 4].y = gMedabotsSlotPositions[(gBattleWork.teamPicks[i] & 0xF) * 2 + 1];
                gSpriteEntries[i + 4].frame = i + 0x401;
                gSpriteEntries[i + 4].palette = 15;
                gSpriteEntries[i + 4].frame_table = 0;
                gSpriteEntries[i + 4].order = 0xC0;
            } else {
                disable_sprites(i + 4, 1);
            }
        }
        break;
    case 3:
        for (i = 0; i < 3; i++) {
            if (gBattleWork.teamPicks[i]) {
                gSpriteEntries[i + 4].flags = SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_FLAG_PART_PALETTE;
                gSpriteEntries[i + 4].x = gMedabotsSlotPositions[(gBattleWork.teamPicks[i] & 0xF) * 2];
                gSpriteEntries[i + 4].y = gMedabotsSlotPositions[(gBattleWork.teamPicks[i] & 0xF) * 2 + 1];
                gSpriteEntries[i + 4].frame = i + 0x404;
                gSpriteEntries[i + 4].palette = 15;
                gSpriteEntries[i + 4].frame_table = 0;
                gSpriteEntries[i + 4].order = 0xC0;
            } else {
                disable_sprites(i + 4, 1);
            }
        }
        break;
    }
}

static void medabots_screen_cancel_input(void) {
    s32 i;

    switch (gGameWork.medabotsMode) {
    case 1:
    case 2:
    case 3:
        for (i = 2; i >= 0; i--) {
            if (gBattleWork.teamPicks[i]) {
                gBattleWork.teamPicks[i] = 0;
                team_select_draw_pick_markers();
                play_sound_effect(5);
                return;
            }
        }
        break;
    default:
        if (gGameWork.reorderPick & 0x80) {
            play_sound_effect(2);
            gGameWork.reorderPick = 0;
            medabots_screen_update_reorder_icons();
        } else if (count_assembled_medabots()) {
            play_sound_effect(5);
            gGameSubState++;
        } else {
            play_sound_effect(6);
            gGameSubState = 11;
        }
        break;
    }
}

static void team_select_confirm_pick(void) {
    u32 i;

    switch (gGameWork.medabotsMode) {
    case 1:
    case 2:
    case 3:
        for (i = 0; i < 3; i++) {
            if (gBattleWork.teamPicks[i] == 0) {
                if (team_select_slot_not_picked(i) && gTeamSlots[gGameWork.medabotsCursor].state == 3) {
                    play_sound_effect(4);
                    gBattleWork.teamPicks[i] = gGameWork.medabotsCursor + 0x10;
                    team_select_draw_pick_markers();
                    if (i == 2) {
                        switch (gGameWork.medabotsMode) {
                        case 1:
                        case 2:
                            gGameSubState = 0x20;
                            break;
                        default:
                            gGameSubState = 0x28;
                            break;
                        }
                    } else if (count_assembled_medabots() == i + 1) {
                        gGameSubState = 0x20;
                    } else {
                        gGameWork.medabotsCursor = gTeamSelectNextSlot[gGameWork.medabotsCursor];
                        medabots_screen_orbit_cursor_icon(0);
                        medabots_screen_orbit_cursor_icon(1);
                        medabots_screen_orbit_cursor_icon(2);
                        medabots_screen_orbit_cursor_icon(3);
                        medabots_screen_draw_medal_nickname();
                        medabots_screen_draw_medal_kind_name();
                        medabots_screen_draw_medal_icon();
                        medabots_screen_redraw_bot_sprite();
                        medabots_screen_place_team_icons();
                        medabots_screen_flag_invalid_bot();
                    }
                } else {
                    play_sound_effect(6);
                }
                return;
            }
            play_sound_effect(6);
        }
        break;
    default:
        if (gTeamSlots[gGameWork.medabotsCursor].state) {
            play_sound_effect(4);
            gGameSubState = 8;
        } else {
            play_sound_effect(6);
        }
        break;
    }
}

static void team_select_finish_input(void) {
    switch (gGameWork.medabotsMode) {
    case 1:
    case 2:
        if (gBattleWork.teamPicks[0]) {
            play_sound_effect(4);
            gGameSubState = 0x20;
        }
        break;
    }
}

static u32 team_select_slot_not_picked(u32 n) {
    u32 i;

    if (n == 0)
        return 1;
    for (i = 0; i < n; i++) {
        if ((gBattleWork.teamPicks[i] & 0xF) == gGameWork.medabotsCursor)
            return 0;
    }
    return 1;
}

// Blinks the team select pick markers (sprites 4-6) every 4 frames.
static void team_select_blink_pick_markers(void) {
    u32 i;

    if (gGameWork.timer & 4) {
        for (i = 0; i <= 2; i++) {
            if (gBattleWork.teamPicks[i])
                gSpriteEntries[i + 4].flags &= (u16)~SPRITE_FLAG_VISIBLE;
        }
    } else {
        for (i = 0; i <= 2; i++) {
            if (gBattleWork.teamPicks[i])
                gSpriteEntries[i + 4].flags |= SPRITE_FLAG_VISIBLE;
        }
    }
    gGameWork.timer++;
}

// guess: the BG2 panel cleared in team select is the SELECT reorder hint (reorder is off there).
static void team_select_clear_hint_panel(void) {
    if (gGameWork.medabotsMode)
        vram_fill_tilemap_rect(16, 4, 13, 16, REG_BG2CNT, 0);
}

// guess: counts the partner's bots received over the link (gBattleBots[3-5]) and loads their parts
static void team_select_link_load_opponents(void) {
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gBattleBots[i + 3].teamState)
            gBattleWork.loadedOpponents++;
    }
    battle_bots_load_parts(3, gBattleWork.loadedOpponents);
}
