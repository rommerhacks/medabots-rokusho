#ifndef GUARD_BATTLE_MEDAFORCE_SELECT_H
#define GUARD_BATTLE_MEDAFORCE_SELECT_H

// Tilemap window save/restore and the Medaforce select (names, skill, cost bar)

void mf_gauge_full_blink_panel(void);
void mf_gauge_draw_panel(void);
void draw_partial_bg1_column(void);
void scroll_tilemap_window(void);
void command_ring_grow_icons(void);
void mf_menu_blink_selected_icon(void);
void mf_menu_input(void);
void mf_menu_slide_out_bg1(void);
void save_restore_bg0_tilemap_region(void);
void save_restore_bg1_tilemap_region(void);
void mf_menu_load_frame(void);
void mf_menu_slide_bg0(void);
void mf_menu_slide_bg1(void);
void mf_menu_init_cursor(void);
void mf_menu_init_center_icon(void);
void mf_menu_draw_medaforce_name(void);
void mf_menu_init_top_icon(u32 highlighted);
void mf_menu_init_left_icon(u32 highlighted);
void mf_menu_init_right_icon(u32 highlighted);
void mf_menu_init_charge_icon(u32 highlighted);
void mf_menu_draw_status(u32 blink_errors);

#endif // GUARD_BATTLE_MEDAFORCE_SELECT_H
