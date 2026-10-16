	.syntax unified

	thumb_func_start sub_080347AC
sub_080347AC: @ 0x080347AC
	push {lr}
	bl sub_08036270
	bl sub_08034F08
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
