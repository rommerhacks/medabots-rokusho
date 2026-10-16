	.syntax unified

	thumb_func_start sub_08034708
sub_08034708: @ 0x08034708
	push {r4, lr}
	ldr r4, _08034724 @ =0x03001800
	adds r4, #0x87
	ldrb r0, [r4]
	bl sub_0803769C
	ldrb r0, [r4]
	bl sub_080376F4
	bl sub_08034F08
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08034724: .4byte 0x03001800
	.syntax divided
