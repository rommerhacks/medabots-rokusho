#include "global.h"

// One tile of 2x2 metatile `id` (copy_tiles_to_bg_tilemap); yoff / xoff are passed but unused.
void build_bg_tile_entry(u16 *dst, u16 id, u16 base, u16 y, u16 x, u16 yoff, u16 xoff) {
    u16 t = x + y * 2;
    *dst = (t + (id + 1) * 4) | (base + (id << 12));
}

// Not called directly (hidden in the tail of build_bg_tile_entry).
void sub_080490F4(u16 *src, u16 *dst, s32 h, s32 w, s32 maxh, s32 pitch, s32 add, s32 pal) {
    s32 i, j;
    if (h > maxh)
        h = maxh;
    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++)
            *dst++ = (*src++ + add) | (pal << 12);
        dst += pitch - w;
    }
}

// Not called directly (hidden in the tail of build_bg_tile_entry).
void sub_0804914C(u8 slot, const void *src) {
    DmaSet(3, src, PLTT + slot * 32, 0x80000008);
}

void fill_tilemap_rect_0804916C(u16 *dst, s32 y, s32 x, s32 w, s32 h, s32 tile, s32 pal, s32 mode) {
    s32 pitch;
    s32 i, j;
    u16 *row;

    switch (mode) {
    case 0:
        pitch = 32;
        break;
    case 1:
        pitch = 64;
        break;
    }
    dst += pitch * y + x;
    for (i = 0; i < h; i++) {
        row = dst;
        for (j = 0; j < w; j++)
            *dst++ = tile + (pal << 12);
        dst = row;
        dst += pitch;
    }
}

void copy_tilemap_region(u16 *src, u16 *dst, s32 y, s32 x, s32 w, s32 h, s32 add, s32 pal, s32 mode) {
    s32 pitch;
    s32 i, j;
    u16 *row;
    u16 v;

    switch (mode) {
    case 0:
        pitch = 32;
        break;
    case 1:
        pitch = 64;
        break;
    }
    dst += pitch * y + x;
    for (i = 0; i < h; i++) {
        row = dst;
        for (j = 0; j < w; j++) {
            v = *src;
            *dst = ((v & 0x3FF) + add) | ((v & 0xC00) | (pal << 12));
            dst++;
            src++;
        }
        dst = row;
        dst += pitch;
    }
}

void copy_tilemap_rect_with_offset(u16 *src, u16 *dst, s32 y, s32 x, s32 w, s32 h, s32 unused6, s32 unused7, s32 add,
                                   s32 mode) {
    s32 pitch;
    s32 i, j;
    u16 *srow;
    u16 *row;

    switch (mode) {
    case 0:
        pitch = 32;
        break;
    case 1:
        pitch = 64;
        break;
    }
    dst += pitch * y + x;
    for (i = 0; i < h; i++) {
        srow = src;
        row = dst;
        for (j = 0; j < w; j++) {
            *dst = *src + add;
            dst++;
            src++;
        }
        dst = row;
        src = srow;
        dst += pitch;
        src += pitch;
    }
}

void sub_080492CC(void) {
    s32 i;
    gUnk_03005310.unk18 = 0;
    gUnk_03005310.unk1A = 0;
    for (i = 0; i < 32; i++) {
        gUnk_03006D40[i].scaleX = 0x100;
        gUnk_03006D40[i].scaleY = 0x100;
        gUnk_03006D40[i].angle = 0;
    }
}

void clear_entity_state(u8 slot) {
    sub_080496C8((u8 *)&gUnk_030055A0[slot], 4);
    sub_080496C8((u8 *)&gUnk_03002C30[slot], 0x40);
}

void calculate_oam_affine_matrix(u8 i) {
    const s16 *sine = gSineTable;
    struct AffineParam *base = gUnk_03006D40;
    struct AffineParam *p = &base[i];
    s32 a;

    p->pa = sub_08048B24(sine[a = p->angle + 0x40], divide_by_65536(p->scaleX));
    p->pb = sub_08048B24(sine[p->angle], divide_by_65536(p->scaleX));
    p->pc = sub_08048B24(-sine[p->angle], divide_by_65536(p->scaleY));
    p->pd = sub_08048B24(sine[a = p->angle + 0x40], divide_by_65536(p->scaleY));
}

void sub_080493D4(u8 idx, u8 val) {
    gUnk_03002C30[idx].unk24 = val;
    gUnk_03002C30[idx].unk23 = 0;
    gUnk_03002C30[idx].unk22 = 0;
}

void advance_sprite_animation_frame(u8 idx) {
    const struct SpriteAnimCmd *c;
    u16 cmd, arg, duration, frame;
    const struct SpriteAnimGfx *gfx;

    c = gUnk_083F7BF4[gUnk_03002C30[idx].unk24];
    cmd = c[gUnk_03002C30[idx].unk22].cmd;
    arg = c[gUnk_03002C30[idx].unk22].arg;
    duration = c[gUnk_03002C30[idx].unk22].duration;
    frame = c[gUnk_03002C30[idx].unk22].frame;

    switch (cmd) {
    case 0xFFFD:
        gUnk_03002C30[idx].unk22++;
        sub_08047BA8(arg);
        advance_sprite_animation_frame(idx);
        break;
    case 0xFFFE:
        gUnk_03002C30[idx].unk22 = arg;
        gUnk_03002C30[idx].unk23 = 0;
        advance_sprite_animation_frame(idx);
        break;
    case 0xFFFA:
        if (gUnk_03002C30[idx].unk23 < duration) {
            gUnk_03002C30[idx].unk6 = frame + gUnk_03002C30[idx].unk2F;
            gUnk_03002C30[idx].unk23++;
            if (gUnk_03002C30[idx].unk23 >= duration) {
                gUnk_03002C30[idx].unk23 = 0;
                gUnk_03002C30[idx].unk22++;
            }
        }
        break;
    case 0xFFFC:
        if (gUnk_03002C30[idx].unk23 == 0) {
            gfx = &gUnk_080AE9FC[arg];
            if (gfx->unk0 == 0)
                LZ77UnCompVram(gfx->src, gfx->dst);
        }
    default:
        if (gUnk_03002C30[idx].unk23 < duration) {
            gUnk_03002C30[idx].unk6 = frame;
            gUnk_03002C30[idx].unk23++;
            if (gUnk_03002C30[idx].unk23 >= duration) {
                gUnk_03002C30[idx].unk23 = 0;
                gUnk_03002C30[idx].unk22++;
            }
        }
        break;
    case 0xFFFF:
        break;
    }
}

// Not called directly (hidden in the tail of advance_sprite_animation_frame).
// guess: debug editor for affine entry 0 / sprite 0 position: A toggles unk18, SELECT + D-pad
// scales and rotates, D-pad moves, R/L change unk1A, START resets the affine params.
u32 sub_0804950C(void) {
    if (KEYS_LO(gNewKeys) & 1)
        gUnk_03005310.unk18 ^= 1;
    if (KEYS_LO(gHeldKeys) & 4) {
        if (KEYS_LO(gHeldKeys) & 0x40) {
            gUnk_03006D40[0].scaleY += 16;
            if (gUnk_03006D40[0].scaleY > 0x400)
                gUnk_03006D40[0].scaleY = 0x400;
        }
        if (KEYS_LO(gHeldKeys) & 0x80) {
            gUnk_03006D40[0].scaleY -= 8;
            if (gUnk_03006D40[0].scaleY < 0x40)
                gUnk_03006D40[0].scaleY = 0x40;
        }
        if (KEYS_LO(gHeldKeys) & 0x20)
            gUnk_03006D40[0].scaleX -= 8;
        if (KEYS_LO(gHeldKeys) & 0x10) {
            gUnk_03006D40[0].scaleX += 16;
            if (gUnk_03006D40[0].scaleX > 0x400)
                gUnk_03006D40[0].scaleX = 0x400;
            gUnk_03006D40[0].angle = (gUnk_03006D40[0].angle + 1) & 0xFF;
        }
        if (KEYS_LO(gHeldKeys) & 0x20)
            gUnk_03006D40[0].angle = (gUnk_03006D40[0].angle + 0xFF) & 0xFF;
    } else {
        if (KEYS_LO(gHeldKeys) & 0x40) {
            gUnk_03002C30[0].unk4 -= 2;
            if (gUnk_03002C30[0].unk4 < -80)
                gUnk_03002C30[0].unk4 = -80;
        }
        if (KEYS_LO(gHeldKeys) & 0x80) {
            gUnk_03002C30[0].unk4 += 2;
            if (gUnk_03002C30[0].unk4 > 80)
                gUnk_03002C30[0].unk4 = 80;
        }
        if (KEYS_LO(gHeldKeys) & 0x10) {
            gUnk_03002C30[0].unk2 += 2;
            if (gUnk_03002C30[0].unk2 > 120)
                gUnk_03002C30[0].unk2 = 120;
        }
        if (KEYS_LO(gHeldKeys) & 0x20) {
            gUnk_03002C30[0].unk2 -= 2;
            if (gUnk_03002C30[0].unk2 < -120)
                gUnk_03002C30[0].unk2 = -120;
        }
        if (KEYS_HI(gNewKeys) & 1) {
            if (gUnk_03005310.unk1A <= 14)
                gUnk_03005310.unk1A++;
        }
        if (KEYS_HI(gNewKeys) & 2) {
            if (gUnk_03005310.unk1A != 0)
                gUnk_03005310.unk1A--;
        }
    }
    if (KEYS_LO(gNewKeys) & 8)
        sub_080492CC();
    return 0;
}

// Not called directly (hidden in the tail of advance_sprite_animation_frame).
void nullsub_080496A0(void) {}

// Not called directly (hidden in the tail of advance_sprite_animation_frame).
void sub_080496A4(u8 slot, const void *src) {
    DmaSet(3, src, OBJ_PLTT + slot * 32, 0x80000008);
}

void sub_080496C8(u8 *dst, u32 size) {
    u32 i;
    for (i = 0; i < size; i++)
        *dst++ = 0;
}

void sub_080496DC(u8 *dst, u32 n, u8 val) {
    u32 i;

    for (i = 0; i < n; i++)
        *dst++ = val;
}

s32 count_byte_differences(const u8 *a, const u8 *b, s32 n) {
    s32 count = 0;
    s32 i;

    for (i = 0; i < n; i++) {
        if (*a++ != *b++)
            count++;
    }
    return count;
}

// Not called directly (hidden in the tail of count_byte_differences at 0x0804971C).
s32 sum_bytes_0804971C(const u8 *p, s32 n) {
    s32 sum = 0;
    s32 i;

    for (i = 0; i < n; i++)
        sum += *p++;
    return sum;
}

u8 field_random(u8 n) {
    const u8 *tbl = gUnk_083F7FF4;
    u8 r;

    r = tbl[(gUnk_030057E0.unkC37 + gUnk_03005310.unk4) & 0xFF];
    gUnk_030057E0.unkC37 = r;
    return Mod(r, n);
}

void memcpy_u8(const void *src, void *dst, u32 n) {
    u32 i;
    for (i = 0; i < n; i++) {
        *((u8 *)dst)++ = *((const u8 *)src)++;
    }
}

void setup_blend_effect(u8 mode, u16 bldcnt, u8 type, u8 sa, u8 sb, u8 sy, u8 a, u8 b, u8 y) {
    if (sa == 0)
        sa = 1;
    if (sb == 0)
        sb = 1;
    if (sy == 0)
        sy = 1;
    gUnk_03006F40.unk0 = mode;
    gUnk_03006F40.unk1 = type;
    gUnk_03006F40.unk14 = 0.0f;
    gUnk_03006F40.unk2 = 1;
    if (mode & 0x80)
        bldcnt |= 0x20;
    else
        bldcnt &= ~0x20;
    switch (gUnk_03006F40.unk1) {
    case 0:
    case 2:
        gUnk_03006F40.unk5 = 16;
        break;
    case 1:
    case 3:
        gUnk_03006F40.unk5 = 16;
        break;
    case 4:
        gUnk_03006F40.unk6 = REG_BLDALPHA & 0x1F;
        gUnk_03006F40.unk7 = (REG_BLDALPHA & 0x1F00) >> 8;
        gUnk_03006F40.unk8 = REG_BLDY & 0x1F;
        gUnk_03006F40.unkC = 0.0f;
        gUnk_03006F40.unk10 = 0.0f;
        gUnk_03006F40.unk18 = (16 - gUnk_03006F40.unk6) / (float)sa;
        gUnk_03006F40.unk1C = (16 - gUnk_03006F40.unk7) / (float)sb;
        goto end;
    case 5:
        gUnk_03006F40.unk6 = a;
        gUnk_03006F40.unk7 = b;
        gUnk_03006F40.unk8 = y;
        gUnk_03006F40.unkC = 0.0f;
        gUnk_03006F40.unk10 = 0.0f;
        gUnk_03006F40.unk18 = (16 - a) / (float)sa;
        gUnk_03006F40.unk1C = (16 - b) / (float)sb;
        gUnk_03006F40.unk3 = 16;
        gUnk_03006F40.unk4 = 16;
        gVBlankCallback = apply_blend_coefficients;
        goto end;
    case 6:
        gUnk_03006F40.unk9 = REG_BLDALPHA & 0x1F;
        gUnk_03006F40.unkA = (REG_BLDALPHA & 0x1F00) >> 8;
        gUnk_03006F40.unk6 = a;
        gUnk_03006F40.unk7 = b;
        gUnk_03006F40.unk8 = y;
        gUnk_03006F40.unkC = 0.0f;
        gUnk_03006F40.unk10 = 0.0f;
        gUnk_03006F40.unk18 = (gUnk_03006F40.unk9 - a) / (float)sa;
        gUnk_03006F40.unk1C = (gUnk_03006F40.unkA - b) / (float)sb;
        goto end;
    default:
        gUnk_03006F40.unk5 = 0;
        break;
    }
end:
    REG_BLDCNT = bldcnt | mode;
}

u32 blend_effect_update(void) {
    u32 done = 0;

    if (gUnk_03006F40.unk2 == 2) {
        done = 1;
        gVBlankCallback = nullsub_08000840;
    } else if (gUnk_03006F40.unk2 == 1) {
        switch (gUnk_03006F40.unk0) {
        case 0x00:
        case 0x40:
            break;
        case 0x80:
        case 0xC0:
            if (gUnk_03006F40.unk14 < 256.0f)
                gUnk_03006F40.unk14 += gUnk_03006F40.unk20;
            else
                gUnk_03006F40.unk14 = 256.0f;
            if (gUnk_03006F40.unk14 >= 256.0f)
                done = 1;
            break;
        }
        switch (gUnk_03006F40.unk1) {
        case 0:
        case 2:
            gUnk_03006F40.unk3 = gUnk_03006F40.unkC * 0.0625f;
            gUnk_03006F40.unk4 = gUnk_03006F40.unk10 * 0.0625f;
            gUnk_03006F40.unk5 = gUnk_03006F40.unk14 * 0.0625f;
            break;
        case 1:
        case 3:
            gUnk_03006F40.unk3 = 16.0f - gUnk_03006F40.unkC * 0.0625f;
            gUnk_03006F40.unk4 = 16.0f - gUnk_03006F40.unk10 * 0.0625f;
            gUnk_03006F40.unk5 = 16.0f - gUnk_03006F40.unk14 * 0.0625f;
            break;
        case 4:
            gUnk_03006F40.unkC += gUnk_03006F40.unk18;
            gUnk_03006F40.unk3 = (u8)gUnk_03006F40.unkC + gUnk_03006F40.unk6;
            if (gUnk_03006F40.unk3 > 15) {
                gUnk_03006F40.unk3 = 16;
                done = 1;
            }
            gUnk_03006F40.unk10 += gUnk_03006F40.unk1C;
            gUnk_03006F40.unk4 = (u8)gUnk_03006F40.unk10 + gUnk_03006F40.unk7;
            if (gUnk_03006F40.unk4 > 15) {
                gUnk_03006F40.unk4 = 16;
                done = 1;
            }
            break;
        case 5:
            gUnk_03006F40.unkC += gUnk_03006F40.unk18;
            gUnk_03006F40.unk3 = 16 - (u8)gUnk_03006F40.unkC;
            if (gUnk_03006F40.unk3 <= gUnk_03006F40.unk6) {
                gUnk_03006F40.unk3 = gUnk_03006F40.unk6;
                done = 1;
            }
            gUnk_03006F40.unk10 += gUnk_03006F40.unk1C;
            gUnk_03006F40.unk4 = 16 - (u8)gUnk_03006F40.unk10;
            if (gUnk_03006F40.unk4 <= gUnk_03006F40.unk7) {
                gUnk_03006F40.unk4 = gUnk_03006F40.unk7;
                done = 1;
            }
            break;
        case 6:
            gUnk_03006F40.unkC += gUnk_03006F40.unk18;
            gUnk_03006F40.unk3 = gUnk_03006F40.unk9 - (u8)gUnk_03006F40.unkC;
            if (gUnk_03006F40.unk6 != gUnk_03006F40.unk9) {
                if (gUnk_03006F40.unk3 >= gUnk_03006F40.unk6) {
                    gUnk_03006F40.unk3 = gUnk_03006F40.unk6;
                    done = 1;
                }
            } else if (gUnk_03006F40.unk3 <= gUnk_03006F40.unk6) {
                gUnk_03006F40.unk3 = gUnk_03006F40.unk6;
                done = 1;
            }
            gUnk_03006F40.unk10 += gUnk_03006F40.unk1C;
            gUnk_03006F40.unk4 = gUnk_03006F40.unkA - (u8)gUnk_03006F40.unk10;
            if (gUnk_03006F40.unk7 != gUnk_03006F40.unkA) {
                if (gUnk_03006F40.unk4 >= gUnk_03006F40.unk7) {
                    gUnk_03006F40.unk4 = gUnk_03006F40.unk7;
                    done = 1;
                }
            } else if (gUnk_03006F40.unk4 <= gUnk_03006F40.unk7) {
                gUnk_03006F40.unk4 = gUnk_03006F40.unk7;
                done = 1;
            }
            break;
        }
    }
    gVBlankCallback = apply_blend_coefficients;
    if (done) {
        done = 0;
        gUnk_03006F40.unk2 = 2;
    }
    return done;
}
// TEMP (testing only): libgcc.s has no __subsf3/__ltsf2/__gesf2/... aliases yet; remove once it does.

void apply_blend_coefficients(void) {
    REG_BLDALPHA = ((gUnk_03006F40.unk4 & 0x3F) << 8) | (gUnk_03006F40.unk3 & 0x3F);
    REG_BLDY = gUnk_03006F40.unk5 & 0x3F;
}

void sub_08049CB0(u16 color, u32 amount) {
    palette_blend_to_color_080013A8(color, amount);
}

void sub_08049CC0(void) {
    copy_obj_palette_to_buffer();
}

void setup_palette_fade_to_color(u16 color, float start, float end, float steps) {
    // called without a prototype in the original (the float is passed as a double)
    ((void (*)())palette_blend_to_color_080013A8)(color, start);
    gUnk_03006F40.unk24 = start;
    gUnk_03006F40.unk28 = start;
    gUnk_03006F40.unk2C = end;
    gUnk_03006F40.unk30 = (start - end) / steps;
    setup_blend_effect(0x40, 0x2F00, 5, steps, steps, steps, 12, 10, 0);
}

// TEMP (testing only): libgcc.s lacks these __*sf* aliases; remove once added there.

void setup_palette_fade_to_color_with_obj(u16 color, float start, float end, float steps) {
    sub_08049CC0();
    // called without a prototype in the original (the float is passed as a double)
    ((void (*)())palette_blend_to_color_080013A8)(color, start);
    gUnk_03006F40.unk24 = start;
    gUnk_03006F40.unk28 = start;
    gUnk_03006F40.unk2C = end;
    gUnk_03006F40.unk30 = (start - end) / steps;
    setup_blend_effect(0x40, 0x2F00, 4, steps, steps, steps, 16, 16, 0);
}

// TEMP (testing only): libgcc.s lacks these __*sf* aliases; remove once added there.

u32 run_blend_fade_transition(u16 color) {
    u32 done = 0;

    blend_effect_update();
    gUnk_03005350.unk20A = 0xFFFF;
    gUnk_03005350.unk20C = 0xBFFF;
    sub_08049E74(color, gUnk_03006F40.unk24, gUnk_03005350.unk20A);
    sub_08049E88(color, gUnk_03006F40.unk24, gUnk_03005350.unk20C);
    gUnk_03006F40.unk24 -= gUnk_03006F40.unk30;
    if (gUnk_03006F40.unk30 > 0.0f) {
        if (gUnk_03006F40.unk24 < gUnk_03006F40.unk2C) {
            gVBlankCallback = nullsub_08000840;
            done = 1;
        }
    } else if (gUnk_03006F40.unk24 > gUnk_03006F40.unk2C) {
        gVBlankCallback = nullsub_08000840;
        done = 1;
    }
    return done;
}

// TEMP (testing only): libgcc.s lacks these __*sf* aliases; remove once added there.

void sub_08049E74(u16 a, u32 b, u16 c) {
    blend_obj_palettes_to_color_0803F684(a, b, c);
}

void sub_08049E88(u16 a, u32 b, u16 c) {
    blend_obj_palettes_to_color_0803F998(a, b, c);
}

// Sorts arr[left..right] in ascending order (quicksort, pivot arr[left]).
void quicksort_u8_array(u8 *arr, s16 left, s16 right) {
    s32 i, j;
    u8 tmp;

    if (left < right) {
        i = left + 1;
        j = right;
        while (i <= j) {
            for (; i <= j; i++)
                if (arr[i] > arr[left])
                    break;
            for (; i <= j; j--)
                if (arr[j] < arr[left])
                    break;
            if (i >= j)
                break;
            tmp = arr[j];
            arr[j] = arr[i];
            arr[i] = tmp;
            i++;
            j--;
        }
        tmp = arr[j];
        arr[j] = arr[left];
        arr[left] = tmp;
        quicksort_u8_array(arr, left, j - 1);
        quicksort_u8_array(arr, j + 1, right);
    }
}

// Not called directly (hidden in the tail of quicksort_u8_array).
// guess: sorts u16 entries by their low byte, ascending
void sub_08049F84(u16 *arr, s16 left, s16 right) {
    s32 i, j;
    u16 tmp;

    if (left < right) {
        i = left + 1;
        j = right;
        while (i <= j) {
            for (; i <= j; i++)
                if ((arr[i] & 0xFF) >= (arr[left] & 0xFF))
                    break;
            for (; i <= j; j--)
                if ((arr[j] & 0xFF) <= (arr[left] & 0xFF))
                    break;
            if (i >= j)
                break;
            tmp = arr[j];
            arr[j] = arr[i];
            arr[i] = tmp;
            i++;
            j--;
        }
        tmp = arr[j];
        arr[j] = arr[left];
        arr[left] = tmp;
        sub_08049F84(arr, left, j - 1);
        sub_08049F84(arr, j + 1, right);
    }
}

// Not called directly (hidden in the tail of quicksort_u8_array).
// guess: sorts u16 entries by their low byte, descending
void sub_0804A0A4(u16 *arr, s16 left, s16 right) {
    s32 i, j;
    u16 tmp;

    if (left < right) {
        i = left + 1;
        j = right;
        while (i <= j) {
            for (; i <= j; i++)
                if ((arr[i] & 0xFF) <= (arr[left] & 0xFF))
                    break;
            for (; i <= j; j--)
                if ((arr[j] & 0xFF) >= (arr[left] & 0xFF))
                    break;
            if (i >= j)
                break;
            tmp = arr[j];
            arr[j] = arr[i];
            arr[i] = tmp;
            i++;
            j--;
        }
        tmp = arr[j];
        arr[j] = arr[left];
        arr[left] = tmp;
        sub_0804A0A4(arr, left, j - 1);
        sub_0804A0A4(arr, j + 1, right);
    }
}

void sub_0804A1C4(void) {
    gGameSubState++;
}

// Copies the 32 affine matrices (pa..pd at +6 of each 16-byte gUnk_03006D40 entry) into the
// affineParam slots of gOamBuffer.
static inline void copy_affine(u8 *base) {
    u16 *src = (u16 *)(base + 6);
    struct OamData *oam = gOamBuffer;
    s32 i;

    for (i = 31; i >= 0; i--) {
        oam[0].affineParam = src[0];
        oam[1].affineParam = src[1];
        oam[2].affineParam = src[2];
        oam[3].affineParam = src[3];
        src += 8;
        oam += 4;
    }
}

// Per-frame update of the field game mode (game mode table 0x083D1F84 entry 1): frame counter,
// map script, the gGameSubState handler from gFieldSubStates, sprites, BG tile animation, OAM affine matrices
void field_update(void) {
    s32 i;

    gUnk_03005310.unk4++;
    if (gUnk_030057E0.unkC88) {
        if (gUnk_030057E0.unkC89)
            map_script_update_command();
        else
            map_script_run_command();
        if (gUnk_030057E0.unkC5F)
            gFieldSubStates[gGameSubState]();
    } else {
        gFieldSubStates[gGameSubState]();
    }
    update_entity_sprites_on_screen();
    update_npc_sprite_animations();
    animate_area_bg_tiles();
    for (i = 0; i < 32; i++)
        calculate_oam_affine_matrix(i);
    update_battle_entity_status_chars();
    copy_affine((u8 *)gUnk_03006D40);
}

void new_game_init(void) {
    u32 zero;

    sub_080496C8((u8 *)&gUnk_03002B70, 0x1C);
    sub_080496C8((u8 *)gUnk_03000BE0, 0x780);
    sub_080496C8(gMedapartInventory, 0x3C0);
    sub_080496C8((u8 *)gUnk_030017A0, 0x48);
    sub_080496C8((u8 *)gItemInventory, 0x80);
    sub_080496C8((u8 *)&gUnk_030057E0, 0xCC0);
    sub_080496C8((u8 *)&gUnk_03000440, 0x13C);
    sub_080496C8((u8 *)gUnk_03000590, 0x600);
    clear_oam();
    sub_080496C8((u8 *)gUnk_03002C30, 0x2000);
    sub_080496C8((u8 *)gUnk_030055A0, 0x200);
    zero = 0;
    DmaSet(3, &zero, OAM, 0x85000100);
    sub_08041D28();
    sub_080421A0();
    gUnk_030057E0.unkCBC = 16;
    gUnk_030057E0.unkCBD = 16;
    REG_BG1CNT = 0xC609;
    REG_BG2CNT = 0xEA0A;
    REG_BG3CNT = 0xEE0B;
    REG_DISPCNT = 0x1E40;
    gMapScriptData = (u8 *)gUnk_08764CB0;
    gUnk_030057D8 = (u8 *)&gUnk_030057E0;
    gUnk_03006D30 = (struct BattleEntity3D *)0x02039000;
    gUnk_03006D14 = (u16 *)0x02030000;
    gUnk_030057DC = (u8 *)0x02038000;
    sub_080496C8((u8 *)gUnk_03002C30, 0x2000);
    sub_080496C8((u8 *)gUnk_030055A0, 0x200);
    zero = 0;
    DmaSet(3, &zero, OAM, 0x85000100);
    sub_080492CC();
    sub_08048B6C();
    gUnk_03005310.unk1C = 0;
    gUnk_03005310.unk24 = 0;
    gUnk_03005310.unk1E = 0;
    gUnk_03005310.unk26 = 0;
    gUnk_03005310.unk20 = 0;
    gUnk_03005310.unk28 = 0;
    gUnk_03005310.unk22 = 0;
    gUnk_03005310.unk2A = 0;
    gBg0Scroll.x = 0;
    gBg0Scroll.y = 0;
    gBg1Scroll.x = 0;
    gBg1Scroll.y = 0;
    gBg2Scroll.x = 0;
    gBg2Scroll.y = 0;
    gBg3Scroll.x = 0;
    gBg3Scroll.y = 0;
    sub_080496C8(&gUnk_030057E0.unk7FC, 0x454);
    gUnk_030057E0.unkCBA = 0;
    gUnk_030057E0.unk7FE = 0x17;
    gUnk_030057E0.unk7FC = 0xE;
    gUnk_030057E0.unk7FD = 7;
    gUnk_030057E0.unkC52 = gUnk_030057E0.unkC48 + 0x120;
    gUnk_030057E0.unkC54 = gUnk_030057E0.unkC4A + 0xD0;
    gUnk_030057E0.unkC67 = 0;
    gUnk_030057E0.unkC34 = 1;
    gUnk_030057E0.unkC56 = sub_080526F0(gUnk_030057E0.unkC52);
    gUnk_030057E0.unkC57 = sub_08052714(gUnk_030057E0.unkC54);
    gUnk_030057E0.unkC5C = 0;
    gUnk_030057E0.unkC5B = 1;
    init_battle_sprite_entry_08048818(0x2F, 0xC804, 3, 0, 1);
    update_bg_scroll_offsets_a();
    if (gUnk_030057E0.unkC76) {
        init_battle_sprite_entry_08048818(0x30, 0xC804, gUnk_030057E0.unkC84 * 12 + gUnk_030057E0.unkC83,
                                          gUnk_030057E0.unkC84, 1);
        gUnk_030057E0.unkC6E = 0x50 - gUnk_030057E0.unkC48;
        gUnk_030057E0.unkC70 = 0x60 - gUnk_030057E0.unkC4A;
    }
    gUnk_03005310.unk1 = 0;
    REG_BLDCNT = 0;
    REG_BLDY = 0;
    sub_080487E4();
    setup_palette_fade_to_color(0x7FFF, 32.0f, 0.0f, 8.0f);
    sub_0804A1C4();
}

void sub_0804A5C0(void) {
    u32 zero;
    sub_080496C8((u8 *)gUnk_03002C30, 0x2000);
    sub_080496C8((u8 *)gUnk_030055A0, 0x200);
    zero = 0;
    DmaSet(3, &zero, OAM, 0x85000100);
    sub_080492CC();
    sub_08048B6C();
    gUnk_030057E0.unkC8A = 0;
    gUnk_030057E0.unkC88 = 0;
    gUnk_030057E0.unkC89 = 0;
    setup_palette_fade_to_color(0x7FFF, 32.0f, 0.0f, 8.0f);
    sub_0804A1C4();
}

void sub_0804A654(void) {
    update_battle_field_frame();
    load_battlefield_data_to_buffer();
    dispatch_jump_table_29(0, 0);
    sub_0804A1C4();
}

void sub_0804A670(void) {
    sub_0804A1C4();
}

void sub_0804A67C(void) {
    if (run_blend_fade_transition(0x7FFF))
        sub_0804A1C4();
}

void sub_0804A694(void) {
    sub_08050F10();
}

void sub_0804A6A0(void) {
    sub_0804A1C4();
}

void sub_0804A6AC(void) {
    sub_0804B1FC();
    restore_script_sprites();
    dispatch_jump_table_29(5, 0);
    gUnk_03005310.unk1 = 0;
    gGameSubState = 5;
}

void sub_0804A6D8(void) {
    init_cursor_state();
    sub_0804A1C4();
}

void sub_0804A6E8(void) {
    s32 exit = check_room_exit_at_position();
    if (scene_transition_step_08047C24(0, 0, 0, gUnk_08411D54[exit]))
        gGameSubState = 5;
}

void sub_0804A718(void) {
    u32 zero;
    clear_oam();
    sub_080496C8((u8 *)gUnk_03002C30, 0x2000);
    sub_080496C8((u8 *)gUnk_030055A0, 0x200);
    zero = 0;
    DmaSet(3, &zero, OAM, 0x85000100);
    sub_080496C8((u8 *)&gUnk_03000440, 0x13C);
    sub_080496C8((u8 *)gUnk_03000590, 0x600);
    gUnk_030057E0.unkC88 = 0;
    gUnk_030057E0.unkC89 = 0;
    gUnk_030057E0.unkC93 = 0;
    gUnk_030057E0.unkC8A = 0;
    gUnk_030057E0.unkC8E = 0;
    gUnk_030057E0.unkC5F = 0;
    gUnk_030057E0.unkC60 = 0;
    gUnk_03005310.unk38 = 0;
    sub_080496C8((u8 *)&gUnk_03006D20, 16);
    sub_0804B1FC();
    gUnk_03005310.unk1 = 0;
    restore_script_sprites();
    gUnk_03005590 = gUnk_08764CB0;
    gUnk_030057D8 = (u8 *)&gUnk_030057E0;
    gUnk_03006D30 = (struct BattleEntity3D *)0x02039000;
    gUnk_03006D14 = (u16 *)0x02030000;
    gUnk_030057DC = (u8 *)0x02038000;
    sub_080496C8((u8 *)gUnk_03002C30, 0x2000);
    sub_080496C8((u8 *)gUnk_030055A0, 0x200);
    zero = 0;
    DmaSet(3, &zero, OAM, 0x85000100);
    REG_BLDCNT = 0;
    REG_BLDY = 0;
    REG_DISPCNT = 0x1E40;
    gUnk_030057E0.unkCBA = 2;
    update_battle_field_frame();
    load_battlefield_data_to_buffer();
    dispatch_jump_table_29(0x1C, 0);
    field_center_camera_on_player();
    sub_080487E4();
    setup_palette_fade_to_color(0x7FFF, 32.0f, 0.0f, 8.0f);
    sub_0804A1C4();
}

void sub_0804A8B4(void) {
    if (run_blend_fade_transition(0x7FFF)) {
        gUnk_03005310.unk1 = 0;
        init_battle_field_setup();
        update_bg_scroll_offsets_a();
        field_set_player_facing(gUnk_030057E0.unkC67);
        gGameSubState = 5;
    }
}

void sub_0804A8F8(void) {
    u32 zero;
    sub_080496C8((u8 *)gUnk_03002C30, 0x2000);
    sub_080496C8((u8 *)gUnk_030055A0, 0x200);
    zero = 0;
    DmaSet(3, &zero, OAM, 0x85000100);
    zero = 0;
    DmaSet(3, &zero, PLTT, 0x85000100);
    REG_BLDCNT = 0;
    REG_BLDY = 0;
    gUnk_03005310.unk1 = 0;
    restore_script_sprites();
    REG_DISPCNT = 0x1E40;
    gUnk_030057E0.unkCBA = 2;
    update_battle_field_frame();
    load_battlefield_data_to_buffer();
    dispatch_jump_table_29(0xE, 0);
    field_center_camera_on_player();
    sub_080487E4();
    setup_palette_fade_to_color(0, 32.0f, 0.0f, 8.0f);
    sub_0804A1C4();
}

void sub_0804A9B8(void) {
    if (run_blend_fade_transition(0)) {
        gUnk_03005310.unk1 = 0;
        init_battle_field_setup();
        update_bg_scroll_offsets_a();
        field_set_player_facing(gUnk_030057E0.unkC67);
        gGameSubState = 5;
    }
}

void sub_0804A9F8(void) {
    if (gUnk_030057E0.unkC5C == gUnk_030057E0.unkC69) {
        gUnk_030057E0.unkC5C = 0;
        gUnk_030057E0.unkC69 = 0;
    } else
        gUnk_030057E0.unkC69 = gUnk_030057E0.unkC5C;
    sub_0804A1C4();
}

void sub_0804AA28(void) {
    u32 zero;
    sub_080496C8((u8 *)gUnk_03002C30, 0x2000);
    sub_080496C8((u8 *)gUnk_030055A0, 0x200);
    zero = 0;
    DmaSet(3, &zero, OAM, 0x85000100);
    sub_0804B1FC();
    REG_DISPCNT = 0x1E40;
    gUnk_030057E0.unkCBA = 2;
    update_battle_field_frame();
    dispatch_jump_table_29(6, 0);
    setup_palette_fade_to_color(0, 32.0f, 0.0f, 8.0f);
    sub_0804A1C4();
}

void sub_0804AAB8(void) {
    if (run_blend_fade_transition(0))
        sub_0804A1C4();
}

void sub_0804AACC(void) {
    sub_0804A1C4();
}

// Not called directly (hidden in the tail of sub_0804AACC).
void sub_0804AAD8(void) {
    gUnk_03005310.unk1 = 0;
    gGameSubState = 5;
}

void sub_0804AAF0(void) {
    sub_0804A1C4();
}

// Not called directly (hidden in the tail of sub_0804AAF0).
void sub_0804AAFC(void) {
    sub_0804A1C4();
}

// Not called directly (hidden in the tail of sub_0804AAF0).
void sub_0804AB08(void) {
    sub_0804A1C4();
}

void sub_0804AB14(void) {
    if (gUnk_030057E0.unkC5C != 1) {
        gUnk_030057E0.unkC69 = gUnk_030057E0.unkC5C;
        gUnk_030057E0.unkC5C = 1;
    } else
        gUnk_030057E0.unkC5C = gUnk_030057E0.unkC69;
    load_battle_palette_via_dma(0);
    dispatch_jump_table_29(7, 0);
    sub_0804A1C4();
}

// Not called directly (hidden in the tail of sub_0804AB14).
void sub_0804AB5C(void) {
    gUnk_03005310.unk1 = 0;
    gGameSubState = 5;
}

void sub_0804AB74(void) {
    sub_0804A1C4();
}

void sub_0804AB80(void) {
    if (gUnk_030057E0.unkC5C != 2) {
        gUnk_030057E0.unkC69 = gUnk_030057E0.unkC5C;
        gUnk_030057E0.unkC5C = 2;
    } else
        gUnk_030057E0.unkC5C = gUnk_030057E0.unkC69;
    load_battle_palette_via_dma(0);
    dispatch_jump_table_29(8, 0);
    sub_0804A1C4();
}

void sub_0804ABC8(void) {
    s32 r;
    struct Unk_030057E0 *s;
    r = sub_080518F4(47);
    s = &gUnk_030057E0;
    s->unkC58 = 0x10 / r;
    field_set_player_facing(gUnk_03002C30[47].unk20);
    sub_080493D4(47, gUnk_03002C30[47].unk20);
    if (s->unkC76) {
        s->unkC6E = s->unkC52;
        s->unkC70 = s->unkC54;
        set_battle_state_byte_c83(gUnk_03002C30[47].unk20);
        sub_080493D4(48, gUnk_03002C30[48].unk2B * 4 + gUnk_03002C30[48].unk20);
    }
    update_battle_direction_indicator(1);
    sub_08047BA8(0x57);
    gUnk_03005310.unk1 = 1;
    gGameSubState = 5;
}

void sub_0804AC7C(void) {
    sub_0804A1C4();
}

void sub_0804AC88(void) {
    vu32 zero;

    sub_080496C8((u8 *)gUnk_03002C30, 0x2000);
    sub_080496C8((u8 *)gUnk_030055A0, 0x200);
    zero = 0;
    DmaSet(3, &zero, OAM, 0x85000100);
    sub_0804B1FC();
    REG_DISPCNT = 0x1E40;
    gUnk_030057E0.unkCBA = 2;
    update_battle_field_frame();
    load_battlefield_data_to_buffer();
    dispatch_jump_table_29(0xB, 0);
    setup_palette_fade_to_color(0, 32.0f, 0.0f, 8.0f);
    sub_0804A1C4();
}

void sub_0804AD1C(void) {
    if (run_blend_fade_transition(0)) {
        gUnk_030057E0.unkC5C = 0xB;
        load_battle_palette_via_dma(0);
        init_sprite_affine_matrices_and_state(0x12, gUnk_030057E0.unkC52, gUnk_030057E0.unkC54, 0);
        sub_0804A1C4();
    }
}

void sub_0804AD68(void) {
    if (sub_0804B694()) {
        gUnk_030057E0.unkC5C = gUnk_030057E0.unkC69;
        load_battle_palette_via_dma(0);
        gUnk_030057E0.unkC67 = 1;
        gUnk_03005310.unk1 = 0;
        init_battle_field_setup();
        update_bg_scroll_offsets_a();
        field_set_player_facing(gUnk_030057E0.unkC67);
        if (gUnk_030057E0.unkC76) {
            gUnk_030057E0.unkC6E = gUnk_030057E0.unkC52;
            gUnk_030057E0.unkC70 = gUnk_030057E0.unkC54;
            set_battle_state_byte_c83(gUnk_03002C30[47].unk20);
            sub_080493D4(0x30, gUnk_03002C30[48].unk2B * 4 + gUnk_03002C30[48].unk20);
        }
        update_battle_entity_status_chars();
        gGameSubState = 5;
    }
}

void nullsub_0804AE2C(void) {}

void nullsub_0804AE30(void) {}

void sub_0804AE34(void) {
    gUnk_030057E0.unkC5C = 0xC;
    load_battle_palette_via_dma(0);
    dispatch_jump_table_29(9, 0);
    init_sprite_affine_matrices_and_state(0xE, gUnk_030057E0.unkC52, gUnk_030057E0.unkC54, 0);
    sub_0804A1C4();
}

void sub_0804AE7C(void) {
    if (sub_0804B694()) {
        gUnk_030057E0.unkC5C = gUnk_030057E0.unkC69;
        load_battle_palette_via_dma(0);
        gUnk_030057E0.unkC67 = 1;
        gUnk_03005310.unk1 = 0;
        init_battle_field_setup();
        update_bg_scroll_offsets_a();
        field_set_player_facing(gUnk_030057E0.unkC67);
        if (gUnk_030057E0.unkC76) {
            gUnk_030057E0.unkC6E = gUnk_030057E0.unkC52;
            gUnk_030057E0.unkC70 = gUnk_030057E0.unkC54;
            set_battle_state_byte_c83(gUnk_03002C30[47].unk20);
            sub_080493D4(0x30, gUnk_03002C30[48].unk2B * 4 + gUnk_03002C30[48].unk20);
        }
        update_battle_entity_status_chars();
        gGameSubState = 5;
    }
}

void nullsub_0804AF40(void) {}

void nullsub_0804AF44(void) {}

void nullsub_0804AF48(void) {}

void sub_0804AF4C(void) {
    struct Unk_030057A0 *s = &gUnk_030057A0;

    if (s->unk11 == 0) {
        s->unk10 = 1;
        sub_08058110(0);
    }
    sub_0804A1C4();
}

void sub_0804AF6C(void) {
    sub_08058214(gUnk_030057A0.unk14);
}

void sub_0804AF80(void) {
    if (sub_0805937C())
        handle_battle_end_state_transition();
}

void sub_0804AF94(void) {
    setup_palette_fade_to_color_with_obj(0x7FFF, 0.0f, 32.0f, 8.0f);
    sub_0804A1C4();
}

void sub_0804AFBC(void) {
    s32 x, y;

    if (run_blend_fade_transition(0x7FFF)) {
        gMapScriptData = (u8 *)gUnk_08764CB0;
        if (gUnk_030057A0.unk14 == 0)
            gUnk_030057E0.unk7FE = gUnk_030057A0.unk26;
        field_load_area_tiles(gUnk_030057E0.unk7FE);
        x = sub_080526F0(gUnk_030057E0.unkC52);
        y = sub_08052714(gUnk_030057E0.unkC54);
        if (gUnk_030057E0.unkC56 >= sub_08052960(gUnk_030057E0.unk7FE, 0) / 2)
            x = sub_08052960(gUnk_030057E0.unk7FE, 0) / 2 - 1;
        if (gUnk_030057E0.unkC57 >= sub_08052960(gUnk_030057E0.unk7FE, 1) / 2)
            y = sub_08052960(gUnk_030057E0.unk7FE, 1) / 2 - 1;
        gUnk_030057E0.unkC52 = (x << 4) + gUnk_030057E0.unkC48;
        gUnk_030057E0.unkC54 = (y << 4) + gUnk_030057E0.unkC4A;
        gUnk_030057E0.unkC56 = sub_080526F0(gUnk_030057E0.unkC52);
        gUnk_030057E0.unkC57 = sub_08052714(gUnk_030057E0.unkC54);
        field_center_camera_on_player();
        gUnk_030057E0.unkC28 = gUnk_030057E0.unkC5C;
        load_battle_terrain_data();
        REG_DISPCNT = 0x1E40;
        sub_0804B1FC();
        gUnk_030057E0.unkCBA = 0;
        gGameSubState = 1;
    }
}

void nullsub_0804B110(void) {}

void sub_0804B114(void) {
    const struct AreaWarp *w = gUnk_08413114[gUnk_030057E0.unk7FE];
    s32 i;

    for (i = 0; w[i].x != 0xFF; i++)
        gUnk_030057E0.unk810[w[i].y * (gUnk_030057E0.unk800 >> 1) + w[i].x] = 2;
}

void update_battle_entity_status_chars(void) {
    s32 i;

    if (gUnk_030057E0.unkC4C) {
        for (i = 0x2E; i <= 0x7F; i++) {
            if (gUnk_03002C30[i].unkB == 0xFF)
                gUnk_03002C30[i].unkB = 0xFF;
            else if (gUnk_03002C30[i].unkB != 0)
                gUnk_03002C30[i].unkB = (gUnk_03002C30[i].unk4 + 0x10) / 4 + 0x40;
            else
                gUnk_03002C30[i].unkB = 0;
            if (i == 0x30 && gUnk_030057E0.unkC70 == gUnk_030057E0.unkC54)
                gUnk_03002C30[48].unkB = gUnk_03002C30[47].unkB - 1;
            if (i == 0x59 && gUnk_030057E0.unkC70 == gUnk_030057E0.unkC54)
                gUnk_03002C30[0x59].unkB = gUnk_03002C30[48].unkB - 1;
        }
    }
}

void sub_0804B1FC(void) {
    vu32 zero;

    zero = 0;
    DmaSet(3, &zero, VRAM + 0x1000, 0x85000800);
}

void sub_0804B224(void) {
    vu32 zero;

    zero = 0;
    DmaSet(3, &zero, VRAM + 0x2800, 0x85001A00);
}

void clear_vram_bg2_tiles(void) {
    sub_080496DC((u8 *)(VRAM + 0x3000), 0x6000, 0x80);
}

// gUnk_083F92F4 indexed as a flat pointer array (three LZ77 tilemaps per area: unk0, unk4, unk8);
// the index has to reach the load unfolded ((area * 3 + 1) << 2), hence the helper.
static inline const void *area_gfx(const void *const *t, u32 i) {
    return t[i];
}

// Sets BG1-3 control, loads the area's tile map and its three BG layers (or blank tiles and a fill
// when the area has no layer graphics), then centres the camera.
void load_room_graphics(void) {
    const void *const *tbl;
    REG_BG1CNT = 0xC609;
    REG_BG2CNT = 0xEA0A;
    REG_BG3CNT = 0xEE0B;
    field_load_area_tiles(gUnk_030057E0.unk7FE);
    gUnk_030057E0.unk800 = sub_08052960(gUnk_030057E0.unk7FE, 0);
    gUnk_030057E0.unk802 = sub_08052960(gUnk_030057E0.unk7FE, 1);
    gUnk_030057E0.unk804 = sub_08052990(gUnk_030057E0.unk7FE, 0);
    gUnk_030057E0.unk806 = sub_08052990(gUnk_030057E0.unk7FE, 1);
    clear_vram_bg2_tiles();
    sub_080496C8(gUnk_030057E0.unk810, 0x400);
    memcpy_u8(gUnk_084045A8[gUnk_030057E0.unk7FE], gUnk_030057E0.unk810,
              (gUnk_030057E0.unk802 >> 1) * (gUnk_030057E0.unk800 >> 1));
    tbl = (const void *const *)gUnk_083F92F4;
    if (area_gfx(tbl, gUnk_030057E0.unk7FE * 3) != NULL && gUnk_083F8CF4[gUnk_030057E0.unk7FE] != NULL) {
        LZ77UnCompVram(gUnk_083F8CF4[gUnk_030057E0.unk7FE], (void *)0x06009000);
        LZ77UnCompVram(area_gfx(tbl, gUnk_030057E0.unk7FE * 3), gUnk_03006D14);
        copy_tilemap_with_offset_08048CA4(gUnk_03006D14 + 8, (void *)0x06003000, gUnk_030057E0.unk806,
                                          gUnk_030057E0.unk804, 0x40, 0x40, 0x80);
        LZ77UnCompVram(area_gfx(tbl, gUnk_030057E0.unk7FE * 3 + 1), gUnk_03006D14);
        copy_tilemap_with_offset_08048CA4(gUnk_03006D14 + 8, (void *)0x06005000, gUnk_030057E0.unk806,
                                          gUnk_030057E0.unk804, 0x40, 0x40, 0x80);
        LZ77UnCompVram(area_gfx(tbl, gUnk_030057E0.unk7FE * 3 + 2), gUnk_03006D14);
        copy_tilemap_with_offset_08048CA4(gUnk_03006D14 + 8, (void *)0x06007000, gUnk_030057E0.unk806,
                                          gUnk_030057E0.unk804, 0x40, 0x40, 0x80);
        if (gUnk_083F8FF4[gUnk_030057E0.unk7FE] != NULL)
            LZ77UnCompVram(gUnk_083F8FF4[gUnk_030057E0.unk7FE], gUnk_030057DC);
    } else {
        sub_080496C8((u8 *)0x06009000, 0x80);
        DmaSet(3, gUnk_080AC5D4, 0x06009080, 0x80000040);
        DmaSet(3, gUnk_080AC674, 0x06009100, 0x80000040);
        DmaSet(3, gUnk_080AC714, 0x06009180, 0x80000040);
        DmaSet(3, gUnk_080AC7B4, 0x06009200, 0x80000040);
        DmaSet(3, gUnk_080AC5D4, 0x06009280, 0x80000040);
        DmaSet(3, gUnk_080AC5D4, 0x06009300, 0x80000040);
        DmaSet(3, gUnk_080AC5D4, 0x06009380, 0x80000040);
        DmaSet(3, gUnk_080AC854, 0x06009400, 0x80000040);
        DmaSet(3, gUnk_080AC8F4, 0x06009480, 0x80000040);
        sub_080496DC((u8 *)gUnk_03006D14, gUnk_030057E0.unk802 * gUnk_030057E0.unk800, 8);
        copy_tiles_to_bg_tilemap(gUnk_03006D14, (void *)0x06003000, gUnk_030057E0.unk802, gUnk_030057E0.unk800, 0x40,
                                 0x40, gUnk_030057E0.unkC4A / 8, gUnk_030057E0.unkC48 / 8, 0x80);
        copy_tiles_to_bg_tilemap(gUnk_03006D14, (void *)0x06005000, gUnk_030057E0.unk802, gUnk_030057E0.unk800, 0x40,
                                 0x40, gUnk_030057E0.unkC4A / 8, gUnk_030057E0.unkC48 / 8, 0x80);
        copy_tiles_to_bg_tilemap(gUnk_030057E0.unk810, (void *)0x06007000, gUnk_030057E0.unk802, gUnk_030057E0.unk800,
                                 0x40, 0x40, gUnk_030057E0.unkC4A / 8, gUnk_030057E0.unkC48 / 8, 0x80);
    }
    field_center_camera_on_player();
    check_and_update_battlefield_palette();
}

void update_blend_effect_from_input(void) {
    if (KEYS_LO(gNewKeys) & 0x40) {
        gUnk_03006F40.unk14 += 1.0f;
        gUnk_03006F40.unk14 = (s32)((u32)gUnk_03006F40.unk14 & 0xF);
        REG_BLDY = (u32)gUnk_03006F40.unk14 % 64;
    }
    if (KEYS_HI(gNewKeys) & 1) {
        gUnk_03006F40.unkC += 1.0f;
        gUnk_03006F40.unkC = (s32)((u32)gUnk_03006F40.unkC & 0xF);
        REG_BLDALPHA = (((u32)gUnk_03006F40.unk10 & 0x3F) << 8) | ((u32)gUnk_03006F40.unkC & 0x3F);
    }
    if (KEYS_HI(gNewKeys) & 2) {
        gUnk_03006F40.unk10 += 1.0f;
        gUnk_03006F40.unk10 = (s32)((u32)gUnk_03006F40.unk10 & 0xF);
        REG_BLDALPHA = (((u32)gUnk_03006F40.unk10 & 0x3F) << 8) | ((u32)gUnk_03006F40.unkC & 0x3F);
    }
}

u32 sub_0804B694(void) {
    if (battle_sequence_dispatch() == 4)
        return 1;
    return 0;
}

void map_script_run_command(void) {
    gUnk_030057E0.unkC92 = read_map_script_byte();
    gUnk_030057E0.unkC89 = 0;
    gUnk_030057E0.unkC93 = 0;
    gMapScriptCommands[gUnk_030057E0.unkC92]();
}

u32 sub_0804B6EC(void) {
    return 0;
}

void nullsub_0804B6F0(void) {}

void sub_0804B6F4(void) {
    sub_0804B70C();
}

void sub_0804B700(void) {
    sub_0804B70C();
}

void sub_0804B70C(void) {
    read_map_script_bytes(3);
    gUnk_030057E0.unkC89 = 1;
}

// Not called directly (hidden in the tail of sub_0804B70C).
void sub_0804B72C(void) {
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804B740(void) {
    gUnk_030057E0.unkC94[0] = read_map_script_byte();
    gUnk_030057E0.unkC89 = 1;
}

// Not called directly (hidden in the tail of sub_0804B740).
void sub_0804B768(void) {
    gUnk_030057E0.unkC89 = 1;
}

// Map script command 6: ends the running script (clears the script id and read offset, frees the
// script sprite slots) and gives control back to the player.
void map_script_cmd_end(void) {
    gUnk_030057E0.unkC88 = 0;
    gUnk_030057E0.unkC89 = 0;
    gUnk_030057E0.unkC93 = 0;
    gUnk_030057E0.unkC8A = 0;
    gUnk_030057E0.unkC8E = 0;
    gUnk_030057E0.unkC5F = 0;
    gUnk_030057E0.unkC60 = 0;
    gUnk_03006D38.unk6 = 0;
    gUnk_03005310.unk38 = 0;
    sub_080496C8(gUnk_030057E0.unkCA4, 16);
    sub_080496C8((u8 *)&gUnk_03006D20, 16);
    gUnk_03002C30[47].unk25 = 1;
    set_battle_state_cancel_flag();
}

// guess: fade to black over n frames (n = script byte, 1..16)
void sub_0804B80C(void) {
    s32 n;
    gUnk_030057E0.unkC94[0] = read_map_script_byte();
    n = gUnk_030057E0.unkC94[0];
    if (n < 2)
        n = 1;
    if (n > 15)
        n = 16;
    setup_palette_fade_to_color_with_obj(0, 0.0f, 32.0f, n);
    gUnk_030057E0.unkC89 = 1;
}

// guess: fade back in from black over n frames
void sub_0804B860(void) {
    s32 n;
    gUnk_030057E0.unkC94[0] = read_map_script_byte();
    n = gUnk_030057E0.unkC94[0];
    if (n < 2)
        n = 1;
    if (n > 15)
        n = 16;
    setup_palette_fade_to_color(0, 32.0f, 0.0f, n);
    gUnk_030057E0.unkC89 = 1;
}

// guess: fade to white over n frames
void sub_0804B8B4(void) {
    s32 n;
    gUnk_030057E0.unkC94[0] = read_map_script_byte();
    n = gUnk_030057E0.unkC94[0];
    if (n < 2)
        n = 1;
    if (n > 15)
        n = 16;
    setup_palette_fade_to_color_with_obj(0x7FFF, 0.0f, 32.0f, n);
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804B90C(void) {
    s32 n;
    gUnk_030057E0.unkC94[0] = read_map_script_byte();
    n = gUnk_030057E0.unkC94[0];
    if (n < 2)
        n = 1;
    if (n > 15)
        n = 16;
    setup_palette_fade_to_color(0x7FFF, 32.0f, 0.0f, n);
    gUnk_030057E0.unkC89 = 1;
}

// guess: warp command (sets unkC5B first)
void sub_0804B964(void) {
    gUnk_030057E0.unkC5B = 1;
    map_script_read_warp();
}

// guess: warp command (clears unkC5B first)
void sub_0804B980(void) {
    gUnk_030057E0.unkC5B = 0;
    map_script_read_warp();
}

// Reads a warp target from the script: area, unk7FC, unk7FD, player tile x/y. The player keeps
// facing the same way; field_warp_to_area then loads the area.
void map_script_read_warp(void) {
    gUnk_030057E0.unk7FE = read_map_script_byte();
    gUnk_030057E0.unk7FC = read_map_script_byte();
    gUnk_030057E0.unk7FD = read_map_script_byte();
    gUnk_030057E0.unkC56 = read_map_script_byte();
    gUnk_030057E0.unkC57 = read_map_script_byte();
    gUnk_030057E0.unkC67 = gUnk_03002C30[47].unk20;
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804BA10(void) {
    gUnk_030057E0.unkC94[0] = read_map_script_byte();
    gUnk_03002C30[47].unk21 = gUnk_030057E0.unkC94[0];
    sub_080493D4(47, gUnk_03002C30[47].unk21);
    gUnk_03002C30[47].unk20 = gUnk_03002C30[47].unk21;
    field_set_player_facing(gUnk_030057E0.unkC94[0]);
}

void sub_0804BA50(void) {
    gUnk_030057E0.unkC94[0] = gUnk_03002C30[47].unk4;
    gUnk_03002C30[47].unk26 = 0;
    gUnk_03002C30[47].unk28 = 0;
    sub_08047BA8(0x70);
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804BAA0(void) {
    gUnk_030057E0.unkC94[0] = read_map_script_byte();
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804BAC8(void) {
    read_map_script_bytes(4);
    *(u8 *)&gHeldKeys = 0; // drops the held buttons (A, B, D-pad...)
    memcpy_u8(gUnk_030057E0.unkC10, gUnk_030057E0.unkC20, 8);
    sub_080496C8(gUnk_030057E0.unkC10, 8);
    gUnk_03002C30[47].unk28 = 0;
    gUnk_03002C30[47].unk26 = 0;
    gUnk_03002C30[47].unk27 = 0;
    gUnk_030057E0.unkC5F = 1;
    setup_battle_sprite_terrain(47, gUnk_030057E0.unkC94[gUnk_03002C30[47].unk26], gUnk_083D28B0[gUnk_030057E0.unkC5C]);
    field_set_player_facing(gUnk_03002C30[47].unk20);
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804BB54(void) {
    gUnk_030057E0.unkC94[0] = read_map_script_byte();
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804BB7C(void) {
    read_map_script_bytes(2);
    sub_0805311C((gUnk_030057E0.unkC94[0] << 8) | gUnk_030057E0.unkC94[1]);
}

void sub_0804BBA8(void) {
    read_map_script_bytes(2);
    sub_08053154((gUnk_030057E0.unkC94[0] << 8) | gUnk_030057E0.unkC94[1]);
}

void sub_0804BBD4(void) {
    if ((gUnk_030057E0.unk5DC[gUnk_030057E0.unkCB4].unk2 & 0xFFF) - gUnk_030057E0.unkC8E == 0)
        sub_0804D934(&gUnk_030057E0.unk5DC[gUnk_030057E0.unkCB4]);
}

void sub_0804BC20(void) {
    gUnk_030057E0.unk5DC[gUnk_030057E0.unkCB4].unk4_7 = 0;
    if (gUnk_030057E0.unk5DC[gUnk_030057E0.unkCB4].unk4_6) {
        clear_battle_sprite_entry(gUnk_030057E0.unk5DC[gUnk_030057E0.unkCB4].unk4_0 + 49);
        clear_battle_sprite_entry(gUnk_030057E0.unk5DC[gUnk_030057E0.unkCB4].unk4_0 + 91);
    }
}

void sub_0804BC88(void) {
    struct MapObject *obj;
    read_map_script_bytes(2);
    obj = battle_find_entity_by_id((gUnk_030057E0.unkC94[0] << 8) | gUnk_030057E0.unkC94[1]);
    if (obj != NULL)
        sub_0804D934(obj);
}

void sub_0804BCBC(void) {
    read_map_script_bytes(3);
    sub_080531EC((gUnk_030057E0.unkC94[0] << 8) | gUnk_030057E0.unkC94[1], gUnk_030057E0.unkC94[2] & 7);
}

void sub_0804BCF8(void) {
    read_map_script_bytes(2);
    sub_08053234((gUnk_030057E0.unkC94[0] << 8) | gUnk_030057E0.unkC94[1]);
}

void sub_0804BD24(void) {
    read_map_script_bytes(2);
    gUnk_030057E0.unkC8E = (gUnk_030057E0.unkC94[0] << 8) | gUnk_030057E0.unkC94[1];
    gUnk_030057E0.unkC8A = 0;
    if (battle_find_entity_by_id((gUnk_030057E0.unkC94[0] << 8) | gUnk_030057E0.unkC94[1]) != NULL)
        gUnk_030057E0.unkCB4 = sub_0804D8A8((u16)((gUnk_030057E0.unkC94[0] << 8) | gUnk_030057E0.unkC94[1]));
}

void sub_0804BD8C(void) {
    read_map_script_bytes(2);
    gUnk_03006D20.unkA = gUnk_030057E0.unk5DC[gUnk_030057E0.unkCB4].unk4_0 + 49;
    set_sprite_anim_and_store(gUnk_03006D20.unkA, gUnk_030057E0.unkC94[0] & 0xF,
                              &gUnk_030057E0.unk5DC[gUnk_030057E0.unkCB4]);
    gUnk_03006D20.unk0 = 0;
    gUnk_03006D20.unk2 = gUnk_030057E0.unkC94[1];
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804BE04(void) {
    if ((gUnk_030057E0.unk5DC[gUnk_030057E0.unkCB4].unk2 & 0xFFF) == gUnk_030057E0.unkC8E)
        set_sprite_anim_and_store(gUnk_030057E0.unk5DC[gUnk_030057E0.unkCB4].unk4_0 + 49,
                                  gUnk_083D24AC[gUnk_03002C30[47].unk21], &gUnk_030057E0.unk5DC[gUnk_030057E0.unkCB4]);
}

void sub_0804BE78(void) {
    gUnk_030057E0.unkC94[0] = read_map_script_byte();
    if ((gUnk_030057E0.unk5DC[gUnk_030057E0.unkCB4].unk2 & 0xFFF) == gUnk_030057E0.unkC8E)
        set_sprite_anim_and_store(gUnk_030057E0.unk5DC[gUnk_030057E0.unkCB4].unk4_0 + 49, gUnk_030057E0.unkC94[0],
                                  &gUnk_030057E0.unk5DC[gUnk_030057E0.unkCB4]);
}

void sub_0804BEE8(void) {
    if ((gUnk_030057E0.unk5DC[gUnk_030057E0.unkCB4].unk2 & 0xFFF) == gUnk_030057E0.unkC8E) {
        gUnk_03006D20.unkA = gUnk_030057E0.unk5DC[gUnk_030057E0.unkCB4].unk4_0 + 49;
        gUnk_03006D20.unk8 = gUnk_03002C30[gUnk_03006D20.unkA].unk10_8;
        gUnk_03002C30[gUnk_03006D20.unkA].unk28 = 0;
        sub_08047BA8(0x70);
        gUnk_030057E0.unkC89 = 1;
    }
}

void sub_0804BF68(void) {
    gUnk_030057E0.unkC94[0] = read_map_script_byte();
    if ((gUnk_030057E0.unk5DC[gUnk_030057E0.unkCB4].unk2 & 0xFFF) == gUnk_030057E0.unkC8E) {
        gUnk_03006D20.unkA = gUnk_030057E0.unk5DC[gUnk_030057E0.unkCB4].unk4_0 + 49;
        gUnk_03006D20.unk0 = gUnk_030057E0.unkC94[0];
        gUnk_03006D20.unk1 = 0;
        gUnk_03006D20.unk2 = 8;
        gUnk_03006D20.unk3 = 8;
        gUnk_030057E0.unkC89 = 1;
    }
}

void sub_0804BFE0(void) {
    u8 id;
    read_map_script_bytes(5);
    id = gUnk_030057E0.unkC94[0];
    sub_0804DB84(id, find_next_available_battle_sprite_slot());
    gUnk_03006D20.unkA = sub_0804DBA4(gUnk_030057E0.unkC94[0]) + 79;
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804C02C(void) {
    u8 id;
    read_map_script_bytes(5);
    id = gUnk_030057E0.unkC94[0];
    sub_0804DB84(id, find_next_available_battle_sprite_slot());
    gUnk_03006D20.unkA = sub_0804DBA4(gUnk_030057E0.unkC94[0]) + 79;
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804C078(void) {
    read_map_script_bytes(4);
    spawn_script_sprite(gUnk_030057E0.unkC94[0], gUnk_030057E0.unkC94[1], gUnk_030057E0.unkC94[2],
                        gUnk_030057E0.unkC94[3]);
}

void sub_0804C0B4(void) {
    read_map_script_bytes(2);
    set_battle_sprite_animation(gUnk_030057E0.unkC94[0] & 0xF, gUnk_030057E0.unkC94[1]);
}

void sub_0804C0E4(void) {
    read_map_script_bytes(2);
    gUnk_03006D20.unkA = sub_0804DBA4(gUnk_030057E0.unkC94[0]) + 79;
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804C11C(void) {
    read_map_script_bytes(2);
    gUnk_03006D20.unkA = sub_0804DBA4(gUnk_030057E0.unkC94[0]) + 79;
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804C154(void) {
    gUnk_030057E0.unkC94[0] = read_map_script_byte();
    sub_08050508(gUnk_030057E0.unkC94[0]);
}

void sub_0804C174(void) {
    read_map_script_bytes(2);
    gUnk_03006D20.unkA = sub_0804DBA4(gUnk_030057E0.unkC94[0]) + 79;
    gUnk_03006D20.unk0 = gUnk_030057E0.unkC94[1];
    gUnk_03006D20.unk1 = 0;
    gUnk_03006D20.unk2 = 8;
    gUnk_03006D20.unk3 = 8;
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804C1C4(void) {
    read_map_script_bytes(3);
    gUnk_03006D20.unkA = sub_0804DBA4(gUnk_030057E0.unkC94[0]) + 79;
    set_sprite_animation_state(gUnk_03006D20.unkA, gUnk_030057E0.unkC94[1] & 0xF);
    gUnk_03006D20.unk0 = 0;
    gUnk_03006D20.unk2 = gUnk_030057E0.unkC94[2];
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804C220(void) {
    gUnk_030057E0.unkC94[0] = read_map_script_byte();
    gUnk_03006D20.unkA = sub_0804DBA4(gUnk_030057E0.unkC94[0]) + 79;
    gUnk_03006D20.unk8 = gUnk_03002C30[gUnk_03006D20.unkA].unk10_8;
    gUnk_03002C30[gUnk_03006D20.unkA].unk28 = 0;
    sub_08047BA8(0x70);
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804C27C(void) {
    gUnk_030057E0.unkC94[0] = read_map_script_byte();
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804C2A4(void) {
    gUnk_030057E0.unkC94[0] = read_map_script_byte();
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804C2CC(void) {
    u8 id;
    read_map_script_bytes(5);
    id = gUnk_030057E0.unkC94[0];
    sub_0804DB84(id, find_next_available_battle_sprite_slot());
    gUnk_03006D20.unkA = sub_0804DBA4(gUnk_030057E0.unkC94[0]) + 79;
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804C318(void) {
    if ((gUnk_030057E0.unkC94[0] = read_map_script_byte()) == 1)
        gUnk_030057E0.unkC5D = (gUnk_030057E0.unkC5D & ~0x10) | 0x10;
    else
        gUnk_030057E0.unkC5D &= ~0x10;
}

void sub_0804C360(void) {
    read_map_script_bytes(2);
    gUnk_03006D20.unkA = sub_0804DBA4(gUnk_030057E0.unkC94[0]) + 79;
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804C398(void) {
    u16 r;
    s16 d;
    gUnk_030057E0.unkC8C = gUnk_030057E0.unkC8A;
    read_map_script_bytes(3);
    r = sub_08047D9C(gUnk_030057E0.unkC94[0], gUnk_030057E0.unkC94[1]);
    d = ((r & 0xFF00) >> 8) - (r & 0xFF);
    if (d == 0)
        gUnk_030057E0.unkC8A = gUnk_030057E0.unkC8C + gUnk_030057E0.unkC94[2];
}

// guess: jump by a byte offset, selected by the flag nibble sub_08053288(script id)
void sub_0804C3F8(void) {
    u16 start = gUnk_030057E0.unkC8A;
    gUnk_030057E0.unkC8A += sub_08053288(gUnk_030057E0.unkC8E);
    gUnk_030057E0.unkC8A = start + read_map_script_byte();
}

// guess: relative jump (read offset += 16-bit big-endian argument, from the opcode's offset)
void sub_0804C42C(void) {
    u16 start = gUnk_030057E0.unkC8A;
    read_map_script_bytes(2);
    gUnk_030057E0.unkC8A = start + ((gUnk_030057E0.unkC94[0] << 8) | gUnk_030057E0.unkC94[1]);
}

void sub_0804C468(void) {
    gUnk_030057E0.unkC8C = gUnk_030057E0.unkC8A;
    gUnk_030057E0.unkC94[0] = read_map_script_byte();
    gUnk_030057E0.unkCB5 = 0;
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804C4AC(void) {
    gUnk_030057E0.unkC8C = gUnk_030057E0.unkC8A;
    gUnk_030057E0.unkC94[0] = read_map_script_byte();
    gUnk_030057E0.unkCB5 = 1;
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804C4F0(void) {
    gUnk_030057E0.unkC2A = read_map_script_byte();
    gUnk_030057E0.unkC2F = read_map_script_byte();
    gUnk_030057E0.unkC2E = read_map_script_byte();
    if (sub_0804B6EC() == 0)
        gUnk_030057E0.unkC89 = 1;
}

void sub_0804C53C(void) {
    struct MapObject *obj;
    read_map_script_bytes(3);
    obj = battle_find_entity_by_id((gUnk_030057E0.unkC94[0] << 8) | gUnk_030057E0.unkC94[1]);
    if (obj != NULL && obj->unk4_6)
        set_sprite_anim_and_store(obj->unk4_0 + 49, gUnk_030057E0.unkC94[2], obj);
}

void sub_0804C598(void) {
    s32 i;
    gUnk_030057E0.unkC94[0] = read_map_script_byte();
    for (i = 0; i <= 3; i++) {
        if (sub_0804DBA4(i) != -1 && gUnk_030055A0[sub_0804DBA4(i) + 79].unk0 != 0)
            set_sprite_animation_state(sub_0804DBA4(i) + 79, gUnk_030057E0.unkC94[0]);
    }
}

void sub_0804C5FC(void) {
    read_map_script_bytes(2);
    if (gUnk_030057E0.unkC94[1] == 0)
        gUnk_030057E0.unkC94[1] = 1;
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804C62C(void) {
    read_map_script_bytes(2);
    if (gUnk_030057E0.unkC94[1] == 0)
        gUnk_030057E0.unkC94[1] = 1;
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804C65C(void) {
    read_map_script_bytes(3);
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804C67C(void) {
    read_map_script_bytes(3);
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804C69C(void) {
    read_map_script_bytes(2);
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804C6BC(void) {
    read_map_script_bytes(2);
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804C6DC(void) {
    gUnk_030057E0.unkC94[0] = read_map_script_byte();
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804C704(void) {
    gUnk_030057E0.unkC94[0] = read_map_script_byte();
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804C72C(void) {
    read_map_script_bytes(2);
    if (gUnk_030057E0.unkC94[0] == 0) {
        gUnk_030057E0.unkCBC += gUnk_030057E0.unkC94[1];
        if (gUnk_030057E0.unkCBD > 32)
            gUnk_030057E0.unkCBD = 32;
    } else {
        gUnk_030057E0.unkCBD += gUnk_030057E0.unkC94[1];
        if (gUnk_030057E0.unkCBD > 32)
            gUnk_030057E0.unkCBD = 32;
    }
}

void sub_0804C790(void) {
    read_map_script_bytes(2);
    if (gUnk_030057E0.unkC94[0] == 0) {
        gUnk_030057E0.unkCBC -= gUnk_030057E0.unkC94[1];
        if (gUnk_030057E0.unkCBC < 0)
            gUnk_030057E0.unkCBC = 0;
    } else {
        gUnk_030057E0.unkCBD -= gUnk_030057E0.unkC94[1];
        if (gUnk_030057E0.unkCBD < 0)
            gUnk_030057E0.unkCBD = 0;
    }
}

void sub_0804C7F4(void) {
    gUnk_030057E0.unkC94[0] = read_map_script_byte();
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804C81C(void) {
    s32 i;
    gUnk_030057E0.unkC94[0] = read_map_script_byte();
    for (i = 0; i <= 3; i++) {
        if (sub_0804DBA4(i) != -1 && gUnk_030055A0[sub_0804DBA4(i) + 79].unk0 != 0) {
            gUnk_03002C30[sub_0804DBA4(i) + 79].unk26 = gUnk_030057E0.unkC94[0];
            gUnk_03002C30[sub_0804DBA4(i) + 79].unk27 = 0;
            gUnk_03002C30[sub_0804DBA4(i) + 79].unk28 = 8;
            gUnk_03002C30[sub_0804DBA4(i) + 79].unk29 = 8;
        }
    }
    gUnk_030057E0.unkC89 = 1;
}

void nullsub_0804C8DC(void) {}

void sub_0804C8E0(void) {
    read_map_script_bytes(2);
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804C900(void) {
    sub_08047BA8(read_map_script_byte());
}

void sub_0804C914(void) {
    gUnk_030057E0.unkC94[0] = read_map_script_byte();
    dispatch_jump_table_29(1, gUnk_030057E0.unkC94[0]);
}

void sub_0804C938(void) {
    dispatch_jump_table_29(2, 0);
}

void sub_0804C948(void) {
    sub_08047BC0(0x78);
}

void sub_0804C954(void) {
    gUnk_030057E0.unkC94[0] = read_map_script_byte();
    dispatch_jump_table_29(3, gUnk_030057E0.unkC94[0]);
}

void sub_0804C978(void) {
    dispatch_jump_table_29(4, 0);
}

void sub_0804C988(void) {
    gUnk_030057E0.unkC8C = gUnk_030057E0.unkC8A;
    read_map_script_bytes(2);
    if (gUnk_030057E0.unkC94[0] != gUnk_03002C30[47].unk21)
        gUnk_030057E0.unkC8A = gUnk_030057E0.unkC8C + gUnk_030057E0.unkC94[1];
}

// guess: opcode 0x4B, skip ahead by arg2 unless the player has at least arg1 of item arg0
void sub_0804C9DC(void) {
    s32 n;
    gUnk_030057E0.unkC8C = gUnk_030057E0.unkC8A;
    read_map_script_bytes(3);
    n = sub_08047D8C(gUnk_030057E0.unkC94[0]);
    if (n == 0 || n < gUnk_030057E0.unkC94[1])
        gUnk_030057E0.unkC8A = gUnk_030057E0.unkC8C + gUnk_030057E0.unkC94[2];
}

void sub_0804CA38(void) {
    u32 r;
    gUnk_030057E0.unkC8C = gUnk_030057E0.unkC8A;
    read_map_script_bytes(3);
    r = lookup_position_table_value(gUnk_030057E0.unkC94[0], gUnk_030057E0.unkC94[1]);
    if (r != -1)
        gUnk_030057E0.unkC60 = r;
    else
        gUnk_030057E0.unkC8A = gUnk_030057E0.unkC8C + gUnk_030057E0.unkC94[2];
}

// guess: opcode 0x4D, skip ahead by arg1 unless medal arg0 is owned (find_medal_slot_by_id)
void sub_0804CA9C(void) {
    gUnk_030057E0.unkC8C = gUnk_030057E0.unkC8A;
    read_map_script_bytes(2);
    if (sub_08047DB0(gUnk_030057E0.unkC94[0]) == 0)
        gUnk_030057E0.unkC8A = gUnk_030057E0.unkC8C + gUnk_030057E0.unkC94[1];
}

// guess: opcode 0x4E, skip ahead by arg2 if money (gMoney) < 16-bit arg * 10
void sub_0804CAE8(void) {
    gUnk_030057E0.unkC8C = gUnk_030057E0.unkC8A;
    read_map_script_bytes(3);
    if ((s32)get_money() < ((gUnk_030057E0.unkC94[0] << 8) | gUnk_030057E0.unkC94[1]) * 10)
        gUnk_030057E0.unkC8A = gUnk_030057E0.unkC8C + gUnk_030057E0.unkC94[2];
}

void sub_0804CB48(void) {
    gUnk_030057E0.unkC8C = gUnk_030057E0.unkC8A;
    read_map_script_bytes(1);
    if (gUnk_03005310.unk39 == 2)
        gUnk_030057E0.unkC8A = gUnk_030057E0.unkC8C + gUnk_030057E0.unkC94[0];
}

void sub_0804CB90(void) {
    struct Unk_030057E0 *s = &gUnk_030057E0;
    s->unkC8C = s->unkC8A;
    read_map_script_bytes(3);
    if (s->unkC94[0] == 0) {
        if (s->unkCBC >= s->unkC94[1])
            return;
    } else if (s->unkCBD >= s->unkC94[1])
        return;
    gUnk_030057E0.unkC8A = gUnk_030057E0.unkC8C + gUnk_030057E0.unkC94[2];
}

void sub_0804CC10(void) {
    gUnk_030057E0.unkC8C = gUnk_030057E0.unkC8A;
    read_map_script_bytes(2);
    if (gUnk_030057E0.unkC94[0] - 70 != gUnk_030057E0.unkC60)
        gUnk_030057E0.unkC8A = gUnk_030057E0.unkC8C + gUnk_030057E0.unkC94[1];
}

void sub_0804CC60(void) {
    gUnk_030057E0.unkC8C = gUnk_030057E0.unkC8A;
    read_map_script_bytes(2);
    if (field_random(0xFF) & 0xF)
        gUnk_030057E0.unkC8A = gUnk_030057E0.unkC8C + gUnk_030057E0.unkC94[2];
}

void sub_0804CCA8(void) {
    read_map_script_bytes(2);
    if (gUnk_030057E0.unkC94[0] != 0)
        gUnk_030057E0.unkC94[0]--;
    gUnk_030057E0.unkC38[gUnk_030057E0.unkC94[0]] = gUnk_030057E0.unkC94[1];
    decompress_battle_tile_graphics();
    switch (gUnk_03006F40.unk1) {
    case 1:
    case 3:
    case 5:
    case 6:
        dma_load_obj_palettes_08048664();
        break;
    default:
        dma_load_battle_palettes();
        break;
    }
}

// Not called directly (hidden in the tail of sub_0804CCA8).
void nullsub_0804CD14(void) {}

// Not called directly (hidden in the tail of sub_0804CCA8).
void nullsub_0804CD18(void) {}

// Not called directly (hidden in the tail of sub_0804CCA8).
void sub_0804CD1C(void) {
    gUnk_030057E0.unkC89 = 1;
}

// Not called directly (hidden in the tail of sub_0804CCA8).
void nullsub_0804CD30(void) {}

// Not called directly (hidden in the tail of sub_0804CCA8).
void nullsub_0804CD34(void) {}

void sub_0804CD38(void) {
    read_map_script_bytes(1);
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804CD58(void) {
    gUnk_030057E0.unkC94[0] = read_map_script_byte();
    gUnk_03002C30[48].unk21 = gUnk_030057E0.unkC94[0];
    gUnk_03002C30[48].unk20 = gUnk_030057E0.unkC94[0];
    sub_080493D4(48, sub_080502B4(48, gUnk_030057E0.unkC94[0] + gUnk_03002C30[48].unk2B * 4));
    set_battle_state_byte_c83(gUnk_030057E0.unkC94[0]);
}

void sub_0804CDB8(void) {
    gUnk_030057E0.unkC8C = gUnk_030057E0.unkC8A;
    read_map_script_bytes(1);
    if (sub_08047F50() <= 2)
        gUnk_030057E0.unkC8A = gUnk_030057E0.unkC8C + gUnk_030057E0.unkC94[1];
}

// guess: opcode 0x5C, skip ahead by arg1 unless an assembled Medabot (0x030017A0) is all model arg0
void sub_0804CDF8(void) {
    gUnk_030057E0.unkC8C = gUnk_030057E0.unkC8A;
    read_map_script_bytes(2);
    if (sub_08047F70(gUnk_030057E0.unkC94[0]) == 0)
        gUnk_030057E0.unkC8A = gUnk_030057E0.unkC8C + gUnk_030057E0.unkC94[1];
}

// Opcode 0x5D. Bit 7 set: arg 1 sets / else clears unkC5D bit 5; else unkC33 (Medawatch
// menu flag) = arg & 0xF. Runtime: sets 0x03006413 to 1 when Dad gives Ikki the Medawatch.
void map_script_cmd_set_medawatch_flag(void) {
    read_map_script_bytes(1);
    if (gUnk_030057E0.unkC94[0] & 0x80) {
        if ((gUnk_030057E0.unkC94[0] & 0xF) == 1)
            gUnk_030057E0.unkC5D = (gUnk_030057E0.unkC5D & ~0x20) | 0x20;
        else
            gUnk_030057E0.unkC5D &= ~0x20;
    } else {
        gUnk_030057E0.unkC33 = gUnk_030057E0.unkC94[0] & 0xF;
    }
}

void sub_0804CEAC(void) {
    if ((gUnk_030057E0.unkC94[0] = read_map_script_byte()) == 1)
        gUnk_030057E0.unkC5D = (gUnk_030057E0.unkC5D & ~0x01) | 0x01;
    else
        gUnk_030057E0.unkC5D &= ~0x01;
}

void sub_0804CEF4(void) {
    gUnk_030057E0.unkC2C = read_map_script_byte();
}

void sub_0804CF10(void) {
    u16 id;
    struct MapObject *obj;
    read_map_script_bytes(3);
    switch (gUnk_030057E0.unkC94[0]) {
    case 0:
        if (sub_0804DBA4(gUnk_030057E0.unkC94[2]) != -1)
            sub_0804D9AC(sub_0804DBA4(gUnk_030057E0.unkC94[2]) + 79);
        break;
    case 1:
        id = (gUnk_030057E0.unkC94[1] << 8) | gUnk_030057E0.unkC94[2];
        if (id != 0) {
            obj = battle_find_entity_by_id(id);
            if (obj != NULL)
                sub_0804D9AC(obj->unk4_0 + 49);
        } else {
            sub_0804D9AC(gUnk_030057E0.unk5DC[gUnk_030057E0.unkCB4].unk4_0 + 49);
        }
        break;
    }
}

void sub_0804CFC0(void) {
    sub_0804DB34();
}

void sub_0804CFCC(void) {
    sub_08044B58();
}

void sub_0804CFD8(void) {
    read_map_script_bytes(3);
    init_sprite_affine_matrices_and_state(gUnk_030057E0.unkC94[0],
                                          (gUnk_030057E0.unkC94[1] & 0x7F) * 16 + gUnk_030057E0.unkC48,
                                          (gUnk_030057E0.unkC94[2] & 0x7F) * 16 + gUnk_030057E0.unkC4A, 0);
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804D038(void) {
    init_battle_sprites();
}

void nullsub_0804D044(void) {}

void sub_0804D048(void) {
    read_map_script_bytes(2);
    gUnk_03006D20.unkA = sub_0804DBA4(gUnk_030057E0.unkC94[0]) + 79;
    gUnk_03002C30[gUnk_03006D20.unkA].unk26 = 0;
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804D094(void) {
    read_map_script_bytes(2);
    gUnk_030057E0.unkC89 = 1;
}

void sub_0804D0B4(void) {
    struct MapObject *obj;
    read_map_script_bytes(2);
    obj = &gUnk_030057E0.unk5DC[gUnk_030057E0.unkCB4];
    if ((obj->unk2 & 0xFFF) == ((gUnk_030057E0.unkC94[0] << 8) | gUnk_030057E0.unkC94[1]))
        set_tile_data(obj->x, obj->y, 0);
}
