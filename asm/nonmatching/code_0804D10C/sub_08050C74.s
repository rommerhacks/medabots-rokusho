	.syntax unified

	thumb_func_start sub_08050C74
sub_08050C74: @ 0x08050C74
	ldr r1, _08050C7C @ =0x03006D20
	movs r0, #0
	strb r0, [r1, #0xb]
	bx lr
	.align 2, 0
_08050C7C: .4byte 0x03006D20
	.syntax divided
