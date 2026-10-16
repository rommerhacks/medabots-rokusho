	.syntax unified

	thumb_func_start sub_080750CC
sub_080750CC: @ 0x080750CC
	ldr r0, _080750D4 @ =0x03007014
	ldr r0, [r0]
	bx lr
	.align 2, 0
_080750D4: .4byte 0x03007014
	.syntax divided
