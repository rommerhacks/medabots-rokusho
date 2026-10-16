	.syntax unified

	thumb_func_start update_battle_field_frame
	.global update_battle_field_frame
update_battle_field_frame: @ 0x08048098
	push {r4, r5, lr}
	ldr r2, _08048108 @ =0x03004C30
	ldr r1, _0804810C @ =0x03005310
	ldrh r0, [r1, #0x1e]
	movs r5, #0
	strh r0, [r2]
	ldrh r0, [r1, #0x26]
	strh r0, [r2, #2]
	ldr r2, _08048110 @ =0x0300057C
	ldrh r0, [r1, #0x20]
	strh r0, [r2]
	ldrh r0, [r1, #0x28]
	strh r0, [r2, #2]
	ldr r2, _08048114 @ =0x03001C04
	ldrh r0, [r1, #0x22]
	strh r0, [r2]
	ldrh r0, [r1, #0x2a]
	strh r0, [r2, #2]
	bl sub_080482C0
	bl dma_load_battle_palettes
	bl load_room_graphics
	ldr r4, _08048118 @ =0x030057E0
	ldr r1, _0804811C @ =0x00000C36
	adds r0, r4, r1
	strb r5, [r0]
	bl update_sprite_animation_dma
	ldr r1, _08048120 @ =0x00000CBA
	adds r0, r4, r1
	ldrb r0, [r0]
	bl load_map_npc_sprites
	bl update_entity_sprites_on_screen
	bl init_battle_field_setup
	bl update_bg_scroll_offsets_a
	bl init_battle_medaforce_sprite
	bl update_bg_scroll_offsets_b
	bl decompress_battle_tile_graphics
	ldr r0, _08048124 @ =0x00000C4C
	adds r4, r4, r0
	movs r0, #1
	strb r0, [r4]
	bl update_battle_entity_status_chars
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08048108: .4byte 0x03004C30
_0804810C: .4byte 0x03005310
_08048110: .4byte 0x0300057C
_08048114: .4byte 0x03001C04
_08048118: .4byte 0x030057E0
_0804811C: .4byte 0x00000C36
_08048120: .4byte 0x00000CBA
_08048124: .4byte 0x00000C4C
	.syntax divided
