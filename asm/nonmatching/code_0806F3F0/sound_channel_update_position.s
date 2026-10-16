	.syntax unified

	thumb_func_start sound_channel_update_position
sound_channel_update_position: @ 0x08072360
	push {r4, lr}
	adds r4, r0, #0
	bl sound_channel_check_and_advance
	cmp r0, #0
	bne _0807238E
	adds r0, r4, #0
	adds r0, #0x5d
	ldrb r0, [r0]
	adds r1, r4, #0
	adds r1, #0x5f
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08072386
	adds r0, r4, #0
	bl sound_channel_parse_note_param
	b _0807238E
_08072386:
	adds r1, r4, #0
	adds r1, #0x61
	movs r0, #4
	strb r0, [r1]
_0807238E:
	pop {r4}
	pop {r0}
	bx r0
	.syntax divided
