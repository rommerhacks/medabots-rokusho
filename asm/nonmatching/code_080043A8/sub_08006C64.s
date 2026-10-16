	.syntax unified

	thumb_func_start sub_08006C64
sub_08006C64: @ 0x08006C64
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	ldr r0, _08006CAC @ =0x0300058C
	ldrb r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne _08006C7C
	b _08006DF8
_08006C7C:
	movs r0, #4
	bl play_sound_effect
	movs r0, #0
	str r0, [sp]
	ldr r1, _08006CB0 @ =0x03000440
	adds r2, r1, #0
	adds r2, #0x5a
	ldrb r0, [r2]
	cmp r0, #0
	beq _08006C96
	subs r0, #1
	str r0, [sp]
_08006C96:
	ldr r0, [sp]
	cmp r0, #1
	beq _08006CBA
	cmp r0, #1
	blo _08006CB4
	cmp r0, #2
	beq _08006CC0
	cmp r0, #3
	beq _08006CC6
	b _08006CCE
	.align 2, 0
_08006CAC: .4byte 0x0300058C
_08006CB0: .4byte 0x03000440
_08006CB4:
	adds r0, r1, #0
	adds r0, #0x98
	b _08006CCA
_08006CBA:
	adds r0, r1, #0
	adds r0, #0x99
	b _08006CCA
_08006CC0:
	adds r0, r1, #0
	adds r0, #0x9a
	b _08006CCA
_08006CC6:
	adds r0, r1, #0
	adds r0, #0x9b
_08006CCA:
	ldrb r0, [r0]
	str r0, [sp, #4]
_08006CCE:
	bl sub_080437E0
	cmp r0, #0
	beq _08006D30
	ldr r0, [sp, #4]
	ldr r2, _08006CF4 @ =0x030017A0
	ldr r1, _08006CF8 @ =0x03000440
	adds r1, #0x51
	ldrb r1, [r1]
	lsls r1, r1, #3
	adds r1, r1, r2
	ldrb r3, [r1, #1]
	ldr r1, [sp]
	movs r2, #0
	bl find_next_available_medapart_slot
	str r0, [sp, #4]
	b _08006D30
	.align 2, 0
_08006CF4: .4byte 0x030017A0
_08006CF8: .4byte 0x03000440
_08006CFC:
	bl render_script_text_window
	bl render_medal_skill_row_0
	bl render_medal_name_text
	bl render_medal_skill_row_1
	bl render_medal_desc_text
	bl render_medal_skill_row_2
	bl render_script_text_line
	bl render_medal_skill_row_3
	bl draw_battle_stat_value
	bl decompress_sprite_from_game_state
	bl setup_battle_sprite_from_game_state
	bl setup_scene_with_link_check
	movs r0, #1
	b _08006DFA
_08006D30:
	ldr r0, [sp, #4]
	bl sub_08006E08
	str r0, [sp, #4]
	ldr r5, _08006DC0 @ =0x030017A0
	ldr r4, _08006DC4 @ =0x03000491
	movs r0, #0x47
	adds r0, r0, r4
	mov sb, r0
	movs r1, #0x4a
	adds r1, r1, r4
	mov r8, r1
	adds r7, r4, #0
	adds r7, #0x48
	adds r6, r4, #0
	adds r6, #0x49
_08006D50:
	ldr r0, [sp, #4]
	ldrb r1, [r4]
	lsls r1, r1, #3
	adds r1, r1, r5
	ldrb r3, [r1, #1]
	movs r1, #0
	movs r2, #0
	bl find_next_available_medapart_slot
	mov r1, sb
	strb r0, [r1]
	ldr r0, [sp, #4]
	ldrb r1, [r4]
	lsls r1, r1, #3
	adds r1, r1, r5
	ldrb r3, [r1, #1]
	movs r1, #1
	movs r2, #0
	bl find_next_available_medapart_slot
	strb r0, [r7]
	ldr r0, [sp, #4]
	ldrb r1, [r4]
	lsls r1, r1, #3
	adds r1, r1, r5
	ldrb r3, [r1, #1]
	movs r1, #2
	movs r2, #0
	bl find_next_available_medapart_slot
	strb r0, [r6]
	ldr r0, [sp, #4]
	ldrb r1, [r4]
	lsls r1, r1, #3
	adds r1, r1, r5
	ldrb r3, [r1, #1]
	movs r1, #3
	movs r2, #0
	bl find_next_available_medapart_slot
	mov r1, r8
	strb r0, [r1]
	bl sub_080437E0
	cmp r0, #0
	bne _08006CFC
	ldr r0, [sp]
	cmp r0, #1
	beq _08006DCC
	cmp r0, #1
	blo _08006DC8
	cmp r0, #2
	beq _08006DD0
	cmp r0, #3
	beq _08006DD4
	b _08006DDA
	.align 2, 0
_08006DC0: .4byte 0x030017A0
_08006DC4: .4byte 0x03000491
_08006DC8:
	mov r1, sb
	b _08006DD6
_08006DCC:
	ldrb r0, [r7]
	b _08006DD8
_08006DD0:
	ldrb r0, [r6]
	b _08006DD8
_08006DD4:
	mov r1, r8
_08006DD6:
	ldrb r0, [r1]
_08006DD8:
	str r0, [sp, #4]
_08006DDA:
	ldr r0, [sp, #4]
	ldrb r1, [r4]
	lsls r1, r1, #3
	adds r1, r1, r5
	ldrb r3, [r1, #1]
	ldr r1, [sp]
	movs r2, #0
	bl find_next_available_medapart_slot
	str r0, [sp, #4]
	ldr r0, [sp, #4]
	bl sub_08006E08
	str r0, [sp, #4]
	b _08006D50
_08006DF8:
	movs r0, #0
_08006DFA:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.syntax divided
