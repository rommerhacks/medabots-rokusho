// Mode-2 state 8: entered after a lost Robattle (battle/prebattle.c sub-states 0x74/0x75); shows Ikki
// falling on the Medabots logo. Name is a guess. game_over_draw_wipe is its BG2 helper;
// game_over_update runs the sub-states gGameOverStates: 0 reset, 1 graphics, 2-3 fade in, 4 Ikki falls,
// 5 the logo drops and bounces (A when done), 7 wipe out, 6 fade out back to the boot logos.
#include "global.h"

static inline void *vram_at(u32 off) {
    return (void *)(0x06004000 + off);
}

static void game_over_draw_wipe(s32 step) {
    u16 buf[0x20];
    u16 *d;
    u16 *s;
    s32 i;

    if (step < 8) {
        u32 zero = 0;

        CpuFastSet(&zero, buf, 0x01000010);
        CpuSet((u8 *)VRAM + ((REG_BG2CNT >> 8) & 0x1F) * 0x800 + (7 - step) * 2, buf, (step + 1) & 0x1FFFFF);
        CpuSet((u8 *)VRAM + ((REG_BG2CNT >> 8) & 0x1F) * 0x800 + 0x2C, &buf[0x1D - step], (step + 1) & 0x1FFFFF);
    } else {
        step -= 8;
        CpuFastSet((u8 *)VRAM + ((REG_BG2CNT >> 8) & 0x1F) * 0x800, buf, 0x10);
        d = &buf[14];
        s = &buf[13 - step];
        for (i = 13; i >= 0; i--) {
            if (i <= step)
                *d = buf[0];
            else
                *d = *s--;
            d--;
        }
        d = &buf[15];
        s = &buf[16 + step];
        for (i = 13; i >= 0; i--) {
            if (i <= step)
                *d = buf[29];
            else
                *d = *s++;
            d++;
        }
    }
    for (i = 0; i < 20; i++)
        CpuFastSet(buf, (u8 *)VRAM + ((REG_BG1CNT >> 8) & 0x1F) * 0x800 + i * 0x40, 0x10);
}

void game_over_update(void) {
    gGameOverStates[gGameSubState]();
    if (gFrameCounter & 1)
        gBg3Scroll.y++;
}

void game_over_reset(void) {
    u32 zero = 0;

    CpuFastSet(&zero, (void *)VRAM, 0x01006000);
    free_all_sprites();
    reset_bg_scroll();
    REG_WIN0H = 0xF0;
    REG_WIN0V = 0x80;
    REG_WININ = 0x3F3F;
    REG_WINOUT = 0x2F;
    REG_DISPCNT = 0x2060;
    REG_BLDCNT = 0x2BF;
    play_song(0x12);
    REG_BLDY = 0x10;
    gGameSubState++;
}

void game_over_load_graphics(void) {
    vu16 *bg0, *bg1, *bg2, *bg3;
    u16 v;
    u32 size;
    u8 one;
    u8 zero8;
    u16 zero16;

    bg0 = &REG_BG0CNT;
    one = 1;
    v = 0x1F04;
    *bg0 = v;
    bg1 = &REG_BG1CNT;
    v -= 0xFF;
    *bg1 = v;
    bg2 = &REG_BG2CNT;
    v -= 0xFF;
    *bg2 = v;
    bg3 = &REG_BG3CNT;
    v = 0x3C07;
    *bg3 = v;
    decompress_and_write_tilemap(gUnk_087962E8, *bg0);
    decompress_and_write_tilemap(gUnk_08796474, *bg2);
    decompress_and_write_tilemap(gUnk_08796598, *bg3);
    size = dma3_copy_or_decompress(gUnk_0879579C, gDecompressBuffer);
    CpuCopy16(gDecompressBuffer, vram_at(0), size);
    lz_decompress_dispatch(gUnk_08784CB0, vram_at(size));
    gMenuWork->unk36 = (size >> 5) - 1;
    zero8 = 0;
    zero16 = 0;
    CpuFastSet(gUnk_0879559C, (void *)PLTT, 0x80);
    CpuFastSet(gUnk_080AF900, (void *)(PLTT + 0x200), 0x10);
    lz_decompress_dispatch(gUnk_08785F34, (void *)0x06010000);
    gSpriteEntries[0].unk0 = 0x8A20;
    gSpriteEntries[0].unk1C = 2;
    gSpriteEntries[0].unk2 = 0x78;
    gSpriteEntries[0].unk4 = -0x20;
    gSpriteEntries[0].unkA = zero8;
    gSpriteEntries[0].unk6 = 0x108;
    gSpriteEntries[0].unk8 = 0x80;
    gSpriteEntries[0].unk9 = 0x80;
    gSpriteEntries[0].unk18 = zero16;
    gSpriteEntries[1].unk0 = 0x8220;
    gSpriteEntries[1].unk1C = 2;
    gSpriteEntries[1].unk2 = 0x78;
    gSpriteEntries[1].unk4 = -0x40;
    gSpriteEntries[1].unkA = one;
    gSpriteEntries[1].unk6 = 0x109;
    gSpriteEntries[1].unk8 = 0x80;
    gSpriteEntries[1].unk9 = 0x80;
    gSpriteEntries[1].unk18 = zero16;
    gMenuWork->unk2 = zero16;
    gMenuWork->unk15 = 0x3C;
    gMenuWork->unk16 = zero8;
    gGameSubState++;
}

void game_over_show_screen(void) {
    REG_DISPCNT |= 0x800;
    REG_DISPCNT |= 0x1000;
    gMenuWork->unk0 = 0x20;
    REG_BLDY = gMenuWork->unk0 >> 1;
    gGameSubState++;
}

void game_over_fade_in(void) {
    struct MenuWork *p = gMenuWork;

    if (p->unk0 != 0) {
        REG_BLDY = p->unk0-- >> 1;
    } else {
        p->unk2 = 0;
        gSpriteEntries[1].unk0 |= 0x4000;
        gSpriteEntries[1].unk1A = 0;
        gGameSubState++;
    }
}

void game_over_ikki_fall(void) {
    struct SpriteEntry *s = gSpriteEntries;
    u32 c = s[1].unk1A;
    u16 zero;

    s[1].unk6 = (c & 4) ? 0x109 : 0x10A;
    zero = 0;
    c = (u16)c;
    if ((u16)c < 0x78) {
        s[1].unk4 = (s32)(s[1].unk1A * 0xA8) / 0x78 - 0x40;
        s[1].unk8 = -0x80 - (s32)(s[1].unk1A * 64) / 0x78;
        s[1].unk9 = -0x80 - (s32)(s[1].unk1A * 64) / 0x78;
        s[1].unk18 = (c & 0x3F) * 16 + 0x340;
        s[1].unk1A = c + 1;
    } else {
        REG_DISPCNT |= 0x100;
        s[1].unk6 = 0x10B;
        s[1].unk8 = 0x40;
        s[1].unk9 = 0x40;
        s[1].unk4 = 0x68;
        s[1].unk18 = zero;
        s[1].unk1A = zero;
        gMenuWork->unk3A = zero;
        gGameSubState++;
    }
}

void game_over_logo_drop(void) {
    u32 done = 0;
    struct MenuWork *p = gMenuWork;
    u16 t;
    u16 y;

    if (p->unk3A <= 7) {
        if (++p->unk3A == 4) {
            REG_DISPCNT &= 0xFEFF;
            REG_DISPCNT |= 0x200;
            play_sound_effect(0x17);
        }
        if (gMenuWork->unk3A <= 3)
            gSpriteEntries[1].unk4--;
        else
            gSpriteEntries[1].unk4++;
    } else {
        if ((u16)p->unk3A <= 0x31)
            p->unk3A++;
        t = gMenuWork->unk3A - 9;
        if (t == 0)
            gSpriteEntries[0].unk0 |= 0x4000;
        if (t <= 0x13) {
            s32 q = (t << 6) / 20;

            y = q - 0x20;
            gSpriteEntries[0].unk9 = gSpriteEntries[0].unk8 = -0x80 - q;
        } else {
            t -= 0x14;
            if (t == 0) {
                gSpriteEntries[0].unk8 = 0x40;
                gSpriteEntries[0].unk9 = 0x40;
            }
            if (t <= 0xC)
                y = gGameOverLogoBounce[t] + 0x20;
            else {
                y = 0x20;
                t -= 0xD;
                if (t <= 7)
                    game_over_draw_wipe(t);
                else
                    done = 1;
            }
        }
        gSpriteEntries[0].unk4 = y;
    }
    if (++gSpriteEntries[1].unk1A > 0x47)
        gSpriteEntries[1].unk1A = 0;
    gSpriteEntries[1].unk6 = gGameOverIkkiFrames[gSpriteEntries[1].unk1A / 6];
    if ((KEYS_LO(gNewKeys) & 1) && done) {
        gSpriteEntries[1].unk0 = 0xCA20;
        gMenuWork->unk3A = 0;
        gGameSubState += 2;
    }
}

void game_over_fade_out_exit(void) {
    if (gMenuWork->unk0 != 32) {
        gMenuWork->unk0++;
        REG_BLDY = gMenuWork->unk0 >> 1;
    } else {
        REG_DISPCNT &= 0xFDFF;
        gGameMode = 3;
        gGameState = 0;
        gGameSubState = 0;
    }
}

void game_over_wipe_out(void) {
    struct MenuWork *p = gMenuWork;

    p->unk3A++;
    game_over_draw_wipe(p->unk3A + 8);
    if (++gSpriteEntries[1].unk1A > 0x47)
        gSpriteEntries[1].unk1A = 0;
    gSpriteEntries[1].unk6 = gGameOverIkkiFramesExit[(u16)(gSpriteEntries[1].unk1A / 6)];
    p = gMenuWork;
    if (p->unk3A > 13) {
        p->unk0 = 0;
        gGameSubState--;
    }
}
