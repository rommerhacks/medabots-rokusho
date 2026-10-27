// Boot and the main loop: AgbMain initialises the hardware, interrupts, sound and serial link, then runs one
// frame per VBlank: read_keys, the gGameMode handler (gUnk_083ABE18: 0 menus/battle via engine/game_state.c,
// 1 field, 2 title, 3 boot/intro/minigames), the OAM build (engine/oam.c) and the link packet. The VBlank /
// HBlank / sound DMA interrupt handlers and the soft reset (A+B+START+SELECT) live here too.

#include "global.h"

static u32 check_soft_reset(void);

void AgbMain(void) {
    s32 i;
    u8 prevConnected;

    REG_WAITCNT = 0x4014;
    hw_reset_init();
    irq_init();
    REG_DISPCNT = 0x60;
    gGameMode = 3;
    gGameState = 0;
    gGameSubState = 0;
    serial_link_init();
    sound_init(&gSoundWorkArea);
    *(u16 *)&gUnk_03001784 = 0;
    gUnk_03005030 = 0;
    gUnk_03002410 = 0;
    gUnk_03005010.unk1E = 0;
    gUnk_03005010.unk1D = 0;
    for (;;) {
        VBlankIntrWait();
        gUnk_03002410 = 0;
        read_keys();
        gFrameCounter++;
        if (gPlayTimeRunning && gPlayerRecord.playTime < 0x014996FF)
            gPlayerRecord.playTime++;
        prevConnected = gSioLink.connected;
        gUnk_03005010.unk1D = 0;
        gUnk_03005010.unk1E = 0;
        gUnk_03005010.unk0 = serial_link_init_and_status((u32 *)gUnk_03005010.unk8);
        for (i = 0; i < 4; i++) {
            if (gUnk_03005010.unk0 & (1 << i)) {
                gUnk_03005010.unk19[i] = 0;
                if (!((prevConnected >> i) & 1)) {
                    gSioLink.connected |= 1 << i;
                    gUnk_03005010.unk1D |= 0xFF;
                }
            } else if (gUnk_03005010.unk19[i] > 10) {
                if ((gSioLink.connected >> i) & 1)
                    gUnk_03005010.unk1E |= 0xFF;
                gSioLink.connected &= ~(1 << i);
                gUnk_03005010.unk19[i] = 0;
            } else {
                gUnk_03005010.unk19[i]++;
            }
        }
        if (check_soft_reset()) {
            VBlankIntrWait();
            sound_init(&gSoundWorkArea);
            VBlankIntrWait();
        } else if (gUnk_03005030) {
            u32 other = 0;

            if (gUnk_03000B90 == 0)
                other = 1;
            if (gUnk_03005010.unk8[other][0] == 0xFFFF &&
                gUnk_03005010.unk8[other][1] == gUnk_03005010.unk8[other][0]) {
                gGameMode = 0;
                gGameState = 10;
                gGameSubState = 16;
            }
        }
        gUnk_083ABE18[gGameMode]();
        check_flag_and_fast_copy();
        serial_prepare_send_packet(&gUnk_03005010.unk4);
    }
}

void irq_init(void) {
    CpuSet(gIntrTableTemplate, gIntrTable, 0x0400000E);
    CpuSet(irq_dispatch_arm, gIntrMain, 0x04000200);
    INTR_VECTOR = gIntrMain;
    gVBlankOnceCallback = empty_callback;
    gVBlankCallback = empty_callback;
    gHBlankCallback = empty_callback;
    REG_IE = 0x2601;
    REG_DISPSTAT = 8;
    REG_IME = 1;
    sub_0807C740(0x40);
    eeprom_setup_timer_irq();
}

void hw_reset_init(void) {
    u32 a, b, c;

    REG_IME = 0;
    a = 0;
    CpuFastSet(&a, (void *)EWRAM, 0x01010000);
    b = 0;
    CpuFastSet(&b, (void *)IWRAM, 0x01001F40);
    clear_oam();
    c = 0;
    CpuFastSet(&c, (void *)PLTT, 0x01000100);
    *(u16 *)PLTT = 0x7FFF;
}

void clear_oam(void) {
    vu32 a, b;
    s32 i;

    a = 0xA0;
    CpuFastSet((void *)&a, (void *)OAM, 0x01000100);
    for (i = 0; i < 128; i++)
        gOamBuffer[i].attr0 = 0xA0;
    b = 0;
    CpuFastSet((void *)&b, (void *)VRAM, 0x01006000);
}

void sound_init(struct SoundWork *work) {
    sound_engine_init(work);
    sound_set_song_table(gSongTable);
    sound_set_se_table(gSoundEffectTable);
    sound_set_drum_kit(&gDrumKit);
    sound_set_instrument_samples((u32)gInstrumentSamples);
    sound_set_drum_samples((u32)gDrumSamples);
    play_song(0);
}

void vblank_irq(void) {
    if (!(gUnk_03002B90 & 1)) {
        gUnk_03002B90 |= 1;
        vblank_body();
        gUnk_03002B90 &= ~1;
        if (gUnk_03005010.unk0 & 0x80)
            sio_vblank_start_frame();
        REG_IME = 0;
        if (++gUnk_03002410 > 5 && gSioLink.sendPending) {
            gUnk_03005010.unk1E = 0xFF;
            INTR_CHECK |= 0x80;
        }
        INTR_CHECK |= 1;
        REG_IME = 1;
    }
}

void vblank_body(void) {
    s32 i;

    if (!(gUnk_03000434 & 1)) {
        REG_BG0HOFS = gBg0Scroll.x + gUnk_03002C2C.x;
        REG_BG0VOFS = gBg0Scroll.y + gUnk_03002C2C.y;
        REG_BG1HOFS = gBg1Scroll.x + gUnk_03002C2C.x;
        REG_BG1VOFS = gBg1Scroll.y + gUnk_03002C2C.y;
        REG_BG2HOFS = gBg2Scroll.x + gUnk_03002C2C.x;
        REG_BG2VOFS = gBg2Scroll.y + gUnk_03002C2C.y;
        REG_BG3HOFS = gBg3Scroll.x + gUnk_03002C2C.x;
        REG_BG3VOFS = gBg3Scroll.y + gUnk_03002C2C.y;
    }
    if (gVBlankOamMode != 0) {
        if (gVBlankOamMode == 2) {
            medabot_sprite_slots_update();
            copy_oam_affine_params(gSpriteWork->oamBuf, gSpriteWork->affineBuf);
            for (i = 0; i < 88; i++)
                gOamBuffer[i].affineParam = gSpriteWork->oamBuf[i].affineParam;
            for (i = 0; i < 40; i++)
                gSpriteWork->oamBuf[i].affineParam = gOamBuffer[88 + i].affineParam;
            if (gGameWork.skipOamHigh == 0)
                CpuFastSet(gSpriteWork->oamBuf, (void *)(OAM + 88 * 8), 0x50);
            gSpriteWork->oamCount = 0;
            gSpriteWork->affineIdx = 0;
            if (gGameWork.oamUploadPending)
                CpuFastSet(gOamBuffer, (void *)OAM, 0xB0);
        } else {
            gVBlankOamMode = 0;
        }
    } else if (gGameWork.oamUploadPending) {
        CpuFastSet(gOamBuffer, (void *)OAM, 0x100);
    }
    gGameWork.oamUploadPending = 0;
    gVBlankOnceCallback();
    gVBlankCallback();
    gVBlankOnceCallback = empty_callback;
    INTR_CHECK = 1;
    REG_IF = 1;
    sound_mix_tick();
    sound_engine_tick();
}

void hblank_irq(void) {
    gHBlankCallback();
    REG_IF = 2;
}

// The default for every IRQ table slot and the VBlank callbacks: does nothing.
void empty_callback(void) {}

void read_keys(void) {
    u16 prev;

    gPrevKeys = prev = gHeldKeys;
    gHeldKeys = REG_KEYINPUT ^ 0x3FF;
    gNewKeys = gHeldKeys & ~prev;
    gReleasedKeys = prev & ~gHeldKeys;
    gRepeatKeys = 0;
    if (gNewKeys) {
        gRepeatKeys = gNewKeys;
        gKeyRepeatTimer = 16;
    }
    if (gHeldKeys) {
        if (gKeyRepeatTimer == 0) {
            gRepeatKeys = gNewKeys | gHeldKeys;
            gKeyRepeatTimer = 3;
        } else {
            gKeyRepeatTimer--;
        }
    }
}

void soft_reset(void) {
    u32 i;

    if (gUnk_03005030) {
        gUnk_03005010.unk4 = 0xFFFF;
        gUnk_03005010.unk6 = -1;
        for (i = 0; i < 8; i++) {
            serial_prepare_send_packet(&gUnk_03005010.unk4);
            VBlankIntrWait();
        }
        gUnk_03005030 = 0;
        serial_multiplayer_init();
    }
    VBlankIntrWait();
    REG_BLDCNT = 0xFF;
    REG_BLDY = 0x10;
    REG_SOUNDCNT_X = 0;
    REG_IME = 0;
    hw_reset_init();
    irq_init();
    serial_link_init();
    gGameMode = 3;
    gGameState = 0;
    gGameSubState = 0;
    REG_DMA0CNT_H = 0;
}

static u32 check_soft_reset(void) {
    if ((*(u8 *)&gHeldKeys & 0xF) == 0xF && (*(u8 *)&gNewKeys & 8)) {
        soft_reset();
        read_keys();
        return 1;
    }
    return 0;
}

void dma1_irq_sound(void) {
    sound_mix_refill_fifo_a();
}

void dma2_irq_sound(void) {
    sound_mix_refill_fifo_b();
}

// Empty and never referenced (dead code kept in the ROM).
static void main_unused_stub_1(void) {}

static void main_unused_stub_2(void) {}
