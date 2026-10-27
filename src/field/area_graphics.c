// Field area graphics: the full area load (area_load_graphics), animated area BG tiles, the area's OBJ sprite
// sheets (LZ to 0x06010000, 0x900 bytes each) and their palettes keyed by the current area
// (gFieldWork.area_id), the area music (field_update_music), blend presets and sprite-slot setup. Called by
// the field modules, the field / pre-battle menus and the mode-3 scenes.

#include "global.h"

void area_load_graphics(void) {
    gBg1Scroll.x = gUnk_03005310.unk1E;
    gBg1Scroll.y = gUnk_03005310.unk26;
    gBg2Scroll.x = gUnk_03005310.unk20;
    gBg2Scroll.y = gUnk_03005310.unk28;
    gBg3Scroll.x = gUnk_03005310.unk22;
    gBg3Scroll.y = gUnk_03005310.unk2A;
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
    gFieldWork.unkC4C = 1;
    update_battle_entity_status_chars();
}

void animate_area_bg_tiles(void) {
    const u8 *anim = gUnk_084096F4[gFieldWork.area_id];
    u8 n = anim[0];
    u8 *src;

    if (gFieldWork.bg_anim_enabled != 0 && anim[2] != 0) {
        if (gFieldWork.bg_anim_timer != 0) {
            gFieldWork.bg_anim_timer--;
        } else {
            if (anim[gFieldWork.bg_anim_frame + 3] == 0xFF)
                gFieldWork.bg_anim_frame = 0;
            src = gUnk_030057DC + anim[gFieldWork.bg_anim_frame + 3] * n * 32;
            DmaSet(3, src, 0x06009020, 0x80000000 | (n << 4));
            gFieldWork.bg_anim_frame++;
            gFieldWork.bg_anim_timer = 2;
        }
    }
}

// Sheet id 0 = the default for gFieldWork.player_form, 0xD0-0xFE = a variant picked by state, 0xFF = end.
s32 resolve_sprite_sheet_id(s32 t) {
    s32 u;
    if (t == 0)
        t = gPlayerFormSpriteSheets[gFieldWork.player_form];
    else if (t <= 0xAF)
        ;
    else if (t <= 0xBF)
        ;
    else if (t <= 0xCF)
        ;
    else if (t <= 0xFE) {
        const u8 *tbl = gUnk_08414394[t - 0xD0];
        t = tbl[gFieldWork.unkC38[t - 0xD0]];
    } else
        t = 0xFF;
    if (t != 0xFF && t > 0xBF)
        t = (t - 0xC0) * 2 + (u = gUnk_03006D38.unk6 + 0x28);
    return t;
}

void area_load_sprite_sheets(void) {
    s32 i = 0;
    u8 *dst = (u8 *)0x06010000;
    u32 t;

    while ((t = area_sprite_sheet_id(i)) != 0xFF) {
        if (gUnk_083F80F4[t] == NULL)
            t = 1;
        LZ77UnCompVram(gUnk_083F80F4[t], dst);
        dst += 0x900;
        i++;
    }
}

// Loads one sheet into all 12 sheet slots.
void fill_sprite_sheets(s32 arg) {
    s32 i;
    u8 *dst;
    const u8 *const *tbl;
    s32 t = resolve_sprite_sheet_id(arg);

    tbl = gUnk_083F80F4;
    dst = (u8 *)0x06010000;
    for (i = 11; i >= 0; i--) {
        if (tbl[t] == NULL)
            t = 1;
        LZ77UnCompVram(tbl[t], dst);
        dst += 0x900;
    }
}

// guess: BG palettes (13 palettes into the buffer at 0x0202FA00, or a default set).
void area_load_bg_palettes(void) {
    const u16 *pal = gUnk_083F9BF4[gFieldWork.area_id];

    if (pal != NULL) {
        DmaSet(3, pal, 0x0202FA00, 0x84000068);
    } else {
        DmaSet(3, gUnk_080AC5B4, 0x0202FA00, 0x84000008);
        DmaSet(3, gUnk_080AC654, 0x0202FA20, 0x84000008);
        DmaSet(3, gUnk_080AC6F4, 0x0202FA40, 0x84000008);
        DmaSet(3, gUnk_080AC794, 0x0202FA60, 0x84000008);
        DmaSet(3, gUnk_080AC5B4, 0x0202FA80, 0x84000008);
        DmaSet(3, gUnk_080AC5B4, 0x0202FAA0, 0x84000008);
        DmaSet(3, gUnk_080AC5B4, 0x0202FAC0, 0x84000008);
        DmaSet(3, gUnk_080AC834, 0x0202FAE0, 0x84000008);
        DmaSet(3, gUnk_080AC8D4, 0x0202FB00, 0x84000008);
    }
}

// The area's song (gUnk_0847EB80), or the script override in script_song while song is 0xFF.
u8 area_song_id(void) {
    if (gFieldWork.song == 0xFF)
        return gFieldWork.script_song;
    return gUnk_0847EB80[gFieldWork.area_id];
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
        if (gUnk_083D29B6[gUnk_03006D38.unk1 * 4])
            field_stop_songs(0x1E);
        break;
    case 24:
        if (gUnk_083D29B6[gUnk_03006D38.unk1 * 4]) {
            table_song = gUnk_083D29B6[gUnk_03006D38.unk1 * 4 + 1];
            gFieldWork.song = table_song;
            field_play_song(table_song);
        }
        break;
    case 25:
        switch (gUnk_083D29B6[gUnk_03006D38.unk1 * 4 + 2]) {
        case 1:
            table_song = gUnk_083D29B6[gUnk_03006D38.unk1 * 4 + 3];
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

u32 area_sprite_sheet_id(u32 arg) {
    return resolve_sprite_sheet_id(gUnk_08413514[gFieldWork.area_id][arg]);
}

void area_load_sprite_palettes_now(void) {
    s32 i;
    u32 t;

    for (i = 0; (t = area_sprite_sheet_id(i)) != 0xFF; i++) {
        t = area_sprite_sheet_id(i);
        if (gFieldSpritePalettes[t] == NULL)
            t = 1;
        DmaSet(3, gFieldSpritePalettes[t], 0x05000200 + i * 0x20, 0x84000008);
    }
}

void area_load_sprite_palettes(void) {
    s32 i;
    u32 t;

    for (i = 0; (t = area_sprite_sheet_id(i)) != 0xFF; i++) {
        t = area_sprite_sheet_id(i);
        if (gFieldSpritePalettes[t] == NULL)
            t = 1;
        DmaSet(3, gFieldSpritePalettes[t], 0x0202F800 + i * 0x20, 0x84000008);
    }
    DmaSet(3, gUnk_085FA0E4, 0x0202F9C0, 0x84000008);
}

void fill_sprite_palettes(s32 arg) {
    s32 i = 0;
    s32 t = resolve_sprite_sheet_id(arg);

    for (; i <= 11; i++) {
        if (gFieldSpritePalettes[t] == NULL)
            t = 1;
        DmaSet(3, gFieldSpritePalettes[t], 0x05000200 + i * 0x20, 0x84000008);
    }
}

// guess: sprite unkB (0xFF / 0 / 0x40) from the kind table gUnk_083D2ADD by sprite unk30.
void sprite_set_blend_from_kind(u8 idx) {
    u8 v = gUnk_083D2ADD[gSpriteEntries[idx].unk30];

    if (v == 2)
        gSpriteEntries[idx].unkB = 0xFF;
    else if (v == 1)
        gSpriteEntries[idx].unkB = 0;
    else
        gSpriteEntries[idx].unkB = 0x40;
}

static void blend_set_alpha_12_8(void) {
    vu16 *bldalpha;
    u16 v;

    REG_BLDCNT = 0x1F41;
    gBlendEffect.eva_level = 12.0f;
    gBlendEffect.evb_level = 8.0f;
    bldalpha = &REG_BLDALPHA;
    v = 0x80C;
    *bldalpha = v;
}

void blend_set_alpha_12_10(void) {
    vu16 *bldalpha;
    u16 v;

    REG_BLDCNT = 0xF40;
    gBlendEffect.eva_level = 12.0f;
    gBlendEffect.evb_level = 10.0f;
    bldalpha = &REG_BLDALPHA;
    v = 0xA0C;
    *bldalpha = v;
}

void sprite_entry_init(u8 slot, u16 a, u32 frame, u8 c, u8 d) {
    gSpriteEntries[slot].unk0 = a;
    gSpriteEntries[slot].unk32 = a;
    gSpriteEntries[slot].unk6 = frame;
    gSpriteEntries[slot].unkA = c;
    gSpriteEntries[slot].unk1C = d;
}

void sprite_entry_clear(u8 slot) {
    memzero_bytes((u8 *)&gSpriteEntries[slot], 0x40);
    clear_entity_state(slot);
}
