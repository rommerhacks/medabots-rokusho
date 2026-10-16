	.syntax unified

	thumb_func_start sub_08014994
sub_08014994: @ 0x08014994
	push {r4, r5, r6, lr}
	bl update_all_battle_status_sprites
	movs r4, #0
	ldr r0, _08014A34 @ =0x03000590
	adds r6, r0, #0
	adds r6, #0xce
	adds r5, r0, #0
	adds r5, #0x40
_080149A6:
	ldrb r0, [r5]
	cmp r0, #0
	beq _080149BC
	ldrb r1, [r6]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080149BC
	adds r0, r4, #0
	bl sub_0801A228
_080149BC:
	movs r0, #0x80
	lsls r0, r0, #1
	adds r6, r6, r0
	adds r5, r5, r0
	adds r4, #1
	cmp r4, #5
	bls _080149A6
	ldr r1, _08014A38 @ =0x03000440
	adds r1, #0x84
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x5a
	bne _08014A2C
	movs r4, #0
	movs r5, #0xa0
	lsls r5, r5, #0x14
_080149E2:
	ldr r1, _08014A34 @ =0x03000590
	lsls r0, r4, #8
	adds r1, r0, r1
	adds r0, r1, #0
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #0
	beq _08014A0E
	adds r2, r1, #0
	adds r2, #0xce
	ldrb r1, [r2]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _08014A0E
	movs r0, #0xf7
	ands r0, r1
	strb r0, [r2]
	lsrs r0, r5, #0x18
	movs r1, #3
	bl clear_battle_sprite_slot
_08014A0E:
	movs r0, #0x80
	lsls r0, r0, #0x13
	adds r5, r5, r0
	adds r4, #1
	cmp r4, #5
	bls _080149E2
	ldr r1, _08014A3C @ =0x03001800
	adds r1, #0x55
	ldrb r2, [r1]
	movs r0, #0xef
	ands r0, r2
	strb r0, [r1]
	ldr r1, _08014A40 @ =0x0300137C
	movs r0, #0x44
	str r0, [r1]
_08014A2C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08014A34: .4byte 0x03000590
_08014A38: .4byte 0x03000440
_08014A3C: .4byte 0x03001800
_08014A40: .4byte 0x0300137C
	.syntax divided
