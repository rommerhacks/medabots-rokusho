// Medapart armor and stat helpers for the battle records gUnk_03000590 (add_part_stat_clamped and its
// variants, part armor sums). Used by the battle action code.

#include "global.h"

static u32 sub_08018EE0(u32 rec);
static u32 add_part_stat_clamped(u32 rec, u32 part, s32 amount);
static u32 sub_08018FF0(u32 rec, u32 part, s32 amount);

void sub_08018CBC(void) {
    u32 i;

    gUnk_03001800.unk55 = 0;
    for (i = 0; i <= 5; i++) {
        if (gUnk_03000590[i].unk40) {
            if (gUnk_03000590[i].unkC4)
                sub_08018D0C(i);
            if (gUnk_03000590[i].unkC9)
                sub_08018DF4(i);
        }
    }
}

void sub_08018D0C(u32 rec) {
    s32 t;
    u32 i, k, v, done;

    t = gUnk_03000590[rec].unkC6 - 4;
    if (t <= 0) {
        gUnk_03000590[rec].unkC4 = 0;
        gUnk_03000590[rec].unkC5 = 0;
        gUnk_03000590[rec].unkC6 = 0;
        gUnk_03000590[rec].unkC7 = 0;
        gUnk_03000590[rec].unkCE |= 1;
        gUnk_03001800.unk55 |= 2;
        return;
    }
    gUnk_03000590[rec].unkC6 = t;
    if (gUnk_03000590[rec].unkC4 != 0x1F)
        return;
    gUnk_03001800.unk59 = gUnk_03000590[rec].unkC7;
    gUnk_03001800.unk86 = 0;
    done = 0;
    for (i = 0; i <= 3; i++) {
        k = sub_08018EE0(rec);
        if (k != 0) {
            v = add_part_stat_clamped(rec, k - 1, gUnk_03001800.unk59);
            gUnk_03001800.unk86 += v;
            gUnk_03001800.unk59 = (v & 0xFF00) >> 8;
            done = 1;
            if (gUnk_03001800.unk59 == 0)
                break;
        } else
            break;
    }
    if (done) {
        gUnk_03000590[rec].unkC8 = gUnk_03001800.unk86;
        gUnk_03000590[rec].unkCE |= 4;
        gUnk_03001800.unk55 |= 8;
    }
}

void sub_08018DF4(u32 rec) {
    s32 t;
    u32 i, k, v, done;

    t = gUnk_03000590[rec].unkCB - 4;
    if (t <= 0) {
        gUnk_03000590[rec].unkC9 = 0;
        gUnk_03000590[rec].unkCA = 0;
        gUnk_03000590[rec].unkCB = 0;
        gUnk_03000590[rec].unkCC = 0;
        gUnk_03000590[rec].unkCE |= 2;
        gUnk_03001800.unk55 |= 4;
        return;
    }
    gUnk_03000590[rec].unkCB = t;
    if ((u8)(gUnk_03000590[rec].unkC9 - 0x13) > 1)
        return;
    gUnk_03001800.unk59 = gUnk_03000590[rec].unkCC;
    gUnk_03001800.unk86 = 0;
    done = 0;
    for (i = 0; i <= 3; i++) {
        k = sub_08018F6C(rec);
        if (k != 0) {
            v = sub_08018FF0(rec, k - 1, gUnk_03001800.unk59);
            gUnk_03001800.unk86 += v;
            gUnk_03001800.unk59 = (v & 0xFF00) >> 8;
            done = 1;
            if (gUnk_03001800.unk59 == 0)
                break;
        } else
            break;
    }
    if (done) {
        gUnk_03000590[rec].unkCD = gUnk_03001800.unk86;
        gUnk_03000590[rec].unkCE |= 8;
        gUnk_03001800.unk55 |= 0x10;
    }
}

static inline u32 part_armor(u32 rec, u32 i) {
    return gUnk_03000590[rec].parts[i].unk11;
}

static u32 sub_08018EE0(u32 rec) {
    u32 i;
    for (i = 0; i <= 3; i++) {
        if (gUnk_03000590[rec].parts[i].unk11 != 0)
            if (gUnk_03000590[rec].parts[i].data[4] != part_armor(rec, i))
                return i + 1;
    }
    return 0;
}

static u32 add_part_stat_clamped(u32 rec, u32 part, s32 amount) {
    u32 v = gUnk_03000590[rec].parts[part].unk11;

    v += amount;
    if (v > gUnk_03000590[rec].parts[part].data[4]) {
        v -= gUnk_03000590[rec].parts[part].data[4];
        gUnk_03000590[rec].parts[part].unk11 = gUnk_03000590[rec].parts[part].data[4];
        return (v << 8) + (amount - v);
    }
    gUnk_03000590[rec].parts[part].unk11 = v;
    return amount;
}

static u32 sub_08018F48(u32 rec) {
    u32 i;

    for (i = 0; i <= 3; i++) {
        if (gUnk_03000590[rec].parts[3 - i].unk11)
            return i + 1;
    }
    return 0;
}

u32 sub_08018F6C(u32 rec) {
    u32 k, i;

    if (gUnk_03000590[rec].unkCA == 0)
        k = 4;
    else
        k = gUnk_03000590[rec].unkCA;
    for (i = 0; i <= 3; i++) {
        if (gUnk_03000590[rec].parts[k - 1].unk11 > 1)
            return k;
        k--;
        if (k == 0)
            k = 4;
    }
    return 0;
}

static u32 sub_08018FB8(u32 rec, u32 part, s32 amount) {
    u32 cur = gUnk_03000590[rec].parts[part].unk11;
    s32 v = cur - amount;
    u32 ret;

    if (v >= 0) {
        gUnk_03000590[rec].parts[part].unk11 = v;
        ret = amount;
    } else {
        gUnk_03000590[rec].parts[part].unk11 = 0;
        ret = ((amount - cur) << 8) + cur;
    }
    return ret;
}

static u32 sub_08018FF0(u32 rec, u32 part, s32 amount) {
    u32 cur = gUnk_03000590[rec].parts[part].unk11;
    u32 m = cur - 1;
    u32 ret;

    if ((s32)(m - amount) >= 0) {
        gUnk_03000590[rec].parts[part].unk11 = cur - amount;
        ret = amount;
    } else {
        gUnk_03000590[rec].parts[part].unk11 = 1;
        ret = ((amount - m) << 8) + m;
    }
    return ret;
}
