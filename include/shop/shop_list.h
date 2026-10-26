#ifndef GUARD_SHOP_SHOP_LIST_H
#define GUARD_SHOP_SHOP_LIST_H

// Mode-2 state 12: shop buy / sell list, cart and purchase

void sub_08061830(void);
void advance_substate_on_handler_complete_1c(void);
void shop_list_dispatch(void); // gUnk_08483E8C[gGameSubState](), BG3 scrolls diagonally
void sub_080625EC(void);
void sub_08061D30(void);
void sub_08062638(
    void); // fades OBJ palettes in, then init_battle_scene(unk19, id of shop list entry unk1A + gUnk_02023078)

#endif // GUARD_SHOP_SHOP_LIST_H
