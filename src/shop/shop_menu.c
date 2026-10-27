// Mode-2 state 11: the Medaparts shop menu (Buy / Sell / Exit). shop_menu_dispatch runs gShopMenuStates.
// shop_highlight_part_type_icon (4-icon menu highlight) and shop_copy_text_with_portrait are shared with
// shop_list.c and shop_return.c.
#include "global.h"

static inline void *vram_at(u32 off) {
    return (void *)(0x06004000 + off);
}

void shop_highlight_part_type_icon(u32 sel, u32 frame) {
    u16 t = (s16)(sel * 4 + gMenuWork->obj_tile_base + 5) | (s16)0xC000;
    s32 i, j;
    u16 *a, *b;
    u16 pal;

    *(u16 *)(((REG_BG2CNT >> 8) & 0x1F) * 0x800 + 0x06000152) = t++;
    *(u16 *)(((REG_BG2CNT >> 8) & 0x1F) * 0x800 + 0x06000154) = t++;
    *(u16 *)(((REG_BG2CNT >> 8) & 0x1F) * 0x800 + 0x06000192) = t++;
    *(u16 *)(((REG_BG2CNT >> 8) & 0x1F) * 0x800 + 0x06000194) = t;
    for (i = 0; i < 4; i++) {
        a = (u16 *)(VRAM + ((REG_BG2CNT >> 8) & 0x1F) * 0x800) + gShopPartTypeIconPos[i][0] +
            gShopPartTypeIconPos[i][1] * 32;
        b = (u16 *)(VRAM + ((REG_BG2CNT >> 8) & 0x1F) * 0x800) + gShopPartTypeIconPos[i][0] +
            (gShopPartTypeIconPos[i][1] + 1) * 32;
        if (frame & 8)
            pal = (i == sel) ? 0x6000 : 0x5000;
        else
            pal = 0x5000;
        for (j = 0; j < 8; j++) {
            *a = (*a & 0xFFF) | pal;
            a++;
            *b = (*b & 0xFFF) | pal;
            b++;
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
    u16 v;
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
    v = 0x1B05;
    *bg1 = v;
    decompress_and_write_tilemap(gUnk_08799838, *bg1);
    bg2 = &REG_BG2CNT;
    v = 0x1A06;
    *bg2 = v;
    decompress_and_write_tilemap(gUnk_087999EC, *bg2);
    v = 0x1E05;
    *bg1 = v;
    v -= 0xFF;
    *bg2 = v;
    bg3 = &REG_BG3CNT;
    v -= 0xFF;
    *bg3 = v;
    decompress_and_write_tilemap(gUnk_08798608, *bg1);
    decompress_and_write_tilemap(gUnk_08798824, *bg2);
    decompress_and_write_tilemap(gUnk_08798A34, *bg3);
    size = dma3_copy_or_decompress(gUnk_0879691C, gDecompressBuffer);
    off = 0x4000;
    CpuCopy16(gDecompressBuffer, (void *)(off + vram), size);
    n = lz_decompress_dispatch(gUnk_084C4DB0, vram_at(size));
    gMenuWork->obj_tile_base = (size >> 5) - 1;
    size += n;
    tilemap_offset_tiles_and_palette(size >> 5, 0, 0x1B);
    tilemap_offset_tiles_and_palette(size >> 5, 0, 0x1A);
    n = dma3_copy_or_decompress(gUnk_08798F2C, gDecompressBuffer);
    dst = vram_at(size);
    CpuCopy16(gDecompressBuffer, dst, n);
    gMenuWork->bg_tile_base = ((size + n) >> 5) - 1;
    lz_decompress_dispatch(gUnk_08784CB0, dst += n);
    lz_decompress_dispatch(gUnk_08784DA4, (void *)0x06010000);
    lz_decompress_dispatch(gSpriteFontTiles, (void *)0x06017400);
    lz_decompress_dispatch(gCursorArrowTiles, (void *)0x06017E00);
    gGameSubState++;
}

void shop_menu_init(void) {
    u32 zero;
    u8 i;

    zero = 0;
    CpuFastSet(&zero, (void *)0x0600DA80, 0x01000080);
    clear_battle_sprite_slot(0, 0x80);
    gSpriteEntries[8].unk0 = 0x8004;
    gSpriteEntries[8].unk1C = 0;
    gSpriteEntries[8].unkA = 0xE;
    gSpriteEntries[8].unk6 = 0x307;
    gSpriteEntries[8].unk2 = 8;
    gSpriteEntries[8].unk4 = gMenuWork->cursor * 24 + 0x20;
    gSpriteEntries[8].unk0 |= 0x1200;
    gSpriteEntries[8].unk8 = 0x40;
    gSpriteEntries[8].unk9 = 0x40;
    gSpriteEntries[7].unk0 = 0xC000;
    gSpriteEntries[7].unk1C = 2;
    gSpriteEntries[7].unkA = 1;
    gSpriteEntries[7].unk6 = 0x1A;
    gSpriteEntries[7].unk2 = 0x98;
    gSpriteEntries[7].unk4 = 0;
    for (i = 0; i < 4; i++) {
        gSpriteEntries[i + 12].unk0 = 0x8000;
        gSpriteEntries[i + 12].unk1C = 2;
        gSpriteEntries[i + 12].unkA = 0;
    }
    gSpriteEntries[13].unk0 |= 0x1000;
    gSpriteEntries[15].unk0 |= 0x2000;
    gSpriteEntries[13].unk6 = 5;
    gSpriteEntries[14].unk6 = 5;
    gSpriteEntries[12].unk6 = 8;
    gSpriteEntries[15].unk6 = 8;
    gSpriteEntries[13].unk2 = 0x48;
    gSpriteEntries[13].unk4 = 0x2C;
    gSpriteEntries[14].unk2 = 0x58;
    gSpriteEntries[14].unk4 = 0x2C;
    gSpriteEntries[12].unk2 = 0x50;
    gSpriteEntries[12].unk4 = 0x22;
    gSpriteEntries[15].unk2 = 0x50;
    gSpriteEntries[15].unk4 = 0x3E;
    divide_by_10000(gUnk_030004DE, gPlayerRecord.money);
    render_text_sprites_08040DB8(gUnk_030004DE, 0, 0x15, 1, 7, 0xF, 1, 0);
    gGameSubState++;
}

void shop_menu_show_layers(void) {
    REG_DISPCNT |= 0x200;
    REG_DISPCNT |= 0x400;
    REG_DISPCNT |= 0x800;
    REG_DISPCNT |= 0x1000;
    CpuFastSet(gCursorArrowPalette, (void *)0x0202F800, 8);
    CpuFastSet(gSpriteFontPalette, (void *)0x0202F9E0, 8);
    CpuFastSet(gCursorArrowPalette, (void *)0x0202F9C0, 8);
    CpuFastSet(gUnk_08488AA4, (void *)0x0202F820, 8);
    CpuFastSet(gUnk_0879671C, (void *)0x0202FA00, 0x80);
    gGameWork.unk84 = 0;
    gGameSubState++;
}

// State 3: fade in from white; back from the list (unk6 == 1) it goes straight to the part types (state 9).
void shop_menu_fade_in(void) {
    if (gMenuWork->returning == 1) {
        struct GameWork *s;
        u8 *n;

        shop_highlight_part_type_icon(gMenuWork->part_kind, 8);
        s = &gGameWork;
        n = &s->unk84;
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
        struct GameWork *s = &gGameWork;
        u8 *n = &s->unk84;

        if (*n <= 8) {
            bg_palettes_blend_masked_now(0, 0x20 - *n * 4, 0xFFFF);
            obj_palettes_blend_masked_now(0, 0x20 - *n * 4, 0xFFFF);
            (*n)++;
        } else {
            gMenuWork->timer = 0;
            gSpriteEntries[8].unk0 |= 0x4000;
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
        gSpriteEntries[8].unk0 |= 0x4000;
        gGameSubState++;
    }
}

// State 5: Buy / Sell / Exit cursor (unk5 = 0 / 1 / 2). Buy and Sell -> 8, Exit or B -> 6.
void shop_menu_choose_action(void) {
    sprite_bob_y(8, gFrameCounter, 8);
    if (KEYS_LO(gRepeatKeys) & 0x40) {
        play_sound_effect(2);
        if (gMenuWork->cursor != 0)
            gMenuWork->cursor--;
        else
            gMenuWork->cursor = 2;
    }
    if (KEYS_LO(gRepeatKeys) & 0x80) {
        play_sound_effect(2);
        if (gMenuWork->cursor <= 1)
            gMenuWork->cursor++;
        else
            gMenuWork->cursor = 0;
    }
    gSpriteEntries[8].unk4 = gMenuWork->cursor * 24 + 0x20;
    if (KEYS_LO(gNewKeys) & 1) {
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
            gGameWork.unk84 = 0;
            gGameSubState = 6;
            break;
        }
    } else if (KEYS_LO(gNewKeys) & 2) {
        play_sound_effect(5);
        goto cancel;
    }
}

void shop_menu_close_message(void) {
    if (game_state_execute_handler_a()) {
        gGameWork.unk84 = 0;
        gGameSubState++;
    }
}

void shop_menu_fade_out_exit(void) {
    struct GameWork *s = &gGameWork;
    u8 *n = &s->unk84;

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
    u8 t = gMenuWork->timer++;

    if (gSpriteEntries[8].unk8 > 4) {
        gSpriteEntries[8].unk8 -= 4;
        gSpriteEntries[8].unk9 -= 4;
    } else {
        gSpriteEntries[8].unk0 &= 0xBFFF;
    }
    if (t <= 16) {
        REG_BLDALPHA = (t << 8) | (16 - t);
    } else {
        REG_BLDALPHA = 0x1000;
        REG_DISPCNT &= 0xFDFF;
        gSpriteEntries[8].unk0 &= 0xBFFF;
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

// State 10: part type (unk19): Up head, Left right arm, Right left arm, Down legs. A -> 12, B -> 11.
void shop_menu_choose_part_type(void) {
    s8 i;

    for (i = 0; i < 4; i++) {
        if ((gFrameCounter >> 3) & 1)
            gSpriteEntries[12 + i].unk0 |= 0x4000;
        else if (gMenuWork->part_kind == i)
            gSpriteEntries[12 + gMenuWork->part_kind].unk0 &= 0xBFFF;
    }
    if (KEYS_LO(gNewKeys) & 0x40) {
        play_sound_effect(2);
        gMenuWork->part_kind = 0;
        shop_highlight_part_type_icon(0, gFrameCounter);
    }
    if (KEYS_LO(gNewKeys) & 0x80) {
        play_sound_effect(2);
        gMenuWork->part_kind = 3;
        shop_highlight_part_type_icon(3, gFrameCounter);
    }
    if (KEYS_LO(gNewKeys) & 0x20) {
        play_sound_effect(2);
        gMenuWork->part_kind = 1;
        shop_highlight_part_type_icon(1, gFrameCounter);
    }
    if (KEYS_LO(gNewKeys) & 0x10) {
        play_sound_effect(2);
        gMenuWork->part_kind = 2;
        shop_highlight_part_type_icon(2, gFrameCounter);
    }
    if (!(gFrameCounter & 7))
        shop_highlight_part_type_icon(gMenuWork->part_kind, gFrameCounter);
    if (KEYS_LO(gNewKeys) & 1) {
        play_sound_effect(4);
        for (i = 0; i < 4; i++)
            gSpriteEntries[12 + i].unk0 |= 0x4000;
        if (gMenuWork->part_kind == 4) {
        back:
            gGameSubState = 0xB;
        } else {
            gGameWork.unk84 = 0;
            gMenuWork->counter = 0x2D;
            gGameSubState = 0xC;
        }
    } else if (KEYS_LO(gNewKeys) & 2) {
        play_sound_effect(5);
        for (i = 0; i < 4; i++)
            gSpriteEntries[12 + i].unk0 &= 0xBFFF;
        REG_DISPCNT |= 0x200;
        gSpriteEntries[8].unk0 |= 0x4000;
        gMenuWork->timer = 0x10;
        goto back;
    }
}

void shop_menu_close_part_types(void) {
    u8 t = gMenuWork->timer--;

    if (gSpriteEntries[8].unk8 < 0x40) {
        gSpriteEntries[8].unk8 += 4;
        gSpriteEntries[8].unk9 += 4;
    } else {
        gSpriteEntries[8].unk9 = 0x40;
    }
    if (t != 0) {
        REG_BLDALPHA = (t << 8) | (16 - t);
    } else {
        REG_BLDALPHA = 16;
        message_next();
        gGameSubState = 4;
    }
}

void shop_menu_part_type_chosen(void) {
    u8 *t;

    shop_highlight_part_type_icon(gMenuWork->part_kind, gFrameCounter * 2);
    t = &gMenuWork->counter;
    if (*t != 0)
        (*t)--;
    else if (game_state_execute_handler_a()) {
        gGameWork.unk84 = 0;
        gGameSubState++;
    }
}

void shop_menu_fade_out_to_list(void) {
    struct GameWork *s = &gGameWork;
    u8 *n = &s->unk84;
    s32 i;

    if (*n <= 8) {
        bg_palettes_blend_masked_now(0, *n * 4, 0xFFFE);
        obj_palettes_blend_masked_now(0, *n * 4, 0x7FFD);
        (*n)++;
    } else {
        for (i = 0; i < 4; i++)
            gSpriteEntries[12 + i].unk0 &= 0xBFFF;
        gMenuWork->returning = 1;
        gMenuWork->list_cursor = 0;
        *(u8 *)0x02023078 = 0;
        {
            u8 *b;
            u32 z = 0;
            i = 0x77;
            b = (u8 *)0x02023077;
            for (; i >= 0; i--)
                *b-- = z;
        }
        gGameState = 12;
        gGameSubState = 0;
    }
}
