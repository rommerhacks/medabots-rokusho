	.syntax unified

	thumb_func_start sub_0805BEA0
sub_0805BEA0: @ 0x0805BEA0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x4c
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #0x40]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	mov r8, r1
	movs r5, #0
_0805BEBA:
	lsls r4, r5, #6
	ldr r1, _0805BF7C @ =0x0202FA00
	adds r0, r4, r1
	mov r1, sp
	ldr r2, _0805BF80 @ =0x04000010
	bl CpuSet
	str r4, [sp, #0x44]
	adds r2, r5, #1
	str r2, [sp, #0x48]
	ldr r6, [sp, #0x40]
	cmp r5, r6
	bne _0805BF54
	movs r0, #0x1f
	mov ip, r0
	movs r1, #0x1f
	mov sl, r1
	mov r7, sp
	movs r2, #0xf
	mov sb, r2
_0805BEE2:
	ldrh r0, [r7]
	ldrh r1, [r7, #0x20]
	adds r6, r0, #0
	mov r2, sl
	ands r6, r2
	lsrs r5, r0, #5
	mov r2, ip
	ands r5, r2
	lsrs r3, r0, #0xa
	ands r3, r2
	adds r2, r1, #0
	mov r0, sl
	ands r2, r0
	lsrs r4, r1, #5
	mov r0, ip
	ands r4, r0
	lsrs r1, r1, #0xa
	ands r1, r0
	subs r0, r6, r2
	mov r6, r8
	muls r6, r0, r6
	adds r0, r6, #0
	cmp r0, #0
	bge _0805BF14
	adds r0, #0x1f
_0805BF14:
	asrs r0, r0, #5
	adds r6, r0, r2
	subs r0, r5, r4
	mov r2, r8
	muls r2, r0, r2
	adds r0, r2, #0
	cmp r0, #0
	bge _0805BF26
	adds r0, #0x1f
_0805BF26:
	asrs r0, r0, #5
	adds r5, r0, r4
	subs r0, r3, r1
	mov r2, r8
	muls r2, r0, r2
	adds r0, r2, #0
	cmp r0, #0
	bge _0805BF38
	adds r0, #0x1f
_0805BF38:
	asrs r0, r0, #5
	adds r3, r0, r1
	lsls r0, r3, #0xa
	lsls r1, r5, #5
	orrs r0, r1
	orrs r0, r6
	strh r0, [r7]
	adds r7, #2
	movs r6, #1
	rsbs r6, r6, #0
	add sb, r6
	mov r0, sb
	cmp r0, #0
	bge _0805BEE2
_0805BF54:
	ldr r2, [sp, #0x44]
	movs r6, #0xa0
	lsls r6, r6, #0x13
	adds r1, r2, r6
	mov r0, sp
	ldr r2, _0805BF84 @ =0x04000008
	bl CpuSet
	ldr r5, [sp, #0x48]
	cmp r5, #2
	ble _0805BEBA
	add sp, #0x4c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0805BF7C: .4byte 0x0202FA00
_0805BF80: .4byte 0x04000010
_0805BF84: .4byte 0x04000008
	.syntax divided
