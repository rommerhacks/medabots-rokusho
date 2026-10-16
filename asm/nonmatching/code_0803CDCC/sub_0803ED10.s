	.syntax unified

	thumb_func_start sub_0803ED10
sub_0803ED10: @ 0x0803ED10
	ldr r1, _0803ED24 @ =0x03002C30
	adds r2, r1, #0
	adds r2, #0xa4
	movs r0, #0
	strb r0, [r2]
	adds r1, #0xa5
	movs r0, #1
	strb r0, [r1]
	bx lr
	.align 2, 0
_0803ED24: .4byte 0x03002C30
	.syntax divided
