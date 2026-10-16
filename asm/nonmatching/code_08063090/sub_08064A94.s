	.syntax unified

	thumb_func_start sub_08064A94
	.global sub_08064A94
sub_08064A94: @ 0x08064A94
	ldr r1, _08064AA8 @ =0x0300178C
	movs r0, #2
	str r0, [r1]
	ldr r1, _08064AAC @ =0x03002B8C
	movs r0, #0x11
	str r0, [r1]
	ldr r1, _08064AB0 @ =0x0300137C
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_08064AA8: .4byte 0x0300178C
_08064AAC: .4byte 0x03002B8C
_08064AB0: .4byte 0x0300137C
	.syntax divided
