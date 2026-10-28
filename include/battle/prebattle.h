#ifndef GUARD_BATTLE_PREBATTLE_H
#define GUARD_BATTLE_PREBATTLE_H

// Game state 6: Robattle intro (mosaic, wipe, opponent), results, part won/lost

void init_opponent_medabot_sprites(void);
void draw_opponent_leg_type_icons(void);
void battlefield_load_params(void);
void calculate_battle_score_summary(void);
void accumulate_team_armor_stats(void);
void battle_pick_random_bot_part(u32 first);
u32 random_pick_weighted4(u32 common, u32 uncommon, u32 rare, u32 very_rare);
void load_area_battlefield(void);
void setup_random_encounter_enemies(void);
u32 afterbattle_pick_unowned_part(void);

#endif // GUARD_BATTLE_PREBATTLE_H
