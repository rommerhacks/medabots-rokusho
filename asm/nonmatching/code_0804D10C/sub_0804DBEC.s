	.syntax unified

	thumb_func_start sub_0804DBEC
sub_0804DBEC: @ 0x0804DBEC
	push {r4, r5, lr}
	ldr r4, _0804DC00 @ =0x030057E0
	ldr r0, _0804DC04 @ =0x00000C93
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #0
	beq _0804DC08
	cmp r0, #1
	beq _0804DC4C
	b _0804DC98
	.align 2, 0
_0804DC00: .4byte 0x030057E0
_0804DC04: .4byte 0x00000C93
_0804DC08:
	bl init_cursor_state
	ldr r2, _0804DC40 @ =0x030057A0
	ldr r1, _0804DC44 @ =0x00000C94
	adds r0, r4, r1
	ldrb r0, [r0]
	subs r0, #2
	strh r0, [r2, #0x2e]
	ldr r3, _0804DC48 @ =0x00000C95
	adds r0, r4, r3
	ldrb r1, [r0]
	lsls r1, r1, #8
	adds r3, #1
	adds r0, r4, r3
	ldrb r0, [r0]
	orrs r0, r1
	strh r0, [r2, #0x30]
	bl sub_0804B6EC
	cmp r0, #0
	beq _0804DC36
	bl sub_08050244
_0804DC36:
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	b _0804DC98
	.align 2, 0
_0804DC40: .4byte 0x030057A0
_0804DC44: .4byte 0x00000C94
_0804DC48: .4byte 0x00000C95
_0804DC4C:
	ldr r0, _0804DC5C @ =0x00000C94
	adds r2, r4, r0
	ldrb r0, [r2]
	cmp r0, #1
	bhi _0804DC64
	ldr r2, _0804DC60 @ =0x08414968
	b _0804DC70
	.align 2, 0
_0804DC5C: .4byte 0x00000C94
_0804DC60: .4byte 0x08414968
_0804DC64:
	ldr r1, _0804DCA0 @ =0x0847E45C
	ldrb r0, [r2]
	subs r0, #2
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r2, [r0]
_0804DC70:
	ldr r1, _0804DCA4 @ =0x00000C95
	adds r0, r4, r1
	ldrb r0, [r0]
	lsls r0, r0, #8
	ldr r3, _0804DCA8 @ =0x00000C96
	adds r1, r4, r3
	ldrb r1, [r1]
	orrs r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r3, [r0]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl scene_transition_step_08047C24
	cmp r0, #0
	beq _0804DC98
	bl sub_08050244
_0804DC98:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0804DCA0: .4byte 0x0847E45C
_0804DCA4: .4byte 0x00000C95
_0804DCA8: .4byte 0x00000C96
	.syntax divided
