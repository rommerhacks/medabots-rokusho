	.syntax unified

	thumb_func_start sub_08034F44
	.global sub_08034F44
sub_08034F44: @ 0x08034F44
	movs r2, #0
	ldr r1, _08034F58 @ =0x03000590
	lsls r0, r0, #8
	adds r1, #0x49
	adds r1, r0, r1
_08034F4E:
	ldrb r0, [r1]
	cmp r0, #0x15
	bne _08034F5C
	movs r0, #1
	b _08034F66
	.align 2, 0
_08034F58: .4byte 0x03000590
_08034F5C:
	adds r1, #0x18
	adds r2, #1
	cmp r2, #2
	bls _08034F4E
	movs r0, #0
_08034F66:
	bx lr
	.syntax divided
