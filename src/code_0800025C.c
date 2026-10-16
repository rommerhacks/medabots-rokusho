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

INCLUDE_ASM("asm/nonmatching/code_0800025C", dispatch_game_substate_handler_08002554);
INCLUDE_ASM("asm/nonmatching/code_0800025C", sub_080025B4);
INCLUDE_ASM("asm/nonmatching/code_0800025C", load_overworld_column_and_advance);
INCLUDE_ASM("asm/nonmatching/code_0800025C", init_save_prompt_text);
INCLUDE_ASM("asm/nonmatching/code_0800025C", advance_substate_with_sound);
INCLUDE_ASM("asm/nonmatching/code_0800025C", sub_0800275C);
INCLUDE_ASM("asm/nonmatching/code_0800025C", sub_0800277C);
INCLUDE_ASM("asm/nonmatching/code_0800025C", sub_080027BC);
INCLUDE_ASM("asm/nonmatching/code_0800025C", sub_080027DC);
INCLUDE_ASM("asm/nonmatching/code_0800025C", sub_080028AC);
INCLUDE_ASM("asm/nonmatching/code_0800025C", sub_08002A2C);
INCLUDE_ASM("asm/nonmatching/code_0800025C", sub_08002AF8);
INCLUDE_ASM("asm/nonmatching/code_0800025C", sub_08002C34);
INCLUDE_ASM("asm/nonmatching/code_0800025C", sub_08002D48);
INCLUDE_ASM("asm/nonmatching/code_0800025C", sub_08002DF4);
INCLUDE_ASM("asm/nonmatching/code_0800025C", sub_08002EC4);
INCLUDE_ASM("asm/nonmatching/code_0800025C", init_battle_display_and_palette);
INCLUDE_ASM("asm/nonmatching/code_0800025C", update_screen_fade_transition);
INCLUDE_ASM("asm/nonmatching/code_0800025C", render_shop_menu_screen);
INCLUDE_ASM("asm/nonmatching/code_0800025C", sub_08003300);
INCLUDE_ASM("asm/nonmatching/code_0800025C", dispatch_game_substate_handler_08003374);
INCLUDE_ASM("asm/nonmatching/code_0800025C", setup_bg_layers_and_decompress);
INCLUDE_ASM("asm/nonmatching/code_0800025C", sub_080034A4);
INCLUDE_ASM("asm/nonmatching/code_0800025C", sub_08003504);
INCLUDE_ASM("asm/nonmatching/code_0800025C", sub_08003620);
INCLUDE_ASM("asm/nonmatching/code_0800025C", sub_08003654);
INCLUDE_ASM("asm/nonmatching/code_0800025C", sub_080036A8);
INCLUDE_ASM("asm/nonmatching/code_0800025C", sub_080036C8);
INCLUDE_ASM("asm/nonmatching/code_0800025C", sub_080036F4);
INCLUDE_ASM("asm/nonmatching/code_0800025C", sub_08003784);
INCLUDE_ASM("asm/nonmatching/code_0800025C", sub_080038CC);

void sub_080038F0(void)
{
    sub_080039BC();
    gGameSubState = 2;
}

INCLUDE_ASM("asm/nonmatching/code_0800025C", sub_08003904);
INCLUDE_ASM("asm/nonmatching/code_0800025C", sub_0800393C);
INCLUDE_ASM("asm/nonmatching/code_0800025C", sub_080039BC);
INCLUDE_ASM("asm/nonmatching/code_0800025C", sub_080039E0);
INCLUDE_ASM("asm/nonmatching/code_0800025C", sub_08003A38);
INCLUDE_ASM("asm/nonmatching/code_0800025C", sub_08003D4C);
INCLUDE_ASM("asm/nonmatching/code_0800025C", sub_08003DE0);
INCLUDE_ASM("asm/nonmatching/code_0800025C", sub_08003E54);
INCLUDE_ASM("asm/nonmatching/code_0800025C", sub_08003EA0);
INCLUDE_ASM("asm/nonmatching/code_0800025C", sub_08003EE0);
INCLUDE_ASM("asm/nonmatching/code_0800025C", sub_08003F28);
INCLUDE_ASM("asm/nonmatching/code_0800025C", sub_08003F74);
INCLUDE_ASM("asm/nonmatching/code_0800025C", sub_08003FE8);
INCLUDE_ASM("asm/nonmatching/code_0800025C", sub_08004028);
INCLUDE_ASM("asm/nonmatching/code_0800025C", sub_0800406C);
