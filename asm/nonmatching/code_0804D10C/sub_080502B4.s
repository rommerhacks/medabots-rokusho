	.syntax unified

	thumb_func_start sub_080502B4
	.global sub_080502B4
sub_080502B4: @ 0x080502B4
	lsls r0, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldr r2, _080502D0 @ =0x03002C30
	lsrs r0, r0, #0x12
	adds r0, r0, r2
	adds r0, #0x2b
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r1, #0
	bx lr
	.align 2, 0
_080502D0: .4byte 0x03002C30
	.syntax divided
