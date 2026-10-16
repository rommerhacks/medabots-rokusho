	.syntax unified

	thumb_func_start sound_channel_tick_duration
sound_channel_tick_duration: @ 0x08072438
	push {lr}
	adds r2, r0, #0
	adds r1, r2, #0
	adds r1, #0x5f
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08072452
	adds r0, r2, #0
	bl sound_channel_process_command_080723D4
_08072452:
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
