	.syntax unified

	thumb_func_start sub_080192B8
sub_080192B8: @ 0x080192B8
	push {lr}
	adds r2, r0, #0
	ldr r0, _080192E4 @ =0x03000590
	lsls r1, r2, #8
	adds r1, r1, r0
	adds r0, r1, #0
	adds r0, #0xc4
	ldrb r0, [r0]
	cmp r0, #0
	beq _080192E0
	cmp r0, #0x26
	beq _080192D4
	cmp r0, #0x29
	bne _080192E0
_080192D4:
	adds r0, r1, #0
	adds r0, #0xc7
	ldrb r1, [r0]
	adds r0, r2, #0
	bl sub_080191A4
_080192E0:
	pop {r0}
	bx r0
	.align 2, 0
_080192E4: .4byte 0x03000590
	.syntax divided
