	.syntax unified

	thumb_func_start sound_update_wave_channels
sound_update_wave_channels: @ 0x0807467C
	push {r4, lr}
	ldr r4, _080746B8 @ =0x03007014
	ldr r0, [r4]
	movs r1, #0xcb
	lsls r1, r1, #2
	adds r0, r0, r1
	bl sound_update_channel_3
	bl sub_080743C8
	cmp r0, #0
	bne _080746B0
	ldr r1, [r4]
	movs r0, #0xd6
	lsls r0, r0, #1
	adds r1, r1, r0
	ldrb r2, [r1]
	movs r0, #0x5f
	orrs r0, r2
	strb r0, [r1]
	ldr r0, [r4]
	movs r1, #0xae
	lsls r1, r1, #1
	adds r0, r0, r1
	bl sound_update_channel_3
_080746B0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080746B8: .4byte 0x03007014
	.syntax divided
