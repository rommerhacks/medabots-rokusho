	.syntax unified

	thumb_func_start sub_0801C1C0
sub_0801C1C0: @ 0x0801C1C0
	push {r4, lr}
	ldr r3, _0801C22C @ =0x03002C30
	adds r1, r3, #0
	adds r1, #0xc0
	movs r2, #0
	ldr r0, _0801C230 @ =0x0000C004
	strh r0, [r1]
	adds r0, r3, #0
	adds r0, #0xdc
	strb r2, [r0]
	ldr r4, _0801C234 @ =0x03001800
	adds r2, r4, #0
	adds r2, #0x87
	ldrb r0, [r2]
	lsls r0, r0, #8
	movs r1, #0xba
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r0, r0, r3
	ldrh r0, [r0, #2]
	adds r1, r3, #0
	adds r1, #0xc2
	strh r0, [r1]
	ldrb r0, [r2]
	lsls r0, r0, #8
	movs r1, #0xba
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r0, r0, r3
	ldrh r0, [r0, #4]
	subs r0, #0xc
	adds r1, r3, #0
	adds r1, #0xc4
	strh r0, [r1]
	adds r1, #6
	movs r0, #6
	strb r0, [r1]
	subs r1, #4
	ldr r0, _0801C238 @ =0x00000A11
	strh r0, [r1]
	adds r1, #5
	movs r0, #0x81
	strb r0, [r1]
	movs r0, #0x2f
	bl play_sound_effect
	adds r4, #0x9c
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801C22C: .4byte 0x03002C30
_0801C230: .4byte 0x0000C004
_0801C234: .4byte 0x03001800
_0801C238: .4byte 0x00000A11
	.syntax divided
