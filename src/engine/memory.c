// Byte-wise memory helpers: fill (mem_fill8), copy (copy_bytes) and swap (memswap).
// Used all over the game instead of the BIOS CpuSet for small or unaligned buffers.

#include "global.h"

void mem_fill8(u8 *dst, u32 size, u8 val) {
    u32 i;
    for (i = 0; i < size; i++)
        *dst++ = val;
}

void copy_bytes(const void *src, void *dst, u32 n) {
    u32 i;
    for (i = 0; i < n; i++) {
        *(u8 *)dst = *(const u8 *)src;
        src = (const u8 *)src + 1;
        dst = (u8 *)dst + 1;
    }
}

void memswap(void *lhs, void *rhs, u32 n) {
    u32 i;
    u8 byte;
    for (i = 0; i < n; i++) {
        byte = *(u8 *)lhs;
        *(u8 *)lhs = *(u8 *)rhs;
        lhs = (u8 *)lhs + 1;
        *(u8 *)rhs = byte;
        rhs = (u8 *)rhs + 1;
    }
}
