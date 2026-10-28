// Item and Medapart list drawing shared by the item menu (menu/item_menu.c) and the shop screens: unpack the
// item inventory into a list buffer, Medapart icons and page numbers, the shop sell list, swapping entries.
// Its callers are in the mode-2 screens; uses engine/ sprite and tilemap helpers.
#include "global.h"

static void clear_item_list_map_run(s32 x, s32 y, s32 n);

static void upload_palette_buffers(void) {
    CpuFastSet(gPaletteBuffer, (void *)OBJ_PLTT, 0x80);
    CpuFastSet(gPaletteBufferBg, (void *)PLTT, 0x80);
}

static void obj_palette_blend_to_color(u16 color, s32 t, u32 pal) {
    u32 inv;
    u32 i;

    if (t < 0)
        t = 0;
    if (t > 32)
        t = 32;
    inv = 32 - t;
    for (i = 0; i < 0x100; i++) {
        if (i >= pal * 16 && i < (pal + 1) * 16) {
            gPaletteBuffer[i] = (((color & 0x1F) * t + inv * (gPaletteBackup[i] & 0x1F)) >> 5) |
                                ((((color & 0x3E0) * t + inv * (gPaletteBackup[i] & 0x3E0)) >> 5) & 0x3E0) |
                                ((((color & 0x7C00) * t + inv * (gPaletteBackup[i] & 0x7C00)) >> 5) & 0x7C00);
        } else {
            gPaletteBuffer[i] = gPaletteBackup[i];
        }
    }
    gVBlankOnceCallback = upload_palette_buffers;
}

static void bg_palettes_blend_to_color(u16 color, s32 t) {
    u32 inv;
    u32 i;

    if (t < 0)
        t = 0;
    if (t > 32)
        t = 32;
    inv = 32 - t;
    for (i = 0x100; i < 0x200; i++) {
        u16 *d = &gPaletteBuffer[i];
        u16 *s = &gPaletteBackup[i];
        *d = (((*s & 0x1F) * inv + (color & 0x1F) * t) >> 5) |
             ((((*s & 0x3E0) * inv + (color & 0x3E0) * t) >> 5) & 0x3E0) |
             ((((*s & 0x7C00) * inv + (color & 0x7C00) * t) >> 5) & 0x7C00);
    }
    gVBlankOnceCallback = upload_palette_buffers;
}

void unpack_item_inventory_to_buffer(void) {
    u16 n = 0;
    s16 i;
    for (i = 0; i < 64; i++) {
        u8 f = gItemInventory[i][0] & 0x80;
        if (f) {
            ((struct ItemListEntry *)0x02040000)[i].id = gItemInventory[i][0] & 0x7F;
            ((struct ItemListEntry *)0x02040000)[i].count = gItemInventory[0][i * 2 + 1];
            n++;
        } else
            ((struct ItemListEntry *)0x02040000)[i].count = f;
    }
    gMenuWork->item_count = n;
}

void update_battle_medapart_icons(void) {
    u16 t0, t1;
    s32 n = 5;
    u8 ids[n];
    u8 counts[n];
    s8 i;

    for (i = 0; i < n; i++) {
        struct ItemListEntry *l = (struct ItemListEntry *)0x02040000;
        ids[i] = l[gMenuWork->list_top + i].id;
        counts[i] = l[gMenuWork->list_top + i].count;
    }
    for (i = 0; i < n; i++) {
        clear_sprite_table_mask(i * 16, 0x10);
        clear_item_list_map_run(0x18, i * 2 + 3, 3);
        clear_item_list_map_run(0x18, i * 2 + 4, 3);
    }
    t0 = *(u16 *)0x0600F0EE;
    t1 = *(u16 *)0x0600F12E;
    for (i = 0; i < n; i++) {
        if (counts[i]) {
            memcpy_bytes_0803F63C((void *)gItemNames[ids[i]], gTextArgBuffer, 0x11);
            render_text_sprites_08040DB8(gTextArgBuffer, i * 15, 0xC, i * 2 + 3, 7, 8, 1, 2);
            draw_number_2digits_tall(counts[i], 0x18, i * 2 + 3);
            *((u16 *)0x0600F02E + ((i * 2 + 3) << 5)) = t0;
            *((u16 *)0x0600F02E + ((i * 2 + 4) << 5)) = t1;
            gSpriteEntries[i + 0x55].unk0 |= 0x4000;
            gSpriteEntries[i + 0x55].unk6 = item_is_usable(ids[i]) ? 0x21 : 0x22;
        } else {
            u16 *map = (u16 *)0x0600F02E;
            u16 *p;
            p = map + ((i * 2 + 3) << 5);
            *p = 0;
            p = map + 1 + ((i * 2 + 3) << 5);
            *p = 0;
            p = map + 2 + ((i * 2 + 3) << 5);
            *p = 0;
            p = map + ((i * 2 + 4) << 5);
            *p = 0;
            p = map + 1 + ((i * 2 + 4) << 5);
            *p = 0;
            p = map + 2 + ((i * 2 + 4) << 5);
            *p = 0;
            gSpriteEntries[i + 0x55].unk0 &= ~0x4000;
        }
    }
    item_menu_draw_page_numbers();
}

void item_menu_set_cursor_pos(struct SpriteEntry *sprite) {
    sprite->unk2 = 0x54;
    sprite->unk4 = (u8)(gMenuWork->item_cursor % 5) * 16 + 0x1C;
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
            struct ShopSellEntry *e = &((struct ShopSellEntry *)0x02040000)[n];
            e->id = i;
            e->count = gMedapartInventory[row + i * 2] - gMedapartInventory[row + i * 2 + 1];
            load_part_data(i, kind, pd);
            e->unk3 = pd[3];
            price[n * 2] = pd[0xB] * 100;
            n++;
        }
    }
    gMenuWork->list_count = n;
}

void load_battle_sprite_tiles(u32 id, s32 kind, s32 slot) {
    switch (kind) {
    case 0:
        lz_decompress_dispatch(gMedabotPartSpriteTiles[((id << 2) + (id << 1))], (void *)(slot * 0x80 + 0x06013340));
        break;
    case 1:
        lz_decompress_dispatch(gMedabotPartSpriteTiles[((id << 2) + (id << 1)) + 1],
                               (void *)(slot * 0x80 + 0x06013340));
        break;
    case 2:
        lz_decompress_dispatch(gMedabotPartSpriteTiles[((id << 2) + (id << 1)) + 3],
                               (void *)(slot * 0x80 + 0x06013340));
        break;
    case 3:
        lz_decompress_dispatch(gMedabotPartSpriteTiles[((id << 2) + (id << 1)) + 5],
                               (void *)(slot * 0x80 + 0x06013340));
        break;
    }
    gSpriteEntries[slot + 0x6E].unkA = gMedabotSpritePalettes[id] + 4;
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
        genders[i] = ((struct ShopSellEntry *)0x02040000)[first].unk3;
        prices[i] = ((struct ShopSellEntry *)0x02040000)[first].price;
        if (mode)
            prices[i] /= 2;
        first++;
    }
    for (i = 0; i < n; i++) {
        clear_sprite_table_mask(i * 14 + 13, 14);
        clear_item_list_map_run(0xC, i * 2 + 10, 3);
        clear_item_list_map_run(0xC, i * 2 + 11, 3);
        clear_sprite_table_mask(i * 7 + 0x45, 7);
    }
    for (i = 0; i < n; i++) {
        if (mode == 0) {
            if (gMenuWork->list_count > i) {
                render_text_sprites_08040DB8((u8 *)gMedapartNames[0][ids[i] * 4 + kind], i * 14 + 13, 2, i * 2 + 10, 14,
                                             13, 1, 1);
                draw_number_tall(counts[i], 2, 13, i * 2 + 10, 5, (REG_BG1CNT >> 8) & 0x1F);
                gSpriteEntries[i + 0x6A].unk0 |= 0x4000;
                gSpriteEntries[i + 0x6A].unk6 = genders[i] + 0x1B;
                gSpriteEntries[i + 0x6E].unk0 |= 0x4000;
                load_battle_sprite_tiles(ids[i], kind, i);
                divide_by_10000(gTextArgBuffer, prices[i]);
                render_text_sprites_08040DB8(gTextArgBuffer, i * 7 + 0x45, 0x12, i * 2 + 10, 7, 13, 2, 1);
            } else
                break;
        } else {
            if (counts[i]) {
                render_text_sprites_08040DB8((u8 *)gMedapartNames[0][ids[i] * 4 + kind], i * 14 + 13, 2, i * 2 + 10, 14,
                                             13, 1, 1);
                draw_number_tall(counts[i], 2, 13, i * 2 + 10, 5, (REG_BG1CNT >> 8) & 0x1F);
                gSpriteEntries[i + 0x6A].unk0 |= 0x4000;
                gSpriteEntries[i + 0x6A].unk6 = genders[i] + 0x1B;
                gSpriteEntries[i + 0x6E].unk0 |= 0x4000;
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
    u16 *base = (u16 *)0x0600B000 + x;
    u16 *p = base + y * 32;
    u16 i;
    for (i = 0; i < n; i++)
        *p++ = 0;
}

void item_menu_draw_page_numbers(void) {
    draw_number_3digits((u8)(gMenuWork->item_cursor / 5) + 1, 2, 3);
    draw_number_3digits((gMenuWork->item_count - 1) / 5 + 1, 5, 3);
}

// guess: SELECT reorder, swaps the marked item (unk13) with the cursor item (unkC)
void swap_inventory_items(void) {
    memswap(gItemInventory[gMenuWork->swap_from], gItemInventory[gMenuWork->item_cursor], 2);
}

void item_menu_update_swap_marker(struct SpriteEntry *attr) {
    struct MenuWork *w = gMenuWork;
    if (w->swap_pending) {
        if (w->swap_from >= w->list_top && w->swap_from < w->list_top + 5)
            attr->unk0 |= 0x4000;
        else
            attr->unk0 &= 0xBFFF;
    }
}

bool32 item_is_usable(u32 id) {
    bool32 r = FALSE;
    if (gItemUsable[id] == 1)
        r = TRUE;
    return r;
}
