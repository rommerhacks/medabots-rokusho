	.syntax unified

	thumb_func_start sub_08072ABC
sub_08072ABC: @ 0x08072ABC
	ldr r1, [r0, #0x20]
	str r1, [r0, #0x14]
	bx lr
	.align 2, 0
	.syntax divided
