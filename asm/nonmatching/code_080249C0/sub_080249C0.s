	.syntax unified

	thumb_func_start sub_080249C0
sub_080249C0: @ 0x080249C0
	push {r4, r5, r6, lr}
	ldr r4, _080249F4 @ =0x03001800
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
	beq _080249F8
	adds r1, r4, #0
	adds r1, #0xa6
	movs r0, #0x1a
	strb r0, [r1]
	adds r1, #4
	ldrb r0, [r1]
	adds r0, #1
	b _08024A28
	.align 2, 0
_080249F4: .4byte 0x03001800
_080249F8:
	adds r0, r4, #0
	adds r0, #0x88
	ldrb r0, [r0]
	bl sub_080331F8
	cmp r0, #0
	bne _08024A16
	adds r1, r4, #0
	adds r1, #0xa6
	movs r0, #0x39
	strb r0, [r1]
	adds r1, #4
	ldrb r0, [r1]
	adds r0, #1
	b _08024A28
_08024A16:
	bl sub_08036270
	ldrb r0, [r5]
	ldrb r1, [r6]
	bl calc_battle_stat_ratio
	adds r1, r4, #0
	adds r1, #0xaa
	movs r0, #4
_08024A28:
	strb r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.syntax divided
