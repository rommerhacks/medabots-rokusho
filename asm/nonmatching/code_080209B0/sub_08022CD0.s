	.syntax unified

	thumb_func_start sub_08022CD0
sub_08022CD0: @ 0x08022CD0
	push {r4, r5, r6, lr}
	ldr r4, _08022D04 @ =0x03001800
	adds r5, r4, #0
	adds r5, #0x87
	ldrb r0, [r5]
	adds r6, r4, #0
	adds r6, #0xa7
	ldrb r1, [r6]
	bl calc_battle_action_speed
	ldrb r0, [r5]
	bl apply_battle_bot_damage_reduction
	bl decrement_battle_timer_and_check_zero
	cmp r0, #0
	beq _08022D08
	adds r1, r4, #0
	adds r1, #0xa6
	movs r0, #0x1a
	strb r0, [r1]
	adds r1, #4
	ldrb r0, [r1]
	adds r0, #1
	b _08022D42
	.align 2, 0
_08022D04: .4byte 0x03001800
_08022D08:
	ldr r1, _08022D2C @ =0x03000590
	adds r0, r4, #0
	adds r0, #0x88
	ldrb r0, [r0]
	lsls r0, r0, #8
	adds r0, r0, r1
	adds r0, #0x59
	ldrb r0, [r0]
	cmp r0, #0
	beq _08022D30
	adds r1, r4, #0
	adds r1, #0xa6
	movs r0, #9
	strb r0, [r1]
	adds r1, #4
	ldrb r0, [r1]
	adds r0, #1
	b _08022D42
	.align 2, 0
_08022D2C: .4byte 0x03000590
_08022D30:
	bl sub_08036270
	ldrb r0, [r5]
	ldrb r1, [r6]
	bl calc_battle_stat_ratio
	adds r1, r4, #0
	adds r1, #0xaa
	movs r0, #4
_08022D42:
	strb r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
