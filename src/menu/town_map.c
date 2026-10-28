// Mode-2 state 10: the Town Map. town_map_dispatch runs gTownMapStates (graphics, then cursor states that
// call town_map_update_cursor / town_map_animate_tiles, the two helpers at the top of the file).
#include "global.h"
#include "constants/sprites.h"

void town_map_update_cursor(void) {
    u8 row = gMenuWork->cursor_style;
    const u8 *t;

    if (++gSpriteEntries[0].unk1A > 0x60)
        gSpriteEntries[0].unk1A = 0;
    t = (const u8 *)gTownMapPlacePositions;
    gSpriteEntries[0].x =
        t[gMenuWork->town_map_place * 2] * 8 + gTownMapCursorOffsetX[row][(gSpriteEntries[0].unk1A >> 3) & 3];
    gSpriteEntries[0].y = t[(u16)(gMenuWork->town_map_place * 2 + 1)] * 8 +
                          gTownMapCursorOffsetY[row][(gSpriteEntries[0].unk1A >> 3) & 3];
    gSpriteEntries[0].frame = gTownMapCursorFrames[row][(gSpriteEntries[0].unk1A >> 3) & 3];
}

void town_map_animate_tiles(void) {
    s32 t;

    if ((u16)++gMenuWork->frame > 0x6D)
        gMenuWork->frame = 0;
    t = gMenuWork->frame;
    if ((s16)(t % 10) == 0)
        CpuSet(gDecompressBuffer + (gTownMapAnimFrameOrder[(s16)(t / 10)] + 1) * 480, (void *)0x06004020, 0xF0);
}

void town_map_dispatch(void) {
    gTownMapStates[gGameSubState]();
}

void town_map_save_bg2_and_reset(void) {
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
    struct MenuWork *p;

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
    decompress_and_write_tilemap(gTownMapBg1Tilemap, *bg1);
    decompress_and_write_tilemap(gTownMapBg2Tilemap, *bg2);
    decompress_and_write_tilemap(gTownMapBg3Tilemap, *bg3);
    {
        struct MenuWork *q;
        if (gGameState == 0x17) {
            q = gMenuWork;
            q->cursor_style = 1;
        } else {
            *(u16 *)(((*bg3 >> 8) & 0x1F) * 0x800 + (VRAM + 0x248)) =
                *(u16 *)(((*bg3 >> 8) & 0x1F) * 0x800 + (VRAM + 0x21E));
            q = gMenuWork;
            q->cursor_style = 0;
        }
    }
    switch (gFieldWork.town_map_phase) {
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
    size = dma3_copy_or_decompress(gTownMapBgTiles, gDecompressBuffer);
    CpuFastSet(gDecompressBuffer, (void *)(VRAM + off), (size / 4) & 0x1FFFFF);
    lz_decompress_dispatch(gMenuDigitTilesLz, (void *)(VRAM + off + size));
    gMenuWork->bg_tile_base = size / 32 - 1;
    CpuFastSet(gTownMapBgPalettes, (void *)PLTT, 0x70);
    lz_decompress_dispatch(gCommonObjTilesLz, (void *)0x06010000);
    CpuFastSet(gTownMapObjPalettes, (void *)(PLTT + 0x200), 0x18);
    gMenuWork->town_map_place = gAreaTownMapPlace[gFieldWork.area_id];
    gSpriteEntries[0].flags = SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE;
    gSpriteEntries[0].frame_table = 2;
    gSpriteEntries[0].y = 0x3C;
    p = gMenuWork;
    gSpriteEntries[0].palette = p->cursor_style;
    gSpriteEntries[0].frame = 0x10D;
    gSpriteEntries[0].unk1A = 0;
    gSpriteEntries[1].flags = SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE;
    gSpriteEntries[1].frame_table = 2;
    gSpriteEntries[1].x = gTownMapPlacePositions[0][p->town_map_place * 2] * 8;
    gSpriteEntries[1].y = gTownMapPlacePositions[0][p->town_map_place * 2 + 1] * 8;
    gSpriteEntries[1].palette = 2;
    gSpriteEntries[1].frame = 0x10E;
    gSpriteEntries[0].x = gTownMapPlacePositions[0][p->town_map_place * 2] * 8;
    gSpriteEntries[0].y = gTownMapPlacePositions[0][p->town_map_place * 2 + 1] * 8;
    dma3_copy_or_decompress(gTownMapAnimTiles, (void *)0x020301E0);
    gGameSubState++;
}

void town_map_enable_layers(void) {
    REG_DISPCNT |= 0x200;
    REG_DISPCNT |= 0x400;
    REG_DISPCNT |= 0x800;
    REG_DISPCNT |= 0x1000;
    gMenuWork->fade_level = 8;
    REG_BLDY = gMenuWork->fade_level * 2;
    gMenuWork->frame = 0;
    gGameSubState++;
}

void town_map_fade_in(void) {
    struct MenuWork *p = gMenuWork;

    if (p->fade_level != 0) {
        REG_BLDY = --p->fade_level * 2;
    } else {
        p->timer = 0;
        text_window_init(1, 2, 0);
        gGameSubState++;
    }
    town_map_update_cursor();
    town_map_animate_tiles();
}

void town_map_show_place_name(void) {
    u8 i = gMenuWork->town_map_place;
    if (run_message(gTownMapPlaceNames[i]))
        gGameSubState++;
    town_map_update_cursor();
    town_map_animate_tiles();
}

void town_map_handle_input(void) {
    u8 keys;

    town_map_update_cursor();
    town_map_animate_tiles();
    if (town_map_move_cursor() == 0) {
        if (!((keys = KEYS_LO(gNewKeys)) & 3))
            return;
        if (gGameState == 10) {
            play_sound_effect(5);
            gMenuWork->counter = 1;
        } else if (keys & 1) {
            play_sound_effect(4);
            gMenuWork->counter = 1;
        } else {
            play_sound_effect(5);
            gMenuWork->counter = 0;
        }
        gMenuWork->fade_level = 0;
        gGameSubState++;
    } else {
        message_next();
        gGameSubState = 4;
    }
}

void town_map_close_message(void) {
    town_map_update_cursor();
    town_map_animate_tiles();
    if (game_state_execute_handler_a()) {
        palette_backup_from_hardware();
        gGameWork.stepCounter = 0;
        gGameSubState++;
    }
}

void town_map_fade_out_exit(void) {
    struct GameWork *s;
    u8 *n;

    town_map_update_cursor();
    town_map_animate_tiles();
    s = &gGameWork;
    n = &s->stepCounter;
    if (*n <= 8) {
        bg_palettes_blend_masked_now(0, *n * 4, 0xFFFF);
        obj_palettes_blend_masked_now(0, *n * 4, 0xFFFF);
        (*n)++;
    } else {
        REG_DISPCNT &= 0xFDFF;
        REG_DISPCNT &= 0xFEFF;
        CpuFastSet((void *)0x02020800, (void *)0x06002800, 0x28);
        if (gGameState == 10) {
            gGameState = 4;
            gGameSubState = 0;
        } else if (gMenuWork->counter) {
            gFieldSceneParams.town_map_place = gMenuWork->town_map_place;
            dispatch_by_index_0476e8(5);
        } else {
            dispatch_by_index_0476e8(6);
        }
    }
}
