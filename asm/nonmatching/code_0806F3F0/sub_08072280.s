	.syntax unified

	thumb_func_start sub_08072280
sub_08072280: @ 0x08072280
	adds r1, r0, #0
	adds r2, r1, #0
	adds r2, #0x61
	movs r0, #0
	strb r0, [r2]
	adds r2, #5
	strb r0, [r2]
	subs r2, #0x16
	ldrb r1, [r2]
	movs r0, #2
	orrs r0, r1
	strb r0, [r2]
	bx lr
	.align 2, 0
	.syntax divided
