	.syntax unified

	thumb_func_start sub_08049CB0
	.global sub_08049CB0
sub_08049CB0: @ 0x08049CB0
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl palette_blend_to_color_080013A8
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
