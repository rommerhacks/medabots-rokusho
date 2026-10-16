	.syntax unified

	thumb_func_start sub_08029354
sub_08029354: @ 0x08029354
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	movs r4, #0
	ldr r7, _08029384 @ =0x03001800
	ldr r6, _08029388 @ =0x03000590
	adds r5, r7, #0
	adds r5, #0x60
_08029364:
	adds r0, r7, #0
	adds r0, #0xd2
	adds r0, r4, r0
	ldrb r0, [r0]
	cmp r0, #0
	beq _08029444
	adds r0, r7, #0
	adds r0, #0x51
	ldrb r0, [r0]
	cmp r0, #1
	beq _080293BE
	cmp r0, #1
	bgt _0802938C
	cmp r0, #0
	beq _08029396
	b _08029444
	.align 2, 0
_08029384: .4byte 0x03001800
_08029388: .4byte 0x03000590
_0802938C:
	cmp r0, #2
	beq _080293E6
	cmp r0, #3
	beq _08029416
	b _08029444
_08029396:
	ldrb r0, [r5]
	adds r0, r0, r4
	lsls r0, r0, #8
	adds r0, r0, r6
	adds r0, #0xcf
	ldrb r1, [r0]
	movs r2, #1
	orrs r1, r2
	strb r1, [r0]
	ldrb r0, [r5]
	adds r1, r0, r4
	lsls r0, r1, #8
	adds r0, r0, r6
	adds r0, #0xc9
	ldrb r0, [r0]
	cmp r0, #0xd
	beq _0802940C
	cmp r0, #0xe
	bne _08029444
	b _0802940C
_080293BE:
	ldrb r0, [r5]
	adds r0, r0, r4
	lsls r0, r0, #8
	adds r0, r0, r6
	adds r0, #0xcf
	ldrb r1, [r0]
	movs r2, #8
	orrs r1, r2
	strb r1, [r0]
	ldrb r0, [r5]
	adds r1, r0, r4
	lsls r0, r1, #8
	adds r0, r0, r6
	adds r0, #0xc9
	ldrb r0, [r0]
	cmp r0, #0xf
	beq _0802940C
	cmp r0, #0x10
	bne _08029444
	b _0802940C
_080293E6:
	ldrb r0, [r5]
	adds r0, r0, r4
	lsls r0, r0, #8
	adds r0, r0, r6
	adds r0, #0xcf
	ldrb r1, [r0]
	movs r2, #2
	orrs r1, r2
	strb r1, [r0]
	ldrb r0, [r5]
	adds r1, r0, r4
	lsls r0, r1, #8
	adds r0, r0, r6
	adds r0, #0xc9
	ldrb r0, [r0]
	cmp r0, #0x11
	beq _0802940C
	cmp r0, #0x12
	bne _08029444
_0802940C:
	adds r0, r1, #0
	movs r1, #1
	bl sub_08038394
	b _08029444
_08029416:
	ldrb r0, [r5]
	adds r0, r0, r4
	lsls r0, r0, #8
	adds r0, r0, r6
	adds r0, #0xcf
	ldrb r1, [r0]
	movs r2, #4
	orrs r1, r2
	strb r1, [r0]
	ldrb r0, [r5]
	adds r1, r0, r4
	lsls r0, r1, #8
	adds r0, r0, r6
	adds r0, #0xc9
	ldrb r0, [r0]
	cmp r0, #0x13
	beq _0802943C
	cmp r0, #0x14
	bne _08029444
_0802943C:
	adds r0, r1, #0
	movs r1, #1
	bl sub_08038394
_08029444:
	adds r4, #1
	cmp r4, #2
	bls _08029364
	ldr r1, _08029460 @ =0x03001800
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
_08029460: .4byte 0x03001800
_08029464:
	.byte 0x05, 0x49, 0x08, 0x1C, 0x51, 0x30, 0x00, 0x78, 0x01, 0x28, 0x10, 0xD0
	.byte 0x01, 0x28, 0x05, 0xDC, 0x00, 0x28, 0x08, 0xD0, 0x17, 0xE0, 0x00, 0x00, 0x00, 0x18, 0x00, 0x03
	.byte 0x02, 0x28, 0x0A, 0xD0, 0x03, 0x28, 0x0C, 0xD0, 0x0F, 0xE0, 0x0A, 0x1C, 0xA6, 0x32, 0x55, 0x20
	.byte 0x0A, 0xE0, 0x0A, 0x1C, 0xA6, 0x32, 0x58, 0x20, 0x06, 0xE0, 0x0A, 0x1C, 0xA6, 0x32, 0x56, 0x20
	.byte 0x02, 0xE0, 0x0A, 0x1C, 0xA6, 0x32, 0x57, 0x20, 0x10, 0x70, 0xAA, 0x31, 0x08, 0x78, 0x01, 0x30
	.byte 0x08, 0x70, 0x70, 0x47
	.syntax divided
