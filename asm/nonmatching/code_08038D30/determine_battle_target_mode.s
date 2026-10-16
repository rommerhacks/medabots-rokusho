	.syntax unified

	thumb_func_start determine_battle_target_mode
	.global determine_battle_target_mode
determine_battle_target_mode: @ 0x0803934C
	push {r4, r5, r6, lr}
	ldr r4, _08039378 @ =0x03001800
	adds r6, r4, #0
	adds r6, #0x87
	ldrb r2, [r6]
	adds r5, r4, #0
	adds r5, #0xa7
	ldrb r1, [r5]
	adds r0, r2, #0
	bl check_can_target_bot
	cmp r0, #0
	beq _0803937C
	adds r1, r4, #0
	adds r1, #0xb8
	movs r0, #4
	strb r0, [r1]
	adds r1, #7
	movs r0, #2
	strb r0, [r1]
	b _080393B4
	.align 2, 0
_08039378: .4byte 0x03001800
_0803937C:
	ldrb r2, [r6]
	ldrb r1, [r5]
	adds r0, r2, #0
	bl check_battle_can_support_target
	cmp r0, #0
	beq _0803939A
	adds r1, r4, #0
	adds r1, #0xb8
	movs r0, #4
	strb r0, [r1]
	adds r1, #7
	movs r0, #3
	strb r0, [r1]
	b _080393B4
_0803939A:
	ldrb r2, [r6]
	ldrb r1, [r5]
	adds r0, r2, #0
	bl check_battle_can_special_target
	cmp r0, #0
	beq _080393B4
	adds r0, r4, #0
	adds r0, #0xb8
	movs r1, #4
	strb r1, [r0]
	adds r0, #7
	strb r1, [r0]
_080393B4:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
