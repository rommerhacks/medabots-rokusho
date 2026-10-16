	.syntax unified

	thumb_func_start sub_0802DBD8
sub_0802DBD8: @ 0x0802DBD8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	movs r5, #0
	ldr r4, _0802DC58 @ =0x03001800
_0802DBE4:
	adds r2, r4, #0
	adds r2, #0xd2
	adds r0, r5, r2
	mov r8, r0
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802DC80
	ldr r7, _0802DC5C @ =0x03000590
	adds r6, r4, #0
	adds r6, #0x60
	ldrb r0, [r6]
	adds r0, r0, r5
	lsls r0, r0, #8
	adds r0, r0, r7
	adds r0, #0xc9
	movs r1, #0x2b
	strb r1, [r0]
	adds r0, r4, #0
	adds r0, #0xe8
	movs r1, #0
	ldrsh r0, [r0, r1]
	str r2, [sp]
	bl sub_08036E54
	ldrb r1, [r6]
	adds r1, r1, r5
	lsls r1, r1, #8
	adds r1, r1, r7
	adds r1, #0xcb
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0xec
	movs r1, #0
	ldrsh r0, [r0, r1]
	bl sub_08036E54
	ldrb r1, [r6]
	adds r1, r1, r5
	lsls r1, r1, #8
	adds r1, r1, r7
	adds r1, #0xcc
	strb r0, [r1]
	mov r1, r8
	ldrb r0, [r1]
	movs r1, #0x7f
	ands r1, r0
	ldr r2, [sp]
	cmp r1, #1
	beq _0802DC60
	cmp r1, #2
	beq _0802DC6E
	ldrb r0, [r6]
	adds r0, r0, r5
	lsls r0, r0, #8
	adds r0, r0, r7
	adds r0, #0xca
	movs r1, #1
	b _0802DC7A
	.align 2, 0
_0802DC58: .4byte 0x03001800
_0802DC5C: .4byte 0x03000590
_0802DC60:
	ldrb r0, [r6]
	adds r0, r0, r5
	lsls r0, r0, #8
	adds r0, r0, r7
	adds r0, #0xca
	movs r1, #2
	b _0802DC7A
_0802DC6E:
	ldrb r0, [r6]
	adds r0, r0, r5
	lsls r0, r0, #8
	adds r0, r0, r7
	adds r0, #0xca
	movs r1, #3
_0802DC7A:
	strb r1, [r0]
	adds r4, r2, #0
	subs r4, #0xd2
_0802DC80:
	adds r5, #1
	cmp r5, #2
	bls _0802DBE4
	adds r1, r4, #0
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_0802DC9C:
	.byte 0x04, 0x49, 0x0A, 0x1C
	.byte 0xA6, 0x32, 0x5E, 0x20, 0x10, 0x70, 0xAA, 0x31, 0x08, 0x78, 0x01, 0x30, 0x08, 0x70, 0x70, 0x47
	.byte 0x00, 0x18, 0x00, 0x03
	.syntax divided
