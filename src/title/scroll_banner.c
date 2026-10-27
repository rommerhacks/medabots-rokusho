// Mode-2 state 19 (scene_dispatch_and_tick, sub-states gUnk_080AFAD0): loads a background strip into a window,
// scrolls BG2 behind it and fades in/out on A. No direct writer of state 19 was found; purpose unknown.
#include "global.h"

void scroll_banner_init(void) {
    u8 *src;
    u8 *dst;
    s32 i;
    u32 size;
    u32 size2;

    clear_battle_sprite_slot(0, 0x80);
    reset_bg_scroll();
    REG_DISPCNT = 0x2060;
    REG_BG2CNT = 0xDB06;
    REG_BG3CNT = 0x1F07;
    dma3_copy_or_decompress(gUnk_087A88CC, gDecompressBuffer);
    dst = (u8 *)0x0600D800;
    src = gDecompressBuffer;
    for (i = 31; i >= 0; i--) {
        CpuFastSet(src, dst, 0x10);
        dst += 0x40;
        src += 0x80;
    }
    src = (u8 *)0x02030040;
    for (i = 31; i >= 0; i--) {
        CpuFastSet(src, dst, 0x10);
        dst += 0x40;
        src += 0x80;
    }
    src = (u8 *)0x02031000;
    for (i = 31; i >= 0; i--) {
        CpuFastSet(src, dst, 0x10);
        dst += 0x40;
        src += 0x80;
    }
    src = (u8 *)0x02031040;
    for (i = 31; i >= 0; i--) {
        CpuFastSet(src, dst, 0x10);
        dst += 0x40;
        src += 0x80;
    }
    decompress_and_write_tilemap(gUnk_087A1084, REG_BG3CNT);
    size = dma3_copy_or_decompress(gUnk_087A92D4, gDecompressBuffer);
    CpuCopy16(gDecompressBuffer, (void *)0x06004000, size);
    size2 = dma3_copy_or_decompress(gUnk_087A046C, gDecompressBuffer);
    CpuCopy16(gDecompressBuffer, (void *)(size + 0x06004000), size2);
    tilemap_offset_tiles_and_palette(size >> 5, 0, 0x1F);
    CpuFastSet(gUnk_087A034C, (void *)PLTT, 0x48);
    REG_DISPCNT |= 0x400;
    REG_DISPCNT |= 0x800;
    REG_WIN0H = 0xF0;
    REG_WIN0V = 0x4858;
    REG_WININ = 0x3F3F;
    REG_WINOUT = 0x3B3B;
    gBg2Scroll.y = 0x58;
    gUnk_03006F74->unk3A = 0;
    init_blend_effect(gUnk_03006F74->unk50, 0x10, 0, -1, 0xC0);
    gGameSubState++;
}

void scene_scroll_with_fade(void) {
    struct Unk_03006F74 *s;
    struct Vec16 *b;

    if (blend_fade_step_08065598(gUnk_03006F74->unk50))
        gGameSubState++;
    b = &gBg2Scroll;
    s = gUnk_03006F74;
    b->y = (u32)(s->unk3A * 16 + 0x1B8) % 512;
    b->x = (s16)(s->unk3A & 0x20) ? 0x100 : 0;
    s->unk3A++;
}

void update_scroll_animation_step(void) {
    struct Unk_03006F74 *s;
    struct Vec16 *b;

    b = &gBg2Scroll;
    s = gUnk_03006F74;
    b->y = (u32)(s->unk3A * 16 + 0x1B8) % 512;
    b->x = (s16)(s->unk3A & 0x20) ? 0x100 : 0;
    s->unk3A++;
    if (KEYS_LO(gRepeatKeys) & 1) {
        init_blend_effect(s->unk50, 0, 0, 1, 0xC0);
        gGameSubState++;
    }
}

void scene_fade_and_scroll_camera(void) {
    struct Unk_03006F74 *s;
    struct Vec16 *b;

    if (blend_fade_step_08065598(gUnk_03006F74->unk50))
        gGameSubState = 0;
    b = &gBg2Scroll;
    s = gUnk_03006F74;
    b->y = (u32)(s->unk3A * 16 + 0x1B8) % 512;
    b->x = (s16)(s->unk3A & 0x20) ? 0x100 : 0;
    s->unk3A++;
}

void scene_dispatch_and_tick(void) {
    struct FuncTable4 t = gUnk_080AFAD0;

    t.f[gGameSubState]();
    if (gFrameCounter & 1)
        gBg3Scroll.x++;
}
