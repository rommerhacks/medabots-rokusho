	.syntax unified

	thumb_func_start sub_0806CDE8
sub_0806CDE8: @ 0x0806CDE8
	push {r4, r5, r6, lr}
	ldr r0, _0806CE0C @ =0x03002C30
	ldr r6, _0806CE10 @ =0x08485E84
	movs r1, #0xa0
	lsls r1, r1, #4
	adds r3, r0, r1
	adds r1, #0x20
	adds r5, r0, r1
	movs r4, #7
_0806CDFA:
	ldrb r0, [r5]
	cmp r0, #1
	blt _0806CE46
	cmp r0, #2
	ble _0806CE14
	cmp r0, #3
	beq _0806CE36
	b _0806CE46
	.align 2, 0
_0806CE0C: .4byte 0x03002C30
_0806CE10: .4byte 0x08485E84
_0806CE14:
	ldrh r2, [r3, #0x1a]
	movs r0, #8
	ands r0, r2
	movs r1, #0x11
	cmp r0, #0
	beq _0806CE22
	movs r1, #0x10
_0806CE22:
	strh r1, [r3, #6]
	movs r0, #0x3f
	ands r0, r2
	adds r0, r0, r6
	movs r1, #0
	ldrsb r1, [r0, r1]
	ldrh r0, [r3, #4]
	subs r0, r0, r1
	strh r0, [r3, #4]
	b _0806CE46
_0806CE36:
	ldrh r1, [r3, #0x1a]
	subs r0, r1, #1
	cmp r0, #0
	bge _0806CE40
	adds r0, r1, #2
_0806CE40:
	asrs r0, r0, #2
	adds r0, #0x13
	strh r0, [r3, #6]
_0806CE46:
	adds r3, #0x40
	adds r5, #0x40
	subs r4, #1
	cmp r4, #0
	bge _0806CDFA
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
