#include "global.h"

INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803CDCC);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803CE18);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803CECC);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803CF7C);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803CFC8);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803D0BC);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803D15C);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803D2A8);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803D3C0);

s16 sub_0803D424(void)
{
    const s16 *seq = gUnk_083CDFE4[gUnk_03001800.unkF9];
    return seq[gUnk_03001800.unk100];
}

void load_battle_sequence_commands(void)
{
    const s16 *seq = gUnk_083CDFE4[gUnk_03001800.unkF9];
    u32 n = gUnk_083CE1F4[seq[gUnk_03001800.unk100]];
    u32 i;

    for (i = 0; i < n; i++)
        gUnk_03001800.unk102[i] = seq[gUnk_03001800.unk100 + i + 1];
}

void battle_advance_sequence_counter(void)
{
    const s16 *seq = gUnk_083CDFE4[gUnk_03001800.unkF9];
    const u8 *ops = gUnk_083CE1F4;
    s32 p = gUnk_03001800.unk100;

    gUnk_03001800.unk100 = p + 1 + ops[seq[p]];
}

INCLUDE_ASM("asm/nonmatching/code_0803CDCC", battle_sprite_rotate_angles);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803D538);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803D5A0);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803D5E0);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803D71C);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803D74C);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803D928);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803D980);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803D9A0);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803D9C8);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803D9F0);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803DA40);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803DA90);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803DAEC);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803DB1C);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803DB4C);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803DB94);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803DBB8);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803DBE0);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803DC0C);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803DC3C);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803DC58);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803DC8C);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803DCDC);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803DE70);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803DE90);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803DEB0);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803DEF0);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803DF98);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803E018);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803E03C);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803E098);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803E0C0);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803E0F0);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803E120);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803E170);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803E1A4);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803E1FC);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803E234);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803E270);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803E2AC);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803E2DC);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803E314);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803E374);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803E434);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803E48C);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803E4B4);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803E4D8);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803E4F4);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803E618);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803E634);

void sub_0803E674(void)
{
    soft_reset_to_title();
}

INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803E680);

void sub_0803E780(void)
{
    if (gUnk_03000440.unk89 == 1)
        gUnk_03005010.unk6 = 0;
}

u32 sub_0803E79C(void)
{
    gUnk_03005010.unk6 = 0xFFFE;
    if (gUnk_03005010.unk8[0][1] == 0xFFFE && gUnk_03005010.unk8[1][1] == gUnk_03005010.unk8[0][1])
        return 1;
    return 0;
}

INCLUDE_ASM("asm/nonmatching/code_0803CDCC", render_battle_text_label);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", load_battle_anim_data_38);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", draw_battle_ui_tiles_from_rom);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", load_battle_script_entry_a);

void sub_0803E894(void)
{
    if (gFrameCounter & 1)
    {
        gBg3Scroll.x++;
        gBg3Scroll.y++;
    }
}

INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803E8B8);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803E8EC);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803E934);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803E978);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803E9BC);

void sub_0803EA18(void)
{
    if (gUnk_03001800.unk1A0 == 0x60)
        gUnk_03001800.unk1A0 = 0;
    else
        gUnk_03001800.unk1A0 += 4;
}

INCLUDE_ASM("asm/nonmatching/code_0803CDCC", draw_battle_gauge_bar);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", fill_bg1_tilemap_column);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", update_battle_gauge_display);

void sub_0803EB30(void)
{
    gUnk_03001800.unk1A1 = 0x68 - gUnk_03001800.unk1A0;
    if (gUnk_03001800.unk1A1 <= 12)
        gUnk_03001800.unk1A1 = 12;
}

INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803EB5C);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803EC04);

void sub_0803EC50(void)
{
    u32 v = gUnk_03002C30[2].unk24 + gUnk_03002C30[2].unk20;
    u32 d = v >> 2;
    gUnk_03002C30[2].unk20 = v & 3;
    if (gUnk_03002C30[2].unk25 == 0)
        gUnk_03002C30[2].unk4 = (gUnk_03002C30[2].unk4 - d) & 0xFF;
    else
        gUnk_03002C30[2].unk4 = (gUnk_03002C30[2].unk4 + d) & 0xFF;
}

INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803EC98);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803ECF0);

void sub_0803ED10(void)
{
    gUnk_03002C30[2].unk24 = 0;
    gUnk_03002C30[2].unk25 = 1;
}

INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803ED28);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", draw_battle_bg1_tilemap_row);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803EE10);

u32 sub_0803EED8(void)
{
    // unk1C..unk1F read as one word (the struct has no u32 there)
    if (gUnk_03000440.unk89 == 1 && (((struct { u8 f[0x1C]; u32 x; } *)&gUnk_03005010)->x & 0xFFFF00))
    {
        gGameMode = 0;
        gGameState = 10;
        gGameSubState = 0x10;
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatching/code_0803CDCC", soft_reset_to_title);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", vram_fill_tilemap_rect);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", tilemap_fill_rect);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", write_tilemap_rect);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", write_tilemap_to_vram_0803F1C8);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", decompress_bg_tiles_to_vram_bg);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", setup_bg0_display_layer);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", decompress_indexed_asset);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", load_bg0_tilemap);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", load_overworld_map_column);

void sub_0803F624(u8 *dst, u32 size, u8 val)
{
    u32 i;
    for (i = 0; i < size; i++)
        *dst++ = val;
}

void memcpy_bytes_0803F63C(const void *src, void *dst, u32 n)
{
    u32 i;
    for (i = 0; i < n; i++)
    {
        *(u8 *)dst = *(const u8 *)src;
        src = (const u8 *)src + 1;
        dst = (u8 *)dst + 1;
    }
}

void memswap(void *a, void *b, u32 n)
{
    u32 i;
    u8 t;
    for (i = 0; i < n; i++)
    {
        t = *(u8 *)a;
        *(u8 *)a = *(u8 *)b;
        a = (u8 *)a + 1;
        *(u8 *)b = t;
        b = (u8 *)b + 1;
    }
}

INCLUDE_ASM("asm/nonmatching/code_0803CDCC", blend_obj_palettes_to_color_0803F684);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", blend_obj_palettes_to_color_0803F788);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", palette_blend_to_color_0803F890);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", blend_obj_palettes_to_color_0803F998);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", text_window_init);

void sub_0803FB0C(void)
{
    gUnk_03000440.unk4 = 4;
    gUnk_03000440.unkC = 0;
    gUnk_03000440.unk14 = 0;
    gUnk_03000440.unk15 = 0;
    gUnk_03000440.unk16 = 0;
    gUnk_03000440.unk17 = 0;
    gUnk_03000440.unk18 = 0;
    gUnk_03000440.unk19 = 0;
    gUnk_03000440.unk1A = 0;
    gUnk_03000440.unk1B = 0;
    gUnk_03000440.unk24 = 0;
    gUnk_03000440.unk25 = 0;
    gUnk_03000440.unk27 = 0;
}

INCLUDE_ASM("asm/nonmatching/code_0803CDCC", run_message);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", game_state_advance_substate);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803FB94);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803FC20);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803FCC8);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803FD28);

void sub_0803FEA8(void)
{
    gUnk_03000440.unkC++;
}

INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803FEB8);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", text_render_glyph_step);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_080402B4);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", reset_text_tile_state);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", update_text_compose_and_input);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0804070C);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_080407A4);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_08040820);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_080408D0);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_080408F4);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_08040914);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_08040934);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_08040954);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_08040974);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_08040994);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_08040A00);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_08040A40);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_08040B0C);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_08040B5C);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", init_battle_sprite_entry_08040B90);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", process_sprite_anim_commands);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", clear_battle_sprite_slot);

void clear_sprite_table_mask(u8 first, u8 count)
{
    u32 i;
    for (i = 0; i < count; i++)
        gUnk_03002C30[first + i].unk0 &= 0x7FFF;
}

void set_sprite_hidden_flags(u8 first, u8 count)
{
    u32 i;
    for (i = 0; i < count; i++)
        gUnk_03002C30[first + i].unk0 |= 0x8000;
}

u32 find_next_free_sprite_slot(u8 first, u8 count)
{
    u8 i;
    u32 slot;
    for (i = 0; i < count; i++)
    {
        slot = first + i;
        if (slot == 0x80)
            return first;
        if (gUnk_03002C30[slot].unk0 == 0)
            return slot;
    }
    return first;
}

INCLUDE_ASM("asm/nonmatching/code_0803CDCC", render_text_sprites_08040DB8);
