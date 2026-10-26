#ifndef GUARD_ENGINE_MEMORY_H
#define GUARD_ENGINE_MEMORY_H

// Byte-wise memset / memcpy / swap

void sub_0803F624(u8 *dst, u32 size, u8 val);
void memcpy_bytes_0803F63C(const void *src, void *dst, u32 n);
void memswap(void *a, void *b, u32 n);

#endif // GUARD_ENGINE_MEMORY_H
