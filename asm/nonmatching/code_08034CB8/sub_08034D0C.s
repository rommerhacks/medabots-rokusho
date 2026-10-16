	.syntax unified

	thumb_func_start sub_08034D0C
sub_08034D0C: @ 0x08034D0C
	push {lr}
	bl sub_0802B000
	ldr r0, _08034D24 @ =0x03001800
	adds r0, #0xb5
	ldrb r0, [r0]
	cmp r0, #0
	beq _08034D20
	bl sub_08034F08
_08034D20:
	pop {r0}
	bx r0
	.align 2, 0
_08034D24: .4byte 0x03001800
	.syntax divided
