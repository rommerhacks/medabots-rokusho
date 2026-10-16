	.syntax unified

	thumb_func_start sub_0802C4F8
sub_0802C4F8: @ 0x0802C4F8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r4, _0802C580 @ =0x03000440
	adds r4, #0x84
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	ldr r6, _0802C584 @ =0x03001800
	adds r0, r6, #0
	adds r0, #0x87
	ldrb r0, [r0]
	bl sub_08032FC4
	adds r1, r6, #0
	adds r1, #0x60
	strb r0, [r1]
	movs r5, #0
	adds r7, r6, #0
	mov r8, r1
_0802C520:
	adds r6, r7, #0
	adds r6, #0xd2
	adds r0, r5, r6
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802C53A
	mov r1, r8
	ldrb r0, [r1]
	adds r0, r0, r5
	ldrb r1, [r4]
	movs r2, #2
	bl sub_08037330
_0802C53A:
	adds r5, #1
	cmp r5, #2
	bls _0802C520
	ldr r0, _0802C580 @ =0x03000440
	adds r0, #0x84
	ldrb r0, [r0]
	cmp r0, #0x3c
	bne _0802C576
	movs r5, #0
	adds r7, r6, #0
	subs r7, #0xd2
	subs r6, #0x72
_0802C552:
	adds r4, r7, #0
	adds r4, #0xd2
	adds r0, r5, r4
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802C566
	ldrb r0, [r6]
	adds r0, r0, r5
	bl sub_080373D4
_0802C566:
	adds r5, #1
	cmp r5, #2
	bls _0802C552
	adds r1, r4, #0
	subs r1, #0x28
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0802C576:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802C580: .4byte 0x03000440
_0802C584: .4byte 0x03001800
	.syntax divided
