	.syntax unified

	thumb_func_start battle_add_active_medal_slot
battle_add_active_medal_slot: @ 0x0801A0A4
	push {r4, lr}
	adds r4, r1, #0
	movs r2, #0
	ldr r1, _0801A0BC @ =0x03001800
	adds r3, r0, #1
	adds r1, #0x45
_0801A0B0:
	ldrb r0, [r1]
	cmp r0, #0
	bne _0801A0C0
	strb r3, [r1]
	strb r4, [r1, #1]
	b _0801A0C8
	.align 2, 0
_0801A0BC: .4byte 0x03001800
_0801A0C0:
	adds r1, #2
	adds r2, #1
	cmp r2, #5
	bls _0801A0B0
_0801A0C8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
