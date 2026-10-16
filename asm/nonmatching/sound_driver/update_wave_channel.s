	.syntax unified

	thumb_func_start update_wave_channel
	.global update_wave_channel
update_wave_channel: @ 0x0807360C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #8]
	cmp r0, #0
	beq _0807364C
	adds r0, r4, #0
	adds r0, #0x6b
	ldrb r0, [r0]
	cmp r0, #0
	beq _0807364C
	adds r0, r4, #0
	adds r0, #0x66
	ldrb r0, [r0]
	cmp r0, #0
	bne _0807364C
	adds r0, r4, #0
	adds r0, #0x50
	ldrb r1, [r0]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _0807364C
	ldr r1, _08073644 @ =0x04000072
	ldr r2, _08073648 @ =0x04000074
	adds r0, r4, #0
	bl update_sound_channel_frequency_080733AC
	b _08073662
	.align 2, 0
_08073644: .4byte 0x04000072
_08073648: .4byte 0x04000074
_0807364C:
	ldr r1, _08073668 @ =0x04000072
	adds r0, r4, #0
	bl update_wave_channel_params
	ldr r1, _0807366C @ =0x04000074
	adds r0, r4, #0
	bl sound_update_channel3_frequency
	adds r0, r4, #0
	bl sound_update_channel_output_routing
_08073662:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08073668: .4byte 0x04000072
_0807366C: .4byte 0x04000074
	.syntax divided
