	.syntax unified

	thumb_func_start divide_by_100000_08041370
	.global divide_by_100000_08041370
divide_by_100000_08041370: @ 0x08041370
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r7, r0, #0
	adds r5, r1, #0
	mov r6, sp
	ldr r4, _08041438 @ =0x000186A0
	adds r0, r5, #0
	adds r1, r4, #0
	bl sub_0807CD58
	strb r0, [r6]
	muls r0, r4, r0
	subs r0, r5, r0
	str r0, [sp, #8]
	mov r6, sp
	ldr r0, [sp, #8]
	ldr r4, _0804143C @ =0x00002710
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
	beq _08041440
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
	b _08041488
	.align 2, 0
_08041438: .4byte 0x000186A0
_0804143C: .4byte 0x00002710
_08041440:
	movs r4, #0
	movs r2, #0
	movs r3, #0
_08041446:
	cmp r3, #4
	bhi _08041466
	mov r1, sp
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _0804145C
	cmp r4, #0
	beq _08041478
	adds r1, r7, r2
	b _0804146E
_0804145C:
	adds r1, r7, r2
	adds r0, #0x35
	strb r0, [r1]
	movs r4, #1
	b _08041472
_08041466:
	adds r1, r7, r2
	mov r5, sp
	adds r0, r5, r3
	ldrb r0, [r0]
_0804146E:
	adds r0, #0x35
	strb r0, [r1]
_08041472:
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
_08041478:
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #5
	bls _08041446
	adds r1, r7, r2
	movs r0, #0xfe
	strb r0, [r1]
_08041488:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.syntax divided
