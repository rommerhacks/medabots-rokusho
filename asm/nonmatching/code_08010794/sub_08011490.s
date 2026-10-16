	.syntax unified

	thumb_func_start sub_08011490
sub_08011490: @ 0x08011490
	push {r4, lr}
	ldr r1, _080114AC @ =0x03001800
	movs r0, #0xc3
	lsls r0, r0, #1
	adds r3, r1, r0
	ldrb r0, [r3]
	cmp r0, #3
	bne _080114B4
	movs r0, #0
	strb r0, [r3]
	ldr r1, _080114B0 @ =0x0300137C
	movs r0, #0x5b
	str r0, [r1]
	b _080114D8
	.align 2, 0
_080114AC: .4byte 0x03001800
_080114B0: .4byte 0x0300137C
_080114B4:
	ldrb r2, [r3]
	lsls r0, r2, #3
	ldr r4, _080114CC @ =0x0000016F
	adds r1, r1, r4
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080114D4
	ldr r1, _080114D0 @ =0x0300137C
	movs r0, #0x4e
	str r0, [r1]
	b _080114D8
	.align 2, 0
_080114CC: .4byte 0x0000016F
_080114D0: .4byte 0x0300137C
_080114D4:
	adds r0, r2, #1
	strb r0, [r3]
_080114D8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
