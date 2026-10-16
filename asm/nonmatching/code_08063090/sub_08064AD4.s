	.syntax unified

	thumb_func_start sub_08064AD4
	.global sub_08064AD4
sub_08064AD4: @ 0x08064AD4
	ldr r1, _08064AE8 @ =0x0300178C
	movs r0, #2
	str r0, [r1]
	ldr r1, _08064AEC @ =0x03002B8C
	movs r0, #0x14
	str r0, [r1]
	ldr r1, _08064AF0 @ =0x0300137C
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_08064AE8: .4byte 0x0300178C
_08064AEC: .4byte 0x03002B8C
_08064AF0: .4byte 0x0300137C
	.syntax divided
