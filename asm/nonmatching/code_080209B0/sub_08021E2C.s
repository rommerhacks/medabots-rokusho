	.syntax unified

	thumb_func_start sub_08021E2C
sub_08021E2C: @ 0x08021E2C
	push {r4, r5, lr}
	ldr r4, _08021E60 @ =0x03001800
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
	beq _08021E64
	adds r1, r4, #0
	adds r1, #0xa6
	movs r0, #0x1a
	strb r0, [r1]
	adds r1, #4
	ldrb r0, [r1]
	adds r0, #1
	b _08021E96
	.align 2, 0
_08021E60: .4byte 0x03001800
_08021E64:
	ldr r1, _08021E88 @ =0x03000590
	adds r0, r4, #0
	adds r0, #0x88
	ldrb r0, [r0]
	lsls r0, r0, #8
	adds r0, r0, r1
	adds r0, #0xc9
	ldrb r0, [r0]
	cmp r0, #0
	bne _08021E8C
	adds r1, r4, #0
	adds r1, #0xa6
	movs r0, #0x70
	strb r0, [r1]
	adds r1, #4
	ldrb r0, [r1]
	adds r0, #1
	b _08021E96
	.align 2, 0
_08021E88: .4byte 0x03000590
_08021E8C:
	bl sub_08036270
	adds r1, r4, #0
	adds r1, #0xaa
	movs r0, #4
_08021E96:
	strb r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
