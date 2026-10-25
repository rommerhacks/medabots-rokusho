	.syntax unified

	thumb_func_start sub_08012234
sub_08012234: @ 0x08012234
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	ldr r4, _080122B0 @ =0x083ACEF0
	bl rng_next_080424B8
	movs r1, #0xf
	ands r1, r0
	adds r1, r1, r4
	ldrb r6, [r1]
	movs r0, #0
	str r0, [sp]
_08012252:
	ldr r5, _080122B4 @ =0x03000590
	adds r0, r6, #3
	lsls r1, r0, #8
	adds r1, r1, r5
	adds r1, #0xba
	ldrb r1, [r1]
	mov sb, r0
	cmp r1, #0
	beq _080122CC
	bl rng_next_080424B8
	adds r4, r0, #0
	movs r0, #3
	ands r4, r0
	movs r7, #0
	adds r2, r5, #0
	ldr r1, _080122B8 @ =0x03001800
	mov r8, r1
	ldr r3, _080122BC @ =0x00000169
	add r3, r8
	mov sl, r3
_0801227C:
	lsls r0, r4, #1
	adds r0, r0, r4
	lsls r0, r0, #3
	mov r3, sb
	lsls r1, r3, #8
	adds r0, r0, r1
	adds r0, r0, r2
	adds r5, r0, #0
	adds r5, #0x5f
	ldrb r0, [r5]
	adds r1, r4, #0
	str r2, [sp, #4]
	bl sub_08042114
	ldr r2, [sp, #4]
	cmp r0, #0
	bne _080122C0
	movs r0, #0xb4
	lsls r0, r0, #1
	add r0, r8
	strb r4, [r0]
	ldrb r0, [r5]
	mov r1, sl
	strb r0, [r1]
	movs r0, #1
	b _080122E2
	.align 2, 0
_080122B0: .4byte gUnk_083ACEF0
_080122B4: .4byte 0x03000590
_080122B8: .4byte 0x03001800
_080122BC: .4byte 0x00000169
_080122C0:
	adds r4, #1
	movs r0, #3
	ands r4, r0
	adds r7, #1
	cmp r7, #3
	bls _0801227C
_080122CC:
	cmp r6, #2
	bne _080122D4
	movs r6, #0
	b _080122D6
_080122D4:
	adds r6, #1
_080122D6:
	ldr r3, [sp]
	adds r3, #1
	str r3, [sp]
	cmp r3, #2
	bls _08012252
	movs r0, #0
_080122E2:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
	.syntax divided
