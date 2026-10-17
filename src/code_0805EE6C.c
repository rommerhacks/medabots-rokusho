#include "global.h"

void sub_0805EE6C(void)
{
    u32 r = is_sound_playing_with_lock(7);
    if (r == 0)
    {
        gUnk_03000440.unk84 = r;
        gGameSubState++;
    }
}

INCLUDE_ASM("asm/nonmatching/code_0805EE6C", sub_0805EE94);

void dispatch_options_menu_and_update_counters(void)
{
    gUnk_08483C6C[gGameSubState]();
    if (gFrameCounter & 1)
    {
        gBg3Scroll.x++;
        gBg3Scroll.y++;
    }
}

INCLUDE_ASM("asm/nonmatching/code_0805EE6C", silence_and_clear_vram);
INCLUDE_ASM("asm/nonmatching/code_0805EE6C", load_battle_background_graphics);
INCLUDE_ASM("asm/nonmatching/code_0805EE6C", init_fade_screen_setup);

void update_fade_effect(void)
{
    struct Unk_03006F74 *p = gUnk_03006F74;

    if (p->unk0 != 0)
    {
        REG_BLDY = p->unk0-- >> 1;
    }
    else
    {
        p->unk2 = 0;
        p->unk0 = 0;
        gUnk_03006F74->unk6 = 0;
        gUnk_03006F74->unk48 = 0;
        gUnk_03006F74->unk49 = 0;
        gUnk_03006F74->unk4A = 0;
        gUnk_03006F74->unk4B = 0;
        gUnk_03002C30[0].unk0 |= 0x4000;
        gUnk_03002C30[1].unk0 |= 0x4000;
        gGameSubState++;
    }
}

INCLUDE_ASM("asm/nonmatching/code_0805EE6C", options_menu_handler);
INCLUDE_ASM("asm/nonmatching/code_0805EE6C", update_fade_transition_state_0805F778);

void advance_substate_on_handler_complete(void)
{
    if (run_message(gUnk_08485788[3]))
        gGameSubState++;
}

INCLUDE_ASM("asm/nonmatching/code_0805EE6C", sub_0805F81C);

void sub_0805F860(void)
{
    if (run_message(gUnk_08485788[16]))
    {
        if (gUnk_03006F74->unk2++ > 60)
            gGameSubState = 13;
    }
}

void sub_0805F898(void)
{
    if (game_state_execute_handler_a())
        gGameSubState = 4;
}

void sub_0805F8B0(void)
{
    if (run_message(gUnk_08485788[4]))
    {
        play_song(0);
        play_sound_effect(0);
        eeprom_setup_timer_irq();
        gUnk_03006F74->unk2 = 0;
        gGameSubState++;
    }
}

INCLUDE_ASM("asm/nonmatching/code_0805EE6C", sub_0805F8F0);

void sub_0805F974(void)
{
    if (run_message(gUnk_08485788[5]))
    {
        if (gUnk_03006F74->unk2++ > 60)
            gGameSubState = 8;
    }
}

void sub_0805F9AC(void)
{
    if (run_message(gUnk_08485788[6]))
    {
        if (gUnk_03006F74->unk2++ > 60)
            gGameSubState = 8;
    }
}

INCLUDE_ASM("asm/nonmatching/code_0805EE6C", clear_or_fill_bg2_tilemap);

void sub_0805FAF0(void)
{
    gUnk_08483CA4[gGameSubState]();
    if (gFrameCounter & 1)
        gBg3Scroll.y++;
}

INCLUDE_ASM("asm/nonmatching/code_0805EE6C", sub_0805FB2C);
INCLUDE_ASM("asm/nonmatching/code_0805EE6C", sub_0805FBA8);

void sub_0805FD60(void)
{
    struct Unk_03006F74 *p = gUnk_03006F74;

    if (p->unk0 != 0)
    {
        REG_BLDY = p->unk0-- >> 1;
    }
    else
    {
        p->unk2 = 0;
        gUnk_03002C30[1].unk0 |= 0x4000;
        gUnk_03002C30[1].unk1A = 0;
        gGameSubState++;
    }
}

INCLUDE_ASM("asm/nonmatching/code_0805EE6C", sub_0805FDB4);
INCLUDE_ASM("asm/nonmatching/code_0805EE6C", sub_0805FE90);
INCLUDE_ASM("asm/nonmatching/code_0805EE6C", sub_0806006C);

void sub_080600E0(void)
{
    if (++gUnk_03002C30[0].unk1A > 0x3F)
        gUnk_03002C30[0].unk1A = 0;
    gUnk_03002C30[0].unk6 = gUnk_080AF980[(gUnk_03002C30[0].unk1A >> 3) & 7] + 0x100;
}

void sub_08060118(void)
{
    gUnk_08483CC4[gGameSubState]();
    if (gFrameCounter & 1)
        gBg3Scroll.y--;
}

INCLUDE_ASM("asm/nonmatching/code_0805EE6C", sub_08060154);
INCLUDE_ASM("asm/nonmatching/code_0805EE6C", sub_080601A4);

void sub_08060324(void)
{
    sub_080600E0();
    if (KEYS_LO(gNewKeys) & 1)
    {
        play_sound_effect(4);
        gUnk_03006F74->unk0 = 0;
        gGameSubState++;
    }
}

INCLUDE_ASM("asm/nonmatching/code_0805EE6C", sub_0806035C);
INCLUDE_ASM("asm/nonmatching/code_0805EE6C", sub_080603A4);
INCLUDE_ASM("asm/nonmatching/code_0805EE6C", update_battle_sprite_animation);

void update_animation_timer(void)
{
    s32 t;

    if ((u16)++gUnk_03006F74->unk3A > 0x6D)
        gUnk_03006F74->unk3A = 0;
    t = gUnk_03006F74->unk3A;
    if ((s16)(t % 10) == 0)
        CpuSet(gDecompressBuffer + (gUnk_08483E04[(s16)(t / 10)] + 1) * 480, (void *)0x06004020, 0xF0);
}

void dispatch_battle_bg_substate(void)
{
    gUnk_08483DA0[gGameSubState]();
}

INCLUDE_ASM("asm/nonmatching/code_0805EE6C", copy_bg2_tilemap_to_ewram);
INCLUDE_ASM("asm/nonmatching/code_0805EE6C", setup_battle_bg_layers);

void sub_08060804(void)
{
    REG_DISPCNT |= 0x200;
    REG_DISPCNT |= 0x400;
    REG_DISPCNT |= 0x800;
    REG_DISPCNT |= 0x1000;
    gUnk_03006F74->unk0 = 8;
    REG_BLDY = gUnk_03006F74->unk0 * 2;
    gUnk_03006F74->unk3A = 0;
    gGameSubState++;
}

INCLUDE_ASM("asm/nonmatching/code_0805EE6C", sub_0806086C);

void sub_080608B4(void)
{
    u8 i = gUnk_03006F74->unk17;
    if (run_message(gUnk_08485504[i]))
        gGameSubState++;
    update_battle_sprite_animation();
    update_animation_timer();
}

INCLUDE_ASM("asm/nonmatching/code_0805EE6C", sub_080608EC);

void sub_0806098C(void)
{
    update_battle_sprite_animation();
    update_animation_timer();
    if (game_state_execute_handler_a())
    {
        copy_obj_palette_to_buffer();
        gUnk_03000440.unk84 = 0;
        gGameSubState++;
    }
}

INCLUDE_ASM("asm/nonmatching/code_0805EE6C", sub_080609C0);
INCLUDE_ASM("asm/nonmatching/code_0805EE6C", battle_menu_highlight_icons);

void copy_text_with_lookup(dst, src, unused, i)
    u8 *dst;
    u8 *src;
    u32 unused;
    u32 i;
{
    do
    {
        dst[i] = src[i];
        i++;
    } while (src[i] != 0xFF);
    dst[i] = src[i];
    i++;
    dst[i] = src[i];
    dst[2] = gUnk_080AFA10[gUnk_03002420];
}

INCLUDE_ASM("asm/nonmatching/code_0805EE6C", execute_substate_and_tick_counters);
INCLUDE_ASM("asm/nonmatching/code_0805EE6C", sub_08060C6C);
INCLUDE_ASM("asm/nonmatching/code_0805EE6C", clear_vram_da80_region);
INCLUDE_ASM("asm/nonmatching/code_0805EE6C", sub_08060FD4);
INCLUDE_ASM("asm/nonmatching/code_0805EE6C", sub_08061080);
INCLUDE_ASM("asm/nonmatching/code_0805EE6C", sub_08061180);
INCLUDE_ASM("asm/nonmatching/code_0805EE6C", sub_080611D0);

void sub_080612D8(void)
{
    if (game_state_execute_handler_a())
    {
        gUnk_03000440.unk84 = 0;
        gGameSubState++;
    }
}

INCLUDE_ASM("asm/nonmatching/code_0805EE6C", sub_08061300);
INCLUDE_ASM("asm/nonmatching/code_0805EE6C", sub_08061374);

void sub_0806142C(void)
{
    u8 buf[0x30];

    copy_text_with_lookup(buf, gUnk_03006F74->unk5 == 0 ? gUnk_08485551 : gUnk_08485580);
    if (run_message(buf))
        gGameSubState++;
}

INCLUDE_ASM("asm/nonmatching/code_0805EE6C", sub_0806146C);
INCLUDE_ASM("asm/nonmatching/code_0805EE6C", sub_08061678);
INCLUDE_ASM("asm/nonmatching/code_0805EE6C", sub_080616F8);
INCLUDE_ASM("asm/nonmatching/code_0805EE6C", sub_0806174C);

void sub_080617F0(void)
{
    gUnk_08483E8C[gGameSubState]();
    if (gFrameCounter & 1)
    {
        gBg3Scroll.x++;
        gBg3Scroll.y++;
    }
}

void sub_08061830(void)
{
    reset_bg_scroll();
    gGameSubState++;
}

INCLUDE_ASM("asm/nonmatching/code_0805EE6C", setup_bg1_and_decompress_tiles);
INCLUDE_ASM("asm/nonmatching/code_0805EE6C", enable_obj_layer_and_load_palette);
INCLUDE_ASM("asm/nonmatching/code_0805EE6C", sub_08061D30);
INCLUDE_ASM("asm/nonmatching/code_0805EE6C", shop_purchase_menu_handler);
INCLUDE_ASM("asm/nonmatching/code_0805EE6C", transition_fade_to_battle);

void advance_substate_on_handler_complete_1c(void)
{
    if (run_message(gUnk_08485788[7]))
        gGameSubState++;
}

INCLUDE_ASM("asm/nonmatching/code_0805EE6C", shop_complete_transaction);
INCLUDE_ASM("asm/nonmatching/code_0805EE6C", sub_080625EC);
INCLUDE_ASM("asm/nonmatching/code_0805EE6C", sub_08062638);
INCLUDE_ASM("asm/nonmatching/code_0805EE6C", sub_080626A4);
INCLUDE_ASM("asm/nonmatching/code_0805EE6C", fade_out_transition_step);
INCLUDE_ASM("asm/nonmatching/code_0805EE6C", dispatch_substate_handler);
INCLUDE_ASM("asm/nonmatching/code_0805EE6C", init_scene_rendering_context);
INCLUDE_ASM("asm/nonmatching/code_0805EE6C", load_medapart_sprite_animation);

void sub_08062A74(u16 id, u8 second)
{
    const u8 *src;
    u8 *dst;
    u32 i;

    src = (const u8 *)gUnk_083BB9CC[0][id];
    dst = gUnk_03000440.unk9E;
    if (second)
        dst += 0x14;
    for (i = 0; i < 20; i++)
    {
        *dst++ = *src++;
        if (*src == 0xFE)
            break;
    }
    *dst = 0xFE;
}

INCLUDE_ASM("asm/nonmatching/code_0805EE6C", sub_08062AB0);
INCLUDE_ASM("asm/nonmatching/code_0805EE6C", update_animated_tilemap);
INCLUDE_ASM("asm/nonmatching/code_0805EE6C", animate_battle_scroll_tiles);
INCLUDE_ASM("asm/nonmatching/code_0805EE6C", update_scroll_animation_tiles);
INCLUDE_ASM("asm/nonmatching/code_0805EE6C", fade_update_tilemap_copy);
INCLUDE_ASM("asm/nonmatching/code_0805EE6C", sub_08062E3C);
