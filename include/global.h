#ifndef GUARD_GLOBAL_H
#define GUARD_GLOBAL_H

#include "gba/types.h"

// Includes the original assembly of a function that hasn't been decompiled yet.
#define INCLUDE_ASM(DIR, NAME) asm(".include \"" DIR "/" #NAME ".s\"")

asm(".include \"asm/macros.inc\"");

#define NAKED __attribute__((naked))

#include "gba/io_reg.h"
#include "structs.h"
#include "variables.h"
#include "functions.h"
#include "keys.h"
#include "constants/game_states.h"
#include "constants/skills.h"
#include "constants/text.h"
#include "constants/sprites.h"

#endif // GUARD_GLOBAL_H
