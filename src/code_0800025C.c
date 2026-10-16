#include "global.h"

INCLUDE_ASM("asm/nonmatching/code_0800025C", main);

void irq_init(void)
{
    CpuSet(gIntrTableTemplate, gIntrTable, 0x0400000E);
    CpuSet(irq_dispatch_arm, gIntrMain, 0x04000200);
    INTR_VECTOR = gIntrMain;
    gVBlankOnceCallback = nullsub_08000840;
    gVBlankCallback = nullsub_08000840;
    gHBlankCallback = nullsub_08000840;
    REG_IE = 0x2601;
    REG_DISPSTAT = 8;
    REG_IME = 1;
    sub_0807C740(0x40);
    eeprom_setup_timer_irq();
}

void hw_reset_init(void)
{
    u32 a, b, c;

    REG_IME = 0;
    a = 0;
    CpuFastSet(&a, (void *)EWRAM, 0x01010000);
    b = 0;
    CpuFastSet(&b, (void *)IWRAM, 0x01001F40);
    clear_oam();
    c = 0;
    CpuFastSet(&c, (void *)PLTT, 0x01000100);
    *(u16 *)PLTT = 0x7FFF;
}

INCLUDE_ASM("asm/nonmatching/code_0800025C", clear_oam);

void sound_init(struct Unk_03007014 *work)
{
    sound_engine_init(work);
    sub_08074900(gUnk_080AFFB8);
    sub_08074BC4(gUnk_080B06EC);
    sub_08074E70(&gUnk_080B1788);
    sub_08073AE4((u32)gUnk_080B1570);
    sub_08073AF8((u32)gUnk_080B1718);
    play_song(0);
}

void vblank_irq(void)
{
    if (!(gUnk_03002B90 & 1))
    {
        gUnk_03002B90 |= 1;
        vblank_body();
        gUnk_03002B90 &= ~1;
        if (gUnk_03005010.unk0 & 0x80)
            sub_080023D8();
        REG_IME = 0;
        if (++gUnk_03002410 > 5 && gUnk_03005170.unk4)
        {
            gUnk_03005010.unk1E = 0xFF;
            INTR_CHECK |= 0x80;
        }
        INTR_CHECK |= 1;
        REG_IME = 1;
    }
}

INCLUDE_ASM("asm/nonmatching/code_0800025C", vblank_body);

void hblank_irq(void)
{
    gHBlankCallback();
    REG_IF = 2;
}

void nullsub_08000840(void)
{
}

void read_keys(void)
{
    u16 prev;

    gPrevKeys = prev = gHeldKeys;
    gHeldKeys = REG_KEYINPUT ^ 0x3FF;
    gNewKeys = gHeldKeys & ~prev;
    gReleasedKeys = prev & ~gHeldKeys;
    gRepeatKeys = 0;
    if (gNewKeys)
    {
        gRepeatKeys = gNewKeys;
        gKeyRepeatTimer = 16;
    }
    if (gHeldKeys)
    {
        if (gKeyRepeatTimer == 0)
        {
            gRepeatKeys = gNewKeys | gHeldKeys;
            gKeyRepeatTimer = 3;
        }
        else
        {
            gKeyRepeatTimer--;
        }
    }
}

void soft_reset(void)
{
    u32 i;

    if (gUnk_03005030)
    {
        gUnk_03005010.unk4 = 0xFFFF;
        gUnk_03005010.unk6 = -1;
        for (i = 0; i < 8; i++)
        {
            serial_prepare_send_packet(&gUnk_03005010.unk4);
            VBlankIntrWait();
        }
        gUnk_03005030 = 0;
        serial_multiplayer_init();
    }
    VBlankIntrWait();
    REG_BLDCNT = 0xFF;
    REG_BLDY = 0x10;
    REG_SOUNDCNT_X = 0;
    REG_IME = 0;
    hw_reset_init();
    irq_init();
    serial_link_init();
    gGameMode = 3;
    gGameState = 0;
    gGameSubState = 0;
    REG_DMA2CNT_H = 0;
}

u32 check_soft_reset(void)
{
    if ((*(u8 *)&gHeldKeys & 0xF) == 0xF && (*(u8 *)&gNewKeys & 8))
    {
        soft_reset();
        read_keys();
        return 1;
    }
    return 0;
}

void dma1_irq_sound(void)
{
    sound_update_channel_at_690();
}

void dma2_irq_sound(void)
{
    sound_update_channel_at_6d8();
}

void nullsub_080009B4(void)
{
}

void nullsub_080009B8(void)
{
}

u32 lz_decompress_dispatch(const u8 *src, void *dst)
{
    if (src[0] != 'L' || src[1] != 'e')
        return 0;
    if ((u32)dst - 0x04000001 <= 0x03FFFFFE)
        return lz_decompress_custom_08000B14(src, dst);
    else
        return lz_decompress_custom_08000A0C(src, dst, src[2] | (src[3] << 8) | (src[4] << 16));
}

INCLUDE_ASM("asm/nonmatching/code_0800025C", lz_decompress_custom_08000A0C);
INCLUDE_ASM("asm/nonmatching/code_0800025C", lz_decompress_custom_08000B14);

void set_tilemap_and_decompress_bg(u32 x, u32 y, const u8 *src, u32 bgcnt, u16 base)
{
    gTilemapBaseEntry = base;
    lz_decompress_dispatch(src, gDecompressBuffer);
    write_tilemap_to_vram_08000E94(x, y, (struct Tilemap *)gDecompressBuffer, bgcnt);
}

void decompress_to_ewram_buffer(u32 x, u32 y, const u8 *src, u32 bgcnt)
{
    lz_decompress_dispatch(src, gDecompressBuffer);
    load_tilemap_rows_to_vram(x, y, (struct Tilemap *)gDecompressBuffer, bgcnt);
}

void decompress_to_bg_scroll_buffer(const u8 *src, void *dst)
{
    u32 size = lz_decompress_dispatch(src, gDecompressBuffer);
    CpuCopy16(gDecompressBuffer, dst, size);
}

void write_tilemap_to_vram_08000E94(u32 x, u32 y, struct Tilemap *map, u32 bgcnt)
{
    u16 *dst = (u16 *)((((bgcnt >> 8) & 0x1F) * 0x800) + VRAM) + x + y * 32;
    u16 *src = map->data;
    u16 *d; u32 i, j;

    if (((bgcnt & 0xC000) >> 14) & 1)
    {
        copy_tilemap_with_offset_08000F78(dst, map);
    }
    else
    {
for (i = 0; i < map->height; i++) { d = dst + (i << 5); for (j = 0; j < map->width; j++) *d++ = *src++ + gTilemapBaseEntry; }
    }
}

void load_tilemap_rows_to_vram(u32 x, u32 y, struct Tilemap *map, u32 bgcnt)
{
    u32 shift = ((bgcnt & 0xC000) >> 14) + 3;
    u8 *dst = (u8 *)((((bgcnt >> 8) & 0x1F) * 0x800) + VRAM) + x + (y << shift);
    u8 *src = (u8 *)map->data;
    u32 i;
    for (i = 0; i < map->height; i++) { CpuCopy16(src, (u16 *)dst + (i << shift), map->width); src += map->width; }
}

INCLUDE_ASM("asm/nonmatching/code_0800025C", copy_tilemap_with_offset_08000F78);
INCLUDE_ASM("asm/nonmatching/code_0800025C", set_bg2_affine_transform);
INCLUDE_ASM("asm/nonmatching/code_0800025C", compute_bg_affine_scanline_params);
INCLUDE_ASM("asm/nonmatching/code_0800025C", hblank_dma0_bg2affine);

u32 rng_next(u16 range)
{
    gRngCounter++;
    gRngValue = gRngTable[gRngCounter & 0xF] ^ gRngState;
    { u32 n = ~gRngValue; u32 t = ((s16 *)&gRngState)[1] + 0x55555555; gRngState = n + t; }
    if (range == 0) return gRngValue;
    return (u32)(((s16 *)&gRngValue)[1] * range) >> 16;
}

// Linear interpolation in 4.12 fixed point: a at t = 0, b at t = 0x1000. Not called.
s32 sub_0800134C(s32 a, s32 b, s32 t)
{
    return b * t / 4096 + a * (4096 - t) / 4096;
}

void copy_obj_palette_to_buffer(void)
{
    CpuFastSet((void *)OBJ_PLTT, gPaletteBackup, 0x80);
    CpuFastSet((void *)PLTT, gPaletteBackupBg, 0x80);
}

INCLUDE_ASM("asm/nonmatching/code_0800025C", palette_blend_to_color_080013A8);

void dma_obj_palette_to_hardware(void)
{
    CpuFastSet(gPaletteBuffer, (void *)OBJ_PLTT, 0x80);
    CpuFastSet(gPaletteBufferBg, (void *)PLTT, 0x80);
}

INCLUDE_ASM("asm/nonmatching/code_0800025C", palette_blend_16_colors);
INCLUDE_ASM("asm/nonmatching/code_0800025C", check_flag_and_fast_copy);
INCLUDE_ASM("asm/nonmatching/code_0800025C", set_oam_affine_params);
INCLUDE_ASM("asm/nonmatching/code_0800025C", compute_scaled_value);
INCLUDE_ASM("asm/nonmatching/code_0800025C", rotate_vector_2d);
INCLUDE_ASM("asm/nonmatching/code_0800025C", shell_sort_by_second_byte);
INCLUDE_ASM("asm/nonmatching/code_0800025C", serial_link_init);

void sub_08002190(void)
{
    if (gUnk_03005170.unk0)
        gUnk_03005170.unk6 = 1;
}

INCLUDE_ASM("asm/nonmatching/code_0800025C", serial_multiplayer_init);
INCLUDE_ASM("asm/nonmatching/code_0800025C", serial_link_init_and_status);
INCLUDE_ASM("asm/nonmatching/code_0800025C", serial_prepare_send_packet);
INCLUDE_ASM("asm/nonmatching/code_0800025C", serial_link_receive_packets);
INCLUDE_ASM("asm/nonmatching/code_0800025C", sub_080023D8);
INCLUDE_ASM("asm/nonmatching/code_0800025C", serial_multiplayer_transfer_handler);

void dispatch_game_state_handler_08002534(void)
{
    gGameStateHandlers_083AC148[gGameState]();
}

void dispatch_game_substate_handler_08002554(void)
{
    gUnk_083AC248[gGameSubState]();
}

INCLUDE_ASM("asm/nonmatching/code_0800025C", sub_08002574);

// guess: debug map viewer input (D-pad scrolls gUnk_03004C30, START/SELECT open text windows)
void sub_080025B4(void)
{
    if (KEYS_LO(gHeldKeys) & 0x40)
        gUnk_03004C30.y++;
    if (KEYS_LO(gHeldKeys) & 0x80)
        gUnk_03004C30.y--;
    if (KEYS_LO(gHeldKeys) & 0x20)
        gUnk_03004C30.x++;
    if (KEYS_LO(gHeldKeys) & 0x10)
        gUnk_03004C30.x--;
    if (KEYS_LO(gNewKeys) & 2)
        gUnk_03000440.unk88 ^= 1;
    if (KEYS_LO(gNewKeys) & 1)
    {
        gUnk_03000440.unkE = 0;
        gGameSubState++;
        gUnk_03000440.unk85 ^= 1;
    }
    if (KEYS_LO(gNewKeys) & 2)
    {
        gGameState = 1;
        gGameSubState = 0;
    }
    if (KEYS_LO(gNewKeys) & 8)
    {
        text_window_init(0, 0, 0);
        gGameSubState += 2;
    }
    if (KEYS_LO(gNewKeys) & 4)
    {
        text_window_init(0, 0, 0);
        gGameSubState += 3;
    }
}

void load_overworld_column_and_advance(void)
{
    u8 r = load_overworld_map_column(0, 1, 8, 4, gUnk_03000440.unk88, gUnk_03000440.unk85);
    if (r == 1)
        gGameSubState = r;
}

void init_save_prompt_text(void)
{
    u8 r;

    gUnk_03002B70.unk4[0] = 0x17;
    gUnk_03002B70.unk4[1] = 0x29;
    gUnk_03002B70.unk4[2] = 0x2C;
    gUnk_03002B70.unk4[3] = 0x25;
    gUnk_03002B70.unk4[4] = 0;
    gUnk_03002B70.unk4[5] = 0x2E;
    gUnk_03002B70.unk4[6] = 0x1F;
    gUnk_03002B70.unk4[7] = 0x2D;
    gUnk_03002B70.unk4[8] = 0x2E;
    gUnk_03002B70.unk4[9] = 0xFE;
    r = run_message(gUnk_083B53F8[0]);
    if (r == 1)
        gGameSubState = r;
}

void sub_08002730(void)
{
    if (run_message(gUnk_083B53F8[1]))
    {
        open_choice_menu(0, 0x16, 7);
        gGameSubState++;
    }
}

void sub_0800275C(void)
{
    if (poll_choice_menu())
    {
        sub_0803FB0C();
        gGameSubState++;
    }
}

void sub_0800277C(void)
{
    const void *msg;

    if (gUnk_03000440.unk28 & 0xF0)
        msg = gUnk_083B53F8[3];
    else
        msg = gUnk_083B53F8[2];
    if (run_message(msg))
        gGameSubState = 1;
}

// Game state 1: the field pause menu (Medawatch / Item / Vehicle / Save, money display).
void field_menu_update(void)
{
    gFieldMenuHandlers[gGameSubState]();
}

void field_menu_load_gfx(void)
{
    REG_DISPCNT = 0x1F60;
    REG_BG0CNT = 0x500;
    lz_decompress_dispatch(gUnk_084C1608, (void *)0x06001800);
    lz_decompress_dispatch(gUnk_084C17F0, (void *)0x06001B00);
    lz_decompress_dispatch(gUnk_084C1934, (void *)0x06001E00);
    lz_decompress_dispatch(gUnk_084C1ACC, (void *)0x06002100);
    lz_decompress_dispatch(gUnk_08487708, (void *)0x06002400);
    DmaSet(3, gUnk_08488A84, 0x050001E0, 0x80000010);
    lz_decompress_dispatch(gUnk_084C6A98, (void *)0x06017400);
    DmaSet(3, gUnk_084E2E38, 0x050003E0, 0x80000010);
    play_song(6);
    gUnk_03000440.unk84 = 0;
    gGameSubState++;
}

void field_menu_open_anim(void)
{
    if (gUnk_03000440.unk84 <= 12)
        write_tilemap_rect(12, 2, 18, 1, gUnk_083B4AE0[gUnk_03000440.unk84 + 0x13], REG_BG0CNT, 0);
    if ((u8)(gUnk_03000440.unk84 - 2) <= 12)
        write_tilemap_rect(12, 2, 18, 3, gUnk_083B4AE0[gUnk_03000440.unk84 + 0x1E], REG_BG0CNT, 0);
    if ((u8)(gUnk_03000440.unk84 - 4) <= 12)
        write_tilemap_rect(12, 2, 18, 5, gUnk_083B4AE0[gUnk_03000440.unk84 + 0x29], REG_BG0CNT, 0);
    if ((u8)(gUnk_03000440.unk84 - 6) <= 12)
        write_tilemap_rect(12, 2, 18, 7, gUnk_083B4AE0[gUnk_03000440.unk84 + 0x34], REG_BG0CNT, 0);
    if (gUnk_03000440.unk84 == 10)
    {
        lz_decompress_dispatch(gUnk_08487814, (void *)0x06002400);
        set_tilemap_and_decompress_bg(0x15, 9, gUnk_08488690, REG_BG0CNT, 0x120);
    }
    if (gUnk_03000440.unk84 == 12)
    {
        lz_decompress_dispatch(gUnk_08487708, (void *)0x06002400);
        set_tilemap_and_decompress_bg(0x15, 9, gUnk_08488644, REG_BG0CNT, 0x120);
    }
    if (++gUnk_03000440.unk84 > 18)
    {
        divide_by_10000(gUnk_03000440.unk9E, gUnk_03002B70.money);
        render_text_sprites_08040DB8(gUnk_03000440.unk9E, 10, 0x17, 10, 5, 15, 2, 0);
        gUnk_03000440.unk8E = 0;
        field_menu_init_cursor();
        gGameSubState++;
    }
}

void field_menu_handle_input(void)
{
    process_sprite_anim_commands(gUnk_083B5F80[0], 0);
    if (KEYS_LO(gRepeatKeys) & 0x40)
    {
        play_sound_effect(2);
        gUnk_03000440.unk8E = (gUnk_03000440.unk8E - 1) & 3;
        gUnk_03002C30[0].unk4 = gUnk_03000440.unk8E * 16 + 8;
    }
    if (KEYS_LO(gRepeatKeys) & 0x80)
    {
        play_sound_effect(2);
        gUnk_03000440.unk8E = (gUnk_03000440.unk8E + 1) & 3;
        gUnk_03002C30[0].unk4 = gUnk_03000440.unk8E * 16 + 8;
    }
    if (KEYS_LO(gNewKeys) & 2)
    {
        sound_stop_all_with_fade_guard(0x10);
        play_sound_effect(5);
        clear_battle_sprite_slot(0, 1);
        clear_battle_sprite_slot(10, 7);
        gUnk_03000440.unk84 = 0;
        gGameSubState = 3;
    }
    else if (KEYS_LO(gNewKeys) & 1)
    {
        play_sound_effect(4);
        gGameSubState = 6;
    }
}

void field_menu_close_anim(void)
{
    if (gUnk_03000440.unk84 <= 12)
        write_tilemap_rect(12, 2, 18, 1, gUnk_083B4AE0[0x1F - gUnk_03000440.unk84], REG_BG0CNT, 0);
    if ((u8)(gUnk_03000440.unk84 - 2) <= 12)
        write_tilemap_rect(12, 2, 18, 3, gUnk_083B4AE0[0x2E - gUnk_03000440.unk84], REG_BG0CNT, 0);
    if ((u8)(gUnk_03000440.unk84 - 4) <= 12)
        write_tilemap_rect(12, 2, 18, 5, gUnk_083B4AE0[0x3D - gUnk_03000440.unk84], REG_BG0CNT, 0);
    if ((u8)(gUnk_03000440.unk84 - 6) <= 12)
        write_tilemap_rect(12, 2, 18, 7, gUnk_083B4AE0[0x4C - gUnk_03000440.unk84], REG_BG0CNT, 0);
    if (gUnk_03000440.unk84 == 10)
    {
        lz_decompress_dispatch(gUnk_08487814, (void *)0x06002400);
        set_tilemap_and_decompress_bg(0x15, 9, gUnk_08488690, REG_BG0CNT, 0x120);
    }
    if (gUnk_03000440.unk84 == 12)
        vram_fill_tilemap_rect(9, 4, 0x15, 9, REG_BG0CNT, 0);
    if (++gUnk_03000440.unk84 > 18)
        sub_08044094();
}

void field_menu_select_start(void)
{
    switch (gUnk_03000440.unk8E)
    {
    case 0:
        vram_fill_tilemap_rect(13, 10, 17, 3, REG_BG0CNT, 0);
        gUnk_03000440.unk88 = 1;
        break;
    case 1:
        vram_fill_tilemap_rect(13, 2, 17, 1, REG_BG0CNT, 0);
        vram_fill_tilemap_rect(13, 8, 17, 5, REG_BG0CNT, 0);
        gUnk_03000440.unk88 = 3;
        break;
    case 2:
        vram_fill_tilemap_rect(13, 4, 17, 1, REG_BG0CNT, 0);
        vram_fill_tilemap_rect(13, 6, 17, 7, REG_BG0CNT, 0);
        gUnk_03000440.unk88 = 5;
        break;
    default:
        vram_fill_tilemap_rect(13, 6, 17, 1, REG_BG0CNT, 0);
        vram_fill_tilemap_rect(13, 4, 17, 9, REG_BG0CNT, 0);
        gUnk_03000440.unk88 = 7;
        break;
    }
    clear_battle_sprite_slot(0, 1);
    clear_battle_sprite_slot(10, 7);
    gGameSubState++;
}

void field_menu_select_collapse(void)
{
    write_tilemap_rect(12, 2, 18, gUnk_03000440.unk88 - 1, gUnk_083B4AE0[gUnk_03000440.unk8E * 13 + 0x1F], REG_BG0CNT, 0);
    vram_fill_tilemap_rect(12, 1, 18, gUnk_03000440.unk88 + 1, REG_BG0CNT, 0);
    if (--gUnk_03000440.unk88 == 0)
    {
        lz_decompress_dispatch(gUnk_084C1C14, (void *)0x060017E0);
        copy_obj_palette_to_buffer();
        gUnk_03000440.unk84 = 0;
        if (gUnk_03000440.unk8E == 0)
            sound_stop_all_with_fade_guard(0x10);
        gGameSubState++;
    }
}

void field_menu_select_slide(void)
{
    if (gUnk_03000440.unk8E != 2 && gUnk_03000440.unk84 <= 16)
    {
        blend_obj_palettes_to_color_0803F684(0, gUnk_03000440.unk84 * 2, 0x1FFF);
        blend_obj_palettes_to_color_0803F998(0, gUnk_03000440.unk84 * 2, 0xFFFF);
        gUnk_03000440.unk84++;
    }
    write_tilemap_rect(12, 2, 18 - gUnk_03000440.unk88, 0, gUnk_083B4AE0[gUnk_03000440.unk8E * 13 + 0x1F], REG_BG0CNT, 0);
    write_tilemap_rect(1, 2, 30 - gUnk_03000440.unk88, 0, gUnk_083B4AE0[0x47], REG_BG0CNT, 0);
    if (++gUnk_03000440.unk88 == 19)
        gGameSubState++;
}

// Runs the chosen entry: Medawatch (game state 2), Item (mode 2 state 4), Vehicle, Save (mode 2 state 5).
void field_menu_run_choice(void)
{
    switch (gUnk_03000440.unk8E)
    {
    case 0:
        play_song(7);
        gUnk_03000440.unk8F = 0;
        gGameState = 2;
        gGameSubState = 0;
        clear_battle_sprite_slot(0x28, 0x57);
        break;
    case 1:
        gGameMode = 2;
        gGameState = 4;
        gGameSubState = 0;
        clear_battle_sprite_slot(0x28, 0x57);
        break;
    case 2:
        sub_0804765C(1);
        break;
    default:
        gUnk_03000588 = 0;
        gGameMode = 2;
        gGameState = 5;
        gGameSubState = 0;
        clear_battle_sprite_slot(0x28, 0x57);
        break;
    }
}

void field_menu_return_init(void)
{
    gUnk_03000588 = 1;
    if (gUnk_03000440.unk8E != 2)
    {
        REG_DISPCNT &= 0xF1FF;
        DmaSet(3, gUnk_084E2E38, 0x0202F9E0, 0x84000008);
        update_battle_field_frame();
        sub_080487E4();
        setup_blend_effect(0x40, 0x2F00, 5, 16, 16, 16, 12, 10, 0);
        REG_DISPCNT |= 0xF60;
    }
    gUnk_03000440.unk88 = 18;
    gUnk_03000440.unk84 = 0;
    gGameSubState++;
}

void field_menu_return_slide(void)
{
    if (gUnk_03000440.unk8E != 2 && gUnk_03000440.unk84 <= 16)
    {
        blend_effect_update();
        blend_obj_palettes_to_color_0803F684(0, 32 - gUnk_03000440.unk84 * 2, 0x1FFF);
        blend_obj_palettes_to_color_0803F998(0, 32 - gUnk_03000440.unk84 * 2, 0xFFFF);
        gUnk_03000440.unk84++;
    }
    gUnk_03000440.unk88--;
    write_tilemap_rect(12, 2, 18 - gUnk_03000440.unk88, 0, gUnk_083B4AE0[gUnk_03000440.unk8E * 13 + 0x1F], REG_BG0CNT, 0);
    vram_fill_tilemap_rect(1, 2, 17 - gUnk_03000440.unk88, 0, REG_BG0CNT, 0);
    if (gUnk_03000440.unk88 == 0)
    {
        gVBlankCallback = nullsub_08000840;
        gUnk_03000440.unk88 = gUnk_03000440.unk8E * 2 + 1;
        gUnk_03000440.unk84 = 0;
        gGameSubState++;
    }
}

void field_menu_return_expand(void)
{
    write_tilemap_rect(12, 2, 18, gUnk_03000440.unk84 + 1, gUnk_083B4AE0[gUnk_03000440.unk8E * 13 + 0x1F], REG_BG0CNT, 0);
    vram_fill_tilemap_rect(12, 1, 18, gUnk_03000440.unk84, REG_BG0CNT, 0);
    if (gUnk_03000440.unk84 + 1 == gUnk_03000440.unk88)
    {
        switch (gUnk_03000440.unk8E)
        {
        case 0:
            write_tilemap_rect(12, 2, 18, 3, gUnk_083B4AE0[0x2C], REG_BG0CNT, 0);
            write_tilemap_rect(12, 2, 18, 5, gUnk_083B4AE0[0x39], REG_BG0CNT, 0);
            write_tilemap_rect(12, 2, 18, 7, gUnk_083B4AE0[0x46], REG_BG0CNT, 0);
            break;
        case 1:
            write_tilemap_rect(12, 2, 18, 1, gUnk_083B4AE0[0x1F], REG_BG0CNT, 0);
            write_tilemap_rect(12, 2, 18, 5, gUnk_083B4AE0[0x39], REG_BG0CNT, 0);
            write_tilemap_rect(12, 2, 18, 7, gUnk_083B4AE0[0x46], REG_BG0CNT, 0);
            break;
        case 2:
            write_tilemap_rect(12, 2, 18, 1, gUnk_083B4AE0[0x1F], REG_BG0CNT, 0);
            write_tilemap_rect(12, 2, 18, 3, gUnk_083B4AE0[0x2C], REG_BG0CNT, 0);
            write_tilemap_rect(12, 2, 18, 7, gUnk_083B4AE0[0x46], REG_BG0CNT, 0);
            break;
        default:
            write_tilemap_rect(12, 2, 18, 1, gUnk_083B4AE0[0x1F], REG_BG0CNT, 0);
            write_tilemap_rect(12, 2, 18, 3, gUnk_083B4AE0[0x2C], REG_BG0CNT, 0);
            write_tilemap_rect(12, 2, 18, 5, gUnk_083B4AE0[0x39], REG_BG0CNT, 0);
            break;
        }
        set_tilemap_and_decompress_bg(0x15, 9, gUnk_08488644, REG_BG0CNT, 0x120);
        divide_by_10000(gUnk_03000440.unk9E, gUnk_03002B70.money);
        render_text_sprites_08040DB8(gUnk_03000440.unk9E, 10, 0x17, 10, 5, 15, 2, 0);
        field_menu_init_cursor();
        gGameSubState = 2;
    }
    else
    {
        gUnk_03000440.unk84++;
    }
}

void field_menu_init_cursor(void)
{
    lz_decompress_dispatch(gUnk_084C7174, (void *)0x06016C00);
    DmaSet(3, gUnk_084E2E58, 0x050003C0, 0x84000008);
    gUnk_03002C30[0].unk0 = 0xC004;
    gUnk_03002C30[0].unk2 = 0x88;
    gUnk_03002C30[0].unk4 = gUnk_03000440.unk8E * 16 + 8;
    gUnk_03002C30[0].unkA = 14;
    gUnk_03002C30[0].unk1C = 0;
    gUnk_03002C30[0].unkB = 0xFF;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0], 0);
}

void dispatch_game_substate_handler_08003374(void)
{
    gUnk_083AC2D4[gGameSubState]();
}

void setup_bg_layers_and_decompress(void)
{
    sub_080415BC();
    REG_DISPCNT &= 0xF1FF;
    REG_BG1CNT = 0x1805;
    REG_BG2CNT = 0x1906;
    REG_BG3CNT = 0x1A07;
    lz_decompress_dispatch(gUnk_084E30D8, (void *)0x06004000);
    sub_08003904();
    set_tilemap_and_decompress_bg(0, 0, gUnk_084EF6A0, REG_BG1CNT, 0);
    set_tilemap_and_decompress_bg(0, 0, gUnk_084F023C, REG_BG2CNT, 0);
    set_tilemap_and_decompress_bg(0, 0, gUnk_084F0F2C, REG_BG3CNT, 0);
    DmaSet(3, gUnk_084F24E0, 0x0202FA00, 0x84000060);
    write_tilemap_rect(4, 4, 5, 9, gUnk_083B4AE0[0x48], REG_BG1CNT, 0);
    REG_DISPCNT |= 0x1F60;
    gUnk_03000440.unk84 = 0;
    gGameSubState++;
}

void sub_080034A4(void)
{
    sub_080039BC();
    if (gUnk_03000440.unk84 <= 8)
    {
        blend_obj_palettes_to_color_0803F684(0, 32 - gUnk_03000440.unk84 * 4, 0x1FFF);
        blend_obj_palettes_to_color_0803F998(0, 32 - gUnk_03000440.unk84 * 4, 0xFFFF);
        gUnk_03000440.unk84++;
    }
    else
    {
        sub_0800393C();
        gGameSubState++;
    }
}

void sub_08003504(void)
{
    sub_080039BC();
    process_sprite_anim_commands(gUnk_083B5F80[0], 0);
    if (KEYS_LO(gRepeatKeys) & 0x40)
    {
        if (gUnk_03000440.unk8F == 0)
            gUnk_03000440.unk8F = 2;
        else
            gUnk_03000440.unk8F--;
        play_sound_effect(2);
        sub_08003904();
        gUnk_03002C30[0].unk2 = 0x88 - gUnk_03000440.unk8F * 8;
        gUnk_03002C30[0].unk4 = gUnk_03000440.unk8F * 24 + 32;
    }
    if (KEYS_LO(gRepeatKeys) & 0x80)
    {
        if (gUnk_03000440.unk8F == 2)
            gUnk_03000440.unk8F = 0;
        else
            gUnk_03000440.unk8F++;
        play_sound_effect(2);
        sub_08003904();
        gUnk_03002C30[0].unk2 = 0x88 - gUnk_03000440.unk8F * 8;
        gUnk_03002C30[0].unk4 = gUnk_03000440.unk8F * 24 + 32;
    }
    if (KEYS_LO(gNewKeys) & 2)
    {
        play_sound_effect(5);
        gGameSubState++;
    }
    if (KEYS_LO(gNewKeys) & 1)
    {
        play_sound_effect(4);
        init_battle_sprite_entry_08040B90(gUnk_083B5F80[1], 0);
        set_blend_effect_mode(6, 0x3F, 0x20);
        gUnk_03000440.unk84 = 0;
        gGameSubState = 8;
    }
}

void sub_08003620(void)
{
    sub_080039BC();
    clear_battle_sprite_slot(0, 1);
    copy_obj_palette_to_buffer();
    gUnk_03000440.unk84 = 0;
    sound_stop_all_with_fade_guard(8);
    gGameSubState++;
}

void sub_08003654(void)
{
    sub_080039BC();
    if (gUnk_03000440.unk84 <= 8)
    {
        blend_obj_palettes_to_color_0803F684(0, gUnk_03000440.unk84 * 4, 0x1FFF);
        blend_obj_palettes_to_color_0803F998(0, gUnk_03000440.unk84 * 4, 0xFFFF);
        gUnk_03000440.unk84++;
    }
    else
    {
        gGameSubState++;
    }
}

void sub_080036A8(void)
{
    play_song(6);
    gGameState = 1;
    gGameSubState = 16;
}

void sub_080036C8(void)
{
    sub_080039BC();
    process_sprite_anim_commands(gUnk_083B5F80[1], 0);
    if (update_blend_effect())
        gGameSubState++;
}

void sub_080036F4(void)
{
    DmaSet(3, 0x06002800, gUnk_02020800, 0x84000200);
    switch (gUnk_03000440.unk8F)
    {
    case 0:
        sub_0803F624((u8 *)&gUnk_03000440 + 0x50, 0x14, 0);
        gGameState = 3;
        gGameSubState = 0;
        break;
    case 1:
        sub_0803F624((u8 *)&gUnk_03000440 + 0x3C, 0x14, 0);
        gGameState = 4;
        gGameSubState = 0;
        break;
    default:
        sub_0803F624((u8 *)&gUnk_03000440 + 0x3C, 0x14, 0);
        gGameState = 5;
        gGameSubState = 0;
        break;
    }
}

void sub_08003784(void)
{
    sub_080415BC();
    REG_DISPCNT &= 0xF0FF;
    REG_BG1CNT = 0x500;
    REG_BG1CNT = 0x1805;
    REG_BG2CNT = 0x1906;
    REG_BG3CNT = 0x1A07;
    lz_decompress_dispatch(gUnk_084E30D8, (void *)0x06004000);
    sub_08003904();
    DmaSet(3, gUnk_02020800, 0x06002800, 0x84000200);
    set_tilemap_and_decompress_bg(0, 0, gUnk_084EF6A0, REG_BG1CNT, 0);
    set_tilemap_and_decompress_bg(0, 0, gUnk_084F023C, REG_BG2CNT, 0);
    set_tilemap_and_decompress_bg(0, 0, gUnk_084F0F2C, REG_BG3CNT, 0);
    DmaSet(3, gUnk_084F24E0, 0x05000000, 0x84000060);
    write_tilemap_rect(4, 4, 5, 9, gUnk_083B4AE0[0x48], REG_BG1CNT, 0);
    REG_DISPCNT |= 0x1F60;
    set_blend_effect_mode(5, 0x3F, 0x20);
    gUnk_03000440.unk84 = 0;
    gGameSubState++;
}

void sub_080038CC(void)
{
    sub_080039BC();
    if (update_blend_effect())
    {
        sub_0800393C();
        gGameSubState++;
    }
}

void sub_080038F0(void)
{
    sub_080039BC();
    gGameSubState = 2;
}

void sub_08003904(void)
{
    const u8 *src;

    switch (gUnk_03000440.unk8F)
    {
    case 0:
        src = gUnk_084C1C24;
        break;
    case 1:
        src = gUnk_084C1E04;
        break;
    default:
        src = gUnk_084C1FD4;
        break;
    }
    lz_decompress_dispatch(src, (void *)0x06007E00);
}

void sub_0800393C(void)
{
    lz_decompress_dispatch(gUnk_084C7174, (void *)0x06016C00);
    DmaSet(3, gUnk_084E2E58, 0x050003C0, 0x84000008);
    gUnk_03002C30[0].unk0 = 0xC004;
    gUnk_03002C30[0].unk2 = 0x88 - gUnk_03000440.unk8F * 8;
    gUnk_03002C30[0].unk4 = gUnk_03000440.unk8F * 24 + 32;
    gUnk_03002C30[0].unkA = 14;
    gUnk_03002C30[0].unk1C = 0;
    gUnk_03002C30[0].unkB = 0xFF;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0], 0);
}

void sub_080039BC(void)
{
    if (gFrameCounter & 1)
    {
        gUnk_03001C04.x--;
        gUnk_03001C04.y++;
    }
}

void sub_080039E0(void)
{
    if (sub_0803EED8() == 0)
    {
        if (gUnk_03000430 == 2)
        {
            u32 fill = 0x200;
            CpuFastSet(&fill, gUnk_03002414->unkB84, 0x01000100);
        }
        gUnk_083AC320[gGameSubState]();
    }
}

void sub_08003A38(void)
{
    u32 zero;

    switch (gUnk_03000440.unk139)
    {
    case 0:
        sub_08043CA8();
        if (gUnk_03000440.unk56 == 1)
            setup_overworld_scene_from_position();
        REG_DISPCNT &= 0xF0FF;
        REG_BG0CNT = 0x500;
        REG_BG1CNT = 0x1801;
        REG_BG2CNT = 0x1902;
        REG_BG3CNT = 0x1A03;
        lz_decompress_dispatch(gUnk_084E5650, (void *)0x06004000);
        lz_decompress_dispatch(gUnk_084C48B4, (void *)0x06006000);
        lz_decompress_dispatch(gUnk_084C4A34, (void *)0x06006200);
        lz_decompress_dispatch(gUnk_084C7428, (void *)0x06016C00);
        lz_decompress_dispatch(gUnk_084C6A98, (void *)0x06017400);
        gUnk_03000440.unk139++;
        break;
    case 1:
        if (gUnk_03000440.unk56 == 1)
            setup_overworld_scene_from_position();
        set_tilemap_and_decompress_bg(0, 0, gUnk_084EF2D8, REG_BG0CNT, 0x200);
        set_tilemap_and_decompress_bg(0, 0, gUnk_084EF95C, REG_BG1CNT, 0x200);
        set_tilemap_and_decompress_bg(0, 0, gUnk_084F02B8, REG_BG2CNT, 0x200);
        set_tilemap_and_decompress_bg(0, 0, gUnk_084F122C, REG_BG3CNT, 0x200);
        if (gUnk_03000440.unk56 == 1)
        {
            CpuFastSet(gUnk_084F2680, gPaletteBackupBg, 0x60);
            CpuFastSet(gUnk_0850DEF8, gPaletteBackup, 0x40);
            CpuFastSet(gUnk_0850DD18, (void *)0x0202F9A0, 8);
            CpuFastSet(gUnk_0850DD18 + 0x10, (void *)0x0202F9C0, 8);
            CpuFastSet(gUnk_084E2EB8, (void *)0x0202F980, 8);
            CpuFastSet(gUnk_084E2ED8, (void *)0x0202F9E0, 8);
            gUnk_03000440.unk84 = 0;
        }
        else
        {
            CpuFastSet(gUnk_084F2680, (void *)0x05000000, 0x60);
            CpuFastSet(gUnk_0850DEF8, (void *)0x05000200, 0x40);
            CpuFastSet(gUnk_0850DD18, (void *)0x050003A0, 8);
            CpuFastSet(gUnk_0850DD18 + 0x10, (void *)0x050003C0, 8);
            CpuFastSet(gUnk_084E2EB8, (void *)0x05000380, 8);
            CpuFastSet(gUnk_084E2ED8, (void *)0x050003E0, 8);
            set_blend_effect_mode(5, 0x3F, 0x20);
        }
        zero = 0;
        CpuFastSet(&zero, gUnk_03002C30, 0x01000800);
        REG_DISPCNT |= 0x1F40;
        REG_DISPCNT &= 0xFFDF;
        gUnk_03000440.unk139++;
        break;
    case 2:
        if (gUnk_03000440.unk56 == 1)
            setup_overworld_scene_from_position();
        gUnk_03000440.unk96 = 1;
        sub_08004FD0();
        sub_08005000();
        sub_08004E98();
        sub_0800508C();
        sub_08005118();
        sub_0800519C();
        sub_0800522C();
        sub_08005948();
        sub_0800750C();
        if (gUnk_03000440.unk56 == 0)
        {
            sub_0800529C();
            if (gUnk_03000440.unk50 == 3)
                play_song(7);
        }
        else if (gUnk_03000440.unk52 & 0x80)
        {
            sub_08005628();
        }
        gGameSubState++;
        gUnk_03000440.unk139 = 0;
        break;
    }
}

void sub_08003D4C(void)
{
    struct Unk_03000440 *s;
    u8 *flag;

    sub_08004E74();
    update_battle_sprite_orbit_clockwise(0);
    update_battle_sprite_orbit_clockwise(1);
    update_battle_sprite_orbit_clockwise(2);
    update_battle_sprite_orbit_clockwise(3);
    setup_overworld_scene_from_position();
    update_battle_icon_blink_and_orbit();
    check_and_update_battle_sprite_orbit();
    s = &gUnk_03000440;
    flag = &s->unk56;
    if (*flag == 1)
    {
        if (s->unk84 > 8)
            goto done;
        blend_obj_palettes_to_color_0803F684(0, 32 - s->unk84 * 4, 0xFFFF);
        blend_obj_palettes_to_color_0803F998(0, 32 - s->unk84 * 4, 0xF0FF);
        s->unk84++;
    }
    else if (update_blend_effect())
    {
    done:
        *flag = 0;
        gGameSubState++;
    }
}

void sub_08003DE0(void)
{
    sub_08004E74();
    update_battle_sprite_orbit_clockwise(0);
    update_battle_sprite_orbit_clockwise(1);
    update_battle_sprite_orbit_clockwise(2);
    update_battle_sprite_orbit_clockwise(3);
    setup_overworld_scene_from_position();
    update_battle_icon_blink_and_orbit();
    check_and_update_battle_sprite_orbit();
    sub_0800712C();
    if (sub_080058A4() == 0 && sub_08005588() == 0)
    {
        if (KEYS_LO(gNewKeys) & 2)
            sub_0800725C();
        else if (KEYS_LO(gNewKeys) & 1)
            team_select_confirm_pick();
        else if (KEYS_LO(gNewKeys) & 8)
            battle_play_alert_sound();
    }
}

void sub_08003E54(void)
{
    sub_08004E74();
    update_battle_sprite_orbit_clockwise(0);
    update_battle_sprite_orbit_clockwise(1);
    update_battle_sprite_orbit_clockwise(2);
    update_battle_sprite_orbit_clockwise(3);
    setup_overworld_scene_from_position();
    check_and_update_battle_sprite_orbit();
    set_blend_effect_mode(6, 0x3F, 0x20);
    gUnk_03000440.unk84 = 0;
    gGameSubState++;
}

void sub_08003EA0(void)
{
    sub_08004E74();
    update_battle_sprite_orbit_clockwise(0);
    update_battle_sprite_orbit_clockwise(1);
    update_battle_sprite_orbit_clockwise(2);
    update_battle_sprite_orbit_clockwise(3);
    setup_overworld_scene_from_position();
    check_and_update_battle_sprite_orbit();
    if (update_blend_effect())
        gGameSubState++;
}

void sub_08003EE0(void)
{
    CpuFastSet(gUnk_084E2E38, (void *)0x050003E0, 8);
    clear_battle_sprite_slot(0, 0x80);
    gUnk_03000440.unk96 = 0;
    gUnk_03000430 = 0;
    gGameState = 2;
    gGameSubState = 16;
}

void sub_08003F28(void)
{
    sub_08004E74();
    update_battle_sprite_orbit_clockwise(0);
    update_battle_sprite_orbit_clockwise(1);
    update_battle_sprite_orbit_clockwise(2);
    update_battle_sprite_orbit_clockwise(3);
    setup_overworld_scene_from_position();
    update_battle_icon_blink_and_orbit();
    check_and_update_battle_sprite_orbit();
    copy_obj_palette_to_buffer();
    gUnk_03000440.unk84 = 0;
    gGameSubState++;
}

void sub_08003F74(void)
{
    sub_08004E74();
    update_battle_sprite_orbit_clockwise(0);
    update_battle_sprite_orbit_clockwise(1);
    update_battle_sprite_orbit_clockwise(2);
    update_battle_sprite_orbit_clockwise(3);
    setup_overworld_scene_from_position();
    update_battle_icon_blink_and_orbit();
    check_and_update_battle_sprite_orbit();
    if (gUnk_03000440.unk84 <= 8)
    {
        blend_obj_palettes_to_color_0803F684(0, gUnk_03000440.unk84 * 4, 0xFFFF);
        blend_obj_palettes_to_color_0803F998(0, gUnk_03000440.unk84 * 4, 0xF0FF);
        gUnk_03000440.unk84++;
    }
    else
    {
        gGameSubState = 16;
    }
}

void sub_08003FE8(void)
{
    sub_08004E74();
    update_battle_sprite_orbit_clockwise(0);
    update_battle_sprite_orbit_clockwise(1);
    update_battle_sprite_orbit_clockwise(2);
    update_battle_sprite_orbit_clockwise(3);
    setup_overworld_scene_from_position();
    check_and_update_battle_sprite_orbit();
    text_window_init(1, 2, 0);
    gGameSubState++;
}

void sub_08004028(void)
{
    sub_08004E74();
    update_battle_sprite_orbit_clockwise(0);
    update_battle_sprite_orbit_clockwise(1);
    update_battle_sprite_orbit_clockwise(2);
    update_battle_sprite_orbit_clockwise(3);
    setup_overworld_scene_from_position();
    check_and_update_battle_sprite_orbit();
    if (run_message(gUnk_083B53F8[22]))
        gGameSubState = 2;
}

INCLUDE_ASM("asm/nonmatching/code_0800025C", sub_0800406C);
