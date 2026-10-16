	.syntax unified

	thumb_func_start sub_0804E79C
sub_0804E79C: @ 0x0804E79C
	push {r4, r5, lr}
	ldr r4, _0804E7B4 @ =0x030057E0
	ldr r0, _0804E7B8 @ =0x00000C93
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #1
	beq _0804E7CA
	cmp r0, #1
	bgt _0804E7BC
	cmp r0, #0
	beq _0804E7C2
	b _0804E80C
	.align 2, 0
_0804E7B4: .4byte 0x030057E0
_0804E7B8: .4byte 0x00000C93
_0804E7BC:
	cmp r0, #2
	beq _0804E800
	b _0804E80C
_0804E7C2:
	movs r0, #0
	bl init_bg0_for_cursor
	b _0804E7F0
_0804E7CA:
	bl sub_08047FEC
	adds r1, r0, #0
	cmp r1, #0
	beq _0804E80C
	movs r0, #0xf0
	ands r0, r1
	cmp r0, #0
	beq _0804E7F0
	ldr r1, _0804E7F8 @ =0x00000C8C
	adds r0, r4, r1
	ldr r2, _0804E7FC @ =0x00000C94
	adds r1, r4, r2
	ldrh r0, [r0]
	ldrb r1, [r1]
	adds r0, r0, r1
	subs r2, #0xa
	adds r1, r4, r2
	strh r0, [r1]
_0804E7F0:
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	b _0804E80C
	.align 2, 0
_0804E7F8: .4byte 0x00000C8C
_0804E7FC: .4byte 0x00000C94
_0804E800:
	bl game_state_execute_handler_a
	cmp r0, #0
	beq _0804E80C
	bl sub_08050244
_0804E80C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
