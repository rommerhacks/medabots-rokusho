	.syntax unified

	thumb_func_start sound_channel_read_pending_note
sound_channel_read_pending_note: @ 0x08073150
	push {r4, lr}
	adds r2, r0, #0
	adds r4, r1, #0
	adds r1, r2, #0
	adds r1, #0x50
	ldrb r3, [r1]
	movs r0, #8
	ands r0, r3
	cmp r0, #0
	beq _08073172
	adds r0, r2, #0
	adds r0, #0x54
	ldrb r0, [r0]
	strh r0, [r4]
	movs r0, #0xf7
	ands r0, r3
	strb r0, [r1]
_08073172:
	pop {r4}
	pop {r0}
	bx r0
	.syntax divided
