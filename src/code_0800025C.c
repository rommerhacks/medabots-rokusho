#include "global.h"

INCLUDE_ASM("asm/nonmatching/code_0800025C", main);
INCLUDE_ASM("asm/nonmatching/code_0800025C", irq_init);
INCLUDE_ASM("asm/nonmatching/code_0800025C", hw_reset_init);
INCLUDE_ASM("asm/nonmatching/code_0800025C", clear_oam);
INCLUDE_ASM("asm/nonmatching/code_0800025C", sound_init);
INCLUDE_ASM("asm/nonmatching/code_0800025C", vblank_irq);
INCLUDE_ASM("asm/nonmatching/code_0800025C", vblank_body);
INCLUDE_ASM("asm/nonmatching/code_0800025C", hblank_irq);

void nullsub_08000840(void)
{
}

INCLUDE_ASM("asm/nonmatching/code_0800025C", read_keys);
INCLUDE_ASM("asm/nonmatching/code_0800025C", soft_reset);
INCLUDE_ASM("asm/nonmatching/code_0800025C", check_soft_reset);

void dma1_irq_sound(void)
{
    sound_update_channel_at_690();
}

void dma2_irq_sound(void)
{
    sound_update_channel_at_6d8();
}

void nullsub_080009B4(void)
{
}

void nullsub_080009B8(void)
{
}

INCLUDE_ASM("asm/nonmatching/code_0800025C", lz_decompress_dispatch);
INCLUDE_ASM("asm/nonmatching/code_0800025C", lz_decompress_custom_08000A0C);
INCLUDE_ASM("asm/nonmatching/code_0800025C", lz_decompress_custom_08000B14);
INCLUDE_ASM("asm/nonmatching/code_0800025C", set_tilemap_and_decompress_bg);
INCLUDE_ASM("asm/nonmatching/code_0800025C", decompress_to_ewram_buffer);
INCLUDE_ASM("asm/nonmatching/code_0800025C", decompress_to_bg_scroll_buffer);
INCLUDE_ASM("asm/nonmatching/code_0800025C", write_tilemap_to_vram_08000E94);
INCLUDE_ASM("asm/nonmatching/code_0800025C", load_tilemap_rows_to_vram);
INCLUDE_ASM("asm/nonmatching/code_0800025C", sub_08000F20);
INCLUDE_ASM("asm/nonmatching/code_0800025C", copy_tilemap_with_offset_08000F78);
INCLUDE_ASM("asm/nonmatching/code_0800025C", set_bg2_affine_transform);
INCLUDE_ASM("asm/nonmatching/code_0800025C", compute_bg_affine_scanline_params);
INCLUDE_ASM("asm/nonmatching/code_0800025C", hblank_dma0_bg2affine);
INCLUDE_ASM("asm/nonmatching/code_0800025C", rng_next_080012F0);
INCLUDE_ASM("asm/nonmatching/code_0800025C", copy_obj_palette_to_buffer);
INCLUDE_ASM("asm/nonmatching/code_0800025C", palette_blend_to_color_080013A8);
INCLUDE_ASM("asm/nonmatching/code_0800025C", dma_obj_palette_to_hardware);
INCLUDE_ASM("asm/nonmatching/code_0800025C", palette_blend_16_colors);
INCLUDE_ASM("asm/nonmatching/code_0800025C", check_flag_and_fast_copy);
INCLUDE_ASM("asm/nonmatching/code_0800025C", set_oam_affine_params);
INCLUDE_ASM("asm/nonmatching/code_0800025C", compute_scaled_value);
INCLUDE_ASM("asm/nonmatching/code_0800025C", rotate_vector_2d);
INCLUDE_ASM("asm/nonmatching/code_0800025C", shell_sort_by_second_byte);
INCLUDE_ASM("asm/nonmatching/code_0800025C", serial_link_init);
INCLUDE_ASM("asm/nonmatching/code_0800025C", sub_08002190);
INCLUDE_ASM("asm/nonmatching/code_0800025C", serial_multiplayer_init);
INCLUDE_ASM("asm/nonmatching/code_0800025C", serial_link_init_and_status);
INCLUDE_ASM("asm/nonmatching/code_0800025C", serial_prepare_send_packet);
INCLUDE_ASM("asm/nonmatching/code_0800025C", serial_link_receive_packets);
INCLUDE_ASM("asm/nonmatching/code_0800025C", sub_080023D8);
INCLUDE_ASM("asm/nonmatching/code_0800025C", serial_multiplayer_transfer_handler);

void dispatch_game_state_handler_08002534(void)
{
    gGameStateHandlers_083AC148[gGameState]();
}

INCLUDE_ASM("asm/nonmatching/code_0800025C", dispatch_game_substate_handler_08002554);
INCLUDE_ASM("asm/nonmatching/code_0800025C", sub_080025B4);
INCLUDE_ASM("asm/nonmatching/code_0800025C", load_overworld_column_and_advance);
INCLUDE_ASM("asm/nonmatching/code_0800025C", init_save_prompt_text);
INCLUDE_ASM("asm/nonmatching/code_0800025C", advance_substate_with_sound);
INCLUDE_ASM("asm/nonmatching/code_0800025C", sub_0800275C);
INCLUDE_ASM("asm/nonmatching/code_0800025C", sub_0800277C);
INCLUDE_ASM("asm/nonmatching/code_0800025C", sub_080027BC);
INCLUDE_ASM("asm/nonmatching/code_0800025C", sub_080027DC);
INCLUDE_ASM("asm/nonmatching/code_0800025C", sub_080028AC);
INCLUDE_ASM("asm/nonmatching/code_0800025C", sub_08002A2C);
INCLUDE_ASM("asm/nonmatching/code_0800025C", sub_08002AF8);
INCLUDE_ASM("asm/nonmatching/code_0800025C", sub_08002C34);
INCLUDE_ASM("asm/nonmatching/code_0800025C", sub_08002D48);
INCLUDE_ASM("asm/nonmatching/code_0800025C", sub_08002DF4);
INCLUDE_ASM("asm/nonmatching/code_0800025C", sub_08002EC4);
INCLUDE_ASM("asm/nonmatching/code_0800025C", init_battle_display_and_palette);
INCLUDE_ASM("asm/nonmatching/code_0800025C", update_screen_fade_transition);
INCLUDE_ASM("asm/nonmatching/code_0800025C", render_shop_menu_screen);
INCLUDE_ASM("asm/nonmatching/code_0800025C", sub_08003300);
INCLUDE_ASM("asm/nonmatching/code_0800025C", dispatch_game_substate_handler_08003374);
INCLUDE_ASM("asm/nonmatching/code_0800025C", setup_bg_layers_and_decompress);
INCLUDE_ASM("asm/nonmatching/code_0800025C", sub_080034A4);
INCLUDE_ASM("asm/nonmatching/code_0800025C", sub_08003504);
INCLUDE_ASM("asm/nonmatching/code_0800025C", sub_08003620);
INCLUDE_ASM("asm/nonmatching/code_0800025C", sub_08003654);
INCLUDE_ASM("asm/nonmatching/code_0800025C", sub_080036A8);
INCLUDE_ASM("asm/nonmatching/code_0800025C", sub_080036C8);
INCLUDE_ASM("asm/nonmatching/code_0800025C", sub_080036F4);
INCLUDE_ASM("asm/nonmatching/code_0800025C", sub_08003784);
INCLUDE_ASM("asm/nonmatching/code_0800025C", sub_080038CC);
INCLUDE_ASM("asm/nonmatching/code_0800025C", sub_080038F0);
INCLUDE_ASM("asm/nonmatching/code_0800025C", sub_08003904);
INCLUDE_ASM("asm/nonmatching/code_0800025C", sub_0800393C);
INCLUDE_ASM("asm/nonmatching/code_0800025C", sub_080039BC);
INCLUDE_ASM("asm/nonmatching/code_0800025C", sub_080039E0);
INCLUDE_ASM("asm/nonmatching/code_0800025C", sub_08003A38);
INCLUDE_ASM("asm/nonmatching/code_0800025C", sub_08003D4C);
INCLUDE_ASM("asm/nonmatching/code_0800025C", sub_08003DE0);
INCLUDE_ASM("asm/nonmatching/code_0800025C", sub_08003E54);
INCLUDE_ASM("asm/nonmatching/code_0800025C", sub_08003EA0);
INCLUDE_ASM("asm/nonmatching/code_0800025C", sub_08003EE0);
INCLUDE_ASM("asm/nonmatching/code_0800025C", sub_08003F28);
INCLUDE_ASM("asm/nonmatching/code_0800025C", sub_08003F74);
INCLUDE_ASM("asm/nonmatching/code_0800025C", sub_08003FE8);
INCLUDE_ASM("asm/nonmatching/code_0800025C", sub_08004028);
INCLUDE_ASM("asm/nonmatching/code_0800025C", sub_0800406C);
