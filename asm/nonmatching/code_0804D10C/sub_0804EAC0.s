	.syntax unified

	thumb_func_start sub_0804EAC0
sub_0804EAC0: @ 0x0804EAC0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r5, _0804EAE0 @ =0x030057E0
	ldr r0, _0804EAE4 @ =0x00000C93
	adds r0, r0, r5
	mov r8, r0
	ldrb r0, [r0]
	cmp r0, #1
	beq _0804EB9C
	cmp r0, #1
	bgt _0804EAE8
	cmp r0, #0
	beq _0804EAEE
	b _0804EBDA
	.align 2, 0
_0804EAE0: .4byte 0x030057E0
_0804EAE4: .4byte 0x00000C93
_0804EAE8:
	cmp r0, #2
	beq _0804EBB8
	b _0804EBDA
_0804EAEE:
	bl init_cursor_state
	ldr r1, _0804EB2C @ =0x00000C94
	adds r7, r5, r1
	ldrb r0, [r7]
	ldr r2, _0804EB30 @ =0x00000C95
	adds r6, r5, r2
	ldrb r1, [r6]
	bl sub_08047D9C
	movs r1, #0xff
	lsls r1, r1, #8
	ands r1, r0
	asrs r4, r1, #8
	cmp r4, #0x63
	bne _0804EB34
	movs r0, #6
	bl sub_08047BA8
	ldrb r0, [r6]
	ldrb r1, [r7]
	bl sub_08047BEC
	adds r1, r0, #0
	movs r0, #0
	bl copy_string_to_text_buffer
	movs r0, #1
	mov r1, r8
	strb r0, [r1]
	b _0804EBDA
	.align 2, 0
_0804EB2C: .4byte 0x00000C94
_0804EB30: .4byte 0x00000C95
_0804EB34:
	movs r0, #0xe
	bl sub_08047BA8
	ldr r2, _0804EB4C @ =0x00000C96
	adds r0, r5, r2
	ldrb r1, [r0]
	adds r0, r1, r4
	cmp r0, #0x63
	ble _0804EB50
	movs r0, #0x63
	subs r7, r0, r4
	b _0804EB52
	.align 2, 0
_0804EB4C: .4byte 0x00000C96
_0804EB50:
	adds r7, r1, #0
_0804EB52:
	ldr r4, _0804EB8C @ =0x030057E0
	ldr r0, _0804EB90 @ =0x00000C94
	adds r6, r4, r0
	ldrb r0, [r6]
	ldr r1, _0804EB94 @ =0x00000C95
	adds r5, r4, r1
	ldrb r1, [r5]
	lsls r2, r7, #0x18
	lsrs r2, r2, #0x18
	bl sub_08047DF0
	ldrb r0, [r5]
	ldrb r1, [r6]
	bl sub_08047BEC
	adds r1, r0, #0
	movs r0, #0
	bl copy_string_to_text_buffer
	movs r0, #1
	adds r1, r7, #0
	bl format_number_to_text_buffer
	ldr r2, _0804EB98 @ =0x00000C93
	adds r4, r4, r2
	movs r0, #2
	strb r0, [r4]
	b _0804EBDA
	.align 2, 0
_0804EB8C: .4byte 0x030057E0
_0804EB90: .4byte 0x00000C94
_0804EB94: .4byte 0x00000C95
_0804EB98: .4byte 0x00000C93
_0804EB9C:
	ldr r0, _0804EBB4 @ =0x0847E8C4
	ldr r3, [r0, #0x14]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl scene_transition_step_08047C24
	cmp r0, #0
	beq _0804EBDA
	bl map_script_command_done
	b _0804EBDA
	.align 2, 0
_0804EBB4: .4byte 0x0847E8C4
_0804EBB8:
	ldr r1, _0804EBE4 @ =0x0847E8C4
	ldr r2, _0804EBE8 @ =0x00000C95
	adds r0, r5, r2
	ldrb r0, [r0]
	adds r0, #6
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r3, [r0]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl scene_transition_step_08047C24
	cmp r0, #0
	beq _0804EBDA
	bl map_script_command_done
_0804EBDA:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804EBE4: .4byte 0x0847E8C4
_0804EBE8: .4byte 0x00000C95
	.syntax divided
