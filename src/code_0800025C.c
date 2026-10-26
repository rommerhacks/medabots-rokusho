#include "global.h"

void AgbMain(void)
{
    s32 i;
    u8 prevConnected;

    REG_WAITCNT = 0x4014;
    hw_reset_init();
    irq_init();
    REG_DISPCNT = 0x60;
    gGameMode = 3;
    gGameState = 0;
    gGameSubState = 0;
    serial_link_init();
    sound_init(&gUnk_03002430);
    *(u16 *)&gUnk_03001784 = 0;
    gUnk_03005030 = 0;
    gUnk_03002410 = 0;
    gUnk_03005010.unk1E = 0;
    gUnk_03005010.unk1D = 0;
    for (;;)
    {
        VBlankIntrWait();
        gUnk_03002410 = 0;
        read_keys();
        gFrameCounter++;
        if (gUnk_03000588 && gUnk_03002B70.unk18 < 0x014996FF)
            gUnk_03002B70.unk18++;
        prevConnected = gSioLink.connected;
        gUnk_03005010.unk1D = 0;
        gUnk_03005010.unk1E = 0;
        gUnk_03005010.unk0 = serial_link_init_and_status((u32 *)gUnk_03005010.unk8);
        for (i = 0; i < 4; i++)
        {
            if (gUnk_03005010.unk0 & (1 << i))
            {
                gUnk_03005010.unk19[i] = 0;
                if (!((prevConnected >> i) & 1))
                {
                    gSioLink.connected |= 1 << i;
                    gUnk_03005010.unk1D |= 0xFF;
                }
            }
            else if (gUnk_03005010.unk19[i] > 10)
            {
                if ((gSioLink.connected >> i) & 1)
                    gUnk_03005010.unk1E |= 0xFF;
                gSioLink.connected &= ~(1 << i);
                gUnk_03005010.unk19[i] = 0;
            }
            else
            {
                gUnk_03005010.unk19[i]++;
            }
        }
        if (check_soft_reset())
        {
            VBlankIntrWait();
            sound_init(&gUnk_03002430);
            VBlankIntrWait();
        }
        else if (gUnk_03005030)
        {
            u32 other = 0;

            if (gUnk_03000B90 == 0)
                other = 1;
            if (gUnk_03005010.unk8[other][0] == 0xFFFF && gUnk_03005010.unk8[other][1] == gUnk_03005010.unk8[other][0])
            {
                gGameMode = 0;
                gGameState = 10;
                gGameSubState = 16;
            }
        }
        gUnk_083ABE18[gGameMode]();
        check_flag_and_fast_copy();
        serial_prepare_send_packet(&gUnk_03005010.unk4);
    }
}

void irq_init(void)
{
    CpuSet(gIntrTableTemplate, gIntrTable, 0x0400000E);
    CpuSet(irq_dispatch_arm, gIntrMain, 0x04000200);
    INTR_VECTOR = gIntrMain;
    gVBlankOnceCallback = nullsub_08000840;
    gVBlankCallback = nullsub_08000840;
    gHBlankCallback = nullsub_08000840;
    REG_IE = 0x2601;
    REG_DISPSTAT = 8;
    REG_IME = 1;
    sub_0807C740(0x40);
    eeprom_setup_timer_irq();
}

void hw_reset_init(void)
{
    u32 a, b, c;

    REG_IME = 0;
    a = 0;
    CpuFastSet(&a, (void *)EWRAM, 0x01010000);
    b = 0;
    CpuFastSet(&b, (void *)IWRAM, 0x01001F40);
    clear_oam();
    c = 0;
    CpuFastSet(&c, (void *)PLTT, 0x01000100);
    *(u16 *)PLTT = 0x7FFF;
}

void clear_oam(void)
{
    vu32 a, b;
    s32 i;

    a = 0xA0;
    CpuFastSet((void *)&a, (void *)OAM, 0x01000100);
    for (i = 0; i < 128; i++)
        gOamBuffer[i].attr0 = 0xA0;
    b = 0;
    CpuFastSet((void *)&b, (void *)VRAM, 0x01006000);
}

void sound_init(struct Unk_03007014 *work)
{
    sound_engine_init(work);
    sub_08074900(gUnk_080AFFB8);
    sub_08074BC4(gUnk_080B06EC);
    sub_08074E70(&gUnk_080B1788);
    sub_08073AE4((u32)gUnk_080B1570);
    sub_08073AF8((u32)gUnk_080B1718);
    play_song(0);
}

void vblank_irq(void)
{
    if (!(gUnk_03002B90 & 1))
    {
        gUnk_03002B90 |= 1;
        vblank_body();
        gUnk_03002B90 &= ~1;
        if (gUnk_03005010.unk0 & 0x80)
            sub_080023D8();
        REG_IME = 0;
        if (++gUnk_03002410 > 5 && gSioLink.sendPending)
        {
            gUnk_03005010.unk1E = 0xFF;
            INTR_CHECK |= 0x80;
        }
        INTR_CHECK |= 1;
        REG_IME = 1;
    }
}

void vblank_body(void)
{
    s32 i;

    if (!(gUnk_03000434 & 1))
    {
        REG_BG0HOFS = gBg0Scroll.x + gUnk_03002C2C.x;
        REG_BG0VOFS = gBg0Scroll.y + gUnk_03002C2C.y;
        REG_BG1HOFS = gBg1Scroll.x + gUnk_03002C2C.x;
        REG_BG1VOFS = gBg1Scroll.y + gUnk_03002C2C.y;
        REG_BG2HOFS = gBg2Scroll.x + gUnk_03002C2C.x;
        REG_BG2VOFS = gBg2Scroll.y + gUnk_03002C2C.y;
        REG_BG3HOFS = gBg3Scroll.x + gUnk_03002C2C.x;
        REG_BG3VOFS = gBg3Scroll.y + gUnk_03002C2C.y;
    }
    if (gUnk_03000430 != 0)
    {
        if (gUnk_03000430 == 2)
        {
            update_anim_object_flags();
            copy_oam_affine_params(gUnk_03002414->unkB84, gUnk_03002414->unkF8C);
            for (i = 0; i < 88; i++)
                gOamBuffer[i].affineParam = gUnk_03002414->unkB84[i].affineParam;
            for (i = 0; i < 40; i++)
                gUnk_03002414->unkB84[i].affineParam = gOamBuffer[88 + i].affineParam;
            if (gUnk_03000440.unk131 == 0)
                CpuFastSet(gUnk_03002414->unkB84, (void *)(OAM + 88 * 8), 0x50);
            gUnk_03002414->unk1094 = 0;
            gUnk_03002414->unk1095 = 0;
            if (gUnk_03000440.unk12E)
                CpuFastSet(gOamBuffer, (void *)OAM, 0xB0);
        }
        else
        {
            gUnk_03000430 = 0;
        }
    }
    else if (gUnk_03000440.unk12E)
    {
        CpuFastSet(gOamBuffer, (void *)OAM, 0x100);
    }
    gUnk_03000440.unk12E = 0;
    gVBlankOnceCallback();
    gVBlankCallback();
    gVBlankOnceCallback = nullsub_08000840;
    INTR_CHECK = 1;
    REG_IF = 1;
    sound_tick_both_channels();
    sound_engine_tick();
}

void hblank_irq(void)
{
    gHBlankCallback();
    REG_IF = 2;
}

void nullsub_08000840(void)
{
}

void read_keys(void)
{
    u16 prev;

    gPrevKeys = prev = gHeldKeys;
    gHeldKeys = REG_KEYINPUT ^ 0x3FF;
    gNewKeys = gHeldKeys & ~prev;
    gReleasedKeys = prev & ~gHeldKeys;
    gRepeatKeys = 0;
    if (gNewKeys)
    {
        gRepeatKeys = gNewKeys;
        gKeyRepeatTimer = 16;
    }
    if (gHeldKeys)
    {
        if (gKeyRepeatTimer == 0)
        {
            gRepeatKeys = gNewKeys | gHeldKeys;
            gKeyRepeatTimer = 3;
        }
        else
        {
            gKeyRepeatTimer--;
        }
    }
}

void soft_reset(void)
{
    u32 i;

    if (gUnk_03005030)
    {
        gUnk_03005010.unk4 = 0xFFFF;
        gUnk_03005010.unk6 = -1;
        for (i = 0; i < 8; i++)
        {
            serial_prepare_send_packet(&gUnk_03005010.unk4);
            VBlankIntrWait();
        }
        gUnk_03005030 = 0;
        serial_multiplayer_init();
    }
    VBlankIntrWait();
    REG_BLDCNT = 0xFF;
    REG_BLDY = 0x10;
    REG_SOUNDCNT_X = 0;
    REG_IME = 0;
    hw_reset_init();
    irq_init();
    serial_link_init();
    gGameMode = 3;
    gGameState = 0;
    gGameSubState = 0;
    REG_DMA0CNT_H = 0;
}

u32 check_soft_reset(void)
{
    if ((*(u8 *)&gHeldKeys & 0xF) == 0xF && (*(u8 *)&gNewKeys & 8))
    {
        soft_reset();
        read_keys();
        return 1;
    }
    return 0;
}

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

u32 lz_decompress_dispatch(const u8 *src, void *dst)
{
    if (src[0] != 'L' || src[1] != 'e')
        return 0;
    if ((u32)dst - 0x04000001 <= 0x03FFFFFE)
        return lz_decompress_custom_08000B14(src, dst);
    else
        return lz_decompress_custom_08000A0C(src, dst, src[2] | (src[3] << 8) | (src[4] << 16));
}

u32 lz_decompress_custom_08000A0C(const u8 *src, u8 *dst, u32 size)
{
    u32 left = size;
    u8 *d = dst;
    const u8 *s = src + 6;
    u8 flags;
    u32 n;
    u32 v;
    u8 *p;

    while (left != 0)
    {
        flags = *s++;
        for (n = 0; n < 4 && left != 0; n++, flags >>= 2)
        {
            switch (flags & 3)
            {
            case 0:
                v = s[0] + (s[1] << 8);
                s += 2;
                p = d - ((v & 0xFFF) + 5);
                v = (v >> 12) + 3;
                left -= v;
                while (v--)
                    *d++ = *p++;
                break;
            case 1:
                v = *s++;
                p = d - ((v & 3) + 1);
                v = (v >> 2) + 2;
                left -= v;
                while (v--)
                    *d++ = *p++;
                break;
            case 3:
                *d++ = *s++;
                *d++ = *s++;
                *d++ = *s++;
                left -= 3;
                break;
            case 2:
                *d++ = *s++;
                left--;
                break;
            }
        }
    }
    return size;
}

u32 lz_decompress_custom_08000B14(const u8 *src, void *dst)
{
    u32 size;
    u32 left;
    u8 *d;
    const u8 *s;
    u8 flags;
    u32 n;
    u32 v;
    u8 *p;

    if (src[0] != 'L' || src[1] != 'e')
        return 0;
    size = src[2] | (src[3] << 8) | (src[4] << 16);
    left = size;
    d = dst;
    s = src + 6;

    while (left != 0)
    {
        flags = *s++;
        for (n = 0; n < 4 && left != 0; n++, flags >>= 2)
        {
            switch (flags & 3)
            {
            case 0:
                v = s[0] + (s[1] << 8);
                s += 2;
                p = d - ((v & 0xFFF) + 5);
                v = (v >> 12) + 3;
                left -= v;
                while (v--)
                {
                    u16 *dh = (u16 *)((u32)d & ~1);
                    u16 sv = *(u16 *)((u32)p & ~1);
                    u16 dv = *dh;
                    if ((u32)p & 1)
                    {
                        if ((u32)d & 1)
                            *dh = (dv & 0xFF) | (sv & 0xFF00);
                        else
                            *dh = (dv & 0xFF00) | (sv >> 8);
                    }
                    else
                    {
                        if ((u32)d & 1)
                            *dh = (dv & 0xFF) | (sv << 8);
                        else
                            *dh = (dv & 0xFF00) | (sv & 0xFF);
                    }
                    d++;
                    p++;
                }
                break;
            case 1:
                v = *s++;
                p = d - ((v & 3) + 1);
                v = (v >> 2) + 2;
                left -= v;
                while (v--)
                {
                    u16 *dh = (u16 *)((u32)d & ~1);
                    u16 sv = *(u16 *)((u32)p & ~1);
                    u16 dv = *dh;
                    if ((u32)p & 1)
                    {
                        if ((u32)d & 1)
                            *dh = (dv & 0xFF) | (sv & 0xFF00);
                        else
                            *dh = (dv & 0xFF00) | (sv >> 8);
                    }
                    else
                    {
                        if ((u32)d & 1)
                            *dh = (dv & 0xFF) | (sv << 8);
                        else
                            *dh = (dv & 0xFF00) | (sv & 0xFF);
                    }
                    d++;
                    p++;
                }
                break;
            case 3:
                {
                    u16 *dh = (u16 *)((u32)d & ~1);
                    u16 dv = *dh;
                    if ((u32)d & 1)
                        *dh = (dv & 0xFF) | (*s << 8);
                    else
                        *dh = (dv & 0xFF00) | *s;
                    d++;
                    s++;
                }
                {
                    u16 *dh = (u16 *)((u32)d & ~1);
                    u16 dv = *dh;
                    if ((u32)d & 1)
                        *dh = (dv & 0xFF) | (*s << 8);
                    else
                        *dh = (dv & 0xFF00) | *s;
                    d++;
                    s++;
                }
                {
                    u16 *dh = (u16 *)((u32)d & ~1);
                    u16 dv = *dh;
                    if ((u32)d & 1)
                        *dh = (dv & 0xFF) | (*s << 8);
                    else
                        *dh = (dv & 0xFF00) | *s;
                    d++;
                    s++;
                }
                left -= 3;
                break;
            case 2:
                {
                    u16 *dh = (u16 *)((u32)d & ~1);
                    u16 dv = *dh;
                    if ((u32)d & 1)
                        *dh = (dv & 0xFF) | (*s << 8);
                    else
                        *dh = (dv & 0xFF00) | *s;
                    d++;
                    s++;
                }
                left--;
                break;
            }
        }
    }
    return size;
}

void set_tilemap_and_decompress_bg(u32 x, u32 y, const u8 *src, u32 bgcnt, u16 base)
{
    gTilemapBaseEntry = base;
    lz_decompress_dispatch(src, gDecompressBuffer);
    write_tilemap_to_vram_08000E94(x, y, (struct Tilemap *)gDecompressBuffer, bgcnt);
}

void decompress_to_ewram_buffer(u32 x, u32 y, const u8 *src, u32 bgcnt)
{
    lz_decompress_dispatch(src, gDecompressBuffer);
    load_tilemap_rows_to_vram(x, y, (struct Tilemap *)gDecompressBuffer, bgcnt);
}

void decompress_to_bg_scroll_buffer(const u8 *src, void *dst)
{
    u32 size = lz_decompress_dispatch(src, gDecompressBuffer);
    CpuCopy16(gDecompressBuffer, dst, size);
}

void write_tilemap_to_vram_08000E94(u32 x, u32 y, struct Tilemap *map, u32 bgcnt)
{
    u16 *dst = (u16 *)((((bgcnt >> 8) & 0x1F) * 0x800) + VRAM) + x + y * 32;
    u16 *src = map->data;
    u16 *d; u32 i, j;

    if (((bgcnt & 0xC000) >> 14) & 1)
    {
        copy_tilemap_with_offset_08000F78(dst, map);
    }
    else
    {
for (i = 0; i < map->height; i++) { d = dst + (i << 5); for (j = 0; j < map->width; j++) *d++ = *src++ + gTilemapBaseEntry; }
    }
}

void load_tilemap_rows_to_vram(u32 x, u32 y, struct Tilemap *map, u32 bgcnt)
{
    u32 shift = ((bgcnt & 0xC000) >> 14) + 3;
    u8 *dst = (u8 *)((((bgcnt >> 8) & 0x1F) * 0x800) + VRAM) + x + (y << shift);
    u8 *src = (u8 *)map->data;
    u32 i;
    for (i = 0; i < map->height; i++) { CpuCopy16(src, (u16 *)dst + (i << shift), map->width); src += map->width; }
}

void copy_tilemap_with_offset_08000F78(u16 *dst, struct Tilemap *map)
{
    s32 w, hh;
    s32 i, j;
    u16 *s, *d;

    w = map->width;
    if (w > 32)
        w = 32;
    hh = map->height;
    if (hh > 32)
        do { hh = 32; } while (0);

    i = 0;
    do
    {
        if (i >= hh)
            break;
        s = &map->data[map->width * i];
        d = dst + i * 32;
        i++;
        for (j = 0; j < w; j++)
            *d++ = *s++ + gTilemapBaseEntry;
    } while (1);
    for (i = 0; i < hh; i++)
    {
        s = &map->data[i * map->width + 32];
        d = dst + 0x400 + i * 32;
        for (j = 32; j < map->width; j++)
            d[j - 32] = s[j - 32] + gTilemapBaseEntry;
    }
    for (i = 32; i < map->height; i++)
    {
        s = &map->data[map->width * i];
        d = dst + 0x400 + i * 32;
        for (j = 0; j < w; j++)
            *d++ = *s++ + gTilemapBaseEntry;
    }
    for (i = 32; i < map->height; i++)
    {
        s = &map->data[i * map->width + 32];
        d = dst + 0x800 + i * 32;
        for (j = 32; j < map->width; j++)
            d[j - 32] = s[j - 32] + gTilemapBaseEntry;
    }
}

// Note: writes the BG3 affine registers (0x04000030-0x0400003E), not BG2.
// pa/pd = cos * 0x400 / scale, pb/pc = +-sin * 0x400 / scale (scale 0x100 = 1:1), angle 1024 steps/turn;
// reference point X = -(pa * a4 + pb * a5) - a2, Y = -(pc * a4 + pd * a5) - a3.
void set_bg2_affine_transform(s32 scale, u32 angle, s32 cx, s32 cy, s32 sx, s32 sy)
{
    s32 pa, pb, pc, pd, x, y;

    pa = Div(gUnk_080750E0[(angle & 0x3FF) + 0x100] * 4, scale);
    pb = Div(gUnk_080750E0[(angle & 0x3FF)] * 4, scale);
    pc = Div(-gUnk_080750E0[(angle & 0x3FF)] * 4, scale);
    pd = Div(gUnk_080750E0[(angle & 0x3FF) + 0x100] * 4, scale);
    *(vu16 *)0x04000030 = pa;
    *(vu16 *)0x04000032 = pb;
    *(vu16 *)0x04000034 = pc;
    *(vu16 *)0x04000036 = pd;
    x = -(pa * sx) - pb * sy - cx;
    y = -(pc * sx) - pd * sy - cy;
    *(vu16 *)0x04000038 = x;
    *(vu16 *)0x0400003A = (x & 0x0FFF0000) >> 16;
    *(vu16 *)0x0400003C = y;
    *(vu16 *)0x0400003E = (y & 0x0FFF0000) >> 16;
}

// New local struct: one scanline of BG2 affine registers (BG2PA..BG2PD, BG2X, BG2Y), 16 bytes.
struct BgAffineLine
{
    s16 pa, pb, pc, pd;
    u16 xl, xh, yl, yh;
};

// MATCH: the line pointer uses its own counter j (for i, j; i++, j++) so its increment lands after i++.
// Fills the back buffer (gUnk_02030A00 on odd frames, gDecompressBuffer on even) with 160
// per-scanline BG2 affine sets whose zoom shrinks as 1 / (1 + line * step) (a perspective
// "floor" effect, Mode-7 like), then arms hblank_dma0_bg2affine for the next vblank.

void compute_bg_affine_scanline_params(s32 step, u32 angle, s32 unused, s32 cx, s32 cy, s32 sx, s32 sy)
{
    struct BgAffineLine *buf;
    s32 i, j;
    s32 pa, pb, pc, pd, x, y, t;

    if (!(gFrameCounter & 1))
        buf = (struct BgAffineLine *)gDecompressBuffer;
    else
        buf = (struct BgAffineLine *)gUnk_02030A00;
    for (i = 0, j = 0; i < 160; i++, j++)
    {
        pa = DivArm(i * step + 1, gUnk_080750E0[(angle & 0x3FF) + 0x100] << 7);
        t = DivArm(i * step + 1, gUnk_080750E0[angle & 0x3FF] << 7);
        pc = -t;
        pb = t * 3;
        pd = pa * 3;
        buf[j].pa = pa;
        buf[j].pb = pb;
        buf[j].pc = pc;
        buf[j].pd = pd;
        x = -(pa * sx) - pb * sy - cx + pb * i;
        y = -(pc * sx) - pd * sy - cy + pd * i;
        buf[j].xl = x;
        buf[j].xh = x >> 16;
        buf[j].yl = y;
        buf[j].yh = y >> 16;
    }
    gVBlankOnceCallback = hblank_dma0_bg2affine;
}

// Run once at vblank (gVBlankOnceCallback, set by compute_bg_affine_scanline_params): copies line 0 of the current (double-buffered) BG2 affine table to BG2PA..BG2Y,
// then starts DMA0 (hblank-triggered, repeat, 8 halfwords) to feed the rest of the lines.
void hblank_dma0_bg2affine(void)
{
    vu32 *dma = (vu32 *)REG_ADDR_DMA0;
    vu16 *dst = (vu16 *)0x04000020;
    u16 *src;

    if (gFrameCounter & 1)
        src = (u16 *)gDecompressBuffer;
    else
        src = (u16 *)gUnk_02030A00;
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
    dst[3] = src[3];
    dst[4] = src[4];
    dst[5] = src[5];
    dst[6] = src[6];
    dst[7] = src[7];
    REG_DMA0CNT_H = 0;
    dma[0] = (u32)(src + 8);
    dma[1] = (u32)dst;
    dma[2] = 0xA2600008;
}

// Stops the per-scanline affine DMA (unreferenced).
void sub_080012E4(void)
{
    REG_DMA0CNT_H = 0;
}

u32 rng_next(u16 range)
{
    gRngCounter++;
    gRngValue = gRngTable[gRngCounter & 0xF] ^ gRngState;
    { u32 n = ~gRngValue; u32 t = ((s16 *)&gRngState)[1] + 0x55555555; gRngState = n + t; }
    if (range == 0) return gRngValue;
    return (u32)(((s16 *)&gRngValue)[1] * range) >> 16;
}

// Linear interpolation in 4.12 fixed point: a at t = 0, b at t = 0x1000. Not called.
s32 sub_0800134C(s32 a, s32 b, s32 t)
{
    return b * t / 4096 + a * (4096 - t) / 4096;
}

void copy_obj_palette_to_buffer(void)
{
    CpuFastSet((void *)OBJ_PLTT, gPaletteBackup, 0x80);
    CpuFastSet((void *)PLTT, gPaletteBackupBg, 0x80);
}

void palette_blend_to_color_080013A8(u16 color, u32 amount)
{
    u32 i;
    u32 inv;
    if (amount > 32)
        amount = 32;
    inv = 32 - amount;
    for (i = 0; i < 0x200; i++)
    {
        u16 *dst = &gPaletteBuffer[i];
        u16 *src = &gPaletteBackup[i];
        *dst = (((*src & 0x1F) * inv + (color & 0x1F) * amount) >> 5)
            | ((((*src & 0x3E0) * inv + (color & 0x3E0) * amount) >> 5) & 0x3E0)
            | ((((*src & 0x7C00) * inv + (color & 0x7C00) * amount) >> 5) & 0x7C00);
    }
    gVBlankOnceCallback = dma_obj_palette_to_hardware;
}

void dma_obj_palette_to_hardware(void)
{
    CpuFastSet(gPaletteBuffer, (void *)OBJ_PLTT, 0x80);
    CpuFastSet(gPaletteBufferBg, (void *)PLTT, 0x80);
}

void palette_blend_16_colors(u16 *src, u16 *dst, u16 color, u32 amount)
{
    u32 i;
    u32 inv;
    if (amount > 32)
        amount = 32;
    inv = 32 - amount;
    for (i = 0; i < 16; i++)
    {
        dst[i] = (((color & 0x1F) * amount + (src[i] & 0x1F) * inv) >> 5)
            | ((((src[i] & 0x3E0) * inv + (color & 0x3E0) * amount) >> 5) & 0x3E0)
            | ((((color & 0x7C00) * amount + (src[i] & 0x7C00) * inv) >> 5) & 0x7C00);
    }
}

void check_flag_and_fast_copy(void)
{
    struct ObjSortEntry sorted[128];
    s32 zero;
    s32 x, y;
    struct Unk_03002C30 *obj;
    s32 i, count, j, oamIdx, affIdx, dbl, affBits;
    s32 px, py, w, h;
    struct SpriteFrame *const *frameSet;
    struct SpritePart *part;
    struct OamData *oam;

    if (gUnk_03000438 & 1)
    {
        gUnk_03000438 = 0;
        return;
    }
    zero = 0;
    CpuFastSet(&zero, sorted, 0x01000040);
    obj = gUnk_03002C30;
    count = 0;
    for (i = 0; i < 128; i++, obj++)
    {
        if (obj->unk0 & 0x8000)
        {
            sorted[count].idx = i;
            sorted[count].key = obj->unkB;
            count++;
        }
    }
    if (!(gUnk_03000438 & 2))
        shell_sort_by_second_byte(sorted, count);
    else
        gUnk_03000438 = 0;

    if (gUnk_03000430 == 2)
        affIdx = 22;
    else
        affIdx = 0;
    oamIdx = 0;
    for (i = 0; i < count; i++)
    {
        obj = &gUnk_03002C30[sorted[i].idx];
        gUnk_03005048 = -1;
        switch (obj->unk0 & 0xC0)
        {
        case 0x80:
            px = obj->unkC_8 * 4;
            py = (obj->unk10_8 + gUnk_03005044) * 4;
            w = (obj->unk14_8 + 0x3000) / 64;
            px = px / w;
            py = py / w;
            obj->unk2 = gUnk_03005040 + px;
            obj->unk4 = gUnk_0300504C + py;
            obj->unk8 = obj->unk9 = 0x8000 / w;
            gUnk_03005048 = 0x700000 / w;
            break;
        case 0xC0:
            break;
        case 0x40:
            obj->unk2 = (obj->unkC_8 >> 8) - gUnk_03002C24.x;
            obj->unk4 = ((obj->unk10_8 + obj->unk14_8) >> 8) - gUnk_03002C24.y;
            break;
        }
        switch (obj->unk1C & 0xF)
        {
        case 1:
            frameSet = gUnk_083AC088[obj->unk6 >> 8];
            break;
        case 2:
            frameSet = gUnk_083AC0C8[obj->unk6 >> 8];
            break;
        case 3:
            frameSet = gUnk_083AC108[obj->unk6 >> 8];
            break;
        case 0:
        default:
            frameSet = gUnk_083ABE30[obj->unk6 >> 8];
            break;
        }
        part = frameSet[obj->unk6 & 0xFF]->parts;
        px = -gUnk_03002C2C.x + gUnk_03001794.x + obj->unk2;
        py = -gUnk_03002C2C.y + gUnk_03001794.y + obj->unk4;
        if ((obj->unk0 & 0xC0) == 0x40)
        {
            if ((u32)(py + 32) > 256)
            {
                obj->unk0 |= 2;
                continue;
            }
            if ((u32)(px + 32) > 336)
            {
                obj->unk0 |= 2;
                continue;
            }
            obj->unk0 &= ~2;
        }
        if (!(obj->unk0 & 0x4000))
            continue;
        if (obj->unk0 & 0x200)
        {
            if ((obj->unk0 & 0xC0) != 0xC0)
            {
                if (affIdx < 32)
                {
                    if (obj->unk18)
                        set_oam_affine_params(affIdx, obj->unk18, obj->unk8, obj->unk9, obj->unk0);
                    else
                        compute_scaled_value(affIdx, obj->unk8, obj->unk9, obj->unk0);
                    dbl = (obj->unk0 & 0x20) ? 0x300 : 0x100;
                    affBits = affIdx << 9;
                    affIdx++;
                }
            }
            else
            {
                dbl = (obj->unk0 & 0x20) ? 0x300 : 0x100;
                affBits = obj->filler1D[0] << 9; // unk1D: shared affine matrix index
            }
        }
        else
        {
            dbl = 0;
            affBits = 0;
        }

        for (j = 0; j < frameSet[obj->unk6 & 0xFF]->count; j++)
        {
            oam = gOamBuffer;
            h = *(u16 *)part & 0xC0C0;
            switch (h)
            {
            case 0x0:
            case 0x80:
            case 0x4080:
                w = 4;
                break;
            case 0x40:
            case 0x4000:
            case 0x8080:
                w = 8;
                break;
            case 0x4040:
            case 0x8000:
            case 0x8040:
            case 0xC080:
                w = 16;
                break;
            case 0xC000:
            case 0xC040:
                w = 32;
                break;
            }
            switch (h)
            {
            case 0x0:
            case 0x40:
            case 0x4040:
                h = 4;
                break;
            case 0x80:
            case 0x4000:
            case 0x8040:
                h = 8;
                break;
            case 0x4080:
            case 0x8000:
            case 0x8080:
            case 0xC040:
                h = 16;
                break;
            case 0xC000:
            case 0xC080:
                h = 32;
                break;
            }
            if (obj->unk0 & 0x200)
            {
                if ((obj->unk0 & 0xC0) != 0xC0)
                {
                    x = part->x + w;
                    y = part->y + h;
                    if (obj->unk0 & 0x20)
                    {
                        w = -w * 2;
                        h = -h * 2;
                    }
                    else
                    {
                        w = -w;
                        h = -h;
                    }
                    if (obj->unk0 & 0x1000)
                        x = -x - (obj->unk8 - 0x40) * x / 64;
                    else
                        x = x + (obj->unk8 - 0x40) * x / 64;
                    if (obj->unk0 & 0x2000)
                        y = -y - (obj->unk9 - 0x40) * y / 64;
                    else
                        y = y + (obj->unk9 - 0x40) * y / 64;
                    if (obj->unk0 & 0x100)
                        rotate_vector_2d(&x, &y, (struct RotateSrc *)obj);
                    w = w + px + x;
                    h = h + py + y;
                    oam[oamIdx].attr0 = (h & 0xFF) | (part->shape << 8) | dbl | ((obj->unk0 & 0x18) << 7) | ((obj->unk0 & 1) << 12);
                    oam[oamIdx].attr1 = (w & 0x1FF) | ((part->size & 0xC0) << 8) | affBits;
                }
                else
                {
                    if (obj->unk0 & 0x20)
                    {
                        w = part->x;
                        h = part->y;
                    }
                    else
                    {
                        w = 0;
                        h = 0;
                    }
                    if (obj->unk0 & 0x1000)
                        w = -part->x - w + px - w;
                    else
                        w = w + (part->x + px);
                    if (obj->unk0 & 0x2000)
                        h = -part->y - h + py - h;
                    else
                        h = h + (part->y + py);
                    oam[oamIdx].attr0 = (h & 0xFF) | (part->shape << 8) | dbl | ((obj->unk0 & 0x18) << 7) | ((obj->unk0 & 1) << 12);
                    oam[oamIdx].attr1 = ((w & 0x1FF) | (part->size << 8) | affBits) ^ (obj->unk0 & 0x3000);
                }
            }
            else
            {
                if (obj->unk0 & 0x1000)
                    w = -part->x - w + px - w;
                else
                    w = px + part->x;
                if (obj->unk0 & 0x2000)
                    h = -part->y - h + py - h;
                else
                    h = py + part->y;
                oam[oamIdx].attr0 = (h & 0xFF) | (part->shape << 8) | dbl | ((obj->unk0 & 0x18) << 7) | ((obj->unk0 & 1) << 12);
                oam[oamIdx].attr1 = ((w & 0x1FF) | (part->size << 8)) ^ (obj->unk0 & 0x3000);
            }
            if (obj->unk0 & 4)
            {
                if (part->tile & 0xF000)
                    ((u16 *)gOamBuffer)[oamIdx * 4 + 2] = (obj->unk0 & 0xC00) | part->tile;
                else
                    ((u16 *)gOamBuffer)[oamIdx * 4 + 2] = (part->tile & 0xFFF) | (obj->unkA << 12) | (obj->unk0 & 0xC00);
            }
            else
            {
                ((u16 *)gOamBuffer)[oamIdx * 4 + 2] = ((obj->unkA << 12) + part->tile) | (obj->unk0 & 0xC00);
            }

            oamIdx++;
            part++;
            if (oamIdx > 127)
                goto end;
        }
        if (oamIdx > 127)
            goto end;
    }
end:
    for (i = oamIdx; i < 128; i++)
        ((u16 *)gOamBuffer)[i * 4] = 0x200;
    gUnk_03000440.unk12E = 1;
}

void set_oam_affine_params(u32 idx, u32 angle, s32 sx, s32 sy, u32 flags)
{
    u32 n = idx * 4;
    s32 cos, sin;

    if (gUnk_03005048 == -1)
    {
        cos = gUnk_080750E0[(angle & 0x3FF) + 0x100];
        sin = gUnk_080750E0[angle & 0x3FF];
        if (sx == 0)
            sx = 1;
        if (sy == 0)
            sy = 1;
        if (flags & 0x1000)
        {
            gOamBuffer[n].affineParam = DivArm(sx, -cos);
            gOamBuffer[n + 1].affineParam = DivArm(sy, -sin);
        }
        else
        {
            gOamBuffer[n].affineParam = DivArm(sx, cos);
            gOamBuffer[n + 1].affineParam = DivArm(sy, sin);
        }
        if (flags & 0x2000)
        {
            gOamBuffer[n + 2].affineParam = DivArm(sx, sin);
            gOamBuffer[n + 3].affineParam = DivArm(sy, -cos);
        }
        else
        {
            gOamBuffer[n + 3].affineParam = DivArm(sy, cos);
            gOamBuffer[n + 2].affineParam = DivArm(sx, -sin);
        }
    }
    else
    {
        cos = gUnk_080750E0[(angle & 0x3FF) + 0x100] << 8;
        sin = gUnk_080750E0[angle & 0x3FF] << 8;
        if (flags & 0x1000)
        {
            gOamBuffer[n].affineParam = DivArm(gUnk_03005048, -cos);
            gOamBuffer[n + 1].affineParam = DivArm(gUnk_03005048, -sin);
        }
        else
        {
            gOamBuffer[n].affineParam = DivArm(gUnk_03005048, cos);
            gOamBuffer[n + 1].affineParam = DivArm(gUnk_03005048, sin);
        }
        if (flags & 0x2000)
        {
            gOamBuffer[n + 2].affineParam = DivArm(gUnk_03005048, sin);
            gOamBuffer[n + 3].affineParam = DivArm(gUnk_03005048, -cos);
        }
        else
        {
            gOamBuffer[n + 3].affineParam = DivArm(gUnk_03005048, cos);
            gOamBuffer[n + 2].affineParam = DivArm(gUnk_03005048, -sin);
        }
    }
}

void compute_scaled_value(u32 idx, s32 sx, s32 sy, u32 flags)
{
    u32 n = idx * 4;

    if (gUnk_03005048 == -1)
    {
        if (flags & 0x1000)
        {
            gOamBuffer[n].affineParam = -0x4000 / sx;
            gOamBuffer[n + 1].affineParam = 0;
        }
        else
        {
            gOamBuffer[n].affineParam = 0x4000 / sx;
            gOamBuffer[n + 1].affineParam = 0;
        }
        if (flags & 0x2000)
        {
            gOamBuffer[n + 2].affineParam = 0;
            gOamBuffer[n + 3].affineParam = -0x4000 / sy;
        }
        else
        {
            gOamBuffer[n + 3].affineParam = 0x4000 / sy;
            gOamBuffer[n + 2].affineParam = 0;
        }
    }
    else
    {
        if (flags & 0x1000)
        {
            gOamBuffer[n].affineParam = -0x400000 / gUnk_03005048;
            gOamBuffer[n + 1].affineParam = 0;
        }
        else
        {
            gOamBuffer[n].affineParam = 0x400000 / gUnk_03005048;
            gOamBuffer[n + 1].affineParam = 0;
        }
        if (flags & 0x2000)
        {
            gOamBuffer[n + 2].affineParam = 0;
            gOamBuffer[n + 3].affineParam = -0x400000 / gUnk_03005048;
        }
        else
        {
            gOamBuffer[n + 3].affineParam = 0x400000 / gUnk_03005048;
            gOamBuffer[n + 2].affineParam = 0;
        }
    }
}

struct RotateSrc
{
    u8 filler0[0x18];
    u16 angle;
};

// Rotates (*x, *y) by p->angle (1024 steps per turn); the table is Q14 sin, cos at +0x100.
void rotate_vector_2d(s32 *x, s32 *y, struct RotateSrc *p)
{
    s32 c = gUnk_080750E0[(p->angle & 0x3FF) + 0x100];
    s32 s = gUnk_080750E0[p->angle & 0x3FF];
    s32 x0 = *x;
    s32 y0 = *y;

    *x = (x0 * c - y0 * s) / 0x4000;
    *y = (x0 * s + y0 * c) / 0x4000;
}

INCLUDE_ASM("asm/nonmatching/code_0800025C", shell_sort_by_second_byte);

void serial_link_init(void)
{
    u32 zero;

    REG_IME = 0;
    REG_IE &= ~0xC0;
    REG_IME = 1;
    REG_RCNT = 0;
    REG_SIOCNT = 0x2000;
    REG_SIOCNT |= 0x4003;
    zero = 0;
    CpuSet(&zero, &gSioLink, 0x05000036);
    CpuSet(link_buffer_swap_arm, gUnk_03005250, 0x04000010);
    CpuSet(serial_multiplayer_transfer_handler, gUnk_03005050, 0x04000048);
    gSioLink.sendIdx = 6;
    gSioLink.recvIdx = 6;
    gSioLink.nextSend = &gSioLink.sendBuf[0];
    gSioLink.curSend = &gSioLink.sendBuf[1];
    gSioLink.curRecv = (void *)gSioLink.recvBuf[0];
    gSioLink.lastRecv = (void *)gSioLink.recvBuf[1];
    gSioLink.recvCheck = gSioLink.recvBuf[2];
    REG_IME = 0;
    REG_IE |= 0x80;
    REG_IME = 1;
}

void sub_08002190(void)
{
    if (gSioLink.isParent)
        gSioLink.started = 1;
}

void serial_multiplayer_init(void)
{
    REG_IME = 0;
    REG_IE &= ~0xC0;
    REG_IME = 1;
    REG_SIOCNT = 0x2003;
    REG_TM3CNT = 0x63F7;
    REG_IF = 0xC0;
    gSioLink.started = 0;
}

u32 serial_link_init_and_status(u32 *recv)
{
    struct SioCnt *cnt = (struct SioCnt *)REG_ADDR_SIOCNT;
    struct SioCnt cur = *cnt;

    switch (gSioLink.running)
    {
    case 0:
        if (!cur.id)
        {
            if (!cur.sd || cur.enable)
                break;
            if (!cur.si && gSioLink.sendIdx == 6)
            {
                REG_IME = 0;
                REG_IE &= ~0x80;
                REG_IE |= 0x40;
                REG_IME = 1;
                cnt->irq = 0;
                REG_TM3CNT = 0x63F7;
                REG_IF = 0xC0;
                gSioLink.isParent = 8;
            }
            gSioLink.running = 1;
        }
    case 1:
        serial_link_receive_packets(recv);
        break;
    }

    gSioLink.frame++;
    return gSioLink.recvOk
         | (gSioLink.isParent == 8 ? 0x80 : 0)
         | (gSioLink.connected << 8)
         | (gSioLink.error ? 0x1000 : 0)
         | (cur.id > 3 ? 0x2000 : 0);
}

void serial_prepare_send_packet(u16 *packet)
{
    s32 sum = 0;
    u32 i;

    gSioLink.nextSend->frame = gSioLink.frame;
    gSioLink.nextSend->errFlags = gSioLink.connected ^ gSioLink.recvOk;
    gSioLink.nextSend->checksum = 0;
    CpuSet(packet, gSioLink.nextSend->data, 0x04000001);
    for (i = 0; i < 4; i++)
        sum += ((u16 *)gSioLink.nextSend)[i];
    gSioLink.nextSend->checksum = ~sum;
    gSioLink.sendPending = 1;
}

u8 serial_link_receive_packets(u32 *dst)
{
    u8 (*swapBuffers)(void) = (u8 (*)(void))0x03005250; // IWRAM copy of link_buffer_swap_arm
    vu32 unused = 0;
    u8 synced;
    s32 i;
    u32 j;

    synced = swapBuffers();
    gSioLink.recvOk = 0;
    if (synced)
    {
        for (i = 0; i < 4; i++)
        {
            struct SioPacket *pkt = &gSioLink.recvCheck[i];
            s32 sum = 0;
            vu32 zero;

            for (j = 0; j < 4; j++)
                sum += ((u16 *)pkt)[j];
            if ((s16)sum == -1)
            {
                CpuSet(pkt->data, &dst[i], 0x04000001);
                gSioLink.recvOk |= 1 << i;
            }
            zero = 0;
            CpuSet((void *)&zero, pkt->data, 0x05000001);
        }
    }
    gSioLink.connected |= gSioLink.recvOk;
    return gSioLink.recvOk;
}

void sub_080023D8(void)
{
    if (gSioLink.running && gSioLink.started)
    {
        void *p;

        gSioLink.recvIdx = -1;
        p = gSioLink.lastRecv;
        gSioLink.lastRecv = gSioLink.curRecv;
        gSioLink.curRecv = p;
        if (gSioLink.sendPending)
        {
            p = gSioLink.curSend;
            gSioLink.curSend = gSioLink.nextSend;
            gSioLink.nextSend = p;
            gSioLink.sendPending = 0;
            gSioLink.sendIdx = 0;
        }
        gSioLink.error = ((struct SioMultiCnt *)REG_ADDR_SIOCNT)->error;
        ((struct SioMultiCnt *)REG_ADDR_SIOCNT)->data = 0xFEFE;
        REG_SIOCNT |= 0x80;
        REG_TM3CNT_H = 0xC0;
    }
}

// SIO interrupt handler, run from its IWRAM copy at 0x03005050.
void serial_multiplayer_transfer_handler(void)
{
    u16 recv[4];
    s32 i;

    *(unsigned long long *)recv = *(unsigned long long *)REG_ADDR_SIOMULTI0;
    gSioLink.error = ((struct SioMultiCnt *)REG_ADDR_SIOCNT)->error;
    if (recv[0] == 0xFEFE && gSioLink.recvIdx > 3)
    {
        u16 (*p)[6];
        struct SioPacket *q;

        gSioLink.recvIdx = -1;
        p = gSioLink.lastRecv;
        gSioLink.lastRecv = gSioLink.curRecv;
        gSioLink.curRecv = p;
        if (gSioLink.sendPending)
        {
            q = gSioLink.curSend;
            gSioLink.curSend = gSioLink.nextSend;
            gSioLink.nextSend = q;
            gSioLink.sendPending = 0;
            gSioLink.sendIdx = 0;
        }
        REG_IME = 0;
        INTR_CHECK |= 0x80;
        REG_IME = 1;
    }
    if (gSioLink.sendIdx < 4)
        ((struct SioMultiCnt *)REG_ADDR_SIOCNT)->data = ((u16 *)gSioLink.curSend)[gSioLink.sendIdx];
    if (gSioLink.sendIdx < 5)
        gSioLink.sendIdx++;
    if (gSioLink.recvIdx >= 0)
    {
        for (i = 0; i < 4; i++)
            gSioLink.curRecv[i][gSioLink.recvIdx] = recv[i];
        if (gSioLink.recvIdx == 3)
            gSioLink.recvDone = 1;
    }
    if (gSioLink.recvIdx < 5)
        gSioLink.recvIdx++;
    if (gSioLink.isParent)
        REG_TM3CNT_H = 0;
    if (gSioLink.sendIdx < 5 && gSioLink.isParent)
    {
        REG_SIOCNT |= 0x80;
        REG_TM3CNT_H = 0xC0;
    }
}

void dispatch_game_state_handler_08002534(void)
{
    gGameStateHandlers_083AC148[gGameState]();
}

void dispatch_game_substate_handler_08002554(void)
{
    gUnk_083AC248[gGameSubState]();
}

void sub_08002574(void)
{
    u16 priority;
    REG_BLDCNT = 0;
    REG_BLDY = 0;
    REG_DISPCNT = 0x1260;
    priority = 9; // the low bits have to go through a variable to load 0x5E09 straight into r0
    REG_BG1CNT = priority | 0x5E00;
    gUnk_03000440.unk85 = 1;
    gGameSubState++;
}

// guess: debug map viewer input (D-pad scrolls gBg1Scroll, START/SELECT open text windows)
void sub_080025B4(void)
{
    if (KEYS_LO(gHeldKeys) & 0x40)
        gBg1Scroll.y++;
    if (KEYS_LO(gHeldKeys) & 0x80)
        gBg1Scroll.y--;
    if (KEYS_LO(gHeldKeys) & 0x20)
        gBg1Scroll.x++;
    if (KEYS_LO(gHeldKeys) & 0x10)
        gBg1Scroll.x--;
    if (KEYS_LO(gNewKeys) & 2)
        gUnk_03000440.unk88 ^= 1;
    if (KEYS_LO(gNewKeys) & 1)
    {
        gUnk_03000440.unkE = 0;
        gGameSubState++;
        gUnk_03000440.unk85 ^= 1;
    }
    if (KEYS_LO(gNewKeys) & 2)
    {
        gGameState = 1;
        gGameSubState = 0;
    }
    if (KEYS_LO(gNewKeys) & 8)
    {
        text_window_init(0, 0, 0);
        gGameSubState += 2;
    }
    if (KEYS_LO(gNewKeys) & 4)
    {
        text_window_init(0, 0, 0);
        gGameSubState += 3;
    }
}

void load_overworld_column_and_advance(void)
{
    u8 r = message_portrait_anim_step(0, 1, 8, 4, gUnk_03000440.unk88, gUnk_03000440.unk85);
    if (r == 1)
        gGameSubState = r;
}

void init_save_prompt_text(void)
{
    u8 r;

    gUnk_03002B70.unk4[0] = 0x17;
    gUnk_03002B70.unk4[1] = 0x29;
    gUnk_03002B70.unk4[2] = 0x2C;
    gUnk_03002B70.unk4[3] = 0x25;
    gUnk_03002B70.unk4[4] = 0;
    gUnk_03002B70.unk4[5] = 0x2E;
    gUnk_03002B70.unk4[6] = 0x1F;
    gUnk_03002B70.unk4[7] = 0x2D;
    gUnk_03002B70.unk4[8] = 0x2E;
    gUnk_03002B70.unk4[9] = 0xFE;
    r = run_message(gUnk_083B53F8[0]);
    if (r == 1)
        gGameSubState = r;
}

void sub_08002730(void)
{
    if (run_message(gUnk_083B53F8[1]))
    {
        open_choice_menu(0, 0x16, 7);
        gGameSubState++;
    }
}

void sub_0800275C(void)
{
    if (poll_choice_menu())
    {
        sub_0803FB0C();
        gGameSubState++;
    }
}

void sub_0800277C(void)
{
    const void *msg;

    if (gUnk_03000440.unk28 & 0xF0)
        msg = gUnk_083B53F8[3];
    else
        msg = gUnk_083B53F8[2];
    if (run_message(msg))
        gGameSubState = 1;
}

// Game state 1: the field pause menu (Medawatch / Item / Vehicle / Save, money display).
void field_menu_update(void)
{
    gFieldMenuHandlers[gGameSubState]();
}

void field_menu_load_gfx(void)
{
    REG_DISPCNT = 0x1F60;
    REG_BG0CNT = 0x500;
    lz_decompress_dispatch(gUnk_084C1608, (void *)0x06001800);
    lz_decompress_dispatch(gUnk_084C17F0, (void *)0x06001B00);
    lz_decompress_dispatch(gUnk_084C1934, (void *)0x06001E00);
    lz_decompress_dispatch(gUnk_084C1ACC, (void *)0x06002100);
    lz_decompress_dispatch(gUnk_08487708, (void *)0x06002400);
    DmaSet(3, gUnk_08488A84, 0x050001E0, 0x80000010);
    lz_decompress_dispatch(gUnk_084C6A98, (void *)0x06017400);
    DmaSet(3, gUnk_084E2E38, 0x050003E0, 0x80000010);
    play_song(6);
    gUnk_03000440.unk84 = 0;
    gGameSubState++;
}

void field_menu_open_anim(void)
{
    if (gUnk_03000440.unk84 <= 12)
        write_tilemap_rect(12, 2, 18, 1, gUnk_083B4AE0[gUnk_03000440.unk84 + 0x13], REG_BG0CNT, 0);
    if ((u8)(gUnk_03000440.unk84 - 2) <= 12)
        write_tilemap_rect(12, 2, 18, 3, gUnk_083B4AE0[gUnk_03000440.unk84 + 0x1E], REG_BG0CNT, 0);
    if ((u8)(gUnk_03000440.unk84 - 4) <= 12)
        write_tilemap_rect(12, 2, 18, 5, gUnk_083B4AE0[gUnk_03000440.unk84 + 0x29], REG_BG0CNT, 0);
    if ((u8)(gUnk_03000440.unk84 - 6) <= 12)
        write_tilemap_rect(12, 2, 18, 7, gUnk_083B4AE0[gUnk_03000440.unk84 + 0x34], REG_BG0CNT, 0);
    if (gUnk_03000440.unk84 == 10)
    {
        lz_decompress_dispatch(gUnk_08487814, (void *)0x06002400);
        set_tilemap_and_decompress_bg(0x15, 9, gUnk_08488690, REG_BG0CNT, 0x120);
    }
    if (gUnk_03000440.unk84 == 12)
    {
        lz_decompress_dispatch(gUnk_08487708, (void *)0x06002400);
        set_tilemap_and_decompress_bg(0x15, 9, gUnk_08488644, REG_BG0CNT, 0x120);
    }
    if (++gUnk_03000440.unk84 > 18)
    {
        divide_by_10000(gUnk_03000440.unk9E, gUnk_03002B70.money);
        render_text_sprites_08040DB8(gUnk_03000440.unk9E, 10, 0x17, 10, 5, 15, 2, 0);
        gUnk_03000440.unk8E = 0;
        field_menu_init_cursor();
        gGameSubState++;
    }
}

void field_menu_handle_input(void)
{
    process_sprite_anim_commands(gUnk_083B5F80[0], 0);
    if (KEYS_LO(gRepeatKeys) & 0x40)
    {
        play_sound_effect(2);
        gUnk_03000440.unk8E = (gUnk_03000440.unk8E - 1) & 3;
        gUnk_03002C30[0].unk4 = gUnk_03000440.unk8E * 16 + 8;
    }
    if (KEYS_LO(gRepeatKeys) & 0x80)
    {
        play_sound_effect(2);
        gUnk_03000440.unk8E = (gUnk_03000440.unk8E + 1) & 3;
        gUnk_03002C30[0].unk4 = gUnk_03000440.unk8E * 16 + 8;
    }
    if (KEYS_LO(gNewKeys) & 2)
    {
        sound_stop_all_with_fade_guard(0x10);
        play_sound_effect(5);
        clear_battle_sprite_slot(0, 1);
        clear_battle_sprite_slot(10, 7);
        gUnk_03000440.unk84 = 0;
        gGameSubState = 3;
    }
    else if (KEYS_LO(gNewKeys) & 1)
    {
        play_sound_effect(4);
        gGameSubState = 6;
    }
}

void field_menu_close_anim(void)
{
    if (gUnk_03000440.unk84 <= 12)
        write_tilemap_rect(12, 2, 18, 1, gUnk_083B4AE0[0x1F - gUnk_03000440.unk84], REG_BG0CNT, 0);
    if ((u8)(gUnk_03000440.unk84 - 2) <= 12)
        write_tilemap_rect(12, 2, 18, 3, gUnk_083B4AE0[0x2E - gUnk_03000440.unk84], REG_BG0CNT, 0);
    if ((u8)(gUnk_03000440.unk84 - 4) <= 12)
        write_tilemap_rect(12, 2, 18, 5, gUnk_083B4AE0[0x3D - gUnk_03000440.unk84], REG_BG0CNT, 0);
    if ((u8)(gUnk_03000440.unk84 - 6) <= 12)
        write_tilemap_rect(12, 2, 18, 7, gUnk_083B4AE0[0x4C - gUnk_03000440.unk84], REG_BG0CNT, 0);
    if (gUnk_03000440.unk84 == 10)
    {
        lz_decompress_dispatch(gUnk_08487814, (void *)0x06002400);
        set_tilemap_and_decompress_bg(0x15, 9, gUnk_08488690, REG_BG0CNT, 0x120);
    }
    if (gUnk_03000440.unk84 == 12)
        vram_fill_tilemap_rect(9, 4, 0x15, 9, REG_BG0CNT, 0);
    if (++gUnk_03000440.unk84 > 18)
        sub_08044094();
}

void field_menu_select_start(void)
{
    switch (gUnk_03000440.unk8E)
    {
    case 0:
        vram_fill_tilemap_rect(13, 10, 17, 3, REG_BG0CNT, 0);
        gUnk_03000440.unk88 = 1;
        break;
    case 1:
        vram_fill_tilemap_rect(13, 2, 17, 1, REG_BG0CNT, 0);
        vram_fill_tilemap_rect(13, 8, 17, 5, REG_BG0CNT, 0);
        gUnk_03000440.unk88 = 3;
        break;
    case 2:
        vram_fill_tilemap_rect(13, 4, 17, 1, REG_BG0CNT, 0);
        vram_fill_tilemap_rect(13, 6, 17, 7, REG_BG0CNT, 0);
        gUnk_03000440.unk88 = 5;
        break;
    default:
        vram_fill_tilemap_rect(13, 6, 17, 1, REG_BG0CNT, 0);
        vram_fill_tilemap_rect(13, 4, 17, 9, REG_BG0CNT, 0);
        gUnk_03000440.unk88 = 7;
        break;
    }
    clear_battle_sprite_slot(0, 1);
    clear_battle_sprite_slot(10, 7);
    gGameSubState++;
}

void field_menu_select_collapse(void)
{
    write_tilemap_rect(12, 2, 18, gUnk_03000440.unk88 - 1, gUnk_083B4AE0[gUnk_03000440.unk8E * 13 + 0x1F], REG_BG0CNT, 0);
    vram_fill_tilemap_rect(12, 1, 18, gUnk_03000440.unk88 + 1, REG_BG0CNT, 0);
    if (--gUnk_03000440.unk88 == 0)
    {
        lz_decompress_dispatch(gUnk_084C1C14, (void *)0x060017E0);
        copy_obj_palette_to_buffer();
        gUnk_03000440.unk84 = 0;
        if (gUnk_03000440.unk8E == 0)
            sound_stop_all_with_fade_guard(0x10);
        gGameSubState++;
    }
}

void field_menu_select_slide(void)
{
    if (gUnk_03000440.unk8E != 2 && gUnk_03000440.unk84 <= 16)
    {
        blend_obj_palettes_to_color_0803F684(0, gUnk_03000440.unk84 * 2, 0x1FFF);
        blend_obj_palettes_to_color_0803F998(0, gUnk_03000440.unk84 * 2, 0xFFFF);
        gUnk_03000440.unk84++;
    }
    write_tilemap_rect(12, 2, 18 - gUnk_03000440.unk88, 0, gUnk_083B4AE0[gUnk_03000440.unk8E * 13 + 0x1F], REG_BG0CNT, 0);
    write_tilemap_rect(1, 2, 30 - gUnk_03000440.unk88, 0, gUnk_083B4AE0[0x47], REG_BG0CNT, 0);
    if (++gUnk_03000440.unk88 == 19)
        gGameSubState++;
}

// Runs the chosen entry: Medawatch (game state 2), Item (mode 2 state 4), Vehicle, Save (mode 2 state 5).
void field_menu_run_choice(void)
{
    switch (gUnk_03000440.unk8E)
    {
    case 0:
        play_song(7);
        gUnk_03000440.unk8F = 0;
        gGameState = 2;
        gGameSubState = 0;
        clear_battle_sprite_slot(0x28, 0x57);
        break;
    case 1:
        gGameMode = 2;
        gGameState = 4;
        gGameSubState = 0;
        clear_battle_sprite_slot(0x28, 0x57);
        break;
    case 2:
        sub_0804765C(1);
        break;
    default:
        gUnk_03000588 = 0;
        gGameMode = 2;
        gGameState = 5;
        gGameSubState = 0;
        clear_battle_sprite_slot(0x28, 0x57);
        break;
    }
}

void field_menu_return_init(void)
{
    gUnk_03000588 = 1;
    if (gUnk_03000440.unk8E != 2)
    {
        REG_DISPCNT &= 0xF1FF;
        DmaSet(3, gUnk_084E2E38, 0x0202F9E0, 0x84000008);
        update_battle_field_frame();
        sub_080487E4();
        setup_blend_effect(0x40, 0x2F00, 5, 16, 16, 16, 12, 10, 0);
        REG_DISPCNT |= 0xF60;
    }
    gUnk_03000440.unk88 = 18;
    gUnk_03000440.unk84 = 0;
    gGameSubState++;
}

void field_menu_return_slide(void)
{
    if (gUnk_03000440.unk8E != 2 && gUnk_03000440.unk84 <= 16)
    {
        blend_effect_update();
        blend_obj_palettes_to_color_0803F684(0, 32 - gUnk_03000440.unk84 * 2, 0x1FFF);
        blend_obj_palettes_to_color_0803F998(0, 32 - gUnk_03000440.unk84 * 2, 0xFFFF);
        gUnk_03000440.unk84++;
    }
    gUnk_03000440.unk88--;
    write_tilemap_rect(12, 2, 18 - gUnk_03000440.unk88, 0, gUnk_083B4AE0[gUnk_03000440.unk8E * 13 + 0x1F], REG_BG0CNT, 0);
    vram_fill_tilemap_rect(1, 2, 17 - gUnk_03000440.unk88, 0, REG_BG0CNT, 0);
    if (gUnk_03000440.unk88 == 0)
    {
        gVBlankCallback = nullsub_08000840;
        gUnk_03000440.unk88 = gUnk_03000440.unk8E * 2 + 1;
        gUnk_03000440.unk84 = 0;
        gGameSubState++;
    }
}

void field_menu_return_expand(void)
{
    write_tilemap_rect(12, 2, 18, gUnk_03000440.unk84 + 1, gUnk_083B4AE0[gUnk_03000440.unk8E * 13 + 0x1F], REG_BG0CNT, 0);
    vram_fill_tilemap_rect(12, 1, 18, gUnk_03000440.unk84, REG_BG0CNT, 0);
    if (gUnk_03000440.unk84 + 1 == gUnk_03000440.unk88)
    {
        switch (gUnk_03000440.unk8E)
        {
        case 0:
            write_tilemap_rect(12, 2, 18, 3, gUnk_083B4AE0[0x2C], REG_BG0CNT, 0);
            write_tilemap_rect(12, 2, 18, 5, gUnk_083B4AE0[0x39], REG_BG0CNT, 0);
            write_tilemap_rect(12, 2, 18, 7, gUnk_083B4AE0[0x46], REG_BG0CNT, 0);
            break;
        case 1:
            write_tilemap_rect(12, 2, 18, 1, gUnk_083B4AE0[0x1F], REG_BG0CNT, 0);
            write_tilemap_rect(12, 2, 18, 5, gUnk_083B4AE0[0x39], REG_BG0CNT, 0);
            write_tilemap_rect(12, 2, 18, 7, gUnk_083B4AE0[0x46], REG_BG0CNT, 0);
            break;
        case 2:
            write_tilemap_rect(12, 2, 18, 1, gUnk_083B4AE0[0x1F], REG_BG0CNT, 0);
            write_tilemap_rect(12, 2, 18, 3, gUnk_083B4AE0[0x2C], REG_BG0CNT, 0);
            write_tilemap_rect(12, 2, 18, 7, gUnk_083B4AE0[0x46], REG_BG0CNT, 0);
            break;
        default:
            write_tilemap_rect(12, 2, 18, 1, gUnk_083B4AE0[0x1F], REG_BG0CNT, 0);
            write_tilemap_rect(12, 2, 18, 3, gUnk_083B4AE0[0x2C], REG_BG0CNT, 0);
            write_tilemap_rect(12, 2, 18, 5, gUnk_083B4AE0[0x39], REG_BG0CNT, 0);
            break;
        }
        set_tilemap_and_decompress_bg(0x15, 9, gUnk_08488644, REG_BG0CNT, 0x120);
        divide_by_10000(gUnk_03000440.unk9E, gUnk_03002B70.money);
        render_text_sprites_08040DB8(gUnk_03000440.unk9E, 10, 0x17, 10, 5, 15, 2, 0);
        field_menu_init_cursor();
        gGameSubState = 2;
    }
    else
    {
        gUnk_03000440.unk84++;
    }
}

void field_menu_init_cursor(void)
{
    lz_decompress_dispatch(gUnk_084C7174, (void *)0x06016C00);
    DmaSet(3, gUnk_084E2E58, 0x050003C0, 0x84000008);
    gUnk_03002C30[0].unk0 = 0xC004;
    gUnk_03002C30[0].unk2 = 0x88;
    gUnk_03002C30[0].unk4 = gUnk_03000440.unk8E * 16 + 8;
    gUnk_03002C30[0].unkA = 14;
    gUnk_03002C30[0].unk1C = 0;
    gUnk_03002C30[0].unkB = 0xFF;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0], 0);
}

// Game state 2: the Medawatch menu (Medabots / Medals / Medaparts, cursor gUnk_03000440.unk8F).
void medawatch_menu_update(void)
{
    gMedawatchMenuHandlers[gGameSubState]();
}

void medawatch_menu_load_gfx(void)
{
    reset_bg_scroll();
    REG_DISPCNT &= 0xF1FF;
    REG_BG1CNT = 0x1805;
    REG_BG2CNT = 0x1906;
    REG_BG3CNT = 0x1A07;
    lz_decompress_dispatch(gUnk_084E30D8, (void *)0x06004000);
    medawatch_menu_load_icon();
    set_tilemap_and_decompress_bg(0, 0, gUnk_084EF6A0, REG_BG1CNT, 0);
    set_tilemap_and_decompress_bg(0, 0, gUnk_084F023C, REG_BG2CNT, 0);
    set_tilemap_and_decompress_bg(0, 0, gUnk_084F0F2C, REG_BG3CNT, 0);
    DmaSet(3, gUnk_084F24E0, 0x0202FA00, 0x84000060);
    write_tilemap_rect(4, 4, 5, 9, gUnk_083B4AE0[0x48], REG_BG1CNT, 0);
    REG_DISPCNT |= 0x1F60;
    gUnk_03000440.unk84 = 0;
    gGameSubState++;
}

void medawatch_menu_fade_in(void)
{
    medawatch_scroll_bg3();
    if (gUnk_03000440.unk84 <= 8)
    {
        blend_obj_palettes_to_color_0803F684(0, 32 - gUnk_03000440.unk84 * 4, 0x1FFF);
        blend_obj_palettes_to_color_0803F998(0, 32 - gUnk_03000440.unk84 * 4, 0xFFFF);
        gUnk_03000440.unk84++;
    }
    else
    {
        medawatch_menu_init_cursor();
        gGameSubState++;
    }
}

void medawatch_menu_handle_input(void)
{
    medawatch_scroll_bg3();
    process_sprite_anim_commands(gUnk_083B5F80[0], 0);
    if (KEYS_LO(gRepeatKeys) & 0x40)
    {
        if (gUnk_03000440.unk8F == 0)
            gUnk_03000440.unk8F = 2;
        else
            gUnk_03000440.unk8F--;
        play_sound_effect(2);
        medawatch_menu_load_icon();
        gUnk_03002C30[0].unk2 = 0x88 - gUnk_03000440.unk8F * 8;
        gUnk_03002C30[0].unk4 = gUnk_03000440.unk8F * 24 + 32;
    }
    if (KEYS_LO(gRepeatKeys) & 0x80)
    {
        if (gUnk_03000440.unk8F == 2)
            gUnk_03000440.unk8F = 0;
        else
            gUnk_03000440.unk8F++;
        play_sound_effect(2);
        medawatch_menu_load_icon();
        gUnk_03002C30[0].unk2 = 0x88 - gUnk_03000440.unk8F * 8;
        gUnk_03002C30[0].unk4 = gUnk_03000440.unk8F * 24 + 32;
    }
    if (KEYS_LO(gNewKeys) & 2)
    {
        play_sound_effect(5);
        gGameSubState++;
    }
    if (KEYS_LO(gNewKeys) & 1)
    {
        play_sound_effect(4);
        init_battle_sprite_entry_08040B90(gUnk_083B5F80[1], 0);
        set_blend_effect_mode(6, 0x3F, 0x20);
        gUnk_03000440.unk84 = 0;
        gGameSubState = 8;
    }
}

void medawatch_menu_exit_start(void)
{
    medawatch_scroll_bg3();
    clear_battle_sprite_slot(0, 1);
    copy_obj_palette_to_buffer();
    gUnk_03000440.unk84 = 0;
    sound_stop_all_with_fade_guard(8);
    gGameSubState++;
}

void medawatch_menu_exit_fade(void)
{
    medawatch_scroll_bg3();
    if (gUnk_03000440.unk84 <= 8)
    {
        blend_obj_palettes_to_color_0803F684(0, gUnk_03000440.unk84 * 4, 0x1FFF);
        blend_obj_palettes_to_color_0803F998(0, gUnk_03000440.unk84 * 4, 0xFFFF);
        gUnk_03000440.unk84++;
    }
    else
    {
        gGameSubState++;
    }
}

void medawatch_menu_return_to_field_menu(void)
{
    play_song(6);
    gGameState = 1;
    gGameSubState = 16;
}

void medawatch_menu_select_fade(void)
{
    medawatch_scroll_bg3();
    process_sprite_anim_commands(gUnk_083B5F80[1], 0);
    if (update_blend_effect())
        gGameSubState++;
}

// Saves the BG tiles at 0x06002800 and enters game state 3 (Medabots), 4 (Medals) or 5 (Medaparts).
void medawatch_menu_run_choice(void)
{
    DmaSet(3, 0x06002800, gUnk_02020800, 0x84000200);
    switch (gUnk_03000440.unk8F)
    {
    case 0:
        sub_0803F624((u8 *)&gUnk_03000440 + 0x50, 0x14, 0);
        gGameState = 3;
        gGameSubState = 0;
        break;
    case 1:
        sub_0803F624((u8 *)&gUnk_03000440 + 0x3C, 0x14, 0);
        gGameState = 4;
        gGameSubState = 0;
        break;
    default:
        sub_0803F624((u8 *)&gUnk_03000440 + 0x3C, 0x14, 0);
        gGameState = 5;
        gGameSubState = 0;
        break;
    }
}

// Back from a Medawatch submenu: reloads the menu graphics and restores the saved BG tiles.
void medawatch_menu_return_init(void)
{
    reset_bg_scroll();
    REG_DISPCNT &= 0xF0FF;
    REG_BG1CNT = 0x500;
    REG_BG1CNT = 0x1805;
    REG_BG2CNT = 0x1906;
    REG_BG3CNT = 0x1A07;
    lz_decompress_dispatch(gUnk_084E30D8, (void *)0x06004000);
    medawatch_menu_load_icon();
    DmaSet(3, gUnk_02020800, 0x06002800, 0x84000200);
    set_tilemap_and_decompress_bg(0, 0, gUnk_084EF6A0, REG_BG1CNT, 0);
    set_tilemap_and_decompress_bg(0, 0, gUnk_084F023C, REG_BG2CNT, 0);
    set_tilemap_and_decompress_bg(0, 0, gUnk_084F0F2C, REG_BG3CNT, 0);
    DmaSet(3, gUnk_084F24E0, 0x05000000, 0x84000060);
    write_tilemap_rect(4, 4, 5, 9, gUnk_083B4AE0[0x48], REG_BG1CNT, 0);
    REG_DISPCNT |= 0x1F60;
    set_blend_effect_mode(5, 0x3F, 0x20);
    gUnk_03000440.unk84 = 0;
    gGameSubState++;
}

void medawatch_menu_return_fade(void)
{
    medawatch_scroll_bg3();
    if (update_blend_effect())
    {
        medawatch_menu_init_cursor();
        gGameSubState++;
    }
}

void medawatch_menu_return_done(void)
{
    medawatch_scroll_bg3();
    gGameSubState = 2;
}

// Watch face icon for the selected entry.
void medawatch_menu_load_icon(void)
{
    const u8 *src;

    switch (gUnk_03000440.unk8F)
    {
    case 0:
        src = gUnk_084C1C24;
        break;
    case 1:
        src = gUnk_084C1E04;
        break;
    default:
        src = gUnk_084C1FD4;
        break;
    }
    lz_decompress_dispatch(src, (void *)0x06007E00);
}

void medawatch_menu_init_cursor(void)
{
    lz_decompress_dispatch(gUnk_084C7174, (void *)0x06016C00);
    DmaSet(3, gUnk_084E2E58, 0x050003C0, 0x84000008);
    gUnk_03002C30[0].unk0 = 0xC004;
    gUnk_03002C30[0].unk2 = 0x88 - gUnk_03000440.unk8F * 8;
    gUnk_03002C30[0].unk4 = gUnk_03000440.unk8F * 24 + 32;
    gUnk_03002C30[0].unkA = 14;
    gUnk_03002C30[0].unk1C = 0;
    gUnk_03002C30[0].unkB = 0xFF;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0], 0);
}

// Scrolls the background pattern diagonally every other frame.
void medawatch_scroll_bg3(void)
{
    if (gFrameCounter & 1)
    {
        gBg3Scroll.x--;
        gBg3Scroll.y++;
    }
}

// Game state 3: the Medabots screen (Medawatch > Medabots). Paused while the serial link is busy.
void medabots_screen_update(void)
{
    if (sub_0803EED8() == 0)
    {
        if (gUnk_03000430 == 2)
        {
            u32 fill = 0x200;
            CpuFastSet(&fill, gUnk_03002414->unkB84, 0x01000100);
        }
        gMedabotsScreenHandlers[gGameSubState]();
    }
}

void medabots_screen_load_gfx(void)
{
    u32 zero;

    switch (gUnk_03000440.unk139)
    {
    case 0:
        sub_08043CA8();
        if (gUnk_03000440.unk56 == 1)
            setup_overworld_scene_from_position();
        REG_DISPCNT &= 0xF0FF;
        REG_BG0CNT = 0x500;
        REG_BG1CNT = 0x1801;
        REG_BG2CNT = 0x1902;
        REG_BG3CNT = 0x1A03;
        lz_decompress_dispatch(gUnk_084E5650, (void *)0x06004000);
        lz_decompress_dispatch(gUnk_084C48B4, (void *)0x06006000);
        lz_decompress_dispatch(gUnk_084C4A34, (void *)0x06006200);
        lz_decompress_dispatch(gUnk_084C7428, (void *)0x06016C00);
        lz_decompress_dispatch(gUnk_084C6A98, (void *)0x06017400);
        gUnk_03000440.unk139++;
        break;
    case 1:
        if (gUnk_03000440.unk56 == 1)
            setup_overworld_scene_from_position();
        set_tilemap_and_decompress_bg(0, 0, gUnk_084EF2D8, REG_BG0CNT, 0x200);
        set_tilemap_and_decompress_bg(0, 0, gUnk_084EF95C, REG_BG1CNT, 0x200);
        set_tilemap_and_decompress_bg(0, 0, gUnk_084F02B8, REG_BG2CNT, 0x200);
        set_tilemap_and_decompress_bg(0, 0, gUnk_084F122C, REG_BG3CNT, 0x200);
        if (gUnk_03000440.unk56 == 1)
        {
            CpuFastSet(gUnk_084F2680, gPaletteBackupBg, 0x60);
            CpuFastSet(gUnk_0850DEF8, gPaletteBackup, 0x40);
            CpuFastSet(gUnk_0850DD18, (void *)0x0202F9A0, 8);
            CpuFastSet(gUnk_0850DD18 + 0x10, (void *)0x0202F9C0, 8);
            CpuFastSet(gUnk_084E2EB8, (void *)0x0202F980, 8);
            CpuFastSet(gUnk_084E2ED8, (void *)0x0202F9E0, 8);
            gUnk_03000440.unk84 = 0;
        }
        else
        {
            CpuFastSet(gUnk_084F2680, (void *)0x05000000, 0x60);
            CpuFastSet(gUnk_0850DEF8, (void *)0x05000200, 0x40);
            CpuFastSet(gUnk_0850DD18, (void *)0x050003A0, 8);
            CpuFastSet(gUnk_0850DD18 + 0x10, (void *)0x050003C0, 8);
            CpuFastSet(gUnk_084E2EB8, (void *)0x05000380, 8);
            CpuFastSet(gUnk_084E2ED8, (void *)0x050003E0, 8);
            set_blend_effect_mode(5, 0x3F, 0x20);
        }
        zero = 0;
        CpuFastSet(&zero, gUnk_03002C30, 0x01000800);
        REG_DISPCNT |= 0x1F40;
        REG_DISPCNT &= 0xFFDF;
        gUnk_03000440.unk139++;
        break;
    case 2:
        if (gUnk_03000440.unk56 == 1)
            setup_overworld_scene_from_position();
        gUnk_03000440.unk96 = 1;
        sub_08004FD0();
        sub_08005000();
        sub_08004E98();
        sub_0800508C();
        sub_08005118();
        sub_0800519C();
        sub_0800522C();
        sub_08005948();
        sub_0800750C();
        if (gUnk_03000440.unk56 == 0)
        {
            sub_0800529C();
            if (gUnk_03000440.unk50 == 3)
                play_song(7);
        }
        else if (gUnk_03000440.unk52 & 0x80)
        {
            medabots_screen_start_reorder_orbit();
        }
        gGameSubState++;
        gUnk_03000440.unk139 = 0;
        break;
    }
}

void medabots_screen_fade_in(void)
{
    struct Unk_03000440 *s;
    u8 *flag;

    medabots_scroll_bg3();
    update_battle_sprite_orbit_clockwise(0);
    update_battle_sprite_orbit_clockwise(1);
    update_battle_sprite_orbit_clockwise(2);
    update_battle_sprite_orbit_clockwise(3);
    setup_overworld_scene_from_position();
    update_battle_icon_blink_and_orbit();
    check_and_update_battle_sprite_orbit();
    s = &gUnk_03000440;
    flag = &s->unk56;
    if (*flag == 1)
    {
        if (s->unk84 > 8)
            goto done;
        blend_obj_palettes_to_color_0803F684(0, 32 - s->unk84 * 4, 0xFFFF);
        blend_obj_palettes_to_color_0803F998(0, 32 - s->unk84 * 4, 0xF0FF);
        s->unk84++;
    }
    else if (update_blend_effect())
    {
    done:
        *flag = 0;
        gGameSubState++;
    }
}

void medabots_screen_handle_input(void)
{
    medabots_scroll_bg3();
    update_battle_sprite_orbit_clockwise(0);
    update_battle_sprite_orbit_clockwise(1);
    update_battle_sprite_orbit_clockwise(2);
    update_battle_sprite_orbit_clockwise(3);
    setup_overworld_scene_from_position();
    update_battle_icon_blink_and_orbit();
    check_and_update_battle_sprite_orbit();
    team_select_draw_pick_markers();
    if (medabots_screen_reorder_input() == 0 && medabots_screen_cursor_input() == 0)
    {
        if (KEYS_LO(gNewKeys) & 2)
            medabots_screen_cancel_input();
        else if (KEYS_LO(gNewKeys) & 1)
            team_select_confirm_pick();
        else if (KEYS_LO(gNewKeys) & 8)
            team_select_finish_input();
    }
}

void medabots_screen_exit_start(void)
{
    medabots_scroll_bg3();
    update_battle_sprite_orbit_clockwise(0);
    update_battle_sprite_orbit_clockwise(1);
    update_battle_sprite_orbit_clockwise(2);
    update_battle_sprite_orbit_clockwise(3);
    setup_overworld_scene_from_position();
    check_and_update_battle_sprite_orbit();
    set_blend_effect_mode(6, 0x3F, 0x20);
    gUnk_03000440.unk84 = 0;
    gGameSubState++;
}

void medabots_screen_exit_fade(void)
{
    medabots_scroll_bg3();
    update_battle_sprite_orbit_clockwise(0);
    update_battle_sprite_orbit_clockwise(1);
    update_battle_sprite_orbit_clockwise(2);
    update_battle_sprite_orbit_clockwise(3);
    setup_overworld_scene_from_position();
    check_and_update_battle_sprite_orbit();
    if (update_blend_effect())
        gGameSubState++;
}

void medabots_screen_return_to_medawatch(void)
{
    CpuFastSet(gUnk_084E2E38, (void *)0x050003E0, 8);
    clear_battle_sprite_slot(0, 0x80);
    gUnk_03000440.unk96 = 0;
    gUnk_03000430 = 0;
    gGameState = 2;
    gGameSubState = 16;
}

// Sub-states 8/9: A on a Medabot in the list fades out, then 16 (medabot_detail_load_gfx) opens its
// detail ("Build") screen (runtime-checked: A -> sub-state 9 -> 18).
void sub_08003F28(void)
{
    medabots_scroll_bg3();
    update_battle_sprite_orbit_clockwise(0);
    update_battle_sprite_orbit_clockwise(1);
    update_battle_sprite_orbit_clockwise(2);
    update_battle_sprite_orbit_clockwise(3);
    setup_overworld_scene_from_position();
    update_battle_icon_blink_and_orbit();
    check_and_update_battle_sprite_orbit();
    copy_obj_palette_to_buffer();
    gUnk_03000440.unk84 = 0;
    gGameSubState++;
}

void sub_08003F74(void)
{
    medabots_scroll_bg3();
    update_battle_sprite_orbit_clockwise(0);
    update_battle_sprite_orbit_clockwise(1);
    update_battle_sprite_orbit_clockwise(2);
    update_battle_sprite_orbit_clockwise(3);
    setup_overworld_scene_from_position();
    update_battle_icon_blink_and_orbit();
    check_and_update_battle_sprite_orbit();
    if (gUnk_03000440.unk84 <= 8)
    {
        blend_obj_palettes_to_color_0803F684(0, gUnk_03000440.unk84 * 4, 0xFFFF);
        blend_obj_palettes_to_color_0803F998(0, gUnk_03000440.unk84 * 4, 0xF0FF);
        gUnk_03000440.unk84++;
    }
    else
    {
        gGameSubState = 16;
    }
}

// guess: sub-states 11/12 show message 22 in a text window, then return to input.
void sub_08003FE8(void)
{
    medabots_scroll_bg3();
    update_battle_sprite_orbit_clockwise(0);
    update_battle_sprite_orbit_clockwise(1);
    update_battle_sprite_orbit_clockwise(2);
    update_battle_sprite_orbit_clockwise(3);
    setup_overworld_scene_from_position();
    check_and_update_battle_sprite_orbit();
    text_window_init(1, 2, 0);
    gGameSubState++;
}

void sub_08004028(void)
{
    medabots_scroll_bg3();
    update_battle_sprite_orbit_clockwise(0);
    update_battle_sprite_orbit_clockwise(1);
    update_battle_sprite_orbit_clockwise(2);
    update_battle_sprite_orbit_clockwise(3);
    setup_overworld_scene_from_position();
    check_and_update_battle_sprite_orbit();
    if (run_message(gUnk_083B53F8[22]))
        gGameSubState = 2;
}

void medabot_detail_load_gfx(void)
{
    u32 zero;

    if (gUnk_03000440.unk56 == 0)
        setup_overworld_scene_from_position();
    REG_DISPCNT &= 0xF0FF;
    REG_BG0CNT = 0x500;
    REG_BG1CNT = 0x1801;
    REG_BG2CNT = 0x1902;
    REG_BG3CNT = 0x1A03;
    lz_decompress_dispatch(gUnk_084E61CC, (void *)0x06004000);
    lz_decompress_dispatch(gUnk_084C48B4, (void *)0x06006000);
    lz_decompress_dispatch(gUnk_084C4A34, (void *)0x06006200);
    lz_decompress_dispatch(gUnk_084C3208, (void *)0x06007480);
    lz_decompress_dispatch(gUnk_084C33DC, (void *)0x06006800);
    lz_decompress_dispatch(gUnk_084C4DB0, (void *)0x06006E00);
    lz_decompress_dispatch(gUnk_084C7318, (void *)0x06017E00);
    lz_decompress_dispatch(gUnk_084C6A98, (void *)0x06017400);
    set_tilemap_and_decompress_bg(0, 0, gUnk_084EF310, REG_BG0CNT, 0x200);
    set_tilemap_and_decompress_bg(0, 0, gUnk_084EF9C8, REG_BG1CNT, 0x200);
    set_tilemap_and_decompress_bg(0, 0, gUnk_084F03EC, REG_BG2CNT, 0x200);
    set_tilemap_and_decompress_bg(0, 0, gUnk_084F13C0, REG_BG3CNT, 0x200);
    if (gUnk_03000440.unk56 == 0)
    {
        CpuFastSet(gUnk_084F2820, gPaletteBackupBg, 0x70);
        CpuFastSet(gUnk_0850DEF8, gPaletteBackup, 0x40);
        CpuFastSet(gUnk_0850DD58, (void *)0x0202F980, 8);
        CpuFastSet(gUnk_0850DD58 + 0x20, (void *)0x0202F9A0, 8);
        CpuFastSet(gUnk_0850DD58 - 0x20, (void *)0x0202F9E0, 8);
        CpuFastSet(gUnk_084E2E58, (void *)0x0202F9C0, 8);
        gUnk_03000440.unk5A = 0;
        sub_080059D0();
        gUnk_03000440.unk84 = 0;
    }
    else
    {
        CpuFastSet(gUnk_084F2820, (void *)0x05000000, 0x70);
        CpuFastSet(gUnk_0850DEF8, (void *)0x05000200, 0x40);
        CpuFastSet(gUnk_0850DD58, (void *)0x05000380, 8);
        CpuFastSet(gUnk_0850DD58 + 0x20, (void *)0x050003A0, 8);
        CpuFastSet(gUnk_0850DD58 - 0x20, (void *)0x050003E0, 8);
        CpuFastSet(gUnk_084E2E58, (void *)0x050003C0, 8);
        set_blend_effect_mode(5, 0x3F, 0x20);
    }
    zero = 0;
    CpuFastSet(&zero, gUnk_03002C30, 0x01000800);
    REG_DISPCNT |= 0x1F40;
    REG_DISPCNT &= 0xFFDF;
    gUnk_03000440.unk53 = 0;
    gUnk_03000440.unk96 = 1;
    medabot_detail_draw_row_icon_0(0);
    medabot_detail_draw_row_icon_1(0);
    medabot_detail_draw_row_icon_2(0);
    medabot_detail_draw_row_icon_3(0);
    medabot_detail_draw_row_icon_4(0);
    sub_08005AD0();
    sub_08005B44();
    sub_08005C10();
    sub_08005BB4();
    medabot_detail_draw_head_name();
    medabot_detail_draw_head_skill_icon();
    medabot_detail_draw_rarm_name();
    medabot_detail_draw_rarm_skill_icon();
    medabot_detail_draw_larm_name();
    medabot_detail_draw_larm_skill_icon();
    medabot_detail_draw_legs_name();
    medabot_detail_draw_legs_skill_icon();
    medabot_detail_draw_legs_type_icon();
    decompress_sprite_from_game_state();
    init_battle_medabot_sprites(gUnk_03000440.unk98, gUnk_03000440.unk99, gUnk_03000440.unk9A, gUnk_03000440.unk9B,
                                0, 6, 0xA8, 0x20, gUnk_03000440.unk5E, 1, 5);
    medabot_detail_place_row_arrows();
    if (gUnk_03000440.unk56)
        init_scene_state();
    gUnk_03000440.unk84 = 0;
    gGameSubState++;
}

