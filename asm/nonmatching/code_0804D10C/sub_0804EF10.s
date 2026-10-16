	.syntax unified

	thumb_func_start sub_0804EF10
sub_0804EF10: @ 0x0804EF10
	push {r4, r5, lr}
	ldr r4, _0804EF28 @ =0x030057E0
	ldr r0, _0804EF2C @ =0x00000C93
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #1
	beq _0804EF64
	cmp r0, #1
	bgt _0804EF30
	cmp r0, #0
	beq _0804EF36
	b _0804EFA2
	.align 2, 0
_0804EF28: .4byte 0x030057E0
_0804EF2C: .4byte 0x00000C93
_0804EF30:
	cmp r0, #2
	beq _0804EF80
	b _0804EFA2
_0804EF36:
	bl init_cursor_state
	movs r0, #0xe
	bl sub_08047BA8
	bl sub_08047E30
	cmp r0, #0
	beq _0804EF4E
	movs r0, #1
	strb r0, [r5]
	b _0804EFA2
_0804EF4E:
	ldr r1, _0804EF60 @ =0x00000C94
	adds r0, r4, r1
	ldrb r0, [r0]
	bl sub_08047E3C
	movs r0, #2
	strb r0, [r5]
	b _0804EFA2
	.align 2, 0
_0804EF60: .4byte 0x00000C94
_0804EF64:
	ldr r0, _0804EF7C @ =0x0847E8C4
	ldr r3, [r0, #0x78]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl scene_transition_step_08047C24
	cmp r0, #0
	beq _0804EFA2
	bl map_script_command_done
	b _0804EFA2
	.align 2, 0
_0804EF7C: .4byte 0x0847E8C4
_0804EF80:
	ldr r1, _0804EFA8 @ =0x0847E8C4
	ldr r2, _0804EFAC @ =0x00000C94
	adds r0, r4, r2
	ldrb r0, [r0]
	adds r0, #0x1f
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r3, [r0]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl scene_transition_step_08047C24
	cmp r0, #0
	beq _0804EFA2
	bl map_script_command_done
_0804EFA2:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0804EFA8: .4byte 0x0847E8C4
_0804EFAC: .4byte 0x00000C94
	.syntax divided
