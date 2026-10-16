	.syntax unified

	thumb_func_start sub_0806CFA4
sub_0806CFA4: @ 0x0806CFA4
	push {r4, r5, r6, lr}
	ldr r0, _0806CFC8 @ =0x03002C30
	ldrh r4, [r0, #0x1a]
	adds r1, r0, #0
	adds r1, #0x20
	ldrb r1, [r1]
	adds r5, r0, #0
	cmp r1, #1
	beq _0806CFB8
	b _0806D1F8
_0806CFB8:
	cmp r4, #0x2f
	ble _0806CFFA
	cmp r4, #0x3f
	bgt _0806CFCC
	ldrh r0, [r5, #4]
	adds r0, #6
	strh r0, [r5, #4]
	b _0806CFFA
	.align 2, 0
_0806CFC8: .4byte 0x03002C30
_0806CFCC:
	cmp r4, #0x5f
	bgt _0806CFFA
	movs r2, #0xf
	ands r2, r4
	adds r3, r5, #0
	adds r3, #0x21
	cmp r2, #0
	bne _0806CFE2
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
_0806CFE2:
	ldr r1, _0806D020 @ =0x08485E84
	lsls r0, r2, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldrb r1, [r3]
	bl sub_0807CBBC
	movs r1, #0x50
	subs r1, r1, r0
	strh r1, [r5, #4]
_0806CFFA:
	ldr r0, _0806D024 @ =0x03001800
	ldrb r0, [r0, #0xe]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x23
	bgt _0806D008
	b _0806D188
_0806D008:
	movs r0, #0x10
	ands r0, r4
	cmp r0, #0
	beq _0806D02C
	movs r0, #8
	ands r0, r4
	cmp r0, #0
	beq _0806D034
	ldr r0, _0806D028 @ =0x00000806
	adds r1, r5, r0
	movs r0, #0xa
	b _0806D032
	.align 2, 0
_0806D020: .4byte 0x08485E84
_0806D024: .4byte 0x03001800
_0806D028: .4byte 0x00000806
_0806D02C:
	ldr r2, _0806D050 @ =0x00000806
	adds r1, r5, r2
	movs r0, #8
_0806D032:
	strh r0, [r1]
_0806D034:
	movs r0, #0x20
	ands r0, r4
	cmp r0, #0
	beq _0806D0E0
	movs r0, #0x1f
	ands r0, r4
	cmp r0, #7
	bgt _0806D058
	ldr r1, _0806D054 @ =0x00000802
	adds r0, r5, r1
	ldrh r0, [r0]
	adds r0, #0x10
	b _0806D064
	.align 2, 0
_0806D050: .4byte 0x00000806
_0806D054: .4byte 0x00000802
_0806D058:
	cmp r0, #0x17
	ble _0806D074
	ldr r1, _0806D06C @ =0x00000802
	adds r0, r5, r1
	ldrh r0, [r0]
	subs r0, #0x10
_0806D064:
	ldr r2, _0806D070 @ =0x00000B82
	adds r1, r5, r2
	strh r0, [r1]
	b _0806D08E
	.align 2, 0
_0806D06C: .4byte 0x00000802
_0806D070: .4byte 0x00000B82
_0806D074:
	ldr r0, _0806D0C8 @ =0x00000802
	adds r2, r5, r0
	adds r0, r4, #0
	subs r0, #8
	lsls r0, r0, #1
	movs r1, #0x1f
	ands r0, r1
	subs r0, #0x10
	ldrh r1, [r2]
	subs r1, r1, r0
	ldr r2, _0806D0CC @ =0x00000B82
	adds r0, r5, r2
	strh r1, [r0]
_0806D08E:
	ldr r0, _0806D0D0 @ =0x00000B84
	adds r1, r5, r0
	movs r3, #0x12
	movs r0, #0x12
	strh r0, [r1]
	ldr r1, _0806D0C8 @ =0x00000802
	adds r2, r5, r1
	movs r1, #0x1f
	adds r0, r4, #0
	ands r0, r1
	subs r0, #0x10
	ldrh r2, [r2]
	adds r0, r0, r2
	ldr r2, _0806D0D4 @ =0x00000BC2
	adds r1, r5, r2
	strh r0, [r1]
	ldr r2, _0806D0D8 @ =0x08485E84
	lsls r0, r4, #1
	movs r1, #0x3f
	ands r0, r1
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x19
	subs r3, r3, r0
	ldr r1, _0806D0DC @ =0x00000BC4
	adds r0, r5, r1
	strh r3, [r0]
	b _0806D15E
	.align 2, 0
_0806D0C8: .4byte 0x00000802
_0806D0CC: .4byte 0x00000B82
_0806D0D0: .4byte 0x00000B84
_0806D0D4: .4byte 0x00000BC2
_0806D0D8: .4byte 0x08485E84
_0806D0DC: .4byte 0x00000BC4
_0806D0E0:
	ldr r2, _0806D120 @ =0x00000802
	adds r1, r5, r2
	movs r6, #0x1f
	adds r0, r4, #0
	ands r0, r6
	subs r0, #0x10
	ldrh r3, [r1]
	adds r0, r3, r0
	ldr r2, _0806D124 @ =0x00000B82
	adds r1, r5, r2
	strh r0, [r1]
	ldr r2, _0806D128 @ =0x08485E84
	lsls r0, r4, #1
	movs r1, #0x3f
	ands r0, r1
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x19
	movs r1, #0x12
	subs r1, r1, r0
	ldr r2, _0806D12C @ =0x00000B84
	adds r0, r5, r2
	strh r1, [r0]
	movs r0, #0x1f
	ands r0, r4
	cmp r0, #7
	bgt _0806D130
	adds r1, r3, #0
	adds r1, #0x10
	adds r2, #0x3e
	b _0806D13A
	.align 2, 0
_0806D120: .4byte 0x00000802
_0806D124: .4byte 0x00000B82
_0806D128: .4byte 0x08485E84
_0806D12C: .4byte 0x00000B84
_0806D130:
	cmp r0, #0x17
	ble _0806D144
	adds r1, r3, #0
	subs r1, #0x10
	ldr r2, _0806D140 @ =0x00000BC2
_0806D13A:
	adds r0, r5, r2
	strh r1, [r0]
	b _0806D156
	.align 2, 0
_0806D140: .4byte 0x00000BC2
_0806D144:
	adds r0, r4, #0
	subs r0, #8
	lsls r0, r0, #1
	ands r0, r6
	subs r0, #0x10
	subs r0, r3, r0
	ldr r2, _0806D178 @ =0x00000BC2
	adds r1, r5, r2
	strh r0, [r1]
_0806D156:
	ldr r0, _0806D17C @ =0x00000BC4
	adds r1, r5, r0
	movs r0, #0x12
	strh r0, [r1]
_0806D15E:
	ldr r1, _0806D180 @ =0x00000B82
	adds r0, r5, r1
	ldrh r1, [r0]
	ldr r2, _0806D184 @ =0x00000D82
	adds r0, r5, r2
	strh r1, [r0]
	ldr r1, _0806D178 @ =0x00000BC2
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r2, #0x40
	adds r0, r5, r2
	strh r1, [r0]
	b _0806D1F8
	.align 2, 0
_0806D178: .4byte 0x00000BC2
_0806D17C: .4byte 0x00000BC4
_0806D180: .4byte 0x00000B82
_0806D184: .4byte 0x00000D82
_0806D188:
	cmp r0, #0
	ble _0806D1D8
	movs r0, #0x10
	ands r0, r4
	cmp r0, #0
	beq _0806D1B6
	ldr r1, _0806D1CC @ =0x08485E84
	movs r0, #0xf
	ands r0, r4
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bge _0806D1AA
	adds r0, #3
_0806D1AA:
	asrs r0, r0, #2
	movs r1, #0x10
	subs r1, r1, r0
	ldr r2, _0806D1D0 @ =0x00000804
	adds r0, r5, r2
	strh r1, [r0]
_0806D1B6:
	adds r1, r5, #0
	movs r0, #0x10
	ands r0, r4
	cmp r0, #0
	bne _0806D1D4
	movs r0, #8
	ands r4, r0
	movs r3, #7
	cmp r4, #0
	beq _0806D1F2
	b _0806D1F0
	.align 2, 0
_0806D1CC: .4byte 0x08485E84
_0806D1D0: .4byte 0x00000804
_0806D1D4:
	movs r3, #9
	b _0806D1F2
_0806D1D8:
	adds r1, r5, #0
	movs r0, #8
	ands r0, r4
	cmp r0, #0
	bne _0806D1F0
	movs r0, #0x10
	ands r4, r0
	movs r3, #0xc
	cmp r4, #0
	beq _0806D1F2
	movs r3, #0xa
	b _0806D1F2
_0806D1F0:
	movs r3, #8
_0806D1F2:
	ldr r2, _0806D200 @ =0x00000806
	adds r0, r1, r2
	strh r3, [r0]
_0806D1F8:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0806D200: .4byte 0x00000806
	.syntax divided
