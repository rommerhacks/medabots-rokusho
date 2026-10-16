	.syntax unified

	thumb_func_start sub_0804E594
sub_0804E594: @ 0x0804E594
	push {lr}
	movs r0, #1
	movs r1, #1
	bl sub_0804E5A4
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
