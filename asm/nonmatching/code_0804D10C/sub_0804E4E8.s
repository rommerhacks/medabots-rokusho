	.syntax unified

	thumb_func_start sub_0804E4E8
sub_0804E4E8: @ 0x0804E4E8
	push {r4, lr}
	ldr r1, _0804E4FC @ =0x030057E0
	ldr r0, _0804E500 @ =0x00000C93
	adds r4, r1, r0
	ldrb r0, [r4]
	cmp r0, #0
	beq _0804E504
	cmp r0, #1
	beq _0804E524
	b _0804E536
	.align 2, 0
_0804E4FC: .4byte 0x030057E0
_0804E500: .4byte 0x00000C93
_0804E504:
	ldr r0, _0804E51C @ =0x03006D20
	ldrb r0, [r0, #0xa]
	ldr r2, _0804E520 @ =0x00000C95
	adds r1, r1, r2
	ldrb r1, [r1]
	movs r2, #0
	bl setup_battle_sprite_terrain
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	b _0804E536
	.align 2, 0
_0804E51C: .4byte 0x03006D20
_0804E520: .4byte 0x00000C95
_0804E524:
	ldr r0, _0804E53C @ =0x03006D20
	ldrb r0, [r0, #0xa]
	movs r1, #1
	bl update_battle_sprite_movement
	cmp r0, #0
	beq _0804E536
	bl map_script_command_done
_0804E536:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804E53C: .4byte 0x03006D20
	.syntax divided
