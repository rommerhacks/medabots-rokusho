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

u32 sub_08045A40(s32 y, s32 x)
{
    u32 ret = 0;

    if (y > -0x40 && x > -0x20 && y <= 0x9F && x <= 0xEF)
        ret = 1;
    return ret;
}

INCLUDE_ASM("asm/nonmatching/code_08044F54", copy_sprite_oam_with_vflip);
INCLUDE_ASM("asm/nonmatching/code_08044F54", render_sprite_if_visible);
INCLUDE_ASM("asm/nonmatching/code_08044F54", init_oam_sprite_entry);
INCLUDE_ASM("asm/nonmatching/code_08044F54", load_sprite_tree_recursive);
INCLUDE_ASM("asm/nonmatching/code_08044F54", load_sprite_tiles_by_table);
INCLUDE_ASM("asm/nonmatching/code_08044F54", render_sprite_node_recursive);
INCLUDE_ASM("asm/nonmatching/code_08044F54", load_sprite_animation_by_type);

void toggle_bg_layer_visibility(s32 a, s32 b, s32 c, s32 d)
{
    if (a >= 0)
        gUnk_030052D0.unkD = -gUnk_030052D0.unkD - 2;
    if (b >= 0)
        gUnk_03005290.unkD = -gUnk_03005290.unkD - 2;
    if (c >= 0)
        gUnk_030052B0.unkD = -gUnk_030052B0.unkD - 2;
    if (d >= 0)
        gUnk_030052F0.unkD = -gUnk_030052F0.unkD - 2;
}

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

void sub_08047850(s32 mode)
{
    if (mode > 3)
        return;
    if (mode < 0)
        return;
    gGameMode = 1;
    gGameState = 1;
    gGameSubState = 5;
}

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
    return team_is_full();
}

void sub_08047E3C(u8 id)
{
    team_add_tinpet(id);
}

void sub_08047E4C(void)
{
}

INCLUDE_ASM("asm/nonmatching/code_08044F54", lookup_position_table_value);
INCLUDE_ASM("asm/nonmatching/code_08044F54", check_position_table_match);

s32 sub_08047F50(void)
{
    s32 n = 0;
    struct Unk_030017A0 *p = gUnk_030017A0;
    s32 i;

    for (i = 8; i >= 0; i--)
    {
        if (p->unk0 == 3)
            n++;
        p++;
    }
    return n;
}

u32 sub_08047F70(u8 id)
{
    u32 found = 0;
    s32 i;
    struct Unk_030017A0 *p;

    for (i = 0, p = gUnk_030017A0; i <= 8; i++)
    {
        if (p->unk0 == 3 && p->unk3 == id && p->unk4 == id && p->unk5 == id && p->unk6 == id)
            found = 1;
        if (found)
            break;
        p++;
    }
    return found;
}

INCLUDE_ASM("asm/nonmatching/code_08044F54", init_bg0_for_cursor);
INCLUDE_ASM("asm/nonmatching/code_08044F54", sub_08047FEC);

u32 sub_0804803C(u32 arg)
{
    u32 ret = 0;

    switch (arg)
    {
    case 0:
        ret = gUnk_083BEA90[0][gUnk_030057E0.unk7FE * 8 + 2];
        break;
    case 1:
        ret = gUnk_083BEA90[0][gUnk_030057E0.unk7FE * 8 + 3];
        break;
    }
    return ret;
}

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

u8 sub_080483AC(void)
{
    if (gUnk_030057E0.unkC30 == 0xFF)
        return gUnk_030057E0.unkC31;
    return gUnk_0847EB80[gUnk_030057E0.unk7FE];
}

INCLUDE_ASM("asm/nonmatching/code_08044F54", dispatch_jump_table_29);
INCLUDE_ASM("asm/nonmatching/code_08044F54", resolve_tile_from_battle_state);
INCLUDE_ASM("asm/nonmatching/code_08044F54", dma_load_obj_palettes_08048664);
INCLUDE_ASM("asm/nonmatching/code_08044F54", dma_load_battle_palettes);
INCLUDE_ASM("asm/nonmatching/code_08044F54", dma_load_obj_palettes_08048730);

void sub_0804877C(u8 idx)
{
    u8 v = gUnk_083D2ADD[gUnk_03002C30[idx].unk30];

    if (v == 2)
        gUnk_03002C30[idx].unkB = 0xFF;
    else if (v == 1)
        gUnk_03002C30[idx].unkB = 0;
    else
        gUnk_03002C30[idx].unkB = 0x40;
}

void sub_080487AC(void)
{
    vu16 *bldalpha;
    u16 v;

    REG_BLDCNT = 0x1F41;
    gUnk_03006F40.unkC = 12.0f;
    gUnk_03006F40.unk10 = 8.0f;
    bldalpha = &REG_BLDALPHA;
    v = 0x80C;
    *bldalpha = v;
}

void sub_080487E4(void)
{
    vu16 *bldalpha;
    u16 v;

    REG_BLDCNT = 0xF40;
    gUnk_03006F40.unkC = 12.0f;
    gUnk_03006F40.unk10 = 10.0f;
    bldalpha = &REG_BLDALPHA;
    v = 0xA0C;
    *bldalpha = v;
}

void init_battle_sprite_entry_08048818(u8 slot, u16 a, u32 frame, u8 c, u8 d)
{
    gUnk_03002C30[slot].unk0 = a;
    gUnk_03002C30[slot].unk32 = a;
    gUnk_03002C30[slot].unk6 = frame;
    gUnk_03002C30[slot].unkA = c;
    gUnk_03002C30[slot].unk1C = d;
}

INCLUDE_ASM("asm/nonmatching/code_08044F54", clear_battle_sprite_entry);
INCLUDE_ASM("asm/nonmatching/code_08044F54", safe_divide_one);
INCLUDE_ASM("asm/nonmatching/code_08044F54", truncate_to_digit_count);
INCLUDE_ASM("asm/nonmatching/code_08044F54", sub_08048914);
INCLUDE_ASM("asm/nonmatching/code_08044F54", sub_08048B24);

s16 fixed_point_divide(s16 a, s16 b)
{
    return (a << 8) / b;
}

s16 divide_by_65536(s16 a)
{
    s32 n = 0x10000;

    return n / a;
}

INCLUDE_ASM("asm/nonmatching/code_08044F54", sub_08048B6C);
INCLUDE_ASM("asm/nonmatching/code_08044F54", copy_tilemap_with_offset_08048CA4);
INCLUDE_ASM("asm/nonmatching/code_08044F54", copy_tiles_to_bg_tilemap);
