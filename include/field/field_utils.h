#ifndef GUARD_FIELD_FIELD_UTILS_H
#define GUARD_FIELD_FIELD_UTILS_H

// Digit helpers, fixed-point math and 64x64 BG tilemap copies

s32 truncate_to_digit_count(s32 n, u8 k);
s16 divide_by_65536(s16 a);
s32 count_decimal_digits(s32 n); // number of decimal digits of n (1 for 0); was safe_divide_one
s16 fixed_point_multiply(s16 a, s16 b);
u32 sub_08048914(u32 a);
void sub_08048B6C(void);
void copy_tilemap_with_offset_08048CA4(const void *src, void *dst, s32 a, s32 b, s32 c, s32 d, s32 e);
void copy_tiles_to_bg_tilemap(const void *src, void *dst, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g);
void sub_08048B94(void);

#endif // GUARD_FIELD_FIELD_UTILS_H
