	.syntax unified

	thumb_func_start sound_read_envelope_params
sound_read_envelope_params: @ 0x08072B38
	push {lr}
	adds r3, r0, #0
	ldr r0, [r3, #0x14]
	ldrb r1, [r0]
	adds r2, r3, #0
	adds r2, #0x5b
	strb r1, [r2]
	adds r0, #1
	str r0, [r3, #0x14]
	ldrb r2, [r0]
	adds r1, r3, #0
	adds r1, #0x5c
	strb r2, [r1]
	adds r1, r0, #1
	str r1, [r3, #0x14]
	ldrb r0, [r0, #1]
	adds r2, r3, #0
	adds r2, #0x5d
	strb r0, [r2]
	adds r0, r1, #1
	str r0, [r3, #0x14]
	ldrb r1, [r1, #1]
	adds r2, #1
	strb r1, [r2]
	adds r0, #1
	str r0, [r3, #0x14]
	adds r1, r3, #0
	adds r1, #0x62
	movs r0, #1
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0x64
	ldrb r0, [r0]
	cmp r0, #2
	bgt _08072B88
	cmp r0, #0
	blt _08072B88
	adds r0, r3, #0
	bl sound_channel_handle_end
_08072B88:
	pop {r0}
	bx r0
	.syntax divided
