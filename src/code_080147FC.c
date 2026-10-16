#include "global.h"

INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_080147FC);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_08014870);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_08014920);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_08014994);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_08014A44);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_08014A60);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_08014A84);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_08014ADC);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_08014B34);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_08014C30);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_08014C84);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_08014CC8);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_08014CF0);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_08014D94);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_08014DC8);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_08014E20);

void clear_battle_bot_array(void)
{
    sub_0803F624(gUnk_03000590, 0x600, 0);
}

INCLUDE_ASM("asm/nonmatching/code_080147FC", count_active_battle_bots);
INCLUDE_ASM("asm/nonmatching/code_080147FC", battle_setup_bot_entry);
INCLUDE_ASM("asm/nonmatching/code_080147FC", copy_player_medals_to_battle_bots);
INCLUDE_ASM("asm/nonmatching/code_080147FC", copy_battle_position_to_sprite);
INCLUDE_ASM("asm/nonmatching/code_080147FC", setup_bot_render_label);
INCLUDE_ASM("asm/nonmatching/code_080147FC", init_battle_entities_and_labels);
INCLUDE_ASM("asm/nonmatching/code_080147FC", init_enemy_bot_medal);
INCLUDE_ASM("asm/nonmatching/code_080147FC", init_enemy_bot_loadouts);
INCLUDE_ASM("asm/nonmatching/code_080147FC", battle_process_all_bots_actions);
INCLUDE_ASM("asm/nonmatching/code_080147FC", battle_process_bot_actions_for_side);
INCLUDE_ASM("asm/nonmatching/code_080147FC", process_bot_battle_turn);
INCLUDE_ASM("asm/nonmatching/code_080147FC", battle_dispatch_action_by_type);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_08015414);
INCLUDE_ASM("asm/nonmatching/code_080147FC", select_bot_battle_action);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_080154E0);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_08015508);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_08015528);

u32 sub_0801554C(u32 a, u32 b)
{
    if (b == 0)
    {
        if (a <= 2)
            return 0;
        return 1;
    }
    if (a <= 2)
        return 1;
    return 0;
}

INCLUDE_ASM("asm/nonmatching/code_080147FC", battle_bot_select_part);
INCLUDE_ASM("asm/nonmatching/code_080147FC", check_medaforce_availability);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_08015648);
INCLUDE_ASM("asm/nonmatching/code_080147FC", load_bot_palette_data);
INCLUDE_ASM("asm/nonmatching/code_080147FC", set_random_battle_formation);
INCLUDE_ASM("asm/nonmatching/code_080147FC", can_bot_perform_action);
INCLUDE_ASM("asm/nonmatching/code_080147FC", load_bg3_tilemap_08488764);
INCLUDE_ASM("asm/nonmatching/code_080147FC", draw_battle_bot_portraits);
INCLUDE_ASM("asm/nonmatching/code_080147FC", get_bot_part_effective_values);
INCLUDE_ASM("asm/nonmatching/code_080147FC", load_bot_part_sprite);
INCLUDE_ASM("asm/nonmatching/code_080147FC", load_all_bot_part_sprites);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_08015924);
INCLUDE_ASM("asm/nonmatching/code_080147FC", setup_battle_bot_sprites_08015960);
INCLUDE_ASM("asm/nonmatching/code_080147FC", setup_all_battle_bot_sprite_positions);
INCLUDE_ASM("asm/nonmatching/code_080147FC", setup_bot_battle_sprites_08015A00);
INCLUDE_ASM("asm/nonmatching/code_080147FC", load_battle_bg_layers);
INCLUDE_ASM("asm/nonmatching/code_080147FC", decompress_two_bg1_layers);
INCLUDE_ASM("asm/nonmatching/code_080147FC", render_bot_name_sprites);
INCLUDE_ASM("asm/nonmatching/code_080147FC", draw_battle_panel_left_a);
INCLUDE_ASM("asm/nonmatching/code_080147FC", draw_battle_panel_left_b);
INCLUDE_ASM("asm/nonmatching/code_080147FC", render_bot_health_bar);
INCLUDE_ASM("asm/nonmatching/code_080147FC", fixed_point_multiply_divide);
INCLUDE_ASM("asm/nonmatching/code_080147FC", render_bot_cash_display);
INCLUDE_ASM("asm/nonmatching/code_080147FC", battle_load_sprite_data);

void sub_08015F78(void)
{
    u32 i;
    for (i = 0; i < 6; i++)
        sub_08015F90(i);
}

INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_08015F90);

void sub_08016068(void)
{
    u32 i;
    for (i = 0; i < 6; i++)
        sub_08016080(i);
}

INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_08016080);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_08016138);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_08016154);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_08016288);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_0801630C);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_08016370);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_08016438);
INCLUDE_ASM("asm/nonmatching/code_080147FC", animate_battle_sprites);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_08016554);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_080165B0);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_080165D0);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_08016614);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_08016660);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_080166AC);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_080166F0);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_0801672C);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_0801677C);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_080167BC);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_08016804);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_0801684C);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_08016894);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_080168F4);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_080169AC);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_08016A3C);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_08016AD8);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_08016C0C);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_08016D18);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_08016DA4);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_08016DCC);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_08016E5C);
INCLUDE_ASM("asm/nonmatching/code_080147FC", save_restore_bg1_tilemap_region);
INCLUDE_ASM("asm/nonmatching/code_080147FC", save_restore_bg0_tilemap_region);
INCLUDE_ASM("asm/nonmatching/code_080147FC", draw_partial_bg1_column);
INCLUDE_ASM("asm/nonmatching/code_080147FC", scroll_tilemap_window);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_08016FB4);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_08017004);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_08017048);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_08017084);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_080170D4);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_08017104);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_08017130);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_08017178);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_080171C0);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_08017208);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_08017268);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_080173B4);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_080175FC);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_0801767C);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_08017734);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_080178CC);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_08017914);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_08017948);
INCLUDE_ASM("asm/nonmatching/code_080147FC", setup_battle_bot_sprites_08017994);
INCLUDE_ASM("asm/nonmatching/code_080147FC", position_battle_team_cursors);
INCLUDE_ASM("asm/nonmatching/code_080147FC", setup_bot_battle_sprites_08017A7C);
INCLUDE_ASM("asm/nonmatching/code_080147FC", init_battle_cursor_sprite_08017B24);
INCLUDE_ASM("asm/nonmatching/code_080147FC", render_battle_bot_label);
INCLUDE_ASM("asm/nonmatching/code_080147FC", draw_bg_window_rect);
INCLUDE_ASM("asm/nonmatching/code_080147FC", animate_bg_window_blink);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_08017D14);
INCLUDE_ASM("asm/nonmatching/code_080147FC", load_bot_sprite_tiles_to_vram);
INCLUDE_ASM("asm/nonmatching/code_080147FC", copy_battle_bot_data_to_state);
INCLUDE_ASM("asm/nonmatching/code_080147FC", battle_load_script_to_buffer);
INCLUDE_ASM("asm/nonmatching/code_080147FC", battle_setup_bot_font_tile);
INCLUDE_ASM("asm/nonmatching/code_080147FC", render_battle_bot_status_row);
INCLUDE_ASM("asm/nonmatching/code_080147FC", set_game_state_params);
INCLUDE_ASM("asm/nonmatching/code_080147FC", init_ewram_buffers_and_state);
INCLUDE_ASM("asm/nonmatching/code_080147FC", setup_scene_from_game_state);
INCLUDE_ASM("asm/nonmatching/code_080147FC", setup_scene_bg_from_game_state);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_0801827C);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_080182AC);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_080182D0);
INCLUDE_ASM("asm/nonmatching/code_080147FC", setup_battle_bot_display);
INCLUDE_ASM("asm/nonmatching/code_080147FC", handle_battle_bot_selection);
INCLUDE_ASM("asm/nonmatching/code_080147FC", display_battle_cursor_on_bot);
INCLUDE_ASM("asm/nonmatching/code_080147FC", animate_battle_field_scroll);
INCLUDE_ASM("asm/nonmatching/code_080147FC", toggle_battle_team_side);
INCLUDE_ASM("asm/nonmatching/code_080147FC", animate_battle_bots_entry);
