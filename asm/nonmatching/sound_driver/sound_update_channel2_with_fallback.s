	.syntax unified

	thumb_func_start sound_update_channel2_with_fallback
sound_update_channel2_with_fallback: @ 0x08074608
	push {r4, lr}
	ldr r4, _0807463C @ =0x03007014
	ldr r0, [r4]
	movs r1, #0x91
	lsls r1, r1, #2
	adds r0, r0, r1
	bl sound_channel_process_tone
	bl sub_080743C8
	cmp r0, #0
	bne _08074634
	ldr r1, [r4]
	adds r1, #0xc4
	ldrb r2, [r1]
	movs r0, #0x5f
	orrs r0, r2
	strb r0, [r1]
	ldr r0, [r4]
	adds r0, #0x74
	bl sound_channel_process_tone
_08074634:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807463C: .4byte 0x03007014
	.syntax divided
