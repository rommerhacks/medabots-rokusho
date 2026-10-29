#ifndef GUARD_KEYS_H
#define GUARD_KEYS_H

// Key masks (KEYINPUT bit order; gHeldKeys etc. are 1 = pressed).
#define A_BUTTON 0x0001
#define B_BUTTON 0x0002
#define SELECT_BUTTON 0x0004
#define START_BUTTON 0x0008
#define DPAD_RIGHT 0x0010
#define DPAD_LEFT 0x0020
#define DPAD_UP 0x0040
#define DPAD_DOWN 0x0080
#define R_BUTTON 0x0100
#define L_BUTTON 0x0200
#define KEYS_MASK 0x03FF

// Held A + B + SELECT, then START pressed: soft reset (main.c).
#define SOFT_RESET_KEYS (A_BUTTON | B_BUTTON | SELECT_BUTTON | START_BUTTON)

// R and L as bits of the high byte (KEYS_HI).
#define R_BUTTON_HI (R_BUTTON >> 8)
#define L_BUTTON_HI (L_BUTTON >> 8)

// Bit view of a key word (KEYINPUT order). Some code reads keys through it: `lsls #31; lsrs #31`.
struct KeyBits {
    u32 a : 1;
    u32 b : 1;
    u32 select : 1;
    u32 start : 1;
    u32 right : 1;
    u32 left : 1;
    u32 up : 1;
    u32 down : 1;
    u32 r : 1;
    u32 l : 1;
};

#define KEY_BITS(keys) (*(struct KeyBits *)&(keys))

// Low byte of a key word (A, B, SELECT, START, D-pad). Some code reads keys with `ldrb`.
#define KEYS_LO(keys) (*(u8 *)&(keys))
// High byte (R = 1, L = 2), read with `ldrb [rN, #1]`.
struct KeyBytes {
    u8 lo;
    u8 hi;
};

#define KEYS_HI(keys) (((struct KeyBytes *)&(keys))->hi)

extern u16 gPrevKeys;
extern u16 gHeldKeys;
extern u16 gNewKeys;
extern u16 gReleasedKeys;
extern u16 gRepeatKeys;
extern u8 gKeyRepeatTimer;

void read_keys(void);

#endif // GUARD_KEYS_H
