	.syntax unified

	thumb_func_start find_next_active_bot
find_next_active_bot: @ 0x0801B700
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	bl rng_next_080424B8
	adds r2, r0, #0
	movs r0, #0x1f
	ands r2, r0
	movs r3, #0
	ldr r0, _0801B744 @ =0x030004C9
	ldrb r4, [r0]
	ldr r6, _0801B748 @ =0x03000590
_0801B716:
	ldr r0, _0801B74C @ =0x083AD3D3
	adds r0, r2, r0
	ldrb r1, [r0]
	cmp r4, #1
	bne _0801B72E
	ldr r0, _0801B750 @ =0x03000B90
	ldrb r0, [r0]
	cmp r0, #0
	beq _0801B72E
	ldr r0, _0801B754 @ =0x083AD3F3
	adds r0, r1, r0
	ldrb r1, [r0]
_0801B72E:
	lsls r0, r1, #8
	adds r0, r0, r6
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #0
	beq _0801B758
	cmp r5, r1
	beq _0801B758
	adds r0, r1, #0
	b _0801B766
	.align 2, 0
_0801B744: .4byte 0x030004C9
_0801B748: .4byte 0x03000590
_0801B74C: .4byte 0x083AD3D3
_0801B750: .4byte 0x03000B90
_0801B754: .4byte 0x083AD3F3
_0801B758:
	adds r2, #1
	movs r0, #0x1f
	ands r2, r0
	adds r3, #1
	cmp r3, #5
	bls _0801B716
	movs r0, #0
_0801B766:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.syntax divided
