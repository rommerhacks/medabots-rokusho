	.syntax unified

	thumb_func_start sub_08012F00
sub_08012F00: @ 0x08012F00
	push {r4, r5, r6, lr}
	bl update_all_battle_status_sprites
	ldr r4, _08012F34 @ =0x03001800
	adds r5, r4, #0
	adds r5, #0x80
	ldrb r0, [r5]
	bl animate_battle_sprites
	ldrb r1, [r5]
	lsls r0, r1, #2
	adds r0, #0x5a
	movs r2, #0
	bl update_battle_sprite_orbiting_positions
	adds r0, r4, #0
	adds r0, #0x81
	ldrb r0, [r0]
	cmp r0, #0
	beq _08012F38
	cmp r0, #1
	beq _08012F42
	ldrb r0, [r5]
	bl process_bot_battle_turn
	b _08012F60
	.align 2, 0
_08012F34: .4byte 0x03001800
_08012F38:
	ldrb r0, [r5]
	adds r1, r4, #0
	adds r1, #0x82
	ldrb r1, [r1]
	b _08012F5C
_08012F42:
	adds r1, r4, #0
	adds r1, #0x82
	ldrb r0, [r1]
	cmp r0, #0
	beq _08012F58
	ldrb r0, [r5]
	ldrb r1, [r1]
	subs r1, #1
	bl load_bot_palette_data
	b _08012F60
_08012F58:
	ldrb r0, [r5]
	movs r1, #0
_08012F5C:
	bl battle_bot_select_part
_08012F60:
	ldr r6, _08012FB8 @ =0x03001800
	adds r4, r6, #0
	adds r4, #0x80
	ldrb r5, [r4]
	adds r0, r5, #0
	movs r1, #3
	bl sub_0807CDD0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r2, r0, #1
	adds r2, r2, r0
	lsls r2, r2, #3
	adds r2, #0x24
	adds r0, r5, #0
	movs r1, #0x28
	bl setup_bot_battle_sprites_08015A00
	adds r1, r6, #0
	adds r1, #0x81
	movs r0, #0
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
	ldrb r0, [r4]
	adds r1, r0, #1
	strb r1, [r4]
	adds r0, r6, #0
	adds r0, #0x84
	ldrb r0, [r0]
	cmp r0, #0
	bne _08012FE4
	lsls r0, r1, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #3
	beq _08012FC0
	adds r0, r6, #0
	adds r0, #0x5a
	ldrb r0, [r0]
	cmp r1, r0
	bhs _08012FC0
	ldr r1, _08012FBC @ =0x0300137C
	movs r0, #4
	b _08012FEA
	.align 2, 0
_08012FB8: .4byte 0x03001800
_08012FBC: .4byte 0x0300137C
_08012FC0:
	ldr r0, _08012FD0 @ =0x03000440
	adds r0, #0x89
	ldrb r0, [r0]
	cmp r0, #1
	beq _08012FD8
	ldr r1, _08012FD4 @ =0x0300137C
	movs r0, #0x40
	b _08012FEA
	.align 2, 0
_08012FD0: .4byte 0x03000440
_08012FD4: .4byte 0x0300137C
_08012FD8:
	ldr r1, _08012FE0 @ =0x0300137C
	movs r0, #0x90
	b _08012FEA
	.align 2, 0
_08012FE0: .4byte 0x0300137C
_08012FE4:
	ldr r1, _08012FF4 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
_08012FEA:
	str r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08012FF4: .4byte 0x0300137C
	.syntax divided
