	.syntax unified

	thumb_func_start sub_080356B4
	.global sub_080356B4
sub_080356B4: @ 0x080356B4
	ldr r1, _080356C4 @ =0x03002C30
	lsls r0, r0, #6
	adds r0, r0, r1
	ldrh r2, [r0]
	ldr r1, _080356C8 @ =0x0000FDFF
	ands r1, r2
	strh r1, [r0]
	bx lr
	.align 2, 0
_080356C4: .4byte 0x03002C30
_080356C8: .4byte 0x0000FDFF
	.syntax divided
