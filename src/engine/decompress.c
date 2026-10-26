// LZ decompression for the game's compressed graphics ("Le" header): lz_decompress_dispatch picks the VRAM-safe
// 16-bit-write variant or the byte-wise one by destination address. Used by all graphics loaders.

#include "global.h"

static u32 lz_decompress_custom_08000A0C(const u8 *src, u8 *dst, u32 size);
static u32 lz_decompress_custom_08000B14(const u8 *src, void *dst);

u32 lz_decompress_dispatch(const u8 *src, void *dst) {
    if (src[0] != 'L' || src[1] != 'e')
        return 0;
    if ((u32)dst - 0x04000001 <= 0x03FFFFFE)
        return lz_decompress_custom_08000B14(src, dst);
    else
        return lz_decompress_custom_08000A0C(src, dst, src[2] | (src[3] << 8) | (src[4] << 16));
}

static u32 lz_decompress_custom_08000A0C(const u8 *src, u8 *dst, u32 size) {
    u32 left = size;
    u8 *d = dst;
    const u8 *s = src + 6;
    u8 flags;
    u32 n;
    u32 v;
    u8 *p;

    while (left != 0) {
        flags = *s++;
        for (n = 0; n < 4 && left != 0; n++, flags >>= 2) {
            switch (flags & 3) {
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

static u32 lz_decompress_custom_08000B14(const u8 *src, void *dst) {
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

    while (left != 0) {
        flags = *s++;
        for (n = 0; n < 4 && left != 0; n++, flags >>= 2) {
            switch (flags & 3) {
            case 0:
                v = s[0] + (s[1] << 8);
                s += 2;
                p = d - ((v & 0xFFF) + 5);
                v = (v >> 12) + 3;
                left -= v;
                while (v--) {
                    u16 *dh = (u16 *)((u32)d & ~1);
                    u16 sv = *(u16 *)((u32)p & ~1);
                    u16 dv = *dh;
                    if ((u32)p & 1) {
                        if ((u32)d & 1)
                            *dh = (dv & 0xFF) | (sv & 0xFF00);
                        else
                            *dh = (dv & 0xFF00) | (sv >> 8);
                    } else {
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
                while (v--) {
                    u16 *dh = (u16 *)((u32)d & ~1);
                    u16 sv = *(u16 *)((u32)p & ~1);
                    u16 dv = *dh;
                    if ((u32)p & 1) {
                        if ((u32)d & 1)
                            *dh = (dv & 0xFF) | (sv & 0xFF00);
                        else
                            *dh = (dv & 0xFF00) | (sv >> 8);
                    } else {
                        if ((u32)d & 1)
                            *dh = (dv & 0xFF) | (sv << 8);
                        else
                            *dh = (dv & 0xFF00) | (sv & 0xFF);
                    }
                    d++;
                    p++;
                }
                break;
            case 3: {
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
            case 2: {
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
