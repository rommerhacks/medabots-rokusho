	.syntax unified

	thumb_func_start sub_08042318
	.global sub_08042318
sub_08042318: @ 0x08042318
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	lsls r0, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r7, r1, #0x18
	movs r1, #0xfc
	lsls r1, r1, #0x16
	ands r1, r0
	lsrs r1, r1, #0x18
	mov r8, r1
	movs r2, #0
	ldr r6, _08042388 @ =0x03002BA0
_08042332:
	lsls r3, r2, #1
	adds r4, r3, r6
	ldrb r1, [r4]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _08042390
	movs r0, #0x7f
	ands r0, r1
	cmp r0, r8
	bne _08042390
	adds r0, r3, #1
	adds r1, r0, r6
	ldrb r0, [r1]
	subs r0, r0, r7
	cmp r0, #0
	bgt _0804238C
	movs r0, #0
	strb r0, [r4]
	strb r0, [r1]
	adds r4, r2, #1
	lsls r0, r4, #1
	adds r0, r0, r6
	ldrb r0, [r0]
	cmp r0, #0
	beq _08042390
	ldr r5, _08042388 @ =0x03002BA0
_08042368:
	lsls r0, r2, #1
	adds r0, r0, r5
	lsls r1, r4, #1
	adds r1, r1, r5
	movs r2, #2
	bl memswap
	adds r2, r4, #0
	adds r4, r2, #1
	lsls r0, r4, #1
	adds r0, r0, r5
	ldrb r0, [r0]
	cmp r0, #0
	bne _08042368
	b _08042390
	.align 2, 0
_08042388: .4byte 0x03002BA0
_0804238C:
	strb r0, [r1]
	b _08042396
_08042390:
	adds r2, #1
	cmp r2, #0x3f
	bls _08042332
_08042396:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.syntax divided
