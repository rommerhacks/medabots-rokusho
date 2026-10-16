	.syntax unified

	thumb_func_start sub_08023CB8
sub_08023CB8: @ 0x08023CB8
	push {r4, r5, r6, lr}
	ldr r4, _08023CEC @ =0x03001800
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
	beq _08023CF0
	adds r1, r4, #0
	adds r1, #0xa6
	movs r0, #0x1a
	strb r0, [r1]
	adds r1, #4
	ldrb r0, [r1]
	adds r0, #1
	b _08023D3A
	.align 2, 0
_08023CEC: .4byte 0x03001800
_08023CF0:
	adds r0, r4, #0
	adds r0, #0x88
	ldrb r0, [r0]
	bl sub_080331F8
	cmp r0, #0
	bne _08023D0E
	adds r1, r4, #0
	adds r1, #0xa6
	movs r0, #0x39
	strb r0, [r1]
	adds r1, #4
	ldrb r0, [r1]
	adds r0, #1
	b _08023D3A
_08023D0E:
	ldrb r0, [r5]
	bl sub_080331F8
	cmp r0, #0
	bne _08023D28
	adds r1, r4, #0
	adds r1, #0xa6
	movs r0, #0x39
	strb r0, [r1]
	adds r1, #4
	ldrb r0, [r1]
	adds r0, #1
	b _08023D3A
_08023D28:
	bl sub_08036270
	ldrb r0, [r5]
	ldrb r1, [r6]
	bl calc_battle_stat_ratio
	adds r1, r4, #0
	adds r1, #0xaa
	movs r0, #4
_08023D3A:
	strb r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
