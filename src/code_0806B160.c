#include "global.h"

INCLUDE_ASM("asm/nonmatching/code_0806B160", update_sprite_position_sincos);
INCLUDE_ASM("asm/nonmatching/code_0806B160", sub_0806B244);
INCLUDE_ASM("asm/nonmatching/code_0806B160", sub_0806B310);
INCLUDE_ASM("asm/nonmatching/code_0806B160", update_sprite_animations_0806B334);
INCLUDE_ASM("asm/nonmatching/code_0806B160", sprite_animation_dispatch);
INCLUDE_ASM("asm/nonmatching/code_0806B160", sub_0806B420);
INCLUDE_ASM("asm/nonmatching/code_0806B160", sub_0806B584);
INCLUDE_ASM("asm/nonmatching/code_0806B160", battle_screen_dispatch);
INCLUDE_ASM("asm/nonmatching/code_0806B160", init_battle_screen);
INCLUDE_ASM("asm/nonmatching/code_0806B160", load_battle_screen_graphics);
INCLUDE_ASM("asm/nonmatching/code_0806B160", sub_0806B990);
INCLUDE_ASM("asm/nonmatching/code_0806B160", sub_0806B9B0);
INCLUDE_ASM("asm/nonmatching/code_0806B160", sub_0806B9D0);
INCLUDE_ASM("asm/nonmatching/code_0806B160", sub_0806BAB4);
INCLUDE_ASM("asm/nonmatching/code_0806B160", sub_0806BB00);
INCLUDE_ASM("asm/nonmatching/code_0806B160", sub_0806BB30);
INCLUDE_ASM("asm/nonmatching/code_0806B160", sub_0806BB68);
INCLUDE_ASM("asm/nonmatching/code_0806B160", sub_0806BBA8);
INCLUDE_ASM("asm/nonmatching/code_0806B160", sub_0806BBDC);
INCLUDE_ASM("asm/nonmatching/code_0806B160", sub_0806BD84);
INCLUDE_ASM("asm/nonmatching/code_0806B160", sub_0806BE58);
INCLUDE_ASM("asm/nonmatching/code_0806B160", sub_0806BEF0);
INCLUDE_ASM("asm/nonmatching/code_0806B160", sub_0806C084);
INCLUDE_ASM("asm/nonmatching/code_0806B160", sub_0806C20C);
INCLUDE_ASM("asm/nonmatching/code_0806B160", sub_0806C4CC);
INCLUDE_ASM("asm/nonmatching/code_0806B160", sub_0806C500);
INCLUDE_ASM("asm/nonmatching/code_0806B160", sub_0806C6F8);
INCLUDE_ASM("asm/nonmatching/code_0806B160", sub_0806C7C4);
INCLUDE_ASM("asm/nonmatching/code_0806B160", sub_0806C994);
INCLUDE_ASM("asm/nonmatching/code_0806B160", sub_0806CAEC);
INCLUDE_ASM("asm/nonmatching/code_0806B160", update_battle_sprite_direction);
INCLUDE_ASM("asm/nonmatching/code_0806B160", sub_0806CD48);
INCLUDE_ASM("asm/nonmatching/code_0806B160", sub_0806CDE8);
INCLUDE_ASM("asm/nonmatching/code_0806B160", sub_0806CE58);
INCLUDE_ASM("asm/nonmatching/code_0806B160", sub_0806CFA4);
INCLUDE_ASM("asm/nonmatching/code_0806B160", get_battle_state_value_div10);
INCLUDE_ASM("asm/nonmatching/code_0806B160", set_bot_y_positions_by_count);
INCLUDE_ASM("asm/nonmatching/code_0806B160", sub_0806D288);
INCLUDE_ASM("asm/nonmatching/code_0806B160", update_bg2_affine_scanline_params);
INCLUDE_ASM("asm/nonmatching/code_0806B160", sub_0806D3F4);
INCLUDE_ASM("asm/nonmatching/code_0806B160", teardown_scene_and_restore_state);
INCLUDE_ASM("asm/nonmatching/code_0806B160", load_scene_graphics);
INCLUDE_ASM("asm/nonmatching/code_0806B160", battle_transition_animate_step);
INCLUDE_ASM("asm/nonmatching/code_0806B160", battle_scene_intro_step);
INCLUDE_ASM("asm/nonmatching/code_0806B160", battle_transition_wipe_effect);
INCLUDE_ASM("asm/nonmatching/code_0806B160", battle_intro_countdown_tick);
INCLUDE_ASM("asm/nonmatching/code_0806B160", sub_0806DAEC);
INCLUDE_ASM("asm/nonmatching/code_0806B160", sub_0806DB30);
INCLUDE_ASM("asm/nonmatching/code_0806B160", update_sprite_special_effects);
INCLUDE_ASM("asm/nonmatching/code_0806B160", sub_0806DD10);
INCLUDE_ASM("asm/nonmatching/code_0806B160", sub_0806DEAC);
INCLUDE_ASM("asm/nonmatching/code_0806B160", sub_0806DEE8);
INCLUDE_ASM("asm/nonmatching/code_0806B160", sub_0806DF80);

void dispatch_game_substate_handler_0806DFA4(void)
{
    gUnk_08485F1C[gGameSubState]();
}

void sub_0806DFC4(void)
{
    if (scene_transition_step_080686F4()) {
        gGameMode = gUnk_03001800_s.nextMode;
        gGameState = gUnk_03001800_s.nextState;
        gGameSubState = gUnk_03001800_s.nextSubState;
    }
}

void scene_complete_dma_and_restore_state(void)
{
    if (execute_scene_step()) {
        u32 zero = 0;
        DmaSet(3, &zero, gUnk_03002C30, 0x85000800);
        REG_DISPCNT &= 0x80FF;
        gGameMode = gUnk_03001800_s.nextMode;
        gGameState = gUnk_03001800_s.nextState;
        gGameSubState = gUnk_03001800_s.nextSubState;
    }
}

void sub_0806E060(void)
{
    u32 zero = 0;
    DmaSet(3, &zero, VRAM, 0x85006000);
    zero = 0;
    DmaSet(3, &zero, PLTT, 0x85000100);
    zero = 0;
    DmaSet(3, &zero, gUnk_03002C30, 0x85000800);
    zero = 0;
    DmaSet(3, &zero, &gUnk_03001800_s, 0x85000004);
    REG_DISPCNT = 0x60;
    gUnk_03001800_s.nextMode = 3;
    gUnk_03001800_s.nextState = 3;
    gUnk_03001800_s.unkC.h = gUnk_03006D38.unk1;
    gBg0Scroll.x = 0;
    gBg0Scroll.y = 0;
    gBg1Scroll.x = 0;
    gBg1Scroll.y = 0;
    gBg2Scroll.x = 0;
    gBg2Scroll.y = 0;
    gBg3Scroll.x = 0;
    gBg3Scroll.y = 0;
    gGameSubState = 3;
}

void battle_init_tilemap_and_palette(void)
{
    u16 map[20][30];
    u16 out[20 * 32];
    s32 i, j;

    LZ77UnCompVram(gUnk_08487328[gUnk_03001800_s.unkC.h], (void *)(VRAM + 0x8000));
    LZ77UnCompVram(gUnk_08487358[gUnk_03001800_s.unkC.h], map);
    for (i = 0; i < 20; i++) {
        for (j = 0; j < 30; j++)
            out[i * 32 + j] = map[i][j];
        out[i * 32 + 30] = 0;
        out[i * 32 + 31] = 0;
    }
    DmaSet(3, out, VRAM + 0x7800, 0x84000140);
    DmaSet(3, gUnk_08487388[gUnk_03001800_s.unkC.h], PLTT, 0x800000E0);
    REG_BG1CNT = 0xF8B;
    setup_screen_transition_effect_080682CC(2, 1, 0);
    text_window_init(1, 2, 0);
    REG_DISPCNT |= 0x200;
    gUnk_03001800_s.nextSubState = 4;
    gGameSubState = 1;
}

void dispatch_battle_event_script(void)
{
    if (run_message(gUnk_08486EEC[gUnk_03001800_s.unkC.h])) {
        gUnk_03001800_s.nextSubState = 5;
        gGameSubState = 2;
    }
}

void sub_0806E26C(void)
{
    sub_08047850(2);
}

void boot_logos_check_skip(void)
{
    if (--gUnk_03001800_s.unk10 == 0)
        play_song(3);
    if (gUnk_03001800_s.unkC.b != 0 && (KEYS_LO(gNewKeys) & 8)) {
        gGameMode = 3;
        gGameState = 2;
        gGameSubState = 0;
        gUnk_03007008 = 1;
    }
}

void boot_logos_update(void)
{
    gBootLogosSubStates[gGameSubState]();
    boot_logos_check_skip();
}

bool32 blend_fade_step_0806E2F8(void)
{
    if ((gUnk_03001800_s.timer & 3) == 0) {
        u8 a = 16 - (gUnk_03001800_s.timer >> 2);
        u8 b = 16 - a;
        REG_BLDALPHA = (b << 8) | a;
        if (b == 16)
            return TRUE;
    }
    gUnk_03001800_s.timer++;
    return FALSE;
}

void sub_0806E340(void)
{
    if (blend_fade_step_0806E2F8()) {
        gUnk_03001800_s.timer = 0;
        gGameMode = gUnk_03001800_s.nextMode;
        gGameState = gUnk_03001800_s.nextState;
        gGameSubState = gUnk_03001800_s.nextSubState;
    }
}

void boot_logos_init(void)
{
    u32 zero = 0;
    DmaSet(3, &zero, VRAM, 0x85006000);
    zero = 0;
    DmaSet(3, &zero, PLTT, 0x85000100);
    zero = 0;
    DmaSet(3, &zero, OAM, 0x85000100);
    zero = 0;
    DmaSet(3, &zero, gUnk_03002C30, 0x85000800);
    zero = 0;
    DmaSet(3, &zero, &gUnk_03001800_s, 0x85000005);
    play_song(0);
    REG_DISPCNT = 0x60;
    gUnk_03001800_s.nextMode = 3;
    gUnk_03001800_s.nextState = 0;
    gUnk_03001800_s.timer = 0;
    gBg0Scroll.x = 0;
    gBg0Scroll.y = 0;
    gBg1Scroll.x = 0;
    gBg1Scroll.y = 0;
    gBg2Scroll.x = 0;
    gBg2Scroll.y = 0;
    gBg3Scroll.x = 0;
    gBg3Scroll.y = 0;
    gUnk_03007008 = 0;
    setup_screen_transition_effect_080682CC(2, 4, 0);
    gGameSubState = 4;
}

void boot_logos_load_licensed_by(void)
{
    u16 map[20][30];
    u16 out[20 * 32];
    s32 i, j;

    LZ77UnCompVram(gUnk_087F1B4C, (void *)VRAM);
    LZ77UnCompVram(gUnk_087F1E4C, map);
    for (i = 0; i < 20; i++) {
        for (j = 0; j < 30; j++)
            out[i * 32 + j] = *(map[i] + j);
        out[i * 32 + 30] = 0;
        out[i * 32 + 31] = 0;
    }
    DmaSet(3, out, VRAM + 0x7800, 0x84000140);
    DmaSet(3, gUnk_087F1F38, PLTT, 0x80000010);
    REG_BG0CNT = 0xF01;
    REG_DISPCNT |= 0x100;
    gUnk_03001800_s.nextSubState = 5;
    gGameSubState = 1;
}

void boot_logos_load_natsume(void)
{
    u16 map[20][30];
    u16 out[20 * 32];
    s32 i, j;

    LZ77UnCompVram(gUnk_087F1F58, (void *)VRAM);
    LZ77UnCompVram(gUnk_087F2658, map);
    for (i = 0; i < 20; i++) {
        for (j = 0; j < 30; j++)
            out[i * 32 + j] = *(map[i] + j);
        out[i * 32 + 30] = 0;
        out[i * 32 + 31] = 0;
    }
    DmaSet(3, out, VRAM + 0x7800, 0x84000140);
    DmaSet(3, gUnk_087F27D8, PLTT, 0x80000010);
    gUnk_03001800_s.unk10 = 0x34;
    REG_BG0CNT = 0xF02;
    REG_DISPCNT |= 0x100;
    gUnk_03001800_s.nextSubState = 7;
    gGameSubState = 1;
}

void boot_logos_load_overlay(void)
{
    u16 map[20][30];
    u16 out[20 * 32];
    s32 i, j;

    LZ77UnCompVram(gUnk_087F27F8, (void *)(VRAM + 0x8000));
    LZ77UnCompVram(gUnk_087F3070, map);
    for (i = 0; i < 20; i++) {
        for (j = 0; j < 30; j++)
            out[i * 32 + j] = *(map[i] + j) + 0x1000;
        out[i * 32 + 30] = 0;
        out[i * 32 + 31] = 0;
    }
    DmaSet(3, out, VRAM + 0xF800, 0x84000140);
    DmaSet(3, gUnk_087F3250, PLTT + 0x20, 0x80000010);
    REG_BG1CNT = 0x1F0B;
    REG_DISPCNT |= 0x200;
    REG_BLDCNT = 0x241;
    REG_BLDALPHA = 0x10;
    gUnk_03001800_s.nextSubState = 9;
    gGameSubState = 3;
}

void sub_0806E780(void)
{
    if (gUnk_03001800_s.timer == 0) {
    } else if (gUnk_03001800_s.timer > 60) {
        gUnk_03001800_s.timer = 0;
        gUnk_03001800_s.nextSubState = 6;
        gGameSubState = 2;
        return;
    }
    gUnk_03001800_s.timer++;
}

void sub_0806E7B0(void)
{
    if (gUnk_03001800_s.timer == 0) {
        gUnk_03001800_s.unkC.b = 1;
    } else if (gUnk_03001800_s.timer > 60) {
        gUnk_03001800_s.timer = 0;
        gGameSubState = 8;
        return;
    }
    gUnk_03001800_s.timer++;
}

void sub_0806E7E0(void)
{
    if (gUnk_03001800_s.timer == 0) {
        REG_DISPCNT &= 0xFEFF;
    } else if (gUnk_03001800_s.timer > 60) {
        gUnk_03001800_s.timer = 0;
        setup_screen_transition_effect_080684F0(2, 4, 0);
        gUnk_03001800_s.nextSubState = 10;
        gGameSubState = 2;
        return;
    }
    gUnk_03001800_s.timer++;
}

void boot_logos_end(void)
{
    gGameMode = 3;
    gGameState = 1;
    gGameSubState = 0;
}

void sub_0806E854(void)
{
    if (gUnk_03000430 == 2) {
        u32 v = 0x200;
        DmaSet(3, &v, gUnk_03002414->unkB84, 0x85000100);
        setup_scene_with_bg_and_sprites(0, 0x2A, 0x2A, 0x2A, 0x2A, 0x70, 0x50, gUnk_03000430, 0xC, 0, 1, 0);
        advance_text_display(0, 0x2D, 0x2A);
    }
}

void intro_check_skip(void)
{
    if (KEYS_LO(gHeldKeys) & 8) {
        gUnk_03007008 = 1;
        gUnk_03000430 = 0;
        gGameMode = 3;
        gGameState = 2;
        gGameSubState = 0;
    }
}

void intro_update(void)
{
    sub_0806E854();
    gIntroSubStates[gGameSubState]();
    intro_check_skip();
}

void sub_0806E934(void)
{
    if (sub_0806F850()) {
        gGameMode = gUnk_03001800_s.nextMode;
        gGameState = gUnk_03001800_s.nextState;
        gGameSubState = gUnk_03001800_s.nextSubState;
    }
}

void sub_0806E968(void)
{
    if (sub_0806F9D4()) {
        gGameMode = gUnk_03001800_s.nextMode;
        gGameState = gUnk_03001800_s.nextState;
        gGameSubState = gUnk_03001800_s.nextSubState;
    }
}

void scene_fade_out_and_restore_state(void)
{
    if (gUnk_03001800_s.timer > 0x4C && gUnk_03001800_s.unkEE >= 0) {
        u8 a = gUnk_03001800_s.unkEE;
        u8 b = 16 - gUnk_03001800_s.unkEE;
        REG_BLDALPHA = a | (b << 8);
        gUnk_03001800_s.unkEE--;
    }
    if (scene_transition_step_080686F4()) {
        REG_DISPCNT &= 0xFBFF;
        gGameMode = gUnk_03001800_s.nextMode;
        gGameState = gUnk_03001800_s.nextState;
        gGameSubState = gUnk_03001800_s.nextSubState;
    }
    gUnk_03001800_s.timer++;
}

void scene_animate_and_complete(void)
{
    gUnk_03001800_s.unkF0++;
    gUnk_03001800_s.unkF2 += 0x6F;
    battle_timer_digit_extract();
    update_sprite_animations_080703D8();
    if (execute_scene_step()) {
        u32 zero = 0;
        DmaSet(3, &zero, gUnk_03002C30, 0x85000800);
        gUnk_03000430 = 0;
        REG_DISPCNT &= 0x80FF;
        gGameMode = gUnk_03001800_s.nextMode;
        gGameState = gUnk_03001800_s.nextState;
        gGameSubState = gUnk_03001800_s.nextSubState;
    }
}

void battle_scene_init_clear(void)
{
    u32 zero = 0;
    DmaSet(3, &zero, VRAM, 0x85006000);
    zero = 0;
    DmaSet(3, &zero, PLTT, 0x85000100);
    zero = 0;
    DmaSet(3, &zero, gUnk_03002C30, 0x85000800);
    zero = 0;
    DmaSet(3, &zero, &gUnk_03001800_s, 0x8500003E);
    REG_DISPCNT = 0x60;
    gUnk_03001800_s.nextMode = 3;
    gUnk_03001800_s.nextState = 1;
    gUnk_03001800_s.timer = 0;
    gBg0Scroll.x = 0;
    gBg0Scroll.y = 0;
    gBg1Scroll.x = 0;
    gBg1Scroll.y = 0;
    gBg2Scroll.x = 0;
    gBg2Scroll.y = 0;
    gBg3Scroll.x = 0;
    gBg3Scroll.y = 0;
    gUnk_03001800_s.unkC.h = 11;
    gUnk_03001800_s.nextSubState = 11;
    gUnk_03001800_s.unk6 = 1;
    gUnk_03001800_s.unkF4 = 0x7C0;
    gUnk_03001800_s.unkF6 = 0x100;
    gUnk_03007008 = 0;
    gGameSubState = 8;
}

void load_battle_scene_graphics(void)
{
    u16 buf1[0x78];
    u16 buf2[0x190];

    LZ77UnCompVram(gUnk_087BA86C, (void *)VRAM);
    LZ77UnCompVram(gUnk_087C8368, (void *)(VRAM + 0x8020));
    LZ77UnCompVram(gUnk_08485FB8[1], (void *)(VRAM + 0x8C80));
    DmaSet(3, gUnk_087BDC10, PLTT, 0x84000080);
    DmaSet(3, gUnk_087C8818, PLTT, 0x84000008);
    DmaSet(3, gUnk_08485FC8[1], PLTT + 0x20, 0x84000008);
    LZ77UnCompVram(gUnk_087BDE10, (void *)(VRAM + 0x7000));
    LZ77UnCompVram(gUnk_087BE18C, (void *)(VRAM + 0x7800));
    LZ77UnCompVram(gUnk_087C8838, buf1);
    copy_tilemap_rect_to_vram(buf1, 0x1F, 0xA, 0xC, 0, 0, 1, 0);
    LZ77UnCompVram(gUnk_08485FC0[1], buf2);
    copy_tilemap_rect_to_vram(buf2, 0x1E, 0x14, 0x14, 0xA, 0, 0x64, 1);
    REG_BG1CNT = 0xE01;
    REG_BG3CNT = 0xF03;
    REG_BG0CNT = 0x1E08;
    REG_BG2CNT = 0x1F0A;
    DmaSet(3, gUnk_08485FD8[1], PLTT + 0x200, 0x80000050);
    init_battle_sprite_entry_08048818(0, 0xC000, 0x40D, 4, 3);
    gUnk_03002C30[0].unk2 = 0x98;
    gUnk_03002C30[0].unk4 = 0x40;
    setup_screen_transition_effect_080682CC(2, 1, 0);
    gUnk_03000430 = 0;
    gUnk_03001800_s.nextSubState = gUnk_03001800_s.unkC.h;
    gGameSubState = 3;
}

void init_scene_graphics(void)
{
    u8 buf[0x50]; // unused, but the original reserves the stack space
    u32 tmp;
    u16 zero;
    s32 i;

    LZ77UnCompVram(gUnk_087BE494, (void *)VRAM);
    LZ77UnCompVram(gUnk_087C88F4, (void *)(VRAM + 0x8020));
    LZ77UnCompVram(gUnk_087C8BD8, (void *)(VRAM + 0x8C80));
    LZ77UnCompVram(gUnk_087C8C94, (void *)(VRAM + 0x9900));
    LZ77UnCompVram(gUnk_087C8CE4, (void *)(VRAM + 0x9A40));
    DmaSet(3, gUnk_087C09C0, PLTT, 0x84000080);
    DmaSet(3, gUnk_087C8CF4, PLTT + 0x100, 0x84000008);
    DmaSet(3, gUnk_087C8D14, PLTT + 0x120, 0x84000008);
    DmaSet(3, gUnk_087C8D34, PLTT, 0x84000008);
    LZ77UnCompVram(gUnk_087C0BC0, (void *)(VRAM + 0x7000));
    LZ77UnCompVram(gUnk_087C0E0C, (void *)(VRAM + 0x7800));
    zero = 0;
    tmp = zero;
    DmaSet(3, &tmp, VRAM + 0xF800, 0x85000200);
    REG_BG1CNT = 0x1F09;
    REG_BG2CNT = 0xE02;
    REG_BG3CNT = 0xF03;
    setup_screen_transition_effect_080682CC(4, 1, 0);
    init_battle_sprite_entry_08048818(9, 0xC800, 0x404, 1, 3);
    gUnk_03002C30[9].unk2 = 8;
    gUnk_03002C30[9].unk4 = 0xA0;
    init_battle_sprite_entry_08048818(10, 0xC800, 0x405, 1, 3);
    gUnk_03002C30[10].unk2 = zero;
    gUnk_03002C30[10].unk4 = 0x90;
    for (i = 0; i <= 2; i++) {
        ((void (*)())init_battle_sprite_entry_08048818)(i + 11, 0xC400, i + 0x400, 0, 3);
        gUnk_03002C30[i + 11].unk2 = 0xC0;
        gUnk_03002C30[i + 11].unk4 = 0xC8;
    }
    for (i = 0; i <= 5; i++) {
        ((void (*)())init_battle_sprite_entry_08048818)(i + 3, 0xC400, 0x408, 2, 3);
        gUnk_03002C30[i + 3].unk2 = i * 8 + 0xA0;
        gUnk_03002C30[i + 3].unk4 = 0xC8;
        gUnk_03002C30[i + 3].unkB = 0x20;
    }
    sub_0806FF50();
    sub_0806FF90();
    sub_08070030();
    sub_0806FFF8();
    REG_DISPCNT |= 0x1E00;
    REG_BLDCNT = 0x1844;
    REG_BLDALPHA = 0x80B;
    gUnk_03001800_s.nextSubState = gUnk_03001800_s.unkC.h;
    gGameSubState = 1;
}

void load_battle_ui_assets(void)
{
    LZ77UnCompVram(gUnk_08485FD0[1], (void *)0x06010000);
    LZ77UnCompVram(gUnk_087C8D54, gUnk_03001800_s.unk30);
    gGameSubState = 6;
}

void init_battle_result_screen(void)
{
    u32 v;
    s32 legs = 0x2A;
    init_scene_buffers_080445F4();
    v = 0x200;
    DmaSet(3, &v, gUnk_03002414->unkB84, 0x85000100);
    setup_scene_with_bg_and_sprites(0, 0x2A, 0x2A, 0x2A, legs, 0x78, 0x50, 2, 0xC, 0, 0, 0);
    DmaSet(3, gUnk_08485FD8[1], PLTT + 0x200, 0x80000050);
    setup_screen_transition_effect_080682CC(2, 4, 0);
    REG_DISPCNT |= 0x1000;
    gUnk_03001800_s.nextSubState = 15;
    gGameSubState = 1;
}

void sub_0806F038(void)
{
    load_bg_screen_b();
    REG_MOSAIC = 0xFF;
    gUnk_03001800_s.unk6 = 6;
    gBg0Scroll.y = 0xFFE4;
    DmaSet(3, gUnk_08485FD8[1], PLTT + 0x200, 0x80000050);
    gUnk_03001800_s.nextSubState = gUnk_03001800_s.unkC.h;
    gGameSubState = 4;
}

void sub_0806F094(void)
{
    if (battle_transition_fade_step()) {
        gUnk_03001800_s.timer = 0;
        gUnk_03001800_s.nextSubState = 7;
        gUnk_03001800_s.unkC.h = 12;
    }
}

INCLUDE_ASM("asm/nonmatching/code_0806B160", sub_0806F0B4);
