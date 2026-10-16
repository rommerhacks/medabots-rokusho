	.syntax unified

	thumb_func_start sub_0804DD80
sub_0804DD80: @ 0x0804DD80
	push {r4, lr}
	bl sub_080482C0
	bl dma_load_battle_palettes
	bl load_room_graphics
	bl load_battlefield_data_to_buffer
	ldr r4, _0804DE04 @ =0x030057E0
	ldr r1, _0804DE08 @ =0x00000C35
	adds r0, r4, r1
	movs r1, #0
	strb r1, [r0]
	ldr r2, _0804DE0C @ =0x00000C36
	adds r0, r4, r2
	strb r1, [r0]
	bl update_sprite_animation_dma
	bl load_battle_terrain_data
	ldr r1, _0804DE10 @ =0x00000C56
	adds r0, r4, r1
	ldrb r0, [r0]
	ldr r2, _0804DE14 @ =0x00000C48
	adds r1, r4, r2
	lsls r0, r0, #4
	ldrh r1, [r1]
	adds r0, r0, r1
	adds r2, #0xa
	adds r1, r4, r2
	strh r0, [r1]
	ldr r1, _0804DE18 @ =0x00000C57
	adds r0, r4, r1
	ldrb r0, [r0]
	subs r2, #8
	adds r1, r4, r2
	lsls r0, r0, #4
	ldrh r1, [r1]
	adds r0, r0, r1
	adds r2, #0xa
	adds r1, r4, r2
	strh r0, [r1]
	bl init_battle_field_setup
	bl update_bg_scroll_offsets_a
	ldr r0, _0804DE1C @ =0x03002C30
	ldr r1, _0804DE20 @ =0x00000BE5
	adds r0, r0, r1
	movs r1, #1
	strb r1, [r0]
	ldr r2, _0804DE24 @ =0x00000C67
	adds r4, r4, r2
	ldrb r0, [r4]
	bl field_set_player_facing
	bl update_cursor_tile_position
	bl decompress_battle_tile_graphics
	bl sub_08050244
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804DE04: .4byte 0x030057E0
_0804DE08: .4byte 0x00000C35
_0804DE0C: .4byte 0x00000C36
_0804DE10: .4byte 0x00000C56
_0804DE14: .4byte 0x00000C48
_0804DE18: .4byte 0x00000C57
_0804DE1C: .4byte 0x03002C30
_0804DE20: .4byte 0x00000BE5
_0804DE24: .4byte 0x00000C67
	.syntax divided
