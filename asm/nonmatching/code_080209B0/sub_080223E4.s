	.syntax unified

	thumb_func_start sub_080223E4
sub_080223E4: @ 0x080223E4
	push {r4, r5, r6, r7, lr}
	ldr r4, _08022418 @ =0x03001800
	adds r5, r4, #0
	adds r5, #0x87
	ldrb r0, [r5]
	adds r7, r4, #0
	adds r7, #0xa7
	ldrb r1, [r7]
	bl calc_battle_action_speed
	ldrb r0, [r5]
	bl apply_battle_bot_damage_reduction
	bl decrement_battle_timer_and_check_zero
	adds r6, r0, #0
	cmp r6, #0
	beq _0802241C
	adds r1, r4, #0
	adds r1, #0xa6
	movs r0, #0x1a
	strb r0, [r1]
	adds r1, #4
	ldrb r0, [r1]
	adds r0, #1
	b _08022474
	.align 2, 0
_08022418: .4byte 0x03001800
_0802241C:
	bl sub_08036270
	ldr r2, _08022448 @ =0x03000590
	ldrb r1, [r7]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	ldrb r1, [r5]
	lsls r1, r1, #8
	adds r0, r0, r1
	adds r0, r0, r2
	adds r0, #0x49
	ldrb r0, [r0]
	cmp r0, #0x1b
	beq _0802244C
	cmp r0, #0x1c
	beq _08022454
	adds r1, r4, #0
	adds r1, #0x51
	movs r0, #2
	b _0802245A
	.align 2, 0
_08022448: .4byte 0x03000590
_0802244C:
	adds r0, r4, #0
	adds r0, #0x51
	strb r6, [r0]
	b _0802245C
_08022454:
	adds r1, r4, #0
	adds r1, #0x51
	movs r0, #1
_0802245A:
	strb r0, [r1]
_0802245C:
	ldr r4, _0802247C @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x87
	ldrb r0, [r0]
	adds r1, r4, #0
	adds r1, #0xa7
	ldrb r1, [r1]
	bl calc_battle_stat_ratio
	adds r1, r4, #0
	adds r1, #0xaa
	movs r0, #4
_08022474:
	strb r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802247C: .4byte 0x03001800
	.syntax divided
