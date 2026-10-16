	.syntax unified

	thumb_func_start sub_08047E20
	.global sub_08047E20
sub_08047E20: @ 0x08047E20
	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl load_palette_entry
	pop {r1}
	bx r1
	.align 2, 0
	.syntax divided
