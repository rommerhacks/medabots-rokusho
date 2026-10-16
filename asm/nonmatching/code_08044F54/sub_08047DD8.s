	.syntax unified

	thumb_func_start sub_08047DD8
	.global sub_08047DD8
sub_08047DD8: @ 0x08047DD8
	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	cmp r1, #0
	bne _08047DE8
	movs r1, #1
_08047DE8:
	bl sub_08042318
	pop {r0}
	bx r0
	.syntax divided
