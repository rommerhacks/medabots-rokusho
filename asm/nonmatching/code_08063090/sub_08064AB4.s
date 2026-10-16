	.syntax unified

	thumb_func_start sub_08064AB4
	.global sub_08064AB4
sub_08064AB4: @ 0x08064AB4
	ldr r1, _08064AC8 @ =0x0300178C
	movs r0, #2
	str r0, [r1]
	ldr r1, _08064ACC @ =0x03002B8C
	movs r0, #0x10
	str r0, [r1]
	ldr r1, _08064AD0 @ =0x0300137C
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_08064AC8: .4byte 0x0300178C
_08064ACC: .4byte 0x03002B8C
_08064AD0: .4byte 0x0300137C
	.syntax divided
