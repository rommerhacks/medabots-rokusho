	.syntax unified

	thumb_func_start sub_080724A0
sub_080724A0: @ 0x080724A0
	push {lr}
	adds r2, r0, #0
	adds r1, r2, #0
	adds r1, #0x5f
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _080724BE
	adds r0, r2, #0
	bl sound_channel_update_position
	b _080724E4
_080724BE:
	adds r1, r2, #0
	adds r1, #0x66
	adds r0, r2, #0
	adds r0, #0x60
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldrb r3, [r1]
	adds r0, r0, r3
	cmp r0, #0
	bge _080724D6
	movs r0, #0
_080724D6:
	strb r0, [r1]
	adds r0, r2, #0
	adds r0, #0x50
	ldrb r1, [r0]
	movs r2, #2
	orrs r1, r2
	strb r1, [r0]
_080724E4:
	pop {r0}
	bx r0
	.syntax divided
