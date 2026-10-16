	.syntax unified

	thumb_func_start sub_08033224
sub_08033224: @ 0x08033224
	ldr r1, _08033238 @ =0x03000590
	lsls r0, r0, #8
	adds r0, r0, r1
	adds r0, #0xc4
	ldrb r0, [r0]
	cmp r0, #0
	bne _0803323C
	movs r0, #1
	b _0803323E
	.align 2, 0
_08033238: .4byte 0x03000590
_0803323C:
	movs r0, #0
_0803323E:
	bx lr
	.syntax divided
