	.syntax unified

	thumb_func_start u8_difference_divide
u8_difference_divide: @ 0x08066818
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	adds r7, r5, #0
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	adds r6, r4, #0
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	subs r0, r5, r4
	adds r1, r2, #0
	bl sub_0807CBBC
	cmp r0, #0
	beq _0806683A
	adds r0, r4, r0
	b _0806684C
_0806683A:
	cmp r5, r4
	bne _08066842
	adds r0, r4, #0
	b _08066850
_08066842:
	cmp r7, r4
	bls _0806684A
	adds r0, r4, #1
	b _0806684C
_0806684A:
	subs r0, r6, #1
_0806684C:
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
_08066850:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
	.syntax divided
