#ifndef GUARD_FIELD_SCENE_3D_H
#define GUARD_FIELD_SCENE_3D_H

// 3-D scene sequences in the field: float helpers, projection, sequence script interpreter

u32 battle_sequence_dispatch(void);
void init_sprite_affine_matrices_and_state(u32 a, u32 x, u32 y, u32 d);
void sub_08053418(void);
void set_state_float_field(float a, float b, float dist, float d);
u32 animation_interpolation_step(struct AnimInterp *p);
void update_3d_entity_projections(void);
void sub_0805689C(struct AnimInterp *p, s32 *a);

#endif // GUARD_FIELD_SCENE_3D_H
