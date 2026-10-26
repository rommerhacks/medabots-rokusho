#include "global.h"
#include "keys.h"

void update_battle_sprite_status_effects(void) {
    struct Unk_03005350 *b = &gUnk_03005350;
    s32 i, j;
    s32 d;
    struct Unk_03002C30 *s;

    if (b->unkF0 != 0) {
        for (i = 0; i <= 15; i++) {
            for (j = 0; j <= 3; j++) {
                struct Unk_03002C30 *spr = gUnk_03002C30;

                s = &spr[gUnk_03006D30[i].unk2DC[j]];
                d = s->unk14_8;
                if (d > gUnk_03005350.unk9C) {
                    s->unkB = gUnk_03005350.unk218;
                    gUnk_03002C30[gUnk_03006D30[i].unk2DC[j]].unk0 &= 0xF3FF;
                    gUnk_03002C30[gUnk_03006D30[i].unk2DC[j]].unk0 |= gUnk_03005350.unk220;
                } else {
                    s->unkB = gUnk_03005350.unk214 + (gUnk_03005350.unk9C - d);
                    gUnk_03002C30[gUnk_03006D30[i].unk2DC[j]].unk0 &= 0xF3FF;
                    gUnk_03002C30[gUnk_03006D30[i].unk2DC[j]].unk0 |= gUnk_03005350.unk21C;
                }
            }
        }
    }
}

void sub_0805689C(struct AnimInterp *p, s32 *a) {
    s32 mode;
    float x, phase;

    p->unkC = mode = a[0];
    p->unk10 = a[1] / 256;
    p->unk14 = a[2];
    p->unk18 = a[3] * (1.0f / 256);
    p->unk1C = a[4];
    p->unk20 = a[5];
    p->unk24 = a[6];
    p->unk28 = a[7];
    p->unk2C = a[8];
    p->unk30 = a[9];
    p->unk34 = a[10];
    p->unk38 = a[11];
    p->unk3C = a[12] * (1.0f / 256);
    p->unk40 = a[13] * (1.0f / 256);
    p->unk44 = a[14];
    if (mode > 1)
        p->unk4 = p->unk0;

    switch (p->unkC) {
    case 0x10:
        p->unk2C = x = p->unk34 / float_default_to_one_if_zero(float_abs_if_negative(p->unk3C));
        p->unk24 = p->unk20 + x;
        if (p->unk44 != 0)
            p->unk0 = p->unk0 - float_sign(p->unk3C) * float_abs_if_negative(p->unk34);
        break;
    case 0x11:
        p->unk24 = p->unk20 + p->unk28;
        p->unk34 = p->unk3C * p->unk2C;
        if (p->unk44 != 0)
            p->unk0 = p->unk0 - float_sign(p->unk3C) * float_abs_if_negative(p->unk34);
        break;
    case 0x12: {
        float sum;
        s32 n;

        p->unk3C = p->unk34 * (1.0f / 64);
        phase = p->unk14;
        sum = 0.0f;
        n = 0;
        for (;;) {
            if (p->unk3C == 0.0f)
                break;
            phase = phase + p->unk3C;
            if (phase >= 64.0f)
                phase = 64.0f;
            sum = sum + p->unk40 * (gSineTable[(s32)(phase + 192.0f) & 0xFF] + 256.0f) * (1.0f / 256);
            if (float_abs_if_negative(sum) >= p->unk34)
                break;
            n++;
        }
        p->unk2C = n;
        p->unk30 = x = p->unk38 / float_default_to_one_if_zero(float_abs_if_negative(p->unk40));
        p->unk24 = p->unk20 + p->unk2C + x;
        p->unk38 = p->unk38 + (p->unk34 - float_abs_if_negative(sum));
        if (p->unk44 != 0)
            p->unk0 =
                p->unk0 - float_sign(p->unk40) * (float_abs_if_negative(p->unk34) + float_abs_if_negative(p->unk38));
        break;
    }
    case 0x13: {
        float step;

        p->unk24 = p->unk20 + p->unk28;
        p->unk30 = p->unk28 - p->unk2C;
        p->unk3C = step = 64.0f / float_default_to_one_if_zero(p->unk2C);
        p->unk38 = p->unk40 * p->unk30;
        phase = p->unk14;
        p->unk34 = 0.0f;
        for (;;) {
            if (step == 0.0f)
                break;
            phase = phase + step;
            p->unk34 = p->unk34 + p->unk40 * (gSineTable[(s32)(phase + 192.0f) & 0xFF] + 256.0f) * (1.0f / 256);
            if (phase >= 64.0f)
                break;
        }
        if (p->unk44 != 0)
            p->unk0 =
                p->unk0 - float_sign(p->unk40) * (float_abs_if_negative(p->unk34) + float_abs_if_negative(p->unk38));
        break;
    }
    case 0x14: {
        float sum;
        s32 n;

        p->unk40 = 64.0f / p->unk38;
        phase = p->unk14;
        sum = 0.0f;
        n = 0;
        for (;;) {
            phase = phase + p->unk40;
            if (phase >= 64.0f)
                phase = 64.0f;
            sum = sum + p->unk3C * gSineTable[((s32)phase & 0xFF) + 0x40] * (1.0f / 256);
            if (phase == 64.0f)
                break;
            n++;
        }
        p->unk30 = n;
        p->unk34 = p->unk34 + (p->unk38 - float_abs_if_negative(sum));
        p->unk38 = float_abs_if_negative(sum);
        p->unk2C = x = p->unk34 / float_default_to_one_if_zero(float_abs_if_negative(p->unk3C));
        p->unk24 = p->unk20 + x + p->unk30;
        if (p->unk44 != 0)
            p->unk0 =
                p->unk0 - float_sign(p->unk3C) * (float_abs_if_negative(p->unk34) + float_abs_if_negative(p->unk38));
        break;
    }
    case 0x15: {

        p->unk24 = p->unk20 + p->unk28;
        p->unk34 = p->unk3C * (p->unk2C = p->unk28 - p->unk30);
        p->unk40 = 64.0f / float_default_to_one_if_zero(p->unk30);
        phase = p->unk14;
        p->unk38 = 0.0f;
        for (;;) {
            phase = phase + p->unk40;
            p->unk38 = p->unk38 + p->unk3C * gSineTable[((s32)phase & 0xFF) + 0x40] * (1.0f / 256);
            if (phase >= 64.0f)
                break;
        }
        if (p->unk44 != 0)
            p->unk0 =
                p->unk0 - float_sign(p->unk3C) * (float_abs_if_negative(p->unk34) + float_abs_if_negative(p->unk38));
        break;
    }
    case 0x17:
        p->unk24 = p->unk20 + p->unk28;
        p->unk0 = p->unk4 + p->unk40 * gSineTable[(s32)p->unk2C & 0xFF];
        p->unk14 = p->unk2C;
        break;
    }
}

u32 animation_interpolation_step(struct AnimInterp *p) {
    u32 ret = 0;
    s32 one = 1;
    float s;

    if (p->unkC != 0) {
        if (p->unk20 <= p->unk1C) {
            switch (p->unkC) {
            case 0x10:
            case 0x11:
                if (p->unk1C < p->unk20 + p->unk2C)
                    p->unk0 = p->unk0 + p->unk3C;
                break;
            case 0x12:
            case 0x13:
                if (p->unk1C < p->unk20 + p->unk2C) {
                    s = one;
                    p->unk14 = p->unk14 + p->unk3C * s;
                    if (p->unk14 >= 64.0f)
                        p->unk14 = 64.0f;
                    p->unk0 =
                        p->unk0 + p->unk40 * (gSineTable[(s32)(p->unk14 + 192.0f) & 0xFF] + 256.0f) * (1.0f / 256) * s;
                } else
                    p->unk0 = p->unk0 + p->unk40;
                break;
            case 0x14:
            case 0x15:
                if (p->unk1C < p->unk20 + p->unk2C)
                    p->unk0 = p->unk0 + p->unk3C;
                else {
                    p->unk14 = p->unk14 + p->unk40;
                    if (p->unk14 >= 64.0f)
                        p->unk14 = 64.0f;
                    p->unk0 = p->unk0 + p->unk3C * gSineTable[((s32)p->unk14 & 0xFF) + 0x40] * (1.0f / 256) * one;
                }
                break;
            case 0x17:
                p->unk14 = p->unk14 + p->unk3C;
                p->unk0 = p->unk4 + p->unk40 * gSineTable[(s32)p->unk14 & 0xFF] * one;
                break;
            }
            p->unk1C = p->unk1C + 1.0f;
            if (p->unk24 != 0xFFFF && p->unk1C >= p->unk24) {
                p->unkC = 0;
                ret = 1;
            }
        } else
            p->unk1C = p->unk1C + 1.0f;
    }
    return ret;
}

void sub_08057024(void) {
    gUnk_083D5E08[gGameSubState]();
}

void sub_08057044(void) {
    sub_080496C8((u8 *)&gUnk_030064A0, 0x874);
    LZ77UnCompVram(gUnk_085FA144, (void *)0x06000F80);
    LZ77UnCompVram(gUnk_085FA5D8, (void *)0x06002100);
    sub_080496C8((u8 *)gUnk_03006D14, 0x2000);
    DmaSet(3, gUnk_085FA4D8, gUnk_03006D14, DMA_ENABLE | (0xE0 / 2));
    DmaSet(3, gUnk_085FA620, gUnk_03006D14 + 0x200, DMA_ENABLE | (0x20 / 2));
    copy_tilemap_region((u16 *)gUnk_083D5F30, gUnk_03006D14 + 0x400, 0, 0, 0x10, 10, 0, 0xF, 0);
    fill_tilemap_rect_0804916C(gUnk_03006D14 + 0x800, 2, 0xE, 0x10, 10, 0, 0xF, 0);
    copy_tilemap_region(gUnk_03006D14, gUnk_03006D14 + 0x400, 1, 1, 0xE, 8, 0x7C, 0xE, 0);

    switch (check_vehicle_usability(0)) {
    case 0:
        LZ77UnCompVram(gUnk_085FA660, (void *)0x06016F80);
        break;
    case 1:
        LZ77UnCompVram(gUnk_085FAA98, (void *)0x06016F80);
        render_npc_tilemap_row(0);
        break;
    default:
        LZ77UnCompVram(gUnk_085FA87C, (void *)0x06016F80);
        break;
    }
    switch (check_vehicle_usability(1)) {
    case 0:
        LZ77UnCompVram(gUnk_085FA6E8, (void *)0x06017000);
        break;
    case 1:
        LZ77UnCompVram(gUnk_085FAA98, (void *)0x06017000);
        render_npc_tilemap_row(1);
        break;
    default:
        LZ77UnCompVram(gUnk_085FA904, (void *)0x06017000);
        break;
    }
    switch (check_vehicle_usability(2)) {
    case 0:
        LZ77UnCompVram(gUnk_085FA774, (void *)0x06017080);
        break;
    case 1:
        LZ77UnCompVram(gUnk_085FAA98, (void *)0x06017080);
        render_npc_tilemap_row(2);
        break;
    default:
        LZ77UnCompVram(gUnk_085FA990, (void *)0x06017080);
        break;
    }
    switch (check_vehicle_usability(3)) {
    case 0:
        LZ77UnCompVram(gUnk_085FA7FC, (void *)0x06017100);
        break;
    case 1:
        LZ77UnCompVram(gUnk_085FAA98, (void *)0x06017100);
        render_npc_tilemap_row(3);
        break;
    default:
        LZ77UnCompVram(gUnk_085FAA18, (void *)0x06017100);
        break;
    }

    DmaCopy32(3, gUnk_085FA640, OBJ_PLTT + 0x180, 32) DmaCopy32(3, gUnk_085FA85C, OBJ_PLTT + 0x1A0, 32)
        decompress_bg_tiles_to_vram_bg();
    DmaCopy32(3, gUnk_084C6998, PLTT + 0x1C0, 32) lz_decompress_dispatch(gUnk_084878EC, (void *)0x06002600);
    lz_decompress_dispatch(gUnk_0848796C, (void *)0x060026E0);
    lz_decompress_dispatch(gUnk_084C7318, (void *)0x06017E00);
    DmaCopy32(3, gUnk_084E2E58, OBJ_PLTT + 0x1C0, 32) gUnk_030064A0.unk66 = 0;
    gUnk_030064A0.unk67 = 0;
    gUnk_030064A0.unk6F = 0;
    gUnk_030064A0.unk6E = gUnk_030064A0.unk6D = gUnk_030064A0.unk6C = 0;
    gUnk_030064A0.unk6C = 0x10;
    gUnk_030064A0.unk6D = 3;
    sub_0804A1C4();
}

void sub_080572F8(void) {
    gUnk_030064A0.unk66 = 0;
    if (gUnk_030064A0.unk6F < 0x10) {
        gUnk_030064A0.unk6F++;
        copy_tilemap_rect_with_offset(gUnk_03006D14 + 0x400, (u16 *)0x06002800, 2, 0x1E - gUnk_030064A0.unk6F,
                                      gUnk_030064A0.unk6F, 10, 0x20, 0x20, 0, 0);
        init_vehicle_menu_sprite(0);
    } else {
        init_battle_sprite_entry_08048818(0x7F, 0xC004, 0x307, 0xC, 0);
        update_cursor_sprite_position();
        gUnk_030064A0.unk65 = 0;
        init_cursor_state();
        sub_0804A1C4();
    }
}

void sub_08057380(void) {
    sub_0804A1C4();
}

void sub_0805738C(void) {
    u32 r;

    gUnk_030064A0.unk67++;
    update_cursor_sprite_position();
    handle_cursor_up_down_input(4);
    if (KEYS_LO(gNewKeys) & 1) {
        r = check_vehicle_usability(gUnk_030064A0.unk65);
        if (r != 0) {
            gUnk_030064A0.unk67 = 0;
            update_cursor_sprite_position();
            sub_08047BA8(6);
            switch (r) {
            case 1:
                break;
            case 2:
                gUnk_030064A0.unk70 = 0;
                gGameSubState = 0xB;
                break;
            case 3:
                gGameSubState = 0xD;
                break;
            case 4:
            case 5:
            case 6:
                gGameSubState = 0xF;
                break;
            }
        } else {
            copy_tilemap_rect_with_offset((u16 *)0x06002800, gUnk_030064A0.unk72, 0, 0, 0x1E, 0x14, 0x20, 0x20, r, r);
            sub_08047BA8(4);
            gGameSubState = 0xA;
        }
    } else if (KEYS_LO(gNewKeys) & 2) {
        sub_08047BA8(5);
        clear_battle_sprite_entry(0x7F);
        gUnk_030064A0.unk6F = 0x10;
        sub_0804A1C4();
    }
}

void sub_08057494(void) {
    if (gUnk_030064A0.unk6F != 0) {
        copy_tilemap_rect_with_offset(gUnk_03006D14 + 0x800, (u16 *)0x06002800, 2, 0x1E - gUnk_030064A0.unk6F, 1, 10,
                                      0x20, 0x20, 0, 0);
        copy_tilemap_rect_with_offset(gUnk_03006D14 + 0x400, (u16 *)0x06002800, 2, 0x1F - gUnk_030064A0.unk6F,
                                      gUnk_030064A0.unk6F, 10, 0x20, 0x20, 0, 0);
        init_vehicle_menu_sprite(1);
        gUnk_030064A0.unk6F--;
    } else {
        lz_decompress_dispatch(gUnk_084C1ACC, (void *)0x06002100);
        sub_0804A1C4();
    }
}

void sub_08057540(void) {
    switch_game_mode(0x40, 0);
}

void sub_08057550(void) {
    setup_palette_fade_to_color_with_obj(0, 0.0f, 32.0f, 8.0f);
    sub_0804A1C4();
}

void sub_08057574(void) {
    if (run_blend_fade_transition(0))
        sub_0804A1C4();
}

void sub_08057588(void) {
    switch_game_mode(6, 0);
}

void sub_08057598(void) {
    u32 zero;

    sub_0804B1FC();
    sub_080496C8((u8 *)gUnk_03002C30, 0x2000);
    sub_080496C8((u8 *)gUnk_030055A0, 0x200);
    zero = 0;
    DmaSet(3, &zero, OAM, 0x85000100);
    REG_DISPCNT = 0x1F40;
    gUnk_030057E0.unkCBA = 1;
    update_battle_field_frame();
    lz_decompress_dispatch(gUnk_084C1C14, (void *)0x060017E0);
    lz_decompress_dispatch(gUnk_084C1608, (void *)0x06001800);
    lz_decompress_dispatch(gUnk_084C17F0, (void *)0x06001B00);
    lz_decompress_dispatch(gUnk_084C1934, (void *)0x06001E00);
    lz_decompress_dispatch(gUnk_084C1ACC, (void *)0x06002100);
    lz_decompress_dispatch(gUnk_08487708, (void *)0x06002400);
    DmaCopy32(3, gUnk_08488A84, 0x0202FBE0, 32) lz_decompress_dispatch(gUnk_084C6A98, (void *)0x06017400);
    DmaCopy32(3, gUnk_084E2E38, 0x0202F9E0, 32) LZ77UnCompVram(gUnk_085FA144, (void *)0x06000F80);
    LZ77UnCompVram(gUnk_085FA5D8, (void *)0x06002100);
    sub_080496C8((u8 *)gUnk_03006D14, 0x2000);
    DmaSet(3, gUnk_085FA4D8, gUnk_03006D14, DMA_ENABLE | (0xE0 / 2));
    DmaSet(3, gUnk_085FA620, gUnk_03006D14 + 0x200, DMA_ENABLE | (0x20 / 2));
    copy_tilemap_region((u16 *)gUnk_083D5F30, gUnk_03006D14 + 0x400, 0, 0, 0x10, 10, 0, 0xF, 0);
    fill_tilemap_rect_0804916C(gUnk_03006D14 + 0x800, 2, 0xE, 0x10, 10, 0, 0xF, 0);
    copy_tilemap_region(gUnk_03006D14, gUnk_03006D14 + 0x400, 1, 1, 0xE, 8, 0x7C, 0xE, 0);

    switch (check_vehicle_usability(0)) {
    case 0:
        LZ77UnCompVram(gUnk_085FA660, (void *)0x06016F80);
        break;
    case 1:
        LZ77UnCompVram(gUnk_085FAA98, (void *)0x06016F80);
        render_npc_tilemap_row(0);
        break;
    default:
        LZ77UnCompVram(gUnk_085FA87C, (void *)0x06016F80);
        break;
    }
    switch (check_vehicle_usability(1)) {
    case 0:
        LZ77UnCompVram(gUnk_085FA6E8, (void *)0x06017000);
        break;
    case 1:
        LZ77UnCompVram(gUnk_085FAA98, (void *)0x06017000);
        render_npc_tilemap_row(1);
        break;
    default:
        LZ77UnCompVram(gUnk_085FA904, (void *)0x06017000);
        break;
    }
    switch (check_vehicle_usability(2)) {
    case 0:
        LZ77UnCompVram(gUnk_085FA774, (void *)0x06017080);
        break;
    case 1:
        LZ77UnCompVram(gUnk_085FAA98, (void *)0x06017080);
        render_npc_tilemap_row(2);
        break;
    default:
        LZ77UnCompVram(gUnk_085FA990, (void *)0x06017080);
        break;
    }
    switch (check_vehicle_usability(3)) {
    case 0:
        LZ77UnCompVram(gUnk_085FA7FC, (void *)0x06017100);
        break;
    case 1:
        LZ77UnCompVram(gUnk_085FAA98, (void *)0x06017100);
        render_npc_tilemap_row(3);
        break;
    default:
        LZ77UnCompVram(gUnk_085FAA18, (void *)0x06017100);
        break;
    }

    lz_decompress_dispatch(gUnk_084873D0, (void *)0x06000020);
    lz_decompress_dispatch(gUnk_084C31BC, (void *)0x06001780);
    DmaCopy32(3, gUnk_08488A84, 0x0202FBE0, 32) DmaCopy32(3, gUnk_084C6998, 0x0202FBC0, 32)
        lz_decompress_dispatch(gUnk_084878EC, (void *)0x06002600);
    lz_decompress_dispatch(gUnk_0848796C, (void *)0x060026E0);
    lz_decompress_dispatch(gUnk_084C7318, (void *)0x06017E00);
    DmaCopy32(3, gUnk_084E2E58, 0x0202F9C0, 32)
        copy_tilemap_rect_with_offset(gUnk_030064A0.unk72, (u16 *)0x06002800, 0, 0, 0x1E, 0x14, 0x20, 0x20, 0, 0);
    DmaCopy32(3, gUnk_085FA640, 0x0202F980, 32) DmaCopy32(3, gUnk_085FA85C, 0x0202F9A0, 32) init_vehicle_menu_sprite(0);
    setup_palette_fade_to_color(0, 32.0f, 0.0f, 8.0f);
    sub_0804A1C4();
}

void sub_08057988(void) {
    if (run_blend_fade_transition(0)) {
        init_battle_sprite_entry_08048818(0x7F, 0xC004, 0x307, 0xC, 0);
        update_cursor_sprite_position();
        gGameSubState = 2;
    }
}

void sub_080579C4(void) {
    struct Unk_030064A0 *s = &gUnk_030064A0;

    if (s->unk65 != 2) {
        sub_0804B1FC();
        sub_08057EBC();
    }
    clear_battle_sprite_entry(0x7F);
    if (s->unk65 == 0)
        switch_game_mode(0x41, 0);
    else if (s->unk65 == 1)
        switch_game_mode(0x43, 0);
    else if (s->unk65 == 2)
        gGameSubState = 5;
    else if (s->unk65 == 3)
        switch_game_mode(0x42, 0);
}

void sub_08057A24(void) {
    u32 id;

    if (gUnk_030064A0.unk65 == 0) {
        id = 0x55;
        switch (gUnk_030064A0.unk70) {
        case 0:
            copy_string_to_text_buffer(0, sub_08047BDC(id));
            break;
        case 1:
            copy_string_to_text_buffer(0, sub_08047BEC(0, id));
            break;
        case 2:
            copy_string_to_text_buffer(1, sub_08047BEC(1, id));
            break;
        case 3:
            copy_string_to_text_buffer(2, sub_08047BEC(2, id));
            break;
        case 4:
            copy_string_to_text_buffer(3, sub_08047BEC(3, id));
            break;
        case 5:
            copy_string_to_text_buffer(0, sub_08047BDC(id));
            break;
        }
    } else if (gUnk_030064A0.unk65 == 2) {
        id = 0xB;
        switch (gUnk_030064A0.unk70) {
        case 0:
            copy_string_to_text_buffer(0, sub_08047BDC(id));
            break;
        case 1:
            copy_string_to_text_buffer(0, sub_08047BEC(0, id));
            break;
        case 2:
            copy_string_to_text_buffer(1, sub_08047BEC(1, id));
            break;
        case 3:
            copy_string_to_text_buffer(2, sub_08047BEC(2, id));
            break;
        case 4:
            copy_string_to_text_buffer(3, sub_08047BEC(3, id));
            break;
        case 5:
            copy_string_to_text_buffer(0, sub_08047BDC(id));
            break;
        }
    } else if (gUnk_030064A0.unk65 == 3) {
        id = 0x6B;
        switch (gUnk_030064A0.unk70) {
        case 0:
            copy_string_to_text_buffer(0, sub_08047BDC(id));
            break;
        case 1:
            copy_string_to_text_buffer(0, sub_08047BEC(0, id));
            break;
        case 2:
            copy_string_to_text_buffer(1, sub_08047BEC(1, id));
            break;
        case 3:
            copy_string_to_text_buffer(2, sub_08047BEC(2, id));
            break;
        case 4:
            copy_string_to_text_buffer(3, sub_08047BEC(3, id));
            break;
        case 5:
            copy_string_to_text_buffer(0, sub_08047BDC(id));
            break;
        }
    }
    if (gUnk_030064A0.unk70 == 0)
        init_cursor_state();
    sub_0804A1C4();
}

void sub_08057B68(void) {
    if (scene_transition_step_08047C24(1, 1, 0, gTextTable[gUnk_030064A0.unk70 + 0x82])) {
        if (++gUnk_030064A0.unk70 <= 5)
            gGameSubState--;
        else
            gGameSubState = 2;
    }
}

void sub_08057BBC(void) {
    init_cursor_state();
    sub_0804A1C4();
}

void sub_08057BCC(void) {
    if (scene_transition_step_08047C24(1, 1, 0, gTextTable[0x81]))
        gGameSubState = 2;
}

void sub_08057BF8(void) {
    init_cursor_state();
    sub_0804A1C4();
}

void sub_08057C08(void) {
    if (scene_transition_step_08047C24(1, 1, 0, gTextTable[0x80]))
        gGameSubState = 2;
}

void nullsub_08057C34(void) {}

u32 check_vehicle_usability(s32 idx) {
    u32 ret = 0;
    s32 n;
    u32 ok;
    u32 flag;

    switch (idx) {
    case 0:
        flag = sub_08047D8C(0x12);
        ret = 1;
        if (!flag)
            break;
        n = check_position_table_match(0x55, 0);
        n += check_position_table_match(0x55, 1);
        n += check_position_table_match(0x55, 2);
        n += check_position_table_match(0x55, 3);
        ret = 2;
        if (n != 4)
            break;
        ok = sub_0804803C(0);
        ret = 3;
        if (!ok)
            break;
        flag = gUnk_030057E0.unkC5D & 2;
        ret = 4;
        if (flag)
            break;
        ret = 0;
        if (gUnk_030057E0.unkC5C == 2)
            ret = 5;
        break;
    case 1:
        flag = sub_08047D8C(0x18);
        ret = 1;
        if (!flag)
            break;
        flag = gUnk_030057E0.unkC5D & 0x10;
        ret = 4;
        if (flag)
            break;
        ret = 0;
        if (gUnk_030057E0.unkC5C == 1 || gUnk_030057E0.unkC5C == 2)
            ret = 5;
        break;
    case 2:
        flag = sub_08047D8C(0x19);
        ret = 1;
        if (!flag)
            break;
        n = check_position_table_match(0xB, 0);
        n += check_position_table_match(0xB, 1);
        n += check_position_table_match(0xB, 2);
        n += check_position_table_match(0xB, 3);
        ret = 2;
        if (n != 4)
            break;
        ok = sub_0804803C(1);
        if (gUnk_083D29EB[gUnk_030057E0.unk7FE] == 0xA)
            ok = 0;
        ret = 3;
        if (!ok)
            break;
        flag = gUnk_030057E0.unkC5D & 4;
        ret = 4;
        if (flag)
            break;
        ret = 0;
        if (gUnk_030057E0.unkC5C == 1 || gUnk_030057E0.unkC5C == 2)
            ret = 5;
        break;
    case 3:
        flag = sub_08047D8C(0x26);
        ret = 1;
        if (!flag)
            break;
        n = check_position_table_match(0x6B, 0);
        n += check_position_table_match(0x6B, 1);
        n += check_position_table_match(0x6B, 2);
        n += check_position_table_match(0x6B, 3);
        ret = 2;
        if (n != 4)
            break;
        flag = gUnk_030057E0.unkC5D & 8;
        ret = 4;
        if (flag)
            break;
        flag = (u8)(gUnk_030057E0.unkC5C - 1);
        ret = 5;
        if (flag <= 1)
            break;
        ret = 0;
        if (get_adjacent_tile_value(gUnk_030057E0.unkC67) != 3)
            ret = 6;
        break;
    }
    return ret;
}

void handle_cursor_up_down_input(s32 count) {
    struct Unk_030064A0 *s;

    gUnk_030057A0.unk15++;
    if (KEYS_LO(gRepeatKeys) & 0x40) {
        sub_08047BA8(2);
        s = &gUnk_030064A0;
        if (--s->unk65 == 0xFF)
            s->unk65 = count - 1;
        s->unk6D = gUnk_083D5F2C[s->unk65];
        update_cursor_sprite_position();
    }
    if (KEYS_LO(gRepeatKeys) & 0x80) {
        sub_08047BA8(2);
        s = &gUnk_030064A0;
        s->unk65++;
        if (s->unk65 >= count)
            s->unk65 = 0;
        s->unk6D = gUnk_083D5F2C[s->unk65];
        update_cursor_sprite_position();
    }
}

void sub_08057EBC(void) {
    clear_battle_sprite_entry(0x20);
    clear_battle_sprite_entry(0x21);
    clear_battle_sprite_entry(0x22);
    clear_battle_sprite_entry(0x23);
}

void update_cursor_sprite_position(void) {
    struct Unk_030064A0 *s = &gUnk_030064A0;
    s32 d = (u8)(s->unk67 & 4) >> 2;

    if (s->unk67 & 8)
        d = -d;
    gUnk_03002C30[0x7F].unk2 = s->unk6C * 8 + 8 + d;
    gUnk_03002C30[0x7F].unk4 = s->unk6D * 8 + 8;
    gUnk_03002C30[0x7F].unk6 = 0x307;
    gUnk_03002C30[0x7F].unkA = 0xE;
    gUnk_03002C30[0x7F].unk1C = 0;
    gUnk_03002C30[0x7F].unk8 = 1;
    gUnk_03002C30[0x7F].unk9 = 1;
    gUnk_03002C30[0x7F].unkB = 0xFF;
}

void init_vehicle_menu_sprite(s32 x) {
    s32 ox;

    init_battle_sprite_entry_08048818(0x20, 0xC004, 0x91, check_vehicle_usability(0) == 0 ? 0xC : 0xD, 1);
    gUnk_03002C30[0x20].unk2 = (0x10 - gUnk_030064A0.unk6F) * 8 + (ox = x * 8 + 0x90);
    gUnk_03002C30[0x20].unk4 = 0x18;
    gUnk_03002C30[0x20].unkB |= 0xFF;
    init_battle_sprite_entry_08048818(0x21, 0xC004, 0x92, check_vehicle_usability(1) == 0 ? 0xC : 0xD, 1);
    gUnk_03002C30[0x21].unk2 = (0x10 - gUnk_030064A0.unk6F) * 8 + ox;
    gUnk_03002C30[0x21].unk4 = 0x28;
    gUnk_03002C30[0x21].unkB |= 0xFF;
    init_battle_sprite_entry_08048818(0x22, 0xC004, 0x93, check_vehicle_usability(2) == 0 ? 0xC : 0xD, 1);
    gUnk_03002C30[0x22].unk2 = (0x10 - gUnk_030064A0.unk6F) * 8 + ox;
    gUnk_03002C30[0x22].unk4 = 0x38;
    gUnk_03002C30[0x22].unkB |= 0xFF;
    init_battle_sprite_entry_08048818(0x23, 0xC004, 0x94, check_vehicle_usability(3) == 0 ? 0xC : 0xD, 1);
    gUnk_03002C30[0x23].unk2 = (0x10 - gUnk_030064A0.unk6F) * 8 + ox;
    gUnk_03002C30[0x23].unk4 = 0x48;
    gUnk_03002C30[0x23].unkB |= 0xFF;
}

void render_npc_tilemap_row(s32 row) {
    copy_tilemap_region(gUnk_03006D14 + 0x200, gUnk_03006D14 + 0x400, row * 2 + 1, 6, 8, 2, 0x108, 0xE, 0);
}

void sub_08058110(void) {
    dispatch_by_index(gUnk_030057A0.unk14);
}

void dispatch_by_index(u32 idx) {
    switch (idx) {
    case 0:
        gUnk_030057A0.unk26 = gUnk_030057E0.unk7FE;
        break;
    case 1:
        gUnk_030057A0.unk28 = gUnk_030057E0.unkC90;
        gUnk_030057A0.unk2A = sub_08053194(gUnk_030057A0.unk28);
        gUnk_030057A0.unk2C = sub_08053288(gUnk_030057A0.unk28);
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        gUnk_030057A0.unk32 = 0;
        break;
    case 6:
        gUnk_030057A0.unk32 = 0;
        gUnk_030057A0.unk24 = 0;
        break;
    }
}

void sub_080581C0(u32 a, s32 b) {
    switch (a) {
    case 0:
        break;
    case 1:
        if (b == 0) {
            gUnk_030057A0.unk2A = sub_08053194(gUnk_030057A0.unk28);
            gUnk_030057A0.unk2C = sub_08053288(gUnk_030057A0.unk28);
        } else if (b < 0) {
        } else if (b <= 2) {
            sub_080531D0(gUnk_030057A0.unk28, gUnk_030057A0.unk2A);
            sub_080531EC(gUnk_030057A0.unk28, gUnk_030057A0.unk2C);
        }
        break;
    }
}

// Local view of gUnk_030057A0 (struct Unk_030057A0 would need unk0, unk12, unk15, s8 unk16[8], unk1E,

void sub_08058214(u32 mode) {
    gUnk_030057A0.unk15++;

    switch (mode) {
    case 0:
        sub_0805889C(6);
        switch (gUnk_030057A0.unk16[gUnk_030057A0.unk14]) {
        case 0:
            sub_08058A88(gUnk_030057A0.unk14, gUnk_030057A0.unk16[gUnk_030057A0.unk14], 0xC0);
            break;
        case 1:
            sub_08058A88(gUnk_030057A0.unk14, gUnk_030057A0.unk16[gUnk_030057A0.unk14], 0x10);
            break;
        case 3:
            sub_08058A88(gUnk_030057A0.unk14, gUnk_030057A0.unk16[gUnk_030057A0.unk14], 4);
            break;
        case 4:
            sub_08058A88(gUnk_030057A0.unk14, gUnk_030057A0.unk16[gUnk_030057A0.unk14], 10);
            break;
        case 2:
        case 5:
            sub_08058A88(gUnk_030057A0.unk14, gUnk_030057A0.unk16[gUnk_030057A0.unk14], 2);
            break;
        }
        break;
    case 1:
        sub_0805889C(3);
        switch (gUnk_030057A0.unk16[gUnk_030057A0.unk14]) {
        case 0:
            sub_08058908(0, 3000);
            break;
        case 1:
            sub_08058908(1, 2);
            break;
        case 2:
            sub_08058908(2, 8);
            break;
        }
        break;
    case 2:
        if (KEYS_LO(gRepeatKeys) & 0x40)
            gUnk_030057E0.unkC54 -= 0x10;
        if (KEYS_LO(gRepeatKeys) & 0x80)
            gUnk_030057E0.unkC54 += 0x10;
        if (KEYS_LO(gRepeatKeys) & 0x20)
            gUnk_030057E0.unkC52 -= 0x10;
        if (KEYS_LO(gRepeatKeys) & 0x10)
            gUnk_030057E0.unkC52 += 0x10;
        gUnk_030057E0.unkC56 = sub_080526F0(gUnk_030057E0.unkC52);
        gUnk_030057E0.unkC57 = sub_08052714(gUnk_030057E0.unkC54);
        field_center_camera_on_player();
        break;
    case 3:
        if (KEYS_LO(gRepeatKeys) & 0x20) {
            if (--gUnk_030057A0.unk12 == 0xFF)
                gUnk_030057A0.unk12 = 0x1F;
        }
        if (KEYS_LO(gRepeatKeys) & 0x10) {
            if (++gUnk_030057A0.unk12 > 0x1F)
                gUnk_030057A0.unk12 = 0;
        }
        break;
    case 4:
        sub_0805889C(6);
        switch (gUnk_030057A0.unk16[gUnk_030057A0.unk14]) {
        case 1:
            sub_08058A88(gUnk_030057A0.unk14, gUnk_030057A0.unk16[gUnk_030057A0.unk14], 3);
            break;
        case 2:
            sub_08058A88(gUnk_030057A0.unk14, gUnk_030057A0.unk16[gUnk_030057A0.unk14], 4);
            break;
        case 0:
        case 3:
        case 4:
            sub_08058A88(gUnk_030057A0.unk14, gUnk_030057A0.unk16[gUnk_030057A0.unk14], 2);
            break;
        case 5:
            sub_08058A88(gUnk_030057A0.unk14, gUnk_030057A0.unk16[gUnk_030057A0.unk14], 3);
            break;
        }
        REG_BLDALPHA = ((gUnk_03006F40.unk4 & 0x3F) << 8) | (gUnk_03006F40.unk3 & 0x3F);
        REG_BLDY = gUnk_03006F40.unk5 & 0x3F;
        break;
    case 5:
        sub_08058A88(gUnk_030057A0.unk14, gUnk_030057A0.unk16[gUnk_030057A0.unk14], 0xB0);
        gUnk_030057A0.unk32 = 1;
        break;
    case 6:
        if (gUnk_030057A0.unk32 == 0) {
            const u32 *const *p;
            s32 n;

            sub_0805889C(3);
            switch (gUnk_030057A0.unk16[gUnk_030057A0.unk14]) {
            case 0:
                sub_080589B0(0, 0x10);
                break;
            case 1:
                sub_080589B0(1, gUnk_030057A0.unk1E);
                break;
            case 2:
                sub_080589B0(2, 2);
                break;
            }
            p = (const u32 *const *)gTextBankTables[gUnk_030057A0.unk20];
            n = 0;
            if (*p != 0) {
                do {
                    p++;
                    n++;
                    if (n > 0xFFF)
                        break;
                } while (*p != 0);
            }
            gUnk_030057A0.unk1E = n;
            if (gUnk_030057A0.unk30 >= (u16)n)
                gUnk_030057A0.unk30 = n - 1;
        }
        break;
    case 7:
        sub_0805889C(5);
        switch (gUnk_030057A0.unk16[gUnk_030057A0.unk14]) {
        case 0:
        case 1:
            update_anim_counter(gUnk_030057A0.unk16[gUnk_030057A0.unk14], 0x20);
            break;
        case 2:
            update_anim_counter(gUnk_030057A0.unk16[gUnk_030057A0.unk14], 0x80);
            break;
        case 3:
            update_anim_counter(gUnk_030057A0.unk16[gUnk_030057A0.unk14], 0xA0);
            break;
        case 4:
            update_anim_counter(gUnk_030057A0.unk16[gUnk_030057A0.unk14], 0x100);
            break;
        }
        switch (gUnk_030057A0.unk16[gUnk_030057A0.unk14]) {
        case 2:
            if (KEYS_LO(gRepeatKeys) & 1)
                sub_08047BB4(gUnk_030057A0.unk33);
            break;
        case 3:
            if (KEYS_LO(gRepeatKeys) & 1)
                sub_08047BA8(gUnk_030057A0.unk34);
            break;
        case 1:
            break;
        }
        break;
    }

    if (KEYS_LO(gNewKeys) & 4) {
        if (++gUnk_030057A0.unk14 > 7)
            gUnk_030057A0.unk14 = 0;
        clear_all_battle_sprites();
        dispatch_by_index(gUnk_030057A0.unk14);
    }
    if (KEYS_LO(gRepeatKeys) & 2)
        handle_battle_end_state_transition();
    if (KEYS_LO(gRepeatKeys) & 1) {
        switch (gUnk_030057A0.unk14) {
        case 3:
            gUnk_030057A0.unk10 = 0;
            clear_all_battle_sprites();
            init_sprite_affine_matrices_and_state(gUnk_030057A0.unk12, gUnk_030057E0.unkC52, gUnk_030057E0.unkC54, 0);
            if (gUnk_030057A0.unk12 == 0xE)
                gUnk_030057E0.unkC5C = 0xC;
            else if (gUnk_030057A0.unk12 == 0x12)
                gUnk_030057E0.unkC5C = 0xB;
            if (gUnk_030057A0.unk12 == 0xE || gUnk_030057A0.unk12 == 0x12) {
                decompress_battle_tile_graphics();
                DmaCopy32(3, gUnk_083F8634[gUnk_083D29A6[gUnk_030057E0.unkC5C]], OBJ_PLTT, 32);
                gUnk_030057E0.unkC28 = gUnk_030057E0.unkC5C;
                load_battle_terrain_data();
            }
            gGameSubState++;
            break;
        case 0:
        case 1:
        case 2:
        case 5:
            break;
        case 4:
            play_sound_effect(gUnk_030057A0.unk0);
            break;
        case 6:
            if (gUnk_030057A0.unk32 == 0) {
                if (gUnk_030057A0.unk24 != 0) {
                    gUnk_030057A0.unk30++;
                    if (gUnk_030057A0.unk30 >= gUnk_030057A0.unk1E) {
                        gUnk_030057A0.unk30 = 0;
                        gUnk_030057A0.unk2E++;
                        if (gUnk_030057A0.unk2E > 0xF)
                            gUnk_030057A0.unk2E = 0;
                    }
                }
                gUnk_030057A0.unk15 = 0;
                sub_08058B04(gUnk_030057A0.unk14);
                init_cursor_state();
                gUnk_030057A0.unk32++;
            }
            break;
        }
    }
}

void sub_0805889C(s32 max) {
    if (KEYS_LO(gRepeatKeys) & 0x40) {
        gUnk_030057A0.unk16[gUnk_030057A0.unk14]--;
        if (gUnk_030057A0.unk16[gUnk_030057A0.unk14] < 0)
            gUnk_030057A0.unk16[gUnk_030057A0.unk14] = max - 1;
    }
    if (KEYS_LO(gRepeatKeys) & 0x80) {
        gUnk_030057A0.unk16[gUnk_030057A0.unk14]++;
        if (gUnk_030057A0.unk16[gUnk_030057A0.unk14] >= max)
            gUnk_030057A0.unk16[gUnk_030057A0.unk14] = 0;
    }
}

void sub_08058908(u32 idx, s32 max) {
    u8 left;
    u16 *p;
    s32 step = 1;

    if (KEYS_HI(gHeldKeys) & 1)
        step = 0x10;

    if ((left = KEYS_LO(gRepeatKeys) & 0x20)) {
        p = gUnk_083D6070[idx];
        if ((u16)(*p -= step) == 0xFFFF)
            *p = max - 1;
        sub_080581C0(gUnk_030057A0.unk14, gUnk_030057A0.unk16[gUnk_030057A0.unk14]);
    } else if (KEYS_LO(gRepeatKeys) & 0x10) {
        p = gUnk_083D6070[idx];
        *p += step;
        if (*p >= max)
            *p = left;
        sub_080581C0(gUnk_030057A0.unk14, gUnk_030057A0.unk16[gUnk_030057A0.unk14]);
    }
}

void sub_080589B0(u32 idx, s32 max) {
    s32 v;
    u16 *p;
    s32 step = 1;

    if (KEYS_HI(gHeldKeys) & 1)
        step = 0x10;

    if (KEYS_LO(gRepeatKeys) & 0x20) {
        p = gUnk_083D607C[idx];
        v = *p;
        v -= step;
        if (v == -1)
            v = max - 1;
        *p = v;
    } else if (KEYS_LO(gRepeatKeys) & 0x10) {
        p = gUnk_083D607C[idx];
        v = *p;
        v += step;
        if (v >= max)
            v = 0;
        *p = v;
    }
}

void update_anim_counter(u32 idx, s32 max) {
    u8 left;
    u8 *p;

    if ((left = KEYS_LO(gRepeatKeys) & 0x20)) {
        p = gUnk_083D6088[idx];
        if ((s8)-- * p == -1)
            *p = max - 1;
    } else if (KEYS_LO(gRepeatKeys) & 0x10) {
        p = gUnk_083D6088[idx];
        (*p)++;
        if (*p >= max)
            *p = left;
    }
}

void sub_08058A88(u32 idx, u32 sub, s32 max) {
    u8 changed = 0;
    s32 v;
    u8 **row;

    if (KEYS_LO(gRepeatKeys) & 0x20) {
        u8 *p;
        row = gUnk_083D60DC[idx];
        p = row[sub];
        v = *p;
        v -= 1;
        if (v == -1)
            v = max - 1;
        *p = v;
        changed = 1;
    } else if (KEYS_LO(gRepeatKeys) & 0x10) {
        u8 *p;
        row = gUnk_083D60DC[idx];
        p = row[sub];
        v = *p;
        v += 1;
        if (v >= max)
            v = 0;
        *p = v;
        changed = 1;
    }
    if (changed && idx == 5)
        init_battle_field_sprites();
}

void sub_08058B04(u32 mode) {
    gUnk_030057A0.unk13 = 0;
    update_bg_scroll_offsets_a();
    load_battle_sprite_tile(gUnk_080AC494, 2, 0x28, 0x18);
    load_battle_sprite_from_index(gUnk_030057A0.unk14, 8, 0x50, 0x18);
    switch (mode) {
    case 0:
        load_battle_sprite_tile(gUnk_080AC498, 2, 0x68, 0x18);
        load_battle_sprite_tile(gUnk_080AC49C, 2, 0x30, 0x20);
        load_or_clear_battle_sprites(0, gUnk_030057A0.unk26, 8, 0x50, 0x20);
        load_battle_sprite_tile(gUnk_080AC4A0, 2, 0x30, 0x28);
        load_or_clear_battle_sprites(1, gUnk_030057E0.unkC5C, 8, 0x50, 0x28);
        switch (gUnk_030057E0.unkC5C) {
        case 0:
            load_battle_sprite_tile(gUnk_080AC4A4, 3, 0x70, 0x28);
            break;
        case 1:
            load_battle_sprite_tile(gUnk_080AC4A8, 3, 0x70, 0x28);
            break;
        case 2:
            load_battle_sprite_tile(gUnk_080AC4AC, 3, 0x70, 0x28);
            break;
        case 3:
            load_battle_sprite_tile(gUnk_080AC4B0, 3, 0x70, 0x28);
            break;
        case 4:
            load_battle_sprite_tile(gUnk_080AC4B4, 3, 0x70, 0x28);
            break;
        case 5:
            load_battle_sprite_tile(gUnk_080AC4B8, 3, 0x70, 0x28);
            break;
        case 6:
            load_battle_sprite_tile(gUnk_080AC4BC, 3, 0x70, 0x28);
            break;
        case 7:
            load_battle_sprite_tile(gUnk_080AC4C0, 3, 0x70, 0x28);
            break;
        case 8:
            load_battle_sprite_tile(gUnk_080AC4C4, 3, 0x70, 0x28);
            break;
        case 9:
            load_battle_sprite_tile(gUnk_080AC4C8, 3, 0x70, 0x28);
            break;
        case 10:
            load_battle_sprite_tile(gUnk_080AC4CC, 3, 0x70, 0x28);
            break;
        case 11:
            load_battle_sprite_tile(gUnk_080AC4D0, 3, 0x70, 0x28);
            break;
        case 12:
            load_battle_sprite_tile(gUnk_080AC4D4, 3, 0x70, 0x28);
            break;
        case 13:
            load_battle_sprite_tile(gUnk_080AC4D8, 3, 0x70, 0x28);
            break;
        case 14:
            load_battle_sprite_tile(gUnk_080AC4DC, 3, 0x70, 0x28);
            break;
        case 15:
            load_battle_sprite_tile(gUnk_080AC4E0, 3, 0x70, 0x28);
            break;
        }
        load_battle_sprite_tile(gUnk_080AC4E4, 2, 0x30, 0x30);
        load_or_clear_battle_sprites(2, gUnk_030057E0.unkC4D, 8, 0x50, 0x30);
        load_battle_sprite_tile(gUnk_080AC4E8, 2, 0x30, 0x38);
        load_or_clear_battle_sprites(3, gUnk_030057E0.unkCB7, 8, 0x50, 0x38);
        switch (gUnk_030057E0.unkCB7) {
        case 0:
            load_battle_sprite_tile(gUnk_080AC4EC, 2, 0x70, 0x38);
            break;
        case 1:
            load_battle_sprite_tile(gUnk_080AC498, 2, 0x70, 0x38);
            break;
        case 2:
            load_battle_sprite_tile(gUnk_080AC4F0, 2, 0x70, 0x38);
            break;
        case 3:
            load_battle_sprite_tile(gUnk_080AC4F4, 2, 0x70, 0x38);
            break;
        }
        load_battle_sprite_tile(gUnk_080AC4F8, 2, 0x30, 0x40);
        load_or_clear_battle_sprites(4, gUnk_030057E0.unk7FF, 8, 0x50, 0x40);
        load_battle_sprite_tile(gUnk_080AC4FC, 2, 0x30, 0x48);
        load_or_clear_battle_sprites(5, gUnk_030057E0.unkC33, 8, 0x50, 0x48);
        break;
    case 1:
        load_battle_sprite_tile(gUnk_080AC500, 5, 0x68, 0x18);
        load_battle_sprite_tile(gUnk_080AC508, 3, 0x30, 0x20);
        load_or_clear_battle_sprites(0, *gUnk_083D6070[0], 16, 0x50, 0x20);
        load_battle_sprite_tile(gUnk_080AC50C, 3, 0x30, 0x28);
        load_or_clear_battle_sprites(1, *gUnk_083D6070[1], 8, 0x50, 0x28);
        load_battle_sprite_tile(gUnk_080AC510, 1, 0x70, 0x28);
        load_battle_sprite_tile(gUnk_080AC514, 2, 0x30, 0x30);
        load_or_clear_battle_sprites(2, *gUnk_083D6070[2], 8, 0x50, 0x30);
        load_battle_sprite_tile(gUnk_080AC510, 1, 0x70, 0x30);
        break;
    case 2:
        load_battle_sprite_tile(gUnk_080AC518, 6, 0x68, 0x18);
        load_battle_sprite_tile(gUnk_080AC520, 3, 0x30, 0x20);
        load_or_clear_battle_sprites(0, gUnk_030057E0.unkC52, 16, 0x50, 0x20);
        load_battle_sprite_tile(gUnk_080AC524, 3, 0x30, 0x28);
        load_or_clear_battle_sprites(0, gUnk_030057E0.unkC54, 16, 0x50, 0x28);
        break;
    case 3:
        load_battle_sprite_tile(gUnk_080AC528, 10, 0x68, 0x18);
        load_battle_sprite_tile(gUnk_080AC534, 3, 0x30, 0x20);
        load_or_clear_battle_sprites(0, gUnk_030057A0.unk12, 16, 0x50, 0x20);
        break;
    case 4:
        load_battle_sprite_tile(gUnk_080AC538, 3, 0x68, 0x18);
        load_battle_sprite_tile(gUnk_080AC53C, 2, 0x30, 0x20);
        load_or_clear_battle_sprites(0, gUnk_030057A0.unk11, 8, 0x50, 0x20);
        load_battle_sprite_tile(gUnk_080AC540, 2, 0x30, 0x28);
        load_or_clear_battle_sprites(1, gUnk_03006D38.unk2, 8, 0x50, 0x28);
        load_battle_sprite_tile(gUnk_080AC544, 2, 0x30, 0x30);
        load_or_clear_battle_sprites(2, gUnk_030057E0.unkC4E, 8, 0x50, 0x30);
        if (gUnk_030057E0.unkC4E & 1)
            load_battle_sprite_tile(gUnk_080AC548, 1, 0x70, 0x30);
        else
            load_battle_sprite_tile(gUnk_080AC54C, 1, 0x70, 0x30);
        if (gUnk_030057E0.unkC4E & 2)
            load_battle_sprite_tile(gUnk_080AC550, 1, 0x90, 0x30);
        else
            load_battle_sprite_tile(gUnk_080AC54C, 1, 0x90, 0x30);
        load_battle_sprite_tile(gUnk_080AC554, 2, 0x30, 0x38);
        load_or_clear_battle_sprites(3, gUnk_030057E0.unkCB8, 8, 0x50, 0x38);
        load_battle_sprite_tile(gUnk_080AC558, 2, 0x30, 0x40);
        load_or_clear_battle_sprites(4, gUnk_030057E0.unkCB9, 8, 0x50, 0x40);
        load_battle_sprite_tile(gUnk_080AC510, 1, 0x70, 0x40);
        load_battle_sprite_tile(gUnk_080AC55C, 2, 0x30, 0x48);
        load_or_clear_battle_sprites(5, gUnk_030057E0.unkC4F, 8, 0x50, 0x48);
        switch (gUnk_030057E0.unkC4F) {
        case 0:
            load_battle_sprite_tile(gUnk_080AC560, 1, 0x70, 0x48);
            break;
        case 1:
            load_battle_sprite_tile(gUnk_080AC564, 1, 0x70, 0x48);
            break;
        case 2:
            load_battle_sprite_tile(gUnk_080AC568, 1, 0x70, 0x48);
            break;
        }
        break;
    case 5:
        load_battle_sprite_tile(gUnk_080AC56C, 4, 0x68, 0x18);
        load_battle_sprite_tile(gUnk_080AC574, 3, 0x30, 0x20);
        load_or_clear_battle_sprites(0, gUnk_030057A0.unk20, 16, 0x50, 0x20);
        if (gUnk_030057A0.unk32 != 0) {
            advance_sprite_animation_frame(0x31);
            advance_sprite_animation_frame(0x32);
            advance_sprite_animation_frame(0x33);
            advance_sprite_animation_frame(0x34);
            if (gUnk_083D2C3D[gUnk_030057A0.unk20] == 3)
                advance_sprite_animation_frame(0x39);
        }
        break;
    case 6:
        switch (gUnk_030057A0.unk32) {
        case 0:
            load_battle_sprite_tile(gUnk_080AC578, 4, 0x68, 0x18);
            load_battle_sprite_tile(gUnk_080AC580, 3, 0x30, 0x20);
            load_or_clear_battle_sprites(0, gUnk_030057A0.unk2E, 16, 0x50, 0x20);
            load_battle_sprite_tile(gUnk_080AC584, 3, 0x30, 0x28);
            load_or_clear_battle_sprites(1, gUnk_030057A0.unk30, 16, 0x50, 0x28);
            load_battle_sprite_tile(gUnk_080AC588, 3, 0x30, 0x30);
            load_or_clear_battle_sprites(2, gUnk_030057A0.unk24, 16, 0x50, 0x30);
            load_battle_sprite_tile(gUnk_080AC58C, 3, 0x30, 0x38);
            load_or_clear_battle_sprites(3, gUnk_030057A0.unk1E, 16, 0x50, 0x38);
            break;
        case 1: {
            const u32 *const *bank = gTextBankTables[gUnk_030057A0.unk2E];
            if (scene_transition_step_08047C24(0, 0, 0, bank[gUnk_030057A0.unk30]))
                gUnk_030057A0.unk32 = 0;
        } break;
        }
        break;
    case 7:
        load_battle_sprite_tile(gUnk_080AC514, 2, 0x68, 0x18);
        load_battle_sprite_tile(gUnk_080AC590, 2, 0x30, 0x20);
        load_or_clear_battle_sprites(0, gUnk_030057E0.unkCBC, 8, 0x50, 0x20);
        load_battle_sprite_tile(gUnk_080AC594, 2, 0x30, 0x28);
        load_or_clear_battle_sprites(1, gUnk_030057E0.unkCBD, 8, 0x50, 0x28);
        load_battle_sprite_tile(gUnk_080AC598, 3, 0x30, 0x30);
        load_or_clear_battle_sprites(2, gUnk_030057A0.unk33, 8, 0x50, 0x30);
        load_battle_sprite_tile(gUnk_080AC59C, 2, 0x30, 0x38);
        load_or_clear_battle_sprites(3, gUnk_030057A0.unk34, 8, 0x50, 0x38);
        load_battle_sprite_tile(gUnk_080AC5A0, 3, 0x30, 0x40);
        load_or_clear_battle_sprites(4, gUnk_030057E0.unkC5D, 8, 0x50, 0x40);
        load_battle_sprite_tile(gUnk_080AC510, 1, 0x70, 0x40);
        break;
    }
}

void load_or_clear_battle_sprites(s8 key, s32 value, u8 width, u8 x, u8 y) {
    struct Unk_030057A0 *s = &gUnk_030057A0;

    if (key != s->unk16[s->unk14]) {
        load_battle_sprite_from_index(value, width, x, y);
    } else if (s->unk15 & 0x10) {
        s32 i;
        for (i = 0; i < width >> 3; i++) {
            clear_battle_sprite_entry(s->unk13);
            s->unk13++;
            clear_battle_sprite_entry(s->unk13);
            s->unk13++;
        }
    } else {
        load_battle_sprite_from_index(value, width, x, y);
    }
}

u32 sub_0805937C(void) {
    switch (gUnk_030057A0.unk14) {
    case 0:
    case 1:
    case 2:
    case 4:
        return 1;
    case 3:
        if (battle_sequence_dispatch() == 4) {
            gUnk_030057E0.unkC5C = 0;
            if (gUnk_030057A0.unk12 == 0xE || gUnk_030057A0.unk12 == 0x12) {
                decompress_battle_tile_graphics();
                DmaCopy32(3, gUnk_083F8634[gUnk_083D29A6[gUnk_030057E0.unkC5C]], (void *)PLTT + 0x200, 0x20);
                gUnk_030057E0.unkC28 = gUnk_030057E0.unkC5C;
                load_battle_terrain_data();
            }
            init_battle_sprites();
            return 1;
        }
        return 0;
    }
}

void clear_all_battle_sprites(void) {
    s32 i;

    for (i = 0; i < 40; i++)
        clear_battle_sprite_entry(i);
}

void handle_battle_end_state_transition(void) {
    if (gUnk_030057A0.unk11 == 0) {
        gUnk_030057A0.unk10 = 0;
        clear_all_battle_sprites();
    }
    gUnk_030057A0.unk15 = 0;
    switch (gUnk_030057A0.unk14) {
    case 0:
    case 2:
        gUnk_03005310.unk1 = 0;
        gGameSubState = 0x33;
        break;
    case 1:
        gUnk_03005310.unk1 = 0;
        gGameSubState = 0x33;
        break;
    default:
        gGameSubState = 5;
        break;
    }
}

// Dead code (nothing calls it): draws *value as three decimal digit sprites at (x, y), like
// load_battle_sprite_tile with the ASCII digits '0' + d.
void sub_08059490(u8 *value, s32 x, s32 y) {
    u8 hundreds, tens, ones;

    hundreds = *value / 100;
    tens = (*value - hundreds * 100) / 10;
    ones = *value - hundreds * 100 - tens * 10;

    DmaSet(3, &gUnk_080ACB7C[(hundreds + '0') * 32], 0x06017A00 + gUnk_030057A0.unk13 * 32, 0x84000008);
    init_battle_sprite_entry_08048818(gUnk_030057A0.unk13, 0xC004, gUnk_030057A0.unk13 + 0x99, 14, 1);
    gUnk_03002C30[gUnk_030057A0.unk13].unk2 = x;
    gUnk_03002C30[gUnk_030057A0.unk13].unk4 = y;
    gUnk_030057A0.unk13++;

    DmaSet(3, &gUnk_080ACB7C[(tens + '0') * 32], 0x06017A00 + gUnk_030057A0.unk13 * 32, 0x84000008);
    init_battle_sprite_entry_08048818(gUnk_030057A0.unk13, 0xC004, gUnk_030057A0.unk13 + 0x99, 14, 1);
    gUnk_03002C30[gUnk_030057A0.unk13].unk2 = x + 8;
    gUnk_03002C30[gUnk_030057A0.unk13].unk4 = y;
    gUnk_030057A0.unk13++;

    DmaSet(3, &gUnk_080ACB7C[(ones + '0') * 32], 0x06017A00 + gUnk_030057A0.unk13 * 32, 0x84000008);
    init_battle_sprite_entry_08048818(gUnk_030057A0.unk13, 0xC004, gUnk_030057A0.unk13 + 0x99, 14, 1);
    gUnk_03002C30[gUnk_030057A0.unk13].unk2 = x + 16;
    gUnk_03002C30[gUnk_030057A0.unk13].unk4 = y;
    gUnk_030057A0.unk13++;
}

void load_battle_sprite_from_index(u32 value, s32 bits, s32 x, s32 y) {
    u8 hex[16];
    s32 i;
    u8 b;
    u8 hi, lo;

    memcpy_optimized(hex, gUnk_080AC5A4, 16);
    for (i = 0; i < bits / 8; i++) {
        if (bits / 8 == 4) {
            if (i == 0)
                b = value >> 24;
            if (i == 1)
                b = (value & 0xFF0000) >> 16;
            if (i == 2)
                b = (value & 0xFF00) >> 8;
            if (i == 3)
                b = value;
        } else if (bits / 8 == 2) {
            if (i == 0)
                b = (value & 0xFF00) >> 8;
            if (i == 1)
                b = value;
        } else if (bits / 8 == 1) {
            if (i == 0)
                b = value;
        }
        hi = b >> 4;
        lo = b - hi * 16;

        DmaSet(3, &gUnk_080ACB7C[hex[hi] * 32], 0x06017A00 + gUnk_030057A0.unk13 * 32, 0x84000008);
        init_battle_sprite_entry_08048818(gUnk_030057A0.unk13, 0xC004, gUnk_030057A0.unk13 + 0x99, 14, 1);
        gUnk_03002C30[gUnk_030057A0.unk13].unk2 = x + i * 16;
        gUnk_03002C30[gUnk_030057A0.unk13].unk4 = y;
        gUnk_030057A0.unk13++;

        DmaSet(3, &gUnk_080ACB7C[hex[lo] * 32], 0x06017A00 + gUnk_030057A0.unk13 * 32, 0x84000008);
        init_battle_sprite_entry_08048818(gUnk_030057A0.unk13, 0xC004, gUnk_030057A0.unk13 + 0x99, 14, 1);
        gUnk_03002C30[gUnk_030057A0.unk13].unk2 = x + i * 16 + 8;
        gUnk_03002C30[gUnk_030057A0.unk13].unk4 = y;
        gUnk_030057A0.unk13++;
    }
}

void load_battle_sprite_tile(const u8 *digits, s32 count, s32 x, s32 y) {
    s32 i;

    for (i = 0; i < count; i++) {
        DmaSet(3, &gUnk_080ACB7C[*digits * 32], 0x06017A00 + gUnk_030057A0.unk13 * 32, 0x84000008);
        init_battle_sprite_entry_08048818(gUnk_030057A0.unk13, 0xC004, gUnk_030057A0.unk13 + 0x99, 14, 1);
        gUnk_03002C30[gUnk_030057A0.unk13].unk2 = x;
        gUnk_03002C30[gUnk_030057A0.unk13].unk4 = y;
        x += 8;
        gUnk_030057A0.unk13++;
        digits++;
    }
}

// battle field 4x2 grid: sprites 49-56 with shadows 91-98, then sprite 57 / shadow 99
static inline void init_field_sprite(u8 row, u8 col) {
    u8 slot = 49 + row * 4 + col;
    u8 j = slot + 42;

    gUnk_03002C30[slot].unk30 = gUnk_030057A0.unk20;
    gUnk_03002C30[slot].unkC_8 = gUnk_03006432 + (col * 32 - 48);
    gUnk_03002C30[slot].unk10_8 = gUnk_03006434 + (16 - row * 32);
    gUnk_03002C30[slot].unk0 = 0xC804;
    gUnk_03002C30[slot].unk2E = 1;
    gUnk_03002C30[j].unk0 = 0xCC0C;
    gUnk_03002C30[slot].unk2 = gUnk_03002C30[slot].unkC_8 - (u16)gBg1Scroll.x;
    gUnk_03002C30[slot].unk4 = gUnk_03002C30[slot].unk10_8 - (u16)gBg1Scroll.y;
    gUnk_03002C30[j].unk2 = gUnk_03002C30[slot].unk2;
    gUnk_03002C30[j].unk4 = gUnk_03002C30[slot].unk4 + (s16)(gUnk_03002C30[slot].unk2C - 5);
    gUnk_03002C30[slot].unk6 = row * 48 + col * 15;
    sub_080493D4(slot, 4 + row * 16 + col * 5);
}

void init_battle_field_sprites(void) {
    s16 zero; // FAKEMATCH: only set inside the first if, read after it (uninitialised on the other path)

    decompress_terrain_tiles_to_vram(gUnk_030057A0.unk20);
    dma_load_obj_palettes_08048730(gUnk_030057A0.unk20);
    init_field_sprite(0, 0);
    init_field_sprite(0, 1);
    init_field_sprite(0, 2);
    init_field_sprite(0, 3);
    init_field_sprite(1, 0);
    init_field_sprite(1, 1);
    init_field_sprite(1, 2);
    init_field_sprite(1, 3);
    {
        u8 slot = 57;
        u8 j = slot + 42;

        clear_battle_sprite_entry(slot);
        clear_battle_sprite_entry(j);
        gUnk_03002C30[slot].unk30 = gUnk_030057A0.unk20;
        if (gUnk_083D2C3D[gUnk_030057A0.unk20] == 3) {
            init_battle_sprite_entry_08048818(slot, 0xC804, calc_medapart_table_index(0), sub_08050264(0), 1);
            gUnk_03002C30[slot].unk2B = sub_08050264(0);
            gUnk_03002C30[slot].unkC_8 = gUnk_03006432 - 0x30;
            gUnk_03002C30[slot].unk10_8 = gUnk_03006434 + 0x30;
            gUnk_030055A0[slot].unk0 = 0xFFFF;
            gUnk_03002C30[slot].unk2C = zero = 0;
            sub_080493D4(slot, 0x60);
        }
        gUnk_03002C30[j].unk0 = zero;
        if (gUnk_083D2B8D[gUnk_030057A0.unk20] != 0) {
            gUnk_03002C30[j].unk0 = 0xCC0C;
            gUnk_03002C30[j].unk2 = gUnk_03002C30[slot].unk2;
            gUnk_03002C30[j].unk4 = gUnk_03002C30[slot].unk4 + (s16)(gUnk_03002C30[slot].unk2C - 5);
        }
    }
}

void sub_08059D04(void) {
    s32 i;

    for (i = 0; i < 128; i++)
        gUnk_03002C30[i].unk0 = 0;
}

void clear_vram_bg2_tilemap(void) {
    u32 zero = 0;
    vu16 *bg2;
    u16 v;

    CpuFastSet(&zero, (void *)0x06008000, 0x01001000);
    lz_decompress_dispatch(gUnk_08784CB0, (void *)0x06008020);
    CpuFastSet(gUnk_08483AA0, (void *)0x05000020, 8);
    bg2 = &REG_BG2CNT;
    v = 0x1608;
    *bg2 = v;
    REG_DISPCNT |= 0x400;
}

void clear_vram_bg1_tilemap(void) {
    u32 zero = 0;
    vu16 *bg1;
    u16 v;

    CpuFastSet(&zero, (void *)0x06004000, 0x01001000);
    lz_decompress_dispatch(gUnk_08784CB0, (void *)0x06004020);
    bg1 = &REG_BG1CNT;
    v = 0x1E04;
    *bg1 = v;
    REG_DISPCNT |= 0x200;
}

void clear_vram_bg2_screenblock(void) {
    u32 zero = 0;
    vu16 *bg2;
    u16 v;

    CpuFastSet(&zero, (void *)0x06008400, 0x01000F00);
    bg2 = &REG_BG2CNT;
    v = 0x1608;
    *bg2 = v;
    REG_DISPCNT |= 0x400;
}

// Decimal number on BG screen block bg: width > 0 right-aligned blank-padded, < 0 zero-padded in -width
// places, 0 left-aligned.
void draw_number(u16 value, s32 width, u8 x, u8 y, u8 pal, u8 bg) {
    u16 buf[6];
    u16 base = gUnk_03006F74->unk36 + 0x16;
    s8 w = width;
    vu16 *p;
    s32 i;

    if (w != 0) {
        if (w > 0) {
            p = (vu16 *)(VRAM + (bg << 11)) + (x + w - 1) + y * 32;
            for (i = 0; i < w; i++) {
                if (i != 0 && value == 0)
                    *p-- = pal << 12;
                else {
                    *p-- = (value % 10 + base) | (pal << 12);
                    value /= 10;
                }
            }
        } else {
            s8 n = -w;
            p = (vu16 *)(VRAM + (bg << 11)) + (x + n - 1) + y * 32;
            for (i = 0; i < n; i++) {
                if (i != 0 && value == 0)
                    *p-- = base | (pal << 12);
                else {
                    *p-- = (value % 10 + base) | (pal << 12);
                    value /= 10;
                }
            }
        }
    } else {
        p = (vu16 *)(VRAM + (bg << 11)) + x + y * 32;
        for (i = 0; i <= 4; i++) {
            buf[i] = value % 10;
            if (value == 0 && i != 0)
                break;
            value /= 10;
        }
        for (i--; i >= 0; i--)
            *p++ = (buf[i] + base) | (pal << 12);
    }
}

// draw_number with 2-tile-tall digits (rows y and y + 1).
void draw_number_tall(u16 value, s8 w, u8 x, u8 y, u8 pal, u8 bg) {
    u16 buf[6];
    u16 saved = value;
    u16 base = gUnk_03006F74->unk36 + 1;
    vu16 *p;
    s32 i;

    if (w != 0) {
        if (w > 0) {
            p = (vu16 *)(VRAM + (bg << 11)) + (x + w - 1) + y * 32;
            for (i = 0; i < w; i++) {
                if (i != 0 && value == 0)
                    *p-- = pal << 12;
                else {
                    *p-- = (value % 10 + base) | (pal << 12);
                    value /= 10;
                }
            }
            value = saved;
            base += 10;
            p = (vu16 *)(VRAM + (bg << 11)) + (x + w - 1) + (y + 1) * 32;
            for (i = 0; i < w; i++) {
                if (i != 0 && value == 0)
                    *p-- = pal << 12;
                else {
                    *p-- = (value % 10 + base) | (pal << 12);
                    value /= 10;
                }
            }
        } else {
            w = -w;
            p = (vu16 *)(VRAM + (bg << 11)) + (x + w - 1) + y * 32;
            for (i = 0; i < w; i++) {
                if (i != 0 && value == 0)
                    *p-- = base | (pal << 12);
                else {
                    *p-- = (value % 10 + base) | (pal << 12);
                    value /= 10;
                }
            }
            value = saved;
            base += 10;
            p = (vu16 *)(VRAM + (bg << 11)) + (x + w - 1) + (y + 1) * 32;
            for (i = 0; i < w; i++) {
                if (i != 0 && value == 0)
                    *p-- = base | (pal << 12);
                else {
                    *p-- = (value % 10 + base) | (pal << 12);
                    value /= 10;
                }
            }
        }
    } else {
        p = (vu16 *)(VRAM + (bg << 11)) + x + y * 32;
        for (i = 0; i <= 4; i++) {
            if ((buf[i] = value % 10) == 0 && i != 0)
                break;
            value /= 10;
        }
        for (i--; i >= 0; i--)
            *p++ = (buf[i] + base) | (pal << 12);
        p = (vu16 *)(VRAM + (bg << 11)) + x + (y + 1) * 32;
        value = saved;
        for (i = 0; i <= 4; i++) {
            if ((buf[i] = value % 10) == 0 && i != 0)
                break;
            value /= 10;
        }
        for (i--; i >= 0; i--)
            *p++ = (buf[i] + base) | (pal << 12);
    }
}

// Runtime: item list page numbers (item_menu_draw_page_numbers).
void draw_number_3digits(s32 n, s32 x, s32 y) {
    s32 pal = 13;
    u16 base = gUnk_03006F74->unk36 + 0x16;
    vu16 *p = (vu16 *)(VRAM + 0xF000);

    p = p + x + y * 32;
    if (n / 100 % 10)
        *p = (base + n / 100 % 10) | (pal << 12);
    else
        *p = 0;
    *p++;
    if (n / 100 % 10 || n / 10 % 10)
        *p = (base + n / 10 % 10) | (pal << 12);
    else
        *p = 0;
    *p++;
    *p = (base + n % 10) | (pal << 12);
}

// n % 100 as 2-tile-tall digits. Runtime: item quantities (update_battle_medapart_icons).
void draw_number_2digits_tall(s32 n, s32 x, s32 y) {
    s16 base;
    s32 pal = 12;
    vu16 *p;
    s32 sbb = 30;

    n %= 100;
    base = gUnk_03006F74->unk36;
    p = (vu16 *)(VRAM + (sbb << 11)) + x + y * 32;
    if (n / 100 % 10 || n / 10 % 10)
        *p = (n / 10 % 10 + (base + 1)) | (pal << 12);
    else
        *p = 0;
    *p++;
    *p = (n % 10 + (base + 1)) | (pal << 12);
    p = (vu16 *)(VRAM + (sbb << 11)) + x + (y + 1) * 32;
    if (n / 100 % 10 || n / 10 % 10)
        *p = (n / 10 % 10 + (base + 0xB)) | (pal << 12);
    else
        *p = 0;
    *p++;
    *p = (n % 10 + (base + 0xB)) | (pal << 12);
}

// 5 digits on BG screen block 22, leading zeros blanked.
void draw_number_5digits(u16 value, u8 x, u8 y) {
    vu16 *p;
    u32 sbb = 22;
    u32 pal = 1;
    u16 base = 0x16;
    u16 d;

    p = (vu16 *)(VRAM + sbb * 0x800 + x * 2 + y * 64);
    d = value / 10000;
    if (d != 0)
        *p = (d + base) | (pal << 12);
    else
        *p = 0;
    *p++;

    d = (u16)(value / 1000) % 10;
    if (d != 0 || (u16)(value / 10000) != 0)
        *p = (d + base) | (pal << 12);
    else
        *p = 0;
    *p++;

    d = (u16)(value / 100) % 10;
    if (d != 0 || (u16)(value / 10000) != 0 || (u16)((u16)(value / 1000) % 10) != 0)
        *p = (d + base) | (pal << 12);
    else
        *p = 0;
    *p++;

    d = (u16)(value / 10) % 10;
    if (d != 0 || (u16)(value / 10000) != 0 || (u16)((u16)(value / 1000) % 10) != 0 ||
        (u16)((u16)(value / 100) % 10) != 0)
        *p = (d + base) | (pal << 12);
    else
        *p = 0;
    *p++;

    *p = (value % 10 + base) | (pal << 12);
}

// Unused.
void draw_number_5digits_tall(u16 value, u8 x, u8 y) {
    vu16 *p;
    u32 pal = 1;
    u16 base = 1;
    u32 sbb = 22;
    u16 d;

    p = (vu16 *)(VRAM + sbb * 0x800 + x * 2 + y * 64);
    d = value / 10000;
    if (d != 0)
        *p++ = (d + base) | (pal << 12);
    else
        *p++;

    d = (u16)(value / 1000) % 10;
    if (d != 0 || (u16)(value / 10000) != 0)
        *p++ = (d + base) | (pal << 12);
    else
        *p++;

    d = (u16)(value / 100) % 10;
    if (d != 0 || (u16)(value / 10000) != 0 || (u16)((u16)(value / 1000) % 10) != 0)
        *p++ = (d + base) | (pal << 12);
    else
        *p++;

    d = (u16)(value / 10) % 10;
    if (d != 0 || (u16)(value / 10000) != 0 || (u16)((u16)(value / 1000) % 10) != 0 ||
        (u16)((u16)(value / 100) % 10) != 0)
        *p++ = (d + base) | (pal << 12);
    else
        *p++;

    *p = (value % 10 + base) | (pal << 12);

    p = (vu16 *)(VRAM + sbb * 0x800 + x * 2 + (y + 1) * 64);
    base = 0xB;
    d = value / 10000;
    if (d != 0)
        *p++ = (d + base) | (pal << 12);
    else
        *p++;

    d = (u16)(value / 1000) % 10;
    if (d != 0 || (u16)(value / 10000) != 0)
        *p++ = (d + base) | (pal << 12);
    else
        *p++;

    d = (u16)(value / 100) % 10;
    if (d != 0 || (u16)(value / 10000) != 0 || (u16)((u16)(value / 1000) % 10) != 0)
        *p++ = (d + base) | (pal << 12);
    else
        *p++;

    d = (u16)(value / 10) % 10;
    if (d != 0 || (u16)(value / 10000) != 0 || (u16)((u16)(value / 1000) % 10) != 0 ||
        (u16)((u16)(value / 100) % 10) != 0)
        *p++ = (d + base) | (pal << 12);
    else
        *p++;

    *p = (value % 10 + base) | (pal << 12);
}

// Unused; the tens-of-thousands digit misses its % 10 in the original.
void draw_number_7digits(u32 value, u32 x, u32 y) {
    vu16 *p;
    u32 sbb = 22;
    u32 pal = 1;
    u16 base = 0x16;
    u16 d;

    p = (vu16 *)(VRAM + sbb * 0x800 + x * 2 + y * 64);
    d = value / 1000000;
    if (d != 0)
        *p++ = (d + base) | (pal << 12);
    else
        *p++;

    d = value / 100000 % 10;
    if (d != 0 || value / 1000000 != 0)
        *p++ = (d + base) | (pal << 12);
    else
        *p++;

    d = value / 10000 % 10;
    if (d != 0 || value / 1000000 != 0 || value / 100000 % 10 != 0)
        *p++ = (d + base) | (pal << 12);
    else
        *p++;

    d = value / 1000 % 10;
    if (d != 0 || value / 1000000 != 0 || value / 100000 % 10 != 0 || value / 10000 % 10 != 0)
        *p++ = (d + base) | (pal << 12);
    else
        *p++;

    d = value / 100 % 10;
    if (d != 0 || value / 1000000 != 0 || value / 100000 % 10 != 0 || value / 10000 % 10 != 0 || value / 1000 % 10 != 0)
        *p++ = (d + base) | (pal << 12);
    else
        *p++;

    d = value / 10 % 10;
    if (d != 0 || value / 1000000 != 0 || value / 100000 % 10 != 0 || value / 10000 != 0 || value / 1000 % 10 != 0 ||
        value / 100 % 10 != 0)
        *p++ = (d + base) | (pal << 12);
    else
        *p++;

    *p = (value % 10 + base) | (pal << 12);
}

void sub_0805AA80(u8 *src, u16 row, u16 x, u16 y, u8 len) {
    u32 v;
    vu16 *p;
    u32 sbb = 22;
    u16 i;

    v &= 0xFFFF0000;
    p = (vu16 *)(VRAM + sbb * 0x800 + x * 2 + y * 64);
    ((struct BgTileEntry *)&v)->pal = 1;
    for (i = 0; i < len; i++) {
        ((struct BgTileEntry *)&v)->tile = (src + i)[row * len] + 0x9F;
        *p++ = *(u16 *)&v;
    }
}

void copy_palettes_to_backup(void) {
    CpuFastSet((void *)(PLTT + 0x200), gPaletteBackup, 0x80);
    CpuFastSet((void *)PLTT, gPaletteBackupBg, 0x80);
}
