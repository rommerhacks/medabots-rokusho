	.syntax unified

	thumb_func_start sub_0803F624
	.global sub_0803F624
sub_0803F624: @ 0x0803F624
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	movs r3, #0
	cmp r3, r1
	bhs _0803F638
_0803F62E:
	strb r2, [r0]
	adds r0, #1
	adds r3, #1
	cmp r3, r1
	blo _0803F62E
_0803F638:
	bx lr
	.align 2, 0
	.syntax divided
