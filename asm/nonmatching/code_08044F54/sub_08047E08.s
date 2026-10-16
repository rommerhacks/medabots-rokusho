	.syntax unified

	thumb_func_start sub_08047E08
	.global sub_08047E08
sub_08047E08: @ 0x08047E08
	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	bl reduce_medapart_stat
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
