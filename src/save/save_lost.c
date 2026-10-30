// Mode-2 state 9: "saved data has been lost". Entered when the save fails to load; save_lost_dispatch
// runs gSaveLostStates: load the screen, fade in, wait for A, fade out, then save_lost_erase_and_restart
// zeroes EEPROM block 0 and goes to the title screen.
#include "global.h"
#include "constants/sprites.h"

// Cycles sprite 0 through its 8 frames (gSaveLostSpriteFrames), one every 8 frames.
void save_lost_animate_sprite(void) {
    if (++gSpriteEntries[0].timer > 0x3F)
        gSpriteEntries[0].timer = 0;
    gSpriteEntries[0].frame = gSaveLostSpriteFrames[(gSpriteEntries[0].timer >> 3) & 7] + 0x100;
}

void save_lost_dispatch(void) {
    gSaveLostStates[gGameSubState]();
    if (gFrameCounter & 1)
        gBg3Scroll.y--;
}

void save_lost_clear_screen(void) {
    u32 zero = 0;

    CpuFastSet(&zero, (void *)VRAM, 0x01006000);
    reset_bg_scroll();
    clear_battle_sprite_slot(0, 0x80);
    REG_DISPCNT = 0x60;
    REG_BLDCNT = 0x2FF;
    REG_BLDY = 0x10;
    gGameSubState++;
}

void save_lost_load_graphics(void) {
    s32 size;
    vu16 *bg0, *bg1, *bg3;
    u16 cnt;

    bg0 = &REG_BG0CNT;
    cnt = 0x1F04;
    *bg0 = cnt;
    bg1 = &REG_BG1CNT;
    cnt -= 0xFF;
    *bg1 = cnt;
    bg3 = &REG_BG3CNT;
    cnt = 0x3C07;
    *bg3 = cnt;
    decompress_and_write_tilemap(gSaveLostBg0Tilemap, *bg0);
    decompress_and_write_tilemap(gSaveLostBg1Tilemap, *bg1);
    decompress_and_write_tilemap(gSaveLostBg3Tilemap, *bg3);
    size = dma3_copy_or_decompress(gSaveLostBgTiles, gDecompressBuffer);
    CpuCopy16(gDecompressBuffer, (void *)BG_CHAR_ADDR(1), size);
    gMenuWork->bg_tile_base = size / 32 - 1;
    CpuFastSet(gSaveLostBgPalette, (void *)PLTT, 0x38);
    CpuFastSet(gSaveLostSpritePalette, (void *)(PLTT + 0x200), 8);
    lz_decompress_dispatch(gCommonObjTilesLz, (void *)OBJ_VRAM0);
    gSpriteEntries[0].flags = SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE;
    gSpriteEntries[0].frame_table = 2;
    gSpriteEntries[0].palette = 0;
    gSpriteEntries[0].frame = 0x112;
    gSpriteEntries[0].x = 0x70;
    gSpriteEntries[0].y = 0x18;
    gSpriteEntries[0].timer = 0;
    gGameSubState++;
}

void save_lost_start_fade_in(void) {
    REG_DISPCNT |= 0x100;
    REG_DISPCNT |= 0x200;
    REG_DISPCNT |= 0x800;
    REG_DISPCNT |= 0x1000;
    gMenuWork->fade_level = 0x20;
    REG_BLDY = gMenuWork->fade_level >> 1;
    gGameSubState++;
}

void save_lost_fade_in(void) {
    struct MenuWork *state = gMenuWork;

    if (state->fade_level != 0)
        REG_BLDY = state->fade_level-- >> 1;
    else
        gGameSubState++;
}

void save_lost_wait_for_a(void) {
    save_lost_animate_sprite();
    if (KEYS_LO(gNewKeys) & A_BUTTON) {
        play_sound_effect(4);
        gMenuWork->fade_level = 0;
        gGameSubState++;
    }
}

void save_lost_fade_out(void) {
    save_lost_animate_sprite();
    if (gMenuWork->fade_level != 32) {
        gMenuWork->fade_level++;
        REG_BLDY = gMenuWork->fade_level >> 1;
    } else {
        REG_DISPCNT &= 0xFDFF;
        gGameSubState++;
    }
}

// Once the A sound has finished: zeroes EEPROM block 0 (the save header, up to 4 tries), then the title.
void save_lost_erase_and_restart(void) {
    u16 buf[4];
    u32 playing = is_sound_effect_playing(4);
    u16 ie;
    u32 zero;
    s32 i;

    if (playing == 0) {
        REG_IME = playing;
        ie = REG_IE;
        REG_IE = 0x2020;
        REG_IME = 1;
        zero = playing;
        CpuSet(&zero, buf, CPU_SET_SRC_FIXED | CPU_SET_32BIT | 0x2);
        for (i = 0; i <= 3; i++) {
            if (ProgramEepromDwordEx(0, buf) == 0)
                break;
        }
        REG_IE |= ie;
        gGameMode = GAME_MODE_SCENE;
        gGameState = MODE3_STATE_TITLE_SCREEN;
        gGameSubState = 0;
        gTitleSkipIntro = 1;
    }
}
