	.syntax unified

	thumb_func_start sub_08035960
sub_08035960: @ 0x08035960
	adds r3, r1, #0
	movs r2, #0
	ldr r1, _0803597C @ =0x03000590
	lsls r0, r0, #8
	adds r1, #0x49
	adds r1, r0, r1
_0803596C:
	ldrb r0, [r1, #0x10]
	cmp r0, #0
	beq _08035980
	ldrb r0, [r1]
	cmp r0, r3
	bne _08035980
	movs r0, #1
	b _0803598A
	.align 2, 0
_0803597C: .4byte 0x03000590
_08035980:
	adds r1, #0x18
	adds r2, #1
	cmp r2, #3
	bls _0803596C
	movs r0, #0
_0803598A:
	bx lr
	.syntax divided
