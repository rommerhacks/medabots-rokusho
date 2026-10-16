	.syntax unified

	thumb_func_start sub_08042950
	.global sub_08042950
sub_08042950: @ 0x08042950
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
	ldr r4, _08042A38 @ =0x000186A0
	mov r0, sb
	adds r1, r4, #0
	bl sub_0807CD58
	strb r0, [r5]
	muls r4, r0, r4
	mov r2, sb
	subs r4, r2, r4
	mov r8, sp
	ldr r5, _08042A3C @ =0x00002710
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
	movs r5, #0
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
	ldr r2, [sp, #0xc]
	lsls r0, r2, #6
	adds r2, r6, r0
	lsrs r1, r1, #0x18
	cmp r1, #5
	bhi _08042A7E
	lsls r0, r7, #0x10
	asrs r4, r0, #0x10
	add r1, sp
	adds r3, r2, #0
	adds r3, #0x40
_08042A22:
	add r0, sp, #4
	cmp r1, r0
	bhi _08042A5C
	ldrb r0, [r1]
	cmp r0, #0
	bne _08042A40
	cmp r5, #0
	bne _08042A5E
	strh r5, [r2]
	strh r5, [r3]
	b _08042A6E
	.align 2, 0
_08042A38: .4byte 0x000186A0
_08042A3C: .4byte 0x00002710
_08042A40:
	ldrb r0, [r1]
	lsls r0, r0, #1
	adds r0, r7, r0
	strh r0, [r2]
	ldrb r0, [r1]
	lsls r0, r0, #1
	adds r0, #1
	adds r0, r4, r0
	strh r0, [r3]
	ldrh r0, [r2]
	adds r3, #2
	adds r2, #2
	movs r5, #1
	b _08042A74
_08042A5C:
	ldrb r0, [r1]
_08042A5E:
	lsls r0, r0, #1
	adds r0, r7, r0
	strh r0, [r2]
	ldrb r0, [r1]
	lsls r0, r0, #1
	adds r0, #1
	adds r0, r4, r0
	strh r0, [r3]
_08042A6E:
	ldrh r0, [r2]
	adds r3, #2
	adds r2, #2
_08042A74:
	adds r1, #1
	mov r0, sp
	adds r0, #5
	cmp r1, r0
	bls _08042A22
_08042A7E:
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
