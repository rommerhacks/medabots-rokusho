	.syntax unified

	thumb_func_start sub_08014ADC
sub_08014ADC: @ 0x08014ADC
	push {r4, lr}
	ldr r1, _08014B24 @ =0x03001800
	adds r0, r1, #0
	adds r0, #0x51
	movs r2, #0
	strb r2, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, #1
	strb r2, [r0]
	movs r0, #0xd3
	lsls r0, r0, #1
	adds r3, r1, r0
	movs r0, #0
	strh r2, [r3]
	ldr r4, _08014B28 @ =0x000001AF
	adds r3, r1, r4
	strb r0, [r3]
	movs r0, #0xd8
	lsls r0, r0, #1
	adds r1, r1, r0
	movs r0, #1
	strb r0, [r1]
	ldr r0, _08014B2C @ =0x03000440
	adds r0, #0x86
	strh r2, [r0]
	ldr r1, _08014B30 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08014B24: .4byte 0x03001800
_08014B28: .4byte 0x000001AF
_08014B2C: .4byte 0x03000440
_08014B30: .4byte 0x0300137C
	.syntax divided
