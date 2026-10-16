	.syntax unified

	thumb_func_start sub_08014754
sub_08014754: @ 0x08014754
	push {r4, r5, r6, r7, lr}
	bl update_all_battle_status_sprites
	movs r5, #0
	ldr r0, _080147E8 @ =0x03002C30
	ldr r7, _080147EC @ =0x03001855
	movs r6, #0x8e
	lsls r6, r6, #0x17
	movs r1, #0x8e
	lsls r1, r1, #5
	adds r4, r0, r1
_0801476A:
	ldr r1, _080147F0 @ =0x03000590
	lsls r0, r5, #8
	adds r1, r0, r1
	adds r0, r1, #0
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #0
	beq _080147C0
	adds r2, r1, #0
	adds r2, #0xce
	ldrb r1, [r2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080147C0
	ldrh r1, [r4]
	movs r3, #0x80
	lsls r3, r3, #8
	adds r0, r3, #0
	orrs r0, r1
	strh r0, [r4]
	ldrb r0, [r4, #9]
	adds r0, #4
	strb r0, [r4, #9]
	ldrb r0, [r4, #8]
	subs r0, #4
	strb r0, [r4, #8]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	bne _080147C0
	ldrb r1, [r7]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r7]
	ldrb r1, [r2]
	movs r0, #0xfd
	ands r0, r1
	strb r0, [r2]
	lsrs r0, r6, #0x18
	movs r1, #1
	bl clear_battle_sprite_slot
_080147C0:
	movs r0, #0xc0
	lsls r0, r0, #0x12
	adds r6, r6, r0
	adds r4, #0xc0
	adds r5, #1
	cmp r5, #5
	bls _0801476A
	ldr r0, _080147F4 @ =0x03001800
	adds r0, #0x55
	ldrb r1, [r0]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	bne _080147E2
	ldr r1, _080147F8 @ =0x0300137C
	movs r0, #0x44
	str r0, [r1]
_080147E2:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080147E8: .4byte 0x03002C30
_080147EC: .4byte 0x03001855
_080147F0: .4byte 0x03000590
_080147F4: .4byte 0x03001800
_080147F8: .4byte 0x0300137C
	.syntax divided
