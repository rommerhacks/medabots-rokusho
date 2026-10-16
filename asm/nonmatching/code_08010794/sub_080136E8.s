	.syntax unified

	thumb_func_start sub_080136E8
sub_080136E8: @ 0x080136E8
	push {r4, lr}
	bl update_all_battle_status_sprites
	ldr r4, _08013720 @ =0x03001800
	adds r4, #0x80
	ldrb r0, [r4]
	bl animate_battle_sprites
	ldrb r1, [r4]
	lsls r0, r1, #2
	adds r0, #0x5a
	movs r2, #0
	bl update_battle_sprite_orbiting_positions
	bl copy_obj_palette_to_buffer
	ldr r0, _08013724 @ =0x03000440
	adds r0, #0x84
	movs r1, #0
	strb r1, [r0]
	ldr r1, _08013728 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08013720: .4byte 0x03001800
_08013724: .4byte 0x03000440
_08013728: .4byte 0x0300137C
	.syntax divided
