#ifndef GUARD_VARIABLES_H
#define GUARD_VARIABLES_H

// RAM variables and ROM data. Addresses are in symbols.ld.

typedef void (*Func)(void);

// RAM
extern u32 gFrameCounter;
extern u32 gGameMode;
extern u32 gGameState;
extern u32 gGameSubState;

// ROM data
extern const Func gGameStateHandlers_083AC148[];

#endif // GUARD_VARIABLES_H
