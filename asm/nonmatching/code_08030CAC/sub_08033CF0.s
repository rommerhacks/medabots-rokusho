	.syntax unified

	thumb_func_start sub_08033CF0
sub_08033CF0: @ 0x08033CF0
	push {lr}
	bl sub_080391C4
	bl sub_08034F08
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
