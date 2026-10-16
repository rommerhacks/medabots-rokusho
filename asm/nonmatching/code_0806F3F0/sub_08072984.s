	.syntax unified

	thumb_func_start sub_08072984
sub_08072984: @ 0x08072984
	adds r2, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, #0x65
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r2, #0x50
	ldrb r1, [r2]
	movs r0, #2
	orrs r0, r1
	strb r0, [r2]
	bx lr
	.align 2, 0
	.syntax divided
