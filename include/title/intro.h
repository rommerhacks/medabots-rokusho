#ifndef GUARD_TITLE_INTRO_H
#define GUARD_TITLE_INTRO_H

// Opening intro (mode 3, state 1)

void update_sprite_animations_080703D8(void);
void load_bg_screen_b(void);
u32 check_battle_timer_expired(u8 a);
u32 process_text_tile_and_dma_transfer(u8 a);
u32 battle_draw_tilemap_row_dma(u8 a);
void load_bg_screen_c(void);

#endif // GUARD_TITLE_INTRO_H
