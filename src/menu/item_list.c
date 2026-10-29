// Item and Medapart list drawing shared by the item menu (menu/item_menu.c) and the shop screens: unpack the
// item inventory into a list buffer, Medapart icons and page numbers, the shop sell list, swapping entries.
// Its callers are in the mode-2 screens; uses engine/ sprite and tilemap helpers.
#include "global.h"
#include "constants/sprites.h"

static void clear_item_list_map_run(s32 x, s32 y, s32 n);

static void upload_palette_buffers(void) {
    CpuFastSet(gPaletteBuffer, (void *)OBJ_PLTT, 0x80);
    CpuFastSet(gPaletteBufferBg, (void *)PLTT, 0x80);
}

static void obj_palette_blend_to_color(u16 color, s32 blend, u32 pal) {
    u32 inv;
    u32 i;

    if (blend < 0)
        blend = 0;
    if (blend > 32)
        blend = 32;
    inv = 32 - blend;
    for (i = 0; i < 0x100; i++) {
        if (i >= pal * 16 && i < (pal + 1) * 16) {
            gPaletteBuffer[i] = (((color & 0x1F) * blend + inv * (gPaletteBackup[i] & 0x1F)) >> 5) |
                                ((((color & 0x3E0) * blend + inv * (gPaletteBackup[i] & 0x3E0)) >> 5) & 0x3E0) |
                                ((((color & 0x7C00) * blend + inv * (gPaletteBackup[i] & 0x7C00)) >> 5) & 0x7C00);
        } else {
            gPaletteBuffer[i] = gPaletteBackup[i];
        }
    }
    gVBlankOnceCallback = upload_palette_buffers;
}

static void bg_palettes_blend_to_color(u16 color, s32 blend) {
    u32 inv;
    u32 i;

    if (blend < 0)
        blend = 0;
    if (blend > 32)
        blend = 32;
    inv = 32 - blend;
    for (i = 0x100; i < 0x200; i++) {
        u16 *dst = &gPaletteBuffer[i];
        u16 *src = &gPaletteBackup[i];
        *dst = (((*src & 0x1F) * inv + (color & 0x1F) * blend) >> 5) |
               ((((*src & 0x3E0) * inv + (color & 0x3E0) * blend) >> 5) & 0x3E0) |
               ((((*src & 0x7C00) * inv + (color & 0x7C00) * blend) >> 5) & 0x7C00);
    }
    gVBlankOnceCallback = upload_palette_buffers;
}

void unpack_item_inventory_to_buffer(void) {
    u16 n = 0;
    s16 i;
    for (i = 0; i < 64; i++) {
        u8 owned = gItemInventory[i][0] & 0x80;
        if (owned) {
            ((struct ItemListEntry *)0x02040000)[i].id = gItemInventory[i][0] & 0x7F;
            ((struct ItemListEntry *)0x02040000)[i].count = gItemInventory[0][i * 2 + 1];
            n++;
        } else
            ((struct ItemListEntry *)0x02040000)[i].count = owned;
    }
    gMenuWork->item_count = n;
}

void update_battle_medapart_icons(void) {
    u16 icon_tile_top, icon_tile_bottom;
    s32 n = 5;
    u8 ids[n];
    u8 counts[n];
    s8 i;

    for (i = 0; i < n; i++) {
        struct ItemListEntry *list = (struct ItemListEntry *)0x02040000;
        ids[i] = list[gMenuWork->list_top + i].id;
        counts[i] = list[gMenuWork->list_top + i].count;
    }
    for (i = 0; i < n; i++) {
        disable_sprites(i * 16, 0x10);
        clear_item_list_map_run(0x18, i * 2 + 3, 3);
        clear_item_list_map_run(0x18, i * 2 + 4, 3);
    }
    icon_tile_top = *(u16 *)(BG_VRAM + 0xF0EE);
    icon_tile_bottom = *(u16 *)(BG_VRAM + 0xF12E);
    for (i = 0; i < n; i++) {
        if (counts[i]) {
            memcpy_bytes_0803F63C((void *)gItemNames[ids[i]], gTextArgBuffer, 0x11);
            render_text_sprites_08040DB8(gTextArgBuffer, i * 15, 0xC, i * 2 + 3, 7, 8, 1, 2);
            draw_number_2digits_tall(counts[i], 0x18, i * 2 + 3);
            *((u16 *)(BG_VRAM + 0xF02E) + ((i * 2 + 3) << 5)) = icon_tile_top;
            *((u16 *)(BG_VRAM + 0xF02E) + ((i * 2 + 4) << 5)) = icon_tile_bottom;
            gSpriteEntries[i + 0x55].flags |= SPRITE_FLAG_VISIBLE;
            gSpriteEntries[i + 0x55].frame = item_is_usable(ids[i]) ? 0x21 : 0x22;
        } else {
            u16 *map = (u16 *)(BG_VRAM + 0xF02E);
            u16 *tile;
            tile = map + ((i * 2 + 3) << 5);
            *tile = 0;
            tile = map + 1 + ((i * 2 + 3) << 5);
            *tile = 0;
            tile = map + 2 + ((i * 2 + 3) << 5);
            *tile = 0;
            tile = map + ((i * 2 + 4) << 5);
            *tile = 0;
            tile = map + 1 + ((i * 2 + 4) << 5);
            *tile = 0;
            tile = map + 2 + ((i * 2 + 4) << 5);
            *tile = 0;
            gSpriteEntries[i + 0x55].flags &= ~SPRITE_FLAG_VISIBLE;
        }
    }
    item_menu_draw_page_numbers();
}

void item_menu_set_cursor_pos(struct SpriteEntry *sprite) {
    sprite->x = 0x54;
    sprite->y = (u8)(gMenuWork->item_cursor % 5) * 16 + 0x1C;
}

void shop_build_sell_list(void) {
    u8 kind = gMenuWork->part_kind;
    s32 i, row;
    u8 n;
    u32 *price;
    u8 *pd;
    {
        u8 zero = 0;
        for (i = 0x77; i >= 0; i--)
            ((struct ShopSellEntry *)0x02040000)[i].count = zero;
    }
    row = kind * 240;
    i = 0;
    n = 0;
    pd = (u8 *)0x0300052E;     // &gGameWork.partAbility (the symbol form does not match)
    price = (u32 *)0x02040004; // &((struct ShopSellEntry *)0x02040000)->price
    for (; i <= 0x77; i++) {
        if (gMedapartInventory[row + i * 2] > gMedapartInventory[row + i * 2 + 1]) {
            struct ShopSellEntry *entry = &((struct ShopSellEntry *)0x02040000)[n];
            entry->id = i;
            entry->count = gMedapartInventory[row + i * 2] - gMedapartInventory[row + i * 2 + 1];
            load_part_data(i, kind, pd);
            entry->gender = pd[3];
            price[n * 2] = pd[0xB] * 100;
            n++;
        }
    }
    gMenuWork->list_count = n;
}

void load_battle_sprite_tiles(u32 id, s32 kind, s32 slot) {
    switch (kind) {
    case 0:
        lz_decompress_dispatch(gMedabotPartSpriteTiles[((id << 2) + (id << 1))],
                               (void *)(slot * 0x80 + (OBJ_VRAM0 + 0x3340)));
        break;
    case 1:
        lz_decompress_dispatch(gMedabotPartSpriteTiles[((id << 2) + (id << 1)) + 1],
                               (void *)(slot * 0x80 + (OBJ_VRAM0 + 0x3340)));
        break;
    case 2:
        lz_decompress_dispatch(gMedabotPartSpriteTiles[((id << 2) + (id << 1)) + 3],
                               (void *)(slot * 0x80 + (OBJ_VRAM0 + 0x3340)));
        break;
    case 3:
        lz_decompress_dispatch(gMedabotPartSpriteTiles[((id << 2) + (id << 1)) + 5],
                               (void *)(slot * 0x80 + (OBJ_VRAM0 + 0x3340)));
        break;
    }
    gSpriteEntries[slot + 0x6E].palette = gMedabotSpritePalettes[id] + 4;
}

void render_battle_medapart_list(u32 mode) {
    s32 n = 4;
    u8 ids[n];
    u8 counts[n];
    u8 genders[n];
    u32 prices[n];
    u8 kind = gMenuWork->part_kind;
    s32 i;
    s32 first;

    first = gListScrollTop;
    for (i = 0; i < n; i++) {
        ids[i] = ((struct ShopSellEntry *)0x02040000)[first].id;
        counts[i] = ((struct ShopSellEntry *)0x02040000)[first].count;
        genders[i] = ((struct ShopSellEntry *)0x02040000)[first].gender;
        prices[i] = ((struct ShopSellEntry *)0x02040000)[first].price;
        if (mode)
            prices[i] /= 2;
        first++;
    }
    for (i = 0; i < n; i++) {
        disable_sprites(i * 14 + 13, 14);
        clear_item_list_map_run(0xC, i * 2 + 10, 3);
        clear_item_list_map_run(0xC, i * 2 + 11, 3);
        disable_sprites(i * 7 + 0x45, 7);
    }
    for (i = 0; i < n; i++) {
        if (mode == 0) {
            if (gMenuWork->list_count > i) {
                render_text_sprites_08040DB8((u8 *)gMedapartNames[0][ids[i] * 4 + kind], i * 14 + 13, 2, i * 2 + 10, 14,
                                             13, 1, 1);
                draw_number_tall(counts[i], 2, 13, i * 2 + 10, 5, BGCNT_SCREEN_BLOCK(REG_BG1CNT));
                gSpriteEntries[i + 0x6A].flags |= SPRITE_FLAG_VISIBLE;
                gSpriteEntries[i + 0x6A].frame = genders[i] + 0x1B;
                gSpriteEntries[i + 0x6E].flags |= SPRITE_FLAG_VISIBLE;
                load_battle_sprite_tiles(ids[i], kind, i);
                divide_by_10000(gTextArgBuffer, prices[i]);
                render_text_sprites_08040DB8(gTextArgBuffer, i * 7 + 0x45, 0x12, i * 2 + 10, 7, 13, 2, 1);
            } else
                break;
        } else {
            if (counts[i]) {
                render_text_sprites_08040DB8((u8 *)gMedapartNames[0][ids[i] * 4 + kind], i * 14 + 13, 2, i * 2 + 10, 14,
                                             13, 1, 1);
                draw_number_tall(counts[i], 2, 13, i * 2 + 10, 5, BGCNT_SCREEN_BLOCK(REG_BG1CNT));
                gSpriteEntries[i + 0x6A].flags |= SPRITE_FLAG_VISIBLE;
                gSpriteEntries[i + 0x6A].frame = genders[i] + 0x1B;
                gSpriteEntries[i + 0x6E].flags |= SPRITE_FLAG_VISIBLE;
                load_battle_sprite_tiles(ids[i], kind, i);
                divide_by_10000(gTextArgBuffer, prices[i]);
                render_text_sprites_08040DB8(gTextArgBuffer, i * 7 + 0x45, 0x12, i * 2 + 10, 7, 13, 2, 1);
            } else
                break;
        }
    }
    divide_by_10000(gTextArgBuffer, gMenuWork->total);
    render_text_sprites_08040DB8(gTextArgBuffer, 0x61, 0x13, 5, 7, 12, 2, 0);
}

static void clear_item_list_map_run(s32 x, s32 y, s32 n) {
    u16 *base = (u16 *)(BG_VRAM + 0xB000) + x;
    u16 *dst = base + y * 32;
    u16 i;
    for (i = 0; i < n; i++)
        *dst++ = 0;
}

void item_menu_draw_page_numbers(void) {
    draw_number_3digits((u8)(gMenuWork->item_cursor / 5) + 1, 2, 3);
    draw_number_3digits((gMenuWork->item_count - 1) / 5 + 1, 5, 3);
}

// guess: SELECT reorder, swaps the marked item (swap_from) with the cursor item (item_cursor)
void swap_inventory_items(void) {
    memswap(gItemInventory[gMenuWork->swap_from], gItemInventory[gMenuWork->item_cursor], 2);
}

void item_menu_update_swap_marker(struct SpriteEntry *attr) {
    struct MenuWork *w = gMenuWork;
    if (w->swap_pending) {
        if (w->swap_from >= w->list_top && w->swap_from < w->list_top + 5)
            attr->flags |= SPRITE_FLAG_VISIBLE;
        else
            attr->flags &= (u16)~SPRITE_FLAG_VISIBLE;
    }
}

bool32 item_is_usable(u32 id) {
    bool32 usable = FALSE;
    if (gItemUsable[id] == 1)
        usable = TRUE;
    return usable;
}
