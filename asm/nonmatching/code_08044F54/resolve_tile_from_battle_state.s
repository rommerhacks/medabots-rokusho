	.syntax unified

	thumb_func_start resolve_tile_from_battle_state
	.global resolve_tile_from_battle_state
resolve_tile_from_battle_state: @ 0x08048638
	push {lr}
	ldr r2, _08048658 @ =0x08413514
	ldr r1, _0804865C @ =0x030057E0
	ldr r3, _08048660 @ =0x000007FE
	adds r1, r1, r3
	ldrb r1, [r1]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	adds r1, r1, r0
	ldrb r0, [r1]
	bl sub_080481C4
	pop {r1}
	bx r1
	.align 2, 0
_08048658: .4byte 0x08413514
_0804865C: .4byte 0x030057E0
_08048660: .4byte 0x000007FE
	.syntax divided
