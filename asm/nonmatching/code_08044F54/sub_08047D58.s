	.syntax unified

	thumb_func_start sub_08047D58
	.global sub_08047D58
sub_08047D58: @ 0x08047D58
	ldr r2, _08047D6C @ =0x03002B70
	ldr r1, [r2]
	adds r1, r1, r0
	str r1, [r2]
	ldr r0, _08047D70 @ =0x0001869F
	cmp r1, r0
	bls _08047D68
	str r0, [r2]
_08047D68:
	bx lr
	.align 2, 0
_08047D6C: .4byte 0x03002B70
_08047D70: .4byte 0x0001869F
	.syntax divided
