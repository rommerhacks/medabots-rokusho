// Game state 1: the field pause menu (START on the field): Medawatch / Item / Vehicle / Save and the money
// display, its open / close animations and the return from the sub-screens.

#include "global.h"
#include "constants/sprites.h"

static void field_menu_init_cursor(void);

// Game state 1: the field pause menu (Medawatch / Item / Vehicle / Save, money display).
void field_menu_update(void) {
    gFieldMenuHandlers[gGameSubState]();
}

void field_menu_load_gfx(void) {
    REG_DISPCNT = 0x1F60;
    REG_BG0CNT = 0x500;
    lz_decompress_dispatch(gFieldMenuMedawatchLabelTiles, (void *)(BG_VRAM + 0x1800));
    lz_decompress_dispatch(gFieldMenuItemLabelTiles, (void *)(BG_VRAM + 0x1B00));
    lz_decompress_dispatch(gFieldMenuVehicleLabelTiles, (void *)(BG_VRAM + 0x1E00));
    lz_decompress_dispatch(gFieldMenuSaveLabelTiles, (void *)(BG_VRAM + 0x2100));
    lz_decompress_dispatch(gMoneyWindowTiles, (void *)(BG_VRAM + 0x2400));
    DmaSet(3, gMenuBgPalette, 0x050001E0, 0x80000010);
    lz_decompress_dispatch(gSpriteFontTiles, (void *)(OBJ_VRAM0 + 0x7400));
    DmaSet(3, gSpriteFontPalette, 0x050003E0, 0x80000010);
    play_song(6);
    gGameWork.stepCounter = 0;
    gGameSubState++;
}

void field_menu_open_anim(void) {
    if (gGameWork.stepCounter <= 12)
        write_tilemap_rect(12, 2, 18, 1, gUiTilemaps[gGameWork.stepCounter + 0x13], REG_BG0CNT, 0);
    if ((u8)(gGameWork.stepCounter - 2) <= 12)
        write_tilemap_rect(12, 2, 18, 3, gUiTilemaps[gGameWork.stepCounter + 0x1E], REG_BG0CNT, 0);
    if ((u8)(gGameWork.stepCounter - 4) <= 12)
        write_tilemap_rect(12, 2, 18, 5, gUiTilemaps[gGameWork.stepCounter + 0x29], REG_BG0CNT, 0);
    if ((u8)(gGameWork.stepCounter - 6) <= 12)
        write_tilemap_rect(12, 2, 18, 7, gUiTilemaps[gGameWork.stepCounter + 0x34], REG_BG0CNT, 0);
    if (gGameWork.stepCounter == 10) {
        lz_decompress_dispatch(gMoneyWindowHalfTiles, (void *)(BG_VRAM + 0x2400));
        set_tilemap_and_decompress_bg(0x15, 9, gMoneyWindowHalfTilemap, REG_BG0CNT, 0x120);
    }
    if (gGameWork.stepCounter == 12) {
        lz_decompress_dispatch(gMoneyWindowTiles, (void *)(BG_VRAM + 0x2400));
        set_tilemap_and_decompress_bg(0x15, 9, gMoneyWindowTilemap, REG_BG0CNT, 0x120);
    }
    if (++gGameWork.stepCounter > 18) {
        divide_by_10000(gGameWork.textBuf, gPlayerRecord.money);
        render_text_sprites_08040DB8(gGameWork.textBuf, 10, 0x17, 10, 5, 15, 2, 0);
        gGameWork.fieldMenuCursor = 0;
        field_menu_init_cursor();
        gGameSubState++;
    }
}

void field_menu_handle_input(void) {
    process_sprite_anim_commands(gBattleSpriteAnimScripts[0], 0);
    if (KEYS_LO(gRepeatKeys) & DPAD_UP) {
        play_sound_effect(2);
        gGameWork.fieldMenuCursor = (gGameWork.fieldMenuCursor - 1) & 3;
        gSpriteEntries[0].y = gGameWork.fieldMenuCursor * 16 + 8;
    }
    if (KEYS_LO(gRepeatKeys) & DPAD_DOWN) {
        play_sound_effect(2);
        gGameWork.fieldMenuCursor = (gGameWork.fieldMenuCursor + 1) & 3;
        gSpriteEntries[0].y = gGameWork.fieldMenuCursor * 16 + 8;
    }
    if (KEYS_LO(gNewKeys) & B_BUTTON) {
        fade_out_music(0x10);
        play_sound_effect(5);
        clear_battle_sprite_slot(0, 1);
        clear_battle_sprite_slot(10, 7);
        gGameWork.stepCounter = 0;
        gGameSubState = 3;
    } else if (KEYS_LO(gNewKeys) & A_BUTTON) {
        play_sound_effect(4);
        gGameSubState = 6;
    }
}

void field_menu_close_anim(void) {
    if (gGameWork.stepCounter <= 12)
        write_tilemap_rect(12, 2, 18, 1, gUiTilemaps[0x1F - gGameWork.stepCounter], REG_BG0CNT, 0);
    if ((u8)(gGameWork.stepCounter - 2) <= 12)
        write_tilemap_rect(12, 2, 18, 3, gUiTilemaps[0x2E - gGameWork.stepCounter], REG_BG0CNT, 0);
    if ((u8)(gGameWork.stepCounter - 4) <= 12)
        write_tilemap_rect(12, 2, 18, 5, gUiTilemaps[0x3D - gGameWork.stepCounter], REG_BG0CNT, 0);
    if ((u8)(gGameWork.stepCounter - 6) <= 12)
        write_tilemap_rect(12, 2, 18, 7, gUiTilemaps[0x4C - gGameWork.stepCounter], REG_BG0CNT, 0);
    if (gGameWork.stepCounter == 10) {
        lz_decompress_dispatch(gMoneyWindowHalfTiles, (void *)(BG_VRAM + 0x2400));
        set_tilemap_and_decompress_bg(0x15, 9, gMoneyWindowHalfTilemap, REG_BG0CNT, 0x120);
    }
    if (gGameWork.stepCounter == 12)
        vram_fill_tilemap_rect(9, 4, 0x15, 9, REG_BG0CNT, 0);
    if (++gGameWork.stepCounter > 18)
        return_to_field();
}

void field_menu_select_start(void) {
    switch (gGameWork.fieldMenuCursor) {
    case 0:
        vram_fill_tilemap_rect(13, 10, 17, 3, REG_BG0CNT, 0);
        gGameWork.menuRowAnim = 1;
        break;
    case 1:
        vram_fill_tilemap_rect(13, 2, 17, 1, REG_BG0CNT, 0);
        vram_fill_tilemap_rect(13, 8, 17, 5, REG_BG0CNT, 0);
        gGameWork.menuRowAnim = 3;
        break;
    case 2:
        vram_fill_tilemap_rect(13, 4, 17, 1, REG_BG0CNT, 0);
        vram_fill_tilemap_rect(13, 6, 17, 7, REG_BG0CNT, 0);
        gGameWork.menuRowAnim = 5;
        break;
    default:
        vram_fill_tilemap_rect(13, 6, 17, 1, REG_BG0CNT, 0);
        vram_fill_tilemap_rect(13, 4, 17, 9, REG_BG0CNT, 0);
        gGameWork.menuRowAnim = 7;
        break;
    }
    clear_battle_sprite_slot(0, 1);
    clear_battle_sprite_slot(10, 7);
    gGameSubState++;
}

void field_menu_select_collapse(void) {
    write_tilemap_rect(12, 2, 18, gGameWork.menuRowAnim - 1, gUiTilemaps[gGameWork.fieldMenuCursor * 13 + 0x1F],
                       REG_BG0CNT, 0);
    vram_fill_tilemap_rect(12, 1, 18, gGameWork.menuRowAnim + 1, REG_BG0CNT, 0);
    if (--gGameWork.menuRowAnim == 0) {
        lz_decompress_dispatch(gMenuSlideLineTile, (void *)(BG_VRAM + 0x17E0));
        palette_backup_from_hardware();
        gGameWork.stepCounter = 0;
        if (gGameWork.fieldMenuCursor == 0)
            fade_out_music(0x10);
        gGameSubState++;
    }
}

void field_menu_select_slide(void) {
    if (gGameWork.fieldMenuCursor != 2 && gGameWork.stepCounter <= 16) {
        bg_palettes_blend_masked_now(0, gGameWork.stepCounter * 2, 0x1FFF);
        obj_palettes_blend_masked_now(0, gGameWork.stepCounter * 2, 0xFFFF);
        gGameWork.stepCounter++;
    }
    write_tilemap_rect(12, 2, 18 - gGameWork.menuRowAnim, 0, gUiTilemaps[gGameWork.fieldMenuCursor * 13 + 0x1F],
                       REG_BG0CNT, 0);
    write_tilemap_rect(1, 2, 30 - gGameWork.menuRowAnim, 0, gUiTilemaps[0x47], REG_BG0CNT, 0);
    if (++gGameWork.menuRowAnim == 19)
        gGameSubState++;
}

// Runs the chosen entry: Medawatch (game state 2), Item (mode 2 state 4), Vehicle, Save (mode 2 state 5).
void field_menu_run_choice(void) {
    switch (gGameWork.fieldMenuCursor) {
    case 0:
        play_song(7);
        gGameWork.medawatchCursor = 0;
        gGameState = MODE0_STATE_MEDAWATCH;
        gGameSubState = 0;
        clear_battle_sprite_slot(0x28, 0x57);
        break;
    case 1:
        gGameMode = 2;
        gGameState = 4;
        gGameSubState = 0;
        clear_battle_sprite_slot(0x28, 0x57);
        break;
    case 2:
        field_resume(1);
        break;
    default:
        gPlayTimeRunning = 0;
        gGameMode = 2;
        gGameState = 5;
        gGameSubState = 0;
        clear_battle_sprite_slot(0x28, 0x57);
        break;
    }
}

void field_menu_return_init(void) {
    gPlayTimeRunning = 1;
    if (gGameWork.fieldMenuCursor != 2) {
        REG_DISPCNT &= 0xF1FF;
        DmaSet(3, gSpriteFontPalette, OBJ_PAL_BACKUP_ADDR(15), 0x84000008);
        area_load_graphics();
        blend_set_alpha_12_10();
        setup_blend_effect(0x40, 0x2F00, 5, 16, 16, 16, 12, 10, 0);
        REG_DISPCNT |= 0xF60;
    }
    gGameWork.menuRowAnim = 18;
    gGameWork.stepCounter = 0;
    gGameSubState++;
}

void field_menu_return_slide(void) {
    if (gGameWork.fieldMenuCursor != 2 && gGameWork.stepCounter <= 16) {
        blend_effect_update();
        bg_palettes_blend_masked_now(0, 32 - gGameWork.stepCounter * 2, 0x1FFF);
        obj_palettes_blend_masked_now(0, 32 - gGameWork.stepCounter * 2, 0xFFFF);
        gGameWork.stepCounter++;
    }
    gGameWork.menuRowAnim--;
    write_tilemap_rect(12, 2, 18 - gGameWork.menuRowAnim, 0, gUiTilemaps[gGameWork.fieldMenuCursor * 13 + 0x1F],
                       REG_BG0CNT, 0);
    vram_fill_tilemap_rect(1, 2, 17 - gGameWork.menuRowAnim, 0, REG_BG0CNT, 0);
    if (gGameWork.menuRowAnim == 0) {
        gVBlankCallback = empty_callback;
        gGameWork.menuRowAnim = gGameWork.fieldMenuCursor * 2 + 1;
        gGameWork.stepCounter = 0;
        gGameSubState++;
    }
}

void field_menu_return_expand(void) {
    write_tilemap_rect(12, 2, 18, gGameWork.stepCounter + 1, gUiTilemaps[gGameWork.fieldMenuCursor * 13 + 0x1F],
                       REG_BG0CNT, 0);
    vram_fill_tilemap_rect(12, 1, 18, gGameWork.stepCounter, REG_BG0CNT, 0);
    if (gGameWork.stepCounter + 1 == gGameWork.menuRowAnim) {
        switch (gGameWork.fieldMenuCursor) {
        case 0:
            write_tilemap_rect(12, 2, 18, 3, gUiTilemaps[0x2C], REG_BG0CNT, 0);
            write_tilemap_rect(12, 2, 18, 5, gUiTilemaps[0x39], REG_BG0CNT, 0);
            write_tilemap_rect(12, 2, 18, 7, gUiTilemaps[0x46], REG_BG0CNT, 0);
            break;
        case 1:
            write_tilemap_rect(12, 2, 18, 1, gUiTilemaps[0x1F], REG_BG0CNT, 0);
            write_tilemap_rect(12, 2, 18, 5, gUiTilemaps[0x39], REG_BG0CNT, 0);
            write_tilemap_rect(12, 2, 18, 7, gUiTilemaps[0x46], REG_BG0CNT, 0);
            break;
        case 2:
            write_tilemap_rect(12, 2, 18, 1, gUiTilemaps[0x1F], REG_BG0CNT, 0);
            write_tilemap_rect(12, 2, 18, 3, gUiTilemaps[0x2C], REG_BG0CNT, 0);
            write_tilemap_rect(12, 2, 18, 7, gUiTilemaps[0x46], REG_BG0CNT, 0);
            break;
        default:
            write_tilemap_rect(12, 2, 18, 1, gUiTilemaps[0x1F], REG_BG0CNT, 0);
            write_tilemap_rect(12, 2, 18, 3, gUiTilemaps[0x2C], REG_BG0CNT, 0);
            write_tilemap_rect(12, 2, 18, 5, gUiTilemaps[0x39], REG_BG0CNT, 0);
            break;
        }
        set_tilemap_and_decompress_bg(0x15, 9, gMoneyWindowTilemap, REG_BG0CNT, 0x120);
        divide_by_10000(gGameWork.textBuf, gPlayerRecord.money);
        render_text_sprites_08040DB8(gGameWork.textBuf, 10, 0x17, 10, 5, 15, 2, 0);
        field_menu_init_cursor();
        gGameSubState = 2;
    } else {
        gGameWork.stepCounter++;
    }
}

static void field_menu_init_cursor(void) {
    lz_decompress_dispatch(gFieldMenuCursorTiles, (void *)(OBJ_VRAM0 + 0x6C00));
    DmaSet(3, gCursorArrowPalette, 0x050003C0, 0x84000008);
    gSpriteEntries[0].flags = SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[0].x = 0x88;
    gSpriteEntries[0].y = gGameWork.fieldMenuCursor * 16 + 8;
    gSpriteEntries[0].palette = 14;
    gSpriteEntries[0].frame_table = 0;
    gSpriteEntries[0].order = 0xFF;
    battle_sprite_anim_init(gBattleSpriteAnimScripts[0], 0);
}
