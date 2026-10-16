	.syntax unified

	thumb_func_start sub_08034594
sub_08034594: @ 0x08034594
	push {lr}
	bl sub_08025AF8
	ldr r0, _080345AC @ =0x03001800
	adds r0, #0xb5
	ldrb r0, [r0]
	cmp r0, #0
	beq _080345A8
	bl sub_08034F08
_080345A8:
	pop {r0}
	bx r0
	.align 2, 0
_080345AC: .4byte 0x03001800
	.syntax divided
