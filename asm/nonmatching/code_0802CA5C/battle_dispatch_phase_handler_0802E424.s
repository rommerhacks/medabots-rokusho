	.syntax unified

	thumb_func_start battle_dispatch_phase_handler_0802E424
	.global battle_dispatch_phase_handler_0802E424
battle_dispatch_phase_handler_0802E424: @ 0x0802E424
	push {lr}
	ldr r1, _0802E444 @ =0x03001800
	adds r2, r1, #0
	adds r2, #0xb5
	movs r0, #0
	strb r0, [r2]
	ldr r2, _0802E448 @ =0x083AE99C
	adds r1, #0xaa
	ldrb r0, [r1]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	bl _call_via_r0
	pop {r0}
	bx r0
	.align 2, 0
_0802E444: .4byte 0x03001800
_0802E448: .4byte 0x083AE99C
	.syntax divided
