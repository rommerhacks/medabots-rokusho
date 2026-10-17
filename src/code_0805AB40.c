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

void sub_0805D378(void)
{
    if (game_state_execute_handler_a())
        gGameSubState++;
}

INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805D394);

void sub_0805D418(void)
{
    if (run_message(gUnk_08485788[8]))
        gGameSubState++;
}

INCLUDE_ASM("asm/nonmatching/code_0805AB40", check_ab_press_play_confirm_sound);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805D488);

void sub_0805D4F0(void)
{
    if (game_state_execute_handler_a())
        gGameSubState++;
}

INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805D50C);

void sub_0805D57C(u16 a)
{
    gUnk_03002C30[0].unk6 = gUnk_080AF7E0[a & 3];
}

void sub_0805D59C(void)
{
    gUnk_08483BDC[gGameSubState]();
    if (gFrameCounter & 1)
    {
        gBg3Scroll.x++;
        gBg3Scroll.y++;
    }
    sub_0805D57C(gFrameCounter >> 3);
}

void sub_0805D5E8(void)
{
    u32 zero = 0;
    CpuFastSet(&zero, gUnk_03006F74, 0x01000100);
    reset_bg_scroll();
    REG_DISPCNT = 0x160;
    gGameSubState++;
}

INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805D628);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805D6F8);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805D8AC);

void sub_0805D948(void)
{
    if (run_message(gUnk_08485788[9]))
        gGameSubState++;
}

INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805D96C);

void sub_0805D9B8(void)
{
    if (run_message(gUnk_08485BD8[18]))
    {
        open_choice_menu(1, 0x16, 7);
        gGameSubState++;
    }
}

void sub_0805D9E4(void)
{
    if (poll_choice_menu())
    {
        sub_0803FB0C();
        if (gUnk_03000440.unk2A == 0)
            gGameSubState = 6;
        else
            gGameSubState = 9;
    }
}

void sub_0805DA1C(void)
{
    if (run_message(gUnk_08485788[10]))
    {
        play_song(0);
        play_sound_effect(0);
        eeprom_setup_timer_irq();
        gUnk_03006F74->unk2 = 0;
        gGameSubState++;
    }
}

INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805DA5C);

void sub_0805DAE4(void)
{
    u8 t = gUnk_03006F74->unk2++;
    if (run_message(gUnk_08485788[11]) && t > 60)
        gGameSubState++;
}

void sub_0805DB20(void)
{
    sub_0803FB0C();
    copy_obj_palette_to_buffer();
    gUnk_03000440.unk84 = 0;
    gGameSubState++;
}

void sub_0805DB48(void)
{
    if (game_state_execute_handler_a())
        gGameSubState++;
}

INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805DB64);

void sub_0805DBE8(void)
{
    u8 t = gUnk_03006F74->unk2++;
    if (run_message(gUnk_08485788[12]) && t > 60)
        gGameSubState = 9;
}

INCLUDE_ASM("asm/nonmatching/code_0805AB40", init_linking_mode);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", save_dispatch);

u16 eeprom_setup_timer_irq(void)
{
    return sub_0807C7A8(2, &gIntrTable[11]);
}

INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805DD60);

void load_save_data(struct SaveData *save)
{
    s32 i;
    struct Unk_03000BE0 *medal;

    gUnk_03002B70 = save->unk10;
    medal = save->medals;
    for (i = 0; i < 30; i++)
    {
        memcpy_optimized(&gUnk_03000BE0[i], medal, sizeof(struct Unk_03000BE0));
        medal++;
    }
    for (i = 0; i < 0x3C0; i++)
        gMedapartInventory[i] = save->medaparts[i];
    for (i = 0; i < 9; i++)
        gUnk_030017A0[i] = save->team[i];
    CpuSet(save->items, gItemInventory, 0x40);
    CpuSet(save->field, &gUnk_030057E0, 0x660);
    gUnk_03001788 = save->flags & 3;
    gUnk_03001360 = (save->flags >> 2) & 1;
    gUnk_03000B94 = (save->flags >> 3) & 3;
    gUnk_03001784.unk0_1 = (save->flags >> 5) & 1;
}

void serialize_save_data(struct SaveData *save)
{
    s32 i;
    u16 sum;
    u8 *p;
    struct Unk_03000BE0 *medal;

    for (i = 0; i < 16; i++)
        save->magic[i] = gSaveMagic[i];
    save->unk10 = gUnk_03002B70;
    medal = save->medals;
    for (i = 0; i < 30; i++)
    {
        memcpy_optimized(medal, &gUnk_03000BE0[i], sizeof(struct Unk_03000BE0));
        medal++;
    }
    for (i = 0; i < 0x3C0; i++)
        save->medaparts[i] = gMedapartInventory[i];
    for (i = 0; i < 9; i++)
        save->team[i] = gUnk_030017A0[i];
    CpuSet(gItemInventory, save->items, 0x40);
    CpuSet(&gUnk_030057E0, save->field, 0x660);
    save->flags = gUnk_03001788 | (gUnk_03001360 << 2) | (gUnk_03000B94 << 3) | (gUnk_03001784.unk0_1 << 5);
    save->checksum = 0;
    sum = 0;
    p = (u8 *)save;
    for (i = 0; i < sizeof(struct SaveData); i++)
        sum += *p++;
    save->checksum = sum;
}

s32 validate_save_data(struct SaveData *save)
{
    u16 buf[4];
    u16 *p;
    s32 i;
    s32 n;
    u8 *b;
    u16 sum;
    u32 tmp; // the empty-name flag, then the stored checksum (one variable in the original)

    n = 920;
    p = (u16 *)save;
    for (i = 0; i < n; i++)
    {
        ReadEepromDword(i, buf);
        *p++ = buf[0];
        *p++ = buf[1];
        *p++ = buf[2];
        *p++ = buf[3];
    }
    for (i = 0; i < 16; i++)
    {
        if (gSaveMagic[i] != save->magic[i])
            return 1;
    }
    tmp = TRUE;
    for (i = 0; i < 16; i++)
    {
        if (save->unk10.unk4[i] == 0xFE)
            break;
        if (save->unk10.unk4[i] != 0)
        {
            tmp = FALSE;
            break;
        }
    }
    if (tmp)
        return -1;
    if (save->unk10.money > 99999)
        return -1;
    if (save->unk10.unk14[0] > 9999)
        return -1;
    if (save->unk10.unk14[0] < save->unk10.unk14[1])
        return -1;
    if (save->unk10.unk18 > 0x014996FF)
        return -1;
    if ((save->flags & 3) > 2)
        return -1;
    if (((save->flags >> 3) & 3) > 2)
        return -1;
    tmp = save->checksum;
    save->checksum = 0;
    sum = 0;
    b = (u8 *)save;
    for (i = 0; i < sizeof(struct SaveData); i++)
        sum += *b++;
    if (sum != tmp)
        return -1;
    return 0;
}

s32 sync_save_or_link_data(u16 *src, u32 force)
{
    u16 buf[4];
    s32 i;
    s32 n;
    u16 changed;
    u32 j;

    n = 920;
    if ((u8)force)
    {
        for (i = 0; i < n; i++)
        {
            buf[0] = *src++;
            buf[1] = *src++;
            buf[2] = *src++;
            buf[3] = *src++;
            ProgramEepromDwordEx(i, buf);
        }
    }
    else
    {
        for (i = 0; i < n; i++)
        {
            changed = ReadEepromDword(i, buf);
            for (j = 0; j < 4; j++)
            {
                if (buf[j] != *src)
                {
                    buf[j] = *src;
                    changed = 1;
                }
                src++;
            }
            if (changed)
                ProgramEepromDwordEx(i, buf);
        }
    }
    return 0;
}

void sub_0805E170(u16 a)
{
    gUnk_03002C30[20].unk6 = gUnk_080AF808[a & 3];
}

INCLUDE_ASM("asm/nonmatching/code_0805AB40", calc_text_pixel_width);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805E29C);

void sub_0805E2E8(void)
{
    clear_battle_sprite_slot(0, 0x80);
    reset_bg_scroll();
    REG_DISPCNT = 0x60;
    gGameSubState++;
}

INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805E310);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805E5B0);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805E878);
INCLUDE_ASM("asm/nonmatching/code_0805AB40", sub_0805E8DC);
