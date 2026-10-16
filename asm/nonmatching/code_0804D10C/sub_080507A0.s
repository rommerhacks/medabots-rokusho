	.syntax unified

	thumb_func_start sub_080507A0
sub_080507A0: @ 0x080507A0
	ldr r2, _080507B8 @ =0x03002C30
	lsls r0, r0, #6
	adds r0, r0, r2
	ldrh r3, [r0, #0x32]
	ldr r2, _080507BC @ =0x0000F3FF
	ands r2, r3
	lsls r1, r1, #0xa
	orrs r2, r1
	strh r2, [r0]
	strh r2, [r0, #0x32]
	bx lr
	.align 2, 0
_080507B8: .4byte 0x03002C30
_080507BC: .4byte 0x0000F3FF
	.syntax divided
