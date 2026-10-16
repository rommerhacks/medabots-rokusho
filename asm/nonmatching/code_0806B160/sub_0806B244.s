	.syntax unified

	thumb_func_start sub_0806B244
sub_0806B244: @ 0x0806B244
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	ldr r1, _0806B270 @ =0x03002C30
	lsls r0, r7, #6
	adds r2, r0, r1
	ldrh r3, [r2, #0x1a]
	adds r4, r3, #0
	adds r4, #0x10
	movs r0, #0x3f
	ands r4, r0
	ldrh r6, [r2, #4]
	movs r5, #4
	ldrsh r0, [r2, r5]
	mov ip, r1
	cmp r0, #0x60
	ble _0806B274
	movs r0, #0xc8
	strh r0, [r2, #4]
	movs r0, #0
	b _0806B2E4
	.align 2, 0
_0806B270: .4byte 0x03002C30
_0806B274:
	movs r5, #1
	ands r3, r5
	cmp r3, #0
	beq _0806B280
	adds r0, r6, #1
	strh r0, [r2, #4]
_0806B280:
	movs r0, #0x10
	ands r4, r0
	cmp r4, #0
	beq _0806B2A0
	ldrh r1, [r2, #0x1a]
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	beq _0806B2BE
	adds r0, r7, #0
	ands r0, r5
	cmp r0, #0
	bne _0806B2B8
	ldrh r0, [r2, #2]
	subs r0, #1
	b _0806B2BC
_0806B2A0:
	ldrh r1, [r2, #0x1a]
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	beq _0806B2BE
	adds r0, r7, #0
	ands r0, r5
	cmp r0, #0
	beq _0806B2B8
	ldrh r0, [r2, #2]
	subs r0, #1
	b _0806B2BC
_0806B2B8:
	ldrh r0, [r2, #2]
	adds r0, #1
_0806B2BC:
	strh r0, [r2, #2]
_0806B2BE:
	lsls r0, r7, #6
	mov r1, ip
	adds r2, r0, r1
	ldrh r1, [r2, #0x1a]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _0806B2DA
	ldrh r1, [r2]
	movs r3, #0x80
	lsls r3, r3, #5
	adds r0, r3, #0
	orrs r0, r1
	b _0806B2E0
_0806B2DA:
	ldrh r1, [r2]
	ldr r0, _0806B2EC @ =0x0000EFFF
	ands r0, r1
_0806B2E0:
	strh r0, [r2]
	movs r0, #1
_0806B2E4:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0806B2EC: .4byte 0x0000EFFF
_0806B2F0:
	.byte 0x00, 0x06, 0x06, 0x49, 0x80, 0x0C, 0x40, 0x18, 0x01, 0x1C, 0x27, 0x31, 0x08, 0x78, 0x00, 0x28
	.byte 0x01, 0xD0, 0x01, 0x38, 0x08, 0x70, 0x01, 0x20, 0x70, 0x47, 0x00, 0x00, 0x30, 0x2C, 0x00, 0x03
	.syntax divided
