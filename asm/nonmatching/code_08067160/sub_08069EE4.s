	.syntax unified

	thumb_func_start sub_08069EE4
sub_08069EE4: @ 0x08069EE4
	adds r2, r0, #0
_08069EE6:
	ldrb r0, [r1]
	strb r0, [r2]
	adds r2, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r1, #1
	cmp r0, #0xf8
	bls _08069EE6
	bx lr
	.syntax divided
