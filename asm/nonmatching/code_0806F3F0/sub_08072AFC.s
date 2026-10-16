	.syntax unified

	thumb_func_start sub_08072AFC
sub_08072AFC: @ 0x08072AFC
	adds r3, r0, #0
	ldr r0, [r3, #0x14]
	ldrb r1, [r0]
	adds r2, r3, #0
	adds r2, #0x56
	strb r1, [r2]
	adds r0, #1
	str r0, [r3, #0x14]
	ldrb r1, [r0]
	adds r0, #1
	str r0, [r3, #0x14]
	lsrs r2, r1, #4
	adds r0, r3, #0
	adds r0, #0x58
	strb r2, [r0]
	movs r0, #0xf
	ands r1, r0
	adds r0, r3, #0
	adds r0, #0x57
	strb r1, [r0]
	bx lr
	.align 2, 0
	.syntax divided
