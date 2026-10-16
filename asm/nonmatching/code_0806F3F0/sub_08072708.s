	.syntax unified

	thumb_func_start sub_08072708
sub_08072708: @ 0x08072708
	adds r3, r0, #0
	ldr r2, [r3, #0x14]
	ldrb r0, [r2]
	ldrb r1, [r2, #1]
	lsls r1, r1, #8
	adds r0, r0, r1
	ldrb r1, [r2, #2]
	lsls r1, r1, #0x10
	adds r0, r0, r1
	ldrb r1, [r2, #3]
	lsls r1, r1, #0x18
	adds r0, r0, r1
	adds r2, #4
	str r2, [r3, #0x14]
	bx lr
	.align 2, 0
	.syntax divided
