	.syntax unified

	thumb_func_start check_bot_ability_type_shoot
	.global check_bot_ability_type_shoot
check_bot_ability_type_shoot: @ 0x080358B8
	push {r4, lr}
	adds r3, r2, #0
	ldr r4, _080358E4 @ =0x03000590
	lsls r2, r1, #1
	adds r2, r2, r1
	lsls r2, r2, #3
	lsls r0, r0, #8
	adds r2, r2, r0
	adds r2, r2, r4
	adds r2, #0x49
	ldrb r0, [r2]
	cmp r0, #0x23
	bne _080358E8
	lsls r0, r3, #8
	adds r0, r0, r4
	adds r0, #0x91
	ldrb r0, [r0]
	cmp r0, #0x6a
	bne _080358E8
	movs r0, #1
	b _080358EA
	.align 2, 0
_080358E4: .4byte 0x03000590
_080358E8:
	movs r0, #0
_080358EA:
	pop {r4}
	pop {r1}
	bx r1
	.syntax divided
