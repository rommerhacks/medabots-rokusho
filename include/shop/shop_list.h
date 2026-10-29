#ifndef GUARD_SHOP_SHOP_LIST_H
#define GUARD_SHOP_SHOP_LIST_H

// Mode-2 state 12: shop buy / sell list, cart and purchase

void shop_list_reset_scroll(void);
void advance_substate_on_handler_complete_1c(void);
void shop_list_dispatch(void); // gShopListHandlers[gGameSubState](), BG3 scrolls diagonally
void shop_list_confirm_choice(void);
void shop_list_fade_in(void);
void shop_list_fade_out_exit(void); // fades OBJ palettes in, then init_battle_scene(part_kind, id of shop list entry
                                    // list_cursor + gListScrollTop)

#endif // GUARD_SHOP_SHOP_LIST_H
