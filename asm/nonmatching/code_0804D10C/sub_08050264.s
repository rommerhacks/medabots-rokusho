	.syntax unified

	thumb_func_start sub_08050264
	.global sub_08050264
sub_08050264: @ 0x08050264
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x1c
	bx lr
	.align 2, 0
	.syntax divided
