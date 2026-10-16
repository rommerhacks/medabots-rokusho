	.syntax unified

	thumb_func_start sub_08034300
sub_08034300: @ 0x08034300
	push {lr}
	bl sub_0802081C
	ldr r0, _08034318 @ =0x03001800
	adds r0, #0xb5
	ldrb r0, [r0]
	cmp r0, #0
	beq _08034314
	bl sub_08034F08
_08034314:
	pop {r0}
	bx r0
	.align 2, 0
_08034318: .4byte 0x03001800
	.syntax divided
