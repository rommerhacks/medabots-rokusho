	.syntax unified

	thumb_func_start sub_08034540
sub_08034540: @ 0x08034540
	push {lr}
	bl sub_08024E04
	ldr r0, _08034558 @ =0x03001800
	adds r0, #0xb5
	ldrb r0, [r0]
	cmp r0, #0
	beq _08034554
	bl sub_08034F08
_08034554:
	pop {r0}
	bx r0
	.align 2, 0
_08034558: .4byte 0x03001800
	.syntax divided
