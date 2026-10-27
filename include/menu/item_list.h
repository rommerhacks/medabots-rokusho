#ifndef GUARD_MENU_ITEM_LIST_H
#define GUARD_MENU_ITEM_LIST_H

// Item / Medapart list drawing shared by the item menu and the shop

void load_battle_sprite_tiles(u32 id, s32 kind, s32 slot);
u32 item_is_usable(u32 id); // gItemUsable[id] == 1
void swap_inventory_items(void);
void item_menu_draw_page_numbers(void); // "page / pages" on the item screen
void item_menu_update_swap_marker(struct SpriteEntry *sprite);
void unpack_item_inventory_to_buffer(
    void); // gItemInventory -> struct ItemListEntry list at 0x02040000, count in gMenuWork->unk10
void update_battle_medapart_icons(void);
void render_battle_medapart_list(u32 mode);
void item_menu_set_cursor_pos(
    struct SpriteEntry *sprite); // list cursor sprite: unk2 = 0x54, unk4 = 0x1C + 16 * (gMenuWork->unkC % 5)
void shop_build_sell_list(void);

#endif // GUARD_MENU_ITEM_LIST_H
