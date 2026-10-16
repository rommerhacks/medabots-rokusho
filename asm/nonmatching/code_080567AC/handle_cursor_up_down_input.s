	.syntax unified

	thumb_func_start handle_cursor_up_down_input
handle_cursor_up_down_input: @ 0x08057E24
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _08057EAC @ =0x030057A0
	ldrb r0, [r1, #0x15]
	adds r0, #1
	strb r0, [r1, #0x15]
	ldr r0, _08057EB0 @ =0x03001798
	ldrb r1, [r0]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08057E6C
	movs r0, #2
	bl sub_08047BA8
	ldr r3, _08057EB4 @ =0x030064A0
	adds r2, r3, #0
	adds r2, #0x65
	ldrb r0, [r2]
	subs r0, #1
	strb r0, [r2]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _08057E5A
	subs r0, r4, #1
	strb r0, [r2]
_08057E5A:
	ldr r1, _08057EB8 @ =0x083D5F2C
	ldrb r0, [r2]
	adds r0, r0, r1
	ldrb r1, [r0]
	adds r0, r3, #0
	adds r0, #0x6d
	strb r1, [r0]
	bl update_cursor_sprite_position
_08057E6C:
	ldr r0, _08057EB0 @ =0x03001798
	ldrb r1, [r0]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _08057EA6
	movs r0, #2
	bl sub_08047BA8
	ldr r3, _08057EB4 @ =0x030064A0
	adds r2, r3, #0
	adds r2, #0x65
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	ldrb r0, [r2]
	cmp r0, r4
	blt _08057E94
	movs r0, #0
	strb r0, [r2]
_08057E94:
	ldr r1, _08057EB8 @ =0x083D5F2C
	ldrb r0, [r2]
	adds r0, r0, r1
	ldrb r1, [r0]
	adds r0, r3, #0
	adds r0, #0x6d
	strb r1, [r0]
	bl update_cursor_sprite_position
_08057EA6:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08057EAC: .4byte 0x030057A0
_08057EB0: .4byte 0x03001798
_08057EB4: .4byte 0x030064A0
_08057EB8: .4byte 0x083D5F2C
	.syntax divided
