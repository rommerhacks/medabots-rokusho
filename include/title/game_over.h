#ifndef GUARD_TITLE_GAME_OVER_H
#define GUARD_TITLE_GAME_OVER_H

// Mode-2 state 8: screen shown after a lost Robattle (Ikki falls on the logo; name is a guess)

void game_over_fade_in(void);
void game_over_update(void); // gGameOverStates[gGameSubState](), BG3 scrolls down every other frame
void game_over_wipe_out(void);
void game_over_reset(void);

#endif // GUARD_TITLE_GAME_OVER_H
