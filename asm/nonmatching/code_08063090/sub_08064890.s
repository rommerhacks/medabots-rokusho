	.syntax unified

	thumb_func_start sub_08064890
sub_08064890: @ 0x08064890
	push {r4, r5, r6, r7, lr}
	movs r5, #0
	ldr r4, _080648FC @ =0x03006F74
	ldr r0, _08064900 @ =0x0300137C
	mov ip, r0
	movs r7, #0x80
	movs r6, #1
	ldr r2, _08064904 @ =0x03000BE0
	movs r3, #0x1d
_080648A2:
	ldrb r1, [r2]
	adds r0, r7, #0
	ands r0, r1
	cmp r0, #0
	beq _080648B4
	adds r0, r6, #0
	ldrb r1, [r2, #1]
	lsls r0, r1
	orrs r5, r0
_080648B4:
	adds r2, #0x40
	subs r3, #1
	cmp r3, #0
	bge _080648A2
	ldr r0, [r4]
	adds r0, #0x48
	movs r1, #0
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, #0x49
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, #0x4a
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, #0x4b
	strb r1, [r0]
	ldr r1, [r4]
	adds r0, r1, #0
	adds r0, #0x7a
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	movs r2, #0
	cmp r0, #0
	beq _080648EA
	adds r2, r5, #0
_080648EA:
	str r2, [r1, #0x1c]
	mov r1, ip
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080648FC: .4byte 0x03006F74
_08064900: .4byte 0x0300137C
_08064904: .4byte 0x03000BE0
	.syntax divided
