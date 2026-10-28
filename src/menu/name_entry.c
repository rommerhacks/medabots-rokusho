// Mode-2 state 0x12: name entry (the player's name, a new Medal's name, or renaming a Medal: gNameEntryMode).
// name_entry_screen_update runs gNameEntryStates: 0 clear, 1 graphics, 2 load the current / default name,
// 3 fade in, 4 letter grid input (name_entry_input), 5 wait for the sound, 6 fade out and store the name.
// calc_text_pixel_width centres the name. Uses text/ and engine/.
#include "global.h"

void name_entry_animate_sprite(u16 a) {
    gSpriteEntries[20].frame = gNameEntrySpriteFrames[a & 3];
}

static s32 calc_text_pixel_width(const u8 *s) {
    s32 w = 0;
    s32 i;
    for (i = 0; i < 10 && *s != 0xFE; i++)
        w += gFontWidths[*s++][0];
    return w;
}

static inline u32 ato(u32 s, u32 c) {
    return (s << 11) + c * 2;
}

static void name_entry_draw_name_tiles(const u8 *s) {
    u16 *top;
    u16 *bot;
    s32 i;
    u8 c, col, row;
    u32 scr;

    top = (u16 *)(VRAM + (((REG_BG1CNT >> 8) & 0x1F) << 11)) + 0x65;
    bot = (u16 *)(VRAM + (((REG_BG1CNT >> 8) & 0x1F) << 11)) + 0x85;
    for (i = 0; i < 10; i++) {
        if (*s != 0) {
            c = *s - 1;
            scr = (REG_BG1CNT >> 8) & 0x1F;
            col = c % 26;
            row = c / 26;
            *top++ = *((u16 *)(VRAM + 0x204) + ((ato(scr, col) + row * 192) >> 1));
            *bot++ = *((u16 *)(VRAM + 0x244) + ((ato((REG_BG1CNT >> 8) & 0x1F, col) + row * 192) >> 1));
        } else {
            *top++ = 0;
            *bot++ = 0;
        }
        s++;
    }
}

void name_entry_screen_update(void) {
    gNameEntryStates[gGameSubState]();
    if (gFrameCounter & 1) {
        gBg3Scroll.x++;
        gBg3Scroll.y++;
    }
    name_entry_animate_sprite(gFrameCounter >> 3);
}

void name_entry_clear(void) {
    clear_battle_sprite_slot(0, 0x80);
    reset_bg_scroll();
    REG_DISPCNT = 0x60;
    gGameSubState++;
}

// Inline helpers keep agbcc from refolding the sums (see CONTRIBUTING: mul9/sub8) and make it
// reload 0x06004000 instead of keeping it in a callee-saved register.
static inline s32 half8(s32 v) {
    return v / 2 - 0x50;
}
static inline s32 half4(s32 v) {
    return v / 2 + 0x40;
}
static inline s32 mul16(u8 v) {
    return v * 16;
}
static inline void *vram_at2(u32 off) {
    return (void *)(0x06004000 + off);
}

// First step of the name-entry screen (runs once as it opens): BG1-3 tilemaps, tiles, palettes, the letter
// and cursor sprites.
void name_entry_init_graphics(void) {
    u32 size;
    u16 v;
    vu16 *bg1;
    vu16 *bg2;
    vu16 *bg3;
    u32 zero;
    u32 zero2;
    vu16 **pbg2;
    u8 i;
    u16 t;
    u32 base;
    u16 *d;
    u16 *map;
    s32 y;
    bg1 = &REG_BG1CNT;
    v = 0x1F05;
    *bg1 = v;
    bg2 = &REG_BG2CNT;
    v -= 0xFF;
    pbg2 = &bg2;
    *(*pbg2) = v;
    bg3 = &REG_BG3CNT;
    v -= 0xFF;
    *bg3 = v;
    decompress_and_write_tilemap(gNameEntryBg1Tilemap, *bg1);
    decompress_and_write_tilemap(gNameEntryBg2Tilemap, *(*pbg2));
    decompress_and_write_tilemap(gNameEntryBg3Tilemap, *bg3);
    size = dma3_copy_or_decompress(gNameEntryBgTiles, gDecompressBuffer);
    CpuSet(gDecompressBuffer, vram_at2(0), (size / 2) & 0x1FFFFF);
    gMenuWork->bg_tile_base = (size >> 5) - 1;
    CpuSet(gMedalIconTiles, vram_at2(size), (0x1000 / 2) & 0x1FFFFF);
    zero = 0;
    CpuFastSet(&zero, (void *)0x05000000, 0x01000080);
    zero2 = 0;
    CpuFastSet(&zero2, (void *)0x05000200, 0x01000080);
    lz_decompress_dispatch(gMenuObjTilesLz, (void *)0x06010000);
    lz_decompress_dispatch(gSpriteFontTiles, (void *)0x06017400);
    for (i = 0; i < 2; i++) {
        gSpriteEntries[i].flags = 0xC000;
        gSpriteEntries[i].frame_table = 2;
        gSpriteEntries[i].palette = 0xE;
        gSpriteEntries[i].frame = 8;
    }

    gSpriteEntries[0].flags |= 0x2000;
    gSpriteEntries[20].flags = 0x8000;
    gSpriteEntries[20].frame_table = 2;
    gSpriteEntries[20].x = 0x10;
    gSpriteEntries[20].y = 0x10;
    gSpriteEntries[20].palette = 0;
    gSpriteEntries[20].frame = 0x23;
    if (gNameEntryMode == 0) {
        gSpriteEntries[20].flags |= 0x4000;
    } else {
        t = gMenuWork->bg_tile_base + ((gMedals[gCurrentMedalSlot].graphicId * 4) + 1);
        t |= 0x6000;
        base = ((REG_BG1CNT >> 8) & 0x1F) << 11;
        map = (u16 *)(0x06000000 + base);
        d = (u16 *)(base + 0x060000C4);
        *d = t;
        d = &map[0x63];
        *d = t + 1;
        d = &map[0x82];
        *d = t + 2;
        d = &map[0x83];
        *d = t + 3;
    }
    for (i = 0; i < 2; i++) {
        gSpriteEntries[i + 2].flags = 0x8000;
        gSpriteEntries[i + 2].frame_table = 2;
        gSpriteEntries[i + 2].palette = 0xE;
        gSpriteEntries[i + 2].frame = 5;
    }

    gSpriteEntries[3].flags |= 0x1000;
    gMenuWork->grid_col = 0;
    gMenuWork->grid_row = 0;
    gMenuWork->step = 0;
    gSpriteEntries[0].x = (y = (gMenuWork->grid_col * 8) + 0x14);
    gSpriteEntries[0].y = mul16(gMenuWork->grid_row) + half4(gMenuWork->step);
    gSpriteEntries[1].x = y;
    gSpriteEntries[1].y = mul16(gMenuWork->grid_row) - half8(gMenuWork->step);
    gSpriteEntries[4].flags = 0xC000;
    gSpriteEntries[4].frame_table = 2;
    gSpriteEntries[4].palette = 0xE;
    gSpriteEntries[4].frame = 0x26;
    gGameSubState++;
}

void name_entry_load_name(void) {
    s8 i;
    s32 x;
    u8 k;
    const u8(*tbl)[2];

    REG_DISPCNT |= 0x200;
    REG_DISPCNT |= 0x400;
    REG_DISPCNT |= 0x800;
    REG_DISPCNT |= 0x1000;
    for (i = 0; i < 16; i++)
        gMenuWork->name_buf[i] = 0xFE;
    disable_sprites(5, 10);
    switch (gNameEntryMode) {
    case 0:
        for (i = 0; i < 16; i++) {
            gMenuWork->name_buf[i] = gDefaultPlayerName[i];
            if (gMenuWork->name_buf[i] == 0xFE)
                break;
        }
        gMenuWork->name_len = i;
        break;
    case 1:
        k = gMedals[gCurrentMedalSlot].graphicId;
        if (k <= 1) {
            for (i = 0; i < 16; i++) {
                gMenuWork->name_buf[i] = ((const u8 *)gMedalNames[k + 0x20])[i];
                if (gMenuWork->name_buf[i] == 0xFE)
                    break;
            }
        } else {
            for (i = 0; i < 16; i++) {
                gMenuWork->name_buf[i] = ((const u8 *)gMedalNames[k])[i];
                if (gMenuWork->name_buf[i] == 0xFE)
                    break;
            }
        }
        gMenuWork->name_len = i;
        break;
    case 2:
        for (i = 0; i < 16; i++) {
            gMenuWork->name_buf[i] = gMedals[gCurrentMedalSlot].name[i];
            if (gMenuWork->name_buf[i] == 0xFE)
                break;
        }
        gMenuWork->name_len = i;
        break;
    }
    CpuSet(gMenuWork->name_buf, gMenuWork->name_buf + 0x10, 8);
    gSpriteEntries[4].x = calc_text_pixel_width(gMenuWork->name_buf) + 0x28;
    gSpriteEntries[4].y = 0x1B;
    render_text_sprites_08040DB8(gMenuWork->name_buf, 5, 5, 3, 10, 13, 1, 0);
    x = gSpriteEntries[4].x + 2;
    {
        register const u8(*tb)[2] asm("r4");
        for (i = gMenuWork->name_len; i <= 9; i++) {
            tb = gFontWidths;
            gSpriteEntries[i + 5].flags = 0xC000;
            gSpriteEntries[i + 5].frame_table = 0;
            gSpriteEntries[i + 5].palette = 0xD;
            gSpriteEntries[i + 5].frame = 0x42;
            gSpriteEntries[i + 5].x = x;
            gSpriteEntries[i + 5].y = 0x1C;
            gSpriteEntries[i + 5].order = 0xFF;
            x += tb[0x43][0];
        }
    }
    CpuFastSet(gMenuDigitPalette, (void *)0x0202FA20, 8);
    CpuFastSet(gCursorArrowPalette, (void *)0x0202F9C0, 8);
    CpuFastSet(gSpriteFontPalette, (void *)0x0202F9A0, 8);
    CpuFastSet(gNameEntryObjPalette, gPaletteBackup, 8);
    CpuFastSet(gNameEntryBgPalettes, gPaletteBackupBg, 0x80);
    gGameWork.unk84 = 0;
    gGameSubState++;
}

void name_entry_fade_in(void) {
    struct GameWork *b = &gGameWork;
    if (b->unk84 <= 8) {
        bg_palettes_blend_masked_now(0, 0x20 - b->unk84 * 4, 0xFFFF);
        obj_palettes_blend_masked_now(0, 0x20 - b->unk84 * 4, 0xFFFF);
        b->unk84++;
    } else {
        gMenuWork->timer = 0;
        gMenuWork->returning = 0;
        gGameSubState++;
    }
}

// Per-frame update of the name-entry screen (runs every frame while naming a Medal): cursor blink and
// movement (rows 0-2 letters, row 3 Space / Back / End), Start / R / A / B, edits the name in unk58.
void name_entry_input(void) {
    s32 i;
    s32 x;
    u8 blank;
    u8 col;
    s32 t;

    gSpriteEntries[4].frame = ((gFrameCounter / 6) & 3) + 0x26;
    if (gMenuWork->returning) {
        if (gMenuWork->timer++ < 8)
            gMenuWork->step++;
        else {
            gMenuWork->timer = 0;
            gMenuWork->returning = 0;
        }
    } else {
        if (gMenuWork->timer++ < 8)
            gMenuWork->step--;
        else {
            gMenuWork->timer = 0;
            gMenuWork->returning = 1;
        }
    }

    if (KEYS_LO(gRepeatKeys) & 0x10) {
        play_sound_effect(2);
        col = gMenuWork->grid_col;
        if (gMenuWork->grid_row == 3 ? col == 2 : col == 0x19)
            gMenuWork->grid_col = 0;
        else
            gMenuWork->grid_col++;
    }
    if (KEYS_LO(gRepeatKeys) & 0x20) {
        play_sound_effect(2);
        if (gMenuWork->grid_col == 0) {
            gMenuWork->grid_col = gMenuWork->grid_row == 3 ? 2 : 0x19;
        } else
            gMenuWork->grid_col--;
    }
    if (KEYS_LO(gRepeatKeys) & 0x40) {
        play_sound_effect(2);
        if (gMenuWork->grid_row == 0) {
            gMenuWork->grid_row = 3;
            if (gMenuWork->grid_col <= 8)
                gMenuWork->grid_col = 0;
            else if (gMenuWork->grid_col <= 0x10)
                gMenuWork->grid_col = 1;
            else
                gMenuWork->grid_col = 2;
        } else {
            gMenuWork->grid_row--;
            if (gMenuWork->grid_row == 2)
                gMenuWork->grid_col = gNameEntryColumnRemap[gMenuWork->grid_col];
        }
    }
    if (KEYS_LO(gRepeatKeys) & 0x80) {
        play_sound_effect(2);
        if (gMenuWork->grid_row == 3) {
            gMenuWork->grid_row = 0;
            gMenuWork->grid_col = gNameEntryColumnRemap[gMenuWork->grid_col];
        } else {
            gMenuWork->grid_row++;
            if (gMenuWork->grid_row == 3) {
                if (gMenuWork->grid_col <= 8)
                    gMenuWork->grid_col = 0;
                else if (gMenuWork->grid_col <= 0x10)
                    gMenuWork->grid_col = 1;
                else
                    gMenuWork->grid_col = 2;
            }
        }
    }

    if (gMenuWork->grid_row == 3) {
        gSpriteEntries[0].x = gMenuWork->grid_col * 64 - (t = (s32)gMenuWork->step / 2 - 0x18);
        gSpriteEntries[0].y = 0x8C;
        gSpriteEntries[1].x = gMenuWork->grid_col * 64 + (t = (s32)gMenuWork->step / 2 + 0x58);
        gSpriteEntries[1].y = gSpriteEntries[0].y;
        gSpriteEntries[0].frame = 5;
        gSpriteEntries[1].frame = 5;
        gSpriteEntries[0].flags &= 0xDFFF;
        gSpriteEntries[1].flags |= 0x1000;
    } else {
        gSpriteEntries[0].x = gMenuWork->grid_col * 8 + 0x14;
        gSpriteEntries[0].y = gMenuWork->grid_row * 24 + (t = (s32)gMenuWork->step / 2 + 0x40);
        gSpriteEntries[1].x = gSpriteEntries[0].x;
        gSpriteEntries[1].y = gMenuWork->grid_row * 24 - (t = (s32)gMenuWork->step / 2 - 0x50);
        gSpriteEntries[0].frame = 8;
        gSpriteEntries[1].frame = 8;
        gSpriteEntries[0].flags |= 0x2000;
        gSpriteEntries[1].flags &= 0xEFFF;
    }

    if (KEYS_LO(gNewKeys) & 8) {
    start:
        play_sound_effect(4);
        gMenuWork->grid_row = 3;
        gMenuWork->grid_col = 2;
    } else if (*((u8 *)&gNewKeys + 1) & 1) {
    space:
        if (gMenuWork->name_len <= 9) {
            play_sound_effect(4);
            gMenuWork->name_buf[gMenuWork->name_len] = 0;
            gMenuWork->name_len++;
            if (gMenuWork->name_len == 10) {
                gSpriteEntries[4].flags &= 0xBFFF;
                disable_sprites(5, 10);
                render_text_sprites_08040DB8(gMenuWork->name_buf, 5, 5, 3, 10, 13, 1, 0);
                goto start;
            }
        } else
            play_sound_effect(6);
        goto redraw;
    } else if (KEYS_LO(gNewKeys) & 1) {
        if (gMenuWork->grid_row == 3) {
            switch (gMenuWork->grid_col) {
            case 1:
                goto back;
            case 0:
                goto space;
            case 2:
                gSpriteEntries[4].flags &= 0xBFFF;
                blank = 1;
                for (i = 0; (u32)i < 16 && gMenuWork->name_buf[i] != 0xFE; i++) {
                    if (gMenuWork->name_buf[i] != 0) {
                        blank = 0;
                        break;
                    }
                }
                if (blank)
                    CpuSet(gMenuWork->name_buf + 0x10, gMenuWork->name_buf, 8);
                disable_sprites(5, 10);
                render_text_sprites_08040DB8(gMenuWork->name_buf, 5, 5, 3, 10, 13, 1, 0);
                play_sound_effect(7);
                gGameSubState++;
                return;
            }
        }
        if (gMenuWork->name_len <= 9) {
            play_sound_effect(4);
            gMenuWork->name_buf[gMenuWork->name_len] = gMenuWork->grid_row * 26 + gMenuWork->grid_col + 1;
            gMenuWork->name_len++;
            if (gMenuWork->name_len == 10) {
                gSpriteEntries[4].flags &= 0xBFFF;
                disable_sprites(5, 10);
                render_text_sprites_08040DB8(gMenuWork->name_buf, 5, 5, 3, 10, 13, 1, 0);
                goto start;
            }
        } else
            play_sound_effect(6);
    redraw:
        disable_sprites(5, 10);
        render_text_sprites_08040DB8(gMenuWork->name_buf, 5, 5, 3, 10, 13, 1, 0);
    } else if (gNewKeys & 0x202) {
    back:
        play_sound_effect(5);
        if (gMenuWork->name_len != 0) {
            gMenuWork->name_len--;
            gMenuWork->name_buf[gMenuWork->name_len] = 0xFE;
        } else {
            gMenuWork->name_len = 0;
            gMenuWork->name_buf[gMenuWork->name_len] = 0xFE;
        }
        disable_sprites(5, 10);
        render_text_sprites_08040DB8(gMenuWork->name_buf, 5, 5, 3, 10, 13, 1, 0);
        gSpriteEntries[4].flags |= 0x4000;
    } else
        return;

    gSpriteEntries[4].x = calc_text_pixel_width(gMenuWork->name_buf) + 0x28;
    gSpriteEntries[4].y = 0x1B;
    x = gSpriteEntries[4].x + 2;
    {
        register const u8(*tb)[2] asm("r4");
        for (i = gMenuWork->name_len; i <= 9; i++) {
            tb = gFontWidths;
            gSpriteEntries[i + 5].flags = 0xC000;
            gSpriteEntries[i + 5].frame_table = 0;
            gSpriteEntries[i + 5].palette = 0xD;
            gSpriteEntries[i + 5].frame = 0x42;
            gSpriteEntries[i + 5].x = x;
            gSpriteEntries[i + 5].y = 0x1C;
            gSpriteEntries[i + 5].order = 0xFF;
            x += tb[0x43][0];
            tb = gFontWidths;
        }
    }
}

void name_entry_wait_sound(void) {
    u32 r = is_sound_effect_playing(7);
    if (r == 0) {
        gGameWork.unk84 = r;
        gGameSubState++;
    }
}

void name_entry_fade_out_store_name(void) {
    struct GameWork *s = &gGameWork;
    u8 *n = &s->unk84;

    if (*n <= 8) {
        bg_palettes_blend_masked_now(0, *n * 4, 0xFFFF);
        obj_palettes_blend_masked_now(0, *n * 4, 0xFFFF);
        (*n)++;
    } else {
        u32 zero;

        REG_DISPCNT &= 0xFDFF;
        zero = 0;
        CpuFastSet(&zero, (void *)VRAM, 0x01006000);
        switch (gNameEntryMode) {
        case 0:
            CpuSet(gMenuWork->name_buf, gPlayerRecord.name, 8);
            dispatch_by_index_0476e8(0);
            break;
        case 1:
            CpuSet(gMenuWork->name_buf, gMedals[gCurrentMedalSlot].name, 7);
            dispatch_by_index_0476e8(1);
            break;
        case 2:
            CpuSet(gMenuWork->name_buf, gMedals[gCurrentMedalSlot].name, 7);
            gGameState = 0x12;
            gGameSubState = 10;
            break;
        }
    }
}
