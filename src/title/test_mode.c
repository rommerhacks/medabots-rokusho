// Mode-2 state 7: the hidden TEST MODE screen (Music / Effect / Erase saved game / Exit).
// test_mode_dispatch runs gTestModeStates: graphics, fades, test_mode_update (menu input, sound test), then the
// erase-save steps (test_mode_erase_save retries save_dispatch(2) through save/save_data.c).
#include "global.h"

static inline void *vram_at(u32 off) {
    return (void *)(0x06004000 + off);
}

void test_mode_dispatch(void) {
    gTestModeStates[gGameSubState]();
    if (gFrameCounter & 1) {
        gBg3Scroll.x++;
        gBg3Scroll.y++;
    }
}

void test_mode_reset(void) {
    u32 zero;

    play_song(0);
    zero = 0;
    CpuFastSet(&zero, (void *)VRAM, 0x01006000);
    reset_bg_scroll();
    clear_battle_sprite_slot(0, 0x80);
    REG_DISPCNT = 0x60;
    REG_BLDCNT = 0x2FF;
    REG_BLDY = 0x10;
    gGameSubState++;
}

void test_mode_load_graphics(void) {
    vu16 *bg1, *bg2, *bg3;
    u16 v;
    u32 size;
    u8 zero;
    u8 i;

    bg1 = &REG_BG1CNT;
    v = 0x1E05;
    *bg1 = v;
    bg2 = &REG_BG2CNT;
    v -= 0xFF;
    *bg2 = v;
    bg3 = &REG_BG3CNT;
    v = 0x3C07;
    *bg3 = v;
    decompress_and_write_tilemap(gUnk_08791694, *bg1);
    decompress_and_write_tilemap(gUnk_087917F4, *bg2);
    decompress_and_write_tilemap(gUnk_087919C4, *bg3);
    size = dma3_copy_or_decompress(gUnk_08790600, gDecompressBuffer);
    CpuCopy16(gDecompressBuffer, vram_at(0), size);
    lz_decompress_dispatch(gUnk_08784CB0, vram_at(size));
    gMenuWork->bg_tile_base = (size >> 5) - 1;
    zero = 0;
    CpuFastSet(gUnk_08790400, (void *)PLTT, 0x80);
    CpuFastSet(gUnk_08483AA0, (void *)(PLTT + 0x1C0), 8);
    lz_decompress_dispatch(gUnk_08784DA4, (void *)0x06010000);
    CpuFastSet(gCursorArrowPalette, (void *)(PLTT + 0x3C0), 8);
    gSpriteEntries[0].unk0 = 0x8000;
    gSpriteEntries[0].unk1C = 2;
    gSpriteEntries[0].unkA = 0xE;
    gSpriteEntries[0].unk6 = 6;
    gMenuWork->cursor = zero;
    gSpriteEntries[0].unk2 = 0x14;
    gSpriteEntries[0].unk4 = gMenuWork->cursor * 16 + 0x20;
    for (i = 0; i <= 1; i++) {
        gSpriteEntries[i + 1].unk0 = 0x8000;
        gSpriteEntries[i + 1].unk1C = 2;
        gSpriteEntries[i + 1].unkA = 0xE;
        gSpriteEntries[i + 1].unk6 = 5;
    }
    gSpriteEntries[1].unk0 |= 0x1000;
    gSpriteEntries[1].unk2 = 0x78;
    gSpriteEntries[1].unk4 = 0x20;
    gSpriteEntries[2].unk2 = 0x90;
    gSpriteEntries[2].unk4 = 0x20;
    for (i = 0; i <= 1; i++) {
        gSpriteEntries[i + 3].unk0 = 0x8000;
        gSpriteEntries[i + 3].unk1C = 2;
        gSpriteEntries[i + 3].unkA = 0xE;
        gSpriteEntries[i + 3].unk6 = 5;
    }
    gSpriteEntries[3].unk0 |= 0x1000;
    gSpriteEntries[3].unk2 = 0x78;
    gSpriteEntries[3].unk4 = 0x30;
    gSpriteEntries[4].unk2 = 0x90;
    gSpriteEntries[4].unk4 = 0x30;
    gGameSubState++;
}

void test_mode_show_screen(void) {
    REG_DISPCNT |= 0x200;
    REG_DISPCNT |= 0x400;
    REG_DISPCNT |= 0x800;
    REG_DISPCNT |= 0x1000;
    gMenuWork->sound_test_song = 0;
    gMenuWork->sound_test_effect = 0;
    draw_number(gMenuWork->sound_test_song, -2, 0x10, 4, 2, (REG_BG1CNT >> 8) & 0x1F);
    draw_number(gMenuWork->sound_test_effect, -3, 0xF, 6, 2, (REG_BG1CNT >> 8) & 0x1F);
    gMenuWork->fade_level = 0x20;
    REG_BLDY = gMenuWork->fade_level >> 1;
    gGameSubState++;
}

void test_mode_fade_in(void) {
    struct MenuWork *p = gMenuWork;

    if (p->fade_level != 0) {
        REG_BLDY = p->fade_level-- >> 1;
    } else {
        p->timer = 0;
        p->fade_level = 0;
        gMenuWork->returning = 0;
        gMenuWork->counter = 0;
        gMenuWork->unk49 = 0;
        gMenuWork->pending_sound = 0;
        gMenuWork->sound_delay = 0;
        gSpriteEntries[0].unk0 |= 0x4000;
        gSpriteEntries[1].unk0 |= 0x4000;
        gGameSubState++;
    }
}

void test_mode_update(void) {
    sprite_bob_y(0, gFrameCounter, 0x14);
    if (gMenuWork->counter != 0) {
        if (--gMenuWork->counter == 0)
            play_sound_effect(2);
    }
    if (KEYS_LO(gRepeatKeys) & 0x40) {
        if (gMenuWork->cursor != 0)
            gMenuWork->cursor--;
        else
            gMenuWork->cursor = 3;
        play_song(0);
        gMenuWork->counter = 2;
    }
    if (KEYS_LO(gRepeatKeys) & 0x80) {
        if (gMenuWork->cursor <= 2)
            gMenuWork->cursor++;
        else
            gMenuWork->cursor = 0;
        play_song(0);
        gMenuWork->counter = 2;
    }
    gSpriteEntries[0].unk4 = gMenuWork->cursor * 16 + 0x20;
    switch (gMenuWork->cursor) {
    case 0:
        if (gFrameCounter & 8) {
            gSpriteEntries[1].unk0 |= 0x4000;
            gSpriteEntries[2].unk0 |= 0x4000;
        } else {
            gSpriteEntries[1].unk0 &= 0xBFFF;
            gSpriteEntries[2].unk0 &= 0xBFFF;
        }
        gSpriteEntries[3].unk0 &= 0xBFFF;
        gSpriteEntries[4].unk0 &= 0xBFFF;
        break;
    case 1:
        gSpriteEntries[1].unk0 &= 0xBFFF;
        gSpriteEntries[2].unk0 &= 0xBFFF;
        if (gFrameCounter & 8) {
            gSpriteEntries[3].unk0 |= 0x4000;
            gSpriteEntries[4].unk0 |= 0x4000;
        } else {
            gSpriteEntries[3].unk0 &= 0xBFFF;
            gSpriteEntries[4].unk0 &= 0xBFFF;
        }
        break;
    default:
        gSpriteEntries[1].unk0 &= 0xBFFF;
        gSpriteEntries[2].unk0 &= 0xBFFF;
        gSpriteEntries[3].unk0 &= 0xBFFF;
        gSpriteEntries[4].unk0 &= 0xBFFF;
        break;
    }
    switch (gMenuWork->cursor) {
    case 0:
        if (KEYS_LO(gRepeatKeys) & 0x20) {
            if (gMenuWork->sound_test_song != 0)
                gMenuWork->sound_test_song--;
            else
                gMenuWork->sound_test_song = 0x33;
            draw_number(gMenuWork->sound_test_song, -2, 0x10, 4, 2, (REG_BG1CNT >> 8) & 0x1F);
        }
        if (KEYS_LO(gRepeatKeys) & 0x10) {
            if (gMenuWork->sound_test_song <= 0x32)
                gMenuWork->sound_test_song++;
            else
                gMenuWork->sound_test_song = 0;
            draw_number(gMenuWork->sound_test_song, -2, 0x10, 4, 2, (REG_BG1CNT >> 8) & 0x1F);
        }
        break;
    case 1:
        if (KEYS_LO(gRepeatKeys) & 0x20) {
            if (gMenuWork->sound_test_effect != 0)
                gMenuWork->sound_test_effect--;
            else
                gMenuWork->sound_test_effect = 0x75;
            draw_number(gMenuWork->sound_test_effect, -3, 0xF, 6, 2, (REG_BG1CNT >> 8) & 0x1F);
        }
        if (KEYS_LO(gRepeatKeys) & 0x10) {
            if (gMenuWork->sound_test_effect <= 0x74)
                gMenuWork->sound_test_effect++;
            else
                gMenuWork->sound_test_effect = 0;
            draw_number(gMenuWork->sound_test_effect, -3, 0xF, 6, 2, (REG_BG1CNT >> 8) & 0x1F);
        }
        break;
    }
    if (gMenuWork->sound_delay != 0)
        gMenuWork->sound_delay--;
    if (gMenuWork->pending_sound != 0 && gMenuWork->sound_delay == 0) {
        play_sound_effect(gMenuWork->pending_sound);
        gMenuWork->pending_sound = 0;
    }
    if (KEYS_LO(gNewKeys) & 1) {
        switch (gMenuWork->cursor) {
        case 0:
            play_song(gSoundTestSongs[gMenuWork->sound_test_song]);
            return;
        case 1:
            gMenuWork->sound_delay = 2;
            gMenuWork->pending_sound = gSoundTestEffects[gMenuWork->sound_test_effect];
            play_song(0);
            play_sound_effect(0);
            return;
        case 2:
            play_sound_effect(4);
            open_choice_menu(1, 0x16, 7);
            text_window_init(1, 2, 0);
            gGameSubState = 6;
            return;
        case 3:
            gMenuWork->unk49 = 0;
            break;
        default:
            return;
        }
    } else if (KEYS_LO(gNewKeys) & 2) {
        gMenuWork->unk49 = 1;
    } else {
        return;
    }
    play_song(0);
    gMenuWork->fade_level = 0;
    gGameSubState = 5;
    gSpriteEntries[0].unk0 &= 0xBFFF;
    gSpriteEntries[1].unk0 &= 0xBFFF;
    gSpriteEntries[2].unk0 &= 0xBFFF;
    gSpriteEntries[3].unk0 &= 0xBFFF;
    gSpriteEntries[4].unk0 &= 0xBFFF;
}

void test_mode_fade_out_exit(void) {
    if (gMenuWork->fade_level == 1)
        play_sound_effect(gMenuWork->unk49 ? 5 : 4);
    if (gMenuWork->fade_level != 32) {
        gMenuWork->fade_level++;
        REG_BLDY = gMenuWork->fade_level >> 1;
    } else {
        REG_DISPCNT &= 0xFDFF;
        gGameMode = 3;
        gGameState = 2;
        gGameSubState = 0;
        gTitleSkipIntro = 1;
    }
}

void test_mode_erase_prompt(void) {
    if (run_message(gUnk_08485788[3]))
        gGameSubState++;
}

void test_mode_erase_choice(void) {
    if (poll_choice_menu()) {
        gMenuWork->timer = 0;
        message_next();
        if (gGameWork.unk2A == 0)
            gGameSubState = 9;
        else
            gGameSubState++;
    }
}

void test_mode_erase_caution(void) {
    if (run_message(gUnk_08485788[16])) {
        if (gMenuWork->timer++ > 60)
            gGameSubState = 13;
    }
}

void test_mode_close_message(void) {
    if (game_state_execute_handler_a())
        gGameSubState = 4;
}

void test_mode_erase_start(void) {
    if (run_message(gUnk_08485788[4])) {
        play_song(0);
        play_sound_effect(0);
        eeprom_setup_timer_irq();
        gMenuWork->timer = 0;
        gGameSubState++;
    }
}

void test_mode_erase_save(void) {
    u8 t = gMenuWork->timer++;
    u16 err = 0;
    s8 i;

    if (t > 29 && !is_sound_effect_playing(4)) {
        for (i = 0; i <= 3; i++) {
            err = save_dispatch(2);
            if (err == 0)
                break;
        }
        if (err == 0) {
            message_next();
            gMenuWork->timer = err;
            gGameSubState++;
        } else {
            message_next();
            gMenuWork->timer = 0;
            gGameSubState = 12;
        }
    }
}

void test_mode_erase_done(void) {
    if (run_message(gUnk_08485788[5])) {
        if (gMenuWork->timer++ > 60)
            gGameSubState = 8;
    }
}

void test_mode_erase_failed(void) {
    if (run_message(gUnk_08485788[6])) {
        if (gMenuWork->timer++ > 60)
            gGameSubState = 8;
    }
}
