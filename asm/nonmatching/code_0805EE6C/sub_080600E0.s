	.syntax unified

	thumb_func_start sub_080600E0
sub_080600E0: @ 0x080600E0
	ldr r3, _08060110 @ =0x03002C30
	ldrh r0, [r3, #0x1a]
	adds r0, #1
	strh r0, [r3, #0x1a]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3f
	bls _080600F4
	movs r0, #0
	strh r0, [r3, #0x1a]
_080600F4:
	ldr r2, _08060114 @ =0x080AF980
	ldrh r0, [r3, #0x1a]
	lsrs r0, r0, #3
	movs r1, #7
	ands r0, r1
	adds r0, r0, r2
	ldrb r0, [r0]
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r2, #0
	adds r0, r0, r1
	strh r0, [r3, #6]
	bx lr
	.align 2, 0
_08060110: .4byte 0x03002C30
_08060114: .4byte 0x080AF980
	.syntax divided
