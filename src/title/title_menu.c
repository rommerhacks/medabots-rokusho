// Mode 2 (title side): menu_mode_update runs gMenuModeStates[gGameState], and state 3 is
// the title menu (title_menu_update runs the sub-states at gTitleMenuStates: load graphics, New Game / Continue /
// options input, the options menu, loading the save through save/save_data.c). Leaves to the field (mode 1),
// the new-game prompt (state 28) or mode 0.
// Rows: 0 Continue (hidden when there is no save: unk4 = first selectable row), 1 New Game, 2 Options.
// Options rows: gOptionTimeLimit, gOptionSkipMessages, gOptionBattleMusic (saved in SaveData.flags).
#include "global.h"

void menu_mode_update(void) {
    gUnk_03005010.unk4 = gHeldKeys;
    gUnk_03005010.unk6 = 0;
    gMenuWork = (struct MenuWork *)&gBattleWork;
    if (gUnk_03005030 != 0 && (*(u32 *)&gUnk_03005010.unk19[3] & 0x00FFFF00)) {
        gGameMode = 0;
        gGameState = 10;
        gGameSubState = 0x10;
    } else {
        gMenuModeStates[gGameState]();
    }
}

s16 title_menu_blend_step(s16 step) {
    u16 a = step;
    s16 n;

    if (a > 0xA0)
        a = 0;
    REG_BLDCNT = 0x844;
    n = a;
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
            u16 *p = (u16 *)(VRAM + (((REG_BG0CNT >> 8) & 0x1F) << 11)) + x + y * 32;
            u16 v = *p & mask;
            u16 c;
            if (sel == i && j < count)
                c = 0x7000;
            else
                c = lo;
            *p = v | c;
            if (j <= 1)
                y++;
            else
                x++;
        }
    }
}

static void title_options_highlight_row(u8 sel) {
    s32 i, j;
    u16 *p;
    u32 v, r;

    for (i = 0; i <= 2; i++) {
        p = (u16 *)(VRAM + (((REG_BG0CNT >> 8) & 0x1F) << 11)) + 7 + (i * 3 + 10) * 32;
        for (j = 0; j <= 10; j++) {
            v = *p;
            v &= 0xFFF;
            if (i == sel)
                r = 0x7000 | v;
            else {
                v |= 0x6000;
                r = v << 16;
                r >>= 16;
            }
            *p = r;
            p++;
        }
    }
}

static void title_options_dim_values(void) {
    s32 i, j;
    for (i = 0; i <= 2; i++) {
        u16 *p = (u16 *)(VRAM + (((REG_BG0CNT >> 8) & 0x1F) << 11)) + 0x167 + i * 96;
        for (j = 0; j < 16; j++) {
            *p = (*p & 0xFFF) | 0x8000;
            p++;
        }
    }
}

void title_options_draw_values(u8 sel) {
    u8 cur[3] = {gOptionTimeLimit, gOptionSkipMessages, gOptionBattleMusic};
    s32 i, j, k;
    for (i = 0; i <= 2; i++) {
        for (j = 0; j <= 2; j++) {
            u16 *p = (u16 *)(VRAM + 0xE + (((REG_BG0CNT >> 8) & 0x1F) << 11) + (i * 3 + 11) * 64);
            u16 mask = gTitleOptionValueMasks[i][j];
            for (k = 0; k < 16; k++) {
                if (mask & 0x8000) {
                    u16 v = *p & 0xFFF;
                    if (sel == i)
                        *p = v | (cur[i] == j ? 0xA000 : 0x8000);
                    else
                        *p = v | (cur[i] == j ? 0x9000 : 0x8000);
                }
                mask <<= 1;
                p++;
            }
        }
    }
}

static void title_options_pulse_palette(u8 step) {
    u16 buf[32];
    s32 i;
    step = step > 15 ? step - 16 : 0;
    CpuSet((void *)0x0202FB00, buf, 0x04000010);
    for (i = 0; i < 16; i++) {
        u16 c = buf[i];
        u16 t = buf[i + 16];
        s32 r = c & 0x1F;
        s32 g = (c >> 5) & 0x1F;
        s32 b = (c >> 10) & 0x1F;
        s32 r2 = t & 0x1F;
        s32 g2 = (t >> 5) & 0x1F;
        s32 b2 = (t >> 10) & 0x1F;
        r = (r - r2) * step / 32 + r2;
        g = (g - g2) * step / 32 + g2;
        b = (b - b2) * step / 32 + b2;
        buf[i] = (b << 10) | (g << 5) | r;
    }
    CpuSet(buf, (void *)0x05000140, 0x04000008);
}

static void title_menu_pulse_selected(u8 sel, u8 blend) {
    u16 buf[32];
    s32 i, j;
    for (j = 0; j <= 2; j++) {
        CpuSet((void *)(j * 0x40 + 0x0202FA00), buf, 0x04000010);
        if (j == sel) {
            for (i = 0; i < 16; i++) {
                u16 c = buf[i];
                u16 t = buf[i + 16];
                s32 r = c & 0x1F;
                s32 g = (c >> 5) & 0x1F;
                s32 b = (c >> 10) & 0x1F;
                s32 r2 = t & 0x1F;
                s32 g2 = (t >> 5) & 0x1F;
                s32 b2 = (t >> 10) & 0x1F;
                r = (r - r2) * blend / 32 + r2;
                g = (g - g2) * blend / 32 + g2;
                b = (b - b2) * blend / 32 + b2;
                buf[i] = (b << 10) | (g << 5) | r;
            }
        }
        CpuSet(buf, (void *)(j * 0x40 + PLTT), 0x04000008);
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
    init_blend_effect(gMenuWork->unk50, 0x10, 0, -1, 0xC0);
    gGameSubState++;
}

void title_menu_load_graphics(void) {
    u32 size;
    u16 v;
    vu16 *bg0, *bg1, *bg2, *bg3;
    u8 one;

    bg0 = &REG_BG0CNT;
    one = 1;
    v = 0x1F04;
    *bg0 = v;
    bg1 = &REG_BG1CNT;
    v -= 0xFF;
    *bg1 = v;
    bg2 = &REG_BG2CNT;
    v = 0x3D06;
    *bg2 = v;
    bg3 = &REG_BG3CNT;
    v -= 0xFF;
    *bg3 = v;
    decompress_and_write_tilemap(gUnk_0878FBB4, *bg0);
    decompress_and_write_tilemap(gUnk_0878FD84, *bg1);
    decompress_and_write_tilemap(gUnk_0878FFC8, *bg2);
    decompress_and_write_tilemap(gUnk_08790128, *bg3);
    size = dma3_copy_or_decompress(gUnk_0878E5F4, gDecompressBuffer);
    CpuCopy16(gDecompressBuffer, (void *)0x06004000, size);
    gMenuWork->unk36 = (size >> 5) - 1;
    lz_decompress_dispatch(gUnk_08784DA4, (void *)0x06010000);
    CpuFastSet(gUnk_0878E3F4, gPaletteBackupBg, 0x80);
    CpuFastSet(gUnk_0878E3F4, (void *)PLTT, 0x80);
    CpuFastSet(gCursorArrowPalette, gPaletteBackup, 0x80);
    CpuFastSet(gCursorArrowPalette, (void *)(PLTT + 0x200), 0x80);
    gSpriteEntries[14].unk0 = 0x8000;
    gSpriteEntries[14].unkB = one;
    gSpriteEntries[14].unk1C = 2;
    gSpriteEntries[14].unkA = 0;
    gSpriteEntries[14].unk6 = 6;
    gSpriteEntries[14].unk2 = 0x20;
    gSpriteEntries[14].unk4 = 0x50;
    gMenuWork->unk5 = 0;
    gGameSubState++;
}

void title_menu_load_save(void) {
    s32 ret, i, j;
    u16 *p;

    REG_DISPCNT |= 0x100;
    REG_DISPCNT |= 0x200;
    REG_DISPCNT |= 0x800;
    REG_DISPCNT |= 0x1000;
    gUnk_03001784.unk0_0 = 0;
    ret = load_save_with_retries();
    if (ret != 0) {
        if (ret < 0) {
            gGameState = 9;
            gGameSubState = 0;
            return;
        }
        for (i = 0; i <= 1; i++) {
            p = (u16 *)(VRAM + (((REG_BG0CNT >> 8) & 0x1F) << 11)) + 9 + (i + 1) * 32;
            for (j = 0; j < 12; j++)
                *p++ = 0;
        }
        gMenuWork->unk5 = 1;
        gMenuWork->unk4 = 1;
        gOptionTimeLimit = 0;
        gOptionSkipMessages = 0;
        gOptionBattleMusic = 0;
    } else {
        gMenuWork->unk5 = ret;
        gMenuWork->unk4 = ret;
        gUnk_03001784.unk0_0 = 1;
    }
    title_menu_pulse_selected(gMenuWork->unk5, gFrameCounter & 0x1F);
    title_options_draw_values(3);
    gGameSubState++;
}

void title_menu_fade_in(void) {
    if (blend_fade_step_08065598(gMenuWork->unk50)) {
        gGameSubState++;
        gMenuWork->unk3A = 0;
        gMenuWork->unk3A = title_menu_blend_step(0);
        REG_DISPCNT |= 0x400;
    }
}

void title_menu_input(void) {
    struct MenuWork *w;

    gMenuWork->unk3A = title_menu_blend_step(gMenuWork->unk3A);
    title_menu_pulse_selected(gMenuWork->unk5, gFrameCounter & 0x1F);
    if (KEYS_LO(gNewKeys) & 0x40) {
        play_sound_effect(2);
        w = gMenuWork;
        if (w->unk5 == w->unk4)
            w->unk5 = 2;
        else
            w->unk5--;
    }
    if (KEYS_LO(gNewKeys) & 0x80) {
        play_sound_effect(2);
        w = gMenuWork;
        if (w->unk5 == 2)
            w->unk5 = w->unk4;
        else
            w->unk5++;
    }
    if (KEYS_LO(gNewKeys) & 1) {
        play_sound_effect(4);
        if (gMenuWork->unk5 == 2) {
            gMenuWork->unk5 = 0;
            gMenuWork->unk2 = 20;
            title_options_pulse_palette(gFrameCounter & 0x1F);
            title_options_highlight_row(gMenuWork->unk5);
            title_options_draw_values(gMenuWork->unk5);
            title_menu_pulse_selected(3, 0);
            gSpriteEntries[14].unk4 = gMenuWork->unk5 * 24 + 0x50;
            gSpriteEntries[14].unk0 |= 0x4000;
            gGameSubState++;
        } else {
            gMenuWork->unk48 = 45;
            gGameSubState = 6;
        }
    }
}

// guess: title options menu input (rows: Robattle time limit gOptionTimeLimit, message skip gOptionSkipMessages,
// battle music gOptionBattleMusic with a preview); A / B leave the menu
void title_options_input(void) {
    gMenuWork->unk3A = title_menu_blend_step(gMenuWork->unk3A);
    sprite_bob_y(14, gFrameCounter, 32);
    title_options_pulse_palette(gFrameCounter & 0x1F);
    title_options_draw_row_sweep(gMenuWork->unk5, 20 - gMenuWork->unk2);
    if (gMenuWork->unk2)
        gMenuWork->unk2--;

    if (KEYS_LO(gNewKeys) & 0x40) {
        play_song(1);
        play_sound_effect(2);
        if (gMenuWork->unk5 == 0)
            gMenuWork->unk5 = 2;
        else
            gMenuWork->unk5--;
        if (gMenuWork->unk5 == 2)
            play_song(gBattleMusicOptionSongs[gOptionBattleMusic]);
        gMenuWork->unk2 = 20;
    } else if (KEYS_LO(gNewKeys) & 0x80) {
        play_song(1);
        play_sound_effect(2);
        if (gMenuWork->unk5 == 2)
            gMenuWork->unk5 = 0;
        else
            gMenuWork->unk5++;
        if (gMenuWork->unk5 == 2)
            play_song(gBattleMusicOptionSongs[gOptionBattleMusic]);
        gMenuWork->unk2 = 20;
    } else {
        switch (gMenuWork->unk5) {
        case 0:
            if (KEYS_LO(gNewKeys) & 0x20) {
                play_sound_effect(2);
                if (gOptionTimeLimit == 0)
                    gOptionTimeLimit = 2;
                else
                    gOptionTimeLimit--;
            }
            if (KEYS_LO(gNewKeys) & 0x10) {
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
            if (KEYS_LO(gNewKeys) & 0x20) {
                if (gOptionBattleMusic == 0)
                    gOptionBattleMusic = 2;
                else
                    gOptionBattleMusic--;
                play_song(gBattleMusicOptionSongs[gOptionBattleMusic]);
            }
            if (KEYS_LO(gNewKeys) & 0x10) {
                if (gOptionBattleMusic == 2)
                    gOptionBattleMusic = 0;
                else
                    gOptionBattleMusic++;
                play_song(gBattleMusicOptionSongs[gOptionBattleMusic]);
            }
            break;
        }
        if (KEYS_LO(gNewKeys) & 0x30)
            title_options_draw_values(gMenuWork->unk5);
        if (KEY_BITS(gNewKeys).a | KEY_BITS(gNewKeys).b) {
            play_song(1);
            play_sound_effect(4);
            gMenuWork->unk5 = 2;
            gSpriteEntries[14].unk0 &= 0xBFFF;
            gGameSubState--;
            title_options_highlight_row(3);
            title_options_draw_row_sweep(3, 0);
            title_options_draw_values(3);
        }
        return;
    }
    title_options_highlight_row(gMenuWork->unk5);
    title_options_draw_values(gMenuWork->unk5);
    gSpriteEntries[14].unk2 = 32;
    gSpriteEntries[14].unk4 = gMenuWork->unk5 * 24 + 0x50;
}

void title_menu_confirm_flash(void) {
    u8 *t = &gMenuWork->unk48;
    if (*t) {
        u8 n = --*t;
        if (n)
            title_menu_pulse_selected(gMenuWork->unk5, ((gMenuWork->unk48 * 4) & 0x1F) <= 15 ? 0x20 : 0);
        else {
            palette_backup_from_hardware();
            gGameWork.unk84 = n;
        }
    } else if (!is_sound_effect_playing(4)) {
        struct GameWork *b = &gGameWork;
        if (b->unk84 <= 8) {
            s32 w = 31;
            s32 c = (w << 10) | (w << 5) | w;
            bg_palettes_blend_masked_now(c, b->unk84 * 4, 0xFFFF);
            obj_palettes_blend_masked_now(c, b->unk84 * 4, 0xFFFF);
            b->unk84++;
        } else {
            REG_DISPCNT &= 0xFDFF;
            switch (gMenuWork->unk5) {
            case 0:
                gUnk_03001784.unk0_0 = 1;
                gGameSubState = 8;
                break;
            case 1:
                gUnk_03001784.unk0_1 = 0;
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
    if (gMenuWork->unk0 != 32) {
        gMenuWork->unk0++;
        REG_BLDY = gMenuWork->unk0 >> 1;
    } else {
        gGameState = 9;
        gGameSubState = 0;
    }
}
