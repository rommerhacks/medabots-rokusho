	.syntax unified

	thumb_func_start sub_08034D28
sub_08034D28: @ 0x08034D28
	push {lr}
	bl sub_0802B7E8
	ldr r0, _08034D40 @ =0x03001800
	adds r0, #0xb5
	ldrb r0, [r0]
	cmp r0, #0
	beq _08034D3C
	bl sub_08034F08
_08034D3C:
	pop {r0}
	bx r0
	.align 2, 0
_08034D40: .4byte 0x03001800
	.syntax divided
