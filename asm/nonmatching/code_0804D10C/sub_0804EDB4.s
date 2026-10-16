	.syntax unified

	thumb_func_start sub_0804EDB4
sub_0804EDB4: @ 0x0804EDB4
	push {r4, r5, lr}
	ldr r4, _0804EDC8 @ =0x030057E0
	ldr r0, _0804EDCC @ =0x00000C93
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #0
	beq _0804EDD0
	cmp r0, #1
	beq _0804EE20
	b _0804EE36
	.align 2, 0
_0804EDC8: .4byte 0x030057E0
_0804EDCC: .4byte 0x00000C93
_0804EDD0:
	bl init_cursor_state
	ldr r1, _0804EE18 @ =0x00000C94
	adds r0, r4, r1
	ldrb r1, [r0]
	lsls r1, r1, #8
	ldr r2, _0804EE1C @ =0x00000C95
	adds r0, r4, r2
	ldrb r0, [r0]
	orrs r1, r0
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r4, r0, #1
	movs r0, #5
	bl sub_08047BA8
	bl sub_08047D4C
	adds r1, r0, #0
	subs r0, r1, r4
	cmp r0, #0
	bgt _0804EDFE
	adds r4, r1, #0
_0804EDFE:
	movs r0, #5
	bl sub_08047BA8
	adds r0, r4, #0
	bl sub_08047D74
	movs r0, #0
	adds r1, r4, #0
	bl sub_08047D24
	movs r0, #1
	strb r0, [r5]
	b _0804EE36
	.align 2, 0
_0804EE18: .4byte 0x00000C94
_0804EE1C: .4byte 0x00000C95
_0804EE20:
	ldr r0, _0804EE3C @ =0x0847E8C4
	ldr r3, [r0, #0x6c]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl scene_transition_step_08047C24
	cmp r0, #0
	beq _0804EE36
	bl map_script_command_done
_0804EE36:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0804EE3C: .4byte 0x0847E8C4
	.syntax divided
