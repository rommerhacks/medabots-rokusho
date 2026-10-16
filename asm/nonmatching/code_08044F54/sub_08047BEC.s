	.syntax unified

	thumb_func_start sub_08047BEC
	.global sub_08047BEC
sub_08047BEC: @ 0x08047BEC
	ldr r2, _08047BFC @ =0x083BB9CC
	lsls r1, r1, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r0, [r1]
	bx lr
	.align 2, 0
_08047BFC: .4byte 0x083BB9CC
	.syntax divided
