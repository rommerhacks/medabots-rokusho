	.syntax unified

	thumb_func_start animate_battle_bots_entry
	.global animate_battle_bots_entry
animate_battle_bots_entry: @ 0x080187D4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	movs r0, #4
	movs r1, #1
	bl clear_sprite_table_mask
	movs r0, #5
	movs r1, #1
	bl clear_sprite_table_mask
	movs r0, #6
	movs r1, #1
	bl clear_sprite_table_mask
	movs r0, #7
	movs r1, #1
	bl clear_sprite_table_mask
	ldr r1, _08018858 @ =0x03000440
	adds r0, r1, #0
	adds r0, #0x3c
	ldrb r0, [r0]
	cmp r0, #0
	bne _08018864
	movs r5, #0
	ldr r0, _0801885C @ =0x03000590
	mov sb, r0
	adds r6, r1, #0
	ldr r7, _08018860 @ =0x083AD3A4
	movs r0, #0x40
	adds r0, r0, r6
	mov r8, r0
_08018818:
	adds r0, r6, #0
	adds r0, #0x3c
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	adds r4, r0, r5
	lsls r0, r4, #8
	add r0, sb
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #0
	beq _08018850
	lsls r1, r4, #1
	adds r0, r1, r7
	ldrb r3, [r0]
	mov r0, r8
	ldrb r2, [r0]
	movs r0, #0xd
	subs r0, r0, r2
	lsls r0, r0, #3
	subs r3, r3, r0
	adds r1, #1
	adds r1, r1, r7
	ldrb r2, [r1]
	adds r0, r4, #0
	adds r1, r3, #0
	bl setup_battle_bot_sprites_08017994
_08018850:
	adds r5, #1
	cmp r5, #2
	bls _08018818
	b _080188B2
	.align 2, 0
_08018858: .4byte 0x03000440
_0801885C: .4byte 0x03000590
_08018860: .4byte 0x083AD3A4
_08018864:
	movs r5, #0
	ldr r0, _080188C8 @ =0x03000590
	mov sb, r0
	adds r6, r1, #0
	ldr r7, _080188CC @ =0x083AD3A4
	movs r0, #0x40
	adds r0, r0, r6
	mov r8, r0
_08018874:
	adds r0, r6, #0
	adds r0, #0x3c
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	adds r4, r0, r5
	lsls r0, r4, #8
	add r0, sb
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #0
	beq _080188AC
	lsls r1, r4, #1
	adds r3, r1, r7
	mov r0, r8
	ldrb r2, [r0]
	movs r0, #0xd
	subs r0, r0, r2
	lsls r0, r0, #3
	ldrb r3, [r3]
	adds r3, r0, r3
	adds r1, #1
	adds r1, r1, r7
	ldrb r2, [r1]
	adds r0, r4, #0
	adds r1, r3, #0
	bl setup_battle_bot_sprites_08017994
_080188AC:
	adds r5, #1
	cmp r5, #2
	bls _08018874
_080188B2:
	ldr r1, _080188D0 @ =0x03000440
	adds r1, #0x40
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xe
	beq _080188D4
	movs r0, #0
	b _080188F2
	.align 2, 0
_080188C8: .4byte 0x03000590
_080188CC: .4byte 0x083AD3A4
_080188D0: .4byte 0x03000440
_080188D4:
	bl init_battle_cursor_sprite_08017B24
	bl render_battle_bot_label
	bl load_bot_sprite_tiles_to_vram
	bl copy_battle_bot_data_to_state
	bl battle_load_script_to_buffer
	bl battle_setup_bot_font_tile
	bl render_battle_bot_status_row
	movs r0, #1
_080188F2:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
	.syntax divided
