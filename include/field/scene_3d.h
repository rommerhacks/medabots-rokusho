#ifndef GUARD_FIELD_SCENE_3D_H
#define GUARD_FIELD_SCENE_3D_H

// 3-D scene sequences in the field: float helpers, projection, sequence script interpreter

u32 field_effect_run(void);
void field_effect_start(u32 flags, u32 x, u32 y, u32 area_id);
void field_effect_reset_view(void);
void set_state_float_field(float yaw, float pitch, float dist, float scale);
u32 animation_interpolation_step(struct AnimInterp *anim);
void field_effect_project_objects(void);
void anim_interp_init(struct AnimInterp *anim, s32 *params);

#endif // GUARD_FIELD_SCENE_3D_H
