	.syntax unified

	thumb_func_start sub_08053154
	.global sub_08053154
sub_08053154: @ 0x08053154
	lsls r3, r0, #0x10
	lsrs r0, r3, #0x10
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _08053178
	ldr r0, _08053174 @ =0x030057D8
	ldr r2, [r0]
	lsrs r0, r3, #0x11
	adds r2, r2, r0
	ldrb r1, [r2]
	movs r0, #0x7f
	ands r0, r1
	movs r1, #0x80
	b _08053188
	.align 2, 0
_08053174: .4byte 0x030057D8
_08053178:
	ldr r0, _08053190 @ =0x030057D8
	ldr r2, [r0]
	lsrs r0, r3, #0x11
	adds r2, r2, r0
	ldrb r1, [r2]
	movs r0, #0xf7
	ands r0, r1
	movs r1, #8
_08053188:
	orrs r0, r1
	strb r0, [r2]
	bx lr
	.align 2, 0
_08053190: .4byte 0x030057D8
	.syntax divided
