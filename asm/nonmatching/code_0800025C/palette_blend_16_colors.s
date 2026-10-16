	.syntax unified

	thumb_func_start palette_blend_16_colors
palette_blend_16_colors: @ 0x0800147C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r4, r0, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	cmp r3, #0x20
	bls _08001494
	movs r3, #0x20
_08001494:
	movs r0, #0x20
	subs r6, r0, r3
	movs r0, #0
	mov ip, r0
	movs r5, #0x1f
	mov sl, r5
	adds r0, r2, #0
	ands r0, r5
	adds r5, r0, #0
	muls r5, r3, r5
	str r5, [sp]
	movs r0, #0xf8
	lsls r0, r0, #2
	mov r8, r0
	movs r7, #0xf8
	lsls r7, r7, #7
	adds r5, r4, #0
	adds r4, r1, #0
	adds r0, r2, #0
	mov r1, r8
	ands r0, r1
	adds r1, r0, #0
	muls r1, r3, r1
	mov sb, r1
	adds r0, r2, #0
	ands r0, r7
	adds r2, r3, #0
	muls r2, r0, r2
	str r2, [sp, #4]
_080014CE:
	ldrh r2, [r5]
	mov r0, sl
	ands r0, r2
	adds r1, r0, #0
	muls r1, r6, r1
	ldr r3, [sp]
	adds r1, r3, r1
	lsrs r1, r1, #5
	mov r0, r8
	ands r0, r2
	muls r0, r6, r0
	add r0, sb
	lsrs r0, r0, #5
	mov r3, r8
	ands r0, r3
	orrs r1, r0
	adds r0, r7, #0
	ands r0, r2
	muls r0, r6, r0
	ldr r2, [sp, #4]
	adds r0, r2, r0
	lsrs r0, r0, #5
	ands r0, r7
	orrs r1, r0
	strh r1, [r4]
	adds r5, #2
	adds r4, #2
	movs r3, #1
	add ip, r3
	mov r0, ip
	cmp r0, #0xf
	bls _080014CE
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
