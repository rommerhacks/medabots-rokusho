	.syntax unified

	thumb_func_start sub_0803E018
sub_0803E018: @ 0x0803E018
	push {lr}
	bl sub_0803E894
	bl sub_0803EB30
	bl sub_0803EB5C
	bl sub_0803EC04
	ldr r1, _0803E038 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0803E038: .4byte 0x0300137C
	.syntax divided
