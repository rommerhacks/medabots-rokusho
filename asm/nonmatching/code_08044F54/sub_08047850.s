	.syntax unified

	thumb_func_start sub_08047850
	.global sub_08047850
sub_08047850: @ 0x08047850
	cmp r0, #3
	bgt _08047868
	cmp r0, #0
	blt _08047868
	ldr r0, _0804786C @ =0x0300178C
	movs r1, #1
	str r1, [r0]
	ldr r0, _08047870 @ =0x03002B8C
	str r1, [r0]
	ldr r1, _08047874 @ =0x0300137C
	movs r0, #5
	str r0, [r1]
_08047868:
	bx lr
	.align 2, 0
_0804786C: .4byte 0x0300178C
_08047870: .4byte 0x03002B8C
_08047874: .4byte 0x0300137C
	.syntax divided
