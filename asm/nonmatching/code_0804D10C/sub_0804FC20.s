	.syntax unified

	thumb_func_start sub_0804FC20
sub_0804FC20: @ 0x0804FC20
	push {lr}
	movs r0, #0
	movs r1, #0
	bl sub_0804E5A4
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
