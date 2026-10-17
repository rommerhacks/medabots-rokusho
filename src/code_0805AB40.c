#include "global.h"

INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805AB40);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", unpack_item_inventory_to_buffer);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", update_battle_medapart_icons);

void calc_fade_sprite_position(u16 *p)
{
    p[1] = 0x54;
    p[2] = (u8)(gUnk_03006F74->unkC % 5) * 16 + 0x1C;
}

INCLUDE_ASM("asm/nonmatching/code_0805AB40", shop_build_sell_list);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", load_battle_sprite_tiles);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", render_battle_medapart_list);

void sub_0805B3E4(s32 x, s32 y, s32 n)
{
    u16 *base = (u16 *)0x0600B000 + x; u16 *p = base + y * 32; u16 i;
    for (i = 0; i < n; i++)
        *p++ = 0;
}

void get_fade_progress_fifth(void)
{
    sub_0805A258((u8)(gUnk_03006F74->unkC / 5) + 1, 2, 3);
    sub_0805A258((gUnk_03006F74->unk10 - 1) / 5 + 1, 5, 3);
}

void swap_inventory_items(void)
{
    memswap(gItemInventory[gUnk_03006F74->unk13], gItemInventory[gUnk_03006F74->unkC], 2);
}

void sub_0805B470(struct Unk_03002C30 *attr)
{
    struct Unk_03006F74 *w = gUnk_03006F74;
    if (w->unk12)
    {
        if (w->unk13 >= w->unk11 && w->unk13 < w->unk11 + 5) attr->unk0 |= 0x4000; else attr->unk0 &= 0xBFFF;
    }
}

INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805B4B0);

u32 sub_0805B7A0(void)
{
    struct Unk_03006F74 **pw = &gUnk_03006F74;
    struct Unk_03006F74 *w = *pw;
    u8 old = w->unk17;
    u32 off = old * 4 + gUnk_030057E0.unkC32 * 40;
    const u8 *tbl = w->unk18 ? gUnk_080AF674 : gUnk_080AF5FC;
    if (*(u8 *)&gNewKeys & 0x20)
        w->unk17 = tbl[off];
    else if (*(u8 *)&gNewKeys & 0x10)
        w->unk17 = tbl[off + 1];
    else if (*(u8 *)&gNewKeys & 0x40)
        w->unk17 = tbl[off + 2];
    else if (*(u8 *)&gNewKeys & 0x80)
        w->unk17 = tbl[off + 3];
    else
        goto none;
    play_sound_effect(old != (*pw)->unk17 ? 2 : 6);
    return 1;
none:
    return 0;
}

INCLUDE_ASM("asm/nonmatching/code_0805AB40", update_battle_sprite_priority_flags);

void decompress_and_write_tilemap(const void *src, u32 bgcnt)
{
    s32 w, h, x, y, cols;
    u16 *data, *dst;

    LZ77UnCompWram(src, gDecompressBuffer);
    w = *(u32 *)gDecompressBuffer;
    h = *(u32 *)0x02030004;
    data = (u16 *)(gDecompressBuffer + 0x10);
    dst = (u16 *)(((bgcnt >> 8) & 0x1F) * 0x800 + VRAM);
    cols = (((bgcnt & 0xC000) >> 14) & 1) ? 64 : 32;
    for (y = 0; y < h; y++)
    {
        for (x = 0; x < cols; x++)
        {
            if (x < w)
                *dst = *data++;
            dst++;
        }
    }
}

INCLUDE_ASM("asm/nonmatching/code_0805AB40", tilemap_offset_tiles_and_palette);

void init_multiplayer_id(void)
{
    u8 buf[4];
    memcpy_optimized(buf, gUnk_080AF6EC, 4);
    gUnk_03000B90 = (*(vu32 *)0x04000128 << 26) >> 30;
}

void sub_0805B9EC(u16 keys)
{
    u16 *newKeys = &gNewKeys;
    u16 *prev = &gUnk_03006F74->unk78;
    *newKeys = keys & ~*prev;
    gReleasedKeys = *prev & ~keys;
    *prev = keys;
}

INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805BA20);

u16 sub_0805BA68(s16 x1, s16 y1, s16 x2, s16 y2)
{
    s32 dx = x2 - x1;
    s32 dy = y2 - y1;
    return Sqrt(dx * dx + dy * dy);
}

void dispatch_game_state_handler_0805BA94(void)
{
    gUnk_03005010.unk4 = gHeldKeys;
    gUnk_03005010.unk6 = 0;
    gUnk_03006F74 = (struct Unk_03006F74 *)&gUnk_03001800;
    if (gUnk_03005030 != 0 && (*(u32 *)&gUnk_03005010.unk19[3] & 0x00FFFF00))
    {
        gGameMode = 0;
        gGameState = 10;
        gGameSubState = 0x10;
    }
    else
    {
        gUnk_08483B00[gGameState]();
    }
}

s16 sub_0805BB10(s16 step)
{
    u16 a = step;
    s16 n;

    if (a > 0xA0)
        a = 0;
    REG_BLDCNT = 0x844;
    n = a;
    REG_BLDALPHA = gUnk_080AF6F0[n / 8] | 0x1000;
    REG_BLDY = 8;
    return n + 1;
}

INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805BB64);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805BBF8);

void sub_0805BC6C(void)
{
    s32 i, j;
    for (i = 0; i <= 2; i++)
    {
        u16 *p = (u16 *)(VRAM + (((REG_BG0CNT >> 8) & 0x1F) << 11)) + 0x167 + i * 96;
        for (j = 0; j < 16; j++)
        {
            *p = (*p & 0xFFF) | 0x8000;
            p++;
        }
    }
}

void sub_0805BCC0(u8 sel)
{
    u8 cur[3] = {gUnk_03001788, gUnk_03001360, gUnk_03000B94};
    s32 i, j, k;
    for (i = 0; i <= 2; i++)
    {
        for (j = 0; j <= 2; j++)
        {
            u16 *p = (u16 *)(VRAM + 0xE + (((REG_BG0CNT >> 8) & 0x1F) << 11) + (i * 3 + 11) * 64);
            u16 mask = gUnk_080AF740[i][j];
            for (k = 0; k < 16; k++)
            {
                if (mask & 0x8000)
                {
                    u16 v = *p & 0xFFF;
                    if (sel == i)
                        *p = v | (cur[i] == j ? 0xA000 : 0x8000);
                    else
                        *p = v | (cur[i] == j ? 0x9000 : 0x8000);
                }
                mask <<= 1;
                p++;
            }
        }
    }
}

void sub_0805BDC8(u8 a)
{
    u16 buf[32];
    s32 i;
    a = a > 15 ? a - 16 : 0;
    CpuSet((void *)0x0202FB00, buf, 0x04000010);
    for (i = 0; i < 16; i++)
    {
        u16 c = buf[i];
        u16 t = buf[i + 16];
        s32 r = c & 0x1F;
        s32 g = (c >> 5) & 0x1F;
        s32 b = (c >> 10) & 0x1F;
        s32 r2 = t & 0x1F;
        s32 g2 = (t >> 5) & 0x1F;
        s32 b2 = (t >> 10) & 0x1F;
        r = (r - r2) * a / 32 + r2;
        g = (g - g2) * a / 32 + g2;
        b = (b - b2) * a / 32 + b2;
        buf[i] = (b << 10) | (g << 5) | r;
    }
    CpuSet(buf, (void *)0x05000140, 0x04000008);
}

void sub_0805BEA0(u8 sel, u8 f)
{
    u16 buf[32];
    s32 i, j;
    for (j = 0; j <= 2; j++)
    {
        CpuSet((void *)(j * 0x40 + 0x0202FA00), buf, 0x04000010);
        if (j == sel)
        {
            for (i = 0; i < 16; i++)
            {
                u16 c = buf[i];
                u16 t = buf[i + 16];
                s32 r = c & 0x1F;
                s32 g = (c >> 5) & 0x1F;
                s32 b = (c >> 10) & 0x1F;
                s32 r2 = t & 0x1F;
                s32 g2 = (t >> 5) & 0x1F;
                s32 b2 = (t >> 10) & 0x1F;
                r = (r - r2) * f / 32 + r2;
                g = (g - g2) * f / 32 + g2;
                b = (b - b2) * f / 32 + b2;
                buf[i] = (b << 10) | (g << 5) | r;
            }
        }
        CpuSet(buf, (void *)(j * 0x40 + PLTT), 0x04000008);
    }
}

void sub_0805BF88(void)
{
    gUnk_08483B78[gGameSubState]();
    gBg2Scroll.x++;
    gBg2Scroll.y++;
    if (gFrameCounter & 1)
    {
        gBg3Scroll.x++;
        gBg3Scroll.y++;
    }
}

void sub_0805BFDC(void)
{
    u32 zero = 0;
    CpuFastSet(&zero, (void *)VRAM, 0x01006000);
    reset_bg_scroll();
    sub_08059D04();
    REG_DISPCNT = 0x60;
    init_blend_effect(gUnk_03006F74->unk50, 0x10, 0, -1, 0xC0);
    gGameSubState++;
}

void sub_0805C030(void)
{
    u32 size;
    u16 v;
    vu16 *bg0, *bg1, *bg2, *bg3;
    u8 one;

    bg0 = &REG_BG0CNT;
    one = 1;
    v = 0x1F04;
    *bg0 = v;
    bg1 = &REG_BG1CNT;
    v -= 0xFF;
    *bg1 = v;
    bg2 = &REG_BG2CNT;
    v = 0x3D06;
    *bg2 = v;
    bg3 = &REG_BG3CNT;
    v -= 0xFF;
    *bg3 = v;
    decompress_and_write_tilemap(gUnk_0878FBB4, *bg0);
    decompress_and_write_tilemap(gUnk_0878FD84, *bg1);
    decompress_and_write_tilemap(gUnk_0878FFC8, *bg2);
    decompress_and_write_tilemap(gUnk_08790128, *bg3);
    size = dma3_copy_or_decompress(gUnk_0878E5F4, gDecompressBuffer);
    CpuCopy16(gDecompressBuffer, (void *)0x06004000, size);
    gUnk_03006F74->unk36 = (size >> 5) - 1;
    lz_decompress_dispatch(gUnk_08784DA4, (void *)0x06010000);
    CpuFastSet(gUnk_0878E3F4, gPaletteBackupBg, 0x80);
    CpuFastSet(gUnk_0878E3F4, (void *)PLTT, 0x80);
    CpuFastSet(gUnk_084E2E58, gPaletteBackup, 0x80);
    CpuFastSet(gUnk_084E2E58, (void *)(PLTT + 0x200), 0x80);
    gUnk_03002C30[14].unk0 = 0x8000;
    gUnk_03002C30[14].unkB = one;
    gUnk_03002C30[14].unk1C = 2;
    gUnk_03002C30[14].unkA = 0;
    gUnk_03002C30[14].unk6 = 6;
    gUnk_03002C30[14].unk2 = 0x20;
    gUnk_03002C30[14].unk4 = 0x50;
    gUnk_03006F74->unk5 = 0;
    gGameSubState++;
}

void sub_0805C190(void)
{
    s32 ret, i, j;
    u16 *p;

    REG_DISPCNT |= 0x100;
    REG_DISPCNT |= 0x200;
    REG_DISPCNT |= 0x800;
    REG_DISPCNT |= 0x1000;
    gUnk_03001784.unk0_0 = 0;
    ret = load_save_with_retries();
    if (ret != 0)
    {
        if (ret < 0)
        {
            gGameState = 9;
            gGameSubState = 0;
            return;
        }
        for (i = 0; i <= 1; i++)
        {
            p = (u16 *)(VRAM + (((REG_BG0CNT >> 8) & 0x1F) << 11)) + 9 + (i + 1) * 32;
            for (j = 0; j < 12; j++)
                *p++ = 0;
        }
        gUnk_03006F74->unk5 = 1;
        gUnk_03006F74->unk4 = 1;
        gUnk_03001788 = 0;
        gUnk_03001360 = 0;
        gUnk_03000B94 = 0;
    }
    else
    {
        gUnk_03006F74->unk5 = ret;
        gUnk_03006F74->unk4 = ret;
        gUnk_03001784.unk0_0 = 1;
    }
    sub_0805BEA0(gUnk_03006F74->unk5, gFrameCounter & 0x1F);
    sub_0805BCC0(3);
    gGameSubState++;
}

void sub_0805C2C4(void)
{
    if (blend_fade_step_08065598(gUnk_03006F74->unk50))
    {
        gGameSubState++;
        gUnk_03006F74->unk3A = 0;
        gUnk_03006F74->unk3A = sub_0805BB10(0);
        REG_DISPCNT |= 0x400;
    }
}

void sub_0805C308(void)
{
    struct Unk_03006F74 *w;

    gUnk_03006F74->unk3A = sub_0805BB10(gUnk_03006F74->unk3A);
    sub_0805BEA0(gUnk_03006F74->unk5, gFrameCounter & 0x1F);
    if (KEYS_LO(gNewKeys) & 0x40)
    {
        play_sound_effect(2);
        w = gUnk_03006F74;
        if (w->unk5 == w->unk4)
            w->unk5 = 2;
        else
            w->unk5--;
    }
    if (KEYS_LO(gNewKeys) & 0x80)
    {
        play_sound_effect(2);
        w = gUnk_03006F74;
        if (w->unk5 == 2)
            w->unk5 = w->unk4;
        else
            w->unk5++;
    }
    if (KEYS_LO(gNewKeys) & 1)
    {
        play_sound_effect(4);
        if (gUnk_03006F74->unk5 == 2)
        {
            gUnk_03006F74->unk5 = 0;
            gUnk_03006F74->unk2 = 20;
            sub_0805BDC8(gFrameCounter & 0x1F);
            sub_0805BBF8(gUnk_03006F74->unk5);
            sub_0805BCC0(gUnk_03006F74->unk5);
            sub_0805BEA0(3, 0);
            gUnk_03002C30[14].unk4 = gUnk_03006F74->unk5 * 24 + 0x50;
            gUnk_03002C30[14].unk0 |= 0x4000;
            gGameSubState++;
        }
        else
        {
            gUnk_03006F74->unk48 = 45;
            gGameSubState = 6;
        }
    }
}

INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805C428);

void sub_0805C6AC(void)
{
    u8 *t = &gUnk_03006F74->unk48;
    if (*t)
    {
        u8 n = --*t;
        if (n)
            sub_0805BEA0(gUnk_03006F74->unk5, ((gUnk_03006F74->unk48 * 4) & 0x1F) <= 15 ? 0x20 : 0);
        else
        {
            copy_obj_palette_to_buffer();
            gUnk_03000440.unk84 = n;
        }
    }
    else if (!is_sound_playing_with_lock(4))
    {
        struct Unk_03000440 *b = &gUnk_03000440;
        if (b->unk84 <= 8)
        {
            s32 w = 31;
            s32 c = (w << 10) | (w << 5) | w;
            blend_obj_palettes_to_color_0803F684(c, b->unk84 * 4, 0xFFFF);
            blend_obj_palettes_to_color_0803F998(c, b->unk84 * 4, 0xFFFF);
            b->unk84++;
        }
        else
        {
            REG_DISPCNT &= 0xFDFF;
            switch (gUnk_03006F74->unk5)
            {
            case 0:
                gUnk_03001784.unk0_0 = 1;
                gGameSubState = 8;
                break;
            case 1:
                gUnk_03001784.unk0_1 = 0;
                gGameSubState = 7;
                break;
            }
        }
    }
}

void sub_0805C7A0(void)
{
    s8 i;

    play_song(0);
    play_sound_effect(0);
    eeprom_setup_timer_irq();
    for (i = 0; i <= 15; i++)
        gUnk_03002B74[i] = 0xFE;
    gGameState = 28;
    gGameSubState = 0;
}

void sub_0805C7E8(void)
{
    u32 zero = 0;

    play_song(0);
    play_sound_effect(0);
    gGameMode = 1;
    gGameState = 1;
    gGameSubState = zero;
    dispatch_by_index_0476e8(11);
}

void sub_0805C820(void)
{
    if (gUnk_03006F74->unk0 != 32)
    {
        gUnk_03006F74->unk0++;
        REG_BLDY = gUnk_03006F74->unk0 >> 1;
    }
    else
    {
        gGameState = 9;
        gGameSubState = 0;
    }
}

void sub_0805C85C(void)
{
    u32 zero = 0;

    CpuFastSet(&zero, (void *)VRAM, 0x01006000);
    clear_battle_sprite_slot(0, 0x80);
    reset_bg_scroll();
    REG_DISPCNT = 0x60;
    CpuFastSet(gUnk_084E2E38, &gPaletteBackup[0xF0], 8);
    lz_decompress_dispatch(gUnk_084C6A98, (void *)0x06017400);
    text_window_init(1, 2, 0);
    REG_DISPCNT |= 0x1000;
    gGameSubState++;
}

void load_rotation_grid_and_advance(void)
{
    u8 buf[0x54];
    memcpy_optimized(buf, gUnk_080AF755, 0x53);
    if (run_message(buf))
    {
        open_choice_menu(1, 0x16, 7);
        gGameSubState++;
    }
}

void sub_0805C90C(void)
{
    if (poll_choice_menu())
    {
        if (gUnk_03000440.unk2A == 0)
            gGameSubState++;
        else
            gGameSubState += 2;
    }
}

void sub_0805C940(void)
{
    if (game_state_execute_handler_a())
        dispatch_by_index_0476e8(10);
}

void advance_substate_with_fade(void)
{
    if (game_state_execute_handler_a())
    {
        gGameSubState++;
        init_blend_effect(gUnk_03006F74->unk50, 0, 0, 1, 0xC0);
    }
}

void fade_step_and_transition_to_mode3(void)
{
    if (blend_fade_step_08065598(gUnk_03006F74->unk50))
    {
        gGameState = 3;
        gGameSubState = 0;
    }
}

INCLUDE_ASM("asm/nonmatching/code_0805AB40", dispatch_rotation_menu_substate);

void update_fade_transition_and_counters(void)
{
    gUnk_08483BA0[gGameSubState]();
    if (gFrameCounter & 1)
    {
        gBg3Scroll.x++;
        gBg3Scroll.y++;
    }
}

void sub_0805CA28(u32 a)
{
    struct Unk_03006F74 *w = gUnk_03006F74;
    if (w->unk12)
    {
        if (w->unk13 >= w->unk11 && w->unk13 < w->unk11 + 5)
        {
            if (a & 1)
                gUnk_03002C30[84].unk0 &= 0xBFFF;
            else
                gUnk_03002C30[84].unk0 |= 0x4000;
        }
        else
            gUnk_03002C30[84].unk0 &= 0xBFFF;
    }
}

void sub_0805CA94(void)
{
    u32 zero = 0;
    CpuFastSet(&zero, gUnk_03006F74, 0x01000100);
    reset_bg_scroll();
    REG_DISPCNT = 0x160;
    gGameSubState++;
}

INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805CAD4);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805CC44);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805CD68);

void sub_0805CDF0(void)
{
    u8 id;
    struct Unk_03006F74 *w;
    sub_0805CA28(gFrameCounter);
    sub_08041C14(0x53, gFrameCounter, 0x54);
    w = gUnk_03006F74;
    if (w->unk10)
    {
        struct ItemListEntry *l = (struct ItemListEntry *)0x02040000;
        id = l[w->unkC].id;
    }
    else
        id = 0x3F;
    if (run_message(gUnk_084851CC[id]))
        gGameSubState++;
}

INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805CE4C);

void init_fade_sprite_and_start_fade(void)
{
    struct Unk_03006F74 **pw = &gUnk_03006F74;
    calc_fade_sprite_position(gUnk_03004130);
    gUnk_03004130[0] |= 0x4000;
    gUnk_03004130[1]++;
    gUnk_03004130[2]++;
    (*pw)->unk12 = 1;
    (*pw)->unk13 = (*pw)->unkC;
}

void sub_0805D378(void)
{
    if (game_state_execute_handler_a())
        gGameSubState++;
}

void sub_0805D394(void)
{
    struct Unk_03000440 *b = &gUnk_03000440;
    if (b->unk84 <= 8)
    {
        blend_obj_palettes_to_color_0803F684(0, b->unk84 * 4, 0x3FFF);
        blend_obj_palettes_to_color_0803F998(0, b->unk84 * 4, 0xFFFF);
        b->unk84++;
    }
    else
    {
        REG_DISPCNT &= 0xFDFF;
        REG_DISPCNT &= 0xFBFF;
        clear_battle_sprite_slot(0, 0x80);
        gGameMode = 0;
        gGameState = 1;
        gGameSubState = 0x10;
    }
}

void sub_0805D418(void)
{
    if (run_message(gUnk_08485788[8]))
        gGameSubState++;
}

void check_ab_press_play_confirm_sound(void)
{
    if (*(u8 *)&gNewKeys & 3)
    {
        play_sound_effect(2);
        sub_0803FB0C();
        gGameSubState = 4;
    }
}

void sub_0805D468(void)
{
    REG_BLDCNT = 0x2FF;
    gGameSubState++;
}

void sub_0805D488(void)
{
    struct Unk_03006F74 *w = gUnk_03006F74;
    if (w->unk0 != 8)
    {
        REG_BLDY = ++w->unk0 * 2;
    }
    else
    {
        REG_DISPCNT &= 0xFDFF;
        REG_DISPCNT &= 0xFBFF;
        clear_battle_sprite_slot(0, 0x80);
        gUnk_03006F74->unk6 = 1;
        gGameState = 10;
        gGameSubState = 0;
    }
}

void sub_0805D4F0(void)
{
    if (game_state_execute_handler_a())
        gGameSubState++;
}

void sub_0805D50C(void)
{
    struct Unk_03000440 *b = &gUnk_03000440;
    if (b->unk84 <= 8)
    {
        blend_obj_palettes_to_color_0803F684(0, b->unk84 * 4, 0xFFFF);
        blend_obj_palettes_to_color_0803F998(0, b->unk84 * 4, 0xFFFF);
        b->unk84++;
    }
    else
    {
        u32 zero;
        REG_DISPCNT &= 0xFDFF;
        zero = 0;
        CpuFastSet(&zero, (void *)VRAM, 0x01006000);
        dispatch_by_index_0476e8(4);
    }
}

void sub_0805D57C(u16 a)
{
    gUnk_03002C30[0].unk6 = gUnk_080AF7E0[a & 3];
}

void save_screen_update(void)
{
    gSaveScreenStates[gGameSubState]();
    if (gFrameCounter & 1)
    {
        gBg3Scroll.x++;
        gBg3Scroll.y++;
    }
    sub_0805D57C(gFrameCounter >> 3);
}

void sub_0805D5E8(void)
{
    u32 zero = 0;
    CpuFastSet(&zero, gUnk_03006F74, 0x01000100);
    reset_bg_scroll();
    REG_DISPCNT = 0x160;
    gGameSubState++;
}

INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805D628);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805D6F8);

void sub_0805D8AC(void)
{
    if (gUnk_03000440.unk84 <= 8)
    {
        blend_obj_palettes_to_color_0803F684(0, 32 - gUnk_03000440.unk84 * 4, 0x3FFF);
        blend_obj_palettes_to_color_0803F998(0, 32 - gUnk_03000440.unk84 * 4, 0xFFFF);
        if (++gUnk_03000440.unk84 == 1)
        {
            REG_DISPCNT |= 0x200;
            REG_DISPCNT |= 0x400;
            REG_DISPCNT |= 0x800;
            REG_DISPCNT |= 0x1000;
        }
    }
    else
    {
        text_window_init(1, 2, 0);
        gGameSubState++;
    }
}

void sub_0805D948(void)
{
    if (run_message(gUnk_08485788[9]))
        gGameSubState++;
}

void sub_0805D96C(void)
{
    if (poll_choice_menu())
    {
        sub_0803FB0C();
        if (gUnk_03000440.unk2A == 0)
            gGameSubState = (*(u8 *)&gUnk_03001784 & 1) ? 13 : 6;
        else
            gGameSubState = 9;
    }
}

void sub_0805D9B8(void)
{
    if (run_message(gUnk_08485BD8[18]))
    {
        open_choice_menu(1, 0x16, 7);
        gGameSubState++;
    }
}

void sub_0805D9E4(void)
{
    if (poll_choice_menu())
    {
        sub_0803FB0C();
        if (gUnk_03000440.unk2A == 0)
            gGameSubState = 6;
        else
            gGameSubState = 9;
    }
}

void sub_0805DA1C(void)
{
    if (run_message(gUnk_08485788[10]))
    {
        play_song(0);
        play_sound_effect(0);
        eeprom_setup_timer_irq();
        gUnk_03006F74->unk2 = 0;
        gGameSubState++;
    }
}

void attempt_save_and_transition(void)
{
    u8 t = gUnk_03006F74->unk2++;
    u16 err = 0;
    s8 i;

    if (t > 29 && !is_sound_playing_with_lock(4))
    {
        for (i = 0; i <= 3; i++)
        {
            err = save_dispatch(0);
            if (err == 0)
                break;
        }
        play_song(6);
        if (err == 0)
        {
            sub_0803FB0C();
            gUnk_03006F74->unk2 = err;
            gGameSubState++;
        }
        else
        {
            sub_0803FB0C();
            gUnk_03006F74->unk2 = 0;
            gGameSubState = 12;
        }
    }
}

void sub_0805DAE4(void)
{
    u8 t = gUnk_03006F74->unk2++;
    if (run_message(gUnk_08485788[11]) && t > 60)
        gGameSubState++;
}

void sub_0805DB20(void)
{
    sub_0803FB0C();
    copy_obj_palette_to_buffer();
    gUnk_03000440.unk84 = 0;
    gGameSubState++;
}

void sub_0805DB48(void)
{
    if (game_state_execute_handler_a())
        gGameSubState++;
}

void sub_0805DB64(void)
{
    if (gUnk_03000440.unk84 <= 8)
    {
        blend_obj_palettes_to_color_0803F684(0, gUnk_03000440.unk84 * 4, 0x3FFF);
        blend_obj_palettes_to_color_0803F998(0, gUnk_03000440.unk84 * 4, 0xFFFF);
        gUnk_03000440.unk84++;
    }
    else
    {
        REG_DISPCNT &= 0xFDFF;
        REG_DISPCNT &= 0xFBFF;
        clear_battle_sprite_slot(0, 0x80);
        gGameMode = 0;
        gGameState = 1;
        gGameSubState = 16;
    }
}

void sub_0805DBE8(void)
{
    u8 t = gUnk_03006F74->unk2++;
    if (run_message(gUnk_08485788[12]) && t > 60)
        gGameSubState = 9;
}

void init_linking_mode(void)
{
    gUnk_03005030 = 0;
    serial_multiplayer_init();
    VBlankIntrWait();
    REG_BLDCNT = 0xFF;
    REG_BLDY = 0x10;
    REG_SOUNDCNT_X = 0;
    gGameMode = 3;
    gGameState = 0;
    gGameSubState = 0;
    REG_DMA0CNT_H = 0;
    VBlankIntrWait();
    sound_init(&gUnk_03002430);
    VBlankIntrWait();
}

INCLUDE_ASM("asm/nonmatching/code_0805AB40", save_dispatch);

u16 eeprom_setup_timer_irq(void)
{
    return sub_0807C7A8(2, &gIntrTable[11]);
}

INCLUDE_ASM("asm/nonmatching/code_0805AB40", load_save_with_retries);

void load_save_data(struct SaveData *save)
{
    s32 i;
    struct Unk_03000BE0 *medal;

    gUnk_03002B70 = save->unk10;
    medal = save->medals;
    for (i = 0; i < 30; i++)
    {
        memcpy_optimized(&gUnk_03000BE0[i], medal, sizeof(struct Unk_03000BE0));
        medal++;
    }
    for (i = 0; i < 0x3C0; i++)
        gMedapartInventory[i] = save->medaparts[i];
    for (i = 0; i < 9; i++)
        gUnk_030017A0[i] = save->team[i];
    CpuSet(save->items, gItemInventory, 0x40);
    CpuSet(save->field, &gUnk_030057E0, 0x660);
    gUnk_03001788 = save->flags & 3;
    gUnk_03001360 = (save->flags >> 2) & 1;
    gUnk_03000B94 = (save->flags >> 3) & 3;
    gUnk_03001784.unk0_1 = (save->flags >> 5) & 1;
}

void serialize_save_data(struct SaveData *save)
{
    s32 i;
    u16 sum;
    u8 *p;
    struct Unk_03000BE0 *medal;

    for (i = 0; i < 16; i++)
        save->magic[i] = gSaveMagic[i];
    save->unk10 = gUnk_03002B70;
    medal = save->medals;
    for (i = 0; i < 30; i++)
    {
        memcpy_optimized(medal, &gUnk_03000BE0[i], sizeof(struct Unk_03000BE0));
        medal++;
    }
    for (i = 0; i < 0x3C0; i++)
        save->medaparts[i] = gMedapartInventory[i];
    for (i = 0; i < 9; i++)
        save->team[i] = gUnk_030017A0[i];
    CpuSet(gItemInventory, save->items, 0x40);
    CpuSet(&gUnk_030057E0, save->field, 0x660);
    save->flags = gUnk_03001788 | (gUnk_03001360 << 2) | (gUnk_03000B94 << 3) | (gUnk_03001784.unk0_1 << 5);
    save->checksum = 0;
    sum = 0;
    p = (u8 *)save;
    for (i = 0; i < sizeof(struct SaveData); i++)
        sum += *p++;
    save->checksum = sum;
}

s32 validate_save_data(struct SaveData *save)
{
    u16 buf[4];
    u16 *p;
    s32 i;
    s32 n;
    u8 *b;
    u16 sum;
    u32 tmp; // the empty-name flag, then the stored checksum (one variable in the original)

    n = 920;
    p = (u16 *)save;
    for (i = 0; i < n; i++)
    {
        ReadEepromDword(i, buf);
        *p++ = buf[0];
        *p++ = buf[1];
        *p++ = buf[2];
        *p++ = buf[3];
    }
    for (i = 0; i < 16; i++)
    {
        if (gSaveMagic[i] != save->magic[i])
            return 1;
    }
    tmp = TRUE;
    for (i = 0; i < 16; i++)
    {
        if (save->unk10.unk4[i] == 0xFE)
            break;
        if (save->unk10.unk4[i] != 0)
        {
            tmp = FALSE;
            break;
        }
    }
    if (tmp)
        return -1;
    if (save->unk10.money > 99999)
        return -1;
    if (save->unk10.unk14[0] > 9999)
        return -1;
    if (save->unk10.unk14[0] < save->unk10.unk14[1])
        return -1;
    if (save->unk10.unk18 > 0x014996FF)
        return -1;
    if ((save->flags & 3) > 2)
        return -1;
    if (((save->flags >> 3) & 3) > 2)
        return -1;
    tmp = save->checksum;
    save->checksum = 0;
    sum = 0;
    b = (u8 *)save;
    for (i = 0; i < sizeof(struct SaveData); i++)
        sum += *b++;
    if (sum != tmp)
        return -1;
    return 0;
}

s32 write_save_to_eeprom(u16 *src, u32 force)
{
    u16 buf[4];
    s32 i;
    s32 n;
    u16 changed;
    u32 j;

    n = 920;
    if ((u8)force)
    {
        for (i = 0; i < n; i++)
        {
            buf[0] = *src++;
            buf[1] = *src++;
            buf[2] = *src++;
            buf[3] = *src++;
            ProgramEepromDwordEx(i, buf);
        }
    }
    else
    {
        for (i = 0; i < n; i++)
        {
            changed = ReadEepromDword(i, buf);
            for (j = 0; j < 4; j++)
            {
                if (buf[j] != *src)
                {
                    buf[j] = *src;
                    changed = 1;
                }
                src++;
            }
            if (changed)
                ProgramEepromDwordEx(i, buf);
        }
    }
    return 0;
}

void sub_0805E170(u16 a)
{
    gUnk_03002C30[20].unk6 = gUnk_080AF808[a & 3];
}

s32 calc_text_pixel_width(const u8 *s)
{
    s32 w = 0;
    s32 i;
    for (i = 0; i < 10 && *s != 0xFE; i++)
        w += gUnk_083B4C88[*s++][0];
    return w;
}

INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805E1CC);

void sub_0805E29C(void)
{
    gUnk_08483C44[gGameSubState]();
    if (gFrameCounter & 1)
    {
        gBg3Scroll.x++;
        gBg3Scroll.y++;
    }
    sub_0805E170(gFrameCounter >> 3);
}

void sub_0805E2E8(void)
{
    clear_battle_sprite_slot(0, 0x80);
    reset_bg_scroll();
    REG_DISPCNT = 0x60;
    gGameSubState++;
}

INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805E310);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805E5B0);

void sub_0805E878(void)
{
    struct Unk_03000440 *b = &gUnk_03000440;
    if (b->unk84 <= 8)
    {
        blend_obj_palettes_to_color_0803F684(0, 0x20 - b->unk84 * 4, 0xFFFF);
        blend_obj_palettes_to_color_0803F998(0, 0x20 - b->unk84 * 4, 0xFFFF);
        b->unk84++;
    }
    else
    {
        gUnk_03006F74->unk2 = 0;
        gUnk_03006F74->unk6 = 0;
        gGameSubState++;
    }
}

INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805E8DC);
