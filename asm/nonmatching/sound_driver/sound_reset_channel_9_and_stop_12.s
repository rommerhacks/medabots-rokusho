	.syntax unified

	thumb_func_start sound_reset_channel_9_and_stop_12
sound_reset_channel_9_and_stop_12: @ 0x08074740
	push {r4, lr}
	ldr r4, _08074768 @ =0x03007014
	ldr r0, [r4]
	movs r1, #0xdb
	lsls r1, r1, #3
	adds r0, r0, r1
	bl sub_08073CA4
	ldr r0, [r4]
	ldr r1, _0807476C @ =0x0000054C
	adds r0, r0, r1
	movs r1, #0
	strb r1, [r0]
	movs r0, #0xc
	bl sound_stop_channel_by_index
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08074768: .4byte 0x03007014
_0807476C: .4byte 0x0000054C
	.syntax divided
