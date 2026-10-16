	.syntax unified

	thumb_func_start sub_0804E9CC
sub_0804E9CC: @ 0x0804E9CC
	push {r4, r5, r6, r7, lr}
	ldr r5, _0804E9E4 @ =0x030057E0
	ldr r0, _0804E9E8 @ =0x00000C93
	adds r7, r5, r0
	ldrb r0, [r7]
	cmp r0, #1
	beq _0804EA7A
	cmp r0, #1
	bgt _0804E9EC
	cmp r0, #0
	beq _0804E9F6
	b _0804EAB6
	.align 2, 0
_0804E9E4: .4byte 0x030057E0
_0804E9E8: .4byte 0x00000C93
_0804E9EC:
	cmp r0, #2
	beq _0804EA84
	cmp r0, #3
	beq _0804EAA0
	b _0804EAB6
_0804E9F6:
	bl init_cursor_state
	ldr r1, _0804EA24 @ =0x00000C94
	adds r6, r5, r1
	ldrb r0, [r6]
	bl sub_08047D8C
	adds r4, r0, #0
	cmp r4, #0
	bne _0804EA28
	movs r0, #6
	bl sub_08047BA8
	ldrb r0, [r6]
	bl sub_08048088
	adds r1, r0, #0
	movs r0, #0
	bl copy_string_to_text_buffer
	movs r0, #1
	strb r0, [r7]
	b _0804EAB6
	.align 2, 0
_0804EA24: .4byte 0x00000C94
_0804EA28:
	movs r0, #5
	bl sub_08047BA8
	ldr r1, _0804EA70 @ =0x00000C95
	adds r0, r5, r1
	ldrb r0, [r0]
	subs r1, r4, r0
	adds r5, r0, #0
	cmp r1, #0
	bge _0804EA3E
	adds r5, r4, #0
_0804EA3E:
	ldrb r0, [r6]
	lsls r1, r5, #0x18
	lsrs r1, r1, #0x18
	bl sub_08047DD8
	ldrb r0, [r6]
	bl sub_08048088
	adds r1, r0, #0
	movs r0, #0
	bl copy_string_to_text_buffer
	movs r0, #1
	adds r1, r5, #0
	bl format_number_to_text_buffer
	ldrb r0, [r6]
	bl sub_08047D8C
	adds r4, r0, #0
	cmp r4, #0
	bne _0804EA74
	movs r0, #3
	strb r0, [r7]
	b _0804EAB6
	.align 2, 0
_0804EA70: .4byte 0x00000C95
_0804EA74:
	movs r0, #2
	strb r0, [r7]
	b _0804EAB6
_0804EA7A:
	ldr r0, _0804EA80 @ =0x0847E8C4
	ldr r3, [r0, #8]
	b _0804EA88
	.align 2, 0
_0804EA80: .4byte 0x0847E8C4
_0804EA84:
	ldr r0, _0804EA9C @ =0x0847E8C4
	ldr r3, [r0, #0xc]
_0804EA88:
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl scene_transition_step_08047C24
	cmp r0, #0
	beq _0804EAB6
	bl map_script_command_done
	b _0804EAB6
	.align 2, 0
_0804EA9C: .4byte 0x0847E8C4
_0804EAA0:
	ldr r0, _0804EABC @ =0x0847E8C4
	ldr r3, [r0, #0x10]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl scene_transition_step_08047C24
	cmp r0, #0
	beq _0804EAB6
	bl map_script_command_done
_0804EAB6:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804EABC: .4byte 0x0847E8C4
	.syntax divided
