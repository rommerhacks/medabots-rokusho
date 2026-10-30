#ifndef GUARD_ENGINE_BLEND_FADE_H
#define GUARD_ENGINE_BLEND_FADE_H

// Blend fade effect state (init + per-frame step)

void init_blend_effect(void *state, u8 level, u8 delay, s8 step, u16 mode);
u32 blend_effect_step(void *state);

#endif // GUARD_ENGINE_BLEND_FADE_H
