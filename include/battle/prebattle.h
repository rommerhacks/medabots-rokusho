#ifndef GUARD_BATTLE_PREBATTLE_H
#define GUARD_BATTLE_PREBATTLE_H

// Game state 6: Robattle intro (mosaic, wipe, opponent), results, part won/lost

void init_opponent_medabot_sprites(void);
void draw_opponent_leg_type_icons(void);
void sub_080121A8(void);
void calculate_battle_score_summary(void);
void accumulate_team_armor_stats(void);
void sub_080122F4(u32 a);
u32 random_pick_weighted4(u32 a, u32 b, u32 c, u32 d);
void load_area_battlefield(void);
void setup_random_encounter_enemies(void);
u32 sub_08012234(void);

#endif // GUARD_BATTLE_PREBATTLE_H
