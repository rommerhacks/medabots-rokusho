// Game state 2: the Medawatch menu, opened from the field menu: Medabots (game state 3), Medals (4) or
// Medaparts (5).

#include "global.h"
#include "constants/sprites.h"

static void medawatch_menu_load_icon(void);
static void medawatch_menu_init_cursor(void);
static void medawatch_scroll_bg3(void);

// Game state 2: the Medawatch menu (Medabots / Medals / Medaparts, cursor gGameWork.medawatchCursor).
void medawatch_menu_update(void) {
    gMedawatchMenuHandlers[gGameSubState]();
}

void medawatch_menu_load_gfx(void) {
    reset_bg_scroll();
    REG_DISPCNT &= 0xF1FF;
    REG_BG1CNT = 0x1805;
    REG_BG2CNT = 0x1906;
    REG_BG3CNT = 0x1A07;
    lz_decompress_dispatch(gMedawatchBgTilesLz, (void *)BG_CHAR_ADDR(1));
    medawatch_menu_load_icon();
    set_tilemap_and_decompress_bg(0, 0, gMedawatchBg1Tilemap, REG_BG1CNT, 0);
    set_tilemap_and_decompress_bg(0, 0, gMedawatchBg2Tilemap, REG_BG2CNT, 0);
    set_tilemap_and_decompress_bg(0, 0, gMedawatchBg3Tilemap, REG_BG3CNT, 0);
    DmaSet(3, gMedawatchBgPalettes, BG_PAL_BACKUP_ADDR(0), 0x84000060);
    write_tilemap_rect(4, 4, 5, 9, gUiTilemaps[0x48], REG_BG1CNT, 0);
    REG_DISPCNT |= 0x1F60;
    gGameWork.stepCounter = 0;
    gGameSubState++;
}

void medawatch_menu_fade_in(void) {
    medawatch_scroll_bg3();
    if (gGameWork.stepCounter <= 8) {
        bg_palettes_blend_masked_now(0, 32 - gGameWork.stepCounter * 4, 0x1FFF);
        obj_palettes_blend_masked_now(0, 32 - gGameWork.stepCounter * 4, 0xFFFF);
        gGameWork.stepCounter++;
    } else {
        medawatch_menu_init_cursor();
        gGameSubState++;
    }
}

void medawatch_menu_handle_input(void) {
    medawatch_scroll_bg3();
    process_sprite_anim_commands(gBattleSpriteAnimScripts[0], 0);
    if (KEYS_LO(gRepeatKeys) & DPAD_UP) {
        if (gGameWork.medawatchCursor == 0)
            gGameWork.medawatchCursor = 2;
        else
            gGameWork.medawatchCursor--;
        play_sound_effect(2);
        medawatch_menu_load_icon();
        gSpriteEntries[0].x = 0x88 - gGameWork.medawatchCursor * 8;
        gSpriteEntries[0].y = gGameWork.medawatchCursor * 24 + 32;
    }
    if (KEYS_LO(gRepeatKeys) & DPAD_DOWN) {
        if (gGameWork.medawatchCursor == 2)
            gGameWork.medawatchCursor = 0;
        else
            gGameWork.medawatchCursor++;
        play_sound_effect(2);
        medawatch_menu_load_icon();
        gSpriteEntries[0].x = 0x88 - gGameWork.medawatchCursor * 8;
        gSpriteEntries[0].y = gGameWork.medawatchCursor * 24 + 32;
    }
    if (KEYS_LO(gNewKeys) & B_BUTTON) {
        play_sound_effect(5);
        gGameSubState++;
    }
    if (KEYS_LO(gNewKeys) & A_BUTTON) {
        play_sound_effect(4);
        battle_sprite_anim_init(gBattleSpriteAnimScripts[1], 0);
        set_blend_effect_mode(6, 0x3F, 0x20);
        gGameWork.stepCounter = 0;
        gGameSubState = 8;
    }
}

void medawatch_menu_exit_start(void) {
    medawatch_scroll_bg3();
    clear_battle_sprite_slot(0, 1);
    palette_backup_from_hardware();
    gGameWork.stepCounter = 0;
    fade_out_music(8);
    gGameSubState++;
}

void medawatch_menu_exit_fade(void) {
    medawatch_scroll_bg3();
    if (gGameWork.stepCounter <= 8) {
        bg_palettes_blend_masked_now(0, gGameWork.stepCounter * 4, 0x1FFF);
        obj_palettes_blend_masked_now(0, gGameWork.stepCounter * 4, 0xFFFF);
        gGameWork.stepCounter++;
    } else {
        gGameSubState++;
    }
}

void medawatch_menu_return_to_field_menu(void) {
    play_song(6);
    gGameState = MODE0_STATE_FIELD_MENU;
    gGameSubState = 16;
}

void medawatch_menu_select_fade(void) {
    medawatch_scroll_bg3();
    process_sprite_anim_commands(gBattleSpriteAnimScripts[1], 0);
    if (update_blend_effect())
        gGameSubState++;
}

// Saves the BG tiles at 0x06002800 and enters game state 3 (Medabots), 4 (Medals) or 5 (Medaparts).
void medawatch_menu_run_choice(void) {
    DmaSet(3, BG_VRAM + 0x2800, gBgTileBackup, 0x84000200);
    switch (gGameWork.medawatchCursor) {
    case 0:
        mem_fill8((u8 *)&gGameWork + 0x50, 0x14, 0);
        gGameState = MODE0_STATE_MEDABOTS;
        gGameSubState = 0;
        break;
    case 1:
        mem_fill8((u8 *)&gGameWork + 0x3C, 0x14, 0);
        gGameState = MODE0_STATE_MEDALS;
        gGameSubState = 0;
        break;
    default:
        mem_fill8((u8 *)&gGameWork + 0x3C, 0x14, 0);
        gGameState = MODE0_STATE_MEDAPARTS;
        gGameSubState = 0;
        break;
    }
}

// Back from a Medawatch submenu: reloads the menu graphics and restores the saved BG tiles.
void medawatch_menu_return_init(void) {
    reset_bg_scroll();
    REG_DISPCNT &= 0xF0FF;
    REG_BG1CNT = 0x500;
    REG_BG1CNT = 0x1805;
    REG_BG2CNT = 0x1906;
    REG_BG3CNT = 0x1A07;
    lz_decompress_dispatch(gMedawatchBgTilesLz, (void *)BG_CHAR_ADDR(1));
    medawatch_menu_load_icon();
    DmaSet(3, gBgTileBackup, BG_VRAM + 0x2800, 0x84000200);
    set_tilemap_and_decompress_bg(0, 0, gMedawatchBg1Tilemap, REG_BG1CNT, 0);
    set_tilemap_and_decompress_bg(0, 0, gMedawatchBg2Tilemap, REG_BG2CNT, 0);
    set_tilemap_and_decompress_bg(0, 0, gMedawatchBg3Tilemap, REG_BG3CNT, 0);
    DmaSet(3, gMedawatchBgPalettes, 0x05000000, 0x84000060);
    write_tilemap_rect(4, 4, 5, 9, gUiTilemaps[0x48], REG_BG1CNT, 0);
    REG_DISPCNT |= 0x1F60;
    set_blend_effect_mode(5, 0x3F, 0x20);
    gGameWork.stepCounter = 0;
    gGameSubState++;
}

void medawatch_menu_return_fade(void) {
    medawatch_scroll_bg3();
    if (update_blend_effect()) {
        medawatch_menu_init_cursor();
        gGameSubState++;
    }
}

void medawatch_menu_return_done(void) {
    medawatch_scroll_bg3();
    gGameSubState = 2;
}

// Watch face icon for the selected entry.
static void medawatch_menu_load_icon(void) {
    const u8 *src;

    switch (gGameWork.medawatchCursor) {
    case 0:
        src = gMedawatchIconMedabotsTiles;
        break;
    case 1:
        src = gMedawatchIconMedalsTiles;
        break;
    default:
        src = gMedawatchIconMedapartsTiles;
        break;
    }
    lz_decompress_dispatch(src, (void *)(BG_VRAM + 0x7E00));
}

static void medawatch_menu_init_cursor(void) {
    lz_decompress_dispatch(gFieldMenuCursorTiles, (void *)(OBJ_VRAM0 + 0x6C00));
    DmaSet(3, gCursorArrowPalette, 0x050003C0, 0x84000008);
    gSpriteEntries[0].flags = SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[0].x = 0x88 - gGameWork.medawatchCursor * 8;
    gSpriteEntries[0].y = gGameWork.medawatchCursor * 24 + 32;
    gSpriteEntries[0].palette = 14;
    gSpriteEntries[0].frame_table = 0;
    gSpriteEntries[0].order = 0xFF;
    battle_sprite_anim_init(gBattleSpriteAnimScripts[0], 0);
}

// Scrolls the background pattern diagonally every other frame.
static void medawatch_scroll_bg3(void) {
    if (gFrameCounter & 1) {
        gBg3Scroll.x--;
        gBg3Scroll.y++;
    }
}
