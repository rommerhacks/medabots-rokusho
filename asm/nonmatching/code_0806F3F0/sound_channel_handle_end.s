	.syntax unified

	thumb_func_start sound_channel_handle_end
sound_channel_handle_end: @ 0x08072414
	push {r4, lr}
	adds r4, r0, #0
	bl sound_channel_check_and_advance
	adds r2, r0, #0
	cmp r2, #0
	bne _08072432
	adds r1, r4, #0
	adds r1, #0x5f
	movs r0, #1
	strb r0, [r1]
	adds r1, #1
	strb r2, [r1]
	adds r1, #1
	strb r0, [r1]
_08072432:
	pop {r4}
	pop {r0}
	bx r0
	.syntax divided
