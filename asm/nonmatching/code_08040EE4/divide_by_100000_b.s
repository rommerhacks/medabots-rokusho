	.syntax unified

	thumb_func_start divide_by_100000_b
	.global divide_by_100000_b
divide_by_100000_b: @ 0x08041490
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r7, r0, #0
	adds r5, r1, #0
	mov r8, r2
	mov r6, sp
	ldr r4, _08041560 @ =0x000186A0
	adds r0, r5, #0
	adds r1, r4, #0
	bl sub_0807CD58
	strb r0, [r6]
	muls r0, r4, r0
	subs r0, r5, r0
	str r0, [sp, #8]
	mov r6, sp
	ldr r0, [sp, #8]
	ldr r4, _08041564 @ =0x00002710
	adds r1, r4, #0
	bl sub_0807CD58
	strb r0, [r6, #1]
	adds r0, r5, #0
	adds r1, r4, #0
	bl sub_0807CD58
	adds r1, r0, #0
	muls r1, r4, r1
	ldr r0, [sp, #8]
	subs r0, r0, r1
	str r0, [sp, #8]
	mov r5, sp
	ldr r0, [sp, #8]
	movs r4, #0xfa
	lsls r4, r4, #2
	adds r1, r4, #0
	bl sub_0807CD58
	strb r0, [r5, #2]
	ldr r0, [sp, #8]
	adds r1, r4, #0
	bl sub_0807CD58
	lsls r1, r0, #5
	subs r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r0
	lsls r1, r1, #3
	ldr r0, [sp, #8]
	subs r0, r0, r1
	str r0, [sp, #8]
	mov r4, sp
	ldr r0, [sp, #8]
	movs r5, #0x64
	movs r1, #0x64
	bl sub_0807CD58
	strb r0, [r4, #3]
	ldr r0, [sp, #8]
	movs r1, #0x64
	bl sub_0807CD58
	adds r1, r0, #0
	muls r1, r5, r1
	ldr r0, [sp, #8]
	subs r0, r0, r1
	str r0, [sp, #8]
	mov r4, sp
	ldr r0, [sp, #8]
	movs r1, #0xa
	bl sub_0807CD58
	strb r0, [r4, #4]
	ldr r0, [sp, #8]
	movs r1, #0xa
	bl sub_0807CD58
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #1
	ldr r0, [sp, #8]
	subs r0, r0, r1
	str r0, [sp, #8]
	mov r1, sp
	ldr r0, [sp, #8]
	strb r0, [r1, #5]
	mov r0, sp
	ldrb r0, [r0]
	cmp r0, #0
	beq _08041568
	movs r0, #5
	strb r0, [r7]
	movs r1, #0x12
	strb r1, [r7, #1]
	strb r1, [r7, #2]
	movs r0, #0xf
	strb r0, [r7, #3]
	strb r1, [r7, #4]
	movs r0, #0xfe
	strb r0, [r7, #5]
	b _080415B0
	.align 2, 0
_08041560: .4byte 0x000186A0
_08041564: .4byte 0x00002710
_08041568:
	movs r4, #0
	movs r2, #0
	movs r3, #0
_0804156E:
	cmp r3, #4
	bhi _0804158E
	mov r1, sp
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _08041584
	cmp r4, #0
	beq _080415A0
	adds r1, r7, r2
	b _08041596
_08041584:
	adds r1, r7, r2
	add r0, r8
	strb r0, [r1]
	movs r4, #1
	b _0804159A
_0804158E:
	adds r1, r7, r2
	mov r5, sp
	adds r0, r5, r3
	ldrb r0, [r0]
_08041596:
	add r0, r8
	strb r0, [r1]
_0804159A:
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
_080415A0:
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #5
	bls _0804156E
	adds r1, r7, r2
	movs r0, #0xfe
	strb r0, [r1]
_080415B0:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.syntax divided
