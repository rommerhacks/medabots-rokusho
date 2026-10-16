	.syntax unified

	thumb_func_start sound_channel_6_update_note
	.global sound_channel_6_update_note
sound_channel_6_update_note: @ 0x0807384C
	push {lr}
	ldr r1, _08073860 @ =0x03007014
	ldr r1, [r1]
	movs r2, #0xd2
	lsls r2, r2, #3
	adds r1, r1, r2
	bl sound_channel_update_note_08073698
	pop {r0}
	bx r0
	.align 2, 0
_08073860: .4byte 0x03007014
	.syntax divided
