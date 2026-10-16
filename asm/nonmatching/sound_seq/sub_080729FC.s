	.syntax unified

	thumb_func_start sub_080729FC
sub_080729FC: @ 0x080729FC
	ldr r1, [r0, #0x14]
	ldrb r2, [r1]
	adds r3, r0, #0
	adds r3, #0x6b
	strb r2, [r3]
	adds r1, #1
	str r1, [r0, #0x14]
	ldrb r0, [r3]
	cmp r0, #0x30
	bls _08072A14
	movs r0, #0x30
	strb r0, [r3]
_08072A14:
	bx lr
	.align 2, 0
	.syntax divided
