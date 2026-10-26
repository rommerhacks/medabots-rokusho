#ifndef GUARD_SHOP_SHOP_MENU_H
#define GUARD_SHOP_SHOP_MENU_H

// Mode-2 state 11: Medaparts shop menu (Buy / Sell / Exit)

void copy_text_with_lookup(); // (u8 *dst, u8 *src, u32 unused, u32 i): copies src[i..] up to 0xFF plus 2 bytes, dst[2]
void sub_080612D8(void);
void sub_0806142C(void);
void battle_menu_highlight_icons(
    u32 sel, u32 frame); // BG2 tiles of 4 icons: palette 6 for icon sel when frame & 8, else palette 5
void sub_08061180(void);
void sub_080616F8(void);
void sub_08060C44(void);
void sub_08060C60(void);
void shop_menu_dispatch(void); // gUnk_08483E10[gGameSubState](), BG3 scrolls diagonally
void sub_08061300(void);
void sub_08061678(void);
void sub_0806174C(void);
void sub_08060FD4(void);
void sub_08061374(void);

#endif // GUARD_SHOP_SHOP_MENU_H
