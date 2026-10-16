#include "global.h"

INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08030CAC);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08030CFC);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08030D3C);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08030D58);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08030D74);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08030D90);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08030DB4);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08030E14);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08030E54);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08030E78);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08030F10);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08030FEC);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08031048);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_080310A0);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08031120);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08031174);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08031218);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08031298);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_080312CC);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_080312F0);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08031390);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08031438);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08031458);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08031518);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08031538);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_080315B0);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08031614);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08031704);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_0803185C);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_080318CC);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", battle_start_transition_to_action);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08031978);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08031994);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_080319B8);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08031A08);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08031A24);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", battle_process_all_bot_actions);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", battle_execute_action_selection);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", call_bot_action_handler);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", select_battle_targets_and_actions);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", battle_ai_select_target_defend);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", battle_ai_select_target_jump);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", ai_select_target_enemy_side_ability22_status);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", ai_select_target_enemy_side_ewram_check);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", battle_ai_select_target_ability22_enemy);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", ai_select_target_enemy_side_available_part);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", select_enemy_battle_target);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", select_battle_target_for_bot);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", battle_ai_select_target_ability22_ally);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", battle_ai_select_target_status58);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", select_player_battle_target);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", ai_select_target_player_side_ability22);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", clear_battle_action_selection);

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

INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08032FD0);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08032FFC);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", select_battle_pending_action);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", rng_lookup_table_value);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", select_random_battle_target);

u32 sub_080330E8(u32 idx)
{
    return get_random_battle_weight_entry(idx);
}

INCLUDE_ASM("asm/nonmatching/code_08030CAC", battle_find_next_active_bot);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08033154);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", clear_ewram_buffer_02023000_b);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_080331F8);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08033224);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08033240);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", find_random_available_part_slot);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_080332B4);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_080332D0);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", begin_battle_action_lookup);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", check_battle_bot_defeated_set_flag);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_080333E4);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08033490);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_080334E0);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08033698);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_080336DC);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08033754);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_080337CC);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08033840);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_080338F4);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08033974);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_080339F4);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08033A10);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08033A2C);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08033A78);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08033A94);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08033AB0);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08033ACC);
INCLUDE_ASM("asm/nonmatching/code_08030CAC", sub_08033B7C);

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
