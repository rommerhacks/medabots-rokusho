	.syntax unified

	thumb_func_start sub_08047D74
	.global sub_08047D74
sub_08047D74: @ 0x08047D74
	ldr r2, _08047D84 @ =0x03002B70
	ldr r1, [r2]
	subs r1, r1, r0
	cmp r1, #0
	bge _08047D88
	movs r0, #0
	str r0, [r2]
	b _08047D8A
	.align 2, 0
_08047D84: .4byte 0x03002B70
_08047D88:
	str r1, [r2]
_08047D8A:
	bx lr
	.syntax divided
