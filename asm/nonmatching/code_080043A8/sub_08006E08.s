	.syntax unified

	thumb_func_start sub_08006E08
sub_08006E08: @ 0x08006E08
	sub sp, #4
	str r0, [sp]
	ldr r0, [sp]
	cmp r0, #0
	bne _08006E2C
	ldr r1, _08006E24 @ =0x030017A0
	ldr r0, _08006E28 @ =0x03000440
	adds r0, #0x51
	ldrb r0, [r0]
	lsls r0, r0, #3
	adds r0, r0, r1
	ldrb r0, [r0, #1]
	adds r0, #0x78
	b _08006E3A
	.align 2, 0
_08006E24: .4byte 0x030017A0
_08006E28: .4byte 0x03000440
_08006E2C:
	ldr r0, [sp]
	cmp r0, #0x77
	bls _08006E36
	movs r0, #0x77
	b _08006E3A
_08006E36:
	ldr r0, [sp]
	subs r0, #1
_08006E3A:
	str r0, [sp]
	ldr r0, [sp]
	add sp, #4
	bx lr
	.align 2, 0
	.syntax divided
