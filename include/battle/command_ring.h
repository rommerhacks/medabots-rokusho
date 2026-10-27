#ifndef GUARD_BATTLE_COMMAND_RING_H
#define GUARD_BATTLE_COMMAND_RING_H

// Robattle command ring: icons, rotation, input

void command_ring_init_icon(u32 a);
void bot_pointer_line_animate(u32 idx);
void bot_pointer_line_init(u32 rec);
u32 bot_pointer_line_extend(u32 rec);
void command_ring_draw_name(void);
void command_ring_init_icons(void);
void command_ring_input(void);
void command_ring_pulse_selected(void);
void command_ring_flash_selected(void);
void command_ring_goto_selected(void);
void command_ring_shrink_icons(void);
void command_ring_close_scroll_right(void);
void command_ring_close_scroll_down(void);
void command_ring_init_icons_hidden(void);
void parts_menu_load_frame(void);
void parts_menu_slide_bg0(void);
void parts_menu_slide_bg1(void);

#endif // GUARD_BATTLE_COMMAND_RING_H
