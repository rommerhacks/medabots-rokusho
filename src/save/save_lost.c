// Mode-2 state 9: "saved data has been lost". Entered when the save fails to load; save_lost_dispatch
// runs gUnk_08483CC4 (message, then sub_080603A4 zeroes EEPROM block 0). sub_080600E0 is its message helper.
#include "global.h"

void sub_080600E0(void) {
    if (++gSpriteEntries[0].unk1A > 0x3F)
        gSpriteEntries[0].unk1A = 0;
    gSpriteEntries[0].unk6 = gUnk_080AF980[(gSpriteEntries[0].unk1A >> 3) & 7] + 0x100;
}

void save_lost_dispatch(void) {
    gUnk_08483CC4[gGameSubState]();
    if (gFrameCounter & 1)
        gBg3Scroll.y--;
}

void sub_08060154(void) {
    u32 zero = 0;

    CpuFastSet(&zero, (void *)VRAM, 0x01006000);
    reset_bg_scroll();
    clear_battle_sprite_slot(0, 0x80);
    REG_DISPCNT = 0x60;
    REG_BLDCNT = 0x2FF;
    REG_BLDY = 0x10;
    gGameSubState++;
}

void sub_080601A4(void) {
    s32 size;
    vu16 *bg0, *bg1, *bg3;
    u16 v;

    bg0 = &REG_BG0CNT;
    v = 0x1F04;
    *bg0 = v;
    bg1 = &REG_BG1CNT;
    v -= 0xFF;
    *bg1 = v;
    bg3 = &REG_BG3CNT;
    v = 0x3C07;
    *bg3 = v;
    decompress_and_write_tilemap(gUnk_08792CD0, *bg0);
    decompress_and_write_tilemap(gUnk_08792E6C, *bg1);
    decompress_and_write_tilemap(gUnk_08792FC4, *bg3);
    size = dma3_copy_or_decompress(gUnk_08791D88, gDecompressBuffer);
    CpuCopy16(gDecompressBuffer, (void *)0x06004000, size);
    gUnk_03006F74->unk36 = size / 32 - 1;
    CpuFastSet(gUnk_08791CA8, (void *)PLTT, 0x38);
    CpuFastSet(gUnk_080AF988, (void *)(PLTT + 0x200), 8);
    lz_decompress_dispatch(gUnk_08785F34, (void *)0x06010000);
    gSpriteEntries[0].unk0 = 0xC000;
    gSpriteEntries[0].unk1C = 2;
    gSpriteEntries[0].unkA = 0;
    gSpriteEntries[0].unk6 = 0x112;
    gSpriteEntries[0].unk2 = 0x70;
    gSpriteEntries[0].unk4 = 0x18;
    gSpriteEntries[0].unk1A = 0;
    gGameSubState++;
}

void sub_08060298(void) {
    REG_DISPCNT |= 0x100;
    REG_DISPCNT |= 0x200;
    REG_DISPCNT |= 0x800;
    REG_DISPCNT |= 0x1000;
    gUnk_03006F74->unk0 = 0x20;
    REG_BLDY = gUnk_03006F74->unk0 >> 1;
    gGameSubState++;
}

void sub_080602F4(void) {
    struct Unk_03006F74 *p = gUnk_03006F74;

    if (p->unk0 != 0)
        REG_BLDY = p->unk0-- >> 1;
    else
        gGameSubState++;
}

void sub_08060324(void) {
    sub_080600E0();
    if (KEYS_LO(gNewKeys) & 1) {
        play_sound_effect(4);
        gUnk_03006F74->unk0 = 0;
        gGameSubState++;
    }
}

void sub_0806035C(void) {
    sub_080600E0();
    if (gUnk_03006F74->unk0 != 32) {
        gUnk_03006F74->unk0++;
        REG_BLDY = gUnk_03006F74->unk0 >> 1;
    } else {
        REG_DISPCNT &= 0xFDFF;
        gGameSubState++;
    }
}

void sub_080603A4(void) {
    u16 buf[4];
    u32 r = is_sound_playing_with_lock(4);
    u16 ie;
    u32 zero;
    s32 i;

    if (r == 0) {
        REG_IME = r;
        ie = REG_IE;
        REG_IE = 0x2020;
        REG_IME = 1;
        zero = r;
        CpuSet(&zero, buf, 0x05000002);
        for (i = 0; i <= 3; i++) {
            if (ProgramEepromDwordEx(0, buf) == 0)
                break;
        }
        REG_IE |= ie;
        gGameMode = 3;
        gGameState = 2;
        gGameSubState = 0;
        gTitleSkipIntro = 1;
    }
}
