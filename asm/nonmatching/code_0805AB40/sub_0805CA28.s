	.syntax unified

	thumb_func_start sub_0805CA28
sub_0805CA28: @ 0x0805CA28
	adds r3, r0, #0
	ldr r0, _0805CA58 @ =0x03006F74
	ldr r2, [r0]
	ldrb r0, [r2, #0x12]
	cmp r0, #0
	beq _0805CA88
	ldrb r0, [r2, #0x13]
	ldrb r1, [r2, #0x11]
	cmp r0, r1
	blo _0805CA78
	adds r1, r0, #0
	ldrb r0, [r2, #0x11]
	adds r0, #5
	cmp r1, r0
	bge _0805CA78
	movs r0, #1
	ands r0, r3
	cmp r0, #0
	beq _0805CA60
	ldr r0, _0805CA5C @ =0x03002C30
	movs r3, #0xa8
	lsls r3, r3, #5
	adds r0, r0, r3
	b _0805CA80
	.align 2, 0
_0805CA58: .4byte 0x03006F74
_0805CA5C: .4byte 0x03002C30
_0805CA60:
	ldr r0, _0805CA74 @ =0x03002C30
	movs r1, #0xa8
	lsls r1, r1, #5
	adds r0, r0, r1
	ldrh r2, [r0]
	movs r3, #0x80
	lsls r3, r3, #7
	adds r1, r3, #0
	orrs r1, r2
	b _0805CA86
	.align 2, 0
_0805CA74: .4byte 0x03002C30
_0805CA78:
	ldr r0, _0805CA8C @ =0x03002C30
	movs r1, #0xa8
	lsls r1, r1, #5
	adds r0, r0, r1
_0805CA80:
	ldrh r2, [r0]
	ldr r1, _0805CA90 @ =0x0000BFFF
	ands r1, r2
_0805CA86:
	strh r1, [r0]
_0805CA88:
	bx lr
	.align 2, 0
_0805CA8C: .4byte 0x03002C30
_0805CA90: .4byte 0x0000BFFF
	.syntax divided
