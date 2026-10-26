#ifndef GUARD_DEBUG_DEBUG_MENU_H
#define GUARD_DEBUG_DEBUG_MENU_H

// Game state 63: the debug menu and its entries.

void debug_menu_update(void);
void debug_menu_init(void);
void debug_menu_select_input(void);
void debug_menu_exit(void);
void debug_menu_run_entry(void);
void debug_process_update(void);
void debug_process_input(void);
void debug_medal_update(void);
void debug_medal_input(void); // rows: give Medal id, remove Medal id, give all 30
void debug_parts_update(void);
void debug_parts_input(void); // rows: give Medapart id (all 4 kinds), take one, give all 120
void debug_tinpet_update(void);
void debug_tinpet_input(void); // one row toggled 0/1, A: team_add_tinpet(value) unless team_is_full()
void debug_item_update(void);
void debug_item_input(void); // rows: give item id, take one, give all 63
void debug_face_update(void);
void debug_face_input(void); // rows: portrait 0-0xAF, expression 0-8; A draws it twice with load_bg0_tilemap
void debug_mdlpic_update(void);
void debug_mdlpic_input(void); // rows: Medal graphic 0-29, sprite variant 0-4; A shows the Medal sprite
void debug_rndtk_update(void);
void debug_rndtk_input(void); // toggles gUnk_030057E0.unkC2C
void debug_battle_update(void);
void debug_battle_input(void); // A: unkC2A = id, starts game state 6 (Robattle intro)
void debug_sound_update(void);
void debug_sound_input(void); // rows: sound effect 0-0x7F, song 0-0x35; B stops the music
void debug_motion_update(void);
void debug_motion_init(void);
void debug_motion_load(void);
void debug_motion_input(void); // START / SELECT change the Medabot model (unk39), A plays animation unk35[0]
void debug_motion_play(void);

#endif // GUARD_DEBUG_DEBUG_MENU_H
