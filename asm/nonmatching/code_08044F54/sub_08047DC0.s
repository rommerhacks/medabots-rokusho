	.syntax unified

	thumb_func_start sub_08047DC0
	.global sub_08047DC0
sub_08047DC0: @ 0x08047DC0
	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	cmp r1, #0
	bne _08047DD0
	movs r1, #1
_08047DD0:
	bl sub_080422B8
	pop {r0}
	bx r0
	.syntax divided
