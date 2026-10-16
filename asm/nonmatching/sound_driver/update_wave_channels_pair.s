	.syntax unified

	thumb_func_start update_wave_channels_pair
update_wave_channels_pair: @ 0x08074640
	push {r4, lr}
	ldr r4, _08074678 @ =0x03007014
	ldr r0, [r4]
	movs r1, #0xae
	lsls r1, r1, #2
	adds r0, r0, r1
	bl update_wave_channel
	bl sub_080743C8
	cmp r0, #0
	bne _08074670
	ldr r1, [r4]
	movs r0, #0x9c
	lsls r0, r0, #1
	adds r1, r1, r0
	ldrb r2, [r1]
	movs r0, #0x7f
	orrs r0, r2
	strb r0, [r1]
	ldr r0, [r4]
	adds r0, #0xe8
	bl update_wave_channel
_08074670:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08074678: .4byte 0x03007014
	.syntax divided
