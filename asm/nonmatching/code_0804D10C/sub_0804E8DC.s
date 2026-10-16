	.syntax unified

	thumb_func_start sub_0804E8DC
sub_0804E8DC: @ 0x0804E8DC
	push {r4, r5, r6, r7, lr}
	ldr r5, _0804E8F4 @ =0x030057E0
	ldr r0, _0804E8F8 @ =0x00000C93
	adds r7, r5, r0
	ldrb r0, [r7]
	cmp r0, #1
	beq _0804E990
	cmp r0, #1
	bgt _0804E8FC
	cmp r0, #0
	beq _0804E902
	b _0804E9C2
	.align 2, 0
_0804E8F4: .4byte 0x030057E0
_0804E8F8: .4byte 0x00000C93
_0804E8FC:
	cmp r0, #2
	beq _0804E9AC
	b _0804E9C2
_0804E902:
	bl init_cursor_state
	ldr r1, _0804E930 @ =0x00000C94
	adds r6, r5, r1
	ldrb r0, [r6]
	bl sub_08047D8C
	adds r4, r0, #0
	cmp r4, #0x63
	bne _0804E934
	movs r0, #6
	bl sub_08047BA8
	ldrb r0, [r6]
	bl sub_08048088
	adds r1, r0, #0
	movs r0, #0
	bl copy_string_to_text_buffer
	movs r0, #1
	strb r0, [r7]
	b _0804E9C2
	.align 2, 0
_0804E930: .4byte 0x00000C94
_0804E934:
	movs r0, #0xe
	bl sub_08047BA8
	ldr r1, _0804E94C @ =0x00000C95
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r0, r1, r4
	cmp r0, #0x63
	ble _0804E950
	movs r0, #0x63
	subs r6, r0, r4
	b _0804E952
	.align 2, 0
_0804E94C: .4byte 0x00000C95
_0804E950:
	adds r6, r1, #0
_0804E952:
	ldr r4, _0804E984 @ =0x030057E0
	ldr r0, _0804E988 @ =0x00000C94
	adds r5, r4, r0
	ldrb r0, [r5]
	lsls r1, r6, #0x18
	lsrs r1, r1, #0x18
	bl sub_08047DC0
	ldrb r0, [r5]
	bl sub_08048088
	adds r1, r0, #0
	movs r0, #0
	bl copy_string_to_text_buffer
	movs r0, #1
	adds r1, r6, #0
	bl format_number_to_text_buffer
	ldr r1, _0804E98C @ =0x00000C93
	adds r4, r4, r1
	movs r0, #2
	strb r0, [r4]
	b _0804E9C2
	.align 2, 0
_0804E984: .4byte 0x030057E0
_0804E988: .4byte 0x00000C94
_0804E98C: .4byte 0x00000C93
_0804E990:
	ldr r0, _0804E9A8 @ =0x0847E8C4
	ldr r3, [r0]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl scene_transition_step_08047C24
	cmp r0, #0
	beq _0804E9C2
	bl sub_08050244
	b _0804E9C2
	.align 2, 0
_0804E9A8: .4byte 0x0847E8C4
_0804E9AC:
	ldr r0, _0804E9C8 @ =0x0847E8C4
	ldr r3, [r0, #4]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl scene_transition_step_08047C24
	cmp r0, #0
	beq _0804E9C2
	bl sub_08050244
_0804E9C2:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804E9C8: .4byte 0x0847E8C4
	.syntax divided
