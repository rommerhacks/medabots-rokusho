	.syntax unified

	thumb_func_start set_display_digit_type
	.global set_display_digit_type
set_display_digit_type: @ 0x0801A28C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r7, r0, #0
	mov r8, r1
	cmp r2, #0
	beq _0801A2A8
	cmp r2, #1
	bne _0801A2A4
	movs r0, #0xb
	b _0801A2AA
_0801A2A4:
	movs r6, #0
	b _0801A2AE
_0801A2A8:
	movs r0, #0xa
_0801A2AA:
	strb r0, [r7]
	movs r6, #1
_0801A2AE:
	mov r4, sp
	movs r5, #0x64
	mov r0, r8
	movs r1, #0x64
	bl sub_0807CD58
	strb r0, [r4]
	muls r0, r5, r0
	mov r1, r8
	subs r0, r1, r0
	str r0, [sp, #4]
	mov r4, sp
	ldr r0, [sp, #4]
	movs r1, #0xa
	bl sub_0807CD58
	strb r0, [r4, #1]
	ldr r0, [sp, #4]
	movs r1, #0xa
	bl sub_0807CD58
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #1
	ldr r0, [sp, #4]
	subs r0, r0, r1
	str r0, [sp, #4]
	mov r1, sp
	ldr r0, [sp, #4]
	strb r0, [r1, #2]
	movs r3, #0
	movs r2, #0
_0801A2EE:
	cmp r2, #1
	bhi _0801A30E
	mov r4, sp
	adds r0, r4, r2
	ldrb r1, [r0]
	cmp r1, #0
	bne _0801A306
	cmp r3, #0
	beq _0801A31E
	adds r0, r7, r6
	strb r1, [r0]
	b _0801A318
_0801A306:
	adds r0, r7, r6
	strb r1, [r0]
	movs r3, #1
	b _0801A318
_0801A30E:
	adds r1, r7, r6
	mov r4, sp
	adds r0, r4, r2
	ldrb r0, [r0]
	strb r0, [r1]
_0801A318:
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
_0801A31E:
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #2
	bls _0801A2EE
	adds r1, r7, r6
	movs r0, #0xfe
	strb r0, [r1]
	strb r6, [r7, #6]
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.syntax divided
