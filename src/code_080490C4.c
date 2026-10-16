#include "global.h"

INCLUDE_ASM("asm/nonmatching/code_080490C4", build_bg_tile_entry);
INCLUDE_ASM("asm/nonmatching/code_080490C4", fill_tilemap_rect_0804916C);
INCLUDE_ASM("asm/nonmatching/code_080490C4", copy_tilemap_region);
INCLUDE_ASM("asm/nonmatching/code_080490C4", copy_tilemap_rect_with_offset);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_080492CC);
INCLUDE_ASM("asm/nonmatching/code_080490C4", clear_entity_state);
INCLUDE_ASM("asm/nonmatching/code_080490C4", calculate_oam_affine_matrix);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_080493D4);
INCLUDE_ASM("asm/nonmatching/code_080490C4", advance_sprite_animation_frame);

void sub_080496C8(u8 *dst, u32 size)
{
    u32 i;
    for (i = 0; i < size; i++)
        *dst++ = 0;
}

INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_080496DC);
INCLUDE_ASM("asm/nonmatching/code_080490C4", count_byte_differences);
INCLUDE_ASM("asm/nonmatching/code_080490C4", field_random);
INCLUDE_ASM("asm/nonmatching/code_080490C4", memcpy_u8);
INCLUDE_ASM("asm/nonmatching/code_080490C4", setup_blend_effect);
INCLUDE_ASM("asm/nonmatching/code_080490C4", blend_effect_update);
INCLUDE_ASM("asm/nonmatching/code_080490C4", apply_blend_coefficients);

void sub_08049CB0(u16 color, u32 amount)
{
    palette_blend_to_color_080013A8(color, amount);
}

void sub_08049CC0(void)
{
    copy_obj_palette_to_buffer();
}

INCLUDE_ASM("asm/nonmatching/code_080490C4", setup_palette_fade_to_color);
INCLUDE_ASM("asm/nonmatching/code_080490C4", setup_palette_fade_to_color_with_obj);
INCLUDE_ASM("asm/nonmatching/code_080490C4", run_blend_fade_transition);

void sub_08049E74(u16 a, u32 b, u16 c)
{
    blend_obj_palettes_to_color_0803F684(a, b, c);
}

void sub_08049E88(u16 a, u32 b, u16 c)
{
    blend_obj_palettes_to_color_0803F998(a, b, c);
}

INCLUDE_ASM("asm/nonmatching/code_080490C4", quicksort_u8_array);

void sub_0804A1C4(void)
{
    gGameSubState++;
}

INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804A1D4);
INCLUDE_ASM("asm/nonmatching/code_080490C4", new_game_init);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804A5C0);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804A654);

void sub_0804A670(void)
{
    sub_0804A1C4();
}

INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804A67C);

void sub_0804A694(void)
{
    sub_08050F10();
}

void sub_0804A6A0(void)
{
    sub_0804A1C4();
}

INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804A6AC);

void sub_0804A6D8(void)
{
    init_cursor_state();
    sub_0804A1C4();
}

INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804A6E8);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804A718);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804A8B4);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804A8F8);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804A9B8);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804A9F8);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804AA28);

void sub_0804AAB8(void)
{
    if (run_blend_fade_transition(0))
        sub_0804A1C4();
}

INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804AACC);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804AAF0);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804AB14);

void sub_0804AB74(void)
{
    sub_0804A1C4();
}

INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804AB80);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804ABC8);

void sub_0804AC7C(void)
{
    sub_0804A1C4();
}

INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804AC88);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804AD1C);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804AD68);

void nullsub_0804AE2C(void)
{
}

void nullsub_0804AE30(void)
{
}

INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804AE34);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804AE7C);

void nullsub_0804AF40(void)
{
}

void nullsub_0804AF44(void)
{
}

void nullsub_0804AF48(void)
{
}

INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804AF4C);

void sub_0804AF6C(void)
{
    sub_08058214(gUnk_030057A0.unk14);
}

void sub_0804AF80(void)
{
    if (sub_0805937C())
        handle_battle_end_state_transition();
}

INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804AF94);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804AFBC);
INCLUDE_ASM("asm/nonmatching/code_080490C4", update_battle_entity_status_chars);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804B1FC);
INCLUDE_ASM("asm/nonmatching/code_080490C4", clear_vram_bg2_tiles);
INCLUDE_ASM("asm/nonmatching/code_080490C4", load_room_graphics);
INCLUDE_ASM("asm/nonmatching/code_080490C4", update_blend_effect_from_input);

u32 sub_0804B694(void)
{
    if (battle_sequence_dispatch() == 4)
        return 1;
    return 0;
}

void map_script_run_command(void)
{
    gUnk_030057E0.unkC92 = read_map_script_byte();
    gUnk_030057E0.unkC89 = 0;
    gUnk_030057E0.unkC93 = 0;
    gMapScriptCommands[gUnk_030057E0.unkC92]();
}

u32 sub_0804B6EC(void)
{
    return 0;
}

void nullsub_0804B6F0(void)
{
}

void sub_0804B6F4(void)
{
    sub_0804B70C();
}

void sub_0804B700(void)
{
    sub_0804B70C();
}

INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804B70C);

// Not called directly (hidden in the tail of sub_0804B70C).
void sub_0804B72C(void)
{
    gUnk_030057E0.unkC89 = 1;
}

INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804B740);

// Not called directly (hidden in the tail of sub_0804B740).
void sub_0804B768(void)
{
    gUnk_030057E0.unkC89 = 1;
}

INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804B77C);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804B80C);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804B860);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804B8B4);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804B90C);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804B964);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804B980);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804B99C);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804BA10);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804BA50);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804BAA0);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804BAC8);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804BB54);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804BB7C);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804BBA8);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804BBD4);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804BC20);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804BC88);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804BCBC);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804BCF8);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804BD24);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804BD8C);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804BE04);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804BE78);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804BEE8);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804BF68);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804BFE0);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804C02C);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804C078);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804C0B4);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804C0E4);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804C11C);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804C154);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804C174);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804C1C4);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804C220);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804C27C);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804C2A4);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804C2CC);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804C318);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804C360);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804C398);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804C3F8);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804C42C);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804C468);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804C4AC);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804C4F0);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804C53C);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804C598);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804C5FC);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804C62C);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804C65C);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804C67C);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804C69C);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804C6BC);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804C6DC);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804C704);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804C72C);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804C790);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804C7F4);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804C81C);

void nullsub_0804C8DC(void)
{
}

INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804C8E0);

void sub_0804C900(void)
{
    sub_08047BA8(read_map_script_byte());
}

INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804C914);

void sub_0804C938(void)
{
    dispatch_jump_table_29(2, 0);
}

void sub_0804C948(void)
{
    sub_08047BC0(0x78);
}

INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804C954);

void sub_0804C978(void)
{
    dispatch_jump_table_29(4, 0);
}

INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804C988);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804C9DC);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804CA38);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804CA9C);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804CAE8);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804CB48);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804CB90);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804CC10);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804CC60);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804CCA8);

// Not called directly (hidden in the tail of sub_0804CCA8).
void nullsub_0804CD14(void)
{
}

// Not called directly (hidden in the tail of sub_0804CCA8).
void nullsub_0804CD18(void)
{
}

// Not called directly (hidden in the tail of sub_0804CCA8).
void sub_0804CD1C(void)
{
    gUnk_030057E0.unkC89 = 1;
}

// Not called directly (hidden in the tail of sub_0804CCA8).
void nullsub_0804CD30(void)
{
}

// Not called directly (hidden in the tail of sub_0804CCA8).
void nullsub_0804CD34(void)
{
}

INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804CD38);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804CD58);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804CDB8);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804CDF8);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804CE44);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804CEAC);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804CEF4);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804CF10);

void sub_0804CFC0(void)
{
    sub_0804DB34();
}

void sub_0804CFCC(void)
{
    sub_08044B58();
}

INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804CFD8);

void sub_0804D038(void)
{
    init_battle_sprites();
}

void nullsub_0804D044(void)
{
}

INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804D048);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804D094);
INCLUDE_ASM("asm/nonmatching/code_080490C4", sub_0804D0B4);
