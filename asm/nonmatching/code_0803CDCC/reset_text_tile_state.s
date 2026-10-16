	.syntax unified

	thumb_func_start reset_text_tile_state
reset_text_tile_state: @ 0x0804056C
	push {lr}
	ldr r2, _080405BC @ =0x03000440
	ldrb r1, [r2, #0x14]
	movs r0, #7
	ands r0, r1
	cmp r0, #0
	beq _080405A2
	ldrb r0, [r2, #0x14]
	adds r1, r0, #0
	adds r1, #8
	asrs r1, r1, #3
	subs r1, #1
	lsls r1, r1, #0x18
	ldr r0, _080405C0 @ =0x02020000
	lsrs r1, r1, #0x12
	ldrb r3, [r2, #0x17]
	lsls r2, r3, #1
	adds r2, r2, r3
	lsls r2, r2, #2
	adds r2, r2, r3
	lsls r2, r2, #7
	ldr r3, _080405C4 @ =0x06000280
	adds r2, r2, r3
	adds r1, r1, r2
	movs r2, #0x20
	bl CpuSet
_080405A2:
	ldr r1, _080405BC @ =0x03000440
	movs r0, #0
	strb r0, [r1, #0x14]
	strb r0, [r1, #0x16]
	strb r0, [r1, #0x18]
	strb r0, [r1, #0x19]
	ldrb r0, [r1, #0x17]
	cmp r0, #1
	bne _080405C8
	movs r0, #2
	strb r0, [r1, #0x19]
	b _080405CC
	.align 2, 0
_080405BC: .4byte 0x03000440
_080405C0: .4byte 0x02020000
_080405C4: .4byte 0x06000280
_080405C8:
	movs r0, #1
	strb r0, [r1, #0x17]
_080405CC:
	pop {r0}
	bx r0
	.syntax divided
