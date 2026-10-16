	.syntax unified

	thumb_func_start sound_channel_init_vibrato
sound_channel_init_vibrato: @ 0x08072394
	push {r4, lr}
	adds r4, r0, #0
	bl sound_channel_check_and_advance
	cmp r0, #0
	bne _080723CE
	adds r1, r4, #0
	adds r1, #0x5c
	ldrb r0, [r1]
	lsrs r0, r0, #4
	adds r2, r4, #0
	adds r2, #0x5f
	strb r0, [r2]
	cmp r0, #0
	bne _080723BA
	adds r0, r4, #0
	bl sound_channel_update_position
	b _080723CE
_080723BA:
	ldrb r1, [r1]
	movs r0, #0xf
	ands r0, r1
	rsbs r0, r0, #0
	adds r1, r4, #0
	adds r1, #0x60
	strb r0, [r1]
	adds r1, #1
	movs r0, #3
	strb r0, [r1]
_080723CE:
	pop {r4}
	pop {r0}
	bx r0
	.syntax divided
