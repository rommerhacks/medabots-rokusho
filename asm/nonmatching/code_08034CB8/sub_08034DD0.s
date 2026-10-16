	.syntax unified

	thumb_func_start sub_08034DD0
sub_08034DD0: @ 0x08034DD0
	push {lr}
	bl sub_0802DCB4
	ldr r0, _08034DE8 @ =0x03001800
	adds r0, #0xb5
	ldrb r0, [r0]
	cmp r0, #0
	beq _08034DE4
	bl sub_08034F08
_08034DE4:
	pop {r0}
	bx r0
	.align 2, 0
_08034DE8: .4byte 0x03001800
	.syntax divided
