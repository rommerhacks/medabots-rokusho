	.syntax unified

	thumb_func_start sub_08041D28
	.global sub_08041D28
sub_08041D28: @ 0x08041D28
	movs r0, #0
	ldr r1, _08041D38 @ =0x03000BE0
_08041D2C:
	strb r0, [r1]
	adds r1, #0x40
	adds r0, #1
	cmp r0, #0x1d
	bls _08041D2C
	bx lr
	.align 2, 0
_08041D38: .4byte 0x03000BE0
	.syntax divided
