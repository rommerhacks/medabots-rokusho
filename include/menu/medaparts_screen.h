#ifndef GUARD_MENU_MEDAPARTS_SCREEN_H
#define GUARD_MENU_MEDAPARTS_SCREEN_H

// Medaparts screen (game state 5): parts list, part detail, help pages

u32 medapart_trade_choice_close_step(void); // runs sprite 4's sub-state handler, 1 when done
s32 medapart_detail_skill_help_index(void);
void medapart_detail_draw_skill(void); // skill type name (gSkillTypeNames[unkF0]) or, for ids >= 100 in unkEF,
                                       // gLegTypeNames[unkEF - 100] (leg type)
void count_compatible_medaparts(
    void); // unk41 = owned parts of kind unk3E; from a Medabot (unk3C 1) only spare ones of its gender

#endif // GUARD_MENU_MEDAPARTS_SCREEN_H
