#ifndef GUARD_FUNCTIONS_H
#define GUARD_FUNCTIONS_H

// Prototypes for game functions (decompiled or still in asm), in ROM order.

u32 lz_decompress_dispatch(const u8 *src, void *dst);
void copy_obj_palette_to_buffer(void);
void palette_blend_to_color_080013A8(u16 color, u32 amount);
void sub_08034F08(void);
u32 get_random_battle_weight_entry(u32 idx);
void sub_08036270(void);
void sub_08038BC0(void);
void sub_08038D30(void);
void battle_begin_action_phase(void);
void sub_08039188(void);
void sub_080391C4(void);
void sub_080392D8(void);
void soft_reset_to_title(void);
u32 find_medal_slot_by_id(u8 id);
u32 load_palette_entry(u8 id);
u32 sub_08042218(void);
void add_position_entry(u8 id);
u32 get_item_quantity_by_id(u8 id);
void update_scroll_movement_a(void);
void sub_08044B58(void);
void sub_08047850(s32 a);
void sub_08047878(u32 a, u32 b);
void sub_08047BC0(u32 a);
void init_cursor_state(void);
u32 dispatch_jump_table_29(u32 a, u32 b);
void sub_0804A1C4(void);
void sub_0804B70C(void);
void sub_0804DB34(void);
void sub_0804DD80(void);
void sub_0804E44C(void);
void sub_0804E4E8(void);
void sub_0804E5A4(u8 a, u8 b);
void sub_08050244(void);
void init_battle_sprites(void);
void sub_08050F10(void);
void sub_08053798(void);
u32 sound_channel_check_and_advance(struct SoundTrack *track);
u32 sub_08072708(struct SoundTrack *track);
void sound_update_channel_at_690(void);
void sound_update_channel_at_6d8(void);
void sound_channel_finish_and_callback(struct SoundTrack *track);
void play_song(u32 id);
void play_sound_effect(u32 id);
void sound_stop_all_with_fade_guard(u32 a);

#endif // GUARD_FUNCTIONS_H
