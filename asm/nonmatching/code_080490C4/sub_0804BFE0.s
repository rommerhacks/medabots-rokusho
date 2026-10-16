	.syntax unified

	thumb_func_start sub_0804BFE0
sub_0804BFE0: @ 0x0804BFE0
	push {r4, r5, r6, lr}
	movs r0, #5
	bl read_map_script_bytes
	ldr r4, _0804C01C @ =0x030057E0
	ldr r0, _0804C020 @ =0x00000C94
	adds r6, r4, r0
	ldrb r5, [r6]
	bl find_next_available_battle_sprite_slot
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r5, #0
	bl sub_0804DB84
	ldrb r0, [r6]
	bl sub_0804DBA4
	ldr r1, _0804C024 @ =0x03006D20
	adds r0, #0x4f
	strb r0, [r1, #0xa]
	ldr r0, _0804C028 @ =0x00000C89
	adds r4, r4, r0
	movs r0, #1
	strb r0, [r4]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804C01C: .4byte 0x030057E0
_0804C020: .4byte 0x00000C94
_0804C024: .4byte 0x03006D20
_0804C028: .4byte 0x00000C89
	.syntax divided
