#ifndef GUARD_FIELD_MAP_OBJECTS_H
#define GUARD_FIELD_MAP_OBJECTS_H

// Field map objects: NPC animation, map events, tile and exit checks, camera, warps, event flag nibbles

void sub_08053234(u16 id);
u32 sub_08053288(u16 id);
void sub_0805311C(u16 id);
void sub_08053154(u16 id);
void sub_080531EC(u16 id, u8 val);
void sub_08052BA0(u8 on);
void update_bg_scroll_offsets_a(void);
void set_tile_data(u8 x, u8 y, u8 val);
void set_sprite_animation_state(u8 idx, u8 state);
u8 sub_080526F0(u16 x);
u8 sub_08052714(u16 y);
void set_battle_state_byte_c83(u8 dir);
u32 get_adjacent_tile_value(u8 dir);
void field_set_player_facing(u8 dir);
void set_sprite_anim_and_store(u8 idx, u8 state, struct MapObject *obj);
void load_battle_terrain_data(void);
u32 sub_08052960(u8 area, u8 which);
void sub_080529C4(u16 x);
void sub_080529E4(u16 y);
u32 sub_08052A04(void);
u32 sub_08052A18(void);
void field_load_area_tiles(u8 area);
void field_center_camera_on_player(void);
void update_cursor_tile_position(void);
void sub_08052A2C(s16 dx);
void sub_08052AF8(s16 dy);
u32 find_npc_event_match(void);
u32 find_map_event_by_coords(u32 x, u32 y);
void update_entity_sprites_on_screen(void);
bool32 check_tile_and_trigger_battle_action(u8 dir);
bool32 field_player_at_map_edge(u8 dir);
void update_npc_random_animation(void);
u32 map_cursor_move_and_check_event(void);
void field_warp_to_area(void);
void update_bg_scroll_offsets_b(void);
void init_battle_medaforce_sprite(void);
void update_npc_sprite_animations(void);
s32 check_room_exit_at_position(void);
void check_and_update_battlefield_palette(void);
u32 sub_08052990(u32 unused, u8 which);
u32 sub_08053194(u16 id);
void sub_080531D0(u16 id, u8 val);

#endif // GUARD_FIELD_MAP_OBJECTS_H
