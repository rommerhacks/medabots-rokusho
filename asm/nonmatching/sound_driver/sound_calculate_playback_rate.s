	.syntax unified

	thumb_func_start sound_calculate_playback_rate
sound_calculate_playback_rate: @ 0x08073AA0
	push {r4, lr}
	adds r4, r0, #0
	ldr r2, [r4]
	ldrh r0, [r2, #4]
	muls r0, r1, r0
	lsrs r0, r0, #0xc
	ldrb r1, [r2, #6]
	bl sub_08073A84
	movs r1, #0xf0
	lsls r1, r1, #0xb
	cmp r0, r1
	bls _08073ABC
	adds r0, r1, #0
_08073ABC:
	str r0, [r4, #4]
	pop {r4}
	pop {r1}
	bx r1
	.syntax divided
