	.syntax unified

	thumb_func_start begin_battle_action_lookup
	.global begin_battle_action_lookup
begin_battle_action_lookup: @ 0x08033318
	push {r4, r5, lr}
	ldr r3, _08033358 @ =0x03001800
	adds r5, r3, #0
	adds r5, #0x51
	movs r2, #0
	strb r2, [r5]
	adds r2, r3, #0
	adds r2, #0x5c
	strb r0, [r2]
	subs r1, #1
	adds r2, #1
	strb r1, [r2]
	ldr r4, _0803335C @ =0x083AEF10
	ldr r3, _08033360 @ =0x03000590
	lsls r2, r1, #1
	adds r2, r2, r1
	lsls r2, r2, #3
	lsls r0, r0, #8
	adds r2, r2, r0
	adds r2, r2, r3
	adds r2, #0x49
	ldrb r0, [r2]
	lsls r0, r0, #2
	adds r0, r0, r4
	ldr r0, [r0]
	bl _call_via_r0
	ldrb r0, [r5]
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08033358: .4byte 0x03001800
_0803335C: .4byte 0x083AEF10
_08033360: .4byte 0x03000590
	.syntax divided
