	.syntax unified

	thumb_func_start sub_08049E88
	.global sub_08049E88
sub_08049E88: @ 0x08049E88
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl blend_obj_palettes_to_color_0803F998
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
