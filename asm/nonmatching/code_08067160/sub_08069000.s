	.syntax unified

	thumb_func_start sub_08069000
sub_08069000: @ 0x08069000
	push {lr}
	bl init_battle_field_screen
	bl init_battle_icon_positions
	bl init_battle_bg_layer1
	movs r0, #0
	bl play_song
	movs r0, #4
	movs r1, #1
	movs r2, #0
	bl setup_screen_transition_effect_080682CC
	movs r0, #0x17
	bl play_song
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r0, [r2]
	movs r3, #0xf0
	lsls r3, r3, #5
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _08069044 @ =0x03006F80
	movs r0, #8
	str r0, [r1]
	ldr r1, _08069048 @ =0x0300137C
	movs r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_08069044: .4byte 0x03006F80
_08069048: .4byte 0x0300137C
	.syntax divided
