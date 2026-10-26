#ifndef GUARD_FIELD_FIELD_WALK_H
#define GUARD_FIELD_FIELD_WALK_H

// Field walking: the player's walk / event / warp frame handler and the fades into and out of other game modes

void init_battle_sprites(void);
void sub_08050F10(void);
u32 scene_state_dispatch(u32 a, u32 b);
void sub_08050C74(void);
u32 battle_scene_state_dispatch(void);

#endif // GUARD_FIELD_FIELD_WALK_H
