	.syntax unified

	thumb_func_start sub_080192E8
sub_080192E8: @ 0x080192E8
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	movs r6, #0
	ldr r7, _08019328 @ =0x03000590
	movs r5, #0
_080192F2:
	lsls r0, r4, #8
	adds r0, r5, r0
	adds r1, r0, r7
	adds r0, r1, #0
	adds r0, #0x49
	ldrb r0, [r0]
	cmp r0, #0x28
	bne _08019318
	adds r0, r1, #0
	adds r0, #0x59
	ldrb r0, [r0]
	cmp r0, #0
	beq _08019318
	adds r0, r1, #0
	adds r0, #0x4e
	ldrb r1, [r0]
	adds r0, r4, #0
	bl sub_080191A4
_08019318:
	adds r5, #0x18
	adds r6, #1
	cmp r6, #2
	bls _080192F2
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08019328: .4byte 0x03000590
	.syntax divided
