	.syntax unified

	thumb_func_start sub_08049CC0
	.global sub_08049CC0
sub_08049CC0: @ 0x08049CC0
	push {lr}
	bl copy_obj_palette_to_buffer
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
