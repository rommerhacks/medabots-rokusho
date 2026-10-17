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

void open_choice_menu(u8 a, u8 b, u8 c)
{
    sub_0803F624(&gUnk_03000440.unk28, 8, 0);
    gUnk_03000440.unk2A = a;
    gUnk_03000440.unk2B = 0x7F;
    gUnk_03000440.unk2C = b;
    gUnk_03000440.unk2D = c;
}

void init_window_params(u8 a, u8 b, u8 c, u8 d)
{
    sub_0803F624(&gUnk_03000440.unk28, 8, 0);
    gUnk_03000440.unk2A = a;
    gUnk_03000440.unk2B = d;
    gUnk_03000440.unk2C = b;
    gUnk_03000440.unk2D = c;
}

u32 poll_choice_menu(void)
{
    gUnk_083B2814[gUnk_03000440.unk29]();
    return gUnk_03000440.unk28;
}

INCLUDE_ASM("asm/nonmatching/code_08040EE4", decompress_bg_tilemap_to_vram);

void clear_tilemap_and_advance_state(void)
{
    vram_fill_tilemap_rect(8, 6, gUnk_03000440.unk2C, gUnk_03000440.unk2D, REG_BG0CNT, 0);
    vram_fill_tilemap_rect(8, 6, 0, 0x15, REG_BG0CNT, 0);
    gUnk_03000440.unk29++;
}

void clear_and_copy_tilemap_rows(void)
{
    u32 i, j;
    u16 *d = (u16 *)(VRAM + 0x2800) + gUnk_03000440.unk2D * 32 + gUnk_03000440.unk2C;
    u16 *row = d;
    u16 *s;

    for (j = 0; j < 2; j++)
    {
        for (i = 0; i < 8; i++)
            *d++ = 0;
        row += 32;
        d = row;
    }
    s = (u16 *)(VRAM + 0x2D40);
    for (i = 0; i < 8; i++)
        *d++ = *s++;
    row += 32;
    d = row;
    s = (u16 *)(VRAM + 0x2E80);
    for (i = 0; i < 8; i++)
        *d++ = *s++;
    row += 32;
    d = row;
    for (j = 0; j < 2; j++)
    {
        for (i = 0; i < 8; i++)
            *d++ = 0;
        row += 32;
        d = row;
    }
    gUnk_03000440.unk29++;
}

INCLUDE_ASM("asm/nonmatching/code_08040EE4", transition_draw_tile_strip);

void copy_transition_tiles_to_bg2(void)
{
    u32 i, j;
    u16 *d = (u16 *)(VRAM + 0x2800) + gUnk_03000440.unk2D * 32 + gUnk_03000440.unk2C;
    u16 *s = (u16 *)(VRAM + 0x2D40);
    u16 *srow = s;
    u16 *row = d;

    for (j = 0; j < 6; j++)
    {
        for (i = 0; i < 8; i++)
            *d++ = *s++;
        row += 32;
        d = row;
        srow += 32;
        s = srow;
    }
    gUnk_03000440.unk29++;
}

INCLUDE_ASM("asm/nonmatching/code_08040EE4", battle_sprite_setup_cursor);

void advance_sprite_scroll_animation(void)
{
    gUnk_03002C30[gUnk_03000440.unk2B].unk8 += 8;
    gUnk_03002C30[gUnk_03000440.unk2B].unk9 += 8;
    if (gUnk_03002C30[gUnk_03000440.unk2B].unk8 >= 0x40)
    {
        gUnk_03002C30[gUnk_03000440.unk2B].unk8 = 0x40;
        gUnk_03002C30[gUnk_03000440.unk2B].unk9 = 0x40;
        gUnk_03000440.unk29++;
    }
    gUnk_03000440.unk84 = 0;
}

INCLUDE_ASM("asm/nonmatching/code_08040EE4", handle_battle_sprite_scroll_input);

void update_sprite_hflip_by_animation_phase(void)
{
    if (gUnk_03000440.unk84 != 0x1E)
    {
        if (gUnk_03000440.unk84 & 4)
            gUnk_03002C30[gUnk_03000440.unk2B].unk0 &= 0xBFFF;
        else
            gUnk_03002C30[gUnk_03000440.unk2B].unk0 |= 0x4000;
        gUnk_03000440.unk84++;
    }
    else
    {
        gUnk_03002C30[gUnk_03000440.unk2B].unk0 |= 0x4000;
        gUnk_03000440.unk29++;
    }
}

INCLUDE_ASM("asm/nonmatching/code_08040EE4", animate_battle_sprite_shrink);

void sub_08041C14(u8 sprite, u8 frame, u16 y)
{
    switch ((frame & 0xC) >> 2)
    {
    case 1:
        gUnk_03002C30[sprite].unk2 = y + 1;
        break;
    case 3:
        gUnk_03002C30[sprite].unk2 = y - 1;
        break;
    default:
        gUnk_03002C30[sprite].unk2 = y;
        break;
    }
}

void sub_08041C5C(u8 sprite, u8 frame, u16 x)
{
    switch ((frame & 0xC) >> 2)
    {
    case 1:
        gUnk_03002C30[sprite].unk4 = x + 1;
        break;
    case 3:
        gUnk_03002C30[sprite].unk4 = x - 1;
        break;
    default:
        gUnk_03002C30[sprite].unk4 = x;
        break;
    }
}

u32 game_state_execute_handler_a(void)
{
    gUnk_03000440.unk4 = 0;
    gUnk_083B284C[gUnk_03000440.unk1B]();
    if (gUnk_03000440.unk4 > 7)
        return 1;
    return 0;
}

u32 game_state_execute_handler_b(void)
{
    gUnk_03000440.unk4 = 0;
    gUnk_083B2864[gUnk_03000440.unk1B]();
    if (gUnk_03000440.unk4 > 7)
        return 1;
    return 0;
}

void memcpy_bytes_08041D04(const void *src, void *dst, u8 n)
{
    u32 i;

    for (i = 0; i < n; i++)
    {
        *(u8 *)dst = *(const u8 *)src;
        src = (const u8 *)src + 1;
        dst = (u8 *)dst + 1;
    }
}

void sub_08041D28(void)
{
    u32 i;
    for (i = 0; i < 30; i++)
        gUnk_03000BE0[i].unk0 = i;
}

u32 find_medal_slot_by_id(u8 id)
{
    u32 i;

    for (i = 0; i < 30; i++)
        if ((gUnk_03000BE0[i].unk0 & 0x80) && gUnk_03000BE0[i].unk1 == id)
            return i + 1;
    return 0;
}

INCLUDE_ASM("asm/nonmatching/code_08040EE4", load_palette_entry);

void medal_remove_by_id(u8 id)
{
    u32 i;

    for (i = 0; i < 30; i++)
    {
        if ((gUnk_03000BE0[i].unk0 & 0x80) && gUnk_03000BE0[i].unk1 == id)
        {
            u8 f = gUnk_03000BE0[i].unk0 & 0x1F;
            sub_0803F624((u8 *)&gUnk_03000BE0[i], 0x40, 0);
            gUnk_03000BE0[i].unk0 = f;
            return;
        }
    }
}

void export_medals_to_buffer(const void *src)
{
    u32 i;

    for (i = 0; i < 30; i++)
    {
        if (!(gUnk_03000BE0[i].unk0 & 0x80))
        {
            u32 f = gUnk_03000BE0[i].unk0 & 0x1F;
            memcpy_bytes_0803F63C(src, &gUnk_03000BE0[i], 0x40);
            gUnk_03000BE0[i].unk0 = (gUnk_03000BE0[i].unk0 & 0x80) | f;
            return;
        }
    }
}

u32 clear_ewram_buffer_02023000(void)
{
    u32 zero = 0;
    struct SortEntry *e = SORT_BUFFER;
    struct Unk_03000BE0 *m;
    u32 i;

    CpuFastSet(&zero, e, 0x01000080);
    for (i = 0, m = gUnk_03000BE0; i < 30; m++, e++, i++)
        e->key = m->unk5;
    sub_0804242C(30);
    return (SORT_BUFFER[0].key - SORT_BUFFER[3].key) / 2 + SORT_BUFFER[3].key;
}

u32 sub_080420C4(u8 level, u8 a, u8 b, u8 c, u8 d)
{
    if (d != 0 && level >= d)
        return 4;
    if (c != 0 && level >= c)
        return 3;
    if (b != 0 && level >= b)
        return 2;
    if (a != 0 && level >= a)
        return 1;
    return 0;
}

u32 sub_08042114(u8 a, u8 b)
{
    u32 hi = gMedapartInventory[b * 240 + a * 2] << 8;
    return gMedapartInventory[b * 240 + a * 2 + 1] | hi;
}

void medapart_add_quantity(u8 id, u8 kind, u8 n)
{
    u8 *inv = gMedapartInventory;
    u8 *p = &inv[kind * 240 + id * 2];
    s32 v = n + *p;

    if (v > 99)
        *p = 99;
    else
        *p = v;
}

void reduce_medapart_stat(u8 id, u8 kind, u8 n)
{
    u8 *inv = gMedapartInventory;
    u8 *p = &inv[kind * 240 + id * 2];
    s32 v = *p - n;

    if (v < 0)
        v = 0;
    *p = v;
}

void sub_080421A0(void)
{
    u32 i;
    for (i = 0; i < 9; i++)
        gUnk_030017A0[i].unk7 = i;
}

void sub_080421B4(u8 medal, u8 kind)
{
    u32 i;

    for (i = 0; i < 9; i++)
    {
        if (gUnk_030017A0[i].unk7 == medal)
        {
            u8 *p = &gUnk_030017A0[i].unk3;
            u8 old = p[kind];

            p[kind] = gUnk_030017A0[i].unk1 + 0x78;
            gUnk_030017A0[i].unk0 = 2;
            gMedapartInventory[kind * 240 + old * 2]--;
            gMedapartInventory[kind * 240 + old * 2 + 1]--;
            return;
        }
    }
}

u32 team_is_full(void)
{
    u32 i;

    for (i = 0; i < 9; i++)
        if (gUnk_030017A0[i].unk0 == 0)
            return 0;
    return 1;
}

void team_add_tinpet(u8 gender)
{
    u32 i;

    for (i = 0; i < 9; i++)
    {
        if (gUnk_030017A0[i].unk0 == 0)
        {
            gUnk_030017A0[i].unk0 = 1;
            gUnk_030017A0[i].unk1 = gender & 1;
            gUnk_030017A0[i].unk2 = 0x1E;
            gUnk_030017A0[i].unk3 = (gender & 1) + 0x78;
            gUnk_030017A0[i].unk4 = (gender & 1) + 0x78;
            gUnk_030017A0[i].unk5 = (gender & 1) + 0x78;
            gUnk_030017A0[i].unk6 = (gender & 1) + 0x78;
            return;
        }
    }
}

u32 get_item_quantity_by_id(u8 id)
{
    u32 i;
    u8 key = id & 0x3F;

    for (i = 0; i < 64; i++)
        if ((gItemInventory[i][0] & 0x80) && (gItemInventory[i][0] & 0x7F) == key)
            return gItemInventory[i][1];
    return 0;
}

INCLUDE_ASM("asm/nonmatching/code_08040EE4", item_add_quantity);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", sub_08042318);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", sub_0804242C);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", rng_next_080424B8);

void set_blend_effect_mode(u8 mode, u16 targets, u16 speed)
{
    u16 bld, eva, evb, evy;

    gUnk_03000440.unk90 = mode;
    gUnk_03000440.unk92 = speed;
    gUnk_03000440.unk94 = 0;
    switch (mode)
    {
    case 1:
        bld = 0x40;
        eva = 16;
        evb = 16;
        evy = 16;
        break;
    case 2:
        bld = 0x40;
        eva = 0;
        evb = 0;
        evy = 0;
        break;
    case 3:
        bld = 0x80;
        eva = 16;
        evb = 16;
        evy = 16;
        break;
    case 4:
        bld = 0x80;
        eva = 0;
        evb = 0;
        evy = 0;
        break;
    case 5:
        bld = 0xC0;
        eva = 16;
        evb = 16;
        evy = 16;
        break;
    case 6:
        bld = 0xC0;
        eva = 0;
        evb = 0;
        evy = 0;
        break;
    default:
        bld = 0;
        eva = 0;
        evb = 0;
        evy = 0;
        break;
    }
    REG_BLDALPHA = ((evb & 0x1F) << 8) | (eva & 0x1F);
    REG_BLDY = evy & 0x1F;
    REG_BLDCNT = bld | targets;
}

// Other modes write whatever eva / evb / evy hold (uninitialized), like the original.
u32 update_blend_effect(void)
{
    u16 eva, evb, evy;

    gUnk_03000440.unk94 += gUnk_03000440.unk92;
    switch (gUnk_03000440.unk90)
    {
    case 1:
    case 3:
    case 5:
        eva = 16 - (gUnk_03000440.unk94 >> 4);
        evb = eva;
        evy = eva;
        break;
    case 2:
    case 4:
    case 6:
        eva = gUnk_03000440.unk94 >> 4;
        evb = eva;
        evy = eva;
        break;
    }
    REG_BLDALPHA = ((evb & 0x1F) << 8) | (eva & 0x1F);
    REG_BLDY = evy & 0x1F;
    if (gUnk_03000440.unk94 > 0xFF)
        return 1;
    return 0;
}

void fill_text_blank(u8 *buf, u8 n)
{
    u32 i;

    for (i = 0; i < n; i++)
        *buf++ = 0x43;
    *buf = 0xFE;
}

void fill_tilemap_rect_08042698(u32 w, u32 h, u32 x, u32 y, u32 bgcnt, u16 entry)
{
    u32 i, j;
    u16 *base = (u16 *)(VRAM + ((bgcnt >> 8) & 0x1F) * 0x800) + x + y * 32;

    for (j = 0; j < h; j++)
    {
        u16 *p = base + j * 32;
        for (i = 0; i < w; i++)
            *p++ = entry++;
    }
}

INCLUDE_ASM("asm/nonmatching/code_08040EE4", fill_tilemap_pair_or_divide);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", divide_by_100000_08042838);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", sub_08042950);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", sub_08042A90);

void load_part_data(u32 part, u32 kind, u8 *dst)
{
    u32 i;
    u8 *d = dst;
    for (i = 0; i < 16; i++)
        *d++ = gUnk_083B827C[part * 64 + kind * 16 + i];
}

// No return for a > 7: the original falls through with a still in r0.
u32 sub_08042B80(u32 a)
{
    switch (a)
    {
    case 0:
    case 1:
    case 4:
    case 5:
        return 0;
    case 2:
    case 3:
    case 6:
        return 1;
    case 7:
        return 1;
    }
}

INCLUDE_ASM("asm/nonmatching/code_08040EE4", calc_polar_to_screen_coords);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", compute_polar_to_screen_position);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", decompress_sprite_to_vram_08042D94);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", init_battle_medabot_sprites);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", setup_battle_sprite_group);

void battle_sprite_set_palette_index(u32 sprite, u32 pal)
{
    u32 i;

    gUnk_03002C30[sprite + 1].unk0 |= 0x200;
    gUnk_03002C30[sprite + 2].unk0 |= 0x200;
    for (i = 0; i < 16; i++)
        ;
    gUnk_03002C30[sprite].unk24 = pal;
    gUnk_03002C30[sprite + 1].unk24 = pal;
    gUnk_03002C30[sprite + 2].unk24 = pal;
    gUnk_03002C30[sprite + 3].unk24 = pal;
}

INCLUDE_ASM("asm/nonmatching/code_08040EE4", update_battle_sprite_orbiting_positions);

void modify_medapart_quantity(u32 id, u32 kind, u32 byte, u32 subtract, u32 n)
{
    if (subtract)
    {
        gMedapartInventory[kind * 240 + id * 2 + byte] -= n;
    }
    else
    {
        u8 *inv = gMedapartInventory;
        u8 *p = &inv[kind * 240 + id * 2 + byte];
        u32 v = *p + n;

        if (v > 99)
            v = 99;
        *p = v;
    }
}

INCLUDE_ASM("asm/nonmatching/code_08040EE4", draw_tilemap_with_offset);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", sub_0804361C);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", find_next_available_medapart_slot);

u32 medabot_detail_is_full_set(void)
{
    if (gUnk_03000440.unk98 != gUnk_03000440.unk99)
        return 0;
    if (gUnk_03000440.unk98 != gUnk_03000440.unk9A)
        return 0;
    if (gUnk_03000440.unk98 != gUnk_03000440.unk9B)
        return 0;
    return 1;
}

u32 validate_medapart_stats(u8 medal, u8 head, u8 rarm, u8 larm, u8 legs)
{
    if (medal != 0x1E && head <= 0x77 && rarm <= 0x77 && larm <= 0x77 && legs <= 0x77)
        return 1;
    return 0;
}

u32 sub_0804384C(u8 medal)
{
    u32 i;
    if (medal >= 0x1E)
        return 0xFF;
    for (i = 0; i < 9; i++)
        if (gUnk_030017A0[i].unk0 > 1 && gUnk_030017A0[i].unk2 == medal)
            return i;
    return 0xFF;
}

void load_battlefield_data_to_buffer(void)
{
    memcpy_bytes_08041D04(gUnk_083BEA90[gUnk_030057E0.unk7FE], &gUnk_03000440.unkEE, 1);
    gUnk_030057E0.unkC29 = gUnk_03000440.unkEE;
    gUnk_030057E0.unkC2B = 0;
}

INCLUDE_ASM("asm/nonmatching/code_08040EE4", check_random_encounter);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", sub_08043AE0);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", decompress_tileset_to_vram);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", decompress_sprite_to_vram_08043C08);

s32 sub_08043C94(void)
{
    return rng_next_080424B8() * 100 / 255;
}

void sub_08043CA8(void)
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

INCLUDE_ASM("asm/nonmatching/code_08040EE4", update_scroll_movement_a);

void apply_battle_blend_effect_a(void)
{
    if (gUnk_03001800.unk39[3])
    {
        REG_BLDALPHA = (gUnk_03001800.unk39[4] << 8) | gUnk_03001800.unk39[5];
        REG_BLDY = 0;
        REG_BLDCNT = 0x1844;
    }
    else
        set_blend_effect_mode(0, 0, 0);
}

void sub_08043E48(void)
{
    update_scroll_movement_a();
}

void load_battle_script_entry_b(void)
{
    memcpy_bytes_0803F63C(gUnk_083C3B5C[gUnk_03001800.unk38], gUnk_03001800.unk74, 8);
}

INCLUDE_ASM("asm/nonmatching/code_08040EE4", update_scroll_movement_b);

void apply_battle_blend_effect_b(void)
{
    if (gUnk_03001800.unk74[3])
    {
        REG_BLDALPHA = (gUnk_03001800.unk74[4] << 8) | gUnk_03001800.unk74[5];
        REG_BLDY = 0;
        REG_BLDCNT = 0x1844;
    }
    else
        set_blend_effect_mode(0, 0, 0);
}

INCLUDE_ASM("asm/nonmatching/code_08040EE4", advance_battle_animation_frame);

void sub_08044094(void)
{
    gGameMode = 1;
    gGameState = 1;
    gGameSubState = 7;
}

u32 sub_080440B4(void)
{
    u32 n = 0;
    u32 i;

    for (i = 0; i < 9; i++)
        if (gUnk_030017A0[i].unk0 == 3)
            n++;
    return n;
}

u32 sub_080440D4(void)
{
    u32 i;

    for (i = 0; i < 480; i++)
        if (gMedapartInventory[i * 2] != gMedapartInventory[i * 2 + 1])
            return 0;
    return 1;
}

void sub_08044100(void)
{
    update_scroll_movement_b();
    advance_battle_animation_frame(gUnk_03001800.unk38);
}

void read_vram_tilemap_rect(u32 w, u32 h, u32 x, u32 y, u32 bgcnt, void *dst)
{
    u32 i, j;
    u16 *d = dst;
    u16 *base = (u16 *)(VRAM + ((bgcnt >> 8) & 0x1F) * 0x800) + x + y * 32;

    for (j = 0; j < h; j++)
    {
        u16 *p = base + j * 32;
        for (i = 0; i < w; i++)
            *d++ = *p++;
    }
}

void write_vram_tilemap_rect(u32 w, u32 h, u32 x, u32 y, u32 bgcnt, const void *src)
{
    u32 i, j;
    const u16 *s = src;
    u16 *base = (u16 *)(VRAM + ((bgcnt >> 8) & 0x1F) * 0x800) + x + y * 32;

    for (j = 0; j < h; j++)
    {
        u16 *p = base + j * 32;
        for (i = 0; i < w; i++)
            *p++ = *s++;
    }
}

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

u32 sub_08044B34(u8 a)
{
    if (a == 0)
        return gUnk_083B2970[gUnk_030057E0.unkC5C];
    return a;
}

void sub_08044B58(void)
{
    gUnk_03000BE0[0].unk0 |= 0xC0;
    gUnk_030017A0[0].unk0 = 3;
    gUnk_030017A0[0].unk2 = 0;
    gUnk_030017A0[0].unk3 = 0x2A;
    gUnk_030017A0[0].unk4 = 0x2A;
    gUnk_030017A0[0].unk5 = 0x2A;
    gUnk_030017A0[0].unk6 = 0x2A;
    gMedapartInventory[0 * 240 + 0x2A * 2 + 1] = 1;
    gMedapartInventory[1 * 240 + 0x2A * 2 + 1] = 1;
    gMedapartInventory[2 * 240 + 0x2A * 2 + 1] = 1;
    gMedapartInventory[3 * 240 + 0x2A * 2 + 1] = 1;
}

INCLUDE_ASM("asm/nonmatching/code_08040EE4", init_battle_scene);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", init_game_mode);

void sub_08044CDC(u32 a)
{
    switch (a)
    {
    case 0: sub_08064A74(); break;
    case 1: sub_08064A94(); break;
    case 2: sub_08064AB4(); break;
    case 3: sub_08064AD4(); break;
    }
}

INCLUDE_ASM("asm/nonmatching/code_08040EE4", dma3_copy_or_decompress);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", set_oam_sprite_shape_size);
INCLUDE_ASM("asm/nonmatching/code_08040EE4", sub_08044E64);
