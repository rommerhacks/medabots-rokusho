	.syntax unified

	thumb_func_start sub_0806B9D0
sub_0806B9D0: @ 0x0806B9D0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r7, _0806BA24 @ =0x03001800
	ldr r4, _0806BA28 @ =0x083F7FF4
	ldr r5, _0806BA2C @ =0x03001780
	ldr r0, [r5]
	adds r0, r0, r6
	movs r1, #0xff
	ands r0, r1
	adds r0, r0, r4
	ldrb r0, [r0]
	movs r1, #3
	bl sub_0807CDD0
	strb r0, [r7, #0xf]
	movs r6, #1
	movs r0, #0xc
	ldrsb r0, [r7, r0]
	ldr r1, _0806BA30 @ =0x0300137C
	mov r8, r1
	cmp r6, r0
	bge _0806BAA2
_0806B9FE:
	ldr r0, [r5]
	adds r0, r0, r6
	movs r1, #0xff
	ands r0, r1
	adds r0, r0, r4
	ldrb r0, [r0]
	movs r1, #7
	bl sub_0807CDD0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #6
	bhi _0806BA98
	lsls r0, r0, #2
	ldr r1, _0806BA34 @ =_0806BA38
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0806BA24: .4byte 0x03001800
_0806BA28: .4byte 0x083F7FF4
_0806BA2C: .4byte 0x03001780
_0806BA30: .4byte 0x0300137C
_0806BA34: .4byte _0806BA38
_0806BA38: @ jump table
	.4byte _0806BA54 @ case 0
	.4byte _0806BA64 @ case 1
	.4byte _0806BA64 @ case 2
	.4byte _0806BA64 @ case 3
	.4byte _0806BA7C @ case 4
	.4byte _0806BA7C @ case 5
	.4byte _0806BA7C @ case 6
_0806BA54:
	adds r1, r7, #0
	adds r1, #0xf
	adds r2, r6, r1
	subs r0, r6, #1
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r2]
	b _0806BA98
_0806BA64:
	adds r0, r7, #0
	adds r0, #0xf
	adds r3, r6, r0
	subs r1, r6, #1
	adds r1, r1, r0
	ldrb r2, [r1]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	beq _0806BA94
	subs r0, r2, #1
	b _0806BA96
_0806BA7C:
	adds r0, r7, #0
	adds r0, #0xf
	adds r3, r6, r0
	subs r1, r6, #1
	adds r1, r1, r0
	ldrb r2, [r1]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #2
	beq _0806BA94
	adds r0, r2, #1
	b _0806BA96
_0806BA94:
	movs r0, #1
_0806BA96:
	strb r0, [r3]
_0806BA98:
	adds r6, #1
	movs r0, #0xc
	ldrsb r0, [r7, r0]
	cmp r6, r0
	blt _0806B9FE
_0806BAA2:
	mov r1, r8
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.syntax divided
