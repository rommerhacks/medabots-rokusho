	.syntax unified

	thumb_func_start sub_08047BDC
	.global sub_08047BDC
sub_08047BDC: @ 0x08047BDC
	ldr r1, _08047BE8 @ =0x083BA4D8
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bx lr
	.align 2, 0
_08047BE8: .4byte 0x083BA4D8
	.syntax divided
