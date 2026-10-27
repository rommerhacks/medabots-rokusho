#ifndef GUARD_FIELD_MAP_OBJECTS_H
#define GUARD_FIELD_MAP_OBJECTS_H

// Field map objects: NPC animation, map events, tile and exit checks, camera, warps, event flag nibbles

void event_counter_increment(u16 id);
u32 event_counter_get(u16 id);
void event_flag_clear(u16 id);
void event_flag_set(u16 id);
void event_counter_set(u16 id, u8 val);
void field_set_player_sprite_visible(u8 on);
void update_bg_scroll_offsets_a(void);
void set_tile_data(u8 x, u8 y, u8 val);
void set_sprite_animation_state(u8 idx, u8 state);
u8 field_pixel_x_to_tile(u16 x);
u8 field_pixel_y_to_tile(u16 y);
void set_battle_state_byte_c83(u8 dir);
u32 get_adjacent_tile_value(u8 dir);
void field_set_player_facing(u8 dir);
void set_sprite_anim_and_store(u8 idx, u8 state, struct MapObject *obj);
void load_battle_terrain_data(void);
u32 area_map_size(u8 area, u8 which);
void field_set_bg_scroll_x(u16 x);
void field_set_bg_scroll_y(u16 y);
u32 field_map_origin_x(void);
u32 field_map_origin_y(void);
void field_load_area_tiles(u8 area);
void field_center_camera_on_player(void);
void update_cursor_tile_position(void);
void field_scroll_bg_x(s16 dx);
void field_scroll_bg_y(s16 dy);
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
u32 field_tilemap_header_word(u32 unused, u8 which);
u32 event_flag_get(u16 id);
void event_flag_write(u16 id, u8 val);

#endif // GUARD_FIELD_MAP_OBJECTS_H
