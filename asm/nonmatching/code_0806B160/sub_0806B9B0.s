	.syntax unified

	thumb_func_start sub_0806B9B0
sub_0806B9B0: @ 0x0806B9B0
	push {lr}
	bl sub_0806BBDC
	cmp r0, #0
	beq _0806B9C2
	ldr r1, _0806B9CC @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0806B9C2:
	bl sub_0806C994
	pop {r0}
	bx r0
	.align 2, 0
_0806B9CC: .4byte 0x0300137C
	.syntax divided
