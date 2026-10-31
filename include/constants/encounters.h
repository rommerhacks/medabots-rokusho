#ifndef GUARD_CONSTANTS_ENCOUNTERS_H
#define GUARD_CONSTANTS_ENCOUNTERS_H

// Random encounters (check_random_encounter): gFieldWork.encounter_steps counts the player's steps and is reset
// on every area load and after each encounter. Steps up to ENCOUNTER_SAFE_STEPS never start a Robattle; after
// that each step has a 1 in ENCOUNTER_CHANCE chance, and step ENCOUNTER_FORCED_STEP always starts one (seen at
// runtime: walking through Medaropolis, the 32nd step in an area always leads to a Robattle).
#define ENCOUNTER_SAFE_STEPS 16
#define ENCOUNTER_FORCED_STEP 32
#define ENCOUNTER_CHANCE 32 // a power of two: the roll masks rng_next_byte() with ENCOUNTER_CHANCE - 1

#endif // GUARD_CONSTANTS_ENCOUNTERS_H
