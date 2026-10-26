#include "global.h"

void sub_08044CDC(u32 a) {
    switch (a) {
    case 0:
        sub_08064A74();
        break;
    case 1:
        sub_08064A94();
        break;
    case 2:
        sub_08064AB4();
        break;
    case 3:
        sub_08064AD4();
        break;
    }
}

u32 dma3_copy_or_decompress(const u32 *src, void *dst) {
    u32 hdr = *src;
    u32 size = hdr >> 8;

    if (((hdr << 24) >> 28) == 1) {
        LZ77UnCompWram(src, dst);
    } else {
        vu32 *dma;

        CpuCopy16(src, dst, size / 2);
        dma = (vu32 *)REG_ADDR_DMA3;
        dma[0] = (u32)src + size / 2;
        dma[1] = (u32)dst + size / 2;
        dma[2] = 0x80000000 | (size / 2 / 2);
        dma[2];
    }
    return size;
}

u32 sub_08044D64(u32 *dst, const u32 *src, u32 n) {
    while (n > 3) {
        *dst++ = *src++;
        n -= 4;
    }
    return n;
}

u32 sub_08044D78(u16 *dst, const u16 *src, u32 n) {
    while (n > 1) {
        *dst++ = *src++;
        n -= 2;
    }
    return n;
}

void sub_08044D90(u8 *dst, const u8 *src, u32 n) {
    while (n != 0) {
        *dst++ = *src++;
        n--;
    }
}

void set_oam_sprite_shape_size(u8 *oam, s32 h, s32 w) {
    if (h > w) {
        oam[1] = (oam[1] & 0x3F) | 0x80;
        if (h == 8)
            oam[3] = oam[3] & 0x3F;
        else if (h == 64)
            oam[3] |= 0xC0;
        else if (w == 8)
            oam[3] = (oam[3] & 0x3F) | 0x40;
        else
            oam[3] = (oam[3] & 0x3F) | 0x80;
    } else if (h < w) {
        oam[1] = (oam[1] & 0x3F) | 0x40;
        if (w == 8)
            oam[3] = oam[3] & 0x3F;
        else if (w == 64)
            oam[3] |= 0xC0;
        else if (h == 8)
            oam[3] = (oam[3] & 0x3F) | 0x40;
        else
            oam[3] = (oam[3] & 0x3F) | 0x80;
    } else {
        oam[1] = oam[1] & 0x3F;
        if (h == 8)
            oam[3] = oam[3] & 0x3F;
        else if (h == 16)
            oam[3] = (oam[3] & 0x3F) | 0x40;
        else if (h == 32)
            oam[3] = (oam[3] & 0x3F) | 0x80;
        else
            oam[3] |= 0xC0;
    }
}

u32 sub_08044E64(s32 shape, s32 size) {
    u32 dims = 0;

    switch (shape) {
    case 0:
        switch (size) {
        case 0:
            dims = 0x00080008;
            break;
        case 0x40000000:
            dims = 0x00100010;
            break;
        case (s32)0x80000000:
            dims = 0x00200020;
            break;
        case (s32)0xC0000000:
            dims = 0x00400040;
            break;
        }
        break;
    case 0x4000:
        switch (size) {
        case 0:
            dims = 0x00080010;
            break;
        case 0x40000000:
            dims = 0x00080020;
            break;
        case (s32)0x80000000:
            dims = 0x00100020;
            break;
        case (s32)0xC0000000:
            dims = 0x00200040;
            break;
        }
        break;
    case 0x8000:
        switch (size) {
        case 0:
            dims = 0x00100008;
            break;
        case 0x40000000:
            dims = 0x00200008;
            break;
        case (s32)0x80000000:
            dims = 0x00200010;
            break;
        case (s32)0xC0000000:
            dims = 0x00400020;
            break;
        }
        break;
    }
    return dims;
}

#include "keys.h"

void dma_load_sprite_tiles(const u32 *src, u16 tile, void *buf, u32 useCpu) {
    if (src != NULL) {
        u32 size = dma3_copy_or_decompress(src, buf);

        if (useCpu)
            CpuSet(buf, (void *)(0x06010000 + tile * 32), ((size / 4) & 0x1FFFFF) | 0x04000000);
        else
            DmaSet(0, buf, 0x06010000 + tile * 32, (size >> 2) | 0x94000000);
    }
}

void copy_sprite_tiles_to_vram(u8 *dst, u8 *src, s32 shape, s32 size, s32 rows, s32 cols, s32 bpp) {
    u16 dim[2];
    u32 hw;
    s32 i, j, k;
    u8 *rowStart;
    register u8 *colStart asm("r8"); // pinned: the original swaps dst / colStart (r9 / r8)

    hw = sub_08044E64(shape, size);
    dim[0] = hw >> 16;
    dim[1] = hw;
    dim[0] >>= 3;
    dim[1] >>= 3;
    dim[1] = Div(0x40, 2 - bpp) * dim[1];
    for (i = 0; i < rows; i++) {
        rowStart = src;
        for (j = 0; j < cols; j++) {
            colStart = src;
            for (k = 0; k < dim[0]; k++) {
                CpuSet(src, dst, (dim[1] >> 2) | 0x04000000);
                src += dim[1] * cols;
                dst += dim[1];
            }
            src = colStart + dim[1];
        }
        src = rowStart + dim[0] * dim[1] * cols;
    }
}

void decompress_and_load_sprite_tiles(const u32 *src, s32 shape, s32 size, s32 rows, s32 cols, s32 bpp, u16 tile,
                                      u32 unused, u8 *buf, u32 useCpu) {
    if (src != NULL) {
        u32 n = dma3_copy_or_decompress(src, buf);
        u8 *out = buf + n;

        copy_sprite_tiles_to_vram(out, buf, shape, size, rows, cols, bpp);
        if (useCpu)
            CpuSet(out, (void *)(0x06010000 + tile * 32), ((n / 4) & 0x1FFFFF) | 0x04000000);
        else
            DmaSet(0, out, 0x06010000 + tile * 32, (n >> 2) | 0x94000000);
    }
}

// Local struct (new): byte-wise view of struct SpriteDesc; the u8 bitfields are needed to match
// (the header's u32 bitfields change the code).
struct SpriteDesc8 {
    u8 bpp : 4;
    u8 shape : 2;
    u8 size : 2;
    u8 w : 4;
    u8 h : 4;
    u16 unk2;
};

// Local view of struct SpriteAnchor with the x / y / attribute bitfields.
struct SpriteAnchorFull {
    u8 filler0[2];
    s16 x;
    u16 y;
    s8 unk6;
    u8 affineMode : 2;
    u8 objMode : 2;
};

u32 setup_oam_sprite_entries(struct OamData *oams, void *tiles, void *pal, const struct SpriteDesc *desc,
                             const struct SpriteAnchor *anchor, u8 palNum, u16 tile) {
    const struct SpriteDesc8 *d;
    u16 dims[2];
    u32 n;
    u8 i, j;

#define DESC ((const struct SpriteDesc8 *)desc)
#define oam ((struct OamFull *)oams)
#define a ((const struct SpriteAnchorFull *)anchor)
    n = sub_08044E64(DESC->shape << 14, DESC->size << 30);
    dims[0] = n >> 16;
    dims[1] = n;
    n = dims[0] * dims[1];
    if (DESC->bpp == 0)
        n >>= 1;
    n = n * DESC->w * DESC->h;
    // the copy (assigned here, not at the top) puts the hoisted desc word in the matching spill slot
    d = DESC;
    decompress_and_load_sprite_tiles(tiles, d->shape << 14, DESC->size << 30, d->w, DESC->h, DESC->bpp, tile, n,
                                     (u8 *)0x02030000, 1);
#undef DESC
    if (pal != NULL)
        CpuSet(pal, (void *)(0x05000200 + palNum * 32), 0x10);
    n = (dims[0] >> 3) * (dims[1] >> 3);
    for (i = 0; i < d->w; i++) {
        for (j = 0; j < d->h; j++) {
            oam->y = a->y + dims[0] * i;
            oam->affineMode = a->affineMode;
            oam->objMode = a->objMode;
            oam->mosaic = 0;
            oam->bpp = d->bpp;
            oam->shape = d->shape;
            oam->x = a->x + dims[1] * j;
            oam->matrixNum = 0;
            oam->hFlip = 0;
            oam->vFlip = 0;
            oam->size = d->size;
            oam->tileNum = tile;
            oam->priority = 0;
            oam->paletteNum = palNum;
            tile += n;
            oams++;
        }
    }
    return tile;
#undef oam
#undef a
}

u32 init_sprite_object_entry(struct SpriteOamList *obj, struct OamData *oams, void *b, void *c,
                             const struct SpriteDesc *desc, const struct SpriteAnchor *e, u8 f, u16 g) {
    obj->oams = oams;
    obj->unk4 = e;
    obj->w = desc->w;
    obj->h = desc->h;
    obj->depth = e->unk6;
    return setup_oam_sprite_entries(oams, b, c, desc, e, f, g);
}

void set_oam_sprite_tile_positions(struct SpriteOamList *obj, s16 y, s16 x, s16 depth) {
    u32 dims[2];
    u32 n;
    u16 i, j;
    struct OamBits *oam = (struct OamBits *)obj->oams;

    dims[0] = ((u8 *)oam)[1] >> 6;
    dims[1] = ((u8 *)oam)[3] >> 6;
    n = sub_08044E64(dims[0] << 14, dims[1] << 30);
    dims[0] = n >> 16;
    dims[1] = n & 0xFFFF;
    do {
        obj->depth = depth;
    } while (0);
    for (i = 0; i < obj->w; i++) {
        for (j = 0; j < obj->h; j++) {
            oam->y = y;
            {
                s32 t = x;
                oam->x = t;
            }
            x += dims[1];
            oam++;
        }
        x -= obj->h * dims[1];
        y += dims[0];
    }
}

void setup_sprite_from_oam_descriptor(const u32 *src, const struct SpriteDesc *desc, u16 tile, u32 useCpu) {
    u16 dims[2];
    u32 n;
    const struct SpriteDesc8 *d = (const struct SpriteDesc8 *)desc;

    n = sub_08044E64(d->shape << 14, d->size << 30);
    dims[0] = n >> 16;
    dims[1] = n;
    n = dims[0] * dims[1];
    if (d->bpp == 0)
        n >>= 1;
    n = n * d->w * d->h;
    decompress_and_load_sprite_tiles(src, d->shape << 14, d->size << 30, d->w, d->h, d->bpp, tile, n, (u8 *)0x02030000,
                                     useCpu);
}

u16 binary_search_sorted_table(struct SortEntry *arr, u16 n, u16 key) {
    u16 lo, hi, mid = 0;
    s16 v;

    if (n != 0) {
        lo = 0;
        hi = n - 1;
        mid = (lo + hi) >> 1;
        while (mid != lo && mid != hi) {
            v = arr[mid].unk6;
            if (v == (s16)key)
                break;
            if (v < (s16)key)
                lo = mid;
            if (v > (s16)key)
                hi = mid;
            mid = (lo + hi) >> 1;
        }
        while (mid < n && (s16)arr[mid].unk6 <= (s16)key)
            mid++;
    }
    return mid;
}

struct OamFull *sorted_array_insert_shift(struct OamFull *arr, u16 n, u16 shift, s16 key) {
    struct OamFull *dst;
    s32 k;
    u16 m;

    m = n;
    n = m - 1;
    if (m != 0) {
        dst = &arr[n + shift];
        arr = &arr[n];
        k = key;
    loop:
        if ((s16)arr->affineParam > k) {
            do {
                *dst = *arr;
                if (n == 0)
                    arr--;
                else {
                    n--;
                    arr--;
                    dst--;
                    goto loop;
                }
            } while (0);
        }
        arr++;
    }
    return arr;
}

u16 copy_oam_entries_with_priority(struct SpriteOamList *list, struct OamData *dst, u16 slot, u16 end) {
    u16 i;

    for (i = 0; i < list->w * list->h && slot < end; i++, slot++) {
        *(struct OamData *)&((struct OamBits *)dst)[slot] = list->oams[i];
        ((struct OamBits *)dst)[slot].affineParam = list->depth;
        if (list->depth > 300)
            ((struct OamBits *)dst)[slot].priority = 3;
        else if (list->depth > 200)
            ((struct OamBits *)dst)[slot].priority = 2;
        else if (list->depth > 100)
            ((struct OamBits *)dst)[slot].priority = 1;
    }
    return slot;
}

// K&R: pal is a u8 here, but callers pass it sign-extended (see the prototype).
u16 copy_sprite_oam_entries(list, dst, slot, pal, end, flip)
struct SpriteOamList *list;
struct OamFull *dst;
u16 slot;
u8 pal;
u16 end;
u8 flip;
{
    u16 i;
    u32 n = list->w * list->h;

    dst = sorted_array_insert_shift(dst, slot, n, list->depth);
    for (i = 0; i < n && slot < end; dst++, slot++, i++) {
        *(struct OamData *)dst = list->oams[i];
        dst->paletteNum += (s8)pal;
        dst->hFlip = flip & 1;
        dst->vFlip = (flip >> 1) % 2;
        dst->affineParam = list->depth;
        if (list->depth > 300)
            dst->priority = 3;
        else if (list->depth > 200)
            dst->priority = 2;
        else if (list->depth > 100)
            dst->priority = 1;
    }
    return slot;
}

// The same with the affine matrix number (flags & 7) and the flips (flags bits 3, 4).
u16 sub_08045794(list, dst, slot, pal, end, flags)
struct SpriteOamList *list;
struct OamFull *dst;
u16 slot;
u8 pal;
u16 end;
u32 flags;
{
    u16 i;
    u32 n = list->w * list->h;

    dst = sorted_array_insert_shift(dst, slot, n, list->depth);
    for (i = 0; i < n && slot < end; dst++, slot++, i++) {
        *(struct OamData *)dst = list->oams[i];
        dst->paletteNum += (s8)pal;
        dst->affineParam = list->depth;
        dst->matrixNum = flags;
        dst->hFlip = (flags >> 3) & 1;
        dst->vFlip = (flags >> 4) & 1;
        if (list->depth > 300)
            dst->priority = 3;
        else if (list->depth > 200)
            dst->priority = 2;
        else if (list->depth > 100)
            dst->priority = 1;
    }
    return slot;
}

void sub_0804589C(struct SpriteOamBatch *batch, struct SpriteOamList **buf) {
    batch->lists = buf;
    batch->count = 0;
}

void sub_080458A4(struct SpriteOamBatch *batch, struct SpriteOamList *list, u16 depth) {
    list->depth = depth;
    batch->lists[batch->count] = list;
    batch->count++;
}

u16 batch_copy_oam_entries(struct SpriteOamBatch *batch, struct OamData *dst, u16 end) {
    u16 n = 0;
    u16 count = batch->count;
    u16 i;

    for (i = 0; i < count; i++) {
        n += copy_oam_entries_with_priority(batch->lists[i], dst, n, end);
        if (n >= end)
            break;
    }
    return n;
}

u16 sub_08045908(struct SpriteOamBatch *batch, struct OamData *dst, u16 end) {
    u16 count = batch->count;
    u16 n = 0;
    u16 i, j;

    for (i = 0; i < count; i++) {
        for (j = i + 1; j < count; j++) {
            struct SpriteOamList *a = batch->lists[i];
            struct SpriteOamList *b = batch->lists[j];
            if (a->depth > b->depth) {
                batch->lists[i] = b;
                batch->lists[j] = a;
            }
        }
        n += copy_oam_entries_with_priority(batch->lists[i], dst, n, end);
        if (n >= end)
            break;
    }
    return n;
}

struct DepthEntry {
    u32 unk0;
    s16 unk4;
    s16 depth;
};

void sub_080459A4(struct DepthEntry *arr, u16 lo, u16 n) {
    s32 i, j;
    struct DepthEntry *p, *q;

    if (n > lo) {
        p = &arr[lo];
        for (i = lo; i < n - 1; p++, i++) {
            q = p;
            for (j = i; j < n; q++, j++) {
                if (p->depth > q->depth) {
                    struct DepthEntry t = *p;
                    *p = *q;
                    *q = t;
                }
            }
        }
    }
}

void copy_oam_affine_params(struct OamData *oam, u16 *affine) {
    s32 i;

    for (i = 31; i >= 0; i--) {
        oam->affineParam = *affine;
        affine++;
        oam++;
        oam->affineParam = *affine;
        affine++;
        oam++;
        oam->affineParam = *affine;
        affine++;
        oam++;
        oam->affineParam = *affine;
        affine++;
        oam++;
    }
}

u32 sub_08045A40(s32 y, s32 x) {
    u32 ret = 0;

    if (y > -0x40 && x > -0x20 && y <= 0x9F && x <= 0xEF)
        ret = 1;
    return ret;
}

u16 copy_sprite_oam_with_vflip(void *a, void *b, u16 c, u32 unused, s8 d, u8 f) {
    return copy_sprite_oam_entries(a, b, c, d, 0x80, f);
}

void sub_08045A8C(struct SpriteOamList *obj, s16 a, s16 b, s32 mode) {
    if (mode != 0) {
        if (mode == 1) {
            a += ((struct OamBits *)obj->oams)->y;
            b += ((struct OamBits *)obj->oams)->x;
        } else {
            a += (s16)obj->unk4->unk4;
            b += (s16)obj->unk4->unk2;
        }
    }
    set_oam_sprite_tile_positions(obj, a, b, obj->depth);
}

u16 render_sprite_if_visible(struct SpriteOamList *list, void *dst, u16 slot, s16 y, s16 x, u16 depth, u8 pal,
                             u8 flip) {
    u16 n = slot;

    if (sub_08045A40(y, x)) {
        set_oam_sprite_tile_positions(list, y, x, depth);
        n = copy_sprite_oam_entries(list, dst, slot, (s8)pal, 0x80, flip);
    }
    return n;
}

// The same plus a scale / flip affine matrix (pa = +-scale, pb = pc = 0, pd = scale) at affine[k * 4].
u16 sub_08045B68(struct SpriteOamList *list, void *dst, u16 slot, s16 y, s16 x, u16 depth, u8 pal, u8 neg, u16 scale,
                 u16 *affine, u32 k) {
    u16 n = slot;

    if (sub_08045A40(y, x)) {
        set_oam_sprite_tile_positions(list, y, x, depth);
        n = sub_08045794(list, dst, slot, (s8)pal, 0x80, k);
        if (affine != NULL) {
            k *= 4;
            if (neg)
                affine[k] = -scale;
            else
                affine[k] = scale;
            k++;
            affine[k] = 0;
            k++;
            affine[k] = 0;
            k++;
            affine[k] = scale;
        }
    }
    return n;
}

// The same plus a rotation matrix (ObjAffineSet, scale 0x100, rotation -angle).
u16 sub_08045C30(struct SpriteOamList *list, void *dst, u16 slot, s16 y, s16 x, u16 depth, u8 pal, u16 angle,
                 u16 *affine, u32 k) {
    struct ObjAffineDstData d;
    u16 n = slot;

    if (sub_08045A40(y, x)) {
        set_oam_sprite_tile_positions(list, y, x, depth);
        n = sub_08045794(list, dst, slot, (s8)pal, 0x80, k);
        if (affine != NULL) {
            struct ObjAffineSrcData src = {0x100, 0x100, 0x10000 - angle};

            d = gUnk_080ABBEC;
            ObjAffineSet(&src, &d, 1, 2);
            k *= 4;
            affine[k] = d.pa;
            k++;
            affine[k] = d.pb;
            k++;
            affine[k] = d.pc;
            k++;
            affine[k] = d.pd;
        }
    }
    return n;
}

void sub_08045D1C(struct Unk_03002414 *work) {
    work->unk1096 = 0;
    work->unk1097 = 0;
}

u16 init_oam_sprite_entry(struct OamFull *oam, struct SpriteNodeDesc *desc, u8 pal, u16 tile) {
    u16 dims[2];
    u16 n;

    oam->y = 0;
    oam->affineMode = desc->affineMode;
    oam->objMode = desc->objMode;
    oam->mosaic = 0;
    oam->bpp = desc->bpp;
    oam->shape = 0;
    oam->x = 0;
    oam->matrixNum = 0;
    oam->hFlip = desc->hFlip;
    oam->vFlip = desc->vFlip;
    oam->size = 0;
    oam->tileNum = tile;
    oam->priority = 2;
    oam->paletteNum = pal + desc->paletteNum;
    oam->affineParam = 0;
    dims[0] = desc->width;
    if (desc->wDiv > 1)
        dims[0] = Div(dims[0], desc->wDiv);
    dims[1] = desc->height;
    if (desc->hDiv > 1)
        dims[1] = Div(dims[1], desc->hDiv);
    set_oam_sprite_shape_size((u8 *)oam, dims[0], dims[1]);
    n = (dims[0] >> 3) * (dims[1] >> 3);
    if (desc->bpp)
        n *= 2;
    return n;
}

// Loads the OBJ tiles of a sprite tree (and the palette of the list's first node) into VRAM via gDecompressBuffer +
// 0x800.
u32 load_sprite_tree_recursive(struct SpriteNodeDesc **nodes, struct SpriteTileRef *list, u8 node, u8 pal,
                               struct SpriteNodeOam *oams, u16 *tile, u32 alt) {
    u32 total = 0;
    s32 key = node; // compared as (u8)key
    struct SpriteNodeDesc *desc = nodes[node];
    u8 frame = 0;
    u32 affine = 0;
    u32 size = 0;
    struct SpriteNodeOam *obj;
    s32 i;

    if (list != NULL) {
        for (i = 0; list[i].node != 0; i++) {
            struct SpriteTileRef v = list[i];

            if ((u8)key == v.node) {
                frame = (v.frame + (alt & v.alt)) << 1;
                if (gUnk_03000440.unk96)
                    affine = 0;
                else
                    affine = v.affine;
                size = 1;
                if (i == 0 && desc->frames[frame + 1] != NULL) {
                    size = 0x20;
                    CpuSet(desc->frames[frame + 1], (void *)(OBJ_PLTT + (desc->paletteNum + pal) * 32), 0x10);
                    CpuSet(desc->frames[frame + 1], (u8 *)0x02030400 + (desc->paletteNum + pal) * 32, 0x10);
                }
                break;
            }
        }
    } else {
        size = 1;
    }
    if (size != 0 && desc->frames[frame] != NULL) {
        size = dma3_copy_or_decompress(desc->frames[frame], (void *)0x02030800);
        if (size != 0)
            CpuCopy16((void *)0x02030800, (void *)(0x06010000 + *tile * 32), size);
        obj = &oams[node];
        *tile += init_oam_sprite_entry(&obj->oam, desc, pal, *tile);
        if (gUnk_03000440.unk96)
            obj->oam.affineMode = 0;
        else
            obj->oam.affineMode = affine;
        total += size;
    }
    if (nodes[node]->child != 0)
        total += load_sprite_tree_recursive(nodes, list, nodes[node]->child, pal, oams, tile, alt);
    if (nodes[node]->sibling != 0)
        total += load_sprite_tree_recursive(nodes, list, nodes[node]->sibling, pal, oams, tile, alt);
    return total;
}

void load_sprite_tiles_by_table(struct SpriteNodeDesc **nodes, struct SpriteNodeOam *oams, struct SpriteTileRef *list,
                                u8 node, u8 k) {
    struct SpriteNodeDesc *desc = nodes[node];

    if (list != NULL) {
        while (list->node) {
            if (node == list->node) {
                s32 size = dma3_copy_or_decompress(desc->frames[list->frame * 2], (void *)0x02030800);
                if (size != 0)
                    CpuCopy16((void *)0x02030800, (void *)(0x06010000 + oams[k].oam.tileNum * 32), size);
                return;
            }
            list++;
        }
    }
}

// guess: builds a Medabot part sprite (4 part trees, tile base 0x160) into work and copies its OAM / affine out;
// like setup_scene_bg_layers_and_sprites without the per-side layer state
u8 sub_080460B0(struct Unk_03002414 *work, u16 *affine, u32 side, struct OamData *oam, u16 tile, u8 *parts, u8 pal,
                u8 x, u8 y, u32 alt) {
    struct SpriteTileRef buf[32];
    struct SpriteNodeOam oams[130];
    struct Unk_08047414Padded obj;
    vu32 fill;
    u32 zero;
    u32 a, b, c, d;
    u16 base;
    s32 k;
    s16 depth;
    struct SpriteTileRef *dst;
    struct SpriteTileRef *src;
    struct SpriteTileRef *pa, *pb, *pc, *pd;

    depth = 0x32;
    zero = 0;
    a = parts[0];
    b = parts[1];
    c = parts[2];
    d = parts[3];
    custom_memset(buf, 0, sizeof(buf));
    custom_memset(oams, 0, sizeof(oams));
    custom_memset(&obj, 0, sizeof(obj));
    fill = zero;
    CpuFastSet((void *)&fill, work, 0x01000426);
    gUnk_03002414 = work;
    sub_08047414(&obj.o, (u8 *)work, (struct SpriteNodeDesc **)gUnk_083D1BF8, oams);
    gUnk_03002414->unk1094 = zero;
    gUnk_03002414->unk1095 = side;
    gUnk_03002414->unk1097 = zero;
    base = 0x160;
    gUnk_030052D0 = gUnk_0807ECA0;
    gUnk_030052B0 = gUnk_0807ECB8;
    gUnk_03005290 = gUnk_0807ECD0;
    gUnk_030052F0 = gUnk_0807ECE8;
    pa = gUnk_0807ED00[a];
    gUnk_030052D0.unk10 = pa->node;
    pb = gUnk_0807F4A0[b];
    gUnk_03005290.unk10 = pb->node;
    pc = gUnk_0807FC40[c];
    gUnk_030052B0.unk10 = pc->node;
    pd = gUnk_080803E0[d];
    gUnk_030052F0.unk10 = pd->node;
    tile = base + 0x140;
    load_sprite_tree_recursive(obj.o.nodes, pa, pa->node, pal, obj.o.oams, &tile, alt);
    tile = base + 0x1A0;
    load_sprite_tree_recursive(obj.o.nodes, pb, pb->node, pal, obj.o.oams, &tile, alt);
    tile = base + 0x1E0;
    load_sprite_tree_recursive(obj.o.nodes, pc, pc->node, pal, obj.o.oams, &tile, alt);
    tile = base + 0x220;
    load_sprite_tree_recursive(obj.o.nodes, pd, pd->node, pal, obj.o.oams, &tile, alt);
    if (alt != 0) {
        for (k = 0; gUnk_0807F4A0[b][k].node; k++) {
            if (!gUnk_0807F4A0[b][k].alt)
                load_sprite_tiles_by_table(obj.o.nodes, obj.o.oams, gUnk_0807FC40[b], gUnk_0807FC40[b][k].node,
                                           gUnk_0807F4A0[b][k].node);
        }
        for (k = 0; gUnk_0807FC40[c][k].node; k++) {
            if (!gUnk_0807FC40[c][k].alt)
                load_sprite_tiles_by_table(obj.o.nodes, obj.o.oams, gUnk_0807F4A0[c], gUnk_0807F4A0[c][k].node,
                                           gUnk_0807FC40[c][k].node);
        }
        toggle_bg_layer_visibility(a, b, c, d);
    }
    dst = buf;
    if (gUnk_030052D0.unk10)
        for (src = gUnk_0807ED00[a]; src->node;)
            *dst++ = *src++;
    if (gUnk_03005290.unk10)
        for (src = gUnk_0807F4A0[b]; src->node;)
            *dst++ = *src++;
    if (gUnk_030052B0.unk10)
        for (src = gUnk_0807FC40[c]; src->node;)
            *dst++ = *src++;
    if (gUnk_030052F0.unk10)
        for (src = gUnk_080803E0[d]; src->node;)
            *dst++ = *src++;
    render_sprite_node_recursive(&obj.o, buf, 1, x << 8, y << 8, depth, 0, alt);
    CpuSet(((struct Unk_03002414 *)obj.o.unk0)->unkB84, oam, gUnk_03002414->unk1094 << 2);
    CpuSet(((struct Unk_03002414 *)obj.o.unk0)->unkF8C, affine, 0x80);
    return gUnk_03002414->unk1094;
}

void render_sprite_node_recursive(struct Unk_08047414 *obj, struct SpriteTileRef *list, u8 node, s32 y, s32 x,
                                  s16 depth, s16 angle, u8 flip) {
    s32 oy = y;
    s32 ox = x;
    s16 rot;
    s16 z;
    struct SpriteNodeDesc *desc = obj->nodes[node];
    struct SpriteNodeOam *oam = &obj->oams[node];
    struct ObjAffineDstData d = gUnk_080ABBF4;
    struct ObjAffineSrcData src = {0x100, 0x100, -angle};
    s32 offx, offy;
    s32 dx, dy;
    u32 vis;
    u32 found;
    s32 i;
    struct OamFull *e;

    if (flip) {
        u8 m = gUnk_08081320[node];
        desc = obj->nodes[m];
        rot = obj->oams[m].unkC;
        offx = obj->oams[m].unk8;
        offy = obj->oams[m].unkA;
    } else {
        rot = oam->unkC;
        offx = oam->unk8;
        offy = oam->unkA;
    }
    z = depth + desc->unkE;
    if (z < 0)
        z = 0;
    dx = desc->unkC + (offx >> 8);
    dy = desc->unkD + (offy >> 8);
    ObjAffineSet(&src, &d, 1, 2);
    if (flip)
        src.rotation = -src.rotation;
    y += d.pb * dy + d.pd * dx;
    if (flip)
        x -= d.pa * dy + d.pc * dx;
    else
        x += d.pa * dy + d.pc * dx;

    if (gUnk_03000440.unk96)
        vis = 0;
    else
        vis = 1;
    if (list != NULL) {
        s32 key = node;
        found = 0;
        for (i = 0; list[i].node != 0; i++) {
            struct SpriteTileRef v = list[i];

            if ((u8)key == v.node) {
                if (gUnk_03000440.unk96)
                    vis = 0;
                else
                    vis = v.affine;
                found = 1;
                break;
            }
        }
    } else
        found = 1;
    if (found) {
        if (vis) {
            if (flip)
                src.rotation += rot;
            else
                src.rotation -= rot;
            ObjAffineSet(&src, &d, 1, 2);
            oam->oam.matrixNum = ((struct Unk_03002414 *)obj->unk0)->unk1095 & 7;
            oam->oam.hFlip = (u8)(((struct Unk_03002414 *)obj->unk0)->unk1095 & 8) >> 3;
            oam->oam.vFlip = (u8)(((struct Unk_03002414 *)obj->unk0)->unk1095 & 0x10) >> 4;
            dx = ((struct Unk_03002414 *)obj->unk0)->unk1095 * 4;
            if (flip) {
                d.pa = -d.pa;
                d.pb = -d.pb;
            }
            ((struct Unk_03002414 *)obj->unk0)->unkF8C[dx] = d.pa;
            dx++;
            ((struct Unk_03002414 *)obj->unk0)->unkF8C[dx] = d.pb;
            dx++;
            ((struct Unk_03002414 *)obj->unk0)->unkF8C[dx] = d.pc;
            dx++;
            ((struct Unk_03002414 *)obj->unk0)->unkF8C[dx] = d.pd;
            if (++((struct Unk_03002414 *)obj->unk0)->unk1095 > 0x1F)
                ((struct Unk_03002414 *)obj->unk0)->unk1095 = 0;
        }
        if (vis) {
            offx = desc->width >> 1;
            offy = desc->height >> 1;
            dx = desc->unk4 - offx;
            dy = desc->unk8 - offy;

            offx = y - (d.pb * dy + d.pd * dx + (offx << 8));
            offy = x - (d.pa * dy + d.pc * dx + (offy << 8));
        } else {
            offx = y - (desc->unk4 << 8);
            if (flip)
                offy = x - ((desc->height - desc->unk8) << 8);
            else
                offy = x - (desc->unk8 << 8);
        }
        while ((s8)gUnk_03002414->unk1094 < 0)
            ;
        e = sorted_array_insert_shift((struct OamFull *)gUnk_03002414->unkB84, gUnk_03002414->unk1094++, 1, z);
        *e = oam->oam;
        e->affineParam = z;
        if (!vis && flip)
            e->hFlip = 1;
        e->y = offx >> 8;
        e->x = (offy >> 8) & 0x3FF;
        if (depth > 0x17B)
            e->priority = 3;
        else if (depth > 0x117)
            e->priority = 2;
        else if (depth > 0xB3)
            e->priority = 1;
        else
            e->priority = 0;
    }
    if (obj->nodes[node]->child) {
        if (!vis)
            render_sprite_node_recursive(obj, list, obj->nodes[node]->child, y, x, z, 0, flip);
        else
            render_sprite_node_recursive(obj, list, obj->nodes[node]->child, y, x, z, (s16)rot + angle, flip);
    }
    if (obj->nodes[node]->sibling)
        render_sprite_node_recursive(obj, list, obj->nodes[node]->sibling, oy, ox, depth, angle, flip);
}

void load_sprite_animation_by_type(struct OamData *oam, struct Unk_08047414 *obj, u32 id, u32 kind, u32 x, u32 y,
                                   u32 tile, u32 pal, u32 e) {
    struct SpriteTileRef *list = NULL;
    u16 t;
    u32 slot = -(e & 2) >> 31;
    u32 j;

    switch ((s32)kind) {
    case 0:
        list = gUnk_0807ED00[id];
        t = 0x140;
        break;
    case 1:
        list = gUnk_0807F4A0[id];
        t = 0x1A0;
        break;
    case 2:
        list = gUnk_0807FC40[id];
        t = 0x1E0;
        break;
    case 3:
        list = gUnk_080803E0[id];
        t = 0x220;
        break;
    }

    if (!(e & 4)) {
        gUnk_03005308[slot].unk2C = (gUnk_03005308[slot].unk2C | 1) & ~8;
        gUnk_03005308[slot].unk28 = slot;
    } else if (gUnk_03005308[slot].unk2C & 2) {
        if (e & 2)
            t += 0x160;
        load_sprite_tree_recursive(obj->nodes, list, list->node, pal, obj->oams, &t, slot);
        if (slot) {
            switch (kind) {
            case 1:
                for (j = 0; gUnk_0807F4A0[id][j].node; j++) {
                    if (!gUnk_0807F4A0[id][j].alt)
                        load_sprite_tiles_by_table(obj->nodes, obj->oams, gUnk_0807FC40[id], gUnk_0807FC40[id][j].node,
                                                   gUnk_0807F4A0[id][j].node);
                }
                break;
            case 2:
                for (j = 0; gUnk_0807FC40[id][j].node; j++) {
                    if (!gUnk_0807FC40[id][j].alt)
                        load_sprite_tiles_by_table(obj->nodes, obj->oams, gUnk_0807F4A0[id], gUnk_0807F4A0[id][j].node,
                                                   gUnk_0807FC40[id][j].node);
                }
                break;
            }
        }
        gUnk_03005308[slot].unk2C &= ~2;
        gUnk_03005308[slot].unk2C |= 4;
        gUnk_03005308[slot].unk2C |= 8;
    } else if (gUnk_03005308[slot].unk2C & 8) {
        x -= obj->nodes[list->node]->unkC;
        y -= obj->nodes[list->node]->unkD;
        render_sprite_node_recursive(obj, list, list->node, x << 8, y << 8, tile, 0, slot);
    }
}

void toggle_bg_layer_visibility(s32 a, s32 b, s32 c, s32 d) {
    if (a >= 0)
        gUnk_030052D0.unkD = -gUnk_030052D0.unkD - 2;
    if (b >= 0)
        gUnk_03005290.unkD = -gUnk_03005290.unkD - 2;
    if (c >= 0)
        gUnk_030052B0.unkD = -gUnk_030052B0.unkD - 2;
    if (d >= 0)
        gUnk_030052F0.unkD = -gUnk_030052F0.unkD - 2;
}

void setup_scene_bg_layers_and_sprites(void *oam, struct Unk_08047414 *obj, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f,
                                       u32 g, u32 h, u32 i, u32 j) {
    u32 slot = j;
    u16 tile;
    u16 base;
    s32 k;
    struct SpriteTileRef *dst;
    struct SpriteTileRef *src;
    struct SpriteTileRef *pa, *pb, *pc, *pd;

    if (!(i & 4)) {
        if (gUnk_03000440.unk130)
            gUnk_03000440.unk131 = 1;
        gUnk_03005308[slot].unk2C = (gUnk_03005308[slot].unk2C | 1) & ~8;
        gUnk_03005308[slot].unk4 = a;
        gUnk_03005308[slot].unk8 = b;
        gUnk_03005308[slot].unkC = c;
        gUnk_03005308[slot].unk10 = d;
        gUnk_03005308[slot].unk28 = slot;
    } else if (gUnk_03005308[slot].unk2C & 2) {
        base = 0;
        if (i & 2)
            base = 0x160;
        gUnk_030052D0 = gUnk_0807ECA0;
        gUnk_030052B0 = gUnk_0807ECB8;
        gUnk_03005290 = gUnk_0807ECD0;
        gUnk_030052F0 = gUnk_0807ECE8;
        a = gUnk_03005308[slot].unk4;
        b = gUnk_03005308[slot].unk8;
        c = gUnk_03005308[slot].unkC;
        d = gUnk_03005308[slot].unk10;
        j = gUnk_03005308[slot].unk28;
        if ((s32)a < 0) {
            gUnk_030052D0.unk10 = 0;
            gUnk_03005290.unk10 = 0;
            gUnk_030052B0.unk10 = 0;
        } else {
            pa = gUnk_0807ED00[a];
            gUnk_030052D0.unk10 = pa->node;
            pb = gUnk_0807F4A0[b];
            gUnk_03005290.unk10 = pb->node;
            pc = gUnk_0807FC40[c];
            gUnk_030052B0.unk10 = pc->node;
            pd = gUnk_080803E0[d];
            gUnk_030052F0.unk10 = pd->node;
            tile = base + 0x140;
            load_sprite_tree_recursive(obj->nodes, pa, pa->node, h, obj->oams, &tile, j);
            tile = base + 0x1A0;
            load_sprite_tree_recursive(obj->nodes, pb, pb->node, h, obj->oams, &tile, j);
            tile = base + 0x1E0;
            load_sprite_tree_recursive(obj->nodes, pc, pc->node, h, obj->oams, &tile, j);
            tile = base + 0x220;
            load_sprite_tree_recursive(obj->nodes, pd, pd->node, h, obj->oams, &tile, j);
            if (slot != 0) {
                for (k = 0; gUnk_0807F4A0[b][k].node; k++) {
                    if (!gUnk_0807F4A0[b][k].alt)
                        load_sprite_tiles_by_table(obj->nodes, obj->oams, gUnk_0807FC40[b], gUnk_0807FC40[b][k].node,
                                                   gUnk_0807F4A0[b][k].node);
                }
                for (k = 0; gUnk_0807FC40[c][k].node; k++) {
                    if (!gUnk_0807FC40[c][k].alt)
                        load_sprite_tiles_by_table(obj->nodes, obj->oams, gUnk_0807F4A0[c], gUnk_0807F4A0[c][k].node,
                                                   gUnk_0807FC40[c][k].node);
                }
                toggle_bg_layer_visibility(a, b, c, d);
            }
        }
        obj->layers[slot][0] = gUnk_030052D0;
        obj->layers[slot][1] = gUnk_03005290;
        obj->layers[slot][2] = gUnk_030052B0;
        obj->layers[slot][3] = gUnk_030052F0;
        gUnk_03005308[slot].unk2C = (gUnk_03005308[slot].unk2C & ~2) | 4;
        gUnk_03005308[slot].unk2C |= 8;
    } else if (gUnk_03005308[slot].unk2C & 8) {
        struct SpriteTileRef buf[32];

        custom_memset(buf, 0, sizeof(buf));
        gUnk_03000440.unk131 = 0;
        a = gUnk_03005308[slot].unk4;
        b = gUnk_03005308[slot].unk8;
        c = gUnk_03005308[slot].unkC;
        d = gUnk_03005308[slot].unk10;
        gUnk_030052D0 = obj->layers[slot][0];
        gUnk_03005290 = obj->layers[slot][1];
        gUnk_030052B0 = obj->layers[slot][2];
        gUnk_030052F0 = obj->layers[slot][3];
        dst = buf;
        if (gUnk_030052D0.unk10)
            for (src = gUnk_0807ED00[a]; src->node;)
                *dst++ = *src++;
        if (gUnk_03005290.unk10)
            for (src = gUnk_0807F4A0[b]; src->node;)
                *dst++ = *src++;
        if (gUnk_030052B0.unk10)
            for (src = gUnk_0807FC40[c]; src->node;)
                *dst++ = *src++;
        if (gUnk_030052F0.unk10)
            for (src = gUnk_080803E0[d]; src->node;)
                *dst++ = *src++;
        render_sprite_node_recursive(obj, buf, 1, e << 8, f << 8, g, 0, j);
    }
}

void update_anim_object_flags(void) {
    s32 i;

    for (i = 0; i < 2; i++) {
        u32 v = gUnk_03005308[i].unk2C;
        if (v & 1) {
            v &= ~1;
            v |= 2;
            gUnk_03005308[i].unk2C = v;
        } else if (!(v & 2)) {
            if (v & 8) {
                if (v & 4) {
                    v &= ~4;
                    gUnk_03005308[i].unk2C = v;
                }
            }
        }
    }
}

// Unused: loads the sprite tree of one part (kind: 0 head, 1 right arm, 2 left arm, 3 legs) and, for the
// arms, the tiles of the other arm's nodes.
void sub_0804725C(u32 unused0, struct Unk_08047414 *obj, s32 kind, s32 idx, u32 unused4, u32 pal, u32 side, u32 alt) {
    u16 tile;
    u16 base;
    struct SpriteTileRef *e;
    s32 i;

    base = 0;
    if (side == 2)
        base = 0x160;
    switch (kind) {
    case 0: {
        struct SpriteTileRef *t;

        tile = base + 0x140;
        load_sprite_tree_recursive(obj->nodes, t = gUnk_0807ED00[idx], t->node, pal, obj->oams, &tile, alt);
        break;
    }
    case 1:
        tile = base + 0x1A0;
        load_sprite_tree_recursive(obj->nodes, e = gUnk_0807F4A0[idx], e->node, pal, obj->oams, &tile, alt);
        if (alt) {
            for (i = 0; gUnk_0807F4A0[idx][i].node; i++) {
                if (!gUnk_0807F4A0[idx][i].alt)
                    load_sprite_tiles_by_table(obj->nodes, obj->oams, gUnk_0807FC40[idx], gUnk_0807FC40[idx][i].node,
                                               gUnk_0807F4A0[idx][i].node);
            }
        }
        break;
    case 2:
        tile = base + 0x1E0;
        load_sprite_tree_recursive(obj->nodes, e = gUnk_0807FC40[idx], e->node, pal, obj->oams, &tile, alt);
        if (alt) {
            for (i = 0; gUnk_0807FC40[idx][i].node; i++) {
                if (!gUnk_0807FC40[idx][i].alt)
                    load_sprite_tiles_by_table(obj->nodes, obj->oams, gUnk_0807F4A0[idx], gUnk_0807F4A0[idx][i].node,
                                               gUnk_0807FC40[idx][i].node);
            }
        }
        break;
    case 3: {
        struct SpriteTileRef *t;

        tile = base + 0x220;
        load_sprite_tree_recursive(obj->nodes, t = gUnk_080803E0[idx], t->node, pal, obj->oams, &tile, alt);
        break;
    }
    }
}

void sub_08047414(struct Unk_08047414 *obj, u8 *buf, struct SpriteNodeDesc **nodes, struct SpriteNodeOam *oams) {
    obj->unk0 = buf;
    obj->nodes = nodes;
    obj->oams = oams;
    buf[0x1094] = 0;
}

// Keeps `x + k` as one term (C's `p - (x - 0x10000)` gets folded to `(p + 0x10000) - x`).
static inline s32 wrap(s32 v, s32 k) {
    return v + k;
}

s32 interpolate_entity_positions(struct InterpEnt *e, s16 *pos, s8 *off, u8 *tbl, u8 unused, u8 frame, u8 idx,
                                 s32 count, s32 stride) {
    s32 done = 0;
    u8 end;
    struct InterpCand c[3];
    s32 rem, i, p;

    pos += idx;
    off += idx * 2;
    if (tbl != NULL) {
        end = tbl[idx];
        for (i = 1; i < count; i++, pos += stride, off += stride * 2) {
            if (frame < end) {
                rem = end - frame;
                p = *pos;
                c[0].val = p - e[i].unkC;
                c[1].val = p - wrap(e[i].unkC, -0x10000);
                c[2].val = p - wrap(e[i].unkC, 0x10000);
                c[0].abs = c[0].val;
                c[1].abs = c[1].val;
                c[2].abs = c[2].val;
                if (c[0].abs < 0)
                    c[0].abs = -c[0].abs;
                if (c[1].abs < 0)
                    c[1].abs = -c[1].abs;
                if (c[2].abs < 0)
                    c[2].abs = -c[2].abs;
                if (c[0].abs > c[1].abs) {
                    if (c[1].abs > c[2].abs)
                        p = c[2].val;
                    else
                        p = c[1].val;
                } else {
                    if (c[0].abs > c[2].abs)
                        p = c[2].val;
                    else
                        p = c[0].val;
                }
                e[i].unkC += Div(p, rem);
                if (off != NULL) {
                    e[i].unk8 += Div((off[0] << 8) - e[i].unk8, rem);
                    e[i].unkA += Div((off[1] << 8) - e[i].unkA, rem);
                }
            } else {
                e[i].unkC = *pos;
                if (off != NULL) {
                    e[i].unk8 = off[0] << 8;
                    e[i].unkA = off[1] << 8;
                }
                done++;
            }
        }
    }
    return done;
}

void nullsub_08047570(void) {}

void sub_08047574(void) {
    sub_080496C8((u8 *)&gUnk_03005310, 0x3C);
    sub_080496C8((u8 *)&gUnk_030057A0, 0x38);
    sub_080496C8((u8 *)&gUnk_03006D14, 4);
    sub_080496C8((u8 *)&gUnk_030057DC, 4);
    sub_080496C8((u8 *)&gUnk_0300534C, 4);
    sub_080496C8((u8 *)gUnk_030055A0, 0x200);
    sub_080496C8((u8 *)gUnk_03006D40, 0x200);
    sub_080496C8((u8 *)&gUnk_03006F40, 0x34);
    sub_080496C8((u8 *)&gUnk_03006D38, 8);
    sub_080496C8((u8 *)&gUnk_03006D20, 0x10);
    sub_080496C8((u8 *)&gUnk_030057D8, 4);
    sub_080496C8((u8 *)&gMapScriptData, 4);
    sub_080496C8((u8 *)&gUnk_03005350, 0x240);
    sub_080496C8((u8 *)&gUnk_03006D30, 4);
    sub_080496C8((u8 *)&gUnk_030064A0, 0x874);
}

void sub_0804763C(void) {
    gUnk_083D1F84[gGameState]();
}

void sub_0804765C(u32 a) {
    switch (a) {
    case 0:
        gUnk_03005310.unk39 = gUnk_03000440.unk9C;
        if (gUnk_030057E0.unkC88 != 0) {
            gGameMode = 1;
            gGameState = 1;
            gGameSubState = 5;
        } else {
            gGameMode = 1;
            gGameState = 1;
            gGameSubState = 13;
        }
        break;
    case 1:
        gGameMode = 1;
        gGameState = 2;
        gGameSubState = 0;
        break;
    }
}

void dispatch_by_index_0476e8(u32 idx) {
    switch (idx) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 12:
        break;
    case 4:
        gGameMode = 1;
        gGameState = 1;
        gGameSubState = 0x10;
        return;
    case 5:
        gGameMode = 1;
        gGameState = 1;
        gGameSubState = 0x20;
        return;
    case 6:
        gGameMode = 1;
        gGameState = 2;
        gGameSubState = 8;
        return;
    case 7:
        gUnk_03006D20.unkC = 7;
        break;
    case 8:
        gUnk_03006D20.unkC = 8;
        break;
    case 10:
        sub_08047574();
        sub_080496C8((u8 *)&gUnk_030057E0, 0xCC0);
        gUnk_03000588 = 1;
        gGameMode = 1;
        gGameState = 1;
        gGameSubState = 0;
        return;
    case 11:
        sub_08047574();
        gUnk_030057E0.unkC88 = 0;
        gUnk_030057E0.unkC89 = 0;
        gUnk_03000588 = 1;
        gGameMode = 1;
        gGameState = 1;
        gGameSubState = 10;
        return;
    case 9:
        gUnk_03000588 = 1;
        break;
    default:
        return;
    }
    gGameMode = 1;
    gGameState = 1;
    gGameSubState = 5;
}

void sub_08047850(s32 mode) {
    if (mode > 3)
        return;
    if (mode < 0)
        return;
    gGameMode = 1;
    gGameState = 1;
    gGameSubState = 5;
}

// Runtime: id 4 when leaving the shop (07_shop, from dispatch_and_increment_state).
void switch_game_mode(u32 a, u32 b) {
    switch (a) {
    case 0x20:
        gUnk_030057E0.unkC2D = 1;
        gGameMode = 0;
        gGameState = 6;
        gGameSubState = 0;
        break;
    case 0x21:
        gUnk_030057E0.unkC2D = 0;
        gGameMode = 0;
        gGameState = 6;
        gGameSubState = 0;
        break;
    case 0x40:
        gGameMode = 0;
        gGameState = 1;
        gGameSubState = 0x10;
        break;
    case 0x41:
        gGameMode = 1;
        gGameState = 1;
        gGameSubState = 0x18;
        break;
    case 0x42:
        gGameMode = 1;
        gGameState = 1;
        gGameSubState = 0x1C;
        break;
    case 0x43:
        gGameMode = 1;
        gGameState = 1;
        gGameSubState = 0x28;
        break;
    case 0:
        gUnk_03000584 = 0;
        gGameMode = 2;
        gGameState = 0x12;
        gGameSubState = 0;
        break;
    case 1:
        gUnk_03000584 = 1;
        gGameMode = 2;
        gGameState = 0x12;
        gGameSubState = 0;
        break;
    case 2:
        gUnk_03000584 = 2;
        gGameMode = 2;
        gGameState = 0x12;
        gGameSubState = 0;
        break;
    case 3:
        gUnk_03002420 = b;
        gGameMode = 2;
        gGameState = 0xB;
        gGameSubState = 0;
        break;
    case 4:
        gGameMode = 2;
        gGameState = 0x15;
        gGameSubState = 0;
        break;
    case 5:
        gUnk_03000588 = 0;
        gGameMode = 2;
        gGameState = 0x14;
        gGameSubState = 0;
        break;
    case 6:
        gGameMode = 2;
        gGameState = 0x17;
        gGameSubState = 0;
        break;
    case 8:
        gGameMode = 2;
        gGameState = 0x16;
        gGameSubState = 0;
        break;
    case 0x10:
        gGameMode = 3;
        gGameState = 4;
        gGameSubState = 0;
        break;
    case 0x11:
        gGameMode = 3;
        gGameState = 5;
        gGameSubState = 0;
        break;
    case 0x12:
        gGameMode = 3;
        gGameState = 3;
        gGameSubState = 0;
        break;
    case 0x13:
        gGameMode = 3;
        gGameState = 6;
        gGameSubState = 0;
        break;
    }
}

void sub_08047BA8(u32 id) {
    play_sound_effect(id);
}

void sub_08047BB4(u32 id) {
    play_song(id);
}

void sub_08047BC0(u32 a) {
    sound_stop_all_with_fade_guard(a);
}

u32 sub_08047BCC(u32 idx) {
    return gUnk_083B6410[idx];
}

u32 sub_08047BDC(u32 idx) {
    return gUnk_083BA4D8[idx];
}

u32 sub_08047BEC(u32 a, u32 b) {
    const u32 *t = (const u32 *)gUnk_083BB9CC;
    return t[b * 4 + a];
}

void init_cursor_state(void) {
    sub_08047E4C();
    gBg0Scroll.x = 0;
    gBg0Scroll.y = 0;
    gUnk_030064A0.unk0 = 0;
    gUnk_030064A0.unk1 = 0;
}

u32 scene_transition_step_08047C24(u8 a, u8 b, u8 c, const void *text) {
    u32 ret = 0;

    switch (gUnk_030064A0.unk0) {
    case 0:
        if (gUnk_030064A0.unk1 == 0)
            text_window_init(a, b, c);
        else
            sub_0803FB0C();
        gUnk_030064A0.unk0++;
        break;
    case 1:
        if (run_message(text)) {
            gUnk_030064A0.unk0 = ret;
            gUnk_030064A0.unk1++;
            ret = 1;
        }
        break;
    }
    return ret;
}

void format_number_to_text_buffer(u32 slot, u32 n) {
    u8 buf[12];
    struct TextBufTable4 t = gUnk_080ABBFC;
    u8 *d = t.p[slot];
    s32 len = count_decimal_digits(n);
    s32 i;

    for (i = 0; i < len; i++)
        buf[i] = truncate_to_digit_count(n, len - 1 - i) + 0x35;
    memcpy_u8(buf, d, len);
    d[len] = 0xFE;
}

void copy_string_to_text_buffer(u32 slot, u32 str) {
    u8 *s = (u8 *)str;
    struct TextBufTable4 t = gUnk_080ABBFC;
    u8 *d = t.p[slot];
    s32 i;

    for (i = 0; i < 16 && *s != 0xFE; i++)
        *d++ = *s++;
    *d = 0xFE;
}

void sub_08047D24(u32 slot, u32 n) {
    u8 buf[12];
    struct TextBufTable4 t = gUnk_080ABBFC;
    divide_by_10000_b(t.p[slot], n);
}

u32 get_money(void) {
    return gMoney;
}

void add_money(u32 n) {
    gMoney += n;
    if (gMoney > 99999)
        gMoney = 99999;
}

void sub_money(u32 n) {
    s32 left = gMoney - n;

    if (left < 0)
        gMoney = 0;
    else
        gMoney = left;
}

u32 sub_08047D8C(u8 id) {
    return get_item_quantity_by_id(id);
}

u32 sub_08047D9C(u8 a, u8 b) {
    return sub_08042114(a, b);
}

u32 sub_08047DB0(u8 id) {
    return find_medal_slot_by_id(id);
}

void sub_08047DC0(u8 id, u8 n) {
    if (n == 0)
        n = 1;
    item_add_quantity(id, n);
}

void sub_08047DD8(u8 id, u8 n) {
    if (n == 0)
        n = 1;
    sub_08042318(id, n);
}

void sub_08047DF0(u8 a, u8 b, u8 n) {
    medapart_add_quantity(a, b, n);
}

void sub_08047E08(u8 a, u8 b, u8 n) {
    reduce_medapart_stat(a, b, n);
}

u32 sub_08047E20(u8 id) {
    return medal_add_by_id(id);
}

u32 sub_08047E30(void) {
    return team_is_full();
}

void sub_08047E3C(u8 id) {
    team_add_tinpet(id);
}

void sub_08047E4C(void) {}

u32 lookup_position_table_value(u8 id, u8 which) {
    u8 buf[16];
    s32 v;
    s32 match = check_position_table_match(id, which);

    if (match) {
        u32 found = 0;
        s32 i;
        struct Unk_030017A0 *p;

        for (i = 0, p = gUnk_030017A0; i <= 8; i++) {
            if (p->unk0 == 3) {
                switch (which) {
                case 0:
                    if (p->unk3 == id)
                        found = 1;
                    break;
                case 1:
                    if (p->unk4 == id)
                        found = 1;
                    break;
                case 2:
                    if (p->unk5 == id)
                        found = 1;
                    break;
                case 3:
                    if (p->unk6 == id)
                        found = 1;
                    break;
                }
            }
            if (found)
                break;
            p++;
        }
        load_part_data(gUnk_030017A0[i].unk6, 3, buf);
        v = buf[1] - 100;
        gUnk_03006D38.unk6 = gUnk_030017A0[i].unk1;
    }
    if (match)
        return v;
    return -1;
}

u32 check_position_table_match(u8 id, u8 which) {
    u32 found = 0;
    s32 i;
    struct Unk_030017A0 *p;

    for (i = 0, p = gUnk_030017A0; i <= 8; i++) {
        if (p->unk0 == 3) {
            switch (which) {
            case 0:
                if (p->unk3 == id)
                    found = 1;
                break;
            case 1:
                if (p->unk4 == id)
                    found = 1;
                break;
            case 2:
                if (p->unk5 == id)
                    found = 1;
                break;
            case 3:
                if (p->unk6 == id)
                    found = 1;
                break;
            }
        }
        if (found)
            break;
        p++;
    }
    return found;
}

s32 sub_08047F50(void) {
    s32 n = 0;
    struct Unk_030017A0 *p = gUnk_030017A0;
    s32 i;

    for (i = 8; i >= 0; i--) {
        if (p->unk0 == 3)
            n++;
        p++;
    }
    return n;
}

u32 sub_08047F70(u8 id) {
    u32 found = 0;
    s32 i;
    struct Unk_030017A0 *p;

    for (i = 0, p = gUnk_030017A0; i <= 8; i++) {
        if (p->unk0 == 3 && p->unk3 == id && p->unk4 == id && p->unk5 == id && p->unk6 == id)
            found = 1;
        if (found)
            break;
        p++;
    }
    return found;
}

void init_bg0_for_cursor(u32 mode) {
    REG_BG0CNT = 0x500;
    REG_DISPCNT = 0x1F60;
    open_choice_menu(mode, 0x16, 7);
    gUnk_030064A0.unk64 = 0;
}

u32 sub_08047FEC(void) {
    u32 ret = 0;
    struct Unk_030064A0 *m = &gUnk_030064A0;
    u8 *step = &m->unk64;

    switch (*step) {
    case 1:
        if (game_state_execute_handler_b() == 0)
            break;
    case 0:
        gUnk_03000440.unk1B = ret;
        (*step)++;
        break;
    case 2:
        ret = poll_choice_menu();
        break;
    }
    return ret;
}

u32 sub_0804803C(u32 arg) {
    u32 ret = 0;

    switch (arg) {
    case 0:
        ret = gUnk_083BEA90[0][gUnk_030057E0.unk7FE * 8 + 2];
        break;
    case 1:
        ret = gUnk_083BEA90[0][gUnk_030057E0.unk7FE * 8 + 3];
        break;
    }
    return ret;
}

u32 sub_08048088(u32 idx) {
    return gUnk_08484444[idx];
}

void update_battle_field_frame(void) {
    gBg1Scroll.x = gUnk_03005310.unk1E;
    gBg1Scroll.y = gUnk_03005310.unk26;
    gBg2Scroll.x = gUnk_03005310.unk20;
    gBg2Scroll.y = gUnk_03005310.unk28;
    gBg3Scroll.x = gUnk_03005310.unk22;
    gBg3Scroll.y = gUnk_03005310.unk2A;
    sub_080482C0();
    dma_load_battle_palettes();
    load_room_graphics();
    gUnk_030057E0.unkC36 = 0;
    animate_area_bg_tiles();
    load_map_npc_sprites(gUnk_030057E0.unkCBA);
    update_entity_sprites_on_screen();
    init_battle_field_setup();
    update_bg_scroll_offsets_a();
    init_battle_medaforce_sprite();
    update_bg_scroll_offsets_b();
    decompress_battle_tile_graphics();
    gUnk_030057E0.unkC4C = 1;
    update_battle_entity_status_chars();
}

void animate_area_bg_tiles(void) {
    const u8 *anim = gUnk_084096F4[gUnk_030057E0.unk7FE];
    u8 n = anim[0];
    u8 *src;

    if (gUnk_030057E0.unkC34 != 0 && anim[2] != 0) {
        if (gUnk_030057E0.unkC36 != 0) {
            gUnk_030057E0.unkC36--;
        } else {
            if (anim[gUnk_030057E0.unkC35 + 3] == 0xFF)
                gUnk_030057E0.unkC35 = 0;
            src = gUnk_030057DC + anim[gUnk_030057E0.unkC35 + 3] * n * 32;
            DmaSet(3, src, 0x06009020, 0x80000000 | (n << 4));
            gUnk_030057E0.unkC35++;
            gUnk_030057E0.unkC36 = 2;
        }
    }
}

s32 sub_080481C4(s32 t) {
    s32 u;
    if (t == 0)
        t = gUnk_083D29A6[gUnk_030057E0.unkC5C];
    else if (t <= 0xAF)
        ;
    else if (t <= 0xBF)
        ;
    else if (t <= 0xCF)
        ;
    else if (t <= 0xFE) {
        const u8 *tbl = gUnk_08414394[t - 0xD0];
        t = tbl[gUnk_030057E0.unkC38[t - 0xD0]];
    } else
        t = 0xFF;
    if (t != 0xFF && t > 0xBF)
        t = (t - 0xC0) * 2 + (u = gUnk_03006D38.unk6 + 0x28);
    return t;
}

void decompress_battle_tile_graphics(void) {
    s32 i = 0;
    u8 *dst = (u8 *)0x06010000;
    u32 t;

    while ((t = resolve_tile_from_battle_state(i)) != 0xFF) {
        if (gUnk_083F80F4[t] == NULL)
            t = 1;
        LZ77UnCompVram(gUnk_083F80F4[t], dst);
        dst += 0x900;
        i++;
    }
}

void decompress_terrain_tiles_to_vram(s32 arg) {
    s32 i;
    u8 *dst;
    const u8 *const *tbl;
    s32 t = sub_080481C4(arg);

    tbl = gUnk_083F80F4;
    dst = (u8 *)0x06010000;
    for (i = 11; i >= 0; i--) {
        if (tbl[t] == NULL)
            t = 1;
        LZ77UnCompVram(tbl[t], dst);
        dst += 0x900;
    }
}

void sub_080482C0(void) {
    const u16 *pal = gUnk_083F9BF4[gUnk_030057E0.unk7FE];

    if (pal != NULL) {
        DmaSet(3, pal, 0x0202FA00, 0x84000068);
    } else {
        DmaSet(3, gUnk_080AC5B4, 0x0202FA00, 0x84000008);
        DmaSet(3, gUnk_080AC654, 0x0202FA20, 0x84000008);
        DmaSet(3, gUnk_080AC6F4, 0x0202FA40, 0x84000008);
        DmaSet(3, gUnk_080AC794, 0x0202FA60, 0x84000008);
        DmaSet(3, gUnk_080AC5B4, 0x0202FA80, 0x84000008);
        DmaSet(3, gUnk_080AC5B4, 0x0202FAA0, 0x84000008);
        DmaSet(3, gUnk_080AC5B4, 0x0202FAC0, 0x84000008);
        DmaSet(3, gUnk_080AC834, 0x0202FAE0, 0x84000008);
        DmaSet(3, gUnk_080AC8D4, 0x0202FB00, 0x84000008);
    }
}

u8 sub_080483AC(void) {
    if (gUnk_030057E0.unkC30 == 0xFF)
        return gUnk_030057E0.unkC31;
    return gUnk_0847EB80[gUnk_030057E0.unk7FE];
}

// sub_080483AC returns its u8 widened: the original uses r0 untruncated here.
#define sub_080483AC() ((u32(*)(void))sub_080483AC)()

u32 dispatch_jump_table_29(u32 a, u32 b) {
    u32 t;
    u32 v;
    u32 w;

    switch (a) {
    case 0:
    case 10:
    case 12:
        if (gUnk_030057E0.unkC30 != 0xFF) {
            v = sub_080483AC();
            if (gUnk_030057E0.unkC30 != v) {
                gUnk_030057E0.unkC30 = v;
                sub_08047BB4(v);
            }
        }
        break;
    case 1:
        gUnk_030057E0.unkC30 = b;
        sub_08047BB4(b);
        break;
    case 2:
        gUnk_030057E0.unkC30 = 0;
        sub_08047BB4(0);
        break;
    case 3:
        if (gUnk_030057E0.unkC30 == 0xFF) {
            if (b & 0x80) {
                gUnk_030057E0.unkC31 = b & 0x7F;
                gUnk_030057E0.unkC30 |= 0xFF;
            }
            break;
        }
        if (!(b & 0x80)) {
            gUnk_030057E0.unkC31 = b & 0x7F;
            sub_08047BB4(b);
            gUnk_030057E0.unkC30 = 0xFF;
            break;
        }
        gUnk_030057E0.unkC31 = b & 0x7F;
        gUnk_030057E0.unkC30 |= 0xFF;
        break;
    case 4:
        t = gUnk_030057E0.unkC30;
        gUnk_030057E0.unkC30 = 0;
        v = sub_080483AC();
        if (t != v) {
            gUnk_030057E0.unkC30 = v;
            sub_08047BB4(v);
        } else
            gUnk_030057E0.unkC30 = v;
        break;
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 19:
    case 28:
        v = sub_080483AC();
        gUnk_030057E0.unkC30 = v;
        sub_08047BB4(v);
        break;
    case 11:
    case 13:
    case 14:
    case 15:
    case 21:
    case 22:
    case 26:
        if (gUnk_030057E0.unkC30 != 0xFF) {
            v = sub_080483AC();
            gUnk_030057E0.unkC30 = v;
            sub_08047BB4(v);
        } else
            sub_08047BB4(gUnk_030057E0.unkC31);
        break;
    case 23:
        if (gUnk_083D29B6[gUnk_03006D38.unk1 * 4])
            sub_08047BC0(0x1E);
        break;
    case 24:
        if (gUnk_083D29B6[gUnk_03006D38.unk1 * 4]) {
            w = gUnk_083D29B6[gUnk_03006D38.unk1 * 4 + 1];
            gUnk_030057E0.unkC30 = w;
            sub_08047BB4(w);
        }
        break;
    case 25:
        switch (gUnk_083D29B6[gUnk_03006D38.unk1 * 4 + 2]) {
        case 1:
            w = gUnk_083D29B6[gUnk_03006D38.unk1 * 4 + 3];
            gUnk_030057E0.unkC30 = w;
            sub_08047BB4(w);
            break;
        case 2:
            w = sub_080483AC();
            gUnk_030057E0.unkC30 = w;
            sub_08047BB4(w);
            break;
        }
        break;
    }
}

#undef sub_080483AC

u32 resolve_tile_from_battle_state(u32 arg) {
    return sub_080481C4(gUnk_08413514[gUnk_030057E0.unk7FE][arg]);
}

void dma_load_obj_palettes_08048664(void) {
    s32 i;
    u32 t;

    for (i = 0; (t = resolve_tile_from_battle_state(i)) != 0xFF; i++) {
        t = resolve_tile_from_battle_state(i);
        if (gUnk_083F8634[t] == NULL)
            t = 1;
        DmaSet(3, gUnk_083F8634[t], 0x05000200 + i * 0x20, 0x84000008);
    }
}

void dma_load_battle_palettes(void) {
    s32 i;
    u32 t;

    for (i = 0; (t = resolve_tile_from_battle_state(i)) != 0xFF; i++) {
        t = resolve_tile_from_battle_state(i);
        if (gUnk_083F8634[t] == NULL)
            t = 1;
        DmaSet(3, gUnk_083F8634[t], 0x0202F800 + i * 0x20, 0x84000008);
    }
    DmaSet(3, gUnk_085FA0E4, 0x0202F9C0, 0x84000008);
}

void dma_load_obj_palettes_08048730(s32 arg) {
    s32 i = 0;
    s32 t = sub_080481C4(arg);

    for (; i <= 11; i++) {
        if (gUnk_083F8634[t] == NULL)
            t = 1;
        DmaSet(3, gUnk_083F8634[t], 0x05000200 + i * 0x20, 0x84000008);
    }
}

void sub_0804877C(u8 idx) {
    u8 v = gUnk_083D2ADD[gUnk_03002C30[idx].unk30];

    if (v == 2)
        gUnk_03002C30[idx].unkB = 0xFF;
    else if (v == 1)
        gUnk_03002C30[idx].unkB = 0;
    else
        gUnk_03002C30[idx].unkB = 0x40;
}

void sub_080487AC(void) {
    vu16 *bldalpha;
    u16 v;

    REG_BLDCNT = 0x1F41;
    gUnk_03006F40.unkC = 12.0f;
    gUnk_03006F40.unk10 = 8.0f;
    bldalpha = &REG_BLDALPHA;
    v = 0x80C;
    *bldalpha = v;
}

void sub_080487E4(void) {
    vu16 *bldalpha;
    u16 v;

    REG_BLDCNT = 0xF40;
    gUnk_03006F40.unkC = 12.0f;
    gUnk_03006F40.unk10 = 10.0f;
    bldalpha = &REG_BLDALPHA;
    v = 0xA0C;
    *bldalpha = v;
}

void init_battle_sprite_entry_08048818(u8 slot, u16 a, u32 frame, u8 c, u8 d) {
    gUnk_03002C30[slot].unk0 = a;
    gUnk_03002C30[slot].unk32 = a;
    gUnk_03002C30[slot].unk6 = frame;
    gUnk_03002C30[slot].unkA = c;
    gUnk_03002C30[slot].unk1C = d;
}

void clear_battle_sprite_entry(u8 slot) {
    sub_080496C8((u8 *)&gUnk_03002C30[slot], 0x40);
    clear_entity_state(slot);
}

s32 count_decimal_digits(s32 n) {
    s32 i, j, p;

    if (n == 0)
        return 1;
    for (i = 0; i <= 9; i++) {
        p = 1;
        for (j = 0; j < i; j++)
            p *= 10;
        if (n / p == 0)
            break;
    }
    return i;
}

s32 truncate_to_digit_count(s32 n, u8 k) {
    s32 rem = n;
    register s32 i asm("r4") = 0; // pinned: the original allocates i before p / j
    s32 p, j;

    do {
        while (i < count_decimal_digits(n) - k && i != count_decimal_digits(n) - 1) {
            p = 1;
            j = 0;
            i++;
            while (j < count_decimal_digits(n) - i) {
                p *= 10;
                j++;
            }
            j = rem / p;
            rem -= p * j;
        }
    } while (0);
    if (k != 0)
        return j;
    return rem;
}

u32 sub_08048914(u32 a) {
    u32 r;

    switch (a) {
    case 0:
        if (gUnk_083D29EB[gUnk_030057E0.unk7FE] == 0xA) {
            r = 2;
            break;
        }
        r = 1;
        if (gUnk_030057E0.unkC5D & 0x20)
            r = 3;
        break;
    case 1:
    case 5:
    case 12:
    case 13:
    case 19:
    case 39:
    case 40:
        r = 1;
        if (gUnk_030057E0.unkC5D & 1)
            r = 3;
        else if ((u8)(gUnk_030057E0.unkC5C - 1) <= 1)
            r = 4;
        break;
    default:
        r = 0;
        break;
    }
    return r;
}

// Dead code (nothing calls it): BG2 affine matrix for gUnk_03005310 (guess).
void sub_08048A40(void) {
    const s16 *sine = gSineTable;
    struct Unk_03005310 *p = &gUnk_03005310;
    s32 a;

    p->unk8 = sub_08048B24(sine[a = p->unk36 + 0x40], divide_by_65536(p->unk32));
    p->unkA = sub_08048B24(sine[p->unk36], divide_by_65536(p->unk32));
    p->unkC = sub_08048B24(-sine[p->unk36], divide_by_65536(p->unk34));
    p->unkE = sub_08048B24(sine[a = p->unk36 + 0x40], divide_by_65536(p->unk34));
    p->unk10 = (120 - p->unk2C) * 256 - p->unk8 * 120 - p->unkA * 80;
    p->unk14 = (120 - p->unk2E) * 256 - p->unkC * 120 - p->unkE * 80;
}

s16 sub_08048B24(s16 a, s16 b) {
    s32 r = a * b;
    r /= 256;
    return r;
}

s16 fixed_point_divide(s16 a, s16 b) {
    return (a << 8) / b;
}

s16 divide_by_65536(s16 a) {
    s32 n = 0x10000;

    return n / a;
}

void sub_08048B6C(void) {
    struct Unk_03005310 *p = &gUnk_03005310;

    p->unk10 = 0;
    p->unk14 = 0;
    p->unk8 = 0x100;
    p->unkA = 0;
    p->unkC = 0;
    p->unkE = 0x100;
    p->unk30 = 0;
    p->unk32 = 0x100;
    p->unk34 = 0x100;
    p->unk36 = 0;
    p->unk2C = 0;
    p->unk2E = 0;
}

// Not called directly (hidden in the tail of sub_08048B6C). Guess: debug, B + D-pad scrolls BG1-3,
// RIGHT/LEFT step unk36 (0-255).
void sub_08048B94(void) {
    if (KEYS_LO(gHeldKeys) & 2) {
        if (KEYS_LO(gHeldKeys) & 0x40) {
            gUnk_03005310.unk26 -= 4;
            gUnk_03005310.unk28 -= 4;
            gUnk_03005310.unk2A -= 4;
        }
        if (KEYS_LO(gHeldKeys) & 0x80) {
            gUnk_03005310.unk26 += 4;
            gUnk_03005310.unk28 += 4;
            gUnk_03005310.unk2A += 4;
        }
        if (KEYS_LO(gHeldKeys) & 0x20) {
            gUnk_03005310.unk1E -= 4;
            gUnk_03005310.unk20 -= 4;
            gUnk_03005310.unk22 -= 4;
        }
        if (KEYS_LO(gHeldKeys) & 0x10) {
            gUnk_03005310.unk1E += 4;
            gUnk_03005310.unk20 += 4;
            gUnk_03005310.unk22 += 4;
        }
    }
    if (KEYS_LO(gHeldKeys) & 0x10)
        gUnk_03005310.unk36 = ++gUnk_03005310.unk36 & 0xFF;
    if (KEYS_LO(gHeldKeys) & 0x20)
        gUnk_03005310.unk36 = (gUnk_03005310.unk36 + 0xFF) & 0xFF;
}

// Not called directly (hidden in the tail of sub_08048B6C).
void sub_08048C5C(u16 *src, u16 *dst, s32 h, s32 w, s32 maxh, s32 pitch, s32 add) {
    s32 i, j;
    if (h > maxh)
        h = maxh;
    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++)
            *dst++ = *src++ + add;
        dst += pitch - w;
    }
}

// Copies a w x h tilemap (u16 entries, row pitch w) into a 64x64 BG screen (four 32x32 blocks), adding add.
void copy_tilemap_with_offset_08048CA4(const void *src, void *dst, s32 h, s32 w, s32 c, s32 d, s32 add) {
    s32 i, j, n;
    s32 rows;

    rows = 32;
    if (h < 32)
        rows = h;
    for (i = 0; i < rows; i++) {
        n = 32;
        if (w < 32)
            n = w;
        for (j = 0; j < n; j++)
            ((u16 *)dst)[i * 32 + j] = ((const u16 *)src)[w * i + j] + add;
        if (w > 31) {
            for (j = 0; j < w - 32; j++)
                ((u16 *)dst)[0x400 + i * 32 + j] = ((const u16 *)src)[w * i + 32 + j] + add;
        }
    }
    if (h > 31) {
        for (i = 0; i < h - 32; i++) {
            n = 32;
            if (w < 32)
                n = w;
            for (j = 0; j < n; j++)
                ((u16 *)dst)[0x800 + i * 32 + j] = ((const u16 *)src)[(i + 32) * w + j] + add;
            if (w > 31) {
                for (j = 0; j < w - 32; j++)
                    ((u16 *)dst)[0xC00 + i * 32 + j] = ((const u16 *)src)[(i + 32) * w + 32 + j] + add;
            }
        }
    }
}

// Expands a (h/2) x (w/2) map of 2x2 metatile ids (src) into a 64x64 BG screen at tile (x, y) (four 32x32 blocks).
#define MAP ((u16(*)[32])dst)
#define SRC(r, c) (((const u8 *)src) + (w / 2) * (r))[c]
void copy_tiles_to_bg_tilemap(const void *src, void *dst, s32 h, s32 w, s32 c, s32 d, s32 y, s32 x, s32 tile) {
    s32 i, j;
    s32 rows, cols;

    rows = h + y > 31 ? 32 : h;
    for (i = 0; i < rows; i++) {
        cols = w + x > 31 ? 32 : w;
        for (j = 0; j < cols; j++)
            build_bg_tile_entry(&MAP[i + y][j + x], SRC(i / 2, j / 2), tile, i % 2, j % 2, y % 2, x % 2);
        if (w > 31) {
            for (j = 0; j < w - 32; j++)
                build_bg_tile_entry(&MAP[i + y + 32][j + x], SRC(i / 2, j / 2 + 16), tile, i % 2, j % 2, y % 2, x % 2);
        }
    }
    if (h > 31) {
        for (i = 0; i < h - 32; i++) {
            cols = 32;
            if (w < 32)
                cols = w;
            for (j = 0; j < cols; j++)
                build_bg_tile_entry(&MAP[i + y + 64][j + x], SRC(i / 2 + 16, j / 2), tile, i % 2, j % 2, y % 2, x % 2);
            if (w > 31) {
                for (j = 0; j < w - 32; j++)
                    build_bg_tile_entry(&MAP[i + y + 96][j + x], SRC(i / 2 + 16, j / 2 + 16), tile, i % 2, j % 2, y % 2,
                                        x % 2);
            }
        }
    }
}
#undef SRC
#undef MAP

// Not called directly (hidden in the tail of copy_tiles_to_bg_tilemap). Writes one 2x2 metatile.
void sub_0804908C(u16 *dst, s32 pal, s32 tile) {
    s32 t = (pal + 1) * 4;
    s32 attr = (pal << 12) + tile;

    dst[0] = t | attr;
    dst[1] = (t + 1) | attr;
    dst[32] = (t + 2) | attr;
    dst[33] = (t + 3) | attr;
}
