// Sprite engine: DMA copies and LZ decompression of sprite tiles into VRAM, OAM shape/size setup, OAM entry
// copies (priority, flips, affine params), and the sprite trees (load_sprite_tree_recursive,
// render_sprite_node_recursive) used for scene layers and animations (setup_medabot_part_sprites).
// Used by the menus, battle and field scenes; talks to engine/oam and engine/decompress.

#include "global.h"

// guess: enters one of the link scenes (game mode 2, states 26 / 17 / 16 / 20) from the menus
void goto_link_scene(u32 a) {
    switch (a) {
    case 0:
        link_enter_handshake();
        break;
    case 1:
        link_enter_medal_trade();
        break;
    case 2:
        link_enter_medapart_trade();
        break;
    case 3:
        link_enter_menu();
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

// Word copy; returns the 0-3 bytes left over.
static u32 mem_copy32_partial(u32 *dst, const u32 *src, u32 n) {
    while (n > 3) {
        *dst++ = *src++;
        n -= 4;
    }
    return n;
}

// Halfword copy; returns the 0-1 byte left over.
static u32 mem_copy16_partial(u16 *dst, const u16 *src, u32 n) {
    while (n > 1) {
        *dst++ = *src++;
        n -= 2;
    }
    return n;
}

static void mem_copy8(u8 *dst, const u8 *src, u32 n) {
    while (n != 0) {
        *dst++ = *src++;
        n--;
    }
}

static void set_oam_sprite_shape_size(u8 *oam, s32 h, s32 w) {
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

// OAM attr0 shape / attr1 size bits -> height << 16 | width in pixels.
u32 oam_shape_size_dims(s32 shape, s32 size) {
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

static void dma_load_sprite_tiles(const u32 *src, u16 tile, void *buf, u32 useCpu) {
    if (src != NULL) {
        u32 size = dma3_copy_or_decompress(src, buf);

        if (useCpu)
            CpuSet(buf, (void *)(0x06010000 + tile * 32), ((size / 4) & 0x1FFFFF) | 0x04000000);
        else
            DmaSet(0, buf, 0x06010000 + tile * 32, (size >> 2) | 0x94000000);
    }
}

static void copy_sprite_tiles_to_vram(u8 *dst, u8 *src, s32 shape, s32 size, s32 rows, s32 cols, s32 bpp) {
    u16 dim[2];
    u32 hw;
    s32 i, j, k;
    u8 *rowStart;
    register u8 *colStart asm("r8"); // pinned: the original swaps dst / colStart (r9 / r8)

    hw = oam_shape_size_dims(shape, size);
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

static void decompress_and_load_sprite_tiles(const u32 *src, s32 shape, s32 size, s32 rows, s32 cols, s32 bpp, u16 tile,
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
    n = oam_shape_size_dims(DESC->shape << 14, DESC->size << 30);
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

static void set_oam_sprite_tile_positions(struct SpriteOamList *obj, s16 y, s16 x, s16 depth) {
    u32 dims[2];
    u32 n;
    u16 i, j;
    struct OamBits *oam = (struct OamBits *)obj->oams;

    dims[0] = ((u8 *)oam)[1] >> 6;
    dims[1] = ((u8 *)oam)[3] >> 6;
    n = oam_shape_size_dims(dims[0] << 14, dims[1] << 30);
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

static void setup_sprite_from_oam_descriptor(const u32 *src, const struct SpriteDesc *desc, u16 tile, u32 useCpu) {
    u16 dims[2];
    u32 n;
    const struct SpriteDesc8 *d = (const struct SpriteDesc8 *)desc;

    n = oam_shape_size_dims(d->shape << 14, d->size << 30);
    dims[0] = n >> 16;
    dims[1] = n;
    n = dims[0] * dims[1];
    if (d->bpp == 0)
        n >>= 1;
    n = n * d->w * d->h;
    decompress_and_load_sprite_tiles(src, d->shape << 14, d->size << 30, d->w, d->h, d->bpp, tile, n, (u8 *)0x02030000,
                                     useCpu);
}

static u16 binary_search_sorted_table(struct SortEntry *arr, u16 n, u16 key) {
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

static struct OamFull *sorted_array_insert_shift(struct OamFull *arr, u16 n, u16 shift, s16 key) {
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
static u16 copy_sprite_oam_entries(list, dst, slot, pal, end, flip)
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
static u16 copy_sprite_oam_entries_affine(list, dst, slot, pal, end, flags)
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

// A batch is a list of sprite objects copied to OAM together.
static void oam_batch_init(struct SpriteOamBatch *batch, struct SpriteOamList **buf) {
    batch->lists = buf;
    batch->count = 0;
}

static void oam_batch_add(struct SpriteOamBatch *batch, struct SpriteOamList *list, u16 depth) {
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

// Like batch_copy_oam_entries, sorting the lists by depth first.
static u16 batch_copy_oam_entries_sorted(struct SpriteOamBatch *batch, struct OamData *dst, u16 end) {
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

// Sorts arr[lo..n) by depth (exchange sort).
static void sort_depth_entries(struct DepthEntry *arr, u16 lo, u16 n) {
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

// True if a sprite at (x, y) can be visible (y in -63..159, x in -31..239).
static u32 sprite_pos_on_screen(s32 y, s32 x) {
    u32 ret = 0;

    if (y > -0x40 && x > -0x20 && y <= 0x9F && x <= 0xEF)
        ret = 1;
    return ret;
}

static u16 copy_sprite_oam_with_vflip(void *a, void *b, u16 c, u32 unused, s8 d, u8 f) {
    return copy_sprite_oam_entries(a, b, c, d, 0x80, f);
}

// Repositions a sprite object's OAM tiles: mode 0 absolute, 1 relative to its current position, 2 relative to
// its anchor.
void move_sprite_object(struct SpriteOamList *obj, s16 a, s16 b, s32 mode) {
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

static u16 render_sprite_if_visible(struct SpriteOamList *list, void *dst, u16 slot, s16 y, s16 x, u16 depth, u8 pal,
                                    u8 flip) {
    u16 n = slot;

    if (sprite_pos_on_screen(y, x)) {
        set_oam_sprite_tile_positions(list, y, x, depth);
        n = copy_sprite_oam_entries(list, dst, slot, (s8)pal, 0x80, flip);
    }
    return n;
}

// The same plus a scale / flip affine matrix (pa = +-scale, pb = pc = 0, pd = scale) at affine[k * 4].
static u16 render_sprite_if_visible_scaled(struct SpriteOamList *list, void *dst, u16 slot, s16 y, s16 x, u16 depth,
                                           u8 pal, u8 neg, u16 scale, u16 *affine, u32 k) {
    u16 n = slot;

    if (sprite_pos_on_screen(y, x)) {
        set_oam_sprite_tile_positions(list, y, x, depth);
        n = copy_sprite_oam_entries_affine(list, dst, slot, (s8)pal, 0x80, k);
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
u16 render_sprite_if_visible_rotated(struct SpriteOamList *list, void *dst, u16 slot, s16 y, s16 x, u16 depth, u8 pal,
                                     u16 angle, u16 *affine, u32 k) {
    struct ObjAffineDstData d;
    u16 n = slot;

    if (sprite_pos_on_screen(y, x)) {
        set_oam_sprite_tile_positions(list, y, x, depth);
        n = copy_sprite_oam_entries_affine(list, dst, slot, (s8)pal, 0x80, k);
        if (affine != NULL) {
            struct ObjAffineSrcData src = {0x100, 0x100, 0x10000 - angle};

            d = gAffineIdentityRotated;
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

// guess: unused; clears the two bytes after affineIdx, whose use is unknown
static void sprite_work_clear_spare(struct SpriteWork *work) {
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
                if (gGameWork.unk96)
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
        if (gGameWork.unk96)
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

static void load_sprite_tiles_by_table(struct SpriteNodeDesc **nodes, struct SpriteNodeOam *oams,
                                       struct SpriteTileRef *list, u8 node, u8 k) {
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

// guess: builds a Medabot sprite (4 part trees, tile base 0x160) into work and copies its OAM / affine out;
// like setup_medabot_part_sprites without the per-side layer state
u8 build_medabot_sprite(struct SpriteWork *work, u16 *affine, u32 side, struct OamData *oam, u16 tile, u8 *parts,
                        u8 pal, u8 x, u8 y, u32 alt) {
    struct SpriteTileRef buf[32];
    struct SpriteNodeOam oams[130];
    struct SpriteTreePadded obj;
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
    gSpriteWork = work;
    init_sprite_tree(&obj.o, (u8 *)work, (struct SpriteNodeDesc **)gMedabotSpriteNodeDescs, oams);
    gSpriteWork->oamCount = zero;
    gSpriteWork->affineIdx = side;
    gSpriteWork->unk1097 = zero;
    base = 0x160;
    gHeadPartLayer = gHeadPartLayerTemplate;
    gLeftArmPartLayer = gLeftArmPartLayerTemplate;
    gRightArmPartLayer = gRightArmPartLayerTemplate;
    gLegPartLayer = gLegPartLayerTemplate;
    pa = gHeadPartSpriteNodes[a];
    gHeadPartLayer.root_node = pa->node;
    pb = gRightArmPartSpriteNodes[b];
    gRightArmPartLayer.root_node = pb->node;
    pc = gLeftArmPartSpriteNodes[c];
    gLeftArmPartLayer.root_node = pc->node;
    pd = gLegPartSpriteNodes[d];
    gLegPartLayer.root_node = pd->node;
    tile = base + 0x140;
    load_sprite_tree_recursive(obj.o.nodes, pa, pa->node, pal, obj.o.oams, &tile, alt);
    tile = base + 0x1A0;
    load_sprite_tree_recursive(obj.o.nodes, pb, pb->node, pal, obj.o.oams, &tile, alt);
    tile = base + 0x1E0;
    load_sprite_tree_recursive(obj.o.nodes, pc, pc->node, pal, obj.o.oams, &tile, alt);
    tile = base + 0x220;
    load_sprite_tree_recursive(obj.o.nodes, pd, pd->node, pal, obj.o.oams, &tile, alt);
    if (alt != 0) {
        for (k = 0; gRightArmPartSpriteNodes[b][k].node; k++) {
            if (!gRightArmPartSpriteNodes[b][k].alt)
                load_sprite_tiles_by_table(obj.o.nodes, obj.o.oams, gLeftArmPartSpriteNodes[b],
                                           gLeftArmPartSpriteNodes[b][k].node, gRightArmPartSpriteNodes[b][k].node);
        }
        for (k = 0; gLeftArmPartSpriteNodes[c][k].node; k++) {
            if (!gLeftArmPartSpriteNodes[c][k].alt)
                load_sprite_tiles_by_table(obj.o.nodes, obj.o.oams, gRightArmPartSpriteNodes[c],
                                           gRightArmPartSpriteNodes[c][k].node, gLeftArmPartSpriteNodes[c][k].node);
        }
        toggle_bg_layer_visibility(a, b, c, d);
    }
    dst = buf;
    if (gHeadPartLayer.root_node)
        for (src = gHeadPartSpriteNodes[a]; src->node;)
            *dst++ = *src++;
    if (gRightArmPartLayer.root_node)
        for (src = gRightArmPartSpriteNodes[b]; src->node;)
            *dst++ = *src++;
    if (gLeftArmPartLayer.root_node)
        for (src = gLeftArmPartSpriteNodes[c]; src->node;)
            *dst++ = *src++;
    if (gLegPartLayer.root_node)
        for (src = gLegPartSpriteNodes[d]; src->node;)
            *dst++ = *src++;
    render_sprite_node_recursive(&obj.o, buf, 1, x << 8, y << 8, depth, 0, alt);
    CpuSet(((struct SpriteWork *)obj.o.unk0)->oamBuf, oam, gSpriteWork->oamCount << 2);
    CpuSet(((struct SpriteWork *)obj.o.unk0)->affineBuf, affine, 0x80);
    return gSpriteWork->oamCount;
}

void render_sprite_node_recursive(struct SpriteTree *obj, struct SpriteTileRef *list, u8 node, s32 y, s32 x, s16 depth,
                                  s16 angle, u8 flip) {
    s32 oy = y;
    s32 ox = x;
    s16 rot;
    s16 z;
    struct SpriteNodeDesc *desc = obj->nodes[node];
    struct SpriteNodeOam *oam = &obj->oams[node];
    struct ObjAffineDstData d = gAffineIdentity;
    struct ObjAffineSrcData src = {0x100, 0x100, -angle};
    s32 offx, offy;
    s32 dx, dy;
    u32 vis;
    u32 found;
    s32 i;
    struct OamFull *e;

    if (flip) {
        u8 m = gMirroredPartNode[node];
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

    if (gGameWork.unk96)
        vis = 0;
    else
        vis = 1;
    if (list != NULL) {
        s32 key = node;
        found = 0;
        for (i = 0; list[i].node != 0; i++) {
            struct SpriteTileRef v = list[i];

            if ((u8)key == v.node) {
                if (gGameWork.unk96)
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
            oam->oam.matrixNum = ((struct SpriteWork *)obj->unk0)->affineIdx & 7;
            oam->oam.hFlip = (u8)(((struct SpriteWork *)obj->unk0)->affineIdx & 8) >> 3;
            oam->oam.vFlip = (u8)(((struct SpriteWork *)obj->unk0)->affineIdx & 0x10) >> 4;
            dx = ((struct SpriteWork *)obj->unk0)->affineIdx * 4;
            if (flip) {
                d.pa = -d.pa;
                d.pb = -d.pb;
            }
            ((struct SpriteWork *)obj->unk0)->affineBuf[dx] = d.pa;
            dx++;
            ((struct SpriteWork *)obj->unk0)->affineBuf[dx] = d.pb;
            dx++;
            ((struct SpriteWork *)obj->unk0)->affineBuf[dx] = d.pc;
            dx++;
            ((struct SpriteWork *)obj->unk0)->affineBuf[dx] = d.pd;
            if (++((struct SpriteWork *)obj->unk0)->affineIdx > 0x1F)
                ((struct SpriteWork *)obj->unk0)->affineIdx = 0;
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
        while ((s8)gSpriteWork->oamCount < 0)
            ;
        e = sorted_array_insert_shift((struct OamFull *)gSpriteWork->oamBuf, gSpriteWork->oamCount++, 1, z);
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

void load_sprite_animation_by_type(struct OamData *oam, struct SpriteTree *obj, u32 id, u32 kind, u32 x, u32 y,
                                   u32 tile, u32 pal, u32 e) {
    struct SpriteTileRef *list = NULL;
    u16 t;
    u32 slot = -(e & 2) >> 31;
    u32 j;

    switch ((s32)kind) {
    case 0:
        list = gHeadPartSpriteNodes[id];
        t = 0x140;
        break;
    case 1:
        list = gRightArmPartSpriteNodes[id];
        t = 0x1A0;
        break;
    case 2:
        list = gLeftArmPartSpriteNodes[id];
        t = 0x1E0;
        break;
    case 3:
        list = gLegPartSpriteNodes[id];
        t = 0x220;
        break;
    }

    if (!(e & 4)) {
        gMedabotSpriteSlots[slot].flags = (gMedabotSpriteSlots[slot].flags | 1) & ~8;
        gMedabotSpriteSlots[slot].side = slot;
    } else if (gMedabotSpriteSlots[slot].flags & 2) {
        if (e & 2)
            t += 0x160;
        load_sprite_tree_recursive(obj->nodes, list, list->node, pal, obj->oams, &t, slot);
        if (slot) {
            switch (kind) {
            case 1:
                for (j = 0; gRightArmPartSpriteNodes[id][j].node; j++) {
                    if (!gRightArmPartSpriteNodes[id][j].alt)
                        load_sprite_tiles_by_table(obj->nodes, obj->oams, gLeftArmPartSpriteNodes[id],
                                                   gLeftArmPartSpriteNodes[id][j].node,
                                                   gRightArmPartSpriteNodes[id][j].node);
                }
                break;
            case 2:
                for (j = 0; gLeftArmPartSpriteNodes[id][j].node; j++) {
                    if (!gLeftArmPartSpriteNodes[id][j].alt)
                        load_sprite_tiles_by_table(obj->nodes, obj->oams, gRightArmPartSpriteNodes[id],
                                                   gRightArmPartSpriteNodes[id][j].node,
                                                   gLeftArmPartSpriteNodes[id][j].node);
                }
                break;
            }
        }
        gMedabotSpriteSlots[slot].flags &= ~2;
        gMedabotSpriteSlots[slot].flags |= 4;
        gMedabotSpriteSlots[slot].flags |= 8;
    } else if (gMedabotSpriteSlots[slot].flags & 8) {
        x -= obj->nodes[list->node]->unkC;
        y -= obj->nodes[list->node]->unkD;
        render_sprite_node_recursive(obj, list, list->node, x << 8, y << 8, tile, 0, slot);
    }
}

void toggle_bg_layer_visibility(s32 a, s32 b, s32 c, s32 d) {
    if (a >= 0)
        gHeadPartLayer.mirror_pos = -gHeadPartLayer.mirror_pos - 2;
    if (b >= 0)
        gRightArmPartLayer.mirror_pos = -gRightArmPartLayer.mirror_pos - 2;
    if (c >= 0)
        gLeftArmPartLayer.mirror_pos = -gLeftArmPartLayer.mirror_pos - 2;
    if (d >= 0)
        gLegPartLayer.mirror_pos = -gLegPartLayer.mirror_pos - 2;
}

void setup_medabot_part_sprites(void *oam, struct SpriteTree *obj, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g,
                                u32 h, u32 i, u32 j) {
    u32 slot = j;
    u16 tile;
    u16 base;
    s32 k;
    struct SpriteTileRef *dst;
    struct SpriteTileRef *src;
    struct SpriteTileRef *pa, *pb, *pc, *pd;

    if (!(i & 4)) {
        if (gGameWork.inCloseup)
            gGameWork.skipOamHigh = 1;
        gMedabotSpriteSlots[slot].flags = (gMedabotSpriteSlots[slot].flags | 1) & ~8;
        gMedabotSpriteSlots[slot].head = a;
        gMedabotSpriteSlots[slot].right_arm = b;
        gMedabotSpriteSlots[slot].left_arm = c;
        gMedabotSpriteSlots[slot].legs = d;
        gMedabotSpriteSlots[slot].side = slot;
    } else if (gMedabotSpriteSlots[slot].flags & 2) {
        base = 0;
        if (i & 2)
            base = 0x160;
        gHeadPartLayer = gHeadPartLayerTemplate;
        gLeftArmPartLayer = gLeftArmPartLayerTemplate;
        gRightArmPartLayer = gRightArmPartLayerTemplate;
        gLegPartLayer = gLegPartLayerTemplate;
        a = gMedabotSpriteSlots[slot].head;
        b = gMedabotSpriteSlots[slot].right_arm;
        c = gMedabotSpriteSlots[slot].left_arm;
        d = gMedabotSpriteSlots[slot].legs;
        j = gMedabotSpriteSlots[slot].side;
        if ((s32)a < 0) {
            gHeadPartLayer.root_node = 0;
            gRightArmPartLayer.root_node = 0;
            gLeftArmPartLayer.root_node = 0;
        } else {
            pa = gHeadPartSpriteNodes[a];
            gHeadPartLayer.root_node = pa->node;
            pb = gRightArmPartSpriteNodes[b];
            gRightArmPartLayer.root_node = pb->node;
            pc = gLeftArmPartSpriteNodes[c];
            gLeftArmPartLayer.root_node = pc->node;
            pd = gLegPartSpriteNodes[d];
            gLegPartLayer.root_node = pd->node;
            tile = base + 0x140;
            load_sprite_tree_recursive(obj->nodes, pa, pa->node, h, obj->oams, &tile, j);
            tile = base + 0x1A0;
            load_sprite_tree_recursive(obj->nodes, pb, pb->node, h, obj->oams, &tile, j);
            tile = base + 0x1E0;
            load_sprite_tree_recursive(obj->nodes, pc, pc->node, h, obj->oams, &tile, j);
            tile = base + 0x220;
            load_sprite_tree_recursive(obj->nodes, pd, pd->node, h, obj->oams, &tile, j);
            if (slot != 0) {
                for (k = 0; gRightArmPartSpriteNodes[b][k].node; k++) {
                    if (!gRightArmPartSpriteNodes[b][k].alt)
                        load_sprite_tiles_by_table(obj->nodes, obj->oams, gLeftArmPartSpriteNodes[b],
                                                   gLeftArmPartSpriteNodes[b][k].node,
                                                   gRightArmPartSpriteNodes[b][k].node);
                }
                for (k = 0; gLeftArmPartSpriteNodes[c][k].node; k++) {
                    if (!gLeftArmPartSpriteNodes[c][k].alt)
                        load_sprite_tiles_by_table(obj->nodes, obj->oams, gRightArmPartSpriteNodes[c],
                                                   gRightArmPartSpriteNodes[c][k].node,
                                                   gLeftArmPartSpriteNodes[c][k].node);
                }
                toggle_bg_layer_visibility(a, b, c, d);
            }
        }
        obj->layers[slot][0] = gHeadPartLayer;
        obj->layers[slot][1] = gRightArmPartLayer;
        obj->layers[slot][2] = gLeftArmPartLayer;
        obj->layers[slot][3] = gLegPartLayer;
        gMedabotSpriteSlots[slot].flags = (gMedabotSpriteSlots[slot].flags & ~2) | 4;
        gMedabotSpriteSlots[slot].flags |= 8;
    } else if (gMedabotSpriteSlots[slot].flags & 8) {
        struct SpriteTileRef buf[32];

        custom_memset(buf, 0, sizeof(buf));
        gGameWork.skipOamHigh = 0;
        a = gMedabotSpriteSlots[slot].head;
        b = gMedabotSpriteSlots[slot].right_arm;
        c = gMedabotSpriteSlots[slot].left_arm;
        d = gMedabotSpriteSlots[slot].legs;
        gHeadPartLayer = obj->layers[slot][0];
        gRightArmPartLayer = obj->layers[slot][1];
        gLeftArmPartLayer = obj->layers[slot][2];
        gLegPartLayer = obj->layers[slot][3];
        dst = buf;
        if (gHeadPartLayer.root_node)
            for (src = gHeadPartSpriteNodes[a]; src->node;)
                *dst++ = *src++;
        if (gRightArmPartLayer.root_node)
            for (src = gRightArmPartSpriteNodes[b]; src->node;)
                *dst++ = *src++;
        if (gLeftArmPartLayer.root_node)
            for (src = gLeftArmPartSpriteNodes[c]; src->node;)
                *dst++ = *src++;
        if (gLegPartLayer.root_node)
            for (src = gLegPartSpriteNodes[d]; src->node;)
                *dst++ = *src++;
        render_sprite_node_recursive(obj, buf, 1, e << 8, f << 8, g, 0, j);
    }
}

void update_anim_object_flags(void) {
    s32 i;

    for (i = 0; i < 2; i++) {
        u32 v = gMedabotSpriteSlots[i].flags;
        if (v & 1) {
            v &= ~1;
            v |= 2;
            gMedabotSpriteSlots[i].flags = v;
        } else if (!(v & 2)) {
            if (v & 8) {
                if (v & 4) {
                    v &= ~4;
                    gMedabotSpriteSlots[i].flags = v;
                }
            }
        }
    }
}

// Unused: loads the sprite tree of one part (kind: 0 head, 1 right arm, 2 left arm, 3 legs) and, for the
// arms, the tiles of the other arm's nodes.
static void load_medabot_part_sprite_tree(u32 unused0, struct SpriteTree *obj, s32 kind, s32 idx, u32 unused4, u32 pal,
                                          u32 side, u32 alt) {
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
        load_sprite_tree_recursive(obj->nodes, t = gHeadPartSpriteNodes[idx], t->node, pal, obj->oams, &tile, alt);
        break;
    }
    case 1:
        tile = base + 0x1A0;
        load_sprite_tree_recursive(obj->nodes, e = gRightArmPartSpriteNodes[idx], e->node, pal, obj->oams, &tile, alt);
        if (alt) {
            for (i = 0; gRightArmPartSpriteNodes[idx][i].node; i++) {
                if (!gRightArmPartSpriteNodes[idx][i].alt)
                    load_sprite_tiles_by_table(obj->nodes, obj->oams, gLeftArmPartSpriteNodes[idx],
                                               gLeftArmPartSpriteNodes[idx][i].node,
                                               gRightArmPartSpriteNodes[idx][i].node);
            }
        }
        break;
    case 2:
        tile = base + 0x1E0;
        load_sprite_tree_recursive(obj->nodes, e = gLeftArmPartSpriteNodes[idx], e->node, pal, obj->oams, &tile, alt);
        if (alt) {
            for (i = 0; gLeftArmPartSpriteNodes[idx][i].node; i++) {
                if (!gLeftArmPartSpriteNodes[idx][i].alt)
                    load_sprite_tiles_by_table(obj->nodes, obj->oams, gRightArmPartSpriteNodes[idx],
                                               gRightArmPartSpriteNodes[idx][i].node,
                                               gLeftArmPartSpriteNodes[idx][i].node);
            }
        }
        break;
    case 3: {
        struct SpriteTileRef *t;

        tile = base + 0x220;
        load_sprite_tree_recursive(obj->nodes, t = gLegPartSpriteNodes[idx], t->node, pal, obj->oams, &tile, alt);
        break;
    }
    }
}

// Binds a sprite tree to its work buffer, node descriptors and per-node OAM, with no OAM entries yet.
void init_sprite_tree(struct SpriteTree *obj, u8 *buf, struct SpriteNodeDesc **nodes, struct SpriteNodeOam *oams) {
    obj->unk0 = buf;
    obj->nodes = nodes;
    obj->oams = oams;
    buf[0x1094] = 0;
}
