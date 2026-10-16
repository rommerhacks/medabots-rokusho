	.syntax unified

	thumb_func_start sub_08064A74
	.global sub_08064A74
sub_08064A74: @ 0x08064A74
	ldr r1, _08064A88 @ =0x0300178C
	movs r0, #2
	str r0, [r1]
	ldr r1, _08064A8C @ =0x03002B8C
	movs r0, #0x1a
	str r0, [r1]
	ldr r1, _08064A90 @ =0x0300137C
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_08064A88: .4byte 0x0300178C
_08064A8C: .4byte 0x03002B8C
_08064A90: .4byte 0x0300137C
	.syntax divided
