#ifndef GUARD_BATTLE_BATTLE_AI_H
#define GUARD_BATTLE_BATTLE_AI_H

// Battle AI: per-ability target selection (gAiTargetPickers) and action usability checks (gAiActionChecks).

u32 ai_random_target_part(u32 idx); // part index to aim at, weighted by the bot's intact parts
void ai_pick_bot_targets(u32 rec);  // AI target for each of rec's three action parts
u32 rng_random_slot(void);          // random 0-2
void ai_pick_part_target(void);
void ai_run_after_pick(void);
u32 select_random_battle_target(u32 base);   // random present record base + 0..2
u32 ai_action_unusable(u32 rec, u32 part);   // 1 if the skill of part (1-3) can't be used on its target
u32 battle_enemy_side_first_record(u32 rec); // first record of the side opposite rec (3 or 0)
u32 battle_side_first_record(u32 rec);       // first record of rec's side (0 or 3)
u32 find_most_damaged_part(u32 rec);         // part (+ 1) with armor left that lost the most armor, 0 = none
u32 battle_bot_lacks_stability(u32 rec);     // 1 if no unbroken part has the Stability skill
u32 bot_random_intact_part(
    u32 rec); // random part index of rec with armor left (from rng_random_slot, stepping by rng bit 0)
u32 find_random_broken_part(u32 rec); // random part (+ 1) of rec with no armor left (armor == 0), 0 = none

#endif // GUARD_BATTLE_BATTLE_AI_H
