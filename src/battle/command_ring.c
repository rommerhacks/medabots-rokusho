// The Robattle command ring: draws the selected command's name, sets up and rotates the ring icons, reads
// the input, pulses the selected icon and animates the battle sprites meanwhile. Called from battle/robattle.

#include "global.h"

static void command_ring_init_icon_hidden(u32 a);
static u32 sub_08016154(u32 i, u32 dir);

void command_ring_draw_name(void) {
    clear_sprite_table_mask(30, 11);
    memcpy_bytes_08041D04(gUnk_083C466C[gUnk_03001800.unk81], gUnk_03000440.unk9E, 12);
    render_text_sprites_08040DB8(gUnk_03000440.unk9E, 30, 21, 17, 8, 14, 0, 1);
}

void command_ring_init_icons(void) {
    u32 i;
    for (i = 0; i < 6; i++)
        command_ring_init_icon(i);
}

void command_ring_init_icon(u32 i) {
    u32 k;
    struct Vec16 p;

    clear_battle_sprite_slot(i, 1);
    gUnk_03002C30[i].unk0 = 0xC604;
    k = i - gUnk_03001800.unk81;
    if (k > 5)
        k += 6;
    p = compute_polar_to_screen_position(gUnk_083AD370[k], 24, 120, 128, 8, 0);
    gUnk_03002C30[i].unk2 = p.x;
    gUnk_03002C30[i].unk4 = p.y;
    gUnk_03002C30[i].unk6 = i + 0x60C;
    if (p.y > 0x87)
        gUnk_03002C30[i].unkA = 8;
    else if (p.y > 0x77)
        gUnk_03002C30[i].unkA = 9;
    else
        gUnk_03002C30[i].unkA = 10;
    gUnk_03002C30[i].unk1C = 0;
    gUnk_03002C30[i].unk9 = 0x40 - (0x90 - gUnk_03002C30[i].unk4) / 2;
    gUnk_03002C30[i].unk8 = 0x40 - (0x90 - gUnk_03002C30[i].unk4) / 2;
    gUnk_03002C30[i].unkB = gUnk_03002C30[i].unk4 - 0x70;
    gUnk_03002C30[i].unk20 = gUnk_083AD370[k];
    gUnk_03002C30[i].unk21 = 0;
    gUnk_03002C30[i].unk22 = 0;
}

void command_ring_init_icons_hidden(void) {
    u32 i;
    for (i = 0; i < 6; i++)
        command_ring_init_icon_hidden(i);
}

static void command_ring_init_icon_hidden(u32 i) {
    u32 k;
    struct Vec16 p;

    clear_battle_sprite_slot(i, 1);
    gUnk_03002C30[i].unk0 = 0xC604;
    k = i - gUnk_03001800.unk81;
    if (k > 5)
        k += 6;
    p = compute_polar_to_screen_position(gUnk_083AD370[k], 24, 120, 128, 8, 0);
    gUnk_03002C30[i].unk2 = p.x;
    gUnk_03002C30[i].unk4 = p.y;
    gUnk_03002C30[i].unk6 = i + 0x60C;
    if (p.y > 0x87)
        gUnk_03002C30[i].unkA = 8;
    else if (p.y > 0x77)
        gUnk_03002C30[i].unkA = 9;
    else
        gUnk_03002C30[i].unkA = 10;
    gUnk_03002C30[i].unk1C = 0;
    gUnk_03002C30[i].unk9 = 1;
    gUnk_03002C30[i].unk8 = 1;
    gUnk_03002C30[i].unkB = gUnk_03002C30[i].unk4 - 0x70;
    gUnk_03002C30[i].unk20 = gUnk_083AD370[k];
    gUnk_03002C30[i].unk21 = 0;
    gUnk_03002C30[i].unk22 = 0;
}

static u32 command_ring_rotate_step(u32 dir) {
    u32 i, done;
    for (i = 0; i <= 5; i++)
        done = sub_08016154(i, dir);
    return done;
}

static u32 sub_08016154(u32 i, u32 dir) {
    u32 done = 0;
    u32 k;
    u32 n;
    struct Vec16 p;

    gUnk_03002C30[i].unk0 &= ~0x20;
    if (dir == 0)
        n = gUnk_083AD376[gUnk_03001800.unk81];
    else
        n = gUnk_083AD37C[gUnk_03001800.unk81];
    k = i - n;
    if (k > 5)
        k += 6;
    if (dir == 0)
        gUnk_03002C30[i].unk20 += 6;
    else
        gUnk_03002C30[i].unk20 -= 6;
    gUnk_03002C30[i].unk21++;
    if (gUnk_03002C30[i].unk21 == 7) {
        done = 1;
        gUnk_03002C30[i].unk20 = gUnk_083AD370[k];
        gUnk_03002C30[i].unk21 = 0;
        gUnk_03002C30[i].unk22 = 0;
    }
    p = compute_polar_to_screen_position(gUnk_03002C30[i].unk20, 24, 120, 128, 8, 0);
    gUnk_03002C30[i].unk2 = p.x;
    gUnk_03002C30[i].unk4 = p.y;
    gUnk_03002C30[i].unk6 = i + 0x60C;
    if (p.y > 0x87)
        gUnk_03002C30[i].unkA = 8;
    else if (p.y > 0x7B)
        gUnk_03002C30[i].unkA = 9;
    else
        gUnk_03002C30[i].unkA = 10;
    gUnk_03002C30[i].unk1C = 0;
    gUnk_03002C30[i].unk9 = 0x40 - (0x90 - gUnk_03002C30[i].unk4) / 2;
    gUnk_03002C30[i].unk8 = 0x40 - (0x90 - gUnk_03002C30[i].unk4) / 2;
    gUnk_03002C30[i].unkB = gUnk_03002C30[i].unk4 - 0x70;
    return done;
}

void command_ring_input(void) {
    if (gUnk_03001800.unk83) {
        if (command_ring_rotate_step(gUnk_03001800.unk83 - 1)) {
            if (gUnk_03001800.unk83 == 1)
                gUnk_03001800.unk81 = gUnk_083AD376[gUnk_03001800.unk81];
            else
                gUnk_03001800.unk81 = gUnk_083AD37C[gUnk_03001800.unk81];
            gUnk_03001800.unk83 = 0;
            command_ring_draw_name();
        }
    } else {
        if (KEYS_LO(gRepeatKeys) & 0x10) {
            play_sound_effect(2);
            gUnk_03001800.unk83 = 1;
        }
        if (KEYS_LO(gRepeatKeys) & 0x20) {
            play_sound_effect(2);
            gUnk_03001800.unk83 = 2;
        }
    }
}

void command_ring_pulse_selected(void) {
    if (gUnk_03001800.unk83 == 0) {
        gUnk_03002C30[gUnk_03001800.unk81].unk0 |= 0x20;
        gUnk_03002C30[gUnk_03001800.unk81].unk22++;
        if (gUnk_03002C30[gUnk_03001800.unk81].unk22 & 8) {
            gUnk_03002C30[gUnk_03001800.unk81].unk9 = 0x50;
            gUnk_03002C30[gUnk_03001800.unk81].unk8 = 0x50;
        } else {
            gUnk_03002C30[gUnk_03001800.unk81].unk9 = 0x40;
            gUnk_03002C30[gUnk_03001800.unk81].unk8 = 0x40;
        }
    }
}

void sub_08016370(u32 kind) {
    s32 count = gUnk_083AD382[kind * 4];
    u32 speed = gUnk_083AD382[kind * 4 + 1];
    u32 x = gUnk_083AD382[kind * 4 + 2];
    u32 y = gUnk_083AD382[kind * 4 + 3];
    s32 i;

    clear_battle_sprite_slot(60, 10);
    for (i = 0; i < (u32)count; i++) {
        gUnk_03002C30[60 + i].unk0 = 0xC404;
        gUnk_03002C30[60 + i].unk1C = 0;
        gUnk_03002C30[60 + i].unk2 = x;
        gUnk_03002C30[60 + i].unk4 = y;
        gUnk_03002C30[60 + i].unkA = 8;
        gUnk_03002C30[60 + i].unkB = 0x80;
        gUnk_03002C30[60 + i].unk6 = (i & 3) + 0x616;
        gUnk_03002C30[60 + i].unk25 = speed;
        gUnk_03002C30[60 + i].unk26 = count - 1 - i;
        gUnk_03002C30[60 + i].unk24 = 0;
        gUnk_03002C30[60 + i].unk27 = i * 2;
        gUnk_03002C30[60 + i].unk28 = 0;
        gUnk_03002C30[60 + i].unk21 = 0;
        gUnk_03002C30[60 + i].unk22 = i & 3;
        if (kind > 2)
            gUnk_03002C30[60 + i].unk0 |= 0x1000;
    }
}

u32 sub_08016438(u32 kind) {
    u32 done = 1;
    u32 count = gUnk_083AD382[kind * 4];
    u32 i;

    for (i = 0; i < count; i++) {
        u32 base;
        if (gUnk_03002C30[60 + i].unk24)
            base = 0x12;
        else
            base = 0x16;
        gUnk_03002C30[60 + i].unk21++;
        if ((gUnk_03002C30[60 + i].unk21 & 3) == 0) {
            gUnk_03002C30[60 + i].unk6 =
                base + ((gUnk_03002C30[60 + i].unk22 = (gUnk_03002C30[60 + i].unk22 + 1) & 3) | 0x600);
        }
        if (gUnk_03002C30[60 + i].unk26 != gUnk_03002C30[60 + i].unk24) {
            done = 0;
            if (gUnk_03002C30[60 + i].unk27)
                gUnk_03002C30[60 + i].unk27--;
            else {
                if (gUnk_03002C30[60 + i].unk24 == 0) {
                    if (gUnk_03002C30[60 + i].unk25)
                        gUnk_03002C30[60 + i].unk2 += 4;
                    else
                        gUnk_03002C30[60 + i].unk2 -= 4;
                } else
                    gUnk_03002C30[60 + i].unk4 += 4;
                gUnk_03002C30[60 + i].unk28++;
                if ((gUnk_03002C30[60 + i].unk28 & 1) == 0)
                    gUnk_03002C30[60 + i].unk24++;
            }
        }
    }
    return done;
}

void animate_battle_sprites(u32 kind) {
    u32 count = gUnk_083AD382[kind * 4];
    u32 i;

    for (i = 0; i < count; i++) {
        u32 base;
        if (gUnk_03002C30[60 + i].unk24)
            base = 0x12;
        else
            base = 0x16;
        gUnk_03002C30[60 + i].unk21++;
        if ((gUnk_03002C30[60 + i].unk21 & 3) == 0) {
            gUnk_03002C30[60 + i].unk6 =
                base + ((gUnk_03002C30[60 + i].unk22 = (gUnk_03002C30[60 + i].unk22 + 1) & 3) | 0x600);
        }
    }
}

void sub_08016554(void) {
    gUnk_03002C30[gUnk_03001800.unk81].unk0 |= 0x20;
    gUnk_03002C30[gUnk_03001800.unk81].unk22++;
    if (gUnk_03002C30[gUnk_03001800.unk81].unk22 & 4) {
        gUnk_03002C30[gUnk_03001800.unk81].unk9 = 0x60;
        gUnk_03002C30[gUnk_03001800.unk81].unk8 = 0x60;
    } else {
        gUnk_03002C30[gUnk_03001800.unk81].unk9 = 0x40;
        gUnk_03002C30[gUnk_03001800.unk81].unk8 = 0x40;
    }
}

void command_ring_goto_selected(void) {
    gGameSubState = gUnk_083AD39A[gUnk_03001800.unk81];
}

void sub_080165D0(void) {
    u32 i;
    for (i = 0; i < 6; i++) {
        if (gUnk_03002C30[i].unk9 == 1)
            clear_sprite_table_mask(i, 1);
        else {
            s32 v = gUnk_03002C30[i].unk9 - 8;
            if (v <= 0) {
                gUnk_03002C30[i].unk9 = 1;
                gUnk_03002C30[i].unk8 = 1;
            } else {
                gUnk_03002C30[i].unk9 = v;
                gUnk_03002C30[i].unk8 -= 8;
            }
        }
    }
}

void sub_08016614(void) {
    if (gUnk_03000440.unk84 < 10) {
        read_vram_tilemap_rect(0xB, 4, 0x13, 0x10, REG_BG1CNT, gUnk_02020800);
        write_vram_tilemap_rect(0xB, 4, 0x14, 0x10, REG_BG1CNT, gUnk_02020800);
    }
}

void sub_08016660(void) {
    if (gUnk_03000440.unk84 < 5) {
        read_vram_tilemap_rect(6, 6, 0xC, 0xE, REG_BG1CNT, gUnk_02020800);
        write_vram_tilemap_rect(6, 6, 0xC, 0xF, REG_BG1CNT, gUnk_02020800);
    }
}

void sub_080166AC(void) {
    set_tilemap_and_decompress_bg(9, 0x15, gUnk_084888A8, REG_BG0CNT, 0x288);
    set_tilemap_and_decompress_bg(0x12, 0x15, gUnk_0848895C, REG_BG1CNT, 0x2D0);
}

void sub_080166F0(void) {
    if (gUnk_03000440.unk84 < 4)
        write_vram_tilemap_rect(0xC, 4, 9, 0x13 - gUnk_03000440.unk84, REG_BG0CNT, gUnk_02020800);
}

void sub_0801672C(void) {
    if (gUnk_03000440.unk84 < 12) {
        read_vram_tilemap_rect(gUnk_03000440.unk84 + 1, 7, 0x12, 0x15, REG_BG1CNT, gUnk_02021000);
        write_vram_tilemap_rect(gUnk_03000440.unk84 + 1, 7, 0x1D - gUnk_03000440.unk84, 0xD, REG_BG1CNT, gUnk_02021000);
    }
}
