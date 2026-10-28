// Fixed-point 4x4 matrices (identity, multiply, scale, translate, rotate_xyz) and the rotating 3-D rings of
// sprites (ring_points_place_on_*, update_scene_animation_frame) drawn by the scenes in code_08067160.c.
#include "global.h"

static void compute_difference_div3(s32 *start, s32 *end, s32 *third_pt, s32 *two_thirds_pt) {
    s32 x, y, end_coord;

    end_coord = end[0];
    x = start[0];
    third_pt[0] = (end_coord - x) / 3 + x;
    end_coord = end[1];
    y = start[1];
    third_pt[1] = (end_coord - y) / 3 + y;
    two_thirds_pt[0] = (end[0] - x) * 2 / 3 + x;
    two_thirds_pt[1] = (end[1] - y) * 2 / 3 + y;
}

void ring_points_place_on_hexagon(u32 radius) {
    s32 pts[7][2];
    s32 out[18][2];
    s32 m1[2];
    s32 m2[2];
    s32 *vertex;
    s32 *next;
    s32 *dst;
    s32 i;
    s32 angle;

    next = pts[0];
    for (i = 0; i <= 5; i++) {
        angle = (i << 8) / 6;
        *next++ = gSineTable[angle] * radius;
        *next++ = gSineTable[angle + 0x40] * radius;
    }
    *next++ = pts[0][0];
    *next = pts[0][1];

    vertex = pts[0];
    next = pts[1];
    dst = out[0];
    for (i = 0; i <= 5; i++) {
        compute_difference_div3(vertex, next, m1, m2);
        *dst++ = *vertex++;
        *dst++ = *vertex++;
        *dst++ = m1[0];
        *dst++ = m1[1];
        *dst++ = m2[0];
        *dst++ = m2[1];
        next += 2;
    }

    dst = out[0];
    for (i = 0; i <= 17; i++) {
        gMenuWork->ring_points[i].x = *dst++ >> 8;
        gMenuWork->ring_points[i].y = *dst++ >> 8;
        gMenuWork->ring_points[i].z = 0x1E;
    }
}

static u8 u8_difference_divide(u8 target, u8 current, u8 n) {
    s32 step = (target - current) / n;

    if (step != 0)
        return current + step;
    if (target == current)
        return current;
    if (target <= current)
        return current - 1;
    return current + 1;
}

static void copy_block_64bytes(s32 dst[4][4], s32 src[4][4]) {
    s32 i, j;

    for (i = 0; i <= 3; i++)
        for (j = 0; j <= 3; j++)
            dst[i][j] = src[i][j];
}

void matrix_set_identity(void) {
    s32 mat[4][4];

    custom_memset(mat, 0, sizeof(mat));
    mat[0][0] = 0x100;
    mat[1][1] = 0x100;
    mat[2][2] = 0x100;
    mat[3][3] = 0x100;
    copy_block_64bytes(gMenuWork->matrix, mat);
}

static void matrix_multiply_4x4_fixed(s32 dst[4][4], s32 lhs[4][4], s32 rhs[4][4]) {
    s32 i, j, k;

    for (i = 0; i <= 3; i++)
        for (j = 0; j <= 3; j++) {
            dst[i][j] = 0;
            for (k = 0; k <= 3; k++)
                dst[i][j] += (lhs[i][k] * rhs[k][j]) >> 8;
        }
}

static void matrix_scale(s32 scale) {
    s32 scale_mat[4][4];
    s32 result[4][4];

    custom_memset(scale_mat, 0, sizeof(scale_mat));
    scale_mat[0][0] = scale;
    scale_mat[1][1] = scale;
    scale_mat[2][2] = scale;
    scale_mat[3][3] = 0x100;
    matrix_multiply_4x4_fixed(result, scale_mat, gMenuWork->matrix);
    copy_block_64bytes(gMenuWork->matrix, result);
}

static void matrix_translate(s32 x, s32 y, s32 z) {
    s32 trans_mat[4][4];
    s32 result[4][4];

    custom_memset(trans_mat, 0, sizeof(trans_mat));
    trans_mat[0][0] = 0x100;
    trans_mat[1][1] = 0x100;
    trans_mat[2][2] = 0x100;
    trans_mat[3][0] = x;
    trans_mat[3][1] = y;
    trans_mat[3][2] = z;
    trans_mat[3][3] = 0x100;
    matrix_multiply_4x4_fixed(result, gMenuWork->matrix, trans_mat);
    copy_block_64bytes(gMenuWork->matrix, result);
}

void matrix_rotate_xyz(s32 angle_x, s32 angle_y, s32 angle_z) {
    s32 rx[4][4] = {
        {0x100, 0, 0, 0},
        {0, gSineTable[angle_x + 0x40], gSineTable[angle_x], 0},
        {0, -gSineTable[angle_x], gSineTable[angle_x + 0x40], 0},
        {0, 0, 0, 0x100},
    };
    s32 ry[4][4] = {
        {gSineTable[angle_y + 0x40], 0, -gSineTable[angle_y], 0},
        {0, 0x100, 0, 0},
        {gSineTable[angle_y], 0, gSineTable[angle_y + 0x40], 0},
        {0, 0, 0, 0x100},
    };
    s32 rz[4][4] = {
        {gSineTable[angle_z + 0x40], gSineTable[angle_z], 0, 0},
        {-gSineTable[angle_z], gSineTable[angle_z + 0x40], 0, 0},
        {0, 0, 0x100, 0},
        {0, 0, 0, 0x100},
    };
    s32 rotated_x[4][4];
    s32 rotated_xy[4][4];

    matrix_multiply_4x4_fixed(rotated_x, rx, gMenuWork->matrix);
    matrix_multiply_4x4_fixed(rotated_xy, ry, rotated_x);
    matrix_multiply_4x4_fixed(gMenuWork->matrix, rz, rotated_xy);
}

void ring_points_place_on_circle(u16 phase) {
    s32 i;

    for (i = 0; i <= 17; i++) {
        s32 radius = gMenuWork->ring_points[i].radius;
        u32 idx = ((i << 8) / 18 + phase) & 0xFF;

        gMenuWork->ring_points[i].sinOffset = (radius * gSineTable[idx]) >> 8;
        gMenuWork->ring_points[i].cosOffset = (gMenuWork->ring_points[i].radius * gSineTable[idx + 0x40]) >> 8;
    }
}

static void ring_points_place_on_circle_b(u16 phase) {
    s32 i;

    for (i = 0; i <= 17; i++) {
        s32 radius = gMenuWork->ring_points[i].radius;
        u32 idx = ((i << 8) / 18 + phase) & 0xFF;

        gMenuWork->ring_points[i].sinOffset = (radius * gSineTable[idx]) >> 8;
        gMenuWork->ring_points[i].cosOffset = (gMenuWork->ring_points[i].radius * gSineTable[idx + 0x40]) >> 8;
    }
}

static inline s32 half(u8 value) {
    return value >> 1;
}
static inline s32 quarter20(u8 value) {
    return (value >> 2) - 0x14;
}

static inline void rings_set_radius(u8 *counter_ptr, u8 *midpoint_ptr) {
    u32 counter_word = *counter_ptr, midpoint_word = *midpoint_ptr;
    u8 counter = counter_word, midpoint = midpoint_word;
    if (counter < midpoint)
        ring_points_place_on_hexagon((counter >> 2) + 0x14);
    else
        ring_points_place_on_hexagon(half(midpoint) - quarter20(counter));
}

// Four rings of 18 sprites rotated in 3-D (matrix_rotate_xyz) around drifting centres
void update_scene_animation_frame(void) {
    s32 i, n;

    rng_next_byte();
    if (gMenuWork->counter == 0) {
        gMenuWork->counter = rng_next_byte();
        if (gMenuWork->counter == 0)
            gMenuWork->counter++;
        gMenuWork->aux = gMenuWork->counter >> 1;
    } else {
        gMenuWork->counter--;
        rings_set_radius(&gMenuWork->counter, &gMenuWork->aux);
    }

    gMenuWork->ring_rot_x[0] =
        (gMenuWork->ring_angles[0] - (s16)gMenuWork->ring_rot_x[0]) / 16 + gMenuWork->ring_rot_x[0];
    gMenuWork->ring_rot_y[0] =
        (gMenuWork->ring_angles[1] - (s16)gMenuWork->ring_rot_y[0]) / 16 + gMenuWork->ring_rot_y[0];
    gMenuWork->ring_rot_z[0] =
        (gMenuWork->ring_angles[2] - (s16)gMenuWork->ring_rot_z[0]) / 16 + gMenuWork->ring_rot_z[0];
    gMenuWork->ring_rot_x[1] =
        ((s16)gMenuWork->ring_rot_x[0] - (s16)gMenuWork->ring_rot_x[1]) / 16 + gMenuWork->ring_rot_x[1];
    gMenuWork->ring_rot_y[1] =
        ((s16)gMenuWork->ring_rot_y[0] - (s16)gMenuWork->ring_rot_y[1]) / 16 + gMenuWork->ring_rot_y[1];
    gMenuWork->ring_rot_z[1] =
        ((s16)gMenuWork->ring_rot_z[0] - (s16)gMenuWork->ring_rot_z[1]) / 16 + gMenuWork->ring_rot_z[1];
    gMenuWork->ring_rot_x[2] =
        ((s16)gMenuWork->ring_rot_x[1] - (s16)gMenuWork->ring_rot_x[2]) / 16 + gMenuWork->ring_rot_x[2];
    gMenuWork->ring_rot_y[2] =
        ((s16)gMenuWork->ring_rot_y[1] - (s16)gMenuWork->ring_rot_y[2]) / 16 + gMenuWork->ring_rot_y[2];
    gMenuWork->ring_rot_z[2] =
        ((s16)gMenuWork->ring_rot_z[1] - (s16)gMenuWork->ring_rot_z[2]) / 16 + gMenuWork->ring_rot_z[2];
    gMenuWork->ring_rot_x[3] =
        ((s16)gMenuWork->ring_rot_x[2] - (s16)gMenuWork->ring_rot_x[3]) / 16 + gMenuWork->ring_rot_x[3];
    gMenuWork->ring_rot_y[3] =
        ((s16)gMenuWork->ring_rot_y[2] - (s16)gMenuWork->ring_rot_y[3]) / 16 + gMenuWork->ring_rot_y[3];
    gMenuWork->ring_rot_z[3] =
        ((s16)gMenuWork->ring_rot_z[2] - (s16)gMenuWork->ring_rot_z[3]) / 16 + gMenuWork->ring_rot_z[3];

    gMenuWork->ring_center_x[4] = u8_difference_divide(gMenuWork->ring_center_x[3], gMenuWork->ring_center_x[4], 0x7F);
    gMenuWork->ring_center_x[3] = u8_difference_divide(gMenuWork->ring_center_x[2], gMenuWork->ring_center_x[3], 0x7F);
    gMenuWork->ring_center_x[2] = u8_difference_divide(gMenuWork->ring_center_x[1], gMenuWork->ring_center_x[2], 0x7F);
    gMenuWork->ring_center_x[1] = u8_difference_divide(gMenuWork->ring_center_x[0], gMenuWork->ring_center_x[1], 0x7F);
    gMenuWork->ring_center_y[4] = u8_difference_divide(gMenuWork->ring_center_y[3], gMenuWork->ring_center_y[4], 0x7F);
    gMenuWork->ring_center_y[3] = u8_difference_divide(gMenuWork->ring_center_y[2], gMenuWork->ring_center_y[3], 0x7F);
    gMenuWork->ring_center_y[2] = u8_difference_divide(gMenuWork->ring_center_y[1], gMenuWork->ring_center_y[2], 0x7F);
    gMenuWork->ring_center_y[1] = u8_difference_divide(gMenuWork->ring_center_y[0], gMenuWork->ring_center_y[1], 0x7F);

    matrix_set_identity();
    gMenuWork->ticks++;
    if ((gMenuWork->ticks & 0xFF) == 0) {
        s32 angle = rng_next_byte() & 0xFF;
        gMenuWork->ring_center_x[0] = gSineTable[angle] * 5 >> 5;
        gMenuWork->ring_center_y[0] = gSineTable[angle + 0x40] * 5 >> 5;
        gMenuWork->ring_center_x[0] += 0x78;
        gMenuWork->ring_center_y[0] += 0x50;
    }
    if ((gMenuWork->ticks & 0x3F) == 0)
        gMenuWork->ring_random_mode = rng_next_byte() & 3;

    switch (gMenuWork->ring_random_mode & 3) {
    case 0:
        gMenuWork->ring_speeds[0] += 2;
        gMenuWork->ring_speeds[1] += 1;
        break;
    case 1:
        gMenuWork->ring_speeds[0] -= 2;
        gMenuWork->ring_speeds[1] += 2;
        gMenuWork->ring_speeds[2] += 3;
        break;
    case 2:
        gMenuWork->ring_speeds[0] += 1;
        gMenuWork->ring_speeds[2] += 2;
        break;
    case 3:
        gMenuWork->ring_speeds[0] += 5;
        gMenuWork->ring_speeds[1] += 1;
        gMenuWork->ring_speeds[2] -= 2;
        break;
    }

    if (gMenuWork->ring_speeds[0] < -16)
        gMenuWork->ring_speeds[0] = -16;
    if (gMenuWork->ring_speeds[1] < -16)
        gMenuWork->ring_speeds[1] = -16;
    if (gMenuWork->ring_speeds[2] < -16)
        gMenuWork->ring_speeds[2] = -16;
    if (gMenuWork->ring_speeds[0] > 16)
        gMenuWork->ring_speeds[0] = 16;
    if (gMenuWork->ring_speeds[1] > 16)
        gMenuWork->ring_speeds[1] = 16;
    if (gMenuWork->ring_speeds[2] > 16)
        gMenuWork->ring_speeds[2] = 16;

    {
        struct MenuWork *work = gMenuWork;
        work->ring_angles[0] += work->ring_speeds[0];
        work->ring_angles[1] += work->ring_speeds[1];
        work->ring_angles[2] += work->ring_speeds[2];
    }

    for (i = 0; i <= 0x47; i = n) {
        s32 j = i % 18;
        struct MenuWork *w;
        s32 x, y;
        s32 px, py, pz;
        struct SpriteEntry *spr;
        s32 k;

        if (j == 0) {
            matrix_set_identity();
            matrix_rotate_xyz(((s16)gMenuWork->ring_rot_x[i / 18] >> 4) & 0xFF,
                              ((s16)gMenuWork->ring_rot_y[i / 18] >> 4) & 0xFF,
                              ((s16)gMenuWork->ring_rot_z[i / 18] >> 4) & 0xFF);
        }
        w = gMenuWork;
        px = w->ring_points[j].x;
        py = w->ring_points[j].y;
        pz = w->ring_points[j].z;
        x = px * w->matrix[0][0] + py * w->matrix[1][0] + pz * w->matrix[2][0] + w->matrix[3][0];
        y = px * w->matrix[0][2] + py * w->matrix[1][2] + pz * w->matrix[2][2] + w->matrix[3][2];
        x >>= 8;
        y >>= 8;
        {
            struct SpriteEntry *sprites = gSpriteEntries;
            n = i + 1;
            spr = &sprites[n];
        }
        k = i / 18 + 1;
        spr->x = w->ring_center_x[k] + x;
        spr->y = w->ring_center_y[k] + y;
    }
}
