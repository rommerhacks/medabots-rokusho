	.syntax unified

	thumb_func_start sub_0801CAA8
sub_0801CAA8: @ 0x0801CAA8
	push {r4, lr}
	ldr r4, _0801CB14 @ =0x0300052E
	ldr r0, _0801CB18 @ =0x03001800
	adds r0, #0x87
	ldrb r1, [r0]
	adds r0, r4, #0
	movs r2, #0x21
	bl update_battle_sprite_animations
	adds r3, r4, #0
	subs r3, #0x6a
	ldrb r0, [r3]
	adds r2, r0, #1
	strb r2, [r3]
	subs r4, #0x65
	ldrb r0, [r4]
	cmp r0, #0
	bne _0801CAE4
	ldr r0, _0801CB1C @ =0x03001798
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0801CAE4
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x32
	bls _0801CAE4
	movs r0, #0x78
	strb r0, [r3]
_0801CAE4:
	ldr r0, _0801CB20 @ =0x03000440
	adds r0, #0x84
	ldrb r0, [r0]
	cmp r0, #0x78
	bne _0801CB0E
	ldr r4, _0801CB18 @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x87
	ldrb r0, [r0]
	lsls r0, r0, #0x1a
	movs r1, #0x84
	lsls r1, r1, #0x16
	adds r0, r0, r1
	lsrs r0, r0, #0x18
	movs r1, #4
	bl clear_battle_sprite_slot
	adds r4, #0xaa
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
_0801CB0E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801CB14: .4byte 0x0300052E
_0801CB18: .4byte 0x03001800
_0801CB1C: .4byte 0x03001798
_0801CB20: .4byte 0x03000440
	.syntax divided
