	.syntax unified

	thumb_func_start sub_08070FEC
sub_08070FEC: @ 0x08070FEC
	push {r4, r5, lr}
	ldr r4, _08071004 @ =0x03001800
	ldr r0, [r4, #8]
	adds r5, r4, #0
	cmp r0, #0xf
	bls _08070FFA
	b _0807112C
_08070FFA:
	lsls r0, r0, #2
	ldr r1, _08071008 @ =_0807100C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08071004: .4byte 0x03001800
_08071008: .4byte _0807100C
_0807100C: @ jump table
	.4byte _0807104C @ case 0
	.4byte _0807110C @ case 1
	.4byte _0807105E @ case 2
	.4byte _0807110C @ case 3
	.4byte _08071072 @ case 4
	.4byte _0807110C @ case 5
	.4byte _08071086 @ case 6
	.4byte _0807110C @ case 7
	.4byte _0807109A @ case 8
	.4byte _0807110C @ case 9
	.4byte _080710AE @ case 10
	.4byte _0807110C @ case 11
	.4byte _080710C2 @ case 12
	.4byte _0807110C @ case 13
	.4byte _080710D6 @ case 14
	.4byte _0807110C @ case 15
_0807104C:
	movs r0, #1
	movs r1, #0
	movs r2, #0
	bl text_window_init
	movs r0, #0x19
	movs r1, #0x4b
	movs r2, #8
	b _080710F8
_0807105E:
	bl sub_0803FB0C
	movs r0, #0x19
	movs r1, #0x4b
	bl sound_channel_stop_0807175C
	movs r0, #0x16
	movs r1, #0x2d
	movs r2, #8
	b _080710F8
_08071072:
	bl sub_0803FB0C
	movs r0, #0x16
	movs r1, #0x2d
	bl sound_channel_stop_0807175C
	movs r0, #0x19
	movs r1, #0x4e
	movs r2, #8
	b _080710F8
_08071086:
	bl sub_0803FB0C
	movs r0, #0x19
	movs r1, #0x4b
	bl sound_channel_stop_0807175C
	movs r0, #0x17
	movs r1, #0x36
	movs r2, #8
	b _080710F8
_0807109A:
	bl sub_0803FB0C
	movs r0, #0x17
	movs r1, #0x36
	bl sound_channel_stop_0807175C
	movs r0, #0x19
	movs r1, #0x51
	movs r2, #8
	b _080710F8
_080710AE:
	bl sub_0803FB0C
	movs r0, #0x19
	movs r1, #0x4b
	bl sound_channel_stop_0807175C
	movs r0, #0x16
	movs r1, #0x2d
	movs r2, #8
	b _080710F8
_080710C2:
	bl sub_0803FB0C
	movs r0, #0x16
	movs r1, #0x2d
	bl sound_channel_stop_0807175C
	movs r0, #0x19
	movs r1, #0x4b
	movs r2, #8
	b _080710F8
_080710D6:
	bl sub_0803FB0C
	movs r0, #0x16
	movs r1, #0x27
	bl sound_channel_stop_0807175C
	movs r0, #0x17
	movs r1, #0x33
	bl sound_channel_stop_0807175C
	movs r0, #0x19
	movs r1, #0x4b
	bl sound_channel_stop_0807175C
	movs r0, #0x18
	movs r1, #0x3f
	movs r2, #6
_080710F8:
	bl sound_channel_set_note
	ldr r1, _08071108 @ =0x03001800
	ldr r0, [r1, #8]
	adds r0, #1
	str r0, [r1, #8]
	b _08071144
	.align 2, 0
_08071108: .4byte 0x03001800
_0807110C:
	ldr r1, _08071128 @ =0x084872DC
	ldr r0, [r5, #8]
	asrs r0, r0, #1
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl run_message
	cmp r0, #0
	beq _08071144
	ldr r0, [r5, #8]
	adds r0, #1
	str r0, [r5, #8]
	b _08071144
	.align 2, 0
_08071128: .4byte 0x084872DC
_0807112C:
	movs r0, #0x18
	movs r1, #0x3f
	movs r2, #0xc
	bl sound_channel_set_note
	movs r0, #0
	str r0, [r4, #8]
	movs r0, #0xc
	strh r0, [r4, #4]
	ldr r1, _0807114C @ =0x0300137C
	movs r0, #2
	str r0, [r1]
_08071144:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807114C: .4byte 0x0300137C
_08071150:
	.byte 0x81, 0xB0, 0x00, 0x20, 0x00, 0x90, 0x08, 0x49, 0x68, 0x46, 0x08, 0x60, 0x07, 0x48, 0x48, 0x60
	.byte 0x07, 0x48, 0x88, 0x60, 0x88, 0x68, 0x07, 0x49, 0x0D, 0x20, 0x88, 0x80, 0x06, 0x49, 0x05, 0x20
	.byte 0x08, 0x60, 0x01, 0xB0, 0x70, 0x47, 0x00, 0x00, 0xD4, 0x00, 0x00, 0x04, 0x30, 0x2C, 0x00, 0x03
	.byte 0x00, 0x08, 0x00, 0x85, 0x00, 0x18, 0x00, 0x03, 0x7C, 0x13, 0x00, 0x03
	.syntax divided
