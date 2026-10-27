#ifndef GUARD_TEXT_MESSAGE_H
#define GUARD_TEXT_MESSAGE_H

// Message window: open/close, text printing, glyph rendering, commands

void text_window_init(u8 a, u8 b, u32 c);
void message_next(void); // start the next message in an open window (run_message state 4: clear, then print)
u32 run_message(const void *msg);
void message_print_step(void);     // run_message state 5, every frame: text control bytes 0xF7-0xFF, else one glyph
void text_render_glyph_step(void); // draws one character of the message into the window tiles
void message_print_var_step(void); // 0xF9 n: draws one character of string variable n (a name buffer)
void message_new_line(void);       // 0xFD / line full: next line, or the page is full (unk19 = 2)
u8 message_wait_next_page(void);   // 0xFC / page full: blink the cursor, A or B clears the page (returns 1)

#endif // GUARD_TEXT_MESSAGE_H
