	.syntax unified

	thumb_func_start sub_0801D5A8
sub_0801D5A8: @ 0x0801D5A8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r4, _0801D5D0 @ =0x03000590
	ldr r2, _0801D5D4 @ =0x03001800
	adds r0, r2, #0
	adds r0, #0x87
	ldrb r0, [r0]
	lsls r0, r0, #8
	adds r0, r0, r4
	adds r0, #0xc0
	ldrb r1, [r0]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _0801D5D8
	adds r1, r2, #0
	b _0801D68E
	.align 2, 0
_0801D5D0: .4byte 0x03000590
_0801D5D4: .4byte 0x03001800
_0801D5D8:
	adds r0, r2, #0
	adds r0, #0x88
	ldrb r0, [r0]
	bl sub_08032FC4
	mov sl, r0
	movs r0, #0
	mov r8, r0
	movs r1, #1
	add r1, sl
	mov ip, r1
	mov r0, sl
	lsls r1, r0, #8
	ldr r0, _0801D684 @ =0x03000590
	adds r0, #0xc9
	adds r2, r1, r0
	ldr r0, _0801D684 @ =0x03000590
	adds r0, #0xbd
	adds r7, r1, r0
	ldr r0, _0801D684 @ =0x03000590
	adds r0, #0x40
	adds r6, r1, r0
	adds r5, r1, #0
	movs r4, #0x80
	lsls r4, r4, #1
_0801D60A:
	mov r3, sl
	add r3, r8
	ldrb r0, [r6]
	ldr r1, _0801D688 @ =0x03001800
	mov sb, r1
	cmp r0, #0
	beq _0801D65A
	ldrb r1, [r7]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _0801D65A
	mov r0, sb
	adds r0, #0x88
	ldrb r0, [r0]
	cmp r0, r3
	beq _0801D65A
	ldrb r0, [r2]
	cmp r0, #0x2f
	beq _0801D65A
	ldrb r0, [r2, #0x15]
	subs r0, #1
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #3
	adds r1, r1, r5
	ldr r0, _0801D684 @ =0x03000590
	adds r1, r1, r0
	adds r1, #0x59
	ldrb r0, [r1]
	cmp r0, #0
	beq _0801D65A
	mov r0, sb
	adds r0, #0xde
	mov r1, ip
	strb r1, [r0]
	ldrb r0, [r2, #0x16]
	mov r1, sb
	adds r1, #0xdf
	strb r0, [r1]
_0801D65A:
	movs r0, #1
	add ip, r0
	adds r2, r2, r4
	adds r7, r7, r4
	adds r6, r6, r4
	adds r5, r5, r4
	add r8, r0
	mov r1, r8
	cmp r1, #2
	bls _0801D60A
	mov r0, sb
	adds r0, #0xde
	ldrb r0, [r0]
	cmp r0, #0
	beq _0801D68C
	mov r1, sb
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	b _0801D692
	.align 2, 0
_0801D684: .4byte 0x03000590
_0801D688: .4byte 0x03001800
_0801D68C:
	mov r1, sb
_0801D68E:
	adds r1, #0xb5
	movs r0, #1
_0801D692:
	strb r0, [r1]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
