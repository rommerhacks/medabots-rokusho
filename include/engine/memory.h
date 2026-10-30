#ifndef GUARD_ENGINE_MEMORY_H
#define GUARD_ENGINE_MEMORY_H

// Byte-wise memset / memcpy / swap

void mem_fill8(u8 *dst, u32 size, u8 val);
void copy_bytes(const void *src, void *dst, u32 n);
void memswap(void *lhs, void *rhs, u32 n);

#endif // GUARD_ENGINE_MEMORY_H
