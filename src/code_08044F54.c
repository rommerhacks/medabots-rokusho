#include "global.h"
#include "keys.h"

void dma_load_sprite_tiles(const u32 *src, u16 tile, void *buf, u32 useCpu)
{
    if (src != NULL)
    {
        u32 size = dma3_copy_or_decompress(src, buf);

        if (useCpu)
            CpuSet(buf, (void *)(0x06010000 + tile * 32), ((size / 4) & 0x1FFFFF) | 0x04000000);
        else
            DmaSet(0, buf, 0x06010000 + tile * 32, (size >> 2) | 0x94000000);
    }
}

INCLUDE_ASM("asm/nonmatching/code_08044F54", copy_sprite_tiles_to_vram);

void decompress_and_load_sprite_tiles(const u32 *src, s32 shape, s32 size, s32 rows, s32 cols, s32 bpp, u16 tile, u32 unused, u8 *buf, u32 useCpu)
{
    if (src != NULL)
    {
        u32 n = dma3_copy_or_decompress(src, buf);
        u8 *out = buf + n;

        copy_sprite_tiles_to_vram(out, buf, shape, size, rows, cols, bpp);
        if (useCpu)
            CpuSet(out, (void *)(0x06010000 + tile * 32), ((n / 4) & 0x1FFFFF) | 0x04000000);
        else
            DmaSet(0, out, 0x06010000 + tile * 32, (n >> 2) | 0x94000000);
    }
}

INCLUDE_ASM("asm/nonmatching/code_08044F54", setup_oam_sprite_entries);

u32 init_sprite_object_entry(struct SpriteOamList *obj, struct OamData *oams, void *b, void *c, const struct SpriteDesc *desc, const struct SpriteAnchor *e, u8 f, u16 g)
{
    obj->oams = oams;
    obj->unk4 = e;
    obj->w = desc->w;
    obj->h = desc->h;
    obj->depth = e->unk6;
    return setup_oam_sprite_entries(oams, b, c, desc, e, f, g);
}

INCLUDE_ASM("asm/nonmatching/code_08044F54", set_oam_sprite_tile_positions);
INCLUDE_ASM("asm/nonmatching/code_08044F54", setup_sprite_from_oam_descriptor);

u16 binary_search_sorted_table(struct SortEntry *arr, u16 n, u16 key)
{
    u16 lo, hi, mid = 0;
    s16 v;

    if (n != 0)
    {
        lo = 0;
        hi = n - 1;
        mid = (lo + hi) >> 1;
        while (mid != lo && mid != hi)
        {
            v = arr[mid].unk6;
            if (v == (s16)key)
                break;
            if (v < (s16)key)
                lo = mid;
            if (v > (s16)key)
                hi = mid;
            mid = (lo + hi) >> 1;
        }
        while (mid < n && (s16)arr[mid].unk6 <= (s16)key)
            mid++;
    }
    return mid;
}

INCLUDE_ASM("asm/nonmatching/code_08044F54", sorted_array_insert_shift);
INCLUDE_ASM("asm/nonmatching/code_08044F54", copy_oam_entries_with_priority);
INCLUDE_ASM("asm/nonmatching/code_08044F54", copy_sprite_oam_entries);

u16 batch_copy_oam_entries(struct SpriteOamBatch *batch, struct OamData *dst, u16 end)
{
    u16 n = 0;
    u16 count = batch->count;
    u16 i;

    for (i = 0; i < count; i++)
    {
        n += copy_oam_entries_with_priority(batch->lists[i], dst, n, end);
        if (n >= end)
            break;
    }
    return n;
}

INCLUDE_ASM("asm/nonmatching/code_08044F54", sub_08045908);
INCLUDE_ASM("asm/nonmatching/code_08044F54", sub_080459A4);

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

u16 copy_sprite_oam_with_vflip(void *a, void *b, u16 c, u32 unused, s8 d, u8 f)
{
    return copy_sprite_oam_entries(a, b, c, d, 0x80, f);
}

INCLUDE_ASM("asm/nonmatching/code_08044F54", sub_08045A8C);
INCLUDE_ASM("asm/nonmatching/code_08044F54", render_sprite_if_visible);

u16 init_oam_sprite_entry(struct OamFull *oam, struct SpriteNodeDesc *desc, u8 pal, u16 tile)
{
    u16 dims[2];
    u16 n;

    oam->y = 0;
    oam->affineMode = desc->affineMode;
    oam->objMode = desc->objMode;
    oam->mosaic = 0;
    oam->bpp = desc->bpp;
    oam->shape = 0;
    oam->x = 0;
    oam->matrixNum = 0;
    oam->hFlip = desc->hFlip;
    oam->vFlip = desc->vFlip;
    oam->size = 0;
    oam->tileNum = tile;
    oam->priority = 2;
    oam->paletteNum = pal + desc->paletteNum;
    oam->affineParam = 0;
    dims[0] = desc->width;
    if (desc->wDiv > 1)
        dims[0] = Div(dims[0], desc->wDiv);
    dims[1] = desc->height;
    if (desc->hDiv > 1)
        dims[1] = Div(dims[1], desc->hDiv);
    set_oam_sprite_shape_size((u8 *)oam, dims[0], dims[1]);
    n = (dims[0] >> 3) * (dims[1] >> 3);
    if (desc->bpp)
        n *= 2;
    return n;
}

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

void sub_08047574(void)
{
    sub_080496C8((u8 *)&gUnk_03005310, 0x3C);
    sub_080496C8((u8 *)&gUnk_030057A0, 0x38);
    sub_080496C8((u8 *)&gUnk_03006D14, 4);
    sub_080496C8((u8 *)&gUnk_030057DC, 4);
    sub_080496C8((u8 *)&gUnk_0300534C, 4);
    sub_080496C8((u8 *)gUnk_030055A0, 0x200);
    sub_080496C8((u8 *)gUnk_03006D40, 0x200);
    sub_080496C8((u8 *)&gUnk_03006F40, 0x34);
    sub_080496C8((u8 *)&gUnk_03006D38, 8);
    sub_080496C8((u8 *)&gUnk_03006D20, 0x10);
    sub_080496C8((u8 *)&gUnk_030057D8, 4);
    sub_080496C8((u8 *)&gMapScriptData, 4);
    sub_080496C8((u8 *)&gUnk_03005350, 0x240);
    sub_080496C8((u8 *)&gUnk_03006D30, 4);
    sub_080496C8((u8 *)&gUnk_030064A0, 0x874);
}

void sub_0804763C(void)
{
    gUnk_083D1F84[gGameState]();
}

void sub_0804765C(u32 a)
{
    switch (a)
    {
    case 0:
        gUnk_03005310.unk39 = gUnk_03000440.unk9C;
        if (gUnk_030057E0.unkC88 != 0)
        {
            gGameMode = 1;
            gGameState = 1;
            gGameSubState = 5;
        }
        else
        {
            gGameMode = 1;
            gGameState = 1;
            gGameSubState = 13;
        }
        break;
    case 1:
        gGameMode = 1;
        gGameState = 2;
        gGameSubState = 0;
        break;
    }
}

void dispatch_by_index_0476e8(u32 idx)
{
    switch (idx)
    {
    case 0:
    case 1:
    case 2:
    case 3:
    case 12:
        break;
    case 4:
        gGameMode = 1;
        gGameState = 1;
        gGameSubState = 0x10;
        return;
    case 5:
        gGameMode = 1;
        gGameState = 1;
        gGameSubState = 0x20;
        return;
    case 6:
        gGameMode = 1;
        gGameState = 2;
        gGameSubState = 8;
        return;
    case 7:
        gUnk_03006D20.unkC = 7;
        break;
    case 8:
        gUnk_03006D20.unkC = 8;
        break;
    case 10:
        sub_08047574();
        sub_080496C8((u8 *)&gUnk_030057E0, 0xCC0);
        gUnk_03000588 = 1;
        gGameMode = 1;
        gGameState = 1;
        gGameSubState = 0;
        return;
    case 11:
        sub_08047574();
        gUnk_030057E0.unkC88 = 0;
        gUnk_030057E0.unkC89 = 0;
        gUnk_03000588 = 1;
        gGameMode = 1;
        gGameState = 1;
        gGameSubState = 10;
        return;
    case 9:
        gUnk_03000588 = 1;
        break;
    default:
        return;
    }
    gGameMode = 1;
    gGameState = 1;
    gGameSubState = 5;
}

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

void sub_08047878(u32 a, u32 b)
{
    switch (a)
    {
    case 0x20:
        gUnk_030057E0.unkC2D = 1;
        gGameMode = 0;
        gGameState = 6;
        gGameSubState = 0;
        break;
    case 0x21:
        gUnk_030057E0.unkC2D = 0;
        gGameMode = 0;
        gGameState = 6;
        gGameSubState = 0;
        break;
    case 0x40:
        gGameMode = 0;
        gGameState = 1;
        gGameSubState = 0x10;
        break;
    case 0x41:
        gGameMode = 1;
        gGameState = 1;
        gGameSubState = 0x18;
        break;
    case 0x42:
        gGameMode = 1;
        gGameState = 1;
        gGameSubState = 0x1C;
        break;
    case 0x43:
        gGameMode = 1;
        gGameState = 1;
        gGameSubState = 0x28;
        break;
    case 0:
        gUnk_03000584 = 0;
        gGameMode = 2;
        gGameState = 0x12;
        gGameSubState = 0;
        break;
    case 1:
        gUnk_03000584 = 1;
        gGameMode = 2;
        gGameState = 0x12;
        gGameSubState = 0;
        break;
    case 2:
        gUnk_03000584 = 2;
        gGameMode = 2;
        gGameState = 0x12;
        gGameSubState = 0;
        break;
    case 3:
        gUnk_03002420 = b;
        gGameMode = 2;
        gGameState = 0xB;
        gGameSubState = 0;
        break;
    case 4:
        gGameMode = 2;
        gGameState = 0x15;
        gGameSubState = 0;
        break;
    case 5:
        gUnk_03000588 = 0;
        gGameMode = 2;
        gGameState = 0x14;
        gGameSubState = 0;
        break;
    case 6:
        gGameMode = 2;
        gGameState = 0x17;
        gGameSubState = 0;
        break;
    case 8:
        gGameMode = 2;
        gGameState = 0x16;
        gGameSubState = 0;
        break;
    case 0x10:
        gGameMode = 3;
        gGameState = 4;
        gGameSubState = 0;
        break;
    case 0x11:
        gGameMode = 3;
        gGameState = 5;
        gGameSubState = 0;
        break;
    case 0x12:
        gGameMode = 3;
        gGameState = 3;
        gGameSubState = 0;
        break;
    case 0x13:
        gGameMode = 3;
        gGameState = 6;
        gGameSubState = 0;
        break;
    }
}

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

void init_cursor_state(void)
{
    sub_08047E4C();
    gBg0Scroll.x = 0;
    gBg0Scroll.y = 0;
    gUnk_030064A0.unk0 = 0;
    gUnk_030064A0.unk1 = 0;
}

u32 scene_transition_step_08047C24(u8 a, u8 b, u8 c, const void *text)
{
    u32 ret = 0;

    switch (gUnk_030064A0.unk0)
    {
    case 0:
        if (gUnk_030064A0.unk1 == 0)
            text_window_init(a, b, c);
        else
            sub_0803FB0C();
        gUnk_030064A0.unk0++;
        break;
    case 1:
        if (run_message(text))
        {
            gUnk_030064A0.unk0 = ret;
            gUnk_030064A0.unk1++;
            ret = 1;
        }
        break;
    }
    return ret;
}

void format_number_to_text_buffer(u32 slot, u32 n)
{
    u8 buf[12];
    struct TextBufTable4 t = gUnk_080ABBFC;
    u8 *d = t.p[slot];
    s32 len = count_decimal_digits(n);
    s32 i;

    for (i = 0; i < len; i++)
        buf[i] = truncate_to_digit_count(n, len - 1 - i) + 0x35;
    memcpy_u8(buf, d, len);
    d[len] = 0xFE;
}

void copy_string_to_text_buffer(u32 slot, u32 str)
{
    u8 *s = (u8 *)str;
    struct TextBufTable4 t = gUnk_080ABBFC;
    u8 *d = t.p[slot];
    s32 i;

    for (i = 0; i < 16 && *s != 0xFE; i++)
        *d++ = *s++;
    *d = 0xFE;
}

void sub_08047D24(u32 slot, u32 n)
{
    u8 buf[12];
    struct TextBufTable4 t = gUnk_080ABBFC;
    divide_by_10000_b(t.p[slot], n);
}

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

void sub_08047DC0(u8 id, u8 n)
{
    if (n == 0)
        n = 1;
    item_add_quantity(id, n);
}

void sub_08047DD8(u8 id, u8 n)
{
    if (n == 0)
        n = 1;
    sub_08042318(id, n);
}

void sub_08047DF0(u8 a, u8 b, u8 n)
{
    medapart_add_quantity(a, b, n);
}

void sub_08047E08(u8 a, u8 b, u8 n)
{
    reduce_medapart_stat(a, b, n);
}

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

u32 lookup_position_table_value(u8 id, u8 which)
{
    u8 buf[16];
    s32 v;
    s32 match = check_position_table_match(id, which);

    if (match)
    {
        u32 found = 0;
        s32 i;
        struct Unk_030017A0 *p;

        for (i = 0, p = gUnk_030017A0; i <= 8; i++)
        {
            if (p->unk0 == 3)
            {
                switch (which)
                {
                case 0:
                    if (p->unk3 == id)
                        found = 1;
                    break;
                case 1:
                    if (p->unk4 == id)
                        found = 1;
                    break;
                case 2:
                    if (p->unk5 == id)
                        found = 1;
                    break;
                case 3:
                    if (p->unk6 == id)
                        found = 1;
                    break;
                }
            }
            if (found)
                break;
            p++;
        }
        load_part_data(gUnk_030017A0[i].unk6, 3, buf);
        v = buf[1] - 100;
        gUnk_03006D38.unk6 = gUnk_030017A0[i].unk1;
    }
    if (match)
        return v;
    return -1;
}

u32 check_position_table_match(u8 id, u8 which)
{
    u32 found = 0;
    s32 i;
    struct Unk_030017A0 *p;

    for (i = 0, p = gUnk_030017A0; i <= 8; i++)
    {
        if (p->unk0 == 3)
        {
            switch (which)
            {
            case 0:
                if (p->unk3 == id)
                    found = 1;
                break;
            case 1:
                if (p->unk4 == id)
                    found = 1;
                break;
            case 2:
                if (p->unk5 == id)
                    found = 1;
                break;
            case 3:
                if (p->unk6 == id)
                    found = 1;
                break;
            }
        }
        if (found)
            break;
        p++;
    }
    return found;
}

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

void init_bg0_for_cursor(u32 mode)
{
    REG_BG0CNT = 0x500;
    REG_DISPCNT = 0x1F60;
    open_choice_menu(mode, 0x16, 7);
    gUnk_030064A0.unk64 = 0;
}

u32 sub_08047FEC(void)
{
    u32 ret = 0;
    struct Unk_030064A0 *m = &gUnk_030064A0;
    u8 *step = &m->unk64;

    switch (*step)
    {
    case 1:
        if (game_state_execute_handler_b() == 0)
            break;
    case 0:
        gUnk_03000440.unk1B = ret;
        (*step)++;
        break;
    case 2:
        ret = poll_choice_menu();
        break;
    }
    return ret;
}

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

void update_battle_field_frame(void)
{
    gBg1Scroll.x = gUnk_03005310.unk1E;
    gBg1Scroll.y = gUnk_03005310.unk26;
    gBg2Scroll.x = gUnk_03005310.unk20;
    gBg2Scroll.y = gUnk_03005310.unk28;
    gBg3Scroll.x = gUnk_03005310.unk22;
    gBg3Scroll.y = gUnk_03005310.unk2A;
    sub_080482C0();
    dma_load_battle_palettes();
    load_room_graphics();
    gUnk_030057E0.unkC36 = 0;
    animate_area_bg_tiles();
    load_map_npc_sprites(gUnk_030057E0.unkCBA);
    update_entity_sprites_on_screen();
    init_battle_field_setup();
    update_bg_scroll_offsets_a();
    init_battle_medaforce_sprite();
    update_bg_scroll_offsets_b();
    decompress_battle_tile_graphics();
    gUnk_030057E0.unkC4C = 1;
    update_battle_entity_status_chars();
}

void animate_area_bg_tiles(void)
{
    const u8 *anim = gUnk_084096F4[gUnk_030057E0.unk7FE];
    u8 n = anim[0];
    u8 *src;

    if (gUnk_030057E0.unkC34 != 0 && anim[2] != 0)
    {
        if (gUnk_030057E0.unkC36 != 0)
        {
            gUnk_030057E0.unkC36--;
        }
        else
        {
            if (anim[gUnk_030057E0.unkC35 + 3] == 0xFF)
                gUnk_030057E0.unkC35 = 0;
            src = gUnk_030057DC + anim[gUnk_030057E0.unkC35 + 3] * n * 32;
            DmaSet(3, src, 0x06009020, 0x80000000 | (n << 4));
            gUnk_030057E0.unkC35++;
            gUnk_030057E0.unkC36 = 2;
        }
    }
}

INCLUDE_ASM("asm/nonmatching/code_08044F54", sub_080481C4);

void decompress_battle_tile_graphics(void)
{
    s32 i = 0;
    u8 *dst = (u8 *)0x06010000;
    u32 t;

    while ((t = resolve_tile_from_battle_state(i)) != 0xFF)
    {
        if (gUnk_083F80F4[t] == NULL)
            t = 1;
        LZ77UnCompVram(gUnk_083F80F4[t], dst);
        dst += 0x900;
        i++;
    }
}

void decompress_terrain_tiles_to_vram(s32 arg)
{
    s32 i;
    u8 *dst;
    const u8 *const *tbl;
    s32 t = sub_080481C4(arg);

    tbl = gUnk_083F80F4;
    dst = (u8 *)0x06010000;
    for (i = 11; i >= 0; i--)
    {
        if (tbl[t] == NULL)
            t = 1;
        LZ77UnCompVram(tbl[t], dst);
        dst += 0x900;
    }
}

void sub_080482C0(void)
{
    const u16 *pal = gUnk_083F9BF4[gUnk_030057E0.unk7FE];

    if (pal != NULL)
    {
        DmaSet(3, pal, 0x0202FA00, 0x84000068);
    }
    else
    {
        DmaSet(3, gUnk_080AC5B4, 0x0202FA00, 0x84000008);
        DmaSet(3, gUnk_080AC654, 0x0202FA20, 0x84000008);
        DmaSet(3, gUnk_080AC6F4, 0x0202FA40, 0x84000008);
        DmaSet(3, gUnk_080AC794, 0x0202FA60, 0x84000008);
        DmaSet(3, gUnk_080AC5B4, 0x0202FA80, 0x84000008);
        DmaSet(3, gUnk_080AC5B4, 0x0202FAA0, 0x84000008);
        DmaSet(3, gUnk_080AC5B4, 0x0202FAC0, 0x84000008);
        DmaSet(3, gUnk_080AC834, 0x0202FAE0, 0x84000008);
        DmaSet(3, gUnk_080AC8D4, 0x0202FB00, 0x84000008);
    }
}

u8 sub_080483AC(void)
{
    if (gUnk_030057E0.unkC30 == 0xFF)
        return gUnk_030057E0.unkC31;
    return gUnk_0847EB80[gUnk_030057E0.unk7FE];
}

INCLUDE_ASM("asm/nonmatching/code_08044F54", dispatch_jump_table_29);

u32 resolve_tile_from_battle_state(u32 arg)
{
    return sub_080481C4(gUnk_08413514[gUnk_030057E0.unk7FE][arg]);
}

void dma_load_obj_palettes_08048664(void)
{
    s32 i;
    u32 t;

    for (i = 0; (t = resolve_tile_from_battle_state(i)) != 0xFF; i++)
    {
        t = resolve_tile_from_battle_state(i);
        if (gUnk_083F8634[t] == NULL)
            t = 1;
        DmaSet(3, gUnk_083F8634[t], 0x05000200 + i * 0x20, 0x84000008);
    }
}

void dma_load_battle_palettes(void)
{
    s32 i;
    u32 t;

    for (i = 0; (t = resolve_tile_from_battle_state(i)) != 0xFF; i++)
    {
        t = resolve_tile_from_battle_state(i);
        if (gUnk_083F8634[t] == NULL)
            t = 1;
        DmaSet(3, gUnk_083F8634[t], 0x0202F800 + i * 0x20, 0x84000008);
    }
    DmaSet(3, gUnk_085FA0E4, 0x0202F9C0, 0x84000008);
}

void dma_load_obj_palettes_08048730(s32 arg)
{
    s32 i = 0;
    s32 t = sub_080481C4(arg);

    for (; i <= 11; i++)
    {
        if (gUnk_083F8634[t] == NULL)
            t = 1;
        DmaSet(3, gUnk_083F8634[t], 0x05000200 + i * 0x20, 0x84000008);
    }
}

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

void clear_battle_sprite_entry(u8 slot)
{
    sub_080496C8((u8 *)&gUnk_03002C30[slot], 0x40);
    clear_entity_state(slot);
}

s32 count_decimal_digits(s32 n)
{
    s32 i, j, p;

    if (n == 0)
        return 1;
    for (i = 0; i <= 9; i++)
    {
        p = 1;
        for (j = 0; j < i; j++)
            p *= 10;
        if (n / p == 0)
            break;
    }
    return i;
}

INCLUDE_ASM("asm/nonmatching/code_08044F54", truncate_to_digit_count);

u32 sub_08048914(u32 a)
{
    u32 r;

    switch (a)
    {
    case 0:
        if (gUnk_083D29EB[gUnk_030057E0.unk7FE] == 0xA)
        {
            r = 2;
            break;
        }
        r = 1;
        if (gUnk_030057E0.unkC5D & 0x20)
            r = 3;
        break;
    case 1:
    case 5:
    case 12:
    case 13:
    case 19:
    case 39:
    case 40:
        r = 1;
        if (gUnk_030057E0.unkC5D & 1)
            r = 3;
        else if ((u8)(gUnk_030057E0.unkC5C - 1) <= 1)
            r = 4;
        break;
    default:
        r = 0;
        break;
    }
    return r;
}

// Dead code (nothing calls it): BG2 affine matrix for gUnk_03005310 (guess).
void sub_08048A40(void)
{
    const s16 *sine = gSineTable;
    struct Unk_03005310 *p = &gUnk_03005310;
    s32 a;

    p->unk8 = sub_08048B24(sine[a = p->unk36 + 0x40], divide_by_65536(p->unk32));
    p->unkA = sub_08048B24(sine[p->unk36], divide_by_65536(p->unk32));
    p->unkC = sub_08048B24(-sine[p->unk36], divide_by_65536(p->unk34));
    p->unkE = sub_08048B24(sine[a = p->unk36 + 0x40], divide_by_65536(p->unk34));
    p->unk10 = (120 - p->unk2C) * 256 - p->unk8 * 120 - p->unkA * 80;
    p->unk14 = (120 - p->unk2E) * 256 - p->unkC * 120 - p->unkE * 80;
}

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

void sub_08048B6C(void)
{
    struct Unk_03005310 *p = &gUnk_03005310;

    p->unk10 = 0;
    p->unk14 = 0;
    p->unk8 = 0x100;
    p->unkA = 0;
    p->unkC = 0;
    p->unkE = 0x100;
    p->unk30 = 0;
    p->unk32 = 0x100;
    p->unk34 = 0x100;
    p->unk36 = 0;
    p->unk2C = 0;
    p->unk2E = 0;
}

// Not called directly (hidden in the tail of sub_08048B6C). Guess: debug, B + D-pad scrolls BG1-3,
// RIGHT/LEFT step unk36 (0-255).
void sub_08048B94(void)
{
    if (KEYS_LO(gHeldKeys) & 2)
    {
        if (KEYS_LO(gHeldKeys) & 0x40)
        {
            gUnk_03005310.unk26 -= 4;
            gUnk_03005310.unk28 -= 4;
            gUnk_03005310.unk2A -= 4;
        }
        if (KEYS_LO(gHeldKeys) & 0x80)
        {
            gUnk_03005310.unk26 += 4;
            gUnk_03005310.unk28 += 4;
            gUnk_03005310.unk2A += 4;
        }
        if (KEYS_LO(gHeldKeys) & 0x20)
        {
            gUnk_03005310.unk1E -= 4;
            gUnk_03005310.unk20 -= 4;
            gUnk_03005310.unk22 -= 4;
        }
        if (KEYS_LO(gHeldKeys) & 0x10)
        {
            gUnk_03005310.unk1E += 4;
            gUnk_03005310.unk20 += 4;
            gUnk_03005310.unk22 += 4;
        }
    }
    if (KEYS_LO(gHeldKeys) & 0x10)
        gUnk_03005310.unk36 = ++gUnk_03005310.unk36 & 0xFF;
    if (KEYS_LO(gHeldKeys) & 0x20)
        gUnk_03005310.unk36 = (gUnk_03005310.unk36 + 0xFF) & 0xFF;
}

// Not called directly (hidden in the tail of sub_08048B6C).
void sub_08048C5C(u16 *src, u16 *dst, s32 h, s32 w, s32 maxh, s32 pitch, s32 add)
{
    s32 i, j;
    if (h > maxh)
        h = maxh;
    for (i = 0; i < h; i++)
    {
        for (j = 0; j < w; j++)
            *dst++ = *src++ + add;
        dst += pitch - w;
    }
}

// Copies a w x h tilemap (u16 entries, row pitch w) into a 64x64 BG screen (four 32x32 blocks), adding add.
void copy_tilemap_with_offset_08048CA4(const void *src, void *dst, s32 h, s32 w, s32 c, s32 d, s32 add)
{
    s32 i, j, n;
    s32 rows;

    rows = 32;
    if (h < 32)
        rows = h;
    for (i = 0; i < rows; i++)
    {
        n = 32;
        if (w < 32)
            n = w;
        for (j = 0; j < n; j++)
            ((u16 *)dst)[i * 32 + j] = ((const u16 *)src)[w * i + j] + add;
        if (w > 31)
        {
            for (j = 0; j < w - 32; j++)
                ((u16 *)dst)[0x400 + i * 32 + j] = ((const u16 *)src)[w * i + 32 + j] + add;
        }
    }
    if (h > 31)
    {
        for (i = 0; i < h - 32; i++)
        {
            n = 32;
            if (w < 32)
                n = w;
            for (j = 0; j < n; j++)
                ((u16 *)dst)[0x800 + i * 32 + j] = ((const u16 *)src)[(i + 32) * w + j] + add;
            if (w > 31)
            {
                for (j = 0; j < w - 32; j++)
                    ((u16 *)dst)[0xC00 + i * 32 + j] = ((const u16 *)src)[(i + 32) * w + 32 + j] + add;
            }
        }
    }
}

// Expands a (h/2) x (w/2) map of 2x2 metatile ids (src) into a 64x64 BG screen at tile (x, y) (four 32x32 blocks).
#define MAP ((u16 (*)[32])dst)
#define SRC(r, c) (((const u8 *)src) + (w / 2) * (r))[c]
void copy_tiles_to_bg_tilemap(const void *src, void *dst, s32 h, s32 w, s32 c, s32 d, s32 y, s32 x, s32 tile)
{
    s32 i, j;
    s32 rows, cols;

    rows = h + y > 31 ? 32 : h;
    for (i = 0; i < rows; i++)
    {
        cols = w + x > 31 ? 32 : w;
        for (j = 0; j < cols; j++)
            build_bg_tile_entry(&MAP[i + y][j + x], SRC(i / 2, j / 2), tile, i % 2, j % 2, y % 2, x % 2);
        if (w > 31)
        {
            for (j = 0; j < w - 32; j++)
                build_bg_tile_entry(&MAP[i + y + 32][j + x], SRC(i / 2, j / 2 + 16), tile, i % 2, j % 2, y % 2, x % 2);
        }
    }
    if (h > 31)
    {
        for (i = 0; i < h - 32; i++)
        {
            cols = 32;
            if (w < 32)
                cols = w;
            for (j = 0; j < cols; j++)
                build_bg_tile_entry(&MAP[i + y + 64][j + x], SRC(i / 2 + 16, j / 2), tile, i % 2, j % 2, y % 2, x % 2);
            if (w > 31)
            {
                for (j = 0; j < w - 32; j++)
                    build_bg_tile_entry(&MAP[i + y + 96][j + x], SRC(i / 2 + 16, j / 2 + 16), tile, i % 2, j % 2, y % 2, x % 2);
            }
        }
    }
}
#undef SRC
#undef MAP

// Not called directly (hidden in the tail of copy_tiles_to_bg_tilemap). Writes one 2x2 metatile.
void sub_0804908C(u16 *dst, s32 pal, s32 tile)
{
    s32 t = (pal + 1) * 4;
    s32 attr = (pal << 12) + tile;

    dst[0] = t | attr;
    dst[1] = (t + 1) | attr;
    dst[32] = (t + 2) | attr;
    dst[33] = (t + 3) | attr;
}

