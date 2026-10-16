	.syntax unified

	thumb_func_start sub_08034498
sub_08034498: @ 0x08034498
	push {lr}
	bl sub_0802342C
	ldr r0, _080344B0 @ =0x03001800
	adds r0, #0xb5
	ldrb r0, [r0]
	cmp r0, #0
	beq _080344AC
	bl sub_08034F08
_080344AC:
	pop {r0}
	bx r0
	.align 2, 0
_080344B0: .4byte 0x03001800
	.syntax divided
