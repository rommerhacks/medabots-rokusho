// Inventory: the Medal list (find / add / remove / export), Medapart counts, the team of Tinpets, the item
// list (gItemInventory) and the bubble sorts of SORT_BUFFER used to order those lists on screen. Called by
// the menus, the debug menu, battles (rewards) and link trades.

#include "global.h"

static u32 medal_new_level(void);

void medal_list_init_order(void) {
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
            gUnk_03000BE0[i].unk5 = medal_new_level();
            gUnk_03000BE0[i].unk8 = medal_tier_for_level(gUnk_03000BE0[i].unk5, gUnk_03000440.unkF1,
                                                         gUnk_03000440.unkF2, gUnk_03000440.unkF3, gUnk_03000440.unkF4);
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
            mem_fill8((u8 *)&gUnk_03000BE0[i], 0x40, 0);
            gUnk_03000BE0[i].unk0 = f;
            return;
        }
    }
}

void medal_add_from_buffer(const void *src) {
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

// Level for a new Medal: halfway between the highest and the fourth-highest Medal levels.
static u32 medal_new_level(void) {
    u32 zero = 0;
    struct SortEntry *e = SORT_BUFFER;
    struct Unk_03000BE0 *m;
    u32 i;

    CpuFastSet(&zero, e, 0x01000080);
    for (i = 0, m = gUnk_03000BE0; i < 30; m++, e++, i++)
        e->key = m->unk5;
    sort_buffer_descending(30);
    return (SORT_BUFFER[0].key - SORT_BUFFER[3].key) / 2 + SORT_BUFFER[3].key;
}

// How many of the thresholds a-d (0 = none) level reaches (0-4).
u32 medal_tier_for_level(u8 level, u8 a, u8 b, u8 c, u8 d) {
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

u32 medapart_get_counts(u8 a, u8 b) {
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

void team_init_order(void) {
    u32 i;
    for (i = 0; i < 9; i++)
        gUnk_030017A0[i].unk7 = i;
}

// The Medabot with Medal medal loses its part of kind kind: back to the bare Tinpet part, one less owned.
void team_lose_equipped_part(u8 medal, u8 kind) {
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

// Removes n of item id; when the count drops to 0 the entry is cleared
// and bubbled to the end of the list.
void item_remove_quantity(u8 id, u8 n) {
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

static void sort_buffer_ascending(u8 n) {
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

void sort_buffer_descending(u8 n) {
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
