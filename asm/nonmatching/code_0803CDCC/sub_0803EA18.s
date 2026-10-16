	.syntax unified

	thumb_func_start sub_0803EA18
sub_0803EA18: @ 0x0803EA18
	ldr r0, _0803EA2C @ =0x03001800
	movs r2, #0xd0
	lsls r2, r2, #1
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, #0x60
	bne _0803EA30
	movs r0, #0
	b _0803EA32
	.align 2, 0
_0803EA2C: .4byte 0x03001800
_0803EA30:
	adds r0, #4
_0803EA32:
	strb r0, [r1]
	bx lr
	.align 2, 0
	.syntax divided
