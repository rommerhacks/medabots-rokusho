	.syntax unified

	thumb_func_start sub_0804ED3C
sub_0804ED3C: @ 0x0804ED3C
	push {r4, r5, lr}
	ldr r4, _0804ED50 @ =0x030057E0
	ldr r0, _0804ED54 @ =0x00000C93
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #0
	beq _0804ED58
	cmp r0, #1
	beq _0804ED94
	b _0804EDAA
	.align 2, 0
_0804ED50: .4byte 0x030057E0
_0804ED54: .4byte 0x00000C93
_0804ED58:
	bl init_cursor_state
	ldr r1, _0804ED8C @ =0x00000C94
	adds r0, r4, r1
	ldrb r0, [r0]
	lsls r0, r0, #8
	ldr r2, _0804ED90 @ =0x00000C95
	adds r1, r4, r2
	ldrb r1, [r1]
	orrs r0, r1
	lsls r4, r0, #2
	adds r4, r4, r0
	lsls r4, r4, #1
	movs r0, #7
	bl sub_08047BA8
	adds r0, r4, #0
	bl sub_08047D58
	movs r0, #0
	adds r1, r4, #0
	bl sub_08047D24
	movs r0, #1
	strb r0, [r5]
	b _0804EDAA
	.align 2, 0
_0804ED8C: .4byte 0x00000C94
_0804ED90: .4byte 0x00000C95
_0804ED94:
	ldr r0, _0804EDB0 @ =0x0847E8C4
	ldr r3, [r0, #0x68]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl scene_transition_step_08047C24
	cmp r0, #0
	beq _0804EDAA
	bl map_script_command_done
_0804EDAA:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0804EDB0: .4byte 0x0847E8C4
	.syntax divided
