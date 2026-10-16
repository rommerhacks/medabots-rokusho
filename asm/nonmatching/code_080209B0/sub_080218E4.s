	.syntax unified

	thumb_func_start sub_080218E4
sub_080218E4: @ 0x080218E4
	push {r4, r5, lr}
	ldr r4, _08021918 @ =0x03001800
	adds r5, r4, #0
	adds r5, #0x87
	ldrb r0, [r5]
	adds r1, r4, #0
	adds r1, #0xa7
	ldrb r1, [r1]
	bl calc_battle_action_speed
	ldrb r0, [r5]
	bl apply_battle_bot_damage_reduction
	bl decrement_battle_timer_and_check_zero
	cmp r0, #0
	beq _0802191C
	adds r1, r4, #0
	adds r1, #0xa6
	movs r0, #0x1a
	strb r0, [r1]
	adds r1, #4
	ldrb r0, [r1]
	adds r0, #1
	b _08021948
	.align 2, 0
_08021918: .4byte 0x03001800
_0802191C:
	adds r0, r4, #0
	adds r0, #0x89
	ldrb r0, [r0]
	lsls r0, r0, #3
	adds r0, r0, r4
	adds r0, #0x2a
	ldrb r0, [r0]
	cmp r0, #0
	bne _0802193E
	adds r1, r4, #0
	adds r1, #0xa6
	movs r0, #0x24
	strb r0, [r1]
	adds r1, #4
	ldrb r0, [r1]
	adds r0, #1
	b _08021948
_0802193E:
	bl sub_08036270
	adds r1, r4, #0
	adds r1, #0xaa
	movs r0, #4
_08021948:
	strb r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.syntax divided
