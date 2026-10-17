#include "global.h"

void sub_0803CDCC(void)
{
    process_sprite_anim_commands(gUnk_083B5F80[gUnk_03002C30[gUnk_03000440.unk12F].unk2D], gUnk_03000440.unk12F);
    if (gUnk_03002C30[gUnk_03000440.unk12F].unk22 == 0xFF)
        clear_battle_sprite_slot(gUnk_03000440.unk12F, 1);
}

void sub_0803CE18(void)
{
    if (gUnk_03002C30[gUnk_03000440.unk12F].unk2B != 0)
    {
        gUnk_03002C30[gUnk_03000440.unk12F].unk2B--;
        return;
    }
    blend_obj_palettes_to_color_0803F684((gUnk_03002C30[gUnk_03000440.unk12F].unk2E << 10)
                                         | (gUnk_03002C30[gUnk_03000440.unk12F].unk2D << 5)
                                         | gUnk_03002C30[gUnk_03000440.unk12F].unk2C,
                                         gUnk_03002C30[gUnk_03000440.unk12F].unk2F, 0xFDFF);
    blend_obj_palettes_to_color_0803F998((gUnk_03002C30[gUnk_03000440.unk12F].unk2E << 10)
                                         | (gUnk_03002C30[gUnk_03000440.unk12F].unk2D << 5)
                                         | gUnk_03002C30[gUnk_03000440.unk12F].unk2C,
                                         gUnk_03002C30[gUnk_03000440.unk12F].unk2F, 0xB00F);
    if (gUnk_03002C30[gUnk_03000440.unk12F].unk2F == 0x10)
        gUnk_03002C30[gUnk_03000440.unk12F].unk29 = 0;
    else
        gUnk_03002C30[gUnk_03000440.unk12F].unk2F++;
}

void sub_0803CECC(void)
{
    if (gUnk_03002C30[gUnk_03000440.unk12F].unk2B != 0)
    {
        gUnk_03002C30[gUnk_03000440.unk12F].unk2B--;
        return;
    }
    blend_obj_palettes_to_color_0803F684((gUnk_03002C30[gUnk_03000440.unk12F].unk2E << 10)
                                         | (gUnk_03002C30[gUnk_03000440.unk12F].unk2D << 5)
                                         | gUnk_03002C30[gUnk_03000440.unk12F].unk2C,
                                         gUnk_03002C30[gUnk_03000440.unk12F].unk2F, 0xFDFF);
    blend_obj_palettes_to_color_0803F998((gUnk_03002C30[gUnk_03000440.unk12F].unk2E << 10)
                                         | (gUnk_03002C30[gUnk_03000440.unk12F].unk2D << 5)
                                         | gUnk_03002C30[gUnk_03000440.unk12F].unk2C,
                                         gUnk_03002C30[gUnk_03000440.unk12F].unk2F, 0xB00F);
    if (gUnk_03002C30[gUnk_03000440.unk12F].unk2F == 0)
        gUnk_03002C30[gUnk_03000440.unk12F].unk29 = 0;
    else
        gUnk_03002C30[gUnk_03000440.unk12F].unk2F--;
}

void sub_0803CF7C(void)
{
    if (gUnk_03002C30[gUnk_03000440.unk12F].unk2C)
        gUnk_03002C30[gUnk_03000440.unk12F].unk2C--;
    if (gUnk_03002C30[gUnk_03000440.unk12F].unk2B)
        gUnk_03002C30[gUnk_03000440.unk12F].unk2B--;
    else
        update_sprite_animation_position(gUnk_03000440.unk12F);
}

void sub_0803CFC8(void)
{
    struct Coords16 v;

    if (gUnk_03002C30[gUnk_03000440.unk12F].unk2C != 0)
        gUnk_03002C30[gUnk_03000440.unk12F].unk2C--;
    else
    {
        gUnk_03002C30[gUnk_03000440.unk12F].unk0 |= 0x8000;
        process_sprite_anim_commands(gUnk_083B5F80[gUnk_03002C30[gUnk_03000440.unk12F].unk2D], gUnk_03000440.unk12F);
    }
    if (gUnk_03002C30[gUnk_03000440.unk12F].unk2B != 0)
    {
        gUnk_03002C30[gUnk_03000440.unk12F].unk2B--;
        return;
    }
    v = calc_polar_to_screen_coords(gUnk_03002C30[gUnk_03000440.unk12F].unk26, 0x10, gUnk_03002C30[10].unk2, gUnk_03002C30[10].unk4);
    gUnk_03002C30[gUnk_03000440.unk12F].unk2 = v.x;
    gUnk_03002C30[gUnk_03000440.unk12F].unk4 = v.y;
    if (!(gUnk_03001800.unkF8 & 2))
        gUnk_03002C30[gUnk_03000440.unk12F].unk26 += 0x10;
    else
        gUnk_03002C30[gUnk_03000440.unk12F].unk26 -= 0x10;
}

void sub_0803D0BC(void)
{
    struct Unk_03002C30 *s;
    u8 i;

    process_sprite_anim_commands(gUnk_083B5F80[gUnk_03002C30[gUnk_03000440.unk12F].unk2D], gUnk_03000440.unk12F);
    i = gUnk_03000440.unk12F;
    s = &gUnk_03002C30[i];
    if (s->unk23 == 0)
    {
        if (s->unk8 <= s->unk26)
        {
            clear_sprite_table_mask(i, 1);
            return;
        }
        s->unk8 -= s->unk26;
        gUnk_03002C30[gUnk_03000440.unk12F].unk9 -= gUnk_03002C30[gUnk_03000440.unk12F].unk26;
    }
    else if (s->unk8 == 0x40)
        s->unk29 = 0;
    else
    {
        s->unk8 += s->unk26;
        gUnk_03002C30[gUnk_03000440.unk12F].unk9 += gUnk_03002C30[gUnk_03000440.unk12F].unk26;
    }
}

INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803D15C);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803D2A8);

void sub_0803D3C0(void)
{
    process_sprite_anim_commands(gUnk_083B5F80[gUnk_03002C30[gUnk_03000440.unk12F].unk26], gUnk_03000440.unk12F);
    if (sub_080353CC(gUnk_03000440.unk12F))
    {
        gUnk_03002C30[gUnk_03000440.unk12F].unk6 = 0x6307 + gUnk_03002C30[gUnk_03000440.unk12F].unk28;
        gUnk_03002C30[gUnk_03000440.unk12F].unk29 = 0;
    }
}

s16 sub_0803D424(void)
{
    const s16 *seq = gUnk_083CDFE4[gUnk_03001800.unkF9];
    return seq[gUnk_03001800.unk100];
}

void load_battle_sequence_commands(void)
{
    const s16 *seq = gUnk_083CDFE4[gUnk_03001800.unkF9];
    u32 n = gUnk_083CE1F4[seq[gUnk_03001800.unk100]];
    u32 i;

    for (i = 0; i < n; i++)
        gUnk_03001800.unk102[i] = seq[gUnk_03001800.unk100 + i + 1];
}

void battle_advance_sequence_counter(void)
{
    const s16 *seq = gUnk_083CDFE4[gUnk_03001800.unkF9];
    const u8 *ops = gUnk_083CE1F4;
    s32 p = gUnk_03001800.unk100;

    gUnk_03001800.unk100 = p + 1 + ops[seq[p]];
}

void battle_sprite_rotate_angles(u32 dir, u32 delta)
{
    u32 i;
    for (i = 0; i <= 0x13; i++)
    {
        if (gUnk_03002C30[i + 10].unk29 != 0)
        {
            if (dir)
                gUnk_03002C30[i + 10].unk2 = (gUnk_03002C30[i + 10].unk2 - delta) & 0x1FF;
            else
                gUnk_03002C30[i + 10].unk2 = (gUnk_03002C30[i + 10].unk2 + delta) & 0x1FF;
        }
    }
}

// Game state 10 handler: runs gUnk_083AFAF8[gGameSubState]; outside sub-states 0x10-0x1F a link error
// (sub_0803EED8) restarts it at 0x10. guess: link Robattle (entered when gUnk_03000440.unk89 == 1).
void sub_0803D538(void)
{
    if (gGameSubState - 0x10 > 0xF && sub_0803EED8())
        return;
    if (gUnk_03000430 == 2)
    {
        u32 fill = 0x200;
        CpuFastSet(&fill, gUnk_03002414->unkB84, 0x01000100);
    }
    sub_0803E780();
    gUnk_083AFAF8[gGameSubState]();
}

void sub_0803D5A0(void)
{
    u32 zero = 0;

    CpuFastSet(&zero, &gUnk_03001800, 0x01000100);
    gUnk_03000440.unk86 = 0;
    gUnk_03000440.unk84 = 0;
    gGameSubState++;
}

void sub_0803D5E0(void)
{
    if (sub_0803E79C())
    {
        gUnk_03000440.unk86 = 0;
        gGameSubState++;
    }
}

void sub_0803D608(void)
{
    if (gUnk_03000440.unk86 == 8)
    {
        gUnk_03000440.unk86 = 0;
        gGameSubState++;
    }
    else
    {
        gUnk_03000440.unk86++;
    }
}

void sub_0803D634(void)
{
    if (gUnk_03000B90 == 0)
    {
        gUnk_03000440.unk8D = gFrameCounter;
        gUnk_03005010.unk6 = gUnk_03000440.unk8D + 0x8000;
    }
    gGameSubState++;
}

void sub_0803D674(void)
{
    if (gUnk_03000B90 != 0)
    {
        u16 v = gUnk_03005010.unk8[0][1];
        if (!(v & 0x8000))
            return;
        gUnk_03000440.unk8D = v;
    }
    gGameSubState++;
}

void sub_0803D6AC(void)
{
    gUnk_03000440.unk84 = 0;
    gUnk_03001800.unk51 = 0;
    gUnk_03001800.unk52 = 0;
    gUnk_03001800.unk53 = 0;
    gUnk_03001800.unk54 = 0;
    gUnk_03001800.unk1A6 = 0;
    gUnk_03001800.unk1A8 = 0;
    gUnk_03001800.unk1AA = 0;
    gUnk_03001800.unk1AC = 0;
    gUnk_03001800.unk1AF = 0;
    gUnk_03001800.unk1B0 = 1;
    gUnk_03000440.unk86 = 0;
    gGameSubState = 0x50;
}

void sub_0803D71C(void)
{
    gUnk_03001800.unk38 = gUnk_083AFC78[rng_next_080424B8() & 0x1F];
    gGameSubState++;
}

void sub_0803D74C(void)
{
    u32 a, b, c;

    sub_08043CA8();
    a = 0;
    CpuFastSet(&a, (void *)OBJ_PLTT, 0x01000080);
    b = 0;
    CpuFastSet(&b, (void *)PLTT, 0x01000080);
    REG_DISPCNT &= 0xE0FF;
    REG_BG0CNT = 0x500;
    REG_BG1CNT = 0x1801;
    REG_BG2CNT = 0x590A;
    REG_BG3CNT = 0x5B0B;
    lz_decompress_dispatch(gUnk_084E6C9C, (void *)0x06004000);
    lz_decompress_dispatch(gUnk_084C48B4, (void *)0x06006000);
    lz_decompress_dispatch(gUnk_084C4A34, (void *)0x06006200);
    lz_decompress_dispatch(gUnk_084C6A98, (void *)0x06017400);
    vram_fill_tilemap_rect(0x20, 0x20, 0, 0, REG_BG0CNT, 0);
    vram_fill_tilemap_rect(0x20, 0x20, 0, 0, REG_BG1CNT, 0);
    set_tilemap_and_decompress_bg(0, 0, gUnk_084EFA34, REG_BG1CNT, 0x200);
    CpuFastSet(gUnk_084F29E0, (void *)0x0202FA00, 0x70);
    CpuFastSet(gUnk_084C69D8, (void *)0x0202FB00, 8);
    CpuFastSet(gUnk_084C69F8, (void *)0x0202FB20, 8);
    CpuFastSet(gUnk_0850DEF8, (void *)0x0202F800, 0x40);
    CpuFastSet(gUnk_0850DCF8 + 0xB0, (void *)0x0202F980, 8);
    CpuFastSet(gUnk_0850DCF8, (void *)0x0202F9A0, 8);
    decompress_tileset_to_vram(gUnk_03001800.unk38, 1);
    c = 0;
    CpuFastSet(&c, gUnk_03002C30, 0x01000800);
    REG_DISPCNT |= 0x1F60;
    render_battle_text_label();
    load_battle_anim_data_38();
    draw_battle_ui_tiles_from_rom();
    load_battle_script_entry_a();
    apply_battle_blend_effect_a();
    play_song(8);
    gUnk_03000440.unk84 = 0;
    gGameSubState++;
}

void sub_0803D928(void)
{
    update_scroll_movement_a();
    if (gUnk_03000440.unk84 <= 8)
    {
        blend_obj_palettes_to_color_0803F684(0, 0x20 - gUnk_03000440.unk84 * 4, 0xFFFF);
        blend_obj_palettes_to_color_0803F998(0, 0x20 - gUnk_03000440.unk84 * 4, 0xFFFF);
        gUnk_03000440.unk84++;
    }
    else
        gGameSubState++;
}

void sub_0803D980(void)
{
    update_scroll_movement_a();
    text_window_init(1, 0, 0);
    gGameSubState++;
}

void sub_0803D9A0(void)
{
    update_scroll_movement_a();
    if (run_message(gUnk_083C2BBC[1]))
        gGameSubState++;
}

void sub_0803D9C8(void)
{
    update_scroll_movement_a();
    copy_obj_palette_to_buffer();
    gUnk_03000440.unk84 = 0;
    gGameSubState++;
}

void sub_0803D9F0(void)
{
    update_scroll_movement_a();
    if (gUnk_03000440.unk84 <= 8)
    {
        blend_obj_palettes_to_color_0803F684(0, gUnk_03000440.unk84 * 4, 0xFFFF);
        blend_obj_palettes_to_color_0803F998(0, gUnk_03000440.unk84 * 4, 0xFFFF);
        gUnk_03000440.unk84++;
    }
    else
        gGameSubState++;
}

void sub_0803DA40(void)
{
    update_scroll_movement_a();
    if (gUnk_03000440.unk84 <= 8)
    {
        blend_obj_palettes_to_color_0803F684(0, gUnk_03000440.unk84 * 4, 0xFFFF);
        blend_obj_palettes_to_color_0803F998(0, gUnk_03000440.unk84 * 4, 0xFFFF);
        gUnk_03000440.unk84++;
    }
    else
        gGameSubState++;
}

void sub_0803DA90(void)
{
    set_blend_effect_mode(0, 0, 0);
    vram_fill_tilemap_rect(0x20, 0x20, 0, 0, REG_BG0CNT, 0);
    vram_fill_tilemap_rect(0x20, 0x20, 0, 0, REG_BG1CNT, 0);
    clear_battle_sprite_slot(0, 0x80);
    gGameSubState++;
}

void sub_0803DAEC(void)
{
    sub_0803F624(&gUnk_03000440.unk50, 0x14, 0);
    gUnk_03000440.unk50 = 1;
    gGameState = 3;
    gGameSubState = 0;
}

void sub_0803DB1C(void)
{
    if (gUnk_03000440.unk9C == 1)
        play_song(14);
    else
        play_song(15);
    gGameSubState++;
}

void sub_0803DB4C(void)
{
    update_scroll_movement_a();
    if (run_message(gUnk_083C3984[1]) && (*(u8 *)&gNewKeys & 3))
    {
        gUnk_03000440.unk1B = 0;
        play_sound_effect(0xD);
        gGameSubState++;
    }
}

void sub_0803DB94(void)
{
    update_scroll_movement_a();
    if (game_state_execute_handler_b())
    {
        sub_0803FB0C();
        gGameSubState++;
    }
}

void sub_0803DBB8(void)
{
    update_scroll_movement_a();
    if (run_message(gUnk_083CF3B0[1]))
        gGameSubState++;
}

void sub_0803DBE0(void)
{
    update_scroll_movement_a();
    if (sub_0803E79C())
    {
        gUnk_03000440.unk86 = 0;
        gGameSubState++;
    }
}

void sub_0803DC0C(void)
{
    update_scroll_movement_a();
    if (gUnk_03000440.unk86 == 8)
    {
        gUnk_03000440.unk86 = 0;
        gGameSubState++;
    }
    else
    {
        gUnk_03000440.unk86++;
    }
}

void sub_0803DC3C(void)
{
    update_scroll_movement_a();
    sound_stop_all_with_fade_guard(8);
    gGameSubState++;
}

void sub_0803DC58(void)
{
    update_scroll_movement_a();
    if (gUnk_03000440.unk138 == 0)
        gGameSubState++;
    else
        gGameSubState = 0x30;
}

void sub_0803DC8C(void)
{
    u32 a, b;

    clear_battle_sprite_slot(0, 0x80);
    sub_08043CA8();
    a = 0;
    CpuFastSet(&a, (void *)(OBJ_PLTT), 0x01000080);
    b = 0;
    CpuFastSet(&b, (void *)PLTT, 0x01000080);
    set_blend_effect_mode(5, 0x3F, 0x20);
    sub_08044CDC(3);
}

void sub_0803DCDC(void)
{
    u32 zero;

    sub_08043CA8();
    set_blend_effect_mode(5, 0x3F, 0x20);
    REG_DISPCNT &= 0xE0FF;
    REG_BG0CNT = 0x500;
    REG_BG1CNT = 0x1801;
    REG_BG2CNT = 0x1902;
    REG_BG3CNT = 0x1B03;
    lz_decompress_dispatch(gUnk_084EDEF0, (void *)0x06004000);
    lz_decompress_dispatch(gUnk_084C66B8, (void *)0x06007000);
    lz_decompress_dispatch(gUnk_084C68E0, (void *)0x06007A00);
    lz_decompress_dispatch(gUnk_084C6A98, (void *)0x06017400);
    lz_decompress_dispatch(gUnk_084E20F8, (void *)0x06010000);
    set_tilemap_and_decompress_bg(0, 0, gUnk_084EF668, REG_BG0CNT, 0x200);
    set_tilemap_and_decompress_bg(0, 0, gUnk_084F0194, REG_BG1CNT, 0x200);
    set_tilemap_and_decompress_bg(0, 0, gUnk_084F0D9C, REG_BG2CNT, 0x200);
    set_tilemap_and_decompress_bg(0, 0, gUnk_084F21E8, REG_BG3CNT, 0x200);
    CpuFastSet(gUnk_084F39A0, (void *)PLTT, 0x60);
    CpuFastSet(gUnk_0850EF58, (void *)OBJ_PLTT, 0x10);
    zero = 0;
    CpuFastSet(&zero, gUnk_03002C30, 0x01000800);
    REG_DISPCNT |= 0x1F60;
    sub_0803E8B8();
    sub_0803E8EC();
    sub_0803E934();
    sub_0803E978();
    sub_0803E9BC();
    gUnk_03001800.unk1A0 = 0;
    play_song(0x14);
    gGameSubState++;
}

void sub_0803DE70(void)
{
    sub_0803E894();
    if (update_blend_effect())
        gGameSubState++;
}

void sub_0803DE90(void)
{
    sub_0803E894();
    text_window_init(1, 0, 0);
    gGameSubState++;
}

void sub_0803DEB0(void)
{
    sub_0803E894();
    if (run_message(gUnk_03000440.unk9C == 1 ? gUnk_083CF3B0[2] : gUnk_083CF3B0[3]))
        gGameSubState++;
}

void sub_0803DEF0(void)
{
    u16 pkt;

    sub_0803E894();
    if (gUnk_03000440.unk9C == 1)
    {
        sub_0803EA18();
        draw_battle_gauge_bar();
        if (!(*(u8 *)&gNewKeys & 1))
            return;
        play_sound_effect(4);
        gUnk_03005010.unk6 = gUnk_03001800.unk1A0 + 0x8000;
        gUnk_03000440.unk86 = 0;
        gGameSubState++;
    }
    else
    {
        pkt = gUnk_03005010.unk8[gUnk_03000B90 ^ 1][1];
        if (!(pkt & 0x8000))
            return;
        play_sound_effect(4);
        gUnk_03001800.unk1A0 = pkt;
        gUnk_03000440.unk1B = 0;
        gUnk_03000440.unk86 = 0;
        gGameSubState++;
    }
}

void sub_0803DF98(void)
{
    u16 n;

    sub_0803E894();
    if (gUnk_03000440.unk9C == 1)
    {
        gUnk_03005010.unk6 = gUnk_03001800.unk1A0 + 0x8000;
        update_battle_gauge_display();
        n = ++gUnk_03000440.unk86;
    }
    else
    {
        update_battle_gauge_display();
        gUnk_03000440.unk86++;
        if (!game_state_execute_handler_a())
            return;
        n = gUnk_03000440.unk86;
    }
    if (n == 0x3C)
    {
        play_sound_effect(0x39);
        draw_battle_gauge_bar();
        gGameSubState++;
    }
}

void sub_0803E018(void)
{
    sub_0803E894();
    sub_0803EB30();
    sub_0803EB5C();
    sub_0803EC04();
    gGameSubState++;
}

void sub_0803E03C(void)
{
    sub_0803E894();
    process_sprite_anim_commands(gUnk_083B5F80[0x75 - gUnk_03001800.unk1A2], 4);
    if (gUnk_03002C30[4].unk22 == 0xFF)
    {
        gUnk_03002C30[3].unk6 = 0x8505;
        play_sound_effect(0x54);
        gGameSubState++;
    }
}

void sub_0803E098(void)
{
    sub_0803E894();
    if (sub_0803EC98())
    {
        sub_0803ECF0();
        sub_0803ED10();
        gGameSubState++;
    }
}

void sub_0803E0C0(void)
{
    sub_0803E894();
    if (sub_0803ED28())
    {
        play_sound_effect(0x2A);
        gUnk_03000440.unk86 = 0;
        gGameSubState++;
    }
}

void sub_0803E0F0(void)
{
    sub_0803E894();
    draw_battle_bg1_tilemap_row();
    if (gUnk_03000440.unk86 == 0x78)
        gGameSubState++;
    else
        gUnk_03000440.unk86++;
}

void sub_0803E120(void)
{
    sub_0803E894();
    draw_battle_bg1_tilemap_row();
    gUnk_03000440.unk86++;
    if (gUnk_03001800.unk19A[gUnk_03001800.unk1A2] == 4)
        gGameSubState++;
    else
        gGameSubState = 0x48;
}

void sub_0803E170(void)
{
    sub_0803E894();
    draw_battle_bg1_tilemap_row();
    gUnk_03000440.unk86++;
    text_window_init(1, 0, 0);
    gGameSubState++;
}

void sub_0803E1A4(void)
{
    sub_0803E894();
    draw_battle_bg1_tilemap_row();
    gUnk_03000440.unk86++;
    if (run_message(gUnk_03000440.unk9C == 1 ? gUnk_083CF3B0[4] : gUnk_083CF3B0[5]))
    {
        text_window_init(1, 0, 0);
        gGameSubState++;
    }
}

void sub_0803E1FC(void)
{
    sub_0803E894();
    draw_battle_bg1_tilemap_row();
    gUnk_03000440.unk86++;
    if (run_message(gUnk_083CF3B0[1]))
        gGameSubState++;
}

void sub_0803E234(void)
{
    sub_0803E894();
    draw_battle_bg1_tilemap_row();
    gUnk_03000440.unk86++;
    if (sub_0803E79C())
    {
        gUnk_03000440.unk84 = 0;
        gGameSubState++;
    }
}

void sub_0803E270(void)
{
    sub_0803E894();
    draw_battle_bg1_tilemap_row();
    gUnk_03000440.unk86++;
    if (gUnk_03000440.unk84 == 4)
    {
        gUnk_03000440.unk84 = 0;
        gGameSubState++;
    }
    else
        gUnk_03000440.unk84++;
}

void sub_0803E2AC(void)
{
    sub_0803E894();
    draw_battle_bg1_tilemap_row();
    gUnk_03000440.unk86++;
    sound_stop_all_with_fade_guard(8);
    gGameSubState++;
}

void sub_0803E2DC(void)
{
    sub_0803E894();
    draw_battle_bg1_tilemap_row();
    gUnk_03000440.unk86++;
    copy_obj_palette_to_buffer();
    gUnk_03000440.unk84 = 0;
    gGameSubState++;
}

void sub_0803E314(void)
{
    sub_0803E894();
    draw_battle_bg1_tilemap_row();
    gUnk_03000440.unk86++;
    if (gUnk_03000440.unk84 <= 8)
    {
        blend_obj_palettes_to_color_0803F684(0, gUnk_03000440.unk84 * 4, 0xFFFF);
        blend_obj_palettes_to_color_0803F998(0, gUnk_03000440.unk84 * 4, 0xFFFF);
        gUnk_03000440.unk84++;
    }
    else
        gGameSubState++;
}

INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803E374);

void sub_0803E434(void)
{
    sub_0803E894();
    draw_battle_bg1_tilemap_row();
    gUnk_03000440.unk86++;
    if (run_message(gUnk_03000440.unk9C == 1 ? gUnk_083CF3B0[6] : gUnk_083CF3B0[7]))
    {
        text_window_init(1, 0, 0);
        gGameSubState++;
    }
}

void sub_0803E48C(void)
{
    sub_0803E894();
    draw_battle_bg1_tilemap_row();
    gUnk_03000440.unk86++;
    gGameSubState = 0x3E;
}

void sub_0803E4B4(void)
{
    sound_stop_all_with_fade_guard(8);
    set_blend_effect_mode(6, 0x3F, 0x20);
    gGameSubState++;
}

void sub_0803E4D8(void)
{
    if (update_blend_effect())
        gGameSubState++;
}

void sub_0803E4F4(void)
{
    u32 a, b, c;

    sub_08043CA8();
    REG_DISPCNT &= 0xE0FF;
    REG_BG0CNT = 0x500;
    REG_BG1CNT = 0x1801;
    REG_BG2CNT = 0x1902;
    REG_BG3CNT = 0x1B03;
    a = 0;
    CpuFastSet(&a, (void *)(PLTT + 0x120), 0x01000008);
    b = 0x11111111;
    CpuFastSet(&b, (void *)0x06004120, 0x01000008);
    vram_fill_tilemap_rect(0x20, 0x20, 0, 0, REG_BG0CNT, 0x9209);
    vram_fill_tilemap_rect(0x20, 0x20, 0, 0, REG_BG1CNT, 0x9209);
    vram_fill_tilemap_rect(0x20, 0x20, 0, 0, REG_BG2CNT, 0x9209);
    vram_fill_tilemap_rect(0x20, 0x20, 0, 0, REG_BG3CNT, 0x9209);
    c = 0;
    CpuFastSet(&c, gUnk_03002C30, 0x01000800);
    REG_DISPCNT |= 0x1F60;
    set_blend_effect_mode(5, 0x3F, 0x20);
    gGameSubState++;
}

void sub_0803E618(void)
{
    text_window_init(1, 0, 0);
    gGameSubState++;
}

void sub_0803E634(void)
{
    if (run_message(gUnk_083CF3B0[12]))
        gGameSubState++;
}

void sub_0803E658(void)
{
    set_blend_effect_mode(4, 0x3F, 0x20);
    gGameSubState++;
}

void sub_0803E674(void)
{
    soft_reset_to_title();
}

INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803E680);

void sub_0803E768(void)
{
    gGameSubState = 6;
}

void sub_0803E774(void)
{
    gGameSubState = 5;
}

void sub_0803E780(void)
{
    if (gUnk_03000440.unk89 == 1)
        gUnk_03005010.unk6 = 0;
}

u32 sub_0803E79C(void)
{
    gUnk_03005010.unk6 = 0xFFFE;
    if (gUnk_03005010.unk8[0][1] == 0xFFFE && gUnk_03005010.unk8[1][1] == gUnk_03005010.unk8[0][1])
        return 1;
    return 0;
}

void render_battle_text_label(void)
{
    render_text_sprites_08040EE4(gUnk_0300198A, 10, 0x12, 3, 10, 13, 0, 1, 0, -4);
}

void load_battle_anim_data_38(void)
{
    memcpy_bytes_0803F63C(gUnk_083BE9E8[gUnk_03001800.unk38], gUnk_03000440.unk9E, 0xB);
    render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x1E, 1, 3, 8, 0xC, 0, 1);
}

void draw_battle_ui_tiles_from_rom(void)
{
    u32 i;
    for (i = 0; i <= 2; i++)
        draw_tilemap_with_offset(0xFF, gUnk_083ACEEA[i][0], gUnk_083ACEEA[i][1], REG_BG0CNT, 0x8300);
}

void load_battle_script_entry_a(void)
{
    memcpy_bytes_0803F63C(gUnk_083C3B04[gUnk_03001800.unk38], gUnk_03001800.unk39, 8);
}

void sub_0803E894(void)
{
    if (gFrameCounter & 1)
    {
        gBg3Scroll.x++;
        gBg3Scroll.y++;
    }
}

void sub_0803E8B8(void)
{
    u32 r = rng_next_080424B8() & 0xF;
    u32 i;
    for (i = 0; i <= 5; i++)
        gUnk_0300199A[i] = gUnk_083AFC98[r][i];
}

void sub_0803E8EC(void)
{
    u32 i;

    for (i = 0; i <= 5; i++)
    {
        u8 *p = gUnk_0300199A;
        fill_tilemap_rect_08042698(7, 2, 4, i * 2 + 2, REG_BG1CNT, p[i] * 14 + 0x3380);
    }
}

void sub_0803E934(void)
{
    clear_battle_sprite_slot(2, 1);
    gUnk_03002C30[2].unk0 = 0xC400;
    gUnk_03002C30[2].unk2 = 0x68;
    gUnk_03002C30[2].unk4 = 0x78;
    gUnk_03002C30[2].unk6 = 0x8506;
    gUnk_03002C30[2].unk1C = 0;
    gUnk_03002C30[2].unkB = 0x82;
}

void sub_0803E978(void)
{
    clear_battle_sprite_slot(3, 1);
    gUnk_03002C30[3].unk0 = 0xC400;
    gUnk_03002C30[3].unk2 = 0x78;
    gUnk_03002C30[3].unk4 = 0x7C;
    gUnk_03002C30[3].unk6 = 0x8504;
    gUnk_03002C30[3].unk1C = 0;
    gUnk_03002C30[3].unkB = 0x81;
}

void sub_0803E9BC(void)
{
    clear_battle_sprite_slot(4, 1);
    gUnk_03002C30[4].unk0 = 0xC400;
    gUnk_03002C30[4].unk2 = 0x9A;
    gUnk_03002C30[4].unk4 = 0x58;
    gUnk_03002C30[4].unk1C = 0;
    gUnk_03002C30[4].unkB = 0x80;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x70], 4);
}

void sub_0803EA18(void)
{
    if (gUnk_03001800.unk1A0 == 0x60)
        gUnk_03001800.unk1A0 = 0;
    else
        gUnk_03001800.unk1A0 += 4;
}

void draw_battle_gauge_bar(void)
{
    u32 x = 0;
    u32 i, n;

    n = gUnk_03001800.unk1A0 >> 3;
    for (i = 0; i < n; i++)
    {
        fill_tilemap_rect_08042698(1, 1, x + 7, 0x12, REG_BG1CNT, 0x53D8);
        x++;
    }
    n = gUnk_03001800.unk1A0;
    n &= 7;
    if (n != 0)
    {
        fill_tilemap_rect_08042698(1, 1, x + 7, 0x12, REG_BG1CNT, n | 0x53D0);
        x++;
    }
    for (i = x; i < 12; i++)
    {
        fill_tilemap_rect_08042698(1, 1, x + 7, 0x12, REG_BG1CNT, 0x53D0);
        x++;
    }
}

void fill_bg1_tilemap_column(void)
{
    u32 i;
    for (i = 0; i <= 11; i++)
        fill_tilemap_rect_08042698(1, 1, i + 7, 0x12, REG_BG1CNT, 0x53D0);
}

void update_battle_gauge_display(void)
{
    if (gUnk_03000440.unk86 & 4)
        draw_battle_gauge_bar();
    else
        fill_bg1_tilemap_column();
}

void sub_0803EB30(void)
{
    gUnk_03001800.unk1A1 = 0x68 - gUnk_03001800.unk1A0;
    if (gUnk_03001800.unk1A1 <= 12)
        gUnk_03001800.unk1A1 = 12;
}

void sub_0803EB5C(void)
{
    gUnk_03001800.unk1A2 = gUnk_03001800.unk1A0 >> 4;
    switch (gUnk_03001800.unk1A2)
    {
    case 0:
        gUnk_03001800.unk1A2 = 5;
        break;
    case 1:
        gUnk_03001800.unk1A2 = 4;
        break;
    case 2:
        gUnk_03001800.unk1A2 = 3;
        break;
    case 3:
        gUnk_03001800.unk1A2 = 2;
        break;
    case 4:
        gUnk_03001800.unk1A2 = 1;
        break;
    case 5:
        gUnk_03001800.unk1A2 = 0;
        break;
    case 6:
        gUnk_03001800.unk1A2 = 0;
        break;
    }
    gUnk_03001800.unk1A3 = gUnk_03001800.unk1A2 * 16 + 0x18;
}

void sub_0803EC04(void)
{
    gUnk_03002C30[2].unk24 = (gUnk_03001800.unk1A0 >> 2) + 4;
    gUnk_03002C30[2].unk25 = 0;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x75 - gUnk_03001800.unk1A2], 4);
}

void sub_0803EC50(void)
{
    u32 v = gUnk_03002C30[2].unk24 + gUnk_03002C30[2].unk20;
    u32 d = v >> 2;
    gUnk_03002C30[2].unk20 = v & 3;
    if (gUnk_03002C30[2].unk25 == 0)
        gUnk_03002C30[2].unk4 = (gUnk_03002C30[2].unk4 - d) & 0xFF;
    else
        gUnk_03002C30[2].unk4 = (gUnk_03002C30[2].unk4 + d) & 0xFF;
}

u32 sub_0803EC98(void)
{
    sub_0803EC50();
    if (gUnk_03002C30[2].unk4 <= gUnk_03001800.unk1A1)
    {
        gUnk_03002C30[2].unk4 = gUnk_03001800.unk1A1;
        return 1;
    }
    gUnk_03002C30[2].unk27++;
    if (!(gUnk_03002C30[2].unk27 & 3) && gUnk_03002C30[2].unk24 != 1)
        gUnk_03002C30[2].unk24--;
    return 0;
}

void sub_0803ECF0(void)
{
    if (gUnk_03001800.unk1A0 == 0x60)
        play_sound_effect(7);
}

void sub_0803ED10(void)
{
    gUnk_03002C30[2].unk24 = 0;
    gUnk_03002C30[2].unk25 = 1;
}

u32 sub_0803ED28(void)
{
    u32 r;

    sub_0803EC50();
    if (gUnk_03002C30[2].unk4 < gUnk_03001800.unk1A3)
    {
        gUnk_03002C30[2].unk24++;
        r = 0;
    }
    else
    {
        gUnk_03002C30[2].unk4 = gUnk_03001800.unk1A3;
        r = 1;
    }
    return r;
}

void draw_battle_bg1_tilemap_row(void)
{
    if (gUnk_03000440.unk86 & 4)
        fill_tilemap_rect_08042698(7, 2, 4, gUnk_03001800.unk1A2 * 2 + 2, REG_BG1CNT,
                                   gUnk_03001800.unk19A[gUnk_03001800.unk1A2] * 14 + 0x3380);
    else
        fill_tilemap_rect_08042698(7, 2, 4, gUnk_03001800.unk1A2 * 2 + 2, REG_BG1CNT,
                                   gUnk_03001800.unk19A[gUnk_03001800.unk1A2] * 14 + 0x4380);
}

void sub_0803EE10(void)
{
    u32 base;
    u32 r, i;

    if (gUnk_03000440.unk9C == 1)
        base = 3;
    else
        base = 0;
    r = gUnk_083AFCF8[rng_next_080424B8() & 0xF];
    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03000590[base + r].unkBA != 0)
        {
            gUnk_03001800.unk1A4 = gUnk_03000590[base + r].unk47;
            gUnk_03001800.unk1A5 = gUnk_03000590[base + r].parts[gUnk_03001800.unk19A[gUnk_03001800.unk1A2]].unk17;
            return;
        }
        if (r == 2)
            r = 0;
        else
            r++;
    }
}

u32 sub_0803EED8(void)
{
    // unk1C..unk1F read as one word (the struct has no u32 there)
    if (gUnk_03000440.unk89 == 1 && (((struct { u8 f[0x1C]; u32 x; } *)&gUnk_03005010)->x & 0xFFFF00))
    {
        gGameMode = 0;
        gGameState = 10;
        gGameSubState = 0x10;
        return 1;
    }
    return 0;
}

void soft_reset_to_title(void)
{
    gUnk_03005030 = 0;
    serial_multiplayer_init();
    VBlankIntrWait();
    REG_SOUNDCNT_X = 0;
    REG_IME = 0;
    hw_reset_init();
    irq_init();
    serial_link_init();
    gGameMode = 3;
    gGameState = 0;
    gGameSubState = 0;
    REG_DMA0CNT_H = 0;
    VBlankIntrWait();
    sound_init(&gUnk_03002430);
    VBlankIntrWait();
}

void vram_fill_tilemap_rect(u32 w, u32 h, u32 x, u32 y, u32 bgcnt, u16 value)
{
    u16 *base = (u16 *)(VRAM + (((bgcnt >> 8) & 0x1F) << 11)) + x + y * 32;
    u32 i, j;
    for (i = 0; i < h; i++)
    {
        u16 *d = base + i * 32;
        for (j = 0; j < w; j++)
            *d++ = value;
    }
}

void tilemap_fill_rect(u32 w, u32 h, u32 x, u32 y, u32 bgcnt, u16 tile)
{
    u16 *dst;
    u16 *d;
    u32 i, j;
    u32 cols, rows;

    if (x < 32)
    {
        if (y < 32)
        {
            dst = (u16 *)(VRAM + (((bgcnt >> 8) & 0x1F) << 11)) + x + y * 32;
            rows = 32 - y;
            for (i = 0; i < h; i++)
            {
                cols = 32 - x;
                d = dst + i * 32;
                for (j = 0; j < w; j++)
                {
                    *d++ = tile;
                    if (--cols == 0)
                        d += 0x3E0;
                }
                if (--rows == 0)
                    dst += 0x400;
            }
        }
        else
        {
            y -= 32;
            dst = (u16 *)(VRAM + (((bgcnt >> 8) & 0x1F) << 11)) + x + y * 32 + 0x800;
            for (i = 0; i < h; i++)
            {
                cols = 32 - x;
                d = dst + i * 32;
                for (j = 0; j < w; j++)
                {
                    *d++ = tile;
                    if (--cols == 0)
                        d += 0x3E0;
                }
            }
        }
    }
    else
    {
        if (y < 32)
        {
            dst = (u16 *)(VRAM + (((bgcnt >> 8) & 0x1F) << 11)) + (x - 32) + y * 32 + 0x400;
            rows = 32 - y;
            for (i = 0; i < h; i++)
            {
                d = dst + i * 32;
                for (j = 0; j < w; j++)
                    *d++ = tile;
                if (--rows == 0)
                    dst += 0x400;
            }
        }
        else
        {
            y -= 32;
            dst = (u16 *)(VRAM + (((bgcnt >> 8) & 0x1F) << 11)) + (x - 32) + y * 32 + 0xC00;
            for (i = 0; i < h; i++)
            {
                d = dst + i * 32;
                for (j = 0; j < w; j++)
                    *d++ = tile;
            }
        }
    }
}

void write_tilemap_rect(u32 w, u32 h, u32 x, u32 y, const void *src, u32 bgcnt, u32 base)
{
    u16 *dst;
    const u16 *s;
    u32 i, j;
    gTilemapBaseEntry = base;
    dst = (u16 *)(VRAM + (((bgcnt >> 8) & 0x1F) << 11)) + x + y * 32;
    s = src;
    for (i = 0; i < h; i++)
    {
        u16 *d = dst + i * 32;
        for (j = 0; j < w; j++)
            *d++ = *s++ + gTilemapBaseEntry;
    }
}

INCLUDE_ASM("asm/nonmatching/code_0803CDCC", write_tilemap_to_vram_0803F1C8);

void decompress_bg_tiles_to_vram_bg(void)
{
    lz_decompress_dispatch(gUnk_084873D0, (void *)0x06000020);
    lz_decompress_dispatch(gUnk_084C31BC, (void *)0x06001780);
    CpuFastSet(gUnk_08488A84, (void *)(PLTT + 0x1E0), 8);
}

INCLUDE_ASM("asm/nonmatching/code_0803CDCC", setup_bg0_display_layer);

void decompress_indexed_asset(u32 set, u32 idx, void *dst, u32 pal, u32 toBuffer)
{
    lz_decompress_dispatch(gUnk_083AFD08[set][idx], dst);
    if (toBuffer)
        CpuFastSet(gUnk_083B15C8[set], (void *)(0x0202FA00 + pal * 32), 8);
    else
        CpuFastSet(gUnk_083B15C8[set], (void *)(PLTT + pal * 32), 8);
}

void load_bg0_tilemap(u32 a, u32 b, u32 x, u32 y, u32 c)
{
    REG_DISPCNT |= 0x100;
    REG_BG0CNT = 0x500;
    lz_decompress_dispatch(gUnk_083AFD08[a][b], (void *)0x06000F80);
    CpuFastSet(gUnk_083B15C8[a], (void *)0x050001A0, 8);
    write_tilemap_rect(8, 8, x, y, gUnk_083B4AE0[c * 9 + 8], REG_BG0CNT, 0);
}

INCLUDE_ASM("asm/nonmatching/code_0803CDCC", load_overworld_map_column);

void sub_0803F624(u8 *dst, u32 size, u8 val)
{
    u32 i;
    for (i = 0; i < size; i++)
        *dst++ = val;
}

void memcpy_bytes_0803F63C(const void *src, void *dst, u32 n)
{
    u32 i;
    for (i = 0; i < n; i++)
    {
        *(u8 *)dst = *(const u8 *)src;
        src = (const u8 *)src + 1;
        dst = (u8 *)dst + 1;
    }
}

void memswap(void *a, void *b, u32 n)
{
    u32 i;
    u8 t;
    for (i = 0; i < n; i++)
    {
        t = *(u8 *)a;
        *(u8 *)a = *(u8 *)b;
        a = (u8 *)a + 1;
        *(u8 *)b = t;
        b = (u8 *)b + 1;
    }
}

INCLUDE_ASM("asm/nonmatching/code_0803CDCC", blend_obj_palettes_to_color_0803F684);

void blend_obj_palettes_to_color_0803F788(u16 color, u32 amount, u16 mask)
{
    u32 i, j;
    u32 inv;
    u16 bit = 1;
    if (amount > 32)
        amount = 32;
    inv = 32 - amount;
    for (i = 0; i < 16; i++)
    {
        if (mask & bit)
        {
            for (j = 0; j < 16; j++)
            {
                u16 *dst = &gPaletteBufferBg[i * 16 + j];
                u16 *src = &gPaletteBackupBg[i * 16 + j];
                *dst = (((*src & 0x1F) * inv + amount * (color & 0x1F)) >> 5)
                    | ((((*src & 0x3E0) * inv + amount * (color & 0x3E0)) >> 5) & 0x3E0)
                    | ((((*src & 0x7C00) * inv + amount * (color & 0x7C00)) >> 5) & 0x7C00);
            }
        }
        else
        {
            for (j = 0; j < 16; j++)
                gPaletteBufferBg[i * 16 + j] = gPaletteBackupBg[i * 16 + j];
        }
        bit <<= 1;
    }
    gVBlankOnceCallback = dma_obj_palette_to_hardware;
}

void palette_blend_to_color_0803F890(u16 color, u32 amount, u16 mask)
{
    u32 i, j;
    u32 inv;
    u16 bit = 1;
    if (amount > 32)
        amount = 32;
    inv = 32 - amount;
    for (i = 0; i < 16; i++)
    {
        if (mask & bit)
        {
            for (j = 0; j < 16; j++)
            {
                u16 *dst = &gPaletteBuffer[i * 16 + j];
                u16 *src = &gPaletteBackup[i * 16 + j];
                *dst = (((*src & 0x1F) * inv + amount * (color & 0x1F)) >> 5)
                    | ((((*src & 0x3E0) * inv + amount * (color & 0x3E0)) >> 5) & 0x3E0)
                    | ((((*src & 0x7C00) * inv + amount * (color & 0x7C00)) >> 5) & 0x7C00);
            }
        }
        else
        {
            for (j = 0; j < 16; j++)
                gPaletteBuffer[i * 16 + j] = gPaletteBackup[i * 16 + j];
        }
        bit <<= 1;
    }
    gVBlankOnceCallback = dma_obj_palette_to_hardware;
}

INCLUDE_ASM("asm/nonmatching/code_0803CDCC", blend_obj_palettes_to_color_0803F998);

void text_window_init(u8 a, u8 b, u32 c)
{
    u8 c8 = c;

    sub_0803F624((u8 *)&gUnk_03000440, 0x28, 0);
    gUnk_03000440.unk0 = a;
    gUnk_03000440.unk1 = b;
    gUnk_03000440.unk2 = c8;
    gUnk_03000440.unkF = 0xFF;
    gUnk_03000440.unk10 = -1;
    gUnk_03000440.unk11 = -1;
    decompress_bg_tiles_to_vram_bg();
    CpuFastSet(gUnk_084C6998, (void *)(OBJ_PLTT - 0x40), 8);
    if (c8 == 1)
        setup_bg0_display_layer();
}

void sub_0803FB0C(void)
{
    gUnk_03000440.unk4 = 4;
    gUnk_03000440.unkC = 0;
    gUnk_03000440.unk14 = 0;
    gUnk_03000440.unk15 = 0;
    gUnk_03000440.unk16 = 0;
    gUnk_03000440.unk17 = 0;
    gUnk_03000440.unk18 = 0;
    gUnk_03000440.unk19 = 0;
    gUnk_03000440.unk1A = 0;
    gUnk_03000440.unk1B = 0;
    gUnk_03000440.unk24 = 0;
    gUnk_03000440.unk25 = 0;
    gUnk_03000440.unk27 = 0;
}

u32 run_message(const void *msg)
{
    gUnk_03000440.unk8 = msg;
    gUnk_083B279C[gUnk_03000440.unk4]();
    if (gUnk_03000440.unk4 > 7)
        return 1;
    return 0;
}

// run_message state 0: back up the palettes, then dim them (state 1); unk0 != 0 skips to state 2.
void message_open(void)
{
    u8 v = gUnk_03000440.unk0;
    if (v == 0)
    {
        copy_obj_palette_to_buffer();
        gUnk_03000440.unk1C = v;
        gUnk_03000440.unk4++;
    }
    else
    {
        gUnk_03000440.unk4 = 2;
    }
}

// run_message state 1: blend all palettes toward 0x01B2 by unk1C * 2 / 32, 10 frames.
void message_dim_palettes_step(void)
{
    blend_obj_palettes_to_color_0803F684(0x1B2, gUnk_03000440.unk1C * 2, 0x1FFF);
    blend_obj_palettes_to_color_0803F998(0x1B2, gUnk_03000440.unk1C * 2, 0x3FFF);
    if (gUnk_03000440.unk1C > 8)
        gUnk_03000440.unk4++;
    else
        gUnk_03000440.unk1C++;
}

// run_message state 2: unk2 == 1 jumps to state 4; else show BG0 (the window) at BG0CNT 0x500.
void message_show_window(void)
{
    if (gUnk_03000440.unk2 == 1)
    {
        gUnk_03000440.unk4 = 4;
    }
    else
    {
        gUnk_03000440.unk4++;
        gUnk_03000440.unk26 = 0;
        REG_DISPCNT |= 0x100;
        REG_BG0CNT = 0x500;
    }
}

void sub_0803FC20(void)
{
    switch (gUnk_03000440.unk26)
    {
    case 0:
        lz_decompress_dispatch(gUnk_08487630, (void *)(VRAM + 0x20));
        set_tilemap_and_decompress_bg(0, 0xD, gUnk_08488600, REG_BG0CNT, 1);
        gUnk_03000440.unk26++;
        break;
    case 1:
        lz_decompress_dispatch(gUnk_08487524, (void *)(VRAM + 0x20));
        set_tilemap_and_decompress_bg(0, 0xD, gUnk_084885A8, REG_BG0CNT, 1);
        gUnk_03000440.unk26++;
        break;
    case 2:
        lz_decompress_dispatch(gUnk_084873D0, (void *)(VRAM + 0x20));
        set_tilemap_and_decompress_bg(0, 0xD, gUnk_08488540, REG_BG0CNT, 1);
        gUnk_03000440.unk26++;
        break;
    default:
        gUnk_03000440.unk4++;
        break;
    }
}

void message_clear_text_area(void)
{
    u32 i;
    u8 *dst;

    for (i = 0, dst = (u8 *)0x06000280; i <= 0x33; i++)
    {
        CpuFastSet(gUnk_084C01C8, dst, 0x10);
        dst += 0x40;
    }
    write_tilemap_rect(0x1A, 4, 2, 0xE, gUnk_083B4AE0[18], REG_BG0CNT, 0);
    gUnk_03000440.unk4++;
    sub_0803FD28();
}

INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803FD28);

void sub_0803FEA8(void)
{
    gUnk_03000440.unkC++;
}

INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0803FEB8);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", text_render_glyph_step);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_080402B4);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", reset_text_tile_state);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", update_text_compose_and_input);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_0804070C);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_080407A4);
INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_08040820);

// run_message state 6: run message command gUnk_083B27C0[unk8[unkC + 1]] (each steps through its own table by unk1B).
void message_run_command(void)
{
    gUnk_083B27C0[gUnk_03000440.unk8[gUnk_03000440.unkC + 1]]();
}

void sub_080408F4(void)
{
    gUnk_083B27D4[gUnk_03000440.unk1B]();
}

void sub_08040914(void)
{
    gUnk_083B27EC[gUnk_03000440.unk1B]();
}

void sub_08040934(void)
{
    gUnk_083B2804[gUnk_03000440.unk1B]();
}

void sub_08040954(void)
{
    gUnk_083B2808[gUnk_03000440.unk1B]();
}

void sub_08040974(void)
{
    gUnk_083B2810[gUnk_03000440.unk1B]();
}

INCLUDE_ASM("asm/nonmatching/code_0803CDCC", sub_08040994);

void sub_08040A00(void)
{
    if (gUnk_03000440.unk2 == 1)
    {
        vram_fill_tilemap_rect(0x1E, 6, 0, 0xD, REG_BG0CNT, 0);
        gUnk_03000440.unk1B += 2;
    }
    else
        gUnk_03000440.unk1B++;
}

void sub_08040A40(void)
{
    switch (gUnk_03000440.unk26)
    {
    case 3:
        lz_decompress_dispatch(gUnk_08487524, (void *)(VRAM + 0x20));
        set_tilemap_and_decompress_bg(0, 0xD, gUnk_084885A8, REG_BG0CNT, 1);
        gUnk_03000440.unk26--;
        break;
    case 2:
        lz_decompress_dispatch(gUnk_08487630, (void *)(VRAM + 0x20));
        set_tilemap_and_decompress_bg(0, 0xD, gUnk_08488600, REG_BG0CNT, 1);
        gUnk_03000440.unk26--;
        break;
    case 1:
        vram_fill_tilemap_rect(0x1E, 6, 0, 0xD, REG_BG0CNT, 0);
        gUnk_03000440.unk26--;
        break;
    default:
        gUnk_03000440.unk1B++;
        break;
    }
}

void sub_08040AF0(void)
{
    if (gUnk_03000440.unk0 == 0)
        gUnk_03000440.unk1B += 1;
    else
        gUnk_03000440.unk1B += 2;
}

// Message close step: undo message_dim_palettes_step one frame at a time (unk1C down to 0).
void message_undim_palettes_step(void)
{
    blend_obj_palettes_to_color_0803F684(0x1B2, gUnk_03000440.unk1C * 2, 0x1FFF);
    blend_obj_palettes_to_color_0803F998(0x1B2, gUnk_03000440.unk1C * 2, 0x1FFF);
    if (gUnk_03000440.unk1C == 0)
        gUnk_03000440.unk1B++;
    else
        gUnk_03000440.unk1C--;
}

// Last message close step: run_message state 8 (done, run_message returns 1).
void message_close(void)
{
    gUnk_03000440.unk4 = 8;
}

void sub_08040B5C(void)
{
    u32 i;
    for (i = 0; i <= 0x33; i++)
        CpuCopy16(gUnk_084C01C8, (void *)(VRAM + 0x280 + i * 0x40), 0x40);
    gUnk_03000440.unk1B++;
}

void init_battle_sprite_entry_08040B90(const void *cmds, u8 slot)
{
    const u8 *p;
    u8 i;
    gUnk_03002C30[slot].unk20 = 0;
    gUnk_03002C30[slot].unk21 = 0;
    gUnk_03002C30[slot].unk22 = 0;
    i = 0;
loop:
    p = (const u8 *)cmds + i;
    if (*p > 0xFA)
    {
        i += 3;
        goto loop;
    }
    gUnk_03002C30[slot].unk6 = (p[1] << 8) + p[2];
}

INCLUDE_ASM("asm/nonmatching/code_0803CDCC", process_sprite_anim_commands);

void clear_battle_sprite_slot(u8 a, u8 b)
{
    u32 i;
    u32 zero;

    for (i = 0; i < b; i++)
    {
        zero = 0;
        CpuFastSet(&zero, &gUnk_03002C30[a + i], 0x01000010);
    }
}

void clear_sprite_table_mask(u8 first, u8 count)
{
    u32 i;
    for (i = 0; i < count; i++)
        gUnk_03002C30[first + i].unk0 &= 0x7FFF;
}

void set_sprite_hidden_flags(u8 first, u8 count)
{
    u32 i;
    for (i = 0; i < count; i++)
        gUnk_03002C30[first + i].unk0 |= 0x8000;
}

u32 find_next_free_sprite_slot(u8 first, u8 count)
{
    u8 i;
    u32 slot;
    for (i = 0; i < count; i++)
    {
        slot = first + i;
        if (slot == 0x80)
            return first;
        if (gUnk_03002C30[slot].unk0 == 0)
            return slot;
    }
    return first;
}

INCLUDE_ASM("asm/nonmatching/code_0803CDCC", render_text_sprites_08040DB8);
