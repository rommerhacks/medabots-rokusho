	.syntax unified

	thumb_func_start divide_by_10000
	.global divide_by_10000
divide_by_10000: @ 0x08041164
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r7, r0, #0
	adds r4, r1, #0
	mov r6, sp
	ldr r5, _08041200 @ =0x00002710
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
_080411F6:
	cmp r4, #0
	bne _08041204
	adds r1, r7, r2
	movs r0, #0x4c
	b _0804120C
	.align 2, 0
_08041200: .4byte 0x00002710
_08041204:
	cmp r4, #4
	bne _08041216
	adds r1, r7, r2
	movs r0, #0x40
_0804120C:
	strb r0, [r1]
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	b _0804125A
_08041216:
	cmp r4, #2
	bhi _08041236
	mov r1, sp
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _0804122C
	cmp r5, #0
	beq _08041248
	adds r1, r7, r2
	b _0804123E
_0804122C:
	adds r1, r7, r2
	adds r0, #0x35
	strb r0, [r1]
	movs r5, #1
	b _08041242
_08041236:
	adds r1, r7, r2
	mov r6, sp
	adds r0, r6, r3
	ldrb r0, [r0]
_0804123E:
	adds r0, #0x35
	strb r0, [r1]
_08041242:
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
_08041248:
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #5
	bne _0804125A
	adds r1, r7, r2
	movs r0, #0xfe
	strb r0, [r1]
	b _08041264
_0804125A:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #9
	bls _080411F6
_08041264:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.syntax divided
