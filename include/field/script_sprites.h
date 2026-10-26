#ifndef GUARD_FIELD_SCRIPT_SPRITES_H
#define GUARD_FIELD_SCRIPT_SPRITES_H

// Map script sprites: spawning, moving and animating the sprites a map script controls, saved across the field menu

void spawn_script_sprite(u8 a, u8 b, u8 c, u8 d);
void sub_08050508(u8 id);
void set_battle_sprite_animation(u8 id, u8 state);
void setup_battle_sprite_terrain(u8 slot, u8 a, u8 b);
void map_script_command_done(void);
u32 find_next_available_battle_sprite_slot(void);
void sub_08050770(u32 idx, u8 val);
void sub_08050780(u8 i, u32 val);
void sub_080507A0(u32 idx, u32 val);
void sub_080507C0(u8 i, u8 val);
u32 sub_080507E0(u8 slot);
u32 update_battle_sprite_movement(u8 slot, u8 a);
u32 sub_08050868(void);
u32 sub_080508CC(void);
u32 sub_080509A0(void);
u8 sub_080502B4(u8 idx, u8 dir);
void advance_sprite_by_terrain_modifier(u8 idx);
void save_script_sprites(void);
void sub_080500D8(u8 slot, u8 a, u8 b);
u8 sub_08050264(u8 a);
void restore_script_sprites(void);
void sub_08050B50(void);
u8 calc_medapart_table_index(u8 a);

#endif // GUARD_FIELD_SCRIPT_SPRITES_H
