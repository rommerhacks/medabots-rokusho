// Inventory: the Medal list (find / add / remove / export), Medapart counts, the team of Tinpets, the item
// list (gItemInventory) and the bubble sorts of SORT_BUFFER used to order those lists on screen. Called by
// the menus, the debug menu, battles (rewards) and link trades.

#include "global.h"

static u32 medal_new_level(void);

void medal_list_init_order(void) {
    u32 i;
    for (i = 0; i < 30; i++)
        gMedals[i].flags = i;
}

u32 find_medal_slot_by_id(u8 id) {
    u32 i;

    for (i = 0; i < 30; i++)
        if ((gMedals[i].flags & 0x80) && gMedals[i].graphicId == id)
            return i + 1;
    return 0;
}

u32 medal_add_by_id(u8 id) {
    u32 i;

    memcpy_bytes_08041D04(gMedalRecords[id], &gGameWork.partAbility, 16);
    for (i = 0; i < 30; i++) {
        if (!(gMedals[i].flags & 0x80)) {
            gMedals[i].flags |= 0x80;
            gMedals[i].graphicId = id;
            gMedals[i].attribute = gGameWork.partSkill;
            gMedals[i].aimSkillType = gGameWork.partSkillType;
            gMedals[i].compatibility = gGameWork.partStat3;
            gMedals[i].level = medal_new_level();
            gMedals[i].spriteVariant = medal_tier_for_level(gMedals[i].level, gGameWork.partGender, gGameWork.partStat0,
                                                            gGameWork.partStat1, gGameWork.partStat2);
            gMedals[i].nextLevelExp = (gMedals[i].level + 1) * 100;
            if ((u8)(gMedals[i].level / 10) * gGameWork.partStat4 + gGameWork.partStat4 > 100)
                gMedals[i].skillLevel[0] = 100;
            else
                gMedals[i].skillLevel[0] = gGameWork.partStat4 + gGameWork.partStat4 * (gMedals[i].level / 10);
            if ((u8)(gMedals[i].level / 10) * gGameWork.partStat5 + gGameWork.partStat5 > 100)
                gMedals[i].skillLevel[1] = 100;
            else
                gMedals[i].skillLevel[1] = gGameWork.partStat5 + gGameWork.partStat5 * (gMedals[i].level / 10);
            if ((u8)(gMedals[i].level / 10) * gGameWork.fillerF8[0] + gGameWork.fillerF8[0] > 100)
                gMedals[i].skillLevel[2] = 100;
            else
                gMedals[i].skillLevel[2] = gGameWork.fillerF8[0] + gGameWork.fillerF8[0] * (gMedals[i].level / 10);
            if ((u8)(gMedals[i].level / 10) * gGameWork.fillerF8[1] + gGameWork.fillerF8[1] > 100)
                gMedals[i].skillLevel[3] = 100;
            else
                gMedals[i].skillLevel[3] = gGameWork.fillerF8[1] + gGameWork.fillerF8[1] * (gMedals[i].level / 10);
            if ((u8)(gMedals[i].level / 10) * gGameWork.fillerF8[2] + gGameWork.fillerF8[2] > 100)
                gMedals[i].skillLevel[4] = 100;
            else
                gMedals[i].skillLevel[4] = gGameWork.fillerF8[2] + gGameWork.fillerF8[2] * (gMedals[i].level / 10);
            if ((u8)(gMedals[i].level / 10) * gGameWork.fillerF8[3] + gGameWork.fillerF8[3] > 100)
                gMedals[i].skillLevel[5] = 100;
            else
                gMedals[i].skillLevel[5] = gGameWork.fillerF8[3] + gGameWork.fillerF8[3] * (gMedals[i].level / 10);
            if ((u8)(gMedals[i].level / 10) * gGameWork.fillerF8[4] + gGameWork.fillerF8[4] > 100)
                gMedals[i].skillLevel[6] = 100;
            else
                gMedals[i].skillLevel[6] = gGameWork.fillerF8[4] + gGameWork.fillerF8[4] * (gMedals[i].level / 10);
            if ((u8)(gMedals[i].level / 10) * gGameWork.fillerF8[5] + gGameWork.fillerF8[5] > 100)
                gMedals[i].skillLevel[7] = 100;
            else
                gMedals[i].skillLevel[7] = gGameWork.fillerF8[5] + gGameWork.fillerF8[5] * (gMedals[i].level / 10);
            return i;
        }
    }
    return i;
}

void medal_remove_by_id(u8 id) {
    u32 i;

    for (i = 0; i < 30; i++) {
        if ((gMedals[i].flags & 0x80) && gMedals[i].graphicId == id) {
            u8 slot_order = gMedals[i].flags & 0x1F;
            mem_fill8((u8 *)&gMedals[i], 0x40, 0);
            gMedals[i].flags = slot_order;
            return;
        }
    }
}

void medal_add_from_buffer(const void *src) {
    u32 i;

    for (i = 0; i < 30; i++) {
        if (!(gMedals[i].flags & 0x80)) {
            u32 slot_order = gMedals[i].flags & 0x1F;
            memcpy_bytes_0803F63C(src, &gMedals[i], 0x40);
            gMedals[i].flags = (gMedals[i].flags & 0x80) | slot_order;
            return;
        }
    }
}

// Level for a new Medal: halfway between the highest and the fourth-highest Medal levels.
static u32 medal_new_level(void) {
    u32 zero = 0;
    struct SortEntry *entry = SORT_BUFFER;
    struct MedalData *medal;
    u32 i;

    CpuFastSet(&zero, entry, 0x01000080);
    for (i = 0, medal = gMedals; i < 30; medal++, entry++, i++)
        entry->key = medal->level;
    sort_buffer_descending(30);
    return (SORT_BUFFER[0].key - SORT_BUFFER[3].key) / 2 + SORT_BUFFER[3].key;
}

// How many of the thresholds tier1_level..tier4_level (0 = none) level reaches (0-4).
u32 medal_tier_for_level(u8 level, u8 tier1_level, u8 tier2_level, u8 tier3_level, u8 tier4_level) {
    if (tier4_level != 0 && level >= tier4_level)
        return 4;
    if (tier3_level != 0 && level >= tier3_level)
        return 3;
    if (tier2_level != 0 && level >= tier2_level)
        return 2;
    if (tier1_level != 0 && level >= tier1_level)
        return 1;
    return 0;
}

u32 medapart_get_counts(u8 part_id, u8 kind) {
    u32 hi = gMedapartInventory[kind * 240 + part_id * 2] << 8;
    return gMedapartInventory[kind * 240 + part_id * 2 + 1] | hi;
}

void medapart_add_quantity(u8 id, u8 kind, u8 n) {
    u8 *inv = gMedapartInventory;
    u8 *count_ptr = &inv[kind * 240 + id * 2];
    s32 total = n + *count_ptr;

    if (total > 99)
        *count_ptr = 99;
    else
        *count_ptr = total;
}

void reduce_medapart_stat(u8 id, u8 kind, u8 n) {
    u8 *inv = gMedapartInventory;
    u8 *count_ptr = &inv[kind * 240 + id * 2];
    s32 remaining = *count_ptr - n;

    if (remaining < 0)
        remaining = 0;
    *count_ptr = remaining;
}

void team_init_order(void) {
    u32 i;
    for (i = 0; i < 9; i++)
        gTeamSlots[i].slotId = i;
}

// The Medabot in team slot slot_id loses its part of kind kind: back to the bare Tinpet part, one less owned.
void team_lose_equipped_part(u8 slot_id, u8 kind) {
    u32 i;

    for (i = 0; i < 9; i++) {
        if (gTeamSlots[i].slotId == slot_id) {
            u8 *parts = &gTeamSlots[i].head;
            u8 old_part = parts[kind];

            parts[kind] = gTeamSlots[i].gender + 0x78;
            gTeamSlots[i].state = 2;
            gMedapartInventory[kind * 240 + old_part * 2]--;
            gMedapartInventory[kind * 240 + old_part * 2 + 1]--;
            return;
        }
    }
}

u32 team_is_full(void) {
    u32 i;

    for (i = 0; i < 9; i++)
        if (gTeamSlots[i].state == 0)
            return 0;
    return 1;
}

void team_add_tinpet(u8 gender) {
    u32 i;

    for (i = 0; i < 9; i++) {
        if (gTeamSlots[i].state == 0) {
            gTeamSlots[i].state = 1;
            gTeamSlots[i].gender = gender & 1;
            gTeamSlots[i].medal = 0x1E;
            gTeamSlots[i].head = (gender & 1) + 0x78;
            gTeamSlots[i].rightArm = (gender & 1) + 0x78;
            gTeamSlots[i].leftArm = (gender & 1) + 0x78;
            gTeamSlots[i].legs = (gender & 1) + 0x78;
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
    u16 tmp_key, tmp_key2, tmp_value, tmp_value2;
    u32 j;
    struct SortEntry *cur, *next;

    if (n <= 1)
        return;
    for (n--; n != 0; n--) {
        for (j = 0; j < n; j++) {
            cur = &SORT_BUFFER[j];
            next = &SORT_BUFFER[j + 1];
            if (cur->key > next->key) {
                tmp_key = cur->key;
                tmp_key2 = cur->key2;
                tmp_value = cur->value;
                tmp_value2 = cur->value2;
                cur->key = next->key;
                cur->key2 = next->key2;
                cur->value = next->value;
                cur->value2 = next->value2;
                next->key = tmp_key;
                next->key2 = tmp_key2;
                next->value = tmp_value;
                next->value2 = tmp_value2;
            } else if (cur->key == next->key && cur->key2 > next->key2) {
                tmp_key = cur->key;
                tmp_key2 = cur->key2;
                tmp_value = cur->value;
                tmp_value2 = cur->value2;
                cur->key = next->key;
                cur->key2 = next->key2;
                cur->value = next->value;
                cur->value2 = next->value2;
                next->key = tmp_key;
                next->key2 = tmp_key2;
                next->value = tmp_value;
                next->value2 = tmp_value2;
            }
        }
    }
}

// Bubble sort of the n SORT_BUFFER entries (struct SortEntry), descending by key then key2.

void sort_buffer_descending(u8 n) {
    u16 tmp_key, tmp_key2, tmp_value, tmp_value2;
    u32 j;
    struct SortEntry *cur, *next;

    if (n <= 1)
        return;
    for (n--; n != 0; n--) {
        for (j = 0; j < n; j++) {
            cur = &SORT_BUFFER[j];
            next = &SORT_BUFFER[j + 1];
            if (cur->key < next->key) {
                tmp_key = cur->key;
                tmp_key2 = cur->key2;
                tmp_value = cur->value;
                tmp_value2 = cur->value2;
                cur->key = next->key;
                cur->key2 = next->key2;
                cur->value = next->value;
                cur->value2 = next->value2;
                next->key = tmp_key;
                next->key2 = tmp_key2;
                next->value = tmp_value;
                next->value2 = tmp_value2;
            } else if (cur->key == next->key && cur->key2 < next->key2) {
                tmp_key = cur->key;
                tmp_key2 = cur->key2;
                tmp_value = cur->value;
                tmp_value2 = cur->value2;
                cur->key = next->key;
                cur->key2 = next->key2;
                cur->value = next->value;
                cur->value2 = next->value2;
                next->key = tmp_key;
                next->key2 = tmp_key2;
                next->value = tmp_value;
                next->value2 = tmp_value2;
            }
        }
    }
}
