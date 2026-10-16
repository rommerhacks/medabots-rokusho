	.syntax unified

	thumb_func_start sub_0802EFD0
sub_0802EFD0: @ 0x0802EFD0
	push {r4, r5, r6, r7, lr}
	movs r2, #0
	ldr r3, _0802F010 @ =0x03001800
	adds r7, r3, #0
	adds r7, #0xd2
	ldr r6, _0802F014 @ =0x03000590
	adds r5, r3, #0
	adds r5, #0x60
	movs r4, #8
_0802EFE2:
	adds r0, r2, r7
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802EFFA
	ldrb r0, [r5]
	adds r0, r0, r2
	lsls r0, r0, #8
	adds r0, r0, r6
	adds r0, #0xc0
	ldrb r1, [r0]
	orrs r1, r4
	strb r1, [r0]
_0802EFFA:
	adds r2, #1
	cmp r2, #2
	bls _0802EFE2
	adds r1, r3, #0
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802F010: .4byte 0x03001800
_0802F014: .4byte 0x03000590
_0802F018:
	.byte 0x04, 0x49, 0x0A, 0x1C, 0xA6, 0x32, 0x68, 0x20
	.byte 0x10, 0x70, 0xAA, 0x31, 0x08, 0x78, 0x01, 0x30, 0x08, 0x70, 0x70, 0x47, 0x00, 0x18, 0x00, 0x03
	.syntax divided
