#include "global.h"

void sub_08030CAC(void)
{
    CpuFastSet(gUnk_084E2EF8, (void *)0x05000300, 8);
    CpuFastSet(gUnk_084E2F18, (void *)0x05000320, 8);
    CpuFastSet(gUnk_084E2F38, (void *)0x05000340, 8);
    gGameState = 7;
    gGameSubState = 0x46;
}

void sub_08030CFC(void)
{
    if (gUnk_03000590[gUnk_03001800.unk87].unkC1 == 0x50)
        gGameSubState++;
    else
    {
        sub_0801AEB4();
        gGameSubState = 0x14;
    }
}

void sub_08030D3C(void)
{
    if (sub_0801C154())
        gGameSubState++;
}

void sub_08030D58(void)
{
    if (sub_0801C0BC(0))
        gGameSubState++;
}

void sub_08030D74(void)
{
    if (dispatch_battle_action_substate(0))
        gGameSubState++;
}

void sub_08030D90(void)
{
    dispatch_battle_action_substate(0);
    if (sub_0801C0BC(1))
        gGameSubState++;
}

void sub_08030DB4(void)
{
    dispatch_battle_action_substate(0);
    play_sound_effect(0x51);
    if (gUnk_03000590[gUnk_03001800.unk87].unkC0 & 8)
        gUnk_03001800.unk51 = 0x50;
    else
        gUnk_03001800.unk51 = 0x28;
    sub_0801B004(gUnk_03001800.unk87);
    gGameSubState++;
}

void sub_08030E14(void)
{
    u32 done;

    dispatch_battle_action_substate(0);
    done = medaforce_gauge_fill_step(gUnk_03001800.unk87);
    done += sub_0801B0E8(gUnk_03001800.unk87);
    if (done == 2)
    {
        clear_battle_ui_tilemaps();
        sub_0801AEB4();
        gGameSubState++;
    }
}

void sub_08030E54(void)
{
    if (sub_0801C0BC(gUnk_03001800.unkA6))
        gGameSubState++;
}

void sub_08030E78(void)
{
    lz_decompress_dispatch(gUnk_084C6A98, (void *)0x06017400);
    increment_medal_skill_level(gUnk_03001800.unk87);
    sub_0801B274(gUnk_03001800.unk87);
    gUnk_03000440.unk9C = 0;
    if (gUnk_03000590[0].unk40 == 0)
    {
        gUnk_03000440.unk9C = 2;
        sound_stop_all_with_fade_guard(4);
        play_sound_effect(0x6F);
        gGameSubState++;
    }
    else if (gUnk_03000590[3].unk40 == 0)
    {
        gUnk_03000440.unk9C = 1;
        sound_stop_all_with_fade_guard(4);
        play_sound_effect(0x6F);
        gGameSubState++;
    }
    else
        gGameSubState = 0x48;
}

void sub_08030F10(void)
{
    lz_decompress_dispatch(gUnk_084C84E4, (void *)0x06014800);
    CpuFastSet(gUnk_084E2FD8, (void *)0x050003E0, 8);
    gUnk_03002C30[0x21].unk0 = 0xC624;
    gUnk_03002C30[0x21].unk1C = 0;
    gUnk_03002C30[0x21].unk2 = 0x78;
    gUnk_03002C30[0x21].unk4 = 0x40;
    gUnk_03002C30[0x21].unkA = 0xF;
    gUnk_03002C30[0x21].unkB = 0xC0;
    gUnk_03002C30[0x21].unk6 = 0x902;
    gUnk_03002C30[0x21].unk9 = 0x80;
    gUnk_03002C30[0x21].unk8 = 0x40;
    gGameSubState++;
}

void sub_08030FB4(void)
{
    if (gUnk_03002C30[0x21].unk9 == 0x40)
    {
        gUnk_03000440.unk86 = 0;
        gGameSubState++;
    }
    else
        gUnk_03002C30[0x21].unk9 -= 8;
}

void sub_08030FEC(void)
{
    if (gUnk_03000440.unk86 == 0x5A)
    {
        if (gUnk_03002C30[0x21].unk9 == 8)
        {
            play_song(0x1C);
            clear_battle_sprite_slot(0x21, 1);
            text_window_init(1, 2, 0);
            gGameSubState++;
        }
        else
            gUnk_03002C30[0x21].unk9 -= 8;
    }
    else
        gUnk_03000440.unk86++;
}

void sub_08031048(void)
{
    if (gUnk_03000440.unk86 == 0x5A)
    {
        if (gUnk_03002C30[0x21].unk9 == 8)
        {
            clear_battle_sprite_slot(0x21, 1);
            text_window_init(1, 2, 0);
            gGameSubState++;
        }
        else
            gUnk_03002C30[0x21].unk9 -= 8;
    }
    else
        gUnk_03000440.unk86++;
}

void sub_080310A0(void)
{
    if (gUnk_03000440.unk9C == 1)
        memcpy_bytes_0803F63C(gUnk_03002B74, gUnk_03000440.unk9E, 0xE);
    else if (gUnk_03000440.unk89 != 1)
        memcpy_bytes_0803F63C(gUnk_083C3F38[gUnk_03001800.unk0], gUnk_03000440.unk9E, 0x12);
    else
        memcpy_bytes_0803F63C(gUnk_0300198A, gUnk_03000440.unk9E, 0x12);
    if (run_message(gUnk_083C65C4[2]))
        gGameSubState++;
}

void sub_08031120(void)
{
    if (gUnk_03001800.unk57)
    {
        if (gUnk_03001800.unk165)
            gGameSubState = 0x60;
        else
            gGameSubState = 0x4F;
    }
    else
    {
        robattle_judge_time_up();
        play_song(0x11);
        gGameSubState++;
    }
}

void sub_08031174(void)
{
    lz_decompress_dispatch(gUnk_084C84E4, (void *)0x06014800);
    CpuFastSet(gUnk_084E2FD8, (void *)0x050003E0, 8);
    gUnk_03002C30[0x21].unk0 = 0xC624;
    gUnk_03002C30[0x21].unk1C = 0;
    gUnk_03002C30[0x21].unk2 = 0x78;
    gUnk_03002C30[0x21].unk4 = 0x40;
    gUnk_03002C30[0x21].unkA = 0xF;
    gUnk_03002C30[0x21].unkB = 0xC0;
    gUnk_03002C30[0x21].unk6 = 0x903;
    gUnk_03002C30[0x21].unk9 = 0x80;
    gUnk_03002C30[0x21].unk8 = 0x40;
    gGameSubState++;
}

void sub_08031218(void)
{
    if (gUnk_03000440.unk9C == 1)
        memcpy_bytes_0803F63C(gUnk_03002B74, gUnk_03000440.unk9E, 0xE);
    else if (gUnk_03000440.unk89 != 1)
        memcpy_bytes_0803F63C(gUnk_083C3F38[gUnk_03001800.unk0], gUnk_03000440.unk9E, 0x12);
    else
        memcpy_bytes_0803F63C(gUnk_0300198A, gUnk_03000440.unk9E, 0x12);
    if (run_message(gUnk_083C65C4[3]))
        gGameSubState++;
}

void sub_08031298(void)
{
    if (gUnk_03000440.unk89 != 1)
    {
        sound_stop_all_with_fade_guard(8);
        gGameSubState++;
    }
    else
        gGameSubState = 0x58;
}

void sub_080312CC(void)
{
    copy_obj_palette_to_buffer();
    gUnk_03000440.unk84 = 0;
    gGameSubState++;
}

void sub_080312F0(void)
{
    if (gUnk_03000440.unk84 <= 8)
    {
        blend_obj_palettes_to_color_0803F684(0, gUnk_03000440.unk84 * 4, 0xFFFF);
        blend_obj_palettes_to_color_0803F998(0, gUnk_03000440.unk84 * 4, 0xFFFF);
        gUnk_03000440.unk84++;
    }
    else
        gGameSubState++;
}

void sub_0803133C(void)
{
    gVBlankCallback = nullsub_08000840;
    gUnk_03000440.unk132 = 1;
    if (gUnk_03000440.unk89 != 1)
    {
        gGameState = 6;
        gGameSubState = 0x30;
    }
    else
    {
        gGameState = 10;
        gGameSubState = 0x20;
    }
}

void sub_08031390(void)
{
    lz_decompress_dispatch(gUnk_084D796C, (void *)0x06014800);
    gUnk_03002C30[0x21].unk0 = 0xC404;
    gUnk_03002C30[0x21].unk1C = 0;
    gUnk_03002C30[0x21].unk2 = gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk2;
    gUnk_03002C30[0x21].unk4 = gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 4;
    gUnk_03002C30[0x21].unkA = 0xC;
    gUnk_03002C30[0x21].unkB = 0x80;
    gUnk_03002C30[0x21].unk6 = 0x5800;
    gUnk_03002C30[0x21].unk23 = 0;
    play_sound_effect(0x2A);
    gGameSubState++;
}

void sub_08031438(void)
{
    if (advance_sprite_anim_frame(0x21, 0))
        gGameSubState++;
}

void sub_08031458(void)
{
    gUnk_03002C30[0x22].unk0 = 0xC404;
    gUnk_03002C30[0x22].unk1C = 0;
    gUnk_03002C30[0x22].unk2 = gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk2 - 0x10;
    gUnk_03002C30[0x22].unk4 = gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk4 + 4;
    gUnk_03002C30[0x22].unkA = gUnk_083AED18[gUnk_03001800.unk166];
    gUnk_03002C30[0x22].unkB = 0x80;
    gUnk_03002C30[0x22].unk6 = 0x5801 + gUnk_03001800.unk166;
    gUnk_03002C30[0x22].unk23 = 0;
    play_sound_effect(0x2A);
    gGameSubState++;
}

void sub_08031518(void)
{
    if (medal_update_exp_progress(0x22, 0))
        gGameSubState++;
}

void sub_08031538(void)
{
    lz_decompress_dispatch(gUnk_084D6BFC, (void *)0x06017E00);
    set_display_digit_type(&gUnk_03000440.unkEE, gUnk_03001800.unk167, 2);
    battle_setup_text_sprites_0801A4F4(&gUnk_03000440.unkEE, gUnk_03001800.unk87, 0x23,
        gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk2 + 0x18,
        gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk4 + 4);
    gUnk_03000440.unk84 = 0;
    gGameSubState++;
}

void sub_080315B0(void)
{
    update_battle_sprite_animations(&gUnk_03000440.unkEE, gUnk_03001800.unk87, 0x23);
    if (++gUnk_03000440.unk84 == 0x78)
    {
        clear_battle_sprite_slot(0x21, 2);
        clear_battle_sprite_slot(gUnk_03001800.unk87 * 4 + 0x23, 4);
        gGameSubState++;
    }
}

void sub_08031608(void)
{
    gGameSubState = 0x4F;
}

void sub_08031614(void)
{
    sub_0801AEB4();
    if (gUnk_03001800.unk58)
    {
        gUnk_03001800.unkA6 = 0x79;
        gGameSubState++;
    }
    else if (gUnk_03001800.unkA7 == 0 && gUnk_03000590[gUnk_03001800.unk87].medal.unk5 <= 9)
    {
        gUnk_03001800.unkA6 = 0x36;
        gGameSubState++;
    }
    else if (gUnk_03001800.unkA7 == 1 && gUnk_03000590[gUnk_03001800.unk87].medal.unk5 <= 0x1D)
    {
        gUnk_03001800.unkA6 = 0x36;
        gGameSubState++;
    }
    else if (gUnk_03001800.unkA7 == 2 && gUnk_03000590[gUnk_03001800.unk87].medal.unk5 <= 0x3B)
    {
        gUnk_03001800.unkA6 = 0x36;
        gGameSubState++;
    }
    else if (gUnk_03000590[gUnk_03001800.unk87].unkC1 != 0x50)
    {
        gUnk_03001800.unkA6 = 0x37;
        gGameSubState++;
    }
    else
        gGameSubState = 0x34;
}

void sub_08031704(void)
{
    dispatch_battle_action_substate(0);
    CpuFastSet(gUnk_084E3018, (void *)0x050002E0, 8);
    gUnk_03002C30[0x21].unk0 = ((gUnk_03001800.unk39[3] + 2) << 10) | 0xC004;
    gUnk_03002C30[0x21].unk1C = 0;
    gUnk_03002C30[0x21].unk2 = gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk2;
    gUnk_03002C30[0x21].unk4 = gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 4;
    gUnk_03002C30[0x21].unkA = 7;
    gUnk_03002C30[0x21].unkB = 0x81;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x4D], 0x21);
    gUnk_03002C30[0x22].unk0 = ((gUnk_03001800.unk39[3] + 2) << 10) | 0xC004;
    gUnk_03002C30[0x22].unk1C = 0;
    gUnk_03002C30[0x22].unk2 = gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk2;
    gUnk_03002C30[0x22].unk4 = gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 4;
    gUnk_03002C30[0x22].unkA = 7;
    gUnk_03002C30[0x22].unkB = gUnk_03001800.unk87 * 4 + 0x59;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x4E], 0x22);
    gUnk_03001800.unk51 = gUnk_03000590[gUnk_03001800.unk87].unkA8[2];
    gGameSubState++;
}

void sub_0803185C(void)
{
    dispatch_battle_action_substate(0);
    medaforce_gauge_drain_step(gUnk_03001800.unk87);
    process_sprite_anim_commands(gUnk_083B5F80[0x4D], 0x21);
    process_sprite_anim_commands(gUnk_083B5F80[0x4E], 0x22);
    if (gUnk_03002C30[0x21].unk22 == 0xFF)
    {
        clear_battle_ui_tilemaps();
        sub_0801AEB4();
        clear_battle_sprite_slot(0x21, 2);
        gGameSubState++;
    }
}

void sub_080318CC(void)
{
    memcpy_bytes_0803F63C((void *)gUnk_083B7338[gUnk_03000590[gUnk_03001800.unk87].unkA8[0]], gUnk_03000440.unk9E, 0x11);
    gUnk_03001800.unkA6 = 0x38;
    gGameSubState++;
}

void battle_start_transition_to_action(void)
{
    gUnk_03001800.unk164 = 1;
    gUnk_03001800.unkA8 = gUnk_03000590[gUnk_03001800.unk87].unkA8[0] + 0x50;
    gUnk_03000590[gUnk_03001800.unk87].unkE0 = 0;
    gUnk_03000590[gUnk_03001800.unk87].unkE1 = 0;
    gGameState = 9;
    gGameSubState = 0;
}

void sub_08031978(void)
{
    text_window_init(1, 0, 0);
    gGameSubState++;
}

void sub_08031994(void)
{
    if (run_message(gUnk_083CF3B0[1]))
        gGameSubState++;
}

void sub_080319B8(void)
{
    if (sub_0803E79C())
    {
        gUnk_03000440.unk86 = 0;
        gGameSubState++;
    }
}

void sub_080319E0(void)
{
    if (gUnk_03000440.unk86 == 8)
        gGameSubState++;
    else
        gUnk_03000440.unk86++;
}

void sub_08031A08(void)
{
    if (game_state_execute_handler_a())
        gGameSubState++;
}

void sub_08031A24(void)
{
    sound_stop_all_with_fade_guard(8);
    gGameSubState = 0x51;
}

void battle_process_all_bot_actions(u32 rec)
{
    u32 i;

    gUnk_03001800.unk5C = rec;
    gUnk_03001800.unk5D = 0;
    for (i = 0; i <= 2; i++)
    {
        battle_execute_action_selection();
        call_bot_action_handler();
        gUnk_03001800.unk5D++;
    }
}

void battle_execute_action_selection(void)
{
    clear_battle_action_selection();
    sub_0803F624(gUnk_03001800.unk61, 3, 0);
    gUnk_083AED20[gUnk_03000590[gUnk_03001800.unk5C].parts[gUnk_03001800.unk5D].data[1]]();
}

void call_bot_action_handler(void)
{
    gUnk_083AEE10[gUnk_03000590[gUnk_03001800.unk5C].parts[gUnk_03001800.unk5D].data[1]]();
}

void select_battle_targets_and_actions(void)
{
    u32 i;

    gUnk_03001800.unk60 = sub_08032FB8(gUnk_03001800.unk5C);
    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03000590[gUnk_03001800.unk60].unk40
         && sub_08032FD0(gUnk_03001800.unk60, gUnk_03000590[gUnk_03001800.unk5C].medal.unk6))
            gUnk_03001800.unk61[i] = gUnk_03001800.unk60 + 1;
        gUnk_03001800.unk60++;
    }
    if (sub_08032FFC())
        gUnk_03001800.unk5E = select_battle_pending_action() + 1;
    else
    {
        gUnk_03001800.unk60 = sub_08032FB8(gUnk_03001800.unk5C);
        gUnk_03001800.unk5E = select_random_battle_target(gUnk_03001800.unk60) + 1;
    }
    gUnk_03001800.unk5F = sub_080330E8(gUnk_03001800.unk5E - 1) + 1;
    sub_08033154(gUnk_03001800.unk5C, gUnk_03001800.unk5D);
}

void battle_ai_select_target_defend(void)
{
    u32 i;

    gUnk_03001800.unk60 = sub_08032FB8(gUnk_03001800.unk5C);
    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03000590[gUnk_03001800.unk60].unk40 && gUnk_03000590[gUnk_03001800.unk60].parts[3].data[1] == 0x64
         && sub_08032FD0(gUnk_03001800.unk60, gUnk_03000590[gUnk_03001800.unk5C].medal.unk6))
            gUnk_03001800.unk61[i] = gUnk_03001800.unk60 + 1;
        gUnk_03001800.unk60++;
    }
    if (sub_08032FFC())
        gUnk_03001800.unk5E = select_battle_pending_action() + 1;
    else
    {
        gUnk_03001800.unk60 = sub_08032FB8(gUnk_03001800.unk5C);
        for (i = 0; i <= 2; i++)
        {
            if (gUnk_03000590[gUnk_03001800.unk60].unk40 && gUnk_03000590[gUnk_03001800.unk60].parts[3].data[1] == 0x64)
                gUnk_03001800.unk61[i] = gUnk_03001800.unk60 + 1;
            gUnk_03001800.unk60++;
        }
        if (sub_08032FFC())
            gUnk_03001800.unk5E = select_battle_pending_action() + 1;
        else
        {
            gUnk_03001800.unk60 = sub_08032FB8(gUnk_03001800.unk5C);
            for (i = 0; i <= 2; i++)
            {
                if (gUnk_03000590[gUnk_03001800.unk60].unk40
                 && sub_08032FD0(gUnk_03001800.unk60, gUnk_03000590[gUnk_03001800.unk5C].medal.unk6))
                    gUnk_03001800.unk61[i] = gUnk_03001800.unk60 + 1;
                gUnk_03001800.unk60++;
            }
            if (sub_08032FFC())
                gUnk_03001800.unk5E = select_battle_pending_action() + 1;
            else
            {
                gUnk_03001800.unk60 = sub_08032FB8(gUnk_03001800.unk5C);
                gUnk_03001800.unk5E = select_random_battle_target(gUnk_03001800.unk60) + 1;
            }
        }
    }
    gUnk_03001800.unk5F = sub_080330E8(gUnk_03001800.unk5E - 1) + 1;
    sub_08033154(gUnk_03001800.unk5C, gUnk_03001800.unk5D);
}

void battle_ai_select_target_jump(void)
{
    u32 i;

    gUnk_03001800.unk60 = sub_08032FB8(gUnk_03001800.unk5C);
    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03000590[gUnk_03001800.unk60].unk40 && gUnk_03000590[gUnk_03001800.unk60].parts[3].data[1] == 0x6A
         && sub_08032FD0(gUnk_03001800.unk60, gUnk_03000590[gUnk_03001800.unk5C].medal.unk6))
            gUnk_03001800.unk61[i] = gUnk_03001800.unk60 + 1;
        gUnk_03001800.unk60++;
    }
    if (sub_08032FFC())
        gUnk_03001800.unk5E = select_battle_pending_action() + 1;
    else
    {
        gUnk_03001800.unk60 = sub_08032FB8(gUnk_03001800.unk5C);
        for (i = 0; i <= 2; i++)
        {
            if (gUnk_03000590[gUnk_03001800.unk60].unk40 && gUnk_03000590[gUnk_03001800.unk60].parts[3].data[1] == 0x6A)
                gUnk_03001800.unk61[i] = gUnk_03001800.unk60 + 1;
            gUnk_03001800.unk60++;
        }
        if (sub_08032FFC())
            gUnk_03001800.unk5E = select_battle_pending_action() + 1;
        else
        {
            gUnk_03001800.unk60 = sub_08032FB8(gUnk_03001800.unk5C);
            for (i = 0; i <= 2; i++)
            {
                if (gUnk_03000590[gUnk_03001800.unk60].unk40
                 && sub_08032FD0(gUnk_03001800.unk60, gUnk_03000590[gUnk_03001800.unk5C].medal.unk6))
                    gUnk_03001800.unk61[i] = gUnk_03001800.unk60 + 1;
                gUnk_03001800.unk60++;
            }
            if (sub_08032FFC())
                gUnk_03001800.unk5E = select_battle_pending_action() + 1;
            else
            {
                gUnk_03001800.unk60 = sub_08032FB8(gUnk_03001800.unk5C);
                gUnk_03001800.unk5E = select_random_battle_target(gUnk_03001800.unk60) + 1;
            }
        }
    }
    gUnk_03001800.unk5F = sub_080330E8(gUnk_03001800.unk5E - 1) + 1;
    sub_08033154(gUnk_03001800.unk5C, gUnk_03001800.unk5D);
}

void ai_select_target_enemy_side_ability22_status(void)
{
    u32 i;

    gUnk_03001800.unk60 = sub_08032FC4(gUnk_03001800.unk5C);
    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03000590[gUnk_03001800.unk60].unk40
         && sub_080331F8(gUnk_03001800.unk60)
         && gUnk_03000590[gUnk_03001800.unk60].unkC9
         && sub_08032FD0(gUnk_03001800.unk60, gUnk_03000590[gUnk_03001800.unk5C].medal.unk6))
            gUnk_03001800.unk61[i] = gUnk_03001800.unk60 + 1;
        gUnk_03001800.unk60++;
    }
    if (sub_08032FFC())
        gUnk_03001800.unk5E = select_battle_pending_action() + 1;
    else
    {
        gUnk_03001800.unk60 = sub_08032FC4(gUnk_03001800.unk5C);
        for (i = 0; i <= 2; i++)
        {
            if (gUnk_03000590[gUnk_03001800.unk60].unk40
             && sub_080331F8(gUnk_03001800.unk60)
             && gUnk_03000590[gUnk_03001800.unk60].unkC9)
                gUnk_03001800.unk61[i] = gUnk_03001800.unk60 + 1;
            gUnk_03001800.unk60++;
        }
        if (sub_08032FFC())
            gUnk_03001800.unk5E = select_battle_pending_action() + 1;
        else
        {
            gUnk_03001800.unk60 = sub_08032FC4(gUnk_03001800.unk5C);
            for (i = 0; i <= 2; i++)
            {
                if (gUnk_03000590[gUnk_03001800.unk60].unk40
                 && sub_080331F8(gUnk_03001800.unk60)
                 && sub_08032FD0(gUnk_03001800.unk60, gUnk_03000590[gUnk_03001800.unk5C].medal.unk6))
                    gUnk_03001800.unk61[i] = gUnk_03001800.unk60 + 1;
                gUnk_03001800.unk60++;
            }
            if (sub_08032FFC())
                gUnk_03001800.unk5E = select_battle_pending_action() + 1;
            else
            {
                gUnk_03001800.unk60 = sub_08032FC4(gUnk_03001800.unk5C);
                gUnk_03001800.unk5E = select_random_battle_target(gUnk_03001800.unk60) + 1;
            }
        }
    }
    gUnk_03001800.unk5F = sub_080330E8(gUnk_03001800.unk5E - 1) + 1;
    sub_08033154(gUnk_03001800.unk5C, gUnk_03001800.unk5D);
}

void ai_pick_ally_most_damaged(void)
{
    u32 i;
    u32 part;

    gUnk_03001800.unk60 = sub_08032FC4(gUnk_03001800.unk5C);
    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03000590[gUnk_03001800.unk60].unk40
         && find_most_damaged_part(gUnk_03001800.unk60)
         && sub_08032FD0(gUnk_03001800.unk60, gUnk_03000590[gUnk_03001800.unk5C].medal.unk6))
            gUnk_03001800.unk61[i] = gUnk_03001800.unk60 + 1;
        gUnk_03001800.unk60++;
    }
    if (sub_08032FFC())
        gUnk_03001800.unk5E = select_battle_pending_action() + 1;
    else
    {
        gUnk_03001800.unk60 = sub_08032FC4(gUnk_03001800.unk5C);
        for (i = 0; i <= 2; i++)
        {
            if (gUnk_03000590[gUnk_03001800.unk60].unk40
             && find_most_damaged_part(gUnk_03001800.unk60))
                gUnk_03001800.unk61[i] = gUnk_03001800.unk60 + 1;
            gUnk_03001800.unk60++;
        }
        if (sub_08032FFC())
            gUnk_03001800.unk5E = select_battle_pending_action() + 1;
        else
        {
            gUnk_03001800.unk60 = sub_08032FC4(gUnk_03001800.unk5C);
            for (i = 0; i <= 2; i++)
            {
                if (gUnk_03000590[gUnk_03001800.unk60].unk40
                 && sub_08032FD0(gUnk_03001800.unk60, gUnk_03000590[gUnk_03001800.unk5C].medal.unk6))
                    gUnk_03001800.unk61[i] = gUnk_03001800.unk60 + 1;
                gUnk_03001800.unk60++;
            }
            if (sub_08032FFC())
                gUnk_03001800.unk5E = select_battle_pending_action() + 1;
            else
            {
                gUnk_03001800.unk60 = sub_08032FC4(gUnk_03001800.unk5C);
                gUnk_03001800.unk5E = select_random_battle_target(gUnk_03001800.unk60) + 1;
            }
        }
    }
    part = find_most_damaged_part(gUnk_03001800.unk5E - 1);
    if (part)
        gUnk_03001800.unk5F = part;
    else
        gUnk_03001800.unk5F = sub_080330E8(gUnk_03001800.unk5E - 1) + 1;
    sub_08033154(gUnk_03001800.unk5C, gUnk_03001800.unk5D);
}

void battle_ai_select_target_ability22_enemy(void)
{
    u32 i;

    gUnk_03001800.unk60 = sub_08032FC4(gUnk_03001800.unk5C);
    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03000590[gUnk_03001800.unk60].unk40
         && sub_080331F8(gUnk_03001800.unk60)
         && sub_08033224(gUnk_03001800.unk60)
         && sub_08032FD0(gUnk_03001800.unk60, gUnk_03000590[gUnk_03001800.unk5C].medal.unk6))
            gUnk_03001800.unk61[i] = gUnk_03001800.unk60 + 1;
        gUnk_03001800.unk60++;
    }
    if (sub_08032FFC())
        gUnk_03001800.unk5E = select_battle_pending_action() + 1;
    else
    {
        gUnk_03001800.unk60 = sub_08032FC4(gUnk_03001800.unk5C);
        for (i = 0; i <= 2; i++)
        {
            if (gUnk_03000590[gUnk_03001800.unk60].unk40
             && sub_080331F8(gUnk_03001800.unk60)
             && sub_08033224(gUnk_03001800.unk60))
                gUnk_03001800.unk61[i] = gUnk_03001800.unk60 + 1;
            gUnk_03001800.unk60++;
        }
        if (sub_08032FFC())
            gUnk_03001800.unk5E = select_battle_pending_action() + 1;
        else
        {
            gUnk_03001800.unk60 = sub_08032FC4(gUnk_03001800.unk5C);
            for (i = 0; i <= 2; i++)
            {
                if (gUnk_03000590[gUnk_03001800.unk60].unk40
                 && sub_08032FD0(gUnk_03001800.unk60, gUnk_03000590[gUnk_03001800.unk5C].medal.unk6))
                    gUnk_03001800.unk61[i] = gUnk_03001800.unk60 + 1;
                gUnk_03001800.unk60++;
            }
            if (sub_08032FFC())
                gUnk_03001800.unk5E = select_battle_pending_action() + 1;
            else
            {
                gUnk_03001800.unk60 = sub_08032FC4(gUnk_03001800.unk5C);
                gUnk_03001800.unk5E = select_random_battle_target(gUnk_03001800.unk60) + 1;
            }
        }
    }
    sub_08033154(gUnk_03001800.unk5C, gUnk_03001800.unk5D);
}

void ai_pick_ally_with_broken_part(void)
{
    u32 i;
    u32 part;

    gUnk_03001800.unk60 = sub_08032FC4(gUnk_03001800.unk5C);
    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03000590[gUnk_03001800.unk60].unk40
         && find_random_broken_part(gUnk_03001800.unk60)
         && sub_08032FD0(gUnk_03001800.unk60, gUnk_03000590[gUnk_03001800.unk5C].medal.unk6))
            gUnk_03001800.unk61[i] = gUnk_03001800.unk60 + 1;
        gUnk_03001800.unk60++;
    }
    if (sub_08032FFC())
        gUnk_03001800.unk5E = select_battle_pending_action() + 1;
    else
    {
        gUnk_03001800.unk60 = sub_08032FC4(gUnk_03001800.unk5C);
        for (i = 0; i <= 2; i++)
        {
            if (gUnk_03000590[gUnk_03001800.unk60].unk40
             && find_random_broken_part(gUnk_03001800.unk60))
                gUnk_03001800.unk61[i] = gUnk_03001800.unk60 + 1;
            gUnk_03001800.unk60++;
        }
        if (sub_08032FFC())
            gUnk_03001800.unk5E = select_battle_pending_action() + 1;
        else
        {
            gUnk_03001800.unk60 = sub_08032FC4(gUnk_03001800.unk5C);
            for (i = 0; i <= 2; i++)
            {
                if (gUnk_03000590[gUnk_03001800.unk60].unk40
                 && sub_08032FD0(gUnk_03001800.unk60, gUnk_03000590[gUnk_03001800.unk5C].medal.unk6))
                    gUnk_03001800.unk61[i] = gUnk_03001800.unk60 + 1;
                gUnk_03001800.unk60++;
            }
            if (sub_08032FFC())
                gUnk_03001800.unk5E = select_battle_pending_action() + 1;
            else
            {
                gUnk_03001800.unk60 = sub_08032FC4(gUnk_03001800.unk5C);
                gUnk_03001800.unk5E = select_random_battle_target(gUnk_03001800.unk60) + 1;
            }
        }
    }
    part = find_random_broken_part(gUnk_03001800.unk5E - 1);
    if (part)
        gUnk_03001800.unk5F = part;
    else
        gUnk_03001800.unk5F = sub_080330E8(gUnk_03001800.unk5E - 1) + 1;
    sub_08033154(gUnk_03001800.unk5C, gUnk_03001800.unk5D);
}

void select_enemy_battle_target(void)
{
    u32 i;

    gUnk_03001800.unk60 = sub_08032FC4(gUnk_03001800.unk5C);
    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03000590[gUnk_03001800.unk60].unkBA == 2
         && sub_08032FD0(gUnk_03001800.unk60, gUnk_03000590[gUnk_03001800.unk5C].medal.unk6))
            gUnk_03001800.unk61[i] = gUnk_03001800.unk60 + 1;
        gUnk_03001800.unk60++;
    }
    if (sub_08032FFC())
        gUnk_03001800.unk5E = select_battle_pending_action() + 1;
    else
    {
        gUnk_03001800.unk60 = sub_08032FC4(gUnk_03001800.unk5C);
        for (i = 0; i <= 2; i++)
        {
            if (gUnk_03000590[gUnk_03001800.unk60].unkBA == 2)
                gUnk_03001800.unk61[i] = gUnk_03001800.unk60 + 1;
            gUnk_03001800.unk60++;
        }
        if (sub_08032FFC())
            gUnk_03001800.unk5E = select_battle_pending_action() + 1;
        else
        {
            gUnk_03001800.unk60 = sub_08032FC4(gUnk_03001800.unk5C);
            for (i = 0; i <= 2; i++)
            {
                if (sub_08032FD0(gUnk_03001800.unk60, gUnk_03000590[gUnk_03001800.unk5C].medal.unk6))
                    gUnk_03001800.unk61[i] = gUnk_03001800.unk60 + 1;
                gUnk_03001800.unk60++;
            }
            if (sub_08032FFC())
                gUnk_03001800.unk5E = select_battle_pending_action() + 1;
            else
            {
                gUnk_03001800.unk60 = sub_08032FC4(gUnk_03001800.unk5C);
                gUnk_03001800.unk5E = select_random_battle_target(gUnk_03001800.unk60) + 1;
            }
        }
    }
    sub_08033154(gUnk_03001800.unk5C, gUnk_03001800.unk5D);
}

void select_battle_target_for_bot(void)
{
    u32 i;

    gUnk_03001800.unk60 = sub_08032FC4(gUnk_03001800.unk5C);
    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03000590[gUnk_03001800.unk60].unk40
         && gUnk_03001800.unk60 != gUnk_03001800.unk5C
         && sub_08032FD0(gUnk_03001800.unk60, gUnk_03000590[gUnk_03001800.unk5C].medal.unk6))
            gUnk_03001800.unk61[i] = gUnk_03001800.unk60 + 1;
        gUnk_03001800.unk60++;
    }
    if (sub_08032FFC())
        gUnk_03001800.unk5E = select_battle_pending_action() + 1;
    else
    {
        gUnk_03001800.unk60 = sub_08032FC4(gUnk_03001800.unk5C);
        for (i = 0; i <= 2; i++)
        {
            if (gUnk_03000590[gUnk_03001800.unk60].unk40
             && gUnk_03001800.unk60 != gUnk_03001800.unk5C)
                gUnk_03001800.unk61[i] = gUnk_03001800.unk60 + 1;
            gUnk_03001800.unk60++;
        }
        if (sub_08032FFC())
            gUnk_03001800.unk5E = select_battle_pending_action() + 1;
        else
        {
            gUnk_03001800.unk60 = sub_08032FC4(gUnk_03001800.unk5C);
            gUnk_03001800.unk5E = select_random_battle_target(gUnk_03001800.unk60) + 1;
        }
    }
    sub_08033154(gUnk_03001800.unk5C, gUnk_03001800.unk5D);
}

void battle_ai_select_target_ability22_ally(void)
{
    u32 i;

    gUnk_03001800.unk60 = sub_08032FB8(gUnk_03001800.unk5C);
    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03000590[gUnk_03001800.unk60].unk40
         && sub_080331F8(gUnk_03001800.unk60)
         && sub_08033240(gUnk_03001800.unk60)
         && sub_08032FD0(gUnk_03001800.unk60, gUnk_03000590[gUnk_03001800.unk5C].medal.unk6))
            gUnk_03001800.unk61[i] = gUnk_03001800.unk60 + 1;
        gUnk_03001800.unk60++;
    }
    if (sub_08032FFC())
        gUnk_03001800.unk5E = select_battle_pending_action() + 1;
    else
    {
        gUnk_03001800.unk60 = sub_08032FB8(gUnk_03001800.unk5C);
        for (i = 0; i <= 2; i++)
        {
            if (gUnk_03000590[gUnk_03001800.unk60].unk40
             && sub_080331F8(gUnk_03001800.unk60)
             && sub_08033240(gUnk_03001800.unk60))
                gUnk_03001800.unk61[i] = gUnk_03001800.unk60 + 1;
            gUnk_03001800.unk60++;
        }
        if (sub_08032FFC())
            gUnk_03001800.unk5E = select_battle_pending_action() + 1;
        else
        {
            gUnk_03001800.unk60 = sub_08032FB8(gUnk_03001800.unk5C);
            for (i = 0; i <= 2; i++)
            {
                if (gUnk_03000590[gUnk_03001800.unk60].unk40
                 && sub_08032FD0(gUnk_03001800.unk60, gUnk_03000590[gUnk_03001800.unk5C].medal.unk6))
                    gUnk_03001800.unk61[i] = gUnk_03001800.unk60 + 1;
                gUnk_03001800.unk60++;
            }
            if (sub_08032FFC())
                gUnk_03001800.unk5E = select_battle_pending_action() + 1;
            else
            {
                gUnk_03001800.unk60 = sub_08032FB8(gUnk_03001800.unk5C);
                gUnk_03001800.unk5E = select_random_battle_target(gUnk_03001800.unk60) + 1;
            }
        }
    }
    sub_08033154(gUnk_03001800.unk5C, gUnk_03001800.unk5D);
}

void battle_ai_select_target_status58(void)
{
    u32 i;

    gUnk_03001800.unk60 = sub_08032FB8(gUnk_03001800.unk5C);
    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03000590[gUnk_03001800.unk60].unk40
         && sub_080332B4(gUnk_03001800.unk60)
         && sub_08032FD0(gUnk_03001800.unk60, gUnk_03000590[gUnk_03001800.unk5C].medal.unk6))
            gUnk_03001800.unk61[i] = gUnk_03001800.unk60 + 1;
        gUnk_03001800.unk60++;
    }
    if (sub_08032FFC())
        gUnk_03001800.unk5E = select_battle_pending_action() + 1;
    else
    {
        gUnk_03001800.unk60 = sub_08032FB8(gUnk_03001800.unk5C);
        for (i = 0; i <= 2; i++)
        {
            if (gUnk_03000590[gUnk_03001800.unk60].unk40
             && sub_080332B4(gUnk_03001800.unk60))
                gUnk_03001800.unk61[i] = gUnk_03001800.unk60 + 1;
            gUnk_03001800.unk60++;
        }
        if (sub_08032FFC())
            gUnk_03001800.unk5E = select_battle_pending_action() + 1;
        else
        {
            gUnk_03001800.unk60 = sub_08032FB8(gUnk_03001800.unk5C);
            for (i = 0; i <= 2; i++)
            {
                if (gUnk_03000590[gUnk_03001800.unk60].unk40
                 && sub_08032FD0(gUnk_03001800.unk60, gUnk_03000590[gUnk_03001800.unk5C].medal.unk6))
                    gUnk_03001800.unk61[i] = gUnk_03001800.unk60 + 1;
                gUnk_03001800.unk60++;
            }
            if (sub_08032FFC())
                gUnk_03001800.unk5E = select_battle_pending_action() + 1;
            else
            {
                gUnk_03001800.unk60 = sub_08032FB8(gUnk_03001800.unk5C);
                gUnk_03001800.unk5E = select_random_battle_target(gUnk_03001800.unk60) + 1;
            }
        }
    }
    gUnk_03001800.unk5F = 1;
    sub_08033154(gUnk_03001800.unk5C, gUnk_03001800.unk5D);
}

void select_player_battle_target(void)
{
    u32 i;

    gUnk_03001800.unk60 = sub_08032FB8(gUnk_03001800.unk5C);
    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03000590[gUnk_03001800.unk60].unk40
         && sub_080332D0(gUnk_03001800.unk60)
         && sub_08032FD0(gUnk_03001800.unk60, gUnk_03000590[gUnk_03001800.unk5C].medal.unk6))
            gUnk_03001800.unk61[i] = gUnk_03001800.unk60 + 1;
        gUnk_03001800.unk60++;
    }
    if (sub_08032FFC())
        gUnk_03001800.unk5E = select_battle_pending_action() + 1;
    else
    {
        gUnk_03001800.unk60 = sub_08032FB8(gUnk_03001800.unk5C);
        for (i = 0; i <= 2; i++)
        {
            if (gUnk_03000590[gUnk_03001800.unk60].unk40
             && sub_080332D0(gUnk_03001800.unk60))
                gUnk_03001800.unk61[i] = gUnk_03001800.unk60 + 1;
            gUnk_03001800.unk60++;
        }
        if (sub_08032FFC())
            gUnk_03001800.unk5E = select_battle_pending_action() + 1;
        else
        {
            gUnk_03001800.unk60 = sub_08032FB8(gUnk_03001800.unk5C);
            for (i = 0; i <= 2; i++)
            {
                if (gUnk_03000590[gUnk_03001800.unk60].unk40
                 && sub_08032FD0(gUnk_03001800.unk60, gUnk_03000590[gUnk_03001800.unk5C].medal.unk6))
                    gUnk_03001800.unk61[i] = gUnk_03001800.unk60 + 1;
                gUnk_03001800.unk60++;
            }
            if (sub_08032FFC())
                gUnk_03001800.unk5E = select_battle_pending_action() + 1;
            else
            {
                gUnk_03001800.unk60 = sub_08032FB8(gUnk_03001800.unk5C);
                gUnk_03001800.unk5E = select_random_battle_target(gUnk_03001800.unk60) + 1;
            }
        }
    }
    sub_08033154(gUnk_03001800.unk5C, gUnk_03001800.unk5D);
}

void ai_select_target_player_side_ability22(void)
{
    u32 i;

    gUnk_03001800.unk60 = sub_08032FB8(gUnk_03001800.unk5C);
    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03000590[gUnk_03001800.unk60].unk40
         && sub_080331F8(gUnk_03001800.unk60)
         && sub_08033240(gUnk_03001800.unk60)
         && sub_08032FD0(gUnk_03001800.unk60, gUnk_03000590[gUnk_03001800.unk5C].medal.unk6))
            gUnk_03001800.unk61[i] = gUnk_03001800.unk60 + 1;
        gUnk_03001800.unk60++;
    }
    if (sub_08032FFC())
        gUnk_03001800.unk5E = select_battle_pending_action() + 1;
    else
    {
        gUnk_03001800.unk60 = sub_08032FB8(gUnk_03001800.unk5C);
        for (i = 0; i <= 2; i++)
        {
            if (gUnk_03000590[gUnk_03001800.unk60].unk40
             && sub_080331F8(gUnk_03001800.unk60)
             && sub_08033240(gUnk_03001800.unk60))
                gUnk_03001800.unk61[i] = gUnk_03001800.unk60 + 1;
            gUnk_03001800.unk60++;
        }
        if (sub_08032FFC())
            gUnk_03001800.unk5E = select_battle_pending_action() + 1;
        else
        {
            gUnk_03001800.unk60 = sub_08032FB8(gUnk_03001800.unk5C);
            for (i = 0; i <= 2; i++)
            {
                if (gUnk_03000590[gUnk_03001800.unk60].unk40
                 && sub_08032FD0(gUnk_03001800.unk60, gUnk_03000590[gUnk_03001800.unk5C].medal.unk6))
                    gUnk_03001800.unk61[i] = gUnk_03001800.unk60 + 1;
                gUnk_03001800.unk60++;
            }
            if (sub_08032FFC())
                gUnk_03001800.unk5E = select_battle_pending_action() + 1;
            else
            {
                gUnk_03001800.unk60 = sub_08032FB8(gUnk_03001800.unk5C);
                gUnk_03001800.unk5E = select_random_battle_target(gUnk_03001800.unk60) + 1;
            }
        }
    }
    gUnk_03001800.unk5F = battle_find_next_active_bot(gUnk_03001800.unk5E - 1) + 1;
    sub_08033154(gUnk_03001800.unk5C, gUnk_03001800.unk5D);
}

void clear_battle_action_selection(void)
{
    gUnk_03001800.unk5E = 0;
    gUnk_03001800.unk5F = 0;
    gUnk_03000590[gUnk_03001800.unk5C].parts[gUnk_03001800.unk5D].unkE = 0;
    gUnk_03000590[gUnk_03001800.unk5C].parts[gUnk_03001800.unk5D].unkF = 0;
}

u32 sub_08032FB8(u32 a)
{
    switch (a)
    {
    case 0:
    case 1:
    case 2:
        return 3;
    default:
        return 0;
    }
}

u32 sub_08032FC4(u32 a)
{
    switch (a)
    {
    case 0:
    case 1:
    case 2:
        return 0;
    default:
        return 3;
    }
}

u32 sub_08032FD0(u32 rec, u32 val)
{
    u32 i;

    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03000590[rec].parts[i].unk11 && gUnk_03000590[rec].parts[i].data[2] == val)
            return 1;
    }
    return 0;
}

u32 sub_08032FFC(void)
{
    u32 i;

    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03001800.unk61[i])
            return 1;
    }
    return 0;
}

u32 select_battle_pending_action(void)
{
    u32 i, j, dir;

    i = rng_lookup_table_value();
    dir = rng_next_080424B8() & 1;
    for (j = 0; j <= 2; j++)
    {
        if (gUnk_03001800.unk61[i])
            return gUnk_03001800.unk61[i] - 1;
        if (dir)
        {
            if (++i > 2)
                i = 0;
        }
        else if (i == 0)
            i = 2;
        else
            i--;
    }
    return gUnk_03001800.unk61[i];
}

u32 rng_lookup_table_value(void)
{
    return gUnk_083AEF00[rng_next_080424B8() & 0xF];
}

u32 select_random_battle_target(u32 base)
{
    u32 i, j, dir;

    i = rng_lookup_table_value();
    dir = rng_next_080424B8() & 1;
    for (j = 0; j <= 2; j++)
    {
        if (gUnk_03000590[base + i].unk40)
            return base + i;
        if (dir)
        {
            if (++i > 2)
                i = 0;
        }
        else if (i == 0)
            i = 2;
        else
            i--;
    }
    return base + i;
}

u32 sub_080330E8(u32 idx)
{
    return get_random_battle_weight_entry(idx);
}

u32 battle_find_next_active_bot(u32 rec)
{
    u32 i, j, dir;

    i = rng_lookup_table_value();
    dir = rng_next_080424B8() & 1;
    for (j = 0; j <= 2; j++)
    {
        if (gUnk_03000590[rec].parts[i].unk11)
            return i;
        if (dir)
        {
            if (++i > 2)
                i = 0;
        }
        else if (i == 0)
            i = 2;
        else
            i--;
    }
    return i;
}

void sub_08033154(u32 rec, u32 part)
{
    gUnk_03000590[rec].parts[part].unkE = gUnk_03001800.unk5E;
    gUnk_03000590[rec].parts[part].unkF = gUnk_03001800.unk5F;
}

u32 find_most_damaged_part(u32 rec)
{
    u32 zero = 0;
    u32 i;

    CpuFastSet(&zero, (void *)0x02023000, 0x01000080);
    for (i = 0; i <= 3; i++)
    {
        SORT_BUFFER[i].value = i;
        if (gUnk_03000590[rec].parts[i].unk11 != 0 && gUnk_03000590[rec].parts[i].unk11 != gUnk_03000590[rec].parts[i].data[4])
            SORT_BUFFER[i].key = gUnk_03000590[rec].parts[i].data[4] - gUnk_03000590[rec].parts[i].unk11;
    }
    sub_0804242C(4);
    if (SORT_BUFFER[0].key != 0)
        return SORT_BUFFER[0].value + 1;
    else
        return 0;
}

u32 sub_080331F8(u32 rec)
{
    u32 i;

    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03000590[rec].parts[i].unk11 && gUnk_03000590[rec].parts[i].data[1] == 0x16)
            return 0;
    }
    return 1;
}

u32 sub_08033224(u32 rec)
{
    if (gUnk_03000590[rec].unkC4 != 0)
        return 0;
    else
        return 1;
}

u32 sub_08033240(u32 rec)
{
    if (gUnk_03000590[rec].unkC9 != 0)
        return 0;
    else
        return 1;
}

u32 find_random_broken_part(u32 rec)
{
    u32 i, slot, dir;

    slot = rng_next_080424B8() & 3;
    dir = rng_next_080424B8() & 1;
    for (i = 0; i <= 3; i++)
    {
        if (gUnk_03000590[rec].parts[slot].unk11 == 0)
            return slot + 1;
        if (dir)
            slot = (slot + 1) & 3;
        else
            slot = (slot - 1) & 3;
    }
    return 0;
}

u32 sub_080332B4(u32 rec)
{
    if (gUnk_03000590[rec].parts[0].unk10 != 0)
        return 1;
    else
        return 0;
}

u32 sub_080332D0(u32 rec)
{
    if (gUnk_03000590[rec].unkC1 != 0)
        return 1;
    else
        return 0;
}

void sub_080332EC(void)
{
    gUnk_03000590[gUnk_03001800.unk5C].parts[gUnk_03001800.unk5D].unkF = 0;
}

u32 begin_battle_action_lookup(u32 rec, u32 part)
{
    gUnk_03001800.unk51 = 0;
    gUnk_03001800.unk5C = rec;
    gUnk_03001800.unk5D = --part;
    gUnk_083AEF10[gUnk_03000590[rec].parts[part].data[1]]();
    return gUnk_03001800.unk51;
}

void check_battle_bot_defeated_set_flag(void)
{
    if (gUnk_03001800.unk28[sub_0801554C(gUnk_03001800.unk5C, 0)].unk2 == 0)
        gUnk_03001800.unk51 = 1;
}

void sub_08033394(void)
{
    if (gUnk_03000590[gUnk_03000590[gUnk_03001800.unk5C].parts[gUnk_03001800.unk5D].unkE - 1].unkC9 == 0)
        gUnk_03001800.unk51 = 1;
}

void sub_080333D4(void)
{
    gUnk_03001800.unk51 = 1;
}

void sub_080333E4(void)
{
    u32 i, n;

    gUnk_03001800.unk60 = sub_08032FC4(gUnk_03001800.unk5C);
    for (i = 0, n = 0; i <= 2; i++)
    {
        if (gUnk_03000590[gUnk_03001800.unk60 + i].unk40)
            n++;
    }
    if (n <= 1)
        gUnk_03001800.unk51 = 1;
}

void sub_08033434(void)
{
    if (gUnk_03000590[gUnk_03000590[gUnk_03001800.unk5C].parts[gUnk_03001800.unk5D].unkE - 1].parts[gUnk_03000590[gUnk_03001800.unk5C].parts[gUnk_03001800.unk5D].unkF - 1].unk11 == 0
     || gUnk_03000590[gUnk_03000590[gUnk_03001800.unk5C].parts[gUnk_03001800.unk5D].unkE - 1].parts[gUnk_03000590[gUnk_03001800.unk5C].parts[gUnk_03001800.unk5D].unkF - 1].unk11 == gUnk_03000590[gUnk_03000590[gUnk_03001800.unk5C].parts[gUnk_03001800.unk5D].unkE - 1].parts[gUnk_03000590[gUnk_03001800.unk5C].parts[gUnk_03001800.unk5D].unkF - 1].data[4])
        gUnk_03001800.unk51 = 1;
}

void sub_08033490(void)
{
    u32 rec = gUnk_03000590[gUnk_03001800.unk5C].parts[gUnk_03001800.unk5D].unkE - 1;

    if (gUnk_03000590[rec].unkC4 != 0 || sub_080331F8(rec) == 0)
        gUnk_03001800.unk51 = 1;
}

void sub_080334E0(void)
{
    if (gUnk_03000590[gUnk_03000590[gUnk_03001800.unk5C].parts[gUnk_03001800.unk5D].unkE - 1].unkC9 != 0)
        gUnk_03001800.unk51 = 1;
    if (sub_080331F8(gUnk_03000590[gUnk_03001800.unk5C].parts[gUnk_03001800.unk5D].unkE - 1) == 0)
        gUnk_03001800.unk51 = 1;
}

void sub_08033550(void)
{
    if (gUnk_03000590[gUnk_03000590[gUnk_03001800.unk5C].parts[gUnk_03001800.unk5D].unkE - 1]
            .parts[gUnk_03000590[gUnk_03001800.unk5C].parts[gUnk_03001800.unk5D].unkF - 1].unk11 != 0)
        gUnk_03001800.unk51 = 1;
}

void sub_080335A0(void)
{
    if (gUnk_03000590[gUnk_03000590[gUnk_03001800.unk5C].parts[gUnk_03001800.unk5D].unkE - 1].unkBA != 2)
        gUnk_03001800.unk51 = 1;
}

void sub_080335E0(void)
{
    if (gUnk_03000590[gUnk_03001800.unk5C].parts[gUnk_03001800.unk5D].unkE - 1 == gUnk_03001800.unk5C)
        gUnk_03001800.unk51 = 1;
}

void sub_08033618(void)
{
    if (gUnk_03000590[gUnk_03000590[gUnk_03001800.unk5C].parts[gUnk_03001800.unk5D].unkE - 1].parts[0].unk10 == 0)
        gUnk_03001800.unk51 = 1;
}

void sub_08033658(void)
{
    if (gUnk_03000590[gUnk_03000590[gUnk_03001800.unk5C].parts[gUnk_03001800.unk5D].unkE - 1].unkC1 == 0)
        gUnk_03001800.unk51 = 1;
}

void sub_08033698(void)
{
    if (gUnk_03001800.unk28[sub_0801554C(gUnk_03001800.unk5C, 1)].unk2 == 0
     || gUnk_03001800.unk28[sub_0801554C(gUnk_03001800.unk5C, 1)].unk3 != 0x33)
        gUnk_03001800.unk51 = 1;
}

void sub_080336DC(void)
{
    u32 i, j;

    gUnk_03001800.unk60 = sub_08032FB8(gUnk_03001800.unk5C);
    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03000590[gUnk_03001800.unk60 + i].unk40)
        {
            for (j = 0; j <= 2; j++)
            {
                if (gUnk_03000590[gUnk_03001800.unk60 + i].parts[j].unk11)
                {
                    if (gUnk_03000590[gUnk_03001800.unk60 + i].parts[j].data[2] == 0)
                        return;
                    if (gUnk_03000590[gUnk_03001800.unk60 + i].parts[j].data[2] == 1)
                        return;
                }
            }
        }
    }
    gUnk_03001800.unk51 = 1;
}

void sub_08033754(void)
{
    u32 i, j;

    gUnk_03001800.unk60 = sub_08032FB8(gUnk_03001800.unk5C);
    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03000590[gUnk_03001800.unk60 + i].unk40)
        {
            for (j = 0; j <= 2; j++)
            {
                if (gUnk_03000590[gUnk_03001800.unk60 + i].parts[j].unk11)
                {
                    if (gUnk_03000590[gUnk_03001800.unk60 + i].parts[j].data[2] == 2)
                        return;
                    if (gUnk_03000590[gUnk_03001800.unk60 + i].parts[j].data[2] == 3)
                        return;
                }
            }
        }
    }
    gUnk_03001800.unk51 = 1;
}

void sub_080337CC(void)
{
    u32 i, j;

    gUnk_03001800.unk60 = sub_08032FC4(gUnk_03001800.unk5C);
    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03000590[gUnk_03001800.unk60 + i].unk40)
        {
            for (j = 0; j <= 2; j++)
            {
                if (gUnk_03000590[gUnk_03001800.unk60 + i].parts[j].unk11
                 && gUnk_03000590[gUnk_03001800.unk60 + i].parts[j].data[1] == 0x34)
                    return;
            }
        }
    }
    gUnk_03001800.unk51 = 1;
}

void sub_08033840(void)
{
    if (sub_0803EED8() == 0)
    {
        if (gUnk_03000430 == 2)
        {
            u32 fill = 0x200;

            CpuFastSet(&fill, gUnk_03002414->unkB84, 0x01000100);
        }
        if (gUnk_03001800.unk1AE == 0)
            update_all_battle_status_sprites();
        do
        {
            gUnk_03001800.unk163 = 0;
            gGameSubState = sub_08034E94();
            while ((s32)gGameSubState > 0x7F)
            {
                sub_08034F08();
                gGameSubState = sub_08034E94();
            }
            gUnk_083AF000[gGameSubState]();
        } while (gUnk_03001800.unk163);
    }
}

void sub_080338DC(void)
{
    gGameState = 8;
    gGameSubState = 0x40;
}

INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_080338F4);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08033974);

void sub_080339F4(void)
{
    sub_0801C4FC();
    if (gUnk_03001800.unkB5)
        sub_08034F08();
}

void sub_08033A10(void)
{
    battle_dispatch_phase_handler_0801D2F0();
    if (gUnk_03001800.unkB5)
        sub_08034F08();
}

void sub_08033A2C(void)
{
    if (gUnk_03000590[gUnk_03001800.unk87].unkE0 == 0)
        sub_08035478(gUnk_03001800.unk87);
    if (gUnk_03000590[gUnk_03001800.unk87].unkE1 == 0)
        calc_bot_evasion_modifier(gUnk_03001800.unk87);
    sub_080355C4(gUnk_03001800.unk87);
    sub_08034F08();
}

void sub_08033A78(void)
{
    sub_0801D380();
    if (gUnk_03001800.unkB5)
        sub_08034F08();
}

void sub_08033A94(void)
{
    sub_0801D40C();
    if (gUnk_03001800.unkB5)
        sub_08034F08();
}

void sub_08033AB0(void)
{
    sub_0801D580();
    if (gUnk_03001800.unkB5)
        sub_08034F08();
}

void sub_08033ACC(void)
{
    if (gUnk_03001800.unkDE)
    {
        memcpy_bytes_0803F63C(gUnk_03003470, gUnk_03003470 + 0xE40 + ((gUnk_03001800.unkDE - 1) << 8), 0x40);
        memcpy_bytes_0803F63C(gUnk_03003470 + 0x40, gUnk_03003470 + 0xE80 + ((gUnk_03001800.unkDE - 1) << 8), 0x40);
        memcpy_bytes_0803F63C(gUnk_03003470 + 0x80, gUnk_03003470 + 0xEC0 + ((gUnk_03001800.unkDE - 1) << 8), 0x40);
        memcpy_bytes_0803F63C(gUnk_03003470 + 0xC0, gUnk_03003470 + 0xF00 + ((gUnk_03001800.unkDE - 1) << 8), 0x40);
        clear_battle_sprite_slot(0x21, 4);
        set_sprite_hidden_flags(gUnk_03001800.unkDE * 4 + 0x56, 4);
        init_battle_sprite_entry_0801BC04(gUnk_03001800.unkDE - 1);
        gUnk_03001800.unkDE = 0;
        load_all_bot_part_sprites();
        iterate_bots_setup_battle_sprites();
    }
    sub_08034F08();
}

void sub_08033B7C(void)
{
    u32 type = gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03001800.unkA7].data[2];

    if (type == 0)
        goto both;
    if (type == 1)
    {
    both:
        gUnk_03000590[gUnk_03001800.unk87].unkBC |= 2;
        if (gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03001800.unkA7].data[2] == 1)
            gUnk_03000590[gUnk_03001800.unk87].unkBC |= 1;
    }
    else if (type == 3)
        gUnk_03000590[gUnk_03001800.unk87].unkBC |= 1;
    sub_08034F08();
}

void sub_08033C00(void)
{
    sub_08038BC0();
    sub_08034F08();
}

void sub_08033C10(void)
{
    sub_08038D30();
    sub_08034F08();
}

INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08033C20);

void sub_08033CD0(void)
{
    battle_begin_action_phase();
    sub_08034F08();
}

void sub_08033CE0(void)
{
    sub_08039188();
    sub_08034F08();
}

void sub_08033CF0(void)
{
    sub_080391C4();
    sub_08034F08();
}

void sub_08033D00(void)
{
    sub_080392D8();
    sub_08034F08();
}

INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08033D10);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08033D30);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08033F04);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08033F64);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08033F9C);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08034008);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_0803402C);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08034048);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08034074);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08034120);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08034170);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_080341C0);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08034200);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08034240);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_0803426C);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08034288);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_080342C8);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_080342E4);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08034300);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_0803431C);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_0803435C);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08034378);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_080343B8);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_080343D4);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_080343F0);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_0803440C);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08034428);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08034444);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08034460);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_0803447C);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08034498);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_080344B4);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_080344D0);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_080344EC);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08034508);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08034524);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08034540);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_0803455C);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08034578);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08034594);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_080345B0);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_080345CC);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_080345E8);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08034628);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08034644);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08034684);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_080346C4);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08034708);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08034728);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_0803476C);

void sub_080347AC(void)
{
    sub_08036270();
    sub_08034F08();
}

INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_080347BC);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_080347F8);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_080348D0);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08034910);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_0803496C);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_080349D8);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08034A68);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08034AA0);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08034AF4);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08034B68);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08034BA0);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08034BBC);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08034BD8);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08034BF4);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08034C10);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08034C2C);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08034C48);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08034C64);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08034C80);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08034C9C);
