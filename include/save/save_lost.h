#ifndef GUARD_SAVE_SAVE_LOST_H
#define GUARD_SAVE_SAVE_LOST_H

// Mode-2 state 9: "saved data has been lost" message, clears the EEPROM header

void sub_080600E0(void); // gSpriteEntries[0].unk1A counts 0-63, unk6 = 0x100 + gUnk_080AF980[(count >> 3) & 7]
void sub_08060324(void);
void save_lost_dispatch(void); // gUnk_08483CC4[gGameSubState](), BG3 scrolls up every other frame
void sub_0806035C(void);
void sub_08060154(void);
void sub_080603A4(void); // zeroes EEPROM block 0 (up to 4 tries), then game mode 3 state 2

#endif // GUARD_SAVE_SAVE_LOST_H
