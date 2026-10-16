	.syntax unified

	thumb_func_start sound_start_channel_full
sound_start_channel_full: @ 0x08073D50
	push {r4, lr}
	sub sp, #0x10
	adds r4, r0, #0
	bl sound_restart_channel
	ldr r1, [r4, #0x1c]
	ldr r0, [r4, #0x28]
	str r0, [sp]
	ldr r0, [r4, #0x2c]
	str r0, [sp, #4]
	adds r0, r4, #0
	adds r0, #0x30
	ldrb r0, [r0]
	str r0, [sp, #8]
	adds r0, r4, #0
	adds r0, #0x31
	ldrb r0, [r0]
	str r0, [sp, #0xc]
	adds r0, r4, #0
	movs r2, #0x20
	movs r3, #0
	bl init_sound_channel_struct
	ldr r1, [r4, #0x20]
	adds r0, r4, #0
	bl sound_calculate_playback_rate
	adds r1, r0, #0
	movs r0, #0x80
	lsls r0, r0, #0x11
	bl sub_0807CD58
	movs r1, #0x80
	lsls r1, r1, #9
	subs r1, r1, r0
	movs r0, #0x80
	lsls r0, r0, #0x10
	orrs r1, r0
	str r1, [r4, #0x10]
	adds r0, r4, #0
	movs r1, #0
	bl sound_channel_play
	ldr r0, [r4, #0x18]
	bl sub_080725BC
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.syntax divided
