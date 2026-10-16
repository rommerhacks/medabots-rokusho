	.syntax unified

	thumb_func_start sound_channel_play
sound_channel_play: @ 0x08073BF8
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r6, r1, #0
	bl sound_channel_stop_08073B0C
	adds r0, r4, #0
	adds r0, #0x3c
	ldrb r0, [r0]
	cmp r0, #0
	beq _08073C34
	adds r0, r4, #0
	bl sound_configure_mixing_channel
	adds r5, r4, #0
	adds r5, #0x3a
	ldrb r0, [r5]
	adds r2, r6, #0
	adds r2, #0x10
	ldr r1, [r4]
	adds r1, r1, r2
	bl configure_sound_channel
	ldr r1, _08073C3C @ =0x084873C0
	ldrb r0, [r5]
	subs r0, #1
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	ldr r0, [r4, #0x10]
	str r0, [r1]
_08073C34:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08073C3C: .4byte 0x084873C0
	.syntax divided
