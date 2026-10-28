// Sprite slot table: init / clear slots, run sprite animation command streams
// (process_sprite_anim_commands, opcodes 0xFB-0xFF), find free slots, and draw text strings and numbers
// (the divide_by_* digit splitters) as sprites. Used by the menus, battle and field.

#include "global.h"
#include "constants/sprites.h"

// Message step: fills the 104 window tiles at VRAM 0x280 with colour 1 (the window background).
void message_fill_window_tiles(void) {
    u32 i;
    for (i = 0; i <= 0x33; i++)
        CpuCopy16(gFontGlyphs, (void *)(VRAM + 0x280 + i * 0x40), 0x40);
    gGameWork.endModeStep++;
}

void battle_sprite_anim_init(const void *cmds, u8 slot) {
    const u8 *cmd;
    u8 i;
    gSpriteEntries[slot].work[SPR_CMD_WAIT] = 0;
    gSpriteEntries[slot].work[SPR_CMD_POS] = 0;
    gSpriteEntries[slot].work[SPR_CMD_STATE] = 0;
    i = 0;
loop:
    cmd = (const u8 *)cmds + i;
    if (*cmd > 0xFA) {
        i += 3;
        goto loop;
    }
    gSpriteEntries[slot].frame = (cmd[1] << 8) + cmd[2];
}

void process_sprite_anim_commands(const u8 *cmds, u8 slot) {
    u32 run;
    u8 op;

    if (gSpriteEntries[slot].work[SPR_CMD_STATE] == SPR_CMD_ENDED)
        return;
    run = 1;
    do {
        if (gSpriteEntries[slot].work[SPR_CMD_WAIT] != 0) {
            gSpriteEntries[slot].work[SPR_CMD_WAIT]--;
            return;
        }
        op = cmds[gSpriteEntries[slot].work[SPR_CMD_POS]];
        switch (op) {
        case 0xFB:
            gSpriteEntries[0].flags &= (u16)~SPRITE_FLAG_VISIBLE;
            gSpriteEntries[slot].work[SPR_CMD_WAIT] = cmds[gSpriteEntries[slot].work[SPR_CMD_POS] + 1];
            gSpriteEntries[slot].work[SPR_CMD_POS] += 3;
            return;
        case 0xFC:
            gSpriteEntries[0].flags |= SPRITE_FLAG_VISIBLE;
            gSpriteEntries[slot].work[SPR_CMD_POS] += 3;
            break;
        case 0xFD:
            play_sound_effect(cmds[gSpriteEntries[slot].work[SPR_CMD_POS] + 1]);
            gSpriteEntries[slot].work[SPR_CMD_POS] += 3;
            break;
        case 0xFE:
            gSpriteEntries[slot].work[SPR_CMD_POS] = cmds[gSpriteEntries[slot].work[SPR_CMD_POS] + 1] * 3;
            break;
        case 0xFF:
            gSpriteEntries[slot].work[SPR_CMD_STATE] = SPR_CMD_ENDED;
            return;
        default:
            gSpriteEntries[slot].work[SPR_CMD_WAIT] = op;
            gSpriteEntries[slot].frame = (cmds[gSpriteEntries[slot].work[SPR_CMD_POS] + 1] << 8) +
                                         cmds[gSpriteEntries[slot].work[SPR_CMD_POS] + 2];
            gSpriteEntries[slot].work[SPR_CMD_POS] += 3;
            break;
        }
    } while (run);
}

void clear_battle_sprite_slot(u8 first, u8 count) {
    u32 i;
    u32 zero;

    for (i = 0; i < count; i++) {
        zero = 0;
        CpuFastSet(&zero, &gSpriteEntries[first + i], 0x01000010);
    }
}

void disable_sprites(u8 first, u8 count) {
    u32 i;
    for (i = 0; i < count; i++)
        gSpriteEntries[first + i].flags &= (u16)~SPRITE_FLAG_ENABLED;
}

void enable_sprites(u8 first, u8 count) {
    u32 i;
    for (i = 0; i < count; i++)
        gSpriteEntries[first + i].flags |= SPRITE_FLAG_ENABLED;
}

u32 find_next_free_sprite_slot(u8 first, u8 count) {
    u8 i;
    u32 slot;
    for (i = 0; i < count; i++) {
        slot = first + i;
        if (slot == 0x80)
            return first;
        if (gSpriteEntries[slot].flags == 0)
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
            gSpriteEntries[slot + i].flags =
                SPRITE_PRIORITY(prio) | SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_FLAG_PART_PALETTE;
            gSpriteEntries[slot + i].x = x;
            gSpriteEntries[slot + i].y = y;
            gSpriteEntries[slot + i].palette = pal;
            gSpriteEntries[slot + i].frame_table = 0;
            gSpriteEntries[slot + i].order = ((3 & ~prio) << 6) + 0x3F;
            gSpriteEntries[slot + i].frame = str[i] - 1;
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
            gSpriteEntries[slot + i].flags =
                SPRITE_PRIORITY(prio) | SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_FLAG_PART_PALETTE;
            gSpriteEntries[slot + i].x = x;
            gSpriteEntries[slot + i].y = y;
            gSpriteEntries[slot + i].palette = pal;
            gSpriteEntries[slot + i].frame_table = 0;
            gSpriteEntries[slot + i].order = ((3 & ~prio) << 6) + 0x3F;
            gSpriteEntries[slot + i].frame = str[i] - 1;
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
            gSpriteEntries[slot + i].flags =
                SPRITE_PRIORITY(prio) | SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_FLAG_PART_PALETTE;
            gSpriteEntries[slot + i].x = x;
            gSpriteEntries[slot + i].y = y;
            gSpriteEntries[slot + i].palette = pal;
            gSpriteEntries[slot + i].frame_table = 0;
            gSpriteEntries[slot + i].order = ((3 & ~prio) << 6) + 0x3F;
            gSpriteEntries[slot + i].frame = str[i] + 0x85FF;
        }
        x += gFontWidths[str[i]][0];
    }
}

void divide_by_10000(u8 *out, u32 n) {
    u8 digits[5];
    vu32 remainder;
    u8 i, j, k, started;

    digits[0] = n / 10000;
    remainder = n - n / 10000 * 10000;
    digits[1] = remainder / 1000;
    remainder = remainder - remainder / 1000 * 1000;
    digits[2] = remainder / 100;
    remainder = remainder - remainder / 100 * 100;
    digits[3] = remainder / 10;
    remainder = remainder - remainder / 10 * 10;
    digits[4] = remainder;

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
                if (digits[j] == 0) {
                    if (started) {
                        out[k] = digits[j] + 0x35;
                        k++;
                        j++;
                    } else
                        j++;
                } else {
                    out[k] = digits[j] + 0x35;
                    started = 1;
                    k++;
                    j++;
                }
            } else {
                out[k] = digits[j] + 0x35;
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
    u8 digits[5];
    vu32 remainder;
    u8 i, j, k, started;

    digits[0] = n / 10000;
    remainder = n - n / 10000 * 10000;
    digits[1] = remainder / 1000;
    remainder = remainder - remainder / 1000 * 1000;
    digits[2] = remainder / 100;
    remainder = remainder - remainder / 100 * 100;
    digits[3] = remainder / 10;
    remainder = remainder - remainder / 10 * 10;
    digits[4] = remainder;

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
                if (digits[j] == 0) {
                    if (started) {
                        out[k] = digits[j] + 0x35;
                        k++;
                        j++;
                    } else
                        j++;
                } else {
                    out[k] = digits[j] + 0x35;
                    started = 1;
                    k++;
                    j++;
                }
            } else {
                out[k] = digits[j] + 0x35;
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
    u8 digits[6];
    vu32 remainder;
    u8 i, k, started;

    digits[0] = n / 100000;
    remainder = n - n / 100000 * 100000;
    digits[1] = remainder / 10000;
    remainder = remainder - n / 10000 * 10000;
    digits[2] = remainder / 1000;
    remainder = remainder - remainder / 1000 * 1000;
    digits[3] = remainder / 100;
    remainder = remainder - remainder / 100 * 100;
    digits[4] = remainder / 10;
    remainder = remainder - remainder / 10 * 10;
    digits[5] = remainder;

    if (digits[0] != 0) {
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
            if (digits[i] == 0) {
                if (started) {
                    out[k] = digits[i] + 0x35;
                    k++;
                }
            } else {
                out[k] = digits[i] + 0x35;
                started = 1;
                k++;
            }
        } else {
            out[k] = digits[i] + 0x35;
            k++;
        }
    }
    out[k] = 0xFE;
}

void divide_by_100000_b(u8 *buf, u32 value, u32 tile) {
    u8 digits[6];
    vu32 remainder;
    u8 i, k, started;

    digits[0] = value / 100000;
    remainder = value - value / 100000 * 100000;
    digits[1] = remainder / 10000;
    remainder = remainder - value / 10000 * 10000;
    digits[2] = remainder / 1000;
    remainder = remainder - remainder / 1000 * 1000;
    digits[3] = remainder / 100;
    remainder = remainder - remainder / 100 * 100;
    digits[4] = remainder / 10;
    remainder = remainder - remainder / 10 * 10;
    digits[5] = remainder;

    if (digits[0] != 0) {
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
            if (digits[i] == 0) {
                if (started) {
                    buf[k] = digits[i] + tile;
                    k++;
                }
            } else {
                buf[k] = digits[i] + tile;
                started = 1;
                k++;
            }
        } else {
            buf[k] = digits[i] + tile;
            k++;
        }
    }
    buf[k] = 0xFE;
}
