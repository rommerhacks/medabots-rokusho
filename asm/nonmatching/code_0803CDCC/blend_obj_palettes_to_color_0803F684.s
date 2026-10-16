	.syntax unified

	thumb_func_start blend_obj_palettes_to_color_0803F684
	.global blend_obj_palettes_to_color_0803F684
blend_obj_palettes_to_color_0803F684: @ 0x0803F684
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	mov ip, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r2, [sp, #4]
	movs r2, #1
	cmp r1, #0x20
	bls _0803F6A8
	movs r0, #0x20
	mov ip, r0
_0803F6A8:
	movs r0, #0x20
	mov r1, ip
	subs r5, r0, r1
	movs r1, #0
_0803F6B0:
	ldr r0, [sp, #4]
	ands r0, r2
	cmp r0, #0
	beq _0803F738
	movs r4, #0
	lsls r3, r1, #4
	str r3, [sp, #8]
	lsls r2, r2, #0x11
	str r2, [sp, #0xc]
	adds r1, #1
	str r1, [sp, #0x10]
	ldr r0, [sp]
	movs r1, #0x1f
	ands r0, r1
	mov r3, ip
	muls r3, r0, r3
	mov sl, r3
	movs r7, #0xf8
	lsls r7, r7, #2
	movs r6, #0xf8
	lsls r6, r6, #7
	ldr r0, [sp]
	ands r0, r7
	mov r1, ip
	muls r1, r0, r1
	mov sb, r1
	ldr r0, [sp]
	ands r0, r6
	mov r3, ip
	muls r3, r0, r3
	mov r8, r3
_0803F6EE:
	ldr r1, [sp, #8]
	adds r0, r1, r4
	lsls r0, r0, #1
	ldr r1, _0803F730 @ =0x0202FE00
	adds r3, r0, r1
	ldr r1, _0803F734 @ =0x0202FA00
	adds r0, r0, r1
	ldrh r2, [r0]
	movs r0, #0x1f
	ands r0, r2
	adds r1, r0, #0
	muls r1, r5, r1
	add r1, sl
	lsrs r1, r1, #5
	adds r0, r7, #0
	ands r0, r2
	muls r0, r5, r0
	add r0, sb
	lsrs r0, r0, #5
	ands r0, r7
	orrs r1, r0
	adds r0, r6, #0
	ands r0, r2
	muls r0, r5, r0
	add r0, r8
	lsrs r0, r0, #5
	ands r0, r6
	orrs r1, r0
	strh r1, [r3]
	adds r4, #1
	cmp r4, #0xf
	bls _0803F6EE
	b _0803F75A
	.align 2, 0
_0803F730: .4byte 0x0202FE00
_0803F734: .4byte 0x0202FA00
_0803F738:
	movs r4, #0
	lsls r2, r2, #0x11
	str r2, [sp, #0xc]
	adds r3, r1, #1
	str r3, [sp, #0x10]
	lsls r0, r1, #5
	ldr r1, _0803F780 @ =0x0202FA00
	adds r2, r0, r1
	ldr r3, _0803F784 @ =0x0202FE00
	adds r1, r0, r3
_0803F74C:
	ldrh r0, [r2]
	strh r0, [r1]
	adds r2, #2
	adds r1, #2
	adds r4, #1
	cmp r4, #0xf
	bls _0803F74C
_0803F75A:
	ldr r0, [sp, #0xc]
	lsrs r2, r0, #0x10
	ldr r1, [sp, #0x10]
	cmp r1, #0xf
	bls _0803F6B0
	ldr r0, _0803F784 @ =0x0202FE00
	movs r1, #0xa0
	lsls r1, r1, #0x13
	movs r2, #0x80
	bl CpuFastSet
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803F780: .4byte 0x0202FA00
_0803F784: .4byte 0x0202FE00
	.syntax divided
