	.syntax unified

	thumb_func_start advance_fade_and_play_music
advance_fade_and_play_music: @ 0x080663A0
	push {lr}
	ldr r0, _080663D8 @ =0x03006F74
	ldr r0, [r0]
	adds r0, #0x50
	bl blend_fade_step_08065598
	cmp r0, #0
	beq _080663D2
	movs r0, #4
	bl is_sound_playing_with_lock
	cmp r0, #0
	bne _080663D2
	movs r0, #0
	bl play_song
	movs r0, #0
	bl play_sound_effect
	bl get_medal_count_or_status
	ldr r1, _080663DC @ =0x0300137C
	ldr r0, [r1]
	adds r0, #2
	str r0, [r1]
_080663D2:
	pop {r0}
	bx r0
	.align 2, 0
_080663D8: .4byte 0x03006F74
_080663DC: .4byte 0x0300137C
	.syntax divided
