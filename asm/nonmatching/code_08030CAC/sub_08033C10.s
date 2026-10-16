	.syntax unified

	thumb_func_start sub_08033C10
sub_08033C10: @ 0x08033C10
	push {lr}
	bl sub_08038D30
	bl sub_08034F08
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
