#ifndef GUARD_MENU_TOWN_MAP_H
#define GUARD_MENU_TOWN_MAP_H

// Mode-2 state 10: Town Map

void sub_08060804(void);
void town_map_dispatch(void); // gUnk_08483DA0[gGameSubState]()
void sub_0806098C(void);
void sub_080608B4(void);
void town_map_update_cursor(void);
void update_animation_timer(void); // gUnk_03006F74->unk3A counts 0-109; every 10th frame copies a 480-byte frame of
void sub_0806086C(void);
void copy_bg2_tilemap_to_ewram(void);
void sub_080608EC(void);
void sub_080609C0(void);

#endif // GUARD_MENU_TOWN_MAP_H
