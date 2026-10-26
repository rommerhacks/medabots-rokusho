#ifndef GUARD_ENGINE_RINGS_3D_H
#define GUARD_ENGINE_RINGS_3D_H

// Fixed-point 4x4 matrices and the rotating 3-D sprite rings

void matrix_set_identity(void);
void ring_points_place_on_hexagon(u32 a);
void update_scene_animation_frame(void);
void matrix_rotate_xyz(s32 a, s32 b, s32 c);
void ring_points_place_on_circle(u16 phase);

#endif // GUARD_ENGINE_RINGS_3D_H
