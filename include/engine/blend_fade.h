#ifndef GUARD_ENGINE_BLEND_FADE_H
#define GUARD_ENGINE_BLEND_FADE_H

// Blend fade effect state (init + per-frame step)

void init_blend_effect(void *state, u8 a, u8 b, s8 c, u16 mode);
u32 blend_fade_step_08065598(void *state);

#endif // GUARD_ENGINE_BLEND_FADE_H
