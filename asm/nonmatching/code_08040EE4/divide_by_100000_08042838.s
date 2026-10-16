	.syntax unified

	thumb_func_start divide_by_100000_08042838
	.global divide_by_100000_08042838
divide_by_100000_08042838: @ 0x08042838
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	mov sb, r0
	str r1, [sp, #8]
	str r2, [sp, #0xc]
	mov sl, r3
	ldr r6, [sp, #0x30]
	ldr r0, [sp, #0x34]
	mov r1, sl
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	mov sl, r1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	mov r5, sp
	ldr r4, _08042918 @ =0x000186A0
	mov r0, sb
	adds r1, r4, #0
	bl sub_0807CD58
	strb r0, [r5]
	muls r4, r0, r4
	mov r2, sb
	subs r4, r2, r4
	mov r8, sp
	ldr r5, _0804291C @ =0x00002710
	adds r0, r4, #0
	adds r1, r5, #0
	bl sub_0807CD58
	mov r1, r8
	strb r0, [r1, #1]
	mov r0, sb
	adds r1, r5, #0
	bl sub_0807CD58
	muls r0, r5, r0
	subs r4, r4, r0
	mov r5, sp
	movs r1, #0xfa
	lsls r1, r1, #2
	adds r0, r4, #0
	bl sub_0807CD58
	strb r0, [r5, #2]
	lsls r1, r0, #5
	subs r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r0
	lsls r1, r1, #3
	subs r4, r4, r1
	mov r5, sp
	movs r2, #0x64
	mov r8, r2
	adds r0, r4, #0
	movs r1, #0x64
	bl sub_0807CD58
	strb r0, [r5, #3]
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	subs r4, r4, r0
	mov r5, sp
	adds r0, r4, #0
	movs r1, #0xa
	bl sub_0807CD58
	strb r0, [r5, #4]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #1
	subs r4, r4, r1
	mov r0, sp
	strb r4, [r0, #5]
	movs r1, #6
	mov r2, sl
	subs r1, r1, r2
	lsls r1, r1, #0x18
	movs r3, #0
	lsrs r6, r6, #8
	movs r0, #0x1f
	ands r6, r0
	lsls r6, r6, #0xb
	ldr r2, [sp, #8]
	lsls r0, r2, #1
	movs r2, #0xc0
	lsls r2, r2, #0x13
	adds r0, r0, r2
	adds r6, r6, r0
	ldr r0, [sp, #0xc]
	lsls r2, r0, #6
	adds r2, r6, r2
	lsrs r1, r1, #0x18
	cmp r1, #5
	bhi _0804293E
	add r1, sp
_08042902:
	add r0, sp, #4
	cmp r1, r0
	bhi _0804292C
	ldrb r0, [r1]
	cmp r0, #0
	bne _08042920
	cmp r3, #0
	bne _0804292E
	strh r3, [r2]
	b _08042932
	.align 2, 0
_08042918: .4byte 0x000186A0
_0804291C: .4byte 0x00002710
_08042920:
	ldrb r0, [r1]
	adds r0, r7, r0
	strh r0, [r2]
	adds r2, #2
	movs r3, #1
	b _08042934
_0804292C:
	ldrb r0, [r1]
_0804292E:
	adds r0, r7, r0
	strh r0, [r2]
_08042932:
	adds r2, #2
_08042934:
	adds r1, #1
	mov r0, sp
	adds r0, #5
	cmp r1, r0
	bls _08042902
_0804293E:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
