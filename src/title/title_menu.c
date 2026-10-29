// Mode 2 (title side): menu_mode_update runs gMenuModeStates[gGameState], and state 3 is
// the title menu (title_menu_update runs the sub-states at gTitleMenuStates: load graphics, New Game / Continue /
// options input, the options menu, loading the save through save/save_data.c). Leaves to the field (mode 1),
// the new-game prompt (state 28) or mode 0.
// Rows: 0 Continue (hidden when there is no save: first_entry = first selectable row), 1 New Game, 2 Options.
// Options rows: gOptionTimeLimit, gOptionSkipMessages, gOptionBattleMusic (saved in SaveData.flags).
#include "global.h"
#include "constants/sprites.h"

void menu_mode_update(void) {
    gLinkPackets.sendKeys = gHeldKeys;
    gLinkPackets.sendData = 0;
    gMenuWork = (struct MenuWork *)&gBattleWork;
    if (gLinkMultiplayerActive != 0 && (*(u32 *)&gLinkPackets.recvTimeouts[3] & 0x00FFFF00)) {
        gGameMode = 0;
        gGameState = 10;
        gGameSubState = 0x10;
    } else {
        gMenuModeStates[gGameState]();
    }
}

s16 title_menu_blend_step(s16 step) {
    u16 clamped = step;
    s16 n;

    if (clamped > 0xA0)
        clamped = 0;
    REG_BLDCNT = 0x844;
    n = clamped;
    REG_BLDALPHA = gTitleMenuBlendAlphas[n / 8] | 0x1000;
    REG_BLDY = 8;
    return n + 1;
}

static void title_options_draw_row_sweep(u8 sel, u8 count) {
    s32 i, j, x, y;
    s32 mask, lo;
    for (i = 0, mask = 0xFFF, lo = 0x6000; i <= 2; i++) {
        x = 6;
        y = i * 3 + 10;
        for (j = 0; j <= 19; j++) {
            u16 *tile = BG_TILEMAP(REG_BG0CNT) + x + y * 32;
            u16 tile_bits = *tile & mask;
            u16 palette_bits;
            if (sel == i && j < count)
                palette_bits = 0x7000;
            else
                palette_bits = lo;
            *tile = tile_bits | palette_bits;
            if (j <= 1)
                y++;
            else
                x++;
        }
    }
}

static void title_options_highlight_row(u8 sel) {
    s32 i, j;
    u16 *tile;
    u32 tile_bits, result;

    for (i = 0; i <= 2; i++) {
        tile = BG_TILEMAP(REG_BG0CNT) + 7 + (i * 3 + 10) * 32;
        for (j = 0; j <= 10; j++) {
            tile_bits = *tile;
            tile_bits &= 0xFFF;
            if (i == sel)
                result = 0x7000 | tile_bits;
            else {
                tile_bits |= 0x6000;
                result = tile_bits << 16;
                result >>= 16;
            }
            *tile = result;
            tile++;
        }
    }
}

static void title_options_dim_values(void) {
    s32 i, j;
    for (i = 0; i <= 2; i++) {
        u16 *tile = BG_TILEMAP(REG_BG0CNT) + 0x167 + i * 96;
        for (j = 0; j < 16; j++) {
            *tile = (*tile & 0xFFF) | 0x8000;
            tile++;
        }
    }
}

void title_options_draw_values(u8 sel) {
    u8 cur[3] = {gOptionTimeLimit, gOptionSkipMessages, gOptionBattleMusic};
    s32 i, j, k;
    for (i = 0; i <= 2; i++) {
        for (j = 0; j <= 2; j++) {
            u16 *tile = (u16 *)(VRAM + 0xE + BGCNT_SCREEN_OFFSET(REG_BG0CNT) + (i * 3 + 11) * 64);
            u16 mask = gTitleOptionValueMasks[i][j];
            for (k = 0; k < 16; k++) {
                if (mask & 0x8000) {
                    u16 tile_bits = *tile & 0xFFF;
                    if (sel == i)
                        *tile = tile_bits | (cur[i] == j ? 0xA000 : 0x8000);
                    else
                        *tile = tile_bits | (cur[i] == j ? 0x9000 : 0x8000);
                }
                mask <<= 1;
                tile++;
            }
        }
    }
}

static void title_options_pulse_palette(u8 step) {
    u16 buf[32];
    s32 i;
    step = step > 15 ? step - 16 : 0;
    CpuSet((void *)0x0202FB00, buf, CPU_SET_32BIT | 0x10);
    for (i = 0; i < 16; i++) {
        u16 color = buf[i];
        u16 target = buf[i + 16];
        s32 red = color & 0x1F;
        s32 green = (color >> 5) & 0x1F;
        s32 blue = (color >> 10) & 0x1F;
        s32 target_red = target & 0x1F;
        s32 target_green = (target >> 5) & 0x1F;
        s32 target_blue = (target >> 10) & 0x1F;
        red = (red - target_red) * step / 32 + target_red;
        green = (green - target_green) * step / 32 + target_green;
        blue = (blue - target_blue) * step / 32 + target_blue;
        buf[i] = (blue << 10) | (green << 5) | red;
    }
    CpuSet(buf, (void *)(PLTT + 0x140), CPU_SET_32BIT | 0x8);
}

static void title_menu_pulse_selected(u8 sel, u8 blend) {
    u16 buf[32];
    s32 i, j;
    for (j = 0; j <= 2; j++) {
        CpuSet((void *)(j * 0x40 + 0x0202FA00), buf, CPU_SET_32BIT | 0x10);
        if (j == sel) {
            for (i = 0; i < 16; i++) {
                u16 color = buf[i];
                u16 target = buf[i + 16];
                s32 red = color & 0x1F;
                s32 green = (color >> 5) & 0x1F;
                s32 blue = (color >> 10) & 0x1F;
                s32 target_red = target & 0x1F;
                s32 target_green = (target >> 5) & 0x1F;
                s32 target_blue = (target >> 10) & 0x1F;
                red = (red - target_red) * blend / 32 + target_red;
                green = (green - target_green) * blend / 32 + target_green;
                blue = (blue - target_blue) * blend / 32 + target_blue;
                buf[i] = (blue << 10) | (green << 5) | red;
            }
        }
        CpuSet(buf, (void *)(j * 0x40 + PLTT), CPU_SET_32BIT | 0x8);
    }
}

void title_menu_update(void) {
    gTitleMenuStates[gGameSubState]();
    gBg2Scroll.x++;
    gBg2Scroll.y++;
    if (gFrameCounter & 1) {
        gBg3Scroll.x++;
        gBg3Scroll.y++;
    }
}

void title_menu_reset(void) {
    u32 zero = 0;
    CpuFastSet(&zero, (void *)VRAM, 0x01006000);
    reset_bg_scroll();
    free_all_sprites();
    REG_DISPCNT = 0x60;
    init_blend_effect(gMenuWork->blend, 0x10, 0, -1, 0xC0);
    gGameSubState++;
}

void title_menu_load_graphics(void) {
    u32 size;
    u16 bgcnt;
    vu16 *bg0, *bg1, *bg2, *bg3;
    u8 one;

    bg0 = &REG_BG0CNT;
    one = 1;
    bgcnt = 0x1F04;
    *bg0 = bgcnt;
    bg1 = &REG_BG1CNT;
    bgcnt -= 0xFF;
    *bg1 = bgcnt;
    bg2 = &REG_BG2CNT;
    bgcnt = 0x3D06;
    *bg2 = bgcnt;
    bg3 = &REG_BG3CNT;
    bgcnt -= 0xFF;
    *bg3 = bgcnt;
    decompress_and_write_tilemap(gTitleMenuBg0Tilemap, *bg0);
    decompress_and_write_tilemap(gTitleMenuBg1Tilemap, *bg1);
    decompress_and_write_tilemap(gTitleMenuBg2Tilemap, *bg2);
    decompress_and_write_tilemap(gTitleMenuBg3Tilemap, *bg3);
    size = dma3_copy_or_decompress(gTitleMenuBgTiles, gDecompressBuffer);
    CpuCopy16(gDecompressBuffer, (void *)BG_CHAR_ADDR(1), size);
    gMenuWork->bg_tile_base = (size >> 5) - 1;
    lz_decompress_dispatch(gMenuObjTilesLz, (void *)OBJ_VRAM0);
    CpuFastSet(gTitleMenuBgPalette, gPaletteBackupBg, 0x80);
    CpuFastSet(gTitleMenuBgPalette, (void *)PLTT, 0x80);
    CpuFastSet(gCursorArrowPalette, gPaletteBackup, 0x80);
    CpuFastSet(gCursorArrowPalette, (void *)(PLTT + 0x200), 0x80);
    gSpriteEntries[14].flags = SPRITE_FLAG_ENABLED;
    gSpriteEntries[14].order = one;
    gSpriteEntries[14].frame_table = 2;
    gSpriteEntries[14].palette = 0;
    gSpriteEntries[14].frame = 6;
    gSpriteEntries[14].x = 0x20;
    gSpriteEntries[14].y = 0x50;
    gMenuWork->cursor = 0;
    gGameSubState++;
}

void title_menu_load_save(void) {
    s32 ret, i, j;
    u16 *tile;

    REG_DISPCNT |= 0x100;
    REG_DISPCNT |= 0x200;
    REG_DISPCNT |= 0x800;
    REG_DISPCNT |= 0x1000;
    gSaveStatus.saveExists = 0;
    ret = load_save_with_retries();
    if (ret != 0) {
        if (ret < 0) {
            gGameState = 9;
            gGameSubState = 0;
            return;
        }
        for (i = 0; i <= 1; i++) {
            tile = BG_TILEMAP(REG_BG0CNT) + 9 + (i + 1) * 32;
            for (j = 0; j < 12; j++)
                *tile++ = 0;
        }
        gMenuWork->cursor = 1;
        gMenuWork->first_entry = 1;
        gOptionTimeLimit = 0;
        gOptionSkipMessages = 0;
        gOptionBattleMusic = 0;
    } else {
        gMenuWork->cursor = ret;
        gMenuWork->first_entry = ret;
        gSaveStatus.saveExists = 1;
    }
    title_menu_pulse_selected(gMenuWork->cursor, gFrameCounter & 0x1F);
    title_options_draw_values(3);
    gGameSubState++;
}

void title_menu_fade_in(void) {
    if (blend_fade_step_08065598(gMenuWork->blend)) {
        gGameSubState++;
        gMenuWork->frame = 0;
        gMenuWork->frame = title_menu_blend_step(0);
        REG_DISPCNT |= 0x400;
    }
}

void title_menu_input(void) {
    struct MenuWork *w;

    gMenuWork->frame = title_menu_blend_step(gMenuWork->frame);
    title_menu_pulse_selected(gMenuWork->cursor, gFrameCounter & 0x1F);
    if (KEYS_LO(gNewKeys) & DPAD_UP) {
        play_sound_effect(2);
        w = gMenuWork;
        if (w->cursor == w->first_entry)
            w->cursor = 2;
        else
            w->cursor--;
    }
    if (KEYS_LO(gNewKeys) & DPAD_DOWN) {
        play_sound_effect(2);
        w = gMenuWork;
        if (w->cursor == 2)
            w->cursor = w->first_entry;
        else
            w->cursor++;
    }
    if (KEYS_LO(gNewKeys) & A_BUTTON) {
        play_sound_effect(4);
        if (gMenuWork->cursor == 2) {
            gMenuWork->cursor = 0;
            gMenuWork->timer = 20;
            title_options_pulse_palette(gFrameCounter & 0x1F);
            title_options_highlight_row(gMenuWork->cursor);
            title_options_draw_values(gMenuWork->cursor);
            title_menu_pulse_selected(3, 0);
            gSpriteEntries[14].y = gMenuWork->cursor * 24 + 0x50;
            gSpriteEntries[14].flags |= SPRITE_FLAG_VISIBLE;
            gGameSubState++;
        } else {
            gMenuWork->counter = 45;
            gGameSubState = 6;
        }
    }
}

// guess: title options menu input (rows: Robattle time limit gOptionTimeLimit, message skip gOptionSkipMessages,
// battle music gOptionBattleMusic with a preview); A / B leave the menu
void title_options_input(void) {
    gMenuWork->frame = title_menu_blend_step(gMenuWork->frame);
    sprite_bob_x(14, gFrameCounter, 32);
    title_options_pulse_palette(gFrameCounter & 0x1F);
    title_options_draw_row_sweep(gMenuWork->cursor, 20 - gMenuWork->timer);
    if (gMenuWork->timer)
        gMenuWork->timer--;

    if (KEYS_LO(gNewKeys) & DPAD_UP) {
        play_song(1);
        play_sound_effect(2);
        if (gMenuWork->cursor == 0)
            gMenuWork->cursor = 2;
        else
            gMenuWork->cursor--;
        if (gMenuWork->cursor == 2)
            play_song(gBattleMusicOptionSongs[gOptionBattleMusic]);
        gMenuWork->timer = 20;
    } else if (KEYS_LO(gNewKeys) & DPAD_DOWN) {
        play_song(1);
        play_sound_effect(2);
        if (gMenuWork->cursor == 2)
            gMenuWork->cursor = 0;
        else
            gMenuWork->cursor++;
        if (gMenuWork->cursor == 2)
            play_song(gBattleMusicOptionSongs[gOptionBattleMusic]);
        gMenuWork->timer = 20;
    } else {
        switch (gMenuWork->cursor) {
        case 0:
            if (KEYS_LO(gNewKeys) & DPAD_LEFT) {
                play_sound_effect(2);
                if (gOptionTimeLimit == 0)
                    gOptionTimeLimit = 2;
                else
                    gOptionTimeLimit--;
            }
            if (KEYS_LO(gNewKeys) & DPAD_RIGHT) {
                play_sound_effect(2);
                if (gOptionTimeLimit == 2)
                    gOptionTimeLimit = 0;
                else
                    gOptionTimeLimit++;
            }
            break;
        case 1:
            if (KEY_BITS(gNewKeys).left | KEY_BITS(gNewKeys).right) {
                play_sound_effect(2);
                gOptionSkipMessages ^= 1;
            }
            break;
        case 2:
            if (KEYS_LO(gNewKeys) & DPAD_LEFT) {
                if (gOptionBattleMusic == 0)
                    gOptionBattleMusic = 2;
                else
                    gOptionBattleMusic--;
                play_song(gBattleMusicOptionSongs[gOptionBattleMusic]);
            }
            if (KEYS_LO(gNewKeys) & DPAD_RIGHT) {
                if (gOptionBattleMusic == 2)
                    gOptionBattleMusic = 0;
                else
                    gOptionBattleMusic++;
                play_song(gBattleMusicOptionSongs[gOptionBattleMusic]);
            }
            break;
        }
        if (KEYS_LO(gNewKeys) & (DPAD_RIGHT | DPAD_LEFT))
            title_options_draw_values(gMenuWork->cursor);
        if (KEY_BITS(gNewKeys).a | KEY_BITS(gNewKeys).b) {
            play_song(1);
            play_sound_effect(4);
            gMenuWork->cursor = 2;
            gSpriteEntries[14].flags &= (u16)~SPRITE_FLAG_VISIBLE;
            gGameSubState--;
            title_options_highlight_row(3);
            title_options_draw_row_sweep(3, 0);
            title_options_draw_values(3);
        }
        return;
    }
    title_options_highlight_row(gMenuWork->cursor);
    title_options_draw_values(gMenuWork->cursor);
    gSpriteEntries[14].x = 32;
    gSpriteEntries[14].y = gMenuWork->cursor * 24 + 0x50;
}

void title_menu_confirm_flash(void) {
    u8 *counter_ptr = &gMenuWork->counter;
    if (*counter_ptr) {
        u8 remaining = --*counter_ptr;
        if (remaining)
            title_menu_pulse_selected(gMenuWork->cursor, ((gMenuWork->counter * 4) & 0x1F) <= 15 ? 0x20 : 0);
        else {
            palette_backup_from_hardware();
            gGameWork.stepCounter = remaining;
        }
    } else if (!is_sound_effect_playing(4)) {
        struct GameWork *work = &gGameWork;
        if (work->stepCounter <= 8) {
            s32 w = 31;
            s32 white = (w << 10) | (w << 5) | w;
            bg_palettes_blend_masked_now(white, work->stepCounter * 4, 0xFFFF);
            obj_palettes_blend_masked_now(white, work->stepCounter * 4, 0xFFFF);
            work->stepCounter++;
        } else {
            REG_DISPCNT &= 0xFDFF;
            switch (gMenuWork->cursor) {
            case 0:
                gSaveStatus.saveExists = 1;
                gGameSubState = 8;
                break;
            case 1:
                gSaveStatus.linkIntroSeen = 0;
                gGameSubState = 7;
                break;
            }
        }
    }
}

void title_menu_start_new_game(void) {
    s8 i;

    play_song(0);
    play_sound_effect(0);
    eeprom_setup_timer_irq();
    for (i = 0; i <= 15; i++)
        gPlayerName[i] = 0xFE;
    gGameState = 28;
    gGameSubState = 0;
}

void title_menu_continue_game(void) {
    u32 zero = 0;

    play_song(0);
    play_sound_effect(0);
    gGameMode = 1;
    gGameState = 1;
    gGameSubState = zero;
    dispatch_by_index_0476e8(11);
}

void title_menu_fade_to_save_lost(void) {
    if (gMenuWork->fade_level != 32) {
        gMenuWork->fade_level++;
        REG_BLDY = gMenuWork->fade_level >> 1;
    } else {
        gGameState = 9;
        gGameSubState = 0;
    }
}
