	.syntax unified

	thumb_func_start sub_080729A0
sub_080729A0: @ 0x080729A0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	str r1, [r0, #0x2c]
	bx lr
	.syntax divided
