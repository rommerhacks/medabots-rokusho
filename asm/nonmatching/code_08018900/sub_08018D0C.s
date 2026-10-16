	.syntax unified

	thumb_func_start sub_08018D0C
sub_08018D0C: @ 0x08018D0C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	ldr r0, _08018D50 @ =0x03000590
	lsls r1, r4, #8
	adds r2, r1, r0
	adds r3, r2, #0
	adds r3, #0xc6
	ldrb r0, [r3]
	subs r0, #4
	cmp r0, #0
	bgt _08018D58
	adds r1, r2, #0
	adds r1, #0xc4
	movs r0, #0
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
	strb r0, [r3]
	adds r1, #2
	strb r0, [r1]
	adds r2, #0xce
	ldrb r0, [r2]
	movs r1, #1
	orrs r0, r1
	strb r0, [r2]
	ldr r1, _08018D54 @ =0x03001800
	adds r1, #0x55
	ldrb r2, [r1]
	movs r0, #2
	orrs r0, r2
	strb r0, [r1]
	b _08018DE0
	.align 2, 0
_08018D50: .4byte 0x03000590
_08018D54: .4byte 0x03001800
_08018D58:
	strb r0, [r3]
	adds r0, r2, #0
	adds r0, #0xc4
	ldrb r0, [r0]
	cmp r0, #0x1f
	bne _08018DE0
	ldr r1, _08018DEC @ =0x03001800
	adds r0, r2, #0
	adds r0, #0xc7
	ldrb r0, [r0]
	adds r2, r1, #0
	adds r2, #0x59
	strb r0, [r2]
	adds r1, #0x86
	movs r0, #0
	strb r0, [r1]
	movs r6, #0
	movs r5, #0
	mov r8, r2
	adds r7, r1, #0
_08018D80:
	adds r0, r4, #0
	bl sub_08018EE0
	cmp r0, #0
	beq _08018DB4
	subs r1, r0, #1
	mov r0, r8
	ldrb r2, [r0]
	adds r0, r4, #0
	bl add_part_stat_clamped
	ldrb r1, [r7]
	adds r1, r1, r0
	strb r1, [r7]
	movs r1, #0xff
	lsls r1, r1, #8
	ands r1, r0
	lsrs r1, r1, #8
	mov r0, r8
	strb r1, [r0]
	movs r6, #1
	cmp r1, #0
	beq _08018DB4
	adds r5, #1
	cmp r5, #3
	bls _08018D80
_08018DB4:
	cmp r6, #0
	beq _08018DE0
	ldr r0, _08018DF0 @ =0x03000590
	lsls r1, r4, #8
	adds r1, r1, r0
	ldr r3, _08018DEC @ =0x03001800
	adds r0, r3, #0
	adds r0, #0x86
	ldrb r2, [r0]
	adds r0, r1, #0
	adds r0, #0xc8
	strb r2, [r0]
	adds r1, #0xce
	ldrb r0, [r1]
	movs r2, #4
	orrs r0, r2
	strb r0, [r1]
	adds r3, #0x55
	ldrb r1, [r3]
	movs r0, #8
	orrs r0, r1
	strb r0, [r3]
_08018DE0:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08018DEC: .4byte 0x03001800
_08018DF0: .4byte 0x03000590
	.syntax divided
