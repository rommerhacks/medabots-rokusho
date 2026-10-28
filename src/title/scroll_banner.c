// Mode-2 state 19 (scene_dispatch_and_tick, sub-states gScrollBannerStates): loads a background strip into a window,
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
    dma3_copy_or_decompress(gScrollBannerStripTiles, gDecompressBuffer);
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
    decompress_and_write_tilemap(gScrollBannerBg3Tilemap, REG_BG3CNT);
    size = dma3_copy_or_decompress(gScrollBannerBgTiles, gDecompressBuffer);
    CpuCopy16(gDecompressBuffer, (void *)0x06004000, size);
    size2 = dma3_copy_or_decompress(gScrollBannerBgTiles2, gDecompressBuffer);
    CpuCopy16(gDecompressBuffer, (void *)(size + 0x06004000), size2);
    tilemap_offset_tiles_and_palette(size >> 5, 0, 0x1F);
    CpuFastSet(gScrollBannerBgPalette, (void *)PLTT, 0x48);
    REG_DISPCNT |= 0x400;
    REG_DISPCNT |= 0x800;
    REG_WIN0H = 0xF0;
    REG_WIN0V = 0x4858;
    REG_WININ = 0x3F3F;
    REG_WINOUT = 0x3B3B;
    gBg2Scroll.y = 0x58;
    gMenuWork->frame = 0;
    init_blend_effect(gMenuWork->blend, 0x10, 0, -1, 0xC0);
    gGameSubState++;
}

void scene_scroll_with_fade(void) {
    struct MenuWork *menu;
    struct Vec16 *scroll;

    if (blend_fade_step_08065598(gMenuWork->blend))
        gGameSubState++;
    scroll = &gBg2Scroll;
    menu = gMenuWork;
    scroll->y = (u32)(menu->frame * 16 + 0x1B8) % 512;
    scroll->x = (s16)(menu->frame & 0x20) ? 0x100 : 0;
    menu->frame++;
}

void update_scroll_animation_step(void) {
    struct MenuWork *menu;
    struct Vec16 *scroll;

    scroll = &gBg2Scroll;
    menu = gMenuWork;
    scroll->y = (u32)(menu->frame * 16 + 0x1B8) % 512;
    scroll->x = (s16)(menu->frame & 0x20) ? 0x100 : 0;
    menu->frame++;
    if (KEYS_LO(gRepeatKeys) & 1) {
        init_blend_effect(menu->blend, 0, 0, 1, 0xC0);
        gGameSubState++;
    }
}

void scene_fade_and_scroll_camera(void) {
    struct MenuWork *menu;
    struct Vec16 *scroll;

    if (blend_fade_step_08065598(gMenuWork->blend))
        gGameSubState = 0;
    scroll = &gBg2Scroll;
    menu = gMenuWork;
    scroll->y = (u32)(menu->frame * 16 + 0x1B8) % 512;
    scroll->x = (s16)(menu->frame & 0x20) ? 0x100 : 0;
    menu->frame++;
}

void scene_dispatch_and_tick(void) {
    struct FuncTable4 states = gScrollBannerStates;

    states.f[gGameSubState]();
    if (gFrameCounter & 1)
        gBg3Scroll.x++;
}
