#ifndef GUARD_BATTLE_BOT_MOVEMENT_H
#define GUARD_BATTLE_BOT_MOVEMENT_H

// Medabot movement on the battle field between the home and front lines

void battle_bots_move_all(void);
void battle_bots_update_walk_anims(void);
void battle_bot_move(u32 rec);
void bot_update_walk_anim(u32 rec);
u32 battle_bot_move_reverse(u32 rec); // battle_bot_move with the other direction; 1 when the line is reached
void bot_move_delay_add_terrain(u32 rec);
void bot_move_delay_sub_propulsion(u32 rec);

#endif // GUARD_BATTLE_BOT_MOVEMENT_H
