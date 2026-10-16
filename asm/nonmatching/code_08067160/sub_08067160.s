	.syntax unified

	thumb_func_start sub_08067160
sub_08067160: @ 0x08067160
	adds r2, r0, #0
	movs r1, #0
	ldrb r0, [r2]
	cmp r0, #0
	beq _08067174
_0806716A:
	adds r1, #1
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0806716A
_08067174:
	movs r0, #0
	cmp r1, #1
	beq _0806717C
	adds r0, r1, #0
_0806717C:
	bx lr
	.align 2, 0
	.syntax divided
