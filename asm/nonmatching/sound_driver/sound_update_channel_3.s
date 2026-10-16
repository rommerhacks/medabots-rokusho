	.syntax unified

	thumb_func_start sound_update_channel_3
	.global sound_update_channel_3
sound_update_channel_3: @ 0x08073670
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _08073690 @ =0x04000078
	bl update_sound_channel_frequency_08073244
	ldr r1, _08073694 @ =0x0400007C
	adds r0, r4, #0
	bl sound_channel_check_note_change
	adds r0, r4, #0
	bl sound_update_channel_output_routing
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08073690: .4byte 0x04000078
_08073694: .4byte 0x0400007C
	.syntax divided
