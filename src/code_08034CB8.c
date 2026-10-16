#include "global.h"

INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08034CB8);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08034CD4);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08034CF0);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08034D0C);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08034D28);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08034D44);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08034D60);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08034D7C);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08034D98);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08034DB4);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08034DD0);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08034DEC);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08034E08);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08034E24);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08034E40);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08034E5C);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08034E78);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08034E94);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08034EB8);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08034F08);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08034F44);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", battle_set_damage_vs_armor);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", set_target_sprite_position);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_080350E0);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", update_target_cursor_position);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", reduce_bot_part_stat);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08035194);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_080351E8);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", add_bot_to_defeated_list);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sprite_move_toward_target);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", update_sprite_deceleration);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_0803536C);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_080353AC);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_080353CC);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", battle_sprite_blink_update);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08035478);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", calc_bot_evasion_modifier);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", get_random_battle_weight_entry);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08035590);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_080355C4);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", move_sprite_toward_target);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", check_sprite_in_range);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08035694);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_080356B4);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", check_sprite_overlap_and_adjust);

void sub_0803572C(u8 *val, s32 amount)
{
    if (*val < amount)
        *val = 0;
    else
        *val -= amount;
}

INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08035740);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08035754);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", calc_bot_matching_part_power);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", calc_battle_action_speed);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", apply_battle_bot_damage_reduction);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", accumulate_battle_speed_value);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", check_bot_ability_type_strike);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", check_bot_ability_type_shoot);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_080358F0);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08035928);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08035944);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08035960);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", check_bot_can_shoot);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", check_bot_can_support);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", check_bot_can_use_shoot_part);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", check_bot_status_effect_4);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", check_can_target_bot);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", check_battle_can_support_target);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", check_battle_can_special_target);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08035B9C);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08035BD4);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08035BFC);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08035C3C);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08035C70);

u32 sub_08035DD4(u32 a)
{
    if (a - 0x128 <= 0xA8)
        return 0;
    return 1;
}

INCLUDE_ASM("asm/nonmatching/code_08034CB8", init_battle_scene_backgrounds);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", setup_battle_medapart_scenes);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", get_active_bot_part_index_and_load_values);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_080361A8);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", battle_advance_dialogue_text);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", battle_advance_action_text);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08036270);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_0803628C);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_080362C4);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08036340);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08036370);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_080363E8);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_080364A8);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_080366DC);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08036784);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_0803684C);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_080368C4);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", setup_battle_sprite_oam_entries);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", advance_sprite_anim_frame);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", advance_sprite_group_anims);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08036B50);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08036B84);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08036BB8);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08036BF4);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08036C20);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", battle_calc_damage_split);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", battle_check_action_counter);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08036D64);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", medal_update_exp_progress);

u32 sub_08036E54(u32 a)
{
    if (a > 99)
        a = 99;
    else if (a == 0)
        a = 1;
    return a;
}

INCLUDE_ASM("asm/nonmatching/code_08034CB8", battle_set_action_params);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", reset_battle_bot_state);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", setup_battle_cursor_sprite_08036FF8);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", update_sprite_animations_tick_080370AC);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_0803713C);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08037230);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", decrement_battle_timer_and_check_zero);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", calc_battle_stat_ratio);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", battle_set_damage_display);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08037330);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_080373D4);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08037424);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08037458);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08037498);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_080374E0);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_0803752C);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08037578);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_0803769C);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_080376F4);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08037728);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08037798);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", battle_select_random_target);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_080378A8);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_080378F0);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", spawn_battle_particle_effect);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08037B9C);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08037BF4);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08037C50);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08037E2C);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_0803809C);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_080380F0);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08038178);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_080381E0);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08038258);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_080382F4);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_0803836C);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08038394);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_080383E8);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08038428);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_0803858C);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_080385D0);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_080385F8);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08038650);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08038700);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08038804);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_0803884C);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_080388A4);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08038AC0);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08038BC0);
