#ifndef GUARD_SAVE_SAVE_SCREEN_H
#define GUARD_SAVE_SAVE_SCREEN_H

// Mode-2 state 5: save screen sub-states, init_linking_mode

void save_screen_animate_sprite(u16 frame_idx);
void save_screen_write_save(
    void); // save screen state 7: up to 4 tries of save_dispatch(0), then state 8 (ok) or 12 (failed)
void init_linking_mode(void);

#endif // GUARD_SAVE_SAVE_SCREEN_H
