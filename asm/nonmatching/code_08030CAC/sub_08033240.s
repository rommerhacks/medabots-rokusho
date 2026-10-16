	.syntax unified

	thumb_func_start sub_08033240
sub_08033240: @ 0x08033240
	ldr r1, _08033254 @ =0x03000590
	lsls r0, r0, #8
	adds r0, r0, r1
	adds r0, #0xc9
	ldrb r0, [r0]
	cmp r0, #0
	bne _08033258
	movs r0, #1
	b _0803325A
	.align 2, 0
_08033254: .4byte 0x03000590
_08033258:
	movs r0, #0
_0803325A:
	bx lr
	.syntax divided
