	.syntax unified

	thumb_func_start dispatch_battle_action_step
	.global dispatch_battle_action_step
dispatch_battle_action_step: @ 0x080257C0
	push {lr}
	ldr r1, _080257E0 @ =0x03001800
	adds r2, r1, #0
	adds r2, #0xb5
	movs r0, #0
	strb r0, [r2]
	ldr r2, _080257E4 @ =0x083AE004
	adds r1, #0xaa
	ldrb r0, [r1]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	bl _call_via_r0
	pop {r0}
	bx r0
	.align 2, 0
_080257E0: .4byte 0x03001800
_080257E4: .4byte 0x083AE004
	.syntax divided
