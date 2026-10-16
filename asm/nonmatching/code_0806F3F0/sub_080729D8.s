	.syntax unified

	thumb_func_start sub_080729D8
sub_080729D8: @ 0x080729D8
	adds r2, r0, #0
	adds r2, #0x67
	strb r1, [r2]
	adds r0, #0x50
	ldrb r2, [r0]
	movs r1, #4
	orrs r1, r2
	strb r1, [r0]
	bx lr
	.align 2, 0
	.syntax divided
