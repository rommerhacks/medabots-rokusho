#ifndef GUARD_CONSTANTS_BATTLEFIELDS_H
#define GUARD_CONSTANTS_BATTLEFIELDS_H

// Robattle battlefield ids (gBattleWork.battlefield): the terrain shown as "ROBATTLE FIELD" before a battle. It picks
// the background and, with the leg type, the movement delay (gTerrainMoveDelays: one row of NUM_BATTLEFIELDS per leg
// type, SKILL_LEGS_AIR first). Each name comes from playing the game: the walkthrough read the id in that battle.

#define BATTLEFIELD_WOODS 5 // Erika's house and Nae's room (walkthrough segment 61): two-legged legs move at full speed

#define NUM_BATTLEFIELDS 11

#endif // GUARD_CONSTANTS_BATTLEFIELDS_H
