	.syntax unified

	thumb_func_start reset_sound_channel_at_690
reset_sound_channel_at_690: @ 0x08074718
	push {r4, lr}
	ldr r4, _0807473C @ =0x03007014
	ldr r0, [r4]
	movs r1, #0xd2
	lsls r1, r1, #3
	adds r0, r0, r1
	bl sub_08073CA4
	ldr r0, [r4]
	movs r1, #0x9b
	lsls r1, r1, #3
	adds r0, r0, r1
	movs r1, #0
	strb r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807473C: .4byte 0x03007014
	.syntax divided
