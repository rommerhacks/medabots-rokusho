	.syntax unified

	thumb_func_start sub_08042114
	.global sub_08042114
sub_08042114: @ 0x08042114
	lsls r0, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldr r3, _08042138 @ =0x03004C40
	lsls r2, r1, #4
	subs r2, r2, r1
	lsls r2, r2, #4
	lsrs r0, r0, #0x17
	adds r2, r2, r0
	adds r0, r2, r3
	ldrb r1, [r0]
	lsls r1, r1, #8
	adds r2, #1
	adds r2, r2, r3
	ldrb r0, [r2]
	orrs r0, r1
	bx lr
	.align 2, 0
_08042138: .4byte 0x03004C40
	.syntax divided
