	.syntax unified

	thumb_func_start sub_08012EA8
sub_08012EA8: @ 0x08012EA8
	push {r4, lr}
	bl update_all_battle_status_sprites
	ldr r4, _08012EF4 @ =0x03001800
	adds r4, #0x80
	ldrb r0, [r4]
	bl animate_battle_sprites
	ldrb r1, [r4]
	lsls r0, r1, #2
	adds r0, #0x5a
	movs r2, #0
	bl update_battle_sprite_orbiting_positions
	bl draw_partial_bg1_column
	bl scroll_tilemap_window
	bl sub_08016FB4
	ldr r1, _08012EF8 @ =0x03000440
	adds r1, #0x84
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xa
	bne _08012EEC
	bl battle_load_sprite_data
	ldr r1, _08012EFC @ =0x0300137C
	movs r0, #7
	str r0, [r1]
_08012EEC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08012EF4: .4byte 0x03001800
_08012EF8: .4byte 0x03000440
_08012EFC: .4byte 0x0300137C
	.syntax divided
