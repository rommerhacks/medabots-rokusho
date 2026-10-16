	.syntax unified

	thumb_func_start sub_08034E40
sub_08034E40: @ 0x08034E40
	push {lr}
	bl sub_0802F628
	ldr r0, _08034E58 @ =0x03001800
	adds r0, #0xb5
	ldrb r0, [r0]
	cmp r0, #0
	beq _08034E54
	bl sub_08034F08
_08034E54:
	pop {r0}
	bx r0
	.align 2, 0
_08034E58: .4byte 0x03001800
	.syntax divided
