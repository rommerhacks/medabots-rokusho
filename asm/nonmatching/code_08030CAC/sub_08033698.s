	.syntax unified

	thumb_func_start sub_08033698
sub_08033698: @ 0x08033698
	push {r4, r5, lr}
	ldr r4, _080336D8 @ =0x03001800
	adds r5, r4, #0
	adds r5, #0x5c
	ldrb r0, [r5]
	movs r1, #1
	bl sub_0801554C
	lsls r0, r0, #3
	adds r0, r0, r4
	adds r0, #0x2a
	ldrb r0, [r0]
	cmp r0, #0
	beq _080336C8
	ldrb r0, [r5]
	movs r1, #1
	bl sub_0801554C
	lsls r0, r0, #3
	adds r0, r0, r4
	adds r0, #0x2b
	ldrb r0, [r0]
	cmp r0, #0x33
	beq _080336D0
_080336C8:
	adds r1, r4, #0
	adds r1, #0x51
	movs r0, #1
	strb r0, [r1]
_080336D0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080336D8: .4byte 0x03001800
	.syntax divided
