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

INCLUDE_ASM("asm/nonmatching/code_0806B160", battle_init_tilemap_and_palette);

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

void scene_transition_countdown_tick(void)
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

void battle_scene_dispatch(void)
{
    gUnk_08485F38[gGameSubState]();
    scene_transition_countdown_tick();
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

void init_game_display_and_clear_state(void)
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

INCLUDE_ASM("asm/nonmatching/code_0806B160", battle_init_bg_screen);
INCLUDE_ASM("asm/nonmatching/code_0806B160", init_battle_bg_tilemap);
INCLUDE_ASM("asm/nonmatching/code_0806B160", battle_bg_init_overlay);

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

void sub_0806E834(void)
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

void sub_0806E8C8(void)
{
    if (KEYS_LO(gHeldKeys) & 8) {
        gUnk_03007008 = 1;
        gUnk_03000430 = 0;
        gGameMode = 3;
        gGameState = 2;
        gGameSubState = 0;
    }
}

void sub_0806E90C(void)
{
    sub_0806E854();
    gUnk_08485F68[gGameSubState]();
    sub_0806E8C8();
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

INCLUDE_ASM("asm/nonmatching/code_0806B160", scene_fade_out_and_restore_state);
INCLUDE_ASM("asm/nonmatching/code_0806B160", scene_animate_and_complete);
INCLUDE_ASM("asm/nonmatching/code_0806B160", battle_scene_init_clear);
INCLUDE_ASM("asm/nonmatching/code_0806B160", load_battle_scene_graphics);
INCLUDE_ASM("asm/nonmatching/code_0806B160", init_scene_graphics);
INCLUDE_ASM("asm/nonmatching/code_0806B160", load_battle_ui_assets);
INCLUDE_ASM("asm/nonmatching/code_0806B160", init_battle_result_screen);
INCLUDE_ASM("asm/nonmatching/code_0806B160", sub_0806F038);
INCLUDE_ASM("asm/nonmatching/code_0806B160", sub_0806F094);
INCLUDE_ASM("asm/nonmatching/code_0806B160", sub_0806F0B4);
