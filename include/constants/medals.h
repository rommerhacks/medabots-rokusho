#ifndef GUARD_CONSTANTS_MEDALS_H
#define GUARD_CONSTANTS_MEDALS_H

// struct MedalData.flags (gMedals[30], one per Medal list slot). The low bits keep the slot's place in the Medals
// list order (medal_list_init_order sets slot i to i); the Medal's id is graphicId. Runtime check: winning the
// last Select Corps guard at Rosewood (walkthrough segment 65) turns slot 10 from 0x0A into 0x8A (Unicorn Medal).

#define MEDAL_FLAG_OWNED 0x80      // the slot holds a Medal
#define MEDAL_FLAG_IN_MEDABOT 0x40 // the Medal is set in a team Medabot (can't be traded or picked twice)
#define MEDAL_ORDER_MASK 0x1F      // the slot's place in the Medals list order

#endif // GUARD_CONSTANTS_MEDALS_H
