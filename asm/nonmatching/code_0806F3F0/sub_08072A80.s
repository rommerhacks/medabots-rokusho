	.syntax unified

	thumb_func_start sub_08072A80
sub_08072A80: @ 0x08072A80
	adds r2, r0, #0
	adds r1, r2, #0
	adds r1, #0x53
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08072A96
	ldr r0, [r2, #0x1c]
	str r0, [r2, #0x14]
_08072A96:
	bx lr
	.syntax divided
