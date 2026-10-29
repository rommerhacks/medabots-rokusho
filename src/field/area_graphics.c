// Field area graphics: the full area load (area_load_graphics), animated area BG tiles, the area's OBJ sprite
// sheets (LZ to 0x06010000, 0x900 bytes each) and their palettes keyed by the current area
// (gFieldWork.area_id), the area music (field_update_music), blend presets and sprite-slot setup. Called by
// the field modules, the field / pre-battle menus and the mode-3 scenes.

#include "global.h"
#include "constants/field_sprites.h"

void area_load_graphics(void) {
    gBg1Scroll.x = gFieldState.saved_bg1_x;
    gBg1Scroll.y = gFieldState.saved_bg1_y;
    gBg2Scroll.x = gFieldState.saved_bg2_x;
    gBg2Scroll.y = gFieldState.saved_bg2_y;
    gBg3Scroll.x = gFieldState.saved_bg3_x;
    gBg3Scroll.y = gFieldState.saved_bg3_y;
    area_load_bg_palettes();
    area_load_sprite_palettes();
    load_room_graphics();
    gFieldWork.bg_anim_timer = 0;
    animate_area_bg_tiles();
    load_map_npc_sprites(gFieldWork.npc_load_mode);
    update_entity_sprites_on_screen();
    init_battle_field_setup();
    update_bg_scroll_offsets_a();
    follower_respawn();
    follower_update_screen_pos();
    area_load_sprite_sheets();
    gFieldWork.depth_sort_enabled = 1;
    field_sort_sprites_by_depth();
}

void animate_area_bg_tiles(void) {
    const u8 *anim = gAreaTileAnims[gFieldWork.area_id];
    u8 n = anim[0];
    u8 *src;

    if (gFieldWork.bg_anim_enabled != 0 && anim[2] != 0) {
        if (gFieldWork.bg_anim_timer != 0) {
            gFieldWork.bg_anim_timer--;
        } else {
            if (anim[gFieldWork.bg_anim_frame + 3] == 0xFF)
                gFieldWork.bg_anim_frame = 0;
            src = gAreaAnimTileSrc + anim[gFieldWork.bg_anim_frame + 3] * n * 32;
            DmaSet(3, src, BG_VRAM + 0x9020, 0x80000000 | (n << 4));
            gFieldWork.bg_anim_frame++;
            gFieldWork.bg_anim_timer = 2;
        }
    }
}

// Sheet id 0 = the default for gFieldWork.player_form, 0xD0-0xFE = a variant picked by state, 0xFF = end.
s32 resolve_sprite_sheet_id(s32 sheet_id) {
    s32 gender_base;
    if (sheet_id == 0)
        sheet_id = gPlayerFormSpriteSheets[gFieldWork.player_form];
    else if (sheet_id <= 0xAF)
        ;
    else if (sheet_id <= 0xBF)
        ;
    else if (sheet_id <= 0xCF)
        ;
    else if (sheet_id <= 0xFE) {
        const u8 *tbl = gSpriteSheetVariantTables[sheet_id - 0xD0];
        sheet_id = tbl[gFieldWork.sheet_variants[sheet_id - 0xD0]];
    } else
        sheet_id = 0xFF;
    if (sheet_id != 0xFF && sheet_id > 0xBF)
        sheet_id = (sheet_id - 0xC0) * 2 + (gender_base = gFieldSceneParams.bot_gender + 0x28);
    return sheet_id;
}

void area_load_sprite_sheets(void) {
    s32 i = 0;
    u8 *dst = (u8 *)OBJ_VRAM0;
    u32 sheet_id;

    while ((sheet_id = area_sprite_sheet_id(i)) != 0xFF) {
        if (gFieldSpriteTiles[sheet_id] == NULL)
            sheet_id = 1;
        LZ77UnCompVram(gFieldSpriteTiles[sheet_id], dst);
        dst += 0x900;
        i++;
    }
}

// Loads one sheet into all 12 sheet slots.
void fill_sprite_sheets(s32 sheet_code) {
    s32 i;
    u8 *dst;
    const u8 *const *tbl;
    s32 sheet_id = resolve_sprite_sheet_id(sheet_code);

    tbl = gFieldSpriteTiles;
    dst = (u8 *)OBJ_VRAM0;
    for (i = 11; i >= 0; i--) {
        if (tbl[sheet_id] == NULL)
            sheet_id = 1;
        LZ77UnCompVram(tbl[sheet_id], dst);
        dst += 0x900;
    }
}

// guess: BG palettes (13 palettes into the buffer at 0x0202FA00, or a default set).
void area_load_bg_palettes(void) {
    const u16 *pal = gAreaBgPalettes[gFieldWork.area_id];

    if (pal != NULL) {
        DmaSet(3, pal, BG_PAL_BACKUP_ADDR(0), 0x84000068);
    } else {
        DmaSet(3, gFallbackAreaPalette0, BG_PAL_BACKUP_ADDR(0), 0x84000008);
        DmaSet(3, gFallbackAreaPalette1, BG_PAL_BACKUP_ADDR(1), 0x84000008);
        DmaSet(3, gFallbackAreaPalette2, BG_PAL_BACKUP_ADDR(2), 0x84000008);
        DmaSet(3, gFallbackAreaPalette3, BG_PAL_BACKUP_ADDR(3), 0x84000008);
        DmaSet(3, gFallbackAreaPalette0, BG_PAL_BACKUP_ADDR(4), 0x84000008);
        DmaSet(3, gFallbackAreaPalette0, BG_PAL_BACKUP_ADDR(5), 0x84000008);
        DmaSet(3, gFallbackAreaPalette0, BG_PAL_BACKUP_ADDR(6), 0x84000008);
        DmaSet(3, gFallbackAreaPalette4, BG_PAL_BACKUP_ADDR(7), 0x84000008);
        DmaSet(3, gFallbackAreaPalette5, BG_PAL_BACKUP_ADDR(8), 0x84000008);
    }
}

// The area's song (gAreaSongs), or the script override in script_song while song is 0xFF.
u8 area_song_id(void) {
    if (gFieldWork.song == 0xFF)
        return gFieldWork.script_song;
    return gAreaSongs[gFieldWork.area_id];
}

// area_song_id returns its u8 widened: the original uses r0 untruncated here.
#define area_song_id() ((u32(*)(void))area_song_id)()

// Starts / keeps / overrides the field song (song = song playing) for an event code.
u32 field_update_music(u32 event, u32 song) {
    u32 prev_song;
    u32 area_song;
    u32 table_song;

    switch (event) {
    case 0:
    case 10:
    case 12:
        if (gFieldWork.song != 0xFF) {
            area_song = area_song_id();
            if (gFieldWork.song != area_song) {
                gFieldWork.song = area_song;
                field_play_song(area_song);
            }
        }
        break;
    case 1:
        gFieldWork.song = song;
        field_play_song(song);
        break;
    case 2:
        gFieldWork.song = 0;
        field_play_song(0);
        break;
    case 3:
        if (gFieldWork.song == 0xFF) {
            if (song & 0x80) {
                gFieldWork.script_song = song & 0x7F;
                gFieldWork.song |= 0xFF;
            }
            break;
        }
        if (!(song & 0x80)) {
            gFieldWork.script_song = song & 0x7F;
            field_play_song(song);
            gFieldWork.song = 0xFF;
            break;
        }
        gFieldWork.script_song = song & 0x7F;
        gFieldWork.song |= 0xFF;
        break;
    case 4:
        prev_song = gFieldWork.song;
        gFieldWork.song = 0;
        area_song = area_song_id();
        if (prev_song != area_song) {
            gFieldWork.song = area_song;
            field_play_song(area_song);
        } else
            gFieldWork.song = area_song;
        break;
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 19:
    case 28:
        area_song = area_song_id();
        gFieldWork.song = area_song;
        field_play_song(area_song);
        break;
    case 11:
    case 13:
    case 14:
    case 15:
    case 21:
    case 22:
    case 26:
        if (gFieldWork.song != 0xFF) {
            area_song = area_song_id();
            gFieldWork.song = area_song;
            field_play_song(area_song);
        } else
            field_play_song(gFieldWork.script_song);
        break;
    case 23:
        if (gEventPictureSongs[gFieldSceneParams.event_picture_id * 4])
            field_stop_songs(0x1E);
        break;
    case 24:
        if (gEventPictureSongs[gFieldSceneParams.event_picture_id * 4]) {
            table_song = gEventPictureSongs[gFieldSceneParams.event_picture_id * 4 + 1];
            gFieldWork.song = table_song;
            field_play_song(table_song);
        }
        break;
    case 25:
        switch (gEventPictureSongs[gFieldSceneParams.event_picture_id * 4 + 2]) {
        case 1:
            table_song = gEventPictureSongs[gFieldSceneParams.event_picture_id * 4 + 3];
            gFieldWork.song = table_song;
            field_play_song(table_song);
            break;
        case 2:
            table_song = area_song_id();
            gFieldWork.song = table_song;
            field_play_song(table_song);
            break;
        }
        break;
    }
}

#undef area_song_id

u32 area_sprite_sheet_id(u32 slot) {
    return resolve_sprite_sheet_id(gAreaSpriteSheetIds[gFieldWork.area_id][slot]);
}

void area_load_sprite_palettes_now(void) {
    s32 i;
    u32 sheet_id;

    for (i = 0; (sheet_id = area_sprite_sheet_id(i)) != 0xFF; i++) {
        sheet_id = area_sprite_sheet_id(i);
        if (gFieldSpritePalettes[sheet_id] == NULL)
            sheet_id = 1;
        DmaSet(3, gFieldSpritePalettes[sheet_id], 0x05000200 + i * 0x20, 0x84000008);
    }
}

void area_load_sprite_palettes(void) {
    s32 i;
    u32 sheet_id;

    for (i = 0; (sheet_id = area_sprite_sheet_id(i)) != 0xFF; i++) {
        sheet_id = area_sprite_sheet_id(i);
        if (gFieldSpritePalettes[sheet_id] == NULL)
            sheet_id = 1;
        DmaSet(3, gFieldSpritePalettes[sheet_id], OBJ_PAL_BACKUP_ADDR(0) + i * 0x20, 0x84000008);
    }
    DmaSet(3, gFieldSharedSpritePalette, OBJ_PAL_BACKUP_ADDR(14), 0x84000008);
}

void fill_sprite_palettes(s32 sheet_code) {
    s32 i = 0;
    s32 sheet_id = resolve_sprite_sheet_id(sheet_code);

    for (; i <= 11; i++) {
        if (gFieldSpritePalettes[sheet_id] == NULL)
            sheet_id = 1;
        DmaSet(3, gFieldSpritePalettes[sheet_id], 0x05000200 + i * 0x20, 0x84000008);
    }
}

// Sets the sprite draw order (0xFF / 0 / 0x40) from its sheet's blend kind,
// gSpriteSheetBlendKinds[work16[FIELD_SPR_SHEET]].
void sprite_set_blend_from_kind(u8 idx) {
    u8 blend_kind = gSpriteSheetBlendKinds[gSpriteEntries[idx].work16[FIELD_SPR_SHEET]];

    if (blend_kind == 2)
        gSpriteEntries[idx].order = 0xFF;
    else if (blend_kind == 1)
        gSpriteEntries[idx].order = 0;
    else
        gSpriteEntries[idx].order = 0x40;
}

static void blend_set_alpha_12_8(void) {
    vu16 *bldalpha;
    u16 value;

    REG_BLDCNT = 0x1F41;
    gBlendEffect.eva_level = 12.0f;
    gBlendEffect.evb_level = 8.0f;
    bldalpha = &REG_BLDALPHA;
    value = 0x80C;
    *bldalpha = value;
}

void blend_set_alpha_12_10(void) {
    vu16 *bldalpha;
    u16 value;

    REG_BLDCNT = 0xF40;
    gBlendEffect.eva_level = 12.0f;
    gBlendEffect.evb_level = 10.0f;
    bldalpha = &REG_BLDALPHA;
    value = 0xA0C;
    *bldalpha = value;
}

void sprite_entry_init(u8 slot, u16 flags, u32 frame, u8 palette, u8 frame_table) {
    gSpriteEntries[slot].flags = flags;
    gSpriteEntries[slot].work16[FIELD_SPR_FLAGS] = flags;
    gSpriteEntries[slot].frame = frame;
    gSpriteEntries[slot].palette = palette;
    gSpriteEntries[slot].frame_table = frame_table;
}

void sprite_entry_clear(u8 slot) {
    memzero_bytes((u8 *)&gSpriteEntries[slot], 0x40);
    clear_entity_state(slot);
}
