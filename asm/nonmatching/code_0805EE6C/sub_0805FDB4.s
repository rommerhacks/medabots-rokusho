	.syntax unified

	thumb_func_start sub_0805FDB4
sub_0805FDB4: @ 0x0805FDB4
	push {r4, r5, r6, r7, lr}
	ldr r5, _0805FE38 @ =0x03002C30
	adds r7, r5, #0
	adds r7, #0x5a
	ldrh r6, [r7]
	movs r0, #4
	ands r0, r6
	movs r2, #0x85
	lsls r2, r2, #1
	adds r1, r2, #0
	cmp r0, #0
	beq _0805FDD0
	ldr r0, _0805FE3C @ =0x00000109
	adds r1, r0, #0
_0805FDD0:
	adds r4, r5, #0
	adds r4, #0x46
	movs r3, #0
	strh r1, [r4]
	lsls r0, r6, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x77
	bhi _0805FE40
	ldrh r1, [r7]
	movs r0, #0xa8
	muls r0, r1, r0
	movs r1, #0x78
	bl sub_0807CBBC
	subs r0, #0x40
	adds r1, r5, #0
	adds r1, #0x44
	strh r0, [r1]
	ldrh r0, [r7]
	lsls r0, r0, #6
	movs r1, #0x78
	bl sub_0807CBBC
	movs r1, #0x80
	rsbs r1, r1, #0
	adds r4, r1, #0
	subs r0, r4, r0
	adds r1, r5, #0
	adds r1, #0x48
	strb r0, [r1]
	ldrh r0, [r7]
	lsls r0, r0, #6
	movs r1, #0x78
	bl sub_0807CBBC
	subs r4, r4, r0
	adds r0, r5, #0
	adds r0, #0x49
	strb r4, [r0]
	movs r0, #0x3f
	ands r0, r6
	lsls r0, r0, #4
	movs r2, #0xd0
	lsls r2, r2, #2
	adds r0, r0, r2
	adds r1, r5, #0
	adds r1, #0x58
	strh r0, [r1]
	adds r0, r6, #1
	strh r0, [r7]
	b _0805FE7E
	.align 2, 0
_0805FE38: .4byte 0x03002C30
_0805FE3C: .4byte 0x00000109
_0805FE40:
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r0, [r2]
	movs r6, #0x80
	lsls r6, r6, #1
	adds r1, r6, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r0, _0805FE84 @ =0x0000010B
	strh r0, [r4]
	adds r0, r5, #0
	adds r0, #0x48
	movs r1, #0x40
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r1, r5, #0
	adds r1, #0x44
	movs r0, #0x68
	strh r0, [r1]
	adds r0, r5, #0
	adds r0, #0x58
	strh r3, [r0]
	strh r3, [r7]
	ldr r0, _0805FE88 @ =0x03006F74
	ldr r0, [r0]
	strh r3, [r0, #0x3a]
	ldr r1, _0805FE8C @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0805FE7E:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0805FE84: .4byte 0x0000010B
_0805FE88: .4byte 0x03006F74
_0805FE8C: .4byte 0x0300137C
	.syntax divided
