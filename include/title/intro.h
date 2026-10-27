#ifndef GUARD_TITLE_INTRO_H
#define GUARD_TITLE_INTRO_H

// Opening intro (mode 3, state 1)

void intro_update_sprite_actions(void);
void intro_load_versus_art(void);
u32 intro_type_scan_text(u8 glyph_base);
u32 intro_type_part_name(u8 part);
u32 intro_draw_pointer_line(u8 part);
void intro_load_closeup_art(void);

#endif // GUARD_TITLE_INTRO_H
