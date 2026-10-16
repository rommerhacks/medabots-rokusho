	.syntax unified

	thumb_func_start sub_0804C02C
sub_0804C02C: @ 0x0804C02C
	push {r4, r5, r6, lr}
	movs r0, #5
	bl read_map_script_bytes
	ldr r4, _0804C068 @ =0x030057E0
	ldr r0, _0804C06C @ =0x00000C94
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
	ldr r1, _0804C070 @ =0x03006D20
	adds r0, #0x4f
	strb r0, [r1, #0xa]
	ldr r0, _0804C074 @ =0x00000C89
	adds r4, r4, r0
	movs r0, #1
	strb r0, [r4]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804C068: .4byte 0x030057E0
_0804C06C: .4byte 0x00000C94
_0804C070: .4byte 0x03006D20
_0804C074: .4byte 0x00000C89
	.syntax divided
