// Helpers shared by the mode-2 (title-side) screens: the eight-sprite wave effect, sprite priority flags,
// decompress_and_write_tilemap (used by nearly every mode-2 screen and the link scenes), tilemap tile /
// palette offsets, init_multiplayer_id and small geometry helpers. Talks to engine/ and link/.
#include "global.h"
#include "constants/sprites.h"

// Eight sprites (spr[0..7]) bob on a sine wave around y = 80: sprite k uses phase t - (7 - k) * 0x80,
// amplitude gMenuWork->shake_amplitude (counts down each call), speed shake_speed (counts up). Returns 1 once the
// amplitude is 0. The divide by d (not a constant) keeps the __divsi3 call of the original.
#define WAVE_X(a) (gSineTableQ14[(a) & 0x3FF] / divisor * amp >> 3)
#define SET_WAVE_Y(k, a)                                                                                               \
    if (gSineTableQ14[(a) & 0x3FF] < 0)                                                                                \
        spr[k].y = WAVE_X(a) + mid;                                                                                    \
    else                                                                                                               \
        spr[k].y = mid - WAVE_X(a)

static u32 sprite_wave_bob8(struct SpriteEntry *spr) {
    u32 done = 0;
    s32 divisor = 0x400;
    s32 mid = 80;
    u8 amp = gMenuWork->shake_amplitude;
    u8 speed = gMenuWork->shake_speed;
    s32 ph[8];

    ph[0] = gMenuWork->timer++ * speed;
    ph[1] = ph[0] - 0x80;
    ph[2] = ph[0] - 0x100;
    ph[3] = ph[0] - 0x180;
    ph[4] = ph[0] - 0x200;
    ph[5] = ph[0] - 0x280;
    ph[6] = ph[0] - 0x300;
    ph[7] = ph[0] - 0x380;

    if (gSineTableQ14[ph[7] & 0x3FF] < 0)
        spr[0].y = WAVE_X(ph[7]) + mid;
    else
        spr[0].y = -WAVE_X(ph[7]) + mid;
    SET_WAVE_Y(1, ph[6]);
    SET_WAVE_Y(2, ph[5]);
    SET_WAVE_Y(3, ph[4]);
    SET_WAVE_Y(4, ph[3]);
    SET_WAVE_Y(5, ph[2]);
    SET_WAVE_Y(6, ph[1]);
    SET_WAVE_Y(7, ph[0]);
    if (gMenuWork->shake_amplitude == 0)
        done = 1;
    else {
        gMenuWork->shake_amplitude--;
        gMenuWork->shake_speed++;
    }
    return done;
}

// D-pad moves the town map cursor (unk17) through the neighbour table of the current map; returns 1 on a press.
u32 town_map_move_cursor(void) {
    struct MenuWork **pw = &gMenuWork;
    struct MenuWork *w = *pw;
    u8 old = w->town_map_place;
    u32 off = old * 4 + gFieldWork.town_map_phase * 40;
    const u8 *tbl = w->cursor_style ? gTownMapNeighboursAlt : gTownMapNeighbours;
    if (*(u8 *)&gNewKeys & 0x20)
        w->town_map_place = tbl[off];
    else if (*(u8 *)&gNewKeys & 0x10)
        w->town_map_place = tbl[off + 1];
    else if (*(u8 *)&gNewKeys & 0x40)
        w->town_map_place = tbl[off + 2];
    else if (*(u8 *)&gNewKeys & 0x80)
        w->town_map_place = tbl[off + 3];
    else
        goto none;
    play_sound_effect(old != (*pw)->town_map_place ? 2 : 6);
    return 1;
none:
    return 0;
}

void update_battle_sprite_priority_flags(void) {
    if (gMenuWork->list_count > 4) {
        if ((*(u8 *)0x02023078) == 0)
            gSpriteEntries[104].flags &= (u16)~SPRITE_FLAG_VISIBLE;
        else if (gFrameCounter & 8)
            gSpriteEntries[104].flags |= SPRITE_FLAG_VISIBLE;
        else
            gSpriteEntries[104].flags &= (u16)~SPRITE_FLAG_VISIBLE;
        if ((*(u8 *)0x02023078) + 3 == gMenuWork->list_count - 1)
            gSpriteEntries[105].flags &= (u16)~SPRITE_FLAG_VISIBLE;
        else if (gFrameCounter & 8)
            gSpriteEntries[105].flags |= SPRITE_FLAG_VISIBLE;
        else
            gSpriteEntries[105].flags &= (u16)~SPRITE_FLAG_VISIBLE;
    }
}

void decompress_and_write_tilemap(const void *src, u32 bgcnt) {
    s32 w, h, x, y, cols;
    u16 *data, *dst;

    LZ77UnCompWram(src, gDecompressBuffer);
    w = *(u32 *)gDecompressBuffer;
    h = *(u32 *)0x02030004;
    data = (u16 *)(gDecompressBuffer + 0x10);
    dst = (u16 *)(((bgcnt >> 8) & 0x1F) * 0x800 + VRAM);
    cols = (((bgcnt & 0xC000) >> 14) & 1) ? 64 : 32;
    for (y = 0; y < h; y++) {
        for (x = 0; x < cols; x++) {
            if (x < w)
                *dst = *data++;
            dst++;
        }
    }
}

void tilemap_offset_tiles_and_palette(u32 tiles, u32 palette, u32 blk) {
    u16 add = tiles;
    // pinned so pal << 12 stays inside the loop (the original recomputes it every tile)
    register u32 pal asm("r6") = (u8)palette;
    u8 block = blk;
    u16 *tile_ptr = (u16 *)(VRAM + block * 0x800);
    s32 i;

    for (i = 0; i < 0x400; i++) {
        u32 h;
        u32 x = *tile_ptr;
        u32 tile = (((x & 0x3FF) + add) & 0x3FF) | (x & 0xFC00);
        s32 mask = 0xF000;

        x = pal;
        h = (tile & mask) + (x << 12);
        *tile_ptr = (tile & 0xFFF) | h;
        tile_ptr++;
    }
}

void init_multiplayer_id(void) {
    u8 buf[4];
    memcpy_optimized(buf, gMultiplayerIdUnusedBytes, 4);
    gLinkPlayerId = (*(vu32 *)0x04000128 << 26) >> 30;
}

// guess: link play uses a key word received over the link; new / released keys from it (no callers).
void keys_update_from(u16 keys) {
    u16 *newKeys = &gNewKeys;
    u16 *prev = &gMenuWork->prev_keys;
    *newKeys = keys & ~*prev;
    gReleasedKeys = *prev & ~keys;
    *prev = keys;
}

static void link_poll_keys(void) {
    if (gLinkMultiplayerActive != 0) {
        if (gLinkPlayerId)
            keys_update_from(gLinkPackets.recv[0][0]);
        else {
            register struct LinkPackets *packets asm("r0") = &gLinkPackets;
            packets->sendKeys = gHeldKeys;
            keys_update_from(packets->recv[0][0]);
        }
    }
}

static u16 point_distance(s16 from_x, s16 from_y, s16 to_x, s16 to_y) {
    s32 dx = to_x - from_x;
    s32 dy = to_y - from_y;
    return Sqrt(dx * dx + dy * dy);
}
