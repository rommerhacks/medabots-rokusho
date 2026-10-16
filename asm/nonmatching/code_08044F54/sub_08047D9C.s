	.syntax unified

	thumb_func_start sub_08047D9C
	.global sub_08047D9C
sub_08047D9C: @ 0x08047D9C
	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	bl sub_08042114
	pop {r1}
	bx r1
	.align 2, 0
	.syntax divided
