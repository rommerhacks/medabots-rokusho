// Mode-2 state 10: the Town Map. town_map_dispatch runs gUnk_08483DA0 (graphics, then cursor states that
// call town_map_update_cursor / update_animation_timer, the two helpers at the top of the file).
#include "global.h"

void town_map_update_cursor(void) {
    u8 row = gUnk_03006F74->unk18;
    const u8 *t;

    if (++gUnk_03002C30[0].unk1A > 0x60)
        gUnk_03002C30[0].unk1A = 0;
    t = (const u8 *)gUnk_08483DC0;
    gUnk_03002C30[0].unk2 = t[gUnk_03006F74->unk17 * 2] * 8 + gUnk_08483DD4[row][(gUnk_03002C30[0].unk1A >> 3) & 3];
    gUnk_03002C30[0].unk4 =
        t[(u16)(gUnk_03006F74->unk17 * 2 + 1)] * 8 + gUnk_08483DE4[row][(gUnk_03002C30[0].unk1A >> 3) & 3];
    gUnk_03002C30[0].unk6 = gUnk_08483DF4[row][(gUnk_03002C30[0].unk1A >> 3) & 3];
}

void update_animation_timer(void) {
    s32 t;

    if ((u16)++gUnk_03006F74->unk3A > 0x6D)
        gUnk_03006F74->unk3A = 0;
    t = gUnk_03006F74->unk3A;
    if ((s16)(t % 10) == 0)
        CpuSet(gDecompressBuffer + (gUnk_08483E04[(s16)(t / 10)] + 1) * 480, (void *)0x06004020, 0xF0);
}

void town_map_dispatch(void) {
    gUnk_08483DA0[gGameSubState]();
}

void copy_bg2_tilemap_to_ewram(void) {
    u32 zero;

    CpuFastSet((void *)0x06002800, (void *)0x02020800, 0x28);
    zero = 0;
    CpuFastSet(&zero, (void *)0x06002800, 0x01000200);
    reset_bg_scroll();
    free_all_sprites();
    REG_DISPCNT = 0x60;
    REG_BLDCNT = 0x2FF;
    REG_BLDY = 0x10;
    gGameSubState++;
}

void town_map_load_graphics(void) {
    u32 size;
    u32 off;
    register u32 cb asm("r5");
    u8 i;
    vu16 tmp;
    vu16 *bg1, *bg2, *bg3;
    u16 v;
    struct Unk_03006F74 *p;

    cb = 1;
    bg1 = &REG_BG1CNT;
    v = 0x1E05;
    *bg1 = v;
    bg2 = &REG_BG2CNT;
    v -= 0xFF;
    *bg2 = v;
    bg3 = &REG_BG3CNT;
    v -= 0xFF;
    *bg3 = v;
    decompress_and_write_tilemap(gUnk_0878A844, *bg1);
    decompress_and_write_tilemap(gUnk_0878A918, *bg2);
    decompress_and_write_tilemap(gUnk_0878AA0C, *bg3);
    {
        struct Unk_03006F74 *q;
        if (gGameState == 0x17) {
            q = gUnk_03006F74;
            q->unk18 = 1;
        } else {
            *(u16 *)(((*bg3 >> 8) & 0x1F) * 0x800 + (VRAM + 0x248)) =
                *(u16 *)(((*bg3 >> 8) & 0x1F) * 0x800 + (VRAM + 0x21E));
            q = gUnk_03006F74;
            q->unk18 = 0;
        }
    }
    switch (gUnk_030057E0.unkC32) {
    case 0:
        for (i = 0; i <= 2; i++) {
            tmp = 0;
            CpuSet((void *)&tmp, (u16 *)(VRAM + ((REG_BG2CNT >> 8) & 0x1F) * 0x800) + 13 + (i + 10) * 32, 0x01000005);
        }
    case 1:
        for (i = 0; i <= 2; i++) {
            tmp = 0;
            CpuSet((void *)&tmp, (u16 *)(VRAM + ((REG_BG2CNT >> 8) & 0x1F) * 0x800) + 8 + (i + 4) * 32, 0x01000005);
        }
        break;
    }
    off = cb << 14;
    size = dma3_copy_or_decompress(gUnk_087877C4, gDecompressBuffer);
    CpuFastSet(gDecompressBuffer, (void *)(VRAM + off), (size / 4) & 0x1FFFFF);
    lz_decompress_dispatch(gUnk_08784CB0, (void *)(VRAM + off + size));
    gUnk_03006F74->unk36 = size / 32 - 1;
    CpuFastSet(gUnk_087871E4, (void *)PLTT, 0x70);
    lz_decompress_dispatch(gUnk_08785F34, (void *)0x06010000);
    CpuFastSet(gUnk_080AF9A8, (void *)(PLTT + 0x200), 0x18);
    gUnk_03006F74->unk17 = gUnk_08483CE0[gUnk_030057E0.unk7FE];
    gUnk_03002C30[0].unk0 = 0xC000;
    gUnk_03002C30[0].unk1C = 2;
    gUnk_03002C30[0].unk4 = 0x3C;
    p = gUnk_03006F74;
    gUnk_03002C30[0].unkA = p->unk18;
    gUnk_03002C30[0].unk6 = 0x10D;
    gUnk_03002C30[0].unk1A = 0;
    gUnk_03002C30[1].unk0 = 0xC000;
    gUnk_03002C30[1].unk1C = 2;
    gUnk_03002C30[1].unk2 = gUnk_08483DC0[0][p->unk17 * 2] * 8;
    gUnk_03002C30[1].unk4 = gUnk_08483DC0[0][p->unk17 * 2 + 1] * 8;
    gUnk_03002C30[1].unkA = 2;
    gUnk_03002C30[1].unk6 = 0x10E;
    gUnk_03002C30[0].unk2 = gUnk_08483DC0[0][p->unk17 * 2] * 8;
    gUnk_03002C30[0].unk4 = gUnk_08483DC0[0][p->unk17 * 2 + 1] * 8;
    dma3_copy_or_decompress(gUnk_087873A4, (void *)0x020301E0);
    gGameSubState++;
}

void sub_08060804(void) {
    REG_DISPCNT |= 0x200;
    REG_DISPCNT |= 0x400;
    REG_DISPCNT |= 0x800;
    REG_DISPCNT |= 0x1000;
    gUnk_03006F74->unk0 = 8;
    REG_BLDY = gUnk_03006F74->unk0 * 2;
    gUnk_03006F74->unk3A = 0;
    gGameSubState++;
}

void sub_0806086C(void) {
    struct Unk_03006F74 *p = gUnk_03006F74;

    if (p->unk0 != 0) {
        REG_BLDY = --p->unk0 * 2;
    } else {
        p->unk2 = 0;
        text_window_init(1, 2, 0);
        gGameSubState++;
    }
    town_map_update_cursor();
    update_animation_timer();
}

void sub_080608B4(void) {
    u8 i = gUnk_03006F74->unk17;
    if (run_message(gUnk_08485504[i]))
        gGameSubState++;
    town_map_update_cursor();
    update_animation_timer();
}

void sub_080608EC(void) {
    u8 keys;

    town_map_update_cursor();
    update_animation_timer();
    if (sub_0805B7A0() == 0) {
        if (!((keys = KEYS_LO(gNewKeys)) & 3))
            return;
        if (gGameState == 10) {
            play_sound_effect(5);
            gUnk_03006F74->unk48 = 1;
        } else if (keys & 1) {
            play_sound_effect(4);
            gUnk_03006F74->unk48 = 1;
        } else {
            play_sound_effect(5);
            gUnk_03006F74->unk48 = 0;
        }
        gUnk_03006F74->unk0 = 0;
        gGameSubState++;
    } else {
        sub_0803FB0C();
        gGameSubState = 4;
    }
}

void sub_0806098C(void) {
    town_map_update_cursor();
    update_animation_timer();
    if (game_state_execute_handler_a()) {
        copy_obj_palette_to_buffer();
        gUnk_03000440.unk84 = 0;
        gGameSubState++;
    }
}

void sub_080609C0(void) {
    struct Unk_03000440 *s;
    u8 *n;

    town_map_update_cursor();
    update_animation_timer();
    s = &gUnk_03000440;
    n = &s->unk84;
    if (*n <= 8) {
        blend_obj_palettes_to_color_0803F684(0, *n * 4, 0xFFFF);
        blend_obj_palettes_to_color_0803F998(0, *n * 4, 0xFFFF);
        (*n)++;
    } else {
        REG_DISPCNT &= 0xFDFF;
        REG_DISPCNT &= 0xFEFF;
        CpuFastSet((void *)0x02020800, (void *)0x06002800, 0x28);
        if (gGameState == 10) {
            gGameState = 4;
            gGameSubState = 0;
        } else if (gUnk_03006F74->unk48) {
            gUnk_03006D38.unk5 = gUnk_03006F74->unk17;
            dispatch_by_index_0476e8(5);
        } else {
            dispatch_by_index_0476e8(6);
        }
    }
}
