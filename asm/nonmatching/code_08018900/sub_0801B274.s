	.syntax unified

	thumb_func_start sub_0801B274
	.global sub_0801B274
sub_0801B274: @ 0x0801B274
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	mov sb, r0
	ldr r6, _0801B2B0 @ =0x03000590
	lsls r4, r0, #8
	adds r3, r4, r6
	adds r2, r3, #0
	adds r2, #0xbd
	ldrb r0, [r2]
	movs r1, #0xfe
	ands r1, r0
	movs r5, #0
	strb r1, [r2]
	adds r2, #0x20
	ldrb r0, [r2]
	adds r1, r3, #0
	adds r1, #0xde
	strb r0, [r1]
	ldrb r0, [r2]
	cmp r0, #0
	beq _0801B2A8
	cmp r0, #3
	bls _0801B2B4
_0801B2A8:
	adds r0, r3, #0
	adds r0, #0xdf
	strb r5, [r0]
	b _0801B2CC
	.align 2, 0
_0801B2B0: .4byte 0x03000590
_0801B2B4:
	ldrb r1, [r2]
	subs r1, #1
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r4
	adds r0, r0, r6
	adds r0, #0x49
	ldrb r1, [r0]
	adds r0, r3, #0
	adds r0, #0xdf
	strb r1, [r0]
_0801B2CC:
	movs r3, #0
	mov r0, sb
	lsls r1, r0, #8
	ldr r7, _0801B3A0 @ =0x030018A8
	add r6, sp, #4
	ldr r0, _0801B3A4 @ =0x03000590
	movs r2, #0
	adds r0, #0x56
	adds r1, r1, r0
_0801B2DE:
	strb r2, [r1]
	strb r2, [r1, #1]
	adds r1, #0x18
	adds r3, #1
	cmp r3, #3
	bls _0801B2DE
	movs r4, #0
	str r4, [sp]
	ldr r5, _0801B3A8 @ =0x05000008
	mov r0, sp
	adds r1, r7, #0
	adds r2, r5, #0
	bl CpuSet
	str r4, [sp, #4]
	adds r1, r7, #0
	adds r1, #0x20
	adds r0, r6, #0
	adds r2, r5, #0
	bl CpuSet
	movs r3, #0
	ldr r1, _0801B3A4 @ =0x03000590
	mov r8, r1
	mov r6, r8
	adds r6, #0xbd
	mov r5, r8
	adds r5, #0xde
	movs r0, #0x40
	add r0, r8
	mov ip, r0
	movs r7, #0x80
	lsls r7, r7, #1
_0801B320:
	lsls r4, r3, #8
	mov r1, ip
	ldrb r0, [r1]
	cmp r0, #0
	beq _0801B35C
	ldrb r2, [r6]
	movs r0, #0x18
	ands r0, r2
	cmp r0, #0
	beq _0801B35C
	ldrb r0, [r5]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bhi _0801B35C
	ldrb r0, [r5]
	subs r0, #1
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #3
	adds r1, r1, r4
	add r1, r8
	adds r1, #0x59
	ldrb r0, [r1]
	cmp r0, #0
	bne _0801B35C
	movs r0, #0xe7
	ands r0, r2
	strb r0, [r6]
_0801B35C:
	adds r6, r6, r7
	adds r5, r5, r7
	add ip, r7
	adds r3, #1
	cmp r3, #5
	bls _0801B320
	movs r3, #0
	ldr r0, _0801B3A4 @ =0x03000590
	movs r5, #0xf
	adds r2, r0, #0
	adds r2, #0xba
	movs r4, #0x80
	lsls r4, r4, #1
_0801B376:
	ldrb r0, [r2]
	cmp r0, #0
	beq _0801B384
	ldrb r1, [r2, #2]
	adds r0, r5, #0
	ands r0, r1
	strb r0, [r2, #2]
_0801B384:
	adds r2, r2, r4
	adds r3, #1
	cmp r3, #5
	bls _0801B376
	mov r0, sb
	bl sub_0801B3AC
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801B3A0: .4byte 0x030018A8
_0801B3A4: .4byte 0x03000590
_0801B3A8: .4byte 0x05000008
	.syntax divided
