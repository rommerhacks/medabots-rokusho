#ifndef GUARD_TITLE_TITLE_SCREEN_H
#define GUARD_TITLE_TITLE_SCREEN_H

// Title screen (mode 3, state 2)

void title_screen_build_wave_tables(void);
void title_screen_update_sprite_effects(void);
bool32 title_effect_blink(u8 i);
bool32 title_effect_glint(u8 i);
void title_screen_hblank(void);
void set_bot_y_positions_by_count(void);

#endif // GUARD_TITLE_TITLE_SCREEN_H
