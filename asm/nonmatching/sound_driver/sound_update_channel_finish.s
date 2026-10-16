	.syntax unified

	thumb_func_start sound_update_channel_finish
sound_update_channel_finish: @ 0x080746E4
	push {r4, lr}
	ldr r4, _08074714 @ =0x03007014
	ldr r1, [r4]
	movs r2, #0xa2
	lsls r2, r2, #3
	adds r0, r1, r2
	ldr r0, [r0]
	cmp r0, #0
	bne _08074700
	movs r2, #0xdb
	lsls r2, r2, #3
	adds r0, r1, r2
	bl sub_08073CA4
_08074700:
	ldr r0, [r4]
	movs r1, #0xae
	lsls r1, r1, #3
	adds r0, r0, r1
	bl sound_channel_finish_and_callback
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08074714: .4byte 0x03007014
	.syntax divided
