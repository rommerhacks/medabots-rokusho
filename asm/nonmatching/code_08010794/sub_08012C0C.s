	.syntax unified

	thumb_func_start sub_08012C0C
sub_08012C0C: @ 0x08012C0C
	push {r4, lr}
	bl update_all_battle_status_sprites
	ldr r4, _08012C5C @ =0x03001800
	adds r4, #0x80
	ldrb r0, [r4]
	bl animate_battle_sprites
	bl load_battle_bg_layers
	ldrb r0, [r4]
	bl render_bot_name_sprites
	ldrb r0, [r4]
	bl draw_battle_panel_left_a
	ldrb r0, [r4]
	bl render_bot_health_bar
	ldrb r0, [r4]
	bl render_bot_cash_display
	bl battle_load_sprite_data
	bl sub_08015F78
	ldrb r0, [r4]
	lsls r0, r0, #2
	adds r0, #0x5a
	movs r1, #8
	bl battle_sprite_set_palette_index
	ldr r1, _08012C60 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08012C5C: .4byte 0x03001800
_08012C60: .4byte 0x0300137C
	.syntax divided
