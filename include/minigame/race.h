#ifndef GUARD_MINIGAME_RACE_H
#define GUARD_MINIGAME_RACE_H

// Mode-3 state 4: the Medaroad race minigame (three teams of three Medabots run a relay; the player mashes A).

void race_dispatch_substate(void); // gRaceSubStates[gGameSubState]()
void race_wait_fade_in(void);
void race_announce_field(void);
void race_open_team_select(void);
void race_introduce_teams(void);
void race_init_track(void);
void race_start_signal(void);
void race_update(void); // race sub-state 9: the race itself, every frame (runtime-checked)
void race_init_results(void);
void race_show_results(void);
void race_exit(void);

void race_load_leader_portraits(void);
void race_load_track_screen(void);
void race_load_track_status_bar(void);
void race_draw_tile_block(u8 block, u8 x, u8 y);
void race_load_frame_bgs(void);
void race_load_character_sprites(void);
void race_refresh_runner_sprite(u8 idx, u8 anim);
void race_pick_field(void);
bool32 race_introduce_teams_step(void);
bool32 race_start_signal_step(void);
void race_update_speeds(void);
void race_advance_runners(void);
void race_update_runners(void);
void race_run_sprite_motions(void);
void race_step_sprite_anims(void);
void clear_sprite_entry(u8 sprite); // zeroes gSpriteEntries[sprite] (0x40 bytes)

#endif // GUARD_MINIGAME_RACE_H
