	.syntax unified

	thumb_func_start sub_08033C00
sub_08033C00: @ 0x08033C00
	push {lr}
	bl sub_08038BC0
	bl sub_08034F08
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
