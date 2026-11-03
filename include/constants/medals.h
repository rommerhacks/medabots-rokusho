#ifndef GUARD_CONSTANTS_MEDALS_H
#define GUARD_CONSTANTS_MEDALS_H

// struct MedalData.flags (gMedals[30], one per Medal list slot). The low bits keep the slot's place in the Medals
// list order (medal_list_init_order sets slot i to i); the Medal's id is graphicId. Runtime check: winning the
// last Select Corps guard at Rosewood (walkthrough segment 65) turns slot 10 from 0x0A into 0x8A (Unicorn Medal).

#define MEDAL_FLAG_OWNED 0x80      // the slot holds a Medal
#define MEDAL_FLAG_IN_MEDABOT 0x40 // the Medal is set in a team Medabot (can't be traded or picked twice)
#define MEDAL_ORDER_MASK 0x1F      // the slot's place in the Medals list order

// Medal ids: struct MedalData.graphicId, TeamSlot.medal, gMedalNames / gMedalRecords index. Names from gMedalNames
// (27 is "?", 29 is "!"); the order matches the fandom wiki's Medal list. Runtime check (walkthrough segment 77): the
// Medal list slots hold ids 0, 18, 6, 7, 8, 9, 15, 12, 16, 13, 10, 11, 17 in the order they were picked up (Kuwagata,
// Chameleon, Snake, ... Mouse), and the team slots hold 0, 18, 8, 30, 12, 30 (Kuwagata, Chameleon, Squid, none, Knight,
// none).
enum {
    MEDAL_KUWAGATA,
    MEDAL_KABUTO,
    MEDAL_TORTOISE,
    MEDAL_JELLYFISH,
    MEDAL_BEAR,
    MEDAL_SPIDER,
    MEDAL_SNAKE,
    MEDAL_QUEEN,
    MEDAL_SQUID,
    MEDAL_PHOENIX,
    MEDAL_UNICORN,
    MEDAL_GHOST,
    MEDAL_KNIGHT,
    MEDAL_MERMAID,
    MEDAL_PENGUIN,
    MEDAL_BAT,
    MEDAL_KAPPA,
    MEDAL_MOUSE,
    MEDAL_CHAMELEON,
    MEDAL_RABBIT,
    MEDAL_MONKEY,
    MEDAL_DEVIL,
    MEDAL_ANGEL,
    MEDAL_DRAGON,
    MEDAL_NINJA,
    MEDAL_ALIEN,
    MEDAL_CAT,
    MEDAL_QUESTION, // "?"
    MEDAL_BOTRO,
    MEDAL_EXCLAMATION, // "!"
    MEDAL_COUNT,
};

#define MEDAL_NONE MEDAL_COUNT      // TeamSlot.medal: no Medal set
#define MEDAL_SLOT_NONE MEDAL_COUNT // gMedals list slot: none (the Medabots detail screen's shownMedal)

#endif // GUARD_CONSTANTS_MEDALS_H
