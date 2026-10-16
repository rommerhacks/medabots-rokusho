	.syntax unified

	thumb_func_start blend_obj_palettes_to_color_0803F998
	.global blend_obj_palettes_to_color_0803F998
blend_obj_palettes_to_color_0803F998: @ 0x0803F998
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
	bls _0803F9BC
	movs r0, #0x20
	mov ip, r0
_0803F9BC:
	movs r0, #0x20
	mov r1, ip
	subs r5, r0, r1
	movs r1, #0
_0803F9C4:
	ldr r0, [sp, #4]
	ands r0, r2
	cmp r0, #0
	beq _0803FA4C
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
_0803FA02:
	ldr r1, [sp, #8]
	adds r0, r1, r4
	lsls r0, r0, #1
	ldr r1, _0803FA44 @ =0x0202FC00
	adds r3, r0, r1
	ldr r1, _0803FA48 @ =0x0202F800
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
	bls _0803FA02
	b _0803FA6E
	.align 2, 0
_0803FA44: .4byte 0x0202FC00
_0803FA48: .4byte 0x0202F800
_0803FA4C:
	movs r4, #0
	lsls r2, r2, #0x11
	str r2, [sp, #0xc]
	adds r3, r1, #1
	str r3, [sp, #0x10]
	lsls r0, r1, #5
	ldr r1, _0803FA94 @ =0x0202F800
	adds r2, r0, r1
	ldr r3, _0803FA98 @ =0x0202FC00
	adds r1, r0, r3
_0803FA60:
	ldrh r0, [r2]
	strh r0, [r1]
	adds r2, #2
	adds r1, #2
	adds r4, #1
	cmp r4, #0xf
	bls _0803FA60
_0803FA6E:
	ldr r0, [sp, #0xc]
	lsrs r2, r0, #0x10
	ldr r1, [sp, #0x10]
	cmp r1, #0xf
	bls _0803F9C4
	ldr r0, _0803FA98 @ =0x0202FC00
	ldr r1, _0803FA9C @ =0x05000200
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
_0803FA94: .4byte 0x0202F800
_0803FA98: .4byte 0x0202FC00
_0803FA9C: .4byte 0x05000200
	.syntax divided
