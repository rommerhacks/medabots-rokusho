	.syntax unified

	thumb_func_start sub_08074900
	.global sub_08074900
sub_08074900: @ 0x08074900
	ldr r1, _08074910 @ =0x03007014
	ldr r1, [r1]
	movs r2, #0xd1
	lsls r2, r2, #3
	adds r1, r1, r2
	str r0, [r1]
	bx lr
	.align 2, 0
_08074910: .4byte 0x03007014
	.syntax divided
