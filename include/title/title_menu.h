#ifndef GUARD_TITLE_TITLE_MENU_H
#define GUARD_TITLE_TITLE_MENU_H

// Mode-2 dispatcher and state 3 (title menu: New Game / Continue / options)

s16 sub_0805BB10(
    s16 step); // title menu blend pulse: sets BLDALPHA from gUnk_080AF6F0[step / 8], returns step + 1 (0 after 0xA0)
void sub_0805BCC0(u8 sel); // title option rows: palette 0xA (selected row, current value), 9 (current value) or 8 on
void sub_0805C820(void);   // fades REG_BLDY up to 16, then game state 9 (carved from sub_0805C7E8)

#endif // GUARD_TITLE_TITLE_MENU_H
