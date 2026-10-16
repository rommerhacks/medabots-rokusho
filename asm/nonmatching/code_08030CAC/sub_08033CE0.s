	.syntax unified

	thumb_func_start sub_08033CE0
sub_08033CE0: @ 0x08033CE0
	push {lr}
	bl sub_08039188
	bl sub_08034F08
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
