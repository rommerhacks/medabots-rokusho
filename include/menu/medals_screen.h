#ifndef GUARD_MENU_MEDALS_SCREEN_H
#define GUARD_MENU_MEDALS_SCREEN_H

// Game state 4: the Medals screen (list and Medal pages).

void load_medal_sprite(void);
void render_medal_level_display(void);
u32 medal_medaforce_get_selected(void);
void sub_0800AA1C(void); // guess: Medals help cursor sprite (layout gUnk_083B7EBC[unk43], entry unk44)
void sub_0800AB0C(void); // guess: draws the 8 Rotation entries (greyed past Medal unk9)
void render_medal_skill_stats(void);
void sub_0800B0F8(void); // guess: copies animation frame unk3F of a 5-tile strip (gUnk_084C3B14)
void draw_medal_skill_bars(void);
void sub_0800B498(void); // guess: copies the Medal's Rotation (unk9, unk18) into gUnk_03000590[gUnk_03001800.unk80]
void setup_battle_cursor_sprite_0800B5E8(void);
u32 update_battle_sprite_and_check_done(void);

#endif // GUARD_MENU_MEDALS_SCREEN_H
