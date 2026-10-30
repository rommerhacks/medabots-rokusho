// LZ decompression for the game's compressed graphics ("Le" header): lz_decompress_dispatch picks the VRAM-safe
// 16-bit-write variant or the byte-wise one by destination address. Used by all graphics loaders.

#include "global.h"

// Byte-wise LZ decoder for WRAM destinations.
static u32 lz_decompress_bytes(const u8 *src, u8 *dst, u32 size);
// LZ decoder for VRAM / IO destinations: every byte goes through a 16-bit read-modify-write.
static u32 lz_decompress_halfwords(const u8 *src, void *dst);

u32 lz_decompress_dispatch(const u8 *src, void *dst) {
    if (src[0] != 'L' || src[1] != 'e')
        return 0;
    if ((u32)dst - 0x04000001 <= 0x03FFFFFE)
        return lz_decompress_halfwords(src, dst);
    else
        return lz_decompress_bytes(src, dst, src[2] | (src[3] << 8) | (src[4] << 16));
}

static u32 lz_decompress_bytes(const u8 *src, u8 *dst, u32 size) {
    u32 left = size;
    u8 *out = dst;
    const u8 *in = src + 6;
    u8 flags;
    u32 n;
    u32 token;
    u8 *back_ref;

    while (left != 0) {
        flags = *in++;
        for (n = 0; n < 4 && left != 0; n++, flags >>= 2) {
            switch (flags & 3) {
            case 0:
                token = in[0] + (in[1] << 8);
                in += 2;
                back_ref = out - ((token & 0xFFF) + 5);
                token = (token >> 12) + 3;
                left -= token;
                while (token--)
                    *out++ = *back_ref++;
                break;
            case 1:
                token = *in++;
                back_ref = out - ((token & 3) + 1);
                token = (token >> 2) + 2;
                left -= token;
                while (token--)
                    *out++ = *back_ref++;
                break;
            case 3:
                *out++ = *in++;
                *out++ = *in++;
                *out++ = *in++;
                left -= 3;
                break;
            case 2:
                *out++ = *in++;
                left--;
                break;
            }
        }
    }
    return size;
}

static u32 lz_decompress_halfwords(const u8 *src, void *dst) {
    u32 size;
    u32 left;
    u8 *out;
    const u8 *in;
    u8 flags;
    u32 n;
    u32 token;
    u8 *back_ref;

    if (src[0] != 'L' || src[1] != 'e')
        return 0;
    size = src[2] | (src[3] << 8) | (src[4] << 16);
    left = size;
    out = dst;
    in = src + 6;

    while (left != 0) {
        flags = *in++;
        for (n = 0; n < 4 && left != 0; n++, flags >>= 2) {
            switch (flags & 3) {
            case 0:
                token = in[0] + (in[1] << 8);
                in += 2;
                back_ref = out - ((token & 0xFFF) + 5);
                token = (token >> 12) + 3;
                left -= token;
                while (token--) {
                    u16 *dh = (u16 *)((u32)out & ~1);
                    u16 sv = *(u16 *)((u32)back_ref & ~1);
                    u16 dv = *dh;
                    if ((u32)back_ref & 1) {
                        if ((u32)out & 1)
                            *dh = (dv & 0xFF) | (sv & 0xFF00);
                        else
                            *dh = (dv & 0xFF00) | (sv >> 8);
                    } else {
                        if ((u32)out & 1)
                            *dh = (dv & 0xFF) | (sv << 8);
                        else
                            *dh = (dv & 0xFF00) | (sv & 0xFF);
                    }
                    out++;
                    back_ref++;
                }
                break;
            case 1:
                token = *in++;
                back_ref = out - ((token & 3) + 1);
                token = (token >> 2) + 2;
                left -= token;
                while (token--) {
                    u16 *dh = (u16 *)((u32)out & ~1);
                    u16 sv = *(u16 *)((u32)back_ref & ~1);
                    u16 dv = *dh;
                    if ((u32)back_ref & 1) {
                        if ((u32)out & 1)
                            *dh = (dv & 0xFF) | (sv & 0xFF00);
                        else
                            *dh = (dv & 0xFF00) | (sv >> 8);
                    } else {
                        if ((u32)out & 1)
                            *dh = (dv & 0xFF) | (sv << 8);
                        else
                            *dh = (dv & 0xFF00) | (sv & 0xFF);
                    }
                    out++;
                    back_ref++;
                }
                break;
            case 3: {
                u16 *dh = (u16 *)((u32)out & ~1);
                u16 dv = *dh;
                if ((u32)out & 1)
                    *dh = (dv & 0xFF) | (*in << 8);
                else
                    *dh = (dv & 0xFF00) | *in;
                out++;
                in++;
            }
                {
                    u16 *dh = (u16 *)((u32)out & ~1);
                    u16 dv = *dh;
                    if ((u32)out & 1)
                        *dh = (dv & 0xFF) | (*in << 8);
                    else
                        *dh = (dv & 0xFF00) | *in;
                    out++;
                    in++;
                }
                {
                    u16 *dh = (u16 *)((u32)out & ~1);
                    u16 dv = *dh;
                    if ((u32)out & 1)
                        *dh = (dv & 0xFF) | (*in << 8);
                    else
                        *dh = (dv & 0xFF00) | *in;
                    out++;
                    in++;
                }
                left -= 3;
                break;
            case 2: {
                u16 *dh = (u16 *)((u32)out & ~1);
                u16 dv = *dh;
                if ((u32)out & 1)
                    *dh = (dv & 0xFF) | (*in << 8);
                else
                    *dh = (dv & 0xFF00) | *in;
                out++;
                in++;
            }
                left--;
                break;
            }
        }
    }
    return size;
}
