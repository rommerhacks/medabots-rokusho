	.syntax unified

	thumb_func_start sub_0802D4D8
sub_0802D4D8: @ 0x0802D4D8
	push {r4, r5, r6, r7, lr}
	movs r4, #0
	ldr r5, _0802D4FC @ =0x03001800
	adds r6, r5, #0
	adds r6, #0x60
_0802D4E2:
	adds r0, r5, #0
	adds r0, #0xd2
	adds r0, r4, r0
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802D52C
	cmp r4, #1
	beq _0802D50C
	cmp r4, #1
	blo _0802D500
	cmp r4, #2
	beq _0802D520
	b _0802D52C
	.align 2, 0
_0802D4FC: .4byte 0x03001800
_0802D500:
	ldrb r1, [r6]
	adds r1, r1, r4
	ldr r0, _0802D508 @ =0x030004DE
	b _0802D512
	.align 2, 0
_0802D508: .4byte 0x030004DE
_0802D50C:
	ldrb r1, [r6]
	adds r1, #1
	ldr r0, _0802D51C @ =0x030004F2
_0802D512:
	movs r2, #0x21
	bl update_battle_sprite_animations
	b _0802D52C
	.align 2, 0
_0802D51C: .4byte 0x030004F2
_0802D520:
	ldrb r1, [r6]
	adds r1, #2
	ldr r0, _0802D5AC @ =0x03000506
	movs r2, #0x21
	bl update_battle_sprite_animations
_0802D52C:
	adds r4, #1
	cmp r4, #2
	bls _0802D4E2
	ldr r0, _0802D5B0 @ =0x03000440
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
	bne _0802D562
	ldr r0, _0802D5B4 @ =0x03001798
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0802D562
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x32
	bls _0802D562
	movs r0, #0x78
	strb r0, [r3]
_0802D562:
	adds r0, r4, #0
	adds r0, #0x84
	ldrb r0, [r0]
	cmp r0, #0x78
	bne _0802D5A4
	movs r4, #0
	ldr r5, _0802D5B8 @ =0x03001800
	adds r7, r5, #0
	adds r7, #0x60
_0802D574:
	adds r6, r5, #0
	adds r6, #0xd2
	adds r0, r4, r6
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802D594
	ldrb r0, [r7]
	adds r0, r0, r4
	lsls r0, r0, #0x1a
	movs r1, #0x84
	lsls r1, r1, #0x16
	adds r0, r0, r1
	lsrs r0, r0, #0x18
	movs r1, #4
	bl clear_battle_sprite_slot
_0802D594:
	adds r4, #1
	cmp r4, #2
	bls _0802D574
	adds r1, r6, #0
	subs r1, #0x28
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0802D5A4:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802D5AC: .4byte 0x03000506
_0802D5B0: .4byte 0x03000440
_0802D5B4: .4byte 0x03001798
_0802D5B8: .4byte 0x03001800
	.syntax divided
