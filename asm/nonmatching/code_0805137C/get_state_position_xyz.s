	.syntax unified

	thumb_func_start get_state_position_xyz
get_state_position_xyz: @ 0x08053770
	push {r4, lr}
	ldr r4, _08053788 @ =0x03005350
	ldr r3, [r4, #0x40]
	str r3, [r0]
	ldr r0, [r4, #0x44]
	str r0, [r1]
	ldr r0, [r4, #0x48]
	str r0, [r2]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08053788: .4byte 0x03005350
	.syntax divided
