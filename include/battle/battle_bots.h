#ifndef GUARD_BATTLE_BATTLE_BOTS_H
#define GUARD_BATTLE_BATTLE_BOTS_H

// Battle Medabots: team setup from the save, opponents, per-turn action and part selection (AI)

void battle_bots_load_parts(u32 a, u32 n);
void clear_battle_bot_array(void);
void count_active_battle_bots(void);
void battle_setup_team_bots(void);
void battle_process_bot_actions_for_side(u32 side);
void init_opponent_bots(void);
void battle_process_all_bots_actions(void);
void process_bot_battle_turn(u32 rec);
void battle_bot_select_medaforce(u32 rec, u32 part);
void battle_bot_select_part(u32 rec, u32 part);
void battle_bot_advance_rotation(u32 rec);
void copy_team_slots_to_battle_bots(void);
void init_enemy_bot_medal(u8 i);
void init_opponent_bot_slots(void);
void select_bot_battle_action(u32 rec);
u32 part_blocked_by_effect(u32 rec,
                           u32 part); // 1 if unkC9 == 0x2B and unkCA == part (guess: part sealed by a status effect)
u32 check_medaforce_availability(
    u32 rec, u32 slot, u32 random); // 0 = Medaforce slot chosen (battle_bot_select_medaforce), 1 = not available
void battle_ai_roll_part_order(void);
u32 bot_side_index(u32 rec, u32 other); // side of rec (0 team, 1 opponents), or the other side when other is 1

#endif // GUARD_BATTLE_BATTLE_BOTS_H
