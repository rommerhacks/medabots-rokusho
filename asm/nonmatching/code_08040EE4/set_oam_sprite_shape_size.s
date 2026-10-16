	.syntax unified

	thumb_func_start set_oam_sprite_shape_size
	.global set_oam_sprite_shape_size
set_oam_sprite_shape_size: @ 0x08044DA8
	push {r4, r5, r6, lr}
	adds r3, r0, #0
	adds r4, r1, #0
	cmp r4, r2
	ble _08044DE8
	ldrb r1, [r3, #1]
	movs r5, #0x3f
	adds r0, r5, #0
	ands r0, r1
	movs r6, #0x80
	orrs r0, r6
	strb r0, [r3, #1]
	cmp r4, #8
	bne _08044DCC
	ldrb r1, [r3, #3]
	adds r0, r5, #0
	ands r0, r1
	b _08044E5A
_08044DCC:
	cmp r4, #0x40
	beq _08044E54
	cmp r2, #8
	bne _08044DDE
	ldrb r0, [r3, #3]
	adds r1, r5, #0
	ands r1, r0
	movs r0, #0x40
	b _08044E4E
_08044DDE:
	ldrb r1, [r3, #3]
	adds r0, r5, #0
	ands r0, r1
	orrs r0, r6
	b _08044E5A
_08044DE8:
	cmp r4, r2
	bge _08044E1E
	ldrb r1, [r3, #1]
	movs r5, #0x3f
	adds r0, r5, #0
	ands r0, r1
	movs r6, #0x40
	orrs r0, r6
	strb r0, [r3, #1]
	cmp r2, #8
	bne _08044E06
	ldrb r1, [r3, #3]
	adds r0, r5, #0
	ands r0, r1
	b _08044E5A
_08044E06:
	cmp r2, #0x40
	beq _08044E54
	cmp r4, #8
	bne _08044E18
	ldrb r1, [r3, #3]
	adds r0, r5, #0
	ands r0, r1
	orrs r0, r6
	b _08044E5A
_08044E18:
	ldrb r0, [r3, #3]
	adds r1, r5, #0
	b _08044E4A
_08044E1E:
	ldrb r1, [r3, #1]
	movs r2, #0x3f
	adds r0, r2, #0
	ands r0, r1
	strb r0, [r3, #1]
	cmp r4, #8
	bne _08044E34
	ldrb r1, [r3, #3]
	adds r0, r2, #0
	ands r0, r1
	b _08044E5A
_08044E34:
	cmp r4, #0x10
	bne _08044E42
	ldrb r0, [r3, #3]
	adds r1, r2, #0
	ands r1, r0
	movs r0, #0x40
	b _08044E4E
_08044E42:
	cmp r4, #0x20
	bne _08044E54
	ldrb r0, [r3, #3]
	adds r1, r2, #0
_08044E4A:
	ands r1, r0
	movs r0, #0x80
_08044E4E:
	orrs r1, r0
	strb r1, [r3, #3]
	b _08044E5C
_08044E54:
	ldrb r0, [r3, #3]
	movs r1, #0xc0
	orrs r0, r1
_08044E5A:
	strb r0, [r3, #3]
_08044E5C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
