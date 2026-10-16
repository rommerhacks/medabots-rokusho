	.syntax unified

	thumb_func_start sub_08073CA4
sub_08073CA4: @ 0x08073CA4
	adds r0, #0x3e
	movs r1, #3
	strb r1, [r0]
	bx lr
	.syntax divided
