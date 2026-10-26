#include "global.h"

void sub_0805AB40(void) {
    CpuFastSet(gPaletteBuffer, (void *)OBJ_PLTT, 0x80);
    CpuFastSet(gPaletteBufferBg, (void *)PLTT, 0x80);
}

void sub_0805AB68(u16 color, s32 t, u32 pal) {
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
    gVBlankOnceCallback = sub_0805AB40;
}

void sub_0805AC4C(u16 color, s32 t) {
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
    gVBlankOnceCallback = sub_0805AB40;
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
    gUnk_03006F74->unk10 = n;
}

void update_battle_medapart_icons(void) {
    u16 t0, t1;
    s32 n = 5;
    u8 ids[n];
    u8 counts[n];
    s8 i;

    for (i = 0; i < n; i++) {
        struct ItemListEntry *l = (struct ItemListEntry *)0x02040000;
        ids[i] = l[gUnk_03006F74->unk11 + i].id;
        counts[i] = l[gUnk_03006F74->unk11 + i].count;
    }
    for (i = 0; i < n; i++) {
        clear_sprite_table_mask(i * 16, 0x10);
        sub_0805B3E4(0x18, i * 2 + 3, 3);
        sub_0805B3E4(0x18, i * 2 + 4, 3);
    }
    t0 = *(u16 *)0x0600F0EE;
    t1 = *(u16 *)0x0600F12E;
    for (i = 0; i < n; i++) {
        if (counts[i]) {
            memcpy_bytes_0803F63C((void *)gUnk_08484444[ids[i]], gUnk_030004DE, 0x11);
            render_text_sprites_08040DB8(gUnk_030004DE, i * 15, 0xC, i * 2 + 3, 7, 8, 1, 2);
            draw_number_2digits_tall(counts[i], 0x18, i * 2 + 3);
            *((u16 *)0x0600F02E + ((i * 2 + 3) << 5)) = t0;
            *((u16 *)0x0600F02E + ((i * 2 + 4) << 5)) = t1;
            gUnk_03002C30[i + 0x55].unk0 |= 0x4000;
            gUnk_03002C30[i + 0x55].unk6 = sub_0805B4B0(ids[i]) ? 0x21 : 0x22;
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
            gUnk_03002C30[i + 0x55].unk0 &= ~0x4000;
        }
    }
    item_menu_draw_page_numbers();
}

void item_menu_set_cursor_pos(struct Unk_03002C30 *sprite) {
    sprite->unk2 = 0x54;
    sprite->unk4 = (u8)(gUnk_03006F74->unkC % 5) * 16 + 0x1C;
}

void shop_build_sell_list(void) {
    u8 kind = gUnk_03006F74->unk19;
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
    pd = (u8 *)0x0300052E;     // &gUnk_03000440.unkEE (the symbol form does not match)
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
    gUnk_03006F74->unk20 = n;
}

void load_battle_sprite_tiles(u32 id, s32 kind, s32 slot) {
    switch (kind) {
    case 0:
        lz_decompress_dispatch(gUnk_083B1888[((id << 2) + (id << 1))], (void *)(slot * 0x80 + 0x06013340));
        break;
    case 1:
        lz_decompress_dispatch(gUnk_083B1888[((id << 2) + (id << 1)) + 1], (void *)(slot * 0x80 + 0x06013340));
        break;
    case 2:
        lz_decompress_dispatch(gUnk_083B1888[((id << 2) + (id << 1)) + 3], (void *)(slot * 0x80 + 0x06013340));
        break;
    case 3:
        lz_decompress_dispatch(gUnk_083B1888[((id << 2) + (id << 1)) + 5], (void *)(slot * 0x80 + 0x06013340));
        break;
    }
    gUnk_03002C30[slot + 0x6E].unkA = gUnk_083BEA14[id] + 4;
}

void render_battle_medapart_list(u32 mode) {
    s32 n = 4;
    u8 ids[n];
    u8 counts[n];
    u8 genders[n];
    u32 prices[n];
    u8 kind = gUnk_03006F74->unk19;
    s32 i;
    s32 first;

    first = gUnk_02023078;
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
        sub_0805B3E4(0xC, i * 2 + 10, 3);
        sub_0805B3E4(0xC, i * 2 + 11, 3);
        clear_sprite_table_mask(i * 7 + 0x45, 7);
    }
    for (i = 0; i < n; i++) {
        if (mode == 0) {
            if (gUnk_03006F74->unk20 > i) {
                render_text_sprites_08040DB8((u8 *)gUnk_083BB9CC[0][ids[i] * 4 + kind], i * 14 + 13, 2, i * 2 + 10, 14,
                                             13, 1, 1);
                draw_number_tall(counts[i], 2, 13, i * 2 + 10, 5, (REG_BG1CNT >> 8) & 0x1F);
                gUnk_03002C30[i + 0x6A].unk0 |= 0x4000;
                gUnk_03002C30[i + 0x6A].unk6 = genders[i] + 0x1B;
                gUnk_03002C30[i + 0x6E].unk0 |= 0x4000;
                load_battle_sprite_tiles(ids[i], kind, i);
                divide_by_10000(gUnk_030004DE, prices[i]);
                render_text_sprites_08040DB8(gUnk_030004DE, i * 7 + 0x45, 0x12, i * 2 + 10, 7, 13, 2, 1);
            } else
                break;
        } else {
            if (counts[i]) {
                render_text_sprites_08040DB8((u8 *)gUnk_083BB9CC[0][ids[i] * 4 + kind], i * 14 + 13, 2, i * 2 + 10, 14,
                                             13, 1, 1);
                draw_number_tall(counts[i], 2, 13, i * 2 + 10, 5, (REG_BG1CNT >> 8) & 0x1F);
                gUnk_03002C30[i + 0x6A].unk0 |= 0x4000;
                gUnk_03002C30[i + 0x6A].unk6 = genders[i] + 0x1B;
                gUnk_03002C30[i + 0x6E].unk0 |= 0x4000;
                load_battle_sprite_tiles(ids[i], kind, i);
                divide_by_10000(gUnk_030004DE, prices[i]);
                render_text_sprites_08040DB8(gUnk_030004DE, i * 7 + 0x45, 0x12, i * 2 + 10, 7, 13, 2, 1);
            } else
                break;
        }
    }
    divide_by_10000(gUnk_030004DE, gUnk_03006F74->unk1C);
    render_text_sprites_08040DB8(gUnk_030004DE, 0x61, 0x13, 5, 7, 12, 2, 0);
}

void sub_0805B3E4(s32 x, s32 y, s32 n) {
    u16 *base = (u16 *)0x0600B000 + x;
    u16 *p = base + y * 32;
    u16 i;
    for (i = 0; i < n; i++)
        *p++ = 0;
}

void item_menu_draw_page_numbers(void) {
    draw_number_3digits((u8)(gUnk_03006F74->unkC / 5) + 1, 2, 3);
    draw_number_3digits((gUnk_03006F74->unk10 - 1) / 5 + 1, 5, 3);
}

// guess: SELECT reorder, swaps the marked item (unk13) with the cursor item (unkC)
void swap_inventory_items(void) {
    memswap(gItemInventory[gUnk_03006F74->unk13], gItemInventory[gUnk_03006F74->unkC], 2);
}

void sub_0805B470(struct Unk_03002C30 *attr) {
    struct Unk_03006F74 *w = gUnk_03006F74;
    if (w->unk12) {
        if (w->unk13 >= w->unk11 && w->unk13 < w->unk11 + 5)
            attr->unk0 |= 0x4000;
        else
            attr->unk0 &= 0xBFFF;
    }
}

bool32 sub_0805B4B0(u32 id) {
    bool32 r = FALSE;
    if (gUnk_08483AC0[id] == 1)
        r = TRUE;
    return r;
}

// Eight sprites (spr[0..7]) bob on a sine wave around y = 80: sprite k uses phase t - (7 - k) * 0x80,
// amplitude gUnk_03006F74->unk15 (counts down each call), speed unk16 (counts up). Returns 1 once the
// amplitude is 0. The divide by d (not a constant) keeps the __divsi3 call of the original.
#define WAVE_X(a) (gUnk_080750E0[(a) & 0x3FF] / d * amp >> 3)
#define SET_WAVE_Y(k, a)                                                                                               \
    if (gUnk_080750E0[(a) & 0x3FF] < 0)                                                                                \
        spr[k].unk4 = WAVE_X(a) + mid;                                                                                 \
    else                                                                                                               \
        spr[k].unk4 = mid - WAVE_X(a)

u32 sub_0805B4C8(struct Unk_03002C30 *spr) {
    u32 done = 0;
    s32 d = 0x400;
    s32 mid = 80;
    u8 amp = gUnk_03006F74->unk15;
    u8 speed = gUnk_03006F74->unk16;
    s32 ph[8];

    ph[0] = gUnk_03006F74->unk2++ * speed;
    ph[1] = ph[0] - 0x80;
    ph[2] = ph[0] - 0x100;
    ph[3] = ph[0] - 0x180;
    ph[4] = ph[0] - 0x200;
    ph[5] = ph[0] - 0x280;
    ph[6] = ph[0] - 0x300;
    ph[7] = ph[0] - 0x380;

    if (gUnk_080750E0[ph[7] & 0x3FF] < 0)
        spr[0].unk4 = WAVE_X(ph[7]) + mid;
    else
        spr[0].unk4 = -WAVE_X(ph[7]) + mid;
    SET_WAVE_Y(1, ph[6]);
    SET_WAVE_Y(2, ph[5]);
    SET_WAVE_Y(3, ph[4]);
    SET_WAVE_Y(4, ph[3]);
    SET_WAVE_Y(5, ph[2]);
    SET_WAVE_Y(6, ph[1]);
    SET_WAVE_Y(7, ph[0]);
    if (gUnk_03006F74->unk15 == 0)
        done = 1;
    else {
        gUnk_03006F74->unk15--;
        gUnk_03006F74->unk16++;
    }
    return done;
}

u32 sub_0805B7A0(void) {
    struct Unk_03006F74 **pw = &gUnk_03006F74;
    struct Unk_03006F74 *w = *pw;
    u8 old = w->unk17;
    u32 off = old * 4 + gUnk_030057E0.unkC32 * 40;
    const u8 *tbl = w->unk18 ? gUnk_080AF674 : gUnk_080AF5FC;
    if (*(u8 *)&gNewKeys & 0x20)
        w->unk17 = tbl[off];
    else if (*(u8 *)&gNewKeys & 0x10)
        w->unk17 = tbl[off + 1];
    else if (*(u8 *)&gNewKeys & 0x40)
        w->unk17 = tbl[off + 2];
    else if (*(u8 *)&gNewKeys & 0x80)
        w->unk17 = tbl[off + 3];
    else
        goto none;
    play_sound_effect(old != (*pw)->unk17 ? 2 : 6);
    return 1;
none:
    return 0;
}

void update_battle_sprite_priority_flags(void) {
    if (gUnk_03006F74->unk20 > 4) {
        if ((*(u8 *)0x02023078) == 0)
            gUnk_03002C30[104].unk0 &= 0xBFFF;
        else if (gFrameCounter & 8)
            gUnk_03002C30[104].unk0 |= 0x4000;
        else
            gUnk_03002C30[104].unk0 &= 0xBFFF;
        if ((*(u8 *)0x02023078) + 3 == gUnk_03006F74->unk20 - 1)
            gUnk_03002C30[105].unk0 &= 0xBFFF;
        else if (gFrameCounter & 8)
            gUnk_03002C30[105].unk0 |= 0x4000;
        else
            gUnk_03002C30[105].unk0 &= 0xBFFF;
    }
}

void decompress_and_write_tilemap(const void *src, u32 bgcnt) {
    s32 w, h, x, y, cols;
    u16 *data, *dst;

    LZ77UnCompWram(src, gDecompressBuffer);
    w = *(u32 *)gDecompressBuffer;
    h = *(u32 *)0x02030004;
    data = (u16 *)(gDecompressBuffer + 0x10);
    dst = (u16 *)(((bgcnt >> 8) & 0x1F) * 0x800 + VRAM);
    cols = (((bgcnt & 0xC000) >> 14) & 1) ? 64 : 32;
    for (y = 0; y < h; y++) {
        for (x = 0; x < cols; x++) {
            if (x < w)
                *dst = *data++;
            dst++;
        }
    }
}

void tilemap_offset_tiles_and_palette(u32 tiles, u32 palette, u32 blk) {
    u16 add = tiles;
    // pinned so pal << 12 stays inside the loop (the original recomputes it every tile)
    register u32 pal asm("r6") = (u8)palette;
    u8 block = blk;
    u16 *p = (u16 *)(VRAM + block * 0x800);
    s32 i;

    for (i = 0; i < 0x400; i++) {
        u32 h;
        u32 x = *p;
        u32 t = (((x & 0x3FF) + add) & 0x3FF) | (x & 0xFC00);
        s32 mask = 0xF000;

        x = pal;
        h = (t & mask) + (x << 12);
        *p = (t & 0xFFF) | h;
        p++;
    }
}

void init_multiplayer_id(void) {
    u8 buf[4];
    memcpy_optimized(buf, gUnk_080AF6EC, 4);
    gUnk_03000B90 = (*(vu32 *)0x04000128 << 26) >> 30;
}

void sub_0805B9EC(u16 keys) {
    u16 *newKeys = &gNewKeys;
    u16 *prev = &gUnk_03006F74->unk78;
    *newKeys = keys & ~*prev;
    gReleasedKeys = *prev & ~keys;
    *prev = keys;
}

void sub_0805BA20(void) {
    if (gUnk_03005030 != 0) {
        if (gUnk_03000B90)
            sub_0805B9EC(gUnk_03005010.unk8[0][0]);
        else {
            register struct Unk_03005010 *p asm("r0") = &gUnk_03005010;
            p->unk4 = gHeldKeys;
            sub_0805B9EC(p->unk8[0][0]);
        }
    }
}

u16 sub_0805BA68(s16 x1, s16 y1, s16 x2, s16 y2) {
    s32 dx = x2 - x1;
    s32 dy = y2 - y1;
    return Sqrt(dx * dx + dy * dy);
}

void dispatch_game_state_handler_0805BA94(void) {
    gUnk_03005010.unk4 = gHeldKeys;
    gUnk_03005010.unk6 = 0;
    gUnk_03006F74 = (struct Unk_03006F74 *)&gUnk_03001800;
    if (gUnk_03005030 != 0 && (*(u32 *)&gUnk_03005010.unk19[3] & 0x00FFFF00)) {
        gGameMode = 0;
        gGameState = 10;
        gGameSubState = 0x10;
    } else {
        gUnk_08483B00[gGameState]();
    }
}

s16 sub_0805BB10(s16 step) {
    u16 a = step;
    s16 n;

    if (a > 0xA0)
        a = 0;
    REG_BLDCNT = 0x844;
    n = a;
    REG_BLDALPHA = gUnk_080AF6F0[n / 8] | 0x1000;
    REG_BLDY = 8;
    return n + 1;
}

void sub_0805BB64(u8 sel, u8 count) {
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

void sub_0805BBF8(u8 sel) {
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

void sub_0805BC6C(void) {
    s32 i, j;
    for (i = 0; i <= 2; i++) {
        u16 *p = (u16 *)(VRAM + (((REG_BG0CNT >> 8) & 0x1F) << 11)) + 0x167 + i * 96;
        for (j = 0; j < 16; j++) {
            *p = (*p & 0xFFF) | 0x8000;
            p++;
        }
    }
}

void sub_0805BCC0(u8 sel) {
    u8 cur[3] = {gUnk_03001788, gUnk_03001360, gUnk_03000B94};
    s32 i, j, k;
    for (i = 0; i <= 2; i++) {
        for (j = 0; j <= 2; j++) {
            u16 *p = (u16 *)(VRAM + 0xE + (((REG_BG0CNT >> 8) & 0x1F) << 11) + (i * 3 + 11) * 64);
            u16 mask = gUnk_080AF740[i][j];
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

void sub_0805BDC8(u8 a) {
    u16 buf[32];
    s32 i;
    a = a > 15 ? a - 16 : 0;
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
        r = (r - r2) * a / 32 + r2;
        g = (g - g2) * a / 32 + g2;
        b = (b - b2) * a / 32 + b2;
        buf[i] = (b << 10) | (g << 5) | r;
    }
    CpuSet(buf, (void *)0x05000140, 0x04000008);
}

void sub_0805BEA0(u8 sel, u8 f) {
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
                r = (r - r2) * f / 32 + r2;
                g = (g - g2) * f / 32 + g2;
                b = (b - b2) * f / 32 + b2;
                buf[i] = (b << 10) | (g << 5) | r;
            }
        }
        CpuSet(buf, (void *)(j * 0x40 + PLTT), 0x04000008);
    }
}

void sub_0805BF88(void) {
    gUnk_08483B78[gGameSubState]();
    gBg2Scroll.x++;
    gBg2Scroll.y++;
    if (gFrameCounter & 1) {
        gBg3Scroll.x++;
        gBg3Scroll.y++;
    }
}

void sub_0805BFDC(void) {
    u32 zero = 0;
    CpuFastSet(&zero, (void *)VRAM, 0x01006000);
    reset_bg_scroll();
    sub_08059D04();
    REG_DISPCNT = 0x60;
    init_blend_effect(gUnk_03006F74->unk50, 0x10, 0, -1, 0xC0);
    gGameSubState++;
}

void sub_0805C030(void) {
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
    gUnk_03006F74->unk36 = (size >> 5) - 1;
    lz_decompress_dispatch(gUnk_08784DA4, (void *)0x06010000);
    CpuFastSet(gUnk_0878E3F4, gPaletteBackupBg, 0x80);
    CpuFastSet(gUnk_0878E3F4, (void *)PLTT, 0x80);
    CpuFastSet(gUnk_084E2E58, gPaletteBackup, 0x80);
    CpuFastSet(gUnk_084E2E58, (void *)(PLTT + 0x200), 0x80);
    gUnk_03002C30[14].unk0 = 0x8000;
    gUnk_03002C30[14].unkB = one;
    gUnk_03002C30[14].unk1C = 2;
    gUnk_03002C30[14].unkA = 0;
    gUnk_03002C30[14].unk6 = 6;
    gUnk_03002C30[14].unk2 = 0x20;
    gUnk_03002C30[14].unk4 = 0x50;
    gUnk_03006F74->unk5 = 0;
    gGameSubState++;
}

void sub_0805C190(void) {
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
        gUnk_03006F74->unk5 = 1;
        gUnk_03006F74->unk4 = 1;
        gUnk_03001788 = 0;
        gUnk_03001360 = 0;
        gUnk_03000B94 = 0;
    } else {
        gUnk_03006F74->unk5 = ret;
        gUnk_03006F74->unk4 = ret;
        gUnk_03001784.unk0_0 = 1;
    }
    sub_0805BEA0(gUnk_03006F74->unk5, gFrameCounter & 0x1F);
    sub_0805BCC0(3);
    gGameSubState++;
}

void sub_0805C2C4(void) {
    if (blend_fade_step_08065598(gUnk_03006F74->unk50)) {
        gGameSubState++;
        gUnk_03006F74->unk3A = 0;
        gUnk_03006F74->unk3A = sub_0805BB10(0);
        REG_DISPCNT |= 0x400;
    }
}

void sub_0805C308(void) {
    struct Unk_03006F74 *w;

    gUnk_03006F74->unk3A = sub_0805BB10(gUnk_03006F74->unk3A);
    sub_0805BEA0(gUnk_03006F74->unk5, gFrameCounter & 0x1F);
    if (KEYS_LO(gNewKeys) & 0x40) {
        play_sound_effect(2);
        w = gUnk_03006F74;
        if (w->unk5 == w->unk4)
            w->unk5 = 2;
        else
            w->unk5--;
    }
    if (KEYS_LO(gNewKeys) & 0x80) {
        play_sound_effect(2);
        w = gUnk_03006F74;
        if (w->unk5 == 2)
            w->unk5 = w->unk4;
        else
            w->unk5++;
    }
    if (KEYS_LO(gNewKeys) & 1) {
        play_sound_effect(4);
        if (gUnk_03006F74->unk5 == 2) {
            gUnk_03006F74->unk5 = 0;
            gUnk_03006F74->unk2 = 20;
            sub_0805BDC8(gFrameCounter & 0x1F);
            sub_0805BBF8(gUnk_03006F74->unk5);
            sub_0805BCC0(gUnk_03006F74->unk5);
            sub_0805BEA0(3, 0);
            gUnk_03002C30[14].unk4 = gUnk_03006F74->unk5 * 24 + 0x50;
            gUnk_03002C30[14].unk0 |= 0x4000;
            gGameSubState++;
        } else {
            gUnk_03006F74->unk48 = 45;
            gGameSubState = 6;
        }
    }
}

// guess: title options menu input (rows: Robattle time limit gUnk_03001788, message skip gUnk_03001360,
// battle music gUnk_03000B94 with a preview); A / B leave the menu
void sub_0805C428(void) {
    gUnk_03006F74->unk3A = sub_0805BB10(gUnk_03006F74->unk3A);
    sub_08041C14(14, gFrameCounter, 32);
    sub_0805BDC8(gFrameCounter & 0x1F);
    sub_0805BB64(gUnk_03006F74->unk5, 20 - gUnk_03006F74->unk2);
    if (gUnk_03006F74->unk2)
        gUnk_03006F74->unk2--;

    if (KEYS_LO(gNewKeys) & 0x40) {
        play_song(1);
        play_sound_effect(2);
        if (gUnk_03006F74->unk5 == 0)
            gUnk_03006F74->unk5 = 2;
        else
            gUnk_03006F74->unk5--;
        if (gUnk_03006F74->unk5 == 2)
            play_song(gUnk_080AF752[gUnk_03000B94]);
        gUnk_03006F74->unk2 = 20;
    } else if (KEYS_LO(gNewKeys) & 0x80) {
        play_song(1);
        play_sound_effect(2);
        if (gUnk_03006F74->unk5 == 2)
            gUnk_03006F74->unk5 = 0;
        else
            gUnk_03006F74->unk5++;
        if (gUnk_03006F74->unk5 == 2)
            play_song(gUnk_080AF752[gUnk_03000B94]);
        gUnk_03006F74->unk2 = 20;
    } else {
        switch (gUnk_03006F74->unk5) {
        case 0:
            if (KEYS_LO(gNewKeys) & 0x20) {
                play_sound_effect(2);
                if (gUnk_03001788 == 0)
                    gUnk_03001788 = 2;
                else
                    gUnk_03001788--;
            }
            if (KEYS_LO(gNewKeys) & 0x10) {
                play_sound_effect(2);
                if (gUnk_03001788 == 2)
                    gUnk_03001788 = 0;
                else
                    gUnk_03001788++;
            }
            break;
        case 1:
            if (KEY_BITS(gNewKeys).left | KEY_BITS(gNewKeys).right) {
                play_sound_effect(2);
                gUnk_03001360 ^= 1;
            }
            break;
        case 2:
            if (KEYS_LO(gNewKeys) & 0x20) {
                if (gUnk_03000B94 == 0)
                    gUnk_03000B94 = 2;
                else
                    gUnk_03000B94--;
                play_song(gUnk_080AF752[gUnk_03000B94]);
            }
            if (KEYS_LO(gNewKeys) & 0x10) {
                if (gUnk_03000B94 == 2)
                    gUnk_03000B94 = 0;
                else
                    gUnk_03000B94++;
                play_song(gUnk_080AF752[gUnk_03000B94]);
            }
            break;
        }
        if (KEYS_LO(gNewKeys) & 0x30)
            sub_0805BCC0(gUnk_03006F74->unk5);
        if (KEY_BITS(gNewKeys).a | KEY_BITS(gNewKeys).b) {
            play_song(1);
            play_sound_effect(4);
            gUnk_03006F74->unk5 = 2;
            gUnk_03002C30[14].unk0 &= 0xBFFF;
            gGameSubState--;
            sub_0805BBF8(3);
            sub_0805BB64(3, 0);
            sub_0805BCC0(3);
        }
        return;
    }
    sub_0805BBF8(gUnk_03006F74->unk5);
    sub_0805BCC0(gUnk_03006F74->unk5);
    gUnk_03002C30[14].unk2 = 32;
    gUnk_03002C30[14].unk4 = gUnk_03006F74->unk5 * 24 + 0x50;
}

void sub_0805C6AC(void) {
    u8 *t = &gUnk_03006F74->unk48;
    if (*t) {
        u8 n = --*t;
        if (n)
            sub_0805BEA0(gUnk_03006F74->unk5, ((gUnk_03006F74->unk48 * 4) & 0x1F) <= 15 ? 0x20 : 0);
        else {
            copy_obj_palette_to_buffer();
            gUnk_03000440.unk84 = n;
        }
    } else if (!is_sound_playing_with_lock(4)) {
        struct Unk_03000440 *b = &gUnk_03000440;
        if (b->unk84 <= 8) {
            s32 w = 31;
            s32 c = (w << 10) | (w << 5) | w;
            blend_obj_palettes_to_color_0803F684(c, b->unk84 * 4, 0xFFFF);
            blend_obj_palettes_to_color_0803F998(c, b->unk84 * 4, 0xFFFF);
            b->unk84++;
        } else {
            REG_DISPCNT &= 0xFDFF;
            switch (gUnk_03006F74->unk5) {
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

void sub_0805C7A0(void) {
    s8 i;

    play_song(0);
    play_sound_effect(0);
    eeprom_setup_timer_irq();
    for (i = 0; i <= 15; i++)
        gUnk_03002B74[i] = 0xFE;
    gGameState = 28;
    gGameSubState = 0;
}

void sub_0805C7E8(void) {
    u32 zero = 0;

    play_song(0);
    play_sound_effect(0);
    gGameMode = 1;
    gGameState = 1;
    gGameSubState = zero;
    dispatch_by_index_0476e8(11);
}

void sub_0805C820(void) {
    if (gUnk_03006F74->unk0 != 32) {
        gUnk_03006F74->unk0++;
        REG_BLDY = gUnk_03006F74->unk0 >> 1;
    } else {
        gGameState = 9;
        gGameSubState = 0;
    }
}

void sub_0805C85C(void) {
    u32 zero = 0;

    CpuFastSet(&zero, (void *)VRAM, 0x01006000);
    clear_battle_sprite_slot(0, 0x80);
    reset_bg_scroll();
    REG_DISPCNT = 0x60;
    CpuFastSet(gUnk_084E2E38, &gPaletteBackup[0xF0], 8);
    lz_decompress_dispatch(gUnk_084C6A98, (void *)0x06017400);
    text_window_init(1, 2, 0);
    REG_DISPCNT |= 0x1000;
    gGameSubState++;
}

void load_rotation_grid_and_advance(void) {
    u8 buf[0x54];
    memcpy_optimized(buf, gUnk_080AF755, 0x53);
    if (run_message(buf)) {
        open_choice_menu(1, 0x16, 7);
        gGameSubState++;
    }
}

void sub_0805C90C(void) {
    if (poll_choice_menu()) {
        if (gUnk_03000440.unk2A == 0)
            gGameSubState++;
        else
            gGameSubState += 2;
    }
}

void sub_0805C940(void) {
    if (game_state_execute_handler_a())
        dispatch_by_index_0476e8(10);
}

void advance_substate_with_fade(void) {
    if (game_state_execute_handler_a()) {
        gGameSubState++;
        init_blend_effect(gUnk_03006F74->unk50, 0, 0, 1, 0xC0);
    }
}

void fade_step_and_transition_to_mode3(void) {
    if (blend_fade_step_08065598(gUnk_03006F74->unk50)) {
        gGameState = 3;
        gGameSubState = 0;
    }
}

// guess: options screen sub-states (gUnk_080AF7A8); the inherited name is probably wrong
void dispatch_rotation_menu_substate(void) {
    struct FuncTable6 t = gUnk_080AF7A8;
    t.f[gGameSubState]();
}

void item_menu_update(void) {
    gItemMenuStates[gGameSubState]();
    if (gFrameCounter & 1) {
        gBg3Scroll.x++;
        gBg3Scroll.y++;
    }
}

void sub_0805CA28(u32 a) {
    struct Unk_03006F74 *w = gUnk_03006F74;
    if (w->unk12) {
        if (w->unk13 >= w->unk11 && w->unk13 < w->unk11 + 5) {
            if (a & 1)
                gUnk_03002C30[84].unk0 &= 0xBFFF;
            else
                gUnk_03002C30[84].unk0 |= 0x4000;
        } else
            gUnk_03002C30[84].unk0 &= 0xBFFF;
    }
}

void sub_0805CA94(void) {
    u32 zero = 0;
    CpuFastSet(&zero, gUnk_03006F74, 0x01000100);
    reset_bg_scroll();
    REG_DISPCNT = 0x160;
    gGameSubState++;
}

static inline void *vram_at(u32 off) {
    return (void *)(0x06004000 + off);
}

void item_menu_load_graphics(void) {
    u32 size;
    u8 i;
    vu16 *bg1, *bg2, *bg3;
    u16 v;

    bg1 = &REG_BG1CNT;
    v = 0x1E05;
    *bg1 = v;
    bg2 = &REG_BG2CNT;
    v = 0x1C06;
    *bg2 = v;
    bg3 = &REG_BG3CNT;
    v = 0x3D07;
    *bg3 = v;
    decompress_and_write_tilemap(gUnk_0878C484, *bg1);
    decompress_and_write_tilemap(gUnk_0878C5B4, *bg2);
    decompress_and_write_tilemap(gUnk_0878C750, *bg3);
    size = dma3_copy_or_decompress(gUnk_0878B078, gDecompressBuffer);
    CpuCopy16(gDecompressBuffer, vram_at(0), size);
    lz_decompress_dispatch(gUnk_08784CB0, vram_at(size));
    gUnk_03006F74->unk36 = (size >> 5) - 1;
    lz_decompress_dispatch(gUnk_08784DA4, (void *)0x06010000);
    for (i = 0; i <= 1; i++) {
        gUnk_03002C30[i + 0x51].unk0 = 0x8000;
        gUnk_03002C30[i + 0x51].unk1C = 2;
        gUnk_03002C30[i + 0x51].unk2 = i * 40 + 0x18;
        gUnk_03002C30[i + 0x51].unk4 = 0x18;
        gUnk_03002C30[i + 0x51].unkA = 0;
        gUnk_03002C30[i + 0x51].unk6 = 5;
    }
    gUnk_03002C30[0x51].unk0 |= 0x1000;
    for (i = 0; i <= 1; i++) {
        gUnk_03002C30[i + 0x53].unk0 = 0x8000;
        gUnk_03002C30[i + 0x53].unk1C = 2;
        gUnk_03002C30[i + 0x53].unkA = 0;
        gUnk_03002C30[i + 0x53].unk6 = 6;
    }
    for (i = 0; i <= 4; i++) {
        gUnk_03002C30[i + 0x55].unk0 = 0x8000;
        gUnk_03002C30[i + 0x55].unk1C = 2;
        gUnk_03002C30[i + 0x55].unkA = 0xE;
        gUnk_03002C30[i + 0x55].unk6 = 7;
        gUnk_03002C30[i + 0x55].unk2 = 0xE0;
        gUnk_03002C30[i + 0x55].unk4 = i * 16 + 0x20;
    }
    lz_decompress_dispatch(gUnk_084C6A98, (void *)0x06017400);
    gGameSubState++;
}

void item_menu_init(void) {
    u32 zero;
    struct Unk_03006F74 *w;

    gUnk_03006F74->unk6 = 0;
    gUnk_03006F74->unkC = 0;
    gUnk_03006F74->unk11 = 0;
    unpack_item_inventory_to_buffer();
    update_battle_medapart_icons();
    if (gUnk_03006F74->unk10) {
        gUnk_03002C30[0x53].unk0 |= 0x4000;
        item_menu_set_cursor_pos(&gUnk_03002C30[0x53]);
    }
    w = gUnk_03006F74;
    if ((w->unk10 - 1) / 5) {
        gUnk_03002C30[0x51].unk0 |= 0x4000;
        gUnk_03002C30[0x52].unk0 |= 0x4000;
    }
    w->unk12 = 0;
    CpuFastSet(gUnk_0850DCF8, gPaletteBackup, 0x80);
    CpuFastSet(gUnk_084E2E58, gPaletteBackup, 8);
    CpuFastSet(gUnk_080AF7C0, (void *)0x0202F9C0, 8);
    CpuFastSet(gUnk_0878AE78, gPaletteBackupBg, 0x80);
    zero = 0;
    CpuFastSet(&zero, (void *)(PLTT + 0x1A0), 0x01000008);
    gUnk_03000440.unk84 = 0;
    REG_DISPCNT |= 0x200;
    REG_DISPCNT |= 0x400;
    REG_DISPCNT |= 0x800;
    REG_DISPCNT |= 0x1000;
    gGameSubState++;
}

void item_menu_fade_in(void) {
    struct Unk_03000440 *b = &gUnk_03000440;
    if (b->unk84 <= 8) {
        if (gUnk_03006F74->unk6 == 0)
            blend_obj_palettes_to_color_0803F684(0, 0x20 - b->unk84 * 4, 0x3FFF);
        else
            blend_obj_palettes_to_color_0803F684(0, 0x20 - b->unk84 * 4, 0xFFFF);
        blend_obj_palettes_to_color_0803F998(0, 0x20 - gUnk_03000440.unk84 * 4, 0xFFFF);
        gUnk_03000440.unk84++;
    } else {
        text_window_init(1, 2, 0);
        gGameSubState++;
    }
}

void item_menu_show_description(void) {
    u8 id;
    struct Unk_03006F74 *w;
    sub_0805CA28(gFrameCounter);
    sub_08041C14(0x53, gFrameCounter, 0x54);
    w = gUnk_03006F74;
    if (w->unk10) {
        struct ItemListEntry *l = (struct ItemListEntry *)0x02040000;
        id = l[w->unkC].id;
    } else
        id = 0x3F;
    if (run_message(gItemDescriptions[id]))
        gGameSubState++;
}

#define ITEM_LIST ((struct ItemListEntry *)0x02040000)

// guess: item_menu_handle_input (5 items per page; D-pad moves / pages, SELECT reorders, A uses, B closes)
void sub_0805CE4C(void) {
    struct Unk_03006F74 *w;
    struct Unk_03006F74 *w2;
    struct Unk_03006F74 *w3;
    struct ItemListEntry *list;
    struct Unk_03006D38 *sel;
    u8 n = 5;
    u8 cnt;

    sub_08041C14(0x53, gFrameCounter, 0x54);
    if ((gUnk_03006F74->unk10 - 1) / 5) {
        if ((gFrameCounter >> 4) & 1) {
            gUnk_03002C30[0x51].unk0 |= 0x4000;
            gUnk_03002C30[0x52].unk0 |= 0x4000;
        } else {
            gUnk_03002C30[0x51].unk0 &= 0xBFFF;
            gUnk_03002C30[0x52].unk0 &= 0xBFFF;
        }
    }

    w = gUnk_03006F74;
    if (w->unk10 > 1) {
        if (KEYS_LO(gRepeatKeys) & 0x40) {
            if (w->unkC == w->unk11) {
                if ((u8)(w->unk11 / n) == (u8)(w->unk10 / n))
                    w->unkC = w->unk11 + w->unk10 % n - 1;
                else
                    w->unkC = n + w->unk11 - 1;
            } else
                w->unkC--;
            goto moved;
        } else if (KEYS_LO(gRepeatKeys) & 0x80) {
            if ((u8)(w->unk11 / n) == (u8)(w->unk10 / n)) {
                if (w->unkC == w->unk11 + (u8)(w->unk10 % n) - 1)
                    w->unkC = w->unk11;
                else
                    w->unkC++;
            } else {
                if (w->unkC == w->unk11 + n - 1)
                    w->unkC = w->unk11;
                else
                    w->unkC++;
            }
            goto moved;
        } else if ((cnt = w->unk10) >= n + 1) {
            if (KEYS_LO(gRepeatKeys) & 0x10) {
                if (w->unk11 + n >= cnt)
                    w->unk11 = 0;
                else
                    w->unk11 += n;
            } else if (KEYS_LO(gRepeatKeys) & 0x20) {
                if (w->unk11 >= n)
                    w->unk11 -= n;
                else if ((u8)(cnt % n) == 0)
                    w->unk11 = cnt - n;
                else
                    w->unk11 = cnt / n * n;
            } else
                goto other;
            gUnk_03006F74->unkC = gUnk_03006F74->unk11;
            update_battle_medapart_icons();
            sub_0805B470(&gUnk_03002C30[0x54]);
            goto moved;
        }
    }

other:
    w2 = gUnk_03006F74;
    if (w2->unk12) {
        sub_0805CA28(gFrameCounter);
        if (KEYS_LO(gNewKeys) & 2) {
            gUnk_03002C30[0x54].unk0 &= 0xBFFF;
            gUnk_03006F74->unk12 = 0;
            goto moved;
        }
        if (!(KEYS_LO(gNewKeys) & 5))
            return;
        gUnk_03002C30[0x54].unk0 &= 0xBFFF;
        gUnk_03006F74->unk12 = 0;
        swap_inventory_items();
        unpack_item_inventory_to_buffer();
        update_battle_medapart_icons();
        goto moved;
    }
    if (w2->unk10 > 1 && (KEYS_LO(gNewKeys) & 4)) {
        w2->unk2 = 0;
        play_sound_effect(2);
        init_fade_sprite_and_start_fade();
    }
    w3 = gUnk_03006F74;
    if (w3->unk12)
        return;
    if (KEYS_LO(gNewKeys) & 1) {
        if (w3->unk10 == 0)
            goto cancel;
        sel = &gUnk_03006D38;
        list = ITEM_LIST;
        sel->unk4 = list[w3->unkC].id;
        switch ((s32)sub_08048914(list[w3->unkC].id)) {
        case 2:
        case 3:
        case 4:
            sub_0803FB0C();
            play_sound_effect(6);
            gUnk_03002C30[0x51].unk0 &= 0xBFFF;
            gUnk_03002C30[0x52].unk0 &= 0xBFFF;
            gGameSubState = 9;
            return;
        case 1:
            play_sound_effect(4);
            switch (ITEM_LIST[gUnk_03006F74->unkC].id) {
            case 0:
                gUnk_03006F74->unk0 = 0;
                gGameSubState = 0xB;
                return;
            case 1:
                gUnk_030057E0.unkC5C = 3;
                break;
            case 5:
                gUnk_030057E0.unkC5C = 4;
                break;
            case 12:
                gUnk_030057E0.unkC5C = 5;
                break;
            case 13:
                gUnk_030057E0.unkC5C = 8;
                break;
            case 19:
                gUnk_030057E0.unkC5C = 6;
                break;
            case 39:
                gUnk_030057E0.unkC5C = 7;
                break;
            case 40:
                gUnk_030057E0.unkC5C = 0xD;
                break;
            default:
                dispatch_by_index_0476e8(4);
                return;
            }
            gUnk_03000440.unk84 = 0;
            gGameSubState = 0xD;
            return;
        case 0:
            play_sound_effect(6);
            return;
        }
    }
    if (KEYS_LO(gNewKeys) & 2) {
    cancel:
        play_sound_effect(5);
        copy_obj_palette_to_buffer();
        gUnk_03000440.unk84 = 0;
        gGameSubState = 7;
    }
    return;

moved:
    play_sound_effect(2);
    sub_0803FB0C();
    item_menu_set_cursor_pos(&gUnk_03002C30[0x53]);
    gGameSubState = 4;
    sub_0805CA28(gFrameCounter);
}

// guess: starts the SELECT reorder: shows the second cursor (sprite 0x54) on the cursor item
void init_fade_sprite_and_start_fade(void) {
    struct Unk_03006F74 **pw = &gUnk_03006F74;
    item_menu_set_cursor_pos(&gUnk_03002C30[0x54]);
    gUnk_03002C30[0x54].unk0 |= 0x4000;
    gUnk_03002C30[0x54].unk2++;
    gUnk_03002C30[0x54].unk4++;
    (*pw)->unk12 = 1;
    (*pw)->unk13 = (*pw)->unkC;
}

void sub_0805D378(void) {
    if (game_state_execute_handler_a())
        gGameSubState++;
}

void sub_0805D394(void) {
    struct Unk_03000440 *b = &gUnk_03000440;
    if (b->unk84 <= 8) {
        blend_obj_palettes_to_color_0803F684(0, b->unk84 * 4, 0x3FFF);
        blend_obj_palettes_to_color_0803F998(0, b->unk84 * 4, 0xFFFF);
        b->unk84++;
    } else {
        REG_DISPCNT &= 0xFDFF;
        REG_DISPCNT &= 0xFBFF;
        clear_battle_sprite_slot(0, 0x80);
        gGameMode = 0;
        gGameState = 1;
        gGameSubState = 0x10;
    }
}

void sub_0805D418(void) {
    if (run_message(gUnk_08485788[8]))
        gGameSubState++;
}

void check_ab_press_play_confirm_sound(void) {
    if (*(u8 *)&gNewKeys & 3) {
        play_sound_effect(2);
        sub_0803FB0C();
        gGameSubState = 4;
    }
}

void sub_0805D468(void) {
    REG_BLDCNT = 0x2FF;
    gGameSubState++;
}

void sub_0805D488(void) {
    struct Unk_03006F74 *w = gUnk_03006F74;
    if (w->unk0 != 8) {
        REG_BLDY = ++w->unk0 * 2;
    } else {
        REG_DISPCNT &= 0xFDFF;
        REG_DISPCNT &= 0xFBFF;
        clear_battle_sprite_slot(0, 0x80);
        gUnk_03006F74->unk6 = 1;
        gGameState = 10;
        gGameSubState = 0;
    }
}

void sub_0805D4F0(void) {
    if (game_state_execute_handler_a())
        gGameSubState++;
}

void sub_0805D50C(void) {
    struct Unk_03000440 *b = &gUnk_03000440;
    if (b->unk84 <= 8) {
        blend_obj_palettes_to_color_0803F684(0, b->unk84 * 4, 0xFFFF);
        blend_obj_palettes_to_color_0803F998(0, b->unk84 * 4, 0xFFFF);
        b->unk84++;
    } else {
        u32 zero;
        REG_DISPCNT &= 0xFDFF;
        zero = 0;
        CpuFastSet(&zero, (void *)VRAM, 0x01006000);
        dispatch_by_index_0476e8(4);
    }
}

void sub_0805D57C(u16 a) {
    gUnk_03002C30[0].unk6 = gUnk_080AF7E0[a & 3];
}

void save_screen_update(void) {
    gSaveScreenStates[gGameSubState]();
    if (gFrameCounter & 1) {
        gBg3Scroll.x++;
        gBg3Scroll.y++;
    }
    sub_0805D57C(gFrameCounter >> 3);
}

void sub_0805D5E8(void) {
    u32 zero = 0;
    CpuFastSet(&zero, gUnk_03006F74, 0x01000100);
    reset_bg_scroll();
    REG_DISPCNT = 0x160;
    gGameSubState++;
}

void sub_0805D628(void) {
    u32 size;
    u16 v;
    vu16 *bg1, *bg2, *bg3;

    bg1 = &REG_BG1CNT;
    v = 0x1E05;
    *bg1 = v;
    bg2 = &REG_BG2CNT;
    v -= 0xFF;
    *bg2 = v;
    bg3 = &REG_BG3CNT;
    v = 0x3C07;
    *bg3 = v;
    decompress_and_write_tilemap(gUnk_0878DE10, *bg1);
    decompress_and_write_tilemap(gUnk_0878DFE0, *bg2);
    decompress_and_write_tilemap(gUnk_0878E104, *bg3);
    size = dma3_copy_or_decompress(gUnk_0878CC64, gDecompressBuffer);
    CpuCopy16(gDecompressBuffer, vram_at(0), size);
    lz_decompress_dispatch(gUnk_08784CB0, vram_at(size));
    gUnk_03006F74->unk36 = (size >> 5) - 1;
    lz_decompress_dispatch(gUnk_08784DA4, (void *)0x06010000);
    gUnk_03002C30[0].unk0 = 0xC000;
    gUnk_03002C30[0].unk1C = 2;
    gUnk_03002C30[0].unkA = 0;
    gUnk_03002C30[0].unk6 = 0x23;
    gUnk_03002C30[0].unk2 = 0xD0;
    gUnk_03002C30[0].unk4 = 0x18;
    gGameSubState++;
}

// guess: save screen info panel (Medal / Medapart counts, play time, Robattle counters, money, name).
// draw_number is called through a cast: this caller passes untruncated ints, the header has u8 / u16 params.
void sub_0805D6F8(void) {
    s32 n;
    s32 i;

    n = 0;
    for (i = 0; i < 30; i++) {
        if (gUnk_03000BE0[i].unk0 & 0x80)
            n++;
    }
    ((void (*)(s32, s32, s32, s32, s32, s32))draw_number)(n, 2, 10, 4, 10, (REG_BG1CNT >> 8) & 0x1F);
    n = 0;
    for (i = 0; i < 480; i++) {
        if (gMedapartInventory[i * 2] != 0)
            n++;
    }
    ((void (*)(s32, s32, s32, s32, s32, s32))draw_number)(n, 3, 9, 6, 11, (REG_BG1CNT >> 8) & 0x1F);
    n = gUnk_03002B70.unk18 / 3600;
    ((void (*)(s32, s32, s32, s32, s32, s32))draw_number)(n / 60, 2, 7, 8, 12, (REG_BG1CNT >> 8) & 0x1F);
    ((void (*)(s32, s32, s32, s32, s32, s32))draw_number)(n % 60, -2, 10, 8, 12, (REG_BG1CNT >> 8) & 0x1F);
    ((void (*)(s32, s32, s32, s32, s32, s32))draw_number)(gUnk_03002B70.unk14[1], 4, 3, 11, 13,
                                                          (REG_BG1CNT >> 8) & 0x1F);
    ((void (*)(s32, s32, s32, s32, s32, s32))draw_number)(gUnk_03002B70.unk14[0], 0, 8, 11, 13,
                                                          (REG_BG1CNT >> 8) & 0x1F);
    divide_by_10000(gUnk_03000440.unk9E, gUnk_03002B70.money);
    render_text_sprites_08040DB8(gUnk_03000440.unk9E, 1, 15, 9, 7, 15, 1, 0);
    render_text_sprites_08040DB8(gUnk_03002B70.unk4, 13, 14, 4, 10, 13, 0, 0);
    open_choice_menu(1, 0x16, 7);
    CpuFastSet(gUnk_0878CA64, gPaletteBackupBg, 0x80);
    CpuFastSet(gUnk_0850DCF8, (void *)0x0202F9A0, 8);
    CpuFastSet(gUnk_084E2E38, (void *)0x0202F9E0, 8);
    CpuFastSet(gUnk_080AF7E8, gPaletteBackup, 8);
    gUnk_03000440.unk84 = 0;
    gGameSubState++;
}

void sub_0805D8AC(void) {
    if (gUnk_03000440.unk84 <= 8) {
        blend_obj_palettes_to_color_0803F684(0, 32 - gUnk_03000440.unk84 * 4, 0x3FFF);
        blend_obj_palettes_to_color_0803F998(0, 32 - gUnk_03000440.unk84 * 4, 0xFFFF);
        if (++gUnk_03000440.unk84 == 1) {
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

void sub_0805D948(void) {
    if (run_message(gUnk_08485788[9]))
        gGameSubState++;
}

void sub_0805D96C(void) {
    if (poll_choice_menu()) {
        sub_0803FB0C();
        if (gUnk_03000440.unk2A == 0)
            gGameSubState = (*(u8 *)&gUnk_03001784 & 1) ? 13 : 6;
        else
            gGameSubState = 9;
    }
}

void sub_0805D9B8(void) {
    if (run_message(gUnk_08485BD8[18])) {
        open_choice_menu(1, 0x16, 7);
        gGameSubState++;
    }
}

void sub_0805D9E4(void) {
    if (poll_choice_menu()) {
        sub_0803FB0C();
        if (gUnk_03000440.unk2A == 0)
            gGameSubState = 6;
        else
            gGameSubState = 9;
    }
}

void sub_0805DA1C(void) {
    if (run_message(gUnk_08485788[10])) {
        play_song(0);
        play_sound_effect(0);
        eeprom_setup_timer_irq();
        gUnk_03006F74->unk2 = 0;
        gGameSubState++;
    }
}

void attempt_save_and_transition(void) {
    u8 t = gUnk_03006F74->unk2++;
    u16 err = 0;
    s8 i;

    if (t > 29 && !is_sound_playing_with_lock(4)) {
        for (i = 0; i <= 3; i++) {
            err = save_dispatch(0);
            if (err == 0)
                break;
        }
        play_song(6);
        if (err == 0) {
            sub_0803FB0C();
            gUnk_03006F74->unk2 = err;
            gGameSubState++;
        } else {
            sub_0803FB0C();
            gUnk_03006F74->unk2 = 0;
            gGameSubState = 12;
        }
    }
}

void sub_0805DAE4(void) {
    u8 t = gUnk_03006F74->unk2++;
    if (run_message(gUnk_08485788[11]) && t > 60)
        gGameSubState++;
}

void sub_0805DB20(void) {
    sub_0803FB0C();
    copy_obj_palette_to_buffer();
    gUnk_03000440.unk84 = 0;
    gGameSubState++;
}

void sub_0805DB48(void) {
    if (game_state_execute_handler_a())
        gGameSubState++;
}

void sub_0805DB64(void) {
    if (gUnk_03000440.unk84 <= 8) {
        blend_obj_palettes_to_color_0803F684(0, gUnk_03000440.unk84 * 4, 0x3FFF);
        blend_obj_palettes_to_color_0803F998(0, gUnk_03000440.unk84 * 4, 0xFFFF);
        gUnk_03000440.unk84++;
    } else {
        REG_DISPCNT &= 0xFDFF;
        REG_DISPCNT &= 0xFBFF;
        clear_battle_sprite_slot(0, 0x80);
        gGameMode = 0;
        gGameState = 1;
        gGameSubState = 16;
    }
}

void sub_0805DBE8(void) {
    u8 t = gUnk_03006F74->unk2++;
    if (run_message(gUnk_08485788[12]) && t > 60)
        gGameSubState = 9;
}

void init_linking_mode(void) {
    gUnk_03005030 = 0;
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
    sound_init(&gUnk_03002430);
    VBlankIntrWait();
}

s32 save_dispatch(s32 mode) {
    s32 ret = 0;
    u32 zero = ret;
    u8 *buf = gDecompressBuffer;
    u16 ie;
    s32 i;

    CpuSet(&zero, buf, 0x0500072E);
    REG_IME = ret;
    ie = REG_IE;
    REG_IE = 0x2020;
    REG_IME = 1;
    switch (mode) {
    case 0: {
        register u8 *p asm("r0") = (u8 *)&gUnk_03001784;
        *p |= 1;
    }
        serialize_save_data((struct SaveData *)buf);
        ret = write_save_to_eeprom((u16 *)0x02030000, 0);
        break;
    case 1:
        ret = validate_save_data((struct SaveData *)buf);
        load_save_data((struct SaveData *)buf);
        break;
    case 2:
        gUnk_03001784.unk0_0 = 0;
        for (i = 0; i < 16; i++)
            gDecompressBuffer[i] = gSaveMagicErased[i];
        ret = write_save_to_eeprom((u16 *)0x02030000, 0);
        break;
    }
    REG_IE |= ie;
    return ret;
}

u16 eeprom_setup_timer_irq(void) {
    return sub_0807C7A8(2, &gIntrTable[11]);
}

s32 load_save_with_retries(void) {
    s32 i, ret;
    u8 *p;
    u8 fe;
    register s32 r asm("r1");
    if ((r = is_sound_playing_with_lock(4)) != 0)
        return r;
    play_song(0);
    play_sound_effect(0);
    p = (u8 *)&gUnk_03002B70;
    fe = 0xFE;
    i = 15;
    p += 19;
    for (; i >= 0; i--)
        *p-- = fe;
    for (i = 0; i <= 3; i++) {
        ret = save_dispatch(1);
        if (ret == 0)
            break;
    }
    return ret;
}

void load_save_data(struct SaveData *save) {
    s32 i;
    struct Unk_03000BE0 *medal;

    gUnk_03002B70 = save->unk10;
    medal = save->medals;
    for (i = 0; i < 30; i++) {
        memcpy_optimized(&gUnk_03000BE0[i], medal, sizeof(struct Unk_03000BE0));
        medal++;
    }
    for (i = 0; i < 0x3C0; i++)
        gMedapartInventory[i] = save->medaparts[i];
    for (i = 0; i < 9; i++)
        gUnk_030017A0[i] = save->team[i];
    CpuSet(save->items, gItemInventory, 0x40);
    CpuSet(save->field, &gUnk_030057E0, 0x660);
    gUnk_03001788 = save->flags & 3;
    gUnk_03001360 = (save->flags >> 2) & 1;
    gUnk_03000B94 = (save->flags >> 3) & 3;
    gUnk_03001784.unk0_1 = (save->flags >> 5) & 1;
}

void serialize_save_data(struct SaveData *save) {
    s32 i;
    u16 sum;
    u8 *p;
    struct Unk_03000BE0 *medal;

    for (i = 0; i < 16; i++)
        save->magic[i] = gSaveMagic[i];
    save->unk10 = gUnk_03002B70;
    medal = save->medals;
    for (i = 0; i < 30; i++) {
        memcpy_optimized(medal, &gUnk_03000BE0[i], sizeof(struct Unk_03000BE0));
        medal++;
    }
    for (i = 0; i < 0x3C0; i++)
        save->medaparts[i] = gMedapartInventory[i];
    for (i = 0; i < 9; i++)
        save->team[i] = gUnk_030017A0[i];
    CpuSet(gItemInventory, save->items, 0x40);
    CpuSet(&gUnk_030057E0, save->field, 0x660);
    save->flags = gUnk_03001788 | (gUnk_03001360 << 2) | (gUnk_03000B94 << 3) | (gUnk_03001784.unk0_1 << 5);
    save->checksum = 0;
    sum = 0;
    p = (u8 *)save;
    for (i = 0; i < sizeof(struct SaveData); i++)
        sum += *p++;
    save->checksum = sum;
}

s32 validate_save_data(struct SaveData *save) {
    u16 buf[4];
    u16 *p;
    s32 i;
    s32 n;
    u8 *b;
    u16 sum;
    u32 tmp; // the empty-name flag, then the stored checksum (one variable in the original)

    n = 920;
    p = (u16 *)save;
    for (i = 0; i < n; i++) {
        ReadEepromDword(i, buf);
        *p++ = buf[0];
        *p++ = buf[1];
        *p++ = buf[2];
        *p++ = buf[3];
    }
    for (i = 0; i < 16; i++) {
        if (gSaveMagic[i] != save->magic[i])
            return 1;
    }
    tmp = TRUE;
    for (i = 0; i < 16; i++) {
        if (save->unk10.unk4[i] == 0xFE)
            break;
        if (save->unk10.unk4[i] != 0) {
            tmp = FALSE;
            break;
        }
    }
    if (tmp)
        return -1;
    if (save->unk10.money > 99999)
        return -1;
    if (save->unk10.unk14[0] > 9999)
        return -1;
    if (save->unk10.unk14[0] < save->unk10.unk14[1])
        return -1;
    if (save->unk10.unk18 > 0x014996FF)
        return -1;
    if ((save->flags & 3) > 2)
        return -1;
    if (((save->flags >> 3) & 3) > 2)
        return -1;
    tmp = save->checksum;
    save->checksum = 0;
    sum = 0;
    b = (u8 *)save;
    for (i = 0; i < sizeof(struct SaveData); i++)
        sum += *b++;
    if (sum != tmp)
        return -1;
    return 0;
}

s32 write_save_to_eeprom(u16 *src, u32 force) {
    u16 buf[4];
    s32 i;
    s32 n;
    u16 changed;
    u32 j;

    n = 920;
    if ((u8)force) {
        for (i = 0; i < n; i++) {
            buf[0] = *src++;
            buf[1] = *src++;
            buf[2] = *src++;
            buf[3] = *src++;
            ProgramEepromDwordEx(i, buf);
        }
    } else {
        for (i = 0; i < n; i++) {
            changed = ReadEepromDword(i, buf);
            for (j = 0; j < 4; j++) {
                if (buf[j] != *src) {
                    buf[j] = *src;
                    changed = 1;
                }
                src++;
            }
            if (changed)
                ProgramEepromDwordEx(i, buf);
        }
    }
    return 0;
}

void sub_0805E170(u16 a) {
    gUnk_03002C30[20].unk6 = gUnk_080AF808[a & 3];
}

s32 calc_text_pixel_width(const u8 *s) {
    s32 w = 0;
    s32 i;
    for (i = 0; i < 10 && *s != 0xFE; i++)
        w += gUnk_083B4C88[*s++][0];
    return w;
}

static inline u32 ato(u32 s, u32 c) {
    return (s << 11) + c * 2;
}

void sub_0805E1CC(const u8 *s) {
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

void sub_0805E29C(void) {
    gUnk_08483C44[gGameSubState]();
    if (gFrameCounter & 1) {
        gBg3Scroll.x++;
        gBg3Scroll.y++;
    }
    sub_0805E170(gFrameCounter >> 3);
}

void sub_0805E2E8(void) {
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
    decompress_and_write_tilemap(gUnk_08794E6C, *bg1);
    decompress_and_write_tilemap(gUnk_0879514C, *(*pbg2));
    decompress_and_write_tilemap(gUnk_08795418, *bg3);
    size = dma3_copy_or_decompress(gUnk_08793628, gDecompressBuffer);
    CpuSet(gDecompressBuffer, vram_at2(0), (size / 2) & 0x1FFFFF);
    gUnk_03006F74->unk36 = (size >> 5) - 1;
    CpuSet(gUnk_084C21BC, vram_at2(size), (0x1000 / 2) & 0x1FFFFF);
    zero = 0;
    CpuFastSet(&zero, (void *)0x05000000, 0x01000080);
    zero2 = 0;
    CpuFastSet(&zero2, (void *)0x05000200, 0x01000080);
    lz_decompress_dispatch(gUnk_08784DA4, (void *)0x06010000);
    lz_decompress_dispatch(gUnk_084C6A98, (void *)0x06017400);
    for (i = 0; i < 2; i++) {
        gUnk_03002C30[i].unk0 = 0xC000;
        gUnk_03002C30[i].unk1C = 2;
        gUnk_03002C30[i].unkA = 0xE;
        gUnk_03002C30[i].unk6 = 8;
    }

    gUnk_03002C30[0].unk0 |= 0x2000;
    gUnk_03002C30[20].unk0 = 0x8000;
    gUnk_03002C30[20].unk1C = 2;
    gUnk_03002C30[20].unk2 = 0x10;
    gUnk_03002C30[20].unk4 = 0x10;
    gUnk_03002C30[20].unkA = 0;
    gUnk_03002C30[20].unk6 = 0x23;
    if (gUnk_03000584 == 0) {
        gUnk_03002C30[20].unk0 |= 0x4000;
    } else {
        t = gUnk_03006F74->unk36 + ((gUnk_03000BE0[gUnk_030017EC].unk1 * 4) + 1);
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
        gUnk_03002C30[i + 2].unk0 = 0x8000;
        gUnk_03002C30[i + 2].unk1C = 2;
        gUnk_03002C30[i + 2].unkA = 0xE;
        gUnk_03002C30[i + 2].unk6 = 5;
    }

    gUnk_03002C30[3].unk0 |= 0x1000;
    gUnk_03006F74->unkD = 0;
    gUnk_03006F74->unkE = 0;
    gUnk_03006F74->unk8 = 0;
    gUnk_03002C30[0].unk2 = (y = (gUnk_03006F74->unkD * 8) + 0x14);
    gUnk_03002C30[0].unk4 = mul16(gUnk_03006F74->unkE) + half4(gUnk_03006F74->unk8);
    gUnk_03002C30[1].unk2 = y;
    gUnk_03002C30[1].unk4 = mul16(gUnk_03006F74->unkE) - half8(gUnk_03006F74->unk8);
    gUnk_03002C30[4].unk0 = 0xC000;
    gUnk_03002C30[4].unk1C = 2;
    gUnk_03002C30[4].unkA = 0xE;
    gUnk_03002C30[4].unk6 = 0x26;
    gGameSubState++;
}

void sub_0805E5B0(void) {
    s8 i;
    s32 x;
    u8 k;
    const u8(*tbl)[2];

    REG_DISPCNT |= 0x200;
    REG_DISPCNT |= 0x400;
    REG_DISPCNT |= 0x800;
    REG_DISPCNT |= 0x1000;
    for (i = 0; i < 16; i++)
        gUnk_03006F74->unk58[i] = 0xFE;
    clear_sprite_table_mask(5, 10);
    switch (gUnk_03000584) {
    case 0:
        for (i = 0; i < 16; i++) {
            gUnk_03006F74->unk58[i] = gUnk_08483C68[i];
            if (gUnk_03006F74->unk58[i] == 0xFE)
                break;
        }
        gUnk_03006F74->unkF = i;
        break;
    case 1:
        k = gUnk_03000BE0[gUnk_030017EC].unk1;
        if (k <= 1) {
            for (i = 0; i < 16; i++) {
                gUnk_03006F74->unk58[i] = ((const u8 *)gUnk_083B6410[k + 0x20])[i];
                if (gUnk_03006F74->unk58[i] == 0xFE)
                    break;
            }
        } else {
            for (i = 0; i < 16; i++) {
                gUnk_03006F74->unk58[i] = ((const u8 *)gUnk_083B6410[k])[i];
                if (gUnk_03006F74->unk58[i] == 0xFE)
                    break;
            }
        }
        gUnk_03006F74->unkF = i;
        break;
    case 2:
        for (i = 0; i < 16; i++) {
            gUnk_03006F74->unk58[i] = gUnk_03000BE0[gUnk_030017EC].unkA[i];
            if (gUnk_03006F74->unk58[i] == 0xFE)
                break;
        }
        gUnk_03006F74->unkF = i;
        break;
    }
    CpuSet(gUnk_03006F74->unk58, gUnk_03006F74->unk58 + 0x10, 8);
    gUnk_03002C30[4].unk2 = calc_text_pixel_width(gUnk_03006F74->unk58) + 0x28;
    gUnk_03002C30[4].unk4 = 0x1B;
    render_text_sprites_08040DB8(gUnk_03006F74->unk58, 5, 5, 3, 10, 13, 1, 0);
    x = gUnk_03002C30[4].unk2 + 2;
    {
        register const u8(*tb)[2] asm("r4");
        for (i = gUnk_03006F74->unkF; i <= 9; i++) {
            tb = gUnk_083B4C88;
            gUnk_03002C30[i + 5].unk0 = 0xC000;
            gUnk_03002C30[i + 5].unk1C = 0;
            gUnk_03002C30[i + 5].unkA = 0xD;
            gUnk_03002C30[i + 5].unk6 = 0x42;
            gUnk_03002C30[i + 5].unk2 = x;
            gUnk_03002C30[i + 5].unk4 = 0x1C;
            gUnk_03002C30[i + 5].unkB = 0xFF;
            x += tb[0x43][0];
        }
    }
    CpuFastSet(gUnk_08483AA0, (void *)0x0202FA20, 8);
    CpuFastSet(gUnk_084E2E58, (void *)0x0202F9C0, 8);
    CpuFastSet(gUnk_084E2E38, (void *)0x0202F9A0, 8);
    CpuFastSet(gUnk_080AF810, gPaletteBackup, 8);
    CpuFastSet(gUnk_08793428, gPaletteBackupBg, 0x80);
    gUnk_03000440.unk84 = 0;
    gGameSubState++;
}

void sub_0805E878(void) {
    struct Unk_03000440 *b = &gUnk_03000440;
    if (b->unk84 <= 8) {
        blend_obj_palettes_to_color_0803F684(0, 0x20 - b->unk84 * 4, 0xFFFF);
        blend_obj_palettes_to_color_0803F998(0, 0x20 - b->unk84 * 4, 0xFFFF);
        b->unk84++;
    } else {
        gUnk_03006F74->unk2 = 0;
        gUnk_03006F74->unk6 = 0;
        gGameSubState++;
    }
}

// Per-frame update of the name-entry screen (runs every frame while naming a Medal): cursor blink and
// movement (rows 0-2 letters, row 3 Space / Back / End), Start / R / A / B, edits the name in unk58.
void name_entry_update(void) {
    s32 i;
    s32 x;
    u8 blank;
    u8 col;
    s32 t;

    gUnk_03002C30[4].unk6 = ((gFrameCounter / 6) & 3) + 0x26;
    if (gUnk_03006F74->unk6) {
        if (gUnk_03006F74->unk2++ < 8)
            gUnk_03006F74->unk8++;
        else {
            gUnk_03006F74->unk2 = 0;
            gUnk_03006F74->unk6 = 0;
        }
    } else {
        if (gUnk_03006F74->unk2++ < 8)
            gUnk_03006F74->unk8--;
        else {
            gUnk_03006F74->unk2 = 0;
            gUnk_03006F74->unk6 = 1;
        }
    }

    if (KEYS_LO(gRepeatKeys) & 0x10) {
        play_sound_effect(2);
        col = gUnk_03006F74->unkD;
        if (gUnk_03006F74->unkE == 3 ? col == 2 : col == 0x19)
            gUnk_03006F74->unkD = 0;
        else
            gUnk_03006F74->unkD++;
    }
    if (KEYS_LO(gRepeatKeys) & 0x20) {
        play_sound_effect(2);
        if (gUnk_03006F74->unkD == 0) {
            gUnk_03006F74->unkD = gUnk_03006F74->unkE == 3 ? 2 : 0x19;
        } else
            gUnk_03006F74->unkD--;
    }
    if (KEYS_LO(gRepeatKeys) & 0x40) {
        play_sound_effect(2);
        if (gUnk_03006F74->unkE == 0) {
            gUnk_03006F74->unkE = 3;
            if (gUnk_03006F74->unkD <= 8)
                gUnk_03006F74->unkD = 0;
            else if (gUnk_03006F74->unkD <= 0x10)
                gUnk_03006F74->unkD = 1;
            else
                gUnk_03006F74->unkD = 2;
        } else {
            gUnk_03006F74->unkE--;
            if (gUnk_03006F74->unkE == 2)
                gUnk_03006F74->unkD = gUnk_080AF850[gUnk_03006F74->unkD];
        }
    }
    if (KEYS_LO(gRepeatKeys) & 0x80) {
        play_sound_effect(2);
        if (gUnk_03006F74->unkE == 3) {
            gUnk_03006F74->unkE = 0;
            gUnk_03006F74->unkD = gUnk_080AF850[gUnk_03006F74->unkD];
        } else {
            gUnk_03006F74->unkE++;
            if (gUnk_03006F74->unkE == 3) {
                if (gUnk_03006F74->unkD <= 8)
                    gUnk_03006F74->unkD = 0;
                else if (gUnk_03006F74->unkD <= 0x10)
                    gUnk_03006F74->unkD = 1;
                else
                    gUnk_03006F74->unkD = 2;
            }
        }
    }

    if (gUnk_03006F74->unkE == 3) {
        gUnk_03002C30[0].unk2 = gUnk_03006F74->unkD * 64 - (t = (s32)gUnk_03006F74->unk8 / 2 - 0x18);
        gUnk_03002C30[0].unk4 = 0x8C;
        gUnk_03002C30[1].unk2 = gUnk_03006F74->unkD * 64 + (t = (s32)gUnk_03006F74->unk8 / 2 + 0x58);
        gUnk_03002C30[1].unk4 = gUnk_03002C30[0].unk4;
        gUnk_03002C30[0].unk6 = 5;
        gUnk_03002C30[1].unk6 = 5;
        gUnk_03002C30[0].unk0 &= 0xDFFF;
        gUnk_03002C30[1].unk0 |= 0x1000;
    } else {
        gUnk_03002C30[0].unk2 = gUnk_03006F74->unkD * 8 + 0x14;
        gUnk_03002C30[0].unk4 = gUnk_03006F74->unkE * 24 + (t = (s32)gUnk_03006F74->unk8 / 2 + 0x40);
        gUnk_03002C30[1].unk2 = gUnk_03002C30[0].unk2;
        gUnk_03002C30[1].unk4 = gUnk_03006F74->unkE * 24 - (t = (s32)gUnk_03006F74->unk8 / 2 - 0x50);
        gUnk_03002C30[0].unk6 = 8;
        gUnk_03002C30[1].unk6 = 8;
        gUnk_03002C30[0].unk0 |= 0x2000;
        gUnk_03002C30[1].unk0 &= 0xEFFF;
    }

    if (KEYS_LO(gNewKeys) & 8) {
    start:
        play_sound_effect(4);
        gUnk_03006F74->unkE = 3;
        gUnk_03006F74->unkD = 2;
    } else if (*((u8 *)&gNewKeys + 1) & 1) {
    space:
        if (gUnk_03006F74->unkF <= 9) {
            play_sound_effect(4);
            gUnk_03006F74->unk58[gUnk_03006F74->unkF] = 0;
            gUnk_03006F74->unkF++;
            if (gUnk_03006F74->unkF == 10) {
                gUnk_03002C30[4].unk0 &= 0xBFFF;
                clear_sprite_table_mask(5, 10);
                render_text_sprites_08040DB8(gUnk_03006F74->unk58, 5, 5, 3, 10, 13, 1, 0);
                goto start;
            }
        } else
            play_sound_effect(6);
        goto redraw;
    } else if (KEYS_LO(gNewKeys) & 1) {
        if (gUnk_03006F74->unkE == 3) {
            switch (gUnk_03006F74->unkD) {
            case 1:
                goto back;
            case 0:
                goto space;
            case 2:
                gUnk_03002C30[4].unk0 &= 0xBFFF;
                blank = 1;
                for (i = 0; (u32)i < 16 && gUnk_03006F74->unk58[i] != 0xFE; i++) {
                    if (gUnk_03006F74->unk58[i] != 0) {
                        blank = 0;
                        break;
                    }
                }
                if (blank)
                    CpuSet(gUnk_03006F74->unk58 + 0x10, gUnk_03006F74->unk58, 8);
                clear_sprite_table_mask(5, 10);
                render_text_sprites_08040DB8(gUnk_03006F74->unk58, 5, 5, 3, 10, 13, 1, 0);
                play_sound_effect(7);
                gGameSubState++;
                return;
            }
        }
        if (gUnk_03006F74->unkF <= 9) {
            play_sound_effect(4);
            gUnk_03006F74->unk58[gUnk_03006F74->unkF] = gUnk_03006F74->unkE * 26 + gUnk_03006F74->unkD + 1;
            gUnk_03006F74->unkF++;
            if (gUnk_03006F74->unkF == 10) {
                gUnk_03002C30[4].unk0 &= 0xBFFF;
                clear_sprite_table_mask(5, 10);
                render_text_sprites_08040DB8(gUnk_03006F74->unk58, 5, 5, 3, 10, 13, 1, 0);
                goto start;
            }
        } else
            play_sound_effect(6);
    redraw:
        clear_sprite_table_mask(5, 10);
        render_text_sprites_08040DB8(gUnk_03006F74->unk58, 5, 5, 3, 10, 13, 1, 0);
    } else if (gNewKeys & 0x202) {
    back:
        play_sound_effect(5);
        if (gUnk_03006F74->unkF != 0) {
            gUnk_03006F74->unkF--;
            gUnk_03006F74->unk58[gUnk_03006F74->unkF] = 0xFE;
        } else {
            gUnk_03006F74->unkF = 0;
            gUnk_03006F74->unk58[gUnk_03006F74->unkF] = 0xFE;
        }
        clear_sprite_table_mask(5, 10);
        render_text_sprites_08040DB8(gUnk_03006F74->unk58, 5, 5, 3, 10, 13, 1, 0);
        gUnk_03002C30[4].unk0 |= 0x4000;
    } else
        return;

    gUnk_03002C30[4].unk2 = calc_text_pixel_width(gUnk_03006F74->unk58) + 0x28;
    gUnk_03002C30[4].unk4 = 0x1B;
    x = gUnk_03002C30[4].unk2 + 2;
    {
        register const u8(*tb)[2] asm("r4");
        for (i = gUnk_03006F74->unkF; i <= 9; i++) {
            tb = gUnk_083B4C88;
            gUnk_03002C30[i + 5].unk0 = 0xC000;
            gUnk_03002C30[i + 5].unk1C = 0;
            gUnk_03002C30[i + 5].unkA = 0xD;
            gUnk_03002C30[i + 5].unk6 = 0x42;
            gUnk_03002C30[i + 5].unk2 = x;
            gUnk_03002C30[i + 5].unk4 = 0x1C;
            gUnk_03002C30[i + 5].unkB = 0xFF;
            x += tb[0x43][0];
            tb = gUnk_083B4C88;
        }
    }
}
