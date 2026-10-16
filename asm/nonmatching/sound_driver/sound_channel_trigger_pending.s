	.syntax unified

	thumb_func_start sound_channel_trigger_pending
sound_channel_trigger_pending: @ 0x08073DF4
	push {lr}
	adds r2, r0, #0
	ldr r1, [r2, #0xc]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08073E14
	movs r0, #2
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r2, #0xc]
	ldr r1, [r2, #8]
	subs r1, #0x20
	adds r0, r2, #0
	bl sound_channel_play
_08073E14:
	pop {r0}
	bx r0
_08073E18:
	.byte 0x3E, 0x30, 0x05, 0x21, 0x01, 0x70, 0x70, 0x47
	.syntax divided
