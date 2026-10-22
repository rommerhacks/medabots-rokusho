	.syntax unified

	thumb_func_start sub_0805B4B0
sub_0805B4B0: @ 0x0805B4B0
	movs r2, #0
	ldr r1, _0805B4C4 @ =0x08483AC0
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _0805B4BE
	movs r2, #1
_0805B4BE:
	adds r0, r2, #0
	bx lr
	.align 2, 0
_0805B4C4: .4byte 0x08483AC0
	.syntax divided
