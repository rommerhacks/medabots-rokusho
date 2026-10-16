	.syntax unified

	thumb_func_start sub_08072ECC
sub_08072ECC: @ 0x08072ECC
	push {r4, lr}
	adds r4, r0, #0
	bl sub_08072658
	adds r0, r4, #0
	bl sound_channel_update_pitch_sweep
	pop {r4}
	pop {r0}
	bx r0
	.syntax divided
