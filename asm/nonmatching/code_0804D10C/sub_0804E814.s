	.syntax unified

	thumb_func_start sub_0804E814
sub_0804E814: @ 0x0804E814
	push {r4, r5, lr}
	ldr r5, _0804E828 @ =0x030057E0
	ldr r0, _0804E82C @ =0x00000C93
	adds r4, r5, r0
	ldrb r0, [r4]
	cmp r0, #0
	beq _0804E830
	cmp r0, #1
	beq _0804E83E
	b _0804E868
	.align 2, 0
_0804E828: .4byte 0x030057E0
_0804E82C: .4byte 0x00000C93
_0804E830:
	movs r0, #1
	bl init_bg0_for_cursor
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	b _0804E868
_0804E83E:
	bl sub_08047FEC
	adds r1, r0, #0
	cmp r1, #0
	beq _0804E868
	movs r0, #0xf0
	ands r0, r1
	cmp r0, #0
	beq _0804E864
	ldr r1, _0804E870 @ =0x00000C8C
	adds r0, r5, r1
	ldr r2, _0804E874 @ =0x00000C94
	adds r1, r5, r2
	ldrh r0, [r0]
	ldrb r1, [r1]
	adds r0, r0, r1
	subs r2, #0xa
	adds r1, r5, r2
	strh r0, [r1]
_0804E864:
	bl map_script_command_done
_0804E868:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0804E870: .4byte 0x00000C8C
_0804E874: .4byte 0x00000C94
	.syntax divided
