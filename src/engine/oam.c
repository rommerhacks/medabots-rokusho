// Sprite-to-OAM builder: check_flag_and_fast_copy (once a frame from AgbMain) turns the sprite table into OAM
// entries from the frame tables, sorted by priority (shell_sort_by_second_byte), with affine matrices from
// set_oam_affine_params / compute_scaled_value / rotate_vector_2d.

#include "global.h"

static void set_oam_affine_params(u32 idx, u32 angle, s32 sx, s32 sy, u32 flags);
static void compute_scaled_value(u32 idx, s32 sx, s32 sy, u32 flags);
static void rotate_vector_2d(s32 *x, s32 *y, struct RotateSrc *p);

void check_flag_and_fast_copy(void) {
    struct ObjSortEntry sorted[128];
    s32 zero;
    s32 x, y;
    struct Unk_03002C30 *obj;
    s32 i, count, j, oamIdx, affIdx, dbl, affBits;
    s32 px, py, w, h;
    struct SpriteFrame *const *frameSet;
    struct SpritePart *part;
    struct OamData *oam;

    if (gUnk_03000438 & 1) {
        gUnk_03000438 = 0;
        return;
    }
    zero = 0;
    CpuFastSet(&zero, sorted, 0x01000040);
    obj = gUnk_03002C30;
    count = 0;
    for (i = 0; i < 128; i++, obj++) {
        if (obj->unk0 & 0x8000) {
            sorted[count].idx = i;
            sorted[count].key = obj->unkB;
            count++;
        }
    }
    if (!(gUnk_03000438 & 2))
        shell_sort_by_second_byte(sorted, count);
    else
        gUnk_03000438 = 0;

    if (gUnk_03000430 == 2)
        affIdx = 22;
    else
        affIdx = 0;
    oamIdx = 0;
    for (i = 0; i < count; i++) {
        obj = &gUnk_03002C30[sorted[i].idx];
        gUnk_03005048 = -1;
        switch (obj->unk0 & 0xC0) {
        case 0x80:
            px = obj->unkC_8 * 4;
            py = (obj->unk10_8 + gUnk_03005044) * 4;
            w = (obj->unk14_8 + 0x3000) / 64;
            px = px / w;
            py = py / w;
            obj->unk2 = gUnk_03005040 + px;
            obj->unk4 = gUnk_0300504C + py;
            obj->unk8 = obj->unk9 = 0x8000 / w;
            gUnk_03005048 = 0x700000 / w;
            break;
        case 0xC0:
            break;
        case 0x40:
            obj->unk2 = (obj->unkC_8 >> 8) - gUnk_03002C24.x;
            obj->unk4 = ((obj->unk10_8 + obj->unk14_8) >> 8) - gUnk_03002C24.y;
            break;
        }
        switch (obj->unk1C & 0xF) {
        case 1:
            frameSet = gUnk_083AC088[obj->unk6 >> 8];
            break;
        case 2:
            frameSet = gUnk_083AC0C8[obj->unk6 >> 8];
            break;
        case 3:
            frameSet = gUnk_083AC108[obj->unk6 >> 8];
            break;
        case 0:
        default:
            frameSet = gUnk_083ABE30[obj->unk6 >> 8];
            break;
        }
        part = frameSet[obj->unk6 & 0xFF]->parts;
        px = -gUnk_03002C2C.x + gUnk_03001794.x + obj->unk2;
        py = -gUnk_03002C2C.y + gUnk_03001794.y + obj->unk4;
        if ((obj->unk0 & 0xC0) == 0x40) {
            if ((u32)(py + 32) > 256) {
                obj->unk0 |= 2;
                continue;
            }
            if ((u32)(px + 32) > 336) {
                obj->unk0 |= 2;
                continue;
            }
            obj->unk0 &= ~2;
        }
        if (!(obj->unk0 & 0x4000))
            continue;
        if (obj->unk0 & 0x200) {
            if ((obj->unk0 & 0xC0) != 0xC0) {
                if (affIdx < 32) {
                    if (obj->unk18)
                        set_oam_affine_params(affIdx, obj->unk18, obj->unk8, obj->unk9, obj->unk0);
                    else
                        compute_scaled_value(affIdx, obj->unk8, obj->unk9, obj->unk0);
                    dbl = (obj->unk0 & 0x20) ? 0x300 : 0x100;
                    affBits = affIdx << 9;
                    affIdx++;
                }
            } else {
                dbl = (obj->unk0 & 0x20) ? 0x300 : 0x100;
                affBits = obj->filler1D[0] << 9; // unk1D: shared affine matrix index
            }
        } else {
            dbl = 0;
            affBits = 0;
        }

        for (j = 0; j < frameSet[obj->unk6 & 0xFF]->count; j++) {
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
            if (obj->unk0 & 0x200) {
                if ((obj->unk0 & 0xC0) != 0xC0) {
                    x = part->x + w;
                    y = part->y + h;
                    if (obj->unk0 & 0x20) {
                        w = -w * 2;
                        h = -h * 2;
                    } else {
                        w = -w;
                        h = -h;
                    }
                    if (obj->unk0 & 0x1000)
                        x = -x - (obj->unk8 - 0x40) * x / 64;
                    else
                        x = x + (obj->unk8 - 0x40) * x / 64;
                    if (obj->unk0 & 0x2000)
                        y = -y - (obj->unk9 - 0x40) * y / 64;
                    else
                        y = y + (obj->unk9 - 0x40) * y / 64;
                    if (obj->unk0 & 0x100)
                        rotate_vector_2d(&x, &y, (struct RotateSrc *)obj);
                    w = w + px + x;
                    h = h + py + y;
                    oam[oamIdx].attr0 =
                        (h & 0xFF) | (part->shape << 8) | dbl | ((obj->unk0 & 0x18) << 7) | ((obj->unk0 & 1) << 12);
                    oam[oamIdx].attr1 = (w & 0x1FF) | ((part->size & 0xC0) << 8) | affBits;
                } else {
                    if (obj->unk0 & 0x20) {
                        w = part->x;
                        h = part->y;
                    } else {
                        w = 0;
                        h = 0;
                    }
                    if (obj->unk0 & 0x1000)
                        w = -part->x - w + px - w;
                    else
                        w = w + (part->x + px);
                    if (obj->unk0 & 0x2000)
                        h = -part->y - h + py - h;
                    else
                        h = h + (part->y + py);
                    oam[oamIdx].attr0 =
                        (h & 0xFF) | (part->shape << 8) | dbl | ((obj->unk0 & 0x18) << 7) | ((obj->unk0 & 1) << 12);
                    oam[oamIdx].attr1 = ((w & 0x1FF) | (part->size << 8) | affBits) ^ (obj->unk0 & 0x3000);
                }
            } else {
                if (obj->unk0 & 0x1000)
                    w = -part->x - w + px - w;
                else
                    w = px + part->x;
                if (obj->unk0 & 0x2000)
                    h = -part->y - h + py - h;
                else
                    h = py + part->y;
                oam[oamIdx].attr0 =
                    (h & 0xFF) | (part->shape << 8) | dbl | ((obj->unk0 & 0x18) << 7) | ((obj->unk0 & 1) << 12);
                oam[oamIdx].attr1 = ((w & 0x1FF) | (part->size << 8)) ^ (obj->unk0 & 0x3000);
            }
            if (obj->unk0 & 4) {
                if (part->tile & 0xF000)
                    ((u16 *)gOamBuffer)[oamIdx * 4 + 2] = (obj->unk0 & 0xC00) | part->tile;
                else
                    ((u16 *)gOamBuffer)[oamIdx * 4 + 2] =
                        (part->tile & 0xFFF) | (obj->unkA << 12) | (obj->unk0 & 0xC00);
            } else {
                ((u16 *)gOamBuffer)[oamIdx * 4 + 2] = ((obj->unkA << 12) + part->tile) | (obj->unk0 & 0xC00);
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
    gUnk_03000440.unk12E = 1;
}

static void set_oam_affine_params(u32 idx, u32 angle, s32 sx, s32 sy, u32 flags) {
    u32 n = idx * 4;
    s32 cos, sin;

    if (gUnk_03005048 == -1) {
        cos = gUnk_080750E0[(angle & 0x3FF) + 0x100];
        sin = gUnk_080750E0[angle & 0x3FF];
        if (sx == 0)
            sx = 1;
        if (sy == 0)
            sy = 1;
        if (flags & 0x1000) {
            gOamBuffer[n].affineParam = DivArm(sx, -cos);
            gOamBuffer[n + 1].affineParam = DivArm(sy, -sin);
        } else {
            gOamBuffer[n].affineParam = DivArm(sx, cos);
            gOamBuffer[n + 1].affineParam = DivArm(sy, sin);
        }
        if (flags & 0x2000) {
            gOamBuffer[n + 2].affineParam = DivArm(sx, sin);
            gOamBuffer[n + 3].affineParam = DivArm(sy, -cos);
        } else {
            gOamBuffer[n + 3].affineParam = DivArm(sy, cos);
            gOamBuffer[n + 2].affineParam = DivArm(sx, -sin);
        }
    } else {
        cos = gUnk_080750E0[(angle & 0x3FF) + 0x100] << 8;
        sin = gUnk_080750E0[angle & 0x3FF] << 8;
        if (flags & 0x1000) {
            gOamBuffer[n].affineParam = DivArm(gUnk_03005048, -cos);
            gOamBuffer[n + 1].affineParam = DivArm(gUnk_03005048, -sin);
        } else {
            gOamBuffer[n].affineParam = DivArm(gUnk_03005048, cos);
            gOamBuffer[n + 1].affineParam = DivArm(gUnk_03005048, sin);
        }
        if (flags & 0x2000) {
            gOamBuffer[n + 2].affineParam = DivArm(gUnk_03005048, sin);
            gOamBuffer[n + 3].affineParam = DivArm(gUnk_03005048, -cos);
        } else {
            gOamBuffer[n + 3].affineParam = DivArm(gUnk_03005048, cos);
            gOamBuffer[n + 2].affineParam = DivArm(gUnk_03005048, -sin);
        }
    }
}

static void compute_scaled_value(u32 idx, s32 sx, s32 sy, u32 flags) {
    u32 n = idx * 4;

    if (gUnk_03005048 == -1) {
        if (flags & 0x1000) {
            gOamBuffer[n].affineParam = -0x4000 / sx;
            gOamBuffer[n + 1].affineParam = 0;
        } else {
            gOamBuffer[n].affineParam = 0x4000 / sx;
            gOamBuffer[n + 1].affineParam = 0;
        }
        if (flags & 0x2000) {
            gOamBuffer[n + 2].affineParam = 0;
            gOamBuffer[n + 3].affineParam = -0x4000 / sy;
        } else {
            gOamBuffer[n + 3].affineParam = 0x4000 / sy;
            gOamBuffer[n + 2].affineParam = 0;
        }
    } else {
        if (flags & 0x1000) {
            gOamBuffer[n].affineParam = -0x400000 / gUnk_03005048;
            gOamBuffer[n + 1].affineParam = 0;
        } else {
            gOamBuffer[n].affineParam = 0x400000 / gUnk_03005048;
            gOamBuffer[n + 1].affineParam = 0;
        }
        if (flags & 0x2000) {
            gOamBuffer[n + 2].affineParam = 0;
            gOamBuffer[n + 3].affineParam = -0x400000 / gUnk_03005048;
        } else {
            gOamBuffer[n + 3].affineParam = 0x400000 / gUnk_03005048;
            gOamBuffer[n + 2].affineParam = 0;
        }
    }
}

struct RotateSrc {
    u8 filler0[0x18];
    u16 angle;
};

// Rotates (*x, *y) by p->angle (1024 steps per turn); the table is Q14 sin, cos at +0x100.
static void rotate_vector_2d(s32 *x, s32 *y, struct RotateSrc *p) {
    s32 c = gUnk_080750E0[(p->angle & 0x3FF) + 0x100];
    s32 s = gUnk_080750E0[p->angle & 0x3FF];
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
