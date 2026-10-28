// Field helpers: 2x2 metatile / tilemap rectangle copies, the OAM affine matrix builder, sprite animation
// frames, field_random, the BG blend effect (setup_blend_effect / blend_effect_update), palette fades to a
// colour and a u8 quicksort. Called mostly from field/field_update and field/map_script; talks to the
// engine (OAM, palettes, IO registers).

#include "global.h"

static void apply_blend_coefficients(void);

// One tile of 2x2 metatile `id` (copy_tiles_to_bg_tilemap); yoff / xoff are passed but unused.
void build_bg_tile_entry(u16 *dst, u16 id, u16 base, u16 y, u16 x, u16 yoff, u16 xoff) {
    u16 t = x + y * 2;
    *dst = (t + (id + 1) * 4) | (base + (id << 12));
}

// Not called directly (hidden in the tail of build_bg_tile_entry).
static void copy_tilemap_rect_clamped(u16 *src, u16 *dst, s32 h, s32 w, s32 maxh, s32 pitch, s32 add, s32 pal) {
    s32 i, j;
    if (h > maxh)
        h = maxh;
    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++)
            *dst++ = (*src++ + add) | (pal << 12);
        dst += pitch - w;
    }
}

// Not called directly (hidden in the tail of build_bg_tile_entry).
static void bg_palette_load_slot(u8 slot, const void *src) {
    DmaSet(3, src, PLTT + slot * 32, 0x80000008);
}

void fill_tilemap_rect(u16 *dst, s32 y, s32 x, s32 w, s32 h, s32 tile, s32 pal, s32 mode) {
    s32 pitch;
    s32 i, j;
    u16 *row;

    switch (mode) {
    case 0:
        pitch = 32;
        break;
    case 1:
        pitch = 64;
        break;
    }
    dst += pitch * y + x;
    for (i = 0; i < h; i++) {
        row = dst;
        for (j = 0; j < w; j++)
            *dst++ = tile + (pal << 12);
        dst = row;
        dst += pitch;
    }
}

void copy_tilemap_region(u16 *src, u16 *dst, s32 y, s32 x, s32 w, s32 h, s32 add, s32 pal, s32 mode) {
    s32 pitch;
    s32 i, j;
    u16 *row;
    u16 v;

    switch (mode) {
    case 0:
        pitch = 32;
        break;
    case 1:
        pitch = 64;
        break;
    }
    dst += pitch * y + x;
    for (i = 0; i < h; i++) {
        row = dst;
        for (j = 0; j < w; j++) {
            v = *src;
            *dst = ((v & 0x3FF) + add) | ((v & 0xC00) | (pal << 12));
            dst++;
            src++;
        }
        dst = row;
        dst += pitch;
    }
}

void copy_tilemap_rect_with_offset(u16 *src, u16 *dst, s32 y, s32 x, s32 w, s32 h, s32 unused6, s32 unused7, s32 add,
                                   s32 mode) {
    s32 pitch;
    s32 i, j;
    u16 *srow;
    u16 *row;

    switch (mode) {
    case 0:
        pitch = 32;
        break;
    case 1:
        pitch = 64;
        break;
    }
    dst += pitch * y + x;
    for (i = 0; i < h; i++) {
        srow = src;
        row = dst;
        for (j = 0; j < w; j++) {
            *dst = *src + add;
            dst++;
            src++;
        }
        dst = row;
        src = srow;
        dst += pitch;
        src += pitch;
    }
}

void affine_params_reset(void) {
    s32 i;
    gFieldState.affine_debug_flag = 0;
    gFieldState.affine_debug_level = 0;
    for (i = 0; i < 32; i++) {
        gAffineParams[i].scaleX = 0x100;
        gAffineParams[i].scaleY = 0x100;
        gAffineParams[i].angle = 0;
    }
}

void clear_entity_state(u8 slot) {
    memzero_bytes((u8 *)&gEntityStates[slot], 4);
    memzero_bytes((u8 *)&gSpriteEntries[slot], 0x40);
}

void calculate_oam_affine_matrix(u8 i) {
    const s16 *sine = gSineTable;
    struct AffineParam *base = gAffineParams;
    struct AffineParam *p = &base[i];
    s32 a;

    p->pa = fixed_point_multiply(sine[a = p->angle + 0x40], divide_by_65536(p->scaleX));
    p->pb = fixed_point_multiply(sine[p->angle], divide_by_65536(p->scaleX));
    p->pc = fixed_point_multiply(-sine[p->angle], divide_by_65536(p->scaleY));
    p->pd = fixed_point_multiply(sine[a = p->angle + 0x40], divide_by_65536(p->scaleY));
}

// Starts animation script `anim_id` (gSpriteAnimScripts) on sprite `slot` from its first frame.
void sprite_anim_start(u8 slot, u8 anim_id) {
    gSpriteEntries[slot].unk24 = anim_id;
    gSpriteEntries[slot].unk23 = 0;
    gSpriteEntries[slot].unk22 = 0;
}

void advance_sprite_animation_frame(u8 idx) {
    const struct SpriteAnimCmd *c;
    u16 cmd, arg, duration, frame;
    const struct SpriteAnimGfx *gfx;

    c = gSpriteAnimScripts[gSpriteEntries[idx].unk24];
    cmd = c[gSpriteEntries[idx].unk22].cmd;
    arg = c[gSpriteEntries[idx].unk22].arg;
    duration = c[gSpriteEntries[idx].unk22].duration;
    frame = c[gSpriteEntries[idx].unk22].frame;

    switch (cmd) {
    case 0xFFFD:
        gSpriteEntries[idx].unk22++;
        field_play_sound_effect(arg);
        advance_sprite_animation_frame(idx);
        break;
    case 0xFFFE:
        gSpriteEntries[idx].unk22 = arg;
        gSpriteEntries[idx].unk23 = 0;
        advance_sprite_animation_frame(idx);
        break;
    case 0xFFFA:
        if (gSpriteEntries[idx].unk23 < duration) {
            gSpriteEntries[idx].frame = frame + gSpriteEntries[idx].unk2F;
            gSpriteEntries[idx].unk23++;
            if (gSpriteEntries[idx].unk23 >= duration) {
                gSpriteEntries[idx].unk23 = 0;
                gSpriteEntries[idx].unk22++;
            }
        }
        break;
    case 0xFFFC:
        if (gSpriteEntries[idx].unk23 == 0) {
            gfx = &gSpriteAnimGfx[arg];
            if (gfx->unk0 == 0)
                LZ77UnCompVram(gfx->src, gfx->dst);
        }
    default:
        if (gSpriteEntries[idx].unk23 < duration) {
            gSpriteEntries[idx].frame = frame;
            gSpriteEntries[idx].unk23++;
            if (gSpriteEntries[idx].unk23 >= duration) {
                gSpriteEntries[idx].unk23 = 0;
                gSpriteEntries[idx].unk22++;
            }
        }
        break;
    case 0xFFFF:
        break;
    }
}

// Not called directly (hidden in the tail of advance_sprite_animation_frame).
// guess: debug editor for affine entry 0 / sprite 0 position: A toggles affine_debug_flag, SELECT + D-pad
// scales and rotates, D-pad moves, R/L change affine_debug_level, START resets the affine params.
static u32 affine_debug_input(void) {
    if (KEYS_LO(gNewKeys) & 1)
        gFieldState.affine_debug_flag ^= 1;
    if (KEYS_LO(gHeldKeys) & 4) {
        if (KEYS_LO(gHeldKeys) & 0x40) {
            gAffineParams[0].scaleY += 16;
            if (gAffineParams[0].scaleY > 0x400)
                gAffineParams[0].scaleY = 0x400;
        }
        if (KEYS_LO(gHeldKeys) & 0x80) {
            gAffineParams[0].scaleY -= 8;
            if (gAffineParams[0].scaleY < 0x40)
                gAffineParams[0].scaleY = 0x40;
        }
        if (KEYS_LO(gHeldKeys) & 0x20)
            gAffineParams[0].scaleX -= 8;
        if (KEYS_LO(gHeldKeys) & 0x10) {
            gAffineParams[0].scaleX += 16;
            if (gAffineParams[0].scaleX > 0x400)
                gAffineParams[0].scaleX = 0x400;
            gAffineParams[0].angle = (gAffineParams[0].angle + 1) & 0xFF;
        }
        if (KEYS_LO(gHeldKeys) & 0x20)
            gAffineParams[0].angle = (gAffineParams[0].angle + 0xFF) & 0xFF;
    } else {
        if (KEYS_LO(gHeldKeys) & 0x40) {
            gSpriteEntries[0].y -= 2;
            if (gSpriteEntries[0].y < -80)
                gSpriteEntries[0].y = -80;
        }
        if (KEYS_LO(gHeldKeys) & 0x80) {
            gSpriteEntries[0].y += 2;
            if (gSpriteEntries[0].y > 80)
                gSpriteEntries[0].y = 80;
        }
        if (KEYS_LO(gHeldKeys) & 0x10) {
            gSpriteEntries[0].x += 2;
            if (gSpriteEntries[0].x > 120)
                gSpriteEntries[0].x = 120;
        }
        if (KEYS_LO(gHeldKeys) & 0x20) {
            gSpriteEntries[0].x -= 2;
            if (gSpriteEntries[0].x < -120)
                gSpriteEntries[0].x = -120;
        }
        if (KEYS_HI(gNewKeys) & 1) {
            if (gFieldState.affine_debug_level <= 14)
                gFieldState.affine_debug_level++;
        }
        if (KEYS_HI(gNewKeys) & 2) {
            if (gFieldState.affine_debug_level != 0)
                gFieldState.affine_debug_level--;
        }
    }
    if (KEYS_LO(gNewKeys) & 8)
        affine_params_reset();
    return 0;
}

// Not called directly (hidden in the tail of advance_sprite_animation_frame).
static void field_effects_unused_stub(void) {}

// Not called directly (hidden in the tail of advance_sprite_animation_frame).
static void obj_palette_load_slot(u8 slot, const void *src) {
    DmaSet(3, src, OBJ_PLTT + slot * 32, 0x80000008);
}

void memzero_bytes(u8 *dst, u32 size) {
    u32 i;
    for (i = 0; i < size; i++)
        *dst++ = 0;
}

void memset_bytes(u8 *dst, u32 n, u8 val) {
    u32 i;

    for (i = 0; i < n; i++)
        *dst++ = val;
}

static s32 count_byte_differences(const u8 *lhs, const u8 *rhs, s32 n) {
    s32 count = 0;
    s32 i;

    for (i = 0; i < n; i++) {
        if (*lhs++ != *rhs++)
            count++;
    }
    return count;
}

// Not called directly (hidden in the tail of count_byte_differences at 0x0804971C).
static s32 sum_bytes(const u8 *p, s32 n) {
    s32 sum = 0;
    s32 i;

    for (i = 0; i < n; i++)
        sum += *p++;
    return sum;
}

u8 field_random(u8 n) {
    const u8 *tbl = gRandomBytes;
    u8 r;

    r = tbl[(gFieldWork.rng_seed + gFieldState.frame_counter) & 0xFF];
    gFieldWork.rng_seed = r;
    return Mod(r, n);
}

void memcpy_u8(const void *src, void *dst, u32 n) {
    u32 i;
    for (i = 0; i < n; i++) {
        *(u8 *)dst = *(const u8 *)src;
        src = (const u8 *)src + 1;
        dst = (u8 *)dst + 1;
    }
}

// Starts BG blend effect `type`: alpha types 4-6 step EVA / EVB toward the targets over eva_frames /
// evb_frames frames (blend_effect_update runs it, apply_blend_coefficients writes the registers in VBlank).
void setup_blend_effect(u8 mode, u16 bldcnt, u8 type, u8 eva_frames, u8 evb_frames, u8 evy_frames, u8 target_eva,
                        u8 target_evb, u8 target_evy) {
    if (eva_frames == 0)
        eva_frames = 1;
    if (evb_frames == 0)
        evb_frames = 1;
    if (evy_frames == 0)
        evy_frames = 1;
    gBlendEffect.mode = mode;
    gBlendEffect.type = type;
    gBlendEffect.evy_level = 0.0f;
    gBlendEffect.status = 1;
    if (mode & 0x80)
        bldcnt |= 0x20;
    else
        bldcnt &= ~0x20;
    switch (gBlendEffect.type) {
    case 0:
    case 2:
        gBlendEffect.evy = 16;
        break;
    case 1:
    case 3:
        gBlendEffect.evy = 16;
        break;
    case 4:
        gBlendEffect.target_eva = REG_BLDALPHA & 0x1F;
        gBlendEffect.target_evb = (REG_BLDALPHA & 0x1F00) >> 8;
        gBlendEffect.target_evy = REG_BLDY & 0x1F;
        gBlendEffect.eva_level = 0.0f;
        gBlendEffect.evb_level = 0.0f;
        gBlendEffect.eva_step = (16 - gBlendEffect.target_eva) / (float)eva_frames;
        gBlendEffect.evb_step = (16 - gBlendEffect.target_evb) / (float)evb_frames;
        goto end;
    case 5:
        gBlendEffect.target_eva = target_eva;
        gBlendEffect.target_evb = target_evb;
        gBlendEffect.target_evy = target_evy;
        gBlendEffect.eva_level = 0.0f;
        gBlendEffect.evb_level = 0.0f;
        gBlendEffect.eva_step = (16 - target_eva) / (float)eva_frames;
        gBlendEffect.evb_step = (16 - target_evb) / (float)evb_frames;
        gBlendEffect.eva = 16;
        gBlendEffect.evb = 16;
        gVBlankCallback = apply_blend_coefficients;
        goto end;
    case 6:
        gBlendEffect.start_eva = REG_BLDALPHA & 0x1F;
        gBlendEffect.start_evb = (REG_BLDALPHA & 0x1F00) >> 8;
        gBlendEffect.target_eva = target_eva;
        gBlendEffect.target_evb = target_evb;
        gBlendEffect.target_evy = target_evy;
        gBlendEffect.eva_level = 0.0f;
        gBlendEffect.evb_level = 0.0f;
        gBlendEffect.eva_step = (gBlendEffect.start_eva - target_eva) / (float)eva_frames;
        gBlendEffect.evb_step = (gBlendEffect.start_evb - target_evb) / (float)evb_frames;
        goto end;
    default:
        gBlendEffect.evy = 0;
        break;
    }
end:
    REG_BLDCNT = bldcnt | mode;
}

u32 blend_effect_update(void) {
    u32 done = 0;

    if (gBlendEffect.status == 2) {
        done = 1;
        gVBlankCallback = empty_callback;
    } else if (gBlendEffect.status == 1) {
        switch (gBlendEffect.mode) {
        case 0x00:
        case 0x40:
            break;
        case 0x80:
        case 0xC0:
            if (gBlendEffect.evy_level < 256.0f)
                gBlendEffect.evy_level += gBlendEffect.evy_step;
            else
                gBlendEffect.evy_level = 256.0f;
            if (gBlendEffect.evy_level >= 256.0f)
                done = 1;
            break;
        }
        switch (gBlendEffect.type) {
        case 0:
        case 2:
            gBlendEffect.eva = gBlendEffect.eva_level * 0.0625f;
            gBlendEffect.evb = gBlendEffect.evb_level * 0.0625f;
            gBlendEffect.evy = gBlendEffect.evy_level * 0.0625f;
            break;
        case 1:
        case 3:
            gBlendEffect.eva = 16.0f - gBlendEffect.eva_level * 0.0625f;
            gBlendEffect.evb = 16.0f - gBlendEffect.evb_level * 0.0625f;
            gBlendEffect.evy = 16.0f - gBlendEffect.evy_level * 0.0625f;
            break;
        case 4:
            gBlendEffect.eva_level += gBlendEffect.eva_step;
            gBlendEffect.eva = (u8)gBlendEffect.eva_level + gBlendEffect.target_eva;
            if (gBlendEffect.eva > 15) {
                gBlendEffect.eva = 16;
                done = 1;
            }
            gBlendEffect.evb_level += gBlendEffect.evb_step;
            gBlendEffect.evb = (u8)gBlendEffect.evb_level + gBlendEffect.target_evb;
            if (gBlendEffect.evb > 15) {
                gBlendEffect.evb = 16;
                done = 1;
            }
            break;
        case 5:
            gBlendEffect.eva_level += gBlendEffect.eva_step;
            gBlendEffect.eva = 16 - (u8)gBlendEffect.eva_level;
            if (gBlendEffect.eva <= gBlendEffect.target_eva) {
                gBlendEffect.eva = gBlendEffect.target_eva;
                done = 1;
            }
            gBlendEffect.evb_level += gBlendEffect.evb_step;
            gBlendEffect.evb = 16 - (u8)gBlendEffect.evb_level;
            if (gBlendEffect.evb <= gBlendEffect.target_evb) {
                gBlendEffect.evb = gBlendEffect.target_evb;
                done = 1;
            }
            break;
        case 6:
            gBlendEffect.eva_level += gBlendEffect.eva_step;
            gBlendEffect.eva = gBlendEffect.start_eva - (u8)gBlendEffect.eva_level;
            if (gBlendEffect.target_eva != gBlendEffect.start_eva) {
                if (gBlendEffect.eva >= gBlendEffect.target_eva) {
                    gBlendEffect.eva = gBlendEffect.target_eva;
                    done = 1;
                }
            } else if (gBlendEffect.eva <= gBlendEffect.target_eva) {
                gBlendEffect.eva = gBlendEffect.target_eva;
                done = 1;
            }
            gBlendEffect.evb_level += gBlendEffect.evb_step;
            gBlendEffect.evb = gBlendEffect.start_evb - (u8)gBlendEffect.evb_level;
            if (gBlendEffect.target_evb != gBlendEffect.start_evb) {
                if (gBlendEffect.evb >= gBlendEffect.target_evb) {
                    gBlendEffect.evb = gBlendEffect.target_evb;
                    done = 1;
                }
            } else if (gBlendEffect.evb <= gBlendEffect.target_evb) {
                gBlendEffect.evb = gBlendEffect.target_evb;
                done = 1;
            }
            break;
        }
    }
    gVBlankCallback = apply_blend_coefficients;
    if (done) {
        done = 0;
        gBlendEffect.status = 2;
    }
    return done;
}
static void apply_blend_coefficients(void) {
    REG_BLDALPHA = ((gBlendEffect.evb & 0x3F) << 8) | (gBlendEffect.eva & 0x3F);
    REG_BLDY = gBlendEffect.evy & 0x3F;
}

void field_palettes_blend_to_color(u16 color, u32 amount) {
    palettes_blend_to_color(color, amount);
}

void field_palette_backup(void) {
    palette_backup_from_hardware();
}

void setup_palette_fade_to_color(u16 color, float start, float end, float steps) {
    // called without a prototype in the original (the float is passed as a double)
    ((void (*)())palettes_blend_to_color)(color, start);
    gBlendEffect.fade_amount = start;
    gBlendEffect.fade_start = start;
    gBlendEffect.fade_end = end;
    gBlendEffect.fade_step = (start - end) / steps;
    setup_blend_effect(0x40, 0x2F00, 5, steps, steps, steps, 12, 10, 0);
}

void setup_palette_fade_to_color_with_obj(u16 color, float start, float end, float steps) {
    field_palette_backup();
    // called without a prototype in the original (the float is passed as a double)
    ((void (*)())palettes_blend_to_color)(color, start);
    gBlendEffect.fade_amount = start;
    gBlendEffect.fade_start = start;
    gBlendEffect.fade_end = end;
    gBlendEffect.fade_step = (start - end) / steps;
    setup_blend_effect(0x40, 0x2F00, 4, steps, steps, steps, 16, 16, 0);
}

u32 run_blend_fade_transition(u16 color) {
    u32 done = 0;

    blend_effect_update();
    gFieldEffect.bg_blend_mask = 0xFFFF;
    gFieldEffect.obj_blend_mask = 0xBFFF;
    field_bg_palettes_blend_masked(color, gBlendEffect.fade_amount, gFieldEffect.bg_blend_mask);
    field_obj_palettes_blend_masked(color, gBlendEffect.fade_amount, gFieldEffect.obj_blend_mask);
    gBlendEffect.fade_amount -= gBlendEffect.fade_step;
    if (gBlendEffect.fade_step > 0.0f) {
        if (gBlendEffect.fade_amount < gBlendEffect.fade_end) {
            gVBlankCallback = empty_callback;
            done = 1;
        }
    } else if (gBlendEffect.fade_amount > gBlendEffect.fade_end) {
        gVBlankCallback = empty_callback;
        done = 1;
    }
    return done;
}

void field_bg_palettes_blend_masked(u16 color, u32 amount, u16 mask) {
    bg_palettes_blend_masked_now(color, amount, mask);
}

void field_obj_palettes_blend_masked(u16 color, u32 amount, u16 mask) {
    obj_palettes_blend_masked_now(color, amount, mask);
}

// Sorts arr[left..right] in ascending order (quicksort, pivot arr[left]).
static void quicksort_u8_array(u8 *arr, s16 left, s16 right) {
    s32 i, j;
    u8 tmp;

    if (left < right) {
        i = left + 1;
        j = right;
        while (i <= j) {
            for (; i <= j; i++)
                if (arr[i] > arr[left])
                    break;
            for (; i <= j; j--)
                if (arr[j] < arr[left])
                    break;
            if (i >= j)
                break;
            tmp = arr[j];
            arr[j] = arr[i];
            arr[i] = tmp;
            i++;
            j--;
        }
        tmp = arr[j];
        arr[j] = arr[left];
        arr[left] = tmp;
        quicksort_u8_array(arr, left, j - 1);
        quicksort_u8_array(arr, j + 1, right);
    }
}

// Not called directly (hidden in the tail of quicksort_u8_array).
// guess: sorts u16 entries by their low byte, ascending
static void quicksort_u16_low_byte_ascending(u16 *arr, s16 left, s16 right) {
    s32 i, j;
    u16 tmp;

    if (left < right) {
        i = left + 1;
        j = right;
        while (i <= j) {
            for (; i <= j; i++)
                if ((arr[i] & 0xFF) >= (arr[left] & 0xFF))
                    break;
            for (; i <= j; j--)
                if ((arr[j] & 0xFF) <= (arr[left] & 0xFF))
                    break;
            if (i >= j)
                break;
            tmp = arr[j];
            arr[j] = arr[i];
            arr[i] = tmp;
            i++;
            j--;
        }
        tmp = arr[j];
        arr[j] = arr[left];
        arr[left] = tmp;
        quicksort_u16_low_byte_ascending(arr, left, j - 1);
        quicksort_u16_low_byte_ascending(arr, j + 1, right);
    }
}

// Not called directly (hidden in the tail of quicksort_u8_array).
// guess: sorts u16 entries by their low byte, descending
static void quicksort_u16_low_byte_descending(u16 *arr, s16 left, s16 right) {
    s32 i, j;
    u16 tmp;

    if (left < right) {
        i = left + 1;
        j = right;
        while (i <= j) {
            for (; i <= j; i++)
                if ((arr[i] & 0xFF) <= (arr[left] & 0xFF))
                    break;
            for (; i <= j; j--)
                if ((arr[j] & 0xFF) >= (arr[left] & 0xFF))
                    break;
            if (i >= j)
                break;
            tmp = arr[j];
            arr[j] = arr[i];
            arr[i] = tmp;
            i++;
            j--;
        }
        tmp = arr[j];
        arr[j] = arr[left];
        arr[left] = tmp;
        quicksort_u16_low_byte_descending(arr, left, j - 1);
        quicksort_u16_low_byte_descending(arr, j + 1, right);
    }
}

void game_substate_advance(void) {
    gGameSubState++;
}
