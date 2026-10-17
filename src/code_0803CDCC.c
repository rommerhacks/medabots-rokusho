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

void battle_sprite_rotate_angles(u32 dir, u32 delta)
{
    u32 i;
    for (i = 0; i <= 0x13; i++)
    {
        if (gUnk_03002C30[i + 10].unk29 != 0)
        {
            if (dir)
                gUnk_03002C30[i + 10].unk2 = (gUnk_03002C30[i + 10].unk2 - delta) & 0x1FF;
            else
                gUnk_03002C30[i + 10].unk2 = (gUnk_03002C30[i + 10].unk2 + delta) & 0x1FF;
        }
    }
}

INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803D538);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803D5A0);

void sub_0803D5E0(void)
{
    if (sub_0803E79C())
    {
        gUnk_03000440.unk86 = 0;
        gGameSubState++;
    }
}

void sub_0803D608(void)
{
    if (gUnk_03000440.unk86 == 8)
    {
        gUnk_03000440.unk86 = 0;
        gGameSubState++;
    }
    else
    {
        gUnk_03000440.unk86++;
    }
}

void sub_0803D634(void)
{
    if (gUnk_03000B90 == 0)
    {
        gUnk_03000440.unk8D = gFrameCounter;
        gUnk_03005010.unk6 = gUnk_03000440.unk8D + 0x8000;
    }
    gGameSubState++;
}

void sub_0803D674(void)
{
    if (gUnk_03000B90 != 0)
    {
        u16 v = gUnk_03005010.unk8[0][1];
        if (!(v & 0x8000))
            return;
        gUnk_03000440.unk8D = v;
    }
    gGameSubState++;
}

void sub_0803D6AC(void)
{
    gUnk_03000440.unk84 = 0;
    gUnk_03001800.unk51 = 0;
    gUnk_03001800.unk52 = 0;
    gUnk_03001800.unk53 = 0;
    gUnk_03001800.unk54 = 0;
    gUnk_03001800.unk1A6 = 0;
    gUnk_03001800.unk1A8 = 0;
    gUnk_03001800.unk1AA = 0;
    gUnk_03001800.unk1AC = 0;
    gUnk_03001800.unk1AF = 0;
    gUnk_03001800.unk1B0 = 1;
    gUnk_03000440.unk86 = 0;
    gGameSubState = 0x50;
}

void sub_0803D71C(void)
{
    gUnk_03001800.unk38 = gUnk_083AFC78[rng_next_080424B8() & 0x1F];
    gGameSubState++;
}

INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803D74C);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803D928);

void sub_0803D980(void)
{
    update_scroll_movement_a();
    text_window_init(1, 0, 0);
    gGameSubState++;
}

void sub_0803D9A0(void)
{
    update_scroll_movement_a();
    if (run_message(gUnk_083C2BBC[1]))
        gGameSubState++;
}

void sub_0803D9C8(void)
{
    update_scroll_movement_a();
    copy_obj_palette_to_buffer();
    gUnk_03000440.unk84 = 0;
    gGameSubState++;
}

INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803D9F0);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803DA40);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803DA90);

void sub_0803DAEC(void)
{
    sub_0803F624(&gUnk_03000440.unk50, 0x14, 0);
    gUnk_03000440.unk50 = 1;
    gGameState = 3;
    gGameSubState = 0;
}

void sub_0803DB1C(void)
{
    if (gUnk_03000440.unk9C == 1)
        play_song(14);
    else
        play_song(15);
    gGameSubState++;
}

INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803DB4C);

void sub_0803DB94(void)
{
    update_scroll_movement_a();
    if (game_state_execute_handler_b())
    {
        sub_0803FB0C();
        gGameSubState++;
    }
}

void sub_0803DBB8(void)
{
    update_scroll_movement_a();
    if (run_message(gUnk_083CF3B0[1]))
        gGameSubState++;
}

void sub_0803DBE0(void)
{
    update_scroll_movement_a();
    if (sub_0803E79C())
    {
        gUnk_03000440.unk86 = 0;
        gGameSubState++;
    }
}

void sub_0803DC0C(void)
{
    update_scroll_movement_a();
    if (gUnk_03000440.unk86 == 8)
    {
        gUnk_03000440.unk86 = 0;
        gGameSubState++;
    }
    else
    {
        gUnk_03000440.unk86++;
    }
}

void sub_0803DC3C(void)
{
    update_scroll_movement_a();
    sound_stop_all_with_fade_guard(8);
    gGameSubState++;
}

void sub_0803DC58(void)
{
    update_scroll_movement_a();
    if (gUnk_03000440.unk138 == 0)
        gGameSubState++;
    else
        gGameSubState = 0x30;
}

INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803DC8C);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803DCDC);

void sub_0803DE70(void)
{
    sub_0803E894();
    if (update_blend_effect())
        gGameSubState++;
}

void sub_0803DE90(void)
{
    sub_0803E894();
    text_window_init(1, 0, 0);
    gGameSubState++;
}

INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803DEB0);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803DEF0);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803DF98);

void sub_0803E018(void)
{
    sub_0803E894();
    sub_0803EB30();
    sub_0803EB5C();
    sub_0803EC04();
    gGameSubState++;
}

INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803E03C);

void sub_0803E098(void)
{
    sub_0803E894();
    if (sub_0803EC98())
    {
        sub_0803ECF0();
        sub_0803ED10();
        gGameSubState++;
    }
}

void sub_0803E0C0(void)
{
    sub_0803E894();
    if (sub_0803ED28())
    {
        play_sound_effect(0x2A);
        gUnk_03000440.unk86 = 0;
        gGameSubState++;
    }
}

void sub_0803E0F0(void)
{
    sub_0803E894();
    draw_battle_bg1_tilemap_row();
    if (gUnk_03000440.unk86 == 0x78)
        gGameSubState++;
    else
        gUnk_03000440.unk86++;
}

INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803E120);

void sub_0803E170(void)
{
    sub_0803E894();
    draw_battle_bg1_tilemap_row();
    gUnk_03000440.unk86++;
    text_window_init(1, 0, 0);
    gGameSubState++;
}

INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803E1A4);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803E1FC);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803E234);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803E270);

void sub_0803E2AC(void)
{
    sub_0803E894();
    draw_battle_bg1_tilemap_row();
    gUnk_03000440.unk86++;
    sound_stop_all_with_fade_guard(8);
    gGameSubState++;
}

INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803E2DC);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803E314);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803E374);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803E434);

void sub_0803E48C(void)
{
    sub_0803E894();
    draw_battle_bg1_tilemap_row();
    gUnk_03000440.unk86++;
    gGameSubState = 0x3E;
}

void sub_0803E4B4(void)
{
    sound_stop_all_with_fade_guard(8);
    set_blend_effect_mode(6, 0x3F, 0x20);
    gGameSubState++;
}

void sub_0803E4D8(void)
{
    if (update_blend_effect())
        gGameSubState++;
}

INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803E4F4);

void sub_0803E618(void)
{
    text_window_init(1, 0, 0);
    gGameSubState++;
}

INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803E634);

void sub_0803E674(void)
{
    soft_reset_to_title();
}

INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803E680);

void sub_0803E768(void)
{
    gGameSubState = 6;
}

void sub_0803E774(void)
{
    gGameSubState = 5;
}

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

void render_battle_text_label(void)
{
    render_text_sprites_08040EE4(gUnk_0300198A, 10, 0x12, 3, 10, 13, 0, 1, 0, -4);
}

INCLUDE_ASM("asm/nonmatching/code_0803CDCC", load_battle_anim_data_38);

void draw_battle_ui_tiles_from_rom(void)
{
    u32 i;
    for (i = 0; i <= 2; i++)
        draw_tilemap_with_offset(0xFF, gUnk_083ACEEA[i][0], gUnk_083ACEEA[i][1], REG_BG0CNT, 0x8300);
}

void load_battle_script_entry_a(void)
{
    memcpy_bytes_0803F63C(gUnk_083C3B04[gUnk_03001800.unk38], gUnk_03001800.unk39, 8);
}

void sub_0803E894(void)
{
    if (gFrameCounter & 1)
    {
        gBg3Scroll.x++;
        gBg3Scroll.y++;
    }
}

void sub_0803E8B8(void)
{
    u32 r = rng_next_080424B8() & 0xF;
    u32 i;
    for (i = 0; i <= 5; i++)
        gUnk_0300199A[i] = gUnk_083AFC98[r][i];
}

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

void fill_bg1_tilemap_column(void)
{
    u32 i;
    for (i = 0; i <= 11; i++)
        fill_tilemap_rect_08042698(1, 1, i + 7, 0x12, REG_BG1CNT, 0x53D0);
}

void update_battle_gauge_display(void)
{
    if (gUnk_03000440.unk86 & 4)
        draw_battle_gauge_bar();
    else
        fill_bg1_tilemap_column();
}

void sub_0803EB30(void)
{
    gUnk_03001800.unk1A1 = 0x68 - gUnk_03001800.unk1A0;
    if (gUnk_03001800.unk1A1 <= 12)
        gUnk_03001800.unk1A1 = 12;
}

void sub_0803EB5C(void)
{
    gUnk_03001800.unk1A2 = gUnk_03001800.unk1A0 >> 4;
    switch (gUnk_03001800.unk1A2)
    {
    case 0:
        gUnk_03001800.unk1A2 = 5;
        break;
    case 1:
        gUnk_03001800.unk1A2 = 4;
        break;
    case 2:
        gUnk_03001800.unk1A2 = 3;
        break;
    case 3:
        gUnk_03001800.unk1A2 = 2;
        break;
    case 4:
        gUnk_03001800.unk1A2 = 1;
        break;
    case 5:
        gUnk_03001800.unk1A2 = 0;
        break;
    case 6:
        gUnk_03001800.unk1A2 = 0;
        break;
    }
    gUnk_03001800.unk1A3 = gUnk_03001800.unk1A2 * 16 + 0x18;
}

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

u32 sub_0803EC98(void)
{
    sub_0803EC50();
    if (gUnk_03002C30[2].unk4 <= gUnk_03001800.unk1A1)
    {
        gUnk_03002C30[2].unk4 = gUnk_03001800.unk1A1;
        return 1;
    }
    gUnk_03002C30[2].unk27++;
    if (!(gUnk_03002C30[2].unk27 & 3) && gUnk_03002C30[2].unk24 != 1)
        gUnk_03002C30[2].unk24--;
    return 0;
}

void sub_0803ECF0(void)
{
    if (gUnk_03001800.unk1A0 == 0x60)
        play_sound_effect(7);
}

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

void vram_fill_tilemap_rect(u32 w, u32 h, u32 x, u32 y, u32 bgcnt, u16 value)
{
    u16 *base = (u16 *)(VRAM + (((bgcnt >> 8) & 0x1F) << 11)) + x + y * 32;
    u32 i, j;
    for (i = 0; i < h; i++)
    {
        u16 *d = base + i * 32;
        for (j = 0; j < w; j++)
            *d++ = value;
    }
}

void tilemap_fill_rect(u32 w, u32 h, u32 x, u32 y, u32 bgcnt, u16 tile)
{
    u16 *dst;
    u16 *d;
    u32 i, j;
    u32 cols, rows;

    if (x < 32)
    {
        if (y < 32)
        {
            dst = (u16 *)(VRAM + (((bgcnt >> 8) & 0x1F) << 11)) + x + y * 32;
            rows = 32 - y;
            for (i = 0; i < h; i++)
            {
                cols = 32 - x;
                d = dst + i * 32;
                for (j = 0; j < w; j++)
                {
                    *d++ = tile;
                    if (--cols == 0)
                        d += 0x3E0;
                }
                if (--rows == 0)
                    dst += 0x400;
            }
        }
        else
        {
            y -= 32;
            dst = (u16 *)(VRAM + (((bgcnt >> 8) & 0x1F) << 11)) + x + y * 32 + 0x800;
            for (i = 0; i < h; i++)
            {
                cols = 32 - x;
                d = dst + i * 32;
                for (j = 0; j < w; j++)
                {
                    *d++ = tile;
                    if (--cols == 0)
                        d += 0x3E0;
                }
            }
        }
    }
    else
    {
        if (y < 32)
        {
            dst = (u16 *)(VRAM + (((bgcnt >> 8) & 0x1F) << 11)) + (x - 32) + y * 32 + 0x400;
            rows = 32 - y;
            for (i = 0; i < h; i++)
            {
                d = dst + i * 32;
                for (j = 0; j < w; j++)
                    *d++ = tile;
                if (--rows == 0)
                    dst += 0x400;
            }
        }
        else
        {
            y -= 32;
            dst = (u16 *)(VRAM + (((bgcnt >> 8) & 0x1F) << 11)) + (x - 32) + y * 32 + 0xC00;
            for (i = 0; i < h; i++)
            {
                d = dst + i * 32;
                for (j = 0; j < w; j++)
                    *d++ = tile;
            }
        }
    }
}

void write_tilemap_rect(u32 w, u32 h, u32 x, u32 y, const void *src, u32 bgcnt, u32 base)
{
    u16 *dst;
    const u16 *s;
    u32 i, j;
    gTilemapBaseEntry = base;
    dst = (u16 *)(VRAM + (((bgcnt >> 8) & 0x1F) << 11)) + x + y * 32;
    s = src;
    for (i = 0; i < h; i++)
    {
        u16 *d = dst + i * 32;
        for (j = 0; j < w; j++)
            *d++ = *s++ + gTilemapBaseEntry;
    }
}

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

void blend_obj_palettes_to_color_0803F788(u16 color, u32 amount, u16 mask)
{
    u32 i, j;
    u32 inv;
    u16 bit = 1;
    if (amount > 32)
        amount = 32;
    inv = 32 - amount;
    for (i = 0; i < 16; i++)
    {
        if (mask & bit)
        {
            for (j = 0; j < 16; j++)
            {
                u16 *dst = &gPaletteBufferBg[i * 16 + j];
                u16 *src = &gPaletteBackupBg[i * 16 + j];
                *dst = (((*src & 0x1F) * inv + amount * (color & 0x1F)) >> 5)
                    | ((((*src & 0x3E0) * inv + amount * (color & 0x3E0)) >> 5) & 0x3E0)
                    | ((((*src & 0x7C00) * inv + amount * (color & 0x7C00)) >> 5) & 0x7C00);
            }
        }
        else
        {
            for (j = 0; j < 16; j++)
                gPaletteBufferBg[i * 16 + j] = gPaletteBackupBg[i * 16 + j];
        }
        bit <<= 1;
    }
    gVBlankOnceCallback = dma_obj_palette_to_hardware;
}

void palette_blend_to_color_0803F890(u16 color, u32 amount, u16 mask)
{
    u32 i, j;
    u32 inv;
    u16 bit = 1;
    if (amount > 32)
        amount = 32;
    inv = 32 - amount;
    for (i = 0; i < 16; i++)
    {
        if (mask & bit)
        {
            for (j = 0; j < 16; j++)
            {
                u16 *dst = &gPaletteBuffer[i * 16 + j];
                u16 *src = &gPaletteBackup[i * 16 + j];
                *dst = (((*src & 0x1F) * inv + amount * (color & 0x1F)) >> 5)
                    | ((((*src & 0x3E0) * inv + amount * (color & 0x3E0)) >> 5) & 0x3E0)
                    | ((((*src & 0x7C00) * inv + amount * (color & 0x7C00)) >> 5) & 0x7C00);
            }
        }
        else
        {
            for (j = 0; j < 16; j++)
                gPaletteBuffer[i * 16 + j] = gPaletteBackup[i * 16 + j];
        }
        bit <<= 1;
    }
    gVBlankOnceCallback = dma_obj_palette_to_hardware;
}

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

u32 run_message(const void *msg)
{
    gUnk_03000440.unk8 = msg;
    gUnk_083B279C[gUnk_03000440.unk4]();
    if (gUnk_03000440.unk4 > 7)
        return 1;
    return 0;
}

void game_state_advance_substate(void)
{
    u8 v = gUnk_03000440.unk0;
    if (v == 0)
    {
        copy_obj_palette_to_buffer();
        gUnk_03000440.unk1C = v;
        gUnk_03000440.unk4++;
    }
    else
    {
        gUnk_03000440.unk4 = 2;
    }
}

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

void sub_080408D0(void)
{
    gUnk_083B27C0[gUnk_03000440.unk8[gUnk_03000440.unkC + 1]]();
}

void sub_080408F4(void)
{
    gUnk_083B27D4[gUnk_03000440.unk1B]();
}

void sub_08040914(void)
{
    gUnk_083B27EC[gUnk_03000440.unk1B]();
}

void sub_08040934(void)
{
    gUnk_083B2804[gUnk_03000440.unk1B]();
}

void sub_08040954(void)
{
    gUnk_083B2808[gUnk_03000440.unk1B]();
}

void sub_08040974(void)
{
    gUnk_083B2810[gUnk_03000440.unk1B]();
}

INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_08040994);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_08040A00);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_08040A40);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_08040B0C);

void sub_08040B5C(void)
{
    u32 i;
    for (i = 0; i <= 0x33; i++)
        CpuCopy16(gUnk_084C01C8, (void *)(VRAM + 0x280 + i * 0x40), 0x40);
    gUnk_03000440.unk1B++;
}

void init_battle_sprite_entry_08040B90(const void *cmds, u8 slot)
{
    const u8 *p;
    u8 i;
    gUnk_03002C30[slot].unk20 = 0;
    gUnk_03002C30[slot].unk21 = 0;
    gUnk_03002C30[slot].unk22 = 0;
    i = 0;
loop:
    p = (const u8 *)cmds + i;
    if (*p > 0xFA)
    {
        i += 3;
        goto loop;
    }
    gUnk_03002C30[slot].unk6 = (p[1] << 8) + p[2];
}

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
