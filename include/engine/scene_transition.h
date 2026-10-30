#ifndef GUARD_ENGINE_SCENE_TRANSITION_H
#define GUARD_ENGINE_SCENE_TRANSITION_H

// Mode-3 dispatcher, mosaic-tile screen transitions and fade / wipe scene steps

void dispatch_game_mode_handler(void);
bool32 scene_fade_in_step(void);
void scene_fade_in_start(u8 step, u8 frames_per_level, u16 fade_color);
void scene_fade_out_start(u8 step, u8 frames_per_level, u16 fade_color);
bool32 scene_step_palette_fade_out(void);
bool32 scene_fade_out_step(void);

#endif // GUARD_ENGINE_SCENE_TRANSITION_H
