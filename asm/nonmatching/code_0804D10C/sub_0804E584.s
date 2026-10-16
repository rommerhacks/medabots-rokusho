	.syntax unified

	thumb_func_start sub_0804E584
sub_0804E584: @ 0x0804E584
	push {lr}
	movs r0, #0
	movs r1, #1
	bl sub_0804E5A4
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
