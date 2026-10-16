	.syntax unified

	thumb_func_start sub_0803DAEC
sub_0803DAEC: @ 0x0803DAEC
	push {r4, lr}
	ldr r4, _0803DB10 @ =0x03000490
	adds r0, r4, #0
	movs r1, #0x14
	movs r2, #0
	bl sub_0803F624
	movs r2, #0
	movs r0, #1
	strb r0, [r4]
	ldr r1, _0803DB14 @ =0x03002B8C
	movs r0, #3
	str r0, [r1]
	ldr r0, _0803DB18 @ =0x0300137C
	str r2, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803DB10: .4byte 0x03000490
_0803DB14: .4byte 0x03002B8C
_0803DB18: .4byte 0x0300137C
	.syntax divided
