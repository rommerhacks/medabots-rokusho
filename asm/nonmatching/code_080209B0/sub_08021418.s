	.syntax unified

	thumb_func_start sub_08021418
sub_08021418: @ 0x08021418
	push {r4, r5, lr}
	ldr r4, _08021498 @ =0x03001800
	adds r5, r4, #0
	adds r5, #0x8a
	ldrb r0, [r5]
	lsls r0, r0, #3
	adds r1, r0, r4
	adds r0, r1, #0
	adds r0, #0x2a
	ldrb r0, [r0]
	cmp r0, #0
	beq _080214B2
	adds r0, r1, #0
	adds r0, #0x2b
	adds r1, r4, #0
	adds r1, #0x52
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bne _080214B2
	adds r1, r4, #0
	adds r1, #0x53
	movs r0, #1
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x51
	ldrb r0, [r0]
	cmp r0, #2
	beq _080214A0
	ldrb r0, [r5]
	lsls r0, r0, #3
	subs r1, #0x27
	adds r0, r0, r1
	adds r1, #0xbc
	ldrh r1, [r1]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x11
	movs r2, #0xff
	bl sub_08035740
	ldrb r0, [r5]
	lsls r0, r0, #3
	adds r1, r4, #0
	adds r1, #0x2d
	adds r0, r0, r1
	adds r3, r4, #0
	adds r3, #0xec
	ldr r1, _0802149C @ =0x03000590
	adds r2, r4, #0
	adds r2, #0x87
	ldrb r2, [r2]
	lsls r2, r2, #8
	adds r2, r2, r1
	adds r2, #0xd5
	movs r5, #0
	ldrsh r1, [r3, r5]
	ldrb r2, [r2]
	adds r1, r1, r2
	asrs r1, r1, #1
	movs r2, #0xff
	bl sub_08035740
	adds r1, r4, #0
	b _08021550
	.align 2, 0
_08021498: .4byte 0x03001800
_0802149C: .4byte 0x03000590
_080214A0:
	ldrb r0, [r5]
	lsls r0, r0, #3
	adds r0, r0, r4
	adds r0, #0x2c
	ldrb r1, [r0]
	adds r1, #1
	strb r1, [r0]
	adds r1, r4, #0
	b _08021550
_080214B2:
	ldr r5, _08021538 @ =0x03001800
	adds r0, r5, #0
	adds r0, #0x53
	movs r2, #0
	strb r2, [r0]
	adds r4, r5, #0
	adds r4, #0x8a
	ldrb r0, [r4]
	lsls r0, r0, #3
	adds r0, r0, r5
	adds r0, #0x2a
	movs r1, #1
	strb r1, [r0]
	ldrb r0, [r4]
	lsls r0, r0, #3
	adds r0, r0, r5
	adds r1, r5, #0
	adds r1, #0x52
	ldrb r1, [r1]
	adds r0, #0x2b
	strb r1, [r0]
	ldrb r0, [r4]
	lsls r0, r0, #3
	adds r0, r0, r5
	adds r0, #0x2c
	strb r2, [r0]
	ldrb r0, [r4]
	lsls r0, r0, #3
	adds r0, r0, r5
	adds r0, #0x2d
	strb r2, [r0]
	adds r0, r5, #0
	adds r0, #0x51
	ldrb r0, [r0]
	cmp r0, #2
	beq _08021540
	ldrb r0, [r4]
	lsls r0, r0, #3
	adds r1, r5, #0
	adds r1, #0x2c
	adds r0, r0, r1
	adds r1, #0xbc
	movs r2, #0
	ldrsh r1, [r1, r2]
	movs r2, #0xff
	bl sub_08035740
	ldrb r0, [r4]
	lsls r0, r0, #3
	adds r1, r5, #0
	adds r1, #0x2d
	adds r0, r0, r1
	adds r4, #0x62
	ldr r3, _0802153C @ =0x03000590
	adds r1, #0x5a
	ldrb r2, [r1]
	lsls r2, r2, #8
	adds r2, r2, r3
	adds r2, #0xd5
	movs r3, #0
	ldrsh r1, [r4, r3]
	ldrb r2, [r2]
	adds r1, r1, r2
	movs r2, #0xff
	bl sub_08035740
	b _0802154E
	.align 2, 0
_08021538: .4byte 0x03001800
_0802153C: .4byte 0x03000590
_08021540:
	ldrb r0, [r4]
	lsls r0, r0, #3
	adds r0, r0, r5
	adds r0, #0x2c
	ldrb r1, [r0]
	adds r1, #1
	strb r1, [r0]
_0802154E:
	ldr r1, _08021560 @ =0x03001800
_08021550:
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08021560: .4byte 0x03001800
_08021564:
	.byte 0x05, 0x49, 0x08, 0x1C, 0x51, 0x30, 0x00, 0x78, 0x0A, 0x1C, 0x01, 0x28
	.byte 0x0F, 0xD0, 0x01, 0x28, 0x04, 0xDC, 0x00, 0x28, 0x07, 0xD0, 0x16, 0xE0, 0x00, 0x18, 0x00, 0x03
	.byte 0x02, 0x28, 0x0A, 0xD0, 0x03, 0x28, 0x0C, 0xD0, 0x0F, 0xE0, 0x11, 0x1C, 0xA6, 0x31, 0x1E, 0x20
	.byte 0x0A, 0xE0, 0x11, 0x1C, 0xA6, 0x31, 0x1F, 0x20, 0x06, 0xE0, 0x11, 0x1C, 0xA6, 0x31, 0x20, 0x20
	.byte 0x02, 0xE0, 0x11, 0x1C, 0xA6, 0x31, 0x21, 0x20, 0x08, 0x70, 0x11, 0x1C, 0x08, 0x1C, 0x53, 0x30
	.byte 0x00, 0x78, 0x00, 0x28, 0x02, 0xD0, 0xA6, 0x31, 0x71, 0x20, 0x08, 0x70, 0x11, 0x1C, 0xAA, 0x31
	.byte 0x08, 0x78, 0x01, 0x30, 0x08, 0x70, 0x70, 0x47
	.syntax divided
