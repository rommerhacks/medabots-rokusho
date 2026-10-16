	.syntax unified

	thumb_func_start sub_0805B470
sub_0805B470: @ 0x0805B470
	adds r3, r0, #0
	ldr r0, _0805B49C @ =0x03006F74
	ldr r2, [r0]
	ldrb r0, [r2, #0x12]
	cmp r0, #0
	beq _0805B4A8
	ldrb r0, [r2, #0x13]
	ldrb r1, [r2, #0x11]
	cmp r0, r1
	blo _0805B4A0
	adds r1, r0, #0
	ldrb r0, [r2, #0x11]
	adds r0, #5
	cmp r1, r0
	bge _0805B4A0
	ldrh r1, [r3]
	movs r2, #0x80
	lsls r2, r2, #7
	adds r0, r2, #0
	orrs r0, r1
	b _0805B4A6
	.align 2, 0
_0805B49C: .4byte 0x03006F74
_0805B4A0:
	ldrh r1, [r3]
	ldr r0, _0805B4AC @ =0x0000BFFF
	ands r0, r1
_0805B4A6:
	strh r0, [r3]
_0805B4A8:
	bx lr
	.align 2, 0
_0805B4AC: .4byte 0x0000BFFF
	.syntax divided
