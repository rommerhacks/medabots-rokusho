#ifndef GUARD_BATTLE_STATUS_SCREEN_H
#define GUARD_BATTLE_STATUS_SCREEN_H

// Robattle status screen: team sprites, Medal and part info, portraits, side change

void position_battle_team_cursors(u32 first, u32 flag);
void status_init_cursor(void);
void status_draw_bot_name(void);
void status_draw_row_icons(void);
void status_load_medal_icon(void);
void status_draw_medal_name(void);
void status_draw_part_names(void);
void status_draw_part_ability_icons(void);
void status_draw_part_armor(void);
void set_portrait_parts(u8 head, u8 right_arm, u8 left_arm, u8 legs);
void status_init_portrait(void);
void status_draw_team_sprites(void);
void status_next_other_slot(void);
void status_blink_lr_button(void);
void status_update_portrait(void);
u32 status_cursor_x(void);
void scroll_bg3_diagonal(void);
void status_select_input(void);
void status_begin_side_change(void);
u32 status_side_change_scroll_out(void);
u32 status_side_change_scroll_in(void);
void status_reset_portrait(void);

#endif // GUARD_BATTLE_STATUS_SCREEN_H
