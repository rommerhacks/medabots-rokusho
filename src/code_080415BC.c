#include "global.h"

void reset_bg_scroll(void) {
    gBg0Scroll.x = 0;
    gBg0Scroll.y = 0;
    gBg1Scroll.x = 0;
    gBg1Scroll.y = 0;
    gBg2Scroll.x = 0;
    gBg2Scroll.y = 0;
    gBg3Scroll.x = 0;
    gBg3Scroll.y = 0;
}

void open_choice_menu(u8 a, u8 b, u8 c) {
    sub_0803F624(&gUnk_03000440.unk28, 8, 0);
    gUnk_03000440.unk2A = a;
    gUnk_03000440.unk2B = 0x7F;
    gUnk_03000440.unk2C = b;
    gUnk_03000440.unk2D = c;
}

void init_window_params(u8 a, u8 b, u8 c, u8 d) {
    sub_0803F624(&gUnk_03000440.unk28, 8, 0);
    gUnk_03000440.unk2A = a;
    gUnk_03000440.unk2B = d;
    gUnk_03000440.unk2C = b;
    gUnk_03000440.unk2D = c;
}

u32 poll_choice_menu(void) {
    gUnk_083B2814[gUnk_03000440.unk29]();
    return gUnk_03000440.unk28;
}

void decompress_bg_tilemap_to_vram(void) {
    lz_decompress_dispatch(gUnk_084878EC, (void *)(VRAM + 0x2600));
    lz_decompress_dispatch(gUnk_0848796C, (void *)(VRAM + 0x26E0));
    lz_decompress_dispatch(gUnk_084C7318, (void *)(VRAM + 0x17E00));
    set_tilemap_and_decompress_bg(0, 0x15, gUnk_084886D0, REG_BG0CNT, 0x130);
    set_tilemap_and_decompress_bg(2, 0x16, gUnk_08488718, REG_BG0CNT, 0x137);
    CpuFastSet(gUnk_084E2E58, (void *)(PLTT + 0x3C0), 8);
    gUnk_03000440.unk29++;
}

void clear_tilemap_and_advance_state(void) {
    vram_fill_tilemap_rect(8, 6, gUnk_03000440.unk2C, gUnk_03000440.unk2D, REG_BG0CNT, 0);
    vram_fill_tilemap_rect(8, 6, 0, 0x15, REG_BG0CNT, 0);
    gUnk_03000440.unk29++;
}

void clear_and_copy_tilemap_rows(void) {
    u32 i, j;
    u16 *d = (u16 *)(VRAM + 0x2800) + gUnk_03000440.unk2D * 32 + gUnk_03000440.unk2C;
    u16 *row = d;
    u16 *s;

    for (j = 0; j < 2; j++) {
        for (i = 0; i < 8; i++)
            *d++ = 0;
        row += 32;
        d = row;
    }
    s = (u16 *)(VRAM + 0x2D40);
    for (i = 0; i < 8; i++)
        *d++ = *s++;
    row += 32;
    d = row;
    s = (u16 *)(VRAM + 0x2E80);
    for (i = 0; i < 8; i++)
        *d++ = *s++;
    row += 32;
    d = row;
    for (j = 0; j < 2; j++) {
        for (i = 0; i < 8; i++)
            *d++ = 0;
        row += 32;
        d = row;
    }
    gUnk_03000440.unk29++;
}

void transition_draw_tile_strip(void) {
    u32 i, j;
    u16 *d = (u16 *)(VRAM + 0x2800) + gUnk_03000440.unk2D * 32 + gUnk_03000440.unk2C;
    u16 *row = d;
    u16 *s;
    u16 *srow;

    for (i = 0; i < 8; i++)
        *d++ = 0;
    row += 32;
    s = (u16 *)(VRAM + 0x2D40);
    srow = s;
    d = row;
    for (j = 0; j < 2; j++) {
        for (i = 0; i < 8; i++)
            *d++ = *s++;
        row += 32;
        d = row;
        srow += 32;
        s = srow;
    }
    s = (u16 *)(VRAM + 0x2E40);
    srow = s;
    for (j = 0; j < 2; j++) {
        for (i = 0; i < 8; i++)
            *d++ = *s++;
        row += 32;
        d = row;
        srow += 32;
        s = srow;
    }
    for (i = 0; i < 8; i++)
        *d++ = 0;
    gUnk_03000440.unk29++;
}

void copy_transition_tiles_to_bg2(void) {
    u32 i, j;
    u16 *d = (u16 *)(VRAM + 0x2800) + gUnk_03000440.unk2D * 32 + gUnk_03000440.unk2C;
    u16 *s = (u16 *)(VRAM + 0x2D40);
    u16 *srow = s;
    u16 *row = d;

    for (j = 0; j < 6; j++) {
        for (i = 0; i < 8; i++)
            *d++ = *s++;
        row += 32;
        d = row;
        srow += 32;
        s = srow;
    }
    gUnk_03000440.unk29++;
}

void battle_sprite_setup_cursor(void) {
    gUnk_03002C30[gUnk_03000440.unk2B].unk0 = 0xD204;
    gUnk_03002C30[gUnk_03000440.unk2B].unk2 = gUnk_03000440.unk2C * 8 + 0x14;
    gUnk_03002C30[gUnk_03000440.unk2B].unk4 = gUnk_03000440.unk2D * 8 + gUnk_03000440.unk2A * 16 + 0x10;
    gUnk_03002C30[gUnk_03000440.unk2B].unk6 = 0x307;
    gUnk_03002C30[gUnk_03000440.unk2B].unkA = 0xE;
    gUnk_03002C30[gUnk_03000440.unk2B].unk1C = 0;
    gUnk_03002C30[gUnk_03000440.unk2B].unk8 = 1;
    gUnk_03002C30[gUnk_03000440.unk2B].unk9 = 1;
    gUnk_03002C30[gUnk_03000440.unk2B].unkB = 0xFF;
    gUnk_03000440.unk84 = 1;
    gUnk_03000440.unk29++;
}

void advance_sprite_scroll_animation(void) {
    gUnk_03002C30[gUnk_03000440.unk2B].unk8 += 8;
    gUnk_03002C30[gUnk_03000440.unk2B].unk9 += 8;
    if (gUnk_03002C30[gUnk_03000440.unk2B].unk8 >= 0x40) {
        gUnk_03002C30[gUnk_03000440.unk2B].unk8 = 0x40;
        gUnk_03002C30[gUnk_03000440.unk2B].unk9 = 0x40;
        gUnk_03000440.unk29++;
    }
    gUnk_03000440.unk84 = 0;
}

void handle_battle_sprite_scroll_input(void) {
    if (KEYS_LO(gNewKeys) & 0xC0) {
        play_sound_effect(2);
        gUnk_03000440.unk2A ^= 1;
        gUnk_03002C30[gUnk_03000440.unk2B].unk4 = gUnk_03000440.unk2A * 16 + 0x48;
    }
    sub_08041C14(gUnk_03000440.unk2B, gUnk_03000440.unk84, gUnk_03000440.unk2C * 8 + 0x14);
    gUnk_03000440.unk84++;
    if (KEYS_LO(gNewKeys) & 2) {
        play_sound_effect(5);
        gUnk_03000440.unk2A = 1;
        gUnk_03002C30[gUnk_03000440.unk2B].unk2 = gUnk_03000440.unk2C * 8 + 0x14;
        gUnk_03002C30[gUnk_03000440.unk2B].unk4 = gUnk_03000440.unk2A * 16 + 0x48;
        gUnk_03000440.unk84 = 0;
        gUnk_03000440.unk29++;
    }
    if (KEYS_LO(gNewKeys) & 1) {
        play_sound_effect(4);
        gUnk_03002C30[gUnk_03000440.unk2B].unk2 = gUnk_03000440.unk2C * 8 + 0x14;
        gUnk_03000440.unk84 = 0;
        gUnk_03000440.unk29++;
    }
}

void update_sprite_hflip_by_animation_phase(void) {
    if (gUnk_03000440.unk84 != 0x1E) {
        if (gUnk_03000440.unk84 & 4)
            gUnk_03002C30[gUnk_03000440.unk2B].unk0 &= 0xBFFF;
        else
            gUnk_03002C30[gUnk_03000440.unk2B].unk0 |= 0x4000;
        gUnk_03000440.unk84++;
    } else {
        gUnk_03002C30[gUnk_03000440.unk2B].unk0 |= 0x4000;
        gUnk_03000440.unk29++;
    }
}

void animate_battle_sprite_shrink(void) {
    gUnk_03002C30[gUnk_03000440.unk2B].unk8 -= 8;
    gUnk_03002C30[gUnk_03000440.unk2B].unk9 -= 8;
    if (gUnk_03002C30[gUnk_03000440.unk2B].unk8 == 0) {
        clear_battle_sprite_slot(gUnk_03000440.unk2B, 1);
        gUnk_03000440.unk29++;
    }
}

void sub_08041BF4(void) {
    gUnk_03000440.unk28 = (gUnk_03000440.unk2A << 4) + 1;
    gUnk_03000440.unk29++;
}

void sub_08041C14(u8 sprite, u8 frame, u16 y) {
    switch ((frame & 0xC) >> 2) {
    case 1:
        gUnk_03002C30[sprite].unk2 = y + 1;
        break;
    case 3:
        gUnk_03002C30[sprite].unk2 = y - 1;
        break;
    default:
        gUnk_03002C30[sprite].unk2 = y;
        break;
    }
}

void sub_08041C5C(u8 sprite, u8 frame, u16 x) {
    switch ((frame & 0xC) >> 2) {
    case 1:
        gUnk_03002C30[sprite].unk4 = x + 1;
        break;
    case 3:
        gUnk_03002C30[sprite].unk4 = x - 1;
        break;
    default:
        gUnk_03002C30[sprite].unk4 = x;
        break;
    }
}

u32 game_state_execute_handler_a(void) {
    gUnk_03000440.unk4 = 0;
    gUnk_083B284C[gUnk_03000440.unk1B]();
    if (gUnk_03000440.unk4 > 7)
        return 1;
    return 0;
}

u32 game_state_execute_handler_b(void) {
    gUnk_03000440.unk4 = 0;
    gUnk_083B2864[gUnk_03000440.unk1B]();
    if (gUnk_03000440.unk4 > 7)
        return 1;
    return 0;
}

void memcpy_bytes_08041D04(const void *src, void *dst, u8 n) {
    u32 i;

    for (i = 0; i < n; i++) {
        *(u8 *)dst = *(const u8 *)src;
        src = (const u8 *)src + 1;
        dst = (u8 *)dst + 1;
    }
}

void sub_08041D28(void) {
    u32 i;
    for (i = 0; i < 30; i++)
        gUnk_03000BE0[i].unk0 = i;
}

u32 find_medal_slot_by_id(u8 id) {
    u32 i;

    for (i = 0; i < 30; i++)
        if ((gUnk_03000BE0[i].unk0 & 0x80) && gUnk_03000BE0[i].unk1 == id)
            return i + 1;
    return 0;
}

u32 medal_add_by_id(u8 id) {
    u32 i;

    memcpy_bytes_08041D04(gUnk_083B6158[id], &gUnk_03000440.unkEE, 16);
    for (i = 0; i < 30; i++) {
        if (!(gUnk_03000BE0[i].unk0 & 0x80)) {
            gUnk_03000BE0[i].unk0 |= 0x80;
            gUnk_03000BE0[i].unk1 = id;
            gUnk_03000BE0[i].unk4 = gUnk_03000440.unkEF;
            gUnk_03000BE0[i].unk6 = gUnk_03000440.unkF0;
            gUnk_03000BE0[i].unk7 = gUnk_03000440.unkF5;
            gUnk_03000BE0[i].unk5 = clear_ewram_buffer_02023000();
            gUnk_03000BE0[i].unk8 = sub_080420C4(gUnk_03000BE0[i].unk5, gUnk_03000440.unkF1, gUnk_03000440.unkF2,
                                                 gUnk_03000440.unkF3, gUnk_03000440.unkF4);
            gUnk_03000BE0[i].unk2 = (gUnk_03000BE0[i].unk5 + 1) * 100;
            if ((u8)(gUnk_03000BE0[i].unk5 / 10) * gUnk_03000440.unkF6 + gUnk_03000440.unkF6 > 100)
                gUnk_03000BE0[i].unk20[0] = 100;
            else
                gUnk_03000BE0[i].unk20[0] = gUnk_03000440.unkF6 + gUnk_03000440.unkF6 * (gUnk_03000BE0[i].unk5 / 10);
            if ((u8)(gUnk_03000BE0[i].unk5 / 10) * gUnk_03000440.unkF7 + gUnk_03000440.unkF7 > 100)
                gUnk_03000BE0[i].unk20[1] = 100;
            else
                gUnk_03000BE0[i].unk20[1] = gUnk_03000440.unkF7 + gUnk_03000440.unkF7 * (gUnk_03000BE0[i].unk5 / 10);
            if ((u8)(gUnk_03000BE0[i].unk5 / 10) * gUnk_03000440.fillerF8[0] + gUnk_03000440.fillerF8[0] > 100)
                gUnk_03000BE0[i].unk20[2] = 100;
            else
                gUnk_03000BE0[i].unk20[2] =
                    gUnk_03000440.fillerF8[0] + gUnk_03000440.fillerF8[0] * (gUnk_03000BE0[i].unk5 / 10);
            if ((u8)(gUnk_03000BE0[i].unk5 / 10) * gUnk_03000440.fillerF8[1] + gUnk_03000440.fillerF8[1] > 100)
                gUnk_03000BE0[i].unk20[3] = 100;
            else
                gUnk_03000BE0[i].unk20[3] =
                    gUnk_03000440.fillerF8[1] + gUnk_03000440.fillerF8[1] * (gUnk_03000BE0[i].unk5 / 10);
            if ((u8)(gUnk_03000BE0[i].unk5 / 10) * gUnk_03000440.fillerF8[2] + gUnk_03000440.fillerF8[2] > 100)
                gUnk_03000BE0[i].unk20[4] = 100;
            else
                gUnk_03000BE0[i].unk20[4] =
                    gUnk_03000440.fillerF8[2] + gUnk_03000440.fillerF8[2] * (gUnk_03000BE0[i].unk5 / 10);
            if ((u8)(gUnk_03000BE0[i].unk5 / 10) * gUnk_03000440.fillerF8[3] + gUnk_03000440.fillerF8[3] > 100)
                gUnk_03000BE0[i].unk20[5] = 100;
            else
                gUnk_03000BE0[i].unk20[5] =
                    gUnk_03000440.fillerF8[3] + gUnk_03000440.fillerF8[3] * (gUnk_03000BE0[i].unk5 / 10);
            if ((u8)(gUnk_03000BE0[i].unk5 / 10) * gUnk_03000440.fillerF8[4] + gUnk_03000440.fillerF8[4] > 100)
                gUnk_03000BE0[i].unk20[6] = 100;
            else
                gUnk_03000BE0[i].unk20[6] =
                    gUnk_03000440.fillerF8[4] + gUnk_03000440.fillerF8[4] * (gUnk_03000BE0[i].unk5 / 10);
            if ((u8)(gUnk_03000BE0[i].unk5 / 10) * gUnk_03000440.fillerF8[5] + gUnk_03000440.fillerF8[5] > 100)
                gUnk_03000BE0[i].unk20[7] = 100;
            else
                gUnk_03000BE0[i].unk20[7] =
                    gUnk_03000440.fillerF8[5] + gUnk_03000440.fillerF8[5] * (gUnk_03000BE0[i].unk5 / 10);
            return i;
        }
    }
    return i;
}

void medal_remove_by_id(u8 id) {
    u32 i;

    for (i = 0; i < 30; i++) {
        if ((gUnk_03000BE0[i].unk0 & 0x80) && gUnk_03000BE0[i].unk1 == id) {
            u8 f = gUnk_03000BE0[i].unk0 & 0x1F;
            sub_0803F624((u8 *)&gUnk_03000BE0[i], 0x40, 0);
            gUnk_03000BE0[i].unk0 = f;
            return;
        }
    }
}

void export_medals_to_buffer(const void *src) {
    u32 i;

    for (i = 0; i < 30; i++) {
        if (!(gUnk_03000BE0[i].unk0 & 0x80)) {
            u32 f = gUnk_03000BE0[i].unk0 & 0x1F;
            memcpy_bytes_0803F63C(src, &gUnk_03000BE0[i], 0x40);
            gUnk_03000BE0[i].unk0 = (gUnk_03000BE0[i].unk0 & 0x80) | f;
            return;
        }
    }
}

u32 clear_ewram_buffer_02023000(void) {
    u32 zero = 0;
    struct SortEntry *e = SORT_BUFFER;
    struct Unk_03000BE0 *m;
    u32 i;

    CpuFastSet(&zero, e, 0x01000080);
    for (i = 0, m = gUnk_03000BE0; i < 30; m++, e++, i++)
        e->key = m->unk5;
    sub_0804242C(30);
    return (SORT_BUFFER[0].key - SORT_BUFFER[3].key) / 2 + SORT_BUFFER[3].key;
}

u32 sub_080420C4(u8 level, u8 a, u8 b, u8 c, u8 d) {
    if (d != 0 && level >= d)
        return 4;
    if (c != 0 && level >= c)
        return 3;
    if (b != 0 && level >= b)
        return 2;
    if (a != 0 && level >= a)
        return 1;
    return 0;
}

u32 sub_08042114(u8 a, u8 b) {
    u32 hi = gMedapartInventory[b * 240 + a * 2] << 8;
    return gMedapartInventory[b * 240 + a * 2 + 1] | hi;
}

void medapart_add_quantity(u8 id, u8 kind, u8 n) {
    u8 *inv = gMedapartInventory;
    u8 *p = &inv[kind * 240 + id * 2];
    s32 v = n + *p;

    if (v > 99)
        *p = 99;
    else
        *p = v;
}

void reduce_medapart_stat(u8 id, u8 kind, u8 n) {
    u8 *inv = gMedapartInventory;
    u8 *p = &inv[kind * 240 + id * 2];
    s32 v = *p - n;

    if (v < 0)
        v = 0;
    *p = v;
}

void sub_080421A0(void) {
    u32 i;
    for (i = 0; i < 9; i++)
        gUnk_030017A0[i].unk7 = i;
}

void sub_080421B4(u8 medal, u8 kind) {
    u32 i;

    for (i = 0; i < 9; i++) {
        if (gUnk_030017A0[i].unk7 == medal) {
            u8 *p = &gUnk_030017A0[i].unk3;
            u8 old = p[kind];

            p[kind] = gUnk_030017A0[i].unk1 + 0x78;
            gUnk_030017A0[i].unk0 = 2;
            gMedapartInventory[kind * 240 + old * 2]--;
            gMedapartInventory[kind * 240 + old * 2 + 1]--;
            return;
        }
    }
}

u32 team_is_full(void) {
    u32 i;

    for (i = 0; i < 9; i++)
        if (gUnk_030017A0[i].unk0 == 0)
            return 0;
    return 1;
}

void team_add_tinpet(u8 gender) {
    u32 i;

    for (i = 0; i < 9; i++) {
        if (gUnk_030017A0[i].unk0 == 0) {
            gUnk_030017A0[i].unk0 = 1;
            gUnk_030017A0[i].unk1 = gender & 1;
            gUnk_030017A0[i].unk2 = 0x1E;
            gUnk_030017A0[i].unk3 = (gender & 1) + 0x78;
            gUnk_030017A0[i].unk4 = (gender & 1) + 0x78;
            gUnk_030017A0[i].unk5 = (gender & 1) + 0x78;
            gUnk_030017A0[i].unk6 = (gender & 1) + 0x78;
            return;
        }
    }
}

u32 get_item_quantity_by_id(u8 id) {
    u32 i;
    u8 key = id & 0x3F;

    for (i = 0; i < 64; i++)
        if ((gItemInventory[i][0] & 0x80) && (gItemInventory[i][0] & 0x7F) == key)
            return gItemInventory[i][1];
    return 0;
}

void item_add_quantity(u8 id, u8 n) {
    u32 i;

    id &= 0x3F;
    for (i = 0; i < 64; i++) {
        if (gItemInventory[i][0] & 0x80) {
            if ((gItemInventory[i][0] & 0x7F) == id) {
                gItemInventory[i][1] += n;
                if (gItemInventory[i][1] > 99)
                    gItemInventory[i][1] = 99;
                return;
            }
        } else {
            gItemInventory[i][0] = id | 0x80;
            gItemInventory[0][i * 2 + 1] = n; // flat index: matches the original's address math
            return;
        }
    }
}

// Removes n of item id (guess: item_remove_quantity); when the count drops to 0 the entry is cleared
// and bubbled to the end of the list.
void sub_08042318(u8 id, u8 n) {
    u32 i;
    s32 left;

    id &= 0x3F;
    for (i = 0; i < 64; i++) {
        if ((gItemInventory[i][0] & 0x80) && (gItemInventory[i][0] & 0x7F) == id) {
            left = gItemInventory[0][i * 2 + 1] - n;
            if (left <= 0) {
                gItemInventory[i][0] = 0;
                gItemInventory[0][i * 2 + 1] = 0;
                while (gItemInventory[i + 1][0] != 0) {
                    memswap(&gItemInventory[0][i * 2], &gItemInventory[0][(i + 1) * 2], 2);
                    i++;
                }
            } else {
                gItemInventory[0][i * 2 + 1] = left;
                return;
            }
        }
    }
}

// Bubble sort of the n SORT_BUFFER entries (struct SortEntry), ascending by key then key2.

void sub_080423A0(u8 n) {
    u16 t0, t1, t2, t3;
    u32 j;
    struct SortEntry *a, *b;

    if (n <= 1)
        return;
    for (n--; n != 0; n--) {
        for (j = 0; j < n; j++) {
            a = &SORT_BUFFER[j];
            b = &SORT_BUFFER[j + 1];
            if (a->key > b->key) {
                t0 = a->key;
                t1 = a->key2;
                t2 = a->value;
                t3 = a->unk6;
                a->key = b->key;
                a->key2 = b->key2;
                a->value = b->value;
                a->unk6 = b->unk6;
                b->key = t0;
                b->key2 = t1;
                b->value = t2;
                b->unk6 = t3;
            } else if (a->key == b->key && a->key2 > b->key2) {
                t0 = a->key;
                t1 = a->key2;
                t2 = a->value;
                t3 = a->unk6;
                a->key = b->key;
                a->key2 = b->key2;
                a->value = b->value;
                a->unk6 = b->unk6;
                b->key = t0;
                b->key2 = t1;
                b->value = t2;
                b->unk6 = t3;
            }
        }
    }
}

// Bubble sort of the n SORT_BUFFER entries (struct SortEntry), descending by key then key2.

void sub_0804242C(u8 n) {
    u16 t0, t1, t2, t3;
    u32 j;
    struct SortEntry *a, *b;

    if (n <= 1)
        return;
    for (n--; n != 0; n--) {
        for (j = 0; j < n; j++) {
            a = &SORT_BUFFER[j];
            b = &SORT_BUFFER[j + 1];
            if (a->key < b->key) {
                t0 = a->key;
                t1 = a->key2;
                t2 = a->value;
                t3 = a->unk6;
                a->key = b->key;
                a->key2 = b->key2;
                a->value = b->value;
                a->unk6 = b->unk6;
                b->key = t0;
                b->key2 = t1;
                b->value = t2;
                b->unk6 = t3;
            } else if (a->key == b->key && a->key2 < b->key2) {
                t0 = a->key;
                t1 = a->key2;
                t2 = a->value;
                t3 = a->unk6;
                a->key = b->key;
                a->key2 = b->key2;
                a->value = b->value;
                a->unk6 = b->unk6;
                b->key = t0;
                b->key2 = t1;
                b->value = t2;
                b->unk6 = t3;
            }
        }
    }
}

s32 rng_next_080424B8(void) {
    if (gUnk_03000440.unk89 == 0) {
        u16 s = gUnk_03000440.unk8A + gUnk_03000440.unk8C;

        s += 0x87 + (((gFrameCounter << 4) + (gFrameCounter >> 4) + 1) >> 1);
        gUnk_03000440.unk8A = ((s & 0xFF) << 8) | (((s & 0xFF00) >> 8) ^ (s & 0xFF));
        gUnk_03000440.unk8C = ((s & 0xFF00) >> 8) ^ s;
        return gUnk_03000440.unk8C;
    } else {
        gUnk_03000440.unk8D++;
        gUnk_03000440.unk8C = gUnk_083B286C[gUnk_03000440.unk8D];
        return gUnk_03000440.unk8C;
    }
}

void set_blend_effect_mode(u8 mode, u16 targets, u16 speed) {
    u16 bld, eva, evb, evy;

    gUnk_03000440.unk90 = mode;
    gUnk_03000440.unk92 = speed;
    gUnk_03000440.unk94 = 0;
    switch (mode) {
    case 1:
        bld = 0x40;
        eva = 16;
        evb = 16;
        evy = 16;
        break;
    case 2:
        bld = 0x40;
        eva = 0;
        evb = 0;
        evy = 0;
        break;
    case 3:
        bld = 0x80;
        eva = 16;
        evb = 16;
        evy = 16;
        break;
    case 4:
        bld = 0x80;
        eva = 0;
        evb = 0;
        evy = 0;
        break;
    case 5:
        bld = 0xC0;
        eva = 16;
        evb = 16;
        evy = 16;
        break;
    case 6:
        bld = 0xC0;
        eva = 0;
        evb = 0;
        evy = 0;
        break;
    default:
        bld = 0;
        eva = 0;
        evb = 0;
        evy = 0;
        break;
    }
    REG_BLDALPHA = ((evb & 0x1F) << 8) | (eva & 0x1F);
    REG_BLDY = evy & 0x1F;
    REG_BLDCNT = bld | targets;
}

// Other modes write whatever eva / evb / evy hold (uninitialized), like the original.
u32 update_blend_effect(void) {
    u16 eva, evb, evy;

    gUnk_03000440.unk94 += gUnk_03000440.unk92;
    switch (gUnk_03000440.unk90) {
    case 1:
    case 3:
    case 5:
        eva = 16 - (gUnk_03000440.unk94 >> 4);
        evb = eva;
        evy = eva;
        break;
    case 2:
    case 4:
    case 6:
        eva = gUnk_03000440.unk94 >> 4;
        evb = eva;
        evy = eva;
        break;
    }
    REG_BLDALPHA = ((evb & 0x1F) << 8) | (eva & 0x1F);
    REG_BLDY = evy & 0x1F;
    if (gUnk_03000440.unk94 > 0xFF)
        return 1;
    return 0;
}

void fill_text_blank(u8 *buf, u8 n) {
    u32 i;

    for (i = 0; i < n; i++)
        *buf++ = 0x43;
    *buf = 0xFE;
}

void fill_tilemap_rect_08042698(u32 w, u32 h, u32 x, u32 y, u32 bgcnt, u16 entry) {
    u32 i, j;
    u16 *base = (u16 *)(VRAM + ((bgcnt >> 8) & 0x1F) * 0x800) + x + y * 32;

    for (j = 0; j < h; j++) {
        u16 *p = base + j * 32;
        for (i = 0; i < w; i++)
            *p++ = entry++;
    }
}

void fill_tilemap_pair_or_divide(u8 value, u8 x, u8 y, u32 bgcnt, u16 tile) {
    u8 d[3];
    u8 r;

    if (value == 0xFF) {
        fill_tilemap_rect_08042698(1, 2, x, y, bgcnt, tile + 0x18);
        fill_tilemap_rect_08042698(1, 2, x + 1, y, bgcnt, tile + 0x18);
    } else {
        d[0] = value / 100;
        r = value - (u8)(value / 100) * 100;
        d[1] = r / 10;
        d[2] = r - (u8)(r / 10) * 10;
        if (d[0] != 0) {
            fill_tilemap_rect_08042698(1, 2, x, y, bgcnt, tile + 0x14);
            fill_tilemap_rect_08042698(1, 2, x + 1, y, bgcnt, tile + 0x16);
        } else if (d[1] != 0) {
            fill_tilemap_rect_08042698(1, 2, x, y, bgcnt, tile + d[1] * 2);
            fill_tilemap_rect_08042698(1, 2, x + 1, y, bgcnt, tile + d[2] * 2);
        } else {
            vram_fill_tilemap_rect(1, 2, x, y, bgcnt, 0);
            fill_tilemap_rect_08042698(1, 2, x + 1, y, bgcnt, tile + d[2] * 2);
        }
    }
}

void divide_by_100000_08042838(u32 n, u32 x, u32 y, u32 digits, u32 bgcnt, u32 tile) {
    u8 d[6];
    u32 r;
    u32 i;
    u8 start, started;
    u16 *dst;
    u8 count = digits;
    u16 t = tile;

    d[0] = n / 100000;
    r = n - n / 100000 * 100000;
    d[1] = r / 10000;
    r = r - n / 10000 * 10000;
    d[2] = r / 1000;
    r = r - r / 1000 * 1000;
    d[3] = r / 100;
    r = r - r / 100 * 100;
    d[4] = r / 10;
    r = r - r / 10 * 10;
    d[5] = r;

    start = 6 - count;
    started = 0;
    dst = (u16 *)(VRAM + ((bgcnt >> 8) & 0x1F) * 0x800) + x + y * 32;
    for (i = start; i <= 5; i++) {
        if (i <= 4) {
            if (d[i] == 0) {
                if (started)
                    *dst++ = t + d[i];
                else
                    *dst++ = 0;
            } else {
                *dst++ = t + d[i];
                started = 1;
            }
        } else {
            *dst++ = t + d[i];
        }
    }
}

static inline u32 lower_digit_tile(s16 base, u32 digit) {
    return base + 1 + digit * 2;
}

void sub_08042950(u32 value, u32 x, u32 y, u8 digits, u32 bgcnt, u16 base) {
    u8 d[6];
    u32 rem;
    u32 i;
    u8 start;
    u32 flag;
    vu16 *dst;

    d[0] = value / 100000;
    rem = value - value / 100000 * 100000;
    d[1] = rem / 10000;
    rem -= value / 10000 * 10000;
    d[2] = rem / 1000;
    rem -= rem / 1000 * 1000;
    d[3] = rem / 100;
    rem -= rem / 100 * 100;
    d[4] = rem / 10;
    rem -= rem / 10 * 10;
    d[5] = rem;

    start = 6 - digits;
    flag = 0;
    dst = (vu16 *)(VRAM + ((bgcnt >> 8) & 0x1F) * 0x800) + x + y * 32;
    for (i = start; i < 6; i++) {
        if (i <= 4) {
            if (d[i] == 0) {
                if (flag) {
                    *dst = base + d[i] * 2;
                    dst[32] = lower_digit_tile(base, d[i]);
                    *dst++;
                } else {
                    *dst = 0;
                    dst[32] = 0;
                    *dst++;
                }
            } else {
                *dst = base + d[i] * 2;
                dst[32] = lower_digit_tile(base, d[i]);
                *dst++;
                flag = 1;
            }
        } else {
            *dst = base + d[i] * 2;
            dst[32] = lower_digit_tile(base, d[i]);
            *dst++;
        }
    }
}

void sub_08042A90(u32 cur, u32 max, u32 x, u32 y, u32 tile, u32 bgcnt, u16 tile2) {
    u8 a[2];
    u8 b[2];
    u16 *dst;
    u32 i;
    u32 q;
    u8 *p;
    u8 *pa;

    pa = a;
    q = cur / 10;
    pa[0] = q;
    q = cur - q * 10;
    a[1] = q;
    p = b;
    q = max / 10;
    p[0] = q;
    q = max - q * 10;
    p[1] = q;
    dst = (u16 *)(VRAM + ((bgcnt >> 8) & 0x1F) * 0x800 + x * 2) + y * 32;
    for (i = 0; i < 2; i++) {
        if (a[i] == 0) {
            if (i == 1)
                *dst++ = tile2 + a[i];
        } else
            *dst++ = tile2 + a[i];
    }
    *dst++ = tile;
    for (i = 0; i < 2; i++) {
        if (b[i] == 0) {
            if (i == 1)
                *dst++ = tile2 + b[i];
        } else
            *dst++ = tile2 + b[i];
    }
}

void load_part_data(u32 part, u32 kind, u8 *dst) {
    u32 i;
    u8 *d = dst;
    for (i = 0; i < 16; i++)
        *d++ = gUnk_083B827C[part * 64 + kind * 16 + i];
}

// No return for a > 7: the original falls through with a still in r0.
u32 sub_08042B80(u32 a) {
    switch (a) {
    case 0:
    case 1:
    case 4:
    case 5:
        return 0;
    case 2:
    case 3:
    case 6:
        return 1;
    case 7:
        return 1;
    }
}

struct Coords16 calc_polar_to_screen_coords(u32 angle, u32 radius, s32 x, s32 y) {
    struct Coords16 r;

    x += (u32)(gUnk_083D6BA0[angle] * (radius / 256.0f));
    y += (u32)(gUnk_083D69A0[0][angle] * (radius / 256.0f));
    r.x = x & 0x1FF;
    r.y = y & 0xFF;
    return r;
}

struct Vec16 compute_polar_to_screen_position(u32 angle, u32 radius, u32 cx, u32 cy, u32 a, u32 b) {
    struct Vec16 r;

    if (radius < a)
        a = radius;
    if (radius < b)
        b = radius;
    cx += (u32)(gUnk_083D6BA0[angle] * ((radius - b) / 256.0f));
    cy += (u32)(gUnk_083D69A0[0][angle] * ((radius - a) / 256.0f));
    r.x = cx & 0x1FF;
    r.y = cy & 0xFF;
    return r;
}

// Decompresses 6 sprite tile chunks (0x80 bytes each in VRAM) into OBJ tile slot `slot` (0x400 bytes):
// chunk 0 from Medabot a, 1-2 from b, 3-4 from c, 5 from d (gUnk_083B1888 has 6 pointers per Medabot).
// The index is written as (n << 2) + (n << 1): `n * 6` compiles to (n * 3) << 1.
void decompress_sprite_to_vram_08042D94(u32 a, u32 b, u32 c, u32 d, u32 slot) {
    lz_decompress_dispatch(gUnk_083B1888[(a << 2) + (a << 1)], (void *)(VRAM + 0x10000 + slot * 0x400));
    lz_decompress_dispatch(gUnk_083B1888[(b << 2) + (b << 1) + 1], (void *)(VRAM + 0x10000 + 0x80 + slot * 0x400));
    lz_decompress_dispatch(gUnk_083B1888[(b << 2) + (b << 1) + 2], (void *)(VRAM + 0x10000 + 0x100 + slot * 0x400));
    lz_decompress_dispatch(gUnk_083B1888[(c << 2) + (c << 1) + 3], (void *)(VRAM + 0x10000 + 0x180 + slot * 0x400));
    lz_decompress_dispatch(gUnk_083B1888[(c << 2) + (c << 1) + 4], (void *)(VRAM + 0x10000 + 0x200 + slot * 0x400));
    lz_decompress_dispatch(gUnk_083B1888[(d << 2) + (d << 1) + 5], (void *)(VRAM + 0x10000 + 0x280 + slot * 0x400));
}

void init_battle_medabot_sprites(u32 head, u32 rarm, u32 larm, u32 legs, u32 tile, u32 sprite, u32 x, u32 y, u32 flip,
                                 u32 prio, u32 pal) {
    clear_battle_sprite_slot(sprite, 4);
    gUnk_03002C30[sprite].unk0 = 0xC004 | (prio << 10);
    if (flip)
        gUnk_03002C30[sprite].unk0 |= 0x1000;
    else
        gUnk_03002C30[sprite].unk0 &= 0xEFFF;
    gUnk_03002C30[sprite].unk2 = x;
    gUnk_03002C30[sprite].unk4 = y - 4;
    gUnk_03002C30[sprite].unk6 = tile * 8 + 0x500;
    gUnk_03002C30[sprite].unkA = gUnk_083BEA14[head];
    gUnk_03002C30[sprite].unk1C = 0;
    gUnk_03002C30[sprite].unkB = pal + 2;

    gUnk_03002C30[sprite + 1].unk0 = 0xC004 | (prio << 10);
    if (flip) {
        gUnk_03002C30[sprite + 1].unk0 |= 0x1000;
        gUnk_03002C30[sprite + 1].unk6 = tile * 8 + 0x502;
        gUnk_03002C30[sprite + 1].unkB = pal;
    } else {
        gUnk_03002C30[sprite + 1].unk0 &= 0xEFFF;
        gUnk_03002C30[sprite + 1].unk6 = tile * 8 + 0x501;
        gUnk_03002C30[sprite + 1].unkB = pal + 3;
    }
    gUnk_03002C30[sprite + 1].unk2 = x - 8;
    gUnk_03002C30[sprite + 1].unk4 = y + 4;
    gUnk_03002C30[sprite + 1].unkA = gUnk_083BEA14[rarm];
    gUnk_03002C30[sprite + 1].unk1C = 0;
    gUnk_03002C30[sprite + 1].unk8 = 0x40;
    gUnk_03002C30[sprite + 1].unk9 = 0x40;
    gUnk_03002C30[sprite + 1].unk18 = 0;

    gUnk_03002C30[sprite + 2].unk0 = 0xC004 | (prio << 10);
    if (flip) {
        gUnk_03002C30[sprite + 2].unk0 |= 0x1000;
        gUnk_03002C30[sprite + 2].unk6 = tile * 8 + 0x503;
        gUnk_03002C30[sprite + 2].unkB = pal + 3;
    } else {
        gUnk_03002C30[sprite + 2].unk0 &= 0xEFFF;
        gUnk_03002C30[sprite + 2].unk6 = tile * 8 + 0x504;
        gUnk_03002C30[sprite + 2].unkB = pal;
    }
    gUnk_03002C30[sprite + 2].unk2 = x + 8;
    gUnk_03002C30[sprite + 2].unk4 = y + 4;
    gUnk_03002C30[sprite + 2].unkA = gUnk_083BEA14[larm];
    gUnk_03002C30[sprite + 2].unk1C = 0;
    gUnk_03002C30[sprite + 2].unk8 = 0x40;
    gUnk_03002C30[sprite + 2].unk9 = 0x40;
    gUnk_03002C30[sprite + 2].unk18 = 0;

    gUnk_03002C30[sprite + 3].unk0 = 0xC004 | (prio << 10);
    if (flip)
        gUnk_03002C30[sprite + 3].unk0 |= 0x1000;
    else
        gUnk_03002C30[sprite + 3].unk0 &= 0xEFFF;
    gUnk_03002C30[sprite + 3].unk2 = x;
    gUnk_03002C30[sprite + 3].unk4 = y + 4;
    gUnk_03002C30[sprite + 3].unk6 = tile * 8 + 0x505;
    gUnk_03002C30[sprite + 3].unkA = gUnk_083BEA14[legs];
    gUnk_03002C30[sprite + 3].unk1C = 0;
    gUnk_03002C30[sprite + 3].unkB = pal + 1;
}

void setup_battle_sprite_group(u32 head, u32 rarm, u32 larm, u32 legs, u32 tile, u32 sprite, u32 x, u32 y, u32 flip,
                               u32 prio, u32 pal) {
    gUnk_03002C30[sprite].unk0 |= 0xC004 | (prio << 10);
    if (flip)
        gUnk_03002C30[sprite].unk0 |= 0x1000;
    else
        gUnk_03002C30[sprite].unk0 &= 0xEFFF;
    gUnk_03002C30[sprite].unk2 = x;
    gUnk_03002C30[sprite].unk4 = y - 4;
    gUnk_03002C30[sprite].unk6 = tile * 8 + 0x500;
    gUnk_03002C30[sprite].unkA = gUnk_083BEA14[head];
    gUnk_03002C30[sprite].unk1C = 0;
    gUnk_03002C30[sprite].unkB = pal + 2;

    gUnk_03002C30[sprite + 1].unk0 |= 0xC004 | (prio << 10);
    if (flip) {
        gUnk_03002C30[sprite + 1].unk0 |= 0x1000;
        gUnk_03002C30[sprite + 1].unk6 = tile * 8 + 0x502;
        gUnk_03002C30[sprite + 1].unkB = pal;
    } else {
        gUnk_03002C30[sprite + 1].unk0 &= 0xEFFF;
        gUnk_03002C30[sprite + 1].unk6 = tile * 8 + 0x501;
        gUnk_03002C30[sprite + 1].unkB = pal + 3;
    }
    gUnk_03002C30[sprite + 1].unk2 = x - 8;
    gUnk_03002C30[sprite + 1].unk4 = y + 4;
    gUnk_03002C30[sprite + 1].unkA = gUnk_083BEA14[rarm];
    gUnk_03002C30[sprite + 1].unk1C = 0;

    gUnk_03002C30[sprite + 2].unk0 |= 0xC004 | (prio << 10);
    if (flip) {
        gUnk_03002C30[sprite + 2].unk0 |= 0x1000;
        gUnk_03002C30[sprite + 2].unk6 = tile * 8 + 0x503;
        gUnk_03002C30[sprite + 2].unkB = pal + 3;
    } else {
        gUnk_03002C30[sprite + 2].unk0 &= 0xEFFF;
        gUnk_03002C30[sprite + 2].unk6 = tile * 8 + 0x504;
        gUnk_03002C30[sprite + 2].unkB = pal;
    }
    gUnk_03002C30[sprite + 2].unk2 = x + 8;
    gUnk_03002C30[sprite + 2].unk4 = y + 4;
    gUnk_03002C30[sprite + 2].unkA = gUnk_083BEA14[larm];
    gUnk_03002C30[sprite + 2].unk1C = 0;

    gUnk_03002C30[sprite + 3].unk0 |= 0xC004 | (prio << 10);
    if (flip)
        gUnk_03002C30[sprite + 3].unk0 |= 0x1000;
    else
        gUnk_03002C30[sprite + 3].unk0 &= 0xEFFF;
    gUnk_03002C30[sprite + 3].unk2 = x;
    gUnk_03002C30[sprite + 3].unk4 = y + 4;
    gUnk_03002C30[sprite + 3].unk6 = tile * 8 + 0x505;
    gUnk_03002C30[sprite + 3].unkA = gUnk_083BEA14[legs];
    gUnk_03002C30[sprite + 3].unk1C = 0;
    gUnk_03002C30[sprite + 3].unkB = pal + 1;
}

void battle_sprite_set_palette_index(u32 sprite, u32 pal) {
    u32 i;

    gUnk_03002C30[sprite + 1].unk0 |= 0x200;
    gUnk_03002C30[sprite + 2].unk0 |= 0x200;
    for (i = 0; i < 16; i++)
        ;
    gUnk_03002C30[sprite].unk24 = pal;
    gUnk_03002C30[sprite + 1].unk24 = pal;
    gUnk_03002C30[sprite + 2].unk24 = pal;
    gUnk_03002C30[sprite + 3].unk24 = pal;
}

void update_battle_sprite_orbiting_positions(u32 sprite, u32 idx, u32 c) {
    struct Coords16 v;
    u32 t;
    u8 a;

    gUnk_03002C30[sprite].unk2 = gUnk_03002C30[sprite + 3].unk2;
    gUnk_03002C30[sprite + 3].unk26 += gUnk_03002C30[sprite + 3].unk24;
    if (gUnk_03002C30[sprite + 3].unk26 > 0x3F) {
        gUnk_03002C30[sprite + 3].unk26 -= 0x40;
        gUnk_03002C30[sprite + 3].unk21 = (gUnk_03002C30[sprite + 3].unk21 + 1) & 3;
        gUnk_03002C30[sprite + 3].unk6 = idx * 8 + 0x505 + gUnk_083B296C[gUnk_03002C30[sprite + 3].unk21];
    }

    gUnk_03002C30[sprite + 1].unk26 += gUnk_03002C30[sprite + 1].unk24;
    a = gUnk_03002C30[sprite + 1].unk26;
    t = a >> 1;
    if (a > 0x3F) {
        t = 0x20;
        gUnk_03002C30[sprite + 1].unk26 -= 0x40;
    }
    switch (gUnk_03002C30[sprite + 1].unk21) {
    case 0:
        gUnk_03002C30[sprite + 1].unk18 = t * 4;
        v = calc_polar_to_screen_coords(t + 0x60, 5, gUnk_03002C30[sprite + 3].unk2, gUnk_03002C30[sprite + 3].unk4);
        gUnk_03002C30[sprite + 1].unk2 = v.x - 5;
        gUnk_03002C30[sprite + 1].unk4 = v.y - 3;
        break;
    case 1:
        gUnk_03002C30[sprite + 1].unk18 = 0x80 - t * 4;
        v = calc_polar_to_screen_coords(0x80 - t, 5, gUnk_03002C30[sprite + 3].unk2, gUnk_03002C30[sprite + 3].unk4);
        gUnk_03002C30[sprite + 1].unk2 = v.x - 5;
        gUnk_03002C30[sprite + 1].unk4 = v.y - 3;
        break;
    case 2:
        gUnk_03002C30[sprite + 1].unk18 = 0x400 - t * 4;
        v = calc_polar_to_screen_coords(0x60 - t, 5, gUnk_03002C30[sprite + 3].unk2, gUnk_03002C30[sprite + 3].unk4);
        gUnk_03002C30[sprite + 1].unk2 = v.x - 5;
        gUnk_03002C30[sprite + 1].unk4 = v.y - 3;
        break;
    case 3:
        gUnk_03002C30[sprite + 1].unk18 = t * 4 + 0x380;
        v = calc_polar_to_screen_coords(t + 0x40, 5, gUnk_03002C30[sprite + 3].unk2, gUnk_03002C30[sprite + 3].unk4);
        gUnk_03002C30[sprite + 1].unk2 = v.x - 5;
        gUnk_03002C30[sprite + 1].unk4 = v.y - 3;
        break;
    }
    if (t == 0x20)
        gUnk_03002C30[sprite + 1].unk21 = (gUnk_03002C30[sprite + 1].unk21 + 1) & 3;

    gUnk_03002C30[sprite + 2].unk26 += gUnk_03002C30[sprite + 2].unk24;
    a = gUnk_03002C30[sprite + 2].unk26;
    t = a >> 1;
    if (a > 0x3F) {
        t = 0x20;
        gUnk_03002C30[sprite + 2].unk26 -= 0x40;
    }
    switch (gUnk_03002C30[sprite + 2].unk21) {
    case 2:
        gUnk_03002C30[sprite + 2].unk18 = t * 4;
        v = calc_polar_to_screen_coords(t + 0x20, 5, gUnk_03002C30[sprite + 3].unk2, gUnk_03002C30[sprite + 3].unk4);
        gUnk_03002C30[sprite + 2].unk2 = v.x + 5;
        gUnk_03002C30[sprite + 2].unk4 = v.y - 3;
        break;
    case 3:
        gUnk_03002C30[sprite + 2].unk18 = 0x80 - t * 4;
        v = calc_polar_to_screen_coords(0x40 - t, 5, gUnk_03002C30[sprite + 3].unk2, gUnk_03002C30[sprite + 3].unk4);
        gUnk_03002C30[sprite + 2].unk2 = v.x + 5;
        gUnk_03002C30[sprite + 2].unk4 = v.y - 3;
        break;
    case 0:
        gUnk_03002C30[sprite + 2].unk18 = 0x400 - t * 4;
        v = calc_polar_to_screen_coords(0x20 - t, 5, gUnk_03002C30[sprite + 3].unk2, gUnk_03002C30[sprite + 3].unk4);
        gUnk_03002C30[sprite + 2].unk2 = v.x + 5;
        gUnk_03002C30[sprite + 2].unk4 = v.y - 3;
        break;
    case 1:
        gUnk_03002C30[sprite + 2].unk18 = t * 4 + 0x380;
        v = calc_polar_to_screen_coords(t, 5, gUnk_03002C30[sprite + 3].unk2, gUnk_03002C30[sprite + 3].unk4);
        gUnk_03002C30[sprite + 2].unk2 = v.x + 5;
        gUnk_03002C30[sprite + 2].unk4 = v.y - 3;
        break;
    }
    if (t == 0x20)
        gUnk_03002C30[sprite + 2].unk21 = (gUnk_03002C30[sprite + 2].unk21 + 1) & 3;

    if (gUnk_083B296C[gUnk_03002C30[sprite + 3].unk21]) {
        gUnk_03002C30[sprite].unk4 = gUnk_03002C30[sprite + 3].unk4 - 7;
        gUnk_03002C30[sprite + 1].unk4++;
        gUnk_03002C30[sprite + 2].unk4++;
    } else {
        gUnk_03002C30[sprite].unk4 = gUnk_03002C30[sprite + 3].unk4 - 8;
    }
}

void modify_medapart_quantity(u32 id, u32 kind, u32 byte, u32 subtract, u32 n) {
    if (subtract) {
        gMedapartInventory[kind * 240 + id * 2 + byte] -= n;
    } else {
        u8 *inv = gMedapartInventory;
        u8 *p = &inv[kind * 240 + id * 2 + byte];
        u32 v = *p + n;

        if (v > 99)
            v = 99;
        *p = v;
    }
}

void draw_tilemap_with_offset(u32 id, u32 x, u32 y, u32 bgcnt, u16 flags) {
    if (id == 0xFF)
        fill_tilemap_rect_08042698(2, 2, x, y, bgcnt, flags + 0x101C);
    else if (id >> 2)
        fill_tilemap_rect_08042698(2, 2, x, y, bgcnt, flags + id * 4 + 0x1000);
    else
        fill_tilemap_rect_08042698(2, 2, x, y, bgcnt, flags + id * 4);
}

// Previous/next owned Medal slot (guess). The backward search is a goto loop (no loop hoisting of 0x80)
// with two pointer locals for the two base copies (r2/r3) the original keeps.

u32 sub_0804361C(volatile u32 medal, volatile u32 backward) {
    if (backward) {
        if (medal != 0) {
            struct Unk_03000BE0 *p = gUnk_03000BE0;
            struct Unk_03000BE0 *q = gUnk_03000BE0;
        loop:
            medal--;
            if (q[medal].unk0 & 0x80) {
                if (!(p[medal].unk0 & 0x40))
                    return medal;
            }
            if (medal != 0)
                goto loop;
        }
    } else {
        do {
            medal++;
            if (medal == 31)
                medal = 0;
            if (medal == 30)
                goto none;
        } while (!(gUnk_03000BE0[medal].unk0 & 0x80) || (gUnk_03000BE0[medal].unk0 & 0x40));
        return medal;
    }
none:
    return 30;
}

u32 find_next_available_medapart_slot(vu32 part, vu32 kind, vu32 backward, vu32 gender) {
    if (backward) {
        while (part != 0) {
            part--;
            if (part == 0x78)
                part--;
            load_part_data(part, kind, gUnk_03000440.unk10E);
            if (gender == gUnk_03000440.unk10E[3] && gMedapartInventory[kind * 240 + part * 2] != 0 &&
                gMedapartInventory[kind * 240 + part * 2] - gMedapartInventory[kind * 240 + part * 2 + 1] != 0)
                goto found;
        }
    } else {
        while (1) {
            part++;
            if (gender != 0 && part == 0x78)
                part = 0x79;
            if (part == gender + 0x79)
                part = 0;
            if (part == gender + 0x78)
                return gender + 0x78;
            load_part_data(part, kind, gUnk_03000440.unk10E);
            if (gender == gUnk_03000440.unk10E[3] && gMedapartInventory[kind * 240 + part * 2] != 0 &&
                gMedapartInventory[kind * 240 + part * 2] - gMedapartInventory[kind * 240 + part * 2 + 1] != 0)
                return part;
        }
    }
    goto fail;
found:
    return part;
fail:
    return gender + 0x78;
}

u32 medabot_detail_is_full_set(void) {
    if (gUnk_03000440.unk98 != gUnk_03000440.unk99)
        return 0;
    if (gUnk_03000440.unk98 != gUnk_03000440.unk9A)
        return 0;
    if (gUnk_03000440.unk98 != gUnk_03000440.unk9B)
        return 0;
    return 1;
}

u32 validate_medapart_stats(u8 medal, u8 head, u8 rarm, u8 larm, u8 legs) {
    if (medal != 0x1E && head <= 0x77 && rarm <= 0x77 && larm <= 0x77 && legs <= 0x77)
        return 1;
    return 0;
}

u32 sub_0804384C(u8 medal) {
    u32 i;
    if (medal >= 0x1E)
        return 0xFF;
    for (i = 0; i < 9; i++)
        if (gUnk_030017A0[i].unk0 > 1 && gUnk_030017A0[i].unk2 == medal)
            return i;
    return 0xFF;
}

void load_battlefield_data_to_buffer(void) {
    memcpy_bytes_08041D04(gUnk_083BEA90[gUnk_030057E0.unk7FE], &gUnk_03000440.unkEE, 1);
    gUnk_030057E0.unkC29 = gUnk_03000440.unkEE;
    gUnk_030057E0.unkC2B = 0;
}

static inline u32 roll_encounter(void) {
    if ((rng_next_080424B8() & 0x1F) == 0x1F)
        return 1;
    return 0;
}

u32 check_random_encounter(void) {
    u8 n;

    if (gUnk_030057E0.unkC2D != 0)
        return 0;
    if (gUnk_030057E0.unkC5F != 0)
        return 0;
    if (gUnk_030057E0.unkC29 == 0)
        return 0;
    if (gUnk_030057E0.unkC2C & 1)
        return 0;
    n = ++gUnk_030057E0.unkC2B;
    if (n > 0x10 && (n > 0x1F || roll_encounter())) {
        gUnk_030057E0.unkC2B = 0;
        gUnk_030057E0.unkC2E = 0;
        gUnk_030057E0.unkC2F = 0;
        return 1;
    }
    return 0;
}

void sub_08043960(u32 phase, s32 amplitude, u32 lines) {
    s32 i;
    u32 idx;
    struct Vec16(*buf)[4];

    buf = !(gFrameCounter & 1) ? gUnk_02023200 : gUnk_02023C00;
    for (i = 0; i < 160; i++) {
        if (i < lines) {
            if ((i & 3) == 0) {
                idx = (i + phase) & 0xFF;
                gUnk_03000440.unk86 = (u32)(gUnk_083D69A0[0][idx] * (amplitude / 512.0f));
            }
            buf[i][0].x = gUnk_03000440.unk86 + (gBg0Scroll.x + gUnk_03002C2C.x);
            buf[i][0].y = gBg0Scroll.y + gUnk_03002C2C.y;
            buf[i][1].x = gUnk_03000440.unk86 + (gBg1Scroll.x + gUnk_03002C2C.x);
            buf[i][1].y = gBg1Scroll.y + gUnk_03002C2C.y;
            buf[i][2].x = gUnk_03000440.unk86 + (gBg2Scroll.x + gUnk_03002C2C.x);
            buf[i][2].y = gBg2Scroll.y + gUnk_03002C2C.y;
            buf[i][3].x = gUnk_03000440.unk86 + (gBg3Scroll.x + gUnk_03002C2C.x);
            buf[i][3].y = gBg3Scroll.y + gUnk_03002C2C.y;
        } else {
            buf[i][0].x = gBg0Scroll.x + gUnk_03002C2C.x;
            buf[i][0].y = gBg0Scroll.y + gUnk_03002C2C.y;
            buf[i][1].x = gBg1Scroll.x + gUnk_03002C2C.x;
            buf[i][1].y = gBg1Scroll.y + gUnk_03002C2C.y;
            buf[i][2].x = gBg2Scroll.x + gUnk_03002C2C.x;
            buf[i][2].y = gBg2Scroll.y + gUnk_03002C2C.y;
            buf[i][3].x = gBg3Scroll.x + gUnk_03002C2C.x;
            buf[i][3].y = gBg3Scroll.y + gUnk_03002C2C.y;
        }
    }
    gVBlankOnceCallback = sub_08043AE0;
}

// Own code (0x78) matches; the .s has a hidden function at 0x08043B58 (0x24 bytes) after the pool.
// Vblank-once callback: line 0 of the double-buffered per-scanline BG0-3 scroll table to BG0HOFS..BG3VOFS,
// then DMA0 (hblank, repeat, 4 words) for the remaining lines.
void sub_08043AE0(void) {
    vu32 *dma = (vu32 *)REG_ADDR_DMA0;
    u16 *src;

    if (!(gFrameCounter & 1))
        src = (u16 *)gUnk_02023200;
    else
        src = (u16 *)gUnk_02023C00;
    *(vu16 *)0x04000010 = src[0];
    *(vu16 *)0x04000012 = src[1];
    *(vu16 *)0x04000014 = src[2];
    *(vu16 *)0x04000016 = src[3];
    *(vu16 *)0x04000018 = src[4];
    *(vu16 *)0x0400001A = src[5];
    *(vu16 *)0x0400001C = src[6];
    *(vu16 *)0x0400001E = src[7];
    REG_DMA0CNT_H = 0;
    dma[0] = (u32)(src + 8);
    dma[1] = 0x04000010;
    dma[2] = 0xA6600004;
}

// guess: stops the scanline scroll wave started by sub_08043960
void sub_08043B58(void) {
    VBlankIntrWait();
    REG_DMA0CNT_H = 0;
    gVBlankOnceCallback = nullsub_08000840;
}

// Tileset idx (4 pointers per entry in gUnk_083B23F8): tiles -> VRAM 0x06008000, BG2 / BG3 tilemaps,
// BG palette -> gPaletteBackupBg (backup != 0) or straight to PLTT.
void decompress_tileset_to_vram(u32 idx, u32 backup) {
    u32 i;

    lz_decompress_dispatch(gUnk_083B23F8[i = idx * 4], (void *)(VRAM + 0x8000));
    set_tilemap_and_decompress_bg(0, 0, gUnk_083B23F8[i + 2], REG_BG2CNT, 0);
    set_tilemap_and_decompress_bg(0, 0, gUnk_083B23F8[i + 3], REG_BG3CNT, 0);
    if (backup)
        CpuFastSet(gUnk_083B23F8[i + 1], gPaletteBackupBg, 0x40);
    else
        CpuFastSet(gUnk_083B23F8[i + 1], (void *)PLTT, 0x40);
}

void decompress_sprite_to_vram_08043C08(u32 idx, u32 backup) {
    lz_decompress_dispatch(gUnk_083B24A8[idx * 5], (void *)(VRAM + 0x8000));
    set_tilemap_and_decompress_bg(0, 0, gUnk_083B24A8[idx * 5 + 3], REG_BG2CNT, 0);
    set_tilemap_and_decompress_bg(0, 0, gUnk_083B24A8[idx * 5 + 4], REG_BG3CNT, 0);
    if (backup)
        CpuFastSet(gUnk_083B24A8[idx * 5 + 2], gPaletteBackupBg, 0x40);
    else
        CpuFastSet(gUnk_083B24A8[idx * 5 + 2], (void *)PLTT, 0x40);
}

s32 sub_08043C94(void) {
    return rng_next_080424B8() * 100 / 255;
}

void sub_08043CA8(void) {
    gBg0Scroll.x = 0;
    gBg0Scroll.y = 0;
    gBg1Scroll.x = 0;
    gBg1Scroll.y = 0;
    gBg2Scroll.x = 0;
    gBg2Scroll.y = 0;
    gBg3Scroll.x = 0;
    gBg3Scroll.y = 0;
}

void update_scroll_movement_a(void) {
    vu8 *acc;
    u32 t;

    if (gUnk_03001800.unk39[0] == 0)
        return;
    acc = &gUnk_03001800.unk39[6];
    *acc = *(vu8 *)&gUnk_03001800.unk39[2] + *acc;
    if ((t = *acc >> 2) == 0)
        return;
    gUnk_03001800.unk39[7] = t;
    {
        u32 v = *acc;
        register u32 mask asm("r1") = 3; // pinned: the original loads the byte into r0, the mask into r1
        *acc = v & mask;
    }
    if (gUnk_03001800.unk39[1] & 1) {
        switch (gUnk_03001800.unk39[0]) {
        case 1:
            gBg2Scroll.y += gUnk_03001800.unk39[7];
            break;
        case 2:
            gBg3Scroll.y += gUnk_03001800.unk39[7];
            break;
        }
    }
    if (gUnk_03001800.unk39[1] & 2) {
        switch (gUnk_03001800.unk39[0]) {
        case 1:
            gBg2Scroll.y -= gUnk_03001800.unk39[7];
            break;
        case 2:
            gBg3Scroll.y -= gUnk_03001800.unk39[7];
            break;
        }
    }
    if (gUnk_03001800.unk39[1] & 4) {
        switch (gUnk_03001800.unk39[0]) {
        case 1:
            gBg2Scroll.x += gUnk_03001800.unk39[7];
            break;
        case 2:
            gBg3Scroll.x += gUnk_03001800.unk39[7];
            break;
        }
    }
    if (gUnk_03001800.unk39[1] & 8) {
        switch (gUnk_03001800.unk39[0]) {
        case 1:
            gBg2Scroll.x -= gUnk_03001800.unk39[7];
            break;
        case 2:
            gBg3Scroll.x -= gUnk_03001800.unk39[7];
            break;
        }
    }
}

void apply_battle_blend_effect_a(void) {
    if (gUnk_03001800.unk39[3]) {
        REG_BLDALPHA = (gUnk_03001800.unk39[4] << 8) | gUnk_03001800.unk39[5];
        REG_BLDY = 0;
        REG_BLDCNT = 0x1844;
    } else
        set_blend_effect_mode(0, 0, 0);
}

void sub_08043E48(void) {
    update_scroll_movement_a();
}

void load_battle_script_entry_b(void) {
    memcpy_bytes_0803F63C(gUnk_083C3B5C[gUnk_03001800.unk38], gUnk_03001800.unk74, 8);
}

void update_scroll_movement_b(void) {
    vu8 *acc;
    u32 t;

    if (gUnk_03001800.unk74[0] == 0)
        return;
    acc = &gUnk_03001800.unk74[6];
    *acc = *(vu8 *)&gUnk_03001800.unk74[2] + *acc;
    if ((t = *acc >> 2) == 0)
        return;
    gUnk_03001800.unk74[7] = t;
    {
        u32 v = *acc;
        register u32 mask asm("r1") = 3; // pinned: the original loads the byte into r0, the mask into r1
        *acc = v & mask;
    }
    if (gUnk_03001800.unk74[1] & 1) {
        switch (gUnk_03001800.unk74[0]) {
        case 1:
            gBg2Scroll.y += gUnk_03001800.unk74[7];
            break;
        case 2:
            gBg3Scroll.y += gUnk_03001800.unk74[7];
            break;
        }
    }
    if (gUnk_03001800.unk74[1] & 2) {
        switch (gUnk_03001800.unk74[0]) {
        case 1:
            gBg2Scroll.y -= gUnk_03001800.unk74[7];
            break;
        case 2:
            gBg3Scroll.y -= gUnk_03001800.unk74[7];
            break;
        }
    }
    if (gUnk_03001800.unk74[1] & 4) {
        switch (gUnk_03001800.unk74[0]) {
        case 1:
            gBg2Scroll.x += gUnk_03001800.unk74[7];
            break;
        case 2:
            gBg3Scroll.x += gUnk_03001800.unk74[7];
            break;
        }
    }
    if (gUnk_03001800.unk74[1] & 8) {
        switch (gUnk_03001800.unk74[0]) {
        case 1:
            gBg2Scroll.x -= gUnk_03001800.unk74[7];
            break;
        case 2:
            gBg3Scroll.x -= gUnk_03001800.unk74[7];
            break;
        }
    }
}

void apply_battle_blend_effect_b(void) {
    if (gUnk_03001800.unk74[3]) {
        REG_BLDALPHA = (gUnk_03001800.unk74[4] << 8) | gUnk_03001800.unk74[5];
        REG_BLDY = 0;
        REG_BLDCNT = 0x1844;
    } else
        set_blend_effect_mode(0, 0, 0);
}

void advance_battle_animation_frame(u32 field) {
    if (++gUnk_03001800.unk7D > 2) {
        gUnk_03001800.unk7D = 0;
        gUnk_03001800.unk7C = (gUnk_03001800.unk7C + 1) & 0x7F;
        memcpy_bytes_08041D04(&gUnk_083C40B8[field], &gUnk_03001800.unk7E, 1);
        memcpy_bytes_08041D04(&gUnk_083C40C3[field * 128 + gUnk_03001800.unk7C], &gUnk_03001800.unk7F, 1);
        if (gUnk_03001800.unk7F == 0xFF) {
            gUnk_03001800.unk7C = 0;
            memcpy_bytes_08041D04(&gUnk_083C40C3[field * 128], &gUnk_03001800.unk7F, 1);
        }
        CpuSet((void *)(0x02027000 + gUnk_03001800.unk7E * gUnk_03001800.unk7F * 32), (void *)(VRAM + 0x8020),
               (gUnk_03001800.unk7E * 8) | 0x04000000);
    }
}

void sub_08044094(void) {
    gGameMode = 1;
    gGameState = 1;
    gGameSubState = 7;
}

u32 sub_080440B4(void) {
    u32 n = 0;
    u32 i;

    for (i = 0; i < 9; i++)
        if (gUnk_030017A0[i].unk0 == 3)
            n++;
    return n;
}

u32 sub_080440D4(void) {
    u32 i;

    for (i = 0; i < 480; i++)
        if (gMedapartInventory[i * 2] != gMedapartInventory[i * 2 + 1])
            return 0;
    return 1;
}

void battle_vblank_update_bg(void) {
    update_scroll_movement_b();
    advance_battle_animation_frame(gUnk_03001800.unk38);
}

void read_vram_tilemap_rect(u32 w, u32 h, u32 x, u32 y, u32 bgcnt, void *dst) {
    u32 i, j;
    u16 *d = dst;
    u16 *base = (u16 *)(VRAM + ((bgcnt >> 8) & 0x1F) * 0x800) + x + y * 32;

    for (j = 0; j < h; j++) {
        u16 *p = base + j * 32;
        for (i = 0; i < w; i++)
            *d++ = *p++;
    }
}

void write_vram_tilemap_rect(u32 w, u32 h, u32 x, u32 y, u32 bgcnt, const void *src) {
    u32 i, j;
    const u16 *s = src;
    u16 *base = (u16 *)(VRAM + ((bgcnt >> 8) & 0x1F) * 0x800) + x + y * 32;

    for (j = 0; j < h; j++) {
        u16 *p = base + j * 32;
        for (i = 0; i < w; i++)
            *p++ = *s++;
    }
}

void decompress_to_ewram_27000(const u8 *src) {
    lz_decompress_dispatch(src, (void *)0x02027000);
}

void race_enter_team_select(void) {
    u32 a = 0;
    u32 b;

    CpuFastSet(&a, (void *)OBJ_PLTT, 0x01000080);
    b = 0;
    CpuFastSet(&b, (void *)PLTT, 0x01000080);
    sub_0803F624(&gUnk_03000440.unk50, 0x14, 0);
    gUnk_03000440.unk50 = 3;
    gUnk_03001800.unk41[0] = 0;
    gUnk_03001800.unk41[1] = 0;
    gUnk_03001800.unk41[2] = 0;
    gGameMode = 0;
    gGameState = 3;
    gGameSubState = 0;
}

// Sprite slot: while unk24 (table, 1-based) is set, add the (x, y) step for frame unk27 & 3 of row unk25
// from gUnk_083C6DF8 to unk4 (wrapped to 0xFF) and unk2 (wrapped to 0x1FF), then advance unk27.
void update_sprite_animation_position(u32 slot) {
    s32 mask = 0x1FF;

    if (gUnk_03002C30[slot].unk24 != 0) {
        gUnk_03002C30[slot].unk4 =
            (gUnk_03002C30[slot].unk4 +
             gUnk_083C6DF8[(gUnk_03002C30[slot].unk24 - 1) * 256 + gUnk_03002C30[slot].unk25 * 8 +
                           (gUnk_03002C30[slot].unk27 & 3) * 2]) &
            0xFF;
        gUnk_03002C30[slot].unk2 =
            (gUnk_03002C30[slot].unk2 +
             gUnk_083C6DF8[(gUnk_03002C30[slot].unk24 - 1) * 256 + gUnk_03002C30[slot].unk25 * 8 +
                           (gUnk_03002C30[slot].unk27 & 3) * 2 + 1]) &
            mask;
        gUnk_03002C30[slot].unk27++;
    }
}

u32 calculate_direction_index(s32 x, s32 y, s32 tx, s32 ty) {
    s32 sx, sy;
    float dx, dy;
    s32 r;

    if (x <= tx) {
        sx = 0;
        dx = tx - x;
    } else {
        sx = 1;
        dx = x - tx;
    }
    if (y <= ty) {
        sy = 0;
        dy = ty - y;
    } else {
        sy = 1;
        dy = y - ty;
    }

    if (sx == 0) {
        if (sy == 0) {
            if (dx == 0)
                return 0x10;
            if (dy == 0)
                return 8;
            if (dx == dy)
                return 0xC;
            if (dx > dy) {
                r = (dx + dy * 0.5f) / dy;
                if (r > 4) {
                    r = (gFrameCounter & 3) ? 4 : 3;
                }
                return 0xC - r;
            } else {
                r = (dy + dx * 0.5f) / dx;
                if (r > 4) {
                    r = (gFrameCounter & 3) ? 4 : 3;
                }
                return r + 0xC;
            }
        } else if (sy == 1) {
            if (dx == 0)
                return 0;
            if (dy == 0)
                return 8;
            if (dx == dy)
                return 4;
            if (dx > dy) {
                r = (dx + dy * 0.5f) / dy;
                if (r > 4) {
                    r = (gFrameCounter & 3) ? 4 : 3;
                }
                return r + 4;
            } else {
                r = (dy + dx * 0.5f) / dx;
                if (r > 4) {
                    r = (gFrameCounter & 3) ? 4 : 3;
                }
                return 4 - r;
            }
        }
    }
    if (sx == 1) {
        if (sy == 1) {
            if (dx == 0)
                return 0;
            if (dy == 0)
                return 0x18;
            if (dx == dy)
                return 0x1C;
            if (dx > dy) {
                r = (dx + dy * 0.5f) / dy;
                if (r > 4) {
                    r = (gFrameCounter & 3) ? 4 : 3;
                }
                return 0x1C - r;
            } else {
                r = (dy + dx * 0.5f) / dx;
                if (r > 4) {
                    r = (gFrameCounter & 3) ? 4 : 3;
                }
                return r + 0x1C;
            }
        } else if (sy == 0) {
            if (dx == 0)
                return 0x10;
            if (dy == 0)
                return 0x18;
            if (dx == dy)
                return 0x14;
            if (dx > dy) {
                r = (dx + dy * 0.5f) / dy;
                if (r > 4) {
                    r = (gFrameCounter & 3) ? 4 : 3;
                }
                return r + 0x14;
            } else {
                r = (dy + dx * 0.5f) / dx;
                if (r > 4) {
                    r = (gFrameCounter & 3) ? 4 : 3;
                }
                return 0x14 - r;
            }
        }
    }
}

void init_scene_buffers_080445F4(void) {
    struct Unk_08047414 *obj = (struct Unk_08047414 *)0x02026000;
    u8 *b;
    u8 *c;
    u32 fill;
    u32 fill2;

    sub_0803F624((u8 *)obj, 0xD0, 0);
    b = (u8 *)0x020260D0;
    sub_0803F624(b, 0x820, 0);
    c = (u8 *)0x020268F0;
    sub_0803F624(c, 0x60, 0);
    gUnk_03000430 = 2;
    gUnk_03002414 = (struct Unk_03002414 *)0x02024000;
    fill = 0;
    CpuFastSet(&fill, (void *)0x02024000, 0x01000426);
    gUnk_03005308 = (struct SceneSlot *)c;
    fill2 = 0x200;
    CpuFastSet(&fill2, gUnk_03002414->unkB84, 0x01000100);
    gUnk_03002414->unk1094 = 0;
    gUnk_03002414->unk1095 = 0;
    sub_08047414(obj, (u8 *)gUnk_03002414, (struct SpriteNodeDesc **)gUnk_083D1BF8, (struct SpriteNodeOam *)b);
}

// K&R definitions: the callers were compiled without a prototype (promoted int arguments), and the
// callee narrows its parameters itself. A prototype with u8 / u16 parameters changes the callers.
void setup_scene_with_bg_and_sprites(slot, head, rarm, larm, legs, y, x, f, g, h, i, j) u32 slot;
u8 head, rarm, larm, legs;
u16 y, x;
u32 f;
u8 g, h, i, j;
{
    u32 flags;
    u32 fill;

    switch (f) {
    case 0:
        f = 100;
        break;
    case 1:
        f = 200;
        break;
    case 2:
        f = 300;
        break;
    case 3:
        f = 400;
        break;
    }
    if (h == 0)
        h = 1;
    else
        h = 2;
    flags = 0;
    if (i == 1)
        flags = 4;
    ((struct Unk_08047414 *)0x02026000)->oams = (struct SpriteNodeOam *)(0x020260D0 + slot * 0x410);
    setup_scene_bg_layers_and_sprites(gUnk_03002414->unkB84, (struct Unk_08047414 *)0x02026000, head, rarm, larm, legs,
                                      (s16)x, (s16)y, f, g, h | flags, j);
    if (i == 2) {
        fill = 0x200;
        CpuFastSet(&fill, gUnk_03002414->unkB84, 0x01000100);
        gUnk_03002414->unk1094 = 0;
        gUnk_03002414->unk1095 = 0;
    }
}

void init_scene_with_bg_and_palette(slot, head, rarm, larm, legs, y, x, f, g, h, i, j, base) u32 slot;
u8 head, rarm, larm, legs;
u16 y, x;
u32 f;
u8 g, h, i, j, base;
{
    u32 flags;
    u32 fill;

    switch (f) {
    case 0:
        f = base + 100;
        break;
    case 1:
        f = base + 200;
        break;
    case 2:
        f = base + 300;
        break;
    case 3:
        f = base + 400;
        break;
    }
    if (h == 0)
        h = 1;
    else
        h = 2;
    flags = 0;
    if (i == 1)
        flags = 4;
    ((struct Unk_08047414 *)0x02026000)->oams = (struct SpriteNodeOam *)(0x020260D0 + slot * 0x410);
    setup_scene_bg_layers_and_sprites(gUnk_03002414->unkB84, (struct Unk_08047414 *)0x02026000, head, rarm, larm, legs,
                                      (s16)x, (s16)y, f, g, h | flags, j);
    if (i == 2) {
        fill = 0x200;
        CpuFastSet(&fill, gUnk_03002414->unkB84, 0x01000100);
        gUnk_03002414->unk1094 = 0;
        gUnk_03002414->unk1095 = 0;
    }
}

void setup_sprite_animation_entry(u32 a, u8 id, u8 kind, u16 y, u16 x, u32 f, u8 g, u8 h, u8 i) {
    u32 flags;
    u32 fill;

    switch (f) {
    case 0:
        f = 100;
        break;
    case 1:
        f = 200;
        break;
    case 2:
        f = 300;
        break;
    case 3:
        f = 400;
        break;
    }
    if (h == 0)
        h = 1;
    else
        h = 2;
    flags = 0;
    if (i == 1)
        flags = 4;
    ((struct Unk_08047414 *)0x02026000)->oams = (struct SpriteNodeOam *)(0x020260D0 + a * 0x410);
    load_sprite_animation_by_type(gUnk_03002414->unkB84, (struct Unk_08047414 *)0x02026000, id, kind, (s16)x, (s16)y, f,
                                  g, h | flags);
    if (i == 2) {
        fill = 0x200;
        CpuFastSet(&fill, gUnk_03002414->unkB84, 0x01000100);
        gUnk_03002414->unk1094 = 0;
        gUnk_03002414->unk1095 = 0;
    }
}

u32 advance_text_display(u32 a0, u32 a1, u32 a2) {
    u32 n;
    u8 *cnt;
    u8 *pos;
    u32 zero;
    s32 done;
    register struct Unk_08047414 *obj asm("r1"); // pinned: the original loads 0x02026000 before 0x020260CE
    // `done` is deliberately uninitialized: the original reads ip when *pos >= n

    a1 = gUnk_0807E77C[a1][gUnk_083CABF8[a2]];
    n = 0;
    if (gUnk_083D1E98[a1][0] != 0) {
        do {
            n++;
            if (n > 0xFE)
                break;
        } while (gUnk_083D1E98[a1][n] != 0);
    }
    cnt = (u8 *)0x020260CC + a0;
    {
        // (*cnt)++ with the zero set between the add and the store
        u8 c = *cnt + 1;
        zero = 0;
        *cnt = c;
    }
    obj = (struct Unk_08047414 *)0x02026000;
    pos = (u8 *)0x020260CE + a0;
    if (*pos < n) {
        obj->oams = (struct SpriteNodeOam *)(0x020260D0 + a0 * 0x410);
        done = interpolate_entity_positions((struct InterpEnt *)obj->oams, gUnk_083D1CC0[a1], gUnk_083D1DAC[a1],
                                            gUnk_083D1E98[a1], a1, *cnt, *pos, 0x40, n);
    }
    if (done) {
        if (++(*pos) >= n) {
            *pos = zero;
            *cnt = zero;
            return 1;
        }
        *cnt = zero;
    }
    return 0;
}

void sub_08044B28(const u8 *src, void *dst) {
    lz_decompress_dispatch(src, dst);
}

u32 sub_08044B34(u8 a) {
    if (a == 0)
        return gUnk_083B2970[gUnk_030057E0.unkC5C];
    return a;
}

void sub_08044B58(void) {
    gUnk_03000BE0[0].unk0 |= 0xC0;
    gUnk_030017A0[0].unk0 = 3;
    gUnk_030017A0[0].unk2 = 0;
    gUnk_030017A0[0].unk3 = 0x2A;
    gUnk_030017A0[0].unk4 = 0x2A;
    gUnk_030017A0[0].unk5 = 0x2A;
    gUnk_030017A0[0].unk6 = 0x2A;
    gMedapartInventory[0 * 240 + 0x2A * 2 + 1] = 1;
    gMedapartInventory[1 * 240 + 0x2A * 2 + 1] = 1;
    gMedapartInventory[2 * 240 + 0x2A * 2 + 1] = 1;
    gMedapartInventory[3 * 240 + 0x2A * 2 + 1] = 1;
}

void init_battle_scene(u32 mode, u32 id) {
    sub_08043CA8();
    clear_battle_sprite_slot(0, 0x80);
    gUnk_03000440.unk96 = 0;
    gUnk_03000430 = 0;
    sub_0803F624(&gUnk_03000440.unk3C, 0x14, 0);
    gUnk_03000440.unk3C = 3;
    gUnk_03000440.unk3D = id;
    switch (mode) {
    case 0:
        gUnk_03000440.unk3E = 0;
        break;
    case 1:
        gUnk_03000440.unk3E = mode;
        break;
    case 2:
        gUnk_03000440.unk3E = mode;
        break;
    case 3:
        gUnk_03000440.unk3E = mode;
        break;
    }
    gGameMode = 0;
    gGameState = 5;
    gGameSubState = 0x10;
}

void init_game_mode(u32 mode) {
    sub_08043CA8();
    sub_0803F624(&gUnk_03000440.unk3C, 0x14, 0);
    sub_0803F624(&gUnk_03000440.unk3C + 0x14, 0x14, 0);
    gUnk_03000440.unk89 = 1;
    gUnk_03000440.unk8D = 0;
    switch (mode) {
    case 0:
        gUnk_03000440.unk3C = 4;
        gGameMode = 0;
        gGameState = 4;
        gGameSubState = 0;
        break;
    case 1:
        gUnk_03000440.unk3C = 4;
        gGameMode = 0;
        gGameState = 5;
        gGameSubState = 0;
        break;
    case 2:
        gUnk_03000440.unk138 = 0;
        gGameMode = 0;
        gGameState = 10;
        gGameSubState = 0;
        break;
    case 3:
        gUnk_03000440.unk138 = 1;
        gGameMode = 0;
        gGameState = 10;
        gGameSubState = 0;
        break;
    }
}

void sub_08044CDC(u32 a) {
    switch (a) {
    case 0:
        sub_08064A74();
        break;
    case 1:
        sub_08064A94();
        break;
    case 2:
        sub_08064AB4();
        break;
    case 3:
        sub_08064AD4();
        break;
    }
}

u32 dma3_copy_or_decompress(const u32 *src, void *dst) {
    u32 hdr = *src;
    u32 size = hdr >> 8;

    if (((hdr << 24) >> 28) == 1) {
        LZ77UnCompWram(src, dst);
    } else {
        vu32 *dma;

        CpuCopy16(src, dst, size / 2);
        dma = (vu32 *)REG_ADDR_DMA3;
        dma[0] = (u32)src + size / 2;
        dma[1] = (u32)dst + size / 2;
        dma[2] = 0x80000000 | (size / 2 / 2);
        dma[2];
    }
    return size;
}

u32 sub_08044D64(u32 *dst, const u32 *src, u32 n) {
    while (n > 3) {
        *dst++ = *src++;
        n -= 4;
    }
    return n;
}

u32 sub_08044D78(u16 *dst, const u16 *src, u32 n) {
    while (n > 1) {
        *dst++ = *src++;
        n -= 2;
    }
    return n;
}

void sub_08044D90(u8 *dst, const u8 *src, u32 n) {
    while (n != 0) {
        *dst++ = *src++;
        n--;
    }
}

void set_oam_sprite_shape_size(u8 *oam, s32 h, s32 w) {
    if (h > w) {
        oam[1] = (oam[1] & 0x3F) | 0x80;
        if (h == 8)
            oam[3] = oam[3] & 0x3F;
        else if (h == 64)
            oam[3] |= 0xC0;
        else if (w == 8)
            oam[3] = (oam[3] & 0x3F) | 0x40;
        else
            oam[3] = (oam[3] & 0x3F) | 0x80;
    } else if (h < w) {
        oam[1] = (oam[1] & 0x3F) | 0x40;
        if (w == 8)
            oam[3] = oam[3] & 0x3F;
        else if (w == 64)
            oam[3] |= 0xC0;
        else if (h == 8)
            oam[3] = (oam[3] & 0x3F) | 0x40;
        else
            oam[3] = (oam[3] & 0x3F) | 0x80;
    } else {
        oam[1] = oam[1] & 0x3F;
        if (h == 8)
            oam[3] = oam[3] & 0x3F;
        else if (h == 16)
            oam[3] = (oam[3] & 0x3F) | 0x40;
        else if (h == 32)
            oam[3] = (oam[3] & 0x3F) | 0x80;
        else
            oam[3] |= 0xC0;
    }
}

u32 sub_08044E64(s32 shape, s32 size) {
    u32 dims = 0;

    switch (shape) {
    case 0:
        switch (size) {
        case 0:
            dims = 0x00080008;
            break;
        case 0x40000000:
            dims = 0x00100010;
            break;
        case (s32)0x80000000:
            dims = 0x00200020;
            break;
        case (s32)0xC0000000:
            dims = 0x00400040;
            break;
        }
        break;
    case 0x4000:
        switch (size) {
        case 0:
            dims = 0x00080010;
            break;
        case 0x40000000:
            dims = 0x00080020;
            break;
        case (s32)0x80000000:
            dims = 0x00100020;
            break;
        case (s32)0xC0000000:
            dims = 0x00200040;
            break;
        }
        break;
    case 0x8000:
        switch (size) {
        case 0:
            dims = 0x00100008;
            break;
        case 0x40000000:
            dims = 0x00200008;
            break;
        case (s32)0x80000000:
            dims = 0x00200010;
            break;
        case (s32)0xC0000000:
            dims = 0x00400020;
            break;
        }
        break;
    }
    return dims;
}
