	.syntax unified

	thumb_func_start sound_engine_update_all_channels
	.global sound_engine_update_all_channels
sound_engine_update_all_channels: @ 0x08072F1C
	push {r4, r5, lr}
	ldr r0, _08072F54 @ =0x03007014
	ldr r0, [r0]
	ldr r1, _08072F58 @ =0x000005E4
	adds r0, r0, r1
	ldr r4, [r0]
	cmp r4, #0
	beq _08072FB6
_08072F2C:
	ldr r5, [r4, #4]
	ldr r0, _08072F54 @ =0x03007014
	ldr r0, [r0]
	ldr r2, _08072F5C @ =0x0000072C
	adds r0, r0, r2
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08072FA0
	adds r0, r4, #0
	adds r0, #0x51
	ldrb r0, [r0]
	cmp r0, #0xc
	bhi _08072F98
	lsls r0, r0, #2
	ldr r1, _08072F60 @ =_08072F64
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08072F54: .4byte 0x03007014
_08072F58: .4byte 0x000005E4
_08072F5C: .4byte 0x0000072C
_08072F60: .4byte _08072F64
_08072F64: @ jump table
	.4byte _08072FA6 @ case 0
	.4byte _08072FA6 @ case 1
	.4byte _08072FA6 @ case 2
	.4byte _08072FA6 @ case 3
	.4byte _08072F98 @ case 4
	.4byte _08072F98 @ case 5
	.4byte _08072F98 @ case 6
	.4byte _08072F98 @ case 7
	.4byte _08072FA6 @ case 8
	.4byte _08072FA6 @ case 9
	.4byte _08072F98 @ case 10
	.4byte _08072F98 @ case 11
	.4byte _08072FA6 @ case 12
_08072F98:
	adds r0, r4, #0
	bl sound_channel_advance_sequence
	b _08072FA6
_08072FA0:
	adds r0, r4, #0
	bl sound_channel_advance_sequence
_08072FA6:
	adds r4, r5, #0
	ldr r0, _08072FD0 @ =0x03007014
	ldr r0, [r0]
	ldr r1, _08072FD4 @ =0x000005E4
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r4, r0
	bne _08072F2C
_08072FB6:
	ldr r0, _08072FD0 @ =0x03007014
	ldr r4, [r0]
	movs r2, #0xe8
	lsls r2, r2, #1
	adds r1, r4, r2
	ldr r0, [r1, #0x14]
	cmp r0, #0
	beq _08072FD8
	adds r0, r1, #0
	bl sound_channel1_update
	b _08072FE6
	.align 2, 0
_08072FD0: .4byte 0x03007014
_08072FD4: .4byte 0x000005E4
_08072FD8:
	bl sound_is_paused
	cmp r0, #0
	bne _08072FE6
	adds r0, r4, #0
	bl sound_channel1_update
_08072FE6:
	movs r0, #0x91
	lsls r0, r0, #2
	adds r1, r4, r0
	ldr r0, [r1, #0x14]
	cmp r0, #0
	beq _08072FFA
	adds r0, r1, #0
	bl sound_channel_process_tone
	b _0807300A
_08072FFA:
	bl sound_is_paused
	cmp r0, #0
	bne _0807300A
	adds r0, r4, #0
	adds r0, #0x74
	bl sound_channel_process_tone
_0807300A:
	movs r2, #0xae
	lsls r2, r2, #2
	adds r1, r4, r2
	ldr r0, [r1, #0x14]
	cmp r0, #0
	beq _0807301E
	adds r0, r1, #0
	bl update_wave_channel
	b _0807302E
_0807301E:
	bl sound_is_paused
	cmp r0, #0
	bne _0807302E
	adds r0, r4, #0
	adds r0, #0xe8
	bl update_wave_channel
_0807302E:
	movs r0, #0xcb
	lsls r0, r0, #2
	adds r1, r4, r0
	ldr r0, [r1, #0x14]
	cmp r0, #0
	bne _0807306C
	bl sound_is_paused
	cmp r0, #0
	bne _08073082
	movs r2, #0xae
	lsls r2, r2, #3
	adds r1, r4, r2
	ldr r0, [r1, #0x14]
	cmp r0, #0
	beq _08073078
	ldr r2, _08073074 @ =0x00000414
	adds r0, r4, r2
	ldr r0, [r0, #0x14]
	cmp r0, #0
	beq _08073078
	adds r2, #0x63
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #2
	bne _08073078
	adds r2, #0x85
	adds r0, r4, r2
	ldr r0, [r0, #0x14]
	cmp r0, #0
	beq _08073078
_0807306C:
	adds r0, r1, #0
	bl sound_update_channel_3
	b _08073082
	.align 2, 0
_08073074: .4byte 0x00000414
_08073078:
	movs r1, #0xae
	lsls r1, r1, #1
	adds r0, r4, r1
	bl sound_update_channel_3
_08073082:
	movs r2, #0x91
	lsls r2, r2, #3
	adds r1, r4, r2
	ldr r0, [r1, #0x14]
	cmp r0, #0
	beq _08073096
	adds r0, r1, #0
	bl sound_channel_6_update_note
	b _080730A8
_08073096:
	bl sound_is_paused
	cmp r0, #0
	bne _080730A8
	movs r1, #0xe8
	lsls r1, r1, #2
	adds r0, r4, r1
	bl sound_channel_6_update_note
_080730A8:
	ldr r2, _080730BC @ =0x000004FC
	adds r1, r4, r2
	ldr r0, [r1, #0x14]
	cmp r0, #0
	beq _080730C0
	adds r0, r1, #0
	bl sound_channel_7_update_note
	b _080730D0
	.align 2, 0
_080730BC: .4byte 0x000004FC
_080730C0:
	bl sound_is_paused
	cmp r0, #0
	bne _080730D0
	ldr r1, _080730F8 @ =0x00000414
	adds r0, r4, r1
	bl sound_channel_7_update_note
_080730D0:
	bl sound_is_paused
	cmp r0, #0
	bne _080730EE
	adds r0, r4, #0
	bl sub_080740D4
	adds r0, r4, #0
	adds r0, #0x74
	bl sub_080740D4
	adds r0, r4, #0
	adds r0, #0xe8
	bl sub_080740D4
_080730EE:
	bl sound_update_master_volume
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080730F8: .4byte 0x00000414
	.syntax divided
