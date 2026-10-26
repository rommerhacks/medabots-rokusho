// Byte-wise memory helpers: fill (sub_0803F624), copy (memcpy_bytes_0803F63C) and swap (memswap).
// Used all over the game instead of the BIOS CpuSet for small or unaligned buffers.

#include "global.h"

void sub_0803F624(u8 *dst, u32 size, u8 val) {
    u32 i;
    for (i = 0; i < size; i++)
        *dst++ = val;
}

void memcpy_bytes_0803F63C(const void *src, void *dst, u32 n) {
    u32 i;
    for (i = 0; i < n; i++) {
        *(u8 *)dst = *(const u8 *)src;
        src = (const u8 *)src + 1;
        dst = (u8 *)dst + 1;
    }
}

void memswap(void *a, void *b, u32 n) {
    u32 i;
    u8 t;
    for (i = 0; i < n; i++) {
        t = *(u8 *)a;
        *(u8 *)a = *(u8 *)b;
        a = (u8 *)a + 1;
        *(u8 *)b = t;
        b = (u8 *)b + 1;
    }
}
