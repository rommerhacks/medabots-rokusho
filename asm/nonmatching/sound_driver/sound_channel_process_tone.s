	.syntax unified

	thumb_func_start sound_channel_process_tone
	.global sound_channel_process_tone
sound_channel_process_tone: @ 0x080735A0
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #8]
	cmp r0, #0
	beq _080735E0
	adds r0, r4, #0
	adds r0, #0x6b
	ldrb r0, [r0]
	cmp r0, #0
	beq _080735E0
	adds r0, r4, #0
	adds r0, #0x66
	ldrb r0, [r0]
	cmp r0, #0
	bne _080735E0
	adds r0, r4, #0
	adds r0, #0x50
	ldrb r1, [r0]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _080735E0
	ldr r1, _080735D8 @ =0x04000068
	ldr r2, _080735DC @ =0x0400006C
	adds r0, r4, #0
	bl update_sound_channel_frequency_080733AC
	b _080735F8
	.align 2, 0
_080735D8: .4byte 0x04000068
_080735DC: .4byte 0x0400006C
_080735E0:
	ldr r1, _08073600 @ =0x04000068
	ldr r2, _08073604 @ =0x0400006D
	adds r0, r4, #0
	bl sound_channel_set_note_attributes
	ldr r1, _08073608 @ =0x0400006C
	adds r0, r4, #0
	bl sound_channel_update_frequency
	adds r0, r4, #0
	bl sound_update_channel_output_routing
_080735F8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08073600: .4byte 0x04000068
_08073604: .4byte 0x0400006D
_08073608: .4byte 0x0400006C
	.syntax divided
