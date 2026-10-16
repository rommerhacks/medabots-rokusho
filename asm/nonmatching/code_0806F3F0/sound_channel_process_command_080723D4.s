	.syntax unified

	thumb_func_start sound_channel_process_command_080723D4
sound_channel_process_command_080723D4: @ 0x080723D4
	push {r4, lr}
	adds r4, r0, #0
	bl sound_channel_check_and_advance
	cmp r0, #0
	bne _0807240C
	adds r2, r4, #0
	adds r2, #0x5b
	ldrb r0, [r2]
	lsrs r0, r0, #4
	adds r1, r4, #0
	adds r1, #0x5f
	strb r0, [r1]
	cmp r0, #0
	bne _080723FA
	adds r0, r4, #0
	bl sound_channel_init_vibrato
	b _0807240C
_080723FA:
	ldrb r1, [r2]
	movs r0, #0xf
	ands r0, r1
	adds r1, r4, #0
	adds r1, #0x60
	strb r0, [r1]
	adds r1, #1
	movs r0, #2
	strb r0, [r1]
_0807240C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
