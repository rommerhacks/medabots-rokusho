	.syntax unified

	thumb_func_start sub_08047DF0
	.global sub_08047DF0
sub_08047DF0: @ 0x08047DF0
	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	bl medapart_add_quantity
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
