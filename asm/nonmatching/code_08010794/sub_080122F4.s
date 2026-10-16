	.syntax unified

	thumb_func_start sub_080122F4
sub_080122F4: @ 0x080122F4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	mov r8, r0
	ldr r4, _08012364 @ =0x083ACEF0
	bl rng_next_080424B8
	movs r1, #0xf
	ands r1, r0
	adds r1, r1, r4
	ldrb r4, [r1]
	bl rng_next_080424B8
	adds r1, r0, #0
	movs r0, #1
	ands r1, r0
	movs r2, #0
	ldr r3, _08012368 @ =0x03000590
	ldr r7, _0801236C @ =0x03001800
	ldr r0, _08012370 @ =0x00000187
	adds r0, r0, r7
	mov sb, r0
_08012324:
	mov r0, r8
	adds r6, r0, r4
	lsls r5, r6, #8
	adds r0, r5, r3
	adds r0, #0xba
	ldrb r0, [r0]
	cmp r0, #0
	beq _08012374
	str r3, [sp]
	bl rng_next_080424B8
	movs r1, #3
	ands r0, r1
	movs r2, #0xb4
	lsls r2, r2, #1
	adds r1, r7, r2
	strb r0, [r1]
	ldrb r1, [r1]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r5
	ldr r3, [sp]
	adds r0, r0, r3
	adds r0, #0x5f
	ldrb r0, [r0]
	adds r2, #1
	adds r1, r7, r2
	strb r0, [r1]
	mov r0, sb
	strb r6, [r0]
	b _08012392
	.align 2, 0
_08012364: .4byte 0x083ACEF0
_08012368: .4byte 0x03000590
_0801236C: .4byte 0x03001800
_08012370: .4byte 0x00000187
_08012374:
	cmp r1, #0
	beq _08012382
	adds r4, #1
	cmp r4, #2
	bls _0801238C
	movs r4, #0
	b _0801238C
_08012382:
	cmp r4, #0
	bne _0801238A
	movs r4, #2
	b _0801238C
_0801238A:
	subs r4, #1
_0801238C:
	adds r2, #1
	cmp r2, #2
	bls _08012324
_08012392:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.syntax divided
