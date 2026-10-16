	.syntax unified

	thumb_func_start sub_08072A54
sub_08072A54: @ 0x08072A54
	adds r2, r0, #0
	adds r1, r2, #0
	adds r1, #0x52
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08072A6A
	ldr r0, [r2, #0x18]
	str r0, [r2, #0x14]
_08072A6A:
	bx lr
	.syntax divided
