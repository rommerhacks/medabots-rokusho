	.syntax unified

	thumb_func_start call_battle_handler_by_state_0804DBC0
	.global call_battle_handler_by_state_0804DBC0
call_battle_handler_by_state_0804DBC0: @ 0x0804DBC0
	push {lr}
	ldr r1, _0804DBDC @ =0x083D24B0
	ldr r0, _0804DBE0 @ =0x030057E0
	ldr r2, _0804DBE4 @ =0x00000C92
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	pop {r0}
	bx r0
	.align 2, 0
_0804DBDC: .4byte 0x083D24B0
_0804DBE0: .4byte 0x030057E0
_0804DBE4: .4byte 0x00000C92

	.syntax divided
