	.syntax unified

	thumb_func_start sub_08014870
sub_08014870: @ 0x08014870
	push {r4, r5, r6, lr}
	bl update_all_battle_status_sprites
	movs r4, #0
	ldr r0, _08014910 @ =0x03000590
	adds r6, r0, #0
	adds r6, #0xce
	adds r5, r0, #0
	adds r5, #0x40
_08014882:
	ldrb r0, [r5]
	cmp r0, #0
	beq _08014898
	ldrb r1, [r6]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _08014898
	adds r0, r4, #0
	bl sub_0801A228
_08014898:
	movs r0, #0x80
	lsls r0, r0, #1
	adds r6, r6, r0
	adds r5, r5, r0
	adds r4, #1
	cmp r4, #5
	bls _08014882
	ldr r1, _08014914 @ =0x03000440
	adds r1, #0x84
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x5a
	bne _08014908
	movs r4, #0
	movs r5, #0xa0
	lsls r5, r5, #0x14
_080148BE:
	ldr r1, _08014910 @ =0x03000590
	lsls r0, r4, #8
	adds r1, r0, r1
	adds r0, r1, #0
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #0
	beq _080148EA
	adds r2, r1, #0
	adds r2, #0xce
	ldrb r1, [r2]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _080148EA
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r2]
	lsrs r0, r5, #0x18
	movs r1, #3
	bl clear_battle_sprite_slot
_080148EA:
	movs r0, #0x80
	lsls r0, r0, #0x13
	adds r5, r5, r0
	adds r4, #1
	cmp r4, #5
	bls _080148BE
	ldr r1, _08014918 @ =0x03001800
	adds r1, #0x55
	ldrb r2, [r1]
	movs r0, #0xf7
	ands r0, r2
	strb r0, [r1]
	ldr r1, _0801491C @ =0x0300137C
	movs r0, #0x44
	str r0, [r1]
_08014908:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08014910: .4byte 0x03000590
_08014914: .4byte 0x03000440
_08014918: .4byte 0x03001800
_0801491C: .4byte 0x0300137C
	.syntax divided
