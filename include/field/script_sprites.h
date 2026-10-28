#ifndef GUARD_FIELD_SCRIPT_SPRITES_H
#define GUARD_FIELD_SCRIPT_SPRITES_H

// Map script sprites: spawning, moving and animating the sprites a map script controls, saved across the field menu

void spawn_script_sprite(u8 flags, u8 part, u8 x, u8 y);
void despawn_script_sprite(u8 code);
void script_object_set_direction(u8 id, u8 state);
void script_sprite_begin_walk(u8 slot, u8 code, u8 speed_id);
void map_script_command_done(void);
u32 find_free_script_sprite_slot(void);
void sprite_set_blend(u32 idx, u8 val);
void script_object_set_blend(u8 i, u32 val);
void sprite_set_priority(u32 idx, u32 val);
void script_object_set_priority(u8 i, u8 val);
u32 script_sprite_blink_step(u8 slot);
u32 script_sprite_update_walk(u8 slot, u8 mode);
u32 script_sprite_anim_step(void);
u32 script_sprite_hop_step(void);
u32 script_sprite_jump_step(void);
u8 sprite_walk_anim_id(u8 slot, u8 direction);
void script_sprite_advance_anim_by_speed(u8 slot);
void save_script_sprites(void);
void script_sprite_begin_slide(u8 slot, u8 code, u8 speed_id);
u8 sprite_code_kind(u8 code);
void restore_script_sprites(void);
void clear_input_keys(void);
u8 sprite_code_anim_index(u8 code);

#endif // GUARD_FIELD_SCRIPT_SPRITES_H
