	.syntax unified

	thumb_func_start sub_08012E40
sub_08012E40: @ 0x08012E40
	push {r4, lr}
	sub sp, #8
	bl update_all_battle_status_sprites
	ldr r4, _08012E94 @ =0x03001800
	adds r4, #0x80
	ldrb r0, [r4]
	bl animate_battle_sprites
	ldrb r1, [r4]
	lsls r0, r1, #2
	adds r0, #0x5a
	movs r2, #0
	bl update_battle_sprite_orbiting_positions
	bl decompress_two_bg1_layers
	bl sub_08016068
	ldr r0, _08012E98 @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp]
	ldr r0, _08012E9C @ =0x02020800
	str r0, [sp, #4]
	movs r0, #6
	movs r1, #5
	movs r2, #0xc
	movs r3, #0x15
	bl read_vram_tilemap_rect
	ldr r0, _08012EA0 @ =0x03000440
	adds r0, #0x84
	movs r1, #0
	strb r1, [r0]
	ldr r1, _08012EA4 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08012E94: .4byte 0x03001800
_08012E98: .4byte 0x0400000A
_08012E9C: .4byte 0x02020800
_08012EA0: .4byte 0x03000440
_08012EA4: .4byte 0x0300137C
	.syntax divided
