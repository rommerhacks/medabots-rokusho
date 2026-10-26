// Mode-2 state 6: name entry (naming a Medal): sub_0805E29C runs gUnk_08483C44 (graphics, letter grid input
// in name_entry_update, confirm, leave). calc_text_pixel_width centres the name. Uses text/ and engine/.
#include "global.h"

void sub_0805E170(u16 a) {
    gUnk_03002C30[20].unk6 = gUnk_080AF808[a & 3];
}

static s32 calc_text_pixel_width(const u8 *s) {
    s32 w = 0;
    s32 i;
    for (i = 0; i < 10 && *s != 0xFE; i++)
        w += gUnk_083B4C88[*s++][0];
    return w;
}

static inline u32 ato(u32 s, u32 c) {
    return (s << 11) + c * 2;
}

static void sub_0805E1CC(const u8 *s) {
    u16 *top;
    u16 *bot;
    s32 i;
    u8 c, col, row;
    u32 scr;

    top = (u16 *)(VRAM + (((REG_BG1CNT >> 8) & 0x1F) << 11)) + 0x65;
    bot = (u16 *)(VRAM + (((REG_BG1CNT >> 8) & 0x1F) << 11)) + 0x85;
    for (i = 0; i < 10; i++) {
        if (*s != 0) {
            c = *s - 1;
            scr = (REG_BG1CNT >> 8) & 0x1F;
            col = c % 26;
            row = c / 26;
            *top++ = *((u16 *)(VRAM + 0x204) + ((ato(scr, col) + row * 192) >> 1));
            *bot++ = *((u16 *)(VRAM + 0x244) + ((ato((REG_BG1CNT >> 8) & 0x1F, col) + row * 192) >> 1));
        } else {
            *top++ = 0;
            *bot++ = 0;
        }
        s++;
    }
}

void sub_0805E29C(void) {
    gUnk_08483C44[gGameSubState]();
    if (gFrameCounter & 1) {
        gBg3Scroll.x++;
        gBg3Scroll.y++;
    }
    sub_0805E170(gFrameCounter >> 3);
}

void sub_0805E2E8(void) {
    clear_battle_sprite_slot(0, 0x80);
    reset_bg_scroll();
    REG_DISPCNT = 0x60;
    gGameSubState++;
}

// Inline helpers keep agbcc from refolding the sums (see CONTRIBUTING: mul9/sub8) and make it
// reload 0x06004000 instead of keeping it in a callee-saved register.
static inline s32 half8(s32 v) {
    return v / 2 - 0x50;
}
static inline s32 half4(s32 v) {
    return v / 2 + 0x40;
}
static inline s32 mul16(u8 v) {
    return v * 16;
}
static inline void *vram_at2(u32 off) {
    return (void *)(0x06004000 + off);
}

// First step of the name-entry screen (runs once as it opens): BG1-3 tilemaps, tiles, palettes, the letter
// and cursor sprites.
void name_entry_init_graphics(void) {
    u32 size;
    u16 v;
    vu16 *bg1;
    vu16 *bg2;
    vu16 *bg3;
    u32 zero;
    u32 zero2;
    vu16 **pbg2;
    u8 i;
    u16 t;
    u32 base;
    u16 *d;
    u16 *map;
    s32 y;
    bg1 = &REG_BG1CNT;
    v = 0x1F05;
    *bg1 = v;
    bg2 = &REG_BG2CNT;
    v -= 0xFF;
    pbg2 = &bg2;
    *(*pbg2) = v;
    bg3 = &REG_BG3CNT;
    v -= 0xFF;
    *bg3 = v;
    decompress_and_write_tilemap(gUnk_08794E6C, *bg1);
    decompress_and_write_tilemap(gUnk_0879514C, *(*pbg2));
    decompress_and_write_tilemap(gUnk_08795418, *bg3);
    size = dma3_copy_or_decompress(gUnk_08793628, gDecompressBuffer);
    CpuSet(gDecompressBuffer, vram_at2(0), (size / 2) & 0x1FFFFF);
    gUnk_03006F74->unk36 = (size >> 5) - 1;
    CpuSet(gUnk_084C21BC, vram_at2(size), (0x1000 / 2) & 0x1FFFFF);
    zero = 0;
    CpuFastSet(&zero, (void *)0x05000000, 0x01000080);
    zero2 = 0;
    CpuFastSet(&zero2, (void *)0x05000200, 0x01000080);
    lz_decompress_dispatch(gUnk_08784DA4, (void *)0x06010000);
    lz_decompress_dispatch(gUnk_084C6A98, (void *)0x06017400);
    for (i = 0; i < 2; i++) {
        gUnk_03002C30[i].unk0 = 0xC000;
        gUnk_03002C30[i].unk1C = 2;
        gUnk_03002C30[i].unkA = 0xE;
        gUnk_03002C30[i].unk6 = 8;
    }

    gUnk_03002C30[0].unk0 |= 0x2000;
    gUnk_03002C30[20].unk0 = 0x8000;
    gUnk_03002C30[20].unk1C = 2;
    gUnk_03002C30[20].unk2 = 0x10;
    gUnk_03002C30[20].unk4 = 0x10;
    gUnk_03002C30[20].unkA = 0;
    gUnk_03002C30[20].unk6 = 0x23;
    if (gUnk_03000584 == 0) {
        gUnk_03002C30[20].unk0 |= 0x4000;
    } else {
        t = gUnk_03006F74->unk36 + ((gUnk_03000BE0[gUnk_030017EC].unk1 * 4) + 1);
        t |= 0x6000;
        base = ((REG_BG1CNT >> 8) & 0x1F) << 11;
        map = (u16 *)(0x06000000 + base);
        d = (u16 *)(base + 0x060000C4);
        *d = t;
        d = &map[0x63];
        *d = t + 1;
        d = &map[0x82];
        *d = t + 2;
        d = &map[0x83];
        *d = t + 3;
    }
    for (i = 0; i < 2; i++) {
        gUnk_03002C30[i + 2].unk0 = 0x8000;
        gUnk_03002C30[i + 2].unk1C = 2;
        gUnk_03002C30[i + 2].unkA = 0xE;
        gUnk_03002C30[i + 2].unk6 = 5;
    }

    gUnk_03002C30[3].unk0 |= 0x1000;
    gUnk_03006F74->unkD = 0;
    gUnk_03006F74->unkE = 0;
    gUnk_03006F74->unk8 = 0;
    gUnk_03002C30[0].unk2 = (y = (gUnk_03006F74->unkD * 8) + 0x14);
    gUnk_03002C30[0].unk4 = mul16(gUnk_03006F74->unkE) + half4(gUnk_03006F74->unk8);
    gUnk_03002C30[1].unk2 = y;
    gUnk_03002C30[1].unk4 = mul16(gUnk_03006F74->unkE) - half8(gUnk_03006F74->unk8);
    gUnk_03002C30[4].unk0 = 0xC000;
    gUnk_03002C30[4].unk1C = 2;
    gUnk_03002C30[4].unkA = 0xE;
    gUnk_03002C30[4].unk6 = 0x26;
    gGameSubState++;
}

void sub_0805E5B0(void) {
    s8 i;
    s32 x;
    u8 k;
    const u8(*tbl)[2];

    REG_DISPCNT |= 0x200;
    REG_DISPCNT |= 0x400;
    REG_DISPCNT |= 0x800;
    REG_DISPCNT |= 0x1000;
    for (i = 0; i < 16; i++)
        gUnk_03006F74->unk58[i] = 0xFE;
    clear_sprite_table_mask(5, 10);
    switch (gUnk_03000584) {
    case 0:
        for (i = 0; i < 16; i++) {
            gUnk_03006F74->unk58[i] = gUnk_08483C68[i];
            if (gUnk_03006F74->unk58[i] == 0xFE)
                break;
        }
        gUnk_03006F74->unkF = i;
        break;
    case 1:
        k = gUnk_03000BE0[gUnk_030017EC].unk1;
        if (k <= 1) {
            for (i = 0; i < 16; i++) {
                gUnk_03006F74->unk58[i] = ((const u8 *)gUnk_083B6410[k + 0x20])[i];
                if (gUnk_03006F74->unk58[i] == 0xFE)
                    break;
            }
        } else {
            for (i = 0; i < 16; i++) {
                gUnk_03006F74->unk58[i] = ((const u8 *)gUnk_083B6410[k])[i];
                if (gUnk_03006F74->unk58[i] == 0xFE)
                    break;
            }
        }
        gUnk_03006F74->unkF = i;
        break;
    case 2:
        for (i = 0; i < 16; i++) {
            gUnk_03006F74->unk58[i] = gUnk_03000BE0[gUnk_030017EC].unkA[i];
            if (gUnk_03006F74->unk58[i] == 0xFE)
                break;
        }
        gUnk_03006F74->unkF = i;
        break;
    }
    CpuSet(gUnk_03006F74->unk58, gUnk_03006F74->unk58 + 0x10, 8);
    gUnk_03002C30[4].unk2 = calc_text_pixel_width(gUnk_03006F74->unk58) + 0x28;
    gUnk_03002C30[4].unk4 = 0x1B;
    render_text_sprites_08040DB8(gUnk_03006F74->unk58, 5, 5, 3, 10, 13, 1, 0);
    x = gUnk_03002C30[4].unk2 + 2;
    {
        register const u8(*tb)[2] asm("r4");
        for (i = gUnk_03006F74->unkF; i <= 9; i++) {
            tb = gUnk_083B4C88;
            gUnk_03002C30[i + 5].unk0 = 0xC000;
            gUnk_03002C30[i + 5].unk1C = 0;
            gUnk_03002C30[i + 5].unkA = 0xD;
            gUnk_03002C30[i + 5].unk6 = 0x42;
            gUnk_03002C30[i + 5].unk2 = x;
            gUnk_03002C30[i + 5].unk4 = 0x1C;
            gUnk_03002C30[i + 5].unkB = 0xFF;
            x += tb[0x43][0];
        }
    }
    CpuFastSet(gUnk_08483AA0, (void *)0x0202FA20, 8);
    CpuFastSet(gUnk_084E2E58, (void *)0x0202F9C0, 8);
    CpuFastSet(gUnk_084E2E38, (void *)0x0202F9A0, 8);
    CpuFastSet(gUnk_080AF810, gPaletteBackup, 8);
    CpuFastSet(gUnk_08793428, gPaletteBackupBg, 0x80);
    gUnk_03000440.unk84 = 0;
    gGameSubState++;
}

void sub_0805E878(void) {
    struct Unk_03000440 *b = &gUnk_03000440;
    if (b->unk84 <= 8) {
        blend_obj_palettes_to_color_0803F684(0, 0x20 - b->unk84 * 4, 0xFFFF);
        blend_obj_palettes_to_color_0803F998(0, 0x20 - b->unk84 * 4, 0xFFFF);
        b->unk84++;
    } else {
        gUnk_03006F74->unk2 = 0;
        gUnk_03006F74->unk6 = 0;
        gGameSubState++;
    }
}

// Per-frame update of the name-entry screen (runs every frame while naming a Medal): cursor blink and
// movement (rows 0-2 letters, row 3 Space / Back / End), Start / R / A / B, edits the name in unk58.
void name_entry_update(void) {
    s32 i;
    s32 x;
    u8 blank;
    u8 col;
    s32 t;

    gUnk_03002C30[4].unk6 = ((gFrameCounter / 6) & 3) + 0x26;
    if (gUnk_03006F74->unk6) {
        if (gUnk_03006F74->unk2++ < 8)
            gUnk_03006F74->unk8++;
        else {
            gUnk_03006F74->unk2 = 0;
            gUnk_03006F74->unk6 = 0;
        }
    } else {
        if (gUnk_03006F74->unk2++ < 8)
            gUnk_03006F74->unk8--;
        else {
            gUnk_03006F74->unk2 = 0;
            gUnk_03006F74->unk6 = 1;
        }
    }

    if (KEYS_LO(gRepeatKeys) & 0x10) {
        play_sound_effect(2);
        col = gUnk_03006F74->unkD;
        if (gUnk_03006F74->unkE == 3 ? col == 2 : col == 0x19)
            gUnk_03006F74->unkD = 0;
        else
            gUnk_03006F74->unkD++;
    }
    if (KEYS_LO(gRepeatKeys) & 0x20) {
        play_sound_effect(2);
        if (gUnk_03006F74->unkD == 0) {
            gUnk_03006F74->unkD = gUnk_03006F74->unkE == 3 ? 2 : 0x19;
        } else
            gUnk_03006F74->unkD--;
    }
    if (KEYS_LO(gRepeatKeys) & 0x40) {
        play_sound_effect(2);
        if (gUnk_03006F74->unkE == 0) {
            gUnk_03006F74->unkE = 3;
            if (gUnk_03006F74->unkD <= 8)
                gUnk_03006F74->unkD = 0;
            else if (gUnk_03006F74->unkD <= 0x10)
                gUnk_03006F74->unkD = 1;
            else
                gUnk_03006F74->unkD = 2;
        } else {
            gUnk_03006F74->unkE--;
            if (gUnk_03006F74->unkE == 2)
                gUnk_03006F74->unkD = gUnk_080AF850[gUnk_03006F74->unkD];
        }
    }
    if (KEYS_LO(gRepeatKeys) & 0x80) {
        play_sound_effect(2);
        if (gUnk_03006F74->unkE == 3) {
            gUnk_03006F74->unkE = 0;
            gUnk_03006F74->unkD = gUnk_080AF850[gUnk_03006F74->unkD];
        } else {
            gUnk_03006F74->unkE++;
            if (gUnk_03006F74->unkE == 3) {
                if (gUnk_03006F74->unkD <= 8)
                    gUnk_03006F74->unkD = 0;
                else if (gUnk_03006F74->unkD <= 0x10)
                    gUnk_03006F74->unkD = 1;
                else
                    gUnk_03006F74->unkD = 2;
            }
        }
    }

    if (gUnk_03006F74->unkE == 3) {
        gUnk_03002C30[0].unk2 = gUnk_03006F74->unkD * 64 - (t = (s32)gUnk_03006F74->unk8 / 2 - 0x18);
        gUnk_03002C30[0].unk4 = 0x8C;
        gUnk_03002C30[1].unk2 = gUnk_03006F74->unkD * 64 + (t = (s32)gUnk_03006F74->unk8 / 2 + 0x58);
        gUnk_03002C30[1].unk4 = gUnk_03002C30[0].unk4;
        gUnk_03002C30[0].unk6 = 5;
        gUnk_03002C30[1].unk6 = 5;
        gUnk_03002C30[0].unk0 &= 0xDFFF;
        gUnk_03002C30[1].unk0 |= 0x1000;
    } else {
        gUnk_03002C30[0].unk2 = gUnk_03006F74->unkD * 8 + 0x14;
        gUnk_03002C30[0].unk4 = gUnk_03006F74->unkE * 24 + (t = (s32)gUnk_03006F74->unk8 / 2 + 0x40);
        gUnk_03002C30[1].unk2 = gUnk_03002C30[0].unk2;
        gUnk_03002C30[1].unk4 = gUnk_03006F74->unkE * 24 - (t = (s32)gUnk_03006F74->unk8 / 2 - 0x50);
        gUnk_03002C30[0].unk6 = 8;
        gUnk_03002C30[1].unk6 = 8;
        gUnk_03002C30[0].unk0 |= 0x2000;
        gUnk_03002C30[1].unk0 &= 0xEFFF;
    }

    if (KEYS_LO(gNewKeys) & 8) {
    start:
        play_sound_effect(4);
        gUnk_03006F74->unkE = 3;
        gUnk_03006F74->unkD = 2;
    } else if (*((u8 *)&gNewKeys + 1) & 1) {
    space:
        if (gUnk_03006F74->unkF <= 9) {
            play_sound_effect(4);
            gUnk_03006F74->unk58[gUnk_03006F74->unkF] = 0;
            gUnk_03006F74->unkF++;
            if (gUnk_03006F74->unkF == 10) {
                gUnk_03002C30[4].unk0 &= 0xBFFF;
                clear_sprite_table_mask(5, 10);
                render_text_sprites_08040DB8(gUnk_03006F74->unk58, 5, 5, 3, 10, 13, 1, 0);
                goto start;
            }
        } else
            play_sound_effect(6);
        goto redraw;
    } else if (KEYS_LO(gNewKeys) & 1) {
        if (gUnk_03006F74->unkE == 3) {
            switch (gUnk_03006F74->unkD) {
            case 1:
                goto back;
            case 0:
                goto space;
            case 2:
                gUnk_03002C30[4].unk0 &= 0xBFFF;
                blank = 1;
                for (i = 0; (u32)i < 16 && gUnk_03006F74->unk58[i] != 0xFE; i++) {
                    if (gUnk_03006F74->unk58[i] != 0) {
                        blank = 0;
                        break;
                    }
                }
                if (blank)
                    CpuSet(gUnk_03006F74->unk58 + 0x10, gUnk_03006F74->unk58, 8);
                clear_sprite_table_mask(5, 10);
                render_text_sprites_08040DB8(gUnk_03006F74->unk58, 5, 5, 3, 10, 13, 1, 0);
                play_sound_effect(7);
                gGameSubState++;
                return;
            }
        }
        if (gUnk_03006F74->unkF <= 9) {
            play_sound_effect(4);
            gUnk_03006F74->unk58[gUnk_03006F74->unkF] = gUnk_03006F74->unkE * 26 + gUnk_03006F74->unkD + 1;
            gUnk_03006F74->unkF++;
            if (gUnk_03006F74->unkF == 10) {
                gUnk_03002C30[4].unk0 &= 0xBFFF;
                clear_sprite_table_mask(5, 10);
                render_text_sprites_08040DB8(gUnk_03006F74->unk58, 5, 5, 3, 10, 13, 1, 0);
                goto start;
            }
        } else
            play_sound_effect(6);
    redraw:
        clear_sprite_table_mask(5, 10);
        render_text_sprites_08040DB8(gUnk_03006F74->unk58, 5, 5, 3, 10, 13, 1, 0);
    } else if (gNewKeys & 0x202) {
    back:
        play_sound_effect(5);
        if (gUnk_03006F74->unkF != 0) {
            gUnk_03006F74->unkF--;
            gUnk_03006F74->unk58[gUnk_03006F74->unkF] = 0xFE;
        } else {
            gUnk_03006F74->unkF = 0;
            gUnk_03006F74->unk58[gUnk_03006F74->unkF] = 0xFE;
        }
        clear_sprite_table_mask(5, 10);
        render_text_sprites_08040DB8(gUnk_03006F74->unk58, 5, 5, 3, 10, 13, 1, 0);
        gUnk_03002C30[4].unk0 |= 0x4000;
    } else
        return;

    gUnk_03002C30[4].unk2 = calc_text_pixel_width(gUnk_03006F74->unk58) + 0x28;
    gUnk_03002C30[4].unk4 = 0x1B;
    x = gUnk_03002C30[4].unk2 + 2;
    {
        register const u8(*tb)[2] asm("r4");
        for (i = gUnk_03006F74->unkF; i <= 9; i++) {
            tb = gUnk_083B4C88;
            gUnk_03002C30[i + 5].unk0 = 0xC000;
            gUnk_03002C30[i + 5].unk1C = 0;
            gUnk_03002C30[i + 5].unkA = 0xD;
            gUnk_03002C30[i + 5].unk6 = 0x42;
            gUnk_03002C30[i + 5].unk2 = x;
            gUnk_03002C30[i + 5].unk4 = 0x1C;
            gUnk_03002C30[i + 5].unkB = 0xFF;
            x += tb[0x43][0];
            tb = gUnk_083B4C88;
        }
    }
}

void sub_0805EE6C(void) {
    u32 r = is_sound_playing_with_lock(7);
    if (r == 0) {
        gUnk_03000440.unk84 = r;
        gGameSubState++;
    }
}

void sub_0805EE94(void) {
    struct Unk_03000440 *s = &gUnk_03000440;
    u8 *n = &s->unk84;

    if (*n <= 8) {
        blend_obj_palettes_to_color_0803F684(0, *n * 4, 0xFFFF);
        blend_obj_palettes_to_color_0803F998(0, *n * 4, 0xFFFF);
        (*n)++;
    } else {
        u32 zero;

        REG_DISPCNT &= 0xFDFF;
        zero = 0;
        CpuFastSet(&zero, (void *)VRAM, 0x01006000);
        switch (gUnk_03000584) {
        case 0:
            CpuSet(gUnk_03006F74->unk58, gUnk_03002B70.unk4, 8);
            dispatch_by_index_0476e8(0);
            break;
        case 1:
            CpuSet(gUnk_03006F74->unk58, gUnk_03000BE0[gUnk_030017EC].unkA, 7);
            dispatch_by_index_0476e8(1);
            break;
        case 2:
            CpuSet(gUnk_03006F74->unk58, gUnk_03000BE0[gUnk_030017EC].unkA, 7);
            gGameState = 0x12;
            gGameSubState = 10;
            break;
        }
    }
}
