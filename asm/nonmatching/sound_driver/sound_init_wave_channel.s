	.syntax unified

	thumb_func_start sound_init_wave_channel
	.global sound_init_wave_channel
sound_init_wave_channel: @ 0x08073910
	push {lr}
	ldr r1, _08073938 @ =0x04000084
	movs r0, #0x80
	strh r0, [r1]
	subs r1, #2
	ldr r2, _0807393C @ =0x0000400E
	adds r0, r2, #0
	strh r0, [r1]
	subs r1, #0x12
	movs r0, #0xc0
	strh r0, [r1]
	movs r0, #0
	bl load_wave_pattern
	movs r0, #7
	movs r1, #7
	bl sound_set_volume
	pop {r0}
	bx r0
	.align 2, 0
_08073938: .4byte 0x04000084
_0807393C: .4byte 0x0000400E
	.syntax divided
