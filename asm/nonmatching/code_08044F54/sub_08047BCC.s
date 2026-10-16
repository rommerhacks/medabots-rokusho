	.syntax unified

	thumb_func_start sub_08047BCC
	.global sub_08047BCC
sub_08047BCC: @ 0x08047BCC
	ldr r1, _08047BD8 @ =0x083B6410
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bx lr
	.align 2, 0
_08047BD8: .4byte 0x083B6410
	.syntax divided
