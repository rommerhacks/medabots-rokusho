#include "global.h"

INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805AB40);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", unpack_item_inventory_to_buffer);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", update_battle_medapart_icons);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", calc_fade_sprite_position);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", shop_build_sell_list);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", load_battle_sprite_tiles);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", render_battle_medapart_list);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805B3E4);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", get_fade_progress_fifth);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", swap_inventory_items);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805B470);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805B4B0);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805B7A0);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", update_battle_sprite_priority_flags);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", decompress_and_write_tilemap);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", tilemap_offset_tiles_and_palette);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", init_multiplayer_id);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", dispatch_game_state_handler_0805BA94);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805BB10);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805BB64);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805BBF8);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805BCC0);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805BDC8);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805BEA0);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805BF88);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805BFDC);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805C030);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805C190);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805C2C4);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805C308);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805C428);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805C6AC);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805C7A0);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805C7E8);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805C85C);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", load_rotation_grid_and_advance);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805C90C);

void sub_0805C940(void)
{
    if (game_state_execute_handler_a())
        dispatch_by_index_0476e8(10);
}

INCLUDE_ASM("asm/nonmatching/code_0805AB40", advance_substate_with_fade);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", fade_step_and_transition_to_mode3);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", dispatch_rotation_menu_substate);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", update_fade_transition_and_counters);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805CA28);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805CA94);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805CAD4);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805CC44);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805CD68);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805CDF0);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805CE4C);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", init_fade_sprite_and_start_fade);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805D378);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805D394);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805D418);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", check_ab_press_play_confirm_sound);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805D488);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805D4F0);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805D50C);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805D57C);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805D59C);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805D5E8);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805D628);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805D6F8);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805D8AC);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805D948);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805D96C);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805D9B8);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805D9E4);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805DA1C);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805DA5C);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805DAE4);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805DB20);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805DB48);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805DB64);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805DBE8);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", init_linking_mode);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", save_dispatch);

u16 eeprom_setup_timer_irq(void)
{
    return sub_0807C7A8(2, &gIntrTable[11]);
}

INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805DD60);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", load_save_data);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", serialize_save_data);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", validate_save_data);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sync_save_or_link_data);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805E170);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", calc_text_pixel_width);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805E29C);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805E2E8);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805E310);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805E5B0);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805E878);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805E8DC);
