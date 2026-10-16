	.syntax unified

	thumb_func_start sub_0804C078
sub_0804C078: @ 0x0804C078
	push {r4, lr}
	movs r0, #4
	bl read_map_script_bytes
	ldr r3, _0804C0A4 @ =0x030057E0
	ldr r1, _0804C0A8 @ =0x00000C94
	adds r0, r3, r1
	ldrb r0, [r0]
	ldr r2, _0804C0AC @ =0x00000C95
	adds r1, r3, r2
	ldrb r1, [r1]
	ldr r4, _0804C0B0 @ =0x00000C96
	adds r2, r3, r4
	ldrb r2, [r2]
	adds r4, #1
	adds r3, r3, r4
	ldrb r3, [r3]
	bl spawn_battle_medapart_sprite
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804C0A4: .4byte 0x030057E0
_0804C0A8: .4byte 0x00000C94
_0804C0AC: .4byte 0x00000C95
_0804C0B0: .4byte 0x00000C96
	.syntax divided
