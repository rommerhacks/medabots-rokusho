	.syntax unified

	thumb_func_start sub_0805BDC8
sub_0805BDC8: @ 0x0805BDC8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	cmp r0, #0xf
	bls _0805BDE6
	subs r0, #0x10
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	b _0805BDE8
_0805BDE6:
	movs r0, #0
_0805BDE8:
	mov r8, r0
	ldr r0, _0805BE90 @ =0x0202FB00
	ldr r2, _0805BE94 @ =0x04000010
	mov r1, sp
	bl CpuSet
	movs r0, #0x1f
	mov ip, r0
	movs r2, #0x1f
	mov sl, r2
	mov r7, sp
	movs r6, #0xf
	mov sb, r6
_0805BE02:
	ldrh r0, [r7]
	ldrh r1, [r7, #0x20]
	adds r6, r0, #0
	mov r2, sl
	ands r6, r2
	lsrs r5, r0, #5
	mov r2, ip
	ands r5, r2
	lsrs r4, r0, #0xa
	ands r4, r2
	adds r2, r1, #0
	mov r0, sl
	ands r2, r0
	lsrs r3, r1, #5
	mov r0, ip
	ands r3, r0
	lsrs r1, r1, #0xa
	ands r1, r0
	subs r0, r6, r2
	mov r6, r8
	muls r6, r0, r6
	adds r0, r6, #0
	cmp r0, #0
	bge _0805BE34
	adds r0, #0x1f
_0805BE34:
	asrs r0, r0, #5
	adds r6, r0, r2
	subs r0, r5, r3
	mov r2, r8
	muls r2, r0, r2
	adds r0, r2, #0
	cmp r0, #0
	bge _0805BE46
	adds r0, #0x1f
_0805BE46:
	asrs r0, r0, #5
	adds r5, r0, r3
	subs r0, r4, r1
	mov r2, r8
	muls r2, r0, r2
	adds r0, r2, #0
	cmp r0, #0
	bge _0805BE58
	adds r0, #0x1f
_0805BE58:
	asrs r0, r0, #5
	adds r4, r0, r1
	lsls r0, r4, #0xa
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
	bge _0805BE02
	ldr r1, _0805BE98 @ =0x05000140
	ldr r2, _0805BE9C @ =0x04000008
	mov r0, sp
	bl CpuSet
	add sp, #0x40
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0805BE90: .4byte 0x0202FB00
_0805BE94: .4byte 0x04000010
_0805BE98: .4byte 0x05000140
_0805BE9C: .4byte 0x04000008
	.syntax divided
