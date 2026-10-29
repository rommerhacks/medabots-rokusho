// Mode-2 state 8: entered after a lost Robattle (battle/prebattle.c sub-states 0x74/0x75); shows Ikki
// falling on the Medabots logo. Name is a guess. game_over_draw_wipe is its BG2 helper;
// game_over_update runs the sub-states gGameOverStates: 0 reset, 1 graphics, 2-3 fade in, 4 Ikki falls,
// 5 the logo drops and bounces (A when done), 7 wipe out, 6 fade out back to the boot logos.
#include "global.h"
#include "constants/sprites.h"

static inline void *vram_at(u32 off) {
    return (void *)(0x06004000 + off);
}

static void game_over_draw_wipe(s32 step) {
    u16 buf[0x20];
    u16 *dst;
    u16 *src;
    s32 i;

    if (step < 8) {
        u32 zero = 0;

        CpuFastSet(&zero, buf, 0x01000010);
        CpuSet((u8 *)VRAM + BGCNT_SCREEN_OFFSET(REG_BG2CNT) + (7 - step) * 2, buf, (step + 1) & 0x1FFFFF);
        CpuSet((u8 *)VRAM + BGCNT_SCREEN_OFFSET(REG_BG2CNT) + 0x2C, &buf[0x1D - step], (step + 1) & 0x1FFFFF);
    } else {
        step -= 8;
        CpuFastSet((u8 *)VRAM + BGCNT_SCREEN_OFFSET(REG_BG2CNT), buf, 0x10);
        dst = &buf[14];
        src = &buf[13 - step];
        for (i = 13; i >= 0; i--) {
            if (i <= step)
                *dst = buf[0];
            else
                *dst = *src--;
            dst--;
        }
        dst = &buf[15];
        src = &buf[16 + step];
        for (i = 13; i >= 0; i--) {
            if (i <= step)
                *dst = buf[29];
            else
                *dst = *src++;
            dst++;
        }
    }
    for (i = 0; i < 20; i++)
        CpuFastSet(buf, (u8 *)VRAM + BGCNT_SCREEN_OFFSET(REG_BG1CNT) + i * 0x40, 0x10);
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
    u16 bgcnt;
    u32 size;
    u8 one;
    u8 zero8;
    u16 zero16;

    bg0 = &REG_BG0CNT;
    one = 1;
    bgcnt = 0x1F04;
    *bg0 = bgcnt;
    bg1 = &REG_BG1CNT;
    bgcnt -= 0xFF;
    *bg1 = bgcnt;
    bg2 = &REG_BG2CNT;
    bgcnt -= 0xFF;
    *bg2 = bgcnt;
    bg3 = &REG_BG3CNT;
    bgcnt = 0x3C07;
    *bg3 = bgcnt;
    decompress_and_write_tilemap(gGameOverBg0Tilemap, *bg0);
    decompress_and_write_tilemap(gGameOverBg2Tilemap, *bg2);
    decompress_and_write_tilemap(gGameOverBg3Tilemap, *bg3);
    size = dma3_copy_or_decompress(gGameOverBgTiles, gDecompressBuffer);
    CpuCopy16(gDecompressBuffer, vram_at(0), size);
    lz_decompress_dispatch(gMenuDigitTilesLz, vram_at(size));
    gMenuWork->bg_tile_base = (size >> 5) - 1;
    zero8 = 0;
    zero16 = 0;
    CpuFastSet(gGameOverBgPalette, (void *)PLTT, 0x80);
    CpuFastSet(gGameOverObjPalettes, (void *)(PLTT + 0x200), 0x10);
    lz_decompress_dispatch(gCommonObjTilesLz, (void *)0x06010000);
    gSpriteEntries[0].flags = SPRITE_FLAG_ENABLED | SPRITE_PRIORITY(2) | SPRITE_FLAG_AFFINE | SPRITE_FLAG_DOUBLE_SIZE;
    gSpriteEntries[0].frame_table = 2;
    gSpriteEntries[0].x = 0x78;
    gSpriteEntries[0].y = -0x20;
    gSpriteEntries[0].palette = zero8;
    gSpriteEntries[0].frame = 0x108;
    gSpriteEntries[0].scale_x = 0x80;
    gSpriteEntries[0].scale_y = 0x80;
    gSpriteEntries[0].angle = zero16;
    gSpriteEntries[1].flags = SPRITE_FLAG_ENABLED | SPRITE_FLAG_AFFINE | SPRITE_FLAG_DOUBLE_SIZE;
    gSpriteEntries[1].frame_table = 2;
    gSpriteEntries[1].x = 0x78;
    gSpriteEntries[1].y = -0x40;
    gSpriteEntries[1].palette = one;
    gSpriteEntries[1].frame = 0x109;
    gSpriteEntries[1].scale_x = 0x80;
    gSpriteEntries[1].scale_y = 0x80;
    gSpriteEntries[1].angle = zero16;
    gMenuWork->timer = zero16;
    gMenuWork->shake_amplitude = 0x3C;
    gMenuWork->shake_speed = zero8;
    gGameSubState++;
}

void game_over_show_screen(void) {
    REG_DISPCNT |= 0x800;
    REG_DISPCNT |= 0x1000;
    gMenuWork->fade_level = 0x20;
    REG_BLDY = gMenuWork->fade_level >> 1;
    gGameSubState++;
}

void game_over_fade_in(void) {
    struct MenuWork *menu = gMenuWork;

    if (menu->fade_level != 0) {
        REG_BLDY = menu->fade_level-- >> 1;
    } else {
        menu->timer = 0;
        gSpriteEntries[1].flags |= SPRITE_FLAG_VISIBLE;
        gSpriteEntries[1].timer = 0;
        gGameSubState++;
    }
}

void game_over_ikki_fall(void) {
    struct SpriteEntry *sprites = gSpriteEntries;
    u32 fall_frame = sprites[1].timer;
    u16 zero;

    sprites[1].frame = (fall_frame & 4) ? 0x109 : 0x10A;
    zero = 0;
    fall_frame = (u16)fall_frame;
    if ((u16)fall_frame < 0x78) {
        sprites[1].y = (s32)(sprites[1].timer * 0xA8) / 0x78 - 0x40;
        sprites[1].scale_x = -0x80 - (s32)(sprites[1].timer * 64) / 0x78;
        sprites[1].scale_y = -0x80 - (s32)(sprites[1].timer * 64) / 0x78;
        sprites[1].angle = (fall_frame & 0x3F) * 16 + 0x340;
        sprites[1].timer = fall_frame + 1;
    } else {
        REG_DISPCNT |= 0x100;
        sprites[1].frame = 0x10B;
        sprites[1].scale_x = 0x40;
        sprites[1].scale_y = 0x40;
        sprites[1].y = 0x68;
        sprites[1].angle = zero;
        sprites[1].timer = zero;
        gMenuWork->frame = zero;
        gGameSubState++;
    }
}

void game_over_logo_drop(void) {
    u32 done = 0;
    struct MenuWork *menu = gMenuWork;
    u16 phase_frame;
    u16 y;

    if (menu->frame <= 7) {
        if (++menu->frame == 4) {
            REG_DISPCNT &= 0xFEFF;
            REG_DISPCNT |= 0x200;
            play_sound_effect(0x17);
        }
        if (gMenuWork->frame <= 3)
            gSpriteEntries[1].y--;
        else
            gSpriteEntries[1].y++;
    } else {
        if ((u16)menu->frame <= 0x31)
            menu->frame++;
        phase_frame = gMenuWork->frame - 9;
        if (phase_frame == 0)
            gSpriteEntries[0].flags |= SPRITE_FLAG_VISIBLE;
        if (phase_frame <= 0x13) {
            s32 grow = (phase_frame << 6) / 20;

            y = grow - 0x20;
            gSpriteEntries[0].scale_y = gSpriteEntries[0].scale_x = -0x80 - grow;
        } else {
            phase_frame -= 0x14;
            if (phase_frame == 0) {
                gSpriteEntries[0].scale_x = 0x40;
                gSpriteEntries[0].scale_y = 0x40;
            }
            if (phase_frame <= 0xC)
                y = gGameOverLogoBounce[phase_frame] + 0x20;
            else {
                y = 0x20;
                phase_frame -= 0xD;
                if (phase_frame <= 7)
                    game_over_draw_wipe(phase_frame);
                else
                    done = 1;
            }
        }
        gSpriteEntries[0].y = y;
    }
    if (++gSpriteEntries[1].timer > 0x47)
        gSpriteEntries[1].timer = 0;
    gSpriteEntries[1].frame = gGameOverIkkiFrames[gSpriteEntries[1].timer / 6];
    if ((KEYS_LO(gNewKeys) & A_BUTTON) && done) {
        gSpriteEntries[1].flags = SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(2) | SPRITE_FLAG_AFFINE |
                                  SPRITE_FLAG_DOUBLE_SIZE;
        gMenuWork->frame = 0;
        gGameSubState += 2;
    }
}

void game_over_fade_out_exit(void) {
    if (gMenuWork->fade_level != 32) {
        gMenuWork->fade_level++;
        REG_BLDY = gMenuWork->fade_level >> 1;
    } else {
        REG_DISPCNT &= 0xFDFF;
        gGameMode = 3;
        gGameState = 0;
        gGameSubState = 0;
    }
}

void game_over_wipe_out(void) {
    struct MenuWork *menu = gMenuWork;

    menu->frame++;
    game_over_draw_wipe(menu->frame + 8);
    if (++gSpriteEntries[1].timer > 0x47)
        gSpriteEntries[1].timer = 0;
    gSpriteEntries[1].frame = gGameOverIkkiFramesExit[(u16)(gSpriteEntries[1].timer / 6)];
    menu = gMenuWork;
    if (menu->frame > 13) {
        menu->fade_level = 0;
        gGameSubState--;
    }
}
