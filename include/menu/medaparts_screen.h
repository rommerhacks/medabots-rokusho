#ifndef GUARD_MENU_MEDAPARTS_SCREEN_H
#define GUARD_MENU_MEDAPARTS_SCREEN_H

// Medaparts screen (game state 5): parts list, part detail, help pages

u32 sub_0801013C(void); // runs sprite 4's sub-state handler, 1 when done
s32 sub_0800F6CC(void);
void medapart_detail_draw_skill(
    void); // skill type name (gUnk_083B6EC8[unkF0]) or, for ids >= 100 in unkEF, gUnk_083BE97C[unkEF - 100] (leg type)
void count_compatible_medaparts(
    void); // unk41 = owned parts of kind unk3E; from a Medabot (unk3C 1) only spare ones of its gender

#endif // GUARD_MENU_MEDAPARTS_SCREEN_H
