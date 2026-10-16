	.syntax unified

	thumb_func_start dispatch_battle_action_substate
	.global dispatch_battle_action_substate
dispatch_battle_action_substate: @ 0x0801C2F0
	push {r4, lr}
	ldr r4, _0801C31C @ =0x03001800
	adds r1, r4, #0
	adds r1, #0x9d
	strb r0, [r1]
	ldr r1, _0801C320 @ =0x083AD424
	adds r0, r4, #0
	adds r0, #0x9c
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	adds r0, r4, #0
	adds r0, #0x9e
	ldrb r0, [r0]
	cmp r0, #0
	bne _0801C324
	movs r0, #0
	b _0801C326
	.align 2, 0
_0801C31C: .4byte 0x03001800
_0801C320: .4byte 0x083AD424
_0801C324:
	movs r0, #1
_0801C326:
	pop {r4}
	pop {r1}
	bx r1
	.syntax divided
