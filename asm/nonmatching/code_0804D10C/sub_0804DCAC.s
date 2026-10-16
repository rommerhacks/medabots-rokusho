	.syntax unified

	thumb_func_start sub_0804DCAC
sub_0804DCAC: @ 0x0804DCAC
	push {lr}
	bl sub_08050244
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
