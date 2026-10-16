	.syntax unified

	thumb_func_start sub_0800EC20
sub_0800EC20: @ 0x0800EC20
	ldr r2, _0800EC40 @ =0x03000440
	adds r3, r2, #0
	adds r3, #0x3d
	ldrb r0, [r3]
	lsrs r0, r0, #2
	adds r1, r2, #0
	adds r1, #0x3f
	strb r0, [r1]
	ldrb r0, [r3]
	movs r1, #3
	ands r0, r1
	adds r1, r2, #0
	adds r1, #0x40
	strb r0, [r1]
	bx lr
	.align 2, 0
_0800EC40: .4byte 0x03000440
	.syntax divided
