	.syntax unified

	thumb_func_start sub_08034E78
sub_08034E78: @ 0x08034E78
	push {lr}
	bl sub_0802FE50
	ldr r0, _08034E90 @ =0x03001800
	adds r0, #0xb5
	ldrb r0, [r0]
	cmp r0, #0
	beq _08034E8C
	bl sub_08034F08
_08034E8C:
	pop {r0}
	bx r0
	.align 2, 0
_08034E90: .4byte 0x03001800
	.syntax divided
