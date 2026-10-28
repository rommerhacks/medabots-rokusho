#ifndef GUARD_FIELD_FIELD_DEBUG_H
#define GUARD_FIELD_FIELD_DEBUG_H

// Field debug screen: pages, value editing, hex-digit sprites (field sub-states 48-52)

void field_debug_update_page(u32 mode);
u32 field_debug_page_done(void);
void field_debug_close(void);
void field_debug_init_page(); // defined as (void); field_debug_open passes an argument
void field_debug_cycle_row(s32 max);
void field_debug_draw_sprite_preview(void);
void field_debug_draw_value_blink(s8 key, s32 value, u8 width, u8 x, u8 y);
void field_debug_draw_label(const u8 *digits, s32 count, s32 x, s32 y);

#endif // GUARD_FIELD_FIELD_DEBUG_H
