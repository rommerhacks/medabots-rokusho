// Field helpers: 2x2 metatile / tilemap rectangle copies, the OAM affine matrix builder, sprite animation
// frames, field_random, the BG blend effect (setup_blend_effect / blend_effect_update), palette fades to a
// colour and a u8 quicksort. Called mostly from field/field_update and field/map_script; talks to the
// engine (OAM, palettes, IO registers).

#include "global.h"

static void apply_blend_coefficients(void);

// One tile of 2x2 metatile `id` (copy_tiles_to_bg_tilemap); yoff / xoff are passed but unused.
void build_bg_tile_entry(u16 *dst, u16 id, u16 base, u16 y, u16 x, u16 yoff, u16 xoff) {
    u16 t = x + y * 2;
    *dst = (t + (id + 1) * 4) | (base + (id << 12));
}

// Not called directly (hidden in the tail of build_bg_tile_entry).
static void sub_080490F4(u16 *src, u16 *dst, s32 h, s32 w, s32 maxh, s32 pitch, s32 add, s32 pal) {
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
static void sub_0804914C(u8 slot, const void *src) {
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
static u32 sub_0804950C(void) {
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
static void nullsub_080496A0(void) {}

// Not called directly (hidden in the tail of advance_sprite_animation_frame).
static void sub_080496A4(u8 slot, const void *src) {
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

static s32 count_byte_differences(const u8 *a, const u8 *b, s32 n) {
    s32 count = 0;
    s32 i;

    for (i = 0; i < n; i++) {
        if (*a++ != *b++)
            count++;
    }
    return count;
}

// Not called directly (hidden in the tail of count_byte_differences at 0x0804971C).
static s32 sum_bytes_0804971C(const u8 *p, s32 n) {
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
        *(u8 *)dst = *(const u8 *)src;
        src = (const u8 *)src + 1;
        dst = (u8 *)dst + 1;
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

static void apply_blend_coefficients(void) {
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
static void quicksort_u8_array(u8 *arr, s16 left, s16 right) {
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
static void sub_08049F84(u16 *arr, s16 left, s16 right) {
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
static void sub_0804A0A4(u16 *arr, s16 left, s16 right) {
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
