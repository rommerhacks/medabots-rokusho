#ifndef GUARD_ENGINE_SPRITES_H
#define GUARD_ENGINE_SPRITES_H

// Sprite slot table: anim commands, slot allocation, text and number sprites

void clear_battle_sprite_slot(u8 a, u8 b);
void divide_by_10000(u8 *digits, u32 n); // guess: n as text "0x4C ddd 0x40 dd" (5 digits, leading zeros dropped)
void divide_by_10000_b(u8 *dst, u32 n);  // guess: like divide_by_10000 without the 0x4C prefix
void divide_by_100000_08041370(u8 *digits,
                               u32 n); // guess: n as text, up to 5 digits; >= 100000 writes a fixed overflow string
void disable_sprites(u8 first, u8 count);
u32 find_next_free_sprite_slot(u8 first, u8 count); // first unused gSpriteEntries slot in [first, first + count)
void render_text_sprites_08040DB8(u8 *str, u8 slot, u32 x, u32 y, u8 width, u8 pal, u8 align,
                                  u16 prio); // 0xFE-terminated, one sprite per character from slot; x / y / width in
void process_sprite_anim_commands(const u8 *cmds, u8 slot);
void battle_sprite_anim_init(const void *cmds, u8 slot);
void divide_by_100000_b(u8 *buf, u32 value,
                        u32 tile); // guess: value as text, digits + tile; >= 100000 writes a fixed overflow string
void render_text_sprites_08040EE4(u8 *text, u8 a, u32 x, u32 y, u8 b, u8 c, u8 d, u16 e, s32 f, s32 g);
void enable_sprites(u8 first, u8 count);
void render_text_string_to_sprites(u8 *str, u8 slot, u32 x, u32 y, u8 a4, u8 a5, u8 a6, u16 a7);

#endif // GUARD_ENGINE_SPRITES_H
