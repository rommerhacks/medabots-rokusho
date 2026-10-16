	.syntax unified

	thumb_func_start sound_channel_set_note_attributes
sound_channel_set_note_attributes: @ 0x08073178
	push {r4, r5, r6, lr}
	adds r3, r0, #0
	adds r5, r1, #0
	adds r4, r2, #0
	adds r2, r3, #0
	adds r2, #0x50
	ldrb r1, [r2]
	movs r0, #6
	ands r0, r1
	cmp r0, #0
	beq _080731CA
	adds r0, r3, #0
	adds r0, #0x66
	ldrb r1, [r0]
	subs r0, #0x26
	ldrh r0, [r0]
	muls r1, r0, r1
	ldr r6, _080731D0 @ =0xFFFFF000
	adds r0, r6, #0
	ands r1, r0
	adds r0, r3, #0
	adds r0, #0x4a
	strh r1, [r0]
	adds r0, #0x1d
	ldrb r0, [r0]
	orrs r0, r1
	movs r3, #0x80
	lsls r3, r3, #4
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r5]
	ldrb r0, [r4]
	movs r1, #0x80
	orrs r0, r1
	strb r0, [r4]
	ldrb r1, [r2]
	movs r0, #0xf9
	ands r0, r1
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r2]
_080731CA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080731D0: .4byte 0xFFFFF000
	.syntax divided
