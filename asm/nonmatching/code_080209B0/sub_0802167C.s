	.syntax unified

	thumb_func_start sub_0802167C
sub_0802167C: @ 0x0802167C
	push {r4, lr}
	ldr r1, _08021700 @ =0x03000440
	adds r3, r1, #0
	adds r3, #0x86
	ldrh r0, [r3]
	subs r0, #1
	strh r0, [r3]
	adds r0, r1, #0
	adds r0, #0x89
	ldrb r2, [r0]
	adds r4, r1, #0
	cmp r2, #0
	bne _080216A4
	ldr r0, _08021704 @ =0x03001798
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080216A4
	strh r2, [r3]
_080216A4:
	adds r0, r4, #0
	adds r0, #0x86
	ldrh r0, [r0]
	cmp r0, #0
	bne _08021728
	ldr r4, _08021708 @ =0x03003470
	adds r1, r4, #0
	adds r1, #0x40
	adds r0, r4, #0
	movs r2, #0x40
	bl memcpy_bytes_0803F63C
	adds r1, r4, #0
	adds r1, #0x80
	adds r0, r4, #0
	movs r2, #0x40
	bl memcpy_bytes_0803F63C
	movs r0, #0x58
	strh r0, [r4, #0x32]
	adds r0, r4, #0
	adds r0, #0x24
	movs r1, #6
	strb r1, [r0]
	adds r2, r4, #0
	adds r2, #0x72
	movs r0, #0x40
	strh r0, [r2]
	adds r0, r4, #0
	adds r0, #0x64
	strb r1, [r0]
	adds r2, #0x40
	movs r0, #0x28
	strh r0, [r2]
	adds r0, r4, #0
	adds r0, #0xa4
	strb r1, [r0]
	ldr r0, _0802170C @ =0x03001800
	adds r0, #0xf8
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _08021710
	movs r0, #0x88
	b _08021712
	.align 2, 0
_08021700: .4byte 0x03000440
_08021704: .4byte 0x03001798
_08021708: .4byte 0x03003470
_0802170C: .4byte 0x03001800
_08021710:
	movs r0, #0x68
_08021712:
	strh r0, [r4, #0x30]
	adds r1, r4, #0
	adds r1, #0x70
	strh r0, [r1]
	adds r1, #0x40
	strh r0, [r1]
	ldr r1, _08021730 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_08021728:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08021730: .4byte 0x03001800
	.syntax divided
