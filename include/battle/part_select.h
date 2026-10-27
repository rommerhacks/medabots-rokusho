#ifndef GUARD_BATTLE_PART_SELECT_H
#define GUARD_BATTLE_PART_SELECT_H

// Robattle part select: part icons, names, skill info, head uses

u32 part_skill_is_passive(u32 rec, u32 part); // 1 if the part's skill id (data[1]) is 0x18-0x1A, 0x28 or 0x35
void part_select_init_cursor(void);
void part_select_init_center_icon(void);
void part_select_draw_part_name(void);
void part_select_draw_skill_type(void);
void part_select_draw_skill_name(void);
void part_select_draw_head_uses(void);
void part_select_blink_selected_icon(void);
void part_select_input(void);
void part_select_blink_status(void);
void part_select_init_head_icon(u32 a);
void part_select_init_right_arm_icon(u32 a);
void part_select_init_left_arm_icon(u32 a);
void part_select_init_bottom_icon(u32 a);

#endif // GUARD_BATTLE_PART_SELECT_H
