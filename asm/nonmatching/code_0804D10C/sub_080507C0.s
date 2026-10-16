	.syntax unified

	thumb_func_start sub_080507C0
sub_080507C0: @ 0x080507C0
	push {r4, lr}
	adds r4, r1, #0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	bl sub_0804DBA4
	adds r0, #0x4f
	adds r1, r4, #0
	bl sub_080507A0
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
