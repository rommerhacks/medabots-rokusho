	.syntax unified

	thumb_func_start sub_0806DEE8
sub_0806DEE8: @ 0x0806DEE8
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	ldr r1, _0806DF2C @ =0x03002C30
	lsls r0, r6, #6
	adds r5, r0, r1
	ldrh r4, [r5, #0x32]
	ldrh r0, [r5, #0x1a]
	cmp r4, r0
	bhs _0806DF76
	adds r3, r5, #0
	adds r3, #0x22
	ldrb r2, [r3]
	cmp r2, #7
	bls _0806DF34
	movs r1, #0
	movs r4, #0
	movs r0, #0x96
	lsls r0, r0, #1
	strh r0, [r5, #2]
	strb r1, [r3]
	movs r0, #0
	bl rng_next_080012F0
	ldr r2, _0806DF30 @ =0x000001FF
	adds r1, r2, #0
	ands r0, r1
	adds r0, #0x20
	strh r0, [r5, #0x32]
	ldrh r0, [r5, #0x30]
	strh r0, [r5, #6]
	strh r4, [r5, #0x1a]
	b _0806DF76
	.align 2, 0
_0806DF2C: .4byte 0x03002C30
_0806DF30: .4byte 0x000001FF
_0806DF34:
	ldr r0, _0806DF4C @ =0x0300137C
	ldr r0, [r0]
	cmp r0, #9
	bne _0806DF54
	cmp r2, #0
	bne _0806DF54
	ldr r1, _0806DF50 @ =0x0000FFFF
	adds r0, r1, #0
	orrs r0, r4
	strh r0, [r5, #0x32]
	strh r2, [r5, #0x1a]
	b _0806DF76
	.align 2, 0
_0806DF4C: .4byte 0x0300137C
_0806DF50: .4byte 0x0000FFFF
_0806DF54:
	lsls r0, r6, #6
	adds r1, r0, r1
	adds r2, r1, #0
	adds r2, #0x22
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _0806DF72
	ldrh r0, [r1, #6]
	adds r0, #1
	strh r0, [r1, #6]
	b _0806DF76
_0806DF72:
	movs r0, #0x78
	strh r0, [r1, #2]
_0806DF76:
	movs r0, #1
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
	.syntax divided
