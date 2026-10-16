	.syntax unified

	thumb_func_start sub_0804A1C4
	.global sub_0804A1C4
sub_0804A1C4: @ 0x0804A1C4
	ldr r1, _0804A1D0 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	bx lr
	.align 2, 0
_0804A1D0: .4byte 0x0300137C
	.syntax divided
