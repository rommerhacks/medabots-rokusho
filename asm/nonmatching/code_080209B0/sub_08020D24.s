	.syntax unified

	thumb_func_start sub_08020D24
sub_08020D24: @ 0x08020D24
	push {r4, r5, r6, r7, lr}
	ldr r4, _08020D58 @ =0x03001800
	adds r6, r4, #0
	adds r6, #0x87
	ldrb r0, [r6]
	adds r5, r4, #0
	adds r5, #0xa7
	ldrb r1, [r5]
	bl calc_battle_action_speed
	ldrb r0, [r6]
	bl apply_battle_bot_damage_reduction
	bl decrement_battle_timer_and_check_zero
	adds r7, r0, #0
	cmp r7, #0
	beq _08020D5C
	adds r1, r4, #0
	adds r1, #0xa6
	movs r0, #0x1a
	strb r0, [r1]
	adds r1, #4
	ldrb r0, [r1]
	adds r0, #1
	b _08020DE6
	.align 2, 0
_08020D58: .4byte 0x03001800
_08020D5C:
	ldrb r0, [r6]
	ldrb r1, [r5]
	bl calc_battle_stat_ratio
	bl sub_08036270
	ldr r2, _08020D90 @ =0x03000590
	ldrb r1, [r5]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	ldrb r1, [r6]
	lsls r1, r1, #8
	adds r0, r0, r1
	adds r0, r0, r2
	adds r0, #0x49
	ldrb r0, [r0]
	cmp r0, #0xa
	beq _08020D94
	cmp r0, #0xa
	blt _08020DB2
	cmp r0, #0xb
	beq _08020D9E
	cmp r0, #0xc
	beq _08020DA6
	b _08020DB2
	.align 2, 0
_08020D90: .4byte 0x03000590
_08020D94:
	adds r0, r4, #0
	adds r0, #0x51
	strb r7, [r0]
	adds r3, r4, #0
	b _08020DBE
_08020D9E:
	adds r1, r4, #0
	adds r1, #0x51
	movs r0, #1
	b _08020DAC
_08020DA6:
	adds r1, r4, #0
	adds r1, #0x51
	movs r0, #2
_08020DAC:
	strb r0, [r1]
	adds r3, r4, #0
	b _08020DBE
_08020DB2:
	ldr r1, _08020DF0 @ =0x03001800
	adds r2, r1, #0
	adds r2, #0x51
	movs r0, #3
	strb r0, [r2]
	adds r3, r1, #0
_08020DBE:
	ldr r2, _08020DF4 @ =0x03000590
	adds r0, r3, #0
	adds r0, #0xa7
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r1, r3, #0
	adds r1, #0x87
	ldrb r1, [r1]
	lsls r1, r1, #8
	adds r0, r0, r1
	adds r0, r0, r2
	adds r0, #0x49
	ldrb r0, [r0]
	adds r1, r3, #0
	adds r1, #0x52
	strb r0, [r1]
	adds r1, #0x58
	movs r0, #4
_08020DE6:
	strb r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08020DF0: .4byte 0x03001800
_08020DF4: .4byte 0x03000590
	.syntax divided
