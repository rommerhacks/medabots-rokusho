// Robattle turn queue: Medabots that reach the front or home line are queued (battle_queue_add), then
// sorted and popped (battle_queue_sort / _take_head / _pop); also the number and text popup sprites
// (battle_number_popup_*). Called from battle/robattle and the battle action modules.

#include "global.h"

u32 sub_08019EF0(void) {
    u32 i;
    u32 a = 0;
    u32 b = 0;

    if (gUnk_03000440.unk89 != 1 || gUnk_03000B90 == 0) {
        for (i = 0; i <= 5; i++) {
            if (gUnk_03000590[i].unk40) {
                a += battle_bot_at_front_line(i, 0);
                b += battle_bot_at_home_line(i, 0);
            }
        }
    } else {
        for (i = 3; i <= 5; i++) {
            if (gUnk_03000590[i].unk40) {
                a += battle_bot_at_front_line(i, 0);
                b += battle_bot_at_home_line(i, 0);
            }
        }
        for (i = 0; i <= 2; i++) {
            if (gUnk_03000590[i].unk40) {
                a += battle_bot_at_front_line(i, 0);
                b += battle_bot_at_home_line(i, 0);
            }
        }
    }
    if (a != 0 || b != 0)
        return 1;
    return 0;
}

u32 battle_bot_at_front_line(u32 rec, u32 peek) {
    u32 reached = 0;

    if (!(gUnk_03000590[rec].unkBD & 4)) {
        if (rec <= 2) {
            if (gUnk_03002C30[rec * 4 + 0x5D].unk2 == 0x68)
                reached = 1;
        } else {
            if (gUnk_03002C30[rec * 4 + 0x5D].unk2 == 0x88)
                reached = 1;
        }
        if (peek == 0 && reached)
            battle_queue_add(rec, gUnk_03000590[rec].parts[3].unk12);
    }
    return reached;
}

u32 battle_bot_at_home_line(u32 rec, u32 peek) {
    u32 reached = 0;

    if (gUnk_03000590[rec].unkBD & 4) {
        if (rec <= 2) {
            if (gUnk_03002C30[rec * 4 + 0x5D].unk2 == 0x28)
                reached = 1;
        } else {
            if (gUnk_03002C30[rec * 4 + 0x5D].unk2 == 0xC8)
                reached = 1;
        }
        if (peek == 0 && reached)
            battle_queue_add(rec, gUnk_03000590[rec].parts[3].unk12);
    }
    return reached;
}

void battle_queue_add(u32 rec, u32 prio) {
    u32 i;
    struct Unk_03001800 *g;

    i = 0;
    g = &gUnk_03001800;
    for (; i <= 5; i++) {
        if (g->unk45[i][0] == 0) {
            g->unk45[i][0] = rec + 1;
            g->unk45[i][1] = prio;
            return;
        }
    }
}

void iterate_bots_setup_battle_sprites(void) {
    u32 i;

    for (i = 0; i <= 5; i++) {
        if (gUnk_03000590[i].unk40)
            setup_bot_battle_sprites_08015A00(i, gUnk_03002C30[0x5D + i * 4].unk2,
                                              gUnk_03002C30[0x5D + i * 4].unk4 - 4);
    }
}

// Hidden function (no callers): 2-digit number buffer, [0] = 0xB when neg else 0xA (sign tile), [1] tens, [2] ones.
static void sub_0801A118(u8 *buf, u32 n, u32 neg) {
    if (neg)
        buf[0] = 0xB;
    else
        buf[0] = 0xA;
    buf[1] = n / 10;
    buf[2] = n % 10;
}

void battle_number_popup_init(u8 *buf, u32 rec) {
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (buf[i] == 0xFE) {
            gUnk_03002C30[rec * 4 + 10 + i].unk21 = 0xFF;
            return;
        }
        gUnk_03002C30[rec * 4 + 10 + i].unk0 = 0xC224;
        gUnk_03002C30[rec * 4 + 10 + i].unk1C = 0;
        gUnk_03002C30[rec * 4 + 10 + i].unk4 = gUnk_03002C30[rec * 4 + 0x5D].unk4 + 4;
        gUnk_03002C30[rec * 4 + 10 + i].unkB = 0x90;
        gUnk_03002C30[rec * 4 + 10 + i].unk6 = buf[i] + 0x800;
        gUnk_03002C30[rec * 4 + 10 + i].unk20 = i * 4;
        gUnk_03002C30[rec * 4 + 10 + i].unk21 = 0;
        gUnk_03002C30[rec * 4 + 10 + i].unk9 = 0x40;
        gUnk_03002C30[rec * 4 + 10 + i].unk8 = 0x40;
        gUnk_03002C30[rec * 4 + 10 + i].unkA = buf[0] + 1;
        switch (buf[6]) {
        case 1:
            gUnk_03002C30[rec * 4 + 10 + i].unk2 = gUnk_03002C30[rec * 4 + 0x5D].unk2 + i * 8;
            break;
        case 2:
            gUnk_03002C30[rec * 4 + 10 + i].unk2 = gUnk_03002C30[rec * 4 + 0x5D].unk2 - 4 + i * 8;
            break;
        case 3:
            gUnk_03002C30[rec * 4 + 10 + i].unk2 = gUnk_03002C30[rec * 4 + 0x5D].unk2 - 8 + i * 8;
            break;
        case 4:
            gUnk_03002C30[rec * 4 + 10 + i].unk2 = gUnk_03002C30[rec * 4 + 0x5D].unk2 - 12 + i * 8;
            break;
        }
    }
}

void battle_number_popup_update(u32 rec) {
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03002C30[rec * 4 + 10 + i].unk21 == 0xFF)
            return;
        if (gUnk_03002C30[rec * 4 + 10 + i].unk21 <= 0x1F) {
            if (gUnk_03002C30[rec * 4 + 10 + i].unk20 == 0) {
                gUnk_03002C30[rec * 4 + 10 + i].unk4 += gUnk_083AD3B3[gUnk_03002C30[rec * 4 + 10 + i].unk21];
                gUnk_03002C30[rec * 4 + 10 + i].unk9 += 2;
                gUnk_03002C30[rec * 4 + 10 + i].unk21++;
            } else
                gUnk_03002C30[rec * 4 + 10 + i].unk20--;
        }
    }
}

void set_display_digit_type(u8 *buf, u32 value, u32 type) {
    u8 n;
    u8 i;
    u8 started;
    u8 d[3];
    vu32 rem;

    if (type != 0) {
        if (type == 1) {
            buf[0] = 0xB;
            n = 1;
        } else
            n = 0;
    } else {
        buf[0] = 0xA;
        n = 1;
    }
    d[0] = value / 100;
    rem = value - (value / 100) * 100;
    d[1] = rem / 10;
    rem = rem - rem / 10 * 10;
    d[2] = rem;
    started = 0;
    for (i = 0; i <= 2; i++) {
        if (i <= 1) {
            if (d[i] == 0) {
                if (started) {
                    buf[n] = d[i];
                    n++;
                }
            } else {
                buf[n] = d[i];
                started = 1;
                n++;
            }
        } else {
            buf[n] = d[i];
            n++;
        }
    }
    buf[n] = 0xFE;
    buf[6] = n;
}

void render_battle_text_sprites(u8 *buf, u32 rec, u32 slot) {
    u32 i;

    for (i = 0; i <= 4; i++) {
        if (buf[i] == 0xFE)
            return;
        gUnk_03002C30[rec * 4 + slot + i].unk0 = 0xC224;
        gUnk_03002C30[rec * 4 + slot + i].unk1C = 0;
        gUnk_03002C30[rec * 4 + slot + i].unk4 = gUnk_03002C30[rec * 4 + 0x5D].unk4 + 4;
        gUnk_03002C30[rec * 4 + slot + i].unkB = 0x90;
        gUnk_03002C30[rec * 4 + slot + i].unk6 = buf[i] + 0x800;
        gUnk_03002C30[rec * 4 + slot + i].unk20 = i * 4;
        gUnk_03002C30[rec * 4 + slot + i].unk21 = 0;
        gUnk_03002C30[rec * 4 + slot + i].unk9 = 0x40;
        gUnk_03002C30[rec * 4 + slot + i].unk8 = 0x40;
        gUnk_03002C30[rec * 4 + slot + i].unkA = buf[0] + 1;
        switch (buf[6]) {
        case 1:
            gUnk_03002C30[rec * 4 + slot + i].unk2 = gUnk_03002C30[rec * 4 + 0x5D].unk2 + i * 8;
            break;
        case 2:
            gUnk_03002C30[rec * 4 + slot + i].unk2 = gUnk_03002C30[rec * 4 + 0x5D].unk2 - 4 + i * 8;
            break;
        case 3:
            gUnk_03002C30[rec * 4 + slot + i].unk2 = gUnk_03002C30[rec * 4 + 0x5D].unk2 - 8 + i * 8;
            break;
        case 4:
            gUnk_03002C30[rec * 4 + slot + i].unk2 = gUnk_03002C30[rec * 4 + 0x5D].unk2 - 12 + i * 8;
            break;
        }
    }
}

void battle_setup_text_sprites_0801A418(u8 *buf, u32 rec, u32 slot) {
    u32 i;

    for (i = 0; i <= 4; i++) {
        if (buf[i] == 0xFE)
            return;
        gUnk_03002C30[rec * 4 + slot + i].unk0 = 0xC224;
        gUnk_03002C30[rec * 4 + slot + i].unk1C = 0;
        gUnk_03002C30[rec * 4 + slot + i].unk4 = gUnk_03002C30[rec * 4 + 0x5D].unk4 + 4;
        gUnk_03002C30[rec * 4 + slot + i].unkB = 0x90;
        gUnk_03002C30[rec * 4 + slot + i].unk6 = buf[i] + 0x5100;
        gUnk_03002C30[rec * 4 + slot + i].unk20 = i * 4;
        gUnk_03002C30[rec * 4 + slot + i].unk21 = 0;
        gUnk_03002C30[rec * 4 + slot + i].unk9 = 0x40;
        gUnk_03002C30[rec * 4 + slot + i].unk8 = 0x40;
        gUnk_03002C30[rec * 4 + slot + i].unkA = 0xC;
        switch (buf[6]) {
        case 1:
            gUnk_03002C30[rec * 4 + slot + i].unk2 = gUnk_03002C30[rec * 4 + 0x5D].unk2 + i * 8;
            break;
        case 2:
            gUnk_03002C30[rec * 4 + slot + i].unk2 = gUnk_03002C30[rec * 4 + 0x5D].unk2 - 4 + i * 8;
            break;
        case 3:
            gUnk_03002C30[rec * 4 + slot + i].unk2 = gUnk_03002C30[rec * 4 + 0x5D].unk2 - 8 + i * 8;
            break;
        case 4:
            gUnk_03002C30[rec * 4 + slot + i].unk2 = gUnk_03002C30[rec * 4 + 0x5D].unk2 - 12 + i * 8;
            break;
        }
    }
}

void battle_setup_text_sprites_0801A4F4(u8 *buf, u32 rec, u32 slot, u32 x, u32 y) {
    u32 i;

    for (i = 0; i <= 4; i++) {
        if (buf[i] == 0xFE)
            return;
        gUnk_03002C30[slot + rec * 4 + i].unk0 = 0xC224;
        gUnk_03002C30[slot + rec * 4 + i].unk1C = 0;
        gUnk_03002C30[slot + rec * 4 + i].unk4 = y;
        gUnk_03002C30[slot + rec * 4 + i].unk2 = x + i * 8;
        gUnk_03002C30[slot + rec * 4 + i].unkB = 0x90;
        gUnk_03002C30[slot + rec * 4 + i].unk6 = buf[i] + 0x5100;
        gUnk_03002C30[slot + rec * 4 + i].unk20 = i * 4;
        gUnk_03002C30[slot + rec * 4 + i].unk21 = 0;
        gUnk_03002C30[slot + rec * 4 + i].unk9 = 0x40;
        gUnk_03002C30[slot + rec * 4 + i].unk8 = 0x40;
        gUnk_03002C30[slot + rec * 4 + i].unkA = 0xC;
    }
}

void update_battle_sprite_animations(u8 *buf, u32 rec, u32 slot) {
    u32 i;

    for (i = 0; i <= 4; i++) {
        if (buf[i] == 0xFE)
            return;
        if (gUnk_03002C30[slot + rec * 4 + i].unk21 <= 0x1F) {
            if (gUnk_03002C30[slot + rec * 4 + i].unk20 == 0) {
                gUnk_03002C30[slot + rec * 4 + i].unk4 += gUnk_083AD3B3[gUnk_03002C30[slot + rec * 4 + i].unk21];
                gUnk_03002C30[slot + rec * 4 + i].unk9 += 2;
                gUnk_03002C30[slot + rec * 4 + i].unk21++;
            } else
                gUnk_03002C30[slot + rec * 4 + i].unk20--;
        }
    }
}

void battle_queue_sort(void) {
    u32 n, i;
    u8 r, p;

    for (n = 5; n != 0; n--) {
        for (i = 0; i < n; i++) {
            if (gUnk_03001800.unk45[0][i * 2 + 1] < gUnk_03001800.unk45[0][(i + 1) * 2 + 1]) {
                r = gUnk_03001800.unk45[0][(i + 1) * 2];
                p = gUnk_03001800.unk45[0][(i + 1) * 2 + 1];
                gUnk_03001800.unk45[0][(i + 1) * 2] = gUnk_03001800.unk45[0][i * 2];
                gUnk_03001800.unk45[0][(i + 1) * 2 + 1] = gUnk_03001800.unk45[0][i * 2 + 1];
                gUnk_03001800.unk45[0][i * 2] = r;
                gUnk_03001800.unk45[0][i * 2 + 1] = p;
            }
        }
    }
}

void battle_queue_take_head(void) {
    gUnk_03001800.unk87 = gUnk_03001800.unk45[0][0] - 1;
    gUnk_03001800.unk89 = (gUnk_03001800.unk45[0][0] - 1) / 3;
    gUnk_03001800.unk8A = gUnk_03001800.unk89 ^ 1;
}

void battle_queue_pop(void) {
    u32 i;

    for (i = 0; i <= 4; i++) {
        gUnk_03001800.unk45[0][i * 2] = gUnk_03001800.unk45[0][(i + 1) * 2];
        gUnk_03001800.unk45[0][i * 2 + 1] = gUnk_03001800.unk45[0][(i + 1) * 2 + 1];
    }
    gUnk_03001800.unk45[0][i * 2] = 0;
    gUnk_03001800.unk45[0][i * 2 + 1] = 0;
}

u32 sub_0801A6B0(void) {
    u32 i;

    for (i = 0; i <= 5; i++) {
        if (gUnk_03000590[i].unk40 && gUnk_03000590[i].unkBF)
            return 1;
    }
    return 0;
}

u32 sub_0801A6EC(u32 rec) {
    if (rec <= 2) {
        switch (rec) {
        case 0:
            if (gUnk_03001800.unk44 & 1)
                return 1;
            return 0;
        case 1:
            if (gUnk_03001800.unk44 & 2)
                return 1;
            return 0;
        case 2:
            if (gUnk_03001800.unk44 & 4)
                return 1;
            return 0;
        }
    }
}

void sub_0801A744(u32 rec) {
    if (rec <= 2) {
        switch (rec) {
        case 0:
            gUnk_03001800.unk44 &= ~1;
            break;
        case 1:
            gUnk_03001800.unk44 &= ~2;
            break;
        case 2:
            gUnk_03001800.unk44 &= ~4;
            break;
        }
    }
}
