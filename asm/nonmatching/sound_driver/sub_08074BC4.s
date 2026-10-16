	.syntax unified

	thumb_func_start sub_08074BC4
	.global sub_08074BC4
sub_08074BC4: @ 0x08074BC4
	ldr r1, _08074BD0 @ =0x03007014
	ldr r1, [r1]
	ldr r2, _08074BD4 @ =0x0000068C
	adds r1, r1, r2
	str r0, [r1]
	bx lr
	.align 2, 0
_08074BD0: .4byte 0x03007014
_08074BD4: .4byte 0x0000068C
	.syntax divided
