	.syntax unified

	thumb_func_start sub_0804E6B4
sub_0804E6B4: @ 0x0804E6B4
	push {r4, r5, r6, lr}
	ldr r4, _0804E6C8 @ =0x030057E0
	ldr r0, _0804E6CC @ =0x00000C93
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #0
	beq _0804E6D0
	cmp r0, #1
	beq _0804E71C
	b _0804E72E
	.align 2, 0
_0804E6C8: .4byte 0x030057E0
_0804E6CC: .4byte 0x00000C93
_0804E6D0:
	ldr r1, _0804E704 @ =0x00000C94
	adds r0, r4, r1
	ldrb r0, [r0]
	ldr r2, _0804E708 @ =0x00000C95
	adds r1, r4, r2
	ldrb r1, [r1]
	ldr r3, _0804E70C @ =0x00000C96
	adds r2, r4, r3
	ldrb r2, [r2]
	ldr r6, _0804E710 @ =0x00000C97
	adds r3, r4, r6
	ldrb r3, [r3]
	bl spawn_battle_medapart_sprite
	ldr r0, _0804E714 @ =0x03006D20
	ldrb r0, [r0, #0xa]
	ldr r2, _0804E718 @ =0x00000C98
	adds r1, r4, r2
	ldrb r1, [r1]
	movs r2, #0
	bl setup_battle_sprite_terrain
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	b _0804E72E
	.align 2, 0
_0804E704: .4byte 0x00000C94
_0804E708: .4byte 0x00000C95
_0804E70C: .4byte 0x00000C96
_0804E710: .4byte 0x00000C97
_0804E714: .4byte 0x03006D20
_0804E718: .4byte 0x00000C98
_0804E71C:
	ldr r0, _0804E734 @ =0x03006D20
	ldrb r0, [r0, #0xa]
	movs r1, #0
	bl update_battle_sprite_movement
	cmp r0, #0
	beq _0804E72E
	bl sub_08050244
_0804E72E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804E734: .4byte 0x03006D20
	.syntax divided
