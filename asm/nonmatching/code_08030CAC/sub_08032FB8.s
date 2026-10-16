	.syntax unified

	thumb_func_start sub_08032FB8
	.global sub_08032FB8
sub_08032FB8: @ 0x08032FB8
	cmp r0, #2
	bls _08032FC0
	movs r0, #0
	b _08032FC2
_08032FC0:
	movs r0, #3
_08032FC2:
	bx lr
	.syntax divided
