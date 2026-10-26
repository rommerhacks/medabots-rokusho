#ifndef GUARD_TITLE_TEST_MODE_H
#define GUARD_TITLE_TEST_MODE_H

// Mode-2 state 7: hidden TEST MODE screen (music, effects, erase save)

void sub_0805F898(void);
void advance_substate_on_handler_complete(void);
void sub_0805F860(void);
void sub_0805F974(void);
void sub_0805F9AC(void);
void test_mode_dispatch(void); // gUnk_08483C6C[gGameSubState](), BG3 scrolls diagonally
void update_fade_effect(void);
void sub_0805F8B0(void);
void sub_0805F81C(void);
void silence_and_clear_vram(void);
void update_fade_transition_state_0805F778(void);
void sub_0805F8F0(void); // up to 4 tries of save_dispatch(2) (erase), then the next sub-state (ok) or 12 (failed)
void init_fade_screen_setup(void);

#endif // GUARD_TITLE_TEST_MODE_H
