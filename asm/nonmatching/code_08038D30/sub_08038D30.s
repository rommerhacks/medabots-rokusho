	.syntax unified

	thumb_func_start sub_08038D30
	.global sub_08038D30
sub_08038D30: @ 0x08038D30
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r6, _08038DC0 @ =0x03000590
	ldr r3, _08038DC4 @ =0x03001800
	adds r7, r3, #0
	adds r7, #0x88
	ldrb r0, [r7]
	lsls r0, r0, #8
	adds r0, r0, r6
	adds r0, #0xbc
	ldrb r2, [r0]
	movs r1, #3
	mov r8, r1
	ands r1, r2
	movs r2, #0
	mov ip, r2
	strb r1, [r0]
	ldrb r0, [r7]
	lsls r0, r0, #8
	adds r0, r0, r6
	adds r0, #0xbd
	ldrb r1, [r0]
	movs r2, #2
	orrs r1, r2
	strb r1, [r0]
	adds r0, r3, #0
	adds r0, #0xde
	ldrb r0, [r0]
	adds r4, r3, #0
	cmp r0, #0
	beq _08038DC8
	ldrb r0, [r7]
	lsls r0, r0, #8
	adds r0, r0, r6
	adds r0, #0xbc
	ldrb r1, [r0]
	movs r2, #0xc
	orrs r1, r2
	strb r1, [r0]
	adds r0, r4, #0
	adds r0, #0xe8
	ldrh r0, [r0]
	adds r1, r4, #0
	adds r1, #0xf2
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0xab
	movs r5, #1
	strb r5, [r0]
	ldrb r0, [r7]
	lsls r0, r0, #8
	adds r0, r0, r6
	adds r0, #0xc0
	ldrb r1, [r0]
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	beq _08038E48
	bl rng_next_080424B8
	ands r0, r5
	cmp r0, #0
	beq _08038E48
	adds r0, r4, #0
	adds r0, #0xf6
	strb r5, [r0]
	subs r0, #0x3f
	mov r1, r8
	strb r1, [r0]
	b _08038E48
	.align 2, 0
_08038DC0: .4byte 0x03000590
_08038DC4: .4byte 0x03001800
_08038DC8:
	adds r5, r4, #0
	adds r5, #0x87
	ldrb r0, [r5]
	lsls r0, r0, #8
	adds r0, r0, r6
	adds r0, #0xc0
	ldrb r1, [r0]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	bne _08038E40
	ldrb r0, [r7]
	lsls r3, r0, #8
	adds r2, r3, r6
	adds r0, r2, #0
	adds r0, #0xbd
	ldrb r1, [r0]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08038E40
	adds r0, r2, #0
	adds r0, #0xde
	ldrb r0, [r0]
	subs r0, #1
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #3
	adds r1, r1, r3
	adds r1, r1, r6
	adds r1, #0x59
	ldrb r0, [r1]
	cmp r0, #0
	beq _08038E40
	adds r2, #0xbc
	ldrb r0, [r2]
	movs r1, #0xc
	orrs r0, r1
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0xe8
	ldrh r0, [r0]
	adds r1, r4, #0
	adds r1, #0xf2
	strh r0, [r1]
	ldrb r0, [r5]
	ldrb r1, [r7]
	lsls r1, r1, #8
	adds r1, r1, r6
	adds r1, #0xde
	ldrb r1, [r1]
	bl sub_08035944
	adds r0, r4, #0
	adds r0, #0xf6
	movs r1, #1
	strb r1, [r0]
	subs r0, #0x4b
	strb r1, [r0]
	b _08038E48
_08038E40:
	adds r1, r4, #0
	adds r1, #0xab
	movs r0, #0
	strb r0, [r1]
_08038E48:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
