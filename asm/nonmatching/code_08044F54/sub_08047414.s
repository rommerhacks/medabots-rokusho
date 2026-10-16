	.syntax unified

	thumb_func_start sub_08047414
	.global sub_08047414
sub_08047414: @ 0x08047414
	str r1, [r0]
	str r2, [r0, #4]
	str r3, [r0, #8]
	ldr r0, _08047424 @ =0x00001094
	adds r1, r1, r0
	movs r0, #0
	strb r0, [r1]
	bx lr
	.align 2, 0
_08047424: .4byte 0x00001094
	.syntax divided
