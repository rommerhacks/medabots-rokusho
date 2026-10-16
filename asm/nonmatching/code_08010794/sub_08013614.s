	.syntax unified

	thumb_func_start sub_08013614
sub_08013614: @ 0x08013614
	push {r4, lr}
	bl update_all_battle_status_sprites
	ldr r4, _08013648 @ =0x03001800
	adds r4, #0x80
	ldrb r0, [r4]
	bl animate_battle_sprites
	ldrb r1, [r4]
	lsls r0, r1, #2
	adds r0, #0x5a
	movs r2, #0
	bl update_battle_sprite_orbiting_positions
	movs r0, #1
	movs r1, #2
	movs r2, #0
	bl text_window_init
	ldr r1, _0801364C @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08013648: .4byte 0x03001800
_0801364C: .4byte 0x0300137C
	.syntax divided
