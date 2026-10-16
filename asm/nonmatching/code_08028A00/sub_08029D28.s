	.syntax unified

	thumb_func_start sub_08029D28
sub_08029D28: @ 0x08029D28
	push {r4, r5, r6, lr}
	movs r4, #0
	ldr r5, _08029D4C @ =0x03001800
	adds r6, r5, #0
	adds r6, #0x60
_08029D32:
	adds r0, r5, #0
	adds r0, #0xd2
	adds r0, r4, r0
	ldrb r0, [r0]
	cmp r0, #0
	beq _08029D7C
	cmp r4, #1
	beq _08029D5C
	cmp r4, #1
	blo _08029D50
	cmp r4, #2
	beq _08029D70
	b _08029D7C
	.align 2, 0
_08029D4C: .4byte 0x03001800
_08029D50:
	ldrb r1, [r6]
	adds r1, r1, r4
	ldr r0, _08029D58 @ =0x030004DE
	b _08029D62
	.align 2, 0
_08029D58: .4byte 0x030004DE
_08029D5C:
	ldrb r1, [r6]
	adds r1, #1
	ldr r0, _08029D6C @ =0x030004F2
_08029D62:
	movs r2, #0x21
	bl update_battle_sprite_animations
	b _08029D7C
	.align 2, 0
_08029D6C: .4byte 0x030004F2
_08029D70:
	ldrb r1, [r6]
	adds r1, #2
	ldr r0, _08029DE4 @ =0x03000506
	movs r2, #0x21
	bl update_battle_sprite_animations
_08029D7C:
	adds r4, #1
	cmp r4, #2
	bls _08029D32
	ldr r0, _08029DE8 @ =0x03000440
	adds r3, r0, #0
	adds r3, #0x84
	ldrb r1, [r3]
	adds r2, r1, #1
	strb r2, [r3]
	adds r1, r0, #0
	adds r1, #0x89
	ldrb r1, [r1]
	adds r4, r0, #0
	cmp r1, #0
	bne _08029DB2
	ldr r0, _08029DEC @ =0x03001798
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08029DB2
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x32
	bls _08029DB2
	movs r0, #0x78
	strb r0, [r3]
_08029DB2:
	adds r0, r4, #0
	adds r0, #0x84
	ldrb r0, [r0]
	cmp r0, #0x78
	bne _08029DDC
	ldr r4, _08029DF0 @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x60
	ldrb r0, [r0]
	lsls r0, r0, #0x1a
	movs r1, #0x84
	lsls r1, r1, #0x16
	adds r0, r0, r1
	lsrs r0, r0, #0x18
	movs r1, #0xc
	bl clear_battle_sprite_slot
	adds r4, #0xaa
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
_08029DDC:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08029DE4: .4byte 0x03000506
_08029DE8: .4byte 0x03000440
_08029DEC: .4byte 0x03001798
_08029DF0: .4byte 0x03001800
_08029DF4:
	.byte 0x04, 0x49, 0x0A, 0x1C, 0xA6, 0x32, 0x3B, 0x20, 0x10, 0x70, 0xAA, 0x31
	.byte 0x08, 0x78, 0x01, 0x30, 0x08, 0x70, 0x70, 0x47, 0x00, 0x18, 0x00, 0x03
	.syntax divided
