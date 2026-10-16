	.syntax unified

	thumb_func_start sub_08072AEC
sub_08072AEC: @ 0x08072AEC
	ldr r1, [r0, #0x14]
	ldrb r2, [r1]
	adds r3, r0, #0
	adds r3, #0x55
	strb r2, [r3]
	adds r1, #1
	str r1, [r0, #0x14]
	bx lr
	.syntax divided
