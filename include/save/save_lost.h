#ifndef GUARD_SAVE_SAVE_LOST_H
#define GUARD_SAVE_SAVE_LOST_H

// Mode-2 state 9: "saved data has been lost" message, clears the EEPROM header

// gSpriteEntries[0].unk1A counts 0-63, unk6 = 0x100 + gSaveLostSpriteFrames[(count >> 3) & 7]
void save_lost_animate_sprite(void);
void save_lost_wait_for_a(void);
void save_lost_dispatch(void); // gSaveLostStates[gGameSubState](), BG3 scrolls up every other frame
void save_lost_fade_out(void);
void save_lost_clear_screen(void);
void save_lost_erase_and_restart(void); // zeroes EEPROM block 0 (up to 4 tries), then game mode 3 state 2

#endif // GUARD_SAVE_SAVE_LOST_H
