	.syntax unified

	thumb_func_start sound_channel1_update
	.global sound_channel1_update
sound_channel1_update: @ 0x08073528
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #8]
	cmp r0, #0
	beq _08073568
	adds r0, r4, #0
	adds r0, #0x6b
	ldrb r0, [r0]
	cmp r0, #0
	beq _08073568
	adds r0, r4, #0
	adds r0, #0x66
	ldrb r0, [r0]
	cmp r0, #0
	bne _08073568
	adds r0, r4, #0
	adds r0, #0x50
	ldrb r1, [r0]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _08073568
	ldr r1, _08073560 @ =0x04000062
	ldr r2, _08073564 @ =0x04000064
	adds r0, r4, #0
	bl update_sound_channel_frequency_080733AC
	b _08073588
	.align 2, 0
_08073560: .4byte 0x04000062
_08073564: .4byte 0x04000064
_08073568:
	ldr r1, _08073590 @ =0x04000060
	adds r0, r4, #0
	bl sound_channel_read_pending_note
	ldr r1, _08073594 @ =0x04000062
	ldr r2, _08073598 @ =0x04000065
	adds r0, r4, #0
	bl sound_channel_set_note_attributes
	ldr r1, _0807359C @ =0x04000064
	adds r0, r4, #0
	bl sound_channel_update_frequency
	adds r0, r4, #0
	bl sound_update_channel_output_routing
_08073588:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08073590: .4byte 0x04000060
_08073594: .4byte 0x04000062
_08073598: .4byte 0x04000065
_0807359C: .4byte 0x04000064
	.syntax divided
