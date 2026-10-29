// Mode-2 state 11: the Medaparts shop menu (Buy / Sell / Exit). shop_menu_dispatch runs gShopMenuStates.
// shop_highlight_part_type_icon (4-icon menu highlight) and shop_copy_text_with_portrait are shared with
// shop_list.c and shop_return.c.
#include "global.h"
#include "constants/sprites.h"

static inline void *vram_at(u32 off) {
    return (void *)(BG_CHAR_ADDR(1) + off);
}

void shop_highlight_part_type_icon(u32 sel, u32 frame) {
    u16 tile = (s16)(sel * 4 + gMenuWork->obj_tile_base + 5) | (s16)0xC000;
    s32 i, j;
    u16 *top_row, *bottom_row;
    u16 pal;

    BG_TILEMAP(REG_BG2CNT)[9 + 5 * 32] = tile++;
    BG_TILEMAP(REG_BG2CNT)[10 + 5 * 32] = tile++;
    BG_TILEMAP(REG_BG2CNT)[9 + 6 * 32] = tile++;
    BG_TILEMAP(REG_BG2CNT)[10 + 6 * 32] = tile;
    for (i = 0; i < 4; i++) {
        top_row = BG_TILEMAP(REG_BG2CNT) + gShopPartTypeIconPos[i][0] + gShopPartTypeIconPos[i][1] * 32;
        bottom_row = BG_TILEMAP(REG_BG2CNT) + gShopPartTypeIconPos[i][0] + (gShopPartTypeIconPos[i][1] + 1) * 32;
        if (frame & 8)
            pal = (i == sel) ? 0x6000 : 0x5000;
        else
            pal = 0x5000;
        for (j = 0; j < 8; j++) {
            *top_row = (*top_row & 0xFFF) | pal;
            top_row++;
            *bottom_row = (*bottom_row & 0xFFF) | pal;
            bottom_row++;
        }
    }
}

void shop_copy_text_with_portrait(dst, src, unused, i) u8 *dst;
u8 *src;
u32 unused;
u32 i;
{
    do {
        dst[i] = src[i];
        i++;
    } while (src[i] != 0xFF);
    dst[i] = src[i];
    i++;
    dst[i] = src[i];
    dst[2] = gShopkeeperPortraitSets[gShopId];
}

void shop_menu_dispatch(void) {
    gShopMenuStates[gGameSubState]();
    if (gFrameCounter & 1) {
        gBg3Scroll.x++;
        gBg3Scroll.y++;
    }
}

void shop_menu_start(void) {
    gMenuWork->cursor = 0;
    gMenuWork->returning = 0;
    gGameSubState = 14;
}

void shop_menu_goto_init(void) {
    gGameSubState = 1;
}

// State 14: clears VRAM, loads the shop backdrop, menu tilemaps and tiles; -> 15.
void shop_menu_load_graphics(void) {
    u32 zero;
    vu16 *bg1, *bg2, *bg3;
    u16 bgcnt;
    u32 size;
    u32 n;
    u32 vram;
    u32 off;
    u8 *dst;

    zero = 0;
    vram = VRAM;
    CpuFastSet(&zero, (void *)vram, 0x01006000);
    reset_bg_scroll();
    clear_battle_sprite_slot(0, 0x80);
    REG_DISPCNT = 0x60;
    REG_BLDCNT = 0xC42;
    REG_BLDALPHA = 0x10;
    bg1 = &REG_BG1CNT;
    bgcnt = 0x1B05;
    *bg1 = bgcnt;
    decompress_and_write_tilemap(gShopMenuPanelTilemap1, *bg1);
    bg2 = &REG_BG2CNT;
    bgcnt = 0x1A06;
    *bg2 = bgcnt;
    decompress_and_write_tilemap(gShopMenuPanelTilemap2, *bg2);
    bgcnt = 0x1E05;
    *bg1 = bgcnt;
    bgcnt -= 0xFF;
    *bg2 = bgcnt;
    bg3 = &REG_BG3CNT;
    bgcnt -= 0xFF;
    *bg3 = bgcnt;
    decompress_and_write_tilemap(gShopMenuBg1Tilemap, *bg1);
    decompress_and_write_tilemap(gShopMenuBg2Tilemap, *bg2);
    decompress_and_write_tilemap(gShopMenuBg3Tilemap, *bg3);
    size = dma3_copy_or_decompress(gShopMenuBgTiles, gDecompressBuffer);
    off = 0x4000;
    CpuCopy16(gDecompressBuffer, (void *)(off + vram), size);
    n = lz_decompress_dispatch(gPartSlotIconTiles, vram_at(size));
    gMenuWork->obj_tile_base = (size >> 5) - 1;
    size += n;
    tilemap_offset_tiles_and_palette(size >> 5, 0, 0x1B);
    tilemap_offset_tiles_and_palette(size >> 5, 0, 0x1A);
    n = dma3_copy_or_decompress(gShopMenuBgTiles2, gDecompressBuffer);
    dst = vram_at(size);
    CpuCopy16(gDecompressBuffer, dst, n);
    gMenuWork->bg_tile_base = ((size + n) >> 5) - 1;
    lz_decompress_dispatch(gMenuDigitTilesLz, dst += n);
    lz_decompress_dispatch(gMenuObjTilesLz, (void *)OBJ_VRAM0);
    lz_decompress_dispatch(gSpriteFontTiles, (void *)(OBJ_VRAM0 + 0x7400));
    lz_decompress_dispatch(gCursorArrowTiles, (void *)(OBJ_VRAM0 + 0x7E00));
    gGameSubState++;
}

void shop_menu_init(void) {
    u32 zero;
    u8 i;

    zero = 0;
    CpuFastSet(&zero, (void *)(BG_VRAM + 0xDA80), 0x01000080);
    clear_battle_sprite_slot(0, 0x80);
    gSpriteEntries[8].flags = SPRITE_FLAG_ENABLED | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[8].frame_table = 0;
    gSpriteEntries[8].palette = 0xE;
    gSpriteEntries[8].frame = 0x307;
    gSpriteEntries[8].x = 8;
    gSpriteEntries[8].y = gMenuWork->cursor * 24 + 0x20;
    gSpriteEntries[8].flags |= SPRITE_FLAG_HFLIP | SPRITE_FLAG_AFFINE;
    gSpriteEntries[8].scale_x = 0x40;
    gSpriteEntries[8].scale_y = 0x40;
    gSpriteEntries[7].flags = SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE;
    gSpriteEntries[7].frame_table = 2;
    gSpriteEntries[7].palette = 1;
    gSpriteEntries[7].frame = 0x1A;
    gSpriteEntries[7].x = 0x98;
    gSpriteEntries[7].y = 0;
    for (i = 0; i < 4; i++) {
        gSpriteEntries[i + 12].flags = SPRITE_FLAG_ENABLED;
        gSpriteEntries[i + 12].frame_table = 2;
        gSpriteEntries[i + 12].palette = 0;
    }
    gSpriteEntries[13].flags |= SPRITE_FLAG_HFLIP;
    gSpriteEntries[15].flags |= SPRITE_FLAG_VFLIP;
    gSpriteEntries[13].frame = 5;
    gSpriteEntries[14].frame = 5;
    gSpriteEntries[12].frame = 8;
    gSpriteEntries[15].frame = 8;
    gSpriteEntries[13].x = 0x48;
    gSpriteEntries[13].y = 0x2C;
    gSpriteEntries[14].x = 0x58;
    gSpriteEntries[14].y = 0x2C;
    gSpriteEntries[12].x = 0x50;
    gSpriteEntries[12].y = 0x22;
    gSpriteEntries[15].x = 0x50;
    gSpriteEntries[15].y = 0x3E;
    divide_by_10000(gTextArgBuffer, gPlayerRecord.money);
    render_text_sprites_08040DB8(gTextArgBuffer, 0, 0x15, 1, 7, 0xF, 1, 0);
    gGameSubState++;
}

void shop_menu_show_layers(void) {
    REG_DISPCNT |= 0x200;
    REG_DISPCNT |= 0x400;
    REG_DISPCNT |= 0x800;
    REG_DISPCNT |= 0x1000;
    CpuFastSet(gCursorArrowPalette, (void *)OBJ_PAL_BACKUP_ADDR(0), 8);
    CpuFastSet(gSpriteFontPalette, (void *)OBJ_PAL_BACKUP_ADDR(15), 8);
    CpuFastSet(gCursorArrowPalette, (void *)OBJ_PAL_BACKUP_ADDR(14), 8);
    CpuFastSet(gShopObjPalette, (void *)OBJ_PAL_BACKUP_ADDR(1), 8);
    CpuFastSet(gShopMenuBgPalettes, (void *)BG_PAL_BACKUP_ADDR(0), 0x80);
    gGameWork.stepCounter = 0;
    gGameSubState++;
}

// State 3: fade in from white; back from the list (returning == 1) it goes straight to the part types (state 9).
void shop_menu_fade_in(void) {
    if (gMenuWork->returning == 1) {
        struct GameWork *game;
        u8 *n;

        shop_highlight_part_type_icon(gMenuWork->part_kind, 8);
        game = &gGameWork;
        n = &game->stepCounter;
        if (*n <= 8) {
            bg_palettes_blend_masked_now(0, 0x20 - *n * 4, 0x7FFE);
            obj_palettes_blend_masked_now(0, 0x20 - *n * 4, 0x7FFD);
            (*n)++;
        } else {
            gMenuWork->timer = 0;
            text_window_init(1, 0, 0);
            gMenuWork->timer = 0;
            gMenuWork->fade_level = 0;
            gMenuWork->returning = 0;
            gGameSubState = 9;
        }
    } else {
        struct GameWork *game = &gGameWork;
        u8 *n = &game->stepCounter;

        if (*n <= 8) {
            bg_palettes_blend_masked_now(0, 0x20 - *n * 4, 0xFFFF);
            obj_palettes_blend_masked_now(0, 0x20 - *n * 4, 0xFFFF);
            (*n)++;
        } else {
            gMenuWork->timer = 0;
            gSpriteEntries[8].flags |= SPRITE_FLAG_VISIBLE;
            text_window_init(1, 0, 0);
            gMenuWork->timer = 0;
            gMenuWork->fade_level = 0;
            gGameSubState++;
        }
    }
}

void shop_menu_greeting(void) {
    u8 *buf = gMenuWork->message_buf;

    shop_copy_text_with_portrait(buf, gShopGreetingText);
    if (run_message(buf)) {
        gSpriteEntries[8].flags |= SPRITE_FLAG_VISIBLE;
        gGameSubState++;
    }
}

// State 5: Buy / Sell / Exit cursor (cursor = 0 / 1 / 2). Buy and Sell -> 8, Exit or B -> 6.
void shop_menu_choose_action(void) {
    sprite_bob_x(8, gFrameCounter, 8);
    if (KEYS_LO(gRepeatKeys) & DPAD_UP) {
        play_sound_effect(2);
        if (gMenuWork->cursor != 0)
            gMenuWork->cursor--;
        else
            gMenuWork->cursor = 2;
    }
    if (KEYS_LO(gRepeatKeys) & DPAD_DOWN) {
        play_sound_effect(2);
        if (gMenuWork->cursor <= 1)
            gMenuWork->cursor++;
        else
            gMenuWork->cursor = 0;
    }
    gSpriteEntries[8].y = gMenuWork->cursor * 24 + 0x20;
    if (KEYS_LO(gNewKeys) & A_BUTTON) {
        play_sound_effect(4);
        switch (gMenuWork->cursor) {
        case 0:
            gMenuWork->timer = 0;
            gGameSubState = 8;
            gMenuWork->returning = 0;
            shop_highlight_part_type_icon(0, 0);
            break;
        case 1:
            gMenuWork->timer = 0;
            gGameSubState = 8;
            gMenuWork->returning = 0;
            shop_highlight_part_type_icon(0, 0);
            break;
        case 2:
        cancel:
            gGameWork.stepCounter = 0;
            gGameSubState = 6;
            break;
        }
    } else if (KEYS_LO(gNewKeys) & B_BUTTON) {
        play_sound_effect(5);
        goto cancel;
    }
}

void shop_menu_close_message(void) {
    if (game_state_execute_handler_a()) {
        gGameWork.stepCounter = 0;
        gGameSubState++;
    }
}

void shop_menu_fade_out_exit(void) {
    struct GameWork *game = &gGameWork;
    u8 *n = &game->stepCounter;

    if (*n <= 8) {
        bg_palettes_blend_masked_now(0, *n * 4, 0xFFFF);
        obj_palettes_blend_masked_now(0, *n * 4, 0xFFFF);
        (*n)++;
    } else {
        REG_DISPCNT &= 0xFDFF;
        REG_DISPCNT &= 0xFBFF;
        REG_DISPCNT &= 0xF7FF;
        clear_battle_sprite_slot(0, 0x80);
        dispatch_by_index_0476e8(3);
    }
}

void shop_menu_open_part_types(void) {
    u8 fade = gMenuWork->timer++;

    if (gSpriteEntries[8].scale_x > 4) {
        gSpriteEntries[8].scale_x -= 4;
        gSpriteEntries[8].scale_y -= 4;
    } else {
        gSpriteEntries[8].flags &= (u16)~SPRITE_FLAG_VISIBLE;
    }
    if (fade <= 16) {
        REG_BLDALPHA = (fade << 8) | (16 - fade);
    } else {
        REG_BLDALPHA = 0x1000;
        REG_DISPCNT &= 0xFDFF;
        gSpriteEntries[8].flags &= (u16)~SPRITE_FLAG_VISIBLE;
        message_next();
        gGameSubState++;
    }
    gMenuWork->part_kind = 0;
}

void shop_menu_part_type_prompt(void) {
    u8 buf[0x30];

    shop_copy_text_with_portrait(buf, gMenuWork->cursor == 0 ? gShopBuyPartTypeText : gShopSellPartTypeText);
    if (run_message(buf))
        gGameSubState++;
}

// State 10: part type (part_kind): Up head, Left right arm, Right left arm, Down legs. A -> 12, B -> 11.
void shop_menu_choose_part_type(void) {
    s8 i;

    for (i = 0; i < 4; i++) {
        if ((gFrameCounter >> 3) & 1)
            gSpriteEntries[12 + i].flags |= SPRITE_FLAG_VISIBLE;
        else if (gMenuWork->part_kind == i)
            gSpriteEntries[12 + gMenuWork->part_kind].flags &= (u16)~SPRITE_FLAG_VISIBLE;
    }
    if (KEYS_LO(gNewKeys) & DPAD_UP) {
        play_sound_effect(2);
        gMenuWork->part_kind = 0;
        shop_highlight_part_type_icon(0, gFrameCounter);
    }
    if (KEYS_LO(gNewKeys) & DPAD_DOWN) {
        play_sound_effect(2);
        gMenuWork->part_kind = 3;
        shop_highlight_part_type_icon(3, gFrameCounter);
    }
    if (KEYS_LO(gNewKeys) & DPAD_LEFT) {
        play_sound_effect(2);
        gMenuWork->part_kind = 1;
        shop_highlight_part_type_icon(1, gFrameCounter);
    }
    if (KEYS_LO(gNewKeys) & DPAD_RIGHT) {
        play_sound_effect(2);
        gMenuWork->part_kind = 2;
        shop_highlight_part_type_icon(2, gFrameCounter);
    }
    if (!(gFrameCounter & 7))
        shop_highlight_part_type_icon(gMenuWork->part_kind, gFrameCounter);
    if (KEYS_LO(gNewKeys) & A_BUTTON) {
        play_sound_effect(4);
        for (i = 0; i < 4; i++)
            gSpriteEntries[12 + i].flags |= SPRITE_FLAG_VISIBLE;
        if (gMenuWork->part_kind == 4) {
        back:
            gGameSubState = 0xB;
        } else {
            gGameWork.stepCounter = 0;
            gMenuWork->counter = 0x2D;
            gGameSubState = 0xC;
        }
    } else if (KEYS_LO(gNewKeys) & B_BUTTON) {
        play_sound_effect(5);
        for (i = 0; i < 4; i++)
            gSpriteEntries[12 + i].flags &= (u16)~SPRITE_FLAG_VISIBLE;
        REG_DISPCNT |= 0x200;
        gSpriteEntries[8].flags |= SPRITE_FLAG_VISIBLE;
        gMenuWork->timer = 0x10;
        goto back;
    }
}

void shop_menu_close_part_types(void) {
    u8 fade = gMenuWork->timer--;

    if (gSpriteEntries[8].scale_x < 0x40) {
        gSpriteEntries[8].scale_x += 4;
        gSpriteEntries[8].scale_y += 4;
    } else {
        gSpriteEntries[8].scale_y = 0x40;
    }
    if (fade != 0) {
        REG_BLDALPHA = (fade << 8) | (16 - fade);
    } else {
        REG_BLDALPHA = 16;
        message_next();
        gGameSubState = 4;
    }
}

void shop_menu_part_type_chosen(void) {
    u8 *delay;

    shop_highlight_part_type_icon(gMenuWork->part_kind, gFrameCounter * 2);
    delay = &gMenuWork->counter;
    if (*delay != 0)
        (*delay)--;
    else if (game_state_execute_handler_a()) {
        gGameWork.stepCounter = 0;
        gGameSubState++;
    }
}

void shop_menu_fade_out_to_list(void) {
    struct GameWork *game = &gGameWork;
    u8 *n = &game->stepCounter;
    s32 i;

    if (*n <= 8) {
        bg_palettes_blend_masked_now(0, *n * 4, 0xFFFE);
        obj_palettes_blend_masked_now(0, *n * 4, 0x7FFD);
        (*n)++;
    } else {
        for (i = 0; i < 4; i++)
            gSpriteEntries[12 + i].flags &= (u16)~SPRITE_FLAG_VISIBLE;
        gMenuWork->returning = 1;
        gMenuWork->list_cursor = 0;
        *(u8 *)LIST_SCROLL_TOP_ADDR = 0;
        {
            u8 *dst;
            u32 z = 0;
            i = 0x77;
            dst = (u8 *)0x02023077;
            for (; i >= 0; i--)
                *dst-- = z;
        }
        gGameState = 12;
        gGameSubState = 0;
    }
}
