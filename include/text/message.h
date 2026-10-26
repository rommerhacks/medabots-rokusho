#ifndef GUARD_TEXT_MESSAGE_H
#define GUARD_TEXT_MESSAGE_H

// Message window: open/close, text printing, glyph rendering, commands

void text_window_init(u8 a, u8 b, u32 c);
void sub_0803FB0C(void);
u32 run_message(const void *msg);
void message_print_step(void); // run_message state 5, every frame: text control bytes 0xF7-0xFF, else one glyph
void text_render_glyph_step(void);
void sub_080402B4(void); // guess: draws a name / number buffer word (0xF9 command)
void reset_text_tile_state(void);
u8 update_text_compose_and_input(void);

#endif // GUARD_TEXT_MESSAGE_H
