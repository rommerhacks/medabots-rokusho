	.syntax unified

	thumb_func_start divide_by_10000_b
	.global divide_by_10000_b
divide_by_10000_b: @ 0x0804126C
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r7, r0, #0
	adds r4, r1, #0
	mov r6, sp
	ldr r5, _08041314 @ =0x00002710
	adds r0, r4, #0
	adds r1, r5, #0
	bl sub_0807CD58
	strb r0, [r6]
	muls r0, r5, r0
	subs r4, r4, r0
	str r4, [sp, #8]
	mov r5, sp
	ldr r0, [sp, #8]
	movs r4, #0xfa
	lsls r4, r4, #2
	adds r1, r4, #0
	bl sub_0807CD58
	strb r0, [r5, #1]
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
	strb r0, [r4, #2]
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
	strb r0, [r4, #3]
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
	strb r0, [r1, #4]
	movs r3, #0
	movs r5, #0
	movs r2, #0
	movs r4, #0
_080412FE:
	cmp r4, #0
	beq _0804135C
	cmp r4, #4
	bne _08041318
	adds r1, r7, r2
	movs r0, #0x40
	strb r0, [r1]
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	b _0804135C
	.align 2, 0
_08041314: .4byte 0x00002710
_08041318:
	cmp r4, #2
	bhi _08041338
	mov r1, sp
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _0804132E
	cmp r5, #0
	beq _0804134A
	adds r1, r7, r2
	b _08041340
_0804132E:
	adds r1, r7, r2
	adds r0, #0x35
	strb r0, [r1]
	movs r5, #1
	b _08041344
_08041338:
	adds r1, r7, r2
	mov r6, sp
	adds r0, r6, r3
	ldrb r0, [r0]
_08041340:
	adds r0, #0x35
	strb r0, [r1]
_08041344:
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
_0804134A:
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #5
	bne _0804135C
	adds r1, r7, r2
	movs r0, #0xfe
	strb r0, [r1]
	b _08041366
_0804135C:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #9
	bls _080412FE
_08041366:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
