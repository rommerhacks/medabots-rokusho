#ifndef GUARD_CONSTANTS_MEDAPARTS_H
#define GUARD_CONSTANTS_MEDAPARTS_H

// Medapart ids: models 0-119 per kind (head, right arm, left arm, legs). A slot with no Medapart shows the bare
// Tinpet, id MEDAPART_BARE_TINPET + the Tinpet's gender (120 male, 121 female); the Medabot detail screen's part
// cycle wraps through it (find_next_available_medapart_slot).
#define MEDAPART_COUNT 120
#define MEDAPART_BARE_TINPET 120

// Tinpet / Medapart gender (TeamSlot.gender, part data[3]); a Medapart fits only a Tinpet of its own gender
// (runtime: a female Tinpet takes the Watergun head, walkthrough segment 72).
#define TINPET_MALE 0
#define TINPET_FEMALE 1

#endif // GUARD_CONSTANTS_MEDAPARTS_H
