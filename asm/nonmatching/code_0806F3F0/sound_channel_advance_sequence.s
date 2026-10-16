	.syntax unified

	thumb_func_start sound_channel_advance_sequence
sound_channel_advance_sequence: @ 0x08072EE0
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x14]
	cmp r0, #0
	beq _08072F16
	adds r1, r4, #0
	adds r1, #0x6e
	movs r0, #0
	strb r0, [r1]
	ldr r0, [r4, #0x28]
	cmp r0, #0
	beq _08072EFC
	subs r0, #1
	str r0, [r4, #0x28]
_08072EFC:
	ldr r0, [r4, #0x28]
	cmp r0, #0
	bne _08072F0E
	adds r0, r4, #0
	bl sound_channel_process_event
	ldr r0, [r4, #0x14]
	cmp r0, #0
	bne _08072EFC
_08072F0E:
	ldr r1, [r4, #0x10]
	adds r0, r4, #0
	bl _call_via_r1
_08072F16:
	pop {r4}
	pop {r0}
	bx r0
	.syntax divided
