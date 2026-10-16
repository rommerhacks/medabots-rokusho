	.syntax unified

	thumb_func_start sub_0806BE58
sub_0806BE58: @ 0x0806BE58
	ldr r0, _0806BE7C @ =0x03002B64
	ldrb r0, [r0, #1]
	movs r1, #3
	ands r1, r0
	cmp r1, #1
	bne _0806BE84
	ldr r1, _0806BE80 @ =0x03001800
	adds r2, r1, #0
	adds r2, #0x41
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #8
	ble _0806BECA
	movs r0, #8
	b _0806BEC8
	.align 2, 0
_0806BE7C: .4byte 0x03002B64
_0806BE80: .4byte 0x03001800
_0806BE84:
	cmp r1, #2
	bne _0806BEA8
	ldr r1, _0806BEA4 @ =0x03001800
	adds r2, r1, #0
	adds r2, #0x41
	ldrb r0, [r2]
	subs r0, #1
	strb r0, [r2]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	movs r3, #8
	rsbs r3, r3, #0
	cmp r0, r3
	bge _0806BECA
	strb r3, [r2]
	b _0806BECA
	.align 2, 0
_0806BEA4: .4byte 0x03001800
_0806BEA8:
	ldr r1, _0806BEE4 @ =0x03001800
	adds r2, r1, #0
	adds r2, #0x41
	ldrb r3, [r2]
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	ble _0806BEBC
	subs r0, r3, #1
	strb r0, [r2]
_0806BEBC:
	ldrb r3, [r2]
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	bge _0806BECA
	adds r0, r3, #1
_0806BEC8:
	strb r0, [r2]
_0806BECA:
	ldr r2, _0806BEE8 @ =0x03002C30
	adds r0, r1, #0
	adds r0, #0x41
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r0, r1, #1
	adds r0, r0, r1
	adds r0, #0x78
	ldr r1, _0806BEEC @ =0x00000782
	adds r2, r2, r1
	strh r0, [r2]
	bx lr
	.align 2, 0
_0806BEE4: .4byte 0x03001800
_0806BEE8: .4byte 0x03002C30
_0806BEEC: .4byte 0x00000782
	.syntax divided
