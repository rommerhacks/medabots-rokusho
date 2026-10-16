	.syntax unified

	thumb_func_start sound_channel_check_note_change
sound_channel_check_note_change: @ 0x0807337C
	push {r4, r5, lr}
	adds r2, r0, #0
	adds r5, r1, #0
	adds r4, r2, #0
	adds r4, #0x50
	ldrb r3, [r4]
	movs r0, #1
	ands r0, r3
	cmp r0, #0
	beq _080733A6
	adds r0, r2, #0
	adds r0, #0x69
	ldrb r0, [r0]
	movs r2, #0x80
	lsls r2, r2, #8
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r5]
	movs r0, #0xfe
	ands r0, r3
	strb r0, [r4]
_080733A6:
	pop {r4, r5}
	pop {r0}
	bx r0
	.syntax divided
