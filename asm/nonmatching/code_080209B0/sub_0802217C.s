	.syntax unified

	thumb_func_start sub_0802217C
sub_0802217C: @ 0x0802217C
	push {r4, r5, lr}
	ldr r4, _080221B0 @ =0x03001800
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
	beq _080221B4
	adds r1, r4, #0
	adds r1, #0xa6
	movs r0, #0x1a
	strb r0, [r1]
	adds r1, #4
	ldrb r0, [r1]
	adds r0, #1
	b _080221BE
	.align 2, 0
_080221B0: .4byte 0x03001800
_080221B4:
	bl sub_08036270
	adds r1, r4, #0
	adds r1, #0xaa
	movs r0, #4
_080221BE:
	strb r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
