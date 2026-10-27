#ifndef GUARD_FIELD_PLAYER_WALK_H
#define GUARD_FIELD_PLAYER_WALK_H

// Field player: NPC sprite loading, walking input and steps, direction indicator, camera scroll

void set_battle_state_cancel_flag(void);
void init_battle_field_setup(void);
void follower_clear_scroll_dir(void);
s32 sprite_walk_speed(u8 idx);
void update_battle_direction_indicator(u8 arg);
void load_battle_palette_via_dma(u32 toBuffer);
void load_map_npc_sprites(); // takes one argument (update_battle_field_frame passes gUnk_030057E0.unkCBA)
void field_player_step(u8 dir);
void field_player_walk_input(void);

#endif // GUARD_FIELD_PLAYER_WALK_H
