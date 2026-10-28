// Field effects ("MAP_EFFECT" on the debug screen): small 3-D sprite scenes played inside the field,
// e.g. the map warp (0x12) and teleport (0xE) effects of field/field_update. field_effect_start picks an
// effect (flags & 0x3F; 0x40 = at the player) and resets the state in gFieldEffect; field_effect_run runs
// its script one frame at a time (4 = finished) over the float camera / projection helpers and the
// interpolated tracks at the end of the file. Started by field/field_update, field/map_script and
// field/field_walk.
#include "global.h"

static void compute_plane_from_points(float *x, float *y, float *z, float *normal_x, float *normal_y, float *normal_z,
                                      float *plane_dist);
static void get_state_position_xyz(float *x, float *y, float *z);
static void field_effect_init_viewport(void);
static void field_effect_init_viewport_centered(void);
static void affine_set_destination_and_compute_transform(float x_min, float x_max, float y_min, float y_max);
static void affine_set_source_and_compute_transform(float x_min, float x_max, float y_min, float y_max);
static void field_effect_project_object(float *x, float *y, float *z);
static void field_effect_project_origin(float x, float y, float z);
static void field_effect_view_to_screen_origin(float view_x, float view_y);
static void field_effect_project_sprite(float x, float y, float z);
static void compute_3d_transform_vectors(float x, float y, float z, float *outX, float *outY, float *outZ);
static void get_state_float_as_int(float view_x, float view_y, s32 *x, s32 *y);
static void field_effect_place_sprite(float view_x, float view_y);
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

void field_effect_start(u32 flags, u32 x, u32 y, u32 area_id) {
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
    gFieldEffect.area_id = area_id;
}

void field_effect_reset_view(void) {
    field_effect_init_viewport();
    gFieldEffect.origin[0] = gFieldEffect.pos_x - gBg1Scroll.x - 0x70;
    gFieldEffect.origin[1] = gFieldEffect.pos_y - gBg1Scroll.y - 0x50;
    memzero_bytes((u8 *)gFieldEffectEntities, 0x3000);
}

static void compute_distance_to_state_position(float *xs, float *ys, float *zs) {
    float normal_x, normal_y, normal_z, plane_dist;
    float px, py, pz;
    float x, y, z;
    float dx, dy, dz;
    float dist;

    compute_plane_from_points(xs, ys, zs, &normal_x, &normal_y, &normal_z, &plane_dist);
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
// Outputs the plane through them: normal (normal_x, normal_y, normal_z) scaled to integers, and plane_dist.
static void compute_plane_from_points(float *x, float *y, float *z, float *normal_x, float *normal_y, float *normal_z,
                                      float *plane_dist) {
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
    *normal_x = nx;
    *normal_y = ny;
    *normal_z = nz;
    *plane_dist = -(nx * x[0] + ny * y[0] + nz * z[0]);
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

static void affine_set_destination_and_compute_transform(float x_min, float x_max, float y_min, float y_max) {
    gFieldEffect.dst_x0 = x_min;
    gFieldEffect.dst_x1 = x_max;
    gFieldEffect.dst_y0 = y_min;
    gFieldEffect.dst_y1 = y_max;
    gFieldEffect.scale_x = (gFieldEffect.src_x1 - gFieldEffect.src_x0) / (x_max - x_min);
    gFieldEffect.scale_y = (gFieldEffect.src_y1 - gFieldEffect.src_y0) / (y_max - y_min);
    gFieldEffect.offset_x = (x_max * gFieldEffect.src_x0 - x_min * gFieldEffect.src_x1) / (x_max - x_min);
    gFieldEffect.offset_y = (y_max * gFieldEffect.src_y0 - y_min * gFieldEffect.src_y1) / (y_max - y_min);
}

static void affine_set_source_and_compute_transform(float x_min, float x_max, float y_min, float y_max) {
    gFieldEffect.src_x0 = x_min;
    gFieldEffect.src_x1 = x_max;
    gFieldEffect.src_y0 = y_min;
    gFieldEffect.src_y1 = y_max;
    gFieldEffect.scale_x = (x_max - x_min) / (gFieldEffect.dst_x1 - gFieldEffect.dst_x0);
    gFieldEffect.scale_y = (y_max - y_min) / (gFieldEffect.dst_y1 - gFieldEffect.dst_y0);
    gFieldEffect.offset_x =
        (gFieldEffect.dst_x1 * x_min - gFieldEffect.dst_x0 * x_max) / (gFieldEffect.dst_x1 - gFieldEffect.dst_x0);
    gFieldEffect.offset_y =
        (gFieldEffect.dst_y1 * y_min - gFieldEffect.dst_y0 * y_max) / (gFieldEffect.dst_y1 - gFieldEffect.dst_y0);
}

void set_state_float_field(float yaw, float pitch, float dist, float scale) {
    float x, y, z, len;

    gFieldEffect.camera_dist = dist;
    gFieldEffect.projection_scale = scale;
    gFieldEffect.cos_yaw = gCosTableF32[(s32)yaw & 0xFF];
    gFieldEffect.sin_yaw = gSinTableF32[(s32)yaw & 0xFF];
    gFieldEffect.cos_pitch = gCosTableF32[(s32)pitch & 0xFF];
    gFieldEffect.sin_pitch = gSinTableF32[(s32)pitch & 0xFF];
    x = gFieldEffect.cos_pitch * gFieldEffect.cos_yaw;
    y = gFieldEffect.cos_pitch * gFieldEffect.sin_yaw;
    z = gFieldEffect.sin_pitch;
    len = compute_sqrt_scaled(x * x + y * y + z * z);
    if (len == 0.0f)
        len = 1.0f;
    x = Div(x, len);
    y = Div(y, len);
    z = Div(z, len);
    gFieldEffect.camera_x = dist * x;
    gFieldEffect.camera_y = dist * y;
    gFieldEffect.camera_z = dist * z;
}

static void field_effect_project_object(float *x, float *y, float *z) {
    float px, py, pz;
    s32 i;

    px = x[0];
    py = y[0];
    pz = z[0];
    field_effect_project_origin(px, py, pz);
    for (i = 1; i < gFieldEffect.part_count; i++) {
        px = x[i];
        py = y[i];
        pz = z[i];
        gFieldEffectEntities[gFieldEffect.cur_entity].cur_part = i;
        field_effect_project_sprite(px, py, pz);
    }
    px = x[0];
    py = y[0];
    pz = z[0];
    gFieldEffectEntities[gFieldEffect.cur_entity].cur_part = 0;
    field_effect_project_sprite(px, py, pz);
}

static void field_effect_project_origin(float px, float py, float pz) {
    float x, y, z;

    compute_3d_transform_vectors(px, py, pz, &x, &y, &z);
    field_effect_view_to_screen_origin(x, y);
}

static void field_effect_view_to_screen_origin(float view_x, float view_y) {
    get_state_float_as_int(view_x, view_y, &gFieldEffect.screen_x, &gFieldEffect.screen_y);
}

static void field_effect_project_sprite(float x, float y, float z) {
    float sx, sy, depth;
    struct SpriteEntry *sprites;

    compute_3d_transform_vectors(x, y, z, &sx, &sy, &depth);
    field_effect_place_sprite(sx, sy);
    sprites = gSpriteEntries;
    sprites[gFieldEffectEntities[gFieldEffect.cur_entity]
                .part_sprite[gFieldEffectEntities[gFieldEffect.cur_entity].cur_part]]
        .pos_z = depth;
}

static void compute_3d_transform_vectors(float x, float y, float z, float *outX, float *outY, float *outZ) {
    float rx, ry, rz, depth;

    rx = x * gFieldEffect.cos_yaw + y * gFieldEffect.sin_yaw;
    ry = -x * gFieldEffect.sin_yaw + y * gFieldEffect.cos_yaw;
    rz = z * gFieldEffect.cos_pitch - rx * gFieldEffect.sin_pitch;
    depth = gFieldEffect.camera_dist - (rx * gFieldEffect.cos_pitch + z * gFieldEffect.sin_pitch);
    if (depth == 0.0f)
        depth = 1.0f;
    rx = gFieldEffect.projection_scale / depth;
    *outX = ry * rx;
    *outY = rz * rx;
    *outZ = depth;
}

static void get_state_float_as_int(float view_x, float view_y, s32 *x, s32 *y) {
    *x = (s32)gFieldEffect.scale_x * (s32)view_x + (s32)gFieldEffect.offset_x + gFieldEffect.viewport_cx;
    *y = gFieldEffect.viewport_cy - ((s32)gFieldEffect.scale_y * (s32)view_y + (s32)gFieldEffect.offset_y);
}

#define CUR_ENTITY gFieldEffectEntities[gFieldEffect.cur_entity]

static void field_effect_place_sprite(float view_x, float view_y) {
    get_state_float_as_int(view_x, view_y, &gFieldEffect.screen_x, &gFieldEffect.screen_y);
    gSpriteEntries[CUR_ENTITY.part_sprite[CUR_ENTITY.cur_part]].x =
        gFieldEffect.screen_x + CUR_ENTITY.part_x[CUR_ENTITY.cur_part];
    gSpriteEntries[CUR_ENTITY.part_sprite[CUR_ENTITY.cur_part]].y =
        gFieldEffect.screen_y + CUR_ENTITY.part_y[CUR_ENTITY.cur_part];
    if (CUR_ENTITY.y_check && (u8)gFieldEffect.screen_y >= CUR_ENTITY.y_min &&
        (u8)gFieldEffect.screen_y <= CUR_ENTITY.y_max) {
        CUR_ENTITY.state = 2;
        CUR_ENTITY.z_mode = 0;
    }
    if (CUR_ENTITY.x_check && (s32)(gFieldEffect.screen_x & 0x1FF) >= CUR_ENTITY.x_min &&
        (s32)(gFieldEffect.screen_x & 0x1FF) <= CUR_ENTITY.x_max) {
        CUR_ENTITY.state = 2;
        CUR_ENTITY.y_mode = 0;
        CUR_ENTITY.x_mode = 0;
    }
    if (CUR_ENTITY.z_check) {
        if (CUR_ENTITY.z <= CUR_ENTITY.z_min) {
            CUR_ENTITY.state = 2;
            CUR_ENTITY.z_mode = 0;
        }
        if (CUR_ENTITY.z >= CUR_ENTITY.z_max) {
            CUR_ENTITY.state = 2;
            CUR_ENTITY.z_mode = 0;
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
    const s32 *model;
    const s32 *cursor;

    gFieldEffect.viewport_w = 240;
    gFieldEffect.viewport_h = 160;
    affine_set_destination_and_compute_transform(-120.5f, 120.5f, -80.5f, 80.5f);
    affine_set_source_and_compute_transform(-120.5f, 120.5f, -80.5f, 80.5f);
    init_affine_transform_viewport(gFieldEffect.origin[0], gFieldEffect.origin[1]);
    for (i = 0; i < 16; i++) {
        if (gFieldEffectEntities[i].state == 0)
            continue;
        if (gFieldEffectEntities[i].unk4 < gFieldEffectEntities[i].unk8)
            continue;
        if (gFieldEffectEntities[i].unk1C0 == 0)
            continue;
        if (gFieldEffectEntities[i].unk1C4 < gFieldEffectEntities[i].unk1C8)
            continue;
        model = gFieldEffectModels[gFieldEffect.effect_id][i];
        cursor = model;
        gFieldEffect.part_count = *cursor++;
        for (j = 0; j < 4; j++) {
            gFieldEffect.model_x[j] = cursor[0];
            gFieldEffect.model_y[j] = cursor[4];
            gFieldEffect.model_z[j] = cursor[8];
            cursor++;
        }
        set_state_float_field(gFieldEffect.base_yaw + gFieldEffectEntities[i].yaw,
                              gFieldEffect.base_pitch + gFieldEffectEntities[i].pitch, gFieldEffect.base_camera_dist,
                              gFieldEffect.projection_scale);
        for (j = 0; j < 4; j++) {
            gFieldEffect.point_x[j] =
                gFieldEffect.model_x[j] * gFieldEffectEntities[i].scale_x + gFieldEffectEntities[i].x;
            gFieldEffect.point_y[j] =
                gFieldEffect.model_y[j] * gFieldEffectEntities[i].scale_y + gFieldEffectEntities[i].y;
            gFieldEffect.point_z[j] =
                gFieldEffect.model_z[j] * gFieldEffectEntities[i].scale_z + gFieldEffectEntities[i].z;
        }
        gFieldEffect.unk98 = model[1];
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
    s32 track_end;
    struct AnimInterp *anim;
    struct SeqTrack *trk;
    struct SeqOsc *osc;
    struct SeqRamp *ramp;
    s32 j, k;
    s32 n;
    s32 flag;
    s32 part;
    s32 trigger_flags, relative_mode, relative_track;
    s32 depth;
    const s32 *model;
    u16 color;
    s32 red, green, blue;

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
            S.near_order_base = 0x80;
            S.far_order = 0;
            S.near_priority = 0x400;
            S.far_priority = 0x800;
            field_effect_reset_view();
            for (i = 0; i < 16; i++) {
                E[i].scale_x.value = 1.0f;
                E[i].scale_y.value = 1.0f;
                E[i].scale_z.value = 1.0f;
            }
            break;
        case 2: // guess: run one frame: fire entity triggers, step all tracks, fade; advance when an entity finished
            done = 0;
            flag = 0;
            cnt = 0;
            for (i = 0; i < 16; i++) {
                if (E[i].state != 0 && E[i].has_triggers != 0) {
                    for (k = 0; k < 16; k++) {
                        if (E[i].trigger_script[k] != 0) {
                            cnt++;
                            if (E[i].timer >= E[i].trigger_time[k]) {
                                S.cur_entity = E[i].trigger_entity[k];
                                E[S.cur_entity].x.value = E[i].x.value;
                                E[S.cur_entity].y.value = E[i].y.value;
                                E[S.cur_entity].z.value = E[i].z.value;
                                S.saved_script[S.call_depth] = script;
                                script = E[i].trigger_script[k];
                                S.saved_pc[S.call_depth] = S.pc;
                                S.call_depth++;
                                S.pc = 0;
                                S.opcode = script[0];
                                E[i].trigger_script[k] = 0;
                                flag = 1;
                            }
                            if (flag)
                                break;
                        }
                        if (flag)
                            break;
                    }
                    if (cnt == 0)
                        E[i].has_triggers = 0;
                }
            }
            if (flag)
                break;
            for (i = 0; i < 16; i++) {
                if (E[i].state == 0)
                    continue;
                if (E[i].start <= E[i].timer) {
                    for (k = 0; k < 3; k++) {
                        if (k == 0)
                            anim = &E[i].x;
                        else if (k == 1)
                            anim = &E[i].y;
                        else if (k == 2)
                            anim = &E[i].z;
                        animation_interpolation_step(anim);
                    }
                    for (k = 0; k < 2; k++) {
                        if (k == 0)
                            trk = &E[i].yaw;
                        else if (k == 1)
                            trk = &E[i].pitch;
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
                            osc = &E[i].affine_scale_x;
                        else if (j == 1)
                            osc = &E[i].affine_scale_y;
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
                            ramp = &E[i].scale_x;
                        else if (k == 1)
                            ramp = &E[i].scale_y;
                        else if (k == 2)
                            ramp = &E[i].scale_z;
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
                    if (E[i].affine_angle.active) {
                        if (E[i].affine_angle.start <= E[i].affine_angle.timer) {
                            E[i].affine_angle.value = E[i].affine_angle.value + E[i].affine_angle.step;
                            for (k = 0; k < 4; k++)
                                gAffineParams[i * 4 + k].angle = (s32)E[i].affine_angle.value & 0xFF;
                            E[i].affine_angle.timer++;
                            if (E[i].affine_angle.end != 0xFFFF && E[i].affine_angle.timer >= E[i].affine_angle.end)
                                E[i].affine_angle.active = 0;
                        } else
                            E[i].affine_angle.timer++;
                    }
                    if (E[i].animate) {
                        for (k = 0; k < E[i].part_count; k++)
                            advance_sprite_animation_frame(E[i].part_sprite[k]);
                    }
                    if (E[i].hide_timer.active) {
                        if (E[i].hide_timer.start <= E[i].hide_timer.timer) {
                            for (k = 0; k < E[i].part_count; k++)
                                gSpriteEntries[E[i].part_sprite[k]].flags |= SPRITE_FLAG_VISIBLE;
                            E[i].hide_timer.timer++;
                            if (E[i].hide_timer.end != 0xFFFF && E[i].hide_timer.timer >= E[i].hide_timer.end) {
                                for (k = 0; k < E[i].part_count; k++)
                                    sprite_entry_clear(E[i].part_sprite[k]);
                                E[i].hide_timer.active = 0;
                                E[i].animate = 0;
                            }
                        } else
                            E[i].hide_timer.timer++;
                    }
                    if (E[i].blink_timer.active) {
                        if (E[i].blink_timer.start <= E[i].blink_timer.timer) {
                            if (!(E[i].blink_timer.timer & 1)) {
                                for (k = 0; k < E[i].part_count; k++)
                                    gSpriteEntries[E[i].part_sprite[k]].flags &= ~SPRITE_FLAG_VISIBLE;
                            } else {
                                for (k = 0; k < E[i].part_count; k++)
                                    gSpriteEntries[E[i].part_sprite[k]].flags |= SPRITE_FLAG_VISIBLE;
                            }
                            E[i].blink_timer.timer++;
                            if (E[i].blink_timer.end != 0xFFFF && E[i].blink_timer.timer >= E[i].blink_timer.end)
                                E[i].blink_timer.active = 0;
                        } else
                            E[i].blink_timer.timer++;
                    }
                    if (E[i].sound_timer.active) {
                        if (E[i].sound_timer.start <= E[i].sound_timer.timer) {
                            field_play_sound_effect(E[i].sound_id);
                            E[i].sound_timer.timer++;
                            if (E[i].sound_timer.end != 0xFFFF && E[i].sound_timer.timer >= E[i].sound_timer.end)
                                E[i].sound_timer.active = 0;
                        } else
                            E[i].sound_timer.timer++;
                    }
                    E[i].timer++;
                    if (E[i].end != 0xFFFF && E[i].timer >= E[i].end)
                        done++;
                } else
                    E[i].timer++;
            }
            field_effect_project_objects();
            for (i = 0; i < 16; i++) {
                if (E[i].state == 2)
                    done++;
            }
            for (i = 0; i < 16; i++) {
                if (E[i].state != 0 && (E[i].affine_scale_x.type | E[i].affine_scale_y.type) == 0) {
                    for (k = 0; k < 4; k++) {
                        depth = gSpriteEntries[E[i].part_sprite[k]].pos_z;
                        if (depth > S.base_camera_dist) {
                            gAffineParams[i * 4 + k].scaleX = 0x101 - depth / S.base_camera_dist;
                            gAffineParams[i * 4 + k].scaleY =
                                0x101 - gSpriteEntries[E[i].part_sprite[k]].pos_z / S.base_camera_dist;
                        } else {
                            gAffineParams[i * 4 + k].scaleX = S.base_camera_dist / depth + 0xFF;
                            gAffineParams[i * 4 + k].scaleY =
                                S.base_camera_dist / gSpriteEntries[E[i].part_sprite[k]].pos_z + 0xFF;
                        }
                    }
                }
            }
            field_effect_update_sprite_depth();
            if (S.fade_mode != 0) {
                if (S.fade_start <= S.fade_timer) {
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
                        field_bg_palettes_blend_masked(S.blend_b << 10 | S.blend_g << 5 | S.blend_r,
                                                       S.blend_level * S.blend_step, S.bg_blend_mask);
                        field_obj_palettes_blend_masked(S.blend_b << 10 | S.blend_g << 5 | S.blend_r,
                                                        S.blend_level * S.blend_step, S.obj_blend_mask);
                        if (S.blend_level < 0x20 / S.blend_step)
                            S.blend_level++;
                        else {
                            gVBlankCallback = empty_callback;
                            S.fade_mode = 0;
                            done++;
                        }
                        break;
                    case 4:
                        blend_effect_update();
                        red = S.blend_level * S.blend_step - 1;
                        green = red;
                        blue = red;
                        if (red < S.blend_r)
                            red = S.blend_r;
                        if (green < S.blend_g)
                            green = S.blend_g;
                        if (blue < S.blend_b)
                            blue = S.blend_b;
                        color = blue << 10 | green << 5 | red;
                        field_bg_palettes_blend_masked(color, S.blend_level * S.blend_step, S.bg_blend_mask);
                        field_obj_palettes_blend_masked(color, S.blend_level * S.blend_step, S.obj_blend_mask);
                        if (S.blend_level != 0)
                            S.blend_level--;
                        else {
                            gVBlankCallback = empty_callback;
                            S.fade_mode = 0;
                            done++;
                        }
                        break;
                    }
                    if (S.fade_end != 0xFFFF && S.fade_timer >= S.fade_end) {
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
            E[n].state = script[S.pc++];
            E[n].timer = script[S.pc++];
            E[n].start = script[S.pc++];
            E[n].end = script[S.pc++];
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
                E[n].x.value = script[S.pc++];
            else
                E[n].x.value = script[S.pc++] + E[E[n].parent].x.value;
            break;
        case 7: // guess: set y (absolute or relative to the parent entity)
            S.pc++;
            S.pc++;
            n = S.cur_entity;
            if (script[S.pc++] == 0)
                E[n].y.value = script[S.pc++];
            else
                E[n].y.value = script[S.pc++] + E[E[n].parent].y.value;
            break;
        case 8: // guess: set z (absolute or relative to the parent entity)
            S.pc++;
            S.pc++;
            n = S.cur_entity;
            if (script[S.pc++] == 0)
                E[n].z.value = script[S.pc++];
            else
                E[n].z.value = script[S.pc++] + E[E[n].parent].z.value;
            break;
        case 9: // guess: set yaw
            S.pc++;
            S.pc++;
            n = S.cur_entity;
            E[n].yaw.value = script[S.pc++];
            break;
        case 10: // guess: set pitch
            S.pc++;
            S.pc++;
            n = S.cur_entity;
            E[n].pitch.value = script[S.pc++];
            break;
        case 11: // guess: set affine x-scale oscillator type/value
            S.pc++;
            S.pc++;
            n = S.cur_entity;
            E[n].affine_scale_x.type = script[S.pc++];
            E[n].affine_scale_x.value = script[S.pc++];
            if (E[n].affine_scale_x.type == 0)
                break;
            for (k = 0; k < 4; k++)
                gAffineParams[n * 4 + k].scaleX = E[n].affine_scale_x.value;
            break;
        case 12: // guess: set affine y-scale oscillator type/value
            S.pc++;
            S.pc++;
            n = S.cur_entity;
            E[n].affine_scale_y.type = script[S.pc++];
            E[n].affine_scale_y.value = script[S.pc++];
            if (E[n].affine_scale_y.type == 0)
                break;
            for (k = 0; k < 4; k++)
                gAffineParams[n * 4 + k].scaleY = E[n].affine_scale_y.value;
            break;
        case 13: // guess: set 3-D scale x
            S.pc++;
            S.pc++;
            n = S.cur_entity;
            E[n].scale_x.value = script[S.pc++];
            break;
        case 14: // guess: set 3-D scale y
            S.pc++;
            S.pc++;
            n = S.cur_entity;
            E[n].scale_y.value = script[S.pc++];
            break;
        case 15: // guess: set 3-D scale z
            S.pc++;
            S.pc++;
            n = S.cur_entity;
            E[n].scale_z.value = script[S.pc++];
            break;
        case 16: // guess: set up x/y/z interpolation (16 words)
        case 17:
        case 18:
            S.pc++;
            S.pc++;
            n = S.cur_entity;
            if (S.opcode == 0x10)
                anim = &E[n].x;
            else if (S.opcode == 0x11)
                anim = &E[n].y;
            else if (S.opcode == 0x12)
                anim = &E[n].z;
            memcpy_u8(&script[S.pc], buf, 0x40);
            S.pc += 0x10;
            anim_interp_init(anim, buf);
            break;
        case 23: // guess: 3-D scale x ramp
            S.pc++;
            S.pc++;
            n = S.cur_entity;
            E[n].scale_x.active = script[S.pc++];
            E[n].scale_x.step = script[S.pc++] / 10.0f;
            E[n].scale_x.timer = script[S.pc++];
            E[n].scale_x.start = script[S.pc++];
            E[n].scale_x.end = script[S.pc++];
            break;
        case 24: // guess: 3-D scale y ramp
            S.pc++;
            S.pc++;
            n = S.cur_entity;
            E[n].scale_y.active = script[S.pc++];
            E[n].scale_y.step = script[S.pc++] / 10.0f;
            E[n].scale_y.timer = script[S.pc++];
            E[n].scale_y.start = script[S.pc++];
            E[n].scale_y.end = script[S.pc++];
            break;
        case 25: // guess: 3-D scale z ramp
            S.pc++;
            S.pc++;
            n = S.cur_entity;
            E[n].scale_z.active = script[S.pc++];
            E[n].scale_z.step = script[S.pc++] / 10.0f;
            E[n].scale_z.timer = script[S.pc++];
            E[n].scale_z.start = script[S.pc++];
            E[n].scale_z.end = script[S.pc++];
            break;
        case 19: // guess: yaw track
            S.pc++;
            S.pc++;
            n = S.cur_entity;
            E[n].yaw.active = script[S.pc++];
            E[n].yaw.step = script[S.pc++] * 0.125f;
            E[n].yaw.timer = script[S.pc++];
            E[n].yaw.start = script[S.pc++];
            E[n].yaw.end = script[S.pc++];
            break;
        case 20: // guess: pitch track
            S.pc++;
            S.pc++;
            n = S.cur_entity;
            E[n].pitch.active = script[S.pc++];
            E[n].pitch.step = script[S.pc++] * 0.125f;
            E[n].pitch.timer = script[S.pc++];
            E[n].pitch.start = script[S.pc++];
            E[n].pitch.end = script[S.pc++];
            break;
        case 21: // guess: affine x-scale oscillator
            S.pc++;
            S.pc++;
            n = S.cur_entity;
            E[n].affine_scale_x.type = script[S.pc++];
            E[n].affine_scale_x.amp = script[S.pc++] * 0.125f;
            E[n].affine_scale_x.angle = script[S.pc++];
            E[n].affine_scale_x.angleStep = script[S.pc++];
            E[n].affine_scale_x.timer = script[S.pc++];
            E[n].affine_scale_x.start = script[S.pc++];
            E[n].affine_scale_x.end = script[S.pc++];
            break;
        case 22: // guess: affine y-scale oscillator
            S.pc++;
            S.pc++;
            n = S.cur_entity;
            E[n].affine_scale_y.type = script[S.pc++];
            E[n].affine_scale_y.amp = script[S.pc++] * 0.125f;
            E[n].affine_scale_y.angle = script[S.pc++];
            E[n].affine_scale_y.angleStep = script[S.pc++];
            E[n].affine_scale_y.timer = script[S.pc++];
            E[n].affine_scale_y.start = script[S.pc++];
            E[n].affine_scale_y.end = script[S.pc++];
            break;
        case 26: // guess: affine angle ramp
            S.pc++;
            S.pc++;
            n = S.cur_entity;
            E[n].affine_angle.active = script[S.pc++];
            E[n].affine_angle.step = script[S.pc++] * 0.125f;
            E[n].affine_angle.timer = script[S.pc++];
            E[n].affine_angle.start = script[S.pc++];
            E[n].affine_angle.end = script[S.pc++];
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
            E[n].part_count = *model;
            if (part >= *model)
                break;
            E[n].part_sprite[part] = n * 4 + part;
            E[n].part_x[part] = 0;
            E[n].part_y[part] = 0;
            LZ77UnCompVram(gFieldEffectObjTiles[S.effect_id], (void *)0x06016C00);
            if (!(S.flags & 0x80))
                DmaSet(3, gFieldEffectObjPalettes[S.effect_id], 0x050003A0,
                       0x84000008) else DmaSet(3, gFieldEffectObjPalettes[S.effect_id], 0x0202F9A0, 0x84000008)
                    sprite_entry_init(E[n].part_sprite[part], x, (u16)y, 0xD, 1);
            gSpriteEntries[E[n].part_sprite[part]].flags |= attr;
            gSpriteEntries[E[n].part_sprite[part]].affine_idx = n * 4 + part;
            break;
        case 134: // guess: set a sprite part (slot, offsets, attributes)
            S.pc++;
            S.pc++;
            n = S.cur_entity;
            part = script[S.pc++];
            E[n].part_sprite[part] = script[S.pc++];
            E[n].part_x[part] = script[S.pc++];
            E[n].part_y[part] = script[S.pc++];
            gSpriteEntries[E[n].part_sprite[part]].flags = script[S.pc++];
            gSpriteEntries[E[n].part_sprite[part]].affine_idx = n * 4 + part;
            break;
        case 28: // guess: hide timer, then free the sprites
            S.pc++;
            S.pc++;
            n = S.cur_entity;
            E[n].hide_timer.active = script[S.pc++];
            E[n].hide_timer.timer = script[S.pc++];
            E[n].hide_timer.start = script[S.pc++];
            E[n].hide_timer.end = script[S.pc++];
            break;
        case 29: // guess: animate sprites flag + palette
            S.pc++;
            S.pc++;
            n = S.cur_entity;
            E[n].animate = script[S.pc++];
            E[n].anim_id = script[S.pc++];
            for (k = 0; k < 4; k++)
                sprite_anim_start(E[n].part_sprite[k], E[n].anim_id);
            break;
        case 30: // guess: blink timer
            S.pc++;
            S.pc++;
            n = S.cur_entity;
            E[n].blink_timer.active = script[S.pc++];
            E[n].blink_timer.timer = script[S.pc++];
            E[n].blink_timer.start = script[S.pc++];
            E[n].blink_timer.end = script[S.pc++];
            break;
        case 31: // guess: x range check
            S.pc++;
            S.pc++;
            n = S.cur_entity;
            E[n].x_check = script[S.pc++];
            E[n].x_min = script[S.pc++];
            E[n].x_max = script[S.pc++];
            break;
        case 32: // guess: y range check
            S.pc++;
            S.pc++;
            n = S.cur_entity;
            E[n].y_check = script[S.pc++];
            E[n].y_min = script[S.pc++];
            E[n].y_max = script[S.pc++];
            break;
        case 33: // guess: depth range check
            S.pc++;
            S.pc++;
            n = S.cur_entity;
            E[n].z_check = script[S.pc++];
            E[n].z_min = script[S.pc++];
            E[n].z_max = script[S.pc++];
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
            E[S.cur_entity].trigger_entity[k] = k;
            trigger_flags = script[S.pc++];
            E[S.cur_entity].has_triggers = trigger_flags & 0xFF;
            E[S.cur_entity].trigger_time[k] = script[S.pc++];
            E[S.cur_entity].trigger_script[k] = (s32 *)script[S.pc++];
            E[k].parent = S.cur_entity;
            if ((trigger_flags & 0xFF00) != 0x100)
                break;
            relative_mode = script[S.pc++];
            relative_track = script[S.pc++];
            if (relative_mode != 1)
                break;
            old = E[S.cur_entity].trigger_time[k];
            if (relative_track == 0)
                track_end = E[S.cur_entity].z.end;
            E[S.cur_entity].trigger_time[k] = track_end - old;
            break;
        }
        case 128: // guess: fade from white (with OBJ)
            S.pc++;
            S.fade_timer = script[S.pc++];
            S.fade_start = script[S.pc++];
            S.fade_end = script[S.pc++];
            setup_palette_fade_to_color_with_obj(0x7FFF, 0.0f, 32.0f, 8.0f);
            S.fade_mode = 1;
            break;
        case 129: // guess: fade to white
            S.pc++;
            S.fade_timer = script[S.pc++];
            S.fade_start = script[S.pc++];
            S.fade_end = script[S.pc++];
            setup_palette_fade_to_color(0x7FFF, 32.0f, 0.0f, 8.0f);
            S.fade_mode = 2;
            break;
        case 130: // guess: palette blend in
            S.pc++;
            S.blend_level = script[S.pc++];
            S.bg_blend_mask = script[S.pc++];
            S.obj_blend_mask = script[S.pc++];
            S.blend_r = script[S.pc++];
            S.blend_g = script[S.pc++];
            S.blend_b = script[S.pc++];
            S.blend_step = script[S.pc++];
            S.fade_timer = script[S.pc++];
            S.fade_start = script[S.pc++];
            S.fade_end = script[S.pc++];
            S.fade_mode = 3;
            field_palette_backup();
            setup_blend_effect(0x40, 0x2F00, 6, 8, 8, 8, 0xD, 0xB, 0);
            break;
        case 131: // guess: palette blend out
            S.pc++;
            S.blend_level = script[S.pc++];
            S.bg_blend_mask = script[S.pc++];
            S.obj_blend_mask = script[S.pc++];
            S.blend_r = script[S.pc++];
            S.blend_g = script[S.pc++];
            S.blend_b = script[S.pc++];
            S.blend_step = script[S.pc++];
            S.fade_timer = script[S.pc++];
            S.fade_start = script[S.pc++];
            S.fade_end = script[S.pc++];
            S.fade_mode = 4;
            if (S.blend_level != 0) {
                if (S.blend_level == 0x10) {
                    field_palettes_blend_to_color(0x7FFF, 0x20);
                    gBlendEffect.fade_amount = 32.0f;
                    gBlendEffect.fade_end = 0.0f;
                    setup_blend_effect(0x40, 0x2F00, 5, 8, 8, 8, 0xE, 0xC, 0);
                } else if (S.blend_level == 8)
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
                S.area_id = gTeleportWarpArea;
                S.pos_x = gTeleportWarpPosition[2] << 4;
                S.pos_y = gTeleportWarpPosition[3] << 4;
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
            gSpriteEntries[89].flags &= ~SPRITE_FLAG_VISIBLE;
            break;
        case 133: // guess: set the depth sort orders / OBJ priorities (field_effect_update_sprite_depth)
            S.pc++;
            S.near_order_base = script[S.pc++];
            S.far_order = script[S.pc++];
            S.near_priority = script[S.pc++];
            S.far_priority = script[S.pc++];
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
                E[dst].z.value = E[src].z.value;
                break;
            case 1:
                E[dst].end = E[src].z.end;
                break;
            case 2:
                E[dst].end = E[src].y.end;
                break;
            case 3:
                E[dst].end = E[src].x.end;
                break;
            }
            break;
        }
        case 138: // guess: callback timer (field_play_sound_effect)
            S.pc++;
            S.pc++;
            n = S.cur_entity;
            E[n].sound_timer.active = script[S.pc++];
            E[n].sound_timer.timer = script[S.pc++];
            E[n].sound_timer.start = script[S.pc++];
            E[n].sound_timer.end = script[S.pc++];
            E[n].sound_id = script[S.pc++];
            break;
        case 136: // set gFieldWork.depth_sort_enabled and re-sort the sprites
            S.pc++;
            gFieldWork.depth_sort_enabled = script[S.pc++];
            field_sort_sprites_by_depth();
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
                s32 slot;

                affine_params_reset();
                for (slot = 0; slot < 32; slot++)
                    calculate_oam_affine_matrix(slot);
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
                field_sort_sprites_by_depth();
            }
            if (S.opcode == 4)
                break;
        }
    }
    return S.opcode;
}

#include "keys.h"
#include "constants/sprites.h"

static void field_effect_update_sprite_depth(void) {
    struct FieldEffectState *effect = &gFieldEffect;
    s32 i, j;
    s32 depth;
    struct SpriteEntry *sprite;

    if (effect->unkF0 != 0) {
        for (i = 0; i <= 15; i++) {
            for (j = 0; j <= 3; j++) {
                struct SpriteEntry *spr = gSpriteEntries;

                sprite = &spr[gFieldEffectEntities[i].part_sprite[j]];
                depth = sprite->pos_z;
                if (depth > gFieldEffect.base_camera_dist) {
                    sprite->order = gFieldEffect.far_order;
                    gSpriteEntries[gFieldEffectEntities[i].part_sprite[j]].flags &= (u16)~SPRITE_FLAG_PRIORITY_MASK;
                    gSpriteEntries[gFieldEffectEntities[i].part_sprite[j]].flags |= gFieldEffect.far_priority;
                } else {
                    sprite->order = gFieldEffect.near_order_base + (gFieldEffect.base_camera_dist - depth);
                    gSpriteEntries[gFieldEffectEntities[i].part_sprite[j]].flags &= (u16)~SPRITE_FLAG_PRIORITY_MASK;
                    gSpriteEntries[gFieldEffectEntities[i].part_sprite[j]].flags |= gFieldEffect.near_priority;
                }
            }
        }
    }
}

void anim_interp_init(struct AnimInterp *anim, s32 *params) {
    s32 mode;
    float x, phase;

    anim->mode = mode = params[0];
    anim->unk10 = params[1] / 256;
    anim->phase = params[2];
    anim->unk18 = params[3] * (1.0f / 256);
    anim->frame = params[4];
    anim->start = params[5];
    anim->end = params[6];
    anim->duration = params[7];
    anim->firstFrames = params[8];
    anim->secondFrames = params[9];
    anim->firstDistance = params[10];
    anim->secondDistance = params[11];
    anim->firstSpeed = params[12] * (1.0f / 256);
    anim->secondSpeed = params[13] * (1.0f / 256);
    anim->endAtStart = params[14];
    if (mode > 1)
        anim->base = anim->value;

    switch (anim->mode) {
    case 0x10:
        anim->firstFrames = x =
            anim->firstDistance / float_default_to_one_if_zero(float_abs_if_negative(anim->firstSpeed));
        anim->end = anim->start + x;
        if (anim->endAtStart != 0)
            anim->value = anim->value - float_sign(anim->firstSpeed) * float_abs_if_negative(anim->firstDistance);
        break;
    case 0x11:
        anim->end = anim->start + anim->duration;
        anim->firstDistance = anim->firstSpeed * anim->firstFrames;
        if (anim->endAtStart != 0)
            anim->value = anim->value - float_sign(anim->firstSpeed) * float_abs_if_negative(anim->firstDistance);
        break;
    case 0x12: {
        float sum;
        s32 n;

        anim->firstSpeed = anim->firstDistance * (1.0f / 64);
        phase = anim->phase;
        sum = 0.0f;
        n = 0;
        for (;;) {
            if (anim->firstSpeed == 0.0f)
                break;
            phase = phase + anim->firstSpeed;
            if (phase >= 64.0f)
                phase = 64.0f;
            sum = sum + anim->secondSpeed * (gSineTable[(s32)(phase + 192.0f) & 0xFF] + 256.0f) * (1.0f / 256);
            if (float_abs_if_negative(sum) >= anim->firstDistance)
                break;
            n++;
        }
        anim->firstFrames = n;
        anim->secondFrames = x =
            anim->secondDistance / float_default_to_one_if_zero(float_abs_if_negative(anim->secondSpeed));
        anim->end = anim->start + anim->firstFrames + x;
        anim->secondDistance = anim->secondDistance + (anim->firstDistance - float_abs_if_negative(sum));
        if (anim->endAtStart != 0)
            anim->value = anim->value - float_sign(anim->secondSpeed) * (float_abs_if_negative(anim->firstDistance) +
                                                                         float_abs_if_negative(anim->secondDistance));
        break;
    }
    case 0x13: {
        float step;

        anim->end = anim->start + anim->duration;
        anim->secondFrames = anim->duration - anim->firstFrames;
        anim->firstSpeed = step = 64.0f / float_default_to_one_if_zero(anim->firstFrames);
        anim->secondDistance = anim->secondSpeed * anim->secondFrames;
        phase = anim->phase;
        anim->firstDistance = 0.0f;
        for (;;) {
            if (step == 0.0f)
                break;
            phase = phase + step;
            anim->firstDistance = anim->firstDistance + anim->secondSpeed *
                                                            (gSineTable[(s32)(phase + 192.0f) & 0xFF] + 256.0f) *
                                                            (1.0f / 256);
            if (phase >= 64.0f)
                break;
        }
        if (anim->endAtStart != 0)
            anim->value = anim->value - float_sign(anim->secondSpeed) * (float_abs_if_negative(anim->firstDistance) +
                                                                         float_abs_if_negative(anim->secondDistance));
        break;
    }
    case 0x14: {
        float sum;
        s32 n;

        anim->secondSpeed = 64.0f / anim->secondDistance;
        phase = anim->phase;
        sum = 0.0f;
        n = 0;
        for (;;) {
            phase = phase + anim->secondSpeed;
            if (phase >= 64.0f)
                phase = 64.0f;
            sum = sum + anim->firstSpeed * gSineTable[((s32)phase & 0xFF) + 0x40] * (1.0f / 256);
            if (phase == 64.0f)
                break;
            n++;
        }
        anim->secondFrames = n;
        anim->firstDistance = anim->firstDistance + (anim->secondDistance - float_abs_if_negative(sum));
        anim->secondDistance = float_abs_if_negative(sum);
        anim->firstFrames = x =
            anim->firstDistance / float_default_to_one_if_zero(float_abs_if_negative(anim->firstSpeed));
        anim->end = anim->start + x + anim->secondFrames;
        if (anim->endAtStart != 0)
            anim->value = anim->value - float_sign(anim->firstSpeed) * (float_abs_if_negative(anim->firstDistance) +
                                                                        float_abs_if_negative(anim->secondDistance));
        break;
    }
    case 0x15: {

        anim->end = anim->start + anim->duration;
        anim->firstDistance = anim->firstSpeed * (anim->firstFrames = anim->duration - anim->secondFrames);
        anim->secondSpeed = 64.0f / float_default_to_one_if_zero(anim->secondFrames);
        phase = anim->phase;
        anim->secondDistance = 0.0f;
        for (;;) {
            phase = phase + anim->secondSpeed;
            anim->secondDistance =
                anim->secondDistance + anim->firstSpeed * gSineTable[((s32)phase & 0xFF) + 0x40] * (1.0f / 256);
            if (phase >= 64.0f)
                break;
        }
        if (anim->endAtStart != 0)
            anim->value = anim->value - float_sign(anim->firstSpeed) * (float_abs_if_negative(anim->firstDistance) +
                                                                        float_abs_if_negative(anim->secondDistance));
        break;
    }
    case 0x17:
        anim->end = anim->start + anim->duration;
        anim->value = anim->base + anim->secondSpeed * gSineTable[(s32)anim->firstFrames & 0xFF];
        anim->phase = anim->firstFrames;
        break;
    }
}

u32 animation_interpolation_step(struct AnimInterp *anim) {
    u32 ret = 0;
    s32 one = 1;
    float scale;

    if (anim->mode != 0) {
        if (anim->start <= anim->frame) {
            switch (anim->mode) {
            case 0x10:
            case 0x11:
                if (anim->frame < anim->start + anim->firstFrames)
                    anim->value = anim->value + anim->firstSpeed;
                break;
            case 0x12:
            case 0x13:
                if (anim->frame < anim->start + anim->firstFrames) {
                    scale = one;
                    anim->phase = anim->phase + anim->firstSpeed * scale;
                    if (anim->phase >= 64.0f)
                        anim->phase = 64.0f;
                    anim->value = anim->value + anim->secondSpeed *
                                                    (gSineTable[(s32)(anim->phase + 192.0f) & 0xFF] + 256.0f) *
                                                    (1.0f / 256) * scale;
                } else
                    anim->value = anim->value + anim->secondSpeed;
                break;
            case 0x14:
            case 0x15:
                if (anim->frame < anim->start + anim->firstFrames)
                    anim->value = anim->value + anim->firstSpeed;
                else {
                    anim->phase = anim->phase + anim->secondSpeed;
                    if (anim->phase >= 64.0f)
                        anim->phase = 64.0f;
                    anim->value = anim->value +
                                  anim->firstSpeed * gSineTable[((s32)anim->phase & 0xFF) + 0x40] * (1.0f / 256) * one;
                }
                break;
            case 0x17:
                anim->phase = anim->phase + anim->firstSpeed;
                anim->value = anim->base + anim->secondSpeed * gSineTable[(s32)anim->phase & 0xFF] * one;
                break;
            }
            anim->frame = anim->frame + 1.0f;
            if (anim->end != 0xFFFF && anim->frame >= anim->end) {
                anim->mode = 0;
                ret = 1;
            }
        } else
            anim->frame = anim->frame + 1.0f;
    }
    return ret;
}
