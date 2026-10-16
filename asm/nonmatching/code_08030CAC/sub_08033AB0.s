	.syntax unified

	thumb_func_start sub_08033AB0
sub_08033AB0: @ 0x08033AB0
	push {lr}
	bl sub_0801D580
	ldr r0, _08033AC8 @ =0x03001800
	adds r0, #0xb5
	ldrb r0, [r0]
	cmp r0, #0
	beq _08033AC4
	bl sub_08034F08
_08033AC4:
	pop {r0}
	bx r0
	.align 2, 0
_08033AC8: .4byte 0x03001800
	.syntax divided
