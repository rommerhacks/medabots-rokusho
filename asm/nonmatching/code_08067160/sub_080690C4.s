	.syntax unified

	thumb_func_start sub_080690C4
sub_080690C4: @ 0x080690C4
	push {lr}
	bl sub_0806918C
	bl load_battle_sprite_graphics
	bl init_battle_background_layers
	bl load_bg_tilemaps_and_palette
	movs r0, #0
	bl play_song
	movs r0, #2
	movs r1, #2
	movs r2, #0
	bl setup_screen_transition_effect_080682CC
	movs r0, #0x13
	bl play_song
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r0, [r2]
	movs r3, #0xd0
	lsls r3, r3, #5
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _0806910C @ =0x03006F80
	movs r0, #0xb
	str r0, [r1]
	ldr r1, _08069110 @ =0x0300137C
	movs r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0806910C: .4byte 0x03006F80
_08069110: .4byte 0x0300137C
	.syntax divided
