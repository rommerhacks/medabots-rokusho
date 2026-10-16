	.syntax unified

	thumb_func_start sub_08033D00
sub_08033D00: @ 0x08033D00
	push {lr}
	bl sub_080392D8
	bl sub_08034F08
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
