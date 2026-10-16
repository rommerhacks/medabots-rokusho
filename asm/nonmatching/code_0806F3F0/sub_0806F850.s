	.syntax unified

	thumb_func_start sub_0806F850
	.global sub_0806F850
sub_0806F850: @ 0x0806F850
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x28
	movs r0, #0
	mov sb, r0
	ldr r0, _0806F8C0 @ =0x03001800
	ldr r4, [r0, #8]
	adds r6, r0, #0
	cmp r4, #0
	bne _0806F8DC
	ldr r1, _0806F8C4 @ =0x040000D4
	ldr r0, _0806F8C8 @ =0x05000280
	str r0, [r1]
	adds r0, r6, #0
	adds r0, #0xe
	str r0, [r1, #4]
	ldr r0, _0806F8CC @ =0x80000010
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	mov r0, sp
	adds r0, #0x1e
_0806F880:
	mov r1, sb
	strh r1, [r0]
	subs r0, #2
	cmp r0, sp
	bge _0806F880
	ldr r1, _0806F8C4 @ =0x040000D4
	mov r2, sp
	str r2, [r1]
	ldr r0, _0806F8C8 @ =0x05000280
	str r0, [r1, #4]
	ldr r0, _0806F8D0 @ =0x84000008
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r2, _0806F8D4 @ =0x04000050
	ldrh r1, [r2]
	ldr r0, _0806F8D8 @ =0x0000FFEF
	ands r0, r1
	strh r0, [r2]
	subs r2, #0x50
	ldrh r0, [r2]
	movs r3, #0xd8
	lsls r3, r3, #5
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldrh r0, [r6, #6]
	cmp r0, #0
	bne _0806F9AC
	movs r0, #1
	strh r0, [r6, #6]
	b _0806F9AC
	.align 2, 0
_0806F8C0: .4byte 0x03001800
_0806F8C4: .4byte 0x040000D4
_0806F8C8: .4byte 0x05000280
_0806F8CC: .4byte 0x80000010
_0806F8D0: .4byte 0x84000008
_0806F8D4: .4byte 0x04000050
_0806F8D8: .4byte 0x0000FFEF
_0806F8DC:
	ldrh r5, [r6, #6]
	lsls r0, r5, #5
	cmp r4, r0
	bne _0806F90C
	mov r7, sb
	str r7, [r6, #8]
	ldr r1, _0806F900 @ =0x040000D4
	adds r0, r6, #0
	adds r0, #0xe
	str r0, [r1]
	ldr r0, _0806F904 @ =0x05000280
	str r0, [r1, #4]
	ldr r0, _0806F908 @ =0x80000010
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r0, #1
	b _0806F9B4
	.align 2, 0
_0806F900: .4byte 0x040000D4
_0806F904: .4byte 0x05000280
_0806F908: .4byte 0x80000010
_0806F90C:
	adds r0, r4, #0
	adds r1, r5, #0
	bl sub_0807CC88
	cmp r0, #0
	bne _0806F9AC
	adds r0, r4, #0
	adds r1, r5, #0
	bl sub_0807CBBC
	adds r3, r0, #0
	movs r0, #0x20
	subs r0, r0, r3
	str r0, [sp, #0x20]
	movs r0, #0x1f
	mov sl, r0
	movs r1, #0xf8
	lsls r1, r1, #2
	mov r8, r1
	adds r2, r6, #0
	adds r2, #0xe
	str r2, [sp, #0x24]
	mov r4, sp
	movs r7, #0xf8
	lsls r7, r7, #7
	mov ip, r7
	movs r5, #0xf
_0806F942:
	ldr r0, [sp, #0x24]
	ldrh r2, [r0]
	mov r0, sl
	ands r0, r2
	adds r1, r0, #0
	muls r1, r3, r1
	asrs r1, r1, #5
	mov r0, r8
	ands r0, r2
	muls r0, r3, r0
	asrs r0, r0, #5
	mov r7, r8
	ands r0, r7
	adds r1, r1, r0
	mov r0, ip
	ands r0, r2
	muls r0, r3, r0
	asrs r0, r0, #5
	mov r2, ip
	ands r0, r2
	adds r1, r1, r0
	strh r1, [r4]
	ldr r7, [sp, #0x24]
	adds r7, #2
	str r7, [sp, #0x24]
	adds r4, #2
	subs r5, #1
	cmp r5, #0
	bge _0806F942
	ldr r1, _0806F9C4 @ =0x040000D4
	mov r0, sp
	str r0, [r1]
	ldr r0, _0806F9C8 @ =0x05000280
	str r0, [r1, #4]
	ldr r0, _0806F9CC @ =0x84000008
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldrh r7, [r6, #6]
	lsls r1, r7, #1
	ldr r5, [r6, #8]
	adds r0, r5, #0
	bl sub_0807CC88
	cmp r0, #0
	bne _0806F9AC
	ldr r4, _0806F9D0 @ =0x04000054
	lsls r1, r7, #2
	adds r0, r5, #0
	bl sub_0807CBBC
	movs r1, #0x10
	subs r1, r1, r0
	strh r1, [r4]
_0806F9AC:
	ldr r0, [r6, #8]
	adds r0, #1
	str r0, [r6, #8]
	movs r0, #0
_0806F9B4:
	add sp, #0x28
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0806F9C4: .4byte 0x040000D4
_0806F9C8: .4byte 0x05000280
_0806F9CC: .4byte 0x84000008
_0806F9D0: .4byte 0x04000054
	.syntax divided
