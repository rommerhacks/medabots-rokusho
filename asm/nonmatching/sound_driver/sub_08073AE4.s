	.syntax unified

	thumb_func_start sub_08073AE4
	.global sub_08073AE4
sub_08073AE4: @ 0x08073AE4
	ldr r1, _08073AF4 @ =0x03007014
	ldr r1, [r1]
	movs r2, #0xe4
	lsls r2, r2, #3
	adds r1, r1, r2
	str r0, [r1]
	bx lr
	.align 2, 0
_08073AF4: .4byte 0x03007014
	.syntax divided
