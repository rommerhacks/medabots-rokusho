	.syntax unified

	thumb_func_start sub_080342E4
sub_080342E4: @ 0x080342E4
	push {lr}
	bl sub_080207A4
	ldr r0, _080342FC @ =0x03001800
	adds r0, #0xb5
	ldrb r0, [r0]
	cmp r0, #0
	beq _080342F8
	bl sub_08034F08
_080342F8:
	pop {r0}
	bx r0
	.align 2, 0
_080342FC: .4byte 0x03001800
	.syntax divided
