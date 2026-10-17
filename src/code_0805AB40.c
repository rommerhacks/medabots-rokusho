#include "global.h"

INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805AB40);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", unpack_item_inventory_to_buffer);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", update_battle_medapart_icons);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", calc_fade_sprite_position);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", shop_build_sell_list);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", load_battle_sprite_tiles);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", render_battle_medapart_list);

void sub_0805B3E4(s32 x, s32 y, s32 n)
{
    u16 *base = (u16 *)0x0600B000 + x; u16 *p = base + y * 32; u16 i;
    for (i = 0; i < n; i++)
        *p++ = 0;
}

INCLUDE_ASM("asm/nonmatching/code_0805AB40", get_fade_progress_fifth);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", swap_inventory_items);

void sub_0805B470(struct Unk_03002C30 *attr)
{
    struct Unk_03006F74 *w = gUnk_03006F74;
    if (w->unk12)
    {
        if (w->unk13 >= w->unk11 && w->unk13 < w->unk11 + 5) attr->unk0 |= 0x4000; else attr->unk0 &= 0xBFFF;
    }
}

INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805B4B0);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805B7A0);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", update_battle_sprite_priority_flags);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", decompress_and_write_tilemap);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", tilemap_offset_tiles_and_palette);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", init_multiplayer_id);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", dispatch_game_state_handler_0805BA94);

s16 sub_0805BB10(u16 a)
{
    s16 n;
    if (a > 0xA0)
        a = 0;
    REG_BLDCNT = 0x844;
    n = a;
    REG_BLDALPHA = gUnk_080AF6F0[n / 8] | 0x1000;
    REG_BLDY = 8;
    return n + 1;
}

INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805BB64);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805BBF8);

void sub_0805BC6C(void)
{
    s32 i, j;
    for (i = 0; i <= 2; i++)
    {
        u16 *p = (u16 *)(VRAM + (((REG_BG0CNT >> 8) & 0x1F) << 11)) + 0x167 + i * 96;
        for (j = 0; j < 16; j++)
        {
            *p = (*p & 0xFFF) | 0x8000;
            p++;
        }
    }
}
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805BCC0);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805BDC8);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805BEA0);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805BF88);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805BFDC);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805C030);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805C190);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805C2C4);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805C308);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805C428);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805C6AC);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805C7A0);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805C7E8);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805C85C);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", load_rotation_grid_and_advance);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805C90C);

void sub_0805C940(void)
{
    if (game_state_execute_handler_a())
        dispatch_by_index_0476e8(10);
}

INCLUDE_ASM("asm/nonmatching/code_0805AB40", advance_substate_with_fade);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", fade_step_and_transition_to_mode3);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", dispatch_rotation_menu_substate);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", update_fade_transition_and_counters);

void sub_0805CA28(u32 a)
{
    struct Unk_03006F74 *w = gUnk_03006F74;
    if (w->unk12)
    {
        if (w->unk13 >= w->unk11 && w->unk13 < w->unk11 + 5)
        {
            if (a & 1)
                gUnk_03002C30[84].unk0 &= 0xBFFF;
            else
                gUnk_03002C30[84].unk0 |= 0x4000;
        }
        else
            gUnk_03002C30[84].unk0 &= 0xBFFF;
    }
}

INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805CA94);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805CAD4);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805CC44);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805CD68);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805CDF0);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805CE4C);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", init_fade_sprite_and_start_fade);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805D378);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805D394);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805D418);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", check_ab_press_play_confirm_sound);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805D488);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805D4F0);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805D50C);

void sub_0805D57C(u16 a)
{
    gUnk_03002C30[0].unk6 = gUnk_080AF7E0[a & 3];
}

INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805D59C);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805D5E8);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805D628);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805D6F8);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805D8AC);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805D948);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805D96C);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805D9B8);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805D9E4);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805DA1C);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805DA5C);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805DAE4);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805DB20);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805DB48);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805DB64);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805DBE8);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", init_linking_mode);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", save_dispatch);

u16 eeprom_setup_timer_irq(void)
{
    return sub_0807C7A8(2, &gIntrTable[11]);
}

INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805DD60);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", load_save_data);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", serialize_save_data);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", validate_save_data);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sync_save_or_link_data);

void sub_0805E170(u16 a)
{
    gUnk_03002C30[20].unk6 = gUnk_080AF808[a & 3];
}

INCLUDE_ASM("asm/nonmatching/code_0805AB40", calc_text_pixel_width);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805E29C);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805E2E8);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805E310);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805E5B0);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805E878);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805E8DC);
