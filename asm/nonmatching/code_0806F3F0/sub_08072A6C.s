	.syntax unified

	thumb_func_start sub_08072A6C
sub_08072A6C: @ 0x08072A6C
	ldr r1, [r0, #0x14]
	ldrb r2, [r1]
	adds r3, r0, #0
	adds r3, #0x53
	strb r2, [r3]
	adds r1, #1
	str r1, [r0, #0x14]
	str r1, [r0, #0x1c]
	bx lr
	.align 2, 0
	.syntax divided
