// Mode-2 state 8: entered after a lost Robattle (battle/prebattle.c sub-states 0x74/0x75); shows Ikki
// falling on the Medabots logo. Name is a guess. clear_or_fill_bg2_tilemap is its BG2 helper;
// sub_0805FAF0 runs the sub-states gUnk_08483CA4.
#include "global.h"

static inline void *vram_at(u32 off) {
    return (void *)(0x06004000 + off);
}

static void clear_or_fill_bg2_tilemap(s32 a) {
    u16 buf[0x20];
    u16 *d;
    u16 *s;
    s32 i;

    if (a < 8) {
        u32 zero = 0;

        CpuFastSet(&zero, buf, 0x01000010);
        CpuSet((u8 *)VRAM + ((REG_BG2CNT >> 8) & 0x1F) * 0x800 + (7 - a) * 2, buf, (a + 1) & 0x1FFFFF);
        CpuSet((u8 *)VRAM + ((REG_BG2CNT >> 8) & 0x1F) * 0x800 + 0x2C, &buf[0x1D - a], (a + 1) & 0x1FFFFF);
    } else {
        a -= 8;
        CpuFastSet((u8 *)VRAM + ((REG_BG2CNT >> 8) & 0x1F) * 0x800, buf, 0x10);
        d = &buf[14];
        s = &buf[13 - a];
        for (i = 13; i >= 0; i--) {
            if (i <= a)
                *d = buf[0];
            else
                *d = *s--;
            d--;
        }
        d = &buf[15];
        s = &buf[16 + a];
        for (i = 13; i >= 0; i--) {
            if (i <= a)
                *d = buf[29];
            else
                *d = *s++;
            d++;
        }
    }
    for (i = 0; i < 20; i++)
        CpuFastSet(buf, (u8 *)VRAM + ((REG_BG1CNT >> 8) & 0x1F) * 0x800 + i * 0x40, 0x10);
}

void sub_0805FAF0(void) {
    gUnk_08483CA4[gGameSubState]();
    if (gFrameCounter & 1)
        gBg3Scroll.y++;
}

void sub_0805FB2C(void) {
    u32 zero = 0;

    CpuFastSet(&zero, (void *)VRAM, 0x01006000);
    sub_08059D04();
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

void sub_0805FBA8(void) {
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
    gUnk_03006F74->unk36 = (size >> 5) - 1;
    zero8 = 0;
    zero16 = 0;
    CpuFastSet(gUnk_0879559C, (void *)PLTT, 0x80);
    CpuFastSet(gUnk_080AF900, (void *)(PLTT + 0x200), 0x10);
    lz_decompress_dispatch(gUnk_08785F34, (void *)0x06010000);
    gUnk_03002C30[0].unk0 = 0x8A20;
    gUnk_03002C30[0].unk1C = 2;
    gUnk_03002C30[0].unk2 = 0x78;
    gUnk_03002C30[0].unk4 = -0x20;
    gUnk_03002C30[0].unkA = zero8;
    gUnk_03002C30[0].unk6 = 0x108;
    gUnk_03002C30[0].unk8 = 0x80;
    gUnk_03002C30[0].unk9 = 0x80;
    gUnk_03002C30[0].unk18 = zero16;
    gUnk_03002C30[1].unk0 = 0x8220;
    gUnk_03002C30[1].unk1C = 2;
    gUnk_03002C30[1].unk2 = 0x78;
    gUnk_03002C30[1].unk4 = -0x40;
    gUnk_03002C30[1].unkA = one;
    gUnk_03002C30[1].unk6 = 0x109;
    gUnk_03002C30[1].unk8 = 0x80;
    gUnk_03002C30[1].unk9 = 0x80;
    gUnk_03002C30[1].unk18 = zero16;
    gUnk_03006F74->unk2 = zero16;
    gUnk_03006F74->unk15 = 0x3C;
    gUnk_03006F74->unk16 = zero8;
    gGameSubState++;
}

void sub_0805FD1C(void) {
    REG_DISPCNT |= 0x800;
    REG_DISPCNT |= 0x1000;
    gUnk_03006F74->unk0 = 0x20;
    REG_BLDY = gUnk_03006F74->unk0 >> 1;
    gGameSubState++;
}

void sub_0805FD60(void) {
    struct Unk_03006F74 *p = gUnk_03006F74;

    if (p->unk0 != 0) {
        REG_BLDY = p->unk0-- >> 1;
    } else {
        p->unk2 = 0;
        gUnk_03002C30[1].unk0 |= 0x4000;
        gUnk_03002C30[1].unk1A = 0;
        gGameSubState++;
    }
}

void sub_0805FDB4(void) {
    struct Unk_03002C30 *s = gUnk_03002C30;
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
        gUnk_03006F74->unk3A = zero;
        gGameSubState++;
    }
}

void sub_0805FE90(void) {
    u32 done = 0;
    struct Unk_03006F74 *p = gUnk_03006F74;
    u16 t;
    u16 y;

    if (p->unk3A <= 7) {
        if (++p->unk3A == 4) {
            REG_DISPCNT &= 0xFEFF;
            REG_DISPCNT |= 0x200;
            play_sound_effect(0x17);
        }
        if (gUnk_03006F74->unk3A <= 3)
            gUnk_03002C30[1].unk4--;
        else
            gUnk_03002C30[1].unk4++;
    } else {
        if ((u16)p->unk3A <= 0x31)
            p->unk3A++;
        t = gUnk_03006F74->unk3A - 9;
        if (t == 0)
            gUnk_03002C30[0].unk0 |= 0x4000;
        if (t <= 0x13) {
            s32 q = (t << 6) / 20;

            y = q - 0x20;
            gUnk_03002C30[0].unk9 = gUnk_03002C30[0].unk8 = -0x80 - q;
        } else {
            t -= 0x14;
            if (t == 0) {
                gUnk_03002C30[0].unk8 = 0x40;
                gUnk_03002C30[0].unk9 = 0x40;
            }
            if (t <= 0xC)
                y = gUnk_080AF95A[t] + 0x20;
            else {
                y = 0x20;
                t -= 0xD;
                if (t <= 7)
                    clear_or_fill_bg2_tilemap(t);
                else
                    done = 1;
            }
        }
        gUnk_03002C30[0].unk4 = y;
    }
    if (++gUnk_03002C30[1].unk1A > 0x47)
        gUnk_03002C30[1].unk1A = 0;
    gUnk_03002C30[1].unk6 = gUnk_080AF942[gUnk_03002C30[1].unk1A / 6];
    if ((KEYS_LO(gNewKeys) & 1) && done) {
        gUnk_03002C30[1].unk0 = 0xCA20;
        gUnk_03006F74->unk3A = 0;
        gGameSubState += 2;
    }
}

void sub_08060018(void) {
    if (gUnk_03006F74->unk0 != 32) {
        gUnk_03006F74->unk0++;
        REG_BLDY = gUnk_03006F74->unk0 >> 1;
    } else {
        REG_DISPCNT &= 0xFDFF;
        gGameMode = 3;
        gGameState = 0;
        gGameSubState = 0;
    }
}

void sub_0806006C(void) {
    struct Unk_03006F74 *p = gUnk_03006F74;

    p->unk3A++;
    clear_or_fill_bg2_tilemap(p->unk3A + 8);
    if (++gUnk_03002C30[1].unk1A > 0x47)
        gUnk_03002C30[1].unk1A = 0;
    gUnk_03002C30[1].unk6 = gUnk_080AF968[(u16)(gUnk_03002C30[1].unk1A / 6)];
    p = gUnk_03006F74;
    if (p->unk3A > 13) {
        p->unk0 = 0;
        gGameSubState--;
    }
}
