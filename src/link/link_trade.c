// Link trade scenes (mode 2). State 16 (medapart_trade_update): both players swap one Medapart; each side sends
// its part as a 0x4000-tagged packet through gLinkPackets, then reduce_medapart_stat / medapart_add_quantity apply
// the swap. State 17 (medal_trade_update): the player who chose the link menu entry (unk7A == 0) gives a Medal; its
// 0x40-byte record is sent one byte per packet (0xC000 | index << 8 | byte) and the receiver adds it with
// medal_add_from_buffer while the giver removes it. Their sub-state tables gPartTradeStates (13) and gMedalTradeStates
// (12) are adjacent in ROM. Entered from link_enter_medapart_trade / link_enter_medal_trade; both end in link_menu
// (state 20). Not runnable in the single-GBA harness: names come from the code.
// gMenuWork here: own_part_id / own_part_kind and the partner's, frame the tile animation counter,
// ticks the timeout, trade_medal the traded Medal record.
#include "global.h"
#include "constants/sprites.h"

static void medapart_trade_init_sprite_tree(u32 side) {
    if (side == 0) {
        struct SpriteTree *obj = (struct SpriteTree *)0x02026000;
        u8 *oams;
        u8 *slots;
        u32 fill;

        mem_fill8((u8 *)obj, 0xD0, 0);
        oams = (u8 *)0x020260D0;
        mem_fill8(oams, 0x820, 0);
        mem_fill8((u8 *)0x020264E0, 0x820, 0);
        slots = (u8 *)0x020268F0;
        mem_fill8(slots, 0x60, 0);
        gVBlankOamMode = 2;
        gSpriteWork = (struct SpriteWork *)0x02024000;
        fill = side;
        CpuFastSet(&fill, (void *)0x02024000, 0x01000426);
        gMedabotSpriteSlots = (struct MedabotSpriteSlot *)slots;
        init_sprite_tree(obj, (u8 *)gSpriteWork, (struct SpriteNodeDesc **)gMedabotSpriteNodeDescs,
                         (struct SpriteNodeOam *)oams);
        obj->oams = (struct SpriteNodeOam *)oams;
        draw_medapart_sprite(gSpriteWork->oamBuf, obj, gMenuWork->own_part_id, gMenuWork->own_part_kind, 0x3C, 0x28,
                             0xC7, side, 1);
    } else {
        struct SpriteTree *obj = (struct SpriteTree *)0x02026000;

        init_sprite_tree(obj, (u8 *)gSpriteWork, (struct SpriteNodeDesc **)gMedabotSpriteNodeDescs,
                         (struct SpriteNodeOam *)0x020264E0);
        obj->oams = (struct SpriteNodeOam *)0x020264E0;
        draw_medapart_sprite(gSpriteWork->oamBuf, obj, gMenuWork->partner_part_id, gMenuWork->partner_part_kind, 0x3C,
                             0x28, 0xC7, 4, 2);
    }
}

void load_medapart_sprite_animation(u8 id, u8 kind, u32 which) {
    struct SpriteTree *obj = (struct SpriteTree *)0x02026000;
    u8 x, y;

    obj->oams = (struct SpriteNodeOam *)(0x020260D0 + which * 0x410);
    x = gPartTradeSpritePositions[which][kind][0];
    y = gPartTradeSpritePositions[which][kind][1];
    if (which)
        draw_medapart_sprite(gSpriteWork->oamBuf, obj, id, kind, y, x, 0xC7, 4, 6);
    else
        draw_medapart_sprite(gSpriteWork->oamBuf, obj, id, kind, y, x, 0xC7, which, 5);
}

// Copies Medapart name id (part * 4 + kind) into the text buffer, slot 0 or 1 (0x14 bytes each).
static void medapart_copy_name(u16 id, u8 second) {
    const u8 *src;
    u8 *dst;
    u32 i;

    src = (const u8 *)gMedapartNames[0][id];
    dst = gGameWork.textBuf;
    if (second)
        dst += 0x14;
    for (i = 0; i < 20; i++) {
        *dst++ = *src++;
        if (*src == 0xFE)
            break;
    }
    *dst = 0xFE;
}

// Loads the Medal picture into OBJ VRAM and sets up the affine Medal sprite (hidden for the receiver).
static void medal_trade_show_medal_sprite(u32 medal, u32 frame) {
    struct SpriteEntry *sprite;
    u8 zero;

    lz_decompress_dispatch(gMedalSpriteGfx[medal][frame], (void *)0x06010000);
    sprite = gSpriteEntries;
    zero = 0;
    sprite->flags = SPRITE_FLAG_ENABLED | SPRITE_PRIORITY(2) | SPRITE_FLAG_AFFINE | SPRITE_FLAG_DOUBLE_SIZE |
                    SPRITE_FLAG_PART_PALETTE;
    if (gMenuWork->partner_chose == 0)
        sprite->flags |= SPRITE_FLAG_VISIBLE;
    sprite->x = 0xB8;
    sprite->y = 0x38;
    sprite->frame = 0x200;
    sprite->palette = zero;
    sprite->frame_table = zero;
    sprite->order = 0x40;
    sprite->scale_x = 0x40;
    sprite->scale_y = 0x40;
}

// The trade screen's BG tile animation (two tile rows): frame from unk3A, which counts down, so the frames speed up.
static void trade_tiles_speed_up_two_rows(void) {
    s32 anim_frame;
    s32 i;
    u32 src_off;
    u32 dst_off;
    s32 other_frame;
    s32 next_frame;
    u32 tiles;

    switch (gMenuWork->frame / 128) {
    case 0:
        anim_frame = gMenuWork->frame >> 1;
        break;
    case 1:
        anim_frame = gMenuWork->frame >> 2;
        break;
    case 2:
        anim_frame = gMenuWork->frame >> 3;
        break;
    case 3:
        anim_frame = gMenuWork->frame >> 4;
        break;
    default:
        anim_frame = gMenuWork->frame >> 5;
        break;
    }
    anim_frame &= 3;
    if (--gMenuWork->frame < 0)
        gMenuWork->frame = 0x3F;
    i = 0;
    next_frame = anim_frame + 2;
    tiles = 0x0600D800;
    dst_off = 0x1C0;
    src_off = anim_frame << 9;
    for (; i < 8; i++) {
        other_frame = anim_frame;
        CpuSet((void *)(src_off + tiles), (void *)(0x0600E804 + dst_off), 0xC);
        other_frame = next_frame & 3;
        CpuSet((void *)((other_frame * 8 + i) * 0x40 + tiles), (void *)(0x0600E820 + dst_off), 0xC);
        dst_off += 0x40;
        src_off += 0x40;
    }
}

static void trade_tiles_speed_up(void) {
    s32 anim_frame;
    s32 i;
    u8 *src;
    u8 *dst;

    switch (gMenuWork->frame / 128) {
    case 0:
        anim_frame = gMenuWork->frame >> 1;
        break;
    case 1:
        anim_frame = gMenuWork->frame >> 2;
        break;
    case 2:
        anim_frame = gMenuWork->frame >> 3;
        break;
    case 3:
        anim_frame = gMenuWork->frame >> 4;
        break;
    default:
        anim_frame = gMenuWork->frame >> 5;
        break;
    }
    anim_frame &= 3;
    if (--gMenuWork->frame < 0)
        gMenuWork->frame = 0x3F;
    dst = (u8 *)0x0600E9E2;
    anim_frame <<= 9;
    src = (u8 *)0x0600D800 + anim_frame;
    for (i = 0; i < 8; i++) {
        CpuSet(src, dst, 0xC);
        dst += 0x40;
        src += 0x40;
    }
}

// As trade_tiles_speed_up_two_rows, with the speed table reversed (slows down as unk3A counts down).
static void trade_tiles_slow_down_two_rows(void) {
    s32 anim_frame;
    s32 i;
    u32 src_off;
    u32 dst_off;
    s32 other_frame;
    s32 next_frame;
    u32 tiles;

    switch (gMenuWork->frame / 128) {
    case 0:
    case 1:
        anim_frame = gMenuWork->frame >> 5;
        break;
    case 2:
        anim_frame = gMenuWork->frame >> 4;
        break;
    case 3:
        anim_frame = gMenuWork->frame >> 3;
        break;
    case 4:
        anim_frame = gMenuWork->frame >> 2;
        break;
    default:
        anim_frame = gMenuWork->frame >> 1;
        break;
    }
    anim_frame &= 3;
    if (--gMenuWork->frame < 0)
        gMenuWork->frame = 0x3F;
    i = 0;
    next_frame = anim_frame + 2;
    tiles = 0x0600D800;
    dst_off = 0x1C0;
    src_off = anim_frame << 9;
    for (; i < 8; i++) {
        other_frame = anim_frame;
        CpuSet((void *)(src_off + tiles), (void *)(0x0600E804 + dst_off), 0xC);
        other_frame = next_frame & 3;
        CpuSet((void *)((other_frame * 8 + i) * 0x40 + tiles), (void *)(0x0600E820 + dst_off), 0xC);
        dst_off += 0x40;
        src_off += 0x40;
    }
}

static void trade_tiles_slow_down(void) {
    s32 anim_frame;
    s32 i;
    u8 *src;
    u8 *dst;

    switch (gMenuWork->frame / 128) {
    case 0:
    case 1:
        anim_frame = gMenuWork->frame >> 5;
        break;
    case 2:
        anim_frame = gMenuWork->frame >> 4;
        break;
    case 3:
        anim_frame = gMenuWork->frame >> 3;
        break;
    case 4:
        anim_frame = gMenuWork->frame >> 2;
        break;
    default:
        anim_frame = gMenuWork->frame >> 1;
        break;
    }
    anim_frame &= 3;
    if (--gMenuWork->frame < 0)
        gMenuWork->frame = 0x3F;
    dst = (u8 *)0x0600E9E2;
    anim_frame <<= 9;
    src = (u8 *)0x0600D800 + anim_frame;
    for (i = 0; i < 8; i++) {
        CpuSet(src, dst, 0xC);
        dst += 0x40;
        src += 0x40;
    }
}

void medapart_trade_take_selection(void) {
    gMenuWork->own_part_id = gLinkTradeData;
    gMenuWork->own_part_kind = ((u16 *)&gLinkTradeData)[1];
    gGameSubState++;
}

void medapart_trade_init_screen(void) {
    u32 size;
    u32 zero;
    u32 z;

    if (sound_current_song() != 0x18)
        play_song(0x18);
    zero = z = 0;
    CpuFastSet(&zero, (void *)VRAM, 0x01006000);
    reset_bg_scroll();
    clear_battle_sprite_slot(0, 0x80);
    REG_DISPCNT = 0x60;
    REG_BLDCNT = 0x2FF;
    REG_BLDY = 0x10;
    REG_BG1CNT = 0x1E05;
    REG_BG2CNT = 0x1B06;
    REG_BG3CNT = 0x3C07;
    decompress_and_write_tilemap(gPartTradeBg1Tilemap, REG_BG1CNT);
    decompress_and_write_tilemap(gPartTradeAnimFramesTilemap, REG_BG2CNT);
    decompress_and_write_tilemap(gPartTradeBg3Tilemap, REG_BG3CNT);
    REG_BG2CNT = 0x1D06;
    size = dma3_copy_or_decompress(gPartTradeBgTiles, gDecompressBuffer);
    CpuCopy16(gDecompressBuffer, (void *)0x06004000, size);
    lz_decompress_dispatch(gMenuDigitTilesLz, (void *)(0x06004000 + size));
    gMenuWork->bg_tile_base = size / 32 - 1;
    CpuFastSet(gPartTradeBgPalette, (void *)PLTT, 0x80);
    CpuFastSet(gGradientPaletteCyan, (void *)(PLTT + 0x3A0), 8);
    CpuFastSet(gGradientPaletteCyan, &gPaletteBackup[0xD0], 8);
    lz_decompress_dispatch(gMenuObjTilesLz, (void *)0x06010000);
    lz_decompress_dispatch(gSpriteFontTiles, (void *)0x06011E00);
    gMenuWork->frame = 0x280;
    medapart_copy_name(gMenuWork->own_part_id * 4 + gMenuWork->own_part_kind, 0);
    render_text_string_to_sprites(gGameWork.textBuf, 0, 0, 10, 16, 13, z, 1);
    medapart_trade_init_sprite_tree(0);
    load_medapart_sprite_animation(gMenuWork->own_part_id, gMenuWork->own_part_kind, 0);
    trade_tiles_speed_up_two_rows();
    init_blend_effect(gMenuWork->blend, 0x10, 0, -1, 0xC0);
    gSpriteEntries[0x21].flags = SPRITE_FLAG_ENABLED;
    gSpriteEntries[0x21].frame_table = 2;
    gSpriteEntries[0x21].x = 0x28;
    gSpriteEntries[0x21].y = 0x40;
    gSpriteEntries[0x21].palette = 8;
    gSpriteEntries[0x21].frame = 0x2A;
    REG_DISPCNT |= 0x200;
    REG_DISPCNT |= 0x400;
    REG_DISPCNT |= 0x800;
    REG_DISPCNT |= 0x1000;
    gGameSubState++;
}

static inline void *vram_at(u32 off) {
    return (void *)(0x06004000 + off);
}

void medapart_trade_fade_in(void) {
    if (blend_fade_step_08065598(gMenuWork->blend)) {
        gGameSubState++;
        gMenuWork->ticks = 0x258;
        text_window_init(1, 0, 1);
    }
    load_medapart_sprite_animation(gMenuWork->own_part_id, gMenuWork->own_part_kind, 0);
}

// Sends the own part and waits for both partners' part packets, then keeps the partner's.
void medapart_trade_exchange_parts(void) {
    struct LinkPackets *packets;
    struct MenuWork *w;
    u16 packet0, packet1;

    run_message(gLinkMenuMessages[15]);
    packets = &gLinkPackets;
    w = gMenuWork;
    packets->sendData = w->own_part_id | (w->own_part_kind << 8) | 0x4000;
    packet0 = packets->recv[0][1];
    packet1 = packets->recv[1][1];
    if ((packet0 & 0xC000) == 0x4000 && (packet1 & 0xC000) == (packet0 & 0xC000)) {
        if (gLinkPlayerId) {
            w->partner_part_id = packet0 & 0x7F;
            gMenuWork->partner_part_kind = (packet0 >> 8) & 3;
        } else {
            w->partner_part_id = packet1 & 0x7F;
            gMenuWork->partner_part_kind = (packet1 >> 8) & 3;
        }
        medapart_trade_init_sprite_tree(1);
        medapart_copy_name(gMenuWork->partner_part_id * 4 + gMenuWork->partner_part_kind, 1);
        render_text_string_to_sprites(gGameWork.textBuf + 0x14, 0x10, 0xE, 0xA, 0x10, 0xD, 0, 1);
        text_window_init(1, 0, 1);
        gGameSubState++;
    }
    load_medapart_sprite_animation(gMenuWork->own_part_id, gMenuWork->own_part_kind, 0);
}

void medapart_trade_apply(void) {
    run_message(gLinkMenuMessages[19]);
    trade_tiles_speed_up_two_rows();
    load_medapart_sprite_animation(gMenuWork->own_part_id, gMenuWork->own_part_kind, 0);
    load_medapart_sprite_animation(gMenuWork->partner_part_id, gMenuWork->partner_part_kind, 1);
    if ((s16)--gMenuWork->ticks < 0) {
        gGameWork.stepCounter = 0;
        gGameSubState++;
        reduce_medapart_stat(gMenuWork->own_part_id, gMenuWork->own_part_kind, 1);
        medapart_add_quantity(gMenuWork->partner_part_id, gMenuWork->partner_part_kind, 1);
        CpuFastSet((void *)0x05000200, gPaletteBackup, 0x100);
        play_sound_effect(0x4B);
    }
}

void medapart_trade_flash_white(void) {
    struct GameWork *game = &gGameWork;
    u8 *step = &game->stepCounter;

    if (*step <= 0x40) {
        obj_palettes_blend_masked_now(0x7FFF, *step >> 1, 0xFF);
        (*step)++;
    } else {
        gMenuWork->ticks = 0;
        *step = 0;
        gGameSubState++;
    }
    load_medapart_sprite_animation(gMenuWork->own_part_id, gMenuWork->own_part_kind, 0);
    load_medapart_sprite_animation(gMenuWork->partner_part_id, gMenuWork->partner_part_kind, 1);
    trade_tiles_speed_up_two_rows();
}

void medapart_trade_crossfade_swap(void) {
    struct MenuWork *w = gMenuWork;
    s32 n;
    u16 zero;
    vu16 oam_fill;

    n = 16 - (s16)w->ticks++;
    if (n != 0) {
        REG_BLDCNT = 0xE50;
        REG_BLDALPHA = ((16 - n) << 8) | n;
        REG_BLDY = 8;
        load_medapart_sprite_animation(w->own_part_id, w->own_part_kind, 0);
        load_medapart_sprite_animation(gMenuWork->partner_part_id, gMenuWork->partner_part_kind, 1);
        if (n == 1)
            clear_battle_sprite_slot(0, 0x80);
    } else {
        n = w->own_part_id;
        w->own_part_id = w->partner_part_id;
        zero = 0;
        gMenuWork->partner_part_id = n;
        n = gMenuWork->own_part_kind;
        gMenuWork->own_part_kind = gMenuWork->partner_part_kind;
        gMenuWork->partner_part_kind = n;
        medapart_trade_init_sprite_tree(0);
        medapart_trade_init_sprite_tree(1);
        gMenuWork->ticks = zero;
        gGameSubState++;
        oam_fill = 0x200;
        CpuSet((void *)&oam_fill, gSpriteWork->oamBuf, 0x01000200);
    }
    trade_tiles_speed_up_two_rows();
}

void medapart_trade_swap_palettes(void) {
    u8 buf[0x20];
    s32 i;
    u16 *staged, *backup;
    u32 zero, one;

    staged = (u16 *)0x0202F880;
    backup = gPaletteBackup;
    for (i = 3; i >= 0; i--) {
        CpuFastSet(backup, buf, 8);
        CpuFastSet(staged, backup, 8);
        CpuFastSet(buf, staged, 8);
        staged += 16;
        backup += 16;
    }
    gGameSubState++;
    gMenuWork->ticks = (zero = 0, one = 1);
    clear_battle_sprite_slot(0, 0x80);
    medapart_copy_name(gMenuWork->own_part_id * 4 + gMenuWork->own_part_kind, 0);
    medapart_copy_name(gMenuWork->partner_part_id * 4 + gMenuWork->partner_part_kind, 1);
    render_text_string_to_sprites(gGameWork.textBuf, 0, 0, 10, 16, 13, zero, one);
    render_text_string_to_sprites(gGameWork.textBuf + 0x14, 16, 14, 10, 16, 13, zero, one);
    play_sound_effect(0x2A);
    trade_tiles_speed_up_two_rows();
}

void medapart_trade_blend_in(void) {
    struct MenuWork *w = gMenuWork;
    s32 n = (s16)w->ticks++;

    if (n <= 16) {
        obj_palettes_blend_masked_now(0x7FFF, 0x20, 0xFF);
        REG_BLDCNT = 0xE50;
        REG_BLDALPHA = ((16 - n) << 8) | n;
        REG_BLDY = 8;
    } else {
        REG_BLDCNT = 0xE10;
        REG_BLDALPHA = ((16 - n) << 8) | n;
        REG_BLDY = 8;
        w->ticks = 0;
        gGameWork.stepCounter = 0;
        gGameSubState++;
    }
    load_medapart_sprite_animation(gMenuWork->own_part_id, gMenuWork->own_part_kind, 0);
    load_medapart_sprite_animation(gMenuWork->partner_part_id, gMenuWork->partner_part_kind, 1);
    trade_tiles_speed_up_two_rows();
}

void medapart_trade_unflash(void) {
    struct GameWork *game = &gGameWork;
    u8 *step = &game->stepCounter;

    if (*step <= 0x40) {
        obj_palettes_blend_masked_now(0x7FFF, 0x20 - (*step >> 1), 0xFF);
        (*step)++;
    } else {
        CpuFastSet(gPartTradeObjPalette, (void *)0x05000300, 8);
        CpuFastSet(gPartTradeObjPalette, gPaletteBackup + 0x80, 8);
        *step = 0;
        gGameSubState++;
        gMenuWork->frame = 0x280;
    }
    load_medapart_sprite_animation(gMenuWork->own_part_id, gMenuWork->own_part_kind, 0);
    load_medapart_sprite_animation(gMenuWork->partner_part_id, gMenuWork->partner_part_kind, 1);
    trade_tiles_speed_up_two_rows();
}

void medapart_trade_scroll_in(void) {
    load_medapart_sprite_animation(gMenuWork->own_part_id, gMenuWork->own_part_kind, 0);
    load_medapart_sprite_animation(gMenuWork->partner_part_id, gMenuWork->partner_part_kind, 1);
    trade_tiles_slow_down_two_rows();
    if (gMenuWork->frame == 0) {
        gSpriteEntries[0x21].flags = SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE;
        gSpriteEntries[0x21].frame_table = 2;
        gSpriteEntries[0x21].x = 0x28;
        gSpriteEntries[0x21].y = 0x40;
        gSpriteEntries[0x21].palette = 8;
        gSpriteEntries[0x21].frame = 0x2A;
        text_window_init(1, 0, 1);
        gGameSubState++;
    }
}

void medapart_trade_wait_confirm(void) {
    load_medapart_sprite_animation(gMenuWork->own_part_id, gMenuWork->own_part_kind, 0);
    load_medapart_sprite_animation(gMenuWork->partner_part_id, gMenuWork->partner_part_kind, 1);
    if (run_message(gLinkMenuMessages[gMenuWork->own_part_kind + 0x14]) && (KEYS_LO(gNewKeys) & 1)) {
        gLinkPackets.sendData = 0xFF07;
        play_sound_effect(0xD);
    }
    if (gLinkPackets.recv[0][1] == 0xFF07 || gLinkPackets.recv[1][1] == 0xFF07) {
        init_blend_effect(gMenuWork->blend, 0, 0, 1, 0xC0);
        gGameSubState++;
    }
}

void medapart_trade_fade_out(void) {
    if (blend_fade_step_08065598(gMenuWork->blend)) {
        clear_battle_sprite_slot(0, 0x80);
        gGameState = 0x14;
        gGameSubState = 0;
    } else {
        load_medapart_sprite_animation(gMenuWork->own_part_id, gMenuWork->own_part_kind, 0);
        load_medapart_sprite_animation(gMenuWork->partner_part_id, gMenuWork->partner_part_kind, 1);
    }
}

// Link Medapart trade (state 16): runs sub-state gPartTradeStates[gGameSubState], scrolls BG3.
void medapart_trade_update(void) {
    struct FuncTable13 states = gPartTradeStates;

    if (gVBlankOamMode == 2) {
        u32 fill = 0x200;
        CpuFastSet(&fill, gSpriteWork->oamBuf, 0x01000100);
    }
    states.f[gGameSubState]();
    if (gFrameCounter & 1) {
        gBg3Scroll.x++;
        gBg3Scroll.y++;
    }
}

#define TM(cnt, i) (*(u16 *)(((((cnt) >> 8) & 0x1F) << 11) + (0x06000000 + (i) * 2)))

void medal_trade_init_screen(void) {
    u8 *src;
    u8 *dst;
    u32 i;
    u32 zero;
    u32 size;
    struct MenuWork *w;
    struct MenuWork *w2;
    s32 partner_chose;
    s32 j;
    vu16 *bg2, *bg3;

    src = (u8 *)0x02023000;
    dst = (u8 *)&gMenuWork->trade_medal;
    for (i = 0; i < 0x40; i++)
        *dst++ = *src++;
    if (sound_current_song() != 0x18)
        play_song(0x18);
    zero = 0;
    CpuFastSet(&zero, (void *)VRAM, 0x01006000);
    reset_bg_scroll();
    clear_battle_sprite_slot(0, 0x80);
    REG_DISPCNT = 0x60;
    REG_BLDCNT = 0x2FF;
    REG_BLDY = 0x10;
    REG_BG1CNT = 0x1E05;
    bg2 = &REG_BG2CNT;
    *bg2 = 0x1B06;
    bg3 = &REG_BG3CNT;
    *bg3 = 0x3C07;
    decompress_and_write_tilemap(gMedalTradeBg1Tilemap, REG_BG1CNT);
    decompress_and_write_tilemap(gMedalTradeAnimFramesTilemap, *bg2);
    decompress_and_write_tilemap(gMedalTradeBg3Tilemap, *bg3);
    *bg2 = 0x1D06;
    decompress_and_write_tilemap(gMedalTradeBg2Tilemap, *bg2);
    size = dma3_copy_or_decompress(gMedalTradeBgTiles, (void *)0x02030000);
    CpuCopy16((void *)0x02030000, (void *)0x06004000, size);
    lz_decompress_dispatch(gMenuDigitTilesLz, (void *)(size + 0x06004000));
    gMenuWork->bg_tile_base = (size >> 5) + 4;
    lz_decompress_dispatch(gSmallDigitTiles, (void *)(size + 0x06004080));
    CpuFastSet(gMedalTradeBgPalettes, (void *)PLTT, 0x50);
    CpuFastSet(gGradientPaletteGold + 0x30, (void *)0x050003A0, 8);
    CpuFastSet(gGradientPaletteGold + 0x30, (void *)0x0202F9A0, 8);
    CpuFastSet(gCommonObjPalette, (void *)0x05000200, 8);
    CpuFastSet(gGradientPaletteGold + 0x20, (void *)0x05000220, 8);
    CpuFastSet(gGradientPaletteGold, (void *)0x05000240, 8);
    lz_decompress_dispatch(gSpriteFontTiles, (void *)0x06017400);
    w = gMenuWork;
    w->frame = 0x280;
    partner_chose = w->partner_chose;
    if (partner_chose == 0) {
        u32 medal;
        u32 icon_tile;
        u32 buf;
        const u8 *const *names;
        s32 lvl;
        u16 tile;
        u16 icon_tile16;
        u16 *map;

        medal = w->trade_medal.graphicId;
        medal_trade_show_medal_sprite(medal, w->trade_medal.spriteVariant);
        render_text_sprites_08040DB8(gMenuWork->trade_medal.name, 0x20, 4, 4, 0xA, 2, partner_chose, 1);
        j = 0;
        icon_tile = size >> 5;
        buf = (u32)gGameWork.textBuf;
        names = (const u8 *const *)gMedalNames;
        for (; j <= 9; j++)
            *(u8 *)(j + buf) = names[medal][j];
        render_text_sprites_08040DB8(gGameWork.textBuf, 0x10, 5, 8, 0xA, 1, 1, 1);
        w2 = gMenuWork;
        lvl = w2->trade_medal.level;
        if (lvl == 100) {
            TM(REG_BG1CNT, 0x10D) = (w2->bg_tile_base + 0x14) | 0x7000;
            TM(REG_BG1CNT, 0x12D) = (gMenuWork->bg_tile_base + 0x15) | 0x7000;
            TM(REG_BG1CNT, 0x10E) = (gMenuWork->bg_tile_base + 0x16) | 0x7000;
            TM(REG_BG1CNT, 0x12E) = (gMenuWork->bg_tile_base + 0x17) | 0x7000;
        } else {
            TM(REG_BG1CNT, 0x10D) = (w2->bg_tile_base + lvl / 10 * 2) | 0x7000;
            TM(REG_BG1CNT, 0x12D) = (gMenuWork->bg_tile_base + lvl / 10 * 2 + 1) | 0x7000;
            TM(REG_BG1CNT, 0x10E) = (gMenuWork->bg_tile_base + lvl % 10 * 2) | 0x7000;
            TM(REG_BG1CNT, 0x12E) = (gMenuWork->bg_tile_base + lvl % 10 * 2 + 1) | 0x7000;
        }
        CpuSet(gMedalIconTiles + medal * 0x80, (void *)(size + 0x06004000), 0x40);
        icon_tile16 = icon_tile;
        tile = icon_tile16 | 0x6000;
        map = (u16 *)(VRAM + (((REG_BG1CNT >> 8) & 0x1F) << 11)) + 3 + 8 * 32;
        *map = tile;
        map++;
        *map = tile + 1;
        map += 31;
        *map = tile + 2;
        map++;
        *map = tile + 3;
    } else {
        w->saved_tiles[0] = TM(*bg2, 0x10C);
        w->saved_tiles[1] = TM(*bg2, 0x10D);
        w->saved_tiles[2] = TM(*bg2, 0x12C);
        w->saved_tiles[3] = TM(*bg2, 0x12D);
        TM(*bg2, 0x10C) = TM(*bg2, 0x10B);
        TM(*bg2, 0x10D) = TM(*bg2, 0x10B);
        TM(*bg2, 0x12C) = TM(*bg2, 0x12B);
        TM(*bg2, 0x12D) = TM(*bg2, 0x12B);
    }
    trade_tiles_speed_up();
    init_blend_effect(gMenuWork->blend, 0x10, 0, -1, 0xC0);
    REG_DISPCNT |= 0x200;
    REG_DISPCNT |= 0x400;
    REG_DISPCNT |= 0x800;
    REG_DISPCNT |= 0x1000;
    gGameSubState++;
}

void medal_trade_fade_in(void) {
    if (blend_fade_step_08065598(gMenuWork->blend)) {
        CpuFastSet((void *)0x05000200, gPaletteBackup, 0x40);
        gGameSubState++;
        gMenuWork->ticks = 600;
        text_window_init(1, 0, 1);
    }
}

// Both sides send 0xFDEF until they see each other; 0xFEDF from the partner aborts to state 26.
void medal_trade_handshake(void) {
    if (gMenuWork->partner_chose)
        run_message(gLinkMenuMessages[24]);
    if (gLinkPackets.recv[gLinkPlayerId == 0][1] == 0xFEDF)
        gGameState = 0x1A;
    else if (gLinkPackets.recv[0][1] == 0xFDEF && gLinkPackets.recv[1][1] == gLinkPackets.recv[0][1]) {
        gGameSubState++;
        gMenuWork->counter = 0;
        if (gMenuWork->partner_chose)
            text_window_init(1, 0, 1);
    } else
        gLinkPackets.sendData = 0xFDEF;
}

static inline s16 link_packet_hi(u16 pkt) {
    return (pkt & 0xF) << 8 | 0xC000;
}

// Receiver requests the Medal record byte by byte (0xFE00 | index); giver answers; 0xFF00 when all 0x40 arrived.
void medal_trade_transfer(void) {
    u8 *buf;
    u8 *byte_ptr;
    u16 pkt;
    u8 n;
    u16 value;
    struct MenuWork *menu;

    run_message(gLinkMenuMessages[25]);
    menu = gMenuWork;
    buf = (u8 *)&menu->trade_medal;
    pkt = gLinkPackets.recv[gLinkPlayerId == 0][1];
    if (menu->partner_chose) {
        n = menu->counter;
        byte_ptr = buf + n;
        if ((pkt & 0xF000) == 0xC000 && (n & 0xF) == ((pkt >> 8) & 0xF)) {
            *byte_ptr = pkt;
            gMenuWork->counter++;
        }
        if (gMenuWork->counter > 0x3F)
            gLinkPackets.sendData = 0xFF00;
        else
            gLinkPackets.sendData = gMenuWork->counter | 0xFE00;
    } else {
        u16 cmd = pkt & 0xFF00;
        if (cmd == 0xFF00)
            gLinkPackets.sendData = cmd;
        if (cmd == 0xFE00) {
            byte_ptr = buf + (pkt & 0xFF);
            value = *byte_ptr;
            gLinkPackets.sendData = value | link_packet_hi(pkt);
        }
    }
    if (gLinkPackets.recv[0][1] == 0xFF00 && gLinkPackets.recv[1][1] == gLinkPackets.recv[0][1]) {
        if (gMenuWork->partner_chose) {
            medal_add_from_buffer(buf);
            medal_trade_show_medal_sprite(buf[1], buf[8]);
        } else
            medal_remove_by_id(buf[1]);
        gGameSubState++;
    }
}

void medal_trade_skip_step(void) {
    gGameSubState++;
}

void medal_trade_wait_message(void) {
    if (run_message(gLinkMenuMessages[25])) {
        struct MenuWork *menu;
        trade_tiles_speed_up();
        menu = gMenuWork;
        if ((s16)--menu->ticks < 0) {
            gGameSubState++;
            menu->ticks = 0;
        }
    }
}

#define BG1(o) (*(u16 *)(VRAM + (o) + (((REG_BG1CNT >> 8) & 0x1F) << 11)))
#define BG2(o) (*(u16 *)(VRAM + (o) + (((REG_BG2CNT >> 8) & 0x1F) << 11)))

// Shrinks the Medal sprite to a sliver, then swaps in the received Medal (receiver) or hides it (giver).
void medal_trade_flip_close(void) {
    struct MenuWork *menu;
    s16 ticks;
    u8 lvl;
    s32 i;

    trade_tiles_speed_up();
    menu = gMenuWork;
    ticks = ++menu->ticks;
    if (ticks > 0xF) {
        gGameSubState++;
        if (menu->partner_chose == 0) {
            gSpriteEntries[0].flags &= (u16)~SPRITE_FLAG_VISIBLE;
            return;
        }
        gSpriteEntries[0].flags |= SPRITE_FLAG_VISIBLE;
        lvl = menu->trade_medal.level;
        render_text_sprites_08040DB8(menu->trade_medal.name, 0x20, 4, 4, 10, 2, 0, 1);
        for (i = 0; i <= 9; i++)
            gGameWork.textBuf[i] = ((const u8 *)gMedalNames[gMenuWork->trade_medal.graphicId])[i];
        render_text_sprites_08040DB8(gGameWork.textBuf, 0x10, 5, 8, 10, 1, 1, 1);
        BG2(0x218) = gMenuWork->saved_tiles[0];
        BG2(0x21A) = gMenuWork->saved_tiles[1];
        BG2(0x258) = gMenuWork->saved_tiles[2];
        BG2(0x25A) = gMenuWork->saved_tiles[3];
        if (lvl == 100) {
            BG1(0x21A) = (gMenuWork->bg_tile_base + 0x14) | 0x7000;
            BG1(0x25A) = (gMenuWork->bg_tile_base + 0x15) | 0x7000;
            BG1(0x21C) = (gMenuWork->bg_tile_base + 0x16) | 0x7000;
            BG1(0x25C) = (gMenuWork->bg_tile_base + 0x17) | 0x7000;
        } else {
            BG1(0x21A) = (gMenuWork->bg_tile_base + (u8)(lvl / 10) * 2) | 0x7000;
            BG1(0x25A) = (gMenuWork->bg_tile_base + (u8)(lvl / 10) * 2 + 1) | 0x7000;
            BG1(0x21C) = (gMenuWork->bg_tile_base + (u8)(lvl % 10) * 2) | 0x7000;
            BG1(0x25C) = (gMenuWork->bg_tile_base + (u8)(lvl % 10) * 2 + 1) | 0x7000;
        }
        CpuFastSet(gMedalIconTiles + gMenuWork->trade_medal.graphicId * 0x80,
                   (void *)(VRAM + 0x3F80 + gMenuWork->bg_tile_base * 32), 0x20);
        {
            u16 tile;
            u16 *dst;
            tile = gMenuWork->bg_tile_base - 4;
            tile |= 0x6000;
            dst = (u16 *)(VRAM + (((REG_BG1CNT >> 8) & 0x1F) << 11)) + 3 + 8 * 32;
            *dst = tile;
            dst++;
            *dst = tile + 1;
            dst += 31;
            *dst = tile + 2;
            dst++;
            *dst = tile + 3;
        }
        return;
    }
    if (ticks <= 7)
        gSpriteEntries[0].scale_x = 0x40 - (s16)menu->ticks * 8;
    else
        gSpriteEntries[0].scale_x = 1;
    if ((s16)gMenuWork->ticks > 1) {
        gSpriteEntries[0].scale_y = (s16)gMenuWork->ticks * 4 + 0x38;
        gSpriteEntries[0].y = 0x38 - ((s16)gMenuWork->ticks - 2) * 8;
    }
}

void medal_trade_flip_open(void) {
    struct MenuWork *menu;
    s16 ticks;

    trade_tiles_speed_up();
    menu = gMenuWork;
    ticks = --menu->ticks;
    if (ticks < 0) {
        menu->frame = 0x280;
        gGameSubState++;
        return;
    }
    if (ticks <= 7)
        gSpriteEntries[0].scale_x = 0x40 - (s16)menu->ticks * 8;
    else
        gSpriteEntries[0].scale_x = 1;
    menu = gMenuWork;
    if ((s16)menu->ticks > 1) {
        gSpriteEntries[0].scale_y = (s16)menu->ticks * 4 + 0x38;
        gSpriteEntries[0].y = 0x38 - ((s16)menu->ticks - 2) * 8;
    }
}

void medal_trade_scroll_in(void) {
    trade_tiles_slow_down();
    if (gMenuWork->frame == 0) {
        text_window_init(1, 0, 1);
        gGameSubState++;
        play_sound_effect(gMenuWork->partner_chose ? 0xE : 5);
    }
}

void medal_trade_wait_confirm(void) {
    if (run_message(gLinkMenuMessages[gMenuWork->partner_chose ? 26 : 27])) {
        if (KEYS_LO(gRepeatKeys) & 1) {
            play_sound_effect(0xD);
            gGameSubState++;
        } else if (gLinkPackets.recv[gLinkPlayerId == 0][1] == 0xFEFF)
            gGameSubState++;
    }
}

void medal_trade_sync_done(void) {
    if (run_message(gLinkMenuMessages[gMenuWork->partner_chose ? 26 : 27])) {
        gLinkPackets.sendData = 0xFEFF;
        if (gLinkPackets.recv[0][1] == 0xFEFF && gLinkPackets.recv[1][1] == gLinkPackets.recv[0][1]) {
            gGameSubState++;
            init_blend_effect(gMenuWork->blend, 0, 0, 1, 0xC0);
        }
    }
}

void medal_trade_fade_out(void) {
    if (blend_fade_step_08065598(gMenuWork->blend)) {
        gGameState = 0x14;
        gGameSubState = 0;
    }
}

// Link Medal trade (state 17): runs sub-state gMedalTradeStates[gGameSubState], scrolls BG3.
void medal_trade_update(void) {
    struct FuncTable12 states = gMedalTradeStates;

    if (gVBlankOamMode == 2) {
        u32 fill = 0x200;
        CpuFastSet(&fill, gSpriteWork->oamBuf, 0x01000100);
    }
    states.f[gGameSubState]();
    if (gFrameCounter & 1) {
        gBg3Scroll.x++;
        gBg3Scroll.y++;
    }
}
