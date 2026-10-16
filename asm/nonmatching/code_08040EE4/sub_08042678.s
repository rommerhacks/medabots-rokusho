	.syntax unified

	thumb_func_start sub_08042678
	.global sub_08042678
sub_08042678: @ 0x08042678
	adds r2, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	movs r0, #0
	cmp r0, r1
	bhs _08042690
	movs r3, #0x43
_08042686:
	strb r3, [r2]
	adds r2, #1
	adds r0, #1
	cmp r0, r1
	blo _08042686
_08042690:
	movs r0, #0xfe
	strb r0, [r2]
	bx lr
	.align 2, 0
	.syntax divided
