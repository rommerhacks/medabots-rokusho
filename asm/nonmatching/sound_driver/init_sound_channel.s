	.syntax unified

	thumb_func_start init_sound_channel
init_sound_channel: @ 0x080743E4
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	bl clear_sound_channel_wave_data
	str r4, [r5, #0x14]
	movs r1, #0
	str r1, [r5, #0x18]
	str r1, [r5, #0x1c]
	str r1, [r5, #0x20]
	str r1, [r5, #0x24]
	str r1, [r5, #0x28]
	str r1, [r5, #0x2c]
	str r1, [r5, #0x30]
	adds r2, r5, #0
	adds r2, #0x50
	movs r0, #0x5f
	strb r0, [r2]
	adds r0, r5, #0
	adds r0, #0x52
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r2, #4
	movs r0, #8
	strb r0, [r2]
	adds r0, r5, #0
	adds r0, #0x55
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	str r1, [r5, #0x34]
	str r1, [r5, #0x38]
	adds r0, #9
	strb r1, [r0]
	subs r2, #0xc
	movs r3, #0
	movs r0, #0xff
	strh r0, [r2]
	adds r2, #0x1d
	movs r0, #0xf
	strb r0, [r2]
	adds r0, r5, #0
	adds r0, #0x66
	strb r3, [r0]
	adds r0, #1
	strb r3, [r0]
	adds r0, #1
	strb r3, [r0]
	adds r0, #1
	strb r3, [r0]
	adds r0, #1
	strb r3, [r0]
	adds r0, #1
	strb r3, [r0]
	adds r2, #7
	movs r0, #0xff
	strb r0, [r2]
	adds r0, r5, #0
	adds r0, #0x62
	strb r3, [r0]
	adds r0, #0xb
	strb r3, [r0]
	adds r0, #1
	strb r3, [r0]
	subs r0, #0x2e
	movs r2, #0x80
	lsls r2, r2, #5
	strh r2, [r0]
	adds r0, #2
	strh r2, [r0]
	adds r0, #2
	strh r1, [r0]
	str r1, [r5, #0x3c]
	adds r2, r5, #0
	adds r2, #0x6f
	movs r0, #3
	strb r0, [r2]
	adds r0, r5, #0
	adds r0, #0x70
	strb r3, [r0]
	subs r0, #0x24
	strh r1, [r0]
	adds r1, r5, #0
	adds r1, #0x4e
	ldr r0, _080744B0 @ =0x0000FFFF
	strh r0, [r1]
	adds r0, r5, #0
	bl sub_08074800
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080744B0: .4byte 0x0000FFFF
	.syntax divided
