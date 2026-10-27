#ifndef GUARD_TITLE_TITLE_MENU_H
#define GUARD_TITLE_TITLE_MENU_H

// Mode-2 dispatcher and state 3 (title menu: New Game / Continue / options)

s16 title_menu_blend_step(s16 step); // title menu blend pulse: sets BLDALPHA from gTitleMenuBlendAlphas[step / 8],
                                     // returns step + 1 (0 after 0xA0)
void title_options_draw_values(
    u8 sel); // title option rows: palette 0xA (selected row, current value), 9 (current value) or 8 on
void title_menu_fade_to_save_lost(
    void); // fades REG_BLDY up to 16, then game state 9 (carved from title_menu_continue_game)

#endif // GUARD_TITLE_TITLE_MENU_H
