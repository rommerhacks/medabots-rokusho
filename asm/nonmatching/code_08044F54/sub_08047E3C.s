	.syntax unified

	thumb_func_start sub_08047E3C
	.global sub_08047E3C
sub_08047E3C: @ 0x08047E3C
	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl add_position_entry
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
