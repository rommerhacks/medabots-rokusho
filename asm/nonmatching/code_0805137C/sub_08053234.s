	.syntax unified

	thumb_func_start sub_08053234
	.global sub_08053234
sub_08053234: @ 0x08053234
	lsls r3, r0, #0x10
	lsrs r0, r3, #0x10
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _08053268
	ldr r0, _08053264 @ =0x030057D8
	ldr r2, [r0]
	lsrs r0, r3, #0x11
	adds r2, r2, r0
	ldrb r3, [r2]
	movs r0, #0x70
	ands r0, r3
	lsls r0, r0, #0x14
	movs r1, #0x80
	lsls r1, r1, #0x11
	adds r0, r0, r1
	movs r1, #0x8f
	ands r1, r3
	lsrs r0, r0, #0x14
	orrs r1, r0
	strb r1, [r2]
	b _08053280
	.align 2, 0
_08053264: .4byte 0x030057D8
_08053268:
	ldr r0, _08053284 @ =0x030057D8
	ldr r1, [r0]
	lsrs r0, r3, #0x11
	adds r1, r1, r0
	ldrb r2, [r1]
	movs r3, #7
	ands r3, r2
	adds r3, #1
	movs r0, #0xf8
	ands r0, r2
	orrs r3, r0
	strb r3, [r1]
_08053280:
	bx lr
	.align 2, 0
_08053284: .4byte 0x030057D8
	.syntax divided
