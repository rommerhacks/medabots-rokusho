	.syntax unified

	thumb_func_start sub_08009BC8
	.global sub_08009BC8
sub_08009BC8: @ 0x08009BC8
	push {r4, r5, lr}
	sub sp, #0xc
	ldr r0, _08009C74 @ =0x0300058C
	ldrb r1, [r0]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _08009CA4
	movs r0, #2
	bl play_sound_effect
	ldr r2, _08009C78 @ =0x03000440
	adds r4, r2, #0
	adds r4, #0x3e
	ldrb r1, [r4]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _08009C88
	movs r0, #0x7f
	ands r0, r1
	strb r0, [r4]
	ldrb r3, [r4]
	adds r5, r2, #0
	adds r5, #0x3f
	ldrb r1, [r5]
	lsls r0, r1, #1
	adds r0, r0, r1
	adds r1, r2, #0
	adds r1, #0x40
	lsls r0, r0, #1
	ldrb r1, [r1]
	adds r1, r0, r1
	cmp r3, r1
	beq _08009C68
	lsls r0, r3, #6
	ldr r2, _08009C7C @ =0x03000BE0
	adds r0, r0, r2
	lsls r1, r1, #6
	adds r1, r1, r2
	movs r2, #0x40
	bl memswap
	ldr r1, _08009C80 @ =0x083B4AE0
	ldrb r0, [r5]
	adds r0, #0x4b
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	str r0, [sp]
	ldr r0, _08009C84 @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp, #4]
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [sp, #8]
	movs r0, #0xa
	movs r1, #2
	movs r2, #5
	movs r3, #2
	bl write_tilemap_rect
	bl render_medal_sprite_tile
	bl render_medal_list_entries
	bl render_medal_slots_in_menu
	bl render_medal_name_display
	bl load_medal_sprite
	bl render_medal_level_display
	bl decompress_active_medal_sprite
	bl init_active_medal_battle_sprites
	bl draw_medal_position_tile
_08009C68:
	movs r0, #0
	strb r0, [r4]
	bl update_battle_sprite_visibility
	b _08009CA4
	.align 2, 0
_08009C74: .4byte 0x0300058C
_08009C78: .4byte 0x03000440
_08009C7C: .4byte 0x03000BE0
_08009C80: .4byte 0x083B4AE0
_08009C84: .4byte 0x0400000A
_08009C88:
	adds r0, r2, #0
	adds r0, #0x3f
	ldrb r0, [r0]
	lsls r1, r0, #1
	adds r1, r1, r0
	adds r0, r2, #0
	adds r0, #0x40
	lsls r1, r1, #1
	ldrb r0, [r0]
	adds r1, r1, r0
	subs r1, #0x80
	strb r1, [r4]
	bl update_battle_sprite_visibility
_08009CA4:
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.syntax divided
