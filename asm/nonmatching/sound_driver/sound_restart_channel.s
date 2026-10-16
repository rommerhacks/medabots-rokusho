	.syntax unified

	thumb_func_start sound_restart_channel
sound_restart_channel: @ 0x08073C7C
	push {r4, lr}
	sub sp, #0x10
	adds r4, r0, #0
	bl sound_channel_stop_08073B0C
	movs r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	str r0, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl init_sound_channel_struct
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.syntax divided
