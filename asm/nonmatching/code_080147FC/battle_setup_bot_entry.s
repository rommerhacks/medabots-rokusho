	.syntax unified

	thumb_func_start battle_setup_bot_entry
	.global battle_setup_bot_entry
battle_setup_bot_entry: @ 0x08014EC8
	push {lr}
	bl copy_player_medals_to_battle_bots
	bl copy_battle_position_to_sprite
	ldr r0, _08014EE4 @ =0x03001800
	adds r0, #0x5a
	ldrb r1, [r0]
	movs r0, #0
	bl setup_bot_render_label
	pop {r0}
	bx r0
	.align 2, 0
_08014EE4: .4byte 0x03001800
	.syntax divided
