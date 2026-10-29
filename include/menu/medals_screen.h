#ifndef GUARD_MENU_MEDALS_SCREEN_H
#define GUARD_MENU_MEDALS_SCREEN_H

// Game state 4: the Medals screen (list and Medal pages).

void load_medal_sprite(void);
void render_medal_level_display(void);
u32 medal_medaforce_get_selected(void);
void medals_help_init_cursor(void); // help cursor sprite 6 (layout gHelpCursorLayouts[helpFromPage], entry helpPage)
void medal_rotation_draw_actions(
    void); // the 8 Rotation action slots (MedalData.rotation), highlighted up to rotationLen
void render_medal_skill_stats(void);
void medal_skill_load_shine_frame(void); // guess: shine frame listTab of a 5-tile strip (gMedalSkillShineTiles)
void draw_medal_skill_bars(void);
void medal_rotation_store_to_battle_bot(
    void); // in battle (openedFrom == 2): copies the Rotation (rotationLen, rotation) back to the acting Medabot
void medal_skill_debug_init_cursor(void);
u32 medal_trade_choice_close_step(void);

#endif // GUARD_MENU_MEDALS_SCREEN_H
