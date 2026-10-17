#ifndef GUARD_KEYS_H
#define GUARD_KEYS_H

// Bit view of a key word (KEYINPUT order). Some code reads keys through it: `lsls #31; lsrs #31`.
struct KeyBits
{
    u32 a:1;
    u32 b:1;
    u32 select:1;
    u32 start:1;
    u32 right:1;
    u32 left:1;
    u32 up:1;
    u32 down:1;
    u32 r:1;
    u32 l:1;
};

#define KEY_BITS(keys) (*(struct KeyBits *)&(keys))

// Low byte of a key word (A, B, SELECT, START, D-pad). Some code reads keys with `ldrb`.
#define KEYS_LO(keys) (*(u8 *)&(keys))
// High byte (R = 1, L = 2), read with `ldrb [rN, #1]`.
struct KeyBytes
{
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
