	.syntax unified

	thumb_func_start sub_0804CFCC
sub_0804CFCC: @ 0x0804CFCC
	push {lr}
	bl sub_08044B58
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
