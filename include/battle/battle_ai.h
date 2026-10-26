#ifndef GUARD_BATTLE_BATTLE_AI_H
#define GUARD_BATTLE_BATTLE_AI_H

// Battle AI: per-ability target selection (gUnk_083AED20) and action usability checks (gUnk_083AEF10).

u32 sub_080330E8(u32 idx);
void battle_process_all_bot_actions(u32 rec);
u32 rng_lookup_table_value(void);
void battle_execute_action_selection(void);
void call_bot_action_handler(void);
u32 select_random_battle_target(u32 base); // random present record base + 0..2
u32 begin_battle_action_lookup(u32 rec, u32 part);
u32 sub_08032FB8(u32 rec);           // first record of the side opposite rec (3 or 0)
u32 sub_08032FC4(u32 rec);           // first record of rec's side (0 or 3)
u32 find_most_damaged_part(u32 rec); // part (+ 1) with armor left that lost the most armor, 0 = none
u32 sub_080331F8(u32 rec);
u32 battle_find_next_active_bot(
    u32 rec); // random part index of rec with armor left (from rng_lookup_table_value, stepping by rng bit 0)
u32 find_random_broken_part(u32 rec); // random part (+ 1) of rec with no armor left (unk11 == 0), 0 = none

#endif // GUARD_BATTLE_BATTLE_AI_H
