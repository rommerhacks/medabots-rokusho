// Sprite-to-OAM builder: build_sprite_oam (once a frame from AgbMain) turns the sprite table into OAM
// entries from the frame tables, sorted by priority (shell_sort_by_second_byte), with affine matrices from
// set_oam_affine_params / compute_scaled_value / rotate_vector_2d.

#include "global.h"

static void set_oam_affine_params(u32 idx, u32 angle, s32 sx, s32 sy, u32 flags);
static void compute_scaled_value(u32 idx, s32 sx, s32 sy, u32 flags);
static void rotate_vector_2d(s32 *x, s32 *y, struct SpriteEntry *p);

void build_sprite_oam(void) {
    struct ObjSortEntry sorted[128];
    s32 zero;
    s32 x, y;
    struct SpriteEntry *obj;
    s32 i, count, j, oamIdx, affIdx, dbl, affBits;
    s32 px, py, w, h;
    struct SpriteFrame *const *frameSet;
    struct SpritePart *part;
    struct OamData *oam;

    if (gOamBuildFlags & 1) {
        gOamBuildFlags = 0;
        return;
    }
    zero = 0;
    CpuFastSet(&zero, sorted, 0x01000040);
    obj = gSpriteEntries;
    count = 0;
    for (i = 0; i < 128; i++, obj++) {
        if (obj->flags & SPRITE_FLAG_ENABLED) {
            sorted[count].idx = i;
            sorted[count].key = obj->order;
            count++;
        }
    }
    if (!(gOamBuildFlags & 2))
        shell_sort_by_second_byte(sorted, count);
    else
        gOamBuildFlags = 0;

    if (gVBlankOamMode == 2)
        affIdx = 22;
    else
        affIdx = 0;
    oamIdx = 0;
    for (i = 0; i < count; i++) {
        obj = &gSpriteEntries[sorted[i].idx];
        gOamAffineZoomOverride = -1;
        switch (obj->flags & SPRITE_POS_MASK) {
        case SPRITE_POS_PERSPECTIVE:
            px = obj->pos_x * 4;
            py = (obj->pos_y + gSpritePerspOffsetY) * 4;
            w = (obj->pos_z + 0x3000) / 64;
            px = px / w;
            py = py / w;
            obj->x = gSpritePerspCenterX + px;
            obj->y = gSpritePerspCenterY + py;
            obj->scale_x = obj->scale_y = 0x8000 / w;
            gOamAffineZoomOverride = 0x700000 / w;
            break;
        case SPRITE_POS_SHARED_AFFINE:
            break;
        case SPRITE_POS_WORLD:
            obj->x = (obj->pos_x >> 8) - gSpriteCameraPos.x;
            obj->y = ((obj->pos_y + obj->pos_z) >> 8) - gSpriteCameraPos.y;
            break;
        }
        switch (obj->frame_table & 0xF) {
        case 1:
            frameSet = gSpriteFrameSets1[obj->frame >> 8];
            break;
        case 2:
            frameSet = gMenuSpriteFrameSets[obj->frame >> 8];
            break;
        case 3:
            frameSet = gSpriteFrameSets3[obj->frame >> 8];
            break;
        case 0:
        default:
            frameSet = gSpriteFrameSets[obj->frame >> 8];
            break;
        }
        part = frameSet[obj->frame & 0xFF]->parts;
        px = -gBgScrollOffset.x + gSpriteScreenOffset.x + obj->x;
        py = -gBgScrollOffset.y + gSpriteScreenOffset.y + obj->y;
        if ((obj->flags & SPRITE_POS_MASK) == SPRITE_POS_WORLD) {
            if ((u32)(py + 32) > 256) {
                obj->flags |= SPRITE_FLAG_OFFSCREEN;
                continue;
            }
            if ((u32)(px + 32) > 336) {
                obj->flags |= SPRITE_FLAG_OFFSCREEN;
                continue;
            }
            obj->flags &= ~SPRITE_FLAG_OFFSCREEN;
        }
        if (!(obj->flags & SPRITE_FLAG_VISIBLE))
            continue;
        if (obj->flags & SPRITE_FLAG_AFFINE) {
            if ((obj->flags & SPRITE_POS_MASK) != SPRITE_POS_SHARED_AFFINE) {
                if (affIdx < 32) {
                    if (obj->angle)
                        set_oam_affine_params(affIdx, obj->angle, obj->scale_x, obj->scale_y, obj->flags);
                    else
                        compute_scaled_value(affIdx, obj->scale_x, obj->scale_y, obj->flags);
                    dbl = (obj->flags & SPRITE_FLAG_DOUBLE_SIZE) ? 0x300 : 0x100;
                    affBits = affIdx << 9;
                    affIdx++;
                }
            } else {
                dbl = (obj->flags & SPRITE_FLAG_DOUBLE_SIZE) ? 0x300 : 0x100;
                affBits = obj->affine_idx << 9;
            }
        } else {
            dbl = 0;
            affBits = 0;
        }

        for (j = 0; j < frameSet[obj->frame & 0xFF]->count; j++) {
            oam = gOamBuffer;
            h = *(u16 *)part & 0xC0C0;
            switch (h) {
            case 0x0:
            case 0x80:
            case 0x4080:
                w = 4;
                break;
            case 0x40:
            case 0x4000:
            case 0x8080:
                w = 8;
                break;
            case 0x4040:
            case 0x8000:
            case 0x8040:
            case 0xC080:
                w = 16;
                break;
            case 0xC000:
            case 0xC040:
                w = 32;
                break;
            }
            switch (h) {
            case 0x0:
            case 0x40:
            case 0x4040:
                h = 4;
                break;
            case 0x80:
            case 0x4000:
            case 0x8040:
                h = 8;
                break;
            case 0x4080:
            case 0x8000:
            case 0x8080:
            case 0xC040:
                h = 16;
                break;
            case 0xC000:
            case 0xC080:
                h = 32;
                break;
            }
            if (obj->flags & SPRITE_FLAG_AFFINE) {
                if ((obj->flags & SPRITE_POS_MASK) != SPRITE_POS_SHARED_AFFINE) {
                    x = part->x + w;
                    y = part->y + h;
                    if (obj->flags & SPRITE_FLAG_DOUBLE_SIZE) {
                        w = -w * 2;
                        h = -h * 2;
                    } else {
                        w = -w;
                        h = -h;
                    }
                    if (obj->flags & SPRITE_FLAG_HFLIP)
                        x = -x - (obj->scale_x - SPRITE_SCALE_ONE) * x / 64;
                    else
                        x = x + (obj->scale_x - SPRITE_SCALE_ONE) * x / 64;
                    if (obj->flags & SPRITE_FLAG_VFLIP)
                        y = -y - (obj->scale_y - SPRITE_SCALE_ONE) * y / 64;
                    else
                        y = y + (obj->scale_y - SPRITE_SCALE_ONE) * y / 64;
                    if (obj->flags & SPRITE_FLAG_ROTATE)
                        rotate_vector_2d(&x, &y, obj);
                    w = w + px + x;
                    h = h + py + y;
                    oam[oamIdx].attr0 = (h & 0xFF) | (part->shape << 8) | dbl |
                                        ((obj->flags & SPRITE_FLAG_OBJ_MODE_MASK) << 7) |
                                        ((obj->flags & SPRITE_FLAG_MOSAIC) << 12);
                    oam[oamIdx].attr1 = (w & 0x1FF) | ((part->size & 0xC0) << 8) | affBits;
                } else {
                    if (obj->flags & SPRITE_FLAG_DOUBLE_SIZE) {
                        w = part->x;
                        h = part->y;
                    } else {
                        w = 0;
                        h = 0;
                    }
                    if (obj->flags & SPRITE_FLAG_HFLIP)
                        w = -part->x - w + px - w;
                    else
                        w = w + (part->x + px);
                    if (obj->flags & SPRITE_FLAG_VFLIP)
                        h = -part->y - h + py - h;
                    else
                        h = h + (part->y + py);
                    oam[oamIdx].attr0 = (h & 0xFF) | (part->shape << 8) | dbl |
                                        ((obj->flags & SPRITE_FLAG_OBJ_MODE_MASK) << 7) |
                                        ((obj->flags & SPRITE_FLAG_MOSAIC) << 12);
                    oam[oamIdx].attr1 = ((w & 0x1FF) | (part->size << 8) | affBits) ^
                                        (obj->flags & (SPRITE_FLAG_HFLIP | SPRITE_FLAG_VFLIP));
                }
            } else {
                if (obj->flags & SPRITE_FLAG_HFLIP)
                    w = -part->x - w + px - w;
                else
                    w = px + part->x;
                if (obj->flags & SPRITE_FLAG_VFLIP)
                    h = -part->y - h + py - h;
                else
                    h = py + part->y;
                oam[oamIdx].attr0 = (h & 0xFF) | (part->shape << 8) | dbl |
                                    ((obj->flags & SPRITE_FLAG_OBJ_MODE_MASK) << 7) |
                                    ((obj->flags & SPRITE_FLAG_MOSAIC) << 12);
                oam[oamIdx].attr1 =
                    ((w & 0x1FF) | (part->size << 8)) ^ (obj->flags & (SPRITE_FLAG_HFLIP | SPRITE_FLAG_VFLIP));
            }
            if (obj->flags & SPRITE_FLAG_PART_PALETTE) {
                if (part->tile & 0xF000)
                    ((u16 *)gOamBuffer)[oamIdx * 4 + 2] = (obj->flags & SPRITE_FLAG_PRIORITY_MASK) | part->tile;
                else
                    ((u16 *)gOamBuffer)[oamIdx * 4 + 2] =
                        (part->tile & 0xFFF) | (obj->palette << 12) | (obj->flags & SPRITE_FLAG_PRIORITY_MASK);
            } else {
                ((u16 *)gOamBuffer)[oamIdx * 4 + 2] =
                    ((obj->palette << 12) + part->tile) | (obj->flags & SPRITE_FLAG_PRIORITY_MASK);
            }

            oamIdx++;
            part++;
            if (oamIdx > 127)
                goto end;
        }
        if (oamIdx > 127)
            goto end;
    }
end:
    for (i = oamIdx; i < 128; i++)
        ((u16 *)gOamBuffer)[i * 4] = 0x200;
    gGameWork.oamUploadPending = 1;
}

static void set_oam_affine_params(u32 idx, u32 angle, s32 sx, s32 sy, u32 flags) {
    u32 n = idx * 4;
    s32 cos, sin;

    if (gOamAffineZoomOverride == -1) {
        cos = gSineTableQ14[(angle & 0x3FF) + 0x100];
        sin = gSineTableQ14[angle & 0x3FF];
        if (sx == 0)
            sx = 1;
        if (sy == 0)
            sy = 1;
        if (flags & SPRITE_FLAG_HFLIP) {
            gOamBuffer[n].affineParam = DivArm(sx, -cos);
            gOamBuffer[n + 1].affineParam = DivArm(sy, -sin);
        } else {
            gOamBuffer[n].affineParam = DivArm(sx, cos);
            gOamBuffer[n + 1].affineParam = DivArm(sy, sin);
        }
        if (flags & SPRITE_FLAG_VFLIP) {
            gOamBuffer[n + 2].affineParam = DivArm(sx, sin);
            gOamBuffer[n + 3].affineParam = DivArm(sy, -cos);
        } else {
            gOamBuffer[n + 3].affineParam = DivArm(sy, cos);
            gOamBuffer[n + 2].affineParam = DivArm(sx, -sin);
        }
    } else {
        cos = gSineTableQ14[(angle & 0x3FF) + 0x100] << 8;
        sin = gSineTableQ14[angle & 0x3FF] << 8;
        if (flags & SPRITE_FLAG_HFLIP) {
            gOamBuffer[n].affineParam = DivArm(gOamAffineZoomOverride, -cos);
            gOamBuffer[n + 1].affineParam = DivArm(gOamAffineZoomOverride, -sin);
        } else {
            gOamBuffer[n].affineParam = DivArm(gOamAffineZoomOverride, cos);
            gOamBuffer[n + 1].affineParam = DivArm(gOamAffineZoomOverride, sin);
        }
        if (flags & SPRITE_FLAG_VFLIP) {
            gOamBuffer[n + 2].affineParam = DivArm(gOamAffineZoomOverride, sin);
            gOamBuffer[n + 3].affineParam = DivArm(gOamAffineZoomOverride, -cos);
        } else {
            gOamBuffer[n + 3].affineParam = DivArm(gOamAffineZoomOverride, cos);
            gOamBuffer[n + 2].affineParam = DivArm(gOamAffineZoomOverride, -sin);
        }
    }
}

static void compute_scaled_value(u32 idx, s32 sx, s32 sy, u32 flags) {
    u32 n = idx * 4;

    if (gOamAffineZoomOverride == -1) {
        if (flags & SPRITE_FLAG_HFLIP) {
            gOamBuffer[n].affineParam = -0x4000 / sx;
            gOamBuffer[n + 1].affineParam = 0;
        } else {
            gOamBuffer[n].affineParam = 0x4000 / sx;
            gOamBuffer[n + 1].affineParam = 0;
        }
        if (flags & SPRITE_FLAG_VFLIP) {
            gOamBuffer[n + 2].affineParam = 0;
            gOamBuffer[n + 3].affineParam = -0x4000 / sy;
        } else {
            gOamBuffer[n + 3].affineParam = 0x4000 / sy;
            gOamBuffer[n + 2].affineParam = 0;
        }
    } else {
        if (flags & SPRITE_FLAG_HFLIP) {
            gOamBuffer[n].affineParam = -0x400000 / gOamAffineZoomOverride;
            gOamBuffer[n + 1].affineParam = 0;
        } else {
            gOamBuffer[n].affineParam = 0x400000 / gOamAffineZoomOverride;
            gOamBuffer[n + 1].affineParam = 0;
        }
        if (flags & SPRITE_FLAG_VFLIP) {
            gOamBuffer[n + 2].affineParam = 0;
            gOamBuffer[n + 3].affineParam = -0x400000 / gOamAffineZoomOverride;
        } else {
            gOamBuffer[n + 3].affineParam = 0x400000 / gOamAffineZoomOverride;
            gOamBuffer[n + 2].affineParam = 0;
        }
    }
}

// Rotates (*x, *y) by p->angle (1024 steps per turn); the table is Q14 sin, cos at +0x100.
static void rotate_vector_2d(s32 *x, s32 *y, struct SpriteEntry *p) {
    s32 c = gSineTableQ14[(p->angle & 0x3FF) + 0x100];
    s32 s = gSineTableQ14[p->angle & 0x3FF];
    s32 x0 = *x;
    s32 y0 = *y;

    *x = (x0 * c - y0 * s) / 0x4000;
    *y = (x0 * s + y0 * c) / 0x4000;
}

void shell_sort_by_second_byte(struct ObjSortEntry *arr, u16 n) {
    u16 gap;
    u16 i;
    u16 j;
    u32 swapped;
    u16 t;
    struct ObjSortEntry *b, *a;
    gap = n;
    if (gap <= 1)
        return;
outer:
    gap = (u16)(gap * 5 / 8);
    if (gap == 0)
        gap = 1;
    swapped = 0;
    i = 0;
loop:
    j = (u16)(i + gap);
    a = (struct ObjSortEntry *)(i * 4 + (u32)arr);
    b = (struct ObjSortEntry *)(j * 4 + (u32)arr);
    if (a->key < b->key) {
        t = *(u16 *)a;
        *(u16 *)a = *(u16 *)b;
        swapped = t;
        *(u16 *)b = swapped;
        swapped = 1;
    }
    if (j + 1 < n) {
        i = (u16)(i + 1);
        goto loop;
    }
    if (swapped == 1 || gap > 1)
        goto outer;
}
