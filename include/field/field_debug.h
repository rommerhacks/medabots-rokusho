#ifndef GUARD_FIELD_FIELD_DEBUG_H
#define GUARD_FIELD_FIELD_DEBUG_H

// Debug battle-field screen: field sub-states 0x0804AF4C.. pages, value editing, hex-digit sprites

void sub_08058214(u32 a);
u32 sub_0805937C(void);
void handle_battle_end_state_transition(void);
void sub_08058110(); // defined as (void); sub_0804AF4C passes an argument
void sub_0805889C(s32 max);
void init_battle_field_sprites(void);
void load_or_clear_battle_sprites(s8 key, s32 value, u8 width, u8 x, u8 y);
void load_battle_sprite_tile(const u8 *tiles, s32 count, s32 x, s32 y);

#endif // GUARD_FIELD_FIELD_DEBUG_H
