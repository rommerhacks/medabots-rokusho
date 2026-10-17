	.syntax unified

	thumb_func_start sub_08028130
sub_08028130: @ 0x08028130
	push {r4, r5, lr}
	ldr r1, _0802819C @ =0x03001800
	adds r5, r1, #0
	adds r5, #0x8a
	ldrb r0, [r5]
	lsls r0, r0, #3
	adds r2, r0, r1
	adds r0, r2, #0
	adds r0, #0x2a
	ldrb r0, [r0]
	adds r4, r1, #0
	cmp r0, #0
	beq _080281A4
	adds r0, r2, #0
	adds r0, #0x2b
	ldrb r0, [r0]
	cmp r0, #0x5a
	bne _080281A4
	adds r1, #0x53
	movs r0, #1
	strb r0, [r1]
	ldrb r0, [r5]
	lsls r0, r0, #3
	adds r1, r4, #0
	adds r1, #0x2c
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
	ldr r1, _080281A0 @ =0x03000590
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
	b _08028216
	.align 2, 0
_0802819C: .4byte 0x03001800
_080281A0: .4byte 0x03000590
_080281A4:
	adds r0, r4, #0
	adds r0, #0x53
	movs r2, #0
	strb r2, [r0]
	adds r5, r4, #0
	adds r5, #0x8a
	ldrb r0, [r5]
	lsls r0, r0, #3
	adds r0, r0, r4
	adds r0, #0x2a
	movs r1, #1
	strb r1, [r0]
	ldrb r0, [r5]
	lsls r0, r0, #3
	adds r0, r0, r4
	adds r0, #0x2b
	movs r1, #0x5a
	strb r1, [r0]
	ldrb r0, [r5]
	lsls r0, r0, #3
	adds r0, r0, r4
	adds r0, #0x2c
	strb r2, [r0]
	ldrb r0, [r5]
	lsls r0, r0, #3
	adds r0, r0, r4
	adds r0, #0x2d
	strb r2, [r0]
	ldrb r0, [r5]
	lsls r0, r0, #3
	adds r1, r4, #0
	adds r1, #0x2c
	adds r0, r0, r1
	adds r1, #0xbc
	movs r2, #0
	ldrsh r1, [r1, r2]
	movs r2, #0xff
	bl sub_08035740
	ldrb r0, [r5]
	lsls r0, r0, #3
	adds r1, r4, #0
	adds r1, #0x2d
	adds r0, r0, r1
	adds r3, r4, #0
	adds r3, #0xec
	ldr r1, _0802822C @ =0x03000590
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
_08028216:
	movs r2, #0xff
	bl sub_08035740
	adds r1, r4, #0
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802822C: .4byte 0x03000590
	.syntax divided
