	.syntax unified

	thumb_func_start sub_0801C524
sub_0801C524: @ 0x0801C524
	push {r4, r5, r6, r7, lr}
	ldr r5, _0801C59C @ =0x03000590
	ldr r4, _0801C5A0 @ =0x03001800
	adds r6, r4, #0
	adds r6, #0x87
	ldrb r2, [r6]
	lsls r0, r2, #8
	adds r0, r0, r5
	adds r0, #0xc0
	ldrb r1, [r0]
	movs r7, #2
	adds r0, r7, #0
	ands r0, r1
	cmp r0, #0
	beq _0801C544
	b _0801C650
_0801C544:
	adds r0, r2, #0
	bl sub_08034F44
	adds r3, r0, #0
	cmp r3, #0
	beq _0801C552
	b _0801C650
_0801C552:
	adds r0, r4, #0
	adds r0, #0x89
	ldrb r0, [r0]
	lsls r0, r0, #3
	adds r0, r0, r4
	adds r0, #0x2b
	ldrb r0, [r0]
	cmp r0, #0xa
	bne _0801C5A4
	ldrb r2, [r6]
	lsls r2, r2, #8
	adds r0, r2, r5
	adds r0, #0xdd
	ldrb r1, [r0]
	subs r1, #1
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r2
	adds r0, r0, r5
	adds r0, #0x4a
	ldrb r0, [r0]
	cmp r0, #0
	beq _0801C586
	cmp r0, #1
	bne _0801C650
_0801C586:
	adds r1, r4, #0
	adds r1, #0xa6
	movs r0, #0xe
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x51
	strb r3, [r0]
	adds r1, #4
	ldrb r0, [r1]
	adds r0, #1
	b _0801C656
	.align 2, 0
_0801C59C: .4byte 0x03000590
_0801C5A0: .4byte 0x03001800
_0801C5A4:
	cmp r0, #0xb
	bne _0801C5E0
	ldrb r2, [r6]
	lsls r2, r2, #8
	adds r0, r2, r5
	adds r0, #0xdd
	ldrb r1, [r0]
	subs r1, #1
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r2
	adds r0, r0, r5
	adds r0, #0x4a
	ldrb r0, [r0]
	cmp r0, #2
	beq _0801C5CA
	cmp r0, #3
	bne _0801C650
_0801C5CA:
	adds r1, r4, #0
	adds r1, #0xa6
	movs r0, #0xf
	strb r0, [r1]
	subs r1, #0x55
	movs r0, #1
	strb r0, [r1]
	adds r1, #0x59
	ldrb r0, [r1]
	adds r0, #1
	b _0801C656
_0801C5E0:
	cmp r0, #0xc
	bne _0801C618
	ldrb r2, [r6]
	lsls r2, r2, #8
	adds r0, r2, r5
	adds r0, #0xdd
	ldrb r1, [r0]
	subs r1, #1
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r2
	adds r0, r0, r5
	adds r0, #0x4a
	ldrb r0, [r0]
	cmp r0, #3
	bhi _0801C650
	adds r1, r4, #0
	adds r1, #0xa6
	movs r0, #0x10
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x51
	strb r7, [r0]
	adds r1, #4
	ldrb r0, [r1]
	adds r0, #1
	b _0801C656
_0801C618:
	cmp r0, #0x5a
	bne _0801C650
	ldrb r2, [r6]
	lsls r2, r2, #8
	adds r0, r2, r5
	adds r0, #0xdd
	ldrb r1, [r0]
	subs r1, #1
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r2
	adds r0, r0, r5
	adds r0, #0x4a
	ldrb r0, [r0]
	cmp r0, #3
	bhi _0801C650
	adds r1, r4, #0
	adds r1, #0xa6
	movs r0, #0x11
	strb r0, [r1]
	subs r1, #0x55
	movs r0, #3
	strb r0, [r1]
	adds r1, #0x59
	ldrb r0, [r1]
	adds r0, #1
	b _0801C656
_0801C650:
	adds r1, r4, #0
	adds r1, #0xaa
	movs r0, #0x2d
_0801C656:
	strb r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
