	.syntax unified

	thumb_func_start sub_0804EBEC
sub_0804EBEC: @ 0x0804EBEC
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r5, _0804EC0C @ =0x030057E0
	ldr r0, _0804EC10 @ =0x00000C93
	adds r0, r0, r5
	mov r8, r0
	ldrb r0, [r0]
	cmp r0, #1
	beq _0804ECC4
	cmp r0, #1
	bgt _0804EC14
	cmp r0, #0
	beq _0804EC1E
	b _0804ED26
	.align 2, 0
_0804EC0C: .4byte 0x030057E0
_0804EC10: .4byte 0x00000C93
_0804EC14:
	cmp r0, #2
	beq _0804ECD8
	cmp r0, #3
	beq _0804ED04
	b _0804ED26
_0804EC1E:
	bl init_cursor_state
	ldr r1, _0804EC5C @ =0x00000C94
	adds r7, r5, r1
	ldrb r0, [r7]
	ldr r2, _0804EC60 @ =0x00000C95
	adds r6, r5, r2
	ldrb r1, [r6]
	bl sub_08047D9C
	movs r1, #0xff
	lsls r1, r1, #8
	mov sb, r1
	ands r0, r1
	asrs r4, r0, #8
	cmp r4, #0
	bne _0804EC64
	movs r0, #6
	bl sub_08047BA8
	ldrb r0, [r6]
	ldrb r1, [r7]
	bl sub_08047BEC
	adds r1, r0, #0
	movs r0, #0
	bl copy_string_to_text_buffer
	movs r0, #1
	b _0804ECBE
	.align 2, 0
_0804EC5C: .4byte 0x00000C94
_0804EC60: .4byte 0x00000C95
_0804EC64:
	movs r0, #5
	bl sub_08047BA8
	ldr r1, _0804ECB8 @ =0x00000C96
	adds r0, r5, r1
	ldrb r0, [r0]
	subs r1, r4, r0
	adds r5, r0, #0
	cmp r1, #0
	bge _0804EC7A
	adds r5, r4, #0
_0804EC7A:
	ldrb r0, [r7]
	ldrb r1, [r6]
	lsls r2, r5, #0x18
	lsrs r2, r2, #0x18
	bl sub_08047E08
	ldrb r0, [r6]
	ldrb r1, [r7]
	bl sub_08047BEC
	adds r1, r0, #0
	movs r0, #0
	bl copy_string_to_text_buffer
	movs r0, #1
	adds r1, r5, #0
	bl format_number_to_text_buffer
	ldrb r0, [r7]
	ldrb r1, [r6]
	bl sub_08047D9C
	mov r2, sb
	ands r0, r2
	cmp r0, #0
	bne _0804ECBC
	movs r0, #3
	mov r1, r8
	strb r0, [r1]
	b _0804ED26
	.align 2, 0
_0804ECB8: .4byte 0x00000C96
_0804ECBC:
	movs r0, #2
_0804ECBE:
	mov r2, r8
	strb r0, [r2]
	b _0804ED26
_0804ECC4:
	ldr r1, _0804ECD0 @ =0x0847E8C4
	ldr r2, _0804ECD4 @ =0x00000C95
	adds r0, r5, r2
	ldrb r0, [r0]
	adds r0, #0xe
	b _0804ECE2
	.align 2, 0
_0804ECD0: .4byte 0x0847E8C4
_0804ECD4: .4byte 0x00000C95
_0804ECD8:
	ldr r1, _0804ECFC @ =0x0847E8C4
	ldr r2, _0804ED00 @ =0x00000C95
	adds r0, r5, r2
	ldrb r0, [r0]
	adds r0, #0x12
_0804ECE2:
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r3, [r0]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl scene_transition_step_08047C24
	cmp r0, #0
	beq _0804ED26
	bl sub_08050244
	b _0804ED26
	.align 2, 0
_0804ECFC: .4byte 0x0847E8C4
_0804ED00: .4byte 0x00000C95
_0804ED04:
	ldr r1, _0804ED34 @ =0x0847E8C4
	ldr r2, _0804ED38 @ =0x00000C95
	adds r0, r5, r2
	ldrb r0, [r0]
	adds r0, #0x12
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r3, [r0]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl scene_transition_step_08047C24
	cmp r0, #0
	beq _0804ED26
	bl sub_08050244
_0804ED26:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804ED34: .4byte 0x0847E8C4
_0804ED38: .4byte 0x00000C95
	.syntax divided
