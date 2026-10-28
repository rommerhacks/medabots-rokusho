#ifndef GUARD_FIELD_SCRIPT_HELPERS_H
#define GUARD_FIELD_SCRIPT_HELPERS_H

// Wrappers the field event scripts call: sound, money, items, Medals, team, text

void field_play_sound_effect(u32 id);
void field_stop_songs(u32 frames);
void message_steps_reset(void);
u32 get_money(void);
u32 field_item_quantity(u8 id);
u32 field_medapart_counts(u8 part_id, u8 kind);
u32 field_find_medal_slot(u8 id);
u32 team_equipped_part_legs_value(u8 id, u8 which);
s32 team_count_complete_bots(void);
u32 team_has_full_part_set(u8 id);
u32 message_step_run(u8 keep_palettes, u8 portrait_mode, u8 no_frame, const void *text);
u32 area_allows_vehicle(u32 vehicle);
void yes_no_menu_open(u32 mode);
u32 yes_no_menu_poll(void);
void format_money_to_text_buffer(u32 slot, u32 n);
void add_money(u32 n);
void subtract_money(u32 n);
u32 item_name(u32 idx);
u32 field_team_is_full(void);
void field_team_add_tinpet(u8 id);
void field_give_item(u8 id, u8 n);
void copy_string_to_text_buffer(u32 slot, u32 str);
void format_number_to_text_buffer(u32 slot, u32 n);
u32 medal_name(u32 idx);
u32 field_give_medal(u8 id);
void field_take_item(u8 id, u8 n);
u32 medapart_name(u32 kind, u32 part_id);
void field_give_medapart(u8 part_id, u8 kind, u8 n);
void field_take_medapart(u8 part_id, u8 kind, u8 n);
void message_reset_hook(void);
u32 team_has_part_equipped(u8 id, u8 which);
u32 medabot_name(u32 idx);
void field_play_song(u32 id);

#endif // GUARD_FIELD_SCRIPT_HELPERS_H
