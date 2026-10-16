	.syntax unified

	thumb_func_start sub_08037424
	.global sub_08037424
sub_08037424: @ 0x08037424
	ldr r1, _08037450 @ =0x03002C30
	lsls r0, r0, #6
	adds r0, r0, r1
	ldr r2, _08037454 @ =0x083AF4E0
	adds r3, r0, #0
	adds r3, #0x23
	ldrb r1, [r3]
	lsls r1, r1, #1
	adds r1, r1, r2
	ldrh r1, [r1]
	ldrh r2, [r0, #4]
	adds r1, r1, r2
	movs r2, #0xff
	ands r1, r2
	strh r1, [r0, #4]
	ldrb r0, [r3]
	adds r0, #1
	movs r1, #0x1f
	ands r0, r1
	strb r0, [r3]
	bx lr
	.align 2, 0
_08037450: .4byte 0x03002C30
_08037454: .4byte 0x083AF4E0
	.syntax divided
