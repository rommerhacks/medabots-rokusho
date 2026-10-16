#ifndef GUARD_VARIABLES_H
#define GUARD_VARIABLES_H

// RAM variables and ROM data. Addresses are in symbols.ld.

typedef void (*Func)(void);

// RAM
extern struct Unk_03000440 gUnk_03000440;
extern u32 gFrameCounter;
extern u32 gGameMode;
extern u32 gUnk_03002B70;
extern u32 gGameState;
extern u32 gGameSubState;
extern struct Unk_03002C30 gUnk_03002C30[];
extern struct Unk_03006D20 gUnk_03006D20;
extern struct Unk_03007014 *gUnk_03007014;

// ROM data
extern const u16 gUnk_083AB9D0[];
extern const Func gGameStateHandlers_083AC148[];
extern const u32 gUnk_083B6410[];
extern const u32 gUnk_083BA4D8[];
extern const u32 gUnk_08484444[];

#endif // GUARD_VARIABLES_H
