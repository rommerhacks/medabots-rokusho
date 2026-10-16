#include "global.h"

INCLUDE_ASM("asm/nonmatching/code_08063090", sub_08063090);
INCLUDE_ASM("asm/nonmatching/code_08063090", sub_080630DC);
INCLUDE_ASM("asm/nonmatching/code_08063090", sub_080631DC);
INCLUDE_ASM("asm/nonmatching/code_08063090", sub_08063284);
INCLUDE_ASM("asm/nonmatching/code_08063090", sub_080632FC);
INCLUDE_ASM("asm/nonmatching/code_08063090", sub_080633E4);
INCLUDE_ASM("asm/nonmatching/code_08063090", update_fade_in_blend_effect);
INCLUDE_ASM("asm/nonmatching/code_08063090", fade_screen_and_update_sprites);
INCLUDE_ASM("asm/nonmatching/code_08063090", init_medapart_detail_view);
INCLUDE_ASM("asm/nonmatching/code_08063090", menu_confirm_selection_with_fade);
INCLUDE_ASM("asm/nonmatching/code_08063090", scene_fade_or_transition);
INCLUDE_ASM("asm/nonmatching/code_08063090", sub_080637D0);
INCLUDE_ASM("asm/nonmatching/code_08063090", sub_0806384C);
INCLUDE_ASM("asm/nonmatching/code_08063090", sub_08063D44);
INCLUDE_ASM("asm/nonmatching/code_08063090", sub_08063D90);
INCLUDE_ASM("asm/nonmatching/code_08063090", sub_08063E38);
INCLUDE_ASM("asm/nonmatching/code_08063090", sub_08063F74);
INCLUDE_ASM("asm/nonmatching/code_08063090", sub_08063FB4);
INCLUDE_ASM("asm/nonmatching/code_08063090", sub_080642E4);
INCLUDE_ASM("asm/nonmatching/code_08063090", sub_08064360);
INCLUDE_ASM("asm/nonmatching/code_08063090", sub_080643AC);
INCLUDE_ASM("asm/nonmatching/code_08063090", sub_08064428);
INCLUDE_ASM("asm/nonmatching/code_08063090", sub_08064498);
INCLUDE_ASM("asm/nonmatching/code_08063090", sub_080644C4);
INCLUDE_ASM("asm/nonmatching/code_08063090", sub_0806454C);
INCLUDE_ASM("asm/nonmatching/code_08063090", scene_scroll_with_fade);
INCLUDE_ASM("asm/nonmatching/code_08063090", update_scroll_animation_step);
INCLUDE_ASM("asm/nonmatching/code_08063090", scene_fade_and_scroll_camera);
INCLUDE_ASM("asm/nonmatching/code_08063090", scene_dispatch_and_tick);
INCLUDE_ASM("asm/nonmatching/code_08063090", sub_08064890);
INCLUDE_ASM("asm/nonmatching/code_08063090", process_fade_transition_step);
INCLUDE_ASM("asm/nonmatching/code_08063090", dispatch_fade_substate);
INCLUDE_ASM("asm/nonmatching/code_08063090", sub_08064A74);
INCLUDE_ASM("asm/nonmatching/code_08063090", sub_08064A94);
INCLUDE_ASM("asm/nonmatching/code_08063090", sub_08064AB4);
INCLUDE_ASM("asm/nonmatching/code_08063090", sub_08064AD4);
INCLUDE_ASM("asm/nonmatching/code_08063090", render_battle_medal_names);
INCLUDE_ASM("asm/nonmatching/code_08063090", sub_08064C3C);
INCLUDE_ASM("asm/nonmatching/code_08063090", sub_08064CA0);
INCLUDE_ASM("asm/nonmatching/code_08063090", sub_08064D3C);
INCLUDE_ASM("asm/nonmatching/code_08063090", sub_08064EFC);
INCLUDE_ASM("asm/nonmatching/code_08063090", sub_08065020);
INCLUDE_ASM("asm/nonmatching/code_08063090", sub_08065090);
INCLUDE_ASM("asm/nonmatching/code_08063090", sub_08065348);
INCLUDE_ASM("asm/nonmatching/code_08063090", sub_080653B4);
INCLUDE_ASM("asm/nonmatching/code_08063090", sub_08065418);
INCLUDE_ASM("asm/nonmatching/code_08063090", sub_08065484);
INCLUDE_ASM("asm/nonmatching/code_08063090", init_blend_effect);
INCLUDE_ASM("asm/nonmatching/code_08063090", blend_fade_step_08065598);
INCLUDE_ASM("asm/nonmatching/code_08063090", sub_08065618);
INCLUDE_ASM("asm/nonmatching/code_08063090", battle_cutscene_dispatch);
INCLUDE_ASM("asm/nonmatching/code_08063090", sub_08065894);

void sub_08065908(void)
{
    if (game_state_execute_handler_a())
        dispatch_by_index_0476e8(8);
}

INCLUDE_ASM("asm/nonmatching/code_08063090", fade_transition_and_input_check);
INCLUDE_ASM("asm/nonmatching/code_08063090", multiplayer_battle_sync_update);
INCLUDE_ASM("asm/nonmatching/code_08063090", handle_battle_fade_transition);

void sub_08065B68(void)
{
    if (game_state_execute_handler_a())
        dispatch_by_index_0476e8(7);
}

INCLUDE_ASM("asm/nonmatching/code_08063090", dispatch_battle_cutscene_substate);
INCLUDE_ASM("asm/nonmatching/code_08063090", clear_vram_bg);
INCLUDE_ASM("asm/nonmatching/code_08063090", fade_state_dispatch);
INCLUDE_ASM("asm/nonmatching/code_08063090", sub_080660AC);
INCLUDE_ASM("asm/nonmatching/code_08063090", handle_battle_menu_selection);
INCLUDE_ASM("asm/nonmatching/code_08063090", update_fade_transition_state_080662CC);
INCLUDE_ASM("asm/nonmatching/code_08063090", advance_fade_and_play_music);
INCLUDE_ASM("asm/nonmatching/code_08063090", init_link_save_and_connect);
INCLUDE_ASM("asm/nonmatching/code_08063090", sub_0806641C);
INCLUDE_ASM("asm/nonmatching/code_08063090", setup_dialogue_script_from_rom);
INCLUDE_ASM("asm/nonmatching/code_08063090", sub_080664F8);
INCLUDE_ASM("asm/nonmatching/code_08063090", advance_substate_with_sound_ch1);
INCLUDE_ASM("asm/nonmatching/code_08063090", sub_08066560);
INCLUDE_ASM("asm/nonmatching/code_08063090", menu_yes_no_confirmation_handler);
INCLUDE_ASM("asm/nonmatching/code_08063090", dispatch_battle_menu_and_update_counters);
INCLUDE_ASM("asm/nonmatching/code_08063090", compute_difference_div3);
INCLUDE_ASM("asm/nonmatching/code_08063090", battle_ui_setup_partial);
INCLUDE_ASM("asm/nonmatching/code_08063090", u8_difference_divide);
INCLUDE_ASM("asm/nonmatching/code_08063090", copy_block_64bytes);
INCLUDE_ASM("asm/nonmatching/code_08063090", init_fade_color_blend_params);
INCLUDE_ASM("asm/nonmatching/code_08063090", matrix_multiply_4x4_fixed);
INCLUDE_ASM("asm/nonmatching/code_08063090", sub_080669B8);
INCLUDE_ASM("asm/nonmatching/code_08063090", fade_init_divide_setup);
INCLUDE_ASM("asm/nonmatching/code_08063090", fade_init_divide_setup_b);
INCLUDE_ASM("asm/nonmatching/code_08063090", update_scene_animation_frame);
