	.syntax unified

	thumb_func_start reset_battle_bot_state
	.global reset_battle_bot_state
reset_battle_bot_state: @ 0x08036FA0
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r5, _08036FF4 @ =0x03000590
	lsls r4, r4, #8
	adds r1, r4, r5
	adds r0, r1, #0
	adds r0, #0x40
	movs r2, #0
	strb r2, [r0]
	adds r0, #0x19
	strb r2, [r0]
	adds r0, #0x60
	strb r2, [r0]
	adds r3, r1, #0
	adds r3, #0xba
	movs r0, #2
	strb r0, [r3]
	adds r6, r1, #0
	adds r6, #0xbc
	strb r2, [r6]
	adds r3, #3
	ldrb r1, [r3]
	movs r0, #0xe4
	ands r0, r1
	strb r0, [r3]
	strb r2, [r6]
	adds r0, r5, #0
	adds r0, #0xc4
	adds r0, r4, r0
	movs r1, #0xc
	bl sub_0803F624
	adds r5, #0xdc
	adds r4, r4, r5
	adds r0, r4, #0
	movs r1, #8
	movs r2, #0
	bl sub_0803F624
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08036FF4: .4byte 0x03000590
	.syntax divided
