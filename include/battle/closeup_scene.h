#ifndef GUARD_BATTLE_CLOSEUP_SCENE_H
#define GUARD_BATTLE_CLOSEUP_SCENE_H

// Action close-up scene: backgrounds, Medapart scenes, action and dialogue text.

void side_add_action_point(void);
void init_battle_closeup_scene(void); // places and draws both Medabots of the attack close-up (runtime-checked)
void init_battle_scene_backgrounds(void);
u32 closeup_reset_text_states(); // old-style: passes its unused r0 argument through
u32 closeup_left_pose_step(void);
u32 closeup_right_pose_step(void);
void charge_target_medaforce(void);
void setup_battle_medapart_scenes(void);
void get_active_bot_part_index_and_load_values(u32 side);

#endif // GUARD_BATTLE_CLOSEUP_SCENE_H
