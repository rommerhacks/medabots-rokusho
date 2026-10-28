// Vehicle menu (the field menu's "Vehicle" entry), mode-1 handler 2: vehicle_menu_update runs the
// gVehicleMenuStates sub-states: 0 load, 1 slide the window in, 2 input, 3-4 slide out and go back to the field
// menu; 5-7 fade out to the town map (Wings of Wind), 8-9 reload and fade back in; 0xA use the chosen vehicle;
// 0xB-0x10 the "can't use" messages. vehicle_check_usable says which of the 4 entries (enum VehicleId) can be
// used. The menu state lives in gFieldScriptWork after the choice menu fields. Icons are drawn
// with gVehicleIconPalette when usable, else dimmed (gVehicleIconDimPalette, *IconDimTiles).
#include "global.h"
#include "constants/sprites.h"

static u32 vehicle_check_usable(s32 vehicle);
static void vehicle_menu_move_cursor(s32 count);
static void vehicle_menu_clear_icons(void);
static void vehicle_menu_update_cursor(void);
static void vehicle_menu_place_icons(s32 slide_out);
static void vehicle_menu_draw_unowned_row(s32 row);

void vehicle_menu_update(void) {
    gVehicleMenuStates[gGameSubState]();
}

void vehicle_menu_load_gfx(void) {
    memzero_bytes((u8 *)&gFieldScriptWork, 0x874);
    LZ77UnCompVram(gVehicleMenuNameTiles, (void *)0x06000F80);
    LZ77UnCompVram(gVehicleMenuBlankRowTiles, (void *)0x06002100);
    memzero_bytes((u8 *)gFieldTilemapBuf, 0x2000);
    DmaSet(3, gVehicleMenuNamesTilemap, gFieldTilemapBuf, DMA_ENABLE | (0xE0 / 2));
    DmaSet(3, gVehicleMenuBlankRowTilemap, gFieldTilemapBuf + 0x200, DMA_ENABLE | (0x20 / 2));
    copy_tilemap_region((u16 *)gVehicleMenuWindowTilemap, gFieldTilemapBuf + 0x400, 0, 0, 0x10, 10, 0, 0xF, 0);
    fill_tilemap_rect(gFieldTilemapBuf + 0x800, 2, 0xE, 0x10, 10, 0, 0xF, 0);
    copy_tilemap_region(gFieldTilemapBuf, gFieldTilemapBuf + 0x400, 1, 1, 0xE, 8, 0x7C, 0xE, 0);

    switch (vehicle_check_usable(0)) {
    case 0:
        LZ77UnCompVram(gMiniSWheelIconTiles, (void *)0x06016F80);
        break;
    case 1:
        LZ77UnCompVram(gVehicleIconBlankTiles, (void *)0x06016F80);
        vehicle_menu_draw_unowned_row(0);
        break;
    default:
        LZ77UnCompVram(gMiniSWheelIconDimTiles, (void *)0x06016F80);
        break;
    }
    switch (vehicle_check_usable(1)) {
    case 0:
        LZ77UnCompVram(gSilverLocketIconTiles, (void *)0x06017000);
        break;
    case 1:
        LZ77UnCompVram(gVehicleIconBlankTiles, (void *)0x06017000);
        vehicle_menu_draw_unowned_row(1);
        break;
    default:
        LZ77UnCompVram(gSilverLocketIconDimTiles, (void *)0x06017000);
        break;
    }
    switch (vehicle_check_usable(2)) {
    case 0:
        LZ77UnCompVram(gWingsOfWindIconTiles, (void *)0x06017080);
        break;
    case 1:
        LZ77UnCompVram(gVehicleIconBlankTiles, (void *)0x06017080);
        vehicle_menu_draw_unowned_row(2);
        break;
    default:
        LZ77UnCompVram(gWingsOfWindIconDimTiles, (void *)0x06017080);
        break;
    }
    switch (vehicle_check_usable(3)) {
    case 0:
        LZ77UnCompVram(gPeriscopeIconTiles, (void *)0x06017100);
        break;
    case 1:
        LZ77UnCompVram(gVehicleIconBlankTiles, (void *)0x06017100);
        vehicle_menu_draw_unowned_row(3);
        break;
    default:
        LZ77UnCompVram(gPeriscopeIconDimTiles, (void *)0x06017100);
        break;
    }

    DmaCopy32(3, gVehicleIconPalette, OBJ_PLTT + 0x180, 32) DmaCopy32(3, gVehicleIconDimPalette, OBJ_PLTT + 0x1A0, 32)
        decompress_bg_tiles_to_vram_bg();
    DmaCopy32(3, gTextWindowObjPalette, PLTT + 0x1C0, 32)
        lz_decompress_dispatch(gChoiceMenuFrameTiles, (void *)0x06002600);
    lz_decompress_dispatch(gChoiceMenuLabelTiles, (void *)0x060026E0);
    lz_decompress_dispatch(gCursorArrowTiles, (void *)0x06017E00);
    DmaCopy32(3, gCursorArrowPalette, OBJ_PLTT + 0x1C0, 32) gFieldScriptWork.unk66 = 0;
    gFieldScriptWork.frame = 0;
    gFieldScriptWork.slideStep = 0;
    gFieldScriptWork.unk6E = gFieldScriptWork.cursorY = gFieldScriptWork.cursorX = 0;
    gFieldScriptWork.cursorX = 0x10;
    gFieldScriptWork.cursorY = 3;
    game_substate_advance();
}

void vehicle_menu_slide_in(void) {
    gFieldScriptWork.unk66 = 0;
    if (gFieldScriptWork.slideStep < 0x10) {
        gFieldScriptWork.slideStep++;
        copy_tilemap_rect_with_offset(gFieldTilemapBuf + 0x400, (u16 *)0x06002800, 2, 0x1E - gFieldScriptWork.slideStep,
                                      gFieldScriptWork.slideStep, 10, 0x20, 0x20, 0, 0);
        vehicle_menu_place_icons(0);
    } else {
        sprite_entry_init(0x7F, SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_FLAG_PART_PALETTE, 0x307, 0xC, 0);
        vehicle_menu_update_cursor();
        gFieldScriptWork.cursor = 0;
        message_steps_reset();
        game_substate_advance();
    }
}

static void vehicle_menu_next_state(void) {
    game_substate_advance();
}

void vehicle_menu_handle_input(void) {
    u32 result;

    gFieldScriptWork.frame++;
    vehicle_menu_update_cursor();
    vehicle_menu_move_cursor(VEHICLE_COUNT);
    if (KEYS_LO(gNewKeys) & 1) {
        result = vehicle_check_usable(gFieldScriptWork.cursor);
        if (result != VEHICLE_USABLE) {
            gFieldScriptWork.frame = 0;
            vehicle_menu_update_cursor();
            field_play_sound_effect(6);
            switch (result) {
            case VEHICLE_NOT_OWNED:
                break;
            case VEHICLE_BOT_INCOMPLETE:
                gFieldScriptWork.textPage = 0;
                gGameSubState = 0xB;
                break;
            case VEHICLE_AREA_FORBIDS:
                gGameSubState = 0xD;
                break;
            case VEHICLE_BLOCKED:
            case VEHICLE_FORM_CONFLICT:
            case VEHICLE_NOT_FACING_WATER:
                gGameSubState = 0xF;
                break;
            }
        } else {
            copy_tilemap_rect_with_offset((u16 *)0x06002800, gFieldScriptWork.savedBg, 0, 0, 0x1E, 0x14, 0x20, 0x20,
                                          result, result);
            field_play_sound_effect(4);
            gGameSubState = 0xA;
        }
    } else if (KEYS_LO(gNewKeys) & 2) {
        field_play_sound_effect(5);
        sprite_entry_clear(0x7F);
        gFieldScriptWork.slideStep = 0x10;
        game_substate_advance();
    }
}

void vehicle_menu_slide_out(void) {
    if (gFieldScriptWork.slideStep != 0) {
        copy_tilemap_rect_with_offset(gFieldTilemapBuf + 0x800, (u16 *)0x06002800, 2, 0x1E - gFieldScriptWork.slideStep,
                                      1, 10, 0x20, 0x20, 0, 0);
        copy_tilemap_rect_with_offset(gFieldTilemapBuf + 0x400, (u16 *)0x06002800, 2, 0x1F - gFieldScriptWork.slideStep,
                                      gFieldScriptWork.slideStep, 10, 0x20, 0x20, 0, 0);
        vehicle_menu_place_icons(1);
        gFieldScriptWork.slideStep--;
    } else {
        lz_decompress_dispatch(gFieldMenuSaveLabelTiles, (void *)0x06002100);
        game_substate_advance();
    }
}

void vehicle_menu_return_to_field_menu(void) {
    switch_game_mode(0x40, 0);
}

void vehicle_menu_start_fade_out(void) {
    setup_palette_fade_to_color_with_obj(0, 0.0f, 32.0f, 8.0f);
    game_substate_advance();
}

void vehicle_menu_wait_fade_out(void) {
    if (run_blend_fade_transition(0))
        game_substate_advance();
}

void vehicle_menu_open_flight_map(void) {
    switch_game_mode(6, 0);
}

// Re-entry from field_mode result 6 (guess: the town map cancelled without flying): reload the area and the
// menu, then fade in.
void vehicle_menu_reload(void) {
    u32 zero;

    clear_vram_tiles_1000();
    memzero_bytes((u8 *)gSpriteEntries, 0x2000);
    memzero_bytes((u8 *)gEntityStates, 0x200);
    zero = 0;
    DmaSet(3, &zero, OAM, 0x85000100);
    REG_DISPCNT = 0x1F40;
    gFieldWork.npc_load_mode = 1;
    area_load_graphics();
    lz_decompress_dispatch(gMenuSlideLineTile, (void *)0x060017E0);
    lz_decompress_dispatch(gFieldMenuMedawatchLabelTiles, (void *)0x06001800);
    lz_decompress_dispatch(gFieldMenuItemLabelTiles, (void *)0x06001B00);
    lz_decompress_dispatch(gFieldMenuVehicleLabelTiles, (void *)0x06001E00);
    lz_decompress_dispatch(gFieldMenuSaveLabelTiles, (void *)0x06002100);
    lz_decompress_dispatch(gMoneyWindowTiles, (void *)0x06002400);
    DmaCopy32(3, gMenuBgPalette, 0x0202FBE0, 32) lz_decompress_dispatch(gSpriteFontTiles, (void *)0x06017400);
    DmaCopy32(3, gSpriteFontPalette, 0x0202F9E0, 32) LZ77UnCompVram(gVehicleMenuNameTiles, (void *)0x06000F80);
    LZ77UnCompVram(gVehicleMenuBlankRowTiles, (void *)0x06002100);
    memzero_bytes((u8 *)gFieldTilemapBuf, 0x2000);
    DmaSet(3, gVehicleMenuNamesTilemap, gFieldTilemapBuf, DMA_ENABLE | (0xE0 / 2));
    DmaSet(3, gVehicleMenuBlankRowTilemap, gFieldTilemapBuf + 0x200, DMA_ENABLE | (0x20 / 2));
    copy_tilemap_region((u16 *)gVehicleMenuWindowTilemap, gFieldTilemapBuf + 0x400, 0, 0, 0x10, 10, 0, 0xF, 0);
    fill_tilemap_rect(gFieldTilemapBuf + 0x800, 2, 0xE, 0x10, 10, 0, 0xF, 0);
    copy_tilemap_region(gFieldTilemapBuf, gFieldTilemapBuf + 0x400, 1, 1, 0xE, 8, 0x7C, 0xE, 0);

    switch (vehicle_check_usable(0)) {
    case 0:
        LZ77UnCompVram(gMiniSWheelIconTiles, (void *)0x06016F80);
        break;
    case 1:
        LZ77UnCompVram(gVehicleIconBlankTiles, (void *)0x06016F80);
        vehicle_menu_draw_unowned_row(0);
        break;
    default:
        LZ77UnCompVram(gMiniSWheelIconDimTiles, (void *)0x06016F80);
        break;
    }
    switch (vehicle_check_usable(1)) {
    case 0:
        LZ77UnCompVram(gSilverLocketIconTiles, (void *)0x06017000);
        break;
    case 1:
        LZ77UnCompVram(gVehicleIconBlankTiles, (void *)0x06017000);
        vehicle_menu_draw_unowned_row(1);
        break;
    default:
        LZ77UnCompVram(gSilverLocketIconDimTiles, (void *)0x06017000);
        break;
    }
    switch (vehicle_check_usable(2)) {
    case 0:
        LZ77UnCompVram(gWingsOfWindIconTiles, (void *)0x06017080);
        break;
    case 1:
        LZ77UnCompVram(gVehicleIconBlankTiles, (void *)0x06017080);
        vehicle_menu_draw_unowned_row(2);
        break;
    default:
        LZ77UnCompVram(gWingsOfWindIconDimTiles, (void *)0x06017080);
        break;
    }
    switch (vehicle_check_usable(3)) {
    case 0:
        LZ77UnCompVram(gPeriscopeIconTiles, (void *)0x06017100);
        break;
    case 1:
        LZ77UnCompVram(gVehicleIconBlankTiles, (void *)0x06017100);
        vehicle_menu_draw_unowned_row(3);
        break;
    default:
        LZ77UnCompVram(gPeriscopeIconDimTiles, (void *)0x06017100);
        break;
    }

    lz_decompress_dispatch(gMessageWindowTiles, (void *)0x06000020);
    lz_decompress_dispatch(gMessageWindowIconTiles, (void *)0x06001780);
    DmaCopy32(3, gMenuBgPalette, 0x0202FBE0, 32) DmaCopy32(3, gTextWindowObjPalette, 0x0202FBC0, 32)
        lz_decompress_dispatch(gChoiceMenuFrameTiles, (void *)0x06002600);
    lz_decompress_dispatch(gChoiceMenuLabelTiles, (void *)0x060026E0);
    lz_decompress_dispatch(gCursorArrowTiles, (void *)0x06017E00);
    DmaCopy32(3, gCursorArrowPalette, 0x0202F9C0, 32)
        copy_tilemap_rect_with_offset(gFieldScriptWork.savedBg, (u16 *)0x06002800, 0, 0, 0x1E, 0x14, 0x20, 0x20, 0, 0);
    DmaCopy32(3, gVehicleIconPalette, 0x0202F980, 32) DmaCopy32(3, gVehicleIconDimPalette, 0x0202F9A0, 32)
        vehicle_menu_place_icons(0);
    setup_palette_fade_to_color(0, 32.0f, 0.0f, 8.0f);
    game_substate_advance();
}

void vehicle_menu_wait_fade_in(void) {
    if (run_blend_fade_transition(0)) {
        sprite_entry_init(0x7F, SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_FLAG_PART_PALETTE, 0x307, 0xC, 0);
        vehicle_menu_update_cursor();
        gGameSubState = 2;
    }
}

// The field takes over: 0x41 rides the car, 0x43 runs the Silver Locket warp, 0x42 swims; Wings of Wind fades
// out to the town map first.
void vehicle_menu_use_vehicle(void) {
    struct FieldScriptWork *menu = &gFieldScriptWork;

    if (menu->cursor != VEHICLE_WINGS_OF_WIND) {
        clear_vram_tiles_1000();
        vehicle_menu_clear_icons();
    }
    sprite_entry_clear(0x7F);
    if (menu->cursor == VEHICLE_MINI_S_WHEEL)
        switch_game_mode(0x41, 0);
    else if (menu->cursor == VEHICLE_SILVER_LOCKET)
        switch_game_mode(0x43, 0);
    else if (menu->cursor == VEHICLE_WINGS_OF_WIND)
        gGameSubState = 5;
    else if (menu->cursor == VEHICLE_PERISCOPE)
        switch_game_mode(0x42, 0);
}

// Puts the name of the Medabot (pages 0, 5) or its part (pages 1-4) the chosen vehicle needs into the text
// buffer for the missing-parts message page.
void vehicle_menu_load_part_name(void) {
    u32 bot_id;

    if (gFieldScriptWork.cursor == VEHICLE_MINI_S_WHEEL) {
        bot_id = 0x55;
        switch (gFieldScriptWork.textPage) {
        case 0:
            copy_string_to_text_buffer(0, medabot_name(bot_id));
            break;
        case 1:
            copy_string_to_text_buffer(0, medapart_name(0, bot_id));
            break;
        case 2:
            copy_string_to_text_buffer(1, medapart_name(1, bot_id));
            break;
        case 3:
            copy_string_to_text_buffer(2, medapart_name(2, bot_id));
            break;
        case 4:
            copy_string_to_text_buffer(3, medapart_name(3, bot_id));
            break;
        case 5:
            copy_string_to_text_buffer(0, medabot_name(bot_id));
            break;
        }
    } else if (gFieldScriptWork.cursor == VEHICLE_WINGS_OF_WIND) {
        bot_id = 0xB;
        switch (gFieldScriptWork.textPage) {
        case 0:
            copy_string_to_text_buffer(0, medabot_name(bot_id));
            break;
        case 1:
            copy_string_to_text_buffer(0, medapart_name(0, bot_id));
            break;
        case 2:
            copy_string_to_text_buffer(1, medapart_name(1, bot_id));
            break;
        case 3:
            copy_string_to_text_buffer(2, medapart_name(2, bot_id));
            break;
        case 4:
            copy_string_to_text_buffer(3, medapart_name(3, bot_id));
            break;
        case 5:
            copy_string_to_text_buffer(0, medabot_name(bot_id));
            break;
        }
    } else if (gFieldScriptWork.cursor == VEHICLE_PERISCOPE) {
        bot_id = 0x6B;
        switch (gFieldScriptWork.textPage) {
        case 0:
            copy_string_to_text_buffer(0, medabot_name(bot_id));
            break;
        case 1:
            copy_string_to_text_buffer(0, medapart_name(0, bot_id));
            break;
        case 2:
            copy_string_to_text_buffer(1, medapart_name(1, bot_id));
            break;
        case 3:
            copy_string_to_text_buffer(2, medapart_name(2, bot_id));
            break;
        case 4:
            copy_string_to_text_buffer(3, medapart_name(3, bot_id));
            break;
        case 5:
            copy_string_to_text_buffer(0, medabot_name(bot_id));
            break;
        }
    }
    if (gFieldScriptWork.textPage == 0)
        message_steps_reset();
    game_substate_advance();
}

void vehicle_menu_show_parts_message(void) {
    if (message_step_run(1, 1, 0, gTextTable[gFieldScriptWork.textPage + 0x82])) {
        if (++gFieldScriptWork.textPage <= 5)
            gGameSubState--;
        else
            gGameSubState = 2;
    }
}

void vehicle_menu_area_message_init(void) {
    message_steps_reset();
    game_substate_advance();
}

void vehicle_menu_show_area_message(void) {
    if (message_step_run(1, 1, 0, gTextTable[0x81]))
        gGameSubState = 2;
}

void vehicle_menu_blocked_message_init(void) {
    message_steps_reset();
    game_substate_advance();
}

void vehicle_menu_show_blocked_message(void) {
    if (message_step_run(1, 1, 0, gTextTable[0x80]))
        gGameSubState = 2;
}

static void vehicle_menu_unused_nop(void) {}

// Whether vehicle can be used now (enum VehicleUse): the item, the full Medabot on the team, the area, the
// map-script block flags, the current player_form; checked in that order.
static u32 vehicle_check_usable(s32 vehicle) {
    u32 result = 0;
    s32 parts;
    u32 allowed;
    u32 flag;

    switch (vehicle) {
    case VEHICLE_MINI_S_WHEEL:
        flag = field_item_quantity(0x12);
        result = VEHICLE_NOT_OWNED;
        if (!flag)
            break;
        parts = team_has_part_equipped(0x55, 0);
        parts += team_has_part_equipped(0x55, 1);
        parts += team_has_part_equipped(0x55, 2);
        parts += team_has_part_equipped(0x55, 3);
        result = VEHICLE_BOT_INCOMPLETE;
        if (parts != 4)
            break;
        allowed = area_allows_vehicle(0);
        result = VEHICLE_AREA_FORBIDS;
        if (!allowed)
            break;
        flag = gFieldWork.useBlockFlags & 2;
        result = VEHICLE_BLOCKED;
        if (flag)
            break;
        result = VEHICLE_USABLE;
        if (gFieldWork.player_form == 2)
            result = VEHICLE_FORM_CONFLICT;
        break;
    case VEHICLE_SILVER_LOCKET:
        flag = field_item_quantity(0x18);
        result = VEHICLE_NOT_OWNED;
        if (!flag)
            break;
        flag = gFieldWork.useBlockFlags & 0x10;
        result = VEHICLE_BLOCKED;
        if (flag)
            break;
        result = VEHICLE_USABLE;
        if (gFieldWork.player_form == 1 || gFieldWork.player_form == 2)
            result = VEHICLE_FORM_CONFLICT;
        break;
    case VEHICLE_WINGS_OF_WIND:
        flag = field_item_quantity(0x19);
        result = VEHICLE_NOT_OWNED;
        if (!flag)
            break;
        parts = team_has_part_equipped(0xB, 0);
        parts += team_has_part_equipped(0xB, 1);
        parts += team_has_part_equipped(0xB, 2);
        parts += team_has_part_equipped(0xB, 3);
        result = VEHICLE_BOT_INCOMPLETE;
        if (parts != 4)
            break;
        allowed = area_allows_vehicle(1);
        if (gAreaTypes[gFieldWork.area_id] == 0xA)
            allowed = 0;
        result = VEHICLE_AREA_FORBIDS;
        if (!allowed)
            break;
        flag = gFieldWork.useBlockFlags & 4;
        result = VEHICLE_BLOCKED;
        if (flag)
            break;
        result = VEHICLE_USABLE;
        if (gFieldWork.player_form == 1 || gFieldWork.player_form == 2)
            result = VEHICLE_FORM_CONFLICT;
        break;
    case VEHICLE_PERISCOPE:
        flag = field_item_quantity(0x26);
        result = VEHICLE_NOT_OWNED;
        if (!flag)
            break;
        parts = team_has_part_equipped(0x6B, 0);
        parts += team_has_part_equipped(0x6B, 1);
        parts += team_has_part_equipped(0x6B, 2);
        parts += team_has_part_equipped(0x6B, 3);
        result = VEHICLE_BOT_INCOMPLETE;
        if (parts != 4)
            break;
        flag = gFieldWork.useBlockFlags & 8;
        result = VEHICLE_BLOCKED;
        if (flag)
            break;
        flag = (u8)(gFieldWork.player_form - 1);
        result = VEHICLE_FORM_CONFLICT;
        if (flag <= 1)
            break;
        result = VEHICLE_USABLE;
        if (get_adjacent_tile_value(gFieldWork.player_facing) != 3)
            result = VEHICLE_NOT_FACING_WATER;
        break;
    }
    return result;
}

static void vehicle_menu_move_cursor(s32 count) {
    struct FieldScriptWork *menu;

    gFieldDebug.frame++;
    if (KEYS_LO(gRepeatKeys) & 0x40) {
        field_play_sound_effect(2);
        menu = &gFieldScriptWork;
        if (--menu->cursor == 0xFF)
            menu->cursor = count - 1;
        menu->cursorY = gVehicleMenuCursorRows[menu->cursor];
        vehicle_menu_update_cursor();
    }
    if (KEYS_LO(gRepeatKeys) & 0x80) {
        field_play_sound_effect(2);
        menu = &gFieldScriptWork;
        menu->cursor++;
        if (menu->cursor >= count)
            menu->cursor = 0;
        menu->cursorY = gVehicleMenuCursorRows[menu->cursor];
        vehicle_menu_update_cursor();
    }
}

static void vehicle_menu_clear_icons(void) {
    sprite_entry_clear(0x20);
    sprite_entry_clear(0x21);
    sprite_entry_clear(0x22);
    sprite_entry_clear(0x23);
}

static void vehicle_menu_update_cursor(void) {
    struct FieldScriptWork *menu = &gFieldScriptWork;
    s32 wobble = (u8)(menu->frame & 4) >> 2;

    if (menu->frame & 8)
        wobble = -wobble;
    gSpriteEntries[0x7F].x = menu->cursorX * 8 + 8 + wobble;
    gSpriteEntries[0x7F].y = menu->cursorY * 8 + 8;
    gSpriteEntries[0x7F].frame = 0x307;
    gSpriteEntries[0x7F].palette = 0xE;
    gSpriteEntries[0x7F].frame_table = 0;
    gSpriteEntries[0x7F].scale_x = 1;
    gSpriteEntries[0x7F].scale_y = 1;
    gSpriteEntries[0x7F].order = 0xFF;
}

// Icon sprites 0x20-0x23, palette 0xC when usable else 0xD, following the window as it slides.
static void vehicle_menu_place_icons(s32 slide_out) {
    s32 base_x;

    sprite_entry_init(0x20, SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_FLAG_PART_PALETTE, 0x91,
                      vehicle_check_usable(0) == 0 ? 0xC : 0xD, 1);
    gSpriteEntries[0x20].x = (0x10 - gFieldScriptWork.slideStep) * 8 + (base_x = slide_out * 8 + 0x90);
    gSpriteEntries[0x20].y = 0x18;
    gSpriteEntries[0x20].order |= 0xFF;
    sprite_entry_init(0x21, SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_FLAG_PART_PALETTE, 0x92,
                      vehicle_check_usable(1) == 0 ? 0xC : 0xD, 1);
    gSpriteEntries[0x21].x = (0x10 - gFieldScriptWork.slideStep) * 8 + base_x;
    gSpriteEntries[0x21].y = 0x28;
    gSpriteEntries[0x21].order |= 0xFF;
    sprite_entry_init(0x22, SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_FLAG_PART_PALETTE, 0x93,
                      vehicle_check_usable(2) == 0 ? 0xC : 0xD, 1);
    gSpriteEntries[0x22].x = (0x10 - gFieldScriptWork.slideStep) * 8 + base_x;
    gSpriteEntries[0x22].y = 0x38;
    gSpriteEntries[0x22].order |= 0xFF;
    sprite_entry_init(0x23, SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_FLAG_PART_PALETTE, 0x94,
                      vehicle_check_usable(3) == 0 ? 0xC : 0xD, 1);
    gSpriteEntries[0x23].x = (0x10 - gFieldScriptWork.slideStep) * 8 + base_x;
    gSpriteEntries[0x23].y = 0x48;
    gSpriteEntries[0x23].order |= 0xFF;
}

// Blanks the name of an entry whose item the player lacks.
static void vehicle_menu_draw_unowned_row(s32 row) {
    copy_tilemap_region(gFieldTilemapBuf + 0x200, gFieldTilemapBuf + 0x400, row * 2 + 1, 6, 8, 2, 0x108, 0xE, 0);
}
