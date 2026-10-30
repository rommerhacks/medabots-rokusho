// Boot and the main loop: AgbMain initialises the hardware, interrupts, sound and serial link, then runs one
// frame per VBlank: read_keys, the gGameMode handler (gGameModeHandlers, GAME_MODE_* in constants/game_states.h:
// menus/battle, field, menu screens incl. the title menu, scenes such as boot/intro/minigames), the OAM build
// (engine/oam.c) and the link packet. The VBlank / HBlank / sound DMA interrupt handlers and the soft reset
// (A+B+START+SELECT) live here too.

#include "global.h"

static u32 check_soft_reset(void);

void AgbMain(void) {
    s32 i;
    u8 prevConnected;

    REG_WAITCNT = 0x4014;
    hw_reset_init();
    irq_init();
    REG_DISPCNT = 0x60;
    gGameMode = GAME_MODE_SCENE;
    gGameState = MODE3_STATE_BOOT_LOGOS;
    gGameSubState = 0;
    serial_link_init();
    sound_init(&gSoundWorkArea);
    *(u16 *)&gSaveStatus = 0;
    gLinkMultiplayerActive = 0;
    gFramesSinceMainLoop = 0;
    gLinkPackets.linkLost = 0;
    gLinkPackets.playerJoined = 0;
    for (;;) {
        VBlankIntrWait();
        gFramesSinceMainLoop = 0;
        read_keys();
        gFrameCounter++;
        if (gPlayTimeRunning && gPlayerRecord.playTime < 0x014996FF)
            gPlayerRecord.playTime++;
        prevConnected = gSioLink.connected;
        gLinkPackets.playerJoined = 0;
        gLinkPackets.linkLost = 0;
        gLinkPackets.status = serial_link_init_and_status((u32 *)gLinkPackets.recv);
        for (i = 0; i < 4; i++) {
            if (gLinkPackets.status & (1 << i)) {
                gLinkPackets.recvTimeouts[i] = 0;
                if (!((prevConnected >> i) & 1)) {
                    gSioLink.connected |= 1 << i;
                    gLinkPackets.playerJoined |= 0xFF;
                }
            } else if (gLinkPackets.recvTimeouts[i] > 10) {
                if ((gSioLink.connected >> i) & 1)
                    gLinkPackets.linkLost |= 0xFF;
                gSioLink.connected &= ~(1 << i);
                gLinkPackets.recvTimeouts[i] = 0;
            } else {
                gLinkPackets.recvTimeouts[i]++;
            }
        }
        if (check_soft_reset()) {
            VBlankIntrWait();
            sound_init(&gSoundWorkArea);
            VBlankIntrWait();
        } else if (gLinkMultiplayerActive) {
            u32 other = 0;

            if (gLinkPlayerId == 0)
                other = 1;
            if (gLinkPackets.recv[other][0] == 0xFFFF && gLinkPackets.recv[other][1] == gLinkPackets.recv[other][0]) {
                gGameMode = GAME_MODE_MENU_BATTLE;
                gGameState = MODE0_STATE_LINK_ROBATTLE;
                gGameSubState = 16;
            }
        }
        gGameModeHandlers[gGameMode]();
        build_sprite_oam();
        serial_prepare_send_packet(&gLinkPackets.sendKeys);
    }
}

void irq_init(void) {
    CpuSet(gIntrTableTemplate, gIntrTable, CPU_SET_32BIT | 0xE);
    CpuSet(irq_dispatch_arm, gIntrMain, CPU_SET_32BIT | 0x200);
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
    u32 ewram_fill, iwram_fill, pltt_fill;

    REG_IME = 0;
    ewram_fill = 0;
    CpuFastSet(&ewram_fill, (void *)EWRAM, 0x01010000);
    iwram_fill = 0;
    CpuFastSet(&iwram_fill, (void *)IWRAM, 0x01001F40);
    clear_oam();
    pltt_fill = 0;
    CpuFastSet(&pltt_fill, (void *)PLTT, 0x01000100);
    *(u16 *)PLTT = 0x7FFF;
}

void clear_oam(void) {
    vu32 hidden_y, zero;
    s32 i;

    hidden_y = 0xA0;
    CpuFastSet((void *)&hidden_y, (void *)OAM, 0x01000100);
    for (i = 0; i < 128; i++)
        gOamBuffer[i].attr0 = 0xA0;
    zero = 0;
    CpuFastSet((void *)&zero, (void *)VRAM, 0x01006000);
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
    if (!(gVBlankFlags & 1)) {
        gVBlankFlags |= 1;
        vblank_body();
        gVBlankFlags &= ~1;
        if (gLinkPackets.status & 0x80)
            sio_vblank_start_frame();
        REG_IME = 0;
        if (++gFramesSinceMainLoop > 5 && gSioLink.sendPending) {
            gLinkPackets.linkLost = 0xFF;
            INTR_CHECK |= 0x80;
        }
        INTR_CHECK |= 1;
        REG_IME = 1;
    }
}

void vblank_body(void) {
    s32 i;

    if (!(gVBlankBgFlags & 1)) {
        REG_BG0HOFS = gBg0Scroll.x + gBgScrollOffset.x;
        REG_BG0VOFS = gBg0Scroll.y + gBgScrollOffset.y;
        REG_BG1HOFS = gBg1Scroll.x + gBgScrollOffset.x;
        REG_BG1VOFS = gBg1Scroll.y + gBgScrollOffset.y;
        REG_BG2HOFS = gBg2Scroll.x + gBgScrollOffset.x;
        REG_BG2VOFS = gBg2Scroll.y + gBgScrollOffset.y;
        REG_BG3HOFS = gBg3Scroll.x + gBgScrollOffset.x;
        REG_BG3VOFS = gBg3Scroll.y + gBgScrollOffset.y;
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
    gHeldKeys = REG_KEYINPUT ^ KEYS_MASK;
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

    if (gLinkMultiplayerActive) {
        gLinkPackets.sendKeys = 0xFFFF;
        gLinkPackets.sendData = -1;
        for (i = 0; i < 8; i++) {
            serial_prepare_send_packet(&gLinkPackets.sendKeys);
            VBlankIntrWait();
        }
        gLinkMultiplayerActive = 0;
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
    gGameMode = GAME_MODE_SCENE;
    gGameState = MODE3_STATE_BOOT_LOGOS;
    gGameSubState = 0;
    REG_DMA0CNT_H = 0;
}

static u32 check_soft_reset(void) {
    if ((KEYS_LO(gHeldKeys) & SOFT_RESET_KEYS) == SOFT_RESET_KEYS && (KEYS_LO(gNewKeys) & START_BUTTON)) {
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
