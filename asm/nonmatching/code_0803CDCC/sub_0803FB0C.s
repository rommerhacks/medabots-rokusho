	.syntax unified

	thumb_func_start sub_0803FB0C
	.global sub_0803FB0C
sub_0803FB0C: @ 0x0803FB0C
	ldr r2, _0803FB38 @ =0x03000440
	movs r1, #0
	movs r0, #4
	strb r0, [r2, #4]
	movs r0, #0
	strh r1, [r2, #0xc]
	strb r0, [r2, #0x14]
	strb r0, [r2, #0x15]
	strb r0, [r2, #0x16]
	strb r0, [r2, #0x17]
	strb r0, [r2, #0x18]
	strb r0, [r2, #0x19]
	strb r0, [r2, #0x1a]
	strb r0, [r2, #0x1b]
	adds r1, r2, #0
	adds r1, #0x24
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
	adds r1, #2
	strb r0, [r1]
	bx lr
	.align 2, 0
_0803FB38: .4byte 0x03000440
	.syntax divided
