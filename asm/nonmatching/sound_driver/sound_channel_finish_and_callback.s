	.syntax unified

	thumb_func_start sound_channel_finish_and_callback
	.global sound_channel_finish_and_callback
sound_channel_finish_and_callback: @ 0x080747E4
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x14]
	cmp r0, #0
	beq _080747FA
	adds r0, r4, #0
	bl sound_channel_reset
	ldr r0, [r4, #0xc]
	bl _call_via_r0
_080747FA:
	pop {r4}
	pop {r0}
	bx r0
	.syntax divided
