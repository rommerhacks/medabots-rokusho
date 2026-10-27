#ifndef GUARD_BATTLE_TURN_ORDER_H
#define GUARD_BATTLE_TURN_ORDER_H

// Time-up judging, next-bot selection, part action priority

u32 find_next_active_bot(u32 rec);
void determine_battle_part_action_priority(void);
void target_marker_show(void);
void target_marker_update(void);
void target_marker_hide(void);
void robattle_judge_time_up(void);
void reset_bot_status_and_init_palette_transfers(u32 rec);
void battle_set_actor_side(u32 rec);
void select_next_bot_and_action(u32 rec);

#endif // GUARD_BATTLE_TURN_ORDER_H
