	.syntax unified

	thumb_func_start sub_08074E70
	.global sub_08074E70
sub_08074E70: @ 0x08074E70
	ldr r1, _08074E80 @ =0x03007014
	ldr r1, [r1]
	movs r2, #0xe5
	lsls r2, r2, #3
	adds r1, r1, r2
	str r0, [r1]
	bx lr
	.align 2, 0
_08074E80: .4byte 0x03007014
	.syntax divided
