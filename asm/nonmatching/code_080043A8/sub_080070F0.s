	.syntax unified

	thumb_func_start sub_080070F0
sub_080070F0: @ 0x080070F0
	push {r4, r5, r6, lr}
	movs r3, #0
	ldr r4, _08007124 @ =0x03000481
	ldr r2, _08007128 @ =0x03000BE0
	movs r6, #0x80
	movs r5, #0x40
_080070FC:
	ldrb r1, [r2]
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq _08007114
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	bne _08007114
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
_08007114:
	adds r2, #0x40
	adds r3, #1
	cmp r3, #0x1d
	bls _080070FC
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08007124: .4byte 0x03000481
_08007128: .4byte 0x03000BE0
	.syntax divided
