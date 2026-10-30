// Mode-2 state 5: the save screen. save_screen_update runs gSaveScreenStates: 0 clear, 1 graphics, 2 info panel,
// 3 fade in, 4/5 "Do you want to save your game?" (No -> 9), 13/14 "Do you wish to Overwrite?" when a save
// exists, 6 "Saving game data now.", 7 save_screen_write_save (save/save_data.c), 8 "Game data saved." /
// 12 "Failed to save.", 9-11 leave and fade out back to the field. init_linking_mode (end of the file) switches to mode
// 3 for the link scenes.
#include "global.h"
#include "constants/sprites.h"

static inline void *vram_at(u32 off) {
    return (void *)(BG_CHAR_ADDR(1) + off);
}

// Item menu state 14 (the last entry of gItemMenuStates): fade out and return to the field, which applies
// the disguise set in gFieldWork.player_form.
void item_menu_fade_out_use_item(void) {
    struct GameWork *game = &gGameWork;
    if (game->stepCounter <= 8) {
        bg_palettes_blend_masked_now(0, game->stepCounter * 4, 0xFFFF);
        obj_palettes_blend_masked_now(0, game->stepCounter * 4, 0xFFFF);
        game->stepCounter++;
    } else {
        u32 zero;
        REG_DISPCNT &= 0xFDFF;
        zero = 0;
        CpuFastSet(&zero, (void *)VRAM, 0x01006000);
        dispatch_by_index_0476e8(4);
    }
}

void save_screen_animate_sprite(u16 frame_idx) {
    gSpriteEntries[0].frame = gSaveScreenSpriteFrames[frame_idx & 3];
}

void save_screen_update(void) {
    gSaveScreenStates[gGameSubState]();
    if (gFrameCounter & 1) {
        gBg3Scroll.x++;
        gBg3Scroll.y++;
    }
    save_screen_animate_sprite(gFrameCounter >> 3);
}

void save_screen_clear(void) {
    u32 zero = 0;
    CpuFastSet(&zero, gMenuWork, 0x01000100);
    reset_bg_scroll();
    REG_DISPCNT = 0x160;
    gGameSubState++;
}

void save_screen_load_graphics(void) {
    u32 size;
    u16 bgcnt;
    vu16 *bg1, *bg2, *bg3;

    bg1 = &REG_BG1CNT;
    bgcnt = 0x1E05;
    *bg1 = bgcnt;
    bg2 = &REG_BG2CNT;
    bgcnt -= 0xFF;
    *bg2 = bgcnt;
    bg3 = &REG_BG3CNT;
    bgcnt = 0x3C07;
    *bg3 = bgcnt;
    decompress_and_write_tilemap(gSaveScreenBg1Tilemap, *bg1);
    decompress_and_write_tilemap(gSaveScreenBg2Tilemap, *bg2);
    decompress_and_write_tilemap(gSaveScreenBg3Tilemap, *bg3);
    size = dma3_copy_or_decompress(gSaveScreenBgTiles, gDecompressBuffer);
    CpuCopy16(gDecompressBuffer, vram_at(0), size);
    lz_decompress_dispatch(gMenuDigitTilesLz, vram_at(size));
    gMenuWork->bg_tile_base = (size >> 5) - 1;
    lz_decompress_dispatch(gMenuObjTilesLz, (void *)OBJ_VRAM0);
    gSpriteEntries[0].flags = SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE;
    gSpriteEntries[0].frame_table = 2;
    gSpriteEntries[0].palette = 0;
    gSpriteEntries[0].frame = 0x23;
    gSpriteEntries[0].x = 0xD0;
    gSpriteEntries[0].y = 0x18;
    gGameSubState++;
}

// The info panel: Medals and Medaparts owned, play time (h:mm), Robattles fought / won, money, player name.
// draw_number is called through a cast: this caller passes untruncated ints, the header has u8 / u16 params.
void save_screen_draw_info(void) {
    s32 n;
    s32 i;

    n = 0;
    for (i = 0; i < 30; i++) {
        if (gMedals[i].flags & 0x80)
            n++;
    }
    ((void (*)(s32, s32, s32, s32, s32, s32))draw_number)(n, 2, 10, 4, 10, BGCNT_SCREEN_BLOCK(REG_BG1CNT));
    n = 0;
    for (i = 0; i < 480; i++) {
        if (gMedapartInventory[i * 2] != 0)
            n++;
    }
    ((void (*)(s32, s32, s32, s32, s32, s32))draw_number)(n, 3, 9, 6, 11, BGCNT_SCREEN_BLOCK(REG_BG1CNT));
    n = gPlayerRecord.playTime / 3600;
    ((void (*)(s32, s32, s32, s32, s32, s32))draw_number)(n / 60, 2, 7, 8, 12, BGCNT_SCREEN_BLOCK(REG_BG1CNT));
    ((void (*)(s32, s32, s32, s32, s32, s32))draw_number)(n % 60, -2, 10, 8, 12, BGCNT_SCREEN_BLOCK(REG_BG1CNT));
    ((void (*)(s32, s32, s32, s32, s32, s32))draw_number)(gPlayerRecord.robattleCounts[1], 4, 3, 11, 13,
                                                          BGCNT_SCREEN_BLOCK(REG_BG1CNT));
    ((void (*)(s32, s32, s32, s32, s32, s32))draw_number)(gPlayerRecord.robattleCounts[0], 0, 8, 11, 13,
                                                          BGCNT_SCREEN_BLOCK(REG_BG1CNT));
    divide_by_10000(gGameWork.textBuf, gPlayerRecord.money);
    render_text_sprites_at(gGameWork.textBuf, 1, 15, 9, 7, 15, 1, 0);
    render_text_sprites_at(gPlayerRecord.name, 13, 14, 4, 10, 13, 0, 0);
    open_choice_menu(1, 0x16, 7);
    CpuFastSet(gSaveScreenBgPalettes, gPaletteBackupBg, 0x80);
    CpuFastSet(gGradientPaletteYellow, (void *)OBJ_PAL_BACKUP_ADDR(13), 8);
    CpuFastSet(gSpriteFontPalette, (void *)OBJ_PAL_BACKUP_ADDR(15), 8);
    CpuFastSet(gSaveScreenObjPalette, gPaletteBackup, 8);
    gGameWork.stepCounter = 0;
    gGameSubState++;
}

void save_screen_fade_in(void) {
    if (gGameWork.stepCounter <= 8) {
        bg_palettes_blend_masked_now(0, 32 - gGameWork.stepCounter * 4, 0x3FFF);
        obj_palettes_blend_masked_now(0, 32 - gGameWork.stepCounter * 4, 0xFFFF);
        if (++gGameWork.stepCounter == 1) {
            REG_DISPCNT |= 0x200;
            REG_DISPCNT |= 0x400;
            REG_DISPCNT |= 0x800;
            REG_DISPCNT |= 0x1000;
        }
    } else {
        text_window_init(1, 2, 0);
        gGameSubState++;
    }
}

void save_screen_ask_save(void) {
    if (run_message(gSystemMessages[9]))
        gGameSubState++;
}

void save_screen_poll_save_choice(void) {
    if (poll_choice_menu()) {
        message_next();
        if (gGameWork.choiceCursor == 0)
            gGameSubState = (*(u8 *)&gSaveStatus & 1) ? 13 : 6;
        else
            gGameSubState = 9;
    }
}

void save_screen_ask_overwrite(void) {
    if (run_message(gLinkMenuMessages[18])) {
        open_choice_menu(1, 0x16, 7);
        gGameSubState++;
    }
}

void save_screen_poll_overwrite_choice(void) {
    if (poll_choice_menu()) {
        message_next();
        if (gGameWork.choiceCursor == 0)
            gGameSubState = 6;
        else
            gGameSubState = 9;
    }
}

void save_screen_show_saving(void) {
    if (run_message(gSystemMessages[10])) {
        play_song(0);
        play_sound_effect(0);
        eeprom_setup_timer_irq();
        gMenuWork->timer = 0;
        gGameSubState++;
    }
}

void save_screen_write_save(void) {
    u8 elapsed = gMenuWork->timer++;
    u16 err = 0;
    s8 i;

    if (elapsed > 29 && !is_sound_effect_playing(4)) {
        for (i = 0; i <= 3; i++) {
            err = save_dispatch(0);
            if (err == 0)
                break;
        }
        play_song(6);
        if (err == 0) {
            message_next();
            gMenuWork->timer = err;
            gGameSubState++;
        } else {
            message_next();
            gMenuWork->timer = 0;
            gGameSubState = 12;
        }
    }
}

void save_screen_show_saved(void) {
    u8 elapsed = gMenuWork->timer++;
    if (run_message(gSystemMessages[11]) && elapsed > 60)
        gGameSubState++;
}

void save_screen_exit_begin(void) {
    message_next();
    palette_backup_from_hardware();
    gGameWork.stepCounter = 0;
    gGameSubState++;
}

void save_screen_exit_wait(void) {
    if (game_state_execute_handler_a())
        gGameSubState++;
}

void save_screen_fade_out(void) {
    if (gGameWork.stepCounter <= 8) {
        bg_palettes_blend_masked_now(0, gGameWork.stepCounter * 4, 0x3FFF);
        obj_palettes_blend_masked_now(0, gGameWork.stepCounter * 4, 0xFFFF);
        gGameWork.stepCounter++;
    } else {
        REG_DISPCNT &= 0xFDFF;
        REG_DISPCNT &= 0xFBFF;
        clear_battle_sprite_slot(0, 0x80);
        gGameMode = 0;
        gGameState = 1;
        gGameSubState = 16;
    }
}

void save_screen_show_failed(void) {
    u8 elapsed = gMenuWork->timer++;
    if (run_message(gSystemMessages[12]) && elapsed > 60)
        gGameSubState = 9;
}

void init_linking_mode(void) {
    gLinkMultiplayerActive = 0;
    serial_multiplayer_init();
    VBlankIntrWait();
    REG_BLDCNT = 0xFF;
    REG_BLDY = 0x10;
    REG_SOUNDCNT_X = 0;
    gGameMode = 3;
    gGameState = 0;
    gGameSubState = 0;
    REG_DMA0CNT_H = 0;
    VBlankIntrWait();
    sound_init(&gSoundWorkArea);
    VBlankIntrWait();
}
