	.syntax unified

	thumb_func_start sub_08013E30
sub_08013E30: @ 0x08013E30
	push {r4, r5, r6, lr}
	sub sp, #8
	bl sub_080182D0
	bl setup_scene_bg_from_game_state
	bl sub_080182AC
	ldr r5, _08013E58 @ =0x03000440
	adds r6, r5, #0
	adds r6, #0x3f
	ldrb r0, [r6]
	cmp r0, #1
	beq _08013F20
	cmp r0, #1
	bgt _08013E5C
	cmp r0, #0
	beq _08013E66
	b _08013F94
	.align 2, 0
_08013E58: .4byte 0x03000440
_08013E5C:
	cmp r0, #2
	beq _08013F36
	cmp r0, #3
	beq _08013F44
	b _08013F94
_08013E66:
	bl animate_bg_window_blink
	bl setup_battle_bot_display
	ldr r0, _08013EB4 @ =0x03001780
	ldrb r4, [r0]
	bl sub_0801827C
	adds r2, r0, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r0, #8
	adds r1, r4, #0
	bl sub_08041C14
	bl handle_battle_bot_selection
	ldr r0, _08013EB8 @ =0x0300058C
	ldrb r1, [r0, #1]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08013EBC
	adds r0, r5, #0
	adds r0, #0x3c
	ldrb r4, [r0]
	cmp r4, #0
	bne _08013EBC
	movs r0, #2
	bl play_sound_effect
	bl display_battle_cursor_on_bot
	adds r0, r5, #0
	adds r0, #0x40
	strb r4, [r0]
	ldrb r0, [r6]
	adds r0, #1
	b _08013F92
	.align 2, 0
_08013EB4: .4byte 0x03001780
_08013EB8: .4byte 0x0300058C
_08013EBC:
	ldr r2, _08013EF0 @ =0x0300058C
	ldrb r1, [r2, #1]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08013EF8
	ldr r4, _08013EF4 @ =0x03000440
	adds r0, r4, #0
	adds r0, #0x3c
	ldrb r0, [r0]
	cmp r0, #1
	bne _08013EF8
	movs r0, #2
	bl play_sound_effect
	bl display_battle_cursor_on_bot
	adds r1, r4, #0
	adds r1, #0x40
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _08013F94
	.align 2, 0
_08013EF0: .4byte 0x0300058C
_08013EF4: .4byte 0x03000440
_08013EF8:
	ldrb r1, [r2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08013F94
	movs r0, #5
	bl play_sound_effect
	movs r0, #6
	movs r1, #0x3f
	movs r2, #0x20
	bl set_blend_effect_mode
	ldr r1, _08013F1C @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	b _08013F94
	.align 2, 0
_08013F1C: .4byte 0x0300137C
_08013F20:
	bl animate_battle_field_scroll
	cmp r0, #0
	beq _08013F94
	adds r1, r5, #0
	adds r1, #0x40
	movs r0, #0
	strb r0, [r1]
	ldrb r0, [r6]
	adds r0, #1
	b _08013F92
_08013F36:
	bl animate_battle_bots_entry
	cmp r0, #0
	beq _08013F94
	ldrb r0, [r6]
	adds r0, #1
	b _08013F92
_08013F44:
	adds r2, r5, #0
	adds r2, #0x3d
	adds r0, r5, #0
	adds r0, #0x3c
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	ldrb r2, [r2]
	adds r0, r0, r2
	ldr r4, _08013F9C @ =0x03001864
	adds r1, r4, #0
	bl get_bot_part_effective_values
	ldrb r0, [r4]
	ldrb r1, [r4, #1]
	ldrb r2, [r4, #2]
	ldrb r3, [r4, #3]
	bl set_game_state_params
	bl init_ewram_buffers_and_state
	movs r0, #0
	movs r1, #8
	bl battle_sprite_set_palette_index
	ldr r0, _08013FA0 @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp]
	ldr r0, _08013FA4 @ =0x000063C0
	str r0, [sp, #4]
	movs r0, #2
	movs r1, #2
	movs r2, #0xb
	movs r3, #2
	bl fill_tilemap_rect_08042698
	bl setup_scene_from_game_state
	movs r0, #0
_08013F92:
	strb r0, [r6]
_08013F94:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08013F9C: .4byte 0x03001864
_08013FA0: .4byte 0x0400000A
_08013FA4: .4byte 0x000063C0
	.syntax divided
