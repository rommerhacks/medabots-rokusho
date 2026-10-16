	.syntax unified

	thumb_func_start sub_08047D4C
	.global sub_08047D4C
sub_08047D4C: @ 0x08047D4C
	ldr r0, _08047D54 @ =0x03002B70
	ldr r0, [r0]
	bx lr
	.align 2, 0
_08047D54: .4byte 0x03002B70
	.syntax divided
