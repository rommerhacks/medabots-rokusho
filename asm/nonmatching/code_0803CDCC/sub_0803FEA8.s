	.syntax unified

	thumb_func_start sub_0803FEA8
sub_0803FEA8: @ 0x0803FEA8
	ldr r1, _0803FEB4 @ =0x03000440
	ldrh r0, [r1, #0xc]
	adds r0, #1
	strh r0, [r1, #0xc]
	bx lr
	.align 2, 0
_0803FEB4: .4byte 0x03000440
	.syntax divided
