	.syntax unified

	thumb_func_start sub_08050770
sub_08050770: @ 0x08050770
	ldr r2, _0805077C @ =0x03002C30
	lsls r0, r0, #6
	adds r0, r0, r2
	strb r1, [r0, #0xb]
	bx lr
	.align 2, 0
_0805077C: .4byte 0x03002C30
	.syntax divided
