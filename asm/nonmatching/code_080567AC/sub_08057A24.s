	.syntax unified

	thumb_func_start sub_08057A24
sub_08057A24: @ 0x08057A24
	push {lr}
	ldr r0, _08057A48 @ =0x030064A0
	adds r1, r0, #0
	adds r1, #0x65
	ldrb r1, [r1]
	cmp r1, #0
	bne _08057A78
	movs r2, #0x55
	adds r0, #0x70
	ldrb r0, [r0]
	cmp r0, #5
	bls _08057A3E
	b _08057B4E
_08057A3E:
	lsls r0, r0, #2
	ldr r1, _08057A4C @ =_08057A50
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08057A48: .4byte 0x030064A0
_08057A4C: .4byte _08057A50
_08057A50: @ jump table
	.4byte _08057A68 @ case 0
	.4byte _08057AF8 @ case 1
	.4byte _08057B0A @ case 2
	.4byte _08057B1C @ case 3
	.4byte _08057B2E @ case 4
	.4byte _08057A70 @ case 5
_08057A68:
	adds r0, r2, #0
	bl sub_08047BDC
	b _08057B00
_08057A70:
	adds r0, r2, #0
	bl sub_08047BDC
	b _08057B00
_08057A78:
	cmp r1, #2
	bne _08057ABC
	movs r2, #0xb
	adds r0, #0x70
	ldrb r0, [r0]
	cmp r0, #5
	bhi _08057B4E
	lsls r0, r0, #2
	ldr r1, _08057A90 @ =_08057A94
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08057A90: .4byte _08057A94
_08057A94: @ jump table
	.4byte _08057AAC @ case 0
	.4byte _08057AF8 @ case 1
	.4byte _08057B0A @ case 2
	.4byte _08057B1C @ case 3
	.4byte _08057B2E @ case 4
	.4byte _08057AB4 @ case 5
_08057AAC:
	adds r0, r2, #0
	bl sub_08047BDC
	b _08057B00
_08057AB4:
	adds r0, r2, #0
	bl sub_08047BDC
	b _08057B00
_08057ABC:
	cmp r1, #3
	bne _08057B4E
	movs r2, #0x6b
	adds r0, #0x70
	ldrb r0, [r0]
	cmp r0, #5
	bhi _08057B4E
	lsls r0, r0, #2
	ldr r1, _08057AD4 @ =_08057AD8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08057AD4: .4byte _08057AD8
_08057AD8: @ jump table
	.4byte _08057AF0 @ case 0
	.4byte _08057AF8 @ case 1
	.4byte _08057B0A @ case 2
	.4byte _08057B1C @ case 3
	.4byte _08057B2E @ case 4
	.4byte _08057B40 @ case 5
_08057AF0:
	adds r0, r2, #0
	bl sub_08047BDC
	b _08057B00
_08057AF8:
	movs r0, #0
	adds r1, r2, #0
	bl sub_08047BEC
_08057B00:
	adds r1, r0, #0
	movs r0, #0
	bl copy_string_to_text_buffer
	b _08057B4E
_08057B0A:
	movs r0, #1
	adds r1, r2, #0
	bl sub_08047BEC
	adds r1, r0, #0
	movs r0, #1
	bl copy_string_to_text_buffer
	b _08057B4E
_08057B1C:
	movs r0, #2
	adds r1, r2, #0
	bl sub_08047BEC
	adds r1, r0, #0
	movs r0, #2
	bl copy_string_to_text_buffer
	b _08057B4E
_08057B2E:
	movs r0, #3
	adds r1, r2, #0
	bl sub_08047BEC
	adds r1, r0, #0
	movs r0, #3
	bl copy_string_to_text_buffer
	b _08057B4E
_08057B40:
	adds r0, r2, #0
	bl sub_08047BDC
	adds r1, r0, #0
	movs r0, #0
	bl copy_string_to_text_buffer
_08057B4E:
	ldr r0, _08057B64 @ =0x030064A0
	adds r0, #0x70
	ldrb r0, [r0]
	cmp r0, #0
	bne _08057B5C
	bl init_cursor_state
_08057B5C:
	bl sub_0804A1C4
	pop {r0}
	bx r0
	.align 2, 0
_08057B64: .4byte 0x030064A0
	.syntax divided
