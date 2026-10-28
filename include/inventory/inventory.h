#ifndef GUARD_INVENTORY_INVENTORY_H
#define GUARD_INVENTORY_INVENTORY_H

// Medal, Medapart, item and team inventory

u32 find_medal_slot_by_id(u8 id);
u32 medal_add_by_id(u8 id);
void medal_remove_by_id(u8 id);
void medapart_add_quantity(u8 id, u8 kind, u8 n);
void reduce_medapart_stat(u8 id, u8 kind, u8 n); // takes n of Medapart (id, kind), floor 0
u32 medal_tier_for_level(u8 level, u8 a, u8 b, u8 c,
                         u8 d); // guess: Medal sprite variant (0-4) from its level and four gMedalRecords record bytes
u32 medapart_get_counts(u8 a, u8 b);
u32 team_is_full(void); // 1 when all 9 gTeamSlots slots are in use (runtime-checked)
void team_add_tinpet(
    u8 gender); // first free team slot: in use, gender, no Medal (0x1E), default parts 0x78 + gender (runtime-checked)
void item_add_quantity(
    u8 id, u8 n); // adds n of item id (gItemInventory: new entry 0x80 | id, or count capped at 99; runtime-checked)
void item_remove_quantity(u8 id, u8 n); // guess: take n of item id
u32 get_item_quantity_by_id(u8 id);
void team_lose_equipped_part(u8 slot_id, u8 kind);
void sort_buffer_descending(u8 n); // sorts gListWorkBuffer[0..n-1] by key, key2, largest first
void medal_add_from_buffer(const void *src);
void medal_list_init_order(void);
void team_init_order(void);

#endif // GUARD_INVENTORY_INVENTORY_H
