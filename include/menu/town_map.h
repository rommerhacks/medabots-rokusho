#ifndef GUARD_MENU_TOWN_MAP_H
#define GUARD_MENU_TOWN_MAP_H

// Mode-2 state 10: Town Map

void town_map_enable_layers(void);
void town_map_dispatch(void); // gTownMapStates[gGameSubState]()
void town_map_close_message(void);
void town_map_show_place_name(void);
void town_map_update_cursor(void);
void town_map_animate_tiles(void); // gUnk_03006F74->unk3A counts 0-109; every 10th frame copies a 480-byte frame of
void town_map_fade_in(void);
void town_map_save_bg2_and_reset(void);
void town_map_handle_input(void);
void town_map_fade_out_exit(void);

#endif // GUARD_MENU_TOWN_MAP_H
