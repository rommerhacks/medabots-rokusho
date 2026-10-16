	.syntax unified

	thumb_func_start sub_08012C64
sub_08012C64: @ 0x08012C64
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	bl update_all_battle_status_sprites
	ldr r7, _08012CC4 @ =0x03001800
	adds r6, r7, #0
	adds r6, #0x80
	ldrb r0, [r6]
	bl animate_battle_sprites
	ldrb r1, [r6]
	lsls r0, r1, #2
	adds r0, #0x5a
	movs r2, #0
	bl update_battle_sprite_orbiting_positions
	bl sub_08016288
	bl sub_080178CC
	adds r0, r7, #0
	adds r0, #0x83
	ldrb r0, [r0]
	cmp r0, #0
	bne _08012D82
	bl sub_0801630C
	ldr r0, _08012CC8 @ =0x0300058C
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08012CF4
	ldr r0, _08012CCC @ =0x03000440
	adds r0, #0x89
	ldrb r0, [r0]
	cmp r0, #1
	bne _08012CD0
	adds r0, r7, #0
	adds r0, #0x81
	ldrb r0, [r0]
	cmp r0, #5
	bne _08012CD0
	movs r0, #6
	bl play_sound_effect
	b _08012D82
	.align 2, 0
_08012CC4: .4byte 0x03001800
_08012CC8: .4byte 0x0300058C
_08012CCC: .4byte 0x03000440
_08012CD0:
	movs r0, #4
	bl play_sound_effect
	bl sub_08017914
	ldr r0, _08012CEC @ =0x03000440
	adds r0, #0x84
	movs r1, #0
	strb r1, [r0]
	ldr r1, _08012CF0 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	b _08012D80
	.align 2, 0
_08012CEC: .4byte 0x03000440
_08012CF0: .4byte 0x0300137C
_08012CF4:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08012D82
	adds r0, r7, #0
	adds r0, #0x84
	ldrb r5, [r0]
	cmp r5, #0
	bne _08012D82
	ldrb r0, [r6]
	cmp r0, #0
	beq _08012D82
	movs r0, #5
	bl play_sound_effect
	ldrb r4, [r6]
	adds r0, r4, #0
	movs r1, #3
	bl sub_0807CDD0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r2, r0, #1
	adds r2, r2, r0
	lsls r2, r2, #3
	adds r2, #0x24
	adds r0, r4, #0
	movs r1, #0x28
	bl setup_bot_battle_sprites_08015A00
	ldrb r0, [r6]
	subs r0, #1
	strb r0, [r6]
	movs r0, #0
	bl draw_battle_panel_left_a
	ldrb r0, [r6]
	bl sub_0801A744
	adds r0, r7, #0
	adds r0, #0x81
	strb r5, [r0]
	adds r0, #1
	strb r5, [r0]
	movs r0, #0
	movs r1, #0x46
	bl clear_battle_sprite_slot
	ldr r0, _08012D8C @ =0x04000008
	ldrh r0, [r0]
	str r0, [sp]
	str r5, [sp, #4]
	movs r0, #0x1e
	movs r1, #8
	movs r2, #0
	movs r3, #0xc
	bl vram_fill_tilemap_rect
	ldr r0, _08012D90 @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp]
	str r5, [sp, #4]
	movs r0, #0x1e
	movs r1, #8
	movs r2, #0
	movs r3, #0xc
	bl vram_fill_tilemap_rect
	ldr r1, _08012D94 @ =0x0300137C
	movs r0, #4
_08012D80:
	str r0, [r1]
_08012D82:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08012D8C: .4byte 0x04000008
_08012D90: .4byte 0x0400000A
_08012D94: .4byte 0x0300137C
	.syntax divided
