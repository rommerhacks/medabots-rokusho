#ifndef GUARD_SAVE_SAVE_SCREEN_H
#define GUARD_SAVE_SAVE_SCREEN_H

// Mode-2 state 5: save screen sub-states, init_linking_mode

void sub_0805D57C(u16 a);
void attempt_save_and_transition(
    void); // save screen state 7: up to 4 tries of save_dispatch(0), then state 8 (ok) or 12 (failed)
void init_linking_mode(void);

#endif // GUARD_SAVE_SAVE_SCREEN_H
