	.syntax unified

	thumb_func_start sub_0802B184
sub_0802B184: @ 0x0802B184
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	movs r0, #0
	mov r8, r0
	bl sub_0803836C
	ldr r4, _0802B200 @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x87
	ldrb r0, [r0]
	bl sub_08032FB8
	adds r1, r4, #0
	adds r1, #0x60
	strb r0, [r1]
	movs r5, #0
	ldr r6, _0802B204 @ =0x03000590
	adds r7, r1, #0
_0802B1AA:
	ldrb r0, [r7]
	adds r2, r0, r5
	lsls r0, r2, #8
	adds r1, r0, r6
	adds r0, r1, #0
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802B226
	adds r0, r1, #0
	adds r0, #0x59
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802B226
	adds r0, r2, #0
	bl sub_080331F8
	cmp r0, #0
	beq _0802B226
	adds r0, r4, #0
	adds r0, #0x87
	ldrb r0, [r0]
	lsls r0, r0, #8
	adds r0, r0, r6
	adds r0, #0xa8
	ldrb r0, [r0]
	cmp r0, #0x1e
	bne _0802B208
	ldrb r0, [r7]
	adds r0, r0, r5
	lsls r0, r0, #8
	adds r0, r0, r6
	adds r0, #0x91
	ldrb r0, [r0]
	cmp r0, #0x64
	bne _0802B226
	adds r0, r4, #0
	adds r0, #0xd2
	adds r0, r5, r0
	movs r1, #1
	strb r1, [r0]
	mov r8, r1
	b _0802B226
	.align 2, 0
_0802B200: .4byte 0x03001800
_0802B204: .4byte 0x03000590
_0802B208:
	ldrb r0, [r7]
	adds r0, r0, r5
	lsls r0, r0, #8
	adds r0, r0, r6
	adds r0, #0x91
	ldrb r0, [r0]
	cmp r0, #0x6a
	bne _0802B226
	adds r0, r4, #0
	adds r0, #0xd2
	adds r0, r5, r0
	movs r1, #2
	strb r1, [r0]
	movs r0, #1
	mov r8, r0
_0802B226:
	adds r5, #1
	cmp r5, #2
	bls _0802B1AA
	mov r0, r8
	cmp r0, #0
	bne _0802B240
	ldr r1, _0802B23C @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	b _0802B248
	.align 2, 0
_0802B23C: .4byte 0x03001800
_0802B240:
	ldr r1, _0802B254 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #2
_0802B248:
	strb r0, [r1]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802B254: .4byte 0x03001800
	.syntax divided
