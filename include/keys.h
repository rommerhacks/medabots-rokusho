#ifndef GUARD_KEYS_H
#define GUARD_KEYS_H

extern u16 gPrevKeys;
extern u16 gHeldKeys;
extern u16 gNewKeys;
extern u16 gReleasedKeys;
extern u16 gRepeatKeys;
extern u8 gKeyRepeatTimer;

void read_keys(void);

#endif // GUARD_KEYS_H
