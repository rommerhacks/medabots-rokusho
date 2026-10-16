	.syntax unified

	thumb_func_start sub_08068C6C
sub_08068C6C: @ 0x08068C6C
	push {lr}
	bl sub_0806918C
	movs r0, #0
	bl play_song
	ldr r1, _08068CD8 @ =0x03006FDC
	ldr r0, _08068CDC @ =0x03006D38
	ldrb r0, [r0]
	strb r0, [r1]
	bl get_entity_speed_value
	bl load_battle_sprite_graphics
	bl load_bg_tilemaps_and_palette
	bl init_battle_bg_layer
	movs r0, #0x13
	bl play_song
	movs r0, #4
	movs r1, #1
	movs r2, #0
	bl setup_screen_transition_effect_080682CC
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r0, [r2]
	movs r3, #0xf0
	lsls r3, r3, #5
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _08068CE0 @ =0x03006F88
	movs r0, #0
	str r0, [r1]
	ldr r1, _08068CE4 @ =0x03006F94
	strb r0, [r1]
	strb r0, [r1, #1]
	strb r0, [r1, #2]
	ldr r1, _08068CE8 @ =0x03006F8C
	strb r0, [r1]
	strb r0, [r1, #1]
	strb r0, [r1, #2]
	ldr r1, _08068CEC @ =0x03006F80
	movs r0, #3
	str r0, [r1]
	ldr r1, _08068CF0 @ =0x0300137C
	movs r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_08068CD8: .4byte 0x03006FDC
_08068CDC: .4byte 0x03006D38
_08068CE0: .4byte 0x03006F88
_08068CE4: .4byte 0x03006F94
_08068CE8: .4byte 0x03006F8C
_08068CEC: .4byte 0x03006F80
_08068CF0: .4byte 0x0300137C
	.syntax divided
