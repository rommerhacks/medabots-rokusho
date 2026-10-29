#ifndef GUARD_MENU_MEDAPARTS_SCREEN_H
#define GUARD_MENU_MEDAPARTS_SCREEN_H

// Medaparts screen (game state 5): parts list, part detail, help pages

u32 medapart_trade_choice_close_step(void); // runs sprite 4's sub-state handler, 1 when done
s32 medapart_detail_skill_help_index(void);
void medapart_detail_draw_skill(void); // skill type name (gSkillTypeNames[partSkillType]) or, for ids >= 100 in
                                       // partSkill, gLegTypeNames[partSkill - 100] (leg type)
void count_compatible_medaparts(
    void); // freeMedalCount = owned parts of kind partSlot; from a Medabot (openedFrom 1) only spare ones of its gender

#endif // GUARD_MENU_MEDAPARTS_SCREEN_H
