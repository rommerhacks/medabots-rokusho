// Medabot movement on the battle field: battle_bot_move steps a Medabot between its home line and the front
// line, with the small per-record movement helpers before it. Called from battle/robattle.

#include "global.h"

static void sub_080190B8(u32 rec);
static void sub_08019108(u32 rec);
static void sub_08019184(u32 rec, u32 n);
static void sub_080191C0(u32 rec);
static void sub_0801922C(u32 rec);
static void sub_08019264(u32 rec);
static void sub_080192B8(u32 rec);
static void sub_080192E8(u32 rec);
static void sub_0801932C(u32 rec);

void sub_0801902C(void) {
    u32 i;

    for (i = 0; i <= 5; i++) {
        if (gUnk_03000590[i].unk40 && (u8)(gUnk_03000590[i].unkC9 - 0xF) > 1) {
            sub_080190B8(i);
            battle_bot_move(i);
            sub_08019544(i);
        }
    }
}

void sub_08019078(void) {
    u32 i;

    for (i = 0; i <= 5; i++) {
        if (gUnk_03000590[i].unk40 && (u8)(gUnk_03000590[i].unkC9 - 0xF) > 1) {
            sub_08019544(i);
        }
    }
}

static void sub_080190B8(u32 rec) {
    gUnk_03000590[rec].unkBB = 0;
    sub_08019108(rec);
    sub_080191C0(rec);
    sub_080191E4(rec);
    sub_0801922C(rec);
    sub_08019264(rec);
    sub_0801928C(rec);
    sub_080192B8(rec);
    sub_080192E8(rec);
    sub_0801932C(rec);
}

static void sub_08019108(u32 rec) {
    if (gUnk_03000590[rec].unkDD == 0)
        return;
    if (gUnk_03000590[rec].unkDD > 3) {
        sub_08019184(rec, 12);
        return;
    }
    if (gUnk_03000590[rec].parts[gUnk_03000590[rec].unkDD - 1].unk11 == 0)
        return;
    if (gUnk_03000590[rec].unkDD == 1)
        sub_08019184(rec, 6);
    else if (!(gUnk_03000590[rec].unkBD & 4))
        sub_08019184(rec, gUnk_03000590[rec].parts[gUnk_03000590[rec].unkDD - 1].data[8]);
    else
        sub_08019184(rec, gUnk_03000590[rec].parts[gUnk_03000590[rec].unkDD - 1].data[9]);
}

static void sub_08019184(u32 rec, u32 n) {
    n += gUnk_03000590[rec].unkBB;
    if (n > 0xFF)
        n = 0xFF;
    gUnk_03000590[rec].unkBB = n;
}

static void sub_080191A4(u32 rec, u32 n) {
    s32 v = gUnk_03000590[rec].unkBB - n;

    if (v < 0)
        v = 0;
    gUnk_03000590[rec].unkBB = v;
}

static void sub_080191C0(u32 rec) {
    if (gUnk_03000590[rec].parts[3].unk11 == 0)
        sub_08019184(rec, 6);
}

void sub_080191E4(u32 rec) {
    memcpy_bytes_08041D04(&gUnk_083C4C10[gUnk_03001800.unk38 + (gUnk_03000590[rec].parts[3].data[1] - 100) * 11],
                          &gUnk_03000440.unkEE, 1);
    sub_08019184(rec, gUnk_03000440.unkEE);
}

static void sub_0801922C(u32 rec) {
    if (gUnk_03000590[rec].unkC9 != 0 &&
        ((u8)(gUnk_03000590[rec].unkC9 - 0x11) <= 1 || gUnk_03000590[rec].unkC9 == 0x29))
        sub_08019184(rec, gUnk_03000590[rec].unkCC);
}

static void sub_08019264(u32 rec) {
    sub_080191A4(rec, (u8)(gUnk_03000590[rec].medal.unk5 / 10));
}

void sub_0801928C(u32 rec) {
    sub_080191A4(rec, (u8)(gUnk_03000590[rec].parts[3].unk12 / 20));
}

static void sub_080192B8(u32 rec) {
    if (gUnk_03000590[rec].unkC4 != 0 && (gUnk_03000590[rec].unkC4 == 0x26 || gUnk_03000590[rec].unkC4 == 0x29))
        sub_080191A4(rec, gUnk_03000590[rec].unkC7);
}

static void sub_080192E8(u32 rec) {
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03000590[rec].parts[i].data[1] == 0x28 && gUnk_03000590[rec].parts[i].unk11 != 0)
            sub_080191A4(rec, gUnk_03000590[rec].parts[i].data[6]);
    }
}

static void sub_0801932C(u32 rec) {
    if (gUnk_03000590[rec].unkBB > 0x1F)
        gUnk_03000590[rec].unkBB = 0x1F;
}

void battle_bot_move(u32 rec) {

    gUnk_03000590[rec].unkD7 += 0x20 - gUnk_03000590[rec].unkBB;
    gUnk_03000590[rec].unkDA = gUnk_03000590[rec].unkD7 / 16;
    gUnk_03000590[rec].unkD7 %= 16;
    if (rec <= 2) {
        if (!(gUnk_03000590[rec].unkBD & 4)) {
            if (gUnk_03002C30[rec * 4 + 0x5D].unk2 + gUnk_03000590[rec].unkDA > 0x68)
                gUnk_03002C30[rec * 4 + 0x5D].unk2 = 0x68;
            else
                gUnk_03002C30[rec * 4 + 0x5D].unk2 += gUnk_03000590[rec].unkDA;
        } else {
            if (gUnk_03002C30[rec * 4 + 0x5D].unk2 - gUnk_03000590[rec].unkDA < 0x28)
                gUnk_03002C30[rec * 4 + 0x5D].unk2 = 0x28;
            else
                gUnk_03002C30[rec * 4 + 0x5D].unk2 -= gUnk_03000590[rec].unkDA;
        }
    } else {
        if (!(gUnk_03000590[rec].unkBD & 4)) {
            if (gUnk_03002C30[rec * 4 + 0x5D].unk2 - gUnk_03000590[rec].unkDA < 0x88)
                gUnk_03002C30[rec * 4 + 0x5D].unk2 = 0x88;
            else
                gUnk_03002C30[rec * 4 + 0x5D].unk2 -= gUnk_03000590[rec].unkDA;
        } else {
            if (gUnk_03002C30[rec * 4 + 0x5D].unk2 + gUnk_03000590[rec].unkDA > 0xC8)
                gUnk_03002C30[rec * 4 + 0x5D].unk2 = 0xC8;
            else
                gUnk_03002C30[rec * 4 + 0x5D].unk2 += gUnk_03000590[rec].unkDA;
        }
    }
}

u32 sub_08019440(u32 rec) {
    u32 done = 0;

    gUnk_03000590[rec].unkD7 += 0x20 - gUnk_03000590[rec].unkBB;
    gUnk_03000590[rec].unkDA = gUnk_03000590[rec].unkD7 / 16;
    gUnk_03000590[rec].unkD7 %= 16;
    if (rec <= 2) {
        if (gUnk_03000590[rec].unkBD & 4) {
            if (gUnk_03002C30[rec * 4 + 0x5D].unk2 + gUnk_03000590[rec].unkDA > 0x68) {
                gUnk_03002C30[rec * 4 + 0x5D].unk2 = 0x68;
                done = 1;
            } else
                gUnk_03002C30[rec * 4 + 0x5D].unk2 += gUnk_03000590[rec].unkDA;
        } else {
            if (gUnk_03002C30[rec * 4 + 0x5D].unk2 - gUnk_03000590[rec].unkDA < 0x28) {
                gUnk_03002C30[rec * 4 + 0x5D].unk2 = 0x28;
                done = 1;
            } else
                gUnk_03002C30[rec * 4 + 0x5D].unk2 -= gUnk_03000590[rec].unkDA;
        }
    } else {
        if (gUnk_03000590[rec].unkBD & 4) {
            if (gUnk_03002C30[rec * 4 + 0x5D].unk2 - gUnk_03000590[rec].unkDA < 0x88) {
                gUnk_03002C30[rec * 4 + 0x5D].unk2 = 0x88;
                done = 1;
            } else
                gUnk_03002C30[rec * 4 + 0x5D].unk2 -= gUnk_03000590[rec].unkDA;
        } else {
            if (gUnk_03002C30[rec * 4 + 0x5D].unk2 + gUnk_03000590[rec].unkDA > 0xC8) {
                gUnk_03002C30[rec * 4 + 0x5D].unk2 = 0xC8;
                done = 1;
            } else
                gUnk_03002C30[rec * 4 + 0x5D].unk2 += gUnk_03000590[rec].unkDA;
        }
    }
    return done;
}

void sub_08019544(u32 rec) {
    if (gUnk_03002C30[rec * 4 + 0x5B].unk0 & 0x200) {
        gUnk_03002C30[rec * 4 + 0x5D].unk24 = ((s32)(0x20 - gUnk_03000590[rec].unkBB) >> 1) + 1;
        update_battle_sprite_orbiting_positions(rec * 4 + 0x5A, rec, bot_sprite_is_flipped(rec));
    } else {
        battle_sprite_set_palette_index(rec * 4 + 0x5A, ((s32)(0x20 - gUnk_03000590[rec].unkBB) >> 1) + 1);
    }
}
