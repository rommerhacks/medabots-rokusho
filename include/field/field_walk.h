#ifndef GUARD_FIELD_FIELD_WALK_H
#define GUARD_FIELD_FIELD_WALK_H

// Field walking: the player's walk / event / warp frame handler and the fades into and out of other game modes

void init_battle_sprites(void);
void field_walk_update(void);
u32 scene_state_dispatch(u32 mode, u32 mode_param);
void scene_state_reset(void);
u32 field_effect_run_and_restore(void);

#endif // GUARD_FIELD_FIELD_WALK_H
