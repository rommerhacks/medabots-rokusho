#ifndef GUARD_BATTLE_ACTION_CALC_H
#define GUARD_BATTLE_ACTION_CALC_H

// Action calculations: speed, damage modifiers, AI action type and target mode.

void select_ai_action_type(void);
void determine_battle_target_mode(void);
void battle_calc_attack_success(void);
void battle_check_guard_or_cover(void);
void battle_begin_action_phase(void);
u32 battle_check_damage_threshold(s16 threshold);
void battle_check_dodged(void);
void battle_check_nullified(void);
void battle_check_absorbed(void);

#endif // GUARD_BATTLE_ACTION_CALC_H
