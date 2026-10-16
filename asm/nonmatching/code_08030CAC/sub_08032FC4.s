	.syntax unified

	thumb_func_start sub_08032FC4
	.global sub_08032FC4
sub_08032FC4: @ 0x08032FC4
	cmp r0, #2
	bls _08032FCC
	movs r0, #3
	b _08032FCE
_08032FCC:
	movs r0, #0
_08032FCE:
	bx lr
	.syntax divided
