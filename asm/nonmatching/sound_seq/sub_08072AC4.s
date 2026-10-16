	.syntax unified

	thumb_func_start sub_08072AC4
sub_08072AC4: @ 0x08072AC4
	adds r3, r0, #0
	ldr r0, [r3, #0x14]
	ldrb r1, [r0]
	adds r2, r3, #0
	adds r2, #0x54
	strb r1, [r2]
	adds r0, #1
	str r0, [r3, #0x14]
	ldrb r0, [r2]
	cmp r0, #0
	bne _08072ADE
	movs r0, #8
	strb r0, [r2]
_08072ADE:
	adds r0, r3, #0
	adds r0, #0x50
	ldrb r1, [r0]
	movs r2, #8
	orrs r1, r2
	strb r1, [r0]
	bx lr
	.syntax divided
