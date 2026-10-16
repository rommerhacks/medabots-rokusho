	.syntax unified

	thumb_func_start update_sound_channel_frequency_08073244
update_sound_channel_frequency_08073244: @ 0x08073244
	push {r4, r5, lr}
	adds r2, r0, #0
	adds r4, r1, #0
	adds r3, r2, #0
	adds r3, #0x50
	ldrb r1, [r3]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08073282
	adds r0, r2, #0
	adds r0, #0x66
	ldrb r1, [r0]
	subs r0, #0x26
	ldrh r0, [r0]
	adds r5, r1, #0
	muls r5, r0, r5
	adds r0, r5, #0
	ldr r5, _08073288 @ =0xFFFFF000
	adds r1, r5, #0
	ands r0, r1
	adds r1, r2, #0
	adds r1, #0x4a
	strh r0, [r1]
	strh r0, [r4]
	ldrb r1, [r3]
	movs r0, #0xfd
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	strb r0, [r3]
_08073282:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08073288: .4byte 0xFFFFF000
	.syntax divided
