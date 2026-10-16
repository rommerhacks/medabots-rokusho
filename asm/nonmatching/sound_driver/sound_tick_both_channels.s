	.syntax unified

	thumb_func_start sound_tick_both_channels
	.global sound_tick_both_channels
sound_tick_both_channels: @ 0x08073EF8
	push {lr}
	mov r3, sb
	push {r3}
	mov sb, sp
	movs r0, #0
	bl sound_channel_tick
	mov sb, sp
	movs r0, #1
	bl sound_channel_tick
	pop {r3}
	mov sb, r3
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
