	.syntax unified

	thumb_func_start sub_080209D8
sub_080209D8: @ 0x080209D8
	push {r4, r5, r6, r7, lr}
	ldr r2, _08020A28 @ =0x03000590
	ldr r4, _08020A2C @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x8b
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r1, r4, #0
	adds r1, #0x88
	ldrb r1, [r1]
	lsls r1, r1, #8
	adds r0, r0, r1
	adds r0, r0, r2
	adds r0, #0x59
	ldrb r0, [r0]
	cmp r0, #0
	bne _08020A4E
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
	beq _08020A30
	adds r1, r4, #0
	adds r1, #0xa6
	movs r0, #0x1a
	b _08020A54
	.align 2, 0
_08020A28: .4byte 0x03000590
_08020A2C: .4byte 0x03001800
_08020A30:
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
	b _08020A62
_08020A4E:
	adds r1, r4, #0
	adds r1, #0xa6
	movs r0, #0x27
_08020A54:
	strb r0, [r1]
	adds r1, #4
	movs r0, #2
	strb r0, [r1]
	adds r1, #1
	movs r0, #1
	strb r0, [r1]
_08020A62:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.syntax divided
