#ifndef GUARD_BATTLE_CLOSEUP_SCENE_H
#define GUARD_BATTLE_CLOSEUP_SCENE_H

// Action close-up scene: backgrounds, Medapart scenes, action and dialogue text.

void sub_08036270(void);
void init_battle_closeup_scene(void); // places and draws both Medabots of the attack close-up (runtime-checked)
void init_battle_scene_backgrounds(void);
u32 sub_080361A8(); // old-style: passes its unused r0 argument through
u32 battle_advance_dialogue_text(void);
u32 battle_advance_action_text(void);
void sub_0803628C(void);
void setup_battle_medapart_scenes(void);
void get_active_bot_part_index_and_load_values(u32 side);

#endif // GUARD_BATTLE_CLOSEUP_SCENE_H
