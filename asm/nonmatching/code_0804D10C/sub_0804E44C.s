	.syntax unified

	thumb_func_start sub_0804E44C
sub_0804E44C: @ 0x0804E44C
	push {r4, r5, r6, lr}
	ldr r4, _0804E460 @ =0x030057E0
	ldr r0, _0804E464 @ =0x00000C93
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #0
	beq _0804E468
	cmp r0, #1
	beq _0804E4B4
	b _0804E4C6
	.align 2, 0
_0804E460: .4byte 0x030057E0
_0804E464: .4byte 0x00000C93
_0804E468:
	ldr r1, _0804E49C @ =0x00000C94
	adds r0, r4, r1
	ldrb r0, [r0]
	ldr r2, _0804E4A0 @ =0x00000C95
	adds r1, r4, r2
	ldrb r1, [r1]
	ldr r3, _0804E4A4 @ =0x00000C96
	adds r2, r4, r3
	ldrb r2, [r2]
	ldr r6, _0804E4A8 @ =0x00000C97
	adds r3, r4, r6
	ldrb r3, [r3]
	bl spawn_battle_medapart_sprite
	ldr r0, _0804E4AC @ =0x03006D20
	ldrb r0, [r0, #0xa]
	ldr r2, _0804E4B0 @ =0x00000C98
	adds r1, r4, r2
	ldrb r1, [r1]
	movs r2, #0
	bl setup_battle_sprite_terrain
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	b _0804E4C6
	.align 2, 0
_0804E49C: .4byte 0x00000C94
_0804E4A0: .4byte 0x00000C95
_0804E4A4: .4byte 0x00000C96
_0804E4A8: .4byte 0x00000C97
_0804E4AC: .4byte 0x03006D20
_0804E4B0: .4byte 0x00000C98
_0804E4B4:
	ldr r0, _0804E4CC @ =0x03006D20
	ldrb r0, [r0, #0xa]
	movs r1, #1
	bl update_battle_sprite_movement
	cmp r0, #0
	beq _0804E4C6
	bl sub_08050244
_0804E4C6:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804E4CC: .4byte 0x03006D20
	.syntax divided
