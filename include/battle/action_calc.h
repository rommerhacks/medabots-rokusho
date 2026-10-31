#ifndef GUARD_BATTLE_ACTION_CALC_H
#define GUARD_BATTLE_ACTION_CALC_H

// Action calculations: speed, damage modifiers, AI action type and target mode.

void battle_check_nullified_on_actor(void);
void battle_check_absorbed_on_actor(void);
void battle_calc_attack_success(void);
void battle_check_guard_or_cover(void);
void battle_begin_action_phase(void);
u32 battle_check_damage_threshold(s16 threshold);
void battle_check_dodged(void);
void battle_check_nullified(void);
void battle_check_absorbed(void);

#endif // GUARD_BATTLE_ACTION_CALC_H
