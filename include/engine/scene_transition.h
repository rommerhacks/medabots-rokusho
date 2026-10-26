#ifndef GUARD_ENGINE_SCENE_TRANSITION_H
#define GUARD_ENGINE_SCENE_TRANSITION_H

// Mode-3 dispatcher, mosaic-tile screen transitions and fade / wipe scene steps

void dispatch_game_mode_handler(void);
bool32 scene_transition_step_080686F4(void);
void setup_screen_transition_effect_080682CC(u8 a, u8 b, u16 c);
void setup_screen_transition_effect_080684F0(u8 a, u8 b, u16 c);
bool32 scene_step_palette_fade_out(void);
bool32 execute_scene_step(void);

#endif // GUARD_ENGINE_SCENE_TRANSITION_H
