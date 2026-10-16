	.syntax unified

	thumb_func_start sub_080729BC
sub_080729BC: @ 0x080729BC
	ldr r1, [r0, #0x14]
	ldrb r2, [r1]
	adds r3, r0, #0
	adds r3, #0x67
	strb r2, [r3]
	adds r1, #1
	str r1, [r0, #0x14]
	adds r0, #0x50
	ldrb r2, [r0]
	movs r1, #0x20
	orrs r1, r2
	strb r1, [r0]
	bx lr
	.align 2, 0
	.syntax divided
