#include "global.h"

INCLUDE_ASM("asm/nonmatching/code_08040EE4", render_text_sprites_08040EE4);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", render_text_string_to_sprites);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", divide_by_10000);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", divide_by_10000_b);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", divide_by_100000_08041370);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", divide_by_100000_b);

void reset_bg_scroll(void)
{
    gBg0Scroll.x = 0;
    gBg0Scroll.y = 0;
    gBg1Scroll.x = 0;
    gBg1Scroll.y = 0;
    gBg2Scroll.x = 0;
    gBg2Scroll.y = 0;
    gBg3Scroll.x = 0;
    gBg3Scroll.y = 0;
}

INCLUDE_ASM("asm/nonmatching/code_08040EE4", open_choice_menu);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", init_window_params);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", poll_choice_menu);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", decompress_bg_tilemap_to_vram);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", clear_tilemap_and_advance_state);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", clear_and_copy_tilemap_rows);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", transition_draw_tile_strip);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", copy_transition_tiles_to_bg2);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", battle_sprite_setup_cursor);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", advance_sprite_scroll_animation);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", handle_battle_sprite_scroll_input);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", update_sprite_hflip_by_animation_phase);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", animate_battle_sprite_shrink);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", sub_08041C14);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", sub_08041C5C);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", game_state_execute_handler_a);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", game_state_execute_handler_b);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", memcpy_bytes_08041D04);

void sub_08041D28(void)
{
    u32 i;
    for (i = 0; i < 30; i++)
        gUnk_03000BE0[i].unk0 = i;
}

INCLUDE_ASM("asm/nonmatching/code_08040EE4", find_medal_slot_by_id);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", load_palette_entry);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", medal_remove_by_id);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", export_medals_to_buffer);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", clear_ewram_buffer_02023000);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", sub_080420C4);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", sub_08042114);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", medapart_add_quantity);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", reduce_medapart_stat);

void sub_080421A0(void)
{
    u32 i;
    for (i = 0; i < 9; i++)
        gUnk_030017A0[i].unk7 = i;
}

INCLUDE_ASM("asm/nonmatching/code_08040EE4", sub_080421B4);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", sub_08042218);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", add_position_entry);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", get_item_quantity_by_id);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", sub_080422B8);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", sub_08042318);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", sub_0804242C);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", rng_next_080424B8);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", set_blend_effect_mode);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", update_blend_effect);

void fill_text_blank(u8 *buf, u8 n)
{
    u32 i;

    for (i = 0; i < n; i++)
        *buf++ = 0x43;
    *buf = 0xFE;
}

INCLUDE_ASM("asm/nonmatching/code_08040EE4", fill_tilemap_rect_08042698);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", fill_tilemap_pair_or_divide);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", divide_by_100000_08042838);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", sub_08042950);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", sub_08042A90);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", load_part_data);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", sub_08042B80);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", calc_polar_to_screen_coords);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", compute_polar_to_screen_position);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", decompress_sprite_to_vram_08042D94);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", init_battle_medabot_sprites);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", setup_battle_sprite_group);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", battle_sprite_set_palette_index);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", update_battle_sprite_orbiting_positions);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", modify_medapart_quantity);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", draw_tilemap_with_offset);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", sub_0804361C);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", find_next_available_medapart_slot);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", sub_080437E0);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", validate_medapart_stats);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", sub_0804384C);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", load_battlefield_data_to_buffer);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", check_random_encounter);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", sub_08043AE0);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", decompress_tileset_to_vram);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", decompress_sprite_to_vram_08043C08);

s32 sub_08043C94(void)
{
    return rng_next_080424B8() * 100 / 255;
}

INCLUDE_ASM("asm/nonmatching/code_08040EE4", sub_08043CA8);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", update_scroll_movement_a);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", apply_battle_blend_effect_a);

void sub_08043E48(void)
{
    update_scroll_movement_a();
}

INCLUDE_ASM("asm/nonmatching/code_08040EE4", load_battle_script_entry_b);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", update_scroll_movement_b);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", apply_battle_blend_effect_b);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", advance_battle_animation_frame);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", sub_08044094);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", sub_080440B4);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", sub_080440D4);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", sub_08044100);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", read_vram_tilemap_rect);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", write_vram_tilemap_rect);

void decompress_to_ewram_27000(const u8 *src)
{
    lz_decompress_dispatch(src, (void *)0x02027000);
}

INCLUDE_ASM("asm/nonmatching/code_08040EE4", race_enter_team_select);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", update_sprite_animation_position);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", calculate_direction_index);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", init_scene_buffers_080445F4);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", setup_scene_with_bg_and_sprites);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", init_scene_with_bg_and_palette);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", setup_sprite_animation_entry);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", advance_text_display);

void sub_08044B28(const u8 *src, void *dst)
{
    lz_decompress_dispatch(src, dst);
}

INCLUDE_ASM("asm/nonmatching/code_08040EE4", sub_08044B34);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", sub_08044B58);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", init_battle_scene);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", init_game_mode);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", sub_08044CDC);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", dma3_copy_or_decompress);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", set_oam_sprite_shape_size);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", sub_08044E64);
