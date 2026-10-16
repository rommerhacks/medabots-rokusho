	.syntax unified

	thumb_func_start sound_set_pitch_offset
	.global sound_set_pitch_offset
sound_set_pitch_offset: @ 0x08073AC4
	push {r4, lr}
	adds r4, r0, #0
	adds r0, r1, #0
	ldr r1, [r4]
	ldrb r1, [r1, #7]
	subs r0, r0, r1
	bl sound_volume_lookup
	adds r1, r0, #0
	adds r0, r4, #0
	bl sound_calculate_playback_rate
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	.syntax divided
