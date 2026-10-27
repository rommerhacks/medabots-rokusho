// Sprite slot table: init / clear slots, run sprite animation command streams
// (process_sprite_anim_commands, opcodes 0xFB-0xFF), find free slots, and draw text strings and numbers
// (the divide_by_* digit splitters) as sprites. Used by the menus, battle and field.

#include "global.h"

// Message step: fills the 104 window tiles at VRAM 0x280 with colour 1 (the window background).
void message_fill_window_tiles(void) {
    u32 i;
    for (i = 0; i <= 0x33; i++)
        CpuCopy16(gFontGlyphs, (void *)(VRAM + 0x280 + i * 0x40), 0x40);
    gGameWork.endModeStep++;
}

void init_battle_sprite_entry_08040B90(const void *cmds, u8 slot) {
    const u8 *p;
    u8 i;
    gSpriteEntries[slot].unk20 = 0;
    gSpriteEntries[slot].unk21 = 0;
    gSpriteEntries[slot].unk22 = 0;
    i = 0;
loop:
    p = (const u8 *)cmds + i;
    if (*p > 0xFA) {
        i += 3;
        goto loop;
    }
    gSpriteEntries[slot].unk6 = (p[1] << 8) + p[2];
}

void process_sprite_anim_commands(const u8 *cmds, u8 slot) {
    u32 run;
    u8 op;

    if (gSpriteEntries[slot].unk22 == 0xFF)
        return;
    run = 1;
    do {
        if (gSpriteEntries[slot].unk20 != 0) {
            gSpriteEntries[slot].unk20--;
            return;
        }
        op = cmds[gSpriteEntries[slot].unk21];
        switch (op) {
        case 0xFB:
            gSpriteEntries[0].unk0 &= 0xBFFF;
            gSpriteEntries[slot].unk20 = cmds[gSpriteEntries[slot].unk21 + 1];
            gSpriteEntries[slot].unk21 += 3;
            return;
        case 0xFC:
            gSpriteEntries[0].unk0 |= 0x4000;
            gSpriteEntries[slot].unk21 += 3;
            break;
        case 0xFD:
            play_sound_effect(cmds[gSpriteEntries[slot].unk21 + 1]);
            gSpriteEntries[slot].unk21 += 3;
            break;
        case 0xFE:
            gSpriteEntries[slot].unk21 = cmds[gSpriteEntries[slot].unk21 + 1] * 3;
            break;
        case 0xFF:
            gSpriteEntries[slot].unk22 = 0xFF;
            return;
        default:
            gSpriteEntries[slot].unk20 = op;
            gSpriteEntries[slot].unk6 =
                (cmds[gSpriteEntries[slot].unk21 + 1] << 8) + cmds[gSpriteEntries[slot].unk21 + 2];
            gSpriteEntries[slot].unk21 += 3;
            break;
        }
    } while (run);
}

void clear_battle_sprite_slot(u8 a, u8 b) {
    u32 i;
    u32 zero;

    for (i = 0; i < b; i++) {
        zero = 0;
        CpuFastSet(&zero, &gSpriteEntries[a + i], 0x01000010);
    }
}

void clear_sprite_table_mask(u8 first, u8 count) {
    u32 i;
    for (i = 0; i < count; i++)
        gSpriteEntries[first + i].unk0 &= 0x7FFF;
}

void set_sprite_hidden_flags(u8 first, u8 count) {
    u32 i;
    for (i = 0; i < count; i++)
        gSpriteEntries[first + i].unk0 |= 0x8000;
}

u32 find_next_free_sprite_slot(u8 first, u8 count) {
    u8 i;
    u32 slot;
    for (i = 0; i < count; i++) {
        slot = first + i;
        if (slot == 0x80)
            return first;
        if (gSpriteEntries[slot].unk0 == 0)
            return slot;
    }
    return first;
}

void render_text_sprites_08040DB8(u8 *str, u8 slot, u32 x, u32 y, u8 width, u8 pal, u8 align, u16 prio) {
    u8 len;
    u8 w;
    u32 i;

    x *= 8;
    y *= 8;
    len = 0;
    for (i = 0; str[i] != 0xFE; i++)
        len += gFontWidths[str[i]][0];
    w = width * 8;
    if (len <= w) {
        switch (align) {
        case 0:
            len = (w - len) / 2;
            x += len;
            break;
        case 1:
            break;
        case 2:
            len = w - len;
            x += len;
            break;
        }
    } else {
        switch (align) {
        case 0:
            len = (len - w) / 2;
            x -= len;
            break;
        case 1:
            break;
        case 2:
            len = len - w;
            x -= len;
            break;
        }
    }
    for (i = 0; str[i] != 0xFE; i++) {
        if (str[i] != 0) {
            gSpriteEntries[slot + i].unk0 = (prio << 10) | 0xC004;
            gSpriteEntries[slot + i].unk2 = x;
            gSpriteEntries[slot + i].unk4 = y;
            gSpriteEntries[slot + i].unkA = pal;
            gSpriteEntries[slot + i].unk1C = 0;
            gSpriteEntries[slot + i].unkB = ((3 & ~prio) << 6) + 0x3F;
            gSpriteEntries[slot + i].unk6 = str[i] - 1;
        }
        x += gFontWidths[str[i]][0];
    }
}

void render_text_sprites_08040EE4(u8 *str, u8 slot, u32 x, u32 y, u8 width, u8 pal, u8 align, u16 prio, s32 dx,
                                  s32 dy) {
    u8 len;
    u8 w;
    u32 i;

    x = x * 8 + dx;
    y = y * 8 + dy;
    len = 0;
    for (i = 0; str[i] != 0xFE; i++)
        len += gFontWidths[str[i]][0];
    w = width * 8;
    if (len <= w) {
        switch (align) {
        case 0:
            len = (w - len) / 2;
            x += len;
            break;
        case 1:
            break;
        case 2:
            len = w - len;
            x += len;
            break;
        }
    } else {
        switch (align) {
        case 0:
            len = (len - w) / 2;
            x -= len;
            break;
        case 1:
            break;
        case 2:
            len = len - w;
            x -= len;
            break;
        }
    }
    for (i = 0; str[i] != 0xFE; i++) {
        if (str[i] != 0) {
            gSpriteEntries[slot + i].unk0 = (prio << 10) | 0xC004;
            gSpriteEntries[slot + i].unk2 = x;
            gSpriteEntries[slot + i].unk4 = y;
            gSpriteEntries[slot + i].unkA = pal;
            gSpriteEntries[slot + i].unk1C = 0;
            gSpriteEntries[slot + i].unkB = ((3 & ~prio) << 6) + 0x3F;
            gSpriteEntries[slot + i].unk6 = str[i] - 1;
        }
        x += gFontWidths[str[i]][0];
    }
}

void render_text_string_to_sprites(u8 *str, u8 slot, u32 x, u32 y, u8 width, u8 pal, u8 align, u16 prio) {
    u8 len;
    u8 w;
    u32 i;

    x *= 8;
    y *= 8;
    len = 0;
    for (i = 0; str[i] != 0xFE; i++)
        len += gFontWidths[str[i]][0];
    w = width * 8;
    if (len <= w) {
        switch (align) {
        case 0:
            len = (w - len) / 2;
            x += len;
            break;
        case 1:
            break;
        case 2:
            len = w - len;
            x += len;
            break;
        }
    } else {
        switch (align) {
        case 0:
            len = (len - w) / 2;
            x -= len;
            break;
        case 1:
            break;
        case 2:
            len = len - w;
            x -= len;
            break;
        }
    }
    for (i = 0; str[i] != 0xFE; i++) {
        if (str[i] != 0) {
            gSpriteEntries[slot + i].unk0 = (prio << 10) | 0xC004;
            gSpriteEntries[slot + i].unk2 = x;
            gSpriteEntries[slot + i].unk4 = y;
            gSpriteEntries[slot + i].unkA = pal;
            gSpriteEntries[slot + i].unk1C = 0;
            gSpriteEntries[slot + i].unkB = ((3 & ~prio) << 6) + 0x3F;
            gSpriteEntries[slot + i].unk6 = str[i] + 0x85FF;
        }
        x += gFontWidths[str[i]][0];
    }
}

void divide_by_10000(u8 *out, u32 n) {
    u8 d[5];
    vu32 r;
    u8 i, j, k, started;

    d[0] = n / 10000;
    r = n - n / 10000 * 10000;
    d[1] = r / 1000;
    r = r - r / 1000 * 1000;
    d[2] = r / 100;
    r = r - r / 100 * 100;
    d[3] = r / 10;
    r = r - r / 10 * 10;
    d[4] = r;

    j = 0;
    started = 0;
    k = 0;
    for (i = 0; i < 10; i++) {
        if (i == 0) {
            out[k] = 0x4C;
            k++;
        } else if (i == 4) {
            out[k] = 0x40;
            k++;
        } else {
            if (i <= 2) {
                if (d[j] == 0) {
                    if (started) {
                        out[k] = d[j] + 0x35;
                        k++;
                        j++;
                    } else
                        j++;
                } else {
                    out[k] = d[j] + 0x35;
                    started = 1;
                    k++;
                    j++;
                }
            } else {
                out[k] = d[j] + 0x35;
                k++;
                j++;
            }
            if (j == 5) {
                out[k] = 0xFE;
                break;
            }
        }
    }
}

void divide_by_10000_b(u8 *out, u32 n) {
    u8 d[5];
    vu32 r;
    u8 i, j, k, started;

    d[0] = n / 10000;
    r = n - n / 10000 * 10000;
    d[1] = r / 1000;
    r = r - r / 1000 * 1000;
    d[2] = r / 100;
    r = r - r / 100 * 100;
    d[3] = r / 10;
    r = r - r / 10 * 10;
    d[4] = r;

    j = 0;
    started = 0;
    k = 0;
    for (i = 0; i < 10; i++) {
        if (i == 0) {
        } else if (i == 4) {
            out[k] = 0x40;
            k++;
        } else {
            if (i <= 2) {
                if (d[j] == 0) {
                    if (started) {
                        out[k] = d[j] + 0x35;
                        k++;
                        j++;
                    } else
                        j++;
                } else {
                    out[k] = d[j] + 0x35;
                    started = 1;
                    k++;
                    j++;
                }
            } else {
                out[k] = d[j] + 0x35;
                k++;
                j++;
            }
            if (j == 5) {
                out[k] = 0xFE;
                break;
            }
        }
    }
}

void divide_by_100000_08041370(u8 *out, u32 n) {
    u8 d[6];
    vu32 r;
    u8 i, k, started;

    d[0] = n / 100000;
    r = n - n / 100000 * 100000;
    d[1] = r / 10000;
    r = r - n / 10000 * 10000;
    d[2] = r / 1000;
    r = r - r / 1000 * 1000;
    d[3] = r / 100;
    r = r - r / 100 * 100;
    d[4] = r / 10;
    r = r - r / 10 * 10;
    d[5] = r;

    if (d[0] != 0) {
        out[0] = 5;
        out[1] = 0x12;
        out[2] = 0x12;
        out[3] = 0xF;
        out[4] = 0x12;
        out[5] = 0xFE;
        return;
    }

    started = 0;
    k = 0;
    for (i = 0; i < 6; i++) {
        if (i <= 4) {
            if (d[i] == 0) {
                if (started) {
                    out[k] = d[i] + 0x35;
                    k++;
                }
            } else {
                out[k] = d[i] + 0x35;
                started = 1;
                k++;
            }
        } else {
            out[k] = d[i] + 0x35;
            k++;
        }
    }
    out[k] = 0xFE;
}

void divide_by_100000_b(u8 *buf, u32 value, u32 tile) {
    u8 d[6];
    vu32 r;
    u8 i, k, started;

    d[0] = value / 100000;
    r = value - value / 100000 * 100000;
    d[1] = r / 10000;
    r = r - value / 10000 * 10000;
    d[2] = r / 1000;
    r = r - r / 1000 * 1000;
    d[3] = r / 100;
    r = r - r / 100 * 100;
    d[4] = r / 10;
    r = r - r / 10 * 10;
    d[5] = r;

    if (d[0] != 0) {
        buf[0] = 5;
        buf[1] = 0x12;
        buf[2] = 0x12;
        buf[3] = 0xF;
        buf[4] = 0x12;
        buf[5] = 0xFE;
        return;
    }

    started = 0;
    k = 0;
    for (i = 0; i <= 5; i++) {
        if (i <= 4) {
            if (d[i] == 0) {
                if (started) {
                    buf[k] = d[i] + tile;
                    k++;
                }
            } else {
                buf[k] = d[i] + tile;
                started = 1;
                k++;
            }
        } else {
            buf[k] = d[i] + tile;
            k++;
        }
    }
    buf[k] = 0xFE;
}
