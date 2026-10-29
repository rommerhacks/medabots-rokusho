// Mode-2 state 24, started by start_medal_transform from battle/prebattle.c after a won Robattle for each Medal with
// new stats. Sub-states gMedalLevelUpSubStates: decompress the Medal sprite, sparkle sprites, two messages, then back
// to mode 0 state 6 (after-battle). Messages 0x11/0x12: "Wow!!! <Medal>!!! It's transformed into a new shape!",
// so this is the Medal transformation that follows a level-up (new MedalData.spriteVariant of the Medal sprite).
#include "global.h"
#include "constants/sprites.h"

void start_medal_transform(u8 slot) {
    gCurrentMedalSlot = slot;
    gGameMode = 2;
    gGameState = 0x18;
    gGameSubState = 0;
}

static void medal_transform_update_sparkles(void) {
    int i, j, k;
    u16 life;
    struct SpriteEntry *sprite;
    for (i = 0; i < 16; i = j) {
        struct SpriteEntry *base = gSpriteEntries;
        k = i + 1;
        sprite = &base[k];
        life = sprite->timer;
        j = k;
        if (life == 0) {
            sprite->x = 0x78;
            sprite->y = 0x28;
            sprite->pos_x = sprite->x << 8;
            sprite->pos_y = sprite->y << 8;
            sprite->pos_x_frac = rng_next_byte();
            sprite->pos_y_frac = rng_next_byte();
            sprite->timer = 0x3F;
            sprite->scale_x = 0;
            sprite->scale_y = 0;
            sprite->flags &= ~8;
        } else {
            if (--sprite->timer <= 0xF)
                sprite->flags |= SPRITE_OBJ_MODE(1);
            sprite->pos_x += ((s8 *)sprite)[0xC] * 4;
            sprite->pos_y += ((s8 *)sprite)[0x10] * 4;
            sprite->x = sprite->pos_x >> 8;
            sprite->y = sprite->pos_y >> 8;
            sprite->scale_x = 0x40 - (u8)sprite->timer;
            sprite->scale_y = 0x40 - (u8)sprite->timer;
        }
    }
    REG_BLDCNT = 0xC40;
    REG_BLDALPHA = (gMenuWork->counter-- & 0xF) | 0x1000;
    REG_BLDY = 8;
}

void medal_transform_init(void) {
    u16 pal[16] = {0, 0x6FFF, 0x6B7A, 0x66D5, 0x622F, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    u8 slot = gCurrentMedalSlot;
    u32 zero;
    int i;
    u32 size;
    u8 *vram;
    play_song(0x19);
    zero = 0;
    CpuFastSet(&zero, vram = (u8 *)VRAM, 0x01006000);
    clear_battle_sprite_slot(0, 0x80);
    reset_bg_scroll();
    REG_DISPCNT = 0x60;
    REG_BG1CNT = 0x1E05;
    REG_BG2CNT = 0x3D06;
    REG_BG3CNT = 0x1C07;
    decompress_and_write_tilemap(gMedalSceneBg1Tilemap, REG_BG1CNT);
    decompress_and_write_tilemap(gMedalSceneBg2Tilemap, REG_BG2CNT);
    decompress_and_write_tilemap(gMedalSceneBg3Tilemap, REG_BG3CNT);
    size = dma3_copy_or_decompress(gMedalSceneBgTiles, (void *)0x02030000);
    CpuFastSet((void *)0x02030000, (void *)BG_CHAR_ADDR(1), (size << 9) >> 11);
    size = 0x1800;
    gMenuWork->bg_tile_base = 0xC4;
    CpuFastSet(gMedalIconTiles + gMedals[slot].graphicId * 0x80, vram + size, 0x20);
    lz_decompress_dispatch(gSmallDigitTiles, (void *)(size + (BG_VRAM + 0x80)));
    {
        u16 tile = 0x60C0;
        u32 bg = BGCNT_SCREEN_OFFSET(REG_BG0CNT);
        u32 tile_addr = BG_VRAM + 0x286;
        u16 *tile_ptr;
        tile_ptr = (u16 *)(bg + tile_addr);
        *tile_ptr = tile;
        tile_ptr = (u16 *)(bg + (tile_addr + 2));
        *tile_ptr = tile + 1;
        tile_ptr = (u16 *)(bg + (BG_VRAM + 0x2C6));
        *tile_ptr = tile + 2;
        tile_ptr = (u16 *)(bg + (BG_VRAM + 0x2C8));
        *tile_ptr = tile + 3;
    }
    CpuFastSet(gMedalSceneObjPalettes, (void *)0x0202FA00, 0x80);
    CpuFastSet(gSpriteFontPalette, (void *)0x0202F9E0, 8);
    lz_decompress_dispatch(gCommonObjTilesLz, (void *)OBJ_VRAM0);
    CpuFastSet(gCommonObjPalette, (void *)0x0202F800, 8);
    CpuFastSet(gGradientPaletteOlive, (void *)0x0202F820, 8);
    CpuFastSet(gGradientPaletteOlive - 0x20, (void *)0x0202F840, 8);
    CpuFastSet(pal, (void *)0x0202F860, 8);
    lz_decompress_dispatch(gSpriteFontTiles, (void *)(OBJ_VRAM0 + 0x7400));
    for (i = 0; i < 16; i++) {
        gSpriteEntries[i + 1].flags =
            SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(2) | SPRITE_FLAG_AFFINE;
        gSpriteEntries[i + 1].x = 0x78;
        gSpriteEntries[i + 1].y = 0x28;
        gSpriteEntries[i + 1].frame_table = 2;
        gSpriteEntries[i + 1].palette = 3;
        gSpriteEntries[i + 1].frame = 0x117;
        gSpriteEntries[i + 1].scale_x = 0x40;
        gSpriteEntries[i + 1].scale_y = 0x40;
        gSpriteEntries[i + 1].timer = (i & 3) << 4;
    }
    REG_BLDCNT = 0xC40;
    REG_BLDALPHA = 0x1010;
    REG_BLDY = 8;
    gGameSubState++;
}

void medal_transform_draw_medal(void) {
    struct SpriteEntry *sprite;
    u8 zero;
    int i;
    int id, fr;

    id = gMedals[gCurrentMedalSlot].graphicId;
    fr = gMedals[gCurrentMedalSlot].spriteVariant - 1;
    lz_decompress_dispatch(gMedalSpriteGfx[id][fr], (void *)OBJ_VRAM0);
    sprite = gSpriteEntries;
    zero = 0;
    sprite->flags =
        SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(2) | SPRITE_FLAG_AFFINE | SPRITE_FLAG_PART_PALETTE;
    sprite->x = 0x78;
    sprite->y = 0x28;
    sprite->frame = 0x200;
    sprite->palette = zero;
    sprite->frame_table = zero;
    sprite->order = 0x40;
    sprite->scale_x = 0x40;
    sprite->scale_y = 0x40;
    for (i = 0; i < 16; i++) {
        gTextArgBuffer[i] = ((const u8 *)gMedalNames[gMedals[gCurrentMedalSlot].graphicId])[i];
        if (gTextArgBuffer[i] == 0xFE)
            break;
    }
    render_text_sprites_08040DB8(gTextArgBuffer, 0x14, 5, 10, 10, 1, 1, 0);
    if (gMedals[gCurrentMedalSlot].level == 100) {
        *(u16 *)(BGCNT_SCREEN_OFFSET(REG_BG0CNT) + (BG_VRAM + 0x29A)) = (gMenuWork->bg_tile_base + 0x14) | 0x7000;
        *(u16 *)(BGCNT_SCREEN_OFFSET(REG_BG0CNT) + (BG_VRAM + 0x2DA)) = (gMenuWork->bg_tile_base + 0x15) | 0x7000;
        *(u16 *)(BGCNT_SCREEN_OFFSET(REG_BG0CNT) + (BG_VRAM + 0x29C)) = (gMenuWork->bg_tile_base + 0x16) | 0x7000;
        *(u16 *)(BGCNT_SCREEN_OFFSET(REG_BG0CNT) + (BG_VRAM + 0x2DC)) = (gMenuWork->bg_tile_base + 0x17) | 0x7000;
    } else {
        *(u16 *)(BGCNT_SCREEN_OFFSET(REG_BG0CNT) + (BG_VRAM + 0x29A)) =
            (gMenuWork->bg_tile_base + (u8)(gMedals[gCurrentMedalSlot].level / 10u) * 2) | 0x7000;
        *(u16 *)(BGCNT_SCREEN_OFFSET(REG_BG0CNT) + (BG_VRAM + 0x2DA)) =
            (gMenuWork->bg_tile_base + (u8)(gMedals[gCurrentMedalSlot].level / 10u) * 2 + 1) | 0x7000;
        *(u16 *)(BGCNT_SCREEN_OFFSET(REG_BG0CNT) + (BG_VRAM + 0x29C)) =
            (gMenuWork->bg_tile_base + (u8)(gMedals[gCurrentMedalSlot].level % 10u) * 2) | 0x7000;
        *(u16 *)(BGCNT_SCREEN_OFFSET(REG_BG0CNT) + (BG_VRAM + 0x2DC)) =
            (gMenuWork->bg_tile_base + (u8)(gMedals[gCurrentMedalSlot].level % 10u) * 2 + 1) | 0x7000;
    }
    render_text_sprites_08040DB8(gMedals[gCurrentMedalSlot].name, 0x1E, 0x11, 10, 10, 2, 0, 0);
    REG_DISPCNT |= 0x200;
    REG_DISPCNT |= 0x400;
    REG_DISPCNT |= 0x800;
    REG_DISPCNT |= 0x1000;
    gMenuWork->frame = 0;
    gMenuWork->counter = 0;
    gMenuWork->aux = 0;
    gMenuWork->pending_sound = 0;
    gMenuWork->sound_delay = 0;
    gMenuWork->cursor = 0;
    gGameSubState++;
    gGameWork.stepCounter = 0;
}

void medal_transform_fade_in(void) {
    struct GameWork *game;
    u8 *n;
    medal_transform_update_sparkles();
    game = &gGameWork;
    n = &game->stepCounter;
    if (*n <= 8) {
        bg_palettes_blend_masked_now(0, 0x20 - *n * 4, 0xFFFF);
        obj_palettes_blend_masked_now(0, 0x20 - *n * 4, 0xFFFF);
        (*n)++;
    } else {
        text_window_init(1, 2, 0);
        gGameSubState++;
    }
}

void medal_transform_flash_in(void) {
    medal_transform_update_sparkles();
    if (run_message(gSystemMessages[0x11])) {
        int elapsed = (s16)gMenuWork->frame++;
        if (elapsed > 0x77) {
            elapsed -= 0x78;
            if (elapsed <= 0x80)
                obj_palettes_blend_masked_now(0x7FFF, elapsed >> 2, 1);
            else {
                struct MedalData *medals = gMedals;
                struct MedalData *medal = &medals[gCurrentMedalSlot];
                u8 id = medal->graphicId;
                lz_decompress_dispatch(gMedalSpriteGfx[id][medal->spriteVariant], (void *)OBJ_VRAM0);
                gMenuWork->frame = 0;
                gGameSubState++;
            }
        }
    }
}

void medal_transform_flash_out(void) {
    int elapsed;
    medal_transform_update_sparkles();
    elapsed = (s16)gMenuWork->frame++;
    if (elapsed > 0x3B) {
        elapsed -= 0x3C;
        if (elapsed <= 0x80)
            obj_palettes_blend_masked_now(0x7FFF, 0x20 - (elapsed >> 2), 1);
        else {
            message_next();
            gGameSubState++;
        }
    }
}

void medal_transform_wait_confirm(void) {
    medal_transform_update_sparkles();
    if (run_message(gSystemMessages[0x12]) && (KEYS_LO(gNewKeys) & A_BUTTON)) {
        init_blend_effect(gMenuWork->blend, 0, 0, 1, 0xC0);
        gGameSubState++;
    }
}

void medal_transform_exit(void) {
    if (blend_fade_step_08065598(gMenuWork->blend)) {
        gGameMode = 0;
        gGameState = 6;
        gGameSubState = 0x50;
    }
}

void medal_transform_update(void) {
    struct FuncTable7 states = gMedalLevelUpSubStates;
    states.f[gGameSubState]();
    gBg2Scroll.y++;
}
