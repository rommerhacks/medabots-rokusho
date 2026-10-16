	.syntax unified

	thumb_func_start sub_0806E8C8
sub_0806E8C8: @ 0x0806E8C8
	ldr r0, _0806E8F4 @ =0x03002B64
	ldrb r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _0806E8F0
	ldr r1, _0806E8F8 @ =0x03007008
	movs r0, #1
	strb r0, [r1]
	ldr r0, _0806E8FC @ =0x03000430
	movs r2, #0
	str r2, [r0]
	ldr r1, _0806E900 @ =0x0300178C
	movs r0, #3
	str r0, [r1]
	ldr r1, _0806E904 @ =0x03002B8C
	movs r0, #2
	str r0, [r1]
	ldr r0, _0806E908 @ =0x0300137C
	str r2, [r0]
_0806E8F0:
	bx lr
	.align 2, 0
_0806E8F4: .4byte 0x03002B64
_0806E8F8: .4byte 0x03007008
_0806E8FC: .4byte 0x03000430
_0806E900: .4byte 0x0300178C
_0806E904: .4byte 0x03002B8C
_0806E908: .4byte 0x0300137C
	.syntax divided
