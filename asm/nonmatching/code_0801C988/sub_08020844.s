	.syntax unified

	thumb_func_start sub_08020844
sub_08020844: @ 0x08020844
	push {r4, r5, r6, r7, lr}
	ldr r4, _08020884 @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x88
	ldrb r0, [r0]
	adds r1, r4, #0
	adds r1, #0x8b
	ldrb r1, [r1]
	bl sub_08037230
	cmp r0, #0
	bne _080208A6
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
	beq _08020888
	adds r1, r4, #0
	adds r1, #0xa6
	movs r0, #0x1a
	b _080208AC
	.align 2, 0
_08020884: .4byte 0x03001800
_08020888:
	ldrb r0, [r5]
	ldrb r1, [r7]
	bl calc_battle_stat_ratio
	bl sub_08036270
	adds r1, r4, #0
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0xab
	strb r6, [r0]
	b _080208BA
_080208A6:
	adds r1, r4, #0
	adds r1, #0xa6
	movs r0, #0x26
_080208AC:
	strb r0, [r1]
	adds r1, #4
	movs r0, #2
	strb r0, [r1]
	adds r1, #1
	movs r0, #1
	strb r0, [r1]
_080208BA:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.syntax divided
