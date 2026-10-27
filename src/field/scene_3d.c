// Field effects ("MAP_EFFECT" on the debug screen): small 3-D sprite scenes played inside the field,
// e.g. the map warp (0x12) and teleport (0xE) effects of field/field_update. field_effect_start picks an
// effect (flags & 0x3F; 0x40 = at the player) and resets the state in gUnk_03005350; field_effect_run runs
// its script one frame at a time (4 = finished) over the float camera / projection helpers and the
// interpolated tracks at the end of the file. Started by field/field_update, field/map_script and
// field/field_walk.
#include "global.h"

static void compute_plane_from_points(float *x, float *y, float *z, float *a, float *b, float *c, float *d);
static void get_state_position_xyz(float *x, float *y, float *z);
static void field_effect_init_viewport(void);
static void field_effect_init_viewport_centered(void);
static void affine_set_destination_and_compute_transform(float x0, float x1, float y0, float y1);
static void affine_set_source_and_compute_transform(float x0, float x1, float y0, float y1);
static void field_effect_project_object(float *x, float *y, float *z);
static void field_effect_project_origin(float x, float y, float z);
static void field_effect_view_to_screen_origin(float a, float b);
static void field_effect_project_sprite(float x, float y, float z);
static void compute_3d_transform_vectors(float x, float y, float z, float *outX, float *outY, float *outZ);
static void get_state_float_as_int(float a, float b, s32 *x, s32 *y);
static void field_effect_place_sprite(float a, float b);
static void field_effect_update_sprite_depth(void);

static float float_default_to_one_if_zero(float x) {
    if (x == 0.0f)
        x = 1.0f;
    return x;
}

static float float_sign(float x) {
    if (x < 0.0f)
        return -1.0f;
    return 1.0f;
}

static float float_abs_if_negative(float x) {
    if (x < 0.0f)
        x *= -1.0f;
    return x;
}

static double compute_sqrt_scaled(double x) {
    return (u16)Sqrt((s32)x << 3) >> 3;
}

void field_effect_start(u32 flags, u32 x, u32 y, u32 d) {
    s32 i;

    affine_params_reset();
    for (i = 0; i < 32; i++)
        calculate_oam_affine_matrix(i);
    memzero_bytes((u8 *)&gUnk_03005350, 0x240);
    gUnk_03005350.unk1D4 = flags;
    if (flags & 0x40) {
        x = gFieldWork.player_x;
        y = gFieldWork.player_y;
    }
    gUnk_03005350.unk1D8 = x;
    gUnk_03005350.unk1DC = y;
    gUnk_03005350.unk1E0 = d;
}

void field_effect_reset_view(void) {
    field_effect_init_viewport();
    gUnk_03005350.unkA4[0] = gUnk_03005350.unk1D8 - gBg1Scroll.x - 0x70;
    gUnk_03005350.unkA4[1] = gUnk_03005350.unk1DC - gBg1Scroll.y - 0x50;
    memzero_bytes((u8 *)gUnk_03006D30, 0x3000);
}

static void compute_distance_to_state_position(float *xs, float *ys, float *zs) {
    float a, b, c, d;
    float px, py, pz;
    float x, y, z;
    float dx, dy, dz;
    float dist;

    compute_plane_from_points(xs, ys, zs, &a, &b, &c, &d);
    x = *xs;
    y = *ys;
    z = *zs;
    get_state_position_xyz(&px, &py, &pz);
    dx = x - px;
    dy = y - py;
    dz = z - pz;
    dist = dx * dx + dy * dy + dz * dz;
    dist = compute_sqrt_scaled(dist);
    if (dist == 0.0f)
        dist = 1.0f;
    Div((s32)dx, (s32)dist);
    Div((s32)dy, (s32)dist);
    Div((s32)dz, (s32)dist);
    if (dist < 10000.0f)
        field_effect_project_object(xs, ys, zs);
}

// x, y, z: the three points' coordinates (x[i], y[i], z[i] = point i).
// Outputs the plane through them: normal (a, b, c) scaled to integers, and d.
static void compute_plane_from_points(float *x, float *y, float *z, float *a, float *b, float *c, float *d) {
    float nx, ny, nz, len;

    nx = y[0] * (z[1] - z[2]) + y[1] * (z[2] - z[0]) + y[2] * (z[0] - z[1]);
    ny = z[0] * (x[1] - x[2]) + z[1] * (x[2] - x[0]) + z[2] * (x[0] - x[1]);
    nz = x[0] * (y[1] - y[2]) + x[1] * (y[2] - y[0]) + x[2] * (y[0] - y[1]);
    len = nx * nx + ny * ny + nz * nz;
    len = compute_sqrt_scaled(len);
    if (len == 0.0f)
        len = 1.0f;
    nx = Div(nx, len);
    ny = Div(ny, len);
    nz = Div(nz, len);
    *a = nx;
    *b = ny;
    *c = nz;
    *d = -(nx * x[0] + ny * y[0] + nz * z[0]);
}

static void get_state_position_xyz(float *x, float *y, float *z) {
    *x = gUnk_03005350.unk40;
    *y = gUnk_03005350.unk44;
    *z = gUnk_03005350.unk48;
}

static void field_effect_init_viewport(void) {
    field_effect_init_viewport_centered();
}

static void field_effect_init_viewport_centered(void) {
    s32 zero;

    gUnk_03005350.unk0 = 240;
    gUnk_03005350.unk4 = 160;
    zero = 0;
    gUnk_03005350.unk8 = 120;
    gUnk_03005350.unkC = 80;
    affine_set_destination_and_compute_transform(-120.5f, 120.5f, -80.5f, 80.5f);
    affine_set_source_and_compute_transform(-120.5f, 120.5f, -80.5f, 80.5f);
    gUnk_03005350.unkB4 = zero;
    gUnk_03005350.unkB8 = zero;
}

static void affine_set_destination_and_compute_transform(float x0, float x1, float y0, float y1) {
    gUnk_03005350.unk10 = x0;
    gUnk_03005350.unk14 = x1;
    gUnk_03005350.unk18 = y0;
    gUnk_03005350.unk1C = y1;
    gUnk_03005350.unk30 = (gUnk_03005350.unk24 - gUnk_03005350.unk20) / (x1 - x0);
    gUnk_03005350.unk34 = (gUnk_03005350.unk2C - gUnk_03005350.unk28) / (y1 - y0);
    gUnk_03005350.unk38 = (x1 * gUnk_03005350.unk20 - x0 * gUnk_03005350.unk24) / (x1 - x0);
    gUnk_03005350.unk3C = (y1 * gUnk_03005350.unk28 - y0 * gUnk_03005350.unk2C) / (y1 - y0);
}

static void affine_set_source_and_compute_transform(float x0, float x1, float y0, float y1) {
    gUnk_03005350.unk20 = x0;
    gUnk_03005350.unk24 = x1;
    gUnk_03005350.unk28 = y0;
    gUnk_03005350.unk2C = y1;
    gUnk_03005350.unk30 = (x1 - x0) / (gUnk_03005350.unk14 - gUnk_03005350.unk10);
    gUnk_03005350.unk34 = (y1 - y0) / (gUnk_03005350.unk1C - gUnk_03005350.unk18);
    gUnk_03005350.unk38 =
        (gUnk_03005350.unk14 * x0 - gUnk_03005350.unk10 * x1) / (gUnk_03005350.unk14 - gUnk_03005350.unk10);
    gUnk_03005350.unk3C =
        (gUnk_03005350.unk1C * y0 - gUnk_03005350.unk18 * y1) / (gUnk_03005350.unk1C - gUnk_03005350.unk18);
}

void set_state_float_field(float a, float b, float c, float d) {
    float x, y, z, len;

    gUnk_03005350.unk4C = c;
    gUnk_03005350.unkA0 = d;
    gUnk_03005350.unk50 = gUnk_083D6EA0[(s32)a & 0xFF];
    gUnk_03005350.unk54 = gUnk_083D72A0[(s32)a & 0xFF];
    gUnk_03005350.unk58 = gUnk_083D6EA0[(s32)b & 0xFF];
    gUnk_03005350.unk5C = gUnk_083D72A0[(s32)b & 0xFF];
    x = gUnk_03005350.unk58 * gUnk_03005350.unk50;
    y = gUnk_03005350.unk58 * gUnk_03005350.unk54;
    z = gUnk_03005350.unk5C;
    len = compute_sqrt_scaled(x * x + y * y + z * z);
    if (len == 0.0f)
        len = 1.0f;
    x = Div(x, len);
    y = Div(y, len);
    z = Div(z, len);
    gUnk_03005350.unk40 = c * x;
    gUnk_03005350.unk44 = c * y;
    gUnk_03005350.unk48 = c * z;
}

static void field_effect_project_object(float *x, float *y, float *z) {
    float a, b, c;
    s32 i;

    a = x[0];
    b = y[0];
    c = z[0];
    field_effect_project_origin(a, b, c);
    for (i = 1; i < gUnk_03005350.unk1D0; i++) {
        a = x[i];
        b = y[i];
        c = z[i];
        gUnk_03006D30[gUnk_03005350.unk1CC].unk20C = i;
        field_effect_project_sprite(a, b, c);
    }
    a = x[0];
    b = y[0];
    c = z[0];
    gUnk_03006D30[gUnk_03005350.unk1CC].unk20C = 0;
    field_effect_project_sprite(a, b, c);
}

static void field_effect_project_origin(float a, float b, float c) {
    float x, y, z;

    compute_3d_transform_vectors(a, b, c, &x, &y, &z);
    field_effect_view_to_screen_origin(x, y);
}

static void field_effect_view_to_screen_origin(float a, float b) {
    get_state_float_as_int(a, b, &gUnk_03005350.unkB4, &gUnk_03005350.unkB8);
}

static void field_effect_project_sprite(float x, float y, float z) {
    float sx, sy, depth;
    struct SpriteEntry *sprites;

    compute_3d_transform_vectors(x, y, z, &sx, &sy, &depth);
    field_effect_place_sprite(sx, sy);
    sprites = gSpriteEntries;
    sprites[gUnk_03006D30[gUnk_03005350.unk1CC].unk2DC[gUnk_03006D30[gUnk_03005350.unk1CC].unk20C]].unk14_8 = depth;
}

static void compute_3d_transform_vectors(float x, float y, float z, float *outX, float *outY, float *outZ) {
    float rx, ry, rz, d;

    rx = x * gUnk_03005350.unk50 + y * gUnk_03005350.unk54;
    ry = -x * gUnk_03005350.unk54 + y * gUnk_03005350.unk50;
    rz = z * gUnk_03005350.unk58 - rx * gUnk_03005350.unk5C;
    d = gUnk_03005350.unk4C - (rx * gUnk_03005350.unk58 + z * gUnk_03005350.unk5C);
    if (d == 0.0f)
        d = 1.0f;
    rx = gUnk_03005350.unkA0 / d;
    *outX = ry * rx;
    *outY = rz * rx;
    *outZ = d;
}

static void get_state_float_as_int(float a, float b, s32 *x, s32 *y) {
    *x = (s32)gUnk_03005350.unk30 * (s32)a + (s32)gUnk_03005350.unk38 + gUnk_03005350.unk8;
    *y = gUnk_03005350.unkC - ((s32)gUnk_03005350.unk34 * (s32)b + (s32)gUnk_03005350.unk3C);
}

#define CUR_ENTITY gUnk_03006D30[gUnk_03005350.unk1CC]

static void field_effect_place_sprite(float a, float b) {
    get_state_float_as_int(a, b, &gUnk_03005350.unkB4, &gUnk_03005350.unkB8);
    gSpriteEntries[CUR_ENTITY.unk2DC[CUR_ENTITY.unk20C]].unk2 =
        gUnk_03005350.unkB4 + CUR_ENTITY.unk2E0[CUR_ENTITY.unk20C];
    gSpriteEntries[CUR_ENTITY.unk2DC[CUR_ENTITY.unk20C]].unk4 =
        gUnk_03005350.unkB8 + CUR_ENTITY.unk2E8[CUR_ENTITY.unk20C];
    if (CUR_ENTITY.unk1EC && (u8)gUnk_03005350.unkB8 >= CUR_ENTITY.unk1F0 &&
        (u8)gUnk_03005350.unkB8 <= CUR_ENTITY.unk1F4) {
        CUR_ENTITY.unk0 = 2;
        CUR_ENTITY.unkAC = 0;
    }
    if (CUR_ENTITY.unk1E0 && (s32)(gUnk_03005350.unkB4 & 0x1FF) >= CUR_ENTITY.unk1E4 &&
        (s32)(gUnk_03005350.unkB4 & 0x1FF) <= CUR_ENTITY.unk1E8) {
        CUR_ENTITY.unk0 = 2;
        CUR_ENTITY.unk64 = 0;
        CUR_ENTITY.unk1C = 0;
    }
    if (CUR_ENTITY.unk1F8) {
        if (CUR_ENTITY.unkA0 <= CUR_ENTITY.unk1FC) {
            CUR_ENTITY.unk0 = 2;
            CUR_ENTITY.unkAC = 0;
        }
        if (CUR_ENTITY.unkA0 >= CUR_ENTITY.unk200) {
            CUR_ENTITY.unk0 = 2;
            CUR_ENTITY.unkAC = 0;
        }
    }
}

static void init_affine_transform_viewport(s32 x, s32 y) {
    gUnk_03005350.unk0 = 240;
    gUnk_03005350.unk4 = 160;
    gUnk_03005350.unk8 = x + 120;
    gUnk_03005350.unkC = y + 80;
    affine_set_destination_and_compute_transform(-120.5f, 120.5f, -80.5f, 80.5f);
    affine_set_source_and_compute_transform(-120.5f, 120.5f, -80.5f, 80.5f);
}

void field_effect_project_objects(void) {
    s32 i, j;
    const s32 *p;
    const s32 *q;

    gUnk_03005350.unk0 = 240;
    gUnk_03005350.unk4 = 160;
    affine_set_destination_and_compute_transform(-120.5f, 120.5f, -80.5f, 80.5f);
    affine_set_source_and_compute_transform(-120.5f, 120.5f, -80.5f, 80.5f);
    init_affine_transform_viewport(gUnk_03005350.unkA4[0], gUnk_03005350.unkA4[1]);
    for (i = 0; i < 16; i++) {
        if (gUnk_03006D30[i].unk0 == 0)
            continue;
        if (gUnk_03006D30[i].unk4 < gUnk_03006D30[i].unk8)
            continue;
        if (gUnk_03006D30[i].unk1C0 == 0)
            continue;
        if (gUnk_03006D30[i].unk1C4 < gUnk_03006D30[i].unk1C8)
            continue;
        p = gUnk_083D2DB0[gUnk_03005350.unkF8][i];
        q = p;
        gUnk_03005350.unk1D0 = *q++;
        for (j = 0; j < 4; j++) {
            gUnk_03005350.unkC0[j] = q[0];
            gUnk_03005350.unkD0[j] = q[4];
            gUnk_03005350.unkE0[j] = q[8];
            q++;
        }
        set_state_float_field(gUnk_03005350.unk90 + gUnk_03006D30[i].unkF8,
                              gUnk_03005350.unk94 + gUnk_03006D30[i].unk110, gUnk_03005350.unk9C, gUnk_03005350.unkA0);
        for (j = 0; j < 4; j++) {
            gUnk_03005350.unk60[j] = gUnk_03005350.unkC0[j] * gUnk_03006D30[i].unk164 + gUnk_03006D30[i].unk10;
            gUnk_03005350.unk70[j] = gUnk_03005350.unkD0[j] * gUnk_03006D30[i].unk17C + gUnk_03006D30[i].unk58;
            gUnk_03005350.unk80[j] = gUnk_03005350.unkE0[j] * gUnk_03006D30[i].unk194 + gUnk_03006D30[i].unkA0;
        }
        gUnk_03005350.unk98 = p[1];
        gUnk_03005350.unk1CC = i;
        compute_distance_to_state_position(gUnk_03005350.unk60, gUnk_03005350.unk70, gUnk_03005350.unk80);
    }
}

#define S (*(struct SeqState *)&gUnk_03005350)
#define E ((struct SeqEntity *)gUnk_03006D30)

// Field effect script interpreter. Runs the script picked by unk1D4 & 0x3F until an opcode
// returns control: 0 (script end), 1, 2 (wait a frame) or 4 (finished).
u32 field_effect_run(void) {
    s32 *script;
    s32 buf[16];
    u32 zero;
    s32 x, y, attr;
    s32 i;
    s32 done;
    s32 cnt;
    s32 tmp;
    struct AnimInterp *anim;
    struct SeqTrack *trk;
    struct SeqOsc *osc;
    struct SeqRamp *ramp;
    s32 j, k;
    s32 n;
    s32 flag;
    s32 part;
    s32 v, a, b;
    s32 d;
    const s32 *model;
    u16 color;
    s32 r, g, bl;

    S.unkF0 = 1;
    S.unkF8 = S.unk1D4 & 0x3F;
    script = gUnk_083D5D84[S.unkF8];
    while (1) {
        switch (S.unkF4 = script[S.unkFC]) {
        case 0: // guess: end of script (return 0); 4 = finish (reset, rebuild the field), 37 = nop
        case 4:
        case 37:
            break;
        case 1: // guess: init: camera distance/scale, yaw/pitch, reset entity scales
            S.unkFC++;
            S.unk9C = script[S.unkFC++];
            S.unkA0 = script[S.unkFC++];
            S.unk90 = script[S.unkFC++];
            S.unk94 = script[S.unkFC++];
            S.unk214 = 0x80;
            S.unk218 = 0;
            S.unk21C = 0x400;
            S.unk220 = 0x800;
            field_effect_reset_view();
            for (i = 0; i < 16; i++) {
                E[i].unk160.value = 1.0f;
                E[i].unk178.value = 1.0f;
                E[i].unk190.value = 1.0f;
            }
            break;
        case 2: // guess: run one frame: fire entity triggers, step all tracks, fade; advance when an entity finished
            done = 0;
            flag = 0;
            cnt = 0;
            for (i = 0; i < 16; i++) {
                if (E[i].unk0 != 0 && E[i].unk218 != 0) {
                    for (k = 0; k < 16; k++) {
                        if (E[i].unk29C[k] != 0) {
                            cnt++;
                            if (E[i].unk4 >= E[i].unk21C[k]) {
                                S.unk184 = E[i].unk25C[k];
                                E[S.unk184].unk10.unk0 = E[i].unk10.unk0;
                                E[S.unk184].unk58.unk0 = E[i].unk58.unk0;
                                E[S.unk184].unkA0.unk0 = E[i].unkA0.unk0;
                                S.unk144[S.unk140] = script;
                                script = E[i].unk29C[k];
                                S.unk100[S.unk140] = S.unkFC;
                                S.unk140++;
                                S.unkFC = 0;
                                S.unkF4 = script[0];
                                E[i].unk29C[k] = 0;
                                flag = 1;
                            }
                            if (flag)
                                break;
                        }
                        if (flag)
                            break;
                    }
                    if (cnt == 0)
                        E[i].unk218 = 0;
                }
            }
            if (flag)
                break;
            for (i = 0; i < 16; i++) {
                if (E[i].unk0 == 0)
                    continue;
                if (E[i].unk8 <= E[i].unk4) {
                    for (k = 0; k < 3; k++) {
                        if (k == 0)
                            anim = &E[i].unk10;
                        else if (k == 1)
                            anim = &E[i].unk58;
                        else if (k == 2)
                            anim = &E[i].unkA0;
                        animation_interpolation_step(anim);
                    }
                    for (k = 0; k < 2; k++) {
                        if (k == 0)
                            trk = &E[i].unkE8;
                        else if (k == 1)
                            trk = &E[i].unk100;
                        if (trk->active) {
                            if (trk->start <= trk->timer) {
                                trk->value = trk->value + trk->step;
                                trk->timer++;
                                if (trk->end != 0xFFFF && trk->timer >= trk->end)
                                    trk->active = 0;
                            } else
                                trk->timer++;
                        }
                    }
                    for (j = 0; j < 2; j++) {
                        if (j == 0)
                            osc = &E[i].unk118;
                        else if (j == 1)
                            osc = &E[i].unk13C;
                        if (osc->type != 0) {
                            if (osc->start <= osc->timer) {
                                if (osc->type == 1) {
                                    osc->value = osc->value + osc->amp;
                                    for (k = 0; k < 4; k++) {
                                        if (j == 0)
                                            gAffineParams[i * 4 + k].scaleX = osc->value;
                                        else if (j == 1)
                                            gAffineParams[i * 4 + k].scaleY = osc->value;
                                    }
                                } else if (osc->type == 2) {
                                    osc->value = osc->amp * gSineTable[(s32)osc->angle & 0xFF];
                                    for (k = 0; k < 4; k++) {
                                        if (j == 0)
                                            gAffineParams[i * 4 + k].scaleX = osc->value;
                                        else if (j == 1)
                                            gAffineParams[i * 4 + k].scaleY = osc->value;
                                    }
                                    osc->angle = osc->angle + osc->angleStep;
                                } else if (osc->type == 3) {
                                    osc->value = osc->amp * gSineTable[((s32)osc->angle & 0xFF) + 0x40];
                                    for (k = 0; k < 4; k++) {
                                        if (j == 0)
                                            gAffineParams[i * 4 + k].scaleX = osc->value;
                                        else if (j == 1)
                                            gAffineParams[i * 4 + k].scaleY = osc->value;
                                    }
                                    osc->angle = osc->angle + osc->angleStep;
                                }
                                osc->timer++;
                                if (osc->end != 0xFFFF && osc->timer >= osc->end)
                                    osc->type = 4;
                            } else
                                osc->timer++;
                        }
                    }
                    for (k = 0; k < 3; k++) {
                        if (k == 0)
                            ramp = &E[i].unk160;
                        else if (k == 1)
                            ramp = &E[i].unk178;
                        else if (k == 2)
                            ramp = &E[i].unk190;
                        if (ramp->active) {
                            if (ramp->start <= ramp->timer) {
                                ramp->value = ramp->value + ramp->step;
                                ramp->timer++;
                                if (ramp->end != 0xFFFF && ramp->timer >= ramp->end)
                                    ramp->active = 0;
                            } else
                                ramp->timer++;
                        }
                    }
                    if (E[i].unk1A8.active) {
                        if (E[i].unk1A8.start <= E[i].unk1A8.timer) {
                            E[i].unk1A8.value = E[i].unk1A8.value + E[i].unk1A8.step;
                            for (k = 0; k < 4; k++)
                                gAffineParams[i * 4 + k].angle = (s32)E[i].unk1A8.value & 0xFF;
                            E[i].unk1A8.timer++;
                            if (E[i].unk1A8.end != 0xFFFF && E[i].unk1A8.timer >= E[i].unk1A8.end)
                                E[i].unk1A8.active = 0;
                        } else
                            E[i].unk1A8.timer++;
                    }
                    if (E[i].unk208) {
                        for (k = 0; k < E[i].unk210; k++)
                            advance_sprite_animation_frame(E[i].unk2DC[k]);
                    }
                    if (E[i].unk1C0.active) {
                        if (E[i].unk1C0.start <= E[i].unk1C0.timer) {
                            for (k = 0; k < E[i].unk210; k++)
                                gSpriteEntries[E[i].unk2DC[k]].unk0 |= 0x4000;
                            E[i].unk1C0.timer++;
                            if (E[i].unk1C0.end != 0xFFFF && E[i].unk1C0.timer >= E[i].unk1C0.end) {
                                for (k = 0; k < E[i].unk210; k++)
                                    sprite_entry_clear(E[i].unk2DC[k]);
                                E[i].unk1C0.active = 0;
                                E[i].unk208 = 0;
                            }
                        } else
                            E[i].unk1C0.timer++;
                    }
                    if (E[i].unk1D0.active) {
                        if (E[i].unk1D0.start <= E[i].unk1D0.timer) {
                            if (!(E[i].unk1D0.timer & 1)) {
                                for (k = 0; k < E[i].unk210; k++)
                                    gSpriteEntries[E[i].unk2DC[k]].unk0 &= ~0x4000;
                            } else {
                                for (k = 0; k < E[i].unk210; k++)
                                    gSpriteEntries[E[i].unk2DC[k]].unk0 |= 0x4000;
                            }
                            E[i].unk1D0.timer++;
                            if (E[i].unk1D0.end != 0xFFFF && E[i].unk1D0.timer >= E[i].unk1D0.end)
                                E[i].unk1D0.active = 0;
                        } else
                            E[i].unk1D0.timer++;
                    }
                    if (E[i].unk2EC.active) {
                        if (E[i].unk2EC.start <= E[i].unk2EC.timer) {
                            field_play_sound_effect(E[i].unk2FC);
                            E[i].unk2EC.timer++;
                            if (E[i].unk2EC.end != 0xFFFF && E[i].unk2EC.timer >= E[i].unk2EC.end)
                                E[i].unk2EC.active = 0;
                        } else
                            E[i].unk2EC.timer++;
                    }
                    E[i].unk4++;
                    if (E[i].unkC != 0xFFFF && E[i].unk4 >= E[i].unkC)
                        done++;
                } else
                    E[i].unk4++;
            }
            field_effect_project_objects();
            for (i = 0; i < 16; i++) {
                if (E[i].unk0 == 2)
                    done++;
            }
            for (i = 0; i < 16; i++) {
                if (E[i].unk0 != 0 && (E[i].unk118.type | E[i].unk13C.type) == 0) {
                    for (k = 0; k < 4; k++) {
                        d = gSpriteEntries[E[i].unk2DC[k]].unk14_8;
                        if (d > S.unk9C) {
                            gAffineParams[i * 4 + k].scaleX = 0x101 - d / S.unk9C;
                            gAffineParams[i * 4 + k].scaleY = 0x101 - gSpriteEntries[E[i].unk2DC[k]].unk14_8 / S.unk9C;
                        } else {
                            gAffineParams[i * 4 + k].scaleX = S.unk9C / d + 0xFF;
                            gAffineParams[i * 4 + k].scaleY = S.unk9C / gSpriteEntries[E[i].unk2DC[k]].unk14_8 + 0xFF;
                        }
                    }
                }
            }
            field_effect_update_sprite_depth();
            if (S.unk1F4 != 0) {
                if (S.unk200 <= S.unk1FC) {
                    S.unk1FC++;
                    switch (S.unk1F4) {
                    case 1:
                        if (run_blend_fade_transition(0x7FFF)) {
                            S.unk1F4 = 0;
                            done++;
                        }
                        break;
                    case 2:
                        if (run_blend_fade_transition(0x7FFF)) {
                            S.unk1F4 = 0;
                            done++;
                        }
                        break;
                    case 3:
                        blend_effect_update();
                        field_bg_palettes_blend_masked(S.unk210 << 10 | S.unk20F << 5 | S.unk20E, S.unk208 * S.unk1F8,
                                                       S.unk20A);
                        field_obj_palettes_blend_masked(S.unk210 << 10 | S.unk20F << 5 | S.unk20E, S.unk208 * S.unk1F8,
                                                        S.unk20C);
                        if (S.unk208 < 0x20 / S.unk1F8)
                            S.unk208++;
                        else {
                            gVBlankCallback = empty_callback;
                            S.unk1F4 = 0;
                            done++;
                        }
                        break;
                    case 4:
                        blend_effect_update();
                        r = S.unk208 * S.unk1F8 - 1;
                        g = r;
                        bl = r;
                        if (r < S.unk20E)
                            r = S.unk20E;
                        if (g < S.unk20F)
                            g = S.unk20F;
                        if (bl < S.unk210)
                            bl = S.unk210;
                        color = bl << 10 | g << 5 | r;
                        field_bg_palettes_blend_masked(color, S.unk208 * S.unk1F8, S.unk20A);
                        field_obj_palettes_blend_masked(color, S.unk208 * S.unk1F8, S.unk20C);
                        if (S.unk208 != 0)
                            S.unk208--;
                        else {
                            gVBlankCallback = empty_callback;
                            S.unk1F4 = 0;
                            done++;
                        }
                        break;
                    }
                    if (S.unk204 != 0xFFFF && S.unk1FC >= S.unk204) {
                        gVBlankCallback = empty_callback;
                        S.unk1F4 = 0;
                        done++;
                    }
                } else
                    S.unk1FC++;
            }
            if (done == 0)
                break;
            if (S.unk1F4 != 0)
                break;
            S.unkFC++;
            S.unkF4 = script[S.unkFC];
            break;
        case 3: // guess: set current entity state/timer/start/end
            S.unkFC++;
            S.unkFC++;
            n = S.unk184;
            E[n].unk0 = script[S.unkFC++];
            E[n].unk4 = script[S.unkFC++];
            E[n].unk8 = script[S.unkFC++];
            E[n].unkC = script[S.unkFC++];
            break;
        case 5: // guess: skip one argument
            S.unkFC++;
            S.unkFC++;
            break;
        case 6: // guess: set x (absolute or relative to the parent entity)
            S.unkFC++;
            S.unkFC++;
            n = S.unk184;
            if (script[S.unkFC++] == 0)
                E[n].unk10.unk0 = script[S.unkFC++];
            else
                E[n].unk10.unk0 = script[S.unkFC++] + E[E[n].unk214].unk10.unk0;
            break;
        case 7: // guess: set y (absolute or relative to the parent entity)
            S.unkFC++;
            S.unkFC++;
            n = S.unk184;
            if (script[S.unkFC++] == 0)
                E[n].unk58.unk0 = script[S.unkFC++];
            else
                E[n].unk58.unk0 = script[S.unkFC++] + E[E[n].unk214].unk58.unk0;
            break;
        case 8: // guess: set z (absolute or relative to the parent entity)
            S.unkFC++;
            S.unkFC++;
            n = S.unk184;
            if (script[S.unkFC++] == 0)
                E[n].unkA0.unk0 = script[S.unkFC++];
            else
                E[n].unkA0.unk0 = script[S.unkFC++] + E[E[n].unk214].unkA0.unk0;
            break;
        case 9: // guess: set yaw
            S.unkFC++;
            S.unkFC++;
            n = S.unk184;
            E[n].unkE8.value = script[S.unkFC++];
            break;
        case 10: // guess: set pitch
            S.unkFC++;
            S.unkFC++;
            n = S.unk184;
            E[n].unk100.value = script[S.unkFC++];
            break;
        case 11: // guess: set affine x-scale oscillator type/value
            S.unkFC++;
            S.unkFC++;
            n = S.unk184;
            E[n].unk118.type = script[S.unkFC++];
            E[n].unk118.value = script[S.unkFC++];
            if (E[n].unk118.type == 0)
                break;
            for (k = 0; k < 4; k++)
                gAffineParams[n * 4 + k].scaleX = E[n].unk118.value;
            break;
        case 12: // guess: set affine y-scale oscillator type/value
            S.unkFC++;
            S.unkFC++;
            n = S.unk184;
            E[n].unk13C.type = script[S.unkFC++];
            E[n].unk13C.value = script[S.unkFC++];
            if (E[n].unk13C.type == 0)
                break;
            for (k = 0; k < 4; k++)
                gAffineParams[n * 4 + k].scaleY = E[n].unk13C.value;
            break;
        case 13: // guess: set 3-D scale x
            S.unkFC++;
            S.unkFC++;
            n = S.unk184;
            E[n].unk160.value = script[S.unkFC++];
            break;
        case 14: // guess: set 3-D scale y
            S.unkFC++;
            S.unkFC++;
            n = S.unk184;
            E[n].unk178.value = script[S.unkFC++];
            break;
        case 15: // guess: set 3-D scale z
            S.unkFC++;
            S.unkFC++;
            n = S.unk184;
            E[n].unk190.value = script[S.unkFC++];
            break;
        case 16: // guess: set up x/y/z interpolation (16 words)
        case 17:
        case 18:
            S.unkFC++;
            S.unkFC++;
            n = S.unk184;
            if (S.unkF4 == 0x10)
                anim = &E[n].unk10;
            else if (S.unkF4 == 0x11)
                anim = &E[n].unk58;
            else if (S.unkF4 == 0x12)
                anim = &E[n].unkA0;
            memcpy_u8(&script[S.unkFC], buf, 0x40);
            S.unkFC += 0x10;
            anim_interp_init(anim, buf);
            break;
        case 23: // guess: 3-D scale x ramp
            S.unkFC++;
            S.unkFC++;
            n = S.unk184;
            E[n].unk160.active = script[S.unkFC++];
            E[n].unk160.step = script[S.unkFC++] / 10.0f;
            E[n].unk160.timer = script[S.unkFC++];
            E[n].unk160.start = script[S.unkFC++];
            E[n].unk160.end = script[S.unkFC++];
            break;
        case 24: // guess: 3-D scale y ramp
            S.unkFC++;
            S.unkFC++;
            n = S.unk184;
            E[n].unk178.active = script[S.unkFC++];
            E[n].unk178.step = script[S.unkFC++] / 10.0f;
            E[n].unk178.timer = script[S.unkFC++];
            E[n].unk178.start = script[S.unkFC++];
            E[n].unk178.end = script[S.unkFC++];
            break;
        case 25: // guess: 3-D scale z ramp
            S.unkFC++;
            S.unkFC++;
            n = S.unk184;
            E[n].unk190.active = script[S.unkFC++];
            E[n].unk190.step = script[S.unkFC++] / 10.0f;
            E[n].unk190.timer = script[S.unkFC++];
            E[n].unk190.start = script[S.unkFC++];
            E[n].unk190.end = script[S.unkFC++];
            break;
        case 19: // guess: yaw track
            S.unkFC++;
            S.unkFC++;
            n = S.unk184;
            E[n].unkE8.active = script[S.unkFC++];
            E[n].unkE8.step = script[S.unkFC++] * 0.125f;
            E[n].unkE8.timer = script[S.unkFC++];
            E[n].unkE8.start = script[S.unkFC++];
            E[n].unkE8.end = script[S.unkFC++];
            break;
        case 20: // guess: pitch track
            S.unkFC++;
            S.unkFC++;
            n = S.unk184;
            E[n].unk100.active = script[S.unkFC++];
            E[n].unk100.step = script[S.unkFC++] * 0.125f;
            E[n].unk100.timer = script[S.unkFC++];
            E[n].unk100.start = script[S.unkFC++];
            E[n].unk100.end = script[S.unkFC++];
            break;
        case 21: // guess: affine x-scale oscillator
            S.unkFC++;
            S.unkFC++;
            n = S.unk184;
            E[n].unk118.type = script[S.unkFC++];
            E[n].unk118.amp = script[S.unkFC++] * 0.125f;
            E[n].unk118.angle = script[S.unkFC++];
            E[n].unk118.angleStep = script[S.unkFC++];
            E[n].unk118.timer = script[S.unkFC++];
            E[n].unk118.start = script[S.unkFC++];
            E[n].unk118.end = script[S.unkFC++];
            break;
        case 22: // guess: affine y-scale oscillator
            S.unkFC++;
            S.unkFC++;
            n = S.unk184;
            E[n].unk13C.type = script[S.unkFC++];
            E[n].unk13C.amp = script[S.unkFC++] * 0.125f;
            E[n].unk13C.angle = script[S.unkFC++];
            E[n].unk13C.angleStep = script[S.unkFC++];
            E[n].unk13C.timer = script[S.unkFC++];
            E[n].unk13C.start = script[S.unkFC++];
            E[n].unk13C.end = script[S.unkFC++];
            break;
        case 26: // guess: affine angle ramp
            S.unkFC++;
            S.unkFC++;
            n = S.unk184;
            E[n].unk1A8.active = script[S.unkFC++];
            E[n].unk1A8.step = script[S.unkFC++] * 0.125f;
            E[n].unk1A8.timer = script[S.unkFC++];
            E[n].unk1A8.start = script[S.unkFC++];
            E[n].unk1A8.end = script[S.unkFC++];
            break;
        case 27: // guess: create a sprite part (gfx + palette from the script set)
            S.unkFC++;
            S.unkFC++;
            n = S.unk184;
            part = script[S.unkFC++];
            x = script[S.unkFC++];
            y = script[S.unkFC++];
            attr = script[S.unkFC++];
            model = gUnk_083D2DB0[S.unkF8][n];
            E[n].unk210 = *model;
            if (part >= *model)
                break;
            E[n].unk2DC[part] = n * 4 + part;
            E[n].unk2E0[part] = 0;
            E[n].unk2E8[part] = 0;
            LZ77UnCompVram(gUnk_0847ECC0[S.unkF8], (void *)0x06016C00);
            if (!(S.unk1D4 & 0x80))
                DmaSet(3, gUnk_0847EC40[S.unkF8], 0x050003A0, 0x84000008) else DmaSet(3, gUnk_0847EC40[S.unkF8],
                                                                                      0x0202F9A0, 0x84000008)
                    sprite_entry_init(E[n].unk2DC[part], x, (u16)y, 0xD, 1);
            gSpriteEntries[E[n].unk2DC[part]].unk0 |= attr;
            gSpriteEntries[E[n].unk2DC[part]].filler1D[0] = n * 4 + part;
            break;
        case 134: // guess: set a sprite part (slot, offsets, attributes)
            S.unkFC++;
            S.unkFC++;
            n = S.unk184;
            part = script[S.unkFC++];
            E[n].unk2DC[part] = script[S.unkFC++];
            E[n].unk2E0[part] = script[S.unkFC++];
            E[n].unk2E8[part] = script[S.unkFC++];
            gSpriteEntries[E[n].unk2DC[part]].unk0 = script[S.unkFC++];
            gSpriteEntries[E[n].unk2DC[part]].filler1D[0] = n * 4 + part;
            break;
        case 28: // guess: hide timer, then free the sprites
            S.unkFC++;
            S.unkFC++;
            n = S.unk184;
            E[n].unk1C0.active = script[S.unkFC++];
            E[n].unk1C0.timer = script[S.unkFC++];
            E[n].unk1C0.start = script[S.unkFC++];
            E[n].unk1C0.end = script[S.unkFC++];
            break;
        case 29: // guess: animate sprites flag + palette
            S.unkFC++;
            S.unkFC++;
            n = S.unk184;
            E[n].unk208 = script[S.unkFC++];
            E[n].unk204 = script[S.unkFC++];
            for (k = 0; k < 4; k++)
                sprite_anim_start(E[n].unk2DC[k], E[n].unk204);
            break;
        case 30: // guess: blink timer
            S.unkFC++;
            S.unkFC++;
            n = S.unk184;
            E[n].unk1D0.active = script[S.unkFC++];
            E[n].unk1D0.timer = script[S.unkFC++];
            E[n].unk1D0.start = script[S.unkFC++];
            E[n].unk1D0.end = script[S.unkFC++];
            break;
        case 31: // guess: x range check
            S.unkFC++;
            S.unkFC++;
            n = S.unk184;
            E[n].unk1E0 = script[S.unkFC++];
            E[n].unk1E4 = script[S.unkFC++];
            E[n].unk1E8 = script[S.unkFC++];
            break;
        case 32: // guess: y range check
            S.unkFC++;
            S.unkFC++;
            n = S.unk184;
            E[n].unk1EC = script[S.unkFC++];
            E[n].unk1F0 = script[S.unkFC++];
            E[n].unk1F4 = script[S.unkFC++];
            break;
        case 33: // guess: depth range check
            S.unkFC++;
            S.unkFC++;
            n = S.unk184;
            E[n].unk1F8 = script[S.unkFC++];
            E[n].unk1FC = script[S.unkFC++];
            E[n].unk200 = script[S.unkFC++];
            break;
        case 34: // guess: call: select entity, run a sub-script
            S.unkFC++;
            S.unk188[S.unk140] = script[S.unkFC++];
            S.unk184 = S.unk188[S.unk140];
            S.unk144[S.unk140] = script;
            script = (s32 *)script[S.unkFC++];
            S.unk100[S.unk140] = S.unkFC;
            S.unk140++;
            S.unkFC = 0;
            break;
        case 35: // guess: return from a sub-script
            S.unkFC++;
            S.unk140--;
            S.unkFC = S.unk100[S.unk140];
            script = S.unk144[S.unk140];
            S.unk184 = S.unk188[S.unk140];
            break;
        case 36: // guess: add a trigger: run a sub-script on another entity at a given time
        {
            s32 old;

            S.unkFC++;
            S.unk188[S.unk140] = script[S.unkFC++];
            k = S.unk188[S.unk140];
            E[S.unk184].unk25C[k] = k;
            v = script[S.unkFC++];
            E[S.unk184].unk218 = v & 0xFF;
            E[S.unk184].unk21C[k] = script[S.unkFC++];
            E[S.unk184].unk29C[k] = (s32 *)script[S.unkFC++];
            E[k].unk214 = S.unk184;
            if ((v & 0xFF00) != 0x100)
                break;
            a = script[S.unkFC++];
            b = script[S.unkFC++];
            if (a != 1)
                break;
            old = E[S.unk184].unk21C[k];
            if (b == 0)
                tmp = E[S.unk184].unkA0.unk24;
            E[S.unk184].unk21C[k] = tmp - old;
            break;
        }
        case 128: // guess: fade from white (with OBJ)
            S.unkFC++;
            S.unk1FC = script[S.unkFC++];
            S.unk200 = script[S.unkFC++];
            S.unk204 = script[S.unkFC++];
            setup_palette_fade_to_color_with_obj(0x7FFF, 0.0f, 32.0f, 8.0f);
            S.unk1F4 = 1;
            break;
        case 129: // guess: fade to white
            S.unkFC++;
            S.unk1FC = script[S.unkFC++];
            S.unk200 = script[S.unkFC++];
            S.unk204 = script[S.unkFC++];
            setup_palette_fade_to_color(0x7FFF, 32.0f, 0.0f, 8.0f);
            S.unk1F4 = 2;
            break;
        case 130: // guess: palette blend in
            S.unkFC++;
            S.unk208 = script[S.unkFC++];
            S.unk20A = script[S.unkFC++];
            S.unk20C = script[S.unkFC++];
            S.unk20E = script[S.unkFC++];
            S.unk20F = script[S.unkFC++];
            S.unk210 = script[S.unkFC++];
            S.unk1F8 = script[S.unkFC++];
            S.unk1FC = script[S.unkFC++];
            S.unk200 = script[S.unkFC++];
            S.unk204 = script[S.unkFC++];
            S.unk1F4 = 3;
            field_palette_backup();
            setup_blend_effect(0x40, 0x2F00, 6, 8, 8, 8, 0xD, 0xB, 0);
            break;
        case 131: // guess: palette blend out
            S.unkFC++;
            S.unk208 = script[S.unkFC++];
            S.unk20A = script[S.unkFC++];
            S.unk20C = script[S.unkFC++];
            S.unk20E = script[S.unkFC++];
            S.unk20F = script[S.unkFC++];
            S.unk210 = script[S.unkFC++];
            S.unk1F8 = script[S.unkFC++];
            S.unk1FC = script[S.unkFC++];
            S.unk200 = script[S.unkFC++];
            S.unk204 = script[S.unkFC++];
            S.unk1F4 = 4;
            if (S.unk208 != 0) {
                if (S.unk208 == 0x10) {
                    field_palettes_blend_to_color(0x7FFF, 0x20);
                    gBlendEffect.fade_amount = 32.0f;
                    gBlendEffect.fade_end = 0.0f;
                    setup_blend_effect(0x40, 0x2F00, 5, 8, 8, 8, 0xE, 0xC, 0);
                } else if (S.unk208 == 8)
                    setup_blend_effect(0x40, 0x2F00, 6, 8, 8, 8, 0xC, 0xA, 0);
            } else
                setup_blend_effect(0x40, 0x2F00, 4, 8, 8, 8, 0x10, 0x10, 0);
            break;
        case 132: // guess: clear the sprites and reload the field
            S.unkFC++;
            save_script_sprites();
            memzero_bytes((u8 *)gSpriteEntries, 0x2000);
            memzero_bytes((u8 *)gUnk_030055A0, 0x200);
            zero = 0;
            DmaSet(3, &zero, OAM, 0x85000100);
            restore_script_sprites();
            if (S.unkF8 == 0x12) {
                if (gUnk_03006D38.unk5 <= 8)
                    S.unk1E0 = gUnk_083D2AAB[gUnk_03006D38.unk5];
                else
                    S.unk1E0 = 0;
                S.unk1D8 = gUnk_083D2AB4[gUnk_03006D38.unk5 * 4 + 2] << 4;
                S.unk1DC = gUnk_083D2AB4[gUnk_03006D38.unk5 * 4 + 3] << 4;
                gFieldWork.player_x = S.unk1D8;
                gFieldWork.player_y = S.unk1DC;
                gFieldWork.player_tile_x = field_pixel_x_to_tile(gFieldWork.player_x);
                gFieldWork.player_tile_y = field_pixel_y_to_tile(gFieldWork.player_y);
                gFieldWork.area_id = S.unk1E0;
                field_center_camera_on_player();
                field_update_music(0xC, 0);
            } else if (S.unkF8 == 0xE) {
                S.unk1E0 = gUnk_083D2AD8;
                S.unk1D8 = gUnk_083D2AD9[2] << 4;
                S.unk1DC = gUnk_083D2AD9[3] << 4;
                gFieldWork.player_x = S.unk1D8;
                gFieldWork.player_y = S.unk1DC;
                gFieldWork.player_tile_x = field_pixel_x_to_tile(gFieldWork.player_x);
                gFieldWork.player_tile_y = field_pixel_y_to_tile(gFieldWork.player_y);
                gFieldWork.area_id = S.unk1E0;
                field_center_camera_on_player();
                field_update_music(0xA, 0);
            }
            gFieldWork.npc_load_mode = 1;
            area_load_graphics();
            area_load_encounter_rate();
            gSpriteEntries[89].unk0 &= ~0x4000;
            break;
        case 133: // guess: set unk214..unk220
            S.unkFC++;
            S.unk214 = script[S.unkFC++];
            S.unk218 = script[S.unkFC++];
            S.unk21C = script[S.unkFC++];
            S.unk220 = script[S.unkFC++];
            break;
        case 135: // guess: set unk224..unk23C
            S.unkFC++;
            S.unk224 = script[S.unkFC++];
            S.unk228 = script[S.unkFC++];
            S.unk22C = script[S.unkFC++];
            S.unk230 = script[S.unkFC++];
            S.unk234 = script[S.unkFC++];
            S.unk238 = script[S.unkFC++];
            S.unk23C = script[S.unkFC++];
            break;
        case 137: // guess: copy z / end frames between entities
        {
            s32 src, dst;

            S.unkFC++;
            src = script[S.unkFC++];
            dst = script[S.unkFC++];
            switch (script[S.unkFC++]) {
            case 0:
                E[dst].unkA0.unk0 = E[src].unkA0.unk0;
                break;
            case 1:
                E[dst].unkC = E[src].unkA0.unk24;
                break;
            case 2:
                E[dst].unkC = E[src].unk58.unk24;
                break;
            case 3:
                E[dst].unkC = E[src].unk10.unk24;
                break;
            }
            break;
        }
        case 138: // guess: callback timer (field_play_sound_effect)
            S.unkFC++;
            S.unkFC++;
            n = S.unk184;
            E[n].unk2EC.active = script[S.unkFC++];
            E[n].unk2EC.timer = script[S.unkFC++];
            E[n].unk2EC.start = script[S.unkFC++];
            E[n].unk2EC.end = script[S.unkFC++];
            E[n].unk2FC = script[S.unkFC++];
            break;
        case 136: // guess: set gFieldWork.unkC4C and refresh the status chars
            S.unkFC++;
            gFieldWork.unkC4C = script[S.unkFC++];
            update_battle_entity_status_chars();
            break;
        default:
            S.unkF4 = 0;
            S.unkFC = 0;
            break;
        }
        if (S.unkF4 == 0)
            break;
        if (S.unkF4 == 1)
            break;
        if (S.unkF4 == 2)
            break;
        if (S.unkF4 == 4) {
            S.unkFC = 0;
            S.unkF0 = 0;
            if ((S.unk1D4 & 0x3F) != 0xD && (S.unk1D4 & 0x3F) != 0x16) {
                s32 q;

                affine_params_reset();
                for (q = 0; q < 32; q++)
                    calculate_oam_affine_matrix(q);
            }
            if (S.unkF8 == 0xE || S.unkF8 == 0x12) {
                gFieldWork.player_facing = 1;
                set_battle_state_cancel_flag();
                init_battle_field_setup();
                update_bg_scroll_offsets_a();
                field_set_player_facing(gFieldWork.player_facing);
                if (gFieldWork.follower_active) {
                    follower_set_facing(gSpriteEntries[47].unk20);
                    sprite_anim_start(0x30, gSpriteEntries[48].unk2B * 4 + gSpriteEntries[48].unk20);
                }
                update_battle_entity_status_chars();
            }
            if (S.unkF4 == 4)
                break;
        }
    }
    return S.unkF4;
}

#include "keys.h"

static void field_effect_update_sprite_depth(void) {
    struct Unk_03005350 *b = &gUnk_03005350;
    s32 i, j;
    s32 d;
    struct SpriteEntry *s;

    if (b->unkF0 != 0) {
        for (i = 0; i <= 15; i++) {
            for (j = 0; j <= 3; j++) {
                struct SpriteEntry *spr = gSpriteEntries;

                s = &spr[gUnk_03006D30[i].unk2DC[j]];
                d = s->unk14_8;
                if (d > gUnk_03005350.unk9C) {
                    s->unkB = gUnk_03005350.unk218;
                    gSpriteEntries[gUnk_03006D30[i].unk2DC[j]].unk0 &= 0xF3FF;
                    gSpriteEntries[gUnk_03006D30[i].unk2DC[j]].unk0 |= gUnk_03005350.unk220;
                } else {
                    s->unkB = gUnk_03005350.unk214 + (gUnk_03005350.unk9C - d);
                    gSpriteEntries[gUnk_03006D30[i].unk2DC[j]].unk0 &= 0xF3FF;
                    gSpriteEntries[gUnk_03006D30[i].unk2DC[j]].unk0 |= gUnk_03005350.unk21C;
                }
            }
        }
    }
}

void anim_interp_init(struct AnimInterp *p, s32 *a) {
    s32 mode;
    float x, phase;

    p->unkC = mode = a[0];
    p->unk10 = a[1] / 256;
    p->unk14 = a[2];
    p->unk18 = a[3] * (1.0f / 256);
    p->unk1C = a[4];
    p->unk20 = a[5];
    p->unk24 = a[6];
    p->unk28 = a[7];
    p->unk2C = a[8];
    p->unk30 = a[9];
    p->unk34 = a[10];
    p->unk38 = a[11];
    p->unk3C = a[12] * (1.0f / 256);
    p->unk40 = a[13] * (1.0f / 256);
    p->unk44 = a[14];
    if (mode > 1)
        p->unk4 = p->unk0;

    switch (p->unkC) {
    case 0x10:
        p->unk2C = x = p->unk34 / float_default_to_one_if_zero(float_abs_if_negative(p->unk3C));
        p->unk24 = p->unk20 + x;
        if (p->unk44 != 0)
            p->unk0 = p->unk0 - float_sign(p->unk3C) * float_abs_if_negative(p->unk34);
        break;
    case 0x11:
        p->unk24 = p->unk20 + p->unk28;
        p->unk34 = p->unk3C * p->unk2C;
        if (p->unk44 != 0)
            p->unk0 = p->unk0 - float_sign(p->unk3C) * float_abs_if_negative(p->unk34);
        break;
    case 0x12: {
        float sum;
        s32 n;

        p->unk3C = p->unk34 * (1.0f / 64);
        phase = p->unk14;
        sum = 0.0f;
        n = 0;
        for (;;) {
            if (p->unk3C == 0.0f)
                break;
            phase = phase + p->unk3C;
            if (phase >= 64.0f)
                phase = 64.0f;
            sum = sum + p->unk40 * (gSineTable[(s32)(phase + 192.0f) & 0xFF] + 256.0f) * (1.0f / 256);
            if (float_abs_if_negative(sum) >= p->unk34)
                break;
            n++;
        }
        p->unk2C = n;
        p->unk30 = x = p->unk38 / float_default_to_one_if_zero(float_abs_if_negative(p->unk40));
        p->unk24 = p->unk20 + p->unk2C + x;
        p->unk38 = p->unk38 + (p->unk34 - float_abs_if_negative(sum));
        if (p->unk44 != 0)
            p->unk0 =
                p->unk0 - float_sign(p->unk40) * (float_abs_if_negative(p->unk34) + float_abs_if_negative(p->unk38));
        break;
    }
    case 0x13: {
        float step;

        p->unk24 = p->unk20 + p->unk28;
        p->unk30 = p->unk28 - p->unk2C;
        p->unk3C = step = 64.0f / float_default_to_one_if_zero(p->unk2C);
        p->unk38 = p->unk40 * p->unk30;
        phase = p->unk14;
        p->unk34 = 0.0f;
        for (;;) {
            if (step == 0.0f)
                break;
            phase = phase + step;
            p->unk34 = p->unk34 + p->unk40 * (gSineTable[(s32)(phase + 192.0f) & 0xFF] + 256.0f) * (1.0f / 256);
            if (phase >= 64.0f)
                break;
        }
        if (p->unk44 != 0)
            p->unk0 =
                p->unk0 - float_sign(p->unk40) * (float_abs_if_negative(p->unk34) + float_abs_if_negative(p->unk38));
        break;
    }
    case 0x14: {
        float sum;
        s32 n;

        p->unk40 = 64.0f / p->unk38;
        phase = p->unk14;
        sum = 0.0f;
        n = 0;
        for (;;) {
            phase = phase + p->unk40;
            if (phase >= 64.0f)
                phase = 64.0f;
            sum = sum + p->unk3C * gSineTable[((s32)phase & 0xFF) + 0x40] * (1.0f / 256);
            if (phase == 64.0f)
                break;
            n++;
        }
        p->unk30 = n;
        p->unk34 = p->unk34 + (p->unk38 - float_abs_if_negative(sum));
        p->unk38 = float_abs_if_negative(sum);
        p->unk2C = x = p->unk34 / float_default_to_one_if_zero(float_abs_if_negative(p->unk3C));
        p->unk24 = p->unk20 + x + p->unk30;
        if (p->unk44 != 0)
            p->unk0 =
                p->unk0 - float_sign(p->unk3C) * (float_abs_if_negative(p->unk34) + float_abs_if_negative(p->unk38));
        break;
    }
    case 0x15: {

        p->unk24 = p->unk20 + p->unk28;
        p->unk34 = p->unk3C * (p->unk2C = p->unk28 - p->unk30);
        p->unk40 = 64.0f / float_default_to_one_if_zero(p->unk30);
        phase = p->unk14;
        p->unk38 = 0.0f;
        for (;;) {
            phase = phase + p->unk40;
            p->unk38 = p->unk38 + p->unk3C * gSineTable[((s32)phase & 0xFF) + 0x40] * (1.0f / 256);
            if (phase >= 64.0f)
                break;
        }
        if (p->unk44 != 0)
            p->unk0 =
                p->unk0 - float_sign(p->unk3C) * (float_abs_if_negative(p->unk34) + float_abs_if_negative(p->unk38));
        break;
    }
    case 0x17:
        p->unk24 = p->unk20 + p->unk28;
        p->unk0 = p->unk4 + p->unk40 * gSineTable[(s32)p->unk2C & 0xFF];
        p->unk14 = p->unk2C;
        break;
    }
}

u32 animation_interpolation_step(struct AnimInterp *p) {
    u32 ret = 0;
    s32 one = 1;
    float s;

    if (p->unkC != 0) {
        if (p->unk20 <= p->unk1C) {
            switch (p->unkC) {
            case 0x10:
            case 0x11:
                if (p->unk1C < p->unk20 + p->unk2C)
                    p->unk0 = p->unk0 + p->unk3C;
                break;
            case 0x12:
            case 0x13:
                if (p->unk1C < p->unk20 + p->unk2C) {
                    s = one;
                    p->unk14 = p->unk14 + p->unk3C * s;
                    if (p->unk14 >= 64.0f)
                        p->unk14 = 64.0f;
                    p->unk0 =
                        p->unk0 + p->unk40 * (gSineTable[(s32)(p->unk14 + 192.0f) & 0xFF] + 256.0f) * (1.0f / 256) * s;
                } else
                    p->unk0 = p->unk0 + p->unk40;
                break;
            case 0x14:
            case 0x15:
                if (p->unk1C < p->unk20 + p->unk2C)
                    p->unk0 = p->unk0 + p->unk3C;
                else {
                    p->unk14 = p->unk14 + p->unk40;
                    if (p->unk14 >= 64.0f)
                        p->unk14 = 64.0f;
                    p->unk0 = p->unk0 + p->unk3C * gSineTable[((s32)p->unk14 & 0xFF) + 0x40] * (1.0f / 256) * one;
                }
                break;
            case 0x17:
                p->unk14 = p->unk14 + p->unk3C;
                p->unk0 = p->unk4 + p->unk40 * gSineTable[(s32)p->unk14 & 0xFF] * one;
                break;
            }
            p->unk1C = p->unk1C + 1.0f;
            if (p->unk24 != 0xFFFF && p->unk1C >= p->unk24) {
                p->unkC = 0;
                ret = 1;
            }
        } else
            p->unk1C = p->unk1C + 1.0f;
    }
    return ret;
}
