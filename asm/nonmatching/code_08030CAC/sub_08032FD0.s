	.syntax unified

	thumb_func_start sub_08032FD0
sub_08032FD0: @ 0x08032FD0
	adds r3, r1, #0
	movs r2, #0
	ldr r1, _08032FEC @ =0x03000590
	lsls r0, r0, #8
	adds r1, #0x4a
	adds r1, r0, r1
_08032FDC:
	ldrb r0, [r1, #0xf]
	cmp r0, #0
	beq _08032FF0
	ldrb r0, [r1]
	cmp r0, r3
	bne _08032FF0
	movs r0, #1
	b _08032FFA
	.align 2, 0
_08032FEC: .4byte 0x03000590
_08032FF0:
	adds r1, #0x18
	adds r2, #1
	cmp r2, #2
	bls _08032FDC
	movs r0, #0
_08032FFA:
	bx lr
	.syntax divided
