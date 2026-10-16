	.syntax unified

	thumb_func_start sub_08010B24
sub_08010B24: @ 0x08010B24
	push {r4, lr}
	ldr r4, _08010B48 @ =0x03000490
	adds r0, r4, #0
	movs r1, #0x14
	movs r2, #0
	bl sub_0803F624
	movs r2, #0
	movs r0, #2
	strb r0, [r4]
	ldr r1, _08010B4C @ =0x03002B8C
	movs r0, #3
	str r0, [r1]
	ldr r0, _08010B50 @ =0x0300137C
	str r2, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08010B48: .4byte 0x03000490
_08010B4C: .4byte 0x03002B8C
_08010B50: .4byte 0x0300137C
	.syntax divided
