#include "global.h"

INCLUDE_ASM("asm/nonmatching/code_08044F54", dma_load_sprite_tiles);
INCLUDE_ASM("asm/nonmatching/code_08044F54", copy_sprite_tiles_to_vram);
INCLUDE_ASM("asm/nonmatching/code_08044F54", decompress_and_load_sprite_tiles);
INCLUDE_ASM("asm/nonmatching/code_08044F54", setup_oam_sprite_entries);
INCLUDE_ASM("asm/nonmatching/code_08044F54", init_sprite_object_entry);
INCLUDE_ASM("asm/nonmatching/code_08044F54", set_oam_sprite_tile_positions);
INCLUDE_ASM("asm/nonmatching/code_08044F54", setup_sprite_from_oam_descriptor);
INCLUDE_ASM("asm/nonmatching/code_08044F54", binary_search_sorted_table);
INCLUDE_ASM("asm/nonmatching/code_08044F54", sorted_array_insert_shift);
INCLUDE_ASM("asm/nonmatching/code_08044F54", copy_oam_entries_with_priority);
INCLUDE_ASM("asm/nonmatching/code_08044F54", copy_sprite_oam_entries);
INCLUDE_ASM("asm/nonmatching/code_08044F54", batch_copy_oam_entries);

void copy_oam_affine_params(struct OamData *oam, u16 *affine)
{
    s32 i;

    for (i = 31; i >= 0; i--)
    {
        oam->affineParam = *affine;
        affine++;
        oam++;
        oam->affineParam = *affine;
        affine++;
        oam++;
        oam->affineParam = *affine;
        affine++;
        oam++;
        oam->affineParam = *affine;
        affine++;
        oam++;
    }
}

INCLUDE_ASM("asm/nonmatching/code_08044F54", sub_08045A40);
INCLUDE_ASM("asm/nonmatching/code_08044F54", copy_sprite_oam_with_vflip);
INCLUDE_ASM("asm/nonmatching/code_08044F54", render_sprite_if_visible);
INCLUDE_ASM("asm/nonmatching/code_08044F54", init_oam_sprite_entry);
INCLUDE_ASM("asm/nonmatching/code_08044F54", load_sprite_tree_recursive);
INCLUDE_ASM("asm/nonmatching/code_08044F54", load_sprite_tiles_by_table);
INCLUDE_ASM("asm/nonmatching/code_08044F54", render_sprite_node_recursive);
INCLUDE_ASM("asm/nonmatching/code_08044F54", load_sprite_animation_by_type);
INCLUDE_ASM("asm/nonmatching/code_08044F54", toggle_bg_layer_visibility);
INCLUDE_ASM("asm/nonmatching/code_08044F54", setup_scene_bg_layers_and_sprites);
INCLUDE_ASM("asm/nonmatching/code_08044F54", update_anim_object_flags);

void sub_08047414(struct Unk_08047414 *obj, u8 *buf, u32 b, u32 c)
{
    obj->unk0 = buf;
    obj->unk4 = b;
    obj->unk8 = c;
    buf[0x1094] = 0;
}

INCLUDE_ASM("asm/nonmatching/code_08044F54", interpolate_entity_positions);

void nullsub_08047570(void)
{
}

INCLUDE_ASM("asm/nonmatching/code_08044F54", sub_08047574);
INCLUDE_ASM("asm/nonmatching/code_08044F54", sub_0804763C);
INCLUDE_ASM("asm/nonmatching/code_08044F54", sub_0804765C);
INCLUDE_ASM("asm/nonmatching/code_08044F54", dispatch_by_index_0476e8);
INCLUDE_ASM("asm/nonmatching/code_08044F54", sub_08047850);
INCLUDE_ASM("asm/nonmatching/code_08044F54", sub_08047878);

void sub_08047BA8(u32 id)
{
    play_sound_effect(id);
}

void sub_08047BB4(u32 id)
{
    play_song(id);
}

void sub_08047BC0(u32 a)
{
    sound_stop_all_with_fade_guard(a);
}

u32 sub_08047BCC(u32 idx)
{
    return gUnk_083B6410[idx];
}

u32 sub_08047BDC(u32 idx)
{
    return gUnk_083BA4D8[idx];
}

u32 sub_08047BEC(u32 a, u32 b)
{
    const u32 *t = (const u32 *)gUnk_083BB9CC;
    return t[b * 4 + a];
}

INCLUDE_ASM("asm/nonmatching/code_08044F54", init_cursor_state);
INCLUDE_ASM("asm/nonmatching/code_08044F54", scene_transition_step_08047C24);
INCLUDE_ASM("asm/nonmatching/code_08044F54", format_number_to_text_buffer);
INCLUDE_ASM("asm/nonmatching/code_08044F54", copy_string_to_text_buffer);
INCLUDE_ASM("asm/nonmatching/code_08044F54", sub_08047D24);

u32 get_money(void)
{
    return gMoney;
}

void add_money(u32 n)
{
    gMoney += n;
    if (gMoney > 99999)
        gMoney = 99999;
}

void sub_money(u32 n)
{
    s32 left = gMoney - n;

    if (left < 0)
        gMoney = 0;
    else
        gMoney = left;
}

u32 sub_08047D8C(u8 id)
{
    return get_item_quantity_by_id(id);
}

u32 sub_08047D9C(u8 a, u8 b)
{
    return sub_08042114(a, b);
}

u32 sub_08047DB0(u8 id)
{
    return find_medal_slot_by_id(id);
}

INCLUDE_ASM("asm/nonmatching/code_08044F54", sub_08047DC0);
INCLUDE_ASM("asm/nonmatching/code_08044F54", sub_08047DD8);
INCLUDE_ASM("asm/nonmatching/code_08044F54", sub_08047DF0);
INCLUDE_ASM("asm/nonmatching/code_08044F54", sub_08047E08);

u32 sub_08047E20(u8 id)
{
    return load_palette_entry(id);
}

u32 sub_08047E30(void)
{
    return sub_08042218();
}

void sub_08047E3C(u8 id)
{
    add_position_entry(id);
}

void sub_08047E4C(void)
{
}

INCLUDE_ASM("asm/nonmatching/code_08044F54", lookup_position_table_value);
INCLUDE_ASM("asm/nonmatching/code_08044F54", check_position_table_match);
INCLUDE_ASM("asm/nonmatching/code_08044F54", sub_08047F50);
INCLUDE_ASM("asm/nonmatching/code_08044F54", sub_08047F70);
INCLUDE_ASM("asm/nonmatching/code_08044F54", init_bg0_for_cursor);
INCLUDE_ASM("asm/nonmatching/code_08044F54", sub_08047FEC);
INCLUDE_ASM("asm/nonmatching/code_08044F54", sub_0804803C);

u32 sub_08048088(u32 idx)
{
    return gUnk_08484444[idx];
}

INCLUDE_ASM("asm/nonmatching/code_08044F54", update_battle_field_frame);
INCLUDE_ASM("asm/nonmatching/code_08044F54", update_sprite_animation_dma);
INCLUDE_ASM("asm/nonmatching/code_08044F54", sub_080481C4);
INCLUDE_ASM("asm/nonmatching/code_08044F54", decompress_battle_tile_graphics);
INCLUDE_ASM("asm/nonmatching/code_08044F54", decompress_terrain_tiles_to_vram);
INCLUDE_ASM("asm/nonmatching/code_08044F54", sub_080482C0);
INCLUDE_ASM("asm/nonmatching/code_08044F54", sub_080483AC);
INCLUDE_ASM("asm/nonmatching/code_08044F54", dispatch_jump_table_29);
INCLUDE_ASM("asm/nonmatching/code_08044F54", resolve_tile_from_battle_state);
INCLUDE_ASM("asm/nonmatching/code_08044F54", dma_load_obj_palettes_08048664);
INCLUDE_ASM("asm/nonmatching/code_08044F54", dma_load_battle_palettes);
INCLUDE_ASM("asm/nonmatching/code_08044F54", dma_load_obj_palettes_08048730);
INCLUDE_ASM("asm/nonmatching/code_08044F54", sub_0804877C);
INCLUDE_ASM("asm/nonmatching/code_08044F54", sub_080487E4);
INCLUDE_ASM("asm/nonmatching/code_08044F54", init_battle_sprite_entry_08048818);
INCLUDE_ASM("asm/nonmatching/code_08044F54", clear_battle_sprite_entry);
INCLUDE_ASM("asm/nonmatching/code_08044F54", safe_divide_one);
INCLUDE_ASM("asm/nonmatching/code_08044F54", truncate_to_digit_count);
INCLUDE_ASM("asm/nonmatching/code_08044F54", sub_08048914);
INCLUDE_ASM("asm/nonmatching/code_08044F54", sub_08048B24);
INCLUDE_ASM("asm/nonmatching/code_08044F54", fixed_point_divide);
INCLUDE_ASM("asm/nonmatching/code_08044F54", divide_by_65536);
INCLUDE_ASM("asm/nonmatching/code_08044F54", sub_08048B6C);
INCLUDE_ASM("asm/nonmatching/code_08044F54", copy_tilemap_with_offset_08048CA4);
INCLUDE_ASM("asm/nonmatching/code_08044F54", copy_tiles_to_bg_tilemap);
