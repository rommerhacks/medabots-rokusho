#ifndef GUARD_BATTLE_BATTLE_SETUP_H
#define GUARD_BATTLE_BATTLE_SETUP_H

// Robattle start: Medal skill use counts, battle music, the action-select UI

void fill_opponent_medaforce_for_battle_type(void);
void count_bot_skill_use(u32 rec); // guess: counts the chosen action's skill type in the record's unkB0
void init_battle_action_select_ui(u32 a);
void count_team_skill_uses(void);
void select_battle_music(void);

#endif // GUARD_BATTLE_BATTLE_SETUP_H
