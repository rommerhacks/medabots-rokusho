// Mode-2 state 24, started by start_medal_transform from battle/prebattle.c after a won Robattle for each Medal with
// new stats. Sub-states gMedalLevelUpSubStates: decompress the Medal sprite, sparkle sprites, two messages, then back
// to mode 0 state 6 (after-battle). Messages 0x11/0x12: "Wow!!! <Medal>!!! It's transformed into a new shape!",
// so this is the Medal transformation that follows a level-up (new variant unk8 of the Medal sprite).
#include "global.h"

void start_medal_transform(u8 slot) {
    gCurrentMedalSlot = slot;
    gGameMode = 2;
    gGameState = 0x18;
    gGameSubState = 0;
}

static void medal_transform_update_sparkles(void) {
    int i, j, k;
    u16 t;
    struct SpriteEntry *s;
    for (i = 0; i < 16; i = j) {
        struct SpriteEntry *base = gSpriteEntries;
        k = i + 1;
        s = &base[k];
        t = s->unk1A;
        j = k;
        if (t == 0) {
            s->unk2 = 0x78;
            s->unk4 = 0x28;
            s->unkC_8 = s->unk2 << 8;
            s->unk10_8 = s->unk4 << 8;
            s->unkC_0 = rng_next_byte();
            s->unk10_0 = rng_next_byte();
            s->unk1A = 0x3F;
            s->unk8 = 0;
            s->unk9 = 0;
            s->unk0 &= ~8;
        } else {
            if (--s->unk1A <= 0xF)
                s->unk0 |= 8;
            s->unkC_8 += ((s8 *)s)[0xC] * 4;
            s->unk10_8 += ((s8 *)s)[0x10] * 4;
            s->unk2 = s->unkC_8 >> 8;
            s->unk4 = s->unk10_8 >> 8;
            s->unk8 = 0x40 - (u8)s->unk1A;
            s->unk9 = 0x40 - (u8)s->unk1A;
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
    CpuFastSet((void *)0x02030000, (void *)0x06004000, (size << 9) >> 11);
    size = 0x1800;
    gMenuWork->bg_tile_base = 0xC4;
    CpuFastSet(gMedalIconTiles + gMedals[slot].graphicId * 0x80, vram + size, 0x20);
    lz_decompress_dispatch(gSmallDigitTiles, (void *)(size + 0x06000080));
    {
        u16 t = 0x60C0;
        u32 bg = ((REG_BG0CNT >> 8) & 0x1F) * 0x800;
        u32 a = 0x06000286;
        u16 *d;
        d = (u16 *)(bg + a);
        *d = t;
        d = (u16 *)(bg + (a + 2));
        *d = t + 1;
        d = (u16 *)(bg + 0x060002C6);
        *d = t + 2;
        d = (u16 *)(bg + 0x060002C8);
        *d = t + 3;
    }
    CpuFastSet(gMedalSceneObjPalettes, (void *)0x0202FA00, 0x80);
    CpuFastSet(gSpriteFontPalette, (void *)0x0202F9E0, 8);
    lz_decompress_dispatch(gCommonObjTilesLz, (void *)0x06010000);
    CpuFastSet(gCommonObjPalette, (void *)0x0202F800, 8);
    CpuFastSet(gGradientPaletteOlive, (void *)0x0202F820, 8);
    CpuFastSet(gGradientPaletteOlive - 0x20, (void *)0x0202F840, 8);
    CpuFastSet(pal, (void *)0x0202F860, 8);
    lz_decompress_dispatch(gSpriteFontTiles, (void *)0x06017400);
    for (i = 0; i < 16; i++) {
        gSpriteEntries[i + 1].unk0 = 0xCA00;
        gSpriteEntries[i + 1].unk2 = 0x78;
        gSpriteEntries[i + 1].unk4 = 0x28;
        gSpriteEntries[i + 1].unk1C = 2;
        gSpriteEntries[i + 1].unkA = 3;
        gSpriteEntries[i + 1].unk6 = 0x117;
        gSpriteEntries[i + 1].unk8 = 0x40;
        gSpriteEntries[i + 1].unk9 = 0x40;
        gSpriteEntries[i + 1].unk1A = (i & 3) << 4;
    }
    REG_BLDCNT = 0xC40;
    REG_BLDALPHA = 0x1010;
    REG_BLDY = 8;
    gGameSubState++;
}

void medal_transform_draw_medal(void) {
    struct SpriteEntry *s;
    u8 zero;
    int i;
    int id, fr;

    id = gMedals[gCurrentMedalSlot].graphicId;
    fr = gMedals[gCurrentMedalSlot].spriteVariant - 1;
    lz_decompress_dispatch(gMedalSpriteGfx[id][fr], (void *)0x06010000);
    s = gSpriteEntries;
    zero = 0;
    s->unk0 = 0xCA04;
    s->unk2 = 0x78;
    s->unk4 = 0x28;
    s->unk6 = 0x200;
    s->unkA = zero;
    s->unk1C = zero;
    s->unkB = 0x40;
    s->unk8 = 0x40;
    s->unk9 = 0x40;
    for (i = 0; i < 16; i++) {
        gTextArgBuffer[i] = ((const u8 *)gMedalNames[gMedals[gCurrentMedalSlot].graphicId])[i];
        if (gTextArgBuffer[i] == 0xFE)
            break;
    }
    render_text_sprites_08040DB8(gTextArgBuffer, 0x14, 5, 10, 10, 1, 1, 0);
    if (gMedals[gCurrentMedalSlot].level == 100) {
        *(u16 *)(((REG_BG0CNT >> 8) & 0x1F) * 0x800 + 0x0600029A) = (gMenuWork->bg_tile_base + 0x14) | 0x7000;
        *(u16 *)(((REG_BG0CNT >> 8) & 0x1F) * 0x800 + 0x060002DA) = (gMenuWork->bg_tile_base + 0x15) | 0x7000;
        *(u16 *)(((REG_BG0CNT >> 8) & 0x1F) * 0x800 + 0x0600029C) = (gMenuWork->bg_tile_base + 0x16) | 0x7000;
        *(u16 *)(((REG_BG0CNT >> 8) & 0x1F) * 0x800 + 0x060002DC) = (gMenuWork->bg_tile_base + 0x17) | 0x7000;
    } else {
        *(u16 *)(((REG_BG0CNT >> 8) & 0x1F) * 0x800 + 0x0600029A) =
            (gMenuWork->bg_tile_base + (u8)(gMedals[gCurrentMedalSlot].level / 10u) * 2) | 0x7000;
        *(u16 *)(((REG_BG0CNT >> 8) & 0x1F) * 0x800 + 0x060002DA) =
            (gMenuWork->bg_tile_base + (u8)(gMedals[gCurrentMedalSlot].level / 10u) * 2 + 1) | 0x7000;
        *(u16 *)(((REG_BG0CNT >> 8) & 0x1F) * 0x800 + 0x0600029C) =
            (gMenuWork->bg_tile_base + (u8)(gMedals[gCurrentMedalSlot].level % 10u) * 2) | 0x7000;
        *(u16 *)(((REG_BG0CNT >> 8) & 0x1F) * 0x800 + 0x060002DC) =
            (gMenuWork->bg_tile_base + (u8)(gMedals[gCurrentMedalSlot].level % 10u) * 2 + 1) | 0x7000;
    }
    render_text_sprites_08040DB8(gMedals[gCurrentMedalSlot].name, 0x1E, 0x11, 10, 10, 2, 0, 0);
    REG_DISPCNT |= 0x200;
    REG_DISPCNT |= 0x400;
    REG_DISPCNT |= 0x800;
    REG_DISPCNT |= 0x1000;
    gMenuWork->frame = 0;
    gMenuWork->counter = 0;
    gMenuWork->unk49 = 0;
    gMenuWork->pending_sound = 0;
    gMenuWork->sound_delay = 0;
    gMenuWork->cursor = 0;
    gGameSubState++;
    gGameWork.unk84 = 0;
}

void medal_transform_fade_in(void) {
    struct GameWork *s;
    u8 *n;
    medal_transform_update_sparkles();
    s = &gGameWork;
    n = &s->unk84;
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
        int t = (s16)gMenuWork->frame++;
        if (t > 0x77) {
            t -= 0x78;
            if (t <= 0x80)
                obj_palettes_blend_masked_now(0x7FFF, t >> 2, 1);
            else {
                struct MedalData *b = gMedals;
                struct MedalData *m = &b[gCurrentMedalSlot];
                u8 id = m->graphicId;
                lz_decompress_dispatch(gMedalSpriteGfx[id][m->spriteVariant], (void *)0x06010000);
                gMenuWork->frame = 0;
                gGameSubState++;
            }
        }
    }
}

void medal_transform_flash_out(void) {
    int t;
    medal_transform_update_sparkles();
    t = (s16)gMenuWork->frame++;
    if (t > 0x3B) {
        t -= 0x3C;
        if (t <= 0x80)
            obj_palettes_blend_masked_now(0x7FFF, 0x20 - (t >> 2), 1);
        else {
            message_next();
            gGameSubState++;
        }
    }
}

void medal_transform_wait_confirm(void) {
    medal_transform_update_sparkles();
    if (run_message(gSystemMessages[0x12]) && (*(u8 *)&gNewKeys & 1)) {
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
    struct FuncTable7 t = gMedalLevelUpSubStates;
    t.f[gGameSubState]();
    gBg2Scroll.y++;
}
