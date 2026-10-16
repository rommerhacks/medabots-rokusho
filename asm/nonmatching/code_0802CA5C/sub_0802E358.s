	.syntax unified

	thumb_func_start sub_0802E358
sub_0802E358: @ 0x0802E358
	push {r4, r5, r6, lr}
	movs r4, #0
	ldr r5, _0802E37C @ =0x03001800
	adds r6, r5, #0
	adds r6, #0x60
_0802E362:
	adds r0, r5, #0
	adds r0, #0xd2
	adds r0, r4, r0
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802E3AC
	cmp r4, #1
	beq _0802E38C
	cmp r4, #1
	blo _0802E380
	cmp r4, #2
	beq _0802E3A0
	b _0802E3AC
	.align 2, 0
_0802E37C: .4byte 0x03001800
_0802E380:
	ldrb r1, [r6]
	adds r1, r1, r4
	ldr r0, _0802E388 @ =0x030004DE
	b _0802E392
	.align 2, 0
_0802E388: .4byte 0x030004DE
_0802E38C:
	ldrb r1, [r6]
	adds r1, #1
	ldr r0, _0802E39C @ =0x030004F2
_0802E392:
	movs r2, #0x21
	bl update_battle_sprite_animations
	b _0802E3AC
	.align 2, 0
_0802E39C: .4byte 0x030004F2
_0802E3A0:
	ldrb r1, [r6]
	adds r1, #2
	ldr r0, _0802E414 @ =0x03000506
	movs r2, #0x21
	bl update_battle_sprite_animations
_0802E3AC:
	adds r4, #1
	cmp r4, #2
	bls _0802E362
	ldr r0, _0802E418 @ =0x03000440
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
	bne _0802E3E2
	ldr r0, _0802E41C @ =0x03001798
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0802E3E2
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x32
	bls _0802E3E2
	movs r0, #0x78
	strb r0, [r3]
_0802E3E2:
	adds r0, r4, #0
	adds r0, #0x84
	ldrb r0, [r0]
	cmp r0, #0x78
	bne _0802E40C
	ldr r4, _0802E420 @ =0x03001800
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
_0802E40C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0802E414: .4byte 0x03000506
_0802E418: .4byte 0x03000440
_0802E41C: .4byte 0x03001798
_0802E420: .4byte 0x03001800
	.syntax divided
