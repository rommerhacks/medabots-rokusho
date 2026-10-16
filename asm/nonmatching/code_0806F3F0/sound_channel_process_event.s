	.syntax unified

	thumb_func_start sound_channel_process_event
sound_channel_process_event: @ 0x08072BF0
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x14]
	cmp r0, #0
	bne _08072BFC
	b _08072DFE
_08072BFC:
	ldrb r2, [r0]
	adds r0, #1
	str r0, [r4, #0x14]
	adds r0, r2, #0
	subs r0, #0xe0
	cmp r0, #0x1f
	bls _08072C0C
	b _08072D8C
_08072C0C:
	lsls r0, r0, #2
	ldr r1, _08072C18 @ =_08072C1C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08072C18: .4byte _08072C1C
_08072C1C: @ jump table
	.4byte _08072DB6 @ case 0
	.4byte _08072C9C @ case 1
	.4byte _08072CAC @ case 2
	.4byte _08072CBC @ case 3
	.4byte _08072CC4 @ case 4
	.4byte _08072CCE @ case 5
	.4byte _08072CD8 @ case 6
	.4byte _08072CE2 @ case 7
	.4byte _08072CEC @ case 8
	.4byte _08072CF4 @ case 9
	.4byte _08072CFC @ case 10
	.4byte _08072D04 @ case 11
	.4byte _08072D8C @ case 12
	.4byte _08072D8C @ case 13
	.4byte _08072D8C @ case 14
	.4byte _08072D8C @ case 15
	.4byte _08072D0C @ case 16
	.4byte _08072D14 @ case 17
	.4byte _08072D1C @ case 18
	.4byte _08072D24 @ case 19
	.4byte _08072D2C @ case 20
	.4byte _08072D34 @ case 21
	.4byte _08072D3C @ case 22
	.4byte _08072D44 @ case 23
	.4byte _08072D4C @ case 24
	.4byte _08072D54 @ case 25
	.4byte _08072D5C @ case 26
	.4byte _08072D64 @ case 27
	.4byte _08072D6C @ case 28
	.4byte _08072D74 @ case 29
	.4byte _08072D7C @ case 30
	.4byte _08072D84 @ case 31
_08072C9C:
	ldr r0, [r4, #0x14]
	ldrb r1, [r0]
	adds r0, #1
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl sub_080729A0
	b _08072DFE
_08072CAC:
	ldr r0, [r4, #0x14]
	ldrb r1, [r0]
	adds r0, #1
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl sub_080729A8
	b _08072DFE
_08072CBC:
	adds r0, r4, #0
	bl sub_080729BC
	b _08072DFE
_08072CC4:
	adds r0, r4, #0
	movs r1, #0
	bl sub_080729D8
	b _08072DFE
_08072CCE:
	adds r0, r4, #0
	movs r1, #0x40
	bl sub_080729D8
	b _08072DFE
_08072CD8:
	adds r0, r4, #0
	movs r1, #0x80
	bl sub_080729D8
	b _08072DFE
_08072CE2:
	adds r0, r4, #0
	movs r1, #0xc0
	bl sub_080729D8
	b _08072DFE
_08072CEC:
	adds r0, r4, #0
	bl sub_080729EC
	b _08072DFE
_08072CF4:
	adds r0, r4, #0
	bl sub_080729FC
	b _08072DFE
_08072CFC:
	adds r0, r4, #0
	bl sub_08072A18
	b _08072DFE
_08072D04:
	adds r0, r4, #0
	bl sub_08072A34
	b _08072DFE
_08072D0C:
	adds r0, r4, #0
	bl sub_08072A40
	b _08072DFE
_08072D14:
	adds r0, r4, #0
	bl sub_08072A54
	b _08072DFE
_08072D1C:
	adds r0, r4, #0
	bl sub_08072A6C
	b _08072DFE
_08072D24:
	adds r0, r4, #0
	bl sub_08072A80
	b _08072DFE
_08072D2C:
	adds r0, r4, #0
	bl stream_read_u32_to_field
	b _08072DFE
_08072D34:
	adds r0, r4, #0
	bl stream_read_and_shift_u32
	b _08072DFE
_08072D3C:
	adds r0, r4, #0
	bl sub_08072ABC
	b _08072DFE
_08072D44:
	adds r0, r4, #0
	bl sub_08072AC4
	b _08072DFE
_08072D4C:
	adds r0, r4, #0
	bl sub_08072AEC
	b _08072DFE
_08072D54:
	adds r0, r4, #0
	bl sub_08072AFC
	b _08072DFE
_08072D5C:
	adds r0, r4, #0
	bl sub_08072B28
	b _08072DFE
_08072D64:
	adds r0, r4, #0
	bl sound_read_envelope_params
	b _08072DFE
_08072D6C:
	adds r0, r4, #0
	bl sound_channel_enable
	b _08072DFE
_08072D74:
	adds r0, r4, #0
	bl sound_channel_disable
	b _08072DFE
_08072D7C:
	adds r0, r4, #0
	bl sub_08072BD4
	b _08072DFE
_08072D84:
	adds r0, r4, #0
	bl sub_08072BE4
	b _08072DFE
_08072D8C:
	movs r0, #0xf0
	ands r0, r2
	cmp r0, #0xa0
	beq _08072DFE
	cmp r0, #0xa0
	bgt _08072DA2
	cmp r0, #0x80
	beq _08072DB6
	cmp r0, #0x90
	beq _08072DFE
	b _08072DF6
_08072DA2:
	cmp r0, #0xc0
	beq _08072DFE
	cmp r0, #0xc0
	bgt _08072DB0
	cmp r0, #0xb0
	beq _08072DFE
	b _08072DF6
_08072DB0:
	cmp r0, #0xd0
	beq _08072DBE
	b _08072DF6
_08072DB6:
	adds r0, r4, #0
	bl sub_08072948
	b _08072DFE
_08072DBE:
	movs r0, #0xf
	ands r2, r0
	adds r0, r4, #0
	adds r1, r2, #0
	bl sub_08072984
	adds r0, r4, #0
	adds r0, #0x63
	ldrb r0, [r0]
	cmp r0, #1
	bne _08072DFE
	adds r0, r4, #0
	adds r0, #0x64
	ldrb r0, [r0]
	cmp r0, #3
	bne _08072DFE
	ldr r0, [r4, #0x24]
	cmp r0, #0
	bne _08072DFE
	ldr r0, [r4, #0x2c]
	str r0, [r4, #0x28]
	adds r2, r4, #0
	adds r2, #0x50
	ldrb r1, [r2]
	movs r0, #0x50
	orrs r0, r1
	strb r0, [r2]
	b _08072DFE
_08072DF6:
	adds r0, r4, #0
	adds r1, r2, #0
	bl sound_channel_update_note_08072798
_08072DFE:
	pop {r4}
	pop {r0}
	bx r0
	.syntax divided
