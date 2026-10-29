// Game state 5: the Medaparts screen (Medawatch > Medaparts): the part list by kind with counts and icons,
// a part's detail page (skill, ability, stats, compatible count), the START help pages, and the part sprite
// loaders. Entry point medaparts_screen_update; returns to the field menu. Uses the engine OAM/BG helpers
// and the text renderer.

#include "global.h"
#include "constants/sprites.h"

// gSpriteEntries work[] indices
#define MEDAPARTS_SPR_BLINK_TIMER 0x7 // trade choice cursor (sprite 4): blink frames, 0-30
#define MEDAPARTS_SPR_CLOSE_STEP 0x9  // trade choice cursor: gMedapartTradeChoiceCloseSteps index

static void medaparts_scroll_bg(void);
static void medaparts_list_set_cursor_from_part(void);
static void medaparts_list_draw_names(void);
static void medaparts_list_draw_counts(void);
static void medaparts_list_draw_equipped_counts(void);
static void medaparts_list_draw_part_icons(void);
static void medaparts_list_init_page_arrows(void);
static void medaparts_list_blink_page_arrows(void);
static void medaparts_list_init_cursor(void);
static u32 medaparts_list_row_input(void);
static u32 medaparts_list_page_input(void);
static u32 medaparts_list_kind_input(void);
static void medaparts_list_load_part_sprite(void);
static void medapart_draw_sprite(void);
static void load_medapart_sprite_by_slot(void);
static void medapart_detail_init_sprite(void);
static void medapart_detail_draw_ability(void);
static void medapart_detail_draw_skill_icon(void);
static void medapart_detail_draw_name(void);
static void medapart_detail_draw_gender_icon(void);
static void medapart_detail_draw_stat_labels(void);
static void medapart_detail_draw_stats(void);
static void medapart_detail_init_arrows(void);
static void medapart_detail_blink_arrows(void);
static u32 medapart_detail_cycle_part_input(void);
static void medaparts_help_init_cursor(void);
static void medaparts_help_move_cursor(void);
static void medapart_trade_init_choice_cursor(void);
static void medapart_trade_choice_cursor_input(void);

void medaparts_screen_update(void) {
    u32 fill;

    if (link_error_check() == 0) {
        if (gVBlankOamMode == 2) {
            fill = 0x200;
            CpuFastSet(&fill, gSpriteWork->oamBuf, 0x01000100);
        }
        gMedapartsScreenHandlers[gGameSubState]();
    }
}

void medaparts_list_load_gfx(void) {
    u32 zero;

    if (gGameWork.medalPage == 1)
        load_medapart_sprite_by_slot();
    else if (gGameWork.openedFrom == 4)
        play_song(7);
    REG_DISPCNT &= 0xF0FF;
    REG_BG0CNT = 0x500;
    REG_BG1CNT = 0x1801;
    REG_BG2CNT = 0x1902;
    REG_BG3CNT = 0x1A03;
    lz_decompress_dispatch(gMedapartsListBgTiles, (void *)0x06004000);
    lz_decompress_dispatch(gMedapartTypeLabelTiles, (void *)0x06006000);
    lz_decompress_dispatch(gPartGenderIconTiles, (void *)0x06006A00);
    lz_decompress_dispatch(gTallDigitTiles, (void *)0x06006C00);
    lz_decompress_dispatch(gCursorArrowTiles, (void *)0x06017E00);
    lz_decompress_dispatch(gTradeChoiceWindowTiles, (void *)0x06007000);
    lz_decompress_dispatch(gSpriteFontTiles, (void *)0x06017400);
    set_tilemap_and_decompress_bg(0, 0, gMedapartsListBg0Tilemap, REG_BG0CNT, 0x200);
    set_tilemap_and_decompress_bg(0, 0, gMedapartsListBg1Tilemap, REG_BG1CNT, 0x200);
    set_tilemap_and_decompress_bg(0, 0, gMedapartsListBg2Tilemap, REG_BG2CNT, 0x200);
    set_tilemap_and_decompress_bg(0, 0, gMedapartsListBg3Tilemap, REG_BG3CNT, 0x200);
    if (gGameWork.medalPage == 1) {
        CpuFastSet(gMedapartsListBgPalette, (void *)0x0202FA00, 0x70);
        CpuFastSet((void *)0x05000200, (void *)0x0202F800, 0x80);
        CpuFastSet(gGradientPaletteOlive + 0x10, (void *)0x0202F9A0, 8);
        CpuFastSet(gCursorArrowPalette, (void *)0x0202F9C0, 8);
        CpuFastSet(gTradeChoiceWindowPalette, (void *)0x0202FB60, 8);
        gGameWork.stepCounter = 0;
    } else {
        CpuFastSet(gMedapartsListBgPalette, (void *)0x05000000, 0x70);
        CpuFastSet(gGradientPaletteOlive + 0x10, (void *)0x050003A0, 8);
        CpuFastSet(gCursorArrowPalette, (void *)0x050003C0, 8);
        CpuFastSet(gTradeChoiceWindowPalette, (void *)0x05000160, 8);
        set_blend_effect_mode(5, 0x3F, 0x20);
    }
    zero = 0;
    CpuFastSet(&zero, gSpriteEntries, 0x01000800);
    REG_DISPCNT |= 0x1F60;
    write_tilemap_rect(10, 2, 0x10, 0, gUiTilemaps[gGameWork.partSlot + 0x59], REG_BG0CNT, 0x200);
    medaparts_list_set_cursor_from_part();
    draw_number_tall_bgcnt(gGameWork.listTab + 1, 0xB, 2, 2, REG_BG1CNT, 0x7360);
    medaparts_list_draw_names();
    medaparts_list_draw_counts();
    medaparts_list_draw_equipped_counts();
    medaparts_list_draw_part_icons();
    medaparts_list_init_page_arrows();
    medaparts_list_init_cursor();
    gGameWork.helpPage = 0;
    if (gGameWork.medalPage != 1)
        medaparts_list_load_part_sprite();
    gGameSubState++;
}

void medaparts_list_fade_in(void) {
    medaparts_scroll_bg();
    medaparts_list_blink_page_arrows();
    sprite_bob_x(3, gFrameCounter, 0x50);
    load_medapart_sprite_by_slot();
    if (gGameWork.medalPage == 1) {
        if (gGameWork.stepCounter <= 8) {
            bg_palettes_blend_masked_now(0, 32 - gGameWork.stepCounter * 4, 0xFFFF);
            obj_palettes_blend_masked_now(0, 32 - gGameWork.stepCounter * 4, 0xF0FF);
            gGameWork.stepCounter++;
        } else {
            gGameWork.medalPage = 0;
            gGameSubState++;
        }
    } else if (update_blend_effect()) {
        gGameWork.medalPage = 0;
        gGameSubState++;
    }
}

void medaparts_list_open_text_window(void) {
    medaparts_scroll_bg();
    medaparts_list_blink_page_arrows();
    sprite_bob_x(3, gFrameCounter, 0x50);
    load_medapart_sprite_by_slot();
    text_window_init(1, 2, 0);
    gGameSubState++;
}

void medaparts_list_show_hint(void) {
    medaparts_scroll_bg();
    medaparts_list_blink_page_arrows();
    sprite_bob_x(3, gFrameCounter, 0x50);
    load_medapart_sprite_by_slot();
    if (run_message(gMenuMessages[16]))
        gGameSubState++;
}

void medaparts_list_handle_input(void) {
    medaparts_scroll_bg();
    medaparts_list_blink_page_arrows();
    sprite_bob_x(3, gFrameCounter, 0x50);
    load_medapart_sprite_by_slot();
    if (medaparts_list_row_input())
        return;
    if (medaparts_list_page_input())
        return;
    if (medaparts_list_kind_input())
        return;
    if (KEYS_LO(gNewKeys) & B_BUTTON) {
        if (gGameWork.openedFrom == 4) {
            play_sound_effect(6);
        } else {
            play_sound_effect(5);
            gGameSubState++;
        }
    } else if (KEYS_LO(gNewKeys) & A_BUTTON) {
        if ((u16)medapart_get_counts(gGameWork.shownId, gGameWork.partSlot)) {
            play_sound_effect(4);
            if (gGameWork.openedFrom == 4)
                gGameSubState = 0x40;
            else
                gGameSubState = 10;
        } else {
            play_sound_effect(6);
        }
    }
}

void medaparts_list_start_fade_out(void) {
    set_blend_effect_mode(6, 0x3F, 0x20);
    CpuFastSet(gSpriteFontPalette, (void *)0x050003E0, 8);
    medaparts_scroll_bg();
    medaparts_list_blink_page_arrows();
    sprite_bob_x(3, gFrameCounter, 0x50);
    load_medapart_sprite_by_slot();
    gGameSubState++;
}

void medaparts_list_wait_fade(void) {
    medaparts_scroll_bg();
    medaparts_list_blink_page_arrows();
    sprite_bob_x(3, gFrameCounter, 0x50);
    load_medapart_sprite_by_slot();
    if (update_blend_effect())
        gGameSubState++;
}

void medaparts_list_exit(void) {
    clear_battle_sprite_slot(0, 0x80);
    gVBlankOamMode = 0;
    gGameState = 2;
    gGameSubState = 0x10;
}

void medaparts_list_open_detail(void) {
    medaparts_scroll_bg();
    medaparts_list_blink_page_arrows();
    sprite_bob_x(3, gFrameCounter, 0x50);
    load_medapart_sprite_by_slot();
    palette_backup_from_hardware();
    gGameWork.stepCounter = 0;
    gGameSubState++;
}

void medaparts_list_detail_fade_out(void) {
    medaparts_scroll_bg();
    medaparts_list_blink_page_arrows();
    sprite_bob_x(3, gFrameCounter, 0x50);
    load_medapart_sprite_by_slot();
    if (gGameWork.stepCounter <= 8) {
        bg_palettes_blend_masked_now(0, gGameWork.stepCounter * 4, 0xFFFF);
        obj_palettes_blend_masked_now(0, gGameWork.stepCounter * 4, 0xF0FF);
        gGameWork.stepCounter++;
    } else {
        gGameSubState = 0x10;
    }
}

void medapart_detail_load_gfx(void) {
    u32 zero;

    clear_bg_scroll();
    if (gGameWork.openedFrom == 0 || gGameWork.openedFrom == 4)
        load_medapart_sprite_by_slot();
    REG_DISPCNT &= 0xF0FF;
    REG_BG0CNT = 0x500;
    REG_BG1CNT = 0x1801;
    REG_BG2CNT = 0x1902;
    REG_BG3CNT = 0x1A03;
    lz_decompress_dispatch(gMedapartDetailBgTiles, (void *)0x06004000);
    lz_decompress_dispatch(gMedapartStatLabelTiles, (void *)0x06006000);
    lz_decompress_dispatch(gPartPowerMarkTiles, (void *)0x06007080);
    lz_decompress_dispatch(gPartGenderIconTiles, (void *)0x06007100);
    lz_decompress_dispatch(gSkillRangeIconTiles, (void *)0x06007200);
    lz_decompress_dispatch(gBotActionIconTiles, (void *)0x06007300);
    lz_decompress_dispatch(gMedaforceGaugeTiles, (void *)0x06007880);
    lz_decompress_dispatch(gCursorArrowTiles, (void *)0x06017E00);
    set_tilemap_and_decompress_bg(0, 0, gMedapartDetailBg0Tilemap, REG_BG0CNT, 0x200);
    set_tilemap_and_decompress_bg(0, 0, gMedapartDetailBg1Tilemap, REG_BG1CNT, 0x200);
    set_tilemap_and_decompress_bg(0, 0, gMedapartDetailBg2Tilemap, REG_BG2CNT, 0x200);
    set_tilemap_and_decompress_bg(0, 0, gMedapartDetailBg3Tilemap, REG_BG3CNT, 0x200);
    if (gGameWork.openedFrom == 0 || gGameWork.openedFrom == 4) {
        CpuFastSet(gMedapartDetailBgPalette, (void *)0x0202FA00, 0x70);
        CpuFastSet((void *)0x05000200, (void *)0x0202F800, 0x80);
        CpuFastSet(gGradientPaletteOlive + 0x40, (void *)0x0202F980, 8);
        CpuFastSet(gGradientPaletteOlive + 0x10, (void *)0x0202F9A0, 8);
        CpuFastSet(gCursorArrowPalette, (void *)0x0202F9C0, 8);
        gGameWork.stepCounter = 0;
    } else {
        CpuFastSet(gMedapartDetailBgPalette, (void *)0x05000000, 0x70);
        CpuFastSet(gGradientPaletteOlive + 0x40, (void *)0x05000380, 8);
        CpuFastSet(gGradientPaletteOlive + 0x10, (void *)0x050003A0, 8);
        CpuFastSet(gCursorArrowPalette, (void *)0x050003C0, 8);
        medapart_detail_init_sprite();
        medapart_draw_sprite();
        set_blend_effect_mode(5, 0x3F, 0x20);
    }
    zero = 0;
    CpuFastSet(&zero, gSpriteEntries, 0x01000800);
    REG_DISPCNT |= 0x1F60;
    load_part_data(gGameWork.shownId, gGameWork.partSlot, &gGameWork.partAbility);
    medapart_detail_draw_skill();
    medapart_detail_draw_ability();
    medapart_detail_draw_skill_icon();
    medapart_detail_draw_name();
    medapart_detail_draw_gender_icon();
    medapart_detail_draw_stat_labels();
    medapart_detail_draw_stats();
    count_compatible_medaparts();
    medapart_detail_init_arrows();
    gGameWork.medalPage = 1;
    gGameSubState++;
}

void medapart_detail_fade_in(void) {
    medaparts_scroll_bg();
    load_medapart_sprite_by_slot();
    medapart_detail_blink_arrows();
    if (gGameWork.openedFrom == 0 || gGameWork.openedFrom == 4) {
        if (gGameWork.stepCounter <= 8) {
            bg_palettes_blend_masked_now(0, 32 - gGameWork.stepCounter * 4, 0xFFFF);
            obj_palettes_blend_masked_now(0, 32 - gGameWork.stepCounter * 4, 0xF0FF);
            gGameWork.stepCounter++;
        } else {
            gGameSubState++;
        }
    } else if (update_blend_effect()) {
        gGameSubState++;
    }
}

void medapart_detail_open_text_window(void) {
    medaparts_scroll_bg();
    load_medapart_sprite_by_slot();
    medapart_detail_blink_arrows();
    text_window_init(1, 2, 0);
    gGameSubState++;
}

void medapart_detail_show_hint(void) {
    medaparts_scroll_bg();
    load_medapart_sprite_by_slot();
    medapart_detail_blink_arrows();
    if (gGameWork.partSlot <= 2) {
        if (run_message(gMedapartDetailHelpMessages[medapart_detail_skill_help_index()]))
            gGameSubState++;
    } else {
        if (run_message(gMedapartLegDetailHelpMessages[medapart_detail_skill_help_index()]))
            gGameSubState++;
    }
}

void medapart_detail_handle_input(void) {
    medaparts_scroll_bg();
    load_medapart_sprite_by_slot();
    medapart_detail_blink_arrows();
    if (medapart_detail_cycle_part_input()) {
        message_next();
        gGameSubState--;
    } else if (KEYS_LO(gNewKeys) & B_BUTTON) {
        play_sound_effect(5);
        gGameSubState++;
    } else if (KEYS_LO(gNewKeys) & START_BUTTON) {
        play_sound_effect(4);
        switch (gGameWork.partSlot) {
        case 0:
            gGameWork.helpFromPage = 3;
            break;
        case 1:
        case 2:
            gGameWork.helpFromPage = 4;
            break;
        case 3:
            gGameWork.helpFromPage = 5;
            break;
        }
        gGameSubState = 0x20;
    }
}

void medapart_detail_start_fade_out(void) {
    medaparts_scroll_bg();
    load_medapart_sprite_by_slot();
    medapart_detail_blink_arrows();
    if (gGameWork.openedFrom == 0 || gGameWork.openedFrom == 4) {
        palette_backup_from_hardware();
        gGameWork.stepCounter = 0;
    } else {
        set_blend_effect_mode(6, 0x3F, 0x20);
    }
    gGameSubState++;
}

void medapart_detail_wait_fade(void) {
    medaparts_scroll_bg();
    load_medapart_sprite_by_slot();
    medapart_detail_blink_arrows();
    if (gGameWork.openedFrom == 0 || gGameWork.openedFrom == 4) {
        if (gGameWork.stepCounter <= 8) {
            bg_palettes_blend_masked_now(0, gGameWork.stepCounter * 4, 0xFFFF);
            obj_palettes_blend_masked_now(0, gGameWork.stepCounter * 4, 0xF0FF);
            gGameWork.stepCounter++;
        } else {
            gGameSubState++;
        }
    } else if (update_blend_effect()) {
        gGameSubState++;
    }
}

void medapart_detail_exit(void) {
    u32 zero1, zero2, zero3, zero4;

    load_medapart_sprite_by_slot();
    clear_battle_sprite_slot(0, 0x80);
    switch (gGameWork.openedFrom) {
    case 0:
    case 4:
        gGameSubState = 0;
        break;
    case 1:
        gVBlankOamMode = 0;
        gGameState = 3;
        gGameSubState = 0x10;
        switch (gGameWork.partSlot) {
        case 0:
            gGameWork.shownHead = gGameWork.shownId;
            break;
        case 1:
            gGameWork.shownRightArm = gGameWork.shownId;
            break;
        case 2:
            gGameWork.shownLeftArm = gGameWork.shownId;
            break;
        case 3:
            gGameWork.shownLegs = gGameWork.shownId;
            break;
        }
        break;
    case 2:
        zero1 = 0;
        CpuFastSet(&zero1, (void *)0x05000200, 0x01000080);
        zero2 = 0;
        CpuFastSet(&zero2, (void *)0x05000000, 0x01000080);
        gVBlankOamMode = 0;
        gGameState = 6;
        gGameSubState = 0x65;
        break;
    case 3:
        zero3 = 0;
        CpuFastSet(&zero3, (void *)0x05000200, 0x01000080);
        zero4 = 0;
        CpuFastSet(&zero4, (void *)0x05000000, 0x01000080);
        gVBlankOamMode = 0;
        gGameMode = 2;
        gGameState = 0x19;
        gGameSubState = 0;
        break;
    }
}

void medaparts_help_load(void) {
    medaparts_scroll_bg();
    load_medapart_sprite_by_slot();
    disable_sprites(1, 5);
    CpuFastSet(gHelpCursorPalette, (void *)0x050003C0, 8);
    medaparts_help_init_cursor();
    message_next();
    gGameSubState++;
}

void medaparts_help_show_intro(void) {
    medaparts_scroll_bg();
    load_medapart_sprite_by_slot();
    process_sprite_anim_commands(gBattleSpriteAnimScripts[3], 6);
    if (run_message(gMenuMessages[5]))
        gGameSubState++;
}

void medaparts_help_cursor_input(void) {
    u8 up;

    medaparts_scroll_bg();
    load_medapart_sprite_by_slot();
    process_sprite_anim_commands(gBattleSpriteAnimScripts[3], 6);
    if ((up = KEYS_LO(gRepeatKeys) & DPAD_UP)) {
        if (gGameWork.helpPage == 0)
            gGameWork.helpPage = gGameWork.helpPageCount - 1;
        else
            gGameWork.helpPage--;
        play_sound_effect(2);
        medaparts_help_move_cursor();
    } else if (KEYS_LO(gRepeatKeys) & DPAD_DOWN) {
        if (gGameWork.helpPage == gGameWork.helpPageCount - 1)
            gGameWork.helpPage = up;
        else
            gGameWork.helpPage++;
        play_sound_effect(2);
        medaparts_help_move_cursor();
    } else if (KEYS_LO(gNewKeys) & A_BUTTON) {
        play_sound_effect(4);
        medaparts_help_init_cursor();
        message_next();
        gGameSubState++;
    } else if (KEYS_LO(gNewKeys) & (B_BUTTON | START_BUTTON)) {
        play_sound_effect(5);
        gGameSubState = 0x24;
    }
}

void medaparts_help_show_text(void) {
    u8 done;

    medaparts_scroll_bg();
    load_medapart_sprite_by_slot();
    switch (gGameWork.partSlot) {
    case 0:
        switch (gGameWork.helpPage) {
        case 0:
            done = run_message(gMedaforceSkillHelpMessages[gGameWork.partSkillType]);
            break;
        case 1:
            done = run_message(gAbilityHelpMessages[gGameWork.partAbility]);
            break;
        case 2:
            done = run_message(gMenuMessages[skill_type_is_remote(gGameWork.partSkillType) + 17]);
            break;
        case 3:
            done = run_message(gMedapartsHelpMessages[0]);
            break;
        case 4:
            done = run_message(gMedapartsHelpMessages[1]);
            break;
        case 5:
            done = run_message(gMedapartsHelpMessages[2]);
            break;
        case 6:
            done = run_message(gMedapartsHelpMessages[3]);
            break;
        }
        break;
    case 1:
    case 2:
        switch (gGameWork.helpPage) {
        case 0:
            done = run_message(gMedaforceSkillHelpMessages[gGameWork.partSkillType]);
            break;
        case 1:
            done = run_message(gAbilityHelpMessages[gGameWork.partAbility]);
            break;
        case 2:
            done = run_message(gMenuMessages[skill_type_is_remote(gGameWork.partSkillType) + 17]);
            break;
        case 3:
            done = run_message(gMedapartsHelpMessages[0]);
            break;
        case 4:
            done = run_message(gMedapartsHelpMessages[1]);
            break;
        case 5:
            done = run_message(gMedapartsHelpMessages[2]);
            break;
        case 6:
            done = run_message(gMedapartsHelpMessages[4]);
            break;
        case 7:
            done = run_message(gMedapartsHelpMessages[5]);
            break;
        }
        break;
    case 3:
        switch (gGameWork.helpPage) {
        case 0:
            done = run_message(gAbilityHelpMessages[gGameWork.partAbility]);
            break;
        case 1:
            done = run_message(gMenuMessages[19]);
            break;
        case 2:
            done = run_message(gMedapartsHelpMessages[0]);
            break;
        case 3:
            done = run_message(gMedapartsHelpMessages[6]);
            break;
        case 4:
            done = run_message(gMedapartsHelpMessages[7]);
            break;
        case 5:
            done = run_message(gMedapartsHelpMessages[8]);
            break;
        case 6:
            done = run_message(gMedapartsHelpMessages[9]);
            break;
        case 7:
            done = run_message(gMedapartsHelpMessages[10]);
            break;
        }
        break;
    }
    if (done) {
        message_next();
        gGameSubState = 0x21;
    }
}

void medaparts_help_exit(void) {
    medaparts_scroll_bg();
    load_medapart_sprite_by_slot();
    disable_sprites(6, 1);
    CpuFastSet(gCursorArrowPalette, (void *)0x050003C0, 8);
    message_next();
    medapart_detail_init_arrows();
    gGameSubState = 0x13;
}

// Medaparts screen sub-states 64-71: A on a part in link trade mode (openedFrom == 4) opens a 3-entry choice (cursor
// sprite 4, choice in gGameWork.tradeChoice): 0 opens the part's detail page, 1 offers it for trade (refused with
// sound 6 when every owned copy is equipped), 2 goes back to the list. Twin of the Medals screen's medal_trade_*.
// Code-read only (needs a link partner).
void medapart_trade_choice_open(void) {
    medaparts_scroll_bg();
    load_medapart_sprite_by_slot();
    gSpriteEntries[1].flags &= (u16)~SPRITE_FLAG_VISIBLE;
    gSpriteEntries[2].flags &= (u16)~SPRITE_FLAG_VISIBLE;
    set_tilemap_and_decompress_bg(18, 5, gTradeChoiceWindowTilemap, REG_BG0CNT, 0x380);
    gGameWork.tradeChoice = 0;
    medapart_trade_init_choice_cursor();
    gGameSubState++;
}

void medapart_trade_choice_input(void) {
    s32 counts;

    medaparts_scroll_bg();
    load_medapart_sprite_by_slot();
    sprite_bob_x(4, gFrameCounter, 0xA8);
    medapart_trade_choice_cursor_input();
    if (KEYS_LO(gNewKeys) & A_BUTTON) {
        if (gGameWork.tradeChoice == 1) {
            counts = (u16)medapart_get_counts(gGameWork.shownId, gGameWork.partSlot);
            if ((counts >> 8 & 0xFF) != (counts & 0xFF))
                goto ok;
            play_sound_effect(6);
            return;
        }
    ok:
        play_sound_effect(4);
    } else if (KEYS_LO(gNewKeys) & B_BUTTON) {
        play_sound_effect(5);
        gGameWork.tradeChoice = 2;
    } else
        return;
    medapart_trade_init_choice_cursor();
    gGameSubState++;
}

void medapart_trade_choice_close(void) {
    medaparts_scroll_bg();
    load_medapart_sprite_by_slot();
    if (medapart_trade_choice_close_step()) {
        disable_sprites(4, 1);
        gGameSubState++;
    }
}

void medapart_trade_choice_dispatch(void) {
    medaparts_scroll_bg();
    load_medapart_sprite_by_slot();
    switch (gGameWork.tradeChoice) {
    case 0:
        gGameSubState = 10;
        break;
    case 1:
        fade_out_music(8);
        gGameSubState++;
        break;
    case 2:
        gGameSubState = 4;
        break;
    }
}

void medapart_trade_store_part(void) {
    gLinkTradeData = (gGameWork.partSlot << 16) + gGameWork.shownId;
    gGameSubState++;
}

void medapart_trade_enter_link(void) {
    clear_battle_sprite_slot(0, 0x80);
    clear_bg_scroll();
    goto_link_scene(2);
}

static void medaparts_scroll_bg(void) {
    if (gFrameCounter & 1) {
        gBg3Scroll.x++;
        gBg3Scroll.y++;
    }
}

static void medaparts_list_set_cursor_from_part(void) {
    gGameWork.listTab = gGameWork.shownId / 4;
    gGameWork.medalRow = gGameWork.shownId % 4;
}

static void medaparts_list_draw_names(void) {
    u32 i;
    u32 page;

    disable_sprites(10, 60);
    for (i = 0; i < 4; i++) {
        if (gMedapartInventory[gGameWork.partSlot * 240 + (page = gGameWork.listTab * 4) * 2 + i * 2]) {
            memcpy_bytes_08041D04((void *)gMedapartNames[0][(page + i) * 4 + gGameWork.partSlot], gGameWork.textBuf,
                                  15);
            render_text_sprites_08040DB8(gGameWork.textBuf, i * 15 + 10, 11, i * 2 + 5, 10, 13, 1, 1);
        } else {
            fill_text_blank(gGameWork.textBuf, 13);
            render_text_sprites_08040DB8(gGameWork.textBuf, i * 15 + 10, 11, i * 2 + 5, 10, 13, 1, 1);
        }
    }
}

static void medaparts_list_draw_counts(void) {
    u32 i;

    for (i = 0; i < 4; i++) {
        if (MEDAPART_INV(gGameWork.partSlot, gGameWork.listTab, i, 0))
            draw_number_tall_bgcnt(MEDAPART_INV(gGameWork.partSlot, gGameWork.listTab, i, 0), 0x16, i * 2 + 5, 2,
                                   REG_BG1CNT, 0x7360);
        else
            draw_number_tall_bgcnt(0, 0x16, i * 2 + 5, 2, REG_BG1CNT, 0x7360);
    }
}

// The second count column: how many of each part are equipped (inventory byte 1, which
// team_lose_equipped_part decrements together with the owned count).
static void medaparts_list_draw_equipped_counts(void) {
    u32 i;

    for (i = 0; i < 4; i++) {
        if (MEDAPART_INV(gGameWork.partSlot, gGameWork.listTab, i, 1))
            draw_number_tall_bgcnt(MEDAPART_INV(gGameWork.partSlot, gGameWork.listTab, i, 1), 0x19, i * 2 + 5, 1,
                                   REG_BG1CNT, 0x6360);
        else
            draw_number_tall_bgcnt(0, 0x19, i * 2 + 5, 1, REG_BG1CNT, 0x6360);
    }
}

static void medaparts_list_draw_part_icons(void) {
    u32 i;
    u32 page;

    for (i = 0; i < 4; i++) {
        if (gMedapartInventory[gGameWork.partSlot * 240 + (page = gGameWork.listTab * 4) * 2 + i * 2]) {
            load_part_data(page + i, gGameWork.partSlot, &gGameWork.partAbility);
            if (gGameWork.partGender)
                draw_tile_block(2, 2, 0x1B, i * 2 + 5, REG_BG1CNT, 0xA354);
            else
                draw_tile_block(2, 2, 0x1B, i * 2 + 5, REG_BG1CNT, 0xA350);
        } else {
            vram_fill_tilemap_rect(2, 2, 0x1B, i * 2 + 5, REG_BG1CNT, 0);
        }
    }
}

static void medaparts_list_init_page_arrows(void) {
    gSpriteEntries[1].flags = SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(2) | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[1].x = 0x4C;
    gSpriteEntries[1].y = 0x18;
    gSpriteEntries[1].frame = 0x302;
    gSpriteEntries[1].palette = 14;
    gSpriteEntries[1].frame_table = 0;
    gSpriteEntries[1].order = 0x80;
    gSpriteEntries[2].flags = SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(2) | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[2].x = 0x8C;
    gSpriteEntries[2].y = 0x18;
    gSpriteEntries[2].frame = 0x303;
    gSpriteEntries[2].palette = 14;
    gSpriteEntries[2].frame_table = 0;
    gSpriteEntries[2].order = 0x80;
}

static void medaparts_list_blink_page_arrows(void) {
    if (gFrameCounter & 8) {
        gSpriteEntries[1].flags &= (u16)~SPRITE_FLAG_VISIBLE;
        gSpriteEntries[2].flags &= (u16)~SPRITE_FLAG_VISIBLE;
    } else {
        gSpriteEntries[1].flags |= SPRITE_FLAG_VISIBLE;
        gSpriteEntries[2].flags |= SPRITE_FLAG_VISIBLE;
    }
}

static void medaparts_list_init_cursor(void) {
    gSpriteEntries[3].flags = SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(2) | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[3].x = 0x50;
    gSpriteEntries[3].y = gGameWork.medalRow * 16 + 0x30;
    gSpriteEntries[3].frame = 0x307;
    gSpriteEntries[3].palette = 14;
    gSpriteEntries[3].frame_table = 0;
    gSpriteEntries[3].order = 0x81;
}

static u32 medaparts_list_row_input(void) {
    u32 ret;

    if (KEYS_LO(gRepeatKeys) & DPAD_UP) {
        if (gGameWork.medalRow == 0)
            gGameWork.medalRow = 3;
        else
            gGameWork.medalRow--;
    }
    if (KEYS_LO(gRepeatKeys) & DPAD_DOWN) {
        if (gGameWork.medalRow == 3)
            gGameWork.medalRow = 0;
        else
            gGameWork.medalRow++;
    }
    if (!(KEYS_LO(gRepeatKeys) & (DPAD_UP | DPAD_DOWN))) {
        ret = 0;
    } else {
        play_sound_effect(2);
        gGameWork.shownId = gGameWork.listTab * 4 + gGameWork.medalRow;
        medaparts_list_init_cursor();
        medapart_draw_sprite();
        ret = 1;
    }
    return ret;
}

static u32 medaparts_list_page_input(void) {
    u32 ret;

    if (KEYS_LO(gRepeatKeys) & DPAD_LEFT) {
        if (gGameWork.listTab == 0)
            gGameWork.listTab = 29;
        else
            gGameWork.listTab--;
    }
    if (KEYS_LO(gRepeatKeys) & DPAD_RIGHT) {
        if (gGameWork.listTab == 29)
            gGameWork.listTab = 0;
        else
            gGameWork.listTab++;
    }
    if (!(KEYS_LO(gRepeatKeys) & (DPAD_RIGHT | DPAD_LEFT))) {
        ret = 0;
    } else {
        play_sound_effect(2);
        gGameWork.shownId = gGameWork.listTab * 4 + gGameWork.medalRow;
        draw_number_tall_bgcnt(gGameWork.listTab + 1, 0xB, 2, 2, REG_BG1CNT, 0x7360);
        medaparts_list_draw_names();
        medaparts_list_draw_counts();
        medaparts_list_draw_equipped_counts();
        medaparts_list_draw_part_icons();
        medapart_draw_sprite();
        ret = 1;
    }
    return ret;
}

static u32 medaparts_list_kind_input(void) {
    u32 ret;

    if (KEYS_HI(gNewKeys) & L_BUTTON_HI) {
        if (gGameWork.partSlot == 0)
            gGameWork.partSlot = 3;
        else
            gGameWork.partSlot--;
    }
    if (KEYS_HI(gNewKeys) & R_BUTTON_HI) {
        if (gGameWork.partSlot == 3)
            gGameWork.partSlot = 0;
        else
            gGameWork.partSlot++;
    }
    if (!(KEYS_HI(gNewKeys) & (R_BUTTON_HI | L_BUTTON_HI))) {
        ret = 0;
    } else {
        play_sound_effect(2);
        gGameWork.shownId = gGameWork.listTab * 4 + gGameWork.medalRow;
        write_tilemap_rect(10, 2, 0x10, 0, gUiTilemaps[gGameWork.partSlot + 0x59], REG_BG0CNT, 0x200);
        medaparts_list_draw_names();
        medaparts_list_draw_counts();
        medaparts_list_draw_equipped_counts();
        medaparts_list_draw_part_icons();
        medapart_draw_sprite();
        ret = 1;
    }
    return ret;
}

static void medaparts_list_load_part_sprite(void) {
    struct SpriteTree *obj;
    u8 *oam_buf;
    u8 *slot_buf;
    u32 fill;

    gGameWork.shownId = gGameWork.listTab * 4 + gGameWork.medalRow;
    obj = (struct SpriteTree *)0x02026000;
    mem_fill8((u8 *)obj, 0xD0, 0);
    oam_buf = (u8 *)0x020260D0;
    mem_fill8(oam_buf, 0x800, 0);
    slot_buf = (u8 *)0x020268D0;
    mem_fill8(slot_buf, 0x60, 0);
    gVBlankOamMode = 2;
    gSpriteWork = (struct SpriteWork *)0x02024000;
    fill = 0;
    CpuFastSet(&fill, (void *)0x02024000, 0x01000426);
    gMedabotSpriteSlots = (struct MedabotSpriteSlot *)slot_buf;
    init_sprite_tree(obj, (u8 *)gSpriteWork, (struct SpriteNodeDesc **)gMedabotSpriteNodeDescs,
                     (struct SpriteNodeOam *)oam_buf);
    obj->oams = (struct SpriteNodeOam *)oam_buf;
    draw_medapart_sprite(gSpriteWork->oamBuf, obj, gGameWork.shownId, gGameWork.partSlot, 0x3C, 0x28, 0x1C2, 8, 1);
}

static void medapart_draw_sprite(void) {
    struct SpriteTree *obj = (struct SpriteTree *)0x02026000;
    u32 fill;

    obj->oams = (struct SpriteNodeOam *)0x020260D0;
    switch (gGameWork.partSlot) {
    case 0:
        draw_medapart_sprite(gSpriteWork->oamBuf, obj, gGameWork.shownId, 0, 0x3C, 0x32, 0x1C2, 8, 1);
        break;
    case 1:
        draw_medapart_sprite(gSpriteWork->oamBuf, obj, gGameWork.shownId, 1, 0x28, 0x3C, 0x1C2, 8, 1);
        break;
    case 2:
        draw_medapart_sprite(gSpriteWork->oamBuf, obj, gGameWork.shownId, 2, 0x28, 0x28, 0x1C2, 8, 2);
        break;
    case 3:
        draw_medapart_sprite(gSpriteWork->oamBuf, obj, gGameWork.shownId, 3, 0x1E, 0x32, 0x1C2, 8, 1);
        break;
    }
    fill = 0x200;
    CpuFastSet(&fill, gSpriteWork->oamBuf, 0x01000100);
    gSpriteWork->oamCount = 0;
    gSpriteWork->affineIdx = 0;
}

static void load_medapart_sprite_by_slot(void) {
    struct SpriteTree *obj;

    if ((u8)(gGameWork.openedFrom - 2) <= 1) {
        obj = (struct SpriteTree *)0x02026000;
        obj->oams = (struct SpriteNodeOam *)0x020260D0;
        switch (gGameWork.partSlot) {
        case 0:
            draw_medapart_sprite(gSpriteWork->oamBuf, obj, gGameWork.shownId, 0, 0x3C, 0x32, 0x1C2, 8, 5);
            break;
        case 1:
            draw_medapart_sprite(gSpriteWork->oamBuf, obj, gGameWork.shownId, 1, 0x28, 0x3C, 0x1C2, 8, 5);
            break;
        case 2:
            draw_medapart_sprite(gSpriteWork->oamBuf, obj, gGameWork.shownId, 2, 0x28, 0x28, 0x1C2, 8, 6);
            break;
        case 3:
            draw_medapart_sprite(gSpriteWork->oamBuf, obj, gGameWork.shownId, 3, 0x1E, 0x32, 0x1C2, 8, 5);
            break;
        }
    } else if (medapart_get_counts(gGameWork.shownId, gGameWork.partSlot)) {
        obj = (struct SpriteTree *)0x02026000;
        obj->oams = (struct SpriteNodeOam *)0x020260D0;
        switch (gGameWork.partSlot) {
        case 0:
            draw_medapart_sprite(gSpriteWork->oamBuf, obj, gGameWork.shownId, 0, 0x3C, 0x32, 0x1C2, 8, 5);
            break;
        case 1:
            draw_medapart_sprite(gSpriteWork->oamBuf, obj, gGameWork.shownId, 1, 0x28, 0x3C, 0x1C2, 8, 5);
            break;
        case 2:
            draw_medapart_sprite(gSpriteWork->oamBuf, obj, gGameWork.shownId, 2, 0x28, 0x28, 0x1C2, 8, 6);
            break;
        case 3:
            draw_medapart_sprite(gSpriteWork->oamBuf, obj, gGameWork.shownId, 3, 0x1E, 0x32, 0x1C2, 8, 5);
            break;
        }
    }
}

static void medapart_detail_init_sprite(void) {
    struct SpriteTree *obj = (struct SpriteTree *)0x02026000;
    u8 *oam_buf;
    u8 *slot_buf;
    u32 fill;

    mem_fill8((u8 *)obj, 0xD0, 0);
    oam_buf = (u8 *)0x020260D0;
    mem_fill8(oam_buf, 0x800, 0);
    slot_buf = (u8 *)0x020268D0;
    mem_fill8(slot_buf, 0x60, 0);
    gVBlankOamMode = 2;
    gSpriteWork = (struct SpriteWork *)0x02024000;
    fill = 0;
    CpuFastSet(&fill, (void *)0x02024000, 0x01000426);
    gMedabotSpriteSlots = (struct MedabotSpriteSlot *)slot_buf;
    init_sprite_tree(obj, (u8 *)gSpriteWork, (struct SpriteNodeDesc **)gMedabotSpriteNodeDescs,
                     (struct SpriteNodeOam *)oam_buf);
    obj->oams = (struct SpriteNodeOam *)oam_buf;
    draw_medapart_sprite(gSpriteWork->oamBuf, obj, gGameWork.shownId, gGameWork.partSlot, 0x3C, 0x28, 0x1C2, 8, 1);
}

// The skill's index into the detail help messages: special skills (100 and up) restart at 0.
s32 medapart_detail_skill_help_index(void) {
    s32 ret;
    if (gGameWork.partSkill > 99)
        ret = gGameWork.partSkill - 100;
    else
        ret = gGameWork.partSkill;
    return ret;
}

void medapart_detail_draw_skill(void) {
    disable_sprites(10, 15);
    if (gGameWork.partSkill < 100) {
        memcpy_bytes_0803F63C((void *)gSkillTypeNames[gGameWork.partSkillType], gGameWork.textBuf, 14);
        render_text_sprites_08040DB8(gGameWork.textBuf, 10, 1, 9, 10, 12, 0, 1);
    } else {
        memcpy_bytes_0803F63C((void *)gLegTypeNames[gGameWork.partSkill - 100], gGameWork.textBuf, 14);
        render_text_sprites_08040DB8(gGameWork.textBuf, 10, 1, 9, 10, 12, 0, 1);
    }
}

static void medapart_detail_draw_ability(void) {
    disable_sprites(25, 15);
    memcpy_bytes_0803F63C((void *)gAttributeNames[gGameWork.partAbility], gGameWork.textBuf, 14);
    render_text_sprites_08040DB8(gGameWork.textBuf, 25, 2, 11, 8, 12, 0, 1);
}

static void medapart_detail_draw_skill_icon(void) {
    if (gGameWork.partSlot <= 2)
        draw_tile_block(2, 2, 11, 9, REG_BG1CNT, 0x8390 + skill_type_is_remote(gGameWork.partSkillType) * 4);
    else
        draw_tile_block(2, 2, 11, 9, REG_BG1CNT, 0xA208 + gGameWork.partSkill * 4);
}

static void medapart_detail_draw_name(void) {
    disable_sprites(40, 15);
    memcpy_bytes_08041D04((void *)gMedapartNames[0][gGameWork.shownId * 4 + gGameWork.partSlot], gGameWork.textBuf, 15);
    render_text_sprites_08040DB8(gGameWork.textBuf, 40, 11, 3, 10, 13, 0, 1);
}

static void medapart_detail_draw_gender_icon(void) {
    draw_tile_block(2, 2, 21, 3, REG_BG1CNT, 0x7388 + gGameWork.partGender * 4);
}

static void medapart_detail_draw_stat_labels(void) {
    switch (gGameWork.partSlot) {
    case 0:
        draw_tile_block(12, 1, 14, 6, REG_BG1CNT, 0x5300);
        draw_tile_block(12, 1, 14, 7, REG_BG1CNT, 0x530C);
        draw_tile_block(12, 1, 14, 8, REG_BG1CNT, 0x5318);
        draw_tile_block(12, 1, 14, 9, REG_BG1CNT, 0x5324);
        break;
    case 1:
    case 2:
        draw_tile_block(12, 1, 14, 6, REG_BG1CNT, 0x5300);
        draw_tile_block(12, 1, 14, 7, REG_BG1CNT, 0x530C);
        draw_tile_block(12, 1, 14, 8, REG_BG1CNT, 0x5318);
        draw_tile_block(12, 1, 14, 9, REG_BG1CNT, 0x5330);
        draw_tile_block(12, 1, 14, 10, REG_BG1CNT, 0x533C);
        break;
    case 3:
        draw_tile_block(12, 1, 14, 6, REG_BG1CNT, 0x5300);
        draw_tile_block(12, 1, 14, 7, REG_BG1CNT, 0x5348);
        draw_tile_block(12, 1, 14, 8, REG_BG1CNT, 0x5354);
        draw_tile_block(12, 1, 14, 9, REG_BG1CNT, 0x5360);
        draw_tile_block(12, 1, 14, 10, REG_BG1CNT, 0x536C);
        draw_tile_block(12, 1, 14, 11, REG_BG1CNT, 0x5378);
        break;
    }
}

static void medapart_detail_draw_stats(void) {
    switch (gGameWork.partSlot) {
    case 0:
        draw_number_bgcnt(gGameWork.partStat0, 26, 6, 3, REG_BG1CNT, 0x53C4);
        draw_number_bgcnt(gGameWork.partStat1, 26, 7, 3, REG_BG1CNT, 0x53C4);
        draw_number_bgcnt(gGameWork.partStat2, 26, 8, 3, REG_BG1CNT, 0x53C4);
        draw_number_bgcnt(gGameWork.partStat4, 26, 9, 3, REG_BG1CNT, 0x53C4);
        if (gGameWork.partStat3)
            draw_tile_block(2, 1, 25, 8, REG_BG1CNT, 0x5384);
        else
            vram_fill_tilemap_rect(2, 1, 25, 8, REG_BG1CNT, 0);
        break;
    case 1:
    case 2:
        draw_number_bgcnt(gGameWork.partStat0, 26, 6, 3, REG_BG1CNT, 0x53C4);
        draw_number_bgcnt(gGameWork.partStat1, 26, 7, 3, REG_BG1CNT, 0x53C4);
        draw_number_bgcnt(gGameWork.partStat2, 26, 8, 3, REG_BG1CNT, 0x53C4);
        draw_number_bgcnt(gGameWork.partStat4, 26, 9, 3, REG_BG1CNT, 0x53C4);
        draw_number_bgcnt(gGameWork.partStat5, 26, 10, 3, REG_BG1CNT, 0x53C4);
        if (gGameWork.partStat3)
            draw_tile_block(2, 1, 25, 8, REG_BG1CNT, 0x5384);
        else
            vram_fill_tilemap_rect(2, 1, 25, 8, REG_BG1CNT, 0);
        break;
    case 3:
        draw_number_bgcnt(gGameWork.partStat0, 26, 6, 3, REG_BG1CNT, 0x53C4);
        draw_number_bgcnt(gGameWork.partStat1, 26, 7, 3, REG_BG1CNT, 0x53C4);
        draw_number_bgcnt(gGameWork.partStat2, 26, 8, 3, REG_BG1CNT, 0x53C4);
        draw_number_bgcnt(gGameWork.partStat3, 26, 9, 3, REG_BG1CNT, 0x53C4);
        draw_number_bgcnt(gGameWork.partStat4, 26, 10, 3, REG_BG1CNT, 0x53C4);
        draw_number_bgcnt(gGameWork.partStat5, 26, 11, 3, REG_BG1CNT, 0x53C4);
        break;
    }
}

void count_compatible_medaparts(void) {
    u32 i;
    u16 counts;

    gGameWork.freeMedalCount = 0;
    if ((u8)(gGameWork.openedFrom - 2) > 1) {
        for (i = 0; i < 120; i++) {
            counts = medapart_get_counts(i, gGameWork.partSlot);
            if (counts) {
                if (gGameWork.openedFrom == 1) {
                    u32 hi = counts >> 8;
                    if (hi != (counts & 0xFF)) {
                        load_part_data(i, gGameWork.partSlot, gGameWork.medalGfxRecord);
                        if (gTeamSlots[gGameWork.medabotsCursor].gender == gGameWork.medalGfxRecord[3])
                            gGameWork.freeMedalCount++;
                    }
                } else
                    gGameWork.freeMedalCount++;
            }
        }
    }
}

static void medapart_detail_init_arrows(void) {
    if (gGameWork.freeMedalCount > 1) {
        gSpriteEntries[1].flags =
            SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(2) | SPRITE_FLAG_PART_PALETTE;
        gSpriteEntries[1].x = 0x0C;
        gSpriteEntries[1].y = 0x28;
        gSpriteEntries[1].frame = 0x302;
        gSpriteEntries[1].palette = 14;
        gSpriteEntries[1].frame_table = 0;
        gSpriteEntries[1].order = 0x80;
        gSpriteEntries[2].flags =
            SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(2) | SPRITE_FLAG_PART_PALETTE;
        gSpriteEntries[2].x = 0x54;
        gSpriteEntries[2].y = 0x28;
        gSpriteEntries[2].frame = 0x303;
        gSpriteEntries[2].palette = 14;
        gSpriteEntries[2].frame_table = 0;
        gSpriteEntries[2].order = 0x80;
    }
}

static void medapart_detail_blink_arrows(void) {
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

static u32 medapart_detail_cycle_part_input(void) {
    u16 counts;

    if (gGameWork.freeMedalCount <= 1)
        goto none;
    if (KEYS_LO(gRepeatKeys) & DPAD_LEFT) {
        while (1) {
            if (gGameWork.shownId == 0)
                gGameWork.shownId = 119;
            else
                gGameWork.shownId--;
            counts = medapart_get_counts(gGameWork.shownId, gGameWork.partSlot);
            if (counts) {
                if (gGameWork.openedFrom != 1)
                    break;
                {
                    u32 hi = counts >> 8;
                    if (hi != (counts & 0xFF)) {
                        load_part_data(gGameWork.shownId, gGameWork.partSlot, gGameWork.medalGfxRecord);
                        if (gTeamSlots[gGameWork.medabotsCursor].gender == gGameWork.medalGfxRecord[3])
                            break;
                    }
                }
            }
        }
    }
    if (KEYS_LO(gRepeatKeys) & DPAD_RIGHT) {
        while (1) {
            if (gGameWork.shownId == 119)
                gGameWork.shownId = 0;
            else
                gGameWork.shownId++;
            counts = medapart_get_counts(gGameWork.shownId, gGameWork.partSlot);
            if (counts) {
                if (gGameWork.openedFrom != 1)
                    break;
                {
                    u32 hi = counts >> 8;
                    if (hi != (counts & 0xFF)) {
                        load_part_data(gGameWork.shownId, gGameWork.partSlot, gGameWork.medalGfxRecord);
                        if (gTeamSlots[gGameWork.medabotsCursor].gender == gGameWork.medalGfxRecord[3])
                            break;
                    }
                }
            }
        }
    }
    if (KEYS_LO(gRepeatKeys) & (DPAD_RIGHT | DPAD_LEFT)) {
        play_sound_effect(2);
        load_part_data(gGameWork.shownId, gGameWork.partSlot, &gGameWork.partAbility);
        medapart_detail_draw_skill();
        medapart_detail_draw_ability();
        medapart_detail_draw_skill_icon();
        medapart_detail_draw_name();
        medapart_detail_draw_gender_icon();
        medapart_detail_draw_stats();
        medapart_draw_sprite();
        return 1;
    }
none:
    return 0;
}

static void medaparts_help_init_cursor(void) {
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

static void medaparts_help_move_cursor(void) {
    const u8 *rec = gHelpCursorLayouts[gGameWork.helpFromPage];

    gSpriteEntries[6].x = rec[(gGameWork.helpPage + 1) << 1] * 8;
    gSpriteEntries[6].y = rec[((gGameWork.helpPage + 1) << 1) + 1] * 8;
}

static void medapart_trade_init_choice_cursor(void) {
    gSpriteEntries[4].flags =
        SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_FLAG_HFLIP | SPRITE_FLAG_AFFINE | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[4].x = 0xA8;
    gSpriteEntries[4].y = gGameWork.tradeChoice * 16 + 0x38;
    gSpriteEntries[4].frame = 0x307;
    gSpriteEntries[4].palette = 14;
    gSpriteEntries[4].scale_x = 0x40;
    gSpriteEntries[4].scale_y = 0x40;
    gSpriteEntries[4].frame_table = 0;
    gSpriteEntries[4].work[MEDAPARTS_SPR_CLOSE_STEP] = 0;
    gSpriteEntries[4].work[MEDAPARTS_SPR_BLINK_TIMER] = 0;
    gSpriteEntries[4].order = 0xC1;
}

static void medapart_trade_choice_cursor_input(void) {
    if (KEYS_LO(gRepeatKeys) & DPAD_UP) {
        if (gGameWork.tradeChoice == 0)
            gGameWork.tradeChoice = 2;
        else
            gGameWork.tradeChoice--;
    }
    if (KEYS_LO(gRepeatKeys) & DPAD_DOWN) {
        if (gGameWork.tradeChoice == 2)
            gGameWork.tradeChoice = 0;
        else
            gGameWork.tradeChoice++;
    }
    if (KEYS_LO(gRepeatKeys) & (DPAD_UP | DPAD_DOWN)) {
        play_sound_effect(2);
        gSpriteEntries[4].y = gGameWork.tradeChoice * 16 + 0x38;
    }
}

// The choice window's close animation (blink, shrink, clear), one step per frame; 1 when done.
u32 medapart_trade_choice_close_step(void) {
    gMedapartTradeChoiceCloseSteps[gSpriteEntries[4].work[MEDAPARTS_SPR_CLOSE_STEP]]();
    if (gSpriteEntries[4].work[MEDAPARTS_SPR_CLOSE_STEP] == 3)
        return 1;
    return 0;
}

void medapart_trade_choice_blink_step(void) {
    if (gSpriteEntries[4].work[MEDAPARTS_SPR_BLINK_TIMER] != 30) {
        if (gSpriteEntries[4].work[MEDAPARTS_SPR_BLINK_TIMER] & 4)
            gSpriteEntries[4].flags &= (u16)~SPRITE_FLAG_VISIBLE;
        else
            gSpriteEntries[4].flags |= SPRITE_FLAG_VISIBLE;
        gSpriteEntries[4].work[MEDAPARTS_SPR_BLINK_TIMER]++;
    } else {
        gSpriteEntries[4].flags |= SPRITE_FLAG_VISIBLE;
        gSpriteEntries[4].work[MEDAPARTS_SPR_CLOSE_STEP]++;
    }
}

void medapart_trade_choice_shrink_step(void) {
    gSpriteEntries[4].scale_x -= 8;
    gSpriteEntries[4].scale_y -= 8;
    if (gSpriteEntries[4].scale_x == 0) {
        disable_sprites(4, 1);
        gSpriteEntries[4].work[MEDAPARTS_SPR_CLOSE_STEP]++;
    }
}

void medapart_trade_choice_clear_step(void) {
    vram_fill_tilemap_rect(12, 8, 18, 5, REG_BG0CNT, 0);
    gSpriteEntries[4].work[MEDAPARTS_SPR_CLOSE_STEP]++;
}
