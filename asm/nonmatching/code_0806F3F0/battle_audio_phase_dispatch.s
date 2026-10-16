	.syntax unified

	thumb_func_start battle_audio_phase_dispatch
battle_audio_phase_dispatch: @ 0x080714B8
	push {r4, lr}
	ldr r1, _080714D0 @ =0x03001800
	ldr r0, [r1, #8]
	adds r4, r1, #0
	cmp r0, #7
	bhi _08071584
	lsls r0, r0, #2
	ldr r1, _080714D4 @ =_080714D8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080714D0: .4byte 0x03001800
_080714D4: .4byte _080714D8
_080714D8: @ jump table
	.4byte _080714F8 @ case 0
	.4byte _08071560 @ case 1
	.4byte _0807150A @ case 2
	.4byte _08071560 @ case 3
	.4byte _0807151E @ case 4
	.4byte _08071560 @ case 5
	.4byte _08071532 @ case 6
	.4byte _08071560 @ case 7
_080714F8:
	movs r0, #1
	movs r1, #0
	movs r2, #0
	bl text_window_init
	movs r0, #0x19
	movs r1, #0x4b
	movs r2, #8
	b _0807154C
_0807150A:
	bl sub_0803FB0C
	movs r0, #0x19
	movs r1, #0x4b
	bl sound_channel_stop_0807175C
	movs r0, #0x17
	movs r1, #0x36
	movs r2, #8
	b _0807154C
_0807151E:
	bl sub_0803FB0C
	movs r0, #0x17
	movs r1, #0x36
	bl sound_channel_stop_0807175C
	movs r0, #0x19
	movs r1, #0x4b
	movs r2, #8
	b _0807154C
_08071532:
	bl sub_0803FB0C
	movs r0, #0x17
	movs r1, #0x33
	bl sound_channel_stop_0807175C
	movs r0, #0x19
	movs r1, #0x4b
	bl sound_channel_stop_0807175C
	movs r0, #0x18
	movs r1, #0x3f
	movs r2, #6
_0807154C:
	bl sound_channel_set_note
	ldr r1, _0807155C @ =0x03001800
	ldr r0, [r1, #8]
	adds r0, #1
	str r0, [r1, #8]
	b _080715C2
	.align 2, 0
_0807155C: .4byte 0x03001800
_08071560:
	ldr r1, _08071580 @ =0x084872DC
	ldr r0, [r4, #8]
	asrs r0, r0, #1
	adds r0, #0xf
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl run_message
	cmp r0, #0
	beq _080715C2
	ldr r0, [r4, #8]
	adds r0, #1
	str r0, [r4, #8]
	b _080715C2
	.align 2, 0
_08071580: .4byte 0x084872DC
_08071584:
	movs r0, #0
	str r0, [r1, #8]
	movs r0, #0x16
	movs r1, #0x27
	movs r2, #8
	bl sound_channel_set_note
	movs r0, #0x17
	movs r1, #0x33
	movs r2, #8
	bl sound_channel_set_note
	movs r0, #0x19
	movs r1, #0x4b
	movs r2, #8
	bl sound_channel_set_note
	movs r0, #3
	movs r1, #0
	movs r2, #0
	bl sub_08071C40
	movs r0, #4
	movs r1, #0xb
	movs r2, #0
	bl sub_08071C40
	ldr r1, _080715C8 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_080715C2:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080715C8: .4byte 0x0300137C
	.syntax divided
