	.syntax unified

	thumb_func_start sub_08072A34
sub_08072A34: @ 0x08072A34
	adds r0, #0x4c
	ldrh r1, [r0]
	adds r1, #1
	strh r1, [r0]
	bx lr
	.align 2, 0
	.syntax divided
