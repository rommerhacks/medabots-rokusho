#ifndef GUARD_FIELD_SCRIPT_HELPERS_H
#define GUARD_FIELD_SCRIPT_HELPERS_H

// Wrappers the field event scripts call: sound, money, items, Medals, team, text

void sub_08047BA8(u32 id);
void sub_08047BC0(u32 a);
void init_cursor_state(void);
u32 get_money(void);
u32 sub_08047D8C(u8 id);
u32 sub_08047D9C(u8 a, u8 b);
u32 sub_08047DB0(u8 id);
u32 lookup_position_table_value(u8 a, u8 b);
s32 sub_08047F50(void);
u32 sub_08047F70(u8 id);
u32 scene_transition_step_08047C24(u8 a, u8 b, u8 c, const void *text);
u32 sub_0804803C(u32 arg);
void init_bg0_for_cursor(u32 mode);
u32 sub_08047FEC(void);
void sub_08047D24(u32 a, u32 n);
void add_money(u32 n);
void sub_money(u32 n);
u32 sub_08048088(u32 idx);
u32 sub_08047E30(void);
void sub_08047E3C(u8 id);
void sub_08047DC0(u8 id, u8 n);
void copy_string_to_text_buffer(u32 slot, u32 str);
void format_number_to_text_buffer(u32 slot, u32 n);
u32 sub_08047BCC(u32 idx);
u32 sub_08047E20(u8 id);
void sub_08047DD8(u8 id, u8 n);
u32 sub_08047BEC(u32 a, u32 b);
void sub_08047DF0(u8 a, u8 b, u8 n);
void sub_08047E08(u8 a, u8 b, u8 n);
void sub_08047E4C(void);
u32 check_position_table_match(u8 id, u8 which);
u32 sub_08047BDC(u32 idx);
void sub_08047BB4(u32 id);

#endif // GUARD_FIELD_SCRIPT_HELPERS_H
