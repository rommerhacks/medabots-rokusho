#ifndef GUARD_TEXT_CHOICE_MENU_H
#define GUARD_TEXT_CHOICE_MENU_H

// Choice menu (yes/no prompt) states, sprite jitter helpers and the message window runners

u32 game_state_execute_handler_a(void);
void open_choice_menu(u8 a, u8 b, u8 c);
u32 poll_choice_menu(void);
void sprite_bob_x(u8 sprite, u8 frame,
                  u16 x); // sets gSpriteEntries[sprite].x to x, x + 1 or x - 1 by frame (cursor bob)
void sprite_bob_y(u8 sprite, u8 frame, u16 y); // the same for gSpriteEntries[sprite].y
void memcpy_bytes_08041D04(const void *src, void *dst, u8 n);
void reset_bg_scroll(void); // zeroes the four BG scroll positions
u32 game_state_execute_handler_b(void);
void clear_tilemap_and_advance_state(void);
void animate_battle_sprite_shrink(void);
void choice_menu_finish(void);
void decompress_bg_tilemap_to_vram(void);
void transition_draw_tile_strip(void);
void battle_sprite_setup_cursor(void);
void handle_battle_sprite_scroll_input(void);

#endif // GUARD_TEXT_CHOICE_MENU_H
