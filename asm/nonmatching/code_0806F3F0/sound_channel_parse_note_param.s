	.syntax unified

	thumb_func_start sound_channel_parse_note_param
sound_channel_parse_note_param: @ 0x0807229C
	push {lr}
	adds r2, r0, #0
	adds r3, r2, #0
	adds r3, #0x5e
	ldrb r0, [r3]
	lsrs r0, r0, #4
	cmp r0, #0
	bne _080722B4
	adds r0, r2, #0
	bl sub_08072280
	b _080722CE
_080722B4:
	adds r1, r2, #0
	adds r1, #0x5f
	movs r0, #1
	strb r0, [r1]
	ldrb r1, [r3]
	movs r0, #0xf
	ands r0, r1
	adds r1, r2, #0
	adds r1, #0x60
	strb r0, [r1]
	adds r1, #1
	movs r0, #5
	strb r0, [r1]
_080722CE:
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
