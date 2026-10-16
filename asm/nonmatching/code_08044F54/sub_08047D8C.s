	.syntax unified

	thumb_func_start sub_08047D8C
	.global sub_08047D8C
sub_08047D8C: @ 0x08047D8C
	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl get_item_quantity_by_id
	pop {r1}
	bx r1
	.align 2, 0
	.syntax divided
