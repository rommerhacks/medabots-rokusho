#ifndef GUARD_CONSTANTS_STORY_H
#define GUARD_CONSTANTS_STORY_H

// Story phases (gFieldWork.story_phase, set by map script opcode 0x6B): the chapter of the story. A map NPC record
// is only placed while bit story_phase of its phase_mask is set, so each chapter has its own crowd. The names come
// from reading the phase at the end of every walkthrough segment; the last two phases are not reached yet.
#define STORY_PHASE_RIVERVIEW 0       // new game: Riverview, Erika's first Robattle, the Screws
#define STORY_PHASE_FIRST_RUBBEROBO 1 // from Nae's Medal: the warehouse, Koji, the Rubberobo disguise
#define STORY_PHASE_MT_ODORO 2        // from the Town Map: Mt. Odoro, its marsh and cave
#define STORY_PHASE_MEDABOT_ISLAND 3  // from the Bat Medal letter: Medabot Island, the tournaments, the Witch's Castle
#define STORY_PHASE_MEDAROPOLIS 4     // from the night back home: Medaropolis, Rosewood, the Medalinks
#define STORY_PHASE_UNDERGROUND 5     // from Earthkrono: the dog statue, the sewer, the Rubberobo base, the colony
#define STORY_PHASE_KODINE 6          // from the tag game: the Kodine Kingdom in the past, Cafe Ole
#define STORY_PHASE_THE_DATE 7        // from the return to the present: the date, Erika kidnapped, Fiyun Fortress

#endif // GUARD_CONSTANTS_STORY_H
