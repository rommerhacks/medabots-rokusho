	.syntax unified

	thumb_func_start handle_battle_bot_selection
	.global handle_battle_bot_selection
handle_battle_bot_selection: @ 0x080183A4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	movs r0, #0
	mov r8, r0
	ldr r3, _08018420 @ =0x083AD3A4
	ldr r0, _08018424 @ =0x03000440
	adds r6, r0, #0
	adds r6, #0x3d
	ldrb r4, [r6]
	adds r0, #0x3c
	ldrb r2, [r0]
	lsls r0, r2, #1
	adds r5, r0, r2
	adds r0, r4, r5
	lsls r0, r0, #1
	adds r1, r0, r3
	ldrb r1, [r1]
	adds r0, #1
	adds r0, r0, r3
	ldrb r3, [r0]
	cmp r2, #0
	bne _08018458
	ldr r0, _08018428 @ =0x03001798
	ldrb r2, [r0]
	movs r0, #0xa0
	ands r0, r2
	cmp r0, #0
	beq _08018430
	adds r2, r4, #0
	cmp r2, #2
	bne _080183E8
	b _08018510
_080183E8:
	ldr r7, _0801842C @ =0x03000590
	adds r0, r5, #1
	adds r0, r4, r0
	lsls r0, r0, #8
	adds r0, r0, r7
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #0
	bne _080184D6
	cmp r2, #0
	beq _08018400
	b _08018510
_08018400:
	adds r0, r5, #2
	adds r0, r4, r0
	lsls r0, r0, #8
	adds r0, r0, r7
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #0
	bne _08018412
	b _08018510
_08018412:
	movs r0, #0
	adds r2, r3, #0
	bl setup_bot_battle_sprites_08017A7C
	movs r0, #2
	strb r0, [r6]
	b _08018516
	.align 2, 0
_08018420: .4byte 0x083AD3A4
_08018424: .4byte 0x03000440
_08018428: .4byte 0x03001798
_0801842C: .4byte 0x03000590
_08018430:
	movs r0, #0x50
	ands r0, r2
	cmp r0, #0
	beq _08018510
	adds r2, r4, #0
	cmp r2, #0
	beq _08018510
	ldr r7, _08018454 @ =0x03000590
	subs r0, r5, #1
	adds r0, r4, r0
	lsls r0, r0, #8
	adds r0, r0, r7
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #0
	bne _0801847C
	b _08018494
	.align 2, 0
_08018454: .4byte 0x03000590
_08018458:
	ldr r0, _0801848C @ =0x03001798
	ldrb r2, [r0]
	movs r0, #0x60
	ands r0, r2
	cmp r0, #0
	beq _080184B6
	adds r2, r4, #0
	cmp r2, #0
	beq _08018510
	ldr r7, _08018490 @ =0x03000590
	subs r0, r5, #1
	adds r0, r4, r0
	lsls r0, r0, #8
	adds r0, r0, r7
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #0
	beq _08018494
_0801847C:
	movs r0, #0
	adds r2, r3, #0
	bl setup_bot_battle_sprites_08017A7C
	ldrb r0, [r6]
	subs r0, #1
	strb r0, [r6]
	b _08018516
	.align 2, 0
_0801848C: .4byte 0x03001798
_08018490: .4byte 0x03000590
_08018494:
	cmp r2, #2
	bne _08018510
	subs r0, r5, #2
	adds r0, r4, r0
	lsls r0, r0, #8
	adds r0, r0, r7
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #0
	beq _08018510
	movs r0, #0
	adds r2, r3, #0
	bl setup_bot_battle_sprites_08017A7C
	mov r0, r8
	strb r0, [r6]
	b _08018516
_080184B6:
	movs r0, #0x90
	ands r0, r2
	cmp r0, #0
	beq _08018510
	adds r2, r4, #0
	cmp r2, #2
	beq _08018510
	ldr r7, _080184E8 @ =0x03000590
	adds r0, r5, #1
	adds r0, r4, r0
	lsls r0, r0, #8
	adds r0, r0, r7
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #0
	beq _080184EC
_080184D6:
	movs r0, #0
	adds r2, r3, #0
	bl setup_bot_battle_sprites_08017A7C
	ldrb r0, [r6]
	adds r0, #1
	strb r0, [r6]
	b _08018516
	.align 2, 0
_080184E8: .4byte 0x03000590
_080184EC:
	cmp r2, #0
	bne _08018510
	adds r0, r5, #2
	adds r0, r4, r0
	lsls r0, r0, #8
	adds r0, r0, r7
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #0
	beq _08018510
	movs r0, #0
	adds r2, r3, #0
	bl setup_bot_battle_sprites_08017A7C
	movs r0, #2
	strb r0, [r6]
	movs r0, #1
	mov r8, r0
_08018510:
	mov r0, r8
	cmp r0, #0
	beq _0801858C
_08018516:
	movs r0, #2
	bl play_sound_effect
	bl init_battle_cursor_sprite_08017B24
	bl render_battle_bot_label
	bl load_bot_sprite_tiles_to_vram
	bl copy_battle_bot_data_to_state
	bl battle_load_script_to_buffer
	bl battle_setup_bot_font_tile
	bl render_battle_bot_status_row
	ldr r5, _08018598 @ =0x03000440
	adds r2, r5, #0
	adds r2, #0x3d
	adds r5, #0x3c
	ldrb r1, [r5]
	lsls r0, r1, #1
	adds r0, r0, r1
	ldrb r2, [r2]
	adds r0, r0, r2
	ldr r4, _0801859C @ =0x03001864
	adds r1, r4, #0
	bl get_bot_part_effective_values
	ldrb r0, [r4]
	ldrb r1, [r4, #1]
	ldrb r2, [r4, #2]
	ldrb r3, [r4, #3]
	bl set_game_state_params
	bl setup_scene_from_game_state
	ldrb r1, [r5]
	lsls r0, r1, #1
	adds r0, r0, r1
	movs r1, #0
	bl position_battle_team_cursors
	movs r0, #0
	movs r1, #8
	bl battle_sprite_set_palette_index
	ldr r0, _080185A0 @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp]
	ldr r0, _080185A4 @ =0x000063C0
	str r0, [sp, #4]
	movs r0, #2
	movs r1, #2
	movs r2, #0xb
	movs r3, #2
	bl fill_tilemap_rect_08042698
_0801858C:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08018598: .4byte 0x03000440
_0801859C: .4byte 0x03001864
_080185A0: .4byte 0x0400000A
_080185A4: .4byte 0x000063C0
	.syntax divided
