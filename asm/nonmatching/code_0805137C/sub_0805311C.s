	.syntax unified

	thumb_func_start sub_0805311C
	.global sub_0805311C
sub_0805311C: @ 0x0805311C
	lsls r2, r0, #0x10
	lsrs r0, r2, #0x10
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0805313C
	ldr r0, _08053138 @ =0x030057D8
	ldr r1, [r0]
	lsrs r0, r2, #0x11
	adds r1, r1, r0
	ldrb r2, [r1]
	movs r0, #0x7f
	b _08053148
	.align 2, 0
_08053138: .4byte 0x030057D8
_0805313C:
	ldr r0, _08053150 @ =0x030057D8
	ldr r1, [r0]
	lsrs r0, r2, #0x11
	adds r1, r1, r0
	ldrb r2, [r1]
	movs r0, #0xf7
_08053148:
	ands r0, r2
	strb r0, [r1]
	bx lr
	.align 2, 0
_08053150: .4byte 0x030057D8
	.syntax divided
