#ifndef GUARD_MENU_MEDALS_SCREEN_H
#define GUARD_MENU_MEDALS_SCREEN_H

// Game state 4: the Medals screen (list and Medal pages).

void load_medal_sprite(void);
void render_medal_level_display(void);
u32 medal_medaforce_get_selected(void);
void medals_help_init_cursor(void);     // help cursor sprite 6 (layout gHelpCursorLayouts[unk43], entry unk44)
void medal_rotation_draw_actions(void); // the 8 Rotation action slots (unk18), highlighted up to Medal unk9
void render_medal_skill_stats(void);
void medal_skill_load_shine_frame(void); // guess: shine frame unk3F of a 5-tile strip (gUnk_084C3B14)
void draw_medal_skill_bars(void);
void medal_rotation_store_to_battle_bot(
    void); // in battle (unk3C == 2): copies the Rotation (unk9, unk18) back to the acting Medabot
void medal_skill_debug_init_cursor(void);
u32 medal_trade_choice_close_step(void);

#endif // GUARD_MENU_MEDALS_SCREEN_H
