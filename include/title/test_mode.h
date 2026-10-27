#ifndef GUARD_TITLE_TEST_MODE_H
#define GUARD_TITLE_TEST_MODE_H

// Mode-2 state 7: hidden TEST MODE screen (music, effects, erase save)

void test_mode_close_message(void);
void test_mode_erase_prompt(void);
void test_mode_erase_caution(void);
void test_mode_erase_done(void);
void test_mode_erase_failed(void);
void test_mode_dispatch(void); // gTestModeStates[gGameSubState](), BG3 scrolls diagonally
void test_mode_fade_in(void);
void test_mode_erase_start(void);
void test_mode_erase_choice(void);
void test_mode_reset(void);
void test_mode_fade_out_exit(void);
void test_mode_erase_save(
    void); // up to 4 tries of save_dispatch(2) (erase), then the next sub-state (ok) or 12 (failed)
void test_mode_show_screen(void);

#endif // GUARD_TITLE_TEST_MODE_H
