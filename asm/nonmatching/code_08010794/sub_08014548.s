	.syntax unified

	thumb_func_start sub_08014548
sub_08014548: @ 0x08014548
	push {r4, r5, r6, r7, lr}
	bl update_all_battle_status_sprites
	bl init_battle_bot_sprites
	movs r5, #0
_08014554:
	ldr r1, _080145A8 @ =0x03000590
	lsls r0, r5, #8
	adds r1, r0, r1
	adds r0, r1, #0
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #0
	beq _080145B0
	adds r6, r1, #0
	adds r6, #0xbf
	ldrb r0, [r6]
	cmp r0, #0
	beq _080145B0
	adds r0, r1, #0
	adds r0, #0xbb
	movs r7, #0
	movs r1, #8
	strb r1, [r0]
	adds r0, r5, #0
	bl sub_08019348
	adds r0, r5, #0
	bl sub_08019544
	adds r0, r5, #0
	movs r1, #1
	bl sub_08019FBC
	adds r4, r0, #0
	adds r0, r5, #0
	movs r1, #1
	bl sub_0801A030
	cmp r4, #0
	bne _0801459E
	cmp r0, #0
	beq _080145B0
_0801459E:
	strb r7, [r6]
	ldr r1, _080145AC @ =0x0300137C
	movs r0, #0x45
	str r0, [r1]
	b _080145B6
	.align 2, 0
_080145A8: .4byte 0x03000590
_080145AC: .4byte 0x0300137C
_080145B0:
	adds r5, #1
	cmp r5, #5
	bls _08014554
_080145B6:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.syntax divided
