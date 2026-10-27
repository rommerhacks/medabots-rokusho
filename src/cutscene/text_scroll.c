// Mode-2 state 22, entered from a field script (switch_game_mode case 8). Sub-states gUnk_080AFEA8: three
// pages of text lines (gUnk_080AFE9C / line counts gSceneTextLineCounts) scroll up over a 3-D hexagon ring
// (engine/rings_3d.c) with song 5, then everything fades to white and the field resumes. Purpose is a guess
// (story text). Uses text/ and engine/ helpers only.
#include "global.h"

// Line length, 0 for a one-character line.
static int text_line_glyph_count(u8 *s) {
    int n = 0;
    int r;
    while (s[n] != 0)
        n++;
    r = 0;
    if (n != 1)
        r = n;
    return r;
}

static void text_scroll_draw_bar(s32 len, s32 step) {
    u16 buf[32];
    u32 zero = 0;
    CpuFastSet(&zero, buf, 0x01000010);
    if (step <= 13) {
        u16 tile = *(u16 *)0x0600DD3E;
        int i;
        for (i = 0; i < len; i++) {
            int n = step * 29 / 13;
            if (n - i >= 0)
                buf[n - i] = tile;
        }
    }
    if (buf[0] == 0)
        buf[0] = *(u16 *)0x0600D8C0;
    else
        buf[0] = *(u16 *)0x0600D940;
    CpuFastSet(buf, (void *)(((REG_BG0CNT >> 8) & 0x1F) * 0x800 + 0x06000400), 0x10);
}

void text_scroll_shift_row(s32 row, s32 step) {
    u16 buf[32];
    u8 x = gUnk_080AFE96[gMenuWork->cursor];
    if (step <= 14) {
        CpuSet((u8 *)VRAM + ((REG_BG0CNT >> 8) & 0x1F) * 0x800 + x * 2 + 0x100, buf, (30 - x) & 0x1FFFFF);
        CpuSet(buf, (u8 *)VRAM + ((REG_BG0CNT >> 8) & 0x1F) * 0x800 + (x + 1) * 2 + 0x100, (29 - x) & 0x1FFFFF);
    } else {
        int i;
        u16 t;
        CpuFastSet((u8 *)VRAM + ((REG_BG1CNT >> 8) & 0x1F) * 0x800 + row * 64, buf, 0x10);
        buf[31] = *(u16 *)0x0600DD3E | 0x800;
        t = 0;
        for (i = 10; i < 30; i++) {
            if (buf[i] != 0)
                t = buf[31];
            buf[i] = t;
        }
        CpuSet(buf + x, (u8 *)VRAM + ((REG_BG0CNT >> 8) & 0x1F) * 0x800 + x * 2 + 0x100, (30 - x) & 0x1FFFFF);
    }
}

static void text_scroll_draw_line(const u8 *s, u8 row) {
    int len;
    u16 *dst;
    int i;
    int c;
    len = 0;
    while (*s != 0) {
        s++;
        len++;
    }
    s--;
    dst = &((u16 *)(((REG_BG1CNT >> 8) & 0x1F) * 0x800 + 0x06000000))[row * 32 + 29];
    for (i = 0; i < 20; i++) {
        if (i < len) {
            c = *s--;
            if (c == ' ')
                *dst-- = 0;
            else
                *dst-- = ((u16 *)0x0600DD00)[c -= 0x41];
        } else {
            *dst-- = 0;
        }
    }
}

static bool32 text_scroll_slide_in_heading(s32 col, s32 step) {
    int i;
    if (step > 13)
        return TRUE;
    for (i = 0; i < 3; i++)
        CpuSet(&((u16 *)0x0600D800)[(col * 3 + 4 + i) * 32],
               &((u16 *)(((REG_BG0CNT >> 8) & 0x1F) * 0x800 + 0x06000000))[(i - step + 0x11) * 32], 0xD);
    return FALSE;
}

static bool32 text_scroll_slide_out_heading(s32 step) {
    int i;
    int a, b;
    if (step > 3)
        return TRUE;
    for (i = 0; i < 3; i++)
        CpuSet(&((u16 *)(((REG_BG0CNT >> 8) & 0x1F) * 0x800 + VRAM))[((a = i + 4) - step) * 32],
               &((u16 *)(((REG_BG0CNT >> 8) & 0x1F) * 0x800 + VRAM))[((b = i + 3) - step) * 32], 0xD);
    return FALSE;
}

void text_scroll_init(void) {
    u16 pal[64] = {
        0, 0x6B40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x5EE0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0x5280, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x4A40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    };
    u32 zero;
    u32 size;
    int i;

    play_song(5);
    zero = 0;
    CpuFastSet(&zero, (void *)VRAM, 0x01006000);
    clear_battle_sprite_slot(0, 0x80);
    reset_bg_scroll();
    REG_DISPCNT = 0x6060;
    REG_BG0CNT = 0x1B04;
    decompress_and_write_tilemap(gUnk_087A3CFC, REG_BG0CNT);
    REG_BG0CNT = 0x1F04;
    REG_BG1CNT = 0x1E05;
    REG_BG2CNT = 0x3D06;
    REG_BG3CNT = 0x1C07;
    decompress_and_write_tilemap(gUnk_087A3E64, REG_BG2CNT);
    decompress_and_write_tilemap(gUnk_087A40A0, REG_BG3CNT);
    size = dma3_copy_or_decompress(gUnk_087A1410, (void *)0x02030000);
    CpuFastSet((void *)0x02030000, (void *)0x06004000, (size << 9) >> 11);
    CpuFastSet(gUnk_087A13B0, (void *)0x0202FA00, 0x18);
    CpuFastSet(pal, (void *)0x0202F800, 0x20);
    lz_decompress_dispatch(gUnk_08785F34, (void *)0x06010000);
    CpuFastSet(gUnk_0850DEB8, (void *)0x05000200, 8);
    for (i = 0; i < sizeof(gMenuWork->ring_center_x); i++) {
        gMenuWork->ring_center_x[i] = 0x78;
        gMenuWork->ring_center_y[i] = 0x50;
    }
    for (i = 0; i < sizeof(gMenuWork->ring_rot_x) / sizeof(gMenuWork->ring_rot_x[0]); i++) {
        struct MenuWork *p = gMenuWork;
        p->ring_rot_x[i] = 0;
        p->ring_rot_y[i] = 0;
        p->ring_rot_z[i] = 0;
    }
    gMenuWork->ticks = 0;
    for (i = 0; i < 0x48; i++) {
        gSpriteEntries[i + 1].unk0 = 0xC800;
        gSpriteEntries[i + 1].unk1C = 2;
        gSpriteEntries[i + 1].unkA = i / 18;
        gSpriteEntries[i + 1].unk6 = 0x116;
    }
    matrix_set_identity();
    ring_points_place_on_hexagon(0x32);
    REG_WIN1H = 0xF0;
    REG_WIN1V = 0x1888;
    REG_WIN0H = 0xF0;
    REG_WIN0V = 0x2880;
    REG_WININ = 0x3D3F;
    REG_WINOUT = 0;
    REG_DISPCNT |= 0x100;
    REG_DISPCNT |= 0x200;
    REG_DISPCNT |= 0x400;
    REG_DISPCNT |= 0x800;
    REG_DISPCNT |= 0x1000;
    REG_BLDCNT = 0x844;
    REG_BLDALPHA = 0x1004;
    REG_BLDY = 8;
    gMenuWork->frame = 0;
    gMenuWork->counter = 0;
    gMenuWork->unk49 = 0;
    gMenuWork->pending_sound = 0;
    gMenuWork->sound_delay = 0;
    gGameWork.unk84 = 0;
    gGameSubState++;
}

void text_scroll_fade_in(void) {
    struct GameWork *s;
    u8 *n;
    update_scene_animation_frame();
    s = &gGameWork;
    n = &s->unk84;
    if (*n <= 0x40) {
        bg_palettes_blend_masked_now(0, 0x20 - (*n / 2), 0xFFFF);
        obj_palettes_blend_masked_now(0, 0x20 - (*n / 2), 0xFFFF);
        s->unk84++;
        gMenuWork->cursor = 0;
    } else
        gGameSubState++;
}

void text_scroll_page_start(void) {
    struct PtrTable3 t = gUnk_080AFE9C;
    struct MenuWork *s;
    update_scene_animation_frame();
    s = gMenuWork;
    if (++s->frame > 0xD) {
        if (text_scroll_slide_in_heading(s->cursor, s->frame - 0xE)) {
            struct MenuWork *u = gMenuWork;
            u->scene_text = t.p[u->cursor];
            u->frame = 0;
            gGameSubState++;
            gMenuWork->text_len = text_line_glyph_count((u8 *)*u->scene_text);
        }
    } else
        ((u16 *)(((REG_BG0CNT >> 8) & 0x1F) * 0x800 + VRAM))[(s->frame + 2) * 32] = *(u16 *)0x0600D8C0;
}

void text_scroll_lines(void) {
    int lines;
    update_scene_animation_frame();
    lines = gSceneTextLineCounts[gMenuWork->cursor];
    if ((u16)gMenuWork->frame % 32 == 0) {
        if (lines > gMenuWork->frame / 32) {
            text_scroll_draw_line(*gMenuWork->scene_text, (gMenuWork->frame / 32 + 0x10) & 0x1F);
            if (lines == gMenuWork->frame / 32)
                gMenuWork->text_len = 0;
            else
                gMenuWork->text_len = text_line_glyph_count((u8 *)*gMenuWork->scene_text);
            gMenuWork->scene_text++;
        } else {
            gGameSubState++;
            gMenuWork->frame = -1;
        }
    }
    text_scroll_draw_bar(gMenuWork->text_len, gMenuWork->frame & 0x1F);
    text_scroll_shift_row((gMenuWork->frame / 32 + 5) & 0x1F, (gMenuWork->frame + 2) & 0x1F);
    if ((gMenuWork->frame & 3) == 0)
        gBg1Scroll.y++;
    gMenuWork->frame++;
}

void text_scroll_page_end(void) {
    update_scene_animation_frame();
    if (text_scroll_slide_out_heading(gMenuWork->frame++)) {
        gMenuWork->frame = 0;
        if (++gMenuWork->cursor > 2)
            gGameSubState++;
        else {
            gBg1Scroll.y = 0;
            gGameSubState -= 2;
        }
    }
}

void text_scroll_clear_bar(void) {
    struct MenuWork *s;
    update_scene_animation_frame();
    s = gMenuWork;
    if (++s->frame > 0xE) {
        gGameSubState++;
        s->fade_step = 0;
        fade_out_music(0xC0);
    } else
        ((u16 *)(((REG_BG0CNT >> 8) & 0x1F) * 0x800 + VRAM))[(s->frame + 2) * 32] = 0;
}

void text_scroll_fade_out(void) {
    update_scene_animation_frame();
    if (gMenuWork->fade_step <= 0xC0) {
        bg_palettes_blend_masked_now(0, (s16)(gMenuWork->fade_step / 6), 0xFFFF);
        obj_palettes_blend_masked_now(0, (s16)(gMenuWork->fade_step / 6), 0xFFFF);
        gMenuWork->fade_step++;
    } else if (is_music_fading() == 0) {
        gGameSubState = 0;
        dispatch_by_index_0476e8(0xC);
    }
}

void text_scroll_update(void) {
    struct FuncTable7 t = gUnk_080AFEA8;
    t.f[gGameSubState]();
    gBg2Scroll.y--;
}
