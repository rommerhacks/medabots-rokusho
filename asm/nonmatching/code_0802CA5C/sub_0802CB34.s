	.syntax unified

	thumb_func_start sub_0802CB34
sub_0802CB34: @ 0x0802CB34
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	movs r4, #0
	ldr r6, _0802CBC8 @ =0x03001800
	ldr r7, _0802CBCC @ =0x03000590
	adds r5, r6, #0
	adds r5, #0x60
	movs r0, #0xec
	adds r0, r0, r6
	mov sl, r0
	mov sb, r4
_0802CB50:
	movs r1, #0xd2
	adds r1, r1, r6
	mov r8, r1
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802CBA8
	ldrb r0, [r5]
	adds r0, r0, r4
	lsls r0, r0, #8
	adds r0, r0, r7
	adds r0, #0xc4
	movs r1, #0x26
	strb r1, [r0]
	ldrb r0, [r5]
	adds r0, r0, r4
	lsls r0, r0, #8
	adds r0, r0, r7
	adds r0, #0xc5
	mov r2, sb
	strb r2, [r0]
	adds r0, r6, #0
	adds r0, #0xe8
	movs r1, #0
	ldrsh r0, [r0, r1]
	bl sub_08036E54
	ldrb r1, [r5]
	adds r1, r1, r4
	lsls r1, r1, #8
	adds r1, r1, r7
	adds r1, #0xc6
	strb r0, [r1]
	mov r2, sl
	movs r1, #0
	ldrsh r0, [r2, r1]
	bl sub_08036E54
	ldrb r1, [r5]
	adds r1, r1, r4
	lsls r1, r1, #8
	adds r1, r1, r7
	adds r1, #0xc7
	strb r0, [r1]
_0802CBA8:
	adds r4, #1
	cmp r4, #2
	bls _0802CB50
	mov r1, r8
	subs r1, #0x28
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802CBC8: .4byte 0x03001800
_0802CBCC: .4byte 0x03000590
_0802CBD0:
	.byte 0x04, 0x49, 0x0A, 0x1C, 0xA6, 0x32, 0x59, 0x20, 0x10, 0x70, 0xAA, 0x31, 0x08, 0x78, 0x01, 0x30
	.byte 0x08, 0x70, 0x70, 0x47, 0x00, 0x18, 0x00, 0x03
	.syntax divided
