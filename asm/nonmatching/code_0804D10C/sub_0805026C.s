	.syntax unified

	thumb_func_start sub_0805026C
sub_0805026C: @ 0x0805026C
	adds r1, r0, #0
	lsls r1, r1, #0x18
	movs r0, #0xc0
	lsls r0, r0, #0x12
	ands r0, r1
	lsrs r0, r0, #0x18
	bx lr
	.align 2, 0
	.syntax divided
