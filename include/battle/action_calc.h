#ifndef GUARD_BATTLE_ACTION_CALC_H
#define GUARD_BATTLE_ACTION_CALC_H

// Action calculations: speed, damage modifiers, AI action type and target mode.

void select_ai_action_type(void);
void determine_battle_target_mode(void);
void sub_08038BC0(void);
void sub_08038D30(void);
void battle_begin_action_phase(void);
u32 battle_check_damage_threshold(s16 v);
void sub_08039188(void);
void sub_080391C4(void);
void sub_080392D8(void);

#endif // GUARD_BATTLE_ACTION_CALC_H
