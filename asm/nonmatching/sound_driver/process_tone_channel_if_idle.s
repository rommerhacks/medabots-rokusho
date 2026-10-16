	.syntax unified

	thumb_func_start process_tone_channel_if_idle
process_tone_channel_if_idle: @ 0x08074568
	push {lr}
	ldr r0, _08074588 @ =0x03007014
	ldr r1, [r0]
	movs r2, #0x96
	lsls r2, r2, #2
	adds r0, r1, r2
	ldr r0, [r0]
	cmp r0, #0
	bne _08074582
	adds r0, r1, #0
	adds r0, #0x74
	bl sound_channel_process_tone
_08074582:
	pop {r0}
	bx r0
	.align 2, 0
_08074588: .4byte 0x03007014
	.syntax divided
