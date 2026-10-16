	.syntax unified

	thumb_func_start sub_0802BC60
sub_0802BC60: @ 0x0802BC60
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	movs r4, #0
	ldr r7, _0802BC98 @ =0x03001800
	adds r5, r7, #0
	adds r5, #0x60
	ldr r0, _0802BC9C @ =0x030005D8
	mov r8, r0
	adds r6, r7, #0
	adds r6, #0xec
_0802BC76:
	adds r0, r7, #0
	adds r0, #0xd2
	adds r0, r4, r0
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802BCFC
	adds r0, r7, #0
	adds r0, #0x51
	ldrb r0, [r0]
	cmp r0, #1
	beq _0802BCB6
	cmp r0, #1
	bgt _0802BCA0
	cmp r0, #0
	beq _0802BCAA
	b _0802BCEC
	.align 2, 0
_0802BC98: .4byte 0x03001800
_0802BC9C: .4byte 0x030005D8
_0802BCA0:
	cmp r0, #2
	beq _0802BCC2
	cmp r0, #3
	beq _0802BCD8
	b _0802BCEC
_0802BCAA:
	ldrb r0, [r5]
	adds r0, r0, r4
	lsls r0, r0, #8
	add r0, r8
	adds r0, #0x4d
	b _0802BCCC
_0802BCB6:
	ldrb r0, [r5]
	adds r0, r0, r4
	lsls r0, r0, #8
	add r0, r8
	adds r0, #0x4e
	b _0802BCCC
_0802BCC2:
	ldrb r0, [r5]
	adds r0, r0, r4
	lsls r0, r0, #8
	add r0, r8
	adds r0, #0x50
_0802BCCC:
	movs r2, #0
	ldrsh r1, [r6, r2]
	movs r2, #0xff
	bl sub_08035740
	b _0802BCEC
_0802BCD8:
	ldrb r0, [r5]
	adds r0, r0, r4
	lsls r0, r0, #8
	add r0, r8
	adds r0, #0x51
	movs r2, #0
	ldrsh r1, [r6, r2]
	movs r2, #0xff
	bl sub_08035740
_0802BCEC:
	ldrb r0, [r5]
	adds r0, r0, r4
	bl sub_08035194
	ldrb r0, [r5]
	adds r0, r0, r4
	bl sub_080351E8
_0802BCFC:
	adds r4, #1
	cmp r4, #2
	bls _0802BC76
	ldr r1, _0802BD18 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802BD18: .4byte 0x03001800
_0802BD1C:
	.byte 0x05, 0x49, 0x08, 0x1C
	.byte 0x51, 0x30, 0x00, 0x78, 0x01, 0x28, 0x10, 0xD0, 0x01, 0x28, 0x05, 0xDC, 0x00, 0x28, 0x08, 0xD0
	.byte 0x17, 0xE0, 0x00, 0x00, 0x00, 0x18, 0x00, 0x03, 0x02, 0x28, 0x0A, 0xD0, 0x03, 0x28, 0x0C, 0xD0
	.byte 0x0F, 0xE0, 0x0A, 0x1C, 0xA6, 0x32, 0x3D, 0x20, 0x0A, 0xE0, 0x0A, 0x1C, 0xA6, 0x32, 0x3E, 0x20
	.byte 0x06, 0xE0, 0x0A, 0x1C, 0xA6, 0x32, 0x40, 0x20, 0x02, 0xE0, 0x0A, 0x1C, 0xA6, 0x32, 0x41, 0x20
	.byte 0x10, 0x70, 0xAA, 0x31, 0x08, 0x78, 0x01, 0x30, 0x08, 0x70, 0x70, 0x47
	.syntax divided
