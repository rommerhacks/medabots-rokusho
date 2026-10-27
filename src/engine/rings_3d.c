// Fixed-point 4x4 matrices (identity, multiply, scale, translate, rotate_xyz) and the rotating 3-D rings of
// sprites (ring_points_place_on_*, update_scene_animation_frame) drawn by the scenes in code_08067160.c.
#include "global.h"

static void compute_difference_div3(s32 *a, s32 *b, s32 *c, s32 *d) {
    s32 x, y, t;

    t = b[0];
    x = a[0];
    c[0] = (t - x) / 3 + x;
    t = b[1];
    y = a[1];
    c[1] = (t - y) / 3 + y;
    d[0] = (b[0] - x) * 2 / 3 + x;
    d[1] = (b[1] - y) * 2 / 3 + y;
}

void ring_points_place_on_hexagon(u32 r) {
    s32 pts[7][2];
    s32 out[18][2];
    s32 m1[2];
    s32 m2[2];
    s32 *p;
    s32 *q;
    s32 *o;
    s32 i;
    s32 a;

    q = pts[0];
    for (i = 0; i <= 5; i++) {
        a = (i << 8) / 6;
        *q++ = gSineTable[a] * r;
        *q++ = gSineTable[a + 0x40] * r;
    }
    *q++ = pts[0][0];
    *q = pts[0][1];

    p = pts[0];
    q = pts[1];
    o = out[0];
    for (i = 0; i <= 5; i++) {
        compute_difference_div3(p, q, m1, m2);
        *o++ = *p++;
        *o++ = *p++;
        *o++ = m1[0];
        *o++ = m1[1];
        *o++ = m2[0];
        *o++ = m2[1];
        q += 2;
    }

    o = out[0];
    for (i = 0; i <= 17; i++) {
        gUnk_03006F74->unkD0[i].unk2 = *o++ >> 8;
        gUnk_03006F74->unkD0[i].unk4 = *o++ >> 8;
        gUnk_03006F74->unkD0[i].unk6 = 0x1E;
    }
}

static u8 u8_difference_divide(u8 a, u8 b, u8 n) {
    s32 d = (a - b) / n;

    if (d != 0)
        return b + d;
    if (a == b)
        return b;
    if (a <= b)
        return b - 1;
    return b + 1;
}

static void copy_block_64bytes(s32 dst[4][4], s32 src[4][4]) {
    s32 i, j;

    for (i = 0; i <= 3; i++)
        for (j = 0; j <= 3; j++)
            dst[i][j] = src[i][j];
}

void matrix_set_identity(void) {
    s32 m[4][4];

    custom_memset(m, 0, sizeof(m));
    m[0][0] = 0x100;
    m[1][1] = 0x100;
    m[2][2] = 0x100;
    m[3][3] = 0x100;
    copy_block_64bytes(gUnk_03006F74->unk1F0, m);
}

static void matrix_multiply_4x4_fixed(s32 dst[4][4], s32 a[4][4], s32 b[4][4]) {
    s32 i, j, k;

    for (i = 0; i <= 3; i++)
        for (j = 0; j <= 3; j++) {
            dst[i][j] = 0;
            for (k = 0; k <= 3; k++)
                dst[i][j] += (a[i][k] * b[k][j]) >> 8;
        }
}

static void matrix_scale(s32 s) {
    s32 m[4][4];
    s32 t[4][4];

    custom_memset(m, 0, sizeof(m));
    m[0][0] = s;
    m[1][1] = s;
    m[2][2] = s;
    m[3][3] = 0x100;
    matrix_multiply_4x4_fixed(t, m, gUnk_03006F74->unk1F0);
    copy_block_64bytes(gUnk_03006F74->unk1F0, t);
}

static void matrix_translate(s32 x, s32 y, s32 z) {
    s32 m[4][4];
    s32 t[4][4];

    custom_memset(m, 0, sizeof(m));
    m[0][0] = 0x100;
    m[1][1] = 0x100;
    m[2][2] = 0x100;
    m[3][0] = x;
    m[3][1] = y;
    m[3][2] = z;
    m[3][3] = 0x100;
    matrix_multiply_4x4_fixed(t, gUnk_03006F74->unk1F0, m);
    copy_block_64bytes(gUnk_03006F74->unk1F0, t);
}

void matrix_rotate_xyz(s32 a, s32 b, s32 c) {
    s32 rx[4][4] = {
        {0x100, 0, 0, 0},
        {0, gSineTable[a + 0x40], gSineTable[a], 0},
        {0, -gSineTable[a], gSineTable[a + 0x40], 0},
        {0, 0, 0, 0x100},
    };
    s32 ry[4][4] = {
        {gSineTable[b + 0x40], 0, -gSineTable[b], 0},
        {0, 0x100, 0, 0},
        {gSineTable[b], 0, gSineTable[b + 0x40], 0},
        {0, 0, 0, 0x100},
    };
    s32 rz[4][4] = {
        {gSineTable[c + 0x40], gSineTable[c], 0, 0},
        {-gSineTable[c], gSineTable[c + 0x40], 0, 0},
        {0, 0, 0x100, 0},
        {0, 0, 0, 0x100},
    };
    s32 t1[4][4];
    s32 t2[4][4];

    matrix_multiply_4x4_fixed(t1, rx, gUnk_03006F74->unk1F0);
    matrix_multiply_4x4_fixed(t2, ry, t1);
    matrix_multiply_4x4_fixed(gUnk_03006F74->unk1F0, rz, t2);
}

void ring_points_place_on_circle(u16 phase) {
    s32 i;

    for (i = 0; i <= 17; i++) {
        s32 r = gUnk_03006F74->unkD0[i].unk0;
        u32 idx = ((i << 8) / 18 + phase) & 0xFF;

        gUnk_03006F74->unkD0[i].unk8 = (r * gSineTable[idx]) >> 8;
        gUnk_03006F74->unkD0[i].unkA = (gUnk_03006F74->unkD0[i].unk0 * gSineTable[idx + 0x40]) >> 8;
    }
}

static void ring_points_place_on_circle_b(u16 phase) {
    s32 i;

    for (i = 0; i <= 17; i++) {
        s32 r = gUnk_03006F74->unkD0[i].unk0;
        u32 idx = ((i << 8) / 18 + phase) & 0xFF;

        gUnk_03006F74->unkD0[i].unk8 = (r * gSineTable[idx]) >> 8;
        gUnk_03006F74->unkD0[i].unkA = (gUnk_03006F74->unkD0[i].unk0 * gSineTable[idx + 0x40]) >> 8;
    }
}

static inline s32 half(u8 d) {
    return d >> 1;
}
static inline s32 quarter20(u8 c) {
    return (c >> 2) - 0x14;
}

static inline void rings_set_radius(u8 *p, u8 *q) {
    u32 a = *p, b = *q;
    u8 c = a, d = b;
    if (c < d)
        ring_points_place_on_hexagon((c >> 2) + 0x14);
    else
        ring_points_place_on_hexagon(half(d) - quarter20(c));
}

// Four rings of 18 sprites rotated in 3-D (matrix_rotate_xyz) around drifting centres
void update_scene_animation_frame(void) {
    s32 i, n;

    rng_next_byte();
    if (gUnk_03006F74->unk48 == 0) {
        gUnk_03006F74->unk48 = rng_next_byte();
        if (gUnk_03006F74->unk48 == 0)
            gUnk_03006F74->unk48++;
        gUnk_03006F74->unk49 = gUnk_03006F74->unk48 >> 1;
    } else {
        gUnk_03006F74->unk48--;
        rings_set_radius(&gUnk_03006F74->unk48, &gUnk_03006F74->unk49);
    }

    gUnk_03006F74->unk8A[0] = (gUnk_03006F74->unk80[0] - (s16)gUnk_03006F74->unk8A[0]) / 16 + gUnk_03006F74->unk8A[0];
    gUnk_03006F74->unk92[0] = (gUnk_03006F74->unk80[1] - (s16)gUnk_03006F74->unk92[0]) / 16 + gUnk_03006F74->unk92[0];
    gUnk_03006F74->unk9A[0] = (gUnk_03006F74->unk80[2] - (s16)gUnk_03006F74->unk9A[0]) / 16 + gUnk_03006F74->unk9A[0];
    gUnk_03006F74->unk8A[1] =
        ((s16)gUnk_03006F74->unk8A[0] - (s16)gUnk_03006F74->unk8A[1]) / 16 + gUnk_03006F74->unk8A[1];
    gUnk_03006F74->unk92[1] =
        ((s16)gUnk_03006F74->unk92[0] - (s16)gUnk_03006F74->unk92[1]) / 16 + gUnk_03006F74->unk92[1];
    gUnk_03006F74->unk9A[1] =
        ((s16)gUnk_03006F74->unk9A[0] - (s16)gUnk_03006F74->unk9A[1]) / 16 + gUnk_03006F74->unk9A[1];
    gUnk_03006F74->unk8A[2] =
        ((s16)gUnk_03006F74->unk8A[1] - (s16)gUnk_03006F74->unk8A[2]) / 16 + gUnk_03006F74->unk8A[2];
    gUnk_03006F74->unk92[2] =
        ((s16)gUnk_03006F74->unk92[1] - (s16)gUnk_03006F74->unk92[2]) / 16 + gUnk_03006F74->unk92[2];
    gUnk_03006F74->unk9A[2] =
        ((s16)gUnk_03006F74->unk9A[1] - (s16)gUnk_03006F74->unk9A[2]) / 16 + gUnk_03006F74->unk9A[2];
    gUnk_03006F74->unk8A[3] =
        ((s16)gUnk_03006F74->unk8A[2] - (s16)gUnk_03006F74->unk8A[3]) / 16 + gUnk_03006F74->unk8A[3];
    gUnk_03006F74->unk92[3] =
        ((s16)gUnk_03006F74->unk92[2] - (s16)gUnk_03006F74->unk92[3]) / 16 + gUnk_03006F74->unk92[3];
    gUnk_03006F74->unk9A[3] =
        ((s16)gUnk_03006F74->unk9A[2] - (s16)gUnk_03006F74->unk9A[3]) / 16 + gUnk_03006F74->unk9A[3];

    gUnk_03006F74->unkA2[4] = u8_difference_divide(gUnk_03006F74->unkA2[3], gUnk_03006F74->unkA2[4], 0x7F);
    gUnk_03006F74->unkA2[3] = u8_difference_divide(gUnk_03006F74->unkA2[2], gUnk_03006F74->unkA2[3], 0x7F);
    gUnk_03006F74->unkA2[2] = u8_difference_divide(gUnk_03006F74->unkA2[1], gUnk_03006F74->unkA2[2], 0x7F);
    gUnk_03006F74->unkA2[1] = u8_difference_divide(gUnk_03006F74->unkA2[0], gUnk_03006F74->unkA2[1], 0x7F);
    gUnk_03006F74->unkA7[4] = u8_difference_divide(gUnk_03006F74->unkA7[3], gUnk_03006F74->unkA7[4], 0x7F);
    gUnk_03006F74->unkA7[3] = u8_difference_divide(gUnk_03006F74->unkA7[2], gUnk_03006F74->unkA7[3], 0x7F);
    gUnk_03006F74->unkA7[2] = u8_difference_divide(gUnk_03006F74->unkA7[1], gUnk_03006F74->unkA7[2], 0x7F);
    gUnk_03006F74->unkA7[1] = u8_difference_divide(gUnk_03006F74->unkA7[0], gUnk_03006F74->unkA7[1], 0x7F);

    matrix_set_identity();
    gUnk_03006F74->unk3C++;
    if ((gUnk_03006F74->unk3C & 0xFF) == 0) {
        s32 r = rng_next_byte() & 0xFF;
        gUnk_03006F74->unkA2[0] = gSineTable[r] * 5 >> 5;
        gUnk_03006F74->unkA7[0] = gSineTable[r + 0x40] * 5 >> 5;
        gUnk_03006F74->unkA2[0] += 0x78;
        gUnk_03006F74->unkA7[0] += 0x50;
    }
    if ((gUnk_03006F74->unk3C & 0x3F) == 0)
        gUnk_03006F74->unk7E = rng_next_byte() & 3;

    switch (gUnk_03006F74->unk7E & 3) {
    case 0:
        gUnk_03006F74->unk86[0] += 2;
        gUnk_03006F74->unk86[1] += 1;
        break;
    case 1:
        gUnk_03006F74->unk86[0] -= 2;
        gUnk_03006F74->unk86[1] += 2;
        gUnk_03006F74->unk86[2] += 3;
        break;
    case 2:
        gUnk_03006F74->unk86[0] += 1;
        gUnk_03006F74->unk86[2] += 2;
        break;
    case 3:
        gUnk_03006F74->unk86[0] += 5;
        gUnk_03006F74->unk86[1] += 1;
        gUnk_03006F74->unk86[2] -= 2;
        break;
    }

    if (gUnk_03006F74->unk86[0] < -16)
        gUnk_03006F74->unk86[0] = -16;
    if (gUnk_03006F74->unk86[1] < -16)
        gUnk_03006F74->unk86[1] = -16;
    if (gUnk_03006F74->unk86[2] < -16)
        gUnk_03006F74->unk86[2] = -16;
    if (gUnk_03006F74->unk86[0] > 16)
        gUnk_03006F74->unk86[0] = 16;
    if (gUnk_03006F74->unk86[1] > 16)
        gUnk_03006F74->unk86[1] = 16;
    if (gUnk_03006F74->unk86[2] > 16)
        gUnk_03006F74->unk86[2] = 16;

    {
        struct Unk_03006F74 *v = gUnk_03006F74;
        v->unk80[0] += v->unk86[0];
        v->unk80[1] += v->unk86[1];
        v->unk80[2] += v->unk86[2];
    }

    for (i = 0; i <= 0x47; i = n) {
        s32 j = i % 18;
        struct Unk_03006F74 *w;
        s32 x, y;
        s32 px, py, pz;
        struct SpriteEntry *spr;
        s32 k;

        if (j == 0) {
            matrix_set_identity();
            matrix_rotate_xyz(((s16)gUnk_03006F74->unk8A[i / 18] >> 4) & 0xFF,
                              ((s16)gUnk_03006F74->unk92[i / 18] >> 4) & 0xFF,
                              ((s16)gUnk_03006F74->unk9A[i / 18] >> 4) & 0xFF);
        }
        w = gUnk_03006F74;
        px = w->unkD0[j].unk2;
        py = w->unkD0[j].unk4;
        pz = w->unkD0[j].unk6;
        x = px * w->unk1F0[0][0] + py * w->unk1F0[1][0] + pz * w->unk1F0[2][0] + w->unk1F0[3][0];
        y = px * w->unk1F0[0][2] + py * w->unk1F0[1][2] + pz * w->unk1F0[2][2] + w->unk1F0[3][2];
        x >>= 8;
        y >>= 8;
        {
            struct SpriteEntry *b = gSpriteEntries;
            n = i + 1;
            spr = &b[n];
        }
        k = i / 18 + 1;
        spr->unk2 = w->unkA2[k] + x;
        spr->unk4 = w->unkA7[k] + y;
    }
}
