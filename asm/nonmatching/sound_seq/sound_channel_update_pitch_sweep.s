	.syntax unified

	thumb_func_start sound_channel_update_pitch_sweep
sound_channel_update_pitch_sweep: @ 0x080726A0
	push {r4, lr}
	adds r3, r0, #0
	adds r2, r3, #0
	adds r2, #0x44
	movs r1, #0
	ldrsh r0, [r2, r1]
	cmp r0, #0
	beq _08072702
	ldr r0, [r3, #0x3c]
	adds r4, r3, #0
	adds r4, #0x40
	cmp r0, #0
	beq _080726F0
	subs r0, #1
	str r0, [r3, #0x3c]
	cmp r0, #0
	beq _080726F0
	ldrh r0, [r2]
	ldrh r1, [r4]
	adds r0, r0, r1
	strh r0, [r4]
	adds r0, r3, #0
	adds r0, #0x4a
	ldrh r2, [r0]
	adds r0, #0x1c
	ldrb r1, [r0]
	ldrh r0, [r4]
	muls r0, r1, r0
	movs r1, #0xf0
	lsls r1, r1, #8
	ands r0, r1
	cmp r2, r0
	beq _08072702
	adds r2, r3, #0
	adds r2, #0x50
	ldrb r1, [r2]
	movs r0, #2
	orrs r0, r1
	strb r0, [r2]
	b _08072702
_080726F0:
	adds r0, r3, #0
	adds r0, #0x42
	ldrh r0, [r0]
	movs r1, #0
	strh r0, [r4]
	strh r1, [r2]
	adds r0, r3, #0
	bl sound_channel_finish_and_callback
_08072702:
	pop {r4}
	pop {r0}
	bx r0
	.syntax divided
