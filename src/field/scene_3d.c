// Field effects ("MAP_EFFECT" on the debug screen): small 3-D sprite scenes played inside the field,
// e.g. the map warp (0x12) and teleport (0xE) effects of field/field_update. field_effect_start picks an
// effect (flags & 0x3F; 0x40 = at the player) and resets the state in gFieldEffect; field_effect_run runs
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
    memzero_bytes((u8 *)&gFieldEffect, 0x240);
    gFieldEffect.flags = flags;
    if (flags & 0x40) {
        x = gFieldWork.player_x;
        y = gFieldWork.player_y;
    }
    gFieldEffect.pos_x = x;
    gFieldEffect.pos_y = y;
    gFieldEffect.area_id = d;
}

void field_effect_reset_view(void) {
    field_effect_init_viewport();
    gFieldEffect.origin[0] = gFieldEffect.pos_x - gBg1Scroll.x - 0x70;
    gFieldEffect.origin[1] = gFieldEffect.pos_y - gBg1Scroll.y - 0x50;
    memzero_bytes((u8 *)gFieldEffectEntities, 0x3000);
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
    *x = gFieldEffect.camera_x;
    *y = gFieldEffect.camera_y;
    *z = gFieldEffect.camera_z;
}

static void field_effect_init_viewport(void) {
    field_effect_init_viewport_centered();
}

static void field_effect_init_viewport_centered(void) {
    s32 zero;

    gFieldEffect.viewport_w = 240;
    gFieldEffect.viewport_h = 160;
    zero = 0;
    gFieldEffect.viewport_cx = 120;
    gFieldEffect.viewport_cy = 80;
    affine_set_destination_and_compute_transform(-120.5f, 120.5f, -80.5f, 80.5f);
    affine_set_source_and_compute_transform(-120.5f, 120.5f, -80.5f, 80.5f);
    gFieldEffect.screen_x = zero;
    gFieldEffect.screen_y = zero;
}

static void affine_set_destination_and_compute_transform(float x0, float x1, float y0, float y1) {
    gFieldEffect.dst_x0 = x0;
    gFieldEffect.dst_x1 = x1;
    gFieldEffect.dst_y0 = y0;
    gFieldEffect.dst_y1 = y1;
    gFieldEffect.scale_x = (gFieldEffect.src_x1 - gFieldEffect.src_x0) / (x1 - x0);
    gFieldEffect.scale_y = (gFieldEffect.src_y1 - gFieldEffect.src_y0) / (y1 - y0);
    gFieldEffect.offset_x = (x1 * gFieldEffect.src_x0 - x0 * gFieldEffect.src_x1) / (x1 - x0);
    gFieldEffect.offset_y = (y1 * gFieldEffect.src_y0 - y0 * gFieldEffect.src_y1) / (y1 - y0);
}

static void affine_set_source_and_compute_transform(float x0, float x1, float y0, float y1) {
    gFieldEffect.src_x0 = x0;
    gFieldEffect.src_x1 = x1;
    gFieldEffect.src_y0 = y0;
    gFieldEffect.src_y1 = y1;
    gFieldEffect.scale_x = (x1 - x0) / (gFieldEffect.dst_x1 - gFieldEffect.dst_x0);
    gFieldEffect.scale_y = (y1 - y0) / (gFieldEffect.dst_y1 - gFieldEffect.dst_y0);
    gFieldEffect.offset_x =
        (gFieldEffect.dst_x1 * x0 - gFieldEffect.dst_x0 * x1) / (gFieldEffect.dst_x1 - gFieldEffect.dst_x0);
    gFieldEffect.offset_y =
        (gFieldEffect.dst_y1 * y0 - gFieldEffect.dst_y0 * y1) / (gFieldEffect.dst_y1 - gFieldEffect.dst_y0);
}

void set_state_float_field(float a, float b, float c, float d) {
    float x, y, z, len;

    gFieldEffect.camera_dist = c;
    gFieldEffect.projection_scale = d;
    gFieldEffect.cos_yaw = gCosTableF32[(s32)a & 0xFF];
    gFieldEffect.sin_yaw = gSinTableF32[(s32)a & 0xFF];
    gFieldEffect.cos_pitch = gCosTableF32[(s32)b & 0xFF];
    gFieldEffect.sin_pitch = gSinTableF32[(s32)b & 0xFF];
    x = gFieldEffect.cos_pitch * gFieldEffect.cos_yaw;
    y = gFieldEffect.cos_pitch * gFieldEffect.sin_yaw;
    z = gFieldEffect.sin_pitch;
    len = compute_sqrt_scaled(x * x + y * y + z * z);
    if (len == 0.0f)
        len = 1.0f;
    x = Div(x, len);
    y = Div(y, len);
    z = Div(z, len);
    gFieldEffect.camera_x = c * x;
    gFieldEffect.camera_y = c * y;
    gFieldEffect.camera_z = c * z;
}

static void field_effect_project_object(float *x, float *y, float *z) {
    float a, b, c;
    s32 i;

    a = x[0];
    b = y[0];
    c = z[0];
    field_effect_project_origin(a, b, c);
    for (i = 1; i < gFieldEffect.part_count; i++) {
        a = x[i];
        b = y[i];
        c = z[i];
        gFieldEffectEntities[gFieldEffect.cur_entity].unk20C = i;
        field_effect_project_sprite(a, b, c);
    }
    a = x[0];
    b = y[0];
    c = z[0];
    gFieldEffectEntities[gFieldEffect.cur_entity].unk20C = 0;
    field_effect_project_sprite(a, b, c);
}

static void field_effect_project_origin(float a, float b, float c) {
    float x, y, z;

    compute_3d_transform_vectors(a, b, c, &x, &y, &z);
    field_effect_view_to_screen_origin(x, y);
}

static void field_effect_view_to_screen_origin(float a, float b) {
    get_state_float_as_int(a, b, &gFieldEffect.screen_x, &gFieldEffect.screen_y);
}

static void field_effect_project_sprite(float x, float y, float z) {
    float sx, sy, depth;
    struct SpriteEntry *sprites;

    compute_3d_transform_vectors(x, y, z, &sx, &sy, &depth);
    field_effect_place_sprite(sx, sy);
    sprites = gSpriteEntries;
    sprites[gFieldEffectEntities[gFieldEffect.cur_entity].unk2DC[gFieldEffectEntities[gFieldEffect.cur_entity].unk20C]]
        .unk14_8 = depth;
}

static void compute_3d_transform_vectors(float x, float y, float z, float *outX, float *outY, float *outZ) {
    float rx, ry, rz, d;

    rx = x * gFieldEffect.cos_yaw + y * gFieldEffect.sin_yaw;
    ry = -x * gFieldEffect.sin_yaw + y * gFieldEffect.cos_yaw;
    rz = z * gFieldEffect.cos_pitch - rx * gFieldEffect.sin_pitch;
    d = gFieldEffect.camera_dist - (rx * gFieldEffect.cos_pitch + z * gFieldEffect.sin_pitch);
    if (d == 0.0f)
        d = 1.0f;
    rx = gFieldEffect.projection_scale / d;
    *outX = ry * rx;
    *outY = rz * rx;
    *outZ = d;
}

static void get_state_float_as_int(float a, float b, s32 *x, s32 *y) {
    *x = (s32)gFieldEffect.scale_x * (s32)a + (s32)gFieldEffect.offset_x + gFieldEffect.viewport_cx;
    *y = gFieldEffect.viewport_cy - ((s32)gFieldEffect.scale_y * (s32)b + (s32)gFieldEffect.offset_y);
}

#define CUR_ENTITY gFieldEffectEntities[gFieldEffect.cur_entity]

static void field_effect_place_sprite(float a, float b) {
    get_state_float_as_int(a, b, &gFieldEffect.screen_x, &gFieldEffect.screen_y);
    gSpriteEntries[CUR_ENTITY.unk2DC[CUR_ENTITY.unk20C]].unk2 =
        gFieldEffect.screen_x + CUR_ENTITY.unk2E0[CUR_ENTITY.unk20C];
    gSpriteEntries[CUR_ENTITY.unk2DC[CUR_ENTITY.unk20C]].unk4 =
        gFieldEffect.screen_y + CUR_ENTITY.unk2E8[CUR_ENTITY.unk20C];
    if (CUR_ENTITY.unk1EC && (u8)gFieldEffect.screen_y >= CUR_ENTITY.unk1F0 &&
        (u8)gFieldEffect.screen_y <= CUR_ENTITY.unk1F4) {
        CUR_ENTITY.unk0 = 2;
        CUR_ENTITY.unkAC = 0;
    }
    if (CUR_ENTITY.unk1E0 && (s32)(gFieldEffect.screen_x & 0x1FF) >= CUR_ENTITY.unk1E4 &&
        (s32)(gFieldEffect.screen_x & 0x1FF) <= CUR_ENTITY.unk1E8) {
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
    gFieldEffect.viewport_w = 240;
    gFieldEffect.viewport_h = 160;
    gFieldEffect.viewport_cx = x + 120;
    gFieldEffect.viewport_cy = y + 80;
    affine_set_destination_and_compute_transform(-120.5f, 120.5f, -80.5f, 80.5f);
    affine_set_source_and_compute_transform(-120.5f, 120.5f, -80.5f, 80.5f);
}

void field_effect_project_objects(void) {
    s32 i, j;
    const s32 *p;
    const s32 *q;

    gFieldEffect.viewport_w = 240;
    gFieldEffect.viewport_h = 160;
    affine_set_destination_and_compute_transform(-120.5f, 120.5f, -80.5f, 80.5f);
    affine_set_source_and_compute_transform(-120.5f, 120.5f, -80.5f, 80.5f);
    init_affine_transform_viewport(gFieldEffect.origin[0], gFieldEffect.origin[1]);
    for (i = 0; i < 16; i++) {
        if (gFieldEffectEntities[i].unk0 == 0)
            continue;
        if (gFieldEffectEntities[i].unk4 < gFieldEffectEntities[i].unk8)
            continue;
        if (gFieldEffectEntities[i].unk1C0 == 0)
            continue;
        if (gFieldEffectEntities[i].unk1C4 < gFieldEffectEntities[i].unk1C8)
            continue;
        p = gFieldEffectModels[gFieldEffect.effect_id][i];
        q = p;
        gFieldEffect.part_count = *q++;
        for (j = 0; j < 4; j++) {
            gFieldEffect.model_x[j] = q[0];
            gFieldEffect.model_y[j] = q[4];
            gFieldEffect.model_z[j] = q[8];
            q++;
        }
        set_state_float_field(gFieldEffect.base_yaw + gFieldEffectEntities[i].unkF8,
                              gFieldEffect.base_pitch + gFieldEffectEntities[i].unk110, gFieldEffect.base_camera_dist,
                              gFieldEffect.projection_scale);
        for (j = 0; j < 4; j++) {
            gFieldEffect.point_x[j] =
                gFieldEffect.model_x[j] * gFieldEffectEntities[i].unk164 + gFieldEffectEntities[i].unk10;
            gFieldEffect.point_y[j] =
                gFieldEffect.model_y[j] * gFieldEffectEntities[i].unk17C + gFieldEffectEntities[i].unk58;
            gFieldEffect.point_z[j] =
                gFieldEffect.model_z[j] * gFieldEffectEntities[i].unk194 + gFieldEffectEntities[i].unkA0;
        }
        gFieldEffect.unk98 = p[1];
        gFieldEffect.cur_entity = i;
        compute_distance_to_state_position(gFieldEffect.point_x, gFieldEffect.point_y, gFieldEffect.point_z);
    }
}

#define S (*(struct SeqState *)&gFieldEffect)
#define E ((struct SeqEntity *)gFieldEffectEntities)

// Field effect script interpreter. Runs the script picked by flags & 0x3F until an opcode
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

    S.running = 1;
    S.effect_id = S.flags & 0x3F;
    script = gFieldEffectScripts[S.effect_id];
    while (1) {
        switch (S.opcode = script[S.pc]) {
        case 0: // guess: end of script (return 0); 4 = finish (reset, rebuild the field), 37 = nop
        case 4:
        case 37:
            break;
        case 1: // guess: init: camera distance/scale, yaw/pitch, reset entity scales
            S.pc++;
            S.base_camera_dist = script[S.pc++];
            S.projection_scale = script[S.pc++];
            S.base_yaw = script[S.pc++];
            S.base_pitch = script[S.pc++];
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
                                S.cur_entity = E[i].unk25C[k];
                                E[S.cur_entity].unk10.unk0 = E[i].unk10.unk0;
                                E[S.cur_entity].unk58.unk0 = E[i].unk58.unk0;
                                E[S.cur_entity].unkA0.unk0 = E[i].unkA0.unk0;
                                S.saved_script[S.call_depth] = script;
                                script = E[i].unk29C[k];
                                S.saved_pc[S.call_depth] = S.pc;
                                S.call_depth++;
                                S.pc = 0;
                                S.opcode = script[0];
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
                        if (d > S.base_camera_dist) {
                            gAffineParams[i * 4 + k].scaleX = 0x101 - d / S.base_camera_dist;
                            gAffineParams[i * 4 + k].scaleY =
                                0x101 - gSpriteEntries[E[i].unk2DC[k]].unk14_8 / S.base_camera_dist;
                        } else {
                            gAffineParams[i * 4 + k].scaleX = S.base_camera_dist / d + 0xFF;
                            gAffineParams[i * 4 + k].scaleY =
                                S.base_camera_dist / gSpriteEntries[E[i].unk2DC[k]].unk14_8 + 0xFF;
                        }
                    }
                }
            }
            field_effect_update_sprite_depth();
            if (S.fade_mode != 0) {
                if (S.unk200 <= S.fade_timer) {
                    S.fade_timer++;
                    switch (S.fade_mode) {
                    case 1:
                        if (run_blend_fade_transition(0x7FFF)) {
                            S.fade_mode = 0;
                            done++;
                        }
                        break;
                    case 2:
                        if (run_blend_fade_transition(0x7FFF)) {
                            S.fade_mode = 0;
                            done++;
                        }
                        break;
                    case 3:
                        blend_effect_update();
                        field_bg_palettes_blend_masked(S.unk210 << 10 | S.unk20F << 5 | S.unk20E, S.unk208 * S.unk1F8,
                                                       S.bg_blend_mask);
                        field_obj_palettes_blend_masked(S.unk210 << 10 | S.unk20F << 5 | S.unk20E, S.unk208 * S.unk1F8,
                                                        S.obj_blend_mask);
                        if (S.unk208 < 0x20 / S.unk1F8)
                            S.unk208++;
                        else {
                            gVBlankCallback = empty_callback;
                            S.fade_mode = 0;
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
                        field_bg_palettes_blend_masked(color, S.unk208 * S.unk1F8, S.bg_blend_mask);
                        field_obj_palettes_blend_masked(color, S.unk208 * S.unk1F8, S.obj_blend_mask);
                        if (S.unk208 != 0)
                            S.unk208--;
                        else {
                            gVBlankCallback = empty_callback;
                            S.fade_mode = 0;
                            done++;
                        }
                        break;
                    }
                    if (S.unk204 != 0xFFFF && S.fade_timer >= S.unk204) {
                        gVBlankCallback = empty_callback;
                        S.fade_mode = 0;
                        done++;
                    }
                } else
                    S.fade_timer++;
            }
            if (done == 0)
                break;
            if (S.fade_mode != 0)
                break;
            S.pc++;
            S.opcode = script[S.pc];
            break;
        case 3: // guess: set current entity state/timer/start/end
            S.pc++;
            S.pc++;
            n = S.cur_entity;
            E[n].unk0 = script[S.pc++];
            E[n].unk4 = script[S.pc++];
            E[n].unk8 = script[S.pc++];
            E[n].unkC = script[S.pc++];
            break;
        case 5: // guess: skip one argument
            S.pc++;
            S.pc++;
            break;
        case 6: // guess: set x (absolute or relative to the parent entity)
            S.pc++;
            S.pc++;
            n = S.cur_entity;
            if (script[S.pc++] == 0)
                E[n].unk10.unk0 = script[S.pc++];
            else
                E[n].unk10.unk0 = script[S.pc++] + E[E[n].unk214].unk10.unk0;
            break;
        case 7: // guess: set y (absolute or relative to the parent entity)
            S.pc++;
            S.pc++;
            n = S.cur_entity;
            if (script[S.pc++] == 0)
                E[n].unk58.unk0 = script[S.pc++];
            else
                E[n].unk58.unk0 = script[S.pc++] + E[E[n].unk214].unk58.unk0;
            break;
        case 8: // guess: set z (absolute or relative to the parent entity)
            S.pc++;
            S.pc++;
            n = S.cur_entity;
            if (script[S.pc++] == 0)
                E[n].unkA0.unk0 = script[S.pc++];
            else
                E[n].unkA0.unk0 = script[S.pc++] + E[E[n].unk214].unkA0.unk0;
            break;
        case 9: // guess: set yaw
            S.pc++;
            S.pc++;
            n = S.cur_entity;
            E[n].unkE8.value = script[S.pc++];
            break;
        case 10: // guess: set pitch
            S.pc++;
            S.pc++;
            n = S.cur_entity;
            E[n].unk100.value = script[S.pc++];
            break;
        case 11: // guess: set affine x-scale oscillator type/value
            S.pc++;
            S.pc++;
            n = S.cur_entity;
            E[n].unk118.type = script[S.pc++];
            E[n].unk118.value = script[S.pc++];
            if (E[n].unk118.type == 0)
                break;
            for (k = 0; k < 4; k++)
                gAffineParams[n * 4 + k].scaleX = E[n].unk118.value;
            break;
        case 12: // guess: set affine y-scale oscillator type/value
            S.pc++;
            S.pc++;
            n = S.cur_entity;
            E[n].unk13C.type = script[S.pc++];
            E[n].unk13C.value = script[S.pc++];
            if (E[n].unk13C.type == 0)
                break;
            for (k = 0; k < 4; k++)
                gAffineParams[n * 4 + k].scaleY = E[n].unk13C.value;
            break;
        case 13: // guess: set 3-D scale x
            S.pc++;
            S.pc++;
            n = S.cur_entity;
            E[n].unk160.value = script[S.pc++];
            break;
        case 14: // guess: set 3-D scale y
            S.pc++;
            S.pc++;
            n = S.cur_entity;
            E[n].unk178.value = script[S.pc++];
            break;
        case 15: // guess: set 3-D scale z
            S.pc++;
            S.pc++;
            n = S.cur_entity;
            E[n].unk190.value = script[S.pc++];
            break;
        case 16: // guess: set up x/y/z interpolation (16 words)
        case 17:
        case 18:
            S.pc++;
            S.pc++;
            n = S.cur_entity;
            if (S.opcode == 0x10)
                anim = &E[n].unk10;
            else if (S.opcode == 0x11)
                anim = &E[n].unk58;
            else if (S.opcode == 0x12)
                anim = &E[n].unkA0;
            memcpy_u8(&script[S.pc], buf, 0x40);
            S.pc += 0x10;
            anim_interp_init(anim, buf);
            break;
        case 23: // guess: 3-D scale x ramp
            S.pc++;
            S.pc++;
            n = S.cur_entity;
            E[n].unk160.active = script[S.pc++];
            E[n].unk160.step = script[S.pc++] / 10.0f;
            E[n].unk160.timer = script[S.pc++];
            E[n].unk160.start = script[S.pc++];
            E[n].unk160.end = script[S.pc++];
            break;
        case 24: // guess: 3-D scale y ramp
            S.pc++;
            S.pc++;
            n = S.cur_entity;
            E[n].unk178.active = script[S.pc++];
            E[n].unk178.step = script[S.pc++] / 10.0f;
            E[n].unk178.timer = script[S.pc++];
            E[n].unk178.start = script[S.pc++];
            E[n].unk178.end = script[S.pc++];
            break;
        case 25: // guess: 3-D scale z ramp
            S.pc++;
            S.pc++;
            n = S.cur_entity;
            E[n].unk190.active = script[S.pc++];
            E[n].unk190.step = script[S.pc++] / 10.0f;
            E[n].unk190.timer = script[S.pc++];
            E[n].unk190.start = script[S.pc++];
            E[n].unk190.end = script[S.pc++];
            break;
        case 19: // guess: yaw track
            S.pc++;
            S.pc++;
            n = S.cur_entity;
            E[n].unkE8.active = script[S.pc++];
            E[n].unkE8.step = script[S.pc++] * 0.125f;
            E[n].unkE8.timer = script[S.pc++];
            E[n].unkE8.start = script[S.pc++];
            E[n].unkE8.end = script[S.pc++];
            break;
        case 20: // guess: pitch track
            S.pc++;
            S.pc++;
            n = S.cur_entity;
            E[n].unk100.active = script[S.pc++];
            E[n].unk100.step = script[S.pc++] * 0.125f;
            E[n].unk100.timer = script[S.pc++];
            E[n].unk100.start = script[S.pc++];
            E[n].unk100.end = script[S.pc++];
            break;
        case 21: // guess: affine x-scale oscillator
            S.pc++;
            S.pc++;
            n = S.cur_entity;
            E[n].unk118.type = script[S.pc++];
            E[n].unk118.amp = script[S.pc++] * 0.125f;
            E[n].unk118.angle = script[S.pc++];
            E[n].unk118.angleStep = script[S.pc++];
            E[n].unk118.timer = script[S.pc++];
            E[n].unk118.start = script[S.pc++];
            E[n].unk118.end = script[S.pc++];
            break;
        case 22: // guess: affine y-scale oscillator
            S.pc++;
            S.pc++;
            n = S.cur_entity;
            E[n].unk13C.type = script[S.pc++];
            E[n].unk13C.amp = script[S.pc++] * 0.125f;
            E[n].unk13C.angle = script[S.pc++];
            E[n].unk13C.angleStep = script[S.pc++];
            E[n].unk13C.timer = script[S.pc++];
            E[n].unk13C.start = script[S.pc++];
            E[n].unk13C.end = script[S.pc++];
            break;
        case 26: // guess: affine angle ramp
            S.pc++;
            S.pc++;
            n = S.cur_entity;
            E[n].unk1A8.active = script[S.pc++];
            E[n].unk1A8.step = script[S.pc++] * 0.125f;
            E[n].unk1A8.timer = script[S.pc++];
            E[n].unk1A8.start = script[S.pc++];
            E[n].unk1A8.end = script[S.pc++];
            break;
        case 27: // guess: create a sprite part (gfx + palette from the script set)
            S.pc++;
            S.pc++;
            n = S.cur_entity;
            part = script[S.pc++];
            x = script[S.pc++];
            y = script[S.pc++];
            attr = script[S.pc++];
            model = gFieldEffectModels[S.effect_id][n];
            E[n].unk210 = *model;
            if (part >= *model)
                break;
            E[n].unk2DC[part] = n * 4 + part;
            E[n].unk2E0[part] = 0;
            E[n].unk2E8[part] = 0;
            LZ77UnCompVram(gFieldEffectObjTiles[S.effect_id], (void *)0x06016C00);
            if (!(S.flags & 0x80))
                DmaSet(3, gFieldEffectObjPalettes[S.effect_id], 0x050003A0,
                       0x84000008) else DmaSet(3, gFieldEffectObjPalettes[S.effect_id], 0x0202F9A0, 0x84000008)
                    sprite_entry_init(E[n].unk2DC[part], x, (u16)y, 0xD, 1);
            gSpriteEntries[E[n].unk2DC[part]].unk0 |= attr;
            gSpriteEntries[E[n].unk2DC[part]].filler1D[0] = n * 4 + part;
            break;
        case 134: // guess: set a sprite part (slot, offsets, attributes)
            S.pc++;
            S.pc++;
            n = S.cur_entity;
            part = script[S.pc++];
            E[n].unk2DC[part] = script[S.pc++];
            E[n].unk2E0[part] = script[S.pc++];
            E[n].unk2E8[part] = script[S.pc++];
            gSpriteEntries[E[n].unk2DC[part]].unk0 = script[S.pc++];
            gSpriteEntries[E[n].unk2DC[part]].filler1D[0] = n * 4 + part;
            break;
        case 28: // guess: hide timer, then free the sprites
            S.pc++;
            S.pc++;
            n = S.cur_entity;
            E[n].unk1C0.active = script[S.pc++];
            E[n].unk1C0.timer = script[S.pc++];
            E[n].unk1C0.start = script[S.pc++];
            E[n].unk1C0.end = script[S.pc++];
            break;
        case 29: // guess: animate sprites flag + palette
            S.pc++;
            S.pc++;
            n = S.cur_entity;
            E[n].unk208 = script[S.pc++];
            E[n].unk204 = script[S.pc++];
            for (k = 0; k < 4; k++)
                sprite_anim_start(E[n].unk2DC[k], E[n].unk204);
            break;
        case 30: // guess: blink timer
            S.pc++;
            S.pc++;
            n = S.cur_entity;
            E[n].unk1D0.active = script[S.pc++];
            E[n].unk1D0.timer = script[S.pc++];
            E[n].unk1D0.start = script[S.pc++];
            E[n].unk1D0.end = script[S.pc++];
            break;
        case 31: // guess: x range check
            S.pc++;
            S.pc++;
            n = S.cur_entity;
            E[n].unk1E0 = script[S.pc++];
            E[n].unk1E4 = script[S.pc++];
            E[n].unk1E8 = script[S.pc++];
            break;
        case 32: // guess: y range check
            S.pc++;
            S.pc++;
            n = S.cur_entity;
            E[n].unk1EC = script[S.pc++];
            E[n].unk1F0 = script[S.pc++];
            E[n].unk1F4 = script[S.pc++];
            break;
        case 33: // guess: depth range check
            S.pc++;
            S.pc++;
            n = S.cur_entity;
            E[n].unk1F8 = script[S.pc++];
            E[n].unk1FC = script[S.pc++];
            E[n].unk200 = script[S.pc++];
            break;
        case 34: // guess: call: select entity, run a sub-script
            S.pc++;
            S.saved_entity[S.call_depth] = script[S.pc++];
            S.cur_entity = S.saved_entity[S.call_depth];
            S.saved_script[S.call_depth] = script;
            script = (s32 *)script[S.pc++];
            S.saved_pc[S.call_depth] = S.pc;
            S.call_depth++;
            S.pc = 0;
            break;
        case 35: // guess: return from a sub-script
            S.pc++;
            S.call_depth--;
            S.pc = S.saved_pc[S.call_depth];
            script = S.saved_script[S.call_depth];
            S.cur_entity = S.saved_entity[S.call_depth];
            break;
        case 36: // guess: add a trigger: run a sub-script on another entity at a given time
        {
            s32 old;

            S.pc++;
            S.saved_entity[S.call_depth] = script[S.pc++];
            k = S.saved_entity[S.call_depth];
            E[S.cur_entity].unk25C[k] = k;
            v = script[S.pc++];
            E[S.cur_entity].unk218 = v & 0xFF;
            E[S.cur_entity].unk21C[k] = script[S.pc++];
            E[S.cur_entity].unk29C[k] = (s32 *)script[S.pc++];
            E[k].unk214 = S.cur_entity;
            if ((v & 0xFF00) != 0x100)
                break;
            a = script[S.pc++];
            b = script[S.pc++];
            if (a != 1)
                break;
            old = E[S.cur_entity].unk21C[k];
            if (b == 0)
                tmp = E[S.cur_entity].unkA0.unk24;
            E[S.cur_entity].unk21C[k] = tmp - old;
            break;
        }
        case 128: // guess: fade from white (with OBJ)
            S.pc++;
            S.fade_timer = script[S.pc++];
            S.unk200 = script[S.pc++];
            S.unk204 = script[S.pc++];
            setup_palette_fade_to_color_with_obj(0x7FFF, 0.0f, 32.0f, 8.0f);
            S.fade_mode = 1;
            break;
        case 129: // guess: fade to white
            S.pc++;
            S.fade_timer = script[S.pc++];
            S.unk200 = script[S.pc++];
            S.unk204 = script[S.pc++];
            setup_palette_fade_to_color(0x7FFF, 32.0f, 0.0f, 8.0f);
            S.fade_mode = 2;
            break;
        case 130: // guess: palette blend in
            S.pc++;
            S.unk208 = script[S.pc++];
            S.bg_blend_mask = script[S.pc++];
            S.obj_blend_mask = script[S.pc++];
            S.unk20E = script[S.pc++];
            S.unk20F = script[S.pc++];
            S.unk210 = script[S.pc++];
            S.unk1F8 = script[S.pc++];
            S.fade_timer = script[S.pc++];
            S.unk200 = script[S.pc++];
            S.unk204 = script[S.pc++];
            S.fade_mode = 3;
            field_palette_backup();
            setup_blend_effect(0x40, 0x2F00, 6, 8, 8, 8, 0xD, 0xB, 0);
            break;
        case 131: // guess: palette blend out
            S.pc++;
            S.unk208 = script[S.pc++];
            S.bg_blend_mask = script[S.pc++];
            S.obj_blend_mask = script[S.pc++];
            S.unk20E = script[S.pc++];
            S.unk20F = script[S.pc++];
            S.unk210 = script[S.pc++];
            S.unk1F8 = script[S.pc++];
            S.fade_timer = script[S.pc++];
            S.unk200 = script[S.pc++];
            S.unk204 = script[S.pc++];
            S.fade_mode = 4;
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
            S.pc++;
            save_script_sprites();
            memzero_bytes((u8 *)gSpriteEntries, 0x2000);
            memzero_bytes((u8 *)gEntityStates, 0x200);
            zero = 0;
            DmaSet(3, &zero, OAM, 0x85000100);
            restore_script_sprites();
            if (S.effect_id == 0x12) {
                if (gFieldSceneParams.town_map_place <= 8)
                    S.area_id = gTownMapWarpAreas[gFieldSceneParams.town_map_place];
                else
                    S.area_id = 0;
                S.pos_x = gTownMapWarpPositions[gFieldSceneParams.town_map_place * 4 + 2] << 4;
                S.pos_y = gTownMapWarpPositions[gFieldSceneParams.town_map_place * 4 + 3] << 4;
                gFieldWork.player_x = S.pos_x;
                gFieldWork.player_y = S.pos_y;
                gFieldWork.player_tile_x = field_pixel_x_to_tile(gFieldWork.player_x);
                gFieldWork.player_tile_y = field_pixel_y_to_tile(gFieldWork.player_y);
                gFieldWork.area_id = S.area_id;
                field_center_camera_on_player();
                field_update_music(0xC, 0);
            } else if (S.effect_id == 0xE) {
                S.area_id = gUnk_083D2AD8;
                S.pos_x = gUnk_083D2AD9[2] << 4;
                S.pos_y = gUnk_083D2AD9[3] << 4;
                gFieldWork.player_x = S.pos_x;
                gFieldWork.player_y = S.pos_y;
                gFieldWork.player_tile_x = field_pixel_x_to_tile(gFieldWork.player_x);
                gFieldWork.player_tile_y = field_pixel_y_to_tile(gFieldWork.player_y);
                gFieldWork.area_id = S.area_id;
                field_center_camera_on_player();
                field_update_music(0xA, 0);
            }
            gFieldWork.npc_load_mode = 1;
            area_load_graphics();
            area_load_encounter_rate();
            gSpriteEntries[89].unk0 &= ~0x4000;
            break;
        case 133: // guess: set unk214..unk220
            S.pc++;
            S.unk214 = script[S.pc++];
            S.unk218 = script[S.pc++];
            S.unk21C = script[S.pc++];
            S.unk220 = script[S.pc++];
            break;
        case 135: // guess: set unk224..unk23C
            S.pc++;
            S.unk224 = script[S.pc++];
            S.unk228 = script[S.pc++];
            S.unk22C = script[S.pc++];
            S.unk230 = script[S.pc++];
            S.unk234 = script[S.pc++];
            S.unk238 = script[S.pc++];
            S.unk23C = script[S.pc++];
            break;
        case 137: // guess: copy z / end frames between entities
        {
            s32 src, dst;

            S.pc++;
            src = script[S.pc++];
            dst = script[S.pc++];
            switch (script[S.pc++]) {
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
            S.pc++;
            S.pc++;
            n = S.cur_entity;
            E[n].unk2EC.active = script[S.pc++];
            E[n].unk2EC.timer = script[S.pc++];
            E[n].unk2EC.start = script[S.pc++];
            E[n].unk2EC.end = script[S.pc++];
            E[n].unk2FC = script[S.pc++];
            break;
        case 136: // guess: set gFieldWork.unkC4C and refresh the status chars
            S.pc++;
            gFieldWork.unkC4C = script[S.pc++];
            update_battle_entity_status_chars();
            break;
        default:
            S.opcode = 0;
            S.pc = 0;
            break;
        }
        if (S.opcode == 0)
            break;
        if (S.opcode == 1)
            break;
        if (S.opcode == 2)
            break;
        if (S.opcode == 4) {
            S.pc = 0;
            S.running = 0;
            if ((S.flags & 0x3F) != 0xD && (S.flags & 0x3F) != 0x16) {
                s32 q;

                affine_params_reset();
                for (q = 0; q < 32; q++)
                    calculate_oam_affine_matrix(q);
            }
            if (S.effect_id == 0xE || S.effect_id == 0x12) {
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
            if (S.opcode == 4)
                break;
        }
    }
    return S.opcode;
}

#include "keys.h"

static void field_effect_update_sprite_depth(void) {
    struct FieldEffectState *b = &gFieldEffect;
    s32 i, j;
    s32 d;
    struct SpriteEntry *s;

    if (b->unkF0 != 0) {
        for (i = 0; i <= 15; i++) {
            for (j = 0; j <= 3; j++) {
                struct SpriteEntry *spr = gSpriteEntries;

                s = &spr[gFieldEffectEntities[i].unk2DC[j]];
                d = s->unk14_8;
                if (d > gFieldEffect.base_camera_dist) {
                    s->unkB = gFieldEffect.unk218;
                    gSpriteEntries[gFieldEffectEntities[i].unk2DC[j]].unk0 &= 0xF3FF;
                    gSpriteEntries[gFieldEffectEntities[i].unk2DC[j]].unk0 |= gFieldEffect.unk220;
                } else {
                    s->unkB = gFieldEffect.unk214 + (gFieldEffect.base_camera_dist - d);
                    gSpriteEntries[gFieldEffectEntities[i].unk2DC[j]].unk0 &= 0xF3FF;
                    gSpriteEntries[gFieldEffectEntities[i].unk2DC[j]].unk0 |= gFieldEffect.unk21C;
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
