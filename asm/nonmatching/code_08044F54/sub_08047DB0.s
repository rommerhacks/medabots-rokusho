	.syntax unified

	thumb_func_start sub_08047DB0
	.global sub_08047DB0
sub_08047DB0: @ 0x08047DB0
	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl find_medal_slot_by_id
	pop {r1}
	bx r1
	.align 2, 0
	.syntax divided
