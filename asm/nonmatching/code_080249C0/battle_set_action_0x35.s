	.syntax unified

	thumb_func_start battle_set_action_0x35
battle_set_action_0x35: @ 0x08025790
	push {r4, lr}
	ldr r0, _080257B8 @ =0x030004DE
	ldr r4, _080257BC @ =0x03001800
	adds r1, r4, #0
	adds r1, #0x51
	ldrb r1, [r1]
	movs r2, #0x35
	bl divide_by_100000_b
	adds r1, r4, #0
	adds r1, #0xa6
	movs r0, #0x35
	strb r0, [r1]
	adds r1, #4
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080257B8: .4byte 0x030004DE
_080257BC: .4byte 0x03001800
	.syntax divided
