	.syntax unified

	thumb_func_start sub_0803E674
sub_0803E674: @ 0x0803E674
	push {lr}
	bl soft_reset_to_title
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
