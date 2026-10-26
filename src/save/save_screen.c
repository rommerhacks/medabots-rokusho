// Mode-2 state 5: the save screen (save_screen_update runs its gUnk_08483B78 sub-states: graphics, the info
// panel, the save prompt, attempt_save_and_transition writes through save/save_data.c, then back to the
// field or the title). init_linking_mode (end of the file) switches to mode 3 for the link scenes.
#include "global.h"

static inline void *vram_at(u32 off) {
    return (void *)(0x06004000 + off);
}

void sub_0805D50C(void) {
    struct Unk_03000440 *b = &gUnk_03000440;
    if (b->unk84 <= 8) {
        blend_obj_palettes_to_color_0803F684(0, b->unk84 * 4, 0xFFFF);
        blend_obj_palettes_to_color_0803F998(0, b->unk84 * 4, 0xFFFF);
        b->unk84++;
    } else {
        u32 zero;
        REG_DISPCNT &= 0xFDFF;
        zero = 0;
        CpuFastSet(&zero, (void *)VRAM, 0x01006000);
        dispatch_by_index_0476e8(4);
    }
}

void sub_0805D57C(u16 a) {
    gUnk_03002C30[0].unk6 = gUnk_080AF7E0[a & 3];
}

void save_screen_update(void) {
    gSaveScreenStates[gGameSubState]();
    if (gFrameCounter & 1) {
        gBg3Scroll.x++;
        gBg3Scroll.y++;
    }
    sub_0805D57C(gFrameCounter >> 3);
}

void sub_0805D5E8(void) {
    u32 zero = 0;
    CpuFastSet(&zero, gUnk_03006F74, 0x01000100);
    reset_bg_scroll();
    REG_DISPCNT = 0x160;
    gGameSubState++;
}

void sub_0805D628(void) {
    u32 size;
    u16 v;
    vu16 *bg1, *bg2, *bg3;

    bg1 = &REG_BG1CNT;
    v = 0x1E05;
    *bg1 = v;
    bg2 = &REG_BG2CNT;
    v -= 0xFF;
    *bg2 = v;
    bg3 = &REG_BG3CNT;
    v = 0x3C07;
    *bg3 = v;
    decompress_and_write_tilemap(gUnk_0878DE10, *bg1);
    decompress_and_write_tilemap(gUnk_0878DFE0, *bg2);
    decompress_and_write_tilemap(gUnk_0878E104, *bg3);
    size = dma3_copy_or_decompress(gUnk_0878CC64, gDecompressBuffer);
    CpuCopy16(gDecompressBuffer, vram_at(0), size);
    lz_decompress_dispatch(gUnk_08784CB0, vram_at(size));
    gUnk_03006F74->unk36 = (size >> 5) - 1;
    lz_decompress_dispatch(gUnk_08784DA4, (void *)0x06010000);
    gUnk_03002C30[0].unk0 = 0xC000;
    gUnk_03002C30[0].unk1C = 2;
    gUnk_03002C30[0].unkA = 0;
    gUnk_03002C30[0].unk6 = 0x23;
    gUnk_03002C30[0].unk2 = 0xD0;
    gUnk_03002C30[0].unk4 = 0x18;
    gGameSubState++;
}

// guess: save screen info panel (Medal / Medapart counts, play time, Robattle counters, money, name).
// draw_number is called through a cast: this caller passes untruncated ints, the header has u8 / u16 params.
void sub_0805D6F8(void) {
    s32 n;
    s32 i;

    n = 0;
    for (i = 0; i < 30; i++) {
        if (gUnk_03000BE0[i].unk0 & 0x80)
            n++;
    }
    ((void (*)(s32, s32, s32, s32, s32, s32))draw_number)(n, 2, 10, 4, 10, (REG_BG1CNT >> 8) & 0x1F);
    n = 0;
    for (i = 0; i < 480; i++) {
        if (gMedapartInventory[i * 2] != 0)
            n++;
    }
    ((void (*)(s32, s32, s32, s32, s32, s32))draw_number)(n, 3, 9, 6, 11, (REG_BG1CNT >> 8) & 0x1F);
    n = gUnk_03002B70.unk18 / 3600;
    ((void (*)(s32, s32, s32, s32, s32, s32))draw_number)(n / 60, 2, 7, 8, 12, (REG_BG1CNT >> 8) & 0x1F);
    ((void (*)(s32, s32, s32, s32, s32, s32))draw_number)(n % 60, -2, 10, 8, 12, (REG_BG1CNT >> 8) & 0x1F);
    ((void (*)(s32, s32, s32, s32, s32, s32))draw_number)(gUnk_03002B70.unk14[1], 4, 3, 11, 13,
                                                          (REG_BG1CNT >> 8) & 0x1F);
    ((void (*)(s32, s32, s32, s32, s32, s32))draw_number)(gUnk_03002B70.unk14[0], 0, 8, 11, 13,
                                                          (REG_BG1CNT >> 8) & 0x1F);
    divide_by_10000(gUnk_03000440.unk9E, gUnk_03002B70.money);
    render_text_sprites_08040DB8(gUnk_03000440.unk9E, 1, 15, 9, 7, 15, 1, 0);
    render_text_sprites_08040DB8(gUnk_03002B70.unk4, 13, 14, 4, 10, 13, 0, 0);
    open_choice_menu(1, 0x16, 7);
    CpuFastSet(gUnk_0878CA64, gPaletteBackupBg, 0x80);
    CpuFastSet(gUnk_0850DCF8, (void *)0x0202F9A0, 8);
    CpuFastSet(gUnk_084E2E38, (void *)0x0202F9E0, 8);
    CpuFastSet(gUnk_080AF7E8, gPaletteBackup, 8);
    gUnk_03000440.unk84 = 0;
    gGameSubState++;
}

void sub_0805D8AC(void) {
    if (gUnk_03000440.unk84 <= 8) {
        blend_obj_palettes_to_color_0803F684(0, 32 - gUnk_03000440.unk84 * 4, 0x3FFF);
        blend_obj_palettes_to_color_0803F998(0, 32 - gUnk_03000440.unk84 * 4, 0xFFFF);
        if (++gUnk_03000440.unk84 == 1) {
            REG_DISPCNT |= 0x200;
            REG_DISPCNT |= 0x400;
            REG_DISPCNT |= 0x800;
            REG_DISPCNT |= 0x1000;
        }
    } else {
        text_window_init(1, 2, 0);
        gGameSubState++;
    }
}

void sub_0805D948(void) {
    if (run_message(gUnk_08485788[9]))
        gGameSubState++;
}

void sub_0805D96C(void) {
    if (poll_choice_menu()) {
        sub_0803FB0C();
        if (gUnk_03000440.unk2A == 0)
            gGameSubState = (*(u8 *)&gUnk_03001784 & 1) ? 13 : 6;
        else
            gGameSubState = 9;
    }
}

void sub_0805D9B8(void) {
    if (run_message(gUnk_08485BD8[18])) {
        open_choice_menu(1, 0x16, 7);
        gGameSubState++;
    }
}

void sub_0805D9E4(void) {
    if (poll_choice_menu()) {
        sub_0803FB0C();
        if (gUnk_03000440.unk2A == 0)
            gGameSubState = 6;
        else
            gGameSubState = 9;
    }
}

void sub_0805DA1C(void) {
    if (run_message(gUnk_08485788[10])) {
        play_song(0);
        play_sound_effect(0);
        eeprom_setup_timer_irq();
        gUnk_03006F74->unk2 = 0;
        gGameSubState++;
    }
}

void attempt_save_and_transition(void) {
    u8 t = gUnk_03006F74->unk2++;
    u16 err = 0;
    s8 i;

    if (t > 29 && !is_sound_playing_with_lock(4)) {
        for (i = 0; i <= 3; i++) {
            err = save_dispatch(0);
            if (err == 0)
                break;
        }
        play_song(6);
        if (err == 0) {
            sub_0803FB0C();
            gUnk_03006F74->unk2 = err;
            gGameSubState++;
        } else {
            sub_0803FB0C();
            gUnk_03006F74->unk2 = 0;
            gGameSubState = 12;
        }
    }
}

void sub_0805DAE4(void) {
    u8 t = gUnk_03006F74->unk2++;
    if (run_message(gUnk_08485788[11]) && t > 60)
        gGameSubState++;
}

void sub_0805DB20(void) {
    sub_0803FB0C();
    copy_obj_palette_to_buffer();
    gUnk_03000440.unk84 = 0;
    gGameSubState++;
}

void sub_0805DB48(void) {
    if (game_state_execute_handler_a())
        gGameSubState++;
}

void sub_0805DB64(void) {
    if (gUnk_03000440.unk84 <= 8) {
        blend_obj_palettes_to_color_0803F684(0, gUnk_03000440.unk84 * 4, 0x3FFF);
        blend_obj_palettes_to_color_0803F998(0, gUnk_03000440.unk84 * 4, 0xFFFF);
        gUnk_03000440.unk84++;
    } else {
        REG_DISPCNT &= 0xFDFF;
        REG_DISPCNT &= 0xFBFF;
        clear_battle_sprite_slot(0, 0x80);
        gGameMode = 0;
        gGameState = 1;
        gGameSubState = 16;
    }
}

void sub_0805DBE8(void) {
    u8 t = gUnk_03006F74->unk2++;
    if (run_message(gUnk_08485788[12]) && t > 60)
        gGameSubState = 9;
}

void init_linking_mode(void) {
    gUnk_03005030 = 0;
    serial_multiplayer_init();
    VBlankIntrWait();
    REG_BLDCNT = 0xFF;
    REG_BLDY = 0x10;
    REG_SOUNDCNT_X = 0;
    gGameMode = 3;
    gGameState = 0;
    gGameSubState = 0;
    REG_DMA0CNT_H = 0;
    VBlankIntrWait();
    sound_init(&gUnk_03002430);
    VBlankIntrWait();
}
