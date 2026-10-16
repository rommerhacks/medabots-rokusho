	.syntax unified

	thumb_func_start sub_080342C8
sub_080342C8: @ 0x080342C8
	push {lr}
	bl sub_0802057C
	ldr r0, _080342E0 @ =0x03001800
	adds r0, #0xb5
	ldrb r0, [r0]
	cmp r0, #0
	beq _080342DC
	bl sub_08034F08
_080342DC:
	pop {r0}
	bx r0
	.align 2, 0
_080342E0: .4byte 0x03001800
	.syntax divided
