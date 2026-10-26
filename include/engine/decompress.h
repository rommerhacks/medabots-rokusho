#ifndef GUARD_ENGINE_DECOMPRESS_H
#define GUARD_ENGINE_DECOMPRESS_H

// LZ77 decompression (BIOS and the game's custom variants).

u32 lz_decompress_dispatch(const u8 *src, void *dst);

#endif // GUARD_ENGINE_DECOMPRESS_H
