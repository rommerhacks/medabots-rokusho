	.syntax unified

	thumb_func_start sub_080729EC
sub_080729EC: @ 0x080729EC
	ldr r1, [r0, #0x14]
	ldrb r2, [r1]
	adds r3, r0, #0
	adds r3, #0x6a
	strb r2, [r3]
	adds r1, #1
	str r1, [r0, #0x14]
	bx lr
	.syntax divided
